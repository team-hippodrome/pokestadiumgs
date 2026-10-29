# Region notes — fragment31_193D50

## func_88220AD0 — session 60

The independent 44-word wrapper matches with its original 584-byte frame. Original caller func_8820908C passes two words (320, 240) and ignores the result; compiled callers pass either literals or signed halfwords, and the existing local declaration is void(s16, s16). The owner preserves both actual signed-halfword formals and their home loads after the buffer-formatting calls.

A real 512-byte local buffer is passed to canonical void *func_8004C8A0(void *, s32, s32, s32) with (buffer, 512, 31, 19). The preceding count is obtained from actual no-argument word-result func_88203FB4 and passed to actual s32(s32, s32) func_8004C594 with selector 4. The returned buffer pointer is forwarded directly to func_88903C50, preserving the original temporary lifetime and stack layout.

The full original func_88903C50 body was audited: its two coordinates are read as signed halfwords, color/mode fields as bytes, two pointer arguments are stored as pointer fields and used as word output pointers, and its final callback is saved before later use. The supplied func_88903B00 is compiled void(void); D_88000E4C is the original no-argument JR/NOP stub used as a callback. Keep the constructor's actual thirteen-argument declaration; do not fabricate incoming arguments or change the callback/helper implementations. The known failed func_88903B2C and skipped 88004804/88004990 families were inspected only as ABI evidence, never retried or modified.

No exact owner attempt, reference or owner-specific regional record was found at fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed, so there is no historical normalized/raw_similarity_score for this owner. Current master and all open PR scopes were inspected before editing. This first candidate passed the normal US build with host checks and COMPARE=1, followed by explicit md5sum -c baseroms/us/checksum.md5: OK, retail MD5 1561c75d11cedf356a8ddb1a4a5f9d5d.

No new semantic names, tokens marked known, artificial padding, fakes, data, layout, CI, compiler or verification changes were authored. The two new source/doc blobs are based on master 58cb58d58dc38711c4d3ec2517436161bd40639a. All earlier matches and failure notes remain intact.


## func_88220E08 — name-entry window initialization

This one-word, void initializer allocates 128 bytes at `D_88234800`, stores
its mode at offset 124 and clears 118 bytes beginning at offset 4. It passes
that output buffer, the incoming mode and `func_88220B80` to the existing
name-entry constructor `func_88700364`. The constructor stores the output
pointer and callback word in its own state and selects the keyboard and
capacity by mode. Its compiled coordinate helpers `func_887002F4` and
`func_8870032C` return signed words, which this owner narrows to signed
halfword coordinates.
//@src/fragments/36/fragment36_code.c

The existing window constructor `func_88004804` receives mode 3, those
coordinates, color bytes 220/220/180 and four callback addresses. It returns
an unsigned-byte slot in the six-entry, 76-byte `D_8800ED50` array. This owner
stores the selected window pointer at the beginning of its allocated record,
writes halfwords 385 and 348 at window offsets 16 and 18, then clears
`D_880068B4`. The callbacks are the existing input/draw routines
`func_88700CE4` and `func_88701240`, followed by `func_88220BB8` and
`func_88220BDC`. The latter reads the saved mode. The completion callback
`func_88220B80` advances the selected window and sets `D_880068B8`.
//@src/fragments/29/fragment29_168330.c
//@src/fragments/31/fragment31_193D50.c

Compiled caller `func_88214330` invokes the owner with mode 1. Original
`func_8821EC34` invokes it with mode 0. These uses establish its incoming
word and window-initialization role; unknown function names remain intact.
//@src/fragments/31/fragment31_186690.c
//@src/fragments/31/fragment31_190BB0.c

The accepted C reproduces all 78 words (312 instruction bytes) and the
88-byte frame. Naming the consumed window slot before the two coordinate
locals reproduces the first coordinate's stack home at offset 82. An inline
slot calculation instead uses offset 86 and differs in two words. All
existing C remains unchanged, including the later window initializer whose
calls now see the verified allocation and window-constructor declarations.
No new storage, padding, fake, layout or instruction rewrite is introduced.

Fresh validation on master `1e134dac9c50998f48be57936af184736cd9439f` plus
this patch forces the changed translation unit through the normal
syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_193D50.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Complete retail comparison and whitespace
checks pass. Independent original-assembly and raw-retail comparisons verify
all 312 bytes at ROM `0x194088..0x1941C0`.
