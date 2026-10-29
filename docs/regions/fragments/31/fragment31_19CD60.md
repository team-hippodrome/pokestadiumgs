# Fragment 31 menu-input callback

## `func_88229B44` — selection and flag updates

The 324-byte owner is registered by `func_88229CB0` through
`func_88004804`. Its initializer allocates a 104-byte record, supplies
four entries, and places the menu at record offset 32. The callback reads
`D_80087200->buttonsPressed`. Mask `0x4000` plays sound 72, calls the slot
helper with the byte reached through record offset 0, and sets `D_880068B8`.
//@src/fragments/31/fragment31_19CD60.c

Mask `0x8000` calls the no-argument state snapshot `func_8821C2F4`, then
reads the signed selection at menu offset 40. Selections 0, 1 and 2 play
sound 92, store the selection in `D_8823476C`, and set mask `0x200` through
`func_8821B980`. Selection 3 plays sound 311 and clears that mask. The
callback then runs `func_8821C0B0`, resets the existing view with
`func_8800225C(D_88006880, 0, 0)`, calls the slot helper, and sets the same
status word. The actual assembly of `func_8821C0B0` returns its signed-word
status; this callback ignores that result. Broader menu meanings remain
unresolved.
//@src/fragments/31/fragment31_189760.c

With neither mask set, `func_88002720` receives the signed selection,
count at menu offset 12, and descriptor at offset 44. The helper's actual
assembly reads a word flag and a byte-array pointer from that descriptor.
`func_88004990` has its actual void result and two byte arguments; the
snapshot has its actual zero-argument interface. All existing C remains
byte-identical. Declaring the consumed menu pointer before the button word
places its spill at stack offset 28, reproducing all 81 original words and
the 32-byte frame.
//@src/fragments/29/fragment29_168330.c
//@src/fragments/29/fragment29_167940.c

Fresh validation uses master `dbf90bbce549156e2c31d2341eb3be643fd52c14`
plus this patch. The unchanged baseline passed first. The normal
syntax-enabled Makefile forcibly recompiles the changed source and links
the complete US ROM:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/31/fragment31_19CD60.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The result is `build/pokestadiumgs-us.z64: OK`, full ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`, and a successful complete retail byte
comparison. Independent original-word and raw-retail comparisons cover all
324 bytes at `0x19CDC4..0x19CF08`. No new fake, padding, storage, instruction
rewrite, layout or CI change is introduced.
