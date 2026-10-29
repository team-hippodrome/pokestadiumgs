# fragment67_344D70

## 2026-10-28 — `func_82908B60` matched; `D_8291B880` owned as file-scope bss

Resets 14 0x40-byte records (`unk_00 = 0`, `unk_02 = 0`, `unk_04 = 10.0f`) with a plain `for` loop; copt peels two iterations and unrolls the rest by four. Retail shares one `lui $at` across the peeled stores to `D_8291B880`/`+2`/`+4`/`+0x40`…. IDO does that only when the array is **defined** in the compiling file; against an `extern` it emits one `lui` per store. So the array is a file-scope `static unk_D_8291B880 D_8291B880[14]`, and `linker_scripts/us/datamig_bss.ld` pins this object's `.bss` at 0x8291B880 (the same mechanism as fragment67_34AB40). The three existing C users now spell it `(u8 *)D_8291B880` instead of a byte `extern`, byte-identical. The remaining assembly users (`func_82908E90`, `func_82909170`, `func_8290954C`) still resolve it through `undefined_syms_auto` at the same address.

## 2026-10-29: `func_8290A208` requeue

requeue (0.79). Record transform for `D_8291A7C0.records[index]`:
- `func_8290A0B0(model.modelId, offset)`, then scale offset by 0.05f and subtract `unk_198` from y;
- `Vec3f_SetComponentsDuplicate(position, position[0], position[1] - offset[1], position[2])`;
- `func_8290A0D0(rotation, record->rotation)`;
- `model.mtx = T(offset) * R * T(position)` via MtxF_SetTranslation/MtxF_Multiply.
- It is followed by an empty function at 0x8290A2F4.

Stack matches with locals declared `offset, position, translation1, rotation, translation2, tmp, record`. Remaining: retail keeps 0.05f in $f2 and computes y in $f0 before z, while ours uses $f0 for the constant. A `scale` local (any position) grows the frame by 8. The permuter (400 s) only reached 230.


## 2026-10-29 — Independently callable default callback boundary

`8290A2F4` is an original zero-argument void callback, not transform padding.
The retail word at ROM34FA80 (`D_82912F80`) contains this address; additional
entries in the four-pointer records beginning34FA84 repeat it.
`func_829084E4` installs a four-pointer record into `D_8291B838`, resetters
including `func_8290ADD0` load the default pointer from `D_82912F80`, and
`func_82908520` invokes every installed slot as void(void). Its instruction
pair is JR RA; NOP at ROM346DF4. Explicitly identifying that referenced
entry corrects the previous extraction extent of `func_8290A208` to236B.
No other function boundary or global detector option changes. The separate
scanner tail8005A5BC has no equivalent independent evidence.


## 2026-10-29 — Default callback and opposite X-motion updates accepted

`func_8290A2F4` is accepted as `Scene67_DefaultCallback` (8B), and
`func_8290B934`/`func_8290BADC` as `Scene67_UpdateModelMotionPositiveX`
and `Scene67_UpdateModelMotionNegativeX` (424B each). The callback uses the
ordinary void(void) interface and implicit return. The motion updates visit
three actual records, move active records by1.44f in mode50 or1.2f otherwise,
update their transform, and transition at positive/negative70.0f. The real
17-halfword scene row is indexed with34-byte stride, not the old68-byte
arithmetic. The previous historical candidates also reversed the fast and
normal step values. Those semantic defects were repaired before comparison.

Direct record indexing produces the correct80-byte frame and all body
instructions. An ordinary `for (i = 0; i < 3; i++)` puts initialization after
the hoisted bases/constants, unlike separate `i = 0` before a `!=3` loop.
That closes the remaining schedule difference for both directions. No forced
register, instruction patch, manual unroll, padding or unused work is used.
The canonical callback is link-verified; relocation-masked motion candidates
require and pass sequential authoritative full-ROM gates. All accepted rows
retain enabled statistics, explicit host syntax checks and retail MD5
1561c75d11cedf356a8ddb1a4a5f9d5d. Private receipts: callback batch
`scene67-callback-transform-first8-v2/gate-0`, motion batch
`scene67-mover-loop-initialization8/gate-*`, under scratch.

Naming and removing two unused matrix probe declarations preserve complete
module sections/text/function extents/semantic relocation tuples in normal
and+20-line controls. The existing local BSS symbol D_8291B880 has an object
path prefix: controls compare its original name only after checking its
OBJECT type, section and offset0. No bytes or relocation records are changed.

### Transform requeue after the proven boundary repair

