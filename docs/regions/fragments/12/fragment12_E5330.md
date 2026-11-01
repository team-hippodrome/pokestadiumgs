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
