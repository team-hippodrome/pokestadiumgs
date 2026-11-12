# `src/fragments/63/fragment63_30B540.c`

## 2026-10-27 — `func_87E07F4C`: requeue

requeue. Maximum of the four words at `arg0 + 0x2190 + i * 0x18`. The plain `max = e0; if (max < e1) …` chain (with a `void *` parameter, as the later prototype requires) reaches 0.95; retail loads `e1` before `e0` and copies `arg0` into `a1` for the last two reads, the signature of a copt-unrolled loop over a pointer copy. Indexed, pointer-walking, `!=` and struct-array loops are all left rolled by copt (0.29–0.42). Next: find the loop shape copt unrolls with an `if` body (see the `for` notes in AGENTS.md §5).

## 2026-10-28 — `func_87E07E38`: requeue, temp-numbering residual

Returns the first of four 0x18-byte slots (base +0x2190) whose `marked` bit
is set (the s16 at +0x16 is negative). The slot must also pass the mode test
on `*(s8 *)(arg0 + 0x218E)`: mode 0 always passes; modes 1 and 2 pass when
the `tested` bit (bit 14 of the word at +0x14) is clear. Finally, its id plus
`*(s8 *)(arg0 + 0x218D)` must reach `*(s32 *)(arg0 + 0x2188)`; otherwise
return -1. The caller `func_87E07F18` must pass `arg0` (it currently calls
with no arguments and relies on `a0`). Best form (40/40 instructions, branch
layout identical): `s32 ret = -1; s32 found = 0; s32 i;`, a `for (i = 0;
i != 4; i++)` loop, `switch` with `case 1: case 2:` (test
`(word << 17) >= 0`) before `case 0:`, and `ret = i; break;`. Returning `i`
directly makes copt unroll the loop twice (71 instructions). Residual: our
temps start at `$t6` where retail's start at `$t7`. A 240-second permuter got
75 -> 25 only by splitting the shift (`<< 11 << 2 << 4`), which hints at a
bitfield read. But a file-level `Fragment63Slot` bitfield indexed through
`(u8 *)arg0 + 0x2190` changes the indexing (0.41).

### `func_87E07E38` matched (2026-10-28, follow-up)

The temp-numbering residual came from the two bit tests. Both must be
unsigned 1-bit extracts, as IDO lowers bitfield reads:
`(u32)*(u16 *)(slot + 0x16) >> 15` for `marked` (retail's `lh`/`bgez`) and
`!(((u32)word << 17) >> 31)` for `tested`. The sign tests `< 0` / `>= 0`
use one temp fewer and shift every later register. The rest of the earlier
best form (`ret`/`found`, `case 1: case 2:` before `case 0:`, `ret = i;
break;`) is unchanged. The caller now passes `arg0`, and the K&R prototype
is retyped.

## 2026-10-29: `func_87E07CD0` tooling-blocked

tooling-blocked (uncached globals, 0.38). Two 30-button cheat sequences: compare D_80087200's pressed buttons against `D_87E1A180[D_87E1A1F8]` and `D_87E1A1BC[D_87E1A1FC]`. On completion it plays 0xCF0C and calls func_87E07CB0 / func_87E07C90; on a mismatch the index resets. The logic matches, but retail re-forms each counter's address with `lui $at` per store, where IDO caches the address in $a1. This is the known per-access global-address shape; no C spelling found yet. Also note: controller.h conflicts with this file's `D_800CE060` byte-array declaration.

## 2026-10-29 — `func_87E09514`: requeue

Status: **requeue**, best ≈0.74 (hand body kept locally as `514_b.c`). The only
structural divergence left is that retail keeps `arg0` in its stack home and
reloads it, while our compile allocates it to `$s0`. A permuter run found
improvements only through fakes (`if (1) {}` / comma expressions), and those
are not acceptable.

Next: make `arg0`'s live range cross a call in the retail order (take its
address once, or reload it through a `volatile`-free local copy declared first).
Alternatively, pass it into the callee chain explicitly.

## 2026-10-29 — `func_87E09F20`: requeue

Status: **requeue**, best 0.9699 (166/166 words). The only diff left is that
retail loads `arg0+0x14` into **`$v1`** in the 0x7B8 == 0x14 block (`lw
v1,0x14(s0)` plus three `beq v1`), where ours uses `$v0`.

Recipe that reaches 0.97:
- Companion edit: `func_87E09BDC` returns `s32` (`return func_87E08E8C(...)`).
  The bytes are unchanged; this function tests its result.
- Locals in order: `sp3C, temp_v0, var_a1, temp_v1, sp2C, var_v1, sp24`, which
  gives the 0x40 frame with sp3C@0x3C, sp2C@0x2C and sp24@0x24.
