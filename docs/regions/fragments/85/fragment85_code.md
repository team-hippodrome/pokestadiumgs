# fragment85_code

## 2026-10-28 — `func_8FD005B4`: requeue, register tie at 0.925 (cached asset draw)

Reload `D_8FD022A8` through `func_8004E0F0(D_8FD022A8, id, index)` only when
the bytes at `D_8FD02188 + 0x13` / `+ 0x17` differ from the cached words at
`+ 0x18` / `+ 0x1C`; return if the load fails, else store the new pair. Then
draw with `func_8FD00514(arg0..arg3, D_8FD022A8)`. Best local form (37/40
instructions identical; frame, homes 0x28/0x24 and call order all match):
`u8 id; u8 index;` loaded first, a direct `if (func_8004E0F0(...) == NULL)
return;` (a named result local shifts the homes down a slot), and
`*(s32 *)(&D_8FD02188 + 0x18) != id || index != *(s32 *)(&D_8FD02188 + 0x1C)`.
Residual: retail compares `bne t6(cached), v0(id)` and `beq t8, t0(index)`.
Ours is `bne v0, t7` and `beq t0, t8`, unchanged across all four operand
orders, s32/u32 field widths, explicit casts, and u8/u16/s16/s32/u32 local
types. A 180-second permuter stays at 25. Next: test `D_8FD02188` as a typed
file-level struct (byte fields at 0x13/0x17, words at 0x18/0x1C). That would
also replace this file's `M2C_FIELD` helper uses.

## 2026-10-28: `func_8FD01AB8` text lookup selection

The byte index selects `func_8004C874(16, entry)` with entries
9, 11, 13, 14, 15, 12, 10 and 8 for indices 0..7. The helper's implementation
returns `void *` and forwards the two word arguments to `func_8004C7A0`.
The existing caller `func_8FD01B90` measures all eight returned strings with
`func_80049148`, retains the widest index and places that lookup in message
slot 43 through `func_8004C54C`. The caller supplies only indices 0..7.
//@src/4CC20.c

Return directly from each switch case. An intermediate result local enlarges the frame by 8 bytes and adds result
loads/stores; direct returns reproduce the original
24-byte frame, all 54 instruction words and the existing eight-entry jump
table. Retail leaves the result register unspecified for indices above 7;
the C fallthrough preserves that behavior and is marked `//!bug`. Unknown
names remain unchanged. No new data, padding, instruction rewrite or layout
change is needed.

Validation on master `7dd349bcded32b4fcc4a13f36b80a20826487d86` plus this
replacement: fresh US extraction and the complete unchanged baseline passed.
`make -W src/fragments/85/fragment85_code.c -j4 VERSION=us rom` freshly
recompiled the final source with normal syntax checks and produced exact
acceptance `build/pokestadiumgs-us.z64: OK`. Full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail `cmp` and `git diff --check` pass.
Original-assembly/raw-ROM comparisons verify the 216 bytes at
`0x433B78..0x433C50` and the jump table at `0x434220..0x434240`.
