# Region notes: fragment14_1077C0

## 2026-10-14: func_8131109C remains GLOBAL_ASM

No match was accepted. The original func_81301548 and func_813018FC callers
both pass their real pointer at incoming object offset 0xF64C, retain the
word result across a subsequent call, and use it as a signed switch selector.
The callee reads only that pointer, returns -2 for either outer guard failure,
-1 when the word at offset 168 is zero, and the word at offset 72 otherwise.
It is a separately called owner; the callers' switch tails are not owners.
The retail boundary contains nineteen executable words and two trailing nops.

This ordinary nested spelling failed the full US ROM checksum:

```c
s32 func_8131109C(u8* arg0) {
    s32 var_v1 = -2;

    if (arg0[56] == 5) {
        if (arg0[58] >= 3) {
            if (*(s32*)(arg0 + 168) != 0) {
                return *(s32*)(arg0 + 72);
            }
            return -1;
        }
    }
    return var_v1;
}
#pragma C_FUNCTION_PADDING(8)
```

The compiled owner has eighteen executable words instead of nineteen.
IDO coalesces the default -2 into v0 instead of the required v1 followed by
a return move, and moves the -1 literal into the return delay slot rather
than before the inner word guard. The byte loads, comparisons and pointer
offsets otherwise follow the expected body. This is the known result/tail
allocation family. Do not repeat ordinary nested, ternary, result-phi or
declaration permutations without a materially new supported lifetime model.

The valid trial used default host syntax checks and COMPARE=1 against master
1b4e3e80a7dc471cecbe89311c25f86080ba1f81, excluding only the four other
freshly open matching PRs. All merged sources, including both #885 files and
current foreign resource-loading work, were preserved. Make failed the retail
comparison with MD5 d465fdd16c22474d6537387365d45b47. The baseline and all
canonical siblings were restored; a full rebuild and explicit
md5sum -c baseroms/us/checksum.md5 passed with retail MD5
1561c75d11cedf356a8ddb1a4a5f9d5d. Source, logs and object evidence remain in
work/session-46. No unverified trial is left in the working source.

An earlier host-only failure used C_FUNCTION_PADDING as a macro call instead
of the repository's pragma syntax. Host checking rejected it; its object
dump was still the assembly baseline and is explicitly not candidate evidence.
The invalid source and diagnostic log were retained separately. The corrected
pragma trial above is the only full-ROM failure for this owner.

History audit found no exact owner attempts, unrelated references or 1077C0
regional note at fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed, so no
historical raw similarity score is available. All open PR scopes were inspected
before source edits. Unknown names remain address/argument/register based.


## 2026-10-15: func_8130FF70 matched

The original func_813102A4 callers pass f12 and consume f0; the existing compiled func_8130FFE0 also declares the actual f32(f32) ABI. This is an independent 28-instruction leaf with no padding. Its four existing symbols D_81312988/8C/90/94 reside in the shared 10AA10 rodata block and contain single-precision 3.141592741, 6.283185482, -3.141592741 and 6.283185482 respectively. Retain those existing symbol references; no new pool, data, mapping or layout is needed.

The first two direct while loops using those globals failed full-ROM comparison with MD5 801eec6ec917735a54182b9233c8af7b. All 28 words and the first loop match; the second increment constant loads only inside the loop guard rather than unconditionally before its comparison, shifting the guard displacement. Capturing both existing second-loop threshold and increment in f32 locals before the loop reproduces the original unconditional loads and passes. The first-loop increment remains conditional as in retail. All arithmetic, strict first comparison and inclusive second comparison remain unchanged.

Fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed has no exact/solved owner attempt, owner reference or 1077C0 regional file, so no historical normalized/raw scores exist. The earlier func_8131109C rejection above remains unchanged and was not retried. All open source PRs were this process's separate matching owners.

Based on master 224774092bdc686b39361e5308a59d6567d7ed75. Full US rebuild with default host syntax checks and COMPARE=1, then explicit md5sum -c baseroms/us/checksum.md5 passes retail 1561c75d11cedf356a8ddb1a4a5f9d5d. Source/object/build evidence for both variants remains in work/session-53. No new semantic names, tokens, fakes, helper edits or verification changes.

