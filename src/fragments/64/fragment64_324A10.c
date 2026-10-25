#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_324A10/func_87F01DA0.s")

extern u8 *D_87F11980;
void func_87F01E8C(s32 arg0, u8 *arg1) {
    s32 flag;
    u32 mode;

    switch (arg0) {
        case 0:
            *(u16 *)(arg1 + 2) &= 0xFFFD;
            break;
        case 1:
            mode = *(u32 *)(arg1 + 0x20);
            switch (mode) {
                case 0:
                    flag = 1;
                    break;
                case 1:
                    flag = 2;
                    break;
                case 2:
                    flag = 3;
                    break;
            }
            if (flag == *(u32 *)(D_87F11980 + 0xC)) {
                *(u16 *)(arg1 + 2) |= 2;
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_324A10/func_87F01F34.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_324A10/func_87F02104.s")

extern u8 *D_87F11980; extern void func_87F08FA0(u8); extern void func_800503A4(void *); void func_87F022F0(void) { func_87F08FA0(D_87F11980[0x28]); func_800503A4(*(void **)(D_87F11980 + 4)); }

extern u8 *D_87F11980; void func_87F02328(void) { D_87F11980[0x28] = 0; }
#pragma C_FUNCTION_PADDING(8)
#endif
