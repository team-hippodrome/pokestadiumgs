#include "global.h"


#ifdef VERSION_US
extern s16 D_82919D2E;
extern s16 D_82919D30;
s32 func_829057F0(s32 arg0, u8 *arg1) {
    if (arg0 == 2) {
        arg1[0x18] = 0xFF;
        arg1[0x19] = 0xFF;
        arg1[0x1A] = 0xFF;
        *(s16 *)(arg1 + 0x1C) = D_82919D2E + 0x2000;
        *(s16 *)(arg1 + 0x1E) = D_82919D30 + 0x2000;
    }
    return 0;
}

typedef struct {
    u8 r, g, b, a;
} Fragment67Color;

extern s32 D_82919D24;
extern u8 D_82919DD0[];
extern u8 D_829120C0[];
extern void *D_80094908;
extern void func_80037120(void *, void *, s16 *, s16 *, s16 *);

// D_829120C0 holds 12-byte rows of three 4-byte colors, indexed by D_82919D24, and
// D_82919DD0 holds three 4-byte tints (func_82906170 resets them to white). This writes the
// row's first color into arg1, scaled by the first tint unless that tint is white.
s32 func_82905830(s32 arg0, u8 *arg1) {
    s16 pad0;
    s16 pad1;
    s16 pad2;
    s16 sp30;
    s16 sp2E;
    s16 sp2C;

    if (arg0 == 0) {
        arg1[0x18] = D_829120C0[D_82919D24 * 12];
        arg1[0x19] = D_829120C0[D_82919D24 * 12 + 1];
        arg1[0x1A] = D_829120C0[D_82919D24 * 12 + 2];
    }
    if (arg0 == 2) {
        if ((((Fragment67Color *)D_82919DD0)->r & ((Fragment67Color *)D_82919DD0)->g &
             ((Fragment67Color *)D_82919DD0)->b) == 0xFF) {
            arg1[0x18] = D_829120C0[D_82919D24 * 12];
            arg1[0x19] = D_829120C0[D_82919D24 * 12 + 1];
            arg1[0x1A] = D_829120C0[D_82919D24 * 12 + 2];
        } else {
            arg1[0x18] = (((Fragment67Color *)D_82919DD0)->r * D_829120C0[D_82919D24 * 12]) / 255;
            arg1[0x19] = (((Fragment67Color *)D_82919DD0)->g * D_829120C0[D_82919D24 * 12 + 1]) / 255;
            arg1[0x1A] = (((Fragment67Color *)D_82919DD0)->b * D_829120C0[D_82919D24 * 12 + 2]) / 255;
        }
        func_80037120((u8 *)D_80094908 + 0xB4, (u8 *)D_80094908 + 0xA8, &sp30, &sp2E, &sp2C);
        *(s16 *)(arg1 + 0x1C) = sp2E + 0x2000;
        *(s16 *)(arg1 + 0x1E) = sp2C - 0x2000;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_3422F0/func_82905A88.s")

// func_82905830's color step for the row's third color and the third tint.
s32 func_82905CE4(s32 arg0, u8 *arg1) {
    if (arg0 == 0) {
        arg1[0x18] = D_829120C0[D_82919D24 * 12 + 8];
        arg1[0x19] = D_829120C0[D_82919D24 * 12 + 9];
        arg1[0x1A] = D_829120C0[D_82919D24 * 12 + 10];
    }
    if (arg0 == 2) {
        if ((((Fragment67Color *)(D_82919DD0 + 8))->r & ((Fragment67Color *)(D_82919DD0 + 8))->g &
             ((Fragment67Color *)(D_82919DD0 + 8))->b) == 0xFF) {
            arg1[0x18] = D_829120C0[D_82919D24 * 12 + 8];
            arg1[0x19] = D_829120C0[D_82919D24 * 12 + 9];
            arg1[0x1A] = D_829120C0[D_82919D24 * 12 + 10];
        } else {
            arg1[0x18] = (((Fragment67Color *)(D_82919DD0 + 8))->r * D_829120C0[D_82919D24 * 12 + 8]) / 255;
            arg1[0x19] = (((Fragment67Color *)(D_82919DD0 + 8))->g * D_829120C0[D_82919D24 * 12 + 9]) / 255;
            arg1[0x1A] = (((Fragment67Color *)(D_82919DD0 + 8))->b * D_829120C0[D_82919D24 * 12 + 10]) / 255;
        }
    }
    return 0;
}

s32 func_82905EE4(s32 arg0, u8 *arg1) {
    arg1[0x18] = 100;
    arg1[0x19] = 100;
    arg1[0x1A] = 100;
    return 0;
}

extern s16 D_829199F8;
s32 func_82905F00(s32 arg0, u8 *arg1) { if (arg0 == 0) *(s16 *)(arg1 + 0x1A) = 0; if (arg0 == 2) { if (D_829199F8 >= 7) *(s16 *)(arg1 + 0x1A) = 1; else *(s16 *)(arg1 + 0x1A) = 0; } return 0; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_3422F0/func_82905F40.s")

/* mkdraft:func_829060BC begin */
extern s32 D_82919DC8;
extern u8 D_800D0510[];
extern void func_8000766C(u8 *, s32, s32, s32, s32);
extern void GfxImage_FillCurrent(u8 *, s32);
extern s32 func_82905F40(s32);

void func_829060BC(void) {
    s32 value = D_82919DC8;
    if (value == 0) {
        func_8000766C(D_800D0510, 0, 0, 0x140, 0xF0);
    } else if (value == -1) {
        GfxImage_FillCurrent(D_800D0510, 1);
    } else if ((u32)value < 0x10000) {
        s32 converted = func_82905F40(value & 0xFFFF);
        GfxImage_FillCurrent(D_800D0510, converted & 0xFFFF);
    } else {
        GfxImage_FillCurrent(D_800D0510, 1);
    }
}
/* mkdraft:func_829060BC end */

extern f32 D_80128C54[];

void func_82906164(f32 arg0) {
    D_80128C54[1] = arg0;
}

extern u8 D_80128C5C[];

void func_82906170(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    u8 *ptr = D_80128C5C;
    u8 *color = D_82919DD0;

    ptr[0] = arg0;
    ptr[1] = arg1;
    ptr[2] = arg2;
    // FAKE: the mask and the chained store below together select $t7 for 0xFF;
    // diff score 50 without either one.
    ptr[3] = arg3 & 0xFFFF;
    color[2] = 0xFF;
    color[1] = 0xFF;
    color[0] = 0xFF;
    color[6] = 0xFF;
    color[5] = 0xFF;
    color[10] = (color[4] = 0xFF);
    color[9] = 0xFF;
    color[8] = 0xFF;
}

extern s32 D_82919DC0;
extern void *D_82919DC4;
extern s32 D_82919DC8;
extern u8 D_82912228[];
extern void func_82906170(u8, u8, u8, u8);
extern void *process_geo_layout(void *, void *);

void func_829061CC(s32 arg0, void *arg1, s32 (*arg2)(s32, s32)) {
    D_82919D24 = arg0;
    func_82906170(255, 255, 255, 0);
    func_82906164(1.0f);
    D_82919DC0 = arg2(0, 0);
    D_82919DC4 = process_geo_layout(arg1, D_82912228);
    D_82919DC8 = arg2(1, 0);
}

extern s32 D_82919DC0;
extern s32 D_82919DC8;
void func_82906264(s32 (*arg0)(s32, s32)) {
    D_82919DC0 = arg0(0, 0);
    D_82919DC8 = arg0(1, 0);
}
#endif