- Block: `switch (x14) { case 1: case 3: case 4: var_a1 = 0; break; default:
  var_a1 = *(s32 *)(*(u8 **)(arg0+0x20) + 0x2188); break; }`. Only this form
  emits retail's redundant `b`.
- The two rounding macros use the if/else form with `(f32)f() * 2` (an integer
  2) and `(f32)f() / 2.0f`. Writing `* 0.5f` lets IDO share the 0.5f constant
  across branches, which retail does not do.
- Tail: `if (x14 != 3 && x14 != 4) { +4 = 6; func_87E155DC(sp24); EA8(-1);
  F2C(-1); } else { +4 = 7; EA8(0x29); F2C(0); }`, then
  `func_800279C4(0xCF02)`.

Tried for `$v1`, none of which help: a temp for the scrutinee, an if-chain, a
ternary argument, calls split per case, and an `s32` scrutinee. The permuter
can't build this owner yet: it injects the stale `void func_87E09BDC`
prototype next to the companion-edited definition.

## 2026-11-02 — `func_87E07DD0`: remove instruction rewriting

Base revision: `7d0511c4829cce1912c2a5ced28734f343ebbc66`.
The function scans four 24-byte records and returns the first index whose
halfword at `arg0 + 0x21A6 + index * 24` has its high bit set, or -1. Adjacent
`func_87E07E08` counts this same unsigned flag, and `func_87E07E38` uses it
to filter its search. `func_87E088E0` stores the returned index as its
selection. The flag's more specific game meaning remains unresolved.

Decode that bit as `(u32)*(u16 *)address >> 15`, consistently with the
neighboring helpers. Stock IDO emits the retail `lh t7`/`bgezl t7` sequence
directly. This removes both `REWRITE_FUNCTION_WORD` directives at +0x10
and +0x14. Reversing declarations, naming the loaded halfword, changing
index forms and walking an explicit byte cursor did not repair this pair.
The direct mask spelling adds instructions; the unsigned shift is exact.

Four fresh known/candidate normal/+20-leading-blank controls reproduce
the complete module's allocated bytes, section layout, defined extents
and semantic relocations. The function remains 56 bytes; no local,
prototype, compiler flag, padding or assembly owner is added. The normal
host syntax check passes. Exhaustive enumeration of all 65536 halfword
values confirms that the unsigned high-bit test equals the preceding
signed-negative test. After final formatting, two further normal/blank
complete-module controls, normal host syntax, and the full native stock
IDO build pass. Retail ROM MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`.

## `func_87E0A2D4`: confirmation and fade transition

The state-7 handler matches 186 instructions / 744 bytes at US ROM
`0x30DC44..0x30DF2C`, with a 24-byte frame. Caller `func_87E0A620`
increments the unsigned counter at offset 1976 and dispatches this handler.
It updates the children at offsets 1604, 96 and 140 before testing input.
The frame-rate helper returns 50 or 60 according to the video standard.
//@src/dp_intro.c

For phase word 20 equal to 5, the handler issues audio command 80 when
the counter equals the rounded rate times 2. After the counter exceeds
the rounded rate times 0.5, it checks confirmation through
`func_87E09BDC` with a rounded rate-times-2.5 threshold, or through the
shared input helper's `0x8000` bit. Every rounding comparison and selected
rounding arm calls the rate helper separately, preserving the original
call sites and single-precision operations.

`func_87E09BDC` now explicitly returns the `s32` result of
`func_87E08E8C`: it checks the selected port, using port 0 when no slot is
selected, and forwards the selected-port or elapsed-threshold result.
Its bytes remain unchanged. On confirmation, the owner sets state word 4
to 8, issues the existing audio commands, resets the three UI status
values, and starts a 15-frame fade. Otherwise it updates the waiting status.
//@src/fragments/63/fragment63_312AE0.c
//@src/8470.c

The source labels the unchecked shift count with `//!bug`:
`func_87E07ED8` returns -1 when no slot reaches the shared target, and the
owner uses that result in `1 << index` without a range check. The original
MIPS shift uses the low five bits of the count. No new check or behavior
change is introduced. Unknown function and global names are retained.

Validation target: `VERSION=us`, master
`681ed989c17bff34dad6443126730afbcbd64b1d` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/63/fragment63_30B540.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled full build reports exactly
`build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. All 11,824 module text bytes, 272 read-only bytes, 24 register-info
bytes, 51 defined function extents, and 522 semantic relocations equal the
original assembly baseline. The helper and all previously matched C remain
byte-identical; no padding, fixed registers, new data, or instruction rewriting
is used.
