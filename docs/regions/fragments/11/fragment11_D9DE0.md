# src/fragments/11/fragment11_D9DE0.c

## 2026-10-28: `func_816089E0` handoff

requeue (0.86). Swaps `D_8160BE80` with `func_8000731C()->+8` when non-zero
and returns the old value. Retail re-forms `D_8160BE80`'s address for every
access; IDO keeps it in `a1` (0.82), and declaring it `volatile` gives 0.86.

## 2026-10-28 — `func_81606800`: requeue, one operand-order residual (0.979)

`if (arg1 != 0 || D_8160BE5C != arg0) { D_8160BE5C = arg0; gDPPipeSync;
arg0 ? (EnvColor 0,0,0,255; PrimColor m=255,l=255, 255,255,255,255) :
(EnvColor 255,255,255,255; PrimColor 255,255, 0,0,0,255); }`, written with
the file's `(*(Gfx **)&D_800D0510)++` (the file declares `D_800D0510` as
`u32`). Everything matches except `beq t6(cached), a0` vs our `beq a0, t6`.
Unchanged by: both operand orders, an early-return or `goto` form, s32/u32/
u8/s16/pointer cache types, pointer/u32 parameters, and a one-line `if`.
A 180-second permuter reached 50 only with macro-expanded one-line layouts.

## 2026-10-29 — whole `.rodata` owned from 0xE3C60; both switches matched

The 0xE3C60 rodata blob belonged entirely to this object. Its `.rodata`
now starts there; the `const u32 D_8160C270[3]` jump-table-tail hack is
gone.

- C-used tables are now in-place `const` definitions: `D_8160C0F0`
  (`s16[16]`; its last word doubles as `D_8160C10C` via `aliases.ld`),
  `D_8160C128`, `D_8160C180`, `D_8160C188`.
- The two empty strings are `""` literals in `func_816087C8`, and
  `D_8160C208` is the literal `0.4f`.
- A zero-initialised `const` scalar does not land in `.rodata`, which is
  why `D_8160C10C` lives inside the array.

Matched:

- `func_81602940`: 28-case switch over `func_8004C990(0x14C, k)`.
- `func_81602C68`: 28-case switch returning data addresses. It needs a K&R
  definition, because the existing caller `func_81602DA4` calls it with no
  arguments, plus a `CC_CHECK`-only argument at that call so the host clang
  check accepts it.
