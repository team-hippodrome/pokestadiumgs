#include "229E0.h"

#ifdef VERSION_US

void func_80039070(s32 arg0) { *(s32 *)((u8 *)&D_80124F68 + 0x10A0) = 0; *((u8 *)&D_80124F68 + 0x1080) = 0; MtxF_Identity((f32 *)&D_80124F68); if (arg0 == 0) { *(s32 *)((u8 *)&D_80124F68 + 0x1000) = (s32)Gfx_AllocDisplayList(0x40); } else { *(s32 *)((u8 *)&D_80124F68 + 0x1000) = arg0; } MtxF_ToFixed((void *)*(s32 *)((u8 *)&D_80124F68 + 0x1000), (S1_MtxF *)&D_80124F68); }

void GeoRender_CommitMatrix(Mtx *fixed) {
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
}

Mtx *GeoRender_SetMatrix(S1_MtxF *matrix, Mtx *fixed) {
    MtxF_Copy((u32 *)(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]), (u32 *)matrix);
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
    return ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
}

void GeoRender_PushMultipliedMatrix(S1_MtxF *matrix, Mtx *fixed) {
    ((SceneTransformPool *)&D_80124F68)->top++;
    MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1]);
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
}

Mtx *GeoRender_PushScaledMatrix(S1_Vec3f *scale, Mtx *fixed) {
    ((SceneTransformPool *)&D_80124F68)->top++;
    MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1], scale);
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
    return ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
}

void *func_8003936C(s32 arg0) {
    void *var_v1;
    struct PoolBase {
        u8 pad[0x10A0];
        s32 count;
    };

    var_v1 = NULL;
    if (arg0 <= 0) {
        var_v1 = (void *)((u8 *)&D_80124F68 + (((struct PoolBase *)&D_80124F68)->count << 6) + (arg0 << 6));
    }
    return var_v1;
}

void *GeoRender_GetMatrix(s32 arg0) {
    void *var_v1;

    var_v1 = NULL;
    if ((arg0 >= 0) && (arg0 < 0x20)) {
        var_v1 = (arg0 << 6) + &D_80124F68;
    }
    return var_v1;
}

void GeoRender_ResetTransformStack(void) {
    struct Vec3Words {
        s32 x;
        s32 y;
        s32 z;
    };
    struct State {
        struct Vec3Words value;
        u8 pad[0x174];
        s32 flag;
    };

    ((struct State *)&D_80126010)->flag = 0;
    ((struct State *)&D_80126010)->value = *(struct Vec3Words *)D_800948E4;
}

void func_800393F0(S1_Vec3f *arg0) {
    S1_Vec3f *vec = (S1_Vec3f *)&D_80126010;
    s32 *counter = (s32 *)((u8 *)&D_80126010 + 0x180);
    vec[*counter + 1].x = vec[*counter].x * arg0->x;
    vec[*counter + 1].y = vec[*counter].y * arg0->y;
    vec[*counter + 1].z = vec[*counter].z * arg0->z;
    (*counter)++;
}

