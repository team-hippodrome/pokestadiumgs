# fragment14_FF070 matching notes

## func_81309820

This one-pointer, void handler reads the signed halfword at offset
`0x137B6`. When it is below 2, it increments that halfword, stores 1 and 2
in the halfwords at `0x137D4` and `0x137D6`, sets the byte at `0x137F5` to
10, and calls existing `func_800226C0(1)`. Otherwise it calls existing
`func_81309740(arg0, 8, 0)`.

Compiled `func_81309928` selects this handler for input mask `0x400` and
ignores its result. Compiled sibling `func_813096B4` decrements the same
signed halfword when nonzero, writes -1 and -2 to the same two halfwords,
and sets the same state byte to 10; its zero branch calls `func_813095C4`.
These shared accesses establish the actual widths and local structure view.
The unknown fields retain their address-based names, and the view allocates
no storage.
//@src/fragments/14/fragment14_FF070.c

Original `func_81309740` receives a context pointer, consumes the second
argument's unsigned low halfword and the third word, updates these transition
fields, and calls other existing context helpers. Existing calls and
declarations are preserved. Original `func_800226C0` constructs its subsequent
call arguments from the incoming selector; this owner supplies only selector
1 and consumes no result.
//@src/229E0.c

The first candidate reproduces all 36 instruction words (144 bytes), including
the 24-byte frame. The current region catalog and private attempt ledger
contained no earlier attempt for this owner. Existing matched C and helper
bodies remain unchanged. No new fakes, padding, qualifiers, instruction
rewriting, storage, layout, or CI changes are required.

Fresh validation uses master `0acfa5069e1b3a1b796d209bf7c4a8a2e4e51071`
plus this patch. The updated unchanged baseline passed its own complete US
build and retail comparison after normal extraction. An unsuccessful trial
in fragment 37 was restored and forced through compilation before acceptance.
Final validation forces the changed source through the default syntax-enabled
Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/14/fragment14_FF070.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 144 bytes at ROM `0x1019B0..0x101A40`.

## 2026-10-27 — `func_81308014`: matched

`D_81311F80 += func_816092FC(); if (D_81311F80 > 30.0f) { D_81311F80 -= 30.0f; return 1; } return 0;`. Retail's three separate `lui $at` reloads of `D_81311F80` come from a function-scope `static f32 D_81311F80 = 0.0f`: IDO CSEs the address into a register for an `extern` or a file-scope static, but not for a function-scope static. The static needs this object to own the 16 bytes at 0x81311F80, so `yamls/us/rom.yaml` splits `fragment14_data` there (`[0x10A110, .data, fragments/14/fragment14_FF070]`, then an unnamed `[0x10A120, data]`). IDO pads the section to 16 bytes, so the three unreferenced words at 0x81311F84-0x81311F8C are defined after the function as `D_81311F84[2]` and `D_81311F8C`; IDO emits the function-scope static first only when those definitions follow the function.

## 2026-10-27 — `func_81307228`: layout-prerequisite

layout-prerequisite. A 12-case switch on `*(u8 *)(arg0 + 0x137F5)`, after a `+0x137D0 < 16.0f` early 0, returning 0/1. Its table `jtbl_81312564` sits in the shared `rodata` blob at `0x10A6D0`, below `fragment14_FF070`'s current `.rodata` subsegment (`0x10A7D0`); extend the subsegment down (every label in the run must be this file's) before writing the switch.

## 2026-10-28: `func_8130AEF4` prototype; `func_8130B06C` handoff

- `func_8130AEF4` takes an `s32` third argument: the callee tests it with
  `bltz`. Declaring it `u8` made every caller mask with `andi 0xFF`.
