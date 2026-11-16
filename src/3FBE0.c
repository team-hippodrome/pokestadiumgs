#include "229E0.h"

#ifdef VERSION_US

void ModelRenderer_InitDisplayRoots(void) {
    GeoNode_CreateContainer(0, D_80126420);
    GeoNode_CreateContainer(0, D_80126438);
}

void func_8003F018(s32 arg0) {
    func_8003F03C(arg0, D_80126420);
}

void func_8003F03C(s32 arg0, void *arg1) {
    GeoNode_CreateModelPart(NULL, (void *) arg0, -1, &D_800948D0, &D_800948DC, (S1_Vec3f *) D_800948E4);
    func_80038F8C(arg1, (void *) arg0);
    (*(u8 *)((u8 *)(arg0) + (1))) = (u8) ((*(u8 *)((u8 *)(arg0) + (1))) & 0xFFFE);
}

void ModelRenderer_AttachSecondaryDisplayObject(void *arg0) {
    GeoNode_CreateModelPart(NULL, arg0, 0, &D_800948D0, &D_800948DC, (S1_Vec3f *) D_800948E4);
    func_80038F8C(D_80126438, arg0);
    (*(u8 *)((u8 *)(arg0) + (1))) = (u8) ((*(u8 *)((u8 *)(arg0) + (1))) & 0xFFFE);
}

void func_8003F114(u8 *node, s16 animation, s16 model, void *data) {
    func_80038F8C(node, data);
    MtxF_Identity((f32 *)(node + 0x60));
    *(s16 *)(node + 0x18) = animation;
    *(s16 *)(node + 0x1A) = model;
    node[0x1D] = 0xFF;
    node[0x1C] = 0;
    node[1] |= 1;
    node[2] &= ~4;
    node[2] |= 0x20;
    node[2] |= 0x40;
    node[2] &= ~2;
    *(u32 *)(node + 0xA0) = 0xFFFFFF00U;
    *(u32 *)(node + 0x3C) = 0xFFFFFF00U;
    node[0xA6] = 0;
    *(s16 *)(node + 0x40) = -1;
    *(void **)(node + 0x44) = NULL;
    *(s16 *)(node + 0x54) = -1;
    *(void **)(node + 0x58) = NULL;
    node[2] &= ~8;
    if (model >= 0) func_8007074C(node);
    func_8006D430((s32)node);
}

void func_8003F1DC(void *arg0) {
    func_8006D438();
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(u8 *)((u8 *)(arg0) + (1))) = (u8) ((*(u8 *)((u8 *)(arg0) + (1))) & 0xFFFE);
}

s32 ModelAnim_SetAnimation(S1_unk_D_86002F58_004_000 *object, s32 animation) {
    s32 result = 0;
    SceneAnimationBank *bank;
    if (object->unk_000.unk_0C != NULL) {
        if (((SceneAnimationAsset *)object->unk_000.unk_0C)->getAnimationBank != NULL) {
            bank = ((SceneAnimationAsset *)object->unk_000.unk_0C)->getAnimationBank(0, 0);
            if (bank != NULL) {
                if (animation == -1) {
                    ModelAnim_ClearTransformChannel((u8 *)object);
                } else if (animation < bank->transformCount) {
                    ModelAnim_BindTransformCurve(object, (s16)animation, bank->transformTracks[animation], 0x10000);
                    result = 1;
                }
            }
        }
    }
    return result;
}

s32 ModelAnim_SetResourceAnimation(SceneAnimationResource *resource, u8 *object, s32 animation) {
    s32 result = 0;
    SceneAnimationAsset *asset;
    SceneAnimationBank *bank;
    S1_unk_D_86002F58_004_000_040 *channel;
    asset = (SceneAnimationAsset *)((S1_unk_D_86002F58_004_000 *)object)->unk_000.unk_0C;
    bank = asset->getAnimationBank(0, 0);
    channel = &((S1_unk_D_86002F58_004_000 *)object)->unk_040;
    if (animation == -1) {
        ModelAnim_ClearTransformChannel((u8 *)object);
    } else if (animation < bank->transformCount) {
        if (channel->unk_04 != resource->loadedCurve || animation != channel->unk_00) {
            s32 format;
            format = func_80042ADC((u8 *)bank);
            if (format >= 0) {
                func_800422B4((u8 *)resource, format, *(u16 *)bank, ((SceneAnimationTransfer *)bank->transformTracks)[animation].second);
                func_80042968((s32)resource);
            }
        }
        ModelAnim_BindTransformCurve(object, (s16)animation, resource->loadedCurve, 0x10000);
        result = 1;
    }
    return result;
}

