# Region notes -- src/fragments/79/fragment79_393CA0.c

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-14

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-14

TYPE CONFLICT: D_841951BD is extern u8 D_841951BD, not extern u8 D_841951D1, D_841951BC, D_841951BD

## 2026-09-14

func_84126440: plateau at 0.0 (raw None), mismatch unknown; tried families: call_sequence; tie-pool no

## 2026-09-18

func_8413860C: plateau at 0.9474 (raw 0.5263), mismatch operand_or_scheduling_drift; tried families: bounded_lookup; tie-pool yes

## 2026-09-18

func_84126850: matched (state_field_access:return_width:unsigned_halfword_result), 2 iterations, agent unbiased

## 2026-09-18

func_84126EDC: matched (constant_map:nested:single_u8_local), 1 iterations, agent unbiased

## 2026-09-18

func_841351EC: matched (state_field_access:aggregate_transfer:single_word_struct_assignment), 3 iterations, agent unbiased

## 2026-09-18

func_841256E0: matched (init_sequence:halfword_entry:constant_biased_byte_base), 2 iterations, agent unbiased

## 2026-09-18

func_84130A74: matched (state_field_access:compound_assignment:signed_global_clamp), 1 iterations, agent unbiased

## 2026-09-18

func_84125484: matched (state_field_access:while:direct-global-index), 1 iterations, agent unbiased

## 2026-09-18

func_84125424: matched (state_field_access:global_while:narrow_parameter), 1 iterations, agent unbiased

## 2026-09-18

func_84128B30: plateau at 0.7143 (raw 0.2857), mismatch operand_or_scheduling_drift; tried families: state_field_access; tie-pool yes

## 2026-09-18

func_84133B14: plateau at 0.9688 (raw 0.75), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool yes

## 2026-09-18

func_8412F39C: matched (call_sequence:direct-index:all-inline-accesses), 4 iterations, agent codex

## 2026-09-19

func_8412BB9C: matched (call_sequence:direct-index:u8-cast-u16-store), 4 iterations, agent codex

## 2026-09-19

TYPE CONFLICT: D_841951BF is extern u8 D_841951BF, not extern u8 D_841951E6, D_841951BF

## 2026-09-19

func_841383B4: matched (call_sequence:direct_global:exact_probe_match), 5 iterations, agent codex

## 2026-09-19

TYPE CONFLICT: D_84195278 is extern u8 D_8418615C, D_84195278, not extern u8 D_84195278

## 2026-09-19

TYPE CONFLICT: D_8418615C is extern u8 D_8418615C, not extern u8 D_8418615C, D_8419A006, D_8419A007, D_84199D82

## 2026-09-20

func_8413C2C0: plateau at 0.9492 (raw 0.8305), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool yes

## 2026-09-20

TYPE CONFLICT: func_8413584C is void func_8413584C(u8), not extern void func_8413584C(u8)

## 2026-09-20

func_8412DC20: matched (call_sequence:nested_guard:u8_argument_temp), 1 iterations, agent unbiased

## 2026-09-20

func_841306AC: matched (call_sequence:indexed:direct-global-access), 1 iterations, agent unbiased

## 2026-09-20

func_8412E420: matched (call_sequence:if_else:pointer_baseline), 1 iterations, agent unbiased

## 2026-09-20

func_84139528: matched (call_sequence:else_chain:direct_indexing), 1 iterations, agent unbiased

## 2026-09-20

func_841350F4: time cap at 0.9516 (raw 0.9516) after 2400s, mismatch instruction_drift; tried families: call_sequence; tie-pool yes

## 2026-09-20

func_8412C47C: matched (call_sequence:postflag:independent-switch), 2 iterations, agent codex

## 2026-09-20

func_8413794C: time cap at 0.9074 (raw 0.5988) after 2400s, mismatch instruction_drift; tried families: call_sequence; tie-pool no; 1 iteration(s) with a suspicious identical batch-wide failure

## 2026-09-20

func_8413A12C: time cap at 0.0 (raw None) after 2401s, mismatch unknown; tried families: (none); tie-pool no

## 2026-09-20

func_8413B254: matched (call_sequence:switch:cast-index), 1 iterations, agent openrouter

## 2026-09-21

func_84137D04: matched (call_sequence:nested:repeated-byte-index), 4 iterations, agent unbiased

## 2026-09-21

func_84124E44: plateau at 0.9787 (raw 0.8298), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool yes

## 2026-09-21

func_841246AC: matched (call_sequence:narrow_signature:direct_parameter), 2 iterations, agent unbiased

## 2026-09-21

func_84137BD4: matched (call_sequence:cached_destination:byte_subscript_address), 2 iterations, agent unbiased

## 2026-09-22

func_84139EB0: matched (call_sequence:else_if:pointer_table:s32_flags_exact), 4 iterations, agent codex

## 2026-09-22

func_8413DD94: plateau at 0.8919 (raw 0.4595), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool yes

## 2026-09-22

func_8413860C: plateau at 0.0 (raw None), mismatch operand_or_scheduling_drift; tried families: bounded_lookup; tie-pool yes

## 2026-09-22

func_84128B30: plateau at 0.7143 (raw 0.2857), mismatch operand_or_scheduling_drift; tried families: address_exposed_scalar, aggregate_copy, aggregate_mask, bitfield_narrowing, bitfield_update, boolean_high_bit, complement_extract, destination_alias, idempotent_recurrence, mask_algebra, mask_join, mask_phi, mask_store, masked_dispatch, masked_termination, ordered_bit_partition, ordered_conditional_phi, ordered_extract, ordered_mask, ordered_mask_absorption, ordered_mask_phi, ordered_masked_dispatch, ordered_masked_termination, ordered_modular_difference, ordered_remainder, ordered_xor_cancellation, pointer_loop, quotient_reconstruction, range_normalization, single_iteration, source_array_scalarization, state_field_access, store_forwarding, wide_extract, wide_lane_extract, wide_mask, wide_remainder; tie-pool yes

## 2026-09-22

func_8413860C: matched (bounded_lookup:conditional:permuter-shape), 8 iterations, agent codex

## 2026-09-22

TYPE CONFLICT: D_841951E5 is extern u8 D_841951E5, not extern u8 D_841951E4, D_841951E5

## 2026-09-22

func_84128B04: plateau at 0.9167 (raw 0.75), mismatch operand_or_scheduling_drift; tried families: algebraic_reset, alias_reset, assignment_dispatch, bounded_reset_loop, comparator_lifetime, comparator_materialization, comparison_narrowing, compound_reset, exclusive_arithmetic_reset, label_dispatch, local_phi, loop_dispatch, ordered_reset, permuter_seed, predicate_dispatch, reset_operand, selector_widening, sequential_guards, single_pass_block, state_field_access, store_value_lifetime; tie-pool yes

## 2026-09-22

func_84132B9C: plateau at 1.0 (raw 0.9906), mismatch register_allocation_only; tried families: call_sequence; tie-pool yes

## 2026-09-22

func_84128954: matched (call_sequence:global_access:canonical_compound_updates), 2 iterations, agent unbiased

## 2026-09-22

func_84126CD0: time cap at 0.8818 (raw 0.3273) after 2400s, mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool no

## 2026-09-22

func_841397FC: matched (call_sequence:locals:u8-index-m2c), 1 iterations, agent codex

## 2026-09-22

func_84131760: time cap at 0.9886 (raw 0.9886) after 2400s, mismatch instruction_drift; tried families: call_sequence; tie-pool yes

## 2026-09-23

func_8412D53C: matched (call_sequence:loop:byte_pointer_arithmetic), 3 iterations, agent openrouter

## 2026-09-24

func_8413A53C: matched (call_sequence:pointer-table:casted-base-expression), 1 iterations, agent openrouter

## 2026-09-27

func_84135A2C: time cap at 0.9444 (raw 0.3704) after 2400s, mismatch operand_or_scheduling_drift; tried families: address_expression, argument_definition, base_dataflow, base_materialization, cache_definition, cache_signedness, cache_storage, call_sequence, copy_address, copy_argument, exit_topology, guard_base, guard_materialization, identifier_store, lexical_lifetime, local_layout, lookup_result, parameter_home, parameter_lifetime, permuter_output, permuter_seed, pointer_storage, promoted_call_boundary, record_representation, result_lifetime, tail_dataflow, tail_increment, tail_materialization, tail_operand_order, tail_statement_order, tail_width; tie-pool yes; 1 iteration(s) with a suspicious identical batch-wide failure

## 2026-09-27

func_8412DDC0: plateau at 0.963 (raw 0.963), mismatch symbol_size_drift; tried families: call_sequence; tie-pool yes

## 2026-09-27

func_84135D3C: matched (call_sequence:guard_returns:direct_byte_indexing), 1 iterations, agent unbiased

## 2026-09-27

func_84139244: matched (call_sequence:for_loop:inequality_termination), 1 iterations, agent unbiased

## 2026-09-27

func_841266C4: matched (call_sequence:direct_index:signed_result), 1 iterations, agent unbiased

## 2026-09-27

func_84136678: matched (init_sequence:narrow_owner_signature:direct_record), 6 iterations, agent codex

## 2026-09-27

func_84128B30: plateau at 0.0 (raw None), mismatch operand_or_scheduling_drift; tried families: address_exposed_scalar, aggregate_copy, aggregate_mask, bitfield_narrowing, bitfield_update, boolean_high_bit, complement_extract, control_wrapper, copy_chain, destination_alias, destination_indirection, idempotent_recurrence, loop_wrapper, mask_algebra, mask_join, mask_phi, mask_store, masked_dispatch, masked_termination, ordered_bit_partition, ordered_conditional_phi, ordered_extract, ordered_mask, ordered_mask_absorption, ordered_mask_phi, ordered_masked_dispatch, ordered_masked_termination, ordered_modular_difference, ordered_remainder, ordered_xor_cancellation, pointer_loop, quotient_reconstruction, range_normalization, single_iteration, source_array_scalarization, source_indirection, state_field_access, store_forwarding, wide_extract, wide_lane_extract, wide_mask, wide_remainder; tie-pool yes

## 2026-09-27

func_84136014: matched (call_sequence:early_guard:probed_exact_s32_result), 1 iterations, agent codex

## 2026-09-27

func_84124E44: time cap at 0.9787 (raw 0.8723) after 2400s, mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool yes

## 2026-09-27

func_8412E680: plateau at 0.0 (raw None), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool yes; 3 iteration(s) with a suspicious identical batch-wide failure

## 2026-09-27

TYPE CONFLICT: func_84136124 is extern s32 func_84136124(u8, s16, u16, u8, u8), not extern void func_84136124(u8, s16, u16, u8, u8)

## 2026-09-29

func_8412E82C: plateau at 0.9722 (raw 0.9722), mismatch symbol_size_drift; tried families: bounded_lookup; tie-pool yes

## 2026-09-29

func_841260D4: matched (state_field_access:indexed:signed_index_byte_counter), 1 iterations, agent unbiased

## 2026-09-29

func_84124F40: time cap at 0.9875 (raw 0.975) after 2408s, mismatch operand_or_scheduling_drift; tried families: call_chain; tie-pool yes

## 2026-09-30

func_84125EC0: matched (call_sequence:byte_pointer:nonpositive_clamp), 4 iterations, agent codex

## 2026-09-30

TYPE CONFLICT: D_841951D9 is extern u8 D_841951D8, D_841951D9, not extern u8 D_841951D9

## 2026-09-30

func_84129E84: time cap at 0.9811 (raw 0.7925) after 2412s, mismatch instruction_drift; tried families: call_sequence; tie-pool yes; 2 iteration(s) hit section_layout_drift -- needs a rom.yaml fix, not more candidates

## 2026-09-30

func_841358B0: plateau at 1.0 (raw 0.9828), mismatch register_allocation_only; tried families: call_sequence; tie-pool yes

## 2026-09-30

TYPE CONFLICT: Display_QueueFramebufferRequest_fragment79 is void Display_QueueFramebufferRequest_fragment79(OSMesg), not extern void Display_QueueFramebufferRequest_fragment79(OSMesg)

## 2026-09-30

TYPE CONFLICT: func_84135808 is void func_84135808(u8 *), not extern void func_84135808(u8 *)

## 2026-09-30

func_8413C2C0: matched (initial_narrowing:wide_index:explicit_initializer_mask), 2 iterations, agent unbiased

## 2026-09-30

func_84132E40: matched (call_sequence:direct_index:signed_inequality_loop), 1 iterations, agent unbiased

## 2026-09-30

func_841350F4: plateau at 0.9841 (raw 0.619), mismatch operand_or_scheduling_drift; tried families: aggregate_address_binding, aggregate_destination_bias, aggregate_destination_view, aggregate_member_projection, aggregate_representation, aggregate_result, aggregate_source_bias, aggregate_source_view, aggregate_storage, binding_definition_point, binding_lexical_home, branch_home_representation, call_sequence, local_layout, permuter_address_form, permuter_aggregate_kind, permuter_aggregate_representation, permuter_cleanup, permuter_declaration_order, permuter_home_allocation, permuter_lifetime, permuter_output, permuter_representation, permuter_result, permuter_scope, permuter_source_address, permuter_storage, permuter_transfer_lvalue, permuter_unused_home, result_home_representation, result_home_width, scalar_transfer, scalar_union, source_home_representation, transfer_member_selection, unused_binding_alignment, unused_binding_storage_class; tie-pool yes

