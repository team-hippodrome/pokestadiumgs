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


## 2026-11-03 — `func_88203A18`: genuine indexed-search acceptance

Accepted: remove all six `REWRITE_FUNCTION_WORD` directives. The missing
source shape is indexed addressing, not another explicit cursor spelling:

```c
index = 0;
if (list->capacity != 0) {
    do {
        if (entry == (void *)((u8 *)list->entries + index * 0x76)) {
            return index & 0xFF;
        }
        index++;
    } while (index < list->capacity);
}
return index & 0xFF;
```

Stock IDO 7.1 creates the cursor induction variable, hoists the list fields,
and allocates capacity to V0 and the cursor to A2. All 16 retail instructions
(64 bytes, including the return tail) match directly. The incoming entry and
12-byte list descriptor use their actual pointer types; the result retains
its existing byte mask and signed-word return contract. No explicit cursor,
new parameter, unused local, padding or register hint is needed.

This supersedes the earlier explicit-cursor requeue. Returning capacity on
exhaustion, a separate default-result carrier and a narrowed byte return did
not resolve the residual; byte-addressed indexed comparison with direct
capacity reads matched on its first probe. Keep the signed-word interface.

Verification: unchanged and candidate native modules each reproduce with
20 leading blank lines, and both equal the built module in all allocated
bytes/layout, function/object extents and semantic relocations. Normal host
syntax and `make -j1 COMPARE=1 RUN_CC_CHECK=1` pass; retail ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. No compiler, linker, coverage or tool changes.

## 2026-11-12 — `func_88203744` storage-list initialization accepted

`func_88203744(void *pool)` matches **114 instructions / 456 bytes** with
an 88-byte frame (US ROM `0x1769C4..0x176B8C`, end exclusive). It clears
`D_88234660`, allocates and zeroes the 118-byte fallback at `D_88234664`,
then initializes four existing `LabPCStorageList` descriptors at
`D_88234630`. `func_8820137C` uses the fallback for other list types.

The selector words in `D_88233760` are 37, 36, 23 and 22. Lists 0 and 1
obtain capacity from `GbSave_GetRecordCapacity` and use the signed byte
`D_88006868` as the deck port; lists 2 and 3 use `func_80053230` and port
0. Each list receives a zeroed `capacity * 118` entry array and a cleared
`changed` flag. When `func_8800005C` is nonzero, lists 0 and 1 receive a
zero count. Otherwise, a successful `func_8006218C(selector, port, 0, 0)`
handle supplies entries through `Deck_ReadEntries`; `func_88203670` clears
entries whose existing flags are zero, and `func_8006229C` closes the
handle. Failed opens preserve the existing count, as in retail.

Inspected definitions and callers establish the pool-pointer interface,
12-byte descriptors, 118-byte entries and three-argument reader. The
existing typedef is moved before this owner; storage ownership is unchanged.
The new declarations retain the helper definitions' word/pointer ABI.

//@src/fragments/31/fragment31_186690.c
//@src/fragments/31/fragment31_189760.c
//@src/fragments/31/fragment31_174460.c
//@src/fragments/29/fragment29_166060.c
//@src/3A00.c
//@src/517E0.c
//@src/585D0.c
//@src/615D0.c

Putting the list initialization in the `for` initializer and assigning port
0 after the capacity call recovers the retail instruction schedule. A
marked `FAKE` unused two-word local preserves eight otherwise unused stack
bytes. The port is assigned by every reachable switch case; its original
live-in/live-out stack home is preserved without inventing an initial port.

Fresh validation on master `5b3625a93b231fc725defa603571d3912dc34161`
plus this source replacement: default syntax-enabled
`make -W src/fragments/31/fragment31_1768F0.c -j4 VERSION=us rom`, exact
`build/pokestadiumgs-us.z64: OK`, full retail `cmp`, and
`git diff --check` pass. ROM MD5: `1561c75d11cedf356a8ddb1a4a5f9d5d`.
Reader-only object comparison verifies all allocated module sections,
function extents and semantic relocations against the original assembly
module. No generated coverage, layout, compiler or CI changes.
