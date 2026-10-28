# fragment34_1C5AA0 matching notes

## func_88509538

This one-pointer, void update decrements the record's signed halfword at
offset 8, reloads that narrowed value, and computes `(count * 255) / 40.0f`.
The integer multiplication happens before conversion to float. It subtracts
the result from 255, adds 0.5 when the scaled result is below 255 and -0.5
otherwise, truncates to an integer, and stores the signed halfword at offset
14. It preserves the original floating-point comparison and operation order.

When the decremented count is nonpositive, it obtains the record index from
`(arg0 - D_88523050) / 80` and calls existing `func_88509418(index, 2)`.
That helper's actual index formal is unsigned byte-sized; the call preserves
the original narrowing. Its compiled state-2 branch stores 30 in the timer,
clears the offset-10 halfword, and sets the offset-14 halfword to 255.

Compiled `func_88509418` initializes state 1 with count 40 and the offset-14
halfword zero. Compiled `func_8850998C` walks two 80-byte ball records and
dispatches state 1 to this owner. `func_885093F0` clears the two state words,
and the existing record views and trail functions describe the same 80-byte
storage. These producers and consumers establish the timer, record stride,
state transition, and one-pointer interface. The value's broader rendering
role remains unnamed here; existing address-based names remain.
//@src/fragments/34/fragment34_1C5AA0.c

The first candidate reproduces all 45 instruction words (180 bytes), including
the 24-byte frame. Current regional notes and the private ledger contained no
earlier attempt for this owner. The existing helper, callers, record types,
and storage remain unchanged. No new fakes, padding, qualifiers, instruction
rewriting, layout, or CI changes are required.

Fresh validation uses master `33de8ee58f9393c8692e713bb812b9b6b7c80c3c`
plus this patch. The updated unchanged baseline passed its own complete US
build and retail comparison after normal extraction. Final validation forces
the changed source through the default syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/34/fragment34_1C5AA0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent original-assembly and retail-span comparisons verify
all 180 bytes at ROM `0x1C6B48..0x1C6BFC`.


## func_8850A2F4: sequence timer and rounded halfwords

This 252-byte owner (63 instructions, 24-byte frame) decrements the existing
sequence record's signed halfword `unk_18`. It updates `unk_14` from
`32 - (count * -96) / 30.0f` and `unk_16` from
`128 - (count * 64) / 30.0f`. Each expression adds 0.5 when its quotient
is below the corresponding base, or -0.5 otherwise, before truncation and
halfword storage. The integer products precede conversion to float. The
original narrowing, comparison and arithmetic order are preserved.

When the decremented count is nonpositive, it calls `func_8850A0EC(2)`.
That existing helper's state-1 branch seeds the timer with 30 and sets flag
`0x10`; its state-2 branch resets the timer to 10. State 0 initializes the
two output halfwords to 128 and 64. Original `func_8850AEA8` dispatches to
this owner with no arguments and ignores the result. These producer and
consumer operations establish the existing sequence fields and void interface;
the halfwords' broader rendering roles retain their unknown names.
//@src/fragments/34/fragment34_1C5AA0.c

The first recipe reproduces every original instruction. It reuses the
existing `unk_D_88523030` view and the rounding idiom already present in
`func_8850A710` and `func_88509538`. No type, helper, caller, global storage,
layout, or previously matched body changes are needed; no new fakes,
padding, qualifiers or instruction rewrites are introduced.

Fresh validation uses master `69fd21b88c54746b6ac65ea2babec60d980cc216`
plus this patch. The unchanged baseline passed its complete US build and
retail comparison. Failed trials in fragments 49 and 25 were restored and
forced through normal compilation before the accepted build.

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/34/fragment34_1C5AA0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Default host syntax checks, forced source compilation and the complete link
pass with `build/pokestadiumgs-us.z64: OK`. The full ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`; retail and whitespace checks pass.
Independent original-word and raw retail comparisons verify all 252 bytes
at `0x1C7904..0x1C7A00`.

## 2026-10-28 — `func_8850A988`, `func_8850AAA8`, `func_8850ABCC` matched

All three use the file's rounded float lerp
`(s16)((C - (t * K) / 10.0f) + (C > (t * K) / 10.0f ? 0.5f : -0.5f))` for
`unk_04` and `unk_06`. `unk_06` uses `C = 24.0f` with `K = 0`: the zero
product survives as `mtc1 $zero` + `cvt`.
- `func_8850ABCC`: `unk_18--` first, then lerp with -20/480. At
  `unk_18 <= 0`: state 0x11 and `func_885084EC(0, 8)`, `(1, 8)`.
- `func_8850A988` / `func_8850AAA8`: `s16 v = D_88523030.unk_18--;`, clamped
  to 0 when negative, lerp with 450/470 or -500/-950. At `unk_18 < -5`:
  state 0xD or 0xF and `func_88509F68(0)` or `(1)`. The post-decrement
  initializer produces retail's redundant `sll`/`sra` re-sign-extension;
  a separate `unk_18 = v - 1` statement drops it.
