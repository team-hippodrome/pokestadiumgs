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

## 2026-11-01 — animated texture callback accepted

`Fragment56_AnimatedTextureCallback` (formerly `func_86800298`, 332 bytes)
selects archive227 entry0 at event0. At event5 it advances a counter unless
`D_8682F2B4` is set, wraps at21, selects entry counter/4, installs the texture
at graphics segment15, submits `D_86808640`, and calls `func_8003CD84`.
The one-argument texture-data getter and two-argument archive getter are
verified in `src/4CC20.c`; the assembly-only draft inferred extra arguments.

A function-local static counter restores the original scalar accesses.
Direct counter clamping and a live asset-return temporary reproduce the
original40-byte frame and segment-command spill at24. There are no dummy
locals, source-line directives, instruction rewriting, or changed compiler flags.
The static is pinned by `datamig_bss.ld` at its original word86807CFC.
Its object has a16-byte NOBITS section containing the four-byte static and
compiler alignment tail. The loaded data blob retains the original zero word
and following data, so the overlay preserves retail initialization. Only this
counter is assigned to that overlay; future bss additions need separate review.

A private opt-in verifier checks the source/function, sole static at section
zero, NOBITS size16, exact linker pin, and loaded zero backing. It real-links
the entire candidate text and rodata at game addresses with the bss overlay,
then compares every linked byte. Ten positive/negative controls pass. This
proof only enables a sequential canonical ROM gate; it does not install C.
`fragment56-pinned-counter8` candidate0 passed the normal host syntax check
and full US ROM gate on `d39a2204`, retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The assembly baseline also passed with
that overlay before candidate admission. Naming preserves all module bytes,
function extents, and normalized relocations normally and with20 leading blank
lines. The old function address remains a linker alias. Diagnostic tools and
receipts stay private; the production source and linker pin are reproducible.
