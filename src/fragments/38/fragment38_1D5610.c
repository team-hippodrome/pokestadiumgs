#include "global.h"
#include "controller.h"

#ifdef VERSION_US
extern u8 *D_88904190;
u8 *fragment38_main(void) {
    return D_88904190 + 0x6C;
}

typedef struct ModelPreviewState ModelPreviewState;
extern s32 main_pool_push_state(s32);
extern void *Util_Malloc(s32);
extern s32 func_8004C4B0(s32);
extern s32 func_8004C8C0(s32);
extern void func_88004FF0(s32);
extern void *D_80128C64;
extern ModelPreviewState *ModelPreview_Create(void *,s32,s32);
extern s32 func_80042D74(u8 *,s32);
extern void func_88005714(void *);
extern s32 func_80001FF0(void);

void LabPC_InitEvolutionView(void) {
    main_pool_push_state(0x45564F56);
    D_88904190 = Util_Malloc(348);
    func_8004C4B0(69);
    func_8004C8C0(53);
    func_88004FF0(58);
    *(s16 *)(D_88904190 + 336) = (s16)(u32)(((f32)func_80001FF0() * 20.0f) / 2);
    *(s16 *)(D_88904190 + 338) = (s16)(u32)(((f32)func_80001FF0() * 2.0f) / 2);
    *(s16 *)(D_88904190 + 340) = (s16)(u32)(((f32)func_80001FF0() * 10.0f) / 2);
    *(s16 *)(D_88904190 + 342) = (s16)(u32)(((f32)func_80001FF0() * 2.0f) / 2);
    *(s16 *)(D_88904190 + 344) = (s16)(u32)(((f32)func_80001FF0() * 2.0f) / 2);
    *(s16 *)(D_88904190 + 346) = (s32)((245760.0f / (f32)func_80001FF0()) + (0.0f < 245760.0f / (f32)func_80001FF0() ? 0.5f : -0.5f));
    *(ModelPreviewState **)(D_88904190 + 96) = ModelPreview_Create(D_80128C64, 208, 141);
    *(u16 *)*(u8 **)(D_88904190 + 96) &= 0xFFFD;
    func_80042D74(*(u8 **)(D_88904190 + 96), (s32)func_88005714);
}

extern void Util_Free(void *arg0);
extern void main_pool_pop_state(s32 arg0);
void func_88900494(void) {
    Util_Free(D_88904190);
    main_pool_pop_state(0x45564F56);
}

extern s32 func_880007B0(s32);
s32 func_889004C4(void) {
    s32 result;
    s32 zero;

    result = 0;
    if (*(s32 *)(D_88904190 + 0x11C) != 0) {
        zero = 0;
        result = zero;
        if (func_880007B0(*(s32 *)(D_88904190 + 0x68)) != 0) {
            if (*(u8 *)(D_88904190 + 0x13C) >= 0xA6) {
                result = 1;
            }
        }
    }
    return result;
}

s32 func_88900528(s32 arg0) {
    s32 result = 0;

    switch (arg0) {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            result = 1;
            break;
    }
    return result;
}

void func_8890055C(void) {
    *(s32 *)(D_88904190 + 0x120) = 0;
    *(s32 *)(D_88904190 + 0x124) = 1;
    *(s16 *)(D_88904190 + 0x13E) = (s16)(u32)((f32)func_80001FF0() / 2);
}

extern s32 func_88902B70(u8 *);
extern s32 func_889004C4(void);

void func_88900638(void) {
    *(s32 *)(D_88904190 + 0x120) = 0;
    if ((func_88902B70(*(u8 **)(D_88904190 + 0x68)) != 4) &&
        (func_889004C4() == 0)) {
        *(s32 *)(D_88904190 + 0x124) = 6;
    } else {
        *(s32 *)(D_88904190 + 0x124) = 7;
    }
    *(s16 *)(D_88904190 + 0x13E) =
        (s16)(u32)((f32)func_80001FF0() / 2);
}

void func_88900754(void) {
    u8 *ptr = D_88904190;
    if (*(u32 *)(ptr + 0x44) != 0) {
        *(s32 *)(*(u8 **)(ptr + 0x48) + 0x2C) = 1;
    }
}

extern void Input_SetRepeatController(void *arg0);
void func_8890077C(void) {
    Input_SetRepeatController(D_80087200);
}

typedef struct LabPCTextMask {
    s32 enabled;
    u8 *flags;
} LabPCTextMask;
typedef struct LabPCTextList {
    s16 x, y;
    s32 align;
    u8 **strings;
    u16 count, width;
    s32 font;
    s16 spacing_x, spacing_y, left, right, top, bottom;
    s32 constrain;
    s32 active;
    s16 selected;
    LabPCTextMask mask;
} LabPCTextList;
extern void func_88900DB4(void);

extern void func_800226C0(s32);
extern void func_88002720(s16 *,u16,void *);
extern void func_88004990(u8, s32);

extern void LabPC_OpenChoiceWindow(s32 mode);

extern s8 D_8800EF18;

