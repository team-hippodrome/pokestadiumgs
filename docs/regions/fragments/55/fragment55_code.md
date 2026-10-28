# fragment55_code matching notes

## func_8670A404 — accepted C, session 65

The original no-argument initializer is called by original `func_8670A4D4` without outgoing argument setup. It initializes six float fields through a float view of the existing state global, copies the two existing float data values, sets two halfwords, and invokes the canonical one-pointer `func_8003F1DC` seven times. Its compiled definition confirms the pointer/void contract. Existing global declarations and accepted siblings are retained; no invented formals, helper signature, padding or FAKE construct is introduced.

Keep explicit references to existing D_8670C684 and D_8670C688 rather than emitting replacement literal data. The ordinary field stores retain the original pre-frame float/halfword scheduling and the seven actual object addresses. The first candidate matches all 52 original words and the 24-byte frame and preserves the complete retail ROM.

Full fleet fragment55_code history was read. No exact owner attempt or owner-specific recipe exists for A404. The unrelated 0018C .9798 normalized/.7475 raw, 00588 .9625/.8625 and exact-span .9620/.8608, 00418 .9565/.9565, 0427C .9487/.5641, 068EC .8690/.4643, 097D8 .6491/.3246, 08EDC1/.8539 and other recorded plateaus remain excluded. Inspected-only A404 from earlier sessions was not a failed trial; no old failed recipe is replayed.

Validation: default host syntax checks, `make rom COMPARE=1 -j2`, and explicit `md5sum -c baseroms/us/checksum.md5` pass with retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. No CI, verification, tool, layout, data, linker or naming edits belong to this owner change.

## 2026-10-28: `func_86706D3C` and `func_86703E9C` accepted; `func_867036B4` handoff

- `func_86706D3C`: spawns an entry whose `D_86710C20` row is picked by
  `arg0` tier (<3, <6, <9, else 3). It reads `size = D_8670C4FC` into a
  local before the `+0x50` store; the stored `z - D_8670C500` comes first.
  `func_87F025B8`/`func_8003F114` stay implicitly declared, as in
  `func_86706AC8`.
- `func_86703E9C`: `func_87F03884` particle spawn with three
  `func_8003570C` randoms. Declare `rand2`, a FAKE pad, then `rand1` and
  `rand0`, so the spilled `rand0`/`rand1` land at `sp+0x30/0x34` in the 0x40
  frame. The `Row86706A30` typedef now sits at the top of the file so earlier
  owners can index `D_86710C20`.
- `func_867036B4`: requeue / register-tie. Resets rows of
  `D_86711760[group][60]` whose z is below -600 (`func_8003F1DC`, slot pair
  in `D_8670C980` set to -1, z to `D_8670C394`, y to 90). Retail hoists
  -600, the reset z and 90 into `fs0`, `fs1`, `fs2`; IDO orders them
  reset/-600/90 regardless of local declarations. Permuter 200 s: 380 → 300.

## 2026-10-28: `func_8670427C`, `func_867068EC`, `func_8670675C` handoffs

- `func_8670427C`: requeue (0.97). Fades row `D_86710668[i]` alpha (`+0x1D`)
  by 10 per frame for `D_86728408[i]` mode 1 (stop at 70, reset z from
  `D_8670C404`, mode 0) and mode -1 (stop at 20, `func_8003F1DC`), then
  clamps to [5, 200]. Write the `+0x38` store before the mode reset. A FAKE
  `if (!row && !row) {}` after it fixes the `a1`/`a2` roles (permuter). The
  only remaining diff is the `row` spill (retail `sp+0x1C`, IDO `0x18`); any
  extra local grows the frame to 0x30.
- `func_867068EC`: requeue (0.91). Spawns an entry (`func_87F025B8(D_8670D948,
  D_867068E4)`) at `D_8670C04C[arg0 / 2]`, `D_8670C05C`, z from
  `D_8670C060[arg0 odd]`, size `D_8670C4F0`, index from `D_86728408[half] +
  0x50`; `func_87F0DB3C(D_8670D920, half, entry + 0x24)` for even slots.
  Code order matches with `z` assigned right after the `+0x48` store and
  `size` held in a local. The compiler spills (`z`, `half`,
  `entry + 0x24`) land 4 bytes below retail's.
