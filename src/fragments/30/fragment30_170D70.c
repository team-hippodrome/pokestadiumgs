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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/30/fragment30_170D70/func_881038A0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/30/fragment30_170D70/func_88104214.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/30/fragment30_170D70/func_88104730.s")
#endif
