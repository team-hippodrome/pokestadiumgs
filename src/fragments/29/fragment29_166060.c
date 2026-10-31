#include "global.h"


#ifdef VERSION_US
extern u8 D_8800686C;
extern s32 fragment29_main(u8);
s32 fragment29_main(u8 arg0) {
    s32 result = 0;
    switch (arg0) {
    case 1:
    case 2:
    case 3:
    case 4:
        result = 1;
        break;
    }
    return result;
}

s32 func_8800005C(void) {
    return fragment29_main(D_8800686C);
}

/* mkdraft:Envelope_Advance begin */
typedef struct { s16 tick, value, start, end; u8 delay, rise, hold, fall; } Fragment29Envelope;

s16 Envelope_Advance(Fragment29Envelope *envelope) {
    f32 bias;
    f32 delta;
    if (envelope->tick <= envelope->delay) {
        envelope->value = envelope->start;
    } else if (envelope->delay < envelope->tick && envelope->tick < envelope->delay + envelope->rise) {
        if (((f32)((envelope->end - envelope->start) * (envelope->tick - envelope->delay)) / envelope->rise) > 0.0f) {
            bias = 0.5f;
        } else {
            bias = -0.5f;
        }
        delta = (f32)((envelope->end - envelope->start) * (envelope->tick - envelope->delay)) / envelope->rise;
        envelope->value = (s32)(bias + delta) + envelope->start;
    } else if (envelope->delay + envelope->rise <= envelope->tick && envelope->tick <= envelope->delay + envelope->rise + envelope->hold) {
        envelope->value = envelope->end;
    } else {
        if (((f32)((envelope->start - envelope->end) * (envelope->tick - envelope->delay - envelope->rise - envelope->hold)) / envelope->fall) > 0.0f) {
            bias = 0.5f;
        } else {
            bias = -0.5f;
        }
        delta = (f32)((envelope->start - envelope->end) * (envelope->tick - envelope->delay - envelope->rise - envelope->hold)) / envelope->fall;
        envelope->value = (s32)(bias + delta) + envelope->end;
    }
    envelope->tick++;
    if (envelope->tick == envelope->delay + envelope->rise + envelope->hold + envelope->fall) {
        envelope->tick = 0;
    }
    return envelope->value;
}
/* mkdraft:Envelope_Advance end */

extern s16 Envelope_Advance(Fragment29Envelope *);
void func_88000288(void *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    *(s16 *)((u8 *)arg0 + 0) = arg1;
    *(s16 *)((u8 *)arg0 + 4) = arg2;
    *(s16 *)((u8 *)arg0 + 6) = arg3;
    *(u8 *)((u8 *)arg0 + 8) = arg4;
    *(u8 *)((u8 *)arg0 + 9) = arg5;
    *(u8 *)((u8 *)arg0 + 10) = arg6;
    *(u8 *)((u8 *)arg0 + 11) = arg7;
    Envelope_Advance(arg0);
}

void func_880002F4(u8 *arg0, s16 arg1) {
    *(s16 *)arg0 = arg1;
}

/* mkdraft:func_88000308 begin */
extern u8 D_88005FA4[];



u8 *func_88000308(u8 *arg0, s16 arg1) {

    arg0[0] = (s8)(s32)(((f32)((D_88005FA4[3] * arg1) + (D_88005FA4[0] * (0xFF - arg1))) / 255.0f) + (((f32)((D_88005FA4[3] * arg1) + (D_88005FA4[0] * (0xFF - arg1))) / 255.0f) > 0.0f ? 0.5f : -0.5f));
    arg0[1] = (s8)(s32)(((f32)((D_88005FA4[4] * arg1) + (D_88005FA4[1] * (0xFF - arg1))) / 255.0f) + (((f32)((D_88005FA4[4] * arg1) + (D_88005FA4[1] * (0xFF - arg1))) / 255.0f) > 0.0f ? 0.5f : -0.5f));
    arg0[2] = (s8)(s32)(((f32)((D_88005FA4[5] * arg1) + (D_88005FA4[2] * (0xFF - arg1))) / 255.0f) + (((f32)((D_88005FA4[5] * arg1) + (D_88005FA4[2] * (0xFF - arg1))) / 255.0f) > 0.0f ? 0.5f : -0.5f));
    return arg0;
}
/* mkdraft:func_88000308 end */

