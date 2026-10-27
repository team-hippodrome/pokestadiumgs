# fragment31_1A4160 matching notes

## func_88230F5C

The 152-byte, no-argument callback first calls `func_88230E38`, then emits
one SDK `gDPFillRectangle` command through `D_800D0510`. The record pointed
to by `D_882349C0` supplies signed x/y halfwords at offsets 2 and 4 and an
unsigned width halfword at offset 6. The rectangle runs from `(x, y)` to
`(x + width, y + 20)`. The macro preserves the original two command words,
including the record-pointer reload between their stores.

Original `func_882310A0` allocates this eight-byte record, initializes its
two leading bytes from the selected parent records, obtains x and width
through `func_88216D98` and `func_88216E28`, and obtains y from
`D_88006890`. It registers this owner with `func_88005B60`, whose C signature
accepts no-argument callbacks. The new unknown record type leaves the leading
two bytes opaque and allocates no storage.
//@src/fragments/29/fragment29_16BBA0.c

The existing helper `func_88230E38` selects the render display list and
primitive color using `func_88230D80` and `D_8800EF58`. Its no-argument void
interface is preserved. The broader record role remains unresolved, so the
address-based function and global names remain unchanged.
//@src/fragments/31/fragment31_1A3960.c

The SDK macro reproduces all 38 instruction words and the 24-byte frame.
Fresh validation on master `01a86e873e3acc639a69c300b289a59cc6df34a7` plus this
patch uses the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_1A4160.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Full US linking produces `build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent comparison covers all owner bytes at ROM
`0x1A41DC..0x1A4274`. Previously matched C and layout remain unchanged;
no new qualifiers, padding, forced registers, FAKE constructs, or instruction
rewriting are introduced.

## 2026-10-27 — `func_882310A0` state setup accepted

`func_882310A0` is now C: **52 words / 208 bytes**, frame 0x18. It registers
this file's `func_88230F5C`/`func_88230FF4`/`func_88230EE0` with
`func_88005B60(1, ...)` and allocates the 8-byte `unk_D_882349C0` state.
It fills the two leading bytes from `D_882345F4` (byte 8 of `**D_882345F4`,
byte 4 of `*D_882345F4`), sets `x = func_88216D98(0, 4)`, `y = D_88006890`
and `width = func_88216E28(0, 4)`, and stores the pointer in `D_8800EF54`.
The straightforward typed spelling matches; the draw callbacks already use
the same field names.
