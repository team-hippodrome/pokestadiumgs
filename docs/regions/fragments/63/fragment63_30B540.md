# `src/fragments/63/fragment63_30B540.c`

## 2026-10-27 — `func_87E07F4C`: requeue

requeue. Maximum of the four words at `arg0 + 0x2190 + i * 0x18`. The plain `max = e0; if (max < e1) …` chain (with a `void *` parameter, as the later prototype requires) reaches 0.95; retail loads `e1` before `e0` and copies `arg0` into `a1` for the last two reads, the signature of a copt-unrolled loop over a pointer copy. Indexed, pointer-walking, `!=` and struct-array loops are all left rolled by copt (0.29–0.42). Next: find the loop shape copt unrolls with an `if` body (see the `for` notes in AGENTS.md §5).

## 2026-10-28 — `func_87E07E38`: requeue, temp-numbering residual

Returns the first of four 0x18-byte slots (base +0x2190) whose `marked` bit
is set (the s16 at +0x16 is negative). The slot must also pass the mode test
on `*(s8 *)(arg0 + 0x218E)`: mode 0 always passes; modes 1 and 2 pass when
the `tested` bit (bit 14 of the word at +0x14) is clear. Finally, its id plus
`*(s8 *)(arg0 + 0x218D)` must reach `*(s32 *)(arg0 + 0x2188)`; otherwise
return -1. The caller `func_87E07F18` must pass `arg0` (it currently calls
with no arguments and relies on `a0`). Best form (40/40 instructions, branch
layout identical): `s32 ret = -1; s32 found = 0; s32 i;`, a `for (i = 0;
i != 4; i++)` loop, `switch` with `case 1: case 2:` (test
`(word << 17) >= 0`) before `case 0:`, and `ret = i; break;`. Returning `i`
directly makes copt unroll the loop twice (71 instructions). Residual: our
temps start at `$t6` where retail's start at `$t7`. A 240-second permuter got
75 -> 25 only by splitting the shift (`<< 11 << 2 << 4`), which hints at a
bitfield read. But a file-level `Fragment63Slot` bitfield indexed through
`(u8 *)arg0 + 0x2190` changes the indexing (0.41).

### `func_87E07E38` matched (2026-10-28, follow-up)

The temp-numbering residual came from the two bit tests. Both must be
unsigned 1-bit extracts, as IDO lowers bitfield reads:
`(u32)*(u16 *)(slot + 0x16) >> 15` for `marked` (retail's `lh`/`bgez`) and
`!(((u32)word << 17) >> 31)` for `tested`. The sign tests `< 0` / `>= 0`
use one temp fewer and shift every later register. The rest of the earlier
best form (`ret`/`found`, `case 1: case 2:` before `case 0:`, `ret = i;
break;`) is unchanged. The caller now passes `arg0`, and the K&R prototype
is retyped.

## 2026-10-29: `func_87E07CD0` tooling-blocked

tooling-blocked (uncached globals, 0.38). Two 30-button cheat sequences: compare D_80087200's pressed buttons against `D_87E1A180[D_87E1A1F8]` and `D_87E1A1BC[D_87E1A1FC]`. On completion it plays 0xCF0C and calls func_87E07CB0 / func_87E07C90; on a mismatch the index resets. The logic matches, but retail re-forms each counter's address with `lui $at` per store, where IDO caches the address in $a1. This is the known per-access global-address shape; no C spelling found yet. Also note: controller.h conflicts with this file's `D_800CE060` byte-array declaration.
