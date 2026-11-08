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

extern u8 D_8AF31E40;
extern u8 D_8AF31E48[];
extern void *D_8AF32E10;
extern void _bzero(void *, s32);
extern s32 func_80064800(u8 arg0);
extern u8 func_80062F68(u8 arg0);
extern u8 func_80063014(u8 arg0);
extern s32 func_80063BF4(u8 arg0, u8 arg1);
extern s32 func_80063CC4(u8 arg0, u8 arg1);
extern s32 func_8AF00020(void);
extern s32 func_8AF0C5BC(s16 arg0, s16 arg1);
extern s32 Pokemon_CanLearnGen1Machine(u8 arg0, u8 arg1);

// arg0 selects one 14-byte record in D_8AF31E48; arg1 is an s16 key whose low byte
// func_80064800 uses as a lookup index. The record is cleared, then filled from the
// keyed entry list, then from three 58-value scans, and finally validated.


s32 func_8AF141E8(s16 arg0, s16 arg1) {
    s32 result;
    s32 one;
    s16 value;
    u8 *entry;
    u8 *table;
    u8 entry0;
    u8 entry2;

    result = 0;
    // FAKE: function-scope constant keeps the retail `li s7,1` and s7 colouring;
    // with every use replaced by the literal 1 the function scores 7008.
    one = 1;
    table = D_8AF31E48 + arg0 * 14;
    _bzero(table, 14);
    entry = (u8 *)func_80064800((u8)arg1);
    *(u16 *)((u8 *)D_8AF32E10 + 2) &= 0xFFFD;

    // The entry list is tested at the top of the loop; with the test folded into
    // the loop condition (`while (entry[1] != 0)`) the function scores 4155.
    while (1) {
        if (!entry[1]) break;
        // Only entries whose byte 1 equals D_8AF31E40 fill slots.
        if (D_8AF31E40 == entry[1]) {
            entry0 = entry[0];
            entry2 = entry[2];
            // 235/166 are the arg1 and D_8AF31E40 values of one excluded entry
            // class: byte values below 2 cannot set the high slots.
            if (!((s16)arg1 == 235 && D_8AF31E40 == 166 && entry0 >= 2)) {
                if (entry2 & 0x1) {
                    table[0] = entry0;
                    result = one;
                }
                if (entry2 & 0x2) {
                    table[1] = entry0;
                    result = one;
                }
                if (entry2 & 0x4) {
                    table[2] = entry0;
                    result = one;
                }
                if (entry2 & 0x40) {
                    if (entry0 >= 2) {
                        *(u16 *)(table + 8) = one;
                        result = one;
                    }
                }
                // Slots 3, 5 and 6 are filled only while func_8AF00020() is true.
                if (func_8AF00020() != 0) {
                    if (entry2 & 0x8) {
                        table[3] = entry0;
                        result = one;
                    }
                    if (entry2 & 0x20) {
                        if (entry0 >= 2) {
                            *(u16 *)(table + 10) = one;
                            result = one;
                        }
                    }
                    if (entry2 & 0x10) {
                        if (entry0 > 0) {
                            *(u16 *)(table + 12) = one;
                            result = one;
                        }
                    }
                }
            }
        }
        entry += 3;
    }

    // Each scan takes the first value in 1..57 that two predicates accept and whose
    // type (func_80063014) is D_8AF31E40; the value is stored in slot 4.
    for (value = one; value < 58; value++) {
        if (func_80063CC4((u8)arg1, (u8)value) != 0 &&
            D_8AF31E40 == func_80063014((u8)value)) {
            table[4] = value;
            result = one;
            break;
        }
    }

    for (value = one; value < 58; value++) {
        if (Pokemon_CanLearnGen1Machine((u8)arg1, (u8)value) != 0 &&
            D_8AF31E40 == func_80063014((u8)value)) {
            table[5] = value;
            result = one;
            break;
        }
    }

    for (value = one; value < 58; value++) {
        if (func_80063BF4((u8)arg1, (u8)value) != 0 &&
            D_8AF31E40 == func_80062F68((u8)value)) {
            table[6] = value;
            table[7] = value;
            result = one;
            break;
        }
    }

    // func_8AF00020() splits the validation in two. Slots 0..2 plus 4..6 are enough
    // when it is false; slot 3 and slot 7 are additionally required when it is true.
    if (func_8AF00020() == 0) {
        if (*(s16 *)(table + 8) != one) {
            goto done;
        }
        if (func_8AF0C5BC((s16)arg1, D_8AF31E40) != 0) {
            goto done;
        }
        // FAKE: the chains are rotated left by one operand so IDO emits the byte
        // loads in ascending address order (it otherwise emits the last operand's
        // load first). Plain 0|1|2 order scores 70.
        if ((table[1] | table[2] | table[0]) == 0 &&
            (table[5] | table[6] | table[4]) == 0) {
            return 0;
        }
        *(s16 *)(table + 8) = 0;
        *(s16 *)(table + 10) = 0;
    } else {
        // Either high slot being set is enough to continue.
        if (*(s16 *)(table + 8) != one && *(s16 *)(table + 10) != one) {
            goto done;
        }
        if (func_8AF0C5BC((s16)arg1, D_8AF31E40) != 0) {
            goto done;
        }
        // FAKE: same operand rotation as the branch above; natural order scores 70.
        if ((table[1] | table[2] | table[3] | table[0]) == 0 &&
            (table[5] | table[6] | table[7] | table[4]) == 0 &&
            *(s16 *)(table + 12) == 0) {
            return 0;
        }
        *(s16 *)(table + 8) = 0;
        *(s16 *)(table + 10) = 0;
    }
done:
    return result;
}

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

