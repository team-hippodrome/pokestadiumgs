# fragment17_11A7F0

## 2026-10-28 — `func_8220B7A0`: requeue (address-CSE finding)

requeue. Box-overlay start: if `D_822109C0` (active) is 0, set active = 1, `+2 = 0`, x/y at `+4`/`+6`, copy two RGB triples to `D_822109CC` and `D_822109CF` (contiguous: a `u8 [2][3]`), set alpha `+8 = 0xFF`, call `func_8220AE30(&record)` and return 1. The record (0x822109C0..0x822109D8, `.bss`) is used only by this file (`func_8220B248`, `func_8220B478`, `func_8220B770`); owning it as `static` and pinning it in `datamig_bss.ld` is byte-identical, so the layout half works.

The code does not match, because retail shares one `lui $at` for the four `s16` field stores yet forms the record's address fresh for the call. In IDO, once the address is also passed to a function, every spelling (defined struct, `s16[6]`, separate statics, mixed struct + array, `extern` struct) CSEs it into `$s0` for all accesses. Scores: struct 0.52, mixed 0.61, separate statics 0.82 (`$at` per store). fragment16's `func_8200070C` (`bzero(&sFadeState)` then field stores) has the same signature. Next: find what makes IDO keep a per-access address while sharing `$at` for adjacent stores; a function-local static avoids the CSE (`func_8F100020`), but the record is shared by four functions here.