- `func_8670675C`: requeue (0.73). Camera orbit: `D_8670C8A8 = sqrtf(bb.x18² +
  bb.x1C²)` (needs the `BUILD_VERSION` intrinsic), `GeoCamera_SetPerspective(cam,
  D_8670BE7C, 100, 12800)`, then `func_80038E14(cam, cos[pitch] * r + 1,
  sin[yaw] * d, sin[pitch] * r, bb+0x20..0x28, D_8670BE88)` with `r = d *
  cos[yaw]` from `D_80088E50`/`D_80087E50`. Retail keeps the distance in
  `f14` and loads the `D_8670BE84` index first.

## 2026-10-28 native worker: three genuine C owners

Verified from base `a3884b41a6c4526790213ca0061ae61f7e603788` on
`codex/reset-native-stage55-20261028`, using the unmodified native IDO 7.1
compiler, SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.

- `func_8670018C` (396 bytes, 0x38 frame): resource 205 drawing callback.
  The unsigned tick at context +0x14 wraps at 72; the first 36 ticks select
  forward/reverse frames, and later ticks select frame zero. With
  `D_8670B394 == 0`, it adds a random low bit during the later interval and
  increments the tick after drawing. Four used locals in declaration order
  `advance`, `frame`, `resource`, `context` give the retail spill slots.
- `func_86709934` (412 bytes, 0x48 frame): updates three entry pools, cycles
  the resource frame counter modulo six, and processes four banks of 60
  model slots. A live resource index and z <450 cause `func_8003F114` and
  reset the index to -1. `D_8670BB84` and `D_8670BB58` are fields at +0x3C
  and +0x10 of the state rooted at `D_8670BB48`; accessing that containing
  record reproduces retail address generation. Independent scalar accesses
  materialized a different base register. The frame counter is consumed by
  `func_86700318`; the time counter is consumed by `func_86703F9C`.
- `func_8670A790` (476 bytes, 0x40 frame): initializes four rows when the
  incoming context byte +0x2180 equals four, starts the opaque fade, then
  updates the stage until `func_8670A4D4` returns state three. Its existing
  later declaration now returns void. `func_8003F210` uses the integer-return,
  32-bit animation-index contract of its alias `ModelAnim_SetAnimation` in
  `src/340C0.c`; its return is ignored here.

Each candidate batch passed unchanged-module and +20-leading-blank-line
controls over sections, bytes, symbol extents and relocations. Accepted
owners passed sequential full-ROM gates, including relocation-addend
resolution, with host syntax checks enabled. The post-cleanup checkpoint
also passed native `make COMPARE=1 RUN_CC_CHECK=1`; retail MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. No rewrite, schedule patch, forced
register, unused local, padding helper or fabricated argument was added.

Sealed receipts in the worker's private worktree:

- `scratch/b09934-v5/gate-0/receipt.json`
- `scratch/b0018c-v4/gate-0/receipt.json`
- `scratch/b0a790-v2/gate-0/receipt.json`
- `scratch/checkpoint-3/receipt.json` (all three after cleanup)

The checkpoint directory also contains source, object, ELF, map, ROM,
`gate.log` and `provenance.json`. These private artifacts are for parent
integration and are not repository inputs.

### Fourth owner: `func_86708EDC`

The two-case `switch` on `func_87F08208` matches all 356 bytes with the 0x38
frame. Result one selects animation one and speed 0x50000 for four rows;
rows whose state +0x98 equals 206 instead select animation seven, mode ten,
and speed 0x20000. It starts the transparent fade and advances the main
state. Result two writes main-state words +0, +0x30 and +0x48 and starts
the shorter fade. The counter at `D_8670BBB0` wraps after 200.

`func_87F08208`'s result contract is visible in
`src/fragments/64/fragment64_3290A0.c`; the model animation/speed signatures
are visible in `src/340C0.c`, and the clear-color and audio argument widths
in `src/8470.c` and `src/229E0.c`. These existing contracts determine the
prototypes; return categories are not allocation hints.

