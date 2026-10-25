# Fragment 67 and 79 x/z transforms

## func_82902FE0 and func_8410B8FC

These owners have identical 120-byte assembly bodies, 30 words each, with
no stack frame. Both take output and input float pointers plus a signed
16-bit angle. Converting the angle to unsigned and shifting by four selects
the existing sine table `D_80087E50` and cosine table `D_80088E50`. Retail
table samples at indices 0 and 1024 are respectively 0/1 and 1/0. The two
stores are:

```c
output[0] = input[0] * cosine + input[2] * sine;
output[2] = -input[0] * sine + input[2] * cosine;
```

The implementations retain the original source and table reads between
stores; the y component is untouched. No data storage or table ownership
changes. The address-based function names remain unchanged.

Original `func_82903058` supplies a stack output vector, `D_82919CF0` as
input, and angle -16384, then consumes output offsets 0 and 8. Original
`func_8410CD3C` supplies a stack output vector, the input vector at parent
offset 1588, and a signed angle; it consumes the same output components.
Compiled `BattleAnim_ModelDispatch_127` uses the second owner identically.
Its existing declaration and input-pointer cast now agree with the float
view, preserving its instruction bytes and pointer ABI.
//@src/fragments/67/fragment67_33FAE0.c
//@src/fragments/79/fragment79_37A6E0.c

The first array-expression recipe emitted 124 bytes with 16 differing
original-span words. Reordering the sums recovered 120 bytes with four
operand/register differences. The conventional product order shown above
reproduces all 30 words in each copy. No forced registers, padding, new
qualifiers, FAKE constructs, or instruction rewriting are introduced.

Fresh validation on master `618ab42eae3e532644d5866221859323d8485879`
plus this patch uses the normal syntax-enabled Makefile:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/67/fragment67_33FAE0.c -W src/fragments/79/fragment79_37A6E0.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

Full US linking produces `build/pokestadiumgs-us.z64: OK`, MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. Retail comparison and whitespace
checks pass. Independent instruction comparisons cover ROM
`0x33FAE0..0x33FB58` and `0x37B18C..0x37B204`, 240 bytes total. Previously
matched C, section layout, and CI remain unchanged.
