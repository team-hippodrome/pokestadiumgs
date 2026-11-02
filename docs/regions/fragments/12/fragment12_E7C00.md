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

## 2026-11-02: image and label panel renderer accepted

`Fragment12_DrawImageAndLabelPanels` (`func_814063A0`, 216 words / 864
bytes, ROM 0xEB6B0) replaces its assembly owner through the canonical
native runner and a host-syntax/full-retail-ROM gate on `5d468de0`.
It draws the square image panel before the label for modes below two,
and after the label for the remaining modes. The existing interpolators
supply the rectangles; +0x4D50 holds the copied label and +0x4D5C the
integer texture handle supplied by `func_81404A08`. A compatibility alias
preserves the old address-keyed name for remaining assembly callers.

The previous scheduling requeue is resolved. Explicit inline `(u32)`
casts on the four display-list addresses retain the optimizer's shared
address-word expressions. Unlike named address scalars, these casts add
no frontend local homes. This reproduces the argument-copy placement,
address setup, spill offsets and 104-byte frame using ordinary SDK
`gSPDisplayList` calls. There are no cached-pointer arrays, manual command
writes, added helpers, unused locals, artificial padding or output rewrite.
`u32` is the SDK's unsigned-long type; the DMA macro's final address cast
uses unsigned int. The measured spellings are not interchangeable here.

Normal and +20-leading-blank whole-module allocated-byte, function-extent
and semantic-relocation controls pass after naming, variable cleanup and
removing duplicate declarations. The token-identical formatting probes
also established that statement-line ties can change address scheduling
under this compiler profile; they were diagnostic only and supplied no
accepted source. Nested guards, early returns and pointer-typed variants
did not resolve the residual. Coverage and private tooling are unchanged.

Fresh validation on integrated source revision `a2792d92`, rebased onto
master `368517eb`, passes native `make extract DISASSEMBLE_ALL=1` followed
by `make -j1 COMPARE=1 RUN_CC_CHECK=1`. The complete retail ROM has MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All 216 final instruction words equal
the saved original assembly at ROM 0xEB6B0, and the link map preserves
VRAM 0x814063A0 and the 864-byte function size. Final integrated normal/+20
whole-module controls pass as well. Only this verification note follows
the sealed source revision; coverage and the pending fragment 79 notes
are preserved.


## 2026-11-02: selection-grid renderer — requeue

`func_81405CC4` draws six entries in three columns and two rows. The
image, overlay and text passes use index `row * 3 + column`, column
spacing 84 and row spacing 92. Image storage starts at state +64 with
3200-byte records (40 by 40 RGBA16). Metadata starts at +0x4B40 with an
88-byte stride: species +0, overlay argument +1, DVs +22, level +29 and
name +52. `func_80064474` consumes the species and DVs; its result selects
text-table 13 entries 29/30. These offsets are read from the original
assembly; the helper's argument types also have a C definition in
`src/641E0.c`. No additional interpretation of the gender labels is needed
for this candidate.

Native canonical probes on merged revision `8563b92e` have not accepted
this owner. The retained best candidate uses ordinary nested `for` loops,
inline index/address expressions, separate overlay/text coordinates and
SDK texture macros. It has a 232-byte frame and 438 words / 1752 bytes,
compared with the original 439 words / 1756 bytes. The normalized score
0.9704 is not a one-word residual: the entry pointer, 84, 92 and load-sync
constant have a cyclic global-register difference, and the index spill,
command-head scheduling and later operations still differ. The candidate
uses S5/S6/S7/FP for those four values; retail uses FP/S5/S6/S7.

The retained manifest is `fragment12-summary-coordinate-phases6`,
candidate 4 (both coordinates scoped to their active-entry blocks).
Separate X or Y alone does not recover the correct frame. Earlier derived
index/base expressions improved the 1712-byte candidate to 1732 bytes;
changing all three inner loops together to `for` reached 1752 bytes.
Individual loop changes did not produce that improvement.

