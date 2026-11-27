#include "global.h"


#ifdef VERSION_US
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
extern void func_87C037C0(void *, void *);
extern f32 D_86B0D168;
extern f32 D_86B0D16C;
extern f32 D_86B0D170;
extern f32 D_86B0D174;
extern s32 D_86B17EAC;
extern u8 D_86B17E2C;
s32 func_86B00020(s32 arg0, void *camera) {
    u16 roll = 0;

    GeoCamera_SetPerspective(camera, D_86B0D174, 100.0f, 12800.0f);
    func_80038E14(camera, 0, (__sinf(D_86B0D16C) * D_86B0D168) + 400.0f + D_86B0D170, (__cosf(D_86B0D16C) * D_86B0D168), 0.0f, D_86B0D170, 0.0f, roll);
    if (D_86B17EAC == 0) {
        func_87C037C0(&D_86B17E2C, camera);
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86B000F0(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(sp26 + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 - 0x2000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86B00158(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - sp26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 + 0x6000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_86B0D160;
extern u8 *D_86B181C0;
extern u8 D_86B17A78[];
extern s32 D_86B0D8F0[];
extern s32 D_86B0D990[];
extern s32 D_86B18118[];
extern s32 D_86B18128[];
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 func_8004D1FC(u8 *arg0);
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);

#define TEX_W_86B001C4(t) ((f32)(u32)((u16 *)(t))[0])
#define TEX_H_86B001C4(t) ((f32)(u32)((u16 *)(t))[1])
#define ROUND_86B001C4(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
#define POS_86B001C4(k) (((s32 (*)[5][2])D_86B0D8F0)[j][i][k])
#define OFS_86B001C4(n, k) (((s32 (*)[2])D_86B0D990)[n][k])
#define SLOT_86B001C4(o) (*(s32 *)(D_86B17A78 + j * 20 + i * 4 + (o)))

s32 func_86B001C4(s32 arg0, s32 arg1) {
    s32 j;
    s32 i;
    s32 val;

    if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4) {
        if (*(s32 *)D_86B181C0 != 0 && *(s32 *)D_86B181C0 != 1 && *(s32 *)D_86B181C0 != 2 && D_86B0D160 == 0) {
            gSPDisplayList(D_800D0510++, D_80094E38);
            for (j = 0; j < 2; j++) {
                for (i = 0; i < *(s32 *)(D_86B17A78 + j * 4 + 0x1B4); i++) {
                    if (*(s32 *)(D_86B17A78 + j * 4 + 0x1B4) - 1 == i && *(s32 *)(D_86B17A78 + j * 4 + 0x1A4) % 2) {
                        gDPSetCombine(D_800D0510++, 0xFC377E6E, 0x11FCF279);
                        gDPSetPrimColor(D_800D0510++, 0x64, 0x64, 0xFF, 0xFF, 0xFF, 0xFF);
                    } else {
                        gSPDisplayList(D_800D0510++, D_80094E38);
                    }
                    func_8004D1FC((u8 *)D_86B18118[SLOT_86B001C4(0x1C4)]);
                    GfxRect_DrawTextured(POS_86B001C4(0) + OFS_86B001C4(SLOT_86B001C4(0x1C4), 0),
                                         POS_86B001C4(1) + OFS_86B001C4(SLOT_86B001C4(0x1C4), 1),
                                         (s32)ROUND_86B001C4(TEX_W_86B001C4(D_86B18118[SLOT_86B001C4(0x1C4)])),
                                         (s32)ROUND_86B001C4(TEX_H_86B001C4(D_86B18118[SLOT_86B001C4(0x1C4)])), 0, 0,
                                         0x400, 0x400, 0);
                    if (SLOT_86B001C4(0x224) != 0) {
                        gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xB4, 0x00, 0xFF);
                        gDPSetEnvColor(D_800D0510++, 0, 0, 0, 0xFF);
                        gDPSetCombine(D_800D0510++, 0xFC30FE61, 0xFFFFF3F9);
                        val = SLOT_86B001C4(0x224);
                        if (val / 10 != 0) {
                            func_8004D1FC((u8 *)D_86B18128[val / 10]);
                            GfxRect_DrawTextured(POS_86B001C4(0) + 10, POS_86B001C4(1) + 13,
                                                 (s32)ROUND_86B001C4(TEX_W_86B001C4(D_86B18128[val / 10])),
                                                 (s32)ROUND_86B001C4(TEX_H_86B001C4(D_86B18128[val / 10])), 0, 0,
                                                 0x400, 0x400, 0);
                        }
                        func_8004D1FC((u8 *)D_86B18128[val % 10]);
                        GfxRect_DrawTextured(POS_86B001C4(0) + 14, POS_86B001C4(1) + 13,
                                             (s32)ROUND_86B001C4(TEX_W_86B001C4(D_86B18128[val % 10])),
                                             (s32)ROUND_86B001C4(TEX_H_86B001C4(D_86B18128[val % 10])), 0, 0,
                                             0x400, 0x400, 0);
                    }
                }
            }
            gSPDisplayList(D_800D0510++, D_80094F50);
        }
    }
    return 1;
}
#endif

#ifdef VERSION_US
typedef struct {
    u8 unk_00[0x14];
    f32 vel[4][2];
    u8 unk_34[0x48 - 0x34];
    f32 mag[4];
    f32 angle[4];
    s32 mode;
    s32 all;
    u8 unk_70[0x4B4 - 0x70];
} Blob86B007D0;
extern void func_87F02684(void *);
extern void func_87F02328(void);
extern u8 D_86B0E9A0, D_86B0EE60, D_86B12AD0, D_86B13A68, D_86B0E1A8, D_86B0E7F8;
extern u8 D_86B0D384[];


extern u8 *D_86B181C0;
extern f32 __cosf(f32);
extern f32 __sinf(f32);
// Fragment 61's 0x4B4-byte runtime state at 0x86B17A78 (D_86B17A78 in the other
// functions), reset from the D_86B0D384 template. This unit's .bss is pinned at
// 0x86B17A78 in datamig_bss.ld and is laid out in declaration order:
// sStateHead (0x00-0x37), func_86B01A94's sStatePair (0x38-0x3F) and
// sStateTail (0x40-0x4B3). func_86B007D0 reaches the whole record through
// sStateHead; as an in-unit static the mode stores share one lui.
static u8 sStateHead[0x38];
#define sBlob (*(Blob86B007D0 *)sStateHead)
void func_86B007D0(void) {
    f32 *p;
    s32 i;
    u8 *q;
    s32 flags;
    func_87F02684(&D_86B0E9A0);
    func_87F02684(&D_86B0EE60);
    func_87F02684(&D_86B12AD0);
    func_87F02684(&D_86B13A68);
    func_87F02684(&D_86B0E1A8);
    func_87F02684(&D_86B0E7F8);
    sBlob = *(Blob86B007D0 *)D_86B0D384;
    for (i = 0; i < 4; i++) {
        sBlob.vel[i][0] = sBlob.mag[i] * __cosf(sBlob.angle[i]);
        sBlob.vel[i][1] = sBlob.mag[i] * __sinf(sBlob.angle[i]);
    }
    q = D_86B181C0;
    flags = *(s8 *)(*(u8 **)(q + 0xC) + 0x2181);
    switch (flags) {
    case 0: sBlob.mode = 0; break;
    case 1: sBlob.mode = 1; break;
    case 2: sBlob.mode = 2; break;
    case 3: sBlob.mode = 3; break;
    }
    flags = *(u8 *)(*(u8 **)(q + 0xC) + 0x2182);
    if ((flags & 1) && (flags & 2) && (flags & 4) && (flags & 8)) {
        sBlob.all = 1;
        sBlob.mode = 2;
    } else {
        sBlob.all = 0;
    }
    func_87F02328();
}
#endif

#ifdef VERSION_US
extern s32 D_86B0D160; extern s32 D_86B0D164; extern void *D_86B0E0A8; extern u8 *D_86B181C0; extern s32 func_87F08208(void *); extern void StageContext_SetClearColor(s32); extern void StageFade_StartFromTransparent(s32); extern void func_800225C4(s32); extern void Audio_PlayDefaultSound(s32); extern void func_800226C0(s32); extern void func_86B01720(s32);
void func_86B00994(void) {
    s32 temp_v0;
    D_86B0D164 = 0;
    temp_v0 = func_87F08208(&D_86B0E0A8);
    switch (temp_v0) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)D_86B181C0 = 2;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        D_86B0D160 = 0;
        return;
    case 2:
        func_86B01720(0);
        func_800226C0(3);
        D_86B0D160 = 1;
        return;
    }
}
void func_86B00994_padding(void) {}
#endif

#ifdef VERSION_US
extern u8 *D_86B180E0[];
extern Gfx *D_86B180D8;
extern u8 *D_86B1817C;
extern u8 *D_86B18180[];
extern s32 func_80001FF0(void);
extern s32 D_86B0E0A0;
extern u8 *D_86B181C0;
extern void func_87F0C650(void *);
extern void func_87F0C694(void *, s32);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern s32 func_80040E80(s32, void *);
extern s32 WidgetTree_RunMessagePanelSilent(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern void ModelRenderer_InitDisplayRoots(void);
extern void func_87F024CC(void);
extern void func_87F01870(void *);
extern void func_87F01F34(void *);
extern void func_87F00030(void);
extern void func_87F024F4(void *, void *, s32);
extern void func_80037E9C(s32, void *);
extern void func_87F0252C(void *, void *, void *, s32);
extern void func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);
extern s32 func_87F08DF8(s32, f32, f32, s32);
extern void func_8004DDF4(s32);
#include "color_adjustment.h"
extern ColorAdjustment func_87F0AD50(s32, s32, s32);
extern s32 func_8004E018(s32, s32, s32, ColorAdjustment);
extern void func_8003F018(void *);
extern void func_80037E3C(u8 *, void *, s32);
extern void func_87F03BB0(void *, s32);
extern void func_87F029B8(void *, s32);
extern void func_86B0B608(s32);
extern void func_86B0B9A0(void);
extern void func_87F00688(void);
extern void func_8003F3BC(void *, s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_800225C4(s32);
extern u8 D_86B0D9A8, D_86B0D18C, D_86B0D1C0, D_86B0D88C;
extern s32 D_86B0E7F0, D_86B0E99C, D_86B180D4, D_86B0E188, D_86B0E190, D_86B0E18C, D_86B0E194, D_86B0E198, D_86B0E19C, D_86B0E1A0, D_86B0E1A4, D_86B17908;
extern u8 D_86B0E9A0, D_86B0E9B8, D_86B0EE60, D_86B0EE78, D_86B12AD0, D_86B12AF0, D_86B0E088, D_86B13A68, D_86B13A80;
extern s32 D_86B180F8[], D_86B18108[], D_86B18150[], D_86B18178, D_86B181A8[], D_86B18118[], D_86B18128[];
extern u8 D_86B0E070, D_86B17F30, D_86B17F48;
extern u8 D_86B16DA0[], D_86B17340[], D_86B17364[];
extern u32 D_86B16D90[];
extern u8 D_87F15B70;
extern s32 D_86B17910;
extern s32 D_86B0E7F4;
extern u8 D_86B0E1A8, D_86B0E1C0, D_86B0E7F8, D_86B0E810, D_86B178E8;
extern s32 func_86B023FC();
extern s32 func_86B03228();
extern void func_8003F03C(void *, void *);
extern void func_87F06430(void *, s32);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F210(void *, s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_8003F1DC(u8 *);
extern void func_86B007D0(void);
typedef struct { f32 x, y, z; } Vec3f_86B;
typedef struct { s32 unk00; Vec3f_86B unk04; u8 pad10[2]; u8 unk12; u8 unk13; u8 unk14; u8 unk15; u8 pad16[2]; } Unk86B_18;
typedef struct { u8 pad0[0x54]; Vec3f_86B unk54; u8 pad60[0x12C]; } Unk86B_18C;
typedef struct { u8 pad0[0x14]; Unk86B_18C *unk14; Unk86B_18 *unk18; } Unk86B181F0;
extern Unk86B181F0 D_86B181F0;
void func_86B00A3C(void) {
    s32 padA[2]; // FAKE
    Unk86B_18 *ep2;
    Unk86B_18 *ep3;
    ColorAdjustment tint;
    s32 padB[1]; // FAKE
    s32 pool;
    s32 i;
    f32 sixth;
    Unk86B_18 *ep;
    Unk86B_18C *fp;

    if (func_80001FF0() == 0x3C) {
        D_86B0E0A0 = 1;
    } else {
        D_86B0E0A0 = 0;
    }
    func_87F0C650(D_86B181C0 + 0x1C);
    if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) == 4) {
        func_87F0C694(D_86B181C0 + 0x1C, 0x14);
    }
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)(D_86B181C0 + 8) = func_80040E80(pool, &D_86B0D9A8);
    D_86B0E7F0 = func_80040E80(pool, &D_86B0D18C);
    D_86B0E99C = func_80040E80(pool, &D_86B0D1C0);
    D_86B180D4 = func_80040E80(pool, &D_86B0D88C);
    D_86B0E188 = WidgetTree_RunMessagePanelSilent(pool, 0x97);
    D_86B0E190 = WidgetTree_RunMessagePanelSilent(pool, 0xD8);
    D_86B0E18C = WidgetTree_RunMessagePanelSilent(pool, 0xD3);
    D_86B0E194 = WidgetTree_RunMessagePanelSilent(pool, 0xD1);
    D_86B0E198 = WidgetTree_RunMessagePanelSilent(pool, 0xD5);
    D_86B0E19C = WidgetTree_RunMessagePanelSilent(pool, 0xCB);
    D_86B0E1A0 = WidgetTree_RunMessagePanelSilent(pool, 0xCC);
    D_86B0E1A4 = WidgetTree_RunMessagePanelSilent(pool, 0xCF);
    D_86B17908 = WidgetTree_RunMessagePanelSilent(pool, 0x96);
    MainPool_FinalizeAllocation(pool);
    ModelRenderer_InitDisplayRoots();
    func_87F024CC();
    func_87F01870(*(void **)(D_86B181C0 + 0xC));
    func_87F01F34(*(void **)(D_86B181C0 + 0xC));
    func_87F00030();
    func_87F024F4(&D_86B0E9A0, &D_86B0E9B8, 3);
    func_87F024F4(&D_86B0EE60, &D_86B0EE78, 0x27);
    func_87F024F4(&D_86B12AD0, &D_86B12AF0, 0xA);
    func_80037E9C(0, &D_86B0E088);
    func_87F0252C(&D_86B0E088, &D_86B13A68, &D_86B13A80, 0x21);
    func_8004C8C0(0x1B2);
    func_8004C8C0(0x1AD);
    func_8004C8C0(0x1AE);
    D_86B180F8[0] = func_8004C990(0x1B2, 6);
    D_86B180F8[1] = func_8004C990(0x1B2, 7);
    D_86B180F8[2] = func_8004C990(0x1B2, 8);
    D_86B180F8[3] = func_8004C990(0x1B2, 9);
    D_86B18108[0] = func_8004C990(0x1B2, 2);
    D_86B18108[1] = func_8004C990(0x1B2, 3);
    D_86B18108[2] = func_8004C990(0x1B2, 4);
    D_86B18108[3] = func_8004C990(0x1B2, 5);
    D_86B18150[0] = func_8004C990(0x1AD, 0);
    D_86B18150[1] = func_8004C990(0x1AD, 1);
    D_86B18150[2] = func_8004C990(0x1AD, 2);
    D_86B18150[3] = func_8004C990(0x1AD, 3);
    D_86B18150[4] = func_8004C990(0x1AD, 4);
    D_86B18150[5] = func_8004C990(0x1AD, 5);
    D_86B18150[6] = func_8004C990(0x1AD, 6);
    D_86B18150[7] = func_8004C990(0x1AD, 7);
    D_86B18150[8] = func_8004C990(0x1AD, 8);
    D_86B18150[9] = func_8004C990(0x1AD, 9);
    D_86B18178 = func_8004C990(0x1AE, 1);
    func_8004C8C0(0x189);
    func_8004C8C0(0x18A);
    D_86B1817C = (u8 *)func_8004C990(0x189, 0);
    D_86B18180[0] = (u8 *)func_8004C990(0x18A, 0);
    D_86B18180[1] = (u8 *)func_8004C990(0x18A, 1);
    D_86B18180[2] = (u8 *)func_8004C990(0x18A, 2);
    D_86B18180[3] = (u8 *)func_8004C990(0x18A, 3);
    D_86B18180[4] = (u8 *)func_8004C990(0x18A, 4);
    D_86B18180[5] = (u8 *)func_8004C990(0x18A, 5);
    D_86B18180[6] = (u8 *)func_8004C990(0x18A, 6);
    D_86B18180[7] = (u8 *)func_8004C990(0x18A, 7);
    D_86B18180[8] = (u8 *)func_8004C990(0x18A, 8);
    D_86B18180[9] = (u8 *)func_8004C990(0x18A, 9);
    D_86B181A8[0] = 0xB43C3CFF;
    D_86B181A8[1] = 0xB48C28FF;
    D_86B181A8[2] = 0x28A028FF;
    D_86B181A8[3] = 0x289696FF;
    D_86B181A8[4] = 0x5050C8FF;
    D_86B181A8[5] = 0x963C96FF;
    func_8004C8C0(0x185);
    func_8004C8C0(0x186);
    D_86B18118[0] = func_8004C990(0x185, 2);
    D_86B18118[1] = func_8004C990(0x185, 0);
    D_86B18118[2] = func_8004C990(0x185, 3);
    D_86B18128[0] = func_8004C990(0x186, 0);
    D_86B18128[1] = func_8004C990(0x186, 1);
    D_86B18128[2] = func_8004C990(0x186, 2);
    D_86B18128[3] = func_8004C990(0x186, 3);
    D_86B18128[4] = func_8004C990(0x186, 4);
    D_86B18128[5] = func_8004C990(0x186, 5);
    D_86B18128[6] = func_8004C990(0x186, 6);
    D_86B18128[7] = func_8004C990(0x186, 7);
    D_86B18128[8] = func_8004C990(0x186, 8);
    D_86B18128[9] = func_8004C990(0x186, 9);
    func_8004C8C0(0x188);
    D_86B180E0[0] = (u8 *)func_8004C990(0x188, 0);
    D_86B180E0[1] = (u8 *)func_8004C990(0x188, 1);
    D_86B180E0[2] = (u8 *)func_8004C990(0x188, 2);
    D_86B180E0[3] = (u8 *)func_8004C990(0x188, 3);
    D_86B180E0[4] = (u8 *)func_8004C990(0x188, 4);
    D_86B180D8 = (Gfx *)func_87F08DF8(func_8004C990(0x188, 0), 0.0f, 0.0f, 0xF000000);
    func_80037E9C(0, &D_86B0E070);
    func_87F0252C(&D_86B0E070, &D_86B17F30, &D_86B17F48, 1);
    for (i = 0; i < 4; i++) {
        func_8004DDF4(0x8F);
        pool = MainPool_AllocState(main_pool_get_available(), 0);
        tint = func_87F0AD50(*(s32 *)(D_86B181C0 + 0xC), 0xB, i);
        D_86B16D90[i] = func_8004E018(pool, 0x8F, 0, tint);
        MainPool_FinalizeAllocation(pool);
    }
    sixth = 0.16666667f;
    for (i = 0; i < 4; i++) {
        func_8003F03C(D_86B17340 + i * 0x168, &D_87F15B70);
        func_87F06430(D_86B17364 + i * 0x168, i);
        *(f32 *)(D_86B17340 + i * 0x168 + 0x38) = sixth;
        *(f32 *)(D_86B17340 + i * 0x168 + 0x34) = sixth;
        *(f32 *)(D_86B17340 + i * 0x168 + 0x30) = sixth;
        *(f32 *)(D_86B17340 + i * 0x168 + 0x28) = 50.0f;
        func_8003F114(D_86B17340 + i * 0x168, 0, -1, D_86B16D90[i]);
        func_8003F210(D_86B17340 + i * 0x168, 0);
        ModelAnim_SetFrame(D_86B17340 + i * 0x168, guRandom() % 30);
    }
    for (i = 0; i < 4; i++) {
        func_8003F018(D_86B16DA0 + i * 0x168);
        func_80037E3C(D_86B16DA0 + i * 0x168, func_86B023FC, i);
        *(f32 *)(D_86B16DA0 + i * 0x168 + 0x38) = sixth;
        *(f32 *)(D_86B16DA0 + i * 0x168 + 0x34) = sixth;
        *(f32 *)(D_86B16DA0 + i * 0x168 + 0x30) = sixth;
    }
    func_8003F018((u8 *)&D_86B17910);
    func_80037E3C((u8 *)&D_86B17910, func_86B03228, 0);
    *(f32 *)((u8 *)&D_86B17910 + 0x38) = 0.5f;
    *(f32 *)((u8 *)&D_86B17910 + 0x34) = *(f32 *)((u8 *)&D_86B17910 + 0x38);
    *(f32 *)((u8 *)&D_86B17910 + 0x30) = *(f32 *)((u8 *)&D_86B17910 + 0x34);
    func_8004C8C0(0x133);
    D_86B0E7F4 = func_87F08DF8(func_8004C990(0x133, 0), 0.0f, 0.0f, 0xF000000);
    func_87F024F4(&D_86B0E1A8, &D_86B0E1C0, 4);
    func_87F024F4(&D_86B0E7F8, &D_86B0E810, 1);
    func_87F03BB0(&D_86B178E8, 0x63);
    func_87F029B8(&D_86B181F0, *(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182));
    for (i = 0; i < 4; i++) {
        ep2 = &D_86B181F0.unk18[i];
        ep2->unk00 = 0;
        ep3 = &D_86B181F0.unk18[i];
        ep3->unk04.x = 0;
        ep3->unk04.y = 55;
        ep3->unk04.z = 0;
        fp = &D_86B181F0.unk14[i];
        fp->unk54.x = 0.9f;
        fp->unk54.y = 0.9f;
        fp->unk54.z = 0.9f;
        ep = &D_86B181F0.unk18[i];
        ep->unk12 = 0xFF;
        ep->unk13 = 0xFF;
        ep->unk14 = 0xFF;
        ep->unk15 = 0;
    }
    func_86B007D0();
    if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) == 4) {
        for (i = 0; i < 4; i++) {
            func_8003F114(D_86B16DA0 + i * 0x168, 0, -1, D_86B16D90[i]);
            func_86B0B608(i);
            ep = &D_86B181F0.unk18[i];
            ep->unk15 = 0xB4;
            ep->unk12 = 0xFF;
            ep->unk13 = 0xFF;
            ep->unk14 = 0xFF;
        }
        func_8003F1DC((u8 *)&D_86B17910);
        func_8003F114((u8 *)&D_86B17910, 0, -1, D_86B17908);
        func_8003F210((u8 *)&D_86B17910, 1);
        ModelAnim_SetFrame((u8 *)&D_86B17910, 0x1E);
        func_8003F3BC((u8 *)&D_86B17910, 0);
        func_86B0B9A0();
        StageFade_StartFromOpaque(0x14);
        *(s32 *)D_86B181C0 = 3;
        func_87F00688();
        *(s32 *)D_86B181C0 = 3;
        func_87F00688();
        func_800225C4(0x28);
    }
}
#endif

