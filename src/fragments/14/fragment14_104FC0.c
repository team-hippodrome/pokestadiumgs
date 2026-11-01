#include "global.h"


#ifdef VERSION_US
s32 func_8130CE30(u8 *arg0) {
    return *(s32 *)(arg0 + 0x5C) != 0;
}

extern s32 func_81601FA0(u8);
extern s32 func_81601980(s32 *, s32);
extern void func_81601D24(s32, s32);
extern f32 func_816092FC(void);
extern s32 func_8130CE30(u8 *);
s32 func_8130CE3C(u8 *arg0) {
    s32 result;
    u8 selector;
    if (arg0[0x35] == 1) {
        return 0;
    }
    selector = arg0[0x39];
    if (selector == 0) {
        return 0;
    }
    result = func_81601FA0(selector) == 0;
    if (result == 0) {
        result = func_81601980((s32 *)(arg0 + 0x3C), arg0[0x39]) != 0;
    }
    return result;
}

extern s32 func_81601FA0(u8);
extern s32 func_81601980(s32 *, s32);
extern void func_81601D24(s32, s32);
extern f32 func_816092FC(void);
extern s32 func_8130CE30(u8 *);
s32 func_8130CEAC(u8 *arg0) {
    s32 result;
    if ((arg0[0x35] == 1) || (func_8130CE30(arg0) == 0)) {
        result = 2;
    } else {
        result = 3;
    }
    return result;
}

/* Overlay rectangle filled from an eased window-close progress: arg0 carries
 * the s16 origin (+8/+0xA) and the close progress at +0x2C, which the
 * func_8130F09C update in this file drives toward 1.0f. D_8160BD18 and
 * D_8160BD1C are the easing function-pointer tables shared with the matched
 * grid code (Fragment14_ComputeGridRectangles in fragment14_FF070.c); the
 * rectangle layout and the trailing func_816072FC finalize call match
 * func_8130D45C below, which fills the same struct without easing. */

extern f32 (*D_8160BD18)(f32);
extern f32 (*D_8160BD1C)(f32);
extern void func_816072FC(void *arg0);
typedef struct unk_func_8130D45C {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} unk_func_8130D45C;

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_104FC0/func_8130CEF0.s")

f32 func_8130D098(u8 *arg0, unk_func_8130D45C *arg1) {
    f32 progress;
    f32 scale;

    progress = *(f32 *)(arg0 + 0x2C);
    scale = 1.0f;
    /* FAKE: division by 1. Keep the divisor int-spelled: IDO lowers progress / 1.0f to a multiply
     * (same lowering as the / 16 in Fragment14_InterpolatePanelRectangle,
     * //@src/fragments/14/fragment14_FCD40.c). */
    if (progress < 1) {
        scale = progress / 1;
    }
    /* The double adds keep the integer base as the left operand; writing the
     * product first flips add.d's operands and rotates the FPU temp
     * assignment of every statement after these two. */
    arg1->unk_00 = (s16)(s32)(*(s16 *)(arg0 + 8) + 27 + (1.0f - D_8160BD18(scale)) * 36.5);
    arg1->unk_02 = (s16)(s32)(*(s16 *)(arg0 + 10) + 37 + (1.0f - D_8160BD1C(scale)) * 36.5);
    arg1->unk_04 = (s16)(s32)(D_8160BD18(scale) * 73.0f);
    arg1->unk_06 = (s16)(s32)(D_8160BD1C(scale) * 73.0f);
    func_816072FC(arg1);
    return scale;
}
extern void func_8160945C(void *, const s16 *, const s16 *, f32);
f32 func_8130D1FC(u8 *arg0, unk_func_8130D45C *arg1) {
    f32 t;
    const s16 colors[4][4] = {
        { 401, 0, 147, 146 },
        { 401, 0, 147, 49 },
        { 474, 73, 0, 0 },
        { 474, 24, 0, 0 },
    };
    s32 row;

    // Retail divides the progress by 1, like func_8130D098; a float 1.0f divisor becomes a multiply.
    t = *(f32 *)(arg0 + 0x2C) / 1;
    row = arg0[0x35] >= 2;
    func_8160945C(arg1, colors[row + 2], colors[row], t);
    arg1->unk_00 += *(s16 *)(arg0 + 8);
    arg1->unk_02 += *(s16 *)(arg0 + 0xA);
    if (arg0[0x35] < 2 && arg0[0x34] >= 5) {
        arg1->unk_06 += D_8160BD1C(*(f32 *)(arg0 + 0x30) / 12.0f) * 53.0f;
    }
    func_816072FC(arg1);
    return t;
}


