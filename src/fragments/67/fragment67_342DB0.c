#include "global.h"


#ifdef VERSION_US
typedef float MtxF_t[4][4];
typedef struct { f32 x, y, z; } Vec3f;
typedef struct { s16 x, y, z; } Vec3s;

extern f32 D_80088E50[];
extern u8 D_82919DE0[];
extern s32 D_82912328;
extern Gfx *D_800D0510;

extern s32 Gfx_AllocDisplayList(s32);
extern void MtxF_SetRotationTranslationF(MtxF_t *, Vec3f *, Vec3s *);
extern void MtxF_ScaleRows(MtxF_t *, MtxF_t *, Vec3f *);
extern void MtxF_ToFixed(s32, MtxF_t *);

void func_829062B0(s32 arg0) {
    Vec3f spBC;
    Vec3s spB4;
    MtxF_t sp74;
    MtxF_t sp34;
    s32 sp30;
    f32 temp_fv0;
    u8 *temp_a1;
    Gfx *temp_v0_2;

    sp30 = Gfx_AllocDisplayList(0x40);
    temp_a1 = (arg0 * 0x24) + D_82919DE0;
    spB4.y = -0x4000;
    *(s16 *)(temp_a1 + 0x16) = *(s16 *)(temp_a1 + 0x18) + *(s16 *)(temp_a1 + 0x16);
    spB4.z = *(s16 *)(temp_a1 + 0x16);
    temp_fv0 = *(f32 *)(temp_a1 + 0xC) * D_80088E50[(s32)*(u16 *)(temp_a1 + 0x14) >> 4];
    spB4.x = 0;
    spBC.x = temp_fv0;
    spBC.y = temp_fv0;
    spBC.z = temp_fv0;
    MtxF_SetRotationTranslationF(&sp74, (Vec3f *)temp_a1, &spB4);
    MtxF_ScaleRows(&sp34, &sp74, &spBC);
    MtxF_ToFixed(sp30, &sp34);
    temp_v0_2 = D_800D0510;
    D_800D0510 = temp_v0_2 + 1;
    temp_v0_2->words.w0 = 0xDA380002;
    temp_v0_2->words.w1 = sp30 & 0x1FFFFFFF;
    temp_v0_2 = D_800D0510;
    D_800D0510 = temp_v0_2 + 1;
    gSPVertex(temp_v0_2, (u32)&D_82912328, 4, 0);
    temp_v0_2 = D_800D0510;
    D_800D0510 = temp_v0_2 + 1;
    gSP2Triangles(temp_v0_2, 0, 1, 2, 0, 0, 2, 3, 0);
}
/* Retail has a second jr ra; nop at 0x829063E4, after this function's epilogue and
 * before func_829063EC; no symbol in linker_scripts/us/symbol_addrs_code.txt covers
 * that address. An unreferenced empty function compiles to those eight bytes and
 * keeps the fragment's layout.
 * //@{asm/us/nonmatchings/fragments/67/fragment67_342DB0/func_829062B0.s} */

void func_829062B0_padding(void) {}

/* mkdraft:func_829063EC begin */
extern s32 MathUtil_Random16(void);
extern f64 D_829174D0;

u16 func_829063EC(s32 arg0) {
    return ((f32)(u32)MathUtil_Random16() / D_829174D0) * arg0;
}
/* mkdraft:func_829063EC end */

/* mkdraft:func_829064D0 begin */
extern f32 MathUtil_Random_ZeroOne(void);
extern f32 D_829174D8;
extern f32 D_829174DC;
extern u8 D_82919DE0[];

