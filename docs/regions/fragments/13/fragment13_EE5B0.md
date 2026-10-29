# fragment13_EE5B0

## func_824008C4: requeue at 0.98 (2026-10-28)

Scene state machine `s32 f(s32 arg0)` with states 0..2. It needs a *local*
`s32 state = arg0;`: retail keeps it in the frame at `0x1C(sp)`, not in `s0`
or in the argument home. Then `switch (state)` with the bodies below matches
except for one scheduling slot:

- case 0: `D_82409288 = D_82409284 + 1`; if `StageContext_GetFadeMode() == 0`, set state 1.
- case 1: if `func_82406CCC(D_824090A0)` succeeds, then if the s32 at `+0x210`
  is set, `func_82404DD8(D_824090A0)` != 0 gives `func_800226C0(17); D_824092B0 = 0;`.
  Otherwise set state 2, then `StageFade_StartFromTransparent(12); func_80035424(24);`.
- case 2: if the fade mode is 1, set state 3.

Retail fills the `beqz v0` delay slot after `func_82406CCC` with
`lui a0, %hi(D_824090A0)` and emits the `addiu` after the branch. Ours hoists the
`lui` above the branch and puts the `addiu` in the slot.

Already tried without gain:
- `break` guard
- `== 0` ordering
- a `u8 *group` local, before or after the call
- `[0x210]` / `((s32 *)D)[0x84]` spellings
- a result temp
- if-chain instead of switch (much worse)
- 180 s of permuter

`func_82404DD8` (fragment13_EEC50) is now typed
`s32 func_82404DD8(u8 *)`, returning `func_81A00074`'s result; this caller
consumes it (declaration-only change, ROM verified).

## 2026-10-29 — `func_824005D8` requeue

Model-anim reset callback (`scratch/c/5d8_best.c`, normalized 1.0,
raw 0.83):

- The animation id is
  `((s16 *)(state + x1A0 * 2 + 0x54))[x16A]`. That spelling gives retail's
  load order.
- `switch` cases 9/0x2A/0xB add 1/5/9 to `state->x1F4`, then
  `func_8003F1DC` / `func_8003F114(arg1, 0, -1, func_80071ADC(D_82409FC0, D_82408EE0[index]))`.
- Retail's frame is 0x28 (ours 0x20).
- Retail hoists `lui %hi(D_82407458)` into `$t2` above the `arg0 != 2`
  test (ours loads it after, in `$t3`). A `type` local, an `s16` id and a
  separate model local don't change it.
- Next: find the extra 8 bytes of locals and a shape that evaluates the
  table pointer before the guard.