The individual sealed gate is `scratch/b08edc-v1/gate-0/receipt.json`.
`scratch/checkpoint-4/receipt.json` seals all four owners after formatting
cleanup, with matching retail MD5, the compiler identity above and
`RUN_CC_CHECK=1`. Its `provenance.json` ties every removed pragma to an
accepted canonical-runner result. Coverage and shared symbol/layout files
are unchanged.

Parent review: use a typed external main-state prefix with observed fields
through +0x48. `gStage55MainState = D_8670BB48` is a data compatibility alias;
no storage is allocated. New state accesses use real fields for transition
mode/result and the two float parameters, preserving every module byte,
extent and relocation modulo that alias, including a +20blank control.
Descriptive names keep original address-keyed function entries as aliases.
- `func_8670018C` → `Stage55_DrawAnimatedResource`.
- `func_86708EDC` → `Stage55_UpdateTransition`.
- `func_86709934` → `Stage55_UpdateResourcePools`.
- `func_8670A790` → `Stage55_RunStage`.

## Second native box: `func_8670408C`, `func_8670427C`, `func_867068EC` accepted

Continuation from `422256ef04e13bc5322fd00a7dbd7e68ac24623d`. These three
acceptances supersede their earlier requeue entries. The four owners in
the published checkpoint remain unchanged.

- `func_8670408C`: 496 bytes, 0x28 frame. State modes zero and one emit
  0x9F03 and 0x9F04 at animation frame thresholds 14 and 32, with separate
  latches reset below frame ten. Retain the model pointer, but access the
  exact-stride state array directly; removing the redundant state pointer
  eliminates the extra eight frame bytes. The audio contract is
  `void func_80027A28(u16, u8)`, confirmed by the argument masks in its
  assembly in `asm/us/nonmatchings/229E0/func_80027A28.s`.
- `func_8670427C`: 304 bytes, 0x28 frame. Direct array access eliminates
  both redundant pointer locals and gives the retail pointer registers,
  spill slot and frame. Mode one decrements the byte alpha, clamps it to
  70 at the threshold, restores model scale Z at +0x38 and clears the mode.
  Mode minus one clears alpha and hides the model below its threshold.
  The final tests clamp above 200 to 200 and below five to zero. Byte
  subtraction wraps before comparison. No FAKE branch is needed.
- `func_867068EC`: 324 bytes, 0x38 frame. Inline the repeated `arg0 / 2`
  expressions and model address `entry + 0x24`; the compiler shares them.
  The four used locals are `entry`, Z-table pointer, side selector and
  scale, in that declaration order. This removes the extra frame bytes
  while retaining every measured spill. The side selector remains signed
  `arg0 % 2 == 1`, and the Z-table pointer comparison remains after model
  initialization. Pool stride 0x18C and node offset +0x24 are confirmed by
  `func_87F0252C` and `func_87F025B8` in
  `src/fragments/64/fragment64_324FB0.c`. `D_8670FF54` is modeled as the
  pointer returned by `func_80040E80`, stored in `func_86706E34`.

Sealed individual retail gates, with unmodified IDO 7.1 and host syntax
checks enabled:

- `scratch/box2-0408c-arrays/gate-0/receipt.json`
- `scratch/box2-0427c-local-views/gate-0/receipt.json`
- `scratch/box2-068-inline-half/gate-0/receipt.json`

All three passed full-ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Each
batch also passed the normal and +20blank whole-module byte/section/
extent/relocation controls. The diagnostic `-g3 -keep` build of a retained
068EC candidate is separate: its prologue differs from the production
build and it supplies metadata only, never acceptance evidence.

### Second-box remaining owners and prerequisites

- `func_86708944`: **layout-prerequisite**, superseding the earlier frame
  hypothesis. The genuine literal `0.3f` produces the exact 0x88 frame,
  468-byte extent and all 117 opcode/register rows. The sole raw text
  difference is the vector address: `D_867111C0 + 0x24` versus retail's
  equivalent label `D_867111E4`. The runner rejects it because `.rodata`
  exists only in the candidate object. The section is 16 bytes, aligned to
  16, containing `3E99999A` followed by 12 zero bytes; the corresponding
  retail constant is `D_8670C54C` at ROM 0x2AEA2C. This requires coordinator
  work on pool ownership, ordering and alignment, including neighboring
  constants; adding a four-byte segment alone is not established as safe.
  No layout input was edited and no candidate was installed. Exact body,
  object and result are in `scratch/box2-08944-literal`; section facts are
  sealed in `scratch/box2-08944-layout-handoff.json`. Stop ordinary source
  spelling probes until that prerequisite is addressed and assembly-gated.