s32 ModelAnim_SetEventTrack(void *arg0, s32 arg1) { struct CallbackData { char pad[0x2C]; void *(*callback)(s32, s32); } *data; void *result; data = *(struct CallbackData **)((u8 *)arg0 + 0x0C); result = data->callback(0, 0); if (arg1 == -1) { ModelAnim_ClearEventTrack(arg0); } else if (arg1 < *(u8 *)((u8 *)result + 5)) { ModelAnim_BindEventTrack(arg0, (s16)arg1, ((s32 *)*(void **)((u8 *)result + 0x10))[arg1]); return 1; } return 0; }

void func_8003F454(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    Color_SetRGBA((Color3575C *)(u32)(arg0 + 0xA0), arg1 & 0xFF, arg2 & 0xFF, arg3 & 0xFF, (u8) (s32) arg4);
}

void func_8003F498(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    Color_SetRGBA((Color3575C *)(u32)(arg0 + 0xA0), arg1 & 0xFF, arg2 & 0xFF, arg3 & 0xFF, (u8) (s32) arg4);
}

void func_8003F4DC(u8 *arg0, u8 value) { arg0[0x1D] = value; }

void func_8003F4E8(u8 *arg0, u8 value) { arg0[0x1C] = value; }

s32 func_8003F4F4(void *arg0, s32 arg1) {
    s32 result = 0;
    void *entry;
    if (arg0 == NULL) arg0 = D_8009491C;
    if (arg0 != NULL) {
        entry = *(void **)((u8 *)arg0 + 0xC);
        result = (*(s32 (**)())((u8 *)entry + 0x2C))(arg1, 0);
    }
    return result;
}

void *func_8003F54C(void *arg0) {
    void *result = NULL;
    void *entry;
    void *value;

    entry = *(void **)((u8 *)arg0 + 0xC);
    if (entry != NULL) {
        value = (*(void *(**)(s32, s32))((u8 *)entry + 0x2C))(0, 0);
        if (*(void **)((u8 *)value + 0x18) != NULL) {
            result = func_80003240(*(void **)((u8 *)value + 0x18));
        }
    }
    return result;
}

/* mkdraft:func_8003F5AC begin */
extern s32 HAL_Strcmp(const s8 *, const s8 *);
extern s16 func_8004B920(s32 arg0, s32 arg1);
extern char *func_80060F68(char *arg0, char *arg1);
extern s32 func_800625E0(s32 arg0, s32 arg1);

typedef union unk_func_8003F5AC {
    struct {
        /* 0x00 */ s16 unk_00;
        /* 0x02 */ s8 unk_02;
        /* 0x03 */ s8 unk_03;
    };
    u32 raw;
} unk_func_8003F5AC;

typedef struct unk_func_8003F5AC_arg1 {
    /* 0x00 */ u8 species;
    /* 0x01 */ u8 unk_01[5];
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u8 unk_08[0x2C];
    /* 0x34 */ s8 unk_34[0xC];
    /* 0x40 */ s8 unk_40[0x10];
} unk_func_8003F5AC_arg1;



unk_func_8003F5AC *func_8003F5AC(unk_func_8003F5AC *arg0, unk_func_8003F5AC_arg1 *arg1) {
    char sp50[0x10];
    char sp40[0x10];
    unk_func_8003F5AC sp3C;
    s16 sp3A;
    s16 sp38;
    u8 var_a0;
    UNUSED s32 pad; // FAKE: 4-byte hole between var_a0 and var_v1 keeps the frame at 0x60; without it: 120.
    s8 *var_v1;

    sp3A = func_8004B920(arg1->species, 0);
    sp38 = func_8004B920(arg1->species, 1);
    sp3C.raw = 0;
    func_800625E0((s32)sp50, arg1->species);
    func_80060F68(sp40, (char *)arg1->unk_34);
    if (arg1->species != 0xEB && HAL_Strcmp((const s8 *)sp40, (const s8 *)sp50) != 0) {
        var_a0 = ((arg1->unk_06 >> 8) & 0xFF) + (arg1->unk_06 & 0xFF);
        if (1) {} // FAKE: empty statement closes the sum before the pointers go live, which is what
                  // keeps var_a0 in a0 and var_v1 in v1; without it the two swap registers: 110.

        var_v1 = arg1->unk_34;
        while (*var_v1) {
            var_a0 += *var_v1++ & 0xFF;
            var_a0 += 0; // FAKE: no-op add; places `andi a0,a0,0xFF` in the loop delay slot. Without it: 120.
        }
        var_v1 = arg1->unk_40;
        while (*var_v1) {
            var_a0 += *var_v1++ & 0xFF;
            var_a0 += 0; // FAKE: same delay-slot filler for the second loop. Without both: 240.
        }
        sp3C.unk_00 = ((((sp38 - sp3A) << 6) * var_a0) / 255) + (sp3A << 6);
    }
    *arg0 = sp3C;
    return arg0;
}
/* mkdraft:func_8003F5AC end */

