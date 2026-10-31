#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_87F01DA0 begin */
extern u8 *D_87F11980;

typedef union {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
} Rgba;

void func_87F00944(void *arg0, Rgba c1, Rgba c2, s32 arg3);


s32 func_87F01DA0(s32 arg0, void *arg1) {
    s32 flag;
    Rgba c1;
    Rgba c2;
    // FAKE: unused locals that widen the frame to 0x30 so c1, c2 and the callee's
    // color home slots land at 0x24/0x28; without them the object differs in its
    // stack offsets (score 90).
    Rgba t1;
    Rgba t2;

    flag = 0;
    switch (arg0) {
    case 0:
        (*(u16 *)((u8 *)arg1 + 2)) &= 0xFFFD;
        break;
    case 1:
        switch (*(u32 *)((u8 *)arg1 + 0x20)) {
        case 0:
            if (*(s32 *)(D_87F11980 + 0xC) == 1) {
                flag = 1;
            }
            break;
        case 1:
            if (*(s32 *)(D_87F11980 + 0xC) == 2) {
                flag = 1;
            }
            break;
        case 2:
            if (*(s32 *)(D_87F11980 + 0xC) == 3) {
                flag = 1;
            }
            break;
        }
        c1.rgba = 0xFFFFEBAA;
        c2.rgba = 0xAA5A00FF;
        func_87F00944(arg1, c1, c2, flag);
        break;
    }
    return 1;
}
/* mkdraft:func_87F01DA0 end */

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
