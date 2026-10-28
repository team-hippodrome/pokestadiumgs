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

## func_86304B98

This six-pointer owner copies the object's float fields at offsets 72 and
76 into a two-float local and calls `func_87D00670`. That helper solves the
two-vector intersection equations when their determinant is nonzero,
writing two scalar parameters. This owner negates the first scalar local
and requires it to lie strictly between -21 and 21. The parameter written
through arg4 must lie strictly between 0 and 1. On success, arg5 receives
`21 - abs(local)` through the original two branches and the owner returns 1;
otherwise it returns 0 and leaves arg5 untouched. The helper may still have
written arg4 on a rejected intersection.

The new declaration preserves the helper's six pointer arguments and word
result. The existing two-float structure describes its pair inputs; no
global storage changes. `func_86304CA8` supplies all six pointers and tests
the result after its preceding intersection attempts. The neighboring
matched owner also establishes the object's position fields at 72 and 76.
//@src/fragments/65/fragment65_code.c
//@src/fragments/51/fragment51_27A740.c

The first recipe matches 66 of 68 instructions and the original 56-byte
frame. Setting the success result after the output write reproduces the
remaining load/assignment schedule. All 68 words match without artificial
locals, padding, instruction rewrites or layout changes. Unknown names are
preserved.

Fresh validation uses master `1cb9964865b7dc9138f80ad0b3f9935a6b74f130`
plus this patch. The initial unchanged baseline passed; after unrelated
fragment 64 and audio channel merges, each updated unchanged baseline passed
before the accepted source was reapplied. Final validation forces compilation through
the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/51/fragment51_27A740.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Exact acceptance: `build/pokestadiumgs-us.z64: OK`. Full ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Original-assembly and raw retail comparisons verify all 68
words at `0x27A9B8..0x27AAC8`.
