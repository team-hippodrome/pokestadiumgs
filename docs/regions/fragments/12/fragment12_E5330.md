# Fragment 12 choice and message panels

## 2026-11-02: two choice panels accepted

`Fragment12_DrawChoicePanel` (`func_81400884`, 115 instructions / 460 bytes)
and `Fragment12_DrawCompactChoicePanel` (`func_81400A50`, 117 / 468) draw a
framed background, two choice rows, a heading and an animated row cursor.
Both retain a 72-byte frame. The compact variant selects font 8 and 26-pixel
rows; the other selects font 16 and 30-pixel rows. Their caller
`func_81404470` selects them for panel types 0/1 and supplies the bounds,
transition fraction, selected row and cursor-phase storage.

Each background branch owns its bounds assignments. Keeping the first row's
lookup result in a consumed `const char *` local recovers the bounds' stack
homes. Once clipping is finished, the horizontal local becomes the label
column and the vertical local becomes the selected row's pixel offset.
The latter closes the final ADDU operand order. All formals and locals are
consumed; no padding, output patch, fake statement or forced register is used.

Canonical acceptance is `fragment12-choice-cursor16`, candidates 3 and 11,
at base `fdf95bb2`. Their float-literal relocations require sequential full-ROM
verification; these are not object-only link-verified hits. Normal host syntax
and the complete retail US ROM comparison pass for both installations.
Naming, formatting, integer-literal style and unused shared-declaration cleanup
preserve every module section, instruction byte, function extent and semantic
relocation in normal and +20-leading-blank builds. Final validation includes
fresh native IDO 7.1 extraction/build and retail-ROM comparison, plus all 232
instruction words checked against original assembly at ROM 0xE5B94/0xE5D60.
Compatibility aliases retain the original address symbols.

## 2026-11-02: all three message panels accepted

| Owner | Behavior-backed name | Instructions / bytes | Frame |
| --- | --- | ---: | ---: |
| `func_81400C24` | `Fragment12_DrawMessagePanel` | 113 / 452 | 64 |
| `func_81400DE8` | `Fragment12_DrawValueMessagePanel` | 111 / 444 | 200 |
| `func_81400FA4` | `Fragment12_DrawCompactValueMessagePanel` | 117 / 468 | 200 |

The message panel fetches text-table 17 entry 8 and lowers messages shorter
than two lines by 15 pixels. The value panels set formatting slot 3 and
render table 17 entry 7 through a real 128-byte text buffer. The caller
`func_81404470` selects these routines for panel types 2/3/4.

All three accept the first `repeated-bounds:explicit-all:earlyFalse` spelling
in `fragment12-repeated-bounds24` (candidates 0/8/16), at base `bb29ff9c`.
Each float relocation is explicitly masked only to permit its sequential
full-ROM gate; none is credited as an object-only link-verified match.
The final gate contains all five accepted panels and passes normal host
syntax and the complete retail US ROM comparison.

### Compiler mechanism

Repeat `x + 8`, `y + 8`, `width - 19`, and `height - 19` in the background
and scissor calls. These are the actual inner bounds; no synthetic operation
or new storage is introduced. Letting UOPT cache those repeated expressions
recovers the original code. Replacing them with explicit named bound locals
had changed the optimizer's representation and the later assembler motion.

For the message panel, the retained Binasm and calibrated assembler trace
showed the named X-bound store before the Y load. Moving Y before the branch
would cross that store; the assembler instead hoisted the default color's
high-half address. Repeated expressions restore the retail Y/width reloads
and color register. In the formatted-value routines, repeated expressions
also recover all four bounds in S0-S3 across the formatter calls. The only
C local needed there is the consumed text buffer. The background calls and
narrowed scissor calls retain their inspected signatures.

Named-local source investigations were bounded: 56 message-panel source
cells and 40 cells per value panel preceded the successful family. A
calibrated 60-second, single-worker search with stack differences enabled
retained score 278 and produced no improved source. Its permitted mutations
were statement/declaration order, commutation and compound assignments;
dummy temporaries, type/interface changes and artificial masks were disabled.
That scoped negative did not rule out the successful expression family.

Naming, integer formatting, string-view casting and duplicate-prototype
removal preserve complete-module sections, instruction bytes, function
extents and semantic relocations under normal/+20-leading-blank builds.
Fresh native IDO 7.1 extraction and a normal host/full-ROM build pass on
merged base `25110a32`; all 341 final instruction words are independently
checked against original assembly. Only C, names/aliases and these notes
are published. Coverage and private tools are unchanged by these PRs.

The repository-wide m2c context failed on an unrelated undeclared
`PackedRecord`; its diagnostic was on stdout, so the draft wrapper's stderr
field appeared empty. A private context with inspected helper signatures
produced all five drafts. The leading owner-local float literals and the
existing per-file rodata subsegment were inspected directly; the file brief's
path adaptation missed those local payloads. Neither tooling diagnostic counts
as a source-shape rejection. An initial named-baseline follow-up stopped before any candidate because
its old object retained former symbol names. After a normal named build,
the eight call-layout cells ran and reproduced the same three-word residual;
they are included in the 56-cell checkpoint above.

Private receipts are under `scratch/fragment12-panel-preparation`, canonical
batch directories `fragment12-panels-first40`, `fragment12-panels-bounds-lifetimes40`,
`fragment12-panels-scissor-conversions40`, `fragment12-panels-branch-owned-bounds40-v2`,
`fragment12-panel-text-and-args24`, `fragment12-choice-cursor16` and
`fragment12-message-followup24`. Naming controls, the final native seal and
original-word proof use the `fragment12-choice-panels-*` prefix. Private
compiler inputs, scripts and build outputs are not published.

