#include "global.h"
#include "controller.h"


#ifdef VERSION_US

typedef struct unk_func_88103D30 unk_func_88103D30;

typedef struct {
    unk_func_88103D30 *owner;
    u8 index;
    u8 unk_05[91];
} unk_func_88103D30_entry;

struct unk_func_88103D30 {
    u8 unk_00[12];
    s32 unk_0C;
    unk_func_88103D30_entry **entries;
    u8 unk_14;
    u8 count;
};

// A cursor list: func_88002720 moves cursor with the D-pad within [0, count). func_88103BB8 frees
// count pointers from the arrays at unk_D_88104EA0.unk_38 (lists[0]) and unk_3C (lists[1]).
//@src/fragments/29/fragment29_168330.c
typedef struct {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ u16 count;
    /* 0x06 */ s16 cursor;
    /* 0x08 */ u8 unk_08[8];
} unk_D_88104EA0_list; // size = 0x10

typedef struct {
    /* 0x000 */ u8 unk_00[12];
    /* 0x00C */ unk_D_88104EA0_list lists[2];
    /* 0x02C */ u8 unk_2C[20];
    /* 0x040 */ s32 unk_40;
    /* 0x044 */ s16 unk_44; // 0-2; func_88103DC8 passes it to func_88002720 with count 3
    /* 0x046 */ u8 unk_46[2];
    /* 0x048 */ u8 unk_48[90];
    /* 0x0A2 */ u8 selected;
    /* 0x0A3 */ u8 unk_A3;
    /* 0x0A4 */ unk_func_88103D30_entry entries[2];
    /* 0x164 */ s32 unk_164;
    /* 0x168 */ s32 unk_168;
    /* 0x16C */ u8 unk_16C;
    /* 0x16D */ s8 unk_16D;
    /* 0x16E */ s8 unk_16E;
    /* 0x16F */ s8 unk_16F; // copied to D_8800EF40 every frame by func_88103DC8
} unk_D_88104EA0;

extern unk_D_88104EA0 *D_88104EA0;

/* mkdraft:func_881038A0 begin */
extern u8 D_88104E50;
extern u8 D_88104E51;
extern u8 D_88104E52;
extern u8 D_88104E53;
extern u8 D_88104E54;
extern u8 D_88104E55;
extern u8 D_88104E56;
extern u8 D_88104E57;
extern u8 D_88104E80[];
extern void func_80035700(u32);
extern u32 func_8003570C(void);
extern void *func_8004B7A4(s32);
extern void *func_8004C874(s32, s32);
extern u8 *func_80060D70(u8 *, u8 *);
extern void func_800619E8(u8 *);
extern s32 func_80061B88(s32, u16);
extern void func_80061F44(u8 *);
extern u8 func_80062E10(u8);
extern s8 *HAL_Strcpy(s8 *, s8 *);


void func_881038A0(void) {
    u8 *mon;
    s32 i;

    // The file's own `extern unk_D_88104EA0 *D_88104EA0` sits below this function, so the
    // state pointer is loaded through the byte array that precedes it: 0x88104EA0 is the
    // word at D_88104E80 + 0x20. IDO folds the addend into the %lo relocation, giving the
    // same lui/lw pair the target has.
    mon = *(u8 **)(D_88104E80 + 0x20);
    mon += (*(u8 **)(D_88104E80 + 0x20))[0xA2] * 0x60 + 0xAC;
    _bzero(mon, 0x58);
    if ((*(u8 **)(D_88104E80 + 0x20))[0xA3] == 0x53) {
        mon[2] = D_88104E50;
        mon[3] = D_88104E51;
        mon[4] = D_88104E52;
        mon[5] = D_88104E53;
        mon[1] = 0xAE;
    } else {
        mon[2] = D_88104E54;
        mon[3] = D_88104E55;
        mon[4] = D_88104E56;
        mon[5] = D_88104E57;
        mon[1] = 0x96;
    }
    for (i = 0; i < 4; i++) {
        // FAKE: the mask emits no instruction (the destination is a byte), but its temporary
        // advances the function's temp-register counter by one, which is what the target's
        // tail needs (li t3,0x7d0 ... lbu t6,0x1d ... li t7,0x7f); without it every tail
        // temporary shifts down one register (diff score 90).
        mon[i + 0x18] = func_80062E10(mon[i + 2]) & 0xFF;
    }
    func_80035700(guRandom() + osGetCount());
    *(u16 *)(mon + 0x16) = func_8003570C();
    mon[0] = (*(u8 **)(D_88104E80 + 0x20))[0xA3];
    *(u16 *)(mon + 6) = 0x7D0;
    mon[0x1D] = 5;
    mon[0x1C] = 0x46;
    *(u32 *)(mon + 8) = func_80061B88(mon[0], mon[0x1D]);
    mon[0x21] = mon[0x1D];
    mon[0x22] = 0x7F;
    HAL_Strcpy((s8 *)(mon + 0x34), func_8004B7A4(mon[0]));
    HAL_Strcpy((s8 *)(mon + 0x40), func_8004C874(0x1E, 0x1A));
    func_80060D70(mon + 0x4C, mon + 0x40);
    func_800619E8(mon);
    func_80061F44(mon);
}
/* mkdraft:func_881038A0 end */

