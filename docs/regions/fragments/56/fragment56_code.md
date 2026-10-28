# fragment56_code matching notes

## 2026-10-29 — `.rodata` owned; `func_86803ED8` matched; `func_86806E94` requeue

The `fragment56_data` blob held this object's `.rodata` too. It is now split:
`data` up to 0x2B95C0, then `fragment56_code`'s `.rodata` from
0x2B95C0 (the first EUC-JP string, 16-aligned) to 0x2B9A10 (after the 1.4f
constant and its zero padding), and a `fragment56_tail` rodata blob after
that. The C now writes `1.8f`/`1.2f`/`1.4f` literals instead of
`extern D_86808218/D_868083E0/D_868084C4`. This unblocks jump-table owners
`func_86800594`, `func_86801E8C`, `func_8680537C` and `func_8680686C`.

`func_86803ED8` (frame draw) matched. Case 8 falls through into the case
2/5 body.

`func_86806E94` (**requeue**, 0.89, `scratch/c/e94.json`) is the screen-state
update; the whole switch is written out. Retail re-forms `%hi(D_86808070)`
for each access (load, store, reload) and loads the returned `D_8682F2A8`
through `$v1`. Ours caches the address in `$v0`. `D_86808070` sits in the 16
bytes at 0x2B95B0, just before this object's `.rodata`. That is consistent
with a function-local `static s32` in this file, which would need the data
blob split to give `fragment56_code` that `.data` word (see the
per-access-`lui` note for `func_8F100020`).
