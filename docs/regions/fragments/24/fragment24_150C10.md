# Region notes -- src/fragments/24/fragment24_150C10.c

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

func_82B0373C: plateau at 0.9479 (raw 0.7917), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool no


## 2026-09-17

func_82B025E0: time cap at 0.9848 (raw 0.803) after 2400s, mismatch operand_or_scheduling_drift; tried families: state_field_access; tie-pool yes

## 2026-09-17

func_82B041C8: matched (call_chain:macros:ternary-alpha-exact), 1 iterations, agent codex

## 2026-09-29

func_82B01F14: time cap at 0.0 (raw None) after 2400s, mismatch unknown; tried families: (none); tie-pool no

## 2026-09-29

func_82B025E0: time cap at 0.0 (raw None) after 2401s, mismatch unknown; tried families: (none); tie-pool no

## 2026-09-29

func_82B01BB8: matched (packed:interleaved:exact-copy-before-second-negations), 1 iterations, agent codex

## 2026-09-29

func_82B01CE0: matched (state:permuter:exact-pointer-handoff), 3 iterations, agent codex

## 2026-09-30

func_82B0341C: matched (call_sequence:array_layout:exact_match), 1 iterations, agent codex

## 2026-09-30

func_82B05F60: time cap at 0.925 (raw 0.7625) after 2420s, mismatch instruction_drift; tried families: call_sequence; tie-pool no

## 2026-10-27 — `func_82B029B8`: matched

Entry in state 2 → state 3, `+0x08 = 0`; for `arg1 >= 0` copy the `+0x10` pair to `+0x40` and `D_82B085DC` to `+0x44`, otherwise shift `+0x40` into `+0x44` and copy `+0x10` into `+0x40`. Written with the file's `Pair02198` struct copies.

## 2026-10-27 — `func_82B02800`: matched

Searches `D_82B126A8` (20 records of 0x70 bytes, typed `unk_D_82B126A8`) for the one whose `unk_00`/`unk_02` halfwords equal `(arg0, arg1)`. Declaring `count = 20`, `i`, `entry`, then `result = NULL` (in that order), walking `entry = D_82B126A8` with `i++, entry++` and nested `if`s that `break` with `result = entry` gives retail's rolled loop and its `a2`/`a3` assignment. Returns `void *` to agree with the file's existing prototypes.

## 2026-10-27 — `func_82B055A0`: requeue

