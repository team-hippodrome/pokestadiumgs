# Region notes -- src/fragments/64/fragment64_3312D0.c

## 2026-10-27 — `func_87F0F2B8` per-port item pass accepted

`func_87F0F2B8(unk_func_87F0F2B8 *ports, s32 port)` is now C: **54 words /
216 bytes**, frame 0x30. It calls `osGetTime()` and discards the result.
If the top bit of word +0x6B8 of the 0x6C0-byte record `ports[port]` is
clear, it returns 1. Otherwise it calls this file's `func_87F0F234(port,
&item.unk_30)` for each of the 18 0x5C-byte items whose signed byte +0x30 is
non-zero, and returns 1 when `func_81A00074(&D_87F15BB0, port)` succeeds,
else 0. The `fragment63_30B540.c` caller passes the record base and the
port.

Index the typed record and item arrays directly (raw byte arithmetic lets
IDO CSE `port * 0x6C0` and count the loop in items instead of bytes), and
declare `i` before `result` (the result's frame slot is +0x28).

## 2026-10-28 — `func_87F0E660` matched

A debug scan whose bodies were stripped. It walks four 0x6C0-byte records (`unk_func_87F0E660`), each with 18 0x5C-byte entries and 3 0x10-byte entries. Only the loop skeletons survive, so the empty `if` bodies and `if (entry) {}` are marked `// karodo`. `entry = &arg0[i]` reproduces retail's dead `$a1` record pointer (computed but never read), while both inner loops index `arg0[i]` directly; the permuter got the pointer split, and the clean typed-parameter spelling was found by hand.