extern void func_816072FC(void *arg0);
f32 func_8130D340(u8 *arg0, unk_func_8130D45C *arg1) {
    f32 t;
    f32 w;
    f32 h;

    if (*(f32 *)(arg0 + 0x30) < 12.0f) {
        t = *(f32 *)(arg0 + 0x30) / 12.0f;
    } else {
        t = 1.0f;
    }
    w = D_8160BD18(t);
    h = D_8160BD1C(t);
    arg1->unk_04 = 302.0f * w;
    arg1->unk_06 = 135.0f * h;
    arg1->unk_00 = *(s16 *)(arg0 + 8) + (302 - arg1->unk_04) / 2 + 246;
    arg1->unk_02 = *(s16 *)(arg0 + 0xA) + (135 - arg1->unk_06) / 2;
    func_816072FC(arg1);
    return t;
}


extern void func_8160732C(void* arg0, void* arg1);
extern void func_8160724C(s16* arg0, s16* arg1);
extern void func_816072FC(void* arg0);

void func_8130D45C(u8* arg0, unk_func_8130D45C* arg1, unk_func_8130D45C* arg2) {
    unk_func_8130D45C var_sp18;

    var_sp18 = *arg2;
    func_8160732C(&var_sp18, arg2);
    arg1->unk_00 = *(s16*)(arg0 + 8) + 157;
    arg1->unk_02 = *(s16*)(arg0 + 10) + 112;
    arg1->unk_04 = 72;
    arg1->unk_06 = 72;
    func_8160724C((s16*)arg1, (s16*)&var_sp18);
    func_816072FC(arg1);
}

