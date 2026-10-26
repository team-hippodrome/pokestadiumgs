# fragment43_1EC950 matching notes

## func_8AC07AF4

This four-argument owner scans the three existing 408-byte records at
`D_8AC099D0` for a zero state halfword. It initializes the first free entry
with state 1, clears halfword 2, narrows the two incoming words into
halfwords 4 and 6, copies the two incoming three-byte records into offsets
12 and 15, and sets halfword 8 to 255. It calls existing
`func_8AC06F60(entry)` and returns 1. If all three entries are occupied, it
returns 0 without changing them.

Compiled `func_8AC07A8C` clears all 1224 bytes, initializes three records
with the same stride, and stores the existing resource handle at offset 20.
Its body remains unchanged. The expanded type exposes only fields within
its previously opaque prefix; the record size, resource offset and tail
remain the same, with no allocated storage added.

Original `func_8AC06F60` receives one pointer, reads the signed coordinates
at offsets 4 and 6, and initializes the float records beginning at offset
24. Original `func_8AC075A8` packs the three bytes at offset 12 into an RDP
primitive-color command, using halfword 8's low byte as alpha. It packs the
three bytes at offset 15 into an environment-color command with alpha 255.
These consumers support the two three-byte aggregate views. Other fields
retain their address-based names.
//@src/fragments/43/fragment43_1EC950.c

Original callers `func_8AB07A34`, `func_8AF22608` and `func_8AF23B64` pass
coordinate words and two pointers, then test the returned word before
playing a sound. The owner preserves the original word argument home and
narrowing at the stores. The caller and helper bodies remain unchanged.
//@src/fragments/45/fragment45_22AB80.c
//@src/fragments/44/fragment44_20F140.c

The first scalar byte-copy recipe emits 172 bytes with 12 register-operand
differences. Copying the evidenced triples as aggregates recovers all 43
original instruction words, including the 32-byte frame and loop exits.
No new fakes, qualifiers, instruction rewriting, layout or CI changes are
required.

Fresh validation uses master `cfa29ddb25bdfa4e2817ab991fea133c9b7469a1`
plus this patch. The updated unchanged baseline passed its own complete US
build and retail comparison after normal extraction. Final validation forces
the changed source through the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/43/fragment43_1EC950.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons cover
all 172 bytes at ROM `0x1ED4E4..0x1ED590`.