void LabPC_HandleChoiceInput(void) {
    LabPCTextList *list = (LabPCTextList *)(D_88904190 + 8);
    s32 special_sound;

    if (((D_80087200->buttonsPressed) & 0x8000) && list->selected == 0) {
        special_sound = 0;
        switch (*(s32 *)(D_88904190 + 288)) {
        case 9:
            if (func_889004C4() != 0) {
                *(s32 *)(D_88904190 + 292) = 12;
                *(s32 *)(*(u8 **)(D_88904190 + 4) + 32) = 0;
                LabPC_OpenChoiceWindow(0);
            } else {
                *(s32 *)(D_88904190 + 292) = 13;
                func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
                func_88900DB4();
            }
            break;
        case 11:
            special_sound = 1;
            *(s32 *)(D_88904190 + 292) = 10;
            func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
            break;
        case 12:
            if (func_88902B70(*(u8 **)(D_88904190 + 104)) == 4) {
                *(s32 *)(D_88904190 + 292) = 13;
                func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
                func_88900DB4();
            } else {
                *(s32 *)(D_88904190 + 292) = 6;
                func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
            }
            break;
        case 14:
            *(s32 *)(D_88904190 + 292) = 6;
            func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
            func_88004990((*(u8 **)(D_88904190 + 72))[0], 0);
            break;
        }
        *(s32 *)(D_88904190 + 288) = 0;
        *(s16 *)(D_88904190 + 318) = D_8800EF18;
        if (special_sound != 0) {
            func_800226C0(334);
        } else {
            func_800226C0(*(s32 *)(D_88904190 + 328));
        }
    } else if ((D_80087200->buttonsPressed) & 0xC000) {
        func_800226C0(*(s32 *)(D_88904190 + 332));
        switch (*(s32 *)(D_88904190 + 288)) {
        case 9:
            *(s32 *)(D_88904190 + 292) = 11;
            *(s32 *)(*(u8 **)(D_88904190 + 4) + 32) = 0;
            LabPC_OpenChoiceWindow(0);
            break;
        case 11:
            *(s32 *)(D_88904190 + 292) = 7;
            func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
            break;
        case 12:
            if (func_88902B70(*(u8 **)(D_88904190 + 104)) == 4) {
                *(s32 *)(D_88904190 + 292) = 11;
                *(s32 *)(*(u8 **)(D_88904190 + 4) + 32) = 0;
                LabPC_OpenChoiceWindow(0);
            } else {
                *(s32 *)(D_88904190 + 292) = 10;
                func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
            }
            break;
        case 14:
            *(s32 *)(D_88904190 + 292) = 13;
            func_88004990((*(u8 **)(D_88904190 + 4))[0], 0);
            *(s32 *)(D_88904190 + 68) = 1;
            break;
        }
        *(s32 *)(D_88904190 + 288) = 0;
        *(s16 *)(D_88904190 + 318) = D_8800EF18;
    } else {
        func_88002720(&list->selected, list->count, &list->mask);
    }
}

extern void func_889033FC(void *arg0, void *arg1);
void func_88900ADC(void) {
    func_889033FC(*(void **)(D_88904190 + 4), D_88904190 + 8);
}

typedef struct LabPCChoiceDialog LabPCChoiceDialog;
extern void func_889034DC(LabPCChoiceDialog *);
extern void LabPC_HandleChoiceInput(void);
extern u8 func_88004804(s32,s32,s16,s16,s32,s32,u8,u8,u8,
                         s32 *,s32 *,s32 *,s32 *,u8,u8);
extern void func_88900754(void);
extern void func_8890077C(void);
extern void func_88900ADC(void);
extern u8 D_8800ED50[];

void LabPC_OpenChoiceWindow(s32 mode) {
    u8 slot;
    s16 x;
    s16 y;
    s32 style;

    switch (mode) {
    case 0:
        x = *(s8 *)(D_88904190 + 301) + 528;
        y = *(s8 *)(D_88904190 + 302) + 442;
        style = 8;
        break;
    case 1:
        x = *(s8 *)(D_88904190 + 301) + 528;
        y = *(s8 *)(D_88904190 + 302) + 345;
        style = 2;
        break;
    }
    func_889034DC((LabPCChoiceDialog *)(D_88904190 + 4));
    slot = func_88004804(
        (s32)(D_88904190 + 8), 0, x, y, style, 1,
        *(u8 *)(D_88904190 + 297), *(u8 *)(D_88904190 + 298), *(u8 *)(D_88904190 + 299),
        (s32 *)LabPC_HandleChoiceInput, (s32 *)func_88900ADC, (s32 *)func_8890077C, (s32 *)func_88900754, 1, 2);
    *(u8 **)(D_88904190 + 4) = D_8800ED50 + slot * 76;
    *(u8 *)(D_88904190 + 300) = 3;
}

void func_88900C54(void) {
    Input_SetRepeatController(D_80087200);
}

typedef struct LabPCControllerMovePane {
    u8 *window;
    s16 x, y;
    u8 *pokemon;
    s16 selected;
    u8 count, unk_0F;
    s32 state;
} LabPCControllerMovePane;
extern u8 D_889041A0;

extern u8 D_88006020[];
extern void LabPC_OpenChoiceWindow(s32);

void LabPC_HandleMovePaneInput(void) {
    LabPCControllerMovePane *pane = (LabPCControllerMovePane *)(D_88904190 + 72);
    u32 pressed = D_80087200->buttonsPressed;

    if (pressed & 0x8000) {
        func_800226C0(*(s32 *)(D_88904190 + 328));
        *(s32 *)(pane->window + 44) = 0;
        D_889041A0 = pane->selected;
        *(s32 *)(D_88904190 + 288) = 0;
        *(s32 *)(D_88904190 + 292) = 14;
        *(s16 *)(D_88904190 + 318) = D_8800EF18;
        LabPC_OpenChoiceWindow(1);
    } else if (pressed & 0x4000) {
        func_800226C0(*(s32 *)(D_88904190 + 332));
        func_88004990(pane->window[0], 0);
        *(s32 *)(D_88904190 + 288) = 0;
        *(s32 *)(D_88904190 + 292) = 11;
        *(s16 *)(D_88904190 + 318) = D_8800EF18;
        LabPC_OpenChoiceWindow(0);
    } else {
        func_88002720(&pane->selected, pane->count, D_88006020);
    }
}

