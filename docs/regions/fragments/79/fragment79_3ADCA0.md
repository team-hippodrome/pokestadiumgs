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

## 2026-10-29 — color selection matched

`func_84146DBC` selects RGB triples by record kind and calls `func_84146D98`,
which copies three bytes and sets alpha to 255. The lookup used for kinds 0,
1, 2, 9–15 and 28 is `func_8413D26C(state[1], state[2])`; its accepted
producer in `src/fragments/79/fragment79_393CA0.c` returns a byte from
`D_84195252[arg0 * 24 + arg1]`. Case 22 indexes `D_84186FD4` with the second
argument. The native batch `scratch/battle79-novel3456` has a sealed retail
gate for the direct switch spelling with that real `u8` return prototype:
`scratch/battle79-novel3456/gate-0/receipt.json`. Final transaction status and
commits are recorded in `scratch/agent-report.json`.

## 2026-10-29 — `func_84143F18` and `func_84144410`: genuine C matches

`func_84143F18` matches with `(u16 x, u16 y, u8 kind, u16 id, char *name)`.
Declare the byte color before the 12-byte buffer. For kinds 29 and 32, compare
`name` with `func_800625E0((s32)buf, kind)`, passing the callee's real second
argument. That input keeps the kind in `$a1` across the test and resolves the
historical register tie. The nested guard and ternary marker mapping match
220 bytes with a 64-byte frame using ordinary byte-parameter C.

`func_84144410` matches 260 bytes with a 72-byte frame. A signed counted loop
visits up to three slots from `func_8413FD04`, breaks immediately on 255,
indexes the pointer table at `&D_841951F8`, and advances a `u16` horizontal
offset by 67. Each selected record is 88 bytes; kind, ID and name are read at
24, 46 and 76. The separate transaction makes `D_84186D18` and `D_84186D1C`
visible before this definition and closes its earlier declaration-scope handoff.

Canonical batch `scratch/battle79-name-row` accepted the first candidate for
both owners. Unchanged/+20-blank whole-module controls and the explicit host
syntax check passed. The combined retail ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; sealed source/object/ELF/map/ROM and receipt
are at `scratch/battle79-name-row/gate-0/`. These two accepts resolve their
prior requeue entries; the border drawer and move-type drawer remain active.

## 2026-10-29 — `func_8413EDF8`: genuine C match

Matched the seven-rectangle border drawer (572 bytes, 96-byte frame). Declare
`GfxRect_DrawTextured` with its verified signature from `src/44E70.c`: eight
`s16` geometry/texture parameters and an `s32` cycle parameter. Use repeated
expressions for the top/bottom coordinates and inner width so IDO shares
those values. Compute the real left-edge height, `s16 left_height = arg3 - 2`,
before the first call; this orders the height and top-coordinate spill slots
correctly. Keep the right-edge coordinate as `s16` and the sum `arg0 + arg2`
as a word for the later right corner. Every temporary supplies rectangle
geometry; there are no filler locals, forced storage slots or rewrite pragmas.

Canonical batch `scratch/battle79-border-height` accepted the first candidate,
`border:left-height-first:s16:cast-False:first`, with `link_verified: true`.
The unchanged/+20-blank module controls, explicit host syntax check and full
retail ROM gate passed. The retail MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the sealed receipt is
`scratch/battle79-border-height/gate-0/receipt.json`. This closes the prior
border-drawer requeue entry.
