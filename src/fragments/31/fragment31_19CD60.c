#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_88229AE0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern s32 D_880068B4;
extern u32 D_882348C0;
void func_88229B08(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_882348C0);
}

extern void func_800226C0(s32);
extern void func_88004990(u8, u8);
extern void func_8821C2F4(void);
extern void func_8821B980(u16, s32);
extern s32 func_8821C0B0(void);
extern void func_8800225C(void *, s16, s16);
extern void func_88002720(s16 *, u16, void *);
extern s32 D_8823476C;
extern u8 D_88006880[];

void func_88229B44(void) {
    u8 *menu;
    u32 buttons;

    buttons = D_80087200->buttonsPressed;
    menu = (u8 *)(D_882348C0 + 32);
    if (buttons & 0x4000) {
        func_800226C0(72);
        func_88004990(**(u8 **)D_882348C0, 0);
        D_880068B8 = 1;
    } else if (buttons & 0x8000) {
        func_8821C2F4();
        switch (*(s16 *)(menu + 40)) {
        case 0:
        case 1:
        case 2:
            func_800226C0(92);
            D_8823476C = *(s16 *)(menu + 40);
            func_8821B980(0x200, 1);
            break;
        case 3:
            func_800226C0(311);
            func_8821B980(0x200, 0);
            break;
        }
        func_8821C0B0();
        func_8800225C(D_88006880, 0, 0);
        func_88004990(**(u8 **)D_882348C0, 0);
        D_880068B8 = 1;
    } else {
        func_88002720((s16 *)(menu + 40), *(u16 *)(menu + 12), menu + 44);
    }
}

extern void func_8821D930(s32);
void func_88229C88(void) {
    func_8821D930((D_882348C0 + 4));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19CD60/func_88229CB0.s")
#endif
