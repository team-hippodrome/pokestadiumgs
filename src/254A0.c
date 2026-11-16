#include "229E0.h"

#ifdef VERSION_US

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

#endif
