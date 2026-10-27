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

## 2026-10-27 — `func_82B02800`: requeue

requeue. Returns the 0x70-byte record of `D_82B126A8` (20 entries) whose two leading halfwords equal `(arg0, arg1)`, else NULL. A constant `i < 20` bound is unrolled by copt; `s32 count = 20` with `result = entry; break;` gives retail's rolled loop and tail-duplicated return (0.53 locally). The only remaining diff is `a2`/`a3` swapped between `entry` and `i`; declaration/statement orders, struct/`while`/`for`-increment forms and extra parameters do not move it. Permuter 180 s: no improvement (60).

## 2026-10-27 — `func_82B055A0`: requeue

requeue. Copies halfwords 4/6/8 of the record at `D_82B12450 + 0x254` into `+0x0E/+0x10/+0x12`, clears `+0x0C`, sets `D_82B12466`, `D_82B12464`, `D_82B12468`, `D_82B1246A` to 1, and calls `func_82B0556C`. Retail shares one `lui $at` for the (66, 64) pair and another for (68, 6A, in the call's delay slot), and loads each `1` into its own register (`t9`, `t0`, `t1`, `t2`), whereas IDO folds them into one register. Needs a `COALESCE_AT_LUI` symbol-list run per pair, plus a source shape that keeps four separate constants.
