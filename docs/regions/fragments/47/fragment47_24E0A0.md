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
