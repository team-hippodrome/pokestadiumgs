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

#pragma GLOBAL_ASM("asm/us/nonmatchings/44300/func_80043C14.s")

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