- `func_867097D8`: **layout-prerequisite / requeue**. Ordinary array
  initialization emits a new `.data` section, rejected as
  `section_layout_drift`; no layout workaround was installed. The best
  ordinary-loop candidate is 344 versus 348 bytes, normalized 0.9080,
  raw 0.4828, frame 0x28 versus retail 0x30. See
  `scratch/box2-097d8/result.json` and `scratch/box2-097d8.json`.
  Retail copies the four zero words at `D_8670C0D8` and then zeroes the
  local array again. The generated initializer alone does not reproduce
  that second store group. Next: establish original initializer/storage
  ownership and lowering before further source variants. No redundant
  explicit reset or manually unrolled override loop was introduced.
- `func_86700FD4`: **requeue**, a new close sibling. A normal 60-element
  loop automatically emits retail's four-way unrolled search. Best C has
  all search-body instructions and registers correct. The return tail
  still differs: the 592-byte candidate lacks retail's final unreachable
  `jr ra; nop` pair in the 600-byte owner, and its fallback uses the
  equivalent field address `D_86728328 + 0x20` rather than `D_86728348`.
  Raw 0.9800, normalized 0.9867. Other genuine return trees reach 600
  bytes but change reachable tail branches. No source instruction/padding
  helper was added. See `scratch/box2-00fd4-tail/result.json` and
  `scratch/box2-00fd4-tail.json`, candidate `lookup:return-topology:1`;
  `scratch/box2-00fd4-goto` records direct shared-exit variants. No reference
  to the final eight bytes was found in the code/data/symbol scan. Next:
  inspect original owner boundaries and authentic return lowering; do not
  invent an unreferenced empty function to fill the span.
- `func_8670122C`: **requeue**. Complete rank/probability search candidate
  is 664 versus 660 bytes, normalized 0.9699/raw 0.6145. Preheader saved
  registers differ: retail keeps one in s8 and state/result in s4/s5;
  candidate keeps the slot base in s8 and state/result in s5/s4. Correct
  signed rank/probability comparisons and the 150-unit first-rank offset
  are modeled. See `scratch/box2-0122c/result.json` and
  `scratch/box2-0122c.json`, `lookup:ranked:ptrFalse-flagTrue-continueFalse`.
  A direct `D_8670C984` field-symbol view and alternate boolean forms did
  not improve it (`box2-0122c-filter`). Next: inspect preheader invariant
  lifetimes and cached slot-base use with the current real prototypes.
- `func_86706B88`: **requeue**. Complete interpolation callback draft has
  retail's 436-byte extent and no frame, but remains 0.8624 normalized,
  0.5229 raw, with pointer/index register roles and float evaluation order
  differing. It models the tier split, mapped state X offset, node angle,
  lane-progress Z interpolation and +/-600 reset. See
  `scratch/box2-06b88/result.json`, best
  `motion:interpolate:ptrTrue-distanceFalse-xorderFalse`. An explicit root
  snapshot made allocation worse (`box2-06b88-root`). Next: compare the
  expression tree and lifetimes, retaining the actual repeated current-
  object pointer reloads rather than forcing registers.

