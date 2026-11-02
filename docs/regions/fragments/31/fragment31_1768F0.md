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

## 2026-10-27 — `func_88203670` and `func_88203ED8` accepted

- `func_88203670(s32 type, u8 *entries, u8 count)` (**53 words / 212
  bytes**): for type 0 (flags `D_88234618`) or 2 (flags `D_882345F8`) it
  `_bzero`s every 0x76-byte entry whose flag byte is 0. Write a `switch` with
  one loop per case, an **unsigned** (`u32`) index (the target tests
  `count == 0` with `beqz`; `s32` uses `blez`), and `entries += 0x76` per
  iteration.
- `func_88203ED8(u8 *entry, s32 list)` (**55 words / 220 bytes**): when
  `D_88234630[list]` (`LabPCStorageList`) is not full, append a copy of
  `entry` at `entries[count]`, increment `count`, set `changed`, then call
  `func_88203A58(entry)`. The 0x76-byte entry type needs 2-byte alignment
  (the copy ends with `lhu`/`sh`), and `count++` must precede `changed = 1`.


## 2026-11-02 — `func_88203A18`: rewrite cleanup requeue

Base: `4d4dea19cb9d3ef8c26c6931b4bda157c40862c5`. Six word rewrites still
exchange the capacity and cursor registers. The function searches the
allocated 118-byte entry range, using `LabPCStorageList.capacity` at +1
and `entries` at +4, and returns the matching index or capacity. The
assembly caller `func_88203A58` passes the original entry address and a
12-byte `D_88234630` list descriptor, then uses the index to update storage.

Reading capacity directly in the guard and bound recovers its retail V0
load. The candidate is 68 bytes instead of 64: it moves the incoming address
from A0 to A2 and keeps the cursor in A0, reversing retail's roles. Cached
count widths, raw/typed header views, byte/record cursors, numeric/pointer
address views and a byte result do not close this residual. Standard C
`register` hints are byte-inert on both the cached and direct-field controls.
The existing function and ABI remain unchanged. Next: test loop entry/exit
and cursor lifetime forms against the capacity-root control, keeping the
caller-proven pointer/index behavior. No replacement was installed or gated.
