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

## Frame-driven alpha callback

`func_87F0691C` matches as C: 99 instructions, 396 bytes, with its original
48-byte frame. Event zero clears bit 1 of the node's unsigned halfword at
offset 2. Event one draws through `func_87F06804` with RGB `0xFFE600` and a
clamped alpha; other events do nothing. The unsigned frame counter at
`D_87F15B88 + 40` is reduced modulo 360, multiplied by 5 and
182.0416718, and rounded by adding or subtracting 0.5 before truncation.
The low 16 bits shifted right by 4 index the existing sine table. The
sample is mapped through `(sample + 1) * 0.5`, multiplied by 455, offset
by -100, rounded again, and clamped to 0 through 255.

`func_87F07FE8` increments that counter before traversal. The original
`func_87F06EAC` registers this callback for DBP1/DBP2 through
`func_87F0AB08`; that registration interface takes a void callback.
The draw helper consumes the packed color by value. These inspected
interfaces establish the event and draw roles without renaming the owner.
//@src/fragments/64/fragment64_3290A0.c
//@src/fragments/64/fragment64_32D260.c

The repeated phase expression is labeled `FAKE`: caching it in a local
changes the floating-point register allocation. The real normalized-wave
and scaled-wave locals preserve the original rounding registers. The
existing aggregate color type and its `FAKE` annotation remain intact.
The float literals occupy the original `D_87F115C0`/`D_87F115C4` slots;
data ownership, section sizes, and previous C implementations are unchanged.

Fresh verification targets master
`149f6559ed4d51b884e6ebea43b7f717b3ecd500` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_3290A0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled forced compile and complete US link report
`build/pokestadiumgs-us.z64: OK`. Retail byte comparison and whitespace
checks pass; both ROMs have MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
All 7760 linked module text bytes and 352 rodata bytes equal retail,
including the owner's ROM interval `0x32958C..0x329718` (end exclusive).
The two changed object operands are equivalent relocations from named
float symbols to their section offsets. No generated layout, compiler,
CI, padding, new storage, or instruction rewrite is introduced.

## Two-color alpha callback

`func_87F06AA8` matches as C: 159 instructions, 636 bytes, preserving its
48-byte frame. Event zero clears bit 1 of the node flags at offset 2.
Event one selects RGB `0xFFE600` when the node word at offset 32 is zero,
or `0x8CDCFF` otherwise. Both paths derive the sine-table index from the
unsigned frame counter modulo 360, multiplied by 5 and 182.0416718 and
rounded by adding or subtracting 0.5 before truncation. The zero-data path
uses `(sample + 1) * 0.5`; the other uses `(1 - sample) * 0.5`. The shared
tail scales by 455, subtracts 100, rounds, clamps alpha to 0 through 255,
and draws through `func_87F06804`. Other events do nothing.

The original `func_87F06EAC` registers this callback for EVP1 through EVP8
using `func_87F0AB08`, supplying zero callback data except for EVP8's one.
`func_8004E308` stores that data at node offset 32 and invokes event zero;
the registration interface takes a void callback. `func_87F07FE8` advances
the frame counter before traversal. These inspected producers and callees
establish the fields used here without assigning a broader meaning to them.
//@src/fragments/64/fragment64_3290A0.c
//@src/fragments/64/fragment64_32D260.c
//@src/4EE50.c

A local union exposes the packed argument and RGBA channels, allowing the
alpha-byte update without a cached byte pointer. Its packed member uses the
existing one-word aggregate; that type's `FAKE` annotation remains intact.
The repeated phase expressions are also labeled `FAKE`, following the
matched sibling's floating-point allocation. All locals have actual uses.
The existing float slots and other C implementations retain their bytes.

Fresh verification targets master
`8563b92e9e4b909456990605743358d4baa92b1c` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_3290A0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled forced compile and complete US link report
`build/pokestadiumgs-us.z64: OK`. Retail byte comparison and whitespace
checks pass; both ROMs have MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
All 7760 linked module text bytes and 352 rodata bytes equal retail,
including the owner's ROM interval `0x329718..0x329994` (end exclusive).
Three object operands change from named float symbols to equivalent
section offsets 136, 140, and 144; every other text byte and all rodata
bytes equal the assembly-backed baseline. No generated layout, compiler,
CI, padding, new storage, or instruction rewrite is introduced.
