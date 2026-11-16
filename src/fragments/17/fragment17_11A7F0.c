#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_11A7F0/func_8220AE30.s")

/* mkdraft:func_8220B248 begin */
extern f32 D_8220E050;
extern s16 D_8220E054;

typedef struct {
    f32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    f32 unk10;
    f32 unk14;
} Unk18;



void func_8220B248(s16 *arg0)
{
  Unk18 *e;
  s16 *o;
  s32 i;
  s32 v;
  f32 vx;
  f32 t;

  arg0[1] += 1;
  e = (Unk18 *) ((u8 *) arg0 + 0x18);
  o = arg0 + 2;
  v = arg0[1] - 10;
  if (v < 0)
  {
    v = 0;
  }
  arg0[4] = 0xFF - (s32) ((u32) v * 0xFF) / D_8220E054;
  if (arg0[4] > 0)
  {
    for (i = 0; i < 16; i += 4)
    {
      vx = e[0].unk10;
      t = (D_8220E050 * ((f32) arg0[1])) + e[0].unk14;
      e[0].unk00 = (vx * ((f32) arg0[1])) + ((f32) o[0]);
      e[0].unk04 = (t * ((f32) arg0[1])) + ((f32) o[1]);
      vx = e[1].unk10;
      t = (D_8220E050 * ((f32) arg0[1])) + e[1].unk14;
      e[1].unk00 = (vx * ((f32) arg0[1])) + ((f32) o[0]);
      e[1].unk04 = (t * ((f32) arg0[1])) + ((f32) o[1]);
      vx = e[2].unk10;
      t = (D_8220E050 * ((f32) arg0[1])) + e[2].unk14;
      e[2].unk00 = (vx * ((f32) arg0[1])) + ((f32) o[0]);
      e[2].unk04 = (t * ((f32) arg0[1])) + ((f32) o[1]);
      vx = e[3].unk10;
      t = (D_8220E050 * ((f32) arg0[1])) + e[3].unk14;
      e[3].unk00 = (vx * ((f32) arg0[1])) + ((f32) o[0]);
      e[3].unk04 = (t * ((f32) arg0[1])) + ((f32) o[1]);
      e += 4;
    }
  }
  else
  {
    arg0[0] = 0;
  }
}
/* mkdraft:func_8220B248 end */

/* mkdraft:func_8220B478 begin */
extern s16 D_822109C0;
extern s32 D_822109D4;
extern Gfx *D_800D0510;
extern Gfx D_8220E010;
extern u8 D_822109CC[];
extern u8 D_822109CF[];
extern s16 D_822109C8;
extern s32 func_8004D1FC(u8 *);
extern void func_8220B248(s16 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

typedef struct Fragment17SpriteSlot {
    f32 center_x;
    f32 center_y;
    f32 scale_x;
    f32 scale_y;
    u32 unk_10;
    u32 unk_14;
} Fragment17SpriteSlot;

extern Fragment17SpriteSlot D_822109D8[16];



void func_8220B478(void) {
    s16 *state;
    f32 bias;
    f32 width;
    f32 height;
    f32 *dims;
    s32 draw_width;
    s32 i;
    u16 *texture;
    Fragment17SpriteSlot *slot;

    state = &D_822109C0;
    if (*state != 0) {
        func_8220B248(state);
    }
    if (*state != 0) {
        texture = (u16 *)D_822109D4;
        slot = D_822109D8;
        if (texture != 0) {
            gSPDisplayList(D_800D0510++, &D_8220E010);
            gDPSetColor(D_800D0510++, 0xFA, _SHIFTL(D_822109CC[1], 16, 8) | _SHIFTL(D_822109CC[2], 8, 8) | _SHIFTL(D_822109CC[0], 24, 8) | _SHIFTL(D_822109C8, 0, 8));
            gDPSetColor(D_800D0510++, 0xFB, _SHIFTL(D_822109CF[1], 16, 8) | _SHIFTL(D_822109CF[2], 8, 8) | _SHIFTL(D_822109CF[0], 24, 8) | _SHIFTL(255, 0, 8));
            func_8004D1FC((u8 *)texture);
            i = 0;
            do {
                dims = (f32 *)((u8 *)slot + 8);
                width = (f32)(u32)texture[0] * slot->scale_x;
                height = (f32)(u32)texture[1] * slot->scale_y;
                bias = width > 0.0f ? 0.5f : -0.5f;
                draw_width = (s32)(bias + width);
                bias = height > 0.0f ? 0.5f : -0.5f;
                if (dims[0] > 0.001f && dims[1] > 0.001f) {
                    s16 scale_w = (s16)(1024.0f / dims[0]);
                    s16 scale_h = (s16)(1024.0f / dims[1]);

                    GfxRect_DrawTextured((s16)(s32)(slot->center_x - width / 2),
                                         (s16)(s32)(slot->center_y - height / 2),
                                         draw_width, (s32)(bias + height), 0, 0,
                                         scale_w, scale_h, 0);
                }
                i++;
                slot++;
            } while (i != 16);
        }
    }
}
/* mkdraft:func_8220B478 end */

s32 func_8004C990(s32, s32);
extern s16 D_822109C0;
extern s32 D_822109D4;

void func_8220B770(void) {
    D_822109C0 = 0;
    D_822109D4 = func_8004C990(0x93, 0);
}

/* The overlay header at 0x822109C0 (D_822109C0 above). linker_scripts/us/datamig_bss.ld
 * pins this object's .data there. func_8220B7A0 uses this definition because IDO's
 * assembler gives its four stores one lui only when the symbol is defined in this
 * file. FAKE: the one-element array, indexed by a variable, keeps IDO from loading
 * the address into a base register. */
typedef struct F17OverlayHeader {
    /* 0x00 */ s16 state;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
} F17OverlayHeader; // size = 0x8

typedef struct F17Rgb {
    u8 r;
    u8 g;
    u8 b;
} F17Rgb;

static F17OverlayHeader sOverlayHeader[1] = { 0 };

extern void func_8220AE30(F17OverlayHeader *);

// Starts the overlay when it is idle: stores the position and the two colors
// (D_822109CC, with alpha D_822109C8 = 255, and D_822109CF) that func_8220B478
// draws with. Returns 1 when started and 0 when the overlay was already active.
s32 func_8220B7A0(s32 x, s32 y, u8 *color, u8 *color2) {
    s32 result = 0;
    s32 i = 0; // FAKE: constant index written as a variable (see F17OverlayHeader)

    if (sOverlayHeader[i].state == 0) {
        sOverlayHeader[i].state = 1;
        sOverlayHeader[i].unk_02 = 0;
        sOverlayHeader[i].x = x;
        sOverlayHeader[i].y = y;
        *(F17Rgb *)D_822109CC = *(F17Rgb *)color;
        result = 1;
        *(F17Rgb *)D_822109CF = *(F17Rgb *)color2;
        D_822109C8 = 0xFF;
        func_8220AE30(sOverlayHeader);
    }
    return result;
}
#endif
