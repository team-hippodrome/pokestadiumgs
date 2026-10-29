
## func_826002BC — accepted (2026-10-29)

Per-side marker pair fill. Winning spelling: local overlays for the
`D_82615324` state (`sides[4]` @0x74, `members[8]` @0x78, `pairs[2][2]` @0x80,
`selection` @0x88) and the context (`defaults[22][2]` @0x58, two 0x428-byte
descriptors @0xB0 = the RecordSelectionPartyDescriptor of fragment20_128B10.c).
Field arrays (not byte offsets) give retail's base-first `addu` order; the
fallback copy is the `owners[0] < 0` *else* branch. The last register tie closed
by computing `desc = &arg0->descs[i]` unconditionally before `if (a == -1)`.

## func_826003BC — register-tie (2026-10-29)

Fragment entry ('EYEC' pool state, 'mprc' phase loop over 0/1/2 → 3).
Best: normalized 0.9929 / raw 0.9787 (`entry:field-s32`, body in
scratch/c/3bc_best.json). Keys found: read the mode back through the global
(`D_82615324 = arg1; mode = *(u16 *)((u8 *)D_82615324 + 8);`) — that gives
retail's materialized `&D_82615324` in a0 with the load copy-propagated to `arg1`;
compare `(mode & 0xFF00)` (masking at assignment with a u16 adds an `andi 0xffff`).
Remaining diff: retail `lhu v1 / andi v1,v1` (in place), ours `lhu v0 / andi v1,v0`.
The trailing alignment nop is the 16-byte object alignment (the file ends here);
`C_FUNCTION_PADDING(4)` after the body had no effect.
Tried: mode s32/u32/u16, declaration orders, nested if, switch on mode, `&=` form.
Permuter 300 s: best 5, only with a `char` truncation temp (fake).
Next: a struct type for the arg1 state with a u16 field at 8 (field access instead
of the cast), or `switch (mode & 0xFF00)` with the u16 field read.
