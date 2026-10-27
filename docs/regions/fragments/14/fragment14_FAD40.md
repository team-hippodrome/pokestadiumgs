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
