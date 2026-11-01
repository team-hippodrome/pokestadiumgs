#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern f32 D_80087E50[];
extern f32 D_80088E50[];
void func_82902FE0(f32 *arg0, f32 *arg1, s16 arg2) {
    s32 index;

    index = (u16)arg2 >> 4;
    arg0[0] = arg1[0] * D_80088E50[index] + arg1[2] * D_80087E50[index];
    arg0[2] = -arg1[0] * D_80087E50[index] + arg1[2] * D_80088E50[index];
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_33FAE0/func_82903058.s")
#endif

#ifdef VERSION_US
extern u8 D_22E0;
extern u8 D_49B780;
extern u8 D_82919CE0;
void func_80003F74(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
extern void func_8290325C(void *);
extern void func_82903298(void *);
extern void func_829034D8();
extern void func_829035C4();
extern void func_8290367C();
extern u8 D_82919D48;
void func_80003F74(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
void func_829031F4(void *arg0) {
    u8 *temp_a1;

    temp_a1 = ((s32) (((*(s16 *)((u8 *)(arg0) + (0x106C))) * 0x30) - 0x30 + &D_22E0) & 0xFFFFFF) + &D_49B780;
    func_80003F74(&D_82919CE0, temp_a1, temp_a1 + 0x30, 0);
}
#endif

#ifdef VERSION_US
extern void PokeIcon_InitResourceArchives(void);
extern void func_8003F018(s32);
extern s32 PokeIcon_AllocLoadContext(s32);
void func_8290325C(void *arg0) {
    PokeIcon_InitResourceArchives();
    func_8003F018((s32)((u8 *)arg0 + 4));
    *(s32 *)arg0 = PokeIcon_AllocLoadContext(5);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82903298 begin */
extern void *D_82919C14;
extern u8 *D_82919C18;
extern f32 D_82919CE8;
extern u16 Pokemon_GetDisplaySpecies(u8 *);
extern void func_8003F1DC(void *);
extern s32 func_8006456C(u16);
extern void func_800428F8(s32);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F9AC(void *, s16, u16);
extern void func_8003F2C4(s32, void *, s32);
extern void Vec3s_SetComponents(void *, s16, s16, s16);
extern void *Vec3f_SetComponentsDuplicate(void *, f32, f32, f32);
// Four-byte color adjustment word func_8003F5AC writes through its first argument and
// func_80041FD0 reads by value.
//@include/229E0.h
typedef union { s32 word; s8 bytes[4]; } Func80041FA0State;
extern void func_8003F5AC(Func80041FA0State *, u8 *);
extern s32 func_80041FD0(s32, u16, Func80041FA0State, s32);
// Row of the table D_82919C14 points at, selected by the mode byte at arg0+0x1070; 0x58 bytes
// per row. D_82919C18 receives the address of the Pokemon record at row offset 8.
typedef struct {
    u8 unk_00[8];
    u8 unk_08[0x50];
} unk_D_82919C14_000;



void func_82903298(void *arg0) {
    u8 *model;
    s32 variant;
    Func80041FA0State adjustment;

    model = (u8 *)arg0 + 4;
    D_82919C18 = ((unk_D_82919C14_000 *)D_82919C14)[*(u8 *)((u8 *)arg0 + 0x1070)].unk_08;
    *(u16 *)((u8 *)arg0 + 0x106C) = Pokemon_GetDisplaySpecies(D_82919C18);
    func_8003F1DC(model);
    func_8003F5AC(&adjustment, D_82919C18);
    variant = func_8006456C(*(u16 *)(D_82919C18 + 0x16));
    func_80041FD0(*(s32 *)((u8 *)arg0 + 0), *(u16 *)((u8 *)arg0 + 0x106C), adjustment, variant);
    func_800428F8(*(s32 *)((u8 *)arg0 + 0));
    func_8003F114(model, 0, *(s16 *)((u8 *)arg0 + 0x106C),
                  **(s32 **)(*(u8 **)((u8 *)*(s32 *)((u8 *)arg0 + 0) + 0x38) + 8));
    func_8003F9AC(model, *(s16 *)((u8 *)arg0 + 0x106C), *(u16 *)(D_82919C18 + 0x16));
    func_8003F2C4(*(s32 *)((u8 *)arg0 + 0), model, 0);
    Vec3s_SetComponents((u8 *)arg0 + 0x22, 0, -0x4000, 0);
    Vec3f_SetComponentsDuplicate((u8 *)arg0 + 0x28, 0.0f, 0.0f, 0.0f);
    func_829031F4(arg0);
    *(f32 *)((u8 *)arg0 + 0x2C) += D_82919CE8;
}
/* mkdraft:func_82903298 end */
#endif

#ifdef VERSION_US
extern f64 D_82917438;
void func_829033DC(f32 *arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    f64 temp_fv1;
    temp_fv0 = *arg0;
    *arg0 = ((arg1 - temp_fv0) * arg2) + temp_fv0;
    temp_fv1 = (f64)*(volatile f32 *)arg0;
    if ((temp_fv1 < D_82917438) && (-0.001 < temp_fv1)) {
        *arg0 = 0.0f;
    }
}
#endif

#ifdef VERSION_US
s32 main_pool_get_available();
s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
void *func_80004B4C(s32, s32);
extern void func_829061CC(s32, void *, s32 (*)(s32, s32));
extern void main_pool_push_state(s32);
extern s32 D_82919D14;
extern s32 D_82919D24;
void func_82903444(void) {
    s32 sp1C;
    s32 sp18;
    s32 temp_v0;

    main_pool_push_state(0x53544144);
    sp18 = (s32)func_80004B4C(D_82919D14, D_82919D24);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    func_829061CC(D_82919D24, (void *)temp_v0, (s32 (*)(s32, s32))sp18);
    MainPool_FinalizeAllocation(sp1C);
}
#endif

#ifdef VERSION_US
void func_829034B0(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0x34))) = 20.0f;
    (*(f32 *)((u8 *)(arg0) + (0x38))) = 6400.0f;
    (*(f32 *)((u8 *)(arg0) + (0x2C))) = 45.0f;
}
#endif

#ifdef VERSION_US
extern u8 D_82918990[];
extern void *D_82919C38;
extern void *D_82919DC4;
extern void func_829034B0(void *);
extern void func_82903058(void *, s32);
void func_829034D8(void) {
    D_82919C38 = *(void **)((u8 *)D_82919DC4 + 0xC);
    func_829034B0(D_82919C38);
    func_82903058(D_82918990, 0);
}
#endif

#ifdef VERSION_US
extern f32 D_82912098;
extern f32 D_8291209C;
extern f32 D_829120A0;
extern s16 D_82919D2E;
extern s16 D_82919D30;
extern f32 D_82919D34;
extern void *Vec3f_SetComponentsDuplicate(void *, f32, f32, f32);
extern void func_800371B4(void *, void *, f32, s16, s32);
void func_8290351C(void) {
    Vec3f_SetComponentsDuplicate((u8 *)D_82919C38 + 0xB4, D_82912098, D_8291209C, D_829120A0);
    *(f32 *)((u8 *)D_82919C38 + 0x2C) = 30.0f;
    D_82919D34 = 800.0f;
    D_82919D2E = 0;
    D_82919D30 = -0x4000;
    func_800371B4((u8 *)D_82919C38 + 0xB4, (u8 *)D_82919C38 + 0xA8, D_82919D34, D_82919D2E, D_82919D30);
}
#endif

#ifdef VERSION_US
extern void *D_82919A08;
extern s32 D_82919D1C;
extern s32 D_82919C10;
extern f32 D_82911FD4[];
extern void func_8003F114(void *, s32, s32, s32);
extern void Vec3s_SetComponents(void *, s16, s16, s16);
void func_829035C4(u8 *arg0) {
    D_82919A08 = arg0 + 0x34C;
    func_8003F018((s32)D_82919A08);
    func_8003F114(D_82919A08, 0, -1, D_82919D1C);
    Vec3f_SetComponentsDuplicate((u8 *)D_82919A08 + 0x24, 0.0f, *(f32 *)((u8 *)D_82911FD4 + D_82919C10 * 0x14), 0.0f);
    Vec3s_SetComponents((u8 *)D_82919A08 + 0x1E, 0, -0x8000, 0);
    *((u8 *)D_82919A08 + 1) &= 0xFFFE;
    *(s16 *)((u8 *)&D_82919A08 + 0x38) = 0;
    *(f32 *)((u8 *)&D_82919A08 + 0x30) = 0.0f;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_33FAE0/func_8290367C.s")
#endif

#ifdef VERSION_US
void func_8290379C(void *arg0) {
    func_829035C4(arg0);
    (*(s16 *)((u8 *)(arg0) + (0x1068))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1072))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1070))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x106C))) = -1;
    (*(s8 *)((u8 *)(&D_82919D48) + (0))) = 0;
    (*(f32 *)((u8 *)(&D_82919D48) + (4))) = 0.0f;
    (*(f32 *)((u8 *)(&D_82919D48) + (8))) = 0.0f;
    func_8290325C(arg0);
    func_82903298(arg0);
    func_8290367C();
    func_829034D8();
}
#endif

