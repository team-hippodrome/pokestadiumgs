# Region notes -- src/fragments/32/fragment32_1B9840.c

## 2026-10-27 — `func_8830865C`: requeue

requeue. Draws `str` via func_88308530(x, y, c) with a 19-px advance; align 1 subtracts (19*len + 1) >> 1 and align 2 subtracts 19*len + 1 (`s32 len = strlen(str)`, switch on align inside `if (align != 0)`). Best 0.83: the target computes 19*len as `len*20 + (-len)` (negu + addu) in both cases; `len * 19`, `len*20 - len` and `-len` temps give subu. Permuter 300 s: 560 -> 280 (slop). Next: a glyph-width macro or s16/u16 length type.
