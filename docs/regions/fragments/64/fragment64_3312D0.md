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

## func_87F0EE0C

This 192-byte owner (48 instructions, 40-byte frame) initializes four
1728-byte port records. For each port, it writes byte-offset 1720 bit 7
from the corresponding bit of `func_8005D8C0()`'s signed word result,
clears bit 6, and copies the port's 16-byte metadata to offset 1704 through
`func_8005D9E0`. It then calls `func_87F0E978` on 18 consecutive 92-byte
entries immediately after the four port records, passing indices 0–17.
The new partial record view expresses the two flag bits and metadata
extent without allocating storage. Unknown fields retain offset names.

`func_8005D8C0` returns `D_80128748`. Its producer, `func_8005AEA0`, sets
one bit per port when the port has a detected game version.
`func_8005D964` refreshes the trainer ID, name and cleared pair in the
port cache; `func_8005D9E0` copies those 16 bytes with two 64-bit loads and
stores. These establish the mask and metadata interfaces.
//@src/585D0.c

Compiled `func_87F0E978` clears the entry's first byte, reads its species
from `D_87F113D0[index]`, calls `func_800625E0` at entry offset 56 and sets
flag 2 at offset 34 for species 25. `Minigame_ProcessInput` resolves this
owner through `func_80003240` and passes `D_801291E0`; it consumes no
result. The existing caller and helper bodies remain unchanged.
//@src/72C30.c

The first recipe matches all original instructions. Directly indexed port
records retain both live byte-pointer inductions, while a byte pointer
walks the trailing entries. The new owner needs no artificial locals,
padding, compiler directives or layout changes.

Fresh validation uses master `203fd4e8c89194273787d4f02ecc25bfffd421d9`
plus this patch. The unchanged baseline passes normal US extraction, the
complete link and retail comparison. Final validation forces the changed
source through the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_3312D0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The link prints `build/pokestadiumgs-us.z64: OK`; full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail and whitespace checks pass.
Independent original-assembly and raw retail comparisons verify the
192-byte span `0x331A7C..0x331B3C`.
