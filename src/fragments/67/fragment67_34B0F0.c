#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_34B0F0/func_8290E5F0.s")
#endif

#ifdef VERSION_US
typedef struct unk_D_8291BC50 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u8 unk_06[2];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
} unk_D_8291BC50;

extern unk_D_8291BC50 D_8291BC50;

void func_8290E6D4(void) {
    D_8291BC50.unk_0E++;
    switch (D_8291BC50.unk_12) {
        case 3:
            D_8291BC50.unk_12 = 4;
            D_8291BC50.unk_0E = 0;
            break;
        case 4:
            D_8291BC50.unk_12 = 5;
            D_8291BC50.unk_0E = 0;
            break;
        case 5:
            D_8291BC50.unk_12 = 0;
            D_8291BC50.unk_0E = 0;
            break;
        case 0:
            D_8291BC50.unk_12 = 1;
            D_8291BC50.unk_0E = 0;
            break;
        case 1:
            D_8291BC50.unk_12 = 2;
            D_8291BC50.unk_0E = 0;
            break;
        case 2:
            D_8291BC50.unk_12 = 3;
            D_8291BC50.unk_0E = 0;
            break;
    }
}
#endif

#ifdef VERSION_US
void func_8290E76C(void) {
    D_8291BC50.unk_0C++;
    switch (D_8291BC50.unk_10) {
        case 0:
            if (D_8291BC50.unk_0C % 30 == 0) {
                D_8291BC50.unk_10 = 1;
                D_8291BC50.unk_0C = 0;
            }
            break;
        case 1:
            D_8291BC50.unk_10 = 2;
            D_8291BC50.unk_0C = 0;
            break;
        case 2:
            D_8291BC50.unk_10 = 3;
            D_8291BC50.unk_0C = 0;
            break;
        case 3:
            D_8291BC50.unk_10 = 4;
            D_8291BC50.unk_0C = 0;
            break;
        case 4:
            D_8291BC50.unk_10 = 5;
            D_8291BC50.unk_0C = 0;
            break;
        case 5:
            D_8291BC50.unk_10 = 0;
            D_8291BC50.unk_0C = 0;
            break;
    }
}
#endif

#ifdef VERSION_US
typedef struct unk_D_8291BC68 {
    s16 unk_00;
    s16 unk_02;
    s16 index;
    u8 unk_06[2];
    s8 text[255];
    s8 revealed[255];
} unk_D_8291BC68;

extern unk_D_8291BC68 D_8291BC68;
extern void func_800226C0(s32);

