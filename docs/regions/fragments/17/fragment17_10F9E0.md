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
