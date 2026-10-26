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