Compiler evidence isolates a real effect of the combined loop change:
in the retained UGEN input, the do-loop version loads the E600 load-sync
word with `Uldc` inside the loop; the for-loop versions use `Urldc` with
physical register 30 before the loop. Eight normal/+20-leading-blank
whole-module stock-pass controls passed. Eighteen stock/observer-off/on
optimized-Ucode and UGEN-symbol-input controls passed, as did twelve
stock-equivalent debug-listing controls. These read-only observations did
not alter production compiler decisions. Internal allocator color numbers
must not be treated as physical MIPS registers; the physical-register
claim comes from UGEN. Observer commit rows whose expression pointer is
zero cannot establish semantic root identities.

The complete 63 remaining for/do combinations around the phase-coordinate
candidate all rejected. Three further eight-candidate families also
rejected: explicit per-cell indices/pointers/texture addresses; consumed
image-coordinate scalars before texture setup or drawing; and correctly
typed metadata/image/label accesses. Shared versus cell-scoped indices
stay at 1752 bytes. Named X alone is effectively inert; naming both image
coordinates yields 1772 bytes. Fully typed entry accesses change several
other instructions rather than fixing the allocation cycle. These are
bounded negative results, not evidence that other source shapes cannot
match. The all-for baseline was excluded from the 63-cell batch rather
than replayed as another hypothesis.

The format string remains at module rodata offset 320 and the texture-step
float at 572. Differences in later jump-table relocation addends follow
changed text positions; no missing per-file rodata prerequisite was
established. No candidate in these families reached a retail ROM gate or
was installed. Next: follow the measured entry-index store and four-value
global-allocation cycle from the phase-coordinate source; do not repeat
the completed for/do or scalar-image-coordinate spaces. Preserve the
original complete module as the stock control.

## 2026-11-02: history renderer consumed-temporary controls — requeue

`func_81403400` still retains the ordinary-for candidate from
`fragment12-row-history-steps8`, candidate 4: 196 words / 784 bytes and a
184-byte frame, with three real next-age stack-offset differences
(0x168, 0x184 and 0x298: candidate 100(sp), original 112(sp)). The raw
float relocation difference is separate from those instruction operands.

Preloading the current position, changing direction carriers to float,
explicit next-age variables with consumed slot-position/image temporaries,
and typed/raw row-address variants did not close that residual. A further
eight-candidate batch reused the expired slot-phase index, direction,
loaded flag or Y coordinate as the branch-assigned next age, with both
`< 128` and `!= 128` bounds. All rejected (788–800 bytes); their changes
also disturb the previously exact slot-rendering prefix. Keep the original
three-offset candidate as the control. The next useful experiment must
explain the independent next-age and sample-offset spill order rather
than add unused locals, force registers or pad the frame.

All these probes used the native canonical runner with statistics enabled.
No C, linker-layout or coverage change is installed. The pending fragment
79 notes remain byte-identical to the preserved copy.


### 2026-11-02: history counter with the target stack homes — requeue

A separate source-level witness now reproduces both retail stack homes
without adding a coordinate temporary or padding. Starting with the
branch-assigned named-next-age candidate, moving the existing `history_y`
declaration before `next_age` gives the user counter Mmt -72. The optimized
sample-byte offset remains Mmt -88. Actual ELF inspection confirms 784
bytes and a 184-byte frame, hence counter 112(sp) and sample offset 96(sp),
as in retail. The frontend reserves 76 bytes and UOPT reserves 88. The
coordinate remains assigned before every use; no new local was added.

The witness is `fragment12-row-named-age-coordinate-homes8`, candidate 1:
history Y first in function scope, slot Y scoped to the image loop, and a
`!= 128` loop bound. Four fresh known/candidate normal/+20-leading-blank
controls reproduce each reference's complete module, including allocated
bytes, function extents and semantic relocations. Stock frontend and UGEN
captures independently confirm Mmt -72/-88 in both candidate builds.

