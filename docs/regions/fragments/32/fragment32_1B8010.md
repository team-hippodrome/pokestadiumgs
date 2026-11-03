# Region notes — fragment32_1B8010

## 2026-11-03 — `func_8830765C`: rewrite-free panel strips

Stock IDO 7.1 emits all 432 retail bytes without the two
`REWRITE_FUNCTION_WORD` directives. The function uses the existing input
pointers and the same four draw calls, in the same order.

`F32TextureSize` describes the unsigned halfwords at offsets 0 and 2.
The first halfword supplies draw width and the mirrored horizontal texture
origin. The second input's next halfword supplies the bottom strip height
and the vertical split position. Direct named-field reads preserve the
original unsigned loads, arithmetic, narrowing and per-call read timing.
The view adds no storage and leaves the function signature unchanged.
//@src/fragments/32/fragment32_1B8010.c

The previous flat-pointer form required operand rewrites for the coordinate
adds at owner offsets `0x84` and `0x148`. The size-prefix view produces those
retail additions directly. Scalar width casts, coordinate snapshots and
operand reversal had not resolved both sites; the accepted change uses the
actual width/height layout.

Validation starts from merged master
`d5a573c68f4b0431fc5c146b8d5cc0fc12461faa`. Unchanged and final source each
reproduce the complete module normally and with 20 leading blank lines,
including allocated section bytes/layout, function/object extents and
semantic relocations. The normal host syntax check passes. Native
`make -j1 COMPARE=1 RUN_CC_CHECK=1` produces retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`; all 432 linked owner bytes match retail.
Existing function/object extents, legacy addresses and fragment boundaries
remain unchanged. Compiler, linker, ABI, tooling and coverage are unchanged.
