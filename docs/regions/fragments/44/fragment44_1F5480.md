# `src/fragments/44/fragment44_1F5480.c`

## 2026-10-27 — `func_8AF07210`: matched

Clears bit 0 of halfword +0x02 in `*D_8AF2C638`/`*D_8AF2C63C`, sets the colors at +0x28/+0x2C of `*D_8AF2C640`/`*D_8AF2C644` to 0xC3A05AFF/0xE1C38CFF, then for `D_8AF2C654` 0 sets the `*D_8AF2C63C` bit and both `*D_8AF2C640` colors to 0xFFFF00FF (1: `*D_8AF2C638` and `*D_8AF2C644`), as a `switch`. Written with `u8 *` globals and cast offsets, with the stores in the order above; this spelling reproduces retail's a1/a3/t0/t3 allocation.