Post-cleanup second-box gate: `scratch/box2-checkpoint-3/receipt.json`,
with source/object/ELF/map/ROM and `provenance.json` sealed beside it.
Retail MD5 and host syntax checks pass for all seven accepted owners.
`scratch/box2-protected-checkpoint.json` records exact definition hashes
for the four published owners and verifies them unchanged from 422256ef.
Cleanup affects only the three newly accepted definitions and their
unused probe-only type declarations. No coverage, shared layout, symbol,
compiler or core runner files were changed.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_8670408C` → `Stage55_UpdateModelSounds`.
- `func_8670427C` → `Stage55_UpdateModelFade`.
- `func_867068EC` → `Stage55_SpawnVariantEffect`.


## 2026-10-28 third native box: constant-pool and allocation follow-ups

Incremental base is `5e7cad6471536851ced11b976146e12522574243`.
The seven accepted owners in the preceding two boxes remain protected. Parent
owns naming and publication. The extended cutoff for this worker is 06:55 UTC.
All candidate batches retain normal/+20-blank whole-module controls and use the
unmodified native compiler; scores below describe rejected candidates only.

- `func_867036B4`: **layout-prerequisite**. A normal indexed 60-row reset loop
  using the real `3000.0f` boundary matches all 65 text words exactly (260 bytes,
  frame `0x48`). Canonical link verification rejects candidate-only `.rodata`:
  16 bytes, alignment 16, `453b8000000000000000000000000000`.
  The existing literal is `D_8670C394`, ROM `0x2AE874`, bits `453B8000`.
  Do not spend more source spellings before parent fixes constant-pool ownership.
  Exact candidate 0: `scratch/box3-036b4-literal.json`; result and captured
  source/object: `scratch/box3-036b4-literal/`; section facts and hashes:
  `scratch/box3-036b4-layout-handoff.json`. This owner was never installed.
- `func_86702B28`: **requeue**. Genuine four-lane state/model initialization is
  808/808 bytes, frame `0x30`, best normalized `0.9901`, raw `0.9703`.
  Snapshot `D_8670B3C4` after the two calls and use it in both the initial speed
  calculation and lane X positions; that removes the extra two-word reload.
  Initialize state `+0x1C` immediately after `+0x18` to reproduce the float
  constant/register order. Keep ordinary inner loops: IDO supplies the retail
  four-way unroll without manual unrolling. Explicit `clearEnd` and `clear`
  locals initialized end-first improve the remaining setup. Best is candidate 4
  of `scratch/box3-02b28-bounds.json`, with source/object in its result folder.
  Residual: clear iterator/bound `v0`/`v1` roles and their setup; two equivalent
  address spellings are `D_86727CE8+0x640` versus `D_86728328`, and
  `D_86710C20+0x2C` versus `D_86710C4C`. Indexed clearing, pre/post increment,
  reversed comparison, do/while, pointer setup placement, and direct field-label
  references did not close it. Next: use the sealed linked diagnostic controls
  before further allocation experiments, and retain the real 400-word bound.
- `func_8670675C`: **register-tie/requeue**. Best 280/280 bytes, frame `0x28`,
  normalized `1.0`, raw `0.9143`: candidate 4 of
  `scratch/box3-0675c-staged.json`. Compute vertical byte offset before horizontal
  byte offset, copy the global distance into `radius`, then multiply `radius`
  by the horizontal cosine. This fixes the integer angle register roles and
  almost all orbit arithmetic. Remaining words: perspective/global-store setup
  ordering; sqrt destination `f0` versus retail `f14`; reloaded distance `f2`
  versus `f14` and its two uses. Named coordinate snapshots, explicit squared
  distance, shared before/after-call distance locals, byte-offset declaration
  order, and staged cosine-first forms did not close that last float web.
  The original unlinked permuter run is not a controlled compiler result: host
  preprocessing omits `PR/gu.h:196-198`'s `__sgi`-conditional intrinsic pragma.
  The control failure is retained in `scratch/box3-camera-import-control.json`.
  Reproducing that exact SDK `#pragma intrinsic(sqrtf);` in the private diagnostic
  context restores a byte-identical base control and a retail-identical linked
  target. `scratch/linked-permute55-intrinsic.py` also disables synthetic,
  external-type, ABI, padding, and line-grouping mutations. Next: use that sealed
  context before tracing/searching the remaining float web.
- `func_8670122C`: **requeue**. Best remains normalized `0.9699`, 664/660 bytes,
  frame `0x58`; a current-model pointer raises raw score to `0.6928` (candidate 1,
  `scratch/box3-0122c-loop.json`). Candidate caches the slot-table base in `s8`,
  while retail uses `s8` for the initial literal one; state/result are consequently
  `s5`/`s4` instead of `s4`/`s5`. Counted-loop conditions, pointer induction,
  unsigned random chance, flattened slot indices and byte/word address forms
  did not remove the cached base. Next: trace the table-base hoist and initial
  constant allocation rather than replaying these boolean/array spellings.