#ifdef VERSION_US
extern void func_800088DC(void);
extern void func_800468A0(s32);
extern s32 D_86B0E0A4;
extern Gfx *D_800D0510;
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern s32 func_87F00930(void);
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C6B8(void *);
extern void func_86B0990C(void);
extern void func_87F07FE8(void *);
extern void func_87F022F0(void);
extern void func_86B08CEC(void);
extern void func_86B08E08(void);
extern void func_86B08214(void);
extern void func_86B08F18(void);
extern void func_86B09378(void);
extern void func_86B09478(void);
extern s32 D_86B17DD4;
extern u8 D_86B0E0E0[];
extern void func_87F0A5BC(void *);
extern void func_87F01D44(void);
extern void func_87F0C88C(void *);
extern void func_80008648(void);
extern s32 D_86B0D160;
extern u8 * D_86B181C0;
void func_86B014E8(void) {
    s32 mode;

    func_800088DC();
    func_800468A0(D_86B0E0A4);
    func_8000766C(&D_800D0510, 0, 0, 320, 240);
    if (func_87F00930() == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    func_8003C6B8(*(void **)(D_86B181C0 + 8));
    if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4) {
        mode = *(s32 *)D_86B181C0;
        if (mode != 0 && mode != 1 && mode != 2 && D_86B0D160 == 0) {
            func_86B0990C();
        }
    }
    switch (*(s32 *)D_86B181C0) {
    case 0:
    case 1:
    case 2:
        func_87F07FE8(&D_86B0E0A8);
        break;
    case 12:
        if (D_86B0D160 != 0) {
            func_87F07FE8(&D_86B0E0A8);
        }
        if (D_86B0D164 != 0) {
            func_87F022F0();
        }
        break;
    case 4:
        func_86B08CEC();
        break;
    case 5:
        func_86B08E08();
        func_86B08214();
        break;
    case 6:
        func_86B08214();
        break;
    case 7:
        func_86B08F18();
        func_86B08214();
        break;
    case 8:
        func_86B09378();
        func_86B08214();
        if (D_86B17DD4 != 0) {
            func_87F0A5BC(D_86B0E0E0);
        }
        break;
    case 9:
        func_86B09478();
        func_86B08214();
        func_87F0A5BC(D_86B0E0E0);
        break;
    case 10:
        func_87F0A5BC(D_86B0E0E0);
        break;
    case 11:
        func_87F022F0();
        break;
    }
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
    func_87F0C88C(D_86B181C0 + 0x1C);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern u8 *D_86B181C0;
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
void func_86B01720(s32 arg0) {
    *(s32 *)(D_86B181C0 + 0x18) = arg0;
    *(s32 *)D_86B181C0 = 0xC;
    *(s32 *)(D_86B181C0 + 4) = 0xD;
    StageContext_SetClearColor((u16)0xFFFF);
    StageFade_StartFromTransparent(0xA);
}
#endif

#ifdef VERSION_US
#include "PR/ultratypes.h"
extern u8 D_86B17A78[];
extern u8 *D_86B181C0;
extern void func_86B057B0(void);
extern void func_86B081B4(void);
extern void func_86B0CB1C(s32);
extern void func_86B04500(s32, s32, s32, s32);
extern void func_800280C0(void);
extern void func_800279C4(s32);
extern void func_80021ED8(s32);

// FAKE: `counter` is a parameter only to make this function have 3 automatic
// locals instead of 4; the real function takes no arguments (the caller at
// 0x86B01D48 does `jal func_86B01770` with a nop delay slot). All four names
// are register-only, so the named-local count changes nothing except where
// uopt places the temp slots: with 4 named locals the loop-cursor spill temp
// lands at 0x20 instead of the target's 0x24 (differ score 8, all other 199
// instructions identical). `counter` is the only variable assigned before any
// call, so as a parameter its incoming register is dead at entry and no spill
// code is added. Without the parameter the score is 8. The definition is K&R
// style so func_86B01A94 can make that argument-less call.


void func_86B01770(counter)
    s32 counter;
{
    s32 n;
    u32 i;
    s32 value;

    counter = *(s32 *)(D_86B17A78 + 0x284);
    *(s32 *)(D_86B17A78 + 0x284) = counter + 1;
    if (*(s32 *)D_86B17A78 < 4) {
        *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.016);
    } else {
        *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.01911111111111111);
    }
    if (*(f32 *)(D_86B17A78 + 0xF8) < 0.0f) {
        *(f32 *)(D_86B17A78 + 0xF8) += 6.2831855f;
    }
    func_86B057B0();
    func_86B0CB1C(counter);
    n = *(s32 *)(D_86B17A78 + 0x70);
    i = 0;
    if (n > 0) {
        do {
            value = *(s32 *)(D_86B17A78 + (i * 4) + 0x84);
            if (counter + 5 == value) {
                func_800280C0();
                n = *(s32 *)(D_86B17A78 + 0x70);
                value = *(s32 *)(D_86B17A78 + (i * 4) + 0x84);
            }
            if (counter == value) {
                *(s32 *)(D_86B17A78 + 0x44) = 3;
            }
            i += 1;
        } while (i < n);
    }
    if (counter == *(s32 *)(D_86B17A78 + 0x288)) {
        *(s32 *)(D_86B17A78 + 0x44) = 1;
        *(s32 *)(D_86B17A78 + 0x344) = 0;
        func_86B04500(0, *(s32 *)(D_86B17A78 + 0xC), *(s32 *)(D_86B17A78 + 0x10), 0);
        n = *(s32 *)(D_86B17A78 + 0xC);
        if (n == 1 && *(s32 *)(D_86B17A78 + 0x10) == 1) {
            func_86B04500(1, n, *(s32 *)(D_86B17A78 + 0x10), 0);
            func_86B04500(2, *(s32 *)(D_86B17A78 + 0xC), *(s32 *)(D_86B17A78 + 0x10), 0);
        }
    }
    if (counter == *(s32 *)(D_86B17A78 + 0x288) + 4) {
        *(s32 *)(D_86B17A78 + 0x33C) = 1;
    }
    func_86B081B4();
    if (counter >= *(s32 *)(D_86B17A78 + 0x288) + 0x64 &&
        (*(s32 *)(D_86B17A78 + 0x34) == 2 || *(s32 *)(D_86B17A78 + 0x34) == 0 || *(s32 *)(D_86B17A78 + 0x34) == 0x10 || *(s32 *)(D_86B17A78 + 0x34) == 0x11 || *(s32 *)(D_86B17A78 + 0x34) == 0x12) &&
        (*(s32 *)(D_86B17A78 + 0x38) == 2 || *(s32 *)(D_86B17A78 + 0x38) == 0 || *(s32 *)(D_86B17A78 + 0x38) == 0x10 || *(s32 *)(D_86B17A78 + 0x38) == 0x11 || *(s32 *)(D_86B17A78 + 0x38) == 0x12) &&
        (*(s32 *)(D_86B17A78 + 0x3C) == 2 || *(s32 *)(D_86B17A78 + 0x3C) == 0 || *(s32 *)(D_86B17A78 + 0x3C) == 0x10 || *(s32 *)(D_86B17A78 + 0x3C) == 0x11 || *(s32 *)(D_86B17A78 + 0x3C) == 0x12) &&
        (*(s32 *)(D_86B17A78 + 0x40) == 2 || *(s32 *)(D_86B17A78 + 0x40) == 0 || *(s32 *)(D_86B17A78 + 0x40) == 0x10 || *(s32 *)(D_86B17A78 + 0x40) == 0x11 || *(s32 *)(D_86B17A78 + 0x40) == 0x12) &&
        (*(s32 *)(D_86B17A78 + 0x344) == 0 || *(s32 *)(D_86B17A78 + 0x344) >= 0x8D)) {
        *(s32 *)D_86B181C0 = 7;
    }
    if (*(s32 *)(D_86B17A78 + 0x34) == 0xD || *(s32 *)(D_86B17A78 + 0x38) == 0xD || *(s32 *)(D_86B17A78 + 0x3C) == 0xD || *(s32 *)(D_86B17A78 + 0x40) == 0xD) {
        if ((*(s32 *)(D_86B17A78 + 0x498))++ < 0x19) {
            func_800279C4(0xCA0F);
        }
    }
    if (*(s32 *)(D_86B17A78 + 0x358) != 0) {
        if (*(s32 *)(D_86B17A78 + 0x354) != 0) {
            if (++(*(s32 *)(D_86B17A78 + 0x358)) == 0x46 && *(s32 *)D_86B17A78 < 4) {
                func_80021ED8(0x35);
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_8003F210(void *, s32);
extern void func_8003F03C(void *, void *);
extern void func_87F06430(void *, s32);
extern s32 func_87F00930(void);
extern void func_87F006BC(void);
extern void func_87F0277C(s32 *);
extern u8 D_86B17F30;
extern u8 *D_86B181C0;
extern u8 D_86B16DA0[];
extern u8 *D_86B18208;
extern s32 D_86B17910;
extern s32 StageContext_GetFadeMode(void);
extern void func_86B00994(void);
extern void func_86B08978(void);
extern s32 func_87F01A40(void);
extern s32 func_87F006AC(void);
extern void func_86B01720(s32);
extern void func_86B08B74(void);
extern void func_86B08CF4(void);
extern void func_86B08E10(void);
extern void func_86B08F20(void);
extern void func_86B09380(void);
extern s32 Fragment64_UpdateBounceAndConfirm(void *);
extern u8 D_86B0E0E0[];
extern s32 D_86B17AAC;
extern s32 D_86B17AB8;
extern s32 D_86B0D164;
extern s32 func_87F02104(void);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void StageFade_StartFromOpaque(s32);
extern u8 D_86B17340[];
extern u8 D_86B17364[];
extern u32 D_86B16D90[];
extern u8 D_87F15B70;
extern void func_86B09834(void);
extern u8 D_86B0E148[];
extern void func_87F0D5B8(void *);
extern s32 func_87F0C6F4(void *);
extern void func_800279C4(s32);
extern void func_80021ED8(s32);
extern u8 D_86B17A78[];
#define FRAG_CONFIRM() \
    if (*(s32 *)(D_86B17A78 + 0x35C) != 0) { \
        if (Fragment64_UpdateBounceAndConfirm(D_86B0E0E0) != 0) { \
            if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) == 1) { \
                func_86B01720(2); \
            } else { \
                *(s32 *)D_86B181C0 = 0xB; \
            } \
        } \
    }
void func_86B01A94(void) {
    // D_86B17AB0/D_86B17AB4 (state record +0x38). As a function-scope static the
    // two clears share one `lui $at` and get no base register, as in retail.
    static struct { s32 a, b; } sStatePair;
    s32 i;
    u8 *p;
    s32 pad;
    if (func_87F00930() == 0) {
        func_87F006BC();
    }
    func_87F0277C((s32 *)&D_86B17F30);
    switch (*(s32 *)D_86B181C0) {
    case 0:
        for (i = 0; i < 4; i++) {
            func_8003F1DC(D_86B16DA0 + i * 0x168);
            p = D_86B18208 + i * 0x18;
            p[0x12] = 0xFF;
            p[0x13] = 0xFF;
            p[0x14] = 0xFF;
            p[0x15] = 0;
        }
        func_8003F1DC((u8 *)&D_86B17910);
        if (StageContext_GetFadeMode() == 0) {
            *(s32 *)D_86B181C0 = 1;
        }
        break;
    case 1:
        func_86B00994();
        break;
    case 2:
        func_86B08978();
        break;
    case 3:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            if (func_87F006AC() == 1) {
                func_800279C4(0x2F00);
            }
            if ((*(s32 *)(D_86B17A78 + 0x284))++ == 0x41) {
                func_80021ED8(0x35);
            }
            if (func_87F006AC() == 2) {
                *(s32 *)D_86B181C0 = 4;
                D_86B17AAC = 0;
                sStatePair.a = 0;
                sStatePair.b = 0;
                D_86B17AB8 = 0;
                *(s32 *)(D_86B17A78 + 0x284) = 0;
            }
            break;
        case 3:
            func_86B01720(0);
            break;
        case 4:
            func_86B01720(1);
            break;
        }
        break;
    case 4:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_86B08B74();
            break;
        case 3:
            func_86B01720(0);
            break;
        case 4:
            func_86B01720(1);
            break;
        }
        break;
    case 5:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_86B08CF4();
            break;
        case 3:
            func_86B01720(0);
            break;
        case 4:
            func_86B01720(1);
            break;
        }
        break;
    case 6:
        switch (func_87F01A40()) {
        case 0:
            func_86B01770();
            break;
        case 2:
            break;
        case 3:
            func_86B01720(0);
            break;
        case 4:
            func_86B01720(1);
            break;
        }
        break;
    case 7:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_86B08E10();
            break;
        case 3:
            func_86B01720(0);
            break;
        case 4:
            func_86B01720(1);
            break;
        }
        break;
    case 8:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_86B08F20();
            FRAG_CONFIRM();
            break;
        case 3:
            func_86B01720(0);
            break;
        case 4:
            func_86B01720(1);
            break;
        }
        break;
    case 9:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_86B09380();
            if (Fragment64_UpdateBounceAndConfirm(D_86B0E0E0) != 0) {
                if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) == 1) {
                    func_86B01720(2);
                } else {
                    *(s32 *)D_86B181C0 = 0xB;
                }
            }
            break;
        case 3:
            func_86B01720(0);
            break;
        case 4:
            func_86B01720(1);
            break;
        }
        break;
    case 10:
        func_86B09380();
        if (Fragment64_UpdateBounceAndConfirm(D_86B0E0E0) != 0) {
            if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) == 1) {
                func_86B01720(2);
            } else {
                *(s32 *)D_86B181C0 = 0xB;
            }
        }
        break;
    case 11:
        D_86B0D164 = 1;
        func_86B09380();
        switch (func_87F02104()) {
        case 1:
            StageContext_SetClearColor(0);
            *(s32 *)D_86B181C0 = 0xC;
            *(s32 *)(D_86B181C0 + 4) = 0;
            StageFade_StartFromTransparent(0xA);
            for (i = 0; i < 4; i++) {
                func_8003F03C(D_86B17340 + i * 0x168, &D_87F15B70);
                func_87F06430(D_86B17364 + i * 0x168, i);
                *(f32 *)(D_86B17340 + i * 0x168 + 0x38) = 0.16666667f;
                *(f32 *)(D_86B17340 + i * 0x168 + 0x34) = 0.16666667f;
                *(f32 *)(D_86B17340 + i * 0x168 + 0x30) = 0.16666667f;
                *(f32 *)(D_86B17340 + i * 0x168 + 0x28) = 50.0f;
                func_8003F114(D_86B17340 + i * 0x168, 0, -1, D_86B16D90[i]);
                func_8003F210(D_86B17340 + i * 0x168, 0);
                ModelAnim_SetFrame(D_86B17340 + i * 0x168, guRandom() % 30);
            }
            break;
        case 2:
            func_86B01720(0);
            break;
        case 3:
            func_86B01720(1);
            break;
        }
        break;
    case 12:
        func_86B09834();
        if (StageContext_GetFadeMode() == 1) {
            *(s32 *)D_86B181C0 = *(s32 *)(D_86B181C0 + 4);
            if (*(s32 *)D_86B181C0 == 0) {
                func_86B007D0();
                StageFade_StartFromOpaque(0xA);
            }
        }
        break;
    }
    func_87F0D5B8(D_86B0E148);
    if (func_87F0C6F4(D_86B181C0 + 0x1C) != 0) {
        *(s32 *)(D_86B181C0 + 0x18) = 3;
        *(s32 *)D_86B181C0 = 0xD;
    }
}

// Rest of the state record after sStatePair (0x86B17AB8-0x86B17F2B).
static u8 sStateTail[0x474];

#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern u8 * D_86B181C0;
void func_86B02180(void) { s32 mode; u8 **state; func_800086A4(2); StageFade_StartFromOpaque(0xA); mode = 0xD; state = (u8 **)((u8 *)&D_86B181C0 + 0); do { func_80064D28(); func_86B01A94(); func_86B014E8(); } while (*(s32 *)*state != mode); }
#endif

#ifdef VERSION_US
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern s32 D_86B0E0A4;
extern s32 D_86B0E0B0;
extern u8 D_86B0E0E0[];
extern s32 D_86B0E100;
extern u8 D_86B0E148[];
extern u8 D_86B181C8[];

s32 func_86B021E8(s32 arg0, void *arg1) {
    void *stage;
    s32 pad; // FAKE: unused stack space; diff score 54 without it.
    s32 flags;

    main_pool_push_state(0x4B414D45);
    D_86B181C0 = D_86B181C8;
    *(void **)((u8 *)D_86B181C0 + 0xC) = arg1;
    if ((*(u8 **)((u8 *)D_86B181C0 + 0xC))[0x2180] == 4) {
        func_80027EE0(0xFFF);
    }
    Gfx_InitDisplayListBuffers(0x20000, 0);
    stage = func_800082E0(0, 0, 2, 1, 2, 1);
    func_8004C09C(303);
    D_86B0E0A4 = func_8004D690(44);
    func_87F06EAC(105, &D_86B0E0A8, *(void **)((u8 *)D_86B181C0 + 0xC));
    func_87F09EBC(D_86B0E0E0, *(void **)((u8 *)D_86B181C0 + 0xC));
    func_87F0D48C(D_86B0E148, *(void **)((u8 *)D_86B181C0 + 0xC), 0);
    func_8004DDF4(151);
    func_8004DDF4(216);
    func_8004DDF4(211);
    func_8004DDF4(209);
    func_8004DDF4(213);
    func_8004DDF4(203);
    func_8004DDF4(204);
    func_8004DDF4(207);
    func_8004DDF4(149);
    func_8004DDF4(150);
    //!bug: flags is never assigned; this ORs whatever the stack slot holds.
    func_80047588(D_86B0E0B0 | 0x3D | D_86B0E100 | flags, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_86B00A3C();
    func_80008514(stage);
    func_86B02180();
    func_80008574();
    func_80006158();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4B414D45);
    func_87F0F480(*(void **)((u8 *)D_86B181C0 + 0xC));
    func_80027EE0(0xFFE);
    return *(s32 *)((u8 *)D_86B181C0 + 0x18);
}

#endif
#ifdef VERSION_US
extern u16 D_86B12AE8[];
extern u16 D_80094904;
extern u8 D_86B17A78[];
extern u8 D_86B16DA0[];
extern u8 *D_86B18208;
extern u8 *D_86B181C0;
extern s32 D_86B17C18;
extern f32 D_86B0D20C[];
extern f32 D_86B0D2D4[];
extern f32 __cosf(f32);
extern f32 __sinf(f32);
extern f32 sqrtf(f32);
extern void func_8003F210(void *, s32);
extern void func_8003F3BC(void *, s32);
extern s32 ModelAnim_IsFinished(void *);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern s32 func_8003EC54(s32 *);
extern void func_8002781C(u16 resource_id, u8 mode, ...);
#define SPEED_CALC(m, k1, k2, k3, k4, k5, k6, k7) \
    ModelAnim_SetSpeed(m, (s32)(81920.0f * sqrtf((*(f32 *)(D_86B17A78 + idx * 8 + 0x14) - *(f32 *)(D_86B17A78 + idx * 8 + 0x98)) * (*(f32 *)(D_86B17A78 + idx * 8 + 0x14) - *(f32 *)(D_86B17A78 + idx * 8 + 0x98)) + (*(f32 *)(D_86B17A78 + idx * 8 + 0x18) - *(f32 *)(D_86B17A78 + idx * 8 + 0x9C)) * (*(f32 *)(D_86B17A78 + idx * 8 + 0x18) - *(f32 *)(D_86B17A78 + idx * 8 + 0x9C))) \
        / sqrtf((130.0f * (__cosf(0.016f) - __cosf(0.0f))) * (130.0f * (__cosf(0.016f) - __cosf(0.0f))) + (130.0f * (__sinf(0.016f) - __sinf(0.0f))) * (130.0f * (__sinf(0.016f) - __sinf(0.0f))))))
