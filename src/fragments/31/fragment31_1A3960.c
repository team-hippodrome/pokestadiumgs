#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
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

extern void func_800226C0(s32);
extern s32 func_8004C54C(s32 index,s32 value);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern s32 func_80063754(s32 arg0);
extern void func_88002720(void *, u16, void *);
extern void func_88004990(u8, s32);
extern void func_88A017B4(u8, s16);
void func_88230770(void) {
    u8 *list;
    s32 pressed;

    pressed = D_80087200->buttonsPressed;
    list = (u8 *)D_882349A0 + 0x20;
    if (pressed & B_BUTTON) {
        func_800226C0(72);
        *(s32 *)((u8 *)D_882349A0 + 0xE4) = 1;
        func_88004990(**(u8 **)D_882349A0, 0);
        D_880068B8 = 1;
        return;
    }
    if (pressed & A_BUTTON) {
        func_800226C0(93);
        func_88A017B4(*((u8 *)D_882349A0 + 0xE3), *(s16 *)(list + 0x28));
        if (func_80063754(*((u8 *)D_882349A0 + 0xE3)) != 0) {
            func_8004C54C(26, func_8004C874(35, *(s16 *)(list + 0x28) + 18));
        }
        func_88004990(**(u8 **)D_882349A0, 0);
        D_880068B8 = 1;
        return;
    }
    func_88002720(list + 0x28, *(u16 *)(list + 0xC), list + 0x2C);
}


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
    u32 buttons = D_80087200->buttonsPressed;

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

extern void *func_800635E0(u8);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern u8 *func_88002AA8(u8 *, s32, u8 **, u16, s32, s16, s16, s16, s16, s16, s16, s32, s16, void *);
extern void func_880048D4(s32, s32, s16, s32, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32, s32);
extern u8 D_88006020[];
extern u8 D_8800EE80[];
extern u8 D_8800EECC[];
extern void D_88000E4C(void);
extern u8 *D_88234620;
extern void Util_Free(s32 arg0);
extern s32 func_8004C54C(s32 index,s32 value);
extern void func_882309B0(void);
extern void func_882309D8(void);
extern void func_88230A88(void);
extern void func_88230B2C(void);
extern s32 D_880068B4;
extern s32 D_882345F4;
extern u32 D_882349B0;
void func_88230B64(void) {
    s16 x;

    D_882349B0 = (u32)Util_Malloc(0x224);
    if (func_882304B0(D_882349B0 + 8, ((u8 *)D_882345F4)[9]) == 0) {
        Util_Free(D_882349B0);
        return;
    }
    func_8004C54C(24, (s32)func_800635E0(*D_88234620));
    *(void **)(D_882349B0 + 0x120) = func_8004C8A0((u8 *)D_882349B0 + 0x124, 256, 35, 23);
    func_88002AA8((u8 *)D_882349B0 + 0xEC, 0, (u8 **)(D_882349B0 + 0x120), 1, 8, 1, 6, 15, 18, 13, 16, 0, 0,
                  D_88006020);
    func_880048D4(D_882349B0 + 0xEC, 0, 112, 208, 0, 1, 220, 220, 180, (s32 *)func_88230A88, (s32 *)func_88230B2C,
                  (s32 *)func_882309B0, (s32 *)func_882309D8, 0, 0, 4);
    **(u8 ***)&D_882349B0 = D_8800EE80;
    x = *(s16 *)(*(u8 **)D_882349B0 + 0xC) + *(u16 *)(*(u8 **)D_882349B0 + 0x10) + 5;
    func_880048D4(D_882349B0 + 8, 2, x,
                  208, 0, 1, 220, 220, 180, (s32 *)D_88000E4C, (s32 *)D_88000E4C, (s32 *)D_88000E4C, (s32 *)D_88000E4C, 0, 0, 5);
    *(u8 **)(D_882349B0 + 4) = D_8800EECC;
    D_880068B4 = 0;
}

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
