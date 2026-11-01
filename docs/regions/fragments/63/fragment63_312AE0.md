# Region notes -- src/fragments/63/fragment63_312AE0.c

## 2026-10-27 — own `.rodata` subsegment

`yamls/us/rom.yaml` splits the shared `31F000` blob: `0x31F020..0x31F04F`
belongs to `fragment63_310270.c` and `0x31F050..0x31F14F` to
`fragment63_312AE0.c`, followed by a bare `rodata` subsegment at `0x31F150`.
Every label in each range is referenced only by that file. In the linker
script, the leading `31F000.rodata.o` piece now precedes
`fragment63_310270.o(.rodata)` and the trailing piece `31F150.rodata.o`
takes the old blob's place. All assembly owners assemble unchanged (their
tables become per-owner late rodata), so the switch owners in both files can
now be written in C.

## 2026-10-28 — `func_87E0F1C4`: requeue (text reader next char)

`D_87E1EBB8` points at a reader {`s8 *text` @0, `s8 flags` @4 (bit 0 =
active), `s16 pos` @6}. When active and `text != NULL`: read
`c = text[pos]`. If `c & 0x80`, return the two-byte char
`(c << 8) | text[pos + 1]`, advance one byte and reload `c`. If
`c == '<'`, skip to the closing `'>'` (store `pos + 1`, reload, compare) and
return 10. Otherwise return `c`. If the current `c` is 0, clear the active
bit; else store `pos + 1`. Returns u16; the result starts at 0. Retail
keeps the reader base in `$v0`, the result in `$v1`, text in `$a0` and pos
in `$a1`, with one shared exit. A `pos` local (stored, then reloaded with
`lh` after each `sh`) reproduces the structure (~0.2 raw, registers rotated). A typed
`Fragment63TextReader *` global re-reads the pointer after every store, and
the 240-second permuter stays at 750.

## 2026-10-29: `func_87E1087C` register-tie

register-tie. Callback `(s32 *arg0, s32 arg1)`: when arg1 == 0xA8 it registers 'DGP1'..'DGP4' with func_87E102D4 and 'DG_1'..'DG_4' with func_87E0F74C (data 0..3) via func_87F0AB08. The straight-line form matches except that $s0/$s1 are swapped (retail: s0 = callback, s1 = arg0). The permuter reaches 0 only with a fake `if (1) {}` before the last call, which we didn't use. A loop form doesn't get copt-unrolled.

## 2026-11-01 — `func_87E102D4`: requeue, void render callback

The DGP1..DGP4 registrations in `func_87E1087C` pass this function to
`func_87F0AB08`, whose callback type is `void (*)(s32, u8 *)`. Event 0 clears
bit 1 of the node flags; event 1 conditionally draws the node's image and
appends display lists. No return value is consumed.

The current integer return declaration is a matching workaround and is marked
FAKE. `5e64b6db` replaced the two bare returns with switch breaks to satisfy
the host parser. A returned result is not part of the callback protocol;
void functions and explicit value-returning functions elsewhere in this file
must not be labeled as missing-return bugs.

The closest void candidate retains the 556-byte function and differs in four
register fields of the final display-list append (V1 versus V0). Reusing the
image buffer pointer for the first append fixes the final append but moves
the four-field residual to the first append. A new Gfx pointer local adds
eight bytes to the frame; local scopes/declaration order, switch exits, and
compatible old-style definitions do not resolve it. All candidate locals
are used. Preserve the void callback contract in further recovery work.

Private probes preserve the retail-verified module and normal/+20 controls;
they do not establish void C acceptance. The initial permuter fixture gives
the already-matching integer control score 245, so its flat search cannot
establish a source limitation. Next: repair that fixture's residual before
further permuting, or resume the genuine packet-pointer lifetime hypothesis.
Evidence is retained under `scratch/fragment63-void-callback-*` and
`scratch/fragment63-permuter-score-controls-v2`.

Annotation cleanup on `5e64b6db`: before/after module comparisons preserve
section layout, text bytes, function extents and relocation targets, including
a 20-blank-line control. Fresh extraction and the normal native build with
`COMPARE=1 RUN_CC_CHECK=1` reproduce retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. These checks cover the annotations;
the proper void implementation remains unresolved.
