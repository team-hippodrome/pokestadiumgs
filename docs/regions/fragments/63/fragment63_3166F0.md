# Fragment 63 3166F0 matching notes

## 2026-10-29 — split from `fragment63_315A90`

Retail `.rodata` shows a second object starting here.
`fragment63_315A90`'s constants end at `D_87E1B844`, then two zero words pad
to the 16-byte boundary. This object's own constants (`D_87E1B850`,
`D_87E1B854` = 182.0416718f, used by `func_87E12D80`) follow, padded again
before `fragment63_317060` at `D_87E1B860`. No function between
`func_87E129D0` (the last user of the first block) and `func_87E12D80` touches
rodata, so the text boundary lies in that range. 0x87E12D80 was chosen, and any
16-aligned choice there gives identical bytes. Both objects own their
`.rodata` now (0x31F150 / 0x31F1C0), so the `31F150` blob is gone. The
`fragment63_315A90` C that used `extern D_87E1B824..844` now writes
`0.33333334f` (one literal per use, as IDO does not merge them).
