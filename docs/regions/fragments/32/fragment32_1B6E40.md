# fragment32_1B6E40 matching notes

## func_8830602C and func_8830609C

These adjacent no-argument queries inspect the four existing 24-byte records
beginning at `D_88308E38`. Each owner is 112 instruction bytes with no stack
frame. `func_8830602C` returns 1 when any record's byte at offset 4 is nonzero,
otherwise 0. `func_8830609C` returns 1 when every record's signed word at
offset 0 equals 1, otherwise 0.

Original `func_88305B84` initializes all four status words to 1 and their
offset-4 bytes to 3, then passes each record to the existing bounds initializer
`func_88305B30`. Compiled `func_88306404` writes status 2 and byte 1 to a
selected record. Compiled `func_8830639C` traverses all four records and uses
the offset-4 byte to decide whether to draw their bounds. This establishes
the common record stride and accessed field types. The new unknown structure
view leaves bytes 5 through 23 opaque and allocates no storage.

Compiled `func_8830099C` consumes the first query to gate `func_8830639C`.
Original `func_88300B48` and `func_88301C00` call the second query without
arguments and branch on its result. The meanings of the status values remain
unknown, so the address-based names are preserved.
//@src/fragments/32/fragment32_1B1330.c

A separate first-record guard followed by a three-record loop produced
80- and 84-byte bodies and failed the ROM comparison. The four-record typed
loops reproduce the retail unrolling naturally on the second recipe; there
is no manual unrolling, forced register, padding or instruction rewriting.
No prior owner-specific note or private failed attempt was found.

Fresh validation on master `d3d30d14a3fb2048a8bcb918204151cf7cfd7a8f` plus
this patch used the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/32/fragment32_1B6E40.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Full US linking produced `build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks passed. All 28 words in each owner match, 224 instruction bytes total.
Previously matched C and data layout remain unchanged.

## 2026-10-29 — `func_88306B24` matched

Lab-state init. `D_8860189C = D_88006880` comes first, then
`func_88001C6C(..., (s32)(720.0f / f() + ((720.0f / f() > 0.0f) ? 0.5f : -0.5f)), 42, 42, 0xF00, 70)`
(the frame-rate rounding macro), then `D_88601898 = Util_Malloc(0x3EC)` and
`D_88601894[0] = D_88601894[1] = 0` on an `s8` array. A `u32 i` loop over
`(u16 *)(D_88601890 + 0x18)` writes `i`, or
`func_80064700((u8)func_80060110(D_88006868))` at i == 0xC9. The tail runs
through one pointer: `p = (u16 *)(D_88601890 + 0x20E); *p++ = 0xC9; *p++ =
0xFE;`, then 24 entries of `i + 0xFE`. Writing the tail stores with separate
global reloads fails.

## 2026-10-29 — `func_883067C4`: requeue

Status: **requeue**, best 0.9491. The text is 216/216 words and identical
apart from the frame: ours is 0x70, retail is 0x68. The 2026-10-29 session's
body is `scratch/c/7c4t2S.c`.

Shape: the arg0 vs `+0x244` cache update (`func_88300230(+0x242)` or
`D_88308DF8`) runs first. If arg0 == 0, set `D_8860189C = D_88006880` and
`D_88601896 = 0xFB`. Otherwise:
- If `*(s32 *)D_88601890 == 4`, call `func_88306430()` and copy count `+0x38E`.
- Otherwise use `s8 type[2] = func_88307AD0(0/1, 0)` and loop `i = 1..0xFB`
  over `u16 *entry`. When `func_886000F0(i) >= 2`, set
  `mon[0] = func_8006397C(i)` and `mon[1] = second = func_800639C0(i)`.
  `u16 found` is either the `(type0 == mon0 || type0 == second)` form or the
  two-pair form, chosen by `D_88601895 == 0 || type0 == type1`.
  `*out++ = entry; D_88601896++`.
- Window: `D_8860189C = +0x248`, then `func_88001C6C` with the 720/f() macro.
- Tail: `func_883064C8(*state)` if it is < 3, `func_8800225C(D_8860189C, 0, 0)`
  if arg0 != 0, then `func_88300230(*D_88601898[*(s16 *)(D_8860189C + 8)])`.

Key detail: retail compares the **unmasked** `func_800639C0` return in `$v0`.
That needs an `s32` temp (`second`) and an `s32`-returning prototype. Every
`u8` route adds `andi v0, 0xFF`. The extra `s32 second` local costs the 8
frame bytes. Tried with no effect: every declaration order, block-scoped
`second`/`found`, dropping `found` (the structure breaks), and dropping `out`
(the s-registers shift). Next: find a spelling that keeps the raw return
without a new declared local, or one where `found` shares a slot.
