# fragment10_D5250

## 2026-10-28 — `func_82801718`: requeue

requeue. Slot search: `if (arg0->unk_88) { step i by arg2 while 0 <= i < 4 && arg0->unk_18[i] != 0 } else { i = arg1 + arg2; }`, then return `i` if it is in range, otherwise `arg1`. Struct overlay: `unk_18` is `u8[4]` and `unk_88` is `s32`. Best local spelling (0.913): `s32 i = arg1; s32 result = arg1;`, a `do { i += arg2; } while (...)` loop, `else i = arg1 + arg2;`, and `if (in range) result = i; return result;`. The only diff is the return tail: retail has `jr ra; nop` for the in-range path and a separate `jr ra; or v0,v1` fallback. With `return i; return result;` instead, the else path's `i` moves to `$v1`. Making `arg1` itself the loop variable (`start = arg1`) matches everything except the else path, which then writes `$a1` instead of `$v0`. The `for (i = arg1 + arg2; ...)` and pre-test `while` forms change the loop body's temps (`t9`/`t0`). The permuter made no progress in 300 s (220 → 220). Next: give the else path its own early return (`return arg1 + arg2` after a range check), or a `goto`-based common tail.

## 2026-10-29 — `func_828020C4`: requeue (per-access `lui` on `D_82802858`)

Pulse highlight. `t = D_82802858 + func_816092FC()`, wrapped by
`D_82802854`, is stored back. Then
`pulse = __sinf(6.2831855f * t / D_82802854) * 0.5f + 0.5f`,
`gDPSetCombine(0x30B261, 0x5566DB6D)`, and four slots switch on `arg0[0x18+i]`:
case 0 calls `func_82800620(i, 0, pulse)`; cases 4 and 7-10 call it with 1.
Both then call `func_82800984(i, *(f32 *)(arg0+0x98+i*4))`, and the function
ends with `func_82800AE0(arg0)`. The structure matches. Retail re-forms
`%hi(D_82802858)` for the load and for the join-point store (`lui at` each),
while ours caches `&D_82802858` in `$v0` and moves the store into a `bc1fl`
delay slot. That is the per-access-`lui` pattern: try a function-local
`static f32` (it needs this file to own the data up to it), as in
`func_8F100020`. Body: `scratch/c/0c4.json`.
