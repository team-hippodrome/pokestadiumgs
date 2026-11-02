# Fragment 67 342DB0 matching notes

## 2026-11-03 — particle initializer word rewrites: requeue

`requeue` **func_829064D0**, 432 bytes, revision `4835fc02`. All 15
rewrites change registers beginning with the integer result/store after
`func_829063EC(546)`, then cascade into the later random fields. An actual
36-byte particle view preserves the opcode shape but retains the register
residual (normalized 1.0, raw 0.8611). The record has four leading floats,
six halfwords, the float at +28, and bytes at +32/+33. The drawing consumer
reads +33 as an unsigned color channel. Internal unknown fields remain
unknown. Narrow/float carriers for the second RNG result, removing redundant
unsigned promotions and a consumed target-halfword temporary did not close
it; most produced the same compiler outcome.

A one-worker 60-second bounded permuter run completed 707 mutations with
one compile error and no improvement from score 110. Calibration proved the
isolated source's non-call words and semantic relocations against the full
candidate, regenerated AST score zero, and the small oracle's final linked
text against the current retail ELF. In-module call fields were normalized
to their actual callee names only for that private oracle, never in a
production object. The search process group was stopped at its bound. No
candidate is installed or accepted.

Next: inspect temp allocation around the first RNG halfword result; this
search was flat, so another identical mutation run or record-width family
has no evidence behind it. Preserve RNG call order and the actual helper's
`u16` return. Private proof: `rewrite-cleanup-f67-particle-permuter` calibration
and result receipts; source family `rewrite-cleanup-f67-particle-fields8`.
