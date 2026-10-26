# fragment64_32DC40 matching notes

## func_87F0B1A4 and func_87F0B24C

These two 168-byte owners configure parallel three-float transitions. Each
compares the requested target components with the supplied source vector.
If all three compare equal, it returns without writing state or calling the
helper. Otherwise it captures the source, clears the elapsed word, stores
the supplied duration, sets its flag together with the caller's mask, writes
the target, and calls existing `func_87F0B18C`.

| State field | func_87F0B1A4 | func_87F0B24C |
|---|---|---|
| Source vector byte offset | 0 | 12 |
| Target vector byte offset | 36 | 48 |
| Elapsed word byte offset | 108 | 116 |
| Duration word byte offset | 112 | 120 |
| Flag in word at byte offset 132 | 1 | 0x10 |

Original `func_87F0B4AC` tests those flags, advances and caps the elapsed
words against their durations, and consumes the corresponding source and
target components. This supports the transition roles without assigning
unverified meanings to the two vectors. Existing `func_87F0B18C` clears masks
`0x80` and `0x40` in byte 104; its implementation remains unchanged.
//@src/fragments/64/fragment64_32DC40.c

Compiled `func_87E07040` supplies a three-float source, three float targets,
a duration and mask `0x2000` to the first owner. Compiled `func_87E0D6BC`
likewise supplies source components and a target displaced by 120 on the
second component, duration 30 and mask `0x3000`. Compiled `func_87E07194`
calls the second owner with a source at record offset 84, three zero targets,
duration 15 and mask zero. These calls confirm two pointer arguments, three
floats and two words; no result is consumed. Existing caller bytes and
address-based function names remain unchanged.
//@src/fragments/63/fragment63_308D70.c
//@src/fragments/63/fragment63_310270.c

The first candidate for `func_87F0B1A4` emits 168 bytes with eight instruction
differences in the final stores. Writing the flags before the target vector,
and its second component before its first, recovers all 42 original words.
Applying that same ordinary store sequence to the sibling matches its first
candidate. Each retains the 24-byte frame, float comparisons, source reloads,
flag operations and helper call. There are no new fakes, padding, qualifiers,
instruction rewrites, data-layout changes or allocated storage.

Fresh validation uses master `95cdb02f8fce513576abea79130055af3f20e46e`
plus this batch. The unchanged baseline passes its own complete build.

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_32DC40.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forces recompilation and the complete US
ROM link. Exact acceptance is `build/pokestadiumgs-us.z64: OK`, with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail byte comparison and whitespace
checks pass. Independent comparisons cover all 336 original bytes at ROM
`0x32DE14..0x32DEBC` and `0x32DEBC..0x32DF64`. Previously matched C remains
unchanged.
