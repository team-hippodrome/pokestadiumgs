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
