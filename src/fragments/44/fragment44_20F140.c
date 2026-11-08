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

extern void _bzero(void *, s32);
void func_8AF20FF8(s32 arg0, u8 *destination) {
    unk_func_8AF20F64 packet;
    u8 *node;
    unk_func_8AF20F64 *settings;
    s32 x;
    s32 y;

    node = (u8 *)arg0;
    settings = &packet;
    x = *(s16 *)(node + 8);
    y = *(s16 *)(node + 10);
    _bzero(settings, sizeof(packet));
    ((s16 *)settings)[0] = *(s16 *)(node + 12);
    ((s16 *)settings)[1] = *(s16 *)(node + 14);
    ((s16 *)settings)[10] = 13;
    settings->unk_00[9] = 85;
    settings->unk_00[10] = 65;
    settings->unk_00[11] = 3;
    ((s16 *)settings)[30] = 2;
    settings->unk_00[1] = 0;
    settings->unk_00[2] = 0;
    ((s16 *)settings)[6] = 0;
    ((s16 *)settings)[7] = 0;
    ((s16 *)settings)[9] = 0;
    ((s16 *)settings)[31] = 1;
    settings->unk_00[13] = 5;
    settings->unk_00[14] = 0;
    ((s16 *)settings)[37] = 65;
    func_8AF20F64(destination, 10, x, y, 8, 0, 0, 0, 100, 100, 100, 4, 11, settings);
}

/* mkdraft:func_8AF210FC begin */
extern u8 *D_8AF279B0;
extern s32 D_8AF3A000;
extern s32 D_8AF3A004;
extern s16 D_8AF3A008;
extern void func_8AC06570(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
extern s32 func_8AF02C28();




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

extern u8 func_8005453C(s32);
extern u8 *D_8AF3A098;
void func_8AF21FBC(s16 arg0) {
    s32 i;
    s16 flags[6];
    s16 *flag;

    i = 0;
    flag = flags;
    do {
        *flag = func_8005453C(i);
        i++;
        flag++;
    } while (i != 6);
    switch (arg0) {
    case 1:
        *(s16 *)(D_8AF3A090 + 50) = 226;
        break;
    case 2:
        if ((flags[2] == 1) && (flags[5] == 1)) {
            *(s16 *)(D_8AF3A090 + 50) = 230;
        } else if (flags[2] == 1) {
            *(s16 *)(D_8AF3A090 + 50) = 229;
        } else if ((flags[1] == 1) && (flags[4] == 1)) {
            *(s16 *)(D_8AF3A090 + 50) = 228;
        } else if ((flags[0] == 1) && (flags[3] == 1)) {
            *(s16 *)(D_8AF3A090 + 50) = 228;
        } else {
            *(s16 *)(D_8AF3A090 + 50) = 227;
        }
        break;
    }
    *(s16 *)(D_8AF3A098 + 50) = 242;
}

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

extern void func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);
extern void func_800476A0(u8 *, s32);
extern void func_800476FC(u8 *, s32);
extern void func_80047738(s32, s32, s32, s32);
extern void func_8AC07A8C(void);
extern s32 func_8AF220E8(void);
extern u8 *func_8AC06D8C(s32, s32);
extern void func_8AC05E40(s32, s32, u8 *);
extern void func_8AC06400(u8 *, u8 *);
extern void func_8AC02C80(s32, s32, s32, u8 *);
extern void func_8004E308(u8 *, void *, s32);
extern s32 func_8004E0F0(s32, s16, s32);
extern void func_8AF22608(s32);
extern void func_8AC0080C(s32);
extern void func_8AC006F4(void);
extern s32 func_8AF2228C(void);
extern s32 func_8AF22384(void);
extern void func_80054488(s32, u8);
extern void func_8AF219B4(void);
extern void func_8AF013D8(void);
extern s32 D_8AF26564;
extern s16 D_8AF3A084;
extern s16 D_8AF3A170;
extern u8 D_8AF3A050[];
extern u8 D_8AF3A0C8[];
extern u8 D_8AF3A0F8[];
extern u8 D_8AF3A1A8[];
extern u8 D_8AF3A220[];
extern u8 D_8AF3A298[];
extern u8 D_8AF3A310[];
extern u8 *D_8AF3A098;
extern u8 *D_8AF3A09C;
extern u8 *D_8AF3A0A0;
extern u8 *D_8AF3A0A4;
extern u8 *D_8AF3A0A8;
extern u8 *D_8AF3A0AC;
extern u8 *D_8AF3A0B8;
extern u8 *D_8AF3A0BC;
extern u8 *D_8AF3A0C0;
extern u8 *D_8AF3A124;
extern u8 *D_8AF3A128;
extern u8 *D_8AF3A12C;
extern u8 *D_8AF3A130;
extern u8 *D_8AF3A134;
extern u8 *D_8AF3A138;
extern u8 *D_8AF3A13C;
extern u8 *D_8AF3A150;
extern u8 *D_8AF3A154;
extern u8 *D_8AF3A164;
extern u8 *D_8AF3A168;

