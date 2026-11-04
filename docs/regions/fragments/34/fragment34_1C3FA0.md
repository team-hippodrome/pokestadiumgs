# Confirmation menu: genuine match for `func_88507370`

The handler navigates the confirmation menu, plays the appropriate sound,
updates the result, and either closes the menu or starts its transition.
The nonzero-mode cancellation and transition paths are separate `if/else`
branches; the zero-mode handler is the outer `else`. Both former early
returns are expressed by these mutually exclusive branches.

This source shape makes IDO 7.1 restore its alias information on reachable
paths. Stock AS1 can then hoist the result address before the mode test,
matching retail without changing register allocation. Changing only one of
those two branches does not match. This is evidence for this handler,
not a general rule that early returns should be removed.

The actual confirmation flag is cleared before the navigation sound call.
Its required saved value supplies the retail stack store; the old unused
`sp1C` variable is removed. Menu and result accesses use the existing public
`F34ConfirmMenu` and `MenuResult` fields. Initialization remains five explicit
stores, with no synthetic loop, padding, empty tests, or unused operations.

Validation: stock native IDO 7.1 emits all 142 retail instructions (568
bytes, 32-byte frame) and the complete module's original allocated sections,
function extents, and semantic relocations. Independent normal and
20-leading-blank compiles match. `make -j1 COMPARE=1 RUN_CC_CHECK=1` passes
with the retail 64 MiB ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.
The `REWRITE_FUNCTION_HEX` and all 30 `REWRITE_FUNCTION_RELOC_TARGET`
directives for this handler are removed. Compiler, linker layout, and
coverage files are unchanged.
