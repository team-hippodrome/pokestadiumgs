#include "global.h"


void func_8414F260(void) {
}

#ifdef VERSION_US
extern u8 func_84154B24(void);
void func_8414F268(void *arg0) {
    s32 value;
    s32 amount;

    value = ((u16 *)((u8 *)arg0 + 2))[(u8)(1 - func_84154B24())];
    amount = *(s32 *)((u8 *)arg0 + 0x14);
    if (value != 0) {
        if (amount < 0) {
            amount = -amount;
        }
        if (value < 0x80) {
        // karodo: empty check on the magnitude; the original keeps its branch.
        if (!amount) {
        }
            *(s32 *)((u8 *)arg0 + 0x18) = (value + 10) * -amount / 255;
        } else {
            *(s32 *)((u8 *)arg0 + 0x18) = -amount;
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3BEAF0/func_8414F2F4.s")
#endif

#ifdef VERSION_US
extern u8 func_84154B24(void);
void func_8414F3FC(void *arg0) {
    u8 value = func_84154B24();
    if (*(u16 *)((u8 *)arg0 + value * 2 + 2) < 0xB2) {
        *(u8 *)arg0 |= 0x10;
    }
}
#endif

#ifdef VERSION_US
extern u8 *func_84154B64(u8);
extern s32 func_841556C4(u8 *, u8);
void func_8414F444(u8 *arg0, u8 arg1) {
    u8 value = func_84154B24();
    if (func_841556C4(func_84154B64(1 - value), arg1) != 0) {
        *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) - *(s32 *)(arg0 + 0x14);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3BEAF0/func_8414F4A0.s")
#endif

#ifdef VERSION_US
extern void func_8414F268(void *);
extern void func_8414F2F4(void *);
void func_8414F5F0(void *arg0) {
    func_8414F268(arg0);
    func_8414F2F4(arg0);
}
#endif

#ifdef VERSION_US
extern void func_8414F5F0(void *);
extern void func_8414F3FC(void *);
void func_8414F618(void *arg0) {
    u8 value;
    u8 *ptr;
    func_8414F5F0(arg0);
    value = func_84154B24();
    ptr = func_84154B64(1 - value);
    if (*(u16 *)(ptr + 0x26) & 0x20) {
        func_8414F3FC(arg0);
    }
}
#endif

#ifdef VERSION_US
extern u8 *func_8414A3A0(u8);
extern void func_8414F444(u8 *, u8);
void func_8414F668(u8 *arg0) {
    u8 value = func_84154B24();
    u8 *ptr = func_8414A3A0(value);
    if ((*(s32 *)ptr << 15) >= 0) {
        func_8414F444(arg0, 0x11);
        func_8414F444(arg0, 0x5E);
        func_8414F444(arg0, 0x19);
        func_8414F444(arg0, 0x71);
    }
}
#endif

#ifdef VERSION_US
void func_8414F6D0(void *arg0) {
    u8 value;
    u8 *ptr;
    func_8414F2F4(arg0);
    value = func_84154B24();
    ptr = func_8414A3A0(value);
    if ((*(s32 *)ptr << 15) >= 0) {
        func_8414F444(arg0, 0x11);
        func_8414F444(arg0, 0x5E);
        func_8414F444(arg0, 0x19);
        func_8414F444(arg0, 0x71);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3BEAF0/func_8414F748.s")
#endif

#ifdef VERSION_US
extern void func_8414F4A0(s32, s32);
void func_8414F894(s32 arg0) {
    func_8414F4A0(arg0, 83);
}
#endif

#ifdef VERSION_US
void func_8414F8B4(s32 arg0) {
    u8 temp_v0;
    u8 temp_t7;

    temp_v0 = func_84154B24();
    temp_t7 = 1 - temp_v0;
    func_8414F2F4((void *)arg0);
    if (*(u16 *)((u8 *)arg0 + temp_t7 * 2 + 2) == 0) {
        *(s32 *)((u8 *)arg0 + 0x18) = -*(s32 *)((u8 *)arg0 + 0x14);
    } else {
        *(s32 *)((u8 *)arg0 + 0x18) += *(s32 *)((u8 *)arg0 + 0x14) * *(u16 *)((u8 *)arg0 + temp_t7 * 2 + 2) / 128;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3BEAF0/func_8414F93C.s")
#endif

#ifdef VERSION_US
extern u8 *func_84154B30(u8);
void func_8414FA3C(void *arg0) {
    u8 side = func_84154B24();
    u8 other = 1 - side;
    u8 ok = 1;
    u8 *self;
    u8 *mon;

    self = func_84154B64(side);
    mon = func_84154B64(other);
    if (mon[0xD] >= 10) {
        ok = 0;
    }
    if (mon[0x10] >= 10) {
        ok = 0;
    }
    if (func_84154B30(side)[2] >= 2) {
        if (mon[0x13] >= 10) {
            ok = 0;
        }
        if (mon[0xE] >= 10) {
            ok = 0;
        }
        if (mon[0x11] >= 10) {
            ok = 0;
        }
    }
    if (ok) {
        func_8414F268(arg0);
    }
}
#endif

#ifdef VERSION_US
extern u8 func_80062D20(u8);
void func_8414F748(void *);
void func_8414F93C(void *);
typedef struct unk_func_8414FB24 {
    /* 0x00 */ u8 unk_00[0x2E];
    /* 0x2E */ u8 unk_2E[2];
} unk_func_8414FB24;

void func_8414FB24(u8 *arg0) {
    switch (func_80062D20(((unk_func_8414FB24 *)arg0)->unk_2E[func_84154B24()])) {
        case 5:
        case 6:
        case 31:
        case 49:
        case 67:
        case 76:
        case 111:
        case 113:
            func_8414F2F4(arg0);
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 26:
        case 30:
        case 46:
        case 47:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 81:
        case 82:
        case 84:
        case 109:
        case 129:
        case 138:
        case 139:
        case 140:
        case 142:
        case 145:
            func_8414F268(arg0);
            break;
        case 2:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 24:
        case 33:
        case 36:
        case 42:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 64:
        case 66:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 74:
        case 77:
        case 90:
        case 94:
        case 100:
        case 101:
        case 106:
        case 115:
        case 136:
        case 137:
        case 156:
            func_8414F5F0(arg0);
            break;
        case 4:
            func_8414F618(arg0);
            break;
        case 16:
        case 56:
            func_8414F668(arg0);
            break;
        case 23:
        case 63:
        case 73:
            func_8414F6D0(arg0);
            break;
        case 97:
            func_8414F748(arg0);
            break;
        case 25:
            func_8414FA3C(arg0);
            break;
        case 114:
            func_8414F894((s32)arg0);
            break;
        case 116:
            func_8414F8B4((s32)arg0);
            break;
        case 120:
            func_8414F93C(arg0);
            break;
    }
}
#endif
