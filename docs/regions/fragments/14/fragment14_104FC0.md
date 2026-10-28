# Fragment 14 104FC0 matching notes

## func_8130D45C

Accepted recipe: copy the incoming eight-byte rectangle into a local `unk_func_8130D45C`, call the existing rectangle adjustment helper, set the output coordinates from the real first pointer's signed halfwords at offsets 8 and 10 plus 157 and 112, set both output sizes to 72, then call the existing clipping and minimum-size helpers in order. The four signed halfword fields retain `unk_00`, `unk_02`, `unk_04` and `unk_06` names. The aggregate has its actual two-byte alignment and eight-byte footprint; there is no fake, padding, invented argument or semantic rename.

Original `func_8130DEB8` forwards the real object pointer and two separate stack rectangle pointers, and ignores the result. The canonical compiled helpers establish `func_8160732C(void*, void*)`, `func_8160724C(s16*, s16*)` and `func_816072FC(void*)`. Preserve the original aggregate copy even though the adjustment helper writes its fields: the copy is part of the original behavior. It reproduces both unaligned word load pairs and aligned stack stores, including their order. The owner has 33 instructions and a 32-byte frame, with no trailing padding, jump table or shared switch tail.

History audit: live fleet main `afee707ab78d3f63f2f9deeadc7551ec0080eeed` has no exact owner attempt, owner reference or `14_104FC0` regional document in the consulted catalog. No normalized or raw similarity score is available. Current master has no regional document at this path. All open scopes were inspected: process PR #947 covers the separate `func_8414C7D4` owner, while drafts #922, #932 and #940 cover only session documentation. The previous failed `func_8130EA8C` investigation is retained; neither that owner nor its stale helper declarations is changed by this match.

Independent validation against master `e5264768303a56409602fd72f01f029a60d54de1`: the first rectangle recipe passed the full US `make rom COMPARE=1 -j2` with default host syntax checks. The separate unmerged #947 implementation was excluded for that independent build and restored immediately afterward. The independent ROM MD5 and the combined build with #947 both equal retail `1561c75d11cedf356a8ddb1a4a5f9d5d`; `md5sum -c baseroms/us/checksum.md5` passed after the combined build. All 201 already merged process owners and current foreign master matches remain present. No CI, verification, compiler or layout changes are authored. A fresh current-head and merge-result Public PR ROM Gate must actually run its checksum build before merging; skipped draft checks do not count.

Current-master integration: after #947 was strictly verified as merged at `09ed36b421c6d4217ed030f1e29e4313381ce198`, the unchanged rectangle owner passed the full US build and explicit retail checksum again with all 202 merged process owners present. The draft branch was refreshed onto that master before ready validation.

## 2026-10-28 — whole `.rodata` window; hand-maintained `func_8130F2C4` asm retired; `func_8130EF88`, `func_8130D340` matched

`rom.yaml` now gives this file its full `.rodata` window, 0x10A8C0–0x10AA10 (formerly only 0x10A9E0 onward). Splat migrates the strings, floats and both of `func_8130F2C4`'s jump tables into the generated `.s` files. The hand-maintained `hand_asm/fragments/14/func_8130F2C4_manual.s` existed only to carry the tail of `jtbl_81312840`, so it is deleted and the pragma points at the generated file.

The address-taken data splat does not migrate is defined in C at its retail position:
- `D_81312730` (`func_8130D1FC`'s template) before that pragma;
- `D_81312750`/`758`/`760` before `func_8130D4E0`;
- `D_8131279C`–`D_813127DC` right after `func_8130DEB8`.

`D_813127E0` is not a constant. It is `func_8130DEB8`'s end pointer one past `D_813127DC`, now the `aliases.ld` line `D_813127E0 = D_813127DC + 0x4`. The two 36.5 values there are `func_8130D098`'s own double literals. File-scope `const f64` scalars land in `.data` under IDO, and one-element arrays cost an extra `addiu`.

- `func_8130EF88` (input handler): B or an empty slot cancels (phase 7). Otherwise the d-pad bits 8/1/4/2 pick a slot, accepted (sound 2) when non-empty and different, refused (sound 5) otherwise. Needed:
  - base-first subscripts, `(counts + cur)[2]`;
  - locals `input`, `counts`, `dir`, `cur`;
  - `cur` read after the 12.0 store.
- `func_8130D340`: `t = min(+0x30 / 12, 1)`; the size is 302 × `D_8160BD18(t)` by 135 × `D_8160BD1C(t)`, centered on (+8 + 246, +0xA). It uses the file's `unk_func_8130D45C` rect.

## 2026-10-28 — `func_8130D1FC` matched

The color fill for the panel rect:
- it picks row `arg0[0x35] >= 2` of a `const s16 colors[4][4]` local and calls `func_8160945C(rect, colors[row + 2], colors[row], t)`, with `t = +0x2C / 1` (an integer 1, as in `func_8130D098`; a `1.0f` divisor becomes a multiply);
- it offsets the rect by (+8, +0xA);
- in rows 0/1 at phase ≥ 5 it grows the height by `D_8160BD1C(+0x30 / 12) * 53`;
- then `func_816072FC`.

The local must be `const`. IDO then puts its initializer template (`D_81312730`) in `.rodata`, ahead of the file's other constants, as in retail; a non-`const` local puts it in `.data`. `t` is declared before `colors`. The runner rejects the data move as non-text layout drift, so this was installed by hand and verified with `make COMPARE=1 RUN_CC_CHECK=1`.

## 2026-10-28 — `.data` window; `func_8130D4E0` matched

`rom.yaml` gives this file the `.data` window 0x10A240–0x10A270, between `fragment14_FF070`'s data in the shared blob and `fragment14_1077C0`'s window.
- `D_813120B0` is `func_8130D4E0`'s function `static f32` timer. Retail forms its address with `lui` on every access; IDO only does that for a function static (an `extern` or file-scope definition gets its address CSE'd into a saved register).
- Function statics are emitted in source order with file-scope data, so the rest is defined just after `func_8130D4E0`: the highlight color `D_813120B4` (shared by `func_8130E99C` and the still-assembly `func_8130D6A4`), then `D_813120B8` and `D_813120C4`–`D_813120D4`.

`func_8130D4E0` draws the four selector icons (`func_8004D19C` at `pos + D_81312750/758[i]`, texture `func_8004C990(51, D_81312760[i])`). The selected one (+0x38) blinks while `func_8160BCB0(timer, 32) > 16`, using `gDPSetEnvColor` 0x808080FF around it and white after. The whole draw is wrapped in the `D_80094E38`/`D_80094F50` display lists (`gSPDisplayList`). Positions are written `pos[k] + table[i]`. `D_81312760` is `u16`, since retail reads it with `lhu`.
