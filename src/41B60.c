#include "229E0.h"

#ifdef VERSION_US

void Model_AdjustTextureColors(SceneTextureModel *model, S1_arg1_func_80010CA8 adjustment) {
    s32 i;
    s32 j;
    SceneTextureData *texture = model->textures;
    ScenePaletteData *palette = model->palettes;
    for (i = 0; i < model->textureCount; i++, texture++) {
        if (texture != NULL && texture->texture != NULL && texture->mode == 0) {
            if (texture->type == 2) {
                u16 *pixel = texture->texture;
                for (j = 0; j < texture->numTexels; j++, pixel++) {
                    *pixel = Color_AdjustRGB5551(*pixel, adjustment);
                }
            } else if (texture->type == 3) {
                u32 *pixel = texture->texture;
                for (j = 0; j < texture->numTexels; j++, pixel++) {
                    *pixel = Color_AdjustRGBA8(*pixel, adjustment);
                }
            }
        }
    }
    for (i = 0; i < model->paletteCount; i++, palette++) {
        if (palette != NULL && palette->colors != NULL) {
            u16 *pixel = palette->colors;
            for (j = 0; j < palette->count; j++, pixel++) {
                *pixel = Color_AdjustRGB5551(*pixel, adjustment);
            }
        }
    }
}

void *func_80041130(void *arg0, void *arg1, s32 arg2, CandidateJpegHeader *arg3) {
    void *sp1C;
    s32 sp18;
    s32 result;
    sp18 = 0;
    if (arg1 == NULL) {
        sp18 = ((s32 *)arg0)[1];
        sp1C = MainPool_AllocAligned(arg0, arg3->size + 0x100, 0x10);
    } else {
        sp1C = arg1;
    }
    if (sp1C != NULL) {
            result = Jpeg_DecodeImage((u32)sp1C, arg3->size + 0x100, (u8 *)arg3 + arg3->offset);
        if (arg1 == NULL) {
            if (result == 0) {
                MainPool_ResetStateToOffset(arg0, sp18);
                sp1C = NULL;
            } else {
                MainPool_ResetStateToOffset(arg0, sp18 + result);
            }
        }
    }
    return sp1C;
}

u8 *func_800411F0(void *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    u8 *var_a1;
    u8 *sp1C;

    if (arg1 == NULL) {
        var_a1 = MainPool_AllocAligned(arg0, *(u32 *)((u8 *)arg3 + 0x10), 0x10);
    } else {
        var_a1 = arg1;
    }
    if (var_a1 != NULL) {
        sp1C = var_a1;
        Yay0_DecompressAndRelocate(arg3, var_a1);
    }
    return var_a1;
}

void *func_8004124C(void *arg0, void *arg1, s32 arg2, s32 arg3, u32 arg4) {
    void *var_a0;
    void *sp1C;

    if (arg1 == NULL) {
        var_a0 = MainPool_AllocAligned(arg0, arg4, 0x10);
    } else {
        var_a0 = arg1;
    }
    if (var_a0 != NULL) {
        sp1C = var_a0;
        Util_Memcpy(var_a0, arg2 + arg3, arg4 >> 2);
    }
    return var_a0;
}

s32 Fragment_LoadResourceFromRomRange(s32 pool, s32 destination, s32 start, s32 end, s32 buffer, s32 capacity) {
    u32 size = (end - start + 0xF) & ~0xF;
    s32 result = 0;
    u32 *header;
    if ((u32)capacity >= size) {
        header = (u32 *)buffer;
        func_80003F74((u8 *)buffer, (u8 *)start, (u8 *)end, 0);
        if (header[0] == 0x50455253 && header[1] == 0x2D535A50) {
            result = (s32)func_800411F0((void *)pool, (u8 *)destination, buffer, (u8 *)buffer);
        } else if (header[0] == 0x50524553 && header[1] == 0x4A504547) {
            result = (s32)func_80041130((void *)pool, (void *)destination, buffer, (CandidateJpegHeader *)buffer);
        } else {
            result = (s32)func_8004124C((void *)pool, (void *)destination, buffer, 0, size);
        }
    }
    return result;
}

