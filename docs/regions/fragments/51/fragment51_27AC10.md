# fragment51_27AC10 matching notes

## func_86305B44

This no-argument owner traverses four 396-byte entries beginning at
`D_863075D8 + 320`. For each entry it loads the pointer at offset 32 and
calls existing `func_86305A04` only when that object's word at offset 64 is
nonzero. It passes the address of a local work record containing the loop
index, entry pointer and object pointer at offsets 0, 4 and 8. Preserve the
record reloads after the helper and the index-before-entry increment order.
//@src/fragments/51/fragment51_27AC10.c

The existing assembly helper uses this same record throughout its geometry
and list-processing calls. It reads the entry/object pointers at 4/8,
writes the list pointer at 12 and floats at 16/20, and passes addresses
within the record to `func_86304DF0` and `func_863057A0`. Its float store at
136 establishes the 140-byte record extent. The 128 bytes after the three
named fields are opaque helper working storage, rather than unused stack
padding. Their existing initialization and processing remain in the helper
chain (`func_86305448`, `func_86305694`, `func_86305840`).
//@src/fragments/51/fragment51_27AC10.c

Compiled `func_86302404` calls this owner without arguments during each of
three update iterations and ignores its result. The new declaration uses the
existing root pointer and allocates no global storage. Unknown fields and
function names remain address-based.
//@src/fragments/51/fragment51_275E40.c

The accepted do-while matches all 30 executable instruction words (120 bytes)
and the original 176-byte frame. The first for-loop candidate had only the
two loop-store positions reversed and was rejected. The original assembly
also includes one trailing alignment NOP after the return delay slot; that
four-byte alignment is preserved and excluded from the executable byte count.

Fresh validation uses master `28bd8b2298dc22a4ca5a8c380379ba4ac1ed053c`
plus this patch. Final validation forces the changed translation unit through
the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/51/fragment51_27AC10.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
the executable bytes at `0x27B964..0x27B9DC` and the following four alignment
bytes through `0x27B9E0`. Existing neighboring C, helper bodies, callers,
storage and layout remain unchanged; no new fakes or instruction rewriting.

## func_8630557C

This 280-byte owner (70 instructions, 24-byte frame) subtracts an incoming
two-float position from the object's position at offsets 72/76, storing the
difference in the work record at offsets 128/132 and its length at 116.
Lengths strictly below 21 return 1: a zero-length difference is replaced by
the two incoming fallback components, the stored length becomes
`21 - length`, and `func_87D0059C` normalizes the difference. The word output
is 1 when its dot product with the object's floats at offsets 32/36 is
negative, otherwise 0. Rejected distances return 0 and leave that word
output untouched; the difference and distance fields have still been written.

The existing `func_87D0059C` definition accepts two float pointers and
returns the original length as a float. Its declaration now expresses that
interface before the new call site. The existing `func_863057A0` call uses
float-pointer casts and continues to ignore the result; its machine code
is preserved by the complete ROM comparison.
//@src/fragments/65/fragment65_code.c
//@src/fragments/51/fragment51_27AC10.c

Assembly `func_86305694` supplies the work record, object pointer, one of
the position pairs at work offsets 32/40, two fallback floats and a stack
word output. It tests both the returned word and output flag before its
subsequent correction calls. The existing `func_86305B44` work-record
extent includes all fields written here. Unknown field roles remain
offset-based; no data ownership or layout changes are required.
//@src/fragments/51/fragment51_27AC10.c

The initial arithmetic spelling emits 284 bytes. Preserving the original
sum/product operand order restores the 280-byte instruction sequence, then
resolves the final two floating-point load-register differences. No padding,
artificial locals, instruction rewrites or compiler changes are introduced.

Fresh validation uses master `781e8bdecbb239089213fbc37b3f27f1d496da90`
plus this patch. Normal US extraction and the full unchanged baseline passed
initially. After the unrelated five-owner merge changed a fragment 31
layout, extraction and the updated assembly baseline passed again before
this C was reapplied. Final validation forces the changed source through
the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/51/fragment51_27AC10.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Exact acceptance: `build/pokestadiumgs-us.z64: OK`. Full ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Original-assembly and raw retail comparisons verify all 70
words at `0x27B39C..0x27B4B4`.