## 2026-10-04

func_84133304: matched (call_sequence:direct_index:narrow_signature_baseline), 1 iterations, agent unbiased

## 2026-10-04

func_84139C54: matched (stride_signedness:destination:unsigned_index), 2 iterations, agent unbiased

## 2026-10-04

func_84124798: plateau at 0.0 (raw None), mismatch unknown; tried families: call_sequence; tie-pool no

## 2026-10-04

func_84129180: matched (call_sequence:direct_index:u16_compound_baseline), 1 iterations, agent unbiased

## 2026-10-04

func_84135E4C: matched (record_base_lifetime:embedded_matrix:eliminate_record_local), 3 iterations, agent unbiased

## 2026-10-04

func_8412A028: matched (store_signedness:first_flag:unsigned_byte_alias), 2 iterations, agent unbiased

## 2026-10-04

func_8413293C: matched (call_sequence:indexed_loop:narrow_argument_local), 1 iterations, agent unbiased

## 2026-10-04

func_84139618: plateau at 0.8384 (raw 0.404), mismatch operand_or_scheduling_drift; tried families: call_lowering, call_scope, call_sequence, callee_designator, callee_type_erasure, dispatch_alias, dispatch_argument_width, erased_dispatch_address, erased_dispatch_control, erased_dispatch_index, erased_dispatch_record, erased_dispatch_table, guard_topology, index_dataflow, index_storage, owner_base, owner_index, record_addressing, record_dispatch, record_layout, record_materialization, record_representation, restriction_load, restriction_materialization, restriction_topology, selection_allocation, selection_lifetime, selection_phi, selection_scope, state_lifetime, validation_branch, validation_dataflow, validation_operand, variadic_dispatch; tie-pool yes

## 2026-10-04

TYPE CONFLICT: D_841951F8 is extern u8 *D_841951F8[], not extern void *D_841951F8[]

## 2026-10-04

func_84126440: matched (call_sequence:switch:direct_callee_individual_returns), 5 iterations, agent antigravity

## 2026-10-04

func_84126C3C: matched (call_sequence:byte_offset_arithmetic:shift_neg_cast_and_masked_sub), 1 iterations, agent antigravity

## 2026-10-04

func_84128204: time cap at 0.9459 (raw 0.7297) after 2400s, mismatch unaligned_data_drift; tried families: call_sequence; tie-pool no

## 2026-10-04

func_8412D4A8: plateau at 0.0 (raw None), mismatch unknown; tried families: call_sequence; tie-pool no; 6 iteration(s) with a suspicious identical batch-wide failure

## 2026-10-05

func_8412F170: matched (comparison_dataflow:record_pointer:two_byte_array_stride), 2 iterations, agent unbiased

## 2026-10-05

func_841268A0: matched (call_sequence:direct_global:baseline), 1 iterations, agent unbiased

## 2026-10-05

func_84131F80: plateau at 0.7209 (raw 0.3023), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool yes; 2 iteration(s) with a suspicious identical batch-wide failure

## 2026-10-05

func_84124E44: matched (call_input_materialization:second_lookup:byte_local), 2 iterations, agent unbiased

## 2026-10-05

func_8412E680: plateau at 0.9455 (raw 0.9273), mismatch operand_or_scheduling_drift; tried families: argument_materialization, call_sequence, callee_return_contract, definition_contract_repair, duration_lifetime, initial_dispatch, mode_reuse, outgoing_stack_argument, permuter_repair, permuter_seed, result_dataflow, state_base_bias, state_representation, state_store, state_store_sequence, state_value_lifetime, tail_control, tail_expression, tail_short_circuit; tie-pool yes

## 2026-10-05

func_84139F44: matched (call_sequence:switch:direct_global_index), 1 iterations, agent unbiased

## 2026-10-05

func_8412EC70: plateau at 0.0 (raw None), mismatch unknown; tried families: call_sequence; tie-pool no; 6 iteration(s) with a suspicious identical batch-wide failure

## 2026-10-05

func_8412EC70: plateau at 0.0 (raw None), mismatch unknown; tried families: call_sequence; tie-pool no; 7 iteration(s) with a suspicious identical batch-wide failure

## 2026-10-05

func_841318C0: time cap at 0.9841 (raw 0.9683) after 2400s, mismatch instruction_drift; tried families: call_sequence; tie-pool yes

## 2026-10-05

func_8413A6CC: time cap at 0.8819 (raw 0.8583) after 2400s, mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool no

## func_841366C4

Accepted recipe: retain the unsigned-byte first argument and use a signed-halfword second argument. Read byte 19841 of `D_84195280`, subtract one, replace a negative index with 29, then call the existing `func_841365F4(u8*, u8, s16)` with the record at index times 640 and both real arguments. Keep unknown names and decimal literals. Update the six existing owner declarations to the same signed-halfword type.

The original owner normalizes incoming `a1` through a shift-left/arithmetic-shift-right pair at entry, forwards it in `a2`, and stores both real arguments at their incoming homes. Its separately called 23-instruction body has a 24-byte frame and a complete return, with no shared switch tail or trailing padding. Original ASM callers, including `func_8413146C` and `func_84129374`, supply a byte and -1 and ignore the result. The compiled callers also pass -1. The helper normalizes its byte and signed-halfword inputs and stores them into the selected record; its existing prototype is retained.

The first trial kept the stale word second formal and cast only at the helper call. It failed the full ROM checksum (`4c66f0ae26d4207794df386f124ce142`): the resulting 22-instruction owner loaded the low halfword from the stack at call time instead of reproducing retail's early normalization pair. Correcting the real narrow formal and all six declarations produced the accepted match. No unrelated caller implementation or helper body changed. A declaration-count precondition initially aborted before any source write or build; it was corrected after confirming the unchanged baseline.

History audit: fleet main `afee707ab78d3f63f2f9deeadc7551ec0080eeed` has no exact owner attempt. References to this owner in other failed candidates are caller references. The full regional notes provide the record-stride clamp-wrapper recipe and warn about incoming-home and rodata dead ends. The helper's unrelated plateau (normalized 0.8788, raw 0.5455) was read and not retried; no historical owner raw score is available. All open PR scopes were checked before both trials.

Independent validation against master `47055da7fbdf7bda1f80f70fbd626c5d8233ab94`: full US ROM build with default host syntax checks and `COMPARE=1`, followed by successful `md5sum -c baseroms/us/checksum.md5`. Retail MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`. All 194 previously matched US owners, including merged #915, remained present. This local result does not substitute for the current-head and merge-result Public PR ROM Gate.

## 2026-10-22: weather healing, command sequence, and record write slot

Three owners were accepted by the recorded native candidate runner with the
ordinary host-syntax-enabled full-ROM comparison, totaling 512 bytes:

| Owner | Name | Bytes |
| --- | --- | --- |
| `8412F49C` | `BattleEffect_HealByWeather` | 264 |
| `841315C4` | `BattleCommand_RunSequence` | 160 |
| `84136CA8` | `BattleRecord_AdvanceWriteSlot` | 88 |

The healing effect reads current/max HP at offsets 38/40 of the selected
`D_84195200` record. Weather byte 2500 of `D_841951F0` selects a right shift
of 1, 0, or 2; the heal is capped by missing HP. Its real helpers are
`func_84136AF8(u8, s16, s16, u8)` and `func_841366C4(u8, s16)`.
The shift byte follows the meaningful halfword amount local, recovering
retail's stack home without padding. Maximum-first equality recovers the
original branch operands. Weather values outside 0..3 leave the shift
unspecified in the original owner; the matching source adds no default.

The command sequence dispatches bytes through `D_84185EB0`, stopping at a
byte at least 254 or a global cursor at least 27. Advancing `D_841951B8` as
a statement before loading the next command recovers the original temporary
sequence; pre-increment inside the subscript instead leaves six register
differences. The slot advance increments byte 19841 of `D_84195280`, wraps
at 30, and clears the selected 640-byte record. The neighboring record
writers provide the same stride and index evidence. Array-address spelling
recovers the original address-add operand order.

Every first successful gate immediately froze the complete changed object,
four collateral objects, source, ROM, ELF, linked script, layout inputs,
and original assembly dependencies. External hashes were checked before
further compilation. Full original-module comparison and the four unchanged
collateral objects were checked independently. No byte rewrite, artificial
local, padding, manual unroll, extra argument, or generated coverage edit
was used. Address aliases preserve the existing callers.

### `84130380`: requeue, scan/copy value lifetimes

The original scans seven stage bytes at record offset 30, advancing its byte
cursor before checking the current value against 7. If any differs, it copies
all seven stages from `D_841951BD` to `D_841951BC`, updates the target, and
emits message 73; otherwise it uses the existing failure helper. Five
eight-cell families tested cached/inline records, for/do loops, independent
scan/copy indices and byte values, advance-before-test ordering, promoted
wrapped cursors, and byte/word flags. The advance-before-test/copy-temporary
family reaches the original 256-byte size, but still has 37 raw word
differences, including a v1/a0 and a1/a2 role shift and differing relocation
positions. This is not a proven register-only residual. Next: capture the
first scan-value web and determine why it survives in v1 rather than an
uncolored byte temporary; preserve the two original loop roles. The owner
remains assembly, with no near-match installed.

## 2026-10-23: critical-hit roll

`84127C88` is accepted as `BattleDamage_RollCriticalHit`, 304 bytes, through
the recorded native runner and the ordinary host-syntax-enabled full-ROM
gate. The original threshold table `D_84185484` contains bytes 17, 32, 64,
85, 128, 128, 128. `D_8418547C` supplies the terminated high-critical move
list. The function resets `D_841951D1`/`D_841951E4`, combines the species/item
exceptions with the record flag and move/item contributions, and sets both
flags when the existing byte RNG is below the selected threshold.
`func_84125200` consumes the critical flag when comparing stage values.

Three source mechanisms recover the retail object: read the existing gate
as an unsigned byte; put species case 113 before case 83 in the source
while keeping the compiler's sorted comparison chain; and inline the record
lookup in the switch and flag test. The cached record pointer had exchanged
v0/a0 roles with the species expression, leaving seven instruction words
different. A calibrated, restricted source search found the inlining change;
its unused pointer declaration and empty statement were removed before the
candidate was submitted to the recorded runner. Neither artifact is present
in the accepted source. No padding, extra arguments, manual unrolling,
forced registers, or instruction/relocation rewrite was introduced.

The first successful gate immediately froze the source, complete module,
four collateral objects, ROM, ELF, linked script, layout inputs, and original
assembly dependencies. External hashes and the full original-module
comparison were verified before further compilation. The ROM MD5 remains
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The address alias preserves existing callers.

Publication controls compile both the complete current-master source and the
proposed public source, preserving intervening merges. Original game bytes,
section layout, and semantic relocation targets agree throughout. Public
function extents are compared with the current-master baseline: its existing
`8413E2EC` extent is 288 bytes rather than the older assembly-backed 292,
with the same trailing alignment bytes. This change preserves that metadata.

### Remaining evidence

`84130380` is already C in current master `737f43b`. Independent signed
scan/copy cursors, explicit byte wrapping, and direct indexed accesses
supersede the private cached-value candidate's 37-word residual. Earlier
stock/off/on/blank controls and the byte-local allocator observation describe
that private candidate, not an unresolved owner in the public tree. Do not
schedule this owner again; consult the current-master source when refreshing
an older native checkout.

### `8412D950`: accepted party-status clear

`BattleEffect_ClearPartyStatus` replaces all 420 bytes of `8412D950` with
genuine C through the recorded native runner and ordinary full-ROM gate.
Its active status is a byte at offset 36, saved in a real halfword local
across the existing calls; party rows have an 88-byte stride and a status
byte at offset 60. The cross-file `func_841566D0` interface takes three
byte arguments; the fourth address inferred by m2c is not an argument.

The integer loop index uses a byte-sized next-index value: assigning
`index + 1` to that value performs the original byte wrap before widening
it for row arithmetic and the next count comparison. Both values are live
parts of the cursor update. Alongside the saved status local, this source
form recovers the original stack home and multiplication sequence. No
unused local, forced register/frame, padding, or synthetic access is added.
The first successful gate froze source, whole module, four collateral
objects, linked outputs, layout inputs, and assembly dependencies; external
hashes and all original-module/collateral comparisons passed before more
compilation. The ROM MD5 remains `1561c75d11cedf356a8ddb1a4a5f9d5d`.

## 2026-10-28: native status checks before move execution

`func_84127194` is accepted as genuine C through the canonical native runner
from base `bf5c39aa5f7d927ef2ffc75b50ddf1ac1d264660`: 468 instructions,
1,872 bytes, 40-byte frame. Direct indexed byte reads and compound updates
preserve the original reloads across sleep, freeze, flinch, disable, confusion,
attraction, and paralysis checks. Sleep uses `> 0`, preserving the retail
`blez`; changing it to `!= 0` leaves one branch opcode different. Caching the
move byte changes register allocation, so the accepted body leaves it inline.
The three-argument `func_841566D0(u8, u8, u8)` call follows the existing
party-status clear interface. No output rewrite, artificial local, extra
argument, forced register, manual unroll, or new padding is involved.

The unchanged whole module and a control with 20 leading blank lines have
identical bytes, sections, function extents, and relocations. The first
`status:initial:direct` candidate passed link-shape verification, the explicit
normal host syntax recipe, and the full US ROM comparison under stock IDO7.1
(SHA256 `975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`).
Retail MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`. Private sealed evidence is
`scratch/battle27194-first/gate-0/receipt.json` in the native worker checkout;
parent integration must revalidate its combined tree. Evidence supports the
name `BattleTurn_CheckMoveStatus`; shared names/aliases are left to integration.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_84127194` → `BattleTurn_CheckMoveStatus`.

### Battle-state initializer: `8413DE28`

`func_8413DE28` is accepted through `battle-init:global-flow:global:global:global`
as genuine C: 305 instructions, 1,220 bytes, 40-byte frame. The incoming state
pointer selects generation versus existing team data. Team records have a
1,248-byte stride; the 88-byte party rows begin at offset 24, and the active
battle record begins at offset 1080. Typed team indexing recovers the byte
cursor's separate shift-count value across `func_8005D8C0`; typed party-row
indexing with a byte cursor recovers the original inner loop and frame.
Eight-byte aggregate copies reproduce the two unaligned name-field transfers.
The initializer also sets both view records, timer flags/limits, record storage,
replay seed/data, and the battle thread. Evidence supports `Battle_InitState`.

The last eight-word residual was resolved by testing the assigned global
pointer for null and reading its mode bytes directly for the two timer-flag
conditions. A cached pointer changes the allocator's state-pointer register
and the prologue schedule. Signed loop cursors, explicit shift casts,
independent loader cursors, declaration permutations, explicit early pointer
locals, state refreshes, and alternate null-return topology were tested but
did not reproduce the complete owner. These are measured source-shape limits,
not evidence that IDO cannot emit the original function.

The real two-argument interface is `void (s32, u8 *)`: the assembly initializes
state and supplies no return value, and the existing caller discards it. Its
stale later prototype was corrected in the same accepted companion transaction.
The pool functions are explicitly declared `s32 (s32)`, consistent with their
implementations in `src/3280.c`; automatic synthesis had instead introduced
conflicting void declarations in an initial compile-only failure.

The canonical runner's first successful gate passed explicit normal host
syntax and the full retail ROM comparison with the same stock IDO7.1 hash
recorded above. Private receipt: `scratch/battle3de28-global/gate-0/receipt.json`.
An independent comparison against the original module confirms all 106,496
text bytes, section layout, function extents, and sorted semantic relocations
remain identical with both new owners installed. The captures include the
original baseline object and SHA256 manifests. No output patch, fake local,
extra argument, forced register, padding, unrolling, or coverage edit was added.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_8413DE28` → `Battle_InitState`.