void func_800413A0(S1_MainPoolState* arg0, u32 arg1, S1_Fragment* arg2) {
    Memmap_RelocateFragment(arg1, arg2);
    MainPool_ResetStateToOffset(arg0, ((u32)arg2 + arg2->sizeInRam) - (u32)arg0->listHeadR);
}

s32 func_800413E8(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5) {
    s32 sum1 = arg3[0] + arg2[1];
    s32 sum2 = sum1 + arg3[1];
    return Fragment_LoadResourceFromRomRange(arg0, arg1, sum1, sum2, arg4, arg5);
}

s32 func_80041430(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 base = arg2;
    s32 result = 0;
    s32 *entry;
    if ((u32)arg3 < *(u32 *)((u8 *)base + 0xC)) {
        if (*(u16 *)base & 1) {
            result = (arg2 += *(s32 *)((u8 *)base + arg3 * 0x10 + 0x10));
        } else {
            if (!(*(u16 *)base & 4)) {
                if (*(s32 *)((u8 *)base + arg3 * 0x10 + 0x18) != 0) {
                    result = *(s32 *)((u8 *)base + arg3 * 0x10 + 0x18);
                    goto done;
                }
            }
            entry = (s32 *)((u8 *)base + arg3 * 0x10 + 0x10);
            result = func_800413E8(arg0, arg1, (s32 *)base, entry, arg4, arg5);
            if (result != 0 && arg1 == 0) {
                if (*(s32 *)(result + 8) == 0x46524147 && *(s32 *)(result + 12) == 0x4D454E54) {
                    func_800413A0((S1_MainPoolState *)arg0, *(u16 *)((u8 *)base + 2), (S1_Fragment *)result);
                }
                entry[2] = result;
            }
        }
    }
done:
    return result;
}

SceneProcessedModel *Fragment_ProcessGeoLayout(pool, entry, adjustment, format, special)
S1_MemoryBlock *pool;
SceneModelEntry entry;
S1_arg1_func_80010CA8 adjustment;
u8 format;
s32 special;
{
    SceneProcessedModel *model;
    s32 i;
    model = entry(0, 0);
    model->entry = entry;
    for (i = 0; i < model->geometryCount; i++) {
        SceneGeometryNode *node;
        node = process_geo_layout(pool, model->geometry[i]);
        if (node->node.unk_00 == 14) {
            node->entry = entry;
            if (adjustment.raw != 0) {
                Model_AdjustTextureColors((SceneTextureModel *)node, adjustment);
            }
        }
        model->geometry[i] = node;
    }
    model->format = format & 0xF;
    if (special != 0) {
        model->format |= 0x80;
    }
    return model;
}

void Fragment_ProcessGeoLayoutList(S1_MemoryBlock* arg0, S1_arg1_func_80019420* arg1) {
    while (arg1->unk_00) {
        if (arg1->unk_00 == 3) {
            arg1->unk_04 = process_geo_layout(arg0, arg1->unk_04);
        }

        arg1++;
    }
}

void func_800416C8(SceneWorkerMessageLoad *message) {
    s32 fragment;
    s32 buffer;
    S1_MemoryBlock *pool;
    s32 used;

    buffer = message->buffer;
    pool = (S1_MemoryBlock *)MainPool_InitState(message->destination, message->size);
    fragment = func_80041430((s32)pool, 0, *(s32 *)((u8 *)&D_80126530 + 0x9E8), message->id,
                             *(s32 *)((u8 *)&D_80126530 + 0x9FC), 0xF000);
    if (fragment != 0) {
        message->data = Fragment_ProcessGeoLayout(pool, fragment, message->adjustment, buffer, message->variant);
    } else {
        message->data = NULL;
    }
    used = pool->size;
    message->size = (used + 1039) & ~0x3FF;
    MainPool_FinalizeAllocation(pool);
}

