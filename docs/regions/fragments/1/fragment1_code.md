# fragment1_code matching notes

## `func_83503548`: fade-state transition and record copy

The 168-byte owner (42 instructions, 24-byte frame) obtains the current
fade mode. When both that mode and `D_83503E80` equal one, it calls
`StageFade_StartFromOpaque(10)`, sets `D_83503BB0` to one, copies 168 bytes
from `D_83503B00` to `D_83503E88`, calls `func_87F0DBFC` with the existing
state at `D_83503F58` and arguments 0, 150 and -1, and sets `D_83503BA8`
to one. The broader meanings of the copied fields and state words remain
unknown. The word-aligned record view gives the original three-word copy
loop; both globals remain externally owned and no storage is added.
//@src/fragments/1/fragment1_code.c

Compiled caller `func_835035F0` invokes this owner for state four of
`D_83503BB4`. Compiled `StageContext_GetFadeMode` returns the stage's mode
byte; `StageFade_StartFromOpaque` starts the fade only in mode one.
Compiled `func_87F0DBFC` initializes its state fields and active flag;
its -1 argument selects a value of zero and limit of one. Existing helper
interfaces and bodies retain their bytes.
//@src/fragments/1/fragment1_tail.c
//@src/8470.c
//@src/fragments/64/fragment64_330850.c

The consumed word-sized mode local and constant-first equality preserve
the original branch operand order. The ordinary opposite equality order
differs in that one instruction. No fakes or padding are required.

Fresh validation on master `a0141fa8b9af852b10a582c487cb972ceeb1c0d8`
plus this patch:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/1/fragment1_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The default host syntax check, forced source compilation and complete US
link pass with `build/pokestadiumgs-us.z64: OK`. ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail comparison and whitespace checks
pass. All 42 original words and retail span `0xABFC8..0xAC070` compare
exactly. Existing matched C, data ownership, layout and CI are unchanged.
