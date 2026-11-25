#include "global.h"


#ifdef VERSION_US
extern u16 *D_8AF2BA98;
extern u16 *D_8AF2BA9C;
extern u8 func_80062D98(u8);
s32 func_8AF0BB40(s16 move) {
    s32 result = 1;
    u8 type = func_80062D98(move);
    u16 *table;
    u16 mask;

    if (move == 0xF8) {
        result = 0;
    } else if (move == 0xED) {
        result = 0;
    } else if (move == 0xFB) {
        result = 0;
    } else {
        if (type == 0x1B) {
            table = D_8AF2BA9C;
            mask = 0x8000;
        } else {
            table = D_8AF2BA98;
            mask = 0xFFFF;
        }
        if (!(table[move - 1] & mask)) {
            result = 0;
        }
    }
    return result;
}

extern s32 D_8AF26A20;
extern s8 *D_8AF2E8E8;
extern s8 *D_8AF2E8F0;
extern s8 *D_8AF2E8F4;
void func_8AF0BBF0(void *arg0) {
    sprintf(D_8AF26A20 + 0x300, D_8AF2E8E8);
    sprintf(D_8AF26A20 + 0x400, D_8AF2E8E8);
    sprintf(D_8AF26A20 + 0x700, D_8AF2E8E8);
    sprintf(D_8AF26A20 + 0x800, D_8AF2E8E8);
    sprintf(D_8AF26A20 + 0x900, D_8AF2E8E8);
    if ((*(u8 *)((u8 *)(arg0) + (0x10))) == 0) {
        sprintf(D_8AF26A20 + 0x500, D_8AF2E8E8);
    } else {
        sprintf(D_8AF26A20 + 0x500, D_8AF2E8F0);
    }
    if ((*(u8 *)((u8 *)(arg0) + (0x11))) == 0) {
        sprintf(D_8AF26A20 + 0x600, D_8AF2E8E8);
    } else {
        sprintf(D_8AF26A20 + 0x600, D_8AF2E8F0);
    }
    if ((*(u8 *)((u8 *)(arg0) + (0x12))) == 0) {
        sprintf(D_8AF26A20 + 0xA00, D_8AF2E8E8);
        return;
    }
    sprintf(D_8AF26A20 + 0xA00, D_8AF2E8F4);
}

/* mkdraft:func_8AF0BD2C begin */
extern s32 D_8AF26A20;
extern s8 *D_8AF2E8E8;
extern s8 *D_8AF2E8E4;
extern s8 D_8AF29230;
extern s8 D_8AF29234;
extern s8 D_8AF29238;
extern s8 D_8AF2923C;
extern int sprintf(char *, const char *, ...);
extern s32 func_8004C594(s32 index, s32 value);
extern void *func_8004C8A0(void *dst, s32 size, s32 arg2, s32 arg3);



void func_8AF0BD2C(void *arg0) {
    u8 name_kind;
    u8 name_kind_2;
    u8 name_kind_3;
    u8 name_kind_4;

    // Bytes 1 through 4 each pick one of three name formats rendered into
    // D_8AF26A20 + 0x300 + 0x100 * i; kinds other than 0 and 1 share the
    // string at D_8AF29230 + 4 * i.
    name_kind = *(u8 *)((u8 *)arg0 + 1);
    if (name_kind == 0) {
        sprintf(D_8AF26A20 + 0x300, D_8AF2E8E8, name_kind);
    } else if (name_kind == 1) {
        sprintf(D_8AF26A20 + 0x300, D_8AF2E8E4, name_kind);
    } else {
        sprintf(D_8AF26A20 + 0x300, &D_8AF29230, name_kind);
    }
    name_kind_2 = *(u8 *)((u8 *)arg0 + 2);
    if (name_kind_2 == 0) {
        sprintf(D_8AF26A20 + 0x400, D_8AF2E8E8, name_kind_2);
    } else if (name_kind_2 == 1) {
        sprintf(D_8AF26A20 + 0x400, D_8AF2E8E4, name_kind_2);
    } else {
        sprintf(D_8AF26A20 + 0x400, &D_8AF29234, name_kind_2);
    }
    name_kind_3 = *(u8 *)((u8 *)arg0 + 3);
    if (name_kind_3 == 0) {
        sprintf(D_8AF26A20 + 0x500, D_8AF2E8E8, name_kind_3);
    } else if (name_kind_3 == 1) {
        sprintf(D_8AF26A20 + 0x500, D_8AF2E8E4, name_kind_3);
    } else {
        sprintf(D_8AF26A20 + 0x500, &D_8AF29238, name_kind_3);
    }
    name_kind_4 = *(u8 *)((u8 *)arg0 + 4);
    if (name_kind_4 == 0) {
        sprintf(D_8AF26A20 + 0x600, D_8AF2E8E8, name_kind_4);
    } else if (name_kind_4 == 1) {
        sprintf(D_8AF26A20 + 0x600, D_8AF2E8E4, name_kind_4);
    } else {
        sprintf(D_8AF26A20 + 0x600, &D_8AF2923C, name_kind_4);
    }
    // Bytes 6 through 9 are scanned for the first nonzero value, which is
    // handed to func_8004C594(2, ...); 0x33 and above are stored reduced by
    // 0x32.
    if ((s32) * (u8 *)((u8 *)arg0 + 6) >= 0x33) {
        func_8004C594(2, *(u8 *)((u8 *)arg0 + 6) - 0x32);
    } else if ((s32) * (u8 *)((u8 *)arg0 + 6) > 0) {
        func_8004C594(2, (s32) * (u8 *)((u8 *)arg0 + 6));
    } else if ((s32) * (u8 *)((u8 *)arg0 + 7) >= 0x33) {
        func_8004C594(2, *(u8 *)((u8 *)arg0 + 7) - 0x32);
    } else if ((s32) * (u8 *)((u8 *)arg0 + 7) > 0) {
        func_8004C594(2, (s32) * (u8 *)((u8 *)arg0 + 7));
    } else if ((s32) * (u8 *)((u8 *)arg0 + 8) >= 0x33) {
        func_8004C594(2, *(u8 *)((u8 *)arg0 + 8) - 0x32);
    } else if ((s32) * (u8 *)((u8 *)arg0 + 8) > 0) {
        func_8004C594(2, (s32) * (u8 *)((u8 *)arg0 + 8));
    } else if ((s32) * (u8 *)((u8 *)arg0 + 9) >= 0x33) {
        func_8004C594(2, *(u8 *)((u8 *)arg0 + 9) - 0x32);
    } else if ((s32) * (u8 *)((u8 *)arg0 + 9) > 0) {
        func_8004C594(2, (s32) * (u8 *)((u8 *)arg0 + 9));
    }
    // The same four bytes are rendered into D_8AF26A20 + 0x700 + 0x100 * i.
    if (*(u8 *)((u8 *)arg0 + 6) == 0) {
        sprintf(D_8AF26A20 + 0x700, D_8AF2E8E8);
    } else if ((s32) * (u8 *)((u8 *)arg0 + 6) < 0x33) {
        func_8004C8A0(D_8AF26A20 + 0x700, 0x100, 0x3B, 0x39);
    } else {
        func_8004C8A0(D_8AF26A20 + 0x700, 0x100, 0x3B, 0x3A);
    }
    if (*(u8 *)((u8 *)arg0 + 7) == 0) {
        sprintf(D_8AF26A20 + 0x800, D_8AF2E8E8, *(u8 *)((u8 *)arg0 + 7));
    } else if ((s32) * (u8 *)((u8 *)arg0 + 7) < 0x33) {
        func_8004C8A0(D_8AF26A20 + 0x800, 0x100, 0x3B, 0x39);
    } else {
        func_8004C8A0(D_8AF26A20 + 0x800, 0x100, 0x3B, 0x3A);
    }
    if (*(u8 *)((u8 *)arg0 + 8) == 0) {
        sprintf(D_8AF26A20 + 0x900, D_8AF2E8E8, *(u8 *)((u8 *)arg0 + 8));
    } else if ((s32) * (u8 *)((u8 *)arg0 + 8) < 0x33) {
        func_8004C8A0(D_8AF26A20 + 0x900, 0x100, 0x3B, 0x39);
    } else {
        func_8004C8A0(D_8AF26A20 + 0x900, 0x100, 0x3B, 0x3A);
    }
    if (*(u8 *)((u8 *)arg0 + 9) == 0) {
        sprintf(D_8AF26A20 + 0xA00, D_8AF2E8E8, *(u8 *)((u8 *)arg0 + 9));
        return;
    }
    if ((s32) * (u8 *)((u8 *)arg0 + 9) < 0x33) {
        func_8004C8A0(D_8AF26A20 + 0xA00, 0x100, 0x3B, 0x39);
        return;
    }
    func_8004C8A0(D_8AF26A20 + 0xA00, 0x100, 0x3B, 0x3A);
}
/* mkdraft:func_8AF0BD2C end */