### Extended native checkpoint: oldest scalar-mask requeue

`func_84128B30` remains `requeue`. The September 18 scalar-mask residual was
reproduced with stock IDO7.1: retail is a 28-byte, frameless body with the
masked value in `v1`, its store before `jr`, and a nop delay slot. Ordinary
byte/promoted/halfword locals, unsigned remainder, byte bitfield extraction,
explicit void return, and source tail-location variants produce a 24-byte
body with the store in the return delay slot (best normalized 0.7143, raw
0.2857). This is a size/scheduling mismatch, not a register-only tie.

A separate diagnostic fixture compiled with both unmodified native IDO7.1
and IDO5.3. Both emitted a 24-byte return-delay-slot store for the byte-local
mask; IDO5.3 changed register allocation but did not recover the retail tail.
That compiler comparison was diagnostic only and installed no owner. Private
evidence: `scratch/mask-compiler-fingerprint/result.json`,
`scratch/battle28b30-native/result.json`, and
`scratch/battle28b30-tail/result.json`. No ABI/return-category hint, volatile
barrier, padding or instruction rewrite was tried. The bounded stale-owner
box did not find a genuine source match. Next: compare a larger authentic
source context or a measured scheduler/frontend lineage witness before
spending another box on scalar mask algebra. No impossibility is established.

### `84133B14`: accepted switch-in state update

The next September 18 requeue, `func_84133B14`, is accepted as genuine C:
63 instructions, 252 bytes, 40-byte frame. Its signed-word fainted flag is
initialized before `func_84137DB8`, set from the active record's **halfword** HP
at offset 38, and passed to `func_84133714(u8, s32, s32)` after refreshing
the selected party slot and derived battle values. The helper then clears
move bytes in both sides' records and runs `func_84131EAC`'s item check.
The word argument loads in `func_84133714` verify the two word flag arguments;
the older history's byte-argument declarations are not the interface used here.

Direct array-field accesses recover the original common shifted index without
an explicit offset or table-entry pointer local. The mirrored pointer table
uses `(u8 *)D_8419520C + -(arg0 << 2)` as a **byte** displacement; indexing
`D_8419520C[-offset]` when `offset` already equals `arg0 * 4` multiplies the
stride twice. That incorrect old spelling and a byte-sized HP test help
explain why the historical 0.9688 normalized result was only 0.75 raw. No
near-match or historical `probe_one` match marker was admitted as acceptance.

The successful `replace-switch:direct-fields:byte-offset:early:bytes` body
passed canonical link verification, explicit normal host syntax, and the full
retail ROM gate under stock IDO7.1. Private receipt:
`scratch/battle33b14-direct/gate-0/receipt.json`. The original whole-module
106,496 text bytes, section layout, function extents, and sorted semantic
relocations remain identical with all three new owners installed. No ABI
hint, unused local, forced register, padding, manual unrolling or output
rewrite was introduced. An evidence-backed name is `Battle_ApplySwitchInState`.

### `8413DA18`: accepted player deck load

`func_8413DA18` is accepted as genuine C: 68 instructions, 272 bytes,
48-byte frame. It establishes one player's 1,248-byte team record, party
pointer at offset 24 and active battle pointer at 1080, selects the controller,
opens deck type 32, reads up to six entries, and updates the count fields.
An empty read uses the existing fallback `func_8413D7AC`; both paths close
the opened handle. `src/615D0.c` verifies the real byte-pointer handle,
word count return from `Deck_ReadEntries`, and four word arguments to
`func_8006218C`. `src/585D0.c` verifies `func_8005A014(s32)`.

Typed team indexing reproduces the arithmetic and register sequence. The
initial 272-byte/48-byte candidate differed only in a controller spill at
stack offset 32 instead of 36. Independent controller and read-count locals,
entry-pointer types, handle scope, and declaration placement did not close
that residual. The accepted body directly indexes the global team table and
reuses one **used signed-word temporary**: first the controller value passed
to both word-argument APIs, then the read result stored into the count byte.
Both values participate in the real computation; there is no unused/filler
local, fake ABI, extra argument, volatile barrier or output rewrite.

