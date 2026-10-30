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

## 2026-10-29: remove the `func_822016C8` byte rewrite

`Fragment17_ResetAnimationEntries` now uses its existing C loop directly.
Remove its whole-function HEX replacement and fourteen relocation-target
directives; the control flow and data operations require no source changes.
The loop resets four 60-byte records, chooses state zero or two from the
input, sets quarter-turn angles, and clears the four following fields.
Keep `func_822016C8` as a compatibility alias.

The apparent object mismatch was relocation spelling alone. The ordinary
loop addresses later records as `D_8220E378 + 60`, `+120`, and `+180`; the
rewrite instead names `D_8220E3B4`, `D_8220E3F0`, and `D_8220E42C` with zero
addends. Exactly five `addiu` immediate words differ before linking, at
function offsets 0x4C, 0x5C, 0x80, 0x90 and 0x9C. Those aliases denote the
same fixed addresses, and the authoritative native full-ROM comparison
passes after all fifteen directives are removed. An object-only comparison
had mistaken equivalent relocation expressions for a source mismatch.

Verification: unchanged/+20-leading-blank whole-module controls; normal
and +20-blank naming controls preserve every module byte/section/function
extent/relocation after normalizing the renamed entry; explicit normal
host syntax; stock IDO 7.1 native full-ROM comparison with retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The private receipt seals the compiled
source, object, ELF, map, ROM and compiler identity. No replacement byte
patch, changed compiler flag, register constraint, padding or added helper
is needed. This cleans an existing C owner and does not add a new owner
to the decompilation totals.


## func_822007D8 — record-counter expiration

This one-pointer, void owner walks 30 twelve-byte records at argument offset
36. For every record whose signed halfword at offset 0 is nonzero, it
increments the signed halfword at offset 2 and clears offset 0 when the
updated value is at least 10. Inactive records retain their counters. The
existing `F822006CC_Particle` view provides both narrow fields; no new type
or storage is needed.

`func_82200694` searches the same 30 records for a zero first halfword.
`func_822006CC` initializes an available record with first halfword 1 and
counter 0, along with its remaining float/coordinate fields. Original
`func_82200E04` calls that initializer at record offset 36 plus an index
times 12, then passes the owning record to this updater and ignores its
result. These producers and consumers establish the active flag, counter,
stride and void interface. Unknown function and field names remain unchanged.
//@src/fragments/17/fragment17_10FFC0.c

The first C trial for this owner matches all 80 instruction words (320
bytes), with no stack frame. The ordinary indexed loop reproduces IDO's
initial two-record peel and subsequent four-record unrolling. Signed-halfword
increment/narrowing and the comparison after the store remain intact. All
previous C and existing assembly owners remain unchanged. No new fake,
unused local, extra storage, padding, instruction rewrite, layout or helper
change is introduced.

Fresh validation on master `0fd5e1868fa3456b2f36c74484ff3ca1bb01a772` plus
this patch follows normal extraction and an exact unchanged baseline. An
unsuccessful sorting candidate was restored and freshly compiled before
this replacement. Final validation forces the changed translation unit
through the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/17/fragment17_10FFC0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Complete retail comparison and whitespace
checks pass. Independent original-assembly and raw-retail comparisons verify
all 320 bytes at ROM `0x110198..0x1102D8`.