Vtx *GeoOverlay_BuildFadeQuad(S1_unk_D_86002F34_00C_0CC *overlay, S1_unk_D_86002F34_00C_040 *projection) {
    u8 alpha;
    Vtx *vertices;

    vertices = Gfx_AllocDisplayList(4 * sizeof(Vtx));
    if (vertices != NULL) {
        switch (overlay->unk_00) {
        case 1:
            alpha = 255;
            break;
        case 2:
            alpha = 255 - (overlay->unk_0A * 255) / overlay->unk_08;
            break;
        case 3:
            alpha = (overlay->unk_0A * 255) / overlay->unk_08;
            break;
        }
        Gfx_SetVertexAttributes(&vertices[0], (s16)projection->l, (s16)projection->t, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
        Gfx_SetVertexAttributes(&vertices[1], (s16)projection->l, (s16)projection->b, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
        Gfx_SetVertexAttributes(&vertices[2], (s16)projection->r, (s16)projection->b, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
        Gfx_SetVertexAttributes(&vertices[3], (s16)projection->r, (s16)projection->t, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
    }
    return vertices;
}

void GeoOverlay_DrawFadeQuad(S1_unk_D_86002F34_00C_0CC* arg0, S1_unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = GeoOverlay_BuildFadeQuad(arg0, arg1);

    if (temp_v0 != NULL) {
        gDPSetCombineMode(D_800D0510++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(D_800D0510++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

        gSPVertex(D_800D0510++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
    }

    if (arg0->unk_00 != 1) {
        arg0->unk_0A++;
        if (arg0->unk_0A == arg0->unk_08) {
            if (arg0->unk_00 == 2) {
                arg0->unk_00 = 0;
            } else {
                arg0->unk_00 = 1;
            }
        }
    }
}


void func_80039808(Vtx* arg0, S1_unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    f32 temp_fa0;
    f32 temp_fv1;
    u16 idx = arg1->unk_18;
    f32 a4;
    f32 a5;
    s16 tmp1;
    s16 tmp2;
    s16 x;
    s16 y;

    a4 = arg4;
    temp_fv1 = COSS(idx);
    temp_fa0 = SINS(idx);
    a5 = arg5;

    tmp1 = ((a4 * temp_fv1) - (temp_fa0 * a5));
    tmp2 = ((temp_fv1 * a5) + (a4 * temp_fa0));

    // FAKE: the write-backs to arg2/arg3 are dead, but they stop IDO from sinking
    // x and y into the call. That keeps their instructions on these earlier
    // lines, and as1's scheduler breaks the remaining tie by line number, which
    // gives the retail order of `sra a2` and the alpha store (same as Pokemon
    // Stadium's func_80012870).
    x = tmp1 + arg2;
    arg2 = x;
    y = tmp2 + arg3;
    arg3 = y;

    Gfx_SetVertexAttributes(arg0, x, y, -1, arg6 * 32, arg7 * 32, arg1->color.r, arg1->color.g, arg1->color.b, 0xFF);
}

Vtx *func_800398F8(S1_unk_D_86002F34_00C_0CC *arg0) {
    Vtx *out = (Vtx *)Gfx_AllocDisplayList(0x80); Vtx *p; s16 x,y,z,nz;
    if (out) {
        x=arg0->unk_10+((arg0->unk_14-arg0->unk_10)*arg0->unk_0A)/arg0->unk_08; y=arg0->unk_12+((arg0->unk_16-arg0->unk_12)*arg0->unk_0A)/arg0->unk_08; z=arg0->unk_0C+((arg0->unk_0E-arg0->unk_0C)*arg0->unk_0A)/arg0->unk_08; nz=-z; p=out;
        if(arg0->unk_00==2){func_80039808(p++,arg0,x,y,nz,nz,-31,63);func_80039808(p++,arg0,x,y,z,nz,31,63);func_80039808(p++,arg0,x,y,z,z,31,0);func_80039808(p++,arg0,x,y,nz,z,-31,0);}else{func_80039808(p++,arg0,x,y,nz,nz,0,63);func_80039808(p++,arg0,x,y,z,nz,63,63);func_80039808(p++,arg0,x,y,z,z,63,0);func_80039808(p++,arg0,x,y,nz,z,0,0);}
        func_80039808(p++,arg0,x,y,-2000,-2000,0,0);func_80039808(p++,arg0,x,y,2000,-2000,0,0);func_80039808(p++,arg0,x,y,2000,2000,0,0);func_80039808(p,arg0,x,y,-2000,2000,0,0);
    } arg0->unk_18+=arg0->unk_1A; return out;
}

void GeoOverlay_DrawRotatingQuad(S1_unk_D_86002F34_00C_0CC* arg0, UNUSED S1_unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = func_800398F8(arg0);

    if (temp_v0 != 0) {
        gDPSetCombineMode(D_800D0510++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(D_800D0510++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

        gSPVertex(D_800D0510++, (u32)temp_v0 & 0x1FFFFFFF, 8, 0);
        gSP2Triangles(D_800D0510++, 0, 4, 1, 0, 1, 4, 5, 0);
        gSP2Triangles(D_800D0510++, 1, 5, 2, 0, 2, 5, 6, 0);
        gSP2Triangles(D_800D0510++, 2, 6, 7, 0, 2, 7, 3, 0);
        gSP2Triangles(D_800D0510++, 3, 4, 0, 0, 3, 7, 4, 0);

        gDPPipeSync(D_800D0510++);

        gDPSetCombineMode(D_800D0510++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
        gDPSetRenderMode(D_800D0510++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gDPSetTextureFilter(D_800D0510++, G_TF_BILERP);

        if (arg0->unk_02 == 0) {
            gDPLoadTextureBlock(D_800D0510++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPLoadTextureBlock(D_800D0510++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 64, 0,
                                G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
        }

        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        gSPVertex(D_800D0510++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);

        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetTextureFilter(D_800D0510++, G_TF_BILERP);
    }

    arg0->unk_0A++;
    if (arg0->unk_0A == arg0->unk_08) {
        if (arg0->unk_00 == 4) {
            arg0->unk_00 = 0;
        } else {
            arg0->unk_00 = 1;
        }
    }
}

void GeoOverlay_Draw(S1_unk_D_86002F34_00C_0CC* arg0, S1_unk_D_86002F34_00C_040* arg1) {
    if (arg0->unk_00 != 0) {
        gDPPipeSync(D_800D0510++);

        gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_LIGHTING);
        gSPPerspNormalize(D_800D0510++, 0xFFFF);
        gSPMatrix(D_800D0510++, (u32)arg1->mtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_800D0510++, (u32)&D_80094890 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if ((arg0->unk_00 == 1) || (arg0->unk_00 == 2) || (arg0->unk_00 == 3)) {
            GeoOverlay_DrawFadeQuad(arg0, arg1);
        } else {
            GeoOverlay_DrawRotatingQuad(arg0, arg1);
        }

        gDPPipeSync(D_800D0510++);
        gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
    }
}

void Geo_ProcessNodeChildren(void *root) {
    S1_GraphNode *first;
    S1_GraphNode *child;
    first = (S1_GraphNode *)((S1_GraphNode *)root)->unk_0C;
    child = first;
    if (first != NULL) {
        do {
            if (child->unk_01 & 1) {
                D_80124D60 = 0;
                if (child->unk_10 != NULL) {
                    D_80124D60 = child->unk_10(2, child);
                }
                ((void (*)(S1_GraphNode *))D_80094924[child->unk_00])(child);
            }
            child = child->unk_08;
        } while (child != first);
    }
}

void Geo_PrepareShadowChildren(s32 root) {
    S1_GraphNode *first = (S1_GraphNode *)((S1_GraphNode *)root)->unk_0C;
    S1_GraphNode *node = first;
    if (first != NULL) {
        do {
            if (node->unk_01 & 1) {
                D_80124D60 = 0;
                if (node->unk_10 != NULL) {
                    D_80124D60 = node->unk_10(6, node);
                }
                switch (node->unk_00) {
                default:
                    Geo_PrepareShadowChildren((s32)node);
                    break;
                case 0x13:
                    func_8003B690((s32)node);
                    break;
                case 0x14:
                    Geo_PrepareAnimatedPart((s32)node);
                    break;
                }
            }
            node = node->unk_08;
        } while (node != first);
    }
}

void Geo_NodeReference(void *arg0) {
    s32 (*callback)(s32, void *);
    void *child;
    callback = 0;
    child = *(void **)((u8 *)arg0 + 0x18);
    if (child != 0 && (*(u8 *)((u8 *)child + 1) & 1) != 0) {
        D_80124D60 = 0;
        callback = *(s32 (**)(s32, void *))((u8 *)child + 0x10);
        if (callback != 0) {
            D_80124D60 = callback(2, child);
        }
        ((void (*)(void *))((void **)D_80094924)[*(u8 *)child])(child);
    }
    Geo_ProcessNodeChildren(arg0);
}

void func_8003A4CC(S1_GraphNode *arg0) {
    UNUSED S1_MtxF pad_mtx;
    S1_unk_D_86002F34_00C *arg = (S1_unk_D_86002F34_00C *)arg0;
    S1_unk_D_86002F34_00C_040 *temp_s2 = &arg->unk_40;
    S1_unk_D_86002F34_00C_060 *temp_s1 = &arg->unk_60;
    S1_unk_D_86002F34_00C_024 *sp48 = &arg->unk_24;
    S1_unk_D_86002F34_00C_018 *temp_s0 = &arg->unk_18;

    temp_s0->vp = Gfx_AllocDisplayList(sizeof(Vp) * 1);
    temp_s2->mtx = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp48->mtx = Gfx_AllocDisplayList(sizeof(S1_MtxF) * 1);
    temp_s1->p_mtxf = Gfx_AllocDisplayList(sizeof(S1_MtxF) * 1);
    temp_s1->lookat = Gfx_AllocDisplayList(sizeof(LookAt) * 1);

    temp_s0->vp->vp.vtrans[0] = (temp_s0->x * 4) + (temp_s0->width * 2);
    temp_s0->vp->vp.vtrans[1] = (temp_s0->y * 4) + (temp_s0->height * 2);
    temp_s0->vp->vp.vtrans[2] = 0x1FF;

    temp_s0->vp->vp.vscale[0] = temp_s0->width * 2;
    temp_s0->vp->vp.vscale[1] = temp_s0->height * 2;
    temp_s0->vp->vp.vscale[2] = 0x1FF;

    gSPViewport(D_800D0510++, (u32)temp_s0->vp & 0x1FFFFFFF);
    gDPSetScissorFrac(D_800D0510++, G_SC_NON_INTERLACE, temp_s0->x * 4.0f, temp_s0->y * 4.0f,
                      (temp_s0->x + temp_s0->width) * 4.0f, (temp_s0->y + temp_s0->height) * 4.0f);

    guOrtho(temp_s2->mtx, temp_s2->l, temp_s2->r, temp_s2->b, temp_s2->t, temp_s2->n, temp_s2->f, temp_s2->scale);
    func_80077DC0(sp48->mtx, &sp48->perspNorm, sp48->fovy, sp48->aspect, sp48->near, sp48->far, sp48->scale);
    guLookAtReflectF(&temp_s1->mtxf, temp_s1->lookat, temp_s1->eye.x, temp_s1->eye.y, temp_s1->eye.z, temp_s1->at.x,
                     temp_s1->at.y, temp_s1->at.z, temp_s1->up.x, temp_s1->up.y, temp_s1->up.z);
    MtxF_ToFixed(temp_s1->p_mtxf, &temp_s1->mtxf);

    D_80094908 = arg;
    if ((arg->unk_CC.unk_00 != 1) && (arg->unk_00.unk_0C != NULL)) {
        func_8003A2C8(&arg->unk_00);
    }
    GeoOverlay_Draw(&arg->unk_CC, temp_s2);
    Gfx_ApplyScissorRect(&D_800D0510);
    D_80094908 = NULL;
}

void Geo_NodeType3Pass(s32 arg0) {
    D_8009490C = arg0;
    Geo_ProcessNodeChildren((void *)arg0);
    D_8009490C = 0;
}

void Geo_NodeModelRoot(void *root) {
    ModelFrame *node = (ModelFrame *)root;
    if (((S1_GraphNode *)root)->unk_0C != NULL) {
        node->unknown1D = 0;
        node->unknown20 = -1;
        node->lights = (Lights7 *)Gfx_AllocDisplayList(sizeof(Lights7));
        node->lightCount = 0;
        node->activeLights = 0;
        node->extraGeometryMode = 0;
        node->lights->a.l.col[0] = 0;
        node->lights->a.l.col[1] = 0;
        node->lights->a.l.col[2] = 0;
        // Geo_NodeAmbientLight conditionally enables the unnamed 0x00400000 bit.
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0x00400000);
        gSPSetGeometryMode(D_800D0510++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gSPTexture(D_800D0510++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
        ModelAnim_ResetCurveContext();
        ModelAnim_ResetEventContext();
        func_80039070(0);
        GeoRender_ResetTransformStack();
        gSPMatrix(D_800D0510++, (u32)((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        D_80094910 = node;
        Geo_ProcessNodeChildren(root);
        D_80094910 = NULL;
    }
    node->unk_1A = D_80094904;
}

void Geo_NodeModelPartRoot(void *root) {
    void *node;
    node = root;
    if (D_80094914 == NULL && ((S1_GraphNode *)node)->unk_0C != NULL) {
        D_80094914 = (S1_unk_D_86002F34_00C *)node;
        GeoRender_InitMaterialState(((S1_GraphNode *)node)->unk_02 & 7, D_80094900);
        Geo_ProcessNodeChildren(root);
        GeoRender_FlushMaterialSlots();
        D_80094914 = NULL;
    }
}

void Geo_NodeOrtho(void *root) {
    if (D_80094914 == NULL && ((S1_GraphNode *)root)->unk_0C != NULL) {
        gSPPerspNormalize(D_800D0510++, 0xFFFF);
        gSPMatrix(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_40.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        Geo_NodeModelPartRoot(root);
    }
}

void Geo_NodePerspective(void *root) {
    if (D_80094914 == NULL && ((S1_GraphNode *)root)->unk_0C != NULL) {
        gSPLookAt(D_800D0510++, (u32)(((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.lookat) & 0x1FFFFFFF);
        gSPPerspNormalize(D_800D0510++, ((S1_unk_D_86002F34_00C *)D_80094908)->unk_24.perspNorm);
        gSPMatrix(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_24.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.p_mtxf & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        Geo_NodeModelPartRoot(root);
    }
}

void Geo_NodeBackground(u8 *arg0) { u8 *state = (u8 *)D_80094908 + 0x18; GfxImage_FillRectangle(&D_800D0510, *(s16 *)(state + 4), *(s16 *)(state + 6), *(s16 *)(state + 8), *(s16 *)(state + 10), *(s32 *)(arg0 + 0x18)); gDPPipeSync(D_800D0510++); gSPSetOtherMode(D_800D0510++, G_SETOTHERMODE_H, 20, 2, 0x100000); }

void Geo_NodeClearDepth(s32 arg0) {
    void *state = (u8 *)D_80094908 + 0x18;
    GfxImage_ClearDepthRectangle(&D_800D0510, *(s16 *)((u8 *)state + 4), *(s16 *)((u8 *)state + 6), *(s16 *)((u8 *)state + 8), *(s16 *)((u8 *)state + 10));
    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
}

void func_8003AC84(s32 arg0) {}

void Geo_NodeFog(S1_GraphNode *root) {
    S1_unk_D_86002F34_alt3 *node = (S1_unk_D_86002F34_alt3 *)root;
    D_80094910->unknown1D = 1;
    D_80094910->unknown20 = node->unk_1C;
    gSPFogPosition(D_800D0510++, node->unk_18, node->unk_1A);
    gSPSetGeometryMode(D_800D0510++, G_FOG);
    gDPSetColor(D_800D0510++, G_SETFOGCOLOR, node->unk_1C);
}

void Geo_NodeLight(S1_GraphNode *root) {
    SceneDirectionalLight *node = (SceneDirectionalLight *)root;
    SceneLightRecord *light;
    s32 index;
    if (D_80094910->lightCount >= 7) {
        return;
    }
    light = (SceneLightRecord *)&D_80094910->lights->l[D_80094910->lightCount];
    if (node->overrideDirection == 0) {
        light->directional.l.pad1 = 0;
        *(u32 *)light->directional.l.col = node->color.rgba;
        *(u32 *)light->directional.l.colc = node->color.rgba;
        light->directional.l.dir[0] = (120.0f * D_80088E50[((u16)node->pitch >> 4)]) * D_80087E50[((u16)node->yaw >> 4)];
        light->directional.l.dir[1] = 120.0f * D_80087E50[((u16)node->pitch >> 4)];
        light->directional.l.dir[2] = (120.0f * D_80088E50[((u16)node->pitch >> 4)]) * D_80088E50[((u16)node->yaw >> 4)];
    } else {
        light->point.color = node->color.rgba;
        light->point.colorCopy = node->color.rgba;
        light->point.position.x = node->direction.x;
        light->point.position.y = node->direction.y;
        light->point.position.z = node->direction.z;
        light->directional.l.pad1 = node->red;
        light->directional.l.pad2 = node->green;
        light->point.quadratic = node->blue;
        D_80094910->extraGeometryMode++;
    }
    D_80094910->lightCount++;
    if (node->node.unk_02 & 1) {
        gMoveWd(D_800D0510++, G_MW_NUMLIGHT, 0, D_80094910->lightCount * 0x18);
        for (index = D_80094910->activeLights; index < D_80094910->lightCount; index++) {
            gSPLight(D_800D0510++, &D_80094910->lights->l[index], index + 1);
        }
        gSPLight(D_800D0510++, D_80094910->lights, index + 1);
    }
}

void func_8003B03C(s32 arg0) {}

void Geo_NodeAmbientLight(void *root) {
    SceneAmbientLightNode *node = root;
    s32 i;
    Lights7 *lights;
    lights = D_80094910->lights;
    if (node->color.r == 0xFF && node->color.g == 0xFF && node->color.b == 0xFF) {
        lights->a.l.colc[0] = lights->a.l.col[0];
        lights->a.l.colc[1] = lights->a.l.col[1];
        lights->a.l.colc[2] = lights->a.l.col[2];
    } else {
        lights->a.l.colc[0] = lights->a.l.col[0] = node->color.r;
        lights->a.l.colc[1] = lights->a.l.col[1] = node->color.g;
        lights->a.l.colc[2] = lights->a.l.col[2] = node->color.b;
    }
    D_80094910->activeLights = D_80094910->lightCount;
    gSPSetGeometryMode(D_800D0510++, G_LIGHTING);
    if (D_80094910->extraGeometryMode > 0) {
        gSPSetGeometryMode(D_800D0510++, 0x00400000);
    }
    gMoveWd(D_800D0510++, G_MW_NUMLIGHT, 0, D_80094910->lightCount * 0x18);
    for (i = 0; i < D_80094910->lightCount; i++) {
        gSPLight(D_800D0510++, &D_80094910->lights->l[i], i + 1);
    }
    gSPLight(D_800D0510++, D_80094910->lights, i + 1);
}

void Geo_NodeUpdateLights(S1_GraphNode *root) {
    s32 index;
    if (D_80094910->activeLights != D_80094910->lightCount) {
        D_80094910->lightCount = D_80094910->activeLights;
        gMoveWd(D_800D0510++, G_MW_NUMLIGHT, 0, D_80094910->lightCount * 0x18);
        for (index = 0; index < D_80094910->lightCount; index++) {
            gSPLight(D_800D0510++, &D_80094910->lights->l[index], index + 1);
        }
        gSPLight(D_800D0510++, D_80094910->lights, index + 1);
    }
}

/* mkdraft:func_8003B350 begin */
extern u8 D_1000D90[];
extern void func_800390D8(Mtx *);
extern void func_8003D888(s16, Mtx *);
extern void func_8003A370(s32);



void func_8003B350(u8 *arg0) {
    s32 pad[2];
    S1_MtxF *matrix;
    Vec3f35784 position;
    Vec3s35AA0 rotation;
    s32 index;

    matrix = &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top];
    if (((u8 *)D_8009491C)[2] & 2) {
        Vec3f_SetComponentsDuplicate(&position, matrix->mf[3][0], 0.0f, matrix->mf[3][2]);
        Vec3s_SetComponents(&rotation, 0, *(s16 *)((u8 *)D_8009491C + 0x20), 0);
        MtxF_SetRotationTranslationF(((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 1].mf, &position, &rotation);
        ((SceneTransformPool *)&D_80124F68)->top++;
        func_800390D8(NULL);
        func_8003D888(0, ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top]);
        func_8003DA20((s32)D_1000D90, 1);
        ((SceneTransformPool *)&D_80124F68)->top--;
    }
    // FAKE: alias write of D_80094920 (the word after D_8009491C); the named form
    // folds the address into $s0 and costs an instruction. See func_8003B350.report.md.
    ((u8 **)&D_8009491C)[1] = arg0;
    for (index = 0; index < 128; index++) D_80124D68[index] = 0;
    if (*(u16 *)(arg0 + 0x28) & 1) {
        func_8003A370((s32)arg0);
    }
    func_8003A2C8(arg0);
    D_80094920 = NULL;
}
/* mkdraft:func_8003B350 end */

void Geo_NodeCullDistance(S1_GraphNode *root) {
    S1_unk_D_86002F34_alt3 *range = (S1_unk_D_86002F34_alt3 *)root;
    S1_MtxF *view = &((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf;
    f32 x = ((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top].mf[3][0];
    f32 y = ((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top].mf[3][1];
    f32 z = ((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top].mf[3][2];
    s16 depth = ((x * view->mf[0][2]) + (y * view->mf[1][2]) + (z * view->mf[2][2])) + view->mf[3][2];
    if ((depth >= range->unk_18) && (depth < range->unk_1A)) {
        Geo_ProcessNodeChildren(root);
    }
}

void Geo_NodeSwitchCase(S1_GraphNode *root) {
    S1_unk_D_86002F34_alt3 *selection = (S1_unk_D_86002F34_alt3 *)root;
    s32 index;
    S1_GraphNode *child = (S1_GraphNode *)selection->unk_00.unk_0C;
    if (child != NULL) {
        for (index = 0; index < selection->unk_1A; index++) {
            child = child->unk_08;
        }
    }
    if (child->unk_01 & 1) {
        ((void (*)(S1_GraphNode *))D_80094924[child->unk_00])(child);
    }
}

void func_8003B5AC(u8 *arg0) {
    struct {
        u8 unused[8];
        f32 matrix[4][4];
    } scratch;

    MtxF_SetRotationTranslationF(scratch.matrix, (Vec3f35784 *)(arg0 + 0x18), (Vec3s35AA0 *)(arg0 + 0x24));
    GeoRender_PushMultipliedMatrix((S1_MtxF *)scratch.matrix, NULL);
    Geo_ProcessNodeChildren(arg0);
    *(s32 *)((u8 *)&D_80124F68 + 0x10A0) -= 1;
}

void func_8003B600(u8 *arg0) {
    s32 status = 0;
    if (D_80094920 != NULL && (*(u16 *)(D_80094920 + 0x28) & 1) != 0) {
        status = 1;
    }
    if (status != 0) {
        GeoRender_PushScaledMatrix((S1_Vec3f *)(arg0 + 0x18), (Mtx *)D_8009499C);
    } else {
        D_8009499C = (s32)GeoRender_PushScaledMatrix((S1_Vec3f *)(arg0 + 0x18), NULL);
    }
    Geo_ProcessNodeChildren(arg0);
    (*(s32 *)((u8 *)&D_80124F68 + 0x10A0))--;
}

void func_8003B690(s32 arg0) {
    D_8009499C = (s32)GeoRender_PushScaledMatrix((S1_Vec3f *)(arg0 + 0x18), NULL);
    Geo_PrepareShadowChildren(arg0);
    (*(s32 *)((u8 *)(&D_80124F68) + (0x10A0))) = (s32) ((*(s32 *)((u8 *)(&D_80124F68) + (0x10A0))) - 1);
}

void Geo_NodeAnimatedPart(s32 root) {
    S1_Vec3s rotation;
    S1_Vec3f position;
    S1_Vec3f scaling;
    S1_MtxF matrix;
    S1_unk_D_86002F34_alt6 *node = (S1_unk_D_86002F34_alt6 *)root;
    s32 pushed;
    s32 reuse;
    pushed = 0;
    reuse = 0;
    if (D_80094920 != NULL && (*(u16 *)(D_80094920 + 0x28) & 1) != 0) {
        reuse = 1;
    }
    rotation = node->unk_1E;
    scaling = node->unk_24;
    Vec3f_FromVec3s((Vec3f358AC *)&position, (Vec3s358AC *)&node->unk_18);
    func_8003E8C8(&position, &rotation, &scaling, node->unk_32 * 3);
    if (node->unk_31 & 2) {
        MtxF_BuildTransform(&matrix, &position, &rotation, &scaling, &((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        if (reuse != 0) {
            GeoRender_SetMatrix(&matrix, (Mtx *)D_80124D68[node->unk_30]);
        } else {
            GeoRender_SetMatrix(&matrix, NULL);
        }
    } else if (node->unk_31 & 1) {
        MtxF_SetRotationScaleTranslation(&matrix, &position, &rotation, &scaling);
        if (reuse != 0) {
            GeoRender_PushMultipliedMatrix(&matrix, (Mtx *)D_80124D68[node->unk_30]);
        } else {
            GeoRender_PushMultipliedMatrix(&matrix, NULL);
        }
    } else {
        MtxF_SetRotationAndScaledTranslation(&matrix, &position, &rotation, &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        func_800393F0(&scaling);
        if (((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top - 1] == 1) {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 31]);
        } else {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1]);
        }
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        if (reuse != 0) {
            GeoRender_CommitMatrix((Mtx *)D_80124D68[node->unk_30]);
        } else {
            GeoRender_CommitMatrix(NULL);
        }
        ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 1;
        pushed = 1;
    }
    if (reuse == 0) {
        D_80124D68[node->unk_30] = (s32)((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
    }
    Geo_ProcessNodeChildren((void *)root);
    ((SceneTransformPool *)&D_80124F68)->top--;
    if (pushed != 0) {
        ((SceneScaleStack *)&D_80126010)->top--;
    }
}

void Geo_PrepareAnimatedPart(s32 root) {
    S1_Vec3s rotation;
    S1_Vec3f position;
    S1_Vec3f scaling;
    S1_MtxF matrix;
    S1_unk_D_86002F34_alt6 *node = (S1_unk_D_86002F34_alt6 *)root;
    s32 pushed;
    pushed = 0;
    rotation = node->unk_1E;
    scaling = node->unk_24;
    Vec3f_FromVec3s((Vec3f358AC *)&position, (Vec3s358AC *)&node->unk_18);
    func_8003E8C8(&position, &rotation, &scaling, node->unk_32 * 3);
    if (node->unk_31 & 2) {
        MtxF_BuildTransform(&matrix, &position, &rotation, &scaling, &((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        GeoRender_SetMatrix(&matrix, NULL);
    } else if (node->unk_31 & 1) {
        MtxF_SetRotationScaleTranslation(&matrix, &position, &rotation, &scaling);
        GeoRender_PushMultipliedMatrix(&matrix, NULL);
    } else {
        MtxF_SetRotationAndScaledTranslation(&matrix, &position, &rotation, &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        func_800393F0(&scaling);
        if (((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top - 1] == 1) {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 31]);
        } else {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1]);
        }
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        GeoRender_CommitMatrix(NULL);
        ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 1;
        pushed = 1;
    }
    D_80124D68[node->unk_30] = (s32)((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
    Geo_PrepareShadowChildren(root);
    ((SceneTransformPool *)&D_80124F68)->top--;
    if (pushed != 0) {
        ((SceneScaleStack *)&D_80126010)->top--;
    }
}

void func_8003BC48(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x18) != 0) {
        GeoRender_SubmitMaterial(*((u8 *)arg0 + 3), D_80124D68[*(s16 *)((u8 *)arg0 + 0x1C)]);
        func_8003DA20(*(s32 *)((u8 *)arg0 + 0x18), (*((u8 *)arg0 + 2) & 4) != 0);
    }
    Geo_ProcessNodeChildren(arg0);
}

void Geo_NodeModelPart(void *root) {
    S1_MtxF matrix;
    S1_Color_RGBA8_u32 reset_color;
    S1_unk_D_86002F58_004_000 *node = (S1_unk_D_86002F58_004_000 *)root;
    if (node->animType == *(s16 *)((u8 *)D_80094910 + 0x18) || node->animType == 10) {
        node->anchorCount = 0;
        func_8003E7B0((S1_unk_D_86002F58_004_000_040_raw *)&node->unk_040, D_80094904, (node->unk_000.unk_02 & 0x20) != 0);
        ModelAnim_BeginEventContext(&node->unk_054, D_80094904, (node->unk_000.unk_02 & 0x20) != 0);
        if (node->unk_000.unk_02 & 0x10) {
            MtxF_Multiply(&matrix, &node->unk_060, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        } else if (node->unk_000.unk_02 & 8) {
            func_80036714(&matrix, (s32)&((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf, (s32)&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], (s32)&node->unk_024, 1.0f);
        } else if (node->unk_000.unk_02 & 0x80) {
            MtxF_SetRotationAndTransformTranslation(matrix.mf, (Vec3f35784 *)&node->unk_024, (Vec3s35AA0 *)&node->unk_01E);
            MtxF_Multiply(&matrix, &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        } else {
            MtxF_SetRotationTranslationF(matrix.mf, (Vec3f35784 *)&node->unk_024, (Vec3s35AA0 *)&node->unk_01E);
            MtxF_Multiply(&matrix, &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        }
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 1], &matrix, &node->unk_030);
        if (!(node->unk_000.unk_02 & 4)) {
            ((SceneTransformPool *)&D_80124F68)->top++;
            GeoRender_CommitMatrix(NULL);
            D_8009491C = node;
            GeoRender_SetMaterialParams(node->unk_0A0, node->materialAlpha, node->textureMode);
            if (node->modelId >= 0) {
                func_800707D0(node);
            }
            Geo_ProcessNodeChildren(root);
            if (node->modelId >= 0) {
                func_80070860((s32)node);
            }
            reset_color.rgba = 0xFFFFFF00;
            GeoRender_SetMaterialParams(reset_color, 0xFF, 0);
            D_8009491C = NULL;
        }
        ModelAnim_EndCurveContext();
        ModelAnim_EndEventContext();
        ((SceneTransformPool *)&D_80124F68)->top--;
    }
}

void func_8003BEF0(void *arg0) { s32 *counter = &D_80126008; GeoRender_PushMultipliedMatrix((u8 *)arg0 + 0x1C, 0); if (*(s32 *)((u8 *)arg0 + 0x18) != 0 || *(s32 *)((u8 *)arg0 + 0x10) != 0) { GeoRender_SubmitMaterial(*((u8 *)arg0 + 3), ((s32 *)&D_80124F68)[*(s32 *)((u8 *)&D_80124F68 + 0x10A0) + 0x400]); if (*(void **)((u8 *)arg0 + 0x10) != 0) ((void (*)(s32, void *))(*(void **)((u8 *)arg0 + 0x10)))(5, arg0); func_8003DA20(*(s32 *)((u8 *)arg0 + 0x18), (*((u8 *)arg0 + 2) & 4) != 0); } Geo_ProcessNodeChildren(arg0); *counter = *counter - 1; }

void func_8003BF9C(void *arg0) {
    S1_MtxF sp30;
    u8 (*pool)[0x40] = (u8 (*)[0x40])(void *)&D_80124F68;
    func_80036714(&sp30, (s32)((u8 *)D_80094908 + 0x64), (s32)pool[*(s32 *)((u8 *)&D_80124F68 + 0x10A0)], (s32)((u8 *)arg0 + 0x1C), *(f32 *)((u8 *)arg0 + 0x28));
    (*(s32 *)((u8 *)&D_80124F68 + 0x10A0))++;
    GeoRender_SetMatrix(&sp30, 0);
    if (*(s32 *)((u8 *)arg0 + 0x18) != 0 || *(s32 *)((u8 *)arg0 + 0x10) != 0) {
        GeoRender_SubmitMaterial(*((u8 *)arg0 + 3), ((s32 *)&D_80124F68)[*(s32 *)((u8 *)&D_80124F68 + 0x10A0) + 0x400]);
        if (*(void **)((u8 *)arg0 + 0x10) != 0) ((void (*)(s32, void *))(*(void **)((u8 *)arg0 + 0x10)))(5, arg0);
        func_8003DA20(*(s32 *)((u8 *)arg0 + 0x18), (*((u8 *)arg0 + 2) & 4) != 0);
    }
    Geo_ProcessNodeChildren(arg0);
    (*(s32 *)((u8 *)&D_80124F68 + 0x10A0))--;
}

void Geo_NodeDisplayList(void *arg0) {
    void *root = arg0;
    s32 callback;
    if (*(s32 *)((u8 *)root + 0x18) != 0 || *(s32 *)((u8 *)root + 0x10) != 0) {
        GeoRender_SubmitMaterial(*(u8 *)((u8 *)root + 3), ((s32 *)((u8 *)&D_80124F68 + 0x1000))[*(s32 *)((u8 *)&D_80124F68 + 0x10A0)]);
        callback = *(s32 *)((u8 *)root + 0x10);
        if (callback != 0) ((void (*)(s32, void *))callback)(5, root);
        func_8003DA20(*(s32 *)((u8 *)root + 0x18), (*(u8 *)((u8 *)root + 2) & 4) != 0);
    }
    Geo_ProcessNodeChildren(root);
}

void Geo_NodeShadowTexture(void *root) {
    CandidateColor color;
    S1_unk_D_86002F34_alt10 *node = (S1_unk_D_86002F34_alt10 *)root;
    s32 texture;
    s32 material;
    s32 display_list;
    texture = 0;
    material = 0;
    display_list = (s32)node->unk_18;
    if (node->unk_22 == 1) {
        color.rgba = 0xFFFFFFFF;
    } else {
        color.rgba = node->unk_24.rgba;
    }
    if (node->unk_1C >= 0) {
        texture = *(s32 *)(D_80094920 + 0x18) + node->unk_1C * 12;
    }
    if (node->unk_1E >= 0) {
        material = *(s32 *)(D_80094920 + 0x1C) + node->unk_1E * 12;
    }
    if (D_8009491C != NULL) {
        color.r = (color.r * ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_03C.r) / 255;
        color.g = (color.g * ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_03C.g) / 255;
        color.b = (color.b * ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_03C.b) / 255;
    }
    func_8003EE20(&texture, *(s32 *)(D_80094920 + 0x18), node->unk_20);
    GeoRender_SetMaterialTexture(node->unk_22, color, (void *)texture, (void *)material, display_list);
    Geo_ProcessNodeChildren(root);
}

void func_8003C2D8(s32 id) {
    S1_MtxF *matrix;
    SceneAnchorPosition *anchor;
    if (((SceneDisplayObjectAnchors *)D_8009491C) != NULL) {
        if (((SceneDisplayObjectAnchors *)D_8009491C)->anchorCount < 12) {
            anchor = &((SceneDisplayObjectAnchors *)D_8009491C)->anchors[
                ((SceneDisplayObjectAnchors *)D_8009491C)->anchorCount++];
            matrix = &((SceneTransformPool *)&D_80124F68)->matrices[
                ((SceneTransformPool *)&D_80124F68)->top];
            anchor->id = id;
            anchor->position.x = matrix->mf[3][0];
            anchor->position.y = matrix->mf[3][1];
            anchor->position.z = matrix->mf[3][2];
        }
    }
}

void Geo_NodeAnchor(void *arg0) {
    func_8003C2D8(*(s16 *)((u8 *)arg0 + 0x18));
    Geo_ProcessNodeChildren(arg0);
}

 void Geo_NodeGroup(void *arg0) { Geo_ProcessNodeChildren(arg0); }

void Geo_NodeShadow(S1_unk_D_86002F34_alt12 *node) {
    Vec3f35784 position;
    Vec3f35784 up;
    S1_Vec3f scale;
    f32 height_scale;
    S1_MtxF basis;
    S1_MtxF *current;
    Gfx *commands;

    current = &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top];
    commands = Gfx_AllocDisplayList(2 * sizeof(Gfx));
    if (GeoRender_FindAnchorPosition(D_8009491C, 100, NULL) == NULL) {
        func_8003C2D8(100);
    }
    Vec3f_SetComponentsDuplicate(&position, current->mf[3][0], current->mf[3][1] + node->unk_1E, current->mf[3][2]);
    position.y = 0.0f;
    if (((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_000.unk_02 & 0x40) {
        Vec3f_SetComponentsDuplicate(&up, 0.0f, 1.0f, 0.0f);
        func_80036D8C(&current->mf[0][0], &scale.x);
        height_scale = 1.0f - ((current->mf[3][1] - position.y) / 1000.0f);
        if (height_scale < 0.5f) {
            height_scale = 0.5f;
        }
        if (height_scale > 1.0f) {
            height_scale = 1.0f;
        }
        scale.x *= (node->unk_1A / 100.0f) * height_scale;
        scale.z *= (node->unk_1C / 100.0f) * height_scale;
        MtxF_SetOrthonormalBasis(basis.mf, &up, &position, ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_01E.y);
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 1], &basis, &scale);
        ((SceneTransformPool *)&D_80124F68)->top++;
        GeoRender_CommitMatrix(NULL);
        if (node->unk_18 == 0) {
            gSPBranchList(&commands[1], func_80003240(D_1000C80));
        } else {
            gSPBranchList(&commands[1], func_80003240(D_1000D08));
        }
        gDPSetEnvColor(&commands[0], 0, 0, 0, (s32)(120.0f * height_scale));
        if (((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_000.unk_02 & 2) {
            GeoRender_SubmitMaterial(7, ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top]);
        } else {
            GeoRender_SubmitMaterial(6, ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top]);
        }
        gDPSetFogColor(D_800D0510++, 255, 255, 255, 0);
        gDPSetPrimColor(D_800D0510++, 0, ((S1_unk_D_86002F58_004_000 *)D_8009491C)->materialAlpha, 255, 255, 255, 255);
        func_8003DA20((u32)commands & 0x1FFFFFFF, 1);
        Geo_ProcessNodeChildren(node);
        ((SceneTransformPool *)&D_80124F68)->top--;
    }
}

void Geo_RenderRootNode(u8 *node) {
    if (node[1] & 1) {
        gDPPipeSync(D_800D0510++);
        gDPSetTextureLOD(D_800D0510++, G_TL_TILE);
        gDPSetTextureLUT(D_800D0510++, G_TT_NONE);
        gDPSetTextureDetail(D_800D0510++, G_TD_CLAMP);
        gDPSetTexturePersp(D_800D0510++, G_TP_PERSP);
        gDPSetTextureFilter(D_800D0510++, G_TF_BILERP);
        gDPSetTextureConvert(D_800D0510++, G_TC_FILT);
        gDPSetCombineKey(D_800D0510++, G_CK_NONE);
        gDPSetAlphaCompare(D_800D0510++, G_AC_NONE);
        gDPSetColorDither(D_800D0510++, G_CD_MAGICSQ);
        gDPSetAlphaDither(D_800D0510++, G_AD_PATTERN);
        func_8006D2C0();
        D_8009490C = (s32)node;
        Geo_ProcessNodeChildren(node);
        D_8009490C = 0;
    }
    D_80094900 = 0;
}

void Geo_ProcessCallbacks(S1_GraphNode *root, s32 event) {
    S1_GraphNode *node = root;
    S1_GraphNode **slot;
    do {
        if (node->unk_10 != NULL) {
            node->unk_10(event, node);
        }
        if (node->unk_0C != NULL) {
            switch (node->unk_00) {
            default:
                slot = NULL;
                break;
            case 2:
                slot = (S1_GraphNode **)&D_80094908;
                break;
            case 4:
                slot = (S1_GraphNode **)&D_80094910;
                break;
            case 6:
                slot = (S1_GraphNode **)&D_80094918;
                break;
            case 22:
                slot = (S1_GraphNode **)&D_8009491C;
                break;
            }
            if (slot != NULL) {
                *slot = node;
            }
            Geo_ProcessCallbacks((S1_GraphNode *)node->unk_0C, event);
            if (slot != NULL) {
                *slot = NULL;
            }
        }
        node = node->unk_08;
    } while (node != root);
}

void func_8003C964(s32 value) { D_80094900 = value; }

void GeoRender_AdvanceFrameCounter(void) { D_80094904++; }

s32 GeoRender_IsModelFrameCurrent(void) { s32 var_v1 = 1; if (D_80094910 != NULL) { var_v1 = D_80094910->unk_1A == D_80094904; } return var_v1; }

S1_Vec3f *GeoRender_FindAnchorPosition(u8 *object, s16 id, S1_Vec3f *out) {
    s32 i;
    for (i = 0; i < object[0xA7]; i++) {
        if (id == *(u16 *)(object + i * 0x10 + 0xA8)) {
            if (out != NULL) {
                *out = *(S1_Vec3f *)(object + i * 0x10 + 0xAC);
            }
            return (S1_Vec3f *)(object + i * 0x10 + 0xAC);
        }
    }
    return NULL;
}

#endif
