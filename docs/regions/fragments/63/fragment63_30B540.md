
## 2026-10-27 — `func_87E07F4C`: requeue

requeue. Maximum of the four words at `arg0 + 0x2190 + i * 0x18`. The plain `max = e0; if (max < e1) …` chain (with a `void *` parameter, as the later prototype requires) reaches 0.95; retail loads `e1` before `e0` and copies `arg0` into `a1` for the last two reads, the signature of a copt-unrolled loop over a pointer copy. Indexed, pointer-walking, `!=` and struct-array loops are all left rolled by copt (0.29–0.42). Next: find the loop shape copt unrolls with an `if` body (see the `for` notes in AGENTS.md §5).
