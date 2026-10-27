# fragment44_207AF0 matching notes

## func_8AF19A1C

This signed-halfword query clears 255 bytes at `D_8AF36F30`, then reads
the signed-halfword stream selected by `D_8AF2BA90[arg0]`. Positive values
are narrowed into consecutive output bytes. A nonpositive value sets a
separator flag; another nonpositive value before the next positive value
ends the scan. The other stopping condition is 255 output bytes. The result
is the number of bytes written, and no extra terminator is written when
the buffer fills. No source bounds or index checks are added.

Compiled `func_8AF02208` opens the existing archive and populates the 14
stream pointers with `func_80004B4C`. Compiled callers `func_8AF1A0DC` and
`func_8AF1A1B8` select streams 6 and 12 and pass the returned count to
`func_8AF19E7C` and `func_8AF19FAC`. Those original consumers iterate the
output bytes as indices into their supplied halfword tables. These accesses
establish the stream, byte-index buffer and count roles; broader meanings
of the individual indices remain unresolved, so the owner and global names
are retained.
//@src/fragments/44/fragment44_1EE290.c
//@src/fragments/44/fragment44_207AF0.c

The input index, output count and separator flag use signed halfwords,
matching the original home-slot load and narrowing operations. The existing
same-file declaration now agrees with the owner's signed-halfword argument.
The byte-clear declarations use a generic destination pointer; all existing
callers keep their compiled instructions. All globals remain external and
their storage ownership is unchanged.

The first source candidate reproduces all 42 words, 168 instruction bytes,
and the 32-byte frame. Independent comparison covers the entire retail span
`0x207C8C..0x207D34`. No fakes, padding, instruction rewrites, data-layout
changes or generated-report changes are introduced.

Fresh validation on master
`90d00498cbc6500e07622ef42d75c2247176d2ba` plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/44/fragment44_207AF0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal host syntax check, forced source compilation and full US link
pass with `build/pokestadiumgs-us.z64: OK`, full-ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, exact retail byte comparison and clean
whitespace checks. The updated unchanged baseline passes its own complete
build and retail comparison before this source is reapplied.
