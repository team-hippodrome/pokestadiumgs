# fragment14_FF070 matching notes

## func_81309820

This one-pointer, void handler reads the signed halfword at offset
`0x137B6`. When it is below 2, it increments that halfword, stores 1 and 2
in the halfwords at `0x137D4` and `0x137D6`, sets the byte at `0x137F5` to
10, and calls existing `func_800226C0(1)`. Otherwise it calls existing
`func_81309740(arg0, 8, 0)`.

Compiled `func_81309928` selects this handler for input mask `0x400` and
ignores its result. Compiled sibling `func_813096B4` decrements the same
signed halfword when nonzero, writes -1 and -2 to the same two halfwords,
and sets the same state byte to 10; its zero branch calls `func_813095C4`.
These shared accesses establish the actual widths and local structure view.
The unknown fields retain their address-based names, and the view allocates
no storage.
//@src/fragments/14/fragment14_FF070.c

Original `func_81309740` receives a context pointer, consumes the second
argument's unsigned low halfword and the third word, updates these transition
fields, and calls other existing context helpers. Existing calls and
declarations are preserved. Original `func_800226C0` constructs its subsequent
call arguments from the incoming selector; this owner supplies only selector
1 and consumes no result.
//@src/229E0.c

The first candidate reproduces all 36 instruction words (144 bytes), including
the 24-byte frame. The current region catalog and private attempt ledger
contained no earlier attempt for this owner. Existing matched C and helper
bodies remain unchanged. No new fakes, padding, qualifiers, instruction
rewriting, storage, layout, or CI changes are required.

Fresh validation uses master `0acfa5069e1b3a1b796d209bf7c4a8a2e4e51071`
plus this patch. The updated unchanged baseline passed its own complete US
build and retail comparison after normal extraction. An unsuccessful trial
in fragment 37 was restored and forced through compilation before acceptance.
Final validation forces the changed source through the default syntax-enabled
Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/14/fragment14_FF070.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 144 bytes at ROM `0x1019B0..0x101A40`.

## 2026-10-27 — `func_81308014`: matched

`D_81311F80 += func_816092FC(); if (D_81311F80 > 30.0f) { D_81311F80 -= 30.0f; return 1; } return 0;`. Retail's three separate `lui $at` reloads of `D_81311F80` come from a function-scope `static f32 D_81311F80 = 0.0f`: IDO CSEs the address into a register for an `extern` or a file-scope static, but not for a function-scope static. The static needs this object to own the 16 bytes at 0x81311F80, so `yamls/us/rom.yaml` splits `fragment14_data` there (`[0x10A110, .data, fragments/14/fragment14_FF070]`, then an unnamed `[0x10A120, data]`). IDO pads the section to 16 bytes, so the three unreferenced words at 0x81311F84-0x81311F8C are defined after the function as `D_81311F84[2]` and `D_81311F8C`; IDO emits the function-scope static first only when those definitions follow the function.

## 2026-10-27 — `func_81307228`: layout-prerequisite

layout-prerequisite. A 12-case switch on `*(u8 *)(arg0 + 0x137F5)`, after a `+0x137D0 < 16.0f` early 0, returning 0/1. Its table `jtbl_81312564` sits in the shared `rodata` blob at `0x10A6D0`, below `fragment14_FF070`'s current `.rodata` subsegment (`0x10A7D0`); extend the subsegment down (every label in the run must be this file's) before writing the switch.

## 2026-10-28: `func_8130AEF4` prototype; `func_8130B06C` handoff

- `func_8130AEF4` takes an `s32` third argument: the callee tests it with
  `bltz`. Declaring it `u8` made every caller mask with `andi 0xFF`.
- `func_8130B06C`: requeue (normalized 1.0, frame only). It is the
  increment twin of `func_8130B0E0`: `count = base[0x6911]`; if below 8,
  store `count + 1`, advance the `+0xE8E8` node to its `+0x4D98` successor,
  and call `func_8130AEF4(arg0, func_8160A33C(node, 2), count' + 2)`.
  With the sibling's spelling and an inline last argument, every instruction
  matches except the frame: 0x30 vs retail's 0x20, because the named
  `base`/`store_base` locals reserve slots. Neither declaration order nor the
  stack-aware permuter (200 s) fixes it.

## 2026-10-28 — `func_8130B06C` matched; `func_8130B0E0` cleaned

Both read a real state struct (`unk_func_8130B06C`: current node at 0xE8E8, index byte at 0xE911) and node struct (`unk_D_8130B06C_node`: predecessor 0x4D94, successor 0x4D98). With typed fields IDO forms the two large-offset bases itself (`a0 + 0x8000` for loads, `a0 + 0x7FFF` for stores) and keeps the 0x20 frame. The named `base`/`store_base` locals were what cost the extra 0x10. `func_8130B0E0`'s permuter body (`new_var`, `((0, 0x7FFF))`) is replaced by the plain decrement twin, byte-identical.