// Tables func_8130D4E0 (still assembly) reads.
const s16 D_81312750[4] = { 24, 48, 24, 0 };
const s16 D_81312758[4] = { 0, 24, 48, 24 };
const u16 D_81312760[4] = { 6, 5, 3, 4 };
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern f32 func_816092FC(void);
extern f32 func_8160BCB0(f32, f32);
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
void func_8130D4E0(u8 *arg0, s16 *pos) {
    static f32 D_813120B0 = 0.0f;
    s32 i;
    s32 blink;

    D_813120B0 += func_816092FC();
    gSPDisplayList(D_800D0510++, D_80094E38);
    for (i = 0; i < 4; i++) {
        blink = (i == *(s8 *)(arg0 + 0x38)) && (func_8160BCB0(D_813120B0, 32.0f) > 16.0f);
        if (blink) {
            gDPSetEnvColor(D_800D0510++, 0x80, 0x80, 0x80, 0xFF);
        }
        func_8004D19C(pos[0] + D_81312750[i], pos[1] + D_81312758[i], func_8004C990(51, D_81312760[i]), 1, 0);
        if (blink) {
            gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}


// The highlight color func_8130E99C packs and func_8130D6A4 (still assembly) reads, then the
// data of the still-assembly func_8130D6A4 and func_8130DEB8.
u8 D_813120B4[4] = { 0x64, 0x96, 0xFF, 0x00 };
s32 D_813120B8[3] = { 0x1C, 0x1E00, 0x9600 };
s32 D_813120C4 = 100;
s32 D_813120C8 = 100;
s32 D_813120CC = 100;
s32 D_813120D0 = 100;
s32 D_813120D4 = 100;

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_104FC0/func_8130D6A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_104FC0/func_8130DA04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_104FC0/func_8130DEB8.s")

// Data func_8130DEB8 (still assembly) reads; its loop end pointer one past D_813127DC is the
// linker alias D_813127E0.
const u8 D_8131279C[4] = { 0 };
const char D_813127A0[8] = "%s%s";
const char D_813127A8[8] = "%s%s";
const char D_813127B0[8] = "%s%s";
const char D_813127B8[8] = "%s%s";
const s32 D_813127C0[4] = { 179, 254, 230, 155 };
const s32 D_813127D0[3] = { 116, 140, 164 };
const s32 D_813127DC[1] = { 140 };

extern u8 D_813120B4[];
extern s32 func_80042D54(u8 *, u16);
void func_8130E99C(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    u16 color;
    arg0[0x34] = 0;
    arg0[0x37] = 0;
    *(s32 *)(arg0 + 0x60) = 0;
    *(s32 *)(arg0 + 0x5C) = arg1;
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x64) = arg2;
    *(u8 **)(arg0 + 0x68) = arg3;
    *(s32 *)(arg0 + 0x6C) = 0;
    *(u16 *)(arg0 + 0x12) = 0;
    *(u16 *)(arg0 + 0x10) = 0;
    *(u16 *)(arg0 + 0x0C) = 0x2F;
    *(u16 *)(arg0 + 0x0E) = 0xFF;
    *(u16 *)(arg0 + 0x08) = 0x2F;
    *(u16 *)(arg0 + 0x0A) = 0xFF;
    *(s32 *)(arg0 + 0x00) = 0;
    *(s32 *)(arg0 + 0x70) = 0;
    *(f32 *)(arg0 + 0x28) = 0.0f;
    *(f32 *)(arg0 + 0x30) = 0.0f;
    *(f32 *)(arg0 + 0x2C) = 1.0f;
    *(u16 *)arg3 &= 0xFFFD;
    *(u16 *)(*(u8 **)(arg0 + 0x68)) &= 0xFFFB;
    *(u16 *)(*(u8 **)(arg0 + 0x68)) |= 0x100;
    color = (((D_813120B4[2] >> 2) & 0x3E) |
             (((D_813120B4[1] * 8) & 0x7C0) |
              ((D_813120B4[0] << 8) & 0xF800)) | 1) & 0xFFFF;
    func_80042D54(*(u8 **)(arg0 + 0x68), color);
}

void func_8130EA8C(u8 *arg0, u8 *arg1) {
    if ((*(u8 **)(arg0 + 0x6C) != arg1) || (*(s32 *)(arg1 + 0x58) != *(s32 *)(arg0 + 0x24))) {
        *(u8 **)(arg0 + 0x6C) = arg1;
        *(s32 *)(arg0 + 0x24) = *(s32 *)(arg1 + 0x58);
        *(s32 *)(arg0 + 0x00) = 1;
        *(u8 *)(arg0 + 0x39) = arg1[1];
        func_81601D24((s32)(arg0 + 0x3C), arg1[0]);
        *(s32 *)(arg0 + 0x70) = 2;
        *(s32 *)(arg0 + 0x60) = 0;
    }
}
// The 0x20-byte record func_8130EB04 copies to +0x3C (func_81601A38 initializes it otherwise).
typedef struct unk_D_8130EB04 {
    /* 0x00 */ s32 unk_00[8];
} unk_D_8130EB04; // size = 0x20
extern void func_8130F5AC(u8 *arg0);
extern void func_81601A38(void *, s32);
extern s32 func_8130CE3C(u8 *arg0);
extern s32 func_8130CEAC(u8 *arg0);
extern void func_8130EA8C(u8 *arg0, u8 *arg1);
void func_8130EB04(u8 *arg0, s16 arg1, u8 *arg2, s16 arg3, unk_D_8130EB04 *arg4, unk_func_8130D45C *arg5,
                   unk_func_8130D45C *arg6, s32 arg7) {
    *(s32 *)(arg0 + 4) = arg7;
    if (arg2[0] == 0) {
        func_8130F5AC(arg0);
        *(s32 *)(arg0 + 0x6C) = 0;
        arg0[0x34] = 0;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        return;
    }
    switch (arg0[0x34]) {
        case 0:
            *(s8 *)(arg0 + 0x38) = -1;
            *(s16 *)(arg0 + 0x12) = 0;
            *(s16 *)(arg0 + 0x10) = 0;
            *(f32 *)(arg0 + 0x2C) = 0.0f;
        case 2:
        case 3:
            arg0[0x34] = 2;
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
    }
    arg0[0x35] = arg3;
    arg0[0x37] = arg1;
    *(unk_func_8130D45C *)(arg0 + 0x1C) = *arg5;
    *(unk_func_8130D45C *)(arg0 + 0x14) = *arg6;
    if (arg4 != NULL) {
        *(unk_D_8130EB04 *)(arg0 + 0x3C) = *arg4;
    } else {
        func_81601A38(arg0 + 0x3C, 0);
    }
    func_8130EA8C(arg0, arg2);
    if (func_8130CE3C(arg0)) {
        *(s8 *)(arg0 + 0x36) = func_8130CEAC(arg0) - 1;
    } else {
        arg0[0x36] = 0;
    }
}

void func_8130EC94(u8 *arg0) {
    *(u32 *)(arg0 + 0x6C) = 0;
}

/* mkdraft:func_8130EC9C begin */
extern void func_800226C0(s32);
extern void func_81306C18(void *, s32, s32 *, s32);
extern u8 D_800CE060[];

/* m2c field-access helper (see matching_notes/TECHNIQUES.md). */
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))



