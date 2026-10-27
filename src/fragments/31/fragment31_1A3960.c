#include "global.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_80087200;
extern s32 D_880068B8;

void func_882306E0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void func_88213BE4(s32, s32);
extern s32 D_882346F4;
extern u32 D_882349A0;
void func_88001900(void);
extern s32 D_880068B4;
void Util_Free(s32 arg0);
void func_88230708(void) {
    if ((*(s32 *)((u8 *)(D_882349A0) + (0xE4))) != 0) {
        func_88001900();
    } else {
        func_88213BE4(0x12, 0);
    }
    D_880068B4 = 1;
    D_882346F4 = 0;
    Util_Free((s32) D_882349A0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1A3960/func_88230770.s")

extern void func_8821D930(s32);
void func_88230878(void) {
    func_8821D930(D_882349A0 + 4);
}

extern u8 D_8800ED50[];
void func_882308A0(u8 arg0) {
    extern s32 D_880068B4;
    extern s32 D_882346F4;
    extern void func_88230770(void);
    extern void func_88230878(void);
    extern void func_882306E0(void);
    extern void func_88230708(void);
    s32 idx;

    D_882349A0 = (s32)Util_Malloc(232);
    if (func_882304B0(D_882349A0 + 4, arg0) == 0) {
        Util_Free(D_882349A0);
        return;
    }
    idx = func_88004804(
        D_882349A0 + 4,
        2,
        320,
        240,
        4,
        1,
        220,
        220,
        180,
        func_88230770,
        func_88230878,
        func_882306E0,
        func_88230708,
        0,
        0
    );
    *(void **)D_882349A0 = (void *)((idx * 76) + D_8800ED50);
    D_880068B4 = 0;
    D_882346F4 = 1;
}


void func_882309B0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void func_88214330();
extern u32 D_882349B0;
void func_88001900(void);
void Util_Free(s32 arg0);
void func_882309D8(void) {
    if ((*(s32 *)((u8 *)(D_882349B0) + (0xE8))) != 0) {
        func_88001900();
        D_880068B4 = 1;
    } else {
        func_88214330();
    }
    D_882346F4 = 0;
    Util_Free((s32) D_882349B0);
}

extern void func_88004990(u8, s32);
void func_88230A38(void) {
    func_88004990(*(*(u8 **)((u8 *)(D_882349B0) + (0))), 0);
    func_88004990(*(*(u8 **)((u8 *)(D_882349B0) + (4))), 0);
    D_880068B8 = 1;
}

extern void func_800226C0(s32);
extern void func_88214394(void);
extern s32 func_882026A4(s32, s32);
extern void func_88002720(void *, u16, void *);
extern s32 D_882345F4;
void func_88230A88(void) {
    u8 *menu = (u8 *)D_882349B0 + 0x24;
    u32 buttons = *(u16 *)(D_80087200 + 8);

    if (buttons & 0x4000) {
        func_800226C0(0x48);
        *(s32 *)((u8 *)D_882349B0 + 0xE8) = 1;
        func_88230A38();
    } else if (buttons & 0x8000) {
        func_88214394();
        func_882026A4(D_882345F4, *(s16 *)(menu + 0x28) + 2);
        func_88230A38();
    } else {
        func_88002720(menu + 0x28, *(u16 *)(menu + 0xC), menu + 0x2C);
    }
}

extern void func_889033A0(s32);
void func_88230B2C(void) { func_889033A0((D_882349B0 + 236)); func_8821D930((D_882349B0 + 8)); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1A3960/func_88230B64.s")

// Viewed as s16 words: [4] and [5] are the count and limit fields of the F29Callbacks
// transition state that func_88005B60 initializes.
//@src/fragments/29/fragment29_16BBA0.c
extern s16 D_8800EF50[];
// Writes half the transition length to *half and maps the remaining count onto a
// rounded alpha ramp, 255 at the start through 0 at the midpoint to -255 at the end.
void func_88230D80(s16 *half, s16 *alpha) {
    f32 value;
    f32 rounding;

    *half = D_8800EF50[5] >> 1;
    value = 255.0f * (D_8800EF50[4] - *half) / *half;
    if (value > 0.0f) {
        rounding = 0.5f;
    } else {
        rounding = -0.5f;
    }
    *alpha = rounding + value;
    if (*alpha >= 256) {
        *alpha = 255;
    } else if (*alpha < -255) {
        *alpha = -255;
    }
}

extern Gfx *D_800D0510;
extern s16 D_8800EF58;
extern u8 D_88233B20[];
void func_88230E38(void) {
    s16 half;
    s16 alpha;
    s32 level;

    func_88230D80(&half, &alpha);
    if (half >= D_8800EF58) {
        alpha = -alpha;
    }
    level = (255 - alpha) >> 1;
    gSPDisplayList(D_800D0510++, D_88233B20);
    gDPSetPrimColor(D_800D0510++, 0, level, 0, 0, 0, 255);
}
#endif
