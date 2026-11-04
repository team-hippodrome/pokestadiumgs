# fragments/64/fragment64_328E40.c

## Historical 2026-10-29 investigation (resolved below)

requeue (0.73). `(s16 x, s16 y, f32 scaleX, f32 scaleY, s32 digit)` draws digit texture `func_8004C990(0x1AD, D_87F10CD0[digit % 10])` through GfxRect_DrawTextured with rounded `w*scaleX`, `h*scaleY`, `1024/scaleX` and `1024/scaleY` (u16 dims convert as unsigned). Instruction stream and branches match. Remaining: retail's frame is 0x50, ours 0x48. Retail spills scaleX before reusing $a2 for `digit % 10`, and its float temp slots are texture at 0x4C, roundW at 0x3C and the height spill at 0x34. A 720-order declaration sweep (texture first, roundW 5th, height 7th) topped out at 0.86. Next: different variable set (e.g. explicit rounded s16 temps), or `digit` reassigned in place.


## 2026-11-04: `func_87F06240` genuine match

The renderer selects the digit texture, scales its unsigned width and height,
and rounds the two extents and texture steps with a signed half-unit bias.
A four-byte texture extent prefix supplies the verified width/height fields.
The fully consumed 12-byte metrics record contains two `s16` extents and two
`s32` texture steps; it reproduces the retail 80-byte frame without padding.

The height bias and both reciprocal/step-bias calculations form one sequenced,
multiline C expression. Every assignment supplies an actual draw argument.
The comma operators preserve calculation order and give CFE one source
statement for these calculations. This resolves AS1's ordering tie between
the scale-Y reload and the negative-half constant. Five separate statements
retain the swapped pair; collapsing only the reciprocal calculations also
fails. The match depends on expression structure, not an absolute source
line number: independent normal and 20-leading-blank whole-module compiles
both match. No `#line` directives or compressed code are needed.

All 123 instructions (492 bytes), allocated module sections, symbol extents,
and semantic relocations match retail under unmodified native IDO 7.1.
`make -j1 COMPARE=1 RUN_CC_CHECK=1` passes with the 64 MiB ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The word-swap pragma and unused
`pad[3]` are removed. Compiler options, linker layout, and coverage are not
changed by this cleanup.
