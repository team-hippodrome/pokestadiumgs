# Fragment 47 vector quotient calculation

## `func_860095DC`

The 152-byte owner reads three doubles from each of three input vectors
and writes three components through `func_87C00120`. For each cyclic index
triple `(i, j, k)` = `(0, 1, 2)`, `(1, 2, 0)`, `(2, 0, 1)`, it computes:

```c
(arg2[i] + (arg3[j] - arg3[k]) * arg1[j] * arg1[k]) / arg3[i]
```

The C preserves the subtraction, left-associated multiplication pair,
addition and division. It returns the destination pointer supplied by
the existing constructor. The input vectors' broader roles remain
unresolved, so the owner and arguments retain unknown names.

Retail `func_86009674` in `src/fragments/47/fragment47_24E0A0.c` passes a
24-byte scratch destination, two scratch input vectors and the three-double
span at parent offset `0x60`. It forwards the returned pointer as the input
to `func_87C002A8`. The latter scales three doubles, while `func_87C00120`
stores three doubles at offsets 0, 8 and 16 and returns the destination.
Both helper definitions are in `src/fragments/48/fragment48_256020.c`.

The retail instruction span is byte-identical to `func_87C0288C`, including
the shared constructor call. That relationship supports the source shape;
this owner's replacement was independently rebuilt and verified. These
claims come from inspected C, assembly and retail bytes, without runtime
observations or a semantic rename.

## Validation

Tested for `VERSION=us` against master
`ff1afeb0dbd48ea9c10607203084e39d2d1ba0aa` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/47/fragment47_24E0A0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced source recompilation and linked
the complete US ROM. It reported `build/pokestadiumgs-us.z64: OK`, with
MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. The retail byte comparison and
whitespace check passed. All 38 instruction words, totaling 152 bytes,
and the 40-byte frame match. Existing matched C remains unchanged.

## 2026-10-26 — shape scaling and curve sampling

Starting revision `27ab9930c95bfb59687e651f07ab76d65d877303`. Two owners pass
canonical acceptance and syntax-enabled full US retail-ROM comparison:

- `func_86007B4C` (152 bytes, 40-byte frame) saves the incoming radius at
  object offset `0xC8`, updates `0xD0/0xD8` from the existing coefficient
  table, and passes three equal components to `func_87C00120` at `0x60`.
  Cache the property at `0xE0`, rather than its divided intermediate, to
  recover the original floating-point instruction order. Reading the saved
  radius in the `0xD8` product recovers its final multiplication operand order.
- `func_86007CB0` (232 bytes, 48-byte frame) writes six doubles. The first
  and third components use the configuration value at offset 8, the scale,
  and single-precision sine/cosine of the angle. The second comes from
  `func_86009C98`; the remaining components use the existing table and
  trigonometric values. Multiplication order must be considered separately
  for the leading and trailing products: composing the independently useful
  orders closes the function.

