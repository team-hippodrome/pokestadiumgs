# fragment11_D7BC0

## func_81600340

Accepted recipe: a single `f32 arg0`, the existing zero/one clamp guards, then `arg0 = (arg0 - 0.5f) * 2.0f` and the left-associated cubic expression `arg0 * arg0 * arg0 * 0.5f + 0.5f`. IDO emits the original subtraction, doubling through `add.s`, three multiplies, and final addition. The comparisons, including their behavior for unordered floating-point input, retain the original instruction sequence. Unknown names and decimal literals are preserved; no fakes or additional arguments are needed.

The original leaf reads `f12` and returns `f0`. Data at `D_8160BD00` registers it as entry 8 at offset 32 alongside the existing `f32(f32)` clamp callbacks. Original table calls in `func_824070E4` and `func_8130881C` pass a single float in `f12` and consume `f0`; these particular calls select the first table entry. No direct named caller for entry 8 was found. The owner's complete 28-instruction body ends before the separate `func_816003B0`, with no stack frame, trailing padding or shared switch tail.

History audit: fleet main `afee707ab78d3f63f2f9deeadc7551ec0080eeed` has no exact owner attempt or `11_D7BC0` regional record, and current master has no regional document at this path. No historical normalized or raw similarity score is available for this owner. Earlier failed `func_81600450` and `func_81600884` investigations were retained and not retried. All open PR scopes were inspected; only documentation draft #922 was open before the trial.

Independent validation against master `c73a3a3c9a8097a4e5ff8b85cc062e5a0b531fee`: the first recipe passed the full US ROM build with default host syntax checks and `COMPARE=1`, followed by `md5sum -c baseroms/us/checksum.md5`. Retail MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`. All 195 prior matched US owners remained present. The Public PR ROM Gate must actually run its checksum build successfully for the current PR head and merge result before merging; a skipped draft check is not validation.

## 2026-10-27 — `func_81600A34` region-list append accepted

`func_81600A34` is now C: **47 words / 188 bytes**, frame 0x28. With a
non-zero id it takes a free node from `func_81600884(ctx)`, writes the
rectangle with `func_816003B0`, stores the id at node+8, calls
`func_816009C0(ctx, node, id, arg2)`, and appends the node to the list whose
head/tail pointers live in `*(ctx + 0x28)`. Links are node+0x14 (next) and
node+0x10 (previous). Callers in other fragments (for example
`func_824027F4`, `Fragment13_UpdateConfirmationDialog`) pass the id as
`void *`.

Source shape: re-read `*(ctx + 0x28)` in every statement (no cached list
pointer: 0.94), and test `head != NULL` first. The target falls through into
the append and branches (`beql`) to the empty-list case; the opposite
polarity scores 0.74. In the empty case write `tail = node; head = tail;`.

## 2026-10-27 — `func_81600E28` region-context constructor accepted

`func_81600E28(pool, arg1, count)` is now C: **57 words / 228 bytes**, frame
0x30. It allocates the 0x30-byte context and `count * 4 + 1` nodes of 0x20
bytes from `pool` (`MainPool_AllocAligned(..., 4)`) and resets every node
with `func_816003C8`. It then initializes both 12-byte lists at +0x10 and
leaves list 1 current (`list_index` +0x4, `list` +0x28), and stores `arg1`
at +0xC. The `list` pointer is the head/tail pair `func_81600A34` appends
to (`unk_func_81600A34_List` is the first eight bytes of
`unk_func_81600E28_List`).

Source shape: inside the list loop, assign `ctx->list = &ctx->lists[i]`
and then clear `ctx->list->tail` (not `ctx->lists[i].tail` or an
assignment expression; those add two words). Finish with the chained
`ctx->list->head = ctx->list->unk_08 = ctx->list->tail;`.

## Free region-node lookup

`func_81600884` has a matching C implementation (26 instructions, 104 bytes).
It reads the signed node count at context offset zero and the array pointer
at offset eight, scans the 32-byte records in order, and returns the first
record whose ID at offset eight is zero after calling `func_816003C8` to
reset it. A nonpositive count or an array with no free record returns NULL.
The reset clears the rectangle, ID, list links, and other existing fields;
it does not reserve the record by assigning a nonzero ID.

`func_81600E28` allocates and initializes this array with `count * 4 + 1`
records. The caller `func_81600A34` writes the returned record's rectangle
and ID before appending it to the current list. These producers and
consumers establish the record stride and ID field. The node view allocates
no storage and leaves the remaining bytes unnamed. Indexed struct accesses
preserve the retail scan cursor and separate returned-record address.
//@src/fragments/11/fragment11_D7BC0.c

Verification targets master `bcca6fe6161cec32b2e2d902cfd49d3f49464c61` plus
this replacement and declaration cleanup:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/11/fragment11_D7BC0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled forced compile and complete US ROM link report
`build/pokestadiumgs-us.z64: OK`. The ROM compares byte-for-byte with retail;
MD5 is `1561c75d11cedf356a8ddb1a4a5f9d5d`. The 32-byte frame and original
owner extent are preserved. No new fake, storage, layout change, compiler
flag, or instruction rewrite is used. Behavior is established by source
and original disassembly inspection.
