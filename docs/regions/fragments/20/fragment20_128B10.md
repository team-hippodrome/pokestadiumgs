# Fragment 20 record-name loading

## 2026-10-23: four-slot names

`82601A84` is accepted as `RecordNames_LoadFourSlots`, 300 bytes, through
the recorded native runner and ordinary host-syntax-enabled full-ROM gate.
The four signed owner bytes select between asset group 42 entry 87 when
overriding assigned slots, and the selected 152-byte record row's name ID
minus one for unassigned slots. Each successful lookup copies exactly
12 bytes to state offset 2256 plus the slot index times 12. Other negative
owner values preserve the existing destination. No terminator or bounds
behavior is added.

The selection halfword at state offset 136 is loaded before the nullable
record-table guard, as the original branch delay slot requires. Halfword
indexing of the context selection table and a 152-byte array-element view
recover both address-add operand orders. Direct signed-slot tests recover
the original sentinel branch; the cached byte local caused one reversed
comparison. A calibrated, restricted source search found that mechanism.
Its dead local/store were removed before the clean candidate was submitted
to the recorded runner. No padding, unused local, forced register/frame,
extra argument, manual unroll, or instruction/relocation rewrite is used.

The real shared interfaces are `func_8004C874(s32, s32) -> void *` in
`src/4CC20.c` and the existing three-argument `_bcopy`. Every first gate
immediately froze source, the complete changed module, four collateral
objects, ROM/ELF/linked script, layout inputs, and assembly dependencies.
External hashes, the complete original module, and unchanged collateral
objects were checked before more compilation. The ROM MD5 remains
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The address alias preserves callers.

## 2026-10-23: two-slot record-name family

Four more owners are accepted through the recorded native runner and
ordinary host-syntax-enabled US full-ROM gate: 1296 matching bytes total.

- `82601BB0` becomes `RecordNames_FormatTwoSlots` (380 bytes). Two
  1064-byte context descriptors select between formatting one or two signed
  byte values and copying an existing record name. The mode at descriptor
  offset zero is a signed halfword; the signed bytes are at offsets two
  and three. The destination slots are 12 bytes at state offset 2256.
  `func_8004C594` supplies values and `func_8004C8A0` formats asset group
  18 entries 29 or 28; the copy fallback uses group 42. Their real
  interfaces are defined in `src/4CC20.c`. Loading selection before the
  table and using the 152-byte array view recover the record-address
  sequence. A signed state pointer with an explicit destination byte view
  recovers the three remaining address-add operand orders.
- `82601D2C` becomes `RecordNames_LoadTwoSlots` (324 bytes). The two
  direct row pointers and three profile choices are all initialized and
  used. Signed owner -1 chooses the profile indexed by the state halfword
  at offset 12; -2 preserves the destination; every other owner chooses
  the direct row for that slot. A two-case `switch`, with -1 before -2
  and default last, recovers the original allocation without a jump table
  or rodata change. Placing the three used loop locals after the two real
  arrays recovers their original stack homes. No array capacity is added.
- `82601E70` becomes `RecordNames_LoadSelectedOrDefaultSlots` (288
  bytes). The same owner cases choose a selected record or the table's
  first record for either slot. Selection uses state offset 136 and the
  context halfword map at offset 24. Independent selected/default row
  expressions avoid retaining the raw table pointer throughout the loop.
  The same two-case switch fixes the allocation class; initializing the
  default row before the state snapshot resolves the final row-register
  swap. No transient pointer-copy chain is needed.
- `82601F90` becomes `RecordText_SelectAndMeasure` (304 bytes). Each
  selected 152-byte record chooses text group `record[3] + 76`. Entry 39
  is used below the state threshold at offset 136; later rows choose from
  the three `D_82615348` entries. Successful lookups store the chosen ID
  and measured width/height as halfwords. The SDK declares `guRandom`
  as returning `int` in `lib/ultralib/include/PR/gu.h`; an explicit
  `u32` conversion before modulo three reproduces retail's unsigned
  division without changing that interface. Initializing the real index
  first and placing its declaration before the two used measurement outputs
  recover the initialization order and output homes. An opaque context
  parameter with explicit byte addressing recovers the final address add.

All four first successful gates immediately froze the source, complete
changed module, four collateral objects, ROM/ELF/linked script, layout
inputs, and original assembly dependencies. External hashes, complete
original-module equality, and unchanged collateral objects passed before
further compilation. ROM MD5 remains `1561c75d11cedf356a8ddb1a4a5f9d5d`.
Address aliases preserve existing callers. No instruction/relocation
rewrite, padding, unused local, synthetic read, forced register/frame,
fake argument/interface, or manual unroll is used.

### Resolved requeue and source-search safeguards

