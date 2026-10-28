# fragment43_1E5A10 matching notes

## func_8AC01F8C

This owner emits the existing display list `D_80094DB8`, writes a horizontal
coordinate to the output record's signed halfword at offset 8, and increments
an unsigned halfword counter. Its phase is the low 16 bits of
`step * (counter & mask)`. Shifting that phase right by 4 indexes the existing
float table `D_80087E50`; the sample is multiplied by the signed amplitude and
added to the signed base coordinate. Conversion truncates toward zero before
the halfword store. The output pointer is captured before the display-list
write, and the counter is read again after the output store, preserving the
original access order when records overlap.

The state view follows the original loads: output pointer at offset 0, base
coordinate at 10, amplitude at 20, counter at 22, step at 24, and mask at 26.
Other bytes remain opaque. The unsigned multiplication makes the phase's
modular arithmetic explicit. The views and extern declarations allocate no
new storage; both display-list and sample-table ownership remain unchanged.

Original `func_8AC02564` obtains this state through its second argument's
pointer at offset 32 and dispatches to this owner with that pointer. Its
initialization path copies the output's coordinates at offsets 8 and 10 into
the state's base coordinates at offsets 10 and 12. Existing C
`func_8AC02770` clears a 48-byte state, stores the output pointer and mode,
and registers `func_8AC02564` through `func_8004E308`. These operations support
the coordinate and state roles; the address-based function name is retained.
//@src/fragments/43/fragment43_1E5A10.c

The first ordinary typed-record and SDK-macro candidate matches all 40 words
(160 instruction bytes), with no stack frame. An explicit unsigned phase
product preserves the same bytes. No new fakes, instruction rewrites, padding,
or data-layout changes are needed.

Fresh verification uses master `dad8c110d74a4d9d5458abdcfa56742d9357b4d8`
plus this source change. The unchanged imported baseline passes first.
`make -W src/fragments/43/fragment43_1E5A10.c -j4 VERSION=us rom` forces the
normal syntax-enabled compilation and complete link. The checksum acceptance
is `build/pokestadiumgs-us.z64: OK`, with ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and
`git diff --check` pass. The complete owner span at ROM
`0x1E797C..0x1E7A1C` independently matches all 160 original bytes.

## func_8AC01354

This owner processes at most the supplied number of 32-byte records. Each
record supplies two signed words at offsets 8 and 12 to `func_8004C874`.
The returned text pointer is stored at offset 16, and its width from
`func_80049148(8, 0, text)` is narrowed into the signed halfword at offset
20. The existing string at `D_8AC07F28` decodes to `"end"`. That sentinel's
pointer and width are populated before the loop stops; the signed-halfword
result counts only records preceding it. Nonpositive limits return zero.

`func_8004C874` returns the text resource through `func_8004C7A0`.
`func_80049148` accepts a signed word font argument and a variadic format
pointer and computes text width. The declarations in this translation unit
now agree with those definitions. The existing `func_8AC06A94` resource
local carries a text pointer, with its compiled instructions unchanged.
`HAL_Strcmp` compares signed character sequences and returns zero on equal
strings.
//@src/4CC20.c
//@src/47580.c
//@src/C180.c

Compiled caller `func_8AF10CD4` passes the existing record arrays and limits
10, 9, 18 and 13, storing the first three signed-halfword results.
`func_8AF10AB8` constructs 32-byte records with resource words at offsets
8 and 12. Original `func_8AC013FC` consumes the text pointer at offset 16
when calculating and drawing the entries. The new view describes only the
accessed fields, leaving the remaining bytes opaque and allocating no data.
The address-based owner and field names remain unchanged.
//@src/fragments/44/fragment44_1FD260.c
//@src/fragments/43/fragment43_1E5A10.c

Advancing the record pointer immediately after saving the string comparison
preserves the original loop schedule. All 42 instruction words, 168 bytes,
and the 48-byte frame match, including ROM `0x1E6D44..0x1E6DEC`.
No fakes, padding, instruction rewrites or layout changes are introduced.

Fresh verification on master
`79adabc72d99147fb5daa4b9fa34230dfbaeff89` plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/43/fragment43_1E5A10.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and complete US link
pass, producing `build/pokestadiumgs-us.z64: OK` and full-ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. The updated unchanged baseline passes its own full build and
retail comparison before this candidate is reapplied.

