# fragments/44/fragment44_20C560.c

## 2026-10-29: `func_8AF1E54C` requeue

requeue (0.987). Screen setup for page 0x92: picture/selector nodes, the 'slif' slider, a 0x504-byte payload (zeroed, then fields 0x00-0x4A) passed to func_8AF1E4B8, then the list setup. Declaring `page, x, index, y, payload, state, selector, window, slider, title, (2 slots), picture, sub, (1 slot)` reproduces every stack offset. Retail has two more register-only locals between title and picture and one after sub, which we haven't identified (`unused0` stands in). Payload stores must be in source order 13, 0x55, 0x41, 6, 3, 1, 5, 0, 0x41 (offsets 0x14, 0x24, 0x28, 0x2C, 0x3C, 0x3E, 0x34, 0x38, 0x4A). Remaining: retail forms `s0 = state + 0x28` in the jal delay slot and loads `0x20(s0)` for func_8004C594's argument, where IDO folds our `sub` into `0x48(state)`. Next: make the payload a typed member of the state and pass `&state->payload` somewhere, so the base is materialized.