The earlier `82601D2C` requeue is resolved. Typed views and a unified
five-entry table had removed the spill but retained 22/23 instruction-word
differences. Calibrated logging-only allocation/frame diagnostics passed
stock/off/on/20-leading-blank whole-module controls and localized the
table-base/state competition. The decisive change was the owner switch,
which left only seven stack-home words; relocating three already-used
local declarations closed them.

A later two-array source search returned deceptively close variants.
Review rejected a last-row load from the state buffer instead of the
context table, an uninitialized state pointer, a changed captured-state
read, and a cursor reset on every iteration. Corrected forms did not retain
their apparent gains. None of those variants was installed. The accepted
matches came from the clean source families described above, not from the
invalid mutations.

## 2026-10-23: unassigned-owner text and name loading

Three additional owners (792 bytes) passed the recorded native runner and
ordinary host-syntax-enabled US full-ROM gate. A fourth function replaces
an existing public C implementation without adding decompilation coverage.

- `82601968` becomes `RecordText_CopyUnassignedEntries` (284 bytes),
  resolving the requeue above. Signed owner -1 selects six text lookups
  from entries 33 through 38 of group `row[3] + 76`. Non-null, nonempty
  results copy 12 bytes into the corresponding record. The destination
  identity `outer * 528 + inner * 88 + 196` is
  `144 + (outer * 6 + inner) * 88 + 52`: four groups of six 88-byte
  records with text at byte 52. The grid ends at 2256, where the accepted
  four-slot name loaders begin. Compile-time size checks describe this
  external state; no local array or runtime storage is added. The text's
  game-facing label is unresolved. The historical parent used an `s32`
  lookup return, while `func_8004C874` in `src/4CC20.c` returns `void *`.
  Correcting that interface alone retained five instruction differences;
  the typed grid destination closed the remaining address-expression chain.
- `82602AC0` becomes `RecordNames_LoadUnassignedFourSlots` (220 bytes).
  Each signed owner -1 loads the selected row's group-42 name into its
  12-byte slot at state offset 2256; other owners and failed lookups preserve
  their slots. The row is fixed across all four slots. Selection-before-table
  initialization, a 152-byte row view, and the signed-state/byte-destination
  distinction transfer from the accepted neighboring formatter.
- `82602CF4` becomes `RecordNames_LoadSelectedOrDefaultPair` (288 bytes).
  Its opcode shape is identical to `RecordNames_LoadSelectedOrDefaultSlots`
  at `82601E70`; transferring that accepted C body matches this distinct
  retail entry point too. Owner -1 selects the mapped row, -2 preserves
  the slot, and other owners use the table's first row. Both entry points
  remain separate definitions at their original addresses.
- `82603814` becomes `RecordOwners_AnyUnassigned` (92 bytes). The public
  implementation used an unused pointer read and four repeated tests.
  A natural four-iteration loop matches the same retail bytes; IDO performs
  the unrolling. All four owners are inspected, with result one if any is
  -1. This is source cleanup, not a newly decompiled public owner.

The first successful gates froze source, complete changed module, four
collateral objects, ROM/ELF/linked script, layout inputs, and original assembly
dependencies before further compilation. Independent external hashes,
whole-module comparisons, and collateral checks passed. ROM MD5 remains
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Address aliases preserve callers.
No instruction/relocation rewrite, padding, unused local, synthetic read,
forced register/frame, fake interface, or source-level manual unroll is used.

### Requeue: `82602FE8` descriptor validation

Retail sums signed bytes starting at descriptor offset four, using the signed
halfword at zero as its count. It then checks a halfword at
`46 + index * 88` for every index below that sum. The result starts at one
and becomes zero on any zero field; a nonpositive sum returns one. Older
manually unrolled candidates that returned zero for an empty input change
this behavior and must not be reused.

A natural pointer sum loop followed by an indexed field-check loop reaches
the original 252-byte size and near-identical opcode sequence, but remains
unmatched. Logging-only allocator diagnostics passed known-sibling and
stock/off/on/20-leading-blank complete-module controls. They identify the
count temporary taking V0 while the sum takes A1, unlike retail's count A3
and sum V0. Parameter-walk and inline-count families produced 248-byte
objects with different bulk-loop induction. A calibrated 90-second source
search improved its own score from 435 to 240 through ordinary initialization
ordering but did not match. These scores are not acceptance evidence.

Next: retain the natural 252-byte loop topology, compose the measured
initialization-order improvement with a source-lifetime change for count,
and inspect exact register/operand differences. Keep the known descriptor
dimensions (8-byte header plus twelve 88-byte entries = 1064) without
inventing the checked field's gameplay meaning. No candidate for this owner
has been installed.

## 2026-10-23: optional default names and remaining selection phases

