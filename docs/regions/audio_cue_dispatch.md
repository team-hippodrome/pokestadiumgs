# Audio cue dispatcher

`src/audio_cue_dispatch.c` contains `func_800226C0` at ROM `0x232C0`,
VRAM `0x800226C0`. Its 306-, 11-, and 21-entry jump tables occupy
ROM `0xA3270..0xA37B8`; the next eight bytes are zero alignment before
the following audio tables at `0xA37C0`.

The dispatcher has its own code and rodata input sections so compiler-emitted
switch tables receive normal section alignment independently of the following
audio routines. `src/229E0.c` holds the preceding routines and `src/23D10.c`
holds the following routines. This partition follows complete function and
table boundaries; it does not establish the original translation-unit boundaries.
The 24-entry recent-sound history remains at `0x800D1AD8`, owned by
`src/23D10.c` alongside its consumers.

The layout change, based on `18003058`, retains the assembly dispatcher.
`make -j1 COMPARE=1 RUN_CC_CHECK=1` with native IDO 7.1,
and a second native build using fresh Splat extraction, both reproduce
the 64 MiB US retail ROM (MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`).

## C follow-up: requeue

An m2c draft needs nine explicit early-return cases from the first jump table:
122, 197, 208, 209, 215, 250, 279, 283, and 285. Its default label also needs
legal control flow, and its assignment-only spill locals must be removed.
The sound-call block precedes the default command block in the retail text.
`func_80025294` uses the existing legacy declaration; a draft-inferred fourth
argument has no supporting caller/callee evidence.

Continue from the complete table mapping and compare real command lifetimes,
the two default-path switch guards, and the shared sound-call block. Keep the
assembly owner until both its compiler output and the entire ROM match.
