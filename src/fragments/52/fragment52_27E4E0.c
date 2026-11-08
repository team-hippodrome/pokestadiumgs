#include "global.h"


void func_86400020(void) {
}

#ifdef VERSION_US
extern u8 D_86409668[];
extern u8 D_86409688[];
extern u8 D_864096E8[];
extern void func_87D00648(void *, void *, void *);
extern f32 func_87D0059C(f32 *, f32 *);
void func_86400028(void)
{
  u8 *var_s0;
  u8 *table;
  s32 var_s1;
  var_s0 = D_86409688;
  table = D_86409668;
 var_s1 = 0; do { u8 *temp_s2; u8 *temp_a1; u8 *temp_a2;
    temp_s2 = var_s0 + 0xC;
    temp_a1 = table + (var_s0[0] << 3);
    temp_a2 = table + (var_s0[1] << 3);
    *((f32 *) (var_s0 + 4)) = (*((f32 *) (temp_a2 + 0))) - (*((f32 *) (temp_a1 + 0)));
    *((f32 *) (var_s0 + 8)) = (*((f32 *) (temp_a2 + 4))) - (*((f32 *) (temp_a1 + 4)));
    func_87D00648(temp_s2, temp_a1, temp_a2);
    func_87D0059C((f32 *) temp_s2, (f32 *) (var_s0 + 0x10));
    var_s1 += 1;
    var_s0 += 0x18;
  }
  while (var_s1 < 4);
  var_s0 = D_864096E8;
  var_s1 = 0;
  do
  {
    u8 *temp_v0;
    temp_v0 = table + (var_s0[0] << 3);
    *((f32 *) (var_s0 + 4)) = *((f32 *) (temp_v0 + 0));
    *((f32 *) (var_s0 + 8)) = *((f32 *) (temp_v0 + 4));
    func_87D0059C((f32 *) (var_s0 + 4), (f32 *) (var_s0 + 8));
    var_s1 += 1;
    var_s0 += 0xC;
  }
  while (var_s1 != 4);
}
#endif

#ifdef VERSION_US
extern f32 func_87D00720(void *, void *, void *, f32 *, f32 *);
extern s32 func_87D00670(void *, void *, f32 *, void *, void *, f32 *);

s32 func_86400114(void *arg0, f32 arg1, void *arg2, void *arg3, void *arg4, f32 *arg5) {
    f32 sp30[2];
    f32 sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp28 = 0;
    func_87D00720(arg0, arg2, arg3, sp30, &sp2C);
    if ((sp2C < arg1) &&
        (func_87D00670(arg0, arg4, &sp24, arg2, arg3, &sp20) != 0) &&
        (sp20 >= 0.0f) && (sp20 <= 1.0f)) {
        *arg5 = arg1 - sp2C;
        sp28 = 1;
    }
    return sp28;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864001E0 begin */
s32 func_864001E0(f32 *arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 normal_x;
    f32 normal_y;
    f32 delta_y;
    f32 distance;
    f32 delta_x;
    s32 within_radius;

    within_radius = 0;
    arg4[0] = arg0[0] - arg2[0];
    delta_x = arg4[0];
    arg4[1] = arg0[1] - arg2[1];
    delta_y = arg4[1];
    distance = sqrtf((delta_x * delta_x) + (delta_y * delta_y));
    if (distance < arg1) {
        if (distance == 0.0f) {
            arg4[0] = arg3[0];
            arg4[1] = arg3[1];
        } else {
            arg4[0] = delta_x / distance;
            arg4[1] = delta_y / distance;
        }
        normal_y = arg4[1];
        if (((normal_y * arg3[1]) + (arg3[0] * arg4[0])) >= 0.0f) {
            *arg5 = arg1 - distance;
        } else {
            // The retail routine writes the normal back unchanged on this path.
            normal_x = arg4[0];
            arg4[0] = normal_x;
            arg4[1] = normal_y;
            *arg5 = arg1 + distance;
        }
        within_radius = 1;
    }
    return within_radius;
}
/* mkdraft:func_864001E0 end */
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern s32 func_87F026E8(s32, void *);
extern s32 D_87F119D8;
extern void *D_87F119DC;

/* Per-frame update callback of the D_87F119DC node (registered through
 * func_87F025B8 in func_86400804; the fragment 64 walker invokes it at
 * node offset 8 and increments the 0x1C counter it tests here):
 * position (0x48/0x4C/0x50) += velocity (0x10/0x14/0x18); scale
 * (0x54/0x58/0x5C) *= growth factor, where flag 0x10000000 in word 0xC
 * selects D_86409990 (35/33, 1.0606060f) over D_86409994 (1.05f);
 * velocity decays, x/z (0x10/0x18) *= D_86409998 (0.8f) and y (0x14) *=
 * D_8640999C (0.95f); s16 0x46 += 0xFF (255); once the walker's counter
 * at 0x1C reaches the rounded 10Hz frame count ((f32)func_80001FF0() /
 * 60.0f * 6.0f; func_80001FF0 returns 50 or 60 from osTvType), hands the
 * node to func_87F026E8(D_87F119D8, D_87F119DC) - the same dequeue call
 * as func_8630421C in fragment 51. */
void func_864002CC(void) {
    f32 var_fv0;
    f32 var_fv1;
    s32 var_a0;

    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
    *(f32 *)((u8 *)D_87F119DC + 0x50) += *(f32 *)((u8 *)D_87F119DC + 0x18);
    var_fv0 = (*(s32 *)((u8 *)D_87F119DC + 0xC) & 0x10000000) ? 1.06f : 1.05f;
    var_fv1 = 0.8f;
    if (var_fv1 == var_fv1) {} // FAKE: fully-DCE'd self-compare (nothing reaches the ROM - not original karodo); the dead compare still mentions var_fv1 in uopt's FPR walk, demoting it behind var_fv0 (f0) so var_fv1 takes f2
    *(f32 *)((u8 *)D_87F119DC + 0x54) = *(f32 *)((u8 *)D_87F119DC + 0x54) * var_fv0;
    *(f32 *)((u8 *)D_87F119DC + 0x58) = *(f32 *)((u8 *)D_87F119DC + 0x58) * var_fv0;
    *(f32 *)((u8 *)D_87F119DC + 0x5C) = *(f32 *)((u8 *)D_87F119DC + 0x5C) * var_fv0;
    *(f32 *)((u8 *)D_87F119DC + 0x10) = *(f32 *)((u8 *)D_87F119DC + 0x10) * var_fv1;
    *(f32 *)((u8 *)D_87F119DC + 0x14) = *(f32 *)((u8 *)D_87F119DC + 0x14) * 0.95f;
    *(f32 *)((u8 *)D_87F119DC + 0x18) = *(f32 *)((u8 *)D_87F119DC + 0x18) * var_fv1;
    *(s16 *)((u8 *)D_87F119DC + 0x46) = *(s16 *)((u8 *)D_87F119DC + 0x46) + 0xFF;
    if ((((f32)func_80001FF0() / 60.0f) * 6.0f) >= 0.0f) {
        var_a0 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) + 0.5f);
    } else {
        var_a0 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) - 0.5f);
    }
    if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= var_a0) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
void * func_8004C990();
extern void *func_8004CA60(void *);
extern void func_8003CD84(void);
extern Gfx *D_800D0510;
extern u8 D_86409718[];
extern u8 D_864098C0[];
extern void *D_8009491C;
/* Draws one HUD-style quad: picks a palette entry from D_86409718 and a colour from the
 * object's flags at 0xC, fades it out by the rounded 10Hz frame count, then queues
 * pipe-sync / env-colour / segment / display-list into D_800D0510 and flushes. */


void func_864004B4(s32 arg0, s32 arg1) {
    u8 *link;
    u8 *obj;
    f32 alpha;
    u8 r;
    u8 g;
    u8 b;
    u8 idx;
    if (arg0 != 5) {
        return;
    }
    link = D_8009491C;
    obj = *(u8 **)((u8 *)link + 0x14);
    idx = D_86409718[(*((s32 *)(obj + 0x1C)) % 16) / 2];
    alpha = 255.0f; alpha -= (255.0f * (f32)*((s32 *)(obj + 0x1C))) / (f32)((((f32)func_80001FF0() / 60.0f) * 6.0f) >= 0.0f ? (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) + 0.5f) : (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) - 0.5f));
    if (*((s32 *)(obj + 0xC)) & 0x01000000) {
        r = 0x8C;
        g = 0x8C;
        b = 0xC8;
    } else if (*((s32 *)(obj + 0xC)) & 0x02000000) {
        r = 0x8C;
        g = 0xC8;
        b = 0x8C;
    } else if (*((s32 *)(obj + 0xC)) & 0x04000000) {
        r = 0xDC;
        g = 0x8C;
        b = 0x8C;
    } else if (*((s32 *)(obj + 0xC)) & 0x08000000) {
        r = 0xDC;
        g = 0x8C;
        b = 0x8C;
    } else {
        r = 0xC8;
        g = 0xAA;
        b = 0x82;
    }
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, r, g, b, alpha);
    gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0x9F, idx)));
    gSPDisplayList(D_800D0510++, D_864098C0);
    func_8003CD84();
}
#endif

#ifdef VERSION_US
extern void func_87F05FB0(s32, s32, s32, s32, s32);
extern s32 D_80094908;
void func_864007B8(s32 arg0, s32 arg1) {
    if (arg0 == 2) {
        func_87F05FB0(arg1 + 0x60, D_80094908 + 0x64, arg1 + 0x24, arg1 + 0x1E, arg1 + 0x30);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern u32 func_8003570C(void);
extern void func_80037E3C(void *, void *, void *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 *func_87F025B8(void *, void *);
extern u8 *D_86416C00;
extern void func_864002CC(void);
void func_86400804(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    u8 *object;
    // karodo: unused declaration. IDO reserves its home slot at 0x30(sp), which keeps the
    // spilled object+0x24 common subexpression at 0x24(sp) as in the original frame layout.
    u8 *sp30;
    u32 sp2C;
    s32 var_v1;

    object = func_87F025B8(D_86416C00 + 0x3334, (void *)func_864002CC);
    if (object != NULL) {
        func_80037E3C(object + 0x24, (void *)func_864007B8, object);
        func_8003F1DC(object + 0x24);
        func_8003F114(object + 0x24, 0, -1, *(s32 *)(D_86416C00 + 0x7B8));
        *(u8 *)(object + 0x26) |= 0x10;
        sp2C = func_8003570C();
        if ((((f32)func_80001FF0() / 60.0f) * 6.0f) >= 0.0f) {
            var_v1 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) + 0.5f);
        } else {
            var_v1 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) - 0.5f);
        }
        *(u32 *)(object + 0x1C) = sp2C % (u32)((var_v1 >> 2) + 1);
        *(f32 *)(object + 0x48) = arg0;
        *(f32 *)(object + 0x4C) = arg1;
        *(f32 *)(object + 0x50) = arg2;
        *(f32 *)(object + 0x54) = arg3;
        *(f32 *)(object + 0x58) = arg3;
        *(f32 *)(object + 0x5C) = arg3;
        *(f32 *)(object + 0x10) = arg4;
        *(f32 *)(object + 0x14) = arg5;
        *(f32 *)(object + 0x18) = arg6;
        *(s32 *)(object + 0xC) = *(s32 *)(object + 0xC) | arg7;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864009D4 begin */
extern s32 func_80001FF0(void);
extern s32 func_87F026E8(s32, void *);
extern s32 D_87F119D8;
extern void *D_87F119DC;
extern u8 *D_86416C00;

// Per-frame callback of the D_87F119DC effect node. func_864012A0 registers it
// through func_87F025B8(D_86416C00 + 0xE00, func_864009D4) and sets the fields
// read here: word 0xC = 0x10000000, counter 0x1C = 0, position 0x48/0x4C/0x50 =
// its three f32 arguments, scale 0x54/0x58/0x5C = 2.5f, velocity 0x10/0x14/0x18
// = 0.0f, and the u8 at (*(node + 0x20)) + 4.
//
// Position 0x48/0x4C/0x50 += velocity 0x10/0x14/0x18, velocity *= 0.95f, and the
// s32 addressed by node + 0x20 is incremented. Word 0xC selects one of three
// stages; each compares the frame counter at 0x1C (incremented by the walker
// that invokes the callback - func_864002CC reads the same counter) against a
// frame count scaled from 60 Hz, then zeroes 0x1C:
//   bit28 set (by func_864012A0): 5 frames, clear bit28, set bit29;
//   bit28 and bit30 clear (the only arm left for bit29): 175 frames, clear
//     bit29, set bit30;
//   bit30 set: 10 frames, then decrement the s32 at 0x4BC8 of record
//     (*(u8 *) (node + 0x20) + 4) in the D_86416C00 + 0x8000 array of 0x5C-byte
//     records, and hand the node to func_87F026E8(D_87F119D8, D_87F119DC).
// The frame count is ((f32)func_80001FF0() / 60.0f) * N and func_80001FF0
// returns 50 or 60 from osTvType, so N is a 60 Hz frame count scaled to the
// console's refresh rate; func_864002CC converts the same way.


void func_864009D4(void) {
    s32 *counter;
    u8 *entry;
    s32 state;
    s32 threshold;

    counter = *(s32 **)((u8 *)D_87F119DC + 0x20);
    *counter += 1;
    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
    *(f32 *)((u8 *)D_87F119DC + 0x50) += *(f32 *)((u8 *)D_87F119DC + 0x18);
    *(f32 *)((u8 *)D_87F119DC + 0x10) *= 0.95f;
    *(f32 *)((u8 *)D_87F119DC + 0x14) *= 0.95f;
    *(f32 *)((u8 *)D_87F119DC + 0x18) *= 0.95f;
    state = *(s32 *)((u8 *)D_87F119DC + 0xC);
    if (state & 0x10000000) {
        if ((((f32)func_80001FF0() / 60.0f) * 5.0f) >= 0.0f) {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 5.0f) + 0.5f);
        } else {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 5.0f) - 0.5f);
        }
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= threshold) {
            *(s32 *)((u8 *)D_87F119DC + 0xC) &= 0xEFFFFFFF;
            *(s32 *)((u8 *)D_87F119DC + 0xC) |= 0x20000000;
            *(s32 *)((u8 *)D_87F119DC + 0x1C) = 0;
        }
    } else if (state & 0x40000000) {
        if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
        } else {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
        }
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= threshold) {
            entry = ((u8 (*)[0x5C]) (D_86416C00 + 0x8000))[*(u8 *)((u8 *)counter + 4)];
            *(s32 *)(entry + 0x4BC8) -= 1;
            func_87F026E8(D_87F119D8, D_87F119DC);
        }
    } else {
        if ((((f32)func_80001FF0() / 60.0f) * 175.0f) >= 0.0f) {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 175.0f) + 0.5f);
        } else {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 175.0f) - 0.5f);
        }
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= threshold) {
            *(s32 *)((u8 *)D_87F119DC + 0xC) &= 0xDFFFFFFF;
            *(s32 *)((u8 *)D_87F119DC + 0xC) |= 0x40000000;
            *(s32 *)((u8 *)D_87F119DC + 0x1C) = 0;
        }
    }
}
/* mkdraft:func_864009D4 end */
#endif

