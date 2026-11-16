#include "229E0.h"

#ifdef VERSION_US

void GeoNode_Init(S1_GraphNode* arg0, u8 arg1) {
    if (arg0 != NULL) {
        arg0->unk_00 = arg1;
        arg0->unk_01 = 0x11;
        arg0->unk_02 = 0;
        arg0->unk_03 = 0;
        arg0->unk_04 = arg0;
        arg0->unk_08 = arg0;
        arg0->unk_0C = NULL;
        arg0->unk_10 = NULL;
        arg0->unk_14 = NULL;
    }
}

void func_80037E3C(S1_GraphNode* arg0, S1_func_D_86002F34_000_010 arg1, void* arg2) {
    if (arg1 != NULL) {
        arg1 = func_80003240(arg1);
    }

    if (arg0 != NULL) {
        arg0->unk_14 = arg2;
        arg0->unk_10 = arg1;
        if (arg1 != NULL) {
            arg1(0, arg0);
        }
    }
}

S1_GraphNode* GeoNode_CreateContainer(S1_MainPoolState* arg0, S1_GraphNode* arg1) { if (arg0 != NULL) { arg1 = MainPool_AllocAligned(arg0, sizeof(S1_GraphNode), 4); } if (arg1 != NULL) { GeoNode_Init(arg1, 0); } return arg1; }

S1_unk_D_86002F34_alt2* GeoNode_CreateWithReference(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt2* arg1, S1_GraphNode* arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt2), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 1);
    }

    return arg1;
}

S1_unk_D_86002F34_00C *GeoNode_CreateCamera(S1_MainPoolState *pool, S1_unk_D_86002F34_00C *node, s16 x, s16 y, s16 width, s16 height) {
    if (pool != NULL) {
        node = MainPool_AllocAligned(pool, sizeof(S1_unk_D_86002F34_00C), 4);
    }
    if (node != NULL) {
        GeoCamera_SetViewport(node, x, y, width, height);
        GeoCamera_SetPerspective(node, 30.0f, 100.0f, 12800.0f);
        func_80038E14(node, 0.0f, 512.0f, 4096.0f, 0.0f, 0.0f, 0.0f, 0);
        GeoCamera_SetBackground(node, 2, 0, 0, 0, 0);
        GeoNode_Init((void *)node, 2);
    }
    return node;
}

S1_unk_D_86002F34_alt13* GeoNode_CreateType3(S1_MemoryBlock* arg0, S1_unk_D_86002F34_alt13* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt13), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 3);
    }

    return arg1;
}

S1_unk_D_86002F34_alt1* GeoNode_CreateType4(S1_MemoryBlock* arg0, S1_unk_D_86002F34_alt1* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt1), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = 0;
        GeoNode_Init(arg1, 4);
    }

    return arg1;
}

void *func_800380B8(S1_MainPoolState *arg0, s32 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = (s32)(u32)MainPool_AllocAligned(arg0, 0x18, 4);
    }
    if (arg1 != 0) {
        GeoNode_Init((S1_GraphNode *)arg1, 5U);
        *(u8 *)(arg1 + 2) = *(u8 *)(arg1 + 2) | (arg2 & 7);
    }
    return (void *)arg1;
}

void *func_8003811C(S1_MainPoolState *arg0, s32 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = (s32)(u32)MainPool_AllocAligned(arg0, 0x18, 4);
    }
    if (arg1 != 0) {
        GeoNode_Init((S1_GraphNode *)arg1, 6);
        *(u8 *)(arg1 + 2) = *(u8 *)(arg1 + 2) | (arg2 & 7);
    }
    return (void *)arg1;
}

S1_unk_D_86002F34_alt16* GeoNode_CreateBackground(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt16* arg1, u8 arg2, u8 arg3, u8 arg4) {
    u32 temp_v0;

    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt16), 4);
    }

    if (arg1 != NULL) {
        temp_v0 = ((arg2 >> 3) << 0xB) | ((arg3 >> 3) << 6) | ((arg4 >> 3) << 1) | 1;
        arg1->unk_18 = (temp_v0 << 0x10) | temp_v0;
        GeoNode_Init(arg1, 7);
    }
    return arg1;
}

s32 func_8003820C(s32 arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = arg1;
    if (arg0 != 0) {
        var_a2 = (s32)(u32)MainPool_AllocAligned((void *)(u32)arg0, 0x18, 4);
    }
    if (var_a2 != 0) {
        arg1 = var_a2;
        GeoNode_Init((S1_GraphNode *) var_a2, 8U);
        var_a2 = arg1;
    }
    return var_a2;
}