This is not a function match or a closer overall instruction candidate.
The normalized 0.9949 score hides changed temporary registers and a
changed increment topology: retail computes the alpha-path age+1 before
the branch and duplicates it on the constant-alpha path; the named
counter places those calculations differently. Keep the ordinary-for
three-offset source as the closest instruction control, and this named
counter as the independently measured stack-layout control.

Seven eight-candidate native canonical families completed on revision
`08150777`: paired position carriers; one-based ages with equivalent
sample/alpha/parity calculations; inline base/sign and shared-factor
combinations on the closest source; coordinate declaration placement;
assignment-expression/order variants; split copy/increment and branch
orientation; and ordinary C `register` hints. None accepted. The hints
are byte-inert for the witness. One-based parity equivalence was checked
for all 128 iterations. Inlining the base float or sharing scale/alpha
retains opcode shape in some candidates but changes both stack homes;
reusing position carriers changes too much of the float data flow.

Next: preserve the demonstrated stack-home mechanism while recovering the
retail common/duplicated increment expression topology. Do not infer that
the layout requires a compiler patch, unused local or artificial frame
size. No candidate reached a ROM gate, and C, linker layout and coverage
remain unchanged; the pending fragment 79 notes are preserved.


### 2026-11-02: history expression-versus-local allocation — requeue

Thirty-two further canonical candidates on `57fbd886` rejected: independent
alpha expressions with reordered next-age assignments; coupled current/next
counters; a record containing both consumed counters; and compact flags
with equivalent row/sample address forms. None installed or ran a ROM gate.
The closest instruction and target-stack-home controls remain separate.

Read-only allocator traces distinguish them more precisely. The ordinary
loop's `age + 1` expression has uncolored ranges with savings -571.4286
(divisor 7) and -1495 (divisor 2). In the named-counter source, the user
local at Mmt -72 is also uncolored, with savings -570/-1500; a separate
`age + 1` expression in the alpha block has savings 30 (divisor 1) and is
assigned internal color 1. UGEN independently shows the latter value in
physical register 2. Internal color 1 must not be called MIPS register 1.
The changed expression lifetime explains why reproducing the user local's
home alone does not recover the closest candidate's instruction stream.

The private observer's old commit-site lookup could lose expressions
because it used a stale table index. Reading the semantic root from the
live range and logging bounded expression children recovers those records.
Twelve stock/observer-off/on optimized-Ucode and symbol-input controls
passed for both candidate sources, normal and +20-leading-blank; secondary
symbol outputs also match. Valid table lookups and range roots agree, and
normal/blank decision signatures agree. Production compilers are unchanged.
Equal memory offsets in different sources do not identify the same local:
the -72 next-age role applies only to the named-counter source.

Next: recover the ordinary loop's expression lifetime while obtaining the
retail spill order through real declarations and address expressions. The
completed named-counter assignment/coupled-counter spaces are not fresh
work. Resume from the retained two controls; do not add dead locals,
artificial padding or output rewrites.


## 2026-11-02: selection-scene initializer — requeue

`func_81406AAC` initializes the two row-state buffers, constructs selection
panels, loads two image buffers and saves the setup pointer. Its original
span is 255 words / 1020 bytes at ROM 0xEBDBC, with a 168-byte frame.
The source baseline is merged revision `8563b92e`; these native experiments
run on documentation revision `57fbd886` without changing tracked C.

The setup has four 528-byte entry sets, four signed IDs at +0x84C, four
12-byte names at +0x850 and two signed-halfword image-ID pairs at +0x880.
The constructor copies six 88-byte `Fragment12SelectionEntry` records
from each entry set. The initializer searches IDs 0 through 3 for the
first missing ID and uses it as a fallback. For setup mode +0x848, it
constructs up to four panels; an even slot whose following ID is below -1
requests a six-entry limit. Otherwise it constructs panels 0 and 3 and
requests a three- or six-entry limit from the rules word high bit at +0x40.
The rule halfword at +0x38 becomes the constructor's timer argument.

