# Fragment 64 decimal text formatting

## `func_87F056E0`

This 268-byte owner writes a signed word as decimal text through its first
pointer argument and returns the character count, excluding the terminating
zero. It collects signed remainder digits in reverse order, appends a minus
sign for negative inputs, reverses those bytes into the destination, and
writes the terminator. Zero takes the digit loop once. Negating the minimum
signed word overflows; the replacement preserves the retail negation and
labels that original bug.

`func_87F05BC8` and `func_87F05C0C` format into local buffers before passing
the text to the existing drawing helpers. `func_87F05CE0` uses the returned
length to subtract seven pixels per character from its draw coordinate;
original `func_87F05D34` also consumes the returned count. These callers
establish the existing two-argument, signed-word result interface.
//@src/fragments/64/fragment64_326ED0.c

The C scratch array has 16 signed bytes. Together with the three consumed
word locals it reproduces the observed buffer at stack offset 20 and the
48-byte frame. Signed-byte loads, signed division checks, digit order and
IDO's four-byte reverse-copy unrolling all match the inspected assembly.
No helper calls, manual unrolling or instruction rewriting are introduced.

Tested for `VERSION=us` on master
`84702c99be2004d63e48ba54c5cc71e535c42907` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/64/fragment64_326ED0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Fresh extraction and the unchanged baseline passed before editing. The
normal syntax-enabled Makefile forced recompilation and linked the complete
ROM, reporting `build/pokestadiumgs-us.z64: OK`, with MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Full retail byte comparison and whitespace
checks passed. Independent original-assembly/raw-ROM comparison verifies
all 67 instruction words at `0x328350..0x32845C`.
