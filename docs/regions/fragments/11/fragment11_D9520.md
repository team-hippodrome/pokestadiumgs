# fragments/11/fragment11_D9520.c

## 2026-10-29: `func_81601B00` requeue

requeue (0.86). `(s32 *flags, s32 port, s32 value)` walks three save files of a Game Boy port and sets flag bits via func_816019C0:
- kind 0x20/0x21 deck files, looping `i <= func_8005CB38(port, 0x21)`;
- kind 0x23 roster pairs at +0x3A, counted by +0x39 (closed only when read succeeds);
- kind 0x22 header.

The shape that matches the control flow: `kind = (i == 0) ? 0x20 : 0x21; sub = (i > 0) ? i - 1 : 0;` computed before `if (port >= 0 && port < 4 && (handle = func_8006218C(kind, port, sub, 0)) != NULL)`, plus a `pair = &roster[0x3A + i*2]` pointer. Buffers are entry[0x4C..0x50] @0xF8, roster[0xA8] @0x50, header[0x10] @0x40. Remaining: s-register numbering. Retail has handle s0 / &entry s1 / i s2 in loop 1 and handle s2 / i s1 / pair s0 in loop 2, and loads entry[1] into $v0 (a species temp) before the call. Next: separate handle variables per section, plus a species temporary declared inside the while.