Scene strides are 3272 bytes for the two row-state records, 19816 bytes
for each of four panels and 8200 bytes for each of two image buffers.
The scene stores its setup at +0x14F30, has image buffers at +0x14F38,
active flags at +0x18F48, finished at +0x18F58 and activated at +0x18F5C.
The loader's inspected signature is `u8 *func_8004E0F0(u8 *, s32, s32)`;
the existing panel constructor's argument 11 is an integer image handle.
These contracts are preserved in every valid comparison candidate.

The retained candidate is `fragment12-scene-initializer-texture-layout8`,
candidate 0. It has the exact 1020-byte extent, 168-byte frame and measured
homes: setting Mmt -20, flag +0x890 Mmt -24, draw ID Mmt -36 and image-loop
byte offset Mmt -60. These become 148(sp), 144(sp), 132(sp) and 108(sp).
No local or padding was added to produce those homes: existing declarations
were reordered. Separate search variables avoid carrying search lifetimes
into the panel loop. A separate single-mode entry count restores the main
loop index/predicate registers; initializing the input cursor before the
active cursor restores their saved-register assignments. Record-member
addresses reproduce the base/index operand order. A direct byte-offset
image loop avoids caching the first image's address across the later call.

This remains unaccepted. Direct comparison of complete-module owner bytes
finds 29 differing instruction words, including mode-branch scheduling,
loop-initializer ordering and single-mode saved-register choices. The first
50 words, all 94 words from owner offset 0xEC through 0x264, and the final
18 words are byte-identical to the matching module object. An aligned
similarity metric must not be substituted for that positional word count.

Four fresh known/candidate normal/+20-leading-blank controls reproduce
complete-module allocated bytes, defined function extents and semantic
relocations against each respective reference. Relative to the matching
module, every byte outside this owner is equal, allocated section layout
is equal, all defined function extents are equal and semantic relocations
are equal. Earlier six stock-pass controls establish that moving only the
setting declarations changes their homes but leaves UOPT's 44-byte local
reservation unchanged; positioning the live counter correctly raises that
reservation to the target 60 bytes. Captures identify this owner as procedure
76 in this source snapshot; rediscover the ordinal after source changes.

The canonical ledger contains 135 comparison rejections and seven generator
compile failures. Two stale source-slice failures in the initial wide m2c
variants were superseded by the direct reconstruction. Five member-name
rewrite failures were repaired and the corrected candidates also rejected.
These failures are generator evidence, not owner mismatch evidence. Integer
handle spellings, bounded local widths and typed parameter/rules layouts
are byte-inert on the retained source. For/do search spellings converge;
ordinary structured search and a ternary fallback improve the earlier raw
m2c graph. Fully indexed image loops recover opcode shape but enlarge the
frame to 200 bytes, so the 168-byte byte-offset loop remains the control.

Next: follow the single-mode generated image cursor versus bound allocation
and the mode-branch scheduling in the captured stock passes. Test post-test
update placement and initializer ordering before replaying type or address
families. Preserve the four fixed homes and the typed main-loop addresses.
No candidate reached a ROM gate or was installed. C, linker layout, coverage
and the pending fragment 79 notes remain unchanged.


### 2026-11-02 initializer lifetime follow-up (requeue)

Source base: `b1e9f1806a76fb4080b594c581ad28dfb24307a0`;
owner `func_81406AAC`. Initializing the main loop in index/input/active
order reduces the preceding 29-word positional residual to 27 words.
Incrementing the image byte offset before the ID cursor reduces it to 26.
The latter change came from a calibrated 60-second restricted permuter run
(1027 mutations); its other proposed timer-pointer reread was unnecessary.
Equal aligned similarity scores concealed this one-word improvement, so
compare the actual retained instruction bytes before calling a change inert.

