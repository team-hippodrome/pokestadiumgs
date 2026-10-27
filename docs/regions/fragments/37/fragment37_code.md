# Region notes -- src/fragments/37/fragment37_code.c

## 2026-10-27 — `func_88800D34` move-slot PP draw accepted

`func_88800D34` is now C: **35 words / 140 bytes**, frame 0x20, `s8` slot
argument (stored word, reloaded with `lb`). If the move ID at
`D_880068B0 + 2 + slot` is not 252, it passes the current PP
(`D_880068B0[0x18 + slot] & 0x3F`) and `func_80062EB0(move, pp byte) & 0x3F`
to `func_88000FC4(273, slot * 27 + 259, 1, 1, ...)`. `func_80062EB0` is the
existing max-PP helper (its other caller stores the result as `max_pp`), so
the two values are current and maximum PP for one row.

Source shape: index the field arrays as `(D_880068B0 + 2)[slot]` /
`(D_880068B0 + 0x18)[slot]` (a struct with `moves[]`/`pp[]` arrays at those
offsets also matches). `D_880068B0[slot + 2]`, a cached `D_880068B0 + slot`
record pointer, and commuted `slot + D_880068B0` all reverse the `addu`
operands and the `t6`/`t7` roles (normalized 1.0, raw 0.83–0.89).
`func_88000FC4` is declared with `s16` final parameters as in its other
caller; `s32` changes nothing here.
