# fragment12_E7C00

## 2026-10-28 — `func_81403244` matched (stack a new row); rows typed

New file-level types: `Fragment12Row` (0x210: `f32 values[0x80]`,
`unk_200`, `unk_204`, `s16 unk_208` (negative = free), `unk_20A`,
`unk_20B`, `unk_20C`; the fields `func_81402930` initializes) and
`Fragment12Rows` (`rows[6]`, `f32 unk_CAC` @0xCAC, `s8 unk_CB0` @0xCB0).
`func_81403244(rows, arg1, arg2)` takes the highest `values[unk_CB0]` across
the six rows, seeded with `unk_CAC + 180.0f`. It then initializes the first
free row at `max + 22.0f + 1.0f` via `func_81402930(row, y, arg1, arg2)`.
Typed indexing gives retail's base-first `addu`; raw byte offsets give
index-first. The caller `func_81403918` now declares and forwards `arg1`/
`arg2`; it previously took one argument and relied on `a1`/`a2` passthrough
(same bytes).

## layout-prerequisite: jtbl owners in the shared rodata blob (2026-10-28)

`func_8140438C` (`jtbl_81407ADC`) and its jump-table siblings `func_81404040`,
`func_814040D8`, `func_81404470`, `func_8140463C`, `func_814046C4` and the
head of `jtbl_81407B2C` all live in the anonymous `[0xECC60, rodata]` blob.
That blob is entirely this file's rodata. In emission order:

- data: `D_81407950/54` (asm `func_81403758`); the C-referenced `const s16`
  tables `D_81407968`, `D_81407A08`, `D_81407A1C`, `D_81407A2C`; then asm data
  for `func_8140487C`, `func_814057CC`, `func_81405CC4`
- floats: `D_81407A98` (`func_81402A64`), `D_81407A9C` (`func_81403400`)
- jump tables in function order from `jtbl_81407AA0` on

Moving the subsegment start from 0xECE50 to 0xECC60 needs the four C tables
defined in C at the right point in that order. Next action: define them, re-split,
gate with every owner still in assembly, then write the switches. All six
dispatchers are short `switch` + call shapes (e.g. `func_8140438C`: 5 cases on
the u8 at `+0xC`, each `x = func(arg0)`, then a guarded `func_81600A34` call
with four s16s from `func_81403E7C`).

## 2026-10-29 — whole `.rodata` owned from 0xECC60; `func_81404BEC`, `func_814046C4` matched

The 0xECC60 rodata blob belonged entirely to this object. Its `.rodata`
subsegment now starts there (it used to start at 0xECE50, behind a
`const u32 D_81407B40[3]` jump-table-tail hack, which is now gone).

- The C-only tables `D_81407950` (`s32[6]`), `D_81407968`, `D_81407A08`,
  `D_81407A1C`, `D_81407A2C`, `D_81407A3C` and `D_81407A5C` are now `const`
  definitions. They sit together near the top of the file, in retail
  order: IDO did not emit them in file-position order when they were
  spread out.
- `D_81407954` is `D_81407950 + 4` in `aliases.ld`.

`func_81404BEC` and `func_814046C4` are now C switches (case 0 falls into
case 6, and cases 1/2 respectively).

They had to move to C in the same change. Their 14-instruction `.s` files
carry 8- and 5-word jump tables, which trips asm-processor's "late rodata
to text ratio" limit as soon as this file owns its rodata. That also means
the runner can't gate them: the pragma-form baseline no longer compiles,
and a `.late_rodata_alignment` workaround changes the layout. They were
verified with full `make COMPARE=1 RUN_CC_CHECK=1` (`z64: OK`) and
committed with `DECOMP_PROVENANCE_SKIP=1`.

Tooling gap: the runner needs a way to gate owners whose GLOBAL_ASM form
is uncompilable under the target layout.

Same day: `func_81404040`, `func_8140463C`, `func_8140438C` and
`func_81404470` matched through the runner.

- `func_8140463C`: the equal-index branch goes in `else`, after the switch.
- `func_81404470`: write the divisor as an integer, `x / 16`. With
  `/ 16.0f`, IDO turns the division into `* 0.0625f` (`mul.s`).

`func_814040D8` (input handler, **requeue**, `scratch/c/0d8_best.c`):

- Exact except one compiler spill slot. Retail spills the button mask
  copied to `$v0` at `0x18(sp)`; ours uses `0x1C`.
- Use a ternary for the 0xA1/0xA2 sound; an if/else is much worse.
- Already tried: declaration order (`buttons` must be declared first,
  since its home is 0x2E), an `sfx` local, a `pad`-in-condition form,
  `s32 buttons` (frame shrinks).