s32 func_86B023FC(s32 arg0, u8 *arg1) {
    u8 *s1;
    s32 state;
    s32 idx;
    s32 v;

    idx = *(s32 *)(arg1 + 0x14);
    *(s32 *)(arg1 + 0xA0) = -0x100;
    if (D_80094904 != D_86B12AE8[idx] && arg0 != 0 && arg0 == 2) {
        *(f32 *)(arg1 + 0x24) = *(f32 *)(D_86B17A78 + idx * 8 + 0x14);
        *(f32 *)(arg1 + 0x2C) = *(f32 *)(D_86B17A78 + idx * 8 + 0x18);
        *(s16 *)(arg1 + 0x20) = *(s16 *)(D_86B17A78 + idx * 2 + 0xE8);
        s1 = D_86B17A78 + idx * 4;
        switch (*(s32 *)(s1 + 0x34)) {
        case 0:
            func_8003F210((D_86B16DA0 + idx * 0x168), 0);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            break;
        case 1:
            func_8003F210((D_86B16DA0 + idx * 0x168), 1);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = 2;
            }
            break;
        case 2:
        case 4:
            func_8003F210((D_86B16DA0 + idx * 0x168), 2);
            SPEED_CALC((D_86B16DA0 + idx * 0x168), 0, 0, 0, 0, 0, 0, 0);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            break;
        case 3:
            func_8003F210((D_86B16DA0 + idx * 0x168), 3);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = 0;
            }
            break;
        case 5:
            func_8003F210((D_86B16DA0 + idx * 0x168), 4);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = 6;
            }
            break;
        case 7:
            func_8003F210((D_86B16DA0 + idx * 0x168), 2);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            break;
        case 8:
            func_8003F210((D_86B16DA0 + idx * 0x168), 2);
            SPEED_CALC((D_86B16DA0 + idx * 0x168), 0, 0, 0, 0, 0, 0, 0);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            break;
        case 9:
            func_8003F210((D_86B16DA0 + idx * 0x168), 5);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            ModelAnim_SetSpeed((D_86B16DA0 + idx * 0x168), 0x4000);
            break;
        case 6:
        case 12:
            func_8003F210((D_86B16DA0 + idx * 0x168), 5);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            ModelAnim_SetSpeed((D_86B16DA0 + idx * 0x168), 0x10000);
            break;
        case 10:
            func_8003F210((D_86B16DA0 + idx * 0x168), 6);
            ModelAnim_SetSpeed((D_86B16DA0 + idx * 0x168), 0x18000);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                v = *(s32 *)(s1 + 0xC8);
                *(s32 *)(s1 + 0x34) = v;
                if (v == 0xE) {
                    func_8002781C(0xAF03, (u8)idx, D_86B17A78 + idx * 2 + 0x49C);
                }
            }
            if (*(f32 *)(s1 + 0x48) <= 45.0f) {
                if (*(s32 *)(s1 + 0xC8) == 0xE) {
                    *(s32 *)(s1 + 0x34) = *(s32 *)(s1 + 0xC8);
                    *(f32 *)(s1 + 0x48) = 45.0f;
                    *(f32 *)(s1 + 0xD8) = (130.0f - *(f32 *)(s1 + 0x48)) / 14.0f;
                    func_8002781C(0xAF03, (u8)idx, D_86B17A78 + idx * 2 + 0x49C);
                }
            }
            break;
        case 11:
            func_8003F210((D_86B16DA0 + idx * 0x168), 6);
            ModelAnim_SetSpeed((D_86B16DA0 + idx * 0x168), 0x18000);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = *(s32 *)(s1 + 0xC8);
            }
            break;
        case 13:
            func_8003F210((D_86B16DA0 + idx * 0x168), 7);
            ModelAnim_SetSpeed((D_86B16DA0 + idx * 0x168), 0x10000);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (func_8003EC54((s32 *)(D_86B16DA0 + idx * 0x168)) == 0) {
                if (*(s32 *)(s1 + 0x1A4) != 0) {
                    *(s32 *)(s1 + 0x1B4) += 1;
                }
            }
            if (*(s32 *)(s1 + 0x1A4) != 0) {
                *(s32 *)(s1 + 0x1A4) += 1;
            }
            if (*(s32 *)(s1 + 0x214) != 0) {
                *(s32 *)(s1 + 0x214) -= 1;
                ((s32 *)(D_86B17A78 + idx * 20 + 0x220))[*(s32 *)(s1 + 0x1B4)] += 1;
            }
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                if (*(s32 *)(s1 + 0x1A4) != 0) {
                    *(s32 *)(s1 + 0x1A4) = 0;
                }
                if (*(s32 *)D_86B181C0 == 6) {
                    *(s32 *)(s1 + 0x34) = 7;
                }
                if (D_86B17C18 != 0) {
                    *(s32 *)(s1 + 0x34) = 0x15;
                }
            }
            break;
        case 14:
            func_8003F210((D_86B16DA0 + idx * 0x168), 8);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = 2;
            }
            break;
        case 15:
            func_8003F210((D_86B16DA0 + idx * 0x168), 9);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 1);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(f32 *)(s1 + 0x48) = (f32)((f64)*(f32 *)(s1 + 0x48) + 35.58583333333334);
                *(s32 *)(s1 + 0x34) = 7;
            }
            break;
        case 16:
            if (*(f32 *)(s1 + 0x48) != 180.0f) {
                *(s32 *)(arg1 + 0xA0) = 0x9F;
            }
            func_8003F210((D_86B16DA0 + idx * 0x168), 10);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = 0x11;
                func_8002781C(0xAF07, (u8)idx, D_86B17A78 + idx * 2 + 0x49C);
            }
            break;
        case 17:
            func_8003F210((D_86B16DA0 + idx * 0x168), 11);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = 0x12;
            }
            break;
        case 18:
            func_8003F210((D_86B16DA0 + idx * 0x168), 12);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                *(s32 *)(s1 + 0x34) = 0;
            }
            break;
        case 19:
            func_8003F210((D_86B16DA0 + idx * 0x168), 13);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 2);
            if (ModelAnim_IsFinished((D_86B16DA0 + idx * 0x168))) {
                if (D_86B17C18 != 0) {
                    *(s32 *)(s1 + 0x34) = 0x14;
                } else {
                    *(s32 *)(s1 + 0x34) = 7;
                }
            }
            break;
        case 20:
            func_8003F210((D_86B16DA0 + idx * 0x168), 14);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 3);
            break;
        case 21:
            func_8003F210((D_86B16DA0 + idx * 0x168), 2);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            break;
        case 22:
        case 23:
            func_8003F210((D_86B16DA0 + idx * 0x168), 5);
            func_8003F3BC((D_86B16DA0 + idx * 0x168), 0);
            ModelAnim_SetSpeed((D_86B16DA0 + idx * 0x168), 0x10000);
            break;
        }
        switch (*(s32 *)(s1 + 0x34)) {
        case 0xD: {
            u8 *p = D_86B18208 + idx * 0x18; *(f32 *)(p + 4) = *(f32 *)(D_86B17A78 + idx * 8 + 0x14); v = func_8003EC54((s32 *)(D_86B16DA0 + idx * 0x168));
            *(f32 *)(p + 8) = (f32)((f64)D_86B0D20C[v] * 0.16666666666666666 * 50.0 - 5.260833);
            *(f32 *)(p + 0xC) = *(f32 *)(D_86B17A78 + idx * 8 + 0x18);
            break; }
        case 0xE: {
            u8 *p = D_86B18208 + idx * 0x18; *(f32 *)(p + 4) = *(f32 *)(D_86B17A78 + idx * 8 + 0x14); v = func_8003EC54((s32 *)(D_86B16DA0 + idx * 0x168));
            *(f32 *)(p + 8) = (f32)((f64)D_86B0D2D4[v] * 0.16666666666666666 * 50.0 - 5.260833);
            *(f32 *)(p + 0xC) = *(f32 *)(D_86B17A78 + idx * 8 + 0x18);
            break; }
        default: {
            u8 *p =  D_86B18208 + idx * 0x18;
            *(f32 *)(p + 4) = *(f32 *)(D_86B17A78 + idx * 8 + 0x14);
            *(f32 *)(p + 8) = 55.0f;
            *(f32 *)(p + 0xC) = *(f32 *)(D_86B17A78 + idx * 8 + 0x18);
            break; }
        }
    }
    D_86B12AE8[idx] = D_80094904;
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern s32 func_8003EC54(s32 *);
extern u16 D_80094904;
extern u16 D_86B178E0;
extern s32 D_86B17910;
extern s32 D_86B17ABC;
extern void func_8003F210(void *, s32);
extern void func_800279C4(s32);
extern void func_86B0952C(void);
s32 func_86B03228(s32 arg0, s32 arg1) {
    s32 i;
    if (D_86B178E0 != D_80094904) {
        if (guRandom() % 300 == 0) {
            ModelAnim_SetEventFrame((void *)&D_86B17910, 0);
        }
        if (arg0 != 0 && arg0 == 2) {
            switch (D_86B17ABC) {
            case 0:
                func_8003F210((void *)&D_86B17910, 0);
                break;
            case 1:
                func_8003F210((void *)&D_86B17910, 1);
                if (*(s32 *)D_86B17A78 < 5) {
                    if (func_8003EC54(&D_86B17910) == 0) {
                        func_800225C4(2);
                    }
                }
                if (func_8003EC54(&D_86B17910) == 5) {
                    func_800279C4(0xAF01);
                }
                break;
            case 2:
                func_8003F210((void *)&D_86B17910, 2);
                if (func_8003EC54(&D_86B17910) == 0) {
                    func_800279C4(0xAF08);
                }
                if (func_8003EC54(&D_86B17910) == 5) {
                    func_800279C4(0xAF00);
                    if (*(s32 *)D_86B17A78 < 5) {
                        if (*(s32 *)D_86B17A78 < 4) {
                            func_80021ED8(0x36);
                        } else {
                            func_80021ED8(0x65);
                        }
                    }
                }
                if (func_8003EC54(&D_86B17910) == 5) {
                    if (*(s32 *)D_86B17A78 < 5) {
                        func_86B0952C();
                    }
                }
                if (ModelAnim_IsFinished((void *)&D_86B17910) != 0) {
                    D_86B17ABC = 0;
                }
                break;
            case 3:
                func_8003F210((void *)&D_86B17910, 1);
                if (func_8003EC54(&D_86B17910) >= 5) {
                    D_86B17ABC = 5;
                }
                break;
            case 4:
                func_8003F210((void *)&D_86B17910, 1);
                if (func_8003EC54(&D_86B17910) >= 5) {
                    D_86B17ABC = 6;
                }
                break;
            case 5:
                func_8003F210((void *)&D_86B17910, 1);
                ModelAnim_SetSpeed((u8 *)&D_86B17910, 0xFFFF0000);
                if (func_8003EC54(&D_86B17910) < 0) {
                    D_86B17ABC = 0;
                    func_800280EC();
                }
                if (func_8003EC54(&D_86B17910) == 4) {
                    for (i = 2; i != 10; i += 4) {}
                }
                break;
            case 6:
                func_8003F210((void *)&D_86B17910, 1);
                ModelAnim_SetSpeed((u8 *)&D_86B17910, 0xFFFF0000);
                if (func_8003EC54(&D_86B17910) < 0) {
                    D_86B17ABC = 3;
                }
                if (func_8003EC54(&D_86B17910) == 4) {
                    for (i = 2; i != 10; i += 4) {}
                }
                break;
            }
        }
    }
    D_86B178E0 = D_80094904;
    return 0;
}

#endif

