# Fragment 20 fixed-pool lookup

## `func_82606E90`

The 56-byte owner in `src/fragments/20/fragment20_12C460.c` scans 40
12-byte records in order. It returns the first record whose signed halfword
at offset zero is zero, or `NULL` when every record is occupied. The helper
does not modify the records.

The inspected retail caller, `func_82606EC8`, passes the pool at offset
`0x50` of its argument. At `0x826072C8` it marks a returned record occupied
by storing one at offset zero. The surrounding stores initialize the other
five halfwords. Its later loop walks the same 40 records at a 12-byte stride
and calls `_bzero` with size 12 when the record's counter reaches eight.
This establishes the record size and free-entry test. The enclosing object's
complete layout and the effect's identity remain unresolved, so the function,
record type, and fields retain address-based or offset-based names.

The C loop computes a record pointer from each array index, saves it as the
result when free, and breaks. That ordinary source shape preserves the
retail loop and return scheduling without padding or code-generation fakes.

## Validation

Tested against master `8677ca6bf0d1baef93abedf8d49197a171fd7573` for
`VERSION=us`. The changed translation unit was forced through the normal
Makefile, including its host syntax check, and the complete ROM was linked:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/20/fragment20_12C460.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The build reported `build/pokestadiumgs-us.z64: OK`, with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the byte comparison and whitespace
check passed. The compiled owner occupies 56 instruction bytes. Behavior
claims above come from inspected code and assembly; no runtime observation
was required.

## `func_82604C98`

The 88-byte owner searches an array of six-byte records. It compares each
record's first two signed halfwords with the supplied word-sized keys and
returns the first matching index, or -1 when none match. A nonpositive
signed count also returns -1. The search does not modify the array.

`func_82604CF0` in this source calls the search, then reads the matching
record's signed halfword at offset 4 and adds 41; it returns 41 when the
search fails. `func_826065B0` passes the table at parent offset `0x3544`,
the signed halfword count at offset `0x14`, and two signed-halfword fields
from its new descriptor. These operations establish the six-byte record
and all three halfword positions. Their broader meanings remain unresolved,
so the record type, fields and owner retain unknown names.

The indexed loop computes a typed current-record pointer, saves the index
and breaks on a matching pair. This preserves the retail scalar loop,
comparison operand order and eight-byte frame. Existing matched C remains
unchanged. The evidence comes from inspected C and retail assembly without
runtime observations.

Tested for `VERSION=us` on master
`0100644fecb840962da14abb8029467474cad7df` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/20/fragment20_12C460.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced source recompilation and linked
the complete ROM. Exact acceptance was `build/pokestadiumgs-us.z64: OK`,
with MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. The retail byte comparison and
whitespace check passed. All 22 instruction words, totaling 88 bytes, match.

## 2026-10-27 — `func_82605EF4`: requeue

requeue. Descriptor builder for kind 8 (`func_826065B0`): pair at `+0x10` = (0, -480) mirrored to `+0x18`, `+0x14` = 169, `+0x16` = 92, flags `+0x04 &= 0xFFFE`, `+0x24` = 305, `+0x26` = `D_82615504[+0x00]`; then copies from the two 0x428-byte records at `**(arg0 + 0x110) + 0xB0`: the halfword into `out[i]` and two signed bytes into `out[2 + 2i + j]`, and two halfwords from `*state + 0x900` into `out[6..7]` (`out` = `desc + 0x30`). Best 0.78 locally (`out` assigned first, `state` and the flag clear after the first store, inner loops `j != 2`, outer `i < 2`): the remaining diff is which induction temp (`t2`/`t3`) holds the `out[i]` pointer vs the row pointer, and the last loop's pointer register. Permuter 2 × 420 s: 135 → 75. Next: try a typed out struct with row arrays, or a pointer-walking source.

## 2026-10-27 — `func_826063AC`: requeue

requeue. Text descriptor: loads asset 284, clears the pair/sizes, gets an image via `func_82614F40` + `func_8004C874` and measures it (`func_80049148`, plus `*font + 4` when `state+0xF` is set), measures a 0x80-byte string from `func_826150A4`, takes the wider, sets `+0x24 = width + 80`, `+0x14 = (640 - +0x24) / 2`, and `+0x16 = 129` for kinds 0 and 0x300. Best 0.90 (declaring `image_id`, `image_index`, `buf[0x80]`, `font` in that order fixes the frame and most slots): retail places the two halfword out-params at `sp+0xC4/0xC6`, 12 bytes above the end of `buf`, while IDO packs them right after it (`0xB8/0xBA`); an explicit pad grows the frame instead. `width + *font` also keeps IDO's `addu s2,t5,v0` operand order. Stack-diff permuter 420 s: 74 → 44.

## 2026-10-27 — `func_8260E03C`: requeue

requeue. Draws the animated marker: `x = +0x10 + +0x14`, `y = +0x12 + +0x16` (both `s16`), a switch on `+0x30` (0–7) picks the `(dx, dy)` offset, then `Ui_DrawAnimatedTextureMarker(x + dx, y + dy + +0x32 * 25)`. Best 0.95 normalized (`unaligned_data_drift`): retail computes `y + dy` before the `* 25` term, IDO reassociates to `(k * 25 + y) + dy`; an `s32 ny = y + dy` temporary gets closest. Operands written `+0x14 + +0x10` match retail's load order.

## 2026-10-27 — `func_82614630`: requeue

