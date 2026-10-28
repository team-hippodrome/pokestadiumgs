# Region notes — src/fragments/64/fragment64_32C420.c

## 2026-10-28 — matching counter update accepted

`func_87F097B0` is genuine C: 48 instructions / 192 bytes, frame 0x10.
Canonical candidate `counter:equivalent-high-bit-predicate:3` is accepted
through the syntax-enabled full retail ROM gate, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Private receipt:
`scratch/parent64-counter-flags/gate-0/receipt.json` in the parent native
integration checkout. No permuter output was admitted.

Four 0x6C0-byte model spans supply the selected object's byte at +4.
The 18-entry ID map is `D_87F113D0`; its selected byte counter belongs to
one of four 24-byte rows beginning at +0x2194. Each row's state halfword
is at +0x12. A set high bit enables the saturating increment.
The typed spans recover shift/add indexing where raw numeric pointer
multiplication had retained multiply instructions and saved constants.

Ordinary for-loop induction and declaration order row/index/counter/value/
cursor recover the original frame and pointer home. The remaining opcode-
exact candidate still starts its temporary ring one register early. Writing
`(*(u16 *)(cursor + 0x21A6) >> 15) != 0`, the direct high-bit condition,
closes that allocation difference without extra locals or output changes.
All retained locals are consumed. Initial lookup failure leaves the carried
counter pointer unspecified exactly as in retail; no defensive reset is
introduced. Integer-width/declaration variants and their failures remain
in the canonical ledger and private captures.

Post-acceptance cleanup removes an unused type-only whole-context view and
uses fragment-specific names for the two observed spans. Normal and +20blank
whole-module controls preserve every allocated byte, extent and relocation.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_87F097B0` → `Fragment64_IncrementMatchingCounters`.

## 2026-10-28 — motion owner progression (resolved below)

`func_87F098F4` remains `requeue`, not installed. Target: 162 instructions /
648 bytes, frame 0x18. Best canonical candidate is
`scratch/parent64-motion-counts.json`, index 0: 648 bytes, frame 0x18,
normalized 0.9815 / raw 0.7963. Normal/+20blank whole-module controls pass.

The 28-byte state has mode at +0, X/Y/width/velocity floats at +4/+8/+C/+10,
packed color at +0x14 (alpha byte +0x17), and frame at +0x18. The existing
initializer proves the extent. Its sound call is the one-argument
`Audio_PlayDefaultSound(u16)` (`func_800279C4` compatibility alias), verified
at `src/229E0.c`; the M2C-suggested second argument was only a live pointer.

An ordinary five-case switch emits a new jump table absent from retail.
An early inactive-state return followed by a sparse switch recovers the
linear dispatcher without a layout edit. Distinct old/new frame snapshots
then recover the two counter updates. The initial sparse-switch source
lowered alpha division by eight to a
reciprocal multiply. Integer-divisor spelling restores the actual divide
and unsigned-byte conversion. The counter-lifetime frontier still placed
its increment/store before geometry. Moving both after the width calculation
produces the complete opcode sequence: 648 bytes, frame 0x18, normalized 1.0 /
raw 0.7963. Only register allocation differs. Latest source:
`scratch/parent64-motion-geometry-counts.json`, index 0. Stock IDO 5.3 and 7.1 produce
identical candidate bytes and preserve the known module text and section
layout; there is no current
compiler-lineage evidence for the residual.

Next: trace consumed frame-assignment result and temporary-register webs
with a calibrated stock compiler pass observer.
Do not fabricate occupancy, ABI hints, dead guards, padding or output patches.
Private canonical manifests/results retain all source variants and diagnostics.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_87F098F4` → `Fragment64_AdvancePanelAnimation`.

## 2026-10-28 — motion owner accepted

