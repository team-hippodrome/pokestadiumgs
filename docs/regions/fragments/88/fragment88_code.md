# fragment88_code

## 2026-10-28 — `func_81C007A4`: requeue

requeue. Reads a 3-byte record via `func_8005E278(arg0, &rec)`. It computes `elapsed = arg1 - rec.unk_1` (wrapping by +140), `remaining = rec.unk_0 - elapsed`, then writes `{1, arg1}` back with `func_8005E2BC` and calls `func_8005E07C(arg0, 0)` when `remaining <= 0`. Signature `(u8, u16)`. Best clean 0.8857: register numbering only, with retail keeping `arg1` in `$v1` and `elapsed` in `$a0`. The permuter reaches 30 only with fakes (`new_var = 1;` hoisted and an empty `if (remaining && ...)`), so none was committed. Next: a different expression shape for the wrap, e.g. a modulo-style helper or `elapsed` declared first.
