# Region notes -- src/fragments/52/fragment52_2862C0.c

## 2026-10-27 — `func_864080A0` and `func_86408148` column layouts accepted

Both place the five 0x20-byte records at `D_86416C00 + 0xCE00 + 0xC`: four
in a loop, then the fifth (`+ 0x8C`) separately.

| Owner | Words / bytes | Frame | Loop | Fifth record |
| --- | ---: | ---: | --- | --- |
| `func_864080A0` | 42 / 168 | 0x30 | `func_86407E00(rec, 114.0f, 240 + 64 * i)` | `(320.0f, 86.0f)` |
| `func_86408148` | 40 / 160 | 0x38 | `func_86407E2C(rec, 110.0f, 79 + 15 * i, 40)` | `(156.0f, 86.0f, 40)` |

`func_864080A0` first stores 0 to header word +8, then -1 to +0 and +4, in
that order (the 0/4/8 order misses a store immediate).

Write `for (i = 0; i < 4; i++)` with `temp + 0xC + i * 0x20` and
`(f32)(base + i * step)`. IDO strength-reduces this into the original
pointer/coordinate induction pair. The accepted sibling `func_864081E8`'s
explicit two-variable `for (i = start, ptr = ...; i != end; ...)` form does
**not** match these two (register allocation, raw 0.93).
