#include "global.h"


#ifdef VERSION_US
extern s32 D_84191208;
extern s32 D_8419120C;
s32 func_8411F750(s32 arg0) {
    if (arg0 == 0) {
        return D_84191208;
    }
    return D_8419120C;
}

s32 func_8411F770(s32 arg0) { if (arg0 == D_84191208) return 0; return 1; }

extern u8 *D_84193DD0; extern void func_8411FEE8(u16);
s32 func_8411F794(s32 arg0) { if (((*(u16 *)((u8 *)(u32)D_84193DD0 + (arg0 << 4) + 0x12)) & 0x2) != 0) { func_8411FEE8(0); return 1; } return 0; }

extern u8 *D_84193DD0; extern void func_8411FEE8(u16);
s32 func_8411F7E0(s32 arg0) { if (((*(u16 *)((u8 *)(u32)D_84193DD0 + (arg0 << 4) + 0x12)) & 0x4) != 0) { func_8411FEE8(0); return 1; } return 0; }

s32 func_8411F82C(s32 arg0) {
    if (*(u16 *)((u8 *)(u32)D_84193DD0 + (arg0 << 4) + 0x10) == 0x20) {
        func_8411FEE8(0);
        return 1;
    }
    return 0;
}

s32 func_8411F878(s32 arg0) {
    if (*(u16 *)((u8 *)(u32)D_84193DD0 + (arg0 << 4) + 0x10) == 7) {
        func_8411FEE8(0);
        return 1;
    }
    return 0;
}

extern u8 *D_84193DD0; extern void func_8411FEE8(u16);
s32 func_8411F8C4(s32 arg0) { if ((*(u16 *)((u8 *)(u32)D_84193DD0 + (arg0 << 4) + 0xE)) == 0) { func_8411FEE8(0); return 1; } return 0; }

extern void func_8410B104(void);
extern void func_800238C4(void);
extern s32 func_8411F750(s32);
extern void func_841125F4(s32, s32);
void func_8411F90C(s32 arg0, s32 arg1) {
    func_8410B104();
    func_800238C4();
    func_841125F4(func_8411F750(arg0), 0x1F);
}

extern s32 D_84191208;
extern s32 D_8419120C;
extern s32 func_8003570C(void);
extern u16 D_84183C60[];
extern u8 *D_841911E0;
extern void func_84111348(s32, s32);
extern void func_841125F4(s32, s32);
extern s32 func_8411F750(s32 arg0);
extern void func_8411FEE8(u16 arg0);
void func_8411F94C(void *arg0, void *arg1) {
    u32 v0;

    func_8411FEE8(0x64);
    func_841125F4(D_84191208, 0);
    func_841125F4(D_8419120C, 0);
    v0 = func_8003570C();
    (*(u16 *)((u8 *)(D_841911E0) + (0x98))) = D_84183C60[v0 % 5];
    func_84111348(func_8411F750((s32) arg0), 0xA);
}

extern void func_84112564(s32);
extern void func_84111348(s32, s32);
extern u8 *D_841911E0;
void func_8411F9D8(s32 arg0, s32 arg1) {
    func_8411FEE8(0x12C);
    func_841125F4(D_84191208, 0x1B);
    func_841125F4(D_8419120C, 0x1B);
    func_84112564(func_8411F750(arg0));
    *(u16 *)(D_841911E0 + 0x98) = 0;
    func_84111348(func_8411F750(arg0), 0x12);
}

extern void func_841125F4(s32, s32); void func_8411FA50(s32 arg0, s32 arg1) { func_841125F4(func_8411F750(arg0), 0x16); }

extern void func_841125F4(s32, s32); void func_8411FA7C(s32 arg0, s32 arg1) { func_841125F4(func_8411F750(arg0), 2); }

extern void func_841125F4(s32, s32); void func_8411FAA8(s32 arg0, s32 arg1) { func_841125F4(func_8411F750(arg0), 8); }

extern void func_841125F4(s32, s32); void func_8411FAD4(s32 arg0, s32 arg1) { func_841125F4(func_8411F750(arg0), 6); }

extern void func_841125F4(s32, s32); void func_8411FB00(s32 arg0, s32 arg1) { func_841125F4(func_8411F750(arg0), 7); }

void func_8411FB2C(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0xF);
}
void func_8411FB2C_padding(void) {}

void func_8411FB60(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x10);
}

void func_8411FB8C(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x11);
}

void func_8411FBB8(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 4);
}

void func_8411FBE4(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 5);
}

void func_8411FC10(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x13);
}

void func_8411FC3C(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x17);
}

void func_8411FC68(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 3);
}

extern u8 D_841911F9;
void func_8411FC94(s32 arg0, s32 arg1) {
    if (D_841911F9 == 5) {
        func_841125F4(func_8411F750(0), 0x22);
    } else {
        func_841125F4(func_8411F750(0), 0x18);
    }
}

void func_8411FCF4(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0xC);
}

void func_8411FD20(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x19);
}

void func_8411FD4C(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x12);
}

void func_8411FD78(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x14);
}

