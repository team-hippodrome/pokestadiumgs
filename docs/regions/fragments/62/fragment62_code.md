# Fragment 62

## 2026-10-15: func_86C000B4

Matched the independent 37-instruction owner with a word argument/result and a switch retaining the incoming value for unhandled cases. The original caller func_86C00148 passes its word state and consumes the returned word. Modes 0 and 2 query the existing byte-result StageContext_GetFadeMode; mode 1 calls the existing word-result func_86C002C4 and forwards duration 5 to StageFade_StartFromTransparent when that result is nonzero.

This owner was previously inspected without a trial because the fade wrapper's implicit forwarding needed an ABI audit. Current master has the explicit canonical s32 StageFade_StartFromTransparent(s32) definition, resolving that prerequisite. No invented arguments or changed helper definitions are needed. No padding or shared switch tails are involved.

The fleet history at afee707ab78d3f63f2f9deeadc7551ec0080eeed contains no exact owner attempt (including the solved archive), owner references, or fragment 62 region note; consequently no historical normalized/raw similarity score exists for this owner. All open PR scopes were documentation only before the trial.

The first candidate passes the full US build with default host syntax checks and COMPARE=1, followed by md5sum -c baseroms/us/checksum.md5: retail 1561c75d11cedf356a8ddb1a4a5f9d5d. The trial is based on master a6247e6263c537e663eb035e7fbac5cd6a064150 and preserves all 206 earlier process matches. No new semantic names, tokens, fakes, data, tooling, layout, or verification changes.

## 2026-10-27 — `func_86C00148` stage loop accepted (FAKE)

`func_86C00148` is now C: **33 words / 132 bytes**, frame 0x28, saved
`s0..s3`. It calls `func_800086A4(2)` and `StageFade_StartFromOpaque(5)`,
then runs the stage state machine until `func_86C000B4` returns 3. Each
iteration calls `func_80064D28` when the word at `D_86C00350 + 8` is -1,
advances the state, and draws one frame through `func_86C00070`. The file's
stale `M2C_UNK func_86C00148();` extern is retyped to `void (void)` in the
same change; the only caller, `func_86C001CC`, ignores the result.

Register evidence: the target keeps `&D_86C00350` in `s1`, -1 in `s2`, 3 in
`s3`, and loads the word into `t6`. Direct `if (*(s32 *)(D_86C00350 + 8) ==
-1)` (any operand order, array/struct casts, `while`/`for` loop forms)
gives `s1`/`s2` swapped (0.82). A named `s32` value local fixes the
`s`-register order but loads into `v0` (0.85). A 4-minute permuter run found
a 64-bit round trip of the loaded value; `(s64)` alone is sufficient and is
marked `// FAKE`. `s64` locals, `-1LL`, `0xFFFFFFFF` and `volatile` do not
match. Next: replace the fake if a typed `D_86C00350` struct or the real
field declaration reproduces the `t6` load.
