#include "global.h"


#ifdef VERSION_US
extern u32 osSetIntMask(u32 arg0);
extern s32 D_B0000800;

s32 func_82604390(s32 arg0) {
    OSIntMask old_mask;

    old_mask = osSetIntMask(OS_IM_NONE);
    // FAKE: the u-suffixed second mask is codegen load-bearing - a single & 0xFFFF
    // on the s32-typed global emits a lui+and pair, while the doubled form emits the
    // target's single andi.
    if (!(IO_READ(PI_STATUS_REG) & 0x3) && ((D_B0000800 & 0xFFFF) & 0xFFFFu) != 1) {
        arg0 = -0x80;
    }
    osSetIntMask(old_mask);
    return arg0;
}
void func_826043F8(s16 *arg0, s16 *arg1, s32 arg2, s32 arg3) {
    s16 result;
    s16 subresult;
    s32 type;
    s32 value;

    result = -1;
    subresult = -1;
    type = arg2 & 0xFF00;
    switch (type) {
    case 0x0:
        value = arg2 & 0xFF;
        switch (value) {
        case 0:
            result = 0x6E;
            subresult = 1;
            break;
        case 1:
            result = 0x6E;
            subresult = 4;
            break;
        case 2:
            result = 0x6E;
            subresult = 2;
            break;
        case 3:
            result = 0x6E;
            subresult = 6;
            break;
        }
        break;
    case 0x100:
        result = 0x5C;
        subresult = 0;
        break;
    case 0x700:
        result = 0x63;
        subresult = 0;
        break;
    case 0x200:
        result = 0x5D;
        subresult = 0;
        break;
    case 0x300:
        switch (arg3) {
        case 5:
            result = 0x60;
            subresult = 5;
            break;
        case 6:
            result = 0x60;
            subresult = 4;
            break;
        case 7:
            result = 0x60;
            subresult = 6;
            break;
        case 8:
            result = 0x60;
            subresult = 2;
            break;
        case 9:
            result = 0x60;
            subresult = 7;
            break;
        case 10:
            result = 0x60;
            subresult = 0;
            break;
        case 11:
            result = 0x6B;
            subresult = 1;
            break;
        case 12:
            result = 0x60;
            subresult = 1;
            break;
        case 13:
            result = 0x60;
            subresult = 3;
            break;
        case 14:
            result = 0x5E;
            subresult = 0;
            break;
        case 15:
            result = 0x72;
            subresult = 0;
            break;
        case 16:
            result = 0x62;
            subresult = 2;
            break;
        case 17:
            result = 0x62;
            subresult = 7;
            break;
        case 18:
            result = 0x62;
            subresult = 1;
            break;
        case 19:
            result = 0x62;
            subresult = 5;
            break;
        case 20:
            result = 0x62;
            subresult = 4;
            break;
        case 21:
            result = 0x62;
            subresult = 3;
            break;
        case 22:
            result = 0x62;
            subresult = 0;
            break;
        case 23:
            result = 0x62;
            subresult = 6;
            break;
        case 24:
            result = 0x6A;
            subresult = 0;
            break;
        }
        break;
    case 0x400:
        result = 0x6C;
        subresult = 0;
        break;
    case 0x500:
        result = 0x70;
        subresult = 1;
        break;
    case 0x600:
        result = 0x69;
        subresult = 0;
        break;
    }
    if (arg0 != NULL) {
        *arg0 = result;
    }
    if (arg1 != NULL) {
        *arg1 = subresult;
    }
}

void func_82604628(s16 *arg0, s32 arg1, s32 arg2) {
    s16 result;
    s32 type;
    s32 value;

    result = -1;
    type = arg1 & 0xFF00;
    switch (type) {
    case 0:
        result = 0x57;
        break;
    case 0x100:
    case 0x200:
    case 0x700:
        value = arg1 & 0xFF;
        switch (value) {
        case 0x10: result = 0x5B; break;
        case 0x20: result = 0x64; break;
        default: result = 0x6E; break;
        }
        break;
    case 0x300:
        switch (arg2) {
        case 0xF: result = 0x72; break;
        case 0x18: result = 0x6A; break;
        default: result = 0x6F; break;
        }
        break;
    }
    if (arg0 != NULL) *arg0 = result;
}

extern void func_826043F8(s16 *, s16 *, s32, s32);
extern s32 func_8004C8C0(s32);
s32 func_826046D0(s32 arg0, s32 arg1) {
    s16 value;
    s32 result;

    result = 0;
    func_826043F8(&value, 0, arg0, arg1);
    if (value >= 0) {
        result = func_8004C8C0(value);
    }
    return result;
}

extern s32 func_8004C990(s32, s32);
extern void func_826043F8(s16 *, s16 *, s32, s32);
s32 func_82604720(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result;
    s16 value2;
    s16 value1;

    result = 0;
    func_826043F8(&value2, &value1, arg1, arg2);
    if (value2 >= 0) {
        if (value1 >= 0) {
            if (arg3 != 0) {
                arg0[0] = func_8004C990(0x71, 0);
                result = 1;
            }
            arg0[result] = func_8004C990((s32)value2, (s32)value1);
            result += 1;
        }
    }
    return result;
}

extern void func_82604628(s16 *, s32, s32);
extern s32 func_8004C8C0(s32);
s32 func_826047C4(s32 arg0, s32 arg1) {
    s16 value;
    s32 result;

    func_82604628(&value, arg0, arg1);
    if (value >= 0) {
        result = func_8004C8C0(value);
    } else {
        result = 1;
    }
    return result;
}

extern s16 D_82615532[];
extern s32 func_8004C990(s32, s32);
s32 func_82604814(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result;

    result = 0;
    switch (arg1) {
    case 1:
        arg0[0] = func_8004C990(0x57, 1);
        result = 1;
        break;
    case 2:
        arg0[0] = func_8004C990(0x57, 3);
        result = 1;
        break;
    case 3:
        arg0[0] = func_8004C990(0x57, 0);
        result = 1;
        break;
    case 4:
        arg0[0] = func_8004C990(0x57, 2);
        result = 1;
        break;
    }

    arg1 = arg2 + 1;
    if (arg3 != arg1) goto block_1;
    arg0[result] = func_8004C990(0x6E, 3);
    result = result + 1;
    goto end;

block_1:
    arg1 = arg2 + 2;
    if (arg3 != arg1) goto block_2;
    arg0[result] = func_8004C990(0x6E, 5);
    result = result + 1;
    goto end;

block_2:
    if (arg2 < 6) {
        arg0[result] = func_8004C990(0x6E, 0);
        result = result + 1;
        arg0[result] = func_8004C990(0x65, D_82615532[arg2]);
        result = result + 1;
    }

end:
    return result;
}

extern s32 func_8004C990(s32, s32);

s32 func_826049A0(s32 *arg0, s32 arg1) {
    s32 result;

    result = 0;
    switch (arg1 & 0xFF) {
    case 0:
        *arg0 = func_8004C990(0x6E, 1);
        result = 1;
        break;
    case 1:
        *arg0 = func_8004C990(0x6E, 4);
        result = 1;
        break;
    case 2:
        *arg0 = func_8004C990(0x6E, 2);
        result = 1;
        break;
    case 3:
        *arg0 = func_8004C990(0x6E, 6);
        result = 1;
        break;
    case 16:
        *arg0 = func_8004C990(0x5B, 0);
        result = 1;
        break;
    case 32:
        *arg0 = func_8004C990(0x64, 0);
        result = 1;
        break;
    }
    return result;
}

extern s16 D_82615542[];
extern s32 func_8004C990(s32, s32);
s32 func_82604A78(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result;
    s32 next;

    result = 0;
    switch (arg1) {
    case 15:
        arg0[0] = func_8004C990(0x72, 1);
        result = 1;
        break;
    case 11:
        arg0[0] = func_8004C990(0x6B, 0);
        result = result + 1;
        arg0[result] = func_8004C990(0x65, D_82615542[arg2]);
        result = result + 1;
        break;
    case 14:
        arg0[0] = func_8004C990(0x6F, 1);
        result = result + 1;
        arg0[result] = func_8004C990(0x65, D_82615542[arg2]);
        result = result + 1;
        break;
    case 24:
        arg0[0] = func_8004C990(0x6A, 1);
        result = 1;
        break;
    default:
        next = arg2 + 1;
        if (arg3 != next) goto indexed_default;
        arg0[0] = func_8004C990(0x6F, 0);
        result = 1;
        break;
indexed_default:
        if (arg2 >= 6) goto done_default;
        arg0[0] = func_8004C990(0x6F, 2);
        result = result + 1;
        arg0[result] = func_8004C990(0x65, D_82615542[arg2]);
        result = result + 1;
done_default:
        break;
    }
    return result;
}

s16 *func_82604C08(s16 *arg0, s32 arg1)
{
    s16 *new_var;
    s16 *current;
    s16 *result;
    s32 index;
    result = 0;
    index = 0;
    if (arg1 > 0)
    {
        current = (new_var = arg0);
        do
        {
            index += 1;
            if ((*current) == 0)
            {
                result = current;
                break;
            }
            current += 0x14C;
        }
        while (index != arg1);
    }
    return result;
}

void *func_82604C40(s32 arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 var_v0;
    u8 *var_a0;
    void *var_v1;

    var_v1 = NULL;
    var_v0 = 0;
    if (arg3 > 0) {
        var_a0 = arg2;
loop_2:
        var_v0 += 1;
        if ((arg0 == *(s16 *)var_a0) && (arg1 == *(s16 *)(var_a0 + 2))) {
            var_v1 = var_a0;
        } else {
            var_a0 += 0x298;
            if (var_v0 != arg3) {
                goto loop_2;
            }
        }
    }
    return var_v1;
}

typedef struct unk_func_82604C98 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
} unk_func_82604C98;

s32 func_82604C98(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_v1 = -1;
    s32 var_v0;
    unk_func_82604C98* var_a2;

    for (var_v0 = 0; var_v0 < arg1; var_v0++) {
        var_a2 = &((unk_func_82604C98*)arg0)[var_v0];
        if ((arg2 == var_a2->unk_00) && (arg3 == var_a2->unk_02)) {
            var_v1 = var_v0;
            break;
        }
    }
    return var_v1;
}

