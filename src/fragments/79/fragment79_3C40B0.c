#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3C40B0/func_84154820.s")

extern u8 *D_841951F8[];
extern u8 D_8419E780[];
void func_841548CC(u8 arg0) {
    D_8419E780[arg0 * 0xCC] = D_841951F8[arg0][8];
    D_8419E780[arg0 * 0xCC + 1] = D_841951F8[arg0][0xA];
    D_8419E780[arg0 * 0xCC + 2] = D_841951F8[arg0][9];
    D_8419E780[arg0 * 0xCC + 3] = D_841951F8[arg0][0xB];
    D_8419E780[arg0 * 0xCC + 4] = D_841951F8[arg0][0xC];
    D_8419E780[arg0 * 0xCC + 5] = D_841951F8[arg0][0xD];
    D_8419E780[arg0 * 0xCC + 6] = D_841951F8[arg0][0xE];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3C40B0/func_84154948.s")

extern u8 D_8419E920[];
void func_84154AD4(void) {
    _bzero(D_8419E780, 0x19C);
    _bzero(D_8419E920, 0x4D8);
}

u8 *func_84154B0C(void) {
    return D_8419E780;
}

extern u8 D_8419E918;
u8 func_84154B18(void) {
    return D_8419E918;
}

extern u8 D_8419E91A;
u8 func_84154B24(void) {
    return D_8419E91A;
}

u8 *func_84154B30(u8 arg0) {
    return D_8419E780 + arg0 * 0xCC;
}

u8 *func_84154B64(u8 arg0) {
    return D_8419E780 + arg0 * 0xCC + 8;
}

s32 func_84154B9C(u8 arg0, u16 arg1) {
    s32 i = 0;
    u8 *record = D_841951F8[arg0];

    for (; i < record[8]; i++) {
        if ((*(u16 *)(record + i * 0x58 + 0x3E) != 0) && (*(u8 *)(record + i * 0x58 + 0x3C) & arg1)) {
            return 1;
        }
    }
    return 0;
}


extern u8 *D_84195208[];
extern u8 *D_84195200[];
void func_84154C10(u8 *arg0, u8 arg1) {
    u8 *value = D_84195208[arg1];
    u8 *aux = D_84195200[arg1];
    arg0[0] = value[0];
    arg0[1] = aux[1];
    *(u16 *)(arg0 + 0x26) = aux[0x24];
    arg0[2] = value[1];
    arg0[3] = value[2];
    arg0[4] = value[5];
    arg0[5] = value[6];
    arg0[6] = value[7];
    arg0[7] = value[8];
    arg0[8] = value[9];
    arg0[9] = value[0xA];
    arg0[0xA] = value[0xB];
    arg0[0xB] = value[0xC];
    arg0[0xC] = aux[0x1D];
    *(u16 *)(arg0 + 0x28) = *(u16 *)(aux + 0x26);
    *(u16 *)(arg0 + 0x2A) = *(u16 *)(aux + 0x28);
    *(u16 *)(arg0 + 0x2C) = *(u16 *)(value + 0x32);
    *(u16 *)(arg0 + 0x2E) = *(u16 *)(value + 0x34);
    *(u16 *)(arg0 + 0x30) = *(u16 *)(value + 0x36);
    *(u16 *)(arg0 + 0x32) = *(u16 *)(value + 0x38);
    *(u16 *)(arg0 + 0x34) = *(u16 *)(value + 0x3A);
    *(u16 *)(arg0 + 0x36) = *(u16 *)(value + 0x3C);
    *(u16 *)(arg0 + 0x38) = *(u16 *)(value + 0x3E);
    *(u16 *)(arg0 + 0x3A) = *(u16 *)(value + 0x40);
    *(u16 *)(arg0 + 0x3C) = *(u16 *)(value + 0x42);
    *(u16 *)(arg0 + 0x3E) = *(u16 *)(value + 0x44);
    arg0[0xD] = value[0x1E];
    arg0[0xE] = value[0x1F];
    arg0[0xF] = value[0x20];
    arg0[0x10] = value[0x21];
    arg0[0x11] = value[0x22];
    arg0[0x12] = value[0x23];
    arg0[0x13] = value[0x24];
    arg0[0x14] = aux[0x1C];
    *(u16 *)(arg0 + 0x40) = *(u16 *)(value + 0x2E);
    *(u16 *)(arg0 + 0x42) = *(u16 *)(value + 0x46);
    arg0[0x15] = value[0xD];
    arg0[0x16] = value[0xE];
    arg0[0x17] = value[0xF];
    arg0[0x18] = value[0x10];
    arg0[0x19] = value[0x11];
    arg0[0x1A] = value[0x12];
    arg0[0x1B] = value[0x13];
    arg0[0x1C] = value[0x14];
    arg0[0x1D] = value[0x15];
    arg0[0x1E] = value[0x16];
    arg0[0x1F] = value[0x17];
    arg0[0x20] = value[0x18];
    arg0[0x21] = value[0x19];
    arg0[0x23] = value[0x1B];
    arg0[0x24] = value[0x26];
    arg0[0x25] = value[0x27];
    *(u16 *)(arg0 + 0x44) = *(u32 *)(value + 0x4C);

    arg0[0x22] = value[0x1A];
    *(u16 *)(arg0 + 0x46) = *(u16 *)(value + 0x30);
    *(u32 *)(arg0 + 0x48) = value[0x2A];
}

extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);

