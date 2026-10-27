# Region notes -- src/fragments/31/fragment31_1A3960.c

## 2026-10-27 — `func_88230A88` and `func_88230E38` accepted

- `func_88230A88` (**41 words / 164 bytes**, frame 0x20): input handler for
  the menu record at `D_882349B0 + 0x24`. B (0x4000) plays sound 0x48, sets
  word +0xE8 and calls `func_88230A38`. A (0x8000) calls `func_88214394`,
  then `func_882026A4(D_882345F4, menu[+0x28] + 2)` and `func_88230A38`.
  Otherwise it forwards to `func_88002720(menu + 0x28, menu[+0xC], menu +
  0x2C)`. Declare `menu` first and `buttons` as `u32` (a `u16` local moves
  it to `a0` and the spill slot to +0x18).
- `func_88230E38` (**40 words / 160 bytes**, frame 0x28): reads `half`/`alpha`
  with this file's `func_88230D80`, negates `alpha` when
  `half >= D_8800EF58`, then appends `gSPDisplayList(D_88233B20)` and
  `gDPSetPrimColor(0, (255 - alpha) >> 1, 0, 0, 0, 255)`. The LOD value must
  be computed into a local **before** the first macro (0.54 otherwise).