/* mkdraft:func_88103A64 begin */
// Transfer Pak check for the GB Tower screen. While the session flag unk_168 is set it reruns the
// func_80052ECC/func_80054E48 setup for entry 3, or for entries 1 and 2 when unk_44 selects the
// second list; otherwise it reads the pak status of port D_88006868, requires the pak to stay
// inserted and calls func_8005ADD8 when the status is nonzero. Returns the status (1 when the
// unk_44 == 2 path runs); a zero result clears unk_168 so the screen returns to the pak prompt.
extern s8 D_88006868;
extern s32 func_8005B120(s32);
extern void GbSave_RequirePakPresent(s32);
extern void func_8005ADD8(s32);
extern void func_80054A24(u8, s32);
extern void func_80052ECC(s32);
extern s32 func_80054E48(s32);
extern void func_881038A0(void);
extern void func_88A0057C(void);
extern void func_881000B8(void);



s32 func_88103A64(void) {
    s32 result;
    u32 i;

    result = 1;
    if (D_88104EA0->unk_168 != 0) {
        func_881038A0();
        func_88A0057C();
        func_80054A24(D_88104EA0->selected, 0);
        func_80052ECC(3);
        func_80054E48(3);
    }
    if (D_88104EA0->unk_44 == 2) {
        if (D_88104EA0->unk_168 != 0) {
            for (i = 0; i < 2; i++) {
                func_80052ECC(i + 1);
                func_80054E48(i + 1);
            }
        }
    } else {
        result = func_8005B120(D_88006868);
        if (D_88104EA0->unk_168 == 0) {
            GbSave_RequirePakPresent(D_88006868);
        }
        if (result != 0) {
            func_8005ADD8(D_88006868);
        }
    }
    if (result != 0) {
        func_881000B8();
    } else {
        D_88104EA0->unk_168 = 0;
    }
    return result;
}
/* mkdraft:func_88103A64 end */

