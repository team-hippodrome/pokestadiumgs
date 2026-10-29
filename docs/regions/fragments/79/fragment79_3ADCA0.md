# `src/fragments/79/fragment79_3ADCA0.c`

## 2026-10-27 — `func_84143E64`: matched

Draws a name label: `color = func_80064474(kind, id)`, copy 12 bytes of the name, draw them with `func_800495F8(x, y, 1, buf)`, then a marker at `(x + 21, y + 10)` coloured 169/190 for `color` 1/2. `x`/`y` are `u16` (retail reloads them with `lhu` from their homes; the callers' extern is retyped to match); `kind` is read back as the low byte of its homed word (`lbu 0x4B(sp)`), spelled `*((u8 *)&arg2 + 3)` (`// FAKE`). `func_800495F8` is now declared varargs (`(s32, s32, s32, void *, ...)`) throughout the file, which leaves every existing caller byte-identical.

## 2026-10-27 — `func_84143F18`: requeue

requeue. Same head as `func_84143E64`; for kinds 29/32 it draws the name directly when it equals `func_800625E0(buf)` (`HAL_Strcmp`), otherwise `func_800495F8(x, y, 1, D_8418B1C4, name, colour)` (varargs). Declaring `color` before `u8 buf[12]` fixes the frame; the only remaining diff is the reloaded kind byte landing in `v0` instead of retail's `a1` (register tie, `kind` locals/`switch` do not move it). Permuter 240 s: 15 → 15.

## 2026-10-27 — `func_8413E410`: matched

Finds or allocates a name slot among the 48 0x7A-byte `unk_D_8419C0C0` records at `D_8419C0C0` (`u8 tag`, `char name[0x79]`): returns if a slot's tag equals `arg0`, otherwise claims the first empty slot (tag 0) and `sprintf(name, (char *)func_8004C874(7, arg0 - 1))` with no further arguments. A counted indexed loop `for (i = 0; i < 48; i++)` over `((unk_D_8419C0C0 *)&D_8419C0C0)[i]` is strength-reduced by IDO into retail's end pointer in `a0` (`D_8419D7A0`) and its 0x28 frame, which the `do`/`while` cursor form does not reach.

## 2026-10-28 — `func_8413F390`: requeue

requeue. Digit drawer `(s16 x, s16 y, s16 numDigits, u16 value)`:
- `do { *p++ = value % 10; value /= 10; numDigits--; } while (value > 0 || numDigits > 0);`
- then `for (p--; p >= digits; p--) { func_8413F32C(x, y, *p); x += 6; }`.

The callers' externs must take `s16` for `numDigits`: retail sign-extends it, and the retype is byte-identical. Best is 8 diff ops: IDO CSEs `&digits` into `$s2` for the whole function, while retail recomputes it for the loop test and the second loop. Buffer sizes, declaration orders, `while`/`do` forms and `&digits[0]` did not change it; a 300 s permuter found only temp-copy fakes.

## 2026-10-28: `func_84143D8C` drawing record dispatch

The owner skips records when byte 8 has any of masks 0x01, 0x02 or 0x10 set,
testing them in that order. Otherwise byte 0 selects a drawing helper: kinds 1, 9, 10, 11,
12, 13, 21 and 22 call `func_84142F0C`, `func_841430D0`, `func_8414327C`,
`func_84143508`, `func_841436EC`, `func_841438EC`, `func_84143BF4` and
`func_84143CF0`, respectively. Other kinds do nothing. Every helper receives
the same record pointer. Compiled helper definitions and original assembly
establish the single-pointer interfaces; no extra arguments are introduced.
The original caller `func_84145BA0` walks from `D_84186188` to `D_841869A8`
in 40-byte record steps and discards the result. Unknown names are retained.

Three early returns followed by the switch reproduce all 54 instruction words,
the 24-byte frame and the existing 22-entry jump table. No storage, padding,
instruction rewrite or layout change is needed.

Validation on master `d06e6d3ca33dd23364f02701d87f5c2996d51146` plus this
replacement: fresh US extraction and the complete initial assembly baseline
passed. When master advanced, the updated assembly baseline passed before
reapplying the same C. Final validation freshly force-compiled the source with
normal syntax checks through
`make -W src/fragments/79/fragment79_3ADCA0.c -j4 VERSION=us rom` and produced
`build/pokestadiumgs-us.z64: OK`. Full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail `cmp` and `git diff --check` pass.
Original-assembly/raw-ROM comparisons verify the 216 bytes at
`0x3B361C..0x3B36F4` and the jump table at `0x3FAB9C..0x3FABF4`.

## 2026-10-29 — color selection matched

`func_84146DBC` selects RGB triples by record kind and calls `func_84146D98`,
which copies three bytes and sets alpha to 255. The lookup used for kinds 0,
1, 2, 9–15 and 28 is `func_8413D26C(state[1], state[2])`; its accepted
producer in `src/fragments/79/fragment79_393CA0.c` returns a byte from
`D_84195252[arg0 * 24 + arg1]`. Case 22 indexes `D_84186FD4` with the second
argument. The native batch `scratch/battle79-novel3456` has a sealed retail
gate for the direct switch spelling with that real `u8` return prototype:
`scratch/battle79-novel3456/gate-0/receipt.json`. Final transaction status and
commits are recorded in `scratch/agent-report.json`.

## 2026-10-29 — `func_84143F18` and `func_84144410`: genuine C matches

`func_84143F18` matches with `(u16 x, u16 y, u8 kind, u16 id, char *name)`.
Declare the byte color before the 12-byte buffer. For kinds 29 and 32, compare
`name` with `func_800625E0((s32)buf, kind)`, passing the callee's real second
argument. That input keeps the kind in `$a1` across the test and resolves the
historical register tie. The nested guard and ternary marker mapping match
220 bytes with a 64-byte frame using ordinary byte-parameter C.

`func_84144410` matches 260 bytes with a 72-byte frame. A signed counted loop
visits up to three slots from `func_8413FD04`, breaks immediately on 255,
indexes the pointer table at `&D_841951F8`, and advances a `u16` horizontal
offset by 67. Each selected record is 88 bytes; kind, ID and name are read at
24, 46 and 76. The separate transaction makes `D_84186D18` and `D_84186D1C`
visible before this definition and closes its earlier declaration-scope handoff.

Canonical batch `scratch/battle79-name-row` accepted the first candidate for
both owners. Unchanged/+20-blank whole-module controls and the explicit host
syntax check passed. The combined retail ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; sealed source/object/ELF/map/ROM and receipt
are at `scratch/battle79-name-row/gate-0/`. These two accepts resolve their
prior requeue entries; the border drawer and move-type drawer remain active.

## 2026-10-29 — `func_8413EDF8`: genuine C match

Matched the seven-rectangle border drawer (572 bytes, 96-byte frame). Declare
`GfxRect_DrawTextured` with its verified signature from `src/44E70.c`: eight
`s16` geometry/texture parameters and an `s32` cycle parameter. Use repeated
expressions for the top/bottom coordinates and inner width so IDO shares
those values. Compute the real left-edge height, `s16 left_height = arg3 - 2`,
before the first call; this orders the height and top-coordinate spill slots
correctly. Keep the right-edge coordinate as `s16` and the sum `arg0 + arg2`
as a word for the later right corner. Every temporary supplies rectangle
geometry; there are no filler locals, forced storage slots or rewrite pragmas.

Canonical batch `scratch/battle79-border-height` accepted the first candidate,
`border:left-height-first:s16:cast-False:first`, with `link_verified: true`.
The unchanged/+20-blank module controls, explicit host syntax check and full
retail ROM gate passed. The retail MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the sealed receipt is
`scratch/battle79-border-height/gate-0/receipt.json`. This closes the prior
border-drawer requeue entry.

## 2026-10-29 — `func_84143E64`: genuine argument cleanup follow-up

requeue; instruction_drift. The requested cleanup has not been installed and
there is no cleanup acceptance/commit. The closest genuine body declares the
kind parameter `u8`, passes it directly to `func_80064474`, and updates the two
caller prototypes. It has retail's 180 bytes and 64-byte frame, normalized
0.9778/raw 0.9556. Only the first call's two setup words differ: retail loads
`a0` with `lbu sp+75` and supplies the ID mask in the call delay slot; the
candidate supplies the ID mask first and uses `andi a0,a2,255` in the delay
slot. See `scratch/battle79-typed-name-cleanup/result.json`, first candidate.

Normal and +20blank whole-module controls passed for each cleanup batch.
All candidate changes used canonical companion-edit validation, compile and
link-shape helpers, transaction locking and statistics. No candidate's complete
module fingerprint matched, so no tracked source change or full-ROM cleanup
gate was attempted. This is accepted-C cleanup, not a new GLOBAL_ASM owner;
the private adapter probes companion replacements rather than falsifying
assembly ownership. A future hit must still pass explicit normal host syntax
and the inherited serial retail gate before installation is accepted.

Measured families: direct byte parameter and real pointer name typing; marker
control forms; old-style definitions with the actual narrow parameter types
and compatible default-promoted prototypes; used value temporaries; read-only
parameter declarations and matching prototypes; explicit scalar promotions;
byte normalization; real local-value role reuse; and guard/comma-assignment
forms. The read-only inputs initially exposed IDO's requirement for matching
qualifiers in the externs; the corrected batch compiled and did not improve
the residual. The producer `src/641E0.c` uses an old-style `u8/u16` definition
of `func_80064474`; compatible promoted `int/int` externs were also tested
together and rejected. None of those declaration changes was installed.
Retained batches: `scratch/battle79-typed-name-cleanup*/result.json`.

Calibrated native optimizer evidence is at `scratch/ido-name-parameter-trace/`.
Both normal trace inputs reproduce their canonical 180-byte function words
(`controls.json`). The current address-peek body lists parameter P/3/11 as
non-vreg; the genuine byte body lists the same byte parameter as vreg and
assigns it a constrained color. This distinguishes memory eligibility from
a mere register spelling difference. The genuine sibling `func_8413F32C`
is also a useful limit: its byte parameter is vreg but is reported not colored,
not splittable (`scratch/ido-digit-parameter-trace/`), and its outgoing third
argument reuses the incoming parameter register. That register constraint is
a candidate explanation, not a general impossibility proof.

Next: a genuine source-lifetime/argument-build mechanism that leaves the kind
read in memory without address hints, volatile, fabricated ABI/return types,
unused state or physical bindings. Retain the original function until such a
body passes the complete native retail gate. No near body is installable.

### Native owner box 2026-10-28 20:44–21:39 UTC: func_84140D68 — requeue / register-tie

Party status icon drawer, 436 bytes / 56-byte frame. Best genuine body is
`scratch/batch-party-icons7.json`, `party-icons:record-address-word:condition-count:u32-sum`.
Normalized similarity 1.0, raw 0.9817: only the tail count `lbu` / `slt`
uses v0 rather than retail t0; all remaining instruction words agree.
The real caller supplies one state pointer, not a second argument. The party
header count is byte 8; records begin at 24, stride 88, status +36 / HP +38.
Explicit duplicated slot initialization in both side branches and real count
assignment in the for condition fix the initial register rotation. Runtime
word address arithmetic for record +24 retains the original addiu; ordinary
typed pointer arithmetic folds it away (432 bytes). No fixed register, stack
or address binding was used.

Tried typed pointer/index views, cached and condition-assigned counts, true
branch scopes, for/do/goto guards, real role reuse, signed/unsigned value and
address expressions, exact byte conversions. Eleven documented batches plus
a restricted 120-second declaration/commutative search: search base/best 10,
no output or improvement. No installation or retail receipt. Next hypothesis:
genuine count-expression/lifetime separation retaining the correct preheader
while leaving the late count in t0; no fabricated second formal or filler.

Complete exact visible declarations were supplied to the restricted search
after the parent indexing finding; no rejected candidate was replayed for
performance. Next fresh owner is func_84144EF4 (zero historical attempts).

### Native accepted panel borders — 2026-10-28 21:40 UTC

`func_84144EF4` accepted as `panel-edges:sdk-macro:xy:update:u16` in
`scratch/battle79-panel-edges/result.json`. Real unsigned 16-bit x then y
locals, x increment before the inner pair, and ordinary SDK
`gDPFillRectangle` macros give exact 448-byte / 64-byte-frame output.
The signed coordinate form instead needs 464 bytes / 56-byte frame; reversed
unsigned declarations preserve size but swap the actual halfword spill slots.
The existing caller `func_84145744` demonstrably forwards the state in a0 in
retail assembly. Its existing C call and the stale prototype now explicitly
pass that same pointer, keeping the caller unchanged at the machine level.
All complete exact visible data/helper declarations were supplied up front;
no declarations or compiler/guard changes were invented for speed.
Whole-module normal and +20blank controls passed. Automatic canonical native
full-ROM gate and normal host syntax check passed. Sealed receipt:
`scratch/battle79-panel-edges/gate-0/receipt.json`; ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, stock IDO7.1 compiler SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.
This is a new owner, distinct from the four accepts integrated in PR1989.

### Native accepted intersecting panel borders — 2026-10-28 21:41 UTC

`func_841450B4` accepted with genuine SDK rectangle macros and four used u16
coordinates declared x, hx, y, hy; assignments follow x, y, hx, hy. Target
652 bytes / 96-byte frame. The six rectangles are three actual distinct
outer/inner borders, not a loop expansion. Historical 52 attempts all failed
compilation at the existing caller's omitted state argument. Verified a0
forwarding in the original sealed module supports the explicit pointer call
and prototype companions; no invented argument or fake ABI. Complete visible
helper/data declarations avoid the unrelated global index scan.
Manifest `scratch/batch-panel-cross.json`, accepted label
`panel-cross:sdk:x,hx,y,hy:assign-x,y,hx,hy`. Normal/+20blank whole-module
controls, explicit normal host syntax and canonical serialized native full-ROM
gate passed. Sealed receipt `scratch/battle79-panel-cross/gate-0/receipt.json`,
retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. No compiler rewrite or padding.

### Native accepted panel grid — 2026-10-28 21:43 UTC

`func_84145340` accepted at 1028 bytes / 48-byte frame. Genuine `u16 v[6]`
coordinate storage and SDK rectangle macros reproduce the repeated halfword
loads/stores and exact command scheduling. Index 0 is the vertical border's
y coordinate, indices 1–3 are the three horizontal row y positions, index 4
is the vertical border x, and index 5 is the horizontal start x. Updates
increment the vertical x and the three row y values. These are four different
outer and inner borders, not manually expanded loop iterations. The old 164
attempts included 151 compile failures at the omitted caller argument; many
also swapped the real coordinate axes. The remaining raw command candidates
had only ~0.62 normalized similarity. Fixing the actual caller and modeling
correct geometry with an ordinary unsigned array is materially different.
`func_84145744` and the stale prototype now explicitly pass the already-live
state pointer. No ABI hint, fabricated argument, stack binding, filler or
compiler rewrite. Signed array / scalar / struct alternatives differ greatly.
Manifest `scratch/batch-panel-grid.json`, label
`panel-grid:sdk-correct-axes:array:u16`; normal/+20blank whole-module controls,
explicit normal host syntax and canonical native retail full-ROM gate pass.
Receipt `scratch/battle79-panel-grid/gate-0/receipt.json`, retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Earlier panel timestamps above corrected
to actual UTC clock readings; receipts and immutable source proof unchanged.

### Native func_8414327C: counted-call-loop prerequisite / requeue — 2026-10-28 21:55 UTC

Move-detail renderer: retail 652 bytes, frame72. No source installed; no gate
receipt or new acceptance. Five genuine hypothesis batches (40 compiled
variants), plus the initial 8 failed only on stale own-owner pointer prototype.
That prototype was corrected through a real candidate-owner companion; all
subsequent whole-module normal/+20blank controls passed. Complete exact
visible declarations supplied, including real u8-return move getters from
src/638E0.c; no fake return-category hints. Explored for/do/offset/countdown,
preincrement/predecrement, real break form, typed 10-byte move/PP record,
u8/u16/s16/s32 counter widths, actual side/index role reuse, signed/unsigned
coordinate cursor and count/end termination, u16 power value and signed use
of unsigned coordinate storage. Best normalized 0.8098 / raw0.454, 608 bytes
(frame88) in `scratch/batch-move-detail5.json`,
`move-detail:coordinate-cursor:s16:count`. Major residual is a real loop
instead of retail's three straight-line glyph calls, not an allocator tie.

Controlled normal standalone reproduction of the typed-slot s32 do-loop is
instruction-words-identical to the canonical 608-byte candidate object:
`scratch/ido-move-detail-trace/controls.json`. Stock diagnostic `-Wo,-zdbug:8`
shows loop9(0) unchanged before and after unroll analysis; see
`loop-debug8-uoptlist`. Diagnostic summary crashes with the previously observed
wrapper_ecvt signal6, after emitting the procedure listing; normal control is
valid. No acceptance compiler options or binaries changed.

Primary compiler decompilation source, read to identify the prerequisite:
https://github.com/n64decomp/ido/blob/master/src/uopt/uoptloop.c#L916-L934
`complex_control_flow_in_interval` treats Ucup/Uicuf calls as complex flow;
`determine_if_unrollable` at1122–1131 rejects that multi-block loop. The
calibrated listing and all tested loop bodies agree. This rules out automatic
unrolling of these counted-call loops under the canonical compiler, rather
than all possible C sources. Retail likely reflects explicit source call
repetition, but manufacturing that expansion violates this session's no-manual-
unroll restriction. No expanded candidate was submitted. Close this owner box
early on that demonstrated prerequisite; do not spend remaining time on more
counter spellings. Next action: seek independent authentic source-topology
evidence before revisiting; retain ASM under present constraints. Continue
unmerged party/detail drawing owners using their real loops.

### Native accepted party level/HP columns — 2026-10-28 22:01 UTC

`func_84143508` accepted, 484 bytes / frame64, label
`party-stats:loop-update-order:for-ne:direct`. Genuine 88-byte record layout:
level +29, HP +38, maximum HP +40, party header24. The real helper
`func_8413FD04(u8,u8,u8)` provides the slot or255; the old history's wide
signature was not retained. u16 running column offset and y, plain offset
update, ordinary for-loop, mon lookup before height calculation, and direct
coordinate globals give exact output. No explicit duplicate column local:
the compiler introduces the retail working copy naturally. A do-loop was
only two scheduling sites short; for-loop fixes both. Explicit coordinate
pointer alternatives remained near and were not accepted. No binding,
manual unroll, filler or fake ABI. The own stale prototype is now the real
u8 state pointer type; existing callers already pass it.
Normal/+20blank complete module controls, explicit normal host syntax and
automatic canonical native retail gate passed. Manifest
`scratch/batch-party-stats4.json`; sealed receipt
`scratch/battle79-party-stats4/gate-0/receipt.json`, retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, stock native compiler unchanged.

### Native accepted selected Pokémon details — 2026-10-28 22:12 UTC

`func_841438EC` accepted, 776 bytes / frame96. Label
`active-detail:natural-party-expression:mon-last:byte:ne`, manifest
`scratch/batch-active-detail6.json`. Party record has a24-byte header and
88-byte Pokémon records: moves +2, PP +24, level +29, HP +38 / maxHP +40.
Selected slot matches party byte10 to choose live PP data, otherwise stored
record values. Four actual move rows are a real for-loop; no manual expansion.

The typed party view fixes the initial record expression's genuine evaluation
and register order. u16 height / row offset and for-loop fix height conversion
and both loop scheduling sites. Best intermediate differed only in frame104
rather than96, with all used spill offsets already exact. The extra explicit
party-slot local was unnecessary: using the actual table expression directly
lets the compiler cache its address and reduces the frame to96 without any
binding, artificial local, padding or compiler change. Record pointer declared
after the other used locals gives the actual +80 spill. Counter narrowing
instead adds instructions; wide scalar promotions do not fix the frame. The
prepared declaration-only optional search was never run because the natural
source hypothesis accepted first.
Normal/+20blank complete module controls, explicit normal host syntax and
canonical serialized native retail full-ROM gate passed. Sealed receipt
`scratch/battle79-active-detail6/gate-0/receipt.json`, retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, stock IDO7.1 unchanged. Existing owner
prototype now takes the real u8 state pointer; existing callers already pass it.

### Native accepted all-party level/HP grid — 2026-10-28 22:15 UTC

`func_841436EC` accepted, 512 bytes / frame88. Real count at party byte8,
24-byte header and88-byte record, two rows of three columns with x+=67 and
row46 after entry2. Initial explicit cached party value stayed live across
the first glyph call and spilled the row offset; direct typed table lookup
lets the compiler form the actual record pointer earlier. u16 x, row and
per-row y reproduce the target conversions. Best intermediate had only two
words different: cached table-address spill +68 vs retail+64. Explicit byte
stride fixes that slot but exchanges two saved registers; count-cache forms
rotate more registers. A restricted declaration/commutative permuter found
the genuine final scope in1.8seconds: y is declared inside the row loop,
matching its actual lifetime. All other source expressions are unchanged.
No artificial local, stack binding, filler, manual unroll or compiler rewrite.

Search result `scratch/permute-safe-all-party-stats-result.json`, base8 ->0;
only the reviewed per-row declaration scope changed. That optional score is
not the acceptance proof. Its single known lead went through canonical
validation, automatic native full-ROM gate and explicit normal host syntax:
`scratch/batch-all-party-stats-scope.json`, label
`all-party-stats:per-row-height-scope:verified-search-lead`.
Sealed receipt `scratch/battle79-all-party-stats-scope/gate-0/receipt.json`,
retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Both pre-probe controls and
fresh post-accept whole-module normal/+20blank sections, bytes, function
extents and relocation controls pass. Post-accept proof is bound to the
sealed receipt/source hashes in `gate-0/post-controls.json`. Private control
helper only invokes the unchanged canonical object recipe; no source mutation
or runner/guard/compiler change. Existing own prototype takes the real state
pointer. Earlier selected-detail note timestamp corrected to actual UTC.

## func_84147BA4 — register-tie (2026-10-29)

Best: normalized 1.0 / raw 0.8065 (`ramp:pair-post:v0-out-idx`, scratch body below).
Shape that got there: `Fragment79Ramp { s16 values[10]; }` struct copy of
`D_84187004` declared *between* `v` and `index` (lands at sp+0xC like retail);
step-6 loop `for (i = 0, out = (s16 *)(arg0 + 0xC); i < 12; i += 6)` with two
explicit stores per pass, `out[9]` (thresholds 0x20/0x16, `v - 0x16`) then
`out[7]` (thresholds 0x1D/0x13, `v - 0x13`, re-reading `arg0[9]`), then
`out -= 4`; `s32 v = 0;` initializer moves `v` into v0 like retail.
Remaining diff: `out` and `index` swap a1/a2 (retail out=a2, index=a1).
Tried: every declaration order of out/index/i, `index = 0` before the loop,
`i = index = 0` chains. Permuter (300 s) reached score 0 only with an
empty `if (!i) {}` fake — rejected per the no-fakes rule.
Next: look for a non-fake source shape that gives `index` the earlier
register (e.g. index as a `s16 *` into `ramp.values`, or a step-3 loop
original copt-unrolled by 2); else leave for a permuter run with fakes
disallowed.