S1_unk_D_8690A610* GeoNode_CreateFog(s32 arg0, S1_unk_D_8690A610* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != 0) {
        arg1 = MainPool_AllocAligned((void *)(u32)arg0, sizeof(S1_unk_D_8690A610), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18.fogNear = arg2;
        arg1->unk_18.fogFar = arg3;
        arg1->unk_18.fogColor.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0xA);
    }

    return arg1;
}

void *GeoNode_CreateLight(S1_MainPoolState *pool, void *storage, s16 pitch, s16 yaw, u8 red, u8 green, u8 blue, u8 alpha) {
    SceneDirectionalLight *light;
    if (pool != NULL) {
        storage = MainPool_AllocAligned(pool, sizeof(SceneDirectionalLight), 4);
    }
    light = storage;
    if (light != NULL) {
        light->color.r = red;
        light->color.g = green;
        light->color.b = blue;
        light->color.a = alpha;
        light->pitch = pitch;
        light->yaw = yaw;
        light->direction = D_800948DC;
        light->red = 0;
        light->green = 0;
        light->blue = 0;
        light->overrideDirection = 0;
        GeoNode_Init((S1_GraphNode *)light, 0xB);
    }
    return light;
}

void func_80038390(void *arg0, S1_Vec3s *arg1, u8 arg2, u8 arg3, u8 arg4) {
    if (arg0 != NULL) {
        *(S1_Vec3s *)((u8 *)arg0 + 0x20) = *arg1;
        ((u8 *)arg0)[0x28] = arg2;
        ((u8 *)arg0)[0x29] = arg3;
        ((u8 *)arg0)[0x2A] = arg4;
        ((u8 *)arg0)[0x2B] = 1;
    }
}

void func_800383DC(void *arg0, s16 arg1, s16 arg2) {
    if (arg0 != NULL) {
        (*(s16 *)((u8 *)(arg0) + (0x1C))) = arg1;
        (*(s16 *)((u8 *)(arg0) + (0x1E))) = arg2;
        (*(s8 *)((u8 *)(arg0) + (0x2B))) = 0;
    }
}

S1_unk_D_86002F34_alt19* GeoNode_CreateAmbientLight(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt19* arg1, u8 r, u8 g, u8 b) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt19), 4);
    }

    if (arg1 != NULL) {
        arg1->r = r;
        arg1->g = g;
        arg1->b = b;
        GeoNode_Init(arg1, 0xD);
    }

    return arg1;
}

s32 func_80038474(s32 arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = arg1;
    if (arg0 != 0) {
        var_a2 = (s32)(u32)MainPool_AllocAligned((void *)(u32)arg0, 0x18, 4);
    }
    if (var_a2 != 0) {
        arg1 = var_a2;
        GeoNode_Init((S1_GraphNode *) var_a2, 0x1DU);
        var_a2 = arg1;
    }
    return var_a2;
}

S1_GraphNode *func_800384C0(void *arg0, S1_GraphNode *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u16 arg8) {
    S1_GraphNode *new_var;
    u8 *new_var2;
    if (arg0 != 0) {
        arg1 = MainPool_AllocAligned(arg0, 0x30, 4);
    }
    if (arg1 != 0) {
        ((s32 *)(((u8 *)arg1) + 0x18))[0] = arg3;
        ((s32 *)(((u8 *)arg1) + 0x1C))[0] = arg5;
        ((s32 *)(((u8 *)arg1) + 0x20))[0] = arg7;
        ((u8 *)arg1)[0x24] = (u8)arg2;
        ((u8 *)arg1)[0x25] = (u8)arg4;
        ((u16 *)(((u8 *)arg1) + 0x26))[0] = (u16)arg6;
        new_var2 = (u8 *)arg1;
        ((u16 *)(((u8 *)arg1) + 0x28))[0] = arg8;
        ((s32 *)(new_var2 + 0x2C))[0] = 0;
        GeoNode_Init(arg1, 0xE);
    }
    if (1) {
        new_var = arg1;
    }
    return new_var;
}

S1_unk_D_86002F34_alt12* GeoNode_CreateShadow(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt12* arg1, s16 arg2, s16 arg3, s16 arg4,
                                    s16 arg5) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt12), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        arg1->unk_1C = arg4;
        arg1->unk_1E = arg5;
        GeoNode_Init(arg1, 0xF);
    }

    return arg1;
}

S1_unk_D_86002F34_alt20* GeoNode_CreateCullDistance(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt20* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt20), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        GeoNode_Init(arg1, 0x10);
    }

    return arg1;
}

S1_unk_D_86002F34_alt21* GeoNode_CreateSwitchCase(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt21* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt21), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        GeoNode_Init(arg1, 0x11);
    }

    return arg1;
}

