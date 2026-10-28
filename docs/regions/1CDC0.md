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

## 2026-10-28 — `func_8001FA80`: requeue (layout findings)

requeue. GS's `AudioSeq_InitSequencePlayers`. Audio-context layout it establishes:
- five 0x160-byte sequence players pooled at context + 0x346C (`D_8011F2FC`), ending exactly at the layers;
- 64 0x90-byte layers at + 0x3B4C, with the enable bit 7 of byte 0 and `channel` at + 0x60;
- a pointer table `seqPlayers[5]` at + 0x604C;
- an extra player at + 0x60B4 (`D_80121F44`) and its single extra channel at + 0x6214 (`D_801220A4`). The channel's `seqPlayer` is at + 0x50 (`D_801220F4`), and the six words at + 0x54 are zeroed by a copt-peeled loop.

The body:
- `AudioLayerPool_Init`; clear each layer's channel and enable bit;
- set and init the 5 player slots;
- init the extra player; link and disable the channel; zero `unk_54[6]`; `func_8001C404(channel)`;
- player `channels[0] = channel`, bytes 4/5 = 0xFF, + 0x18 and + 0x78 = `D_8008F988`, + 0x90 = 0, + 0x10 = 0, + 0xDC = 0, enabled = 1, finished = 0.

Best 0.75. Two problems remain:
- Retail ends the slot loop with `bne` on the pointer-table induction (`D_8011BE90 + 4i` against `D_8011BEA4`); IDO picks the pool pointer and `sltu`.
- Retail forms every extra-player field address with its own `lui $at`, while IDO keeps `&player` in `$s0` once it is passed to `func_8001F9B0`. Routing everything through a context view makes it worse (0.73).
Next: test an `extern` context *struct* (not the cast `u8[]`) in a scratch file, and an index loop whose body uses only `seqPlayers[i]`.

## 2026-10-28 — `SequenceLayer` flags are `u32` bitfields

`func_8001CE70` now takes the file's real `SequenceLayer *` instead of an ad-hoc view. Retail loads the layer flags with `lw`, so the leading bitfields are declared in a `u32` unit (they were `u8`). Every other user of the type stays byte-identical. The `SequencePlayer`/`SequenceChannel`/`SequenceLayer` typedef block is moved above `func_8001CE70` (declarations only), and its caller casts to `struct SequenceLayer *`.
