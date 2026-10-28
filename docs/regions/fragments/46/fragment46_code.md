# Region notes -- src/fragments/46/fragment46_code.c

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

func_8AE032C8: plateau at 0.9565 (raw 0.9565), mismatch instruction_drift; tried families: call_sequence; tie-pool no

## 2026-09-15

func_8AE01738: plateau at 0.0 (raw None), mismatch unknown; tried families: (none); tie-pool no

## 2026-09-27

func_8AE04FA8: matched (call_sequence:coordinate_temporaries:s16_load_temps), 3 iterations, agent unbiased

## 2026-09-27

func_8AE017A4: plateau at 0.9067 (raw 0.6667), mismatch instruction_drift; tried families: call_sequence; tie-pool yes; 2 iteration(s) with a suspicious identical batch-wide failure

## 2026-09-27

func_8AE00AF4: plateau at 0.0 (raw None), mismatch unknown; tried families: call_sequence; tie-pool no; 1 iteration(s) with a suspicious identical batch-wide failure

## 2026-09-27

TYPE CONFLICT: D_8AE08508 is extern u8 D_8AE08508[], not extern Fragment46LookupEntry D_8AE08508[]

## 2026-09-27

func_8AE01B88: matched (call_sequence:parameter_for_control:reset_in_increment_clause), 4 iterations, agent unbiased

## 2026-09-27

func_8AE02568: time cap at 0.8295 (raw 0.5114) after 2418s, mismatch instruction_drift; tried families: access_qualification, call_sequence, conversion_spelling, global_dataflow, global_storage, global_value_flow, local_representation; tie-pool no

## 2026-10-04

func_8AE018C4: time cap at 0.0 (raw None) after 2401s, mismatch unknown; tried families: (none); tie-pool no

## 2026-10-04

func_8AE01DC0: matched (call_sequence:loop:matched_sibling_shape), 6 iterations, agent codex

## 2026-10-04

func_8AE026C8: time cap at 0.8814 (raw 0.4407) after 2414s, mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool no

## 2026-10-08

func_8AE035BC: matched (call_sequence:matched:signed_buffer_and_reversed_equality), 1 iterations, agent codex

## 2026-10-11

func_8AE00C1C: plateau at 0.0 (raw None), mismatch unknown; tried families: call_sequence; tie-pool yes

## 2026-10-11

func_8AE05B24: matched (call_sequence:stack_record:renamed_snapshot), 1 iterations, agent codex

## 2026-10-11

func_8AE02398: time cap at 0.963 (raw 0.8704) after 2449s, mismatch operand_or_scheduling_drift; tried families: access_qualification, access_representation, argument_representation, arithmetic_form, arithmetic_lifetime, arithmetic_temporaries, arithmetic_temporary, assignment_expression, assignment_nesting, call_sequence, case_layout, comparison_spelling, conditional_form, control_flow, control_layout, control_region, conversion_form, conversion_lifetime, conversion_representation, conversion_source, conversion_spelling, declaration_order, dispatch_lifetime, dispatch_shape, global_dataflow, global_storage, initial_conversion, initial_store, lifetime, live_range_coalescing, live_range_partition, load_scheduling, loads, local_lifetime, local_representation, local_width, masking_form, narrowing, permuter_seed, pointer_form, read_qualification, record_access, record_representation, sequence_point, sequencing, stage_lifetime, statement_order, storage, storage_indirection, store_alias_type, store_expression, store_partition, store_qualification, store_schedule, store_scheduling, store_shape, tail, tail_conversion, tail_expression, tail_loop_form, temporary_representation, temporary_width, value_flow, writeback_control, writeback_partition, writeback_qualification; tie-pool yes

## 2026-10-28 native IDO 7.1 campaign

