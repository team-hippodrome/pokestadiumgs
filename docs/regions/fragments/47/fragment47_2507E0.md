# Fragment 47 image rendering

## 2026-10-27 — owned constant pool and matching slot image

Starting revision `4e92d7a43909a7b47b4f9c4f13dd3bd50ea5cc30` (#1674).
The rendering functions beginning at `func_8600A1C0` move from
`src/fragments/47/fragment47_24E0A0.c` into this source unit. Earlier attempts
and accepted render spellings are documented in that file's region notes.

The aligned text boundary at ROM `0x2507E0` separates the renderer's readonly
pool from the geometry code. Its `.rodata` subsegment spans ROM
`0x253FB0..0x254010` (VMA `0x8600D990..0x8600D9F0`): five signed-short tables
occupy 76 bytes, followed by the fixed-point helper's `0.000488f` bias,
two `0.8f` literals for the slot draw, and `func_8600B100`'s `0.2f` literal
plus four alignment bytes. The geometry up-vector and pi value remain in
the preceding bare rodata segment. This grouping is a verified layout for
C constant ownership; the original translation-unit boundaries are unknown.

Define the tables as constant C arrays, retain the exact stored bias in
`func_8600A1C0`, and re-extract with pinned spimdisasm 1.35.0-dev0. The
extractor gives both remaining assembly draw routines their literal pools
through `.late_rodata`. Gate this layout with `func_8600AB6C` still in
assembly before trying its C body; that baseline reproduces the US retail
ROM byte for byte.

`func_8600AB6C` then passes canonical acceptance and the full retail gate:
344 bytes / 86 instructions, with the original 64-byte frame. It selects a
texture from resource 434 using `D_8600D9A0[slot + variant * 4]`, loads it,
emits the setup display list, draws at the slot's `D_8600D990` coordinates
with dimensions scaled by `0.8f`, emits the closing display list, and calls
`func_87F0D600` with the same slot, coordinates, and scale.

Keep both dimension queries nested in the rectangle call, and access the
coordinate table directly in both calls. Explicit width/height locals add
an eight-byte frame difference; reusing the selector parameter recovers the
frame but leaves a width spill at the wrong offset. Nested calls with direct
table accesses recover the compiler's temporary width spill and position
carrier without source scaffolding. Correct the local texture APIs to the
existing definitions in `src/4CC20.c`: `func_8004D1FC` returns `s32` and takes
`u8*`; both dimension accessors return `s32` and take `u16*`.

Sixteen whole-module controls cover all combinations of declaration cleanup,
pointer/API cleanup, and formatting, each with ordinary and blank-prefixed
sources. Every section byte, extent, and relocation is preserved. A forced
native IDO 7.1 build with the host C check enabled reproduces retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The GS/Stadium 1 maps provide no supported
function rename.

## Remaining owners

- `func_8600A20C` — requeue. The scaled strip routine is 932 bytes / 233
  instructions with a 216-byte frame. Its strongest genuine draft matches
  all opcodes but colors the format selector and saved draw arguments
  differently. Follow the declaration and step-lifetime evidence in the
  predecessor region notes; readonly ownership is now available in this unit.
- `func_8600B100` — requeue. The 552-byte draw routine requires a 72-byte
  frame. Prior drafts with named dimensions require 80 bytes; reducing those
  lifetimes changes the phase-field address allocation. Next test nested
  dimension queries and the newly owned literal pool together, preserving
  both width queries.
- `func_8600B328` — requeue. The 324-byte display-list routine's prior draft
  has 320 bytes and materializes the phase field at `D_8600D408` differently.
  Read the predecessor diagnostics before repeating display-list spellings.
