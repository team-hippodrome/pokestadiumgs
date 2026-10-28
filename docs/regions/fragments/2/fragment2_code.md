# fragment2_code

## 2026-10-28 — `func_81900164` matched (model slot reset); `D_81900820` typed

`D_81900820` is now `Fragment2State`: `active[4]`, `scale` @0x10,
`unk_014` @0x14, `unk_01C` @0x1C, and `Fragment2Model models[4]` (0x168
each) from 0x20 to `D_81900DE0`. `func_81900164(arg0, x, y, scale, slot)`
stores `scale` *before* `active[slot] = 1` (that order schedules like
retail), clears `unk_014`, resets the model with
`func_8003F114(model, 0, -1, unk_01C)`, then zeroes 0x30..0x38 and sets
x/y/index. The `model` local must be used only for the call argument:
taking it for every store changes the allocation (0.54). Without it the
CSE'd model base spills to 0x1C instead of 0x18. A 240-second permuter found
the store order; the permuter ignores stack offsets, so check spill slots
with the gate.