#ifdef VERSION_US
extern u8 D_86409720;
extern float sqrtf(float value);
extern s32 func_80001FF0(void);
extern u8 *D_86416C00;
extern void func_8003CD84(void);
extern u8 D_864095D0;



void func_86400DDC(s32 arg0, s32 arg1)
{
  u8 level;
  u8 *model;
  u8 *child;
  u8 alpha;
  u8 *colors;
  u8 *env_colors;
  // Never read. Its presence alone moves the "segment" Gfx pointer from
  // 0x1c(sp) to the retail 0x18(sp).
  s32 random;
  if (arg0 == 5)
  {
    arg0 = (s32) D_8009491C;
    model = *((u8 **) (arg0 + 0x14));
    child = *((u8 **) (model + 0x20));
    alpha = (&D_86409720)[(*((s32 *) child)) & 0xF];
    level = child[4];
    colors = (&D_864095D0) + ((level << 2) << 1);
    env_colors = colors + 4;
    if ((*((s32 *) (model + 0xC))) & 0x10000000)
    {
      level = (u8) ((200.0f * ((f32) (*((s32 *) (model + 0x1C))))) / ((f32) (((((((f32) func_80001FF0()) / 60.0f) * 5.0f) >= 0.0f) ? (s32) (((((f32) func_80001FF0()) / 60.0f) * 5.0f) + 0.5f) : (s32) (((((f32) func_80001FF0()) / 60.0f) * 5.0f) - 0.5f)))));
      // FAKE: empty loop, nothing reaches the ROM. Deleting it makes the differ
      // score 295 instead of 0 (it only shifts IDO's statement numbering).
      do
      {
      }
      while (0);
    }
    else
      if ((*((s32 *) (model + 0xC))) & 0x40000000)
    {
      level = (u8) (200.0f - ((200.0f * ((f32) (*((s32 *) (model + 0x1C))))) / ((f32) (((((((f32) func_80001FF0()) / 60.0f) * 10.0f) >= 0.0f) ? (s32) (((((f32) func_80001FF0()) / 60.0f) * 10.0f) + 0.5f) : (s32) (((((f32) func_80001FF0()) / 60.0f) * 10.0f) - 0.5f))))));
    }
    else
    {
      level = 200;
    }
    {
      Gfx *_g = (Gfx *) ((*((Gfx **) (&D_800D0510)))++);
      _g->words.w0 = (unsigned int) ((((unsigned int) 0xe7) & ((0x01 << 8) - 1)) << 24);
      _g->words.w1 = 0;
    }
    ;
    {
      Gfx *_g = (Gfx *) ((*((Gfx **) (&D_800D0510)))++);
      _g->words.w0 = ((unsigned int) ((((unsigned int) 0xfc) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((((((unsigned int) ((((unsigned int) 3) & ((0x01 << 4) - 1)) << 20)) | ((unsigned int) ((((unsigned int) 1) & ((0x01 << 5) - 1)) << 15))) | ((unsigned int) ((((unsigned int) 5) & ((0x01 << 3) - 1)) << 12))) | ((unsigned int) ((((unsigned int) 1) & ((0x01 << 3) - 1)) << 9))) | (((unsigned int) ((((unsigned int) 15) & ((0x01 << 4) - 1)) << 5)) | ((unsigned int) ((((unsigned int) 31) & ((0x01 << 5) - 1)) << 0))))) & ((0x01 << 24) - 1)) << 0)); _g->words.w1 = (unsigned int) ((((((unsigned int) ((((unsigned int) 5) & ((0x01 << 4) - 1)) << 28)) | ((unsigned int) ((float) ((((unsigned int) 5) & ((0x01 << 3) - 1)) << 15)))) | ((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 12))) | ((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 9))) | (((((((unsigned int) ((((unsigned int) 15) & ((0x01 << 4) - 1)) << 24)) | ((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 21))) | ((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 18))) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 3) - 1)) << 6))) | ((unsigned int) ((((unsigned int) 7) & ((0x01 << 3) - 1)) << 3))) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 3) - 1)) << 0))));
    }
    ;
    {
      Gfx *_g = (Gfx *) ((*((Gfx **) (&D_800D0510)))++);
      _g->words.w0 = (((unsigned int) ((((unsigned int) 0xfa) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 8) - 1)) << 0));
      _g->words.w1 = ((((unsigned int) ((((unsigned int) colors[1]) & ((0x01 << 8) - 1)) << 16)) | ((unsigned int) ((((unsigned int) colors[2]) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) level) & ((0x01 << 8) - 1)) << 0))) | ((unsigned int) ((((unsigned int) colors[0]) & ((0x01 << 8) - 1)) << 24));
    }
    ;
    {
      Gfx *_g = (Gfx *) ((*((Gfx **) (&D_800D0510)))++);
      _g->words.w0 = (unsigned int) ((((unsigned int) 0xfb) & ((0x01 << 8) - 1)) << 24);
      _g->words.w1 = ((((unsigned int) ((((unsigned int) env_colors[1]) & ((0x01 << 8) - 1)) << 16)) | ((unsigned int) ((((unsigned int) env_colors[2]) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) level) & ((0x01 << 8) - 1)) << 0))) | ((unsigned int) ((((unsigned int) env_colors[0]) & ((0x01 << 8) - 1)) << 24));
    }
    ;
    {
      Gfx *segment = (*((Gfx **) (&D_800D0510)))++;
      segment->words.w0 = 0xDB06003C;
      segment->words.w1 = (u32) func_8004CA60(func_8004C990(0x96, alpha, &D_800D0510));
    }
    {
      Gfx *_g = (Gfx *) ((*((Gfx **) (&D_800D0510)))++);
      _g->words.w0 = (((unsigned int) ((((unsigned int) 0xde) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) 0x00) & ((0x01 << 8) - 1)) << 16))) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 16) - 1)) << 0));
      _g->words.w1 = (unsigned int) (*((s32 *) (D_86416C00 + 0xB550)));
    }
    ;
    func_8003CD84();
  }
}
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern void func_864009D4(void);
extern u8 *func_87F025B8(void *, void *);
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
void func_864012A0(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 *object;
    u8 *child;
    u8 *base;

    object = func_87F025B8(D_86416C00 + 0xE00, (void *)func_864009D4);
    if (object != 0) {
        child = *(u8 **)(object + 0x20);
        *(u8 **)(object + 0x38) = object;
        base = object + 0x24;
        func_8003F1DC(base);
        func_8003F114(base, 0, -1, *(s32 *)(D_86416C00 + 0x7B4));
        *(s32 *)(object + 0x0C) |= 0x10000000;
        *(s32 *)(object + 0x1C) = 0;
        *(f32 *)(object + 0x48) = arg1;
        *(f32 *)(object + 0x4C) = arg2;
        *(f32 *)(object + 0x50) = arg3;
        *(s16 *)(object + 0x42) = -0x4000;
        *(f32 *)(object + 0x54) = 2.5f;
        *(f32 *)(object + 0x58) = 2.5f;
        *(f32 *)(object + 0x5C) = 2.5f;
        *(f32 *)(object + 0x10) = 0.0f;
        *(f32 *)(object + 0x14) = 0.0f;
        *(f32 *)(object + 0x18) = 0.0f;
        *(s32 *)(child + 0x00) = 0;
        *(u8 *)(child + 0x04) = *(s32 *)((u8 *)arg0 + 0x00);
        *(u8 *)(child + 0x05) = *(s32 *)((u8 *)arg0 + 0x0C);
        *(u8 *)(child + 0x06) = *(s32 *)((u8 *)arg0 + 0x04);
    }
}
void func_864012A0_padding(void) {
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864013A8 begin */
typedef struct {
    u8 pad[0x18];
    f32 unk_18;
    u8 pad_1C[0x2C];
    f32 unk_48;
} unk_func_864013A8;

typedef struct {
    f32 unk_00;
} unk_D_86416C00;

extern u8 *D_86416C00;
extern s32 func_80001FF0(void);

// Frame update for the node in arg0. arg0+0x1C takes the TV refresh rate
// (func_80001FF0 returns 50 or 60) as ((f32)refresh / 60.0f) * 2.0f, rounded to
// s32, times 1 - arg1's 0x18 float / the f32 at D_86416C00; 0x10000000 is then
// ORed into arg0+0xC. When arg2 is non-NULL, bit 18 of the 0x0C word (the sign
// of the word shifted left 13) selects the -0.1 decay of arg0+0x10 and
// arg0+0x18 over copying arg2's floats at 0 and 4 into them and arg2's 0x8
// halfword into the f32 at arg1+0x48.


void func_864013A8(u8 *arg0, unk_func_864013A8 *arg1, u8 *arg2) {
    f32 rate = 2.0f;
    s32 value;
    if ((((f32)func_80001FF0() / 60.0f) * rate) >= 0.0f) {
        value = (s32)((((f32)func_80001FF0() / 60.0f) * rate) + 0.5f);
    } else {
        value = (s32)((((f32)func_80001FF0() / 60.0f) * rate) - 0.5f); } *(s32 *)(arg0 + 0x1C) = (s32)((f32)value * (1.0f - arg1->unk_18 / ((unk_D_86416C00 *)D_86416C00)->unk_00)); // FAKE: this store shares a line with the else assignment and its closing brace; IDO's local scheduler breaks the load-order tie by source line, and splitting them schedules the arg1 spill reload ahead of the D_86416C00 pointer load. diff score 60 without it.
    *(s32 *)(arg0 + 0xC) |= 0x10000000;
    if (arg2 != NULL) {
        if ((*(s32 *)(arg0 + 0xC) << 13) < 0) {
            *(f32 *)(arg0 + 0x10) *= -0.1f;
            *(f32 *)(arg0 + 0x18) *= -0.1f;
        } else {
            arg1->unk_48 = (f32)*(u16 *)(arg2 + 8);
            *(f32 *)(arg0 + 0x10) = *(f32 *)(arg2 + 0);
            *(f32 *)(arg0 + 0x18) = *(f32 *)(arg2 + 4);
        }
    }
}
/* mkdraft:func_864013A8 end */
#endif

#ifdef VERSION_US
extern u8 D_864095F8[];
extern u8 D_86409604[];
extern u8 D_86409610[];
extern u8 D_8640961C[];



void func_86401550(void) {
    u8 *state;
    u8 *entry;
    u8 *entry2;
    f32 sp94[2];
    s32 j;
    f32 sp8C;
    s32 i;
    s32 k;
    u8 *child;
    f32 sp78[2];

    state = D_86416C00 + 0x7D0;
    for (i = 0; i != 4; i++) {
        child = *(u8 **)(state + 0x20);
        entry = D_86409688;
        j = 0;
        do {
            sp94[0] = *(f32 *)(state + 0x48);
            sp94[1] = *(f32 *)(state + 0x50);
            if (func_86400114(sp94, 23.2f, D_86409668 + (entry[0] << 3), entry + 4, entry + 0xC, &sp8C) != 0) {
                *(f32 *)(state + 0x48) += *(f32 *)(entry + 0xC) * sp8C;
                *(f32 *)(state + 0x50) += *(f32 *)(entry + 0x10) * sp8C;
                if (*(f32 *)(entry + 0x10) * *(f32 *)(state + 0x18) + *(f32 *)(state + 0x10) * *(f32 *)(entry + 0xC) < 0.0f) {
                    func_864013A8(state, child, *(u8 **)(entry + 0x14));
                    *(s32 *)(state + 0xC) |= 0x04000000;
                }
            }
            j++;
            entry += 0x18;
        } while (j < 4);
        entry = D_864096E8;
        j = 0;
        do {
            sp94[0] = *(f32 *)(state + 0x48);
            sp94[1] = *(f32 *)(state + 0x50);
            if (func_864001E0(sp94, 23.2f, D_86409668 + (entry[0] << 3), entry + 4, sp78, &sp8C) != 0) {
                *(f32 *)(state + 0x48) += sp78[0] * sp8C;
                *(f32 *)(state + 0x50) += sp78[1] * sp8C;
            }
            entry += 0xC;
            j++;
        } while (j != 4);
        if (*(f32 *)(state + 0x48) < -309.8f) {
            *(f32 *)(state + 0x48) = -309.8f;
            if (*(f32 *)(state + 0x10) < 0.0f) {
                func_864013A8(state, child, D_86409604);
            }
        }
        if (309.8f < *(f32 *)(state + 0x48)) {
            *(f32 *)(state + 0x48) = 309.8f;
            if (*(f32 *)(state + 0x10) * -1.0f < 0.0f) {
                func_864013A8(state, child, D_8640961C);
            }
        }
        if (*(f32 *)(state + 0x50) < -254.3f) {
            *(f32 *)(state + 0x50) = -254.3f;
            if (*(f32 *)(state + 0x18) < 0.0f) {
                func_864013A8(state, child, D_864095F8);
            }
        }
        if (254.3f < *(f32 *)(state + 0x50)) {
            *(f32 *)(state + 0x50) = 254.3f;
            // FAKE: the trailing x * 0.0f folds to 0.0f, so the test is unchanged; the second
            // reference makes uopt share the 0x18 load in temp-pool $f8 and keeps -1.0f as
            // mul.s's fs operand. Without it the whole function scores 10 with only that
            // mul.s's operands swapped.
            if (-1.0f * *(f32 *)(state + 0x18) < *(f32 *)(state + 0x18) * 0.0f) {
                func_864013A8(state, child, D_86409610);
            }
        }
        state += 0x18C;
    }
}
#endif

#ifdef VERSION_US
extern void func_8002781C(s32, u8, void *);
void func_864018B0(u8 *arg0, u8 *arg1) {
    if (!(*(s32 *)(arg0 + 0xC) & 0x20000000)) {
        *(s32 *)(arg1 + 0x38) = 0x14;
        *(f32 *)(arg1 + 0x1C) = 0.0f;
        *(s32 *)(arg0 + 0xC) |= 0x20000000;
        *(f32 *)(arg0 + 0x14) = 46.4f;
        func_8002781C(0x5F03, *(u8 *)(arg1 + 3), arg1 + 0x58);
    }
}
#endif

#ifdef VERSION_US
extern u32 func_8003570C(void);
extern f32 sqrtf(f32);
extern f32 func_87D005E8(f32 *, f32 *, f32 *);
extern void func_864018B0(u8 *, u8 *);
extern u8 *D_86416C00;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;



void func_86401920(void *arg0, void *arg1) {
    Vec3 v;
    f32 dist;
    f32 diff;
    u8 *pa;
    u8 *pb;

    v.x = *(f32 *)((u8 *)arg1 + 0x48) - *(f32 *)((u8 *)arg0 + 0x48);
    v.y = *(f32 *)((u8 *)arg1 + 0x4C) - *(f32 *)((u8 *)arg0 + 0x4C);
    v.z = *(f32 *)((u8 *)arg1 + 0x50) - *(f32 *)((u8 *)arg0 + 0x50);
    dist = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (dist < 46.4f) {
        diff = 46.4f - dist;
        pa = *(u8 **)((u8 *)arg0 + 0x20);
        pb = *(u8 **)((u8 *)arg1 + 0x20);
        if (dist > 0.0f) {
            v.x = v.x / dist;
            v.y = v.y / dist;
            v.z = v.z / dist;
        } else {
            v.x = 2.0f * ((f32)func_8003570C() / 4294967296.0f) - 1.0f;
            v.y = 2.0f * ((f32)func_8003570C() / 4294967296.0f) - 1.0f;
            v.z = 2.0f * ((f32)func_8003570C() / 4294967296.0f) - 1.0f;
            func_87D005E8(&v.x, &v.y, &v.z);
        }
        *(f32 *)(pa + 0x2C) = *(f32 *)(pa + 0x2C) + (-v.x * diff * 0.5f);
        *(f32 *)(pa + 0x30) = *(f32 *)(pa + 0x30) + (-v.y * diff * 0.5f);
        *(f32 *)(pa + 0x34) = *(f32 *)(pa + 0x34) + (-v.z * diff * 0.5f);
        *(f32 *)(pb + 0x2C) = *(f32 *)(pb + 0x2C) + (v.x * diff * 0.5f);
        *(f32 *)(pb + 0x30) = *(f32 *)(pb + 0x30) + (v.y * diff * 0.5f);
        *(f32 *)(pb + 0x34) = *(f32 *)(pb + 0x34) + (v.z * (46.4f - dist) * 0.5f);
        if ((*(f32 *)D_86416C00 * 0.9f * 0.5f < *(f32 *)(pa + 0x1C)) && ((*(f32 *)((u8 *)arg0 + 0x18) * v.y) + (*(f32 *)((u8 *)arg0 + 0x10) * v.x) >= 0.0f) && (*(f32 *)(pb + 0x1C) < (*(f32 *)D_86416C00 * 0.9f * 0.5f))) {
            func_864018B0(arg1, pb);
        }
        if ((*(f32 *)D_86416C00 * 0.9f * 0.5f < *(f32 *)(pb + 0x1C)) && ((*(f32 *)((u8 *)arg1 + 0x18) * -v.y) + (*(f32 *)((u8 *)arg1 + 0x10) * -v.x) >= 0.0f) && (*(f32 *)(pa + 0x1C) < (*(f32 *)D_86416C00 * 0.9f * 0.5f))) {
            func_864018B0(arg0, pa);
        }
        if ((*(s32 *)((u8 *)arg0 + 0xC) & 0x80000000) && !(*(s32 *)((u8 *)arg1 + 0xC) & 0x80000000)) {
            *(f32 *)((u8 *)arg0 + 0x14) = 34.800003f;
        }
        if ((*(s32 *)((u8 *)arg1 + 0xC) & 0x80000000) && !(*(s32 *)((u8 *)arg0 + 0xC) & 0x80000000)) {
            *(f32 *)((u8 *)arg1 + 0x14) = 34.800003f;
        }
    }
}
#endif

#ifdef VERSION_US
void func_86401920(void *, void *);
extern u8 * D_86416C00;
void func_86401D1C(void) {
    u8 *base = D_86416C00 + 0x7D0;
    int i, j;
    u8 *p2;
    int n = 4;
    int m = 3;
    for (i = 0; i != m; i++) {
        p2 = base + 0x18C;
        for (j = i + 1; j < n; j++) {
            func_86401920(base, p2);
            p2 += 0x18C;
        }
        base += 0x18C;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86401DBC begin */
extern u32 func_8003570C(void);
extern u8 *D_86416C00;

void func_86401DBC(void *arg0, void *arg1, f32 arg2) {
    s32 flags;
    f32 scale;
    f32 random;
    s32 mask;
    if (*(f32 *)((u8 *)arg0 + 0x4C) <= 0.0f) {
        if (*(f32 *)D_86416C00 * ((f32)func_8003570C() / 4294967296.0f) < arg2) {
            mask = 0x10000000;
            if (*(u32 *)((u8 *)arg0 + 0xC) & 0x01000000) {
                flags = 0x01000000 << *(s32 *)((u8 *)arg1 + 0);
            } else {
                flags = mask;
            }
            if (*(u32 *)((u8 *)arg0 + 0xC) & 0x80000000) {
                scale = 1.0f;
            } else if (*(f32 *)((u8 *)arg1 + 0x1C) > 0.0f) {
                scale = 1.5f;
            } else {
                scale = 0.75f;
            }
            random = (f32)func_8003570C();
            scale *= (random / 4294967296.0f) + 0.5f;
            func_86400804(
                *(f32 *)((u8 *)arg0 + 0x48),
                *(f32 *)((u8 *)arg0 + 0x4C),
                *(f32 *)((u8 *)arg0 + 0x50),
                scale,
                -*(f32 *)((u8 *)arg0 + 0x10) * arg2,
                5.0f,
                -*(f32 *)((u8 *)arg0 + 0x18) * arg2,
                flags
            );
        }
    }
}
/* mkdraft:func_86401DBC end */
#endif

#ifdef VERSION_US
s32 func_86401F60(void *arg0) {
    f32 temp_fv0;
    f32 temp_fv1;
    s32 var_v1;

    temp_fv0 = *(f32 *)((u8 *)arg0 + 0x48);
    var_v1 = 0;
    if (*(f32 *)((u8 *)arg0 + 0x48) <= -309.8f) {
        var_v1 = 0x200;
    }
    if (309.8f <= *(f32 *)((u8 *)arg0 + 0x48)) {
        var_v1 = (var_v1 | 0x100) & 0xFFFF;
    }
    temp_fv1 = *(f32 *)((u8 *)arg0 + 0x50);
    if (temp_fv1 <= -254.3f) {
        var_v1 = (var_v1 | 0x800) & 0xFFFF;
    }
    if (254.3f <= temp_fv1) {
        var_v1 = (var_v1 | 0x400) & 0xFFFF;
    }
    if ((*(f32 *)((u8 *)arg0 + 0x48) <= -148.0f) &&
        (-171.2f <= *(f32 *)((u8 *)arg0 + 0x48)) &&
        (temp_fv1 > -92.5f) && (temp_fv1 < 92.5f)) {
        var_v1 = (var_v1 | 0x100) & 0xFFFF;
    }
    if ((*(f32 *)((u8 *)arg0 + 0x48) >= 148.0f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) <= 171.2f) &&
        (temp_fv1 > -92.5f) && (temp_fv1 < 92.5f)) {
        var_v1 = (var_v1 | 0x200) & 0xFFFF;
    }
    if ((temp_fv1 <= -92.5f) && (-115.7f <= temp_fv1) &&
        (*(f32 *)((u8 *)arg0 + 0x48) > -148.0f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) < 148.0f)) {
        var_v1 = (var_v1 | 0x400) & 0xFFFF;
    }
    if ((temp_fv1 >= 92.5f) && (temp_fv1 <= 115.7f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) > -148.0f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) < 148.0f)) {
        var_v1 = (var_v1 | 0x800) & 0xFFFF;
    }
    return var_v1;
}
#endif