/* mkdraft:func_8003F6E0 begin */
extern s16 func_8004B920(s32 arg0, s32 arg1);
extern char *func_80060F68(char *arg0, char *arg1);
extern s32 func_800625E0(s32 arg0, s32 arg1);
extern s32 HAL_Strcmp(const s8 *a, const s8 *b);

typedef union { struct { s16 value; s16 pad; }; u32 raw; } SizeResult;



SizeResult func_8003F6E0(u8 *arg1, s32 arg2)
{
    char speciesName[16];
    char nickname[16];
    SizeResult result;
    s16 low;
    s16 high;
    s8 *storedName;
    s8 *p;
    u8 sum;
    low = func_8004B920(arg2, 0);
    high = func_8004B920(arg2, 1);
    result.raw = 0;
    func_800625E0((s32)speciesName, arg1[0]);
    storedName = (s8 *)(arg1 + 0x34);
    func_80060F68(nickname, storedName);
    if (arg1[0] != 0xEB && HAL_Strcmp(nickname, speciesName) != 0) {
        sum = ((u8)*((u16 *)(arg1 + 6))) + ((u8)((*((u16 *)(arg1 + 6))) >> 8));
        for (p = (s8 *)(arg1 + 0x34); *p; p++) {
            sum += *p & 0xff;
        }
        for (p = (s8 *)(arg1 + 0x40); *p; p++) {
            sum += *p & 0xff;
        }
        result.value = (s16)(((high - low) << 6) * sum / 255 + (low << 6));
    }
    return result;
}
/* mkdraft:func_8003F6E0 end */

void func_8003F818(s32 *arg0, s32 arg1) {
    _bzero(arg0, 0x10);
    *arg0 = arg1;
}

void func_8003F84C(u8 *arg0, u32 value1, u32 value2) { arg0[4] |= 0x80; *(u32 *)(arg0 + 8) = value1; *(u32 *)(arg0 + 0xC) = value2; }

void func_8003F864(u8 *arg0) { arg0[4] = (u8)(arg0[4] & ~0x10); }

void PokeIcon_RequestBackgroundForObject(SceneBackgroundRequest *request) {
    if (!(request->flags & 0x40) && (request->flags & 0x80)) {
        func_800421E0(request->context, request->source, request->background);
        request->flags |= 0x40;
        request->flags &= ~0x10;
        if (request->flags & 0x20) {
            PokeIcon_WaitBackgroundLoad((s32)request->context);
            request->background = *(s32 *)(request->context + 0x3C);
            request->flags &= ~0xE0;
        }
    }
}

void func_8003F904(u8 *arg0) {
    if (func_80042808(*(s32 *)arg0)) {
        *(s32 *)(arg0 + 0xC) = *(s32 *)(*(s32 *)arg0 + 0x3C), arg0[4] = (arg0[4] & ~0xE0), arg0[4] |= 0x10;
    }
}

s32 func_8003F954(u16 value) { return value % 9; }

s32 func_8003F970(s32 arg0, u16 arg1) {
    s32 result = 0;
    if (arg0 == 0xEB) {
        result = func_8003F954(arg1);
    }
    return result;
}

s32 SceneObject_SetModelVariant(u8 *object, s32 kind, u16 value) {
    s32 result = 0;
    if (object != NULL) {
        object[0xA6] = func_8003F970(kind, value);
        result = 1;
    }
    return result;
}

#endif
