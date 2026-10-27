# fragment32_1B8DE0 matching notes

## func_88307DA4

This no-argument, void owner reads signed byte `D_88308EB1`. For selector 0
or 1, it calls existing `func_88002640` with the record at
`&D_88308ED0 + selector * 32`. Other selector values cause no helper call.
The switch preserves the original signed load, two comparisons, shared
call path and address calculation.

Compiled `func_88307C2C` initializes the two nodes at `D_88308ED0` and
`D_88308EF0` through `func_880024FC`, establishing their 32-byte spacing.
The existing scalar declarations remain unchanged; the owner forms a byte
pointer for indexing and allocates no storage.
//@src/fragments/32/fragment32_1B8DE0.c

Compiled `func_88306E90` stores its signed byte argument in `D_88308EB1`.
Original `func_88300B48` calls this owner without arguments when
`D_88308EA0` is zero, then proceeds without consuming a result. Existing
`func_88002640` takes one node pointer, returns void, and updates mode/status
before calling `func_8800254C`. These producers and consumers support the
selector width, record addresses and helper interface. Existing address-based
names remain.
//@src/fragments/32/fragment32_1B8010.c
//@src/fragments/32/fragment32_1B1330.c
//@src/fragments/29/fragment29_168330.c

The first switch recipe matches all 17 instruction words (68 bytes), including
the 24-byte frame. Existing C, helper bodies, callers and layout remain
unchanged. No new fakes, qualifiers, instruction rewriting or CI changes are
required.

Fresh validation uses master `3ae5d2640371e8c0aa66db7d397d401f86300d3c`
plus this patch. The unchanged baseline passed its own complete US build and
retail comparison. Final validation forces source recompilation through the
default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/32/fragment32_1B8DE0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons cover
all 68 bytes at ROM `0x1B90B4..0x1B90F8`.

## 2026-10-27 — `func_88307F28` two-record clear predicate accepted

`func_88307F28` is now C: **32 words / 128 bytes** plus two alignment
nops, leaf. It returns 1 when both 0x20-byte records at `D_88308ED0` have
their halfword +0x04, word +0x08 and halfword +0x16 all zero (overlay
`unk_D_88308ED0`).

Source shape: each record sets its **own** flag with `if (a && b && c)
flag = 1; else flag = 0;` (the else arm produces the target's
branch-to-join). Then `result = first != 0; if (result) { ...; result =
second != 0; }`. Reusing one flag variable for both records moves the base
pointer from `a1` to `a0` (0.73), and `return first && second` reshapes the
tail.