extern void func_889035FC(void *arg0);
void func_88900D8C(void) {
    func_889035FC(D_88904190 + 0x48);
}

extern void func_889035A0(void *, u8 *, s16, s16);

extern void LabPC_HandleMovePaneInput(void);
extern void func_88900D8C(void);
extern void func_88900C54(void);
extern u8 D_88000E4C;

void func_88900DB4(void) {
    s32 result;

    func_889035A0(D_88904190 + 0x48, *(u8 **)(D_88904190 + 0x68),
                  *(s8 *)(D_88904190 + 0x12D), *(s8 *)(D_88904190 + 0x12E));
    result = func_88004804(
        0, 3,
        (s16)(*(s8 *)(D_88904190 + 0x12D) + 0x153),
        (s16)(*(s8 *)(D_88904190 + 0x12E) + 0x98),
        0, 1,
        *(u8 *)(D_88904190 + 0x129),
        *(u8 *)(D_88904190 + 0x12A),
        *(u8 *)(D_88904190 + 0x12B),
        (s32 *)LabPC_HandleMovePaneInput, (s32 *)func_88900D8C, (s32 *)func_88900C54, (s32 *)&D_88000E4C, 1, 1);
    *(u8 **)(D_88904190 + 0x48) = D_8800ED50 + result * 0x4C;
    *(s16 *)(*(u8 **)(D_88904190 + 0x48) + 0x10) = 0xBE;
    *(s16 *)(*(u8 **)(D_88904190 + 0x48) + 0x12) = 0xC5;
    *(u8 *)(D_88904190 + 0x12C) = 3;
}

extern void func_8002602C(void);

void func_88900EE4(void) {
    func_800226C0(*(s32 *)(D_88904190 + 0x148));
    func_8002602C();
    func_88004990(*(u8 *)(*(u8 **)(D_88904190 + 0x0)), 0);
    *(s32 *)(*(u8 **)(D_88904190 + 0x0) + 0x34) = 1;
    ((void (*)(void))(u32)*(u32 *)(D_88904190 + 0x130))();
}

extern s8 *func_8004B7A4(s32);

extern void func_80060F68(s8 *, s8 *);

extern s32 HAL_Strcmp(s8 *, s8 *);

extern u8 func_880032C4(void);

extern void func_80021ED8(s32);

extern void func_800225C4(s32);

extern void func_88902BE0(u8 *, u8);

extern s32 func_88902CF0(void *, u8 *, s8);

extern void func_800619E8(void *);

extern s32 func_8003F2C4(void *, void *, s32);

extern s32 ModelAnim_IsFinished(void *);

extern s32 func_8000204C(void);

extern void func_80026068(s32);

extern void func_80042F94(void *, void *);

extern s8 *HAL_Strcpy(s8 *, s8 *);

extern void func_88900F54(void);

extern s32 func_88902E4C(u32 *, u8 *, s8);

extern char *LabPC_FormatColoredMoveName(char *, u8);

