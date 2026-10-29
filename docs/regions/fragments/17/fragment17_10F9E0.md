# fragment17_10F9E0 matching notes

## 2026-10-29 — `func_82200374`: requeue (delay slot only)

Phase-to-step map. `switch (D_8220E2D0)` returns 1 for case 0; 7 or 2 for
case 1 (by `*(s16 *)(&D_8220E2D0 + 0x24)`); 3, 4, 5 for cases 2-4; and
`result = 6` for case 5. Otherwise it returns `result` (= 0). The caller's
`extern void func_82200374(void)` in front of `func_822003EC` must go (a
companion edit). Every instruction matches except the tail: retail fills the
final `jr ra` delay slot with `or v0, v1, zero`, while ours puts the move
before the `jr` and leaves a `nop`. Also tried: no `break` on case 5, a
separate `result = 0`, an explicit `default`, `u8 result`, and the permuter
(120 s, flat at 60).

## 2026-10-29 — `.data` owned in C; `func_82200020` requeue

`fragment17_10F9E0` now owns its `.data` (0x11D0B0–0x11D130):

- four `s16` animation key lists;
- their `{ s16, s16 count, s16 *keys }` records;
- `D_8220D758[4]`, the record table `func_822000F0` reads;
- `static s16 D_8220D768`, `D_8220D76C`. IDO 4-aligns each, matching
  retail.

The fragment17 data blob now starts at 0x11D130.

`func_82200020` (geo callback that slides `x8` by 0x40 up to 640;
**requeue**, `scratch/c/020_best.c`):

- The logic is right. Retail re-forms `lui $at` for every access to
  `D_8220D768`/`D_8220D76C` and keeps the slide in a truncated `s16`
  register.
- Ours CSEs the address into `$v1`, whether the variables are extern or
  in-file static.
- Next: find the access shape that stops IDO materialising the base, for
  example separate expressions per block, or a `switch` with `return` per
  case and no shared local.
