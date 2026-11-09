#include "global.h"

#ifdef VERSION_US

typedef struct F17FadeClipRectangle {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
} F17FadeClipRectangle;
typedef struct F17FadeClipBuffer {
    s16 count;
    F17FadeClipRectangle rectangles[100];
} F17FadeClipBuffer;
typedef struct F17FadeRenderState {
    s32 resource;
    s16 alpha;
    s16 timer;
    s16 countdown;
    s16 active_buffer;
    F17FadeClipBuffer buffers[2];
} F17FadeRenderState;
// The constructor enumerates 100 rectangle names for each clipping buffer.
// Legacy D_8220EC40..D_8220EC4A views address this same loader-cleared state.
static F17FadeRenderState sFadeState;

typedef struct F17TransitionState {
    s16 state;
    s16 unk_02;
} F17TransitionState;
// func_8220AA54 initializes enabled in six consecutive 28-byte records.
typedef struct Fragment17ChoiceEntry {
    s32 enabled;
    u8 unk_04[24];
} Fragment17ChoiceEntry;
extern Fragment17ChoiceEntry D_8220DEF4[];
static F17TransitionState sTransition106B2 = { 0 };
extern s16 D_822106B2;
extern s16 D_822106CC, D_822106CE;
extern s16 D_822106BA;
extern f32 D_822106C4;
extern f32 D_822106C8;
extern void func_800226C0(s32);
extern u16 D_822106B6;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern s32 func_8220D67C(void);
extern void func_800503A4(s32);
extern void *D_8220EB88;
extern s32 func_8220AD10(void);
extern void *D_8220DA08;
extern u16 D_8220EB82;
extern u8 D_8220D8D0[];
extern s32 D_8220EC38;
extern u8 D_82210698[];
extern void func_82204444(void);
extern void func_82204744(void);
extern s32 func_822047BC(s32 arg0, s32 arg1);
/* mkdraft:Fragment17_InitFadeState begin */
extern void _bzero(u8 *, size_t);
extern s32 func_8004D690(s32);
extern s32 StageContext_GetFadeMode(void);
extern s32 D_8220EC40;
extern s16 D_8220EC44;
extern s16 D_8220EC46;
extern s16 D_8220EC48;

void Fragment17_InitFadeState(void) {
    s16 *alpha = &sFadeState.alpha;
    s16 *timer = &sFadeState.timer;
    _bzero((u8 *)&D_8220EC40, sizeof(sFadeState));
    D_8220EC40 = func_8004D690(7);
    D_8220EC48 = -1;
    if (StageContext_GetFadeMode() == 0) {
        *alpha = 255;
        *timer = 5;
    } else {
        *alpha = 0;
        *timer = 0;
    }
}
/* mkdraft:Fragment17_InitFadeState end */

// Counts D_8220EC46 down by one per call and sets D_8220EC44, the env color alpha drawn by
// func_822069A4, to timer * 0xFF / 5. Returns that alpha; func_822085EC waits for 0.
s32 func_82206950(void) {
    s16 alpha;
    s16 *timer = &D_8220EC46;

    if (*timer > 0) {
        (*timer)--;
        alpha = (*timer * 0xFF) / 5;
    } else {
        alpha = 0;
    }
    D_8220EC44 = alpha;
    return alpha;
}

extern Gfx *D_800D0510;
extern u8 D_8220DBC8[];
extern void func_80046634();
extern void * D_8220DA08;
void func_822069A4(void) { s16 *count_ptr = &D_8220EC44; if (*count_ptr > 0) { gSPDisplayList(D_800D0510++, D_8220DBC8); gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, *count_ptr); func_80046634(((s32 *)D_8220DA08)[1]); } }

/* mkdraft:func_82206A2C begin */
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern void func_800468A0(s32 arg0);
extern void func_81600F0C(void *, s32, s32, s32, s32);


void func_82206A2C(void) {
    s16 *D_8220EC48_ptr = &D_8220EC48;
    s32 var_s2;
    u8 *var_s4;
    u8 *var_s0;
    u8 *var_s1;
    u8 *base;
    base = (u8 *)&D_8220EC40;
    // A count and 100 four-halfword rectangles give each buffer a 0x322-byte stride.
    var_s4 = ((u8 (*)[802])base)[(((s16 *)base)[5])] + 0xC;
    if (((s16 *)base)[4] != 0) {
        func_800468A0(*(s32 *)base);
    } else {
        var_s2 = 0;
        var_s0 = var_s4;
        var_s1 = var_s4 + 2;
        if (*(s16 *)var_s0 > 0) {
            do {
                func_80006F70(&D_800D0510, *(s16 *)(var_s0 + 2), *(s16 *)(var_s0 + 4), *(s16 *)(var_s0 + 6), *(s16 *)(var_s0 + 8));
                func_81600F0C(*(s32 *)base, *(s16 *)var_s1, *(s16 *)(var_s1 + 2), *(s16 *)(var_s1 + 4), *(s16 *)(var_s1 + 6));
                var_s2 += 1;
                var_s0 += 8;
                var_s1 += 8;
            } while (var_s2 < *(s16 *)var_s4);
        }
        func_80006F70(&D_800D0510, 0, 0, 640, 480);
    }
    if ((*D_8220EC48_ptr) > 0) {
        (*D_8220EC48_ptr)--;
    }
}
/* mkdraft:func_82206A2C end */

s32 func_82206B64(s32 arg0) {
    return (0x800 / arg0) & ~1;
}

