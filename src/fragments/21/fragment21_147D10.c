#include "global.h"


#ifdef VERSION_US
extern void _bzero(void *, s32);
extern s16 D_82509680;
extern s16 D_82509686;
void func_82507D90(void) {
    _bzero(&D_82509680, 0x12C8);
    D_82509686 = 1;
}

extern u16 D_82509684;
// Each byte holds four two-bit cells in the 160-by-120 transition mask.
void CellularTransition_SeedCells(s16 *arg0) {
    s32 i;
    s32 column;
    s32 cell;
    u8 *cells;
    cells = (u8 *)arg0 + 8;
    _bzero(cells, 4800);
    for (i = 0; i < 10; i++) {
        column = (s32)(guRandom() % 160U);
        cell = (s32)(guRandom() % 120U) * 160 + column;
        cells[cell >> 2] = (cells[cell >> 2] & ((3 << ((cell & 3) * 2)) ^ 0xFF)) | (1 << ((cell & 3) * 2));
    }
    if ((((u16 *)arg0)[2] & 1) != 0) {
        arg0[0] = 4;
        arg0[1] = 0;
    } else {
        arg0[0] = 2;
        arg0[1] = 0;
    }
}

s32 CellularTransition_FindEmptyNeighbors(s32 *arg0, u8 *arg1, s32 arg2, s16 *arg3) {
    s32 count = 0;
    s32 cell;
    s32 i;
    for (i = 0; i < 8; i++) {
        cell = (arg3[i] + arg2) % 19200;
        if (cell < 0) cell += 19200;
        if ((u8)((arg1[cell >> 2] >> ((cell & 3) * 2)) & 3) == 0) {
            count++;
            arg0[i] = 1;
        } else {
            arg0[i] = 0;
        }
    }
    return count;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_147D10/func_82508014.s")

extern void func_82508014(s16 *);
void func_82508268(void) {
    switch (D_82509680) {                           /* irregular */
    case 1:
        CellularTransition_SeedCells(&D_82509680);
        return;
    case 2:
    case 4:
        func_82508014(&D_82509680);
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_147D10/func_825082C8.s")

extern Gfx *D_800D0510;
extern void GfxImage_FillRectangle(Gfx **, s32, s32, s32, s32, u16);
extern void func_825082C8(s16 *);
void CellularTransition_Draw(void) {
    switch (D_82509680) {
    case 1:
        if (D_82509684 & 1) {
            GfxImage_FillRectangle(&D_800D0510, 0, 0, 640, 480, 1);
        } else {
            func_825082C8(&D_82509680);
        }
        break;
    case 2:
    case 4:
        func_825082C8(&D_82509680);
        break;
    case 3:
        GfxImage_FillRectangle(&D_800D0510, 0, 0, 640, 480, 1);
        break;
    }
}

s32 func_825085E4(void) {
    struct {
        s16 unk_00;
        s16 unk_02;
        u16 unk_04;
    } *state = (void *)&D_82509680;
    s32 result = 0;

    if (state->unk_00 == 0) {
        state->unk_00 = 1;
        state->unk_04 &= 0xFFFE;
        result = 1;
    }
    return result;
}

/* mkdraft:func_82508620 begin */
// func_82508620: if the transition state word is 3, set it to 1, set the
// red-fill flag in D_82509684, and report the transition happened.
extern s16 D_82509680;
extern u16 D_82509684;

// NON_MATCHING: The state and red-fill stores still use different page-base allocation.
#ifdef NON_MATCHING
s32 func_82508620(void) {
    struct {
        s16 unk_00;
        s16 unk_02;
        u16 unk_04;
    } *state = (void *)&D_82509680;
    s32 result = 0;

    if (state->unk_00 == 3) {
        state->unk_00 = 1;
        D_82509684 |= 1;
        result = 1;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_147D10/func_82508620.s")
#endif
/* mkdraft:func_82508620 end */


s32 func_8250865C(void) {
    return D_82509680 == 3;
}


s32 func_82508670(void) {
    return D_82509680 == 0;
}
#endif
