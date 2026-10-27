# Fragment 8 indexed-byte drawing callback

## `func_82F01958`

The 116-byte callback (29 instructions, 40-byte frame) obtains the transition
weight through `func_818055E0`, calls `WidgetResources_DrawRecords`, draws
an indexed state byte through `func_82F01658`, then calls
`WidgetResources_DrawSelection`. It passes the first two signed halfwords
of the incoming rectangle as coordinates and preserves the weight obtained
before the records draw.

The state byte at offset 3791 indexes bytes beginning at offset 3792.
The prefix view ends at offset 3808, where compiled `func_82F01C34` stores
a cached copy of that selector. It also caches the byte at offset 3792
in the next byte. The array view reproduces the original base-before-index
address addition. These operations establish byte locations and uses;
the meanings of the indexed values remain unresolved.
//@src/fragments/8/fragment8_code.c

Compiled `WidgetDefinitions_Draw` obtains a resource draw callback, computes
a four-halfword rectangle through its bounds callback, and invokes the draw
callback with the definition pointer, state pointer and rectangle. Five
fragment 8 resource entries reference this owner. The C definition uses
that same `void (void *, void *, s16 *)` interface.

Compiled `func_818055E0` selects the state's transition weight or 1.0f.
The records and selection helpers consume the same definition, state and
rectangle words. Original `func_82F01658` consumes two signed-halfword
coordinates, an unsigned-byte value and a float weight; it uses the value
for resource/color lookups and the weight for drawing alpha.
//@src/fragments/4/fragment4_B2D00.c

The local draw aggregate holds the weight and indexed byte passed to that
helper. Both members are consumed. It preserves the weight's original
stack offset 32. Separate scalar locals put it at offset 36 and differ in
two spill instructions. An earlier raw-byte view also reversed the address
addition's operands. Failed sources and complete build measurements remain
private. Existing helper bodies, global storage and resource tables retain
their ownership; the callback allocates no state.

Fresh validation uses master `20ef2789d441e6068da6f4761c9621abc8f2dfc5`
plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/8/fragment8_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and complete US
link pass with `build/pokestadiumgs-us.z64: OK`. The ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the retail byte comparison and whitespace
check pass. All 29 original words and retail span `0xCE008..0xCE07C` compare
exactly. No new fakes, padding members, instruction rewrites, data/layout,
generated reports or CI changes are required.
