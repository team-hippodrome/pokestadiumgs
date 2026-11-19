# fragment58_code matching notes

## func_83402D00: position step toward a target

This 168-byte owner (42 instructions, 56-byte frame) obtains the distance
and two signed halfword angles from `D_83404274` to `D_83403D80`. When the
distance exceeds 10, it computes a new position at one tenth of that distance
along the same angles and copies all three resulting components back to
`D_83404274`. The multiplication uses the existing double `D_834040D8`
(0.1), then narrows to float before the position helper. The original
threshold, floating-point precision and call order are preserved.

The target's US data words decode to `(0, 220, 0)`. `D_83404274` is the
three-float field at `D_83404250 + 36`; compiled `func_83402C80` copies that
field before its anchor lookup. Original `func_83402DA8` invokes this owner
with no arguments and ignores its result when its surrounding gates pass,
including the word `D_834047F0 == 207`. The surrounding state behavior
remains unchanged.
//@src/fragments/58/fragment58_code.c

`func_80037120` writes an actual float distance and two signed halfword
angles. `Camera_ComputeEyeFromAngles` writes the three-float output position.
`Vec3f_SetComponentsDuplicate` stores the supplied components and returns
its destination pointer. Its existing declaration here now reflects that
pointer result; existing caller `func_83402C80` ignores it and retains its
original machine code. The new owner likewise consumes no helper result.
//@src/229E0.c

The first C recipe reproduces all instructions and the complete frame using
one real three-float output buffer, one distance float and two angle
halfwords. No padding, artificial locals, fakes, instruction rewrites,
allocated storage or layout changes are introduced. The unknown function
and data names remain unchanged.

Fresh validation uses master `4e92d7a43909a7b47b4f9c4f13dd3bd50ea5cc30`
plus this patch. The initial baseline passed normal extraction and its full
US build. Separate fragment 11 and 47 changes merged during investigation;
the updated unchanged baseline passed another complete build and retail
comparison before this source was reapplied.

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/58/fragment58_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Default host syntax checks, forced source compilation and the complete link
pass with `build/pokestadiumgs-us.z64: OK`. The full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail and whitespace checks pass.
Independent original-word and raw retail comparisons verify all 168 bytes
at `0x2CB110..0x2CB1B8`.

## 2026-10-28 — `func_83400A64` / `func_83400AFC` matched

Twin model callbacks: on step 2 they copy a 3-byte color plus a fourth byte from the camera-color record at `D_83404188` (`colorA` at + 0x78, `colorB` at + 0x8C) into the model at + 0x18. They then read the camera angle with `func_80037120(cam + 0xB4, cam + 0xA8, ...)` and store `angleX ± 0x2000` and `angleY`. Spelling details:
- Use a struct-member access `((Fragment58CameraColors *)&D_83404188)->colorA[i]`, so IDO strength-reduces to retail's `record + i` induction with 0x78 in the load offset. A named `D_83404200` or a cast `u8 *` index gives the wrong base.
- Copy `arg1` into a `dst` local, which keeps it in `$s0`.
- Declare `s32 i; u8 *dst;` before `distance`, which puts the out-parameters at `sp+0x30..0x34`.

## 2026-10-28 — `D_83404188` typed as a record

`D_83404188` is now declared as `Fragment58State188` (state word, `unk_14`/`unk_18`, and `colorA`/`colorB` at 0x78/0x8C) instead of an `s32` read through a cast struct. The camera-color callbacks read `D_83404188.colorA[i]`, `func_834022F8` switches on `.state`, and the `+0x14`/`+0x18` stores use the named fields. Byte-identical.

## 2026-11-19 — `func_834022F8` matched

Sliding-sprite intro: four sprites move toward the target in `D_83403F2C` and each is drawn twice. Once the first sprite reaches both targets, only it is drawn, and a flash overlay pulses in and fades out.
- `D_83403F34`, `D_83403F38` and `D_83403F3C` are function statics. As externs, IDO hoisted their addresses into saved registers. The fragment's C `.data` now runs from `0x2CC330` to `0x2CC350`. `D_83403F2C` becomes `s32[2] = { 0x43, 0x43 }`, and the remaining 16 zero bytes stay in `asm/us/data/2CC350.data.s`.
- The loop is `for (i = 0; i < count; i++)` over `D_83404848.unk00[i]`, `[i + 4]`, `[i + 8]` and `[i + 12]`. IDO turns `i` into the pointer in `$s0` and rebuilds `base + count * 4` before the texture call. A pointer loop instead let it rewrite the later `count == 1` tests as pointer compares.
- `D_83404188` words go through `((s32 *)&D_83404188)[n]`, which keeps the address in `$fp`. A `(u32)`-cast pointer local takes `$s7` instead.
- The float rounding is one expression per axis, `ROUND_DIFF58(a, b)`. Named `a`, `b` and `half` locals change the frame and the float register picks.
- Alpha arguments are passed plain, without `& 0xFF`. The extra mask shifted the temp-register rotation through both display-list blocks.
- One unused `s32` after `count` (marked FAKE) puts the two hoisted display-list addresses at retail's `sp+0x68` and `sp+0x60`.
