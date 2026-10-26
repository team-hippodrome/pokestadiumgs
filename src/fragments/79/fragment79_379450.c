#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_379450/func_84109BC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_379450/func_84109E18.s")

typedef struct unk_D_841833E0 {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u8 r;
    /* 0x09 */ u8 g;
    /* 0x0A */ u8 b;
    /* 0x0B */ u8 unk_0B;
} unk_D_841833E0; // size = 0xC

typedef struct unk_D_84190218 {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u8 r;
    /* 0x09 */ u8 g;
    /* 0x0A */ u8 b;
} unk_D_84190218;

extern s32 D_84190208;
extern unk_D_841833E0 D_841833E0[];
extern unk_D_84190218 D_84190218;

// Geo layout callback (command 0x08 in D_84183548): copies the RGB color of
// table entry D_84190208 (set by func_8410A524) into node bytes 0x18-0x1A.
// With arg0 == 2 the color is scaled by D_84190218's color unless that is white.
s32 func_8410A074(s32 arg0, u8 *node) {
    if (arg0 == 0) {
        node[0x18] = D_841833E0[D_84190208].r;
        node[0x19] = D_841833E0[D_84190208].g;
        node[0x1A] = D_841833E0[D_84190208].b;
    }
    if (arg0 == 2) {
        if ((D_84190218.r & D_84190218.g & D_84190218.b) == 0xFF) {
            node[0x18] = D_841833E0[D_84190208].r;
            node[0x19] = D_841833E0[D_84190208].g;
            node[0x1A] = D_841833E0[D_84190208].b;
        } else {
            node[0x18] = (D_841833E0[D_84190208].r * D_84190218.r) / 255;
            node[0x19] = (D_841833E0[D_84190208].g * D_84190218.g) / 255;
            node[0x1A] = (D_841833E0[D_84190208].b * D_84190218.b) / 255;
        }
    }
    return 0;
}

s32 func_8410A274(u8 *arg0, s32 arg1) {
    return 0;
}

extern u8 *D_80094910;
s32 func_8410A284(s32 arg0, s32 arg1) {
    u8 *ptr = D_80094910;
    if (arg0 == 2) {
        *(s16 *)(ptr + 0x18) = 3;
    }
    return 0;
}

s32 func_8410A2A8(s32 arg0, s32 arg1) {
    u8 *ptr = D_80094910;
    if (arg0 == 2) {
        *(s16 *)(ptr + 0x18) = 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_379450/func_8410A2C8.s")

extern s32 D_84190204;
extern u8 D_800D0510[];
extern void GfxImage_ClearDepthRectangle(u8 *, s32, s32, s32, s32);
extern void GfxImage_FillCurrent(u8 *, s32);
extern s32 func_8410A2C8(s32);
void func_8410A444(void) {
    s32 value = D_84190204;
    if (value == 0) {
        GfxImage_ClearDepthRectangle(D_800D0510, 0, 0, 0x140, 0xF0);
    } else if (value == -1) {
        GfxImage_FillCurrent(D_800D0510, 1);
    } else if ((u32)value < 0x10000) {
        s32 converted = func_8410A2C8(value & 0xFFFF);
        GfxImage_FillCurrent(D_800D0510, converted & 0xFFFF);
    } else {
        GfxImage_FillCurrent(D_800D0510, 1);
    }
}

extern f32 D_80128C54[];
void func_8410A4EC(f32 arg0) {
    D_80128C54[1] = arg0;
}

extern f32 D_80128C54[];
void Audio_SetChannelGroupCounts(u8 arg0, u8 arg1, u8 arg2, u8 arg3) { volatile u8 *state; state = (volatile u8 *)D_80128C54; state += 8; state[0] = arg0; state[1] = arg1; state[2] = arg2; state[3] = arg3; }
extern s32 D_84190200;
extern s32 D_84190208;
extern s32 D_8419020C;
extern u8 D_84183548[];
extern void Audio_SetChannelGroupCounts(u8, u8, u8, u8);
extern void func_8410A4EC(f32);
extern s32 process_geo_layout(s32, u8 *);
void func_8410A524(s32 arg0, s32 arg1, s32 (*arg2)(s32, s32)) {
    D_84190208 = arg0;
    Audio_SetChannelGroupCounts(0xFF, 0xFF, 0xFF, 0);
    func_8410A4EC(1.0f);
    D_84190200 = arg2(0, 0);
    D_8419020C = process_geo_layout(arg1, D_84183548);
    D_84190204 = arg2(1, 0);
}

extern s32 D_84190210;
extern u8 D_84183610[];
void func_8410A5BC(s32 arg0, s32 arg1, s32 arg2) {
    D_84190210 = process_geo_layout(arg1, D_84183610);
}
#endif