extern Gfx *D_800D0510;
void func_88000488(s32 *arg0, s32 arg1) {
    if (*arg0 != arg1) {
        gDPPipeSync(D_800D0510++);
        if (arg1 != 0) {
            gDPSetCombine(D_800D0510++, 0x509AA1, 0x3335FEFF);
        } else {
            gDPSetCombine(D_800D0510++, 0x129A25, 0xFF37FFFF);
        }
        *arg0 = arg1;
    }
}

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
} Color_88000510;
extern s8 D_88005FE8[];
extern Color_88000510 D_88005FAC[];
Color_88000510 *func_88000510(Color_88000510 *dest, s8 arg0) {
    s32 index;

    for (index = 0; index < 0x12; index++) {
        if (arg0 == D_88005FE8[index]) {
            break;
        }
    }
    *dest = D_88005FAC[index];
    return dest;
}

extern Color_88000510 D_88005FFC[];
// Copies color D_88005FFC[arg1 - 1] to dest for arg1 1-6 and the last entry,
// D_88005FFC[6], for any other value.
Color_88000510 *func_88000578(Color_88000510 *dest, u8 arg1) {
    switch (arg1) {
        case 1:
            *dest = D_88005FFC[0];
            break;
        case 2:
            *dest = D_88005FFC[1];
            break;
        case 3:
            *dest = D_88005FFC[2];
            break;
        case 4:
            *dest = D_88005FFC[3];
            break;
        case 5:
            *dest = D_88005FFC[4];
            break;
        case 6:
            *dest = D_88005FFC[5];
            break;
        default:
            *dest = D_88005FFC[6];
            break;
    }
    return dest;
}

extern u8 D_8800ED28[];
void func_880006BC(u8 *arg0) { struct S { u8 a,b,c; }; *(struct S *)&D_8800ED28 = *(struct S *)arg0; }

extern void func_8004972C(s32, s32, s32, s32);
// Passes the color with alpha 0xFF to func_8004972C only when it differs from
// the copy cached in D_8800ED28, then updates that copy.
void func_880006E0(Color_88000510 *color) {
    if ((color->red != D_8800ED28[0]) || (color->green != D_8800ED28[1]) || (color->blue != D_8800ED28[2])) {
        func_8004972C(color->red, color->green, color->blue, 0xFF);
        *(Color_88000510 *)D_8800ED28 = *color;
    }
}

s32 func_88000770(u8 *arg0)
{
  s32 result = 0;
  s32 count = 0;
  u8 *ptr = arg0;
  while (count != 4)
  {
    u8 value = ptr[2];
    count++;
    if (!value)
    {
      break;
    }
    if (value >= 0xA6)
    {
      result = 1;
      break;
    }
    ptr++;
  }

  return result;
}

extern s32 func_88000770(u8 *);
s32 func_880007B0(u8 *arg0) {
    s32 result = 0;
    if ((arg0[0] > 0) && (arg0[0] < 0x98) && ((arg0[0x1E] & 1) == 0)) {
        s32 temp = 0;
        result = temp;
        if (func_88000770(arg0) == 0) {
            result = 1;
        }
    }
    return result;
}

extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
void func_88000808(u8 type, s16 x, s16 y, s32 arg3, s32 arg4) {
    s32 icon;

    switch (type) {
        case 1:
            icon = 5;
            break;
        case 2:
            icon = 4;
            break;
        case 3:
            icon = 1;
            break;
        case 4:
            icon = 7;
            break;
        case 5:
            icon = 3;
            break;
        case 6:
            icon = 6;
            break;
        default:
            icon = 2;
            break;
    }
    func_8004D19C(x, y, func_8004C990(0x38, icon), arg3, arg4);
}

extern Gfx *D_800D0510;
void func_880008B0(s16 arg0, s16 arg1, s16 arg2) {
    s32 i;

    for (i = 0; i != 2; i++, arg1++) {
        gDPPipeSync(D_800D0510++);
        if (i == 0) {
            gDPSetFillColor(D_800D0510++, 0x10001);
        } else {
            gDPSetFillColor(D_800D0510++, 0xFFFFFFFF);
        }
        gDPFillRectangle(D_800D0510++, arg0, arg1, arg0 + arg2 - 1, arg1);
    }
}