s32 func_8290E81C(void) {
    if (D_8291BC68.text[D_8291BC68.index] == 0) {
        return 1;
    }
    D_8291BC68.revealed[D_8291BC68.index] = D_8291BC68.text[D_8291BC68.index];
    if (D_8291BC68.text[D_8291BC68.index] == 10) {
        D_8291BC68.index++;
        return 0;
    }
    D_8291BC68.index++;
    if (D_8291BC68.text[D_8291BC68.index] == 0) {
        return 1;
    }
    func_800226C0(295);
    D_8291BC68.revealed[D_8291BC68.index] = D_8291BC68.text[D_8291BC68.index];
    D_8291BC68.index++;
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_34B0F0/func_8290E8D8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_34B0F0/func_8290EAC0.s")
#endif

#ifdef VERSION_US
// Close to Pokemon Stadium's BattleHud_DrawGradientRect; GS takes the vertex alpha as arg6
// instead of 0xFF, sets G_SHADE | G_SHADING_SMOOTH, and draws with G_RM_XLU_SURF instead
// of G_RM_OPA_SURF.
typedef struct GfxImage {
    /* 0x00 */ u16 fmt;
    /* 0x02 */ u16 size;
    /* 0x04 */ u16 width;
    /* 0x06 */ u16 height;
    /* 0x08 */ u8 *img_p;
    /* 0x0C */ void *depth_p;
} GfxImage;
extern GfxImage *func_8000731C(void);
extern void *Gfx_AllocDisplayList(s32);
extern void Gfx_SetViewportDimensions(void *, s16, s16);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
extern Gfx *D_800D0510;
extern Mtx D_80094890;
void func_8290EFA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4, u8 *arg5, u8 arg6) {
    Vtx *temp_s2;
    GfxImage *temp_s1;
    Mtx *sp7C;
    Vp *sp78;

    temp_s1 = func_8000731C();
    temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    sp7C = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp78 = Gfx_AllocDisplayList(sizeof(Vp) * 1);
    Gfx_SetViewportDimensions(sp78, temp_s1->width, temp_s1->height);

    gSPViewport(D_800D0510++, (u32)sp78 & 0x1FFFFFFF);

    guOrtho(sp7C, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, arg4[0], arg4[1], arg4[2], arg6);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, arg4[0], arg4[1], arg4[2], arg6);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, arg5[0], arg5[1], arg5[2], arg6);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, arg5[0], arg5[1], arg5[2], arg6);

    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
    gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_LIGHTING);
    gSPSetGeometryMode(D_800D0510++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetCombineMode(D_800D0510++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(D_800D0510++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(D_800D0510++, 0xFFFF);
    gSPMatrix(D_800D0510++, (u32)sp7C & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(D_800D0510++, (u32)&D_80094890 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(D_800D0510++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(D_800D0510++, 0, 2, 3, 0, 0, 3, 1, 0);
}
#endif

void func_8290F36C(void) {
}

#ifdef VERSION_US
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

M2C_UNK GfxRect_DrawTextured(s16, s16, s16, s16, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800459AC(s32, u8, u8, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_8004CA60(u8 *);                          /* extern */

void func_8290F374(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 *arg4) {
    if (arg4 != NULL) {
        func_800459AC(func_8004CA60(arg4), M2C_FIELD(arg4, u8 *, 4), M2C_FIELD(arg4, u8 *, 5), M2C_FIELD(arg4, u16 *, 0), (s32) M2C_FIELD(arg4, u16 *, 2), 1, 0, 2, 2, 0, 0, 0, 0);
    }
    GfxRect_DrawTextured(arg0, arg1, arg2, arg3, 0, 0, 0x400, 0x400, 0);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_34B0F0/func_8290F42C.s")
#endif

#ifdef VERSION_US
extern void BgStage_DrawFrame(void);
extern void func_8290F42C(void);
extern void func_80008648(void);
void func_8290FA00(void) {
    BgStage_DrawFrame();
    func_8290F42C();
    func_80008648();
}
#endif

#ifdef VERSION_US
extern s32 D_8291BC40;
extern s32 D_8291BC44;
extern void StageFade_StartFromOpaque(s32);
extern void func_8290FA00(void);
extern void func_80021ED8(s32);
void func_8290FA30(void) {
    s32 var_s0;

    D_8291BC40 = 1;
    D_8291BC44 = 1;
    StageFade_StartFromOpaque(0xC);
    var_s0 = 0;
    do {
        func_8290FA00();
        var_s0 += 1;
    } while (var_s0 != 0xE);
    func_80021ED8(0x3F);
    D_8291BC44 = 0;
}
#endif

#ifdef VERSION_US
extern void func_80064D28(void);
extern void func_8290E8D8(void);
void func_8290FA9C(void) {
    func_80064D28();
    func_8290E8D8();
    func_8290FA00();
}
#endif

#ifdef VERSION_US
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
void func_8290FACC(void) {
    s32 var_s0;

    func_800225C4(0x10);
    StageFade_StartFromTransparent(0x10);
    var_s0 = 0;
    do {
        func_8290FA00();
        var_s0 += 1;
    } while (var_s0 != 0x10);
}
#endif

#ifdef VERSION_US
extern void func_8290E5F0(void);
void func_8290FB1C(void) {
    func_8290E5F0();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_34B0F0/func_8290FB3C.s")
#endif