`func_87F098F4` → `Fragment64_AdvancePanelAnimation`: 648 bytes / 162
instructions, frame 0x18. Canonical batch
`parent64-motion-both-fields`, label
`motion:both-frame-fields:direct0-tail0`, accepted through the sequential
full-ROM gate. The initial relocation-only probe difference was not used
as proof: the retail ROM comparison passed with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Explicit host syntax checking also passed.

The resolving source shape increments and tests the actual frame field in
both the expansion and fade states. Cached old frames remain consumed by
the angle/alpha calculations; no next-frame local, unused assignment, ABI
hint, output rewrite, or padding is required. The real one-argument
`Audio_PlayDefaultSound(u16)` declaration also replaces the stale s32
prototype for the whole module. Integer `/ 8` retains the retail floating
division. Normal and +20blank whole-module naming/extern cleanup controls
preserve all allocated bytes, function extents and relocation topology
modulo the reviewed compatibility alias. Stock IDO 7.1, unchanged flags.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_87F0A3E8` → `Fragment64_UpdateBounceAndConfirm`.
- `func_87F09B7C` → `Fragment64_DrawExpandingPanel`.

## 2026-10-28 — bounce, confirmation, and panel rendering accepted

`func_87F0A3E8` → `Fragment64_UpdateBounceAndConfirm` matches 468 bytes /
117 instructions through canonical batch `parent64-bounce-stack`, label
`bounce:memory-velocity:decl-order4`. The initial opcode-exact candidate's
extra velocity snapshot shifted the three retained locals' stack slots.
Reading velocity directly from the state and declaring panel, result, then
buttons recovers the retail frame and offsets. The resulting source has
three consumed locals and no extra occupancy assignments.

The initializer `func_87F09EBC` establishes the model pointer at +0x24,
vertical position/velocity at +0x28/+0x2C, counters at +0x30/+0x34, flags at
+0x38, embedded panel at +0x3C, and input state at +0x58. The updater applies
a downward acceleration scaled by `func_80001FF0`'s TV-dependent 50/60 Hz
return, rebounds at zero, writes the model's +0xA halfword with signed
rounding, and accepts the 0x8000 input after a 60-frame minimum wait.
`func_87F0E610` and `func_87F0E524` in `src/fragments/64/fragment64_331000.c`
show that their existing pointer-typed second argument is compared as an
integer timeout; the call retains an explicit conversion to that interface.

`func_87F09B7C` → `Fragment64_DrawExpandingPanel` matches 832 bytes / 208
instructions through canonical batch `parent64-panel-draw-channels`, label
`panel-draw:named-channels:add1:pack0`. Resource 444 supplies the texture's
width/height halfwords. Two textured rectangles stretch and mirror its
edges using the panel X/Y/width, followed by resource 445 at (70, 115).
The second draw separately rounds X and width before summing them.
Independent coordinate expressions recover the register roles that reused
integer locals had tied together. Named RGBA byte members recover the
primitive-color command's load schedule with the standard SDK macro.
The combine command passes texture color and multiplies texture alpha by
primitive alpha in both cycles; its SDK LERP operands reproduce the decoded
RDP command. Real graphics signatures are verified in `src/44E70.c` and
`src/4CC20.c`.

Both canonical gates reproduce retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d` with explicit host syntax checks.
Post-acceptance naming, duplicate-extern cleanup, shared named-color state,
and formatting preserve complete-module allocated bytes, extents and
relocations, normally and with twenty leading blank lines. The previous
animation uses the same color byte at +0x17 after consolidation.

Remaining owner `func_87F0A098` is `layout-prerequisite`: its five-entry
`jtbl_87F116A8` remains in shared `asm/us/data/334310.rodata.s`, and this
source has no per-file .rodata subsegment. The table and neighboring float
constants occupy 0x334310 through 0x334333, followed by alignment to
0x334340. Next: assign that verified range to this source, re-extract and
gate the still-assembly owner before trying its C switch. A private M2C
draft with the actual table confirms its case structure; no C candidate
has been admitted for that owner.
