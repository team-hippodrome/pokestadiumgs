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
