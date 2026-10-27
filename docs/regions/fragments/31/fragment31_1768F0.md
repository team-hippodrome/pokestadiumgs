# Region notes -- src/fragments/31/fragment31_1768F0.c

## 2026-10-27 — `func_88203FB4` zero-byte count accepted

`func_88203FB4` is now C: **39 words / 156 bytes**, leaf. It returns (as
`u8`) how many of the 30 bytes at `D_88A01C40` are zero; the neighbouring
`func_88204050` counts the leading run of non-zero bytes in the same array.
A plain `for (i = 0; i < 30; i++)` matches; copt peels two iterations and
unrolls the rest by four.

`D_88A01C40` must be declared as an array (`extern u8 D_88A01C40[];`, as in
`fragment31_174460.c`). With this file's former scalar `extern u8
D_88A01C40;` and `(&D_88A01C40)[i]`, IDO unrolls differently (0.88). The
declaration and `func_88204050`'s `&D_88A01C40` were updated in the same
transaction (companion edit, no code change for `func_88204050`).
