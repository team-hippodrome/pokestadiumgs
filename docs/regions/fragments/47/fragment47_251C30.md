# fragment47_251C30

## 2026-10-28 — `func_8600CD10` matched (load four tinted models)

Four times: `func_8004DDF4(0x73)`, open a main-pool state, then
`arg0[i] = func_8004DFEC(pool, 0x73, func_87F0AD50(arg1, 1, i))`, and
finalize. Same shape as `Fragment51_InitScene`'s player resources. The
`ColorAdjustment` returned by `func_87F0AD50` must be passed inline: a named
`tint` local moves the struct-return temporary from sp+0x38 to sp+0x3C.
