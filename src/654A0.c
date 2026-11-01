#include "global.h"


#ifdef VERSION_US
extern u8 D_8009DE50[]; u8 func_800648A0(u8 index) { return D_8009DE50[index]; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/654A0/func_800648B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/654A0/func_80064940.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/654A0/func_80064980.s")

s32 func_800649CC(void) { return 2; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/654A0/func_800649D4.s")

extern void _bzero(s32 *, s32);
extern s8 D_80128B50;
extern u8 D_80128B58;

void func_800649E0(void) {
    D_80128B50 = 0;
    _bzero(&D_80128B58, 0x80);
}

extern u8 D_80128B5A;
u8 func_80064980(u8);
void func_80064A10(u8 arg0, u8 arg1) {
    (&D_80128B58)[(u8)D_80128B50 * 4] = arg0;
    (&D_80128B58)[(u8)D_80128B50 * 4 + 1] = arg1;
    (&D_80128B5A)[(u8)D_80128B50 * 4] = func_80064980(arg1);
    D_80128B50 = (u8)D_80128B50 + 1;
}

extern u8 D_80128BD8;
extern u8 D_80128B58;
u8 func_80064A7C(u8 arg0)
{
 do { register u8 *ptr = &D_80128B58; loop: if ((*ptr) != 0) { if (arg0 == (*ptr)) { return ptr[3]; } ptr += 4; if (ptr != (&D_80128BD8)) { goto loop; } } } while (0);
  return 0;
}

typedef struct unk_func_80064AC8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
} unk_func_80064AC8; // size = 4

void func_80064AC8(void) {
    s32 last_index = 31;
    s32 index;
    unk_func_80064AC8 temporary;

    while (((unk_func_80064AC8 *)&D_80128B58)[last_index].unk_00 == 0 && last_index != 0) {
        last_index--;
    }
    for (; last_index > 0; last_index--) {
        for (index = 0; index < last_index; index++) {
            if (((unk_func_80064AC8 *)&D_80128B58)[last_index].unk_02 <
                ((unk_func_80064AC8 *)&D_80128B58)[index].unk_02) {
                temporary = ((unk_func_80064AC8 *)&D_80128B58)[index];
                ((unk_func_80064AC8 *)&D_80128B58)[index] = ((unk_func_80064AC8 *)&D_80128B58)[last_index];
                ((unk_func_80064AC8 *)&D_80128B58)[last_index] = temporary;
            }
        }
    }
}

void func_80064B84(u8 arg0) {
    u8 sum = 0;
    s32 i = 0;
    for (; i != 32; i++) {
        (&D_80128B58)[i * 4 + 3] = sum;
        if (arg0) {
            sum += func_80064940((&D_80128B58)[i * 4 + 1]);
        } else {
            sum += func_800648B8((&D_80128B58)[i * 4 + 1]);
        }
    }
}

/* Preserve the five alignment NOPs at the end of the original assembly owner. */
#pragma C_FUNCTION_PADDING(20)
#endif