extern u8 *D_8AF27130;
extern s16 D_8AF2BDDC;
extern u8 D_8AF31E40;
extern u8 D_8AF33628[];
extern u8 D_8AF336A0[];
extern u8 D_8AF33718[];
extern void func_800476A0(u8 *arg0, s32 arg1);
extern s32 func_800476FC(s32 arg0, s32 arg1);
extern s32 func_80047738(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_8004C4B0(s32 value);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern s32 func_8004C8C0(u16 arg0);
extern s32 func_8004C990(s32 arg0, s32 arg1);
extern u8 func_80063804(u8 arg0);
extern s32 func_800643CC(s32 arg0, s32 arg1, s32 arg2);
extern void func_8AC02C80(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern void func_8AC05ED4(s32 arg0, s32 arg1, s32 arg2);
extern void func_8AC0651C(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
extern s32 func_8AC06D8C(s32 arg0, s32 arg1);
extern void func_8AC06E98(void *arg0);
extern s32 func_8AF00020(void);
extern s32 func_8AF003A8(s16 arg0);
extern void func_8AF00504(s32);
extern void func_8AF02DA4(s32 arg0, s32 arg1);

void func_8AF13B30(void *);
s32 func_8AF141E8(s16, s16);

extern s32 D_8AF26940;
extern u8 D_8AF31E10;
extern u8 D_8AF31E48[];
extern s16 D_8AF32C10;
extern s16 D_8AF32C12;
extern s32 D_8AF32E08;
extern s32 D_8AF32E0C;
extern s16 D_8AF33624;
extern u8 D_8AF33728[];
extern s32 D_8AF33754;
extern s32 D_8AF33758;
extern s32 D_8AF3375C;
extern s16 D_8AF33760;
extern s16 D_8AF33762;



void func_8AF14648(void) {
    s32 pad[2]; // FAKE: unused stack padding; without it the frame is 0x580 instead of 0x588 (diff score 10).
    s16 *var_s2;
    s16 temp_s0;
    s32 temp_s1_2;
    s16 temp_v0_5;
    s32 temp_s1; // FAKE: unused declaration; its frame slot keeps sp68 at sp+0x68, and without it sp68 lands at sp+0x6C (diff score 74).
    u8 sp68[0x504];
    s32 temp_v0_2;
    s32 temp_v0;

    _bzero(D_8AF27130, 0x52C);
    func_8004C4B0(6);
    func_8004C4B0(0x3B);
    func_8004C8C0(0xBEU);
    func_8004C8C0(0x37U);
    func_8004C8C0(0x38U);
    func_8004C8C0(0x143U);
    func_800476A0(&D_8AF31E10, 3);
    func_800476FC((s32) &D_8AF31E10, 3);
    func_80047738(0, func_8004C990(0x37, 0), 0, 0);
    if (func_8AF00020() != 0) {
        func_80047738(1, func_8004C990(0x37, 1), 0, 0);
    } else {
        func_80047738(1, func_8004C990(0x143, 0), 0, 0);
    }
    func_80047738(2, func_8004C990(0x38, 2), 0, 0);
    func_8AF00504(0x62);
    temp_v0 = (s32)(func_8AF003A8(0x62));
    func_8AC06E98(((void *)temp_v0));
    D_8AF32E08 = func_8AC06D8C((s32) ((void *)temp_v0), 0x706F5F77);
    D_8AF32E0C = func_8AC06D8C((s32) ((void *)temp_v0), 0x736C6966);
    *(u16 *)((u8 *)D_8AF32E0C + 0x30) = 0x3B;
    *(s16 *)((u8 *)D_8AF32E0C + 0x32) = 0xA6;
    D_8AF32E10 = func_8AC06D8C((s32) ((void *)temp_v0), 0x6B696473);
    *(u16 *)((u8 *)D_8AF32E10 + 0x30) = 0x3B;
    *(s16 *)((u8 *)D_8AF32E10 + 0x32) = 0xA7;
    D_8AF32E14 = func_8AC06D8C((s32) ((void *)temp_v0), 0x6F796167);
    *(u16 *)((u8 *)D_8AF32E14 + 0x30) = 0x3B;
    *(s16 *)((u8 *)D_8AF32E14 + 0x32) = 0x110;
    *(u16 *)((u8 *)D_8AF32E14 + 2) &= ~1;
    D_8AF33618 = func_8004C874(0x3B, 0x3D);
    D_8AF3361C = func_8004C874(0x3B, 0x46);
    D_8AF33620 = func_8004C874(0x3B, 0x10C);
    func_8AC05ED4((s32) ((void *)temp_v0), 0x79615F75, (s32) D_8AF33628);
    func_8AC05ED4((s32) ((void *)temp_v0), 0x79615F73, (s32) D_8AF336A0);
    func_8AC02C80((s32) ((void *)temp_v0), 0x725F6C5F, 0x725F725F, D_8AF33728);
    D_8AF33754 = func_8AC06D8C((s32) ((void *)temp_v0), 0x676F6C64);
    D_8AF33758 = func_8AC06D8C((s32) ((void *)temp_v0), 0x73696C76);
    D_8AF3375C = func_8AC06D8C((s32) ((void *)temp_v0), 0x63727973);
    if (D_8AF26940 == 0) {
        *(s16 *)((u8 *)D_8AF33754 + 0x24) = 0xBE;
        *(s16 *)((u8 *)D_8AF33754 + 0x26) = 0;
        *(s16 *)((u8 *)D_8AF33758 + 0x24) = 0xBE;
        *(s16 *)((u8 *)D_8AF33758 + 0x26) = 0;
        *(s16 *)((u8 *)D_8AF3375C + 0x24) = 0xBE;
        *(s16 *)((u8 *)D_8AF3375C + 0x26) = 0;
    }
    if (func_8AF00020() == 0) {
        *(u16 *)((u8 *)D_8AF3375C + 2) &= ~1;
    }
    _bzero(D_8AF31E48, 0xDC8);
    _bzero(&D_8AF32C10, 0x1F8);
    D_8AF33624 = 0;
    var_s2 = &D_8AF32C10;
    if (D_8AF31E40 == 0xA6) {
        func_8AF141E8(D_8AF33624, 0xEB);
        D_8AF32C10 = 0xEB;
        var_s2 = &D_8AF32C12;
        D_8AF33624 += 1;
    } else {
        for (temp_v0_2 = 0; temp_v0_2 != 0xFB; temp_v0_2++) {
            temp_v0_5 = func_80063804(temp_v0_2 + 1);
            if ((temp_v0_5 != 0xEB) && (func_800643CC(temp_v0_5 & 0xFF, (s32) D_8AF31E40, 0x64) != 0) && (func_8AF141E8(D_8AF33624, temp_v0_5) != 0)) {
                *var_s2 = temp_v0_5;
                var_s2++;
                D_8AF33624 += 1;
            }
        }
    }
    *var_s2 = -1;
    temp_s0 = *(s16 *)((u8 *)D_8AF32E08 + 8);
    temp_s1_2 = *(s16 *)((u8 *)D_8AF32E08 + 0xA);
    _bzero(sp68, 0x504);
    *(s16 *)(sp68 + 0x00) = 0x226;
    *(s16 *)(sp68 + 0x02) = 0xF0;
    *(s16 *)(sp68 + 0x14) = 0xD;
    *(s32 *)(sp68 + 0x24) = 0x55;
    *(s32 *)(sp68 + 0x28) = 0x41;
    *(s32 *)(sp68 + 0x2C) = 6;
    *(s32 *)(sp68 + 0x04) = 0;
    *(s32 *)(sp68 + 0x08) = 0;
    *(s16 *)(sp68 + 0x0C) = 0;
    *(s16 *)(sp68 + 0x0E) = 0;
    *(s16 *)(sp68 + 0x12) = 0;
    *(s16 *)(sp68 + 0x3C) = 2;
    *(s16 *)(sp68 + 0x3E) = 1;
    *(s32 *)(sp68 + 0x34) = 0;
    *(s32 *)(sp68 + 0x38) = 0;
    *(s16 *)(sp68 + 0x4A) = 0x41;
    func_8AF145B4(D_8AF27130, 0xA, (s32) temp_s0, (s32) temp_s1_2, 8, 0U, 0U, 0U, 0x64U, 0x64U, 0x64U, 4, 0xB, (unk_func_8AF145B4 *) sp68);
    func_8AF02DA4((s32) D_8AF27130, (s32) &D_8AF32C10);
    func_8AC0651C(D_8AF33718, (s16) ((s32) (D_8AF33624 - 1) / 6), 0x3C, 2, 0xA);
    D_8AF31E41 = (s8) D_8AF32C10;
    D_8AF2BDDC = 1;
    func_8AF13B30(&D_8AF31E48);
    D_8AF33760 = 0;
    D_8AF33762 = 0;
    *(u16 *)((u8 *)D_8AF32E14 + 2) = (u16) (*(u16 *)((u8 *)D_8AF32E14 + 2) | 1);
}

extern u8 *D_8AF27130;
extern void *D_8AF263C0;
extern u16 D_8AF2BDC6;
extern u8 D_8AF31E41;
extern u8 D_8AF31E48[];
extern s16 D_8AF32C10;
extern s16 D_8AF33624;
extern u8 D_8AF33628[];
extern u8 D_8AF336A0[];
extern u8 D_8AF33718[];
extern s16 D_8AF33760;
extern s16 D_8AF33762;
void func_8AC0619C(u8 *, u16);
void func_8AC06220(u8 *, u16);
void func_8AC0686C(u8 *, s16);
void func_8AF00130(s32);
s32 func_8AF0326C(u8 *);
void func_8AF13B30(void *);



s16 func_8AF14BE8(void)
{
  s16 sp36;
  u8 *volatile sp30; // FAKE: keeps the state pointer in its 0x30(sp) slot so the join reloads it; diff score 1005 without it.
  s32 pad[4]; // FAKE: unused stack padding; widens the frame from 0x28 to the target 0x38; diff score 106 without it.
  u8 *t;
  s16 var_a1;
  s16 temp_v0;
  sp36 = 15;
  sp30 = D_8AF27130;
  if ((func_8AF0326C(D_8AF27130) == 0) && ((*((u16 *) (((u8 *) D_8AF263C0) + 8))) & 0x4000))
  {
    func_8AF00130(3), sp36 = 14;
  }
  t = sp30;
  temp_v0 = ((*((s16 *) (t + 0x38))) * 6) + (*((s16 *) (t + 0x34)));
  t += 0x28;
  if (temp_v0 >= D_8AF33624)
  {
    D_8AF31E41 = 0;
  }
  else
  {
    D_8AF31E41 = (&D_8AF32C10)[temp_v0];
  }
  // FAKE: the comma expression loads D_8AF33760 after the sprite's 0xC field; diff score 25 without it.
  if (((*((s16 *) (t + 0xC))) != ((0, D_8AF33760))) || ((var_a1 = *((s16 *) (t + 0x10))), var_a1 != D_8AF33762))
  {
    func_8AF13B30((s16 *) D_8AF31E48 + (temp_v0 * 7));
    var_a1 = *((s16 *) (t + 0x10));
  }
  func_8AC0686C(D_8AF33718, var_a1);
  func_8AC0619C(D_8AF33628, D_8AF2BDC6);
  func_8AC06220(D_8AF336A0, D_8AF2BDC6);
  D_8AF33760 = *((s16 *) (t + 0xC));
  D_8AF33762 = *((s16 *) (t + 0x10));
  return sp36;
}

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
