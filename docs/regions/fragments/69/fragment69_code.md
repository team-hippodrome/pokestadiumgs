# Fragment 69

## 2026-10-15: func_8F102A20

Matched the independent 30-instruction no-argument owner, called by original func_8F102BC8 with no result use. Existing D_80087200 supplies the halfword at offset 12; the original concrete global D_8F1DECA8 supplies unsigned byte offset 28. Mask 0x200 decrements that byte, and mask 0x100 increments it with a maximum of 2. Keep both independent input tests and both original base materializations.

The original decrement narrows to an unsigned byte before comparing against zero. Its BGEZ always skips the lower clamp, so zero decrements to 255. Preserve the source's unreachable lower-clamp test and label this existing bug with //!bug. Do not silently correct the field to signed or remove the comparison. This is an actual retail bug, not a fake, empty debug operation, padding or independent switch tail.

The first direct byte-lvalue recipe passes the full US build with default host syntax checks and COMPARE=1, then explicit md5sum -c baseroms/us/checksum.md5: retail 1561c75d11cedf356a8ddb1a4a5f9d5d. Based on master 13df50bb51c537a3f669831a147cd7c7654bb95a, preserving all 209 previous process matches and the exact new foreign fragment 13 changes. Source/object/build evidence is retained in work/session-54.

Fleet main afee707ab78d3f63f2f9deeadc7551ec0080eeed has no exact or solved owner attempt or owner reference, so no normalized/raw score exists for this owner. The complete fragment 69 notes were consulted, including the accepted direct-global-lvalue 2A98 recipe and terminal 049C (0.7903/raw0.3548), B54 (0.8676/raw0.8676), 37C4 (0.9620/raw0.9494), and 1FF4 (0.9778/raw0.2222) histories; none was retried. The earlier process failure for 8F100020 remains untouched. All open PR scopes were documentation only before edits. No new names, tokens, fakes, qualifiers, data, tooling, layout or verification changes.

## 2026-10-28 — `func_8F100020`: requeue (optimizer-level finding)

requeue. Z-trigger toggle: `if (arg0 == 2) { if (D_80087200->buttonsPressed & Z_TRIG) D_8F103A50 ^= 1; if (D_8F103A50) arg1[2] |= 0x40; else arg1[2] &= ~0x40; } return 0;`.

With standard `-O2`, IDO's global optimizer (uopt) CSEs `&D_8F103A50` into `$v0` (`lui v0; addiu v0`). Retail instead re-forms it per access (`lui t9`/`lui t1` hoisted above the branch, `lui at` for the store). Compiling this exact C with **`-O2 -Wo,-O1`** (uopt at level 1, normal ugen/as1 scheduling) reproduces retail instruction for instruction. Plain `-O1` gets the per-access `lui`s but not the delay-slot scheduling. A per-file `OPTFLAGS := -O2 -Wo,-O1` for `fragment69_code.o` is **not** the answer: 43 functions in the file change and the ROM compare fails, so retail mixes both shapes within one file. What makes uopt skip address CSE for individual functions is still unknown. The same per-access `lui` signature blocks `func_8220D630` (fragment17) and `func_88210FAC`/`func_88211018` (fragment31), so the explanation would likely unlock a family. Next: find the per-function trigger (something in the function that disables uopt's address CSE, an Olimit effect, or a declaration that makes the global non-CSE-able); don't brute-force spellings.

## 2026-10-28 — `func_8F100020`: per-function trigger found — layout-prerequisite

layout-prerequisite. The trigger is a **function-local `static`**. Declaring the toggle as `static s32 D_8F103A50;` *inside* `func_8F100020` makes standard `-O2` emit retail's per-access `lui t9`/`lui t1`/`lui at` exactly. IDO does not CSE the address of a function-local static. A file-scope `static`, a block-scope `extern`, `volatile`, array and struct spellings all still CSE into `$v0`. This is ordinary, plausible original source (a toggle kept in a static), not a fake.

Landing it requires this C file to emit that static at retail's address. IDO places function statics in `.data` in source order (checked: `a, f's static, b, g's static, c`), and `func_8F100020` is the file's first function. Its static sits 0x150 bytes into the data (`D_8F103A50` at ROM 0x35C280, initial value 1), so the source evidently defines the 0x150 bytes of tables from `D_8F103900` (scripts with `func_8F10008C`/`func_8F1000F4` pointers, the "DummyMon" record, the EUC-JP prompts "Save current data to ROM?"/"Quit ?") before the function. Next action: give `fragment69_code` a `.data` subsegment from 0x35C130, define that data in C, then define `func_8F100020` with `static s32 D_8F103A50 = 1;`. The data after it (`D_8F103A54`...) is dense and needs the same treatment up to a 16-byte boundary, or the subsegment has to end where retail pads.

Check this for every owner with the per-access `lui` signature: if the global is used by only one function, a function-local static is the likely original.
