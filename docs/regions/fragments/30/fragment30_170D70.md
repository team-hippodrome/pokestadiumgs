# fragment30_170D70 matching notes

## func_88103D30

This 152-byte owner captures the address of the next pointer-list slot from
the argument's pointer at offset 16 and byte count at 21. It calls existing
`func_800226C0(333)`, sets the global state's word at offset 356 to 1, reloads
the global pointer, and stores the selected embedded record in the captured
slot. The selected record receives the argument pointer at offset 0 and the
argument's current count at offset 4. Finally the argument's count increments
and its word at offset 12 becomes 1.

Original `func_88103DC8` supplies actual owner pointers at both call sites:
one from `D_88A01C34` and one saved from the current selection. Both ignore a
return value. The incoming pointer and list slot remain live across the
helper call; the global pointer is first read after that call. The reloads
after the global flag and list writes preserve the original access sequence.
//@src/fragments/30/fragment30_170D70.c

The state contains two 96-byte records beginning at offset 164, selected by
the byte at offset 162. Original `func_88104730` allocates 368 bytes and
initializes that selector to 0 or 1. Original `func_881038A0` uses the same
96-byte stride and clears the 88-byte suffix beginning eight bytes into a
selected record. This independently supports the record extent and the
opaque suffix in the C view. The global's existing `void *` declaration and
storage ownership remain unchanged; the new types allocate no storage.
Broader meanings of the two state words and record contents remain unresolved,
so their unknown names and the address-based function name are preserved.

The first typed-record candidate matches all 38 instruction words and the
32-byte frame. No new fakes, qualifiers, padding, instruction rewrites, or
data-layout changes are required. Previously matched C is unchanged.

Fresh verification uses master `7209452ff6e3fbbe12a21ed5a2f8784e08a74f44`
plus this replacement. The imported baseline passed its own complete build.
`make -W src/fragments/30/fragment30_170D70.c -j4 VERSION=us rom` forces
normal syntax-enabled compilation and the complete US ROM link. The exact
acceptance line is `build/pokestadiumgs-us.z64: OK`, with ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and
`git diff --check` pass. Independent comparison of the complete owner span at
ROM `0x171200..0x171298` confirms all 152 original bytes.
