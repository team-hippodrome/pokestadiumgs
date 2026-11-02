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

### 2026-11-02: dispatcher source/lifetime controls — requeue

After PR #2159, `func_81405514` remains assembly. Three eight-candidate
families tested the shared switch-result temporary with the real controller
layout, controller-address assignment before the CPU guard, and a typed
state-field view. The shared-result family reaches 696 bytes but changes the
frame to 96 and the switch joins; the other two families still emit 692 bytes
versus retail's 696. They do not improve the earlier optional-pointer leader.
The rejected bodies and companion declaration transactions remain private.
A companion preflight failure on a prototype-removal transaction was corrected
before compilation and is not a source-hypothesis result.

Unchanged stock IDO 7.1 pass captures compare the direct and optional-pointer
forms against fresh reference objects, each with normal/+20 whole-module
controls. In the direct form, UOPT passes the global address and scaled index
straight into the halfword load (`Ulda`, `Uixa`, `Uilod`); the local controller
pointer has no surviving register value. The optional form emits a pointer
store/load in register 2 but retains the extra initialization and null branch.
Native UOPT debug-6 listings preserve the captured optimized Ucode and symbol
outputs byte-for-byte; the platform's later `wrapper_ecvt` abort limits the
listing, rather than invalidating those already-compared outputs. These are
source/lifetime measurements, not evidence that the retail shape is
unreachable. Private captures are `fragment12-panel-update-stock-passes` and
`fragment12-panel-update-uopt-graphs`.

Next action: investigate the genuine pointer-return helper's inlining and
conditional lifetime, using the direct/optional optimized inputs as controls.
A normal helper call was already measured to emit a call; do not repeat it or
add a null check merely to reserve a pointer register. Preserve the actual
controller and callback contracts, and keep the full ROM gate mandatory.

### 2026-11-02: history renderer loop/lifetime controls — requeue

`func_81403400` remains assembly. Five eight-candidate families tested consumed
next-age/sample-offset carriers, independent variables for the two drawing
phases, a distinct consumed age increment, the typed draft's control-flow
graph, and float-value lifetimes. None passed the object probe. Candidate
replay preflight was resolved before the phase-variable family compiled and
does not count as an attempted source hypothesis.

