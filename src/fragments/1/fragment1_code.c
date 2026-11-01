#include "global.h"

#pragma GLOBAL_ASM("hand_asm/fragments/1/fragment1_de0.s")

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern s32 D_835040D8;
extern s32 D_835040DC;
void func_83500020(s32 arg0, s32 arg1) {
    s32 pad[2];
    if (arg0 == 0) {
        D_835040DC = func_8004C990(0x136, 0);
    }
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0, 0, 0, 0x80);
        gDPSetCombine(D_800D0510++, 0xFFB3FF, 0xFFFCFE38);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)D_835040DC));
        gSPDisplayList(D_800D0510++, D_835040D8);
        GeoRender_ApplyMaterialState();
    }
}

extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, s32);
extern u16 D_83503C20;
extern f32 D_80088E50[];
extern f32 D_83503DBC;

s32 func_83500124(s32 arg0, s32 arg1) {
    func_80038E14(arg1, 0, 0.0f, D_80088E50[D_83503C20 >> 4] * D_83503DBC, 0.0f, 0.0f, 0.0f, 0);
    return 0;
}
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_83500198(s32 arg0, void *arg1) {
    s32 pad;
    s32 v28;
    s16 v26;
    s16 v24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &v28, &v26, &v24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(v26 + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(v24 - 0x2000);
    }
    return 0;
}

extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_83500200(s32 arg0, void *arg1) {
    s32 pad;
    s32 v28;
    s16 v26;
    s16 v24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &v28, &v26, &v24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - v26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(v24 + 0x6000);
    }
    return 0;
}

s32 process_geo_layout(s32, s32 *);
extern void PokeIcon_InitResourceArchives();
extern u8 D_83503BEC;
extern u8 D_83503C24;
extern u8 D_83503F30;
extern s32 D_83503F54;
extern s32 D_83503F6C;
extern u8 D_83503F70;
extern s32 MainPool_AllocState(s32, s32);
s32 main_pool_get_available(void);
extern void MainPool_FinalizeAllocation(s32);
void ModelRenderer_InitDisplayRoots(void);
void func_87F02CB0(s32 arg0, s32 arg1);
void func_8003F018(s32 arg0);
void func_8350026C(void) {
    s32 sp1C[3];
    s32 temp_v0;
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C[0] = temp_v0;
    D_83503F54 = process_geo_layout(temp_v0, &D_83503C24);
    D_83503F6C = process_geo_layout(sp1C[0], &D_83503BEC);
    MainPool_FinalizeAllocation(sp1C[0]);
    ModelRenderer_InitDisplayRoots();
    PokeIcon_InitResourceArchives();
    func_87F02CB0((s32) &D_83503F30, 0x64);
    func_8003F018((s32) &D_83503F70);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_code/func_83500300.s")

/* mkdraft:func_83500708 begin */
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_83503AEC;
extern s32 D_83503AD4;
extern f32 D_83503BE8;
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))

// Each packet assigns both words on one source line. With the pair on one line
// IDO 7.1 emits retail's store order here: the w1 store precedes the w0 store
// for every packet except E200001C. Writing each assignment on its own line
// emits w0 before w1 throughout and does not match.


void func_83500708(void) {
    UNUSED s32 pad; // FAKE: unused slots; they place y at sp+0x88 and texture at sp+0x80 (score 18 without pad/pad2)
    s32 y;
    UNUSED s32 pad2;
    s32 texture;
    s32 i;
    u8 *image;

    gSPDisplayList(D_800D0510++, D_80094E38);
    texture = func_8004C990(0x44, 2);
    y = (s32) ((233.0f - 24.0f * D_83503BE8) + ((233.0f > 24.0f * D_83503BE8) ? 0.5f : -0.5f));
    for (i = 0; i != 0x5A00; i += 0xF00) {
        image = func_8004CA60((u8 *) texture);
        gDPPipeSync(D_800D0510++);
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xE200001C; _g->words.w1 = 0x504240; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFA000000; _g->words.w1 = -1U; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFCFFFFFF; _g->words.w1 = 0xFFFCF67B; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFD100000; _g->words.w1 = (u32) &image[i]; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF5100000; _g->words.w1 = 0x07000000; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xE6000000; _g->words.w1 = 0; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF3000000; _g->words.w1 = 0x0777F000; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xE7000000; _g->words.w1 = 0; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF5107800; _g->words.w1 = 0; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF2000000; _g->words.w1 = 0x3BC01C; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFA000000; _g->words.w1 = -0xB0U; }
        GfxRect_DrawTextured(D_83503AEC + D_83503AD4, (s16) (s32) ROUND_MAX((f32) y),
                             (s16) (s32) ROUND_MAX(240.0f * D_83503BE8),
                             (s16) (s32) ROUND_MAX(8.0f * D_83503BE8), 0, 0,
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8),
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8), 0);
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFA000000; _g->words.w1 = -1U; }
        GfxRect_DrawTextured(*(s16 *) ((u8 *) &D_83503AD4 + 2), (s16) (s32) ROUND_MAX((f32) y),
                             (s16) (s32) ROUND_MAX(240.0f * D_83503BE8),
                             (s16) (s32) ROUND_MAX(8.0f * D_83503BE8), 0, 0,
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8),
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8), 0);
        y = (s32) ((f32) y + 8.0f * D_83503BE8);
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_83500708 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_code/func_83500C14.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_code/func_835012C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_code/func_8350182C.s")

