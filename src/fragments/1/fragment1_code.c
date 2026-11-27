#include "global.h"

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern s32 D_835040D8;
extern s32 D_835040DC;
void func_83500020(s32 arg0, s32 arg1) {
    s32 pad[2];
    if (arg0 == 0) {
        D_835040DC = func_8004C990(0x136, 0);
    }
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0, 0, 0, 0x80);
        gDPSetCombine(D_800D0510++, 0xFFB3FF, 0xFFFCFE38);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)D_835040DC));
        gSPDisplayList(D_800D0510++, D_835040D8);
        GeoRender_ApplyMaterialState();
    }
}

extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, s32);
extern u16 D_83503C20;
extern f32 D_80088E50[];

s32 func_83500124(s32 arg0, s32 arg1) {
    func_80038E14(arg1, 0, 0.0f, D_80088E50[D_83503C20 >> 4] * 1700.0f, 0.0f, 0.0f, 0.0f, 0);
    return 0;
}
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_83500198(s32 arg0, void *arg1) {
    s32 pad;
    s32 v28;
    s16 v26;
    s16 v24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &v28, &v26, &v24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(v26 + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(v24 - 0x2000);
    }
    return 0;
}

extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_83500200(s32 arg0, void *arg1) {
    s32 pad;
    s32 v28;
    s16 v26;
    s16 v24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &v28, &v26, &v24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - v26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(v24 + 0x6000);
    }
    return 0;
}

s32 process_geo_layout(s32, s32 *);
extern void PokeIcon_InitResourceArchives();
extern u8 D_83503BEC;
extern u8 D_83503C24;
extern u8 D_83503F30;
extern s32 D_83503F54;
extern s32 D_83503F6C;
extern u8 D_83503F70;
extern s32 MainPool_AllocState(s32, s32);
s32 main_pool_get_available(void);
extern void MainPool_FinalizeAllocation(s32);
void ModelRenderer_InitDisplayRoots(void);
void func_87F02CB0(s32 arg0, s32 arg1);
void func_8003F018(s32 arg0);
void func_8350026C(void) {
    s32 sp1C[3];
    s32 temp_v0;
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C[0] = temp_v0;
    D_83503F54 = process_geo_layout(temp_v0, &D_83503C24);
    D_83503F6C = process_geo_layout(sp1C[0], &D_83503BEC);
    MainPool_FinalizeAllocation(sp1C[0]);
    ModelRenderer_InitDisplayRoots();
    PokeIcon_InitResourceArchives();
    func_87F02CB0((s32) &D_83503F30, 0x64);
    func_8003F018((s32) &D_83503F70);
}

extern u8 *func_87F0328C(u8 *arg0, s32 arg1, f32 x, f32 y, f32 z, f32 scale, s32 arg6);
extern u32 func_8003570C(void);
#define RAND01() (func_8003570C() / 4294967296.0f)
void func_83500300(void) {
    static f32 D_83503CDC = -40.0f;
    static f32 D_83503CE0 = 0.0f;
    static f32 D_83503CE4 = 0.0f;
    static f32 D_83503CE8 = 0.0f;
    static s32 D_83503CEC = 0;
    static s32 D_83503CF0 = 1;
    static s32 D_83503CF4 = 36;
    static s32 D_83503CF8 = 0; // unreferenced .data word
    s32 i;
    s32 count;
    s32 r;
    f32 vx;
    f32 vz;
    u8 *obj;
    u8 *state;
    u8 *col;

    D_83503CE8 = 3.5f;
    D_83503CE0 = 5.0f;
    D_83503CE4 = 0;
    count = 4;
    for (i = 0; i < count; i++) {
        r = (s32)guRandom() % 4;
        if (r < 1) {
            vz = 2.8f;
            vx = 2.8f;
        } else if (r < 2) {
            vx = -2.8f;
            vz = 2.8f;
        } else if (r < 3) {
            vz = -2.8f;
            vx = -2.8f;
        } else {
            vz = -2.8f;
            vx = 2.8f;
        }
        obj = func_87F0328C(&D_83503F30, 0, RAND01() * vz * (40.0f * D_83503CE8),
                            RAND01() * (vx < 0 ? -vx : vx) * (D_83503CF4 * D_83503CE8) + D_83503CDC, 0,
                            (f64)(RAND01() * 0.8f) * D_83503CE8, (func_8003570C() % 9) + D_83503CE0);
        if (obj != NULL) {
            D_83503CEC++;
            if (D_83503CEC >= 126) {
                D_83503CEC = 0;
            }
            state = *(u8 **)(obj + 0x20);
            *(f32 *)(obj + 0x10) = RAND01() * vz * 0;
            *(f32 *)(obj + 0x14) = RAND01() * (vx < 0 ? -vx : vx) * (-1.5 * D_83503CE4);
            *(f32 *)(obj + 0x18) = 0.0f;
            *(f32 *)(state + 0x18) = 1.0f;
            col = *(u8 **)(obj + 0x20);
            col[0x10] = 255;
            col[0x11] = 255;
            col[0x12] = 255;
            col[0x13] = 255;
            col[0x14] = (func_8003570C() % 176) * D_83503CF0 + 80; col[0x15] = 255; col[0x16] = 0; col[0x17] = 255;
        }
    }
}

