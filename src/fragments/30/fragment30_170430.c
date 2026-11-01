#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void *D_88104E90;
extern s8 D_88006868;
extern void func_88A017B4(u8, s16);
extern void func_88A01990(void);
extern void func_8005DFD4(s32, s32);
extern s32 func_8005B120(s32);
extern void GbSave_RequirePakPresent(s32);
extern void GbTower_StartPortSession(s8);
extern void func_80052ECC(s32);
extern void func_80054E48(s32);
extern void func_881000B8(void);

s32 func_88102F60(void) {
    s32 result;

    if (*(s32 *)((u8 *)D_88104E90 + 0xCC) != 0) {
        func_88A017B4(*(u8 *)((u8 *)D_88104E90 + 0xC7), *(s16 *)((u8 *)D_88104E90 + 0x2C));
        func_88A01990();
        func_8005DFD4(D_88006868, 0);
    }
    result = func_8005B120(D_88006868);
    if (*(s32 *)((u8 *)D_88104E90 + 0xCC) == 0) {
        GbSave_RequirePakPresent(D_88006868);
    }
    if (result != 0) {
        GbTower_StartPortSession(D_88006868);
    }
    if ((*(s32 *)((u8 *)D_88104E90 + 0xCC) != 0) &&
        (*(s16 *)((u8 *)D_88104E90 + 0x2C) == 2)) {
        func_80052ECC(3);
        func_80054E48(3);
    }
    if (result != 0) {
        func_881000B8();
    } else {
        *(s32 *)((u8 *)D_88104E90 + 0xCC) = 0;
    }
    return result;
}

extern void Input_SetRepeatController(void *);
extern s32 D_880068B8;
void func_88103058(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void *D_88104E90;
extern void Util_Free(void *);
extern s32 D_880068B4;
void func_88103080(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_88104E90);
}

extern void func_88004990(s32, s32);
void func_881030BC(void) {
    func_88004990(**(u8 **)(D_88104E90), 0);
    D_880068B8 = 1;
}

/* mkdraft:func_881030F4 begin */
extern void func_800226C0(s32);
extern s32 func_8005A228(s8);
extern void func_88002720(void *, u16, void *);
extern s8 D_8800EF40;
extern s8 D_8800EF41;

// Per-frame update of the GB Tower port menu state at D_88104E90. The u8 at +0xD0 counts
// 0 -> 1 -> 2 and then runs the sequence held in the s8 at +0xD1: 1 runs the func_8005A228
// checks on port D_88006868 and stores 1 or 3 in the result byte +0xD3, while a result of 2
// moves +0xD1 to 2 and loads the countdown +0xD2 with 3; 2 counts +0xD2 down and plays
// func_800226C0(330) on its last frame, or clears +0xD1 and +0xD2 when it reaches 0; 0 calls
// func_88102F60 and either finishes with +0xD3 = -1 or restarts with +0xD3 = 2.
// While +0xD0 is 0, a set +0xC8 flag (set below by A_BUTTON) is cleared by any button in
// 0xCF00; otherwise B_BUTTON closes the port session through func_881030BC and A_BUTTON sets
// +0xC8 = 1, leaving any other input to func_88002720 with the cursor at +0x2C, the count
// read from +0x10 and the repeat state at +0x30. The result byte +0xD3 is published as
// D_8800EF40, and port D_88006868 as D_8800EF41 unless +0xD3 is -1.
// The same state machine drives the list menu func_88103DC8, which uses the equivalent s8
// fields at D_88104EA0 +0x16C..+0x16F.
//@src/fragments/30/fragment30_170D70.c