extern s32 func_82604C98(s32, s32, s32, s32);
s32 func_82604CF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result;
    s32 index;

    result = 0x29;
    index = func_82604C98(arg0, arg1, arg2, arg3);
    if (index >= 0) {
        result = *(s16 *)((index * 6) + arg0 + 4) + 0x29;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82604D40.s")

typedef struct unk_func_82605110_pair {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_func_82605110_pair;
typedef struct unk_func_82605110 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u8 unk_06[0xA];
    /* 0x10 */ unk_func_82605110_pair unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ unk_func_82605110_pair unk_18;
    /* 0x1C */ u8 unk_1C[8];
    /* 0x24 */ s16 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ u8 unk_28[8];
    /* 0x30 */ s16 unk_30[2];
    /* 0x34 */ s16 unk_34[2][2];
    /* 0x3C */ s16 unk_3C[2];
} unk_func_82605110;
extern s16 D_82615504[];
extern s32 func_82604720(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_82604CF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_82605110(void *arg0, void *arg1) {
    unk_func_82605110 *desc = arg1;
    u8 *state;
    s32 offset;
    s32 *out;
    s32 is_first;

    state = **(u8 ***)((u8 *)arg0 + 0x110);
    offset = *(s16 *)((u8 *)arg0 + 0x16);
    is_first = *(s16 *)arg0 == 1;
    out = (s32 *)desc->unk_30;
    desc->unk_10.unk_00 = 0;
    desc->unk_24 = 554;
    desc->unk_26 = D_82615504[desc->unk_00];
    if (is_first) {
        desc->unk_10.unk_02 = -480;
        desc->unk_16 = 240 - desc->unk_26;
    } else {
        if (*(s16 *)((u8 *)arg0 + 0x12) != 1) {
            desc->unk_10.unk_02 = -480;
        } else {
            desc->unk_10.unk_02 = 480;
        }
        desc->unk_16 = func_82604CF0((s32)((u8 *)arg0 + 0x3544), *(s16 *)((u8 *)arg0 + 0x14), desc->unk_00, desc->unk_02) + offset;
    }
    desc->unk_14 = 44;
    desc->unk_18 = desc->unk_10;
    *out = func_82604720(out + 1, *(u16 *)(state + 8), *(s16 *)(state + 0xA), *(s8 *)(state + 0xF));
}

extern s32 func_8004C990(s32, s32);
extern s32 func_82604814(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_826049A0(s32 *arg0, s32 arg1);
extern s32 func_82604A78(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_82604CF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s16 D_82615504[];
void func_82605218(void *arg0, void *arg1) {
    unk_func_82605110 *desc = arg1;
    u8 *state;
    s32 offset;
    s32 *out;
    s32 is_first;

    state = **(u8 ***)((u8 *)arg0 + 0x110);
    offset = *(s16 *)((u8 *)arg0 + 0x16);
    is_first = *(s16 *)arg0 == 1;
    desc->unk_10.unk_00 = 0;
    desc->unk_10.unk_02 = 480;
    desc->unk_14 = 44;
    desc->unk_24 = 554;
    desc->unk_26 = D_82615504[desc->unk_00];
    if (is_first) {
        desc->unk_16 = 240;
    } else {
        desc->unk_16 = func_82604CF0((s32)((u8 *)arg0 + 0x3544), *(s16 *)((u8 *)arg0 + 0x14), desc->unk_00, desc->unk_02) + offset;
    }
    desc->unk_18 = desc->unk_10;
    if (is_first) {
        out = (s32 *)desc->unk_30;
        out[out[0] + 1] = func_8004C990(89, 0);
        out[0]++;
    } else {
        out = (s32 *)desc->unk_30;
        switch (*(u16 *)(state + 8) & 0xFF00) {
            case 0:
                out[0] = func_82604814(out + 1, *(s16 *)(state + 0xA), *(s16 *)(state + 0x88), *(s16 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x14));
                break;
            case 0x100:
            case 0x200:
            case 0x700:
                out[0] = func_826049A0(out + 1, *(u16 *)(state + 8));
                break;
            case 0x300:
                out[0] = func_82604A78(out + 1, *(s16 *)(state + 0xA), *(s16 *)(state + 0x88), *(s16 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x14));
                break;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826053A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826057A8.s")

s32 func_826058CC(s32 arg0) {
    s32 result;

    switch (arg0) {
    case 0:
    case 4:
        result = 0;
        break;
    case 1:
    case 3:
        result = 1;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82605908.s")

extern s16 D_82615504[];
void func_82605E04(void *arg0, void *arg1) {
    unk_func_82605110 *desc = arg1;
    u8 *state;
    s16 count;
    s32 quotient;
    s32 remainder;
    s16 *range;

    state = **(u8 ***)((u8 *)arg0 + 0x110);
    count = *(s16 *)(state + 0x88);
    quotient = *(s16 *)(state + 0x88) / 4; // FAKE: count
    remainder = count % 4;
    desc->unk_10.unk_00 = 0;
    desc->unk_14 = 44;
    if (desc->unk_02 == 0) {
        desc->unk_10.unk_02 = -480;
        desc->unk_16 = 41;
    } else {
        desc->unk_10.unk_02 = 480;
        desc->unk_16 = 242;
    }
    desc->unk_18 = desc->unk_10;
    desc->unk_24 = 554;
    desc->unk_26 = D_82615504[desc->unk_00];
    range = desc->unk_30;
    if (desc->unk_02 < quotient) {
        range[0] = 4;
        range[1] = -1;
    } else if (quotient < desc->unk_02) {
        range[0] = 0;
        range[1] = -1;
    } else {
        range[0] = remainder + 1;
        range[1] = remainder;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82605EF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82605FE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826063AC.s")

typedef struct { s16 a; s16 b; } Pair16_6548;
extern s16 D_82615504[];
typedef struct {
    s16 f0; s16 f2; u16 f4; s16 f6; s16 f8; s16 fA; s16 fC; s16 fE;
    Pair16_6548 f10; Pair16_6548 f14; Pair16_6548 f18;
    s16 f1C; s16 f1E; s16 f20; s16 f22; s16 f24; s16 f26;
} Rec6548;
void func_82606548(void *arg0, void *arg1) {
    u8 *p = arg1;
    *(s16 *)(p + 0x10) = 0;
    *(u16 *)(p + 4) &= 0xFFFE;
    *(s16 *)(p + 0x12) = -0x1E0;
    *(Pair16_6548 *)(p + 0x18) = *(Pair16_6548 *)(p + 0x10);
    *(s16 *)(p + 0x14) = 0;
    *(s16 *)(p + 0x16) = 0;
    *(s16 *)(p + 0x24) = 0x197;
    *(s16 *)(p + 0x26) = D_82615504[*(s16 *)(p + 0)];
    *(s16 *)(p + 0x14) = 0x74;
    *(s16 *)(p + 0x16) = 0x4B;
}

extern s32 func_82604C98(s32, s32, s32, s32);

extern void _bzero(void *, s32);
extern void func_82604D40(void *, void *);
extern void func_82605110(void *, void *);
extern void func_82605218(void *, void *);
extern void func_826053A4(void *, void *);
extern void func_826057A8(void *, void *);
extern void func_82605908(void *, void *);
extern void func_82605E04(void *, void *);
extern void func_82605EF4(void *, void *);
extern void func_82605FE4(void *, void *);
extern void func_826063AC(void *, void *);
extern void func_82606548(void *, void *);
void func_826065B0(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *pool;
    pool = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x110));
    _bzero(arg1, 0x298);
    *(s16 *)((u8 *)arg1 + 0) = arg2;
    *(u16 *)((u8 *)arg1 + 4) |= 1;
    *(u16 *)((u8 *)arg1 + 4) |= 2;
    *(u16 *)((u8 *)arg1 + 4) |= 4;
    if (*(s8 *)(pool + 0xF) != 0) *(u16 *)((u8 *)arg1 + 4) |= 8;
    *(s16 *)((u8 *)arg1 + 2) = arg3;
    *(s16 *)((u8 *)arg1 + 6) = 0;
    *(s16 *)((u8 *)arg1 + 0xA) = func_82604C98((s32)((u8 *)arg0 + 0x3544), *(s16 *)((u8 *)arg0 + 0x14), *(s16 *)((u8 *)arg1 + 0), *(s16 *)((u8 *)arg1 + 2));

    switch (*(s16 *)((u8 *)arg1 + 0)) {
    case 1: func_82604D40(arg0, arg1); break;
    case 2: func_82605110(arg0, arg1); break;
    case 3: func_82605218(arg0, arg1); break;
    case 4: func_826053A4(arg0, arg1); break;
    case 5: func_826057A8(arg0, arg1); break;
    case 6: func_82605908(arg0, arg1); break;
    case 7: func_82605E04(arg0, arg1); break;
    case 8: func_82605EF4(arg0, arg1); break;
    case 9: func_82605FE4(arg0, arg1); break;
    case 10: func_826063AC(arg0, arg1); break;
    case 11: func_82606548(arg0, arg1); break;
    }
}

void func_8260675C(u8 *arg0) {
    if (arg0 != NULL && *(s16 *)(arg0 + 6) == 0) {
        *(s16 *)(arg0 + 6) = 1;
        *(s16 *)(arg0 + 8) = 0;
    }
}

extern void func_800226C0(s32);
void func_82606784(u8*a0,s32 a1,s32 a2,s32 a3){if(*(s16*)(a0+6)==0){*(s16*)(a0+6)=1;*(s16*)(a0+8)=0;*(s16*)(a0+0x1C)=a1;*(s16*)(a0+0x1E)=a3;*(s16*)(a0+0x20)=a2;*(s16*)(a0+0x22)=a3;func_800226C0(0x6D);}}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826067D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82606B28.s")

extern s32 D_826155C8;
extern s32 D_826155CC;
extern s32 D_826155D0;
extern s32 D_826155D4;
void func_82606CE8(u8 *arg0) {
    u8 *sub;
    s32 duration;
    s32 stagger;
    s32 delay;
    s32 i;
    s32 t;
    s16 prev;

    sub = arg0 + 0x30;
    if (*(s16 *)(sub + 4) != 0) {
        duration = D_826155CC;
        stagger = D_826155D4;
    } else {
        duration = D_826155C8;
        stagger = D_826155D0;
    }
    delay = 0;
    if (*(s16 *)(arg0 + 8) < 0x800) {
        (*(s16 *)(arg0 + 8))++;
    }
    for (i = 0; i < *(s16 *)(sub + 6); delay += stagger, i++) {
        t = *(s16 *)(arg0 + 8) - delay;
        prev = ((s16 *)sub)[((s16 *)sub)[i + 22] + 10];
        if (t < 0) {
            t = 0;
        } else if (duration < t) {
            t = duration;
        }
        ((s16 *)sub)[((s16 *)sub)[i + 22] + 10] = 255 - t * 255 / duration;
        if (*(s16 *)(arg0 + 2) == 0 && prev == 255 && ((s16 *)sub)[((s16 *)sub)[i + 22] + 10] < 255) {
            if (i != *(s16 *)(sub + 6)) {
                func_800226C0(103);
            } else {
                func_800226C0(104);
            }
        }
    }
}

typedef struct unk_func_82606E90 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
} unk_func_82606E90;

unk_func_82606E90* func_82606E90(unk_func_82606E90* arg0) {
    unk_func_82606E90* result = NULL;
    s32 i;
    unk_func_82606E90* entry;

    for (i = 0; i < 40; i++) {
        entry = &arg0[i];
        if (entry->unk_00 == 0) {
            result = entry;
            break;
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82606EC8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82607528.s")

typedef struct { s16 a; s16 b; } Pair16_7734;
void func_82607734(void *arg0, s32 arg1) {
    u8 *p = arg0;
    if (*(s16 *)(p + 6) == 2) {
        *(s16 *)(p + 6) = 3;
        *(s16 *)(p + 8) = 0;
        *(Pair16_7734 *)(p + 0x1C) = *(Pair16_7734 *)(p + 0x14);
        *(s16 *)(p + 0x20) = *(s16 *)(p + 0x14);
        *(s16 *)(p + 0x22) = (s16)(((0x1E0 - *(s16 *)(p + 0x26)) / 2) - arg1);
    }
}

extern s32 D_82615600;
typedef struct unk_func_82607790_pair {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} unk_func_82607790_pair;
typedef struct unk_func_82607790 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02[2];
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A[5];
    /* 0x14 */ unk_func_82607790_pair unk_14;
    /* 0x18 */ s16 unk_18[2];
    /* 0x1C */ unk_func_82607790_pair unk_1C;
    /* 0x20 */ unk_func_82607790_pair unk_20;
    /* 0x24 */ s16 unk_24[7];
    /* 0x32 */ s16 unk_32;
} unk_func_82607790;
void func_82607790(unk_func_82607790 *arg0) {
    s32 total;
    s32 step;

    step = 0; // FAKE
    if (1) { // FAKE
        total = D_82615600;
        arg0->unk_08++;
    }
    step = arg0->unk_08;
    if (step < total) {
        arg0->unk_14.unk_00 = (arg0->unk_20.unk_00 - arg0->unk_1C.unk_00) * step / total + arg0->unk_1C.unk_00;
        arg0->unk_14.unk_02 = (arg0->unk_20.unk_02 - arg0->unk_1C.unk_02) * step / total + arg0->unk_1C.unk_02;
    } else {
        arg0->unk_06 = 2;
        arg0->unk_14 = arg0->unk_20;
        arg0->unk_08 = 0;
        if (arg0->unk_00 == 1 && arg0->unk_32 != -1) {
            func_800226C0(108);
        }
    }
}

extern s32 D_8261A5A0;
extern u16 D_8261A494;
extern s16 D_8261A490;
void func_826078B4(void *arg0) {
    s16 *entry = arg0;
    s32 is_one;

    is_one = D_8261A490 == 1;
    if (entry != NULL && entry[3] == 2) {
        entry[3] = 4;
        entry[4] = 0;
        switch (entry[0]) {
            case 1:
                if (entry[25] == -1) {
                    if (!(entry[5] & 1)) {
                        entry[12] = -640;
                    } else {
                        entry[12] = 640;
                    }
                } else {
                    entry[12] = -640;
                }
                entry[13] = 0;
                break;
            case 3:
                if (!(entry[5] & 1)) {
                    entry[12] = -640;
                } else {
                    entry[12] = 640;
                }
                entry[13] = 0;
                break;
            case 2:
                if (is_one) {
                    entry[12] = -640;
                } else if (!(entry[5] & 1)) {
                    entry[12] = -640;
                } else {
                    entry[12] = 640;
                }
                entry[13] = 0;
                break;
            case 5:
                entry[12] = 640;
                entry[13] = 0;
                break;
            case 4:
            case 7:
                if (entry[1] & 1) {
                    entry[12] = 640;
                } else {
                    entry[12] = -640;
                }
                entry[13] = 0;
                break;
            case 6:
                if ((entry[1] & 1) == 1) {
                    if (*(s32 *)(D_8261A5A0 + 0xC) != 0 && !(D_8261A494 & 0x800)) {
                        entry[12] = -640;
                    } else {
                        entry[12] = 640;
                    }
                } else {
                    entry[12] = -640;
                }
                entry[13] = 0;
                break;
            case 8:
                entry[12] = -640;
                entry[13] = 0;
                break;
            case 9:
                entry[12] = 640;
                entry[13] = 0;
                break;
            case 10:
                entry[12] = -640;
                entry[13] = 0;
                break;
            case 11:
                entry[12] = -640;
                entry[13] = 0;
                break;
        }
    }
}

extern s32 D_82615604;
void func_82607AA0(s16 *arg0) {
    s32 total;
    s32 step;

    step = 0; // FAKE
    if (1) { // FAKE
        total = D_82615604;
        arg0[4]++;
    }
    step = arg0[4];
    if (step < total) {
        arg0[8] = (arg0[12] * step) / total;
        arg0[9] = (arg0[13] * step) / total;
    } else {
        arg0[3] = 0;
        arg0[4] = 0;
        arg0[6] = 0;
        arg0[7] = 0;
        arg0[8] = 0;
        arg0[9] = 0;
    }
}

extern void func_826067D4();
extern void func_82607528();
void func_82607B74(void *arg0) {
    s16 temp_v0;

    temp_v0 = (*(s16 *)((u8 *)(arg0) + (6)));
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_826067D4();
        return;
    case 2:
        func_82607528();
        return;
    case 3:
        func_82607790(arg0);
        return;
    case 4:
        func_82607AA0(arg0);
        return;
    }
}

extern u8 D_82615608[];
extern u8 D_8261560C[];
extern u8 D_82615610[];
extern u8 D_82615614[];
extern u8 D_82615618[];
extern u8 D_8261561C[];
extern u8 D_82615620;
extern u8 D_82615621;
extern u8 D_82615622;
extern u8 D_82615624;
extern u8 D_82615625;
extern u8 D_82615626;
void func_82607BF4(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    u8 *from_prim;
    u8 *from_env;
    s32 max = 255;

    if (arg0 == 11) {
        from_prim = D_82615618;
        from_env = D_8261561C;
    } else if (arg4 != 0) {
        from_prim = D_82615610;
        from_env = D_82615614;
    } else {
        from_prim = D_82615608;
        from_env = D_8261560C;
    }
    arg1[0] = from_prim[0] + (D_82615620 - from_prim[0]) * arg3 / max;
    arg1[1] = from_prim[1] + (D_82615621 - from_prim[1]) * arg3 / max;
    arg1[2] = from_prim[2] + (D_82615622 - from_prim[2]) * arg3 / max;
    arg2[0] = from_env[0] + (D_82615624 - from_env[0]) * arg3 / max;
    arg2[1] = from_env[1] + (D_82615625 - from_env[1]) * arg3 / max;
    arg2[2] = from_env[2] + (D_82615626 - from_env[2]) * arg3 / max;
}

extern u8 D_82615628;
extern u8 D_82615629;
extern u8 D_8261562A;
extern u8 D_8261562C;
extern u8 D_8261562D;
extern u8 D_8261562E;
void func_82607E40(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    register s32 b0;
    register s32 b1;
    register s32 b2;
    register s32 b3;

    b0 = D_82615628;
    arg0[0] = (((arg2[0] - b0) * arg4) / 255) + b0;
    arg0[1] = (((arg2[1] - (b1 = D_82615629)) * arg4) / 255) + b1;
    arg0[2] = (((arg2[2] - (b2 = D_8261562A)) * arg4) / 255) + b2;
    arg1[0] = (((arg3[0] - (b3 = D_8261562C)) * arg4) / 255) + b3;
    arg1[1] = (((arg3[1] - D_8261562D) * arg4) / 255) + D_8261562D;
    arg1[2] = (((arg3[2] - D_8261562E) * arg4) / 255) + D_8261562E;
}

extern u8 D_82615630;
extern u8 D_82615631;
extern u8 D_82615632;
extern u8 D_82615634;
extern u8 D_82615635;
extern u8 D_82615636;
extern u8 D_82615638;
extern u8 D_82615639;
extern u8 D_8261563A;
extern u8 D_8261563C;
extern u8 D_8261563D;
extern u8 D_8261563E;
void func_82608054(u8 *arg0, u8 *arg1, s32 arg2) {
    arg0[0] = (((D_82615638 - D_82615630) * arg2) / 255) + D_82615630;
    arg0[1] = (((D_82615639 - D_82615631) * arg2) / 255) + D_82615631;
    arg0[2] = (((D_8261563A - D_82615632) * arg2) / 255) + D_82615632;
    arg1[0] = (((D_8261563C - D_82615634) * arg2) / 255) + D_82615634;
    if (0) { }
    arg1[1] = (((D_8261563D - D_82615635) * arg2) / 255) + D_82615635;
    arg1[2] = (((D_8261563E - D_82615636) * arg2) / 255) + D_82615636;
}

typedef struct { u8 r; u8 g; u8 b; } Color82608270;
extern Color82608270 D_82615640;
extern Color82608270 D_82615644[];
void func_82608270(Color82608270 *arg0, Color82608270 *arg1, s32 arg2) {
    *arg0 = D_82615640;
    *arg1 = D_82615644[arg2];
}

typedef struct unk_func_826082C0_rgb {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
} unk_func_826082C0_rgb;
extern unk_func_826082C0_rgb D_8261565C;
extern u8 D_82615660[];
void func_826082C0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 *row;
    s32 step;
    s32 steps;

    *(unk_func_826082C0_rgb *)arg0 = D_8261565C;
    if (arg3 < 3) {
        steps = 3;
        row = D_82615660 + arg2 * 9;
        arg1[0] = (row[3] - row[0]) * arg3 / steps + row[0];
        arg1[1] = (row[4] - row[1]) * arg3 / steps + row[1];
        arg1[2] = (row[5] - row[2]) * arg3 / steps + row[2];
    } else {
        step = arg3 - 3;
        steps = 6;
        row = D_82615660 + arg2 * 9;
        arg1[0] = (row[6] - row[3]) * step / steps + row[3];
        arg1[1] = (row[7] - row[4]) * step / steps + row[4];
        arg1[2] = (row[8] - row[5]) * step / steps + row[5];
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260850C.s")

extern Gfx *D_800D0510;
extern u8 D_80094E78[];
extern s32 func_8004D1FC(u8 *);
extern void func_82607BF4(s32, u8 *, u8 *, s32, s32);
extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
void func_8260899C(u8 *arg0, s32 arg1) {
    u8 *tex;
    s32 unused[2];
    f32 step;
    f32 bias;
    s16 x;
    s16 y;
    struct Color { u8 r, g, b, a; } prim;
    struct Color2 { u8 r, g, b, a; } env;
    s32 w;
    s32 h;
    f32 scale;

    tex = (u8 *)func_8004C990(0x52, 1);
    if (tex == NULL) {
        return;
    }

    w = *(s16 *)(arg0 + 0x24) - 10;
    h = *(s16 *)(arg0 + 0x26) - 10;
    scale = (f32)w / (f32)(u32)*(u16 *)tex;
    if (scale > 0.0f && w > 0 && h > 0) {
        if (arg1 != 0) {
            gSPDisplayList(D_800D0510++, D_80094E78);
            gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
            func_8004D1FC(tex);
        }

        func_82607BF4(*(s16 *)arg0, (u8 *)&prim, (u8 *)&env, *(s16 *)(arg0 + 0xC), (*(u16 *)(arg0 + 4) & 8) != 0);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, prim.r, prim.g, prim.b, 255);
        step = 1024.0f / scale;
        gDPSetPrimColor(D_800D0510++, 0, 0, env.r, env.g, env.b, 255);

        x = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
        y = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);

        bias = (step > 0.0f) ? 0.5f : -0.5f;

        func_80044270((s16)(x + 5), (s16)(y + 5), *(s16 *)(arg0 + 0x24) - 10, *(s16 *)(arg0 + 0x26) - 10, 0, 0, (s32)(bias + step), 0x400, 0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82608C1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82608EC4.s")

extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
void func_826090F4(u8 *arg0, s32 arg1) {
    u8 *tex;
    s32 i;
    s16 x; // FAKE: unused, reserves the stack slot retail has
    struct { s16 x, y; } pos;
    struct Color { u8 r, g, b, a; } prim;
    struct Color2 { u8 r, g, b, a; } env;
    s16 y;
    u16 width;

    tex = (u8 *)func_8004C990(84, 0);
    pos.x = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
    pos.y = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);
    if (arg1 != 0) {
        gSPDisplayList(D_800D0510++, D_80094E78);
        gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
        func_8004D1FC(tex);
    }
    func_82607BF4(*(s16 *)arg0, (u8 *)&prim, (u8 *)&env, *(s16 *)(arg0 + 0xC), (*(u16 *)(arg0 + 4) & 8) != 0);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, prim.r, prim.g, prim.b, 255);
    gDPSetPrimColor(D_800D0510++, 0, 0, env.r, env.g, env.b, 255);
    y = pos.y + 36;
    for (i = 0; i < 4; i++) {
        GfxRect_DrawTextured(pos.x + i * 135 + 27, y, *(s16 *)tex, *(s16 *)(tex + 2), 0, 0, 1024, 1024, 0);
        width = *(u16 *)tex;
        GfxRect_DrawTextured(pos.x + i * 135 + width + 27, y, width, *(s16 *)(tex + 2), (width - 1) << 5, 0, -1024, 1024, 0);
    }
}

/* mkdraft:func_8260933C begin */
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern s16 D_826156A8[];
extern s16 D_8261DA4C;
extern s16 D_8261DA4E;
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);



void func_8260933C(u8 *arg0, s32 arg1) {
    s32 i;
    u8 *border;
    s32 k;
    s32 tex;
    s32 x;
    s32 y;
    s16 cx;
    s16 cy;

    border = arg0 + 0x30;
    cx = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
    cy = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);
    if (arg1 != 0) {
        gSPDisplayList(D_800D0510++, D_80094E38);
    }
    for (i = 0; i < *(s16 *)border; i++) {
        k = *(s16 *)(arg0 + 2) * 4 + i;
        tex = func_8004C990(0x56, D_826156A8[k]);
        gDPPipeSync(D_800D0510++);
        switch (D_8261DA4C) {
        case 6:
            gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
            x = cx + i * 135 + 35;
            y = cy + 36;
            break;
        case 5:
            x = cx + i * 135 + 35;
            y = cy + 36;
            if (i != *(s16 *)(border + 2)) {
                gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
            } else {
                gDPSetRenderMode(D_800D0510++, 0x504240, 0);
                gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255 - D_8261DA4E);
            }
            break;
        default:
            if (i != *(s16 *)(border + 2)) {
                x = cx + i * 135 + 35;
                y = cy + 36;
            } else {
                continue;
            }
            break;
        }
        func_8004D19C(x, y, tex, 0, 0);
    }
}
/* mkdraft:func_8260933C end */

typedef struct unk_func_82609584_rgb {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
} unk_func_82609584_rgb;
extern unk_func_82609584_rgb D_826156B8;
extern unk_func_82609584_rgb D_826156BC;
extern void func_800459AC();
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern u8 *func_8004CA60(u8 *);
void func_82609584(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *texture;
    unk_func_82609584_rgb *color;
    unk_func_82609584_rgb on;
    unk_func_82609584_rgb off;
    s32 i;

    if (arg2 != 0) {
        texture = func_8004CA60((u8 *)arg2);
        on = D_826156B8;
        off = D_826156BC;
        if (arg3 != 0) {
            color = &on;
        } else {
            color = &off;
        }
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, color->r, color->g, color->b, 255);
        for (i = 0; i < 2; i++) {
            func_800459AC(texture + i * 0x1000, *(u8 *)(arg2 + 4), *(u8 *)(arg2 + 5), *(u16 *)arg2, 32, 1, 0, 2, 2, 0, 0, 0, 0);
            GfxRect_DrawTextured(arg0, arg1 + i * 64, *(u16 *)arg2 * 2, 64, 0, 0, 512, 512, 0);
        }
    }
}

extern Gfx *D_800D0510;
extern u8 D_80094E38[];

void func_82609730(void *arg0, s32 arg1) {
    s16 temp_s5;
    s16 temp_s6;
    s32 temp_a2;
    s32 var_s0;
    u8 *temp_a3;
    u8 *var_s1;
    u8 *var_s2;
    temp_a3 = (u8 *)arg0 + 0x30;
    if (arg1 != 0) {
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
    }
    temp_s5 = *(s16 *)((u8 *)arg0 + 0x14) + *(s16 *)((u8 *)arg0 + 0x10);
    temp_s6 = *(s16 *)((u8 *)arg0 + 0x16) + *(s16 *)((u8 *)arg0 + 0x12);
    var_s0 = 0;
    if (*(s16 *)(temp_a3 + 4) > 0) {
        var_s1 = temp_a3;
        var_s2 = temp_a3;
        do {
            temp_a2 = *(s32 *)(var_s2 + 0x24);
            if ((*(s16 *)(var_s1 + 0xA) < 0xFF) && (temp_a2 != 0)) {
                func_82609584(temp_s5 + (var_s0 * 0x86) + 0xB, temp_s6 + 9, temp_a2, *(s16 *)(var_s1 + 0x12));
            }
            var_s0 += 1;
            var_s1 += 2;
            var_s2 += 4;
        } while (var_s0 < *(s16 *)(temp_a3 + 4));
    }
}

extern s16 D_826156C0[];
extern s16 D_826156C4[];
void func_82609868(void *arg0, s32 arg1, s32 arg2) {
    s16 temp_s6;
    s16 temp_s5;
    s32 index;
    if (arg2 != 0) {
        if (arg1 != 0) {
            gSPDisplayList(D_800D0510++, D_80094E38);
            gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
        }
        index = *(s16 *)((u8 *)arg0 + 2) * 2;
        temp_s5 = *(s16 *)((u8 *)arg0 + 0x14) + *(s16 *)((u8 *)arg0 + 0x10);
        temp_s6 = *(s16 *)((u8 *)arg0 + 0x16) + *(s16 *)((u8 *)arg0 + 0x12);
        func_82609584(*(s16 *)((u8 *)D_826156C0 + index) + temp_s5, *(s16 *)((u8 *)D_826156C4 + index) + temp_s6, arg2, 1);
    }
}

extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern void func_80046204(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_82609938(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    if (arg4 > 0) {
        do {
            temp_v0 = arg4 - var_s1;
            if (temp_v0 < arg5) var_s0 = temp_v0;
            else var_s0 = arg5;
            func_80046204((arg3 * var_s1 * 2) + arg2, 0, 2, arg3, var_s0, 0, 0, arg3, var_s0 - 1, 0, 2, 2, 0, 0, 0, 0);
            func_80044270((s16)arg0, (s16)(arg1 + var_s1), (s16)arg3, (s16)var_s0, 0, 0, 0x400, 0x400, 0);
            var_s1 += arg5;
        } while (var_s1 < arg4);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82609A88.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82609D84.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260A0B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260A6B4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260AF30.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260B424.s")

/* mkdraft:func_8260B8CC begin */
extern s32 func_8004C990(s32, s32);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

void func_8260B8CC(s32 x, s32 y, s32 width, s32 height) {
    s32 resource;
    s32 tile_width;
    s32 tile_height;

    resource = func_8004C990(81, 0);
    tile_width = ((u16 *)resource)[0];
    tile_height = ((u16 *)resource)[1];
    tile_width /= 4;
    GfxRect_DrawTextured(x, y, tile_width, tile_height, 0, 0, 1024, 1024, 0);
    GfxRect_DrawTextured(x + tile_width, y, width - tile_width * 2, tile_height,
                  tile_width << 5, 0, 0, 1024, 0);
    GfxRect_DrawTextured(x + width - tile_width, y, tile_width, tile_height,
                  tile_width << 5, 0, 1024, 1024, 0);
    GfxRect_DrawTextured(x, y + tile_height, tile_width, height - tile_height * 2,
                  (tile_width * 2) << 5, 0, 1024, 0, 0);
    GfxRect_DrawTextured(x, y + height - tile_height, tile_width, tile_height,
                  (tile_width * 2) << 5, 0, 1024, 1024, 0);
    GfxRect_DrawTextured(x + tile_width, y + height - tile_height,
                  width - tile_width * 2, tile_height,
                  (tile_width * 3) << 5, 0, 0, 1024, 0);
    GfxRect_DrawTextured(x + width - tile_width, y + height - tile_height,
                  tile_width, tile_height, (tile_width * 3) << 5, 0, 1024, 1024, 0);
    GfxRect_DrawTextured(x + width - tile_width, y + tile_height,
                  tile_width, height - tile_height * 2,
                  (tile_width * 3) << 5, 0, 1024, 0, 0);
}
/* mkdraft:func_8260B8CC end */

extern s32 func_8004D1FC(u8 *);
extern void func_82607BF4(s32, u8 *, u8 *, s32, s32);
extern void func_8260B8CC(s32, s32, s32, s32);
extern u8 D_80094E78[];
extern s32 func_8004C990(s32, s32);
extern Gfx * D_800D0510;
void func_8260BBA8(void *arg0, s32 arg1) {
    s32 temp_v0;
    s16 sp4A;
    s16 sp48;
    struct Color { u8 r; u8 g; u8 b; u8 a; } sp44;
    struct Color2 { u8 r; u8 g; u8 b; u8 a; } sp40;

    temp_v0 = func_8004C990(0x51, 0);
    if (temp_v0 != 0) {
        sp48 = *(s16 *)((u8 *)arg0 + 0x14) + *(s16 *)((u8 *)arg0 + 0x10);
        sp4A = *(s16 *)((u8 *)arg0 + 0x16) + *(s16 *)((u8 *)arg0 + 0x12);
        if (arg1 != 0) {
            gSPDisplayList(D_800D0510++, D_80094E78);
            gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
            func_8004D1FC((u8 *)temp_v0);
        }
        func_82607BF4(*(s16 *)arg0, (u8 *)&sp44, (u8 *)&sp40,
                      *(s16 *)((u8 *)arg0 + 0xC),
                      (*(u16 *)((u8 *)arg0 + 4) & 8) != 0);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, sp44.r, sp44.g, sp44.b, 0xFF);
        gDPSetPrimColor(D_800D0510++, 0, 0, sp40.r, sp40.g, sp40.b, 0xFF);
        func_8260B8CC(sp48 + 0x36, sp4A + 0x24, 0x12C, 0x61);
        func_8260B8CC(sp48 + 0x36, sp4A + 0xAC, 0x12C, 0x52);
    }
}

extern u8 D_80094D90[];
extern void Gfx_FillRectRgb(s16, s16, s16, s16, u8, u8, u8);
void func_8260BD50(u8 *arg0, s32 arg1) {
    s16 x = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
    s16 y = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);
    s32 i;

    if (arg1 != 0) {
        gSPDisplayList(D_800D0510++, D_80094D90);
    }

    for (i = 0; i < 142; i += 71) {
        Gfx_FillRectRgb(x + 21, y + 45 + i, 261, 57, 0, 0, 0);
    }
}

extern Gfx *D_800D0510;
extern u8 D_80094D90[];
extern void Gfx_FillRectRgb(s16, s16, s16, s16, u8, u8, u8);

void func_8260BE24(u8 *arg0, s32 arg1) {
    s16 pad;
    s16 temp_t1;
    s16 temp_t0;
    temp_t1 = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
    temp_t0 = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);
    if (arg1 != 0) {
        gSPDisplayList(D_800D0510++, D_80094D90);
    }
    Gfx_FillRectRgb(temp_t1 + 0x3A, temp_t0 + 0x28, 0x124, 0x59, 0, 0, 0);
    Gfx_FillRectRgb(temp_t1 + 0x3A, temp_t0 + 0xB0, 0x124, 0x4A, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260BEF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260C2B0.s")

extern void func_8004D150(s32, s32, s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
extern u8 D_80094E78[];
extern Gfx * D_800D0510;
void func_8260C7D4(void *arg0, s32 arg1) {
    s16 y; s16 x; s32 result; void *base; s32 index; s32 stride;
    base = (u8 *)arg0 + 0x30; stride = 0x86; result = func_8004C990(0x58, 1);
    x = *(s16 *)((u8 *)arg0 + 0x14) + *(s16 *)((u8 *)arg0 + 0x10);
    y = *(s16 *)((u8 *)arg0 + 0x16) + *(s16 *)((u8 *)arg0 + 0x12);
    if (arg1 != 0) { gSPDisplayList(D_800D0510++, D_80094E78); gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0); }
    gDPPipeSync(D_800D0510++); gDPSetEnvColor(D_800D0510++, 255,255,255,255); gDPSetPrimColor(D_800D0510++,0,0,0x32,0,0,255);
    index = 0; if (*(s16 *)((u8 *)base + 4) > 0) do {
        if (*(s16 *)((u8 *)base + index * 2 + 0x54) != 0 && *(s16 *)((u8 *)base + index * 2 + 0xA) < 0xFF) func_8004D150(x + stride * index + 0x1B, y + 0x1B, result, 0, 0x100, 0);
        index++;
    } while (index < *(s16 *)((u8 *)base + 4));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260C988.s")

extern u8 *func_8004CA60(u8 *);
extern void func_800459AC();
extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
extern void func_82607BF4(s32, u8 *, u8 *, s32, s32);
extern u8 D_80094E78[];
extern Gfx * D_800D0510;
void func_8260CC24(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *base;
    u8 *tex;
    s32 i;
    s32 value;
    struct Color { u8 r,g,b,a; } prim;
    struct Color2 { u8 r,g,b,a; } env;
    s32 clipped;
    s32 amount;
    s16 x;
    s16 y;
    s32 unused[2];
    base = arg0 + 0x30;
    tex = (u8 *)func_8004C990(0x51, 2);
    if (tex == NULL) return;
    if (arg1 == 0 && arg2 != 0) {
        gSPDisplayList(D_800D0510++, D_80094E78);
        gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
    }
    if (arg2 != 0) {
        u8 *pixels = func_8004CA60(tex);
        func_800459AC(pixels + ((*(u16 *)tex * 0x3E * arg1) / 2), tex[4], tex[5], *(u16 *)tex, 62U, 1, 0, 2, 2, 0, 0, 0, 0);
    }
    if (arg1 == 0) {
        func_82607BF4(*(s16 *)arg0, (u8 *)&prim, (u8 *)&env, *(s16 *)(arg0 + 0xC), (*(u16 *)(arg0 + 4) & 8) != 0);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, prim.r, prim.g, prim.b, 255);
        gDPSetPrimColor(D_800D0510++, 0, 0, env.r, env.g, env.b, 255);
    }
    x = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
    y = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);
    for (i = 0; i < *(s16 *)(base + 4); i++) {
        value = (*(u16 *)(tex + 2) * *(s16 *)(base + 0xA + i * 2)) / 255;
        clipped = value >= 0x3E ? 0x3E : value;
        amount = arg1 == 0 ? value - clipped : clipped;
        if (amount > 0) {
            func_80044270((s16)(x + i * 0x86 + 0xB), (s16)(y + (value - clipped) * arg1 + 9), *(s16 *)tex, (s16)amount, 0, (0x3E - amount) << 5, 0x400, 0x400, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260CF84.s")

s32 func_8004C990(s32, s32);

s32 func_8260D3F4(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_v0;

    if (arg0 != 0) {
        var_v0 = func_8004C990(0x6D, 1);
    } else {
        var_v0 = func_8004C990(0x6D, 0);
    }
    return var_v0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260D440.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260D820.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260DB98.s")

typedef struct unk_func_8260DD84_entry {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} unk_func_8260DD84_entry; // size = 0xC

typedef struct unk_func_8260DD84 {
    /* 0x00 */ u8 unk_00[0x16];
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ unk_func_8260DD84_entry unk_20[40];
} unk_func_8260DD84;

extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
extern void func_82608054(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 D_80094E78[];
extern Gfx * D_800D0510;
void func_8260DD84(u8 *arg0, s32 arg1) {
    u8 *tex;
    s32 i;
    struct Color { u8 r, g, b, a; } prim;
    struct Color2 { u8 r, g, b, a; } env;
    s16 y;
    unk_func_8260DD84_entry *entry;
    s16 x;
    unk_func_8260DD84 *sub;
    s32 flag;

    tex = (u8 *)func_8004C990(103, 0);
    flag = 0;
    x = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
    y = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);
    sub = (unk_func_8260DD84 *)(arg0 + 0x30);
    if (arg1 != 0) {
        gSPDisplayList(D_800D0510++, D_80094E78);
    }
    if (sub->unk_18 != 0 && sub->unk_18 != 3) {
        flag = 1;
    }
    if (tex == NULL || flag == 0 || sub->unk_16 == 0 || sub->unk_1E <= 0) {
        return;
    }
    func_82608054((u8 *)&prim, (u8 *)&env, sub->unk_1C);
    for (i = 0; i < 40; i++) {
        entry = &sub->unk_20[i];
        if (entry->unk_00 != 0) {
            gDPPipeSync(D_800D0510++);
            gDPSetEnvColor(D_800D0510++, prim.r, prim.g, prim.b, entry->unk_04);
            gDPSetPrimColor(D_800D0510++, 0, 0, env.r, env.g, env.b, 255);
            func_8004D19C(x + entry->unk_08, y + entry->unk_0A, (s32)tex, 1, 0);
        }
    }
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, prim.r, prim.g, prim.b, sub->unk_1E);
    gDPSetPrimColor(D_800D0510++, 0, 0, env.r, env.g, env.b, 255);
    func_8004D19C(x + 74, y + 144, (s32)tex, 1, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260E03C.s")

extern void Ui_DrawAnimatedTextureMarker(s16, s16);
extern s16 D_8261A4AE;
void func_8260E140(u8 *arg0, s32 arg1) {
    s16 x;
    s16 y;

    x = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 0x10);
    y = *(s16 *)(arg0 + 0x16) + *(s16 *)(arg0 + 0x12);
    Ui_DrawAnimatedTextureMarker((s16)(x + 0x3C), (s16)(y + D_8261A4AE * 0x1F + 0xBC));
}

extern void func_800498C4(void);
extern void func_800499EC(void);
void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
void func_800496A4(s32 a0, s32 a1);
void func_8004989C(s32 arg0);
extern void func_800495BC(s32, s32, s32 *);
extern u8 D_82615738[];
extern u8 D_8261573C[];
extern u8 D_82615740[];
void func_8260E1B4(void *arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 arg4) {
    s16 sp26;
    s16 sp24;
    s32 idx;
    s32 idx2;

    sp24 = *(s16 *)((u8 *)arg0 + 0x14) + *(s16 *)((u8 *)arg0 + 0x10);
    sp26 = *(s16 *)((u8 *)arg0 + 0x16) + *(s16 *)((u8 *)arg0 + 0x12);
    func_800498C4();
    func_8004972C(0xFF, 0xFF, 0xFF, arg4);
    func_800496A4(4, 0);
    func_8004989C(0x10);
    if (arg2 != NULL) {
        idx = *(s16 *)((u8 *)arg0 + 2) * 2;
        func_800495BC(*(s16 *)(D_82615738 + idx) + sp24, *(s16 *)(D_8261573C + idx) + sp26, arg2);
    }
    func_800496A4(8, 0);
    if (arg3 != NULL) {
        idx2 = *(s16 *)((u8 *)arg0 + 2) * 2;
        func_800495BC(*(s16 *)(D_82615738 + idx2) + sp24, *(s16 *)(D_82615740 + idx2) + sp26, arg3);
    }
    func_800499EC();
}

extern void func_800495BC(s32, s32, s32 *);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8004989C(s32 arg0);
extern void func_800498C4(void);
extern void func_800499EC(void);
void func_8260E2C4(void *arg0, s32 arg1) {
    s16 pad2;
    s16 pad1;
    s16 sp22;
    s16 sp20;
    struct Entry { s16 x; s16 y; s16 count; s16 pad; } *base;

    sp20 = *(s16 *)((u8 *)arg0 + 0x14) + *(s16 *)((u8 *)arg0 + 0x10);
    sp22 = *(s16 *)((u8 *)arg0 + 0x16) + *(s16 *)((u8 *)arg0 + 0x12);
    if (*(s16 *)((u8 *)arg0 + 0x2A) == *(s16 *)((u8 *)arg0 + 0x24)) {
        base = (struct Entry *)((u8 *)arg0 + 0x30);
        if (*(s16 *)((u8 *)arg0 + 0x2E) == *(s16 *)((u8 *)arg0 + 0x26) && base->count > 0) {
            func_800498C4();
            func_8004972C(0xFF, 0xFF, 0xFF, base->count);
            func_800496A4(8, 0);
            func_8004989C(0x14);
            if (*(s32 **)((u8 *)base + 8) != NULL) {
                func_800495BC(sp20 + base->x, sp22 + base->y, *(s32 **)((u8 *)base + 8));
            }
            func_800499EC();
        }
    }
}

extern s32 func_8004C874(s32, s32);
extern void func_800495F8(s32, s32, s32, s32);
extern u8 D_82615744[];
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800498C4(void);
extern void func_800499EC(void);
void func_8260E398(void *arg0, s32 arg1) {
    s16 y;
    s16 x;
    s32 index;
    s32 table_index;
    s32 offset;
    u8 *entry;
    x = (*((s16 *) (((u8 *) arg0) + 0x14))) + (*((s16 *) (((u8 *) arg0) + 0x10)));
    y = (*((s16 *) (((u8 *) arg0) + 0x16))) + (*((s16 *) (((u8 *) arg0) + 0x12)));
    func_800498C4();
    do { func_800496A4(8, 0); index = 0; offset = x + 0x4B; do { table_index = ((*((s16 *) (((u8 *) arg0) + 2))) * 4) + index; entry = D_82615744 + (table_index * 3); func_8004972C(entry[0], entry[1], entry[2], 0xFF); func_800495F8(offset, y + 0x9E, 1, func_8004C874(0x12, table_index)); index++; offset += 0x87; } while (index != 4); } while (0);
    func_800499EC();
}

extern void func_8004C594(s32, s32);
extern s32 func_8004C8A0(void *, s32, s32, s32);
void func_8260E4A8(void *arg0, s32 arg1) {
    s16 x;
    s16 y;
    s32 i;
    s32 text;
    char buf[0x80];
    s16 *sub;

    x = *(s16 *)((u8 *)arg0 + 0x14) + *(s16 *)((u8 *)arg0 + 0x10);
    y = *(s16 *)((u8 *)arg0 + 0x16) + *(s16 *)((u8 *)arg0 + 0x12);
    func_800498C4();
    func_800496A4(8, 0);
    func_8004972C(255, 255, 255, 255);
    func_800495F8(x + 150, y + 13, 1, func_8004C874(18, 8));
    sub = (s16 *)((u8 *)arg0 + 0x30);
    for (i = 0; i < 2; i++) {
        if (sub[i * 2 + 2] == -1) {
            text = func_8004C874(18, 11);
        } else if (sub[i] == 1) {
            func_8004C594(1, sub[i * 2 + 2] + 1);
            text = func_8004C8A0(buf, 0x80, 18, 9);
        } else {
            func_8004C594(1, sub[i * 2 + 2] + 1);
            func_8004C594(2, sub[i * 2 + 3] + 1);
            text = func_8004C8A0(buf, 0x80, 18, 10);
        }
        func_800495F8(x + 53, y + 63 + i * 71, 0, text);
        func_8004C594(2, sub[i + 6]);
        func_800495F8(x + 252, y + 63 + i * 71, 2, func_8004C8A0(buf, 0x80, 18, 12));
    }
    func_800499EC();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260E684.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260EA60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260ED40.s")

void func_8260F084(void *arg0, s32 arg1) {
    struct Vec2s {
        s16 x;
        s16 y;
    };
    struct State {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        s16 unk8;
        s16 padA;
        s32 unkC;
        s32 unk10;
        struct Vec2s unk14;
        struct Vec2s unk18;
        struct Vec2s unk1C;
    } *ptr = (struct State *)arg0;

    ptr->unk0 = 0;
    ptr->unk2 = 0;
    ptr->unk4 = 0;
    ptr->unk6 = arg1;
    ptr->unk8 = 0;
    ptr->unkC = 0;
    ptr->unk10 = 0x40000;
    ptr->unk14.x = 0x110;
    ptr->unk14.y = 0xC0;
    ptr->unk18 = ptr->unk14;
    ptr->unk1C = ptr->unk14;
}

void func_8260F0DC(u8 *arg0) {
    *(s16 *)(arg0 + 0) = 1;
    *(s16 *)(arg0 + 4) = 0;
    func_800226C0(0x78);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260F108.s")

extern s32 func_8004E0F0(s32, s32, s32);
s32 func_8260F49C(s32 arg0, s32 arg1) {
    s32 value;
    s32 result;
    void *record;

    record = (void *)((u8 *)(u32)arg0 + (arg1 * 4));
    value = *(s16 *)((u8 *)record + 0x58);
    result = 0;
    if (value != -1) {
        result = func_8004E0F0(0, value, *(s16 *)((u8 *)record + 0x5A));
    }
    return result;
}

void func_8260F4E4(void *arg0) {
    s32 width;
    s32 height;
    u8 *tex;
    u16 *size;
    f32 step;
    f32 scale;

    size = *(u16 **)((u8 *)arg0 + 0x18);
    width = size[2];
    height = size[3];
    tex = (u8 *)func_8004C990(104, 0);
    if (tex != NULL) {
        scale = (f32)height / (f32)(u32)*(u16 *)tex;
        if (scale > 0.0f) {
            gSPDisplayList(D_800D0510++, D_80094E78);
            gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
            gDPSetEnvColor(D_800D0510++, 155, 155, 255, 255);
            gDPSetPrimColor(D_800D0510++, 0, 0, 0, 0, 0, 255);
            func_8004D1FC(tex);
            gSPTextureRectangleFlip(D_800D0510++, 0, 0, (width - 1) << 2, (height - 1) << 2, 0, 0, 0, (s32)(((step = 1024.0f / scale) > 0.0f ? 0.5f : -0.5f) + step), 1024);
        }
    }
}

extern s32 func_8006456C(s32);
extern s32 func_80064728(void *);
extern s32 func_8003F970(s32, u16);
s32 func_8260F6C8(void *arg0, void **arg1, s32 arg2) {
    struct ResultSlot {
        s32 value;
        s32 pad;
    } result;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0;
    s32 i;
    void **ptr;
    void *entry;

    result.value = -1;
    temp_s5 = func_8006456C(*(u16 *)((u8 *)arg0 + 0x16));
    temp_s6 = func_80064728(arg0);
    temp_s7 = func_8003F970(*(u8 *)arg0, *(u16 *)((u8 *)arg0 + 0x16));
    i = 0;
    if (arg2 > 0) {
        ptr = arg1;
loop_2:
        entry = *ptr;
        temp_s2 = func_8006456C(*(u16 *)((u8 *)entry + 0x16));
        temp_s3 = func_80064728(entry);
        temp_v0 = func_8003F970(*(u8 *)entry, *(u16 *)((u8 *)entry + 0x16));
        if ((temp_s6 == temp_s3) && (temp_s5 == temp_s2) && (temp_s7 == temp_v0)) {
            result.value = i;
        } else {
            i += 1;
            ptr++;
            if (i != arg2) goto loop_2;
        }
    }
    return result.value;
}

s32 func_8260F7C4(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v1;

    var_v1 = 0;
    if (arg0 == -1) {
        temp_v0 = (s32) (arg1 + 3) / 4;
        var_v1 = temp_v0;
        if (temp_v0 >= 3) {
            var_v1 = 2;
        }
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260F7FC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_8260FFE8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826101B4.s")

extern void _bzero(void *, s32);
extern s32 D_8261A5A0;
extern s32 func_8260F7FC(s32);
extern s32 func_826101B4(s32);
extern s16 D_8261A490;
s32 func_82610C84(s32 arg0, s32 arg1) {
    s32 result;
    s32 mode;

    result = 1;
    _bzero((void *)&D_8261A490, 0x35DC);
    D_8261A5A0 = arg0;
    mode = *(s16 *)((u8 *)&arg1 + 2);
    D_8261A490 = mode;
    switch (mode) {
    case 0:
        result = func_8260F7FC(arg0);
        break;
    case 1:
        result = func_826101B4(arg0);
        break;
    }
    return result;
}

extern s16 D_8261A490;
s32 func_82610D14(void) {
    u8 *base = (u8 *)&D_8261A490;
    s32 result = 1;
    s32 i;

    for (i = 0; i < *(s16 *)(base + 0x18); i++) {
        if (((s16 **)(base + 0x34F4))[i][3] != 0) {
            result = 0;
            break;
        }
    }
    return result;
}

/* Retail takes one argument; func_82610EE8 passes a second one that is ignored. */
#ifdef CC_CHECK
s32 func_82610D6C(s16 *arg0, s32 arg1) {
#else
s32 func_82610D6C(arg0)
s16 *arg0;
{
#endif
    s32 result;
    s32 i;
    s32 j;
    u8 *entry;
    s16 *sub;

    result = 1;
    for (i = 0; i < arg0[9]; i++) {
        entry = func_82604C40(1, i, (u8 *)arg0 + 0x114, 0x14);
        if (entry != NULL) {
            sub = (s16 *)(entry + 0x30);
            for (j = 0; j < sub[3]; j++) {
                if (sub[j + 5] > 0) {
                    result = 0;
                }
            }
            if (result == 0) {
                break;
            }
        }
        if (1) {} // karodo
    }
    return result;
}



void *func_82604C40(s32 arg0, s32 arg1, void *arg2, s32 arg3);
s32 func_82610E34(s32 arg0)
{
  s16 new_var2;
  s32 new_var;
  s32 found;
  s32 i;
  s32 j;
  u8 *entry;
  u8 *sub;
  u8 *walker;
  found = 1;
  i = 0;
  // FAKE: 0xFF & 2 is the constant 2.
  while (i != (0xFF & 2))
  {
    entry = func_82604C40(6, i, ((u8 *) arg0) + 0x114, 0x14);
    i += 1;
    sub = entry + 0x30;
    // FAKE: new_var is a second name for 0; j starts from it below.
    new_var = 0;
    // FAKE: - (-0x36) is + 0x36.
    if ((*((s16 *) (((u8 *) entry) - (-0x36)))) > 0)
    {
      j = new_var;
      new_var2 = *((s16 *) (sub + 6));
      walker = sub;
      do
      {
        j += 2;
        if ((*((s16 *) (walker + 0x208))) > 0)
        {
          found = 0;
        }
        // FAKE: arithmetic nop; new_var stays 0.
        new_var++;
        new_var--;
        walker += 2;
      }
      while (j < (new_var2 * 2));
      // FAKE: arithmetic nop; sub is not read again.
      sub++;
      sub--;
    }
    if (found == 0)
    {
      break;
    }
  }

  return found;
}
extern s32 func_80001FF0(void);
#ifdef CC_CHECK
extern s32 func_82610D6C(s16 *, s32);
#else
extern s32 func_82610D6C();
#endif
// arg0[0] selects the check, arg0[3] counts frames, and arg0[1] receives the
// next state (2 or 7) when the check passes.
void func_82610EE8(s16 *arg0) {
    s32 frames;

    // Rounds func_80001FF0() * 0.75 to the nearest integer; the sign test
    // calls func_80001FF0 a second time.
    frames = (func_80001FF0() * 0.5f * 1.5f) + ((func_80001FF0() * 0.5f * 1.5f > 0.0f) ? 0.5f : -0.5f);
    switch (arg0[0]) {
        case 0:
            arg0[3]++;
            if (func_82610D6C(arg0, frames) && (arg0[3] >= frames)) {
                arg0[1] = 2;
                arg0[3] = 0;
            }
            break;
        case 1:
            if (func_82610E34((s32)arg0)) {
                arg0[1] = 7;
                arg0[3] = 0;
            }
            break;
    }
}

extern s32 D_82615768;
extern void func_826078B4(void *);
void func_82610FF8(s16 *arg0) {
    s32 i;
    u8 *entry;

    i = 0;
    arg0[3]++;
    if (D_82615768 < arg0[3]) {
        if (arg0[9] > 0) {
            arg0[1] = 3;
        } else {
            arg0[1] = 5;
        }
        arg0[3] = 0;
        arg0[4] = 0;
        arg0[12] = 0;
        for (i = 0; i < arg0[9]; i++) {
            entry = func_82604C40(1, i, (u8 *)arg0 + 0x114, 0x14);
            if (*(s16 *)(entry + 0x32) == -1) {
                ((void **)((u8 *)arg0 + 0x34F4))[arg0[12]] = entry;
                arg0[12]++;
            }
        }
        ((void **)((u8 *)arg0 + 0x34F4))[arg0[12]] = func_82604C40(2, 0, (u8 *)arg0 + 0x114, 0x14);
        arg0[12]++;
        entry = func_82604C40(3, 0, (u8 *)arg0 + 0x114, 0x14);
        if (entry != NULL) {
            ((void **)((u8 *)arg0 + 0x34F4))[arg0[12]] = entry;
            arg0[12]++;
        }
        for (i = 0; i < arg0[12]; i++) {
            func_826078B4(((void **)((u8 *)arg0 + 0x34F4))[i]);
        }
        func_800226C0(105);
    }
}

extern void func_82607734(void *, s32);
void func_82611184(u8 *arg0)
{
  s32 pad[2];
  u8 *sp34;
  s16 temp_v1;
  s32 var_a1;
  s32 var_s0;
  s32 var_s2;
  u8 *temp_s3;
  u8 *temp_v0;
  u8 *var_v0;
  temp_v1 = *((s16 *) (arg0 + 0x18));
  var_a1 = 1;
  var_s0 = 0;
  if ((temp_v1 - 1) >= 0)
  {
    var_v0 = arg0;
    loop_2:
    var_s0 += 1;

    if ((*((s16 *) ((*((u8 **) (var_v0 + 0x34F4))) + 6))) != 0)
    {
      var_a1 = 0;
    }
    else
    {
      var_v0 += 4;
      if (var_s0 < temp_v1)
      {
        goto loop_2;
      }
    }
  }
  if (var_a1 != (0 ^ 0))
  {
    temp_s3 = arg0 + 0x114;
    sp34 = func_82604C40(5, 0, temp_s3, 0x14);
    var_s0 = 0;
    *((s16 *) (arg0 + 2)) = 4;
    *((s16 *) (arg0 + 6)) = 0;
    if ((*((s16 *) (arg0 + 0x12))) > 0)
    {
      var_s2 = -1;
      do
      {
        temp_v0 = func_82604C40(1, var_s0, temp_s3, 0x14);
        if ((*((s16 *) (temp_v0 + 0x32))) != var_s2)
        {
          *((u8 **) ((arg0 + 0x34F4) + ((*((s16 *) (arg0 + 0x18))) * 4))) = func_82604C40(1, var_s0, temp_s3, 0x14);
          *((s16 *) (arg0 + 0x18)) = (*((s16 *) (arg0 + 0x18))) + 1;
          func_82607734(temp_v0, (*((s16 *) (sp34 + 0x26))) / 2);
          return;
        }
        var_s0 += 1;
      }
      while (var_s0 < (*((s16 *) (arg0 + 0x12))));
    }
  }
}

extern s32 D_826153C4;
extern void *D_80087200;
extern void func_826078B4(void *);
extern void func_800226C0(s32);
extern void * func_82604C40(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_82606784(u8*a0,s32 a1,s32 a2,s32 a3);
void func_826112CC(u8 *arg0) {
    s32 pad;
    u8 *sp28;
    s16 temp_t1;
    s32 var_s0;
    u8 *temp_s1;
    u8 *temp_v0;
    u8 *var_s1;
    u8 *var_t0;
    u8 *var_v1;

    temp_s1 = arg0 + 0x114;
    sp28 = func_82604C40(5, 0, temp_s1, 0x14);
    var_t0 = NULL;
    var_v1 = NULL;
    var_s0 = 0;
    if (*(s16 *)(arg0 + 0x12) > 0) {
        do {
            temp_v0 = func_82604C40(1, var_s0, temp_s1, 0x14);
            var_t0 = temp_v0;
            var_v1 = temp_v0 + 0x30;
            if (*(s16 *)(temp_v0 + 0x32) != -1) {
                break;
            }
            var_s0++;
        } while (var_s0 < *(s16 *)(arg0 + 0x12));
    }
    switch (*(s16 *)(sp28 + 6)) {
    case 0:
        if (*(s16 *)(var_v1 + 2) != -1 && *(s16 *)(var_t0 + 6) == 2) {
            func_82606784(sp28,
                          (*(s16 *)(var_v1 + 2) * 0x86) + *(s16 *)(var_t0 + 0x14) + 0xB,
                          ((*(s16 *)(var_t0 + 0x24) - *(s16 *)(sp28 + 0x24)) / 2) + *(s16 *)(var_t0 + 0x14),
                          *(s16 *)(var_t0 + 0x26) + *(s16 *)(var_t0 + 0x16));
        }
        break;
    case 2:
        *(s16 *)(arg0 + 6) += 1;
        if ((*(s16 *)(arg0 + 6) >= D_826153C4) || (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000)) {
            *(s16 *)(arg0 + 0x18) = 0;
            *(s16 *)(arg0 + 2) = 5;
            *(s16 *)(arg0 + 6) = 0;
            *(s16 *)(arg0 + 8) = 0;
            *(u8 **)(arg0 + 0x34F4 + (*(s16 *)(arg0 + 0x18)) * 4) = var_t0;
            *(s16 *)(arg0 + 0x18) += 1;
            *(u8 **)(arg0 + 0x34F4 + (*(s16 *)(arg0 + 0x18)) * 4) = sp28;
            *(s16 *)(arg0 + 0x18) += 1;
            var_s0 = 0;
            var_s1 = arg0;
            if (*(s16 *)(arg0 + 0x18) > 0) {
                do {
                    func_826078B4(*(void **)(var_s1 + 0x34F4));
                    var_s0++;
                    var_s1 += 4;
                } while (var_s0 < *(s16 *)(arg0 + 0x18));
            }
            func_800226C0(0x69);
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826114DC.s")

s32 func_826119A4(s32 arg0, s32 arg1, s16 *arg2) {
    s32 result;
    s32 i;

    result = -1;
    for (i = 0; i < arg1; i++) {
        if (arg0 != arg2[i]) {
            continue;
        }
        result = i;
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826119DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82611D44.s")

void func_826122A4(u8 *arg0) {
    s32 ready;
    s32 i;
    u8 *first;
    u8 *second;
    u8 *sub;

    ready = 1;
    for (i = 0; i < *(s16 *)(arg0 + 0x18); i++) {
        if (*(s16 *)(*(u8 **)(arg0 + 0x34F4 + i * 4) + 6) != 0) {
            ready = 0;
            break;
        }
    }
    if (ready) {
        i = 0;
        first = func_82604C40(5, 0, arg0 + 0x114, 0x14);
        second = func_82604C40(6, 1, arg0 + 0x114, 0x14);
        *(s16 *)(arg0 + 2) = 11;
        *(s16 *)(arg0 + 6) = 0;
        sub = second + 0x30;
        func_82607734(second, *(s16 *)(first + 0x26) / 2);
        for (i = 0; i < *(s16 *)(sub + 6); i++) {
            *(s16 *)(sub + 0x214 + i * 2) = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826123B0.s")

extern s32 D_826153C4;
extern void *D_80087200;
extern void func_800226C0(s32);
extern void * func_82604C40(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_82606784(u8*a0,s32 a1,s32 a2,s32 a3);
extern void func_826078B4(void *arg0);
void func_826127A4(void *arg0) {
    u8 *first;
    u8 *second;
    s32 i;
    u16 flags;
    u32 state;

    first = func_82604C40(5, 0, (u8 *)arg0 + 0x114, 0x14);
    second = func_82604C40(6, 1, (u8 *)arg0 + 0x114, 0x14);
    switch (*(s16 *)(first + 6)) {
        case 0:
            if (*(s16 *)(second + 6) == 2) {
                func_82606784(first, *(s16 *)(second + 0x14) + 416, (*(s16 *)(second + 0x24) - *(s16 *)(first + 0x24)) / 2 + *(s16 *)(second + 0x14), *(s16 *)(second + 0x26) + *(s16 *)(second + 0x16));
            }
            break;
        case 2:
            (*(s16 *)((u8 *)arg0 + 6))++;
            if (*(s16 *)((u8 *)arg0 + 6) >= D_826153C4 || (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000)) {
                flags = *(u16 *)((u8 *)arg0 + 4);
                if (flags & 0x200) {
                    *(s16 *)((u8 *)arg0 + 2) = 17;
                    *(s16 *)((u8 *)arg0 + 6) = 0;
                } else if (flags & 4) {
                    *(s16 *)((u8 *)arg0 + 2) = 12;
                    *(s16 *)((u8 *)arg0 + 6) = 0;
                } else if (flags & 0x100) {
                    *(s16 *)((u8 *)arg0 + 2) = 13;
                    *(s16 *)((u8 *)arg0 + 6) = 0;
                } else if (flags & 0x10) {
                    *(s16 *)((u8 *)arg0 + 2) = 14;
                    *(s16 *)((u8 *)arg0 + 6) = 0;
                } else {
                    state = 2;
                    if (!arg0) {} // FAKE
                    *(s16 *)((u8 *)arg0 + 2) = 19;
                    *(s16 *)((u8 *)arg0 + 6) = 0;
                    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x9C) = state;
                }
                *(s16 *)((u8 *)arg0 + 0x18) = 0;
                ((u8 **)((u8 *)arg0 + 0x34F4))[*(s16 *)((u8 *)arg0 + 0x18)] = second;
                (*(s16 *)((u8 *)arg0 + 0x18))++;
                ((u8 **)((u8 *)arg0 + 0x34F4))[*(s16 *)((u8 *)arg0 + 0x18)] = first;
                (*(s16 *)((u8 *)arg0 + 0x18))++;
                for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x18); i++) {
                    func_826078B4(((u8 **)((u8 *)arg0 + 0x34F4))[i]);
                }
                func_800226C0(105);
            }
            break;
    }
}
extern void func_80021ED8(s32);
extern s32 D_826153D0;
void func_826129AC(void *arg0) {
    s32 ready;
    u8 *first;
    s32 i;
    u8 *state;
    u32 mode;

    ready = 1;
    first = func_82604C40(7, 0, (u8 *)arg0 + 0x114, 0x14);
    state = **(u8 ***)((u8 *)arg0 + 0x110);
    for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x18); i++) {
        if (*(s16 *)(((u8 **)((u8 *)arg0 + 0x34F4))[i] + 6) != 0) {
            ready = 0;
            break;
        }
    }
    if (ready) {
        switch (*(s16 *)(first + 6)) {
            case 0:
                for (i = 0; i != 2; i++) {
                    func_8260675C(func_82604C40(7, i, (u8 *)arg0 + 0x114, 0x14));
                }
                if (*(s16 *)(state + 0x88) == 7) {
                    func_80021ED8(96);
                }
                break;
            case 2:
                switch (*(s16 *)((u8 *)arg0 + 0x35BC)) {
                    case 0:
                        func_8260F0DC((u8 *)arg0 + 0x35BC);
                        *(s16 *)((u8 *)arg0 + 8) = 0;
                        break;
                    case 6:
                        (*(s16 *)((u8 *)arg0 + 8))++;
                        if (*(s16 *)((u8 *)arg0 + 8) >= D_826153D0) {
                            if (*(u16 *)((u8 *)arg0 + 4) & 0x10) {
                                *(s16 *)((u8 *)arg0 + 2) = 14;
                            } else {
                                mode = 2;
                                if (!arg0) {} // FAKE
                                *(s16 *)((u8 *)arg0 + 2) = 19;
                                *(s32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x9C) = mode;
                            }
                            *(s16 *)((u8 *)arg0 + 6) = 0;
                            *(s16 *)((u8 *)arg0 + 0x18) = 0;
                            for (i = 0; i < 2; i++) {
                                ((u8 **)((u8 *)arg0 + 0x34F4))[*(s16 *)((u8 *)arg0 + 0x18)] = func_82604C40(7, i, (u8 *)arg0 + 0x114, 0x14);
                                (*(s16 *)((u8 *)arg0 + 0x18))++;
                            }
                            for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x18); i++) {
                                func_826078B4(((u8 **)((u8 *)arg0 + 0x34F4))[i]);
                            }
                            func_800226C0(105);
                        }
                        break;
                }
                break;
        }
    }
}

extern s16 D_826157A8;
extern s16 D_826157AC;
void func_82612BD0(void *arg0) {
    u8 *first;
    u8 *entry;
    u8 *sub;
    s32 total;
    s32 i;

    first = func_82604C40(1, 0, (u8 *)arg0 + 0x114, 0x14);
    total = D_826157A8 + D_826157AC;
    if (func_82610D14() != 0) {
        switch (*(s16 *)(first + 6)) {
            case 0:
                for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x12); i++) {
                    func_8260675C(func_82604C40(1, i, (u8 *)arg0 + 0x114, 0x14));
                }
                break;
            case 2:
                if (*(s16 *)((u8 *)arg0 + 6) == 0) {
                    func_800226C0(108);
                }
                (*(s16 *)((u8 *)arg0 + 6))++;
                if (*(s16 *)((u8 *)arg0 + 6) >= total) {
                    if (*(u16 *)((u8 *)arg0 + 4) & 0x200) {
                        *(s16 *)((u8 *)arg0 + 2) = 17;
                        *(s16 *)((u8 *)arg0 + 6) = 0;
                    } else {
                        *(s16 *)((u8 *)arg0 + 2) = 14;
                        *(s16 *)((u8 *)arg0 + 6) = 0;
                    }
                    *(s16 *)((u8 *)arg0 + 0x18) = 0;
                    for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x12); i++) {
                        ((u8 **)((u8 *)arg0 + 0x34F4))[*(s16 *)((u8 *)arg0 + 0x18)] = func_82604C40(1, i, (u8 *)arg0 + 0x114, 0x14);
                        (*(s16 *)((u8 *)arg0 + 0x18))++;
                    }
                    for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x18); i++) {
                        func_826078B4(((u8 **)((u8 *)arg0 + 0x34F4))[i]);
                    }
                    func_800226C0(106);
                } else if (D_826157A8 == *(s16 *)((u8 *)arg0 + 6)) {
                    for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x12); i++) {
                        entry = func_82604C40(1, i, (u8 *)arg0 + 0x114, 0x14);
                        sub = entry + 0x30;
                        if (*(s16 *)(entry + 0x32) != -1) {
                            ((s16 *)(sub + 0x12))[*(s16 *)(sub + 2)] = 0;
                            ((s16 *)(sub + 0x54))[*(s16 *)(sub + 2)] = 1;
                            func_800226C0(119);
                        }
                    }
                }
                break;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82612E1C.s")

extern s16 D_826157B0;
void func_826131A4(u8 *arg0) {
    s32 i;
    s32 done;
    s32 ready;

    done = 1;
    *(s16 *)(arg0 + 6) += 1;
    for (i = 0; i < *(s16 *)(arg0 + 0x18); i++) {
        if ((((u8 **)(arg0 + 0x34F4))[i] != NULL) && (*(s16 *)(((u8 **)(arg0 + 0x34F4))[i] + 0xC) > 0)) {
            done = 0;
            break;
        }
    }
    if ((*(s16 *)(arg0 + 6) >= D_826157B0) && (done != 0)) {
        if (*(s32 *)(*(u8 **)(arg0 + 0x110) + 0x9C) == 7) {
            if (func_80054E10(*(u8 **)(arg0 + 0x110) + 0x900) != 0) {
                ready = 1;
            } else {
                ready = 0;
            }
        } else {
            ready = 0;
        }
        if (ready != 0) {
            *(s16 *)(arg0 + 2) = 0x10;
            *(s16 *)(arg0 + 6) = 0;
        } else {
            *(s16 *)(arg0 + 2) = 0x13;
            *(s16 *)(arg0 + 6) = 0;
        }
        for (i = 0; i < *(s16 *)(arg0 + 0x18); i++) {
            func_826078B4(((void **)(arg0 + 0x34F4))[i]);
        }
        func_800226C0(0x69);
    }
}

extern void func_800355E4(s32);
void func_826132D8(void *arg0) {
    u8 *first;
    u8 *second;
    s32 limit;
    s32 kind;
    s32 i;
    u8 *state;

    first = func_82604C40(2, 0, (u8 *)arg0 + 0x114, 0x14);
    second = func_82604C40(3, 0, (u8 *)arg0 + 0x114, 0x14);
    state = **(u8 ***)((u8 *)arg0 + 0x110);
    if ((*(u16 *)(state + 8) & 0xFF00) == 0x600) {
        limit = func_80001FF0() * 130 / 60;
    } else {
        limit = func_80001FF0() * 90 / 60;
    }
    if (func_82610D14() != 0) {
        switch (*(s16 *)(first + 6)) {
            case 0:
                func_8260675C(first);
                func_8260675C(second);
                kind = *(u16 *)(**(u8 ***)((u8 *)arg0 + 0x110) + 8) & 0xFF00;
                if (kind == 0x300 || kind == 0x600) {
                    func_800355E4(83);
                }
                break;
            case 2:
                (*(s16 *)((u8 *)arg0 + 6))++;
                if (*(s16 *)((u8 *)arg0 + 6) >= limit) {
                    *(s16 *)((u8 *)arg0 + 0x18) = 0;
                    *(s16 *)((u8 *)arg0 + 2) = 19;
                    *(s16 *)((u8 *)arg0 + 6) = 0;
                    ((u8 **)((u8 *)arg0 + 0x34F4))[*(s16 *)((u8 *)arg0 + 0x18)] = first;
                    (*(s16 *)((u8 *)arg0 + 0x18))++;
                    ((u8 **)((u8 *)arg0 + 0x34F4))[*(s16 *)((u8 *)arg0 + 0x18)] = second;
                    (*(s16 *)((u8 *)arg0 + 0x18))++;
                    for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x18); i++) {
                        func_826078B4(((u8 **)((u8 *)arg0 + 0x34F4))[i]);
                    }
                    func_800226C0(105);
                    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x9C) = 2;
                }
                break;
        }
    }
}

extern void func_8006CC18(s32, s32);
void func_826134DC(void *arg0) {
    u8 *first;
    u8 *second;
    u8 *sub;
    s32 done;
    s32 i;
    s32 prev;
    u8 *slot;
    s32 flag;
    u8 *state;

    first = func_82604C40(11, 0, (u8 *)arg0 + 0x114, 0x14);
    second = func_82604C40(9, 0, (u8 *)arg0 + 0x114, 0x14);
    sub = second + 0x30;
    done = 0;
    prev = *(s16 *)((u8 *)arg0 + 0x1E);
    slot = *(s16 *)(second + 0x32) * 12 + *(u8 **)(second + 0x38);
    state = **(u8 ***)((u8 *)arg0 + 0x110);
    if (func_82610D14() != 0) {
        switch (*(s16 *)(first + 6)) {
            case 0:
                func_8260675C(first);
                func_800226C0(169);
                break;
            case 2:
                if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x800) {
                    (*(s16 *)((u8 *)arg0 + 0x1E))--;
                    if (*(s16 *)((u8 *)arg0 + 0x1E) < 0) {
                        *(s16 *)((u8 *)arg0 + 0x1E) = 0;
                    }
                }
                if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x400) {
                    (*(s16 *)((u8 *)arg0 + 0x1E))++;
                    if (*(s16 *)((u8 *)arg0 + 0x1E) >= 2) {
                        *(s16 *)((u8 *)arg0 + 0x1E) = 1;
                    }
                }
                if (prev != *(s16 *)((u8 *)arg0 + 0x1E)) {
                    func_800226C0(1);
                }
                if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
                    done = 1;
                    if (func_826058CC(state[7]) == 0) {
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                    if (*(s16 *)((u8 *)arg0 + 0x1E) == 0) {
                        if (*(s16 *)(slot + 2) != 0) {
                            if (*(s16 *)(state + 0x8C) > 0) {
                                (*(s16 *)(state + 0x8C))--;
                            }
                        }
                        func_8006CC18(flag, *(s16 *)(state + 0x8C));
                        func_800226C0(131);
                    } else {
                        *(s32 *)(*(u8 **)((u8 *)arg0 + 0x110) + 0x9C) = *(u16 *)(*(u8 **)(sub + 8) + 6);
                        func_800226C0(147);
                    }
                }
                break;
        }
        if (done) {
            if (*(s16 *)((u8 *)arg0 + 0x1E) == 0) {
                *(s16 *)((u8 *)arg0 + 2) = 19;
            } else {
                *(s16 *)((u8 *)arg0 + 2) = 18;
            }
            *(s16 *)((u8 *)arg0 + 0x18) = 0;
            *(s16 *)((u8 *)arg0 + 6) = 0;
            ((u8 **)((u8 *)arg0 + 0x34F4))[*(s16 *)((u8 *)arg0 + 0x18)] = first;
            (*(s16 *)((u8 *)arg0 + 0x18))++;
            for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x18); i++) {
                func_826078B4(((u8 **)((u8 *)arg0 + 0x34F4))[i]);
            }
            func_800226C0(167);
        }
    }
}

s32 func_82610D14();

void func_82613764(void *arg0) {
    if (func_82610D14() != 0) {
        (*(s16 *)((u8 *)(arg0) + (6))) = (s16) ((*(s16 *)((u8 *)(arg0) + (6))) + 1);
        if ((*(s16 *)((u8 *)(arg0) + (6))) >= 8) {
            (*(s16 *)((u8 *)(arg0) + (2))) = 0x13;
            (*(s16 *)((u8 *)(arg0) + (6))) = 0;
            (*(s16 *)((u8 *)(arg0) + (0x18))) = 0;
        }
    }
}

void func_826137B8(s16 *arg0) {
    s32 found;
    s32 i;
    u8 *ptr;
    s16 *entry;

    found = 1;
    i = 0;
    if (arg0[0xC] > 0) {
        ptr = (u8 *)arg0;
        do {
            entry = *(s16 **)(ptr + 0x34F4);
            i++;
            if (entry != NULL && entry[3] != 0) {
                found = 0;
                break;
            }
            ptr += 4;
        } while (i < arg0[0xC]);
    }
    if (found != 0) {
        arg0[1] = 0;
        arg0[3] = 0;
    }
}

extern s16 D_8261A492;
extern u16 D_8261A494;
extern s16 D_8261DA4C;
extern void func_8260F108(void *);
extern void func_826114DC(void *);
extern void func_826119DC(void *);
extern void func_82611D44(void *);
extern void func_826123B0(void *);
extern void func_826127A4(void *);
extern void func_826129AC(void *);
extern void func_82612BD0(void *);
extern void func_82612E1C(void *);
extern void func_826134DC(void *);
extern void func_826132D8(void *);
s32 func_82613814(void) {
    void *s0 = &D_8261A490;
    u8 *entry;
    s32 i;

    if (*(u16 *)((u8 *)s0 + 4) & 1) {
        switch (D_8261A492) {
            case 1:
                func_82610EE8(s0);
                break;
            case 2:
                func_82610FF8(s0);
                break;
            case 3:
                func_82611184(s0);
                break;
            case 4:
                func_826112CC(s0);
                break;
            case 5:
                func_826114DC(s0);
                break;
            case 7:
                func_826119DC(s0);
                break;
            case 8:
                func_82611D44(s0);
                break;
            case 9:
                func_826122A4(s0);
                break;
            case 10:
                func_826123B0(s0);
                break;
            case 11:
                func_826127A4(s0);
                break;
            case 12:
                func_826129AC(s0);
                break;
            case 13:
                func_82612BD0(s0);
                break;
            case 14:
                func_82612E1C(s0);
                break;
            case 15:
                func_826131A4(s0);
                break;
            case 16:
                func_826134DC(s0);
                break;
            case 17:
                func_826132D8(s0);
                break;
            case 18:
                func_82613764(s0);
                break;
            case 19:
                func_826137B8(s0);
                break;
        }
        for (i = 0; i < 20; i++) {
            entry = (u8 *)&D_8261A490 + i * 0x298;
            if (*(s16 *)(entry + 0x114) != 0) {
                func_82607B74(entry + 0x114);
            }
        }
        func_8260F108(&D_8261DA4C);
    }
    return (D_8261A494 & 1) != 0;
}

extern void func_8260850C(u8 *, s32);
extern void func_8260899C(u8 *, s32);
extern void func_82608C1C(u8 *, s32);
extern void func_826090F4(u8 *, s32);
extern void func_8260933C(u8 *, s32);
extern void func_8260BEF4(u8 *, s32);
extern void func_8260C2B0(u8 *, s32);
extern void func_8260D820(u8 *, s32);
extern void func_8260DB98(u8 *, s32);
extern void func_8260DD84(u8 *, s32);
void func_826139D4(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) != 0) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260850C(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

void func_82613A4C(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) != 0) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260899C(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

void func_82613AC4(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 7) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_82608C1C(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

extern void func_82608EC4(u8 *, s32);
void func_82613B48(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s16 temp_v0;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_v0 = *(s16 *)(var_s0 + 0x114);
        temp_a0 = var_s0 + 0x114;
        if ((temp_v0 == 2) || (temp_v0 == 3)) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_82608EC4(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

void func_82613BE0(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 7) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_826090F4(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

extern void func_82609868(void *, s32, s32);
extern void func_82609730(void *arg0, s32 arg1);
void func_82613C64(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;
    s32 var_s1;
    s32 var_s2;
    s16 temp_v0;
    u8 *temp_a0;
    u8 *var_s0;

    var_s1 = 1;
    var_s0 = arg0;
    var_s2 = 0;
    do {
        temp_v0 = *(s16 *)(var_s0 + 0x114);
        temp_a0 = var_s0 + 0x114;
        switch (temp_v0) {
        case 1:
            temp_a1 = var_s1;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s1 = 0;
                func_82609730(temp_a0, temp_a1);
            }
            break;
        case 4:
            temp_a1 = var_s1;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                temp_a2 = *(s32 *)(var_s0 + 0x144);
                var_s1 = 0;
                func_82609868(temp_a0, temp_a1, temp_a2);
            }
            break;
        case 6:
            temp_a1 = var_s1;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                temp_a2 = *(s32 *)(var_s0 + 0x144);
                var_s1 = 0;
                func_82609868(temp_a0, temp_a1, temp_a2);
            }
            break;
        }
        var_s2 += 0x298;
        var_s0 += 0x298;
    } while (var_s2 != 0x33E0);
}

extern void func_82609A88(void *, s32);
extern void func_82609D84(void *, s32);
void func_82613D60(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    s16 temp_v0;
    u8 *temp_a0;
    u8 *var_s0;

    var_s1 = 1;
    var_s0 = arg0;
    var_s2 = 0;
    do {
        temp_v0 = *(s16 *)(var_s0 + 0x114);
        temp_a0 = var_s0 + 0x114;
        switch (temp_v0) {
        case 4:
            temp_a1 = var_s1;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s1 = 0;
                func_82609A88(temp_a0, temp_a1);
            }
            break;
        case 6:
            temp_a1 = var_s1;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s1 = 0;
                func_82609D84(temp_a0, temp_a1);
            }
            break;
        }
        var_s2 += 0x298;
        var_s0 += 0x298;
    } while (var_s2 != 0x33E0);
}

void func_82613E20(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 7) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260933C(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

extern void func_8260BE24(u8 *arg0, s32 arg1);
void func_82613EA4(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    s16 temp_v0;
    u8 *temp_a0;
    u8 *var_s0;

    var_s1 = 1;
    var_s0 = arg0;
    var_s2 = 0;
    do {
        temp_v0 = *(s16 *)(var_s0 + 0x114);
        temp_a0 = var_s0 + 0x114;
        switch (temp_v0) {
        case 8:
            temp_a1 = var_s1;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s1 = 0;
                func_8260BD50(temp_a0, temp_a1);
            }
            break;
        case 0xB:
            temp_a1 = var_s1;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s1 = 0;
                func_8260BE24(temp_a0, temp_a1);
            }
            break;
        }
        var_s2 += 0x298;
        var_s0 += 0x298;
    } while (var_s2 != 0x33E0);
}

extern void func_8260A0B8(void *, s32);
extern void func_8260A6B4(void *, s32);
extern void func_8260AF30(void *, s32);
extern void func_8260B424(void *, s32);
void func_82613F64(u8 *arg0) {
    s32 first;
    s32 i;
    u8 *entry;

    first = 1;
    for (i = 0; i < 20; i++) {
        entry = arg0 + i * 0x298 + 0x114;
        switch (*(s16 *)entry) {
            case 4:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260A0B8(entry, first);
                    first = 0;
                }
                break;
            case 6:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260A6B4(entry, first);
                    first = 0;
                }
                break;
            case 7:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260AF30(entry, first);
                    first = 0;
                }
                break;
            case 8:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260B424(entry, first);
                    first = 0;
                }
                break;
            case 11:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260BBA8(entry, first);
                    first = 0;
                }
                break;
        }
    }
}

