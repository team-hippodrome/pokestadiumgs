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
