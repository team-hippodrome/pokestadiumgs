#include "229E0.h"

#ifdef VERSION_US

void func_8003CA30(Gfx* arg0, S1_arg1_func_81407874_014_000_010* arg1) {
    gDPSetCombine(arg0++,
                  GCCc0w0(arg1->unk_00, arg1->unk_02, arg1->unk_04, arg1->unk_06) | GCCc1w0(arg1->unk_08, arg1->unk_0A),

                  GCCc0w1(arg1->unk_01, arg1->unk_03, arg1->unk_05, arg1->unk_07) |
                      GCCc1w1(arg1->unk_09, arg1->unk_0C, arg1->unk_0E, arg1->unk_0B, arg1->unk_0D, arg1->unk_0F));
}

void func_8003CB3C(Gfx *arg0, u8 arg1, u8 arg2) {
    S1_arg1_func_81407874_014_000_010 local;
    local = D_80094AAC[arg1];
    if (arg2 == 0xFF) {
        local.unk_0C = 7; local.unk_0D = 7; local.unk_0E = 7; local.unk_0F = 0;
    }
    func_8003CA30(arg0, &local);
}

void func_8003CBD4(void) {
    Gfx *command;
    if (D_801261A8 == 0) {
        D_801261A8 = 1;
        command = D_800D0510++;
        command->words.w1 = 0;
        command->words.w0 = 0xE7000000;
    }
}

void GeoRender_SetRenderMode(void) {
    s32 mode = D_800949A4[D_801261A0][((SceneMaterialState *)D_801263A8)->unknown24];
    D_801261A8 = 1;
    gDPPipeSync(D_800D0510++);
    ((SceneMaterialState *)D_801263A8)->fogColor.rgba = 0;
    gDPSetColor(D_800D0510++, G_SETFOGCOLOR, D_80094910->unknown20);
    if ((D_801261A4 & 1) && D_801261A0 == 1 && (((SceneMaterialState *)D_801263A8)->unknown24 == 6 || ((SceneMaterialState *)D_801263A8)->unknown24 == 8)) {
        mode = 0x107A58;
    }
    if (D_80094910->unknown1D != 0) {
        gDPSetRenderMode(D_800D0510++, mode, 0xC8000000);
    } else {
        gDPSetRenderMode(D_800D0510++, mode, 0x0C080000);
    }
}

s32 func_8003CD58(s32 arg0) { s32 var_v1; if ((arg0 != 0) && (arg0 != 5) && (arg0 != 0xA)) { var_v1 = 0; } else { var_v1 = 1; } return var_v1; }