extern Gfx D_8220DA20[];
extern Gfx *Gfx_AllocDisplayList(s32);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
extern void func_800459AC(s32, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_82206BA4(s32 x, s32 y, s32 width, s32 remaining_height, u8 *image,
                   s32 format, s32 size, s32 rows_per_strip, s32 strip_count, s32 swapped) {
    s32 index;
    s32 right_x;
    s16 bottom_y;
    Vtx *vertices;
    s32 strip_height;
    u32 offset;
    s32 bottom_edge;
    u8 *strip_image;

    vertices = (Vtx *)Gfx_AllocDisplayList(strip_count * 4 * sizeof(Vtx));
    if (vertices != NULL) {
        gSPDisplayList(D_800D0510++, D_8220DA20);
        right_x = x + width;
        for (index = 0; index < strip_count; index++) {
            if (remaining_height < rows_per_strip) {
                strip_height = remaining_height;
            } else {
                strip_height = rows_per_strip;
            }
            offset = index * (width * rows_per_strip);
            if (size == G_IM_SIZ_16b) {
                strip_image = offset * 2 + image;
            } else {
                strip_image = offset + image;
            }
            bottom_edge = y - strip_height;
            Gfx_SetVertexAttributes(vertices, (s16)x, (s16)y, 0, 0, 0, 255, 255, 255, 255);
            // The pixel address is complete; reuse offset for the strip's 10.5 T coordinate.
            offset = (s16)(strip_height << 5);
            bottom_y = bottom_edge;
            Gfx_SetVertexAttributes(vertices + 1, (s16)x, bottom_y, 0, 0, (s16)offset,
                                    255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 2, (s16)right_x, bottom_y, 0, (s16)(width << 5),
                                    (s16)offset, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 3, (s16)right_x, (s16)y, 0, (s16)(width << 5), 0,
                                    255, 255, 255, 255);
            func_800459AC((s32)strip_image, format, size, width, strip_height, swapped,
                          0, 2, 2, 0, 0, 0, 0);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            remaining_height -= rows_per_strip;
            y -= rows_per_strip;
            vertices += 4;
        }
    }
}

extern u8 D_8220DA6C[];
extern s16 D_8220DA40;
extern f32 D_80087E50[];

s32 func_82206EB8(s32 mode, void *node) {
    s32 index = *(s32 *)((u8 *)node + 20);
    f32 amplitude;

    switch (mode) {
    case 0: {
        s16 *entry = (s16 *)((u8 *)D_8220DA6C + (index << 2));
        Vec3f_SetComponentsDuplicate((f32 *)((u8 *)node + 36),
            (f32)entry[0] - 320.0f, 240.0f - (f32)entry[1], -579.0f);
        break;
    }
    case 2:
        switch (index) {
        case 0:
        case 3:
        case 4:
            amplitude = 4096.0f;
            break;
        default:
            amplitude = 2048.0f;
            break;
        }
        *(s16 *)((u8 *)node + 34) = amplitude * D_80087E50[((u16)D_8220DA40) >> 4];
        break;
    }
    return 0;
}

typedef struct Fragment17TextureHeader {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u8 unk_06[2];
} Fragment17TextureHeader;
typedef struct Fragment17TextureRecord {
    u8 model[360];
    void *layout;
    Fragment17TextureHeader *texture;
    s16 tile_count;
    s16 tile_height;
} Fragment17TextureRecord;
extern s16 D_8220DA5A[];
extern s16 D_8220DA80[];
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_82206BA4(s32, s32, s32, s32, u8 *, s32, s32, s32, s32, s32);
extern void func_8003CD84(void);
extern Fragment17TextureRecord D_8220F290[];

s32 func_82206FBC(s32 mode, void *node)
{
  s32 index = *((s32 *) (((u8 *) node) + 20));
  Fragment17TextureRecord *record = &D_8220F290[index];
  s32 offset = index * 4;
  s16 asset = ((s16 *) (((s32) D_8220DA5A) + offset))[0];
  Fragment17TextureHeader *texture;
  s16 y;
  switch (mode)
  {
    case 0:
      if (asset < 0)
    {
      record = &D_8220F290[index];
      record->texture = (Fragment17TextureHeader *) func_8004C990(0, 0);
      record->tile_height = 5;
      record->tile_count = 1;
    }
    else
    {
      record = &D_8220F290[index];
      record->texture = (Fragment17TextureHeader *) func_8004C990(1, asset);
      record->tile_height = func_82206B64(record->texture->width);
      record->tile_count = func_822047BC(record->texture->height, record->tile_height);
    }
      break;

    case 5:
      record = &D_8220F290[index];
      // FAKE: two empty blocks with no effect on the result; they change how IDO
      // schedules the record and texture loads that follow.
      if (1) { } if (1) { }
      texture = record->texture;
      switch (index)
    {
      case 3:

      case 4:
      {
        s16 amount = D_80087E50[((u16) D_8220DA40) >> 4] * 12.0f;
        if (amount >= 3)
        {
          amount = 2;
        }
        y = ((s16 *) (((s32) D_8220DA80) + offset))[1] + amount;
        break;
      }

      default:
        y = ((s16 *) (((s32) D_8220DA80) + offset))[1];
        break;

    }

      func_82206BA4(((s16 *) (((s32) D_8220DA80) + offset))[0], y, texture->width, texture->height, func_8004CA60((u8 *) texture), texture->format, texture->size, record->tile_height, record->tile_count, 1);
      func_8003CD84();
      break;

  }

  return 0;
}

extern u8 D_8220DAB8[];
extern s16 D_8220DA94;
s32 func_822071E8(s32 arg0, void *arg1)
{
  s32 temp_v1;
  u16 angle;
  s32 index;
  temp_v1 = *((s32 *) (((u8 *) arg1) + 0x14));
  switch (arg0)
  {
    case 0:
    {
      s16 *entry;
      entry = (s16 *) (((u8 *) D_8220DAB8) + (temp_v1 << 2));
      Vec3f_SetComponentsDuplicate((f32 *) (((u8 *) arg1) + 0x24), ((f32) entry[0]) - 320.0f, 240.0f - ((f32) entry[1]), -579.0f);
      break;
    }

    case 2:
      angle = D_8220DA94;
      ;
      *((s16 *) (((u8 *) arg1) + 0x22)) = (s16) (D_80087E50[((u16) D_8220DA94) >> 4] * 6144.0f);
      if (temp_v1 >= 2)
    {
      *((s16 *) (((u8 *) arg1) + 0x22)) = -(*((s16 *) (((u8 *) arg1) + 0x22)));
    }
      break;

  }

  return 0;
}

extern Fragment17TextureRecord D_8220F9D8[];
extern Fragment17TextureRecord D_8220FFA8[];
extern s16 D_8220DAAA[];
extern s16 D_8220DAEE[];
extern s16 D_8220DAC8[][2];
extern s16 D_8220DB0C[][2];

s32 func_822072D0(s32 mode, void *node) {
    s32 index = *(s32 *)((u8 *)node + 20);
    s32 offset = index * 4;
    s32 asset = *(s16 *)((u8 *)D_8220DAAA + offset);
    Fragment17TextureRecord *record;
    Fragment17TextureHeader *texture;
    u8 *pixels;

    switch (mode) {
    case 0:
        record = &D_8220F9D8[index];
        record->texture = (Fragment17TextureHeader *)func_8004C990(1, asset);
        record->tile_height = func_82206B64(record->texture->width);
        record->tile_count = func_822047BC(record->texture->height, record->tile_height);
        break;
    case 5:
        record = &D_8220F9D8[index];
        texture = record->texture;
        pixels = func_8004CA60((u8 *)texture);
        func_82206BA4(((s16 *)((s32)D_8220DAC8 + offset))[0],
                     ((s16 *)((s32)D_8220DAC8 + offset))[1],
                     texture->width, texture->height, pixels, texture->format,
                     texture->size, record->tile_height, record->tile_count, 1);
        func_8003CD84();
        break;
    }
    return 0;
}

extern u8 D_8220DAFC[];
extern s16 D_8220DAD8;

s32 func_82207414(s32 mode, void *node) {
    s32 index = *(s32 *)((u8 *)node + 20);
    s16 offset;

    switch (mode) {
    case 0: {
        s16 *entry = (s16 *)((u8 *)D_8220DAFC + (index << 2));
        Vec3f_SetComponentsDuplicate((f32 *)((u8 *)node + 36),
            (f32)entry[0] - 320.0f, 240.0f - (f32)entry[1], -579.0f);
        break;
    }
    case 2:
        switch (index) {
        case 0:
        case 2:
            offset = ((D_80087E50[((u16)D_8220DAD8) >> 4] + 1.0) * 10.0) * 0.5;
            if (index >= 2) {
                offset = -offset;
            }
            *(f32 *)((u8 *)node + 36) =
                (*(s16 *)((u8 *)D_8220DAFC + index * 4) + offset) - 320.0f;
            break;
        case 1:
        case 3:
            *(s16 *)((u8 *)node + 34) = D_80087E50[((u16)D_8220DAD8) >> 4] * 6144.0f;
            if (index >= 2) {
                *(s16 *)((u8 *)node + 34) = -*(s16 *)((u8 *)node + 34);
            }
            break;
        }
        break;
    }
    return 0;
}

s32 func_822075D0(s32 mode, void *node) {
    s32 index = *(s32 *)((u8 *)node + 20);
    s32 offset = index * 4;
    s32 asset = *(s16 *)((u8 *)D_8220DAEE + offset);
    Fragment17TextureRecord *record;
    Fragment17TextureHeader *texture;
    u8 *pixels;

    switch (mode) {
    case 0:
        record = &D_8220FFA8[index];
        record->texture = (Fragment17TextureHeader *)func_8004C990(1, asset);
        record->tile_height = func_82206B64(record->texture->width);
        record->tile_count = func_822047BC(record->texture->height, record->tile_height);
        break;
    case 5:
        record = &D_8220FFA8[index];
        texture = record->texture;
        pixels = func_8004CA60((u8 *)texture);
        func_82206BA4(((s16 *)((s32)D_8220DB0C + offset))[0],
                     ((s16 *)((s32)D_8220DB0C + offset))[1],
                     texture->width, texture->height, pixels, texture->format,
                     texture->size, record->tile_height, record->tile_count, 1);
        func_8003CD84();
        break;
    }
    return 0;
}

struct S1_MemoryBlock;
typedef s32 (*Fragment17NodeCallback)(s32, void *);
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(struct S1_MemoryBlock *);
extern void *process_geo_layout(struct S1_MemoryBlock *, void *);
extern void func_8003F018(s32);
extern void func_80037E3C(void *, Fragment17NodeCallback, void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void *D_8220DA44[];
extern void *D_8220DA98[];
extern void *D_8220DADC[];
extern u8 D_8220DB1C[];
extern s32 D_82210578;

void func_82207714(s32 arg0) {
    struct S1_MemoryBlock *pool;
    Fragment17TextureRecord *record;
    Fragment17TextureRecord *entry;
    s32 index;

    pool = (struct S1_MemoryBlock *)MainPool_AllocState(main_pool_get_available(), 0);
    D_82210578 = (s32)process_geo_layout(pool, D_8220DB1C);
    for (index = 0; index < 5; index++) {
        entry = &D_8220F290[index];
        entry->layout = process_geo_layout(pool, D_8220DA44[index]);
    }
    for (index = 0; index < 4; index++) {
        entry = &D_8220F9D8[index];
        entry->layout = process_geo_layout(pool, D_8220DA98[index]);
    }
    for (index = 0; index < 4; index++) {
        entry = &D_8220FFA8[index];
        entry->layout = process_geo_layout(pool, D_8220DADC[index]);
    }
    MainPool_FinalizeAllocation(pool);
    for (index = 0; index < 5; index++) {
        record = &D_8220F290[index];
        func_8003F018((s32)record->model);
        func_80037E3C(record->model, func_82206EB8, (void *)index);
        func_8003F114(record->model, 0, -1, record->layout);
    }
    for (index = 0; index < 4; index++) {
        record = &D_8220F9D8[index];
        func_8003F018((s32)record->model);
        func_80037E3C(record->model, func_822071E8, (void *)index);
        func_8003F114(record->model, 0, -1, record->layout);
    }
    for (index = 0; index < 4; index++) {
        record = &D_8220FFA8[index];
        func_8003F018((s32)record->model);
        func_80037E3C(record->model, func_82207414, (void *)index);
        func_8003F114(record->model, 0, -1, record->layout);
    }
}


extern void func_8005487C(u8 *);
extern void func_82206854(s32, s32, s32);
extern s32 func_800562B8(s32);
extern void func_822068E0(void);
extern s32 func_800071A4(s32, s32, s32, s32, s32);
extern s32 func_8004EB58(u8 *, s32);
extern s32 func_8005049C(s32, s32);
extern void func_8004E308(s32, s32 (*)(s32, void *), s32);
extern void func_8005053C(s32, u8 *);
extern void func_80050578(s32, void *);
extern void func_8004C8C0(s32);
extern void ModelRenderer_InitDisplayRoots(void);
extern void func_82207714(s32);
extern void func_8220AA54(s32, s32);
extern void func_822040A0(s16 *);
extern void func_8220AD38(s32, void *);
extern void func_8220AD70(s32, void *);
extern void func_8220ADA8(s32, void *);
extern void func_8220B770(void);
extern void func_8220B900(void);
extern void func_8220BF68(s32);
extern s32 func_82205A14(s32, void *);
extern s32 func_82205A48(s32, void *);
extern s32 func_82205A8C(s32, void *);
extern s32 func_82205B00(s32, void *);
extern s32 func_82205C14(s32, void *);
extern s32 func_82205CE8(s32, void *);
extern s32 func_82205D78(s32, void *);
extern s32 func_82205E04(s32, void *);
extern s32 func_822061A8(s32, void *);
extern s32 func_82206304(s32, u8 *);
extern s32 func_822064DC(s32, void *);
extern s32 D_8220DA0C;
extern s32 D_8220DA10;
extern s32 D_8220DA14;
extern s32 D_8220DA18;
extern s32 D_8220DA1C;
extern u8 D_8220EC28[];
extern s32 D_8220E120;
extern u8 D_8220EBE0[];
extern u8 D_8220F284[];
extern u8 D_822105A0;
extern u8 D_822105AC;
extern u8 D_822105B8;
extern u8 D_822105C4;
extern u8 D_822105D0;
extern u8 D_822105DC[];
extern u8 D_8220DB8C;


// Defined in src/fragments/17/fragment17_113A60.c.
extern s16 D_8220EB98;
extern s32 func_82205F2C(s32 arg0, u8 *arg1);
extern s32 func_82206124(s32 arg0, void *arg1);
extern s32 func_82206400(s32 arg0, void *arg1);
extern void func_822067C4(s32 arg0, void *arg1);
extern void func_82206804(s32 arg0);

void func_8220792C(void *arg0, s32 arg1) {
    s32 pad0;
    s32 pad1;
    s32 pad2;
    s32 pad3;
    s32 pad4;
    s16 sp80[2];
    u8 *temp_s0_2;
    u8 *var_s2;
    u8 *var_s2_2;
    s32 node;
    u32 tag;
    s32 var_s1;
    u8 *temp_v0;
    void *temp_s0;
    s8 sp5C[4];
    u8 *temp_v1;
    u8 *temp_v1_2;
    u16 digits;

    temp_s0 = (*(void **)((u8 *)(arg0) + 0x20));
    D_8220DA08 = arg0;
    func_8005487C(D_8220EC28);
    func_82206854(arg1, 0, 0);
    D_8220EC38 = 0;
    D_8220DA10 = func_800562B8(0);
    if ((*(u16 *)((u8 *)(D_8220EC28) + 2)) & 1) {
        (*(s16 *)((u8 *)(temp_s0) + 0)) = 1;
    } else {
        (*(s16 *)((u8 *)(temp_s0) + 0)) = 0;
    }
    D_8220DA0C = (s32) (*(s16 *)((u8 *)(temp_s0) + 0));
    (*(s16 *)((u8 *)(temp_s0) + 2)) = 0;
    (*(s16 *)((u8 *)(temp_s0) + 4)) = 0;
    (*(s32 *)((u8 *)(D_8220DA08) + 0)) = -1;
    func_822068E0();
    var_s2_2 = (u8 *)&D_8220EB98, var_s2 = D_8220EBE0;
    do {
        temp_s0_2 = var_s2_2;
        (*(s32 *)((u8 *)(temp_s0_2) + 4)) = func_800071A4(0, 2, 0x20, 0x20, 1);
        (*(f32 *)((u8 *)(temp_s0_2) + 0xC)) = 0.0f;
        (*(f32 *)((u8 *)(temp_s0_2) + 8)) = 0.0f;
        (*(f32 *)((u8 *)(temp_s0_2) + 0x14)) = 0.0f;
        (*(f32 *)((u8 *)(temp_s0_2) + 0x10)) = 0.0f;
        var_s2_2 += 0x18;
    } while ((u32) var_s2_2 < (u32) var_s2);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    D_8220DA14 = func_8004EB58(temp_v0, (*(s32 *)((u8 *)(D_8220DA08) + 0x10)));
    D_8220DA18 = func_8004EB58(temp_v0, (*(s32 *)((u8 *)(D_8220DA08) + 0x14)));
    D_8220DA1C = func_8004EB58(temp_v0, (*(s32 *)((u8 *)(D_8220DA08) + 0x18)));
    MainPool_FinalizeAllocation((struct S1_MemoryBlock *) temp_v0);
    for (var_s1 = 0; var_s1 < 3; var_s1++) {
        func_8004E308(func_8005049C(D_8220DA14, var_s1 + 0x47544530), func_82205F2C, var_s1);
    }
    func_8004E308(func_8005049C(D_8220DA14, 0x6572616E), func_82205A14, 0);
    func_8004E308(func_8005049C(D_8220DA14, 0x635F725F), func_82205A48, 0);
    func_8004E308(func_8005049C(D_8220DA14, 0x73745F6D), func_82205A8C, 0);
    func_8004E308(func_8005049C(D_8220DA14, 0x66757369), func_82205E04, 3);
    func_8004E308(func_8005049C(D_8220DA14, 0x6F70746E), func_82205E04, 4);
    func_8004E308(func_8005049C(D_8220DA14, 0x636F6D69), func_82205E04, 5);
    func_8004E308(func_8005049C(D_8220DA14, 0x66755F6D), func_82205B00, 3);
    func_8004E308(func_8005049C(D_8220DA14, 0x6F705F6D), func_82205B00, 4);
    func_8004E308(func_8005049C(D_8220DA14, 0x636F5F6D), func_82205B00, 5);
    func_8004E308(func_8005049C(D_8220DA14, 0x63617274), (s32 (*)(s32, void *)) func_822067C4, 0);
    func_8004E308(func_8005049C(D_8220DA14, 0x6D6F5F6C), (s32 (*)(s32, void *)) func_82206804, 0);
    func_8004E308(D_8220DA18, func_82205C14, 0);
    func_8004E308(func_8005049C(D_8220DA18, 0x4D57494E), func_82205CE8, 0);
    func_8004E308(func_8005049C(D_8220DA18, 0x4D534731), func_82205D78, 0);
    for (var_s1 = 0; var_s1 != 2; var_s1++) {
        func_8004E308(func_8005049C(D_8220DA1C, var_s1 + 0x736C6630), func_82206124, var_s1);
    }
    func_8004E308(func_8005049C(D_8220DA1C, 0x31703170), func_822061A8, 0);
    func_8004E308(func_8005049C(D_8220DA1C, 0x32703270), func_822061A8, 1);
    func_8004E308(func_8005049C(D_8220DA1C, 0x796F7761), func_82206304, 0);
    func_8004E308(func_8005049C(D_8220DA1C, 0x66757475), func_82206304, 1);
    func_8004E308(func_8005049C(D_8220DA1C, 0x7475796F), func_82206304, 2);
    node = func_8005049C(D_8220DA1C, 0x31705F6D);
    func_8004E308(node, func_82206400, 0);
    func_8005053C(node, &D_822105A0);
    func_80050578(node, &D_8220DB8C);
    node = func_8005049C(D_8220DA1C, 0x3270306D);
    func_8004E308(node, func_82206400, 1);
    func_8005053C(node, &D_822105AC);
    func_80050578(node, &D_8220DB8C);
    node = func_8005049C(D_8220DA1C, 0x3270316D);
    func_8004E308(node, func_82206400, 1);
    func_8005053C(node, &D_822105B8);
    func_80050578(node, &D_8220DB8C);
    node = func_8005049C(D_8220DA1C, 0x6D615F30);
    func_8004E308(node, func_822064DC, 0);
    func_8005053C(node, &D_822105C4);
    func_80050578(node, &D_8220DB8C);
    node = func_8005049C(D_8220DA1C, 0x6D615F31);
    func_8004E308(node, func_822064DC, 1);
    func_8005053C(node, &D_822105D0);
    func_80050578(node, &D_8220DB8C);
    node = func_8005049C(D_8220DA1C, 0x6D615F32);
    func_8004E308(node, func_822064DC, 2);
    func_8005053C(node, D_822105DC);
    // Layout is load-bearing for IDO 7.1 here: the head statements below stay on
    // one source line, and the `do { ... } while (0)` keeps the row-pointer setup
    // as one statement; splitting either changes the register allocation.
    // The byte offset is added with `+=` on a pointer copy because
    // `temp_v1 + off` emits `addu idx,base`, while the increment emits
    // `addu base,idx`.
    func_80050578(node, &D_8220DB8C); var_s2_2 = D_8220EC28 + 0x18; do { (*(s16 *)((u8 *)(var_s2_2) + 0xC)) = 0; var_s1 = 0; loop_11: if (var_s2_2 == (u8 *)&D_8220EC40) {
            tag = 0x57503030;
        } else {
            tag = 0x43483030;
        }
        sprintf(sp5C, "%02d", var_s1);
        digits = (sp5C[0] << 8) | sp5C[1];
        tag = (tag & 0xFFFF0000) | (digits & 0xFFFF);
        node = func_8005049C(D_8220DA14, tag);
        var_s1 += 1;
        if (node != 0) {
            do { temp_v1 = var_s2_2 + 0xC; } while (0);
            temp_v1_2 = temp_v1;
            temp_v1_2 += (*(s16 *)((u8 *)(temp_v1) + 0)) * 8;
            (*(s16 *)((u8 *)(temp_v1_2) + 2)) = (s16) (*(s16 *)((u8 *)(node) + 8));
            temp_v1_2 += 2;
            (*(s16 *)((u8 *)(temp_v1_2) + 2)) = (s16) (*(s16 *)((u8 *)(node) + 0xA));
            (*(s16 *)((u8 *)(temp_v1_2) + 4)) = (s16) (*(s16 *)((u8 *)(node) + 0xC));
            (*(s16 *)((u8 *)(temp_v1_2) + 6)) = (s16) (*(s16 *)((u8 *)(node) + 0xE));
            (*(s16 *)((u8 *)(temp_v1) + 0)) = (s16) ((*(s16 *)((u8 *)(temp_v1) + 0)) + 1);
        }
        if (var_s1 != 0x64) {
            goto loop_11;
        }
        var_s2_2 += 0x322;
    } while (var_s2_2 != D_8220F284);
    func_8004C8C0(1);
    func_8004C8C0(0);
    func_8004C8C0(8);
    func_8004C8C0(9);
    func_8004C8C0(2);
    func_8004C8C0(3);
    func_8004C8C0(0xC5);
    func_8004C8C0(0xC6);
    func_8004C8C0(0x93);
    ModelRenderer_InitDisplayRoots();
    func_82207714(arg1);
    func_8220AA54(arg1, 0);
    node = func_8005049C(D_8220DA14, 0x6B6E5F74);
    if (node != 0) {
        func_8220AD70(0, sp80);
        sp80[0] = (*(s16 *)((u8 *)(node) + 8)) - sp80[0];
        sp80[1] = (*(s16 *)((u8 *)(node) + 0xA)) - sp80[1];
        func_8220ADA8(0, sp80);
    }
    node = func_8005049C(D_8220DA14, 0x6B6E5F77);
    if (node != 0) {
        func_8220AD70(1, sp80);
        sp80[0] = (*(s16 *)((u8 *)(node) + 8)) - sp80[0];
        sp80[1] = (*(s16 *)((u8 *)(node) + 0xA)) - sp80[1];
        func_8220ADA8(1, sp80);
    }
    node = func_8005049C(D_8220DA14, 0x6B6E5F65);
    if (node != 0) {
        func_8220AD70(2, sp80);
        sp80[0] = (*(s16 *)((u8 *)(node) + 8)) - sp80[0];
        sp80[1] = (*(s16 *)((u8 *)(node) + 0xA)) - sp80[1];
        func_8220ADA8(2, sp80);
    }
    node = func_8005049C(D_8220DA14, 0x6D745F66);
    if (node != 0) {
        sp80[0] = (*(s16 *)((u8 *)(node) + 8));
        sp80[1] = (*(s16 *)((u8 *)(node) + 0xA));
        func_8220AD38(3, sp80);
        node = func_8005049C(D_8220DA14, 0x6B6E5F66);
        if (node != 0) {
            sp80[0] = (*(s16 *)((u8 *)(node) + 8)) - sp80[0];
            sp80[1] = (*(s16 *)((u8 *)(node) + 0xA)) - sp80[1];
            func_8220ADA8(3, sp80);
        }
    }
    node = func_8005049C(D_8220DA14, 0x6D745F6F);
    if (node != 0) {
        sp80[0] = (*(s16 *)((u8 *)(node) + 8));
        sp80[1] = (*(s16 *)((u8 *)(node) + 0xA));
        func_8220AD38(4, sp80);
        node = func_8005049C(D_8220DA14, 0x6B6E5F6F);
        if (node != 0) {
            sp80[0] = (*(s16 *)((u8 *)(node) + 8)) - sp80[0];
            sp80[1] = (*(s16 *)((u8 *)(node) + 0xA)) - sp80[1];
            func_8220ADA8(4, sp80);
        }
    }
    node = func_8005049C(D_8220DA14, 0x6D745F63);
    if (node != 0) {
        sp80[0] = (*(s16 *)((u8 *)(node) + 8));
        sp80[1] = (*(s16 *)((u8 *)(node) + 0xA));
        func_8220AD38(5, sp80);
        node = func_8005049C(D_8220DA14, 0x6B6E5F63);
        if (node != 0) {
            sp80[0] = (*(s16 *)((u8 *)(node) + 8)) - sp80[0];
            sp80[1] = (*(s16 *)((u8 *)(node) + 0xA)) - sp80[1];
            func_8220ADA8(5, sp80);
        }
    }
    func_822040A0(func_8005049C(D_8220DA18, 0x4D57494E));
    func_8220B770();
    func_8220B900();
    func_8220BF68((*(s32 *)((u8 *)(D_8220DA08) + 0x20)) + 8);
}

/* mkdraft:func_822083C4 begin */
extern void *func_8004C874(s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800497E4(s32, s32, s32, s32);
extern u8 func_80050518(u8);
extern void func_800495BC(s32, s32, const char *);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void Font_EnableTwoCycleTexturing(void);
extern void Font_DisableTwoCycleTexturing(void);
extern void func_800499EC(void);

void func_822083C4(void) {
    u8 *obj = D_8220EB88;
    u8 *position;
    u8 *first_rect;
    u8 *second_rect;
    void *result;
    s32 same;
    // FAKE: unused; its stack home is the unreferenced 0x2C slot that the
    // retail frame (0x48) reserves. Removing it shrinks the frame and
    // shifts the 0x30/0x34 slots (score 16).
    s32 junk;
    first_rect = obj + 0x28;
    result = func_8004C874(*(u16 *)(obj + 0x30), *(u16 *)(obj + 0x32));
    position = first_rect;
    second_rect = obj + 0x2C;
    same = 0;
    func_800498C4();
    func_800496A4(*(u16 *)(obj + 0x24), 0);
    func_8004972C(position[0], position[1], position[2], position[3]);
    if (*(u32 *)second_rect != *(u32 *)position) {
        same = 1;
        Font_EnableTwoCycleTexturing();
        func_800497E4(second_rect[0], second_rect[1], second_rect[2], second_rect[3]);
    }

    if (result) {
        switch (func_80050518(obj[0x27])) {
            case 2:
                func_800495BC(*(s16 *)(obj + 8), *(s16 *)(obj + 0xA), result);
                break;
            case 0:
                func_800495F8(*(s16 *)(obj + 8), *(s16 *)(obj + 0xA), 1, result);
                break;
            case 1:
                func_800495F8(*(s16 *)(obj + 8), *(s16 *)(obj + 0xA), 2, result);
                break;
        }
    }
    if (same) {
        Font_DisableTwoCycleTexturing();
    }
    func_800496A4(8, 0);
    func_8004972C(0, 0xFF, 0xFF, 0xFF);
    func_800499EC();
}
/* mkdraft:func_822083C4 end */

extern void func_80008648();
extern void BgStage_DrawFrame();
extern void Geo_RenderRootNode(s32);
extern void func_822069A4();
extern void func_82206A2C();
extern void func_822083C4();
extern void func_8220B478();
extern void func_8220B984();
extern void func_8220D560();
void func_82208518(void) {
    BgStage_DrawFrame();
    func_82206A2C();
    func_800503A4(D_8220DA14);
    Geo_RenderRootNode(D_82210578);
    func_822069A4();
    func_82204444();
    func_8220B984();
    func_8220B478();
    func_822083C4();
    func_800503A4((*(s32 *)((u8 *)(D_8220DA08) + (0x1C))));
    func_8220D560();
    if (D_8220EB82 & 1) {
        D_8220DA40 += 0x200;
        D_8220DA94 += 0x400;
        D_8220DAD8 += 0x400;
    }
    func_80008648();
}

extern s16 D_8220EB80[];
extern s32 func_82206950(void);
extern s32 func_8220AC38(void);
extern s32 func_8220ADE0(s32);

s32 func_822085EC(void) {
    s32 var_v0 = 0;
    u8 *var_v1 = (u8 *)D_8220EB80;

    if (func_82206950() == 0) {
        var_v0 = 1;
        *(u16 *)(var_v1 + 2) |= 1;
        func_8220AC38();
        if (*(s32 *)(var_v1 + 0x14) != 0) {
            func_82204744();
        }
        if ((*(s16 *)var_v1 == -1) || (func_8220ADE0(*(s16 *)var_v1) != 0)) {
            func_800226C0(52);
        }
    }
    return var_v0;
}

/* mkdraft:func_82208678 begin */
extern u32 func_800060E8(void);
extern s32 func_8220AC64(void);
extern void *D_80087200;

// Selection update for the two modes of this fragment's menu, dispatched on D_8220EC38.
// Mode 1 clamps the s16 cursor at node + 0x2, mode 2 the one at node + 0x4, where "node" is
// the object at D_8220DA08 + 0x20. Every test reads the input halfword at D_80087200 + 8
// afresh; the pointer itself is re-materialized after each func_800226C0 call. flags[] holds
// whether
// bit 0 and bit 1 of func_800060E8's low byte are set, i.e. whether cursor entry 0 or 1 may
// be confirmed. Confirming cursor 0 in mode 1 switches to mode 2 (D_8220EC38 = 2) with that
// mode's cursor set to 1; bit 0x4000 in mode 2 switches back to mode 1. Returns 1 when a
// confirmation was accepted (func_8220AC64 is then called for its switch side effects) and
// -1 when bit 0x4000 was seen in mode 1.




s32 func_82208678(void) {
    s32 old_cursor;
    s32 result = 0;
    s32 i;
    u8 *node;
    s32 flags[2];
    u8 mask;

    node = *(u8 **)((u8 *)D_8220DA08 + 0x20);
    mask = func_800060E8();
    for (i = 0; i < 2; i++) {
        flags[i] = (mask & (1 << i)) != 0;
    }
    switch (D_8220EC38) {
    case 1:
        old_cursor = *(s16 *)(node + 2);
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x200) {
            *(s16 *)(node + 2) = *(s16 *)(node + 2) - 1;
            if (*(s16 *)(node + 2) < 0) {
                *(s16 *)(node + 2) = 0;
            }
        }
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x100) {
            *(s16 *)(node + 2) = *(s16 *)(node + 2) + 1;
            if (*(s16 *)(node + 2) >= 2) {
                *(s16 *)(node + 2) = 1;
            }
        }
        if (old_cursor != *(s16 *)(node + 2)) {
            func_800226C0(1);
        }
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
            if (flags[*(s16 *)(node + 2)] != 0) {
                if (*(s16 *)(node + 2) == 0) {
                    D_8220EC38 = 2;
                    *(s16 *)(node + 4) = 1;
                    func_800226C0(144);
                } else {
                    result = 1;
                }
            } else {
                func_800226C0(5);
            }
        } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
            result = -1;
            func_800226C0(3);
        }
        break;
    case 2:
        old_cursor = *(s16 *)(node + 4);
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x200) {
            *(s16 *)(node + 4) = *(s16 *)(node + 4) - 1;
            if (*(s16 *)(node + 4) < 0) {
                *(s16 *)(node + 4) = 0;
            }
        }
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x100) {
            *(s16 *)(node + 4) = *(s16 *)(node + 4) + 1;
            if (*(s16 *)(node + 4) >= 3) {
                *(s16 *)(node + 4) = 2;
            }
        }
        if (old_cursor != *(s16 *)(node + 4)) {
            func_800226C0(1);
        }
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
            result = 1;
        } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
            D_8220EC38 = 1;
            func_800226C0(3);
        }
        break;
    }
    if (result == 1) {
        func_8220AC64();
    }
    return result;
}
/* mkdraft:func_82208678 end */

