#include "229E0.h"

#ifdef VERSION_US

extern s32 D_80090B94;
extern s32 D_80090B98;
extern s32 func_800265B0(u32 arg0, s32 arg1);

extern s8 D_800901BC[];
extern void func_80025294();
// Passes 0x66 or 0x65 to func_80025294 for arg0 0 or 1. For arg0 340 it reads
// entry arg1 (0-61) of the signed table D_800901BC and, when the entry is not
// negative, passes entry + 0x1000D.
void func_80023110(s32 arg0, s32 arg1) {
    s32 sound;

    switch (arg0) {
        case 0:
            func_80025294(0x66);
            return;
        case 1:
            func_80025294(0x65);
            return;
        case 340:
            if ((arg1 >= 0) && (arg1 < 62)) {
                sound = D_800901BC[arg1];
                if (sound >= 0) {
                    func_80025294(sound + 0x1000D, 0, 0);
                }
            }
            return;
    }
}

#pragma C_FUNCTION_PADDING(4)

#pragma GLOBAL_ASM("asm/us/nonmatchings/23D10/func_800231A0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/23D10/func_80023A3C.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/23D10/func_8002421C.s")

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

#pragma C_FUNCTION_PADDING(8)

void func_800248A0(void) {
    func_80035068((u32)D_154F190 + 4, (u8 *)&D_800D1900, 8);
    D_800D1900 += (u32)D_154F190;
}

void func_800248EC(void *arg0) {
    u8 count = *(u8 *)arg0;
    u32 *ptr = (u32 *)((u8 *)arg0 + 4);
    u32 i = 0;
    while (i < count) {
        *ptr += (u32)arg0;
        i++;
        ptr++;
    }
    *((u8 *)arg0 + 1) = 1;
}

#pragma GLOBAL_ASM("hand_asm/23D10/func_80024974_manual.s")

void func_80024D10(s32 arg0) {
    D_80090A54 = 0;
    func_80018728(0x83030000U, arg0 * 3, arg0);
}

void func_80024D44(void) {
    D_80090A50 = 0;
    (*(s8 *)((u8 *)(&D_80090A74) + (0))) = 0;
    (*(s8 *)((u8 *)(&D_80090A74) + (1))) = 0;
    D_80090A78 = -1;
}

s32 Audio_GetOrCacheResourceId(u32 id) {
    s32 found;
    s32 slot;
    u8 replacement;
    AudioResourceCacheView *cache;
    if ((id == 0 || id >= 0xFC) && id != 0x12C) { return -1; }
    found = func_80024E30(id);
    if (found == 0 || found == 1) { return found; }
    cache = (AudioResourceCacheView *)D_80090A74;
    for (slot = 0; slot < 2; slot++) {
        if (cache->ids[slot] == 0) {
            cache->ids[slot] = id;
            return slot;
        }
    }
    replacement = cache->lastSlot ^ 1;
    cache->ids[replacement] = id;
    cache->lastSlot = replacement;
    return replacement;
}

void func_80024D6C_padding(void) {}

s32 func_80024E30(u32 arg0) {
    s32 var_v1;
    u8 *var_v0;

    if (((arg0 == 0) || (arg0 >= 0xFCU)) && (arg0 != 0x12C)) {
        return -1;
    }
    var_v0 = D_80090A74;
    var_v1 = 0;
loop_5:
    if (arg0 == *var_v0) {
        return var_v1;
    }
    var_v1 += 1;
    var_v0 += 1;
    if (var_v1 == 2) {
        return -2;
    }
    goto loop_5;
}

void func_80024E8C(s32 arg0) {
    D_80090A80 = arg0;
    switch (arg0) {
    case 0:
    case 1:
    case 11:
    case 12:
    default:
        return;
    case 2:
        arg0 = 0x100;
        break;
    case 3:
        arg0 = 0x107;
        break;
    case 4:
        arg0 = 0x106;
        break;
    case 5:
        arg0 = 0x102;
        break;
    case 6:
        arg0 = 0x103;
        break;
    case 7:
        arg0 = 0x108;
        break;
    case 8:
        arg0 = 0x105;
        break;
    case 9:
        arg0 = 0x109;
        break;
    case 10:
        arg0 = 0x104;
        break;
    }
    func_80024480(arg0, 0xA);
}

#pragma C_FUNCTION_PADDING(8)

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/23D10/func_80025294.s")

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

#pragma C_FUNCTION_PADDING(12)

void func_80025C50(u32 arg0) {
    if (arg0 < 5U) {
        if (arg0 == 4) {
            D_80090B90 = 1;
        } else {
            D_80090B90 = 0;
        }
        func_80018728(0xF0000000U, arg0);
    }
}

s32 func_80025C9C(void) {
    return func_80018C14();
}

void func_80025CBC(s32 arg0) {
    s32 temp_s0;

    func_8002B1A0();
    Audio_DisableCommandQueue();
    func_80028140();
    temp_s0 = arg0 * 3;
    func_80018728(0x83000000U, temp_s0);
    func_80018728(0x83010000U, temp_s0);
    func_80018728(0x83020000U, temp_s0);
    func_80018728(0x83030000U, temp_s0);
    func_80018728(0x83040000U, temp_s0);
    D_80090B9C = 0;
}