The accepted label is `deck-load:shared-word-lifetime:s32:early:direct`.
Canonical link verification, explicit host syntax, and full retail ROM passed.
Private receipt: `scratch/battle3da18-word/gate-0/receipt.json`. The complete
module's 106,496 text bytes, sections, function extents, and sorted semantic
relocations still match the original baseline with all four owners installed.
Evidence supports the name `Battle_LoadPlayerDeck`; naming/aliases remain
integration work.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_84133B14` → `Battle_ApplySwitchInState`.
- `func_8413DA18` → `Battle_LoadPlayerDeck`.

### `8413DD94`: requeue, snapshot indirections and loop representation

The extended native box leaves `func_8413DD94` as `requeue`, still assembly.
Retail is 37 instructions/148 bytes with a 24-byte frame. It clears 19,844
bytes at `D_84195280`, then initializes two snapshot entries on a 16-byte
stride. The writes at root offsets 12, 14, 16 and 20 are **halfwords**;
the last four-byte field is at offset 24. Two active-record pointer loads
from `D_84195208` appear in the retail loop, alongside one party pointer
load from `D_84195200`.

Forty canonical native candidates tested scalar/aggregate transfers, typed
entry and 84-byte active-record views, distinct index widths, numeric versus
pointer-derived loop control, and value/flag store order. The compact scalar
form is 132 bytes; a four-byte aggregate or the actual color-adjustment union
produces 144 bytes with the correct 24-byte frame (best normalized 0.9459,
raw 0.4324 for the separate word-symbol view). The latter still merges an
active-record pointer load and rotates the remaining address/register roles.
It is not a register-only tie. Narrow index views expand to 156/172 bytes;
reconstructing indices from a strided destination pointer expands to
560/580 bytes and a 64-byte frame. Those are rejected source families, not
native compiler or ROM acceptance failures.

The last field is the real four-byte color-adjustment aggregate: the producer
`func_8413D6D4` passes record offset 80 to `func_8003F5AC`; the latter's
assembly uses a hidden aggregate-result pointer. Existing declarations in
`src/fragments/7/fragment7_C4C10.c`, `src/4CC20.c`, and
`include/color_adjustment.h` establish the union's halfword/two-byte fields
and raw-word view. No producer signature or existing accepted body was changed.
Using this actual union rather than a generic one-word struct preserves the
same unresolved loop result in the tested forms.

Private evidence: `scratch/battle3dd94-records/result.json`,
`scratch/battle3dd94-views/result.json`,
`scratch/battle3dd94-indices/result.json`,
`scratch/battle3dd94-cursor/result.json`, and
`scratch/battle3dd94-tint/result.json`. Next: obtain an authentic source or
measured compiler-stage witness for the duplicated active-record load and
its relation to the strided word-copy loop; preserve the verified field
widths and color-adjustment type. Do not replay the rejected pointer-difference
or narrow-index families, or add volatile/unused locals/output rewrites to
manufacture the extra instruction. No impossibility has been established.

## 2026-10-28: `func_84137404` command dispatch

Replace the 204-byte owner with a switch over its unsigned halfword command.
Command 0 does nothing. Commands 16, 18, 22, 39 and 69 call `func_8002B5B0`
with the incoming byte index and byte 0 of `D_84195208[index]`. Commands 17,
19, 20 and 21 call `Audio_RequestSlot` through its existing `func_8002B490`
alias; command 111 calls `func_8002BE44`. Other commands go to
`func_8002C2A0`, whose implementation appends the halfword to the audio event
queue. The helper implementations establish their real parameter widths;
`Audio_RequestSlot` takes only the byte index.
//@src/229E0.c
//@src/2C1B0.c

The same-file caller `func_841374D0` supplies the byte at offset 384 and each
halfword from offset 388, using the count byte at offset 386. Existing unknown
names are preserved. The switch reproduces the original 24-byte frame, all
51 instruction words, and the 40-entry jump table already assigned to this
file's `.rodata` range. No storage, padding, instruction rewrite or layout
change is needed.

Validation on master `26838e62838b8485a54857683a930772ec848191` plus this
replacement: fresh US extraction and the complete unchanged baseline passed;
`make -W src/fragments/79/fragment79_393CA0.c -j4 VERSION=us rom` then passed
with normal syntax checks and exact acceptance
`build/pokestadiumgs-us.z64: OK`. Full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail `cmp` and `git diff --check` pass.
Independent original-assembly/raw-ROM comparisons cover instructions at
`0x3A6C94..0x3A6D60` and the jump table at `0x3FA8B0..0x3FA950`.

## 2026-10-29: `func_84125080` layout-prerequisite

layout-prerequisite (0.92, shared `$at`). It refreshes a 10-byte LCG pool with `x = x*5 + 1` (a copt-unrolled `for (i = 0; i < 10; i++)` once the cursor reaches 10), resets the cursor, and returns `D_84195188[D_84195180++]`. Return type is s32, matching the existing externs. The only remaining difference: retail stores both peeled iterations (D_84195188, D_84195189) through one `lui $at`. That is the shared-`$at` assembler artifact, which needs a COALESCE-style fold this project doesn't use.

## 2026-10-29: `func_84124410` requeue

requeue (0.42). Stat-stage scaling: `value = (u16)(stat * ratio[0]) / ratio[1]`, with `ratio = D_8418542C[(u8)(stage - 1)]`, floored at 1; then the same with `D_8418542C[(u8)(13 - opposing)]`, capped at 255, stored back to *stat. Its caller's extern needs `(u8 *, u8, u8)`. Retail keeps the table pointers in $a3/$a1, the running value in $v0 and a copy in $v1. Our temporaries land in v0/t registers and the multiply operands are swapped.


## 2026-10-29 — Independently callable return entries

The command table based at D_84185EB0 contains address8412DE90 at index74
(ROM3F5868/VRAM84185FD8) and8412E944 at index84
(ROM3F5890/VRAM84186000). BattleCommand_RunSequence invokes table entries
as void functions with no arguments. Each target is a retail JR RA/NOP pair.
These are independently referenced callable entries, not solely an inference
from consecutive return instructions.

Explicit function symbols and adjacent assembly pragmas separate these entries
from func_8412DDC0 and func_8412E82C. The extractor otherwise merges a following
JR/NOP into an unbounded preceding function when its redundant-end heuristic
is enabled. Explicitly naming proven entries preserves that heuristic for
unproven boundaries. This evidence supplies no boundary claim for8005A5BC.
Source callback bodies must still pass canonical owner comparison and the
normal host/native retail ROM gate before admission.
//@src/fragments/79/fragment79_393CA0.c


## 2026-10-29 — Four command owners accepted after proven boundary extraction

The boundary baseline at `1389fa80e9c0c34f4c8b63ac3e4a121b9831d18b`
passes the native retail build with the two independently referenced entries
already symbolized. All four adjacent owners now have canonical accepted C:

| Owner | Command index in D_84185EB0 | Bytes | Frame |
| --- | --- | --- | --- |
| func_8412DDC0 | 73 | 208 | 24 |
| func_8412DE90 | 74 | 8 | 0 |
| func_8412E82C | 83 | 280 | 0 |
| func_8412E944 | 84 | 8 | 0 |

The entries at indices 74 and 84 are ordinary no-argument void callbacks with
empty bodies. The first ANSI `(void)` spelling won for each. Their table
pointers, zero-argument dispatcher calls, and original two instruction words
establish callable behavior independently of neighboring return sequences.

Command 73 loads the target active record selected by D_841951BD. It calls
func_84126BA8 for active-record byte 15 mask 0x60, byte 16 mask 0x10,
a clear low-three-bit field in party-record byte 36, or an already-set active
byte 13 bit 0. Otherwise it sets that bit and calls func_84136678 with the
real `(u8, s16)` arguments `(D_841951BD, -1)`, then func_84135B00(30),
func_84134E30(5), func_84124604, and BattleRecord_AdvanceWriteSlot.
The accepted form uses one byte pointer and direct global indexing.
BattleTurn_CheckMoveStatus clears the same bit when the party status becomes
zero; BattleEffect_ClearPartyStatus also clears it. These consumers support
its relationship to the party status, but no move-specific name is installed.

Command 83 first requires the acting party record's byte 36 low-three-bit
field to be clear. A nonzero D_841951D2 clears active byte 13 mask 0x40.
Otherwise it increments active byte 18, sets mask 0x40 while that byte is
below 5 and clears it at 5 or above, and shifts D_841951C8 by byte 18 plus
31 plus a zero/one value from active byte 14 bit 0. Results at or above
65536 are capped at 65535. The neighboring BattleAnim_Table_84185FDC_007
resets byte 18 when the flag is clear; func_84126568 and func_84134018
also inspect mask 0x40. These are verified operations; the record-field and
move meanings remain unnamed.

The first command-83 batch emitted 276 bytes: its initialized-zero conditional
lowered to a branch-likely and omitted one retail instruction. Assigning both
zero and one through a genuine `if/else`, followed by the direct compound
shift and cap, matches all 280 bytes. No filler, padding, artificial arguments,
return category, storage, labels, output rewrites, or other boundaries were
introduced. Generic owner names remain for coordinator naming review.

Three canonical batches of eight candidates retain statistics and accepted
rows for all four owners. Every winning installation passed link verification,
the explicit normal host syntax recipe, and the full native retail ROM gate
using unchanged production IDO7.1 and flags. Final ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Normal and 20-blank-line whole-module
controls passed before each batch. Final module section bytes, all function
extents, and sorted semantic relocation tuples match the earlier callback-only
gated module; raw relocation record ordering changes while the tuples agree.
The comparator sorts records for diagnosis; no object or instruction rewriting
is performed. YAML, linker script, aliases, and symbol metadata hashes remain
identical to the coordinator's boundary baseline.

Private evidence:
- `scratch/callable-battle-boundaries-baseline-seal/receipt.json`
- `scratch/battle-entries-ansi8/gate-0/receipt.json`
- `scratch/battle-parents-first8/gate-0/receipt.json`
- `scratch/battle-e82c-terminal8/gate-0/receipt.json` (all four installed)
- `scratch/battle-command-entries-final-receipt.json`
- `scratch/battle-command-entries-handoff.md`

These verified callback boundaries supply no boundary claim for 8005A5BC;
the Gen-1 scanner's separate 340-byte prefix proof remains independently scoped.

### Accepted command entry names

The four accepted definitions are named `BattleCommand_073`,
`BattleCommand_NoOp074`, `BattleCommand_083`, and `BattleCommand_NoOp084`
from their actual command-table indices. Generic-address aliases remain in
`aliases.ld`. Names preserve the full module sections, text, function extents
and semantic relocation tuples in normal and +20-line controls.
No move-specific semantics or scanner boundary follows from these names.


## 2026-10-29 — Native follow-up on four prepared owners

### `84136440`: accepted text-control record collection

`func_84136440(u8)` is accepted at 292 bytes with an 80-byte frame. For
text keys 21 through 24, it obtains text from `func_8004C874` using the
player record's byte 1179 plus 76 as the resource selector. It passes the
returned pointer to `func_80049D9C`, which parses three byte outputs.
When the first byte is positive, it sets its bit in the selected record's
word at offset 0 and appends all three outputs plus the text key to a
four-byte entry. Records have a 64-byte stride, count byte at offset 8,
and 13 four-byte entries beginning at offset 9.

The historical body discarded the returned text, passed null to the parser,
omitted the third output and placed the text key in the wrong byte. Those
operations were corrected before comparing source shapes. A typed view of
the verified record layout recovers the retail loop's load/store scheduling.
The accepted local order is signed-word cursor, three used byte outputs,
then entry pointer. It gives the actual output homes at stack offsets
75, 74 and 73 without added storage or padding.

The same accepted transaction repairs the one existing declaration of
`func_8004C874` from a word result to its real pointer result, established
by `src/4CC20.c`. Its only existing same-file caller, `func_84131760`, remains
exact across all 352 bytes and semantic relocations. The parser's real
four-byte-pointer, void-result interface is established by `src/47580.c`.
No accepted caller body or unrelated helper implementation was changed.
//@src/4CC20.c
//@src/47580.c

Acceptance label: `text-record:interleave-real-locals:i,first,second,third,entry`.
Canonical link verification, explicit normal host syntax and the full native
retail ROM gate passed under unchanged production IDO7.1 and flags.
Private receipt: `scratch/followup-36440-interleave8/gate-0/receipt.json`.

### `84133714`: accepted HP-based message selection

`func_84133714(u8, s32, s32)` is accepted at 528 bytes with a 48-byte frame.
It formats the acting active-record identifier and party name, refreshes
HP snapshots, and selects message/animation halfwords using the opposing
party's current and maximum HP. The signed-word ratio is exactly
`current_hp * 25 / (maximum_hp >> 2)`; the division is preserved rather than
replaced with an algebraically different percent calculation. The thresholds
are 70, 40 and 10, with a separate zero-HP case. A mode byte at state offset
2503 selects its existing special path. The two incoming word arguments are
forwarded unchanged to `func_84124CC4` on the normal path.

Direct halfword reads and the three real locals (ratio, animation, message)
recover the retail instructions and stack homes. A separate cached HP or
party-pointer local enlarged the frame. The accepted expression accesses the
mirrored party pointer through the existing `D_84195204` scalar pointer's
byte address and a negative four-byte displacement; no array bound or global
alias was invented. Animation and message are actual used halfword locals,
not storage to shape the frame. The existing `Battle_ApplySwitchInState` and
`Battle_InitState` callers corroborate the byte/word/word interface.

Acceptance label:
`hp-message:direct-hp:('ratio', 'animation', 'message'):constant-leftFalse`.
Canonical link verification, explicit normal host syntax and full native
retail ROM comparison passed. Private receipt:
`scratch/followup-33714-locals8/gate-0/receipt.json`.
The combined accepted module has identical allocated section bytes, all
function extents and sorted semantic relocation tuples to the original
named baseline at `788e0e30`. Raw relocation record ordering differs.
Independent check: `scratch/followup-module-seal.json`.
Both retail receipts report MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.

### `8412A804`: tooling-blocked, symbolic load admission

The corrected arithmetic uses acting-party byte 29 minus target-party byte
29 and falls back when the acting value is smaller, as established by the
retail `slt`/`beqz` and `subu`. The retained canonical candidate is
`scratch/followup-a804-ordered8.json` candidate 2: 304 bytes/frame 24,
all opcode/operand shapes exact, with only two raw word differences.
At owner offsets 80 and 140 the baseline object has literal
`lui a0,0x8419` / `lbu a0,20927(a0)` fields; the symbolic candidate has
HI16/LO16 references to `D_841951BF`. The baseline object has no relocation
at either site, so strict canonical probing rejects the added topology.
The candidate remains unaccepted and the owner remains assembly.

Ordinary GNU linking of the unchanged canonical object at addresses from the
current retail-gated ELF/map reproduces all 106,496 text bytes and 576 rodata
bytes, including all 304 owner bytes, directly against the original ROM.
This is diagnostic evidence, not an acceptance or full-ROM gate for this
candidate. No instruction, relocation, object or source bytes were rewritten.
Receipts: `scratch/followup-a804-relocation-proof/receipt.json` and
`scratch/followup-a804-relocation-proof/linked-receipt.json`.

Next action: coordinator review of a bounded canonical admission path that
validates added symbolic load fields by real linking before the mandatory
host/full native ROM gate. The existing absolute-load matcher handles a
different direction and a word-load pattern; it does not cover this literal
baseline / symbolic candidate byte load. Do not hardcode the address in C,
rewrite the baseline assembly/relocations, or install this candidate manually.
No production runner or metadata path was edited in this worker checkout.


### `8412D6C0`: requeue, move-slot promotion and PP clamp

`func_8412D6C0` remains assembly: retail is 520 bytes/frame 48. It obtains a
one-based move slot from `func_841263D8`, rejects invalid or empty PP slots,
then subtracts a random 2–5 PP amount limited by the current low-six-bit PP.
The conditional mask write and subsequent global-pointer/byte reload are
retained as real operations. Party PP is also updated unless active byte 17
mask 8 is set. The normal path preserves the original formatting, event and
record calls; existing callee implementations and return categories were not
changed to improve allocation.

Eighty-eight canonical candidates in eleven batches tested raw result versus
narrow slot carriers, count lifetimes and clamp selection, direct and actual
four-slot move/PP field views, declaration/home placement, an explicit used
global-target pointer, and success-first/guard-return topology. One additional
carrier batch was refused before probing for a repeated body; it contributes
zero source attempts. It was not bypassed with irrelevant declarations.
No candidate matched. The source is not a register-only near-match.

Retained diagnostics include `followup-d6c0-fields8` candidate 0:
524 bytes/frame 56, normalized 0.9313/raw 0.4809; and
`followup-d6c0-byte-homes8` candidate 3: exact 520-byte length/frame 48,
normalized 0.9077/raw 0.4462, with different slot promotion and clamp code.
The numerically highest normalized result, 0.9328, is a larger 536-byte/frame
64 body (`followup-d6c0-field-carriers8` candidate 7), not a better match by
length or native instruction evidence. Wider local/home/positive-guard grids
repeated the same early fingerprint and are not a useful next batch.

Passive stock IDO7.1 replay retains normal and +20-line controls for the
accepted module and two unchanged canonical parents: six complete-module
byte/section/extent/relocation controls pass. Before UGEN, the raw parent's
optimized Ucode reserves 28 local memory bytes versus 16 entering UOPT; the
field parent's reserves 20 versus 12. The latter already writes its narrowed
slot as a byte in Mmt offset -2 in UGEN input. This localizes the observed
stack representation before UGEN/assembler scheduling; it does not establish
that a saved-register slot is impossible. A read-only comparison of the
accepted `func_8412F170` byte counter also finds a stack byte across calls,
so that sibling is a negative control, not the missing positive witness.

Private receipts and decoded streams:
`scratch/followup-d6c0-stock-passes-v3/receipt.json`,
`scratch/followup-d6c0-stock-passes-v3/frame-summary.json`, and
`scratch/followup-byte-register-witness/receipt.json`.
Initial replay failures from cleaned accepted ASM includes and an overstrict
include-count assertion remain recorded; final replay uses private,
byte-identical preparation snapshots, and its whole-module controls pass.
No compiler decisions or production flags were modified.

Next action: trace the real slot's UOPT web eligibility/cost and obtain an
authentic matching byte-slot/return-contract witness. In particular,
`func_841263D8` currently has an accepted word-result definition while its
implemented range is 0–4; range alone does not prove an original byte-result
interface. Any return-contract repair needs independent evidence, exact-once
companions and affected-caller verification. Do not fabricate that interface,
add register hints, introduce unused work, or replay the failed width/home/
guard families. No owner replacement or native acceptance is claimed here.


## 2026-10-29 — Text/HP follow-up integration names

The accepted33714 and36440 owners are named
`Battle_QueueSwitchInHpMessage` and `BattleText_CollectEntriesForSide`,
with address aliases retained. The former's switch-in/init callers support
the name; its existing side/flag word arguments and signed HP ratio remain
unchanged. The latter parses three bytes from each text21..24 and appends
code/parameter0/parameter1/text_id records. `BattleTextRecord` retains the
observed64-byte stride, mask0/count8 and four-byte entries starting9.
The actual void-pointer return declaration for func_8004C874 is preserved.
Naming, parser-output names and removal of duplicate declarations in only
these two new blocks pass normal/+20-line complete-module byte/section/extent/
semantic-relocation controls. No helper function, instruction rewrite or
coverage edit is introduced by this integration. A804/D6C0 remain ASM with
the earlier tooling/requeue handoffs; neither is included as an acceptance.

The remaining assembly caller of33714 keeps its original address-name alias.
Post-acceptance naming controls resolve that exact alias to the renamed C
definition before comparing relocation targets; raw module bytes and all
function extents are identical. The final extracted build resolves it through
the tracked alias/symbol definitions and still requires the full ROM gate.


## 2026-10-29 — `8412A804` accepted through bounded symbolic byte-load proof

This acceptance supersedes the earlier `8412A804` tooling-blocked handoff.
`func_8412A804(void)` is now genuine C: 304 bytes with the original 24-byte
frame. It clears D_841951C8, rejects a clear D_841951D5 low-seven-bit field
or an acting party byte 29 smaller than the target's, and otherwise forms
an unsigned-halfword result from `func_80062DD4(D_841951BF)` plus twice the
acting-minus-target byte difference. It caps the result at 255, stores it
in D_841951C4 and runs `func_841284A4`; the existing success path sets
D_841951C8 to 65535 and D_841951D1/D_841951E4 to 2. The result local is
initialized inside the branch where it is used. No absolute-address C or
ABI/data-operation change is involved.

A private, owner-bound verifier resolves the exact canonical admission gap:
the original object has literal LUI/LBU fields at owner offsets 80/140,
while ordinary C adds one HI16/LO16 pair for D_841951BF. It requires the same
304-byte owner span, every module function extent, all allocated input-section
descriptors, unchanged non-text bytes, and no removed or unrelated added
relocation. Only this two-site ordinary LUI/LBU pair is eligible; opcode,
register flow, zero addend, and the fixed symbol address from the sealed
retail-gated ELF must agree. Every other module text word remains exact.

The verifier then GNU-links both original, unmodified objects using sealed
map/ELF addresses. All allocated output sections, their bytes and all function
extents must agree, including retained `.reginfo`. Text and rodata must also
match the uniquely named `.fragment79` section of the gated game ELF. The
first read-only regression exposed overlapping overlay VRAM ranges; the final
checker explicitly selects `.fragment79` instead of accepting another overlay
with a containing numeric range. Original failure records remain preserved.
No object bytes, relocations, original assembly, symbols or metadata are edited.

Eighteen focused private regressions pass: the old unchanged candidate is a
read-only positive link control, while wrong addresses/opcodes/registers,
nonzero addends, unrelated relocation/text changes, non-text content, section
sets, module/owner sizes, other function extents and missing map entries reject.
Invalid regression views exist only in memory; no modified object files are
written. The old rejected source was not replayed through admission or its
statistics changed. Deduplication and the declarations block remain unchanged.

Eight genuinely new canonical source hypotheses tested branch-local result
lifetimes, a used byte-base temporary, result width and natural guard-return
forms. The first candidate won:
`a804:branch-local-result:u16:named-byte-baseFalse:guard-returnFalse`.
The verifier provides gate eligibility with `link_verified: false`; the
canonical sequential path still performs the explicit normal host syntax
check and authoritative full native retail ROM comparison. Both passed.
The accepted statistics row retains the exact verifier hash and proof receipt.

Private verifier SHA256:
`3852553b04f3d7e244613f1f04172f9bc1d1e505ee36e5d02f42c4f0f3a560eb`.
Gate receipt: `scratch/a804-lifetimes8/gate-0/receipt.json`.
Complete audit: `scratch/a804-tooling-v1/final-receipt.json`.
Tests: `scratch/a804-tooling-v1/tests-receipt.json`.
Native retail MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`.
The earlier `84133714` and `84136440` accepts and the affected `84131760`
caller remain byte-identical. Production compiler/flags and metadata are
unchanged. Private verifier/tests remain ignored scratch artifacts; no
production tooling or coverage change is part of this source commit.