void func_84154DF8(u8 *arg0, u8 arg1, u8 arg2) {
    u8 *p;
    p = D_841951F8[arg1] + arg2 * 88 + 0x18;
    arg0[0] = p[0];
    arg0[1] = p[1];
    *(u16 *)(arg0 + 0x26) = p[0x24];
    arg0[2] = func_8006397C(p[0]);
    arg0[3] = func_800639C0(p[0]);
    arg0[4] = p[2];
    arg0[5] = p[3];
    arg0[6] = p[4];
    arg0[7] = p[5];
    arg0[8] = p[0x18];
    arg0[9] = p[0x19];
    arg0[0xA] = p[0x1A];
    arg0[0xB] = p[0x1B];
    arg0[0xC] = p[0x1D];
    *(u16 *)(arg0 + 0x28) = *(u16 *)(p + 0x26);
    *(u16 *)(arg0 + 0x2A) = *(u16 *)(p + 0x28);
    *(u16 *)(arg0 + 0x2C) = *(u16 *)(p + 0x2A);
    *(u16 *)(arg0 + 0x2E) = *(u16 *)(p + 0x2C);
    *(u16 *)(arg0 + 0x30) = *(u16 *)(p + 0x2E);
    *(u16 *)(arg0 + 0x32) = *(u16 *)(p + 0x30);
    *(u16 *)(arg0 + 0x34) = *(u16 *)(p + 0x32);
    *(u16 *)(arg0 + 0x36) = *(u16 *)(p + 0x2A);
    *(u16 *)(arg0 + 0x38) = *(u16 *)(p + 0x2C);
    *(u16 *)(arg0 + 0x3A) = *(u16 *)(p + 0x2E);
    *(u16 *)(arg0 + 0x3C) = *(u16 *)(p + 0x30);
    *(u16 *)(arg0 + 0x3E) = *(u16 *)(p + 0x32);
    arg0[0xD] = 7;
    arg0[0xE] = 7;
    arg0[0xF] = 7;
    arg0[0x10] = 7;
    arg0[0x11] = 7;
    arg0[0x12] = 7;
    arg0[0x13] = 7;
    arg0[0x14] = p[0x1C];
    *(u16 *)(arg0 + 0x40) = *(u16 *)(p + 0x16);
    *(u16 *)(arg0 + 0x42) = 0;
    arg0[0x15] = 0;
    arg0[0x16] = 0;
    arg0[0x17] = 0;
    arg0[0x18] = 0;
    arg0[0x19] = 0;
    arg0[0x1A] = 0;
    arg0[0x1B] = 0;
    arg0[0x1C] = 0;
    arg0[0x1D] = 0;
    arg0[0x1E] = 0;
    arg0[0x1F] = 0;
    arg0[0x20] = 0;
    arg0[0x21] = 0;
    arg0[0x23] = 0;
    arg0[0x24] = 0;
    arg0[0x25] = 0;
    *(u16 *)(arg0 + 0x44) = 0;
    arg0[0x22] = 0;
    *(u16 *)(arg0 + 0x46) = 0;
    *(s32 *)(arg0 + 0x48) = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3C40B0/func_84154FC4.s")

/* mkdraft:func_841551D4 begin */
extern u8 *func_84156590(u8, u8);
extern u8 *func_841565E0(u8 arg0);



void func_841551D4(u8 *arg0, u8 arg1, u8 arg2) {
    u8 *sp1C;
    u8 *temp_v0;
    u8 *temp_v1;
    u8 *temp_a1;

    sp1C = func_841565E0(arg1);
    temp_v0 = func_84156590(arg1, arg2);
    temp_v1 = D_84195208[arg1];
    temp_a1 = D_841951F8[arg1] + arg2 * 0x58;
    arg0[0] = temp_v1[0];
    arg0[1] = temp_v0[0xB];
    *(s16 *)(arg0 + 0x26) = *(u8 *)(temp_a1 + 0x3C);
    temp_a1 += 0x18;
    arg0[2] = temp_v1[1];
    arg0[3] = temp_v1[2];
    arg0[4] = sp1C[1];
    arg0[5] = sp1C[2];
    arg0[6] = sp1C[3];
    arg0[7] = sp1C[4];
    if (!sp1C && !sp1C && !sp1C) {} // FAKE: empty test retained for code generation.
    arg0[8] = temp_v1[9];
    arg0[9] = temp_v1[0xA];
    arg0[0xA] = temp_v1[0xB];
    arg0[0xB] = temp_v1[0xC];
    arg0[0xC] = temp_a1[0x1D];
    *(u16 *)(arg0 + 0x28) = *(u16 *)(temp_a1 + 0x26);
    *(u16 *)(arg0 + 0x2A) = *(u16 *)(temp_a1 + 0x28);
    *(u16 *)(arg0 + 0x2C) = *(u16 *)(temp_v0 + 0xE);
    *(u16 *)(arg0 + 0x2E) = *(u16 *)(temp_v0 + 0x10);
    *(u16 *)(arg0 + 0x30) = *(u16 *)(temp_v0 + 0x12);
    *(u16 *)(arg0 + 0x32) = *(u16 *)(temp_v0 + 0x14);
    *(u16 *)(arg0 + 0x34) = *(u16 *)(temp_v0 + 0x16);
    *(u16 *)(arg0 + 0x36) = *(u16 *)(sp1C + 6);
    *(u16 *)(arg0 + 0x38) = *(u16 *)(sp1C + 8);
    *(u16 *)(arg0 + 0x3A) = *(u16 *)(sp1C + 0xA);
    *(u16 *)(arg0 + 0x3C) = *(u16 *)(sp1C + 0xC);
    *(u16 *)(arg0 + 0x3E) = *(u16 *)(sp1C + 0xE);
    arg0[0xD] = temp_v1[0x1E];
    arg0[0xE] = temp_v1[0x1F];
    arg0[0xF] = temp_v1[0x20];
    arg0[0x10] = temp_v1[0x21];
    arg0[0x11] = temp_v1[0x22];
    arg0[0x12] = temp_v1[0x23];
    arg0[0x13] = temp_v1[0x24];
    arg0[0x14] = temp_v0[0xC];
    *(u16 *)(arg0 + 0x40) = *(u16 *)(temp_a1 + 0x16);
    *(u16 *)(arg0 + 0x42) = *(u16 *)(temp_v1 + 0x46);
    arg0[0x15] = temp_v1[0xD];
    arg0[0x16] = temp_v1[0xE];
    arg0[0x17] = temp_v1[0xF];
    arg0[0x18] = temp_v1[0x10];
    arg0[0x19] = temp_v1[0x11];
    arg0[0x1A] = temp_v1[0x12];
    arg0[0x1B] = temp_v1[0x13];
    arg0[0x1C] = temp_v1[0x14];
    arg0[0x1D] = temp_v1[0x15];
    arg0[0x1E] = temp_v1[0x16];
    arg0[0x1F] = temp_v1[0x17];
    arg0[0x20] = temp_v1[0x18];
    arg0[0x21] = temp_v1[0x19];
    arg0[0x23] = temp_v1[0x1B];
    arg0[0x24] = temp_v1[0x26];
    arg0[0x25] = temp_v1[0x27];
    *(s16 *)(arg0 + 0x44) = *(s32 *)(temp_v1 + 0x4C);
    arg0[0x22] = temp_v1[0x1A];
    *(u16 *)(arg0 + 0x46) = *(u16 *)(temp_v1 + 0x30);
    *(s32 *)(arg0 + 0x48) = temp_v1[0x2A];
}
/* mkdraft:func_841551D4 end */

void func_8415541C(u8 *arg0, u8 arg1, u8 arg2) {
    u8 *value;
    value = D_841951F8[arg1] + arg2 * 0x58;
    arg0[0] = value[0x1A];
    value += 0x18;
    arg0[1] = value[3];
    arg0[2] = value[4];
    arg0[3] = value[5];
    arg0[8] = value[1];
    arg0[9] = value[0x1C];
    *(u16 *)(arg0 + 0xA) = *(u16 *)(value + 0x2A);
    *(u16 *)(arg0 + 0xC) = *(u16 *)(value + 0x2C);
    *(u16 *)(arg0 + 0xE) = *(u16 *)(value + 0x2E);
    *(u16 *)(arg0 + 0x10) = *(u16 *)(value + 0x30);
    *(u16 *)(arg0 + 0x12) = *(u16 *)(value + 0x32);
}

extern u8 *func_84156590(u8, u8);
void func_841554B4(u8 *arg0, u8 arg1, u8 arg2) {
    u8 *value;
    value = func_84156590(arg1, arg2);
    arg0[0] = value[1];
    arg0[1] = value[2];
    arg0[2] = value[3];
    arg0[3] = value[4];
    arg0[8] = value[0xB];
    arg0[9] = value[0xC];
    *(u16 *)(arg0 + 0xA) = *(u16 *)(value + 0xE);
    *(u16 *)(arg0 + 0xC) = *(u16 *)(value + 0x10);
    *(u16 *)(arg0 + 0xE) = *(u16 *)(value + 0x12);
    *(u16 *)(arg0 + 0x10) = *(u16 *)(value + 0x14);
    *(u16 *)(arg0 + 0x12) = *(u16 *)(value + 0x16);
}

s32 func_84155544(u8 *arg0, u8 arg1) {
    s32 result;
    result = (arg1 == arg0[2]);
    if (result == 0) {
        result = (arg1 == arg0[3]);
    }
    return result;
}

extern void func_80063454(u8, u8, u8, s32);
void func_84155574(u8 *arg0, u8 arg1) {
    func_80063454(arg1, arg0[2], arg0[3], (arg0[0x15] & 8) != 0);
}

extern u8 func_80062D98(u8 move);
extern u8 func_80062D5C(u8 move);
extern void _bcopy(void *source, u8 *destination, s32 size);
s32 BattleRecord_HasPoweredMoveOfType(u8 *record, u8 type) {
    s32 i;
    const u8 *cursor;
    u8 move;

    i = 0;
    cursor = record;
    for (; i != 4; i++, cursor++) {
        move = cursor[4];
        if (move == 0) {
            return 0;
        }
        if (type == func_80062D98((u8)move) && func_80062D5C((u8)move) >= 2) {
            return 1;
        }
    }
    return 0;
}

s32 BattleRecord_HasMove(u8 *record, u8 move) {
    s32 i;
    u8 current;

    for (i = 0; i < 4; i++) {
        current = record[i + 4];
        if (current == move) {
            return 1;
        }
    }
    return 0;
}

extern u8 func_80062D20(u8);
s32 func_841556C4(u8 *arg0, u8 arg1)
{
    s32 var_s0;
    u8 *var_s1;
    u8 var_s3;
    s32 var_s4;
    s32 var_s5;
    u8 temp_a0;

    var_s3 = arg1;
    var_s0 = 0;
    var_s1 = arg0;
    var_s4 = 0xFF;
    var_s5 = 4;
loop_1:
    temp_a0 = var_s1[4];
    if (temp_a0 != var_s4) {
        if (var_s3 == func_80062D20(temp_a0)) {
            return 1;
        }
        var_s0 += 1;
        var_s1 += 1;
        if (var_s0 == var_s5) {
            goto block_5;
        }
        goto loop_1;
    }
block_5:
    return 0;
}

void BattleState_PushSnapshot(void) {
    _bcopy(D_8419E780, &D_8419E920[D_8419E920[0]++ * 0x19C + 4], 0x19C);
}

void func_841557B0(void)
{
  u8 temp_v0;
  temp_v0 = ((*D_8419E920) - 1) & 0xFF;
 *D_8419E920 = temp_v0; _bcopy((D_8419E920 + (temp_v0 * 0x19C)) + 4, D_8419E780, 0x19C);
}
#endif
