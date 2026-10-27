# fragment47_24AE60

## 2026-10-28 — `func_860065E8` matched

`switch` directly on `func_87F01A40(arg0)`. Case 3 sets flag bits 5, 7 and 4 of byte 0x75C0, in that order, as three separate bitfield writes; case 4 clears bit 5 and sets 7 and 4. Both return 1. There is no trailing `return`: retail returns whatever the call left in `$v0` (marked `//!bug`). Keeping the result in a variable, or returning it, adds a `move`.
