# fragment84_code

## 2026-10-28 — `func_8FC0069C` matched (party image grid)

`gSPDisplayList(D_80094E38)`, then for each of the two 0x4D40-byte player
blocks at `&D_8FC02830` and each of six 0xC80-byte slots, draw image
`block + j * 0xC80 + 0x58` with `func_8004D998(D_8FC02448[p] + j * 0x26 + 0xF,
0x15E, image, 0, 0)`. Retail's loop end symbol `D_8FC0C2B0` is
`&D_8FC02830 + 0x9A80`. It matched on the first probe.

## func_8FC00FF8 (accepted 2026-10-28)

Loads one 0x44-byte record from ROM table `D_15833A0` (1-based index) through an
8-byte-aligned stack buffer, then `_bcopy`s it to `dst`. It is the same family as
fragment76's `func_8F700538` and fragment80's `TeamParameters_Load_fragment80`.
Matching details:

- `volatile u8 index`: retail reloads the byte from its home slot.
- The aligned address `(u32)scratch & ~7U` must be written inline in both calls.
  A `buffer` local moves the array to `0x28`.
- `u8 scratch[0x44 + 16]` puts the array at `0x24` in the 0x78 frame. A u64
  array is 8-aligned and too low.
- The file's m2c extern was retyped to `void func_8FC00FF8(void *, volatile u8)`.
