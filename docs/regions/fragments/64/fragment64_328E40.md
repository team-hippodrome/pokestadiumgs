# fragments/64/fragment64_328E40.c

## 2026-10-29: `func_87F06240` requeue

requeue (0.73). `(s16 x, s16 y, f32 scaleX, f32 scaleY, s32 digit)` draws digit texture `func_8004C990(0x1AD, D_87F10CD0[digit % 10])` through GfxRect_DrawTextured with rounded `w*scaleX`, `h*scaleY`, `1024/scaleX` and `1024/scaleY` (u16 dims convert as unsigned). Instruction stream and branches match. Remaining: retail's frame is 0x50, ours 0x48. Retail spills scaleX before reusing $a2 for `digit % 10`, and its float temp slots are texture at 0x4C, roundW at 0x3C and the height spill at 0x34. A 720-order declaration sweep (texture first, roundW 5th, height 7th) topped out at 0.86. Next: different variable set (e.g. explicit rounded s16 temps), or `digit` reassigned in place.
