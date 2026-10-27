# Region notes: fragment44_20F140

## 2026-10-14: func_8AF20F64

This distinct fourteen-argument owner receives a destination pointer, four
words, six unsigned bytes, two words and an aligned source pointer.
The full original func_8AF20FF8 caller was audited. It zeroes the actual
1284-byte buffer at stack offset 84 and passes that pointer in outgoing slot
52. The buffer ends at offset 1368, exactly within the caller's 1368-byte
frame. No return value is consumed.

The accepted unk_func_8AF20F64 contains 321 u32 elements. The aggregate
assignment copies to destination offset 40 and emits all 37 retail
instructions, including the three-word streaming loop and no stack frame.
The header retains all field widths and offsets. Store arg11 at offset 0
before sentinel -1 at offset 20 in source order, following the independently
verified sibling recipe. The first source spelling passes. Unknown tokens
retain address/offset/argument names, and new numeric literals are decimal.
No semantic names or fakes were introduced.

History audit at fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed found
no exact owner attempts or owner-specific regional note and therefore no
historical raw score. The existing 20F140 history concerns func_8AF221C4:
ten, seven and five exhausted probes reached normalized/raw .84/.38,
.74/.34 and .66/.34 with global-address register drift. That owner remains
unchanged and was not retried. All open PR scopes were inspected before this
trial; this owner has a separate call and complete return boundary.

Independent US ROM validation on master e587efc2aca4b35aa7dfdaa72497b54c53c509db
passed with default host syntax checks and COMPARE=1, followed by explicit
md5sum -c baseroms/us/checksum.md5 and retail MD5
1561c75d11cedf356a8ddb1a4a5f9d5d. Only 6 freshly open matching siblings
were excluded; all merged process sources, both #885 files, and the newly
merged foreign resource-loading changes were preserved. The combined
193-owner workspace also passed. Require an actual successful Public PR ROM
Gate checksum build for the current head and merge result before integration;
skipped draft checks are not a pass.



## func_8AF21C58: selected-record flag update

The 188-byte owner (47 instructions, no frame) reads the signed halfword at
byte 64 of the 68-byte record selected by `D_8AF3A082` from `D_8AF3A198`.
Value 1 sets mask 2 in the offset-2 halfword reached by `D_8AF3A0B0` and
clears it through `D_8AF3A0B4`. Value 2 clears the first and sets the second;
all other values clear both. Other bits are preserved. The broader meaning
of the record field remains unknown.

`func_8AF220E8` selects the existing descriptor table among `D_8AF279F0`,
`D_8AF27BCC` and `D_8AF27D20`. Original `func_8AF233B4` obtains the two
flag-bearing pointers through `func_8AC06D8C` with tags `0x6E6D5354` and
`0x6E6D5256` and stores them in those globals. Original `func_8AF22608`
also clears mask 2 in both offset-2 halfwords. Original callers
`func_8AF21D14` and `func_8AF23B64` supply no arguments and ignore the
result. The new declarations are views of existing pointer storage only.
//@src/fragments/44/fragment44_20F140.c
//@src/fragments/43/fragment43_1E5A10.c

The record view preserves the observed 68-byte stride and signed halfword
at 64, with all other bytes opaque. A direct byte-address spelling retains
188 bytes but changes 34 words. The typed record view reduces the remaining
differences to twelve register assignments. Index-plus-record-base pointer
addition reproduces all original registers and instructions. This is ordinary
commutative pointer arithmetic; no artificial locals, padding, instruction
rewrites, extra storage or layout changes are introduced.

Fresh validation uses master `c9cc4ce18015174cfdf1c6c144b158d9832ce79e`
plus this replacement. Master advanced with separate fragment 47 work during
investigation; the updated unchanged baseline passed its own full build and
retail comparison before this source was reapplied. All failed candidates in
other files were restored and forced through the normal Makefile.

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/44/fragment44_20F140.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Default host syntax checks, forced source compilation and the complete US
link pass with `build/pokestadiumgs-us.z64: OK`. The full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail and whitespace checks pass.
Independent original-word and raw retail comparisons verify all 188 bytes
at `0x20FEC8..0x20FF84`. Existing C and both assembly callers remain unchanged.
