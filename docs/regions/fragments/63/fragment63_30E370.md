# fragment63_30E370 matching notes

## func_87E0AE64

This 224-byte owner (56 instructions, 80-byte frame) walks the list whose
head is at context offset 40 and whose next pointers are at node offset 4.
For each node, it follows the pointer at offset 56 and takes that object's
state pointer at offset 12. It passes the node's three-float position at
offset 72 to `func_87F0B1A4`, keeping the first component, subtracting -120
from the second, and adding 200 to the third. The duration is 15 and the
mask is `0x2000`. It then passes the node's three-halfword rotation at
offset 66 to `func_87F0B2F4` with float arguments (180, 0, 0), duration 15
and mask zero. The existing names remain because the enclosing list and
state roles need more evidence.
//@src/fragments/63/fragment63_30E370.c

`func_87E0AC8C` supplies the node's position and rotation to the state
initializer `func_87F0AFD0`. `func_87E0B0EC` calls this owner when input
mask `0x8000` is set, then sets the enclosing state word to 2. The compiled
`func_87F0B1A4` consumes two pointers, three floats and two words and
configures a position transition. The original `func_87F0B2F4` reads the
second pointer as three signed halfwords and converts the incoming float
angles before configuring the rotation transition. These accesses establish
the local pointer and callee declarations; no storage or helper body changes
are needed.
//@src/fragments/64/fragment64_32DC40.c

The first recipe matches all instructions. The explicit subtraction of the
negative second-component offset preserves the original floating-point
operation. The loop hoists its four float constants and keeps the node and
state pointers across both calls without artificial locals or padding.

Fresh validation uses master `1710ef64558bbd6bc45c72b153371dc475a2f47d`
plus this patch. The unchanged current baseline passes the complete US ROM
gate and retail comparison. Final validation forces compilation through the
normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/63/fragment63_30E370.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The link prints `build/pokestadiumgs-us.z64: OK`; the full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail and whitespace checks pass.
Independent original-assembly and raw retail comparisons verify the span
`0x30E7D4..0x30E8B4`.