`82602B9C` is accepted as `RecordNames_LoadTwoSlotsOptionalDefaults`
(344 bytes). It uses the two real direct-row pointers and three real profile
pointers of `RecordNames_LoadTwoSlots` at `82601D2C`. Owner -1 selects the
profile indexed by the state halfword at offset 12; owner -2 preserves its
name; other owners copy their direct-row name only when `use_defaults` is
nonzero. A failed lookup also preserves the destination. Both destinations
are 12-byte slots at state offset 2256.

Transferring the accepted sibling's switch and declaration order recovers
the allocation and real array homes. The conditional default row must be
expressed as a conditional expression: an equivalent initial-zero/conditional
assignment retained 14 instruction differences. Initializing state before
the first direct-row expression matches; reversing those statements retained
two instruction differences. Every array entry is initialized and used.
No extra array capacity, unused local, artificial read, padding, instruction
rewrite, or forced frame/register is introduced.

The recorded native runner accepted this owner through the ordinary
host-syntax-enabled US full-ROM gate. Its first successful gate immediately
froze source, complete changed module, four collateral objects, ROM/ELF,
linked script, layout inputs, and original assembly dependencies. External
hashes, whole-module equality, unchanged collateral objects, and ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d` passed independently before further
compilation. This is the first accepted owner of the next publication batch.

### Requeue: `82602FE8` count and descriptor views

Follow-up count-lifetime variants reach 252 bytes with 30 differing instruction
words and an allocation-only diagnostic. Keeping a bound pointer initialized
at the descriptor, then extending it only inside the positive-count guard,
recovers retail's count A3 and scan-end A1 in one parent. Its preserved base
and byte cursor remain swapped. Moving the actual incoming argument instead
of a separate cursor changes bulk-loop induction and emits 248 bytes.
Resetting that argument for the second scan does not close the difference.

A second calibrated 90-second source search improves its own score from
225 to 180, without matching. Review finds its base-to-unchanged-context
substitution semantically valid; a same-line initialization group improves
the score further. Neither is acceptance evidence, and the packed source
is not installed. Keep both the original 252-byte parent and this measured
partial improvement. Next: compare their exact allocation webs before
another source-lifetime family; do not replay parameter-walk, count-width,
byte-view, declaration-only, or cursor-reset families unchanged.

### Requeue: `82603870` phase dispatcher

The natural four-case switch reaches 304 bytes with the correct frame,
state-pointer home, result home, and branch/call body. The best parent has
raw similarity 0.9474; nine to ten instruction words differ in its opening
global counter address/update sequence. IDO retains the counter's address
in V1 while retail uses separate high/low load and store references.
Plain `++`, `+= 1`, explicit addition in either operand order, and a named
tick snapshot do not close it. Changing the snapshot into a new local
worsens allocation and sometimes the frame; it is not installed.

Required interface evidence: `StageContext_GetFadeMode` returns `u8`
in `src/8470.c`; `Audio_RequestIfChanged` (alias `800355E4`) returns `s32`
in `src/229E0.c`; `82614F0C` returns `s32` in
`src/fragments/20/fragment20_12C460.c`; assembly `80044144` dereferences
its argument, so its argument is a pointer. Prototypes must precede their
first uses in the existing `82602930` sibling, not only this new candidate.
Companion edits can hoist them without changing that sibling's object.
The runner synthesizes declarations before applying companions: explicitly
supply these same interfaces in the batch declarations as well, or its
cross-file fallback injects conflicting void-return/integer-argument forms.
These context failures are not source-shape rejections.

Next: obtain a calibrated logging-only allocation/expression trace for the
global address common subexpression. The ordinary source-level counter
families above are already measured; do not add volatile qualifiers or
instruction rewrites to suppress the commoning.

### Resolved: `826039A0` enclosing phase loop

`RecordSelection_RunPhaseLoop` is accepted through the recorded runner and
ordinary host-syntax-enabled US full-ROM gate. It advances `82603870` until
phase four while updating the background, UI, and selection view. After the
loop, `826058CC` classifies the saved state's byte-seven mode: modes zero
and four return zero, one and three return one, and other modes return -1
(`src/fragments/20/fragment20_12C460.c`). Category zero permits the two
finishing actions selected by the saved high byte at state offset eight:
`0x300` invokes `826036DC`, and `0x600` invokes `826037BC`.

The first natural loop retained six frame/home instruction differences.
Calibrated logging-only UGEN frame diagnostics passed stock/off/on/20-leading-
blank controls for both the accepted `82602A0C` sibling and retained parent.
They locate the missing space in the local area, not extra saved registers
or invented arguments. Keeping the actual mode-category query result as a
named, used local resolves it: category, state pointer, mode group, next
phase, and current phase are all initialized and used. The 48-byte frame
places the pointer at stack offset 40 and the mode group at 38. There is
no unused local or artificial storage.

First-success artifact verification distinguishes instruction extent from
terminal section alignment. The assembly owner reports 240 bytes, including
two trailing zero words. IDO reports 232 instruction bytes ending in the
retail `jr ra` / stack-restore epilogue, followed by the same eight natural
section-alignment bytes outside its function symbol. The entire text section
has the same length and bytes; every other function extent and all semantic
relocations agree. The initial strict symbol-size comparison correctly
surfaced this metadata difference; the follow-up audit checks exactly this
single terminal 240-versus-232 case, its epilogue, and its eight-byte tail.
No source padding, helper, or object modification produces these bytes.

The first successful gate froze source, complete module, four collateral
objects, layout/assembly inputs, linked script, ROM, and ELF before further
compilation. External hashes, whole-module byte/relocation equality with the
explicit terminal-alignment audit, unchanged collateral objects, and a full
`cmp` against the US baserom passed. ROM MD5 remains
`1561c75d11cedf356a8ddb1a4a5f9d5d`. This is the second accepted owner in
the current publication batch: 576 instruction bytes plus eight natural
terminal alignment bytes across the two original owner extents.

### Phase-dispatcher diagnostic follow-up

The calibrated `82603870` trace passes known-owner and retained-parent
stock/off/on/20-leading-blank complete-object controls. It identifies the
counter address as an allocator web selected into V1 in phase one, rather
than a delay-slot or post-link issue. A stock IDO 5.3 versus 7.1 control also
produces the same candidate prefix and the same known complete module.
Neither stock C driver resolves this parent; no compiler selection changed.
The next experiment must change that address-expression web through genuine
source structure, not add register pressure or alter instruction bytes.

### Requeue: `82602710` viewport border fill

The signed halfwords at context offsets 160 and 164 through 170 select
full-screen fill or four border rectangles around a 640-by-480 viewport.
`GfxImage_FillRectangle` in `src/7A50.c` takes a display-list pointer,
four signed 32-bit geometry arguments, and a 16-bit color. The initial
natural geometry family compiles to 332 bytes versus retail's 376, with
S0/S1 saved rather than retail's caller-saved geometry. Separate, used
left/right border heights and a pointer initialized only in the draw
branch improve the structural size to 360/364 bytes, but still save S0
and retain operand/scheduling differences (best reported raw similarity
0.3085). Typed/raw views, width/height ordering, and moving the constants
to the end of the subtraction do not resolve it. No candidate is installed.
Next: inspect the retained branch-local pointer's allocation/liveness and
the independent border geometry, preserving the reloads after drawing
calls rather than retaining stale viewport fields across them.

The follow-up native box passes eight stock/off/on/20-leading-blank whole-
module controls for a known owner and the retained geometry parent. Its
logging-only trace assigns the incoming pointer web to S0 in allocator phase
one (`save=1.6`, five uses); this is a measured saved-register choice, not an
assembler delay-slot hypothesis. Signed-halfword snapshots, explicit embedded
array/struct views, advancing the incoming argument to the viewport, and an
early full-fill return all remain unmatched. Halfword snapshots can reach
376 bytes but retain the wrong frame and saved pointer; they are not close
instruction matches. The best later reported raw score is 0.3404 with a
360-byte argument-advance body. Keep the 364-byte geometry parent as well:
different scalar scores do not settle its better structural subregions.
Next: distinguish the named/derived pointer's coalescing from its saved-
register cost, using the calibrated allocation evidence before any new
source family. No pointer-address escape, extra read, volatile qualifier,
fabricated argument, or padding is justified by these results.

### Resolved: `82600BA0` sorted unique index selection

`RecordSelection_ChooseSortedIndices` calls `82600A40` with an output array,
draw count, and pool count, then selection-sorts the chosen signed indices
in ascending order. `82600D38` supplies six output slots and the row count
from its packed table; the callee `82600A40` reads all three arguments.
The interface is therefore three arguments even though the wrapper forwards
the incoming pool-count register without emitting a new assignment.

The accepted 340-byte source uses a guarded do/while over the last index
and an ordinary inner scan. IDO performs the inner unrolling. The swap
loads the chosen minimum first. No source-level unrolling, extra storage,
object rewrite, or padding is used. Recorded runner acceptance and the
normal host-syntax-enabled full-ROM gate passed. The first-success source,
complete module, four collateral objects, layout/assembly inputs, ROM, ELF,
and linked script were frozen before further compilation. Independent
external hashes, whole-module byte/relocation/extent equality, unchanged
collateral and foreign files, and US ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d` passed.

