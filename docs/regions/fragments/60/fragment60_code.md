# Fragment 60 camera callback

## Accepted: `func_86A00020`, 2026-10-20

The 188-byte callback sets the perspective, then positions the camera at
`(0, sin(angle) * radius + 400 + centerY, cos(angle) * radius + centerZ)`
looking toward `(0, centerY, centerZ)`. `D_86A0D4DC` supplies the angle,
`D_86A0D4D8` the radius, `D_86A0D4E0`/`D_86A0D4E4` the center and
`D_86A0D4E8` the field of view.

The shared helper's actual definition in `src/229E0.c`, `func_80038E14`,
takes six `f32` coordinates followed by a `u16` roll angle. It stores the
eye/target coordinates and uses the roll angle's high bits to index the
trigonometric tables for the up vector. The callback now declares that
actual contract and passes a real `u16 roll = 0` local as the final argument.
The first coordinate is the ordinary integer literal `0`, converted to
`f32` by the prototype. No fake declaration, unused padding local or
instruction rewrite is needed to obtain the original 56-byte frame and
zero-argument materialization.

The normal runner accepts this source with `link_verified: true`, followed
by the full-ROM gate. Stop candidate-probing this owner after acceptance.
Real scalar/vector experiments without the roll local did not match; unused
padding is not a substitute for the consumed roll-angle value. Runtime
aggregate initializers are rejected by this IDO frontend and establish no
code-generation result.

The paired fragment-61 callback uses the same mechanism. Four successful
stages (assembly baseline, each individual acceptance and declaration cleanup)
freeze seven complete modules inside the successful gate callback, reread
receipts and externally hash every object before returning and before later
compilation. Every allocated-object fingerprint equals its original baseline.
Independent retail-address links cover all 69 function extents and 54,448
text bytes in this module and all 63 extents/53,568 bytes in fragment 61.
Native/public compiler paths, twenty-leading-blank controls, accepted-attempt
provenance, all-source host syntax and all 76 native tests pass. The final
normal ROM gate retains MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.

Only this callback and its helper declaration change in the source file.
Unrelated assembly owners and existing C remain untouched. No private helper
or coverage changes are part of the public correction.

## 2026-10-28 — `func_86A03F48`: requeue

requeue. The queue push that `func_86A0405C` pops:
- returns 0 when the player's queue holds 5, or when `D_86A0D560[item].cost (+4) + unk_00E8[player] >= 6`;
- otherwise `count + 1` and `values[(head + count) wrapped at 5] = item`;
- adds the entry's `f32 +8` to `unk_00D8` and its cost to `unk_00E8`, sets `unk_00F8 = item`, and calls `func_86A0BA80(player)` when the cost total reaches 5;
- returns 1.

Retail keeps an `entry` pointer (which spills `arg1` to its home), loads the cost once, and reuses `head` for the wrapped slot. Best 12 ops: retail holds the queue base in `$v1` and copies `count` into a second register (`or a3,t0`). A 240 s permuter suggested computing `head + count` before the full check; that spelling alone does not match.

## 2026-10-28 — `func_86A0588C`: requeue (offset-ring reach test)

Semantics: `D_86A444D8` is `D_86A443F0.unk_00E8`. The per-player index
selects an `F60C7Pair` from `D_86A0F2D4`, and its x/y feed
`MathUtil_Atan2s` and `sqrtf`. The heading adds `unk_0E6C[arg0]` (an
`s16[4]` at 0x0E6C), and the result indexes the cos/sin tables
`D_80088E50`/`D_80087E50`. The test is whether
`(pos.x - cos*d - arg1)^2 + (pos.z + sin*d - arg2)^2 < D_86A0F2BC[arg0]`.
`angle` must be `s32`: `s16` adds an `sll`/`sra` pair. The best local
similarity is 0.486 (72/72 instructions). A 96-form grid (struct field vs
`D_86A444D8`, pair pointer vs direct, position pointer vs direct, three
negation spellings, if vs expression return, three declaration orders) and
a 300-second permuter (2660 -> 2170) did not close it. Retail homes `arg2`
first and reuses `$a2` for `arg0 * 4`, which it spills to 0x18. Next: start
from that early `$a2` reuse; check whether `D_86A0F2BC[arg0]` is loaded
through the same `arg0 * 4` temporary before the call.

