#include "global.h"


#ifdef VERSION_US
/* Model preview record initialized by ModelPreview_Create. */
//@src/43700.c
typedef struct Fragment22ModelPreview {
    u16 flags, clear_color;
    s16 width, height;
    void *callback;
    s16 countdown, rotation_step;
    f32 scale;
    void *resource;
    void *layout;
    u8 *model;
    u8 *image;
    u8 *depth;
    u8 selection[8];
} Fragment22ModelPreview;

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/22/fragment22_14A2E0/func_82700020.s")

/* mkdraft:func_827000B8 begin */
extern Fragment22ModelPreview *D_827031C4;
extern void *D_827031C0;

s32 ModelAnim_IsFinished(u8 *);
s32 Vec3f_SetComponentsDuplicate(s32 *, f32, f32, s32);
s32 func_8003F2C4(void *, u8 *, s16);
extern void *D_80087200;
extern s32 D_82703360;
extern s16 D_82703382;
extern s32 D_82703384;
extern s16 D_827034CC;
extern s16 D_827034CE;
extern s16 D_827034D0;
extern s16 D_827034D2;
extern s16 D_827034D4;
extern s16 D_827034D6;
extern s16 D_827034D8;

#pragma COALESCE_AT_LUI(func_827000B8, D_827034CC, D_827034CE)


