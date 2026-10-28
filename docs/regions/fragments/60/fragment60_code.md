# Fragment 60 camera callback

## Accepted: `func_86A00020`, 2026-10-20

The 188-byte callback sets the perspective, then positions the camera at
`(0, sin(angle) * radius + 400 + centerY, cos(angle) * radius + centerZ)`
looking toward `(0, centerY, centerZ)`. `D_86A0D4DC` supplies the angle,
`D_86A0D4D8` the radius, `D_86A0D4E0`/`D_86A0D4E4` the center and
`D_86A0D4E8` the field of view.

The shared helper's actual definition in `src/229E0.c`, `func_80038E14`,
takes six `f32` coordinates followed by a `u16` roll angle. It stores the
eye/target coordinates and uses the roll angle's high bits to index the
trigonometric tables for the up vector. The callback now declares that
actual contract and passes a real `u16 roll = 0` local as the final argument.
The first coordinate is the ordinary integer literal `0`, converted to
`f32` by the prototype. No fake declaration, unused padding local or
instruction rewrite is needed to obtain the original 56-byte frame and
zero-argument materialization.

The normal runner accepts this source with `link_verified: true`, followed
by the full-ROM gate. Stop candidate-probing this owner after acceptance.
Real scalar/vector experiments without the roll local did not match; unused
padding is not a substitute for the consumed roll-angle value. Runtime
aggregate initializers are rejected by this IDO frontend and establish no
code-generation result.

The paired fragment-61 callback uses the same mechanism. Four successful
stages (assembly baseline, each individual acceptance and declaration cleanup)
freeze seven complete modules inside the successful gate callback, reread
receipts and externally hash every object before returning and before later
compilation. Every allocated-object fingerprint equals its original baseline.
Independent retail-address links cover all 69 function extents and 54,448
text bytes in this module and all 63 extents/53,568 bytes in fragment 61.
Native/public compiler paths, twenty-leading-blank controls, accepted-attempt
provenance, all-source host syntax and all 76 native tests pass. The final
normal ROM gate retains MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.

Only this callback and its helper declaration change in the source file.
Unrelated assembly owners and existing C remain untouched. No private helper
or coverage changes are part of the public correction.

## 2026-10-28 — `func_86A03F48`: requeue

requeue. The queue push that `func_86A0405C` pops:
- returns 0 when the player's queue holds 5, or when `D_86A0D560[item].cost (+4) + unk_00E8[player] >= 6`;
- otherwise `count + 1` and `values[(head + count) wrapped at 5] = item`;
- adds the entry's `f32 +8` to `unk_00D8` and its cost to `unk_00E8`, sets `unk_00F8 = item`, and calls `func_86A0BA80(player)` when the cost total reaches 5;
- returns 1.

Retail keeps an `entry` pointer (which spills `arg1` to its home), loads the cost once, and reuses `head` for the wrapped slot. Best 12 ops: retail holds the queue base in `$v1` and copies `count` into a second register (`or a3,t0`). A 240 s permuter suggested computing `head + count` before the full check; that spelling alone does not match.

## 2026-10-28 — `func_86A0588C`: requeue (offset-ring reach test)

Semantics: `D_86A444D8` is `D_86A443F0.unk_00E8`. The per-player index
selects an `F60C7Pair` from `D_86A0F2D4`, and its x/y feed
`MathUtil_Atan2s` and `sqrtf`. The heading adds `unk_0E6C[arg0]` (an
`s16[4]` at 0x0E6C), and the result indexes the cos/sin tables
`D_80088E50`/`D_80087E50`. The test is whether
`(pos.x - cos*d - arg1)^2 + (pos.z + sin*d - arg2)^2 < D_86A0F2BC[arg0]`.
`angle` must be `s32`: `s16` adds an `sll`/`sra` pair. The best local
similarity is 0.486 (72/72 instructions). A 96-form grid (struct field vs
`D_86A444D8`, pair pointer vs direct, position pointer vs direct, three
negation spellings, if vs expression return, three declaration orders) and
a 300-second permuter (2660 -> 2170) did not close it. Retail homes `arg2`
first and reuses `$a2` for `arg0 * 4`, which it spills to 0x18. Next: start
from that early `$a2` reuse; check whether `D_86A0F2BC[arg0]` is loaded
through the same `arg0 * 4` temporary before the call.
