# fragment63_315A90 matching notes

## func_87E13558

This 252-byte owner (63 instructions, 40-byte frame) operates on the existing
state pointer `D_87E1EBD8` when flag 1 is set and flag 2 is clear. When its
node pointer at offset 12 is null, it copies the incoming node's three-float
vector at offset 72 to state offset 136, records the three incoming float
offsets at 16/20/24, and clears the word at 616. When the incoming node differs
from the stored node, it stores that pointer and configures `func_87F0B1A4`
with the state at 460, captured vector at 136, component-wise sums of the
saved offsets and current node vector, the incoming duration word, and mask
zero. Global pointer reloads follow the original stores.

`func_87E13380` supplies and initializes the state pointer. `func_87E13490`
sets flag 1 and clears flag 2; `func_87E134C0` clears flag 1 and the node
pointer. `func_87E133F0` increments the word at 616 while flag 4 is set.
`func_87E12120` supplies node offset 72 to the existing vector update helper.
The three-float aggregate view preserves the original three word copies;
unknown field roles retain address-based names and no storage is added.
//@src/fragments/63/fragment63_315A90.c

Compiled `func_87E0AA8C` calls this owner with its node and float offsets
(-34, 11, 0), duration 6. Compiled `func_87E0D8EC` supplies another node,
(-123, -2, 0), duration 1. These establish one pointer, three floats and one
word with no consumed result.
//@src/fragments/63/fragment63_30E370.c
//@src/fragments/63/fragment63_310270.c

`func_87F0B1A4` consumes two pointers, three floats and two words and returns
no value. The repeated declarations and the second-component loads in the
two existing calls (`func_87E12AA0` and `func_87E134E8`) now express that
actual float interface. The complete ROM comparison verifies their existing
machine code as well as the new owner. The helper captures a source vector,
stores its target and duration, and sets the transition flag.
//@src/fragments/64/fragment64_32DC40.c

The first recipe has the correct extent and frame, with six floating-point
load register differences. Writing each sum as saved offset plus node
component reproduces all original words. No padding, artificial locals,
instruction rewrites, layout changes or compiler changes are required.

Fresh validation uses master `865cf93a62a14642acd1288949c9820f6a389ca6`
plus this patch. The unchanged baseline passed normal extraction, a full US
link and retail byte comparison. Final validation forces compilation through
the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/63/fragment63_315A90.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The link prints `build/pokestadiumgs-us.z64: OK`; the full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail and whitespace checks pass.
Independent original-assembly and raw retail comparisons verify the 252-byte
span `0x316EC8..0x316FC4`.

## func_87E126D4

This 228-byte owner (57 instructions, 80-byte frame) walks eight 396-byte
nodes from the pointer at context offset 12. For each node whose state word
matches arg2, it starts a position transition using the corresponding
three-float vector from arg1, duration arg3 and flags arg4. State zero also
receives archive 359 entry `context->unk_00->unk_2188 - 5` at state offset 4.
Unknown context and state fields retain offset names.

`func_87E12568` allocates eight node records and eight 148-byte state
records, installing each state pointer at node offset 56. The callers
`func_87E127FC`, `func_87E12BE8` and their siblings supply the eight-vector
tables `D_87E1ABC4` and `D_87E1AB64`, state IDs, durations and masks.
The vector tables remain assembly-owned data.
//@src/fragments/63/fragment63_315A90.c

`func_87F0B1A4` consumes two pointers, three float components, a duration
and flags; it captures the current vector and starts the transition.
`func_8004C990` resolves an archive entry and returns its address as a word.
The declarations before the new call sites express those existing interfaces.
//@src/fragments/64/fragment64_32DC40.c
//@src/4CC20.c

The first recipe used a separate vector cursor and differed in four
parameter-save instructions. Advancing the incoming vector pointer directly
matches every instruction. No storage, layout, padding or compiler changes
are required.

Fresh validation uses master `64a8ad61cd35322f41313c105fd729502c1a9a67`
plus this patch. Normal US extraction and the full unchanged baseline passed
before the attempt; the subsequent upstream change only added an audio
region note. Final validation forces the changed source through the default
syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/63/fragment63_315A90.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The link prints `build/pokestadiumgs-us.z64: OK`; full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail and whitespace checks pass.
Independent original-assembly and raw retail comparisons verify all 57
words at `0x316044..0x316128`.
