#include "global.h"


#ifdef VERSION_US
// Not referenced by code or data (debug format strings); they open this file's .rodata.
const char D_8AF2A0F0[] = "ogSetPage_EGG_NAME_S1() target = [%s]\n";
const char D_8AF2A118[] = "size of OG_WIN_TYPE = %d\n";
const char D_8AF2A134[] = "Egg Group %d\n";
const char D_8AF2A144[] = "ogSetPage_EGG_NAME_S1() end\n";
const char D_8AF2A164[] = "";
const char D_8AF2A168[] = "";
const char D_8AF2A16C[] = "";
const char D_8AF2A170[] = "EGG_NAME_S2 : ogSetCursorMode() step1\n";
const char D_8AF2A198[] = "EGG_NAME_S2 : ogSetCursorMode() step2\n";
const char D_8AF2A1C0[] = "pane_wi_1(%d,%d) pane_wi_2(%d,%d)\n";
/* mkdraft:func_8AF20ED0 begin */
extern void func_800504BC(s16 *);
extern void func_8AC007B8(s32, s32, s32, s32);
extern void func_8AF02F18(void *);
extern void func_8AC00738(void);

s32 func_8AF20ED0(s32 arg0, u8 *arg1) {
    struct { s32 pad[2]; s16 angles[2]; } scratch;
    s32 *ptr;
    s16 x;
    s16 y;
    s16 z;
    s16 w;

    ptr = *(s32 **)(arg1 + 0x20);
    if ((arg0 != 0) && (arg0 == 1)) {
        func_800504BC(scratch.angles);
        x = *(s16 *)(arg1 + 8) + scratch.angles[0];
        y = *(s16 *)(arg1 + 0xA) + scratch.angles[1];
        z = *(s16 *)(arg1 + 0xC);
        w = *(s16 *)(arg1 + 0xE);
        ptr[2] = x;
        ptr[3] = y;
        func_8AC007B8(x, y, z, w);
        func_8AF02F18(ptr);
        func_8AC00738();
    }
    return 0;
}
/* mkdraft:func_8AF20ED0 end */

typedef struct {
    u32 unk_00[321];
} unk_func_8AF20F64;

