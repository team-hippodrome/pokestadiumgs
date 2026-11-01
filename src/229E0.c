#include "229E0.h"

#ifdef VERSION_US

f32 func_80021DE0(s32 arg0) {
    u8 value = D_80090137[arg0];
    if (value >= 0x80) {
        value = D_800917F8[value & 0x7F];
        value = (u32)(f32)value;
    }
    return (f32)value / 127.0f;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80021ED8.s")

void func_800225C4(s32 arg0) {
    func_80018728(0x83000000U, arg0 * 3, arg0);
    func_800187AC();
    D_8009019C = 0;
    D_800901A0 = 0;
    D_800901A4 = 0;
}

void func_8002260C(s32 arg0, s32 arg1) {
    func_80018728(0x82000100, 0);
  }

s32 func_8002263C(void) {
    return 0x61;
}

extern f32 D_800A2664;
void func_80022644(u32 arg0) {
    f32 volume;

    if (arg0 != 0 && arg0 < 0x62) {
        volume = func_80021DE0(arg0);
        func_80018728(((u8)(arg0 + 0x27) << 8) | 0x82000000, 0);
        func_80018704(0x41000000, volume * D_800A2664);
    }
}

#pragma C_FUNCTION_PADDING(4)

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_800226C0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_800231A0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80023A3C.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_8002421C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80024480.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80024974.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80025294.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80025DB0.s")

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

// Forward the active GB audio-channel mask; callers test the result for silence.
//@src/340C0.c
s32 func_80026098(void) {
    return GbAudio_GetActiveChannelMask();
}

#pragma C_FUNCTION_PADDING(8)

#pragma asmproc late_rodata_alignment("func_800260C0", 8)

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_800260C0.s")

s32 func_80026298(void) {
    func_80018810();
    if (D_80090B64 != 0) {
        if (func_80018ACC() == 0) {
            return 0;
        }
        D_80090B64 = 0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 1;
    }
    return 1;
}

void Audio_ResetCategoryState(void) {
    D_80090B64 = 0;
    D_80090B6C = -1;
    D_80090B70 = -1;
    func_80018728(0x82010000U, 0);
    func_80018704(0x41010000, 0.63f);
    D_80090B80 = 1;
    switch (D_80090B60) {
    case 2:
    case 3:
    case 5:
    case 7:
    case 9:
    case 10:
        func_80018728(0x82040500U, 0);
        func_80018704(0x41040000, 0.63f);
    case 1:
    case 4:
        if (D_80090B9C == 0) {
            func_80018728(0x82020400U, 0);
            func_80018704(0x41020000, 0.63f);
            D_80090B9C = 1;
        }
        break;
    case 12:
        func_80018728(0x82030800U, 0);
        func_80018704(0x41030000, 0.72f);
        break;
    case 0:
        func_80018728(0x82020600U, 0);
        func_80018704(0x41020000, 0.648f);
        break;
    }
    if (D_80090B60 == 3 || D_80090B60 == 4 || D_80090B60 == 6) {
        func_80018728(0x82030300U, 0);
        func_80018704(0x41030000, 0.765f);
        func_800187AC();
        func_80025E7C();
    }
    if (D_80090B68 != 0) {
        D_80090B68 = 0;
        switch (D_80090B60) {
        case 0:
            func_80018728(0x82020600U, 0);
            break;
        case 12:
            func_80018728(0x82040200U, 0);
            func_80018704(0x41020000, 1.0f);
            break;
        case 8:
            func_80018728(0x82040200U, 0);
            func_80018704(0x41020000, 1.0f);
            func_80018728(0x82020100U, 0);
            func_80018704(0x41020000, 0.63f);
            func_80018728(0x82010A00U, 0);
            func_80018728(0x82010000U, 0);
            func_80018704(0x41010000, 0.63f);
            D_80090B80 = 1;
            func_80024D44();
            func_80018728(0x82032300U, 0);
            D_80090A50 = 35;
            break;
        case 30:
            func_80024D44();
            func_80018728(0x82032300U, 0);
            D_80090A50 = 35;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
        case 11:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
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
            break;
        }
    }
}

/* mkdraft:func_800265B0 begin */
extern s32 D_80090B94;

// Case 18's body is emitted before the -1 and -2 bodies: jump-table entries 16, 17 and 18
// point at 0x80026658, 0x80026660 and 0x80026650, so the case labels appear in that order.


s32 func_800265B0(u32 arg0, s32 arg1) {
    s32 result;

    switch (arg0) {
    case 0: result = 0; break;
    case 1: result = 9; break;
    case 2: result = 18; break;
    case 3: result = 27; break;
    case 4: result = 36; break;
    case 5: result = 45; break;
    case 6: result = 54; break;
    case 7: result = 63; break;
    case 8: result = 72; break;
    case 9: result = 81; break;
    case 10: result = 90; break;
    case 11: result = 113; break;
    case 12: return 118;
    case 13: result = 119; break;
    case 14: return 127;
    case 15: return 128;
    case 18: return 131;
    case 16: result = -1; break;
    case 17: result = -2; break;
    default: return 132;
    }
    switch (arg1) {
    case 10:
        if (D_80090B94 >= 10 && D_80090B94 < 16) {
            result += arg1;
        }
        break;
    case 11:
        if (D_80090B94 >= 10 && D_80090B94 < 16) {
            result += arg1;
            break;
        }
        return -2;
    case 40:
        return -3;
    default:
        // No break: the add falls out of the switch into `return result`, which schedules it
        // into the delay slot of the 40 comparison.
        result += arg1;
    }
    return result;
}
/* mkdraft:func_800265B0 end */

s32 Audio_GetEventConfigIndex(s32 category, u32 request) {
    switch (request) {
    case 10: return 31;
    case 11: return 32;
    case 40: return 33;
    }
    switch (category) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 5: return 5;
    case 6: return 6;
    case 7: return 7;
    case 8: return 8;
    case 9: return 9;
    case 10:
        if (request < 2) return 10;
        if (request >= 2 && request < 5) return 11;
        if (request >= 5 && request < 8) return 12;
        if (request >= 8 && request < 11) return 13;
        if (request >= 11 && request < 13) return 14;
        if (request >= 13 && request < 14) return 15;
        if (request >= 14 && request < 18) return 16;
        if (request >= 18 && request < 21) return 17;
        if (request >= 21 && request < 24) return 18;
        return -1;
    case 11: return 19;
    case 12: return 20;
    case 13:
        switch (request) {
        case 0: return 21;
        case 1: return 22;
        case 2: return 23;
        case 3: return 24;
        case 4: return 25;
        case 5: return 26;
        case 6: return 27;
        case 7: return 28;
        default: return -1;
        }
    case 14: return 29;
    case 15: return 30;
    case 18: return 34;
    case 19: return 35;
    }
    return -1;
}