- `func_8130B06C`: requeue (normalized 1.0, frame only). It is the
  increment twin of `func_8130B0E0`: `count = base[0x6911]`; if below 8,
  store `count + 1`, advance the `+0xE8E8` node to its `+0x4D98` successor,
  and call `func_8130AEF4(arg0, func_8160A33C(node, 2), count' + 2)`.
  With the sibling's spelling and an inline last argument, every instruction
  matches except the frame: 0x30 vs retail's 0x20, because the named
  `base`/`store_base` locals reserve slots. Neither declaration order nor the
  stack-aware permuter (200 s) fixes it.

## 2026-10-28 — `func_8130B06C` matched; `func_8130B0E0` cleaned

Both read a real state struct (`unk_func_8130B06C`: current node at 0xE8E8, index byte at 0xE911) and node struct (`unk_D_8130B06C_node`: predecessor 0x4D94, successor 0x4D98). With typed fields IDO forms the two large-offset bases itself (`a0 + 0x8000` for loads, `a0 + 0x7FFF` for stores) and keeps the 0x20 frame. The named `base`/`store_base` locals were what cost the extra 0x10. `func_8130B0E0`'s permuter body (`new_var`, `((0, 0x7FFF))`) is replaced by the plain decrement twin, byte-identical.

## 2026-10-28 — `func_8130AF94` matched

It links the state's three inline 0x4DA0-byte nodes (`unk_0008[3]`, ending exactly at the current-node pointer at 0xE8E8) into a ring. For each `i` it calls `func_8130AEF4(state, &node[i], index + i)`, sets the predecessor (`node[2]` when `i <= 0`) and the successor (`node[0]` when `i + 1 >= 3`), then makes `node[0]` current. Those condition polarities give retail's `bgtz`/`bnez` (`i == 0` gives `bne`; the positive forms swap the hoisted constants). The `func_8130AF94` externs take the typed state.

`func_8130AEF4` (requeue): with the same types, `count = func_81302290(state->unk_E8EC)`, `func_8160B8A8(node, func_813002D0(state->unk_E8EC), 0)`, then `func_8160A438(node, state->unk_E8EC->unk_1A148->unk_944)` when `0 <= arg2 < count`, else `func_8160A994(node)`, then `func_8160A6AC(node)`. Normalized 1.0: everything matches except that retail reloads `arg2` from its home into `$a2` and IDO uses `$v0`. Condition spellings and a 240 s permuter did not move it.

## 2026-10-28 — `func_8130B3B8` matched; `func_8130A98C` returns `f32`

