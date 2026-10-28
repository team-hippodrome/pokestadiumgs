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

## 2026-10-29 — `func_84105630`: requeue

Status: **requeue**, 0.91 (119/119 text words). The 2026-10-29 session's body
is `scratch/c/630a.c`. It is a `switch (arg1)` over cases 0..4 (1 and 2 empty).
- Case 0: `D_84190074 = Gfx_AllocDisplayList(0x5BE0)` and
  `D_84190070 = 0`.
- Case 3, with `ctx = D_80094908` loaded before the switch:
  - `func_8410933C(arg0)`, `gSPPerspNormalize(*(u16 *)(ctx+0x28))`;
  - `gSPMatrix(ctx+0x24, NOPUSH|LOAD|PROJECTION)` and
    `gSPMatrix(ctx+0x60, NOPUSH|MUL|PROJECTION)`;
  - `gSPDisplayList(D_8416A1C0)`, `func_84103394()`,
    `gSPDisplayList(D_8416A170)`;
  - `guOrtho(D_84190074+0x5B80, 0, 320, 0, 240, -2, 2, 1)` and its
    `gSPMatrix(... & 0x1FFFFFFF, LOAD|PROJECTION)`;
  - `func_84103478(arg0)`, `gSPDisplayList(D_8416A170)`.
- Case 4: `func_84105CF0()`.

Remaining: retail holds `ctx` in `$a3` (and reloads it into `$a0` after the
call); ours uses `$a2`. A third parameter (with the caller passing `arg2`
again) only homes `$a2` and does not move `ctx`.
