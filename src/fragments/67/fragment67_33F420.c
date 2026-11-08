#include "global.h"


#ifdef VERSION_US
extern void func_8004C8C0(s32);
s32 func_8004C990(s32, s32);
extern s32 D_829188F8;
extern s32 D_829188FC;
extern s32 D_82918900;
extern s32 D_82918904;
void func_82902920(void) {
    func_8004C8C0(2);
    D_829188F8 = func_8004C990(2, 0);
    D_829188FC = func_8004C990(2, 1);
    D_82918900 = func_8004C990(2, 5);
    D_82918904 = func_8004C990(2, 6);
}

void func_8290298C(void) {}
void func_8290298C_padding(void) {}

typedef struct unk_D_82911E50_Bytes {
    s8 bytes[4];
} unk_D_82911E50_Bytes;

typedef struct unk_D_82911E50_Pair {
    s32 unk_00;
    s32 unk_04;
} unk_D_82911E50_Pair;

typedef struct unk_D_82911E50 {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ unk_D_82911E50_Bytes unk_05;
    /* 0x09 */ unk_D_82911E50_Bytes unk_09;
    /* 0x0D */ s8 unk_0D[8];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ unk_D_82911E50_Pair *unk_20;
} unk_D_82911E50; // size = 0x24

extern unk_D_82911E50 D_82911E50[];
extern s8 D_829188F0;
extern s8 D_829188F1;
extern s8 D_829188F2;
extern s8 D_829188F3;
extern u8 D_82918960;
extern unk_D_82911E50_Bytes D_82918964;
extern unk_D_82911E50_Bytes D_82918968;
extern s8 D_8291896C;
extern s8 D_8291896D;
extern s8 D_8291896E;
extern s8 D_8291896F;
extern s8 D_82918970;
extern s8 D_82918971;
extern s8 D_82918972;
extern s8 D_82918973;
extern f32 D_82918974;
extern f32 D_82918978;
extern unk_D_82911E50_Pair D_82918980;
// Clears D_829188F0-D_829188F3 and copies record arg0 of D_82911E50 into the
// globals D_82918960-D_82918980.
void func_8290299C(u8 arg0) {
    unk_D_82911E50 *record;

    D_829188F3 = 0;
    D_829188F2 = D_829188F3;
    D_829188F1 = D_829188F2;
    D_829188F0 = D_829188F1;
    record = &D_82911E50[arg0];
    D_82918980.unk_00 = record->unk_20->unk_00;
    D_82918980.unk_04 = record->unk_20->unk_04;
    D_82918960 = record->unk_04;
    D_82918964 = record->unk_05;
    D_82918968 = record->unk_09;
    D_8291896C = record->unk_0D[0];
    D_8291896D = record->unk_0D[1];
    D_8291896E = record->unk_0D[2];
    D_8291896F = record->unk_0D[3];
    D_82918970 = record->unk_0D[4];
    D_82918971 = record->unk_0D[5];
    D_82918972 = record->unk_0D[6];
    D_82918973 = record->unk_0D[7];
    D_82918974 = record->unk_18;
    D_82918978 = record->unk_1C;
}

extern Gfx *D_800D0510;
extern Gfx D_82911F70[];
extern s32 D_82918984;
extern s8 *D_82911E40[4];
extern u8 *func_8004CA60(u8 *);
extern void func_800459AC(s32, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80045DB4(s32, s32, s32, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);

typedef struct Fragment67TextureHeader {
    u16 width, height;
    u8 format, size;
    u16 unk_06;
} Fragment67TextureHeader;
typedef struct Fragment67Rgba {
    u8 r, g, b, a;
} Fragment67Rgba;





void func_82902AC0(u8 arg0) {
    s32 combine_mode;
    u8 i;

    gSPDisplayList(D_800D0510++, D_82911F70);
    gDPSetRenderMode(D_800D0510++, G_RM_PASS, G_RM_CLD_SURF2);
    combine_mode = *(s32 *)D_82911E50[arg0].unk_00;
    switch (combine_mode) {
    case 0:
        gDPSetCombineLERP(D_800D0510++, TEXEL0, TEXEL1, PRIM_LOD_FRAC, TEXEL1, 1, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED);
        break;
    case 1:
        gDPSetCombineLERP(D_800D0510++, NOISE, SHADE, PRIM_LOD_FRAC, TEXEL1, 1, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, COMBINED, ENVIRONMENT, 0, 0, 0, COMBINED);
        break;
    }
    gDPSetPrimColor(D_800D0510++, 0, D_82918960, ((Fragment67Rgba *)&D_82918964)->r,
                    ((Fragment67Rgba *)&D_82918964)->g, ((Fragment67Rgba *)&D_82918964)->b,
                    ((Fragment67Rgba *)&D_82918964)->a);
    gDPSetEnvColor(D_800D0510++, ((Fragment67Rgba *)&D_82918968)->r, ((Fragment67Rgba *)&D_82918968)->g,
                   ((Fragment67Rgba *)&D_82918968)->b, ((Fragment67Rgba *)&D_82918968)->a);
    D_829188F0 += D_8291896C;
    D_829188F1 += D_8291896D;
    D_829188F2 += D_8291896E;
    D_829188F3 += D_8291896F;
    for (i = 0; i < 4; i++) {
        if (*D_82911E40[i] < 0) {
            *D_82911E40[i] = *D_82911E40[i] + 128;
        } else if (*D_82911E40[i] >= 128) {
            *D_82911E40[i] = *D_82911E40[i] - 128;
        }
    }
    func_800459AC((s32)func_8004CA60((u8 *)D_82918980.unk_00),
                  ((Fragment67TextureHeader *)D_82918980.unk_00)->format,
                  ((Fragment67TextureHeader *)D_82918980.unk_00)->size,
                  ((Fragment67TextureHeader *)D_82918980.unk_00)->width,
                  ((Fragment67TextureHeader *)D_82918980.unk_00)->height, 1, 0, 0, 0, 5, 5,
                  D_82918970, D_82918971);
    func_80045DB4((s32)func_8004CA60((u8 *)D_82918984), 256, 1,
                  ((Fragment67TextureHeader *)D_82918984)->format,
                  ((Fragment67TextureHeader *)D_82918984)->size,
                  ((Fragment67TextureHeader *)D_82918984)->width,
                  ((Fragment67TextureHeader *)D_82918984)->height, 1, 0, 0, 0, 5, 5, D_82918972,
                  D_82918973);
    gDPSetTileSize(D_800D0510++, 0, D_829188F0, D_829188F1, D_829188F0 + 124, D_829188F1 + 124);
    gDPSetTileSize(D_800D0510++, 1, D_829188F2, D_829188F3, D_829188F2 + 124, D_829188F3 + 124);
}

/* mkdraft:func_82902EC0 begin */
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern void func_82902AC0(u8);
extern f32 D_82918974;
extern f32 D_82918978;



void func_82902EC0(u8 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    func_82902AC0(arg0);
    GfxRect_DrawTextured(arg1, arg2, arg3, arg4, 0, 0, (s16) (s32) (((D_82918974 * 1024.0f * 32.0f) / (f32) arg3) + ((((D_82918974 * 1024.0f * 32.0f) / (f32) arg3) > 0.0f) ? 0.5f : -0.5f)), (s16) (s32) (((D_82918978 * 1024.0f * 32.0f) / (f32) arg4) + ((((D_82918978 * 1024.0f * 32.0f) / (f32) arg4) > 0.0f) ? 0.5f : -0.5f)), 0);
}
/* mkdraft:func_82902EC0 end */
#endif
