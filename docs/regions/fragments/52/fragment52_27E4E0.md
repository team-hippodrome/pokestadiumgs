
## 2026-10-29 — `func_864013A8`: requeue

Status: **requeue**, best 0.9108 (106/106 text words, ignoring the late_rodata
-0.1f). Body is in the 2026-10-29 session's `scratch/c/3a8.c`.

What works:
- Rounding written as `(((f32)func_80001FF0() / 60.0f) * 2)` with an
  **integer `2`**. `* 2.0f` is strength-reduced to `add.s` (0.715).
- `arg0+0x1C = (s32)(r * (1.0f - arg1+0x18 / *(f32 *)D_86416C00))`.
- `arg0+0xC |= 0x10000000`.
- `if (arg2)`: when bit 0x40000 is set, multiply arg0 +0x10 and +0x18 by -0.1f.
  Otherwise `arg1+0x48 = (f32)(u32)*(u16 *)(arg2+8)` and copy arg2 +0/+4.

Remaining: retail loads `D_86416C00` (and `*D`) before reloading arg1 from
0x1C(sp) and its +0x18. The FP register pair in the multiply and in the -0.1
branch then swaps (f6/f18).

Tried with no effect: a ratio temp, a max temp (f32 and f32 *), `[0]`, an
operand swap, `(f32)` without `(s32)`, `!= 0` on the flag test, and or-first.
The permuter (300 s) only found fakes (`0x10 ^ 0`, `arg1 - -0x48`).

Next: type arg1/D_86416C00 as real structs (find the object type of
`D_86416C00+0x3334` pools), or reorder evaluation through a typed callee
signature.