/* mkdraft:func_8AF0C1D8 begin */
extern s16 D_8AF263C4[];
extern s16 D_8AF2ECF8;
extern s32 func_8004C54C(s32 index, s32 value);
extern s32 func_8004C594(s32 index, s32 value);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern u8 func_80062D5C(u8 arg0);
extern u8 func_80062DD4(u8 arg0);
extern u8 func_80062E10(u8 arg0);
extern u8 func_80062D98(u8 arg0);
extern s32 func_8AF00020(void);
extern s16 func_8AF01530(s16 arg0);
extern int sprintf(char *, const char *, ...);

extern s32 D_8AF26940;
extern s8 D_8AF292A0;
extern s8 D_8AF292A4;
extern s8 D_8AF292A8;
extern s8 D_8AF292AC;
extern s8 D_8AF292B0;
extern s8 D_8AF292B4;
extern s8 D_8AF292B8;
extern s8 D_8AF292BC;
extern void *D_8AF2E88C;
extern void *D_8AF2E890;
extern void *D_8AF2E8C4;
extern s32 D_8AF2E8EC;
extern s16 D_8AF2ED04;
extern u8 D_8AF2F988;
extern u8 D_8AF2F989;



void func_8AF0C1D8(void *arg0) {
    u8 id;
    u8 pp;
    s16 texture_index;
    f32 rounding_bias;
    u8 hit;
    f32 hit_percent;

    id = *(u8 *)arg0;
    texture_index = id - 1;
    *(s16 *)((u8 *)D_8AF2E88C + 0x30) = 6;
    *(s16 *)((u8 *)D_8AF2E88C + 0x32) = texture_index;
    *(s16 *)((u8 *)D_8AF2E890 + 0x30) = 7;
    *(s16 *)((u8 *)D_8AF2E890 + 0x32) = texture_index;
    // Move record fields at D_8009782A: power, PP, hit rate on a 0-255 scale
    // and type, read through func_80062D5C, func_80062E10, func_80062DD4 and
    // func_80062D98 respectively.
    D_8AF2F989 = func_80062D5C(id);
    pp = func_80062E10(id);
    hit = func_80062DD4(id);
    // Round the hit rate percentage to the nearest integer for display.
    if (((f32)func_80062DD4(id) * 100.0f) / 255.0f > 0.0f) {
        rounding_bias = 0.5f;
    } else {
        rounding_bias = -0.5f;
    }
    D_8AF2F988 = func_80062D98(id);
    sprintf(D_8AF26A20 + 0x100, &D_8AF292A0, pp);
    hit_percent = ((f32)hit * 100.0f) / 255.0f;
    sprintf(D_8AF26A20 + 0x200, &D_8AF292A4, (s32)(rounding_bias + hit_percent) & 0xFF);
    func_8004C54C(0x2F, (s32)func_8004C874(0xC, D_8AF263C4[func_8AF01530(D_8AF2F988)]));
    func_8004C54C(0x31, D_8AF26A20 + 0x100);
    func_8004C54C(0x32, D_8AF26A20 + 0x200);
    if (D_8AF2ECF8 == 1) {
        func_8AF0BBF0(arg0);
    } else {
        func_8AF0BD2C(arg0);
    }
    func_8004C54C(0x33, D_8AF26A20 + 0x300);
    func_8004C54C(0x34, D_8AF26A20 + 0x400);
    func_8004C54C(0x37, D_8AF26A20 + 0x700);
    func_8004C54C(0x38, D_8AF26A20 + 0x800);
    if (D_8AF26940 != 0) {
        func_8004C54C(0x35, D_8AF26A20 + 0x500);
        func_8004C54C(0x36, D_8AF26A20 + 0x600);
        func_8004C54C(0x39, D_8AF26A20 + 0x900);
        func_8004C54C(0x3A, D_8AF26A20 + 0xA00);
    } else {
        func_8004C54C(0x35, D_8AF2E8EC);
        func_8004C54C(0x36, D_8AF2E8EC);
        func_8004C54C(0x39, D_8AF2E8EC);
        func_8004C54C(0x3A, D_8AF2E8EC);
    }
    if (func_8AF00020() == 0) {
        func_8004C54C(0x36, &D_8AF292A8);
        func_8004C54C(0x3A, &D_8AF292AC);
        if (D_8AF2ECF8 == 1) {
            func_8004C54C(0x37, &D_8AF292B0);
            func_8004C54C(0x38, &D_8AF292B4);
            func_8004C54C(0x39, &D_8AF292B8);
        }
    }
    func_8004C594(3, D_8AF2ED04);
    *(s16 *)((u8 *)D_8AF2E8C4 + 0x30) = 0x3B;
    if (*(u8 *)((u8 *)arg0 + 0xA) == 1) {
        *(s16 *)((u8 *)D_8AF2E8C4 + 0x32) = 0x3C;
    } else {
        *(s16 *)((u8 *)D_8AF2E8C4 + 0x32) = 0x3B;
    }
    // Power 0 and 1 print the shared blank string instead of a number.
    if (D_8AF2F989 >= 2) {
        sprintf(D_8AF26A20, &D_8AF292BC, D_8AF2F989);
    } else {
        sprintf(D_8AF26A20, D_8AF2E8E8, D_8AF2F989);
    }
    func_8004C54C(0x30, D_8AF26A20);
}
/* mkdraft:func_8AF0C1D8 end */

s32 func_8AF0C5BC(s16 arg0, s16 arg1) {
    s32 var_v1;

    var_v1 = 1;
    if ((arg0 == 0x10) && (arg1 == 0xD3)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x2E) && (arg1 == 0xE6)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x2B) && (arg1 == 0xCC)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x53) && (arg1 == 0xD3)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x78) && (arg1 == 0x3E)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x78) && (arg1 == 0x70)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x78) && (arg1 == 0x30)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x8E) && (arg1 == 0xD3)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x8F) && (arg1 == 0xCC)) {
        var_v1 = 0;
    }
    if ((arg0 == 1) && (arg1 == 0xCC)) {
        var_v1 = 0;
    }
    if ((arg0 == 0xEE) && (arg1 == 0x8E)) {
        var_v1 = 0;
    }
    if ((arg0 == 0x30) && (arg1 == 0xCA)) {
        var_v1 = 0;
    }
    return var_v1;
}