### Accepted command31 integration name

The original word at ROM3F57BC/VRAM84185F2C places8412A804 in
D_84185EB0 slot31, consumed by BattleCommand_RunSequence. The accepted C
therefore uses `BattleCommand_031`; its address alias remains available.
Normal/+20-line post-acceptance controls preserve all module bytes, function
extents and semantic relocation tuples while removing only redundant
declarations in this new block. Source integration is on the merged text/HP
base; its two earlier functions remain unchanged.
## 2026-10-29 — native next-three: `84131664` accepted; two durable requeues

Scope resumed from `5bbb127a` in the isolated battle-followup checkout. Selected
`84131664` (252B/63 instructions), `84137778` (468B/117) and `841334D8`
(572B/143). The last slightly exceeds the preferred128 instructions but was
fresh in available local history and is a direct sibling of accepted33714.
`84129374` was excluded after reading its branch on currently-void36124;
existing D6C0/scalar-mask/shared-LUI/layout blockers were not restarted.

### `84131664`: accepted, 252 bytes / frame24

The winning void(u8) body reads the stored acting/target globals at each
original point, including after calls, instead of recomputing the opposing
index. It clears D_841951D6, calls36D84 and BattleTurn_CheckMoveStatus, then
conditionally calls266C4 and BattleCommand_RunSequence. First accepted
candidate is `next3-31664-global8` index6; probing stopped for this owner.
The ordinary canonical runner verified link shape and passed both the explicit
normal host syntax check and authoritative full native retail ROM gate.
Receipt: `scratch/next3-31664-global8/gate-0/receipt.json`.
Retail MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`.

Independent module seal `scratch/next3-final-seal/module-seal.json` compares
the prior A804-gated object with this gate object: every allocated section's
bytes/descriptors (including .reginfo), all function extents and all semantic
relocations agree. Earlier33714,36440,A804 accepts remain identical. No private
A804 verifier is loaded for these owners; no admission/tooling changes made.

### `841334D8`: requeue — UOPT promotes the real byte parameter

Best source-faithful parent `scratch/next3-334d8-direct8.json` index0:
576B versus retail572B, frame64, normalized .8958/raw .7986. First diff byte7
is savedRA28 versus36. Candidate reserves S0 for the u8 argument and inserts
save/ANDI/reloads; retail repeatedly reads its stack byte and saves no S reg.
The real signed HP-difference ratio, u16 animation/message locals and all real
callee contracts are retained. Tried real table-entry/other-index forms,
local order, direct opposing expression, staged arithmetic/nested guards,
threshold direction, live pair defaults and scoped ratio; no family removes
the entry fingerprint.32 canonical attempts; no candidate gate reached.

Passive unmodified stock pass captures with normal/+20 complete-module controls
localize the change: frontend `Ulod Ldt Pmt length1 offset3` becomes an entry
copy and Rmt16 reads; UOPT output adds `Uregs i1=2 length1 offset16`. Accepted
33714 instead keeps Pmt byte reads with no corresponding reservation. Evidence:
`scratch/next3-stock-passes/decoded-summary.json` and owner-specific rows.
Next action: original-source/real-caller control-topology evidence or a narrow
observational UOPT eligibility/cost trace for this parameter versus33714,
then a genuine lifetime/control hypothesis. Do not repeat home/default grids
or force a memory home with unused work, address escapes or fabricated ABI.

### `84137778`: requeue — optimizer commoning of scalar timer addresses

Best source-faithful parent `scratch/next3-37778-forward8.json` index4:
464B versus retail468B/frame24, normalized .9316/raw .7778. Direct count
index0 is468B/.9145/raw .7692. First diff byte29: scalar LUI t8 becomes an
address LUI a1; compiler then shares pointer-based LH/SH rather than separate
scalar accesses. Stock pass capture shows Smt scalar input becomes `Urlda`
and indirect accesses before resets in UOPT output; no saved integer block.

Historical semantic errors fixed in candidates: no duplicated3771C; display
buffer offset is2 bytes; first/second channels17/16; signed sentinel threshold
is>=-1; preserve each branch's actual cleanup call. Confirmed real484CC API is
s32(u8,u8,u8,u8) in neighboring fragment79_3ADCA0.c. Initial8 compile failures
from its synthesized prototype appearing after accepted callers are preserved
in `next3-37778-branches8`. Exact-once forward-prototype companion before37648
plus own M2C_UNK-to-void prototype repair passes preflight; neither installs
without acceptance. No signature-comment scanner fix or workaround was used.
An eventual winner must verify affected37648/3771C/later timer callers.

48 canonical attempts include those8 compile failures. Correct branches,
early returns/count pointers, sentinel switches, explicit signed reads from
u16 storage and real branch-local timer lifetimes retain the same fingerprint.
A diagnostic field-view parent reaches .9402/raw .8205/464B, but numeric label
relationships alone do not prove original array/object bounds: obtain source
provenance before treating it as an eligible source parent. No such view gated
or installed. Next action: original timer/global object typing/access evidence
and UOPT scalar/address-commoning diagnosis; keep ASM without that evidence.
Do not invent bigger buffers/aliases, absolute-address C, barriers or broaden
the private A804 admission verifier.

Full private handoff: `scratch/next3-final-seal/handoff.md`. Eleven canonical
batches each contained8 candidates, with one skipped after acceptance. Statistics
remain enabled; stock IDO7.1/production flags unchanged. Only31664 source and
this region note are committed; no metadata/naming/coverage changes.


Integration names84131664 as Battle_RunSideCommandSequence, describing its
actual side selection and guarded command-sequence calls. Normal/+20-line
complete module controls preserve sections, bytes, function extents and
semantic relocations while removing redundant declarations only from its new
block. The old address-keyed symbol remains an explicit linker alias.
## 2026-10-29 — native command family: `8412E510` / `841330BC` accepted

This isolated wave starts at `d8d54ac6`, preserving the four earlier accepts
and the334D8/37778 requeues. Selected66–92-instruction33F10/330BC/E510 from
actual ASM and refreshed available histories (33/33/25 rows respectively;
330BC's old rows all compile failures). A fourth small setup sibling252D0
(73 instructions;34 old compile failures) followed33F10's preflight blocker.
No D6C0, documented scalar-mask/shared-LUI/layout blockers or higher-attempt
33C10/31AF8 source search was restarted.

### `8412E510`: accepted, 368 bytes / frame24

The winning void(void) source combines both already-set side flags and the
26320(actor)<2 failure into one short-circuit fallback call site. Otherwise it
sets byte13 bit0x10 and byte23=4 for each side whose bit was clear, preserving
fresh global reads and the original command sequence. First winner:
`scratch/wave2-e510-common8.json` index0. Normal host syntax and authoritative
full native retail ROM gate passed:
`scratch/wave2-e510-common8/gate-0/receipt.json`.

### `841330BC`: accepted, 316 bytes / frame48

A genuine two-entry table loop reloads the party pointer after calls, reads HP
as halfwords38/40, preserves byte-side arguments and the original conditional
command sequence, then always calls25778/259D4. First winner:
`scratch/wave2-330bc-bytecallee8.json` index0. Normal host syntax and full native
retail ROM passed: `scratch/wave2-330bc-bytecallee8/gate-0/receipt.json`.

Its exact-once companion repairs2517C to return the real s32 membership result
from24EFC(63660(arg0),8549C). The accepted24EFC source produces0/1 for a
255-terminated table, and retail330BC branches on the wrapper result. The
initial8 compile failures preserve a synthesized stale void redeclaration;
adding the actual forward prototype with the companion resolves it. A .9873
raw/exact-size parent then differed only at25778's argument: MOVE versus retail
ANDI255. Original25778 SW-homes the argument then LBU-loads home+3; supplying
that missing u8 prototype closes the caller. No guessed narrow return category.
The repaired2517C remains byte-identical to the starting gated module.

### Final source and preservation gate

Post-acceptance cleanup changes only mask notation, precedence parentheses and
nested indentation. All allocated sections (including.reginfo), function
extents and semantic relocations were independently checked before rerunning
normal host syntax and the full native retail gate. Final receipt:
`scratch/wave2-final-seal/tidy-gate/receipt.json`.
Final source SHA256:
`f39e7323c7fe9314c5207fcd9bb70f7c4321e1f1e0bde46258d48a559f42857d`.
Retail MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`.
`scratch/wave2-final-seal/final-module-seal.json` proves the entire final
allocated module, all function extents and semantic relocations equal the
starting module, including33714/36440/A804/31664 and the2517C/32300 witnesses.
Production IDO7.1/flags and canonical tooling remain unchanged.

### `84133F10`: tooling-blocked / requeue — existing ASM-callee declaration

The retained historical parent used byte HP loads where retail uses halfwords.
Corrected `scratch/wave2-33f10-halfword8.json` index0 gives268B versus264B,
normalized .9403/raw .6119, frame40. A byte-contract hypothesis for33C10 is
supported by its incoming ANDI and this caller's outgoing masks; the existing
`extern void func_84133C10(s32);` would need a u8 exact-once companion repair.
Canonical preflight for `wave2-33f10-bytecallee8` refuses before compiling:
`target func_84133C10 is still a GLOBAL_ASM owner; resolve that owner separately
before using a companion edit`. Its log is retained; no attempts/gate or source
change for that transaction. Signature-comment parsing was not changed.

Next action: coordinator resolves192-instruction33C10 (63 retained rows) or
reviews a narrow canonical allowance for repairing an existing prototype for
an ASM callee. Private unapplied declaration patch:
`scratch/wave2-final-seal/proposed-33c10-prototype.patch`. Then resume the real
byte-contract hypotheses and gate the whole module plus existing32300 caller.
That changed-prototype caller check is NOT RUN because preflight stopped it.
No shadow declaration, cast call, direct tracked repair or other bypass used.

### `841252D0`: requeue — slot induction and byte-copy value web

The source-faithful56-candidate search retains the original input/global query
sequence, four-slot scan, and bounded255-terminated byte copy. Best narrow
parent `wave2-252d0-induction8` index0:296B versus292B/frame32, normalized .9730/
raw .8108. First176 bytes are independently exact, but index truncation adds
ANDI and the copy value/register web still differs. Best exact-size word parent
`wave2-252d0-bounds8` index1:292B, .9589/raw .8082, first152 bytes exact; LI4/BNE
replaces retail SLTI4/BNEZ. Prefix seals are independently scoped at
`scratch/wave2-final-seal/252d0-prefix-seal.json`; neither owner nor candidate
ROM acceptance follows from them.

