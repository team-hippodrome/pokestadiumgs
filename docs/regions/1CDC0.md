# Region notes: 1CDC0

## 2026-10-14: func_8001CDE4 remains unmatched

One US/default-host-syntax ROM failure. Actual one-pointer void owner and canonical void func_8001A994(void*) helper/caller audited. Typed record with flag word at 0, byte 0x30, pointer 0x3C and backlink 0x48 preserves all 35 instructions, frame 0x18 and branch/call/store topology. The shifted flag uses t7 instead of retail t8, backlink t8 instead of t9, and final byte/update t9/t0 instead of t1/t2. No false return or unused arguments were introduced. A supported flag/temporary allocation model is required; no ordinary guard, typed record or mask-spelling retries.

History audit: No exact owner attempt. func_8001CCC8 history only references this helper; that is not an owner attempt. The 1CDC0 region records terminal F9B0 exact-size register drift after 10 new and 61 prior attempts (raw score not supplied in that regional paragraph; now merged through another agent) and accepted DE58 normalized 1/raw None; neither was retried.

All failed sources, full build logs, and object disassemblies are retained in
`work/session-44`; each fresh baseline was restored. Open PR scopes were
checked for duplicate owner work. No CI, verification, linker, or data changes
were made. These attempts are failures, not claimed matches. The restored
186-owner workspace passes the US retail checksum with default host syntax
checks. Unknown tokens retain their existing address/offset names.

## 2026-10-28 — `func_8001CE70` matched

Ocarina of Time `AudioSeq_SeqLayerProcessScriptStep5`, without the synthetic-wave reinit. The layer flags are OoT's `u32` bitfields (`continuousNotes`, `bit3`, `bit1` in word 0), the note is at 0x3C and its parent layer at note + 0x44. Two spelling details:
- Use `arg0` directly with casts instead of a typed local, so retail spills it to its home slot around calls (a 0x18 frame, no `$s0`).
- Write `sameSound == 1U`: an unsigned compare reuses the `1` already loaded for the bitfield tests. The permuter found it.
