#include "global.h"


#ifdef VERSION_US
extern s32 D_80094CF0; s32 func_80043700(s32 arg0, s32 arg1) { if (!arg0) { D_80094CF0 = arg1; } return 0; }

extern u8 D_80094CF8;
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern s32 process_geo_layout(s32, void *);
extern void MainPool_FinalizeAllocation(s32);
extern void GeoCamera_SetViewport(void *, s16, s16, s16, s32);
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
void func_80043714(void *arg0, s32 arg1, s32 arg2) {
    s32 camera;
    s32 state;
    state = MainPool_AllocState(main_pool_get_available(), 0);
    *((s32 *)(((u8 *)arg0) + 0x14)) = process_geo_layout(state, &D_80094CF8);
    *((s32 *)(((u8 *)arg0) + 0x18)) = D_80094CF0;
    MainPool_FinalizeAllocation(state);
    camera = *((s32 *)((u8 *)(u32)(*((u32 *)(((u8 *)arg0) + 0x14))) + 0xC));
    GeoCamera_SetViewport((void *)(u32)camera, 0, 0, arg1, arg2);
    GeoCamera_SetPerspective((void *)(u32)camera, 30.0f, 100.0f, 12800.0f);
}

// Render slot of a func_800437B4 list, 0x24 bytes; func_80043BD4 sets unk_20.
typedef struct PokeIconSlot44300 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02[2];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u8 unk_06[0x12];
    /* 0x18 */ u8 *image; // color image from func_800071A4
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} PokeIconSlot44300; // size = 0x24

// Render list made by func_800437B4; func_80043714 sets the geo layout at 0x14 and
// D_80094CF0 at 0x18.
typedef struct PokeIconList44300 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 count;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ void *unk_08;
    /* 0x0C */ PokeIconSlot44300 *slots;
    /* 0x10 */ u8 *depth; // shared depth image, made when arg0 is not NULL
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} PokeIconList44300; // size = 0x1C

extern void *main_pool_alloc(s32, s32);
extern void *func_800071A4(s32, s32, s32, s32, s32);
extern void GfxImage_AttachDepthBuffer(u8 *, u8 *);
extern void _bzero(void *, s32);

// Same code as Pokemon Stadium's PokeIcon_CreateRenderList (src/poke_icon.c): allocates
// arg1 slots, each with an arg2 x arg3 16-bit color image cleared to 0 and sharing the
// depth image, then sets up the scene with func_80043714. GS clears the fields that
// Pokemon Stadium fills with -1 and gSpeciesDisplayTable, and also clears slot words
// 0x1C and 0x20.
PokeIconList44300 *func_800437B4(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    PokeIconList44300 *list = main_pool_alloc(sizeof(PokeIconList44300), 0);

    if (list != NULL) {
        list->unk_00 = 0;
        list->count = arg1;
        list->unk_04 = 0;
        list->unk_06 = 0;
        list->unk_08 = arg0;
        list->slots = main_pool_alloc(arg1 * sizeof(PokeIconSlot44300), 0);
        list->depth = NULL;
        list->unk_14 = 0;
        list->unk_18 = 0;

        if (arg0 != NULL) {
            list->depth = func_800071A4(0, 2, arg2, arg3, 1);
        }

        for (i = 0; i < arg1; i++) {
            list->slots[i].unk_00 = 0;
            list->slots[i].unk_04 = 0;
            list->slots[i].unk_1C = 0;
            list->slots[i].image = func_800071A4(0, 2, arg2, arg3, 0);
            list->slots[i].unk_20 = 0;
            _bzero(*(void **)(list->slots[i].image + 8), arg2 * arg3 * 2);
            if (list->depth != NULL) {
                GfxImage_AttachDepthBuffer(list->slots[i].image, list->depth);
            }
        }

        func_80043714(list, arg2, arg3);
    }
    return list;
}
extern s32 func_80064728();
extern s32 func_8004BA34(s32);
extern void func_8004B7E0(s32, void *);
extern f32 func_8004B888(s32);
s32 func_80043950(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad_frame[2];
    s32 sp24;
    s32 temp_v0;
    s32 var_a0;
    u8 *temp_s0;
    s32 offset;
    s32 var_v1 = 0;
    if ((arg0 != 0) && (arg1 < *((s16 *)((u8 *)arg0 + 2)))) {
        temp_v0 = *((s32 *)((u8 *)arg0 + 0xC));
        if (temp_v0 != 0) {
            offset = arg1 * 0x24;
            temp_s0 = (u8 *)(temp_v0 + offset);
            *((u16 *)temp_s0) = 0;
            if (arg2 != 0) {
                var_a0 = func_80064728(arg3);
                *((u16 *)temp_s0) |= 2;
            } else {
                var_a0 = arg3;
            }
            *((u16 *)(temp_s0 + 2)) = 0;
            *((u16 *)temp_s0) |= 1;
            sp24 = var_a0;
            *((s8 *)(temp_s0 + 6)) = func_8004BA34(var_a0);
            func_8004B7E0(sp24, temp_s0 + 8);
            *((f32 *)(temp_s0 + 0x14)) = func_8004B888(sp24);
            var_v1 = 1;
            *((s32 *)(temp_s0 + 0x1C)) = arg3;
        }
    }
    return var_v1;
}

