# fragment44_1F5F20 matching notes

## 2026-10-29 — `func_8AF07EBC` matched; `func_8AF087D4` requeue

`func_8AF07EBC`: clear bit 0 of `+2` in all six `D_8AF2C964..978`
objects, then `switch (D_8AF2C960)` sets it on one of them.

`func_8AF087D4` (**requeue**): the menu step returns `s16 result = 7`.
- Increment `D_8AF2C9CC` up to 4, else call `func_8AC007FC()`.
- The 0x4000 button gives `func_8AF00130(3)` and result = 1.
- Otherwise `prev = D_8AF2C960` and `switch (D_8AF2C960)` (on the global,
  not `prev`, which removes an `andi`). Cases appear in the order 0, 1, 2, 3,
  5, 4, each calling its `func_8AF08xxx(7)`. If the global changed, call
  `func_8AF00130(1)`.
- Then `func_8AF07EBC`, `func_8AF08390`, `func_8AF07CBC`.

Remaining: retail's frame is 0x28, with `result` at 0x26 and `prev` at 0x1A
(two words apart). Ours packs both `s16`s into one word of a 0x20 frame.