void PokeIcon_LoadResourceList(SceneWorkerMessage *message) {
    s32 fragment;
    S1_MemoryBlock *pool;
    s32 count = 0;
    S1_arg1_func_80019420 **output = message->data;
    s16 *ids;
    pool = (S1_MemoryBlock *)MainPool_InitState(message->destination, message->size);
    ids = (s16 *)message->source;
    while (*ids != -1) {
        fragment = func_80041430((s32)pool, 0, *(s32 *)((u8 *)&D_80126530 + 0x9F4), *ids,
                                 *(s32 *)((u8 *)&D_80126530 + 0x9FC), 0xF000);
        if (fragment == 0) {
            break;
        }
        output[count] = (S1_arg1_func_80019420 *)(fragment + 0x20);
        Fragment_ProcessGeoLayoutList(pool, (S1_arg1_func_80019420 *)(fragment + 0x20));
        ids++;
        count++;
    }
    output[count] = NULL;
    message->size = pool->size + 0x10;
}

/* mkdraft:func_8004186C begin */
extern s32 D_80126F1C;

// Fragment structure reached through the offset in fragment[0]; its words at
// +0xC..+0x18 are fragment-relative offsets that are converted to addresses
// after func_80041430 returns the fragment.
typedef struct unk_func_8004186C {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} unk_func_8004186C;



void func_8004186C(void *arg0)
{
    u8 *base;
    u8 *table;
    u8 *temp;
    S1_MemoryBlock *pool;
    u8 *record;
    unk_func_8004186C *result;
    u8 *aligned;
    u8 *node;
    s32 *fragment;
    s32 count;
    s32 size;
    s32 used;
    // func_80041A78 receives an OSMesg and passes it through this void*
    // parameter; name the SceneWorkerMessage layout for the field accesses.
    SceneWorkerMessage *message = (SceneWorkerMessage *)arg0;

    base = (u8 *)D_80126F1C;
    table = ((u8 (*)[0x10])base)[message->id] + 0x10;
    pool = (S1_MemoryBlock *)MainPool_InitState(message->destination, message->size);
    result = NULL;
    temp = Util_Malloc(47);
    if (temp != NULL) {
        record = (u8 *)(*(s32 *)table + *(s32 *)(base + 4));
        aligned = (u8 *)(((u32)temp + 0xF) & ~0xF);
        func_80003F74(aligned, record, record + 0x20, 0);
        count = *(s32 *)(aligned + 0xC);
        Util_Free(temp);
        size = count << 4;
        node = MainPool_AllocAligned(pool, size + 0x10, 0x10);
        if (node != NULL) {
            func_80003F74(node, record, record + size + 0x10, 0);
            *(u32 *)(node + 4) = (u32)record;
            *(u16 *)(node + 0) |= 2;
            *(u16 *)(node + 0) |= 4;
            fragment = (s32 *)func_80041430((s32)pool, 0, (s32)node, message->buffer,
                                            D_80126F2C, 0xF000);
            if (fragment != NULL) {
                result = (unk_func_8004186C *)((u8 *)fragment + fragment[0]);
                result->unk_0C = (s32)fragment + result->unk_0C;
                result->unk_10 = (s32)fragment + result->unk_10;
                result->unk_14 = (s32)fragment + result->unk_14;
                result->unk_18 = (s32)fragment + result->unk_18;
            }
        }
    }
    if (result != 0) {
        message->data = result;
    } else {
        message->data = NULL;
    }
    used = pool->size;
    message->size = (used + 1055) & ~0x3FF;
    MainPool_FinalizeAllocation(pool);
}
/* mkdraft:func_8004186C end */

void func_80041A18(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_80041430(0, (*(s32 *)((u8 *)(arg0) + (0x14))), (*(s32 *)((u8 *)(&D_80126530) + (0x9F8))), (*(s16 *)((u8 *)(arg0) + (2))), (*(s32 *)((u8 *)(&D_80126530) + (0x9FC))), 0xF000);
    if (temp_v0 != 0) {
        (*(s32 *)((u8 *)(arg0) + (0xC))) = temp_v0;
        return;
    }
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
}

