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

## 2026-10-27 — `func_813037F0`: saved-value record setup

The 224-byte owner (56 instructions, 96-byte frame) reads the selected
index, obtains a four-halfword position/dimension record and builds an
eight-word flag set. It calls `func_81306C18` with context offset 3352,
the saved byte for that index, the flag set and 1. It then calls
`func_8130EB04` with the selected 3304-byte record's block at offset 32,
argument 3, the same flags and position record, and final argument 152
when `func_81302BB0` succeeds or 146 otherwise. It finishes by storing 10
in parent byte 19901. The broader meanings of these numeric states remain
unknown.
//@src/fragments/14/fragment14_FAD40.c

The byte view at parent offset 19902 contains six saved values. Original
`func_81303648` saves each record's byte at offset 33 into this array and
clears the record bytes; original `func_813038D0` restores all six values.
The local type exposes that existing array without allocating new storage.
It preserves the original base-plus-index address calculation; the flat
byte expression differs in the operand order of one `addu`.

Compiled `func_813049AC` and `func_8160B5BC` initialize all four position
halfwords, including dimensions 140 and 57. Original `func_81306C18`
copies eight flag words to its argument's offset 84 and stores its fourth
argument at offset zero. Original `func_8130EB04` copies all eight flag
words and eight bytes from each position argument. These buffers are
consumed data, with original stack offsets 60 and 52 respectively. The
selected index spills at offset 92. Original caller `func_81303EF4`
forwards the parent pointer and discards this owner's result.
//@src/fragments/11/fragment11_E1E10.c
//@src/fragments/14/fragment14_FD770.c
//@src/fragments/14/fragment14_104FC0.c

Fresh validation on master `1052cca0da6ede66e32378c54ca5c272060ce063`
plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/14/fragment14_FAD40.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and complete US
link pass with `build/pokestadiumgs-us.z64: OK`. ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail comparison and whitespace checks
pass. All 56 original words and retail span `0xFB980..0xFBA60` compare
exactly. No new fakes, padding, storage, instruction rewriting, layout,
generated reports or CI changes are required.

## 2026-10-28 — `.rodata` windows for FA520/FAD40; `func_81302C64` matched

The shared rodata blob 0x10A430–0x10A600 is split by file:
- `fragment14_FA520` owns 0x10A430–0x10A440 (`D_813122A0`, 16 zero bytes, used by its still-assembly `func_8130251C`).
- `fragment14_FAD40` owns 0x10A440–0x10A600: the thirteen `s16` menu command lists `fragment14_data`'s descriptors point at, then its late rodata (`jtbl_813123A8`, `D_813123F4`, `jtbl_813123F8`, `jtbl_81312418`).
Splat migrates the late rodata into the owners' `.s` files; the lists and `D_813122A0` are defined in C. Byte-identical.

`func_81302C64` returns 0 for states 0–7, 11, 15 and 16 of +0x4DBD, otherwise 1, as a `switch` with direct returns; it emits retail's 19-entry jump table. `func_81302CB4`, `func_81303648` and `func_81303EF4` are now layout-ready.

## 2026-10-28 — `func_81303648` matched; `func_81302CB4` requeue

- `func_81303648` dispatches on `func_81311C70(owner + 0x74, func_813035A0(obj), slot0.+0xA, -1)` (case bodies in retail order -1, 1, 2/3, 4, 6, 5):
  - -1: `func_8160A928(count >= 6 ? count - 1 : count)` with `count = func_8160A8DC`, state 12;
  - 1: `func_8130A570` then state 3, `func_81302E58` and return;
  - 2/3: state 16;
  - 4: state 17;
  - 6: save and clear each slot's +0x21 byte into +0x4DBE, state 18;
  - 5: `func_8160A94C`, state 12.
  The object is typed (`unk_func_81303648`: six 0xCE8-byte `unk_D_81303648_slot`s, then the state fields). Retail's base-first `addu` in the copt-unrolled save loop only comes from indexing the slot array. The loop reuses `count`. The unused second parameter is kept because retail homes `a1`.
- `func_81302CB4` (requeue) slides the panel rect (w 473, h 143):
  - state 15: x eases from -473 or 640 (by `+0x4DA8 > 0.5`) toward 85 with `D_8160BD08((p - 0.5) * ±2)`, y 91, returns 1;
  - otherwise `t = D_8160BD08(+0x4DA4 / 16)` when +0x4DB0, slot0.+0x20 and state 0/3, and x/y lerp from (85, -143) to (85, 91) by `t`.
  Retail converts all four integer endpoints with `cvt.s.w` at run time. IDO folds at least the start values for every spelling tried (literals, `s32`/`s16`/`u16` locals).
