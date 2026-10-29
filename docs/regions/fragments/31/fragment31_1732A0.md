# Fragment 31 record exchange

## func_88200320

This two-pointer, void owner exchanges the complete 118-byte records at its
arguments. The original assembly first copies the first record into a stack
object, copies the second over the first, then copies the saved object over
the second. Its unaligned word accesses and final halfword establish the
record's two-byte alignment and exact extent. An opaque aggregate of 59
halfwords expresses that extent without assigning meanings to its fields.
Three ordinary struct assignments reproduce IDO's copy loops; the source
contains no manual unroll.
//@src/fragments/31/fragment31_1732A0.c

Compiled `func_8820137C` returns records at a 118-byte stride. Original
`func_88203744` allocates capacity times 118 bytes for the four storage lists
and a separate 118-byte fallback. Compiled `func_88201A74` resolves two
records and passes them to this owner when both list objects are occupied.
//@src/fragments/31/fragment31_174460.c
//@src/fragments/31/fragment31_1768F0.c

Compiled `LabPC_DrawRecordTransferEntries` invokes the exchange for motion
modes 16 and 17 at the animation midpoint and marks both storage lists
changed. Mode 15 exchanges the motion's pointers through a different helper.
The original `func_88201B74` also invokes this owner for its occupied-record
path. These consumers establish the record-exchange operation; the unknown
function name and record fields remain unchanged.
//@src/fragments/31/fragment31_1A5E10.c
//@src/fragments/31/fragment31_174460.c

The first C candidate matches all 78 instruction words (312 bytes), including
the 120-byte frame containing the real 118-byte saved record. Existing C,
callers, data and interfaces remain unchanged. No fake, extra array capacity,
padding, instruction rewrite or layout change is introduced.

Fresh validation on master `1847b5a7ead4451d67489df1197959aef7dc6f6b` plus
this patch forces the changed translation unit through the normal
syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_1732A0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The full link prints `build/pokestadiumgs-us.z64: OK`; ROM MD5 is
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Complete retail comparison and whitespace
checks pass. Independent original-assembly and raw-retail comparisons verify
all 312 bytes at ROM `0x1735A0..0x1736D8`.