extern s32 func_8220D670(void);
s32 func_822088FC(void) { s32 result = 0; s32 value = func_8220D670(); if (value != -1) { result = 1; if (value == 0) { *(s16 *)((u8 *)D_8220DA08 + 0x24) = 0; } else { *(s16 *)((u8 *)D_8220DA08 + 0x24) = 1; } } return result; }

extern s16 D_8220EB84;
extern void func_8220AD1C(s16 *);
extern void func_8220B7A0(s16, s16, u8 *, u8 *);
void func_82208954(s32 arg0) {
    s16 coords[2];
    s32 pad[2];
    u8 *record;

    record = D_8220D8D0 + arg0 * 0x34;
    D_8220EB84 = 0;
    if (*(s16 *)(record + 4) != 0) {
        func_8220AD1C(coords);
        func_8220B7A0(coords[0], coords[1], record + 0x24, record + 0x27);
    }
}

s32 func_822089C0(void) { s32 result = 0; s32 limit; if (func_8220D67C()) limit = 15; else limit = 30; D_8220EB80[2] = D_8220EB80[2] + 1; if (D_8220EB80[2] >= limit) result = 1; return result; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82208A1C.s")

extern s32 StageContext_GetFadeMode(void); extern void func_800086A4(s32); extern void StageFade_StartFromOpaque(s32); extern void func_80064D28(void); extern void func_8220B930(void); extern void func_8220C340(void); extern void func_82204148(void); extern s32 func_82208A1C(s32); extern void func_800548C4(void *); extern void func_80051D64(s32, s32); extern s32 D_8220DA0C; extern u8 D_8220EC28[];
extern void func_82208518(void);
void func_82208DCC(void) {
    s32 temp_v0;
    s16 temp_v0_2;
    s32 var_s0;
    s32 var_s1;
    s32 new_var;

    var_s0 = 1;
    new_var = StageContext_GetFadeMode();
    if (new_var != 0) {
        var_s0 = 0;
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    var_s1 = 9;
    do {
        func_80064D28();
        func_8220B930();
        func_8220C340();
        func_82204148();
        func_82208518();
        temp_v0 = func_82208A1C(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != var_s1);
    ;
    if (D_8220DA0C != (*((s16 *) (*((u8 **) (((u8 *) D_8220DA08) + 0x20)))))) {
        if ((*((s16 *) (*((u8 **) (((u8 *) D_8220DA08) + 0x20))))) == 0) {
            *((u16 *) (D_8220EC28 + 2)) &= 0xFFFE;
        } else {
            *((u16 *) (D_8220EC28 + 2)) |= 1;
        }
        func_800548C4((void *) D_8220EC28);
    }
    func_80051D64(0x14, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82208EB0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82209000.s")

f32 func_822091E0(f32 arg0) {
    return 1.5f - arg0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_822091F0.s")

extern f32 D_822106B0[];
extern s16 D_822106B4, D_822106BE;
extern f32 func_822091E0(f32 arg0);
#pragma COALESCE_AT_LUI(func_82209360, D_822106C8, D_822106CE)
void func_82209360(void) {
    F17TransitionState *transition;
    f32 *scales;
    s32 done;
    s16 *state;
    f32 progress;
    f32 scale;
    f32 width;
    f32 position;
    transition = &sTransition106B2;
    scales = D_822106B0;
    state = (s16 *)D_822106B0;
    state[2]++;
    done = 0;
    if (state[2] >= 2) {
        width = D_822106B4 - 2;
        progress = width / 5.0f;
        if (progress >= 1.0f) {
            progress = 1.0f;
            done = 1;
        }
        scale = (0.6f * progress + 0.4f) * 0.75f;
        scales[6] = scale;
        scales[5] = func_822091E0(scale);
        width = 35.0f;
        position = 320.0f + width - scales[6] * width;
        ((s16 *)scales)[15] = (position > 0.0f ? 0.5f : -0.5f) + position;
        if (done) {
            transition->state = 3;
            transition->unk_02 = 0;
            D_822106BE = 0;
            scales[5] = 0.75f;
            D_822106C8 = 0.75f;
            D_822106CE = 320;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_822094C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_8220980C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82209974.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82209BA4.s")


void func_82209E90(void) {
    D_822106B0[5] = 0.0f;
    D_822106B0[6] = 0.0f;
}

extern void func_822091F0(void);
extern void func_82209360(void);
extern void func_822094C4(void);
extern void func_8220980C(void);
extern void func_82209974(void);
extern void func_82209BA4(void);

s32 func_82209EA8(void) {
    switch (D_822106B2) {
        case 0:
            break;
        case 1:
            func_822091F0();
            break;
        case 2:
            func_82209360();
            break;
        case 3:
            func_822094C4();
            break;
        case 4:
            func_8220980C();
            break;
        case 5:
            func_82209974();
            break;
        case 6:
            func_82209BA4();
            break;
        case 7:
            func_82209E90();
            break;
    }
}

extern s16 D_822106D2;
s32 func_82209F50(void *arg0) {
    s32 pad[4]; // FAKE: reserves the 0x38-byte frame, as in sibling func_8220A098.
    f32 fade;
    f32 x;
    f32 y;

    fade = 1.0f - (f32)(320 - D_822106CE) / 360.0f;
    if (fade < 0.001f) {
        fade = 0.0f;
    } else if (1.0f < fade) {
        fade = 1.0f;
    }
    x = D_822106C4 * fade;
    y = D_822106C8 * fade;
    if (D_822106B6 & 1) {
        x = 0.0f - x;
    }
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x24), (f32)D_822106CC - 320.0f, 240.0f - (f32)(D_822106D2 + 0x15E), -579.0f);
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x30), x, y, 1.0f);
}

// Sets the vectors at arg0 + 0x24 to the screen point (D_822106CC, D_822106CE) relative to the
// 640x480 center at depth -579, and at arg0 + 0x30 to (x, D_822106C8, 1), where x is
// D_822106B0[5], negated when bit 0 of the halfword at D_822106B0 + 6 is set.
s32 func_8220A098(void *arg0) {
    s32 pad[4]; // FAKE: reserves the 0x30-byte frame; diff score 58 without it.
    f32 x;

    x = D_822106B0[5];
    if (*(u16 *)((u8 *)D_822106B0 + 6) & 1) {
        x = 0.0f - x;
    }
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x24), D_822106CC - 320.0f, 240.0f - D_822106CE, -579.0f);
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x30), x, D_822106C8, 1.0f);
}

extern s32 func_82208EB0(void *);
extern s32 func_82209F50(void *);
extern s32 func_8220A098(void *);
s32 func_8220A154(s32 arg0, void *arg1) { s32 flag = *(s32 *)((u8 *)arg1 + 0x14); switch (arg0) { case 0: func_82208EB0(arg1); break; case 2: if (flag == 0) { func_82209EA8(); func_82209F50(arg1); } else { func_8220A098(arg1); } break; } return 0; }

extern Gfx D_8220DEB0[];
void func_8220A1C4(s32 texture) {
    s32 alpha;
    s32 strip_count;
    Vtx *vertices;
    u8 *image;
    s32 width;
    s32 remaining_height;
    s32 index;
    s32 strip_height;
    s32 y;
    f32 fade;
    f32 alpha_value;
    f32 rounding;
    s32 left_x;
    s32 right_x;
    s32 pixel_offset;
    s16 bottom_y;
    s16 texture_t;

    strip_count = 1;
    vertices = (Vtx *)Gfx_AllocDisplayList(strip_count * 4 * sizeof(Vtx));
    width = ((Fragment17TextureHeader *)texture)->width;
    remaining_height = ((Fragment17TextureHeader *)texture)->height;
    y = remaining_height / 2;
    image = func_8004CA60((u8 *)texture);
    if (vertices != NULL) {
        fade = 1.0f - (f32)(320 - D_822106CE) / 200.0f;
        if (fade < 0.001f) {
            fade = 0.0f;
        } else if (fade > 1.0f) {
            fade = 1.0f;
        }
        alpha_value = 255.0f * fade;
        if (alpha_value > 0.0f) {
            rounding = 0.5f;
        } else {
            rounding = -0.5f;
        }
        gSPDisplayList(D_800D0510++, D_8220DEB0);
        alpha = (s32)(rounding + alpha_value);
        gDPSetEnvColor(D_800D0510++, 255, 255, 255, alpha);
        left_x = -(width / 2);
        right_x = left_x + width;
        for (index = 0; index < strip_count; index++) {
            if (remaining_height < 34) {
                strip_height = remaining_height;
            } else {
                strip_height = 34;
            }
            pixel_offset = index * (width * 34);
            texture_t = strip_height << 5;
            bottom_y = y - strip_height;
            Gfx_SetVertexAttributes(vertices, (s16)left_x, (s16)y, 0, 0, 0, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 1, (s16)left_x, bottom_y, 0, 0, strip_height << 5, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 2, (s16)right_x, bottom_y, 0, (s16)(width << 5), texture_t, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 3, (s16)right_x, (s16)y, 0, (s16)(width << 5), 0, 255, 255, 255, 255);
            func_800459AC((s32)(image + pixel_offset), ((Fragment17TextureHeader *)texture)->format,
                          ((Fragment17TextureHeader *)texture)->size, width, strip_height,
                          1, 0, 2, 2, 0, 0, 0, 0);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            vertices += 4;
            y -= strip_height;
            remaining_height -= strip_height;
        }
    }
}

extern void GeoRender_ApplyMaterialState();
extern void func_8220A1C4(s32);
extern s32 D_82210844;
s32 func_8220A5BC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5) && (D_82210844 != 0)) {
        func_8220A1C4(D_82210844);
        GeoRender_ApplyMaterialState();
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_8220A608.s")

extern void func_8220A608(s32);
extern s32 D_822109B4;
s32 func_8220AA08(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5) && (D_822109B4 != 0)) {
        func_8220A608(D_822109B4);
        GeoRender_ApplyMaterialState();
    }
    return 0;
}

