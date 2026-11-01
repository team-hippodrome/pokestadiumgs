#include "global.h"

// The three command lists D_813120E0's records point at.
const s16 D_81312880[4] = { 96, 2, -1, 0 };
const s16 D_81312888[4] = { 57, 2, -1, 0 };
const s16 D_81312890[4] = { 58, 2, -1, 0 };

const s16 D_81312898[70] = {
    104, 193, -1, -1, 134, 265, -1, 1, 4, -1,
    228, 193, -1, -1, 258, 265, -1, 2, 5, 0,
    352, 193, -1, -1, 382, 265, -1, 3, 5, 1,
    476, 193, -1, -1, 506, 265, -1, -1, 6, 2,
    126, 322, 9, 53, 164, 385, 0, 5, -1, -1,
    276, 322, 9, 54, 314, 385, 1, 6, -1, 4,
    423, 320, 8, 55, 471, 385, 2, -1, -1, 5,
};

// Four s16[4] color sets func_8130F6A4 picks from (+0, +8, +0x10, +0x18).
const s16 D_81312924[16] = {
    85, 91, 473, 61, -473, 91, 473, 61, 640, 91, 473, 61, 85, 91, 473, 143,
};

// The empty name func_8130FA0C copies into a cleared slot; retail copies it as a one-byte
// record (address formed, then lbu/sb), not as a folded character load.
typedef struct unk_D_81312944 {
    /* 0x0 */ char unk_0;
} unk_D_81312944;
const unk_D_81312944 D_81312944 = { 0 };

const f32 D_81312948[4] = { -1.5707964f, 0.0f, 1.5707964f, 3.1415927f };

extern u8 D_1000000[];

// The three menu descriptors func_81310800 passes to func_81311C70; each ends with one of the
// command lists above.
typedef struct unk_D_813120E0 {
    /* 0x00 */ void *unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 unk_10[8];
    /* 0x18 */ s16 unk_18[4];
    /* 0x20 */ const s16 *unk_20;
} unk_D_813120E0; // size = 0x24

unk_D_813120E0 D_813120E0 = {
    D_1000000, 0, 320, 240, 0, { 0x10, 0x13, 0x10, 0x13, 0x10, 0x18, 0x20, 0xFF }, { -1, 2, 1, 15 }, D_81312880,
};
unk_D_813120E0 D_81312104 = {
    D_1000000, 0, 320, 240, 0, { 0x10, 0x13, 0x10, 0x13, 0x10, 0x18, 0x20, 0xFF }, { -1, 2, 1, 15 }, D_81312888,
};
unk_D_813120E0 D_81312128 = {
    D_1000000, 0, 320, 240, 0, { 0x10, 0x13, 0x10, 0x13, 0x10, 0x18, 0x20, 0xFF }, { -1, 2, 1, 15 }, D_81312890,
};



#ifdef VERSION_US
/* mkdraft:func_8130F630 begin */
s32 func_8130F630(u8 *arg0) {
    return (*(s32 *)(arg0 + 0x44) == 0 && arg0[0x38] == 1) ||
           (*(s32 *)(arg0 + 0x48) != -1 && *(s32 *)(arg0 + 0x48) != 4 && *(s32 *)(arg0 + 0x48) != 5 && arg0[0x38] >= 4);
}
/* mkdraft:func_8130F630 end */
#endif

void func_8130F69C(void) {
}

#ifdef VERSION_US
/* mkdraft:func_8130F6A4 begin */
extern f32 (*D_8160BD08)(f32);
extern f32 (*D_8160BD1C)(f32);
extern void func_8160945C(s16 *, s16 *, s16 *, f32);


f32 func_8130F6A4(u8 *arg0, s16 *arg1, u8 *arg2) {
    u8 *ptr = arg2 + 8;
    f32 temp = 0.0f;

    if (func_8130F630(arg0) != 0) {
        ptr = arg2 + 0x18;
        if (*(f32 *)(arg0 + 0x30) >= 9.0f) {
            temp = D_8160BD1C((*(f32 *)(arg0 + 0x30) - 9.0f) / 7.0f);
        }
    } else {
        temp = D_8160BD08(*(f32 *)(arg0 + 0x30) / 16);
        if (arg0[0x38] == 4) {
            ptr = arg2 + 0x10;
        }
    }
    func_8160945C(arg1, ptr, arg2, temp);
    return temp;
}
/* mkdraft:func_8130F6A4 end */
#endif

