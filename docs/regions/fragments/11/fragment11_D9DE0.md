# src/fragments/11/fragment11_D9DE0.c

## 2026-10-28: `func_816089E0` handoff

requeue (0.86). Swaps `D_8160BE80` with `func_8000731C()->+8` when non-zero
and returns the old value. Retail re-forms `D_8160BE80`'s address for every
access; IDO keeps it in `a1` (0.82), and declaring it `volatile` gives 0.86.
