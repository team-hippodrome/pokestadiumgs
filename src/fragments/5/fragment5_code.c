#include "global.h"
#include "controller.h"


void func_83200020(void) {
}

#ifdef VERSION_US
extern void func_81600F0C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_818057D0(void *arg0, void *arg1, void *arg2);
void func_83200028(void *arg0, void *arg1, void *arg2) {
    func_81600F0C(*(void **)((u8 *)arg1 + 0x38), 0, 0, 0x280, 0x1E0);
    func_818057D0(arg0, arg1, arg2);
}
#endif

#ifdef VERSION_US

/* mkdraft:func_83200078 begin */
extern Gfx *D_800D0510;
extern void *Gfx_AllocDisplayList(s32 arg0);
extern s32 func_8004CA10(void *arg0);
extern s32 func_8004CA24(void *arg0);
extern s32 func_8004D1FC(void *arg0);
extern void func_81801810(u8 *arg0, s32 arg1, s32 arg2);
extern void func_8180189C(u8 *arg0, void *arg1, f32 arg2);
extern void Gfx_SetVertexAttributes(Vtx *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9);



void func_83200078(void *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4) {
    Vtx *vertices;
    s32 i;
    s32 height;
    s32 width;
    s16 corners[4][2];

    vertices = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    height = func_8004CA24(arg0);
    width = func_8004CA10(arg0);
    func_81801810((u8 *)&corners[0], (s32)(-width * 0.5), -height);
    func_81801810((u8 *)&corners[1], (s32)(width * 0.5), -height);
    func_81801810((u8 *)&corners[2], (s32)(-width * 0.5), 0);
    func_81801810((u8 *)&corners[3], (s32)(width * 0.5), 0);

    for (i = 0; i < 4; i++) {
        func_8180189C((u8 *)&corners[i], &corners[i], arg3);
        corners[i][0] += arg1;
        corners[i][1] += arg2;
    }

    Gfx_SetVertexAttributes(&vertices[0], corners[0][0], corners[0][1], -1, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&vertices[1], corners[1][0], corners[1][1], -1, width << 5, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&vertices[2], corners[2][0], corners[2][1], -1, 0, height << 5, 0xFF, 0xFF, 0xFF, 0xFF);
    Gfx_SetVertexAttributes(&vertices[3], corners[3][0], corners[3][1], -1, width << 5, height << 5, 0xFF, 0xFF,
                            0xFF, 0xFF);

    gDPPipeSync(D_800D0510++);
    gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    func_8004D1FC(arg0);
    gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
    if (arg4 != 0) {
        gDPSetPrimColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPSetEnvColor(D_800D0510++, 0x0F, 0x17, 0x64, 0x00);
    } else {
        gDPSetPrimColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPSetEnvColor(D_800D0510++, 0x00, 0x00, 0x00, 0x00);
    }
    gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombineMode(D_800D0510++, G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA);
    gDPSetRenderMode(D_800D0510++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPVertex(D_800D0510++, (u32)vertices & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(D_800D0510++, 0, 2, 3, 0, 0, 3, 1, 0);
}
/* mkdraft:func_83200078 end */
#endif

#ifdef VERSION_US
/* mkdraft:func_83200484 begin */
extern void WidgetResources_DrawRecords(s32 arg0, s32 arg1, s32 arg2);
extern u8 *WidgetTexture_GetDescriptor(void *arg0);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern void func_818055E0(void *arg0, void *arg1);
extern Gfx *D_800D0510;

extern void func_83200078(void *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4);
extern f32 D_83200DA4;
extern f32 D_83200DA8;
extern f32 D_83200DAC;

typedef struct {
    s16 unk0;
    s16 unk2;
} WidgetTextureRef;

typedef struct {
    WidgetTextureRef refs[3];
} WidgetTextureRefList;

extern WidgetTextureRefList D_83200CF8;



void func_83200484(void *arg0, u8 *arg1, void *arg2) {
    WidgetTextureRefList refs = D_83200CF8;
    s32 pad[2]; // FAKE: unused; allocates the 0x50-byte frame with refs at sp+0x44 as in the target. Score without it: 54.

    func_818055E0(arg0, arg1);
    func_83200078(WidgetTexture_GetDescriptor(&refs.refs[0]), *(s16 *)((u8 *)arg2 + 0) + 0x48, *(s16 *)((u8 *)arg2 + 2) + 0x34, ((((f32)*(u8 *)(arg1 + 0x43) / 60.0f) + (f32)*(u8 *)(arg1 + 0x42)) / 12.0f) * D_83200DA4, 1);
    func_83200078(WidgetTexture_GetDescriptor(&refs.refs[1]), *(s16 *)((u8 *)arg2 + 0) + 0x48, *(s16 *)((u8 *)arg2 + 2) + 0x34, ((((f32)*(u8 *)(arg1 + 0x44) / 60.0f) + (f32)*(u8 *)(arg1 + 0x43)) / 60.0f) * D_83200DA8, 1);
    func_83200078(WidgetTexture_GetDescriptor(&refs.refs[2]), *(s16 *)((u8 *)arg2 + 0) + 0x48, *(s16 *)((u8 *)arg2 + 2) + 0x34, ((f32)*(u8 *)(arg1 + 0x44) / 60.0f) * D_83200DAC, 0);
    WidgetResources_DrawRecords((s32)arg0, (s32)arg1, (s32)arg2);
    func_800498C4();
    func_800496A4(4, 0);
    gDPSetCombine(D_800D0510++, 0xFC30FE61, 0x55FEF379);
    gDPSetPrimColor(D_800D0510++, 0xFF, 0xFF, 0x6E, 0x6E, 0x6E, 0xFF);
    gDPSetEnvColor(D_800D0510++, 0xBE, 0xBE, 0xD2, 0);
    func_800495F8(*(s16 *)((u8 *)arg2 + 0) + 0x49, *(s16 *)((u8 *)arg2 + 2) + 0x6F, 1, func_8004C874(0x3D, (*(u16 *)(arg1 + 0x40) % 7) + 0xB));
    func_800499EC();
}
/* mkdraft:func_83200484 end */
#endif

#ifdef VERSION_US
extern void _bzero(void *ptr, s32 size);
extern u8 D_83200D38[];
extern void func_81804954(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4);
extern void WidgetTree_OpenMessagePanel_fragment4(void *arg0);
extern void *func_8004D690(s32 arg0);
typedef struct {
    u8 pad00[0x1E];
    u8 active;
    u8 pad1F[0x19];
    void *resource0;
    void *resource1;
    u16 value;
    u8 width;
    u8 height;
    u8 flags;
} Frag5Resource;
void func_83200744(Frag5Resource *arg0, s32 arg1) {
    _bzero(arg0, 0x48);
    func_81804954(arg0, 0, 2, D_83200D38, arg1);
    WidgetTree_OpenMessagePanel_fragment4(arg0);
    arg0->active = 1;
    arg0->resource0 = func_8004D690(0x18);
    arg0->resource1 = func_8004D690(0x2D);
    arg0->value = 0;
    arg0->width = 9;
    arg0->height = 0x1E;
    arg0->flags = 0;
}
#endif

#ifdef VERSION_US
extern void func_80064D28(void);
extern void StageFade_StartFromOpaque(s32);
extern s32 StageContext_GetFadeMode();
extern void func_81804FD0(u8 *);
extern s32 func_81804A20(u8 *);
extern void func_800225C4(s32);
extern void StageFade_StartFromTransparent(s32);
extern u8 D_83200DB0[];
s32 func_832007D4(s32 arg0) {
    func_80064D28();
    switch (arg0) {
    case 0:
        StageFade_StartFromOpaque(5);
        break;
    case 1:
        if (StageContext_GetFadeMode() == 0) {
            return 2;
        }
        break;
    case 2:
        func_81804FD0(D_83200DB0);
        if (((func_81804A20(D_83200DB0) != 0) &&
             ((D_80087200->buttonsPressed & 0x1000) != 0)) ||
            ((D_83200DB0[0x1D] == 0) &&
             (D_83200DB0[0x1C] == 0) &&
             (D_83200DB0[0x1E] == 0))) {
            arg0 = 4;
            func_800225C4(5);
            StageFade_StartFromTransparent(5);
        }
        break;
    case 3:
        if (StageContext_GetFadeMode() == 1) {
            return 4;
        }
        break;
    default:
        break;
    }
    return arg0;
}
#endif

#ifdef VERSION_US
extern u8 D_83200DB0[];
extern void BgStage_DrawFrame(void);
extern void func_818017A8(void);
extern void func_81805308(void *);
extern void func_80008648(void);
void func_832008F0(s32 arg0) {
    BgStage_DrawFrame();
    func_818017A8();
    func_81805308(D_83200DB0);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern s32 func_832007D4(s32 arg0);
extern void func_832008F0(s32 arg0);
void func_8320092C(s32 arg0, s32 arg1) {
    s32 state = 0;
    while (state != 4) {
        state = func_832007D4(state);
        func_832008F0(state);
    }
}
#endif

#ifdef VERSION_US
extern void Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_8004C4B0(s32);
extern void func_8004C8C0(s32);
extern s32 func_80047588(s32, s32);
extern void func_8004C54C(s32, s32);
extern void func_80008514(s32);
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_81801794(void);
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern u8 D_83200D88[];
extern u8 D_83200D90[];
extern s32 D_83200DF8;
void func_8320097C(s32 arg0, s32 arg1) {
    s32 sp24;

    Asset_LoadToSegment((s32) ((u32) ((s32) D_1000000 & 0x0F000000) >> 0x18), &D_446E30, D_447D00, 0);
    D_83200DF8 = 0;
    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(0x10F);
    func_8004C4B0(0x3D);
    func_8004C4B0(0x3C);
    func_8004C8C0(0x151);
    func_80047588(0x1C, 0);
    func_83200744((Frag5Resource *) D_83200DB0, D_83200DF8);
    func_8004C54C(0x15, (s32) &D_83200D88);
    func_8004C54C(0x46, (s32) &D_83200D90);
    func_80008514(sp24);
    func_800086A4(2);
    StageFade_StartFromOpaque(1);
    func_81801794();
}
#endif

#ifdef VERSION_US
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
void func_83200A84(s32 arg0, s32 arg1) {
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
}
#endif

#ifdef VERSION_US
extern void main_pool_push_state(s32 arg0);
extern void main_pool_pop_state(s32 arg0);
extern void func_8320097C();
extern void func_8320092C();
extern void func_83200A84(s32 arg0, s32 arg1);
s32 fragment5_main(s32 arg0, s32 arg1) {
    main_pool_push_state(0x57445052);
    func_8320097C(arg0, arg1);
    func_8320092C(arg0, arg1);
    func_83200A84(arg0, arg1);
    main_pool_pop_state(0x57445052);
    return 0;
}
#endif