#ifdef VERSION_US
extern f32 func_8130F6A4(u8 *arg0, s16 *arg1, u8 *arg2);
f32 func_8130F794(u8 *arg0, s16 *arg1) {
    return func_8130F6A4(arg0, arg1, (u8 *)D_81312924);
}
#endif

#ifdef VERSION_US
extern f32 (*D_8160BD04)(f32);
extern s16 *func_81609530(s32);
extern void func_8160945C(s16 *, s16 *, s16 *, f32);
f32 func_8130F7B8(u8 *arg0, s16 *arg1) {
    f32 scale = D_8160BD04(*(f32 *)(arg0 + 0x30) / 16);
    s16 *color = (s16 *)(arg0 + 0x20);

    if (arg0[0x38] == 4 || arg0[0x38] == 5) {
        switch (*(s32 *)(arg0 + 0x48)) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 6:
                color = func_81609530(3);
                break;
            case 4:
                color = func_81609530(1);
                break;
            case 5:
                color = func_81609530(2);
                break;
            case -1:
                if (*(s32 *)(arg0 + 0x3C) != 0) {
                    color = func_81609530(2);
                } else {
                    color = (s16 *)(arg0 + 0x28);
                }
                break;
        }
    }
    func_8160945C(arg1, color, func_81609530(0), scale);
    return scale;
}
#endif

#ifdef VERSION_US
extern f32 func_8130F7B8(u8 *arg0, s16 *arg1);
extern void func_81609A90(s16 *arg0, s16 *arg1);
void func_8130F8B4(u8 *arg0, s32 arg1) {
    s16 sp40[4];
    s16 sp38[4];
    s16 sp30[4];
    s16 sp28[4];
    f32 sp24;
    sp24 = *(f32 *)(arg0 + 0x30);
    *(f32 *)(arg0 + 0x30) = 0.0f;
    func_8130F794(arg0, sp40);
    func_8130F7B8(arg0, sp30);
    *(f32 *)(arg0 + 0x30) = 16.0f;
    func_8130F794(arg0, sp40);
    func_8130F7B8(arg0, sp28);
    if (arg1 != 0) {
        func_81609A90(sp40, sp38);
        func_81609A90(sp30, sp28);
    } else {
        func_81609A90(sp38, sp40);
        func_81609A90(sp28, sp30);
    }
    *(f32 *)(arg0 + 0x30) = sp24;
}
#endif

