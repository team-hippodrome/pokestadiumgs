# `src/fragments/79/fragment79_3ADCA0.c`

## 2026-10-27 — `func_84143E64`: matched

Draws a name label: `color = func_80064474(kind, id)`, copy 12 bytes of the name, draw them with `func_800495F8(x, y, 1, buf)`, then a marker at `(x + 21, y + 10)` coloured 169/190 for `color` 1/2. `x`/`y` are `u16` (retail reloads them with `lhu` from their homes; the callers' extern is retyped to match); `kind` is read back as the low byte of its homed word (`lbu 0x4B(sp)`), spelled `*((u8 *)&arg2 + 3)` (`// FAKE`). `func_800495F8` is now declared varargs (`(s32, s32, s32, void *, ...)`) throughout the file, which leaves every existing caller byte-identical.

## 2026-10-27 — `func_84143F18`: requeue

requeue. Same head as `func_84143E64`; for kinds 29/32 it draws the name directly when it equals `func_800625E0(buf)` (`HAL_Strcmp`), otherwise `func_800495F8(x, y, 1, D_8418B1C4, name, colour)` (varargs). Declaring `color` before `u8 buf[12]` fixes the frame; the only remaining diff is the reloaded kind byte landing in `v0` instead of retail's `a1` (register tie, `kind` locals/`switch` do not move it). Permuter 240 s: 15 → 15.

## 2026-10-27 — `func_8413E410`: matched

Finds or allocates a name slot among the 48 0x7A-byte `unk_D_8419C0C0` records at `D_8419C0C0` (`u8 tag`, `char name[0x79]`): returns if a slot's tag equals `arg0`, otherwise claims the first empty slot (tag 0) and `sprintf(name, (char *)func_8004C874(7, arg0 - 1))` with no further arguments. A counted indexed loop `for (i = 0; i < 48; i++)` over `((unk_D_8419C0C0 *)&D_8419C0C0)[i]` is strength-reduced by IDO into retail's end pointer in `a0` (`D_8419D7A0`) and its 0x28 frame, which the `do`/`while` cursor form does not reach.

## 2026-10-28 — `func_8413F390`: requeue

requeue. Digit drawer `(s16 x, s16 y, s16 numDigits, u16 value)`:
- `do { *p++ = value % 10; value /= 10; numDigits--; } while (value > 0 || numDigits > 0);`
- then `for (p--; p >= digits; p--) { func_8413F32C(x, y, *p); x += 6; }`.

The callers' externs must take `s16` for `numDigits`: retail sign-extends it, and the retype is byte-identical. Best is 8 diff ops: IDO CSEs `&digits` into `$s2` for the whole function, while retail recomputes it for the loop test and the second loop. Buffer sizes, declaration orders, `while`/`do` forms and `&digits[0]` did not change it; a 300 s permuter found only temp-copy fakes.

## 2026-10-28: `func_84143D8C` drawing record dispatch

The owner skips records when byte 8 has any of masks 0x01, 0x02 or 0x10 set,
testing them in that order. Otherwise byte 0 selects a drawing helper: kinds 1, 9, 10, 11,
12, 13, 21 and 22 call `func_84142F0C`, `func_841430D0`, `func_8414327C`,
`func_84143508`, `func_841436EC`, `func_841438EC`, `func_84143BF4` and
`func_84143CF0`, respectively. Other kinds do nothing. Every helper receives
the same record pointer. Compiled helper definitions and original assembly
establish the single-pointer interfaces; no extra arguments are introduced.
The original caller `func_84145BA0` walks from `D_84186188` to `D_841869A8`
in 40-byte record steps and discards the result. Unknown names are retained.

Three early returns followed by the switch reproduce all 54 instruction words,
the 24-byte frame and the existing 22-entry jump table. No storage, padding,
instruction rewrite or layout change is needed.

Validation on master `d06e6d3ca33dd23364f02701d87f5c2996d51146` plus this
replacement: fresh US extraction and the complete initial assembly baseline
passed. When master advanced, the updated assembly baseline passed before
reapplying the same C. Final validation freshly force-compiled the source with
normal syntax checks through
`make -W src/fragments/79/fragment79_3ADCA0.c -j4 VERSION=us rom` and produced
`build/pokestadiumgs-us.z64: OK`. Full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail `cmp` and `git diff --check` pass.
Original-assembly/raw-ROM comparisons verify the 216 bytes at
`0x3B361C..0x3B36F4` and the jump table at `0x3FAB9C..0x3FABF4`.
