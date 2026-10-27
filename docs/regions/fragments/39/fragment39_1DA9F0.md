# fragment39_1DA9F0 matching notes

## func_88A01018

This read-only query uses the existing pointer `D_88A01C64`. It starts at
the byte index stored at offset 7 and examines at most the byte count at
offset 3. Two-byte rows begin at offset 9. The index advances while the
unsigned-byte argument is at least the first byte of the current row;
the first greater row byte ends the scan. A zero count returns the starting
index. The local index retains the original signed-halfword narrowing and
the result is returned as a word. No bounds checks are added.

Compiled `func_88A00710(0, index)` returns `table + 9 + index * 2`.
Compiled `func_8820C8A0` uses the same count, starting index and two-byte
rows, comparing each row's first byte and reading its second byte.
Compiled caller `func_8820CAE4` passes a byte and uses this query's result
as the upper selection bound, with the lower bound four less. Original
`func_88A017B4` also passes a byte and consumes the result as a signed
halfword. These accesses establish the row layout and index role; the
address-based owner and global names are retained.
//@src/fragments/39/fragment39_1DA9F0.c
//@src/fragments/31/fragment31_17F280.c

The two-byte row view preserves the original base-plus-scaled-index operand
order. The flat byte view differs in that single `addu`; commuting the flat
pointer expression leaves it unchanged. All 23 words, 92 instruction bytes,
and the absence of a stack frame match with the row view. Independent
comparison covers retail span `0x1DB2F8..0x1DB354`. The existing fragment 39
data continues to own the pointer, and all pointed-to storage is unchanged.
No new globals, helper bodies, caller edits, fakes, padding or instruction
rewrites are introduced.

Fresh validation on master
`d87cef80abb923be934d64bca92c1c720c1db36d` plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/39/fragment39_1DA9F0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and complete US link
pass with `build/pokestadiumgs-us.z64: OK` and full-ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Refreshed extraction and the initial unchanged baseline pass;
after separate upstream changes, the updated unchanged baseline passes its
own complete build and retail comparison before this source is reapplied.
