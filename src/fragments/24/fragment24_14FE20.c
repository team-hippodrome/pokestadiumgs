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

extern s32 D_82B08524;
extern s32 D_82B08528;

// Packs D_82B08524 + 1 (only for 0-4; other non-negative values give 1) into the
// upper halfword and the low halfword of D_82B08528 into the lower one; returns 0
// while D_82B08524 is negative.
u32 func_82B00B78(void) {
    u32 result = 0;
    u32 high;

    if (D_82B08524 >= 0) {
        high = 0x10000;
        switch (D_82B08524) {
            case 0:
                break;
            case 1:
                high = 0x20000;
                break;
            case 2:
                high = 0x30000;
                break;
            case 3:
                high = 0x40000;
                break;
            case 4:
                high = 0x50000;
                break;
        }
        result = (D_82B08528 & 0xFFFF) | high;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B00BE0.s")
#endif
