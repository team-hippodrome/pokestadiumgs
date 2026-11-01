#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_8AF13B30 begin */
/* m2c field-access helper (see matching_notes/TECHNIQUES.md). */
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
extern u8 D_8AF31E40;
extern void *func_8004B7A4(s32 arg0);
extern s32 func_8004C54C(s32 index,s32 value);
extern s32 func_8004C594(s32 index,s32 value);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern void *func_8004C8A0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_8AF00020(void);
extern int sprintf(char *, const char *, ...);

extern s32 D_8AF26940;
extern s8 D_8AF297B0;
extern s8 D_8AF297B4;
extern s8 D_8AF297B8;
extern s8 D_8AF297BC;
extern s32 D_8AF297C0;
extern s32 D_8AF297C4;
extern u8 D_8AF31E41;
extern void *D_8AF32E10;
extern void *D_8AF32E14;
extern s8 D_8AF32E18;
extern s8 D_8AF32F18;
extern s8 D_8AF33018;
extern s8 D_8AF33118;
extern s8 D_8AF33218;
extern s8 D_8AF33318;
extern s8 D_8AF33418;
extern s8 D_8AF33518;
extern s8 *D_8AF33618;
extern s8 *D_8AF3361C;
extern s32 D_8AF33620;
extern s16 D_8AF33624;



