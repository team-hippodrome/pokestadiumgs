# fragment78_code

## 2026-10-28 — `func_8F9005B4` matched (open the hex number editor)

GS twin of fragment77's `func_8F802A68`. Place the editor at
`(cell_x * 34 + 0xB4, cell_y * 22 + 0x69)` (cells `D_8F911630`/`D_8F911634`),
size 0x20×0x14, `selected = 0`, `last = 1`. Call `func_8F900574()`, then
split `numeric.value` into hex digits with signed `% 16` / `/= 16` in a
guarded `do`/`while` (as in the twin). The `F78EditorState` type and the
`D_8F911650` extern moved above this function (declaration-only, same bytes).