- The permuter ignores stack offsets and scores the base 0.

`func_81403304` (per-row nearest-candidate pick; **requeue**,
`scratch/c/304_best.c`, normalized 1.0, raw 0.89):

- Exact except that `s2`/`s3` are swapped between the `arg0` copy and the
  `0..0xC60` row offset.
- A 240 s permuter run only won with a fake `if (arg0) {}` that extends
  `arg0`'s lifetime. Not used.
- Next: find a real later use of `arg0` (the original may have had one),
  or a loop form that keeps `arg0` live.

## 2026-11-02: four row, layout and selection functions accepted

The native solo batch reconstructs these owners on the tree published in
PR #2154 (`2c9fad2e`, identical to its merge `fc603d87`):

- `Fragment12_RankActiveRows` (`func_81402A64`, 157 words / 628 bytes,
  ROM 0xE7D74) repeatedly selects the lowest sampled position among six
  unused active rows, then terminates the seven-entry output with NULL.
  Existing `Fragment12Row` fields give the actual 528-byte stride and
  fixed signed activity field at 0x208. Ordinary nested loops reproduce
  retail's compiler unrolling; no hand-unrolled body is needed.
- `Fragment12_GetInterpolatedPanelY` (`func_81403758`, 52 / 208,
  ROM 0xE8A68) selects one three-word row by orientation and interpolates
  its first two words for phases 1 and 3. The third word is preserved;
  its meaning is unresolved here. `D_81407950` is `s32[2][3]` and its
  existing +4 alias `D_81407954` is viewed with the same three-word
  stride. `func_81403828` now explicitly passes its state pointer and
  uses the helper's actual 32-bit result, preserving its generated code.
- `Fragment12_GetInterpolatedPanelRect` (`func_8140487C`, 84 / 336,
  ROM 0xE9B8C) produces X/Y and the fixed 261-by-193 extent through the
  callback at `D_8160BD08`. The initial callback is the float-returning
  `func_8160006C` in `src/fragments/11/fragment11_D7BC0.c`. A nonzero
  remap argument maps modes 0,1,2,3 to 1,0,2,2; otherwise the mode is
  unchanged. The existing coordinate data is typed as `[2][4][2]` and
  `[4][2]`, without changing its bytes.
- `Fragment12_HandleSelectionInput` (`func_81404E68`, 161 / 644,
  ROM 0xEA178) handles controller-selected entries or timed automatic
  entries, reports selection/state changes and emits the existing sounds.
  Human-path count/button indices and automatic-path destination/selected
  indices have separate scopes. Every local is consumed. These scopes
  reproduce the 72-byte frame; handling unavailable entries before the
  available-entry assignment restores the remaining branch order.

The two interpolators need `/ 16`, not `/ 16.0f`, to retain retail's
`div.s`. Explicit integer-to-float conversions and writing delta times
factor before the start term restore the observed floating-register
allocation. The typed table rows/pairs supply the address-scaling shape.
Earlier rectangle probes also changed the remap's false/default behavior;
that candidate behavior is inconsistent with the original assembly.

Canonical accepts are `fragment12-row-sort8` candidate 4,
`fragment12-layout-position-float-webs8` candidate 2,
`fragment12-rect-coordinate-pairs8` candidate 6 and
`fragment12-selection-entry-guard8` candidate 0. Every acceptance has normal
host syntax and a full retail US ROM comparison. The row sort uses a
relocation-masked sequential gate; the other three are object/link-shape
verified before the ROM gate. Probe statistics remain enabled.

Post-acceptance naming preserves all allocated module bytes and function
extents. Remaining assembly callers still use the original names, so their
call relocations resolve through the explicit compatibility aliases to the
same defined functions and offsets. This alias resolution is included in
the normal/+20-leading-blank semantic-relocation controls; it is not an
instruction rewrite. Fresh normal native extraction and the host-checked
ROM build pass after integration with master `609431a2`. All 454 final
instruction words and 72 bytes of the retyped tables equal the original ROM.
No padding, unused local, forced register, fabricated interface or private
helper is included in the batch.

## 2026-11-02: row transfers and selection panels accepted

`Fragment12_AssignActiveRowsToSlots` (`func_81403304`, 63 instruction
words / 252 bytes, frame 56, ROM 0xE8614) resolves the documented register
tie. It transfers each active row's current position and image index to a
slot and resets the row. The comparison threshold is an integer: each
improved float slot value is truncated before the next comparison.
Canonical `fragment12-nearest-slot-formal8` candidate 1 uses the typed state
as the formal parameter and initializes the selected slot before the
threshold. It passes object/link-shape verification, normal host syntax
and the full retail US ROM gate without a fake lifetime extension.