void func_8130EC9C(u8 *arg0) {
    s32 sp34;
    void *temp_v1;
    s32 sp2C;
    s32 sp28;
    u16 sp26;
    u16 sp24;
    s32 sp20;
    void *sp30;
    s32 temp_v0;
    s32 var_v0;
    s8 temp_v0_2;
    u8 temp_v0_3;

    sp34 = 0;
    temp_v1 = (M2C_FIELD(arg0, u8 *, 0x37) * 0x28) + D_800CE060;
    sp2C = M2C_FIELD(arg0, s32 *, 0x6C);
    sp28 = -1;
    sp26 = M2C_FIELD(temp_v1, u16 *, 0xC);
    sp30 = temp_v1;
    sp24 = M2C_FIELD(temp_v1, u16 *, 8);
    temp_v0 = func_8130CE3C(arg0);
    sp20 = temp_v0;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x35) < 2) {
        if (M2C_FIELD(temp_v1, u16 *, 0xC) & 0x8000) {
            temp_v0_2 = M2C_FIELD(arg0, s8 *, 0x36);
            if (temp_v0_2 == 2) {
                func_81306C18(M2C_FIELD(arg0, void **, 0x5C), (s32) M2C_FIELD(arg0, u8 *, 0x39), (s32 *) (arg0 + 0x3C), 0);
                temp_v0_3 = M2C_FIELD(arg0, u8 *, 0x35);
                M2C_FIELD(arg0, s8 *, 0x34) = 4;
                switch (temp_v0_3) {                /* irregular */
                case 1:
                    func_800226C0(0x96);
                    break;
                case 0:
                case 2:
                    func_800226C0(2);
                    break;
                }
            } else if (temp_v0_2 == 1) {
                func_800226C0(3);
                M2C_FIELD(arg0, s8 *, 0x34) = 3;
                M2C_FIELD(arg0, f32 *, 0x2C) = 1.0f;
            } else {
                func_800226C0(M2C_FIELD(arg0, s32 *, 4));
                M2C_FIELD(arg0, s8 *, 0x34) = 3;
                M2C_FIELD(arg0, f32 *, 0x2C) = 1.0f;
            }
        } else if (sp26 & 0x4000) {
            func_800226C0(3);
            M2C_FIELD(arg0, s8 *, 0x36) = 1;
            M2C_FIELD(arg0, s8 *, 0x34) = 3;
            M2C_FIELD(arg0, f32 *, 0x2C) = 1.0f;
        } else if (sp26 & 0x800) {
            if (temp_v0 != 0) {
                var_v0 = 1;
            } else {
                var_v0 = 0;
            }
            if (var_v0 < M2C_FIELD(arg0, s8 *, 0x36)) {
                func_800226C0(1);
                M2C_FIELD(arg0, s8 *, 0x36) = (s8) (M2C_FIELD(arg0, s8 *, 0x36) - 1);
            }
        } else if (sp26 & 0x400) {
            if (M2C_FIELD(arg0, s8 *, 0x36) < (func_8130CEAC(arg0) - 1)) {
                func_800226C0(1);
                M2C_FIELD(arg0, s8 *, 0x36) = (s8) (M2C_FIELD(arg0, s8 *, 0x36) + 1);
            }
        } else {
            sp34 = 1;
        }
    } else {
        sp34 = 1;
    }
    M2C_FIELD(arg0, s8 *, 0x38) = -1;
    if ((sp34 != 0) && (M2C_FIELD(arg0, u8 *, 0x35) != 3)) {
        if ((sp20 != 0) && (M2C_FIELD(arg0, s8 *, 0x36) == 0)) {
            M2C_FIELD(arg0, s8 *, 0x36) = 1;
        } else if (sp24 & 8) {
            sp28 = 0;
        } else if (sp24 & 1) {
            sp28 = 1;
        } else if (sp24 & 4) {
            sp28 = 2;
        } else if (sp24 & 2) {
            sp28 = 3;
        }
    }
    if (sp28 >= 0) {
        if ((s32) M2C_FIELD((sp2C + sp28), u8 *, 2) > 0) {
            func_800226C0(0x91);
            M2C_FIELD(arg0, s8 *, 0x38) = (s8) sp28;
            M2C_FIELD(arg0, s8 *, 0x34) = 5;
        } else {
            func_800226C0(5);
        }
    }
    M2C_FIELD(arg0, f32 *, 0x30) = 0.0f;
}
/* mkdraft:func_8130EC9C end */