void func_82614088(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 6) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260BEF4(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

void func_8261410C(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 1) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260C2B0(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

void func_82614190(void *arg0) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 var_s1;
    s16 temp_v0;
    s32 var_s2;
    u8 *new_var;
    u8 *temp_a0;
    u8 *var_s0;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    var_s1 = 1;
    var_s0 = arg0;
    var_s2 = 0;
    var_s3 = 1;
    var_s4 = 6;
    ;
    do {
        temp_v0 = *((s16 *)(var_s0 + 0x114));
        temp_a0 = var_s0 + 0x114;
        switch (temp_v0) {
        case 1:
            temp_a1_2 = var_s1;
            if ((*((s16 *)(temp_a0 + 6))) != 0) {
                var_s1 = 0;
                func_8260C7D4(temp_a0, temp_a1_2);
            }
            break;
        case 6:
            temp_a1 = var_s1;
            if ((*((s16 *)((new_var = temp_a0 + 6)))) != 0) {
                var_s1 = 0;
                func_8260C988(temp_a0, temp_a1);
            }
            break;
        }
        var_s2 += 0x298;
        var_s0 += 0x298;
    } while (var_s2 != 0x33E0);
}

void func_82614250(void *arg0) {
    unsigned short state1;
    s16 state2;
    s32 index;
    void *entry;
    u8 *new_var;
    void *record;
    unsigned int one;
    state1 = 1;
    entry = arg0;
    index = 0;
    one = 1;
    do {
        record = ((u8 *)entry) + 0x114;
        new_var = ((u8 *)entry) + 0x114;
        if ((*((s16 *)new_var)) == one) {
            if (1) {
                if ((*((s16 *)(((u8 *)record) + 6))) != 0) {
                    func_8260CC24(record, 0, state1);
                    state1 = 0;
                }
            }
        }
        index += 0x298;
        entry = ((u8 *)entry) - -0x298;
    } while (index < 0x33E0);
    entry = arg0;
    state2 = 1;
    index = 0; do { record = ((u8 *)entry) + 0x114; if ((*((s16 *)(((u8 *)entry) + 0x114))) == one) {
        if ((*((s16 *)(((u8 *)record) + 6))) != 0) {
            func_8260CC24(record, one, state2);
            state2 = 0;
        }
      }
      index += 0x298;
      entry = ((u8 *)entry) + 0x298;
    } while (index != 0x33E0);
}

void func_82614324(void *arg0) {
    s32 var_s1;
    s32 var_s2;
    void *var_s0;
    s16 temp_v0;
    void *temp_a0;
    void *temp_a0_2;
    s32 temp_a1;
    var_s1 = 1;
    var_s0 = arg0;
    var_s2 = 0;
    do {
        temp_v0 = *(s16 *)((u8 *)var_s0 + 0x114);
        temp_a0 = (u8 *)var_s0 + 0x114;
        switch (temp_v0) {
        case 4:
            temp_a1 = var_s1;
            if (*(s16 *)((u8 *)temp_a0 + 6) != 0) { var_s1 = 0; func_8260CF84(temp_a0, temp_a1); }
            break;
        case 6:
            temp_a0_2 = temp_a0;
            temp_a1 = var_s1;
            if (*(s16 *)((u8 *)temp_a0_2 + 6) != 0) { var_s1 = 0; func_8260D440(temp_a0_2, temp_a1); }
            break;
        }
        var_s2 += 0x298;
        var_s0 = (u8 *)var_s0 + 0x298;
    } while (var_s2 != 0x33E0);
}

void func_826143E4(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 1) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260D820(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

void func_82614468(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 6) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260DB98(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

void func_826144EC(void *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 var_s1;
    u8 *temp_a0;
    u8 *var_s0;

    var_s2 = 1;
    var_s0 = arg0;
    var_s1 = 0;
    do {
        temp_a0 = var_s0 + 0x114;
        if (*(s16 *)(var_s0 + 0x114) == 6) {
            temp_a1 = var_s2;
            if (*(s16 *)(temp_a0 + 6) != 0) {
                var_s2 = 0;
                func_8260DD84(temp_a0, temp_a1);
            }
        }
        var_s1 += 0x298;
        var_s0 += 0x298;
    } while (var_s1 != 0x33E0);
}

extern void func_8260E140(u8 *arg0, s32 arg1);
void func_82614570(void *arg0) {
    void *var_s0;
    s32 var_s1;
    s32 var_s2;
    s16 temp_v0;
    void *temp_a0;
    s32 temp_a1;

    var_s1 = 1;
    var_s0 = arg0;
    var_s2 = 0;
    do {
        temp_v0 = *(s16 *)((u8 *)var_s0 + 0x114);
        temp_a0 = (u8 *)var_s0 + 0x114;
        switch (temp_v0) {
        case 9:
            if (*(s16 *)((u8 *)temp_a0 + 6)) { temp_a1 = var_s1; var_s1 = 0; func_8260E03C(temp_a0, temp_a1); }
            break;
        case 0xB:
            if (*(s16 *)((u8 *)temp_a0 + 6)) { temp_a1 = var_s1; var_s1 = 0; func_8260E140(temp_a0, temp_a1); }
            break;
        }
        var_s2 += 0x298;
        var_s0 = (u8 *)var_s0 + 0x298;
    } while (var_s2 != 0x33E0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82614630.s")

extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern void func_82607E40(u8 *, u8 *, u8 *, u8 *, s32);
extern u8 D_80094E78[];
extern u8 D_8261551C[];
extern u8 D_82615520[];
void func_8261479C(void *arg0) {
    struct State { u8 pad[0xA]; s16 index; s16 alpha; };
    s32 result;
    struct Color { u8 r; u8 g; u8 b; } color1;
    struct Color color2;

    result = func_8004C990(0x53, 3);
    gSPDisplayList(D_800D0510++, D_80094E78);
    func_82607E40(&color1.r, &color2.r, D_8261551C, D_82615520, ((struct State *)arg0)->index);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, color1.r, color1.g, color1.b, ((struct State *)arg0)->alpha);
    gDPSetPrimColor(D_800D0510++, 0, 0, color2.r, color2.g, color2.b, 0xFF);
    func_8004D19C(0x141, 0xD0, result, 1, 0);
}

extern u8 D_82615524;
extern u8 D_82615528;
void func_826148D4(void *arg0) {
    struct State { u8 pad[0xE]; s16 index; s16 alpha; };
    struct Color { u8 r; u8 g; u8 b; };
    s32 result;
    struct Color color1;
    struct Color color2;

    result = func_8004C990(0x5F, 0);
    gSPDisplayList(D_800D0510++, D_80094E78);
    func_82607E40(&color1.r, &color2.r, &D_82615524, &D_82615528, ((struct State *)arg0)->index);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, color1.r, color1.g, color1.b, ((struct State *)arg0)->alpha);
    gDPSetPrimColor(D_800D0510++, 0, 0, color2.r, color2.g, color2.b, 0xFF);
    func_8004D19C(0x141, 0xD4, result, 1, 0);
}

typedef struct unk_func_82614A0C {
    /* 0x000 */ u8 unk_000[0x114];
    /* 0x114 */ u8 unk_114[0x30];
    /* 0x144 */ u8 unk_144[0x154];
} unk_func_82614A0C;
extern void func_8260E4A8(void *, s32);
extern void func_8260E684(void *, s32);
extern void func_8260EA60(void *, s32);
extern void func_8260ED40(void *, s32);
void func_82614A0C(void *arg0) {
    s32 first;
    s32 i;
    u8 *entry;
    u8 *sub;

    first = 1;
    for (i = 0; i < 20; i++) {
        entry = ((unk_func_82614A0C *)arg0)[i].unk_114;
        switch (*(s16 *)entry) {
            case 4:
                sub = ((unk_func_82614A0C *)arg0)[i].unk_144;
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260E1B4(entry, first, *(s32 **)(sub + 0xC), *(s32 **)(sub + 0x10), 255);
                    first = 0;
                }
                break;
            case 6:
                sub = ((unk_func_82614A0C *)arg0)[i].unk_144;
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260E1B4(entry, first, *(s32 **)(sub + 0x200), *(s32 **)(sub + 0x204), 255 - *(s16 *)(sub + 0x1E));
                    first = 0;
                }
                break;
            case 5:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260E2C4(entry, first);
                    first = 0;
                }
                break;
            case 7:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260E398(entry, first);
                    first = 0;
                }
                break;
            case 8:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260E4A8(entry, first);
                    first = 0;
                }
                break;
            case 9:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260E684(entry, first);
                    first = 0;
                }
                break;
            case 10:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260EA60(entry, first);
                    first = 0;
                }
                break;
            case 11:
                if (*(s16 *)(entry + 6) != 0) {
                    func_8260ED40(entry, first);
                    first = 0;
                }
                break;
        }
    }
}

