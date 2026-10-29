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
