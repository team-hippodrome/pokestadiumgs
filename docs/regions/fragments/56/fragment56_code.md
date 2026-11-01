# fragment56_code matching notes

## 2026-10-29 — `.rodata` owned; `func_86803ED8` matched; `func_86806E94` requeue

The `fragment56_data` blob held this object's `.rodata` too. It is now split:
`data` up to 0x2B95C0, then `fragment56_code`'s `.rodata` from
0x2B95C0 (the first EUC-JP string, 16-aligned) to 0x2B9A10 (after the 1.4f
constant and its zero padding), and a `fragment56_tail` rodata blob after
that. The C now writes `1.8f`/`1.2f`/`1.4f` literals instead of
`extern D_86808218/D_868083E0/D_868084C4`. This unblocks jump-table owners
`func_86800594`, `func_86801E8C`, `func_8680537C` and `func_8680686C`.

`func_86803ED8` (frame draw) matched. Case 8 falls through into the case
2/5 body.

`func_86806E94` (**requeue**, 0.89, `scratch/c/e94.json`) is the screen-state
update; the whole switch is written out. Retail re-forms `%hi(D_86808070)`
for each access (load, store, reload) and loads the returned `D_8682F2A8`
through `$v1`. Ours caches the address in `$v0`. `D_86808070` sits in the 16
bytes at 0x2B95B0, just before this object's `.rodata`. That is consistent
with a function-local `static s32` in this file, which would need the data
blob split to give `fragment56_code` that `.data` word (see the
per-access-`lui` note for `func_8F100020`).

## 2026-11-01 — animated texture callback accepted

`Fragment56_AnimatedTextureCallback` (formerly `func_86800298`, 332 bytes)
selects archive227 entry0 at event0. At event5 it advances a counter unless
`D_8682F2B4` is set, wraps at21, selects entry counter/4, installs the texture
at graphics segment15, submits `D_86808640`, and calls `func_8003CD84`.
The one-argument texture-data getter and two-argument archive getter are
verified in `src/4CC20.c`; the assembly-only draft inferred extra arguments.

A function-local static counter restores the original scalar accesses.
Direct counter clamping and a live asset-return temporary reproduce the
original40-byte frame and segment-command spill at24. There are no dummy
locals, source-line directives, instruction rewriting, or changed compiler flags.
The static is pinned by `datamig_bss.ld` at its original word86807CFC.
Its object has a16-byte NOBITS section containing the four-byte static and
compiler alignment tail. The loaded data blob retains the original zero word
and following data, so the overlay preserves retail initialization. Only this
counter is assigned to that overlay; future bss additions need separate review.

A private opt-in verifier checks the source/function, sole static at section
zero, NOBITS size16, exact linker pin, and loaded zero backing. It real-links
the entire candidate text and rodata at game addresses with the bss overlay,
then compares every linked byte. Ten positive/negative controls pass. This
proof only enables a sequential canonical ROM gate; it does not install C.
`fragment56-pinned-counter8` candidate0 passed the normal host syntax check
and full US ROM gate on `d39a2204`, retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The assembly baseline also passed with
that overlay before candidate admission. Naming preserves all module bytes,
function extents, and normalized relocations normally and with20 leading blank
lines. The old function address remains a linker alias. Diagnostic tools and
receipts stay private; the production source and linker pin are reproducible.

## 2026-11-01 — scene loop accepted

`Fragment56_RunSceneLoop` (formerly `func_86807120`, 380 bytes) initializes
four model groups when the scene mode byte at offset0x2180 equals4, selects
random starting animation frames, starts a fade, and renders/updates until
state13. Its indexed model initialization reuses the accepted source shape
from `func_8680649C`, with the target's call order and state writes.

`fragment56-setup8` candidate0 passed the canonical host syntax check and
full retail ROM gate on `582d79e4`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Naming preserves all module sections,
function extents, and relocations in normal and +20-line controls. The original
address is retained as a linker alias. No additional bss or linker changes
were required by this function.

## 2026-11-01 — model-grid transforms accepted

`Fragment56_UpdateModelGridTransforms` (formerly `func_8680671C`, 336 bytes)
sets the scale and horizontal spacing of four parent models, applies the same
scale to twenty child models per parent, and updates two vertical positions.
The placement factor is the product of two scale ratios against 0.17f; the
shared height calculation uses double precision before storing a float.

Assigning the local height after that shared-height calculation reproduces the
original floating-point allocation and scheduling. The indexed child loop is
unrolled by the stock compiler; no manual unroll or source-line controls are
needed. Candidate4 of `fragment56-model-evaluation8` passed the canonical
normal host syntax check and full US retail ROM gate on `c90635d5`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Readable local names and function naming
preserve every module section, function extent, and relocation in normal and
+20-leading-line controls. The old function name remains a linker alias.