void func_80041A78(void *arg0) {
    OSMesg msg;
    OSMesgQueue *queue;
    queue = &D_80126F00;
    __osSetFpcCsr(0x1000C01);
    for (;;) {
        osRecvMesg(queue, &msg, 1);
        switch (*(s16 *)msg) {
        case 1: func_800416C8(msg); break;
        case 2: PokeIcon_LoadResourceList(msg); break;
        case 4: func_8004186C(msg); break;
        case 8: func_80041A18(msg); break;
        }
        if (*(OSMesgQueue **)((u8 *)msg + 8) != NULL) {
            osSendMesg(*(OSMesgQueue **)((u8 *)msg + 8), msg, 1);
        }
    }
}

void func_80041B84(void) {
    osCreateMesgQueue(&D_80126F00, &D_80126EE0, 8);
    osCreateThread(&D_80126530, 7, func_80041A78, NULL, &D_80126EE0, 0xA);
    osStartThread(&D_80126530);
}

void PokeIcon_InitLoadContext(SceneLoadContext *context, s32 flags, s32 modelBufferSize) {
    context->flags = flags;
    context->pending = 0;
    context->variant = 0;
    context->bufferCount = 0;
    context->loadedModel = NULL;
    context->modelBuffers[0] = NULL;
    context->modelBuffers[1] = NULL;
    context->backgroundBuffer = NULL;
    context->animationBuffers[0] = NULL;
    context->animationBuffers[1] = NULL;
    context->modelBufferSize = modelBufferSize;
    context->animationBufferSizes[0] = 0;
    context->animationBufferSizes[1] = 0;
    context->colorAdjust.raw = 0;
    context->species = 0;
    osCreateMesgQueue(&context->queues[0].queue, context->queues[0].messages, 2);
    osCreateMesgQueue(&context->queues[1].queue, context->queues[1].messages, 2);
    osCreateMesgQueue(&context->queues[2].queue, context->queues[2].messages, 2);
    osCreateMesgQueue(&context->queues[3].queue, context->queues[3].messages, 2);
}

SceneLoadContext *PokeIcon_AllocLoadContext(u32 flags) {
    SceneLoadContext *context = (SceneLoadContext *)main_pool_alloc(sizeof(SceneLoadContext), 1);
    s32 doubleBuffered;
    if (context != NULL) {
        PokeIcon_InitLoadContext(context, flags, 0x26000);
        if (flags & 1) {
            context->modelBuffers[0] = (void *)main_pool_alloc(0x26000, 1);
            if (flags & 4) {
                context->modelBuffers[1] = (void *)main_pool_alloc(0x26000, 1);
            }
        }
        if (flags & 2) {
            context->backgroundBuffer = (void *)main_pool_alloc(0x18000, 1);
        }
        if (flags & 0x10) {
            doubleBuffered = flags & 4;
            context->imageBuffers[0] = (void *)main_pool_alloc(0x25C00, 1);
            if (doubleBuffered) {
                context->imageBuffers[1] = (void *)main_pool_alloc(0x25C00, 1);
            }
        }
    }
    return context;
}

SceneLoadContext *PokeIcon_AllocSpecialModelContext(u16 modelId) {
    SceneLoadContext *context = NULL;
    s32 capacity = 0;
    switch (modelId) {
    case 0xFC:
        capacity = 0xF000;
        break;
    case 0x118:
        capacity = 0x4C00;
        break;
    }
    if (capacity != 0) {
        context = (SceneLoadContext *)main_pool_alloc(sizeof(SceneLoadContext), 1);
    }
    if (context != NULL) {
        PokeIcon_InitLoadContext(context, 1, capacity);
        context->bufferCount = 1;
        context->modelBuffers[0] = (void *)main_pool_alloc(capacity, 1);
    }
    return context;
}

