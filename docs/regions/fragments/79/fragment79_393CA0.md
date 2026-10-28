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