The accepted message-family evidence is under `scratch/fragment12-repeated-bounds24`;
normal/+20 naming and prototype controls use `fragment12-message-panels-naming`
and `fragment12-message-panels-dedup`. The final native seal and 341-word
proof use the `fragment12-message-panels-*` prefix. Calibrated pass evidence
is retained in `fragment12-message-stock-passes` and
`fragment12-message-as1-trace`; the bounded search receipt is
`fragment12-message-call-layout8-named-observed-permute.json`.

## 2026-11-02: scrolling footer accepted

`Fragment12_DrawScrollingFooter` (`func_814025E8`) replaces 174 instruction
words / 696 bytes at ROM 0xE78F8 and retains the retail 72-byte frame.
It advances a signed scroll position by two pixels, measures table 17 entry
0/1 plus optional suffix 9, and wraps by that width (plus 286 for the single
copy mode). It draws the bottom frames, icons and labels, clips the moving
text to `(261, 425, 286, 20)`, then restores the full-screen clip. The caller
`func_81400098` supplies both flags.

### Storage and interface mechanism

The scroll word is a function-local static. IDO treats this differently
from a file-scope static or an extern: it emits retail's separate LUI/LW
loads and LUI/store accesses instead of caching the counter address.
The same mechanism is documented in
`docs/regions/fragments/69/fragment69_code.md` for `func_8F100020`.
Check that history before searching ordinary update spellings for this
per-access-LUI pattern. The footer color is also a local static RGBA array,
initialized to `{0, 0, 0, 120}`.

The frame helper `func_816059CC` reads its final argument as four indexed
bytes. Giving that parameter its actual `u8 *` view closes the remaining
color-address spill and restores the frame with ordinary SDK display-list
macros. Its C definition, local forward declaration, and word-interface
wrapper cast are corrected in fragment 11. That module's code, section
bytes, function extents and semantic relocations remain identical under
normal and +20-leading-blank controls. No call argument or return category
is invented.

`rom.yaml` assigns this file the existing data window ROM
`0xECB90..0xECBB0` (VRAM `0x81407880..0x814078A0`). The upper renderer's
30-step state and the lower renderer's two counters retain their global
views while those functions remain in assembly. The footer owns its scroll
and color statics; the existing initialized word 1000 after them is retained
with unknown semantics. All 32 bytes, including natural section alignment,
match retail. No dummy local, manual padding or output rewriting is used.
The original 44-byte readonly footer payload includes an unused
`<LENGTH>%d\n` format; those real bytes are preserved.

The data-only migration first passes the complete retail ROM check with
all three assembly owners retained. Canonical `fragment12-footer-data-promotion4-v2`,
candidate 0, then accepts the SDK-macro/local-static/pointer-argument body
with its paired data-definition edits. Relocation masking permits the
mandatory sequential ROM gate; it is not credited as object-only link
verification. Normal host syntax and the full retail US ROM comparison pass.

The local runner's sequential and combined installation paths interpreted
backslashes in C strings as regex replacement escapes. Literal callback
replacement fixes all three paths; a regression covers exact preservation
and restoration after failure. The defect affected installation of the
existing debug-format payload, not the isolated compiler result. Private
scripts, captures and runner changes are not published with this source PR.
Final naming and formatting have whole-module controls for both source files;
the final native seal and original-word proof use private
`fragment12-footer-*` artifacts.

## 2026-11-02: upper and lower animated panels — requeue

`func_814018F4` (303 words / 1212 bytes, frame 192, ROM 0xE6C04) and
`func_81401DB0` (299 / 1196, frame 184, ROM 0xE70C0) draw upper and lower
animated colored panels. `func_81403CD0` in
`src/fragments/12/fragment12_E7C00.c` chooses their orientation and supplies
the rectangle, type byte, two color addresses and ornament count. The
ornaments use a 75-unit sine phase with 65-unit spacing; opacity spans
50–255 above and 0–255 below. A separate 30-unit state is also advanced.

Function-local static counters reproduce retail's per-access global loads
and stores. A `u8` type parameter restores the initial argument stores and
mask. A consumed explicit phase induction variable restores both frames.
Compound updates of both statics give the best retained spellings in
`fragment12-animated-local-updates8-v2`, candidates 3 and 7: upper 1212
bytes, normalized 0.9868 / raw 0.8383; lower 1196 bytes, normalized 0.9866 /
raw 0.8361. These are layout diagnostics, not accepted C definitions.
The readonly 2-pi literal and actual eight-byte `TextureRenderHeader` are
preserved. The render mode is `G_RM_OPA_SURF | AA_EN | CVG_X_ALPHA |
ALPHA_CVG_SEL`, combined with `G_RM_OPA_SURF2`.

Next action: retain local statics, the byte parameter, compound updates,
and explicit phase induction. Resolve the remaining expression/packet
scheduling differences with complete opcode and relocation views. The
lower renderer's two data words now have C definitions immediately before
its pragma, so paired data companion edits can replace their global views
with the local statics in one canonical transaction. The upper renderer's
first counter is still in the preceding assembly data window; its eventual
migration must preserve a real aligned data range. Do not add padding to a
near-match. Calibration and captured candidates are under private
`fragment12-animated-renderers-*`, `fragment12-animated-local-*`, and
`fragment12-function-static8` paths.
