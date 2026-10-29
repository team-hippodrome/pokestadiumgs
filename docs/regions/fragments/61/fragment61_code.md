# Fragment 61 camera callback

## Accepted: `func_86B00020`, 2026-10-20

The 208-byte callback sets the perspective and places the camera at
`(0, sin(angle) * radius + 400 + centerY, cos(angle) * radius)`, looking
toward `(0, centerY, 0)`. `D_86B0D16C` supplies the angle, `D_86B0D168`
the radius, `D_86B0D170` the center height and `D_86B0D174` the field of
view. When `D_86B17EAC` is zero, the original `func_87C037C0` camera call
with `D_86B17E2C` is preserved.

The actual six-float/`u16` helper signature and the consumed `u16 roll = 0`
value reproduce the original instructions and 56-byte frame without the old
word rewrite or unused padding. The normal runner accepts the callback with
`link_verified: true` and a full-ROM gate; do not candidate-probe it again.

Shared evidence and source-shape limits are recorded in
`docs/regions/fragments/60/fragment60_code.md`. Independent retail links
cover every one of this module's 63 function extents and all 53,568 text
bytes. All frozen-stage, whole-module, collateral, public compiler path,
blank-line, provenance, syntax, regression and final normal-ROM checks pass.
Other owners in this file remain outside this correction.


## func_86B09480: counter-driven node update

The 172-byte owner (43 instructions, 24-byte frame) obtains its current node
from `D_87F119DC`. It reads the signed counter at offset 28 once. After
counter 10 it calculates `(counter - 10) * D_86B0E018 + 2.0` in double
precision, converts to float, and writes offsets 92, 88 and 84, reloading
the global node pointer between stores. It also subtracts 12 from the word
at `D_86B17A78 + 148`. After counter 30 it releases the current node through
`func_87F026E8`. The field meanings beyond these operations remain unknown.
The existing double constant is 0.06 in the US retail data; no new storage
or rounded replacement literal is introduced.

`func_86B0952C` registers this no-argument callback with `func_87F025B8`,
initializes its counter to zero and the three float fields to 2.0.
`func_87F0277C` invokes the registered callback and increments the current
node's counter. `func_87F026E8` takes the state and node pointers, clears
the active flag, unlinks the node and decrements the state's active count.
The three repeated declarations of that helper and `D_87F119D8` in this
translation unit now describe their actual pointer arguments and storage;
existing caller bodies remain unchanged.

//@src/fragments/61/fragment61_code.c
//@src/fragments/64/fragment64_324FB0.c

Validation uses master `796f1ce5815fdff0a176bbddedda7ea01b412733` plus
this source change. The first C recipe reproduces all 43 original words,
including the global reloads, floating-point operations and counter tests.
The raw retail span `0x2FC3D0..0x2FC47C` also compares exactly.

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/61/fragment61_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The default host syntax check, forced translation-unit rebuild and full US
link pass with `build/pokestadiumgs-us.z64: OK`. The complete ROM has MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d` and matches retail byte-for-byte,
including every existing caller affected by the declaration corrections.

## 2026-10-28 — `func_86B0355C` matched (model-follow callback)

For mode 2: copy the x/z (0xAC/0xB4) of the 0x168-byte model record
`D_86B16DA0[idx]` (idx = s32 at `arg1 + 0x14`) into `arg1` +0x24/+0x2C. When
`D_86B17A78[idx]`'s s32 at +0x34 is 16 and its f32 at +0x48 is not 180.0f,
spawn `func_86B05484(x, y, z, 0xFF)` on every third `func_8003EC54(model)`
value. Returns 0. Retail spills `model` to sp+0x18 in a 0x28 frame. The
named local alone lands at 0x1C, and an inline expression shrinks the frame
to 0x20. One marked `s32 pad; // FAKE` gives both (as in fragment19
`func_823016B4`). The prototype is retyped from `void` to `s32`.
## 2026-10-28 — `func_86B07FB0` matched (step choice)

`s16 func_86B07FB0(s16 a, s16 pos, s16 step, s32 mode)`: if
`step < func_86B08088(a, pos)`, evaluate `func_86B08088` at `pos + step`
(kept as s16 `upValue`) and at `pos - step` (s32 `downValue`, compared
untruncated). Mode 1 returns `pos - step`, mode 2 `pos + step`; otherwise
return whichever side has the smaller value, else `a`. Locals `s16 up;
s16 upValue; s32 downValue;` give retail's homes (upValue at 0x24 behind
`up`). `pos - step` stays an expression (a spilled temp, not a home), and a
named s32 `down` adds a frame word.

## 2026-10-29 — `.rodata` owned; `func_86B014E8` matched; `func_86B03228` requeue

`fragment61_data` held this object's `.rodata` (no strings). It is now split:
`data` up to 0x300B80 (`func_86B00A3C`'s first float), `fragment61_code`'s
`.rodata` up to 0x300FC0 (end of `jtbl_86B0E058`), then a `fragment61_tail`
rodata blob. The 20 C references into that range are now literals. Two
needed care:

- `0.072` must be written `0.07200000000000001`. IDO rounds the short
  literal one ULP low (`...DF3B` instead of retail's `...DF3C`).
- `func_86B05610` had hoisted its 900.0 threshold into a local to match
  against the extern. With a literal that schedules differently. The real
  shape is a `for (i = 0; i < 4; i++)` loop over the `s32` array at
  `D_86B17A78 + 0x34` and the `f32` array at `+0x58`, comparing directly
  against `900.0`.

`func_86B014E8` (frame draw) matched.

`func_86B03228` (**requeue**, 0.94, `scratch/c/228_best.c`):

- Every case, the empty `for (i = 2; i < 10; i += 4) {}` loops, and the
  final `D_86B178E0 = D_80094904` are exact.
- The only difference is two delay slots. After `guRandom() % 300 == 0`,
  retail uses `bnel` + a duplicated `lw v0,24(sp)` where ours hoists
  `lui a0` above `bne`. The `arg0 == 2` test uses `bnel`/`lw ra` where ours
  uses `bne`/`lui t9`.
- Already tried: nested `if`, `else if`, `switch (arg0)`, `!(...)`. A
  300 s permuter run found nothing real.

`func_86B0B04C` (RNG setup, 308 lines) has been read but not written.
`func_86B01A94`, `func_86B023FC` and `func_86B04970` are large.

`func_86B0B500` (**requeue**, `scratch/c/b500_best.c`):

- The `.s` also holds the empty callback `D_86B0B600(s32, u8 *)`, which
  `func_87F025B8` uses, so the candidate must define both.
- Max over the four `s32` at `D_86B17A78 + 0x17C`, then four
  `if (best == D_86B17BF4..C00) D_86B17CEC..CF8 = 1`, then zero 0x274..0x280
  if their product is nonzero.
- Any index loop (`for` or do-while) is fully unrolled by `copt`.
- A pointer do-while from `D_86B17A78` to `D_86B17A88` gives retail's loop
  shape. But ours keeps the `D_86B17A78` base live in `$a1` (pointer in
  `$v1`) and reuses it for the 0x274.. block. Retail walks the pointer in
  `$a0` and re-forms `lui v0` for the later block.
- Next: a spelling where the loop's base and the later block's base don't
  CSE, such as a struct type for the 0x274 block.