#ifdef VERSION_US
extern u8 D_86B16DA0[];
extern u8 D_86B17A78[];
void func_86B05484(f32 arg0, f32 arg1, f32 arg2, s32 arg3);
extern s32 func_8003EC54(s32 *);
s32 func_86B0355C(s32 arg0, u8 *arg1) {
    s32 idx = *(s32 *)(arg1 + 0x14);
    s32 pad; // FAKE
    u8 *model;

    if ((arg0 != 0) && (arg0 == 2)) {
        model = D_86B16DA0 + idx * 0x168;
        *(f32 *)(arg1 + 0x24) = *(f32 *)(model + 0xAC);
        *(f32 *)(arg1 + 0x2C) = *(f32 *)(model + 0xB4);
        if (*(s32 *)(D_86B17A78 + idx * 4 + 0x34) == 16 && *(f32 *)(D_86B17A78 + idx * 4 + 0x48) != 180.0f) {
            if (func_8003EC54((s32 *)model) % 3 == 0) {
                func_86B05484(*(f32 *)(model + 0xAC), *(f32 *)(model + 0xB0), *(f32 *)(model + 0xB4), 0xFF);
            }
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
typedef struct { f32 x, y, z, w; } V16;
extern void *D_87F119DC;
extern void *D_87F119D8;
extern void func_87F026E8(void *, void *);
extern u32 D_86B0D838[];
extern u32 D_86B0D848;
extern u32 D_86B0D83C;
extern u32 D_86B0D840;
extern u32 D_86B0D844;
extern f32 D_86B0D1FC[];
extern s32 D_86B17AAC;
extern s32 D_86B17AB0;
extern s32 D_86B17AB4;
extern s32 D_86B17AB8;
extern s32 D_86B17B40[4];
extern s32 D_86B17B44, D_86B17B48, D_86B17B4C;
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern s32 func_86B05548(s32 *);
extern f32 func_86B05738(f32);
extern void func_86B04970(s32, s32, s32, s32, f32, f32, f32);
extern void func_86B052BC(s32);
extern void func_8003EF60(void *);
#define V20 (*(u32 *)((u8 *)D_87F119DC + 0x20))
void func_86B03628(void) {
    u32 m;
    s32 i;
    s32 st;
    s32 changed = 0;
    s32 result;
    s32 buttons;
    s32 d0;
    s32 mode;
    s32 d2;
    s32 d1;
    u8 *p;
    s32 n;
    f32 fv;
    s16 rnd;
    f32 ang;

    mode = V20 / 1000;
    d2 = V20 / 100 % 10;
    d1 = V20 / 10 % 10;
    d0 = V20 % 10;
    switch (mode) {
    case 0:
        if (D_86B17A78 + d1 * 4) {} // FAKE: makes uopt create this item first so the &D_86B0D1FC[i] spill takes retail's stack slot
        switch (*(s32 *)(D_86B17A78 + 0x44)) {
        case 1:
            break;
        case 2:
            if (d0 != 1) {
                changed = 1;
                func_86B04500(d1, mode, d2, 1);
            }
            break;
        }
        break;
    case 1:
        switch (*(s32 *)(D_86B17A78 + 0x44)) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            if (d0 != 1) {
                changed = 1;
                func_86B04500(d1, mode, d2, 1);
            }
            break;
        }
        break;
    case 2:
        switch (*(s32 *)(D_86B17A78 + 0x44)) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            if (d0 != 1) {
                changed = 1;
                func_86B04500(d1, mode, d2, 1);
            }
            break;
        }
        break;
    default:
        break;
    }

    st = *(s32 *)(D_86B17A78 + 0x344);
    if (st != 0) {
        if (st < 0x47) {
            *(s32 *)((u8 *)D_87F119DC + 0xC4) = 0x9F;
        } else if (st < 0x6E) {
            *(s32 *)((u8 *)D_87F119DC + 0xC4) = 0x1B7 - st * 4;
        } else {
            *(s32 *)((u8 *)D_87F119DC + 0xC4) = 0;
        }
    }

    result = func_86B05548(&buttons);
    if (result != 0) {
        if (result == 1) {
            if (mode == 0) {
                for (i = 0; i < 4; i++) {
                    if (D_86B0D838[i] & buttons) {
                        if (d2 != 0) {
                            if (d2 == 1) {
                                ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x1F4;
                                ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 1;
                                ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                            }
                        } else {
                            ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x3E8;
                            ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 0;
                            ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                        }
                        changed = 1;
                        ((s32 *)(D_86B17A78 + 0x34))[i] = 0xB;
                        ((s32 *)(D_86B17A78 + 0xC8))[i] = 0xD;
                        func_8002781C(0xAF05, i, D_86B17A78 + i * 2 + 0x49C);
                        func_86B04970(mode, d2, buttons, result,
                                      *(f32 *)((u8 *)D_87F119DC + 0x48),
                                      *(f32 *)((u8 *)D_87F119DC + 0x4C),
                                      *(f32 *)((u8 *)D_87F119DC + 0x50));
                        *(s32 *)(D_86B17A78 + 0x354) = 1;
                    } else {
                        if (((s32 *)(D_86B17A78 + 0x34))[i] == 6 || ((s32 *)(D_86B17A78 + 0x34))[i] == 10) {
                            ((s32 *)(D_86B17A78 + 0xC8))[i] = 0xE;
                        }
                    }
                }
            } else if (mode == 1) {
                for (i = 0; i < 4; i++) {
                    if ((m = D_86B0D838[i]) & buttons) {
                        switch (d2) {
                        case 0:
                            ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 2;
                            ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x64;
                            ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                            ((s32 *)(D_86B17A78 + 0x214))[i] += 1;
                            n = --*(s32 *)(D_86B17A78 + d1 * 4 + 0x348);
                            if (n < 0) {
                                *(s32 *)(D_86B17A78 + d1 * 4 + 0x348) = 0;
                                n = 0;
                            }
                            func_86B04970(mode, d2, m, result,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].x,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].y,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].z);
                                                    break;
                        case 1:
                            ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 2;
                            ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x64;
                            ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                            ((s32 *)(D_86B17A78 + 0x214))[i] += 1;
                            n = --*(s32 *)(D_86B17A78 + d1 * 4 + 0x348);
                            if (n < 0) {
                                *(s32 *)(D_86B17A78 + d1 * 4 + 0x348) = 0;
                                n = 0;
                            }
                            func_86B04970(mode, d2, m, result,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].x,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].y,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].z);
                                                    break;
                        }
                        ((s32 *)(D_86B17A78 + 0xC8))[i] = 0xD;
                        if (((s32 *)(D_86B17A78 + 0x4A4))[i] == 0) {
                            func_8002781C(0xAF05, i, D_86B17A78 + i * 2 + 0x49C);
                            ((s32 *)(D_86B17A78 + 0x4A4))[i] = 1;
                        }
                    }
                }
                if (*(s32 *)(D_86B17A78 + d1 * 4 + 0x348) <= 0) {
                    *(s32 *)(D_86B17A78 + d1 * 4 + 0x348) = 0;
                    *(s32 *)(D_86B17A78 + 0x354) = 1;
                    changed = 1;
                }
            } else if (mode == 2) {
                for (i = 0; i < 4; i++) {
                    if (D_86B0D838[i] & buttons) {
                        ((s32 *)(D_86B17A78 + 0x34))[i] = 0x10;
                        fv = func_86B05738(((f32 *)(D_86B17A78 + 0x58))[i]);
                        ((f32 *)(D_86B17A78 + 0x58))[i] = fv;
                        ang = D_86B0D1FC[i];
                        ((f32 *)(D_86B17A78 + 0xFC))[i] = fv - ang;
                        if (fv < ang) {
                            ((f32 *)(D_86B17A78 + 0xFC))[i] += 6.2831855f;
                        }
                    }
                }
                func_800279C4(0xAF06);
                if (*(s32 *)(D_86B17A78 + 0x344) == 0) {
                    func_86B052BC(0);
                    *(s32 *)(D_86B17A78 + 0x344) = 1;
                    for (i = 0; i < 4; i++) {
                        if (D_86B0D838[i] & buttons) {
                            func_8002781C(0xAF0B, i, D_86B17A78 + i * 2 + 0x49C);
                        }
                    }
                }
            }
        } else {
            if (mode == 0) {
                for (i = 0; i < 4; i++) {
                    if (D_86B0D838[i] & buttons) {
                        if (d2 != 0) {
                            if (d2 == 1) {
                                ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x1F4;
                                ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 1;
                                ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                            }
                        } else {
                            ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x3E8;
                            ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 0;
                            ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                        }
                        changed = 1;
                        ((s32 *)(D_86B17A78 + 0xC8))[i] = 0xD;
                        func_8002781C(0xAF05, i, D_86B17A78 + i * 2 + 0x49C);
                        func_86B04970(mode, d2, D_86B0D838[i], result,
                                      *(f32 *)((u8 *)D_87F119DC + 0x48),
                                      *(f32 *)((u8 *)D_87F119DC + 0x4C),
                                      *(f32 *)((u8 *)D_87F119DC + 0x50));
                        *(s32 *)(D_86B17A78 + 0x354) = 1;
                    } else {
                        if (((s32 *)(D_86B17A78 + 0x34))[i] == 6 || ((s32 *)(D_86B17A78 + 0x34))[i] == 10) {
                            ((s32 *)(D_86B17A78 + 0xC8))[i] = 0xE;
                        }
                    }
                }
            } else if (mode == 1) {
                for (i = 0; i < 4; i++) {
                    if ((m = D_86B0D838[i]) & buttons) {
                        switch (d2) {
                        case 0:
                            ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 2;
                            ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x64;
                            ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                            ((s32 *)(D_86B17A78 + 0x214))[i] += 1;
                            n = --*(s32 *)(D_86B17A78 + d1 * 4 + 0x348);
                            if (n < 0) {
                                *(s32 *)(D_86B17A78 + d1 * 4 + 0x348) = 0;
                                n = 0;
                            }
                            func_86B04970(mode, d2, m, result,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].x,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].y,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].z);
                                                    break;
                        case 1:
                            ((s32 (*)[5])(D_86B17A78 + 0x1C4))[i][((s32 *)(D_86B17A78 + 0x1B4))[i]] = 2;
                            ((s32 *)(D_86B17A78 + 0x17C))[i] += 0x64;
                            ((s32 *)(D_86B17A78 + 0x1A4))[i] = 2;
                            ((s32 *)(D_86B17A78 + 0x214))[i] += 1;
                            n = --*(s32 *)(D_86B17A78 + d1 * 4 + 0x348);
                            if (n < 0) {
                                *(s32 *)(D_86B17A78 + d1 * 4 + 0x348) = 0;
                                n = 0;
                            }
                            func_86B04970(mode, d2, m, result,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].x,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].y,
                                          ((V16 *)((u8 *)D_87F119DC + 0xD0))[9 - n].z);
                                                    break;
                        }
                        ((s32 *)(D_86B17A78 + 0xC8))[i] = 0xD;
                        if (((s32 *)(D_86B17A78 + 0x4A4))[i] == 0) {
                            func_8002781C(0xAF05, i, D_86B17A78 + i * 2 + 0x49C);
                            ((s32 *)(D_86B17A78 + 0x4A4))[i] = 1;
                        }
                    }
                }
                if (*(s32 *)(D_86B17A78 + d1 * 4 + 0x348) <= 0) {
                    *(s32 *)(D_86B17A78 + d1 * 4 + 0x348) = 0;
                    *(s32 *)(D_86B17A78 + 0x354) = 1;
                    changed = 1;
                }
            } else if (mode == 2) {
                for (i = 0; i < 4; i++) {
                    if (!(D_86B0D838[i] & buttons)) {
                    } else if (D_86B0D838[i] & buttons) {
                        ((s32 *)(D_86B17A78 + 0x34))[i] = 0x10;
                        fv = func_86B05738(((f32 *)(D_86B17A78 + 0x58))[i]);
                        ((f32 *)(D_86B17A78 + 0x58))[i] = fv;
                        ang = D_86B0D1FC[i];
                        ((f32 *)(D_86B17A78 + 0xFC))[i] = fv - ang;
                        if (fv < ang) {
                            ((f32 *)(D_86B17A78 + 0xFC))[i] += 6.2831855f;
                        }
                    }
                }
                func_800279C4(0xAF06);
                if (*(s32 *)(D_86B17A78 + 0x344) == 0) {
                    func_86B052BC(0);
                    *(s32 *)(D_86B17A78 + 0x344) = 1;
                    for (i = 0; i < 4; i++) {
                        if (D_86B0D838[i] & buttons) {
                            func_8002781C(0xAF0B, i, D_86B17A78 + i * 2 + 0x49C);
                        }
                    }
                }
            }
        }
    }

    if (changed != 0 && mode == 1) {
        for (i = 0; i < 4; i++) {
            if (!(D_86B0D838[i] & buttons)) {
                if (((s32 *)(D_86B17A78 + 0x34))[i] == 6 || ((s32 *)(D_86B17A78 + 0x34))[i] == 10) {
                    ((s32 *)(D_86B17A78 + 0xC8))[i] = 0xE;
                }
            }
        }
        *(s32 *)(D_86B17A78 + 0x340) = 1;
    }

    if (*(s32 *)(D_86B17A78 + 0x44) == 0) {
        changed = 1;
    }
    if (*(s32 *)(D_86B17A78 + 0x344) != 0) {
        *(s32 *)(D_86B17A78 + 0x344) += 1;
        fv = (f32)(guRandom() % 0x24);
        rnd = guRandom() % 0xFFFF;
        if (*(s32 *)(D_86B17A78 + 0x344) == 0x19) {
            n = ((u16)rnd) >> 4;
            *(s32 *)(D_86B17A78 + 0x354) = 1;
            *(s32 *)(D_86B17A78 + 0x284) = *(s32 *)(D_86B17A78 + 0x288) + 0x64;
            func_86B05484(D_80088E50[n] * fv, 35.0f, D_80087E50[n] * fv, 0xFF);
        }
        if (*(s32 *)(D_86B17A78 + 0x344) == 0x1C) {
            n = ((u16)rnd) >> 4;
            func_86B05484(D_80088E50[n] * fv, 35.0f, D_80087E50[n] * fv, 0xFF);
        }
        if (*(s32 *)(D_86B17A78 + 0x344) == 0x1F) {
            n = ((u16)rnd) >> 4;
            func_86B05484(D_80088E50[n] * fv, 35.0f, D_80087E50[n] * fv, 0xFF);
        }
        if (*(s32 *)(D_86B17A78 + 0x344) == 0x28) {
            n = ((u16)rnd) >> 4;
            func_86B05484(D_80088E50[n] * fv, 35.0f, D_80087E50[n] * fv, 0xFF);
        }
        if (*(s32 *)(D_86B17A78 + 0x344) == 0x2B) {
            n = ((u16)rnd) >> 4;
            func_86B05484(D_80088E50[n] * fv, 35.0f, D_80087E50[n] * fv, 0xFF);
        }
    }

    if (mode == 1) {
        switch (d2) {
        case 0:
            ModelAnim_SetEventFrame((u8 *)D_87F119DC + 0x24, (s16)(9 - *(s32 *)(D_86B17A78 + d1 * 4 + 0x348)));
            func_8003EF60((u8 *)D_87F119DC + 0x24);
            break;
        case 1:
            ModelAnim_SetEventFrame((u8 *)D_87F119DC + 0x24, (s16)(9 - *(s32 *)(D_86B17A78 + d1 * 4 + 0x348)));
            func_8003EF60((u8 *)D_87F119DC + 0x24);
            break;
        }
    }
    if (changed != 0) {
        *(s32 *)(D_86B17A78 + 0x358) = 1;
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86B04500 begin */
extern f32 D_86B0DD8C;
extern f32 D_86B0DD90;
extern f32 D_86B0DD94;
extern f32 D_86B0DD98;
extern s32 D_86B0E188;
extern s32 D_86B0E190;
extern s32 D_86B0E194;
extern s32 D_86B0E198;
extern u8 D_86B0E9A0;
extern void ModelAnim_SetFrame(u8 *arg0, s16 value);
extern void func_8003F210(void *, s32);
extern void func_8003F3BC(void *, s32);
extern void func_86B03628(void);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 *func_87F025B8(u8 *, void (*)(void));




void func_86B04500(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad[2]; // FAKE: 8 unused bytes of frame; without them IDO sizes the frame 0x28, moving the argument home slots from 0x30..0x3C to 0x28..0x34 (score 146)
    u8 *result;
    u8 *node;
    result = func_87F025B8(&D_86B0E9A0, func_86B03628);
    if (result == NULL) return;
    // Packed index stored as four decimal places: arg1 thousands, arg2 hundreds, arg0 tens, arg3 ones.
    *(s32 *)(result + 0x20) = (arg1 * 1000) + (arg2 * 100) + (arg0 * 10) + arg3;
    node = result + 0x24;
    switch(arg0) {
    case 0: *(f32 *)(result + 0x48) = 0; *(f32 *)(result + 0x4C) = 0; *(f32 *)(result + 0x50) = 0; break;
    case 1: *(f32 *)(result + 0x48) = (-4.46f); *(f32 *)(result + 0x50) = 0; *(f32 *)(result + 0x4C) = -10.0f; break;
    case 2: *(f32 *)(result + 0x48) = 4.46f; *(f32 *)(result + 0x50) = 0; *(f32 *)(result + 0x4C) = -10.0f; break;
    default: break;
    }
    *(s32 *)(result + 0x1C) = 0;
    *(f32 *)(result + 0x5C) = 0.35555556f;
    *(f32 *)(result + 0x58) = 0.35555556f;
    *(f32 *)(result + 0x54) = 0.35555556f;
    func_8003F1DC(node);
    switch(arg1) {
    case 0:
        switch(arg2) {
        case 0: func_8003F114(node, 0, -1, D_86B0E194); break;
        case 1: func_8003F114(node, 0, -1, D_86B0E198); break;
        }
        switch(arg3) {
        case 0: func_8003F210(node, 0); ModelAnim_SetFrame(node, 0); break;
        case 1: func_8003F210(node, 1); ModelAnim_SetFrame(node, 1); break;
        }
        break;
    case 1:
        *(f32 *)(result + 0x5C) = 0.35555556f;
        *(f32 *)(result + 0x58) = 0.35555556f;
        *(f32 *)(result + 0x54) = 0.35555556f;
        switch(arg2) {
        case 0: func_8003F114(node, 0, -1, D_86B0E190); func_8003F3BC(node, 0); break;
        case 1: func_8003F114(node, 0, -1, D_86B0E190); func_8003F3BC(node, 0); break;
        }
        switch(arg3) {
        case 0: func_8003F210(node, 0); ModelAnim_SetFrame(node, 0); break;
        case 1: func_8003F210(node, 1); ModelAnim_SetFrame(node, 1); break;
        }
        break;
    case 2:
        *(f32 *)(result + 0x5C) = 0.5f;
        *(f32 *)(result + 0x58) = 0.5f;
        *(f32 *)(result + 0x54) = 0.5f;
        *(f32 *)(result + 0x50) = 0.0f;
        func_8003F114(node, 0, -1, D_86B0E188);
        switch(arg3) {
        case 0: func_8003F210(node, 1); ModelAnim_SetFrame(node, 0); break;
        case 1: func_8003F210(node, 2); ModelAnim_SetFrame(node, 1); break;
        }
        break;
    }
}
/* mkdraft:func_86B04500 end */
#endif

#ifdef VERSION_US
extern void func_87F026E8(void *, void *);
extern void *D_87F119D8;
extern void * D_87F119DC;
void func_86B04870(void) {
    s32 result = 0;
    s32 divisor = 30;
    u8 *obj;
    obj = D_87F119DC;
    *(f32 *)(obj + 0x48) += *(f32 *)(obj + 0x10);
    obj = D_87F119DC;
    *(f32 *)(obj + 0x4C) += *(f32 *)(obj + 0x14);
    obj = D_87F119DC;
    *(f32 *)(obj + 0x50) += *(f32 *)(obj + 0x18);
    obj = D_87F119DC;
    *(f32 *)(obj + 0x14) -= (f32)(*(u32 *)(obj + 0x20) / divisor);
    obj = D_87F119DC;
    *(u8 *)(obj + 0x41) -= *(u32 *)(obj + 0x20) % divisor;
    obj = D_87F119DC;
    if (*(s32 *)(obj + 0x1C) >= 25) result = 1;
    if (result) func_87F026E8(D_87F119D8, obj);
}
#endif

#ifdef VERSION_US
extern u8 *func_87F025B8(u8 *, void (*)(void));
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern void func_8003F210(void *, s32);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern u8 D_86B0EE60;
extern u8 D_86B17A78[];
extern s32 D_86B0E188;
extern s32 D_86B0E18C;
extern s32 D_86B0E194;
extern s32 D_86B0E198;
extern void func_86B04870(void);



void func_86B04970(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4,
                   f32 arg5, f32 arg6) {
    f64 pad; // FAKE: never referenced; IDO still reserves 8 bytes, giving the
              // 0x30 frame the target uses (score without it: 154)
    u8 *ptr;
    u8 *anim;

    ptr = func_87F025B8(&D_86B0EE60, func_86B04870);
    if (ptr != NULL) {
        *(f32 *)(ptr + 0x48) = arg4;
        *(f32 *)(ptr + 0x4C) = arg5;
        *(f32 *)(ptr + 0x50) = arg6;
        *(f32 *)(ptr + 0x10) = 0.0f;
        *(f32 *)(ptr + 0x18) = 0.0f;
        *(u8 *)(ptr + 0x41) = 0xFF;
        *(f32 *)(ptr + 0x14) = 12.0f;
        if (arg2 != 1 && arg2 != 2 && arg2 != 4 && arg2 != 8) {
            // one expression so IDO keeps the 0x1C store before the 0x20 store
            *(s32 *)(ptr + 0x20) = 81, *(s32 *)(ptr + 0x1C) = 13;
            *(f32 *)(ptr + 0x14) = 24.0f;
        } else {
            switch (guRandom() % 3) {
                case 0:
                    *(f32 *)(ptr + 0x14) = 12.0f;
                    *(s32 *)(ptr + 0x20) = 35;
                    break;
                case 1:
                    *(f32 *)(ptr + 0x14) = 13.0f;
                    *(s32 *)(ptr + 0x20) = 35;
                    break;
                case 2:
                    *(f32 *)(ptr + 0x14) = 12.5f;
                    *(s32 *)(ptr + 0x20) = 35;
                    break;
            }
            *(s32 *)(ptr + 0x1C) = 0;
        }
        switch (arg2) {
            case 1:
                switch (arg0) {
                    case 0:
                        if (arg3 != 1) {
                            *(f32 *)(ptr + 0x10) = *(f32 *)(D_86B17A78 + 0x14) / 25.0f;
                            *(f32 *)(ptr + 0x18) = *(f32 *)(D_86B17A78 + 0x18) / 25.0f;
                        }
                        break;
                    case 1:
                        *(f32 *)(ptr + 0x10) = (*(f32 *)(D_86B17A78 + 0x14) - arg4) / 25.0f;
                        *(f32 *)(ptr + 0x18) = (*(f32 *)(D_86B17A78 + 0x18) - arg6) / 25.0f;
                        break;
                }
                break;
            case 2:
                switch (arg0) {
                    case 0:
                        if (arg3 != 1) {
                            *(f32 *)(ptr + 0x10) = *(f32 *)(D_86B17A78 + 0x1C) / 25.0f;
                            *(f32 *)(ptr + 0x18) = *(f32 *)(D_86B17A78 + 0x20) / 25.0f;
                        }
                        break;
                    case 1:
                        *(f32 *)(ptr + 0x10) = (*(f32 *)(D_86B17A78 + 0x1C) - arg4) / 25.0f;
                        *(f32 *)(ptr + 0x18) = (*(f32 *)(D_86B17A78 + 0x20) - arg6) / 25.0f;
                        break;
                }
                break;
            case 4:
                switch (arg0) {
                    case 0:
                        if (arg3 != 1) {
                            *(f32 *)(ptr + 0x10) = *(f32 *)(D_86B17A78 + 0x24) / 25.0f;
                            *(f32 *)(ptr + 0x18) = *(f32 *)(D_86B17A78 + 0x28) / 25.0f;
                        }
                        break;
                    case 1:
                        *(f32 *)(ptr + 0x10) = (*(f32 *)(D_86B17A78 + 0x24) - arg4) / 25.0f;
                        *(f32 *)(ptr + 0x18) = (*(f32 *)(D_86B17A78 + 0x28) - arg6) / 25.0f;
                        break;
                }
                break;
            case 8:
                switch (arg0) {
                    case 0:
                        if (arg3 != 1) {
                            *(f32 *)(ptr + 0x10) = *(f32 *)(D_86B17A78 + 0x2C) / 25.0f;
                            *(f32 *)(ptr + 0x18) = *(f32 *)(D_86B17A78 + 0x30) / 25.0f;
                        }
                        break;
                    case 1:
                        *(f32 *)(ptr + 0x10) = (*(f32 *)(D_86B17A78 + 0x2C) - arg4) / 25.0f;
                        *(f32 *)(ptr + 0x18) = (*(f32 *)(D_86B17A78 + 0x30) - arg6) / 25.0f;
                        break;
                }
                break;
            case 3:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x14) + *(f32 *)(D_86B17A78 + 0x1C)) * -3.0f) / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x18) + *(f32 *)(D_86B17A78 + 0x20)) * -3.0f) / 25.0f;
                break;
            case 5:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x14) + *(f32 *)(D_86B17A78 + 0x24)) * -3.0f) / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x18) + *(f32 *)(D_86B17A78 + 0x28)) * -3.0f) / 25.0f;
                break;
            case 9:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x14) + *(f32 *)(D_86B17A78 + 0x2C)) * -3.0f) / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x18) + *(f32 *)(D_86B17A78 + 0x30)) * -3.0f) / 25.0f;
                break;
            case 6:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x1C) + *(f32 *)(D_86B17A78 + 0x24)) * -3.0f) / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x20) + *(f32 *)(D_86B17A78 + 0x28)) * -3.0f) / 25.0f;
                break;
            case 10:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x1C) + *(f32 *)(D_86B17A78 + 0x2C)) * -3.0f) / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x20) + *(f32 *)(D_86B17A78 + 0x30)) * -3.0f) / 25.0f;
                break;
            case 12:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x24) + *(f32 *)(D_86B17A78 + 0x2C)) * -3.0f) / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x28) + *(f32 *)(D_86B17A78 + 0x30)) * -3.0f) / 25.0f;
                break;
            case 7:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x14) + *(f32 *)(D_86B17A78 + 0x1C)) + *(f32 *)(D_86B17A78 + 0x24)) * -3.0f / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x18) + *(f32 *)(D_86B17A78 + 0x20)) + *(f32 *)(D_86B17A78 + 0x28)) * -3.0f / 25.0f;
                break;
            case 11:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x14) + *(f32 *)(D_86B17A78 + 0x1C)) + *(f32 *)(D_86B17A78 + 0x2C)) * -3.0f / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x18) + *(f32 *)(D_86B17A78 + 0x20)) + *(f32 *)(D_86B17A78 + 0x30)) * -3.0f / 25.0f;
                break;
            case 13:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x14) + *(f32 *)(D_86B17A78 + 0x24)) + *(f32 *)(D_86B17A78 + 0x2C)) * -3.0f / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x18) + *(f32 *)(D_86B17A78 + 0x28)) + *(f32 *)(D_86B17A78 + 0x30)) * -3.0f / 25.0f;
                break;
            case 14:
                *(f32 *)(ptr + 0x10) = ((*(f32 *)(D_86B17A78 + 0x1C) + *(f32 *)(D_86B17A78 + 0x24)) + *(f32 *)(D_86B17A78 + 0x2C)) * -3.0f / 25.0f;
                *(f32 *)(ptr + 0x18) = ((*(f32 *)(D_86B17A78 + 0x20) + *(f32 *)(D_86B17A78 + 0x28)) + *(f32 *)(D_86B17A78 + 0x30)) * -3.0f / 25.0f;
                break;
            case 15:
                break;
        }
        *(f32 *)(ptr + 0x5C) = 0.35555556f;
        *(f32 *)(ptr + 0x58) = 0.35555556f;
        *(f32 *)(ptr + 0x54) = 0.35555556f;
        anim = ptr + 0x24;
        func_8003F1DC(anim);
        switch (arg0) {
            case 0:
                switch (arg1) {
                    case 0:
                        func_8003F114(anim, 0, -1, D_86B0E194);
                        break;
                    case 1:
                        func_8003F114(anim, 0, -1, D_86B0E198);
                        break;
                }
                func_8003F210(anim, 1);
                ModelAnim_SetSpeed(anim, 0);
                break;
            case 1:
                *(f32 *)(ptr + 0x5C) = 0.24888889f;
                *(f32 *)(ptr + 0x58) = 0.24888889f;
                *(f32 *)(ptr + 0x54) = 0.24888889f;
                switch (arg1) {
                    case 0:
                        func_8003F114(anim, 0, -1, D_86B0E18C);
                        break;
                    case 1:
                        func_8003F114(anim, 0, -1, D_86B0E18C);
                        break;
                }
                func_8003F210(anim, 1);
                ModelAnim_SetSpeed(anim, 0);
                break;
            case 2:
                *(f32 *)(ptr + 0x5C) = 0.5f;
                *(f32 *)(ptr + 0x58) = 0.5f;
                *(f32 *)(ptr + 0x54) = 0.5f;
                func_8003F114(anim, 0, -1, D_86B0E188);
                func_8003F210(anim, 2);
                ModelAnim_SetSpeed(anim, 0);
                break;
        }
    }
}
#endif

#ifdef VERSION_US
extern void *D_87F119DC;
extern void *D_87F119D8;
extern void func_87F026E8(void *, void *);
extern void func_86B052BC(s32);
void func_86B05194(void) {
    s32 result;
    s32 value;
    s32 state_value;

    result = 0;
    value = *(s32 *)((u8 *)D_87F119DC + 0x20);
    switch (value) {
    case 0:
        state_value = *(s32 *)((u8 *)D_87F119DC + 0x1C);
        if (state_value == 0) {
            func_86B052BC(1);
            state_value = *(s32 *)((u8 *)D_87F119DC + 0x1C);
        }
        if (state_value == 2) {
            func_86B052BC(1);
            state_value = *(s32 *)((u8 *)D_87F119DC + 0x1C);
        }
        if (state_value == 4) {
            func_86B052BC(1);
            state_value = *(s32 *)((u8 *)D_87F119DC + 0x1C);
        }
        if (state_value == 6) {
            func_86B052BC(1);
            state_value = *(s32 *)((u8 *)D_87F119DC + 0x1C);
        }
        if (state_value == 8) {
            func_86B052BC(1);
            state_value = *(s32 *)((u8 *)D_87F119DC + 0x1C);
        }
        if (state_value >= 9) {
            result = 1;
        }
        break;
    case 1:
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= 8) {
            result = 1;
        }
        break;
    }
    if (result != 0) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