The measured `Fragment12Slot` has floats at 0/4 and a signed halfword at 8;
natural alignment gives its 12-byte size. Six slots replace the opaque
range at state+0xC60, followed by the existing word at 0xCA8. Consolidating
this view into `Fragment12Rows` preserves every allocated module byte,
function extent and semantic relocation in normal/+20-leading-blank
controls. The callee's actual contract is pointer-taking and void;
`func_81403938` now uses that prototype and passes an explicit pointer.

`Fragment12_DrawSelectionPanels` (`func_81406700`, 204 words / 816 bytes,
frame 80, ROM 0xEBA10) draws panel frames/content in the current animation
and layer order. Canonical `fragment12-render-payloads8` candidate 0 is
object/link-shape verified and accepted through normal host syntax and a
full retail-ROM gate. The existing 64-byte header precedes six 3200-byte
asset buffers and six 88-byte selection entries at 0x4B40. Typed payload
array indexing restores retail's base-first address additions. Reading the
selection field directly lets the compiler share the load without reserving
extra scalar homes. The accepted function uses four real rectangle arrays.
Earlier candidates used a 96-byte record stride or placed the final drawing
phase outside its actual enclosing branch; both disagree with assembly.

Post-acceptance naming, declaration cleanup, consolidation of the slot
view, and the descriptive `Fragment12SelectionEntry` type name preserve
the complete module in normal/+20 controls. Remaining assembly references
resolve through compatibility aliases. A fresh normal native extraction/build on integrated revision
`c52efdc3328ed6f0fecbb7538a1366eb3f6726cf` passes the complete retail-ROM
comparison (MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`). All 267 original
instruction words, function extents and linked addresses match. Decimal
screen dimensions also pass both module controls. Coverage is unchanged.
Private bodies, diagnostics and proofs are under `fragment12-nearest-slot*`,
`fragment12-row-slots-consolidation`, `fragment12-render-*` and
`fragment12-row-transfer-panels-*`.

### 2026-11-02: panel update/controller lookup — requeue

`func_81405514` remains assembly (174 words / 696 bytes, frame 88).
The minimal verified-context draft reproduces its eight-way switch in
source order 0,6,1,2,3,4,5,7. Direct typed controller-field forms in
`fragment12-update-panels8-v2` and `fragment12-update-controller-state8`
produce 692-byte bodies, normalized 0.9943, but fold the global controller
address into the halfword load; retail materializes the full record address.
The resulting temporary-register sequence also differs.

`fragment12-update-optional-controller8` candidate 3 preserves the remaining
body and its array homes, reaching raw 0.9492 / normalized 0.9718 at 708
bytes: an optional record pointer adds initialization and a null test that
retail lacks. Assigning that optional pointer inside the condition does not
remove the extra instructions. Explicit 32-bit address arithmetic also folds
back to the shorter direct form. None of these bodies is installed.

The real view is `ControllerState[4]` in `include/controller.h`, with
`buttonsPressed` at offset 8. Probe companions correct the old scalar
`D_800CE060` declaration and its two record-address producers, plus the
state-manager callback flag prototypes against `func_81600A34` in
`src/fragments/11/fragment11_D7BC0.c`; these edits are part of the unaccepted
transaction. Next action: combine the shared switch-result temporary with
the typed controller view, or capture the stock UOPT address/color decisions
for the direct and optional-pointer bodies. Do not add an empty lifetime use
or retain unnecessary address casts. Full-module normal/+20 controls pass.

### 2026-11-02: slot sprites and row histories — requeue

`func_81403400` remains assembly (196 words / 784 bytes, frame 184,
ROM 0xE8710). It first draws six slot sprites grouped by four image indices,
using the slot scale divided by 400. It then visits 128 history samples,
draws alternate ages, and suppresses non-current positions less than one
unit from the current position. The history opacity uses the age/128 times
0.2, with the current sample drawn at full opacity.

Eight typed-loop candidates in `fragment12-row-draw8` do not match. The
integer-divisor cells have 800 bytes, frame 176, normalized 0.91 / raw
0.425; float-divisor cells have 804 bytes and normalized 0.9005. Changing
slot-loop spelling or the distance conditional does not improve those
objects. Next action: preserve the consumed next-age and sample-offset
values visible in the original stack homes rather than relying on the
current for-loop reconstruction, then compare complete loop/float shapes.
Use the verified slot layout and actual `func_81401178`/`func_814011B4`
contracts; do not introduce padding or volatile fields. The minimal-context
m2c draft and original assembly are in `fragment12-row-render-preparation`.