The original indexed body remains the strongest normalized leader (0.91,
800 bytes, frame 176 versus retail's 784 bytes/frame 184). A byte-offset
carrier can produce frame 184 but still has normalized 0.8636 and different
allocation/loop structure. The draft control-flow forms produce 792–800 bytes
and frame 216; splitting more phase variables grows the frame to 192–208.
Sharing the consumed float calculation variable reaches normalized 0.895 /
raw 0.38, 800 bytes, frame 168. Matching a frame alone does not close the
function. Integer and float divisors remain distinct measured cells.

Fresh stock pass captures of the indexed body and shared-factor candidate 4
pass normal/+20 whole-module controls. Their frontend local reservations
are 60 and 68 bytes; UOPT produces an 80-byte local reservation in both, and
both final functions have frame 176 with the same saved-register set. Their
register assignments and instruction order still differ. Candidate 6, which
also inlines the base-Y conversion, is the separate frame-168 result. These
measurements separate frontend storage counts from the final optimized frame.
The initial diagnostic capture lacked the runner-synthesized display-list
pointer declaration; its corrected capture uses that real declaration and
preserves the tracked source. Captures/decoded rows and frame diagnostics are
in `fragment12-row-history-stock-passes-v2`.

Next action: compare the optimized loop/float webs and actual spill homes of
the frame-184 byte-offset body with this controlled 80-byte-reservation pair.
The source formal, slot/row layouts and drawing helper contracts are verified;
keep them fixed. Do not add unused storage to obtain the 184-byte frame.
Private manifests/results use `fragment12-row-history-carriers8`,
`fragment12-row-phase-webs8-v2`, `fragment12-row-next-value8`,
`fragment12-row-draft-graph8` and `fragment12-row-float-lifetimes8`.

### 2026-11-02: history renderer stack-home residual — requeue

`func_81403400` remains assembly. The strongest canonical candidate is
`fragment12-row-history-steps8` candidate 4: 196 words / 784 bytes, frame 184,
normalized similarity 1.0 and raw object similarity 0.9796. At owner offsets
0x168, 0x184 and 0x298 it stores/loads the next history age at `sp + 100`;
retail uses `sp + 112`. The fourth raw word difference is the float literal's
relocation addend. Link-shape and full-ROM acceptance have not been reached.
No candidate from this box is installed.

The key source mechanism is to read sample values directly from the row
storage. A named float-position local becomes a saved float register across
the texture-selection call and delays the integer Y conversion; direct
sample reads produce retail's integer-Y lifetime and float register sequence.
Use separate scoped slot/history Y locals, inline the current-sample read,
and keep the ordinary `for (age = 0; age < 128; age++)` loop. The byte-offset
history traversal needs its counter initialized before the row pointer, and
its row-pointer step before the counter step. Those changes close the
register cycle and scheduling differences that a single aggregate score
obscures. The row/state-array cells in `fragment12-row-direct-samples8`
retain an unread sample cursor and are diagnostic-only; later candidates
remove it.

Fresh unchanged-stock pass captures in `fragment12-row-stack-only-stock`
reproduce this canonical candidate's complete allocated module in normal/+20
controls. The frontend reserves 72 local bytes; UOPT reserves 88 and assigns
the next-age temporary memory offset -84, giving `184 - 84 = 100`. The sample
offset uses -88 and already lands at retail's `sp + 96`. Moving the source
`age` declaration through eight positions does not move the generated slot.
The remaining problem is optimizer-generated temporary storage, rather than
the scalar's source declaration position.

Two single-worker permuter boxes are calibrated against canonical objects
and an AST-regenerated self-target scoring zero; SDK display-list blocks are
preserved. The 60-second restricted box stays at score 136, and the improved
90-second expression/lifetime box stays at score 36. Their sources and logs
are private under `fragment12-row-indexed-history8-observed-permute.json`
and `fragment12-row-history-steps8-observed-permute.json`. Source variants
cover slot/history scopes, scalar lifetimes, history step order, explicit
next-age variables, graphics cursors, bounded counters, shared phase
variables and natural indexed arrays. Natural array traversal grows the body
to 800 bytes; explicit next-age forms shorten it to 776. Keep the stack-only
leader as the control instead of restarting from those weaker bodies.

Next action: trace creation of UOPT's -84/-88 temporaries and the reservation
between the 72-byte frontend area and those homes, using the captured
frontend and optimized inputs. Then test a source lifetime or induction
change that moves the next-age home while preserving the 184-byte frame. No padding, unused local, fixed register or
object rewrite is an admissible resolution. Any text hit still requires the
canonical link/host/retail-ROM gates and post-cleanup module controls.

### 2026-11-02: compiler/helper controls for the remaining owners

Stock IDO 5.3 and 7.1 comparisons each include normal/+20 controls and six
accepted fragment-12 witnesses. Neither the history body nor the dispatcher
matches under 5.3, and the complete known module differs. Explicit `-g0`
reproduces the production candidate; `-g3` changes the known module and does
not match the candidate. Production compiler/flags remain unchanged. Private
receipts are `fragment12-rows-panels-stock-frontends` and
`fragment12-row-debug-profile`.

Marking the existing `func_814049CC` definition `__inline` fails canonical
asm processing in both normal/+20 controls with `Wrongly computed size for
section .text (diff 2680)`; ordinary controls pass. This is a terminal result
for that inline-qualification transaction, not proof that the dispatcher is
unreachable from C. Separately, appending `return ret` to `func_81404700`
produces 40 bytes instead of 36 and fails complete-module equality. Neither
helper experiment is installed. The dispatcher remains a requeue at its
previous direct/optional-controller diagnostics.

### Native spill observer and source-shape follow-up (2026-11-02)

`func_81403400` remains `requeue`; `row-history-steps8` candidate 4 remains
its strongest source. A native UOPT observer reproduced stock optimized
Ucode and UGEN symbol-table input byte for byte with tracing disabled and
enabled, for both normal and 20-leading-blank source controls. It changes
no compiler decisions. The measured frontend reservation is 72 bytes.
Eight PRE spill assignments use seven unique slots: direction conversion
at -76; first-pass address and current-index load sharing -80; next age
at -84; sample byte offset at -88; then three unused-in-emitted-code
address/load homes at -92, -96 and -100. Only -84 and -88 reach emitted
Ucode; final frame size remains 184. Retail needs the next-age home at
-72 while retaining the sample-offset home at -88. Declaration placement
alone does not explain the required separation.

Fresh canonical native batches retained statistics and passed normal/+20
whole-module controls. Moving the distance filter before Y computation
changes scheduling and allocation. Grouping the four drawing flags/signs
as word-sized struct fields preserves the three-offset residual; byte-sized
fields preserve the instruction sequence but shrink the frame to 176.
Early current-sample address/index locals and explicit next-age locals
also reject. None was installed. The next source hypothesis must account
for PRE spill ordering rather than merely moving scalar declarations.
Private evidence: `scratch/fragment12-row-spill-observation-v2/receipt.json`
and the `row-local-state8`, `row-current-address8`, `row-next-age8` results.

`func_81402D08` preliminary assembly inspection exposes a separate source
reconstruction issue. `$s4` is initialized at owner offset 0x9C, set on a
boundary collision at 0x15C/0x184 and updated by a collision-pair OR at
0x24C. Its only reads feed that OR; it has no output store, branch use or
return transfer. The epilogue restores the caller's `$s4`. The m2c draft
omits this discarded mask. No candidate was submitted for this owner;
reconstructing its useful row/slot physics alone would omit retail words.

### Inset-panel renderer: pointer homes resolved, setup order remains

`func_814063A0` is now a measured `requeue` at 864 bytes and a 104-byte
frame. It draws the square image panel before or after the rectangular
label panel according to the signed mode byte at +9, with manager checks
for channels state+1/state+2. The label comes from the string copied to
+0x4D50 by `func_81404A08`; the image handle is stored at +0x4D5C by that
initializer. Actual contracts are `func_8004D19C(s32,s32,s32,s32,s32)`
(`src/4CC20.c`) and `func_816073A0(void *)` (fragment 11). Pointer-typed
texture prototypes found in other callers are insufficient evidence for
changing this integer-handle contract.

Separate scoped `s16[4]` rectangles and `/ 16` reproduce the rectangle
homes and floating instructions. Writing width/2 before X in the centered
label expression restores the temporary-register order. Plain local
setup/restore pointer scalars rematerialize their addresses, yielding 848
rather than 864 bytes. A two-pointer local array assigned through separate
statements retains the required stores and loads. Braced initialization
adds a constant-data copy and fails section layout; do not adopt it.

The best current source uses separate setup/restore `Gfx *` command locals,
both consumed by ordinary display-list writes. An array ordered restore,
setup, assigned setup first, reproduces retail's pointer homes and address
registers. It introduces no padding, unused fields or machine-code rewrite.
`scratch/fragment12-inset-separate-commands8.json` candidate 1 (also 5)
retains all 216 instructions. Its real residual is six instruction words
in the setup-call prefix (owner offsets 0x24C, 0x250, 0x254, 0x25C, 0x260,
0x264): the argument copy occurs after pointer initialization instead of
in the preceding branch delay slot. The 0x1C8 raw float-relocation spelling
resolves to the same `.rodata + 576` target on both sides. The reported scalar raw score is not a count
of differing object words.

Before that final source refinement, stock CFE/UOPT/UGEN/AS1 inputs were
captured for known assembly, a shared command cursor and a first-command
SDK macro, each normal/+20. All six complete-module identity controls
passed. Both partial forms reserve 52 frontend bytes and 56 optimized
bytes. The cursor's pointer array occupies Mmt -52/-48; the SDK form's
occupies -48/-44. The separate-command source composes those independently
observed pointer-home and register-web mechanisms. Its stock pass boundaries also reproduce the canonical object
under four known/candidate normal/+20 complete-module controls, with the
same 52/56-byte frontend/optimized reservations. Semantic relocations
outside the reordered prefix are equal; inside it, the relocation target
multiset is equal. Next: establish the owning scheduler/IR ordering before
another source family. No candidate was installed or ROM gate run for these
rejections; source, linker layout and coverage remain unchanged.