S1_unk_D_86002F34_alt5* GeoNode_CreateTranslateRotate(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt5* arg1, S1_Vec3f* arg2, S1_Vec3s* arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt5), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        arg1->unk_24 = *arg3;
        GeoNode_Init(arg1, 0x12);
    }

    return arg1;
}

S1_unk_D_86002F34_alt22* GeoNode_CreateTranslate(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt22* arg1, S1_Vec3f* arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt22), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        GeoNode_Init(arg1, 0x13);
    }

    return arg1;
}

S1_unk_D_86002F34_alt6* GeoNode_CreateAnimatedPart(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt6* arg1, s16 arg2, s16 arg3, s16 arg4,
                                   S1_Vec3s* arg5, S1_Vec3s* arg6, S1_Vec3f* arg7) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt6), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg5;
        arg1->unk_1E = *arg6;
        arg1->unk_24 = *arg7;
        arg1->unk_30 = arg2;
        arg1->unk_31 = arg3;
        arg1->unk_32 = arg4;
        GeoNode_Init(arg1, 0x14);
    }

    return arg1;
}

S1_unk_D_86002F34_alt7* GeoNode_CreateDisplayListPart(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt7* arg1, s32 arg2, Gfx* arg3, s16 arg4) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt7), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        arg1->unk_1C = arg4;
        GeoNode_Init(arg1, 0x15);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

S1_unk_D_86002F58_004_000 *GeoNode_CreateModelPart(S1_MainPoolState *pool, void *storage, s16 model, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) {
    if (pool != NULL) storage = MainPool_AllocAligned(pool, 0x168, 4);
    if (storage != NULL) {
        S1_unk_D_86002F58_004_000 *node = storage;
        node->animType = 0;
        node->modelId = model;
        node->unk_024 = *position;
        node->unk_030 = *scale;
        node->unk_01E = *rotation;
        node->materialAlpha = 0xFF;
        node->textureMode = 0;
        node->unk_0A0.rgba = 0xFFFFFF00U;
        node->unk_03C.rgba = 0xFFFFFF00U;
        node->poolIndex = 0;
        node->unk_040.unk_00 = 0;
        node->unk_040.unk_04 = NULL;
        node->unk_040.unk_08 = 0;
        node->unk_040.unk_0C = 0x10000;
        node->unk_040.unk_12 = 0;
        node->unk_054.unk_00 = 0;
        *(s16 *)((u8 *)node + 0x56) = 0;
        node->unk_054.unk_04 = NULL;
        node->unk_054.unk_08 = 0;
        node->unk_054.unk_0A = 0;
        GeoNode_Init((S1_GraphNode *)node, 0x16);
        node->unk_000.unk_02 |= 0x60;
    }
    return storage;
}

void *func_8003899C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    if (arg0 != 0) {
        arg1 = (s32) MainPool_AllocAligned((void *) arg0, sizeof(S1_unk_D_86002F34_alt8), 4);
    }
    if (arg1 != 0) {
        ((S1_unk_D_86002F34_alt8 *) arg1)->unk_18 = (Gfx *) arg3;
        if (arg4 == NULL) {
            MtxF_Identity((f32 *) &((S1_unk_D_86002F34_alt8 *) arg1)->unk_1C);
        } else {
            MtxF_Copy((u32 *) &((S1_unk_D_86002F34_alt8 *) arg1)->unk_1C, (u32 *) arg4);
        }
        GeoNode_Init((S1_GraphNode *) arg1, 0x17);
        ((S1_unk_D_86002F34_alt8 *) arg1)->unk_00.unk_03 = (u8) arg2;
    }
    return (void *) arg1;
}

void *GeoNode_CreateDisplayListMatrixFromTransform(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    f32 temp[4][4];
    MtxF_SetRotationTranslationF(temp, (Vec3f35784 *)arg4, (Vec3s35AA0 *)arg5);
    func_8003899C(arg0, arg1, arg2, arg3, temp);
}

S1_unk_D_86002F34_alt9* GeoNode_CreateScale(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt9* arg1, s32 arg2, Gfx* arg3, S1_Vec3f* arg4,
                                   f32 arg5) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt9), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = *arg4;
        arg1->unk_28 = arg5;
        arg1->unk_18 = arg3;
        GeoNode_Init(arg1, 0x18);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

S1_unk_func_80011B94* GeoNode_CreateDisplayList(S1_MainPoolState* arg0, S1_unk_func_80011B94* arg1, s32 arg2, Gfx* arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_func_80011B94), 4);
    }

    if (arg1 != NULL) {
        arg1->displayList = arg3;
        GeoNode_Init(arg1, 0x19);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

S1_unk_D_86002F34_alt10* GeoNode_CreateShadowTexture(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt10* arg1, s16 arg2, s16 arg3, Gfx* arg4,
                                    s16 arg5, s16 arg6, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt10), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_22 = arg2;
        arg1->unk_20 = arg3;
        arg1->unk_18 = arg4;
        arg1->unk_1C = arg5;
        arg1->unk_1E = arg6;
        arg1->unk_24.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0x1A);
    }

    return arg1;
}

