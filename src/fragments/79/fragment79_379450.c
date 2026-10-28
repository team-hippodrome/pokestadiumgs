#include "global.h"


#ifdef VERSION_US
typedef struct unk_D_841833E0 {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u8 r;
    /* 0x09 */ u8 g;
    /* 0x0A */ u8 b;
    /* 0x0B */ u8 unk_0B;
} unk_D_841833E0; // size = 0xC

typedef struct unk_D_84190218_tint {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
    /* 0x03 */ u8 a;
} unk_D_84190218_tint; // size = 0x4

typedef struct unk_D_84190218 {
    /* 0x00 */ unk_D_84190218_tint tints[2];
    /* 0x08 */ u8 r;
    /* 0x09 */ u8 g;
    /* 0x0A */ u8 b;
} unk_D_84190218;

extern s32 D_84190208;
extern unk_D_841833E0 D_841833E0[];
extern unk_D_84190218 D_84190218;
extern void *D_80094908;
extern void func_80037120(void *, void *, s16 *, s16 *, s16 *);

// Same code as func_82905830 in fragment67_3422F0.c, on this file's tables: copies the
// first color (bytes 0-2) of the 12-byte D_841833E0 row D_84190208 into node bytes
// 0x18-0x1A, scaled by the first tint in D_84190218 unless that tint is white, and
// offsets the angles from func_80037120 into node halfwords 0x1C/0x1E.
//@src/fragments/67/fragment67_3422F0.c
s32 func_84109BC0(s32 arg0, u8 *arg1) {
    s16 pad0, pad1, pad2; // FAKE: unused locals that set the frame size; diff score 27 without them.
    s16 sp30;
    s16 sp2E;
    s16 sp2C;

    if (arg0 == 0) {
        arg1[0x18] = D_841833E0[D_84190208].unk_00[0];
        arg1[0x19] = D_841833E0[D_84190208].unk_00[1];
        arg1[0x1A] = D_841833E0[D_84190208].unk_00[2];
    }
    if (arg0 == 2) {
        // FAKE: the white test reads the tint through pointer arithmetic on tints; diff score 20 without it.
        if ((D_84190218.tints->r & D_84190218.tints->g & D_84190218.tints->b) == 0xFF) {
            arg1[0x18] = D_841833E0[D_84190208].unk_00[0];
            arg1[0x19] = D_841833E0[D_84190208].unk_00[1];
            arg1[0x1A] = D_841833E0[D_84190208].unk_00[2];
        } else {
            arg1[0x18] = (D_84190218.tints[0].r * D_841833E0[D_84190208].unk_00[0]) / 255;
            arg1[0x19] = (D_84190218.tints[0].g * D_841833E0[D_84190208].unk_00[1]) / 255;
            arg1[0x1A] = (D_84190218.tints[0].b * D_841833E0[D_84190208].unk_00[2]) / 255;
        }
        func_80037120((u8 *)D_80094908 + 0xB4, (u8 *)D_80094908 + 0xA8, &sp30, &sp2E, &sp2C);
        *(s16 *)(arg1 + 0x1C) = sp2E + 0x2000;
        *(s16 *)(arg1 + 0x1E) = sp2C - 0x2000;
    }
    return 0;
}

// Same code as func_84109BC0 for the second color (row bytes 4-6) and the second tint;
// the halfword at 0x1C is -0x2000 minus the angle and the one at 0x1E adds 24576.
s32 func_84109E18(s32 arg0, u8 *arg1) {
    s16 pad0, pad1, pad2; // FAKE: unused locals that set the frame size; diff score 27 without them.
    s16 sp30;
    s16 sp2E;
    s16 sp2C;

    if (arg0 == 0) {
        arg1[0x18] = D_841833E0[D_84190208].unk_00[4];
        arg1[0x19] = D_841833E0[D_84190208].unk_00[5];
        arg1[0x1A] = D_841833E0[D_84190208].unk_00[6];
    }
    if (arg0 == 2) {
        // FAKE: the white test reads the tint through pointer arithmetic on tints; diff score 20 without it.
        if (((D_84190218.tints + 1)->r & (D_84190218.tints + 1)->g & (D_84190218.tints + 1)->b) == 0xFF) {
            arg1[0x18] = D_841833E0[D_84190208].unk_00[4];
            arg1[0x19] = D_841833E0[D_84190208].unk_00[5];
            arg1[0x1A] = D_841833E0[D_84190208].unk_00[6];
        } else {
            arg1[0x18] = (D_84190218.tints[1].r * D_841833E0[D_84190208].unk_00[4]) / 255;
            arg1[0x19] = (D_84190218.tints[1].g * D_841833E0[D_84190208].unk_00[5]) / 255;
            arg1[0x1A] = (D_84190218.tints[1].b * D_841833E0[D_84190208].unk_00[6]) / 255;
        }
        func_80037120((u8 *)D_80094908 + 0xB4, (u8 *)D_80094908 + 0xA8, &sp30, &sp2E, &sp2C);
        *(s16 *)(arg1 + 0x1C) = -0x2000 - sp2E;
        *(s16 *)(arg1 + 0x1E) = sp2C + 24576;
    }
    return 0;
}

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
