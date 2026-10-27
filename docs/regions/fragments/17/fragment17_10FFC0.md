# Fragment 17 sine-offset coordinate update

## `func_822017B0`

The 132-byte owner writes three signed halfwords in its record:

- Offset `0x1E` receives the signed-halfword conversion of
  `D_80087E50[phase >> 4] * 10.0f + value_at_0x12`, where phase is the
  unsigned halfword at offset 2. The float converts to a signed word before
  narrowing to a halfword.
- Offset `0x20` receives the halfword at `0x1C` plus the signed-halfword
  difference between offsets `0x18` and `0x10`.
- Offset `0x22` receives the newly stored halfword at `0x1E` plus the
  signed-halfword difference between offsets `0x1A` and `0x12`.

The difference locals preserve narrowing before the additions. The owner
does not advance the phase. `func_82201AE0` in the same source computes a
related set of coordinates from different input halfwords and advances the
phase; it remains unchanged.

`func_82201B70` in `src/fragments/17/fragment17_10FFC0.c` walks four 60-byte
records beginning at `D_8220E378` and selects this owner for mode zero.
Retail `func_82201834` reads the coordinate pair at offsets `0x20` and
`0x22` when changing mode. These observations establish the record stride,
dispatch condition and coordinate handoff. The record's broader role remains
unresolved, so the function and new locals keep unknown names. Claims here
come from inspected C and retail assembly without runtime observations.

## Validation

Tested for `VERSION=us` against master
`4b893d5fe4a6225f86fbbdbb86a3fcc27caa93ce` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/17/fragment17_10FFC0.c -W src/fragments/4/fragment4_AE600.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced source recompilation and linked
the complete US ROM. It reported `build/pokestadiumgs-us.z64: OK`, with ROM
MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. The retail byte comparison and
whitespace check passed. All 33 instruction words, totaling 132 bytes, match
with no stack frame. Fragment 4 was also freshly compiled after restoring
its unsuccessful candidate to assembly. No instruction rewrite was added.

## 2026-10-28: `func_82200C60` handoff

requeue (0.95). Returns 0 if any of the 30 twelve-byte entries
(`+0x24`, s16) in any of the four 0x18C-byte records from `D_8220E4E0` up to
`D_8220EB10` is non-zero, else 1. The do-while with `goto` gets the
structure. Retail keeps the result in `v1` and exits through `b` to the
shared return; IDO tail-duplicates `jr ra; li v0,0`, and the record/end
registers are named differently.
