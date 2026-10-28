# fragments/83/fragment83_code.c

## 2026-10-29: `func_82C0273C` requeue

requeue (0.70). For six rows: set `*(s32 *)(D_82C05E80 + j*0x4B28 + 0x148) = 1`; for six slots, copy `D_82C05E80[j*6 + 0x4C + i]` into `rec[5 + i]` and `((u16 *)(rec + 0xC))[i]` (with `rec = D_82C05FC8 + j*0x4B28`, i.e. +0x148). Then OR `1 << i` into `rec[4]` when `func_82C02664(*(u8 **)(&D_82C04C38 + 0x18) + 0x14, value)`. Retail's outer loop is pointer-driven: $s7 steps 6 up to D_82C05EA4, $fp is a copy of $s7 stepping 0x4B28, and $s4 steps 0x4B28 from D_82C05FC8. A three-pointer `for` reaches the same instruction stream except that IDO initializes $fp first and copies it into $s7 (reversed). Neither declaration order nor init order changes that.
