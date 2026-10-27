#include "global.h"


// Model display object at 0x004 of each D_8291A7C0 record. func_8003F018 attaches it to a
// display root, func_8003F114 initializes it, and the ModelAnim_* functions read its animation
// channel at 0x040. Only the members this file uses are broken out.
//@src/229E0.c
typedef struct unk_D_8291A7C0_000_004 {
    /* 0x000 */ u8 unk_000;
    /* 0x001 */ u8 unk_001; // bit 0 set by func_8003F114, cleared by func_8003F03C and func_8003F1DC
    /* 0x002 */ u8 unk_002; // flag bits written by func_8003F114
    /* 0x003 */ char unk_003[0x17];
    /* 0x01A */ s16 modelId; // func_8003F114's model argument
    /* 0x01C */ u8 unk_01C;
    /* 0x01D */ u8 alpha; // func_8003F4DC stores it; func_8003F114 resets it to 0xFF
    /* 0x01E */ char unk_01E[0x12];
    /* 0x030 */ f32 scale[3]; // func_8290A6F4 sets all three to the func_8004B888 factor for the model
    /* 0x03C */ char unk_03C[4];
    /* 0x040 */ s16 animation; // index ModelAnim_SetResourceAnimation compares and rebinds
    /* 0x042 */ char unk_042[0x1E];
    /* 0x060 */ f32 mtx[4][4]; // func_8003F114 sets identity; func_8290A208 stores the record's transform
    /* 0x0A0 */ char unk_0A0[0xC8];
} unk_D_8291A7C0_000_004; // size = 0x168

// Fragment67 model record. func_82908594 runs func_8003F018 over ten records and allocates load
// contexts for the first four; func_8290A5B0 activates records from the D_82913210 row selected by
// D_8291A7C0.unk_1068.
typedef struct unk_D_8291A7C0_000 {
    /* 0x000 */ s32 loadContext; // PokeIcon_AllocLoadContext(5) result; ModelAnim_SetResourceAnimation's resource
    /* 0x004 */ unk_D_8291A7C0_000_004 model;
    /* 0x16C */ f32 position[3]; // translation func_8290A208 builds into model.mtx
    /* 0x178 */ char unk_178[0x18];
    /* 0x190 */ s16 rotation[3]; // angles func_8290A208 passes to func_8290A0D0 for the rotation matrix
    /* 0x196 */ char unk_196[2];
    /* 0x198 */ f32 unk_198; // subtracted from the model-dependent height offset in func_8290A208
    /* 0x19C */ char unk_19C[4];
    /* 0x1A0 */ u16 unk_1A0; // frame counter; func_8290CFD8 increments it, func_8290B478 compares record 0's
    /* 0x1A2 */ u8 active; // set by func_8290A5B0/func_8290ABB0; per-frame updates skip records where it is 0
    /* 0x1A3 */ s8 unk_1A3; // func_8290A6F4 copies it from the D_82913820 entry
} unk_D_8291A7C0_000; // size = 0x1A4

// Fragment67 scene state: the model records followed by the scene selector and activation count.
// func_82908270 and func_8290894C address 0x1068 from the D_8291A7C0 base, so the fields after the
// records belong to the same object.
typedef struct unk_D_8291A7C0 {
    /* 0x0000 */ unk_D_8291A7C0_000 records[10];
    /* 0x1068 */ s16 unk_1068; // row of D_82913210 and entry of D_82916B80 used for this scene
    /* 0x106A */ s16 unk_106A;
    /* 0x106C */ char unk_106C[5];
    /* 0x1071 */ u8 unk_1071; // count of records activated by func_8290A5B0 and func_8290ABB0
} unk_D_8291A7C0; // size = 0x1074

#ifdef VERSION_US
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6[4];
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Fragment67Entry;

extern Fragment67Entry D_82916B80[];
extern unk_D_8291A7C0 D_8291A7C0;
extern u8 D_82913210[];
extern void *D_80094908;
extern void func_80037120(void *, void *, s16 *, s16 *, s16 *);
s32 func_82908270(s32 arg0, u8 *arg1) {
    s16 pad0;
    s16 pad1;
    s16 pad2;
    s16 sp30;
    s16 sp2E;
    s16 sp2C;

    if (arg0 == 2) {
        *(u8 *)(arg1 + 0x18) = D_82916B80[D_8291A7C0.unk_1068].unk0;
        *(u8 *)(arg1 + 0x19) = D_82916B80[D_8291A7C0.unk_1068].unk1;
        *(u8 *)(arg1 + 0x1A) = D_82916B80[D_8291A7C0.unk_1068].unk2;
        func_80037120((u8 *)D_80094908 + 0xB4, (u8 *)D_80094908 + 0xA8, &sp30, &sp2E, &sp2C);
        *(s16 *)(arg1 + 0x1C) = D_82916B80[D_8291A7C0.unk_1068].unkA + sp2E;
        *(s16 *)(arg1 + 0x1E) = D_82916B80[D_8291A7C0.unk_1068].unkC + sp2C;
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_82908370(s32 arg0, u8 *arg1) {
    s16 pad0;
    s16 pad1;
    s16 pad2;
    s16 sp30;
    s16 sp2E;
    s16 sp2C;

    if (arg0 == 2) {
        *(u8 *)(arg1 + 0x18) = D_82916B80[D_8291A7C0.unk_1068].unk3;
        *(u8 *)(arg1 + 0x19) = D_82916B80[D_8291A7C0.unk_1068].unk4;
        *(u8 *)(arg1 + 0x1A) = D_82916B80[D_8291A7C0.unk_1068].unk5;
        func_80037120((u8 *)D_80094908 + 0xB4, (u8 *)D_80094908 + 0xA8, &sp30, &sp2E, &sp2C);
        *(s16 *)(arg1 + 0x1C) = D_82916B80[D_8291A7C0.unk_1068].unkE + sp2E;
        *(s16 *)(arg1 + 0x1E) = D_82916B80[D_8291A7C0.unk_1068].unk10 + sp2C;
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_82908470(s32 arg0, u8 *arg1) {
    if (arg0 == 2) {
        *(u8 *)(arg1 + 0x18) = D_82916B80[D_8291A7C0.unk_1068].unk6[0];
        *(u8 *)(arg1 + 0x19) = D_82916B80[D_8291A7C0.unk_1068].unk6[1];
        *(u8 *)(arg1 + 0x1A) = D_82916B80[D_8291A7C0.unk_1068].unk6[2];
    }
    return 0;
}
#endif

void func_829084DC(void) {
}

#ifdef VERSION_US
extern u8 D_82912F84;
extern u8 D_8291B838;

void func_829084E4(s32 arg0) {
    void *temp_v0;

    temp_v0 = (arg0 * 0x10) + &D_82912F84;
    (*(s32 *)((u8 *)(&D_8291B838) + (0))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (0)));
    (*(s32 *)((u8 *)(&D_8291B838) + (4))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (4)));
    (*(s32 *)((u8 *)(&D_8291B838) + (8))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (8)));
    (*(s32 *)((u8 *)(&D_8291B838) + (0xC))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (0xC)));
}
#endif

