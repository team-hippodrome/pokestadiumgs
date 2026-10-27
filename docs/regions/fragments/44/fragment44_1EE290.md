# fragment44_1EE290 matching notes

## func_8AF0007C

This one-word, void owner refreshes input through `func_80064D28`, copies
40 bytes from the controller pointed to by `D_80087200` into existing
`D_8AF2A590`, then conditionally clears three input halfwords through
`D_8AF263C0`. The snapshot precedes those stores. Input remains enabled only
when signed halfword `D_8AF2BDDC` is at least 4, word `D_8AF2BDD0` is zero,
and the incoming argument is 1. Other cases clear pressed, held, and repeat
at byte offsets 8, 6, and 12, respectively. The global pointer is reloaded
for each store, preserving the original alias behavior.

The original aggregate copy performs three 12-byte iterations and one final
word transfer. Its aligned word loads/stores and complete 40-byte extent
support the local structure view. Bytes outside the three input halfwords
remain opaque. All declarations are external; storage ownership and layout
remain unchanged.
//@src/fragments/44/fragment44_1EE290.c

Existing `MenuInputState` and compiled `func_8AF133C0` consume offsets 6, 8,
and 12 as held, pressed, and repeated input. The actual no-argument, void
`func_80064D28` starts controller input reads and calls the existing input
and UI updates. Compiled `func_8AF01EAC` passes its word state to this owner
and consumes no result. Its stale local result declaration is corrected to
void; independent comparison preserves all 84 caller instructions.
//@src/fragments/44/fragment44_1FD260.c
//@src/65820.c

The first aggregate-copy recipe matches all 45 instruction words (180 bytes)
and the original 24-byte frame. Existing address-based names and neighboring
C remain. No new fakes, qualifiers, padding, instruction rewrites or CI changes
are required.

Fresh validation uses master `3fab4ae5dc818b9b491874fdbe2833795b067377`
plus this patch. The unchanged baseline passes its own complete US ROM build
and retail comparison. Final validation forces recompilation through the
default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/44/fragment44_1EE290.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 180 bytes at ROM `0x1EE2EC..0x1EE3A0`.

## 2026-10-27 — `func_8AF01C84`: requeue

requeue (temp numbering). gSPDisplayList(D_80094E38), gDPSetPrimColor(0, 0, 255, 255, 255, 255), then 28 strips func_8AF01A0C(x, y + 4i, 96, 4, texture + 0x300 * i, 96), then gSPDisplayList(D_80094F50). An `s32` first parameter copied into an `s16 x` local fixes the home-slot store (0.77); the residual is the prim-color temps (target t1/t2, IDO t0/t1). Permuter 75 s: 610 -> 225.
