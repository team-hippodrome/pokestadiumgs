# fragment64_32BC10 matching notes

## func_87F09040

The owner appends seven commands through the existing display-list cursor:
the display list at `D_80094DE0`, a pipe synchronization, fill color
`0xFFFFFFFF`, and four fill rectangles. The rectangles form the edges of
the region from `(22, 16)` to `(298, 224)`: top, bottom, left, then right.
Each edge uses equal coordinates on its narrow axis, preserving the original
fill-mode command coordinates rather than expanding them into a different
rectangle. Standard SDK macros produce the original command words and
cursor updates without manual command encoding.
//@src/fragments/64/fragment64_32BC10.c

The existing 32-byte display list at retail ROM `0x959E0` / VRAM
`0x80094DE0` contains pipe synchronization, fill-cycle selection, a zero
render-mode word, and an end command. Its storage ownership stays unchanged;
the new `Gfx[]` declaration is external and allocates no storage.

Compiled `func_86303F00` and `func_86407A54` conditionally call this owner
after `func_87F05204(&D_800D0510)`, without arguments or a consumed result.
Original `func_865064B0` likewise calls it before its text-drawing setup.
These callers establish the no-argument void interface. The broader screen
purpose remains unresolved, so the address-based name is preserved.
//@src/fragments/51/fragment51_279A20.c
//@src/fragments/52/fragment52_285750.c
//@src/fragments/53/fragment53_code.c

The first SDK-macro candidate matches all 56 instruction words (224 bytes),
with no stack frame. No new fakes, padding, qualifiers, instruction rewrites,
or data-layout changes are needed. Existing matched C remains unchanged.

Fresh verification uses master `cd6eebe91c9e220e99f66fde4cb56dd02e8f53cc`
plus this replacement. The unchanged baseline passes its own complete build.
`make -W src/fragments/64/fragment64_32BC10.c -j4 VERSION=us rom` forces
normal syntax-enabled compilation and the complete US ROM link. The exact
acceptance line is `build/pokestadiumgs-us.z64: OK`, with ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and
`git diff --check` pass. Independent comparison of the complete owner span
at ROM `0x32BCB0..0x32BD90` confirms all 224 original bytes.
