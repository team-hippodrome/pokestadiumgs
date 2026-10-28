# fragment59_code

## 2026-10-28 — `func_86900698` matched (model key refresh)

When the global key `D_80094904` differs from the model's cached key
`D_8691ADB0[idx]` (idx = the s32 at `arg1 + 0x14`), and `arg0 == 2` while
the scene state `*D_8691AD58 != 6`, copy the position (0xDC..0xE4) and the
s16 at 0x20 from the 0x168-stride model record in `D_86919D00` into `arg1`.
Then always store the key. Index `D_8691ADB0[idx]` directly: a `u16 *last`
pointer local swaps `$v1`/`$a2` (0.78). Found by a 180-second permuter, then
cleaned to plain C.

## func_8690B89C (accepted 2026-10-28)

Finds the maximum of the four s32s at `D_8691A2A0 + 0x28` with a pointer loop
(bounded by `D_8691A2A0 + 0x10`), then flags each one equal to it in
`D_8691AB68[4]`. That second loop must be an *index* loop (`for (i = 0; i < 4; i++)`
with `((s32 *)D_8691A2A0)[i + 10]`); a second pointer loop keeps `i` live and adds a
`sll`. The final branch passes the four flags to `func_87F0A098`. Comparator
note: retail's `%lo(D_8691A2B0)` is our `D_8691A2A0 + 16`, the same bytes once linked.