#ifdef VERSION_US
extern s32 func_8130F970(void *arg0, s32 arg1);
s32 func_8130F970(void *arg0, s32 arg1) {
    if ((arg1 < 4) && (((u8 *)arg0 + arg1)[0x8C] == 2)) {
        return 0;
    }
    if ((*(s32 *)((u8 *)arg0 + 0x40) == 0) && (arg1 >= 4) && (arg1 < 6)) {
        return 0;
    }
    if ((*(s32 *)((u8 *)arg0 + 0x3C) != 0) && (arg1 >= 4) && (arg1 < 6)) {
        return 0;
    }
    if ((arg1 == 6) && (*(s32 *)((u8 *)arg0 + 0xAC) == 0)) {
        return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern s32 func_81603404(s32, u8);
extern s32 func_81603368(s32);
extern void func_8005D9E0(s32, void *);
void func_8130FA0C(u8 *arg0) {
    u8 status;
    s32 i;
    struct {
        u16 id;
        char name[12];
    } entry;

    for (i = 0; i < 4; i++) {
        status = func_81603404(i, 4);
        arg0[0x8C + i] = status;
        switch (status) {
            case 0:
                func_8005D9E0(i, &entry);
                HAL_Strcpy(arg0 + 0x54 + i * 12, entry.name);
                *(u16 *)(arg0 + 0x84 + i * 2) = entry.id;
            case 6:
                *(s32 *)(arg0 + 0x90 + i * 4) = func_81603368(i);
                break;
            case 2:
            case 3:
                *(unk_D_81312944 *)(arg0 + 0x54 + i * 12) = D_81312944;
                *(u16 *)(arg0 + 0x84 + i * 2) = 0xFFFF;
                *(s32 *)(arg0 + 0x90 + i * 4) = 7;
                break;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8130F970(void *arg0, s32 arg1);
void func_8130FB58(u8 *arg0) {
    s32 i;
    *(s32 *)(arg0 + 0xA8) = 0;
    for (i = 0; i != 7; i++) {
        if (func_8130F970(arg0, i) != 0) {
            *(s32 *)(arg0 + 0xA8) = 1;
        }
    }
}
#endif

#ifdef VERSION_US
void func_8130FBC0(void *arg0) {
    s32 temp_a1;
    s32 i;
    u8 *ptr;
    if ((*(s32 *)((u8 *)arg0 + 0xA8) != 0) &&
        ((temp_a1 = *(s32 *)((u8 *)arg0 + 0x48), temp_a1 < 0) ||
         (temp_a1 >= 7) ||
         (func_8130F970(arg0, temp_a1) == 0))) {
        *(s32 *)((u8 *)arg0 + 0x48) = 0;
        i = 0;
        ptr = (u8 *)arg0;
        while (i < 4) {
            if (ptr[0x8C] == 0) {
                *(s32 *)((u8 *)arg0 + 0x48) = i;
                return;
            }
            i++;
            ptr++;
        }
        i = 0;
        while (i != 7) {
            if (func_8130F970(arg0, i) != 0) {
                *(s32 *)((u8 *)arg0 + 0x48) = i;
                return;
            }
            i++;
        }
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8130FC80 begin */
extern void func_8130FA0C(u8 *);
extern s32 func_81311CFC(void);

void func_8130FC80(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_81311CFC();
    *(s8 *)(arg0 + 0x38) = 0;
    *(s8 *)(arg0 + 0x39) = 0;
    *(f32 *)(arg0 + 0x30) = 0.0f;
    *(s32 *)(arg0 + 0x4C) = arg3;
    *(s32 *)(arg0 + 0x50) = arg4;
    *(s32 *)(arg0 + 0x3C) = 0;
    *(s32 *)(arg0 + 0xA0) = 0;
    *(f32 *)(arg0 + 0x34) = 0.0f;
    *(s32 *)(arg0 + 0x40) = arg1;
    *(s32 *)(arg0 + 0xA8) = 1;
    *(s32 *)(arg0 + 0xAC) = arg2;
    func_8130FA0C(arg0);
    func_8130FB58(arg0);
    func_8130FBC0(arg0);
}
/* mkdraft:func_8130FC80 end */
#endif

#ifdef VERSION_US
// The two 8-byte records func_8130FD10 copies into its object at 0x20 and 0x28.
typedef struct unk_D_8130FD10 {
    /* 0x0 */ s16 unk_0[4];
} unk_D_8130FD10; // size = 0x8
extern void func_800226C0(s32);
extern void func_8130F8B4(u8 *arg0, s32 arg1);
void func_8130FD10(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, unk_D_8130FD10 *arg6,
                   unk_D_8130FD10 *arg7, s32 arg8, s32 arg9) {
    *(unk_D_8130FD10 *)(arg0 + 0x20) = *arg6;
    *(unk_D_8130FD10 *)(arg0 + 0x28) = *arg7;
    arg0[0x39] = arg1;
    arg0[0xA4] = arg3;
    arg0[0xA5] = arg4;
    *(s32 *)(arg0 + 0x44) = arg5;
    *(s32 *)(arg0 + 0x3C) = arg8;
    *(s32 *)(arg0 + 0xA0) = arg9;
    func_8130FA0C(arg0);
    func_8130FB58(arg0);
    *(s32 *)(arg0 + 0x48) = arg2;
    func_8130FBC0(arg0);
    if (arg5 != 0) {
        func_800226C0(0xA5);
    }
    switch (arg0[0x38]) {
        case 0:
            *(f32 *)(arg0 + 0x30) = 0.0f;
        case 1:
        case 4:
            arg0[0x38] = 1;
            break;
        case 3:
            break;
    }
    func_8130F8B4(arg0, 1);
}
#endif

#ifdef VERSION_US
extern void func_8130F8B4(u8 *arg0, s32 arg1);
void func_8130FE28(u8 *arg0) {
    switch (arg0[0x38]) {
    case 0:
        *(f32 *)(arg0 + 0x30) = 0.0f;
    case 1:
    case 3:
    case 4:
        arg0[0x38] = 4;
        break;
    }
    func_8130F8B4(arg0, 0);
}
#endif

#ifdef VERSION_US
s32 func_8130FE8C(u8 *arg0) {
    *(f32 *)(arg0 + 0x30) = 0.0f;
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_8130FE9C(u8 *arg0) {
    arg0[0x3A]++;
    *(f32 *)(arg0 + 0x30) = 0.0f;
    return 1;
}
#endif

void func_8130FEB8(void) {
}

#ifdef VERSION_US
extern f32 func_816092FC(void);
extern void func_8130FEC0(u8 *arg0, f32 arg1);
extern f32 func_8130FF70(f32 arg0);
void func_8130FEC0(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x30) += arg1;
    if (*(f32 *)(arg0 + 0x30) >= 16.0f) {
        *(f32 *)(arg0 + 0x30) = 16.0f;
        return;
    }
    if (*(f32 *)(arg0 + 0x30) <= 0.0f) {
        *(f32 *)(arg0 + 0x30) = 0.0f;
    }
}
#endif

#ifdef VERSION_US
s32 func_8130FF18(u8 *arg0) {
    func_8130FEC0(arg0, func_816092FC());
    if (*(f32 *)(arg0 + 0x30) >= 16.0f) {
        arg0[0x38] = 3;
    }
    return 1;
}
#endif

#ifdef VERSION_US
f32 func_8130FF70(f32 arg0) {
    while (3.1415927f < arg0) {
        arg0 -= 6.2831855f;
    }
    while (arg0 <= -3.1415927f) {
        arg0 += 6.2831855f;
    }
    return arg0;
}
#endif

#ifdef VERSION_US
void func_8130FFE0(f32 arg0, f32 arg1) {
    f32 temp[2];
    temp[0] = func_8130FF70(arg1);
    func_8130FF70(temp[0] - func_8130FF70(arg0));
}
#endif

#ifdef VERSION_US
/* mkdraft:MathUtil_Atan2d_fragment14 begin */
f64 MathUtil_Atan2d_fragment14(f64 arg0, f64 arg1) {
    f64 ratio;
    f64 reduced;
    f64 fraction;
    s32 i;

    if ((arg1 == 0.0) && (arg0 == 0.0)) {
        return 0.0;
    }
    if (arg1 == 0.0) {
        if (arg0 > 0.0) {
            return 1.5707963705062866;
        }
        return -1.5707963705062866;
    }
    ratio = arg0 / arg1;
    reduced = ((ratio > 0.0 ? ratio : -ratio) <= 1.0) ? ratio : 1.0 / ratio;
    fraction = 0.0;
    for (i = 14; i > 0; i--) {
        fraction = (i * i) * reduced * reduced / ((2 * i + 1) + fraction);
    }
    reduced = reduced / (1.0 + fraction);
    if (ratio > 1.0) {
        reduced = 1.5707963705062866 - reduced;
    }
    if (ratio < -1.0) {
        reduced = -1.5707963705062866 - reduced;
    }
    if (arg1 > 0.0) {
        return reduced;
    }
    if (arg0 > 0.0) {
        return reduced + 3.1415927410125732;
    }
    return reduced - 3.1415927410125732;
}
/* mkdraft:MathUtil_Atan2d_fragment14 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_813102A4.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_8131058C begin */
extern u8 D_800CE060[];
extern s32 func_813102A4(u8 *, s32, s32);



s32 func_8131058C(u8 *arg0) {
    u8 *entry;
    s32 old;
    s32 index;
    s32 direction;

    // D_800CE060 holds four 0x28-byte ControllerState records; +0x8 is buttonsPressed and
    // +0xC is buttonsRepeat.
    //@include/controller.h
    entry = D_800CE060 + arg0[0x39] * 0x28;
    *(f32 *)(arg0 + 0x30) = 16.0f;
    if (*(s32 *)(arg0 + 0xA8) == 0) {
        func_800226C0(5);
        arg0[0x38] = 2;
        *(s32 *)(arg0 + 0x48) = -1;
        return 1;
    }
    index = *(s32 *)(arg0 + 0x48);
    if (index >= 0) {
        old = index;
        direction = -1;
        // buttonsRepeat D-pad bits; the direction value selects one of the four s16 neighbours
        // at D_81312898 + index * 0x14 + direction * 2 + 0xC inside func_813102A4.
        if (*(u16 *)(entry + 0xC) & 0x800) {
            direction = 0;
        } else if (*(u16 *)(entry + 0xC) & 0x100) {
            direction = 1;
        } else if (*(u16 *)(entry + 0xC) & 0x400) {
            direction = 2;
        } else if (*(u16 *)(entry + 0xC) & 0x200) {
            direction = 3;
        }
        if (direction >= 0) {
            // func_813102A4 returns the index reached from `index` along `direction` in
            // D_81312898, following the neighbour entries while func_8130F970 returns 0.
            index = func_813102A4(arg0, index, direction);
            *(s32 *)(arg0 + 0x48) = index;
        }
        if (old != index) {
            func_800226C0(1);
        }
    } else {
        *(s32 *)(arg0 + 0x48) = 0;
        func_8130FBC0(arg0);
    }
    if (*(u16 *)(entry + 8) & 0x8000) {
        index = *(s32 *)(arg0 + 0x48);
        if (index < 4) {
            // Written base first: `arg0[index + 0x8C]` makes IDO emit `addu $t9,$a1,$a3`.
            switch (*(u8 *)(arg0 + 0x8C + index)) {
            case 0:
                func_800226C0(0x8F);
                arg0[0x38] = 4;
                func_8130F8B4(arg0, 0);
                break;
            case 3:
            case 6:
                arg0[0x38] = 2;
                break;
            }
        } else {
            func_800226C0(0x8F);
            arg0[0x38] = 4;
            func_8130F8B4(arg0, 0);
        }
    } else if (*(u16 *)(entry + 0xC) & 0x4000) {
        arg0[0x38] = 4;
        func_8130F8B4(arg0, 0);
        *(s32 *)(arg0 + 0x48) = -1;
        func_800226C0(3);
    }
    return 1;
}
/* mkdraft:func_8131058C end */
#endif

#ifdef VERSION_US
s32 func_813107A0(u8 *arg0) {
    func_8130FEC0(arg0, -func_816092FC());
    if (*(f32 *)(arg0 + 0x30) <= 0.0f) {
        arg0[0x38] = 5;
        arg0[0x3A] = 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
typedef struct unk_func_81310800 {
    /* 0x00 */ u8 unk_00[0x38];
    /* 0x38 */ u8 unk_38; // phase byte (see func_8131109C)
    /* 0x39 */ u8 unk_39; // passed to func_81311C70 as its third argument
    /* 0x3A */ u8 unk_3A[0x48 - 0x3A];
    /* 0x48 */ s32 unk_48; // entry index (see func_8131109C)
    /* 0x4C */ u8 unk_4C[0x8C - 0x4C];
    /* 0x8C */ u8 unk_8C[6]; // per-entry byte indexed by unk_48; func_8130F970 tests it against 2
    /* 0x92 */ u8 unk_92[0xA8 - 0x92];
    /* 0xA8 */ s32 unk_A8; // any-selectable flag (set by func_8130FB58)
} unk_func_81310800;

extern s32 func_81311C70(void *arg0, void *arg1, s32 arg2, s32 arg3);

// Calls func_81311C70 with table D_813120E0, or, when the any-selectable flag is set, D_81312128
// if unk_8C[unk_48] is 6 and D_81312104 otherwise. On a nonzero result, sets the
// phase byte to 3 (flag set) or 4 (flag clear).
// func_81310894 uses the result, but there is no return statement: it returns func_81311C70's
// value left in $v0.
s32 func_81310800(unk_func_81310800 *arg0) {
    if (func_81311C70(arg0,
                      (arg0->unk_A8 != 0) ? ((arg0->unk_8C[arg0->unk_48] == 6) ? &D_81312128 : &D_81312104)
                                          : &D_813120E0,
                      arg0->unk_39, -1)) {
        arg0->unk_38 = (arg0->unk_A8 != 0) ? 3 : 4;
    }
    //!bug: no return statement
}
#endif

#ifdef VERSION_US
extern s32 func_8131058C(u8 *);
extern s32 *func_81602D70(s32);
extern s32 func_81602AEC(u8 *, u8 *);
extern void func_81600A34(void *, void *, s32, s32, s32, s32, s32);
extern void func_81311AAC(u8 *, void *);
extern void func_81600F0C(void *, s16, s16, s16, s16);
extern void func_81604944(s32, s32, s32, s32, u8 *, u8 *);
extern void func_81605D24(s32, s32, s32, s32, u8 *);
extern void func_8160615C(s32, s32, s32, f32);
extern void func_81605F94(s32, s32, s32, u8 *, f32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void *func_8004C874(s32, s32);
extern void func_800499EC(void);
void func_81310894(u8 *arg0, void *arg1) {
    s32 result = 0;
    u8 unusedColor[3] = { 0xFF, 0xFF, 0xFF }; // unused: retail copies the template and never reads it
    s16 rect[4];
    s16 unusedRect[4]; // unused: retail reserves its slot

    func_8130FA0C(arg0);
    func_8130FB58(arg0);
    switch (arg0[0x38]) {
        case 0:
            result = func_8130FE8C(arg0);
            break;
        case 1:
            result = func_8130FF18(arg0);
            break;
        case 3:
            result = func_8131058C(arg0);
            break;
        case 4:
            result = func_813107A0(arg0);
            break;
        case 5:
            result = func_8130FE9C(arg0);
            break;
        case 2:
            result = func_81310800((unk_func_81310800 *)arg0);
            break;
    }
    if (func_81602AEC(*(u8 **)(arg0 + 0x4C), (u8 *)func_81602D70(*(s8 *)(arg0 + 0xA5)))) {
        result = 1;
    }
    if (arg0[0x38] != 0) {
        func_8130F794(arg0, rect);
        func_81600A34(arg1, arg0 + 1, result, rect[0], rect[1], rect[2], rect[3]);
        func_8130F7B8(arg0, rect);
        func_81600A34(arg1, arg0 + 2, 1, rect[0], rect[1], rect[2], rect[3]);
    }
    func_81311AAC(arg0, arg1);
}

#endif

#ifdef VERSION_US
void func_81310A14(u8 *arg0) {
    static u8 D_81312150[3] = { 0x00, 0x00, 0x00 };
    static u8 D_81312154[3] = { 0xFF, 0xFF, 0xFF };
    static u8 D_81312158[3] = { 0xFF, 0xBE, 0xDC };
    static u8 D_8131215C[4][3] = {
        { 0x8C, 0x8C, 0xFF }, { 0x3C, 0xD2, 0x5A }, { 0xFF, 0x64, 0x46 }, { 0xFF, 0xF0, 0x00 },
    };
    static u8 D_81312168[3] = { 0xFF, 0xA0, 0xFF };
    s16 rect[4];
    f32 scale;

    scale = func_8130F794(arg0, rect);
    func_81600F0C(*(void **)(arg0 + 0x50), rect[0], rect[1] - 17, rect[2], 17);
    if (*(s32 *)(arg0 + 0x3C) != 0) {
        func_81604944(rect[0], rect[1], rect[2], rect[3], D_81312158, D_81312150);
        func_81605D24(rect[0] - 6, rect[1] - 9, 289, 40, D_81312168);
        func_8160615C(rect[0], rect[1], *(s32 *)(arg0 + 0xA0) + 1, 1.0f);
    } else {
        func_81604944(rect[0], rect[1], rect[2], rect[3], *(u8 **)(arg0 + 0x4C), D_81312150);
        func_81605D24(rect[0] - 6, rect[1] - 9, 289, 40, D_8131215C[*(s8 *)(arg0 + 0xA5)]);
        func_81605F94(rect[0] - 1, rect[1] - 18, *(s8 *)(arg0 + 0xA4), D_81312154, 1.0f);
    }
    func_800498C4();
    func_800496A4(16, 1);
    func_8004972C(255, 255, 255, 255.0f * scale);
    func_800495F8(rect[0] + 235, rect[1] + 17, 1, func_8004C874(15, *(s32 *)(arg0 + 0x3C) ? 52 : 51));
    func_800499EC();
}

#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_81310BF8.s")
#endif

#ifdef VERSION_US
extern s32 func_81600DA8(void *arg0, void *arg1);
extern void func_81310A14(u8 *arg0);
extern void func_81310BF8(s32 arg0);
extern void func_81311650(s32 arg0, s32 arg1);
void func_81311030(s32 arg0, s32 arg1) {
    if (func_81600DA8((void *)arg1, (void *)(arg0 + 1)) != 0) {
        func_81310A14((u8 *)arg0);
    }
    if (func_81600DA8((void *)arg1, (void *)(arg0 + 2)) != 0) {
        func_81310BF8(arg0);
    }
    func_81311650(arg0, arg1);
}
#endif

#ifdef VERSION_US
// Returns -2 unless the phase byte at +0x38 is 5 (set by func_813107A0 once the
// value at +0x30 falls to 0) and the counter at +0x3A (incremented by func_8130FE9C)
// is at least 3. Otherwise returns the entry index at +0x48 when the any-selectable
// flag at +0xA8 (set by func_8130FB58) is nonzero, or -1.
s32 func_8131109C(u8 *arg0) {
    s32 result;
    s32 result_copy; // FAKE: copy of result restored in the else branch; diff score 1210 without it.

    result = -1;
    if (arg0[0x38] == 5 && arg0[0x3A] >= 3) {
        result_copy = result;
        if (*(s32 *)(arg0 + 0xA8) != 0) {
            result = *(s32 *)(arg0 + 0x48);
        } else {
            result = result_copy;
        }
    } else {
        result = -2;
    }
    return result;
}
#endif
