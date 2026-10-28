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

## 2026-10-28 — `func_86300EF8` matched (actor axis-swap matrix)

Build the actor's rotation from the three angles at `arg0 + 0x42`
(`func_87F06094`). Multiply it with the fixed axis swap
`{1,0,0,0 / 0,0,1,0 / 0,-1,0,0 / 0,0,0,1}` into `arg0 + 0x84`
(`MtxF_Multiply`). Then copy the position (0x48..0x50) to 0xB4..0xBC and set
0xC0 = 1.0f. Retail's 0x118 frame has 0x80 more bytes of locals than the two
matrices. Hence one marked `// FAKE` unreferenced `f32 unused[2][4][4]`,
declared first. (Growing `rotation` to `[12][4]` also matches, but
`func_87F06094` only writes 16 floats.)

## 2026-10-28 — `func_863006F8` matched (spawn three scaled models)

Three times: take an object from the pool at `D_863075D8 + 0x1ACC`
(`func_87F025B8(pool, NULL)`). If one is free, re-init its model at +0x24
with `func_8003F1DC`/`func_8003F114(model, 0, -1, models_114[i])` and set
scale 0x54..0x5C to 0.1f. It matches only as a non-void function with no
`return` (marked `//!bug`): the reserved return register makes IDO compute
`obj + 0x24` from `$s0` instead of `$v0`. The caller ignores the value; the
prototype is retyped to `s32`. Found by a 180-second permuter, which
changed the return type.
