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

## `func_87F057EC`: decimal text with a minimum width

The 324-byte sibling retains the same signed decimal digit collection and
reversal. After the sign is appended to the reverse buffer, it appends
spaces until the requested minimum width is reached. Reversal therefore
places those spaces before the sign and digits. It writes a terminating
zero and has the existing void, three-argument interface. It does not
truncate values longer than the requested width.

`func_87F05C50` and `func_87F05C98` pass their value and width arguments
along with a local output buffer, then send that text to `func_87F05B88`
and `func_87F05954`, respectively. The latter consumes signed characters
until zero while drawing text. The formatter has no callees or external
data dependencies. The signed-minimum negation overflow and unchecked
width beyond the scratch capacity are preserved and labeled `//!bug`.
//@src/fragments/64/fragment64_326ED0.c

The C scratch array has 16 signed bytes. Four consumed word locals
reproduce the observed scratch start at stack offset 24 and 56-byte frame.
The natural digit, space-fill and reverse-copy loops emit all original
instructions, including IDO's four-byte reverse-copy unrolling. No fake,
padding, manual unrolling or instruction rewriting is introduced.

Fresh validation on master
`5c5290f4d96406b9e7be7c9c9f6f6f58cfc1b207` plus this replacement used the
same commands above, forcing `src/fragments/64/fragment64_326ED0.c` through
the normal syntax-enabled Makefile and linking the complete US ROM. Fresh
extraction and the unchanged baseline passed first. The replacement passed
`build/pokestadiumgs-us.z64: OK`, MD5 `1561c75d11cedf356a8ddb1a4a5f9d5d`,
full retail byte comparison and whitespace checks. All 81 instruction words
at ROM `0x32845C..0x3285A0` independently match original assembly and retail.
