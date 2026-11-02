# Region notes — fragment63_308D70

## func_87E06D8C — session 60

The independent initialization wrapper matches all 47 words, its original 32-byte frame and all fourteen calls. The original func_87E08EF0 caller passes its object+1176 and a second pointer-bearing word from object+32. The existing compiled func_87E0027C caller and its declaration agree with void(u8 *, s32); retain that second word handle and cast only at the signed-byte read at offset 8579. No incoming arguments or return values are invented.

Canonical src/3280.c establishes s32 main_pool_push_state(s32). Its original tag is written as decimal 1296516947. Preserve the second word at owner offset 368, sign-extended byte at offset 8, zero words at offsets 4 and 0, and the byte mask clearing bit 0x80 at offset 396. The ordinary full-width complement preserves the original ANDI and byte store.

The two no-argument helpers are established by compiled func_87F0BD10(void) and the original func_80041E2C assembly, which constructs all arguments internally. The existing pointer-formal empty func_87E06D84 remains unchanged. The local compiled helpers retain their actual pointer/word contracts, with explicit pointer-to-word casts where their existing definitions use word handles. The original func_87E069A4 and func_87E06BCC bodies consume one pointer each. All eight pointer-bearing calls and final three word-argument setters retain the original call order. No skipped helper is retried or modified.

Fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed has no exact owner attempt or owner reference. The full 308D70 regional note was read: unrelated func_87E07278 remains at normalized .9697/raw .8485; the func_87E06BCC 0/raw None record is not an owner attempt or evidence for retrying that helper. Existing accepted sibling recipes and previous process/user skips remain intact.

The first candidate passed the normal US build with host checks and COMPARE=1 after exact upstream imports through master 95fe6846ebcb9a1116be0f16f92705cfaaf1f27b, including its narrow fragment-44 rodata split. Explicit md5sum -c baseroms/us/checksum.md5 reported OK, MD5 1561c75d11cedf356a8ddb1a4a5f9d5d. All previously merged sources, including #1060/#1061/#1062, remain present. No new semantic names, tokens marked known, fakes, padding, helper implementations, data, layout, compiler, CI or verification changes were authored.


## 2026-11-02 — `func_87E07A2C`: rewrite cleanup requeue

Base: `4d4dea19cb9d3ef8c26c6931b4bda157c40862c5`. The installed function
still has two word rewrites and source scaffolding; no replacement is
accepted. A reconstruction with scalar locals, a real positive-count guard
and nested selection loops produces the retail 152-byte instruction shape.
Declaring the initial selection first restores the 32-byte frame and its
28(sp) home. It removes the dummy two-word array, multiplied-zero predicate
and empty conditionals from the candidate, but register assignments differ.

Four stock normal/+20 module controls reproduce the existing source and
this reconstruction independently. Procedure 43 is verified from each
captured Uent/Ucomm header. Twelve stock/observer-off/observer-on controls
preserve optimized Ucode and both symbol outputs. Normal and blank traces
agree: the existing source has 12 allocation events, the clean source 10.
The existing graph contains an extra unsigned `Uneq(Urem(RNG, 145), 0)`
range with computed benefit 50.5 and divisor 4. Its internal color is 1; the clean source
lacks this range. The original multiplied-zero/empty tests must not be
reintroduced to recover that allocation graph.

A calibrated single-worker 60-second permuter search made 1368 mutations
with no compile errors and no improvement over its base score of 80. Raw
canonical-candidate bytes, the target call relocation, and an AST-regenerated
score-zero positive control pass. Count aliases, scalar default/cursor
separation and remainder-expression lifetimes do not improve the complete
candidate. Guarded pre-test loops add two instructions. Next: test a genuine
control-flow use of the count predicate or a different source lifetime;
preserve the dummy-free body and measured frame rather than adding a dead
allocation range. No candidate in this block was installed or ROM-gated.