#ifdef VERSION_US
extern u8 D_8291B838;
extern s32 D_8291B858;

void func_82908520(void) {
    for (D_8291B858 = 0; D_8291B858 < 4; D_8291B858++) {
        ((void (*)(void)) *(s32 *)((u8 *)&D_8291B838 + D_8291B858 * 4))();
    }
}
#endif

#ifdef VERSION_US
extern void PokeIcon_InitResourceArchives(void);
extern void func_8003F018(s32);
extern s32 PokeIcon_AllocLoadContext(s32);
void func_82908594(void) { u8 *temp_s0; u8 *temp_s1; PokeIcon_InitResourceArchives(); temp_s0 = (u8 *)&D_8291A7C0.records[0].model; temp_s1 = (u8 *)&D_8291A7C0.records[10].model; do { func_8003F018((s32)temp_s0); temp_s0 += sizeof(unk_D_8291A7C0_000); } while (temp_s0 < temp_s1); temp_s0 = (u8 *)&D_8291A7C0.records[0]; temp_s1 = (u8 *)&D_8291A7C0.records[4]; do { ((unk_D_8291A7C0_000 *)temp_s0)->loadContext = PokeIcon_AllocLoadContext(5); temp_s0 += sizeof(unk_D_8291A7C0_000); } while (temp_s0 != temp_s1); }
#endif

#ifdef VERSION_US
extern void func_82908520();
extern s16 D_8291B862;

void func_82908608(void) {
    func_82908520();
    D_8291B862 += 1;
}
#endif

void func_82908638(void) {
}

#ifdef VERSION_US
extern u8 D_829130A8;
extern u8 D_8291B848;

void func_82908640(s32 arg0) {
    void *temp_v0;

    temp_v0 = (arg0 * 0x10) + &D_829130A8;
    (*(s32 *)((u8 *)(&D_8291B848) + (0))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (0)));
    (*(s32 *)((u8 *)(&D_8291B848) + (4))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (4)));
    (*(s32 *)((u8 *)(&D_8291B848) + (8))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (8)));
    (*(s32 *)((u8 *)(&D_8291B848) + (0xC))) = (s32) (*(s32 *)((u8 *)(temp_v0) + (0xC)));
}
#endif

#ifdef VERSION_US
extern u8 D_8291B848;
extern s32 D_8291B858;

void func_8290867C(void) {
    for (D_8291B858 = 0; D_8291B858 < 4; D_8291B858++) {
        ((void (*)(void)) *(s32 *)((u8 *)&D_8291B848 + D_8291B858 * 4))();
    }
}
#endif

void func_829086F0(void) {
}

#ifdef VERSION_US
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
extern s32 D_8291A380;
extern s16 D_8291B85C;
extern s16 D_8291B85E;
extern s16 D_8291B860;
extern s32 D_8291B868;
void func_829086F8(void) {
    s32 *slot;

    slot = &D_8291A380;
    *slot = *(s32 *)(D_8291B868 + 0xC);
    Vec3f_SetComponentsDuplicate((f32 *)(*slot + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0x96;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
    *(f32 *)(D_8291A380 + 0x34) = 10.0f;
    *(f32 *)(D_8291A380 + 0x38) = 6400.0f;
}
#endif

#ifdef VERSION_US
extern void func_8290867C(void);
void func_829087C0(void) {
    func_8290867C();
}
#endif

#ifdef VERSION_US
extern void func_8290E014(void);
void func_829087E0(void) {
    func_8290E014();
}
#endif

#ifdef VERSION_US
extern void GfxImage_FillCurrent(s32 *, s32);
extern void func_80008648();
extern void BgStage_DrawFrame();
extern void Geo_RenderRootNode(s32);
extern void GeoRender_AdvanceFrameCounter();
extern u8 D_800D0510;
extern s32 D_8291B868;
void func_82908800(void) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 1);
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_8291B868);
    func_829087E0();
    func_80008648();
}
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void func_800355E4(s32);
extern void StageFade_StartFromOpaque(s32);
extern s32 D_8291B864;
void func_82908854(void) {
    func_800086A4(0x14);
    func_800355E4(0x51);
    StageFade_StartFromOpaque(0x10);
    D_8291B864 = 1;
}
#endif

#ifdef VERSION_US
extern void func_80064D28();
void func_8290888C(void) {
    if (D_8291B864 != 0) {
        do {
            func_80064D28();
            func_82908608();
            func_829087C0();
            func_82908800();
        } while (D_8291B864 != 0);
    }
}
#endif

#ifdef VERSION_US
extern s32 StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
void func_829088EC(void) {
    s32 var_s0;

    StageFade_StartFromTransparent(0x10);
    func_800225C4(0x10);
    var_s0 = 0;
    do {
        func_82908608();
        func_829087C0();
        func_82908800();
        var_s0 += 1;
    } while (var_s0 != 0x10);
}
#endif