extern s32 D_83503BB4;
extern s16 D_83503E82;
extern void func_835012C8(void);
extern void func_83500C14(void);
extern void func_83500708(void);
extern void func_8350182C(void);

void func_83501D3C(void) {
    switch (D_83503BB4) {
        case 2:
        case 3:
        case 4:
            func_835012C8();
        case 1:
            func_83500C14();
        case 0:
            func_83500708();
    }
    if (D_83503BB4 >= 2 && D_83503E82 == 1) {
        func_8350182C();
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_code/func_83501DC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_code/func_83502BFC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/1/fragment1_code/func_83502EF0.s")

/* mkdraft:func_83503048 begin */
extern s32 D_83503BA8;

extern s32 D_83503AD4;
extern s32 D_83503AEC;
extern f32 D_83503BE8;
extern f32 D_83503DA0;



void func_83503048(void)
{
  f32 **new_var2;
  f32 new_var;
  f32 *D_83503DA0_ptr = &D_83503DA0;
  f32 temp_fa1;
  f32 temp_ft4;
  f32 var_fv1;
  s32 temp_t2;
  if ((120.0f * D_83503BE8) < 320.0f)
  {
    var_fv1 = 0.5f;
  }
  else
  {
    var_fv1 = -0.5f;
  }
  new_var = *D_83503DA0_ptr;
  temp_fa1 = ((f32) D_83503AD4) + (new_var * new_var);
  temp_ft4 = 320.0f - (120.0f * D_83503BE8);
  if (((f32) ((s32) (var_fv1 + temp_ft4))) <= temp_fa1)
  {
    if (1)
    {
      if ((120.0f * D_83503BE8) < 320.0f)
      {
        var_fv1 = 0.5f;
      }
      else
      {
        var_fv1 = -0.5f;
      }
      D_83503AD4 = (s32) (var_fv1 + temp_ft4);
    }
    D_83503AEC = 0;
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) -= 2;
    if (((temp_t2 = *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)), temp_t2 < 0)) != 0)
    {
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 1;
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = 0x1E;
    }
  }
  else
  {
    D_83503AD4 = (s32) temp_fa1;
    new_var2 = &D_83503DA0_ptr;
    new_var = (f32) (((f64) new_var) + 0.5);
    *(*new_var2) = new_var;
  }
}
/* mkdraft:func_83503048 end */

/* mkdraft:func_83503188 begin */
extern s32 D_83503BA8;
extern s32 D_83503AC4;
extern s32 D_83503AD4;
extern s32 D_83503AF0;
extern f32 D_83503BE8;
extern f32 D_83503DA4;
extern f64 D_83503E38;
extern void func_800226C0(s32);

// Arena timer state; D_83503BA8+0xC / +0x10 are its two counters.
// func_835034A8 (below in this file) drives the same block.



void func_83503188(void) {
    f32 *D_83503DA4_ptr = &D_83503DA4;
    f32 temp_fa0;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv1;
    
    var_fv0 = 27.0f * D_83503BE8;
    if (var_fv0 < 155.0f) {
        var_fv1 = 0.5f;
    } else {
        var_fv1 = -0.5f;
    }
    var_fa1 = 155.0f - var_fv0;
    temp_fa0 = ((*D_83503DA4_ptr) * (*D_83503DA4_ptr)) + (f32) (*(s32 *) ((u8 *) (&D_83503AD4) + 0xC));
    if ((f32) (s32) (var_fv1 + var_fa1) <= temp_fa0) {
        if (D_83503AC4 == 0) {
            func_800226C0(0x66);
            D_83503AC4 = 1;
            var_fv0 = 27.0f * D_83503BE8;
            var_fa1 = 155.0f - var_fv0;
        }
        if (var_fv0 < 155.0f) {
            var_fv1 = 0.5f;
        } else {
            var_fv1 = -0.5f;
        }
        (*(s32 *) ((u8 *) ((u32) &D_83503AD4) + 0xC)) = (s32) (var_fv1 + var_fa1);
        D_83503AF0 = 0;
        if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) -= 2) < 0) {
            *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 2;
            *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = 0x1E;
        }

    } else {
        (*(s32 *) ((u8 *) (&D_83503AD4) + 0xC)) = (s32) temp_fa0;
        (*D_83503DA4_ptr) = (f32) ((f64) (*D_83503DA4_ptr) + (D_83503E38));
    }
}
/* mkdraft:func_83503188 end */

