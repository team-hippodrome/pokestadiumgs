#include "229E0.h"

#ifdef VERSION_US

#pragma GLOBAL_ASM("asm/us/nonmatchings/23DA0/func_800231A0.s")

void func_800238C4(void) {
    if (D_80090B80 == 2) {
        D_80090220 = 0;
        func_80018728(0x83010000U, 0xB4);
        D_8009022C = -1;
    }
}

void func_8002390C(s32 arg0) {
    if (D_80090B80 == 2) {
        D_80090220 = 0;
        func_80018728(0x83010000U, arg0);
        D_8009022C = -1;
    }
}

void func_80023954(void) {
    func_8001874C(0x06010005, 1);
}

u8 Audio_GetSpeciesMaskBit(u32 species) {
    u8 value;
    u8 bit;
    u8 mask;
    value = D_80090200[(u8)((species - 1) >> 3)];
    bit = (species - 1) & 7;
    mask = 1 << (7 - bit);
    value &= mask;
    return value;
}

void func_800239B4(s32 arg0, s32 arg1) {
    D_80090224 = arg0;
    D_80090228 = arg1;
}

void func_800239C8(void) {
    if (D_80090224 >= 0) {
        D_80090224--;
        if (D_80090224 < 0) {
            func_8002390C(D_80090228);
            D_80090228 = 0;
        }
    }
}

s32 func_80023A10(u8 arg0, u8 arg1) {
    return D_8009061C[arg0][arg1];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/23DA0/func_80023A3C.s")

void func_80024180(u32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
    case 26:
    case 27:
    case 28:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
        func_8001874C(0x06020005, 1);
        return;
    case 30:
    case 35:
        func_8001874C(0x06020105, 1);
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/23DA0/func_8002421C.s")

extern u8 D_8009065E[][4];
extern u8 D_8009065F[][4];
extern u16 D_80091B10;
extern void Audio_QueueDeferredSound(s32 sound, s32 delay, u8 parameter);
extern void func_80023A3C(s32, s32, s32);

void func_80024480(s32 channel, s32 kind) {
    u8 volume;
    s32 flag;
    u8 sv;
    s32 delay;

    delay = 0;
    flag = 0;
    if (kind != 10) {
        if ((u32)channel >= 254 && (u32)channel < 279) {
            channel = 201;
        }
    }
    if (channel == 279) {
        channel = 300;
    }
    if (channel == 300) {
        flag = 1;
    } else if (channel == 0 || (u32)channel >= 252) {
        if (kind != 10) {
            return;
        }
    }
    switch (kind) {
    case 0:
        if (flag) {
            channel = 257;
        }
        sv = 127;
        break;
    case 7:
        if (flag) {
            channel = 257;
        }
        sv = 48;
        delay = 3;
        break;
    case 8:
        if (flag) {
            channel = 257;
        }
        sv = 80;
        delay = 7;
        break;
    case 2:
        if (flag) {
            channel = 257;
            delay = 20;
        } else {
            delay = D_8009065E[channel][0];
        }
        sv = 96;
        break;
    case 3:
        if (flag) {
            channel = 257;
            delay = 20;
        } else {
            delay = D_8009065E[channel][0];
        }
        sv = 104;
        func_80023A3C(1, 0, 0);
        break;
    case 4:
        if (flag) {
            channel = 256;
            delay = 27;
        } else {
            delay = D_8009065E[channel][0];
        }
        sv = 127;
        if (D_80090BA4 == 0) {
            func_80023A3C(2, 0, 0);
        }
        break;
    case 5:
        if (!flag) {
            return;
        }
        if (D_80091B10 == 46 || D_80091B10 == 18) {
            return;
        }
        channel = 254;
        delay = 3;
        if ((u32)D_80090A80 < 2) {
            return;
        }
        sv = 127;
        break;
    case 6:
        if (!flag) {
            return;
        }
        channel = 255;
        delay = 3;
        if ((u32)D_80090A80 < 2) {
            return;
        }
        sv = 127;
        break;
    case 1:
        if (flag) {
            channel = 252;
            delay = 3;
            sv = 127;
        } else {
            sv = 112;
            delay = D_8009065F[channel][0];
        }
        func_80023A3C(2, 0, 0);
        break;
    case 10:
        sv = 127;
        switch (channel) {
        case 252:
            delay = 12;
            break;
        case 253:
            delay = 10;
            break;
        case 254:
            delay = 17;
            break;
        case 255:
            delay = 17;
            break;
        case 256:
            delay = 19;
            break;
        case 257:
            delay = 23;
            break;
        case 258:
            break;
        case 259:
            delay = 10;
            break;
        case 260:
            delay = 5;
            break;
        case 261:
            delay = 3;
            break;
        case 262:
            delay = 5;
            break;
        case 263:
            delay = 26;
            break;
        case 264:
            break;
        case 265:
            delay = 16;
            break;
        default:
            delay = 10;
            break;
        }
        break;
    default:
        if (flag) {
            channel = 257;
        }
        sv = 112;
        break;
    }
    sv = sv * 0.81f;
    Audio_QueueDeferredSound(--channel, delay, sv);
}

s32 func_80024864(void) {
    extern s32 func_80019230(s32, s32, s32);
    if (func_80019230(4, 0, 0) != 0) {
        return 1;
    }
    return 0;
}

#endif