#ifdef VERSION_US
extern u8 D_864095F8[];
extern u8 D_86409604[];
extern u8 D_86409610[];
extern u8 D_8640961C[];

// arg1 holds direction bits 0x100-0x800. The bits func_86401F60 returns for the position limits
// and the bits the mode at state + 4 excludes are cleared; the highest remaining bit selects a
// record. If the pair at +0x10/+0x18 has a non-negative dot product with the record's (x, z), the
// record's pair replaces it and the record's halfword at +8 is stored as a float at state + 0x48.
void func_86402158(u8 *arg0, u16 arg1) {
    u8 *state;
    s32 pad;
    u8 *record;

    state = *(u8 **)(arg0 + 0x20);
    record = NULL;
    if (*(u32 *)(arg0 + 0xC) & 0x90000000) {
        arg1 = 0;
    }
    arg1 &= ~func_86401F60(arg0);
    switch (*(u32 *)(state + 4)) {
        case 0:
            arg1 &= 0xF6FF;
            break;
        case 1:
            arg1 &= 0xF5FF;
            break;
        case 2:
            arg1 &= 0xF9FF;
            break;
        case 3:
            arg1 &= 0xFAFF;
            break;
        case 6:
            arg1 &= 0xFEFF;
            break;
        case 7:
            arg1 &= 0xFDFF;
            break;
        case 4:
            arg1 &= 0xF7FF;
            break;
        case 5:
            arg1 &= 0xFBFF;
            break;
    }

    if (arg1 & 0x800) {
        record = D_8640961C;
    } else if (arg1 & 0x400) {
        record = D_86409604;
    } else if (arg1 & 0x200) {
        record = D_864095F8;
    } else if (arg1 & 0x100) {
        record = D_86409610;
    }
    if (record != NULL && 0.0f <= (*(f32 *)(arg0 + 0x18) * *(f32 *)(record + 4)) +
                                          (*(f32 *)(record + 0) * *(f32 *)(arg0 + 0x10))) {
        *(f32 *)(state + 0x48) = *(u16 *)(record + 8);
        *(f32 *)(arg0 + 0x10) = *(f32 *)(record + 0);
        *(f32 *)(arg0 + 0x18) = *(f32 *)(record + 4);
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86402304 begin */
extern float sqrtf(float value);
extern s32 func_80001FF0(void);
extern void func_8002781C(s32, u8, void *);
extern u8 *D_86416C00;



void func_86402304(u8 *arg0) {
    f32 temp_fa0;
    f32 temp_fv1;
    s32 temp_t6;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_t3;
    s32 var_v1;
    s32 var_v1_2;
    u8 *temp_s1;
    u8 *var_s0;
    u8 *child;

    var_s0 = *(u8 **)(D_86416C00 + 0xE0C);
    temp_s1 = *(u8 **)(arg0 + 0x20);
    if (var_s0 != NULL) {
        do {
            child = *(u8 **)(var_s0 + 0x20);
            if ((*(u8 *)(child + 4) != *(s32 *)(temp_s1 + 0)) && (*(s32 *)(var_s0 + 0xC) & 0x20000000)) {
                temp_fv1 = *(f32 *)(arg0 + 0x48) - *(f32 *)(var_s0 + 0x48);
                temp_fa0 = *(f32 *)(arg0 + 0x50) - *(f32 *)(var_s0 + 0x50);
                if (sqrtf((temp_fv1 * temp_fv1) + (temp_fa0 * temp_fa0)) < 30.0f) {
                    temp_v0 = *(s32 *)(arg0 + 0xC);
                    if (!(temp_v0 & 0x40000) && !(temp_v0 & 0x80000000)) {
                        *(f32 *)(temp_s1 + 0x1C) = 0.0f;
                        *(f32 *)(arg0 + 0x14) = 34.800003f;
                        var_v1 = *(s32 *)(temp_s1 + 0x14);
                        switch (var_v1) {
                        case 0:
                            if ((((f32) func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
                                var_t3 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
                                *(s32 *)(temp_s1 + 0x38) = var_t3;
                            } else {
                                *(s32 *)(temp_s1 + 0x38) = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
                            }
                            break;
                        case 1:
                            if ((((f32) func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
                                var_v1 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
                            } else {
                                var_v1 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
                            }
                            *(s32 *)(temp_s1 + 0x38) = (s32) ((f32) var_v1 * 0.7f);
                            break;
                        case 2:
                        case 3:
                            if ((((f32) func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
                                var_v1_2 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
                            } else {
                                var_v1_2 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
                            }
                            *(s32 *)(temp_s1 + 0x38) = (s32) ((f32) var_v1_2 * 0.4f);
                            break;
                        }
                        *(s32 *)(arg0 + 0xC) |= 0x80000000;
                        func_8002781C(0x5F03, *(u8 *)(temp_s1 + 3), temp_s1 + 0x58);
                    }
                    *(s32 *)(var_s0 + 0xC) |= 0x40000000;
                    *(s32 *)(var_s0 + 0xC) &= 0xDFFFFFFF;
                    *(s32 *)(var_s0 + 0x1C) = 0;
                }
            }
            var_s0 = *(u8 **)(var_s0 + 4);
        } while (var_s0 != NULL);
    }
}
/* mkdraft:func_86402304 end */
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
void func_86402688(u8 *arg0, u16 arg1) {
    u8 *state;
    s32 random_value;
    s32 next_random;

    state = *(u8 **)(arg0 + 0x20);
    if (*(s32 *)(arg0 + 0x0C) & 0x02000000) {
        if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
            random_value = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
        } else {
            random_value = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
        }
        if (random_value < *(s32 *)(arg0 + 0x1C)) {
            *(s32 *)(arg0 + 0x0C) &= 0xFDFFFFFF;
        } else if (arg1 & 0x8000) {
            if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
                next_random = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
            } else {
                next_random = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
            }
            *(f32 *)(state + 0x18) += (556.80005f / (f32)func_80001FF0()) * 0.8f *
                                      (1.0f - ((f32)*(s32 *)(arg0 + 0x1C) / (f32)next_random));
            *(s32 *)(arg0 + 0x0C) &= 0xFDFFFFFF;
            *(s32 *)(state + 0x20) = 0x1E;
        }
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864028B8 begin */
extern void func_8002781C(s32, u8, void *);



s32 func_864028B8(u8 *arg0, u8 *arg1, u16 *arg2) {
    s32 flags;
    s32 ret;
    s32 state;

    flags = *(s32 *)(arg0 + 0xC);
    ret = 1;
    if (flags & 0x20000000) {
        *(u32 *)(arg0 + 0xC) = flags & 0x7FFFFFFF;
        if (--*(s32 *)(arg1 + 0x38) > 0) {
            if (*(s32 *)(arg1 + 0x38) >= 18) {
                *(u32 *)(arg0 + 0xC4) = 0xFF6464C8;
            } else {
                *(u32 *)(arg0 + 0xC4) = 0xFF000000;
            }
            if (*(s32 *)(arg1 + 0x38) % 5 == 0) {
                func_8002781C(0x5404, *(u8 *)(arg1 + 3), arg1 + 0x58);
            }
            *arg2 &= 0xF0FF;
            state = *(s32 *)(arg1 + 0x14);
            switch (state) {
                case 0:
                    *(f32 *)(arg1 + 0x18) *= 0.9f;
                    break;
                case 1:
                    *(f32 *)(arg1 + 0x18) *= 0.92f;
                    break;
                case 2:
                    *(f32 *)(arg1 + 0x18) *= 0.95f;
                    break;
                case 3:
                    *(f32 *)(arg1 + 0x18) *= 0.95f;
                    break;
            }
            ret = 0;
        } else {
            *(f32 *)(arg0 + 0x14) = 0.0f;
            *(u32 *)(arg0 + 0xC) &= 0xDFFFFFFF;
            *(f32 *)(arg0 + 0x4C) = 0.0f;
        }
    }
    return ret;
}
/* mkdraft:func_864028B8 end */
#endif

#ifdef VERSION_US

void func_86402A2C(u8 *arg0) {
    s32 flags = *(s32 *)(arg0 + 0xC);

    if ((flags & 0x80000000) && !(flags & 0x40000)) {
        if (*(f32 *)(arg0 + 0x4C) < 92.8f) {
            *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) + 9.280001f;
            if ((f64)34.80000114440918 < (f64)*(f32 *)(arg0 + 0x14)) {
                *(f32 *)(arg0 + 0x14) = 34.800003f;
            }
        } else {
            *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) - 9.280001f;
        }
    } else {
        *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) - 9.280001f;
    }
    *(f32 *)(arg0 + 0x4C) = *(f32 *)(arg0 + 0x14) + *(f32 *)(arg0 + 0x4C);
    if (*(f32 *)(arg0 + 0x4C) < 0.0f) {
        *(f32 *)(arg0 + 0x4C) = 0.0f;
        *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) * -0.75f;
    }
}
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern f32 D_86409A5C;
extern f32 D_86409A60;
extern f32 D_86409A64;
extern f32 D_86409A68;
extern f32 D_86409A6C;
extern f32 D_86409A70;
extern f32 D_86409A74;
extern f32 D_86409A78;
extern f32 D_86409A7C;
extern f32 D_86409A80;
extern f32 D_86409A84;
extern f32 D_86409A88;
extern f32 D_86409A8C;
extern f32 D_86409A90;
extern f32 D_86409A94;
extern f32 D_86409A98;
extern f32 D_86409A9C;
extern f32 D_86409AA0;
extern f32 D_86409AA4;
extern f32 D_86409AA8;
extern f32 D_86409AAC;
extern s32 func_80001FF0(void);
extern s32 func_864028B8(u8 *, u8 *, u16 *);
extern void func_864094BC(u8 *, u8 *, s32);
extern void func_87C03B60(u8 *, void *, void *);
void func_864012A0(void *, f32, f32, f32);
void func_86402158(u8 *, u16);
void func_86402688(u8 *, u16);
void func_86402A2C(u8 *);



void func_86402B1C(u8 *arg0, u16 arg1) {
    u8 *state;
    f32 step;
    u8 *pos;
    f32 limit;
    s32 value;

    state = *(u8 **)(arg0 + 0x20);
    pos = state + 0x58;
    func_87C03B60(D_86416C00 + 0xCEC8, arg0 + 0x48, pos);
    if (*(s32 *)(state + 0xC) >= 2) {
        *(s32 *)(state + 0x20) -= 1;
        if (*(s32 *)(state + 0x20) <= 0) {
            *(s32 *)(state + 0x20) = 0;
        }
    } else {
        *(s32 *)(state + 0x20) = 1;
    }
    *(f32 *)(state + 0x24) = *(f32 *)(arg0 + 0x48);
    *(f32 *)(state + 0x28) = *(f32 *)(arg0 + 0x50);
    func_86402688(arg0, arg1);
    if (*(s32 *)(arg0 + 0xC) & 0x10000000) {
        if ((((f32)func_80001FF0() / 60.0f) * 2) >= 0.0f) {
            value = (s32)((((f32)func_80001FF0() / 60.0f) * 2) + 0.5f);
        } else {
            value = (s32)((((f32)func_80001FF0() / 60.0f) * 2) - 0.5f);
        }
        if (value < *(s32 *)(arg0 + 0x1C)) {
            *(s32 *)(arg0 + 0xC) &= ~0x10000000;
        }
    }
    if (*(s32 *)(arg0 + 0xC) & 0x40000) {
        limit = 0.97f;
        limit -= 0.025f * (f32)*(s32 *)(state + 0x14);
        *(f32 *)(state + 0x18) *= limit;
        *(f32 *)(state + 0x1C) *= limit * 0.5f;
        arg1 = 0;
        func_86402304(arg0);
    } else {
        func_86402158(arg0, arg1);
        step = *(f32 *)(D_86416C00 + 4) * 0.22f * 60.0f / (f32)func_80001FF0();
        if (*(s32 *)(state + 0xC) < *(s32 *)(D_86416C00 + 8) - 1) {
            step += 0.0f / (f32)func_80001FF0() * (f32)*(s32 *)(state + 0x14);
        }
        if (*(f32 *)(arg0 + 0x4C) <= 0.0f) {
            value = *(s32 *)(state + 0x14);
            limit = *(f32 *)D_86416C00;
            switch (value) {
                case 0:
                    limit *= 0.85f;
                    break;
                case 1:
                    limit *= 0.9f;
                    break;
                case 2:
                    limit *= 0.95f;
                    break;
                case 3:
                    break;
            }
            *(f32 *)(state + 0x18) += step;
            if (limit < *(f32 *)(state + 0x18)) {
                *(f32 *)(state + 0x18) = limit;
            }
        }
        *(f32 *)(state + 0x1C) *= 0.9f;
        if (*(f32 *)(state + 0x1C) < *(f32 *)D_86416C00 * 0.9f * 0.1f) {
            *(f32 *)(state + 0x1C) = 0.0f;
        }
    }
    *(f32 *)(arg0 + 0x48) += *(f32 *)(arg0 + 0x10) * (*(f32 *)(state + 0x18) + *(f32 *)(state + 0x1C));
    *(f32 *)(arg0 + 0x50) += *(f32 *)(arg0 + 0x18) * (*(f32 *)(state + 0x18) + *(f32 *)(state + 0x1C));
    func_86402A2C(arg0);
    if (func_864028B8(arg0, state, &arg1)) {
        if (*(s32 *)(arg0 + 0xC) & 0x80000000) {
            if (--*(s32 *)(state + 0x38) > 0) {
                if (*(s32 *)(state + 0x38) % 5 == 0) {
                    func_8002781C(0x5404, *(u8 *)(state + 3), pos);
                }
                arg1 &= 0xF0FF;
                *(s16 *)(arg0 + 0x44) += 0x1FFF;
                *(f32 *)(state + 0x4C) = (f32)*(s16 *)(arg0 + 0x44);
                value = *(s32 *)(state + 0x14);
                switch (value) {
                    case 0:
                        *(f32 *)(state + 0x18) *= 0.9f;
                        break;
                    case 1:
                        *(f32 *)(state + 0x18) *= 0.92f;
                        break;
                    case 2:
                        *(f32 *)(state + 0x18) *= 0.95f;
                        break;
                    case 3:
                        *(f32 *)(state + 0x18) *= 0.95f;
                        break;
                }
                *(f32 *)(state + 0x18) = 0.0f;
            } else {
                *(s32 *)(arg0 + 0xC) &= 0x7FFFFFFF;
            }
        } else {
            limit = *(f32 *)(state + 0x48) - *(f32 *)(state + 0x4C);
            if (limit > 32767.0f) {
                limit = 65535.0f - limit;
            }
            if (limit < -32767.0f) {
                limit = 65535.0f + limit;
            }
            *(f32 *)(state + 0x4C) += limit * 0.5f;
            if ((f64)*(f32 *)(state + 0x4C) < 0.0) {
                *(f32 *)(state + 0x4C) += 65535.0f;
            }
            if (*(f32 *)(state + 0x4C) > 65535.0f) {
                *(f32 *)(state + 0x4C) -= 65535.0f;
            }
            *(s16 *)(arg0 + 0x44) = (u16)*(f32 *)(state + 0x4C);
            func_86402304(arg0);
        }
    }
    if (*(s32 *)(state + 0x44) > 0 && !(*(s32 *)(arg0 + 0xC) & 0x20000000) && !(*(s32 *)(arg0 + 0xC) & 0x80000000) && *(f32 *)(arg0 + 0x4C) <= 0.0f) {
        *(s32 *)(arg0 + 0xC) |= 0x08000000;
        if (arg1 & 0x8000) {
            *(s32 *)(state + 0x40) = 0;
            if (*(s32 *)(state + 0xC) >= 2) {
                *(f32 *)(state + 0x1C) = *(f32 *)D_86416C00 * 0.9f * 0.3f;
            } else {
                *(f32 *)(state + 0x18) = *(f32 *)D_86416C00;
                *(f32 *)(state + 0x1C) = *(f32 *)D_86416C00 * 0.9f;
            }
            func_864012A0(state, *(f32 *)(arg0 + 0x48), *(f32 *)(arg0 + 0x4C) + 23.2f, *(f32 *)(arg0 + 0x50));
            *(s32 *)(arg0 + 0x1C) = 0;
            *(s32 *)(arg0 + 0xC) |= 0x01000000;
            *(s32 *)(state + 0x44) -= 1;
            func_864094BC(D_86416C00 + 0xB554, arg0, *(s32 *)(state + 0x44));
            func_8002781C(0x4F06, *(u8 *)(state + 3), pos);
        }
    } else {
        *(s32 *)(arg0 + 0xC) &= ~0x08000000;
    }
    if (*(s32 *)(arg0 + 0xC) & 0x01000000) {
        *(f32 *)(state + 0x18) = *(f32 *)(state + 0x18);
        if ((((f32)func_80001FF0() / 60.0f) * 8.0f) >= 0.0f) {
            value = (s32)((((f32)func_80001FF0() / 60.0f) * 8.0f) + 0.5f);
        } else {
            value = (s32)((((f32)func_80001FF0() / 60.0f) * 8.0f) - 0.5f);
        }
        if (value < *(s32 *)(arg0 + 0x1C)) {
            *(s32 *)(arg0 + 0xC) &= ~0x01000000;
        }
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864033AC begin */
extern u8 *D_86416C00;

// Sorts pointers to the four records at D_86416C00 + 0xCB8C (stride 0x5C) in
// descending order of the f32 at +0x10, stores the winning record's pointer at
// D_86416C00 + 0x8000 + 0x4DFC, then writes each record's sorted position
// (0 = highest f32) into the s32 at +0x14.


void func_864033AC(void) {
    u8 *entries[4];
    s32 i;
    s32 j;
    u8 *p;

    for (i = 0; i < 4; i++) {
        entries[i] = D_86416C00 + 0xCB8C + i * 0x5C;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            if (*(f32 *)(entries[j] + 0x10) < *(f32 *)(entries[j + 1] + 0x10)) {
                p = entries[j];
                entries[j] = entries[j + 1];
                entries[j + 1] = p;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            *(void **)(D_86416C00 + 0x8000 + 0x4DFC) = entries[0];
        }
        *(s32 *)(entries[i] + 0x14) = i;
    }
}
/* mkdraft:func_864033AC end */
#endif

#ifdef VERSION_US
// Stores at arg0 + 0x50 the frame count of 175 frames at 60 Hz, converted to the rate
// func_80001FF0 reports, times a random factor whose range depends on the byte at +0x2181:
// [1, 2), [0.3, 0.5), [0.2, 0.5) or 0.
void func_86403550(u8 *arg0) {
    f32 scale;
    s32 value;

    value = *(s8 *)(*(u8 **)(D_86416C00 + 0x70) + 0x2181);
    switch (value) {
        case 0:
            scale = func_8003570C() / 4294967296.0f + 1.0f;
            break;
        case 1:
            scale = func_8003570C() / 4294967296.0f * 0.2f + 0.3f;
            break;
        case 2:
            scale = func_8003570C() / 4294967296.0f * 0.3f + 0.2f;
            break;
        case 3:
            scale = 0.0f;
            break;
    }

    value = (func_80001FF0() / 60.0f * 175.0f >= 0.0f) ? func_80001FF0() / 60.0f * 175.0f + 0.5f
                                                       : func_80001FF0() / 60.0f * 175.0f - 0.5f;
    *(s32 *)(arg0 + 0x50) = value * scale;
}
#endif

#ifdef VERSION_US
extern f32 func_87D0059C(f32 *, f32 *);
f32 func_8640377C(void *arg0, void *arg1) {
    f32 values[2];
    f32 *first = &values[0];
    f32 *second = &values[1];

    *first = *(f32 *)((u8 *)arg0 + 0x48) - *(f32 *)((u8 *)arg1 + 0);
    *second = *(f32 *)((u8 *)arg0 + 0x50) - *(f32 *)((u8 *)arg1 + 4);
    return func_87D0059C(first, second);
}
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern s32 func_87D00670(void *, void *, f32 *, void *, void *, f32 *);
extern float sqrtf(float value);

s32 func_864037C0(void *arg0, u8 *arg1, f32 arg2, f32 *arg3, f32 *arg4, void *arg5, f32 arg6) {
    f32 far;
    f32 offset;
    f32 delta;
    // Entry-time position, at 0x98(sp) and 0x94(sp). Two scalars, not f32[2]:
    // with the array IDO reuses the comparison's previous[0] load in the
    // distance term and emits three loads instead of the retail tail's four.
    // Scalars take home slots in declaration order (first = highest), so the
    // y slot is declared before the x slot.
    f32 previous_y;
    f32 previous_x;
    f32 p3;
    f32 node_position[2];
    f32 second;
    f32 first;
    f32 p4;
    f32 near;
    f32 current_x;
    f32 current_y;
    u8 *node;
    u8 *state;
    s32 result;

    node = *(u8 **)(D_86416C00 + 0xE0C);
    current_x = arg3[0];
    previous_x = current_x;
    current_y = arg3[1];
    previous_y = current_y;
    result = 0;
    if (node != 0) {
        do {
            state = *(u8 **)(node + 0x20);
            if (*(s32 *)arg1 != *(u8 *)(state + 4) &&
                (*(u32 *)(node + 0xC) & 0x30000000) != 0 &&
                *(s32 *)(arg1 + 0x50) < *(s32 *)(node + 0x1C)) {
                node_position[0] = *(f32 *)(node + 0x48);
                node_position[1] = *(f32 *)(node + 0x50);
                if (func_87D00670(arg3, arg4, &second, node_position, arg5, &first) != 0) {
                    if (arg2 < second) {
                        delta = second - arg2;
                    } else {
                        delta = -(second - arg2);
                    }
                    if (delta < 30.0f && first < 30.0f) {
                        result = 1;
                    }
                    if (first < 30.0f && -(arg6 + 30.0f) < first) {
                        near = second - 30.0f;
                        far = second + 30.0f;
                        if (first > 0.0f) {
                            offset = first;
                        } else {
                            offset = -first;
                        }
                        if (offset < 30.0f) {
                            if (0.0f < far && far < arg2) {
                                arg3[0] += arg4[0] * far;
                                arg3[1] += arg4[1] * far;
                                arg2 = func_8640377C(arg0, arg3);
                            }
                            if (near < arg2 && arg2 < far) {
                                if ((arg2 - near) < (far - arg2)) {
                                    offset = near;
                                } else {
                                    offset = far;
                                }
                                arg3[0] += arg4[0] * offset;
                                arg3[1] += arg4[1] * offset;
                                arg2 = func_8640377C(arg0, arg3);
                            }
                        } else if (near < 0.0f && 0.0f < far) {
                            arg3[0] += arg4[0] * far;
                            arg3[1] += arg4[1] * far;
                            arg2 = func_8640377C(arg0, arg3);
                        }
                    }
                }
            }
            node = *(u8 **)(node + 4);
        } while (node != 0);
        current_x = arg3[0];
        current_y = arg3[1];
    }
    if (previous_x != current_x || previous_y != current_y) {
        if (138.6f < sqrtf((previous_x - current_x) * (previous_x - current_x) +
                           (previous_y - current_y) * (previous_y - current_y))) {
            arg3[0] = previous_x;
            arg3[1] = previous_y;
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86403B3C begin */



f32 func_86403B3C(u8 *arg0, void *arg1, f32 arg2, f32 *arg3, void *arg4) {
    f32 current;
    f32 result;
    f32 near[2];
    f32 far[2];
    f32 second;
    f32 first;
    void *tag;
    u8 *node;

    node = *(u8 **)((u8 *)D_86416C00 + 0x7C8);
    result = 0.0f;
    while (node != NULL) {
        tag = *(void **)(node + 0x20);
        if (arg1 != tag) {
            near[0] = *(f32 *)(arg0 + 0x48);
            near[1] = *(f32 *)(arg0 + 0x50);
            far[0] = *(f32 *)(node + 0x48);
            far[1] = *(f32 *)(node + 0x50);
            if (func_87D00670(near, arg3, &second, far, arg4, &first) != 0) {
                if (arg2 < second) {
                    current = second - arg2;
                } else {
                    current = second - arg2;
                    current = -current;
                }
                if (current < 46.4f && first > 0.0f && result < first) {
                    result = first;
                }
            }
        }
        node = *(u8 **)(node + 4);
    }
    return result;
}
/* mkdraft:func_86403B3C end */
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
void func_86403CB4(void) { void *node; node = *(void **)(D_86416C00 + 0xE0C); while (node != NULL) { node = *(void **)((u8 *)node + 4); } }
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86403CDC.s")
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern u32 func_8003570C(void);
extern s32 func_80001FF0(void);
extern s32 func_86403CDC(void *, void *, f32);



u16 func_86403F5C(u8 *arg0) {
    u8 *state;
    u16 result;
    f32 pos[2];
    f32 dir1[2];
    f32 dir0[2];
    f32 sp5C;
    f32 sp58;
    s32 kind;
    s32 sp50;
    s32 count;
    u32 sp48;
    s32 v;

    state = *(u8 **)(arg0 + 0x20);
    result = 0;
    switch (*(u32 *)(state + 4)) {
    case 0:
    case 4:
        dir0[1] = 1.0f;
        dir1[0] = -1.0f;
        dir1[1] = 0.0f;
        dir0[0] = 0.0f;
        pos[0] = -148.0f - (*(f32 *)(state + 0x54) + 23.2f);
        pos[1] = *(f32 *)(arg0 + 0x50);
        sp5C = 122.5f - *(f32 *)(arg0 + 0x50);
        if (pos[0] < *(f32 *)(arg0 + 0x48)) {
            sp58 = *(f32 *)(arg0 + 0x48) - pos[0];
        } else {
            sp58 = -(*(f32 *)(arg0 + 0x48) - pos[0]);
        }
        break;
    case 1:
    case 7:
        dir1[1] = 1.0f;
        dir0[0] = 1.0f;
        dir1[0] = 0.0f;
        dir0[1] = 0.0f;
        pos[0] = *(f32 *)(arg0 + 0x48);
        pos[1] = *(f32 *)(state + 0x54) + 23.2f + 92.5f;
        sp5C = 178.0f - *(f32 *)(arg0 + 0x48);
        if (pos[1] < *(f32 *)(arg0 + 0x50)) {
            sp58 = *(f32 *)(arg0 + 0x50) - pos[1];
        } else {
            sp58 = -(*(f32 *)(arg0 + 0x50) - pos[1]);
        }
        break;
    case 2:
    case 5:
        dir1[0] = 1.0f;
        dir1[1] = 0.0f;
        dir0[0] = 0.0f;
        dir0[1] = -1.0f;
        pos[0] = *(f32 *)(state + 0x54) + 23.2f + 148.0f;
        pos[1] = *(f32 *)(arg0 + 0x50);
        sp5C = *(f32 *)(arg0 + 0x50) - -122.5f;
        if (pos[0] < *(f32 *)(arg0 + 0x48)) {
            sp58 = *(f32 *)(arg0 + 0x48) - pos[0];
        } else {
            sp58 = -(*(f32 *)(arg0 + 0x48) - pos[0]);
        }
        break;
    case 3:
    case 6:
        dir1[1] = -1.0f;
        dir0[0] = -1.0f;
        dir1[0] = 0.0f;
        dir0[1] = 0.0f;
        pos[0] = *(f32 *)(arg0 + 0x48);
        pos[1] = -92.5f - (*(f32 *)(state + 0x54) + 23.2f);
        if (*(s32 *)(state + 0xC) == 1) {
            sp5C = *(f32 *)(arg0 + 0x48) - 45.0f;
        } else {
            sp5C = *(f32 *)(arg0 + 0x48) - -178.0f;
        }
        if (pos[1] < *(f32 *)(arg0 + 0x50)) {
            sp58 = *(f32 *)(arg0 + 0x50) - pos[1];
        } else {
            sp58 = -(*(f32 *)(arg0 + 0x50) - pos[1]);
        }
        break;
    }
    v = func_864037C0(arg0, state, sp58, pos, dir1, dir0, sp5C);
    if (*(s8 *)(*(u8 **)(D_86416C00 + 0x70) + 0x2181) == 3 && *(s32 *)(state + 0xC) == 9) {
        v = 1;
    }
    switch (*(u32 *)(state + 4)) {
    case 0:
        if (*(f32 *)(arg0 + 0x48) < pos[0]) {
            v = 0x400;
        } else {
            v = 0x200;
        }
        result = v;
        break;
    case 1:
        if (pos[1] < *(f32 *)(arg0 + 0x50)) {
            v = 0x100;
        } else {
            v = 0x400;
        }
        result = v;
        break;
    case 3:
        if (*(f32 *)(arg0 + 0x50) < pos[1]) {
            v = 0x200;
        } else {
            v = 0x800;
        }
        result = v;
        break;
    case 2:
        if (pos[0] < *(f32 *)(arg0 + 0x48)) {
            v = 0x800;
        } else {
            v = 0x100;
        }
        result = v;
        break;
    case 4:
    case 5:
        if (v) {
            if (*(f32 *)(arg0 + 0x48) < pos[0] - *(f32 *)D_86416C00) {
                result = 0x100;
            } else if (pos[0] + *(f32 *)D_86416C00 < *(f32 *)(arg0 + 0x48)) {
                result = 0x200;
            } else if (*(u32 *)(state + 4) == 4) {
                result = 0x400;
            } else {
                result = 0x800;
            }
        } else if (*(u32 *)(state + 4) == 4) {
            result = 0x400;
        } else {
            result = 0x800;
        }
        break;
    case 6:
    case 7:
        if (*(s32 *)(state + 0xC) == 0 && *(u32 *)(state + 4) == 6) {
            result = 0x200;
        } else if (v) {
            if (*(f32 *)(arg0 + 0x50) < pos[1] - *(f32 *)D_86416C00) {
                result = 0x400;
            } else if (pos[1] + *(f32 *)D_86416C00 < *(f32 *)(arg0 + 0x50)) {
                result = 0x800;
            } else if (*(u32 *)(state + 4) == 6) {
                result = 0x200;
            } else {
                result = 0x100;
            }
        } else if (*(u32 *)(state + 4) == 6) {
            result = 0x200;
        } else {
            result = 0x100;
        }
        break;
    }
    if (*(u32 *)(arg0 + 0xC) & 0x02000000) {
        kind = *(s8 *)(*(u8 **)(D_86416C00 + 0x70) + 0x2181);
        switch (kind) {
        case 0:
            sp50 = 0;
            break;
        case 1:
            sp48 = func_8003570C();
            if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
                count = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
            } else {
                count = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
            }
            sp50 = (sp48 % (u32)(count + 1)) == 0;
            break;
        case 2:
            sp48 = func_8003570C();
            if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
                count = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
            } else {
                count = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
            }
            sp50 = (sp48 % (u32)((count >> 2) + 1)) == 0;
            break;
        case 3:
            sp50 = 1;
            break;
        }
        if (sp50 != 0) {
            result |= 0x8000;
        }
    } else {
        if (((*(s32 *)(state + 0x40))++ < 6) ^ 1) {
            result |= func_86403CDC(arg0, state, func_86403B3C(arg0, state, sp58, dir1, dir0));
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
f32 func_86404724(void) {
    s8 kind;
    f32 result;

    kind = *(s8 *)((u8 *)(*(u8 **)(D_86416C00 + 0x70)) + 0x2181);
    switch (kind) {
    case 0:
        result = (f32)func_8003570C();
        result = (((result / 4294967296.0f) + (result / 4294967296.0f)) - 1.0f) * 23.2f * 6.0f;
        break;
    case 1:
        result = (f32)func_8003570C();
        result = (((result / 4294967296.0f) + (result / 4294967296.0f)) - 1.0f) * 23.2f * 2.0f;
        break;
    default:
        result = 0.0f;
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
// Classifies the x/z position at 0x48/0x50 into a zone: corners 0-3 (each also sets one
// flag bit at 0xC), then edges 4-7, and stores it at child + 4. When the zone changes,
// child + 0x54 receives a new value from func_86404724.
void func_86404824(u8 *arg0) {
    u8 *child;
    s32 previous_zone;

    child = *(u8 **)(arg0 + 0x20);
    previous_zone = *(s32 *)(child + 4);
    if (*(f32 *)(arg0 + 0x48) <= -124.8f && *(f32 *)(arg0 + 0x50) <= -69.3f) {
        *(u32 *)(arg0 + 0xC) |= 0x100000;
        *(s32 *)(child + 4) = 0;
    } else if (*(f32 *)(arg0 + 0x48) <= -124.8f && 69.3f <= *(f32 *)(arg0 + 0x50)) {
        *(u32 *)(arg0 + 0xC) |= 0x200000;
        *(s32 *)(child + 4) = 1;
    } else if (124.8f <= *(f32 *)(arg0 + 0x48) && 69.3f <= *(f32 *)(arg0 + 0x50)) {
        *(u32 *)(arg0 + 0xC) |= 0x800000;
        *(s32 *)(child + 4) = 2;
    } else if (124.8f <= *(f32 *)(arg0 + 0x48) && *(f32 *)(arg0 + 0x50) <= -69.3f) {
        *(u32 *)(arg0 + 0xC) |= 0x400000;
        *(s32 *)(child + 4) = 3;
    } else if (*(f32 *)(arg0 + 0x50) <= -92.5f) {
        *(s32 *)(child + 4) = 6;
    } else if (*(f32 *)(arg0 + 0x50) >= 92.5f) {
        *(s32 *)(child + 4) = 7;
    } else if (*(f32 *)(arg0 + 0x48) <= -148.0f) {
        *(s32 *)(child + 4) = 4;
    } else if (*(f32 *)(arg0 + 0x48) >= 148.0f) {
        *(s32 *)(child + 4) = 5;
    }
    if (previous_zone != *(s32 *)(child + 4)) {
        *(f32 *)(child + 0x54) = func_86404724();
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86404A0C begin */
extern void func_8003F210(u8 *, s16);



void func_86404A0C(u8 *arg0) {
    u8 *child;
    s32 mode;

    mode = *(s32 *)(D_86416C00 + 0x10);
    child = *(u8 **)(arg0 + 0x20);
    switch (mode) {
    case 4:
        if (*(s32 *)(arg0 + 0xC) & 0x40000) {
            if (*(s32 *)(arg0 + 0x30) != ((s32 *)(D_86416C00 + 0x788))[*(s32 *)child]) {
                func_8003F1DC(arg0 + 0x24);
                func_8003F114(arg0 + 0x24, 0, -1, ((s32 *)(D_86416C00 + 0x788))[*(s32 *)child]);
            }
            func_8003F210(arg0 + 0x24, 0);
        } else if (*(s32 *)(child + 0x20) > 0) {
            if (*(s32 *)(arg0 + 0x30) != ((s32 *)(D_86416C00 + 0x798))[*(s32 *)child]) {
                func_8003F1DC(arg0 + 0x24);
                func_8003F114(arg0 + 0x24, 0, -1, ((s32 *)(D_86416C00 + 0x798))[*(s32 *)child]);
            }
            func_8003F210(arg0 + 0x24, 4);
            func_8002781C(0x5001, *(u8 *)(child + 3), child + 0x58);
        } else {
            if (*(s32 *)(arg0 + 0x30) != ((s32 *)(D_86416C00 + 0x788))[*(s32 *)child]) {
                func_8003F1DC(arg0 + 0x24);
                func_8003F114(arg0 + 0x24, 0, -1, ((s32 *)(D_86416C00 + 0x788))[*(s32 *)child]);
                ModelAnim_SetFrame(arg0 + 0x24, (s16)(func_8003570C() % 7));
            }
            func_8003F210(arg0 + 0x24, 1);
            if (ModelAnim_HasCrossedFrame(arg0 + 0x24, 1) != 0) {
                func_8002781C(0x5F00, *(u8 *)(child + 3), child + 0x58);
            }
            if (*(s32 *)(arg0 + 0xC) & 0x20000000) {
                ModelAnim_SetSpeed(arg0 + 0x24, 0x20000);
            } else {
                ModelAnim_SetSpeed(arg0 + 0x24, 0x10000);
            }
        }
        break;
    case 5:
        if (*(s32 *)(arg0 + 0x30) != ((s32 *)(D_86416C00 + 0x788))[*(s32 *)child]) {
            func_8003F1DC(arg0 + 0x24);
            func_8003F114(arg0 + 0x24, 0, -1, ((s32 *)(D_86416C00 + 0x788))[*(s32 *)child]);
        }
        if (*(s32 *)(arg0 + 0xC) & 0x20000) {
            if (*(s32 *)(arg0 + 0xC) & 0x10000) {
                func_8003F210(arg0 + 0x24, 2);
                if (*(u8 *)(child + 0x5A) < 2) {
                    if (ModelAnim_HasCrossedFrame(arg0 + 0x24, 4) != 0) {
                        func_8002781C(0x5F06, *(u8 *)(child + 3), child + 0x58);
                        *(u8 *)(child + 0x5A) += 1;
                    }
                }
            } else {
                if (*(s16 *)(arg0 + 0x64) != 3) {
                    func_8003F210(arg0 + 0x24, 3);
                    *(s16 *)(*(s32 *)(arg0 + 0x68) + 6) = 0x32;
                }
                if (ModelAnim_HasCrossedFrame(arg0 + 0x24, 0xF) != 0) {
                    func_8002781C(0x5F05, *(u8 *)(child + 3), child + 0x58);
                }
            }
        } else {
            func_8003F210(arg0 + 0x24, 0);
        }
        break;
    }
}
/* mkdraft:func_86404A0C end */
#endif

#ifdef VERSION_US
void func_86404D48(u8 *arg0, u8 *arg1) {
    *(f32 *)(arg0 + 0x48) += *(f32 *)(arg1 + 0x2C);
    *(f32 *)(arg0 + 0x4C) += *(f32 *)(arg1 + 0x30);
    *(f32 *)(arg0 + 0x50) += *(f32 *)(arg1 + 0x34);
    *(f32 *)(arg1 + 0x2C) = 0.0f;
    *(f32 *)(arg1 + 0x30) = 0.0f;
    *(f32 *)(arg1 + 0x34) = 0.0f;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86404D8C.s")
#endif

#ifdef VERSION_US
extern void func_86407290(f32, f32, f32, f32, f32, f32, s32); //@src/fragments/52/fragment52_285750.c

// Averages the positions (+0x48/+0x4C/+0x50) of the four 0x18C-byte records from
// D_86416C00 + 0x7D0 whose word +0xC has flag 0x10000, or of all four when none has it, and
// passes func_86407290 two points offset from that average.
void func_86405138(void) {
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    s32 count;
    u8 *p;

    count = 0;
    p = D_86416C00 + 0x7D0;
    x = y = z = 0.0f;
    for (i = 0; i < 4; i++) {
        if (*(s32 *)(p + 0xC) & 0x10000) {
            count++;
        }
        p += 0x18C;
    }
    if (count == 0) {
        count = 4;
        p = D_86416C00 + 0x7D0;
        for (i = 0; i < 4; i++, p += 0x18C) {
            x += *(f32 *)(p + 0x48);
            y += *(f32 *)(p + 0x4C);
            z += *(f32 *)(p + 0x50);
        }
    } else {
        p = D_86416C00 + 0x7D0;
        for (i = 0; i < 4; i++, p += 0x18C) {
            if (*(s32 *)(p + 0xC) & 0x10000) {
                x += *(f32 *)(p + 0x48);
                y += *(f32 *)(p + 0x4C);
                z += *(f32 *)(p + 0x50);
            }
        }
    }
    if (count >= 2) {
        x /= count;
        y /= count;
        z /= count;
    }
    func_86407290(x - 200.0f, y + 450.0f, z + 80.0f, x + 90.0f, y - 40.0f, z, 60);
}
#endif

#ifdef VERSION_US
// Sine and cosine tables indexed by a 16-bit angle >> 4, as in SINS/COSS. //@include/229E0.h
extern f32 D_80087E50[];
extern f32 D_80088E50[];

// For each of the four 396-byte records from D_86416C00 + 0x7D0, updates the node scale at
// child + 0x18 (child = record + 0x20): while flag 0x20000 at +0xC is set, the scale grows by
// 0.13 for the first 20 frames counted at +0x1C and then decays by 0.9; otherwise it decays by
// 0.94. The position at +0x48/+0x50 advances by the direction at +0x10/+0x18 times the scale.
// In the second pass, a record whose scale has dropped below 1 and whose flag 0x20000 is clear
// sets flag 0x10000000 on the entry indexed by child + 0 in the 396-byte array at
// D_86416C00 + 0xCDD0, sets its own flag 0x20000 (record 0 first calls func_86405138), and,
// unless flag 0x10000 is set, restarts the counter, points +0x10/+0x18 along the angle at +0x44
// (cosine, negated sine) and clears the scale.
void func_8640533C(void) {
    u8 *state;
    u8 *child;
    s32 i;

    state = D_86416C00 + 0x7D0;
    for (i = 0; i < 4; i++, state += 396) {
        child = *(u8 **)(state + 0x20);
        *(s32 *)(child + 0x20) = 0;
        func_86404824(state);
        if (*(s32 *)(state + 0xC) & 0x20000) {
            if (++*(s32 *)(state + 0x1C) < 20) {
                *(f32 *)(child + 0x18) += 0.13f;
            } else {
                *(f32 *)(child + 0x18) *= 0.9f;
            }
            *(f32 *)(state + 0x48) += *(f32 *)(state + 0x10) * *(f32 *)(child + 0x18);
            *(f32 *)(state + 0x50) += *(f32 *)(state + 0x18) * *(f32 *)(child + 0x18);
        } else {
            *(f32 *)(child + 0x18) *= 0.94f;
            *(f32 *)(state + 0x48) += *(f32 *)(state + 0x10) * *(f32 *)(child + 0x18);
            *(f32 *)(state + 0x50) += *(f32 *)(state + 0x18) * *(f32 *)(child + 0x18);
        }
        func_86402A2C(state);
    }
    func_86401D1C();
    state = D_86416C00 + 0x7D0;
    for (i = 0; i != 4; i++, state += 396) {
        child = *(u8 **)(state + 0x20);
        func_86404D48(state, child);
        func_86401DBC(state, child, *(f32 *)(child + 0x18));
        if (*(f32 *)(child + 0x18) < 1.0f && !(*(s32 *)(state + 0xC) & 0x20000)) {
            *(s32 *)(*(s32 *)child * 396 + *(u8 **)(D_86416C00 + 0xCDD0) + 0xC) |= 0x10000000;
            if (i == 0) {
                func_86405138();
            }
            *(s32 *)(state + 0xC) |= 0x20000;
            if (!(*(s32 *)(state + 0xC) & 0x10000)) {
                *(s32 *)(state + 0x1C) = 0;
                *(f32 *)(state + 0x10) = D_80088E50[*(u16 *)(state + 0x44) >> 4];
                *(f32 *)(state + 0x18) = -D_80087E50[*(u16 *)(state + 0x44) >> 4];
                *(f32 *)(child + 0x18) = 0.0f;
            }
        }
        func_86404A0C(state);
    }
}

#endif

#ifdef VERSION_US
// For each of the four 0x18C-byte records from D_86416C00 + 0x7D0, decays the node scale at
// +0x18 by 0.8 and advances +0x48 by +0x10 times that scale. Once the scale drops below 1 it
// is cleared (record 0 first calls func_86407290 while it is still positive) and, when +0x64
// is 1, the animation at +0x24 restarts at a random frame 0-15.
void func_864055CC(void) {
    u8 *state = D_86416C00;
    u8 *node;
    u8 *child;
    s32 i;

    state += 0x7D0;
    for (i = 0; i < 4; i++, state += 0x18C) {
        node = *(u8 **)(state + 0x20);
        *(f32 *)(node + 0x18) *= 0.8f;
        *(f32 *)(state + 0x48) += *(f32 *)(state + 0x10) * *(f32 *)(node + 0x18);
        if (*(f32 *)(node + 0x18) < 1.0f) {
            if (i == 0 && *(f32 *)(node + 0x18) > 0.0f) {
                func_86407290(0.0f, 1049.5f, 553.0f, 0.0f, 30.0f, 30.0f, 80);
            }
            *(f32 *)(node + 0x18) = 0.0f;
            if (*(s16 *)(state + 0x64) == 1) {
                func_8003F210(state + 0x24, 0);
                ModelAnim_SetFrame(state + 0x24, (s16)(func_8003570C() & 0xF));
            }
        }
    }
    func_86401D1C();
    state = D_86416C00;
    state += 0x7D0;
    for (i = 0; i < 4; i++, state += 0x18C) {
        child = *(u8 **)(state + 0x20);
        func_86404D48(state, child);
        func_86401DBC(state, child, *(f32 *)(child + 0x18));
    }
}
#endif

#ifdef VERSION_US
extern void func_86404D8C();
extern void func_8640533C();
extern void func_864055CC();
void func_86405778(void) {
    s32 temp_v0;

    temp_v0 = (*(s32 *)((u8 *)(D_86416C00) + (0x10)));
    switch (temp_v0) {                              /* irregular */
    case 3:
        func_864055CC();
        return;
    case 4:
        func_86404D8C();
        return;
    default:
        func_8640533C();
        return;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864057E0 begin */
extern u32 func_8003570C(void);
extern u8 *func_87F025B8(void *, void *);
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern f32 func_86404724(void);
extern void func_86403550(u8 *);
extern void func_86407D58(u8 *, u8 *);
extern void func_8640912C(u8 *, u8 *);
extern u8 *D_86416C00;




void func_864057E0(void) {
    u8 *child;
    s32 i;
    s32 j;
    s32 indices[4];
    s32 k;
    s32 temp;
    u8 *object;
    u8 *unk;
    u8 *entry;
    u8 *entry2;
    u8 *entry3;
    u8 *rec;

    for (i = 0; i < 4; i++) {
        indices[i] = i;
    }
    for (i = 0; i < (func_8003570C() % 101) * 4; i++) {
        j = func_8003570C() & 3;
        k = func_8003570C() & 3;
        temp = indices[j];
        indices[j] = indices[k];
        indices[k] = temp;
    }
    for (i = 0; i != 4; i++) {
        object = func_87F025B8(D_86416C00 + 0x7BC, NULL);
        if (object != NULL) {
            unk = *(u8 **)(object + 0x20);
            child = object + 0x24;
            func_8003F1DC(child);
            func_8003F114(child, 0, -1, ((s32 *)(D_86416C00 + 0x788))[i]);
            func_8003F210(child, 1);
            ModelAnim_SetFrame(child, (s16)(func_8003570C() % 7));
            *(s32 *)(unk + 0x00) = i;
            *(f32 *)(unk + 0x18) = 20.0f;
            *(f32 *)(unk + 0x1C) = 0.0f;
            *(s32 *)(unk + 0x20) = 0;
            *(s32 *)(unk + 0x0C) = *(s32 *)(D_86416C00 + 8);
            *(f32 *)(unk + 0x2C) = 0.0f;
            *(f32 *)(unk + 0x30) = 0.0f;
            *(f32 *)(unk + 0x34) = 0.0f;
            *(s32 *)(unk + 0x40) = 0;
            *(f32 *)(unk + 0x54) = func_86404724();
            *(f32 *)(unk + 0x10) = 0.0f;
            *(s32 *)(unk + 0x14) = i;
            *(s32 *)(unk + 0x3C) = 0;
            *(s32 *)(unk + 0x44) = 0;
            *(u8 *)(unk + 0x5A) = 0;
            func_86403550(unk);
            *(u32 *)(object + 0x0C) |= 0x42000000;
            *(f32 *)(object + 0x4C) = 0.0f;
            // The pool words are 0x3D23D70B and 0x42147AE2, one above 0.04f and 37.12f;
            // these spellings round to them.
            *(f32 *)(object + 0x5C) = 0.040000003f;
            *(f32 *)(object + 0x58) = 0.040000003f;
            *(f32 *)(object + 0x54) = 0.040000003f;
            *(f32 *)(object + 0x48) = indices[i] * 37.120003f + 116.0f;
            *(f32 *)(object + 0x50) = (f64)indices[i] * 41.7600013732910185 + -254.300003051757812;
            *(s16 *)(object + 0x44) = -0x4001;
            *(f32 *)(object + 0x14) = 0.0f;
            *(f32 *)(object + 0x18) = 0.0f;
            *(f32 *)(object + 0x10) = -1.0f;
            *(s32 *)(unk + 0x08) = 0;
            *(s32 *)(unk + 0x04) = 0;
            *(f32 *)(unk + 0x24) = *(f32 *)(object + 0x48);
            *(f32 *)(unk + 0x28) = *(f32 *)(object + 0x50);
            *(f32 *)(unk + 0x48) = *(f32 *)(unk + 0x4C) = (f32)*(s16 *)(object + 0x44);
            *(s32 *)(*(s32 *)unk * 396 + *(u8 **)(D_86416C00 + 0xCDD0) + 0xC) &= 0xEFFFFFFF;
            entry = *(u8 **)(D_86416C00 + 0xCDD4) + i * 24;
            *(u8 **)entry = child;
            entry2 = *(u8 **)(D_86416C00 + 0xCDD4) + i * 24;
            *(f32 *)(entry2 + 0x04) = 0.0f;
            *(f32 *)(entry2 + 0x08) = 75.0f;
            *(f32 *)(entry2 + 0x0C) = 0.0f;
            rec = *(u8 **)(D_86416C00 + 0xCDD0) + i * 396;
            *(f32 *)(rec + 0x54) = 1.5f;
            *(f32 *)(rec + 0x58) = 1.5f;
            *(f32 *)(rec + 0x5C) = 1.5f;
            // FAKE: entry2 and entry3 hold the same address; repeating the base load through
            // the otherwise unused entry3 moves the 0xFF constant past the 0xEFFFFFFF mask
            // store, so it materializes in v1 right before the entry base. Using entry2 for
            // all four stores scores 215.
            entry3 = entry2 = *(u8 **)(D_86416C00 + 0xCDD4) + i * 24;
            *(u8 *)(entry3 + 0x12) = 0xFF;
            *(u8 *)(entry3 + 0x13) = 0xFF;
            *(u8 *)(entry3 + 0x14) = 0xFF;
            *(u8 *)(entry2 + 0x15) = 0xAF;
            func_86407D58(object, rec);
            func_8640912C(D_86416C00 + 0xB554, object);
        }
    }
}
/* mkdraft:func_864057E0 end */
#endif

#ifdef VERSION_US
extern void func_8003F03C(void *, void *);
extern void func_8003F018(void *);
extern u8 D_86409C70[];
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 * D_86416C00;
// The three 0.37f stores are separate literals: the ROM holds three 0.37f words at
// 0x86409B78-0x86409B80 even though the compiled code loads only one of them.
void func_86405BEC(void) { u8 *obj; f32 value; obj = D_86416C00 + 0xC8BC; func_8003F03C(obj, D_86409C70); func_8003F1DC(obj); func_8003F114(obj, 0, -1, *(s32 *)(D_86416C00 + 0x7A8)); *(f32 *)(obj + 0x38) = 0.37f; *(f32 *)(obj + 0x34) = 0.37f; *(f32 *)(obj + 0x30) = 0.37f; obj = D_86416C00 + 0xCA24; func_8003F018(obj); func_8003F1DC(obj); func_8003F114(obj, 0, -1, *(s32 *)(D_86416C00 + 0x7AC)); value = 0.37f; *(f32 *)(obj + 0x38) = value; *(f32 *)(obj + 0x34) = value; *(f32 *)(obj + 0x30) = value; }
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern void func_80035700(u32);
extern s32 func_87F026E8(s32, void *);
extern void func_86407B54(void);
extern void func_86409240(s32);
extern void func_8640708C(void);
extern void func_86407330(f32, f32, f32, f32, f32, f32);
extern void func_864080A0(void);
extern void func_86408BE0(void);
extern void func_87F0CB58(void);

// Field accesses (not `*(s32 *)(D_86416C00 + n)`) make IDO split each displacement
// at 0x7FFF (`addiu at, base, 0x7FFF`); the pointer-arithmetic spelling instead
// materializes 0x8000 and adds it.
struct Func86405CB4State {
    u8 pad0[0xCDFC];
    s32 unk_CDFC;
    u8 pad1[0xCEAC - 0xCE00];
    s32 unk_CEAC;
};

// Each loop attaches a run of 0x18C-byte entries to the list head 0x14 bytes
// before the run's first entry: 4 entries at 0x7D0, 24 at 0xE14, 80 at 0x3348.
// The first two loops count with `i < n` (slti); the 80-entry loop counts with
// `i != 80` (bne against a register holding 0x50), so the source compares differ.
// unk_CDFC receives a pointer to D_86416C00 + 0xCB8C, unk_CEAC is cleared.
// func_86407330 takes six f32 parameters and stores them at D_86416C00+0x14..0x28
// //@asm/us/nonmatchings/fragments/52/fragment52_285750/func_86407330.s


void func_86405CB4(void) {
    s32 i;
    u8 *entry;

    func_80035700(osGetTime());
    entry = D_86416C00 + 0x7D0;
    for (i = 0; i < 4; i++, entry += 0x18C) {
        func_87F026E8((s32)(D_86416C00 + 0x7BC), entry);
    }
    entry = D_86416C00 + 0xE14;
    for (i = 0; i < 24; i++, entry += 0x18C) {
        func_87F026E8((s32)(D_86416C00 + 0xE00), entry);
    }
    entry = D_86416C00 + 0x3348;
    for (i = 0; i != 80; i++, entry += 0x18C) {
        func_87F026E8((s32)(D_86416C00 + 0x3334), entry);
    }
    func_86407B54();
    func_86409240((s32)(D_86416C00 + 0xB554));
    func_8640708C();
    ((struct Func86405CB4State *)D_86416C00)->unk_CDFC =
        (s32)(D_86416C00 + 0xCB8C);
    ((struct Func86405CB4State *)D_86416C00)->unk_CEAC = 0;
    func_86407330(120.0f, 430.0f, 40.0f, 120.0f, 0.0f, -210.0f);
    func_864080A0();
    func_86408BE0();
    func_87F0CB58();
}
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern void func_87F0277C(u8 *);
extern s32 func_87F08208(u8 *);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void Audio_PlayDefaultSound(s32);
extern void func_86406660(s32);
extern void func_800226C0(s32);
void func_86405E08(void) {
    s32 state;

    func_87F0277C(D_86416C00 + 0xE0);
    state = func_87F08208(D_86416C00 + 0xA8);
    switch (state) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)(D_86416C00 + 0x10) = 2;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        break;
    case 2:
        func_86406660(0);
        func_800226C0(3);
        break;
    }
}
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern void func_87C037C0(u8 *, s32);
extern s32 StageContext_GetFadeMode(void);
extern void func_86407034(void);
extern void func_864057E0(void);
extern void StageFade_StartFromOpaque(s32);
extern void func_87F00688(void);
extern void func_87F0277C(u8 *);

void func_86405EA4(void) {
    func_87C037C0(D_86416C00 + 0xCEC8, *(s32 *)(*(u8 **)(D_86416C00 + 0xB4) + 0xC));
    if (StageContext_GetFadeMode() == 1) {
        func_86407034();
        func_864057E0();
        StageFade_StartFromOpaque(0x14);
        *(s32 *)(D_86416C00 + 0x10) = 3;
        func_87F00688();
    }
    func_87F0277C(D_86416C00 + 0xE0);
}
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern u8 D_86409720;
extern u8 D_86409734[];
extern s32 D_864097EC;
extern u8 D_86409928[];
extern u8 D_8640995C[];
extern u8 D_86409C70[];
extern u8 D_86409C88[];
extern u8 D_86409CA0[];
extern u8 D_87F15B70[];
// include/color_adjustment.h declares this union; it is flattened to one line here because this
// file does not include that header.
// The tag and members are the header's.
typedef union S1_arg1_func_80010CA8 { struct { s16 unk_00; s8 unk_02; s8 unk_03; }; u32 raw; } ColorAdjustment;
extern void func_87F0C650(void *);
extern void func_87F0C694(void *, s32);
extern s32 func_8004DDF4(s32);
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern s32 func_80040E80(s32, void *);
extern u8 *func_8004DF38(s32, s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern ColorAdjustment func_87F0AD50(s32, s32, s32);
extern s32 func_8004E018(s32, s32, s32, ColorAdjustment);
void * func_8004C990();
extern s32 func_87F08E3C(void *, s32);
extern void ModelRenderer_InitDisplayRoots(void);
extern void func_87F024CC(void);
extern s32 func_86407610(void);
extern void *func_80037E9C(void *, void *);
extern void func_87F01870(void *);
extern void func_87F01F34(void *);
extern void func_87F00030(void);
extern void func_87F0C980(void);
extern void func_87F024F4(void *, void *, s32);
extern void func_87F0252C(void *, void *, void *, s32);
extern void func_86407AA0(void);
extern void func_86409280(void *, void *);
extern void func_86405BEC(void);
extern void func_87F029B8(s32, u8);
extern void func_87F0D48C(void *, void *, s32);
extern void func_87F02CB0(s32, s32);
extern void func_86400028(void);
extern void func_86405CB4(void);
extern void func_86407034(void);
extern void func_864057E0(void);
extern void func_87F00688(void);

// Scene-entry rebuild of the renderer state block D_86416C00: registers the four indexed
// colour adjustments (tint func_87F0AD50(*(u8 **)(obj + 0x70), 6, i) stored to +0x788/+0x798 +
// 4*i), an 0x0F000000-flagged alloc at +0xB550, and three func_80037E9C table registrations,
// then fills two pointer tables: four pointers at +0x7F0 + 0x18C*k, each obj + 0x5C*k +
// 0xCB8C, and over six steps of 0x630 the pointers obj + 0x20*n + 0xCCFC/0xCD04/0xCD0C/0xCD14
// to +0xE34/0xFC0/0x114C/0x12D8 + 0x630*n. When byte 0x2180 of the struct at
// *(u8 **)(obj + 0x70) reads 4 the tail also runs func_87F0C694(obj + 0x9C, 0x14) up front
// and, at the end, stores 3 to obj + 0x10 and runs three setup calls.


void func_86405F28(void)
{
  u8 *pool;
  s32 i;
  volatile s32 spare;
  ColorAdjustment tint;
  s32 dof;
  s32 j;
  spare = D_864097EC;
  func_87F0C650(D_86416C00 + 0x9C);
  if ((*((u8 *) ((*((u8 **) (D_86416C00 + 0x70))) + 0x2180))) == 4)
  {
    func_87F0C694(D_86416C00 + 0x9C, 0x14);
  }
  func_8004DDF4(0x71);
  pool = MainPool_AllocState(main_pool_get_available(), 0);
  *((s32 *) (D_86416C00 + 0x6C)) = func_80040E80((s32) pool, D_86409734);
  *((u8 **) (D_86416C00 + 0x7A8)) = func_8004DF38((s32) pool, 0x71, 0);
  *((u8 **) (D_86416C00 + 0x7AC)) = func_8004DF38((s32) pool, 0x71, 1);
  *((s32 *) (D_86416C00 + 0x7B4)) = func_80040E80((s32) pool, D_86409928);
  *((s32 *) (D_86416C00 + 0x7B8)) = func_80040E80((s32) pool, D_8640995C);
  MainPool_FinalizeAllocation(pool);
  // FAKE: emits no instructions; the comparison is the tint loop counter's first use, and
  // uopt's allocation of that counter's web (s1 vs s2 across the loop body) depends on it.
  // Removing it scores 140 (24 rows).
  if (i == 4)
  {
  }
  for (i = 0; i < 4; i++)
  {
    func_8004DDF4(0x6C);
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    tint = func_87F0AD50((s32) (*((u8 **) (D_86416C00 + 0x70))), 6, i);
    *((s32 *) ((D_86416C00 + (i * 4)) + 0x788)) = func_8004E018((s32) pool, 0x6C, 0, tint);
    *((s32 *) ((D_86416C00 + (i * 4)) + 0x798)) = func_8004E018((s32) pool, 0x6C, 1, tint);
    MainPool_FinalizeAllocation(pool);
  }

  // FAKE: `i ^= 0` stores `i` back unchanged and emits no instructions; it gives `i` a web
  // after the tint loop, which is what makes that loop end `slti at,s2,4; bnez` instead of
  // `li at,4; bne s2,at`. Removing it scores 440 (8 rows).
  i ^= 0;
  *((s32 *) (D_86416C00 + 0xB550)) = func_87F08E3C((void *) func_8004C990(0x96, D_86409720), 0x0F000000);
  ModelRenderer_InitDisplayRoots();
  func_87F024CC();
  func_86407610();
  func_80037E9C((void *) 0, D_86409C70);
  func_80037E9C((void *) 0, D_86409C88);
  func_80037E9C((void *) 0, D_86409CA0);
  func_87F01870(*((u8 **) (D_86416C00 + 0x70)));
  func_87F01F34(*((u8 **) (D_86416C00 + 0x70)));
  func_87F00030();
  func_87F0C980();
  func_87F024F4(D_86416C00 + 0x7BC, D_86416C00 + 0x7D0, 4);
  // FAKE: emits no instructions. uopt's colour walk demotes BOTH values that a fully dead
  // `if (v == k) {}` mentions to the end of the walk (in mention order), so this dead
  // compare is what puts the loop-1 counter in $a0 and the 0xCB8C constant in $a1,
  // leaving dof in $v0 and the loop's base load in $v1. Removing it scores 56 (rows).
  if (j == 0xCB8C)
  {
  }
  // Init order and the value's spelling are load-bearing:
  // - `dof = 0, j = 0` (this order) makes as1 emit the two zero moves as the retail
  //   `move v0,zero; move a0,zero`; `j = 0, dof = 0` emits them the other way (2 rows).
  // - the value must be the plain `(base + j) + 0xCB8C`: a `(j * 1)` copy leaves a dead
  //   preheader move and pushes the counter back to $a1 (6 rows).
  for (dof = 0, j = 0; j < 0x170; j += 0x5C, dof += 0x18C)
  {
    *((u8 **) ((D_86416C00 + dof) + 0x7F0)) = (D_86416C00 + j) + 0xCB8C;
  }
  func_87F0252C(D_86409C88, D_86416C00 + 0xE00, D_86416C00 + 0xE14, 0x18);
  dof = 0;
  j = 0;
  l2:
  *((u8 **) ((D_86416C00 + dof) + 0xE34)) = (D_86416C00 + j) + 0xCCFC;

  *((u8 **) ((D_86416C00 + dof) + 0xFC0)) = (D_86416C00 + j) + 0xCD04;
  *((u8 **) ((D_86416C00 + dof) + 0x114C)) = (D_86416C00 + j) + 0xCD0C;
  *((u8 **) ((D_86416C00 + dof) + 0x12D8)) = (D_86416C00 + j) + 0xCD14;
  j += 0x20;
  dof += 0x630;
  if (j != 0xC0)
  {
    goto l2;
  }
  func_87F024F4(D_86416C00 + 0x3334, D_86416C00 + 0x3348, 0x50);
  func_86407AA0();
  func_86409280(D_86416C00 + 0xB554, D_86409CA0);
  func_87F0252C(D_87F15B70, D_86416C00 + 0xE0, D_86416C00 + 0xF4, 4);
  func_86405BEC();
  func_87F029B8((s32) (D_86416C00 + 0xCDBC), *((u8 *) ((*((u8 **) (D_86416C00 + 0x70))) + 0x2182)));
  func_87F0D48C(D_86416C00 + 0x74, *((u8 **) (D_86416C00 + 0x70)), 0);
  func_87F02CB0((s32) (D_86416C00 + 0xCDDC), 0x1E);
  func_86400028();
  *((s32 *) ((u8 *) ((s32) D_86416C00 + 0xCEB0))) = 0;
  func_86405CB4();
  // Tail of the same obj + 0x2180 == 4 branch as the entry guard: the two per-scene
  // registrations func_86407034/func_864057E0, the store of render mode 3 to obj + 0x10,
  // and the final setup call func_87F00688.
  if ((*((u8 *) ((*((u8 **) (D_86416C00 + 0x70))) + 0x2180))) == 4)
  {
    func_86407034();
    func_864057E0();
    *((s32 *) (D_86416C00 + 0x10)) = 3;
    func_87F00688();
  }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8640633C begin */
extern u8 *D_86416C00;
extern void func_80027774(s32, s32);
extern void func_800279C4(s32);
extern void func_87F0CA58(void);
extern void func_8640826C(void);



s32 func_8640633C(void) {
    s32 should_stop;
    s32 result;
    s32 count;
    u8 *p;
    s32 i;
    s32 k;
    u8 *obj;
    u8 *entry;
    s32 flags;

    should_stop = 0;
    result = 0;
    count = 0;
    p = D_86416C00 + 0x7D0;
    for (k = 0; k < 4; k++) {
        if (*(s32 *)(p + 0xC) & 0x40000) {
            count++;
        }
        p += 0x18C;
    }
    obj = D_86416C00 + 0x7D0;
    i = 0;
    do {
        entry = *(u8 **)(obj + 0x20);
        if (*(s32 *)(entry + 0xC) <= 0) {
            if (count == 4) {
                result = 1;
            }
            if (count == 0) {
                should_stop = 1;
                *(s32 *)(obj + 0xC) |= 0x10000;
            }
            flags = *(s32 *)(obj + 0xC);
            if (!(flags & 0x40000)) {
                *(s32 *)(obj + 0xC) = flags | 0x40000;
                *(f32 *)(entry + 0x10) = 10000.0f - (f32)*(s32 *)(entry + 0x14);
                if (*(s32 *)(obj + 0xC) & 0x10000) {
                    func_80027774(0x1C07, 0x44);
                    func_800279C4(0x5F08);
                } else {
                    func_800279C4(0x5F08);
                }
            }
        }
        i++;
        obj += 0x18C;
    } while (i != 4);
    if (should_stop != 0) {
        func_87F0CA58();
        func_8640826C();
    }
    return result;
}
/* mkdraft:func_8640633C end */
#endif

#ifdef VERSION_US
extern void *func_87F0A3E8(void *);
extern void func_8002781C(s32, u8, void *);
extern void func_86406660(s32 arg0);
extern void func_864066B4(void);
void func_864064DC(void) {
    u8 *v0;
    void *v1;

    func_864066B4();
    v1 = func_87F0A3E8(D_86416C00 + 0x724);
    if (v1 != NULL) {
        v0 = D_86416C00;
        if (*(u8 *)(*(u8 **)(v0 + 0x70) + 0x2180) == 1) {
            func_86406660(2);
        } else {
            *(s32 *)(v0 + 0x10) = 6;
        }
    }
}
#endif

#ifdef VERSION_US
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(void *, u16);
extern void GfxImage_ClearDepthRectangle(void *, s32, s32, s32, s32);
extern s32 func_87F00930(void);
extern void GeoRender_AdvanceFrameCounter(void);
extern Gfx *D_800D0510;
extern u8 *D_86416C00;
extern void Geo_RenderRootNode(s32);
extern void func_864082A8(void);
extern void func_87F0A5BC(u8 *);
extern void func_87F07FE8(u8 *);
extern void func_87F022F0(void);
extern void func_87F01D44(void);
extern void func_87F0C88C(u8 *);
extern void func_80008648(void);
void func_86406544(void) {
    s32 flags;

    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 0x401);
    GfxImage_ClearDepthRectangle(&D_800D0510, 0, 0, 0x140, 0xF0);
    if (func_87F00930() == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(*(s32 *)(D_86416C00 + 0x6C));
    func_864082A8();
    if (*(s32 *)(D_86416C00 + 0x10) == 5) {
        func_87F0A5BC(D_86416C00 + 0x724);
    }
    flags = *(s32 *)(D_86416C00 + 0xCEB0);
    if (flags & 1) {
        func_87F07FE8(D_86416C00 + 0xA8);
        flags = *(s32 *)(D_86416C00 + 0xCEB0);
    }
    if (flags & 2) {
        func_87F022F0();
    }
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
    func_87F0C88C(D_86416C00 + 0x9C);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern void StageFade_StartFromTransparent(s32);
extern void StageContext_SetClearColor(s32);
void func_86406660(s32 arg0) {
    (*(s32 *)((u8 *)(D_86416C00) + (0xCEB4))) = arg0;
    (*(s32 *)((u8 *)(D_86416C00) + (0x10))) = 7;
    (*(s32 *)((u8 *)(D_86416C00) + (0x68))) = 8;
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(0xA);
}
#endif

#ifdef VERSION_US
extern void func_86405778(void);
extern void func_87F0277C(u8 *);
extern void func_86409260(u8 *);
extern void func_86401550(void);
void func_864066B4(void) {
    func_86405778();
    func_87F0277C(D_86416C00 + 0xE00);
    func_87F0277C(D_86416C00 + 0x3334);
    func_86409260(D_86416C00 + 0xB554);
    func_86401550();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86406710.s")
#endif

#ifdef VERSION_US
extern u8 D_800CE060[];
extern s32 func_87F01A40(void);
extern s32 func_87F006AC(void);
extern void func_86408CA0(s32, s32);
extern void func_87F0CA30(void);
extern void func_86408148(void);
extern void Audio_PlayDefaultSound(s32);
extern void func_86406660(s32 arg0);
extern void func_864066B4(void);
extern u8 * D_86416C00;
void func_864068A4(void) {
    s32 state;
    s32 i;
    u8 *record;
    u8 *object;
    if (StageContext_GetFadeMode() == 0) {
        state = func_87F01A40();
    } else {
        state = 2;
    }
    switch (state) {
    case 0:
    case 2:
        func_864066B4();
        record = D_800CE060;
        object = D_86416C00 + 0x7D0;
        for (i = 0; i < 4; i++, record += 0x28, object += 0x18C) {
            if (*(u16 *)(record + 8) & 0x8000) {
                *(s32 *)(object + 0xC) &= 0xFDFFFFFF;
            }
        }
        if (func_87F006AC() == 1) {
            Audio_PlayDefaultSound(0x5F07);
        }
        if (func_87F006AC() == 2) {
            *(s32 *)(D_86416C00 + 0x10) = 4;
            Audio_PlayDefaultSound(0x5F08);
            func_86408CA0(0x22, 0x1E);
            func_87F0CA30();
            func_86408148();
        }
        break;
    case 3:
        func_86406660(0);
        break;
    case 4:
        func_86406660(1);
        break;
    }
}
#endif

#ifdef VERSION_US
extern void func_86408C1C(void);
extern void func_87F006BC(void);
extern void func_86405E08(void);
extern void func_86405EA4(void);
extern void func_86406710(void);
extern void func_864064DC(void);
extern void func_86405CB4(void);
extern s32 func_87F02104(void);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_87F0D5B8(u8 *);
extern s32 func_87F0C6F4(u8 *);
extern void func_87F0C9D0(s32);
void func_864069DC(void) {
    func_87C037C0(D_86416C00 + 0xCEC8, *(s32 *)(*(u8 **)(D_86416C00 + 0x6C) + 0xC));
    func_86408C1C();
    if (func_87F00930() == 0) {
        func_87F006BC();
    }
    switch (*(s32 *)(D_86416C00 + 0x10)) {
    case 0:
        *(s32 *)(D_86416C00 + 0xCEB0) = 1;
        if (StageContext_GetFadeMode() == 0) {
            *(s32 *)(D_86416C00 + 0x10) = 1;
        }
        break;
    case 1:
        func_86405E08();
        break;
    case 2:
        func_86405EA4();
        break;
    case 3:
        *(s32 *)(D_86416C00 + 0xCEB0) = 0;
        func_864068A4();
        break;
    case 4:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_86406710();
            break;
        case 3:
            func_86406660(0);
            break;
        case 4:
            func_86406660(1);
            break;
        }
        break;
    case 5:
        func_864064DC();
        break;
    case 6:
        *(s32 *)(D_86416C00 + 0xCEB0) = 2;
        switch (func_87F02104()) {
        case 1:
            StageContext_SetClearColor(0);
            *(s32 *)(D_86416C00 + 0x10) = 7;
            *(s32 *)(D_86416C00 + 0x68) = 0;
            StageFade_StartFromTransparent(10);
            break;
        case 2:
            func_86406660(0);
            break;
        case 3:
            func_86406660(1);
            break;
        }
        break;
    case 7:
        if (StageContext_GetFadeMode() == 1) {
            *(s32 *)(D_86416C00 + 0x10) = *(s32 *)(D_86416C00 + 0x68);
            if (*(s32 *)(D_86416C00 + 0x10) == 0) {
                func_86405CB4();
                StageFade_StartFromOpaque(10);
            }
        }
        break;
    }
    func_87F0D5B8(D_86416C00 + 0x74);
    if (func_87F0C6F4(D_86416C00 + 0x9C) != 0) {
        *(s32 *)(D_86416C00 + 0xCEB4) = 3;
        *(s32 *)(D_86416C00 + 0x10) = 8;
    }
    func_87F0C9D0(func_87F00930());
}
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_864069DC(void);
extern void func_86406544(void);
void func_86406C6C(void)
{
  struct Func86406C6CState {
    u8 pad0[0x10];
    s32 status;
    u8 pad1[0xCEAC - 0x14];
    s32 counter;
  };

  func_800086A4(2);
  StageFade_StartFromOpaque(0xA);
  do
  {
    ((struct Func86406C6CState *)D_86416C00)->counter =
        ((struct Func86406C6CState *)D_86416C00)->counter + 1;
    func_80064D28();
    func_864069DC();
    func_86406544();
  }
  while (((struct Func86406C6CState *)D_86416C00)->status != 8);
}
#endif

#ifdef VERSION_US
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern u8 D_800CE100[];
extern u8 D_86409CB8[];
extern void func_86405F28(void);
extern void func_86406C6C(void);

// Same code as fragment50's func_86205308 on this fragment's state D_86409CB8 (stage
// context at 0x70); GS loads different resources (291; 150, 159, 434, 385-387),
// passes 100 to func_87F06EAC, passes the word at 0xB0 with bit 2 set to
// func_80047588, and returns the word at 0xCEB4.
//@src/fragments/50/fragment50_266A60.c
s32 func_86406CF8(s32 arg0, s32 arg1) {
    u8 *var_v0;
    u8 *ptr;
    u8 *end;

    main_pool_push_state(0x4D59524D); // 'MYRM'
    D_86416C00 = D_86409CB8;
    *(s32 *)(D_86416C00 + 0x70) = arg1;
    if (*(u8 *)((u8 *)*(s32 *)(D_86416C00 + 0x70) + 0x2180) == 4) {
        func_80027EE0(4095);
    }
    Gfx_InitDisplayListBuffers(0x20000, 0);
    var_v0 = func_800082E0(0, 0, 2, 1, 2, 1);
    func_8004C09C(291);
    func_87F09EBC(D_86416C00 + 0x724, *(s32 *)(D_86416C00 + 0x70));
    func_87F06EAC(100, D_86416C00 + 0xA8, *(s32 *)(D_86416C00 + 0x70));
    func_8004C8C0(150);
    func_8004C8C0(159);
    func_8004C8C0(434);
    func_8004C8C0(385);
    func_8004C8C0(386);
    func_8004C8C0(387);
    func_87F061D0();
    func_80047588(*(s32 *)(D_86416C00 + 0xB0) | 2, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    // FAKE: both assignments share one source line, as in func_86205308; diff score 30
    // without it.
    ptr = D_800CE060, end = D_800CE100;
    do {
        func_80006148(ptr);
        ptr += 40;
    } while (ptr != end);
    func_86405F28();
    func_80008514(var_v0);
    func_86406C6C();
    func_80008574();
    func_80006158();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D59524D); // 'MYRM'
    func_87F0F480(*(s32 *)(D_86416C00 + 0x70));
    func_80027EE0(4094);
    return *(s32 *)(D_86416C00 + 0xCEB4);
}
#endif
