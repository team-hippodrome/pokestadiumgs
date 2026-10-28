# fragments/67/fragment67_34AB40.c

## 2026-10-28: `func_8290E2FC` requeue

requeue (0.91). `(f32 *weights, f32 *out, s16 index, s32 which)`: picks D_829168AC/D_829169A8 (f32[][3]) by `which` and computes `out[k] = w0*r[0][k] + w1*r[1][k] + w2*r[2][k] + w3*r[3][k]` from row `index`. Then `D_8291BC08[which] = D_8291BC08[which] + 1.0f / ((s16 *)&D_8291BC00)[which]`. Best: the ternary inlined into `row = &(which == 0 ? A : B)[index]` (fixes the addu order) with `weights[3] * row[3][k]`. Remaining: retail reuses $v0 for &D_8291BC08[which] and $t0 for the BC00 address, where ours uses $t0/$t1. Next: permuter from that base, or an `f32 *acc` temporary formed before the divide.
