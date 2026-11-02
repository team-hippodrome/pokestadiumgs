# Region notes: fragment44_20EBC0

## 2026-10-14: func_8AF209E4

This is a distinct fourteen-argument, void aggregate-copy owner. Its original
`func_8AF20A78` caller was audited: it passes four header words, six unsigned
byte values, two additional words and its actual stack buffer at 0x54 in the
outgoing slot 0x34. No return value is consumed. The 1284-byte input buffer
ends within the caller's 0x558 frame.

The accepted `unk_func_8AF209E4` contains 321 `u32` elements. Four header word
stores, six byte stores, the word at offset 0, sentinel -1 at offset 0x14,
and word at offset 0x1C preserve the retail layout. The aggregate assignment
copies to offset 0x28 and emits the exact three-word streaming loop with no
stack frame. Store `arg11` at offset 0 before the sentinel in source order,
following the positively verified sibling recipe. The first spelling matches
all 37 instructions. All names remain unknown address/offset names; no new
semantic names or fake operations were introduced.

History audit: no exact owner attempt or 20EBC0 region record was present at
fleet main `afee707ab78d3f63f2f9deeadc7551ec0080eeed`; no historical raw score is
available for this owner. All open PR scopes were checked for duplicate work.
The neighboring callback `func_8AF20950` and the deferred `func_8AF20E4C`
pointer-lifetime family were inspected only and remain unchanged.

Independent validation on master `b4ded57db9dbd84a9a209f134f7b72204d97aecb`:
US ROM rebuilt with default host syntax checks and `COMPARE=1`; explicit
`md5sum -c baseroms/us/checksum.md5` passed with retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All fourteen other open process matching PRs
were excluded, preserving merged #880 and current foreign rendering work.
The combined 189-owner workspace also passed. Await the authoritative Public
PR ROM Gate for the current head and actual merge result before integration.


## `func_8AF20A78`: initialize the node payload

This owner matches all 65 instructions (260 bytes), including its 1368-byte
frame. It captures signed node coordinates at offsets 8 and 10, zeroes the
existing 1284-byte packet, copies signed dimensions from offsets 12 and 14,
and fills the original word and halfword defaults. The word at packet offset
44 is 6 and the halfword at offset 60 is 3. The fourteen-argument
`func_8AF209E4` copies the packet into destination offset 40.

`func_8AF20B7C` supplies the node returned by `func_8AC06D8C` through
`D_8AF39940` and the destination `D_8AF279A0`. Its existing pointer and void
interface is preserved; the redundant declaration is removed. The node and
settings locals hold pointers used by the reads, zeroing, field stores and
final call. The existing opaque packet representation is retained.
//@src/fragments/44/fragment44_20EBC0.c

Fresh verification targets master
`fd3bf02709d70d45effb097e5bb5b71433c4440d` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/44/fragment44_20EBC0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled forced compile and full US link report
`build/pokestadiumgs-us.z64: OK`. Both ROMs have MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail byte comparison and whitespace
checks pass. All 1408 module text bytes equal the assembly-backed baseline,
including the existing caller and callee; the module has no rodata section.
The owner occupies ROM `0x20ECE8..0x20EDEC` (end exclusive). No new fake,
padding, data ownership, instruction rewrite, generated layout or CI change
is included.
