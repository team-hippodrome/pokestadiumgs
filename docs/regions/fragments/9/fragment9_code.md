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

## 2026-10-29: remove selection-pointer instruction rewriting

`Fragment9_UpdateSelectionPointers` (`func_8FB024BC`) now emits its retail
164-byte body without `REWRITE_FUNCTION_WORD`. The old directive swapped
the operands of the address addition at function offset 0x80. Eight normal
C address forms show that an indexed view of the actual 544-byte columns
emits the required operand order directly. `Fragment9SelectionColumn` is
a byte-array type for that existing stride; it allocates no storage. The
selected record remains at base + 92 + column * 544 + row * 88, with the
original column/row clamps and secondary table-pointer update unchanged.

The accepted cleanup uses the first exact indexed form, with a named type
and source identifiers added afterward. Both initial exact forms preserve
the complete module: section bytes/layout, function extents and relocation
topology all equal the original patched object. Unchanged/+20-leading-blank
controls and normal/+20-blank cleanup/naming controls pass. The original
address-keyed entry remains available as a linker alias. No replacement
word patch, forced register, artificial storage, compiler flag change or
new helper function is introduced. This cleans an existing C owner rather
than increasing the new-owner count.

## `func_8FB000D0`: load an editable name

This owner matches as C: 40 instructions, 160 bytes, with its original
24-byte frame. It reads the descriptor's first unsigned halfword through
context offset 68. Value 34 selects the pointed record at context offset
72, plus 52 bytes. Value 6 selects the signed row index at context offset
56 in the existing 544-byte rows beginning at offset 76. Both paths copy
12 bytes to destination offset 14, clear its signed halfword at offset 12,
and return one. Other descriptor values return zero without copying.

`func_8FB00170` prepares the destination geometry and propagates this
helper's result. `func_8FB001C0` writes the edited name back to the same
record/row locations, establishing the name-copy role. The existing
`unk_func_8FB02108` and row declarations move before this definition so it
can reuse `rows[].info`; their fields and all other C bodies are unchanged.
The existing `_bcopy` prototype also moves before its new first caller,
and the redundant old helper declaration is removed.
//@src/fragments/9/fragment9_code.c

The indexed row view closes the final address-addition operand mismatch
from the byte-pointer candidate. It introduces no allocation, fake,
padding, compiler flag, data-layout change, or instruction rewrite.

Fresh verification targets master
`7e2bc65068fe58bc4b16ca6dbcd668d1482eda44` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/9/fragment9_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled forced compilation and complete US ROM link
report `build/pokestadiumgs-us.z64: OK`. Retail byte comparison and
whitespace checks pass; both ROMs have MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. All 13424 module text bytes and 240
rodata bytes equal the assembly-backed baseline, including previous C.
The owner independently matches ROM `0xD0550..0xD05F0` (end exclusive).

## `func_8FB005E4`: key-grid input and name editing

This handler matches 247 instructions / 988 bytes at US ROM
`0xD0A64..0xD0E40`, with a 32-byte frame. Caller `func_8FB02878`
uses it for edit page 2 and consumes its result: zero keeps editing,
one accepts the page, and two cancels it. Repeat-button input moves over
the existing 15-column, nine-row character table; only an exact direction
mask enters the navigation switch. Confirmation selects the table word,
applies the existing held-button character adjustments, and passes it to
`func_8FB002BC`. Table word 94 accepts the page.

The initializer and copy-back helpers establish text at byte 14 and the
capacity halfword at byte 32. `NameEditTextView` describes those existing
bytes without allocating storage. The remaining header halfwords keep
unknown names. Cursor movement and deletion distinguish one- and two-byte
characters by the high bit. Deletion copies the remaining capacity bytes
forward from the old cursor, then installs the preceding character boundary.
//@src/fragments/9/fragment9_code.c

Controller offsets 12 and 6 are the repeat and held masks in
`ControllerState`. This file retains its existing word-valued view of the
controller pointer. The audio dispatcher consumes one word; this handler
passes event 1 for nonzero repeat input and event 2 for confirmation. Its
no-prototype declaration also preserves the file's existing legacy calls,
including calls carrying an unused second argument register.
//@include/controller.h
//@src/audio_cue_dispatch.c

The typed text-array access reproduces retail's base-first address addition.
Two code-generation choices are labeled `// FAKE`: unsigned promotion on
the one-step character adjustment retains the source register before
halfword narrowing, and the two independent Start-button cursor stores
share a source line to retain the original as1 schedule. No padding,
fixed registers, instruction rewriting, new data ownership or helper
behavior is introduced.

Fresh validation targets `VERSION=us`, master
`e03c10c491680572e82007e4f75028c4f9b55c74` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/9/fragment9_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled full build reports exactly
`build/pokestadiumgs-us.z64: OK`. Rebuilt and retail ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Byte comparison and whitespace checks
pass. All 13,424 module text bytes, 240 read-only bytes, 24 register-info
bytes, 36 defined function extents, and 480 semantic relocations equal
the original assembly baseline, including all previously matched C.