void func_8AF20F64(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7,
                   u8 arg8, u8 arg9, u8 arg10, s32 arg11, s32 arg12, const unk_func_8AF20F64* arg13) {
    *(s32*)(arg0 + 24) = arg1;
    *(s32*)(arg0 + 8) = arg2;
    *(s32*)(arg0 + 12) = arg3;
    *(s32*)(arg0 + 16) = arg4;
    arg0[34] = arg5;
    arg0[35] = arg6;
    arg0[36] = arg7;
    arg0[37] = arg8;
    arg0[38] = arg9;
    arg0[39] = arg10;
    *(s32*)arg0 = arg11;
    *(s32*)(arg0 + 20) = -1;
    *(s32*)(arg0 + 28) = arg12;
    *(unk_func_8AF20F64*)(arg0 + 40) = *arg13;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20F140/func_8AF20FF8.s")

/* mkdraft:func_8AF210FC begin */
extern u8 *D_8AF279B0;
extern s32 D_8AF3A000;
extern s32 D_8AF3A004;
extern s16 D_8AF3A008;
extern void func_8AC06570(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
extern s32 func_8AF02C28();
extern s32 func_8AF20FF8();




void func_8AF210FC(s16 arg0) {
    extern u8 D_8AF39A00[];
    extern u8 D_8AF2BE28[];
    extern u8 D_8AF39C00[];
    extern u8 D_8AF2BE48[];
    extern u8 D_8AF39FE0;
    extern u8 D_8AF39FF0;
    u8 *ptr;

    D_8AF3A008 = arg0;
    switch (D_8AF3A008) {
    case 0:
        func_8AF20FF8((s32)D_8AF3A000, D_8AF279B0);
        func_8AF02C28(D_8AF279B0, D_8AF39A00, D_8AF2BE28, 0x494C5331);
        ptr = D_8AF279B0 + 0x28;
        *(s16 *)(ptr + 0x18) = 1;
        func_8AC06570(&D_8AF39FE0, *(s16 *)(ptr + 0x22), 0x41, 3, 2, 0xA);
        break;
    case 1:
        func_8AF20FF8((s32)D_8AF3A004, D_8AF279B0 + 0x52C);
        func_8AF02C28(D_8AF279B0 + 0x52C, D_8AF39C00, D_8AF2BE48, 0x494C5332);
        ptr = D_8AF279B0 + 0x554;
        *(s16 *)(ptr + 0x18) = 1;
        func_8AC06570(&D_8AF39FF0, *(s16 *)(ptr + 0x22), 0x41, 3, 2, 0xA);
        break;
    }
}
/* mkdraft:func_8AF210FC end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20F140/func_8AF2123C.s")

/* mkdraft:func_8AF21610 begin */
extern s32 func_8AF0326C(u8 *);
extern void func_8AC0602C(void *, u16, s32);
extern void func_8AC060E4(void *, u16, s32);
extern void func_8AC0686C(void *, s16);
extern void func_8AF00130(s32);
extern u8 *D_8AF263C0;
extern u8 *D_8AF279B0;
extern u16 D_8AF2BDC6;
extern u8 D_8AF39E00;
extern u8 D_8AF39E78;
extern u8 D_8AF39EF0;
extern u8 D_8AF39F68;
extern u8 D_8AF39FE0;
extern u8 D_8AF39FF0;
extern s16 D_8AF3A008;
extern u8 *D_8AF3A03C;
extern u8 *D_8AF3A040;
extern u8 *D_8AF3A044;
extern u8 *D_8AF3A048;

s16 func_8AF21610(void) {
    s16 result = 0x1B;
    u8 *ptr;
    s32 state;
    s32 temp;

    state = D_8AF3A008;
    switch (state) {
    case 0:
        ptr = D_8AF279B0;
        temp = func_8AF0326C(ptr);
        func_8AC0602C(&D_8AF39E00, D_8AF2BDC6, 1);
        func_8AC060E4(&D_8AF39E78, D_8AF2BDC6, 1);
        func_8AC0602C(&D_8AF39EF0, D_8AF2BDC6, 0);
        func_8AC060E4(&D_8AF39F68, D_8AF2BDC6, 0);
        func_8AC0686C(&D_8AF39FE0, *(s16 *)(ptr + 0x38));
        break;
    case 1:
        ptr = D_8AF279B0 + 0x52C;
        temp = func_8AF0326C(ptr);
        func_8AC0602C(&D_8AF39EF0, D_8AF2BDC6, 1);
        func_8AC060E4(&D_8AF39F68, D_8AF2BDC6, 1);
        func_8AC0602C(&D_8AF39E00, D_8AF2BDC6, 0);
        func_8AC060E4(&D_8AF39E78, D_8AF2BDC6, 0);
        func_8AC0686C(&D_8AF39FF0, *(s16 *)(ptr + 0x38));
        break;
    default:
        temp = 0;
        break;
    }
    if (temp == 0) {
        if ((D_8AF3A008 == 0) && (*(u16 *)(D_8AF263C0 + 8) & 0x100)) {
            func_8AF00130(1);
            D_8AF3A008 = 1;
        } else if ((D_8AF3A008 == 1) && (*(u16 *)(D_8AF263C0 + 8) & 0x200)) {
            func_8AF00130(1);
            D_8AF3A008 = 0;
        } else if (*(u16 *)(D_8AF263C0 + 8) & 0x4000) {
            func_8AF00130(3);
            D_8AF3A008 = -1;
            result = 0x18;
            *(u16 *)(D_8AF3A03C + 2) &= 0xFFFE;
            *(u16 *)(D_8AF3A040 + 2) &= 0xFFFE;
            *(u16 *)(D_8AF3A044 + 2) &= 0xFFFE;
            *(u16 *)(D_8AF3A048 + 2) &= 0xFFFE;
        }
    }
    return result;
}
/* mkdraft:func_8AF21610 end */

void func_8AF21864(void) {
    u8 *base;

    base = D_8AF279B0;
    if (func_8AC06800(&D_8AF39FE0, *(s16 *)(base + 0x38)) != 0) {
        func_8AC05F00(&D_8AF39E00);
    }
    if (func_8AC06834(&D_8AF39FE0, *(s16 *)(base + 0x38)) != 0) {
        func_8AC05F00(&D_8AF39E78);
    }
    if (D_8AF3A008 == 0) {
        func_8004B314(*(s32 *)(base + 8), *(s32 *)(base + 0xC), 255, 195);
    }
    base = D_8AF279B0 + 0x52C;
    if (func_8AC06800(&D_8AF39FF0, *(s16 *)(base + 0x38)) != 0) {
        func_8AC05F00(&D_8AF39EF0);
    }
    if (func_8AC06834(&D_8AF39FF0, *(s16 *)(base + 0x38)) != 0) {
        func_8AC05F00(&D_8AF39F68);
    }
    if (D_8AF3A008 == 1) {
        func_8004B314(*(s32 *)(base + 8), *(s32 *)(base + 0xC), 255, 195);
    }
}

/* mkdraft:func_8AF21960 begin */
extern f32 D_80088E50[];

void func_8AF21960(void *arg0, u16 *arg1) {
    f32 scale;
    u16 temp_v0;

    temp_v0 = *arg1;
    scale = 0.3f;
    // karodo: empty block. Its line boundary keeps the 1.0f materialization attributed
    // here instead of uopt's entry constant pool, so as1 schedules it next to the multiplies.
    if (arg0) {
    }
    *(f32 *)((u8 *)arg0 + 0x40) = D_80088E50[temp_v0 >> 4] * scale + 1.0f;
    *(f32 *)((u8 *)arg0 + 0x44) = D_80088E50[temp_v0 >> 4] * scale + 1.0f;
    temp_v0 += 0x2000;
    *arg1 = temp_v0;
}
/* mkdraft:func_8AF21960 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20F140/func_8AF219B4.s")

extern u8 *D_8AF2BDD8;
s16 func_8AF21C04(void) {
    u8 *entry = D_8AF2BDD8;
    s16 result;

    switch (entry[0]) {
        case 0:
            result = 0;
            break;
        case 1:
            result = 7;
            break;
        case 2:
            result = 0xC;
            break;
        default:
            result = 0;
            break;
    }
    result += entry[1];
    return result;
}

extern s16 D_8AF3A082;
extern u8 *D_8AF3A198;
extern u16 *D_8AF3A0B0;
extern u16 *D_8AF3A0B4;
typedef struct unk_func_8AF21C58 {
    u8 unk_00[64];
    s16 unk_40;
    u8 unk_42[2];
} unk_func_8AF21C58;

void func_8AF21C58(void) {
    unk_func_8AF21C58 *record = D_8AF3A082 + (unk_func_8AF21C58 *)D_8AF3A198;
    s16 mode = record->unk_40;

    switch (mode) {
    case 1:
        D_8AF3A0B0[1] |= 2;
        D_8AF3A0B4[1] &= ~2;
        break;
    case 2:
        D_8AF3A0B0[1] &= ~2;
        D_8AF3A0B4[1] |= 2;
        break;
    default:
        D_8AF3A0B0[1] &= ~2;
        D_8AF3A0B4[1] &= ~2;
        break;
    }
}

/* mkdraft:func_8AF21D14 begin */
extern s16 D_8AF2BA6E;
extern u8 *D_8AF3A08C;
extern u8 *D_8AF3A094;
extern s16 D_8AF3A174;
extern u8 *D_8AF3A198;
extern u8 func_80054410(s32 arg0);



void func_8AF21D14(void) {
    s16 value;
    u8 *entry;

    *(u8 *)(D_8AF2BDD8 + 1) = (u8) D_8AF3A082;
    value = func_8AF21C04();
    *(s16 *)(D_8AF3A094 + 0x32) = value + 0xBA;
    entry = (D_8AF3A082 * 0x44) + D_8AF3A198;
    if (*(s16 *)(entry + 0x40) == 1) {
        *(s32 *)(D_8AF3A094 + 0x28) = 0xC8C8C8FF;
        *(s32 *)(D_8AF3A094 + 0x2C) = 0xC8C8C8FF;
    } else {
        *(s32 *)(D_8AF3A094 + 0x28) = -1;
        *(s32 *)(D_8AF3A094 + 0x2C) = -1;
    }
    if (D_8AF2BA6E == 1) {
        switch (D_8AF3A174) {
        case 1:
            *(s16 *)(D_8AF3A08C + 0x32) = (value * 10) + 3;
            break;
        case 2:
            *(s16 *)(D_8AF3A08C + 0x32) = (value * 10) + 6;
            break;
        default:
        case 3:
            *(s16 *)(D_8AF3A08C + 0x32) = (value * 10) + 8;
            break;
        }
    } else {
        switch (func_80054410(value)) {
        case 1:
            *(s16 *)(D_8AF3A08C + 0x32) = (value * 10) + 1;
            break;
        case 2:
            *(s16 *)(D_8AF3A08C + 0x32) = (value * 10) + 2;
            break;
        default:
        case 3:
            *(s16 *)(D_8AF3A08C + 0x32) = value * 10;
            break;
        }
    }
    func_8AF21C58();
}
/* mkdraft:func_8AF21D14 end */

extern u8 *D_8AF2BDD8;
extern s16 D_8AF3A082;
extern u8 *D_8AF3A090;
extern s16 D_8AF3A176;
extern s16 func_8AF21C04(void);
void func_8AF21EE0(void) {
    s16 temp_v0;
    *(u8 *)(D_8AF2BDD8 + 1) = (u8)D_8AF3A082;
    temp_v0 = func_8AF21C04();
    switch (D_8AF3A176) {
    case 4:
        *(s16 *)(D_8AF3A090 + 0x32) = (s16)(((temp_v0 * 5) * 2) + 4);
        return;
    case 5:
        *(s16 *)(D_8AF3A090 + 0x32) = (s16)(((temp_v0 * 5) * 2) + 5);
        return;
    case 6:
        *(s16 *)(D_8AF3A090 + 0x32) = (s16)(((temp_v0 * 5) * 2) + 7);
        return;
    case 7:
    default:
        *(s16 *)(D_8AF3A090 + 0x32) = (s16)(((temp_v0 * 5) * 2) + 9);
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20F140/func_8AF21FBC.s")

extern u8 *D_8AF2BDD8;
extern u8 D_8AF279F0[];
extern u8 D_8AF27BCC[];
extern u8 D_8AF27D20[];
extern u8 *D_8AF3A198;
extern s16 D_8AF3A19C;
extern void func_8AF00504(s32);
extern s32 func_8AF003A8(s16);
s32 func_8AF220E8(void) {
    s32 sp1C;
    u8 temp_v0 = *D_8AF2BDD8;
    switch (temp_v0) {
    case 0:
        D_8AF3A19C = 7;
        D_8AF3A198 = D_8AF279F0;
        func_8AF00504(0x51);
        sp1C = func_8AF003A8(0x51);
        break;
    case 1:
        D_8AF3A19C = 5;
        D_8AF3A198 = D_8AF27BCC;
        func_8AF00504(0x47);
        sp1C = func_8AF003A8(0x47);
        break;
    case 2:
        D_8AF3A19C = 4;
        D_8AF3A198 = D_8AF27D20;
        func_8AF00504(0x3C);
        sp1C = func_8AF003A8(0x3C);
        break;
    }
    return sp1C;
}

extern s16 D_8AF3A080;
extern s16 D_8AF3A140;
extern u8 *D_8AF3A160;
extern u8 *D_8AF3A164;
extern u8 *D_8AF3A168;
void func_8AF221C4(void) {
    *(u16 *)(D_8AF3A160 + 2) &= ~1;
    *(u16 *)(D_8AF3A164 + 2) &= ~1;
    *(u16 *)(D_8AF3A168 + 2) &= ~1;
    if (D_8AF3A080 == 3) {
        switch (D_8AF3A140) {
            case 0:
                *(u16 *)(D_8AF3A160 + 2) |= 1;
                break;
            case 1:
                *(u16 *)(D_8AF3A164 + 2) |= 1;
                break;
            case 2:
                *(u16 *)(D_8AF3A168 + 2) |= 1;
                break;
        }
    }
}

s32 func_8AF2228C(void) {
    u8 *entry;
    u8 *party;
    s32 result;
    s32 a, b, c, x, y, z;

    result = 0;
    entry = D_8AF3A198 + D_8AF3A082 * 0x44;
    a = entry[0x1A];
    b = entry[0x1B];
    c = entry[0x1C];
    party = *(u8 **)(D_8AF2BDD8 + 4);
    x = party[0x18];
    y = party[0x70];
    party += 0xC8; // FAKE
    z = *party;
    if (x == a && y == b && z == c) {
        result = 1;
    }
    if (x == a && y == c && z == b) {
        result = 1;
    }
    if (x == b && y == a && z == c) {
        result = 1;
    }
    if (x == b && y == c && z == a) {
        result = 1;
    }
    if (x == c && y == a && z == b) {
        result = 1;
    }
    if (x == c && y == b && z == a) {
        result = 1;
    }
    return result;
}

s32 func_8AF22384(void) {
    u8 *entry = *(u8 **)(D_8AF2BDD8 + 4);
    s32 first = *(u16 *)(entry + 0x3E);
    s32 second = *(u16 *)(entry + 0x96);
    s32 third;
    entry += 0xC8;
    third = *(u16 *)(entry + 0x26);
    if ((first > 0) && (second > 0) && (third > 0)) {
        return 1;
    }
    return 0;
}

/* mkdraft:func_8AF223C8 begin */
extern u8 func_80054410(s32 arg0);
extern s32 D_8AF3A148;
extern s16 D_8AF3A14C;
extern s16 D_8AF3A19C;
extern u8 *D_8AF2BDD8;
extern u8 *D_8AF3A198;



s32 func_8AF223C8(void) {
    s16 ret;
    s16 count;
    s32 i;
    s32 mode;
    u8 *entry;

    mode = 0;
    count = 0;
    if ((*D_8AF2BDD8) == 1) {
        mode = 7;
    } else if ((*D_8AF2BDD8) == 2) {
        mode = 0xC;
    }
    entry = D_8AF3A198;
    i = 0;
    if (D_8AF3A19C > 0) {
        do {
            ret = func_80054410(mode + i);
            *(s16 *)(entry + 0x40) = ret;
            if ((D_8AF3A148 != 0) && (i == D_8AF3A14C)) {
                *(u16 *)(*(u8 **)(entry + 0x20) + 2) &= ~2;
                *(u16 *)(*(u8 **)(entry + 0x24) + 2) &= ~2;
                if (ret == 1) {
                    count += 1;
                }
            } else {
                switch (ret) {
                case 1:
                    *(u16 *)(*(u8 **)(entry + 0x20) + 2) |= 2;
                    count += 1;
                    *(u16 *)(*(u8 **)(entry + 0x24) + 2) &= ~2;
                    break;
                case 2:
                    *(u16 *)(*(u8 **)(entry + 0x20) + 2) &= ~2;
                    *(u16 *)(*(u8 **)(entry + 0x24) + 2) |= 2;
                    break;
                default:
                    *(u16 *)(*(u8 **)(entry + 0x20) + 2) &= ~2;
                    *(u16 *)(*(u8 **)(entry + 0x24) + 2) &= ~2;
                    break;
                }
            }
            i += 1;
            entry += 0x44;
        } while (i < D_8AF3A19C);
    }
    return count;
}
/* mkdraft:func_8AF223C8 end */

extern void func_80051D64(s32, s32);
s8 func_8005453C(u8);
extern void func_800545B4(u8, s32);
extern void func_80054E48(s32);
s32 func_8AF223C8();
extern u8 *D_8AF2BDD8;
extern s8 D_8AF3A144;
extern s16 D_8AF3A19C;

void func_8AF22594(void) {
    if (func_8AF223C8() >= D_8AF3A19C) {
        D_8AF3A144 = func_8005453C(*D_8AF2BDD8);
        func_800545B4(*D_8AF2BDD8, 1);
        func_80051D64(0x13, 0);
        func_80054E48(3);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20F140/func_8AF22608.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20F140/func_8AF233B4.s")

extern void func_8AC006B8(s32, s32, s32, s32);
void func_8AF23B38(void) {
    func_8AC006B8(56, 26, 584, 454);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20F140/func_8AF23B64.s")

extern void func_800498C4();
extern void func_800499EC();
extern void func_8AC005D8();
extern void func_8AC075A8();
extern s16 D_8AF2BA6E;
void func_8AF2447C(void) {
    if (D_8AF2BA6E == 1) {
        func_8AF23B38();
        func_8AC005D8();
        func_8AC075A8();
    }
    func_800498C4();
    func_800499EC();
}
#endif
