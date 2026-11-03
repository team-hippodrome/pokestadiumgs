# fragments/64/fragment64_324A10.c

## 2026-10-29: `func_87F01DA0` requeue

requeue (0.93). Callback `(s32 arg0, u8 *node)`:
- case 0: clear flag 2;
- case 1: `selected = (D_87F11980->0xC == mode + 1)`, written per case as `switch (mode = *(u32 *)(node + 0x20))` cases 0..2, then `func_87F00944(node, prim, env, selected)`. prim/env are 4-byte color unions passed by value, with word 0xFFFFEBAA and 0xAA5A00FF assigned right before the call. Declaring `(u8 *pad slot), prim, env, mode, selected` fixes the frame.

Remaining: retail CSEs the constant 1 into $v1 for both the outer `arg0 == 1` test and the inner `== 1` compare, while ours uses $at twice. if/else instead of the outer switch is worse (0.84).


## 2026-11-03: `func_87F02104` genuine controller-loop match

Accepted: remove one `REWRITE_FUNCTION_HEX` and all 13 associated
`REWRITE_FUNCTION_RELOC_TARGET` directives. Stock native IDO 7.1 produces
all 123 retail instructions (492 bytes, 56-byte frame) after normal linking.

Use `controller.h`'s actual 40-byte `ControllerState` and `flags` field at
0x10. The initialization loop saves four flag halfwords and enables stick
input. A normal four-iteration restoration loop is unrolled by the compiler
into the retail stores, including its saved-register cursor. This replaces
the manually written interior aliases and negative-offset stores. Direct
`D_87F11980` accesses replace the pointer-to-integer-to-pointer expressions.
Keep the producer's signed input result before narrowing to the working
`u16 buttons`; both values are consumed. Remove the unused pointer and empty
result test. The sound helper's `u16` argument matches its real definition
(`Audio_PlayDefaultSound`); the controller helper uses its real header ABI.

Verification: native unchanged and candidate modules each reproduce their
complete allocated bytes/layout, symbol extents and semantic relocations
with 20 leading blank lines. Every other function's bytes and module section
layout are preserved. The two changed raw relocation addends resolve to the
same controller addresses; an independent GNU ld link, positively calibrated
against retail with a VMA-aware ELF reader, matches all 492 bytes. Host syntax
and normal `make -j1 COMPARE=1 RUN_CC_CHECK=1` pass. Full-ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`.

All function/storage extents and legacy addresses remain unchanged. Removing
the last typed reference to the zero-sized `D_800CE088` interior alias changes
only its ELF type from `OBJECT` to `NOTYPE`; its address stays `0x800CE088`.
No compiler, layout, coverage, or tool changes. Other callbacks' existing
frame scaffolding is outside this acceptance and remains unresolved.
