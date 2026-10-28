#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_882211D0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(void *);
extern void func_88001900();
extern s32 D_880068B4;
extern s16 D_88234748;
extern void *D_88234820;
void func_882211F8(void) {
    func_88001900();
    D_880068B4 = (*(s32 *)((u8 *)(D_88234820) + (0x130)));
    D_88234748 = (*(s16 *)((u8 *)(D_88234820) + (0x2C)));
    Util_Free(D_88234820);
}

extern void func_88004990(u8, s32);
void func_8822123C(s32 arg0) {
    func_88004990(*(*(u8 **)((u8 *)(D_88234820) + (0))), 0);
    D_880068B8 = 1;
    (*(s32 *)((u8 *)(D_88234820) + (0x130))) = arg0;
}

extern void D_88000E4C(void);
extern u8 *D_882345F4;
extern u8 D_8823475C;
extern u8 D_8823475D;
extern u8 D_8823475E;
extern u8 D_889041B8;
extern u8 func_88903B00[];
extern void LabPC_OpenMessageDialog(s8 *title, s16 x, s16 y, s32 style, u8 red, u8 green, u8 blue, u8 delay,
                                    u8 kind, s32 *done, s32 *cancel, s32 *extra, void (*callback)(void));
extern void func_800226C0(s32);
extern void func_8004C54C(s32, void *);
extern s8 *func_8004C8A0(void *, s32, s32, s32);
extern void *func_800635E0(u8);
extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern void func_88002720(void *, u16, void *);
extern void func_8821B980(u16, s32);
extern s32 func_8821C0B0(void);
extern void func_8821C2F4(void);
extern void func_882206A0(s32);
extern void func_88225BC0(s32);
extern void func_88228390(void);
extern void func_8822ABE8(u8 *);
extern void func_8822B43C(u8);
extern void func_8822BE00(s32);
// Input handler for the menu at D_88234820; nothing runs while D_889041B8 is set. A calls
// func_800226C0(92), then dispatches on the selected entry (the u16 at D_88234820 + 0x2C) with
// the record at D_882345F4; entry 5 opens a LabPC message dialog when record byte 9 is
// nonzero. B calls func_800226C0(72) and func_8822123C(1). Any other input goes to
// func_88002720 with the selection, the u16 at +0x10 and the buffer at +0x30.
void func_8822128C(void) {
    if (!D_889041B8) {
        if (D_80087200->buttonsPressed & A_BUTTON) {
            func_800226C0(92);
            switch (*(u16 *)((u8 *)D_88234820 + 0x2C)) {
                case 0:
                    func_8821C2F4();
                    if (D_882345F4[0x26] & 1) {
                        D_8823475C = 0xFD;
                    } else {
                        D_8823475C = D_882345F4[8];
                    }
                    func_8821B980(16, *(s32 *)((u8 *)D_88234820 + 0x128));
                    func_8821C0B0();
                    func_8822123C(1);
                    break;
                case 1:
                    func_8821C2F4();
                    D_8823475D = func_8006397C(D_882345F4[8]);
                    D_8823475E = func_800639C0(D_882345F4[8]);
                    func_8821B980(8, *(s32 *)((u8 *)D_88234820 + 0x12C));
                    func_8821C0B0();
                    func_8822123C(1);
                    break;
                case 2:
                    func_8822123C(0);
                    func_88228390();
                    break;
                case 3:
                    func_8822123C(0);
                    func_88225BC0((s32)(D_882345F4 + 8));
                    break;
                case 4:
                    func_8822123C(0);
                    func_882206A0(1);
                    break;
                case 5:
                    if (D_882345F4[9] != 0) {
                        func_8004C54C(24, func_800635E0(D_882345F4[9]));
                        LabPC_OpenMessageDialog(func_8004C8A0((u8 *)D_88234820 + 0xA5, 128, 37, 102), 380, 287,
                                                4, 255, 170, 140, 2, 1, (s32 *)(*(u8 **)D_88234820 + 0x2C), NULL,
                                                (s32 *)func_88903B00, D_88000E4C);
                    } else {
                        func_8822123C(0);
                        func_882206A0(2);
                    }
                    break;
                case 6:
                    func_8822123C(0);
                    func_8822BE00(D_882345F4[9]);
                    break;
                case 7:
                    func_8822123C(0);
                    func_8822ABE8(D_882345F4 + 8);
                    break;
                case 8:
                    func_8822123C(0);
                    func_8822B43C(D_882345F4[9]);
                    break;
            }
        } else if (D_80087200->buttonsPressed & B_BUTTON) {
            func_800226C0(72);
            func_8822123C(1);
        } else {
            func_88002720((u8 *)D_88234820 + 0x2C, *(u16 *)((u8 *)D_88234820 + 0x10), (u8 *)D_88234820 + 0x30);
        }
    }
}

extern void func_889033FC(void *, void *);
void func_8822157C(void) {
    func_889033FC(*(void **)D_88234820, (u8 *)D_88234820 + 4);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_194450/func_882215A8.s")
#endif
