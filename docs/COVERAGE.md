# Generating the coverage reports

Run `python3 ci/update_coverage.py` from the repository root to regenerate
`COVERAGE.md` and `docs/coverage.svg`. Add `--check` to verify both outputs without
writing them. The hourly `refresh-coverage.yml` workflow regenerates these files
and `UNDOCUMENTED.md` together on the existing refresh PR branch.

The graph uses the same 10,532-function US baseline as the coverage summary.
Each bar counts functions in an original MIPS instruction range, split into C
implementations and remaining `GLOBAL_ASM` owners. These are static instruction
counts, not runtime execution counts. The Markdown table carries the same values
as the SVG. Original sizes remain fixed as functions move to C; original addresses
allow remaining owners to be recognized after a rename. A missing size goes in
Unknown. An owner outside the baseline fails generation so it cannot silently
change the graph's denominator.

`--revision` and `--staged` select both source pragmas and the symbol names used to
resolve renames. The generator reads its instruction baseline from the manifest
beside the script. It needs only Python's standard library, a Git checkout, and
the tracked manifest; CI does not need a ROM, disassembler, or private checkout.
`--output` relocates the Markdown output and defaults the SVG to
`docs/coverage.svg` beside that output. `--graph-output` overrides the SVG path.

## Instruction baseline provenance

`ci/coverage_functions.json` retains one row per original owner:
`[source_path, original_function_name, instruction_count_or_null, original_vram]`.
The source snapshot is `f477acf0cf4bc311959d832278ca6950a2f910b7`, whose
`disasm/src` tree has exactly 10,532 US owners. All of those owners have recovered
instruction counts.

The counts were generated from that snapshot's `disasm` layout using the US ROM
with SHA-1 `d8343e69a7dc63b869cf6361d87cde64444281d3`, splat 0.25.0, and
spimdisasm 1.42.4. Concatenate `yamls/us/header.yaml` and `yamls/us/rom.yaml` into
`pokestadiumgs-us.yaml` in an isolated copy of the baseline `disasm` directory.
Configure the local ROM path, then run:

```sh
python3 -m splat split pokestadiumgs-us.yaml --modes code --disassemble-all
```

Import the resulting sizes in the current checkout with:

```sh
python3 ci/import_coverage_sizes.py --asm-root /path/to/baseline/disasm/asm/us/nonmatchings
```

The importer counts emitted instruction-comment lines, including delay-slot
instructions and NOPs emitted within a function. It excludes labels, directives,
and migrated rodata. It never estimates sizes from gaps between symbol addresses.
Only counts and identities are retained; ROM bytes and generated assembly are
not part of the report or its hourly workflow.

Run the generator tests with:

```sh
python3 -m unittest discover -s ci -p test_update_coverage.py
python3 -m unittest discover -s tools -p test_coverage_owners.py
```