void func_80043A0C(void* arg0, void* arg1, s32 arg2) {
    func_80043950(arg0, arg1, 0, arg2);
}

void func_80043A30(void* arg0, void* arg1, s32 arg2) {
    func_80043950(arg0, arg1, 1, arg2);
}

s32 func_80043A54(void *arg0, s32 arg1, s16 arg2)
{
  s32 temp_v0;
  u8 *new_var;
  s32 var_v1;
  var_v1 = 0;
  if ((arg0 != 0) && (arg1 < (*((s16 *) (((u8 *) arg0) + 2)))))
  {
    ;
    if ((*((s32 *) (((u8 *) arg0) + 0xC))) != 0)
    {
      new_var = (u8 *) ((*((s32 *) (((u8 *) arg0) + 0xC))) + (arg1 * (0x24 & 0xFFu)));
      *((s16 *) (new_var + 2)) = arg2;
      var_v1 = 1;
    }
  }
  return var_v1;
}

s32 func_80043AA0(void *arg0, s32 arg1, s16 arg2) {
    s32 temp_v0;
    u8 *new_var;
    s32 var_v1;
    var_v1 = 0;
    if ((arg0 != 0) && (arg1 < (*((s16 *)(((u8 *)arg0) + 2))))) {
        if ((*((s32 *)(((u8 *)arg0) + 0xC))) != 0) {
            new_var = (u8 *)((*((s32 *)(((u8 *)arg0) + 0xC))) + (arg1 * (0x24 & 0xFFu)));
            *((s8 *)(new_var + 6)) = arg2;
            var_v1 = 1;
        }
    }
    return var_v1;
}

typedef struct { u32 words[3]; } CopyValue_80043AEC;
typedef struct {
    u8 unused[8];
    CopyValue_80043AEC value;
    u8 tail[0x10];
} CopyRow_80043AEC;
typedef struct {
    u8 unused[2];
    s16 count;
    u8 pad[8];
    CopyRow_80043AEC *rows;
} CopyState_80043AEC;

s32 func_80043AEC(CopyState_80043AEC *arg0, s32 arg1, void *arg2) {
    s32 result = 0;

    if (arg0 != NULL && arg1 < arg0->count) {
        if (arg0->rows != NULL && arg2 != NULL) {
            arg0 = (CopyState_80043AEC *)&arg0->rows[arg1];
            ((CopyRow_80043AEC *)arg0)->value = *(CopyValue_80043AEC *)arg2;
            result = 1;
        }
    }
    return result;
}

s32 func_80043B48(void *arg0, s32 arg1, f32 arg2) {
    s32 temp_v0;
    u8 *new_var;
    s32 var_v1;
    var_v1 = 0;
    if ((arg0 != 0) && (arg1 < (*((s16 *)(((u8 *)arg0) + 2))))) {
        if ((*((s32 *)(((u8 *)arg0) + 0xC))) != 0) {
            new_var = (u8 *)((*((s32 *)(((u8 *)arg0) + 0xC))) + (arg1 * (0x24 & 0xFFu)));
            *((f32 *)(new_var + 0x14)) = arg2;
            var_v1 = 1;
        }
    }
    return var_v1;
}

