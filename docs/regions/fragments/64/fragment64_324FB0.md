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
