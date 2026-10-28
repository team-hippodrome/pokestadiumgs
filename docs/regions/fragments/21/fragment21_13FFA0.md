# fragment21_13FFA0 matching notes

## func_825038A4

This one-pointer, void owner reads a data pointer from context offset 12.
The data's first unsigned byte minus 1 supplies the signed loop bound.
For each index below that bound, it reads the bytes at data offsets
`4 + index * 152` and `5 + index * 152`, subtracts 1 from each, and converts
both to signed halfwords. It calls existing `func_82506BEC` with the index,
bound, two converted values, and the pointer from context offset
`28 + index * 4`. A nonpositive bound produces no calls. The context's data
pointer and per-index pointer are read again for each iteration.

Compiled `func_825028E8` and `func_82502924` consume the same data's first
byte and 152-byte stride to read the final pair of metadata bytes minus 1.
Original caller `func_82503F28` passes a 60-byte record selected from
`D_82508D10` and consumes no result. These accesses establish the input,
stride, and unknown data ownership without introducing semantic names.
//@src/fragments/21/fragment21_13FFA0.c

Original `func_82506BEC` receives the first two arguments as words, reads
the next two as signed halfwords, and stores the fifth pointer-bearing
word in its new record at offset 52. It obtains a free record through
`Fragment21_FindFreeRecord`, clears 100 bytes, and writes kind 2 along with
the supplied index and values. This owner preserves the existing helper
body and supplies all five actual arguments.
//@src/fragments/21/fragment21_144790.c

The first candidate reproduces all 44 instruction words (176 bytes), including
the 56-byte frame and the original loop's two independent address strides.
The current region catalog and private ledger contained no prior attempt for
this owner. Existing C remains unchanged. No new storage, fakes, padding,
qualifiers, instruction rewriting, layout, or CI changes are required.

Fresh validation uses master `8c0fa9c2ba73804bf32948c38d8a62aee98c69e0`
plus this patch. The updated unchanged baseline passed its own complete
US check and retail comparison. An unsuccessful lookup trial in `src/674D0.c`
was restored and forced through compilation before acceptance. Final validation
uses the default syntax-enabled Makefile and forces the changed source:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/21/fragment21_13FFA0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 176 bytes at ROM `0x143824..0x1438D4`.

## 2026-10-28: `func_82501034` and `func_82500BC0` accepted; `func_82502854`, `func_82502528` handoffs

- `func_82501034`: the case-1 color copy needs a word-aligned 4-byte color
  struct (`unk_func_82501034`) for both copies. Plain `s32` copies number
  the temporaries two lower.
- `func_82500BC0`: twin of fragment 19's `func_823019F4`. Retail's branch
  layout needs `if (D_82508F7E != 0) { if (index != D_82508F6A) { clear }
  else { set + offset } } else { clear }`, each branch reading the counter
  `D_825087BC` into the reused `arg0`. One of those reads goes through
  `*(s16 *)(D_82508798 + 0x24)` (FAKE) so IDO does not keep the counter's
  address in a register. Mode 0 needs a FAKE `if (arg1) {}` (found by the
  permuter) for its delay slot.
- `func_82502854`: requeue / layout-prerequisite. The archive init stores
  `D_82508D08`, `D_82508D0C` and `D_82508D0E` under one `lui $at`, with `li
  t6,-1` and `lui a0,%hi(D_82508F68)` scheduled above the stores. IDO's own
  order puts them after, so the object-level `COALESCE_AT_LUI` fold (which
  cannot reorder) reaches 148/148 bytes with the wrong order. A struct for
  the three fields gets retail's schedule but a `v1` base instead of `$at`.
- `func_82502528`: requeue. Loops `func_82502404(D_82508D10 + i * 60,
  D_82508D12 + i * 60, state[0], mode, D_82508FD8, i, rec[i].unk26)` over
  `D_82508F84->unk18` records, with `mode` taken from `D_82508FCC/FCE/FD0`
  by state 2/3. Retail reloads `D_82508F84`, `D_82508F68` and `D_82508FD8`
  by symbol every iteration, but tests the bound through the cached state
  base. IDO CSEs all of them into s-registers.

## 2026-10-28: `func_825010F8` accepted; `func_82501490` handoff

- `func_825010F8`: in mode 1, `dy` (held in the reused `arg0`) must be
  computed before the `+0x28` store, together with `dx`. Computing it after
  the store lets IDO hoist the node read instead of the record read (found by
  the permuter).
- `func_82501490`: requeue. The button-gate predicate returns `0x100`/`0x101`
  (mode 1, node kinds 11/14 without bits 1/2), `0x200`/`0x201` (mode 2, kind
  14 with `arg1 == 3`, or kind 15 when `D_82508680->unk2 == 15`, clearing it
  unless `arg4`), and `0x300`/`0x301` (mode 3, unless kind 24; bit 4 clear
  gives `0x300`; with bit 8 clear and all 8 low bits of `D_82508FCE` set,
  `0x301`). Retail returns `result` through an unfolded `v1` at every exit
  and keeps the 8-bit scan rolled with an in-loop `return 0`. IDO
  constant-folds `result = 0` into the exits, and copt unrolls the loop
  unless it breaks out instead (85 vs 82 instructions).

## 2026-10-29 — `func_82501D18`: requeue

Status: **requeue**, best 0.51 (197/197 words). The 2026-10-29 session's body
is `scratch/c/d18b.c`. It is a `switch (state[4])` over cases 0, 1, 2 and 100
on `s16 *state = (s16 *)arg0`, with `s32 index = arg0[0] & 0xFF`:
- Case 0 runs two ease phases (`D_825087DC`, then `D_825087D8`). They write
  `state[8]`/`state[7] = from + ROUND((48 - from) * t)` from `state[0x1C+idx]`
  and `state[0x1A+idx]`, playing sound 0x11C at frame 1. The reset tail plays
  `*(s32 *)(D_82508F84 + 4)`.
- Case 1 fades `state[6] = 255 - ROUND(state[3] * 255.0f / D_825087D4)`. Its
  tail calls `func_82508620()` and
  `func_800225C4(func_80001FF0() * 2)` when bit 8 is set.
- Case 2 is `func_82508670()`; case 100 calls `func_800355E4(*D_82508F84)`
  when bit 0x10 is set.

Remaining:
- In the case-0 second phase, retail emits the product **twice** (`mul.s`
  for the condition and again for the value). IDO CSEs it in every spelling
  tried: a temp `t2`, an inline divide, commuted operands, a `(f32)` cast,
  and `0 < x`.
- Halfword temps are allocated differently (retail keeps `D_825087DC` in
  `$a0` and `from` in `$v0`).
