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