void func_881030F4(void) {
    if (*(u8 *)((u8 *)D_88104E90 + 0xD0) != 0) {
        if (*(u8 *)((u8 *)D_88104E90 + 0xD0) == 2) {
            if (*(s8 *)((u8 *)D_88104E90 + 0xD1) == 1) {
                switch (func_8005A228(D_88006868)) {
                    case 1:
                        *(s8 *)((u8 *)D_88104E90 + 0xD3) = 1;
                        break;
                    case 3:
                        *(s8 *)((u8 *)D_88104E90 + 0xD3) = 3;
                        break;
                    case 2:
                        *(s8 *)((u8 *)D_88104E90 + 0xD1) = 2;
                        *(s8 *)((u8 *)D_88104E90 + 0xD2) = 3;
                        *(s8 *)((u8 *)D_88104E90 + 0xD3) = 0;
                        break;
                }
            }
            if (*(s8 *)((u8 *)D_88104E90 + 0xD1) == 2) {
                *(s8 *)((u8 *)D_88104E90 + 0xD2) -= 1;
                if (*(s8 *)((u8 *)D_88104E90 + 0xD2) == 1) {
                    func_800226C0(330);
                } else if (*(s8 *)((u8 *)D_88104E90 + 0xD2) <= 0) {
                    *(s8 *)((u8 *)D_88104E90 + 0xD1) = 0;
                    *(s8 *)((u8 *)D_88104E90 + 0xD2) = 0;
                }
            }
            if (*(s8 *)((u8 *)D_88104E90 + 0xD1) == 0) {
                if (func_88102F60() != 0) {
                    func_800226C0(17);
                    func_881030BC();
                    *(s8 *)((u8 *)D_88104E90 + 0xD3) = -1;
                } else {
                    *(s8 *)((u8 *)D_88104E90 + 0xD1) = 1;
                    func_800226C0(5);
                    *(s8 *)((u8 *)D_88104E90 + 0xD3) = 2;
                    switch (func_8005A228(D_88006868)) {
                        case 1:
                            *(s8 *)((u8 *)D_88104E90 + 0xD3) = 1;
                            break;
                        case 3:
                            *(s8 *)((u8 *)D_88104E90 + 0xD3) = 3;
                            break;
                    }
                }
            }
        } else {
            *(u8 *)((u8 *)D_88104E90 + 0xD0) += 1;
        }
    } else if (*(s32 *)((u8 *)D_88104E90 + 0xC8) != 0) {
        if (D_80087200->buttonsPressed & 0xCF00) {
            func_800226C0(330);
            *(s32 *)((u8 *)D_88104E90 + 0xC8) = 0;
            *(u8 *)((u8 *)D_88104E90 + 0xD0) = 1;
        }
    } else {
        if (D_80087200->buttonsPressed & B_BUTTON) {
            func_800226C0(3);
            func_881030BC();
        } else if (D_80087200->buttonsPressed & A_BUTTON) {
            func_800226C0(333);
            *(s32 *)((u8 *)D_88104E90 + 0xC8) = 1;
        } else {
            func_88002720((u8 *)D_88104E90 + 0x2C, *(u16 *)((u8 *)D_88104E90 + 0x10),
                          (u8 *)D_88104E90 + 0x30);
        }
    }
    D_8800EF40 = *(s8 *)((u8 *)D_88104E90 + 0xD3);
    if (*(s8 *)((u8 *)D_88104E90 + 0xD3) != -1) {
        D_8800EF41 = D_88006868;
    }
}
/* mkdraft:func_881030F4 end */

extern void *D_88104E90;
extern s32 D_8800687C;
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern s32 func_8004C874(s32, s32);
extern void func_80049064(s32, s32, s32, s32);
extern void func_800499EC(void);
extern s32 func_800472E0(s32);
extern void func_8004989C(s32);
extern s32 func_800635E0(u8);
extern void func_8004C54C(s32, s32);
extern s32 func_8004C8A0(void *, s32, s32, s32);
extern s32 func_80048E30(s32, s32, s32, void *, s32);
extern void func_88002820(s32, s32, s32, s32, s32, s32, void *);
extern void Ui_DrawAnimatedTextureMarker(s32, s16);

void func_881033FC(void) {
    typedef struct {
        u8 padC8[0xC8];
        s32 c8;
        u8 padCC[4];
        u8 d0;
    } State;
    typedef struct {
        u8 padB8[0xB8];
        s32 entries[0x10];
    } TableState;
    struct { u8 pad[8]; u8 data[0x100]; } sp38;
    s32 sp34;

    func_800498C4();
    func_800496A4(8, 1);
    if (((State *)D_88104E90)->d0 != 0) {
        func_80049064(0x13F, 0xCB, 1, func_8004C874(0x1E, 0x1B));
        func_800499EC();
        return;
    }
    if (((State *)D_88104E90)->c8 != 0) {
        sp34 = (func_800472E0(func_8004C874(0x1E, 0x14)) * 0x1A) - 6;
        func_8004989C(0x1A);
        func_8004C54C(0x2A, func_800635E0(*(u8 *)((u8 *)D_88104E90 + 0xC7)));
        func_8004C54C(0x4A, ((TableState *)D_88104E90)->entries[*(s16 *)((u8 *)D_88104E90 + 0x2C)]);
        func_80049064(0x13F, 0xD5 - (sp34 >> 1), 1,
                       func_8004C8A0(sp38.data, 0x100, 0x1E, 0x14));
        func_800499EC();
        return;
    }
    func_80048E30(D_8800687C, 0x65, 0x9D, (u8 *)D_88104E90 + 0x38, 1);
    func_88002820(0x8B, 0xC5, 0,
                   *(s32 *)((u8 *)D_88104E90 + 0xC),
                   *(u16 *)((u8 *)D_88104E90 + 0x10),
                   *(s16 *)((u8 *)D_88104E90 + 0x1A),
                   (u8 *)D_88104E90 + 0x30);
    func_800499EC();
    Ui_DrawAnimatedTextureMarker(0x65,
                   (s16)(*(s16 *)((u8 *)D_88104E90 + 0x2C) * 0x1A + 0xC5));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/30/fragment30_170430/func_881035C0.s")
#endif
