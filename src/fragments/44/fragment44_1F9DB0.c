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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F9DB0/func_8AF0CA00.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F9DB0/func_8AF0CE6C.s")

extern u8 *D_8AF2E888;
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F9DB0/func_8AF0D7C8.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F9DB0/func_8AF0E190.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F9DB0/func_8AF0E838.s")
#endif