typedef struct Fragment17TransitionModelRecord {
    u8 model[360];
    void *layout;
    u8 unk_16C[4];
} Fragment17TransitionModelRecord;
extern Fragment17TransitionModelRecord D_822106D8[];
extern void *D_8220DED8[];
void func_8220AA54(s32 arg0, s32 arg1) {
    s32 index;
    struct S1_MemoryBlock *pool;
    Fragment17TransitionModelRecord *record;
    Fragment17TransitionModelRecord *entry;
    Fragment17ChoiceEntry *choice;
    s16 *selection;

    selection = (s16 *)D_822106B0;
    for (index = 0; index < 6; index++) {
        choice = &D_8220DEF4[index];
        if (index == 5) {
            choice->enabled = arg1;
        } else {
            choice->enabled = 1;
        }
    }
    *selection = arg0;
    do {
        choice = &D_8220DEF4[*selection];
        if (choice->enabled != 0) {
            break;
        }
        if (*selection > 0) {
            --*selection;
        }
    } while (*selection > 0);
    pool = (struct S1_MemoryBlock *)MainPool_AllocState(main_pool_get_available(), 0);
    for (index = 0; index < 2; index++) {
        entry = &D_822106D8[index];
        entry->layout = process_geo_layout(pool, D_8220DED8[index]);
    }
    MainPool_FinalizeAllocation(pool);
    for (index = 0; index < 2; index++) {
        record = &D_822106D8[index];
        func_8003F018((s32)record->model);
        func_80037E3C(record->model, func_8220A154, (void *)index);
        func_8003F114(record->model, 0, -1, record->layout);
    }
}