requeue. Draws `D_8261DA4C`'s panel: when `[1] > 0`, frame = upper half of the word at `+0x0C`, texture = `func_8004C990(85, D_826157B8[frame])`, mode 2 for frames ≥ 6; display list `D_80094E78`, `func_826082C0` fills prim/env colors, env color uses alpha `[1]`, then `func_8004D150([10], [11], texture, 0, mode, 0)`. With an `s32 frame` IDO turns `frame < 6` into a pointer compare against `&D_826157B8[6]`; `u32 frame` avoids that (0.58) but retail keeps `frame` in `a3` and spills it at `sp+0x3C`. Permuter 400 s: 1270 → 535. The later extern is `void func_82614630(void *)`.

## 2026-10-27 — `func_826057A8`: requeue

requeue. Image descriptor (kind 1): looks up the 0x98-byte record for the state's slot, sets `out[0..1] = (16, 24)`, `out+8 = func_8004C874(record[7] + 76, slot+0x38)`, zeroes the pair/sizes, then `+0x24 = func_80049148(8, 0, image) + out[0] * 2`, `+0x26 = func_800472E0(image) * 20 + out[1] * 2`, `+0x28 = 128`, `+0x2C = 16`, `+0x2A/+0x2E` mirror `+0x24/+0x26`. Not probed past 0.47: retail homes `arg0` at `sp+0x40` without reloading it and leaves a dead `addiu t1,t1,4` after reading `record[7]` (`record + 4` then `[3]`?), so the record pointer is probably a struct walk the draft lacks.

## 2026-10-27 — `func_82606B28`: requeue

requeue. Sibling of the matched `func_82606CE8`: caps the timer `+0x08` at 30000 and, while `sub[4]` (`sub = arg0 + 0x30`) is set, fades each slot `sub[5 + i]` toward 0 by `t = timer - stagger * i - stagger * 4 * arg0[1]` (`D_826155C0` duration, `D_826155C4` stagger). Slots with `i >= sub[3]` snap to 255, zero slots are skipped, and it plays sound 103/104 on the 255 → <255 edge. Best 0.55: retail hoists both global values into `a1`/`a2` and re-reads them after each `func_800226C0` call, while every spelling tried (direct globals, locals assigned in the loop, before the loop, at the top) keeps their addresses in two extra saved registers (`s6`/`s7`). Permuter 400 s: 4250 → 3660. Next: try the globals as `static` file-scope data or a struct read.

## 2026-10-27 — `func_8260FFE8`: requeue

requeue. Builds the selection order at `+0x20`: clears `used[count]` (`count = state->unk4->unk2`), records up to 12 nibble-packed indices from `(*state)[0x10 + i]` (stop at 0xFF; index = `(b >> 4 & 0xF) * arg1 + (b & 0xF)`), stores the count at `+0x1C`, then appends every unused index. copt unrolls both clearing/appending loops by 4. Best 0.34: `s32 used[12]` gives retail's 0x60 frame, but retail places the array at `sp+0x20` (IDO: `sp+0x30`) and swaps `v0`/`v1` for count/state; declaration order has no effect. Stack-diff permuter: 1555 → 1080.

## 2026-10-27 — `func_8260DB98`: requeue

requeue. Draws a selection marker: if `+0x3C != -1`, texture 97 frame 0 with colors `D_82615720`/`D_82615724` when `+0x02 == +0x3C`, else frame 1 with `D_82615728`/`D_8261572C`; PipeSync, env color (alpha `+0x44`) and prim color when both are set; then `func_8004D19C(offsets[+0x02] + x, y + dy, tex, 0, 0)` with `offsets`/`dy` = `D_82615734`/31 when `+0x34` is set, else `D_82615730`/17. The parameter must be `u8 *` (later extern). Best 0.96: retail re-reads `+0x3C` for the second compare instead of CSE-ing it, and loads the env color's green byte first. Permuter 420 s: 1680 → 745.

## 2026-10-27 — `func_82607528`: requeue

requeue. Per-kind update: kinds 1/4/6 call `func_82606B28`/`func_82606CE8`/`func_82606EC8`; kind 5 advances `+0x08` (capped at 1000) and sets `+0x34 = min(t, D_826155FC) * 255 / D_826155FC`. Then, while flag bit 0 is set, it advances `+0x0E` and sets `+0x0C` rising over `D_826155F4` frames and falling over `D_826155F8`, clearing the flag after `D_826155F4 + D_826155F8` frames. The caller `func_82607B74` must pass `arg0` (companion edit, as for `func_82607AA0`). Best 0.95 with direct global reads: retail keeps `D_826155F4` in `a3` from the top and re-loads it after each handler call (IDO PRE), plus `255` in `a2`, in a 0x28 frame; a local copy of the global gives the right frame but spills it instead (0.95). Permuter 420 s: 1140 → 840 with semantics-changing output only.

## 2026-10-27 — `func_82608EC4`: requeue

requeue. Draws a horizontal strip of images: colors via `func_82607BF4` (as in the matched `func_8260899C`), sum of the non-null image widths in the `+0x30` list (count at `[0]`), then each image through `func_8004D19C` from `x + (+0x24 - width) / 2`. `x`/`y` are added as `+0x14 + +0x10`. With the scalars declared in the order `y, list, i, width, cursor, image, x, prim, env`, the frame and colour slots match (0.96/0.94). The rest: retail computes `list = arg0 + 0x30` right after the position loads and keeps two copies (`t0`, spilled to `sp+0x58`, and `s4`), and spills `x` at `sp+0x74` (IDO: `0x76`). Stack-diff permuter: 880 → 820.