`func_8290A208` still owns236 bytes and remains ASM. Forty-four new canonical
transform candidates reject. They test actual scalar computation order and
height combination, true coordinate structs, ordinary automatic/static const
factors, actual height capture and argument-assignment value flow, and reuse
of the dead input-index word as the real record address. Both data and all
fields/locals are consumed; no candidate was installed. Typed coordinate
views do not change output. The best exact-frame236-byte body has normalized
.9492/raw.8136 (`scene67-transform-value-flow8`, candidate0); its320-byte
frame, local homes, initial record address and remaining matrix calls match.
The first causal residual is the factor assignedF0 instead of retailF2;
subsequent Y/Z operand colors and update ordering differ. A height-capture
argument variant reaches normalized.9831 but frame328, so it is not stronger
than the exact-frame parent. Separate multiply/subtract stores give240 bytes.
Real three-component loops give264 bytes/frame328. Avoid replaying them or
the old scale-local/permuter grid. Read-only complete positional disassemblies
and results are retained in the corresponding scratch batch directories;
`scene67-transform-current-audit.json` enumerates all44 attempts. Next action:
trace the actual float expression/interference web from the exact-frame
parent under passive stock UOPT/UGEN captures and compare an independently
matched three-component transform before proposing another source family.
No guessed terminal bytes or boundary relaxation is relevant to this owner.


## 2026-10-29 — Four spinning motion updates accepted

B5A4/B76C (456B each) visit four records, clear model flag0x20, rotate Z
by +/-0x71c, move X by1.5 or the retail fast step, and transition at -/+80.
The fast constant is float bits3fe66667 (1.8000001f), one ULP above1.8f.
C0F4/C2A8 (436B each) move Y by2.0f/2.4f then rotate Y by +/-0x71c;
their exit thresholds are independently +65 and -70, not symmetric.
The ordinary indexed for-loop and real17-halfword scene rows reuse the
already accepted X-motion source shape. Names are
Scene67_UpdateSpinningMotionNegativeX/PositiveX/PositiveY/NegativeY.
No instruction/relocation rewrite, padding, artificial work or manual unroll.

Canonical source manifests scene67-four-motion8 and scene67-motion-remaining8
retain enabled stats, normal/+20 whole-module controls, and explicit host
syntax/full native retail-ROM gates. The initial later gates failed when
extraction removed an already accepted owner's generated ASM while a runner
snapshot still referenced it; these are build-input failures, not C syntax
failures. Pinned extraction restored generated inputs before retrying against
the accepted baseline. Only the corrected negative-Y threshold changed source
semantics on retry. All four ultimately accepted; retail MD5 remains
1561c75d11cedf356a8ddb1a4a5f9d5d. Naming preserves complete module section
bytes/extents/semantic relocations under normal/+20-line controls.
Private receipts: scratch/scene67-four-motion8/gate-0,
scratch/scene67-motion-remaining8/gate-*, scene67-four-motion-naming.

A208 remains ASM/requeue: the retained local five-word frontier checkpoint
c906e711 and scratch/scene67-transform-final-attempt-audit.json now cover140
compiled rejections. Actual S1_MtxF matrix locals preserve the best236B,
frame320 body, with five physical F12/F0 operand words unresolved. Existing
factor ownership adds16B data and is rejected. A restricted300-second native
search completed2348 compiles with no improvement. No candidate was installed;
continue from the stock UOPT/UGEN Y-web evidence, not another declaration grid.


## 2026-10-29 — Depth, heading and countdown-fade batch accepted

C45C/C6D0/C908/CB2C are genuine C:628/568/548/552 bytes respectively.
Scene67_UpdateDepthMotion moves four records along Z and handles model120
rotation, model227 animation and visibility/deactivation thresholds.
Scene67_UpdateHeadingMotion advances two records from their heading and
handles the146/144/164 animation family. Scene67_UpdateSpinningHeadingMotion
advances four records, fades alpha in and rotates Z. CountdownFade updates
three timers, fades at the beginning/end, and loads the next scene entry.
Fast heading speed is3.6000001f (retail40666667); spinning speed is10.8f.
All four use the real17-halfword scene rows, actual model fields and consumed
position outputs. No instruction rewrite, padding or artificial work.

The first eight attempts failed because verified animation prototypes appeared
after existing BCF0 callers. An exact-once companion inserts the real return/
argument contracts before BCF0; the full-ROM gate verifies affected older C.
CB2C then accepts with the ordinary indexed for-loop. The two heading bodies
have all opcodes and local vector homes correct but frames eight bytes too
large. Arrays versus genuine vector structs, normal register hints and local
scope do not fix it. Passive stock captures, with normal/+20 complete-module
controls, show source Mmt20 becomes28 in UOPT output. Direct global record
indexing removes the pointer local; declaring the actual output vector before
the index yields exact frames96/120. C908 accepts sequentially. C6D0's combined
hit initially fails because the shared vector-helper prototype appears after
its call; inserting that verified prototype before BCF0 accepts unchanged C.
No incorrect signature or compiler setting is introduced.

