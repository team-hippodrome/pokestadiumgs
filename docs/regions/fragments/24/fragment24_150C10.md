# Region notes -- src/fragments/24/fragment24_150C10.c

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

func_82B0373C: plateau at 0.9479 (raw 0.7917), mismatch operand_or_scheduling_drift; tried families: call_sequence; tie-pool no


## 2026-09-17

func_82B025E0: time cap at 0.9848 (raw 0.803) after 2400s, mismatch operand_or_scheduling_drift; tried families: state_field_access; tie-pool yes

## 2026-09-17

func_82B041C8: matched (call_chain:macros:ternary-alpha-exact), 1 iterations, agent codex

## 2026-09-29

func_82B01F14: time cap at 0.0 (raw None) after 2400s, mismatch unknown; tried families: (none); tie-pool no

## 2026-09-29

func_82B025E0: time cap at 0.0 (raw None) after 2401s, mismatch unknown; tried families: (none); tie-pool no

## 2026-09-29

func_82B01BB8: matched (packed:interleaved:exact-copy-before-second-negations), 1 iterations, agent codex

## 2026-09-29

func_82B01CE0: matched (state:permuter:exact-pointer-handoff), 3 iterations, agent codex

## 2026-09-30

func_82B0341C: matched (call_sequence:array_layout:exact_match), 1 iterations, agent codex

## 2026-09-30

func_82B05F60: time cap at 0.925 (raw 0.7625) after 2420s, mismatch instruction_drift; tried families: call_sequence; tie-pool no

## 2026-10-27 — `func_82B029B8`: matched

Entry in state 2 → state 3, `+0x08 = 0`; for `arg1 >= 0` copy the `+0x10` pair to `+0x40` and `D_82B085DC` to `+0x44`, otherwise shift `+0x40` into `+0x44` and copy `+0x10` into `+0x40`. Written with the file's `Pair02198` struct copies.

## 2026-10-27 — `func_82B02800`: matched

Searches `D_82B126A8` (20 records of 0x70 bytes, typed `unk_D_82B126A8`) for the one whose `unk_00`/`unk_02` halfwords equal `(arg0, arg1)`. Declaring `count = 20`, `i`, `entry`, then `result = NULL` (in that order), walking `entry = D_82B126A8` with `i++, entry++` and nested `if`s that `break` with `result = entry` gives retail's rolled loop and its `a2`/`a3` assignment. Returns `void *` to agree with the file's existing prototypes.

## 2026-10-27 — `func_82B055A0`: requeue

requeue. Copies halfwords 4/6/8 of the record at `D_82B12450 + 0x254` into `+0x0E/+0x10/+0x12`, clears `+0x0C`, sets `D_82B12466`, `D_82B12464`, `D_82B12468`, `D_82B1246A` to 1, and calls `func_82B0556C`. Retail shares one `lui $at` for the (66, 64) pair and another for (68, 6A, in the call's delay slot), and loads each `1` into its own register (`t9`, `t0`, `t1`, `t2`), whereas IDO folds them into one register. Needs a `COALESCE_AT_LUI` symbol-list run per pair, plus a source shape that keeps four separate constants.

## 2026-10-28 — `func_82B03688` matched (option list text)

Fetch the panel position into `s16 coords[8]` with `func_82B0284C`, set the
text color/mode, then draw each entry of the `-1`-terminated `D_82B08630`
list with `func_8004C874(0x1B, id)` at `(x + 0x31, y + row + 9)`, rows 0x18
apart. Locals must be declared `i, y, coords[8]`: that order puts `coords`
at sp+0x30 in the 0x48 frame. An indexed loop with a separate `y` counter
matches; a pointer walk does not. The dispatcher `func_82B05494` used to
call it with no arguments and rely on `a0`; it now passes `arg0` (same
bytes), and the stale `(void)` extern is retyped.

## 2026-10-28 — `func_82B03F38`: requeue (loop-invariant address not hoisted)

Sibling of `func_82B03688` (same `func_82B0284C`/`func_800496A4` setup): four
rows, color (255,255,255,255) or (255,255,0,255) for the selected row
`i == D_82B1246C`, text `func_8004C874(0x1B, i + 0x22)` at
`(coords[0] + 9, coords[1] + y + 0xB)`, rows 0x1A apart. The dispatcher
`func_82B05494` must pass `arg0` as for 03688. With locals
`i, coords[8], y` everything lines up except that IDO 7.1 (and 5.3) hoist
`&D_82B1246C` into an extra saved register (`$s2`) outside the loop, while
retail re-forms it with `lui` + `lh %lo` every iteration and uses only
`$s0`–`$s2` (i, y, 4). `volatile`, s32, and an array form don't change it.
This is the same "uncached global address" behavior as `func_800258F4` and
`func_8220D630`.

## 2026-10-29: `func_82B07960` tooling-blocked

tooling-blocked (uncached globals, 0.70). B-button handler:
- plays sound 5 once when D_82B12456 is first set;
- on B: `switch (D_82B13008)`: case 0 resets D_82B12450 = 9, D_82B12456 = 0, D_82B1245A = -1; case 1 calls func_82B02A34 on each `(void **)(&D_82B12450 + 0xB18)[i]` for `i < *(s16 *)(&D_82B12450 + 0x250)`, then func_82B060A0(1);
- then plays sound 3.

The file's `extern void func_800226C0(void)` must become `()`. Retail re-forms every scalar global's address with `lui $at` while keeping a separate $s2 = &D_82B12450 for the loop. Our compile caches D_82B12456's address in an s-register. Same shape as func_87E07CD0.
