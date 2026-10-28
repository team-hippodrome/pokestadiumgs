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


f32 func_8130F6A4(u8 *arg0, u8 *arg1, u8 *arg2) {
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
extern f32 func_8130F6A4(u8 *arg0, u8 *arg1, u8 *arg2);
f32 func_8130F794(u8 *arg0, u8 *arg1) {
    return func_8130F6A4(arg0, arg1, (u8 *)D_81312924);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_8130F7B8.s")
#endif

#ifdef VERSION_US
extern void func_8130F7B8(u8 *arg0, u8 *arg1);
extern void func_81609A90(u8 *arg0, u8 *arg1);
void func_8130F8B4(u8 *arg0, s32 arg1) {
    u8 sp40[8];
    u8 sp38[8];
    u8 sp30[8];
    u8 sp28[8];
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_8130FD10.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_8131058C.s")
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
extern u8 D_813120E0[];
extern u8 D_81312104[];
extern u8 D_81312128[];

// Calls func_81311C70 with table D_813120E0, or, when the any-selectable flag is set, D_81312128
// if unk_8C[unk_48] is 6 and D_81312104 otherwise. On a nonzero result, sets the
// phase byte to 3 (flag set) or 4 (flag clear).
void func_81310800(unk_func_81310800 *arg0) {
    if (func_81311C70(arg0,
                      (arg0->unk_A8 != 0) ? ((arg0->unk_8C[arg0->unk_48] == 6) ? D_81312128 : D_81312104)
                                          : D_813120E0,
                      arg0->unk_39, -1)) {
        arg0->unk_38 = (arg0->unk_A8 != 0) ? 3 : 4;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_81310894.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_81310A14.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1077C0/func_81310BF8.s")
#endif

#ifdef VERSION_US
extern s32 func_81600DA8(void *arg0, void *arg1);
extern void func_81310A14(s32 arg0);
extern void func_81310BF8(s32 arg0);
extern void func_81311650(s32 arg0, s32 arg1);
void func_81311030(s32 arg0, s32 arg1) {
    if (func_81600DA8((void *)arg1, (void *)(arg0 + 1)) != 0) {
        func_81310A14(arg0);
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
