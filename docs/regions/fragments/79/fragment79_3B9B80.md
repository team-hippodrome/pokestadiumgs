# Fragment 79 3B9B80 matching notes

## func_8414C7D4

Accepted recipe: switch on the existing `func_80062D20(arg0)` byte result. Cases 111 and 116 return 3; case 103 returns 2; cases 28, 89 and 144 return 0. The default returns 0 for incoming byte 233 and 1 otherwise. Preserve the real byte argument and word result, unknown function names, and all original behavior. No fake, artificial argument, semantic rename or padding is introduced.

Original `func_8414C858` supplies byte loads in both calls, consumes the full word result, and separately narrows its saved result to a byte. The canonical compiled `func_80062D20` has the actual `u8(u8)` ABI, already declared correctly in this TU. The complete owner has 33 instructions and a 24-byte frame; its six-case comparison chain is independent, with no jump table or shared switch tail.

History audit: live fleet main `afee707ab78d3f63f2f9deeadc7551ec0080eeed` has no exact owner attempt, owner reference or `79_3B9B80` regional document in the consulted catalog. No normalized or raw similarity score is available for this owner. Current master has no document at this regional path. All open scopes were inspected: documentation drafts #922, #932 and #940 cover only their session notes. Original matching PRs #558, #559 and #561 are already merged.

Independent validation against master `21d7fb8c6505eb8e66031331e63eabf8d2d8fe96`: the first switch recipe passed `make rom COMPARE=1 -j2` with default host syntax checks enabled, followed by `md5sum -c baseroms/us/checksum.md5`. Retail MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`. All 201 previous process matches and foreign #941 through #946 remain present. No CI, verification, compiler or layout changes are authored. A fresh current-head and merge-result Public PR ROM Gate must actually run the Build and compare against the retail checksum step before merging; skipped draft checks do not count.

Current-master integration: after foreign #948 advanced master to `e5264768303a56409602fd72f01f029a60d54de1`, the unchanged accepted owner was rebuilt with default host syntax checks and `COMPARE=1`; the explicit retail checksum passed again. The PR was returned to draft before its branch refresh so validation against the old base cannot authorize a merge.

## 2026-10-27 — `func_8414C858`: matched

Comparator: `records = func_84154B0C()` (declared with no parameters, as fragment79_3B7EA0 does); `first = func_8414C7D4((arg0 + 6)[records[0x19A]])`, `second` likewise for `records[0x19B]`; returns 1 if `second < first`, 0 if `first < second`, otherwise whether the `unk_42` halfword of 0xCC-byte record `records[0x19B]` is below that of `records[0x19A]` (`unk_func_84154B0C`). `u8` index locals spill as bytes; `(arg0 + 6)[index]` gives retail's `addu` operand order. `second` is an `s32` narrowed with `(u8)` only in the second comparison, marked `// FAKE` (diff score 120 without it).

## 2026-10-28: func_8414B7BC, func_8414BF94 accepted; func_8414A2F0 requeue

- `func_8414B7BC`: status-damage scale picked by `D_84195200[side][0x24]` flag
  bits (0x20: ×255, 7: ×128, 8 with `[0x11] & 1`: −(byte × factor × 32)). The flags
  byte must be re-read in each condition (a `flags` local adds a frame slot), and
  the last product is written `D_84195208[side][0x14] * func_8414A258()` for the
  `multu v0, t5` operand order.
- `func_8414BF94`: move-usability predicate. The move pointer is
  `(u8 *)((u32)mon + slot)`; `mon + slot` and `&mon[slot]` reverse the `addu`.
  Its tail is `if (move[5] == mon[0x25]) return 0; return 1;`.
- `func_8414A2F0` (requeue, 0.91): the same aligned-DMA record loader as
  fragment84's `func_8FC00FF8`. It takes `(u8 side, volatile u8 index)`, caches
  `index` once (`s32 current = index`) for the 0xFF/0 tests and re-reads the
  parameter for the ROM offset. It `_bzero`s then `_bcopy`s
  `D_841951F8[side] + 0x49C`. Code and frame (0x78, `u8 scratch[0x4C]` at
  0x24) match; only the two spill slots are 8 bytes high (0x20/0x24 vs 0x18/0x1C).
  The file's extern must become `func_8414A2F0(u8, volatile u8)`.

## `func_8414BDA0`: sum enabled record fields

The 272-byte owner calls `func_8414A3A0(func_84154B24())`, then visits
all 24 records of `D_8419D7C0` with a 168-byte stride. When a record's
first byte has bit 0 set, it stores the sum of the words at offsets
12, 16, 20 and 24 into offset 36. Other records retain their previous
word at offset 36. The field meanings remain unresolved.

`func_8414BEB0` invokes this owner after three other record-update
passes. `func_8414BEE8` clears the full 4032-byte array, while
`func_8414A440` and `func_8414A4E4` initialize these component words and
the result word in individual records. The existing helper
`func_8414A3A0` returns the selected side's pointer plus 1180; its result
is unused by this owner, and the call is preserved.
//@src/fragments/79/fragment79_3B9B80.c

`func_84154B24` takes no arguments and returns the unsigned byte at
`D_8419E91A`. The added declaration follows that implementation and is
placed before the translation unit's first caller.
//@src/fragments/79/fragment79_3C40B0.c

The source uses unsigned word addition and a natural 24-iteration loop;
IDO performs the retail four-record unrolling. Writing the terms in the
order 20, 12, 24, 16 emits the inspected load order 16, 20, 12, 24.
No manual unrolling, artificial storage, fake or instruction rewrite
is introduced.

Freshly tested for `VERSION=us` on master
`aeda3404f40c61b6e9d60ed32c0a23d3ea610ed6` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/79/fragment79_3B9B80.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced recompilation and linked the
complete ROM, reporting `build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks passed. Independent original-assembly/raw-ROM comparison verifies
all 68 words at `0x3BB630..0x3BB740`, including the 24-byte frame.
