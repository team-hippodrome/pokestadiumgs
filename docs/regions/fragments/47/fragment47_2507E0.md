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

## 2026-10-27 — writable renderer data and matching animated indicator

Starting revision `25c2218caf5cf506248fe75e53a06215e6b68c06` (#1705).
Give this source unit the 96 writable bytes at ROM `0x253A10..0x253A70`
(VMA `0x8600D3F0..0x8600D450`). They contain the four slot RGBA colors,
white fallback, two initialized animation counters, four further RGBA
entries, the initialized pairs at `D_8600D41C`, and the two colors used by
`func_8600B474`. The consumer of the initialized pairs is unidentified.
The final 12 bytes come from the compiler's normal data-section alignment.
Gate the layout with both animation draw routines still in assembly before
replacing either routine: all 96 data bytes and the complete retail ROM
match. The original source-unit boundaries remain unknown.

`func_8600B328` then passes canonical acceptance: 320 bytes / 80 instructions,
with its original 40-byte frame. It selects a resource-402 image from
`D_8600D9D0[animation_phase / 2]` before advancing the phase modulo 12,
configures translucent rendering with environment alpha 155, and draws at
(129, 29). Preserve the signed arithmetic and the delta from
`func_80008970`. The phase is an initialized function-local static; a
file-global static or a block-local extern produces different address
materialization and scheduling. This replaces the earlier reversed size
note: the target is 320 bytes and the old global-state draft was 324 bytes.

The hold flag comes from `func_87F00930` in
`src/fragments/64/fragment64_3235A0.c`, which shifts the high bit of a byte
to produce a `u32` value of zero or one. `func_86006F20` forwards that result
through `func_8600B474` to the two animation draws. Retype the indicator and
its immediate caller accordingly. The remaining assembly panel draw keeps
its existing pointer declaration pending its own acceptance.

A stale fragment-15 object initially prevented linking. Fresh baseline
extraction and forced fragment-15 and fragment-47 rebuilds restored a
byte-identical baseline; the matched candidate then passed a canonical
full-ROM gate. Sixteen post-acceptance controls cover all combinations of
declaration cleanup, local naming, and formatting with ordinary and
blank-prefixed sources. They preserve section bytes and extents, function
starts and sizes, and normalized relocations. The final forced native IDO
7.1 rebuild with the host C check enabled reproduces US retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Only the indicator's assembly owner is
removed in this batch; the panel and scaled-strip owners remain unresolved.

## 2026-10-27 — matching pulsing panel

Starting revision `a29ec60c889293d946a7845a60868fc66560344d` (indicator batch).
`func_8600B100` passes canonical acceptance and the full US retail ROM gate:
552 bytes / 138 instructions with the original 72-byte frame. It loads
resource 401, image 5; advances a signed phase modulo 32 unless animation
is held; reflects the phase around 16; and computes horizontal growth from
that triangular pulse. It centers the expanded image around x = 138 at
y = 16 and draws with environment alpha 200. Both texture-width queries
remain because they occur at distinct points in the original routine.

As with the indicator, the counter is an initialized function-local static.
Move its existing word at `D_8600D404` into that definition, preserving the
owned writable data byte for byte. The caller's flag is already backed by
the byte-high-bit producer described above; replace the remaining panel
pointer declaration and cast with the actual `u32` flag interface.

Keep a scoped `f32 scale` for the reflected phase multiplied by `0.2f`, and
compute additional width from `((scale * 0.0625f + 1.0f) - 1.0f)` times the
texture width. The addition and subtraction preserve single-precision
rounding in the original instruction sequence. An explicit integer-phase
local matches every opcode and register but spills that phase at 60 rather
than 44. A single float carrier instead shifts two temporary homes. The
scoped scale local recovers the phase temporary at 44, final width at 40,
and additional width at 64 without artificial storage.

Post-acceptance declaration cleanup, static-local naming, and formatting
are checked in all eight combinations with ordinary and blank-prefixed
sources: 16 exact whole-module comparisons of section bytes/extents,
function starts/sizes, and normalized relocations. A forced native IDO 7.1
rebuild with the host C check enabled reproduces retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Only `func_8600A20C` remains an assembly
owner in this rendering unit.