extern u8 D_800CE060[];
extern void func_800226C0(s32);
void func_8130EF88(u8 *arg0) {
    u8 *input = D_800CE060 + arg0[0x37] * 40;
    u8 *counts = *(u8 **)(arg0 + 0x6C);
    s32 dir = -1;
    s32 cur;

    *(f32 *)(arg0 + 0x30) = 12.0f;
    cur = *(s8 *)(arg0 + 0x38);
    if ((counts + cur)[2] == 0 || (*(u16 *)(input + 8) & 0xC000)) {
        func_800226C0(3);
        arg0[0x34] = 7;
        return;
    }
    if (*(u16 *)(input + 8) & 8) {
        dir = 0;
    } else if (*(u16 *)(input + 8) & 1) {
        dir = 1;
    } else if (*(u16 *)(input + 8) & 4) {
        dir = 2;
    } else if (*(u16 *)(input + 8) & 2) {
        dir = 3;
    }
    if (dir >= 0) {
        if ((counts + dir)[2] > 0) {
            if (dir == cur) {
                func_800226C0(5);
            } else {
                func_800226C0(2);
                *(s8 *)(arg0 + 0x38) = dir;
            }
        } else {
            func_800226C0(5);
        }
    }
}

extern f32 func_816092FC(void);
extern s32 func_8130CE30(u8 *arg0);
void func_8130F09C(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 0x2C) += step;
    if (*(f32 *)(arg0 + 0x2C) >= 1.0f) {
        *(f32 *)(arg0 + 0x2C) = 1.0f;
        arg0[0x34] = 1;
        *(s8 *)(arg0 + 0x38) = -1;
    }
}

extern s16 func_81306B0C(void *);
extern void func_800226C0(s32);
void func_8130F0FC(u8 *arg0) {
    s32 status;
    void *target;
    target = *(void **)(arg0 + 0x5C);
    if (target != NULL) {
        status = func_81306B0C(target);
        if (status != -1) {
            if (status == -2) {
                *(u8 *)(arg0 + 0x34) = 1;
            }
            if (status >= 0) {
                *(u8 *)(arg0 + 0x36) = 0;
                *(s8 *)(arg0 + 0x39) = status;
                *(u8 *)(arg0 + 0x34) = 3;
                *(f32 *)(arg0 + 0x2C) = 1.0f;
                func_800226C0(*(s32 *)(arg0 + 0x04));
            }
        }
    } else {
        *(u8 *)(arg0 + 0x34) = 3;
    }
}

extern f32 func_816092FC(void);
void func_8130F184(u8 *arg0) {
    s32 sp18;
    s32 speed;
    speed = ((arg0[0x34] == 3) && (*(s8 *)(arg0 + 0x36) == 0)) ? 0x32 : 1;
    sp18 = speed;
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x2C) - (func_816092FC() * (f32)speed);
    if (*(f32 *)(arg0 + 0x2C) <= 0.0f) {
        arg0[0x34] = 0;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        *(s8 *)(arg0 + 0x38) = -1;
    }
}

void func_8130F218(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 0x30) += step;
    if (*(f32 *)(arg0 + 0x30) >= 12.0f) {
        *(f32 *)(arg0 + 0x30) = 12.0f;
        arg0[0x34] = 6;
    }
}

void func_8130F270(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 0x30) -= step;
    if (*(f32 *)(arg0 + 0x30) <= 0.0f) {
        arg0[0x34] = 1;
        *(f32 *)(arg0 + 0x30) = 0.0f;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_104FC0/func_8130F2C4.s")

s16 func_8130F578(u8 *arg0, s32 *arg1) {
    s16 result = 0;
    if (arg1 != NULL) {
        *arg1 = arg0[0x39];
    }
    if (arg0[0x34] == 0) {
        result = *(s8 *)(arg0 + 0x36) + 1;
    }
    return result;
}

extern void Fragment14_BeginGridClose(u8 *arg0);
void func_8130F5AC(u8 *arg0) {
    u8 *target;
    switch (arg0[0x34]) {
        case 4:
            target = *(u8 **)(arg0 + 0x5C);
            if (target != NULL) {
                Fragment14_BeginGridClose(target);
            }
        case 5:
        case 6:
        case 7:
            *(f32 *)(arg0 + 0x30) = 0.0f;
        case 1:
            *(f32 *)(arg0 + 0x2C) = 1.0f;
        case 2:
        case 3:
            arg0[0x34] = 3;
        case 0:
        default:
            break;
    }
}
#endif
