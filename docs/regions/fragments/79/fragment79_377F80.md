# Fragment 79 callback-table reset

## `func_841093E8`

The 120-byte owner clears the byte index `D_841901B4`, all eight words of
each paired table `D_841901C0` and `D_841901E0`, and the words `D_841901AC`
and `D_841901B0`. It then calls `func_84156820`.

Retail `func_8410922C` writes corresponding entries in the two tables and
advances the byte index, wrapping it before a write when it reaches eight.
`func_841092B8` invokes a nonzero first-table entry as a status callback and
clears both entries when the result is nonzero. `func_8410933C` invokes
nonzero second-table entries. These producers and consumers establish the
paired callback storage; the two cleared words retain their unknown names.
All three functions are in `src/fragments/79/fragment79_377F80.c`.

The caller `func_84109460` selects this reset for a nonzero argument.
`func_84156820` in `src/fragments/79/fragment79_3C60B0.c` calls
`func_84169B80` and clears the buffer at `D_8419F070`. These claims come
from inspected C and retail assembly, without runtime observations.

The eight-iteration C loop reproduces the retail unrolling, interleaved
table stores, and 24-byte frame. Existing matched neighbors are unchanged.

## Validation

Tested for `VERSION=us` against master
`e9ed7aa5530752fca01b4d369cda684aeafe87ef` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/79/fragment79_377F80.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced recompilation and linked the
complete US ROM. It reported `build/pokestadiumgs-us.z64: OK`, with ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The retail byte comparison and whitespace
check passed. All 30 instruction words, totaling 120 bytes, match retail.
