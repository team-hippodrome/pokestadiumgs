# Region notes -- src/fragments/32/fragment32_1B9390.c

## 2026-10-27 — `func_883083C8` / `func_88308464`: requeue (shared idiom)

These two search backward and forward from the `s16` index at `arg0 + 8`
through `D_88601898` (a `u16 **` record table) for the first record
`func_886000F0` accepts, and return the `u8` distance or 0. The forward
variant stops at the `u16` limit at `arg0 + 0xC`. Best: normalized 0.9231
with `s32 at_start = 0; if (*(s16 *)(arg0 + 8) == 0) at_start = 1; if
(at_start) return 0;` and then `while (TRUE) { if
(func_886000F0(*D_88601898[i])) return count; if (i == 0) return 0; count++;
i--; }`. The only residual is that the target branches (`b`) to the very next
instruction after setting the flag. Empty then/else arms, goto-join,
`do/while(0)` + `break`, `switch`, ternaries, `&&`/`||` forms and `if (1) {}`
all omit that branch. Permuter 240 s: no improvement. Next: find a matched
owner with the same `or v0,zero; bnez; b next; addiu v0,1` join and copy its
source idiom.

## 2026-10-27 — `func_883083C8` backward search accepted; `func_88308464` narrowed

`func_883083C8` is now C (**39 words / 156 bytes**, frame 0x28). The
branch-to-join after `flag = 1` comes from an `if (cur == 0) { flag = 1; }
else { flag = 0; }` with **no initializer** on the flag. With
`s32 flag = 0;` plus a then-only arm the `b` disappears; that was the
earlier 0.92 plateau. Initialize `count = 1` immediately before the loop
(declaring it with `= 1` hoists the `li` ahead of the flag's `or`). The same
then-arm-jumps-over-else shape is confirmed by `func_8AF1F294`
(`fragment44_20D3A0.c`).

`func_88308464` (forward search to the `u16` limit at `arg0 + 0xC`) is still
a requeue, now at 0.78. The same if/else flag and
`for (i = cur + 1, count = 1; ; i++, count++)` with
`if (i + 1 == limit) return 0;` match the control flow. The remaining
difference is that the target recomputes `cur + 1` for the loop start (no
CSE with the flag test) and keeps `i + 1` and `i++` as separate adds. A
180 s permuter run reaches score 10 only with slop (`cur ^ 0` and a `u16`
limit local).

## `func_88308080`: species and Unown flags

The initializer matches 210 instructions / 840 bytes at US ROM
`0x1B9390..0x1B96D8`, with a 112-byte frame. Caller `func_883051E4`
allocates the 916-byte state at `D_88601890`, sets its mode, and invokes
this owner. The caller now declares its actual void, no-argument contract.
//@src/fragments/32/fragment32_1B1330.c

The owner fills 251 species flags at offset 628 using `func_8005E728` and
records the last accepted mapped and direct species indices. It stores
three saved-bitmap population counts at offsets 907–909. The existing
wrappers `func_8005ECA4`, `func_8005ED78`, and `func_8005EE4C` now return
the `s32` result of `GbSave_CountBitmapBits` explicitly; their instruction
bytes are unchanged.
//@src/585D0.c

The 26 form flags begin at offset 879. Saved Unown dex entries mark forms
with 2. The temporary pool tagged `0x554E4B4E` holds 88-byte records from
selector-32/33 archives; species-201 records mark their decoded form with
3. `func_80064520` derives that 1–26 form index from the record's halfword
at offset 22. The final loop counts flags equal to 3. `func_886000F0`
consumes these species/form membership flags through the existing state
view. Unknown function/global names are preserved.
//@src/641E0.c
//@src/fragments/35/fragment35_1CCC20.c

The archive cursor starts in the read loop initializer; the loop bound is
`boxes + 1`. Capacity selection follows opening each archive. These actual
lifetimes reproduce the retail frame and scheduling without padding,
fixed registers, new data, or instruction rewriting.

Validation: `VERSION=us`, master
`9206356d598abf158de1618aeca2f3f1ad8e2518` plus these changes:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/32/fragment32_1B9390.c -W src/585D0.c \
    -W src/fragments/32/fragment32_1B1330.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled full build reports exactly
`build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Across all three changed C modules, 61,376 text bytes,
1,552 read-only bytes, 72 register-info bytes, 263 defined function
extents, and 3,063 semantic relocations equal the original assembly
baseline. Previously matched C, including all three return wrappers and
the caller, remains byte-identical.
