# Fragment 40 1DC1F0 matching notes

## 2026-10-29 — `func_88B01C54` matched

Tiled 640x480 blit. `gSPDisplayList(D_88B05B60)` comes first, then
`gDPSetPrimColor(gfx, 0, ROUND(255.0f * (u32)*(u16 *)(D_88B05F60+0x28) / f()), 255, 255, 255, 255)`
through a `gfx = D_800D0510++` slot reserved before the rounding calls. Then
32-px steps run over `y != 480` and `x != 640`, with both texture pointers
advancing 0x200 per step. For a cell overlapping the (left, top, width,
height) rectangle: `gDPLoadTextureBlock(tex0, RGBA, 16b, 16, 16, clamp)`,
`gDPLoadMultiBlock(tex1, 0x100, 1, RGBA, 16b, 16, 16, clamp)`, then
`GfxRect_DrawTextured(x, y, 32, 32, 0, 0, 0x200, 0x200, 0)`. The real gbi
macros match on the first try.

## 2026-10-29 — `func_88B03B78`: requeue

Status: **requeue**, best 0.76 (300/300 words). The 2026-10-29 session's body
is `scratch/c/b78.c`. The whole init sequence is written out. Key expression:
`obj[3] = R(12) + Credits_RandomRange(R(80) - R(12) + 1)`, with
`R(k) = (s32)(k * f() / 60 + ((f() * k / 60 > 0) ? 0.5 : -0.5))`.

Remaining:
- Retail keeps `arg0` in `$s0` (the `(u8)` narrowing is only for
  `func_80057908`); ours homes it and reloads `lbu 75(sp)`.
- Retail addresses `D_88006868` fields 0/2/4 through a `lui/addiu $v1` base,
  where ours uses direct `%lo` relocations. That likely needs a struct or
  array declaration, which conflicts with the file's later
  `extern s8 D_88006868`; retyping it needs a companion edit.
- `*(u16 *)rec = 1; rec[3] = 1;` load 1 twice in retail and share `$v0` in
  ours.
