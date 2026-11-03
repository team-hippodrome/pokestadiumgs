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

extern s16 D_8220EC44;
extern s16 D_8220EC46;
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

extern s16 D_8220EC44;
extern Gfx *D_800D0510;
extern u8 D_8220DBC8[];
extern void func_80046634();
extern void * D_8220DA08;
void func_822069A4(void) { s16 *count_ptr = &D_8220EC44; if (*count_ptr > 0) { gSPDisplayList(D_800D0510++, D_8220DBC8); gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, *count_ptr); func_80046634(((s32 *)D_8220DA08)[1]); } }

/* mkdraft:func_82206A2C begin */
extern s32 D_8220EC40;
extern s16 D_8220EC48;
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82206BA4.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82206FBC.s")

extern u8 D_8220DAB8[];
extern s16 D_8220DA94;
extern f32 D_80087E50[];
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
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
extern Fragment17TextureRecord D_8220F9D8[];
extern Fragment17TextureRecord D_8220FFA8[];
extern s16 D_8220DAAA[];
extern s16 D_8220DAEE[];
extern s16 D_8220DAC8[][2];
extern s16 D_8220DB0C[][2];
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_82206BA4(s32, s32, s32, s32, u8 *, s32, s32, s32, s32, s32);
extern void func_8003CD84(void);

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
extern Fragment17TextureRecord D_8220F290[];
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_8220792C.s")

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
extern void *D_8220DA08;
extern s32 D_8220DA14;
extern s16 D_8220DA40;
extern s16 D_8220DA94;
extern s16 D_8220DAD8;
extern u16 D_8220EB82;
extern s32 D_82210578;
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
extern void func_82204744(void);
extern s32 func_8220ADE0(s32);
extern void func_800226C0(s32);

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
extern void func_800226C0(s32);
extern s32 func_8220AC64(void);
extern void *D_80087200;
extern void *D_8220DA08;
extern s32 D_8220EC38;

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
extern void *D_8220DA08;
s32 func_822088FC(void) { s32 result = 0; s32 value = func_8220D670(); if (value != -1) { result = 1; if (value == 0) { *(s16 *)((u8 *)D_8220DA08 + 0x24) = 0; } else { *(s16 *)((u8 *)D_8220DA08 + 0x24) = 1; } } return result; }

extern u8 D_8220D8D0[];
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

extern s16 D_8220EB80[];
extern s32 func_8220D67C(void);
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82209360.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_822094C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_8220980C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82209974.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_82209BA4.s")

extern f32 D_822106B0[];

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

extern s16 D_822106CC, D_822106CE;
extern s16 D_822106D2;
extern f32 D_822106C4;
extern f32 D_822106C8;
extern u16 D_822106B6;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_8220A1C4.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_1162A0/func_8220AA54.s")

/* mkdraft:func_8220AC38 begin */
extern u8 D_82210698[];

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

extern s16 D_822106BA;

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

extern s16 D_822106CC, D_822106CE;

void func_8220AD1C(s16 *arg0) {
    arg0[0] = D_822106CC;
    arg0[1] = D_822106CE;
}

extern u8 D_8220DEF4;

void func_8220AD38(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = (arg0 * 0x1C) + &D_8220DEF4;
        (*(s16 *)((u8 *)(temp_v0) + (0xC))) = (s16) (*(s16 *)((u8 *)(arg1) + (0)));
        (*(s16 *)((u8 *)(temp_v0) + (0xE))) = (s16) (*(s16 *)((u8 *)(arg1) + (2)));
    }
}


void func_8220AD70(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = (arg0 * 0x1C) + &D_8220DEF4;
        (*(s16 *)((u8 *)(arg1) + (0))) = (s16) (*(s16 *)((u8 *)(temp_v0) + (0xC)));
        (*(s16 *)((u8 *)(arg1) + (2))) = (s16) (*(s16 *)((u8 *)(temp_v0) + (0xE)));
    }
}


void func_8220ADA8(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = (arg0 * 0x1C) + &D_8220DEF4;
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

extern s16 D_822106B2;

s32 func_8220AE10(void) {
    return D_822106B2 == 3;
}
#endif
