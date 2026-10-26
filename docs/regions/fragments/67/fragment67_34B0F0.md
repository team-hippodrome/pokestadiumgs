# fragment67_34B0F0 matching notes

## func_8290E81C

This owner advances the signed-halfword text index in `D_8291BC68` and copies
source bytes into the corresponding positions of the revealed buffer. A zero
at the current position returns 1 immediately. Otherwise it copies that byte;
newline (10) advances the index once and returns 0. For other bytes it advances
the index, returns 1 if the next source byte is zero, or calls
`func_800226C0(295)`, copies the next byte, advances again and returns 0.
Preserve the source and index reloads around the stores and the helper call.

Original initializer `func_8290E5F0` clears the index at offset 4 and both
255-byte buffers at offsets 8 and 263, then formats string entry `(48, 0)`
into the source buffer. Original renderer `func_8290F42C` passes the revealed
buffer (`D_8291BD6F`) to the text renderer. Original dispatcher
`func_8290E8D8` calls this owner without arguments and uses its word return
to advance its state. These producers and consumers establish the new record
view; its unknown header bytes remain address-based. The declaration refers
to existing storage and allocates none.
//@src/fragments/67/fragment67_34B0F0.c

The existing `func_800226C0` assembly dispatches a word-sized sound command to
the audio helpers. This owner consumes no return value. Its original single
call and argument remain. No caller, helper, storage, layout or neighboring C
changes are required; the new owner uses no fakes or instruction rewrites.
//@src/229E0.c

Fresh validation uses master `abf0c06a5ada4697012be3285f7ab1376eb41268`
plus this patch. The first candidate matches all 47 instruction words (188
bytes), including the original 24-byte frame. Final validation forces the
changed translation unit through the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/67/fragment67_34B0F0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 188 bytes at ROM `0x34B31C..0x34B3D8`.
