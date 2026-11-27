#include "global.h"

#ifdef VERSION_US
extern s16 D_82508F6E;
s32 func_82500020(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_82508F6E != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82508F80;
s32 func_82500064(s32 arg0, s32 arg1) { switch (arg0) { case 0: D_82508F80 = arg1; break; case 1: break; default: break; } return 0; }
#endif

#ifdef VERSION_US
extern u16 D_82508790;
extern f32 D_80088E50[];
s32 func_8250008C(s32 arg0, u8 *arg1) {
    u16 *state;
    u16 value;
    unsigned int new_var2;
    f32 sample;
    f32 square;
    f32 scaled;
    f32 bias;
    float new_var;
    s32 result;
    if ((arg0 != 0) && (arg0 == 1))
    {
        state = &D_82508790;
        value = *state;
        scaled = D_80088E50[value >> 4];
        sample = scaled;
        new_var = 255.0f;
        square = sample * sample;
        scaled = square * new_var;
        bias = (scaled > 0.0f) ? (0.5f) : (-0.5f);
        result = (s32) (bias + scaled);
        arg1[0x33] = result;
        arg1[0x2F] = result;
        new_var2 = value;
        *((0, state)) = new_var2 + 0x100;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u16 D_82508794;
extern f32 D_80088E50[];
s32 func_82500120(s32 arg0, u8 *arg1) {
    u16 *state;
    u16 value;
    unsigned int next;
    f32 sample;
    f32 square;
    f32 scaled;
    f32 bias;
    float scale;
    s32 result;
    if ((arg0 != 0) && (arg0 == 1)) {
        state = &D_82508794;
        value = *state;
        scaled = D_80088E50[value >> 4];
        sample = scaled;
        scale = 255.0f;
        square = sample * sample;
        scaled = square * scale;
        bias = (scaled > 0.0f) ? 0.5f : -0.5f;
        result = (s32)(bias + scaled);
        arg1[0x2F] = result;
        arg1[0x2B] = result;
        next = value;
        *((0, state)) = next + 0x100;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s16 D_82508F6C;
s32 func_825001B4(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_82508F6C != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_825001F8 begin */
extern u8 *D_82508F84;
extern u8 D_82508D12[];
extern s16 D_82508F6A;
extern s16 D_82508F74;
extern Gfx D_82508760[];
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern void func_82502120(void *, void *, s32, s32, s32);

typedef struct { u8 r, g, b, a; } Func825001F8RGBA;

// Emits one color pair for the entry selected by *(s32 *)(arg1 + 0x20): a display
// list from D_82508760, then gDPSetPrimColor/gDPSetEnvColor built from the two RGBA
// quadruples that func_82502120 writes to prim/env. The two colors are read from the
// 0x30-byte entry table at *(u8 **)(D_82508F84 + 0x1C) when *(s16 *)(D_82508F84 + 0x12)
// is set, and from arg1 + 0x24/0x26 otherwise; a negative second component falls back
// to the 0x20/0x28 pair of the table. func_8004C990 packs the pair, and func_8004D19C
// receives the packed color with the halfwords at arg1 + 8/0xA and two zero arguments.


s32 func_825001F8(s32 arg0, void *arg1)
{
  s32 index;
  s32 var_v0;
  u8 *temp_v1;
  s32 var_s0;
  s32 packed;
  s32 pad0; // FAKE: dummy local; without it prim/env move to sp+0x3C/sp+0x38 and the diff score is 64.
  s16 color[2];
  s32 pad1; // FAKE: dummy local; without it prim/env move to sp+0x3C/sp+0x38 and the diff score is 84.
  s32 pad2; // FAKE: dummy local; without it prim/env move to sp+0x3C/sp+0x38 and the diff score is 84.
  Func825001F8RGBA prim;
  Func825001F8RGBA env;
  // FAKE: address of the global pointer, used only for the five reads after the
  // D_82508D12 test. Reading D_82508F84 directly instead makes IDO keep one loaded
  // pointer and the function shrinks from 121 to 114 instructions (diff score 2995).
  u8 **new_var = &D_82508F84;
  index = *((s32 *) (((u8 *) arg1) + 0x20));
  if ((arg0 != 0) && (arg0 == 1))
  {
    *((u16 *) (((u8 *) arg1) + 2)) &= 0xFFFD;
    temp_v1 = (*((u8 **) (D_82508F84 + 0x1C))) + (index * 0x30);
    if ((*((s16 *) (D_82508D12 + (index * 0x3C)))) == 0)
    {
      var_v0 = 0;
    }
    else
    {
      var_v0 = 1;
    }
    if ((*((s16 *) ((*new_var) + 0x12))) != 0)
    {
      if (var_v0 != 0)
      {
        color[1] = *((s16 *) ((*new_var) + 0x22));
        var_s0 = *((s16 *) (temp_v1 + 0x2A));
      }
      else
      {
        color[1] = *((s16 *) ((*new_var) + 0x20));
        var_s0 = *((s16 *) (temp_v1 + 0x28));
      }
      if (var_s0 < 0)
      {
        color[1] = *((s16 *) ((*new_var) + 0x20));
        var_s0 = *((s16 *) (temp_v1 + 0x28));
      }
    }
    else
    {
      color[1] = *((u16 *) (((u8 *) arg1) + 0x24));
      var_s0 = *((s16 *) (((u8 *) arg1) + 0x26));
    }
    func_82502120(&prim, &env, D_82508F6A, D_82508F74, *((s16 *) ((*new_var) + 0x1A)));
    packed = func_8004C990(color[1], var_s0);
    gSPDisplayList(D_800D0510++, D_82508760);
    gDPSetPrimColor(D_800D0510++, 0, 0xFF, prim.r, prim.g, prim.b, 0xFF);
    gDPSetEnvColor(D_800D0510++, env.r, env.g, env.b, 0xFF);
    func_8004D19C(*((s16 *) (((u8 *) arg1) + 8)), *((s16 *) (((u8 *) arg1) + 0xA)), packed, 0, 0);
  }
  return 0;
}
/* mkdraft:func_825001F8 end */
#endif

#ifdef VERSION_US
f32 func_825003DC(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 end1;
    s32 end2;
    s32 phase;
    f32 result;

    end1 = arg1 + arg2;
    end2 = end1 + arg3;
    *arg5 = 0;
    phase = arg0 % (u32)(end2 + arg4);
    if (phase < arg1) {
        result = (f32)phase / (f32)arg1;
    } else if (phase < end1) {
        if (phase == arg1) {
            *arg5 = 1;
        }
        result = 1.0f;
    } else if (phase < end2) {
        result = 1.0f - (f32)(phase - arg1 - arg2) / (f32)arg3;
    } else {
        result = 0.0f;
    }
    return result;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_825004A4 begin */
extern Gfx *D_800D0510;
extern u8 D_80094E78[];
extern s32 func_8004D1FC(u8 *);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

// Four-byte colour word read as r, g, b, a by the G_SETENVCOLOR / G_SETPRIMCOLOR
// packing macros. func_82500EF4, declared further down this file, gives the same
// layout the name unk_func_82500EF4; the two typedefs can be merged once this
// function sits next to that declaration.
typedef struct unk_func_825004A4 {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
    /* 0x03 */ u8 a;
} unk_func_825004A4;

// The file defines ROUND_MAX only below this point, so a call would be emitted
// without this prologue copy.
#ifndef ROUND_MAX
#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
#endif

void func_825004A4(s32 arg0, s32 arg1, u16 *arg2, f32 arg3, u8 *arg4, u8 *arg5, s32 arg6) {
    s32 draw_width;
    s32 draw_height;
    s32 x_offset;
    s32 y_offset;

    if (arg3 > 0.0f) {
        draw_width = (s32)ROUND_MAX((f32)(u32)arg2[0] * arg3);
        draw_height = (s32)ROUND_MAX((f32)(u32)arg2[1] * arg3);
        x_offset = (arg2[0] - draw_width) / 2;
        y_offset = (arg2[1] - draw_height) / 2;
        gSPDisplayList(D_800D0510++, D_80094E78);
        gDPSetEnvColor(D_800D0510++, ((unk_func_825004A4 *)arg4)->r, ((unk_func_825004A4 *)arg4)->g, ((unk_func_825004A4 *)arg4)->b, ((unk_func_825004A4 *)arg4)->a);
        gDPSetPrimColor(D_800D0510++, 0, 0, ((unk_func_825004A4 *)arg5)->r, ((unk_func_825004A4 *)arg5)->g, ((unk_func_825004A4 *)arg5)->b, ((unk_func_825004A4 *)arg5)->a);
        if (arg6 != 0) {
            func_8004D1FC((u8 *)arg2);
            GfxRect_DrawTextured((s16)(arg0 + x_offset), (s16)(arg1 + y_offset), (s16)draw_width, (s16)draw_height, 0, 0,
                                 (s32)ROUND_MAX(1024.0f / arg3), (s32)ROUND_MAX(1024.0f / arg3), 0);
        } else {
            func_8004D19C(arg0, arg1, (s32)arg2, 0, 0);
        }
    }
}
/* mkdraft:func_825004A4 end */
#endif
