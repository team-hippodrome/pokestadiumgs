# Region notes -- src/fragments/51/fragment51_279A20.c

## 2026-10-27 — `func_86303E54` button flag toggle accepted

`func_86303E54` is now C: **43 words / 172 bytes**, frame 0x18. When bit 0x10 of the halfword at
`D_80087208 + 8` is set, it toggles the one-bit flag at the top bit of `D_863075D8 + 0x8F51` (`u8` bitfield), then
clears bit 0 of the halfword at `D_80087208 + 0x10` on both arms of an `if`
on the new value (kept as `// karodo`; collapsing the arms changes the code).
Finally it calls `func_87F04894` while the flag is set. Its twin is
``func_864079AC` (`fragment52_285750.c`)`.

Write the toggle as the condition itself: `if (s->flag ^= 1)`. `!flag`
emits `sltiu` instead of `xori`; a separate `^=` statement adds a reload;
`1 - flag` and a single-arm `if` change the code.