S1_unk_D_86002F34_alt23* GeoNode_CreateAnchor(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt23* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt23), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 0x1B);
    }

    return arg1;
}

S1_unk_D_86002F34_alt24* GeoNode_CreateGroup(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt24* arg1, s32 arg2, s16 arg3, s16 arg4,
                                    s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt24), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = arg3;
        arg1->unk_1E = arg4;
        arg1->unk_20 = arg5;
        arg1->unk_22 = arg6;
        arg1->unk_18 = arg7;
        arg1->unk_1A = arg8;
        arg1->unk_24 = arg9;
        arg1->unk_28.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0x1C);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

void GeoCamera_SetViewport(S1_unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_18.x = arg1;
    arg0->unk_18.y = arg2;
    arg0->unk_18.width = arg3;
    arg0->unk_18.height = arg4;

    arg0->unk_40.l = -arg3 * 0.5f;
    arg0->unk_40.r = arg3 * 0.5f;
    arg0->unk_40.t = arg4 * 0.5f;
    arg0->unk_40.b = -arg4 * 0.5f;
    arg0->unk_40.n = -2.0f;
    arg0->unk_40.f = 2.0f;
    arg0->unk_40.scale = 1.0f;
}

void GeoCamera_SetPerspective(S1_unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_24.aspect = (f32)arg0->unk_18.width / arg0->unk_18.height;
    arg0->unk_24.fovy = arg1;
    arg0->unk_24.near = arg2;
    arg0->unk_24.far = arg3;
    arg0->unk_24.scale = 1.0f;
}

void func_80038E14(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u16 arg7) {
    f32 inv = (f32)(-1.0 / sqrtf((arg4 - arg1) * (arg4 - arg1) + (arg6 - arg3) * (arg6 - arg3)));
    f32 sx = (arg4 - arg1) * inv;
    f32 sz = (arg6 - arg3) * inv;
    u8 *ptr = (u8 *)arg0 + 0x60;
    Vec3f_SetComponentsDuplicate((void *)((u8 *)arg0 + 0xA8), arg1, arg2, arg3);
    Vec3f_SetComponentsDuplicate((void *)(ptr + 0x54), arg4, arg5, arg6);
    Vec3f_SetComponentsDuplicate((void *)(ptr + 0x60), D_80087E50[arg7 >> 4] * sz, D_80088E50[arg7 >> 4], -D_80087E50[arg7 >> 4] * sx);
}

void GeoCamera_SetBackground(S1_unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5) {
    S1_unk_D_86002F34_00C_0CC* ptr = &arg0->unk_CC;

    if (arg2 < 2) {
        if ((arg1 == 2) || (arg1 == 4)) {
            ptr->unk_00 = 0;
        } else {
            ptr->unk_00 = 1;
        }
    } else {
        ptr->unk_00 = arg1;
        ptr->unk_08 = arg2;
        ptr->unk_0A = 1;
        ptr->color.r = arg3;
        ptr->color.g = arg4;
        ptr->color.b = arg5;
    }
}

void func_80038F8C(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v1;

    if ((arg0 != NULL) && (arg1 != NULL)) {
        temp_v0 = (*(void **)((u8 *)(arg0) + (0xC)));
        if (temp_v0 == NULL) {
            (*(void **)((u8 *)(arg0) + (0xC))) = arg1;
            (*(void **)((u8 *)(arg1) + (4))) = arg1;
            (*(void **)((u8 *)(arg1) + (8))) = arg1;
            return;
        }
        temp_v1 = (*(void **)((u8 *)(temp_v0) + (4)));
        (*(void **)((u8 *)(arg1) + (8))) = temp_v0;
        (*(void **)((u8 *)(arg1) + (4))) = temp_v1;
        (*(void **)((u8 *)(temp_v0) + (4))) = arg1;
        (*(void **)((u8 *)(temp_v1) + (8))) = arg1;
    }
}

void GraphNode_RemoveChild(GraphNode38FD4 *root, GraphNodeLink *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if (node == root->child) {
        if (node == node->next) {
            root->child = NULL;
        } else {
            root->child = node->next;
        }
    }
}

unk_func_80039018 *func_80039018(unk_func_80039018 *arg0, s32 arg1) {
    unk_func_80039018 *var_v1 = arg0->unk_0C;
    s32 var_v0;

    if (var_v1 != NULL) {
        for (var_v0 = 0; var_v0 < arg1; var_v0++) {
            var_v1 = var_v1->unk_08;
        }
    }
    return var_v1;
}

#endif