/* mkdraft:func_83500708 begin */
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_83503AEC;
extern s32 D_83503AD4;
extern f32 D_83503BE8;
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))

// Each packet assigns both words on one source line. With the pair on one line
// IDO 7.1 emits retail's store order here: the w1 store precedes the w0 store
// for every packet except E200001C. Writing each assignment on its own line
// emits w0 before w1 throughout and does not match.


void func_83500708(void) {
    UNUSED s32 pad; // FAKE: unused slots; they place y at sp+0x88 and texture at sp+0x80 (score 18 without pad/pad2)
    s32 y;
    UNUSED s32 pad2;
    s32 texture;
    s32 i;
    u8 *image;

    gSPDisplayList(D_800D0510++, D_80094E38);
    texture = func_8004C990(0x44, 2);
    y = (s32) ((233.0f - 24.0f * D_83503BE8) + ((233.0f > 24.0f * D_83503BE8) ? 0.5f : -0.5f));
    for (i = 0; i != 0x5A00; i += 0xF00) {
        image = func_8004CA60((u8 *) texture);
        gDPPipeSync(D_800D0510++);
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xE200001C; _g->words.w1 = 0x504240; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFA000000; _g->words.w1 = -1U; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFCFFFFFF; _g->words.w1 = 0xFFFCF67B; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFD100000; _g->words.w1 = (u32) &image[i]; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF5100000; _g->words.w1 = 0x07000000; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xE6000000; _g->words.w1 = 0; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF3000000; _g->words.w1 = 0x0777F000; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xE7000000; _g->words.w1 = 0; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF5107800; _g->words.w1 = 0; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF2000000; _g->words.w1 = 0x3BC01C; }
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFA000000; _g->words.w1 = -0xB0U; }
        GfxRect_DrawTextured(D_83503AEC + D_83503AD4, (s16) (s32) ROUND_MAX((f32) y),
                             (s16) (s32) ROUND_MAX(240.0f * D_83503BE8),
                             (s16) (s32) ROUND_MAX(8.0f * D_83503BE8), 0, 0,
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8),
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8), 0);
        { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFA000000; _g->words.w1 = -1U; }
        GfxRect_DrawTextured(*(s16 *) ((u8 *) &D_83503AD4 + 2), (s16) (s32) ROUND_MAX((f32) y),
                             (s16) (s32) ROUND_MAX(240.0f * D_83503BE8),
                             (s16) (s32) ROUND_MAX(8.0f * D_83503BE8), 0, 0,
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8),
                             (s16) (s32) ROUND_MAX(1024.0f / D_83503BE8), 0);
        y = (s32) ((f32) y + 8.0f * D_83503BE8);
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_83500708 end */

extern s16 D_83503E84;
extern s32 D_83503AE0;
extern s32 D_83503AF0;

// Draws six 0xAA0-byte strips of the texture from asset (68, D_83503E84 ? 1 : 0)
// in two passes: pass 0 at prim alpha 80, shifted down by D_83503AF0, then pass 1
// at alpha 255. Strips 0-4 are 136x10 tiles and strip 5 is a 136x4 tile.
// D_83503AE0 is the y before the first strip; D_83503BE8 scales the rectangle
// sizes, the per-strip y step and the two texture scales.
void func_83500C14(void) {
    s32 archive;
    s32 i;
    s32 pass;
    s32 y;
    u8 *texBase;
    u32 shift;

    gSPDisplayList(D_800D0510++, D_80094E38);
    if (D_83503E84 == 0) {
        archive = func_8004C990(68, 0);
    } else {
        archive = func_8004C990(68, 1);
    }
    texBase = func_8004CA60((u8 *)archive);
    gDPPipeSync(D_800D0510++);
    gDPSetRenderMode(D_800D0510++, 0x504240, 0);
    gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
    gDPSetCombine(D_800D0510++, 0xFCFFFFFF, 0xFFFCF67B);
    for (pass = 0; pass != 2; pass++) {
        shift = 0;
        y = D_83503AE0;
        if (pass == 0) {
            gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 80);
            shift = 1;
        } else {
            gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
        }
        for (i = 0; i < 6; i++) {
            y = y + 10.0f * D_83503BE8;
            if (i < 5) {
                gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texBase + i * 0xAA0);
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
                gDPLoadSync(D_800D0510++);
                gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 1359, 0);
                gDPPipeSync(D_800D0510++);
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 34, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
                gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 135 << 2, 9 << 2);
                GfxRect_DrawTextured(ROUND_MAX(320.0f - 68.0f * D_83503BE8),
                                     (s32) ROUND_MAX((f32) y) + *(s32 *) &D_83503AF0 * shift,
                                     ROUND_MAX(136.0f * D_83503BE8), ROUND_MAX(10.0f * D_83503BE8), 0, 0,
                                     ROUND_MAX(1024.0f / D_83503BE8), ROUND_MAX(1024.0f / D_83503BE8), 0);
            } else {
                gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texBase + i * 0xAA0);
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
                gDPLoadSync(D_800D0510++);
                gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 543, 0);
                gDPPipeSync(D_800D0510++);
                gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 34, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
                gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 135 << 2, 3 << 2);
                GfxRect_DrawTextured(ROUND_MAX(320.0f - 68.0f * D_83503BE8),
                                     (s32) ROUND_MAX((f32) y) + *(s32 *) &D_83503AF0 * shift,
                                     ROUND_MAX(136.0f * D_83503BE8), ROUND_MAX(4.0f * D_83503BE8), 0, 0,
                                     ROUND_MAX(1024.0f / D_83503BE8), ROUND_MAX(1024.0f / D_83503BE8), 0);
            }
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}

extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern s32 D_83503AE8;
extern s32 D_83503AF4;
extern f32 D_83503BE8;

#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))

// Draws eight 0xB00-byte pages of the texture strip from asset (68, 3): for
// each page it loads the data with func_8004CA60(func_8004C990(68, 3)),
// uploads it into G_TX_LOADTILE, describes a 176x8 tile at G_TX_RENDERTILE,
// and draws it twice through GfxRect_DrawTextured (prim alpha 80, then 255).
// D_83503AE8 supplies the first row's y (minus 2); D_83503BE8 scales the
// rectangle sizes, the per-row y step and the two texture scales. Byte
// identical to asm/us/nonmatchings/fragments/1/fragment1_code/func_835012C8.s
// and to the retail ROM.


void func_835012C8(void) {
    s32 archive;
    s32 y;
    s32 i;
    u8 *tex;
    u8 *texBase;
    s32 pad;

    gSPDisplayList(D_800D0510++, D_80094E38);
    archive = func_8004C990(68, 3);
    y = D_83503AE8 - 2;
    texBase = func_8004CA60((u8 *)archive);
    gDPPipeSync(D_800D0510++);
    gDPSetRenderMode(D_800D0510++, 0x504240, 0);
    gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
    gDPSetCombine(D_800D0510++, 0xFCFFFFFF, 0xFFFCF67B);
    for (i = 0, tex = texBase; i != 0x5800; i += 0xB00) {
        gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, tex);
        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
        gDPLoadSync(D_800D0510++);
        gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 1407, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 44, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
        gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 175 << 2, 7 << 2);
        gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 80);
        GfxRect_DrawTextured(ROUND_MAX(320.0f - 88.0f * D_83503BE8), (u16)((s32)ROUND_MAX((f32)y) + *(s32 *)&D_83503AF4),
                             ROUND_MAX(176.0f * D_83503BE8), ROUND_MAX(8.0f * D_83503BE8), 0, 0,
                             ROUND_MAX(1024.0f / D_83503BE8), ROUND_MAX(1024.0f / D_83503BE8), 0);
        gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
        GfxRect_DrawTextured(ROUND_MAX(320.0f - 88.0f * D_83503BE8), ROUND_MAX((f32)y),
                             ROUND_MAX(176.0f * D_83503BE8), ROUND_MAX(8.0f * D_83503BE8), 0, 0,
                             ROUND_MAX(1024.0f / D_83503BE8), ROUND_MAX(1024.0f / D_83503BE8), 0);
        tex += 0xB00;
        y = y + 8.0f * D_83503BE8;
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}

extern s32 D_83503BA8;
extern f32 D_835040E0;
extern s32 D_83503AC0[];
extern void func_800226C0(s32);
#define ROUND_MAX3(x) ((x) + ((x) > 0 ? 0.5f : -0.5f))
#define BE0 (*(f32 *)((u8 *)&D_83503BA8 + 0x38))
void func_8350182C(void) {
    s32 archive;
    s32 i;
    s32 pass;
    s32 y;
    u8 *texBase;
    static f32 D_83503CFC = 0.0f;
    static f32 D_83503D00 = 0.0f;

    if (BE0 > 0.0f) {
        D_835040E0 = BE0 + 0.1;
        BE0 -= D_83503CFC * D_83503CFC;
        D_83503CFC = D_83503CFC + 0.2;
    } else if (D_83503AC0[3] == 0) {
        D_83503AC0[3] = 1;
        func_800226C0(0x77);
    }
    if (BE0 < 0.0f) {
        BE0 = 0.0f;
        D_835040E0 = 0.0f;
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    archive = func_8004C990(0x44, 4);
    texBase = func_8004CA60((u8 *)archive);
    gDPSetRenderMode(D_800D0510++, 0x504240, 0);
    gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
    gDPSetCombine(D_800D0510++, 0xFCFF97FF, 0xFF2CFE7F);
    for (pass = 0; pass != 2; pass++) {
        if (pass == 0) {
            D_83503D00 = BE0 + D_83503BE8;
            gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
        } else {
            if (!texBase) {} // FAKE
            D_83503D00 = D_835040E0 + D_83503BE8;
            gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 128);
        }
        y = 190.0f - 28.0f * D_83503D00;
        for (i = 0; i != 0x1C00; i += 0xE00) {
            gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texBase + i);
            gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
            gDPLoadSync(D_800D0510++);
            gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 1791, 0);
            gDPPipeSync(D_800D0510++);
            gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
            gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 63 << 2, 27 << 2);
            GfxRect_DrawTextured(ROUND_MAX3(157.0f - 32.0f * D_83503D00), ROUND_MAX3((f32)y),
                                 ROUND_MAX3(64.0f * D_83503D00), ROUND_MAX3(28.0f * D_83503D00), 0, 0,
                                 ROUND_MAX3(1024.0f / D_83503D00), ROUND_MAX3(1024.0f / D_83503D00), 0);
            y = y + 28.0f * D_83503D00;
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    // FAKE: this dead int ternary takes the last 8 bytes of cfe temps, which puts
    // the rect x rounding temp at sp+0x9C and the float spill at sp+0x8C.
    if (0) { pass = pass + (pass ? 1 : 2); }
}

