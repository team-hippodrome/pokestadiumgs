# Region notes: fragment44_20D3A0

## 2026-10-14: func_8AF1F378

The owner receives fourteen real arguments: a destination pointer, four words,
six unsigned bytes, two words, and an aligned source pointer. All three original
call sites were audited: `func_8AF1F978` passes its stack buffer at 0x54, and the
two `func_8AF1FCA4` call sites pass the stack buffer at 0x74. The corresponding
outgoing stack slot is 0x34. The callers do not consume a return value.

The accepted `unk_func_8AF1F378` contains 321 `u32` elements, preserving the
1284-byte copy into destination offset 0x28. The compiler emits the retail
three-word streaming copy loop with no stack frame. Four word stores and six
byte stores retain the original header offsets. Unknown tokens retain address,
argument, and offset names under the separate repository's contributing guide.

Use source order `*(s32 *)arg0 = arg11` before the store of -1 at offset 0x14.
This reproduces the retail instruction order: argument load, sentinel store,
argument store. An initial sentinel-first spelling produced 37 instructions but
swapped t3/t4 allocation and moved the sentinel store ahead of the last byte
store. Its failed source, full build log, and object disassembly are retained
in `work/session-45`. The corrected header order follows the independently
verified sibling recipes and matches all 37 instructions. Do not retry the
sentinel-first or manual pointer-copy-loop families for this owner.

History audit: no exact owner attempt or 20D3A0 regional note was present in
`michiiik/pokestadium-fleet/knowledge-base/gs-attempt-history` at main
`afee707ab78d3f63f2f9deeadc7551ec0080eeed`; unrelated references are not owner
attempts. All open PR scopes were inspected for duplicate owner work.

Independent validation on master `b4ded57db9dbd84a9a209f134f7b72204d97aecb`:
the US ROM rebuilt with default host syntax checks and `COMPARE=1`, then
`md5sum -c baseroms/us/checksum.md5` passed with retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All twelve still-open process matches were
excluded, preserving the already merged #880 source and current foreign
rendering matches. The combined 187-owner workspace also passed. The Public
PR ROM Gate must still validate each current PR head and actual merge result.

## 2026-10-15: func_8AF1F514

Matched the independent 31-instruction sparse-switch owner with a real s16 argument and word boolean result. Both original func_8AF1F5F0 call sites explicitly sign-extend the selected value into a0 and branch on v0. The case set is 29, 30, 31, 113, 115, 124, 238, 241 and 242; initialize var_v1 to zero, set it to one for the shared cases, then return it. IDO emits the original binary decision tree and shared result tail. There is no jump table, padding, additional formal or independent switch-tail owner.

The first source recipe passes the full US build with default host syntax checks and COMPARE=1, followed by explicit md5sum -c baseroms/us/checksum.md5: retail 1561c75d11cedf356a8ddb1a4a5f9d5d. The local combined build also retains the independently verified func_8F102A20 source. Both owners are in separate translation units and separate narrow PRs. No global, helper, data, tooling, layout or verification changes.

Fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed contains no exact/solved owner attempt, owner reference or 20D3A0 region note; historical normalized/raw scores are unavailable. The complete current-master region note above was read. Earlier failed func_8AF1F40C and func_8AF208D0 families remain untouched. All open scopes were inspected; the only source PR was this process's separate func_8F102A20. Unknown names, decimal case constants and var_register locals follow the contributing guide. Source/object/build evidence is retained in work/session-54.

## 2026-10-27 — `func_8AF1F294` tag-gated highlight accepted

`func_8AF1F294(s32 arg0, Func8AF1F130Arg *arg1)` is now C: **57 words / 228
bytes**, frame 0x38. It is the sibling of `func_8AF1F130`. It is active when
`arg1->type` is `'wak1'` and `D_8AF39228 == 0`, or `'wak2'` and
`D_8AF39228 == 1`. For `arg0 == 1` it reads the screen offset with
`func_800504BC` and calls `func_8004B314(x - 5, y - 5, z + 10, w + 10)` (a
rectangle 5 px larger on each side). It always returns 0.

Source shape:
- Write the flag as `if (type == A) { if (D == 0) flag = 1; } else if
  (type == B) { if (D == 1) flag = 1; }`. The then-arm's jump over the
  `else if` is the `b` to the join that the target has right after
  `flag = 1`. Separate `&&` tests (as in `func_8AF1F130`) do not emit it.
- Gate the draw with the sibling's `(arg0 != 0) && (arg0 == 1)`; it yields
  the `beqz` + `bnel` pair.
- Read `z`/`w` into block `s16` locals with `x`/`y`, and use a plain
  `s16 angles[2]` (the sibling's padded scratch struct grows the frame to
  0x40).

## 2026-10-28 — `func_8AF1F490`: requeue

requeue. "Shares a type" predicate: `func_8AF01654(id)` returns a byte with type 1 in the high nibble and type 2 in the low nibble. It returns 1 when any of the four type pairs of `arg0` and `arg1` match. Retail homes both arguments, masks `arg0` (`move a2,a0; andi a0,a2,0xFF`, so `s32`), and reloads `arg1` from its home with `lbu` (a `u8` parameter). The first species' nibbles spill to `sp+0x1E`/`sp+0x1D`. Best 0.9394, with `(s32 arg0, u8 arg1)` and a `u8 types` temp declared first; the remaining differences are `$a0`/`$a1` choices and slot order. The permuter got 265 → 60. Next: K&R-style parameters, or both `arg0` and `arg1` read back from their homes.

## 2026-10-28 — `func_8AF1F1F0`: requeue (shared-`$at` store pair)

Body (sibling style of `func_8AF1F130`/`func_8AF1F294`): extend
`Func8AF1F130Arg` with `u8 pad10[0x10]; void *list;` (0x20, the scroll list
`func_8AF02F18` draws). Use `struct { s32 pad[2]; s16 angles[2]; } scratch;`
for the 0x38 frame. Then, when `arg0 == 1`: `func_800504BC(scratch.angles)`;
block locals `x, y, z, w` (z/w loaded before the stores, as retail does);
`list+8 = x; list+0xC = y; D_8AF395BC = 0; D_8AF395B8 = arg1->type;`;
`func_8AC007B8(x, y, z, w); func_8AF02F18(list); func_8AC00738();`, return 0.
With plain externs, everything matches except one extra `lui $at` before the
`D_8AF395B8` store (retail reuses the `D_8AF395BC` `$at`; the store sits in
the `jal` delay slot).

Ruled out for that residual: file-scope `static` and defined globals (both
are past the image end, at 0x8AF395B8, so they could be pinned like
fragment67). Each still emits the second `lui`. A defined or extern struct or
array CSEs the base into `$v0`. IDO 5.3 (`tools/ido/*/5.3`, already used per
file for C890/C380) also emits the second `lui`, for extern, static and global
alike. This is the same shared-`$at` class as fragment21 `func_82508620` /
`func_82507BFC` / `func_82507C48` and fragment17 `func_822068E0`. Next: the
mechanism must be found once for the whole class, not per owner.