s32 func_80025D44(void) {
    return func_80019378();
}

void func_80025D64(u8 arg0) {
    if (arg0 != 0) {
        func_80018728(0xF1FF0000U, 0);
    } else {
        func_80018728(0xF2FF0000U, 0);
    }
}

#pragma C_FUNCTION_PADDING(8)

/* mkdraft:func_80025DB0 begin */
#include "global.h"
extern u8 D_800D1930[];
extern u8 D_800D1940[];
extern u8 D_800D1980[];
extern u8 D_800D1910;

// Bitfield view of the packed state word at D_800D1930. Big-endian bit order
// puts top at bit 31, mode at bits 28..30, clr at 26..27, en0 at 25, en1 at 24
// and low at bits 0..23.
typedef struct {
    u32 top : 1;
    u32 mode : 3;
    u32 clr : 2;
    u32 en0 : 1;
    u32 en1 : 1;
    u32 low : 24;
} unk_D_800D1930;



void func_80025DB0(void)
{
    /* The four bitfield stores fold into one read-modify-write chain over
       byte 0: mode=4 clears bits 28..30 and sets bit 30, clr=0 clears bits
       26..27, en0=1 sets bit 25, en1=1 sets bit 24.  low=0x200 is lowered
       to a whole-word store that keeps bits 24..31 and forces bit 9. */
    *(s16 *)(&D_800D1980[0]) = 1;
    *(s16 *)(&D_800D1980[2]) = 32000;
    *(s16 *)(&D_800D1980[6]) = 0;
    *(s16 *)(&D_800D1980[4]) = -1;
    *(u8 *)((u8 *)(&D_800D1910) + 0) = 1;
    *(u8 *)((u8 *)(&D_800D1910) + 1) = 0;
    *(u8 *)((u8 *)(&D_800D1910) + 2) = 127;
    *(u8 *)((u8 *)(&D_800D1910) + 3) = 240;
    *(void **)((u8 *)(&D_800D1910) + 4) = (&D_800D1980);
    *(void **)((u8 *)(&D_800D1910) + 0x10) = (&D_800D1930);
    *(u32 *)(&D_800D1940[4]) = 0x10000;
    ((unk_D_800D1930 *)D_800D1930)->mode = 4;
    ((unk_D_800D1930 *)D_800D1930)->clr = 0;
    ((unk_D_800D1930 *)D_800D1930)->en0 = 1;
    *(f32 *)((u8 *)(&D_800D1910) + 0x14) = 0.5f;
    ((unk_D_800D1930 *)D_800D1930)->en1 = 1;
    *(u32 *)(&D_800D1940[0]) = 0;
    *(u32 *)(&D_800D1940[8]) = 1;
    ((unk_D_800D1930 *)D_800D1930)->low = 0x200;
    *(u32 *)(&D_800D1930[4]) = 0;
    *(void **)(&D_800D1930[8]) = (&D_800D1940);
    *(u32 *)(&D_800D1930[0xC]) = 0;
}
/* mkdraft:func_80025DB0 end */

void func_80025E7C(void) {
    func_80025DB0();
    func_80018728(0xE2000700U, &D_800D1910);
}

s32 Audio_RenderNextBuffer(s32 arg0, s32 samples, s32 initialize, s32 arg3) {
    s32 result;
    s16 *buffer;
    if ((s8)D_80090B8C == 0) { return 0; }
    buffer = D_800D1990[D_80090AC0];
    if (initialize == 1) {
        func_80031A6C(32000, D_800D198C);
    }
    result = func_80031C84(buffer, samples);
    D_80090AC0++;
    D_80090AC0 %= 3;
    if ((s8)D_80090B8C == 0) { return 0; }
    if (result == -1) { return result; }
    return (s32)buffer;
}

void Audio_InitializeBufferMemory(void *buffer) {
    u32 aligned = ((u32)buffer + 0xF) & ~0xF;
    u32 mask;
    D_800D198C = (void *)aligned;
    D_800D1990[0] = (s16 *)((u8 *)D_800D198C + 0x2380);
    D_800D1990[1] = (s16 *)((u8 *)D_800D1990[0] + 0x2000);
    D_800D1990[2] = (s16 *)((u8 *)D_800D1990[1] + 0x2000);
    func_80031A6C(32000, D_800D198C);
    func_80018728(0x82030300, 0);
    func_800187AC();
    func_80025E7C();
    func_8001874C(0x06030000, 0);
    func_80034DD0();
    mask = osSetIntMask(1);
    D_80090B8C = 1;
    osSetIntMask(mask);
}

 void func_8002602C(void) { s32 mask; func_80018728(0x83030000, 0); mask = osSetIntMask(1); D_80090B8C = 0; osSetIntMask(mask); }

void func_80026068(u32 arg0) {
    s32 temp_a1;

    if (arg0 != 0) {
        temp_a1 = arg0 - 1;
        if (arg0 < 0xFCU) {
            func_80034E5C(temp_a1 & 0xFFFF, temp_a1);
        }
    }
}

 void func_80026098(void) { GbAudio_GetActiveChannelMask(); }

#pragma C_FUNCTION_PADDING(8)

#endif