/* mkdraft:func_8220AC38 begin */

s32 func_8220AC38(void) {
    F17TransitionState *state = &sTransition106B2;
    s32 ret = 0;
    if (*(s16 *)(D_82210698 + 0x1A) == 0) {
        state->state = 1;
        state->unk_02 = 0;
        ret = 1;
    }
    return ret;
}
/* mkdraft:func_8220AC38 end */

typedef struct unk_func_8220AC64_pair { s16 unk_00; s16 unk_02; } unk_func_8220AC64_pair;
extern s16 D_822106D4;
s32 func_8220AC64(void) {
    F17TransitionState *state = &sTransition106B2;
    s32 result = 0;

    if (*(s16 *)(D_82210698 + 0x1A) == 3) {
        state->state = 5;
        state->unk_02 = 0;
        *(unk_func_8220AC64_pair *)&D_822106D4 = *(unk_func_8220AC64_pair *)&D_822106CC;
        D_822106C4 = 0.75f;
        D_822106C8 = 0.75f;
        D_822106BA = -1;
        func_800226C0(57);
        result = 1;
    }
    return result;
}


void func_8220ACF4(void) {
    D_822106BA = -1;
}

s32 func_8220AD04(void) {
    return D_822106BA;
}

extern s16 D_822106B8;
s32 func_8220AD10(void) {
    return D_822106B8;
}


