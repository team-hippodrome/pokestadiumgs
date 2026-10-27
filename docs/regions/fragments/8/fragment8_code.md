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

## `func_82F019CC`: strided-byte drawing callback

The 144-byte owner (36 instructions, 40-byte frame) gets the transition
weight, draws the resource records, calls `func_82F01658` for one state
byte, then draws the resource selection. It uses the same callback and
helper interfaces described above, passing the incoming rectangle's first
two signed halfwords and the weight captured before the records draw.

Its selected byte is at `state + 88 * state[3790] + state[3792] - 31`.
Compiled `func_82F00580` reads the same address for `func_80062CE0`, using
the same 88-byte array view. This view expresses the address arithmetic;
it does not establish the broader meaning of the indexed bytes. Original
`func_82F01A5C` copies up to six records with an 88-byte destination stride, and
compiled `func_82F01BAC` initializes the encompassing 3832-byte state.
No new guard or index normalization changes the lookup.
//@src/fragments/8/fragment8_code.c

The resource entry beginning at `D_82F03090` references this callback.
Compiled `WidgetDefinitions_Draw` invokes it with the definition pointer,
state pointer and four-halfword rectangle. The local draw aggregate holds
the weight and selected byte consumed by the helper, preserving the weight
spill at stack offset 32. Existing callbacks, helpers, tables and state
storage remain unchanged.
//@src/fragments/4/fragment4_B2D00.c

The first C recipe matches all 36 original words. Fresh validation uses
master `992cda39a8acb96e3797d448d5be79c09f3a9705` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/8/fragment8_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The default host syntax check, forced source compilation and complete US
link pass with `build/pokestadiumgs-us.z64: OK`. The ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the retail byte comparison and whitespace
check pass. The original instruction words and retail span
`0xCE07C..0xCE10C` compare exactly. No new fakes, padding members,
instruction rewrites, data/layout, generated reports or CI changes are added.
