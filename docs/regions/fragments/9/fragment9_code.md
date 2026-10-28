# Fragment 9 state initialization

## `func_8FB00170`

The 80-byte owner in `src/fragments/9/fragment9_code.c` initializes the
first four halfwords of its destination to 230, 150, 300, and 210. It copies
the unsigned halfword at offset `0x0C` of the descriptor referenced by
`arg1 + 0x44` into destination offset `0x20`, then clears destination
halfwords `0x08` and `0x0A`.

It returns `func_8FB000D0(arg0, arg1)`. That helper chooses between two
12-byte copy sources based on the descriptor's first halfword, writes the
selected bytes at destination offset `0x0E`, and returns one; unsupported
descriptor values return zero. `func_8FB02608` passes its parent object
and the destination at parent offset `0x158C`, then propagates the result.
These original instructions establish two pointer arguments and a signed
word return interface for the initializer.

The implementation retains address-based names and the surrounding source's
byte-offset access style. These descriptions follow from inspected retail
assembly and existing caller code; no runtime observations are claimed.

## Validation

Tested for `VERSION=us` against master
`6b6a1b50dd7fb9bb9285a19263f9dc461513ea27` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/9/fragment9_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced source recompilation and linked
the complete ROM. It reported `build/pokestadiumgs-us.z64: OK`, with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The byte comparison and whitespace
check passed. All 80 instruction bytes and the 24-byte frame agree with
retail without padding, forced registers, or instruction rewriting.

## `func_8FB001C0`: copy an edited name

This 252-byte owner reads the first unsigned halfword of the descriptor
at `arg1 + 68`. For value 34, it copies 12 bytes from `arg0 + 14` into
the pointed record at `arg1 + 72`, offset 52. An empty source instead
uses `func_800647C8` with that record's first byte and copies the returned
string. For value 6, a nonempty source is copied into the selected
544-byte row at context offset 76, using the signed word at offset 56.
An empty source copies text lookup `(42, 86)` to the pointed record's
offset 52. Both handled descriptor values return one; other values
return zero.

`func_8FB02878` passes the context and its edit state at offset 5516.
`func_8FB000D0` copies the corresponding 12-byte names into that edit
state. The existing `unk_func_8FB02108` view describes ten rows beginning
at offset 76; `func_8FB02108` fills them, and the inspected assembly of
`func_8FB021F8` visits those rows in 544-byte steps. Moving the existing
type declarations earlier lets this replacement reuse their `rows[].info`
member. The selected row's remaining contents keep their existing names.
//@src/fragments/9/fragment9_code.c

The inspected implementations establish `_bcopy`'s source/destination/count
interface, `HAL_Strcpy`'s two string pointers, `func_800647C8`'s unsigned-byte
input and pointer-valued signed-word result, and `func_8004C874`'s two signed
word inputs and pointer result.
//@lib/ultralib/src/libc/bcopy.s
//@src/C180.c
//@src/641E0.c
//@src/4CC20.c

Tested for `VERSION=us` on master
`8ff69e0d534fa6db2b8ba0ccf0d31a1b6b26485f` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/9/fragment9_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled build forced source recompilation and linked the
complete ROM, reporting `build/pokestadiumgs-us.z64: OK`. MD5 was
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail byte comparison and whitespace
checks passed. All 63 instruction words at ROM `0xD0640..0xD073C` and the
24-byte frame match. No new padding, fake, data layout change or instruction
rewrite is used.
