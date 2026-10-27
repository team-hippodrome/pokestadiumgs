# fragment34_1C1BC0 matching notes

## func_88505718

This no-argument handler forwards `D_8852300C[1]` to `func_80057944` when
that signed byte is not -1, then stores -1 back. It sets the state word at
`D_885229A8` to 1 and clears the signed halfword at offset 4. Slot 0 is
passed to `func_88505038` with state 1. Slots 1 through 3 are passed with
state 2 when their signed halfword at offset 4 is not -1.

`func_80057944(u8)` clears the corresponding bit of `D_80128558`; the byte
argument preserves the original narrowing. Original `func_88505038` stores
its state argument into the slot's first word and initializes fields for
the selected state. Original `func_885045B0` also tests the offset-4
halfword against -1 before using that slot. These accesses support the
state and sentinel operations; the broader meaning of the slot ID remains
unresolved, so the owner and field names are retained.
//@src/56F90.c
//@src/fragments/34/fragment34_1C1BC0.c

Compiled `func_885057BC` invokes the handler when `D_8852300A` equals 1,
before `func_88504EE8`. Original `func_88506618` also invokes it during
initialization, with no arguments and no result use. The existing slot view
keeps its 404-byte stride and every previous field offset; only the opaque
prefix is split to expose the observed signed halfword at offset 4. All
globals remain external fixed-address symbols and no storage is allocated.

The ordinary three-iteration indexed loop reproduces all 41 words, 164
instruction bytes, and the 40-byte frame on its first attempt. Independent
comparison covers retail span `0x1C2D28..0x1C2DCC`. Existing helper bodies
and callers retain their instructions. No fakes, padding, instruction
rewrites or data-layout changes are introduced.

Fresh validation on master
`19ddeceb659413b1916e93a9dc63a68f4835d259` plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/34/fragment34_1C1BC0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and full US link
pass with `build/pokestadiumgs-us.z64: OK`, full-ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, exact retail byte comparison and clean
whitespace checks. The unchanged refreshed baseline passes its own complete
build and retail comparison before this source is tested.
