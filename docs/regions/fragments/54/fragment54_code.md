# fragment54_code

## Historical shared-at investigation, 2026-10-28 — resolved below

`D_8660673C = D_86606720 / 60.0f` (stored, reloaded, divided). Then for each of
four records whose `D_8660A9E0` / `AA38` / `AA90` / `AAE8` word is 201, a float
`D_86606750` goes to three adjacent floats (`+8`, `+4`, `+0`, in that order). Retail
gives the `+8` store its own `lui $at`, but the `+4` and `+0` stores share one `lui $at`.
The initial per-statement C did not reproduce this shared address load.
Chained array assignment instead gives a `lui`/`addiu` base plus a reload
(0.38). The later four-player loop and real model ownership resolve this without
coalescing; see the 2026-11-03 evidence below.

## 2026-10-29 — `.rodata` owned; `func_866040B8` matched; `func_86601A04` requeue

`fragment54_data` held this object's `.rodata`. It is now split: `data` up
to 0x2A0800 (the first EUC-JP string, 16-aligned), `fragment54_code`'s
`.rodata` up to 0x2A0AC0 (end of `jtbl_8660715C` plus padding), then a
`fragment54_tail` rodata blob. This unblocks the jump-table owners
`func_86600678`, `func_86601A04`, `func_866044F0`, `func_86605098` and
`func_86605F04`.

`func_866040B8` (frame draw) matched. It follows `Fragment53_DrawSceneFrame`'s
shape. Case 8 must read `D_866067FC`/`D_8660682C` as their own globals.
Spelling them as `&D_86606788 + 0x74/0xA4` swaps `$v0`/`$v1` around the
re-loaded compare.

`func_86601A04` (**requeue**, `scratch/c/a04_best.c`):

- Control flow and frame-11/13 layout are exact. Use the negated form
  `if ((rec3C >= 0x15 && D_866066F4[arg1] == 0) || rec8 == 0) { if (frame == 13) ... } else { 11 }`,
  since retail branches into the frame-11 block. The case -1 path returns
  early, which gives `b .L…C88`.
- The only remaining difference is allocation. Retail keeps `arg1` in `$s1`
  and spills `record` to `0x20(sp)` with a 0x28 frame. Ours spills both.
- A 300 s permuter run only scored better with fake extra uses of `arg1`.
  This confirms `arg1` needs more real references than ours has.
- Next hypothesis: find the missing `arg1` uses, for example per-case
  `D_8660A990 + arg1 * 0x58` re-indexing for some fields, or a
  `(u16)(arg1 + K)` argument as in `func_86601F70`.

### Same day: `func_86605F04`, `func_86605098` matched; `func_866044F0`, `func_86600678` requeue

- `func_86605F04` (state update) matched. It needs
  `s32 StageContext_GetFadeMode(void)`. With the `u8` prototype the `== 1`
  compare comes out as `bne a1,v0` instead of `bne v0,a1`, which suggests the
  original file had no prototype (implicit `int`). The file-level
  declaration is now `s32`.
- `func_86605098` (debug-menu input) matched as written, using
  `ControllerState *D_80087200` (`buttonsPressed`/`buttonsHeld`) and the
  `0.01`/`0.1` double literals. `controller.h` is included at the top of the
  file.
- `func_866044F0` (**requeue**, `scratch/c/4f0_best.c`). With the `s32`
  fade-mode prototype the only difference left is which saved register each
  hoisted constant gets. Retail has `s5=4`, `s3=3`, `s0=2`, `s6=1`; ours has
  `s5=3`, `s3=2`, `s0=4`.
  - Already tried: `switch (i)` (the right shape; an if-chain is worse),
    `1 ==` operand order, else-branch instead of early return, a `rec`
    pointer local, a `for (; i < 4;)` loop.
  - A 300 s permuter run found nothing real.
  - Next: change the use counts of the constants, for example with a
    different rec-value expression or loop bound spelling.
- `func_86600678` (**requeue**, 0.30 raw, `scratch/c/678_best.c`). The
  structure is all written: four player cases, each with an inner switch
  over `rec->x48`, plus the `placed`/`random` locals. Those two are
  deliberately left uninitialised; retail loads them from `0x44/0x48(sp)` on
  entry and stores them back at exit.
  - Retail keeps `399` in `$a3`, re-materialised before the case switch
    every iteration, and `offset` in `$s0`. Ours hoists `399` into `$fp`
    and spills `offset`.
  - Next: find a source shape that keeps the divisor out of the
    loop-invariant pool, then permute.

### 2026-10-29 — `D_866098A0` owned as file-scope bss; `func_86605DCC` matched

