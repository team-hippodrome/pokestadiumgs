# Fragment 41 code matching notes

## 2026-10-29 — `func_88C00AB0` play-clock tick: requeue

Status: **requeue**, best 0.6265 (83/83 words).

Layout: split `Frag41_State`'s leading `u8 pad00[0x20]` into `u16 days; u8 hours;
u8 minutes; u8 seconds; u8 pad05[3]; u32 lastTick; u16 frames; u8 pad0E[0x12];`
(as a companion edit). With that split, the body is `now = D_800CDA54`. If
`lastTick < now`, then `frames += now - lastTick`. Otherwise, if `now < lastTick`,
the wrap branch runs. After that, `lastTick = now`, and while `frames >=
func_80001FF0()` the code plays sfx 0x155 when arg0 == 1, subtracts, and carries
seconds/minutes/hours/days (`++days > D_88C01A60->unk2E` → 0). The cascade, the
first branch and the frame all match.

Mismatch: only the wrap branch. Retail does `lhu t9; addu t7,t9,v0; addiu
t9,t7,0x0; subu t3,t9,a1`, which is an unfolded `+ 0` between `frames + now` and
`- lastTick`. The later registers then sit one class up (t3 jump).

Tried, none reproduce it:
- `+ 0x10000`, which gives `lui at,1`.
- `(u16)` / `(s16)` / `(u32)` / `(u8)0x100` casts, `<< 16`, `* 0x10000U`,
  `0xFFFFFFFF + 1`, and a u16/s16 local `wrap = 0x10000`. All of these fold the
  constant away (82 words).
- `0x100000000` / `LL` / `ULL`, which gives `addiu at,zero,0` plus `addu`.

Next: a 64-bit or bitfield `frames` temp, a `u16` frames local stored back, or
an `f()`-style macro whose argument folds late in uopt. The permuter is
suitable once a register-only diff remains.