## 2026-10-29: `func_86A059AC` requeue

requeue (0.28). `(s32 player, f32 x, f32 z, s32 kind)` box test against `D_86A443F0.position[player]`, where `entry = D_86A0D560 + kind*0x18`:
- `halfWidth = entry[0x10] * 8.333333f * 0.8f + D_86A45AC8`;
- `px < x + halfWidth && x - halfWidth < px && pz < (0.0f + D_86A45AC8) + z`;
- and `(f64)z - ((f64)(entry[0x14] * 8.333333f) * 2 * 0.8f + margin) < (f64)pz` (the double literal is `(f64)0.8f`).

Retail sets v0 = 0 before the first compare and keeps an explicit `add.s` of 0.0f, while IDO folds our `0.0f + margin`. Find the source of that unfolded zero (probably a zero-valued field or a variable) first.


## 2026-10-29 native block: `func_86A059AC` accepted

The 256-byte leaf tests a player's `position[arg0]` against the item selected
by `arg3` in the 24-byte `D_86A0D560` table. The center comes from `(arg1,
arg2)`. Horizontal half-width is `entry.width * 8.333333f * 0.8f + margin`;
the upper z extent is zero plus the margin, and the lower z extent uses
twice the scaled height in double precision. The strict comparisons leave
the rectangle's edges outside. `func_86A02A9C` supplies each player index,
the object's x/z coordinates, and the item index.

The source uses a two-component upper extent, a real position pointer, and
a margin loaded once. Both extent components feed comparisons. The scalar
literal version folded the zero-plus-margin addition away and produced 248
bytes. Keeping the consumed upper-extent components recovers the original
256 bytes without dummy locals, altered ABI, instruction rewrites or
coalescing. The final accepted spelling includes the margin in the horizontal
extent before comparing it. Nearby `func_86A05B4C` and `func_86A05C94` use the
same bounds calculation over 20-byte collision records.

At base `d06e6d3c`, normal and twenty-leading-blank controls reproduce the
whole module's sections, text, function extents and relocations. The canonical
runner accepted `bounds:margin-in-extent:4` through the sequential full-ROM
gate; its receipt is `scratch/bounds3/gate-0/receipt.json`. The receipt records
an explicit normal host syntax check and retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, using native IDO 7.1 compiler SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.
The accepted installed object's independent link-shape check passes; its only
raw instruction differences from the assembly control are three relocation
fields for compiler-emitted constants. Probe-stat provenance confirms the
removed pragma has an accepted attempt. The owner remains assembly in
upstream `7a127bb6`, so this acceptance is novel at that revision.


## 2026-10-29 native block: `func_86A05C94` accepted

The 312-byte function scans `D_86A45A70` active 20-byte collision records at
`D_86A443F0 + 0xEC4`. Each record contains x/z at offsets 0/4 and an item
index at offset 16. It returns 1 if `(arg0, arg1)` lies strictly inside any
item footprint, using `D_86A45ACC` as the margin. The footprint arithmetic
is shared with `func_86A059AC`; its upper z extent is zero and its lower z
extent uses twice the scaled item height in double precision.

A named horizontal-extent value made IDO copy incoming x from `$f12` into
`$f20`, extending the body to 316 bytes. Repeating the horizontal expression
in the two comparisons lets IDO perform its own common-subexpression
elimination and retain x in `$f12`. A consumed `upper_z_extent = 0.0f`
represents the item's anchored upper edge and preserves the original float
addition of that extent to the margin. Caching the record's item index also
recovers the original integer-register allocation. No unused local, fabricated
argument, instruction rewrite, coalescing, or physical binding is involved.

