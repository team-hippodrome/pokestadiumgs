# Region notes -- src/fragments/79/fragment79_3749B0.c

## 2026-10-27 — `func_84105120`: requeue (register allocation)

The init function zeroes `D_84190180/184/190/188` and `D_841901A8`, sets
`D_84190078[0..2] = 1.0f`, sets bytes 0–2, 4–6 and 8–10 of `D_84190218` to
255, then calls `func_8410358C`, `func_8410474C`, `func_84105D00`,
`func_84100134`, `func_841091CC` and `func_84105CA8`. Normalized 1.0 / raw
0.67. The target keeps the float base in `v1`, the color base in `v0` and 255
in `t7`; flat-array, `[3][4]`, struct, pointer-local, chained-assignment and
loop spellings all give `a0`/`v0`/`v1`. Permuter 300 s: 80 → 70 only.
Declare `D_84190218` in the batch `declarations`, because the runner
otherwise injects `fragment79_379450.c`'s `unk_D_84190218` spelling and the
probe fails to compile. Next: a struct array of RGBA colors with a real
alpha member, or the stores split around a call.
