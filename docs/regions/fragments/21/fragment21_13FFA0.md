# fragment21_13FFA0 matching notes

## func_825038A4

This one-pointer, void owner reads a data pointer from context offset 12.
The data's first unsigned byte minus 1 supplies the signed loop bound.
For each index below that bound, it reads the bytes at data offsets
`4 + index * 152` and `5 + index * 152`, subtracts 1 from each, and converts
both to signed halfwords. It calls existing `func_82506BEC` with the index,
bound, two converted values, and the pointer from context offset
`28 + index * 4`. A nonpositive bound produces no calls. The context's data
pointer and per-index pointer are read again for each iteration.

Compiled `func_825028E8` and `func_82502924` consume the same data's first
byte and 152-byte stride to read the final pair of metadata bytes minus 1.
Original caller `func_82503F28` passes a 60-byte record selected from
`D_82508D10` and consumes no result. These accesses establish the input,
stride, and unknown data ownership without introducing semantic names.
//@src/fragments/21/fragment21_13FFA0.c

Original `func_82506BEC` receives the first two arguments as words, reads
the next two as signed halfwords, and stores the fifth pointer-bearing
word in its new record at offset 52. It obtains a free record through
`Fragment21_FindFreeRecord`, clears 100 bytes, and writes kind 2 along with
the supplied index and values. This owner preserves the existing helper
body and supplies all five actual arguments.
//@src/fragments/21/fragment21_144790.c

The first candidate reproduces all 44 instruction words (176 bytes), including
the 56-byte frame and the original loop's two independent address strides.
The current region catalog and private ledger contained no prior attempt for
this owner. Existing C remains unchanged. No new storage, fakes, padding,
qualifiers, instruction rewriting, layout, or CI changes are required.

Fresh validation uses master `8c0fa9c2ba73804bf32948c38d8a62aee98c69e0`
plus this patch. The updated unchanged baseline passed its own complete
US check and retail comparison. An unsuccessful lookup trial in `src/674D0.c`
was restored and forced through compilation before acceptance. Final validation
uses the default syntax-enabled Makefile and forces the changed source:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/21/fragment21_13FFA0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 176 bytes at ROM `0x143824..0x1438D4`.