void func_88900F54(void) {
    enum { ready_status = 1 };
    u16 old_hp;
    s8 name[64];
    u16 ready;
    if (*(u8 *)(D_88904190 + 300) != 0 && ready_status == func_880032C4()) {
        *(u8 *)(D_88904190 + 300) -= 1;
        if (*(u8 *)(D_88904190 + 300) == 0) *(s32 *)(*(u8 * *)(D_88904190 + 0) + 52) = 0;
        return;
    }
    switch (*(s32 *)(D_88904190 + 288)) {
    case 0:
        *(s16 *)(D_88904190 + 318) -= *(s8 *)(D_88904190 + 320);
        if (*(s16 *)(D_88904190 + 318) <= 0) {
            *(s32 *)(D_88904190 + 288) = *(s32 *)(D_88904190 + 292);
            switch (*(s32 *)(D_88904190 + 288)) {
            case 1:
                *(s16 *)(D_88904190 + 318) = *(s16 *)(D_88904190 + 336);
                *(s8 *)(D_88904190 + 320) = 1;
                func_80021ED8(48);
                func_800226C0(325);
                break;
            case 6:
                func_88902BE0(*(u8 * *)(D_88904190 + 104), *(u8 *)(D_88904190 + 316));
                func_80021ED8(50);
                break;
            case 5:
                *(s16 *)(D_88904190 + 318) = (u32)(((f32)func_80001FF0() * 0.4f) / 2);
                func_800226C0(148);
                break;
            }
        }
        break;
    case 1:
        *(s16 *)(D_88904190 + 318) -= *(s8 *)(D_88904190 + 320);
        *(s16 *)(D_88904190 + 322) = (*(s16 *)(D_88904190 + 336) - *(s16 *)(D_88904190 + 318)) * 240 / *(s16 *)(D_88904190 + 336);
        *(s16 *)(D_88904190 + 326) = 4096 - *(s16 *)(D_88904190 + 318) * 2816 / *(s16 *)(D_88904190 + 336);
        *(s16 *)(D_88904190 + 324) += *(s16 *)(D_88904190 + 346);
        if (*(s16 *)(D_88904190 + 336) - *(s16 *)(D_88904190 + 338) == *(s16 *)(D_88904190 + 318)) {
            *(s32 *)(D_88904190 + 288) = 2;
            *(s16 *)(D_88904190 + 318) = *(s16 *)(D_88904190 + 340);
        } else if (*(s16 *)(D_88904190 + 318) <= 0) {

            old_hp = *(u16 *)((*(u8 **)(D_88904190 + 104)) + 40);
            func_80060F68(name, func_8004B7A4((*(u8 **)(D_88904190 + 104))[0]));
            if (HAL_Strcmp((s8 *)(*(u8 * *)(D_88904190 + 104) + 52), name) == 0) {
                func_80060F68(name, func_8004B7A4(*(u8 *)(D_88904190 + 308)));
                HAL_Strcpy((s8 *)(*(u8 * *)(D_88904190 + 104) + 52), name);
            }
            (*(u8 **)(D_88904190 + 104))[0] = *(u8 *)(D_88904190 + 308);
            func_800619E8(*(u8 * *)(D_88904190 + 104));

            *(u16 *)((*(u8 **)(D_88904190 + 104)) + 38) = *(u16 *)((*(u8 **)(D_88904190 + 104)) + 40) + *(u16 *)((*(u8 **)(D_88904190 + 104)) + 38) - old_hp;
            *(u8 *)(D_88904190 + 308) = 0;
            *(u8 *)(D_88904190 + 316) = func_88902E4C((u32 *)(D_88904190 + 312), *(u8 * *)(D_88904190 + 104), *(s8 *)(D_88904190 + 282));
            if (*(u8 *)(D_88904190 + 316) != 0) LabPC_FormatColoredMoveName((char *)D_88904190 + 154, *(u8 *)(D_88904190 + 316));
            if (*(s32 *)(D_88904190 + 92) == 0) {

                switch ((*(u8 **)(D_88904190 + 104))[0]) {
                case 186: case 199: case 208: case 212: case 230: case 233:
                    (*(u8 **)(D_88904190 + 104))[1] = 0;
                    break;
                }
            }
            while (func_8000204C() == 0) {}
            func_80042F94(*(u8 * *)(D_88904190 + 96), *(u8 * *)(D_88904190 + 104));

            func_8003F2C4(*(void **)((*(u8 **)(D_88904190 + 96)) + 20), *(void **)((*(u8 **)(D_88904190 + 96)) + 28), *(s8 *)(D_88904190 + 309));
            *(s32 *)(*(u8 **)(*(u8 * *)(D_88904190 + 96) + 28) + 76) = 0;
            *(u16 *)*(u8 * *)(D_88904190 + 96) &= 0xFFFB;
            *(s32 *)(D_88904190 + 288) = 3;
            *(s16 *)(D_88904190 + 318) = *(s16 *)(D_88904190 + 342);
            *(s8 *)(D_88904190 + 320) = 1;
            *(u8 *)(D_88904190 + 296) |= 4;
        } else if (*(s16 *)(D_88904190 + 318) >= *(s16 *)(D_88904190 + 336)) {
            *(s32 *)(D_88904190 + 288) = 4;
            *(s16 *)(D_88904190 + 318) = *(s16 *)(D_88904190 + 344);
            *(s8 *)(D_88904190 + 320) = 1;
            *(s16 *)(D_88904190 + 322) = 0;
            *(s16 *)(D_88904190 + 324) = 0;
            *(s16 *)(D_88904190 + 326) = 0;
        }
        break;
    case 2:
        *(s16 *)(D_88904190 + 324) += *(s16 *)(D_88904190 + 346);
        if ((*(u8 *)(D_88904190 + 296) & 1) && (D_80087200->buttonsPressed & 0x4000)) {
            *(s32 *)(D_88904190 + 288) = 1;
            *(s16 *)(D_88904190 + 318) = *(s16 *)(D_88904190 + 336) - *(s16 *)(D_88904190 + 338);
            *(s8 *)(D_88904190 + 320) = -1;
            *(u8 *)(D_88904190 + 296) |= 2;
            func_800226C0(335);
            func_800225C4(30);
        } else {
            *(s16 *)(D_88904190 + 318) -= *(s8 *)(D_88904190 + 320);
            if (*(s16 *)(D_88904190 + 318) <= 0 || (D_80087200->buttonsPressed & 0x8000)) {
                *(s32 *)(D_88904190 + 288) = 1;
                *(s16 *)(D_88904190 + 318) = *(s16 *)(D_88904190 + 336) - *(s16 *)(D_88904190 + 338);
                *(s8 *)(D_88904190 + 320) = *(s16 *)(D_88904190 + 318) / *(s16 *)(D_88904190 + 342);
            }
        }
        break;
    case 3:
        *(s16 *)(D_88904190 + 318) -= *(s8 *)(D_88904190 + 320);
        *(s16 *)(D_88904190 + 322) = 240 * *(s16 *)(D_88904190 + 318) / *(s16 *)(D_88904190 + 342);
        *(s16 *)(D_88904190 + 326) = 1280 - (*(s16 *)(D_88904190 + 318) * -2816) / *(s16 *)(D_88904190 + 342);
        *(s16 *)(D_88904190 + 324) += *(s16 *)(D_88904190 + 346);
        if (*(s16 *)(D_88904190 + 318) == 25) func_800225C4(30);
        else if (*(s16 *)(D_88904190 + 318) == 15) func_80026068((*(u8 **)(D_88904190 + 104))[0]);
        else if (*(s16 *)(D_88904190 + 318) <= 0) {
            *(s32 *)(D_88904190 + 288) = 4;
            *(s16 *)(D_88904190 + 318) = *(s16 *)(D_88904190 + 344);
            *(s8 *)(D_88904190 + 320) = 1;
            *(s16 *)(D_88904190 + 322) = 0;
            *(s16 *)(D_88904190 + 324) = 0;
            *(s16 *)(D_88904190 + 326) = 0;
            *(s32 *)(*(u8 **)(*(u8 * *)(D_88904190 + 96) + 28) + 76) = 65536;
            func_80021ED8(49);
        }
        break;
    case 4:
        if ((*(u8 *)(D_88904190 + 296) & 4) && ModelAnim_IsFinished(*(void **)(*(u8 * *)(D_88904190 + 96) + 28))) {

            if (*(s8 *)(D_88904190 + 309) == *(s16 *)(*(u8 **)((*(u8 **)(D_88904190 + 96)) + 28) + 64)) {
                func_8003F2C4(*(void **)((*(u8 **)(D_88904190 + 96)) + 20), *(void **)((*(u8 **)(D_88904190 + 96)) + 28), 1);
                *(u16 *)*(u8 * *)(D_88904190 + 96) |= 4;
                *(u8 *)(D_88904190 + 296) |= 8;
                break;
            }
        }
        if (*(s16 *)(D_88904190 + 318) != 0) {
            *(s16 *)(D_88904190 + 318) -= *(s8 *)(D_88904190 + 320);
            if (*(s16 *)(D_88904190 + 318) < 0) *(s16 *)(D_88904190 + 318) = 0;
        } else {
            ready = 1;
            if (*(u8 *)(D_88904190 + 296) & 4) ready = (*(u8 *)(D_88904190 + 296) & 8) != 0;
            if (ready) {
                if ((*(u8 *)(D_88904190 + 296) & 4) && *(u8 *)(D_88904190 + 316)) {
                    if (D_80087200->buttonsPressed & 0x8000) {
                        func_800226C0(*(s32 *)(D_88904190 + 328));
                        func_88900638();
                        func_80021ED8(8);
                    }
                } else if (D_80087200->buttonsPressed & 0xC000) {
                    func_88900EE4();
                    func_80021ED8(8);
                }
            }
        }
        break;
    case 5:
        if (*(s16 *)(D_88904190 + 318) != 0) *(s16 *)(D_88904190 + 318) -= 1;
        else if (D_80087200->buttonsPressed & 0xC000) func_88900EE4();
        break;
    case 6: case 10:
        if (D_80087200->buttonsPressed & 0x8000) {
            if (*(s32 *)(D_88904190 + 288) == 6) func_80021ED8(8);
            *(u8 *)(D_88904190 + 316) = func_88902CF0(D_88904190 + 312, *(u8 * *)(D_88904190 + 104), *(s8 *)(D_88904190 + 282));
            if (*(u8 *)(D_88904190 + 316) != 0) {
                LabPC_FormatColoredMoveName((char *)D_88904190 + 154, *(u8 *)(D_88904190 + 316));
                *(s32 *)(D_88904190 + 288) = 0;
                if (func_88902B70(*(u8 * *)(D_88904190 + 104)) != 4 && func_889004C4() == 0) *(s32 *)(D_88904190 + 292) = 6;
                else *(s32 *)(D_88904190 + 292) = 7;
                *(s16 *)(D_88904190 + 318) = D_8800EF18;
                func_800226C0(*(s32 *)(D_88904190 + 328));
            } else if (*(u8 *)(D_88904190 + 308) != 0) {
                func_800226C0(*(s32 *)(D_88904190 + 328));
                func_8890055C();
            } else func_88900EE4();
        }
        break;
    case 7:
        if (D_80087200->buttonsPressed & 0x8000) {
            func_800226C0(*(s32 *)(D_88904190 + 328));
            *(s32 *)(D_88904190 + 288) = 0;
            if (func_88902B70(*(u8 * *)(D_88904190 + 104)) == 4) *(s32 *)(D_88904190 + 292) = 8;
            else {
                *(s32 *)(D_88904190 + 292) = 12;
                LabPC_OpenChoiceWindow(0);
            }
            *(s16 *)(D_88904190 + 318) = D_8800EF18;
        }
        break;
    case 8:
        if (D_80087200->buttonsPressed & 0x8000) {
            func_800226C0(*(s32 *)(D_88904190 + 328));
            *(s32 *)(D_88904190 + 288) = 0;
            *(s32 *)(D_88904190 + 292) = 9;
            *(s16 *)(D_88904190 + 318) = D_8800EF18;
            LabPC_OpenChoiceWindow(0);
        }
        break;
    }
}

