# fragment51_275E40

## 2026-10-28 — `func_863003DC`: requeue

Scale the actor's x/y (+0x10/+0x14) by the f32 at
`D_863075D8 + 0x8F24` and store them at +0x48/+0x4C. Then, for the three
byte indices at `*(u8 **)(arg0 + 0x20)`, set `D_863071F0` Vec2 `[idx]` to
`D_86307190[idx]` plus that offset (load-add-store per component, so
source and destination alias as `f32`). Best: a 240-second permuter (1240 ->
195) with a `f32 *src = D_86307190[idx]` local. Residuals: retail keeps
`scale` in `$f2` and starts the loop with a pipelined `lbu` (`v1 = 1;
beq v1, 3` before the body). Clean src/dst pointer forms stay at 0.35 raw.
