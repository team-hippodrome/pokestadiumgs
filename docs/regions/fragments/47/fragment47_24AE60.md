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

## func_86006364 (accepted 2026-10-28)

Per-player loop over 4 records (0x2D8 stride at +0x775C, 0x1998-stride
objects at +0x1890). Two things were needed. First, the first call's second
argument must load into its own local (`data`) before the call. Inline, IDO
copies `arg0` into `s3` in the prologue instead of reading `a0` first. Second,
the stack vector is `f32 pos[3]` (frame 0x68). The indexed `i * 0x2D8` form
scores higher than a separately advanced record pointer.

## 2026-10-29: `func_8600666C` layout-prerequisite

layout-prerequisite. Its switch table jtbl_8600D8D8 sits in `fragment47_data_tail_rodata` (0x253D40-0x253F30), next to this file's other literals. Existing C in this file references those literals by D_ name, so the file's `.rodata` subsegment can't just grow down to 0x253D40. The shape is straightforward: func_860065E8/func_87F00930 guards, the per-step loop, then a seven-way switch on func_87F006AC().
