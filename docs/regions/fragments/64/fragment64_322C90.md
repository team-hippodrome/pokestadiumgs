# fragment64_322C90 matching notes

## func_87F00030 — accepted C, session 63

The original no-argument initializer is called without outgoing argument setup by `func_86A004B4` and other original assembly callers. The existing global pointer type is retained; its initial fields are word views. Initialization writes 20, five times that stored value, and two zeros, preserving the original reloads rather than folding those reads into constants.

The allocation chain uses the actual no-argument available-size query, two-word allocator, pointer-based layout processor and allocation finalizer. The canonical resource loader has a narrow unsigned-halfword formal, the lookup returns a word handle, and the compiled `func_87F08E3C` takes a pointer and a word. The existing four-argument `func_87F0252C` definition confirms both record pointers and the count; the container constructor receives its real null first pointer and existing destination. No invented formal, ignored incoming argument or false helper return is used.

The first candidate preserves all 66 original executable words and the 40-byte frame and matches the complete retail US ROM with default host syntax checks enabled. No FAKE construct, padding directive or companion edit is introduced. Existing C siblings and previously accepted owners are retained.

Fleet has no exact owner attempt or regional catalog record for this source. References in failed `func_86405F28` and `func_86107A20` drafts concern their callers and are not attempts of this owner; their inconsistent helper declarations do not override actual compiled definitions. All earlier raw/normalized plateaus and shared-tail exclusions remain in force.

Validation: `make rom COMPARE=1 -j2` and explicit `md5sum -c baseroms/us/checksum.md5` pass with retail MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`. No CI, verification, tools, data, layout, linker or symbol-table changes are included.

## 2026-10-27 — `func_87F005F0` state reset accepted

`func_87F005F0(f32 arg0, f32 arg1)` is now C: **38 words / 152 bytes**,
frame 0x18. Through the state pointer `D_87F11768` it sets +4 to five times
+0, +8 to 2, +12 to 0, +16 to `+4 / +0` and the float +20 to 0.0f. It then
forwards both float arguments, still in `$f12`/`$f14`, to
`func_87F00534(arg0, arg1)`. The file's existing
`extern void func_87F005F0(f32, f32)` and callers establish the two
parameters; there is no `mov.s` because the registers are untouched. The
raw-offset spelling follows `func_87F00030`.


## func_87F006BC — countdown and object-list update

This no-argument owner clears state word 12. If word 8 has bit 0 set, it
writes status 3. Otherwise, bit 1 enables decrementing word 4, dividing it
by word 0 into word 16, and storing the fractional remainder at float
offset 20. On an exact multiple of word 0, quotient 0 writes status 3 and
sets word-8 bit 0 plus word-64 mask `0x10000000`; quotient 1 writes status 2;
other quotients write status 1. It always calls `func_87F0277C` on state
plus 32, then reloads and returns the status word. Repeated global reads and
all signed division checks remain intact.

`func_87F005F0` initializes the same countdown to five times word 0 and
sets word 8 to 2. `func_87F0085C` reads the quotient and fractional value
while drawing the overlay; `func_87F006AC` independently returns word 12.
These operations establish the shared state fields. The existing global
pointer declaration and unknown names remain unchanged.
//@src/fragments/64/fragment64_322C90.c

`func_87F0277C` follows the state's linked object list, calls each active
item's nonnull callback and increments its word counter. Compiled caller
`func_861095EC` and original caller `func_86A0167C` invoke the new owner
without arguments when `func_87F00930` is zero; both ignore its returned
word. The retail owner explicitly reloads that result after the list update.
//@src/fragments/64/fragment64_324FB0.c
//@src/fragments/49/fragment49_code.c
//@src/fragments/60/fragment60_code.c

The first C trial matches all 104 instruction words (416 bytes) and the
24-byte frame. All previous C text remains unchanged. No new fake, local
storage, padding, instruction rewrite, layout or helper change is introduced.

Fresh validation on master `69d73da168356f78ab231d797199a5a88738606c` plus
this patch follows normal extraction for the upstream fragment 79 split.
The unchanged full-ROM baseline passes before the replacement. Final
validation forces the changed source through the syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_322C90.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Complete retail comparison and whitespace
checks pass. Independent original-assembly and raw-retail comparisons verify
all 416 bytes at ROM `0x32332C..0x3234CC`.