`D_866098A0` (four 0x168-byte position records, bss past the ROM image) is
now `static u8 D_866098A0[4 * 0x168]` in this file. It is pinned at
0x866098A0 by `linker_scripts/us/datamig_bss.ld`, the same mechanism as
fragment67's `D_8291B880`. Existing C users are byte-identical, and
assembly users still resolve through `undefined_syms_auto`.

`func_86605DCC` (retry-menu result) matched. The `for (i = 0; i < 4; i++)`
loop is unrolled by `copt`, and retail's shared `lui $at` across each
`+0x34`/`+0x30` pair needs the array defined in this file.

Shared-`$at` owners against other bss here (for example `D_8660A990`
records past 0x86608BC0) can use the same mechanism. `func_86600E00`'s
pairs target `D_86607440..`, previously classified as ROM data in
`fragment54_tail`. The header/loader evidence below corrects that
classification: these loaded words are consumed relocation metadata, and
their runtime addresses are cleared before model setup.

## 2026-11-03 — `func_86600E00` four-player scale refresh: proper C match

All 236 retail bytes now compile directly through stock IDO 7.1. The
whole-function hex replacement, 36 relocation-target patches and coalescing
pragma are removed, together with the artificial `do { ... } while (0)`
block. No requested rewrite/coalescing directive remains in this file.

The code converts the frame counter through the original two stores/reload
at `D_8660673C`, then iterates four players. Each state word is at offset
0x50 of a 0x58-byte record rooted at `D_8660A990`. When that word is 201,
the three model scale fields at +0x38/+0x34/+0x30 receive `D_86606750`.
The loop stays rolled in C; IDO unrolls it and emits the exact retail
address-load sharing and prologue scheduling. The old explicit four-branch
spellings materialized general-purpose base registers or retained the
prologue rotation, even after storage ownership was corrected.

`Fragment54Model` names the existing opaque 0x168-byte model record.
`sPlayerModels[4]` owns the actual four-record array at 0x86607410–0x866079B0.
The existing setup loops in `func_86604370` and `func_86605F04` walk these
records by 0x168 and initialize their model/animation fields. The following
array begins at 0x866079B0. This is an existing allocation, not a collection
of fabricated gaps. The highest scale component retains the canonical
`D_86607410` view; the other two use the owned array. Both views resolve to
the same real model records, and all legacy globals retain their addresses.
The separate existing BSS model array at 0x866098A0 is unchanged.
//@src/fragments/54/fragment54_code.c

The fragment header at ROM 0x299920 says relocation offset 0x71A0, loaded
extent 0x8BC0, RAM extent 0xAB50. Therefore the scale fields overlap the
loaded relocation table, which `Memmap_RelocateFragment` consumes and then
clears through the RAM extent. For example the loaded words at relative
0x7440 are relocation entries, not initial float values. The earlier
classification of these fields as initialized ROM data was incomplete.
The array is explicitly zero-initialized in C and its 1440-byte `.data`
input is pinned by the existing NOLOAD mechanism. Original loaded metadata
bytes and loader behavior remain intact; no RAM/header increase occurs.
A linker assertion checks the array's complete original footprint.
//@src/2CA0.c
//@linker_scripts/us/datamig_bss.ld

Normal and 20-leading-blank known/candidate module controls and host syntax
pass. Cleanup removes 16 unused scalar declarations; fresh normal/blank
controls reproduce the complete module. A native `sizeof` assertion proves
360-byte elements and the 1440-byte array without changing that module.
Both private full-ROM links pass. The normal native
`make -j1 COMPARE=1 RUN_CC_CHECK=1` passes before and after cleanup with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d` and SHA256
`8160abe7d4b9734317000c44e9f882efefe4cc6359eacded98be62f2811e40a9`.
All function extents, legacy addresses and previous object addresses/sizes
are preserved. The 12 unused scale labels and four unused state labels
retain their addresses and size zero, changing inferred ELF type OBJECT
to NOTYPE. Actual C object types, including the existing BSS models, are
preserved. Private link storage verification accounts for the probe-file
qualification of the existing local BSS symbol; both links had already
passed, so that diagnostic correction did not repeat them.

Private receipts: `rewrite-cleanup-f54-scale-controls`,
`rewrite-cleanup-f54-scale-link`, `rewrite-cleanup-f54-final-controls`,
`rewrite-cleanup-twenty-first-seal`, and
`rewrite-cleanup-twenty-first-final-seal`. No compiler flags, output patches,
helper files, forced registers, volatile accesses, dummy operations,
manual unrolling or coverage changes are introduced.
