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
