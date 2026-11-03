#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_88229110(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

typedef struct {
    u8 unused[0x1AC];
    u8 selected;
    u8 padding[7];
    void (*callback)(void);
} Cleanup_88229138;
extern u32 D_882348B0;
extern s32 D_880068B4;
extern void func_88001900(void);
extern void Util_Free(s32);
void func_88229138(void) {
    Cleanup_88229138 *state = (Cleanup_88229138 *)D_882348B0;

    if (state->selected != 0) {
        state->callback();
    } else {
        Input_SetRepeatController(D_80087200);
        func_88001900();
        D_880068B4 = 1;
    }
    Util_Free((s32)D_882348B0);
}

/* mkdraft:func_882291A4 begin */
extern u32 D_882348B0;
extern s8 D_88006868;
extern s8 D_8800EF40;
extern s8 D_8800EF41;
extern s32 D_880068B8;
extern s32 func_8005A228(s8);
extern void func_800226C0(s32);
extern void func_88004990(u8, s32);
extern void func_88002720(void *, u16, void *);
extern s32 func_88201048(void);
extern s32 func_8004C8A0(void *, s32, s32, s32);
extern s32 func_8004C874(s32, s32);
extern s32 func_800472B8(s32);
extern s32 Envelope_Advance(void *);

typedef struct {
    /* 0x000 */ void *unk_00;
    /* 0x004 */ s16 unk_04;
    /* 0x006 */ s16 unk_06;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ u8 unk_14[6];
    /* 0x01A */ s16 unk_1A;
    /* 0x01C */ u8 unk_1C[0x1AC - 0x1C];
    /* 0x1AC */ u8 unk_1AC;
    /* 0x1AD */ u8 unk_1AD;
    /* 0x1AE */ u8 unk_1AE;
    /* 0x1AF */ s8 unk_1AF;
    /* 0x1B0 */ s8 unk_1B0;
    /* 0x1B1 */ s8 unk_1B1;
} unk_D_882348B0;

// Every field access re-reads the global D_882348B0 rather than caching the
// pointer in a local: the calls in this function may replace the object.


void func_882291A4(void) {
    s32 pressed;
    u8 *p;

    if (((unk_D_882348B0 *)D_882348B0)->unk_1AE != 0) {
        if (((unk_D_882348B0 *)D_882348B0)->unk_1AE == (((unk_D_882348B0 *)D_882348B0)->unk_1AD + 2)) {
            if (((unk_D_882348B0 *)D_882348B0)->unk_1AF == 1) {
                switch (func_8005A228(D_88006868)) {
                case 1:
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 1;
                    break;
                case 3:
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 3;
                    break;
                case 2:
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AF = 2;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B0 = 3;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 0;
                    break;
                }
            }
            if (((unk_D_882348B0 *)D_882348B0)->unk_1AF == 2) {
                ((unk_D_882348B0 *)D_882348B0)->unk_1B0 = ((unk_D_882348B0 *)D_882348B0)->unk_1B0 - 1;
                if (((unk_D_882348B0 *)D_882348B0)->unk_1B0 == 1) {
                    func_800226C0(0x12C);
                } else if (((unk_D_882348B0 *)D_882348B0)->unk_1B0 <= 0) {
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AF = 0;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B0 = 0;
                }
            }
            if (((unk_D_882348B0 *)D_882348B0)->unk_1AF == 0) {
                if (func_88201048() != 0) {
                    func_800226C0(0x12D);
                    func_88004990(*(u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00, 0);
                    D_880068B8 = 1;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AC = 1;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = -1;
                } else {
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AF = 1;
                    func_800226C0(0x61);
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 2;
                    switch (func_8005A228(D_88006868)) {
                    case 1:
                        ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 1;
                        break;
                    case 3:
                        ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 3;
                        break;
                    }
                }
            }
        } else {
            ((unk_D_882348B0 *)D_882348B0)->unk_1AE = ((unk_D_882348B0 *)D_882348B0)->unk_1AE + 1;
        }
    } else {
        p = (u8 *)D_882348B0 + 0x20;
        sprintf((char *)((u8 *)D_882348B0 + 0x54), "<COL1,LOAD,240,120,30,%d>", Envelope_Advance((u8 *)D_882348B0 + 0x1A0));
        ((unk_D_882348B0 *)D_882348B0)->unk_0C = func_8004C8A0((u8 *)D_882348B0 + 0x94, 0x100, 0x27, 1);
        pressed = D_80087200->buttonsPressed;
        if (pressed & 0x4000) {
            func_800226C0(0x48);
            func_88004990(*(u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00, 0);
            D_880068B8 = 1;
            ((unk_D_882348B0 *)D_882348B0)->unk_1AC = 0;
        } else if (pressed & 0x8000) {
            if (*(s16 *)(p + 0x28) == 0) {
                func_800226C0(0x12C);
                ((unk_D_882348B0 *)D_882348B0)->unk_10 = 0x10;
                ((unk_D_882348B0 *)D_882348B0)->unk_04 =
                    (*(u16 *)((u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00 + 0x10) >> 1) +
                    *(s16 *)((u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00 + 0xC);
                ((unk_D_882348B0 *)D_882348B0)->unk_06 =
                    ((unk_D_882348B0 *)D_882348B0)->unk_06 +
                    ((((unk_D_882348B0 *)D_882348B0)->unk_1A - ((unk_D_882348B0 *)D_882348B0)->unk_06 - 6) >> 1) -
                    (func_800472B8(((unk_D_882348B0 *)D_882348B0)->unk_10) >> 1);
                ((unk_D_882348B0 *)D_882348B0)->unk_08 = 1;
                ((unk_D_882348B0 *)D_882348B0)->unk_0C = func_8004C874(0x27, 3);
                *(s32 *)(p + 0x24) = 2;
                ((unk_D_882348B0 *)D_882348B0)->unk_1AE = 1;
            } else {
                func_88004990(*(u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00, 0);
                D_880068B8 = 1;
                ((unk_D_882348B0 *)D_882348B0)->unk_1AC = 2 - *(s16 *)(p + 0x28);
                if (*(s16 *)(p + 0x28) == 1) {
                    func_800226C0(0x12E);
                } else {
                    func_800226C0(0x48);
                }
            }
        } else {
            func_88002720(p + 0x28, *(u16 *)(p + 0xC), p + 0x2C);
        }
    }
    D_8800EF40 = ((unk_D_882348B0 *)D_882348B0)->unk_1B1;
    if (((unk_D_882348B0 *)D_882348B0)->unk_1B1 != -1) {
        D_8800EF41 = D_88006868;
    }
}
/* mkdraft:func_882291A4 end */

extern u32 D_882348B0;
extern void func_8821D930(s32);
void func_882295BC(void) {
    func_8821D930((D_882348B0 + 4));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19C390/func_882295E4.s")
#endif