void func_827000B8(void)
{
  s16 *D_827034CC_ptr = &D_827034CC;
  u8 *sp1C;
  u8 *temp_a0;
  s16 counter;
  s32 var_v1;
  s16 *D_827034CE_ptr = &D_827034CE;
  s16 *D_827034D2_ptr = &D_827034D2;
  s32 *D_82703360_ptr = &D_82703360;
  temp_a0 = D_827031C4->model;
  if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0xCC00)
  {
    var_v1 = 1;
  }
  else
  {
    var_v1 = 0;
  }
  switch (*D_827034CC_ptr)
  {
    case 0:
      if (var_v1 != 0)
    {
      *D_827034CE_ptr = 0;
    }
    else
    {
      counter = (*D_827034CE_ptr) + 1;
      *D_827034CE_ptr = counter;
      // FAKE: dead pointer test (both pointers are non-null) used as a scheduling
      // barrier. Its `la`/`bne` pair is deleted by as1, but the split keeps the
      // D_827034CE `lh` ahead of the D_827034D0 `lh`; without it the two loads
      // swap and the score is 340 (10 with it).
      if (((!D_827034D2_ptr) && (!D_827034D2_ptr)) && (!D_827034D2_ptr))
      {
      }
      if (counter >= D_827034D0)
      {
        D_827034CC = 1, D_827034CE = 0;
        D_827034D4 = guRandom() & 3;
        D_827034D6 = (s16) (guRandom() % 640U);
        D_827034D8 = (s16) (guRandom() % 480U);

        // FAKE: `& 0xFFFF` is a no-op for a 16-bit store and as1 deletes the
        // `andi 0xFFFF` it emits, but uopt claims one temp-pool slot for the
        // masked expression, which is what numbers case 1's temps one slot
        // higher (without the mask: 190). A bare `guRandom()` call here also
        // gets common-subexpression-eliminated against the identical call in
        // case 1, which removes this store (both branches bare: 810).
        D_82703382 = guRandom() & 0xFFFF;
      }
    }
      break;

    case 1:
      if (var_v1 != 0)
    {
      *D_827034CC_ptr = 0;

      *D_827034CE_ptr = 0;

    }
    else
    {
      sp1C = temp_a0;

      if (ModelAnim_IsFinished(temp_a0) != 0)
      {
        if ((*D_827034D2_ptr) == 0)
        {
          *D_827034D2_ptr = 2;
        }
        else
        {
          *D_827034D2_ptr = 0;
          D_827034D4 = guRandom() & 3;
          D_827034D6 = (s16) (guRandom() % 640U);
          D_827034D8 = (s16) (guRandom() % 480U);
          // FAKE: same `& 0xFFFF` temp-pool claim as the case-0 store. Without
          // it the later temps in this branch and the tail come out one slot
          // lower than retail (score 440).
          D_82703382 = guRandom() & 0xFFFF;
        }
        func_8003F2C4(D_827031C0, sp1C, -1);
        func_8003F2C4(D_827031C0, sp1C, *D_827034D2_ptr);
      }

    }
      break;

  }


  if ((*D_827034CC_ptr) == 0)
  {
    *((u8 *) (((u8 *) D_82703360_ptr) + 2)) = (u8) ((*((u8 *) (((u8 *) D_82703360_ptr) + 2))) | 4);
  }
  else
  {
    *((u8 *) (((u8 *) D_82703360_ptr) + 2)) = (u8) ((*((u8 *) (((u8 *) D_82703360_ptr) + 2))) & 0xFFFB);
  }
  Vec3f_SetComponentsDuplicate(&D_82703384, ((f32) D_827034D6) - 320.0f, 240.0f - ((f32) D_827034D8), 0xC410C000);

}
/* mkdraft:func_827000B8 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/22/fragment22_14A2E0/func_8270030C.s")

extern s32 D_827031C8;
s32 func_82700598(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5) && (D_827031C8 != 0)) {
        func_8270030C(D_827031C8);
        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void func_827005E4(u16 *arg0, u8 *arg1) {
    arg0[0] = 0;
    arg0[1] = arg1[0];
    arg0[2] = (arg1[1] & 1) != 0;
}

typedef struct Fragment22GraphNode {
    u8 unk_00, unk_01, unk_02, unk_03;
    struct Fragment22GraphNode *unk_04;
    struct Fragment22GraphNode *unk_08;
    u8 *camera;
    s32 (*callback)(s32, struct Fragment22GraphNode *);
    void *unk_14;
} Fragment22GraphNode;
extern void *D_827031C0;
extern s32 D_827031B4;
extern void func_827030D0(s32);
extern Fragment22ModelPreview *D_827031C4;
extern void *D_82703358;
extern u8 D_827031CC[], D_8270321C[], D_82703340[], D_82703350[];
extern f32 D_827032F0;
extern s32 func_8004C09C(u32);
extern s32 func_8004C4B0(s32);
extern s32 func_8004C8C0(u16);
extern void func_827013F0(void *, void *);
extern void PokeIcon_InitResourceArchives(void);
extern void *PokeIcon_AllocLoadContext(u32);
extern void *ModelPreview_Create(void *, s32, s32);
extern s32 func_80042D54(u8 *, u16);
extern s32 func_80042FBC(void *, s32);

extern void ModelRenderer_InitDisplayRoots(void);
extern s32 main_pool_get_available(void);
extern void *MainPool_AllocState(s32, s32);
extern void *process_geo_layout(void *, void *);
extern void MainPool_FinalizeAllocation(void *);
extern void func_82700020(void *);
typedef struct Fragment22Vec3f { f32 x, y, z; } Fragment22Vec3f;
/* Camera prefix shared with the geometry renderer. */
//@src/229E0.c
typedef struct Fragment22Camera {
    Fragment22GraphNode node;
    Vp *viewport;
    s16 x, y, width, height;
    Mtx *projection;
    u16 perspective_normalization;
    f32 fovy, aspect, near_plane, far_plane, perspective_scale;
    Mtx *ortho;
    f32 left, right, bottom, top, ortho_near, ortho_far, ortho_scale;
    f32 (*view_matrix)[4];
    f32 view[4][4];
    LookAt *look_at;
    Fragment22Vec3f eye, at, up;
} Fragment22Camera;

extern void Camera_ComputeEyeFromAngles(Fragment22Vec3f *, Fragment22Vec3f *, f32, s16, s16);
void func_82700604(void) {
    Fragment22Camera *camera;
    void *pool;
    void *model;

    func_8004C09C(3);
    func_8004C4B0(26);
    func_8004C8C0(339);
    func_8004C8C0(121);
    func_827013F0(D_82703340, D_82703350);
    if (D_827031B4 == 1) {
        func_827030D0(D_827031B4);
    }
    PokeIcon_InitResourceArchives();
    D_827031C0 = PokeIcon_AllocLoadContext(1);
    D_827031C4 = ModelPreview_Create(D_827031C0, 128, 128);
    func_80042D54((u8 *)D_827031C4, 0);
    D_827031C4->flags &= ~2;
    D_827031C4->flags &= ~4;
    func_80042FBC(D_827031C4, 178);
    D_827031C4->scale *= D_827032F0;
    camera = (Fragment22Camera *)((Fragment22GraphNode *)D_827031C4->layout)->camera;

    Camera_ComputeEyeFromAngles(&camera->at, &camera->eye, 1250.0f, 1820, 0);
    ModelRenderer_InitDisplayRoots();
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    D_82703358 = process_geo_layout(pool, D_827031CC);
    model = process_geo_layout(pool, D_8270321C);
    MainPool_FinalizeAllocation(pool);
    func_82700020(model);
}

