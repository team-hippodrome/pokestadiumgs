#include "global.h"

// The menu command lists fragment14_data's descriptors point at.
const s16 D_813122B0[8] = { 66, 163, 1, 0, 67, 3, -1, 0 };
const s16 D_813122C0[4] = { 31, 2, 0, 0 };
const s16 D_813122C8[4] = { 33, 147, 1, 0 };
const s16 D_813122D0[4] = { 33, 2, 1, 0 };
const s16 D_813122D8[4] = { 34, 2, 1, 0 };
const s16 D_813122E0[4] = { 35, 2, 1, 3 };
const s16 D_813122E8[4] = { 36, 2, 1, 0 };
const s16 D_813122F0[20] = { 26, 147, 1, 0, 27, 148, 3, 0, 28, 149, 4, 0, 29, 150, 5, 0, 30, 151, 6, 0 };
const s16 D_81312318[16] = { 26, 147, 2, 0, 28, 149, 4, 0, 29, 150, 5, 0, 30, 151, 6, 0 };
const s16 D_81312338[16] = { 26, 147, 1, 0, 28, 149, 4, 0, 29, 150, 5, 0, 30, 151, 6, 0 };
const s16 D_81312358[16] = { 26, 147, 1, 0, 27, 148, 3, 0, 28, 149, 4, 0, 29, 150, 5, 0 };
const s16 D_81312378[12] = { 26, 147, 2, 0, 28, 149, 4, 0, 29, 150, 5, 0 };
const s16 D_81312390[12] = { 26, 147, 1, 0, 28, 149, 4, 0, 29, 150, 5, 0 };



#ifdef VERSION_US
s32 func_81302BB0(const u8 *arg0) {
    return *(const s8 *)(arg0 + 0x4DBC) >= 0;
}

extern s32 func_8160A920(u8 *);
s32 func_81302BC0(u8 *arg0) {
    s32 var_v1;
    s32 offset;
    u8 *entry;

    offset = func_8160A920(arg0) * 0xCE8;
    entry = arg0 + offset;
    var_v1 = entry[0x20] == 0;
    if (var_v1 != 0) {
        var_v1 = arg0[0x4DBD] == 0xD;
        if (var_v1 != 0) {
            var_v1 = func_81302BB0(arg0) == 0;
        }
    }
    return var_v1;
}

s32 func_81302C40(const u8 *arg0) {
    return arg0[0x4DBD] == 0 && arg0[0x4DC4] >= 3;
}

s32 func_81302C64(u8 *arg0) {
    switch (arg0[0x4DBD]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 11:
        case 15:
        case 16:
            return 0;
        case 8:
        case 9:
        case 10:
        case 12:
        case 13:
        case 14:
        case 17:
        case 18:
            return 1;
    }
    return 1;
}

