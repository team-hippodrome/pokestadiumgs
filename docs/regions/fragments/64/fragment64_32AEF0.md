# fragments/64/fragment64_32AEF0.c

## 2026-10-29: `func_87F08C68` requeue

requeue (0.47). Tile layout for func_87F08D6C's local record:
- `step = 0x2000 / (bpp * width)` stored at +4;
- if height < step: step = height and count (+2) = 1;
- otherwise step is made even (signed `% 2`, retail emits the `bgez` fixup), then step -= 2, count = height / step, rounded up.

Retail loads layout[0] before size[0] (the product is written `size[0] * layout[0]`) and keeps step in $v1 as `(u16)` of the quotient. Our field-update spellings compute an unsigned `% 2` and differ in register flow. Next: an s32 local for the quotient with explicit u16 field stores.
