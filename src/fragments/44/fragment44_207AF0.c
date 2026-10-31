#include "global.h"


#ifdef VERSION_US
void *func_8004C874(s32, s32);
extern u8 D_8AF29BB0;

s32 *func_8AF19880(s16 arg0) {
    s32 *temp_v0;
    s32 *var_v1;

    temp_v0 = func_8004C874(8, arg0 - 1);
    var_v1 = temp_v0;
    if (temp_v0 == NULL) {
        var_v1 = &D_8AF29BB0;
    }
    return var_v1;
}

void *func_8004C874(s32, s32);
extern u8 D_8AF29BC0;

s32 *func_8AF198C4(s16 arg0) {
    s32 *temp_v0;
    s32 *var_v1;

    temp_v0 = func_8004C874(0xA, arg0 - 1);
    var_v1 = temp_v0;
    if (temp_v0 == NULL) {
        var_v1 = &D_8AF29BC0;
    }
    return var_v1;
}

extern u8 D_8AF29BD4[];
u8 *func_8AF19908(u8 *arg0) {
    u8 *result;
    s32 value;

    value = arg0[0];
    if ((value < 0xBE) || (value == 0xFF)) {
        result = (u8 *)func_8004C874(9, value - 1);
    } else {
        result = (u8 *)func_8004C874(7, arg0[1] - 1);
    }
    if (result == NULL) {
        result = D_8AF29BD4;
    }
    return result;
}

extern u8 D_8AF29BE4[];
u8 *func_8AF19970(u8 *arg0) {
    u8 *result;
    s32 value;

    value = arg0[0];
    if ((value < 0xBE) || (value == 0xFF)) {
        result = (u8 *)func_8004C874(0xB, value - 1);
    } else {
        result = (u8 *)func_8004C874(7, arg0[1] - 1);
    }
    if (result == NULL) {
        result = D_8AF29BE4;
    }
    return result;
}

void *func_8004C874(s32, s32);
extern u8 D_8AF29BF8;

s32 *func_8AF199D8(s16 arg0) {
    s32 *temp_v0;
    s32 *var_v1;

    temp_v0 = func_8004C874(7, arg0 - 1);
    var_v1 = temp_v0;
    if (temp_v0 == NULL) {
        var_v1 = &D_8AF29BF8;
    }
    return var_v1;
}

extern void _bzero(void *, s32);
extern s16 *D_8AF2BA90[];
extern u8 D_8AF36F30[];
s16 func_8AF19A1C(s16 arg0) {
    s16 *source;
    s16 count;
    s16 separator;
    s32 value;

    source = D_8AF2BA90[arg0];
    _bzero(D_8AF36F30, 255);
    count = 0;
    separator = 0;
    while (1) {
        value = *source;
        if (value > 0) {
            D_8AF36F30[count++] = value;
            if (count >= 255) {
                break;
            }
            separator = 0;
        } else {
            if (separator == 1) {
                break;
            }
            separator = 1;
        }
        source++;
    }
    return count;
}

extern u8 func_80062F68(u8);
s32 func_8AF19AC4(u8 arg0) {
    u8 value;
    s32 result = 0;

    if (arg0 >= 0xDD) {
        value = func_80062F68(arg0 - 0xC0);
        result = value & 0xFF;
    } else if (arg0 >= 0xC4) {
        value = func_80062F68(arg0 - 0xBF);
        result = value & 0xFF;
    } else if (arg0 >= 0xBF) {
        value = func_80062F68(arg0 - 0xBE);
        result = value & 0xFF;
    }
    return result;
}

extern u8 func_80063014(u8);
s32 func_8AF19B40(u8 arg0) {
    u8 temp_v0;
    s32 result = 0;

    if (arg0 >= 0xC9) {
        temp_v0 = func_80063014(arg0 - 0xC8);
        result = temp_v0 & 0xFF;
    } else if (arg0 >= 0xC4) {
        temp_v0 = func_80063014(arg0 - 0x91);
        result = temp_v0 & 0xFF;
    }
    return result;
}

s32 func_8AF19BA0(s32 arg0) {
    volatile s32 *p = &arg0;
    arg0 &= 0xFF;
    if (arg0 == 0x46 || arg0 == 0x73 || arg0 == 0x74 || arg0 == 0x81) {
        return 1;
    }
    return 0;
}

