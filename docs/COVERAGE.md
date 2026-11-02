# Generating the coverage reports

Run `python3 ci/update_coverage.py` from a checkout with a current US split to
regenerate `COVERAGE.md` and `docs/coverage.svg`. Add `--check` to verify both
outputs without writing them. `--asm-root` selects an alternate generated
`asm/us/nonmatchings` directory. The source pragmas and generated assembly must
describe the same revision, including function names and file paths.

The graph retains eleven aggregate bucket totals from the existing Markdown
table, totaling the same 10,532 US functions as the coverage summary. The
generator counts instructions in each remaining `GLOBAL_ASM` function and
subtracts that bucket's open count from its retained total to obtain the C count.
No per-function inventory or instruction-size manifest is stored in Git.

These are static MIPS instruction counts, not runtime execution counts. Counts
include delay-slot instructions and NOPs emitted inside each function, and
exclude labels, directives, and migrated rodata. Missing assembly, empty
instruction bodies, or open counts exceeding a bucket's total fail generation
rather than produce an estimated graph. Changes to the function universe or
disassembler's function boundaries require reviewing the aggregate totals.

`--baseline` selects the trusted `COVERAGE.md` supplying bucket totals and
per-file totals; it defaults to the repository's report. `--revision` and
`--staged` select source pragmas; provide matching generated assembly when
using either option. `--output` relocates the Markdown output and defaults
the SVG to `docs/coverage.svg` beside that output. `--graph-output` overrides
the SVG path.

## Hourly refresh

`refresh-coverage.yml` generates reports on the existing credential-free
`gs-decomp-public` runner. `ci/generate-coverage.sh` runs the local baseline
Docker image without network access, mounts the source read-only, and splits
the image's US ROM using the checked-out source and split metadata. It does
not compile or link the game. Only `COVERAGE.md`, `docs/coverage.svg`, and
`UNDOCUMENTED.md` are uploaded as workflow artifacts.

A separate GitHub-hosted job checks out the exact source revision used by the
generator, downloads those three files, and opens or updates the existing
refresh PR using the GitHub App token. Publishing credentials are created only
in that hosted job. The scheduled refresh therefore uses the runner's existing
local ROM but publishes no ROM bytes or generated assembly.

To reproduce the container job on a machine with the baseline image:

```sh
bash ci/generate-coverage.sh "$PWD" /tmp/coverage-reports
```

## Aggregate baseline provenance

The initial bucket totals were recovered from snapshot
`f477acf0cf4bc311959d832278ca6950a2f910b7`, whose `disasm/src` tree has
10,532 US owners, using ROM SHA-1 `d8343e69a7dc63b869cf6361d87cde64444281d3`,
splat 0.25.0, and spimdisasm 1.42.4. All original owners had recovered sizes.
Only the eleven totals in `COVERAGE.md` are retained.

Run the generator tests with:

```sh
python3 -m unittest discover -s ci -p test_update_coverage.py
python3 -m unittest discover -s tools -p test_coverage_owners.py
```
