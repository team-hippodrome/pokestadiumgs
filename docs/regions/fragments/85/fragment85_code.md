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
