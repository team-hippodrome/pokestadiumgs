# fragment64_32FE10 matching notes

## func_87F0D96C

This two-argument scene callback returns 1. On event 2, it reads callback
data through the node's offset-20 pointer. If that data's offset-4 source
node is nonnull, it copies the three-float vectors at offsets 36 and 48,
then the three signed halfwords at offset 30. It reloads the source pointer
between aggregate assignments, preserving possible aliasing. Finally it
passes the data's offset-8 pointer to existing `func_87F0D1A0`, which returns
that pointer plus 8, and copies the returned four-byte color to node offset
60. Other events and a null source leave the node unchanged.

Original `func_87F0DB3C` registers this function through `func_80037E3C`
and supplies the three-word callback record. It writes that record's first
two words from its incoming arguments. Original `func_87F0D48C` initializes
the record's offset-8 pointer. Original `func_87F0DA08` reads the destination
bytes at offsets 60 through 63 and packs them into the RGBA word of an RDP
environment-color command. Original `func_87F0D600` consumes the same four
source color bytes returned by `func_87F0D1A0`.
//@src/fragments/64/fragment64_32FE10.c

Compiled `func_80037E3C` stores the callback and data in the scene node and
calls the callback with an event word and node pointer. Its existing callback
type returns a word. Compiled `GeoNode_CreateModelPart` initializes rotation
at offset 30, position at 36, scale at 48 and a byte/word color union at 60.
Compiled `Geo_NodeModelPart` consumes those vectors in its rotation,
translation and scale operations. These producers and consumers establish
the aggregate layouts and pointer interface used by the local prefix views.
The views allocate no storage; existing address-based names remain.
//@src/229E0.c

The initial scalar color copy emits 156 bytes with two register-operand
differences. Representing the color as its evidenced four-byte union recovers
all 39 original instruction words, including the 24-byte frame, unaligned
halfword-vector copy and helper call. Existing C, helper bodies and callers
remain unchanged. No new fakes, qualifiers, instruction rewriting, layout or
CI changes are required.

Fresh validation uses master `3ffa7087e80232e82d6b719724781d1d4261fb44`
plus this patch. The unchanged baseline passed its own complete US build and
retail comparison. Final validation forces the changed source through the
default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_32FE10.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`. ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons cover
all 156 bytes at ROM `0x3305DC..0x330678`.
