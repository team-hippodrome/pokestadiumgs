# fragments/83/fragment83_code.c

## 2026-10-29: `func_82C0273C` requeue

requeue (0.70). For six rows: set `*(s32 *)(D_82C05E80 + j*0x4B28 + 0x148) = 1`; for six slots, copy `D_82C05E80[j*6 + 0x4C + i]` into `rec[5 + i]` and `((u16 *)(rec + 0xC))[i]` (with `rec = D_82C05FC8 + j*0x4B28`, i.e. +0x148). Then OR `1 << i` into `rec[4]` when `func_82C02664(*(u8 **)(&D_82C04C38 + 0x18) + 0x14, value)`. Retail's outer loop is pointer-driven: $s7 steps 6 up to D_82C05EA4, $fp is a copy of $s7 stepping 0x4B28, and $s4 steps 0x4B28 from D_82C05FC8. A three-pointer `for` reaches the same instruction stream except that IDO initializes $fp first and copies it into $s7 (reversed). Neither declaration order nor init order changes that.

## 2026-10-29 — shuffle-order state owned as file bss; `func_82C02834` requeue

`D_82C05E80` is now `static Fragment83OrderState`, size 0x14C, with
`order[0xFC]` at +0x4C. It is pinned at 0x82C05E80 by `datamig_bss.ld`.

`func_82C02834` (**requeue**, `scratch/c/834_best.c`; needs a companion
edit retyping `extern void func_82C02834(s32)` to `(u8)`):

- The switch with three one-line `for (i = 1; i < 0xFC; i++) order[i - 1] = ...`
  loops is exact. `copt`'s peeled shared-`$at` stores reproduce once the
  struct is defined here.
- The only difference: the trailing `unk_006 = 0; unk_000 = 1;` CSEs the
  struct base (`lui v0`/`addiu v0`). Retail uses one shared `lui $at` with
  `%lo` stores.
- Splitting the head fields into separate statics breaks `order[]`'s base
  encoding (retail addresses the loop from `0x82C05E84 + 0x4B`, i.e. one
  object from 0x82C05E80). Separate statics also realign standalone
  arrays.
- Next: find a source shape for the two tail stores that doesn't CSE a
  base, perhaps a pointer- or macro-based access the original used.
