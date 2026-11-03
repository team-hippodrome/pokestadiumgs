# Region notes: fragment17_1162A0

## 2026-11-04 — scene fade initializer: ordinary C match

`func_822068E0`, now `Fragment17_InitFadeState`, emits all 112 retail bytes
with stock IDO 7.1. The coalescing directive, whole-function replacement and
15 relocation-target directives are removed. The compatibility alias retains
the old ABI name.

The scene owns its actual 0x650-byte runtime state at 0x8220EC40: a resource
word, four halfwords (alpha, fade timer, display countdown and active clipping
buffer), and two clipping buffers. Each buffer contains a halfword count and
100 rectangles, each with four halfwords for x, y, width and height. This is
supported by the clear in the initializer, the renderer's 0x322-byte buffer
stride and eight-byte rectangles, and the constructor in `func_8220792C`,
which enumerates exactly 100 names for each of two buffers. The constructor
appends only successful lookups. The full C object ends at 0x8220F290.

The existing legacy scalar and byte views still address this same storage.
The initializer uses pointers to the real alpha/timer fields, so the compiler
and assembler share the address load and schedule the stores directly. The
new NOLOAD placement consumes exactly 1616 BSS bytes; it inserts no gap fields,
changes no original data-symbol addresses and replaces no instructions or
relocations after compilation. Compiler binaries and flags are unchanged.

The previous combined translation unit could own only two independently
placed data/BSS records; the fade state is a third disjoint object. External
record views and standard common storage were measured and do not reproduce
the initializer. The source is therefore partitioned at the aligned function
boundary 0x822068E0: widget callbacks remain in `fragment17_113A60.c`, while
the complete later scene initialization/rendering/callback region moves here.
All 160 bytes of the former file's read-only data belong to this later region;
the widget module has no read-only section. The scene transition record at
0x822106B2 moves with its users; the widget record at 0x822105E8 stays put.
This is a reconstruction choice, not proof of the original source-file
boundary. Both the YAML and tracked linker script describe the same split.

Validation: normal and 20-leading-blank compilations of both complete modules
match their built objects, including allocated sections, function/object
extents and semantic relocations. All 82 function extents from the former
module, all 261 legacy fragment runtime symbols, and all 17 fragment/loader
boundary symbols remain identical. The linked initializer is 112 bytes and
identical to the original linked body. The normal native build with host
syntax checks and full-ROM comparison passes:

- MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`
- SHA-256: `8160abe7d4b9734317000c44e9f882efefe4cc6359eacded98be62f2811e40a9`

Splat 0.25.0 with spimdisasm 1.35.0-dev0 independently generates the fragment
linker entries from the updated YAML. A fresh isolated fragment extraction
regenerates every referenced assembly path; compiling both modules against
that fresh assembly and linking the full ROM again gives the same retail
hash. Every other C function body is unchanged. Coverage and compiler/tooling sources
are unchanged. Private receipts: `rewrite-cleanup-f17-partition-seal`,
`rewrite-cleanup-f17-partition-final-gate`, and `rewrite-cleanup-f17-split-linker`.
