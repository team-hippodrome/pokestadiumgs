# Region notes -- src/fragments/64/fragment64_3290A0.c

## 2026-10-27 — `func_87F06430`: requeue

requeue (float scheduling). out[0] = D_80087E50[113] / D_80088E50[113] * 1000.0f * D_87F11540 * (2x - 1), out[2] = 0.0f, out[1] = same ratio * 1000.0f * D_87F11544, with x = (46.5f + column * 39.0f) / 320.0f. Best 0.77 (stores in 0/1/2 order or 1000.0f as a local); the target interleaves the out[2] zero store between the two ratio computations. Permuter 120 s: 320 -> 70.