extern void func_8004B2CC(s32, s32, s32, s32, s32, s32, s32, s32);
void func_880009A8(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    if (arg0 != 0) {
        func_8004B314(arg1 - arg5, arg2 - arg6, arg3 + (arg5 * 2), arg4 + (arg6 * 2));
        return;
    }
    func_8004B2CC(arg1 - arg5, arg2 - arg6, arg3 + (arg5 * 2), arg4 + (arg6 * 2), 0x96, 0x96, 0x5A, 0);
}

extern s16 *D_8800ECFC;
extern s16 *D_8800ED00;
extern s16 *D_8800ED04;
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_80044424(s16, s16, s16, s16, s16, s16, s16, s16, s32, s32);
void func_88000A5C(s16 x, s16 y, u32 kind) {
    switch (kind) {
    case 0:
        GfxRect_DrawTextured(x, y, D_8800ECFC[0], D_8800ECFC[1], 0, 0, 0x400, 0x400, 0);
        break;
    case 1:
        GfxRect_DrawTextured(x, y, D_8800ECFC[0], ((u16 *)D_8800ECFC)[1], 0, (((u16 *)D_8800ECFC)[1] - 1) << 5, 0x400, -0x400, 0);
        break;
    case 2:
        func_80044424(x, y, 14, D_8800ED04[1], 0, 0, 0x400, 0x400, 0, 1);
        break;
    case 3:
        func_80044424(x, y, 14, D_8800ED04[1], 0x1A0, 0, -0x400, 0x400, 0, 1);
        break;
    case 4:
        func_80044424(x, y, 10, D_8800ED00[1], 0, 0, 0x400, 0x400, 0, 2);
        break;
    case 5:
        func_80044424(x, y, 10, D_8800ED00[1], 0x120, 0, -0x400, 0x400, 0, 2);
        break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/29/fragment29_166060/func_88000C2C.s")

u32 Credits_RandomRange(u32 arg0) {
    s32 sp1C;

    if (arg0 == 0) {
        return 0U;
    }
    sp1C = guRandom();
    return (u32) ((u32) (osGetCount() + sp1C) / 10U) % arg0;
}

void func_88000EC0(s8 *arg0, s16 arg1, s32 arg2) {
    if (arg1 >= 100) {
        arg0[2] = arg1 / 100;
        arg1 -= arg0[2] * 100;
    } else if (arg2 != 0) {
        arg0[2] = 0;
    } else {
        arg0[2] = -1;
    }
    if (arg1 >= 10) {
        arg0[1] = arg1 / 10;
        arg1 -= arg0[1] * 10;
    } else if (arg0[2] > 0) {
        arg0[1] = 0;
    } else if (arg2 != 0) {
        arg0[1] = 0;
    } else {
        arg0[1] = -1;
    }
    arg0[0] = arg1;
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/29/fragment29_166060/func_88000FC4.s")

typedef struct {
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
} S1_unk_D_800A7440;
extern S1_unk_D_800A7440 *GfxRect_SetBounds(S1_unk_D_800A7440 *, s16, s16, s16, s16);
extern s32 GfxRect_ClipToScissor(S1_unk_D_800A7440 *);
extern Gfx *D_800D0510;
void func_88001144(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    S1_unk_D_800A7440 rect;

    GfxRect_SetBounds(&rect, arg0, arg1, arg0 + arg2 - 1, arg1 + arg3 - 1);
    if (GfxRect_ClipToScissor(&rect) != 0) {
        if ((arg4 == 0) || (arg4 == 0x100000)) {
            rect.y1++;
            rect.x2++;
        }
        gDPFillRectangle(D_800D0510++, rect.x1, rect.y2, rect.y1, rect.x2);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/29/fragment29_166060/func_88001234.s")

u16 func_880014A4(s32 arg0, u16 arg1) {
    u8 var_a3;
    u8 var_a2; //!bug Size selectors outside 0..3 leave the divisor uninitialized.

    switch (arg0) {
    case 0:
        var_a2 = 16;
        break;
    case 1:
        var_a2 = 8;
        break;
    case 2:
        var_a2 = 4;
        break;
    case 3:
        var_a2 = 2;
        break;
    }
    var_a3 = arg1 % var_a2;
    if (var_a3 != 0) {
        arg1 = (arg1 + var_a2) - var_a3;
    }
    switch (arg0) {
    case 0:
        arg1 = (s32)arg1 >> 2;
        break;
    case 1:
        arg1 = (s32)arg1 >> 1;
        break;
    case 3:
        arg1 <<= 1;
        break;
    }
    return 2048 / arg1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/29/fragment29_166060/func_880015F4.s")
#endif