Verified at baseline `a3884b41a6c4526790213ca0061ae61f7e603788` with the
unmodified native IDO 7.1 compiler (SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`).
Every accepted batch passed unchanged-module and +20-leading-blank-line
controls covering sections, text bytes, function extents, and relocations,
then the full retail ROM comparison with host syntax checks enabled. Retail
ROM MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`.

- `func_8AE013B4`: accepted `collect:init:count-first0-guard0` (108
  instructions, 432 bytes, 0x40-byte frame). A 40-byte record carries the
  selection/variant pair and eight subordinate table addresses. Initialize
  the count before loading the record cursor; reversing those initializations
  leaves a two-instruction scheduling difference. Correct the stale `void`
  prototype to its real count return. Receipt:
  `scratch/collect13-v3/gate-0/receipt.json` in the retained stage46 worktree.
- `func_8AE057A8`: accepted the independent flag-mask updates to the three
  nodes (90 instructions, 360 bytes, 0x18-byte frame). The halfword at node offset 2 is
  toggled by masks `0x4901`, `0x9202`, and `0x12404` from the selected lookup
  entry; mode 2 clears all three flags. Receipt:
  `scratch/visibility57-v1/gate-0/receipt.json` in the retained stage46 worktree.

These are genuine compiled C matches; no instruction rewrites, coalescing,
forced registers, or added filler storage were used.
- `func_8AE01600`: accepted
  `neighbors:lifetimes:separate1-do0-guard1` (78 instructions, 312 bytes,
  0x30-byte frame). Separate backward and forward candidate variables give
  the two searches their observed lifetimes. The backward search's explicit
  nonnegative region yields the observed branch orientation. The already
  accepted `func_8AE015C4` now returns the collector's real count; callers in
  this assembly use that result to locate populated neighboring variants.
  Receipt: `scratch/neighbors16-v3b/gate-0/receipt.json`.
- `func_8AE00AF4`: accepted
  `projection:declaration-layout:order0-nested1` (74 instructions, 296 bytes,
  0xD8-byte frame). The local float and fixed matrices have their observed
  offsets when the six real scalar/pointer locals surround those matrix
  declarations. `output = D_8AE084DC = allocation` produces the observed
  global-address carrier. The lookup-entry typedef moves before this new
  consumer; the accepted lookup helper is unchanged. Receipt:
  `scratch/projection00a-v2/gate-0/receipt.json`.
- `func_8AE03BDC`: accepted `text:buffer-layout:group0-width1` (110
  instructions, 440 bytes, 0x228-byte frame). Keep the measured text width
  and padded column width as separate used values before the two 256-byte
  buffer declarations. This gives the observed buffer offsets without
  offsetting outside an array. The second buffer's zeroing is present in
  the retail assembly even though no later operation reads it. Retype
  `func_800495BC` to the variadic `(s32, s32, const char *, ...)` signature
  verified in `src/47580.c`; the old five-argument declaration described
  only one caller. Receipt: `scratch/text3bd-v2/gate-0/receipt.json`.

Parent review: corrected all four local text-width declarations to the real
`s32 func_80049148(s32, s32, const char *, ...)` signature in `src/47580.c`.
The complete module remained byte-identical, including +20blank control.
Descriptive names follow the operations above; old address-keyed names remain
assembly compatibility aliases.
- `func_8AE00AF4` → `Fragment46_BuildLookupMatrices`.
- `func_8AE013B4` → `Fragment46_CollectRecordData`.
- `func_8AE01600` → `Fragment46_FindNeighborVariants`.
- `func_8AE03BDC` → `Fragment46_DrawRecordRange`.
- `func_8AE057A8` → `Fragment46_UpdateSelectionVisibility`.
- `func_8AE03970`: accepted `text:sibling:03970-order0-width0-flow1`
  (155 instructions, 620 bytes, 0x230-byte frame). Reuse the measured/padded
  width separation and actual two-buffer layout. The label's initial byte
  is read as signed (`lb`), including each empty-string test; plain `char`
  on this compiler generated `lbu`. Its three optional labels follow the
  low three input mask bits, with mask 7 bypassing those additions. Receipt:
  `scratch/text-siblings-v1/gate-0/receipt.json`.
- `func_8AE03324`: accepted `text:variant-range:switch-order0` (166
  instructions, 664 bytes, 0x230-byte frame). The input field at offset 3
  supplies a signed upper bound. For label selector 8, modes 0, 1, and 6
  add four before narrowing it to `s8`; a three-case `switch` gives the
  observed shared branch region, whereas the equivalent OR expression
  changes that region's branch orientation and load schedule. The two
  measured/padded-width values give the ordinary two-buffer layout.
  Receipt: `scratch/text33-v2/gate-0/receipt.json`.
- `func_8AE020FC`: accepted `selection:initialize:order0-field0-mask0`
  (167 instructions, 668 bytes, 0x28-byte frame). Mode 0/1/2 copies the
  corresponding 896-byte lookup template and collects availability. A
  populated table advances selection and takes its position at offset 8;
  otherwise the three camera-position floats are narrowed into a real
  three-halfword local vector, then the two camera triples are copied.
  Ordinary halfword bit operations reproduce the node flags. Declaring
  the used lookup pointer before the vector gives vector offset 0x1C;
  reversing them moves it to 0x20. Receipt:
  `scratch/initialize20-v1/gate-0/receipt.json`.

- `func_8AE05CB4`: accepted
  `input:vector-home:var_v0-before-vector` (234 instructions, 936 bytes,
  0x50-byte frame). A `switch` with default, camera mode 0, then camera
  mode 1 gives the observed branch regions. Word-sized button snapshots
  give the observed input-value register; each saved selection is declared
  beside its returned lookup pointer. Placing the camera-state button
  snapshot immediately before the real three-float target vector puts
  that vector at offset 0x30. `func_8AE059A8` takes two arguments; the
  context-free m2c draft inferred a spurious third argument from a residual
  address in `$a2`, which must be removed using the actual accepted
  definition. Receipt: `scratch/input5cb-v5/gate-0/receipt.json`.

### Unresolved native candidates (requeue)

- `func_8AE01738`: `requeue`. Best ordinary locals / saved-state record:
  normalized 1.0, raw 0.8889, 108/108 bytes, both frames 0x28. The saved
  variant uses stack offset 0x26 instead of 0x1C; selection and result homes
  match. Separate locals, all six declaration/field orders, and a real
  two-element snapshot array were tested. The array gives a smaller 0x20
  frame and result offset 0x18. Next: establish the original saved-value
  storage/lifetimes with compiler home-slot evidence; padding or unused
  record fields would not establish that model. Retained manifests/results:
  `scratch/b17.json`, `scratch/snapshot17-v1/result.json`,
  `scratch/b17b.json`, `scratch/snapshot17-v2/result.json`,
  `scratch/b17c.json`, `scratch/snapshot17-v3/result.json`.
- `func_8AE017A4`: `requeue`. Best raw 0.9306, normalized 0.9306,
  288/288 bytes, both frames 0x40. The initial table clear keeps a common
  base in `$v1` and moves it to `$s0`, whereas retail materializes `$s0`
  directly and rematerializes it for the search. An indexed clearing loop
  reaches normalized 0.9861 but raw 0.6528 and different cursor/index
  allocation; that score is not a closer byte match. Tested pointer/index
  loops, end-symbol versus same-array bounds, separate initialization,
  real declaration orders, and minimum/selected write order. Next: inspect
  how the clearing-loop base and search cursor acquire their compiler live
  ranges rather than replaying the same pointer spellings. Latest result:
  `scratch/selection17a-v5/result.json`; indexed alternative:
  `scratch/selection17a-v4/result.json`.
- `func_8AE02470`: `requeue`. Best normalized 0.8387, raw 0.4839,
  expected/actual 248/240 bytes, frame 0x18. The first structural residual
  is expected `lw $a1, 28($sp)` versus a global-address `lui $a0`; later
  stores share that global-address carrier instead of the observed scalar
  value. Tested narrow/wide coordinates and current values, explicit
  narrowing, if/switch layout, real declaration order, and a typed node
  parameter with its stale callback prototype corrected transactionally.
  `src/4F800.c` verifies that `func_800504BC(s16 *)` writes two halfword
  coordinates; typing its destination as `s16[2]` does not change this
  mismatch. Next: examine scalar/global store merging with the actual
  node layout. Best result: `scratch/slide24-v1/result.json`; corrected
  producer/callback model: `scratch/slide24-v4/result.json`.
- `func_8AE04BFC`: `requeue`. Descending orientation cases 8, 4, 2, 1
  give normalized 1.0, raw 0.8514, 700/700 bytes; retail frame 0x78 versus
  candidate 0x70, plus differing cached-word homes/registers. Real cached
  rectangle endpoints before the texture call obtain frame 0x78 but add
  four instructions (716 bytes); computing them after the call gives a
  different 760-byte allocation. Tested ordinary SDK texture/flip macros,
  case ordering, coordinate parameter/local forms, early-return/guard
  shape, and endpoint declaration/computation order. Next: inspect the SDK
  macro scopes and actual packet/cursor roles; do not add filler to close
  the frame. Best source/result: `scratch/b4bfb.json`,
  `scratch/icons4bf-v2/result.json`; endpoint experiment:
  `scratch/icons4bf-v3/result.json`.

Parent review preserves the actual s32 variadic text-width contract in the
two new drawing owners. The existing sound wrapper now explicitly forwards
its real full-word sound ID to func_800226C0; it formerly relied on an
unprototyped incoming register. The selected camera target is a three-float
external view aliased to the12-byte assembly data at D_8AE084D0, with no new
storage. Normal/+20blank controls preserve every module byte and extent
modulo that data alias. New function names retain old assembly entry aliases.
- `func_8AE00020` → `Fragment46_PlaySound`.
- `func_8AE020FC` → `Fragment46_InitializeSelection`.
- `func_8AE03324` → `Fragment46_DrawVariantDetails`.
- `func_8AE03970` → `Fragment46_DrawCategoryDetails`.
- `func_8AE05CB4` → `Fragment46_HandleSelectionInput`.

## 2026-10-28 second native box (after aadbfd65)

The first action resumed the oldest documented `requeue`,
`func_8AE01738`, with a different storage-lifetime hypothesis. Eight C89
scope variants placed the result at its definition, limited the two saved
values to their call region, or introduced each snapshot at its establishing
read. They retained the 108-byte opcode shape but reproduced the old stack
home/frame residual; best raw 0.8519 in this family. The retained `.mdebug`
record contains no usable local-symbol locations, so it does not establish
an alternative storage model. This owner remains `requeue`; no padding or
unused fields were introduced. Evidence:
`scratch/b2-17-scopes.json`, `scratch/b2-snapshot17-scopes/result.json`.

- `func_8AE05118`: accepted `frame:render:if0-mode0-position0`,
  289 instructions, 1,156 bytes, 0x20-byte frame. Use the standard SDK
  display-list and environment-color macros, mode-specific scene roots
  and map overlays, and the observed signed halfword button positions.
  `src/340C0.c` defines `Geo_RenderRootNode` (alias `func_8003C6B8`) with
  one argument; remove the context-free draft's inferred second argument.
  A local mode snapshot changes the dispatch value's register and rejects;
  the direct global switch passes. Native baseline and +20-blank controls,
  host syntax, linked shape, and retail ROM gate passed. Receipt:
  `scratch/b2-render51-v2/gate-0/receipt.json`.

`scratch/b2-preserved-nine.json` records exact definition hashes confirming
that the nine functions accepted before this box remain textually unchanged.

### Second-box unresolved handoffs

- `func_8AE04618`: `requeue`. Expected 1,508 bytes / 377 instructions;
  the nine-rectangle SDK reconstruction emits 1,436 bytes / 359 instructions
  with the correct 0xF0 frame. Tested edge declaration/calculation order,
  guard form, equivalent pixel-versus-quarter-pixel arithmetic, and a named
  texture step; the latter family is byte-inert. The actual texture loader
  is `s32 func_8004D1FC(u8 *)` in `src/4CC20.c`; the draft's residual packet
  pointer in `$a1` is not an additional argument. Next: inspect SDK packet
  temporary lifetimes against the retained assembly; retain the real border
  geometry rather than adding arguments or packet-output rewrites.
  `scratch/b2-window46-v1/result.json`,
  `scratch/b2-window46-v2/result.json`.
- `func_8AE004C0`: `requeue`. Best normalized 0.9849, raw 0.8640,
  expected/actual 1,588/1,580 bytes, with the correct 0x170 frame in
  `markers:record-array:view1-flags1-layout1`. The counter-derived angle is
  established before the state guard. `SINS`/`COSS` use the exact definitions
  at `include/229E0.h:1983`; their unsigned-16 angle contract explains the
  second mask without adding manual duplicate masks. The producer-backed
  marker view is key at 0, flags at 4, three halfword coordinates at 8.
  Remaining structural residuals include retail's separate position-base
  materialization and packet/texture-cursor register ownership. Tested
  matrix declaration order, angle width/definition lifetime, real position
  array/pointer views, and cached flag/alpha values. Next: inspect those
  pointer live ranges; do not fill the frame or fabricate the texture
  loader's unused second argument. `scratch/b2-markers04-v3/result.json`,
  `scratch/b2-markers04-v4/result.json`,
  `scratch/b2-markers04-v5/result.json`.
- `func_8AE03D94`: `requeue`. The info view is an 80-byte object established
  by `func_8AE013B4` and the 5/6/3/4-byte record writers, including three
  four-byte events at offset 64. A direct global view plus four used header
  positions gives the correct 0x58 frame and normalized 0.9932 / raw 0.8299,
  1,756 versus 1,764 bytes. The initial flat-field version has raw 0.8662
  but a 0x38 frame and 1,744 bytes. These are separate basins, not matches.
  The remaining structural differences are around initial panel Y and
  baseline-Y value flow; a final batch tests the order/lifetime of those
  actual origin values and the animation-ready flag. None improved the best
  basin; moving the flag default shortens the owner further to 1,748 bytes.
  Next: inspect how the initial Y/base-Y values and their address
  rematerialization reach the compiler, rather than replaying these source
  orders. No unused draft spill local was retained.
  `scratch/b2-panel3d-v3/result.json`,
  `scratch/b2-panel3d-v5/result.json`,
  `scratch/b2-panel3d-v6/result.json`.
- `func_8AE02398`: `requeue`. The native shared-tail/target-snapshot family
  has best normalized 0.8704 / raw 0.7593, 208 versus 216 bytes, with an
  ordinary 0x18 frame. Tested one shared current-value store versus two,
  a target snapshot, and coordinate widths using the verified two-halfword
  producer `func_800504BC`. Next: establish the original global-position
  object and store data flow, rather than repeating the same scalar-store
  spellings. `scratch/b2-callback23-v1/result.json`.
- `func_8AE00FC4`: `layout-prerequisite`. One confirmation only: a genuine
  five-byte record-copy switch emits 416/416 bytes and normalized 1.0,
  raw 0.8558 (register differences remain). Canonical link verification
  rejects it as `section_layout_drift`, specifically "section .rodata
  exists only in the candidate object". Native `pokestadiumgs-us.yaml`
  gives fragment 46 only text/header/C/data subsegments, with no per-file
  `.rodata`; the table remains in
  `asm/us/data/fragments/46/fragment46_data.data.s` at ROM 0x2446F4.
  The sibling tables start at 0x244714 (`func_8AE01F74`) and 0x244734 /
  0x244750 (`func_8AE0626C`). Parent must perform and gate the shared
  storage migration before further source attempts on these dispatchers.
  Neither YAML, linker inputs, nor assembly were edited here. Prepared C
  and the one confirming result:
  `scratch/b2-lookup0f-prerequisite.json`,
  `scratch/b2-lookup0f-layout-confirm/result.json`.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_8AE05118` → `Fragment46_DrawSelectionFrame`.


## 2026-10-28 third native box (after c227439c)

The oldest `requeue`, `func_8AE01738`, was resumed first. Promoting either
snapshot to a word and narrowing only at the calls adds word stores and
conversion instructions (best new raw 0.8571, 112 versus 108 bytes). A real
info-buffer pointer used by both calls was then introduced at four declaration
positions, with assignment and declaration initialization variants. Those
retain the 108-byte shape; the best still has a 0x20 rather than 0x28 frame.
The pointer's earlier homes move the snapshots rather than solving the return
value's home. No frame filler was introduced. Evidence:
`scratch/b3-snapshot17-widths/result.json`,
`scratch/b3-snapshot17-buffer/result.json`. Next: inspect compiler home-slot
allocation for the three live saved values against a known matching native
small caller; source scope and promoted-snapshot families now have direct
negative evidence.

`func_8AE017A4` remains `requeue`: independent C89 clearing/search cursor
scopes, postfix versus explicit advancement, and end equality versus ordered
comparison did not improve the 288-byte, raw 0.9306 basin. A word parameter
with a real narrow selection local also worsens it. The closest source still
shares the initial address in `$v1`; retail materializes `$s0` and later
rematerializes it. Evidence: `scratch/b3-selection17a-lifetimes/result.json`,
`scratch/b3-selection17a-argument/result.json`. Next: inspect the first
address web and clear-loop/search-loop relationship rather than retrying
those scopes or the argument-width change.

A complete normalized diagnostic of `func_8AE03D94` corrects the earlier
size interpretation: the two-instruction size deficit is retail's trailing
second `jr $ra; nop` at 0x8AE04470, after the ordinary epilogue. The base/
event cursor also differs, while the origin loads are present in both
objects and are scheduled in a different order. This was obscured by the
runner's 32-row display limit. Ordinary final `return;` and a void-returning
call expression do not emit the extra return pair. No helper or padding was
added. Full diagnostic: `scratch/b3-panel-full-diff.json`; source experiments:
`scratch/b3-panel3d-return/result.json`. This remains a `requeue`; next
resolve the original return-boundary/source-shape evidence before treating
the missing eight bytes as ordinary body instructions.

The real buffer pointer and count-first declaration family improves
`func_8AE01738` to raw 0.9259 / normalized 1.0, 108/108 bytes, both frames
0x28. All six snapshot accesses now match; only the result store/reload at
0x24 instead of retail 0x20 remain. Best is
`selection:buffer-homes:count,info,selection,variant` in
`scratch/b3-snapshot17-buffer-homes/result.json`. This is not an acceptance.

### Third-box accepted checkpoint

- `func_8AE01738`: accepted
  `selection:saved-buffer:pointer-first1-init0-scope0`, 27 instructions,
  108 bytes, 0x28 frame. Declare the real buffer pointer before a saved-state
  record containing variant, selection, and count, all used. The record
  carries the two selections across buffer initialization and retains the
  collector's count across the two follow-up calls. This gives variant at
  0x1C, selection at 0x1E, and count at 0x20. Retype its three stale forward
  declarations to the real `s32` count return. No padding, unused fields,
  forced registers, or return-category tricks were used. Sealed native
  source/object/ELF/map/retail ROM receipt:
  `scratch/b3-snapshot17-state-buffer/gate-0/receipt.json`.

The third-box oldest requeue is resolved by that checkpoint. Its earlier
negative results above remain the experiment history, not an active blocker.
`scratch/b3-preserved-ten.json` confirms that the prior ten accepted function
bodies remain textually unchanged.

The bounded `func_8AE017A4` allocator search is not an acceptance: five
minutes with one worker reduced the permuter metric from 885 to 230, but
source review rejects those outputs because they omit the search-cursor
reset or retain dead references. No output was submitted as genuine C.
Its isolated baseline exactly reproduces the canonical candidate's 288
function bytes (`scratch/b3-permute17a-local-control.json`), and the raw
results are `scratch/b3-permute17a-local-result.json`. The shared launcher
initially overrode TMPDIR into the primary checkout's scratch directory;
that run was stopped. A private `scratch/b3-permuter-entry.py` imports the
unchanged package with temporary files confined to this worktree. Neither
shared tool sources nor tracked parent files were edited.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_8AE01738` → `Fragment46_RefreshSavedSelection`.

### Third-box unresolved handoffs at the extended cutoff

- `func_8AE017A4`: `requeue`. The pointer-loop basin remains raw/normalized
  0.9306, 288/288 bytes, 0x40 frames. Named sentinels, producer-backed
  record/minimum pointer types, a narrow variant snapshot, and completing
  the ten-element array inside either loop scope (using `sizeof` for the
  search count) do not fix the shared initial address. Mixed pointer-clear /
  indexed-search forms do emit a fresh search base, but the clear cursor is
  then `$v0` and the search cursor `$s3`; retail keeps both in `$s0`.
  That basin is normalized 0.9861 / raw 0.6528, also 288 bytes. Next:
  obtain compiler web/rematerialization evidence for that specific shared
  cursor before another spelling campaign. Do not treat the normalized
  score as an improvement in actual byte agreement. Latest evidence:
  `scratch/b3-selection17a-sentinel/result.json`,
  `scratch/b3-selection17a-records/result.json`,
  `scratch/b3-selection17a-mixed/result.json`,
  `scratch/b3-selection17a-extent/result.json`.
- `func_8AE004C0`: `requeue`. New best genuine source has the correct
  1,588-byte size and 0x170 frame: normalized 0.9924, raw 0.9118,
  `markers:branch-position:cursor1-decl0-flags1`. Establish the position
  pointer after each scale call, and retain the allocation snapshot and
  advancing texture-upload cursor as separate used roles. Prefix root,
  matrix, opacity, and texture colors remain coherently different, with
  further SDK constant scheduling differences. Moving the upload cursor's
  first definition/scope, using the actual marker/16-bit texture types,
  mixed vector access, matrix pointers, and snapshot timing did not improve
  this basin. Next: trace the first matrix-versus-texture pointer allocation
  rather than adding more source copies. Best manifest/result:
  `scratch/b3-markers-branches.json`,
  `scratch/b3-markers-branches/result.json`; later diagnostics are in
  `b3-markers-lifetimes`, `b3-markers-types`, `b3-markers-position`,
  `b3-markers-snapshot`, and `b3-markers-matrices` under scratch.
- UI callbacks `func_8AE02398`, `func_8AE02470`, `func_8AE026C8`: `requeue`.
  Raw node access and coordinate-record representations do not cure the
  initial global-address carrier. The initial coordinate-record generator
  incorrectly rewrote member names; those compile failures are generator
  evidence only. The corrected batch is
  `scratch/b3-callback26c-record-fixed/result.json`.
  The raw m2c shared-store label inside a case is a materially different
  CFG from the previously tested store after the entire switch. In
  `b3-callback26c-label`, case0/snapshot1/order0 reaches raw 0.8103,
  normalized 0.8793, 224/232 bytes, 0x18 frame, matching the prologue through
  the argument reloads. The case1 label has normalized 0.8966/raw 0.7931,
  220 bytes. The corresponding label families give `func_8AE02398` raw
  0.7778, 208/216 bytes, and `func_8AE02470` raw 0.7903, 240/248 bytes.
  Reusing the final reload local or ordinary conditional step/clamp
  expressions does not improve the raw basin. Next: inspect why retail
  duplicates the store and reloads into `$a0`, while the shared-case source
  branches back to one store and hoists a separate final-load carrier.
  Evidence: `scratch/b3-callback23-label/result.json`,
  `scratch/b3-callback24-label/result.json`,
  `scratch/b3-callback26c-label/result.json`,
  `scratch/b3-callback26c-label-reload/result.json`,
  `scratch/b3-callback26c-conditional/result.json`.
- `func_8AE02568`: `requeue`. The straightforward two-direction clamp emits
  316/352 bytes (best normalized 0.7614/raw 0.3182), frame 0x18. Retail has
  path-specific target stores absent from the simplified source. Next:
  establish that target-assignment value flow from an actual helper/macro
  or source-shape witness; do not manually repeat stores to fill the gap.
  `scratch/b3-callback2568-v1/result.json`.
- `func_8AE04618`: `requeue`. Pixel-to-quarter-pixel shifts materially
  improve the original macro candidate: 1,484/1,508 bytes, normalized
  0.9523/raw 0.3183, frame 0xE8 versus retail 0xF0. A persistent four-field
  signed bounds record gives the exact 1,508 bytes and 0xF0 frame, and the
  first 33 instructions match; normalized 0.9390/raw 0.2997. These are
  separate basins. Per-rectangle records/scalars add other storage or
  narrowing effects; halfword icon parameters also moved the sibling
  `func_8AE04BFC` away from its prior 700-byte basin. Next: inspect the
  coordinate factoring and first SDK temporary allocation using the
  persistent-bounds source. No packet words were rewritten, and the real
  one-argument texture-loader ABI was retained. Evidence:
  `scratch/b3-window-shifts/result.json`,
  `scratch/b3-window-bounds/result.json`,
  `scratch/b3-window-scalars/result.json`,
  `scratch/b3-icons-contract/result.json`.

The existing jump-table `.rodata` prerequisite remains in force. No further
switch probe, shared layout edit, padding helper, or instruction rewrite was
introduced during this box.

The final bounds-field/value-flow batch reproduced the persistent-bounds
basin without improvement: `scratch/b3-window-bound-order/result.json`.
Final native module controls, accepted-row provenance, preserved eleven
function definitions, and full retail ROM comparison passed:
`scratch/b3-final-module-controls.json`,
`scratch/b3-final-provenance.json`, `scratch/b3-preserved-eleven.json`,
`scratch/b3-final-gate.log`. The accepted source SHA256 remains
`b9d62a363a8470feb5ad518fcd86d6c1a4a53a1f9cf8bad53c00adf37e7e42e9`,
identical to the sealed `func_8AE01738` checkpoint source.

## 2026-10-28 fourth native box (after a743e6ee)

User extended the same exclusive assignment through 07:55 UTC, preserving
all earlier committed winners; publication and shared layout remain with
parent. The oldest actionable requeue `func_8AE017A4` was resumed first.

The unchanged native compiler's retained stages reproduce the canonical
288-byte candidate exactly (`scratch/b4-ir-control.json`). UGEN's assembly
already has one `la $3,D_8AE08888` feeding both `$s0` assignments, so the
shared-address residual precedes assembler scheduling. The explicit indexed
clear, with the same named pointer subsequently used by search, instead
reaches the previous 288-byte normalized-0.9861/raw-0.6528 basin; separating
its clear counter adds code. Grouping the actual cursor/index and result
state, and changing array decay to address-of-first-element/array forms,
reproduce raw 0.9306. Library `memset` emits a call and does not match the
retail clear. No return types, callee ABIs, registers or volatile qualifiers
were changed. Evidence:
`scratch/b4-selection17a-indexed-cursor/result.json`,
`scratch/b4-selection17a-state/result.json`,
`scratch/b4-selection17a-library-clear/result.json`,
`scratch/b4-selection17a-addresses/result.json`.

Native detailed listing was investigated without modifying the compiler.
The upstream [IDO argument parser](https://github.com/n64decomp/ido/blob/master/src/uopt/uoptinit.c) identifies `-l`/`-zdbug` as
listing controls; native listing aborts in `wrapper_ecvt` while formatting
floating diagnostics. The normal rerun and code-motion listing's emitted
ucode equal the retained normal `.O`, but the process failure means no
successful full allocation trace is claimed. The allocation listing is
truncated. Receipts and logs: `scratch/b4-uopt-list/receipt.json`,
`scratch/b4-uopt-list/{reg,motion}/listing.txt`. `-dwopcode` is a word-width
option, not an opcode-dump option; its diagnostic run was discarded as a
trace mechanism. No diagnostic flags are used by candidate admission. The
cc driver's `-keep` files were relocated into the private scratch capture;
no generated compiler artifacts are committed.


The remaining fourth-box source families also rejected without installation:

- Marker matrix arrays/records, signed/unsigned DMA-address locals, the
  producer-verified `u8 *D_8AE0A164` paired retype, Gfx-typed state lists,
  and signed/unsigned phase widths do not improve the retained 1,588-byte,
  0x170-frame, raw-0.9118 basin. The paired retype was restored on rejection;
  earlier accepted code/declarations stay intact. Evidence:
  `scratch/b4-markers-matrix-object/result.json`,
  `scratch/b4-markers-dma/result.json`,
  `scratch/b4-markers-buffer-type/result.json`,
  `scratch/b4-markers-gfx-types/result.json`,
  `scratch/b4-markers-angle/result.json`.
- Natural per-case return tails in `func_8AE026C8` do not improve its prior
  shared-case-store basin: `scratch/b4-callback26-leaves/result.json`.
- Gfx-typed state-list declarations in `func_8AE04618` leave the persistent
  bounds basin unchanged: `scratch/b4-window-gfx-types/result.json`.
- `func_8AE02568` was tested with SDK `MIN`/`MAX` target-update operands,
  which naturally reevaluate a real target assignment and therefore offer
  a source mechanism for the retail's repeated stores. These bodies emit
  348–364 versus 352 bytes and remain instruction drift; best normalized
  0.6742/raw 0.3596. This hypothesis does not establish the original source.
  `scratch/b4-callback2568-macro-target/result.json`.
- Persistent quarter-pixel bounds in `func_8AE04BFC` emit 692 or 708 bytes
  versus 700, below the earlier raw-0.8514 basin. All bounds fields were
  used; no frame filler was added. `scratch/b4-icons-bounds/result.json`.

A compiler-lineage diagnostic of the already rejected `func_8AE017A4` body
compiled under stock native IDO 5.3 with the same normal flags, emitting
320 bytes versus the 7.1 candidate's 288. This is not an alternate-compiler
match or admission. `scratch/b4-lineage17a/receipt.json`; native 5.3 SHA256
`fc0ebc664c16cee7a39caa0b4f403c8594e6bea8bc267fe8ea34060b6c1fefdc`.
The pinned 7.1 compiler and its flags remain the admission oracle.

Oldest-owner next action: obtain a source/frontend or cursor-rematerialization
witness for two independent base materializations on the same named cursor,
or inspect the retained UCODE with a functioning stock listing runtime.
Do not infer C unreachability or replay the now-inert aggregate, address,
extent, and declaration-lifetime families. All eleven earlier accepted
bodies remain protected, with their existing sealed receipts retained.
