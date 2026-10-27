# Region notes -- src/fragments/79/fragment79_3BEAF0.c

## 2026-10-27 — `func_8414F268` accepted (karodo)

`func_8414F268(void *arg0)` is now C: **35 words / 140 bytes**, frame 0x18.
It selects halfword `1 - func_84154B24()` (as `u8`) of the array at
arg0+2. When that value is non-zero, it stores into word +0x18 either
`(value + 10) * -|amount| / 255` (value < 0x80) or `-|amount|`, where
`amount` is the word at +0x14.

Two details are required: an `s32` local for the halfword (a `u16` local
swaps registers), and an empty `if (!amount) {}` before the scaled store,
kept as `// karodo` (a 3 s permuter run found it; without it 0.74).
