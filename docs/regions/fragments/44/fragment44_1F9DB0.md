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

## 2026-10-27 — `func_8AF0D704` mode-dependent setup accepted

`func_8AF0D704` is now C: **49 words / 196 bytes**, frame 0x18. It switches
on the `s16` mode `D_8AF2ECF8`. Modes 0 and 2 store 48/49 into halfword
+0x32 of the records at `D_8AF2E8DC`/`D_8AF2E8E0` and set bit 0x2 of the
second record's +2 flags. Mode 1 stores 269/270 and sets or clears that
bit according to this file's `func_8AF00020()`. A plain `switch` with
`case 0: case 2:` sharing one arm matches directly.

## 2026-10-28: `func_8AF0C6F8` handoff

requeue (0.54). Counts the distinct first-byte ids across 0x14-byte records
into `D_8AF2E8F8`. The lookup cursor is not reset between records: retail
sets it once before the outer loop. The nested-while draft is 0.54; retail
lays out three blocks with back-branches and an `s16` count.