// Setup for window 31, opened by the fragment 44 menu dispatcher (case 31 in
// fragment44_1EE290.c). Loads this window's assets from the archive returned by
// func_8AF220E8 by four-character tag. For each of the D_8AF3A19C 0x44-byte records
// at D_8AF3A198, it resolves the three tags stored at +4/+8/+0xC and the per-index
// 'ff_N'/'fb_N' assets, registers func_8AF219B4 on the third asset, and caches
// three func_8004E0F0 lookups for the record's halfword id. The starting record
// D_8AF3A082 comes from the caller's object (kind 1), D_8AF3A084 (when D_8AF26564
// is set) or 0.
//@src/fragments/44/fragment44_1EE290.c
void func_8AF233B4(void) {
    s32 archive;
    u8 *entry;
    s32 i;
    s16 slot;
    void (*callback)(void);
    s16 result;

    D_8AF3A148 = 0;
    func_8004C8C0(147);
    func_8AC07A8C();
    func_8004C8C0(187);
    func_8004C8C0(50);
    func_800476A0(D_8AF3A050, 3);
    func_800476FC(D_8AF3A050, 3);
    func_80047738(0, func_8004C990(187, 0), 0, 0);
    func_80047738(1, func_8004C990(187, 1), 0, 0);
    func_80047738(2, func_8004C990(50, 1), 0, 0);
    archive = func_8AF220E8();
    D_8AF3A08C = func_8AC06D8C(archive, 'msg1');
    *(s16 *)(D_8AF3A08C + 0x30) = 56;
    D_8AF3A090 = func_8AC06D8C(archive, 'msg2');
    D_8AF3A094 = func_8AC06D8C(archive, 'name');
    D_8AF3A098 = func_8AC06D8C(archive, 'endd');
    D_8AF3A09C = func_8AC06D8C(archive, 'true');
    D_8AF3A0A0 = func_8AC06D8C(archive, 'shob');
    D_8AF3A0A4 = func_8AC06D8C(archive, 'yes1');
    D_8AF3A0A8 = func_8AC06D8C(archive, 'no01');
    D_8AF3A0AC = func_8AC06D8C(archive, 'no02');
    D_8AF3A128 = func_8AC06D8C(archive, 'mes0');
    D_8AF3A12C = func_8AC06D8C(archive, 'mes1');
    D_8AF3A130 = func_8AC06D8C(archive, 'mes2');
    D_8AF3A13C = func_8AC06D8C(archive, 'Abtn');
    D_8AF3A134 = func_8AC06D8C(archive, 'AAAA');
    D_8AF3A138 = func_8AC06D8C(archive, 'aaaa');
    func_8AC05E40(archive, 'Abtn', D_8AF3A220);
    func_8AC06400(D_8AF3A220, D_8AF3A13C);
    func_8AC05E40(archive, 'AAAA', D_8AF3A298);
    func_8AC06400(D_8AF3A298, D_8AF3A134);
    func_8AC05E40(archive, 'aaaa', D_8AF3A310);
    func_8AC06400(D_8AF3A310, D_8AF3A138);
    D_8AF3A0B0 = (u16 *)func_8AC06D8C(archive, 'nmST');
    D_8AF3A0B4 = (u16 *)func_8AC06D8C(archive, 'nmRV');
    D_8AF3A0B8 = func_8AC06D8C(archive, 'swin');
    D_8AF3A0BC = func_8AC06D8C(archive, 'stme');
    D_8AF3A0C0 = func_8AC06D8C(archive, 'strt');
    D_8AF3A150 = func_8AC06D8C(archive, 'joba');
    D_8AF3A124 = func_8AC06D8C(archive, 'wind');
    D_8AF3A154 = func_8AC06D8C(archive, 'abtn');
    func_8AC05E40(archive, 'abtn', D_8AF3A1A8);
    func_8AC06400(D_8AF3A1A8, D_8AF3A154);
    func_8AC02C80(archive, 'r_l_', 'r_r_', D_8AF3A0C8);
    func_8AC02C80(archive, 'sanl', 'sanr', D_8AF3A0F8);
    entry = D_8AF3A198;
    callback = func_8AF219B4;
    for (i = 0; i < D_8AF3A19C; i++) {
        *(u8 **)(entry + 0x20) = func_8AC06D8C(archive, *(s32 *)(entry + 4));
        *(u8 **)(entry + 0x24) = func_8AC06D8C(archive, *(s32 *)(entry + 8));
        *(u8 **)(entry + 0x28) = func_8AC06D8C(archive, *(s32 *)(entry + 0xC));
        *(u8 **)(entry + 0x2C) = func_8AC06D8C(archive, i + 'ff_1');
        *(u8 **)(entry + 0x30) = func_8AC06D8C(archive, i + 'fb_1');
        func_8004E308(*(u8 **)(entry + 0x28), callback, i);
        *(s32 *)(entry + 0x34) = func_8004E0F0(0, *(s16 *)entry, 0);
        *(s32 *)(entry + 0x38) = func_8004E0F0(0, *(s16 *)entry, 1);
        *(s32 *)(entry + 0x3C) = func_8004E0F0(0, *(s16 *)entry, 2);
        entry += 0x44;
    }
    D_8AF3A160 = func_8AC06D8C(archive, 'yub1');
    D_8AF3A164 = func_8AC06D8C(archive, 'yub2');
    D_8AF3A168 = func_8AC06D8C(archive, 'yub3');
    func_8004E308(D_8AF3A160, func_8AF013D8, 0);
    func_8004E308(D_8AF3A164, func_8AF013D8, 0);
    func_8004E308(D_8AF3A168, func_8AF013D8, 0);
    if (D_8AF2BA6E == 1) {
        D_8AF3A082 = D_8AF2BDD8[1];
        func_8AF22608(0);
        func_8AC0080C(8);
    } else if (D_8AF26564 != 0) {
        D_8AF3A082 = D_8AF3A084;
        func_8AF22608(0);
        func_8AC0080C(4);
        func_8AC006F4();
        func_8AC00738();
    } else {
        D_8AF3A082 = 0;
        func_8AF22608(0);
    }
    D_8AF3A084 = 0;
    if ((D_8AF2BA6E == 1) && (D_8AF2BDD8[2] != 0)) {
        D_8AF2BA6E = 0;
    }
    if (D_8AF2BA6E == 1) {
        D_8AF3A174 = 3;
        D_8AF3A176 = 7;
        switch ((*(u8 **)(D_8AF2BDD8 + 4))[0x9C6]) {
            case 0:
            case 4:
                if (func_8AF2228C() != 0) {
                    D_8AF3A174 = 1;
                    if (func_8AF22384() != 0) {
                        D_8AF3A176 = 4;
                    } else {
                        D_8AF3A176 = 5;
                    }
                } else {
                    D_8AF3A174 = 2;
                    D_8AF3A176 = 6;
                }
                func_8AF22608(4);
                break;
            default:
            case 1:
            case 2:
            case 3:
                func_8AF22608(6);
                break;
        }
        slot = func_8AF21C04();
        result = func_80054410(slot);
        if (result != 1) {
            if ((result != 2) && (D_8AF3A174 == 1)) {
                D_8AF3A148 = 1;
                D_8AF3A14C = slot;
            }
            func_80054488(slot, ((u8 *)&D_8AF3A174)[1]);
            func_80051D64(19, 0);
            func_80054E48(3);
        }
    } else if (D_8AF2BA6E == 1) {
        // Unreachable: the preceding test already took every D_8AF2BA6E == 1 path.
        // It is kept because the original code tests and stores it.
        D_8AF2BA6E = 0;
    }
    func_8AF22594();
    func_8AF21D14();
    func_8AF21EE0();
    D_8AF3A170 = 0;
}