`func_8130B3B8(state, out)` fills `out` through `func_8160945C(out, colorA, colorB, scale)` and returns the scale:
- `scale = D_8160BD08(state->unk_E8F0 / 16)`, `colorA = state->unk_0000` (the state's first 8 bytes are a default `s16[4]` color), `colorB = func_81609530(1)`;
- when `unk_E8FC > 0`: scale from `func_8130A98C(state)`, colors 1/6, return 1.0;
- otherwise, for mode 12/13 with `unk_E913 == 0` and `unk_E90C != 1`, `colorA = func_81609530(unk_E908 ? 10 : 3)`.

Spelling notes:
- the divisor is the integer `16` (`16.0f` becomes a multiply by 0.0625);
- locals are declared `scale`, `colorA`, `colorB`;
- `colorA` is assigned after the scale call.

`func_8130A98C` was declared `void` but returns `D_8160BD1C(...)`'s float. Its two callers' 8-byte buffers are now `s16[4]`, and `func_81609A90` takes `s16 *`.

## 2026-10-28 — `func_8130BDB8` and `func_8130AAA8` matched

Both use the typed state (now through 0xE915, with `unk_E8EC` typed as the pointer `func_8130AEF4` reads).
- `func_8130BDB8`: `unk_E900 += func_816092FC()`. At 120 it clamps, and if the record's six bytes at 0xB are all zero it sets `unk_E904 = 0`, mode `unk_E912 = 9`, plays sound 0xA8 and calls `func_8160A780(unk_E8EC->unk_1A148->unk_944, unk_E911 + unk_E914)`. Below 120 it draws `min(unk_E900 * 9 / 120, 6)` steps with `func_8160B9A0(record, 5 - i, 1)`. The two loops use separate counters (`i` for the draw loop, `j` for the byte scan). One shared counter puts the scan in a saved register.
- `func_8130AAA8(state, x, y)` interpolates between `166 * y + 128` and a target. The target is `(x - unk_E915 - unk_E914) * 166 + 101` with weight `func_8130A98C(state)` when `func_8130AA54` holds, else -143/91 by `unk_E908` with weight `1 - unk_E8F0 / 16`; in mode 9 past the threshold, `y -= D_8160BD04(unk_E904 / 16)`. This was a first-draft match.

`func_8130AA54` keeps its `u8 *` signature: rewritten over the typed state, its own bytes change (its explicit `base` pointer is what retail compiled).

## 2026-10-28 — `func_8130B4E8` and `func_81306F74` matched

- `func_8130B4E8(state, rect)`: `scale = func_8130B3B8(state, rect)`, `dx = 19.0f * scale`, `t` = `1 - func_8130A98C(state)` when `unk_E8FC > 0`, else `scale`, and `dy = t * 30`. It insets `rect` by `8 + dx`/`8 + dy` and `19 + dx`/`19 + dy`, then returns `scale`. The insets use the integer `19`: with `19.0f` IDO keeps the first constant in a register across the branch, while retail rematerializes it.
- `func_81306F74(state, out)` is `func_8130B3B8`'s twin for the 0x137xx state (`unk_func_81306F74`): default color is the state's first 8 bytes; color 2/4 (by `func_81302BB0(&owner->unk_15370)`) in modes 6/1/2 with `unk_137F0` set; color 8 in modes 5/2 with `unk_137EC` set. Then `func_8160945C(out, color, func_81609530(3), D_8160BD08(unk_137D0 / 16))`, returning the scale. `scale` must be declared before `color`. Its extern now takes the typed state.

Remaining owners that need layout work first:
- `func_81307128` reads a float constant from the shared rodata blob (`D_81312560`, at 0x10A6D0).
- `func_8130C334` is a jump-table dispatcher.
- `func_8130AC40` copies a 3-byte initialized local (`D_8131209C`).
All three wait for this file to own its `.rodata`/`.data`.

## 2026-10-28 — `func_8130BF1C` typed; `func_8130C334` requeue

- `func_8130BF1C`'s `struct S8130BF1C` view is replaced by the shared state (`unk_E904`, `unk_E912`, `unk_E8EC`), byte-identical.
- `func_8130C334` (requeue, register-tie) is the mode dispatcher. Its table (`jtbl_813126F0`) is already in this file's `.rodata` subsegment, so a C `switch` works. The `case` bodies must appear in retail's body order: 0, 1, 2, 3, 4, 11, 5, 12, 6, 8, 7, 10, 9, 13 (handlers B74C, B770, BADC, BFF0, C14C, C0BC, C270, BD2C, B7F8, B88C, BC44, BDB8, BF1C, BFCC).
  - After the switch: `result = 1` if `func_81602AEC(&owner + 0x1A144, func_81602D70(unk_E910))`; then `func_8160A50C(&unk_0008[i])` for the three nodes; then `func_81600A34(gfx, state, mode == 5 || mode == 2 || mode == 3, rectA…)` with `func_8130B3B8`'s rect, and `func_81600A34(gfx, (u8 *)state + 1, result, rectB…)` with `func_8130B4E8`'s rect.
  - Everything matches except the node loop: retail initializes the stack-spilled counter (`$v1`) in the `beqz` delay slot before the node pointer, while IDO puts `addiu s0, s2, 8` there and uses `$v0`.
  - Tried without effect: declaration orders, `u32`/`s16`/`u8` counters, `<=`/`!=` bounds, `while`, `arr + i`, a node local. A 300 s permuter stayed flat.
