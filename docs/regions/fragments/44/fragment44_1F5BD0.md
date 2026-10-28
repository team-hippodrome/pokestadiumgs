# fragments/44/fragment44_1F5BD0.c

## 2026-10-28: `func_8AF07AAC` requeue

requeue (0.90). `(s32 arg0)`: copies D_8AF26568 to D_8AF26570, stores arg0 in D_8AF2BE84, calls func_8AF05C10 and func_8004C8C0(0xAB), and stores func_8004C990(0xAB, 2) in D_8AF2BDCC. Then two branches:
- if D_8AF26564 is set: copy the two ints to the state's +0x4E0/+0x4E8, and call func_8AF05EE0(state) when func_8AF05E94(sub = state + 0x28) is neither -1 nor sub+0x4B4.
- else if D_8AF26568 is set: copy them, and store `(*(s16 **)(D_8AF2BDD8 + 8))[0xC]` into +0x510 and then +0x514 (chained assignment, 0x514 written first in C).

Finally it clears D_8AF2C680. Best: `scratch` spelling with a separate `sub` local, plus a separate `u8 *other` for the else branch, and no `value` local. The only mismatch is register naming: retail loads D_8AF26568 into $v1 and keeps the s16 value in $t6, where ours uses $a0/$v1. The permuter only found a comma-expression fake (15). Next: give the else-branch condition its own temporary, or try a typed state struct, which changes $a0 pressure.