void GeoRender_ApplyMaterialState(void) {
    S1_Color_RGBA8_u32 color;
    color.rgba = ((SceneMaterialState *)D_801263A8)->primitiveColor.rgba;
    ((SceneMaterialState *)D_801263A8)->unknown18 = NULL;
    ((SceneMaterialState *)D_801263A8)->unknown1C = NULL;
    ((SceneMaterialState *)D_801263A8)->unknown0C = NULL;
    ((SceneMaterialState *)D_801263A8)->unknown27 = 0;
    D_801261A8 = 1;
    gDPPipeSync(D_800D0510++);
    gDPSetPrimColor(D_800D0510++, 0, ((SceneMaterialState *)D_801263A8)->primitiveLevel, color.r, color.g, color.b, color.a);
    gDPSetTextureLUT(D_800D0510++, G_TT_NONE);
    if (func_8003CD58(((SceneMaterialState *)D_801263A8)->combineMode) != 0) {
        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    } else {
        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
    func_8003CB3C(D_800D0510++, ((SceneMaterialState *)D_801263A8)->combineMode, ((SceneMaterialState *)D_801263A8)->primitiveLevel);
    gSPSetGeometryMode(D_800D0510++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPClearGeometryMode(D_800D0510++, G_FOG | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPLookAt(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.lookat & 0x1FFFFFFF);
    if (D_80094910->unknown1D != 0) {
        gSPSetGeometryMode(D_800D0510++, G_FOG);
    }
}

void GeoRender_SetFogColor(SceneMaterialParameters *node) {
    if (node->fogColor.rgba != ((SceneMaterialState *)D_801263A8)->fogColor.rgba) {
        func_8003CBD4();
        gDPSetColor(D_800D0510++, G_SETFOGCOLOR, node->fogColor.rgba);
        gDPSetRenderMode(D_800D0510++, D_800949A4[D_801261A0][((SceneMaterialState *)D_801263A8)->unknown24], 0xC4000000);
        ((SceneMaterialState *)D_801263A8)->fogColor.rgba = node->fogColor.rgba;
    }
}

void GeoRender_RestoreRenderMode(s32 arg0) {
    if ((*(s32 *)((u8 *)(D_801263A8) + (0x14))) & 0xFF) {
        GeoRender_SetRenderMode();
    }
}

void GeoRender_SetPrimitiveColor(ScenePrimitiveColor *node) {
    if (node->color.rgba != ((SceneMaterialState *)D_801263A8)->primitiveColor.rgba ||
        node->level != ((SceneMaterialState *)D_801263A8)->primitiveLevel) {
        func_8003CBD4();
        gDPSetPrimColor(D_800D0510++, 0, node->level, node->color.r, node->color.g,
                       node->color.b, node->color.a);
        ((SceneMaterialState *)D_801263A8)->primitiveColor.rgba = node->color.rgba;
        ((SceneMaterialState *)D_801263A8)->primitiveLevel = node->level;
    }
}

void func_8003D188(u8 *arg0) {
    if (((u8 *)D_801263A8)[0x25] != arg0[0]) {
        func_8003CBD4();
        func_8003CB3C(D_800D0510++, arg0[0], arg0[1]);
        ((u8 *)D_801263A8)[0x25] = arg0[0];
    }
}

void func_8003D1F8(s32 arg0) { if (func_8003CD58(((u8 *)D_801263A8)[0x25]) == 0) { Gfx *command = D_800D0510++; command->words.w0 = 0xD7000000; command->words.w1 = 0xFFFFFFFF; } *(s32 *)((u8 *)D_801263A8 + 0x18) = 0; *(s32 *)((u8 *)D_801263A8 + 0x1C) = 0; *(s32 *)((u8 *)D_801263A8 + 0x20) = 0; }

void GeoRender_BindTexture(SceneMaterialParameters *node) {
    SceneBoundTexture *texture;
    s32 imageSize;
    if (func_8003CD58(((SceneMaterialState *)D_801263A8)->combineMode)) {
        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
    if (node->texture != NULL && node->displayList != NULL) {
        if (node->texture != ((SceneMaterialState *)D_801263A8)->unknown18 || node->displayList != ((SceneMaterialState *)D_801263A8)->unknown20) {
            texture = node->texture;
            if (node->material != NULL) {
                gSPDisplayList(D_800D0510++, ((SceneBoundPalette *)node->material)->displayList);
            } else {
                gDPSetTextureLUT(D_800D0510++, G_TT_NONE);
            }
            if (texture->size == 0) {
                if ((texture->width % D_80094B9C[0]) == 0) {
                    gDPSetTextureImage(D_800D0510++, texture->format, G_IM_SIZ_16b, 1, texture->image);
                } else {
                    gDPSetTextureImage(D_800D0510++, texture->format, G_IM_SIZ_8b, texture->width >> 1, texture->image);
                }
            } else if ((texture->width % D_80094B9C[texture->size]) == 0) {
                if (texture->size == 3) {
                    imageSize = 3;
                } else {
                    imageSize = 2;
                }
                gDPSetTextureImage(D_800D0510++, texture->format, imageSize, 1, texture->image);
            } else {
                gDPSetTextureImage(D_800D0510++, texture->format, texture->size, texture->width, texture->image);
            }
            gSPDisplayList(D_800D0510++, node->displayList);
        }
        ((SceneMaterialState *)D_801263A8)->unknown18 = node->texture;
        ((SceneMaterialState *)D_801263A8)->unknown1C = node->material;
        ((SceneMaterialState *)D_801263A8)->unknown20 = node->displayList;
    }
}

void GeoRender_EnableTextureGeneration(SceneMaterialParameters *node) {
    void *texture;
    if (((SceneMaterialState *)D_801263A8)->unknown27 == 0) {
        texture = D_1000000;
        switch (node->textureVariant) {
        case 1:
            break;
        case 2:
            texture = D_10019D0;
            break;
        }
        gDPLoadTextureBlock(D_800D0510++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, 1);
        gSPTexture(D_800D0510++, 0x1194, 0x1194, 0, G_TX_RENDERTILE, G_ON);
        gSPSetGeometryMode(D_800D0510++, G_TEXTURE_GEN);
        gSPClearGeometryMode(D_800D0510++, G_TEXTURE_GEN_LINEAR);
        gDPSetCombineMode(D_800D0510++, G_CC_MODULATEIDECALA, G_CC_PASS2);
        ((SceneMaterialState *)D_801263A8)->unknown27 = 1;
    }
}

void GeoRender_SelectMaterialSlot(s16 slot) {
    if (slot == D_801263AC) {
        return;
    }
    ((SceneMaterialState *)D_801263A8)->unknown08 = D_800D0510;
    gSPBranchList(D_800D0510++, NULL);
    D_801263AC = slot;
    D_801263A8 = &D_801261C8[D_801263AC];
    if (((SceneMaterialState *)D_801263A8)->unknown04 == NULL) {
        ((SceneMaterialState *)D_801263A8)->unknown04 = D_800D0510;
    } else if (((SceneMaterialState *)D_801263A8)->unknown08 != NULL) {
        gSPBranchList((Gfx *)((SceneMaterialState *)D_801263A8)->unknown08, D_800D0510);
    }
}

void func_8003D7B8(s16 arg0) {
    if (((arg0 > 0) && (arg0 < 4)) || (arg0 == 0x84) || (arg0 == 7)) {
        D_801261B0.textureVariant = D_801261B0.unknown02;
        return;
    }
    D_801261B0.textureVariant = 0;
}

s16 func_8003D808(s16 arg0) {
    s16 value = arg0 & 0xF;
    s16 result = value;
    if (D_801261B1 < 0xFF) {
        switch (value) {
        case 1: result = 5; break;
        case 2: result = 7; break;
        case 3: result = 8; break;
        case 4: result = 6; break;
        }
    }
    return result;
}

void GeoRender_SubmitMaterial(s16 format, Mtx *matrix) {
    if (D_800949A0 != 0 && !(D_801261A4 & 2) && D_801261B0.level > 0) {
        func_8003D7B8(format);
        GeoRender_SelectMaterialSlot(func_8003D808(format));
        D_801261A8 = 0;
        if (((SceneMaterialState *)D_801263A8)->unknown00 == 0) {
            GeoRender_SetRenderMode();
            GeoRender_ApplyMaterialState();
            ((SceneMaterialState *)D_801263A8)->unknown00 = 1;
        }
        if (D_801261B0.fogColor.rgba & 0xFF) {
            GeoRender_SetFogColor((&D_801261B0));
        } else {
            GeoRender_RestoreRenderMode((s32)(&D_801261B0));
        }
        if (D_801261B0.textureVariant != 0) {
            GeoRender_EnableTextureGeneration((&D_801261B0));
        } else {
            if (((SceneMaterialState *)D_801263A8)->unknown27 == 1) {
                GeoRender_ApplyMaterialState();
            }
            if (func_8003CD58(D_801261B0.mode)) {
                func_8003D1F8((s32)(&D_801261B0));
            } else {
                GeoRender_BindTexture((&D_801261B0));
            }
            GeoRender_SetPrimitiveColor((ScenePrimitiveColor *)(&D_801261B0));
            func_8003D188((u8 *)(&D_801261B0));
        }
        if (matrix != ((SceneMaterialState *)D_801263A8)->unknown0C) {
            ((SceneMaterialState *)D_801263A8)->unknown0C = matrix;
            gSPMatrix(D_800D0510++, (u32)matrix & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
    }
}

void func_8003DA20(s32 arg0, s32 arg1) {
    if (D_800949A0 != 0 && !(D_801261A4 & 2) && D_801261B1 > 0) {
        if (arg0 != 0) {
            if ((u32)arg0 >= 0x81000000U && (u32)arg0 < 0x90000000U) {
                Gfx *command = D_800D0510++;
                command->words.w0 = 0xDE000000;
                command->words.w1 = Memmap_GetFragmentVaddr((Gfx **)arg0);
            } else {
                Gfx *command = D_800D0510++;
                command->words.w1 = arg0;
                command->words.w0 = 0xDE000000;
            }
        }
        if (arg1 != 0) GeoRender_ApplyMaterialState();
    }
}

void GeoRender_SetMaterialParams(S1_Color_RGBA8_u32 color, u8 level, u32 flags) {
    D_801261B0.fogColor.rgba = color.rgba;
    D_801261B0.level = level;
    D_801261B0.unknown02 = flags;
}

void GeoRender_SetMaterialTexture(s32 arg0, CandidateColor arg1, void *arg2, void *arg3, s32 arg4) {
    D_801261B0.mode = arg0;
    D_801261B0.primitiveColor.rgba = arg1.rgba;
    D_801261B0.texture = arg2;
    D_801261B0.material = arg3;
    D_801261B0.displayList = arg4;
}

void GeoRender_InitMaterialState(s32 mode, s32 flags) {
    s32 index;
    SceneMaterialState *entry = D_801261C8;
    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
    if (mode & 1) {
        gSPSetGeometryMode(D_800D0510++, G_ZBUFFER);
    } else {
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER);
    }
    for (index = 0; index < 12; index++, entry++) {
        entry->unknown04 = NULL;
        entry->unknown08 = NULL;
        entry->unknown00 = 0;
        entry->unknown0C = NULL;
        entry->primitiveColor.rgba = 0xFFFFFFFF;
        entry->fogColor.rgba = 0xFFFFFF00;
        entry->unknown18 = NULL;
        entry->unknown1C = NULL;
        entry->unknown20 = NULL;
        entry->unknown24 = index;
        entry->combineMode = 0;
        entry->unknown27 = 0;
        entry->primitiveLevel = 0xFF;
    }
    D_801261B0.mode = 0;
    D_801261B0.level = 0xFF;
    D_801261B0.unknown02 = 0;
    D_801261B0.textureVariant = 0;
    D_801261B0.primitiveColor.rgba = 0xFFFFFFFF;
    D_801261B0.fogColor.rgba = 0xFFFFFF00;
    D_801261B0.texture = NULL;
    D_801261B0.material = NULL;
    D_801261B0.displayList = NULL;
    D_801261A0 = mode;
    D_801261A4 = flags;
    D_801261C8[0].unknown04 = D_800D0510;
    D_801263AC = 0;
    D_801263A8 = D_801261C8;
    D_800949A0 = 1;
}

void GeoRender_FlushMaterialSlots(void) {
    s32 slot = 0;
    Gfx *branch;
    s32 next;
    GeoRender_SelectMaterialSlot(11);
    if (D_801261C8[0].unknown08 != NULL) {
        while (slot < 11) {
            next = slot + 1;
            branch = D_801261C8[slot].unknown08;
            slot++;
            while (D_801261C8[next].unknown04 == NULL) {
                next = slot + 1;
                slot++;
            }
            gSPBranchList(branch, D_801261C8[slot].unknown04);
        }
    }
    GeoRender_ApplyMaterialState();
    if (D_801261A0 & 1) {
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER);
    }
    D_800949A0 = 0;
}

#endif
