# fragment51_27A740 matching notes

## func_86304ACC

This five-pointer owner subtracts the supplied two-float position from the
object's float fields at byte offsets 72 and 76, writing the difference to
the fourth argument. It writes the Euclidean distance through the fifth
argument. Distances strictly below 21 return 1 and replace that scalar with
`21 - distance`. Other distances return 0 and retain the computed distance.

For zero distance, the owner copies the supplied fallback pair into the
difference output. For a nonzero distance below 21, it calls existing
`func_87D0059C` on the two output components. That compiled helper divides
both components by their length and returns the original length; this owner
consumes only its writes. Preserve the separate output reloads and the
fallback aggregate copy.
//@src/fragments/51/fragment51_27A740.c
//@src/fragments/65/fragment65_code.c

Original `func_86305FD8` supplies an object pointer, an eight-byte table entry,
a fallback pair within a 12-byte record, a two-float stack output, and a
separate stack-float address. It tests the word result before passing those
outputs to the subsequent correction helpers. The neighboring regional notes
also establish the object's float positions at 72 and 76. The new two-float
structure describes those pairs without allocating global storage or changing
the caller or helper interfaces. Existing address-based names remain.
//@src/fragments/51/fragment51_27B9E0.c
//@docs/regions/fragments/51/fragment51_27B9E0.md

The first candidate matches all 51 instruction words (204 bytes) and the
original 24-byte frame. The normal compiler lowers the eight-byte fallback
assignment to the original word loads and stores. Existing C remains unchanged;
no new fakes, qualifiers, padding, instruction rewrites or layout changes are
required.

Fresh validation uses master `1beefdc881ce0aa63000f0d0be2c5c9443c6ad58`
plus this patch. The unchanged baseline passes its own complete US build and
retail comparison. Final validation forces recompilation through the default
syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/51/fragment51_27A740.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 204 bytes at ROM `0x27A8EC..0x27A9B8`.
