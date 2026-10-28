# fragment64_32D7D0 matching notes

## func_87F0AB60

This owner returns the word at byte address `arg0 + arg2 * 1728 + arg1 * 4`
when the signed index `arg1` is in 0..11. The incoming address retains its
existing word-sized interface; converting it to a byte pointer expresses the
row and entry offsets. The original assembly returns an uninitialized stack
word for other indices. The C preserves that behavior and labels the original
bug with `//!bug`.

Compiled `func_87F0AD50` forwards its three explicit arguments to this owner,
then passes the returned address and row index to `func_87F0ABA4`. The latter's
original assembly consumes the record address in `a1`, following the hidden
`ColorAdjustment` return pointer in `a0`. Compiled `func_87F0AD98` independently
uses the same 1728-byte row stride and four-byte entry indexing, then reads
through the selected pointer. These consumers support the address calculation
without introducing a new global allocation or changing their interfaces.
//@src/fragments/64/fragment64_32D7D0.c
//@include/color_adjustment.h

Compiled `Fragment51_InitScene` supplies its game-context pointer, entry index
4 and row indices 0..3 to `func_87F0AD50`, using the returned color adjustment
for resource creation. Broader table contents remain outside this replacement;
existing address-based names and all neighboring C remain unchanged.
//@src/fragments/51/fragment51_275E40.c

An initial integer-address expression differed only in the source operands of
one `addu`. Byte-pointer arithmetic matches all 17 instruction words (68 bytes)
and the original eight-byte frame. No new fakes, qualifiers, padding, instruction
rewrites or layout changes are required.

Fresh validation uses master `86b045009b228b0e6485f70211f05f164eb4e336`
plus this patch. The unchanged baseline passes its own complete US ROM build
and retail comparison. Final validation forces recompilation through the
default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_32D7D0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 68 bytes at ROM `0x32D7D0..0x32D814`.

## func_87F0ADE0 (accepted 2026-10-28)

Pool-allocates `count` 396-byte nodes plus `count` 16-byte link records, then
links each node's `+0x38` to its record and zeroes the record. Matching shape:
`i = 0;` before a guarded `if (count != 0) { ... do { } while (i < count); }`,
with the three pointer inits (`node`, `link`, `clr`) *inside* the guard. If they
sit before the `if`, the `beqz` moves two instructions later (0.98). A plain
`for` loop gets unrolled by copt. The `clr += 4; clr[-4..-1] = 0` order is from
the retail store offsets.

## 2026-10-29: `func_87F0ABA4` requeue

requeue (0.94). Returns ColorAdjustment by value; args `(s32 entry, s32 row)`. `result.raw = 0`. If `*(s8 *)entry == 0`, a 4-case switch picks `step` (0, 2, 1, 3 for rows 0-3), then `result.unk_00 = (func_8004B920(rec[0], 0) + (high - low) / 3 * step) << 6` with `rec = entry + 4`. Otherwise `result = func_8003F5AC(rec)`, replaced by `func_8004B9E0(rec[0])` when func_8006456C(rec+0x16) is set and func_8004B98C(rec[0]) == 2. Stack fixed by declaring `u8 *entry; ColorAdjustment result; s32 step; u8 *record; s16 high; s16 low;` (each declared local reserves a slot). Remaining: retail keeps the argument in $a3 and computes `record = arg + 4` in both arms, with a duplicated `lbu` on the switch's default path. Assigning `record` in each branch moves `entry` into $s1 and grows the frame. Next: drop the `entry` local but keep a fourth declared slot in a way that doesn't need it live.