extern Gfx *D_800D0510;
extern u8 *D_8800ECC4;
extern u8 *D_8800ECC0;
extern u8 *D_8800ECC8;
extern u8 *D_8800687C;
extern u8 D_80094E38[];
extern u8 D_80094E00[];
extern u8 D_80094F50[];
extern u8 D_88903E10[];
extern u8 D_88903E48[];
extern f32 D_80087E50[];
extern s32 func_80043678(u8 *);
extern void func_800088DC(void);
extern s32 func_8004D1FC(u8 *);
extern s32 func_8004D27C(u8 *, s32, s32);
extern void func_88002C2C(s32, s32, s32);
extern s32 func_8004CA10(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_88002CB8(s16, s16, s32, s32);
extern void func_88002EC0(s16, s16, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004989C(s32);
extern s32 func_88900528(s32);
extern s32 func_8004C54C(s32, void *);

extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_80048E30(u8 *, s32, s32, void *, s32);
extern void func_800499EC(void);
extern void func_80006F70(Gfx **, s16, s16, s32, s32);
extern void func_880015F4(s16, s16, s32, s32, s32, s32, s32, s32);

#define GW(a, b) { Gfx *g_ = D_800D0510++; ((u32 *)g_)[0] = (a); ((u32 *)g_)[1] = (b); }
#define PX(d) ((s16)(*(s8 *)(D_88904190 + 0x12D) + (d)))
#define PY(d) ((s16)(*(s8 *)(D_88904190 + 0x12E) + (d)))

typedef struct { u8 r, g, b, a; } LabPCControllerColor;

void func_88901A24(void) {
    u32 i;
    u16 strId;
    u8 *tex;
    s16 y;
    u8 pct;
    s32 flag;

    flag = 0;
    if (D_88904190[0x12C] != 0) {
        if (*(s32 *)(D_88904190 + 0x120) != 13 && *(s32 *)(D_88904190 + 0x120) != 14) {
            flag = 1;
        }
    }
    *(s32 *)(D_88904190 + 0x64) = func_80043678(*(u8 **)(D_88904190 + 0x60));
    func_800088DC();
    GW(0xDE000000, (u32)D_80094E38);
    func_8004D1FC(D_8800ECC4);
    func_8004D27C(D_8800ECC0, 0x80, 1);
    func_88002C2C(D_88904190[0x129], D_88904190[0x12A], D_88904190[0x12B]);
    if (flag != 0) {
        GfxRect_DrawTextured(PX(0xA4), PY(0x97), 0x16B, 0xA7, 0, 0, (s32)((1024.0f * (f32)func_8004CA10(D_8800ECC4)) / 363.0f + (0.0f < (((f32)func_8004CA10(D_8800ECC4) * 1024.0f) / 363.0f) ? 0.5f : -0.5f)), 0, 0);
    }
    if (*(s32 *)(D_88904190 + 0x120) == 12) {
        GW(0xE7000000, 0);
        GW(0xFB000000, 0xFFAA8CFF);
    }
    GfxRect_DrawTextured(PX(0xA4), PY(0x147), 0x16B, 0x72, 0, 0, (s32)((1024.0f * (f32)func_8004CA10(D_8800ECC4)) / 363.0f + (0.0f < (((f32)func_8004CA10(D_8800ECC4) * 1024.0f) / 363.0f) ? 0.5f : -0.5f)), 0, 0);
    GW(0xE7000000, 0);
    GW(0xE200001C, 0x0F0A7008);
    if (flag != 0) {
        if (*(s32 *)(D_88904190 + 0x120) == 12) {
            GW(0xFB000000, ((D_88904190[0x12A] & 0xFF) << 16) | ((D_88904190[0x12B] & 0xFF) << 8) | 0xFF | ((D_88904190[0x129] & 0xFF) << 24));
        }
        func_88002CB8(PX(0x9F), PY(0x92), 0x178, 0xB4);
        if (*(s32 *)(D_88904190 + 0x120) == 12) {
            GW(0xE7000000, 0);
            GW(0xFB000000, 0xFFAA8CFF);
        }
    }
    func_88002CB8(PX(0x9F), PY(0x142), 0x178, 0x7F);
    if (flag != 0) {
        func_8004D27C(D_8800ECC8, 0x100, 2);
        GW(0xE7000000, 0);
        GW(0xFB000000, -1);
        func_88002EC0(PX(0xEE), PY(0xA1), 0xD6, 0x93, 3);
    }
    switch (*(s32 *)(D_88904190 + 0x120)) {
        case 6:
        case 7:
        case 8:
        case 10:
            GW(0xDE000000, (u32)D_80094E00);
            func_8004D19C(*(s8 *)(D_88904190 + 0x12D) + 0x1E9, *(s8 *)(D_88904190 + 0x12E) + 0x195, func_8004C990(0x35, D_88903E48[D_88904190[0x13D]]), 0, 0x200000);
            D_88904190[0x13D]++;
            if (D_88904190[0x13D] >= 0xCU) {
                D_88904190[0x13D] = 0;
            }
        break;
    }
    GW(0xDE000000, (u32)D_80094F50);
    if (*(s32 *)(D_88904190 + 0x120) != 0) {
        char buf[0x100];

        func_800498C4();
        func_800496A4(8, 1);
        func_8004989C(0x1A);
        if (func_88900528(*(s32 *)(D_88904190 + 0x120)) != 0) {
            func_8004C54C(0x1A, *(u8 **)(D_88904190 + 0x68) + 0x34);
            switch (*(s32 *)(D_88904190 + 0x120)) {
                case 8:
                case 13:
                case 14:
                    break;
                default:
                    func_8004C54C(0x41, D_88904190 + 0x9A);
                    break;
            }
        } else {
            func_8004C54C(0x1A, D_88904190 + 0x6C);
        }
        switch (*(s32 *)(D_88904190 + 0x120)) {
            case 1:
            case 2:
            case 3:
                strId = 6;
                break;
            case 4:
                if (D_88904190[0x128] & 2) {
                    strId = 7;
                } else {
                    func_8004C54C(0x22, func_8004B7A4(**(u8 **)(D_88904190 + 0x68)));
                    strId = 8;
                }
                break;
            case 5:
                if ((*(u8 **)(D_88904190 + 0x68))[0x1E] & 1) {
                    func_8004C54C(0x20, (*(u8 **)(D_88904190 + 0x68)) + 0x34);
                } else {
                    func_8004C54C(0x20, func_8004B7A4((*(u8 **)(D_88904190 + 0x68))[0]));
                }
                func_8004C54C(0x15, D_88904190 + 0x8C);
                strId = 9;
                break;
            case 6: strId = 10; break;
            case 7: strId = 11; break;
            case 8: strId = 12; break;
            case 9: strId = 13; break;
            case 10: strId = 14; break;
            case 11: strId = 15; break;
            case 12: strId = 16; break;
            case 13: strId = 17; break;
            case 14: strId = 18; break;
        }
        func_80048E30(D_8800687C, *(s8 *)(D_88904190 + 0x12D) + 0xAE, *(s8 *)(D_88904190 + 0x12E) + 0x14F,
                      func_8004C8A0(buf, 0x100, 0x45, strId), 1);
        func_800499EC();
    }
    switch (*(s32 *)(D_88904190 + 0x120)) {
        case 1:
        case 2:
        case 3:
            GW(0xDE000000, (u32)D_88903E10);
            switch (*(s32 *)(D_88904190 + 0x120)) {
                case 1:
                    pct = ((*(s16 *)(D_88904190 + 0x150) - *(s16 *)(D_88904190 + 0x13E)) * 255) / *(s16 *)(D_88904190 + 0x150);
                    break;
                case 2:
                    pct = (*(s16 *)(D_88904190 + 0x152) * 255) / *(s16 *)(D_88904190 + 0x150);
                    break;
                case 3:
                    pct = (*(s16 *)(D_88904190 + 0x13E) * 255) / *(s16 *)(D_88904190 + 0x156);
                    break;
            }
            GW(0xFA000000 | (pct & 0xFF), -1);
            func_80006F70(&D_800D0510, PX(0xF1), PY(0xA4), 0xD0, 0x8D);
            tex = *(u8 **)(D_88904190 + 0x64);
            y = *(s8 *)(D_88904190 + 0x12E) + 0xA4;
            for (i = 0; i != 0x8D; y++, i++, tex += 0x1A0) {
                GW(0xFD100000, (u32)tex);
                GW(0xF5100000, 0x07080200);
                GW(0xE6000000, 0);
                GW(0xF3000000, 0x070CF028);
                GW(0xE7000000, 0);
                GW(0xF5106800, 0x00080200);
                GW(0xF2000000, 0x0033C000);
                GfxRect_DrawTextured(
                    *(s8 *)(D_88904190 + 0x12D) + (s32)(((f32)*(s16 *)(D_88904190 + 0x142) * D_80087E50[(u16)(*(s16 *)(D_88904190 + 0x146) * i + *(s16 *)(D_88904190 + 0x144)) >> 4]) + (0.0f < ((f32)*(s16 *)(D_88904190 + 0x142) * D_80087E50[(u16)(*(s16 *)(D_88904190 + 0x146) * i + *(s16 *)(D_88904190 + 0x144)) >> 4]) ? 0.5f : -0.5f)) + 0xF1,
                    y, 0xD0, 1, -0x10, -0x10, 0x400, 0x400, 0);
            }
            break;
        default:
            GW(0xDE000000, (u32)D_80094E00);
            switch (*(s32 *)(D_88904190 + 0x120)) {
                case 13:
                case 14:
                    func_80006F70(&D_800D0510, PX(0xF1), PY(0xA4), 0x62, 0x8D);
                    break;
            }
            func_880015F4(PX(0xF1), PY(0xA4), 0xD0, 0x8D, *(s32 *)(D_88904190 + 0x64), 0, 2, 0);
            break;
    }
    func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);
}

#undef GW
#undef PX
#undef PY

extern void *BinArchive_Open();
extern u8 LabPC_FindFireStoneEvolution(u8 species);
extern u8 LabPC_FindLeafStoneEvolution(u8 species);
extern s32 LabPC_FindLevelUpEvolution(u8 *pokemon, s32 use_clock);
extern u8 LabPC_FindWaterStoneEvolution(u8 species);
extern void *func_80004B4C(s32 arg0, s32 arg1);
extern s32 func_800356CC(s32 arg0);
extern u8 func_88903084(u8 arg0);
extern u8 func_8890311C(u8 arg0);
extern u8 func_889031EC(u8 arg0);
extern s32 func_88903220(u8 *arg0, s8 arg1);

// Evolution dispatcher for the lab PC's evolution view (LabPC_OpenEvolutionView
// passes its kind/mode through). Mode 0 evolves by level through
// func_88903220, 1 through LabPC_FindLevelUpEvolution with the clock flag,
// 2/4/7 through the table lookups func_8890311C and func_889031EC, and
// 3/5/6 through the fire/water/leaf stone checks. The resulting species is
// stored at D_88904190[0x134]; when it is nonzero the function pushes the
// 'EXCL' main-pool state, opens the archive func_800356CC(0) returns, and
// copies byte 0x13B0 of the entry func_80004B4C selects with species - 1
// into D_88904190[0x135] before popping the state again.
void func_88902624(s32 mode, u8 *pokemon, s8 level) {
    typedef struct { u8 bytes[0x136]; } ResourceRecord;
    u8 *record;

    switch (mode) {
        case 0:
            D_88904190[0x134] = func_88903220(pokemon, level);
            break;
        case 1:
            D_88904190[0x134] = LabPC_FindLevelUpEvolution(pokemon, 1);
            break;
        case 2:
            D_88904190[0x134] = func_88903084(pokemon[0]);
            break;
        case 3:
            D_88904190[0x134] = LabPC_FindFireStoneEvolution(pokemon[0]);
            break;
        case 4:
            D_88904190[0x134] = func_8890311C(pokemon[0]);
            break;
        case 5:
            D_88904190[0x134] = LabPC_FindWaterStoneEvolution(pokemon[0]);
            break;
        case 6:
            D_88904190[0x134] = LabPC_FindLeafStoneEvolution(pokemon[0]);
            break;
        case 7:
            D_88904190[0x134] = func_889031EC(pokemon[0]);
            break;
    }
    if (D_88904190[0x134] != 0) {
        main_pool_push_state(0x4558434C);
        record = (ResourceRecord *)func_800356CC(0);
        record = (ResourceRecord *)BinArchive_Open(record, 0, 1, 1);
        D_88904190[0x135] = ((u8 *)func_80004B4C(record, D_88904190[0x134] - 1))[0x13B0];
        main_pool_pop_state(0x4558434C);
    }
}

extern LabPCControllerColor *Color_SetRGB(LabPCControllerColor *, u8, u8, u8);
extern void func_80042F94(void *, void *);
extern void Audio_InitializeBufferMemory(void *);
extern u8 D_880068C0[];
extern s8 *HAL_Strcpy(s8 *, s8 *);
extern s32 func_8005DC48(s32, s32);
extern void func_88902624(s32, u8 *, s8);
extern void func_88900F54(void);
extern void func_88901A24(void);
extern s32 func_88902E4C(u32 *, u8 *, s8);
extern char *LabPC_FormatColoredMoveName(char *, u8);
extern void func_88005048(void);

u8 LabPC_OpenEvolutionView(s32 kind, u8 *pokemon, s8 slot, s32 context,
                         s32 *cb2, s32 *cb3, void (*done)(void), u8 delay) {
    func_80042F94(*(void **)(D_88904190 + 96), pokemon);
    Audio_InitializeBufferMemory(D_880068C0);
    if (kind == 0) {
        *(s8 *)(D_88904190 + 301) = -26;
        *(s8 *)(D_88904190 + 302) = -57;
        Color_SetRGB((LabPCControllerColor *)(D_88904190 + 297), 230, 255, 240);
        *(s32 *)(D_88904190 + 328) = 2;
        *(s32 *)(D_88904190 + 332) = 3;
    } else {
        *(s8 *)(D_88904190 + 301) = 8;
        *(s8 *)(D_88904190 + 302) = 0;
        Color_SetRGB((LabPCControllerColor *)(D_88904190 + 297), 220, 220, 180);
        *(s32 *)(D_88904190 + 328) = 71;
        *(s32 *)(D_88904190 + 332) = 72;
    }
    *(u8 **)(D_88904190 + 0) = D_8800ED50 + func_88004804(
        0, 3, (s16)(*(s8 *)(D_88904190 + 301) + 159),
        (s16)(*(s8 *)(D_88904190 + 302) + 146), 0, 2,
        *(u8 *)(D_88904190 + 297), *(u8 *)(D_88904190 + 298), *(u8 *)(D_88904190 + 299),
        (s32 *)func_88900F54, (s32 *)func_88901A24, cb2, cb3, delay, 0) * 76;
    *(s16 *)(*(u8 **)(D_88904190 + 0) + 16) = 376;
    *(s16 *)(*(u8 **)(D_88904190 + 0) + 18) = 303;
    *(s32 *)(D_88904190 + 92) = kind;
    *(u8 **)(D_88904190 + 104) = pokemon;
    *(s8 *)(D_88904190 + 282) = slot;
    *(s32 *)(D_88904190 + 284) = context;
    *(void (**)(void))(D_88904190 + 304) = done;
    HAL_Strcpy((s8 *)(D_88904190 + 108), (s8 *)(pokemon + 52));
    func_8005DC48(slot, (s32)(D_88904190 + 140));
    func_88902624(kind, pokemon, slot);
    *(u8 *)(D_88904190 + 300) = 3;
    *(u8 *)(D_88904190 + 296) = 0;
    if (kind == 1) {
        *(u8 *)(D_88904190 + 296) |= 1;
        *(u8 *)(D_88904190 + 316) = func_88902E4C((u32 *)(D_88904190 + 312), pokemon, slot);
    }
    if (kind == 1 && *(u8 *)(D_88904190 + 316) != 0) {
        LabPC_FormatColoredMoveName((char *)(D_88904190 + 154), *(u8 *)(D_88904190 + 316));
        func_88900638();
    } else if (kind == 0 && *(u8 *)(D_88904190 + 308) == 0) {
        *(s32 *)(D_88904190 + 288) = 0;
        *(s32 *)(D_88904190 + 292) = 5;
        *(s16 *)(D_88904190 + 318) = (s16)(u32)((f32)func_80001FF0() / 2);
    } else {
        func_8890055C();
    }
    *(u8 *)(D_88904190 + 317) = 0;
    *(u8 *)(D_88904190 + 320) = 1;
    *(s16 *)(D_88904190 + 322) = 0;
    *(s16 *)(D_88904190 + 324) = 0;
    *(s16 *)(D_88904190 + 326) = 0;
    func_88005048();
    return *(u8 *)(D_88904190 + 308);
}
#endif