### Requeue: `82600D38` randomized party records

The packed-table row count controls six unique sorted choices. For each
record, `82600A40` produces a three-element permutation whose first two
entries select the two sides' 24-byte packed Pokemon. `80071E48` unpacks
each into an 88-byte working record. Unassigned sides divide five distinct
stat-experience fields according to profile zero/four, one/two, or other/one,
then `82600CF4` refreshes the record.

The field interpretation is producer/consumer verified: `80071E48` copies
packed halfwords to working offsets 12, 14, 16, 18, and 20, and supplies
them to `Pokemon_CalculateStat` for HP, Attack, Defense, Speed, and both
Special stats respectively. `Pokemon_CalculateStat` and
`Pokemon_GetDVForStat` in `src/615D0.c` establish the stat-exp role and stat
index mapping. A named-field model replaces the earlier speculative
indexed loop; this is not a hand-unrolled generic array operation.

Sixteen controlled candidates test that model and then packed-row versus
destination evaluation order and selector width. Whole-module original,
declaration-context, and leading-blank controls pass. The best reported raw
similarity reaches 0.8107, but that 816-byte body remains eight bytes shorter
than retail. Other 820-byte parents have the correct 216-byte frame and
more faithful subregions. All remain rejected and none is installed.
Computing the row first restores the retail inner-loop S1/S2 roles; genuine
array stack homes, divisor branch topology, and temporary order still differ.
Next: test selector/divisor lifetime reuse and inspect the real local-area
layout; do not inflate the permutation or selected arrays, add padding,
invent reads, or force allocation.

