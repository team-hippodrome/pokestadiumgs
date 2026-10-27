# Region notes -- src/fragments/64/fragment64_3235A0.c

## 2026-10-27 — `func_87F01D44` flag-gated call accepted

`func_87F01D44` is now C: **20 words / 80 bytes** plus three alignment nops,
frame 0x18. When the top bit of the byte at `D_87F0F610 + 0x3D` is set (the
same flag `func_87F00930` returns), it calls `func_87F08FA0` with the byte
at +0x3C, then `func_800503A4` with word `*(s32 *)(D_87F0F610 + 0x10)` of
the array at +0x20.

Write the test exactly as `func_87F00930` does, `(u32)D_87F0F610[0x3D] >> 7`
(a one-bit bitfield also matches). An `s8 < 0` test allocates `t6` instead
of `t7`; `& 0x80` is worse. Index as `((s32 *)(D_87F0F610 + 0x20))[i]`;
byte arithmetic commutes the `addu`.
