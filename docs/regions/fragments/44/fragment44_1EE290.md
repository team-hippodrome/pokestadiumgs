# fragment44_1EE290 matching notes

## func_8AF0007C

This one-word, void owner refreshes input through `func_80064D28`, copies
40 bytes from the controller pointed to by `D_80087200` into existing
`D_8AF2A590`, then conditionally clears three input halfwords through
`D_8AF263C0`. The snapshot precedes those stores. Input remains enabled only
when signed halfword `D_8AF2BDDC` is at least 4, word `D_8AF2BDD0` is zero,
and the incoming argument is 1. Other cases clear pressed, held, and repeat
at byte offsets 8, 6, and 12, respectively. The global pointer is reloaded
for each store, preserving the original alias behavior.

The original aggregate copy performs three 12-byte iterations and one final
word transfer. Its aligned word loads/stores and complete 40-byte extent
support the local structure view. Bytes outside the three input halfwords
remain opaque. All declarations are external; storage ownership and layout
remain unchanged.
//@src/fragments/44/fragment44_1EE290.c

Existing `MenuInputState` and compiled `func_8AF133C0` consume offsets 6, 8,
and 12 as held, pressed, and repeated input. The actual no-argument, void
`func_80064D28` starts controller input reads and calls the existing input
and UI updates. Compiled `func_8AF01EAC` passes its word state to this owner
and consumes no result. Its stale local result declaration is corrected to
void; independent comparison preserves all 84 caller instructions.
//@src/fragments/44/fragment44_1FD260.c
//@src/65820.c

The first aggregate-copy recipe matches all 45 instruction words (180 bytes)
and the original 24-byte frame. Existing address-based names and neighboring
C remain. No new fakes, qualifiers, padding, instruction rewrites or CI changes
are required.

Fresh validation uses master `3fab4ae5dc818b9b491874fdbe2833795b067377`
plus this patch. The unchanged baseline passes its own complete US ROM build
and retail comparison. Final validation forces recompilation through the
default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/44/fragment44_1EE290.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 180 bytes at ROM `0x1EE2EC..0x1EE3A0`.

## 2026-10-27 — `func_8AF01C84`: matched

gSPDisplayList(`D_80094E38`), gDPSetPrimColor(0, 0, 255, 255, 255, 255), then 28 strips `func_8AF01A0C(x, arg1 + i * 4, 96, 4, arg2, 96)` with `arg2 += 0x300` after each, then gSPDisplayList(`D_80094F50`). Signature `(s32 arg0, s32 arg1, u8 *arg2)` with `s16 x = arg0`; with the macros written in this order and a `for` loop advancing `arg2` in place, the primitive-color temps land in retail's t1/t2.

## 2026-10-28 — `func_8AF00360`: requeue

requeue. Shape: `s8 buf[4]; sprintf(buf, D_8AF28760, arg0); return (u16)((buf[0] << 8) | buf[1]) | 0x234C0000;`. Retail homes `arg0` and reloads it as `lbu a2,0x2B(sp)`. Only `s32 arg0` with `((u8 *)&arg0)[3]` reproduces that, plus the 0x28 frame (callers pass `(u8)`, and old-style `u8`/`char` definitions still emit `andi`). Best local score 0.8889: the only remaining diff is retail keeping the masked code in `$a3` (`or v1,t6,t8; andi a3,v1,0xFFFF; or v0,a3,at`), where IDO uses `$v0`/`$v1`. The permuter plateaued at 10 after 240 s. Next: hypotheses about the signature (e.g. extra unused parameters that would put the variable in `$a3`).

## 2026-10-28 — `func_8AF00690`: requeue (release queued nodes)

Up to ten times while the s32 counter `D_8AF2BF10` stays positive:
`node = func_8AF00240((s16)count)`. On NULL just decrement. Otherwise call
`func_8AC01064(func_8AF00360((u8)count))` (retail reads the counter's low
byte with `lbu +3`), clear bit 0 of the u16 at `node->+8 + 2`, decrement,
and `_bzero(node, 0xC)`. Retail tests the count before entering, then
re-tests it right after the body and before `i++`/`i != 10`, keeping
`&D_8AF2BF10` in `$s0`, the node in `$s1` and i in `$s2`. Best 0.74
(`for (i = 0; i < 10; i++) { if (count <= 0) break; ... }`). `do`/`while` and
early-return shapes are worse. A 240-second permuter: 1135 -> 1020.


## 2026-11-03 — `func_8AF00504`: rewrite-free loader match

The 284-byte owner now compiles directly with stock IDO 7.1. This removes
one `REWRITE_FUNCTION_HEX`, 18 `REWRITE_FUNCTION_RELOC_TARGET` directives,
and the unused `pad0` local. The work record contains only values used by the
loader. Its byte-sized tag key reproduces the retail low-byte counter load;
the input halfwords retain their actual widths. Existing call signatures
remain unchanged.

The adjacent tag and flag are one eight-byte C state record, scoped to the
function. Their actual addresses remain `0x8AF2BF18` and `0x8AF2BF1C`.
Function-local ownership lets the stock compiler share the address load.
`datamig_bss.ld` places its 16-byte aligned input BSS footprint there through
the existing fixed-address NOLOAD mechanism with four-byte subalignment.
Only eight bytes are state; the remaining bytes are compiler alignment.
There are no fabricated members or explicit padding fields.

The fragment header specifies relocation offset `0x2A590` and RAM size
`0x3A710`. `Memmap_RelocateFragment` clears that whole range after processing
relocations. This includes both state fields, supplying their initial zero
values. The original loaded relocation bytes remain intact; they are not
claimed to be zero initializers. Normal fragment boundaries do not move.

Unchanged and candidate source each reproduce their complete module with
and without 20 leading blank lines. Other allocated sections and existing
function/object extents match. The only raw text difference is the flag
store's legitimate offset 4 within the new record; its three relocation
endpoints describe the same actual addresses. Independent GNU links of both
positive control and candidate reproduce all 284 retail bytes. The normal
host syntax check and native `make -j1 COMPARE=1 RUN_CC_CHECK=1` pass, producing
retail ROM MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`.

All existing function/storage extents, legacy addresses and fragment
boundaries are preserved. The two old zero-sized tag/flag labels become
`NOTYPE` aliases at the same addresses; the new local C symbol owns the
state. No compiler/flag changes, instruction rewriting, forced registers,
unused locals or coverage updates are involved.
