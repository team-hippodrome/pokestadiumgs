# fragments/79/fragment79_36F8B0.c

## 2026-10-28: `func_841032F0`, `func_841031F4`, `func_84101AF4`, `func_84101084` accepted; `func_84100174` handoff

- `func_841032F0` / `func_841031F4`: model draws through the function pointer
  `func_80003240(func_8100348C)`. The single-model draw needs two FAKE pad
  words above its first local (the 0x30 frame). The list draw matched
  directly. Both keep the file's existing prototypes (`(u8 *, s32)` and
  `(u8 *, void *, s32)`).
- `func_84101AF4`: the two `0.01f` literals are separate `.rodata` entries in
  retail; writing `* 0.01f` twice reproduces them. A probe match needs the
  ROM gate (`link_verified: false` from the rodata relocations).
- `func_84101084`: keyframe sampler over `Func84100688Table`. Reload the table
  after `func_84100688` and read `frames = table->values` before the
  last-key test. The frame pair must be read as `*(s16 *)(index * 2 + (u8
  *)frames)`; indexing `frames[index]` swaps the `addu` operands.
- `func_84100174`: requeue. Record initializer with chained zeroing. Retail
  re-reads `+0x4C` for the `+0x44/+0x48` copies and `+0x6E`/`+0x74` for the
  halfword pairs. IDO picks the `+0x50..0x58` float chain to re-read instead.
  Statement order does not change which chain IDO picks. Permuter 240 s:
  1380 → 750.