extern s32 D_83503BB4;
extern s16 D_83503E82;
extern void func_835012C8(void);
extern void func_83500C14(void);
extern void func_83500708(void);
extern void func_8350182C(void);

void func_83501D3C(void) {
    switch (D_83503BB4) {
        case 2:
        case 3:
        case 4:
            func_835012C8();
        case 1:
            func_83500C14();
        case 0:
            func_83500708();
    }
    if (D_83503BB4 >= 2 && D_83503E82 == 1) {
        func_8350182C();
    }
}

extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern s32 func_8004D19C();
extern void func_800226C0(s32);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_87F0DC3C(u8 *);
extern void func_83500300(void);
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_83503BA8;
extern s32 D_83503BBC;
extern s32 D_83503BC4;
extern s32 D_83503BCC;
extern f32 D_83503BE4;
extern s32 D_83503AC0[];
extern s32 D_83503F6C;
extern u8 D_83503F70;
extern u8 D_83503F58[];
extern f32 D_80087E50[];
typedef struct unk_D_83503B00 {
    s32 unk_00[42];
} unk_D_83503B00;
extern unk_D_83503B00 D_83503E88;

#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
#define BA8(off, T) (*(T *)((u8 *)&D_83503BA8 + (off)))

void func_83501DC0(void) {
    // D_83503D04..D_83503D0C and D_83503D14..D_83503D24 are unreferenced
    // .data words between this function's statics.
    static s32 D_83503D04 = 0;
    static s32 D_83503D08 = 0;
    static s32 D_83503D0C = 0;
    static s32 sDir = 1;
    static s32 D_83503D14 = 0;
    static s32 D_83503D18 = 0;
    static s32 sStartIdx = 0;
    static f32 D_83503D20 = 1.0f;
    static s32 D_83503D24 = 0;
    static s32 sPos[2] = { 0xE0, 0x81 };
    static s16 sAngle = 0;
    static s32 sTimer;
    s32 i;
    s32 x1;
    s32 x2;
    s32 y1;
    s32 y2;
    s32 idx;
    s32 n;
    Gfx *gfx;
    s32 m;
    u8 *tex;
    s32 cnt;
    s32 done;
    s32 limit;
    f32 scale;
    s32 y;

    gSPDisplayList(D_800D0510++, D_80094E38);
    func_8004C990(0x136, 0);
    cnt = 0;
    if (BA8(0x14, s32) == 0) {
        BA8(0x20, s32) = 0;
        if (BA8(0x1C, s32) > 0) {
            gfx = D_800D0510++;
            gDPPipeSync(gfx);
            gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, BA8(0x1C, s32));
            gDPSetRenderMode(D_800D0510++, 0x504240, 0);
            gDPSetCombine(D_800D0510++, 0xFCFFB3FF, 0xFF64FE7F);
            func_8004D19C(sPos[0], sPos[1], func_8004C990(0x136, 0), 0, 0);
        }
        idx = sStartIdx;
        BA8(0x18, s32)++;
        for (; idx < 2; idx++) {
            {
                done = 0;
                if (BA8(0x18, s32) < D_83503E88.unk_00[30 + idx]) {
                    if (idx == 0) {} // FAKE
                    continue;
                }
                D_83503E88.unk_00[36 + idx]++;
                if (D_83503E88.unk_00[24 + idx] == 0) {
                    if (D_83503E88.unk_00[6 + idx] < sPos[1] && D_83503E88.unk_00[12 + idx] == 1) {
                        D_83503E88.unk_00[6 + idx] += (s32)ROUND_MAX((f32)D_83503E88.unk_00[36 + idx]);
                    }
                    if (D_83503E88.unk_00[6 + idx] >= sPos[1]) {
                        D_83503E88.unk_00[6 + idx] = sPos[1];
                        D_83503E88.unk_00[12 + idx] = 0;
                        if (idx == 1) {
                            cnt++;
                        }
                        done = 1;
                    }
                } else {
                    if (sPos[1] < D_83503E88.unk_00[6 + idx] && D_83503E88.unk_00[12 + idx] == 1) {
                        D_83503E88.unk_00[6 + idx] -= (s32)ROUND_MAX((f32)D_83503E88.unk_00[36 + idx]);
                    }
                    if (sPos[1] >= D_83503E88.unk_00[6 + idx]) {
                        D_83503E88.unk_00[12 + idx] = 0;
                        D_83503E88.unk_00[6 + idx] = sPos[1];
                        if (idx == 1) {
                            cnt++;
                        }
                        done = 1;
                    }
                }
                if (D_83503E88.unk_00[idx] < sPos[0] && D_83503E88.unk_00[12 + idx] == 0) {
                    D_83503E88.unk_00[idx] += (s32)ROUND_MAX((f32)D_83503E88.unk_00[36 + idx]);
                }
                if (D_83503E88.unk_00[idx] >= sPos[0]) {
                    D_83503E88.unk_00[idx] = sPos[0];
                    D_83503E88.unk_00[12 + idx] = 1;
                    if (idx == 1) {
                        cnt++;
                    }
                    done++;
                }
                if (cnt == 2) {
                    D_83503BBC = 1;
                    sTimer = 1;
                    sStartIdx = 1;
                    func_87F0DC3C(D_83503F58);
                } else {
                    sTimer = 0;
                }
                limit = idx * 0x28 + 0x28;
                gDPPipeSync(D_800D0510++);
                gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 140);
                gDPSetRenderMode(D_800D0510++, 0x504240, 0);
                gDPSetCombine(D_800D0510++, 0xFCFFB3FF, 0xFF64FE7F);
                y1 = (s32)ROUND_MAX((f32)D_83503E88.unk_00[6 + idx]);
                x1 = (s32)ROUND_MAX((f32)D_83503E88.unk_00[idx]);
                x2 = sPos[0] - (x1 - sPos[0]);
                y2 = sPos[1] - (y1 - sPos[1]);
                if (D_83503E88.unk_00[18 + idx] == 0) {
                    n = 1;
                    m = 2;
                } else {
                    n = 2;
                    m = 1;
                }
                if (D_83503BC4 < limit) {
                    for (i = 0; i < 11; i++) {
                        tex = func_8004CA60((u8 *)func_8004C990(0x136, 0));
                        gDPPipeSync(D_800D0510++);
                        gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u8 *)tex + i * 0xF00);
                        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
                        gDPLoadSync(D_800D0510++);
                        gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 1919, 0);
                        gDPPipeSync(D_800D0510++);
                        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
                        gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 191 << 2, 9 << 2);
                        if (m != 2 || i < 6) {
                            GfxRect_DrawTextured((s32)ROUND_MAX((f32)x1), (s32)ROUND_MAX((f32)y1),
                                                 (s32)ROUND_MAX((f32)(0xC0 / n)), 10, 0, 0, 0x400, 0x400, 0);
                        }
                        if (m != 2 || i >= 6) {
                            GfxRect_DrawTextured((s32)ROUND_MAX((f32)(n * 0x60 + x2 - 0x60)), (s32)ROUND_MAX((f32)y2),
                                                 (s32)ROUND_MAX((f32)(0xC0 / n)), 10,
                                                 (s16)((n * 0x300 - 0x300) << 2), 0, 0x400, 0x400, 0);
                        }
                        y1 += 10;
                        y2 += 10;
                    }
                }
                if (done == 2) {
                    func_800226C0(0x125);
                    D_83503BC4 = limit;
                    sStartIdx = idx + 1;
                }
            }
        }
    }
    if (sTimer > 0) {
        sTimer = sTimer + 1;
    }
    if (BA8(0x14, s32) == 1) {
        BA8(0x20, s32) = 1;
        sStartIdx = 0;
        if (sTimer >= 3) {
            if (sDir == 1) {
                BA8(0x3C, f32) = BA8(0x3C, f32) + 0.11;
            }
            if (1.8 <= BA8(0x3C, f32) && sDir == 1) {
                sDir = -1;
            }
            if (sDir == -1) {
                BA8(0x3C, f32) = BA8(0x3C, f32) - 0.11;
            }
            if (BA8(0x3C, f32) < 1.4 && sDir == -1) {
                sDir = 0;
                if (D_83503AC0[4] == 0) {
                    D_83503AC0[4] = 1;
                    func_800226C0(0x66);
                    D_83503BCC = 1;
                    func_8003F114(&D_83503F70, 0, -1, D_83503F6C);
                    ((f32 *)&D_83503F70)[10] = 115.0f;
                    ((f32 *)&D_83503F70)[14] = 3.3f;
                    ((f32 *)&D_83503F70)[13] = ((f32 *)&D_83503F70)[14];
                    ((f32 *)&D_83503F70)[12] = ((f32 *)&D_83503F70)[13];
                }
                D_83503BE4 = 1.4f;
            }
        }
        scale = BA8(0x3C, f32) + 0.4;
        if (BA8(0x24, s32) == 1) {
            n = (s16)(sAngle + 0x400);
            ((f32 *)&D_83503F70)[13] = D_80087E50[(u16)n >> 4] * 0.15 + 3.5;
            ((f32 *)&D_83503F70)[12] = ((f32 *)&D_83503F70)[13]; sAngle = n;
        }
        y = (s32)((184.0f - 55.0f * scale) + ((184.0f > 55.0f * scale) ? 0.5f : -0.5f));
        for (i = 0; i < 11; i++) {
            tex = func_8004CA60((u8 *)func_8004C990(0x136, 0));
            gDPPipeSync(D_800D0510++);
            gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (u8 *)tex + i * 0xF00);
            gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
            gDPLoadSync(D_800D0510++);
            gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 1919, 0);
            gDPPipeSync(D_800D0510++);
            gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
            gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 191 << 2, 9 << 2);
            GfxRect_DrawTextured((s32)((320.0f - 96.0f * scale) + ((96.0f * scale < 320.0f) ? 0.5f : -0.5f)),
                                 (s32)ROUND_MAX((f32)y),
                                 (s32)ROUND_MAX(192.0f * scale),
                                 (s32)ROUND_MAX(10.0f * scale), 0, 0,
                                 (s32)ROUND_MAX(1024.0f / scale),
                                 (s32)ROUND_MAX(1024.0f / scale), 0);
            y = (s32)((f32)y + 10.0f * scale);
        }
    }
    gfx = D_800D0510++;
    gSPDisplayList(gfx, D_80094F50);
    if (BA8(0x24, s32) == 1) {
        func_83500300();
    }
}