extern void func_8AC006B8(s32, s32, s32, s32);
void func_8AF23B38(void) {
    func_8AC006B8(56, 26, 584, 454);
}

#include "global.h"
extern void func_80021ED8(s32);
extern s32 func_80025D44(void);
extern void func_8AF00130(s32);
extern void func_8AF21C58(void);
extern void func_8AF221C4(void);
extern s16 D_8AF3A080;
extern u8 *D_8AF2BDD8;
extern s8 D_8AF3A144;
extern s32 func_8AC07AF4();
extern void func_8AF21D14(void);
extern void func_8AF22608(s32);
extern s32 func_8AF223C8();
extern s16 D_8AF2BDDC;
extern s32 D_8AF2BA68;
extern s16 D_8AF2BA6E;
extern s16 D_8AF3A082;
extern s16 D_8AF3A19C;
extern u8 D_8AF3A220[];
extern u8 D_8AF3A310[];
extern u8 D_8AF3A1A8[];
extern u16 D_8AF3A388[];
extern u16 D_8AF3A38C[];
extern u16 D_8AF3A390[];
extern u16 D_8AF3A394[];
extern u16 D_8AF3A398[];
extern s32 D_8AF3A194;
extern s32 D_8AF3A148;
extern u8 *D_8AF3A154;
extern s16 D_8AF3A174;
extern s16 D_8AF3A142;
extern u32 D_8AF2BDC4;
extern u8 D_8AF279CC[];
extern u8 D_8AF279C4[];
struct RGB { u8 r, g, b; };
extern s16 D_8AF3A084;
extern s16 D_8AF3A140;
extern u8 *D_8AF263C0;
extern void func_8AC006F4(void);
extern void func_8AC007FC(void);
extern void func_8AC0080C(s32);
extern void func_8AC00824(void);
extern void func_8AF079FC(s16, s16);