## 2026-11-01 — animation-state update requeue (resolved below)

`func_86806CD8` remains assembly (**requeue**, **register-tie**). Forty
canonical source variants reproduced the target's 444-byte size and 64-byte
frame; the best normalized score was 0.9910 and raw score 0.8468. The state
pointer uses S4 instead of S3, while the inner byte bound uses S3 instead of
S4, changing save order and dependent instructions. Typed/byte state access,
pointer/index effect cursors, initialization order, block scope, index widths,
and loop-bound spelling did not close the residual.

A 120-second single-worker permuter run reproduced the canonical candidate's
444 instruction bytes exactly before searching. It found no zero. The best
score, 85, moved the node-byte write outside the mode14 guard and was rejected
on semantic review; other retained mutations moved a tick write outside its
guard or replaced advancing pointers with first-element addresses. No searched
body was installed. Next: inspect the allocator webs for the state pointer and
inner bound, rather than repeating width/cursor grids. The assembly masks the
sound call's second argument to a byte; model-frame calls take signed halfwords.

## 2026-11-01 — texture-fade callback accepted

`Fragment56_TextureFadeCallback` (formerly `func_868000AC`, 492 bytes) loads
archive152 at event0. At event5 it clamps the node's unsigned frame word at
0x14 to11, selects one of twelve table entries, computes primitive alpha with
`func_86800020`, and emits texture segment15 and `D_8680863C`. Scene-state
words then control frame increment/decrement. The sound-independent frame
word remains unsigned so decrement wrap agrees with the original instructions.

Direct field clamping removes a duplicated constant-load instruction. Loading
a live texture-index temporary after clamping reproduces the original stack
homes (asset at56, node at48) and segment-command spill at32 within the
64-byte frame. Frame values after helper calls are reloaded from the node;
reusing the pre-call index there would change behavior. No dummy locals,
manual padding, source-line directives, or instruction rewriting are used.

Candidate0 of `fragment56-fade-live-index8` passed link-shape verification,
normal host syntax checks, and the canonical full US retail ROM gate on
`d568dad6`, MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Naming preserves all
module sections, function extents, and relocations in normal and +20-line
controls. The original function name remains a linker alias.

## 2026-11-01 — animation-state update accepted

`Fragment56_UpdateModelAnimations` (formerly `func_86806CD8`, 444 bytes)
updates four animation tick counters. Mode15 holds frame49 and enables event
track1 after completion; mode14 resets frame14, clears forty effect models at
the trigger frame, and runs the per-model update. Its tick threshold is70.

Calibrated stock CFE/UOPT/UGEN/assembler captures preserve the entire module
in normal and +20-leading-line controls. A logging-only UOPT replay preserves
optimized ucode and symbols both with and without diagnostics. For the prior
`do`-loop source, the state pointer's adjusted benefit is13.875 while the
inner bound's is14.2857141; the bound takes the earlier saved register. Using
`for` loops for both iterations restores the target allocation, leaving only
two swapped instruction pairs in the prologue. Initializing the parallel
state/model cursors and model index in the outer `for` header closes both
ordering differences. No compiler decisions, register bindings, or instruction
bytes are forced. The earlier width/cursor requeue is resolved.

Candidate0 of `fragment56-animation-for-init8` passed the canonical normal
host syntax check and full US retail ROM gate on `77ad3fdb`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Naming and readable struct fields preserve
all module sections, function extents, and relocations in normal and +20-line
controls. The original address remains a linker alias.

## 2026-11-01 — scaled parameter selection accepted

`Fragment56_UpdateScaledParameters` (formerly `func_86800B98`, 452 bytes)
selects two floating-point parameters from four selector cases. It scales
`D_86807C60` by `D_86807CC8`, selects the base for `D_86807C9C` using the
comparison of `D_86807C98` and `D_86807C94`, then scales `D_86807C9C`.
The default case preserves `D_86807C60` and still scales `D_86807C9C`.
The selector's broader game meaning remains unresolved.

An ordinary four-case switch with separate if/else assignments reproduces
the retail control flow. Writing `D_86807C98 == D_86807C94` preserves the
original floating-point comparison operand order; reversing that expression
changes four instruction words. Constants5.1f and5.4f occupy the file's
existing rodata subsegment. No jump table or additional layout work is needed.