- `func_86706B88`: **requeue**. Direct global index uses improve the best to
  normalized `0.8716`, raw `0.5872`, 436/436 bytes, leaf frame. Candidate 4 of
  `scratch/box3-06b88-inline.json`; resource-offset snapshots, signed index with
  unsigned comparisons, and nested tier predicates are weaker. Retail keeps
  initial node in `v0`, index in `v1`, then reloads the global node after stores.
  Next: preserve that actual reload behavior while resolving the initial index
  and tier webs; no narrow/fabricated callback arguments.
- `func_86708B18`: **requeue/layout-prerequisite**. The initial exit draft is 968/964
  bytes, normalized `0.9132`, raw `0.6860` (candidate 1,
  `scratch/box3-08b18.json`). The 0/2 mode and sound-latch fields agree with the
  accepted model callbacks; double constants are the existing `D_8670C550` and
  `D_8670C558`. Separate coefficient/coordinate constant snapshots and setup-loop
  index/scale-chain variants were inert. Next hypothesis: compute X before Y
  after storing Z so IDO can overlap the divisor load with double Y arithmetic;
  test indexed state access and a scene-control pointer confined to phase two.
  This hypothesis improved the extern-coefficient draft to 964/964 bytes, frame
  `0x58`, normalized `0.9419`, raw `0.7593` (candidate 1 of
  `scratch/box3-08b18-order.json`). A combined transform/frame model view and
  increment expressions were inert; indexed state access deletes loads retail
  retains. The real coefficients are doubles `-0.13` and `0.1`, respectively,
  at ROM `0x2AEA30`/`0x2AEA38`. Literal-coefficient candidate 0 of
  `scratch/box3-08b18-literal.json` improves to normalized `0.9585`, raw `0.7967`,
  964/964 bytes, but canonical link verification rejects candidate-only `.rodata`.
  It is exactly 16 bytes aligned 16, `bfc0a3d70a3d70a43fb999999999999a`.
  Section facts/captured object: `scratch/box3-08b18-layout-handoff.json`.
  Stop literal variants until parent resolves the shared constant-pool layout.
  Then address first-phase state/secondary-model register roles and the second
  phase's scene/state and double-constant register webs.
- `func_86700418`: **requeue**. A verified minimal model-node view (index `+0x14`,
  Z `+0x2C`) and the real `(s32 reason, void *node)` callback ABI retain the same
  four scheduling differences. Candidate 4 of `scratch/box3-00418-context.json`
  is 368/368 bytes, frame `0x38`, normalized `0.9565`, raw `0.9457`; its extra
  raw difference is the equivalent state-base `+0x50` field reference. Producer:
  `Geo_NodeModelPart` in `src/340C0.c`; node layout in `include/229E0.h`.
  Next: isolate the early lookup/call-argument schedule with the native compiler
  rather than replaying pointer/index/argument-carrier spellings.

Private linked permuter diagnostics keep both an unlinked base control against
its canonical captured object and a linked target control against the exact
retail ROM slice. `scratch/linked-permute55.py` resolves both sides with the
unchanged completed ELF symbol addresses; GNU ld uses the real owner address
and `SUBALIGN(4)` because isolated `.text` defaults to 16-byte alignment while
this owner starts at address `0x86702B28`. The first alignment-control failure
was retained and corrected before searching. No production object/assembly,
compiler, flags, linker files, or source were patched. Do not treat a permuter
score as acceptance; discard synthetic/filler or changed-bound suggestions.


Third-box checkpoint: no additional C owner was accepted. The assigned source
is byte-for-byte identical to `5e7cad64`, SHA256
`32be2d4fa040de959261920dca6272bac5796affd10ff734356758893a5530c3`.
Fresh full native ROM and host-C verification passed; receipt, complete object,
ELF/map/ROM and seven-owner provenance are sealed in
`scratch/box3-checkpoint/`. Retail MD5 remains
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The controlled 300-second linked initializer
search emitted no admissible winner. The corrected ordinary-C camera search
passed both controls and ran for 90 seconds without emitting an improved
candidate; its exact control is in
`scratch/permuter/func_8670675C-ougbje2p/control-receipt.json`, and its result is
`scratch/box3-0675c-linked-intrinsic-result.json`. Prior uncorrected camera
permuter output is excluded as an import-control failure, not a C-reachability
result. `scratch/agent-report.json` contains the final incremental handoff.


