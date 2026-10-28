# fragment47_24AE60

## 2026-10-28 — `func_860065E8` matched

`switch` directly on `func_87F01A40(arg0)`. Case 3 sets flag bits 5, 7 and 4 of byte 0x75C0, in that order, as three separate bitfield writes; case 4 clears bit 5 and sets 7 and 4. Both return 1. There is no trailing `return`: retail returns whatever the call left in `$v0` (marked `//!bug`). Keeping the result in a variable, or returning it, adds a `move`.

## 2026-10-28 — `func_86004F2C` matched (point lookup with fallback)

The `f64[3]` sibling of `func_86004EA8`. Try the tables at `arg0 + 0x66B8`,
then `+ 0x6668` (`func_86009C08` test, `func_86009FB8` result into `arg2`);
otherwise copy the default `Fragment47Vec3d` (three `f64`) at `arg0 + 0x6848`
into `arg2` by struct assignment. Retail's interleaved `lw`/`sw` word pairs
are IDO's struct-copy lowering. Written in the sibling's repeated-expression
style, it matched on the first probe.

## 2026-10-28 — `func_8600688C` matched (all-players-ready banner)

`flags[i] = state == 6 || state == 5` over four 0x1998-byte player records
(state s32 at +0x1828), with `all = all && flags[i]`. If everyone is ready,
call `func_87F0A098(arg0 + 0x751C, *(arg0 + 0x7580), 1, 0, 0, 0, 0)`;
otherwise pass the four flags. It matched on the first probe.