The next eight candidates reuse the profile selector as the divisor and vary
the placement of the three real arrays relative to used scalar locals. They
remain rejected at 820 bytes (best reported raw 0.8010); neither family fixes
the stack homes or the missing instruction. A logging-only frame trace then
passes eight stock/off/on/leading-blank complete-object controls for the
accepted sorted-selector sibling and this retained parent. The parent has a
216-byte frame: 48 bytes at the saved-register phase, a 16-byte local area,
and a 152-byte area added before entry/exit emission. The frame total already
matches retail; this is an internal-home ordering problem, not evidence for
additional storage. The same trace identifies the packed-row and destination
induction webs in S1/S2. Next inspect their expression lifetimes and the
profile-to-divisor branch before changing the declarations again.

### Resolved: `82600D38` two-party preparation

`RecordSelection_PrepareTwoParties` is accepted at 824 bytes through the
recorded native runner and normal host-syntax-enabled full-US-ROM gate.
With randomization enabled it selects six distinct sorted table rows and
uses an independent three-element permutation for each row to choose one
packed Pokemon for each of two parties. An optional nonzero seed initializes
the deterministic RNG. Unassigned sides scale HP, Attack, Defense, Speed,
and Special stat experience by the selected profile's divisor and refresh
their calculated stats. Metadata loading runs for both sides even when
randomization is disabled.

The final source mechanisms are independently explainable. The divisor is
unsigned and only takes one, two, or four; the profile selector remains a
signed halfword. Placing the three real arrays after the two loop indices
matches their stack locations without changing their sizes or introducing
storage. Evaluating the selected row index before its table pointer restores
the temporary lifetime. This leaves exactly one swapped-source `addu` at
owner offset 308; eight byte-pointer arithmetic spellings do not fix it.

The last instruction resolves with the actual packed-row model: an eight-
byte header followed by six 24-byte Pokemon records. `func_80071B58` in
`src/72720.c` establishes the 152-byte row stride; `func_80071BB8` reads
the count at offset four and records at offset eight, bounded to six.
`func_80071E48` supplies the unpacked record and stat-experience evidence.
Ordinary `row->pokemon[index]` member indexing produces the exact operand
order. A pointer-addition spelling on the same member remains one word off.
The implementation has no instruction rewrite, padding, unused variable,
extra read, fabricated ABI, or manually unrolled generic array loop.