void PokeIcon_InitResourceArchives(void) {
    *(s32 *)((u8 *)&D_80126530 + 0x9e8) = BinArchive_Open(func_800356CC(6), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9f4) = BinArchive_Open(func_800356CC(5), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9ec) = BinArchive_Open(func_800356CC(7), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9f0) = BinArchive_Open(func_800356CC(14), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9F8) = 0;
    *(s32 *)((u8 *)&D_80126530 + 0x9FC) = main_pool_alloc(0xF000, 1);
    Fragment_Load(((((u32)D_81000000 & 0x0FF00000) >> 20) - 0x10), fragment26_ROM_START, fragment27_ROM_START);
}

void func_80041F14(void) {
    D_80126F28 = BinArchive_Open(func_800356CC(8), 0, 1, 1);
    D_80126F2C = main_pool_alloc(0xF000, 1);
}

s32 func_80041F60(s16 *arg0) {
    s16 *ptr = D_8009F428;
    s32 result = 0;
    while (*ptr != -1) {
        if (ptr == arg0) {
            result = 1;
        }
        ptr++;
    }
    return result;
}

void func_80041FA0(s32 arg0, u16 arg1, Func80041FA0State arg2) {
    func_80041FD0(arg0, arg1, arg2, 0);
}

/* mkdraft:func_80041FD0 begin */
extern s32 func_8004B98C(s32);
typedef struct Result_8004B9E0 {
    s32 value;
} Result_8004B9E0;
extern Result_8004B9E0 func_8004B9E0(s32);



s32 func_80041FD0(s32 arg0, u16 arg1, Func80041FA0State arg2, s32 arg3) {
    s32 result = 0;
    SceneLoadResult *msg;
    s32 slot;

    if (((u8 *)arg0)[3] != 0 && arg1 != 0xFC && ((s32)arg1) != 0x118) {
        return 0;
    }
    if ((((u8 *)arg0)[0] & 1) && !(((u8 *)arg0)[1] & 1)) {
        msg = Util_Malloc(0x20);
        if (msg != NULL) {
            slot = ((u8 *)arg0)[2];
            if (((u8 *)arg0)[0] & 4) {
                slot ^= 1;
            }
            msg->kind = 1;
            msg->id = ((s32)arg1);
            msg->buffer = slot;
            if (arg3 != 0) {
                msg->variant = func_8004B98C(((s32)arg1));
            } else {
                msg->variant = 0;
            }
            msg->reply = (OSMesgQueue *)(arg0 + 0x50);
            msg->data = NULL;
            msg->source = 0;
            msg->destination = (void *)(*(s32 *)(((u8 (*)[4])arg0)[slot] + 4));
            msg->size = *(s32 *)((u8 *)arg0 + 0x20);
            switch (msg->variant) {
            case 1:
                msg->adjustment.raw = 0;
                break;
            case 2:
                *(Result_8004B9E0 *)&msg->adjustment = func_8004B9E0(((s32)arg1));
                break;
            default:
                *(Func80041FA0State *)&msg->adjustment = arg2;
                break;
            }
            if (*(u8 **)((u8 *)arg0 + 0x38) != NULL &&
                *(u16 *)*(u8 **)((u8 *)arg0 + 0x38) == ((s32)arg1) &&
                msg->adjustment.raw == *(s32 *)((u8 *)arg0 + 0x48) &&
                msg->variant == *(s16 *)((u8 *)arg0 + 0x4C) &&
                func_80041F60((s16 *)(u32)((s32)arg1)) == 0) {
                osSendMesg(msg->reply, (OSMesg)msg, 1);
            } else {
                *(s32 *)(((u8 (*)[4])arg0)[slot] + 0x10) = 0;
                *(s32 *)(((u8 (*)[4])arg0)[slot] + 0x24) = 0;
                osSendMesg(&D_80126F00, (OSMesg)msg, 1);
            }
            ((u8 *)arg0)[1] |= 1;
            result = 1;
        }
    }
    return result;
}
/* mkdraft:func_80041FD0 end */

