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

## Remaining batch owners

- `func_81400C24`: requeue after 48 source cells. Best 452-byte parent is
  `fragment12-panels-branch-owned-bounds40-v2` candidate 17, normalized
  0.9823/raw 0.9735. The native differences concern the Y/width argument
  reloads and the default-color address register, plus the expected float
  relocation. Statement/argument assignment mixtures, ternary versus if,
  and ordinary register hints have not closed it. Next inspect the original
  pre-branch Y reload and default-path width reload at the UGEN/as1 boundary.
- `func_81400DE8` and `func_81400FA4`: requeue after 40 source cells each.
  Retail keeps all four inner bounds in S0-S3. Current parents spill them
  while the 128-byte formatted-text buffer is live. Narrowed carriers,
  consumed input snapshots, ordinary register hints, early-return flow,
  buffer signedness/scope and common-bound initialization do not recover
  the combined shape. The earlier highest normalized parents are 0.8559
  and 0.8547, respectively, and are not register-only matches. Next inspect
  whether the three narrowed scissor arguments are already partial-memory
  loads before global allocation, and compare their range costs with the
  accepted choice panels. Do not add padding, unused copies or a fabricated
  scissor/formatter interface.

The repository-wide m2c context failed on an unrelated undeclared
`PackedRecord`; its diagnostic was on stdout, so the draft wrapper's stderr
field appeared empty. A private context with inspected helper signatures
produced all five drafts. The leading owner-local float literals and the
existing per-file rodata subsegment were inspected directly; the file brief's
path adaptation missed those local payloads. Neither tooling diagnostic counts
as a source-shape rejection. The named-baseline follow-up stopped before any
candidate because its old object retained the former symbol names; rebuild
the named baseline before resuming it.

Private receipts are under `scratch/fragment12-panel-preparation`, canonical
batch directories `fragment12-panels-first40`, `fragment12-panels-bounds-lifetimes40`,
`fragment12-panels-scissor-conversions40`, `fragment12-panels-branch-owned-bounds40-v2`,
`fragment12-panel-text-and-args24`, `fragment12-choice-cursor16` and
`fragment12-message-followup24`. Naming controls, the final native seal and
original-word proof use the `fragment12-choice-panels-*` prefix. Private
compiler inputs, scripts and build outputs are not published.
