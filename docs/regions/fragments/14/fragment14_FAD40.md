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