## 2026-10-27 — `func_81310800`: matched

`arg0` is typed as a local `unk_func_81310800` record (`unk_38` phase byte, `unk_39`, `unk_48` entry index, `unk_8C[]` per-entry bytes, `unk_A8` any-selectable flag). The table argument is one nested conditional inside the `func_81311C70` call (`unk_A8 ? (unk_8C[unk_48] == 6 ? D_81312128 : D_81312104) : D_813120E0`), which produces retail's hoisted `&D_81312104` and else-arm copy; the struct member access gives the `arg0 + index` operand order that the raw `u8 *` index spellings reverse. The result store is `arg0->unk_38 = unk_A8 != 0 ? 3 : 4`, which allocates 4 to t2 and 3 to t1 as retail does.

## 2026-10-28 — `func_8130FD10` matched

Initializer, the long-form sibling of `func_8130FC80`: it copies two 8-byte records (`unk_D_8130FD10`, `s16[4]`, so the copies use `lwl`/`lwr`) to 0x20/0x28, stores the scalar arguments (0x39, 0xA4, 0xA5, 0x44, 0x3C, 0xA0), runs `func_8130FA0C`/`func_8130FB58`, sets 0x48, then runs `func_8130FBC0`. It plays sound 0xA5 when `arg5` is set and moves phase 0/1/4 to 1 (phase 0 also clears 0x30; `case 3: break;` is required). Finally it calls `func_8130F8B4(obj, 1)`. The byte-stored parameters are `s32`: retail neither homes `a1`/`a3` nor narrows the stack-passed one.
## 2026-10-28 — `.rodata` subsegment; `func_8130FA0C` matched

`rom.yaml` gives this file the `.rodata` window 0x10AA10–0x10AB90:
- The three command lists `D_81312880/888/890` at its start belong here: `D_813120E0`'s records in this file's `.data` point at them.
- `D_81312A00` at 0x10AB90 is `fragment14_109280`'s and stays in the shared blob.

IDO emits the plain data first, then the late rodata in function order. Defined in C at the top: the lists, `D_81312898`, the four `s16[4]` color sets `D_81312924`, `D_81312944` and the `D_81312948` angle table. The already-C math helpers now use literals instead of externs:
- `func_8130FF70` is the plain two-loop wrap (`while (3.1415927f < x) x -= 6.2831855f; while (x <= -3.1415927f) x += 6.2831855f;`). The m2c copies emitted the literals in the wrong order.
- `MathUtil_Atan2d_fragment14` uses float-precision pi/2 and pi as double literals.

`func_8130FA0C` fills the four name slots from `func_81603404(i, 4)` (returns `s32`; its second parameter is `u8`, since retail rematerializes the 4):
- status 0 copies name and id from `func_8005D9E0` and falls into status 6, which stores `func_81603368(i)`;
- statuses 2/3 clear the slot (empty name, id 0xFFFF, value 7).

Retail copies the empty name as a one-byte record (address formed, then `lbu`/`sb`). A folded `D_81312944[0]` or `""[0]` load does not reproduce it, so `D_81312944` is typed `unk_D_81312944`. Locals are declared `status`, `i`, then the 14-byte `entry`.

The remaining owners now have their rodata: `func_8130F7B8` (`jtbl_81312968`), `func_813102A4`, `func_81310894` (`jtbl_813129D4`) and `func_81310BF8`.

## 2026-10-28 — `func_8130F7B8` matched

The color picker for this object (`jtbl_81312968` is now in this file's `.rodata`). `scale = D_8160BD04(+0x30 / 16)` and the default color is the object's `s16[4]` at +0x20. In phases 4/5 it switches on the entry index (+0x48):
- 0–3 and 6 → `func_81609530(3)`;
- 4 → color 1;
- 5 → color 2;
- −1 → color 2 if +0x3C is set, else the record at +0x28. This must be written as if/else; assign-then-override adds a `beql`.

Then `func_8160945C(out, color, func_81609530(0), scale)`, returning the scale. The output buffers in `func_8130F8B4`, and `func_8130F794`/`func_8130F6A4`'s output parameter, are now `s16`.