void func_80026938(u16 arg0) {
    s32 index;
    Color_80026938 *entry;

    if (arg0 >= 0x1E) {
        arg0 = 0xE;
    }
    index = D_80090B3C[arg0];
    entry = &D_80090AD0[index];
    D_80090B6C = entry->second;
    D_80090B70 = entry->first;
}

#pragma C_FUNCTION_PADDING(8)

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80026990.s")

void Audio_DebugSampleHistogram(u8 mode) {
    s32 i;
    for (i = 0; i < 100; i++) D_800D19A0[i] = 0;
    for (i = 0; i < 1000; i++) {
        osSyncPrintf(D_800A39A0, (f64)func_80026990(mode));
    }
    for (i = 0; i < 100; i++) {
        osSyncPrintf(D_800A39A4, i, D_800D19A0[i]);
    }
}

void Audio_ProcessChannelEvent(AudioChannelEvent *event, s32 arg1) {
    PackedRecord *entry;
    if (event->slot == 15) {
        D_800918E8 = func_8002738C(Audio_SetupEventVoice(event, D_800918E8));
        return;
    }
    entry = &D_80090C84[event->slot];
    if (((u8 *)entry)[6] == 1) {
        switch (((u8 *)entry)[0]) {
        case 1:
            func_80026ED8(event->slot);
            break;
        case 3:
            ((u8 *)entry)[0] = 2;
            break;
        case 4:
            return;
        }
        entry = &D_80090C84[event->slot];
    }
    if (event->sound != *(u16 *)((u8 *)entry + 4)) {
        D_800918E8 = Audio_ConfigureEventChannel(event, D_800918E8);
        return;
    }
    switch (((u8 *)entry)[0]) {
    case 2:
        ((u8 *)entry)[0] = 3;
        Audio_UpdateEventVoiceParameters(event, ((u8 *)&D_80090C84[event->slot])[1], 0);
        ((u8 *)&D_80090C84[event->slot])[6] = 1;
        return;
    case 4:
        return;
    }
    *entry = D_80090CFC;
}

