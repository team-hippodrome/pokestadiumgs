# fragment54_code

## func_86600E00: tooling-blocked (shared `$at`), 2026-10-28

`D_8660673C = D_86606720 / 60.0f` (stored, reloaded, divided). Then for each of
four records whose `D_8660A9E0` / `AA38` / `AA90` / `AAE8` word is 201, a float
`D_86606750` goes to three adjacent floats (`+8`, `+4`, `+0`, in that order). Retail
gives the `+8` store its own `lui $at`, but the `+4` and `+0` stores share one `lui $at`.
This is the shared-`$at` artifact that plain per-statement C does not reproduce.
Chained array assignment instead gives a `lui`/`addiu` base plus a reload
(0.38). Leave this until shared-`$at` has a sanctioned spelling; no
`COALESCE_AT_LUI`.

## 2026-10-29 — `.rodata` owned; `func_866040B8` matched; `func_86601A04` requeue

`fragment54_data` held this object's `.rodata`. It is now split: `data` up
to 0x2A0800 (the first EUC-JP string, 16-aligned), `fragment54_code`'s
`.rodata` up to 0x2A0AC0 (end of `jtbl_8660715C` plus padding), then a
`fragment54_tail` rodata blob. This unblocks the jump-table owners
`func_86600678`, `func_86601A04`, `func_866044F0`, `func_86605098` and
`func_86605F04`.

`func_866040B8` (frame draw) matched. It follows `Fragment53_DrawSceneFrame`'s
shape. Case 8 must read `D_866067FC`/`D_8660682C` as their own globals.
Spelling them as `&D_86606788 + 0x74/0xA4` swaps `$v0`/`$v1` around the
re-loaded compare.

`func_86601A04` (**requeue**, `scratch/c/a04_best.c`):

- Control flow and frame-11/13 layout are exact. Use the negated form
  `if ((rec3C >= 0x15 && D_866066F4[arg1] == 0) || rec8 == 0) { if (frame == 13) ... } else { 11 }`,
  since retail branches into the frame-11 block. The case -1 path returns
  early, which gives `b .L…C88`.
- The only remaining difference is allocation. Retail keeps `arg1` in `$s1`
  and spills `record` to `0x20(sp)` with a 0x28 frame. Ours spills both.
- A 300 s permuter run only scored better with fake extra uses of `arg1`.
  This confirms `arg1` needs more real references than ours has.
- Next hypothesis: find the missing `arg1` uses, for example per-case
  `D_8660A990 + arg1 * 0x58` re-indexing for some fields, or a
  `(u16)(arg1 + K)` argument as in `func_86601F70`.