extern void func_86B05194(void);
extern u8 *func_87F025B8(u8 *, void (*)(void));
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void ModelAnim_SetAnimation(u8 *, s32);
extern u8 D_86B12AD0;
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern f32 D_86B0D17C;
extern f32 D_86B0D178;
extern s32 D_86B0E19C;
extern s32 D_86B0E1A0;
void func_86B052BC(s32 arg0) {
    u8 *object;
    u8 *base;
    f32 scale;
    f32 factor;
    s32 index;

    object = func_87F025B8(&D_86B12AD0, func_86B05194);
    if (object != NULL) {
        *(s32 *)(object + 0x1C) = 0;
        *(f32 *)(object + 0x48) = 0.0f;
        *(f32 *)(object + 0x4C) = 0.0f;
        *(f32 *)(object + 0x50) = 0.0f;
        base = object + 0x24;
        *(s32 *)(object + 0x20) = arg0;
        scale = (f32)((f64)D_86B0D178 * 0.1111111111111111);
        *(f32 *)(object + 0x5C) = scale;
        *(f32 *)(object + 0x58) = scale;
        *(f32 *)(object + 0x54) = scale;
        func_8003F1DC(base);
        switch (arg0) {
        case 0:
            func_8003F114(base, 0, -1, D_86B0E19C);
            ModelAnim_SetAnimation(base, 0);
            break;
        case 1:
            index = ((guRandom() % 65535) & 0xFFFF) >> 4;
            factor = 45.0f * D_86B0D17C;
            *(f32 *)(object + 0x48) = D_80088E50[index] * factor;
            *(f32 *)(object + 0x4C) = D_80087E50[index] * factor;
            *(f32 *)(object + 0x50) = 0.0f;
            func_8003F114(base, 0, -1, D_86B0E1A0);
            ModelAnim_SetAnimation(base, 0);
            break;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_87F026E8(void *, void *);
extern void *D_87F119D8;
extern void *D_87F119DC;
void func_86B05428(void) {
    s32 var_v0;

    var_v0 = 0;
    (*(s8 *)((u8 *)(D_87F119DC) + (0x41))) = (s8) (*(s32 *)((u8 *)(D_87F119DC) + (0x20)));
    if ((*(s32 *)((u8 *)(D_87F119DC) + (0x1C))) >= 0x18) {
        var_v0 = 1;
    }
    if (var_v0 != 0) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
extern u8 *func_87F025B8(u8 *, void (*)(void));
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void ModelAnim_SetAnimation(u8 *, s32);
extern f32 D_86B0D178;
extern s32 D_86B0E1A4;
extern u8 D_86B13A68;
extern void func_86B05428(void);
void func_86B05484(f32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    u8 *object;
    u8 *base;
    f32 scale;

    object = func_87F025B8(&D_86B13A68, func_86B05428);
    if (object != NULL) {
        *(s32 *)(object + 0x1C) = 0;
        scale = (f32)((f64)D_86B0D178 * 0.1111111111111111);
        *(f32 *)(object + 0x5C) = scale;
        *(f32 *)(object + 0x58) = scale;
        *(f32 *)(object + 0x54) = scale;
        base = object + 0x24;
        func_8003F1DC(base);
        *(f32 *)(object + 0x48) = arg0;
        *(f32 *)(object + 0x4C) = arg1;
        *(f32 *)(object + 0x50) = arg2;
        *(s32 *)(object + 0x20) = arg3;
        func_8003F114(base, 0, -1, D_86B0E1A4);
        ModelAnim_SetAnimation(base, 0);
    }
}
#endif

#ifdef VERSION_US
extern f32 D_86B17AC0[];
extern u32 D_86B0D838[];

// ORs into *arg0 the D_86B0D838 flag word of each of the four D_86B17AC0 thresholds that are at
// most 45.0f, and returns how many passed.
s32 func_86B05548(s32 *arg0) {
    s32 count = 0;
    s32 i;
    f32 value = 45.0f;

    *arg0 = 0;
    for (i = 0; i < 4; i++) {
        if (D_86B17AC0[i] <= value) {
            *arg0 |= D_86B0D838[i];
            count++;
        }
    }
    return count;
}
#endif

#ifdef VERSION_US
extern u8 D_86B17A88[];
extern f32 __cosf(f32);
extern f32 __sinf(f32);
extern u8 D_86B17A78[];
s32 func_86B05610(f32 arg0) {
    s32 i;
    f32 x;
    f32 y;
    f32 dx;
    f32 dy;
    f32 cx;
    f32 sy;
    x = __cosf(arg0) * 180.0f;
    y = __sinf(arg0) * 180.0f;
    for (i = 0; i < 4; i++) {
        if (((s32 *)(D_86B17A78 + 0x34))[i] == 0x10 || ((s32 *)(D_86B17A78 + 0x34))[i] == 0x11 || ((s32 *)(D_86B17A78 + 0x34))[i] == 0x12 || ((s32 *)(D_86B17A78 + 0x34))[i] == 0) {
            cx = __cosf(((f32 *)(D_86B17A78 + 0x58))[i]) * 180.0f;
            sy = __sinf(((f32 *)(D_86B17A78 + 0x58))[i]) * 180.0f;
            dx = x - cx;
            dy = y - sy;
            if ((dx * dx) + (dy * dy) < 900.0) {
                return 1;
            }
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_86B05610(f32 arg0);
f32 func_86B05738(f32 arg0) { f32 angle = arg0;
    f32 limit = 6.2831855f;
    f64 step = 0.016;
    do {
        if (!func_86B05610(angle)) break;
        angle = (f32)((f64)angle + step);
        if (limit < angle) angle -= limit;
    } while (1);
    return angle;
}
#endif

#ifdef VERSION_US
extern int guRandom(void);
extern u8 D_800CE060[];
extern s32 D_86B0E0A0;
extern u8 *D_86B181C0;
extern f32 D_86B0D1FC[];
extern f32 D_86B0D1F4;
extern f32 D_86B0D1F8;
extern u8 D_86B16DA0[];
extern u8 D_86B17E2C;
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern f32 func_86B080D4(f32 arg0, f32 arg1);
extern f32 func_86B08120(f32 arg0, f32 arg1);
extern s16 func_86B07D58(f32 arg0, f32 arg1);
extern void func_86B07D94(s32 arg0, s32 arg1);
extern void func_86B0BB24(s32 arg0);
extern void func_8002781C(u16 resource_id, u8 mode, ...);
extern s32 func_8003EC54(s32 *);
extern u8 *func_87F03F38(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6);
extern f32 func_87C039D4(u8 *arg0, void *arg1, f32 *arg2);

// Per-player views of the state block at D_86B17A78: p0 = base + i * 4 (s32/f32 arrays),
// p2 = base + i * 8 (f32 pairs), p3 = base + i * 2 (s16 / u8 pairs).
#define W(o) (((s32 *)(D_86B17A78 + (o)))[i])
#define F(o) (((f32 *)(D_86B17A78 + (o)))[i])
#define G(o) (*(f32 *)(D_86B17A78 + (o)))
#define GW(o) (*(s32 *)(D_86B17A78 + (o)))
#define P(o) (((f32 (*)[2])(D_86B17A78 + (o)))[i][0])
#define H(o) (((s16 *)(D_86B17A78 + (o)))[i])
#define BY(o) (((u8 (*)[2])(D_86B17A78 + (o)))[i][0])
#define RND(a) ((a) >= 0 ? (s32)((a) + 0.5f) : (s32)((a) - 0.5f))
#define SMOOTH(a) ((f32)(((f64)D_80087E50[(u16)RND(a) >> 4] + 1.0 - (f64)D_80088E50[(u16)RND(a) >> 4]) * 0.5))
#define TWO_PI 6.2831855f
#define UPD_BYTES(arg) \
    BY(0x49C) = (s32)(P(0x14) * 64.0f / 200.0f); \
    BY(0x49D) = (s32)(P(0x18) * 64.0f / 200.0f); \
    func_86B07D94(i, (arg))
#define SET_VEL_NEG(var, a, b) var = (func_86B07D58(-(a), -(b)) - 0x3FFF) % mod

void func_86B057B0(void) {
    s32 i;
    s32 mod;
    f32 tmp;
    s32 c; // FAKE: unused, reserves a stack slot
    s32 d;
    s32 sp178;
    s32 sp174;
    s32 pressed;
    s32 sp16C;
    f32 fs1;
    f32 fs0;

    guRandom();
    sp178 = 0;
    sp174 = 0;
    if (D_86B0E0A0 != 0) {
        sp16C = guRandom() % 3;
    } else {
        sp16C = guRandom() % 4;
    }
    for (i = 0, mod = 0xFFFF; i < 4; i++) {
        P(0x98) = P(0x14);
        P(0x9C) = P(0x18);
        func_86B0BB24(i);
        BY(0x49C) = (s32)(P(0x14) * 64.0f / 200.0f);
        BY(0x49D) = (s32)(P(0x18) * 64.0f / 200.0f);
        if (GW(0x354) == 0 && GW(0x284) < GW(0x288) + 100 && *(s32 *)D_86B181C0 == 6 && W(0x34) == 2 && F(0x48) == 130.0f) {
            if ((f64)func_86B080D4(F(0xFC), G(0xF8)) <= 0.032) {
                pressed = *(u16 *)(D_800CE060 + i * 0x28 + 8);
                if (pressed & 0x8000) {
                    W(0x374) = GW(0x284);
                    W(0x34) = 6;
                    sp178 = 1;
                    d = W(0x374) - GW(0x288);
                    if (d - 5 >= 0) {
                        if (D_86B0E0A0 != 0) {
                            W(0x3A4) = d * 3 + sp16C - 15;
                        } else {
                            W(0x3A4) = d * 4 + sp16C - 20;
                        }
                    }
                    func_8002781C(0xAF02, i, &D_86B17A78[i * 2 + 0x49C]);
                } else if (pressed & 0x4000) {
                    W(0x384) = GW(0x284);
                    W(0x34) = 12;
                    sp178 = 1;
                    func_8002781C(0xAF02, i, &D_86B17A78[i * 2 + 0x49C]);
                }
            }
        }
        switch (W(0x34)) {
        case 0:
            {
                if (*(s32 *)D_86B17A78 < 4) {
                    fs0 = 0.016f;
                } else {
                    fs0 = 0.019111111f;
                }
                if (func_86B08120(G(0xF8) + D_86B0D1FC[i], F(0x58)) <= fs0) {
                    W(0x34) = 2;
                    if ((F(0x58) = F(0xFC) + D_86B0D1FC[i]) < 0.0f) {
                        F(0x58) = F(0x58) + TWO_PI;
                    }
                    fs1 = F(0x48) * __cosf(F(0x58));
                    P(0x14) = fs1;
                    fs0 = F(0x48) * __sinf(F(0x58));
                    P(0x18) = fs0;
                    H(0xE8) = func_86B07D58(-fs1, -fs0);
                    F(0x10C) = F(0x48);
                    F(0x11C) = 130.0f;
                    W(0x12C) = (s32)(50.0f / D_86B0D1F4);
                    W(0x13C) = 0;
                    if ((F(0x14C) = F(0xFC) + D_86B0D1FC[i]) > 6.28318548202514648) {
                        F(0x14C) = F(0x14C) - TWO_PI;
                    }
                    F(0x15C) = (f32)(((f64)G(0xF8) - 0.016 * (f64)W(0x12C)) + (f64)D_86B0D1FC[i]);
                    if (F(0x15C) > TWO_PI) {
                        F(0x15C) = F(0x15C) - TWO_PI;
                    }
                    if (F(0x15C) < 0) {
                        F(0x15C) = F(0x15C) + TWO_PI;
                    }
                    F(0x16C) = F(0x48);
                }
                UPD_BYTES(0);
            }
            break;
        case 1:
        case 2:
        case 3:
            W(0x364) = 0;
            if (F(0x48) > 130.0f) {
                F(0x48) = F(0x48) - D_86B0D1F4;
                if (F(0x48) < 130.0f) {
                    F(0x48) = 130.0f;
                }
            } else if (F(0x48) < 130.0f) {
                F(0x48) = F(0x48) + D_86B0D1F4;
                if (F(0x48) > 130.0f) {
                    F(0x48) = 130.0f;
                }
            }
            if ((f64)func_86B080D4(F(0xFC), G(0xF8)) > 0.032) {
                F(0xFC) = (f32)((f64)F(0xFC) - 0.032);
                if (F(0xFC) < 0.0f) {
                    F(0xFC) = (f32)((f64)F(0xFC) + 6.28318548202514648);
                }
                F(0x58) = F(0xFC) + D_86B0D1FC[i];
            } else {
                F(0xFC) = G(0xF8);
                F(0x58) = F(0xFC) + D_86B0D1FC[i];
            }
            if (F(0x58) < 0.0f) {
                F(0x58) = F(0x58) + TWO_PI;
            }
            fs1 = F(0x48) * __cosf(F(0x58));
            P(0x14) = fs1;
            fs0 = F(0x48) * __sinf(F(0x58));
            P(0x18) = fs0;
            SET_VEL_NEG(H(0xF0), fs1, fs0);
            if (W(0xB8) == 0xE) {
                H(0xE8) = (func_86B07D58(-fs1, -fs0) - 0x3FFF) % mod;
            }
            if (F(0x48) != 130.0f) {
                if (130.0f <= F(0x48) + D_86B0D1F8 * D_86B0D1F4) {
                    H(0xF0) = func_86B07D58(fs1 - P(0x98), fs0 - P(0x9C));
                } else {
                    fs1 = F(0x11C) * __cosf(F(0x15C));
                    tmp = F(0x11C) * __sinf(F(0x15C));
                    H(0xF0) = (func_86B07D58(-fs1, -tmp) - 0x3FFF) % mod;
                }
            }
            UPD_BYTES(0);
            break;
        case 4:
            {
                s32 n = W(0x12C);
                f32 p0e1;
                f32 p0e2;
                f32 r0b;
                f32 r0c;
                f32 p1e1;
                f32 p1e2;
                f32 y; // FAKE: unused, reserves a stack slot
                f32 r1b;
                f32 r1a;
                f32 cx;
                f32 sy;
                f32 spd;
                s32 k = W(0x13C);
                W(0x13C)++;
                p0e1 = (f32)k / (f32)(n - 1);
                p0e2 = (f32)k / (f32)(n - 1);
                r0b = (f32)(1.0 - (f64)p0e2);
                r0c = (f32)(1.0 - (f64)p0e1);
                p1e1 = (f32)(k + 1) / (f32)(n - 1);
                p1e2 = (f32)(k + 1) / (f32)(n - 1);
                r1a = (f32)(1.0 - (f64)p1e1);
                r1b = (f32)(1.0 - (f64)p1e2);
                spd = F(0x11C) * p1e2 + F(0x10C) * r1b;
                if (F(0x15C) < F(0x14C)) {
                    fs0 = F(0x15C) * p1e1 + F(0x14C) * r1a;
                } else {
                    fs0 = F(0x15C) * p1e1 + (F(0x14C) + TWO_PI) * r1a;
                    if (fs0 > TWO_PI) {
                        fs0 = fs0 - TWO_PI;
                    }
                }
                if (fs0 < 0.0f) {
                    fs0 = fs0 + TWO_PI;
                }
                if ((f64)fs0 > 6.28318548202514648) {
                    fs0 = fs0 - TWO_PI;
                }
                cx = __cosf(fs0) * spd;
                sy = __sinf(fs0) * spd;
                F(0x16C) = F(0x48);
                F(0x48) = F(0x11C) * p0e2 + F(0x10C) * r0b;
                if (k == n - 1) {
                    F(0x48) = 130.0f;
                    F(0xFC) = F(0x15C) - D_86B0D1FC[i];
                    W(0x34) = 2;
                }
                if (F(0x15C) < F(0x14C)) {
                    F(0x58) = F(0x15C) * p0e1 + F(0x14C) * r0c;
                } else {
                    F(0x58) = F(0x15C) * p0e1 + (F(0x14C) + TWO_PI) * r0c;
                    if (F(0x58) > TWO_PI) {
                        F(0x58) = F(0x58) - TWO_PI;
                    }
                }
                if (F(0x58) < 0.0f) {
                    F(0x58) = F(0x58) + TWO_PI;
                }
                if ((f64)F(0x58) > 6.28318548202514648) {
                    F(0x58) = F(0x58) - TWO_PI;
                }
                fs1 = F(0x48) * __cosf(F(0x58));
                P(0x14) = fs1;
                fs0 = F(0x48) * __sinf(F(0x58));
                P(0x18) = fs0;
                if (F(0x48) != 130.0f) {
                    H(0xF0) = func_86B07D58(cx - fs1, sy - fs0);
                } else {
                    SET_VEL_NEG(H(0xF0), fs1, fs0);
                }
                UPD_BYTES(0);
            }
            break;
        case 5:
        case 6:
        case 10:
        case 11:
        case 12:
            switch (W(0x34)) {
            case 5:
            case 6:
                if (F(0x48) > 45.0f) {
                    sp174 = 1;
                }
                F(0x48) = F(0x48) - 28.0f;
                if (F(0x48) < 75.0f) {
                    F(0x48) = 75.0f;
                    if (GW(0x33C) != 0) {
                        W(0x34) = 10;
                    } else {
                        W(0x34) = 14;
                        F(0xD8) = (130.0f - F(0x48)) / 14.0f;
                        func_8002781C(0xAF04, i, &D_86B17A78[i * 2 + 0x49C]);
                    }
                }
                break;
            case 10:
                if (F(0x48) > 45.0f) {
                    sp174 = 1;
                }
                F(0x48) = F(0x48) - 14.0f;
                if (F(0x48) < 45.0f) {
                    F(0x48) = 45.0f;
                }
                break;
            case 11:
                if (F(0x48) > 22.0f) {
                    sp174 = 1;
                }
                F(0x48) = F(0x48) - 14.0f;
                if (F(0x48) < 0.0f) {
                    F(0x48) = 0.01f;
                }
                break;
            case 12:
                if (F(0x48) > 45.0f) {
                    sp174 = 1;
                }
                F(0x48) = F(0x48) - 28.0f;
                if (F(0x48) < 100.0f) {
                    W(0x34) = 7;
                    F(0x48) = 100.0f;
                }
                break;
            }
            fs1 = F(0x48) * __cosf(F(0x58));
            P(0x14) = fs1;
            fs0 = F(0x48) * __sinf(F(0x58));
            P(0x18) = fs0;
            H(0xF0) = func_86B07D58(-fs1, -fs0);
            UPD_BYTES(2);
            if (sp174 != 0 && sp178 != 0) {
                if (W(0x364) == 0) {
                    u8 *fx = func_87F03F38(&D_86B178E8, 0, fs1, 10.0f, fs0 + 20.0f, 2.25f, 15);
                    if (fx != NULL) {
                        u8 *q = *(u8 **)(fx + 0x20);
                        q[0x13] = 0x7F;
                        q[0x10] = 0xFF;
                        q[0x11] = 0xFF;
                        q[0x12] = 0xFF;
                        {
                            u8 *q2 = *(u8 **)(fx + 0x20);
                            *(s16 *)(q2 + 0x1E) = 0x20;
                        }
                    }
                    W(0x394) = 0x50;
                    *(f32 *)(D_86B17A78 + i * 12 + 0x438) = P(0x14);
                    *(f32 *)(D_86B17A78 + i * 12 + 0x43C) = 55.0f;
                    *(f32 *)(D_86B17A78 + i * 12 + 0x440) = P(0x18);
                    func_87C039D4(&D_86B17E2C, D_86B17A78 + i * 12 + 0x438, (f32 *)(D_86B17A78 + i * 12 + 0x468));
                }
            }
            W(0x364) = (W(0x364) + 1) % 3;
            break;
        case 7:
            {
                W(0x34) = 8;
                if ((F(0x58) = F(0xFC) + D_86B0D1FC[i]) < 0.0f) {
                    F(0x58) = F(0x58) + TWO_PI;
                }
                fs1 = F(0x48) * __cosf(F(0x58));
                P(0x14) = fs1;
                tmp = F(0x48) * __sinf(F(0x58));
                P(0x18) = tmp;
                BY(0x49C) = (s32)(P(0x14) * 64.0f / 200.0f);
                BY(0x49D) = (s32)(P(0x18) * 64.0f / 200.0f);
                fs0 = __cosf((f32)((f64)(G(0xF8) + D_86B0D1FC[i]) - 0.064));
                H(0xF0) = func_86B07D58(fs0 * 130.0f - fs1, __sinf((f32)((f64)(G(0xF8) + D_86B0D1FC[i]) - 0.064)) * 130.0f - tmp);
                func_86B07D94(i, 1);
                if (H(0xF0) == H(0xE8)) {
                    W(0x34) = 8;
                }
                F(0x11C) = 130.0f;
                W(0x13C) = 0;
                F(0x10C) = F(0x48);
                W(0x12C) = (s32)((130.0f - F(0x48)) / 3.75f);
                F(0x14C) = F(0xFC) + D_86B0D1FC[i];
                if ((f64)F(0x14C) > 6.28318548202514648) {
                    F(0x14C) = F(0x14C) - TWO_PI;
                }
                F(0x15C) = (f32)(((f64)G(0xF8) - 0.016 * (f64)W(0x12C)) + (f64)D_86B0D1FC[i]);
                if (F(0x15C) > TWO_PI) {
                    F(0x15C) = F(0x15C) - TWO_PI;
                }
                if (F(0x15C) < 0.0f) {
                    F(0x15C) = F(0x15C) + TWO_PI;
                }
                F(0x16C) = F(0x48);
            }
            break;
        case 8:
            {
                s32 n = W(0x12C);
                f32 p0e1;
                f32 p0e2;
                f32 r0b;
                f32 r0c;
                f32 p1e1;
                f32 p1e2;
                f32 y; // FAKE: unused, reserves a stack slot
                f32 r1b;
                f32 r1a;
                f32 cx;
                f32 sy;
                f32 spd;
                s32 k = W(0x13C);
                W(0x13C)++;
                p0e1 = SMOOTH((f32)k * 90.0f / (f32)(n - 1) * 182.0416718f);
                p0e2 = SMOOTH((f32)k * 90.0f / (f32)(n - 1) * 182.0416718f);
                r0b = (f32)(1.0 - (f64)p0e2);
                r0c = (f32)(1.0 - (f64)p0e1);
                p1e1 = SMOOTH((f32)(k + 1) * 90.0f / (f32)(n - 1) * 182.0416718f);
                p1e2 = SMOOTH((f32)(k + 1) * 90.0f / (f32)(n - 1) * 182.0416718f);
                r1a = (f32)(1.0 - (f64)p1e1);
                r1b = (f32)(1.0 - (f64)p1e2);
                spd = F(0x11C) * p1e2 + F(0x10C) * r1b;
                if (F(0x15C) < F(0x14C)) {
                    fs0 = F(0x15C) * p1e1 + F(0x14C) * r1a;
                } else {
                    fs0 = F(0x15C) * p1e1 + (F(0x14C) + TWO_PI) * r1a;
                    if (fs0 > TWO_PI) {
                        fs0 = fs0 - TWO_PI;
                    }
                }
                if (fs0 < 0.0f) {
                    fs0 = fs0 + TWO_PI;
                }
                if ((f64)fs0 > 6.28318548202514648) {
                    fs0 = fs0 - TWO_PI;
                }
                cx = __cosf(fs0) * spd;
                sy = __sinf(fs0) * spd;
                F(0x16C) = F(0x48);
                F(0x48) = F(0x11C) * p0e2 + F(0x10C) * r0b;
                if (k == n - 1) {
                    F(0x48) = 130.0f;
                    F(0xFC) = F(0x15C) - D_86B0D1FC[i];
                    W(0x34) = 2;
                }
                if (F(0x15C) < F(0x14C)) {
                    F(0x58) = F(0x15C) * p0e1 + F(0x14C) * r0c;
                } else {
                    F(0x58) = F(0x15C) * p0e1 + (F(0x14C) + TWO_PI) * r0c;
                    if (F(0x58) > TWO_PI) {
                        F(0x58) = F(0x58) - TWO_PI;
                    }
                }
                if (F(0x58) < 0.0f) {
                    F(0x58) = F(0x58) + TWO_PI;
                }
                if ((f64)F(0x58) > 6.28318548202514648) {
                    F(0x58) = F(0x58) - TWO_PI;
                }
                fs1 = F(0x48) * __cosf(F(0x58));
                P(0x14) = fs1;
                fs0 = F(0x48) * __sinf(F(0x58));
                P(0x18) = fs0;
                if (F(0x48) != 130.0f) {
                    H(0xF0) = func_86B07D58(cx - fs1, sy - fs0);
                } else {
                    SET_VEL_NEG(H(0xF0), fs1, fs0);
                }
                UPD_BYTES(1);
            }
            break;
        case 9:
            F(0x48) = F(0x48) + 7.0f;
            if (F(0x48) > 130.0f) {
                F(0x48) = 130.0f;
                W(0x34) = 2;
            }
            if ((f64)func_86B080D4(F(0xFC), G(0xF8)) > 0.032) {
                F(0xFC) = (f32)((f64)F(0xFC) - 0.032);
                if (F(0xFC) < 0.0f) {
                    F(0xFC) = (f32)((f64)F(0xFC) + 6.28318548202514648);
                }
                F(0x58) = F(0xFC) + D_86B0D1FC[i];
            } else {
                F(0xFC) = G(0xF8);
                F(0x58) = F(0xFC) + D_86B0D1FC[i];
            }
            if (F(0x58) < 0.0f) {
                F(0x58) = F(0x58) + TWO_PI;
            }
            fs1 = F(0x48) * __cosf(F(0x58));
            P(0x14) = fs1;
            fs0 = F(0x48) * __sinf(F(0x58));
            P(0x18) = fs0;
            SET_VEL_NEG(H(0xF0), fs1, fs0);
            UPD_BYTES(2);
            break;
        case 14:
            if (W(0xB8) == 0xE) {
                u8 *anim = D_86B16DA0 + i * 360;
                if (func_8003EC54((s32 *)anim) >= 3) {
                    if (func_8003EC54((s32 *)anim) < 0x11) {
                        F(0x48) += F(0xD8);
                    }
                }
            }
            if (W(0xB8) == 0xE) {
                if (func_8003EC54((s32 *)(D_86B16DA0 + i * 360)) == 0x10) {
                    F(0x48) = 130.0f;
                }
            }
            fs1 = F(0x48) * __cosf(F(0x58));
            P(0x14) = fs1;
            fs0 = F(0x48) * __sinf(F(0x58));
            P(0x18) = fs0;
            H(0xF0) = func_86B07D58(-fs1, -fs0);
            UPD_BYTES(2);
            break;
        case 16:
            F(0x48) = F(0x48) + 8.4375f;
            if (F(0x48) > 180.0f) {
                F(0x48) = 180.0f;
            }
            fs1 = F(0x48) * __cosf(F(0x58));
            P(0x14) = fs1;
            fs0 = F(0x48) * __sinf(F(0x58));
            P(0x18) = fs0;
            H(0xF0) = func_86B07D58(-fs1, -fs0);
            UPD_BYTES(2);
            break;
        case 13:
        case 15:
        case 17:
        case 18:
        case 19:
        case 20:
            UPD_BYTES(0);
            break;
        case 21:
            W(0x34) = 0x16;
            F(0x58) = F(0xFC) + D_86B0D1FC[i];
            if (F(0x58) < 0.0f) {
                F(0x58) = F(0x58) + TWO_PI;
            }
            fs1 = F(0x48) * __cosf(F(0x58));
            P(0x14) = fs1;
            fs0 = F(0x48) * __sinf(F(0x58));
            P(0x18) = fs0;
            SET_VEL_NEG(H(0xE8), fs1, fs0);
            F(0x11C) = 87.5f;
            F(0x10C) = F(0x48);
            if (87.5f < F(0x48)) {
                W(0x12C) = (s32)((F(0x48) - 87.5f) / D_86B0D1F4);
            } else {
                W(0x12C) = (s32)((87.5f - F(0x48)) / D_86B0D1F4);
            }
            W(0x13C) = 0;
            F(0x14C) = F(0xFC) + D_86B0D1FC[i];
            if ((f64)F(0x14C) > 6.28318548202514648) {
                F(0x14C) = F(0x14C) - TWO_PI;
            }
            F(0x15C) = (f32)(((f64)G(0xF8) - 0.024 * (f64)W(0x12C)) + (f64)D_86B0D1FC[i]);
            if (F(0x15C) > TWO_PI) {
                F(0x15C) = F(0x15C) - TWO_PI;
            }
            if (F(0x15C) < 0.0f) {
                F(0x15C) = F(0x15C) + TWO_PI;
            }
            F(0x16C) = F(0x48);
            UPD_BYTES(0);
            break;
        case 22:
            {
                s32 n = W(0x12C);
                f32 p0e1;
                f32 p0e2;
                f32 r0b;
                f32 r0c;
                f32 p1e1;
                f32 p1e2;
                f32 y; // FAKE: unused, reserves a stack slot
                f32 r1b;
                f32 r1a;
                f32 cx;
                f32 sy;
                f32 spd;
                f32 ang;
                s32 k = W(0x13C);
                W(0x13C)++;
                p0e1 = SMOOTH((f32)k * 90.0f / (f32)(n - 1) * 182.0416718f);
                p0e2 = SMOOTH((f32)k * 90.0f / (f32)(n - 1) * 182.0416718f);
                r0b = (f32)(1.0 - (f64)p0e2);
                r0c = (f32)(1.0 - (f64)p0e1);
                p1e1 = SMOOTH((f32)(k + 1) * 90.0f / (f32)(n - 1) * 182.0416718f);
                p1e2 = SMOOTH((f32)(k + 1) * 90.0f / (f32)(n - 1) * 182.0416718f);
                r1a = (f32)(1.0 - (f64)p1e1);
                r1b = (f32)(1.0 - (f64)p1e2);
                spd = F(0x11C) * p1e2 + F(0x10C) * r1b;
                if (F(0x15C) < F(0x14C)) {
                    ang = F(0x15C) * p1e1 + F(0x14C) * r1a;
                } else {
                    ang = F(0x15C) * p1e1 + (F(0x14C) + TWO_PI) * r1a;
                    if (ang > TWO_PI) {
                        ang = ang - TWO_PI;
                    }
                }
                if (ang < 0.0f) {
                    ang = ang + TWO_PI;
                }
                if ((f64)ang > 6.28318548202514648) {
                    ang = ang - TWO_PI;
                }
                cx = __cosf(ang) * spd;
                sy = __sinf(ang) * spd;
                F(0x16C) = F(0x48);
                F(0x48) = F(0x11C) * p0e2 + F(0x10C) * r0b;
                if (k == n - 1) {
                    F(0x48) = 87.5f;
                    F(0xFC) = F(0x15C) - D_86B0D1FC[i];
                    W(0x34) = 0x17;
                }
                if (F(0x15C) < F(0x14C)) {
                    F(0x58) = F(0x15C) * p0e1 + F(0x14C) * r0c;
                } else {
                    F(0x58) = F(0x15C) * p0e1 + (F(0x14C) + TWO_PI) * r0c;
                    if (F(0x58) > TWO_PI) {
                        F(0x58) = F(0x58) - TWO_PI;
                    }
                }
                if (F(0x58) < 0.0f) {
                    F(0x58) = F(0x58) + TWO_PI;
                }
                if ((f64)F(0x58) > 6.28318548202514648) {
                    F(0x58) = F(0x58) - TWO_PI;
                }
                fs1 = F(0x48) * __cosf(F(0x58));
                P(0x14) = fs1;
                fs0 = F(0x48) * __sinf(F(0x58));
                P(0x18) = fs0;
                if (F(0x48) != 87.5f) {
                    H(0xF0) = func_86B07D58(cx - fs1, sy - fs0);
                } else {
                    SET_VEL_NEG(H(0xF0), fs1, fs0);
                }
                UPD_BYTES(0);
            }
            break;
        case 23:
            F(0xFC) = G(0xF8);
            F(0x58) = F(0xFC) + D_86B0D1FC[i];
            if (F(0x58) < 0.0f) {
                F(0x58) = F(0x58) + TWO_PI;
            }
            fs1 = F(0x48) * __cosf(F(0x58));
            P(0x14) = fs1;
            fs0 = F(0x48) * __sinf(F(0x58));
            P(0x18) = fs0;
            SET_VEL_NEG(H(0xF0), fs1, fs0);
            UPD_BYTES(0);
            break;
        default:
            break;
        }
        W(0xB8) = W(0x34);
    }
}


#endif

#ifdef VERSION_US
s16 MathUtil_Atan2s(f32 y, f32 x);
s16 func_86B07D58(f32 arg0, f32 arg1) {
    return (s16) ((s32) (MathUtil_Atan2s(arg0, -arg1) + 0x3FFF) % 65535);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86B07D94 begin */
extern u8 D_86B17A78[];
extern s32 func_86B08088(s16 arg0, s16 arg1);
extern s16 func_86B07FB0(s16 arg0, s16 arg1, s16 arg2, s32 arg3);

// Writes func_86B07FB0's result back over the s16 at 0xE8 of the arg0-th entry of
// D_86B17A78. The step argument comes from the s32 state at 0x34 (indexed by arg0 * 4,
// unlike the s16 fields, which are indexed by arg0 * 2); states 2 and 9 instead take a
// quarter of the largest threshold that still exceeds func_86B08088's distance between
// the 0xF0 and 0xE8 fields.


void func_86B07D94(s32 arg0, s32 arg1) {
    s16 field_e8;
    s16 field_f0;
    s16 step;

    field_e8 = ((s16 *)(D_86B17A78 + arg0 * 2))[0xE8 / 2];
    field_f0 = ((s16 *)(D_86B17A78 + arg0 * 2))[0xF0 / 2];
    step = 0x1999;
    switch (*(u32 *)(D_86B17A78 + arg0 * 4 + 0x34)) {
    case 6:
        ((s16 *)(D_86B17A78 + arg0 * 2))[0xE8 / 2] = func_86B07FB0(field_f0, field_e8, 0x1999, arg1);
        return;
    case 12:
        ((s16 *)(D_86B17A78 + arg0 * 2))[0xE8 / 2] = func_86B07FB0(field_f0, field_e8, 0x3332, arg1);
        return;
    case 0:
    case 1:
    case 3:
    case 5:
    case 8:
    case 10:
    case 13:
    case 15:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
        ((s16 *)(D_86B17A78 + arg0 * 2))[0xE8 / 2] = func_86B07FB0(field_f0, field_e8, 0xCCC, arg1);
        return;
    case 7:
        ((s16 *)(D_86B17A78 + arg0 * 2))[0xE8 / 2] = func_86B07FB0(field_f0, field_e8, 0x666, arg1);
        return;
    case 2:
    case 9:
        if (func_86B08088(field_f0, field_e8) < 0x1999) {
            step = 0xCCC;
        }
        if (func_86B08088(field_f0, field_e8) < 0xCCC) {
            step = 0x666;
        }
        if (func_86B08088(field_f0, field_e8) < 0x666) {
            step = 0x333;
        }
        if (func_86B08088(field_f0, field_e8) < 0x333) {
            step = 0x199;
        }
        ((s16 *)(D_86B17A78 + arg0 * 2))[0xE8 / 2] = func_86B07FB0(field_f0, field_e8, (s16)(step / 4), arg1);
        return;
    default:
        ((s16 *)(D_86B17A78 + arg0 * 2))[0xE8 / 2] = func_86B07FB0(field_f0, field_e8, 0xCCC, arg1);
        return;
    }
}
/* mkdraft:func_86B07D94 end */
#endif

#ifdef VERSION_US
s32 func_86B08088(s16 arg0, s16 arg1);
s16 func_86B07FB0(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    s16 up;
    s16 upValue;
    s32 downValue;

    if (arg2 < func_86B08088(arg0, arg1)) {
        up = arg1 + arg2;
        upValue = func_86B08088(arg0, up);
        downValue = func_86B08088(arg0, (s16)(arg1 - arg2));
        if (arg3 == 1) {
            return (s16)(arg1 - arg2);
        }
        if (arg3 == 2) {
            return up;
        }
        if (upValue < downValue) {
            return up;
        }
        return (s16)(arg1 - arg2);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
s32 func_86B08088(s16 arg0, s16 arg1) {
    s32 diff;
    if (arg0 >= arg1) {
        diff = arg0 - arg1;
    } else {
        diff = arg1 - arg0;
    }
    if (diff >= 0x8000) {
        diff = 0xFFFF - diff;
    }
    return (s16)diff;
}
#endif

#ifdef VERSION_US
f32 func_86B080D4(f32 arg0, f32 arg1) {
    f32 var_fv1;

    if (arg1 <= arg0) {
        var_fv1 = arg0 - arg1;
    } else {
        var_fv1 = arg1 - arg0;
    }
    if (3.1415927f < var_fv1) {
        var_fv1 = (f32) (6.283185482025146484375 - (f64) var_fv1);
    }
    return var_fv1;
}
#endif

#ifdef VERSION_US
f32 func_86B08120(f32 arg0, f32 arg1) {
    f32 wrap;
    f32 delta;
    f32 result = arg0 - arg1;
    if (arg0 < 0.0f) { wrap = 6.2831855f; arg0 += wrap; }
    wrap = 6.2831855f;
    if (wrap < arg0) arg0 -= wrap;
    if (arg1 < 0.0f) arg1 += wrap;
    if (wrap < arg1) arg1 -= wrap;
    delta = arg0 - arg1;
    result = delta;
    if (arg0 < arg1) result = delta + wrap;
    if (wrap < result) result -= wrap;
    return result;
}
#endif

#ifdef VERSION_US
extern void func_87F0277C(s32 *);
extern u8 D_86B0E1A8;
extern u8 D_86B0E7F8;
extern u8 D_86B0E9A0;
extern u8 D_86B0EE60;
extern u8 D_86B12AD0;
extern u8 D_86B13A68;
void func_86B081B4(void) {
    func_87F0277C(&D_86B0E9A0);
    func_87F0277C(&D_86B0EE60);
    func_87F0277C(&D_86B12AD0);
    func_87F0277C(&D_86B13A68);
    func_87F0277C(&D_86B0E1A8);
    func_87F0277C(&D_86B0E7F8);
}
#endif

#ifdef VERSION_US

/* mkdraft:func_86B08214 begin */
extern u8 D_80094E78[];
extern u8 D_80094F50[];
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern s32 func_8004D1FC(u8 *arg0);
extern u16 D_80094904;
extern Gfx *D_800D0510;
extern u8 D_86B0DA94[];
extern s32 D_86B17D00;
extern u8 *D_86B1817C;
extern u8 *D_86B18180[];
extern u16 D_86B18210;
extern u8 D_86B17A78[];



void func_86B08214(void)
{
  Gfx *temp_v0_5;
  f32 glyph_w0;
  f32 glyph_w1;
  f32 glyph_w2;
  f32 glyph_w3;
  f32 glyph_h0;
  f32 glyph_h1;
  f32 glyph_h2;
  f32 glyph_h3;
  f32 round_w;
  f32 round_h;
  s16 temp_s2;
  s32 temp_s3;
  s32 temp_s4;
  s32 temp_v0;
  u8 *new_var;
  s32 var_s7;
  void *temp_t1;
  void *temp_v0_10;
  void *temp_v0_8;
  void *temp_v1;
 for (var_s7 = 0; var_s7 != 4; var_s7++) { new_var = (u8 *) (D_86B17A78 + (var_s7 * 4)); if ((((*((s32 *) (new_var + 0x374))) - D_86B17D00) - 5) >= 0) { temp_v0 = *((s32 *) (new_var + 0x394)); if (temp_v0 != 0) { temp_t1 = (var_s7 * 0xC) + D_86B17A78; temp_v1 = D_86B0DA94 + (var_s7 * 0x18); if (D_86B18210 != D_80094904) { *((s32 *) (((u8 *) (D_86B17A78 + (var_s7 * 4))) + 0x394)) = (s32) (temp_v0 - 1); } temp_s4 = (s32) ((*((f32 *) (((u8 *) temp_t1) + 0x468))) - 36.0f);
          temp_s3 = (s32) (*((f32 *) (((u8 *) temp_t1) + 0x46C))); { Gfx *_g = (Gfx *) (D_800D0510++); _g->words.w0 = (((unsigned int) ((((unsigned int) 0xde) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) 0x00) & ((0x01 << 8) - 1)) << 16))) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 16) - 1)) << 0)); _g->words.w1 = (unsigned int) D_80094E78; } ; gDPSetPrimColor(D_800D0510++, 0, 0, *((s32 *) (((u8 *) temp_v1) + 0)), *((s32 *) (((u8 *) temp_v1) + 4)), *((s32 *) (((u8 *) temp_v1) + 8)), 0xFF); gDPSetEnvColor(D_800D0510++, *((s32 *) (((u8 *) temp_v1) + 0xC)), *((s32 *) (((u8 *) temp_v1) + 0x10)), *((s32 *) (((u8 *) temp_v1) + 0x14)), 0xFF); { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFC30B261; _g->words.w1 = 0x5566FF7F; } func_8004D1FC(D_86B1817C); glyph_w0 = (f32) ((u32) (*((u16 *) (((u8 *) D_86B1817C) + 0)))); if (glyph_w0 > 0.0f) { round_w = 0.5f; } else { round_w = -0.5f; } glyph_h1 = (f32) ((u32) (*((u16 *) (((u8 *) D_86B1817C) + 2)))); if (glyph_h1 > 0.0f) { round_h = 0.5f; } else { round_h = -0.5f; } GfxRect_DrawTextured((s16) temp_s4, (s16) temp_s3, (s16) ((s32) (round_w + glyph_w0)), (s16) ((s32) (round_h + glyph_h1)), 0, 0, 0x400, 0x400, 0); { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFB000000; _g->words.w1 = -1U; } { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFC61FEC3; _g->words.w1 = -0xC07U; } func_8004D1FC(D_86B18180[((s32) (*((s32 *) (new_var + 0x3A4)))) / 100]); temp_v0_8 = D_86B18180[((s32) (*((s32 *) (((u8 *) (D_86B17A78 + (var_s7 * 4))) + 0x3A4)))) / 100]; temp_s2 = temp_s3 + 3; glyph_w1 = (f32) (*((u16 *) (((u8 *) temp_v0_8) + 0))); if (glyph_w1 > 0.0f) { round_w = 0.5f; } else { round_w = -0.5f; } glyph_h0 = (f32) ((u32) (*((u16 *) (((u8 *) temp_v0_8) + 2)))); if (glyph_h0 > 0.0f) { round_h = 0.5f; } else { round_h = -0.5f; } GfxRect_DrawTextured((s16) (temp_s4 + 8), temp_s2, (s16) ((s32) (round_w + glyph_w1)), (s16) ((s32) (round_h + glyph_h0)), 0, 0, 0x400, 0x400, 0); func_8004D1FC(D_86B18180[(((s32) (*((s32 *) (new_var + 0x3A4)))) / 10) % 10]); temp_v0_10 = D_86B18180[(((s32) (*((s32 *) (new_var + 0x3A4)))) / 10) % 10]; glyph_w2 = (f32) ((u32) (*((u16 *) (((u8 *) temp_v0_10) + 0)))); if (glyph_w2 > 0.0f) { round_w = 0.5f; } else { round_w = -0.5f; } glyph_h2 = (f32) ((u32) (*((u16 *) (((u8 *) temp_v0_10) + 2)))); if (glyph_h2 > 0.0f) { round_h = 0.5f; } else { round_h = -0.5f; } GfxRect_DrawTextured((s16) (temp_s4 + 0x14), temp_s2, (s16) ((s32) (round_w + glyph_w2)), (s16) ((s32) (round_h + glyph_h2)), 0, 0, 0x400, 0x400, 0); func_8004D1FC(D_86B18180[((s32) (*((s32 *) (((u8 *) (D_86B17A78 + (var_s7 * 4))) + 0x3A4)))) % 10]); temp_v0_10 = D_86B18180[((s32) (*((s32 *) (new_var + 0x3A4)))) % 10]; glyph_w3 = (f32) ((u32) (*((u16 *) (((u8 *) temp_v0_10) + 0)))); if (glyph_w3 > 0.0f) { round_w = 0.5f; } else { round_w = -0.5f; } glyph_h3 = (f32) ((u32) (*((u16 *) (((u8 *) temp_v0_10) + 2)))); if (glyph_h3 > 0.0f) { round_h = 0.5f; } else { round_h = -0.5f; } GfxRect_DrawTextured((s16) (temp_s4 + 0x1C), temp_s2, (s16) ((s32) (round_w + glyph_w3)), (s16) ((s32) (round_h + glyph_h3)), 0, 0, 0x400, 0x400, 0); { Gfx *_g = (Gfx *) (D_800D0510++); _g->words.w0 = ((unsigned int) ((((unsigned int) 0xde) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) 0x00) & ((0x01 << 8) - 1)) << 16)); _g->words.w1 = (unsigned int) D_80094F50; } ; } } } 
  D_86B18210 = D_80094904;
}
/* mkdraft:func_86B08214 end */
#endif

#ifdef VERSION_US
extern void func_8003F210(void *, s32);
extern void func_86B0B608(s32);
extern void func_86B0B9A0(void);
extern void func_87F00688(void);
extern u8 D_86B17340[];
extern u8 D_86B16DA0[];
extern s32 D_86B17910;
extern s32 D_86B17908;

// D_86B181F0 (Unk86B181F0) is declared above func_86B00A3C; its unk18 records hold an RGBA color at 0x12..0x15.

// When the fade mode is 1, resets the four 0x168-byte animations at D_86B17340, starts the four
// at D_86B16DA0 with D_86B16D90's clips and colors their records (0xFF, 0xFF, 0xFF, 0xB4), sets
// up the D_86B17910 animation at frame 0x1E, starts a fade from opaque and sets the stage state
// to 3. Otherwise it advances the D_86B17340 animations (func_8003F210 mode 7), restarts each
// finished one at a random frame 0..5 and stores -0x1001 at offset 0x20.
void func_86B08978(void) {
    s32 i;
    Unk86B_18 *color;

    if (StageContext_GetFadeMode() == 1) {
        for (i = 0; i < 4; i++) {
            func_8003F1DC(D_86B17340 + i * 0x168);
        }
        for (i = 0; i < 4; i++) {
            func_8003F114(D_86B16DA0 + i * 0x168, 0, -1, D_86B16D90[i]);
            func_86B0B608(i);
            color = &D_86B181F0.unk18[i];
            color->unk12 = 0xFF;
            color->unk13 = 0xFF;
            color->unk14 = 0xFF;
            color->unk15 = 0xB4;
        }
        func_8003F1DC(&D_86B17910);
        func_8003F114(&D_86B17910, 0, -1, D_86B17908);
        func_8003F210(&D_86B17910, 1);
        ModelAnim_SetFrame(&D_86B17910, 0x1E);
        func_8003F3BC(&D_86B17910, 0);
        func_86B0B9A0();
        StageFade_StartFromOpaque(0x14);
        *(s32 *)D_86B181C0 = 3;
        func_87F00688();
    } else {
        for (i = 0; i < 4; i++) {
            func_8003F210(D_86B17340 + i * 0x168, 7);
            if (func_8003EC54(D_86B17340 + i * 0x168) == 1) {
                ModelAnim_SetFrame(D_86B17340 + i * 0x168, guRandom() % 6);
            }
            *(s16 *)(D_86B17340 + i * 0x168 + 0x20) = -0x1001;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_86B0B04C(void);
extern s32 D_86B17B40[4];
extern s32 D_86B17DDC[4];
extern s32 D_86B17DEC[4];
extern s32 D_86B17DFC[4];
extern s32 D_86B17F1C[4];
extern s32 D_86B17C1C[4];
// Reaches the state record through the in-unit sStateHead (as func_86B007D0
// does): the stores alias the +0x284 counter and the 2-stores share one lui.
void func_86B08B74(void) {
    s32 i;
    if (*(s32 *)sStateHead == 0) {
        if (*(s32 *)(sStateHead + 0x284) == 14) {
            for (i = 0; i < 4; i++) {
                ((s32 *)(sStateHead + 0x34))[i] = 2;
            }
        }
        if ((*(s32 *)(sStateHead + 0x284))++ < 15) {
            return;
        }
    }
    *(s32 *)(sStateHead + 0x284) = 0;
    *(s32 *)(sStateHead + 0x33C) = 0;
    *(s32 *)(sStateHead + 0x340) = 0;
    *(s32 *)(sStateHead + 0x32C) = 0;
    *(s32 *)(sStateHead + 0x498) = 0;
    *(s32 *)(sStateHead + 0x354) = 0;
    *(s32 *)(sStateHead + 0x358) = 0;
    for (i = 0; i < 4; i++) {
        D_86B17B40[i] = 7;
        D_86B17DDC[i] = 0;
        D_86B17DEC[i] = 0;
        D_86B17DFC[i] = 0;
        D_86B17F1C[i] = 0;
        D_86B17C1C[i] = 0;
    }
    *(s32 *)(sStateHead + 0x70) = 0;
    func_86B0B04C();
    *(s32 *)D_86B181C0 = 5;
}
#endif

void func_86B08CEC(void) {
}

#ifdef VERSION_US
extern void func_86B057B0(void);
extern void func_86B081B4(void);
extern void func_87F02684(void *);
extern u8 D_86B0E9A0;
extern u8 D_86B0EE60;
extern u8 D_86B17A78[];
extern u8 * D_86B181C0;
void func_86B08CF4(void) {
    s32 state;
    *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.016);
    if (*(f32 *)(D_86B17A78 + 0xF8) < 0.0f) {
        *(f32 *)(D_86B17A78 + 0xF8) += 6.2831855f;
    }
    func_86B057B0();
    func_86B081B4();
    state = *(s32 *)(D_86B17A78 + 0x44);
    if (state == 1) {
        if ((*(s32 *)(D_86B17A78 + 0x34) == 2 || *(s32 *)(D_86B17A78 + 0x34) == 0) &&
            (*(s32 *)(D_86B17A78 + 0x38) == 2 || *(s32 *)(D_86B17A78 + 0x38) == 0) &&
            (*(s32 *)(D_86B17A78 + 0x3C) == 2 || *(s32 *)(D_86B17A78 + 0x3C) == 0) &&
            (*(s32 *)(D_86B17A78 + 0x40) == 2 || *(s32 *)(D_86B17A78 + 0x40) == 0)) {
            *(s32 *)(D_86B17A78 + 0x44) = 2;
            state = 2;
        }
    }
    if (state == 0) {
        func_87F02684(&D_86B0E9A0);
        func_87F02684(&D_86B0EE60);
        *(s32 *)D_86B181C0 = 6;
    }
}
#endif

void func_86B08E08(void) {
}

#ifdef VERSION_US
extern void func_86B057B0(void);
extern void func_87F02684(void *);
extern u8 D_86B0E9A0;
extern u8 D_86B0EE60;
extern u8 D_86B17A78[];
extern u8 * D_86B181C0;
void func_86B08E10(void) {
    s32 old;
    *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.016);
    if (*(f32 *)(D_86B17A78 + 0xF8) < 0.0f) {
        *(f32 *)(D_86B17A78 + 0xF8) += 6.2831855f;
    }
    func_86B057B0();
    old = *(s32 *)D_86B17A78;
    *(s32 *)(D_86B17A78 + 0x284) = 0;
    if ((*(s32 *)D_86B17A78)++ < 4) {
        *(s32 *)D_86B181C0 = 4;
    } else if (*(s32 *)(D_86B17A78 + 0x354) != 0) {
        *(s32 *)(D_86B17A78 + 0x44) = 1;
        *(s32 *)D_86B181C0 = 8;
    } else if (*(s32 *)(D_86B17A78 + 0x44) == 0) {
        func_87F02684(&D_86B0E9A0);
        func_87F02684(&D_86B0EE60);
        *(s32 *)(D_86B17A78 + 0x354) = 1;
    } else {
        *(s32 *)(D_86B17A78 + 0x44) = 2;
    }
}
#endif

void func_86B08F18(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B08F20.s")
#endif

void func_86B09378(void) {
}

#ifdef VERSION_US
/* mkdraft:func_86B09380 begin */



void func_86B09380(void) {
    s32 found;
    s32 i;
    s32 counter;

    found = 0;
    counter = *(s32 *)(D_86B17A78 + 0x284);
    *(s32 *)(D_86B17A78 + 0x284) = counter + 1;
    if (counter == 0) {
        *(s32 *)D_86B181C0 = 10;
        *(s32 *)(D_86B17A78 + 0x360) = 1;
    }
    i = 0;
    do {
        if (*(s32 *)(D_86B17A78 + i * 4 + 0x34) == 0x16) {
            found = 1;
        }
        i += 1;
    } while (D_86B17A88 != D_86B17A78 + i * 4);
    if (found != 0) {
        *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.024);
    } else {
        *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.07200000000000001);
    }
    if (*(f32 *)(D_86B17A78 + 0xF8) < 0.0f) {
        *(f32 *)(D_86B17A78 + 0xF8) += 6.2831855f;
    }
    func_86B057B0();
    func_86B081B4();
}
/* mkdraft:func_86B09380 end */
#endif

void func_86B09478(void) {
}

#ifdef VERSION_US
void func_86B09480(void) {
    s32 frame;
    s32 done = 0;
    f32 value;

    frame = *(s32 *)((u8 *)D_87F119DC + 28);
    if (frame > 10) {
        value = (f64)(frame - 10) * 0.06 + 2.0;
        *(f32 *)((u8 *)D_87F119DC + 92) = value;
        *(f32 *)((u8 *)D_87F119DC + 88) = value;
        *(f32 *)((u8 *)D_87F119DC + 84) = value;
        *(s32 *)(D_86B17A78 + 148) -= 12;
    }
    if (frame > 30) {
        done = 1;
    }
    if (done) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_86B17F30;
extern u8 D_86B17B0C;
extern s32 D_86B180D4;
extern void func_86B09480(void);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 * func_87F025B8(u8 *, void (*)(void));
void func_86B0952C(void) {
    u8 *object;
    u8 *base;
    object = func_87F025B8(&D_86B17F30, func_86B09480);
    if (object != NULL) {
        *(s32 *)(object + 0x1C) = 0;
        *(f32 *)(object + 0x48) = 0.0f;
        *(f32 *)(object + 0x4C) = 0.0f;
        *(f32 *)(object + 0x50) = 0.0f;
        *(f32 *)(object + 0x5C) = 2.0f;
        *(f32 *)(object + 0x58) = 2.0f;
        *(f32 *)(object + 0x54) = 2.0f;
        *(s32 *)&D_86B17B0C = 0xFF;
        base = object + 0x24;
        func_8003F1DC(base);
        func_8003F114(base, 0, -1, D_86B180D4);
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_86B17A78[];
extern u8 *D_86B180E0[];
extern Gfx *D_86B180D8;
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);



void func_86B095B4(s32 arg0, Gfx *arg1) {
    u8 *tex;

    if (arg0 == 5) {
        // FAKE: the callback's unused second argument holds the display-list
        // cursor. The plain macro form gDPPipeSync(D_800D0510++) scores 20
        // (the temp lands in v1); a Gfx *gfx local gives v0 but grows the
        // frame to 0x58 and scores 26.
        arg1 = D_800D0510;
        D_800D0510 = arg1 + 1;
        gDPPipeSync(arg1);
        switch (*(s32 *)(D_86B17A78 + 0x00)) {
        case 0:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0x96, 0xE6, 0xFF, *(s32 *)(D_86B17A78 + 0x94));
            gDPSetEnvColor(D_800D0510++, 0x28, 0x50, 0x7C, 0xFF);
            break;
        case 1:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xDC, 0xDC, 0xDC, *(s32 *)(D_86B17A78 + 0x94));
            gDPSetEnvColor(D_800D0510++, 0xBE, 0x82, 0x00, 0xFF);
            break;
        case 2:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0x78, *(s32 *)(D_86B17A78 + 0x94));
            gDPSetEnvColor(D_800D0510++, 0xB4, 0x46, 0x00, 0xFF);
            break;
        case 3:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xE1, 0xD7, 0xFF, *(s32 *)(D_86B17A78 + 0x94));
            gDPSetEnvColor(D_800D0510++, 0x73, 0x4B, 0xA5, 0xFF);
            break;
        case 4:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xB4, 0x00, *(s32 *)(D_86B17A78 + 0x94));
            gDPSetEnvColor(D_800D0510++, 0x00, 0x00, 0x00, 0xFF);
            break;
        }
        gDPSetCombine(D_800D0510++, 0x30B3FF, 0x5FFEFE38);
        tex = D_86B180E0[*(s32 *)(D_86B17A78 + 0x00)];
        gSPSegment(D_800D0510++, 0xF, func_8004CA60(tex));
        gSPDisplayList(D_800D0510++, D_86B180D8);
        func_8003CD84();
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86B09834 begin */

