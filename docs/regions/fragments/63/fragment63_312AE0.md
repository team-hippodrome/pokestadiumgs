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