/* mkdraft:func_8AF0C6F8 begin */
extern u8 D_8AF2E8F8[];



s16 func_8AF0C6F8(u8 *arg0) {
    s16 var_v1;
    u8 *var_a2;
    u8 *var_t1;
    u8 temp_t0;
    u8 temp_v0;

    var_v1 = 0;
    var_t1 = D_8AF2E8F8;
loop_1:
    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        var_a2 = var_t1;
init_2:
        temp_t0 = *var_a2;
        if (temp_t0 != temp_v0) {
            if (((!var_a2) && (!var_a2)) && (!var_a2)) { // FAKE: three redundant var_a2 tests widen its live range so uopt colors temp_t0 as t0; without it the inner lbu takes a3 (score 15)
            }
            if (temp_t0 == 0) {
                *var_a2 = temp_v0;
                var_v1 += 1;
                arg0 += 0x14;
            } else {
                var_a2 += 1;
                goto init_2;
            }
        } else {
            arg0 += 0x14;
        }
        goto loop_1;
    }
    return var_v1;
}
/* mkdraft:func_8AF0C6F8 end */

extern void _bzero(s32 *, s32);
extern s16 func_8AF0C6F8(u8 *);
extern u8 D_8AF2D5C8[];
extern u8 D_8AF2D758[];
extern u8 D_8AF2D8E8[];
extern u8 D_8AF2E8F8[];

s16 func_8AF0C758(void) {
    s16 total;
    s16 temp;

    _bzero((s32 *)D_8AF2E8F8, 0x100);
    /* Two statements per source line: as1 breaks the jal delay-slot fill tie by
     * .loc line, and each spill of the previous call's result belongs in the
     * next call's delay slot. */
    total = func_8AF0C6F8(D_8AF2D5C8); temp = func_8AF0C6F8(D_8AF2D758);
    total += temp; temp = func_8AF0C6F8(D_8AF2D8E8);
    total += temp;
    return total;
}
/* mkdraft:func_8AF0C7C8 begin */


s32 func_8AF0C7C8(u8 *arg0, u8 *arg1) {
    s16 count;
    u8 *base;
    u8 value;

    base = arg1;
    count = 0;
    for (;;) {
        if (arg0[0] == 0) break;
        arg1 = base;
        do {
            value = arg1[0];
            if (!value) break;
            if (arg0[0] == value) {
                count++;
                if (arg0[1] == 0) arg0[1] = arg1[1];
                if (arg0[2] == 0) arg0[2] = arg1[2];
                if (arg0[3] == 0) arg0[3] = arg1[3];
                if (arg0[4] == 0) arg0[4] = arg1[4];
                if (arg0[6] == 0) arg0[6] = arg1[6];
                if (arg0[7] == 0) arg0[7] = arg1[7];
                if (arg0[8] == 0) arg0[8] = arg1[8];
                if (arg0[9] == 0) arg0[9] = arg1[9];
                if (arg1[5] == 0) arg1[5] = arg0[5];
                if (arg1[1] == 0) arg1[1] = arg0[1];
                if (arg1[2] == 0) arg1[2] = arg0[2];
                if (arg1[3] == 0) arg1[3] = arg0[3];
                if (arg1[4] == 0) arg1[4] = arg0[4];
                if (arg1[6] == 0) arg1[6] = arg0[6];
                if (arg1[7] == 0) arg1[7] = arg0[7];
                if (arg1[8] == 0) arg1[8] = arg0[8];
                if (arg1[9] == 0) arg1[9] = arg0[9];
            }
            arg1 += 0x14;
        } while (1);
        arg0 += 0x14;
    }
    return count;
}
/* mkdraft:func_8AF0C7C8 end */

u8 func_8AF0C96C(u8 *arg0) {
    volatile u8 pad; // FAKE: never accessed; without it the function does not match (diff score 40)
    u8 values[4];
    u8 minimum;
    u32 index;

    minimum = 0xFF;
    values[0] = arg0[1];
    values[1] = arg0[2];
    values[2] = arg0[3];
    values[3] = arg0[4];
    for (index = 0; index < 4; index++) {
        if (values[index] != 0 && values[index] < minimum) {
            minimum = values[index];
        }
    }
    return minimum;
}

typedef struct { s32 w[5]; } Slot_8AF0CA00;
extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern u8 *func_80064800(u8);
extern s16 D_8AF2ED00;
extern s16 D_8AF2ED02;
extern u8 *D_8AF2D594;
extern u8 *D_8AF2E888;
extern s16 D_8AF2E89C;
void func_8AF0CA00(s16 arg0) {
    s32 i;
    s32 j;
    u8 b0, b1;
    u8 sp8D;
    u8 sp8C;
    Slot_8AF0CA00 *s5;
    Slot_8AF0CA00 *s0;
    Slot_8AF0CA00 tmp;
    u8 min;
    u8 v;
    u8 flag = 0xF;
    if (func_8AF00020() == 0) {
        flag = 7;
    }
    D_8AF2ED00 = func_8006397C(arg0);
    D_8AF2ED02 = func_800639C0(arg0);
    D_8AF2D594 = func_80064800(arg0);
    _bzero((s32 *)D_8AF2D5C8, 0x190);
    D_8AF2E89C = 0;
    while (1) {
        b0 = D_8AF2D594[0];
        b1 = D_8AF2D594[1];
        sp8D = D_8AF2D594[2];
        if (b0 == 0) {
            break;
        }
        sp8C = func_80062D98(b1);
        D_8AF2E888 = D_8AF2D5C8;
        for (i = 0; i < 0x14; i++, D_8AF2E888 += 0x14) {
            if (b1 == D_8AF2E888[0] || D_8AF2E888[0] == 0) {
                if (sp8D & flag) {
                    if (D_8AF2E888[0] == 0) {
                        D_8AF2E89C++;
                        D_8AF2E888[0] = b1;
                        D_8AF2E888[5] = func_8AF01530(sp8C);
                        *(s32 *)(D_8AF2E888 + 0xC) = (s32)func_8004C874(6, b1 - 1);
                        if (func_8AF0BB40((s16)b1) != 0) {
                            if (sp8C == D_8AF2ED00 || sp8C == D_8AF2ED02) {
                                D_8AF2E888[0xA] = 1;
                            }
                        }
                        if (sp8D & 1) {
                            D_8AF2E888[1] = b0;
                        }
                        if (sp8D & 2) {
                            D_8AF2E888[2] = b0;
                        }
                        if (sp8D & 4) {
                            D_8AF2E888[3] = b0;
                        }
                        if (sp8D & 8) {
                            if (func_8AF00020() != 0) {
                                D_8AF2E888[4] = b0;
                            }
                        }
                    } else if (b1 == D_8AF2E888[0]) {
                        if (arg0 == 0xEB) {
                            D_8AF2E89C++;
                            D_8AF2E888 += 0x14;
                            while (1) {
                                if (D_8AF2E888[0] == 0) {
                                    break;
                                }
                                D_8AF2E888 += 0x14;
                            }
                            D_8AF2E888[0] = b1;
                            D_8AF2E888[5] = func_8AF01530(sp8C);
                            *(s32 *)(D_8AF2E888 + 0xC) = (s32)func_8004C874(6, b1 - 1);
                        }
                        if (sp8D & 1) {
                            D_8AF2E888[1] = b0;
                        }
                        if (sp8D & 2) {
                            D_8AF2E888[2] = b0;
                        }
                        if (sp8D & 4) {
                            D_8AF2E888[3] = b0;
                        }
                        if (sp8D & 8) {
                            if (func_8AF00020() != 0) {
                                D_8AF2E888[4] = b0;
                            }
                        }
                        ; // empty statement (likely a compiled-out debug print) needed for codegen
                    }
                }
                i = 0x14;
            }
        }
        D_8AF2D594 += 3;
    }
    s5 = (Slot_8AF0CA00 *)D_8AF2D5C8;
    for (i = 0; i < D_8AF2E89C - 1; i++, s5++) {
        min = func_8AF0C96C((u8 *)s5);
        for (j = i + 1; j < D_8AF2E89C; j++) {
            s0 = &((Slot_8AF0CA00 *)D_8AF2D5C8)[j];
            if ((v = func_8AF0C96C((u8 *)s0)) < min) {
                min = v;
                tmp = *s5;
                *s5 = *s0;
                *s0 = tmp;
            }
        }
    }
}

extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern u8 *func_80064800(u8);
extern u8 D_8AF2D302[];
extern s16 D_8AF2ED00;
extern s16 D_8AF2ED02;
extern s16 D_8AF2E89E;
extern u8 *D_8AF2D594;
extern u8 *D_8AF2E888;

void func_8AF0CE6C(s16 arg0, s16 arg1) {
    s32 i;
    u8 b0, b1;
    u8 sp59;
    u8 sp58;
    u8 flag = 0x60;
    if (func_8AF00020() == 0) {
        flag = 0x40;
    }
    func_8004C874(0, arg0 - 1);
    D_8AF2ED00 = func_8006397C(D_8AF2D302[1]);
    D_8AF2ED02 = func_800639C0(D_8AF2D302[1]);
    _bzero(D_8AF2D758, 0x190);
    D_8AF2E89E = 0;
    func_8004C874(0, arg1 - 1);
    D_8AF2D594 = func_80064800(arg1);
    while (1) {
        b0 = D_8AF2D594[0];
        b1 = D_8AF2D594[1];
        sp59 = D_8AF2D594[2];
        if (b0 == 0) {
            break;
        }
        sp58 = func_80062D98(b1);
        if (func_8AF0C5BC(arg1, (s16)b1) != 0) {
            D_8AF2E888 = D_8AF2D758;
            for (i = 0; i < 0x14; i++, D_8AF2E888 += 0x14) {
                if (D_8AF2E888[0] == 0 || b1 == D_8AF2E888[0]) {
                    func_8004C874(6, b1 - 1);
                    if ((sp59 & flag) && b0 > 0) {
                        D_8AF2E888[0] = b1;
                        D_8AF2E888[5] = func_8AF01530(func_80062D98(b1));
                        *(s32 *)(D_8AF2E888 + 0xC) = func_8004C874(6, b1 - 1);
                        if (func_8AF0BB40((s16)b1) != 0) {
                            if (sp58 == D_8AF2ED00 || sp58 == D_8AF2ED02) {
                                D_8AF2E888[0xA] = 1;
                            }
                        }
                        if (sp59 & 0x40) {
                            D_8AF2E888[0x10] = b0;
                        }
                        if (sp59 & 0x20) {
                            if (func_8AF00020() != 0) {
                                D_8AF2E888[0x11] = b0;
                            }
                        }
                        if (!(i + 1 < D_8AF2E89E)) {
                            D_8AF2E89E = i + 1;
                        }
                    }
                    i = 0x14;
                }
            }
        }
        D_8AF2D594 += 3;
    }
    if (func_8AF00020() != 0) {
        func_8004C874(0, arg0 - 1);
        D_8AF2D594 = func_80064800(arg0);
        while (1) {
            b0 = D_8AF2D594[0];
            b1 = D_8AF2D594[1];
            sp59 = D_8AF2D594[2];
            if (b0 == 0) {
                break;
            }
            sp58 = func_80062D98(b1);
                if (func_8AF0C5BC(arg0, (s16)b1) != 0) {
                D_8AF2E888 = D_8AF2D758;
                for (i = 0; i < 0x14; i++, D_8AF2E888 += 0x14) {
                        if (D_8AF2E888[0] == 0 || b1 == D_8AF2E888[0]) {
                        func_8004C874(6, b1 - 1);
                        if ((sp59 & 0x10) && b0 > 0) {
                            D_8AF2E888[0] = b1;
                            D_8AF2E888[5] = func_8AF01530(func_80062D98(b1));
                            *(s32 *)(D_8AF2E888 + 0xC) = func_8004C874(6, b1 - 1);
                            if (func_8AF0BB40((s16)b1) != 0) {
                                if (sp58 == D_8AF2ED00 || sp58 == D_8AF2ED02) {
                                    D_8AF2E888[0xA] = 1;
                                }
                            }
                            if (sp59 & 0x10) {
                                D_8AF2E888[0x12] = b0;
                            }
                            if (!(i + 1 < D_8AF2E89E)) {
                                D_8AF2E89E = i + 1;
                            }
                        }
                        i = 0x14;
                    }
                }
            }
            D_8AF2D594 += 3;
        }
    }
}

extern u8 D_8AF2D8E8[];
s32 func_8AF0D29C(s16 id) {
    s32 i;

    D_8AF2E888 = D_8AF2D8E8;
    for (i = 0; i < 200; i++) {
        if (D_8AF2E888[0] == 0) {
            return 0;
        }
        if (id == D_8AF2E888[0]) {
            return 1;
        }
        D_8AF2E888 += 0x14;
    }
    while (TRUE) {
    }
}

/* mkdraft:func_8AF0D398 begin */
extern void *func_8004C874(s32, s32);
extern u8 func_80062F68(u8);
extern u8 func_80063014(u8);
extern s32 func_80063CC4(u8, u8);
extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern s32 func_80063BF4(u8, u8);
extern s32 Pokemon_CanLearnGen1Machine(u8, u8);
extern s16 func_8AF01530(s16);

extern s16 D_8AF2E8A0;
extern s16 D_8AF2ED00;
extern s16 D_8AF2ED02;

// Builds the 200-entry learnset table at D_8AF2D8E8 (func_8AF0D29C scans it in
// 0x14-byte records) from the three sources a Pokemon can learn a move by:
// level-up (func_80063014), TM/HM (func_80063014), and Gen 1 transfer
// (func_80062F68).  arg0 is the species ID: the caller loads it with `lh`, and
// the function truncates it to the 8-bit ID used by the lookup helpers.


