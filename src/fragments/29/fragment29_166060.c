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

/* mkdraft:func_88000C2C begin */
extern s32 D_80128C60;

// Draws four textured rectangles through func_88000A5C, setting an environment
// color before the first, between the second and third, and after the first and
// the third. arg0 and arg5 pick the light gray (220) over the dark gray (100)
// for the first and the third rectangle; the remaining eight arguments are the
// (x, y) pairs, drawn in kind order 2, 0, 1, 3. The two sequences that follow
// the first and the third rectangle and the light gray of the third rectangle
// are drawn only while the fragment state D_80128C60 is 0.
//
// arg0 and arg5 reload from their home slots with lhu and the other eight with
// lh, which is where their signedness comes from.


void func_88000C2C(u16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    gDPPipeSync(D_800D0510++);
    if (arg0) {
        gDPSetEnvColor(D_800D0510++, 220, 220, 220, 255);
    } else {
        gDPSetEnvColor(D_800D0510++, 100, 100, 100, 255);
    }
    func_88000A5C(arg1, arg2, 2);
    if (D_80128C60 == 0 && arg0) {
        gDPPipeSync(D_800D0510++);
        // 0xFFFF00FF: the blue channel is 0, as encoded in the retail ROM.
        gDPSetEnvColor(D_800D0510++, 255, 255, 0, 255);
    }
    func_88000A5C(arg3, arg4, 0);
    gDPPipeSync(D_800D0510++);
    if (arg5) {
        if (D_80128C60 == 0) {
            gDPSetEnvColor(D_800D0510++, 255, 255, 0, 255);
        } else {
            gDPSetEnvColor(D_800D0510++, 220, 220, 220, 255);
        }
    } else {
        gDPSetEnvColor(D_800D0510++, 100, 100, 100, 255);
    }
    func_88000A5C(arg6, arg7, 1);
    if (D_80128C60 == 0 && arg5) {
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 220, 220, 220, 255);
    }
    func_88000A5C(arg8, arg9, 3);
}
/* mkdraft:func_88000C2C end */

// Empty callback whose address sits between func_88000C2C and Credits_RandomRange.
// Fragment 31 passes it to func_882000AC as the do-nothing handler, so the retail
// `jr ra; nop` at 0x88000E4C is an empty function body, and it belongs to the same
// extracted .s file as func_88000C2C.
//@src/fragments/31/fragment31_179030.c
void D_88000E4C(void) {
}

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
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_88000EC0(s8 *, s16, s32);

// Draws the two digits of `first`/`second` as a 2x2 block. func_88000EC0 converts
// each s16 into `digits`; GfxRect_DrawTextured then draws it at (x, y) in an 8x14
// cell. Each digit advances x by dx + 8, and on the first iteration the second row
// is drawn below at y after adding dy + 8.
//
// The AND chain on x and the split shifts below are matching-only spellings: they
// compute the same s16 coordinate as `x` and `digits[n] << 8` (the parameter
// truncation drops the masked-off bits, and uopt folds the two constant shifts),
// but they change uopt's temporary-coloring walk so the emitted registers match the
// retail object. Replacing them with the folded forms was measured to disagree with
// the retail register assignment even though the instruction sequence is unchanged.


void func_88000FC4(s32 x, s32 y, s32 dx, s32 dy, s16 first, s16 second)
{
    s8 digits[4];
    s32 i;
    s16 values[2];

    values[0] = first;
    values[1] = second;
    for (i = 0; i < 2; i++)
    {
        func_88000EC0(digits, values[i], 0);
        if (digits[1] >= 0)
        {
            GfxRect_DrawTextured(x, y, 8, 14, (digits[1] << 2) << 6, 0, 0x400, 0x400, 0);
        }
        x += dx + 8;
        GfxRect_DrawTextured(((((x & 0xFFFFFFFFFFFFFFFF) & (0xFFFF ^ 0)) & 0xFFFF) & 0xFFFF) & 0xFFFF, y, 8, 14, (digits[0] << 8) ^ 0, 0, 0x400, 0x400, 0);
        if (i == 0)
        {
            x += dy + 8;
            GfxRect_DrawTextured(x, y, 8, 14, 0xA00, 0, 0x400, 0x400, 0);
            x += dy + 8;
        }
    }
}

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