Tried actual declaration/global repairs, pointer/index scan, source-pointer
reuse, stored-byte/word sentinel forms, increment placement/real bound exits,
narrow/word index legality, meaningful post-search store, combined loop tests,
and reuse of the consumed input parameter as the real slot index. Passive
stock captures with normal/+20 controls at `scratch/wave2-252d0-stock-passes`
reproduce all allocated bytes/descriptors (including.reginfo), functions and
relocations. UOPT demonstrably changes the word parent's Ules to Uneq; the byte
parent retains Ules and truncation. Inputs/outputs/decoded rows and hashes are
retained. The candidate copy value is Rmt2; retail uses t1/t2, without an
original optimizer trace establishing its eligibility.

Next action: authentic search/copy source evidence or a narrow observational
UOPT induction/virtual-register eligibility trace. Seek a real word index
whose range test survives and the correct natural copy-value expression.
Do not repeat these control/width/lifetime grids or invent barriers, address
escapes, ABI changes or padding. Keep ASM; no candidate native gate reached.

Full durable handoff: `scratch/wave2-final-seal/handoff.md`. Thirteen batches
submit8 candidates each; one stops in preflight, and the other twelve retain
96 enabled-statistics rows (72 rejected,8 compile_failed,2 accepted,14 skipped).
Only the accepted source/helper repair and this note are committed, with no
naming, metadata, coverage or production/private admission-tool changes.


### Integration names and real item-metadata return type

The original table D_84185EB0 at ROM3F5740 contains8412E510 at slot79
(ROM3F587C / VRAM84185FEC). It is therefore BattleCommand_079, matching the
existing command-index convention. The two-entry HP/item loop is
Battle_ProcessLowHpHeldItems:641E0.c implements the item-name/effect/parameter
queries and fragment7's held-item classifier consumes the same effect lookup.
The original address-keyed names remain explicit linker aliases.

Producer24EFC returns a membership predicate, and the new loop branches on2517C;
returning that real s32 result repairs its older void wrapper without changing
its emitted bytes. The metadata-name provider635E0 actually returns s32* in
641E0.c. Existing file declarations now use that pointer result, and the new
formatter call explicitly converts the real pointer into its word payload.
No return category is invented to obtain a match. Naming, these type repairs
and redundant new-block declaration removal preserve all module bytes,
sections, function extents and semantic relocations in normal/+20-line checks.
## 2026-10-29 — native command family:28664 and308A8 accepted

Starting revisionea5a86ce. Refreshed available history selected28664 (zero
rows),EC70 (18 compile failures) and308A8 (34 compile failures), sharing the
36678/35B00/AdvanceWriteSlot command family. Six preceding accepts,2517C's real
predicate repair and all existing blocked/requeue notes remain preserved.

`func_84128664(void)` is accepted at632B/frame24. The direct branch-specific
message calls, fresh global reads, signed C8 reduction/cap and original record
sequence match. First winner `wave3-28664-branches8` index0; normal host syntax
and full native retail ROM passed. Receipt:
`scratch/wave3-28664-branches8/gate-0/receipt.json`.

`func_841308A8(void)` is accepted at460B/frame48. Real semantics corrected from
historical candidates: the slot is saved from active byte18, counter76 is a
word, CE comes from target active halfword52, and invalid halfword62 or nonzero
record byte60 both take the original error path. Record stride88 and fresh
base reload after36678 are preserved. First winner:
`scratch/wave3-308a8-minimal8.json` index0; normal host/full native gate passed.

The decisive308A8 mechanism is independently scoped: unsigned address promotion
removes the extra byte carrier; real slot-first declarations resolve its home.
A retained exact-shape parent still saves/reloads the offset at24 instead of28.
Captured compiler input has an8-byte local area. Prior variants replaced the
named word counter with another named word local, retaining that area. The
final hypothesis removes the named counter and directly reads its actual word
field in both arguments; CSE keeps the original single load. This leaves only
the actual byte slot as source storage and closes the spill homes without
padding, unused work or fabricated ABI. Final passive captures measure CFE
Mmt8->1 and optimized Mmt24->20 while the native frame stays48. No further
probing after acceptance.

Verified post-acceptance indentation/mask notation cleanup also passes whole
allocated-module identity, normal host syntax and a fresh full native retail
ROM gate. Final receipt:
`scratch/wave3-final-seal/tidy-final-gate/receipt.json`.
Source SHA256 `c1ae936afb7f21852af5cae8b31d2aefd715c4207d526171d062dd1b81f436cb`.
Retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
`scratch/wave3-final-seal/final-module-current-seal.json` compares every
allocated byte/descriptor (including.reginfo), all function extents and semantic
relocations with the starting gated module, preserving all six prior accepts.

### EC70: requeue — call-result coalescing

Best opcode parent `scratch/wave3-ec70-lifetimes8.json` index0 is488B versus
retail492B/frame32, normalized.9919/raw.9512. The random query remains inV0
where retail moves it toA1, and the sentinel usesA1 rather thanA2. A cutoff
prefetch parent has492B/raw.9756 but rematerializes a table address and still
compares againstV0; it is not an owner match.

The initial eight compile failures preserve missing synthesis of the existing
signed-byte C1 declaration. A verified forward declaration resolves compilation;
local order/scopes fix frame40 to32. Paired/raw threshold views, lookup controls,
real query carrier reuse and native-int local forms retain the missing-MOVE
fingerprint. No ABI/prototype change or alias was used.25080's final LBU proves
the produced byte value, not an original narrow C return declaration; its word
interface remains unchanged.

Next action: authentic source/interface evidence or a narrow observational
UOPT call-result coalescing/eligibility trace. Keep ASM and do not replay the
above scopes/query grids or manufacture a return category to occupyV0.

Stock passive captures with normal/+20 controls remain in
`scratch/wave3-stock-passes` and `scratch/wave3-final-stock-passes`, including
stage inputs/outputs, hashes and decoded rows. Final accepted308A8 input rows
measure the local-area reduction. Full private handoff:
`scratch/wave3-final-seal/handoff.md`. Fourteen8-candidate canonical batches
retain112 enabled-statistics rows:88 rejected,8 compile_failed,2 accepted,
14 skipped. Source/region only; no metadata, naming, coverage, admission-tool
changes, push or PR.33F10's existing prototype/guard and252D0's requeue untouched.

## 2026-10-29 native display-state family: BC64/DB28 accepted; D7AC requeue

Tested from942c2972 in the isolated source79 native checkout. Selected the
24-byte per-side display-state family: DB28 had no available prior rows,
D7AC had17 mostly semantically unsuitable historical rows, and BC64 had41
rows including a .9091 parent with an address-escape spelling and incorrect
operations. DB28 and BC64 share the actual47228 property setter; D7AC
produces their team/party data. No historical candidate with volatile or
address-escape work was reused.

**Accepted func_8413DB28**,620B/frame64, void(void):
`scratch/wave4-db28-loop8.json` index0. The two-side loop uses an existing
40-byte controller-record view (see `include/controller.h`), two real
controller indices from state bytes10/11, the original team predicate, and
fourteen distinct channel/property calls. Moving controller-base and loop
index initialization into the real for-header fixes the final two-instruction
initializer ordering difference (.9935 raw parent). The body retains the
original two-side loop and all fourteen independently specified setter calls.
Host/full native retail receipt:
`scratch/wave4-db28-loop8/gate-0/receipt.json`.

The existing setter definition in `src/fragments/79/fragment79_3ADCA0.c:2423`
is `void func_84147228(u8,u8,u8,u8,s32)`. Fourteen old declarations in this
file instead used `void(s32,u8,s32,s32,s32)`. The accepted transaction repairs
all14 through exact-once contextual companion edits. Initial compile failures
are retained, including the incomplete two-context repair; no preflight guard
or original-ASM callee prototype was changed. Whole allocated-module equality
including `.reginfo`, every function extent and semantic relocation against
the prior gated module confirms all affected accepted callers are unchanged.

**Accepted func_8413BC64**,304B/frame40, void(u8):
`scratch/wave4-bc64-minimal8.json` index4. Capture the selected controller
before the real word-returning48494 query, truncate its result to the original
byte, and read pressed buttons at controller+8. Preserve the confirm path's
one-argument sound call, fresh context accesses, signed `<104` test, context
child byte107 store and state transition. The toggle setter's channel is14.
The winning existing24-byte state-record view removes redundant state/flags
locals. Host/full native retail receipt:
`scratch/wave4-bc64-minimal8/gate-0/receipt.json`.

Verified post-acceptance braces/mask-notation cleanup has identical allocated
module bytes/extents/relocations and another normal host/full native ROM PASS:
`scratch/wave4-final-seal/tidy-gate/receipt.json`. Retail MD5 remains
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All eight prior accepts and2517C's real
return repair remain byte-identical. Generic names await coordinator review.

**requeue func_8413D7AC**, original620B/frame104, void(u8).
Source-faithful parent `scratch/wave4-d7ac-recordview8.json` index0 reaches
620B/frame104, normalized1.0000/raw.7935, rejected. First difference at owner
byte191: retail `sw a1,68(sp)`, candidate `sw a1,64(sp)`; corresponding
v1/a3 homes are72/88 versus68/84. The first47 instructions match exactly.
Opcode shape/owner size/frame equality does not establish acceptance.

The actual initializer traverses six88-byte records after a24-byte team
header, with a four-move inner loop. Species = side*3+slot+6; moves =
251-side*24-slot*4-move_index. Level100, five distinct stat-experience fields
12/14/16/18/20 set to65535, random DVs at22, byte28=255, species-name copy,
exact seven-byte aggregate copy at64, stat recalculation and current HP38
from maximum HP40. The independent stat consumers are in
`src/615D0.c:476`; `src/728D0.c:85` confirms the same record offsets. The
seven-byte type is only a view of existing storage. Keep both real loops,
fresh party-pointer reloads across calls and actual APIs: 62E10 returnsu8;
61B88 is s32(s32,u16);647C8 returnss32; HAL_Strcpy is s8*(s8*,s8*).

Five8-candidate families measured: typed1248-byte team/address vs byte
arithmetic, cached party entry vs direct table, for/do; stat-loop induction
and move-index reuse; distinct actual stat fields; final team-pointer snapshot;
and actual88-byte record views/direct team-table access. A hypothesized
five-item stat loop partially unrolls and retains index arithmetic (648B);
writing the five independently consumed fields reduces to624B. The final
team-pointer snapshot removes the extra terminal reload (620B). Direct team
access removes the112-byte frame (104B), while all four address associations
have the same remaining fingerprint. Do not repeat these equivalent address
or scope grids. Further differences begin around the random-DV store and
propagate temporary allocation through the name/seven-byte copy and final
stores. The retained snapshots/objdump are private evidence, not admission.

Next action: inspect the captured CFE/UOPT local-symbol homes and the actual
random-result narrowing/copy source interface before choosing a new source
hypothesis. A meaningful used DV/name temporary is an untested possibility,
not permission for padding, unused locals, dummy data or forced registers.
Source stays ASM. Passive stock-stage captures with normal/+20 controls live
in `scratch/wave4-stock-passes`; private handoff and aggregate receipt are
`scratch/wave4-final-seal/handoff.md` and `receipt.json`.

Twelve canonical8-candidate batches retain96 enabled-statistics rows:
68 rejected,16 compile_failed,2 accepted,10 skipped after acceptance. Production
IDO7.1/flags, one worker and shared ROM lock remain unchanged. EC70,33F10,
252D0,D6C0 and other documented blockers were not probed. No naming, metadata,
coverage or admission-tool changes; no push, PR or integration.

Passive stage measurement: finalbase4 CFE/UOPT input Mmt local area20 bytes
becomes44 bytes at UGEN input; direct-team recordview0 is16 then40 bytes.
Both preserve the same saved-register set throughFP. Six normal/+20 replays
match every allocated section, including `.reginfo`, against their retained
objects (`scratch/wave4-stock-passes/allocated-controls-seal.json`). The
4-byte source-local reduction explains the frame112-to104 transition while
the remaining home displacement persists; it does not prove retail C locals.


### Integration of native waves3/4 on the current public base

Four ASM owners replace2016 bytes:632-byte BattleCommand_008 (28664),
460-byte BattleCommand_150 (308A8),304-byte Battle_HandleConfirmChoiceInput
(3BC64), and620-byte Battle_InitializeSideDisplayStates (3DB28). The original
D_84185EB0 command table at ROM3F5740 identifies slots8/150 at ROM3F5760 /
3F5998, VRAM84185ED0 /84186108. Numeric names avoid guessing move semantics.
The input handler reads the real controller before querying the selection,
handles A confirmation or left/right toggling, and preserves its byte carrier.
The initializer uses the real40-byte controller rows and two24-byte side
states; its fourteen distinct property operations are original separate calls,
inside the genuine two-side loop.

The real external setter47228 in fragment79_3ADCA0.c:2423 is
void(u8,u8,u8,u8,s32). Existing declarations are repaired through the accepted
transaction; old callers retain identical code. Full module normal/+20 controls
preserve sections, bytes, all function extents and semantic relocations across
naming and44 redundant new-block declaration removals. Old names remain exact
linker aliases. Canonical wave3/4 receipts, ownership and requeue evidence above
remain applicable; new final integration has its own native receipt.