s32 func_800421E0(u8 *arg0, s32 arg1, s32 arg2) {
    s32 result = 0;
    u8 *msg;
    if ((arg0[0] & 2) != 0) {
        if ((arg0[1] & 2) == 0) {
            msg = Util_Malloc(0x20);
            if (msg != NULL) {
                *(s16 *)(msg + 0) = 2;
                *(s16 *)(msg + 2) = 0;
                *(s16 *)(msg + 4) = 0;
                msg[6] = 0;
                *(void **)(msg + 8) = arg0 + 0x70;
                *(s32 *)(msg + 0xC) = arg2;
                *(s32 *)(msg + 0x10) = arg1;
                *(s32 *)(msg + 0x14) = *(s32 *)(arg0 + 0xC);
                *(s32 *)(msg + 0x18) = 0x18000;
                osSendMesg(&D_80126F00, (OSMesg)msg, 1);
                arg0[1] |= 2;
                result = 1;
            }
        }
    }
    return result;
}

s32 func_800422B4(u8 *arg0, s32 arg1, u16 arg2, u16 arg3) {
    s32 result = 0;
    u8 *msg;
    if ((arg0[0] & 1) && !(arg0[1] & 4) && arg1 < 2 && *(s32 *)(((u8 (*)[4])arg0)[arg1] + 0x10)) {
        msg = Util_Malloc(0x20);
        if (msg != NULL) {
            *(u16 *)(msg + 0) = 4;
            *(u16 *)(msg + 2) = arg2;
            *(u16 *)(msg + 4) = arg3;
            msg[6] = 0;
            *(void **)(msg + 8) = arg0 + 0x90;
            *(s32 *)(msg + 0xC) = 0;
            *(s32 *)(msg + 0x10) = 0;
            *(s32 *)(msg + 0x14) = *(s32 *)(((u8 (*)[4])arg0)[arg1] + 0x10);
            *(s32 *)(msg + 0x18) = *(s32 *)(((u8 (*)[4])arg0)[arg1] + 0x24);
            osSendMesg(&D_80126F00, msg, 1);
            arg0[1] |= 4;
            result = 1;
        }
    }
    return result;
}

s32 func_8004239C(u8 *arg0, s32 arg1) {
    s32 result = 0;
    u8 *msg;
    s32 index;
    u32 base;
    if ((arg0[0] & 0x10) && !(arg0[1] & 8)) {
        msg = Util_Malloc(0x20);
        if (msg != NULL) {
            index = arg0[2];
            if (arg0[0] & 4) { index ^= 1; }
            *(u16 *)(msg + 0) = 8;
            *(u16 *)(msg + 2) = arg1;
            *(u16 *)(msg + 4) = index;
            msg[6] = 0;
            base = (u32)arg0 + 0xB0;
            *(void **)(msg + 8) = (void *)base;
            *(s32 *)(msg + 0xC) = 0;
            *(s32 *)(msg + 0x10) = 0;
            *(s32 *)(msg + 0x14) = *(s32 *)((u8 *)arg0 + (index << 2) + 0x18);
            *(s32 *)(msg + 0x18) = 0x25C00;
            osSendMesg(&D_80126F00, msg, 1);
            arg0[1] |= 8;
            result = 1;
        }
    }
    return result;
}

u32 Model_FindLowestTextureAddress(SceneTextureModel *model) {
    u32 result = 0;
    s32 count;
    u32 minimum;
    s32 i;
    SceneTextureData *entry;
    if (model->node.unk_00 == 14) {
        count = model->textureCount;
        minimum = 0xFFFFFFFF;
        for (i = 0; i < count; i++) {
            entry = &model->textures[i];
            if (entry->texture != NULL) {
                if ((u32)entry->texture < minimum) {
                    minimum = (u32)entry->texture;
                }
            }
        }
        if (minimum != 0xFFFFFFFF) {
            result = minimum;
        }
    }
    return result;
}

