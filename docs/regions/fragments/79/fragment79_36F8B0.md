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
- `func_84100710`, `func_84100874`, `func_841009D8`: the RGBA keyframe
  samplers (the first two are byte-identical; the third reads `anim[2]`).
  Same spellings as `func_84101084`, plus an `s32` time parameter. Retail
  homes it and reads `(s16)time` back with `lh`.
- `func_84100B3C`: requeue. Applies the sampled color: mode 0 indexes
  `anim[1] + (time % divisor) * 4`, mode 1 calls `func_84100710`, and
  `time == divisor` ends via `func_84100094`. The result goes to
  `Audio_SetChannelGroupCounts` for kind 2, else into `+0x8B..0x8E`.
  Retail keeps extra register copies of `time` and `mode`, and spills the
  remainder (`sp+0x28`) and `color` (`sp+0x38`). A sweep of
  `time`/`mode`/`frame` widths only reaches 0.63 (72 vs 75 instructions).

## `func_84102D38`: color-buffer texture commands

The 83-instruction / 332-byte owner obtains a color-buffer descriptor through
`func_8411EF64(func_8411E164(record[2]))`. The first helper selects the other
player context; the second selects `D_84190414` or `D_84190418`. Their producer
`func_8410AA18` allocates RGBA16 images with `func_800071A4`; the local
`GfxImage` view follows the 16-byte descriptor initialized by
`GfxImage_Initialize` (width/height at 4/6, image pointer at 8).
//@src/fragments/79/fragment79_38D510.c
//@src/fragments/79/fragment79_379E90.c
//@src/7A50.c

It appends a primitive-color modulation command and a clamped RGBA16 tile
load to its incoming display list, appends render mode `0x0C184A50` through
`D_800D0510`, and returns the advanced incoming pointer. `func_84102E84`
selects this path when the low six flag bits equal `0x3F`. Unsigned dimension
locals reproduce the tile-stride arithmetic; no new fake or storage is used.

Validated against master `c91ff625e11148ab7d5268c8cab228595655e6ba`
plus this replacement for `VERSION=us`:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/79/fragment79_36F8B0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check HEAD^
```

The normal syntax-enabled full build reports exactly
`build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail comparison and whitespace checks
pass. All 13,616 module text bytes, 160 rodata bytes, defined symbol extents,
and 289 text plus 25 rodata semantic relocations equal the assembly-backed
baseline. The new helper prototypes change their undefined ELF symbols from
NOTYPE to FUNC. The owner retains its 24-byte frame and ROM extent
`0x3725C8..0x372714`; all previously matched C bytes remain exact.