## 2026-10-27 — `func_8AC06D8C`: matched

`func_8005049C(arg0, arg1)`; on a miss, clear `D_8AC0878C` and store `arg1` in `D_8AC08788`, then return the lookup result. The two stores share one `lui $at`, so the definition carries `#pragma COALESCE_AT_LUI(func_8AC06D8C, D_8AC0878C, D_8AC08788)`; the guard-return spelling schedules differently (0.76).

## 2026-10-27 — `func_8AC00FFC` / `func_8AC01064`: tooling-blocked

tooling-blocked. Pool push/pop trace helpers: `main_pool_push_state(arg0)` (resp. `StageLoader_WaitForRetrace(); main_pool_pop_state(arg0)`), a trace pair `D_8AC0979C = 0; D_8AC09798 = arg0` (resp. `D_8AC097A0`/`D_8AC097A4` before and `D_8AC097AC`/`D_8AC097A8` after the pop), an empty `for (i = 0; i < D_8AC086B8; i++) {}` indentation loop (karodo), and the push/pop of `D_8AC086C0[D_8AC086B8]`. The C is straightforward, but retail shares `$at` across stores that IDO interleaves with unrelated instructions (`lui a1` / `sw ra` between the pair), which is AGENTS.md rule 12's interleaved shape: `COALESCE_AT_LUI` refuses ("no fold applied"). Retry only once the object fold handles interleaved runs.

## 2026-10-27 — `func_8AC0619C`: layout-prerequisite

