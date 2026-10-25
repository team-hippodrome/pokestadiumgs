# fragment32_1B6E40 matching notes

## func_8830602C and func_8830609C

These adjacent no-argument queries inspect the four existing 24-byte records
beginning at `D_88308E38`. Each owner is 112 instruction bytes with no stack
frame. `func_8830602C` returns 1 when any record's byte at offset 4 is nonzero,
otherwise 0. `func_8830609C` returns 1 when every record's signed word at
offset 0 equals 1, otherwise 0.

Original `func_88305B84` initializes all four status words to 1 and their
offset-4 bytes to 3, then passes each record to the existing bounds initializer
`func_88305B30`. Compiled `func_88306404` writes status 2 and byte 1 to a
selected record. Compiled `func_8830639C` traverses all four records and uses
the offset-4 byte to decide whether to draw their bounds. This establishes
the common record stride and accessed field types. The new unknown structure
view leaves bytes 5 through 23 opaque and allocates no storage.

Compiled `func_8830099C` consumes the first query to gate `func_8830639C`.
Original `func_88300B48` and `func_88301C00` call the second query without
arguments and branch on its result. The meanings of the status values remain
unknown, so the address-based names are preserved.
//@src/fragments/32/fragment32_1B1330.c

A separate first-record guard followed by a three-record loop produced
80- and 84-byte bodies and failed the ROM comparison. The four-record typed
loops reproduce the retail unrolling naturally on the second recipe; there
is no manual unrolling, forced register, padding or instruction rewriting.
No prior owner-specific note or private failed attempt was found.

Fresh validation on master `d3d30d14a3fb2048a8bcb918204151cf7cfd7a8f` plus
this patch used the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/32/fragment32_1B6E40.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Full US linking produced `build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks passed. All 28 words in each owner match, 224 instruction bytes total.
Previously matched C and data layout remain unchanged.
