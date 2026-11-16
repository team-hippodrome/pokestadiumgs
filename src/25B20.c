#include "229E0.h"

#ifdef VERSION_US

#pragma GLOBAL_ASM("hand_asm/229E0/func_80024F20_manual.s")

void func_800251F8(s32 arg0) {
    switch (arg0) {
    case 0:
        func_80018728(0x82040700U, 0);
        func_80018704(0x41040000, 0.63f);
        return;
    case 1:
        func_80018728(0x83040000U, 0);
        return;
    case 2:
        func_80018728(0x83040000U, 0);
        func_80018728(0x82040700U, 0);
        func_80018704(0x41040000, 0.63f);
        return;
    default:
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/25B20/func_80025294.s")

void func_80025848(s32 arg0) {
    switch (arg0) {
    case 42:
        func_8001874C(0x06020005, 1);
        return;
    case 18:
    case 113:
    case 114:
    case 115:
        func_8001874C(0x06020205, 1);
        return;
    case 62:
        func_8001874C(0x06020305, 1);
        return;
    case 65:
        func_8001874C(0x06020405, 1);
        return;
    case 78:
    case 92:
        func_8001874C(0x06020505, 1);
        return;
    }
}

/* mkdraft:func_800258F4 begin */
extern u8 D_80090AB4;
extern u8 D_80090AB0[];
extern u8 D_80090AAC[];

// Flips bit 0 of the byte at 0x80090AB4, then sends that byte in bits 8-15 of
// command 0x0604xxxx for arg0 1..18 (18 cases, all reaching one shared body).
// FAKE: D_80090AB0[4], D_80090AB4 and D_80090AAC[8] are three spellings of the same
// byte; the linker resolves all three to 0x80090AB4 (build/pokestadiumgs-us.map). One
// spelling makes uopt CSE the address into a single register and reuse it, which drops
// the per-access reload: with D_80090AB4 everywhere this file scores 745 (rscore 1485).


void func_800258F4(s32 arg0) {
    D_80090AB0[4] = D_80090AB4 ^ 1;
    switch (arg0) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        func_8001874C(((D_80090AAC[8] & 0xFF) << 8) | 0x06040000, arg0);
        break;
    }
}
/* mkdraft:func_800258F4 end */

void Audio_ApplyCommandPreset(s32 preset) {
    s32 first;
    s32 second = 0;
    s32 third = 0;
    s32 fourth = 0;
    switch (preset) {
    case 10:
        first = 22;
        break;
    case 1:
        first = 1;
        second = 4;
        fourth = 3;
        func_8001874C(0x06020400, 21);
        break;
    case 2:
        first = 1;
        second = 6;
        third = 7;
        fourth = 5;
        break;
    case 3:
        first = 1;
        second = 9;
        fourth = 8;
        break;
    case 4:
        first = 1;
        second = 11;
        fourth = 10;
        break;
    case 5:
        first = 1;
        second = 13;
        third = 14;
        fourth = 12;
        break;
    case 6:
        first = 1;
        fourth = 15;
        break;
    case 7:
        first = 1;
        second = 17;
        third = 18;
        fourth = 16;
        break;
    case 8:
        first = 1;
        second = 20;
        fourth = 19;
        break;
    default:
        return;
    }
    func_8001874C(0x06020000, (s8)first);
    func_8001874C(0x06020100, (s8)second);
    func_8001874C(0x06020200, (s8)third);
    func_8001874C(0x06020300, (s8)fourth);
}

void func_80025ACC(s32 arg0) {
    switch (arg0) {
    case 7:
        func_8001874C(0x06020405, 1);
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
        func_8001874C(0x06020000, 2);
        func_8001874C(0x06020105, 1);
        func_8001874C(0x06020205, 1);
        func_8001874C(0x06020305, 1);
        return;
    }
}

void Audio_SetPreset(s32 preset) {
    u32 bank;
    s32 sound;
    switch (preset) {
    case 1:
        D_80090BA4 = 1;
        bank = 0;
        sound = 1;
        break;
    case 2:
        bank = 1;
        sound = 2;
        break;
    case 3:
        bank = 1;
        sound = 3;
        break;
    case 4:
        bank = 2;
        sound = 4;
        break;
    case 5:
        bank = 2;
        sound = 5;
        break;
    case 6:
        bank = 0;
        sound = 6;
        break;
    case 7:
        bank = 1;
        sound = 7;
        break;
    case 8:
        bank = 1;
        sound = 8;
        break;
    case 9:
        bank = 2;
        sound = 9;
        break;
    case 10:
        bank = 2;
        sound = 10;
        break;
    case 11:
        bank = 2;
        sound = 11;
        break;
    case 12:
        bank = 1;
        sound = 12;
        break;
    default:
        return;
    }
    func_8001874C(0x06030000 | ((u8)bank << 8), (s8)sound);
}

#endif