s32 PokeIcon_ApplyResourceLoadResult(SceneLoadContext *context, SceneLoadResult *message) {
    s32 result = 0;
    switch (message->kind) {
    case 1:
        context->pending &= ~1;
        if (message->data != NULL) {
            s32 buffer;
            buffer = message->buffer;
            if (context->flags & 4) {
                context->variant ^= 1;
            }
            context->loadedModel = message->data;
            context->modelSize = message->size;
            context->colorAdjust = message->adjustment;
            context->species = message->variant;
            if (message->variant == 1) {
                u32 address;
                address = Model_FindLowestTextureAddress(((SceneProcessedModel *)context->loadedModel)->geometry[0]);
                if (address != 0) {
                    func_80041430(0, address, *(s32 *)((u8 *)&D_80126530 + 0x9F0), message->id,
                                  *(s32 *)((u8 *)&D_80126530 + 0x9FC), 0xF000);
                }
            }
            context->animationBuffers[buffer] = (u8 *)context->modelBuffers[buffer] + context->modelSize;
            if ((u32)context->animationBuffers[buffer] < (u32)context->modelBuffers[buffer] + context->modelBufferSize) {
                context->animationBufferSizes[buffer] = context->modelBufferSize - context->modelSize;
                result = 1;
                break;
            } else {
                context->animationBuffers[buffer] = NULL;
                context->animationBufferSizes[buffer] = 0;
            }
        }
        result = 1;
        break;
    case 2:
        context->pending &= ~2;
        context->loadedBackground = message->data;
        context->backgroundSize = message->size;
        result = 1;
        break;
    case 4:
        context->pending &= ~4;
        if (message->data != NULL) {
            context->loadedCurve = message->data;
            context->curveSize = message->size;
        }
        result = 1;
        break;
    case 8:
        context->pending &= ~8;
        if (message->data != NULL) {
            if (context->flags & 4) {
                context->variant ^= 1;
            }
            context->unknown44 = (u32)message->data;
        }
        result = 1;
        break;
    }
    Util_Free(message);
    return result;
}

s32 func_800427B8(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x50), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

s32 func_80042808(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x70), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

s32 func_80042858(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x90), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

s32 func_800428A8(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0xB0), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

void func_800428F8(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x50), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

void PokeIcon_WaitBackgroundLoad(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x70), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

void func_80042968(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x90), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

void func_800429A0(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0xB0), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

extern void func_80041FA0(s32 arg0, u16 arg1, Func80041FA0State arg2);
extern s32 func_800422B4(u8 *arg0, s32 arg1, u16 arg2, u16 arg3);
extern void func_800428F8(s32 arg0);
extern void func_80042968(s32 arg0);
extern s32 func_80042ADC(u8 *arg0);
u8 *func_800429D8(s32 arg0, s32 arg1) {
    u8 *bank;
    Func80041FA0State state;
    s32 resource;
    s32 format;
    u16 id;

    resource = arg0;
    id = arg1;
    state.word = 0;
    if (!arg0) {} // FAKE
    func_80041FA0(resource, id, state);
    func_800428F8(resource);
    bank = *(u8 **)(resource + 0x38);
    if (bank != NULL && bank[4] > 0) {
        format = func_80042ADC(bank);
        if (format >= 0) {
            func_800422B4((u8 *)resource, format, id, 0);
            func_80042968(resource);
        }
    }
    return bank;
}

s32 func_80042A64(s32 arg0) { return 0; }

S1_arg1_func_80019420 *BattleAnim_LoadResourceTable(s32 arg0) {
    s32 sp24;
    S1_arg1_func_80019420 *sp20;
    S1_MemoryBlock *sp1C;
    sp20 = NULL;
    sp24 = (s32)func_80004B4C(D_80126F24, arg0);
    if (sp24 != 0) {
        sp1C = MainPool_AllocState(main_pool_get_available(), 0);
        sp20 = (S1_arg1_func_80019420 *)(sp24 + 0x20);
        Fragment_ProcessGeoLayoutList(sp1C, sp20);
        MainPool_FinalizeAllocation(sp1C);
    }
    return sp20;
}

s32 func_80042ADC(u8 *arg0) { s32 result = -1; if (arg0 != NULL) result = arg0[2] & 0xF; return result; }

#endif