## Fourth native continuation: stopped by parent; no new accepted owner

The durable `469f449c` checkpoint and all seven genuine C owners through
`5e7cad64` are unchanged. Parent requested the final stop; all runner and
permuter transactions had completed. No further probe or gate was started for
this handoff. Source SHA256 remains
`32be2d4fa040de959261920dca6272bac5796affd10ff734356758893a5530c3`.
The latest applicable successful production receipt remains
`scratch/box3-checkpoint/receipt.json` (retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, host C checks enabled).

- `func_86700418`: **requeue**. Resumed the oldest actionable continuation with
  a genuinely different callback control-flow family: one-case switch, signed
  or unsigned selector, default return or implicit no-op. Verified real callback
  ABI remains `(s32 reason, void *node)`. Eight canonical candidates retained
  the four early scheduling differences; best 368/368 bytes, frame `0x38`,
  normalized `0.9565`, raw `0.9457` (equivalent field-address addend accounts
  for one raw difference). Exact manifest/result:
  `scratch/box4-00418-switch.json`,
  `scratch/box4-00418-switch/result.json`. A 300-second constrained single-worker
  linked permutation run passed exact unlinked-base and retail-target controls:
  `scratch/permuter/func_86700418-f9p1yrg7/control-receipt.json`.
  Its result is `scratch/box4-00418-linked-permute-result.json`; no admissible
  source winner was emitted. The score-270 suggestion changes a GBI word through
  a float cast and was rejected on source/semantic review, never submitted for
  installation. Next: investigate the initial lookup/call setup schedule with
  native compiler intermediate evidence; do not replay the switch family or
  change the verified callee ABI.
- `func_86701874`: **requeue**. Added a complete genuine steering/prediction
  draft based on its producer in `func_86701C6C` and the adjacent `014C0` routine.
  Prediction input has float old-X/target-Z/target-X/width at `+0/+4/+8/+0xC`,
  slot index `+0x10`, and snapped latch `+0x14`. Slot records have stride `0x10`;
  state stride is `0xAC`, X at `+0x1C`, mode at `+0x2C`. Lane stride is `0x38`,
  gain `+8`, slope limit `+0xC`, direction `+0x18`, integer correction `+0x1C`,
  and last direction `+0x24`. `D_86728340` aliases lane direction; `D_8670BAEC`
  has an eight-byte kind-table stride. SDK `osSyncPrintf(const char *, ...)`
  receives only the existing format and one promoted double: `D_8670C110` is
  `angle=%f`, and `D_8670C11C` is `(angle=%f)`. The apparent leftover `a1` in
  assembly is not an extra printf argument.
  Eight canonical candidates varied lane initialization placement and real
  X/Z snapshots. Best normalized `0.8417`, raw `0.3552`, 1036 versus 1016 bytes,
  frame `0x60`: candidate 0 in `scratch/box4-01874.json` and
  `scratch/box4-01874/result.json`. Candidate 2 has raw `0.3571` but is worse
  overall (1064 bytes, normalized `0.8271`). Captured sources/objects and full
  candidate-0 disassembly are in `scratch/box4-01874/`; the readable dump is
  `scratch/box4-01874-disasm.txt`.
  Decisive next hypothesis, **not tested before the stop**: snapshot the current
  direction once into a real used `s32 direction`, use it both for the last-
  direction store and positive/negative branch. Retail loads that value once
  into `v0`; the draft reloads direction after the global slope-limit store and
  spends `v0` on the lane pointer. This may also resolve lane/state/slot register
  roles. Then stage the angle numerator/division or use separate branch-local
  angle values: retail preserves the angle over printf, whereas the current
  positive branch preserves numerator operands and rematerializes the division.
  Retain actual model-Z refresh behavior and the correct one-double printf ABI;
  add no filler locals or fake arguments.

The fourth-box source did not change. No coverage, shared layout, symbols,
headers, compiler, core tools, push, naming or PR operation belongs to this
handoff. Final machine-readable record: `scratch/agent-report.json`; previous
sealed checkpoints and their reports remain in place.