void func_86B09834(void) {
    s32 found;
    s32 i;

    found = 0;
    if (*(s32 *)(D_86B17A78 + 0x360) != 0) {
        // Index-driven scan: uopt strength-reduces `D_86B17A78 + i * 4` into a
        // loop cursor with its own preheader lui/addiu of D_86B17A78, kept
        // separate from the la that serves the 0x360/0xF8 field loads (a2).
        // The reversed compare order produces the exit branch's `bnel v0, a0`.
        i = 0;
        do {
            if (*(s32 *)(D_86B17A78 + i * 4 + 0x34) == 0x16) {
                found = 1;
            }
            i += 1;
        } while (D_86B17A88 != D_86B17A78 + i * 4);
        if (found != 0) {
            *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.024);
        } else {
            *(f32 *)(D_86B17A78 + 0xF8) = (f32)((f64)*(f32 *)(D_86B17A78 + 0xF8) - 0.07200000000000001);
        }
        if (*(f32 *)(D_86B17A78 + 0xF8) < 0.0f) {
            *(f32 *)(D_86B17A78 + 0xF8) += 6.2831855f;
        }
        func_86B057B0();
        func_86B081B4();
    }
}
/* mkdraft:func_86B09834 end */
#endif

#ifdef VERSION_US
#define F61_RND(f) (((f) > 0.0f) ? 0.5f : -0.5f)
#define F61_W(tex, sc) ((f32)(u32)((u16 *)(tex))[0] * (sc))
#define F61_H(tex, sc) ((f32)(u32)((u16 *)(tex))[1] * (sc))
#define F61_DRAW_S(tex, x, y, sc, d) GfxRect_DrawTextured(x, y, (s16)(s32)(F61_W(tex, sc) + F61_RND(F61_W(tex, sc))), (s16)(s32)(F61_H(tex, sc) + F61_RND(F61_H(tex, sc))), 0, 0, d, d, 0);
#define F61_W1(tex) ((f32)(u32)((u16 *)(tex))[0])
#define F61_H1(tex) ((f32)(u32)((u16 *)(tex))[1])
#define F61_DRAW(tex, x, y, d) GfxRect_DrawTextured(x, y, (s16)(s32)(F61_W1(tex) + F61_RND(F61_W1(tex))), (s16)(s32)(F61_H1(tex) + F61_RND(F61_H1(tex))), 0, 0, d, d, 0);
#define F61_PANEL(bit, idx, x, y) \
    if (*(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & (bit)) { \
        func_8004D1FC(D_86B180F8[idx]); F61_DRAW_S(D_86B180F8[idx], x, y, 0.8f, 0x500) \
    } else { \
        func_8004D1FC(D_86B18108[idx]); F61_DRAW_S(D_86B18108[idx], x, y, 0.8f, 0x500) \
    }
#define COL86B0990C(off) (*(s32 *)(D_86B17A78 + (off)))
extern s32 D_86B0DAF4[4][2];
extern s32 D_86B0DB14[4][6];
extern s32 D_86B0DB74[4][5][2];
extern s32 D_86B0DC14[][2];
extern void func_87F0D600(u8 *, s32, s32, s32, f32, f32);
extern u8 D_80094E38[];
typedef struct { s32 w; } F61Col4;

void func_86B0990C(void) {
    f32 inv;
    f32 frac;
    u32 i;
    s32 num;
    s32 x_off;
    s32 k;
    Gfx *_gs;


    { _gs = (Gfx *)(D_800D0510++); _gs->words.w0 = _SHIFTL(G_DL, 24, 8) | _SHIFTL(G_DL_PUSH, 16, 8); _gs->words.w1 = (unsigned int)(D_80094E38); }

    F61_PANEL(1, 0, 0x16, 0x10)
    F61_PANEL(2, 1, 0x10E, 0x10)
    F61_PANEL(4, 2, 0x16, 0xCB)
    F61_PANEL(8, 3, 0x10E, 0xCB)

    { _gs = (Gfx *)(D_800D0510++); _gs->words.w0 = _SHIFTL(G_DL, 24, 8) | _SHIFTL(G_DL_PUSH, 16, 8); _gs->words.w1 = (unsigned int)(D_80094F50); }
    func_87F0D600(D_86B0E148, 0, 0x16, 0x10, 0.8f, 0.8f);
    func_87F0D600(D_86B0E148, 1, 0x10E, 0x10, 0.8f, 0.8f);
    func_87F0D600(D_86B0E148, 2, 0x16, 0xCB, 0.8f, 0.8f);
    func_87F0D600(D_86B0E148, 3, 0x10E, 0xCB, 0.8f, 0.8f);

    if (*(s32 *)(D_86B17A78 + 0x19C) != 0) {
        gSPDisplayList(D_800D0510++, D_80094E78);

        if (*(s32 *)(D_86B17A78 + 0x338) == 0) {
            (*(F61Col4 *)(D_86B17A78 + 0x330)) = (((F61Col4 *)D_86B181A8)[0]);
            (*(F61Col4 *)(D_86B17A78 + 0x334)) = (((F61Col4 *)D_86B181A8)[1]);
        }
        // FAKE: the (x - x) term makes cfe evaluate the right side first; uopt folds it back to 10 at input,
        // which keeps retail's `bne v1,s8` operand order.
        if (*(s32 *)(D_86B17A78 + 0x338) == (10 - (*(s32 *)(D_86B17A78 + 0x338) - *(s32 *)(D_86B17A78 + 0x338)))) {
            (*(F61Col4 *)(D_86B17A78 + 0x330)) = (((F61Col4 *)D_86B181A8)[1]);
            (*(F61Col4 *)(D_86B17A78 + 0x334)) = (((F61Col4 *)D_86B181A8)[2]);
        }
        if (*(s32 *)(D_86B17A78 + 0x338) == 20) {
            (*(F61Col4 *)(D_86B17A78 + 0x330)) = (((F61Col4 *)D_86B181A8)[2]);
            (*(F61Col4 *)(D_86B17A78 + 0x334)) = (((F61Col4 *)D_86B181A8)[3]);
        }
        if (*(s32 *)(D_86B17A78 + 0x338) == 30) {
            (*(F61Col4 *)(D_86B17A78 + 0x330)) = (((F61Col4 *)D_86B181A8)[3]);
            (*(F61Col4 *)(D_86B17A78 + 0x334)) = (((F61Col4 *)D_86B181A8)[4]);
        }
        if (*(s32 *)(D_86B17A78 + 0x338) == 40) {
            (*(F61Col4 *)(D_86B17A78 + 0x330)) = (((F61Col4 *)D_86B181A8)[4]);
            (*(F61Col4 *)(D_86B17A78 + 0x334)) = (((F61Col4 *)D_86B181A8)[5]);
        }
        if (*(s32 *)(D_86B17A78 + 0x338) == 50) {
            (*(F61Col4 *)(D_86B17A78 + 0x330)) = (((F61Col4 *)D_86B181A8)[5]);
            (*(F61Col4 *)(D_86B17A78 + 0x334)) = (((F61Col4 *)D_86B181A8)[0]);
        }
        frac = (f32)(*(s32 *)(D_86B17A78 + 0x338) % 10) / 10.0f;
        inv = 1.0f - frac;
        if ((*(s32 *)(D_86B17A78 + 0x338) += 1) >= 60) {
            *(s32 *)(D_86B17A78 + 0x338) = 0;
        }

        for (i = 0; i != 4; i++) {
            x_off = 0;
            if ((*(s32 *)(D_86B17A78 + 0x1A0) != 0) && (*(s32 *)(D_86B17A78 + i * 4 + 0x274) != 0)) {
                { Gfx *_g = (Gfx *)(D_800D0510++); _g->words.w0 = (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(0, 8, 8) | _SHIFTL(0, 0, 8)); _g->words.w1 = (_SHIFTL((f32)(u32)D_86B17A78[0x331] * inv + (f32)(u32)D_86B17A78[0x335] * frac, 16, 8) | _SHIFTL((f32)(u32)D_86B17A78[0x332] * inv + (f32)(u32)D_86B17A78[0x336] * frac, 8, 8) | _SHIFTL((f32)(u32)D_86B17A78[0x334] * frac + (f32)(u32)D_86B17A78[0x330] * inv, 24, 8) | _SHIFTL(0xFF, 0, 8)); } { Gfx *_g = (Gfx *)(D_800D0510++); _g->words.w0 = (_SHIFTL(G_SETENVCOLOR, 24, 8)); _g->words.w1 = (_SHIFTL(0xFF, 24, 8) | _SHIFTL(0xFF, 16, 8) | _SHIFTL(0xFF, 8, 8) | _SHIFTL(0xFF, 0, 8)); }
                { Gfx *_g = (Gfx *)(D_800D0510++); _g->words.w0 = _SHIFTL(G_SETCOMBINE, 24, 8) | 0x30B261; _g->words.w1 = 0x5566FF7F; }
            } else {
                gDPSetPrimColor(D_800D0510++, 0, 0, D_86B0DB14[i][0], D_86B0DB14[i][1], D_86B0DB14[i][2], 0xFF);
                gDPSetEnvColor(D_800D0510++, D_86B0DB14[i][3], D_86B0DB14[i][4], D_86B0DB14[i][5], 0xFF);
                { Gfx *_g = (Gfx *)(D_800D0510++); _g->words.w0 = _SHIFTL(G_SETCOMBINE, 24, 8) | 0x30B261; _g->words.w1 = 0x5566FF7F; }
            }

            k = *(s32 *)(D_86B17A78 + i * 4 + 0x18C); num = k;
            do {
                func_8004D1FC(D_86B18150[num % 10]);
                F61_DRAW_S(D_86B18150[num % 10], (s16)(D_86B0DAF4[i][0] - x_off + 0x27), (s16)D_86B0DAF4[i][1], 0.57f, 0x704);
                x_off += 0xD;
                num /= 10;
            } while (num != 0);

            func_8004D1FC(D_86B18178);
            F61_DRAW_S(D_86B18178, (s16)(D_86B0DAF4[i][0] + 0x37), (s16)(D_86B0DAF4[i][1] + 4), 0.8f, 0x500);

        }
        gSPDisplayList(D_800D0510++, D_80094F50);
    }

    if ((*(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4) && (*(s32 *)D_86B181C0 != 0) && (*(s32 *)D_86B181C0 != 1) && (*(s32 *)D_86B181C0 != 2) && (D_86B0D160 == 0)) {
        gSPDisplayList(D_800D0510++, D_80094E38);
        i = 2;
        do {
            for (k = 0; k < *(s32 *)(D_86B17A78 + i * 4 + 0x1B4); k++) {
                if ((*(s32 *)(D_86B17A78 + i * 4 + 0x1B4) - 1 == k) && (*(s32 *)(D_86B17A78 + i * 4 + 0x1A4) % 2)) {
                    gDPSetCombine(D_800D0510++, 0x377E6E, 0x11FCF279);
                    gDPSetPrimColor(D_800D0510++, 0x64, 0x64, 0xFF, 0xFF, 0xFF, 0xFF);
                } else {
                    gSPDisplayList(D_800D0510++, D_80094E38);
                }

                                func_8004D1FC(D_86B18118[*(s32 *)(D_86B17A78 + i * 20 + k * 4 + 0x1C4)]);
                                F61_DRAW(D_86B18118[*(s32 *)(D_86B17A78 + i * 20 + k * 4 + 0x1C4)], (s16)(D_86B0DB74[i][k][0] + D_86B0DC14[*(s32 *)(D_86B17A78 + i * 20 + k * 4 + 0x1C4)][0]),
                         (s16)(D_86B0DB74[i][k][1] + D_86B0DC14[*(s32 *)(D_86B17A78 + i * 20 + k * 4 + 0x1C4)][1]), 0x400);

                if (*(s32 *)(D_86B17A78 + i * 20 + k * 4 + 0x224) != 0) {
                    gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xB4, 0x00, 0xFF);
                    gDPSetEnvColor(D_800D0510++, 0x00, 0x00, 0x00, 0xFF);
                    gDPSetCombine(D_800D0510++, 0x30FE61, 0xFFFFF3F9);
                    num = *(s32 *)(D_86B17A78 + i * 20 + k * 4 + 0x224);
                    if (num / 10 != 0) {
                        func_8004D1FC(D_86B18128[num / 10]);
                        F61_DRAW(D_86B18128[num / 10], (s16)(D_86B0DB74[i][k][0] + 0xA), (s16)(D_86B0DB74[i][k][1] + 0xD), 0x400);
                    }
                    func_8004D1FC(D_86B18128[num % 10]);
                    F61_DRAW(D_86B18128[num % 10], (s16)(D_86B0DB74[i][k][0] + 0xE), (s16)(D_86B0DB74[i][k][1] + 0xD), 0x400);
                }
            }
            i++;
        } while (i != 4);
        gSPDisplayList(D_800D0510++, D_80094F50);
    }
}

#endif

#ifdef VERSION_US
extern u8 D_86B17A78[];
extern u8 D_86B17A88[];
extern u8 D_86B17D04[];
extern u8 D_86B17DA4[];
extern s32 func_86B0BF2C(u8 *);



void func_86B0B04C(void) {
    s32 i;
    s32 j;
    s32 flag;
    s32 r;

    flag = 1;
    if (*(s32 *)(D_86B17A78 + 0) == 0) {
        j = *(s32 *)(D_86B17A78 + 0x68);
        if (j == 0 || j == 1) {
            flag = 0;
        }
    }
    switch (*(s32 *)(D_86B17A78 + 0)) {
    case 0:
    case 1:
    case 2:
    case 3:
        do {
            if (flag != 0) {
                switch (guRandom() % 4) {
                case 0:
                case 1:
                    *(s32 *)(D_86B17A78 + 0xC) = 0;
                    break;
                case 2:
                    *(s32 *)(D_86B17A78 + 0xC) = 1;
                    break;
                case 3:
                    *(s32 *)(D_86B17A78 + 0xC) = 2;
                    break;
                }
            } else {
                switch (guRandom() % 3) {
                case 0:
                case 1:
                    *(s32 *)(D_86B17A78 + 0xC) = 0;
                    break;
                case 2:
                    *(s32 *)(D_86B17A78 + 0xC) = 1;
                    break;
                }
            }
        } while (*(s32 *)(D_86B17A78 + 0xC) == *(s32 *)(D_86B17A78 + 4) &&
                 *(s32 *)(D_86B17A78 + 0xC) == *(s32 *)(D_86B17A78 + 8));

        *(s32 *)(D_86B17A78 + 4) = *(s32 *)(D_86B17A78 + 8);
        *(s32 *)(D_86B17A78 + 8) = *(s32 *)(D_86B17A78 + 0xC);
        switch (*(s32 *)(D_86B17A78 + 0xC)) {
        case 0:
            switch (guRandom() % 3) {
            case 0:
                *(s32 *)(D_86B17A78 + 0x10) = 0;
                break;
            case 1:
            case 2:
                *(s32 *)(D_86B17A78 + 0x10) = 1;
                break;
            }
            break;
        case 1:
            *(s32 *)(D_86B17A78 + 0x10) = 0;
            *(s32 *)(D_86B17A78 + 0x348) = 10;
            break;
        case 2:
            break;
        }
        break;
    case 4:
        *(s32 *)(D_86B17A78 + 0xC) = 1;
        *(s32 *)(D_86B17A78 + 0x10) = 1;
        *(s32 *)(D_86B17A78 + 0x348) = 10;
        *(s32 *)(D_86B17A78 + 0x34C) = 10;
        *(s32 *)(D_86B17A78 + 0x350) = 10;
        break;
    }

    switch (*(s32 *)(D_86B17A78 + 0x68)) {
    case 0:
    case 1:
        *(s32 *)(D_86B17A78 + 0x288) = (guRandom() % 141) + 60;
        break;
    case 2:
    case 3:
        if ((guRandom() % 100) < 20) {
            *(s32 *)(D_86B17A78 + 0x288) = (guRandom() % 21) + 30;
        } else {
            *(s32 *)(D_86B17A78 + 0x288) = (guRandom() % 141) + 60;
        }
        break;
    }

    i = 0;
    do {
        if (*(s32 *)(D_86B17A78 + i * 4 + 0x34) == 0x10 ||
            *(s32 *)(D_86B17A78 + i * 4 + 0x34) == 0x11 ||
            *(s32 *)(D_86B17A78 + i * 4 + 0x34) == 0x12 ||
            *(s32 *)(D_86B17A78 + i * 4 + 0x34) == 0) {
            *(s32 *)(D_86B17A78 + 0x288) = (guRandom() % 51) + 70;
        }
        i++;
    } while ((u8 *)D_86B17A88 > (u8 *)(D_86B17A78 + i * 4));

    if (*(s32 *)(D_86B17A78 + 0x288) >= 60) {
        r = guRandom();
        switch (*(s32 *)(D_86B17A78 + 0x68)) {
        case 0:
        case 1:
            if (r % 100 < 0) {
                *(s32 *)(D_86B17A78 + 0x70) = 3;
            } else if (r % 100 < 5) {
                *(s32 *)(D_86B17A78 + 0x70) = 2;
            } else if (r % 100 < 30) {
                *(s32 *)(D_86B17A78 + 0x70) = 1;
            } else {
                *(s32 *)(D_86B17A78 + 0x70) = 0;
            }
            break;
        case 2:
        case 3:
            if (r % 100 < 5) {
                *(s32 *)(D_86B17A78 + 0x70) = 3;
            } else if (r % 100 < 15) {
                *(s32 *)(D_86B17A78 + 0x70) = 2;
            } else if (r % 100 < 40) {
                *(s32 *)(D_86B17A78 + 0x70) = 1;
            } else {
                *(s32 *)(D_86B17A78 + 0x70) = 0;
            }
            break;
        }

    i = 0;
    if (*(s32 *)(D_86B17A78 + 0x70) > 0) {
        do {
            *(s32 *)(D_86B17A78 + i * 4 + 0x84) =
                10 + ((*(s32 *)(D_86B17A78 + 0x288) - 10) / *(s32 *)(D_86B17A78 + 0x70)) * i +
                    (guRandom() % (((*(s32 *)(D_86B17A78 + 0x288) - 10) / *(s32 *)(D_86B17A78 + 0x70)) - 14));
            i++;
        } while (i < *(s32 *)(D_86B17A78 + 0x70));
    }

    }

    i = 0;
    do {
        func_86B0BF2C(D_86B17D04 + i * 0x28);
        i++;
    } while (D_86B17DA4 != D_86B17D04 + i * 0x28);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86B0B500 begin */
extern u8 D_86B17A78[];
extern u8 D_86B17A88[];
extern s32 D_86B17BF4;
extern s32 D_86B17BF8;
extern s32 D_86B17BFC;
extern s32 D_86B17C00;
extern s32 D_86B17CEC;
extern s32 D_86B17CF0;
extern s32 D_86B17CF4;
extern s32 D_86B17CF8;


void func_86B0B500(void) {
    // FAKE: the pointer copies give D_86B17CF0/D_86B17CF8 their own store temps;
    // diff score 460 without them.
    s32 *D_86B17CF0_ptr = &D_86B17CF0;
    s32 *D_86B17CF8_ptr = &D_86B17CF8;
    s32 largest;
    s32 i;

    largest = -1;
    i = 0;
    do {
        if (largest < *(s32 *)(D_86B17A78 + i * 4 + 0x17C)) largest = *(s32 *)(D_86B17A78 + i * 4 + 0x17C);
        i++;
    } while ((u8 *)D_86B17A88 > (u8 *)(D_86B17A78 + i * 4));
    if (largest == D_86B17BF4) D_86B17CEC = 1;
    if (largest == D_86B17BF8) (*D_86B17CF0_ptr) = 1;
    if (largest == D_86B17BFC) D_86B17CF4 = 1;
    if (largest == D_86B17C00) (*D_86B17CF8_ptr) = 1;
    if (*(s32 *)(D_86B17A78 + 0x27C) * (*(s32 *)(D_86B17A78 + 0x278) * (*(s32 *)(D_86B17A78 + 0x274) * *(s32 *)(D_86B17A78 + 0x280))) != 0) {
        *(s32 *)(D_86B17A78 + 0x274) = 0;
        *(s32 *)(D_86B17A78 + 0x278) = 0;
        *(s32 *)(D_86B17A78 + 0x27C) = 0;
        *(s32 *)(D_86B17A78 + 0x280) = 0;
    }
}
/* mkdraft:func_86B0B500 end */
#endif

// The retail func_86B0B500.s also holds the two-instruction glabel D_86B0B600
// (a bare `jr ra; nop`), so the fragment keeps its size only with this definition
// here. func_86B0B608 passes its address to func_87F025B8 as a callback.
//@asm/us/nonmatchings/fragments/61/fragment61_code/func_86B0B500.s
void D_86B0B600(void) {
}

#ifdef VERSION_US
extern void func_80037E3C(u8 *, void *, s32);
extern s32 func_86B0355C(s32, u8 *);
extern void D_86B0B600();
extern u8 D_86B17A78[];
extern s32 D_86B0E7F0;
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 * func_87F025B8(u8 *, void (*)(void));
extern u8 D_86B0E1A8;
void func_86B0B608(s32 arg0) {
    u8 *object;
    object = func_87F025B8(&D_86B0E1A8, D_86B0B600);
    if (object != NULL) {
        func_80037E3C(object + 0x24, func_86B0355C, arg0);
        *(f32 *)(object + 0x48) = *(f32 *)(D_86B17A78 + (arg0 << 3) + 0x14);
        *(f32 *)(object + 0x4C) = 0.0f;
        *(f32 *)(object + 0x50) = *(f32 *)(D_86B17A78 + (arg0 << 3) + 0x18);
        *(s16 *)(object + 0x42) = -0x4001;
        *(s32 *)(object + 0x38) = arg0;
        *(s32 *)(object + 0x20) = arg0;
        *(f32 *)(object + 0x54) = 2.5f;
        *(f32 *)(object + 0x58) = 2.5f;
        *(f32 *)(object + 0x5C) = 2.5f;
        func_8003F1DC(object + 0x24);
        func_8003F114(object + 0x24, 0, -1, D_86B0E7F0);
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern s32 D_86B0E7F4;
void func_86B0B6CC(s32 arg0, s32 arg1) {
    s32 pad[2];
    s32 temp_v0;
    if (arg0 == 5) {
        temp_v0 = func_8004C990(0x133, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 0, 0, 0, 0x80);
        gDPSetCombine(D_800D0510++, 0xFCFFD3FF, 0xFFFEFE38);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)temp_v0));
        gSPDisplayList(D_800D0510++, D_86B0E7F4);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
s32 func_8003EC54(s32 *);
extern s32 D_86B17910;
extern s32 D_86B17ABC;

void func_86B0B7B4(void)
{
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fv0;
  f32 temp_fv1_2;
  f64 temp_fv0_2;
  f64 temp_fv0_3;
  f64 temp_fv1;
  int new_var;
  switch (D_86B17ABC)
  {
    case 0:
      *((f32 *) (((u8 *) D_87F119DC) + 0x5C)) = 7.0f;
      temp_fv0 = *((f32 *) (((u8 *) D_87F119DC) + 0x5C));
      *((f32 *) (((u8 *) D_87F119DC) + 0x58)) = temp_fv0;
      *((f32 *) (((u8 *) D_87F119DC) + 0x54)) = temp_fv0;
      new_var = 0xFF;
      *((s8 *) (((u8 *) D_87F119DC) + 0x41)) = new_var;
      return;

    case 1:
      temp_fv0_2 = (f64) (((f32) (func_8003EC54(&D_86B17910) - 1)) / 30.0f);
      temp_fv1 = 1.0 - temp_fv0_2;
      temp_fa0 = (f32) ((temp_fv1 * 7.0) + (3.5 * temp_fv0_2));
      *((f32 *) (((u8 *) D_87F119DC) + 0x5C)) = temp_fa0;
      *((f32 *) (((u8 *) D_87F119DC) + 0x58)) = temp_fa0;
      *((f32 *) (((u8 *) D_87F119DC) + 0x54)) = temp_fa0;
      *((s32 *) (((u8 *) D_87F119DC) + 0x38)) = (s32) ((temp_fv1 * 128.0) + (64.0 * temp_fv0_2));
      return;

    case 2:
      temp_fv1_2 = ((f32) (func_8003EC54(&D_86B17910) - 1)) / 27.0f;
      temp_fv0_3 = 1.0 - ((f64) temp_fv1_2);
      temp_fa0_2 = (f32) ((temp_fv0_3 * 3.5) + ((f64) (7.0f * temp_fv1_2)));
      *((f32 *) (((u8 *) D_87F119DC) + 0x5C)) = temp_fa0_2;
      *((f32 *) (((u8 *) D_87F119DC) + 0x58)) = temp_fa0_2;
      *((f32 *) (((u8 *) D_87F119DC) + 0x54)) = temp_fa0_2;
      *((s8 *) (((u8 *) D_87F119DC) + 0x41)) = (s8) ((s32) ((temp_fv0_3 * 64.0) + ((f64) (128.0f * temp_fv1_2))));
      return;

  }

}

extern void func_86B0B7B4(void);
#endif

#ifdef VERSION_US
extern void func_86B0B7B4(void);
extern s32 D_86B0E99C;
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 * func_87F025B8(u8 *, void (*)(void));
extern u8 D_86B0E7F8;
void func_86B0B9A0(void) {
    u8 *object;
    u8 *base;
    object = func_87F025B8(&D_86B0E7F8, func_86B0B7B4);
    if (object != NULL) {
        *(s16 *)(object + 0x42) = -0x4001;
        *(s32 *)(object + 0x38) = 0x40;
        base = object + 0x24;
        *(f32 *)(object + 0x48) = 0.0f;
        *(f32 *)(object + 0x4C) = 0.0f;
        *(f32 *)(object + 0x50) = 0.0f;
        *(f32 *)(object + 0x5C) = 3.5f;
        *(f32 *)(object + 0x58) = 3.5f;
        *(f32 *)(object + 0x54) = 3.5f;
        func_8003F1DC(base);
        func_8003F114(base, 0, -1, D_86B0E99C);
    }
}
#endif

#ifdef VERSION_US
extern u8 *D_8009491C;
extern void GeoRender_ApplyMaterialState(void);
extern s32 func_8004C990(s32, s32);
extern u8 * func_8004CA60(u8 *);
extern Gfx * D_800D0510;
extern s32 D_86B0E7F4;
void func_86B0BA28(s32 arg0, s32 arg1) {
    s32 pad0[2];
    s32 alpha;
    s32 temp_v0;
    s32 pad2[2];
    Gfx *pkt;
    if (arg0 == 5) {
        temp_v0 = (s32)D_8009491C;
        alpha = *(s32 *)(temp_v0 + 0x14);
        temp_v0 = func_8004C990(0x133, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 0, 0, 0, alpha);
        gDPSetCombine(D_800D0510++, 0xFCFFD3FF, 0xFFFEFE38);
        pkt = D_800D0510++;
        gSPSegment(pkt, 0xF, func_8004CA60((u8 *)temp_v0));
        gSPDisplayList(D_800D0510++, D_86B0E7F4);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
extern u8 D_86B17A78[];
extern u8 *D_86B181C0;
extern s32 D_86B17CFC;
extern s32 D_86B0E0A0;
extern u8 D_800CE060[];

void func_86B0BB24(s32 arg0) {
    s32 i;

    if (*(s32 *)D_86B181C0 == 9 || *(s32 *)D_86B181C0 == 10 || *(s32 *)D_86B181C0 == 11) {
        return;
    }
    switch (arg0) {
        case 0:
            if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 && (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 1)) {
                return;
            }
            break;
        case 1:
            if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 && (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 2)) {
                return;
            }
            break;
        case 2:
            if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 && (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 4)) {
                return;
            }
            break;
        case 3:
            if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 && (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 8)) {
                return;
            }
            break;
    }
    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0xC000;
    for (i = 0; i < 4; i += 2) {
        if (D_86B17CFC == ((s32 (*)[10])(D_86B17A78 + 0x28C))[arg0][i]) {
            *(u16 *)(D_800CE060 + arg0 * 40 + 8) |= 0x8000;
        }
        if (D_86B17CFC == ((s32 (*)[10])(D_86B17A78 + 0x28C))[arg0][i + 4]) {
            *(u16 *)(D_800CE060 + arg0 * 40 + 8) |= 0x4000;
        }
        if (D_86B17CFC == ((s32 (*)[10])(D_86B17A78 + 0x28C))[arg0][i + 1]) {
            *(u16 *)(D_800CE060 + arg0 * 40 + 8) |= 0x8000;
        }
        if (D_86B17CFC == ((s32 (*)[10])(D_86B17A78 + 0x28C))[arg0][i + 5]) {
            *(u16 *)(D_800CE060 + arg0 * 40 + 8) |= 0x4000;
        }
    }
    if (D_86B17CFC == *(s32 *)(D_86B17A78 + arg0 * 40 + 0x2AC)) {
        *(u16 *)(D_800CE060 + arg0 * 40 + 8) |= 0x8000;
    }
    if (*(s32 *)(D_86B17A78 + arg0 * 40 + 0x2B0) > 0 && D_86B17CFC >= *(s32 *)(D_86B17A78 + arg0 * 40 + 0x2B0)) {
        *(u16 *)(D_800CE060 + arg0 * 40 + 8) |= 0x8000;
    }
    switch (*(s32 *)(D_86B17A78 + 0x68)) {
        case 0:
            if (D_86B0E0A0 != 0) {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 23) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            } else {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 18) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            }
            break;
        case 1:
            if (D_86B0E0A0 != 0) {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 17) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            } else {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 13) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            }
            break;
        case 2:
            if (D_86B0E0A0 != 0) {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 14) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            } else {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 11) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            }
            break;
        case 3:
            if (D_86B0E0A0 != 0) {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 13) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            } else {
                if (D_86B17CFC >= *(s32 *)(D_86B17A78 + 0x288) && D_86B17CFC < *(s32 *)(D_86B17A78 + 0x288) + 10) {
                    *(u16 *)(D_800CE060 + arg0 * 40 + 8) &= ~0x8000;
                }
            }
            break;
    }
}