s32 func_8AF19BDC(u8 arg0) {
    u32 flags = func_8005431C();

    switch (arg0) {
        case 187: if (!(flags & 1)) return 0; break;
        case 189: if (!(flags & 2)) return 0; break;
        case 116: if (!(flags & 4)) return 0; break;
        case 70: if (!(flags & 8)) return 0; break;
        case 115: if (!(flags & 0x10)) return 0; break;
        case 129: if (!(flags & 0x20)) return 0; break;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_207AF0/func_8AF19CB0.s")

extern void func_8AF19CB0(s16, s32);

void func_8AF19E24(s16 arg0) {
    func_8AF19CB0(arg0, 6);
}


void func_8AF19E50(s16 arg0) {
    func_8AF19CB0(arg0, 0xC);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_207AF0/func_8AF19E7C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_207AF0/func_8AF19FAC.s")

extern s16 func_8AF19A1C(s16);
extern u8 *func_8AF19E7C(u8 *, s32, s32, s16);
extern s8 D_8AF29D44;
extern s32 D_8AF2BAAC;
extern s16 D_8AF35050;
extern s8 D_8AF354A8;
extern s32 D_8AF357D0;
extern void _bzero(void *, s32);
extern void *func_8004C874(s32, s32);
void func_8AF1A0DC(s16 arg0) {
    s16 *p = &arg0;
    s32 padding[4];
    s16 sp22;
    s32 sp1C;
    u8 *temp_v0;
    s16 value;

    sp1C = D_8AF2BAAC;
    D_8AF35050 = 2;
    sprintf(&D_8AF354A8, &D_8AF29D44,
            func_8004C874(0x3B, *p + 0xD2));
    sp22 = func_8AF19A1C(6);
    _bzero(&D_8AF357D0, 0x1758);
    value = *p;
    if (value == 1) {
        temp_v0 = func_8AF19E7C(&D_8AF357D0, sp1C, 0x4000, sp22);
        temp_v0[0] = 0xFF;
        temp_v0[0xC] = 0xFF;
        func_8AF19E7C(temp_v0 + 0x18, sp1C, 0x100, sp22);
        return;
    }
    func_8AF19E7C(&D_8AF357D0, sp1C, (0x8000 >> value) & 0xFFFF, sp22);
}

extern u8 *func_8AF19FAC(u8 *, s32, s32, s16);
extern s8 D_8AF29DA0;
extern s32 D_8AF2BAC4;
extern void *func_8004C874(s32, s32);
void func_8AF1A1B8(s16 arg0, s16 arg1) {
    s16 *p0 = &arg0;
    s32 padding[4];
    s16 sp22;
    s32 temp_s0;
    u8 *temp_v0;
    s16 value;

    temp_s0 = D_8AF2BAC4;
    D_8AF35050 = 2;
    sprintf(&D_8AF354A8, &D_8AF29DA0, func_8004C874(0x3B, arg1));
    sp22 = func_8AF19A1C(0xC);
    _bzero(&D_8AF357D0, 0x1758);
    value = *p0;
    switch (value) {
    case 0:
        temp_v0 = func_8AF19FAC(&D_8AF357D0, temp_s0, 0x8000, sp22);
        temp_v0[0] = 0xFF;
        temp_v0[0xC] = 0xFF;
        func_8AF19FAC(temp_v0 + 0x18, temp_s0, 0x200, sp22);
        return;
    case 4:
        func_8AF19FAC(&D_8AF357D0, temp_s0, 0x400, sp22);
        return;
    default:
        func_8AF19FAC(&D_8AF357D0, temp_s0, (0x8000 >> value) & 0xFFFF, sp22);
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_207AF0/func_8AF1A2B8.s")

extern void _bzero(void *, s32);
extern s16 D_8AF357AC;
extern s16 D_8AF357AE;
extern u8 D_8AF357C0;

void func_8AF1A72C(void) {
    D_8AF357AC = 0;
    D_8AF357AE = 0;
    _bzero(&D_8AF357C0, 0xE);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_207AF0/func_8AF1A764.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_207AF0/func_8AF1AE30.s")

/* mkdraft:func_8AF1B23C begin */
extern void func_800495BC(s32, s32, s32 *);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_8004B314(s16, s16, s32, s32);
extern void func_8AC00738(void);
extern void func_8AC0077C(s16, s16, s16, s16);
extern void func_8AC05F00(void *);
extern s32 func_8AC0665C(u8 *, s16);
extern s32 func_8AC0672C(u8 *, s16);
extern u8 *D_8AF35180;
extern u8 D_8AF35058;
extern u8 D_8AF350D0;
extern s16 D_8AF357A8;
extern s16 D_8AF357AA;
extern s16 D_8AF357AC;
extern s16 D_8AF357AE;
extern s16 D_8AF357C2;
extern s16 D_8AF357C4;
extern u8 D_8AF357C0;
extern s32 D_8AF357D0;
extern s16 D_8AF36F28;
extern s16 D_8AF370F0;
extern s16 D_8AF370F2;

// Lays the D_8AF357D0 cell table out over the D_8AF35180 rectangle: one
// func_800495BC call per 12-byte cell, 4 columns per row and sp42 rows, after
// clipping to (x-3, y, x+w, y+h) and setting the 0xFF fill. Then runs the
// func_8AC0665C / func_8AC0672C-gated overlay updates and, when D_8AF357C4 is
// clear, moves the 130x36 area at D_8AF370F0/D_8AF370F2.


void func_8AF1B23C(void) {
    // FAKE: nothing else occupies these 24 bytes; removing the array shrinks the
    // frame to 0x48 and changes only the two addiu sp lines (score 10).
    s32 pad[6];
    // FAKE: reading D_8AF357C2 directly hoists lui %hi(D_8AF357C2) out of the
    // loop and puts sp42 at 0x46(sp); through this pointer the address is
    // rebuilt once per iteration (score 2659 without it).
    s16 *D_8AF357C2_ptr = &D_8AF357C2;
    s16 sp42;
    s16 left, right, bottom;
    // FAKE: the tail load needs its own lui %hi / lh %lo of D_8AF357C0; through
    // the base register the two query calls below carry, IDO reloads 0(base)
    // instead (score 310 without this pointer). The loop read keeps the symbol
    // spelling.
    u8 *D_8AF357C0_ptr = &D_8AF357C0;
    s32 var_s2;
    u8 *var_s1;
    s32 var_s0;
    u8 temp_v1_2;

    sp42 = ((s32)(D_8AF36F28 - 1) / 4) + 1;
    left = *(s16 *)(D_8AF35180 + 8) - 3;
    right = *(s16 *)(D_8AF35180 + 12) + *(s16 *)(D_8AF35180 + 8);
    bottom = *(s16 *)(D_8AF35180 + 14) + *(s16 *)(D_8AF35180 + 10);
    func_8AC0077C(left, *(s16 *)(D_8AF35180 + 10), right, bottom);
    func_800498C4();
    func_800496A4(4, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    var_s1 = (u8 *)&D_8AF357D0;
    for (var_s2 = 0; var_s2 < sp42; var_s2++) {
        for (var_s0 = 0; var_s0 != 4; var_s0++, var_s1 += 12) {
            temp_v1_2 = var_s1[0];
            if (temp_v1_2 == 0) {
                var_s2 = sp42;
                break;
            }
            if ((temp_v1_2 != 0xFFU) && ((*D_8AF357C2_ptr - 2) < var_s2) && (var_s2 < (*D_8AF357C2_ptr + 11))) {
                func_800495BC(*(s16 *)(D_8AF35180 + 8) + (var_s0 * 130) + 6, ((*(s16 *)(D_8AF35180 + 10) + (var_s2 * 20)) - *(s16 *)&D_8AF357C0) + 4, *(s32 *)(var_s1 + 4));
            }
        }
    }
    func_800499EC();
    func_8AC00738();
    if (func_8AC0665C(D_8AF357C0_ptr, D_8AF357AE) != 0) {
        func_8AC05F00(&D_8AF35058);
    }
    if (func_8AC0672C(D_8AF357C0_ptr, D_8AF357AE) != 0) {
        func_8AC05F00(&D_8AF350D0);
    }
    if (D_8AF357C4 == 0) {
        D_8AF370F0 = (D_8AF357A8 + (D_8AF357AC * 130)) - 4;
        D_8AF370F2 = ((D_8AF357AA + (D_8AF357AE * 20)) - *(s16 *)D_8AF357C0_ptr) - 6;
    }
    func_8004B314(D_8AF370F0, D_8AF370F2, 130, 36);
}
/* mkdraft:func_8AF1B23C end */

void func_8AF1B4D0(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x28) = arg1;
    *(s32 *)(arg0 + 0x2C) = arg2;
}

extern u8 *D_8AF371F4;
extern u8 *D_8AF371F8;
extern u8 *D_8AF37204;
extern u8 *D_8AF37208;
extern s16 D_8AF3720C;
extern void func_8AF1B4D0(u8 *, s32, s32);
void func_8AF1B4DC(void) {
    *(u16 *)(D_8AF371F4 + 2) &= 0xFFFE;
    *(u16 *)(D_8AF371F8 + 2) &= 0xFFFE;
    func_8AF1B4D0(D_8AF37204, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF1B4D0(D_8AF37208, 0xC3A05AFF, 0xE1C38CFF);
    switch (D_8AF3720C) {
    case 0:
        *(u16 *)(D_8AF371F4 + 2) |= 1;
        func_8AF1B4D0(D_8AF37204, 0xFFFF00FF, 0xFFFF00FF);
        break;
    case 1:
        *(u16 *)(D_8AF371F8 + 2) |= 1;
        func_8AF1B4D0(D_8AF37208, 0xFFFF00FF, 0xFFFF00FF);
        break;
    }
}

extern s16 D_8AF3720C;
void func_8AF1B5D4(void) {
    D_8AF3720C = 0;
}

/* mkdraft:func_8AF1B5E0 begin */
extern void *func_8AF00504(s16);
extern s32 func_8AF003A8(s16);
extern void func_8AC06E98(void *);
extern void func_8AC05E40(s32, s32, s32);
extern s32 func_8AC06D8C(s32, s32);
extern void func_8004E308(s32, s32 *, s32 *);
extern void func_8AC02C80(s32, s32, s32, void *);
extern s32 func_8AF013D8(s32, void *);
extern u8 *D_8AF371F4;
extern u8 *D_8AF371F8;
extern u8 *D_8AF371FC;
extern u8 *D_8AF37200;
extern u8 *D_8AF37204;
extern u8 *D_8AF37208;
extern u8 *D_8AF3723C;
extern u8 D_8AF37100[];
extern u8 D_8AF37178[];
extern u8 D_8AF37210[];

void func_8AF1B5E0(void) {
    s32 page;

    func_8AF00504(0x7A);
    func_8AF00504(0x35);
    page = func_8AF003A8(0x7A);
    func_8AC06E98((void *)page);
    D_8AF371F4 = (u8 *)func_8AC06D8C(page, 0x79756231);
    D_8AF371F8 = (u8 *)func_8AC06D8C(page, 0x79756232);
    func_8004E308((s32)D_8AF371F4, (s32 *)func_8AF013D8, NULL);
    func_8004E308((s32)D_8AF371F8, (s32 *)func_8AF013D8, NULL);
    D_8AF37204 = (u8 *)func_8AC06D8C(page, 0x6D5F3230);
    D_8AF37208 = (u8 *)func_8AC06D8C(page, 0x635F3230);
    func_8AC05E40(page, 0x736F7531, (s32)D_8AF37100);
    func_8AC05E40(page, 0x736F7532, (s32)D_8AF37178);
    D_8AF371FC = (u8 *)func_8AC06D8C(page, 0x736F7531);
    D_8AF37200 = (u8 *)func_8AC06D8C(page, 0x736F7532);
    page = func_8AF003A8(0x35);
    func_8AC02C80(page, 0x74697431, 0x74697432, D_8AF37210);
    D_8AF3723C = (u8 *)func_8AC06D8C(page, 0x7469746C);
    *(s16 *)(D_8AF3723C + 0x30) = 0x36;
    *(s16 *)(D_8AF3723C + 0x32) = 0x10;
}
/* mkdraft:func_8AF1B5E0 end */

/* mkdraft:func_8AF1B770 begin */
extern void *D_8AF263C0;
extern f32 D_8AF29DF0;
extern u8 *D_8AF371F0;
extern s16 D_8AF3720C;
extern u8 D_8AF37100[];
extern u8 D_8AF37178[];
extern u8 *D_8AF371FC;
extern u8 *D_8AF37200;
extern s32 func_8AC06400(u8 *, u8 *);
extern void func_8AF00130(s32);
extern void func_8AF1BB84(s32);
extern void func_8AF1B4DC(void);



s16 func_8AF1B770(void) {
    s16 sp1E;
    u16 temp_v0;
    f32 scale;

    sp1E = 0x15;
    temp_v0 = *(u16 *)((u8 *)D_8AF263C0 + 8);
    if (temp_v0 & 0x8000) {
        func_8AF00130(0xC0);
        sp1E = 0x16;
        switch (D_8AF3720C) {
        case 0:
            func_8AF1BB84(0x46);
            break;
        case 1:
            func_8AF1BB84(0x27);
            break;
        }
    } else if (temp_v0 & 0x4000) {
        func_8AF00130(3);
        sp1E = 7;
    } else if (temp_v0 & 0x200) {
        if (D_8AF3720C != 0) {
            func_8AF00130(1);
        }
        D_8AF3720C = 0;
    } else if (temp_v0 & 0x100) {
        if (D_8AF3720C != 1) {
            func_8AF00130(1);
        }
        D_8AF3720C = 1;
    }
    func_8AF1B4DC();
    func_8AC06400(D_8AF37100, D_8AF371FC);
    func_8AC06400(D_8AF37178, D_8AF37200);
    switch (D_8AF3720C) {
    case 0:
        D_8AF371F0 = D_8AF37100;
        break;
    case 1:
        D_8AF371F0 = D_8AF37178;
        break;
    default:
        D_8AF371F0 = D_8AF37100;
        break;
    }
    scale = D_8AF29DF0;
    *(f32 *)(D_8AF371F0 + 0x40) = scale;
    *(f32 *)(D_8AF371F0 + 0x44) = scale;
    return sp1E;
}
/* mkdraft:func_8AF1B770 end */

extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800499EC(void);
void func_8AF1B910(void) {
    func_800498C4();
    func_800496A4(0x10, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800499EC();
}
#endif
