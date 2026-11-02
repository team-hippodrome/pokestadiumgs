# fragment18_code

## 2026-10-28 — `func_817000A4` matched

Fragment setup: clears `D_81700DA0`, stores the `func_8004C8C0(0x13F)` result there, and if it is nonzero calls `func_8004C8C0(0x11C)` and runs `fragment18_main` over the four 0x24-byte entries at `D_81700DB0`. It returns `D_81700DA0` (reloaded). It needs an index loop (`D_81700DB0 + i * 0x24`); the pointer-walk forms compare against a precomputed end in the wrong register.

## 2026-11-03 — text entry width update matches without rewrites

`func_81700B8C` now emits all 128 retail bytes through stock IDO 7.1,
removing its three `REWRITE_FUNCTION_WORD` directives. It updates the selected
36-byte entry only when the supplied non-null text pointer differs from the
stored one, measures the text with the entry's font, stores the truncated
halfword width and width+75, and reports whether it changed the entry.
The original signed upper-bound test and return paths are preserved.

The record layout follows the existing initializer and access instructions:
font at +0x06, text pointer at +0x08, flags at +0x0C, measured width at
+0x12 and margin width at +0x14. Unknown fields retain offset-based names. `func_80049148` in
`src/47580.c` defines the actual `s32(s32,s32,const char *,...)` contract;
its earlier local `s16(s32,s32,s32)` declaration was inaccurate. The public
entry argument now expresses that actual text pointer. No C caller or header
declaration of this function exists elsewhere in the checked source tree;
the MIPS argument locations and return behavior are preserved.

Typed records and font/width locals alone kept the original three-word
scheduling residual. A calibrated one-worker, 60-second expression/statement
search (1578 mutations, 0 compile errors) identified address-calculation
placement. Its direct pointer-arithmetic winner was not installed: computing
an unchecked array pointer before the guards adds undefined behavior for
skipped large indices. The accepted form computes the N64 address using
unsigned 32-bit arithmetic, then converts that address to the entry pointer.
Only the original guarded path dereferences it. This restores the original
spill at SP28 and argument scheduling without an unused local, dummy operation,
forced register or compiler change.

Fresh unchanged/candidate normal/+20 complete-object controls preserve every
allocated byte/layout, defined extent and semantic relocation. The installed
source passed two further module controls, normal host syntax and the native
`make -j1 COMPARE=1 RUN_CC_CHECK=1` retail ROM gate. ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Coverage is unchanged.
