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
