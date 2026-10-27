#include "global.h"


#ifdef VERSION_US
s32 func_800668D0(s32 a) {
    s32 r = (u32)0xFFFF;

    switch (a) {
    case 1:
        r = 0;
        break;
    case 2:
        r = 1;
        break;
    case 4:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    }

    return r;
}

extern s32 D_8009DEDC[];
s32 func_80066924(s32 arg0) { s32 result = 0; if (arg0 > 0 && arg0 < 5) { result = D_8009DEDC[arg0]; } return result; }

extern u16 D_8009DEF0[];

s32 func_8006694C(u16 arg0, u16 arg1) {
    s32 i;
    s32 result = 0;

    for (i = 0; i < 4; i++) {
        // FAKE: the mask swaps the bnel operands; diff score 10 without it.
        if (arg0 == (func_800668D0(D_8009DEF0[i]) & 0xFFFFFFFF)) {
            result = D_8009DEF0[i];
            break;
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/674D0/func_800669C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/674D0/func_80066D24.s")
#endif
