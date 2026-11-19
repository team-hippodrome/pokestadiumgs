# Fragment 53, second file (from func_86504EB0)

## 2026-11-19 — file split and func_8650515C matched

`fragment53_code.c` is now two files. The second one,
`fragment53_28E360.c`, starts at `func_86504EB0` (ROM 0x28E360, vram
0x86504EB0). Its rodata starts at 0x296CA0 (vram 0x8650D7F0, the -3000.0f
literal of `func_86504EB0`). Both boundaries are 16-aligned with no padding,
so the bytes are unchanged. The functions moved as-is; GLOBAL_ASM paths now
point at `asm/us/nonmatchings/fragments/53/fragment53_28E360/`.

Why split: `func_8650515C` keeps its table index in a function-scope
static (`D_8650D9D0`, in the loader-cleared area over the relocation
tail). IDO orders `.bss` by first declaration, and the models array that
`fragment53_code.c` pins at 0x86510010 is declared earlier in that file.
So one object's `.bss` could not hold both. Each file's `.bss` now has its
own NOLOAD section in `datamig_bss.ld`.

The new file also owns `.data` 0x296660–0x296690 (vram 0x8650D1B0–D1E0).
In IDO's order that is `D_8650D1B0` (a global, also read by
`func_86507AFC`), the initializer for `func_8650515C`'s local
`s32 tbl[10]`, and the function static `D_8650D1DC = 0.0f`.

`func_8650515C` notes:
- Retail reloads `D_8650D9D0` and `D_8650D1DC` with a fresh lui at every
  access but keeps them in registers across the loops. That only happens
  for function statics: externs got a shared lui/addiu base, and file
  statics lost the register promotion.
- The case-4 loop with stride 0x2D0 that touches 0x28 and 0x190 is IDO's
  unroll by 2 of `for (i = 0; i < 4; i++)` over 0x168-byte models.
- The table is read as `tbl[D_8650D9D0]` after `if (i == 0) D_8650D9D0++;`.
  IDO strength-reduces that index itself (`addiu v0,v0,4` next to the
  increment) and rematerialises `sp+0x58` each pass.
- Operand order in case 2 is significant: the compare is
  `load + (f32)(s32)(ternary + x)`, and the store is
  `(f32)(s32)(x + ternary) + load`.
- One unused `s32 pad` (FAKE) before `tbl` gives retail's slot above it
  (tbl at sp+0x58, frame 0x88).
