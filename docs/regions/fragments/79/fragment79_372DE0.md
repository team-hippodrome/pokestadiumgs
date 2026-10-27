# src/fragments/79/fragment79_372DE0.c

## 2026-10-28: `func_8410373C` handoff

requeue (0.76). `func_8003F864()`, then registers each non-null pointer of
`D_8418D260` with `BattleAnim_RegisterAssetTable`. Retail keeps a dead
counter in `s1` and tests `D_8418D260[0]` through the symbol before a
pointer do-while. A guarded do-while with pointer and counter reaches 0.76.
