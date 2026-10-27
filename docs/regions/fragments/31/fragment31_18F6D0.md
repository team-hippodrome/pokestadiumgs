# fragment31_18F6D0 matching notes

## func_8821C770

This comparator derives one unsigned-byte value for each of its two incoming
objects. Bit 0 of the object's byte at offset 38 selects the value 253;
otherwise it uses the existing byte at offset 8. It returns the first value
minus the second, breaking equal values with `LabPCList_CompareByPointer`.
That existing helper returns 0 for equal pointers, -1 for ascending pointer
order and 1 for descending pointer order. The flag's broader meaning remains
unknown, so the original owner and field names remain.
//@src/fragments/31/fragment31_18F6D0.c

Original dispatcher `func_8821CCE8` selects this function as a callback and
passes it with the pointer array behind `D_88234750` and count `D_88234744`
to `func_88004B60`. That compiled sorter calls its comparator with the array's
stored pointers, establishing the two-object interface. The new owner uses
the existing object type and tie-breaking helper without changing either.
//@src/fragments/29/fragment29_16AA30.c

The pointer pair and derived-byte pair are real local arrays, each populated
and consumed by the two-iteration loop. Keep the unsigned-byte loop counter
and separate difference/result values. Declaring the two scalar result
carriers ahead of those arrays recovers the original array homes and 56-byte
frame. Earlier candidates had a 48-byte frame and shorter return path, or
six differing array offsets; they were rejected. The accepted source matches
all 44 words (176 bytes), including the common return sequence. No unused
locals, fakes, storage changes or instruction rewriting are required.

Fresh validation uses master `20b8adf1b7d02af627d362347b0e3c61b2bcbdc5`
plus this patch. Final validation forces the changed translation unit through
the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_18F6D0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 176 bytes at ROM `0x18F9F0..0x18FAA0`. Existing neighboring C, callers,
helpers, storage, layout and CI remain unchanged.

## func_8821C970

This sibling comparator derives two signed-word values: 100000 when bit 0
of the object's byte at offset 38 is set, otherwise the unsigned halfword
at offset 14. It returns the first value minus the second, using existing
`LabPCList_CompareByPointer` for ties. The flag's wider meaning and the
halfword's semantics remain unknown; existing names are preserved.
//@src/fragments/31/fragment31_18F6D0.c

Original `func_8821CCE8` also selects this owner as a callback for
`func_88004B60`. The sorter's calls pass stored object pointers, as with the
preceding comparator. The accepted byte comparator provides the same real
pointer-pair and value-pair loop structure. This owner uses signed-word
working values for its larger sentinel and halfword input. Both arrays are
populated and consumed; the unsigned-byte counter and separate scalar
difference/result values reproduce the original loop and common return.
//@src/fragments/29/fragment29_16AA30.c

The first candidate matches all 45 instruction words (180 bytes), including
the original 64-byte frame. Fresh validation uses master
`8c29b4904d6e8991e4251e26d9168d142a81fced` plus this patch and forces the
changed translation unit through the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_18F6D0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 180 bytes at ROM `0x18FBF0..0x18FCA4`. Earlier matched C remains unchanged.
No new fakes, unused locals, helper or caller edits, storage, layout,
instruction rewriting or CI changes are required.

## func_8821CA24

This comparator derives the same two byte values as `func_8821C770`: 253
when bit 0 of byte 38 is set, otherwise the object's byte at offset 8. It
passes each value to existing `func_80073450`, retains the first returned
byte across the second call, and subtracts the second result. Equal results
use `LabPCList_CompareByPointer` on the saved object pair. Preserve both
lookup calls and the unsigned-byte intermediate.
//@src/fragments/31/fragment31_18F6D0.c

The compiled lookup takes and returns an unsigned byte. For inputs 1 through
253 it reads `D_8009F97F[input]`; other inputs return zero. This establishes
the declaration and byte-result lifetime without assigning a new meaning to
the table or the unknown object flag.
//@src/74020.c

Original `func_8821CCE8` selects this owner as another callback for
`func_88004B60`, whose compiled calls pass the stored object pointers.
The real pointer and value arrays are populated by the two-iteration loop,
and the saved pointers remain live through the lookup calls for tie-breaking.
The existing type, sort interfaces, helper bodies and storage remain unchanged.
//@src/fragments/29/fragment29_16AA30.c

The first candidate matches all 46 instruction words (184 bytes) and the
original 56-byte frame. Fresh validation uses master
`1f25161aa9f2e2c51f938bcd377e3fb666b06753` plus this patch and forces the
changed translation unit through the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_18F6D0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 184 bytes at ROM `0x18FCA4..0x18FD5C`. Earlier matched C remains unchanged.
No new fakes, unused locals, layout, instruction rewriting or CI changes are
required.
