# Fragment 20 fixed-pool lookup

## `func_82606E90`

The 56-byte owner in `src/fragments/20/fragment20_12C460.c` scans 40
12-byte records in order. It returns the first record whose signed halfword
at offset zero is zero, or `NULL` when every record is occupied. The helper
does not modify the records.

The inspected retail caller, `func_82606EC8`, passes the pool at offset
`0x50` of its argument. At `0x826072C8` it marks a returned record occupied
by storing one at offset zero. The surrounding stores initialize the other
five halfwords. Its later loop walks the same 40 records at a 12-byte stride
and calls `_bzero` with size 12 when the record's counter reaches eight.
This establishes the record size and free-entry test. The enclosing object's
complete layout and the effect's identity remain unresolved, so the function,
record type, and fields retain address-based or offset-based names.

The C loop computes a record pointer from each array index, saves it as the
result when free, and breaks. That ordinary source shape preserves the
retail loop and return scheduling without padding or code-generation fakes.

## Validation

Tested against master `8677ca6bf0d1baef93abedf8d49197a171fd7573` for
`VERSION=us`. The changed translation unit was forced through the normal
Makefile, including its host syntax check, and the complete ROM was linked:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/20/fragment20_12C460.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The build reported `build/pokestadiumgs-us.z64: OK`, with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the byte comparison and whitespace
check passed. The compiled owner occupies 56 instruction bytes. Behavior
claims above come from inspected code and assembly; no runtime observation
was required.

## `func_82604C98`

The 88-byte owner searches an array of six-byte records. It compares each
record's first two signed halfwords with the supplied word-sized keys and
returns the first matching index, or -1 when none match. A nonpositive
signed count also returns -1. The search does not modify the array.

`func_82604CF0` in this source calls the search, then reads the matching
record's signed halfword at offset 4 and adds 41; it returns 41 when the
search fails. `func_826065B0` passes the table at parent offset `0x3544`,
the signed halfword count at offset `0x14`, and two signed-halfword fields
from its new descriptor. These operations establish the six-byte record
and all three halfword positions. Their broader meanings remain unresolved,
so the record type, fields and owner retain unknown names.

The indexed loop computes a typed current-record pointer, saves the index
and breaks on a matching pair. This preserves the retail scalar loop,
comparison operand order and eight-byte frame. Existing matched C remains
unchanged. The evidence comes from inspected C and retail assembly without
runtime observations.

Tested for `VERSION=us` on master
`0100644fecb840962da14abb8029467474cad7df` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/20/fragment20_12C460.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced source recompilation and linked
the complete ROM. Exact acceptance was `build/pokestadiumgs-us.z64: OK`,
with MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. The retail byte comparison and
whitespace check passed. All 22 instruction words, totaling 88 bytes, match.
