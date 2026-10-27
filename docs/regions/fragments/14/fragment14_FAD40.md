# Region notes -- src/fragments/14/fragment14_FAD40.c

## 2026-10-27 — `func_81304A08` / `func_81304AD0` record-array helpers accepted

Both walk the 0xCE8-byte records that start at the base pointer, now typed
as `unk_func_81304A08`. Each record has a word-aligned 0x58-byte block
(`unk_func_81304A08_20`) at +0x20 whose first byte is the slot-in-use count
the other functions in this file test (`[0x20]`).

- `func_81304A08(u8 *arg0, unk_func_81304A08_20 *out)` (**50 words / 200
  bytes**): returns 0 when `func_81302C40(arg0)` fails. Otherwise it copies
  block +0x20 of the first `func_8160A8DC(arg0)` records into `out[]` and
  returns that count. The struct assignment emits the original 12-byte copy
  loop; the block must contain an `s32` member, because a byte array gives
  `lwl`/`lwr` copies.
- `func_81304AD0(u8 *arg0)` (**56 words / 224 bytes**): returns 0 when
  `func_81302C40(arg0)` fails, 1 if any of the six records has a positive
  first byte, otherwise -1. Write the plain `for (i = 0; i < 6; i++)`; copt
  peels two iterations and unrolls the remaining four. Nest the loop under
  `func_81302C40(arg0) != 0` (the target falls through into it) and index
  the typed record array: raw `arg0 + i * 0xCE8` commutes the `addu`.

## 2026-10-27 — `func_813031D8`: selected-record clear result

The 80-byte wrapper (20 instructions, 40-byte frame) reads the signed-byte
index at parent offset 8 through `func_8160A920`, obtains this file's
`func_81302BB0` predicate, and passes both to `func_8160B9A0`. It ORs that
helper's word result into the parent word at offset 19884. The first C
recipe reproduces the original call order, spill at stack offset 36 and
final read/OR/store.

The compiled helpers establish the operations: `func_81302BB0` tests whether
the signed byte at offset 19900 is nonnegative. `func_8160B9A0` selects a
3304-byte record, clears its byte at offset 32 and word at offset 120 when
that byte is nonzero, marks parent byte `index + 11`, optionally
calls `func_800226C0(152)`, and returns whether it cleared a record. Broader
meanings of the parent's status word and predicate remain unresolved.
//@src/fragments/14/fragment14_FAD40.c
//@src/fragments/11/fragment11_E1E10.c

Compiled caller `func_8130437C` sets the selected index through
`func_8160A928` before invoking this wrapper, then changes parent byte
19901 to 12. It discards the wrapper's result; the wrapper returns void.
Existing data ownership and names remain unchanged.

This translation unit's repeated `func_8160A920` declarations now take the
parent pointer consumed by its definition. Five existing calls explicitly
forward that pointer. The `func_8160B9A0` declaration now exposes its word
return. A separate control build with these interface corrections and the
wrapper still in assembly passed the complete ROM comparison, proving that
the existing compiled callers retain their bytes.

Fresh validation uses master `23ec59ef61542b658ff73c933e405d5afbbaf783`
plus this source change:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/14/fragment14_FAD40.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The default host syntax check, forced source compilation and complete US
link pass with `build/pokestadiumgs-us.z64: OK`. The ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the retail byte comparison and whitespace
check pass. All 20 original words and retail span `0xFB368..0xFB3B8` compare
exactly. No new storage, fakes, padding, instruction rewriting, layout,
generated reports or CI changes are required.

## 2026-10-27 — `func_81303D60`: selected-record setup

The 192-byte owner (48 instructions, 96-byte frame) obtains a four-halfword
position/dimension record, reads the selected index through `func_8160A920`,
and builds an eight-word flag set through `func_81304788`. It passes the
selected 3304-byte record's block at offset 32, the flags and the same local
position record twice to `func_8130EB04`. The last argument is 150 when
`func_81302BB0` succeeds and 146 otherwise. Finally it stores 14 in parent
byte 19901. The broader meanings of those numeric states remain unknown.
//@src/fragments/14/fragment14_FAD40.c

`func_813049AC` calls `func_8160B5BC`, which initializes all four halfwords:
the last two are 140 and 57. It then adds `func_81302CB4`'s two offsets to
the first two halfwords. The original assembly of `func_8130EB04` copies
eight bytes from each of its two record arguments, and copies all eight
words of the flag set. `func_81304788` initializes that set through
`func_81601A38`. The four-halfword local therefore represents consumed
data. Its original stack offset is 52; the flags start at 60 and the
selected index spills at 92.
//@src/fragments/11/fragment11_E1E10.c
//@src/fragments/11/fragment11_D9520.c
//@src/fragments/14/fragment14_104FC0.c

The 3304-byte array view preserves the same record stride established by
`func_81304A08` and `func_81304AD0` in this file. The original assembly of
caller `func_81303EF4` passes its parent pointer and discards the result.
Existing callers, helpers and data ownership retain their bytes.

Fresh validation on master `29f0a2e7ba3c00c633b026d74e89423f1866528c`
plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/14/fragment14_FAD40.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and full US link
pass with `build/pokestadiumgs-us.z64: OK`. ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail byte comparison and whitespace
checks pass. All 48 original words and retail span `0xFBEF0..0xFBFB0`
compare exactly. No fakes, padding members, instruction rewriting, new
storage, generated reports, layout or CI changes are needed.

## 2026-10-27 — `func_813042E4`: guarded state transition

The 152-byte owner (38 instructions, 32-byte frame) calls
`func_8160A920`, preserving its discarded result, then returns zero unless
parent byte 19901 equals 13 and `func_8160A8DC` returns a nonzero count.
It reads the context pointer at parent offset 19872, follows pointers at
context offset 106824 and the next record's offset 2368, and tests bit 31
of the final record's word at offset 64. A clear bit returns zero. A set
bit calls `func_81311C18` with context offset 116, stores 4 in parent byte
19901 and returns one. The state numbers and flag's broader meaning remain
unknown. Keeping the context pointer in a local preserves its original
reuse through the flag test and call.
//@src/fragments/14/fragment14_FAD40.c

Compiled `func_8160A920` reads the selected signed byte at parent offset 8.
`func_8160A8DC` counts up to six occupied 3304-byte records, stopping at the
first zero byte at record offset 32. `func_81311C18` writes -1 at its
argument's byte 25 and updates the adjacent state and float according to
the existing state byte. Their bodies and data ownership remain unchanged.
//@src/fragments/11/fragment11_E1E10.c
//@src/fragments/14/fragment14_109280.c

Compiled caller `func_813091E0` tests this owner's word result before
setting its own flag and state and playing sound 2. The complete ROM
comparison also covers that caller and all previously matched functions.
//@src/fragments/14/fragment14_FF070.c

Fresh validation on master `8b887cd48294525153220892eb703a8b6bc8aeec`
plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/14/fragment14_FAD40.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and full US link
pass with `build/pokestadiumgs-us.z64: OK`. ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail byte comparison and whitespace
checks pass. All 38 original words and retail span `0xFC474..0xFC50C`
compare exactly. No new fakes, padding, storage, instruction rewriting,
layout, generated reports or CI changes are required.
