# Region notes -- src/fragments/32/fragment32_1B9390.c

## 2026-10-27 — `func_883083C8` / `func_88308464`: requeue (shared idiom)

These two search backward and forward from the `s16` index at `arg0 + 8`
through `D_88601898` (a `u16 **` record table) for the first record
`func_886000F0` accepts, and return the `u8` distance or 0. The forward
variant stops at the `u16` limit at `arg0 + 0xC`. Best: normalized 0.9231
with `s32 at_start = 0; if (*(s16 *)(arg0 + 8) == 0) at_start = 1; if
(at_start) return 0;` and then `while (TRUE) { if
(func_886000F0(*D_88601898[i])) return count; if (i == 0) return 0; count++;
i--; }`. The only residual is that the target branches (`b`) to the very next
instruction after setting the flag. Empty then/else arms, goto-join,
`do/while(0)` + `break`, `switch`, ternaries, `&&`/`||` forms and `if (1) {}`
all omit that branch. Permuter 240 s: no improvement. Next: find a matched
owner with the same `or v0,zero; bnez; b next; addiu v0,1` join and copy its
source idiom.

## 2026-10-27 — `func_883083C8` backward search accepted; `func_88308464` narrowed

`func_883083C8` is now C (**39 words / 156 bytes**, frame 0x28). The
branch-to-join after `flag = 1` comes from an `if (cur == 0) { flag = 1; }
else { flag = 0; }` with **no initializer** on the flag. With
`s32 flag = 0;` plus a then-only arm the `b` disappears; that was the
earlier 0.92 plateau. Initialize `count = 1` immediately before the loop
(declaring it with `= 1` hoists the `li` ahead of the flag's `or`). The same
then-arm-jumps-over-else shape is confirmed by `func_8AF1F294`
(`fragment44_20D3A0.c`).

`func_88308464` (forward search to the `u16` limit at `arg0 + 0xC`) is still
a requeue, now at 0.78. The same if/else flag and
`for (i = cur + 1, count = 1; ; i++, count++)` with
`if (i + 1 == limit) return 0;` match the control flow. The remaining
difference is that the target recomputes `cur + 1` for the loop start (no
CSE with the flag test) and keeps `i + 1` and `i++` as separate adds. A
180 s permuter run reaches score 10 only with slop (`cur ^ 0` and a `u16`
limit local).
