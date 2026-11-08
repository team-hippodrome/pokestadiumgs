#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern s32 func_88203FB4(void);
extern s32 func_8004C594(s32, s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_88903C50(void *, s16, s16, s32, u8, u8, u8, u8, u8,
                         s32 *, s32 *, void (*)(void), void (*)(void));
extern void func_88903B00(void);
extern void D_88000E4C(void);
extern s32 D_880068B4;
extern s32 D_880068B8;
extern s32 D_88234660;

void func_88220AD0(s16 arg0, s16 arg1) {
    u8 var_v0[512];

    func_8004C594(4, func_88203FB4());
    func_88903C50(func_8004C8A0(var_v0, 512, 31, 19), arg0, arg1, 4,
                 220, 220, 180, 2, 0, &D_880068B4, &D_880068B8,
                 func_88903B00, D_88000E4C);
    D_88234660 = 0;
}

extern void func_88004990(u8, u8);
extern u8 **D_88234800;
extern s32 D_880068B8;
void func_88220B80(void) {
    func_88004990(**D_88234800, 0);
    D_880068B8 = 1;
}

extern void func_8000612C(void);
void func_88220BB8(void) {
    func_8000612C();
    D_880068B8 = 0;
}

extern u8 **D_88234800;
extern s32 D_882345F4;
extern u8 *D_88234620;
extern u8 D_88234630[];
extern u16 D_8800686A;
extern s8 D_8800686D[];
extern u8 D_88A01C3F[];
extern s32 D_88234660;
extern s32 *func_800635E0(u8 arg0);
extern s8 *HAL_Strcpy(s8 *arg0, s8 *arg1);
extern void func_80060D70(void *arg0, void *arg1);
extern void func_80062C30(void *arg0);
extern s32 func_8003514C(void);
extern void func_88202FA0(void *a0, u8 *a1);
extern s32 func_88204050(void);
extern void func_88221034(s16 arg0, s16 arg1, s32 arg2, s32 arg3);
extern void func_887009A0(void);
extern void _bcopy(void *, void *, s32);
void Util_Free(s32 arg0);


void func_88220BDC(void) {
    s32 src;
    s16 width;
    s16 height;
    s32 sprite;
    u8 **entry_list;

    switch (*(s32 *)((u8 *)D_88234800 + 0x7C)) {
    case 0:
        width = 380;
        height = 287;
        break;
    case 1:
        width = 320;
        height = 240;
        break;
    }

    sprite = func_800635E0(*(u8 *)D_88234620);
    func_88221034(width, height, (s32)((u8 *)D_882345F4 + 0x3C), sprite);

    HAL_Strcpy((s8 *)((u8 *)D_88234800 + 0x6A), D_8800686D);

    *(u16 *)((u8 *)D_88234800 + 0x76) = *(u16 *)&D_8800686A;
    *(u8 *)((u8 *)D_88234800 + 0x78) = *((u8 *)D_882345F4 + 8);
    *(u8 *)((u8 *)D_88234800 + 0x79) = *(u8 *)D_88234620;

    func_80060D70((u8 *)D_88234800 + 0x48, (u8 *)D_88234800 + 4);

    if (func_8003514C() != 0) {
        func_80062C30((u8 *)D_88234800 + 4);
    }

    func_88202FA0((void *)D_882345F4, D_88234620);

    switch (*(u8 *)(*(u8 **)*(u8 **)D_882345F4 + 8)) {
    case 0:
        *((u8 *)D_882345F4 + 0x27) = 0;
        src = (s32)(*(s8 *)((u8 *)D_882345F4 + 4) * 0x76 +
                    *(u8 **)(D_88234630 + 4));
        *(s32 *)(D_88234630 + 8) = 1;
        break;
    case 2:
        *((u8 *)D_882345F4 + 0x27) = func_88204050() + 1;
        D_88A01C3F[*((u8 *)D_882345F4 + 0x27)] = 1;
        D_88234660 = 1;
        src = (s32)(*((u8 *)D_882345F4 + 0x27) * 0x76 +
                    *(u8 **)(D_88234630 + 0x1C) - 0x76);
        *(s32 *)(D_88234630 + 0x20) = 1;
        break;
    }

    _bcopy((u8 *)D_88234800 + 4, (void *)src, 0x76);
    func_887009A0();
    Util_Free((s32)D_88234800);
}

extern void *Util_Malloc(s32);
extern void _bzero(void *, s32);
extern void func_88700364(u32, u8 *, u32);
extern s32 func_887002F4(void);
extern s32 func_8870032C(void);
extern void func_88700CE4(void);
extern void func_88701240(void);
extern void func_88220BDC(void);
extern u8 D_8800ED50[];
extern u8 func_88004804(s32, s32, s16, s16, s32, s32, u8, u8, u8,
                         s32 *, s32 *, s32 *, s32 *, u8, u8);
void func_88220E08(s32 arg0) {
    s32 index;
    s16 x;
    s16 y;

    D_88234800 = Util_Malloc(128);
    *(s32 *)((u8 *)D_88234800 + 124) = arg0;
    _bzero((u8 *)D_88234800 + 4, 118);
    func_88700364(arg0, (u8 *)D_88234800 + 4, (u32)func_88220B80);
    x = func_887002F4();
    y = func_8870032C();
    index = func_88004804(0, 3, x, y, 0, 1, 220, 220, 180,
        (s32 *)func_88700CE4, (s32 *)func_88701240,
        (s32 *)func_88220BB8, (s32 *)func_88220BDC, 0, 0);
    *D_88234800 = D_8800ED50 + index * 76;
    *(s16 *)(*D_88234800 + 16) = 385;
    *(s16 *)(*D_88234800 + 18) = 348;
    D_880068B4 = 0;
}

void func_88220F40(void) {
    D_880068B8 = 0;
}

extern void func_88220AD0(s16, s16);
extern s32 D_88234660;
extern u32 D_88234810;
void Input_SetRepeatController(s32 value);
void func_88001900(void);
extern s32 D_880068B4;
void Util_Free(s32 arg0);
void func_88220F4C(void) {
    if (D_88234660 != 0) {
        func_88220AD0((*(s16 *)((u8 *)(D_88234810) + (0x23C))), (*(s16 *)((u8 *)(D_88234810) + (0x23E))));
    } else {
        Input_SetRepeatController((s32)D_80087200);
        func_88001900();
        D_880068B4 = 1;
    }
    Util_Free((s32) D_88234810);
}

void func_88220FB8(void) {
    if (D_80087200->buttonsPressed & 0xC000) {
        func_88004990(**(u8 **)D_88234810, 0);
        D_880068B8 = 1;
    }
}

extern void func_889033A0(s32);
void func_8822100C(void) {
    func_889033A0((D_88234810 + 4));
}

extern u8 D_88006020[];
extern u8 D_8800ED50[];
void func_88221034(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    D_88234810 = Util_Malloc(576);
    *(s16 *)((u8 *)D_88234810 + 0x23C) = arg0;
    *(s16 *)((u8 *)D_88234810 + 0x23E) = arg1;
    func_8004C54C(23, arg2);
    func_8004C54C(24, arg3);
    *(s32 *)((u8 *)D_88234810 + 0x38) = func_8004C8A0(D_88234810 + 0x3C, 512, 31, 20);
    func_88002AA8(D_88234810 + 4, 0, D_88234810 + 0x38, 1, 8, 1, 6, 15, 18, 13, 16, 0, 0, D_88006020);
    *(s32 *)D_88234810 = func_88004804(D_88234810 + 4, 0, arg0, arg1, 4, 1, 219, 220, 180, &func_88220FB8,
                                       &func_8822100C, &func_88220F40, &func_88220F4C, 0, 0) * 76 +
                         D_8800ED50;
    D_880068B4 = 0;
}
#endif
