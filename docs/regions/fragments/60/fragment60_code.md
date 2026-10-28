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

## 2026-10-29: `func_86A059AC` requeue

requeue (0.28). `(s32 player, f32 x, f32 z, s32 kind)` box test against `D_86A443F0.position[player]`, where `entry = D_86A0D560 + kind*0x18`:
- `halfWidth = entry[0x10] * 8.333333f * 0.8f + D_86A45AC8`;
- `px < x + halfWidth && x - halfWidth < px && pz < (0.0f + D_86A45AC8) + z`;
- and `(f64)z - ((f64)(entry[0x14] * 8.333333f) * 2 * 0.8f + margin) < (f64)pz` (the double literal is `(f64)0.8f`).

Retail sets v0 = 0 before the first compare and keeps an explicit `add.s` of 0.0f, while IDO folds our `0.0f + margin`. Find the source of that unfolded zero (probably a zero-valued field or a variable) first.


## 2026-10-29 native block: `func_86A059AC` accepted

The 256-byte leaf tests a player's `position[arg0]` against the item selected
by `arg3` in the 24-byte `D_86A0D560` table. The center comes from `(arg1,
arg2)`. Horizontal half-width is `entry.width * 8.333333f * 0.8f + margin`;
the upper z extent is zero plus the margin, and the lower z extent uses
twice the scaled height in double precision. The strict comparisons leave
the rectangle's edges outside. `func_86A02A9C` supplies each player index,
the object's x/z coordinates, and the item index.

The source uses a two-component upper extent, a real position pointer, and
a margin loaded once. Both extent components feed comparisons. The scalar
literal version folded the zero-plus-margin addition away and produced 248
bytes. Keeping the consumed upper-extent components recovers the original
256 bytes without dummy locals, altered ABI, instruction rewrites or
coalescing. The final accepted spelling includes the margin in the horizontal
extent before comparing it. Nearby `func_86A05B4C` and `func_86A05C94` use the
same bounds calculation over 20-byte collision records.

At base `d06e6d3c`, normal and twenty-leading-blank controls reproduce the
whole module's sections, text, function extents and relocations. The canonical
runner accepted `bounds:margin-in-extent:4` through the sequential full-ROM
gate; its receipt is `scratch/bounds3/gate-0/receipt.json`. The receipt records
an explicit normal host syntax check and retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, using native IDO 7.1 compiler SHA256
`975142f2e9c4ceb72954a51da53af6e44792b91c7c8f628b05e980ce83980944`.
The accepted installed object's independent link-shape check passes; its only
raw instruction differences from the assembly control are three relocation
fields for compiler-emitted constants. Probe-stat provenance confirms the
removed pragma has an accepted attempt. The owner remains assembly in
upstream `7a127bb6`, so this acceptance is novel at that revision.
