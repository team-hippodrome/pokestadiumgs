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
transaction. The growth-state views describe the still-assembly callback's
accessed fields and allocate no storage.
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
