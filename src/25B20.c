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

extern u8 D_80090AA0, D_80090BA8;

extern u32 func_800194A0(void);

extern void func_800226C0(s32);

void func_80025294(u32 arg0, s32 arg1, s32 arg2) {
    s16 pan = -1;
    s16 volume = -1;
    f32 pitch;
    u8 *audio_state = &D_80090AA0;
    switch (arg0) { case 40: if (arg0 == *(u32 *)(audio_state + 8)) {

        func_8001874C(((audio_state[0] & 0xFF) << 8) | 0x06020000U | 5, 1);
    }
    break; }
    if (arg0 == 107) D_80090BA8 = 1;
    switch (arg0) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 44:
    case 46:
    case 47:
    case 48:
    case 49:
    case 59:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 80:
    case 81:
    case 82:
    case 87:
    case 89:
    case 90:
    case 93:
    case 94:
    case 103:
    case 104:
    case 106:
    case 107:
    case 108:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
    case 124:
        audio_state[0] ^= 1;
        func_8001874C(((audio_state[0] & 0xFF) << 8) | 0x06020000U, (s8)arg0);

        func_80018704(((audio_state[0] & 0xFF) << 8) | 0x04020000U, 1.0f);
        break;
    case 95:
        audio_state[0] ^= 1;
        if ((func_800194A0() % 3) == 0) arg0 = 94;
        pitch = (f32)(func_800194A0() % 10) / 100.0f + 0.95f;

        func_8001874C(((audio_state[0] & 0xFF) << 8) | 0x06020000U, (s8)arg0);

        func_80018704(((audio_state[0] & 0xFF) << 8) | 0x04020000U, pitch);
        break;
    case 66:
    case 67:
    case 68:
    case 69:
        func_800226C0(163);
        audio_state[0] ^= 1;
        func_8001874C(((audio_state[0] & 0xFF) << 8) | 0x06020000U, (s8)arg0);
        break;
    case 88:
        func_800226C0(3);
        audio_state[0] ^= 1;
        func_8001874C(((audio_state[0] & 0xFF) << 8) | 0x06020000U, (s8)arg0);
        break;
    case 45:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 105:
    case 109:
    case 110:
    case 111:
    case 112:
        audio_state[4] = (u8)(audio_state[4] + 1) % 3;
        func_8001874C((((audio_state[4] + 3) & 0xFF) << 8) | 0x06020000U, (s8)arg0);
        audio_state[16] = audio_state[4] + 3;
        break;
    case 10:
    case 70:
        audio_state[4] = (u8)(audio_state[4] + 1) % 2;
        func_8001874C((((audio_state[4] + 3) & 0xFF) << 8) | 0x06020000U, (s8)arg0);
        break;
    case 65537:
    case 65538:
    case 65539:
    case 65540:
    case 65541:
    case 65542:
    case 65543:
    case 65544:
    case 65545:
    case 65546:
    case 65547:
    case 65548:
    case 65549:
    case 65550:
    case 65551:
    case 65552:
    case 65553:
    case 65554:
    case 65555:
    case 65556:
    case 65557:
        arg0 &= ~0x10000;
        func_8001874C(0x06020600U, (s8)arg0);
        break;
    case 42:
        func_8001874C(0x06020000U, (s8)arg0);
        break;
    case 43:
        func_8001874C(0x06020100U, (s8)arg0);
        break;
    case 18:
    case 113:
    case 114:
    case 115:
    case 116:
    case 117:
    case 118:
    case 125:
    case 126:
    case 127:
        func_8001874C(0x06020200U, (s8)arg0);
        break;
    case 60:
        func_8001874C(0x06020200U, (s8)arg0);
        audio_state[12] = 0;
        break;
    case 62:
        if (audio_state[12] == 0) {
            func_8001874C(0x06020300U, (s8)arg0);
            audio_state[12] = 1;
        } else {
            func_80018704(0x04020300U, 1.2f);
        }
        break;
    case 61:
        func_80025848(62);
        func_8001874C(0x06020200U, (s8)arg0);
        func_80018704(0x04020300U, 1.0f);
        audio_state[12] = 0;
        break;
    case 63:
    case 64:
    case 65:
    case 91:
        func_8001874C(0x06020400U, (s8)arg0);
        break;
    case 78:
    case 79:
    case 92:
        func_80025848(78);
        func_8001874C(0x06020500U, (s8)arg0);
        break;
    case 83:
    case 85:
        func_8001874C(0x06020400U, (s8)arg0);
        break;
    case 84:
    case 86:
        func_8001874C(0x06020500U, (s8)arg0);
        break;
    default:
        return;
    }
    (*(u32 *)(audio_state + 8)) = arg0;
    switch (arg0) {
    case 102:
        pan = arg1 == 0 ? 10 : 117;
        switch (arg2) {
        case 0: volume = 127; break;
        case 1: volume = 80; break;
        case 2: volume = 35; break;
        default: volume = 0;
        }
        break;
    case 101:
        pan = arg1 == 0 ? 10 : 117;
        volume = 127;
        break;
    }
    if (pan != -1) func_8001874C(0x03020000U | ((audio_state[16] & 0xFF) << 8), (s8)pan);
    if (volume != -1) func_80018704(0x02020000U | ((audio_state[16] & 0xFF) << 8), volume / 127.0f);
}
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