s32 Audio_ConfigureEventChannel(AudioChannelEvent *event, u8 request) {
    u8 channel;
    func_80026ED8(event->slot);
    channel = Audio_SetupEventVoice(event, request);
    ((u8 *)&D_80090C84[event->slot])[1] = channel;
    *(u16 *)((u8 *)&D_80090C84[event->slot] + 4) = event->sound;
    ((u8 *)&D_80090C84[event->slot])[3] = event->kind;
    if (event->kind == 0) {
        ((u8 *)&D_80090C84[event->slot])[0] = 1;
    } else {
        ((u8 *)&D_80090C84[event->slot])[0] = 4;
    }
    ((u8 *)&D_80090C84[event->slot])[6] = 1;
    return func_8002738C(channel);
}

void func_80026ED8(u8 arg0) {
    func_8001874C(0x06020000 | (((u8 *) &D_80090C84[arg0])[1] << 8), 0);
    D_80090C84[arg0] = D_80090CFC;
}

u8 Audio_SetupEventVoice(AudioChannelEvent *arg0, u8 request) {
    request = (u8)Audio_SelectEventChannel(arg0, request);
    Audio_UpdateEventVoiceParameters(arg0, request, 1);
    D_80090BC1[request * 12] = ((u8 *)D_80090D28)[arg0->sound * 16 + 12];
    func_8001874C(((0x06020000 | (((u32)request & 0xFF) << 8)) | 1), (s8)((u8 *)D_80090D28)[arg0->sound * 16]);
    func_8001874C((0x06020000 | (((u32)request & 0xFF) << 8)), 1);
    func_8001874C(((0x06020000 | (((u32)request & 0xFF) << 8)) | 3), (s8)((((u8 *)D_80090D28)[arg0->sound * 16] & 0x80) >> 7));
    return request;
}

