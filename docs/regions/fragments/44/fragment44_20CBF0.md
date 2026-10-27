# `src/fragments/44/fragment44_20CBF0.c`

## 2026-10-27 — `func_8AF1F038`: requeue

requeue. Draws the cursor rectangle at (state+8 + s16[+0x34] * [+0x4C] + [+0x5C] - 4, state+0xC + s16[+0x36] * [+0x50] + [+0x60] - 2, 88, 68) between func_8AC007B8(state+8, state+0xC, s16[+0x28], 260) / func_8AF02F18(state) and func_8AC00738(), then fires func_8AC05F00(D_8AF38DF0 / D_8AF38E68) on func_8AC0665C / func_8AC0672C(D_8AF39190, s16[+0x38]). Best 0.72: IDO reassociates base + index*stride + offset (target keeps (base + product) + offset), and the frame is 8 bytes larger. permute_candidate.py fails on this file (strip_other_fns "unbalanced {}").