/* mkdraft:func_83503324 begin */
extern s32 D_83503AC8;
extern f32 D_83503BE8;
extern f32 D_83503DA8;
extern f32 D_83503E40;
extern f32 D_83503E44;
extern f64 D_83503E48;
extern s32 D_83503AF4;
extern s32 D_83503AD4;
extern s32 D_83503BA8;
extern void func_800226C0(s32);



void func_83503324(void) {
    f32 *D_83503DA8_ptr = &D_83503DA8;
    f32 temp_fa0;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv1;
    f32 var_fv0;

    var_fa1 = D_83503E40;
    // FAKE: weights the D_83503DA8 web; diff score 70 without it.
    if (D_83503DA8_ptr && D_83503DA8_ptr) {}
    // FAKE: rotates the FPR free list so da8/tgt land in f16/f18; diff score 120 without
    // these six empty statements (and 200 without both this and the dead if above).
    if (1) { } if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
    var_fv0 = 32.0f * D_83503BE8;
    if (var_fv0 < var_fa1) {
        var_fv1 = 0.5f;
    } else {
        var_fv1 = -0.5f;
    }
    var_fa0 = var_fa1 - var_fv0;
    // Arena timer read: D_83503AD4+0x14 holds the countdown (580 = 10 s of frames).
    temp_fa0 = ((f32) (*((s32 *) (((u8 *) (&D_83503AD4)) + 0x14)))) - ((*D_83503DA8_ptr) * (*D_83503DA8_ptr));
    if (temp_fa0 <= ((f32) ((s32) (var_fv1 + var_fa0)))) {
        if (D_83503AC8 == 0) {
            func_800226C0(0x66);
            var_fa1 = D_83503E44;
            D_83503AC8 = 1;
            var_fv0 = 32.0f * D_83503BE8;
            var_fa0 = var_fa1 - var_fv0;
        }
        // D_83503BA8+0x10 / +0xC are the two arena counters (see func_835034A8 below).
        *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = 0;
        *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 3;
        if (var_fv0 < var_fa1) {
            var_fv1 = 0.5f;
        } else {
            var_fv1 = -0.5f;
        }
        // The (u32) cast is load-bearing: plain (u8 *) &D_83503AD4 folds the store into
        // lui at,%hi + sw %lo, while the cast keeps the base in $v1 and re-materialises it
        // after the call (diff score 340 without it).
        *((s32 *) (((u8 *) ((u32) &D_83503AD4)) + 0x14)) = (s32) (var_fv1 + var_fa0);
        D_83503AF4 = 0;
        return;
    }
    *((s32 *) (((u8 *) (&D_83503AD4)) + 0x14)) = (s32) temp_fa0;
    *D_83503DA8_ptr = (f32) (((f64) (*D_83503DA8_ptr)) + D_83503E48);
}
/* mkdraft:func_83503324 end */

s32 func_800225C4(s32);
extern s32 D_83503BA8;
extern s16 D_83503E80;
void func_835034A8(void)
{
  *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = (*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10))) + 1;
  if (D_83503E80 == 0)
  {
    if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10))) == 110)
    {
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0)) = 3;
      func_800225C4(10);
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 4;
      StageContext_SetClearColor(1);
      StageFade_StartFromTransparent(10);
    }
  }
  else
  {
    if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10))) == 100)
    {
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 4;
      StageContext_SetClearColor(1);
      StageFade_StartFromTransparent(10);
    }
  }
}
typedef struct unk_D_83503B00 {
    s32 unk_00[42];
} unk_D_83503B00;
extern unk_D_83503B00 D_83503B00;
extern unk_D_83503B00 D_83503E88;
extern s32 D_83503BB0;
extern u8 D_83503F58[];
extern u8 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromOpaque(s32);
extern void func_87F0DBFC(u8 *, s32, u8, s32);
void func_83503548(void) {
    s32 mode;

    mode = StageContext_GetFadeMode();
    if (1 == mode && D_83503E80 == 1) {
        StageFade_StartFromOpaque(10);
        D_83503BB0 = 1;
        D_83503E88 = D_83503B00;
        func_87F0DBFC(D_83503F58, 0, 150, -1);
        D_83503BA8 = 1;
    }
}

#endif
