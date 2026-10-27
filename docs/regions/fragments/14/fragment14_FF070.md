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

## 2026-10-27 — `func_81308014`: requeue

requeue. `t = D_81311F80 + func_816092FC(); if (t > 30.0f) { t -= 30.0f; return 1 } ; D_81311F80 = t` (result 0 otherwise). Best 0.84 with an early-return form. Retail re-materializes `lui $at` for each of the three `D_81311F80` accesses and keeps `t` in `$f2` with an in-place subtract and a tail-duplicated store, whereas IDO CSEs the address into a register in every spelling tried (local/global/duplicated store/`volatile`). Permuter 200 s only found a semantics-changing body.

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