typedef struct Fragment22BackgroundTexture {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u16 unk_06;
} Fragment22BackgroundTexture;
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_800459AC(s32, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80044270(s16, s16, s16, s16, s16, s16, s16, s16, s32);
void func_82700788(void) {
    Fragment22BackgroundTexture *texture;
    s32 slice;
    s32 row;
    s32 offset;
    s32 y;

    texture = (Fragment22BackgroundTexture *)func_8004C990(339, 0);
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetRenderMode(D_800D0510++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetEnvColor(D_800D0510++, 255, 255, 230, 255);
    for (slice = 0, row = 0; slice < 2U; slice++, row += 64) {
        func_800459AC((s32)(func_8004CA60((u8 *)texture) + (texture->width * 64 * slice) / 2),
                      texture->format, texture->size, texture->width,
                      64, 1, 0, 0, 2, 7, 0, 0, 0);
        for (offset = 0, y = row; offset != 512; offset += 128, y += 128) {
            if (y < 480) {
                func_80044270(0, (s16)y, 640, 64, 0, 0, 1024, 1024, 0);
            }
        }
    }
}

extern s32 func_80043678(void *);
extern void BgStage_DrawFrame(void);
extern void func_82700788(void);
extern void Geo_RenderRootNode(void *);
extern void func_82702F70(void);
extern void func_80008648(void);
void func_82700924(void) {
    D_827031C8 = func_80043678(D_827031C4);
    BgStage_DrawFrame();
    func_82700788();
    Geo_RenderRootNode(D_82703358);
    func_82702F70();
    func_80008648();
}

extern s32 func_82703188(void);
s32 func_82700978(void) {
    return func_82703188();
}

extern s32 D_827031B0, D_827031B4;
extern s32 StageContext_GetFadeMode(void);
extern void func_827030D0(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern u32 D_827031B8;
extern s32 D_827031BC;
s32 func_82700998(s32 state) {
    s32 next_state;

    next_state = state;
    switch (state) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            next_state = 1;
            if (D_827031B4 == 0) {
                func_827030D0(D_827031B4);
            }
        }
        break;
    case 1:
        switch (func_82700978()) {
        case 2:
            D_827031B0 = 1;
            D_827031B4 = 1;
            next_state = 3;
            break;
        case 3:
            D_827031B8 = 1;
            D_827031B0 = -1;
            D_827031B4 = 0;
            next_state = 2;
            StageFade_StartFromTransparent(5);
            func_800225C4(10);
            break;
        case 100:
            D_827031BC = 1;
            /* fall through */
        case 4:
            D_827031B0 = -1;
            D_827031B4 = 0;
            next_state = 2;
            StageFade_StartFromTransparent(5);
            func_800225C4(10);
            break;
        }
        break;
    case 2:
        if (StageContext_GetFadeMode() == 1) {
            next_state = 3;
        }
        break;
    }
    return next_state;
}

extern void func_82700604(void);
extern void func_80008624(void);
extern s32 StageContext_GetFadeMode(void);
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_82702658(void);
extern void func_827000B8(void);
extern void func_82700924(void);
extern s32 func_82700998(s32);
extern void StageLoader_WaitForRetrace(void);
void func_82700AF4(void) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    func_82700604();
    func_80008624();
    if (StageContext_GetFadeMode() != 0) {
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    do {
        func_80064D28();
        func_82702658();
        func_827000B8();
        func_82700924();
        temp_v0 = func_82700998(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != 3);
    StageLoader_WaitForRetrace();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/22/fragment22_14A2E0/func_82700B84.s")
#endif
