# fragments/86/fragment86_code.c

## 2026-10-28: `func_844001E0` requeue

requeue (0.55). Pops a random element from a count-prefixed byte list, like ByteList_ChooseRandom: index = (u32)(count * rand_fraction) + 1. If count > 0: result = list[index], list[0] = count - 1, and `for (i = index; i <= list[0]; i++) list[i] = list[i + 1]`. Retail computes the float index and (count - 1) & 0xFF *before* the `blez count` guard. Every if/early-return/u32/s32 spelling we tried makes IDO sink the float math below the branch (lbu/blez first). Next: find a shape where index is live outside the guard (e.g. the loop outside the if with its first check folded), or the conversion written as a separate helper-like expression statement.
