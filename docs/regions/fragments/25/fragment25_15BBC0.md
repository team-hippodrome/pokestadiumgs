# fragment25_15BBC0

## 2026-10-28 — `func_821020B0`: requeue (three-item distance sort)

Compute `dist[i] = func_82102CE4(ref, func_82101B80(items[i]))` for three
items, then bubble-sort `items`/`dist` with three passes of
`j = 2..1: if (dist[j] + D_82103DB0 < dist[j - 1]) swap`. Retail keeps
`&dist[i]` and `items` pointers in saved registers, loads the tolerance
once, and walks the inner loop by pointer (`&dist[2]` down to `dist`, with
a byte offset 8 -> 0 into `items`). Index loops give 0.44. A pointer
rewrite gets unrolled by copt (127 instructions). The 240-second permuter
started from 7820.

## func_82101D88: layout-prerequisite (2026-10-28)

Body (code-equivalent, 0.46 only because of the item below):

```c
for (i = 0; i < 3; i++) {
    func_82101CB4((f32 *)(arg0 + i * 0x2C), arg1, arg2, arg3,
                  *(f32 *)(arg0 + 0x94), (f32)i * TAU / 3.0f);
    *(u8 **)(arg0 + 0x84 + i * 4) = arg0 + i * 0x2C;
}
```

Retail hoists `D_8210411C` (6.2831855f) out of the loop and across the call.
IDO does that only for a compiler literal (`6.2831855f` in C hoists correctly,
0.52 with the remaining diffs being the two separate pointer IVs). The extern
`D_8210411C`, or a `const`/`static` spelling of it, reloads every iteration.

So `D_82104118..D_82104168` in `fragment25_data` are really the C files'
`.rodata` float pools: `D_8210411C` and `D_82104120` are both 6.2831855f, for
two different functions. fragment25 has no `.rodata` subsegments yet. Next
action: find the `.data`/`.rodata` boundary in `fragment25_data` (the
mutable `D_82104170`, `D_82104174`, `D_82104188` and `D_8210418C` follow the
literals, so check whether they are a later file's `.data` or `.bss`). Then give each
file its `.rodata` slice and convert the C files' `D_8210xxxx` float externs to
literals.

## 2026-10-29: `func_82101FB4` requeue

requeue (0.968). `(u8 *arg0, f32 *target, f32 speed)`:
- `delta = target - current` (func_82102C54 with func_82101B80(arg0));
- if `|delta|^2 > 0`: angle = func_82102D10(delta) - arg0[0], wrapped by func_82102D34, scaled by `*(f32 *)(arg0 + 0x28)`, added to arg0[0], then arg0[0] wrapped. func_82102D10's C definition is `void`, but it really returns func_821028E0's f32; this file declares it `f32`.
- `next = (idx + 1 == 4) ? 0 : idx + 1` (the ternary gives retail's two-store form);
- `slot = (arg0 + 4) + next * 8`; func_82102B94(slot, speed, arg0[0]); func_82102BE8(slot, func_82101B80(arg0)); idx = next.

Declare `slot, angle, next, delta[2]`. Remaining: retail spills `slot` at sp+0x24, ours at sp+0x20.