void func_8AF0D398(s16 arg0) {
    s16 i;
    s16 learnset;
    u8 type;
    u8 move;
    u8 id;

    id = arg0;
    D_8AF2ED00 = func_8006397C(id);
    D_8AF2ED02 = func_800639C0(id);
    _bzero((s32 *)D_8AF2D8E8, 0xFA0);
    D_8AF2E8A0 = 0;
    for (i = 1; i < 0x3A; i++) {
        if (func_80063CC4(id, i) != 0) {
            move = func_80063014(i);
            type = func_80062D98(move);
            learnset = func_8AF0D29C(move);
            D_8AF2E888[0] = move;
            D_8AF2E888[5] = func_8AF01530(func_80062D98(move));
            *(s32 *)(D_8AF2E888 + 0xC) = func_8004C874(6, move - 1);
            if (func_8AF0BB40(move) != 0 && (type == D_8AF2ED00 || type == D_8AF2ED02)) {
                D_8AF2E888[0xA] = 1;
            }
            D_8AF2E888[6] = i;
            if (learnset == 0) {
                D_8AF2E8A0++;
            }
        }
        if (Pokemon_CanLearnGen1Machine(id, i) != 0) {
            move = func_80063014(i);
            type = func_80062D98(move);
            learnset = func_8AF0D29C(move);
            D_8AF2E888[0] = move;
            D_8AF2E888[5] = func_8AF01530(func_80062D98(move));
            *(s32 *)(D_8AF2E888 + 0xC) = func_8004C874(6, move - 1);
            if (func_8AF0BB40(move) != 0 && (type == D_8AF2ED00 || type == D_8AF2ED02)) {
                D_8AF2E888[0xA] = 1;
            }
            D_8AF2E888[7] = i;
            if (learnset == 0) {
                D_8AF2E8A0++;
            }
        }
        if (func_80063BF4(id, i) != 0) {
            move = func_80062F68(i);
            type = func_80062D98(move);
            learnset = func_8AF0D29C(move);
            D_8AF2E888[0] = move;
            D_8AF2E888[5] = func_8AF01530(func_80062D98(move));
            *(s32 *)(D_8AF2E888 + 0xC) = func_8004C874(6, move - 1);
            if (func_8AF0BB40(move) != 0 && (type == D_8AF2ED00 || type == D_8AF2ED02)) {
                D_8AF2E888[0xA] = 1;
            }
            D_8AF2E888[8] = i;
            D_8AF2E888[9] = i;
            if (learnset == 0) {
                D_8AF2E8A0++;
            }
        }
    }
}
/* mkdraft:func_8AF0D398 end */

extern s16 D_8AF2ECF8;
extern u8 *D_8AF2E8DC;
extern u8 *D_8AF2E8E0;
void func_8AF0D704(void) {
    switch (D_8AF2ECF8) {
        case 0:
        case 2:
            *(s16 *)(D_8AF2E8DC + 0x32) = 48;
            *(s16 *)(D_8AF2E8E0 + 0x32) = 49;
            *(u16 *)(D_8AF2E8E0 + 2) |= 2;
            break;
        case 1:
            *(s16 *)(D_8AF2E8DC + 0x32) = 269;
            *(s16 *)(D_8AF2E8E0 + 0x32) = 270;
            if (func_8AF00020()) {
                *(u16 *)(D_8AF2E8E0 + 2) |= 2;
            } else {
                *(u16 *)(D_8AF2E8E0 + 2) &= ~2;
            }
            break;
    }
}

