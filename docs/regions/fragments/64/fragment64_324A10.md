# fragments/64/fragment64_324A10.c

## 2026-10-29: `func_87F01DA0` requeue

requeue (0.93). Callback `(s32 arg0, u8 *node)`:
- case 0: clear flag 2;
- case 1: `selected = (D_87F11980->0xC == mode + 1)`, written per case as `switch (mode = *(u32 *)(node + 0x20))` cases 0..2, then `func_87F00944(node, prim, env, selected)`. prim/env are 4-byte color unions passed by value, with word 0xFFFFEBAA and 0xAA5A00FF assigned right before the call. Declaring `(u8 *pad slot), prim, env, mode, selected` fixes the frame.

Remaining: retail CSEs the constant 1 into $v1 for both the outer `arg0 == 1` test and the inner `== 1` compare, while ours uses $at twice. if/else instead of the outer switch is worse (0.84).