The canonical runner accepted `collision-scan:cse-horizontal-expression:1`
at parent worker commit `d161e919`, through a sequential full-ROM gate.
`scratch/scan7/gate-0/receipt.json` seals source/object/ELF/map/ROM and records
explicit normal host syntax success, native IDO 7.1 compiler SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`, and
retail ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Normal and +20-leading-blank
whole-module controls pass before every batch. No candidate is admitted on
the normalized score alone.

Rejected families and retained evidence: scalar/pair extents with a named
horizontal result; local versus direct margin; cached versus direct item
loads; pointer arithmetic; raw half-extents plus a separate expanded width;
loop-local declarations; guard/loop topology; and scalar extent ordering.
The best named-result form was 0.9747 normalized / 0.7975 raw, 316 versus
312 bytes, with the first save changing `$f20`/8(sp) to `$f22`/16(sp).
A calibrated 300-second single-worker permuter run produced an invalid
270-point result by moving the required z load after return. That result
was rejected without a runner submission; statement reordering is disabled
in the private helper's next configuration. The accepted source came from
the manually reviewed common-expression family, not that mutation.


## 2026-10-29 native block: `func_86A05B4C` accepted

The 328-byte sibling of `func_86A05C94` tests the same active 20-byte collision
records and asymmetric item footprints, but sums each overlapping item's
`D_86A0D560[item].cost` instead of returning a predicate. The source uses a
normal counted loop; IDO derives the original pointer/end loop itself.

The first eight-variant batch transferred the accepted common-expression
spelling with a consumed zero upper-z extent and cached item index. The first
candidate, `collision-cost-sum:cse-horizontal-expression:0`, passed the
canonical sequential full-ROM gate at worker base `2d989b14`; no further
hypotheses were run for this owner. `scratch/sum2/gate-0/receipt.json` seals the
source, object, ELF, map and retail ROM, with explicit normal host syntax
success and ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. The native compiler
SHA256 is `975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.
Normal and +20-leading-blank whole-module controls pass.

Post-acceptance cleanup shares one `Fragment60CollisionEntry` definition
between both scans and removes duplicate externs. The record type is moved
before its first use; existing state storage and every unrelated accepted
function remain unchanged. The private final seal and normal/blank controls
verify that this declaration cleanup preserves the complete module and ROM.


## 2026-10-29 native block: `func_86A05504` accepted

The 372-byte function scans the active centers in `D_86A443F0.unk_16A8`;
`D_86A452B0` aliases their count at state offset 0xEC0. The signed byte at
`(*(u8 **)(D_86A46548 + 12))[0x2181]` chooses bounds: modes 0-2 use strict
19.199999-by-19.199999 half-extents, mode 3 uses 36.199997-by-31.199999,
and other values do not accept a point. The source's grouped `switch`
compiles to the original linear comparisons, with no jump table.

Reading x, then the mode byte, then z recovers the original integer-register
allocation and early point-table address setup. Reading the mode first gave
the correct size and 16-byte frame but held mode in `$v0` and the table base
in `$a0`; retail uses mode in `$a0` and the base in `$v0`. Both scalar and
pair read-order families were preflighted, and the first accepted candidate
was `point-bounds:read-order:xmz`; no further hypotheses were run afterward.
There is no fabricated ABI, unused local, unrolled loop, volatile access,
instruction rewrite or physical binding.

`scratch/point2/gate-0/receipt.json` seals acceptance at worker base
`9695325c`. It records explicit normal host syntax success, the stock native
IDO 7.1 compiler SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`,
and retail ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Normal and twenty-leading-
blank whole-module controls pass. The accepted source uses the same genuine
array and field widths as the existing state model.


## 2026-10-29 native block: `func_86A03F48` accepted

The 276-byte queue push now matches as genuine C. It rejects a queue count
of five or a resulting cost of six or more, increments count, stores the
item at `(head + old_count)` wrapped once at five, and updates the player's
amount, last item and cost. Reaching cost five calls `func_86A0BA80`.
`Fragment60QueueEntry` is the real 24-byte table record also consumed by the
bounds helpers; older raw attempts that used a 28-byte descriptor stride
are not evidence about this model.

Three measured source mechanisms recovered the original code. Incrementing
the count field preserves a separate old count for indexing. Repeating
`head + count` in the wrap condition/branches lets the compiler share the
sum without coloring a named computed-slot variable. Caching entry cost in
the limit condition preserves its single load, while writing the last item
before updating integer cost recovers the final temporary-register order.
The amount and integer cost use ordinary expanded assignments. Every local
is consumed by queue or cost logic; no fabricated argument, dummy value,
manual unroll, volatile access, instruction rewrite or physical binding is
used. The final source shares the existing descriptor typedef before its
first use and preserves all pre-existing accepted bodies.

The best intermediate reached matching 276-byte/24-byte-frame opcode shape
at 1.0 normalized / 0.9130 raw, with the first remaining difference at byte
217 (instruction 54): expected `lw t6,232(v0)`, actual `lw t5,232(v0)`.
The last-item store order closed that residual. The runner still emitted a
register-tie warning claiming source variants would not close it; the same
batch accepted `queue-push:update-expression:item-before-total`. That
warning is advisory, not proof of compiler unreachability.

`scratch/queue7/gate-0/receipt.json` seals acceptance at worker base
`c376c438`, with `link_verified: true`, an explicit normal host syntax check,
stock native IDO 7.1 compiler SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`,
and retail ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Each batch first
passes whole-module normal/+20-leading-blank controls. Direct cost rereads
added a load; explicit queue-pointer and budget-snapshot forms changed size
or allocation and were rejected. One private generator accidentally removed
the descriptor's cost member while deleting the local cost variable; its
eight compile failures were corrected with an anchored declaration edit and
supply no code-generation evidence.