extern s16 D_8AF2F990, D_8AF2E898, D_8AF2E89A, D_8AF2ECFA, D_8AF2ECFC, D_8AF2ECFE, D_8AF2E894, D_8AF2E896;
extern u8 D_8AF2E9F8[], D_8AF2EA08[], D_8AF2EA18[];
extern u8 D_8AF2EA28[], D_8AF2EAA0[], D_8AF2EB18[], D_8AF2EB90[], D_8AF2EC08[], D_8AF2EC80[];
extern void *D_8AF2E8A4;
extern void *D_8AF2E8A8;
extern void *D_8AF2E8AC;
extern void *D_8AF2E8CC;
extern void func_8004C4B0(s32);
extern void func_8004C8C0(s32);
extern void func_8AF00504(s32);
extern s32 func_8AF003A8(s32);
extern void func_8AC06E98(s32);
extern s32 func_8AC06D8C(s32, s32);
extern void func_8004E308(s32, void *, s32);
extern void Fragment43_FillRectangleCallback();
extern u8 *D_8AF2E8D0;
extern u8 *D_8AF2E8D4;
extern u8 *D_8AF2E8D8;
extern u8 *D_8AF2F98C;
extern s32 D_8AF2E8B0, D_8AF2E8B4, D_8AF2E8B8, D_8AF2E8BC;
extern s32 D_8AF2E8C0, D_8AF2E8C8;
extern u8 D_8AF2ED08[];
extern s16 D_8AF2D590;
extern s32 D_8AF2D598;
extern s32 func_8004D878(void *, s32, s32);
extern void func_8AC02C80(s32, s32, s32, void *);
extern void func_8AC05ED4(s32, s32, void *);
extern void func_8AC0651C(void *, s16, s32, s32, s32);
extern s16 func_8AC00FAC(u8);
extern void func_8AF0D398(s16);
extern void func_8AF0CA00(s16);
extern void func_8AF0CE6C(s16, s16);
extern s32 func_8AF0C7C8(u8 *, u8 *);
extern s16 func_8AF0C758(void);
// Sets up the screen that page 0x45 holds. It looks up the eleven 'ers1'..'er11'
// elements and gives each one Fragment43_FillRectangleCallback. It caches the
// other named elements, then counts the filled entries of the three 0x14-byte
// lists D_8AF2D5C8 (20 entries), D_8AF2D758 (20) and D_8AF2D8E8 (200). A list
// ends at its first entry whose first byte is 0, and D_8AF2E888 is left
// pointing at that entry. The counts size the three scroll lists at the end.
void func_8AF0D7C8(void) {
    s32 page;
    s32 i;
    s16 c3, c2, c1;
    s32 e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11;
    D_8AF2F990 = 0;
    func_8004C4B0(6);
    func_8004C4B0(7);
    func_8004C4B0(0x3B);
    func_8004C8C0(0xBE);
    func_8004C8C0(0x9D);
    func_8AF00504(0x45);
    page = func_8AF003A8(0x45);
    func_8AC06E98(page);
    e1 = func_8AC06D8C(page, 0x65727331);
    e2 = func_8AC06D8C(page, 0x65727332);
    e3 = func_8AC06D8C(page, 0x65727333);
    e4 = func_8AC06D8C(page, 0x65727334);
    e5 = func_8AC06D8C(page, 0x65727335);
    e6 = func_8AC06D8C(page, 0x65727336);
    e7 = func_8AC06D8C(page, 0x65727337);
    e8 = func_8AC06D8C(page, 0x65727338);
    e9 = func_8AC06D8C(page, 0x65727339);
    e10 = func_8AC06D8C(page, 0x65723130);
    e11 = func_8AC06D8C(page, 0x65723131);
    func_8004E308(e1, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e2, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e3, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e4, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e5, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e6, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e7, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e8, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e9, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e10, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    func_8004E308(e11, (void *)Fragment43_FillRectangleCallback, 0xFFF1);
    D_8AF2E8D0 = (u8 *)func_8AC06D8C(page, 0x676F6C64);
    D_8AF2E8D4 = (u8 *)func_8AC06D8C(page, 0x73696C76);
    D_8AF2E8D8 = (u8 *)func_8AC06D8C(page, 0x63727973);
    if (D_8AF26940 == 0) {
        *(s16 *)(D_8AF2E8D0 + 0x24) = 0xBE;
        *(s16 *)(D_8AF2E8D0 + 0x26) = 0;
        *(s16 *)(D_8AF2E8D4 + 0x24) = 0xBE;
        *(s16 *)(D_8AF2E8D4 + 0x26) = 0;
        *(s16 *)(D_8AF2E8D8 + 0x24) = 0xBE;
        *(s16 *)(D_8AF2E8D8 + 0x26) = 0;
    }
    if (func_8AF00020() == 0) {
        *(u16 *)(D_8AF2E8D8 + 2) &= ~1;
    }
    func_8004D878((void *)D_8AF2ED08, *(s16 *)D_8AF2D302, 0);
    D_8AF2ED00 = func_8006397C(D_8AF2D302[1]);
    D_8AF2ED02 = func_800639C0(D_8AF2D302[1]);
    D_8AF2E898 = 0;
    D_8AF2E89A = 0;
    D_8AF2ECFA = 0;
    D_8AF2ECFC = 0;
    D_8AF2ECFE = 0;
    _bzero((s32 *)D_8AF2E9F8, 0xE);
    _bzero((s32 *)D_8AF2EA08, 0xE);
    _bzero((s32 *)D_8AF2EA18, 0xE);
    D_8AF2ECF8 = 0;
    func_8004C54C(0x19, (s32)func_8004C874(0, *(s16 *)D_8AF2D302 - 1));
    D_8AF2D590 = func_8AC00FAC(D_8AF2D302[1]);
    func_8AF0CA00(*(s16 *)D_8AF2D302);
    func_8AF0CE6C(*(s16 *)D_8AF2D302, D_8AF2D590);
    func_8AF0D398(*(s16 *)D_8AF2D302);
    func_8AF0C7C8(D_8AF2D5C8, D_8AF2D758);
    func_8AF0C7C8(D_8AF2D5C8, D_8AF2D8E8);
    func_8AF0C7C8(D_8AF2D758, D_8AF2D5C8);
    func_8AF0C7C8(D_8AF2D758, D_8AF2D8E8);
    func_8AF0C7C8(D_8AF2D8E8, D_8AF2D5C8);
    func_8AF0C7C8(D_8AF2D8E8, D_8AF2D758);
    D_8AF2ED04 = func_8AF0C758();
    c3 = 0;
    for (i = 0; i < 20; i++) {
        D_8AF2E888 = D_8AF2D5C8 + i * 0x14;
        if (D_8AF2E888[0] == 0) {
            break;
        }
        c3++;
    }
    c2 = 0;
    for (i = 0; i < 20; i++) {
        D_8AF2E888 = D_8AF2D758 + i * 0x14;
        if (D_8AF2E888[0] == 0) {
            break;
        }
        c2++;
    }
    c1 = 0;
    for (i = 0; i < 200; i++) {
        D_8AF2E888 = D_8AF2D8E8 + i * 0x14;
        if (D_8AF2E888[0] == 0) {
            break;
        }
        c1++;
    }
    func_8AC02C80(page, 0x725F6C5F, 0x725F725F, &D_8AF2D598);
    D_8AF2E88C = (void *)func_8AC06D8C(page, 0x6E616D65);
    D_8AF2E890 = (void *)func_8AC06D8C(page, 0x62756E5F);
    D_8AF2E8A4 = (void *)func_8AC06D8C(page, 0x6C765F77);
    D_8AF2E8A8 = (void *)func_8AC06D8C(page, 0x6B6F5F77);
    D_8AF2E8AC = (void *)func_8AC06D8C(page, 0x6D615F77);
    D_8AF2E894 = *(s16 *)((u8 *)D_8AF2E8A4 + 8);
    D_8AF2E896 = *(s16 *)((u8 *)D_8AF2E8A4 + 0xA);
    D_8AF2F98C = (u8 *)func_8AC06D8C(page, 0x4F594147);
    if (func_8AF00020() != 0) {
        *(s16 *)(D_8AF2F98C + 0x30) = 0x3B;
        *(s16 *)(D_8AF2F98C + 0x32) = 0x37;
    } else {
        *(s16 *)(D_8AF2F98C + 0x30) = 0x3B;
        *(s16 *)(D_8AF2F98C + 0x32) = 0x10D;
    }
    func_8AC05ED4(page, 0x79613175, D_8AF2EA28);
    func_8AC05ED4(page, 0x79613173, D_8AF2EAA0);
    func_8AC05ED4(page, 0x79613275, D_8AF2EB18);
    func_8AC05ED4(page, 0x79613273, D_8AF2EB90);
    func_8AC05ED4(page, 0x79613375, D_8AF2EC08);
    func_8AC05ED4(page, 0x79613373, D_8AF2EC80);
    D_8AF2E8DC = (u8 *)func_8AC06D8C(page, 0x4C45564C);
    D_8AF2E8E0 = (u8 *)func_8AC06D8C(page, 0x57415A41);
    func_8AF0D704();
    D_8AF2E8B0 = func_8AC06D8C(page, 0x6C765F31);
    D_8AF2E8B4 = func_8AC06D8C(page, 0x6C765F32);
    D_8AF2E8B8 = func_8AC06D8C(page, 0x6C765F33);
    D_8AF2E8BC = func_8AC06D8C(page, 0x6C765F34);
    D_8AF2E8E4 = func_8004C874(0x3B, 0x3D);
    D_8AF2E8E8 = func_8004C874(0x3B, 0x46);
    D_8AF2E8EC = (s32)func_8004C874(0x3B, 0x10C);
    D_8AF2E8F0 = func_8004C874(0x3B, 0x10D);
    D_8AF2E8F4 = func_8004C874(0x3B, 0x10E);
    D_8AF2E8C0 = func_8AC06D8C(page, 0x77616B31);
    D_8AF2E8C4 = (void *)func_8AC06D8C(page, 0x736C6966);
    D_8AF2E8C8 = func_8AC06D8C(page, 0x706F6B65);
    D_8AF2E8CC = (void *)func_8AC06D8C(page, 0x626F6F6B);
    func_8AF0C1D8(D_8AF2D5C8);
    func_8AC0651C(D_8AF2E9F8, c3 - 1, 0x14, 6, 4);
    func_8AC0651C(D_8AF2EA08, c2 - 1, 0x14, 6, 4);
    func_8AC0651C(D_8AF2EA18, (c1 - 1) / 2, 0x14, 6, 4);
}

extern void func_8AF00130(s32);
extern s16 D_8AF2E894;
extern s16 D_8AF2E896;
extern s16 D_8AF2E89A;
extern void *D_8AF2E8A4;
extern s16 D_8AF2ECF8;
extern s16 D_8AF2ECFA;
void func_8AF0E084(void) {
    func_8AF00130(1);
    D_8AF2ECF8 = 0;
    D_8AF2E894 = (*(s16 *)((u8 *)(D_8AF2E8A4) + (8)));
    D_8AF2E896 = (*(s16 *)((u8 *)(D_8AF2E8A4) + (0xA)));
    D_8AF2E89A = D_8AF2ECFA;
}

extern void *D_8AF2E8A8;
extern s16 D_8AF2ECFC;
void func_8AF0E0D8(void) {
    func_8AF00130(1);
    D_8AF2ECF8 = 1;
    D_8AF2E894 = (*(s16 *)((u8 *)(D_8AF2E8A8) + (8)));
    D_8AF2E896 = (*(s16 *)((u8 *)(D_8AF2E8A8) + (0xA)));
    D_8AF2E89A = D_8AF2ECFC;
}

extern s16 D_8AF2E898;
extern void *D_8AF2E8AC;
extern s16 D_8AF2ECFE;
void func_8AF0E130(void) {
    func_8AF00130(1);
    D_8AF2ECF8 = 2;
    D_8AF2E894 = (*(s16 *)((u8 *)(D_8AF2E8AC) + (8)));
    D_8AF2E896 = (*(s16 *)((u8 *)(D_8AF2E8AC) + (0xA)));
    D_8AF2E898 = 0;
    D_8AF2E89A = D_8AF2ECFE;
}

/* mkdraft:func_8AF0E190 begin */
extern void func_8AC007FC(void);
extern void func_8AC0686C(void *, s16);
extern void func_8AC0602C(void *, u16, s32);
extern void func_8AC060E4(void *, u16, s32);
extern void func_8AF00130(s32);
extern void func_8AF0C1D8(void *);
extern void func_8AF0D704(void);
extern void func_8AF0E084(void);
extern void func_8AF0E0D8(void);
extern void func_8AF0E130(void);
extern void *D_8AF263C0;
extern s16 D_8AF2E898;
extern s16 D_8AF2E89A;
extern s16 D_8AF2E89C;
extern s16 D_8AF2E89E;
extern s16 D_8AF2E8A0;
extern void *D_8AF2E8CC;
extern s16 D_8AF2ECF8;
extern s16 D_8AF2ECFA;
extern s16 D_8AF2ECFC;
extern s16 D_8AF2ECFE;
extern s16 D_8AF2F990;
extern u8 D_8AF2E9F8[];
extern u8 D_8AF2EA08[];
extern u8 D_8AF2EA18[];
extern u8 D_8AF2D5C8[];
extern u8 D_8AF2D758[];
extern u8 D_8AF2D8E8[];
extern u8 D_8AF2EA28[];
extern u8 D_8AF2EAA0[];
extern u8 D_8AF2EB18[];
extern u8 D_8AF2EB90[];
extern u8 D_8AF2EC08[];
extern u8 D_8AF2EC80[];
extern u16 D_8AF2BDC6;



s16 func_8AF0E190(void) {
    s16 result;
    UNUSED s16 pad1;

    u8 *state;
    s16 old_x;
    s16 old_y;
    s16 old_mode;


    s32 flag0;
    s32 flag1;
    s32 flag2;
    s32 changed;
    u16 buttons;
    s16 limit;
    s32 moved;

    old_x = D_8AF2E898;
    old_y = D_8AF2E89A;
    old_mode = D_8AF2ECF8;
    changed = 0;
    buttons = *(u16 *)((u8 *)D_8AF263C0 + 0xC);
    func_8AC007FC();
    if (D_8AF2F990 < 4) {
        *(u16 *)((u8 *)D_8AF2E8CC + 2) |= 2;
    } else {
        *(u16 *)((u8 *)D_8AF2E8CC + 2) &= 0xFFFD;
    }
    result = 0xB;
    switch (D_8AF2ECF8) {
    case 0:
        D_8AF2ECFA = D_8AF2E89A;
        if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x100) {
            if (D_8AF2E89E > 0) {
                func_8AF0E0D8();
            } else if (D_8AF2E8A0 > 0) {
                func_8AF0E130();
            }
        }
        break;
    case 1:
        D_8AF2ECFC = D_8AF2E89A;
        if ((*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x200) && (D_8AF2E89C > 0)) {
            func_8AF0E084();
        }
        if ((*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x100) && (D_8AF2E8A0 > 0)) {
            func_8AF0E130();
        }
        break;
    case 2:
        D_8AF2ECFE = D_8AF2E89A;
        if ((*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x100) && (D_8AF2E898 <= 0)) {
            func_8AF00130(1);
            D_8AF2E898++;
        } else if ((*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x200) && (D_8AF2E898 > 0)) {
            func_8AF00130(1);
            D_8AF2E898--;
        } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x200) {
            if (D_8AF2E89E > 0) {
                func_8AF0E0D8();
            } else if (D_8AF2E89C > 0) {
                func_8AF0E084();
            }
        }
        break;
    }
    switch (D_8AF2ECF8) {
    case 0: state = D_8AF2E9F8; break;
    case 1: state = D_8AF2EA08; break;
    case 2: state = D_8AF2EA18; break;
    default: state = D_8AF2E9F8; break;
    }
    if (*(s16 *)(state + 4) != 0) {
        changed = 1;
    }
    func_8AC0686C(state, D_8AF2E89A);
    if (changed != 0) {
        buttons = *(u16 *)((u8 *)D_8AF263C0 + 6);
    }
    switch (D_8AF2ECF8) {
    case 0: limit = D_8AF2E89C - 1; break;
    case 1: limit = D_8AF2E89E - 1; break;
    case 2: limit = (D_8AF2E8A0 - 1) / 2; break;
    }
    if (*(s16 *)(state + 4) == 0) {
        moved = 0;
        if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
            func_8AF00130(3);
            result = 0xA;
        } else if ((buttons & 0x800) && (D_8AF2E89A > 0)) {
            func_8AF00130(1);
            D_8AF2E89A--;
            moved = 1;
        } else if ((buttons & 0x400) && (D_8AF2E89A < limit)) {
            func_8AF00130(1);
            D_8AF2E89A++;
            moved = 1;
        }
        if (moved != 0) {
            func_8AC0686C(state, D_8AF2E89A);
        }
    }
    if (limit < D_8AF2E89A) {
        D_8AF2E89A = limit;
    }
    if ((old_x != D_8AF2E898) || (old_y != D_8AF2E89A) || (old_mode != D_8AF2ECF8)) {
        switch (D_8AF2ECF8) {
        case 0:
            func_8AF0C1D8(D_8AF2D5C8 + D_8AF2E89A * 0x14);
            break;
        case 1:
            func_8AF0C1D8(D_8AF2D758 + D_8AF2E89A * 0x14);
            break;
        case 2:
            func_8AF0C1D8((s32)(D_8AF2D8E8 + (D_8AF2E898 * 0x14) + (u32)(D_8AF2E89A * 2) * 0x14));
            break;
        }
        func_8AF0D704();
    }
    switch (D_8AF2ECF8) {
    case 0:
        flag0 = 1;
        flag1 = 0;
        flag2 = 0;
        break;
    case 2:
        flag0 = 0;
        flag1 = 1;
        flag2 = 0;
        break;
    case 1:
        flag0 = 0;
        flag1 = 0;
        flag2 = 1;
        break;
    }
    func_8AC0602C(D_8AF2EA28, D_8AF2BDC6, flag0);
    func_8AC060E4(D_8AF2EAA0, D_8AF2BDC6, flag0);
    func_8AC0602C(D_8AF2EB18, D_8AF2BDC6, flag1);
    func_8AC060E4(D_8AF2EB90, D_8AF2BDC6, flag1);
    func_8AC0602C(D_8AF2EC08, D_8AF2BDC6, flag2);
    func_8AC060E4(D_8AF2EC80, D_8AF2BDC6, flag2);
    return result;
}
/* mkdraft:func_8AF0E190 end */

