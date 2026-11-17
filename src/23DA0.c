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

extern f32 D_8009064C;
extern struct {
    u8 pad[0x9C4];
    u8 unk_9C4;
} *D_800D1B70;
extern f32 __cosf(f32);
extern f32 __sinf(f32);

void func_8002421C(s32 arg0, f32 arg1, s32 arg2) {
    s32 left;
    s32 right;
    f32 angle;
    f32 ratio;
    s32 pad; // FAKE

    if (arg2 < 0) {
        D_8009061C[arg0][0] = 0;
        D_8009061C[arg0][1] = 63;
        D_8009061C[arg0][2] = 0;
        D_8009061C[arg0][3] = 0;
        return;
    }
    arg1 -= 16384.0f;
    angle = (D_8009064C / 32768.0f) * arg1;
    left = __cosf(angle) * 64.0f + 64.0f;
    if (left >= 128) {
        left = 127;
    }
    right = 64.0f - __sinf(angle) * 64.0f;
    if (right >= 128) {
        right = 127;
    }
    if (arg2 > 30000) {
        arg2 = 30000;
    }
    D_8009061C[arg0][0] = 1;
    D_8009061C[arg0][1] = left;
    D_8009061C[arg0][2] = right;
    ratio = (f32)(30000 - arg2) / 30000.0f;
    D_8009061C[arg0][3] = (u32)(ratio * 32768.0f);
    if (arg0 == 2 && D_80090BA0 == 9 && D_800D1B70 != NULL) {
        // 1U keeps IDO from reusing the s32 1 stored above for this u8 compare.
        if (D_800D1B70->unk_9C4 != 1U && D_800D1B70->unk_9C4 != 3) {
            func_8001874C(0x03020000, left);
            func_8001874C(0x12020000, right);
            func_80018704(0x01020000, ratio);
        }
    }
}

#endif
