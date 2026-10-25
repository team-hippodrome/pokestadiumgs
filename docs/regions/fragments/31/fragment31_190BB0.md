# fragment31_190BB0 matching notes

## func_8821E0BC

This no-argument, void owner is 128 instruction bytes with a 24-byte stack
frame. It reads the parent address carried by `D_882347F0`, follows the list
pointer at offset 12 and the selection pointer at offset 16, and indexes the
list's pointer array with the selection's signed halfword at offset 8. The
selected pointer is stored in `D_88234620`.

When the parent's word at offset 0 is zero, the owner clears the child word
at offset 44 through the parent's offset-8 pointer, writes 2 to the parent's
offset-4 word, then writes 2 to its byte at offset 1184. The last two stores
reload the parent address from the global. Otherwise it calls the existing
no-argument handler `func_8821DE58`, which consumes `D_88234620` in its tests
and dispatches further state transitions.

Compiled callers `func_8821DE04` and `func_8821E8EC` use the same parent mode
word, child pointer, and child offset-44 word. Both call this owner without
arguments. Four unknown structure prefixes describe only the accessed fields;
they allocate no storage. The existing global word carrier and all previously
matched C remain unchanged. The broader meanings of the state values and
record fields remain unresolved, so address-based names are retained.
//@src/fragments/31/fragment31_190BB0.c

The first typed-prefix candidate reproduces all 32 instruction words. Fresh
validation on master `e1348dcadc077c351b8f3191118ad83c25c010c5` plus this
patch uses the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_190BB0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Full US linking produces `build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. The owner occupies ROM `0x19133C..0x1913BC`. No new data,
qualifiers, padding, forced registers, instruction rewriting, or layout
changes are introduced.