#endif

#ifdef VERSION_US
/* mkdraft:func_86B0BF2C begin */
typedef struct {
    s32 x[10];
} Rec40;
extern u8 D_86B17A78[];
extern s32 D_86B0E0A0;


s32 func_86B0BF2C(u8 *arg0)
{
  s32 rnd;
  s32 out[10];
  s32 b[4];
  s32 a[4];
  int new_var;
  s32 i;
  for (i = 0; i < 4; i++)
  {
    switch (*((s32 *) (D_86B17A78 + 0x68)))
    {
      case 0:
        if (D_86B0E0A0 != 0)
      {
        b[i] = (guRandom() % 11) + 0x17;
        a[i] = (guRandom() % 11) + 0x17;
      }
      else
      {
        b[i] = (guRandom() % 11) + 0x12;
        a[i] = (guRandom() % 11) + 0x12;
      }
        break;

      case 1:
        if (D_86B0E0A0 != 0)
      {
        b[i] = (guRandom() % 11) + 0x11;
        a[i] = (guRandom() % 11) + 0x11;
      }
      else
      {
        b[i] = (guRandom() % 11) + 0xD;
        a[i] = (guRandom() % 11) + 0xD;
      }
        break;

      case 2:
        if (D_86B0E0A0 != 0)
      {
        b[i] = (guRandom() % 9) + 0xE;
        a[i] = (guRandom() % 9) + 0xE;
      }
      else
      {
        b[i] = (guRandom() % 9) + 0xB;
        a[i] = (guRandom() % 9) + 0xB;
      }
        break;

      case 3:
        if (D_86B0E0A0 != 0)
      {
        b[i] = (guRandom() % 7) + 0xD;
        a[i] = (guRandom() % 7) + 0xD;
      }
      else
      {
        b[i] = (guRandom() % 7) + 0xA;
        a[i] = (guRandom() % 7) + 0xA;
      }
        break;

    }

    out[i] = -1;
    out[i + 4] = -1;
  }

  out[8] = -1;
  out[9] = -1;
  rnd = guRandom();
  new_var = rnd % 100;
  if ((*((s32 *) (D_86B17A78 + 0x70))) != 0)
  {
    for (i = 0; i < (*((s32 *) (D_86B17A78 + 0x70))); i++)
    {
      switch (*((s32 *) (D_86B17A78 + 0x68)))
      {
        case 0:
          if (i == ((*((s32 *) (D_86B17A78 + 0x70))) - 1))
        {
          if (new_var < 40)
          {
            out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
            if ((rnd % 100) < 60)
          {
            out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
          {
            out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[i];
          }
        }
        else
          if (new_var < 10)
        {
          out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
        else
          if ((rnd % 100) < 30)
        {
          out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
          break;

        case 1:
          if (i == ((*((s32 *) (D_86B17A78 + 0x70))) - 1))
        {
          if (new_var < 30)
          {
            out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
            if (new_var < 60)
          {
            out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
          {
            out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[i];
          }
        }
        else
          if (new_var < 7)
        {
          out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
        else
          if ((rnd % 100) < 37)
        {
          out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
          break;

        case 2:
          if (i == ((*((s32 *) (D_86B17A78 + 0x70))) - 1))
        {
          if ((rnd % 100) < 20)
          {
            out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
            if (new_var < 60)
          {
            out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
          {
            out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[i];
          }
        }
        else
          if (new_var < 5)
        {
          out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
        else
          if (new_var < 45)
        {
          out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
          break;

        case 3:
          if (i == ((*((s32 *) (D_86B17A78 + 0x70))) - 1))
        {
          if (new_var < 10)
          {
            out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
            if ((rnd % 100) < 60)
          {
            out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
          }
          else
          {
            out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[i];
          }
        }
        else
          if (new_var < 2)
        {
          out[i] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
        else
          if ((rnd % 100) < 52)
        {
          out[i + 4] = (*((s32 *) ((D_86B17A78 + 0x84) + (i * 4)))) + a[i];
        }
          break;

      }

    }

  }
  if ((*((s32 *) (D_86B17A78 + 0x70))) == 0)
  {
    switch (*((s32 *) (D_86B17A78 + 0x68)))
    {
      case 0:
        if ((*((s32 *) (D_86B17A78 + 0xC))) != 2)
      {

        if (new_var < 20)
        {
          out[7] = (*((s32 *) (D_86B17A78 + 0x288))) + a[3];
        }
        else
        {
          out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
        }

      }
      else
        if ((rnd % 100) < 40)
      {
        out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
      }
      else
        if ((rnd % 100) < 60)
      {
        out[7] = (*((s32 *) (D_86B17A78 + 0x288))) + a[3];
      }
      else
      {
        out[3] = -1;
      }
        break;

      case 1:
        if ((*((s32 *) (D_86B17A78 + 0xC))) != 2)
      {

        if (new_var < 10)
        {
          out[7] = (*((s32 *) (D_86B17A78 + 0x288))) + a[3];
        }
        else
        {
          out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
        }

      }
      else
        if (new_var < 30)
      {
        out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
      }
      else
        if (new_var < 40)
      {
        out[7] = (*((s32 *) (D_86B17A78 + 0x288))) + a[3];
      }
      else
      {
        out[3] = -1;
      }
        break;

      case 2:
        if ((*((s32 *) (D_86B17A78 + 0xC))) != 2)
      {
        out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
      }
      else
        if ((rnd % 100) < 20)
      {
        out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
      }
      else
      {
        out[3] = -1;
      }
        break;

      case 3:
        if ((*((s32 *) (D_86B17A78 + 0xC))) != 2)
      {
        out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
      }
      else
        if (new_var < 10)
      {
        out[3] = (*((s32 *) (D_86B17A78 + 0x288))) + b[3];
      }
      else
      {
        out[3] = -1;
      }
        break;

    }

  }
  if ((*((s32 *) (D_86B17A78 + 0xC))) != 2)
  {
    if (D_86B0E0A0 != 0)
    {
      switch (*((s32 *) (D_86B17A78 + 0x68)))
      {
        case 0:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x22;
          break;

        case 1:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x1C;
          break;

        case 2:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x17;
          break;

        case 3:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x14;
          break;

      }

    }
    else
    {
      switch (*((s32 *) (D_86B17A78 + 0x68)))
      {
        case 0:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x1D;
          break;

        case 1:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x18;
          break;

        case 2:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x14;
          break;

        case 3:
          out[9] = ((*((s32 *) (D_86B17A78 + 0x288))) + (guRandom() % 4)) + 0x11;
          break;

      }

    }
  }
  else
  {
    out[9] = -1;
  }
  *((Rec40 *) arg0) = *((Rec40 *) out);
  return arg0;
}
/* mkdraft:func_86B0BF2C end */
#endif

#ifdef VERSION_US
/* mkdraft:func_86B0CB1C begin */
extern s32 D_86B0E0A0;
extern u8 D_86B17A78[];
extern u8 *D_86B181C0;



void func_86B0CB1C(s32 arg0) {
    // FAKE: the four unreferenced slots below are what makes IDO reserve the
    // retail function's 0x68-byte frame, spill the `j` loop counter at 0x60, and
    // keep the four `limit` spills at 0x50/0x4c/0x48/0x44.  Without them the frame
    // is 0x58 bytes and `j` spills at 0x54 (diff score 70).
    s32 pad0;
    s32 j;
    s32 pad1[3];
    s32 limit0;
    s32 limit1;
    s32 limit2;
    s32 limit3;
    s32 i;
    s32 k;
    s32 rnd;

    if (D_86B0E0A0 != 0) {
        limit0 = 0x20;
        limit1 = 0x18;
        limit2 = 0x12;
        limit3 = 0xE;
    } else {
        limit0 = 0x1B;
        limit1 = 0x14;
        limit2 = 0xF;
        limit3 = 0xC;
    }
    if (*(s32 *)(D_86B17A78 + 0x70) != 0) {
        for (i = 0; i != 4; i++) {
            switch (i) {
            case 0:
                if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 &&
                    (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 1)) {
                    continue;
                }
                break;
            case 1:
                if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 &&
                    (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 2)) {
                    continue;
                }
                break;
            case 2:
                if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 &&
                    (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 4)) {
                    continue;
                }
                break;
            case 3:
                if (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2180) != 4 &&
                    (*(u8 *)(*(u8 **)(D_86B181C0 + 0xC) + 0x2182) & 8)) {
                    continue;
                }
                break;
            }
            for (j = 0; j != 4; j++) {
                if (i == j) {
                    continue;
                }
                if (arg0 == *(s32 *)(D_86B17A78 + j * 4 + 0x384)) {
                    rnd = guRandom() % 100;
                    // `k == count - 1` keeps the counter in s2 as in retail;
                    // `k + 1 == count` makes IDO carry `k + 1` in a register of
                    // its own and colors `k` into s0 (diff score 212).
                    for (k = 0; k < *(s32 *)(D_86B17A78 + 0x70); k++) {
                        switch (*(s32 *)(D_86B17A78 + 0x68)) {
                        case 0:
                            if (k == *(s32 *)(D_86B17A78 + 0x70) - 1) {
                                if (rnd < 0x50) {
                                    if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                        *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit0 >= arg0) {
                                        *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 13 + arg0 + 0x1A;
                                    }
                                }
                            } else if (rnd < 0x14) {
                                if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                    *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit0 >= arg0) {
                                    *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 13 + arg0 + 0x1A;
                                }
                            }
                            break;
                        case 1:
                            if (k == *(s32 *)(D_86B17A78 + 0x70) - 1) {
                                if (rnd < 0x3C) {
                                    if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                        *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit1 >= arg0) {
                                        *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 11 + arg0 + 0x15;
                                    }
                                }
                            } else if (rnd < 0xF) {
                                if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                    *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit1 >= arg0) {
                                    *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 11 + arg0 + 0x15;
                                }
                            }
                            break;
                        case 2:
                            if (k == *(s32 *)(D_86B17A78 + 0x70) - 1) {
                                if (rnd < 0x28) {
                                    if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                        *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit2 >= arg0) {
                                        *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 9 + arg0 + 0xE;
                                    }
                                }
                            } else if (rnd < 0xA) {
                                if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                    *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit2 >= arg0) {
                                    *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 9 + arg0 + 0xE;
                                }
                            }
                            break;
                        case 3:
                            if (k == *(s32 *)(D_86B17A78 + 0x70) - 1) {
                                if (rnd < 0x14) {
                                    if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                        *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit3 >= arg0) {
                                        *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 7 + arg0 + 0xB;
                                    }
                                }
                            } else if (rnd < 5) {
                                if (arg0 >= *(s32 *)(D_86B17A78 + k * 4 + 0x84) &&
                                    *(s32 *)(D_86B17A78 + k * 4 + 0x84) + limit3 >= arg0) {
                                    *(s32 *)(D_86B17A78 + i * 0x28 + 0x2AC) = guRandom() % 7 + arg0 + 0xB;
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}
/* mkdraft:func_86B0CB1C end */
#endif