The closest candidate is now `branch-count8`, candidate 6: the main loop
index also carries the single-mode 3/6-entry count. It has 20 differing
instruction words at the same 1020-byte extent and 168-byte frame. It restores
the rules pointer's retail register. The remaining differences are the
mode-branch scheduling, image cursor/bound assignment, and the exchanged
single-mode count and active-pointer registers. This is a comparison
rejection, not an installed function or a full-ROM match.

Fresh known/candidate normal/+20-leading-blank controls pass for both the
26-word and 20-word candidates. Every allocated byte outside the owner,
allocated section layout, defined function extent and decoded semantic
relocation target/addend is unchanged. Read-only optimizer tracing also
passes six stock/observer-off/observer-on controls per candidate, preserving
optimized Ucode, UGEN symbol input and secondary symbol output. Normal and
blank runs reproduce all 48 color/cost events for the 26-word candidate and
47 for the 20-word candidate. Procedure ordinal 76 applies to these captures.
Internal compiler colors must be mapped independently to physical registers.

Grouped integer offsets do not improve the residual; `for` traversal adds
an instruction. Typed image-record traversal chooses a 4-byte ID induction
instead of retail's 8200-byte image induction. A pointer-controlled image
loop reduces the frame to 144 bytes; an explicit image pointer alongside
the byte counter removes eight bytes of code. Search-local reuse reduces
the frame to 160 bytes. Relocating the already-consumed rules-pointer
declaration restores 168 bytes, but the best such candidate has 24 differing
words, including four new search-register differences. These families do
not supersede the 20-word control.

Separating the main predicate from its numeric entry count, with either a
shared or separate numeric local and early/late assignment, preserves size
and frame but leaves 96–120 differing words across eight rejected variants.

Next: compare the image cursor/bound interference and the remaining count
lifetimes in the 20-word control against the measured optimizer ranges.
Use those ranges to select a new source-lifetime hypothesis. Preserve the
four measured scalar homes,
the typed main-loop addresses, the actual pointer-returning image-loader
contract and the constructor's integer image handle. No ROM gate has run
for these rejected candidates; no C or layout is installed.


### 2026-11-02 initializer interference evidence (requeue)

Source base: `5ebbca4daa1d44b859459aeb3cbe1a3f9da92f9b`.
The 20-word `branch-count8` candidate remains the closest complete owner.
A second useful control is `named-bound8`, candidate 1: reuse the main index
as the single-mode byte bound, while reusing the main predicate/count for
the single-mode entry count. Its final 88 instructions, starting at owner
offset 0x29C, are byte-identical. The complete owner still differs in 27
words: the main index and 4-entry bound exchange S1/S2, while the image
cursor and byte bound also exchange S1/S2. The earlier mode-branch scheduling
residual remains. This alternate must be retained despite its larger count.

Four fresh normal/+20 known/candidate controls reproduce this alternate's
1020-byte owner, 168-byte frame, complete surrounding allocated bytes,
section layout, defined extents and decoded relocation targets/addends.
A private read-only observer now also records each selected range's
forbidden-color mask and interfering neighbors. Six stock/off/on output
controls pass independently for the 20-word and tail-matched sources.
The 20-word source reproduces all 47 mask/neighbor-category snapshots after
20 leading blank lines. The production compiler is unchanged.

In the 20-word source, the generated image cursor receives internal color
15 before the 16400-byte bound; their interference makes color 15 unavailable
to that bound, which receives 16. Retained object instructions identify
these source roles as physical S1 and S2. In the tail-matched source, the
image cursor's computed benefit is 20 (divisor 2), ahead of the reused
index/bound local at 130/7 (about 18.571). That local interferes with the
image cursor and receives color 16. These are measured decisions for these
sources, not a general color-to-register table or an impossibility result.