requeue. Copies halfwords 4/6/8 of the record at `D_82B12450 + 0x254` into `+0x0E/+0x10/+0x12`, clears `+0x0C`, sets `D_82B12466`, `D_82B12464`, `D_82B12468`, `D_82B1246A` to 1, and calls `func_82B0556C`. Retail shares one `lui $at` for the (66, 64) pair and another for (68, 6A, in the call's delay slot), and loads each `1` into its own register (`t9`, `t0`, `t1`, `t2`), whereas IDO folds them into one register. Needs a `COALESCE_AT_LUI` symbol-list run per pair, plus a source shape that keeps four separate constants.

## 2026-10-28 — `func_82B03688` matched (option list text)

Fetch the panel position into `s16 coords[8]` with `func_82B0284C`, set the
text color/mode, then draw each entry of the `-1`-terminated `D_82B08630`
list with `func_8004C874(0x1B, id)` at `(x + 0x31, y + row + 9)`, rows 0x18
apart. Locals must be declared `i, y, coords[8]`: that order puts `coords`
at sp+0x30 in the 0x48 frame. An indexed loop with a separate `y` counter
matches; a pointer walk does not. The dispatcher `func_82B05494` used to
call it with no arguments and rely on `a0`; it now passes `arg0` (same
bytes), and the stale `(void)` extern is retyped.

## 2026-10-28 — `func_82B03F38`: requeue (loop-invariant address not hoisted)

Sibling of `func_82B03688` (same `func_82B0284C`/`func_800496A4` setup): four
rows, color (255,255,255,255) or (255,255,0,255) for the selected row
`i == D_82B1246C`, text `func_8004C874(0x1B, i + 0x22)` at
`(coords[0] + 9, coords[1] + y + 0xB)`, rows 0x1A apart. The dispatcher
`func_82B05494` must pass `arg0` as for 03688. With locals
`i, coords[8], y` everything lines up except that IDO 7.1 (and 5.3) hoist
`&D_82B1246C` into an extra saved register (`$s2`) outside the loop, while
retail re-forms it with `lui` + `lh %lo` every iteration and uses only
`$s0`–`$s2` (i, y, 4). `volatile`, s32, and an array form don't change it.
This is the same "uncached global address" behavior as `func_800258F4` and
`func_8220D630`.

## 2026-10-29: `func_82B07960` tooling-blocked

tooling-blocked (uncached globals, 0.70). B-button handler:
- plays sound 5 once when D_82B12456 is first set;
- on B: `switch (D_82B13008)`: case 0 resets D_82B12450 = 9, D_82B12456 = 0, D_82B1245A = -1; case 1 calls func_82B02A34 on each `(void **)(&D_82B12450 + 0xB18)[i]` for `i < *(s16 *)(&D_82B12450 + 0x250)`, then func_82B060A0(1);
- then plays sound 3.

The file's `extern void func_800226C0(void)` must become `()`. Retail re-forms every scalar global's address with `lui $at` while keeping a separate $s2 = &D_82B12450 for the loop. Our compile caches D_82B12456's address in an s-register. Same shape as func_87E07CD0.

## 2026-10-29 — `func_82B07E18`: genuine native C match

On base `d06e6d3c`, canonical batch `scratch/e18-b1.json` accepted
`fade:image-header:decl-order-0`. The renderer fetches archive entry 333/0,
updates the signed halfword alpha `D_82B1269C` toward 255 or 0 in steps of
25 according to `D_82B12454 & 2`, optionally sets the backing rectangle,
and draws the image at (328, 199) with environment color (255, 255, 50, alpha).
The first two unsigned halfwords of the image are width and height, as also
read by `func_8004CA10`/`func_8004CA24` in `src/4CC20.c`.

Locals declared `s16 alpha; u16 *image; s32 x;` preserve the 40-byte frame
and image spill at sp+32. Reordering them can retain the opcode shape while
moving that spill to sp+36 or increasing the frame to 48 bytes. All three
locals carry values used by the renderer; no artificial stack storage or
instruction rewriting is involved. The native IDO 7.1 compiler SHA256 is
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.
Normal and +20blank whole-module controls both reproduced sections, bytes,
function extents, and relocations. Explicit host syntax passed, followed by
the full retail ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
The private receipt and sealed artifacts are in
`scratch/e18-b1/gate-0/receipt.json`. Upstream `7a127bb6` still owns the
assembly pragma for this function.


## 2026-10-29 — `func_82B02334`: genuine native C match

Canonical batch `scratch/2334-b3.json` accepted
`panel:color-pointer-lifetimes:post-4` on top of renderer commit `734db747`.
This initializes the alternating-column panel: size 515 by 106, position
(64, 87) with delta (640, 0) for even `unk_02`, or position (64, 239) with
delta (-640, 0) for odd `unk_02`. The RGB source is `D_82B085C0` or
`D_82B085C4`, respectively. It copies the initial and opposite coordinate
pairs into the four-element trail arrays, then adjusts the second trail
pair in each array.

Typed `Pair02198` cursors for the initial and opposite pairs reproduce the
first 37 instruction words. Using the existing `State02198` fields for the
post-loop edits ends those cursor lifetimes; explicit RGB-source pointers
initialized before the field stores reproduce the remaining address setup
and scheduling. A genuine four-iteration loop is compiled to the retail
copy sequence. There are no dummy locals, manual unrolls, owner instruction
rewrites, or register bindings. The complete function is 384 bytes with no
stack frame; function bytes and link shape both compare exactly against the
unchanged assembly control object.

The normal and +20blank whole-module controls passed. Explicit host syntax
and the full retail ROM gate passed with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, using the same unmodified native IDO 7.1
compiler recorded for `func_82B07E18`. Sealed evidence is in
`scratch/2334-b3/gate-0/receipt.json`; the independent object diagnostic is
`scratch/2334-b3/pending-object-diagnostic.json` (recorded before the ROM
gate completed). Earlier struct-only forms had the correct 384-byte size
but differed in pointer allocation and load scheduling; raw offset views
alone were 392 bytes. This is an accepted source spelling, not an inference
that the original source used the same field names.

## 2026-10-29 — `func_82B05F60`: register-tie requeue

requeue / register-tie. The first native working block retained the assembly
owner. Best candidate: `scratch/5f60-b5-new.json`, index 0,
`mode:full-increment-then-narrow-test:store-1`. Expected and actual sizes
are 320 bytes with a 40-byte frame, all opcode positions and branches agree,
normalized similarity is 1.0, and raw object similarity is 0.85. Raw offset
94 is a relocation-addend difference (`D_82B126A2` versus context + 0x252),
not the operative residual.

A GNU ld diagnostic linked the unchanged assembly control object and the
retained candidate against the last sealed retail ELF's symbol addresses.
It finds nine differing words, all register choices: offsets 204, 224,
236, 240, 244, 248, 252, 268, and 280. Retail's count update uses `t2`
(load), `t3` (32-bit increment and halfword store), `t4`/`t5` (signed
halfword test); C colors the value in `v1` throughout. The later count
reload and comparison use `t6` in retail and `t2` in C. The diagnostic is
`scratch/5f60-linked/diagnostic.json`; it is not acceptance evidence.

Attempted families: pointer-walk versus indexed panel lists; named versus
base-field count accesses; guarded do/while versus for/while first tests;
preincrement, assignment-result, signed temporary, and full-width increment
with a narrow predicate; separate counter-store and loop statements; and a
local typed view of the complete 0xFF8-byte context. The context size comes
from `func_82B05654`'s `_bzero`; `func_82B05920` initializes the 20 records
at +0x258 and fills the list at +0xB68 using the halfword at +0x252.
The coherent context view produces 312 bytes and merges count reads; it
does not resolve the allocation tie. No shared type or storage declarations
were changed. Actual `func_81700B8C(s32, s32)` and
`func_81700CDC(s32)` return `s32`, as defined in fragment 18.

Each compiled batch passed unchanged-module and +20blank controls. Two b2
variants had a generated postincrement precedence error, corrected in b3;
these are syntax failures, not negative source-shape evidence. b5 preflight
refused one already-rejected body before compilation; it was removed and
seven distinct candidates ran as b5-new. No history guard was bypassed.

Next action: test an explicit lookup-result lifetime before loading the
array insertion index, preserving the measured call/load order; if it does
not change the counter web, obtain compiler allocation evidence before
expanding this source family. Do not install the best candidate or treat
the allocation residual as proof that genuine C is unreachable. At this
handoff the tracked C still equals the source sealed for `func_82B02334`.

## 2026-10-29 — `func_82B072DC`: input-access requeue

requeue. Retail has 376 bytes and a 32-byte frame. Best normalized candidate
is `scratch/72dc-b3.json`, index 1: similarity 0.8404, raw 0.5851, 352 bytes.
The best raw candidate is `scratch/72dc-b5.json`, index 1: raw 0.6277,
normalized 0.7766, 360 bytes. Neither is installed.

The handler snapshots the halfword at context +0x1C, gates on
`func_82B02870`, clamps the selection to 0..3 using repeat bits 0x800/0x400,
and dispatches confirmation/cancellation using pressed bits 0x8000/0x4000.
Retail keeps the address of the active-controller slot in v1 and reloads the
controller pointer around the selection writes. Ordinary typed and raw
halfword source forms cache either that controller pointer or a selection
address, leaving shorter code. A pressed-mask snapshot declared before the
previous selection reproduces the first six instruction words, including
the previous-selection spill at sp+24; this does not settle the remaining
load and address lifetimes.

Measured families: prefix and standalone updates; two signed update values
from the assembly-only m2c draft; an explicit signed current-selection value;
pressed-mask snapshots and declaration order; early-return versus nested
control flow; typed controller fields versus byte/halfword views; selection
symbol reads versus observed context-field writes; and a live pointer to the
active-controller slot. A nearby accepted pointer-alias spelling in
`src/fragments/20/fragment20_1286C0.c` is explicitly marked FAKE and is not an
admissible transfer proof.

A further atomic context-type experiment modeled the producer's full
0xFF8-byte object instead of the file's scalar root declaration. Eleven
owned C/data companion blocks preserved existing halfword strides and all
assembly owners. It produced only 348/352-byte input candidates, and
288/292-byte `func_82B05F60` candidates; correct root extent alone does not
explain the retail code shape. Nothing from this experiment was installed.
The retained manifests and preview are
`scratch/72dc-context-type-fixeddecls.json`,
`scratch/5f60-context-type.json`, and
`scratch/context-type-companions-preview.c`.

The sound helper takes the ID in a0: the undecompiled `func_800226C0`
stores it at entry. The file's `(void)` prototype and argument-free call in
`func_82B00E34` were tested as one exact companion context changing the
prototype to `(s32)` and passing `arg0`. The 112-byte accepted caller stays
instruction-byte identical in the retained probe object; the companion is
not installed because no input-handler candidate passed. See
`scratch/72dc-b1-context/sound-companion-diagnostic.json`.

Tool diagnostics: the signature scanner missed the sound prototype after a
marker comment, so the valid edit used the enclosing accepted caller and its
adjacent declaration as one exact anchor. Data-declaration synthesis uses
the baseline before companion retypes; the context experiment therefore
needed an explicit `extern Context24 D_82B12450` shared declaration to
suppress the stale scalar declaration. Seven initial conflicting-declaration
failures are setup evidence, not C-shape failures. The context-based m2c
draft returned empty errors; `--no-context` succeeded. All compiled batches
passed normal/+20blank module controls; no history or ownership guard was
bypassed.

Next action: obtain source/frontend alias-class evidence for the controller
and signed-selection accesses before replaying these spellings. No claim
of source unreachability is supported by this bounded search. The tracked C
still equals the source sealed for the accepted `func_82B02334` batch.


## 2026-10-29 — `func_82B0128C`: genuine native team-rule validation match

Accepted `scratch/128c-b12.json`, candidate 0,
`rules:matching-frame:minima-declaration-0`. The full 1200-byte function and
152-byte frame match the unchanged assembly object and its link shape.
Normal and +20blank whole-module sections/bytes/function extents/relocation
controls PASS; explicit normal host syntax and authoritative native retail
ROM gate PASS. Sealed receipt: `scratch/128c-b12/gate-0/receipt.json`, source
SHA256 `fbb8db1d524a47d03973bf2795b8531c5ef5aa25c9671c49d356abc6c3c60fbf`,
retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`; unmodified native IDO 7.1
SHA256 `975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.

This checks each 88-byte record against species, level, duplicate-species,
and enabled duplicate-item rules, optionally writes per-record flags, then
checks the sum of the three lowest levels if the records passed. Actual
callee definitions were inspected in `src/728D0.c`, `src/71E10.c`,
`src/fragments/11/fragment11_D9520.c`, and the accepted same-file level-bound
helper. The record producer `func_80071E48` clears 0x58 bytes and writes
species/item at 0/1, level at 0x1D, and word/halfword statistics at 8..0x16.
The six helper declarations use actual definitions, including
`func_81601EAC(u8,u8)` and `func_80071CD0(s32,s32)`.

Winning source mechanisms: a real bitfield view of rule word bit 26 gives
retail's shift-and-sign test; computing the current record pointer inside
the rolled level scan causes native IDO to produce the retail four-record
unroll automatically. Both the array initializer and record loop stay
rolled in C. A separate item-duplicate index and named species/item values
serve their real tests and calls; the total-level arithmetic and final
status accumulator are used by the rule call and return. A word-sized team
status, halfword species index, byte item, and declaration of the result
after `lowest[3]` give the exact frame and array position. The ascending
three-term sum gives the expected load order.

Earlier direct record indexing produced only 956/960 bytes and a two-way
compiler unroll. After the rolled record pointer unlocked 1200 bytes,
`128c-b8` reached all 300 normalized opcodes. Actual GNU ld inspection of
`128c-b10` candidate 0 found 73 differences, all an eight-byte stack shift;
`128c-b11` candidate 1 matched the frame and left 55 references to the
minimum-level array shifted by four bytes. Moving the used result
accumulator after the array closed that residual. These are source-shape
experiments, not additional owners. No manual unrolling, filler locals,
forced registers, fake ABI, instruction rewriting, coalescing, shared
header/layout/alias changes, or compiler modifications were used.


## 2026-10-29 — `func_82B03538`: genuine native panel text match

Accepted `scratch/3538-b3.json` candidate 6,
`panel-text:retail-table-base-lifetimes:mode-6`: all 336 bytes and the
80-byte frame match, with exact link shape. Normal and +20blank whole-module
controls, explicit normal host syntax, and the authoritative native retail
ROM gate PASS. Receipt: `scratch/3538-b3/gate-0/receipt.json`, retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, unmodified native IDO 7.1 compiler hash
as recorded in the preceding accept. Both this C owner and its companion
changes were installed by the canonical runner, not by manual source edits.

The panel draws its animated graphic with `func_82B0341C`, an optional
heading from `D_82B08610`, then the two nonnegative entries of the selected
row of `D_82B0861C`, advancing the vertical text position by 23 per entry.
The data contains five two-halfword rows; heading IDs are 6, 7, 8, -1, -1.
`func_82B0284C` writes exactly two halfwords. The new function uses the
existing genuine four-byte `Pair02198`, without the unsupported coordinate
array extent seen in some older sibling bodies. Locals in the winning order
are `i`, `y`, `heading`, `entries`, `coords`, `id`, `text`. The heading and
flat entry-table pointers model the actual saved-register address lifetimes
and are used by their real lookups. With implicit global bases the complete
84-opcode shape already matched but the frame was 72 bytes and eight
register uses differed; explicit bases close both residuals. Changing only
message-ID width or replacing the pair by a two-halfword array did not.

Actual definitions at `src/4CC20.c:262` and `src/47580.c:1340` require
`void *func_8004C874(s32,s32)` and
`void func_800495F8(s32,s32,s32,const char *,...)`. All six old duplicates
of each declaration in the owned file are retyped consistently by companion
edits. The dispatcher `func_82B05494` now takes the real second `s32`
animation argument and forwards `(arg0,arg1)` to this owner. The assembly
caller `func_82B080D0` explicitly supplies both at 0x82B08424/28. Its old
no-argument call depended on live ABI registers. The accepted full ROM gate
covers these corrections and all pre-existing C neighbors. No shared
header, aliases, layouts, instructions, or compiler code was changed.

Preflight initially did not recognize `func_82B0201C` as a companion target
near a preceding comment containing function names. Anchoring that exact
prototype correction to the existing `func_8004C874` prototype passed the
canonical validator; no guard or runner modification was made. Retained
linked ten-word negative diagnostic: `scratch/3538-b1/linked-2/diagnostic.json`.


## 2026-10-29 — `func_82B01904`: genuine cup-panel initializer accepted

accepted. Canonical `scratch/1904-b5.json` index0,
`init:real-fade-substate-pointer:lifetime-0`, replaces only01904's ASM owner.
It is novel against origin/master `c3a17b2fd78e1e06b9d13eed21c9838cf47e6653` checked at sealing. Retail692 bytes,
frame80. Normal/+20blank whole-module sections, bytes, extents and relocations
PASS, explicit normal host syntax PASS, authoritative serialized native retail
ROM gate PASS. Receipt: `scratch/1904-b5/gate-0/receipt.json`; source SHA256
`70780d4cd15f4bf6168e15e06b780e7a1d0a81c2d3343f0f61d97d56c4d0d3f4`; ROM MD5
1561c75d11cedf356a8ddb1a4a5f9d5d. Object/ELF/map/ROM/source are sealed alongside
the receipt. Probe was relocation-masked, not link-verified; the sequential
full retail gate is the acceptance evidence. No new rewrite/coalescing or
physical bindings were introduced, and production compiler/uopt hashes stay
unchanged.

Real C mechanisms: a two-element s32 coordinate array keeps both quotient
and remainder live before the rule-validation callbacks and emits the single
hardware DIV plus the actual two word spills atsp40/44. Both elements feed
panel geometry: quotient is grid row, remainder is column. There is no dummy
denominator variable. SDK div/ldiv calls were negative experiments: they emit
external calls absent from the retained ROM symbols. Plain arithmetic with
separate scalar/struct fields was sunk past callbacks and divided twice.
The explicit CUP3 case represents the no-validation table entry seen in ASM;
it preserves the five-entry jump table in the already-owned .rodata segment.
The integer division and all four Pair copies remain compiler-generated from
ordinary C operators and a rolled four-iteration loop, without manual unroll.

The two-halfword coordinate records have genuine alignment2 and size4, giving
the observed LWL/LWR/SWL/SWR copies. The last four-byte residual in b4 was the
actual fade-substate address atarg0+0x50: direct nested-member stores folded it
away. The winning live FadeHead pointer derives from the real argument using
the native32-bit pointer width and that verified field offset, then writes
active/tick through it. No absolute VM address, forced register, volatile,
unused local or extra coordinate element is used. Both coordinate entries,
the Pair source pointers and fade pointer have actual consumers.

Actual callee interfaces were used: 011C0 is s32(s32,s32), not m2c's guessed
three-argument declaration; its computed rule address is cast to u8* for
128C's real s32(s16*,s16*,u8*,s32,u8*) signature. The panel's generic void*
argument accepts the existing State02198 caller without an ABI invention.
The source-local Panel01904 view extends the proven constructor prefix through
the two fade halfwords, inside the112-byte record initialized by026E8.

Eleven canonical companions correct D_82B12450's inherited scalar declaration
to its producer-proven0xFF8-byte opaque context extent. Every existing
halfword-array stride and state scalar access is preserved using explicit
casts; all companions are in this owned source and passed the combined ROM
gate. Preserve that coherence when integrating the accepted snapshot. No
shared header, linker alias or YAML changed. The unused CellIndex01904 type
and unused SDK div/ldiv declarations came from the shared candidate context;
parent may remove them during its controlled naming/declaration cleanup with
fresh normal/+20whole-module and retail controls. They are not extra locals.

Semantic spelling clarification for earlier notes: tag0x43555030 is CUP0
(C-U-P), not CPU0; the constructor creates five cup choices. No address-keyed
function or shared symbol was renamed by this worker.

Parent integration: named the accepted entry point; normal/+20 blank-line complete-module controls preserve sections, instruction bytes, extents and relocations. Cup initializer cleanup removes the unused quotient/remainder union and unused SDK declarations. No coverage or tooling edits.
