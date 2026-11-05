# Two-digit input constructor

`func_8822CED0` allocates the 24-byte state at `D_88234930` and returns
its registered node pointer. It measures `"9"` and table 33 entry 30,
then positions the label and two digits. The two digit x coordinates
are stored in reverse index order, with one pixel between digit widths.
The state starts with the incoming byte as its value and limit, digit
index 1 selected, a zero timer, and the supplied callback at offset 20.
`func_8822C93C` consumes those fields and invokes the callback on A.
//@src/fragments/31/fragment31_19F570.c

The node has width `label_width + 2 * digit_width + 31`, height 61,
color (220, 220, 180), and the existing input, drawing, setup, and cleanup
callbacks. For an incoming y of at least 261, `func_88003480` applies
mode 6 to the coordinates. `func_88004804` returns the byte index of a
76-byte node in `D_8800ED50`. Its existing word-pointer callback interface
accounts for the callback address casts. Both helper declarations follow
their actual C definitions.
//@src/fragments/29/fragment29_168330.c

Retail caller `func_8820CF8C` supplies `func_8820CCA8` as the callback
and stores the returned node at offset 188 of its record. Unknown owner
and global names remain unchanged. The text measurement interface follows
`func_80049290` and the allocation interface follows `Util_Malloc`.
//@src/fragments/31/fragment31_17F280.c
//@src/47580.c
//@src/3E40.c

The replacement matches 154 instructions / 616 bytes at US ROM
`0x1A0150..0x1A03B8` (exclusive), with a 120-byte frame. The original
624-byte assembly extent includes eight trailing alignment bytes, which
remain identical in the module. The `"9"` literal and natural read-only
section alignment reproduce the original 16 read-only bytes. The original
`D_88234530` relocation and the C section relocation both address
`.rodata + 0`, linked at `0x88234530`.

Validation on master `4e15144993a1f695f3d24aa71cce5089b12f3200`
plus this replacement uses the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_19F570.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check HEAD^
```

The full build reports `build/pokestadiumgs-us.z64: OK` and MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail comparison and whitespace
checks pass. All 3664 text bytes, 16 read-only bytes, 24 register-info
bytes, and 210 semantic text relocations equal the assembly-backed
baseline after resolving the string alias above. Previously matched C
remains byte-identical.