extern void Input_SetRepeatController(void *);
extern s32 D_880068B8;
void func_88103B90(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(void *);
void func_88103BB8(void) {
    u32 var_s0;
    s32 offset;
    void *state;
    state = D_88104EA0;
    var_s0 = 0;
    offset = 0;
    if (*(u16 *)((u8 *)state + 0x10) != 0) {
        do {
            Util_Free(*(void **)((u8 *)*(void **)((u8 *)state + 0x38) + offset));
            state = D_88104EA0;
            var_s0 += 1;
            offset += 4;
        } while (var_s0 < *(u16 *)((u8 *)state + 0x10));
        var_s0 = 0;
    }
    if (*(u16 *)((u8 *)state + 0x20) != 0) {
        offset = 0;
        do {
            Util_Free(*(void **)((u8 *)*(void **)((u8 *)state + 0x3C) + offset));
            state = D_88104EA0;
            var_s0 += 1;
            offset += 4;
        } while (var_s0 < *(u16 *)((u8 *)state + 0x20));
    }
    Util_Free(*(void **)((u8 *)state + 0x18));
    Util_Free(*(void **)((u8 *)D_88104EA0 + 0x28));
    Util_Free(*(void **)((u8 *)D_88104EA0 + 0x38));
    Util_Free(*(void **)((u8 *)D_88104EA0 + 0x3C));
    Util_Free(D_88104EA0);
}

extern void func_88103BB8(void);
extern s32 D_880068B4;
void func_88103CAC(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    func_88103BB8();
}

extern void func_88004990(s32, s32);
void func_88103CE0(void) {
    func_88004990(**(u8 **)((u8 *)D_88104EA0 + 0), 0);
    func_88004990(**(u8 **)((u8 *)D_88104EA0 + 4), 0);
    D_880068B8 = 1;
}

extern void func_800226C0(s32);
void func_88103D30(unk_func_88103D30 *arg0) {
    unk_func_88103D30_entry **entry;
    unk_D_88104EA0 *state;

    entry = &arg0->entries[arg0->count];
    func_800226C0(333);
    ((unk_D_88104EA0 *)D_88104EA0)->unk_164 = 1;
    state = D_88104EA0;
    *entry = &state->entries[state->selected];
    (*entry)->owner = arg0;
    (*entry)->index = arg0->count;
    arg0->count++;
    arg0->unk_0C = 1;
}

typedef struct {
    /* 0x00 */ u8 unk_00[16];
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 unk_11[19];
    /* 0x24 */ u8 unk_24;
} unk_D_88A01C30;

extern s8 D_88006868;
extern s8 D_8800EF40;
extern s8 D_8800EF41;
extern unk_D_88A01C30 *D_88A01C30;
extern unk_func_88103D30 *D_88A01C34;
extern void func_88002720(s16 *cursor, u16 count, void *arg2);
extern s32 func_8005A228(s8);
extern s32 func_88103A64(void);
// Per-frame update. unk_16C counts up to 2 and then runs the func_8005A228 checks on port
// D_88006868 that set the result byte unk_16F; with unk_16C 0 it handles input: after
// func_88103D30 set unk_164, A, B or a D-pad button (0xCF00) clears it; otherwise B and A
// act on the list chosen by unk_44 and the D-pad moves a cursor through func_88002720.
// unk_16F is copied to D_8800EF40, and D_88006868 to D_8800EF41 unless unk_16F is -1.
void func_88103DC8(void) {
    s32 pad; // FAKE: unused stack slot at sp+0x24; diff score 26 without it.
    unk_D_88104EA0_list *list;
    unk_func_88103D30 *target;
    s32 row;
    s32 pressed;

    if (D_88104EA0->unk_16C != 0) {
        if (D_88104EA0->unk_16C == 2) {
            if (D_88104EA0->unk_16D == 1) {
                switch (func_8005A228(D_88006868)) {
                    case 1:
                        D_88104EA0->unk_16F = 1;
                        break;
                    case 3:
                        D_88104EA0->unk_16F = 3;
                        break;
                    case 2:
                        D_88104EA0->unk_16D = 2;
                        D_88104EA0->unk_16E = 3;
                        D_88104EA0->unk_16F = 0;
                        break;
                }
            }
            if (D_88104EA0->unk_16D == 2) {
                D_88104EA0->unk_16E--;
                if (D_88104EA0->unk_16E == 1) {
                    func_800226C0(330);
                } else if (D_88104EA0->unk_16E <= 0) {
                    D_88104EA0->unk_16D = 0;
                    D_88104EA0->unk_16E = 0;
                }
            }
            if (D_88104EA0->unk_16D == 0) {
                if (func_88103A64() != 0) {
                    func_800226C0(17);
                    func_88103CE0();
                    D_88104EA0->unk_16F = -1;
                } else {
                    D_88104EA0->unk_16D = 1;
                    func_800226C0(5);
                    D_88104EA0->unk_16F = 2;
                    switch (func_8005A228(D_88006868)) {
                        case 1:
                            D_88104EA0->unk_16F = 1;
                            break;
                        case 3:
                            D_88104EA0->unk_16F = 3;
                            break;
                    }
                }
            }
        } else {
            D_88104EA0->unk_16C++;
        }
    } else {
        if (D_88104EA0->unk_164 != 0) {
            if (D_80087200->buttonsPressed & 0xCF00) {
                func_800226C0(330);
                D_88104EA0->unk_164 = 0;
                D_88104EA0->unk_16C = 1;
            }
        } else {
            row = D_88104EA0->unk_44;
            switch (row) {
                case 1:
                    list = &D_88104EA0->lists[0];
                    target = D_88A01C34 + D_88A01C30->unk_10 + list->cursor;
                    break;
                case 2:
                    list = &D_88104EA0->lists[1];
                    target = D_88A01C34 + D_88A01C30->unk_24 + D_88A01C30->unk_10 + list->cursor;
                    break;
            }
            if (D_88104EA0->unk_40 != 0) {
                pressed = D_80087200->buttonsPressed;
                if (pressed & B_BUTTON) {
                    func_800226C0(3);
                    func_88103CE0();
                } else if (pressed & A_BUTTON) {
                    // FAKE: rereads unk_44 instead of testing row; diff score 1265 with row.
                    if (D_88104EA0->unk_44 == 0) {
                        func_88103D30(D_88A01C34);
                    } else {
                        func_800226C0(2);
                        D_88104EA0->unk_40 = 0;
                    }
                } else {
                    func_88002720(&D_88104EA0->unk_44, 3, D_88104EA0->unk_48);
                }
            } else {
                pressed = D_80087200->buttonsPressed;
                if (pressed & B_BUTTON) {
                    func_800226C0(3);
                    D_88104EA0->unk_40 = 1;
                } else if (pressed & A_BUTTON) {
                    func_88103D30(target);
                } else if (row == 1 || row == 2) {
                    func_88002720(&list->cursor, list->count, list->unk_08);
                }
            }
        }
    }
    D_8800EF40 = D_88104EA0->unk_16F;
    if (D_88104EA0->unk_16F != -1) {
        D_8800EF41 = D_88006868;
    }
}

/* mkdraft:func_88104214 begin */
extern s32 func_800472E0(u8 *arg0);
extern s32 func_80048E30(u8 *state, s32 x, s32 y, const char *text, s32 draw);
extern void func_80049064(s32 x, s32 y, s32 mode, const char *text);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004989C(s32 arg0);
extern s32 func_80049290(s32 font, s32 flags, const char *text);
extern void func_8004D5B8(s32 x, s32 y, s32 alignment, const char* format, ...);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern void *func_8004C8A0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_8004D334(s32 archive, s32 entry);
extern void func_8004D40C(s32 arg0);
extern s32 func_8800005C(void);
extern void func_880009A8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
extern void func_88000FC4(s32, s32, s32, s32, s16, s16);
extern void func_88002820(s32, s32, s32, s32, s32, s32, void *);
extern void func_88002BA0(u8 arg0, u8 arg1, u8 arg2);
extern void *func_8004B7A4(s32);
extern s32 func_8004C54C(s32 arg0, s32 arg1);
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern u8 *D_8800687C;
extern u8 D_88104E70[];


void func_88104214(void)
{
    u32 i;
    s32 x;
    s32 y;
    s16 row;
    u8 *list;
    u8 *entry;
    s32 var;
    u8 pad[4]; // FAKE: unused stack slot; without it the frame is 0x160, sp48 sits at sp+0x44, and the diff score is 95.
    u8 sp48[0x100];

    if (*(u8 *)((u8 *)D_88104EA0 + 0x16C) != 0) {
        func_800498C4();
        func_800496A4(8, 1);
        func_80049064(0xA9, 0xC1, 1, func_8004C874(0x1E, 0x1B));
        func_800499EC();
        return;
    }
    switch (*(s16 *)((u8 *)D_88104EA0 + 0x44)) {
    case 1:
        list = (u8 *)D_88104EA0 + 0xC;
        entry = 0x18 * D_88A01C30->unk_10 + (u8 *)D_88A01C34;
        break;
    case 2:
        list = (u8 *)D_88104EA0 + 0x1C;
        entry = 0x18 * D_88A01C30->unk_24 + (u8 *)D_88A01C34 + 0x18 * D_88A01C30->unk_10;
        break;
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_88002BA0(0xFF, 0xFF, 0xFF);
    func_8004D334(0xEF, 0);
    if (*(s32 *)((u8 *)D_88104EA0 + 0x164) == 0 && func_8800005C() == 0) {
        func_8004D40C(2);
        func_8004D5B8(func_80049290(8, 1, *(s32 *)((u8 *)D_88104EA0 + 0x54)) + 0x50,
            0xC9, 0, (const char *)D_88104E70, D_88A01C34->count, D_88A01C34->unk_14);
    }
    switch (*(s16 *)((u8 *)D_88104EA0 + 0x44)) {
    case 1:
    case 2:
        x = *(u16 *)((u8 *)D_88104EA0 + 0x34) + 0x139;
        y = 0x83;
        for (i = 0; i < *(u16 *)(list + 4); i++) {
            func_88000FC4(x, y, 1, 2, entry[0x15], entry[0x14]);
            y += 0x14;
            entry += 0x18;
        }
        break;
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    func_800498C4();
    func_800496A4(4, 1);
    switch (*(s16 *)((u8 *)D_88104EA0 + 0x44)) {
    case 1:
    case 2:
        func_88002820(0x133, 0x82, 0, *(s32 *)list, *(u16 *)(list + 4),
            *(s16 *)((u8 *)D_88104EA0 + 0x32), list + 8);
        break;
    }
    func_800496A4(8, 1);
    if (*(s32 *)((u8 *)D_88104EA0 + 0x164) != 0) {
        var = func_800472E0(func_8004C874(0x1E, 0x19));
        var = var * 0x1A - 6;
        func_8004989C(0x1A);
        func_8004C54C(0x19, func_8004B7A4(*(u8 *)((u8 *)D_88104EA0 + 0xA3)));
        func_8004C54C(0x4B, ((s32 *)((u8 *)D_88104EA0 + 0x54))[*(s16 *)((u8 *)D_88104EA0 + 0x44)]);
        func_80049064(0xA9, 0xCB - (var >> 1), 1, func_8004C8A0(sp48, 0x100, 0x1E, 0x19));
    } else {
        func_8004989C(0x1A);
        func_80048E30(D_8800687C, 0x4A, 0x81, (u8 *)D_88104EA0 + 0x62, 1);
        if (func_8800005C() != 0) {
            func_80048E30(D_8800687C, 0x4A, 0xF7, *(u8 **)((u8 *)D_88104EA0 + 0x5C), 1);
        } else {
            func_88002820(0x4A, 0xC3, 0, (u8 *)D_88104EA0 + 0x54, 3, 6, (u8 *)D_88104EA0 + 0x48);
        }
    }
    func_800499EC();
    if (*(s32 *)((u8 *)D_88104EA0 + 0x164) == 0) {
        func_880009A8(*(s32 *)((u8 *)D_88104EA0 + 0x40), 0x4A,
            *(s16 *)((u8 *)D_88104EA0 + 0x44) * 0x1A + 0xC3,
            *(s16 *)((u8 *)D_88104EA0 + 0x60), 0x14, 5, 5);
    }
    if (*(s32 *)((u8 *)D_88104EA0 + 0x40) == 0) {
        row = (*(s16 *)((u8 *)D_88104EA0 + 0x44) == 1) ? *(s16 *)((u8 *)D_88104EA0 + 0x12) : *(s16 *)((u8 *)D_88104EA0 + 0x22);
        func_880009A8(*(s32 *)((u8 *)D_88104EA0 + 0x164) == 0, 0x133, row * 0x14 + 0x82,
            *(s16 *)((u8 *)D_88104EA0 + 0x36), 0x10, 7, 5);
    }
}
/* mkdraft:func_88104214 end */


extern void *Util_Malloc(s32);
extern s32 func_8005CB38(s32, s32);
extern s32 func_8005EE88(s32, s32, void *);
extern s32 func_800532C4(s32);
extern s32 func_80053524(s32, void *);
extern s32 func_8800005C(void);
extern void *func_8004C874(s32, s32);
extern s32 func_8004C54C(s32, s32);
extern s32 func_88004804(void *, s32, s32, s32, s32, s32, s32, s32, s32, void *, void *, void *, void *, s32, s32);
extern void func_88103DC8(void);
extern void func_88104214(void);
extern s32 D_880068B4;
extern u8 D_88000E4C[];
typedef struct {
    u8 unk_00[0x4C];
} unk_D_8800ED50;
extern unk_D_8800ED50 D_8800ED50[];



s32 func_88104730(u8 arg0) {
    u32 i;
    u32 j;
    u32 off;
    u8 *list;
    u8 *entry;

    D_88104EA0 = Util_Malloc(0x170);
    if (arg0 == 0x53) {
        ((u8 *)D_88104EA0)[0xA2] = 0;
    } else {
        ((u8 *)D_88104EA0)[0xA2] = 1;
    }
    ((u8 *)D_88104EA0)[0xA3] = arg0;
    *(s32 *)((u8 *)D_88104EA0 + 0x8) = 0;
    *(s32 *)((u8 *)D_88104EA0 + 0x2C) = 4;
    *(s16 *)((u8 *)D_88104EA0 + 0x30) = 1;
    *(s16 *)((u8 *)D_88104EA0 + 0x32) = 4;
    entry = D_88A01C30->unk_10 * 0x18 + (u8 *)D_88A01C34;
    for (i = 0; i < 2; i++) {
        j = 0;
        if (i == 0) {
            list = (u8 *)D_88104EA0 + 0xC;
            *(u16 *)(list + 4) = func_8005CB38(D_88006868, 0x21);
            *(void **)((u8 *)D_88104EA0 + 0x38) = Util_Malloc(*(u16 *)(list + 4) * 4);
            if (*(u16 *)(list + 4) != 0) {
                off = 0;
                do {
                    *(void **)((u8 *)*(void **)((u8 *)D_88104EA0 + 0x38) + off) = Util_Malloc(9);
                    func_8005EE88(D_88006868, j, *(void **)((u8 *)*(void **)((u8 *)D_88104EA0 + 0x38) + off));
                    j++;
                    off += 4;
                } while (j < *(u16 *)(list + 4));
                j = 0;
            }
            *(void **)list = *(void **)((u8 *)D_88104EA0 + 0x38);
        } else {
            list = (u8 *)D_88104EA0 + 0x1C;
            *(u16 *)(list + 4) = func_800532C4(0x11);
            *(void **)((u8 *)D_88104EA0 + 0x3C) = Util_Malloc(*(u16 *)(list + 4) * 4);
            if (*(u16 *)(list + 4) != 0) {
                off = 0;
                do {
                    *(void **)((u8 *)*(void **)((u8 *)D_88104EA0 + 0x3C) + off) = Util_Malloc(0x12);
                    func_80053524(j, *(void **)((u8 *)*(void **)((u8 *)D_88104EA0 + 0x3C) + off));
                    j++;
                    off += 4;
                } while (j < *(u16 *)(list + 4));
                j = 0;
            }
            *(void **)list = *(void **)((u8 *)D_88104EA0 + 0x3C);
        }
        *(s16 *)(list + 6) = 0;
        *(s32 *)(list + 8) = 0;
        *(void **)(list + 0xC) = Util_Malloc(*(u16 *)(list + 4));
        if (*(u16 *)(list + 4) != 0) {
            do {
                if (*(u8 *)(entry + 0x14) == *(u8 *)(entry + 0x15)) {
                    *(s32 *)(list + 8) = 1;
                    ((u8 *)*(void **)(list + 0xC))[j] = 1;
                    if (j == *(s16 *)(list + 6)) {
                        *(s16 *)(list + 6) = *(s16 *)(list + 6) + 1;
                    }
                } else {
                    ((u8 *)*(void **)(list + 0xC))[j] = 0;
                }
                j++;
                entry += 0x18;
            } while (j < *(u16 *)(list + 4));
        }
    }
    *(s32 *)((u8 *)D_88104EA0 + 0x40) = 1;
    *(s16 *)((u8 *)D_88104EA0 + 0x44) = 0;
    _bzero((u8 *)D_88104EA0 + 0x50, 3);
    *(s32 *)((u8 *)D_88104EA0 + 0x48) = 0;
    *(u8 **)((u8 *)D_88104EA0 + 0x4C) = (u8 *)D_88104EA0 + 0x50;
    if (func_8800005C() != 0 || D_88A01C34->unk_14 == D_88A01C34->count) {
        *(s32 *)((u8 *)D_88104EA0 + 0x48) = 1;
        *(u8 *)((u8 *)D_88104EA0 + 0x50) = 1;
        *(s16 *)((u8 *)D_88104EA0 + 0x44) = 1;
    }
    if (func_8800005C() != 0 || *(u16 *)((u8 *)D_88104EA0 + 0x10) == *(s16 *)((u8 *)D_88104EA0 + 0x12)) {
        *(s32 *)((u8 *)D_88104EA0 + 0x48) = 1;
        *(u8 *)((u8 *)D_88104EA0 + 0x51) = 1;
        if (*(s16 *)((u8 *)D_88104EA0 + 0x44) == 1) {
            *(s16 *)((u8 *)D_88104EA0 + 0x44) = 2;
        }
    }
    if (*(u16 *)((u8 *)D_88104EA0 + 0x20) == *(s16 *)((u8 *)D_88104EA0 + 0x22)) {
        *(s32 *)((u8 *)D_88104EA0 + 0x48) = 1;
        *(u8 *)((u8 *)D_88104EA0 + 0x52) = 1;
        if (*(s16 *)((u8 *)D_88104EA0 + 0x44) == 2) {
            func_88103BB8();
            return 0;
        }
    }
    /* FAKE: dead copy of the func_88004804 result into the scratch local `off`;
       the copy is coalesced away, but its uop numbering makes IDO place the
       D_8800ED50 lui one slot before the index subu. Score without: 60. */
    off = func_88004804(NULL, 3, 0x35, 0x70, 0, 3, 0xFF, 0xFF, 0xFF, func_88103DC8, func_88104214, func_88103B90, func_88103CAC, 0, 0);
    *(void **)((u8 *)D_88104EA0 + 0) = &D_8800ED50[off];
    *(s16 *)((u8 *)*(void **)((u8 *)D_88104EA0) + 0x10) = 0xE9;
    *(s16 *)((u8 *)*(void **)((u8 *)D_88104EA0) + 0x12) = 0xB6;
    *(void **)((u8 *)D_88104EA0 + 4) = &D_8800ED50[func_88004804((u8 *)D_88104EA0 + 8, 1, 0x11E, 0x70, 0, 3, 0xFF, 0xFF, 0xFF, D_88000E4C, D_88000E4C, D_88000E4C, D_88000E4C, 0, 0)];
    D_880068B4 = 0;
    func_8004C54C(0x19, func_8004B7A4(arg0));
    func_8004C8A0((u8 *)D_88104EA0 + 0x62, 0x40, 0x1E, 0x15);
    j = 0;
    for (; j < 3; j++) {
        *(s32 *)((u8 *)D_88104EA0 + 0x54 + j * 4) = func_8004C874(0x1E, j + 0x16);
    }
    if (func_8800005C() != 0) {
        *(u16 *)((u8 *)D_88104EA0 + 0x60) = func_80049290(8, 1, *(void **)((u8 *)D_88104EA0 + 0x5C));
    } else {
        *(u16 *)((u8 *)D_88104EA0 + 0x60) = func_80049290(8, 1, *(void **)((u8 *)D_88104EA0 + 0x54)) + 0x22;
        j = 0;
        /* FAKE: keeps the max-loop counter web on s0/s1 (score without: 40). */
        off = j;
        do {
            *(u16 *)((u8 *)D_88104EA0 + 0x60) =
                (func_80049290(8, 1, *(void **)((u8 *)D_88104EA0 + 0x58 + off)) < *(u16 *)((u8 *)D_88104EA0 + 0x60))
                    ? *(u16 *)((u8 *)D_88104EA0 + 0x60)
                    : func_80049290(8, 1, *(void **)((u8 *)D_88104EA0 + 0x58 + off));
            off += 4;
        } while (off != 8);
    }
    *(s32 *)((u8 *)D_88104EA0 + 0x164) = 0;
    *(s32 *)((u8 *)D_88104EA0 + 0x168) = 1;
    *(u8 *)((u8 *)D_88104EA0 + 0x16C) = 0;
    *(u8 *)((u8 *)D_88104EA0 + 0x16D) = 0;
    *(u8 *)((u8 *)D_88104EA0 + 0x16E) = 0;
    *(s8 *)((u8 *)D_88104EA0 + 0x16F) = -1;
    return 1;
}
#endif
