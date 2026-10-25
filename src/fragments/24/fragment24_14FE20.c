#include "global.h"


#ifdef VERSION_US
s32 func_82B00020(u8 *arg0) {
    s32 result;

    if (arg0[1] != 0) {
        if (arg0[0] == 0) {
            if (arg0[2] < 6) {
                result = 5;
            } else {
                result = 0;
            }
        } else {
            result = 3;
        }
    } else if (arg0[0] == 2) {
        result = 4;
    } else if (arg0[4] != 0) {
        result = 1;
    } else {
        result = 2;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B00098.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B002B8.s")

extern void BgStage_DrawFrame();
extern void func_82B080D0();
extern void func_80008648();
void func_82B004FC(s32 arg0) {
    BgStage_DrawFrame();
    func_82B080D0();
    func_80008648();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B0052C.s")

typedef struct Target82BState Target82BState;
struct Target82BState { u8 pad_0000[0x1A60]; s16 value; };
extern Target82BState D_82B107C0;
extern s16 D_82B12220;
s32 func_82B0069C(void) {
    s32 result = 1;
    volatile Target82BState *state = &D_82B107C0;
    D_82B12220 = state->value + 1;
    if (state->value < 2) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B006D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B00914.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B00B78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B00BE0.s")
#endif
