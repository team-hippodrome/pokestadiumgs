# fragment67_344D70

## 2026-10-28 — `func_82908B60` matched; `D_8291B880` owned as file-scope bss

Resets 14 0x40-byte records (`unk_00 = 0`, `unk_02 = 0`, `unk_04 = 10.0f`) with a plain `for` loop; copt peels two iterations and unrolls the rest by four. Retail shares one `lui $at` across the peeled stores to `D_8291B880`/`+2`/`+4`/`+0x40`…. IDO does that only when the array is **defined** in the compiling file; against an `extern` it emits one `lui` per store. So the array is a file-scope `static unk_D_8291B880 D_8291B880[14]`, and `linker_scripts/us/datamig_bss.ld` pins this object's `.bss` at 0x8291B880 (the same mechanism as fragment67_34AB40). The three existing C users now spell it `(u8 *)D_8291B880` instead of a byte `extern`, byte-identical. The remaining assembly users (`func_82908E90`, `func_82909170`, `func_8290954C`) still resolve it through `undefined_syms_auto` at the same address.