/* mkdraft:func_83502BFC begin */
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_83503D34[4];
extern s32 D_83503D44;
extern s32 D_83503D48;
extern s32 D_83503D4C;
extern s32 D_83503BA8;
typedef struct Table4 { s32 a; s32 b; s32 c; s32 d; } Table4;




void func_83502BFC(void)
{
  s32 timer;
  s32 table[4];
  *((Table4 *) table) = *((Table4 *) D_83503D34);
  func_800498C4();
  func_800496A4(0x10, 1);
  Font_EnableTwoCycleTexturing();
  *((s32 *) (((u8 *) (&D_83503BA8)) + 0x28)) += (*((s32 *) (((u8 *) (&D_83503BA8)) + 0x2C))) * 10;
  if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x28))) < 0)
  {
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x28)) = 0;
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x2C)) = 1;
    *((s32 *) (((u8 *) (&D_83503BA8)) + 4)) = (*((s32 *) (((u8 *) (&D_83503BA8)) + 4))) + 1;
  }
  if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x28))) >= 0x100)
  {
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x28)) = 0xFF;
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x2C)) = 0;
  }
  func_8004972C(0xFF, 0xFF, 0xFF, *((s32 *) (((u8 *) (&D_83503BA8)) + 0x28)));
  func_800497E4(0xFF, 0xFF, 0xFF, *((s32 *) (((u8 *) (&D_83503BA8)) + 0x28)));
  if (0) { } // FAKE: diff score 570 without it; the switch scrutinee lands in v0, not retail v1.
  switch (*((s32 *) (((u8 *) (&D_83503BA8)) + 4)))
  {
    case 0:
      func_800495F8(0x140, 0x145, 1, "%s", func_8004C874(0x49, 0));
      break;

    case 1:
      func_800495F8(0x140, 0x145, 1, "%s", func_8004C874(0x49, 1));
      break;

    case 2:
      func_800495F8(0x140, 0x145, 1, "%s", func_8004C874(0x49, 2));
      break;

  }

  Font_DisableTwoCycleTexturing();
  func_800499EC();
  if (0) { } // FAKE: diff score 30 without it; the 0xFF clamp constant lands in a0, not retail a1.
  gSPDisplayList(D_800D0510++, D_80094E38);
  gDPPipeSync(D_800D0510++);
  if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x28))) == 0xFF)
  {
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x30)) = (*((s32 *) (((u8 *) (&D_83503BA8)) + 0x30))) + 0x32;
    if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x30))) >= 0x100)
    {
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0x30)) = 0xFF;
    }
  }
  if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x2C))) < 0)
  {
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x30)) = (*((s32 *) (((u8 *) (&D_83503BA8)) + 0x30))) - 0x32;
  }
  if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x30))) < 0)
  {
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x30)) = 0;
  }
  {
    s32 val;
    timer = D_83503D44 + 1;
    gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0xFF, *((s32 *) (((u8 *) (&D_83503BA8)) + 0x30)));
    gDPSetCombine(D_800D0510++, 0xFFB3FF, 0xFF64FE7F);
    if (timer >= 0x28)
    {
      timer = 0;
    }
    val = table[timer / 10];
    // FAKE: D_83503D34[4] and the words after it are the counter block; 0x10 is the offset
    // of D_83503D44, so this store targets D_83503D44. Naming that symbol directly lets IDO
    // hoist the address into a3 ahead of the divide (diff score 795); this spelling leaves the
    // lui in the func_8004C990 delay slot as retail does.
    ((s32 *) (((u8 *) (&D_83503D34)) + 0x10))[0] = timer;
    func_8004D19C(D_83503D48, D_83503D4C, func_8004C990(0x35, val), 1, 0);
  }
  gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_83502BFC end */

