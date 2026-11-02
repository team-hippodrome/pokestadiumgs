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

/* mkdraft:func_882215A8 begin */
extern void *Util_Malloc(s32 arg0);
extern void _bzero(void *, s32);
extern void *func_8004B7A4(s32 arg0);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern s32 func_80063754(s32 arg0);
extern u8 func_8006397C(u8 arg0);
extern u8 func_800639C0(u8 arg0);
extern s32 func_88002AA8(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s16, void *);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern s32 func_8821B7E4(u8 arg0);
extern s32 func_8821B81C(s8 arg0, s8 arg1);
typedef struct {
    s32 enabled;
    u8 *flags;
} F31TextMask;
extern F31TextMask D_88006020;
extern u8 D_8800ED50[];



void func_882215A8(volatile u8 arg0, s16 arg1) {
    s32 a3;
    u8 col;
    s32 i;
    F31TextMask state = D_88006020;
    D_88234820 = Util_Malloc(0x134);
    if ((D_882345F4[0x26] & 1) != 0) {
        arg0 = 0xFD;
    }
    func_8004C54C(0x19, func_8004B7A4(arg0));
    if (D_882345F4[8] == 0xFC) {
        a3 = 0x19;
    } else {
        *((s32 *)(((u8 *)D_88234820) + 0x128)) = 1 - func_8821B7E4(arg0);
        if (*((s32 *)(((u8 *)D_88234820) + 0x128)) == 0) {
            a3 = 0x1A;
        } else {
            a3 = 0x19;
        }
    }
    *((s32 *)(((u8 *)D_88234820) + 0x38)) = func_8004C8A0(((u8 *)D_88234820) + 0x65, 0x40, 0x25, a3);

    if (((D_882345F4[0x26] & 1) != 0) || (D_882345F4[8] == 0xFC)) {
        a3 = 0x1B;
    } else {
        col = func_8006397C(arg0);
        *((s32 *)(((u8 *)D_88234820) + 0x12C)) = 1 - func_8821B81C(col, func_800639C0(arg0));
        if (*((s32 *)(((u8 *)D_88234820) + 0x12C)) == 0) {
            a3 = 0x1C;
        } else {
            a3 = 0x1B;
        }
    }
    *((s32 *)(((u8 *)D_88234820) + 0x3C)) = func_8004C874(0x25, a3);

    for (i = 2; i < 9; i++) {
        *((s32 *)((((u8 *)D_88234820) + 0x38) + (i * 4))) = func_8004C874(0x25, i + 0x1B);
    }

    state.flags = ((u8 *)D_88234820) + 0x5C;
    _bzero(state.flags, 9);
    if (D_882345F4[8] == 0xFC) {
        state.enabled = 1;
        state.flags[5] = 1;
        // FAKE: the read-back is the 1 just stored; copying it through col is what makes the
        // four stores share one materialized constant (1120 with a direct 1 in each store).
        col = state.flags[5];
        state.flags[4] = col;
        state.flags[1] = col;
        state.flags[0] = col;
        if (D_882345F4[9] == 0) {
            state.flags[7] = 1;
            state.flags[6] = state.flags[7];
        }
    } else if ((D_882345F4[9] == 0) || (D_882345F4[0x26] & 1)) {
        state.enabled = 1;
        state.flags[7] = 1;
        state.flags[6] = state.flags[7];
        if (D_882345F4[0x26] & 1) {
            state.flags[5] = 1;
            // FAKE: the inner assignment holds both stores in one register; two separate
            // statements abandon the match (465).
            a3 = (state.flags[4] = state.flags[5]);
            state.flags[1] = a3;
        }
    }
    if (func_80063754(D_882345F4[9]) == 0) {
        state.enabled = 1;
        state.flags[8] = 1;
    }
    func_88002AA8(((u8 *)D_88234820) + 4, 0, ((u8 *)D_88234820) + 0x38, 9, 8, 1, 6, 15, 16, 13, 16, 2, D_88234748,
                  &state);
    *((void **)D_88234820) = (void *)((func_88004804(((u8 *)D_88234820) + 4, 0, 0xA8, arg1, 0, 1, 0xDC, 0xDC, 0xB4,
                                                    &func_8822128C, &func_8822157C, &func_882211D0, &func_882211F8, 0,
                                                    0) * 0x4C) + D_8800ED50);
    D_880068B4 = 0;
}
/* mkdraft:func_882215A8 end */
#endif