This public batch includes only these four C owners, genuine interface/naming
metadata and region evidence. It excludes private scripts, coverage changes and
the separate unresolved scene-renderer type checkpoint. No forced register,
no-op helper, padding, artificial work or instruction/relocation rewrite.

## 2026-10-29 native side-event family: four accepted, real interfaces repaired

Fromc68fca8e, a refreshed six-history inventory selected E680 (18 historical
compile/companion failures),28D48 (16 compile failures) and29900 (8 companion
failures). Their shared real callees are36218,366C4,35B40 and36124. Once the
interface prerequisites passed,29374 (122 instructions, no available prior
rows) joined the same family. No documented D7AC/EC70/33F10/252D0 grid was
restarted. All ten prior accepts and2517C/47228 repairs remain unchanged.

**Accepted E680**,212B/frame32, void(void):
`scratch/wave5-e680-initial8.json` index0. Direct if/else on context byte2500;
original second-store reload, side6/5 setup, message178, and conditional second
36124 call remain. Native host/full-ROM receipt:
`scratch/wave5-e680-initial8/gate-0/receipt.json`.

**Genuine36124 return repair:** the native retail112-byte wrapper calls the
existing s32-returning36014 and returns without modifyingV0; original E680,
28D48 and29900 branch on that result.36014's accepted C explicitly returns
zero/one. The companion changes the existing36124 definition to s32 and
returns that existing call's result, and repairs its one old extern. Existing
ignored-result callers (BattleAnim table entries16/17) remain byte-identical.
The direct retail ROM slice, linked/object disassembly and whole allocated
module comparison are in `scratch/wave5-return-proof/receipt.json`.

**Accepted28D48**,376B/frame32, and **29900**,384B/frame40, both void(void):
`scratch/wave5-sideinterface8.json` indices2 and4.28D48 uses sequential real
rejecting guards before setting party byte36 bit0x8 and message148.29900 uses
a conjunctive guard, sets bit0x40, message108 and quarters the original active
halfword64. Both preserve fresh globals across calls and conditional6/5 side
records. Combined host/full native gate:
`scratch/wave5-sideinterface8/gate-0/receipt.json`.

**Genuine36BEC halfword interface repair:** first body probes were otherwise
exact but passed sign-extended-1 to the current s16 formal. Original calls use
ORI A1,zero,0xFFFF. All five available original ASM calls show that unsigned
sentinel, including2955C's branch from84129694 to84129734. Its separate36B9C
call instead loads signed-1.36BEC only forwards the halfword to existing
36B60's signed halfword parameter/store. Making the existing wrapper's second
formal u16 preserves that signed conversion and every allocated instruction;
36B9C remains signed. No accepted C callers of36BEC existed before the
transaction. The exact-once companion changes that existing C definition;
no ASM-owner prototype, cast-call, shadow declaration or verifier changes.
`scratch/wave5-return-proof/unsigned-parameter.md` records the bounded source
interpretation and all original callsites; the typedef is not claimed to be
uniquely determined by assembly. Full allocated-module equality including
.reginfo, all function extents and semantic relocations is sealed separately
in `unsigned-interface-module-receipt.json` in that directory.

**Accepted29374**,488B/frame40, void(void):
`scratch/wave5-29374-existingtype8.json` index0. The nonzero party-byte36 path
conditionally clears bit0x20 state through36BEC, message119 and34D28 before
resetting that byte. The zero path preserves the optional26390 query,
query-type21 rejection, halves active halfword60, sets party bit0x10,
message188 and conditional side records. D_841951C1 has a later existing s8
declaration; the early forward declaration keeps that type and explicitu8
conversions reproduce the original LBU. Initial undefined-byte and conflicting
u8-extern failures remain recorded. Host/full native gate:
`scratch/wave5-29374-existingtype8/gate-0/receipt.json`.

Final accepted guard/mask/continuation readability cleanup was compiled before
installation and checked for identical allocated module bytes/extents/relocs,
then normal host/full native retail-gated again:
`scratch/wave5-final-seal/tidy-final-gate/receipt.json`. All four owners stop
on first acceptance; the full batch accounts for1460 retail text bytes.

**tooling-blocked fifth-family prerequisite,2955C:** assembly-only inspection
finds an actual conditional25778 return consumer.25778 remains an active ASM
owner with its existing void declaration. Read-only canonical preflight
reports `companion_edits[0] target func_84125778 is still a GLOBAL_ASM owner;
resolve that owner separately before using a companion edit`. No fifth-owner
C body or compiler probe ran. Preserve ASM; resolve that actual interface in
its own scope. A future2955C transaction also needs an explicit return of the
existing36014 result in accepted s32 helper360C0. Its older parents wrongly
cached mutable globals, used acting instead of target side for two calls, and
used36CA8 instead of AdvanceWriteSlot. Do not transplant them unchanged.
Exact diagnostic: `scratch/wave5-return-proof/2955c-prerequisite.json`.

Six canonical8-candidate batches retain48 enabled-statistics rows:4 accepted,
10 rejected,16 compile failures,18 skipped after acceptance. Every batch has
normal/+20 whole-module controls. Production IDO7.1/flags, one worker/shared
ROM lock, host/full retail gates and canonical tools remain unchanged.
Retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Durable private handoff and
aggregate receipt: `scratch/wave5-final-seal/handoff.md`, `receipt.json`.
Only assigned source/region tracked; no naming, metadata, coverage, private
helpers, push/PR or integration changes.


### Native side-event integration on PR2054 master

The retail command table D_84185EB0 at ROM3F5740 identifies 28D48 as slot14,
29374 as18,29900 as20 and2E680 as80. Names BattleCommand_014/018/020/080
therefore follow the original dispatch indices without speculative move names.
The four owners cover1460B (376+488+384+212); original address aliases remain.
Naming and removal of48 duplicate declarations in these accepted blocks pass
normal/+20 complete-module section/byte/extent/semantic-relocation controls.
The return-result and unsigned-halfword repairs above preserve their actual
consumer contracts; source61/67 research, coverage and private helpers are absent.

## 2026-10-29 native command-guard family: five accepted;25778 layout prerequisite

Scope began at470457c6 in the isolated native source79 checkout. First checked
25778 for2955C. This file has a576-byte `.rodata` range at ROM3FA810..3FAA50,
but the helper's six-entry `jtbl_8418AD94` is at3FA624..3FA63C in
`asm/us/data/3F9690.rodata.s`. The current gated source object still lists that
symbol UND. All six words were independently checked against the retail ROM.
Available history has187 rows (126 rejected,61 compile failures); its best raw
parent is .7815/.9735 normalized, rejected as `section_layout_drift`.
**layout-prerequisite:** no new C hypothesis or confirming compiler probe was
needed. Proof: `scratch/wave6-25778-layout/receipt.json`.

Coordinator next action: plan ownership/layout for the earlier AD94 table,
reconcile adjacent ADAC/ADCC tables and existing later source tables, re-extract
with pinned tooling and gate the unchanged ASM baseline. A24-byte table move
alone is not asserted sufficient. Only then resume25778's real return contract
with its recorded history.2955C remains ASM behind that prerequisite/prototype
guard;360C0's separate explicit-return prerequisite is now resolved below.
No YAML, linker, table, alias, coverage or verifier changes were made here.

The replacement family was selected from refreshed available history:
B958 (17 compile/companion failures), AAE8 (26 compile failures), B65C
(45 compile failures). Their real record/message/predicate callees overlap.
After their accepts, C294 (48 compile failures, no scored local body) and DE98
(no available attempts) joined the same family. Old D7AC/EC70/33F10/252D0,
334D8/37778 and known layout/shared-LUI grids were not restarted.

| Accepted owner | Retail bytes | Frame | Canonical manifest/index |
| --- | ---: | ---: | --- |
| func_8412B958 |580|40|`wave6-b958-companion8.json`,0|
| func_8412AAE8 |784|32|`wave6-aae8-initial8.json`,0|
| func_8412B65C |764|40|`wave6-b65c-initial8.json`,0|
| func_8412C294 |488|40|`wave6-c294-ppaddress8.json`,4|
| func_8412DE98 |904|56|`wave6-de98-hpvalues8.json`,1|

All are void(void),3520 bytes total. Each owner's first accepted candidate
stops its probes. Host/full native gate receipts are
`scratch/<manifest stem>/gate-0/receipt.json`.

B958 preserves three distinct rejecting messages102/110/71, the status/active
record guard, shared side-record creation, original message108 and final25778
call with ignored result. AAE8 preserves its25-type rejection, flag0x80 path,
three command exceptions76/92/118, real RNG duration, fresh records after calls
and separate15/16-type terminal cleanup. B65C preserves messages102/150/71,
status0x8 creation, command33's original extra active fields,149/148 messages
and distinct3/2 side-event queries. All globals remain fresh where the original
calls can modify them; no original condition or data operation was omitted.

**360C0 genuine return repair:** its existing s32 signature was correct but
its C body omitted return of36014. The original100-byte retail body calls the
existing explicit0/1 provider36014, then restoresRA/SP and returns without
changingV0. B958/AAE8/B65C/C294 branch on the value. One exact-once companion
adds the real return; signature and arguments remain unchanged. Whole allocated
module bytes including.reginfo, every function extent and semantic relocation
remain identical. Direct ROM slice at3A5950 and original/accepted disassembly:
`scratch/wave6-360c0-proof/receipt.json`. An initial invalid companion lacked
its target's name in the old-text context; canonical preflight rejected it
before any candidate compile/statistics row. The corrected transaction uses
the complete existing function as exact-once context. No guard was bypassed.

C294 captures the original move byte38 and retains the meaningful RNG retry
loop. Its byte duration and move have retail homes SP39/SP38. The initial
488-byte parent had matching opcode shape but .8279 raw. Updating the real
duration byte with `+=` before its store removed the post-call temporary drift
(.9918 raw); the remaining one-word PP-address operand order at owner byte72
matched with `*(slot + (active_record + 9))`. This is an ordinary access to the
existing PP bytes, with no escaped address or allocated buffer. Earlier direct
PP address spellings retained the same negative; unselected struct/pointer
forms were not installed. Provider calls, all stores and the retry count stay
original. Retained diagnostics: `scratch/wave6-c294-*/result.json`.

DE98's initial904-byte parent differed only at frame entry/exit (owner offsets
0/892):48 versus56. The saved callback flag is SP47 in both. The accepted
source names the actual bounded HP amount (`u16`, from2676C), returned damage
(`u32`, from26804), then the used byte flag. It forwards the real signed
negative halfword to36AF8 and preserves each distinct callback and state-store
sequence. No dummy or unused locals were added. Stock pass evidence shows the
inline parent UOPT local span12→UGEN1 byte; the accepted named-quantity order
is9→9 bytes, with flag Mmt offset-9 instead of-1. Its saved-register set is
unchanged. Six normal/+20 passive replays for the final evidence independently
match all allocated bytes including.reginfo, function extents and semantic
relocations. See `scratch/wave6-de98-final-stock-passes/decoded-summary.json`
and `allocated-controls-seal.json`; initial captures are also preserved.

Final accepted indentation/mask/cast cleanup was independently compiled before
installation, checked for complete allocated-module identity, then normal
host/full-native-ROM gated again:
`scratch/wave6-final-seal/tidy-final-gate/receipt.json`. Retail MD5 remains
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All14 earlier accepts and2517C/47228/
36124/36BEC interface repairs remain unchanged. Private aggregate receipt and
handoff: `scratch/wave6-final-seal/receipt.json`, `handoff.md`.

Eight valid canonical8-candidate batches retain64 enabled-statistics rows:
5 accepted,29 rejected,30 skipped after acceptance. The separate invalid
companion preflight consumed zero candidate hypotheses. Every batch retained
normal/+20 whole-module controls. Stock IDO7.1/flags, one worker/shared flock,
canonical admission and host/full-ROM gates are unchanged; the A804 plug-in
was not loaded. Source/region only, explicit-path hooks-disabled commit; no
metadata/naming/coverage/private helpers shipped, integration, push or PR.


### Native five-command integration on PR2055 master

The original D_84185EB0 table identifiesAAE8 as35,B65C as40,B958 as41,
C294 as48 andDE98 as75. These five C owners cover3520B; evidence-backed
BattleCommand_035/040/041/048/075 names retain old address aliases. The
existing360C0 s32 result is explicitly returned with unchanged native code.
Naming plus111 duplicate new-block declaration removals preserve normal/+20
whole allocated module bytes/extents/semantic relocations. Real PP-byte
address arithmetic and HP-derived scalar carriers remain; no fake work,
padding or instruction patch. Separate scene67/61 research, coverage and
private helpers are excluded. The unresolved25778 layout remains separate.


## 2026-10-30 early table prerequisite resolved by aligned TU split

**RESOLVED:** previous layout-prerequisite notes for25778/26FA0/3146C/343FC
no longer describe current layout. The source now ends at existing function
boundary841347A0 (ROM3A4030); later owners live in fragment79_3A4030.c.
No function body or signature changed. Both native source halves reproduce
all106496 original code bytes when ordinarily linked against native baseline
exports, under normal/+20 controls. Early-source text66448B, later40048B.

The existing17-byte `SendFightThread\n` literal at ROM3FA610 is retained as
a real const char asset, followed by its natural4-byte table alignment. With
the four original tables (24+32+256+20B) it occupies352B at3FA610..3FA770.
This preserves real ROM data; no invented padding, helper, instruction or
relocation rewrite is used. The shared format-string gap3FA770..3FA810 stays
shared. Later576B of tables at3FA810..3FAA50 follow the later source object.
The code cut and both owned data windows satisfy existing16-byte SUBALIGN.

