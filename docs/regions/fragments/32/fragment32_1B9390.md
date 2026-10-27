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
