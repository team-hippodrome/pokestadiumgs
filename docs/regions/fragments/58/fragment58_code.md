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
