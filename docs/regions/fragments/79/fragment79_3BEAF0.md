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

## 2026-10-27 — `func_8414FA3C` gated call accepted

`func_8414FA3C(void *arg0)` is now C: **58 words / 232 bytes**, frame 0x28.
With `side = func_84154B24()`, it fetches `func_84154B64(side)` (kept in an
otherwise unused `self` local, which the frame requires) and the other
side's record `mon = func_84154B64(1 - side)`. It then calls
`func_8414F268(arg0)` (#1693) only if `mon[0xD]` and `mon[0x10]` are below
10 and, when byte 2 of `func_84154B30(side)` is at least 2, also
`mon[0x13]`, `mon[0xE]` and `mon[0x11]`. The `side`, `other` and flag
locals are `u8` (they spill as bytes at +0x25..+0x27).

## 2026-10-27 — own `.rodata` subsegment; `func_8414FB24` effect dispatch accepted

`yamls/us/rom.yaml` gives this file `[0x3FB760, .rodata]`
(`jtbl_8418BED0`, 155 entries, up to `0x3FB9D0`), the tail of the shared
`3FB010` blob. In the linker script that blob's object now precedes
`fragment79_3BEAF0.o(.rodata)`.

`func_8414FB24(u8 *arg0)` (**64 words / 256 bytes**) maps the byte at
`arg0 + 0x2E + func_84154B24()` through `func_80062D20` and dispatches
values 2..156 to this file's handlers. The case groups are generated from the
table and written in body-address order: `func_8414F2F4` (8 values),
`func_8414F268` (26), `func_8414F5F0` (33), `func_8414F618`,
`func_8414F668` (2), `func_8414F6D0` (3), `func_8414F748`, `func_8414FA3C`,
`func_8414F894`, `func_8414F8B4` and `func_8414F93C`. Index the byte pair as a
typed array (`unk_func_8414FB24.unk_2E[side]`); raw `arg0[0x2E + side]`
commutes the `addu`.
