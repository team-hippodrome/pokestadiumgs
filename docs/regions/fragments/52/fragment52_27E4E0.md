
## 2026-10-29 — `func_864004B4`: requeue

Status: **requeue**, best 0.5596 (193/193 words). The 2026-10-29 session's
body is `scratch/c/4b4b.c`, and it needs a companion edit that drops the file's
stale `extern u8 D_800D0510;` above `func_86406544` (`scratch/c/4b4_comp.json`).

Shape: only for `arg0 == 5`.
- `obj = *(u8 **)(D_8009491C + 0x14)`;
  `tex = D_86409718[(obj+0x1C % 16) / 2]`.
- `period` uses the if/else rounding form of `(f()/60)*6`;
  `alpha = 255 - 255*obj+0x1C/period`.
- The colour comes from a bit chain on `obj+0xC` (bits 24..27, else-if). Each
  branch assigns **all three** channels: (8C,8C,C8), (8C,C8,8C), (DC,8C,8C),
  (DC,8C,8C), else (C8,AA,82). Retail's `r = g = 0x8C` before the first test is
  hoisted from branch 1.
- `gDPPipeSync`, `gDPSetEnvColor(r, g, b, (u32)alpha)`,
  `gSPSegment(0x0F, func_8004CA60((u8 *)func_8004C990(0x9F, tex)))`,
  `gSPDisplayList(D_864098C0)`, then `func_8003CD84()`.

Open problems:
- Our frame is 0x40 and retail's is 0x38, whatever the local count or order
  (alpha, period and the r/g/b declarations were all varied). The extra slots
  likely come from the gbi-macro block temporaries.
- The head loads `D_8009491C` into `$t6` instead of `$v0`.
