# fragment59_code

## 2026-10-28 — `func_86900698` matched (model key refresh)

When the global key `D_80094904` differs from the model's cached key
`D_8691ADB0[idx]` (idx = the s32 at `arg1 + 0x14`), and `arg0 == 2` while
the scene state `*D_8691AD58 != 6`, copy the position (0xDC..0xE4) and the
s16 at 0x20 from the 0x168-stride model record in `D_86919D00` into `arg1`.
Then always store the key. Index `D_8691ADB0[idx]` directly: a `u16 *last`
pointer local swaps `$v1`/`$a2` (0.78). Found by a 180-second permuter, then
cleaned to plain C.