Neither owner has an evidence-backed name in the current GS/Stadium 1 name
maps, so address names remain. No new helper or instruction-rewrite pragma
is required. Duplicate extern declarations were removed. Complete-module
normal/blank-prefix controls preserve all section bytes, symbol extents and
relocations after declaration cleanup and formatting. The final normal build
also forces this source to recompile and reproduces retail MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`.

### Unresolved owners

- `func_8600853C` / `func_860086A4`: **requeue**. Four variants each recover
  the vector-update flow with three real 24-byte double vectors. Their
  frames are 160 bytes rather than the oracle's 328, and extents are
  368/388 versus 360/380. Best normalized scores are 0.9457/0.9588;
  corresponding raw scores are 0.4348/0.5773. Declaration order and bound
  operand order do not resolve this. Inventory the original stack objects
  and interface before further variants; do not invent unused buffers to
  fill the gap. The existing `func_86008038` interface splits one double
  into two words, which the draft forwards through its actual word view.
- `func_86009C98`: **requeue**. Preserve the single-precision `sqrtf` and
  sign multiplication before promotion to double. Initial typed drafts
  reach 0.8621 normalized / 0.5690 raw, with 232 rather than 228 bytes.
  Caching the source radius and splitting branch-local base/sign variables
  do not improve that frontier. Next inspect the double expression tree,
  branch-local loads, and the saved floating-point register; retain the
  actual `(void *, f64, f64)` interface.
- `func_86009E54`: **requeue**. The draft computes the configuration/parameter
  product and ratio, chooses the sign, and calls `func_86009D7C` with the
  square-root-derived value. Best score is 0.8780 normalized / 0.6098 raw,
  with the correct 164-byte extent. Declaration order, sign selection and
  final addition ordering have been tested. Next inspect multiplication
  operand order and the product's lifetime, keeping the float-to-double
  square-root boundary intact.

## 2026-10-26 — initialized height query

Starting revision `cfa29ddb25bdfa4e2817ab991fea133c9b7469a1` (#1623).
`func_8600A0C8` was already C but contained a division using an uninitialized
local, an empty `if (1)` guard, and a comma-zero condition. Removing the
uninitialized division alone preserves the 124-byte extent but changes four
instruction words: the base and ratio exchange floating-point registers.
Removing the empty guard and comma-zero expression does not affect the object.

The fully initialized replacement calculates the ratio directly from the two
configuration fields before caching the base used in the final product. That
order recovers base F12 and ratio F2 with ordinary C. It preserves the flag's
sign selection, single-precision square root, and promotion back to double.
No uninitialized reads, empty guards, or artificial unused operations remain
in this function.

Four complete-module controls (before/after, each normal and blank-prefixed)
prove identical section bytes, symbol extents and relocations. Forced native
source recompilation with host syntax checking passes the full US retail-ROM
comparison, MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. This cleans an existing C
owner; it does not replace another assembly owner or change coverage.

## 2026-10-26 — matching position evaluation

Starting revision `6a4ef16ec124fb72ffd397c9b65069acaa0e4575` (#1627).
`func_86009A90` passes canonical acceptance and the full US retail-ROM gate:
336 bytes, 84 instructions, and the original 48-byte frame. Preserve the
three float trigonometric calls, double products, and the unsigned-angle
conversion used to index `D_80088E50`. The middle coordinate uses that
existing float table, not another trigonometric call.

`Fragment47PositionConfig` describes only the observed 40-byte prefix:
scale/radius at 0, the existing coefficient slot at 8, and coordinate origins
at 16/24/32. It does not claim a complete allocation size or invent a tail.
The neighboring constructor and calculations already access these offsets.
The current GS/Stadium 1 maps provide no evidence-backed function name.

Coordinate addition and multiplication operand orders matter independently.
A typed prefix closes the function; an independently calibrated source search
also finds a matching expression-only spelling by commuting both operations
in the middle coordinate. The selected typed form keeps the data layout
readable. Four complete-module controls (normal/blank-prefix, before/after)
prove that removing unused draft types and duplicate externs, naming the
prefix, and formatting preserve all section bytes, extents and relocations.

### Standalone search calibration

The SDK guards `#pragma intrinsic(sqrtf)` in `PR/gu.h` with `__sgi`.
The native compiler defines it; a generic host preprocessor may not. A
height-owner import without this context emits an external `sqrtf` call and
an 80-byte frame instead of the canonical inline `sqrt.s` and 16-byte frame.
Do not search that imported function. Native IDO `-E`, using the captured
compile flags, preserves the actual header conditions and intrinsic pragma.
It retains some full-line `//` comments; remove these with newline preservation
before parsing. Known-function and target controls pass for raw preprocessed
C, actual parser round-trip C, and blank-prefixed copies. Graphics macro line
groups must still survive parser formatting, as in the earlier renderer work.

### Updated requeues

- `func_86009C98`: **requeue**. A real query-X snapshot fixes the initial
  parameter/displacement register choice; early X-square evaluation plus the
  second branch's sign expression reaches 0.9310 normalized / 0.8103 raw.
  The draft remains 232 bytes versus 228. Its first difference is now the
  branch distance at offset 140, rather than the input register pair.
  Preserve that improvement; inspect the remaining branch/square-root
  schedule before adding more allocation variants. Fifteen complete-module
  controls verify logging-only allocator/frame observations. A calibrated
  180-second search on the earlier frontier improves stock score 650 to 620
  without a hit; do not treat that as a search of the new snapshot frontier.
- `func_8600B328`: **requeue**. The GBI commands match: sync, translucent
  surface render mode, white environment alpha 155, white primitive color,
  environment-color/texture-alpha combiner, and image at (129,29).
  Best draft is 0.9753 normalized / 0.9259 raw, 324 versus 320 bytes.
  The phase update materializes a shared address in V1, where the oracle
  uses separate load/store addresses. Intermediate-value spellings and a
  word-flag interface do not close it. No volatile barrier or instruction
  rewrite is justified.
- `func_8600B100`: **requeue**. Preserve both width queries and the signed
  modulo-32 phase. The triangular phase drives an expanded width around
  X=138, with environment alpha 200. Initial drafts reach 0.9565 normalized /
  0.7029 raw at 552 bytes but an 80-byte rather than 72-byte frame. Explicit
  dimension lifetimes recover the frame in some variants but regress the
  instruction order (best 0.9493 / 0.7174). Continue from those separate
  frontiers; do not force the frame with padding.
