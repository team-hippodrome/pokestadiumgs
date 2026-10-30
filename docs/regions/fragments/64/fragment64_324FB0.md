# fragment64_324FB0 matching notes

## func_87F0277C

One independent 33-word owner now uses C. It receives one real pointer and has no consumed result. Original func_87F006BC supplies an object plus 32, original func_87F0D5B8 supplies its saved pointer plus 12, and compiled func_87E14F98 supplies actual word addresses. The wrapper and its previously failed ABI investigation are unchanged.

The unknown node view preserves pointer fields 0/4, callback at 8, word flags at 12 and signed word counter at 28. Original func_87F025B8 stores the incoming callback at offset 8 and links those node fields. Compiled registrations in fragments 61 and 63 use genuine void(void) callbacks; original registered func_86408D4C and func_864002CC obtain their state from D_87F119DC. No callback argument is fabricated or discarded.

The owner stores the incoming pointer in existing D_87F119D8 and its first node at offset 12 in existing D_87F119DC. It tests flag mask 1, invokes a nonnull callback, reloads the actual global after that call, increments the current counter, and advances through the current node's next field. A callback may change the global: retaining repeated global accesses preserves this behavior rather than caching a node across the callback.

The first typed-loop recipe reproduces all 33 instructions, the 32-byte frame, saved registers, callback dispatch, global reloads and counter scheduling. Full make rom COMPARE=1 with default host syntax checks and explicit md5sum -c baseroms/us/checksum.md5 passes US retail 1561c75d11cedf356a8ddb1a4a5f9d5d. No semantic names, new fakes, invented formals, data/layout/tool/CI changes or weakened verification. A fresh current-head Public PR ROM Gate remains required before merge.

Fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed has no exact owner attempt or owner-specific 64_324FB0 regional note. References from unrelated failed func_86100790 and accepted func_87E0C664 are caller evidence, not owner attempts. The former's wrong conditional-call draft was not reused. Full neighboring 64_325920 notes retain func_87F03204 at normalized/raw 0.9706/0.9706 after repeated float/halfword constant-order probes; that family remains untouched. No historical score exists for this owner. Current master had no regional document here. Every open PR scope was inspected; foreign fragment 13 dispatch/layout remains deferred.

## 2026-10-27 — `func_87F0242C` node field reset accepted (karodo)

`func_87F0242C(void *arg0)` is now C: **40 words / 160 bytes**, leaf. It
resets the record its caller passes at object+0x24: halfwords +0x1E..+0x22
to 0 (+0x22 is written and then copied into +0x20/+0x1E), the f32 triples
+0x24..+0x2C (first 1.0f, later 0.0f) and +0x30..+0x38 = 1.0f, flags +0x1C =
0 / +0x1D = 255, +0x3C and +0xA0 = -0x100, +0x4C = 0x10000, and assorted
zero fields. Finally it copies +0x22 into +0x20/+0x1E again.

The original keeps the first +0x20/+0x1E stores even though they are
overwritten at the end. Only an always-true `if (1) { ... }` around the
middle group reproduces that, marked `// karodo`; a bare `{ }` block lets
IDO delete them (0.90). Found by a 3 s permuter run.


## func_87F029EC — four position-following objects

This owner takes a graph pointer, a pool-state pointer and an unsigned-byte
mask. It creates a main-pool state, allocates four 396-byte objects and
four 24-byte auxiliary records with alignment 4, stores the arrays at
pool offsets 20 and 24, and processes geometry script `D_87F0F728` into
offset 28. After finalizing the allocation and requesting resource 434,
it initializes the object array through this file's `func_87F0252C`.
The geometry script references the still-assembly `func_87F02878` callback.
//@src/3280.c
//@src/3A00.c
//@src/340C0.c
//@src/4CC20.c

For each successful `func_87F025B8` allocation, it registers `func_87F02800`
on the object's node at offset 36, using the object as callback data. It
links object offset 32 to the corresponding auxiliary record, resets and
binds the model, then sets node byte 2 mask 8. `func_87F02800` consumes the
record's position vector at 4 and optional parent pointer at 0.

Four distinct record setup blocks initialize RGBA bytes 18–21 to white,
selector byte 16 to 0/1/2/3, and byte 17 to the supplied mask's respective
masks 1/2/4/8. The parent pointer and position vector become zero. Actual
`Vec3f_SetComponentsDuplicate` writes the three supplied floats and returns
the vector pointer; its result is ignored here. Original `func_87F02878`
uses the selector and mask to choose texture entries from `D_87F0F640` or
`D_87F0F650`, then reads the four color bytes for its environment-color command.
The tables contain entries 2–5 and 6–9, respectively. Unknown meanings retain
their existing names.
//@src/340C0.c

The existing wrapper `func_87F029B8` supplies `D_87F119C0`, its incoming
state address and byte mask. Its local forward declaration now has the
actual pointer/byte parameters; an explicit pointer cast preserves all 52
wrapper instruction bytes. Inspected assembly callers `func_86107A20`,
`func_8690073C` and `func_86A004B4` pass the state and a byte read at context
offset 8578, and consume no result.
//@src/fragments/49/fragment49_code.c
//@src/fragments/59/fragment59_code.c
//@src/fragments/60/fragment60_code.c

The C matches all 176 instruction words (704 bytes) and the 64-byte frame.
The compiler supplies the original final four zero bytes as normal section
alignment, preserving the complete 708-byte extracted span. A loop for the
four record setup blocks emits a smaller 496-byte body and 56-byte frame;
the explicit per-record setup follows the retail field stores and four
vector-helper calls. The allocation loop terminates at index 4 by equality.
All earlier C bodies and existing rewrite pragmas remain unchanged. No new
fake, storage, padding pragma, instruction rewrite or layout change is added.

Fresh validation on master `96ed6d5da224a2a2f3a650cec6696706b574613b` plus
this patch follows normal extraction and an exact unchanged baseline:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_324FB0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full syntax-enabled link prints `build/pokestadiumgs-us.z64: OK`; ROM
MD5 is `1561c75d11cedf356a8ddb1a4a5f9d5d`. Complete retail comparison and
whitespace checks pass. Independent original-assembly and raw-retail
comparisons verify all 708 bytes at ROM `0x32565C..0x325920`, including the
four natural alignment bytes.