layout-prerequisite. Sine wobble: `u16 arg1; arg1 <<= 12;` (gives retail's `sw a1,4(sp); sll; andi`), `wave = &D_80088E50[arg1 >> 4]`, `+0x40 = 1.0f - *wave * 0.3f`, `+0x44 = *wave * 0.3f + 1.0f`, `+0x4C = *(s16 *)(arg0 + 0x5A) * 0.5f * (1.0f - +0x44) + +0x54`. With the literal `0.3f` the text matches exactly (1.0 locally); `D_8AC08180` is that literal, one of the file's float literals that splat left in `fragment43_data`. Through `extern f32 D_8AC08180` (or a local copy) IDO swaps `f0`/`f2` and re-reads it (0.79). Needs `fragment43_1E5A10.c`'s literal pool split out of `fragment43_data` as a per-file `.rodata` subsegment first.

## 2026-10-28 — `.rodata` subsegment; `func_8AC0619C`/`06220`/`062A4`/`06328` matched

`rom.yaml` now splits `[0x1EDB60, .rodata, fragments/43/fragment43_1E5A10]` (0.05f ×2 = `D_8AC08170`/`74`, 0.3f ×6 = `D_8AC08178`..`8C`) with the rest of the pool as `fragment43_rodata_tail` from 0x1EDB80. The whole file's literal pool probably starts at 0x1ED840 (strings, `jtbl_8AC08128`/`8144`, `D_8AC0816C`), but only the 16-byte-aligned float block was split; `D_8AC0816C` stays in `fragment43_data`. `func_8AC0602C`/`060E4` now spell their factor as the literal `0.3f`.

The four wobble owners take the `func_8AC0619C` spelling with literal `0.3f`. `062A4`/`06328` are the X-axis twins: `unk48 = unk50 ± unk58 * 0.5f * (1.0f - unk40)`.

`func_8AC05F38` (still assembly) now carries `D_8AC08170`/`74` as `.late_rodata` while `D_8AC0816C` is a data extern. Decompiling it as C needs the split moved down to cover `D_8AC0816C`, which is not 16-byte aligned (0x1EDB5C), or that one literal kept as an extern.

## 2026-10-28 — native US render/menu batch

Four owners were replaced with ordinary compiled C on base
`a3884b41a6c4526790213ca0061ae61f7e603788`:

| Owner | Operation | Instruction bytes | Frame bytes |
| --- | --- | ---: | ---: |
| `func_8AC00028` | Copy eighteen four-byte RGBA records from `D_8AC07BA0` to `D_8AC081B0` | 244 | 0 |
| `func_8AC013FC` | Draw active text entries and record the selected entry's anchor and padded width | 376 | 64 |
| `func_8AC02DA0` | Initialize texture metadata, then load the primary texture and draw its clipped rectangle | 556 | 96 |
| `func_8AC039A4` | Draw a translated rectangle using a duplicated 16-bit RDP fill color | 344 | 80 |

The RGBA copy uses a byte-aligned four-byte record and an unsigned loop index;
IDO performs the loop expansion. The text renderer retains the existing
integer-address parameter ABI and advances that cursor by the actual 32-byte
entry size. Introducing a separate local pointer moves its initial copy later
in the prologue; retaining the argument cursor reproduces the original
schedule. Text entries expose the two signed coordinates, text pointer, state,
and normal/selected color bytes that the assembly accesses. The selected
entry's width is narrowed to a signed halfword after adding 20; the default
result remains -1. The anchor is recorded even for an inactive selected entry.

`func_8AC02D04` initializes the primary image at state offset 16;
`func_8AC02DA0` obtains the second image and reads format, size and dimensions
through the existing texture-header getters. Its draw path updates the signed
halfwords at offsets 12 and 14 from the current origin plus node coordinates,
checks the resulting Y coordinate, and captures rectangle coordinates before
calling `func_80046204`. The right edge uses the second image's width. The
existing callback installers' address-only declarations for `func_8AC02DA0`
and `func_8AC0479C` were retyped as callback prototypes in the same verified
transaction. Parent review removed unused growth-state typedefs; that callback remains assembly.
//@src/fragments/43/fragment43_1E5A10.c
//@src/4CC20.c
//@src/44E70.c

`func_8AC039A4` reads a word at node offset 32 and narrows it to the fill-color
halfword before dispatch. Its callback adds the current origin only in draw
mode. Source operand order matters: node-coordinate plus origin reproduces
the retail load order; origin plus node-coordinate gives four instruction
operand differences despite the same size and normalized opcode sequence.

Each accepted owner passed the canonical runner and a complete US ROM gate
with host syntax checking enabled. Every batch also rebuilt the unchanged
whole module normally and with twenty leading blank lines, comparing all
section bytes, function extents and relocations with the current object.
Native IDO 7.1 compiler SHA256:
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.
The four sealed gates all produced retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The retained worker receipts are
`scratch/copy01/gate-0/receipt.json`, `scratch/text02/gate-0/receipt.json`,
`scratch/rect02/gate-0/receipt.json` and
`scratch/growth-dual02/gate-0/receipt.json`. These are local evidence artifacts;
the repository build remains the reproducibility oracle. No new rewrite,
coalescing, padding, forced-register or data-layout mechanism is used.

### Remaining owners: requeue

- `func_8AC0479C`: typed growth state with separate signed-halfword X/Y
  overshoot temporaries gives 524/524 bytes and a zero-byte frame, normalized
  1.0 but raw 0.6489 (`growth02`, candidate 2). The mismatch is register
  allocation, not acceptance. Next: shorten the output-node pointer lifetime
  and vary center-coordinate assignment order. Preserve the original vertical
  overshoot's write to the horizontal coordinate at node offset 8.
- `func_8AC0036C`: 372/372 bytes and a 56-byte frame; best normalized 0.9247,
  raw 0.8495 (`flags02`). Next: initialize the aggregate flag after the initial
  switch, separate the bit extraction from accumulation, and use the positive
  final guard. A verified `u8 func_800542B0(s32)` declaration must precede its
  existing first caller; declaring it after the earlier implicit call fails
  compilation and is not a source-shape result.
- `func_8AC017B0` / `func_8AC0198C`: 480/492 bytes versus 476/488 retail;
  40-byte frames versus 88. Payload-lifetime variants retain the same gap;
  raw scores 0.7583/0.6016. Next: reuse the incoming argument as the payload
  cursor, then inspect the true `s32 func_8004D1FC(u8 *)` signature in
  `src/4CC20.c` against this file's existing `void` declarations. Any prototype
  correction must also preserve the already-compiled callers through the full
  ROM gate. Do not add filler locals for the frame difference.
- `func_8AC03AFC`: best current 304 bytes versus 300, with the correct 64-byte
  frame; normalized 0.7763, raw 0.1711. Ordinary scalar/aggregate locals,
  callback guard spellings and typed record views retain an unwanted saved
  `s0` and different color/coordinate scheduling. Next: inspect aggregate
  color-copy placement and the pointer lifetime across `func_800504BC`.

Parent review verified texture/text prototypes against their source definitions,
removed the three unused growth-owner typedefs, and preserved the complete
compiler module including +20blank controls. Descriptive callback names keep
the original address-keyed entry names as assembly compatibility aliases.
- `func_8AC00028` → `Fragment43_CopyMenuColors`.
- `func_8AC013FC` → `Fragment43_DrawTextEntries`.
- `func_8AC02DA0` → `Fragment43_DualTextureCallback`.
- `func_8AC039A4` → `Fragment43_FillRectangleCallback`.

## 2026-10-28 — native texture-family follow-up

Four additional genuine C owners passed the same native controls and complete
syntax-enabled retail ROM gate:

| Owner | Instruction bytes | Frame bytes | Sealed local receipt |
| --- | ---: | ---: | --- |
| `func_8AC017B0` | 476 | 88 | `scratch/strip05/gate-0/receipt.json` |
| `func_8AC0198C` | 488 | 88 | `scratch/strip05/gate-0/receipt.json` |
| `func_8AC030EC` | 584 | 96 | `scratch/dual-family01/gate-0/receipt.json` |
| `func_8AC02A34` | 588 | 96 | `scratch/dual02/gate-0/receipt.json` |

The strip callbacks capture their parent coordinates and primary/environment
RGBA components, load the existing texture, then emit an ordinary SDK texture
rectangle. Primary components are full-word locals; environment components
are byte locals. Declaring three primary components before the four coordinate
halfwords, with alpha after them, gives the original coordinate spill offsets
without extra storage. A persistent payload view carries the rectangle fields
across the texture-load call. `func_8AC0198C` starts texture T at
`bottom << 5` and steps it backward with -0x400; `func_8AC017B0` starts at
zero and steps forward. Both use a zero S increment.

The actual definition in `src/4CC20.c` establishes
`s32 func_8004D1FC(u8 *)`; this file's two earlier `void` declarations were
corrected transactionally. The full-ROM gate verifies that existing compiled
callers remain identical after that correction.
//@src/4CC20.c

The two remaining dual-texture callbacks follow the accepted
`func_8AC02DA0` state layout. `func_8AC030EC` additionally copies node offset 4
to `D_8AC07D20`, checks the upper edge against 480 and the lower edge against
zero, and emits the rectangle with S = 64. `func_8AC02A34` loads the second
image with a four-unit horizontal source range, synchronizes the RDP, and
emits its rectangle. Its vertical source coordinate must be spelled
`(height - 1) << 2`: multiplication by four is distributed into a shift then
subtract, producing two different instructions. The final left-shift spelling
matches all 147 words. These callbacks retain the original narrowing and
edge arithmetic, including the distinct height adjustments.

All four receipts again record compiler SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`
and retail ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
The previous strip requeue is resolved by these accepts. The flag callback's
latest candidate (`flags03`/`flags04`) has the same 372 bytes, opcode sequence
and register operands as retail, but a 48-byte rather than 56-byte frame;
its count and unlocked-byte stack slots are two bytes too low. That owner
remains `requeue`; no padding or unused locals were installed.

Parent integration preserves the previously merged callback names and removes
the duplicate inner texture-state type declarations. Unchanged/cleanup and
+20blank controls reproduce the sealed eight-owner module modulo the four
existing compatibility entries. The actual texture loader prototype remains
`s32 func_8004D1FC(u8 *)`. New names preserve old assembly entry aliases.
- `func_8AC017B0` → `Fragment43_DrawForwardTextureStrip`.
- `func_8AC0198C` → `Fragment43_DrawReverseTextureStrip`.
- `func_8AC02A34` → `Fragment43_SecondaryTextureCallback`.
- `func_8AC030EC` → `Fragment43_ClippedTextureCallback`.

## 2026-10-28 — native IA16 loader and growth callback

`func_8AC01160` matches all 125 instruction words (500 bytes, 40-byte frame)
with the ordinary `gDPLoadTextureBlock` macro: IA16, four texels wide and one
row high, clamped in both directions. It emits the existing display list,
sets black primary color with alpha 128, and draws the supplied signed-halfword
rectangle with zero texture-coordinate increments. The first candidate passed;
no manual expansion or output modification is needed. Receipt:
`scratch/loader01/gate-0/receipt.json`.

`func_8AC0479C` matches all 131 words (524 bytes, no stack frame). Its initial
callback saves the original rectangle and target inner dimensions, hides the
optional output node, and centers a 90-by-14 rectangle. Subsequent callbacks
grow each dimension by its corresponding initial size, recenter, clamp the
overshoot, and reveal the output node once neither dimension changes. Inner
dimensions remain eight less than the outer dimensions. The original vertical
overshoot updates X rather than Y; that operation is preserved and labeled
with `//!bug` in the source.

The winning source declares a promoted signed-word dimension first, reads the
width before initializing the signed-halfword progress flag, adjusts a
coordinate before its size, and uses that cached dimension in the size update.
The cached value is read back after the signed-halfword store before testing
overshoot, preserving narrowing. These ordinary lifetime and expression-tree
changes resolve the remaining seven register operands; an earlier 0.9466 raw
candidate was still rejected. Receipt: `scratch/growth07/gate-0/receipt.json`.
The previous growth `requeue` is resolved.

### Final unresolved handoff for this native box

- `func_8AC0036C` — `requeue`: `flags08` candidate
  `progress:remaining-local-order:0312` has 372/372 bytes, the correct 56-byte
  frame and 92/93 exact instruction words (raw 0.9892). Its only difference
  is the initial switch's invalid-mode path loading the uninitialized count
  from stack offset 54 instead of retail's 48. All 24 orders of the four
  existing locals were tested with the corrected bit extraction and guard;
  phase-local scopes, narrower loop counters, bit temporaries and common
  return carriers did not close it. Next: inspect IDO's count-slot allocation
  and the original mode contract for a missing meaningful local or lifetime.
  Keep the source in assembly until the entire function and ROM match;
  adding padding for an undefined-path load was not attempted.
- `func_8AC03AFC` — `requeue`: best normalized 0.7895, raw 0.1974,
  304/300 bytes, 64-byte frame (`rect05`, packed-color-word candidate 1).
  Byte-color records, typed node views, scalar or aggregate coordinate
  locals, branch scopes, packed-word assignment and packed-member assignment
  retain the extra saved node pointer and different load scheduling. Next:
  inspect the pointer's allocation across `func_800504BC` and the aggregate
  copy's IR cost; the callback's actual pointer ABI must remain intact.
- `func_8AC05F38` — `layout-prerequisite` / `requeue`: the first decrement's
  literal at ROM 0x1EDB5C still precedes this file's `.rodata` subsegment at
  0x1EDB60. One externally referenced-literal confirmation gives 244/244 bytes,
  no frame, normalized 1.0 but raw 0.7049; the external load uses f4 instead
  of retail's f12 and advances subsequent float temporaries. Explicit step
  carriers regress to raw 0.6393. Next: coordinator work on ownership of that
  first literal, then retry the ordinary all-literal C form. No shared layout
  input was changed by this worker.
- `func_8AC0202C` / `func_8AC02564` — `layout-prerequisite`: the current
  `.rodata` split covers only the float block. Their tables `jtbl_8AC08128`
  and `jtbl_8AC08144` remain in the shared fragment data. Coordinator table
  ownership and a still-assembly ROM gate precede useful switch probes.
- `func_8AC00FFC` / `func_8AC01064` — `tooling-blocked` under the genuine-C
  constraints: current assembly confirms the retained shared-LUI trace-store
  patterns and empty indentation loops described above. No new probes,
  coalescing, or empty-loop C were installed for them.
- `func_8AC00908`, `func_8AC033B8`, `func_8AC049A8` — `requeue`, not probed
  in this box. They retain 312-, 379- and 1318-instruction assembly owners.
  Next: inspect the bounded rectangle path in the first, then the texture
  draw family in the second; retain the final large owner for a separate box.

The final native verification forces recompilation of this source, including
its host syntax check, and performs the complete US link and retail checksum.
The resulting ROM again has MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
All ten newly compiled owners have canonical `accepted` statistics. The
worker retains `scratch/final-full-gate.log` and `scratch/final-provenance.json`
with the sealed artifacts and detailed manifests for handoff.

Parent integration retains existing semantic names and unifies the texture-state
views already merged. New callback/panel names preserve original assembly
entries through compatibility aliases. Complete normal/+20blank module controls
preserve bytes, extents and relocation topology modulo those aliases.
- `func_8AC01160` → `Fragment43_DrawDarkOverlayRect`.
- `func_8AC0479C` → `Fragment43_GrowthRectCallback`.
Growth state views are now used by the accepted callback. Its original
vertical-overshoot write to X is preserved; no behavior fix is mixed in.

## Native second box after 8da736fd (2026-10-28)

No additional owner accepted. The source, including all ten accepted owners,
remains byte-for-byte identical to `8da736fd`. Twenty canonical batches tested
230 distinct candidates: eight for the documented `func_8AC03AFC` requeue,
112 for `func_8AC00908`, and 110 for `func_8AC033B8`. Every submitted batch
passed the ordinary and +20-blank whole-module controls. A rejected-body
preflight on the initial lifetime batch was corrected by removing the repeated
body; that preflight is not included in these counts. No candidate ran a retail
gate or was installed. `scratch/box2-evidence.json` records exact manifests,
indices, objects, results, frame sizes and separate normalized/raw leaders.

- `func_8AC03AFC` — `requeue`: the materially new hypothesis was a genuinely
  word-aligned origin union, with both coordinate operand orders, aggregate
  color representations and scopes. Best remains 304/300 bytes, frame 64,
  normalized 0.7895/raw 0.1974 (`b2-origin01`, candidate 1). The extra saved
  node register and early color-copy scheduling remain. Next: investigate
  aggregate alias/lifetime allocation across the origin getter using the
  compiler's IR, rather than repeating pointer views or color packing.
- `func_8AC00908` — `requeue`: recovered a clipped 640x480 tiled-background
  path, drawing 16x16 RGBA16 source tiles at 2x scale in 32-pixel screen blocks.
  Source tiles occupy 512 bytes in a 20-column grid. SDK render setup, scissor,
  texture loads, rectangles and final full-screen scissor are represented by
  ordinary SDK macros. Best normalized candidate is
  `b2:clipping:retained-height:5` (`b2-clipping03`, index 5): 1260/1248 bytes,
  frame 72/96, normalized 0.9460/raw 0.3714. Best raw is
  `b2:clipping:height-carrier:0` (`b2-clipping02`, index 0): 1268 bytes,
  frame 64, normalized 0.9401/raw 0.6025. Actual quarter-pixel scissor and
  rectangle locals can reproduce frame 96, without closing the instruction
  schedule. Tested meaningful height captures, clipped endpoint expressions,
  working coordinates, traversal-bound captures, while/guarded-do/for forms,
  tile addressing and row caches, and fixed-point command corners. Retail
  retains height across the right clamp, uses two endpoint copies around the
  scissor, and saves parameter homes only inside an entered inner loop.
  Important correction to the raw m2c draft: horizontal next-edge arithmetic
  is 32-bit (no halfword narrowing instructions); vertical row advancement
  explicitly narrows to s16. Next: inspect allocation/lifetime decisions at
  the scissor-to-traversal boundary and SDK local-scope expansion. Do not add
  filler locals merely to reproduce the 96-byte frame. The corrected s16
  height prototype at the existing 00F04 caller was only a probe companion;
  it was not installed.
- `func_8AC033B8` — `requeue`: recovered the dual scrolling-sampler callback,
  including all four symbolic SDK combine modes, primary/environment colors,
  four signed-halfword UV updates, texture-loader calls and two tile sizes.
  Its payload is an image pointer at +0; UVs at +4..+A; increments +C..+12;
  primary/LOD/environment bytes +14..+1C; four shifts +1D..+20; mode +21;
  four word clamp flags +24..+30. Best normalized candidate is
  `b2:scroll:promoted-load-metadata:4` (`b2-limits-scroll02`, index 12):
  1496/1516 bytes, correct frame 200, normalized 0.9683/raw 0.4749.
  Best raw is `b2:scroll:shared-loader-arguments:0` (`b2-sharedargs01`,
  index 0): 1480 bytes/frame 200, normalized 0.9367/raw 0.7361.
  A direct-node/word-format candidate (`b2-scrollorder01`, index 15) reaches
  1512 bytes/frame 200 and reproduces origin/coordinate/data/dimension slots,
  but still differs in color slots and metadata operations. Neither proximity
  in size nor normalized similarity constitutes a match. Tested declaration
  grouping/order (all 24 metadata orders), real display-list pointer locals,
  direct node accesses, metadata widths and narrowing casts, block lifetimes,
  promoted loader values, branch-local captures, switch dispatch and shared
  first/second-call arguments. Retail loads signed size before display-list
  setup, keeps format in t2 and size in t3, then preserves four promoted word
  values across the first loader call; candidates tend to reload halfwords
  or keep format directly in a3. Next: inspect IDO IR/allocator decisions for
  those values and audit the historical texture-loader declaration against
  its callee. No speculative ABI change was attempted.

Other unresolved owners retain the previous handoff and were not replayed.
In particular, the shared literal/jump-table layout remains parent work.
Private helpers added under scratch decode actual combine fields, run the
read-only m2c clone, capture instruction listings and summarize diagnostics;
none changes compiler output or is part of the commit. Final verification
and sealed artifacts for the unchanged source are retained separately in
`scratch/box2-final-verification/`; first-box receipts remain untouched.

A final `03AFC` batch used a word-aligned RGBA union with named byte channels,
matching the representation documented in `include/229E0.h`, instead of casts
on a packed word or a byte-aligned local record. All eight variants rejected
(`scratch/b2-colorunion01/result.json`), retaining the extra saved node and
unchanged best score. The complete second-box total is therefore 21 batches /
238 candidates, including 16 for `03AFC`; the source remains unchanged.

## Native extended third box checkpoint (2026-10-28, 06:55 target)

The checkpoint verification completed just after the requested time. No owner
accepted: 32 canonical batches recorded 252 attempts (240 byte rejections,
12 compile failures). Source remains identical to `8da736fd`; the ten accepted
function definitions were individually compared with the checkpoint and remain
unchanged. Evidence: `scratch/box3-evidence.json`, `scratch/box3-provenance.json`
and `scratch/box3-final-verification/receipt.json`. A forced native source
rebuild, host syntax check and complete retail-ROM byte comparison passed.
The MD5 remains `1561c75d11cedf356a8ddb1a4a5f9d5d`.

### func_8AC049A8: requeue, substantial new SDK reconstruction

Recovered initialization and rendering for a sliced/scaled image, including
six standard `gSPScisTextureRectangle` paths: normal, X-flipped and Y-flipped
for full strips and a final remainder. The payload has archive/index at
+24/+26, image data +38, retained display list +3C, scale/center/initial-center
floats +40..+54, signed dimensions and slice metadata +58..+68, RGBA +6C,
a signed-halfword allocation flag +70, and a word follow-position flag +74.
It allocates `(count * 10) * sizeof(Gfx) + 112` bytes when retaining a list.
Preserve the existing origin/center calculations and reverse-strip indexing;
this work did not attempt behavioral fixes.

The useful source-shape change was computing full scaled image height beside
full scaled width, before strip height and rectangle positions. This reproduced
the retail float-global allocation (height f0, strip height f2, half f12,
rectangle top f14, quarter-pixel scale f16, rectangle left f18), including the
width spill/reload. Two real pairs of texel-step values, the signed size/format
results, and the image/geometry locals reproduce the known 328-byte frame and
all observed high local slots. No padding, forced registers or output rewriting
was used.

Best normalized candidate:
`scratch/b3-layoutdataflow01/batch.json`, index 0,
`b3:sliced-image:recovered-geometry-local-dataflow:0`:
5276/5272 bytes, frame 328, normalized 0.9939/raw 0.8537. It has one excess nop
in initialization, and differing temporary allocation/scheduling.

Best raw candidate:
`scratch/b3-permuterreview01/batch.json`, index 0,
`b3:sliced-image:reviewed-permuter-center-pair`:
5272/5272 bytes, frame 328, normalized 0.9932/raw 0.9560. This is ordinary
preprocessed SDK C with center Y moved beside center X before the remaining
initialization resets. The instruction counts and all opcode counts agree;
remaining differences include initialization constant scheduling, some SDK
word-store scheduling, operand order on row additions, and compiler spill
slots (e.g. 88 vs retail 96, 80 vs 84, 96 vs 104). Listings are retained at
`scratch/b3-permuterreview01/func_8AC049A8-{actual,expected}.asm`.
This is a rejected near-match, not an accepted C owner.

Other tested families: meaningful screen-edge captures, metadata narrowing
results, block/function texel-step lifetimes, signed/unsigned texture origins,
zero comparison types, explicit reverse-remainder screen offset, declaration
orders, initialization field order, full-image dimension captures, compatible
old-style loader declarations, actual integer loader-address representation,
and signed/unsigned loop-counter widths. None closed the byte mismatch.
Next: investigate frontend lineage between the host-preprocessed SDK form and
the original SDK macro source, then the remaining spill/allocation differences.
The numeric normalized score alone must not be treated as an allocation-only
classification.

Two single-worker, three-minute permuter diagnostics were retained. Restricting
the second to initialization found the independent center-Y reorder above.
A generated empty-loop alternative was explicitly discarded. An initial
permuter parser failure on `sizeof(Gfx)` was repaired by explicit parentheses
in its private input. Its shared entry point overrides TMPDIR; the private
retry calls the unchanged module through an adapter that keeps temporary files
in this worktree. No shared optional-tool source was edited. Canonical probes,
not permuter scores, supplied all mismatch evidence above.

### Older owners

- `func_8AC0036C` — `requeue`: eight new named-mode/extracted-bit lifetime
  candidates leave the previous 92/93-word result unchanged (372 bytes,
  frame 56, normalized 1.0/raw 0.9892). The invalid-mode count load remains
  at +54 instead of +48. Next: a materially new count-storage/lifetime
  hypothesis; do not replay declaration permutations or add filler.
- `func_8AC03AFC` — `requeue`: 32 new candidates tested integer-address
  expressions, unaligned packed-word loads into aligned named-channel unions,
  packed typed node parameters and dispatch-control shapes. Best remains
  normalized 0.7895; the saved node and aggregate-copy schedule remain.
  Next: compiler IR/alias analysis, rather than more packing variants.
- `func_8AC00908` — `requeue`: eight local rectangle/tile record candidates
  did not improve its earlier best. Preserve the second-box handoff.
- `func_8AC033B8` — `requeue`: eight compatible old-style void-loader
  declaration candidates did not close it. Preserve the second-box handoff.
- Literal/table ownership and shared-LUI prerequisites were not replayed.

Parent owns publication, names and shared layout. Only this region note is
committed at this checkpoint; no new C batch is ready for publication.

## 2026-10-28 07:03 UTC — progress-mode requeue resolved

`func_8AC0036C` is accepted as genuine C: 372 bytes, frame 56, complete native
ROM and host syntax gates passed. The winning source declares the live index
first, then a signed-halfword mode snapshot and count, then the two byte flags.
The mode snapshot supplies every dispatch and the progress-bit extraction; it
is neither unused nor padding. This puts the invalid-mode count load at +48
while retaining the flag at +46, closing the last instruction word.

Correction to the preceding handoff: reading the retained third-box objects
shows its first mode-snapshot variant already moved the count from +54 to +52;
raw similarity remained 0.9892 because exactly one word still differed. The
missing combination was the five-local index/mode/count order, rather than
another permutation of the original four locals. Candidate 0 of the first new
batch accepted; seven later alternatives were skipped.

Winner: `scratch/b4-flagslayout01/batch.json`, index 0,
`b4:progress:index-mode-count-storage:0`.
Canonical sealed gate: `scratch/b4-flagslayout01/gate-0/receipt.json`.
A separate forced source rebuild and provenance/previous-ten definition audit
are sealed in `scratch/box4-flags-final-verification/receipt.json`.
Source SHA256: `ce6f8e443877fba98ba8383da1187448f912b59c610663f6c0523b22a79bf279`.
Retail MD5 and native compiler SHA256 remain the values recorded above.
The earlier uninitialized invalid-mode behavior is preserved; valid modes are
0, 1 and 2, with 20/11/11 progress records and reward flags 6/7/8.

The required `u8 func_800542B0(s32)` declaration is placed before its existing
first caller. This changes no earlier function body. All previous ten accepted
C definitions are byte-for-byte unchanged. No new output rewrite, coalescing,
padding or shared input was introduced. Parent owns naming and publication.

Parent integration preserves all previously merged semantic names and real
callback/sound signatures. Full normal/+20blank module controls retain every
allocated byte, extent and relocation topology modulo reviewed aliases.
- `func_8AC0036C` → `Fragment43_TryGrantCompletionReward`.
