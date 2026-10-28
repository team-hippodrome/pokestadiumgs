#include "global.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_80087200;
extern s32 D_880068B8;

void func_882219B0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(void *);
extern s32 D_880068B4;
extern s16 D_8823474A;
extern void *D_88234830;
void func_882219D8(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = (*(s32 *)((u8 *)(D_88234830) + (0x130)));
    if ((*(s8 *)((u8 *)(D_88234830) + (0x12D))) == 1) {
        D_8823474A = (*(s16 *)((u8 *)(D_88234830) + (0x2C)));
    }
    Util_Free(D_88234830);
}

extern void func_88004990(u8, u8);
void func_88221A34(s32 (*arg0)()) {
    func_88004990(*(*(u8 **)((u8 *)(D_88234830) + (0))), 0);
    D_880068B8 = 1;
    (*(s32 *)((u8 *)(D_88234830) + (0x130))) = 0;
    arg0();
}

extern void func_8821C2F4(void);
extern void func_8821B714(s32, s32);
extern void func_8800225C(void *, s16, s16);
extern u8 D_88006880[];

void func_88221A8C(s32 arg0, s32 arg1) {
    func_8821C2F4();
    func_8821B714(arg0, arg1);
    func_8800225C(D_88006880, 0, 0);
    func_88004990(**(u8 **)D_88234830, 0);
    D_880068B8 = 1;
}

extern void func_8821B438(void);
extern void func_8821B758(u8);
extern void func_8821B980(u16, s32);
extern void func_8821C0B0(void);
extern s32 D_88234768;

void func_88221AF0(void) {
    func_8821C2F4();
    if ((*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 1) && (*(s16 *)((u8 *)(D_88234830) + (0x2C)) == 7)) {
        func_8821B438();
    } else if ((*(s8 *)((u8 *)(D_88234830) + (0x12C)) == 0) && (*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 3)) {
        func_8821B758(*(u8 *)((u8 *)(D_88234830) + (0x2D)));
        func_8821B980(0x40, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
    } else if ((*(s8 *)((u8 *)(D_88234830) + (0x12C)) == 3) && (*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 5)) {
        func_8821B980(0x400, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
    } else if ((*(s8 *)((u8 *)(D_88234830) + (0x12C)) == 3) && (*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 6)) {
        if (*(s16 *)((u8 *)(D_88234830) + (0x2C)) == 0) {
            func_8821B980(0x80, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
        } else {
            D_88234768 = *(s16 *)((u8 *)(D_88234830) + (0x2C));
            func_8821B980(0x100, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
        }
    }
    func_8821C0B0();
    func_8800225C(D_88006880, 0, 0);
    func_88004990(**(u8 **)D_88234830, 0);
    D_880068B8 = 1;
}

extern void func_800226C0(s32);
extern void func_882206A0(s32);
extern s32 func_88229CB0();
extern s32 func_8822A534();
extern s32 func_88227224();
extern s32 func_88223120();
extern void func_88002720(void *, u16, void *);
extern void func_88004990(u8, u8);
extern void func_88221A34(s32 (*arg0)());
extern void func_88221A8C(s32 arg0, s32 arg1);
extern void func_88221AF0(void);
extern s32 D_80087200;
extern s32 D_880068B8;
extern void * D_88234830;
void func_88221C54(void) {
    if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
        func_800226C0(0x5C);
        if (*(s8 *)(((u8 *)D_88234830) + 0x12D) == 1) {
            switch (*(u16 *)(((u8 *)D_88234830) + 0x2C)) {
            case 0:
                func_88221A8C(12, 1);
                break;
            case 1:
                func_88221A8C(8, 1);
                break;
            case 2:
                func_88221A8C(9, 1);
                break;
            case 3:
                func_88221A34(func_88229CB0);
                break;
            case 4:
                func_88221A34(func_8822A534);
                break;
            case 5:
                func_88004990(**(u8 **)D_88234830, 0);
                D_880068B8 = 1;
                *(s32 *)(((u8 *)D_88234830) + 0x130) = 0;
                func_882206A0(0);
                break;
            case 6:
                func_88221A34(func_88227224);
                break;
            case 7:
                func_88221AF0();
                break;
            }
        } else {
            switch (*(s8 *)(((u8 *)D_88234830) + 0x12C)) {
            case 0:
                switch (*(s8 *)(((u8 *)D_88234830) + 0x12D)) {
                case 2:
                    func_88221A8C(14, 1);
                    break;
                case 3:
                    func_88221AF0();
                    break;
                case 4:
                    func_88221A8C(10, 1);
                    break;
                }
                break;
            case 1:
                if (*(s8 *)(((u8 *)D_88234830) + 0x12D) == 2 && *(s16 *)(((u8 *)D_88234830) + 0x2C) == 2) {
                    func_88221A34(func_88223120);
                } else {
                    func_88221A8C(*(s8 *)(((u8 *)D_88234830) + 0x12D) - 1, *(s16 *)(((u8 *)D_88234830) + 0x2C));
                }
                break;
            case 3:
                switch (*(s8 *)(((u8 *)D_88234830) + 0x12D)) {
                case 2:
                    func_88221A8C(11, 1);
                    break;
                case 3:
                    func_88221A8C(15, 1);
                    break;
                case 4:
                    func_88221A8C(13, *(s16 *)(((u8 *)D_88234830) + 0x2C));
                    break;
                case 5:
                    if (*(s16 *)(((u8 *)D_88234830) + 0x2C) == 0) {
                        func_88221A8C(16, 1);
                    } else {
                        func_88221AF0();
                    }
                    break;
                case 6:
                    func_88221AF0();
                    break;
                }
                break;
            }
        }
    } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
        func_800226C0(0x48);
        func_88004990(**(u8 **)D_88234830, 0);
        D_880068B8 = 1;
    } else {
        func_88002720(((u8 *)D_88234830) + 0x2C, *(u16 *)(((u8 *)D_88234830) + 0x10), ((u8 *)D_88234830) + 0x30);
    }
}

extern void func_889033FC(void *, void *);
void func_88221F28(void) {
    func_889033FC(*(void **)D_88234830, (u8 *)D_88234830 + 4);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_194C30/func_88221F54.s")
#endif