/* mkdraft:func_83502EF0 begin */
extern s32 D_83503BA8;
extern s32 D_83503F50;
extern u8 D_83503F58[];
extern void GfxImage_FillCurrent(void *, u16);
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern void func_80008648(void);
extern void func_800088DC(void);
extern void func_8003C6B8(u8 *);
extern void func_800468A0(s32);
extern void func_83501D3C(void);
extern void func_83501DC0(void);
extern void func_83502BFC(void);
extern void func_87F0DFB4(void *);


void func_83502EF0(void) {
    func_800088DC();
    if (D_83503F50 == 0) {
        GfxImage_FillCurrent(&D_800D0510, 1);
    } else {
        func_8000766C(&D_800D0510, 0, 0, 0x280, 0x1E0);
        func_800468A0(D_83503F50);
    }
    /* Case labels are listed out of numeric order: ido emits the compare chain in
       ascending order with case 3's body inline after the last compare, and the
       remaining bodies in source order. */
    switch (D_83503BA8) {
        case 3:
            switch (*(s32 *)((u8 *)&D_83503BA8 + 8)) {
                case 0:
                    func_83501D3C();
                    break;
                case 1:
                    func_83501DC0();
                    if ((*(s32 *)((u8 *)&D_83503BA8 + 0x14)) == 1) {
                        func_83502BFC();
                    }
                    break;
            }
            break;
        case 1:
            func_83501DC0();
            if ((*(s32 *)((u8 *)&D_83503BA8 + 0x14)) == 1) {
                func_83502BFC();
            }
            break;
        case 2:
            func_83501D3C();
            break;
    }
    GeoRender_AdvanceFrameCounter();
    func_8003C6B8(D_83503F54);
    func_87F0DFB4(&D_83503F58);
    func_80008648();
}
/* mkdraft:func_83502EF0 end */

