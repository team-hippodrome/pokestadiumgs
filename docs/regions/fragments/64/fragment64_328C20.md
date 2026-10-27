# Region notes -- src/fragments/64/fragment64_328C20.c

## 2026-10-27 — `func_87F05FB0` transposed-basis matrix accepted

`func_87F05FB0(out, basis, pos, angles, arg4)` is now C: **57 words / 228
bytes**, frame 0xA0. It builds `tmp` from the three `u16` angles with this
file's `func_87F06094`. It then builds `rot` as the transpose of the upper
3×3 of `basis` (row 3 = 0, 0, 0, 1) and calls `MtxF_Multiply(out, tmp,
rot)`. Finally it writes `pos[0..2]` and 1.0f into `out[3]`. Callers in
fragment 52 pass a fifth pointer (`+0x30` of the same object) that this
function never reads; it is kept as `void *arg4`.

Declare `tmp` before `rot` (stack +0x60 / +0x20); the opposite order swaps
the two frames (0.67).
