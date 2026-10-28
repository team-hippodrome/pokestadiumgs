# fragment13_EE0A0

## func_82400020 / func_82400438 (accepted 2026-10-28)

- `func_82400020`: three struct copies from data, passed to `func_80038894`
  for 8 records of 0x168 bytes (same shape as fragment47's `func_86002234`).
  Declaring `s32 i` *before* the three struct locals is required: declared
  after them, every struct slot sits 4 bytes higher.
- `func_82400438`: `*(u16 *)(arg0 + 0xCAC) += f() * D_82408BD8 / 48.0f;`.
  IDO's unsigned-preserving u16 promotion produces the unsigned
  int↔float fix-ups seen in the assembly.
- Requeue: `func_824001C0` (~170 instructions, a 7..0 loop over
  `D_82407370` 0x3C-stride records calling `func_82400154`) not yet attempted.