## 2026-10-29 native box: `func_86A06A1C` requeue

Corrected the historical model: coarse radius is sqrt(2)*31.199999,
normalization saturates at 11 below distance 0.01 and otherwise uses
0.11/distance, and the response uses the OTHER player's motion norm. Old
74-attempt history used sqrt(4) or cap48 and does not test this model.
All new hypotheses went through canonical controls/probes; none accepted.
Best is scratch/repel8.json candidate 1, response-object-coordinates:1:
448 bytes, 56-byte frame, full opcode shape 1.0, raw similarity 0.8571.
Early continue fixes base/bound/flag GPR allocation. Reversing the squared
distance expression and other/player z read order improves floating colors.
Remaining differences include coefficient f20 versus target f2, impulse
f2/f12 versus target f12/f18, penetration f18 versus target f20, and the
other-motion squared-sum temporary. Constant relocations dominate the
first raw difference; inspect full instruction diff, not that warning.
Tried genuine vector locals, position snapshots, loop control forms,
factor objects, in-place vector scaling, alternative clamp expressions,
and branched component scaling. Branched scaling regresses to 472 bytes.
Next hypothesis: reverse normalization/penetration factor member order or
move the consumed penetration declaration ahead of normalization to test
the f20 lifetime preference; then clean position-pair read ordering.
No near-match body installed. This is a register-allocation requeue,
not evidence of a prerequisite or compiler impossibility.


## 2026-10-29 native block: `func_86A014D0` accepted

The 428-byte countdown update now matches as genuine C with a 24-byte
frame. It enables the final countdown at timer <= 30*D_86A0F8E4, plays
CF00 at 3/2/1 multiples and CF06 at zero. Positive timers decrement and
update the three helpers. At zero or below it continues cleanup while
state+0x1AC, func_86A04100, or any player state+0x24 equals 9 requests it;
it decrements and leaves for stage5 when the OLD timer was below -60.
Otherwise it leaves immediately. Postdecrement in the threshold expression
recovers the original old-value compare and delayed store instruction.

The stale local declaration `s32 func_800279C4(s32)` was corrected via a
canonical companion edit to `void func_800279C4(u16)`. This is verified by
linker_scripts/us/aliases.ld, where the symbol aliases Audio_PlayDefaultSound,
and that function's definition in src/229E0.c. Also verified the actual
func_80028118(u8) declaration there. The true audio return type removes
the reserved return register that displaced the timer/limit from v0/v1.
After that correction only instruction36 differed: bne v1,v0 instead of
bne v0,v1. Writing the single-tick equality as limit == timer closes it.
No fabricated ABI, forced register, unused local, instruction rewrite or
manual loop unroll is used. Earlier historical attempts include incorrect
5*limit instead of 3*limit, inverted cleanup guards and stale-value tails;
those are not tests of the final model.

Canonical batch scratch/timer4.json accepted candidate0,
countdown:one-tick-operand-order:0, link_verified true.
Receipt scratch/timer4/gate-0/receipt.json seals explicit normal host
syntax success, native IDO7.1 SHA256
975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944,
and full retail ROM MD5 1561c75d11cedf356a8ddb1a4a5f9d5d.
All batches first passed exact whole-module normal/+20blank controls.
Final declaration cleanup is independently resealed in scratch/timer-final.
