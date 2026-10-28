# Region notes: fragment57_code

## 2026-10-14: func_833084B0 remains unmatched

One US/default-host-syntax ROM failure. Actual no-argument state loop initializes result 1, forwards fade duration 10 through the existing implicit-forwarding StageFade_StartFromOpaque ABI, checks global word +8 against -1, calls real func_83303564(void), and feeds the word result through func_83307C7C(s32) until 14. Do not replace incoming fade duration with zero or try to match the known-dead-end fade owner. The ordinary cached byte-pointer form folds D_8330A288+8 into a direct relocation each iteration, eliminating the saved global base. It emits 32 versus 35 instructions with three rather than four saved registers; sentinel comparison operands and S1/S2 allocation differ. Need a supported global-base/call lifetime model; no ordinary cached/raw pointer, loop or declaration-order retry.

History audit: No exact owner attempt or fragment57 region catalog note at fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed.

All failed sources, full build logs, and object disassemblies are retained in
`work/session-44`; each fresh baseline was restored. Open PR scopes were
checked for duplicate owner work. No CI, verification, linker, or data changes
were made. These attempts are failures, not claimed matches. The restored
186-owner workspace passes the US retail checksum with default host syntax
checks. Unknown tokens retain their existing address/offset names.

## 2026-10-28 — `func_833084B0`: requeue

requeue. Scene loop: `func_800086A4(2); StageContext_SetClearColor(1); StageFade_StartFromOpaque(10);`, then `do { if (D_8330A288 word 2 == -1) func_80064D28(); func_83303564(); state = func_83307C7C(state); } while (state != 14);` with `state = 1`. Normalized 1.0: only `$s1`/`$s2` are swapped between `&D_8330A288` and the `-1` constant. The permuter reaches 0 only with fakes (`(new_var = -1)` plus an empty `if (1)`), so none was committed. The file's m2c externs mistype `func_800086A4` (really `void`) and this function (`s32 ()`), so a candidate needs `void func_800086A4(s32);` in its declarations.

## func_833018E8: packed color and record selection

This 228-byte owner (57 instructions, 32-byte frame) passes the current
packed color `D_8330A2A4` and flag `D_8330A2A8` to `func_80041FD0`, then
refreshes both values from the record at `D_83308E34 + 4`. It selects a byte
from the record's four-byte array at offset 2. A selector other than -1
uses that index and stores it in `D_8330A300`; selector -1 scans indices
3 through 0 for a nonzero byte and stores index + 1. The selected byte goes
to `D_8330ABDC`, and the outer record's first halfword goes to `D_8330ABE0`.
The all-zero scan leaves the previous selection untouched.

`func_8330853C` installs the incoming record pointer or the fallback record
`D_8330AC68`, whose selector is -1. The assembly callers `func_833019CC`
and `func_83301C60` consume no return value. A partial record view describes
the observed four-byte array and halfword at offset 22; other fields keep
offset names. All globals remain in their existing assembly-owned storage.
//@src/fragments/57/fragment57_code.c

The inspected `func_8003F5AC` returns a four-byte color adjustment through
the aggregate-return ABI. The existing `ColorAdjustment` union describes
that value, as also demonstrated by the call in `func_8004D878`.
`func_80041FD0` receives it by value; `func_8006456C` tests the record's
halfword with `(value & 0x2FFF) == 0x2AAA`. Neither helper interface is
replaced with scalar or output-parameter declarations.
//@src/340C0.c
//@src/4CC20.c
//@src/641E0.c
//@include/color_adjustment.h

The raw byte-pointer recipe matches 56 of 57 words, differing only in the
operand order of the indexed address addition. The typed array field
reproduces retail's base-first addition and matches all instructions.
No artificial locals, padding, instruction rewrites or layout changes are
required.

Fresh validation uses master `cbbb0cf7a546aa82f4f14d08549664e60eda57f2`
plus this patch. The unchanged baseline and final forced compilation pass
the normal syntax-enabled Makefile and complete US ROM link:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/57/fragment57_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Exact acceptance: `build/pokestadiumgs-us.z64: OK`. Full ROM MD5:
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Original-assembly and raw retail comparisons verify all 57
words at `0x2BD118..0x2BD1FC`.
