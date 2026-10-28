# Fragment 14 selection frame/control

## 2026-10-15 — resource preloader accepted; control-family requeues

One of four investigated owners is accepted; the file advances from **3 C /
6 ASM** to **4 C / 5 ASM**. Publish the verified partial result rather than
holding it behind the remaining control functions. The two larger asset/entry
owners have not been probed in this block. This is not file completion.

### `func_81302920` — `Fragment14_PreloadSelectionResource`

Normal native runner acceptance: batch `8527c799db244de9ad63038ea62abb66`,
label `f14-control:messages:u16-True:outer-switch-True:inner-switch-True`.
**52 instructions / 208 bytes**, frame **0x20**, `link_verified: true` and a
successful combined full-ROM gate. Stock IDO 7.1; no compiler override.

- Read the default unsigned resource ID from metadata offset 0x3A. Type 6
  selects 0x1A/0x1B/0xD for controller modes 0/1/2, leaving unknown modes
  unchanged. Type 0xE selects 0x17. The high flags byte overrides with 0xE
  for 0x400 and 0x2E for 0x500.
- Keep both selection levels and the final override as ordinary switches.
  If chains change branches and dead switch-tail instructions. The real
  `u16` resource carrier reproduces its halfword spill at stack+0x1E; a word
  local instead emits two different spill instructions.
- `func_8004D690` calls the cached archive loader `func_8004C3EC` for the
  archive at context+0xC. The name deliberately says resource, not music or
  a specific message format. Preserve the unused return value.
- Apply a behavior-backed name and US compatibility alias; retain the
  address-keyed symbol and do not rename JP entries.

### Verification

- Forced native baseline full-ROM build before experiments: PASS.
- Normal link-verified runner gate: PASS. Statistics and host checks enabled.
- Fresh and twenty-leading-blank whole-TU builds after formatting, duplicate
  extern cleanup and naming: identical section bytes to the frozen accepted
  object; original section layouts, all nine function offsets/sizes, the
  accepted span and eight untouched C/ASM spans preserved.
- Forced normal final-source ROM rebuild: byte-identical retail ROM,
  MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
- Whole-TU host syntax check: PASS. Public tooling tests: 22 PASS.
- Publish only accepted C, aliases and region notes. All candidate generators,
  runner copies, compiler diagnostics, assembly, objects and ROMs stay local.
  Work is solo/native, without agents or containers.

### `func_81302438` — requeue, shared large-offset address base

Twenty-four candidates cover inline/cached typed tail views, full-record
views, actual array-of-record declarations, direct globals, split pointer
offsets and early-return versus if/else topology. Best raw similarity is
0.6667 (normalized 0.7895), 204 versus 228 bytes. A typical first difference
is the cached base's `lui` immediate; the candidate folds the large field
offset into that base and omits the repeated target `addiu ...,0x7FFF`.
Cached pointer forms also change the frame to 0x20 versus target 0x28.
No candidate or companion declaration edit is installed.

The record-array companion initially failed preflight because its old text
did not include the named existing function; the corrected transaction was
tested normally. That refusal is not a source-shape rejection.

Next: isolate ownership of the large-offset address folding before another
body rewrite. Test a minimal access fixture against a solved sibling; preserve
the three visibility tests, six background reloads and all five rectangle
arguments. Do not manufacture an address dependency or force a register.

### `func_81302854` — requeue, same large-offset context access

Eight inline/cached pointer, root/tail-base and while/do variants reach at
best 0.8824 normalized / 0.7647 raw, 188 versus 204 bytes. Four context loads
lose the same separate address additions as the overlay owner. Preserve the
zero initial phase, optional fade setup, full nine-call frame sequence and
phase-4 termination. Resolve the shared address mechanism first, then retry
against the cumulative accepted source. No body is installed.

### `func_813026D0` — requeue, return topology and countdown accesses

Twenty-four candidates cover incoming/reused versus separate word carriers,
immediate versus common returns, ternary exit selection, split cancellation
returns, explicit expired predicates, and scalar/one-element-array/record
views of the existing countdown word. The best equal-size leader is 388/388
bytes, 0.9072 normalized / 0.7732 raw. A higher normalized 0.9091 candidate
is 396 bytes and only 0.7172 raw: do not prefer it on normalized score alone.

The equal-size leader still materializes the countdown address across stores
and decrement, unlike the target's independent symbolic accesses, and changes
branch distances. Preserve signed post-decrement semantics, both exit paths,
their side-effect ordering and unknown incoming phases. No speculative narrow
phase or countdown declaration is installed. Next: inspect the address-CSE
and decrement-expression boundary with the 388-byte leader, not another
unsigned/array spelling sweep.

### Toolchain diagnostics are not accepted changes

A diagnostic stock IDO 5.3 compile did not fix the overlay address shape or
the controller leader. An `-O1` overlay probe does emit the split address,
but is 276 bytes and a whole-TU control breaks three of four known C matches.
This does not justify changing the file's compiler or optimization level.
Keep stock IDO 7.1 / `-O2`; these are bounded observations, not proof that a
source shape is unreachable.

## 2026-10-28 — `func_81302854`, `func_81302438` matched; `func_8130251C` requeue

`D_81327800` is the fragment's work area. Retail reaches its pointers at 0xA170/0xA174 (elsewhere read as `D_81331970`/`D_81331974`) through the struct base: `lui D_81327800` + `0x7FFF`/`0x8000` large-offset splits. They are therefore fields of a typed `extern unk_D_81327800 D_81327800`, not separate externs.
- `func_81302854` is the screen's main loop:
  - an optional fade-in first;
  - each frame: `func_80064D28`, `func_816018CC(1)`, `func_81600954`/`func_81302390`/`func_8170024C`/`func_8130209C`/`func_81600B30` on the work pointer, then `func_81302634`;
  - `state = func_813026D0(state)` until it returns 4.
  It has no `return`, so it is `void`, along with the file's forward declaration.
- `func_81302438` is the overlay-draw twin of `func_81302390`: it calls `func_81600F0C` for regions +0/+2/+1 of the 0xA170 pointer when `func_81600DA8` says each is visible, plus `func_81700908`.
- `func_8130251C` (requeue) is the init:
  - set `+0x904 + 12 * i` of the 0xA17C record to `D_813122A0` for i < 4 (a `for` loop gives retail's shared `+0x8000` base);
  - `+0xA180 = BinArchive_Open(func_800356CC(11), 0, 1, 0)`, then `+0xA178 = func_80071B20(+0xA180, func_80071914(rec->+0x940))`;
  - allocate the work buffer into +0xA174 with `func_81600E28(pool, 1, 0x1C)`, then `func_81300830(D_81317800, +0xA178, +0xA17C, +0xA170)` and `func_800355E4(0x1B)`.
  Locals `i`, `size`, `pool` fix the frame. The remaining 6 ops are the unrolled loop's load order (retail reads the record pointer, then the value; IDO reads the value first after iteration 1).
