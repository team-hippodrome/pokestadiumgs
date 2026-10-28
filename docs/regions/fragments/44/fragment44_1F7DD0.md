# fragments/44/fragment44_1F7DD0.c

## 2026-10-29: `func_8AF0A244` requeue

requeue (0.77). Draws the list cursor:
- x = state+8 + (s16)state+0x34 * state+0x4C + state+0x5C - 4; y is the same with 0xC/0x36/0x50/0x60 and -2;
- `func_8AC007B8(state+8, state+0xC, (s16)state+0x28, 0x104)`, `func_8AF02F18(state)`, `func_8004B314(x, y, 0x58, 0x44)`, `func_8AC00738()`;
- then func_8AC0665C/func_8AC0672C on `(s16)(state + 0x28)[+0x10]` pick the D_8AF2D168/D_8AF2D1E0 arrows.

Two open issues. Retail keeps `list = state + 0x28` as a real pointer (`addiu v0, s0, 0x28`, spilled to sp+0x20 across the call), where IDO folds every spelling we tried into `0x38(s0)`: byte offset, `s16 *`, typed view, late assignment. func_8AF1E54C (fragment44_20C560) shows the same unfolded `state + 0x28`, so it is likely one shared source shape. The x/y sums also reassociate differently: retail does `(base + product) + offset`.