s32 func_80043B8C(void *arg0, s32 arg1, u16 arg2) {
    s32 temp_v0;
    u8 *new_var;
    s32 var_v1;
    var_v1 = 0;
    if ((arg0 != 0) && (arg1 < (*((s16 *)(((u8 *)arg0) + 2))))) {
        if ((*((s32 *)(((u8 *)arg0) + 0xC))) != 0) {
            new_var = (u8 *)((*((s32 *)(((u8 *)arg0) + 0xC))) + (arg1 * (0x24 & 0xFFu)));
            *((u16 *)(new_var + 4)) = arg2;
            var_v1 = 1;
        }
    }
    return var_v1;
}

typedef struct { u8 pad0[2]; s16 count; u8 pad4[8]; u8 *base; } Func80043BD4State;
s32 func_80043BD4(Func80043BD4State *arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;
    if ((arg0 != NULL) && (arg1 < arg0->count)) {
        if (arg0->base != 0) {
            arg0 = (Func80043BD4State *)((u8 *)arg0->base + (arg1 * 0x24));
            (*(s32 *)((u8 *)arg0 + 0x20)) = arg2;
            var_v1 = 1;
        }
    }
    return var_v1;
}

/* mkdraft:func_80043C14 begin */
extern s8 D_80094CF4;
extern Gfx *D_800D0510;
extern u16 Pokemon_GetDisplaySpecies(u8 *);
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void GfxImage_SetRenderTarget(Gfx **, s32);
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C964(s32);
extern void Geo_RenderRootNode(s32);
extern void GfxImage_FillCurrent(Gfx **, u16);
extern void GfxImage_ClearDepthRectangle(Gfx **, s32, s32, s32, s32);
extern void Camera_ComputeEyeFromAngles(u8 *, u8 *, f32, s16, s16);
extern void ModelAnim_SetResourceAnimation(void *, void *, s32);
extern s32 SceneObject_SetModelVariant(u8 *, s32, u16);
extern void ModelAnim_SetFrame(u8 *, s16);

// Three-component vector copied into the model's 0x24 field.
typedef struct { s32 x, y, z; } IconVector44300;

// Textures the icon slots into a shared color/depth pair, choosing one of two
// render paths per slot.


