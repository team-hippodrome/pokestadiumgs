# fragment31_19E800 matching notes

## 2026-10-29 — `func_8822BAF8`: requeue

Status: **requeue**, one extra instruction (89 vs 88). The 2026-10-29 session's
body is `scratch/c/af8b.c`, with a companion edit that retypes
`extern s8 D_889041B8` to `u8` in `func_8822B63C` (only stores, so the
bytes are identical; retail tests it with `lbu`). Read the button word
inline, with no `buttons` local, to get retail's `$v0`.
- Layout: the A button (0x4000) path plays sound 0x48 and calls `func_88004990`.
- The B button (0x8000) path either runs the two-case switch when
  `func_8800005C(list + 0x28)` is set, or the cases-0..4 jump-table switch
  when `func_80063754(+0x189)` is set. Otherwise it calls
  `func_8822B580(sel + 2)`.
- With no button, `func_88002720(list + 0x28, +0xC, list + 0x2C)`.

Remaining: retail computes `list + 0x28` once in the `beqz` delay slot
shared by both successors; ours recomputes it on the fall-through path. Tried
a `cursor` local (at the top or just before the test), inverted polarity, and
the permuter (300 s, no gain).
