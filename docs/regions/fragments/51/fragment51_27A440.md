# Region notes -- src/fragments/51/fragment51_27A440.c

## 2026-10-27 — `func_86304620` animation cycle accepted (FAKE)

`func_86304620` is now C: **59 words / 236 bytes**, frame 0x18. In state 2
(word 0 of `D_863075D8`) it sets `ModelAnim_SetSpeed(D_87F119DC + 0x24,
0x20000)`. When the model's halfword +0x64 equals `D_8630745D`, it picks
again on a `func_8003570C() % 6 == 0` roll. The second `func_8003570C()`
result is discarded. It then reinitializes the model with the animation
word `((s32 (*)[2])(D_863075D8 + 0xE0))[*(s32 *)(D_87F119DC + 0x20)]
[D_8630745E]` and calls `func_8003F210(model, D_8630745F)`.

Index the animation table as a 2-D array (raw byte arithmetic commutes the
`addu`). The original loads the model pointer before `D_8630745D`; only the
comma expression `(0, D_8630745D)` from a 41 s permuter run reproduces that
order, and it is marked `// FAKE`. A local for either operand is worse
(0.71–0.75).