void func_80043C14(PokeIconList44300 *arg0, s32 arg1) {
    void *camera;
    PokeIconSlot44300 *slot;
    void *model0;
    s32 species;
    u8 *record;
    u16 variant;

    camera = *(void **)(arg0->unk_14 + 0xC);
    slot = &arg0->slots[arg1];
    model0 = **(void ***)(*(u8 **)((u8 *)arg0->unk_08 + 0x38) + 8);
    if (*(u16 *)((u8 *)slot + 0x0) & 2) {
        record = (u8 *)slot->unk_1C;
        species = Pokemon_GetDisplaySpecies(record);
        variant = *(u16 *)(record + 0x16);
    } else {
        species = slot->unk_1C;
        variant = 0;
    }
    *(IconVector44300 *)((u8 *)arg0->unk_18 + 0x24) = *(IconVector44300 *)((u8 *)slot + 0x8);
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0->unk_18 + 0x30), *(f32 *)((u8 *)slot + 0x14), *(f32 *)((u8 *)slot + 0x14), *(f32 *)((u8 *)slot + 0x14));
    *(s16 *)((u8 *)arg0->unk_18 + 0x20) = *(s16 *)((u8 *)slot + 0x2);
    func_8003F1DC((void *)arg0->unk_18);
    // The high halfword of species is the second s16 the model setup reads; the
    // byte-cast form keeps the load as the retail lh rather than a shift.
    func_8003F114((u8 *)arg0->unk_18, 0, *(s16 *)((u8 *)&species + 2), model0);
    SceneObject_SetModelVariant((u8 *)arg0->unk_18, species, variant);
    if (D_80094CF4 != -1) {
        *(s8 *)((u8 *)arg0->unk_18 + 0xA6) = D_80094CF4;
        D_80094CF4 = -1;
    }
    ModelAnim_SetResourceAnimation((void *)arg0->unk_08, (void *)arg0->unk_18, 1);
    ModelAnim_SetFrame((u8 *)arg0->unk_18, *(u8 *)((u8 *)slot + 0x6));
    *(u8 *)((u8 *)arg0->unk_18 + 0x2) &= ~0x40;
    *(u8 *)((u8 *)arg0->unk_18 + 0x2) |= 0x80;
    Camera_ComputeEyeFromAngles((u8 *)camera + 0xB4, (u8 *)camera + 0xA8, 1250.0f, 0x71C, -0xE39);
    GfxImage_SetRenderTarget(&D_800D0510, (s32)arg0->slots[arg1].image);
    GeoRender_AdvanceFrameCounter();
    func_8003C964(3);
    Geo_RenderRootNode(arg0->unk_14);
    if (slot->unk_20 == 0) {
        GfxImage_FillCurrent(&D_800D0510, *(u16 *)((u8 *)slot + 0x4));
    } else {
        // The callback's value is discarded. Declaration-only change: `s32`
        // instead of `void` keeps that return in $v0 across the two packet
        // writes, which is the retail allocation. With `void` the differ scores
        // 420 plain / 385 with FD_RELOC=1.
        // FAKE: the return type does not describe the callee; it exists to hold
        // $v0 live. Score without this cast: 420 plain, 385 relocated.
        ((s32 (*)())slot->unk_20)(slot);
        gDPPipeSync(D_800D0510++);
        gDPSetTexturePersp(D_800D0510++, G_TP_PERSP);
        GfxImage_ClearDepthRectangle(&D_800D0510, 0, 0, *(u16 *)((u8 *)slot->image + 0x4), *(u16 *)((u8 *)slot->image + 0x6));
    }
    func_8003C964(1);
    Geo_RenderRootNode(arg0->unk_14);
}
/* mkdraft:func_80043C14 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/44300/func_80043E70.s")

typedef struct B4410Value B4410Value; typedef struct B4410Entry B4410Entry; typedef struct B4410State B4410State; struct B4410Value { u8 pad[8]; s32 value; }; struct B4410Entry { u8 pad[0x18]; B4410Value *value; u8 tail[8]; }; struct B4410State { u8 pad0[2]; s16 count; u8 pad4[8]; B4410Entry *entries; };
s32 func_8004410C(B4410State *arg0, s32 arg1) { s32 result = 0; if (arg1 < arg0->count) { result = arg0->entries[arg1].value->value; } return result; }

typedef struct unk_func_80044144 {
    u16 unk_00;
    u8 unk_02[34];
} unk_func_80044144;

typedef struct unk_func_80044144_arg0 {
    u8 unk_00[2];
    s16 unk_02;
    u8 unk_04[8];
    unk_func_80044144* unk_0C;
} unk_func_80044144_arg0;

s32 func_80044144(unk_func_80044144_arg0* arg0) {
    s32 var_v1 = 1;
    s32 var_v0;

    for (var_v0 = 0; var_v0 < arg0->unk_02; var_v0++) {
        if (arg0->unk_0C[var_v0].unk_00 & 1) {
            var_v1 = 0;
            break;
        }
    }
    return var_v1;
}

extern s32 func_8004BB58(s32, s32);
extern s32 func_8004BC6C(s32, s32);
extern f32 func_8004BAE8(s32, s32);
extern void func_8004BBA8(s32, s32, void *);
extern s32 func_80043AEC(CopyState_80043AEC *, s32, void *);
s32 func_8004418C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_v1;
    u8 sp28[0xC];
    var_v1 = 0;
    if ((arg0 != 0) && (arg2 != 0)) {
        func_80043A54(arg0, arg1, (s16)func_8004BB58(arg2, arg3));
        func_80043AA0(arg0, arg1, (s16)func_8004BC6C(arg2, arg3));
        func_80043B48(arg0, arg1, func_8004BAE8(arg2, arg3));
        func_8004BBA8(arg2, arg3, sp28);
        func_80043AEC(arg0, arg1, sp28);
        var_v1 = 1;
    }
    return var_v1;
}

extern s8 D_80094CF4; void func_80044250(s8 value) { D_80094CF4 = value; }
#endif