Candidate0 of `fragment56-scale-compare8` passed the canonical normal host
syntax check and full US retail ROM gate on `505f5bc3`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Function naming preserves all module
sections, function extents, and relocations in normal and +20-leading-line
controls. The original function name remains a linker alias.

## 2026-11-01 — model-group initializer accepted

`Fragment56_InitModelGroups` (formerly `func_86805AA4`, 484 bytes) resets
three model pools per group (40, 40, and20 entries), resets the corresponding
base model, initializes a model with its asset and animation0, chooses a random
starting frame modulo24, and initializes the group's position vector. It sets
all three scale components to0.045f and the vertical position to56.0f before
clearing the shared model context and calling `func_86800D5C`.

Direct indexed model accesses allow the compiler to update induction pointers
before the final transform stores, reproducing the original negative offsets.
A separate model-pointer local introduced an extra register copy and delayed
those stores. Live `scale` and `height` locals reproduce the original136-byte
frame and spill homes while supplying the values written to each model; no
unused locals or padding are required. The three loop comparisons preserve
the original inequality/equality forms.

Candidate4 of `fragment56-model-group-values8` passed the canonical normal
host syntax check and full US retail ROM gate on `dbb8e9a3`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Readable index names, address expressions,
and function naming preserve all module sections, function extents, and
relocations in normal and +20-leading-line controls. The old function name
remains a linker alias.

## 2026-11-01 — pool-completion update accepted

`Fragment56_UpdatePoolCompletion` (formerly `func_868058C0`, 484 bytes)
updates the frame state, scans four groups of40 records for the -1 sentinel
and20 records for active state1, and advances completion when the pools are
empty. In the delayed branch it increments a persistent counter on empty
scans, plays sound0xCF06 at5, and completes at31. A positive outstanding
count resets the counter. The other branch completes directly after an empty
scan when its gate flag is clear.

The uninitialized local form placed the new counter and the existing texture
counter together in BSS, where their required addresses cannot both be met by
one section base. Explicit `static s32 drain_counter = 0` uses IDO's separate
`.data` section and leaves the texture counter at BSS offset0. The linker pins
this initialized counter at its original word86808048 with a NOLOAD overlay;
the loaded data blob retains its zero initializer at ROM2B9588. Compiler
alignment bytes have no load image, preserving neighboring data. Future data
objects in this C file need separate layout review.

The still-assembly baseline passed a normal full-ROM build with the pin on
`0fdac26f`. A private verifier requires the sole initialized scalar at data
offset0, zero-filled PROGBITS size16, unchanged texture-counter BSS placement,
exact pins, and loaded zero backing. It real-links the complete module and
compares every text/rodata byte to the game ELF. Fourteen controls cover wrong
owners, paths, storage classes, sizes, offsets, initializers, pins, and another
function's corrupted instruction. The proof permits a sequential ROM gate.

Candidate0 of `fragment56-drain-admission-and-vectors8` passed normal host
syntax checks and the full retail ROM gate on `0fdac26f`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Naming, readable indices, and unused
shared-declaration cleanup preserve all module sections, function extents, and
relocations in normal and +20-line controls. The original function name remains
a linker alias. This resolves the drain counter's initial layout prerequisite.

## 2026-11-01 — moving-model update requeue

`func_86806180` remains assembly (**requeue**). The best retained source is
`fragment56-moving-position-order8` candidate1: expected588 bytes, actual592,
frame96, normalized0.9797/raw0.9595. Direct array-element access for the
animated model, a live byte-offset cursor, inline tick update, and parallel
`for` initialization reproduce the collision branch and GPR/prologue shape.
The remaining difference is floating-point load/operation scheduling and a
latency NOP in the position calculation. Parameter snapshots and final XYZ
temporaries can reach588 bytes but change FP allocation/order.

There are78 runner attempts, including two rejected generated declaration
errors corrected in later variants. Tried pointer scope/type, array versus
pointer address spelling, opaque/typed record views, pointer initialization,
time temporaries/compound assignment, index signedness, parameter snapshots,
and position-store order. A120-second single-worker permuter run calibrated
the592-byte parent exactly but retained no improvements; its quiet log does not
report an iteration count. No searched body was installed. The actual
`ModelAnim_SetAnimation` signature returns s32 and takes the tagged model
pointer; using that verified API changes no bytes compared with the legacy
void-return alias in this owner.

Next: capture stock UOPT/UGEN/assembler boundaries for the near-match, then
localize the FP parameter-load delay and temporary-register phase before
another source-shape campaign. Preserve the exact collision branch. The
pre-existing `func_86806044` unused `pad[3]` is a separate source-quality cleanup;
its declaration is now marked FAKE and its behavior is unchanged.
