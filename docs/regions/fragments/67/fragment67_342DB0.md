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


## 2026-11-03 — particle initializer matched without rewrites

**Accepted: `func_829064D0`, 432 bytes, all 15 word rewrites removed.**
The random speed is converted to `s16` before adding 728, matching the
signed halfword destination at particle offset +16. The neighboring
`func_82906680` likewise uses a signed halfword random speed before adding
its base. `MathUtil_Random16` masks to 16 bits; this fragment divides by
65535 before scaling, so `func_829063EC(546)` produces 0 through 546.
Conversion to `s16` preserves every possible result. The existing `u16`
helper return and all random calls and field-write ordering remain intact.

This distinguishes narrowing the random input before arithmetic from the
previously rejected experiment that narrowed the completed sum. The explicit
input conversion gives the retail temporary-register sequence through the
remainder of the initializer. Giving that input a separate named `s16` local
was also checked and does not reproduce the same object; it was not installed.
No dummy operations, storage, interface or compiler changes are involved.

Four complete-module controls (known and cleaned source, each with normal
line numbers and 20 leading blank lines) preserve allocated bytes, layout,
function/object extents and semantic relocations. Host syntax and the native
`make -j1 COMPARE=1 RUN_CC_CHECK=1` gate pass with retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All 432 linked owner bytes, function and
object extents, legacy addresses and fragment boundaries are unchanged.
Coverage was not regenerated or edited.
