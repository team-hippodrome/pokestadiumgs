# Fragment 52 2871C0 matching notes

## 2026-11-03 — packed-color rewrite: requeue

`requeue` **func_86408F84**, 424 bytes, revision `4835fc02`. The first
rewritten word at +0xEC commutes the final RGB/opacity OR; the following
seven words repair the resulting register cascade through the environment
color. A prim-expression root reversal gives the target +0xEC operands but
changes RGB byte-load order. Reversing both roots also changes the env
+0x130 operands. Neither is an exact source replacement.

Eight disjoint-bit expression controls and eight consumed RGB/opacity
lifetime/type controls were compared natively with all eight rewrites
removed. The latter included the normal `gDPSetPrimColor` macro. Named
intermediate RGB values add or move work; unsigned packing and the standard
macro reorder the opacity load. No source is installed and no function is
accepted. Next: inspect the uopt/ugen provenance of the prim root OR and the
subsequent env temporaries; do not repeat the same polynomial reorderings.
Private families: `rewrite-cleanup-f52-colour-packing8` and
`rewrite-cleanup-f52-colour-lifetimes8`.
