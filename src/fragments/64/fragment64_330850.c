#include "global.h"


#ifdef VERSION_US
void func_87F0DBE0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x0) = 0;
    *(s32 *)(arg0 + 0x4) = arg1;
    arg0[0x10] = 0;
    arg0[0x12] &= 0xFF7F;
}

void func_87F0DBFC(u8 *arg0, s32 arg1, u8 arg2, s32 arg3) {
    struct State {
        s32 value, unused, count, limit;
        u8 index, mode;
        u8 active : 1;
        u8 other : 7;
    };
    struct State *state = (struct State *)arg0;
    state->value = arg1;
    state->active = 1;
    state->index = 0;
    state->mode = arg2;
    state->count = 0;
    state->limit = arg3;
    if (arg3 == -1) {
        state->value = 0;
        state->limit = 1;
    }
}

void func_87F0DC3C(u8 *arg0) { arg0[0x12] &= 0xFF7F; }

/* mkdraft:func_87F0DC4C begin */
extern f32 D_87F11740;
extern f32 D_80088E50[];

typedef struct State {
  s32 value;
  s32 unused;
  s32 count;
  s32 limit;
  u8 index;
  u8 mode;
  u8 active : 1;
  u8 other : 7;
} State;



void func_87F0DC4C(State *state)
{
  f32 progress;
  f32 v;
  s32 value;
  if (state->active)
  {
    if ((++state->count) > state->limit)
    {
      state->count = state->limit;
      value = state->value;
      switch (value)
      {
        case 1:

        case 3:
          state->active = 0;
          break;

      }

    }
    progress = ((f32) state->count) / ((f32) state->limit);
    value = state->value;
    switch (value)
    {
      case 0:
        state->index = state->mode;
        break;

      case 1:
        v = (360.0f * progress) * D_87F11740;
        if (v >= 0.0f)
      {
        value = (s32) (v + 0.5f);
      }
      else
      {
        value = (s32) (v - 0.5f);
      }
        state->index = (u32) (((f32) state->mode) * (1.0f - D_80088E50[((u16) value) >> 4]));
        if (state->mode < state->index)
        {
          state->index = state->mode;
        }
        break;

      case 2:
        state->index = (u8) (((f32) state->mode) * progress);
        break;

      case 3:
        state->index = (u8) (((f32) state->mode) * (1.0f - progress));
        break;

    }

  }
}
/* mkdraft:func_87F0DC4C end */

/* mkdraft:func_87F0DFB4 begin */
extern Gfx *D_800D0510;
extern Gfx D_87F11380[];



void func_87F0DFB4(u8 *arg0) {
    s8 var_a1;
    u32 image;

    if ((*(s16 *)(arg0 + 0x12) >> 15) != 0) {
        var_a1 = (*(s8 **)(arg0 + 4))[0x16] - 1;
        if (var_a1 < 0) {
            var_a1 = (*(s8 **)(arg0 + 4))[0xE] - 1;
        }
        image = *(u32 *)(*(s8 **)(arg0 + 4) + var_a1 * 4 + 0x18);
        gSPDisplayList(D_800D0510++, D_87F11380);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0xFF, arg0[0x10]);
        if ((*(s8 **)(arg0 + 4))[0xC] == 1) {
            s32 var_s0, var_s1, var_t4;

            for (var_s0 = 0, var_s1 = 2, var_t4 = 3; var_t4 != 0x1E3; var_t4 += 3) {
                gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 640, *(u8 **)(image + 8));
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, G_TX_LOADTILE, 0, 3, 0, 0, 2, 0, 0);
                gDPLoadSync(D_800D0510++);
                gDPLoadTile(D_800D0510++, G_TX_LOADTILE, 0, var_s0 << 2, 0x9FC, var_s1 << 2);
                gDPPipeSync(D_800D0510++);
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 0, G_TX_RENDERTILE, 0, 3, 0, 0, 2, 0, 0);
                gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, var_s0 << 2, 0x9FC, var_s1 << 2);
                gSPTextureRectangle(D_800D0510++, 0, var_s0 << 2, 0xA00, var_t4 << 2, 0, 0, 0, 0x400, 0x400);
                var_s1 += 3;
                var_s0 += 3;
            }
        } else {
            s32 var_t5, var_s0, var_t4;

            for (var_t5 = 0, var_s0 = 0, var_t4 = 6; var_t4 != 0xF6; var_t4 += 6) {
                gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, *(u8 **)(image + 8) + var_t5);
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 3, 0, 0, 2, 0, 0);
                gDPLoadSync(D_800D0510++);
                gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 0x77F, 0x1A);
                gDPPipeSync(D_800D0510++);
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 0, G_TX_RENDERTILE, 0, 3, 0, 0, 2, 0, 0);
                gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 0x4FC, 0x14);
                gSPTextureRectangle(D_800D0510++, 0, var_s0 << 2, 0x500, var_t4 << 2, 0, 0, 0, 0x400, 0x400);
                var_t5 += 0xF00;
                var_s0 += 6;
            }
        }
    }
}
/* mkdraft:func_87F0DFB4 end */
#endif
