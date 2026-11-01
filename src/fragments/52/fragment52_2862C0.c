#include "global.h"


#ifdef VERSION_US
void func_86407E00(u8 *arg0, f32 arg1, f32 arg2) {
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(f32 *)(arg0 + 0x00) = arg1;
    *(f32 *)(arg0 + 0x08) = arg1;
    *(f32 *)(arg0 + 0x10) = arg1;
    *(f32 *)(arg0 + 0x04) = arg2;
    *(f32 *)(arg0 + 0x0C) = arg2;
    *(f32 *)(arg0 + 0x14) = arg2;
}

void func_86407E2C(u8 *arg0, f32 arg1, f32 arg2, s32 arg3) {
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = arg3;
    *(f32 *)(arg0 + 0x10) = arg1;
    *(f32 *)(arg0 + 0x08) = *(f32 *)(arg0 + 0x00);
    *(f32 *)(arg0 + 0x14) = arg2;
    *(f32 *)(arg0 + 0x0C) = *(f32 *)(arg0 + 0x04);
}

/* mkdraft:func_86407E58 begin */
extern u32 func_87F00930(void);
extern f32 D_80088E50[];
extern f32 D_86409C60;

// Eases one menu tile from its start position (0x8, 0xC) toward its end position
// (0x10, 0x14) and writes the rounded result to (0x0, 0x4). 0x18 counts elapsed
// frames and 0x1C the total: 0x18 * 180 / 0x1C degrees, scaled by D_86409C60
// (65535 / 360), gives the 16-bit angle whose cosine in D_80088E50 weights the
// end position against the start. The elapsed-frame counter advances only when
// func_87F00930 reports that rendering advances the frame, the same test
// func_861086AC uses before GeoRender_AdvanceFrameCounter. func_86407E2C sets
// both positions and the total; func_864082A8 calls func_86408048, which eases
// each of the five tiles.


void func_86407E58(u8 *arg0) {
    f32 angle;
    f32 blend;
    f32 start_weight;
    f32 end_weight;
    s32 cos_index;

    if (*(s32 *)(arg0 + 0x18) >= *(s32 *)(arg0 + 0x1C)) {
        *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x1C);
    }
    if (*(s32 *)(arg0 + 0x1C) == 0) {
        start_weight = 1.0f;
        end_weight = 0.0f;
    } else {
        angle = (((f32) *(s32 *)(arg0 + 0x18) * 180.0f) / (f32) *(s32 *)(arg0 + 0x1C)) * D_86409C60;
        if (angle >= 0.0f) {
            cos_index = (s32) (angle + 0.5f);
        } else {
            cos_index = (s32) (angle - 0.5f);
        }
        end_weight = (1.0f - D_80088E50[(u16) cos_index >> 4]) * 0.5f;
        start_weight = 1.0f - end_weight;
    }
    blend = (*(f32 *)(arg0 + 0x10) * end_weight) + (*(f32 *)(arg0 + 0x08) * start_weight);
    if (blend >= 0.0f) {
        *(f32 *)(arg0 + 0x00) = (f32) (s32) (blend + 0.5f);
    } else {
        *(f32 *)(arg0 + 0x00) = (f32) (s32) (blend - 0.5f);
    }
    blend = (*(f32 *)(arg0 + 0x14) * end_weight) + (*(f32 *)(arg0 + 0x0C) * start_weight);
    if (blend >= 0.0f) {
        *(f32 *)(arg0 + 0x04) = (f32) (s32) (blend + 0.5f);
    } else {
        *(f32 *)(arg0 + 0x04) = (f32) (s32) (blend - 0.5f);
    }
    if (func_87F00930() == 0) {
        *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) + 1;
    }
}
/* mkdraft:func_86407E58 end */

extern u8 *D_86416C00;
extern void func_86407E58(u8 *);
void func_86408048(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    func_86407E58(temp + 0x0C);
    func_86407E58(temp + 0x2C);
    func_86407E58(temp + 0x4C);
    func_86407E58(temp + 0x6C);
    func_86407E58(temp + 0x8C);
}

void func_864080A0(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    s32 i;

    *(s32 *)(temp + 8) = 0;
    *(s32 *)(temp + 0) = -1;
    *(s32 *)(temp + 4) = -1;
    for (i = 0; i < 4; i++) {
        func_86407E00(temp + 0xC + i * 0x20, 114.0f, (f32)(240 + i * 64));
    }
    func_86407E00(temp + 0x8C, 320.0f, 86.0f);
}

void func_86408148(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_86407E2C(temp + 0xC + i * 0x20, 110.0f, (f32)(79 + i * 15), 40);
    }
    func_86407E2C(temp + 0x8C, 156.0f, 86.0f, 40);
}

/* mkdraft:func_864081E8 begin */
void func_864081E8(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    u8 *ptr;
    s32 i;

    for (i = 0x40, ptr = temp + 0xC; i != 0x110; i += 0x34, ptr += 0x20) {
        func_86407E2C(ptr, (f32)i, 198.0f, 0x14);
    }
}
/* mkdraft:func_864081E8 end */

void func_8640826C(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    func_86407E2C(temp + 0x8C, -70.0f, 86.0f, 0x14);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_2862C0/func_864082A8.s")
#endif