void func_8220AD1C(s16 *arg0) {
    arg0[0] = D_822106CC;
    arg0[1] = D_822106CE;
}


void func_8220AD38(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = &D_8220DEF4[arg0];
        (*(s16 *)((u8 *)(temp_v0) + (0xC))) = (s16) (*(s16 *)((u8 *)(arg1) + (0)));
        (*(s16 *)((u8 *)(temp_v0) + (0xE))) = (s16) (*(s16 *)((u8 *)(arg1) + (2)));
    }
}


void func_8220AD70(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = &D_8220DEF4[arg0];
        (*(s16 *)((u8 *)(arg1) + (0))) = (s16) (*(s16 *)((u8 *)(temp_v0) + (0xC)));
        (*(s16 *)((u8 *)(arg1) + (2))) = (s16) (*(s16 *)((u8 *)(temp_v0) + (0xE)));
    }
}


void func_8220ADA8(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = &D_8220DEF4[arg0];
        (*(s16 *)((u8 *)(temp_v0) + (0x10))) = (s16) (*(s16 *)((u8 *)(arg1) + (0)));
        (*(s16 *)((u8 *)(temp_v0) + (0x12))) = (s16) (*(s16 *)((u8 *)(arg1) + (2)));
    }
}

extern u8 D_8220DEF8[];
s32 func_8220ADE0(s32 arg0) {
    s32 result = 0;
    if ((arg0 >= 0) && (arg0 < 6)) {
        result = *(s32 *)(D_8220DEF8 + (arg0 * 0x1C));
    }
    return result;
}


s32 func_8220AE10(void) {
    return D_822106B2 == 3;
}
#endif
