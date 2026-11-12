# src/fragments/11/fragment11_D9DE0.c

## 2026-10-28: `func_816089E0` handoff

requeue (0.86). Swaps `D_8160BE80` with `func_8000731C()->+8` when non-zero
and returns the old value. Retail re-forms `D_8160BE80`'s address for every
access; IDO keeps it in `a1` (0.82), and declaring it `volatile` gives 0.86.

## 2026-10-28 — `func_81606800`: requeue, one operand-order residual (0.979)

`if (arg1 != 0 || D_8160BE5C != arg0) { D_8160BE5C = arg0; gDPPipeSync;
arg0 ? (EnvColor 0,0,0,255; PrimColor m=255,l=255, 255,255,255,255) :
(EnvColor 255,255,255,255; PrimColor 255,255, 0,0,0,255); }`, written with
the file's `(*(Gfx **)&D_800D0510)++` (the file declares `D_800D0510` as
`u32`). Everything matches except `beq t6(cached), a0` vs our `beq a0, t6`.
Unchanged by: both operand orders, an early-return or `goto` form, s32/u32/
u8/s16/pointer cache types, pointer/u32 parameters, and a one-line `if`.
A 180-second permuter reached 50 only with macro-expanded one-line layouts.

## 2026-10-29 — whole `.rodata` owned from 0xE3C60; both switches matched

The 0xE3C60 rodata blob belonged entirely to this object. Its `.rodata`
now starts there; the `const u32 D_8160C270[3]` jump-table-tail hack is
gone.

- C-used tables are now in-place `const` definitions: `D_8160C0F0`
  (`s16[16]`; its last word doubles as `D_8160C10C` via `aliases.ld`),
  `D_8160C128`, `D_8160C180`, `D_8160C188`.
- The two empty strings are `""` literals in `func_816087C8`, and
  `D_8160C208` is the literal `0.4f`.
- A zero-initialised `const` scalar does not land in `.rodata`, which is
  why `D_8160C10C` lives inside the array.

Matched:

- `func_81602940`: 28-case switch over `func_8004C990(0x14C, k)`.
- `func_81602C68`: 28-case switch returning data addresses. It needs a K&R
  definition, because the existing caller `func_81602DA4` calls it with no
  arguments, plus a `CC_CHECK`-only argument at that call so the host clang
  check accepts it.


## 2026-11-03 — `func_81606800`: genuine function-local cache match

Accepted: remove the `REWRITE_FUNCTION_WORD` at +0x0C. Stock native IDO 7.1
emits all 48 retail instructions (192 bytes) when the panel color-mode
cache is a function-local `static s32 sPanelColor`, with the condition
`arg1 != 0 || sPanelColor != arg0`. The function still caches the complete
incoming mode, forces an update for nonzero `arg1`, and emits the same
RDP environment/primitive colors for zero and nonzero modes. This replaces
the earlier one-word requeue; a file-scope static did not produce this order.

The cache's initial value is the original loaded zero word at ROM offset
`0xE39FC`, runtime `0x8160BE5C` (`fragment11_data.data.s`). It is inside the
fragment's loaded image, rather than its zero-sized trailing BSS range.
`datamig_bss.ld` consumes this source file's new `.bss` input at the original
cache address before the generated group linker script. This is the existing
NOLOAD placement mechanism: the four-byte C scalar shares the original
loaded word, and the native input section's 12 alignment bytes add no load
image or runtime clearing. `SUBALIGN(4)` preserves the scalar's actual word
alignment; an assertion records the 16-byte native input-section footprint.

Verification: unchanged and candidate modules each reproduce with 20 leading
blank lines. All text bytes and other allocated sections equal the baseline;
only the cache's four relocation endpoints move from the legacy external
label to the new C object's `.bss`. Independently linked unchanged/candidate
controls both reproduce all 192 retail bytes with the cache at `0x8160BE5C`.
Host syntax and normal `make -j1 COMPARE=1 RUN_CC_CHECK=1` pass. Full-ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`.

Every function/storage extent, legacy address and fragment boundary is
preserved. The zero-sized legacy cache label's ELF type changes from `OBJECT`
to `NOTYPE`; the local C cache is the typed object at the same address. The
original data blob is unchanged. No opcode substitution, unused local,
artificial condition, compiler option or coverage update is involved.

## 2026-11-12 — `func_81609A90` rectangle-change flags accepted

`func_81609A90(s16 *arg0, s16 *arg1)` matches **138 instructions / 552
bytes**, leaf, US ROM `0xE1630..0xE1858` (end exclusive). Each input is four
signed halfwords interpreted as x, y, width and height by the comparisons
and area products. `func_8130707C` and `func_8130A8E0` obtain the two
four-halfword interpolated records, then select their order with a mode.
The producer `func_8160945C` interpolates all four components.

//@src/fragments/14/fragment14_FF070.c

A rectangle is inside when x and y exceed 10, x + width is below 630, and
y + height is below 470. With only the second rectangle inside and its
area positive, set high-byte mask 0x80, 0x40 or 0x20 according to the first
rectangle's right edge below 5, left edge at least 636, or neither. The
reverse transition sets 0x10, 0x08 or 0x04 using the second rectangle's
horizontal position. With both inside and either area positive, a second
area greater than `first_area * 1.2f` sets 0x02; the opposite comparison
sets 0x01. Preserve the original disjunction on positive areas.

The new one-byte bitfield view accesses the high byte of the existing
four-byte `D_8160BDF4`; it does not allocate storage. The neighboring
`func_81609CB8` consumes those eight bits, calls `func_800226C0` with the
corresponding IDs and clears the word. Unknown flag names remain. Direct
byte `|=` updates reproduce control flow but leave temporary-register
differences; assigning one-bit fields recovers every retail instruction.
Reversing commutative integer operand spellings preserves retail operand
and load order. No new FAKE code or padding is needed.

Fresh validation on master `222a6b3562fb9b08a7cdcde0a8d6ebb0db9b4c08`
plus this replacement: default syntax-enabled
`make -W src/fragments/11/fragment11_D9DE0.c -j4 VERSION=us rom`, exact
`build/pokestadiumgs-us.z64: OK`, full retail `cmp`, and `git diff --check`
pass. ROM MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`. Reader-only comparison
preserves all module function extents, allocated data/layout and relocation
targets. The 1.2f literal remains at the same pool offset; its relocation
changes from the original local label to the compiler's section symbol.
No storage migration, caller edits, layout, coverage, compiler or CI changes.