extern s16 D_8261A490;
extern u16 D_8261A494;
extern s16 D_8261DA4C;
extern void func_82614A0C(void *arg0);
extern void func_82614630(void *arg0);
extern void func_8261479C(void *arg0);
extern void func_826148D4(void *arg0);
extern void func_826139D4(void *arg0);
extern void func_82613A4C(void *arg0);
extern void func_82613AC4(void *arg0);
extern void func_82613B48(void *arg0);
extern void func_82613BE0(void *arg0);
extern void func_82613E20(void *arg0);
extern void func_82614088(void *arg0);
extern void func_8261410C(void *arg0);
extern void func_826143E4(void *arg0);
extern void func_82614468(void *arg0);
extern void func_826144EC(void *arg0);
s32 func_82614BD0(void) {
    void *s0 = &D_8261A490;

    if (*(u16 *)((u8 *)s0 + 4) & 1) {
        func_82613A4C(s0);
        func_826139D4(s0);
        func_82613B48(s0);
        func_82613BE0(s0);
        func_82613C64(s0);
        func_82613D60(s0);
        func_82613E20(s0);
        func_82613EA4(s0);
        func_82613F64(s0);
        func_82613AC4(s0);
        func_82614088(s0);
        func_8261410C(s0);
        func_82614190(s0);
        func_82614250(s0);
        func_82614324(s0);
        func_826143E4(s0);
        func_82614468(s0);
        func_82614570(s0);
        func_82614A0C(s0);
        func_826144EC(s0);
        if (D_8261DA4C != 0) {
            func_82614630(&D_8261DA4C);
        }
        func_8261479C(s0);
        if (D_8261DA4C) {
        }
        func_826148D4(s0);
    }
    return (D_8261A494 & 1) != 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_82614CE0.s")

extern s16 D_8261A492;
extern u16 D_8261A494;

s32 func_82614F0C(void) {
    s32 var_v1;

    var_v1 = 0;
    if ((D_8261A494 & 1) && (D_8261A492 == 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

void func_82614F40(u16 *arg0, u16 *arg1, u16 arg2, s32 arg3) {
    s32 result = -1;

    switch (arg2 & 0xFF00) {
        case 0:
            switch (arg2 & 0xFF) {
                case 0: result = 85; break;
                case 1: result = 83; break;
                case 2: result = 84; break;
                case 3: result = 86; break;
            }
            break;
        case 0x300:
            switch (arg3) {
                case 5: result = 57; break;
                case 6: result = 58; break;
                case 7: result = 59; break;
                case 8: result = 60; break;
                case 9: result = 61; break;
                case 10: result = 62; break;
                case 11: result = 63; break;
                case 12: result = 64; break;
                case 13: result = 65; break;
                case 14: result = 66; break;
                case 15: result = 79; break;
                case 16: result = 69; break;
                case 17: result = 72; break;
                case 18: result = 68; break;
                case 19: result = 70; break;
                case 20: result = 71; break;
                case 21: result = 67; break;
                case 22: result = 73; break;
                case 23: result = 74; break;
                case 24: result = 82; break;
            }
            break;
    }
    if ((arg0 != NULL) && (result != -1)) {
        *arg0 = 18;
    }
    if (arg1 != NULL) {
        *arg1 = result;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12C460/func_826150A4.s")
#endif