void Audio_UpdateEventVoiceParameters(void *arg0, u8 channel, u8 reset) {
    if (reset) {
        ((u8 *)(&D_80090BB8[channel]))[0] = ((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 1];
        ((s8 *)(&D_80090BB8[channel]))[1] = ((s8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 8];
    }
    *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) = *(f32 *)((u8 *)D_80090D28 + ((AudioVoiceParameters *)arg0)->sound * 16 + 4) * ((AudioVoiceParameters *)arg0)->pitch;
    if (*(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) > 4.0) {
        *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) = 4.0f;
    } else if (*(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) < D_800A39B0) {
        *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) = D_800A39B8;
    }
    if (((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 13] & 0xF0) {
        *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) *= func_80026990(((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 13] >> 4);
    }
    if (((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 13] & 1) {
        if (*((AudioVoiceParameters *)arg0)->pan >= 64) {
            ((u8 *)(&D_80090BB8[channel]))[2] = 127;
        } else if (*((AudioVoiceParameters *)arg0)->pan < -64) {
            ((u8 *)(&D_80090BB8[channel]))[2] = 0;
        } else {
            ((u8 *)(&D_80090BB8[channel]))[2] = *((AudioVoiceParameters *)arg0)->pan + 64;
        }
    } else {
        ((u8 *)(&D_80090BB8[channel]))[2] = ((AudioVoiceParameters *)arg0)->balance;
    }
}

s32 Audio_SelectEventChannel(void *arg0, u8 request) {
    u8 i;
    u8 scanned;
    u32 next;
    for (i = 0; i < 16; i++) {
        ((u8 *)&D_80090BB8[(u32)i])[8] = func_80018C60(2, i, 2);
    }
    next = Audio_FindEnabledChannel((AudioChannelMask *)arg0, request, 0);
    request = next;
    scanned = 0;
    while (((u8 *)&D_80090BB8[(u32)next])[8] == 1 && scanned < ((AudioChannelGroup *)arg0)->count) {
        next = Audio_FindEnabledChannel((AudioChannelMask *)arg0, request, 1);
        request = next;
        scanned++;
    }
    if (((u8 *)&D_80090BB8[(u32)next])[8] == 1) {
        request = Audio_FindLowestPriorityChannel((AudioChannelGroup *)arg0, request);
    }
    return request;
}

u8 Audio_FindEnabledChannel(AudioChannelMask *state, u8 channel, u8 advance) {
    if (advance) {
        channel = func_8002738C(channel);
    }
    if (!((state->mask >> channel) & 1)) {
        s32 next;
        do {
            next = func_8002738C(channel);
            channel = next;
        } while (!((state->mask >> next) & 1));
    }
    return channel;
}

s32 func_8002738C(u8 channel) {
    if (channel < 0xF) {
        channel++;
    } else {
        channel = 0;
    }
    return channel;
}

u8 Audio_FindLowestPriorityChannel(AudioChannelGroup *state, u8 channel) {
    u8 best = channel;
    u8 i;
    for (i = 1; i < state->count; i++) {
        Candidate27F7CRecord *bestRecord = &D_80090BB8[best];
        s32 next = Audio_FindEnabledChannel(&state->channels, channel, 1);
        channel = next;
        if (((u8 *)&D_80090BB8[next])[9] < ((u8 *)bestRecord)[9]) {
            best = next;
        }
    }
    return best;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80027490.s")

s32 func_800275E8(u8 arg0, Candidate275E8Bits *arg1) {
    arg1->value = D_80090BBC[arg0][0];
    arg1->active = 1;
    if (arg1->active == 1) {
        return arg0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80027634.s")

void func_80027774(u16 arg0, u8 arg1) {
    ResourceContext_80027774 context;

    context.resource = D_80090D04;
    context.kind = arg1;
    context.scale = 1.0f;
    Audio_BuildAndDispatchSoundEvent(arg0, 0, &context);
}

void func_800277C4(u16 resource_id, u8 mode) {
    func_8002781C(resource_id, mode);
}

void func_800277F0(u16 resource_id, void *context) {
    func_8002781C(resource_id, 0, context);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_8002781C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_800278C0.s")

void Audio_PlayDefaultSound(u16 id) {
    ResourceContext_80027774 context;
    context.resource = D_80090D04;
    context.kind = 0;
    context.scale = 1.0f;
    if (id == 0x5F0A) {
        func_800225C4(5);
    }
    Audio_BuildAndDispatchSoundEvent(id, 0, &context);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80027A28.s")

void Audio_BuildAndDispatchSoundEvent(u16 encoded, s32 offset, ResourceContext_80027774 *event) {
    u8 i;
    u8 j;
    u8 total = 0;

    event->slot = (encoded & 0xF00) >> 8;
    event->bank = (encoded & 0xF000) >> 12;
    event->sound = encoded & 0xFF;
    for (i = 0; i < event->bank; i++) event->sound += D_800A3990[i];
    event->unknown14[0] = D_80090D31[event->sound * 16];
    for (i = 0; i < 13; i++) total += D_800A3990[i];
    if (event->sound >= total) event->sound = total - 1;
    event->count = 0;
    for (i = 0; i < 16; i++) {
        if ((*(u16 *)(D_80090D28[event->sound] + 10) >> i) & 1) {
            event->count++;
        }
    }
    event->mask = *(u16 *)(D_80090D28[event->sound] + 10);
    if (event->bank != 6 && ((D_80090D28[event->sound][13] >> 1) & 1)) {
        if ((u8)offset * event->count >= 49) return;
        for (i = 0; i < (u8)offset * event->count; i++) {
            event->mask <<= 1;
            total = 0;
            for (j = 0; j < 16; j++) {
                if ((event->mask >> j) & 1) total++;
            }
            if (total == event->count - 1) {
                if (event->mask & 1) return;
                event->mask |= 1;
            } else if (total < event->count - 1) {
                return;
            }
        }
        if (event->slot != 15) {
            event->slot += offset;
            if (event->slot >= 15) event->slot -= 15;
        }
    }
    if (event->count) Audio_ProcessChannelEvent(event, offset);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80027E30.s")

void func_80027EE0(u16 arg0) {
    switch (arg0) {
        case 0xFFF:
            func_80027E30();
            return;
        case 0xFFE:
            func_80027F4C();
            return;
        case 0xFFD:
            func_80027F4C();
            func_80027E30();
            return;
        default:
            return;
    }
}

void func_80027F4C(void) {
    func_80018728(0x83020000U, 0x14);
    func_80027F7C();
    D_80090BB0 = 0;
}

void func_80027F7C(void) { u8 i; u8 j; for (i = 0; i < 15; i++) { D_80090C84[i] = D_80090CFC; } for (j = 0; j < 16; j++) { D_80090BB8[j] = D_80090C78; } }

void func_80028014(void) {
    func_80027EE0(0xFFD);
    Audio_PlayDefaultSound(0xCF07);
    if (D_8011F300 == 0x5C) {
        func_80018728(0x83000000U, 0x1E);
        return;
    }
    func_80018728(0xF1000000U, 0);
}

s32 func_8002806C(void) {
    u8 *base;
    s32 result;

    base = &D_8011BE90;
    result = *(u8 *)(base + 0x3470) - 0x27;
    if (((u32)*(s32 *)(base + 0x346C) >> 31) == 0) {
        return 0;
    }
    return result;
}

void func_8002809C(void) {
    func_80018728(0xF2000000, 0);
}

void func_800280C0(void) {
    func_80027EE0(0xFFE);
    func_80018728(0x4B000000U, 1);
}

void func_800280EC(void) {
    func_80027EE0(0xFFF);
    func_80018728(0x4C000000U, 1);
}

void func_80028118(u8 arg0) {
    D_80090BB4 = arg0 + 1;
}

#pragma C_FUNCTION_PADDING(20)

void func_80028140(void) {
    (*(s32 *)((u8 *)(&D_800D1A70) + (0))) = -1;
    (*(s32 *)((u8 *)(&D_800D1A70) + (4))) = -1;
    (*(s32 *)((u8 *)(&D_800D1A78) + (0))) = -1;
    (*(s32 *)((u8 *)(&D_800D1A78) + (4))) = -1;
    (*(s8 *)((u8 *)(&D_800D1A80) + (0))) = 0x7F;
    (*(s8 *)((u8 *)(&D_800D1A80) + (1))) = 0x7F;
    (*(s8 *)((u8 *)(&D_800D1A82) + (0))) = 0;
    (*(s8 *)((u8 *)(&D_800D1A82) + (1))) = 0;
}

void Audio_QueueDeferredSound(s32 sound, s32 delay, u8 parameter) {
    u16 channel;
    u8 mode = 0;

    channel = (sound >= 266) ? 1 : 0;
    if (channel == 1) {
        mode = ((sound & 0xF000) == 0x3000) ? 2 : 1;
        sound &= 0xFFF;
    }
    func_8001874C((0x06040000 | ((u8)channel << 8)) | 3, 1);
    //!bug Zero delay becomes two before the immediate-play branch tests for zero.
    if (delay == 0) {
        delay = 2;
    }
    if (delay == 0) {
        func_8001874C((0x06040000 | ((u8)channel << 8)), sound % 64);
        func_8001874C((0x06040000 | ((u8)channel << 8)) | 1, sound / 64);
        func_8001874C((0x06040000 | ((u8)channel << 8)) | 2, parameter);
        if (channel == 1) {
            func_8001874C((0x06040000 | ((u8)channel << 8)) | 4, mode);
        }
    } else {
        D_800D1A70[channel] = sound;
        D_800D1A78[channel] = delay;
        D_800D1A80[channel] = parameter;
        D_800D1A82[channel] = mode;
    }
}

void func_80028300(void) {
    func_8001874C(0x06040003, 1);
    func_8001874C(0x06040103, 1);
    func_80028140();
}

void Audio_UpdateDeferredSounds(void) {
    u32 channel;
    s32 command;

    for (channel = 0; channel < 2; channel++) {
        if (D_800D1A70[channel] != -1) {
            if (D_800D1A78[channel] == 1) {
                func_8001874C((0x06040000 | ((u8)channel << 8)) | 3, 1);
            }
            if (D_800D1A78[channel] == 0) {
                command = 0x06040000 | ((u8)channel << 8);
                func_8001874C(command, D_800D1A70[channel] % 64);
                func_8001874C(command | 1, D_800D1A70[channel] / 64);
                func_8001874C(command | 2, D_800D1A80[channel]);
                if (channel == 1) {
                    func_8001874C(command | 4, D_800D1A82[channel]);
                }
                D_800D1A70[channel] = -1;
                D_800D1A78[channel] = -1;
                D_800D1A80[channel] = 127;
                D_800D1A82[channel] = 0;
            } else {
                D_800D1A78[channel]--;
            }
        }
    }
}

#pragma C_FUNCTION_PADDING(8)

u8 Audio_LookupScaledRatio(u16 numerator, u16 denominator) {
    s32 scaled = (numerator * 48) / denominator;
    s32 index = 0;
    for (; index < 6; index++) {
        if (D_8009210C[index * 2] >= scaled) {
            break;
        }
    }
    return D_8009210C[index * 2 + 1];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80028540.s")

void Audio_SwapSoundCandidates(u8 *arg0, u8 *arg1) { if (*arg0 != *arg1) { u8 temp = *arg0; *arg0 = *arg1; *arg1 = temp; } }

u16 Audio_FilterRecentSoundId(u16 arg0) {
    s32 i;
    for (i = 0; i < 24; i++) {
        if (arg0 == D_800D1AD8[i]) return 0;
    }
    return arg0;
}

/* mkdraft:func_800289B0 begin */
extern u32 D_800D1AD8[24];
extern u32 D_800D1ADC;
extern u32 D_800D1AE0;
extern u32 D_800D1AE4;
extern u32 D_800D1B34;

// NON_MATCHING: Extern-array stores still materialize one more page base than retail.
#ifdef NON_MATCHING
void func_800289B0(u16 arg0) {
    s32 i;

    for (i = 0; i < 23; i++) {
        D_800D1AD8[i] = D_800D1AD8[i + 1];
    }
    D_800D1B34 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_800289B0.s")
#endif
/* mkdraft:func_800289B0 end */

void Audio_RemoveRecentSoundAt(u16 arg0) {
    u32 i;
    for (i = arg0; i > 0; i--) D_800D1AD8[i] = D_800D1AD8[i - 1];
    D_800D1AD8[0] = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80028ADC.s")

void func_80028CA8(const void *sound_candidates) {
    s32 v0;
    s32 masked;

    v0 = func_80028ADC(sound_candidates);
    masked = v0 & 0xFFFF;
    if (v0 != 0) {
        func_800314D4(masked);
    }
}

void func_80028CA8_padding(void) {}

void func_80028CA8_padding2(void) {}

s32 func_80028CE8(void *arg0, s32 arg1) {
    struct Node { u32 a; u32 b; struct Node *next; };
    struct Root { u32 a; struct Node *next; };
    struct Node *node = ((struct Root *)arg0)->next;
    s32 i = 0;
    while (i != arg1) {
        if (node->next == 0) return (s32)node;
        node = node->next;
        i++;
    }
    return (s32)node;
}

/* mkdraft:func_80028D9C begin */
extern u32 func_800194A0(void);
extern s32 func_80028CE8(void *arg0, s32 arg1);
extern void func_80028CA8(const void *sound_candidates);



void func_80028D9C(void *arg0) {
    struct Node { u32 a; u32 b; struct Node *next; };
    struct Root { u32 a; struct Node *next; };
    u32 pad0;                        // FAKE: unused; holds frame word 0x2c above count; diff score 24 without it.
    u32 count;
    u32 pad1[3];                     // FAKE: unused; holds frame words 0x24-0x1c below count; diff score 66 without it.
    struct Node *found;              // FAKE: second name for the matched node; keeps it in a stack home across the
                                     // two calls so uopt emits one reload after func_80028CA8; diff score 100 without it.
    struct Node *node;

    node = ((struct Root *)arg0)->next;
    count = 1;
    if (node->a == 0) {
loop:
        if (node->next != 0) {
            node = node->next;
            count++;
            if (node->a == 0) {
                goto loop;
            }
        }
    }
    found = node;
    func_80028CA8((const void *)((struct Node *)func_80028CE8(arg0, func_800194A0() % count))->b);
    node = found;
    ((struct Root *)arg0)->a++;
    if (node->next != 0 && ((struct Root *)arg0)->a >= node->a) {
        ((struct Root *)arg0)->next = node->next;
    }
}
/* mkdraft:func_80028D9C end */

s32 func_80028E60(u32 arg0)
{
  u8 *ptr;
  int value;
  u32 mask;
  s32 result;
  arg0--;
  ptr = &D_800D2660[arg0 >> 3];
  value = *ptr;
  mask = 1U << (arg0 & 7);
  result = value & mask;
  value |= mask;
  if ((mask = result) != 0U)
  {
    return 1;
  }
  *ptr = value;
  return mask != (mask = 0);
}

void func_80028EA8(void) { extern u8 D_80091B90[]; func_80028D9C(D_80091B90); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_80028ECC.s")

void Audio_ResetQueueAndBitmap(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        D_800D1A90[i] = 0;
    }
    D_80091A24 = 0;
    D_80091A28 = 0;
    for (i = 0; i < 32; i++) {
        D_800D2660[i] = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_8002A25C.s")

void func_8002A7A8(s32 arg0, s32 arg1) { D_800D2650[0] = arg0; D_800D2650[1] = arg1; D_800D2650[3] = D_80090BA0; if (D_80090BA0 == 1) D_800D2650[2] = 1; else D_800D2650[2] = 0; D_800D2650[4] = 0; *(u32 *)(D_800D2650 + 8) = 0; }

void func_8002A7E8(s32 arg0) {
    if (arg0 != 0) {
        D_80091A0C = 1;
        return;
    }
    D_80091A0C = 0;
}

void func_8002A80C(s32 arg0) {
    if (arg0 != 0) {
        D_80091A10 = 1;
        return;
    }
    D_80091A10 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_8002A830.s")

void func_8002A9C0(s32 arg0) {
    D_800D2630 = arg0;
}

void func_8002A9CC(s32 arg0) {
    D_800D2634 = arg0;
}

void func_8002A9D8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        osSyncPrintf(D_800A3A60, i);
        osSyncPrintf(D_800A3A6C, D_800D1B78[i][1]);
        osSyncPrintf(D_800A3A84, D_800D1B80[i][0]);
        osSyncPrintf(D_800A3A94, D_800D1B80[i][3]);
        osSyncPrintf(D_800A3AA4, D_800D1B80[i][4]);
    }
}

void func_8002AAD0(u8 arg0) {
    if (arg0) {
        D_80091A18 = 1;
        return;
    }
    D_80091A18 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_8002AAFC.s")

void func_8002B1A0(void) { func_8002A25C(); func_80024180(0, 0); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_8002B1CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/229E0/func_8002B2FC.s")

void func_8002B43C(void) {
    D_80091A18 = 0;
    func_8002AAFC(0);
    func_80023A3C(3, 0, 0);
    func_800314D4(0x2226);
}

void func_8002B47C(s32 arg0, s32 arg1) {
    D_80091B08 = arg0;
    D_80091B0C = arg1;
}

void Audio_RequestSlot(u8 slot) {
    if (D_80091AC8 != 0) {
        if (D_800D1B3B == 0)
        {
            func_800314D4(0x2028);
        }
        if (D_800D2640[slot] < 2U) {
            D_800D269E[slot] = 1;
        }
    } else {
        if (D_800D2640[slot] < 2U) {
            if (*(D_800D269E + slot) != 0) {
                if (D_800D1B3B == 0) {
                    func_80028CA8(D_80091F00);
                }
            } else if (D_800D1B3B == 0) {
                func_80028CA8(D_80091EF8);
            }
            *(D_800D269E + slot) = 1;
        } else if (D_800D1B3B == 0) {
            func_80028CA8(D_80091EEC);
        }
    }
    D_80091AC8 = 1;
}

#endif
