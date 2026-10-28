# fragment4_AE600

## func_81801420: requeue, uncached global address (2026-10-28)

```c
phase = D_81805924 + func_818006B4() / 60.0f;
if (1.0f < phase) phase -= 1.0f;
D_81805924 = phase;
D_81805920 = __sinf((phase + phase) * D_81805CD8) * 0.5f + 0.5f;
```

This is semantically exact. Retail emits separate `lui $at` forms for the
`D_81805924` load (right after the `jal`) and for the store. Our IDO CSEs the
address into `v0` (`lui`/`addiu`) and schedules the `div.s` first, at 0.62.
Reordering the statements, a `delta` temp and `volatile` make no difference. It is
the same retail-vs-local address-CSE gap as `func_800258F4` and `func_8220D630`.