void func_829064D0(s32 arg0, void *arg1) {
    f32 sp24;
    u32 temp_ft1;
    u8 *temp_s0;

    sp24 = (f32)(u32)func_829063EC(200) - 100.0f;
    temp_ft1 = func_829063EC(120);
    temp_s0 = &D_82919DE0[arg0 * 36];
    *(f32 *)(temp_s0 + 8) = *(f32 *)((u8 *)arg1 + 8) + sp24;
    *(f32 *)(temp_s0 + 4) = (f32)temp_ft1 + 60.0f + *(f32 *)((u8 *)arg1 + 4);
    *(f32 *)(temp_s0 + 0) = *(f32 *)((u8 *)arg1 + 0) + (-MathUtil_Random_ZeroOne() * 50.0f - 50.0f);
    *(s16 *)(temp_s0 + 0x10) = (s16)func_829063EC(546) + 728;
    *(s16 *)(temp_s0 + 0x12) = 0;
    *(s16 *)(temp_s0 + 0x14) = -0x4000;
    *(f32 *)(temp_s0 + 0x1C) = (f32)(u32)func_829063EC(2);
    *(s8 *)(temp_s0 + 0x21) = func_829063EC(155) + 99;
    *(s16 *)(temp_s0 + 0x18) = func_829063EC(2) * 182 + 728;
    *(s16 *)(temp_s0 + 0x16) = 0;
    *(f32 *)(temp_s0 + 0xC) = D_829174DC + (f32)(u32)func_829063EC(6) * D_829174D8;
}
/* mkdraft:func_829064D0 end */

void func_82906680(void *arg0) {
    s16 target_speed; // func_82906748 steps each record's s16 at 0x12 toward this value at 0x10.
    s32 i;

    for (i = 0; i != 40; i++) {
        func_829064D0(i, arg0);
        if (i % 5 == 0) {
            target_speed = func_829063EC(1456);
            *(s16 *)(D_82919DE0 + i * 0x24 + 0x10) = target_speed + 10;
        } else {
            target_speed = func_829063EC(728);
            *(s16 *)(D_82919DE0 + i * 0x24 + 0x10) = target_speed + 10;
        }
        *(D_82919DE0 + i * 0x24 + 0x20) = 0;
    }
}

/* mkdraft:func_82906748 begin */
extern u8 D_82919DE0[];
extern s32 Math_StepToS32(s32, s32, s32, s32);
extern void func_829064D0(s32, void *);

void func_82906748(void *arg0) {
    u8 *temp_s0;
    s32 i;

    temp_s0 = D_82919DE0;
    for (i = 0; i != 40; i++, temp_s0 += 0x24) {
        *(s16 *)(temp_s0 + 0x12) = Math_StepToS32(*(s16 *)(temp_s0 + 0x12), *(s16 *)(temp_s0 + 0x10), 0xB6, 0xB6);
        *(s16 *)(temp_s0 + 0x14) = Math_StepToS32(*(s16 *)(temp_s0 + 0x14), 0x4000, -*(s16 *)(temp_s0 + 0x12), *(s16 *)(temp_s0 + 0x12));
        *(u8 *)(temp_s0 + 0x20) = Math_StepToS32(*(u8 *)(temp_s0 + 0x20), 0xFF, 0xA, 0xA);
        if (*(s16 *)(temp_s0 + 0x14) == 0x4000) {
            func_829064D0(i, arg0);
        }
    }
}
/* mkdraft:func_82906748 end */

/* mkdraft:func_82906808 begin */
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_829000CC(void);
extern void func_829000F8(u8, u8, u8, u8);
extern void func_829001E4(u8, u8, u8, u8);
extern void func_829062B0(s32);
extern Gfx *D_800D0510;
extern u8 D_82919DE0[];



void func_82906808(void) {
    u8 *texture;
    u8 *entry;
    s32 i;

    texture = func_8004CA60(func_8004C990(0x93, 0));
    func_829000CC();
    gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureImage(D_800D0510++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, texture);
    gDPSetTile(D_800D0510++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR, 0, 0,
               G_TX_MIRROR, 0, 0);
    gDPLoadSync(D_800D0510++);
    gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 511, 0);
    gDPPipeSync(D_800D0510++);
    gDPSetTile(D_800D0510++, G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR, 0, 0,
               G_TX_MIRROR, 0, 0);
    gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 0x7C, 0x7C);
    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
    gDPSetRenderMode(D_800D0510++, 0x0C184240, 0);
    gDPSetCombine(D_800D0510++, 0x3097FF, 0x5FFEFE38);
    func_829000F8(0xFF, 0xFF, 0xFF, 0xFF);

    entry = D_82919DE0;
    for (i = 0; i != 40; i++, entry += 0x24) {
        func_829001E4(0xFF, entry[0x21], 0, 0xFF);
        func_829062B0(i);
    }
}
/* mkdraft:func_82906808 end */
#endif
