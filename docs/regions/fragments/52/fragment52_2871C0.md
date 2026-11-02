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

## 2026-11-03 — SDK palette rendering matched; requeue resolved

**func_86408F84**, 424 bytes, is matched without all eight word rewrites,
based on `1c44f63964f61aa0bfb01606c9445a063f7641ce`. Both palette words
still place red/green/blue in bits 24/16/8 and use context byte 29 for
opacity. The render guard, display-list order, texture lookup and callback
signature are unchanged. The final source uses `_SHIFTL`, `gDPSetColor`,
`gSPSegment` and the existing SDK commands; all nested shift pairs and the
manual command-word blocks are removed. It adds no helper or storage.

The residual existed before AS1. Stock UOPT's displayed graph already has
the original primitive root `OR(alpha_mask, converted_RGB)`; stock UGEN
emits that operand order. This bounds the cause before AS1, without separately
attributing it to CFE lowering versus UOPT reassociation. Six normal/blank
UGEN listing-and-reassembly controls preserve the complete module, and
12 UOPT debug/no-debug controls preserve its optimized Ucode and symbol
files. An initial diagnostic invocation rejected a 134-byte absolute symbol
file path; the same immutable inputs pass via short relative paths. That
invocation failure is not evidence about the source or optimizer.

The useful source change was the combination of the outer OR order and
RGB subtree association. Reversing only the outer OR rotates the component
visitation to blue/red/green. Reassociating the primitive RGB subtree as well
recovers the whole primitive block, but moves the remaining eight-word
residual to the environment root and later temporary reuse. That partial
winner has the same raw mismatch count as the original; retaining it is
what makes the second adjustment apparent. Applying the corresponding
association to the environment expression closes the complete module.

The packed fields are independent byte lanes with no side effects. Reordering
their bitwise OR operations preserves every field value. Post-match controls
replace all components with the SDK byte-field masks, then use the standard
color and segment commands. Both cleanups preserve all retail bytes; the
final code contains no arithmetic no-op, unused local, forced register,
volatile access, manual opcode, false call contract or frame padding.

Known/candidate normal and 20-leading-blank complete-module controls and host
syntax pass. The allocated sections, text bytes, every function extent and
semantic relocations match the baseline. Normal stock native IDO 7.1
`make -j1 COMPARE=1 RUN_CC_CHECK=1` passes with full-ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d` and SHA256
`8160abe7d4b9734317000c44e9f882efefe4cc6359eacded98be62f2811e40a9`.
All legacy addresses and pre-existing objects remain exact. There is no
storage, linker, compiler, build-flag or ABI change; coverage is untouched.
Private receipts: `rewrite-cleanup-f52-colour-stock`,
`rewrite-cleanup-f52-colour-ugen-listing`, `rewrite-cleanup-f52-colour-uopt`,
`rewrite-cleanup-f52-final-controls`, and `rewrite-cleanup-seventeenth-seal`.
The earlier requeue above is resolved.
