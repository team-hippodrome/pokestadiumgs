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


## 2026-10-27 — matching curve configuration

Starting source revision `6e7c01b373984780972e9019acbf2c04940c4ef9` (#1630).
`func_86009E54` passes canonical acceptance and the full US retail-ROM gate:
164 bytes, 41 instructions, and the original 48-byte frame. It computes the
coefficient/parameter ratio, chooses the sign from offset 0x48, and calls
`func_86009D7C` with the derived height, product, angle, and flags. Preserve
the single-precision square root followed by double-precision multiplication.

The existing `Fragment47PositionConfig` prefix supplies the coefficient,
radius, and vertical origin. Calculate the ratio directly from those fields
before assigning the outgoing product, then give the final height its own
local. IDO shares the repeated multiplication while retaining the original
register allocation and instruction order. Every local contributes to the
calculation or outgoing call. An automated exact candidate instead introduced
a redundant temporary copy; that source was rejected. Four complete-module
normal/blank-prefix controls verify removal of the runner-added declarations
and formatting against the accepted object's bytes, extents, and relocations.

### Updated unresolved owners

- `func_86009C98`: **requeue**. The genuine frontier is now 228 bytes with
  the correct frame and opcode sequence, 1.0 normalized / 0.9649 raw.
  Only the second branch's base load and square differ in F0/F12 selection.
  A full-ROM-exact generated spelling depends on a redundant copy and is
  not installed. Branch scopes, the typed prefix, explicit square/partial
  intermediates, and repeated named operand loads do not resolve the tie.
  Inspect the allocator's treatment of the second branch's base definition;
  keep the genuine two-word frontier as the starting point.
- `func_86007D98`: **requeue**. Two actual three-double vectors reproduce
  the original 112-byte frame and 180-byte extent. Caching `D_8600DE58`
  fixes the constant/value register exchange and reaches 1.0 normalized /
  0.9556 raw. Two final multiplication operand orders remain. Swapping the
  source operands and using three-field structs preserve that residual.
  Full-product temporaries enlarge the frame; do not add artificial padding.


## 2026-10-27 — matching motion-vector calculations

Starting revision `961986b40cb60415730910023a644f0fffc5af04` (#1651).
Both owners pass canonical acceptance and the full US retail-ROM gate:

- `func_86007D98`: 180 bytes / 45 instructions, original 112-byte frame.
  Construct two actual three-double vectors, calculate the scaled X/Z
  displacement, and pass both vectors to `func_86007E4C`.
- `func_86008BB4`: 376 bytes / 94 instructions, original 240-byte frame.
  Construct six actual three-double vectors, calculate the projection and
  response factor, apply the flag-dependent projection and positive cap,
  combine the normal/cross-vector components, and call `func_86007E4C`.
  All vector buffers and scalar locals participate in the calculation.

`Fragment47MotionPrefix` describes the observed object through offset 0xE0;
its extent is 232 bytes, and later fields remain outside this prefix. The
three-double slots are evidenced by the neighboring vector helper calls.
`func_86007B4C` writes the radius at 0xC8, and the selected calculations read
the scalar at 0xE0. Keep that scalar's role unknown. Bytes 0x90–0x97 remain
opaque; the prefix does not assign them an unsupported scalar type.

Typed access to offset 0xE0 closes the remaining multiplication operand and
floating-point register differences in both owners. The displacement owner
therefore needs no cached coefficient. In the response owner, naming the
actual projection and response factor also recovers the frame and all six
vector offsets; there are no dummy locals or padding buffers. Independent
complete-module normal/blank-prefix controls verify declaration cleanup,
the opaque eight-byte range, placement of the prefix above both owners,
and typed access to the displacement owner's input vector. The GS/Stadium 1
maps provide no supported names for either function.

### Compiler observation and remaining work

Ten complete-module stock/blank/off/on controls verify a logging-only native
compiler observation on the displacement draft and the accepted curve
configuration fixture. In the untyped draft, UGEN's final multiplication
already receives the field leaf on the left and the nested product on the
right. The observation does not identify the upstream pass that ordered
those operands. The typed-prefix acceptance resolves this owner; do not
resume the older operand-swap or scaled-input campaigns.

- `func_86009934`: **requeue**. Two real three-double buffers and scalar
  intermediates reproduce the full 348-byte opcode sequence. Reusing the
  ratio as the subsequent square-root value recovers the original 136-byte
  frame and both vector offsets: 1.0 normalized / 0.9310 raw. Six words
  remain: the first helper result spills at SP+56 rather than SP+48, and
  that value exchanges F12/F14 with `D_8600D968`. Declaration placement,
  block scopes, and extracting the second helper result do not close it.
  Inspect that result's spill lifetime before changing vector sizes.
- `func_86009C98`: **requeue**. The two-word F0/F12 residual documented
  above remains. Named return values and signed-square-root intermediates
  do not close it. Its generated redundant-copy exact form remains rejected.


## 2026-10-27 — literal coefficients and vector rescaling

Starting revision `6882f9f8c57ac3241de20f4e6b294a5b1092e4ea` (#1652).
`func_86009934` now passes canonical acceptance and the full US retail-ROM
gate: 348 bytes / 87 instructions, with the original 136-byte frame. Preserve
the two three-double buffers, the returned helper pointer, and reuse of the
ratio as the subsequent square-root value. The guard rejects values below
zero or at least one; it must retain the original NaN behavior. The square
root executes in single precision before promotion and vector rescaling.

The five-register residual came from spelling `D_8600D968` as an external
variable. Its retail pool value is exactly the double encoding of `1e-5`.
Using the literal reproduces the instructions, including the helper result's
register and its SP+48 spill. A logging-only native observation, calibrated
with ten complete-module controls, identifies the external-load coloring:
that draft gives the shared constant F12 and the helper result F14. The
literal closes this owner without extra copies or register constraints.

The literal requires the file's own read-only pool. `yamls/us/rom.yaml`
now assigns ROM 0x253F70–0x253F8F (VMA 0x8600D950–0x8600D96F) to this file's
`.rodata`, followed by the shared tail at 0x253F90. These 32 bytes contain
two `10000` doubles and two `1e-5` doubles. Both boundaries are 16-byte
aligned. Re-extraction generates the corresponding linker entry and migrates
the four constants to their owning functions.

`func_860098A8` already had matching C and now uses its `1e-5` literal too,
so its constant remains in this file after the split. Its 140-byte extent
and 96-byte frame are preserved. The layout control with original assembly
passed the full retail-ROM gate before canonical acceptance of both literal
bodies. Four complete-module normal/blank-prefix controls verify removal of
unused external data declarations and duplicate function declarations.
The earlier six-/five-word rescaling requeues are resolved by this change.

The sequential gate must use the source containing an earlier accepted
owner. During this migration, a batch snapshot that still referenced the
restored neighbor's assembly failed after extraction removed that assembly
file. A fresh canonical batch on the restored C context accepted the new
owner. Treat this failure as a source-context/tooling issue, not another
source-shape hypothesis.


## 2026-10-27 — matching curve-contact adjustment

Starting source #1655 (`77d68dce4f7aabc71721a8d5138bd08fff94de28`).
`func_860093AC` passes canonical acceptance and the full US retail-ROM gate:
524 bytes / 131 instructions, with the original 184-byte frame. The newly
owned constant pool supplies its `10000.0` literal at 0x8600D958.

Capture the object's radius before copying its position. The copied point,
difference vector, projected point, adjustment vector, and all five scalar
locals participate in the calculation. Preserve Y/X/Z projection order,
the two penetration guards, the projected-point predicates, and the squared
threshold guard before adjusting the object and calling `func_86007EB4`.
A typed configuration radius closes the initial operand/scheduling residual;
subsequent field-access cleanup preserves the complete object.

`Fragment47Point` now serves both this owner and the existing
`func_86009F28` point copy, and describes the motion prefix's first member.
`Fragment47CurvePrefix` combines the earlier 40-byte position view with the
observed flag at offset 0x48. `func_86009D7C` writes that flag and the
configuration's radius and center fields. Bytes 0x28–0x47 remain opaque;
the prefix does not establish the complete allocation size.

Eighteen complete-module normal/blank-prefix controls cover point-type
consolidation, curve-prefix consolidation, and typed field access, including
all eight combinations. Every combination preserves bytes, section extents,
and relocations. The selected source consolidates both types, uses direct
member access for the origin copy, and removes duplicate externs. The
GS/Stadium 1 maps provide no supported function rename.
