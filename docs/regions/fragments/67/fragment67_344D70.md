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