Mode-branch inversion and early-return/goto spellings produce larger
residuals or the existing code. Indexing images while independently walking
the ID records recovers the image-byte induction but raises the frame to
192 bytes. Hoisting the group division converges to each control's existing
code; routing it through the first-index local worsens the residual. Main
post-test/condition-update loops add scheduling differences; a less-than
bound converges to the existing code. Skipping cursor updates after the
last panel removes one instruction and does not match.

Next: test a source-level change to the measured index/image live ranges
or their block costs, preserving the exact suffix control. Do not rerun
these branch, division-hoisting or loop-form families without a distinct
mechanism. No new owner was accepted, installed or ROM-gated.

### 2026-11-02 initializer bounded follow-up (requeue)

Source base: `edc01bfe51346d683fc7b4e8e49be64bf8865322`.
Three further eight-candidate families tested derived one-based/countdown
indices, inactive-panel control flow, and per-iteration image destinations.
The derived-index forms shorten the owner to 1008 or 1012 bytes and do not
match. Inactive-panel continue/goto forms enlarge the residual; a valid-panel
continue converges to the existing controls. Destination-local reuse does not
improve their measured residuals. Keep the 20-word complete-owner control and
the 27-word control with its exact final 88 instructions. Neither is accepted.

### 2026-11-02 selected-team export reconstruction (requeue)

Source base: `edc01bfe51346d683fc7b4e8e49be64bf8865322`;
owner `func_81407310`, called by `fragment12_main` in
`src/fragments/12/fragment12_E5330.c` after the scene returns result 1.
The function exports both sides' selected entries, appends the remaining
nonempty entries, clears unused output records, and saves selection order.
This behavior supports a future `Fragment12_ExportSelectedTeams` name.
The owner remains assembly: no candidate is accepted or installed.

The scene's setup pointer is at +0x14F30. Setup contains output +0x840,
rules +0x844, source +0x88C and mode +0x890. Row-state records have a
3272-byte stride and begin with two panel pointers. Panels contain six
88-byte entries at +0x4B40, selected indices at +0xA, a signed selected
count at +0x12, and a name at +0x4D50. Output sides have a 1248-byte stride,
twelve 88-byte entries at +24, and a name at +0x48C. Source sides have a
476-byte stride; their saved indices start at +0x1D4.

Mode 1 prefills the first panel's indices from that source. Each output
records active panels, controller IDs, the selected-entry count and the
first panel's selected count. The current row ID at row-state +0x210
identifies the boundary saved in output +0xA. Unselected nonempty entries
follow the selected entries; only the first byte of each unused record is
cleared. Mode 0 calls `func_842033EC` before exporting, `func_84203360`
once per side, and `func_800730BC` afterward when source is present.
Inspected implementations in `src/fragments/80/fragment80_41AC50.c`,
`src/73C80.c`, and `src/C180.c` establish the real helper contracts:
the first two return void, `func_800730BC` takes two pointer arguments,
and `HAL_Strcpy` returns an `s8 *`.

The accepted panel constructor `func_81404A08` calls `HAL_Strcpy` without
a preceding declaration. Appending its real pointer-returning declaration
for the export candidate conflicts with that earlier implicit-int call.
A canonical companion edit declares `extern s8 *HAL_Strcpy(s8 *, s8 *);`
inside the constructor before its existing declarations. All 484 constructor
bytes remain identical. The initial eight compile failures concern this
declaration transaction, not the export's instruction comparison.

Typed source and destination entry arrays recover two distinct compiler
88-byte stride roots. Retain `array-index8`, candidate 3: 1160 body bytes
and the retail 136-byte frame, with aligned similarity 0.9281/raw 0.476.
Also retain `prefill-cursor8`, candidate 4: 1160 body bytes, a 144-byte
frame, and aligned similarity 0.9384/raw 0.4247. The retail owner is 1168
bytes including eight alignment bytes. Those metrics describe comparison
rejections and do not establish an instruction-exact body.