s32 func_88001234(s32 arg0, u16 arg1, s32 arg2) {
    u16 value;

    switch (arg0) {
    case 0:
        if (arg1 & 0xF) {
            return 0;
        }
        arg1 = (s32)arg1 >> 2;
        break;
    case 1:
        if (arg1 & 7) {
            return 0;
        }
        arg1 = (s32)arg1 >> 1;
        break;
    case 2:
        if (arg1 & 3) {
            return 0;
        }
        break;
    case 3:
        if (arg1 & 1) {
            return 0;
        }
        arg1 *= 2;
        break;
    }
    if (arg2 != 0) {
        value = 0x800 / arg1;
    } else {
        switch (arg1) {
        case 0x4:
        case 0x8:
        case 0xC:
        case 0x10:
        case 0x14:
        case 0x18:
        case 0x1C:
        case 0x20:
        case 0x24:
        case 0x28:
        case 0x30:
        case 0x40:
        case 0x48:
        case 0x4C:
        case 0x64:
        case 0x6C:
        case 0x80:
        case 0x90:
        case 0x98:
        case 0xA4:
        case 0xC8:
        case 0xD8:
        case 0xE4:
        case 0x100:
        case 0x130:
        case 0x148:
        case 0x1B0:
        case 0x1C8:
        case 0x200:
        case 0x2AC:
        case 0x334:
        case 0x390:
            value = 0x800 / arg1;
            break;
        case 0x34:
            value = 0x1A;
            break;
        case 0x2C:
            value = 0x14;
            break;
        case 0x3C:
            value = 0x13;
            break;
        case 0x38:
            value = 0xE;
            break;
        case 0x44:
        case 0x68:
            value = 0xD;
            break;
        case 0x54:
            value = 9;
            break;
        case 0x50:
            value = 8;
            break;
        case 0x74:
            value = 6;
            break;
        case 0x60:
            value = 5;
            break;
        case 0x58:
        case 0x5C:
        case 0xA8:
        case 0xC4:
        case 0x13C:
            value = 4;
            break;
        case 0x70:
        case 0x78:
        case 0x8C:
            value = 3;
            break;
        case 0x7C:
        case 0x84:
        case 0x88:
        case 0x94:
        case 0x9C:
        case 0xAC:
        case 0xB0:
        case 0xB4:
        case 0xB8:
        case 0xBC:
        case 0xC0:
        case 0xD4:
        case 0xEC:
        case 0x11C:
        case 0x188:
        case 0x224:
        case 0x278:
            value = 2;
            break;
        case 0xA0:
        case 0xD0:
        case 0xE0:
        case 0xF4:
        case 0xFC:
        case 0x10C:
        case 0x114:
        case 0x128:
        case 0x158:
        case 0x168:
        case 0x178:
        case 0x19C:
        case 0x1E4:
        case 0x24C:
        case 0x2EC:
            value = 1;
            break;
        default:
            value = 0;
            break;
        }
    }
    return value;
}

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

/* mkdraft:func_880015F4 begin */
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern void func_800459AC(s32 *, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80046204(s32, s32, s32, u32, u32, u32, u32, u32, u32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_88001234(s32, u16, s32);


void func_880015F4(s16 arg0, s16 arg1, u16 arg2, u16 arg3, s16 *arg4, s32 arg5, s32 arg6, s32 arg7)
{
  s32 end_x;
  s32 start_x;
  s32 text_width;
  s32 row_y;
  s32 index;
  s32 gap;
  u16 h;
  s32 column_width;
  s32 flags;
  h = arg2;
  gap = 0;
  if ((arg5 == 0) && (arg6 == 2))
  {
    flags = 0x200000;
  }
  else
  {
    flags = 0;
  }
  column_width = func_88001234(arg6, h, arg7) * 1;
  if (column_width > 0)
  {
    if (arg7 != 0)
    {
      column_width &= 0xFFFE;
    }
  }
  else
  {
    gap = 1;
    column_width = func_880014A4(arg6, h ^ 0);
  }
  start_x = arg3 / column_width;
  text_width = arg3 % column_width;
  if (text_width)
  {
    start_x++;
  }
  else
  {
    text_width = column_width;
  }
  index = 0;
  row_y = arg1;
  if (start_x)
  {
    end_x = start_x - 1;
    do
    {
      if (index == end_x)
      {
        column_width = text_width;
      }
      if (gap)
      {
        func_80046204(arg4, arg5, arg6, arg2, column_width, 0, 0, arg2 - 1, column_width - 1, 0, 2, 2, 0, 0, 0, 0);
      }
      else
      {
        func_800459AC(arg4, arg5, arg6, arg2, column_width, arg7, 0, 2, 2, 0, 0, 0, 0);
      }
      GfxRect_DrawTextured(arg0, row_y, arg2, column_width, 0, 0, 0x400, 0x400, flags);
      switch (arg6)
      {
        case 0:
          arg4 += (arg2 * column_width) >> 2;
          break;

        case 1:
          arg4 += (arg2 * column_width) >> 1;
          break;

        case 2:
          arg4 += arg2 * column_width;
          break;

        case 3:
          arg4 += ((arg2 * column_width) * 2) ^ 0;
          break;

      }

      index++;
      row_y += column_width;
    }
    while (index != start_x);
  }
}
/* mkdraft:func_880015F4 end */
#endif
