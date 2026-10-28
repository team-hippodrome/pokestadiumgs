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
