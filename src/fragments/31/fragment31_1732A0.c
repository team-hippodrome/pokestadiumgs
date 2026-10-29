#include "global.h"


#ifdef VERSION_US
extern u8 *D_88234564;
void func_88200020(u8 count) {
    u32 i;
    u8 *entry;

    // Allocates count 0x44-byte entries and clears each entry's active flag at +0x1C
    // (func_882000AC sets it to 1). The unsigned size matches a sizeof() product.
    D_88234564 = Util_Malloc(count * 0x44U);
    for (i = 0, entry = D_88234564; i != count; i++, entry += 0x44) {
        *(s32 *)(entry + 0x1C) = 0;
    }
}

extern u8 *D_88234564;
void func_882000AC(u8 arg0, s16 arg1, s16 arg2, u16 arg3, u16 arg4, s32 arg5, s32 arg6, u8 arg7) {
    u8 *entry = D_88234564 + arg0 * 0x44;
    *(s16 *)(entry + 0) = 0;
    *(s16 *)(entry + 2) = 0;
    *(u16 *)(entry + 4) = 0;
    *(u16 *)(entry + 6) = 0;
    *(s16 *)(entry + 8) = arg1;
    *(s16 *)(entry + 0xA) = arg2;
    *(u16 *)(entry + 0xC) = arg3;
    *(u16 *)(entry + 0xE) = arg4;
    *(s32 *)(entry + 0x3C) = arg5;
    *(s32 *)(entry + 0x40) = arg6;
    *(s32 *)(entry + 0x1C) = 1;
    *(s8 *)(entry + 0x20) = -arg7;
}

extern u8 *D_88234564;
void func_88200134(u8 arg0, u8 arg1) {
    u8 *entry = D_88234564 + arg0 * 0x44;
    if (*(s32 *)(entry + 0x1C) != 0) {
        entry[0x20] = *(s8 *)(entry + 0x20) + arg1 + 1;
    }
}

extern void func_88003FBC(void *);
extern void func_88002CB8(s16, s16, u16, u16);

void func_88200180(u8 arg0) {
    u8 *entry = D_88234564 + arg0 * 0x44;

    if (*(s32 *)(entry + 0x1C) != 0) {
        func_88003FBC(entry);
        func_88002CB8(*(s16 *)entry, *(s16 *)(entry + 2),
                      *(u16 *)(entry + 4), *(u16 *)(entry + 6));
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1732A0/func_882001E8.s")

u8 func_882002F8(u8 *arg0, u8 *arg1) {
    u8 value = *arg0;

    *arg0 = *arg1;
    *arg1 = value;
    return value;
}

u32 func_8820030C(u32 *arg0, u32 *arg1) {
    u32 value = *arg0;

    *arg0 = *arg1;
    *arg1 = value;
    return value;
}

typedef struct unk_func_88200320_record {
    u16 halfwords[59];
} unk_func_88200320_record;

void func_88200320(void *arg0, void *arg1) {
    unk_func_88200320_record saved;

    saved = *(unk_func_88200320_record *)arg0;
    *(unk_func_88200320_record *)arg0 = *(unk_func_88200320_record *)arg1;
    *(unk_func_88200320_record *)arg1 = saved;
}

u32 func_88200458(u32 *arg0, u32 *arg1) {
    u32 value = *arg0;

    *arg0 = *arg1;
    *arg1 = value;
    return value;
}
#endif
