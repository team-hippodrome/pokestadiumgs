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