void func_8AF13B30(void *arg0) {
    u8 temp_a2;
    u8 temp_a2_10;
    u8 temp_a2_2;
    u8 temp_a2_3;
    u8 temp_a2_4;
    /* FAKE: without the initializer this object scores 150 (30 a2/a3
     * register swaps in the arg0[4..7] chain). The stored 0 is never read;
     * it splits the block so uopt keeps var_a3 in a3 across the chain. */
    s32 temp_a2_5 = 0;
    s32 temp_a2_6;
    s32 temp_a2_7;
    u8 temp_a2_8;
    u8 temp_a2_9;
    s32 var_a3;

    temp_a2 = M2C_FIELD(arg0, u8 *, 0);
    if (temp_a2 == 0) {
        sprintf(&D_8AF32E18, D_8AF3361C, temp_a2);
    } else if (temp_a2 == 1) {
        sprintf(&D_8AF32E18, D_8AF33618, temp_a2);
    } else {
        sprintf(&D_8AF32E18, &D_8AF297B0, temp_a2);
    }
    temp_a2_2 = M2C_FIELD(arg0, u8 *, 1);
    if (temp_a2_2 == 0) {
        sprintf(&D_8AF32F18, D_8AF3361C, temp_a2_2);
    } else if (temp_a2_2 == 1) {
        sprintf(&D_8AF32F18, D_8AF33618, temp_a2_2);
    } else {
        sprintf(&D_8AF32F18, &D_8AF297B4, temp_a2_2);
    }
    temp_a2_3 = M2C_FIELD(arg0, u8 *, 2);
    if (temp_a2_3 == 0) {
        sprintf(&D_8AF33018, D_8AF3361C, temp_a2_3);
    } else if (temp_a2_3 == 1) {
        sprintf(&D_8AF33018, D_8AF33618, temp_a2_3);
    } else {
        sprintf(&D_8AF33018, &D_8AF297B8, temp_a2_3);
    }
    temp_a2_4 = M2C_FIELD(arg0, u8 *, 3);
    if (temp_a2_4 == 0) {
        sprintf(&D_8AF33118, D_8AF3361C, temp_a2_4);
    } else if (temp_a2_4 == 1) {
        sprintf(&D_8AF33118, D_8AF33618, temp_a2_4);
    } else {
        sprintf(&D_8AF33118, &D_8AF297BC, temp_a2_4);
    }
    var_a3 = M2C_FIELD(arg0, u8 *, 4);
    if ((s32) var_a3 >= 0x33) {
        func_8004C594(2, var_a3 - 0x32);
        var_a3 = M2C_FIELD(arg0, u8 *, 4);
    } else if ((s32) var_a3 > 0) {
        func_8004C594(2, (s32) var_a3);
        var_a3 = M2C_FIELD(arg0, u8 *, 4);
    } else {
        temp_a2_5 = M2C_FIELD(arg0, u8 *, 5);
        if ((s32) temp_a2_5 >= 0x33) {
            func_8004C594(2, temp_a2_5 - 0x32);
            var_a3 = M2C_FIELD(arg0, u8 *, 4);
        } else if ((s32) temp_a2_5 > 0) {
            func_8004C594(2, (s32) temp_a2_5);
            var_a3 = M2C_FIELD(arg0, u8 *, 4);
        } else {
            temp_a2_6 = M2C_FIELD(arg0, u8 *, 6);
            if ((s32) temp_a2_6 >= 0x33) {
                func_8004C594(2, temp_a2_6 - 0x32);
                var_a3 = M2C_FIELD(arg0, u8 *, 4);
            } else if ((s32) temp_a2_6 > 0) {
                func_8004C594(2, (s32) temp_a2_6);
                var_a3 = M2C_FIELD(arg0, u8 *, 4);
            } else {
                temp_a2_7 = M2C_FIELD(arg0, u8 *, 7);
                if ((s32) temp_a2_7 >= 0x33) {
                    func_8004C594(2, temp_a2_7 - 0x32);
                    var_a3 = M2C_FIELD(arg0, u8 *, 4);
                } else if ((s32) temp_a2_7 > 0) {
                    func_8004C594(2, (s32) temp_a2_7);
                    var_a3 = M2C_FIELD(arg0, u8 *, 4);
                }
            }
        }
    }
    if (var_a3 == 0) {
        sprintf(&D_8AF33218, D_8AF3361C);
    } else if ((s32) var_a3 < 0x33) {
        func_8004C8A0(&D_8AF33218, 0x100, 0x3B, 0x39);
    } else {
        func_8004C8A0(&D_8AF33218, 0x100, 0x3B, 0x3A);
    }
    temp_a2_8 = M2C_FIELD(arg0, u8 *, 5);
    if (temp_a2_8 == 0) {
        sprintf(&D_8AF33318, D_8AF3361C, temp_a2_8);
    } else if ((s32) temp_a2_8 < 0x33) {
        func_8004C8A0(&D_8AF33318, 0x100, 0x3B, 0x39);
    } else {
        func_8004C8A0(&D_8AF33318, 0x100, 0x3B, 0x3A);
    }
    temp_a2_9 = M2C_FIELD(arg0, u8 *, 6);
    if (temp_a2_9 == 0) {
        sprintf(&D_8AF33418, D_8AF3361C, temp_a2_9);
    } else if ((s32) temp_a2_9 < 0x33) {
        func_8004C8A0(&D_8AF33418, 0x100, 0x3B, 0x39);
    } else {
        func_8004C8A0(&D_8AF33418, 0x100, 0x3B, 0x3A);
    }
    temp_a2_10 = M2C_FIELD(arg0, u8 *, 7);
    if (temp_a2_10 == 0) {
        sprintf(&D_8AF33518, D_8AF3361C, temp_a2_10);
    } else if ((s32) temp_a2_10 < 0x33) {
        func_8004C8A0(&D_8AF33518, 0x100, 0x3B, 0x39);
    } else {
        func_8004C8A0(&D_8AF33518, 0x100, 0x3B, 0x3A);
    }
    if ((M2C_FIELD(arg0, s16 *, 8) > 0) || (M2C_FIELD(arg0, s16 *, 0xA) > 0)) {
        M2C_FIELD(D_8AF32E10, u16 *, 2) = (u16) (M2C_FIELD(D_8AF32E10, u16 *, 2) | 2);
        if (M2C_FIELD(arg0, s16 *, 8) > 0) {
            M2C_FIELD(D_8AF32E10, s16 *, 0x32) = 0xA7;
        } else if (M2C_FIELD(arg0, s16 *, 0xA) > 0) {
            if (func_8AF00020() != 0) {
                M2C_FIELD(D_8AF32E10, s16 *, 0x32) = 0x10F;
            } else {
                M2C_FIELD(D_8AF32E10, u16 *, 2) = (u16) (M2C_FIELD(D_8AF32E10, u16 *, 2) & 0xFFFD);
            }
        }
    } else {
        M2C_FIELD(D_8AF32E10, u16 *, 2) = (u16) (M2C_FIELD(D_8AF32E10, u16 *, 2) & 0xFFFD);
    }
    if ((M2C_FIELD(arg0, s16 *, 0xC) > 0) && (func_8AF00020() != 0)) {
        M2C_FIELD(D_8AF32E14, u16 *, 2) = (u16) (M2C_FIELD(D_8AF32E14, u16 *, 2) | 2);
    } else {
        M2C_FIELD(D_8AF32E14, u16 *, 2) = (u16) (M2C_FIELD(D_8AF32E14, u16 *, 2) & 0xFFFD);
    }
    func_8004C54C(0x33, (s32) &D_8AF32E18);
    func_8004C54C(0x34, (s32) &D_8AF32F18);
    func_8004C54C(0x37, (s32) &D_8AF33218);
    func_8004C54C(0x38, (s32) &D_8AF33318);
    if (D_8AF26940 != 0) {
        func_8004C54C(0x35, (s32) &D_8AF33018);
        func_8004C54C(0x36, (s32) &D_8AF33118);
        func_8004C54C(0x39, (s32) &D_8AF33418);
        func_8004C54C(0x3A, (s32) &D_8AF33518);
    } else {
        func_8004C54C(0x35, D_8AF33620);
        func_8004C54C(0x36, D_8AF33620);
        func_8004C54C(0x39, D_8AF33620);
        func_8004C54C(0x3A, D_8AF33620);
        M2C_FIELD(D_8AF32E10, u16 *, 2) = (u16) (M2C_FIELD(D_8AF32E10, u16 *, 2) & 0xFFFD);
    }
    if (func_8AF00020() == 0) {
        func_8004C54C(0x36, (s32) &D_8AF297C0);
        func_8004C54C(0x3A, (s32) &D_8AF297C4);
    }
    func_8004C594(3, (s32) D_8AF33624);
    func_8004C54C(0x1D, func_8004C874(6, D_8AF31E40 - 1));
    if ((s32) D_8AF31E41 <= 0) {
        func_8004C54C(0x19, (s32) D_8AF3361C);
        return;
    }
    func_8004C54C(0x19, func_8004B7A4((s32) D_8AF31E41));
}
/* mkdraft:func_8AF13B30 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_201DA0/func_8AF141E8.s")

typedef struct {
    u32 unk_00[321];
} unk_func_8AF145B4;

void func_8AF145B4(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7,
                   u8 arg8, u8 arg9, u8 arg10, s32 arg11, s32 arg12, const unk_func_8AF145B4* arg13) {
    *(s32*)(arg0 + 24) = arg1;
    *(s32*)(arg0 + 8) = arg2;
    *(s32*)(arg0 + 12) = arg3;
    *(s32*)(arg0 + 16) = arg4;
    arg0[34] = arg5;
    arg0[35] = arg6;
    arg0[36] = arg7;
    arg0[37] = arg8;
    arg0[38] = arg9;
    arg0[39] = arg10;
    *(s32*)arg0 = arg11;
    *(s32*)(arg0 + 20) = -1;
    *(s32*)(arg0 + 28) = arg12;
    *(unk_func_8AF145B4*)(arg0 + 40) = *arg13;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_201DA0/func_8AF14648.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_201DA0/func_8AF14BE8.s")

extern u8 *D_8AF27130;
extern u8 D_8AF33628[];
extern u8 D_8AF336A0[];
extern u8 D_8AF33718[];
void func_8AF14D3C(void) {
    s32 pad1; // FAKE: unused stack padding (with pad2); diff score 10 without both.
    u8 *state;
    u8 *sprite;
    s32 pad2; // FAKE: see pad1.
    s32 x;
    s32 y;

    state = D_8AF27130;
    sprite = state + 0x28;
    x = *(s16 *)(state + 0x34) * *(s32 *)(state + 0x4C) + *(s32 *)(state + 0x5C) + *(s32 *)(state + 8) - 4;
    y = *(s16 *)(state + 0x36) * *(s32 *)(state + 0x50) + *(s32 *)(state + 0x60) + *(s32 *)(state + 0xC) - 2;
    func_8AC007B8(*(s32 *)(state + 8), *(s32 *)(state + 0xC) + 5, *(s16 *)(state + 0x28), *(s16 *)(state + 0x2A) - 50);
    func_8AF02F18(state);
    func_8AC00738();
    func_8004B314(x, y, 88, 68);
    if (func_8AC0665C(D_8AF33718, *(s16 *)(sprite + 0x10)) != 0) {
        func_8AC05F00(D_8AF33628);
    }
    if (func_8AC0672C(D_8AF33718, *(s16 *)(sprite + 0x10)) != 0) {
        func_8AC05F00(D_8AF336A0);
    }
}
#endif
