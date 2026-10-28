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

## 2026-10-28: `func_8630470C` requeue

requeue (0.74). The file now owns its 0.1f literal: the `.rodata` subsegment at 0x27D370 was gated with the owner still in assembly. The body is a 4-iteration loop: spawn via func_87F025B8(D_863075D8 + 0x88DC, func_86304620), the model init chain (func_8003F1DC/F114/F210, ModelAnim_SetFrame(rand % 41), ModelAnim_SetSpeed(0x17FFE)), func_87F06430(obj + 0x48, i), and the stores +0x20 = i, +0x54/58/5C = 0.1f, +0x4C -= 30. Retail keeps the loop constants (4, 41, 0x17FFE, 0x88DC, func_86304620) in s4-s7/fp and re-forms D_8630745C/D_8630745D per access. Our compile hoists those two byte addresses into s-registers and spills the function pointer instead, and the frame grows from 0x50 to 0x68. The permuter (600 s) found nothing usable. Next: find which source shape keeps `4` in a register (bound compared as a variable) so the byte globals lose the s-register allocation.
