# fragment31_19E800 matching notes

## 2026-10-29 — `func_8822BAF8`: requeue

Status: **requeue**, one extra instruction (89 vs 88). The 2026-10-29 session's
body is `scratch/c/af8b.c`, with a companion edit that retypes
`extern s8 D_889041B8` to `u8` in `func_8822B63C` (only stores, so the
bytes are identical; retail tests it with `lbu`). Read the button word
inline, with no `buttons` local, to get retail's `$v0`.
- Layout: the A button (0x4000) path plays sound 0x48 and calls `func_88004990`.
- The B button (0x8000) path either runs the two-case switch when
  `func_8800005C(list + 0x28)` is set, or the cases-0..4 jump-table switch
  when `func_80063754(+0x189)` is set. Otherwise it calls
  `func_8822B580(sel + 2)`.
- With no button, `func_88002720(list + 0x28, +0xC, list + 0x2C)`.

Remaining: retail computes `list + 0x28` once in the `beqz` delay slot
shared by both successors; ours recomputes it on the fall-through path. Tried
a `cursor` local (at the top or just before the test), inverted polarity, and
the permuter (300 s, no gain).


## `func_8822B9EC` — completion dialog and record release

The 268-byte owner is the completion callback registered by `func_8822BE00`
through `func_88004804`. The initializer allocates the 408-byte record,
stores its incoming byte at offset 393, and clears the words at 396 and 400.
`func_8822B580` sets word 400 to one and stores its argument at 404.
//@src/fragments/31/fragment31_19E800.c

When word 400 is set, the callback fills text slot 24 using
`func_800635E0(record[393])`. A value of four at word 404 selects message
116 or 108 according to word 396. Other values fill text slot 25 from
record offset 329 for value three, or resource 37 / (value + 103), then
select message 115 or 114. When word 400 is clear, it calls `func_88001900`
and sets `D_880068B4` to one. Every path frees the record through `Util_Free`.
The broader meanings of the record fields remain unresolved.

`func_8822B930` takes an integer text ID: it forwards that word as the fourth
argument of `func_8004C8A0`, whose actual definition takes `s32` there.
Correcting its old pointer formal preserves its existing machine code.
The other new declarations follow the actual helper definitions, including
`func_8004C54C`'s two word arguments and signed result, and `Util_Free`'s
word-address argument. Existing C and data remain byte-identical.
//@src/4CC20.c
//@src/641E0.c
//@src/3E40.c
//@src/fragments/29/fragment29_167940.c

Fresh validation uses master `018e25d62b26d532835c98e334c226383c4f18da`
plus this patch. The unchanged baseline passed first. The normal
syntax-enabled Makefile forcibly recompiles the changed source and links
the complete US ROM:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_19E800.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The result is `build/pokestadiumgs-us.z64: OK`, full ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, and a successful complete retail byte
comparison. Independent original-word and raw-retail comparisons cover all
67 words at `0x19EC6C..0x19ED78`, including the original 24-byte frame.
No new fake, padding, storage, instruction rewrite, layout or CI change is
introduced. The separate `func_8822BAF8` requeue above remains unresolved.