/* mkdraft:func_83503048 begin */
extern s32 D_83503BA8;

extern s32 D_83503AD4;
extern s32 D_83503AEC;
extern f32 D_83503BE8;
extern f32 D_83503DA0;



void func_83503048(void)
{
  f32 **new_var2;
  f32 new_var;
  f32 *D_83503DA0_ptr = &D_83503DA0;
  f32 temp_fa1;
  f32 temp_ft4;
  f32 var_fv1;
  s32 temp_t2;
  if ((120.0f * D_83503BE8) < 320.0f)
  {
    var_fv1 = 0.5f;
  }
  else
  {
    var_fv1 = -0.5f;
  }
  new_var = *D_83503DA0_ptr;
  temp_fa1 = ((f32) D_83503AD4) + (new_var * new_var);
  temp_ft4 = 320.0f - (120.0f * D_83503BE8);
  if (((f32) ((s32) (var_fv1 + temp_ft4))) <= temp_fa1)
  {
    if (1)
    {
      if ((120.0f * D_83503BE8) < 320.0f)
      {
        var_fv1 = 0.5f;
      }
      else
      {
        var_fv1 = -0.5f;
      }
      D_83503AD4 = (s32) (var_fv1 + temp_ft4);
    }
    D_83503AEC = 0;
    *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) -= 2;
    if (((temp_t2 = *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)), temp_t2 < 0)) != 0)
    {
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 1;
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = 0x1E;
    }
  }
  else
  {
    D_83503AD4 = (s32) temp_fa1;
    new_var2 = &D_83503DA0_ptr;
    new_var = (f32) (((f64) new_var) + 0.5);
    *(*new_var2) = new_var;
  }
}
/* mkdraft:func_83503048 end */

/* mkdraft:func_83503188 begin */
extern s32 D_83503BA8;
extern s32 D_83503AC4;
extern s32 D_83503AD4;
extern s32 D_83503AF0;
extern f32 D_83503BE8;
extern f32 D_83503DA4;
extern void func_800226C0(s32);

// Arena timer state; D_83503BA8+0xC / +0x10 are its two counters.
// func_835034A8 (below in this file) drives the same block.



void func_83503188(void) {
    f32 *D_83503DA4_ptr = &D_83503DA4;
    f32 temp_fa0;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv1;
    
    var_fv0 = 27.0f * D_83503BE8;
    if (var_fv0 < 155.0f) {
        var_fv1 = 0.5f;
    } else {
        var_fv1 = -0.5f;
    }
    var_fa1 = 155.0f - var_fv0;
    temp_fa0 = ((*D_83503DA4_ptr) * (*D_83503DA4_ptr)) + (f32) (*(s32 *) ((u8 *) (&D_83503AD4) + 0xC));
    if ((f32) (s32) (var_fv1 + var_fa1) <= temp_fa0) {
        if (D_83503AC4 == 0) {
            func_800226C0(0x66);
            D_83503AC4 = 1;
            var_fv0 = 27.0f * D_83503BE8;
            var_fa1 = 155.0f - var_fv0;
        }
        if (var_fv0 < 155.0f) {
            var_fv1 = 0.5f;
        } else {
            var_fv1 = -0.5f;
        }
        (*(s32 *) ((u8 *) ((u32) &D_83503AD4) + 0xC)) = (s32) (var_fv1 + var_fa1);
        D_83503AF0 = 0;
        if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) -= 2) < 0) {
            *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 2;
            *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = 0x1E;
        }

    } else {
        (*(s32 *) ((u8 *) (&D_83503AD4) + 0xC)) = (s32) temp_fa0;
        (*D_83503DA4_ptr) = (f32) ((f64) (*D_83503DA4_ptr) + (0.7));
    }
}
/* mkdraft:func_83503188 end */

