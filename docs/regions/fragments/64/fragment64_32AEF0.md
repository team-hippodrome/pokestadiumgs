# fragments/64/fragment64_32AEF0.c

## 2026-10-29: `func_87F08C68` requeue

requeue (0.47). Tile layout for func_87F08D6C's local record:
- `step = 0x2000 / (bpp * width)` stored at +4;
- if height < step: step = height and count (+2) = 1;
- otherwise step is made even (signed `% 2`, retail emits the `bgez` fixup), then step -= 2, count = height / step, rounded up.

Retail loads layout[0] before size[0] (the product is written `size[0] * layout[0]`) and keeps step in $v1 as `(u16)` of the quotient. Our field-update spellings compute an unsigned `% 2` and differ in register flow. Next: an s32 local for the quotient with explicit u16 field stores.

## func_87F08A94 — vertex-strip allocation

This owner allocates two vertices for each of `count + 1` rows. Its first
argument supplies the unsigned-halfword count at offset 2, unsigned-halfword
row step at offset 4, and float offsets at 8 and 12. The second argument
supplies unsigned-halfword image width and height. Ordinary rows use
`step * row`; the final row uses the exact image height. Each pair passes
texture coordinates `(0, row)` and `(width, row)` to `func_87F088EC`, with
scale 1 and the supplied offsets. The allocation address returns through
the existing word-sized interface.

`func_87F08C68` produces the count and step from image dimensions and the
layout byte. Caller `func_87F08D6C` initializes the two float offsets,
invokes that producer, then passes this owner's allocation word to
`func_87F08280`. The existing C constructor `func_87F088EC` writes each
16-byte `Vtx`, including centered position, fixed-point texture coordinates,
normal and alpha. The new 16-byte view describes these actual fields;
unaccessed bytes retain unknown names. The forward declaration and caller
cast agree with the typed definition; the caller's 140 bytes and constructor's
424 bytes remain exact.
//@src/fragments/64/fragment64_32AEF0.c

All 93 instruction words (372 bytes) match with the original 96-byte frame.
The count-plus-one loop condition preserves the entry test, and declaring
the row index before the saved allocation pointer gives its original
stack home at 84. No unused local, new qualifier, extra storage, padding,
instruction rewrite or helper change is needed. The adjacent `func_87F08C68`
assembly and its earlier requeue above remain unchanged.

Fresh validation on master `01b27533a55bfc244f2264790df162643db22793`
plus this patch follows normal extraction and an exact unchanged baseline.
Earlier unsuccessful owners were restored and freshly compiled. The final
build forces this translation unit through the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_32AEF0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The complete US link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Full retail comparison and whitespace
checks pass. Independent original-assembly and raw-retail comparisons
verify all 372 bytes at ROM `0x32B704..0x32B878`.