The first successful gate froze source, complete module, four collateral
objects, layout/assembly dependencies, linked script, ROM, and ELF before
further compilation. Independent external hashes, complete-module game
sections/bytes/extents/semantic relocations, unchanged collateral and foreign
files, and US ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d` passed. The
earlier requeue entries above describe the rejected parents, not the final
accepted body.

## 2026-10-28: selected-party loading (`8260166C`)

`RecordSelection_LoadSelectedParties` resolves four signed owner entries
against a packed party table. Owner -1 uses the selected row; owner -2
skips the side. Other owners select paired rows only for mode `0x400`
and sides zero and one, subtracting one for the even side. Negative or
out-of-range rows are skipped. The `load_records` flag controls unpacking
into the six-entry working group; valid rows still supply metadata when
that flag is zero. A zero metadata-layout byte uses side indices below two;
the other layout uses the side-pair index.

The header view records the observed signed owner bytes, metadata-layout
byte at six, mode halfword at eight, and selected-index halfword at 136.
The existing 152-byte packed rows and 88-byte working entries are shared
with `RecordSelection_PrepareTwoParties`. `func_80071BB8` in
`src/72720.c` is a void unpacking routine; `func_8006AED4` retains its
actual integer return type even though this caller ignores the result.

The near-match retained 109 of 110 exact instruction words. Its only
residual was the commuted source pair of a `bnel` at owner offset 152
(expected `56e2000e`, actual `5457000e`). Switch/if forms, reversed
comparisons, mask widths, owner case order, and a named long-typed mode
constant did not close it. A calibrated, restricted single-worker source
search recovered an ordinary used `int` local for the paired-mode constant.
The project `s32` alias is `long`; replacing that local with `s32` restores
the one-word mismatch. The local participates directly in the mode test.
There is no unused storage, fabricated interface, source unrolling,
instruction rewrite, or padding.

The canonical eight-candidate batch accepted its first signed-int candidate
on base `9064fa56c9e4f51fea34b3e8b19917c2484ee33f`. Naming and declaration
cleanup passed normal and twenty-leading-blank complete-module comparisons
for sections, text bytes, function extents, and semantic relocations. The
subsequent native `COMPARE=1 RUN_CC_CHECK=1` full-US-ROM build passed with
MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. The first-success source, object,
ROM, ELF, and map were frozen before cleanup; no coverage change accompanies
this implementation.

### 2026-10-28 requeue: `82602FE8` current-HP validation

The checked halfword is current HP. `func_80071E48` in `src/728D0.c`
creates the 88-byte working record, including experience at eight, stat
experience at 12 through 20, DVs at 22, and level at 29. `func_800619E8`
in `src/615D0.c` calculates maximum HP at 40; the local `82600CF4` refresh
copies it to current HP at 38. The descriptor's eight-byte header therefore
places the first checked HP at 46. The actual experience word also establishes
four-byte record alignment. Correcting the earlier two-byte-aligned partial
view preserves the best candidate's instructions but does not finish it.

A bounded native follow-up on base `ca1db4dd` records 128 candidates in 16
canonical batches, with no acceptance. The retained 252-byte parent matches
all 63 opcodes and 45 exact words. A real pointer to the entry array plus
reuse of the count scalar improves the initial parent; both that form and
a later bound-initialization form remain allocation-only residuals.
Two calibrated single-worker source searches run for 120 and 180 seconds;
the second improves its own score from 135 to 120 without reaching zero.
Those search scores are diagnostic evidence, not matching claims.

A private logging-only IDO 7.1 observer records five color-assignment sites
in `globalcolor`. The generated recompiler source has SHA-256
`5da5580a14ca58a0d1dae94a4c0fcfdefc0e08b07469e9c8ccfd8d572db7e38f`.
Known-source and two retained-parent controls pass stock, stock with twenty
leading blanks, observer disabled, observer enabled, and enabled with twenty
leading blanks: fifteen complete-module section/byte/extent/relocation
comparisons. The retained base parameter occupies A0 while its separate
byte cursor occupies A1; retail advances A0 and preserves the base in A2.

Expressing the advancing parameter directly reproduces a different 248-byte
bulk loop: it compares integer offsets instead of record pointers and loses
one address addition. This is a loop-induction difference as well as a
coloring difference. Explicit pointer-bound loops lose retail's unrolling;
raw address grouping, inline bounds, guarded-end construction, initialization
ordering, ordinary register storage hints, comma initialization, and the
correct record alignment do not resolve the owner. Do not repeat those
families unchanged or install a near-match. Nonpositive sums must still
return one, and all referenced HP fields must be checked without a
source-level unroll.

Next: compare the retained 252-byte base/cursor parent and the 248-byte
advancing-parameter parent through calibrated logging at `findinduct`,
`loopunroll`, and `eliminduct`. Identify why the latter selects an integer
bulk-loop bound before changing another source lifetime. The owner remains
assembly; coverage and production compiler selection are unchanged.

### Resolved: `82601070` parties matched to the existing levels

`RecordSelection_LoadLevelMatchedParties` is accepted at 552 bytes / 138
instructions. It scans all six working records for each of four sides whose
owner is nonnegative, retaining the highest level. For each of the first two
sides with owner -1, it resolves the selected packed-party row, checks the
row count, unpacks it, and sets all six levels to at least 50 or the observed
maximum. `82600CF4` refreshes experience and calculated stats and restores
current HP from maximum HP. Metadata loading follows each valid row. Owner
-2 and other owner values skip this loading phase.

The record view now exposes the producer-backed experience, stat experience,
DVs, level, and current/maximum HP fields. The experience word gives the real
88-byte record its four-byte alignment; the working grid remains 2,256 bytes
with its records beginning at 144. Both the new loader and the existing
party-preparation function share these views.

Reading the state directly through the context preserves the temporary-root
load seen in retail. Distinct scan and update pointers express the two
phases; each pointer is consumed directly by its own level access or refresh
call. This closes the final thirteen A0/V1 operand differences. The source
retains ordinary loops: IDO emits the first scan's peeled/unrolled sequence.

The canonical native runner accepted this source on base `6e084305`, with
its normal host syntax recipe and a full retail-ROM gate. Naming, shared-
record cleanup, and the signed loop-index alias each pass normal and twenty-
leading-blank complete-module comparisons for sections, text bytes, function
extents, and semantic relocations. A subsequent named-source build with
`COMPARE=1 RUN_CC_CHECK=1` and an explicit host syntax check also passes.
Retail ROM MD5 is `1561c75d11cedf356a8ddb1a4a5f9d5d`. Coverage and tracked
tooling are unchanged.

### 2026-10-28 requeue: HP loop-induction replacement selection

The follow-up on `0b6466c2` preserves both diagnostic parents in the current
source context: their function bytes remain identical to the earlier
252-byte and 248-byte captures. Logging-only IDO 7.1 controls pass fifteen
complete-module section/byte/extent/relocation comparisons for the current
known source and both parents, including stock, twenty-leading-blank stock,
observer disabled, observer enabled, and twenty-leading-blank enabled.
The pinned generated compiler source hash remains the one recorded above.
No production compiler or emitted instruction is changed.

The two parents both gain 33 expression-table entries during loop unrolling
(53 to 86 and 49 to 82 respectively). Their final bulk-loop comparison tree
still compares the scalar index and sum after induction elimination. Its
replacement metadata differs: the retained parent selects the record-address
expression, while the advancing parent selects its scaled integer index.
At emission the former comparison has pointer datatype zero and the latter
integer datatype six. This accounts for the missing address addition in the
248-byte form; inspecting only the surviving scalar tree misses the cause.

The calibrated trace follows the replacement search in `func_477e20` of the
pinned optimizer. The retained parent accepts address-expression table entry
39 (numeric opcode `0x41`) with induction factor 88. The advancing parent
considers its corresponding address entry 35 but the relation check in
`func_476ecc` returns -1; it then accepts scaled-index entry 34 (numeric
opcode `0x5B`), also with factor 88. Thus the address is present in both
parents: expression order alone does not explain the selection. The relation
checker has a special variable-base check through `func_476e40`; its precise
hash-entry condition is the next diagnostic target, not yet a proven source
rule. Numeric opcode and datatype observations are not guessed enum names.

Three further canonical batches contain 24 attempts. Four initial late-cache
forms fail C89 declaration placement and are corrected in the following
batch; they are context errors, not source-shape evidence. Immutable base/end
pointer bindings, a preserved readonly byte-buffer argument, and late or
direct typed-record views do not close the owner. The best stays 252 bytes,
63 matching opcodes, and 45 matching instruction words. A calibrated
single-worker 180-second source search stays at score 135; its only retained
tie adds a redundant end-pointer copy and is rejected as a solution. No
candidate passes to a retail gate or is installed.

Next: inspect the base-variable eligibility check in `func_476e40` for both
retained parents, then use the result to choose a genuine source-lifetime
change. Do not repeat the pointer-constness or late-record-cache families,
add fake storage, or treat opcode similarity as acceptance. Keep the owner
as assembly until an ordinary C spelling passes the full ROM gate.

### HP eligibility follow-up and box handoff

The next calibrated logging-only control checks `func_476e40` directly.
It returns one for the retained parent's original parameter and zero for
the advancing parent's saved local. The corresponding variable-table nodes
have a null versus non-null assignment pointer at offset 56. The optimizer's
input-reader code records the defining statement at that offset. This is
concrete evidence for the rejected base term, rather than an expression-order
hypothesis. Fifteen stock/off/on/leading-blank whole-module controls pass
again, with both parent instruction streams unchanged.

Forty canonical follow-up attempts test guard-local cursor scope and
initialization, reading the count through the cursor, ordinary C `register`
hints on the parameter/sum/status roles, signed-int versus long sum/count
and signed/unsigned status locals, and natural for/while/postincrement/
preincrement scan forms. All reject without a gate. The best remains
252 bytes with 45 of 63 exact words; guard-local cursor forms can be worse,
and for/while forms can add two instructions. These roles and control forms
must not be recycled unchanged. No candidate or compiler modification is
installed, and the owner remains a `requeue` after box expiry.

Next action for this owner: use the two retained parents and the proven
base-assignment distinction to investigate a different frontend lifetime or
expression-web mechanism. Any proposal must preserve the nonpositive-sum
result and all HP reads and must avoid redundant pointer copies, synthetic
reads, fake arguments, physical register binding, or emitted-byte changes.
The older party-initialization owner is the next file-local working box.

### Resolved: `82601298` party-record initialization

`RecordSelection_InitializePartyRecords` is accepted at 980 bytes / 245
instructions. When enabled, it walks the two 1,064-byte context descriptors
and their signed member counts. The owner byte and state's layout byte
select a six-record working group. Assigned parties skip preparation when
the selected-state or preservation flag requires it. Eligible groups pass
the initialization flag to `84302148`, refresh species-indexed names from
text groups 70/71, and, for unassigned owners, divide all five stat-experience
fields by 4, 2, or 1 before recalculating stats and current HP. The optional
history path increments only one of four valid counters below 250, saves it,
and refreshes the associated state.

The shared working-record layout preserves the earlier 964-byte parent.
An unsigned-byte divisor recovers the retail division sequence. The group
selection needs an explicit if/else, and the owner and initialization flags
need conditional expressions: initial-value-plus-if forms remove three
retail branches. Ordering the actual local declarations recovers the
side/member/header/descriptor stack homes; the comma outer-loop update
recovers their load/store scheduling. This leaves four words that spill an
implicit cursor at 68 instead of 64. A calibrated source search finds zero
scores using redundant scalar copies/constants; those proposals are rejected.
Reading the owner through the already captured header pointer resolves the
four offsets with no added scalar, read, or storage. The original loops remain.

The eight-candidate canonical header/cursor batch accepts its first candidate
on `0b6466c2`, with an explicit normal host syntax check and a full native
retail-ROM comparison. Naming, comments, and duplicate-prototype cleanup pass
normal and twenty-leading-blank complete-module section/byte/extent/relocation
comparisons. `80055F6C` uses its real `(void *, s32)` interface from
`src/517E0.c`; `80054E48` retains its actual integer result, which this caller
ignores. The first-success source, object, ROM, ELF, and map are frozen.
Retail ROM MD5 remains `1561c75d11cedf356a8ddb1a4a5f9d5d`. No coverage change,
unused local, fake interface, source unroll, instruction rewrite, or padding
accompanies this owner.

### 2026-10-29 matched: `826030E4` display-context initialization

`RecordSelection_InitializeDisplayContext` initializes row selection, text
resources, compact party descriptors and icons. It preserves the captured
entry mode for the final eligibility/history update while reloading flags
for the text-loader dispatch. The metadata-layout byte selects one or two
six-record groups per descriptor. Nonzero-species entries are copied as
88-byte records; unused slots among the twelve entries are cleared. Signed
member counts occupy descriptor bytes 4 and 5. Their sum selects the six-
or twelve-icon layout. The descriptor remains 1,064 bytes at context+176.

The four-byte values copied at context+88 are **text dimensions**, comprising
signed 16-bit width and height. `func_82602E14` produces these halfwords at
+88/+90 with a four-byte stride. Their natural two-byte alignment explains
the retail unaligned word loads/stores. A `RecordSelectionTextDimensions`
assignment preserves that layout without packing directives.

A staged row cursor accounts for the packed table's four-byte header.
Separate scan/clear/sum induction variables and comma-form outer updates
reproduce the ordinary record loops, including IDO's own two-record unroll.
Keeping the actual returned `PokeIconList44300 *` for both the context store
and flags update closes the final saved-mode stack offset (64 rather than
68); declaring that pointer before the mode preserves the allocator result
at sp+156 and the 160-byte frame. Every local carries a used value.

The allocator uses its actual `SceneLoadContext *(u32)` interface from
`229E0.h`; the final callback retains its actual integer address-handle API
`func_82610C84(s32, s32)`. The 360-instruction / 1,440-byte function matched
in the canonical runner. A diagnostic-only object batch ran while the
current-master baseline build held the gate queue; its first exact body was
then submitted for installation and the authoritative full-ROM comparison.
Private receipts retain the source, object, ELF, map and retail ROM hashes.

## func_82602FE8 — register-tie (2026-10-29)

Best: normalized 1.0 / raw 0.5238 (`pool-check:alias-both-cast`), size 252 matches.
Shape: `void *arg`; `total = 0; result = 1;`; loop 1 sums
`((Header *)arg)->counts[i]` (header `{ s16 count; u8 unk_02[2]; s8 counts[]; }`)
for `i < ->count`; loop 2 uses a *separate* counter `j` over
`((Entry *)arg)[j].unk_2E` (0x58-byte entry, u16 at 0x2E), `if (== 0) result = 0;`.
A separate `j` is what got the copt 4x unroll + remainder right (one shared `i` = 0.87).
Remaining diff: retail copies arg0 to a2 up front and walks a0 itself as the loop-1
pointer (count in a3, end in a1); ours keeps arg in a0 and walks a copy. `result = 1`
first gives retail's `li v1,1` placement but the normalized score drops to 0.984.
Tried: header/entries locals in every combination, assign-late, a count local
(makes copt unroll loop 1, 316 bytes — wrong), byte-offset access (0.87).
Permuter 300 s: best 120, fakes only.
Next: a single struct with entries embedded (union/array at offset 0), or loop 1
written with an explicit `s8 *` walk of the parameter itself.