s32 func_81302CA4(u8 *arg0) {
    return arg0[0x4DBD] == 0x11;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_81302CB4.s")

extern void func_81302CB4(u8 *, s16 *);
extern void func_81609A90(u8 *, u8 *);
extern void func_8160A928(u8 *, s32);
void func_81302E58(void *arg0, s32 arg1) {
    u8 sp30[8];
    u8 sp28[8];
    f32 sp24;

    sp24 = *(f32 *)((u8 *)arg0 + 0x4DA4);
    *(f32 *)((u8 *)arg0 + 0x4DA4) = 0.0f;
    func_81302CB4((u8 *)arg0, (s16 *)sp30);
    *(f32 *)((u8 *)arg0 + 0x4DA4) = 16.0f;
    func_81302CB4((u8 *)arg0, (s16 *)sp28);
    if (arg1 != 0) {
        func_81609A90(sp30, sp28);
    } else {
        func_81609A90(sp28, sp30);
    }
    *(f32 *)((u8 *)arg0 + 0x4DA4) = sp24;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_81302EE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_8130302C.s")

extern s32 func_8160B9A0(u8 *, s32, s32);
void func_813031D8(u8 *arg0) {
    s32 index;
    s32 flag;

    index = func_8160A920(arg0);
    flag = func_81302BB0(arg0);
    *(s32 *)(arg0 + 19884) |= func_8160B9A0(arg0, index, flag);
}

void func_81303228(u8 *arg0) {}

void func_81303230(u8 *arg0) {
    arg0[0x4DC4] += 1;
}

void func_81303240(u8 *arg0) {}

extern s32 func_8160A920(u8 *);
extern s32 func_8130A708(u8 *arg0);
extern s32 func_8160B9A0(u8 *arg0, s32 arg1, s32 arg2);
void func_81303248(u8 *arg0) {
    s32 value = func_8160A920(arg0);
    if (func_8130A708(*(u8 **)(arg0 + 0x4DA0) + 0xDA8)) {
        s32 valid = func_81302BB0(arg0);
        func_8160B9A0(arg0, value, valid);
        arg0[0x4DBD] = 0xD;
        *(s32 *)(arg0 + 0x4DAC) = 1;
    }
}

extern void func_81303248(u8 *arg0);
void func_813032B0(u8 *arg0) {
    func_81303248(arg0);
}

extern f32 func_816092FC(void);
extern s32 func_8160A9CC();
void func_813032D0(void *arg0) {
    f32 delta;
    f32 temp_fv1;

    delta = func_816092FC();
    *(f32 *)((u8 *)arg0 + 0x4DA4) =
        *(f32 *)((u8 *)arg0 + 0x4DA4) + delta;
    temp_fv1 = *(f32 *)((u8 *)arg0 + 0x4DA4);
    if (temp_fv1 <= 0.0f) {
        *(f32 *)((u8 *)arg0 + 0x4DA4) = 0.0f;
        return;
    }
    if (temp_fv1 >= 16.0f) {
        *(f32 *)((u8 *)arg0 + 0x4DA4) = 16.0f;
        if (func_8160A9CC() != 0) {
            *(u8 *)((u8 *)arg0 + 0x4DBD) = 4;
            return;
        }
        *(u8 *)((u8 *)arg0 + 0x4DBD) = 0xC;
    }
}

f32 func_816092FC(void);
f32 func_816092FC(void);
void func_81303364(void *arg0) {
    f32 temp_fv1;

    (*(f32 *)((u8 *)(arg0) + (0x4DA4))) = (f32) ((*(f32 *)((u8 *)(arg0) + (0x4DA4))) - func_816092FC());
    temp_fv1 = (*(f32 *)((u8 *)(arg0) + (0x4DA4)));
    if (temp_fv1 <= 0.0f) {
        (*(f32 *)((u8 *)(arg0) + (0x4DA4))) = 0.0f;
        (*(s8 *)((u8 *)(arg0) + (0x4DBD))) = 0;
        (*(s8 *)((u8 *)(arg0) + (0x4DC4))) = 0;
        return;
    }
    if (temp_fv1 >= 16.0f) {
        (*(f32 *)((u8 *)(arg0) + (0x4DA4))) = 16.0f;
    }
}

extern s32 func_8130F578(u8 *, u8 *);
extern s32 func_8130A708(u8 *arg0);
extern s32 func_8160A920(u8 *);
void func_813033DC(u8 *arg0) {
    struct { u32 prefix; u8 buffer[8]; } local;
    s32 result;
    func_8160A920(arg0);
    result = func_8130F578(*(u8 **)(arg0 + 0x4DA0), local.buffer);
    if (result == 1) {
        func_8130A708(*(u8 **)(arg0 + 0x4DA0) + 0xDA8);
        *(s32 *)(arg0 + 0x4DAC) = 1;
        arg0[0x4DBD] = 0xD;
    } else if ((s16)result == 2) {
        arg0[0x4DBD] = 0x11;
        *(f32 *)(arg0 + 0x4DA4) = 16.0f;
    }
}

extern void func_81302E58(void *, s32);
s32 func_81311C70(s32, s32 *, u8, s32);
extern u8 D_81311D60;
void func_8130345C(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_81311C70((*(s32 *)((u8 *)(arg0) + (0x4DA0))) + 0x74, &D_81311D60, (*(u8 *)((u8 *)(arg0) + (0xA))), -1);
    if (temp_v0 != -1) {
        if (temp_v0 == 1) {
            (*(s8 *)((u8 *)(arg0) + (0x4DBD))) = 0xF;
            (*(s32 *)((u8 *)(arg0) + (0x4DB8))) = 0;
            (*(f32 *)((u8 *)(arg0) + (0x4DA8))) = 0.0f;
        }
    } else {
        func_8130A570((*(s32 *)((u8 *)(arg0) + (0x4DA0))) + 0xDA8, (*(s32 *)((u8 *)(arg0) + (0x4DB4))));
        (*(s8 *)((u8 *)(arg0) + (0x4DBD))) = 3;
        func_81302E58(arg0, 0);
    }
}

extern void func_8160A94C(u8 *);
extern void func_8160A928(u8 *, s32);
extern f32 func_816092FC(void);
void func_813034E8(u8 *arg0) {
    f32 delta;
    f32 temp_fv1;

    delta = func_816092FC();
    delta = delta / 16;
    *(f32 *)(arg0 + 0x4DA8) = *(f32 *)(arg0 + 0x4DA8) + delta;
    temp_fv1 = *(f32 *)(arg0 + 0x4DA8);
    if (temp_fv1 >= 1.0f) {
        *(u8 *)(arg0 + 0x4DBD) = 0xC;
        return;
    }
    if ((temp_fv1 >= 0.5f) && (*(u32 *)(arg0 + 0x4DB8) == 0)) {
        *(s8 *)(arg0 + 0x4DBC) = *(s8 *)(arg0 + 0x4DBC) + 1;
        func_8160A94C(arg0);
        func_8160A928(arg0, 0);
        *(u32 *)(arg0 + 0x4DB8) = 1;
    }
}

extern u8 D_81311E5C[];

void *func_813035A0(void *arg0) {
    s32 idx;

    idx = 0;
    if (*(s8 *)(*(u8 **)((u8 *)(u32)(*(s32 *)((u8 *)arg0 + 0x4DA0) + 0x20000) - 0x5EB8) + 0x944) < 0) {
        idx = 2;
    }
    if (func_81302BB0(arg0) != 0) {
        idx = 1;
    }
    return &D_81311E5C[((((u32) *(u32 *)(*(u8 **)(*(u8 **)((u8 *)(u32)(*(s32 *)((u8 *)arg0 + 0x4DA0) + 0x20000) - 0x5EB8) + 0x940) + 0x40) << 5) >> 0x1F) == 0) * 108 + idx * 36];
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_81303648.s")

extern void func_813049AC(u8 *, s16 *);
extern void func_81304788(u8 *, s32 *, s32);
extern void func_81306C18(void *, s32, s32 *, s32);
extern void func_8130EB04(void *, s32, void *, s32, s32 *, s16 *, s16 *, s32);
void func_813037F0(u8 *arg0) {
    struct unk_func_813037F0 {
        u8 unk_0000[19902];
        u8 unk_4DBE[6];
    };
    s32 index;
    s32 flags[8];
    s16 position[4];
    s32 mode;

    index = func_8160A920(arg0);
    func_813049AC(arg0, position);
    func_81304788(arg0, flags, index);
    func_81306C18(*(u8 **)(arg0 + 19872) + 3352, ((struct unk_func_813037F0 *)arg0)->unk_4DBE[index], flags, 1);
    if (func_81302BB0(arg0) != 0) {
        mode = 152;
    } else {
        mode = 146;
    }
    func_8130EB04(*(void **)(arg0 + 19872), arg0[10], ((u8 (*)[3304])arg0)[index] + 32,
        3, flags, position, position, mode);
    arg0[19901] = 10;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_813038D0.s")

extern s32 func_8160A9F0(void);
s32 func_81303A38(void *arg0) {
    void *entry;

    entry = *(void **)(*(u8 **)((u8 *)(u32)(*(s32 *)((u8 *)arg0 + 0x4DA0) + 0x20000) - 0x5EB8) + 0x940);
    if (entry == NULL) {
        return 0;
    }
    return *(u16 *)((u8 *)entry + 0x38) < func_8160A9F0();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_81303A88.s")

extern u8 D_81311DA8[];
extern s32 func_81302290(void *);
extern void func_81302E58(void *arg0, s32 arg1);
extern s32 func_81311C70(s32, s32 *, u8, s32);
void func_81303BF4(u8 *arg0) {
    u8 *table;
    table = &D_81311DA8[func_81302BB0(arg0) * 36];
    if (func_81311C70(*(s32 *)(arg0 + 0x4DA0) + 0x74, (s32 *)table, arg0[0xA], -1) != 0) {
        if ((func_81302BB0(arg0) != 0) && (func_81302290(*(void **)(arg0 + 0x4DA0)) < 10)) {
            arg0[0x4DBD] = 0xB;
            return;
        }
        func_8130A570(*(s32 *)(arg0 + 0x4DA0) + 0xDA8, 0);
        arg0[0x4DBD] = 3;
        func_81302E58(arg0, 0);
    }
}

extern s32 func_813022F4(void *arg0, void *arg1);
extern void func_81311C18(s32 arg0);
void func_81303CA0(void *arg0) {
    void *temp_a0;

    func_81311C18(*(s32 *)((u8 *)arg0 + 0x4DA0) + 0x74);
    temp_a0 = *(void **)((u8 *)arg0 + 0x4DA0);
    if ((*(u8 *)((u8 *)temp_a0 + 0x8C) == 0) && (func_813022F4(temp_a0, arg0) != 0)) {
        *(u8 *)((u8 *)arg0 + 0x4DBD) = 5;
        return;
    }
    *(u8 *)((u8 *)arg0 + 0x4DBD) = 6;
}

extern s32 D_81311DF0;
extern void func_81311C18(s32);
void func_81303D04(void *arg0) {
    if (func_81311C70((*(s32 *)((u8 *)(arg0) + (0x4DA0))) + 0x74, &D_81311DF0, (*(u8 *)((u8 *)(arg0) + (0xA))), -1) != 0) {
        func_81311C18((*(s32 *)((u8 *)(arg0) + (0x4DA0))) + 0x74);
        (*(s8 *)((u8 *)(arg0) + (0x4DBD))) = 4;
    }
}

extern void func_813049AC(u8 *, s16 *);
extern void func_81304788(u8 *, s32 *, s32);
extern void func_8130EB04(void *, s32, void *, s32, s32 *, s16 *, s16 *, s32);
void func_81303D60(u8 *arg0) {
    s32 index;
    s32 flags[8];
    s16 position[4];
    s32 mode;

    func_813049AC(arg0, position);
    index = func_8160A920(arg0);
    func_81304788(arg0, flags, index);
    if (func_81302BB0(arg0) != 0) {
        mode = 150;
    } else {
        mode = 146;
    }
    func_8130EB04(*(void **)(arg0 + 19872), arg0[10], ((u8 (*)[3304])arg0)[index] + 32,
        1, flags, position, position, mode);
    arg0[19901] = 14;
}

extern s32 D_81311E14;
extern s32 func_81311C70(s32, s32 *, u8, s32);
void func_81303E20(u8 *arg0) {
    s32 temp_v0_2;
    void *temp_v0;

    temp_v0 = *(void **)(arg0 + 0x4DA0);
    temp_v0_2 = func_81311C70(
        (s32)temp_v0 + 0x74,
        &D_81311E14,
        arg0[0xA],
        *(u16 *)((u8 *)*(void **)(*(u8 **)((u8 *)(u32)((s32)temp_v0 + 0x20000) - 0x5EB8) + 0x940) + 0x38)
    );
    if (temp_v0_2 != 0) {
        if (temp_v0_2 == 0) {
            func_8160A928(arg0, 5);
            arg0[0x4DBD] = 0xC;
            return;
        }
        func_8160A928(arg0, 0);
        arg0[0x4DBD] = 0x11;
    }
}

s32 func_81303A38(void *);
void func_81303EA8(void *arg0) {
    func_81311C18((*(s32 *)((u8 *)(arg0) + (0x4DA0))) + 0x74);
    if (func_81303A38(arg0) != 0) {
        (*(s8 *)((u8 *)(arg0) + (0x4DBD))) = 7;
        return;
    }
    (*(s8 *)((u8 *)(arg0) + (0x4DBD))) = 4;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_81303EF4.s")

extern s32 func_8160A8DC();
extern void func_81302E58(void *arg0, s32 arg1);
extern void func_8160A928(u8 *, s32);
s32 func_81304178(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 value;
    value = func_8160A8DC(arg0);
    *(s32 *)(arg0 + 0x4DB0) = arg2;
    *(s32 *)(arg0 + 0x4DB4) = arg3;
    arg0[0x4DBC] = arg1;
    arg0[0x4DBD] = 2;
    *(f32 *)(arg0 + 0x4DA4) = 0.0f;
    func_81302E58(arg0, 1);
    func_8160A928(arg0, value < 5 ? value : 5);
    return 1;
}

s32 func_81304208(u8 *arg0) {
    if (arg0[0x4DBD] != 0xD) {
        return 0;
    }
    arg0[0x4DBD] = 3;
    func_81302E58(arg0, 0);
    return 1;
}

s32 func_81304248(u8 *arg0) {
    s32 var_s0;

    var_s0 = 0;
    if ((*(u8 *)((u8 *)(arg0) + (0x4DBD))) != 0xD) {
        return 0;
    }
    do {
        func_8160B9A0(arg0, var_s0, func_81302BB0(arg0));
        var_s0 += 1;
    } while (var_s0 != 6);
    func_8130A5D0((*(s32 *)((u8 *)(arg0) + (0x4DA0))) + 0xDA8);
    func_8160A928(arg0, 0);
    (*(u8 *)((u8 *)(arg0) + (0x4DBD))) = 0xCU;
    (*(s32 *)((u8 *)(arg0) + (0x4DAC))) = 1;
    return 1;
}

extern s32 func_8160A8DC(u8 *);
s32 func_813042E4(u8 *arg0) {
    u8 *context;

    func_8160A920(arg0);
    if (arg0[19901] != 13) {
        return 0;
    }
    if (func_8160A8DC(arg0) == 0) {
        return 0;
    }
    context = *(u8 **)(arg0 + 19872);
    if ((*(u32 *)(*(u8 **)(*(u8 **)(context + 106824) + 2368) + 64) >> 31) == 0) {
        return 0;
    }
    func_81311C18((s32)context + 116);
    arg0[19901] = 4;
    return 1;
}

/* mkdraft:func_8130437C begin */
extern s32 func_8160A920(u8 *);
extern s32 func_8160A8DC(u8 *);
extern void func_8160A928(u8 *, s32);
extern void func_813031D8(u8 *);

s32 func_8130437C(u8 *arg0) {
    s32 sp24;

    sp24 = func_8160A920(arg0);
    if (arg0[0x4DBD] == 0xD) {
        if (func_8160A8DC(arg0) == 0) {
            arg0[0x4DBD] = 3;
            return -1;
        }
        if (((u8 *)arg0 + (sp24 * 0xCE8))[0x20] == 0) {
            func_8160A928(arg0, sp24 - 1);
            func_813031D8(arg0);
            arg0[0x4DBD] = 0xC;
        } else {
            arg0[0x4DBD] = 0x11;
        }
        return 1;
    }
    return 0;
}
/* mkdraft:func_8130437C end */

extern void func_8160B8E0(u8 *, s32, s32, s32);
extern s32 func_81303A38(void *arg0);
extern void func_81311C18(s32 arg0);
extern s32 func_8160A920(u8 *);
extern void func_8160A928(u8 *, s32);
extern s32 func_8160A9CC();
s32 func_81304444(u8 *arg0, s32 arg1, s32 arg2) {
    s32 sp24;
    s32 var_a2;

    sp24 = func_8160A920(arg0);
    if (arg0[0x4DBD] != 0xD) {
        return 0;
    }
    *(s32 *)(arg0 + 0x4DAC) = 1;
    func_8160B8E0(arg0, arg1, sp24, 0);
    ((u8 *)arg0 + (sp24 * 0xCE8))[0x21] = (s8)arg2;
    if (func_8160A9CC(arg0) != 0) {
        func_81311C18(*(s32 *)(arg0 + 0x4DA0) + 0x74);
        if (func_81303A38(arg0) != 0) {
            arg0[0x4DBD] = 7;
        } else {
            arg0[0x4DBD] = 4;
        }
    } else {
        do {
            sp24 = (sp24 + 1) % 6;
        } while (((u8 *)arg0 + (sp24 * 0xCE8))[0x20] != 0);
        func_8160A928(arg0, sp24);
        arg0[0x4DBD] = 0xC;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FAD40/func_8130456C.s")

s32 func_81304678(u8 *arg0, u8 *arg1) {
    u8 *entry; entry = arg0 + 0x20;
    if (arg1[0] == 0) return 0;
    if (entry[0] == 0) goto n1; if (*(s32 *)(arg1+0x58) == *(s32 *)(entry+0x58)) return 1;
n1: entry += 0xCE8; if (entry[0] == 0) goto n2; if (*(s32 *)(arg1+0x58) == *(s32 *)(entry+0x58)) return 1;
n2: entry += 0xCE8; if (entry[0] == 0) goto n3; if (*(s32 *)(arg1+0x58) == *(s32 *)(entry+0x58)) return 1;
n3: entry += 0xCE8; if (entry[0] == 0) goto n4; if (*(s32 *)(arg1+0x58) == *(s32 *)(entry+0x58)) return 1;
n4: entry += 0xCE8; if (entry[0] == 0) goto n5; if (*(s32 *)(arg1+0x58) == *(s32 *)(entry+0x58)) return 1;
n5: entry += 0xCE8; if (entry[0] != 0 && *(s32 *)(arg1+0x58) == *(s32 *)(entry+0x58)) return 1; return 0;
}

extern void func_81601A38(s32 *, s32);
extern s32 func_80071230(u8 *);
extern void func_81601D24(s32, s32);
extern void func_816019C0(s32, s32, s32);

void func_81304788(u8 *arg0, s32 *arg1, s32 arg2) {
    s32 i;
    u8 *record;
    func_81601A38(arg1, 0);
    if (func_80071230(*(void **)(*(u8 **)((u8 *)(*(s32 *)(arg0 + 0x4DA0) + 0x20000) - 0x5EB8) + 0x940)) != 0) return;
    if (arg2 >= 0 && arg2 < 6) {
        i = arg2 * 0xCE8;
        record = arg0 + i;
        if (record[0x20] <= 0) {
            record = arg0;
        } else {
            func_81601D24(arg1, record[0x20]);
        }
    }
    record = arg0;
    for (i = 0; i != 6; i++) {
        if (record[0x20] != 0 && record[0x21] != 0 && i != arg2) {
            func_816019C0(arg1, record[0x21], 1);
        }
        record += 0xCE8;
    }
}

extern s32 func_80071230(u8 *arg0);
s32 func_81304884(u8 *arg0, s32 arg1) { u8 *record; s32 count; record = arg0 + 0x20; if (func_80071230(*(u8 **)(*(u8 **)((u8 *)(u32)(*(s32 *)(arg0 + 0x4DA0) + 0x20000) - 0x5EB8) + 0x940)) != 0) return 0; count = 6; do { if (record[0] != 0 && record[1] == arg1) return 1; record += 0xCE8; count--; } while (count != 0); return 0; }

extern void func_81302CB4(u8 *arg0, s16 *arg1);
extern void func_8160B5BC(void *arg0, s16 *arg1);
void func_813049AC(u8 *arg0, s16 *arg1) {
    s16 *output = arg1;
    s16 temp[2];

    func_81302CB4(arg0, temp);
    func_8160B5BC(arg0, output);
    output[0] += temp[0];
    output[1] += temp[1];
}

typedef struct unk_func_81304A08_20 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01[3];
    /* 0x04 */ s32 unk_04[0x15];
} unk_func_81304A08_20; // size = 0x58

typedef struct unk_func_81304A08 {
    /* 0x000 */ u8 unk_000[0x20];
    /* 0x020 */ unk_func_81304A08_20 unk_020;
    /* 0x078 */ u8 unk_078[0xC70];
} unk_func_81304A08; // size = 0xCE8

s32 func_81304A08(u8 *arg0, unk_func_81304A08_20 *out) {
    s32 count;
    s32 i;

    if (func_81302C40(arg0) == 0) {
        return 0;
    }
    count = func_8160A8DC(arg0);
    for (i = 0; i < count; i++) {
        out[i] = ((unk_func_81304A08 *)arg0)[i].unk_020;
    }
    return count;
}

s32 func_81304AD0(u8 *arg0) {
    s32 i;

    if (func_81302C40(arg0) != 0) {
        for (i = 0; i < 6; i++) {
            if (((unk_func_81304A08 *)arg0)[i].unk_020.unk_00 > 0) {
                return 1;
            }
        }
        return -1;
    }
    return 0;
}
#endif
