# Region notes -- src/fragments/51/fragment51_279D70.c

## 2026-10-27 — `func_86304318` object spawn accepted

`func_86304318(f32 x, f32 y, f32 z, f32 scale, u8 kind)` is now C:
**51 words / 204 bytes**, frame 0x28. It allocates an object from the pool at
`D_863075D8 + 0x1F84` with update callback `func_8630421C`. It then
initializes the model at object+0x24 (`func_8003F1DC`, then
`func_8003F114(base, 0, -1, *(s32 *)(D_863075D8 + 0x128))`), and writes
position +0x48/+0x4C/+0x50 and the uniform scale +0x54..+0x5C. Finally it
copies the two words of the 8-byte entry `D_86306FB8[kind]` (word 1 to
+0x60, word 0 to +0xC4) and sets bit 0x08 of byte +0x26.

Write the stores in field order (x, y, z, three scale stores, +0x60, +0xC4,
then the flag `|=`); IDO schedules them into the original order. Chained
scale assignment or moving the flag store earlier changes the schedule
(0.65–0.71). An `s32` kind with `& 0xFF` adds a word.
