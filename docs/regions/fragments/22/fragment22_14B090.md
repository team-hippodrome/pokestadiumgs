# Region notes -- src/fragments/22/fragment22_14B090.c

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

Per-file spellings, skip lists, and unsolved shapes for this source file. Delivered to agents by `tools/file_brief.py`; extend it with `tools/region_notes.py append`.

## 2026-09-15

func_82701278: time cap at 0.9444 (raw 0.6944) after 2546s, mismatch operand_or_scheduling_drift; tried families: state_field_access; tie-pool no


## 2026-10-11

func_82702E78: plateau at 0.0 (raw None), mismatch unknown; tried families: (none); tie-pool no

## 2026-10-11

func_82702CD8: matched (call_sequence:struct_copy:exact_frame_with_two_reserved_words), 3 iterations, agent codex

## 2026-10-11

func_8270160C: time cap at 0.9875 (raw 0.9875) after 2400s, mismatch instruction_drift; tried families: call_sequence; tie-pool yes

## 2026-10-25: func_827010F0 and its initialized parameters

The 152-byte leaf increments the row's signed-halfword counter and updates
`position.x` toward `layout_position.x`. Below the existing duration value 10,
the integer expression is `(-480 * counter) / 10 + layout_position.x + 480`.
At the limit it sets row state 2 and copies the layout x coordinate. The
existing `Fragment22RowEntry` view supplies the actual fields. Compiled
`func_82702658` passes one row pointer when that row is in state 1 and consumes
no result. Counter narrowing and arithmetic grouping remain unchanged.

The initialized cells `D_827032B0` and `D_827032B4` are referenced only by
this owner in the inspected assembly. Function-local statics preserve their
ownership and reproduce the retail load scheduling. An extern-scalar recipe
differed in three setup words; explicit duration snapshots instead reversed
the counter/duration registers. Their failed sources and checksums are retained
privately. No ordinary scalar or declaration-order retry is needed.

The C data section owns exactly the existing 16-byte block at ROM
`0x14D570..0x14D580`, VRAM `0x827032B0..0x827032C0`, containing words
480, 10, 8 and 5. The first two words are the local statics. The genuine
neighbor parameters `D_827032B8` and `D_827032BC` remain externally visible C
definitions for the unchanged assembly owners `func_82701188` and
`func_82701278`. They fill their original cells within the section's 16-byte
alignment; there are no padding-only variables or additional data capacity.
Aliases retain the original names of the two local cells. The YAML split and
generated linker change place this section between the original data prefix
and tail; the rest of the data remains assembly-owned.

The data handoff first passed the complete ROM gate and byte comparison with
`func_827010F0` still assembly-backed on master
`aa6458d2fc2bb341a385408d72f206ba40122dd4`. The final C body was then installed.
After importing the newer audio change, fresh final validation on master
`6d02ce8f3180e4dc0867eca82f219897aea57862` plus this patch used:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/22/fragment22_14B090.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled build produced `build/pokestadiumgs-us.z64: OK`,
MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks passed. All 38 instruction words, the exact 16-byte parameter section,
and both assembly neighbors match; the leaf has no stack frame. No instruction
rewriting, forced registers, fake homes, new guards or CI changes are added.

## 2026-10-28 — `func_827030D0`: requeue (struct vs scalar globals)

Shape: when `D_827034EC & 1` and `D_827034E2 == 0`: set state to 1,
`row_counter` (0xEE) to 0 and `unk_00` (0xE0) to `arg0`. If `arg0 == 1`,
fetch row entry `func_82700E70(2, 2, D_82703514, 0x10)` and set `unk_04`
(0xE4) to 2. Then set the entry's +6 = 2, +0x14 = 0x34 and +0x12 = +0xE, and
call `func_8270188C(2, 2, entry->+0xE, entry->+0x10)`. Return 1 once
started, else 0. Retail emits a separate `lui` per store (E2, EE, E0, E4),
i.e. independent scalar globals. Writing them as `D_827034E0.<field>` (this
file declares `D_827034E0` as `Fragment22Menu`) CSEs the struct base (0.46).
Matching needs scalar externs for those addresses. They can't share the
`D_827034E0` name in this TU, so the next step is a scalar/alias split
agreed with the file's other users (`func_82702658` reads the struct
through `&D_827034E0`).


## 2026-11-03 — row completion: genuine for-loop and menu/row types

`func_82702220` now matches all 81 instructions / 324 retail bytes directly.
Removed seven `REWRITE_FUNCTION_WORD` directives and the unused three-word
`pad_frame` array. The real `Fragment22Menu` and 40-byte
`Fragment22RowEntry` types describe the existing offsets, and the stale
`void *` prototype now agrees with the typed menu definition. All callers
remain byte-identical; the machine calling convention is unchanged.

The routine derives menu alpha from row `(2,4)`, starts one of the three
option rows on each fourth nonnegative counter tick, then transitions to
state 10 once every existing option row is in state 2. Missing optional
rows preserve the original completion behavior. The lookup's final argument
16 is table capacity; its actual record stride is 40 bytes.

Removing padding and typing the data gives the correct frame and instruction
sequence but swaps the saved table/count registers `$s2` and `$s3`. Count
widths, declaration order, table pointer forms and cached/direct field use
do not close it. A literal loop bound gets the right registers but moves
the bound materialization from `+0x44` to `+0xC0`. The natural `for` loop
with its consumed three-option bound reproduces retail's allocation and
instruction order. Its increment follows the readiness test in C; the
compiler safely schedules it earlier because the local index is unobservable
on the early-break path. No dummy tests, unused locals, padding, false ABI
or register declarations are needed.

Final descriptive local names, known/candidate normal/+20 native controls,
and host syntax all pass. The entire module's text, allocated section bytes,
function/object symbols and relocation endpoints remain exact. A fresh normal
native full-ROM gate passes:

```sh
make -j1 COMPARE=1 RUN_CC_CHECK=1 PYTHON=<native-venv-python>
```

Full ROM MD5 is `1561c75d11cedf356a8ddb1a4a5f9d5d`; SHA-256 is
`8160abe7d4b9734317000c44e9f882efefe4cc6359eacded98be62f2811e40a9`.
All function extents, legacy addresses/sizes/types and previous C storage/types
are unchanged. No linker, coverage, compiler/tooling, helper function or
private artifact changes are included. The separate preview-state owner in
`fragment22_14A2E0.c` is not resolved by this acceptance.