#ifdef VERSION_US
// Close to Pokemon Stadium's GalleryUI_DrawGradientQuad; GS takes the alpha as u8, does not
// clear G_FOG, and adds G_SHADING_SMOOTH to the geometry mode.
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
void func_82903808(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    GfxImage *temp_s1 = func_8000731C();
    Vtx *temp_s2 = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    Mtx *sp84 = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    Vp *sp80 = Gfx_AllocDisplayList(sizeof(Vp) * 1);

    Gfx_SetViewportDimensions(sp80, temp_s1->width, temp_s1->height);

    gSPViewport(D_800D0510++, (u32)sp80 & 0x1FFFFFFF);

    guOrtho(sp84, 0.5f, temp_s1->width - 0.5f, temp_s1->height - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);

    Gfx_SetVertexAttributes(&temp_s2[0], arg0, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[1], arg0 + arg2, arg1, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[2], arg0, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);
    Gfx_SetVertexAttributes(&temp_s2[3], arg0 + arg2, arg1 + arg3, -1, 0, 0, 0, 0, 0, arg4);

    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
    gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_LIGHTING);
    gSPSetGeometryMode(D_800D0510++, G_SHADE | G_SHADING_SMOOTH);
    gDPSetCombineMode(D_800D0510++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(D_800D0510++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPPerspNormalize(D_800D0510++, 0xFFFF);
    gSPMatrix(D_800D0510++, (u32)sp84 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(D_800D0510++, (u32)&D_80094890 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(D_800D0510++, (u32)temp_s2 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(D_800D0510++, 0, 2, 3, 0, 0, 3, 1, 0);
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_80094DB8[];
extern u8 D_80094D90[];
extern void Gfx_FillRectRgb(s16, s16, s16, s16, u8, u8, u8);
extern void Gfx_FillRectRgba(s16, s16, s16, s16, u8, u8, u8, u8);
void func_82903BA4(void) {
    gSPDisplayList(D_800D0510++, D_80094DB8);
    gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFE793C);
    gDPSetRenderMode(D_800D0510++, 0x00504240, 0);
    Gfx_FillRectRgba(0, 0x1C, 0x140, 4, 0, 0, 0, 0);
    Gfx_FillRectRgba(0, 0xD0, 0x140, 4, 0, 0, 0, 0);
    gSPDisplayList(D_800D0510++, D_80094D90);
    Gfx_FillRectRgb(0, 0, 0x140, 0x1E, 0, 0, 0);
    Gfx_FillRectRgb(0, 0xD2, 0x140, 0x1E, 0, 0, 0);
}
#endif

#ifdef VERSION_US
extern s32 D_82919C10;
extern void *D_82919D18;
extern u8 D_82911FDD[];
extern s32 D_82911FA0[];
extern s32 func_8004C990(s32, s32);
extern void func_829000CC(void);
extern void func_829000F8(u8, u8, u8, u8);
extern void func_829001E4(u8, u8, u8, u8);
extern void func_8004D19C(s32, s32, void *, s32, s32);
void func_82903CDC(void *arg0) {
    if (((u8 *)arg0)[0x18] & 1) {
        D_82919D18 = (void *)func_8004C990(0x43, ((s32 *)D_82911FA0)[((u8 *)D_82911FDD)[D_82919C10 * 0x14]]);
        func_829000CC();
        func_829000F8((s32)((u8 *)arg0)[1], (s32)((u8 *)arg0)[3], (s32)((u8 *)arg0)[5], (s32)((u8 *)arg0)[0x19]);
        func_829001E4((s32)((u8 *)arg0)[7], (s32)((u8 *)arg0)[9], (s32)((u8 *)arg0)[0xB], (s32)((u8 *)arg0)[0x19]);
        func_8004D19C((s16)(s32)*(f32 *)((u8 *)arg0 + 0xC) - ((s32)*(u16 *)D_82919D18 / 2), 0x10, D_82919D18, 0, 0);
    }
}
#endif

#ifdef VERSION_US
extern s32 D_82919C10;
extern void *D_82919D18;
extern u8 D_82911FDF[];
extern s32 D_82911FC0[];
extern s32 func_8004C990(s32, s32);
extern void func_829000CC(void);
extern void func_829000F8(u8, u8, u8, u8);
extern void func_829001E4(u8, u8, u8, u8);
extern void func_8004D19C(s32, s32, void *, s32, s32);
void func_82903DC0(void *arg0) {
    u8 *base;
    if (((u8 *)arg0)[0x18] & 1) {
        base = (u8 *)D_82911FDF;
        D_82919D18 = (void *)func_8004C990(0x43, ((s32 *)D_82911FC0)[base[D_82919C10 * 0x14]]);
        func_829000CC();
        func_829000F8(0xFF, 0xFF, 0xFF, 0xFF);
        func_829001E4(0xFF, 0, 0, 0xFF);
        func_8004D19C(0x1A, 9, D_82919D18, 0, 0);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_82911FDE[];
extern s32 D_82911FB0[];
extern void *D_82919C14;
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, void *, s32, s32);
extern void func_829000CC(void);
extern void func_829000F8(u8, u8, u8, u8);
extern void func_829001E4(u8, u8, u8, u8);
void func_82903E70(void *arg0) {
    if (((u8 *)arg0)[0x18] & 1) {
        D_82919D18 = (void *)func_8004C990(0x43, ((s32 *)D_82911FB0)[((u8 *)D_82911FDE)[D_82919C10 * 0x14]]);
        func_829000CC();
        func_829000F8((s32)((u8 *)arg0)[1], (s32)((u8 *)arg0)[3], (s32)((u8 *)arg0)[5], (s32)((u8 *)arg0)[0x19]);
        func_829001E4((s32)((u8 *)arg0)[7], (s32)((u8 *)arg0)[9], (s32)((u8 *)arg0)[0xB], (s32)((u8 *)arg0)[0x19]);
        func_8004D19C((s16)(s32)*(f32 *)((u8 *)arg0 + 0xC) - ((s32)*(u16 *)D_82919D18 / 2), 0x2C, D_82919D18, 0, 0);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, void *, s32, s32);
extern void func_829000CC(void);
extern void func_829000F8(u8, u8, u8, u8);
extern void func_829001E4(u8, u8, u8, u8);
void func_82903F54(void *arg0) {
    if (((u8 *)arg0)[0x18] & 1) {
        D_82919D18 = (void *)func_8004C990(0x43, 4);
        func_829000CC();
        func_829000F8((s32)((u8 *)arg0)[1], (s32)((u8 *)arg0)[3], (s32)((u8 *)arg0)[5], (s32)((u8 *)arg0)[0x19]);
        func_829001E4((s32)((u8 *)arg0)[7], (s32)((u8 *)arg0)[9], (s32)((u8 *)arg0)[0xB], (s32)((u8 *)arg0)[0x19]);
        if (*(u16 *)D_82919C14 == 2) {
            func_8004D19C((s16)(s32)*(f32 *)((u8 *)arg0 + 0xC) - ((s32)*(u16 *)D_82919D18 / 2), 0x9E, D_82919D18, 0, 0);
            return;
        }
        func_8004D19C((s16)(s32)*(f32 *)((u8 *)arg0 + 0xC) - ((s32)*(u16 *)D_82919D18 / 2), 0xAC, D_82919D18, 0, 0);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_82919D10;
extern u8 D_82917430[];
extern void func_8004C594(s32, s32);
extern s32 func_8004C8A0(void *, s32, s32, s32);
extern s32 func_80049148(s32, s32, s32);
extern void func_82903808(s32, s32, s32, s32, u8);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_800495F8(s32, s32, s32, void *, void *);
extern void func_800499EC(void);
void func_82904070(void) {
    s32 buffer[16];
    s32 value;
    if (*(u16 *)D_82919C14 == 2) {
        func_8004C594(3, D_82919D10);
        value = func_80049148(1, 0, func_8004C8A0(buffer, 0x40, 0x33, 0)) + 0xA;
        func_82903808(0xA0 - (value / 2), 0xD0, value, 0x10, 0x32);
        func_800498C4();
        func_800496A4(1, 0);
        func_80049148(1, 0, func_8004C8A0(buffer, 0x40, 0x33, 0));
        func_800495F8(0xA0, 0xD3, 1, D_82917430, buffer);
        func_800499EC();
    }
}
#endif

#ifdef VERSION_US
extern void func_82906808(void);
extern s16 D_829199F8;
extern u8 D_82919BD8[];
extern void func_82903CDC(void *arg0);
extern void func_82903DC0(void *arg0);
extern void func_82903E70(void *arg0);
extern void func_82903F54(void *arg0);
extern void func_82904070(void);
extern u8 D_82919A88[];
extern u8 D_82919AF8[];
extern u8 D_82919B68[];
void func_82904160(void) {
    u8 *end;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    func_82906808();
    if (D_829199F8 == 10) { func_82904070(); }
    p1 = D_82919A88; p2 = D_82919AF8; p3 = D_82919B68; end = D_82919BD8;
    do {
        func_82903CDC(p1); func_82903E70(p2); func_82903F54(p3);
        p3 += 0x1C; p1 += 0x1C; p2 += 0x1C;
    } while (p3 != end);
    func_82903DC0(end);
}
#endif

#ifdef VERSION_US
extern void BgStage_DrawFrame(void);
extern void func_829060BC(void);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(s32);
extern void func_82907274(s32);
extern void func_82904160(void);
extern void func_80008648(void);
extern s16 D_829199FC;
void func_82904208(void) {
    BgStage_DrawFrame();
    func_829060BC();
    GeoRender_AdvanceFrameCounter();
    switch (D_829199F8) {
        case 0:
        case 1:
        case 2:
            Geo_RenderRootNode((s32)D_82919DC4);
            func_82907274(D_829199FC);
            func_82903BA4();
            break;
        case 7:
        case 8:
        case 9:
        case 10:
            Geo_RenderRootNode((s32)D_82919DC4);
            func_82904160();
            break;
    }
    func_80008648();
}
#endif

#ifdef VERSION_US
void func_829042A4(f32 *arg0, f32 arg1, f32 arg2) {
    f32 temp_fv0;
    f64 temp_fv1;
    temp_fv0 = *arg0;
    *arg0 = ((arg1 - temp_fv0) * arg2) + temp_fv0;
    temp_fv1 = (f64)*(volatile f32 *)arg0;
    if ((temp_fv1 < 0.001) && (-0.001 < temp_fv1)) {
        *arg0 = 0.0f;
    }
}
#endif

#ifdef VERSION_US
typedef struct Rec28_82912DB8 {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char pad10[4];
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} Rec28_82912DB8;

extern Rec28_82912DB8 D_82912DB8[];
extern f32 D_82919CE4;

/* mkdraft:func_8290430C begin */
void func_8290430C(u8 *arg0) {
    (*(s16 *)((u8 *)&D_82919C38 + 0x3C)) = D_82912DB8[arg0[0x1070]].unk_08;
    (*(s16 *)((u8 *)&D_82919C38 + 0x3E)) = (*(s16 *)((u8 *)arg0 + 0x24)) + D_82912DB8[arg0[0x1070]].unk_0A * -1;
    (*(f32 *)((u8 *)&D_82919C38 + 0x40)) = D_82912DB8[arg0[0x1070]].unk_0C * D_82919CE4;
    (*(f32 *)((u8 *)&D_82919C38 + 0x4C)) = D_82912DB8[arg0[0x1070]].unk_14;
    (*(f32 *)((u8 *)&D_82919C38 + 0x48)) = D_82912DB8[arg0[0x1070]].unk_18;
}
/* mkdraft:func_8290430C end */
#endif

#ifdef VERSION_US
/* mkdraft:func_829043B4 begin */
extern u8 D_82919C88[];
extern void func_80037120(void *, void *, f32 *, s16 *, s16 *);
extern f32 Math_StepToF(f32, f32, f32, f32);

// Per-frame update of the D_82919C38 record. Captures 0xAC with a 6.0 floor into
// speed[0], writes Math_StepToF(0x44, 0x4C, 0x48, 0x48) back to 0x44, fills `eye`
// from the 0x3C/0x3E rotation, copies the pointee's 0xA8 vector into `position`,
// calls func_80037120 to obtain the distance/rotation pair for eye vs position,
// then calls func_800371B4 again with &position, pointee+0xA8 and the scale
// distance * 0x44 * 0.7f. The trailing blocks decay 0xAC 0.85 of the way back to
// 6.0 from the captured speed[0], the second one only while 6.0 < 0xAC <= 7.0.



void func_829043B4(u8 *arg0) {
    typedef struct { f32 x; f32 y; f32 z; } V3;
    V3 eye;
    V3 position;
    f32 distance[1]; // FAKE: one-element array read as distance[0]; diff score 20 without it.
    s16 rotation[2];
    f32 speed[2];
    f32 padding[2]; // FAKE: unused, reserves retail's 0x68-byte frame; diff score 114 without it.

    func_8290430C(arg0);
    if (*(f32 *)((u8 *)D_82919C38 + 0xAC) >= 6.0f) {
        speed[0] = *(f32 *)((u8 *)D_82919C38 + 0xAC);
    } else {
        speed[0] = 6.0f;
    }
    func_829042A4((f32 *)((u8 *)D_82919C38 + 0x2C), *(f32 *)((u8 *)&D_82919C38 + 0x88), 0.02f);
    *(f32 *)((u8 *)&D_82919C38 + 0x44) =
        Math_StepToF(*(f32 *)((u8 *)&D_82919C38 + 0x44), *(f32 *)((u8 *)&D_82919C38 + 0x4C),
                     *(f32 *)((u8 *)&D_82919C38 + 0x48), *(f32 *)((u8 *)&D_82919C38 + 0x48));
    func_800371B4(D_82919C88, &eye, *(f32 *)((u8 *)&D_82919C38 + 0x40),
                  *(s16 *)((u8 *)&D_82919C38 + 0x3C), *(s16 *)((u8 *)&D_82919C38 + 0x3E));
    Vec3f_SetComponentsDuplicate(&position, *(f32 *)((u8 *)D_82919C38 + 0xA8),
                                 *(f32 *)((u8 *)D_82919C38 + 0xAC), *(f32 *)((u8 *)D_82919C38 + 0xB0));
    func_80037120(&position, &eye, distance, &rotation[0], &rotation[1]);
    func_800371B4(&position, (u8 *)D_82919C38 + 0xA8,
                  *(f32 *)((u8 *)&D_82919C38 + 0x44) * distance[0] * 0.7f, rotation[0], rotation[1]);
    if (*(f32 *)((u8 *)D_82919C38 + 0xAC) <= 6.0f) {
        *(f32 *)((u8 *)D_82919C38 + 0xAC) = (speed[0] - 6.0f) * 0.85f + 6.0f;
    }
    if (*(f32 *)((u8 *)D_82919C38 + 0xAC) <= 7.0f && *(f32 *)((u8 *)D_82919C38 + 0xAC) > 6.0f) {
        *(f32 *)((u8 *)D_82919C38 + 0xAC) = (speed[0] - 6.0f) * 0.85f + 6.0f;
    }
}
/* mkdraft:func_829043B4 end */
#endif

void func_82904554(void) {
}

#ifdef VERSION_US
typedef struct S1_unk_D_86002F58_004_000_010_024 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk02[0x6];
    /* 0x08 */ struct S1_unk_D_86002F58_004_000_004* unk_08;
} S1_unk_D_86002F58_004_000_010_024;
typedef union S1_arg1_func_80010CA8 {
    struct {
        /* 0x00 */ s16 unk_00;
        /* 0x02 */ s8 unk_02;
        /* 0x03 */ s8 unk_03;
    };
    u32 raw;
} S1_arg1_func_80010CA8;
typedef struct S1_unk_D_86002F58_004_000_010 {
    /* 0x00 */ u8 configFlags; // PokeIcon_AllocFramebuffers's arg0: bit0=frame-load enabled, bit1=background-load enabled, bit2=double-buffered, bit3=quad-buffered
    /* 0x01 */ u8 pendingFlags; // bit0=frame load pending, bit1=background load pending (PokeIcon_RequestFrameLoad/RequestBackgroundLoad/ApplyLoadResult)
    /* 0x02 */ u8 activeVariant; // index into framebuffers[], flipped by configFlags bit2 in PokeIcon_RequestFrameLoad
    /* 0x04 */ s32 framebuffers[1]; // declared size undersells - up to 5 entries when configFlags bit3 is set (PokeIcon_AllocFramebuffers)
    /* 0x08 */ char pad8[0x10];
    /* 0x18 */ s32 backgroundBuffer; // PokeIcon_RequestBackgroundLoad's poolPtr
    /* 0x1C */ s32 frameResultSize; // PokeIcon_ApplyLoadResult's case 1: poolSize
    /* 0x20 */ s32 backgroundResultSize; // case 2: poolSize
    /* 0x24 */ S1_unk_D_86002F58_004_000_010_024* lastLoadedFragment; // case 1: result; PokeIcon_RequestFrameLoad reuses the load if this matches the requested species
    /* 0x28 */ s32 backgroundResult; // case 2: result
    /* 0x2C */ S1_arg1_func_80010CA8 colorAdjust; // cached alongside lastLoadedFragment for the reuse check
    /* 0x30 */ OSMesgQueue frameQueue;
    /* 0x48 */ OSMesg frameMsgBuf;
    /* 0x4C */ char pad4C[0x4];
    /* 0x50 */ OSMesgQueue backgroundQueue;
    /* 0x68 */ OSMesg backgroundMsgBuf;
    /* 0x6C */ char pad6C[0x4];
} S1_unk_D_86002F58_004_000_010;
typedef struct S1_unk_D_86002F58_004_000_004 {
    /* 0x00 */ struct S1_unk_D_86002F58_004_000_004* unk_00[4];
    /* 0x10 */ struct S1_unk_D_86002F58_004_000_00C* unk_10;
    /* 0x14 */ S1_unk_D_86002F58_004_000_010* unk_14;
} S1_unk_D_86002F58_004_000_004;
typedef struct S1_unk_D_86002F58_004_000_00C_028 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char pad6[6];
    /* 0x0C */ s32* unk_0C;
    /* 0x10 */ s32* unk_10;
} S1_unk_D_86002F58_004_000_00C_028;
typedef S1_unk_D_86002F58_004_000_00C_028* (*S1_unk_D_86002F58_004_000_00C_028_func)(s32, s32);
typedef struct S1_unk_D_86002F58_004_000_00C {
    /* 0x00 */ S1_unk_D_86002F58_004_000_004 unk_00;
    /* 0x18 */ char unk_18[0x10];
    /* 0x28 */ S1_unk_D_86002F58_004_000_00C_028_func unk_28;
} S1_unk_D_86002F58_004_000_00C;
typedef struct S1_unk_D_86002F58_004_000_000 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ struct S1_unk_D_86002F58_004_000_000* unk_04;
    /* 0x08 */ struct S1_unk_D_86002F58_004_000_000* unk_08;
    /* 0x0C */ S1_unk_D_86002F58_004_000_00C* unk_0C;
    /* 0x10 */ S1_unk_D_86002F58_004_000_010* unk_10;
    /* 0x14 */ s32 unk_14;
} S1_unk_D_86002F58_004_000_000;
typedef struct S1_Vec3s {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} S1_Vec3s;
typedef struct S1_Vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} S1_Vec3f;
typedef union S1_Color_RGBA8_u32 {
        u8 r, g, b, a;
    u32 rgba;
} S1_Color_RGBA8_u32;
typedef struct S1_unk_D_86002F58_004_000_040_004 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
} S1_unk_D_86002F58_004_000_040_004;
typedef struct S1_unk_D_86002F58_004_000_040 {
    /* 0x04 */ S1_unk_D_86002F58_004_000_040_004* unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 unk_12;
} S1_unk_D_86002F58_004_000_040;
typedef struct S1_unk_D_86002F58_004_000_054_004 {
    /* 0x02 */ char unk_02[0x2];
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ void* unk_10;
} S1_unk_D_86002F58_004_000_054_004;
typedef struct S1_unk_D_86002F58_004_000_054 {
    /* 0x04 */ S1_unk_D_86002F58_004_000_054_004* unk_04;
    /* 0x08 */ s16 unk_08;
} S1_unk_D_86002F58_004_000_054;
typedef float S1_MtxF_t[4][4];
typedef union {
    S1_MtxF_t mf;
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
} S1_MtxF;
typedef struct S1_unk_D_86002F58_004_000_0A8 {
    /* 0x04 */ S1_Vec3f unk_04;
} S1_unk_D_86002F58_004_000_0A8;
typedef struct S1_unk_D_86002F58_004_000 {
    /* 0x000 */ S1_unk_D_86002F58_004_000_000 unk_000;
    /* 0x018 */ s16 animType; // Model_InitDisplayObject's arg1
    /* 0x01A */ s16 modelId; // Model_InitDisplayObject's arg2; a species id in most battle-scene consumers
    /* 0x01C */ u8 textureMode; // Model_SetMaterialTextureMode
    /* 0x01D */ u8 materialAlpha; // Model_SetMaterialAlpha
    /* 0x01E */ S1_Vec3s unk_01E;			//	total Rotation
    /* 0x024 */ S1_Vec3f unk_024;			//	global Position
    /* 0x030 */ S1_Vec3f unk_030;			//	scale
    /* 0x03C */ S1_Color_RGBA8_u32 unk_03C;
    /* 0x040 */ S1_unk_D_86002F58_004_000_040 unk_040;
    /* 0x054 */ S1_unk_D_86002F58_004_000_054 unk_054;
    /* 0x060 */ S1_MtxF unk_060;
    /* 0x0A0 */ S1_Color_RGBA8_u32 unk_0A0;    //  vertex color ?
    /* 0x0A4 */ char unk0A4[2];
    /* 0x0A6 */ u8 poolIndex; // stable index into the shared displayObjectPool; GeoRender_RecordAnchorPosition/etc.
    /* 0x0A7 */ u8 anchorCount; // GeoRender_RecordAnchorPosition/FindAnchorPosition; caps at 0xC (12)
    /* 0x0A8 */ S1_unk_D_86002F58_004_000_0A8 anchors[1]; // declared size undersells - indexed up to anchorCount (max 12)
    /* 0x0B8 */ char unk0B8[0x24];
    /* 0x0DC */ S1_Vec3f unk_0DC;
    /* 0x0E0 */ char unk0E0[0x4];
    /* 0x0EC */ S1_Vec3f unk_0EC;
    /* 0x0F8 */ char unk0F8[0x4];
    /* 0x0FC */ S1_Vec3f unk_0FC;
    /* 0x108 */ char unk108[0x60];
} S1_unk_D_86002F58_004_000;
s32 Intro_StepRotationOvershoot(S1_unk_D_86002F58_004_000* arg0, s16 arg1, s16 arg2) {
    if (arg1 > 0) {
        arg0->unk_01E.y -= arg1;
        if ((arg0->unk_01E.y < arg2) && ((arg2 - arg1) < arg0->unk_01E.y)) {
            return 1;
        }
    } else {
        arg0->unk_01E.y -= arg1;
        if ((arg2 < arg0->unk_01E.y) && (arg0->unk_01E.y < (arg2 - arg1))) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_829045E4(void *arg0, s16 arg1, s16 arg2) {
    s16 current;
    s16 after;
    s32 delta;
    s32 quotient;
    current = *(s16 *)((u8 *)arg0 + 0x20);
    delta = current - arg2;
    quotient = delta / 182;
    if ((quotient >= -0x168) && (quotient < -0x149)) {
        arg1 = (s16)((s16)(delta + 0x10000) / 4);
    }
    *(s16 *)((u8 *)arg0 + 0x20) = current - arg1;
    if (arg1 > 0) {
        after = *(s16 *)((u8 *)arg0 + 0x20);
        if ((arg2 >= after) && (after >= (arg2 - arg1))) {
            *(s16 *)((u8 *)arg0 + 0x20) = arg2;
            return 1;
        }
    } else {
        after = *(s16 *)((u8 *)arg0 + 0x20);
        if ((after >= arg2) && ((arg2 - arg1) >= after)) {
            *(s16 *)((u8 *)arg0 + 0x20) = arg2;
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void *D_82919A08;
extern f32 Math_StepToF(f32, f32, f32, f32);
void func_829046A8(void) {
    void *ptr;

    if (*(s16 *)((u8 *)&D_82919A08 + 0x38) < 4) {
        if (Intro_StepRotationOvershoot((S1_unk_D_86002F58_004_000 *)D_82919A08, 2548, 0x7FFF) != 0) {
            (*(s16 *)((u8 *)&D_82919A08 + 0x38)) += 1;
        }
    } else {
        func_829045E4(D_82919A08, 2002, 0x7FFF);
    }
    ptr = D_82919A08;
    if (*(f32 *)((u8 *)ptr + 0x28) <= 10.0f) {
        f32 step = 0.2f;

        *(f32 *)((u8 *)&D_82919A08 + 0x30) = Math_StepToF(*(f32 *)((u8 *)&D_82919A08 + 0x30), 3.0f, step, step);
        ptr = D_82919A08;
    } else {
        *(f32 *)((u8 *)&D_82919A08 + 0x30) = 7.0f;
    }
    *(f32 *)((u8 *)D_82919A08 + 0x28) = Math_StepToF(*(f32 *)((u8 *)ptr + 0x28), 0.0f, *(f32 *)((u8 *)&D_82919A08 + 0x30), *(f32 *)((u8 *)&D_82919A08 + 0x30));
}
#endif

#ifdef VERSION_US
extern f32 D_82911FD0[];

void func_82904794(void) {
    func_829033DC((f32 *)((u8 *)D_82919C38 + 0xB8),
                  *(f32 *)((u8 *)D_82919A08 + 0x28) + *(f32 *)((u8 *)D_82911FD0 + D_82919C10 * 20), 0.45f);
    if (*(f32 *)((u8 *)D_82919C38 + 0xB8) > 450.0f) {
        *(f32 *)((u8 *)D_82919C38 + 0xB8) = 450.0f;
    }
}

#endif

#ifdef VERSION_US
extern void *D_82919A08;
extern void func_829046A8(void);
extern void func_82904794(void);
extern void func_800226C0(s32);
void func_82904824(void *arg0) {
    ((u8 *)arg0)[5] &= 0xFFFE;
    ((u8 *)D_82919A08)[1] |= 1;
    func_829046A8();
    func_82904794();
    if (*(f32 *)((u8 *)D_82919A08 + 0x28) == 0.0f) {
        *(s16 *)((u8 *)arg0 + 0x1068) = 8;
        func_800226C0(0x7B);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_33FAE0/func_829048A0.s")
#endif

#ifdef VERSION_US
extern s32 Math_StepToS32(s32 current, s32 target, s32 inc, s32 dec);

// Steps the six halfwords at arg1 toward arg2-arg7 by up to step each call; once all six
// arrive, toggles bit 1 of the byte at arg0 + 0x18. func_82904D78 passes the same record for
// arg0 and arg1.
void func_82904AC8(u8 *arg0, u16 *arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7,
                   s16 step) {
    arg1[0] = Math_StepToS32(arg1[0], arg2, step, step);
    arg1[1] = Math_StepToS32(arg1[1], arg3, step, step);
    arg1[2] = Math_StepToS32(arg1[2], arg4, step, step);
    arg1[3] = Math_StepToS32(arg1[3], arg5, step, step);
    arg1[4] = Math_StepToS32(arg1[4], arg6, step, step);
    arg1[5] = Math_StepToS32(arg1[5], arg7, step, step);
    if (arg1[0] == arg2 && arg1[1] == arg3 && arg1[2] == arg4 && arg1[3] == arg5 && arg1[4] == arg6 &&
        arg1[5] == arg7) {
        if (arg0[0x18] & 2) {
            arg0[0x18] &= ~2;
        } else {
            arg0[0x18] |= 2;
        }
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82904C28 begin */
extern u8 D_82919A88[];
extern u8 D_82919AF8[];
extern u8 D_82919B68[];
extern u8 D_82919AA4[];
extern void func_82904AC8(u8 *, u16 *, u16, u16, u16, u16, u16, u16, s16);
// The three 0x70-byte blocks at D_82919A88, D_82919AF8 and D_82919B68 each hold four
// 0x1C-byte state records; byte 0x18 of a record carries its flag. Starting at record 1
// (D_82919AA4), this clears bit 0 of records 1..3 in every block and leaves record 0
// alone: the 0x88 and 0xF8 offsets are records 5 and 9 of the flattened 0x1C stride.
// func_82904AC8 re-toggles the flag of a block's record 0, which the final test reads.


void func_82904C28(void *arg0) {
    s32 i;

    for (i = 0; i != 3; i += 1) {
        D_82919AA4[i * 0x1C + 0x18] &= ~1;
        D_82919AA4[i * 0x1C + 0x88] &= ~1;
        D_82919AA4[i * 0x1C + 0xF8] &= ~1;
    }
    func_82904AC8(D_82919A88, (u16 *)D_82919A88, 0xFF, 0xFF, 0xFF, 0, 0xC8, 0xFF, 0x14);
    func_82904AC8(D_82919AF8, (u16 *)D_82919AF8, 0xFF, 0xFF, 0xFF, 0, 0xC8, 0xFF, 0x14);
    func_82904AC8(D_82919B68, (u16 *)D_82919B68, 0xFF, 0xFF, 0xFF, 0xFF, 0xC8, 0, 0x14);
    if ((D_82919A88[0x18] & 2) && (D_82919A88[0x88] & 2) && (D_82919A88[0xF8] & 2)) {
        *(s16 *)((u8 *)arg0 + 0x1068) = 10;
    }
}
/* mkdraft:func_82904C28 end */
#endif

#ifdef VERSION_US
extern u8 D_82919A88[];
extern u8 D_82919AF8[];
extern u8 D_82919B68[];
extern u8 D_82919B80;
extern void func_82904AC8(u8 *, u16 *, u16, u16, u16, u16, u16, u16, s16);
void func_82904D78(s32 arg0) {
    func_82904AC8(D_82919A88, (u16 *)D_82919A88, 0xFF, 0xFF, 0xFF, 0, 0x64, 0xFF, 0x14);
    func_82904AC8(D_82919AF8, (u16 *)D_82919AF8, 0xFF, 0xFF, 0xFF, 0, 0x64, 0xFF, 0x14);
    if (!(D_82919B80 & 2)) {
        func_82904AC8(D_82919B68, (u16 *)D_82919B68, 0xFF, 0xFF, 0xFF, 0xFF, 0xC8, 0, 0x14);
        return;
    }
    func_82904AC8(D_82919B68, (u16 *)D_82919B68, 0xFF, 0xFF, 0xFF, 0, 0x64, 0xFF, 0x14);
}
#endif

#ifdef VERSION_US
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_82907188(void);
extern void func_829043B4(u8 *);
void func_82904E9C(u8 *arg0) {
    s16 limit;
    s32 hit;

    limit = 0x50;
    if (arg0[0x1070] == 5) {
        limit = 0x78;
    }
    hit = limit == arg0[0x1072];
    arg0[0x1072]++;
    if (hit) {
        *(s16 *)(arg0 + 0x1068) = 1;
        arg0[0x1072] = 0xE;
        if (arg0[0x1070] == 5) {
            StageContext_SetClearColor(0xFFFF);
        } else {
            StageContext_SetClearColor(1);
        }
        StageFade_StartFromTransparent(0xC);
    }
    if (arg0[0x1072] >= limit / 3) {
        func_82907188();
    }
    func_829043B4(arg0);
}
#endif

#ifdef VERSION_US
extern void func_82906680(void *);
extern void StageFade_StartFromOpaque(s32);
extern void func_82903298(void *);
extern void func_8290351C(void);
extern void func_829043B4(u8 *);
extern void * D_82919A08;
extern u8 D_82919D48;
void func_82904F78(u8 *arg0) {
    s32 active;

    if (arg0[0x1072] != 0) {
        func_829043B4(arg0);
    }
    active = arg0[0x1072] != 0;
    arg0[0x1072]--;
    if (!active) {
        arg0[0x1070]++;
        if (arg0[0x1070] == 6) {
            StageContext_SetClearColor(0xFFFF);
        } else {
            StageContext_SetClearColor(1);
        }
        if (arg0[0x1070] == 6) {
            arg0[0x1072] = 12;
            *(s16 *)(arg0 + 0x1068) = 7;
            func_82906680((u8 *)D_82919A08 + 0x24);
            func_8290351C();
        } else {
            *(s8 *)&D_82919D48 = 0;
            *(f32 *)((u8 *)&D_82919D48 + 4) = 0.0f;
            *(f32 *)((u8 *)&D_82919D48 + 8) = 0.0f;
            func_82903298(arg0);
            func_82903058(arg0, 0);
            arg0[0x1072] = 12;
            *(s16 *)(arg0 + 0x1068) = 2;
        }
        StageFade_StartFromOpaque(12);
    }
}
#endif

#ifdef VERSION_US
extern void func_829043B4(u8 *);
void func_82905078(u8 *arg0) {
    s32 active;

    if (arg0[0x1070] < 6) {
        func_829043B4(arg0);
    }
    active = arg0[0x1072]-- != 0;
    if (active == 0) {
        arg0[0x1072] = 0;
        *(s16 *)(arg0 + 0x1068) = 0;
    }
}
#endif

#ifdef VERSION_US
extern void func_82904F78(u8 *);
extern void func_829048A0(void *);
extern void func_82904C28(void *);
extern void func_82906748(void *);
void func_829050C8(void *arg0) {
    switch (*(u16 *)((u8 *)arg0 + 0x1068)) {
        case 0:
            func_82904E9C(arg0);
            break;
        case 1:
            func_82904F78(arg0);
            break;
        case 2:
            func_82905078(arg0);
            break;
        case 7:
            func_82904824(arg0);
            func_82906748((u8 *)D_82919A08 + 0x24);
            break;
        case 8:
            func_829048A0(arg0);
            func_82906748((u8 *)D_82919A08 + 0x24);
            break;
        case 9:
            func_82904C28(arg0);
            func_82906748((u8 *)D_82919A08 + 0x24);
            break;
        case 10:
            func_82904D78((s32)arg0);
            func_82906748((u8 *)D_82919A08 + 0x24);
            break;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_829051AC begin */
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80055EF0(void *, s32);
extern void func_80055F6C(void *, s32);
extern void func_80051D64(s32, s32);
extern void func_80055028(void);
extern void func_80021ED8(s32);
extern void *D_82919C14;
extern u8 D_82919D10;
extern u8 D_82919C20[];



void func_829051AC(void) {

    StageContext_SetClearColor(1);
    StageFade_StartFromOpaque(0x10);
    if (*(s16 *)((u8 *)D_82919C14 + 6) != 0) {
        func_80055EF0(&D_82919C20, 1);
    } else {
        func_80055EF0(&D_82919C20, 0);
    }
    switch (*(u16 *)D_82919C14) {
        case 0:
            D_82919C20[6] |= 0xF;
            break;
        case 3:
            D_82919C20[9] |= 0xF;
            break;
        case 1:
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 1) {
                D_82919C20[7] |= 1;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 2) {
                D_82919C20[7] |= 2;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 3) {
                D_82919C20[7] |= 4;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 4) {
                D_82919C20[7] |= 8;
            }
            break;
        case 2:
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 1) {
                D_82919C20[8] |= 1;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 2) {
                D_82919C20[8] |= 2;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 3) {
                D_82919C20[8] |= 4;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 4) {
                D_82919C20[8] |= 8;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 1) {
                D_82919D10 = D_82919C20[0x10];
                D_82919C20[0x10] = 0;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 2) {
                D_82919D10 = D_82919C20[0x11];
                D_82919C20[0x11] = 0;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 3) {
                D_82919D10 = D_82919C20[0x12];
                D_82919C20[0x12] = 0;
            }
            if (*(s16 *)((u8 *)D_82919C14 + 2) == 4) {
                D_82919D10 = D_82919C20[0x13];
                D_82919C20[0x13] = 0;
            }
            break;
    }
    if (*(s16 *)((u8 *)D_82919C14 + 6) != 0) {
        func_80055F6C(&D_82919C20, 1);
    } else {
        func_80055F6C(&D_82919C20, 0);
    }
    func_80051D64(0x14, 0);
    func_80055028();
    func_80021ED8(0x46);
}
/* mkdraft:func_829051AC end */
#endif

#ifdef VERSION_US
extern void func_80064D28(void);
extern void func_829050C8(void *);
extern void func_82904208(void);
void func_829053F8(void) {
    s32 var_s0;
    var_s0 = 1;
    do {
        func_80064D28();
        func_829050C8(D_82918990);
        if ((D_80087200->buttonsPressed & 0xD000) && (*(s16 *)((u8 *)D_82918990 + 0x1068) == 0xA)) {
            var_s0 = 0;
        }
        func_82904208();
    } while (var_s0 != 0);
}
#endif

#ifdef VERSION_US
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void func_80064D28(void);
extern void func_82904208(void);
extern void func_829050C8(void *);
extern u8 D_82918990[];
void func_82905488(void) {
    s32 i;

    StageFade_StartFromTransparent(0x20);
    func_800225C4(0x20);
    for (i = 0; i < 0x20; i++) {
        func_80064D28();
        func_829050C8(&D_82918990);
        func_82904208();
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_829054F8 begin */
extern s32 func_8004DDF4(s32);
extern s32 WidgetTree_RunMessagePanelSilent(s32, s32);
extern s32 func_80055948(s32);
extern void ModelRenderer_InitDisplayRoots(void);
extern s32 D_82911FD8[];
extern s32 D_82919D1C;

void func_829054F8(void) {
    s32 sp1C;
    s32 temp_v0;

    if (*(u16 *)D_82919C14 == 0) {
        D_82919C10 = 0;
    }
    if (*(u16 *)D_82919C14 == 3) {
        D_82919C10 = 1;
    }
    if (*(u16 *)D_82919C14 == 1) {
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 1) {
            D_82919C10 = 2;
        }
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 2) {
            D_82919C10 = 3;
        }
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 3) {
            D_82919C10 = 4;
        }
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 4) {
            D_82919C10 = 5;
        }
    }
    if (*(u16 *)D_82919C14 == 2) {
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 1) {
            D_82919C10 = 6;
        }
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 2) {
            D_82919C10 = 7;
        }
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 3) {
            D_82919C10 = 8;
        }
        if (*(s16 *)((u8 *)D_82919C14 + 2) == 4) {
            D_82919C10 = 9;
        }
    }
    func_8004DDF4(*(s32 *)((u8 *)D_82911FD8 + (D_82919C10 * 0x14)));
    D_82919D24 = *(s16 *)((u8 *)D_82919C14 + 4);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    D_82919D1C = WidgetTree_RunMessagePanelSilent(temp_v0, *(s32 *)((u8 *)D_82911FD8 + (D_82919C10 * 0x14)));
    MainPool_FinalizeAllocation(sp1C);
    func_82903444();
    ModelRenderer_InitDisplayRoots();
    func_8290379C(&D_82918990);
    func_80055948(3);
}
/* mkdraft:func_829054F8 end */
#endif

#ifdef VERSION_US
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047588(s32, s32);
extern s32 func_800356CC(s32);
extern s32 BinArchive_Open(s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_8004C8C0(s32);
extern void func_8004C4B0(s32);
extern void Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void main_pool_pop_state(s32);
extern void func_829054F8(void);
extern void func_829051AC(void);
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern void func_829053F8(void);
extern void func_82905488(void);
extern void * D_82919C14;
s32 func_829056A4(void *arg0, void *arg1) {
    s32 sp24;
    main_pool_push_state(0x434150);
    Gfx_InitDisplayListBuffers(0x18000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    func_80047588(0x13, 0);
    D_82919D14 = BinArchive_Open(func_800356CC(0x10), 0, 1, 1);
    D_82919C14 = (void *)arg1;
    func_8004C09C(0x23);
    func_8004C8C0(0x43);
    func_8004C8C0(0x93);
    func_8004C4B0(0x33);
    Asset_LoadToSegment(((u32)&D_1000000 & 0x0F000000) >> 24, &D_446E30, &D_447D00, 0);
    func_829054F8();
    func_80008514(sp24);
    func_829051AC();
    func_829053F8();
    func_82905488();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x434150);
    return 0;
}
#endif