Six stock normal/+20-leading-blank complete-module controls pass for the
known module and both candidates. All allocated bytes outside the owner,
section layout, other defined function extents, and decoded semantic
relocations outside the owner remain equal to the matching module. All five
ordered external call targets agree. The final physical alignment bytes
also agree, although the candidate function-symbol extent differs by eight.

Captured UOPT input identifies the export as procedure 84: its Uent/Ucomm
header names `func_81407310`. Procedure 82 is `func_814071C4`; earlier
four-panel activation traces selecting 82 are excluded from export evidence.
Rediscover the ordinal from the captured procedure headers after source
changes. Twelve stock/observer-off/observer-on controls preserve optimized
Ucode and both symbol outputs. Normal and blank runs reproduce 39 color/cost
events for the 136-byte-frame control and 38 for the 144-byte-frame control.
The observer is read-only; the production compiler is unchanged.

A calibrated one-worker 60-second restricted permuter run made 999 mutations
with no compile errors. Its best weighted score, 3622 versus baseline 3827,
is invalid: the proposal leaves the row pointer uninitialized outside mode 0.
Two other proposals move the clearing-loop start ahead of appended entries
and would erase valid output. They were rejected before canonical probing.
The safe proposal chains the prefill panel/cursor pointer assignments.
Canonical `reviewed-chains8`, candidate 3, changes three real instruction
words at +0x90, +0x9C and +0xAC despite unchanged aligned metrics. It remains
a 1160-byte, 136-byte-frame rejection. Equal scores do not prove byte inertia.

The signed-16-bit column-counter component (`counter-capacity8`, candidate 6)
assigns the column and unsigned stride to the retail S3/S4 roles, but emits
extra sign-extension instructions and remains rejected at 1164 body bytes.
Six further stock normal/+20 module controls and twelve read-only optimizer
controls pass for this component and the safe chain. The short counter's
measured benefit is 163.75, ahead of the unsigned stride's approximately
153.846; the original 32-bit counter's benefit is 151.25. On the safe
unsigned-offset chain it falls to 126.25. These measured sources explain
the priority change; narrowing the counter does not solve the function.

Initializing the six-entry bound at the main-loop entry (`capacity-lifetime8`,
candidate 0, built on the safe chain) preserves 1160 body bytes and the
136-byte frame. It restores the six-entry bound/signed-stride S6/S7 pair;
the column/unsigned-stride S4/S3 exchange and early extra address cache
remain. All surrounding allocated bytes, section layout, other extents,
decoded relocations and ordered call targets remain equal. Its aligned
similarity is 0.9247/raw 0.6849, not a match.

Typed row views on the earlier prefill controls, standard `register`
qualifiers, and pointer-advance spellings were checked byte-for-byte and
converge to their respective parents. Fully indexed scene traversal worsens
the owner and frame. Integer-address signedness was diagnostic only, with
automatic gating disabled; all eight variants reject. Moving the saved row
pointer earlier changes scheduling but leaves the extra address cache.
Reusing consumed rules/output cursors keeps the 144-byte frame. Reusing
slot/value/scan/found locals for the final clearing loop does not repair
the column/stride allocation. Eight typed row-parameter/cursor variants on
the capacity controls are byte-identical to their respective parents. The
capacity variant derived from the 144-byte-frame control has a 152-byte
frame; the 136-byte-frame capacity control remains the useful component.
No function in this block reached a ROM gate.

Next: preserve both frame controls and the independently useful capacity
and prefill-chain components. Test a genuine typed access or source lifetime
that removes the duplicate early address cache while preserving the four
retail spill homes. For the column/stride exchange, require a measured change
in the 32-bit counter's range or cost without the short counter's added
instructions. Do not promote narrow-counter or integer-address diagnostics
solely because a register assignment improves.