void func_8411FDA4(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 9);
}

void func_8411FDD0(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0xB);
}

void func_8411FDFC(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0xD);
}

void func_8411FE28(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x15);
}

void func_8411FE54(s32 arg0, s32 arg1) {
    func_841125F4(func_8411F750(arg0), 0x1C);
}

s32 func_8411FE80(void) {
    if ((*(u8 *)((u8 *)(D_84193DD0) + (2))) == 0) {
        return 1;
    }
    (*(u8 *)((u8 *)(D_84193DD0) + (2))) = 0U;
    return 0;
}

void func_8411FEAC(u8 arg0, u16 arg1, u8 arg2) {
    D_84193DD0[0] = arg0;
    *(u16 *)(D_84193DD0 + 4) = arg1;
    D_84193DD0[2] = 1;
    D_84193DD0[8] = arg2;
}

extern u8 *D_84193DD0;
void func_8411FEE8(u16 arg0) {
    *(u16 *)(D_84193DD0 + 6) = arg0;
}

void func_8411FEFC(void) {
    if (*(u16 *)(D_84193DD0 + 6) != 0) {
        *(u16 *)(D_84193DD0 + 6) -= 1;
    }
}

// Record that D_84193DD0 points to. unk_00 selects one of the 16-byte unk_10 entries;
// func_8411F794 tests bit 0x2 of unk_10[arg0].unk_02, the halfword tested here for 0x10/0x20/0x40.
typedef struct unk_D_84193DD0_entry {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u8 unk_04[12];
} unk_D_84193DD0_entry; // size = 0x10
typedef struct unk_D_84193DD0 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01[3];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09[7];
    /* 0x10 */ unk_D_84193DD0_entry unk_10[1];
} unk_D_84193DD0;
extern void func_8410B578(f32);
extern void func_84112DB8(void);
extern void func_84111C1C(void);
extern void func_84109118(s32);
extern u8 D_841911FA;
extern u8 D_841911F9;
void func_8411FF1C(void) {
    s32 flags;
    s32 cmd;

    if (func_8411FE80() != 0) {
        return;
    }
    func_8410B578(0.0f);
    func_8411FEE8(100);
    switch (((unk_D_84193DD0 *)D_84193DD0)->unk_04) {
    case 92:
    case 93:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 104:
    case 105:
        func_84112DB8();
        func_8411F90C(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 90:
        D_841911FA = 0;
        func_84112DB8();
        func_8411F94C(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 91:
        flags = ((unk_D_84193DD0 *)D_84193DD0)->unk_10[((unk_D_84193DD0 *)D_84193DD0)->unk_00].unk_02;
        if (flags & 0x10) {
            func_84109118(1);
        } else if (flags & 0x20) {
            func_84109118(0);
        } else if (flags & 0x40) {
            func_84109118(2);
        }
        func_84112DB8();
        func_8411F9D8(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 0:
        cmd = ((unk_D_84193DD0 *)D_84193DD0)->unk_08;
        if (cmd == 91) {
            func_8411FB2C(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        } else if (cmd == 164) {
            func_8411FDD0(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        } else if (cmd == 144) {
            func_8411FDFC(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        } else if (cmd == 251) {
            func_8411FA50(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        } else if (cmd > 0 && cmd < 251) {
            func_8411FA7C(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        }
        break;
    case 26:
        func_8411FAD4(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 27:
        func_8411FB00(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 22:
    case 23:
    case 24:
    case 25:
        func_8411FAA8(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 1:
        func_8411FB60(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 6:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
    case 89:
        func_8411FDA4(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 44:
        func_8411FB8C(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 59:
    case 75:
        func_8411FBB8(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 55:
        func_841125F4(func_8411F750(((unk_D_84193DD0 *)D_84193DD0)->unk_00), 32);
        break;
    case 28:
        func_8411FBE4(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 29:
        func_8411FC10(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 38:
        func_8411FD78(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 34:
        func_8411FC94(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 45:
    case 46:
    case 47:
        func_8411FD20(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 33:
    case 35:
    case 36:
        func_8411FCF4(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 41:
    case 42:
    case 43:
    case 56:
    case 57:
    case 58:
        D_841911FA = 0;
        func_84111C1C();
        func_8411FCF4(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 30:
    case 31:
    case 32:
        func_8411FD4C(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
        func_84112DB8();
    case 54:
        func_8411FE54(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 39:
        func_8411FE28(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 37:
        func_8411FC68(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 40:
        func_8411FC3C(((unk_D_84193DD0 *)D_84193DD0)->unk_00, ((unk_D_84193DD0 *)D_84193DD0)->unk_04);
        break;
    case 101:
        if (D_841911F9 == 5) {
            func_841125F4(func_8411F750(0), 33);
        } else {
            func_841125F4(func_8411F750(0), 26);
        }
        break;
    case 102:
        func_841125F4(func_8411F750(0), 29);
        break;
    case 103:
        func_841125F4(func_8411F750(((unk_D_84193DD0 *)D_84193DD0)->unk_00), 30);
        break;
    }
}
#endif
