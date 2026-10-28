# fragment25_15BBC0

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