Pinned extraction defines AD94,ADAC,ADCC,AECC inside their respective original
ASM owners; all four source-object symbols are defined in .rodata, not UND.
The still-assembly host/full native retail ROM gate PASSED with unchanged MD5
1561c75d11cedf356a8ddb1a4a5f9d5d. Four final normal/+20 object controls preserve
all allocated bytes,reginfo,extents andsemantic relocations. Eighteen duplicate
inherited declarations in the later TU were removed only after those controls.

New ready owners: func_84125778,func_84126FA0,func_8413146C,func_841343FC.
Retain their old source histories and restore their best genuine candidates
only through canonical batches in this new layout. Cases must match actual
table target words; layout readiness does not establish a C body match.
2955C still needs the real25778 return contract accepted first; the genuine
360C0 return repair is already present. No active-ASM prototype guard bypass.

Earlier mixed-file notes remain historical evidence; later-file requeues and
current paths are summarized in fragment79_3A4030.md. Private proof packets:
battle-early-table-layout-plan, battle-early-tu-native-preview,
battle-early-tu-module-controls and battle-early-table-layout-gate1. The
proposed direct --just-symbols preview failed with R_MIPS26 overflow; ordinary
PROVIDE exports of actual native baseline addresses produced exact code.
Only the final normal production host/full-ROM gate establishes admission.

## 2026-10-30 native early-table family: five owners accepted after layout checkpoint

Base `6689d7d30f61fc23aaccb6e7e557166aa6ac43f5` supplies the aligned TU split
and four source-owned early tables. This block replaces five ASM owners with
ordinary C, totaling **2,984 retail code bytes**. Each owner stopped at its
first canonical acceptance; all five passed explicit normal host syntax and
full native retail ROM gates. Final MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`.

| Owner | Bytes | Frame | Canonical winning batch/index |
|---|---:|---:|---|
| `func_84125778` |604|48|`early-25778-masks8`,0|
| `func_8412955C` |932|48|`early-2955c-byte8`,0|
| `func_84126FA0` |312|24|`early-26fa0-byteprovider8`,0|
| `func_8413146C` |204|24|`early-3146c-initial8`,2|
| `func_841343FC` |932|40|`early-343fc-homes8`,2|

### 25778: real return, six masks and complete record cleanup

The documented 187-row requeue is resolved. Historical best C used the wrong
advance routine, read the wrong table for the active slot passed to566D0,
and omitted the conditional final clear. None of the187 retained bodies used
`BattleRecord_AdvanceWriteSlot`;179 explicitly used36CA8. The accepted C calls
AdvanceWriteSlot, reads slot10 from the selected `D_841951F8` record, and clears
entry byte1 only when the existing real2517C result is nonzero.

The selector is63660(entry byte1), followed by a fresh byte36 load. Actual
cases10..15 require masks08/20/10/07/40/7F respectively, all nonzero; defaults
return0. Successful paths retain the flags across calls, perform original
record mutations/reloads, and return1. Retail uses full16-bit clearing masks
FFFE/FF7F before byte stores; those immediates closed the initial604B/frame48
parent's three mask differences. Table relocation addends were handled by
ordinary linking and the authoritative ROM gate, without object rewriting.

The provider's original returns0/1 and2955C's branch at841297A4 establish the
`s32(u8)` contract. Two existing void forward declarations were repaired via
exact-once canonical companions. All previously accepted caller bodies remain
byte-identical. The old separate-provider/prototype blocker for2955C is closed.

### 2955C: observed unsigned byte and existing return-bearing helpers

The accepted caller preserves changing globals across calls, target/acting
side choices, AdvanceWriteSlot and the existing360C0/36124 result checks.
The mode2 path uses signed-1 with36B9C; the other path uses the actual unsigned
65535 with36BEC. The360C0 explicit return repair was already in the baseline;
it was preserved, not re-edited.25778's actual result controls the subsequent
record cleanup. The saved entry flag is a realu16, matching SH/LHU atSP46.

A932B parent differed in exactly four instructions around `D_841951C1`:
its existing global declaration is s8, but retail uses LBU. Explicit `(u8)`
interpretation in both the guard and26390 argument closes those differences;
the global declaration was unchanged. An initial redundant u8 extern conflicted
with the existing s8 declaration; the diagnostic and corrected declaration
context remain in the private batches. No prototype or deduplication bypass.

### 26FA0 and3146C: original table operations and byte provider contract

26FA0's eight cases call C874(16,index) for indices9/11/13/14/15/12/10/8,
then pass that real pointer through the32-bit C54C argument with command43.
The provider's initial ANDI and argument home establish its u8 parameter.
Six stale s32 prototypes in existing accepted callers were retyped through
exact-once companions. All301 other prefix functions, including those callers,
retain identical unlinked code bytes; no artificial branches or unused locals
from the historical permuter parent were used.

3146C keeps the actual D8 guard, twelve selector cases14/96/97/104/106/107/
110/111/112/133/151/159, and all64 original jump-table targets. Its default
path calls366C4(target,-1),34EC8(8), then uses the cached real D9 value for the
low-nibble26FA0 argument and high-nibble143/144 continuation. The winning
local is u32; the narrower local changed allocation. Actual provider/consumer
signatures are used throughout.

### 343FC: real33F10 result and distinct five-case sequences

Retail stores33F10's s32 result atSP32 **before** calling the already-defined
void37DB8, then tests the saved result after the counter increment. The old
volatile parent instead consumed37DB8 and also inserted/omitted actual case
calls. Accepted C preserves the unusual original counter choices in cases1/2,
keeps33ACC only at the observed sites, and expresses case5's final counter as
`D_841951F8[1 - side]`. Declaring the real byte side before the result places
it atSP39 while the result occupiesSP32, matching the original frame40.

The added consumer prototype for previously undeclared33F10 is supported by
its actual byte argument mask and explicit0/1 return paths. Its ASM body was
not changed. The existing wrong33C10 prototype and33F10's separate blocked
owner remain untouched; no companion targeted either active ASM owner. The
existing `D_841951FC` symbol identifies the second pointer slot for constant
counter accesses; no global alias or metadata definition was introduced.

### Preservation and receipts

Ten canonical batches of8 retain80 enabled-statistics rows:5 accepted,
28 rejected,16 compile failures and31 skipped after acceptance. Both initial
compile-failure batches are retained:2955C's redundant data declaration and
26FA0's existing s32 prototypes. Each batch kept normal/+20 whole-module
controls, one probe compiler worker and the shared native ROM gate lock.
Production IDO7.1/flags and canonical tools were unchanged; no A804 plug-in.

Final post-acceptance braces, indentation and numeric-notation cleanup was
compiled before installation. Normal/+20 objects preserve all allocated
bytes including.reginfo, extents and semantic relocations relative to the
accepted module, followed by another explicit host/full native ROM PASS.
All301 other prefix functions retain exact object code and every function
extent is unchanged. Source-owned352B rodata is identical; linked prefix66448B
plus untouched tail40048B reproduces all106496 retail code bytes. At the raw
object stage only five relocation-controlled text words differ from baseline,
and one compiler.reginfo FP mask bit differs; reginfo is discarded by the
existing linker script and absent from the native ELF. This is recorded,
not normalized or patched. Final normal/+20 controls include that metadata.

Private root `/private/tmp/gs-agent-battle-early-m0s2kbwm/repo`:
`scratch/early-final-seal/{receipt.json,handoff.md,module-preservation.json,owned-layout.json}`.
Final gate: `scratch/early-final-seal/tidy-gate/receipt.json`. Per-owner gates:
`scratch/<winning-batch>/gate-0/receipt.json`. Earlier19 accepts, all existing
interface repairs, the later TU, metadata and coverage are preserved. Old
38A0C/B870 and other sealed requeues remain in their original workspace; no
new requeue from these five owners. Naming/public integration stays separate.

### Integrated early-table family naming

The retail command table at 0x84185EB0 places 0x8412955C at slot 19:
`BattleCommand_019`. The table at 0x84186004 places 0x8413146C at slot 81:
`BattleAnim_Table_84186004_081`. Both retain old-address aliases. Removed only
redundant declarations in the five new blocks; independent normal and +20-line
complete-module controls preserve allocated bytes, metadata, function extents
and semantic relocations. The other three owners retain address names until
stronger naming evidence exists.


## 2026-10-31 — Sleep Talk selection, move priority, and switch refresh

Four assembly owners now have matching C, admitted on master
`54cab2256c97c68473fd4116f17ef97762197245` and retained in raw commits
`48cd07ad` and `d20ff772`:

| Original owner | C name | Bytes | Stack frame |
| --- | --- | ---: | ---: |
| `func_8412D390` | `BattleMove_HasSleepTalkChoice` | 280 | 48 |
| `func_8412D4A8` | `BattleMove_IsSleepTalkSlotEligible` | 148 | 32 |
| `func_84131F80` | `BattleMove_GetCurrentPriority` | 172 | 40 |
| `func_841339D0` | `Battle_RefreshSideAfterSwitch` | 252 | 48 |

The Sleep Talk scan checks the low three sleep-status bits at party-record
byte 36, then visits four move slots at active-record offsets 5–8. It writes
the inspected move to `D_841951BF` and rejects empty slots, move 214
(Sleep Talk), excluded effects, and the disabled move at offset 37. The
per-slot predicate applies the same move restrictions. Their caller
`func_8412D53C` first checks for an available choice and then selects a random
slot until the predicate accepts it. The scan's byte-wrapped counter and the
predicate's shared zero-return path reproduce the original control flow.

The existing wrapper at `0x841264CC` forwards `func_84126440`'s return value;
both newly decompiled callers test that value. Its previous `void` return
annotation was incorrect. It is now named
`BattleMove_IsSleepTalkEffectExcluded`, replacing the unrelated particle-name
annotation. The effect table read by `func_80062D20` maps its six excluded
effects to move IDs 130, 13, 143, 76, 19/91, and 117. This is a predicate,
with no particle-system operation.
//@src/638E0.c

The priority lookup treats move 233 as priority zero, then scans effect/value
pairs at `D_8418545C` until effect 255. The decoded pairs are
`6F:3, 74:3, 67:2, 1C:0, 59:0, 90:0`; unlisted effects return one.
`func_8413202C` compares the two sides' values to choose which side acts first.
Using the team table directly avoids a redundant pointer local and recovers
the original call-save slots without padding or unused storage.

The switch refresh is called by `func_84133ACC` after `func_841334D8`.
It clears active-record byte 16 bit 0x40, derives the fainted flag from the
party-record halfword at offset 38, runs the existing refresh routines and
queues the HP message, then clears the selected move and the existing
selection-state bytes. It preserves the original negated byte offset into
`D_8419520C`; replacing that expression with subtraction changes the compiler's
address construction.

Each owner passed the canonical object/link checks, explicit normal host
syntax check, and the complete US-ROM comparison. The final four-owner gate
produced retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Naming and declaration
cleanup are separately checked against the entire accepted module, including
sections, instruction bytes, function extents, and resolved relocations, with
normal source and a 20-blank-line control. Old symbol aliases remain available.
No coverage files, instruction rewrites, padding, or compiler flags changed.

## 2026-10-31 native damage modifiers

`func_841280D8` is now `BattleDamage_ApplyTypeAndWeather` (300 bytes).
The function bypasses move 165, applies the matching-attacker-type bonus,
calls the weather multiplier, halves effect 151 damage in weather 1, and
applies defender type effectiveness. `func_84126390` compares the move type
with both attacker types; `func_800632CC` returns the effectiveness byte and
updates damage through its pointer. A zero effectiveness sets the failure
flag, while the status byte preserves the same-type bonus bit.

The native runner accepted a byte-sized effectiveness local and direct global
record accesses. The complete US ROM matched retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, with the normal host syntax check enabled.
Naming and indentation passed whole-module byte, section, symbol extent, and
relocation comparisons in both normal and 20-leading-blank-line controls.
The original address remains a linker alias.

### Selected moves and guarded stat stages

`BattleMove_ResolveSelectedMoves` (`84126CD0`, 440 bytes) resolves each side's
command into a move, selecting the locked move, Bide (117), the selected slot,
or Struggle (165) when PP is exhausted. It clears counters whose move effects
are no longer selected and publishes the move through `func_80031844`.
Direct global record accesses and index-before-pointer addition reproduce
the original register allocation; the side mask preserves the call's byte
argument without a separate long-lived conversion temporary.

`BattleStats_ApplyGuardedStageChange` (`84125CF8`, 456 bytes) checks battle
failure and target-state guards, rejects blocked decreases and saturated
stages, adjusts the selected stage within 1..13, and refreshes derived stats
for indices below 5. Stat 6 with move 107 sets the Minimize marker. The packed
stat/amount and result fields are also maintained for message consumers.
Its close sibling `func_84125EC0` supplies the same stage arithmetic.

Introducing its byte-parameter prototype exposed a redundant mask in caller
`func_84131760`. Passing `t` directly delegates the byte conversion to that
prototype and restores the caller's 352-byte size. Without that companion
edit, the caller grew by four bytes and shifted later jump-table entries.
Both functions and the caller edit passed the native runner's full US-ROM
comparison and normal host syntax checks. Naming retained original-address
aliases and passed normal plus 20-leading-blank whole-module controls.