C45C's apparent pointer residual was instead a constant-sharing difference:
the body mixed ~1 with0xFFFE when clearing the same visibility flag. Using ~1
for both actual clears retains the shared -2 register, restores the original
constant/register schedule and accepts immediately. Earlier pointer-lifetime
variants and direct indexing were measured negatives, not solutions. Do not
replay them. Canonical tags are scene67-next-motion-forward8 (CB2C),
scene67-motion-direct-record8 (C908), scene67-depth-vector-forward8 (C6D0),
and scene67-depth-consistent-mask8 (C45C). Enabled statistics and explicit
host syntax/full native-ROM receipts remain under scratch/<tag>/gate-*;
retail MD5 is1561c75d11cedf356a8ddb1a4a5f9d5d.

Naming and removal of54 redundant declarations from the four new blocks
preserve complete module sections, bytes, function extents and semantic
relocations in normal/+20-line controls. Earlier prototypes required by BCF0
remain visible; address-keyed entry aliases are retained. Private scripts and
coverage are unchanged in this commit. Remaining ASM owners in this file:
0954C,A208,BEEC,CD54,D124,D42C; A208 retains its independent requeue evidence.


## 2026-10-29 — Four remaining scene updates accepted

BEEC/CD54/D124/D42C replace520/644/776/768 bytes of ASM. Names:
Scene67_UpdateAlternatingAnimationMotion, Scene67_UpdateStaggeredAnimations,
Scene67_UpdateFadeOutSequence and Scene67_UpdateDirectionalMotion.

BEEC moves four active records in alternating X directions, synchronizes their
animations, and handles all six model cases154/157/160/243/244/245. Direct
record indexing avoids redundant timer reloads after position writes. Its
canonical full native gate passes in scene67-sequence-diagnostics8.
CD54 selects the actual10-byte configuration by scene32/33/34 and activates
the second/third records at configured timers, scaled by0.8f in mode50.
The first fast activation writes its visibility flag before resetting its
counter; correcting that source order closes the two scheduled store words.
D124 selects the12-byte configurations for36/37/38, fades previous records,
activates the next every five ticks, computes camera-facing yaw for six records,
and clears all ten at the final fade threshold. Declaring index,distance,pitch,
yaw,config in that order reproduces the actual stack homes; placing config[1]
first in the frame-offset addition reproduces the operand lifetimes. The ten-
record clear is an ordinary loop; stock IDO emits the original peeled/unrolled
body. Distance is a real f32 output of37120; pitch/yaw are real s16 outputs.
The file's older37120 prototype still spells its distance pointer s16*; this
new caller passes the actual f32 object through void* for that legacy interface.
The provider340C0.c establishes the true f32 output contract. No dummy local,
manual unroll, new false prototype or ABI change is introduced.

CD54/D124 probe hits initially encounter missing BEEC generated ASM after that
owner accepted; these are failed build-input gates, not accepted source or new
hypotheses. Against the accepted baseline both pass in
scene67-sequence-angle-width8. The initial four-owner batch also retains eight
compile failures from a redundant void StageFade declaration; provider8470.c
and this file already declare its real s32 result. Removing that redundant
wrong declaration fixes compilation without changing the API.

D42C's rodata subsegment was already ready, including its16-entry switch table.
Four-byte direction records have a halfword angle at+2. The actual index at
record+0x1a3 is unsigned: every retail read is LBU, while the only existing C
use copies its byte. Correcting s8 to u8 preserves complete existing module
bytes under normal/+20 controls. Unused provisional u16[][2] declarations are
removed under the same controls. A real direction struct, direct global
record indexing and repeated angle-field expressions let IDO share the original
angle load/shift and select the original table-base registers. Merely caching
an angle/index in scalar locals did not close the register residual. The first
link/gate-eligible global-direct-table body accepts in
scene67-direction-table-flow8. No character-view casts remain in accepted C.

All four have explicit normal host syntax and native retail-ROM PASS, enabled
canonical statistics and no patches/padding/forced registers/artificial work.
Private gate receipts live under the three accepted batch tags; naming and43
redundant-declaration removals preserve complete module sections, bytes,
function extents and semantic relocations in normal/+20 controls. Old address
aliases are retained. The remaining ASM owners are0954C and A208. A208's
five-word transform requeue and bounded negative search remain unchanged.
