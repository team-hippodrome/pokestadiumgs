# fragment64_32EC70 matching notes

## func_87F0C000

The 148-byte leaf recomputes the three floats at offsets 0, 4 and 8 of its
incoming object. It reads the origin at offsets 12, 16 and 20, the radius at
24, and unsigned angle fields at 28 and 30. Each angle is shifted right by
four to index the existing tables `D_80087E50` and `D_80088E50`. With `S` and
`C` denoting those respective tables, `i = angle28 >> 4`, `j = angle30 >> 4`,
and `r` the radius, the outputs are:

- `x = (C[i] * S[j]) * r + originX`
- `y = -S[i] * r + originY`
- `z = (C[i] * C[j]) * r + originZ`

The unknown structure view describes only the first 32 bytes accessed by
this owner. The initializer `func_87F0C094` fills those inputs, invokes this
helper, then initializes further words at offsets 32, 36 and 40. Its call now
passes the actual object pointer. The former two-float declaration happened
to preserve the incoming pointer in the argument register; the pointer call
reproduces all 104 existing initializer bytes.

The original `func_87F0C0FC` and `func_87F0C3EC` also pass their object in
`a0` and consume no result. The compiled `func_86203D50` passes the object
at its parent pointer plus 112 after updating two origin components.
//@src/fragments/50/fragment50_266A60.c

The radius snapshot preserves the original float lifetime. Direct field-index
expressions reproduce the original two index carriers; separate signed-word
index locals retain extra carriers and differ in 12 of 37 words. That failed
source and the earlier 14-word operand-order mismatch are retained privately.
No prior owner-specific region note or private attempt was found. Unknown
names remain, and no forced registers, padding, instruction rewrites or
additional storage are introduced.

Validation on master `d733bceff5de88476097f4a3ec152fb0ed8d03e0` plus this
patch used the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_32EC70.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Fresh compilation and full US linking produced the exact acceptance line
`build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The retail byte comparison and whitespace
check passed. All 37 leaf instruction words and 26 initializer words match;
the leaf has no stack frame.

## func_87F0C358

This 148-byte leaf initializes the interpolation fields later consumed by
`func_87F0C3EC`. It copies the three origin floats at offsets 12, 16 and 20
to offsets 44, 48 and 52, snapshots the radius from offset 24 to offset 56,
and multiplies the signed angle halfwords at offsets 28 and 30 by the
existing float `D_87F11714`, storing the results at offsets 60 and 64.
It stores its six float arguments at offsets 68 through 88, sets the word
at offset 32 to 1, clears the word at offset 36, and stores its word argument
at offset 40. The update routine tests bit 0 of the offset-32 word and uses
the offset-36/40 words in its interpolation ratio.

Original `func_8620392C` passes its object at parent offset 112, a word count,
and six float arguments; `func_87E146DC` uses the same interface. Neither
consumes a return value. The unknown structure view and three-float aggregate
copy retain the original integer-word copy operations and allocate no storage.
The earlier 32-byte view and matched `func_87F0C000`/`func_87F0C094` remain
unchanged. The address-based names preserve the unresolved broader state roles.
//@src/fragments/50/fragment50_266A60.c
//@src/fragments/63/fragment63_317060.c

The first typed-aggregate recipe read the factor directly for both products;
it emitted 156 bytes and two factor loads. A single local factor snapshot
recovers the original one-load lifetime across the destination stores and
reproduces all 37 instruction words with no frame. The original factor cell
remains externally owned. No new qualifiers, padding, forced registers, FAKE
constructs, data-layout changes, or instruction rewriting are introduced.

Fresh validation on master `703110f89dab2e1366fe5e2f6566bc136726112a`
plus this patch uses the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_32EC70.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Full US linking produces `build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent comparison covers all 148 owner bytes at ROM
`0x32EFC8..0x32F05C`; the complete ROM also preserves previously matched C.
