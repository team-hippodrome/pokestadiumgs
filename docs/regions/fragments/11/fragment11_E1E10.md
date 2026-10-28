# Fragment 11 six-slot record clear

## `func_8160A94C`

The 72-byte owner clears the byte at parent offset `0x20` in each of six
records with a 3304-byte stride. The C loop compiles to the retail unrolled
stores and stride calculation, with no stack frame.

`func_8160A8DC` in `src/fragments/11/fragment11_E1E10.c` scans these same
bytes for the first zero and returns six when every slot is occupied.
`func_8160B8E0` copies an incoming record to the selected slot starting at
offset `0x20`; `func_8160B9A0` tests and clears its leading byte. This
establishes the zero value's empty-slot role without assigning a broader
meaning to the record payload.

`func_8160A994` clears all six slots before initializing other parent fields.
The caller `func_813034E8` in `src/fragments/14/fragment14_FAD40.c` invokes
the clear when its progress reaches 0.5, then calls `func_8160A928` with
index zero. These claims come from inspected C and retail assembly;
no runtime observations were used. The function name remains unresolved.

## Validation

Tested for `VERSION=us` against master
`34ac7eb42a85cd9aef72d67212bae69d9f864d63` plus this replacement:

```sh
source /workspace/toolchain/activate.sh
make -W src/fragments/11/fragment11_E1E10.c -W src/fragments/24/fragment24_150C10.c -j4 VERSION=us rom
cmp build/pokestadiumgs-us.z64 baseroms/us/baserom.z64
git diff --check
```

The normal syntax-enabled Makefile forced recompilation and linked the
complete US ROM. Fragment 24 was also recompiled after restoring its
unsuccessful candidate to assembly. The build reported
`build/pokestadiumgs-us.z64: OK`, with ROM MD5
`1561c75d11cedf356a8ddb1a4a5f9d5d`. The retail byte comparison and whitespace
check passed. All 72 instruction bytes match.

## 2026-10-29: `func_8160A438` requeue

requeue (0.84). This is the load counterpart of func_8160A384:
- `_bzero(buffer, 0x180); func_80055A74(arg1); func_80055A9C(buffer, arg2)`;
- `*(s16 *)(arg0 + 0x4D90) = func_800533A4(0x10, arg2)`, then `func_80053440(0x10, arg2, arg0 + 0x11)`;
- for each of six 0x3C records at `buffer + 0x10`: `func_80051830(arg0 + 0x20 + i*0xCE8, rec)`, call func_8004D878(entry + 0x80, 0, dst) when `entry[0x20] > 0`, and clear `entry + 0x78`;
- return `buffer[0x178]`.

Declaring `src, buffer, entry, end, dst` fixes the stack. Remaining: retail keeps arg0 in $s3 (`or s3,a0`) where ours spills it to the arg home. The permuter reaches 10 only with a fake `end = buffer + 0x178;` re-assigned inside the loop. Next: other loop shapes (index loop with pointer temporaries), and arg0 used as the entry cursor after copying it.
