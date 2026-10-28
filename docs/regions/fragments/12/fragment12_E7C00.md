# fragment12_E7C00

## 2026-10-28 — `func_81403244` matched (stack a new row); rows typed

New file-level types: `Fragment12Row` (0x210: `f32 values[0x80]`,
`unk_200`, `unk_204`, `s16 unk_208` (negative = free), `unk_20A`,
`unk_20B`, `unk_20C`; the fields `func_81402930` initializes) and
`Fragment12Rows` (`rows[6]`, `f32 unk_CAC` @0xCAC, `s8 unk_CB0` @0xCB0).
`func_81403244(rows, arg1, arg2)` takes the highest `values[unk_CB0]` across
the six rows, seeded with `unk_CAC + 180.0f`. It then initializes the first
free row at `max + 22.0f + 1.0f` via `func_81402930(row, y, arg1, arg2)`.
Typed indexing gives retail's base-first `addu`; raw byte offsets give
index-first. The caller `func_81403918` now declares and forwards `arg1`/
`arg2`; it previously took one argument and relied on `a1`/`a2` passthrough
(same bytes).

## layout-prerequisite: jtbl owners in the shared rodata blob (2026-10-28)

`func_8140438C` (`jtbl_81407ADC`) and its jump-table siblings `func_81404040`,
`func_814040D8`, `func_81404470`, `func_8140463C`, `func_814046C4` and the
head of `jtbl_81407B2C` all live in the anonymous `[0xECC60, rodata]` blob.
That blob is entirely this file's rodata. In emission order:

- data: `D_81407950/54` (asm `func_81403758`); the C-referenced `const s16`
  tables `D_81407968`, `D_81407A08`, `D_81407A1C`, `D_81407A2C`; then asm data
  for `func_8140487C`, `func_814057CC`, `func_81405CC4`
- floats: `D_81407A98` (`func_81402A64`), `D_81407A9C` (`func_81403400`)
- jump tables in function order from `jtbl_81407AA0` on

Moving the subsegment start from 0xECE50 to 0xECC60 needs the four C tables
defined in C at the right point in that order. Next action: define them, re-split,
gate with every owner still in assembly, then write the switches. All six
dispatchers are short `switch` + call shapes (e.g. `func_8140438C`: 5 cases on
the u8 at `+0xC`, each `x = func(arg0)`, then a guarded `func_81600A34` call
with four s16s from `func_81403E7C`).
