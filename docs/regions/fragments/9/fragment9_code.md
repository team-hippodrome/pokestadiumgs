# Fragment 9 state initialization

## `func_8FB00170`

The 80-byte owner in `src/fragments/9/fragment9_code.c` initializes the
first four halfwords of its destination to 230, 150, 300, and 210. It copies
the unsigned halfword at offset `0x0C` of the descriptor referenced by
`arg1 + 0x44` into destination offset `0x20`, then clears destination
halfwords `0x08` and `0x0A`.

It returns `func_8FB000D0(arg0, arg1)`. That helper chooses between two
12-byte copy sources based on the descriptor's first halfword, writes the
selected bytes at destination offset `0x0E`, and returns one; unsupported
descriptor values return zero. `func_8FB02608` passes its parent object
and the destination at parent offset `0x158C`, then propagates the result.
These original instructions establish two pointer arguments and a signed
word return interface for the initializer.

The implementation retains address-based names and the surrounding source's
byte-offset access style. These descriptions follow from inspected retail
assembly and existing caller code; no runtime observations are claimed.

## Validation

Tested for `VERSION=us` against master
`6b6a1b50dd7fb9bb9285a19263f9dc461513ea27` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/9/fragment9_code.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced source recompilation and linked
the complete ROM. It reported `build/pokestadiumgs-us.z64: OK`, with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The byte comparison and whitespace
check passed. All 80 instruction bytes and the 24-byte frame agree with
retail without padding, forced registers, or instruction rewriting.
