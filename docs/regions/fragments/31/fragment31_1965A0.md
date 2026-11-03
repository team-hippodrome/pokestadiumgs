# Region notes — fragment31_1965A0

## 2026-11-03 — `func_88223418`: rewrite-free selection update

Stock IDO 7.1 emits all 316 retail bytes without the two
`REWRITE_FUNCTION_WORD` directives. The unused byte local is removed.
The selected signed byte and cleared flag occupy a two-field local record;
both fields participate in the update. The loop counter is `u8` and uses a
normal increment. Comparing the index before the current slot reproduces
the retail branch operand order.

`F31SelectionTail` describes the actual final four bytes of the menu state:
a signed halfword current slot and two signed-byte choices. The allocation
and initialization in `func_882241B8` establish the 56-byte allocation,
current slot at offset `0x34`, and choices at offsets `0x36` and `0x37`.
This is a view of existing heap storage, with no new allocation or globals.
//@src/fragments/31/fragment31_1965A0.c

The handler inserts or clears the selected choice, clears a duplicate from
the other slot, then advances the current slot or marks both slots filled.
The byte counter visits indices 0 and 1, just as the previous explicitly
masked word counter did. The controller helper retains its actual
`void(s32)` interface from `src/4AAD0.c`.

The previous near-match used a word counter with an explicit byte mask and
missed one branch operand order. Merely changing that declaration while
keeping the redundant mask creates a different induction-variable shape.
The ordinary byte increment and index-first comparison together produce the
retail code. A private XOR predicate also corrected the branch, but incurred
an extra UGEN temporary and shifted later registers; it was not adopted.

Validation starts from merged master
`b0831f4431c2fb3fb77aad3301d2639b78ed0d66`. Unchanged and final source each
reproduce identical complete module bytes, allocated section layouts,
function/object extents and semantic relocations, normally and with 20
leading blank lines. The normal host syntax check passes. Native
`make -j1 COMPARE=1 RUN_CC_CHECK=1` produces retail ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`; the linked owner matches all 316 bytes.
Existing function/object extents, legacy addresses and fragment boundaries
remain unchanged. Compiler, linker, ABI, tooling and coverage are unchanged.