s16 func_8AF23B64(void)
{
  s16 var_v0;
  u8 *node;
  u16 temp_t0_unused;
  s16 temp_t2;
  s16 sp32;
  s32 temp_t0;
  u8 sp28[4];
  var_v0 = 0x1F;
  if (D_8AF2BDDC < 2)
  {
    goto label_1;
  }
  func_8AC007FC();
label_1:
  if (D_8AF2BA68 == 2)
  {
    return var_v0;
  }
  func_8AF221C4();
  switch (*(u16 *) (&D_8AF3A080))
  {
    case 0:
      node = D_8AF263C0;
      temp_t0 = *((u16 *) (node + 8));
      if (temp_t0 & 0x4000)
      {
        func_8AF00130(3);
        D_8AF2BA6E = 0;
        var_v0 = 0x24;
        break;
      }
      if (temp_t0 & 0x10)
      {
        func_8AF00130(0xC0);
        func_8AF22608(1);
        break;
      }
      if (temp_t0 & 0x8000)
      {
        func_8AF00130(0xC0);
        func_8AF22608(3);
        break;
      }
      node = D_8AF263C0;
      if (((*((u16 *) (node + 0xC))) & 0x200) && (D_8AF3A082 > 0))
      {
        func_8AF00130(1);
        D_8AF3A082 -= 1;
        D_8AF2BA6E = 0;
        func_8AF21D14();
      }
      else
        if ((*((u16 *) (node + 0xC))) & 0x100)
        {
          if (D_8AF3A082 < (D_8AF3A19C - 1))
          {
            func_8AF00130(1);
            D_8AF3A082 += 1;
            D_8AF2BA6E = 0;
            func_8AF21D14();
          }
        }
      break;

    case 1:
      func_8AF21960(&D_8AF3A220, &D_8AF3A388);
      temp_t0 = *((u16 *) (((u8 *) D_8AF263C0) + 8));
      if (temp_t0 & 0x4000)
      {
        func_8AF00130(3);
        func_8AF22608(0);
        func_8AC00824();
      }
      else
        if (temp_t0 & 0x8000)
        {
          func_8AF00130(0xC1);
          func_8AF22608(2);
        }
      break;

    case 2:
      func_8AF21960(&D_8AF3A220, &D_8AF3A38C);
      temp_t0 = *((u16 *) (((u8 *) D_8AF263C0) + 8));
      if (temp_t0 & 0x4000)
      {
        func_8AF00130(3);
        func_8AF22608(1);
      }
      else
        if (temp_t0 & 0x8000)
        {
          func_8AF00130(3);
          func_8AF22608(0);
          func_8AC00824();
        }
      break;

    case 4:
      if (D_8AF3A194 != 0)
      {
        if (func_80025D44() == 0)
        {
          func_80021ED8(7);
          D_8AF3A194 = 0;
          if (D_8AF3A148 != 0)
          {
            D_8AF3A148 = 0;
            func_8AF223C8();
            func_8AF21C58();
          }
        }
      }
      else
      {
        *((u16 *) (((u8 *) D_8AF3A154) + 2)) |= 1;
        func_8AF21960(&D_8AF3A1A8, &D_8AF3A38C[1]);
        if ((*((u16 *) (((u8 *) D_8AF263C0) + 8))) & 0x8000)
        {
          func_8AF22608(5);
          func_8AF00130(0xC2);
        }
      }
      break;

    case 5:
      func_8AF21960(&D_8AF3A310, &D_8AF3A390);
      if ((*((u16 *) (((u8 *) D_8AF263C0) + 8))) & 0x8000)
      {
        func_8AF00130(0xC2);
        func_8005453C(*D_8AF2BDD8);
        if (((*(u8 *) (&D_8AF3A144)) == 0) && (func_8005453C(*D_8AF2BDD8) == 1) && (D_8AF3A174 == 1))
        {
          func_8AF22608(8);
          func_8AC0080C(4);
        }
        else
        {
          func_8AF22608(0);
          D_8AF2BA6E = 0;
          func_8AC0080C(4);
          func_8AC006F4();
          func_8AC00738();
        }
      }
      break;

    case 8:
      func_8AF21960(&D_8AF3A310, &D_8AF3A390[1]);
      if ((*((u16 *) (((u8 *) D_8AF263C0) + 8))) & 0x8000)
      {
        func_8AF22608(9);
        func_80021ED8(0x4A);
      }
      break;

    case 9:
      if (D_8AF3A142 < 0x87)
      {
        temp_t0 = (guRandom() % 6) + 5;
        if ((D_8AF2BDC4 % ((u32) temp_t0)) == 0)
        {
          *((struct RGB *) sp28) = *((struct RGB *) (D_8AF279CC + ((guRandom() % 3) * 3)));
          sp32 = (guRandom() % 0xC8) - 0x64;
          temp_t2 = (guRandom() % 0x64) - 0x32;
          if (func_8AC07AF4(sp32 + 0x140, temp_t2 + 0xC8, D_8AF279C4, sp28) != 0)
          {
            func_8AF00130(0xCF);
          }
        }
      }
      if (((u32) func_80025D44() < 2) && (D_8AF3A142 >= 0xB5))
      {
        func_8AF22608(0xA);
        func_8AC0080C(4);
        D_8AF3A194 = 1;
      }
      else
      {
        D_8AF3A142 += 1;
      }
      break;

    case 10:
      if ((D_8AF3A194 != 0) && (func_80025D44() == 0))
      {
        func_80021ED8(7);
        D_8AF3A194 = 0;
      }
      func_8AF21960(&D_8AF3A310, &D_8AF3A394);
      if ((*((u16 *) (((u8 *) D_8AF263C0) + 8))) & 0x8000)
      {
        func_8AF00130(0xC2);
        func_8AF22608(0);
        D_8AF2BA6E = 0;
        func_8AC0080C(4);
        func_8AC006F4();
        func_8AC00738();
        var_v0 = 0x24;
      }
      break;

    case 6:
      *((u16 *) (((u8 *) D_8AF3A154) + 2)) |= 1;
      func_8AF21960(&D_8AF3A1A8, &D_8AF3A394[1]);
      if ((*((u16 *) (((u8 *) D_8AF263C0) + 8))) & 0x8000)
      {
        func_8AF00130(0xC2);
        func_8AF22608(7);
        func_8AC0080C(4);
      }
      break;

    case 7:
      func_8AF21960(&D_8AF3A310, &D_8AF3A398);
      if ((*((u16 *) (((u8 *) D_8AF263C0) + 8))) & 0x8000)
      {
        func_8AF00130(0xC2);
        func_8AF22608(0);
        D_8AF2BA6E = 0;
        func_8AC0080C(4);
        func_8AC006F4();
        func_8AC00738();
      }
      break;

    case 3:
      func_8AF21960(&D_8AF3A310, &D_8AF3A398[1]);
      temp_t0 = *((u16 *) (((u8 *) D_8AF263C0) + 8));
      if (temp_t0 & 0x4000)
      {
        func_8AF00130(3);
        func_8AF22608(0);
        break;
      }
      if (temp_t0 & 0x8000)
      {
        switch (D_8AF3A140)
        {
          case 0:
            func_8AF00130(0xC1);
            D_8AF2BDD8[1] = (u8) D_8AF3A082;
            D_8AF2BA68 = 2;
            func_8AC006F4();
            func_8AC00738();
            break;

          case 1:
            func_8AF00130(0xC2);
            switch (D_8AF2BDD8[0])
            {
              case 0:
                var_v0 = 3;
                D_8AF2BA6E = 0;
                break;

              case 1:
                var_v0 = 4;
                D_8AF2BA6E = 0;
                break;

              case 2:
                var_v0 = 5;
                D_8AF2BA6E = 0;
                break;

            }
            func_8AF079FC(D_8AF2BDD8[0], D_8AF3A082);
            D_8AF3A084 = D_8AF3A082;
            func_8AC0080C(4);
            func_8AC006F4();
            func_8AC00738();
            break;

          case 2:
            func_8AF00130(3);
            func_8AF22608(0);
            break;

        }
        break;
      }
      if (temp_t0 & 0x800)
      {
        if (D_8AF3A140 > 0)
        {
          func_8AF00130(1);
          D_8AF3A140 -= 1;
        }
      }
      else
        if (temp_t0 & 0x400)
        {
          if (D_8AF3A140 < 2)
          {
            func_8AF00130(1);
            D_8AF3A140 += 1;
          }
        }
      break;

  }

  return var_v0;
}

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