extern void func_8AC04418(s32, s32, s32, s32);
extern void func_8AC0077C(s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495BC(s32, s32, s32);
extern void func_800499EC(void);
extern void func_8AC00738(void);
extern s32 func_8AC0665C(void *, s16);
extern s32 func_8AC0672C(void *, s16);
extern void func_8AC05F00(void *);
extern void func_8004B314(s16, s16, s32, s32);
extern void func_8004D998(s32, s32, u8 *, s32, s32);
// Declared with an int return (as an implicit declaration would give); the call's v0 def affects register allocation.
extern s32 Ui_DrawGradientQuad(s32, s32, s32, s32, void *, void *);
extern u8 D_8AF26450;
extern u8 D_8AF26454;
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern u8 D_8AC081B0[][4];
extern s16 D_8AF2F990;
extern s16 D_8AF2F992;
extern s16 D_8AF2F994;
extern u32 D_8AF2BDC4;
extern void *D_8AF2E8A4, *D_8AF2E8A8, *D_8AF2E8AC;
extern s16 D_8AF2E894, D_8AF2E896, D_8AF2E898, D_8AF2E89A;
extern s16 D_8AF2ECF8, D_8AF2ECFA, D_8AF2ECFC, D_8AF2ECFE;
extern u8 D_8AF2E9F8[], D_8AF2EA08[], D_8AF2EA18[];
extern u8 D_8AF2EA28[], D_8AF2EAA0[], D_8AF2EB18[], D_8AF2EB90[], D_8AF2EC08[], D_8AF2EC80[];
extern u8 D_8AF2ED08[];
extern u8 D_8AF2D5C8[], D_8AF2D758[], D_8AF2D8E8[];
extern u8 *D_8AF2E888;

void func_8AF0E838(void) {
    u8 *col;
    u8 *base;
    s32 i;
    s32 c;
    u8 *sel;
    s16 x;
    s16 y;
    s16 x2;
    s16 y2;
    s16 px;
    s16 py;
    u8 a;
    u8 alpha;
    u8 *p;
    s32 done;
    u8 off;

    if (D_8AF2F990 < 10) {
        D_8AF2F990++;
    }
    switch (D_8AF2ECF8) {
    case 0:
        sel = D_8AF2E9F8;
        break;
    case 1:
        sel = D_8AF2EA08;
        break;
    case 2:
        sel = D_8AF2EA18;
        break;
    default:
        sel = D_8AF2E9F8;
        break;
    }
    alpha = (D_8AF2BDC4 & 0x10) ? 0xFF : 0x80;

    base = D_8AF2E8A4;
    x = *(s16 *)(base + 8) - 3;
    y = *(s16 *)(base + 0xA);
    x2 = *(s16 *)(base + 0xC) + *(s16 *)(base + 8);
    y2 = *(s16 *)(base + 0xE) + *(s16 *)(base + 0xA);
    func_8AC04418(x, y, x2, y2);
    func_8AC0077C(x, y, x2, y2);
    func_800498C4();
    func_800496A4(4, 0);
    D_8AF2E888 = D_8AF2D5C8;
    for (i = 0; i < 0x14; i++, D_8AF2E888 += 0x14) {
        if (D_8AF2E888[0] == 0) {
            i = 0;
            break;
        }
        px = *(s16 *)((u8 *)D_8AF2E8A4 + 8) + 7;
        py = *(s16 *)((u8 *)D_8AF2E8A4 + 0xA) + i * 20 - *(s16 *)D_8AF2E9F8 + 2;
        if (y - 0x14 < py && py < y2 + 0x14) {
            a = (D_8AF2E888[0xA] == 1) ? alpha : 0xFF;
            col = D_8AC081B0[D_8AF2E888[5]];
            func_8004972C(col[0], col[1], col[2], a);
            func_800495BC(px, py, *(s32 *)(D_8AF2E888 + 0xC));
        }
    }
    func_800499EC();
    func_8AC00738();

    base = D_8AF2E8A8;
    x = *(s16 *)(base + 8) - 3;
    y = *(s16 *)(base + 0xA);
    x2 = *(s16 *)(base + 0xC) + *(s16 *)(base + 8);
    y2 = *(s16 *)(base + 0xE) + *(s16 *)(base + 0xA);
    func_8AC04418(x, y, x2, y2);
    func_8AC0077C(x, y, x2, y2);
    func_800498C4();
    func_800496A4(4, 0);
    D_8AF2E888 = D_8AF2D758;
    for (i = 0; i < 0x14; i++, D_8AF2E888 += 0x14) {
        if (D_8AF2E888[0] == 0) {
            break;
        }
        px = *(s16 *)((u8 *)D_8AF2E8A8 + 8) + 7;
        py = *(s16 *)((u8 *)D_8AF2E8A8 + 0xA) + i * 20 - *(s16 *)D_8AF2EA08 + 2;
        if (y - 0x14 < py && py < y2 + 0x14) {
            a = (D_8AF2E888[0xA] == 1) ? alpha : 0xFF;
            col = D_8AC081B0[D_8AF2E888[5]];
            func_8004972C(col[0], col[1], col[2], a);
            func_800495BC(px, py, *(s32 *)(D_8AF2E888 + 0xC));
        }
    }
    i = 0;
    func_8AC00738();
    func_800499EC();

    base = D_8AF2E8AC;
    x = *(s16 *)(base + 8) - 3;
    y = *(s16 *)(base + 0xA);
    x2 = *(s16 *)(base + 0xC) + *(s16 *)(base + 8);
    y2 = *(s16 *)(base + 0xE) + *(s16 *)(base + 0xA);
    func_8AC04418(x, y, x2, y2);
    func_8AC0077C(x, y, x2, y2);
    func_800498C4();
    func_800496A4(4, 0);
    D_8AF2E888 = D_8AF2D8E8;
    done = 0;
    c = 0;
    do {
        for (c = 0; c != 2; c++) {
            if (D_8AF2E888[0] == 0) {
                done = 1;
                break;
            }
            px = *(s16 *)((u8 *)D_8AF2E8AC + 8) + c * 120 + 7;
            py = *(s16 *)((u8 *)D_8AF2E8AC + 0xA) + i * 20 - *(s16 *)D_8AF2EA18 + 2;
            if (y - 0x14 < py && py < y2 + 0x14) {
                a = (D_8AF2E888[0xA] == 1) ? alpha : 0xFF;
                col = D_8AC081B0[D_8AF2E888[5]];
                func_8004972C(col[0], col[1], col[2], a);
                func_800495BC(px, py, *(s32 *)(D_8AF2E888 + 0xC));
            }
            D_8AF2E888 += 0x14;
        }
        i++;
    } while (done == 0 && i != 0xC8);
    func_8AC00738();
    func_800499EC();

    off = 0xE;
    func_8AC04418(*(s16 *)(D_8AF2E8C0 + 8), *(s16 *)(D_8AF2E8C0 + 0xA),
                  *(s16 *)(D_8AF2E8C0 + 0xC) + *(s16 *)(D_8AF2E8C0 + 8),
                  *(s16 *)(D_8AF2E8C0 + off) + *(s16 *)(D_8AF2E8C0 + 0xA));
    c = D_8AF2E8C8;
    Ui_DrawGradientQuad(*(s16 *)(c + 8), *(s16 *)(c + 0xA), 0x28, 0x28, &D_8AF26450, &D_8AF26454);
    gSPDisplayList(D_800D0510++, D_80094E38);
    c = D_8AF2E8C8;
    func_8004D998(*(s16 *)(c + 8), *(s16 *)(c + 0xA), D_8AF2ED08, 0, 0);
    if (func_8AC0665C(D_8AF2E9F8, D_8AF2ECFA) != 0) {
        func_8AC05F00(D_8AF2EA28);
    }
    if (func_8AC0672C(D_8AF2E9F8, D_8AF2ECFA) != 0) {
        func_8AC05F00(D_8AF2EAA0);
    }
    if (func_8AC0665C(D_8AF2EA18, D_8AF2ECFE) != 0) {
        func_8AC05F00(D_8AF2EB18);
    }
    if (func_8AC0672C(D_8AF2EA18, D_8AF2ECFE) != 0) {
        func_8AC05F00(D_8AF2EB90);
    }
    if (func_8AC0665C(D_8AF2EA08, D_8AF2ECFC) != 0) {
        func_8AC05F00(D_8AF2EC08);
    }
    if (func_8AC0672C(D_8AF2EA08, D_8AF2ECFC) != 0) {
        func_8AC05F00(D_8AF2EC80);
    }
    if (*(s16 *)(sel + 4) == 0) {
        D_8AF2F992 = D_8AF2E894 + D_8AF2E898 * 120;
        D_8AF2F994 = D_8AF2E896 + D_8AF2E89A * 20 - *(s16 *)sel - 5;
    }
    func_8004B314(D_8AF2F992, D_8AF2F994, 0x6E, 0x1E);
}
#endif
