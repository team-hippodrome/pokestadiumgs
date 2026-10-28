# fragment84_code

## 2026-10-28 — `func_8FC0069C` matched (party image grid)

`gSPDisplayList(D_80094E38)`, then for each of the two 0x4D40-byte player
blocks at `&D_8FC02830` and each of six 0xC80-byte slots, draw image
`block + j * 0xC80 + 0x58` with `func_8004D998(D_8FC02448[p] + j * 0x26 + 0xF,
0x15E, image, 0, 0)`. Retail's loop end symbol `D_8FC0C2B0` is
`&D_8FC02830 + 0x9A80`. It matched on the first probe.
