# fragment43_1E5A10 matching notes

## func_8AC01F8C

This owner emits the existing display list `D_80094DB8`, writes a horizontal
coordinate to the output record's signed halfword at offset 8, and increments
an unsigned halfword counter. Its phase is the low 16 bits of
`step * (counter & mask)`. Shifting that phase right by 4 indexes the existing
float table `D_80087E50`; the sample is multiplied by the signed amplitude and
added to the signed base coordinate. Conversion truncates toward zero before
the halfword store. The output pointer is captured before the display-list
write, and the counter is read again after the output store, preserving the
original access order when records overlap.

The state view follows the original loads: output pointer at offset 0, base
coordinate at 10, amplitude at 20, counter at 22, step at 24, and mask at 26.
Other bytes remain opaque. The unsigned multiplication makes the phase's
modular arithmetic explicit. The views and extern declarations allocate no
new storage; both display-list and sample-table ownership remain unchanged.

Original `func_8AC02564` obtains this state through its second argument's
pointer at offset 32 and dispatches to this owner with that pointer. Its
initialization path copies the output's coordinates at offsets 8 and 10 into
the state's base coordinates at offsets 10 and 12. Existing C
`func_8AC02770` clears a 48-byte state, stores the output pointer and mode,
and registers `func_8AC02564` through `func_8004E308`. These operations support
the coordinate and state roles; the address-based function name is retained.
//@src/fragments/43/fragment43_1E5A10.c

The first ordinary typed-record and SDK-macro candidate matches all 40 words
(160 instruction bytes), with no stack frame. An explicit unsigned phase
product preserves the same bytes. No new fakes, instruction rewrites, padding,
or data-layout changes are needed.

Fresh verification uses master `dad8c110d74a4d9d5458abdcfa56742d9357b4d8`
plus this source change. The unchanged imported baseline passes first.
`make -W src/fragments/43/fragment43_1E5A10.c -j4 VERSION=us rom` forces the
normal syntax-enabled compilation and complete link. The checksum acceptance
is `build/pokestadiumgs-us.z64: OK`, with ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and
`git diff --check` pass. The complete owner span at ROM
`0x1E797C..0x1E7A1C` independently matches all 160 original bytes.
