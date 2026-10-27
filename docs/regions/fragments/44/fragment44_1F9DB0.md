# Region notes -- src/fragments/44/fragment44_1F9DB0.c

## 2026-10-27 — `func_8AF0BB40` move filter accepted

`func_8AF0BB40(s16 move)` is now C: **44 words / 176 bytes**, frame 0x20.
It returns 0 for moves 248, 237 and 251. Otherwise it looks up halfword
`move - 1` in the table at `D_8AF2BA98` (any bit set passes), or, when the
move's type from `func_80062D98` is 0x1B, in the table at `D_8AF2BA9C`
(bit 0x8000 must be set). `move` follows `func_80062D98`'s other callers,
which store its result as the move type.

Write the three exclusions as separate `if`/`else if` arms (a single `||`
test is 20 bytes shorter) and select table and mask together in one
`if`/`else`.
