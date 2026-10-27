# fragment51_27AC10 matching notes

## func_86305B44

This no-argument owner traverses four 396-byte entries beginning at
`D_863075D8 + 320`. For each entry it loads the pointer at offset 32 and
calls existing `func_86305A04` only when that object's word at offset 64 is
nonzero. It passes the address of a local work record containing the loop
index, entry pointer and object pointer at offsets 0, 4 and 8. Preserve the
record reloads after the helper and the index-before-entry increment order.
//@src/fragments/51/fragment51_27AC10.c

The existing assembly helper uses this same record throughout its geometry
and list-processing calls. It reads the entry/object pointers at 4/8,
writes the list pointer at 12 and floats at 16/20, and passes addresses
within the record to `func_86304DF0` and `func_863057A0`. Its float store at
136 establishes the 140-byte record extent. The 128 bytes after the three
named fields are opaque helper working storage, rather than unused stack
padding. Their existing initialization and processing remain in the helper
chain (`func_86305448`, `func_86305694`, `func_86305840`).
//@src/fragments/51/fragment51_27AC10.c

Compiled `func_86302404` calls this owner without arguments during each of
three update iterations and ignores its result. The new declaration uses the
existing root pointer and allocates no global storage. Unknown fields and
function names remain address-based.
//@src/fragments/51/fragment51_275E40.c

The accepted do-while matches all 30 executable instruction words (120 bytes)
and the original 176-byte frame. The first for-loop candidate had only the
two loop-store positions reversed and was rejected. The original assembly
also includes one trailing alignment NOP after the return delay slot; that
four-byte alignment is preserved and excluded from the executable byte count.

Fresh validation uses master `28bd8b2298dc22a4ca5a8c380379ba4ac1ed053c`
plus this patch. Final validation forces the changed translation unit through
the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/51/fragment51_27AC10.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
the executable bytes at `0x27B964..0x27B9DC` and the following four alignment
bytes through `0x27B9E0`. Existing neighboring C, helper bodies, callers,
storage and layout remain unchanged; no new fakes or instruction rewriting.
