# Region notes -- src/fragments/64/fragment64_3290A0.c

## 2026-10-27 — `func_87F06430`: requeue

requeue (float scheduling). out[0] = D_80087E50[113] / D_80088E50[113] * 1000.0f * D_87F11540 * (2x - 1), out[2] = 0.0f, out[1] = same ratio * 1000.0f * D_87F11544, with x = (46.5f + column * 39.0f) / 320.0f. Best 0.77 (stores in 0/1/2 order or 1000.0f as a local); the target interleaves the out[2] zero store between the two ratio computations. Permuter 120 s: 320 -> 70.

## Colored node-texture drawing

`func_87F06804` has a matching C implementation (70 instructions, 280 bytes).
It obtains the current origin through `func_800504BC`, emits the existing
setup and combine commands, and sets environment color from the packed
RGBA argument. It looks up a texture using the node's unsigned halfwords
at offsets 36 and 38, then calls `func_8004D19C` at the signed node
coordinates at offsets 8 and 10 plus that origin, with both trailing
arguments zero. The final display list restores the existing drawing state.

The callers `func_87F0691C`, `func_87F06AA8`, and `func_87F06D24` supply the
packed color and ignore the return register. The C definition expresses
that drawing interface with `void`. The existing one-word aggregate moves
before the helper definition; its `FAKE` annotation for the already-matched
caller's stack home is preserved. The caller's body and other existing C
implementations retain their bytes.
//@src/fragments/64/fragment64_3290A0.c

`func_8004C990` resolves the archive/entry keys, and `func_8004D19C` forwards
the texture and coordinates to the existing texture renderer. The origin
helper supplies two signed halfwords from the current traversal context.
These source interfaces and the original instructions establish the draw
operation without assigning a broader role to the node or its texture.
//@src/4CC20.c
//@src/4F800.c

Verification targets master `277586f456b36a645efc65306bc22be01163eb6f` plus
this replacement and declaration cleanup:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_3290A0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled forced compile and complete US ROM link report
`build/pokestadiumgs-us.z64: OK`. Retail byte comparison passes with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All 7760 module text bytes and 352 rodata
bytes equal the assembly-backed baseline, including prior C bodies. The
owner preserves its 64-byte frame and original extent. No new fake, padding,
storage, compiler flag, or instruction rewrite is used. Behavior follows
from source and disassembly inspection.
