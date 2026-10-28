# fragment44_1F1850

## 2026-10-28 — `func_8AF03E38`: requeue (clip rectangle, frame layout)

For `arg0 == 1`: `func_800504BC(angles)`. Offset the object at `arg1->+0x20`
(s16 x/y/w/h at 8/A/C/E) by the angles, store h in `D_8AF2BF78` and y in
`D_8AF2BF7C`, and set the clip rectangle `func_8AC0077C(x, y, x + w, y + h)`.
Then set `D_8AF2BF6C = (y + 0x37 < D_8AF26464)` and
`D_8AF2BF70 = (D_8AF26468 < y + h)` as if/else stores. Returns 0. Retail's
0x40 frame puts angles at sp+0x20, `y + h` at 0x2C, y at 0x34 and the
object at 0x3C. Plain locals give a 0x30 frame (0.65). The siblings'
`struct { s32 pad[2]; s16 angles[2]; }` form drops to 0.44 over all 720
local orders.
