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
