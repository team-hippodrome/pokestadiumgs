# Fragment 81 roster-selection initialization

## func_84302148

This three-argument, void owner saves the supplied roster pointer in
`D_84302C80` and initializes only when that stored pointer is non-null.
Compiled `RecordSelection_InitializePartyRecords` supplies a six-entry working
roster, the state's unsigned byte at offset 137, and a word selecting whether
to use the indexed rule table. Its declaration agrees with the new pointer,
unsigned-byte and signed-word formals.
//@src/fragments/20/fragment20_128B10.c

The owner clears the existing 24-byte `D_84302C88` state, seeds the existing
random generator from `osGetCount`, and stores `func_8006A424() - 1` in its
selector byte. The count, two halfwords and used-type mask are cleared. The
second argument is retained in `unk_02`; `unk_03` receives 128 plus either
zero or `101 - selector * 12`, according to the third argument. Existing
`func_843020F0` supplies the mode word. Unknown byte meanings remain unnamed.
//@src/fragments/81/fragment81_code.c
//@src/6AA80.c

For indexed rules, the selected eight-byte record is at
`(selector & 3) * 8 + unk_02` in `D_843028DC`. Otherwise unsigned random
modulo six selects a record in `D_84302A44`. The existing `Fragment81RulePrefix`
contains the type-map and effect-list pointers consumed by the same file's
species/move filters. The original data contains those pointer pairs; its
storage remains in assembly. The owner finishes by passing the incoming
roster to existing assembly `func_84301DEC`.

The accepted C uses the newly stored global for its null guard and a flat
rule-record index. A two-dimensional table spelling leaves fifteen register
words different; the flat index reproduces the original address arithmetic.
All existing C and data remain unchanged. No new storage, padding, fake,
compiler change or instruction rewrite is introduced.

Fresh validation on master `17a1769b910626a72f3c1056414c5ee827556d20` plus
this patch forces the changed translation unit through the normal
syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/81/fragment81_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Complete retail comparison and whitespace
checks pass. All 75 instruction words (300 bytes), the 32-byte frame, and the
following twelve zero bytes of natural section alignment match. The C symbol
is 300 bytes; the extracted assembly span is 312 bytes. Independent raw-retail
comparison covers the complete span at ROM `0x41F898..0x41F9D0`.