#ifdef VERSION_US
extern void *D_82912E80;
extern u16 D_82913178[];
extern s32 D_8291B86C;
extern void func_82908594(void);
extern void func_829084E4(s32);
extern void func_829086F8(void);
extern void func_82908640(s32);
extern u8 *MainPool_AllocState(s32, s32);
extern s32 main_pool_get_available(void);
extern s32 func_80040E80(u8 *, void *);
// D_8291A962, D_8291AB06, D_8291ACAA and D_8291AE4E are D_8291A7C0.records[0..3].active.
extern u8 D_8291A962;
extern u8 D_8291AB06;
extern u8 D_8291ACAA;
extern u8 D_8291AE4E;
void func_8290894C(void) {
    s32 pad; // FAKE: unused slot that moves pool to sp+0x18; diff score 12 without it.
    u8 *pool;

    pool = MainPool_AllocState(main_pool_get_available(), 0);
    D_8291B868 = func_80040E80(pool, &D_82912E80);
    D_8291B86C = WidgetTree_RunMessagePanelSilent((s32)pool, 166);
    MainPool_FinalizeAllocation((s32)pool);
    ModelRenderer_InitDisplayRoots();
    func_82908594();
    D_8291A7C0.unk_106A = 0;
    D_8291A7C0.unk_1068 = D_82913178[D_8291A7C0.unk_106A];
    // FAKE: separate symbols for records[0..3].active; diff score 755 without them.
    D_8291A962 = 0;
    D_8291AB06 = 0;
    D_8291ACAA = 0;
    D_8291AE4E = 0;
    func_829084E4(((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][15]);
    func_829086F8();
    func_82908640(((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][16]);
}
#endif

#ifdef VERSION_US
extern void Gfx_InitDisplayListBuffers(s32, s32);
s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32);
extern void func_80008574();
extern void func_8004C8C0(s32);
extern void func_8290894C();
extern void main_pool_pop_state(s32);
extern void main_pool_push_state(s32);
extern u8 D_446E30;
extern s32 func_80047588(s32 arg0, s32 arg1);
extern void func_8004C09C(s32 arg0);
s32 func_8004DDF4(s32 arg0);
u8 *Asset_LoadToSegment(s32 id, u8 *rom_start, u8 *rom_end, s32 arg3);
extern u8 D_1000000[];
extern u8 D_447D00[];
void func_80047610(void);
void Gfx_FreeDisplayListBuffers(void);
void func_8004C398(void);
s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
s32 func_8004DDF4(s32 arg0);
u8 *Asset_LoadToSegment(s32 id, u8 *rom_start, u8 *rom_end, s32 arg3);
void func_80047610(void);
void Gfx_FreeDisplayListBuffers(void);
void func_8004C398(void);
s32 func_82908A54(s32 arg0, s32 arg1) {
    s32 sp24;

    main_pool_push_state(0x454E44);
    Gfx_InitDisplayListBuffers(0x18000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    func_80047588(6, 0);
    func_8004C09C(0x21);
    func_8004C8C0(0xC1);
    func_8004DDF4(0xA6);
    Asset_LoadToSegment((s32) ((u32) ((s32) D_1000000 & 0x0F000000) >> 0x18), &D_446E30, D_447D00, 0);
    func_8290894C();
    func_80008514(sp24);
    func_82908854();
    func_8290888C();
    func_829088EC();
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    func_8004C398();
    main_pool_pop_state(0x454E44);
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_82908B60.s")
#endif

#ifdef VERSION_US
extern f32 Math_StepToF(f32, f32, f32, f32);
void func_82908BD8(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3) {
    f32 stepX;
    f32 stepY;
    f32 stepZ;

    stepX = (arg1[0] - arg2[0]) / (f32)arg3;
    stepY = (arg1[1] - arg2[1]) / (f32)arg3;
    stepZ = (arg1[2] - arg2[2]) / (f32)arg3;
    if (stepX < 0.0f) stepX *= -1.0f;
    if (stepY < 0.0f) stepY *= -1.0f;
    if (stepZ < 0.0f) stepZ *= -1.0f;
    arg0[0] = Math_StepToF(arg0[0], arg1[0], stepX, stepX);
    arg0[1] = Math_StepToF(arg0[1], arg1[1], stepY, stepY);
    arg0[2] = Math_StepToF(arg0[2], arg1[2], stepZ, stepZ);
}
#endif

#ifdef VERSION_US
extern f32 Math_StepToF(f32, f32, f32, f32);
void func_82908CF4(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3) {
    f32 stepX;
    f32 stepY;
    f32 stepZ;
    f32 stepW;

    stepX = (arg1[0] - arg2[0]) / (f32)arg3;
    stepY = (arg1[1] - arg2[1]) / (f32)arg3;
    stepZ = (arg1[2] - arg2[2]) / (f32)arg3;
    stepW = (arg1[3] - arg2[3]) / (f32)arg3;
    if (stepX < 0.0f) stepX *= -1.0f;
    if (stepY < 0.0f) stepY *= -1.0f;
    if (stepZ < 0.0f) stepZ *= -1.0f;
    if (stepW < 0.0f) stepW *= -1.0f;
    arg0[0] = Math_StepToF(arg0[0], arg1[0], stepX, stepX);
    arg0[1] = Math_StepToF(arg0[1], arg1[1], stepY, stepY);
    arg0[2] = Math_StepToF(arg0[2], arg1[2], stepZ, stepZ);
    arg0[3] = Math_StepToF(arg0[3], arg1[3], stepW, stepW);
}
#endif

#ifdef VERSION_US
void func_82908E50(f32 *arg0, f32 *arg1) { arg0[0] = arg1[0]; arg0[1] = arg1[1]; arg0[2] = arg1[2]; }
#endif

#ifdef VERSION_US
void func_82908E6C(f32 *arg0, const f32 *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_82908E90.s")
#endif

#ifdef VERSION_US
extern u8 D_8291B880;
extern f32 D_82916AF8;
extern f32 D_82916B08;
extern f32 D_82916B18;
extern f32 D_82916B28;
extern f32 D_82916B38;

void func_82908F60(s32 arg0, s32 arg1) {
    switch (arg0) {
        case 0:
            func_82908E6C((f32 *)((arg1 << 6) + 0x24 + &D_8291B880), &D_82916AF8);
            return;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            func_82908CF4((f32 *)((arg1 << 6) + 0x24 + &D_8291B880), &D_82916B08, &D_82916AF8, 5);
            return;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            func_82908CF4((f32 *)((arg1 << 6) + 0x24 + &D_8291B880), &D_82916B18, &D_82916B08, 6);
            return;
        case 12:
        case 13:
            func_82908CF4((f32 *)((arg1 << 6) + 0x24 + &D_8291B880), &D_82916B28, &D_82916B18, 2);
            return;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
            func_82908CF4((f32 *)((arg1 << 6) + 0x24 + &D_8291B880), &D_82916B38, &D_82916B28, 10);
            /* fallthrough */
        default:
            return;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_8291B880;
extern f32 D_82916AD4;
extern f32 D_82916AE0;
extern f32 D_82916AEC;

void func_829090A0(s32 arg0, s32 arg1) {
    switch (arg0) {
        case 0:
            func_82908E50((f32 *)((arg1 << 6) + 0x18 + &D_8291B880), &D_82916AD4);
            return;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            func_82908BD8((f32 *)((arg1 << 6) + 0x18 + &D_8291B880), &D_82916AE0, &D_82916AD4, 11);
            return;
        case 12:
        case 13:
        case 14:
            func_82908BD8((f32 *)((arg1 << 6) + 0x18 + &D_8291B880), &D_82916AEC, &D_82916AE0, 3);
            /* fallthrough */
        default:
            return;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_82909170.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_829092AC begin */
extern s16 D_8291B862;
extern u8 D_82916EB8;
extern u8 D_8291B880;
extern s32 func_80001FF0(void);
extern void func_82908E90(u8, s32);
extern void func_829090A0(s32, s32);
extern void func_82908F60(s32, s32);
extern void func_82909170(u8, s32);

void func_829092AC(void)
{
  s16 temp_s2;
  s16 temp_v1;
  s16 var_b862;
  u8 *temp_s0;
  s32 var_fp;
  s32 var_s1;
  s32 var_s5;
  var_fp = 0xE;
  if (((D_8291A7C0.unk_1068 == 0x24) || (D_8291A7C0.unk_1068 == 0x25)) || (D_8291A7C0.unk_1068 == 0x26))
  {
    var_fp = 1;
  }
  var_s1 = 0;
  if (var_fp > 0)
  {
 var_s5 = 0; do { temp_s2 = *((s16 *) ((((u8 *) D_82913210) + (D_8291A7C0.unk_1068 * 0x22)) + var_s5)); temp_s0 = (var_s1 << 6) + (&D_8291B880); if (temp_s2 > 0) { switch (*((u8 *) temp_s0)) { case 0:
            var_b862 = 1;
            if (func_80001FF0() == 0x32)
          {
            if (D_8291B862 == ((s32) (((f32) (*((s16 *) ((((u8 *) (&D_82916EB8)) + (temp_s2 * 4)) - 4)))) * 0.8f)))
            {
              *((u8 *) temp_s0) = var_b862;
              func_82908E90(*((u8 *) (temp_s0 + 2)), var_s1);
              func_829090A0(*((u8 *) (temp_s0 + 2)), var_s1);
              func_82908F60(*((u8 *) (temp_s0 + 2)), var_s1);
              func_82909170(*((u8 *) (temp_s0 + 2)), var_s1);
            }
          }
          else
            if (D_8291B862 == (*((s16 *) ((((u8 *) (&D_82916EB8)) + (temp_s2 * 4)) - 4))))
          {
            *((u8 *) temp_s0) = var_b862;
            func_82908E90(*((u8 *) (temp_s0 + 2)), var_s1);
            func_829090A0(*((u8 *) (temp_s0 + 2)), var_s1);
            func_82908F60(*((u8 *) (temp_s0 + 2)), var_s1);
            func_82909170(*((u8 *) (temp_s0 + 2)), var_s1);
          }
            break;

          case 1:
            func_82908E90(++(*((u8 *) (temp_s0 + 2))), var_s1);
            func_829090A0(*((u8 *) (temp_s0 + 2)), var_s1);
            func_82908F60(*((u8 *) (temp_s0 + 2)), var_s1);
            func_82909170(*((u8 *) (temp_s0 + 2)), var_s1);
            if (D_8291A7C0.unk_1068 == 0x27)
          {
            temp_v1 = *((s16 *) ((((u8 *) (&D_82916EB8)) + (temp_s2 * 4)) - 4));
            var_b862 = D_8291B862;
            if (((temp_v1 + 0x6E) >= var_b862) && ((*((u8 *) (temp_s0 + 2))) >= 0x18))
            {
              *((u8 *) (temp_s0 + 2)) = 0x18;
            }
            if (var_b862 == (temp_v1 + 0x78))
            {
              *((u8 *) temp_s0) = 0;
            }
            if ((*((u8 *) (temp_s0 + 2))) >= 0x1D)
            {
              *((u8 *) (temp_s0 + 2)) = 0x1D;
            }
          }
          else
            if ((*((u8 *) (temp_s0 + 2))) == 0x1E)
          {
            *((u8 *) temp_s0) = 0;
          }
            break;

        }

      }
      var_s1 += 1;
      var_s5 += 2;
    }
    while (var_s1 != var_fp);
  }
}
/* mkdraft:func_829092AC end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290954C.s")
#endif

#ifdef VERSION_US
extern void func_8004B7E0(s32, f32 *);
void func_8290A0B0(s32 model_id, f32 *offset) {
    func_8004B7E0(model_id, offset);
}
#endif

#ifdef VERSION_US
extern f32 D_80087E50[];
extern f32 D_80088E50[];
void func_8290A0D0(f32 *arg0, u16 *arg1) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;
    volatile f32 t0;
    volatile f32 t1;

    sx = D_80087E50[arg1[0] >> 4];
    cx = D_80088E50[arg1[0] >> 4];
    sy = D_80087E50[arg1[1] >> 4];
    cy = D_80088E50[arg1[1] >> 4];
    sz = D_80087E50[arg1[2] >> 4];
    cz = D_80088E50[arg1[2] >> 4];

    arg0[0] = cy * cz;
    arg0[1] = cy * sz;
    arg0[2] = -sy;
    arg0[3] = 0.0f;
    t0 = sx * sy;
    arg0[4] = t0 * cz - cx * sz;
    arg0[5] = t0 * sz + cx * cz;
    arg0[6] = sx * cy;
    arg0[7] = 0.0f;
    t1 = cx * sy;
    arg0[8] = t1 * cz + sx * sz;
    arg0[9] = t1 * sz - sx * cz;
    arg0[10] = cx * cy;
    arg0[11] = 0.0f;
    arg0[12] = 0.0f;
    arg0[13] = 0.0f;
    arg0[14] = 0.0f;
    arg0[15] = 1.0f;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290A208.s")
#endif

#ifdef VERSION_US
extern void func_8003F1DC(void *);
void func_8290A2FC(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8003F1DC(&D_8291A7C0.records[i].model);
        D_8291A7C0.records[i].active = 0;
    }
}
#endif

#ifdef VERSION_US
typedef union { s32 word; s8 bytes[4]; } Func80041FA0State;
extern s32 D_82912F10;
extern void func_8003F1DC(void *);
extern void func_80041FA0(s32, u16, Func80041FA0State);
void func_8290A358(s32 arg0, u16 arg1) {
    func_8003F1DC(&D_8291A7C0.records[arg0].model);
    func_80041FA0(D_8291A7C0.records[arg0].loadContext, (u16)arg1, *(Func80041FA0State *)(&D_82912F10));
}
#endif

#ifdef VERSION_US
typedef struct {
    /* 0x000 */ f32 position[14][3];
    /* 0x0A8 */ s16 rotation[14][3];
    /* 0x0FC */ f32 unk_0FC[14];
} unk_D_829139C0; // size = 0x134
extern unk_D_829139C0 D_829139C0[];
extern void func_8003F114(unk_D_8291A7C0_000_004 *, s16, s16, s32);
extern s32 ModelAnim_SetResourceAnimation(s32, unk_D_8291A7C0_000_004 *, s32);
extern void Vec3s_SetComponents(s16 *, s16, s16, s16);
extern f32 func_8004B888(s32);
void func_8290A3C4(s32 arg0, s32 arg1) {
    f32 scale;

    func_8003F114(&D_8291A7C0.records[arg0].model, 0, ((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][arg1], **(s32 **)(*(u8 **)(D_8291A7C0.records[arg0].loadContext + 0x38) + 8));
    ModelAnim_SetResourceAnimation(D_8291A7C0.records[arg0].loadContext, &D_8291A7C0.records[arg0].model, 0);
    D_8291A7C0.records[arg0].model.unk_002 &= ~0x40;
    Vec3f_SetComponentsDuplicate(D_8291A7C0.records[arg0].position, D_829139C0[D_8291A7C0.unk_1068].position[arg1][0], D_829139C0[D_8291A7C0.unk_1068].position[arg1][1], D_829139C0[D_8291A7C0.unk_1068].position[arg1][2]);
    Vec3s_SetComponents(D_8291A7C0.records[arg0].rotation, D_829139C0[D_8291A7C0.unk_1068].rotation[arg1][0], D_829139C0[D_8291A7C0.unk_1068].rotation[arg1][1], D_829139C0[D_8291A7C0.unk_1068].rotation[arg1][2]);
    scale = func_8004B888(((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][arg1]) * 0.05f;
    Vec3f_SetComponentsDuplicate(D_8291A7C0.records[arg0].model.scale, scale, scale, scale);
    D_8291A7C0.records[arg0].unk_198 = D_829139C0[D_8291A7C0.unk_1068].unk_0FC[arg1];
}
#endif

#ifdef VERSION_US
extern void func_82908B60(void);
extern void func_800428F8(s32);
extern void func_8290A208(s32);
extern void func_8290A358(s32 arg0, u16 arg1);
extern s16 D_8291B862;
void func_8290A5B0(s32 arg0) {
    s32 i;
    unk_D_8291A7C0_000 *actor;

    D_8291B862 = 0;
    D_8291A7C0.unk_1071 = 0;
    i = 0;
    do {
        D_8291A7C0.records[i].active = 0;
        i++;
    } while (&D_8291A7C0.records[i] < &D_8291A7C0.records[4]);
    func_82908B60();
    for (i = 0; i < arg0; i++) {
        actor = &D_8291A7C0.records[i];
        if (((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][i] != 0) {
            actor->active = 1;
            func_8290A358(i, ((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][i]);
            func_800428F8(actor->loadContext);
            func_8290A3C4(i, i);
            func_8290A208(i);
            actor->model.unk_002 |= 0x10;
            D_8291A7C0.unk_1071++;
        } else {
            actor->active = 0;
        }
    }
}
#endif

#ifdef VERSION_US
extern s16 D_829137A8[];
typedef struct {
    /* 0x00 */ f32 position[3];
    /* 0x0C */ s8 unk_0C;
} unk_D_82913820; // size = 0x10
extern unk_D_82913820 D_82913820[];
void func_8290A6F4(s32 arg0, s32 arg1) {
    f32 scale;

    func_8003F114(&D_8291A7C0.records[arg0].model, 0, D_829137A8[arg1], **(s32 **)(*(u8 **)(D_8291A7C0.records[arg0].loadContext + 0x38) + 8));
    ModelAnim_SetResourceAnimation(D_8291A7C0.records[arg0].loadContext, &D_8291A7C0.records[arg0].model, 0);
    D_8291A7C0.records[arg0].model.unk_002 &= ~0x40;
    Vec3s_SetComponents(D_8291A7C0.records[arg0].rotation, 0, 0, 0);
    Vec3f_SetComponentsDuplicate(D_8291A7C0.records[arg0].position, D_82913820[arg1].position[0], D_82913820[arg1].position[1], D_82913820[arg1].position[2]);
    D_8291A7C0.records[arg0].unk_1A3 = D_82913820[arg1].unk_0C;
    scale = func_8004B888(D_829137A8[arg1]) * 0.05f;
    Vec3f_SetComponentsDuplicate(D_8291A7C0.records[arg0].model.scale, scale, scale, scale);
    D_8291A7C0.records[arg0].unk_198 = 0.0f;
}
#endif

#ifdef VERSION_US
void func_8290A81C(s32 arg0) {
    s32 i;

    D_8291B862 = 0;
    D_8291A7C0.unk_1071 = 0;
    i = 0;
    do {
        D_8291A7C0.records[i].active = 0;
        i++;
    } while (&D_8291A7C0.records[i] < &D_8291A7C0.records[4]);
    func_82908B60();
    for (i = 0; i < arg0; i++) {
        if (D_829137A8[i] != 0) {
            D_8291A7C0.records[i].active = 1;
            func_8290A358(i, D_829137A8[i]);
            func_800428F8(D_8291A7C0.records[i].loadContext);
            func_8290A6F4(i, i);
            func_8290A208(i);
            D_8291A7C0.records[i].model.unk_002 |= 0x10;
            D_8291A7C0.unk_1071++;
        } else {
            D_8291A7C0.records[i].active = 0;
        }
    }
}
#endif

#ifdef VERSION_US
void func_8290A920(s32 arg0, s32 arg1) {
    f32 scale;

    func_8003F1DC(&D_8291A7C0.records[arg0].model);
    func_8003F114(&D_8291A7C0.records[arg0].model, 0, ((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][arg1], **(s32 **)(*(u8 **)(D_8291A7C0.records[0].loadContext + 0x38) + 8));
    ModelAnim_SetResourceAnimation(D_8291A7C0.records[0].loadContext, &D_8291A7C0.records[arg0].model, D_8291A7C0.records[0].model.animation);
    D_8291A7C0.records[arg0].model.unk_002 &= ~0x40;
    Vec3f_SetComponentsDuplicate(D_8291A7C0.records[arg0].position, D_829139C0[D_8291A7C0.unk_1068].position[arg1][0], D_829139C0[D_8291A7C0.unk_1068].position[arg1][1], D_829139C0[D_8291A7C0.unk_1068].position[arg1][2]);
    Vec3s_SetComponents(D_8291A7C0.records[arg0].rotation, D_829139C0[D_8291A7C0.unk_1068].rotation[arg1][0], D_829139C0[D_8291A7C0.unk_1068].rotation[arg1][1], D_829139C0[D_8291A7C0.unk_1068].rotation[arg1][2]);
    scale = func_8004B888(((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][arg1]) * 0.05f;
    Vec3f_SetComponentsDuplicate(D_8291A7C0.records[arg0].model.scale, scale, scale, scale);
    D_8291A7C0.records[arg0].unk_198 = D_829139C0[D_8291A7C0.unk_1068].unk_0FC[arg1];
}
#endif

#ifdef VERSION_US
extern void func_8290A920(s32, s32);
extern void func_8290A208(s32);
void func_8290AB10(s32 arg0) {
    s32 i;

    D_8291A7C0.unk_1071 = 0;
    i = 1;
    if (arg0 >= 2) {
        unk_D_8291A7C0_000 *record;
        record = &D_8291A7C0.records[1];
        do {
            func_8290A920(i, i);
            func_8290A208(i);
            record++;
            record[-1].model.unk_002 = record[-1].model.unk_002 | 0x10;
            record[-1].model.unk_001 = record[-1].model.unk_001 & -2;
            record[-1].active = 1;
            i++;
        } while (i != arg0);
    }
}
#endif

#ifdef VERSION_US
extern void func_8290A208(s32);
void func_8290ABB0(s32 arg0, s32 arg1) {
    D_8291A7C0.records[arg0].active = 1;
    func_8290A3C4(arg0, arg1);
    func_8290A208(arg0);
    D_8291A7C0.records[arg0].model.unk_002 |= 0x10;
    D_8291A7C0.unk_1071++;
}
#endif

#ifdef VERSION_US
extern void func_8290A208(s32);
void func_8290AC2C(s32 arg0, s32 arg1) {
    D_8291A7C0.records[arg0].active = 1;
    func_8290A6F4(arg0, arg1);
    func_8290A208(arg0);
    D_8291A7C0.records[arg0].model.unk_002 |= 0x10;
    D_8291A7C0.unk_1071++;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290ACA8.s")
#endif

#ifdef VERSION_US
extern void StageFade_StartFromOpaque(s32);
extern void func_8290E2A8(void);
extern void func_8290A5B0(s32);
// D_8291A960, D_8291AB04, D_8291ACA8 and D_8291AE4C are D_8291A7C0.records[0..3].unk_1A0. Naming
// them separately gives each store its own lui; member access shares one base register.
extern u16 D_8291A960;
extern u16 D_8291AB04;
extern u16 D_8291ACA8;
extern u16 D_8291AE4C;
extern s32 D_8291B858;
extern s32 D_82912F80;
void func_8290ADD0(void) {
    StageFade_StartFromOpaque(8);
    func_8290E2A8();
    func_8290A5B0(4);
    // FAKE: separate symbols for records[0..3].unk_1A0; diff score 830 without them.
    D_8291A960 = 0;
    D_8291AB04 = 0;
    D_8291ACA8 = 0;
    D_8291AE4C = 0;
    *(s32 *)((u8 *)&D_8291B838 + (D_8291B858 * 4)) = D_82912F80;
}
#endif

#ifdef VERSION_US
void func_8290AE3C(void) {
    StageFade_StartFromOpaque(8);
    func_8290E2A8();
    func_8290A5B0(3);
    // FAKE: separate symbols for records[0..3].unk_1A0; diff score 830 without them.
    D_8291A960 = 0;
    D_8291AB04 = 0;
    D_8291ACA8 = 0;
    D_8291AE4C = 0;
    *(s32 *)((u8 *)&D_8291B838 + (D_8291B858 * 4)) = D_82912F80;
}
#endif

#ifdef VERSION_US
extern void func_8290A5B0(s32);
extern s32 D_8291B858;
extern s32 D_82912F80;
void func_8290AEA8(void) {
    StageFade_StartFromOpaque(8);
    func_8290A5B0(2);
    *(s32 *)((u8 *)&D_8291B838 + (D_8291B858 * 4)) = D_82912F80;
}
#endif

#ifdef VERSION_US
extern void StageFade_StartFromOpaque(s32);
extern void func_8290A5B0(s32);
// D_8291A7C0.records[0..3].model.alpha, named separately for the same reason as in func_8290ADD0.
extern u8 D_8291A7E1;
extern u8 D_8291A985;
extern u8 D_8291AB29;
extern u8 D_8291ACCD;
extern s32 D_8291B858;
extern s32 D_82912F80;
void func_8290AEEC(void) {
    StageFade_StartFromOpaque(8);
    func_8290A5B0(4);
    // FAKE: separate symbols for records[0..3].model.alpha; diff score 830 without them.
    D_8291A7E1 = 0;
    D_8291A985 = 0;
    D_8291AB29 = 0;
    D_8291ACCD = 0;
    *(s32 *)((u8 *)&D_8291B838 + (D_8291B858 * 4)) = D_82912F80;
}
#endif

#ifdef VERSION_US
void func_8290AF50(void) {
    s32 i;

    StageFade_StartFromOpaque(8);
    func_8290A5B0(3);

    for (i = 0; i < 3; i++) {
        D_8291A7C0.records[i].model.alpha = 0;
    }

    // func_80001FF0 returns the refresh rate (50 or 60); the start values are (record + 3) times
    // the 24- or 30-frame step that func_8290B478 compares against record 0's unk_1A0 counter.
    if (func_80001FF0() == 50) {
        D_8291A7C0.records[0].unk_1A0 = 72;
        D_8291A7C0.records[1].unk_1A0 = 96;
        D_8291A7C0.records[2].unk_1A0 = 120;
    } else {
        D_8291A7C0.records[0].unk_1A0 = 90;
        D_8291A7C0.records[1].unk_1A0 = 120;
        D_8291A7C0.records[2].unk_1A0 = 150;
    }
    *(s32 *)(&D_8291B838 + D_8291B858 * 4) = D_82912F80;
}
#endif

#ifdef VERSION_US
void func_8290B004(void) {
    s32 i;

    StageFade_StartFromOpaque(8);
    func_8290A5B0(3);
    for (i = 0; i < 3; i++) {
        D_8291A7C0.records[i].model.alpha = 0;
    }
    D_8291A7C0.records[1].active = 0;
    D_8291A7C0.records[2].active = 0;
    D_8291A7C0.records[1].model.unk_001 &= ~1;
    D_8291A7C0.records[2].model.unk_001 &= ~1;
    D_8291A7C0.records[0].unk_1A0 = 0;
    D_8291A7C0.records[1].unk_1A0 = 0;
    D_8291A7C0.records[2].unk_1A0 = 0;
    *(s32 *)(&D_8291B838 + D_8291B858 * 4) = D_82912F80;
}
#endif

#ifdef VERSION_US
extern u8 D_829131EC;
extern u8 D_829131F8;
extern u8 D_82913204;
extern s16 D_8291B874;
extern s16 D_8291B876;
extern s16 D_8291B878;
extern u8 D_8291B838;
extern s32 D_8291B858;
extern s32 D_82912F80;
extern void StageFade_StartFromOpaque(s32);
extern void func_8290A5B0(s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_8290AB10(s32);
void func_8290B098(void) {
    s16 mode;
    u8 *config;

    mode = D_8291A7C0.unk_1068;
    if (mode == 0x24) {
        config = &D_829131EC;
    }
    if (mode == 0x25) {
        config = &D_829131F8;
    }
    if (mode == 0x26) {
        config = &D_82913204;
    }
    StageFade_StartFromOpaque(8);
    func_8290A5B0(1);
    ModelAnim_SetResourceAnimation(D_8291A7C0.records[0].loadContext, &D_8291A7C0.records[0].model, config[0]);
    ModelAnim_SetFrame((u8 *)&D_8291A7C0.records[0].model, config[1]);
    D_8291A7C0.records[0].unk_1A0 = 0;
    func_8290AB10(6);
    *(s16 *)&D_8291B874 = *(s16 *)(config + 4);
    *(s16 *)&D_8291B876 = *(s16 *)(config + 6);
    *(s16 *)&D_8291B878 = *(s16 *)(config + 8);
    *(s32 *)((u8 *)&D_8291B838 + D_8291B858 * 4) = D_82912F80;
}
#endif

#ifdef VERSION_US
extern void StageFade_StartFromOpaque(s32);
extern void func_8290A2FC(void);
extern void func_8290ACA8(void);
extern void func_8290A5B0(s32);
extern s32 D_8291B858;
extern s32 D_82912F80;
void func_8290B184(void) {
    StageFade_StartFromOpaque(8);
    func_8290A2FC();
    func_8290ACA8();
    func_8290A5B0(3);
    D_8291A7C0.records[0].unk_1A0 = 0;
    D_8291A7C0.records[0].model.unk_001 &= 0xFFFE;
    D_8291A7C0.records[1].model.unk_001 &= 0xFFFE;
    D_8291A7C0.records[2].model.unk_001 &= 0xFFFE;
    D_8291A7C0.records[3].model.unk_001 &= 0xFFFE;
    D_8291A7C0.records[0].model.alpha = 0;
    D_8291A7C0.records[1].model.alpha = 0;
    D_8291A7C0.records[2].model.alpha = 0;
    *(s32 *)((u8 *)&D_8291B838 + (D_8291B858 * 4)) = D_82912F80;
}
#endif

#ifdef VERSION_US
extern void func_8290A81C(s32);
void func_8290B220(void) {
    StageFade_StartFromOpaque(8);
    func_8290A81C(3);
    *(s32 *)((u8 *)&D_8291B838 + (D_8291B858 * 4)) = D_82912F80;
}
#endif

#ifdef VERSION_US
extern s16 D_82916E64[];
extern s16 D_8291B87A;
extern unk_D_8291A7C0_000_004 D_8291A388[3];
void func_8290B264(void) {
    s32 frame;
    s32 i;

    func_829092AC();
    if (func_80001FF0() == 60) {
        frame = D_82916E64[D_8291A7C0.unk_1068];
    } else {
        frame = D_82916E64[D_8291A7C0.unk_1068] * 0.83f;
    }
    if (frame == D_8291B862) {
        StageFade_StartFromTransparent(8);
    }
    if (frame + 12 == D_8291B862) {
        D_8291A7C0.unk_106A++;
        D_8291A7C0.unk_1068 = D_82913178[D_8291A7C0.unk_106A];
        func_8290A2FC();
        func_829084E4(((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][15]);
        func_82908640(((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][16]);
        D_8291B87A = 0;
        for (i = 0; i < 3; i++) {
            func_8003F1DC(&D_8291A388[i]);
        }
    }
}
#endif

#ifdef VERSION_US

s32 func_8290B3BC(void) {
    if (D_8291A7C0.unk_1071 == 0xE) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US

s32 func_8290B3E4(void) {
    if (D_8291A7C0.unk_1071 == 0x1A) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_8290B3BC(void);
s32 func_8290B40C(void) {
    if (((u16 (*)[17])D_82913210)[D_8291A7C0.unk_1068][D_8291A7C0.unk_1071] != 0) {
        if (func_8290B3BC() == 0) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern s32 Math_StepToS32(s32, s32, s32, s32);
extern void func_8290B264(void);
void func_8290B478(void) {
    s32 step;
    s32 threshold;
    s32 i;
    unk_D_8291A7C0_000_004 *model;
    unk_D_8291A7C0_000 *actor;

    step = 0x1E;
    if (func_80001FF0() == 0x32) {
        step = 0x18;
    }
    D_8291A7C0.records[0].unk_1A0++;
    for (i = 0; i < 3; i++) {
        threshold = (i + 1) * step;
        if (threshold == D_8291A7C0.records[0].unk_1A0) {
            model = &D_8291A388[i];
            model->unk_001 |= 1;
            actor = &D_8291A7C0.records[i];
            actor->model.unk_001 |= 1;
        }
        if (threshold < D_8291A7C0.records[0].unk_1A0) {
            actor = &D_8291A7C0.records[i];
            actor->model.alpha = Math_StepToS32(actor->model.alpha, 0xFF, 0x28, 0x28);
        }
    }
    func_8290B264();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290B5A4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290B76C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290B934.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290BADC.s")
#endif

#ifdef VERSION_US
extern void ModelAnim_SetFrame(u8 *, s16);
void func_8290BC84(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = *(u16 *)(*(u8 **)(arg0 + 0x44) + 0xA);
    ModelAnim_SetFrame(arg0, (s16)((((arg1 / temp_v0) + 1) * temp_v0) - arg1));
}
#endif

#ifdef VERSION_US
void func_8290BCF0(void) {
    f32 step;
    s32 i;
    u8 *p;

    p = &D_8291A7C0;
    for (i = 0; i < 4; i++) {
        if (*(u8 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x1A2) == 1) {
            if (D_8291B862 == 0) {
                func_8290BC84(p + i * 0x1A4 + 4, 0x2A);
            }
            step = 3.6000001f;
            if (func_80001FF0() == 0x32) {
                if (D_8291B862 < 0x22) {
                    if ((i & 1) == 0) {
                        *(f32 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x16C) -= step;
                    } else {
                        *(f32 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x16C) += step;
                    }
                }
            } else if (D_8291B862 < 0x29) {
                if ((i & 1) == 0) {
                    *(f32 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x16C) -= 3.0f;
                } else {
                    *(f32 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x16C) += 3.0f;
                }
            }
            if (D_8291B862 == 0x29) {
                if (*(s16 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x1E) == 3) {
                    func_8003F2C4(*(s32 *)((u8 *)&D_8291A7C0 + i * 0x1A4), p + i * 0x1A4 + 4, 5);
                } else if (*(s16 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x1E) == 6) {
                    func_8003F2C4(*(s32 *)((u8 *)&D_8291A7C0 + i * 0x1A4), p + i * 0x1A4 + 4, 4);
                } else if (*(s16 *)((u8 *)&D_8291A7C0 + i * 0x1A4 + 0x1E) == 9) {
                    func_8003F2C4(*(s32 *)((u8 *)&D_8291A7C0 + i * 0x1A4), p + i * 0x1A4 + 4, 6);
                } else {
                    func_8003F2C4(*(s32 *)((u8 *)&D_8291A7C0 + i * 0x1A4), p + i * 0x1A4 + 4, 2);
                }
            }
            if (ModelAnim_IsFinished(p + i * 0x1A4 + 4) != 0) {
                ModelAnim_SetFrame(p + i * 0x1A4 + 4, 0);
            }
            func_8290A208(i);
        }
    }
    func_8290B264();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290BEEC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290C0F4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290C2A8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290C45C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290C6D0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290C908.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290CB2C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290CD54.s")
#endif

#ifdef VERSION_US
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern void func_80037120(void *, void *, s16 *, s16 *, s16 *);
extern void func_8290A208(s32);
extern void func_8290B264(void);
void func_8290CFD8(void) {
    f32 sp6C[3];
    s16 pad6A;
    s16 sp68;
    s16 sp66;
    s16 sp64;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (D_8291A7C0.records[i].active == 1) {
            Vec3f_SetComponentsDuplicate(sp6C, D_8291A7C0.records[i].position[0], D_8291A7C0.records[i].position[1], D_8291A7C0.records[i].position[2]);
            func_8290E438(D_8291A7C0.records[i].position, i);
            D_8291A7C0.records[i].unk_1A0++;
            if (D_8291A7C0.records[i].unk_1A0 < 151) {
                func_80037120(sp6C, D_8291A7C0.records[i].position, &sp68, &sp66, &sp64);
                D_8291A7C0.records[i].rotation[1] = sp64;
                func_8290A208(i);
            }
            if (D_8291A7C0.records[i].unk_1A0 == 0) {
                ModelAnim_SetResourceAnimation(D_8291A7C0.records[i].loadContext, &D_8291A7C0.records[i].model, 2);
            }
            D_8291A7C0.records[i].unk_1A0++;
            if (ModelAnim_IsFinished(&D_8291A7C0.records[i].model)) {
                ModelAnim_SetResourceAnimation(D_8291A7C0.records[i].loadContext, &D_8291A7C0.records[i].model, 0);
            }
        }
    }
    func_8290B264();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290D124.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_344D70/func_8290D42C.s")
#endif

#ifdef VERSION_US

void func_8290D72C(void) {
    D_8291B864 = 0;
}
#endif

#ifdef VERSION_US
extern s32 D_8291A380;
extern s16 D_8291B85C;
extern s16 D_8291B85E;
extern s16 D_8291B860;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_045(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 30.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0xBE;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_001(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0x96;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_005(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0x1A00;
    D_8291B860 = 0x5A;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_009(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = -0x1A00;
    D_8291B860 = 0x5A;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_013(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0x8C;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_017(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0x1900;
    D_8291B85E = 0x1900;
    D_8291B860 = 0x82;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_021(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = -0x1700;
    D_8291B85E = -0x1400;
    D_8291B860 = 0x96;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_025(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0x1900;
    D_8291B85E = 0;
    D_8291B860 = 0x8C;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_029(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0x96;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_033(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0xB4;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_037(void) {
    Vec3f_SetComponentsDuplicate((f32 *)(D_8291A380 + 0xB4), 0.0f, 15.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0x78;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
#endif

#ifdef VERSION_US
extern s32 D_8291A380; extern s16 D_8291B85C; extern s16 D_8291B85E; extern s16 D_8291B860; extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32); extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
void BattleAnim_Fragment67Dispatch_041(void) { s16 mode; mode = D_8291A7C0.unk_1068; switch (mode) { case 0x24: Vec3f_SetComponentsDuplicate(D_8291A380 + 0xB4, 0.0f, 30.0f, 0.0f); D_8291B85C = -0x400; D_8291B85E = 0x3A00; D_8291B860 = 0x78; break; case 0x25: Vec3f_SetComponentsDuplicate(D_8291A380 + 0xB4, 0.0f, 30.0f, 0.0f); D_8291B85C = -0x800; D_8291B85E = 0x4500; D_8291B860 = 0x96; break; case 0x26: Vec3f_SetComponentsDuplicate(D_8291A380 + 0xB4, 0.0f, 30.0f, 0.0f); D_8291B85C = -0x400; D_8291B85E = 0x3700; D_8291B860 = 0x96; break; } Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E); }
#endif

#ifdef VERSION_US
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern void Camera_ComputeEyeFromAngles(s32, s32, f32, s16, s32);
extern s32 D_8291A380;
extern s16 D_8291B85C;
extern s16 D_8291B85E;
extern s16 D_8291B860;
void func_8290DED4(void) {
    Vec3f_SetComponentsDuplicate(D_8291A380 + 0xB4, 0.0f, 0.0f, 0.0f);
    D_8291B85C = 0;
    D_8291B85E = 0;
    D_8291B860 = 0x10E;
    Camera_ComputeEyeFromAngles(D_8291A380 + 0xB4, D_8291A380 + 0xA8, (f32)D_8291B860, D_8291B85C, (s32)D_8291B85E);
}
void func_8290DED4_padding(void) {}
#endif

#ifdef VERSION_US
extern s32 D_8291B870;
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern u8 D_80094E38[];
extern u8 D_800D0510;
extern s16 D_8291B874;
extern s16 D_8291B876;
void func_8290DF6C(void) {
    do {
        if (((D_8291A7C0.unk_1068 == 0x24) || (D_8291A7C0.unk_1068 == 0x25)) || (D_8291A7C0.unk_1068 == 0x26)) {
            if (D_8291B87A != 0) {
                D_8291B870 = func_8004C990(0xC1, 0);
                gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
                func_8004D19C(D_8291B874, D_8291B876, D_8291B870, 0, 0);
            }
        }
    } while (0);
}
#endif

#ifdef VERSION_US
extern void func_8290DF6C(void);
extern void func_8290954C(void);
void func_8290E014(void) {
    func_8290DF6C();
    func_8290954C();
}
#endif
