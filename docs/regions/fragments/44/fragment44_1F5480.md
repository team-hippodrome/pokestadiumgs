# `src/fragments/44/fragment44_1F5480.c`

## 2026-10-27 — `func_8AF07210`: requeue

requeue (register allocation). Clears bit 0 of halfword +2 in *D_8AF2C638/*D_8AF2C63C, sets words +0x28/+0x2C of *D_8AF2C640/*D_8AF2C644 to 0xC3A05AFF/0xE1C38CFF, then for D_8AF2C654 == 0 sets bit 0 on *D_8AF2C63C and both colors of *D_8AF2C640 to 0xFFFF00FF (== 1: *D_8AF2C638 and *D_8AF2C644). Structure matches; the target keeps the four global addresses in a1/a3/t0/t3 while IDO allocates a2/a3/t2 (0.43). Permuter 90 s: 270 -> 145.
