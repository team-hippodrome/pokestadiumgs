#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B9390/func_88308080.s")

extern u16 **D_88601898;
extern s32 func_886000F0(u16);
u8 func_883083C8(u8 *arg0) {
    s32 at_first;
    s32 count;
    s32 i;

    if (*(s16 *)(arg0 + 8) == 0) {
        at_first = 1;
    } else {
        at_first = 0;
    }
    if (at_first) {
        return 0;
    }
    count = 1;
    i = *(s16 *)(arg0 + 8) - 1;
    while (TRUE) {
        if (func_886000F0(*D_88601898[i])) {
            return count;
        }
        if (i == 0) {
            return 0;
        }
        count++;
        i--;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B9390/func_88308464.s")
#endif