/* mkdraft:func_83503324 begin */
extern s32 D_83503AC8;
extern f32 D_83503BE8;
extern f32 D_83503DA8;
extern s32 D_83503AF4;
extern s32 D_83503AD4;
extern s32 D_83503BA8;
extern void func_800226C0(s32);



extern f32 D_83503E40;
extern f32 D_83503E44;
extern f64 D_83503E48;

void func_83503324(void) {
    f32 *D_83503DA8_ptr = &D_83503DA8;
    f32 temp_fa0;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fv1;
    f32 var_fv0;

    var_fa1 = D_83503E40;
    // karodo: weights the D_83503DA8 web; diff score 70 without it.
    if (D_83503DA8_ptr && D_83503DA8_ptr) {}
    // karodo: rotates the FPR free list so da8/tgt land in f16/f18; diff score 120 without
    // these six empty statements (and 200 without both this and the dead if above).
    if (1) { } if (1) { } if (1) { } if (1) { } if (1) { } if (1) { }
    var_fv0 = 32.0f * D_83503BE8;
    if (var_fv0 < var_fa1) {
        var_fv1 = 0.5f;
    } else {
        var_fv1 = -0.5f;
    }
    var_fa0 = var_fa1 - var_fv0;
    // Arena timer read: D_83503AD4+0x14 holds the countdown (580 = 10 s of frames).
    temp_fa0 = ((f32) (*((s32 *) (((u8 *) (&D_83503AD4)) + 0x14)))) - ((*D_83503DA8_ptr) * (*D_83503DA8_ptr));
    if (temp_fa0 <= ((f32) ((s32) (var_fv1 + var_fa0)))) {
        if (D_83503AC8 == 0) {
            func_800226C0(0x66);
            var_fa1 = D_83503E44;
            D_83503AC8 = 1;
            var_fv0 = 32.0f * D_83503BE8;
            var_fa0 = var_fa1 - var_fv0;
        }
        // D_83503BA8+0x10 / +0xC are the two arena counters (see func_835034A8 below).
        *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = 0;
        *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 3;
        if (var_fv0 < var_fa1) {
            var_fv1 = 0.5f;
        } else {
            var_fv1 = -0.5f;
        }
        // The (u32) cast is load-bearing: plain (u8 *) &D_83503AD4 folds the store into
        // lui at,%hi + sw %lo, while the cast keeps the base in $v1 and re-materialises it
        // after the call (diff score 340 without it).
        *((s32 *) (((u8 *) ((u32) &D_83503AD4)) + 0x14)) = (s32) (var_fv1 + var_fa0);
        D_83503AF4 = 0;
        return;
    }
    *((s32 *) (((u8 *) (&D_83503AD4)) + 0x14)) = (s32) temp_fa0;
    *D_83503DA8_ptr = (f32) (((f64) (*D_83503DA8_ptr)) + D_83503E48);
}
/* mkdraft:func_83503324 end */

s32 func_800225C4(s32);
extern s32 D_83503BA8;
extern s16 D_83503E80;
void func_835034A8(void)
{
  *((s32 *) (((u8 *) (&D_83503BA8)) + 0x10)) = (*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10))) + 1;
  if (D_83503E80 == 0)
  {
    if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10))) == 110)
    {
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0)) = 3;
      func_800225C4(10);
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 4;
      StageContext_SetClearColor(1);
      StageFade_StartFromTransparent(10);
    }
  }
  else
  {
    if ((*((s32 *) (((u8 *) (&D_83503BA8)) + 0x10))) == 100)
    {
      *((s32 *) (((u8 *) (&D_83503BA8)) + 0xC)) = 4;
      StageContext_SetClearColor(1);
      StageFade_StartFromTransparent(10);
    }
  }
}
extern unk_D_83503B00 D_83503B00;
extern s32 D_83503BB0;
extern u8 D_83503F58[];
extern u8 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromOpaque(s32);
extern void func_87F0DBFC(u8 *, s32, u8, s32);
void func_83503548(void) {
    s32 mode;

    mode = StageContext_GetFadeMode();
    if (1 == mode && D_83503E80 == 1) {
        StageFade_StartFromOpaque(10);
        D_83503BB0 = 1;
        D_83503E88 = D_83503B00;
        func_87F0DBFC(D_83503F58, 0, 150, -1);
        D_83503BA8 = 1;
    }
}

#endif
