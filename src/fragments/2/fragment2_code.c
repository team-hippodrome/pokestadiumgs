#include "global.h"
typedef struct Fragment2Model {
    /* 0x000 */ u8 unk_000[0x14];
    /* 0x014 */ s32 index;
    /* 0x018 */ u8 unk_018[0xC];
    /* 0x024 */ f32 x;
    /* 0x028 */ f32 y;
    /* 0x02C */ u8 unk_02C[4];
    /* 0x030 */ f32 unk_030;
    /* 0x034 */ f32 unk_034;
    /* 0x038 */ f32 unk_038;
    /* 0x03C */ u8 unk_03C[0x168 - 0x3C];
} Fragment2Model; // size = 0x168

typedef struct Fragment2State {
    /* 0x000 */ s32 active[4];
    /* 0x010 */ f32 scale;
    /* 0x014 */ s16 unk_014;
    /* 0x016 */ u8 unk_016[6];
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ Fragment2Model models[4];
} Fragment2State;
extern Fragment2State D_81900820;


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/2/fragment2_code/func_81900020.s")

extern s32 D_81900718;
void func_81900154(void) {
    D_81900718 = 1;
}

extern void func_8003F114(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_81900164(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    Fragment2Model *model;

    D_81900820.scale = arg3;
    D_81900820.active[arg4] = 1;
    D_81900820.unk_014 = 0;
    model = &D_81900820.models[arg4];
    func_8003F114(model, 0, -1, D_81900820.unk_01C);
    D_81900820.models[arg4].unk_038 = 0.0f;
    D_81900820.models[arg4].unk_034 = 0.0f;
    D_81900820.models[arg4].unk_030 = 0.0f;
    D_81900820.models[arg4].x = arg1;
    D_81900820.models[arg4].y = arg2;
    D_81900820.models[arg4].index = arg4;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/2/fragment2_code/func_81900214.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/2/fragment2_code/func_8190037C.s")

/* mkdraft:func_81900500 begin */
// Partial view of the active scene object at D_8009491C: only the field this
// function reads is typed.
typedef struct Fragment2SceneObject {
    /* 0x00 */ u8 unk_00[0x14];
    /* 0x14 */ s32 colorIndex;
} Fragment2SceneObject;

// Row of D_81900784. Each channel is stored as its own word (the accesses are
// lw, not lbu) and gDPSetPrimColor/gDPSetEnvColor keep only its low 8 bits.
// The env color reuses primAlpha because the table has no separate env alpha.
typedef struct Fragment2Color {
    /* 0x00 */ s32 primRed;
    /* 0x04 */ s32 primGreen;
    /* 0x08 */ s32 primBlue;
    /* 0x0C */ s32 primAlpha;
    /* 0x10 */ s32 envRed;
    /* 0x14 */ s32 envGreen;
    /* 0x18 */ s32 envBlue;
} Fragment2Color;

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern Fragment2Color D_81900784[];
extern s32 D_81900838;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);



void func_81900500(s32 arg0, s32 arg1) {
    s32 pad; // FAKE: unused stack slot the retail frame reserves (score 16 without it)
    Fragment2SceneObject *sceneObject;
    s32 asset;

    if (arg0 == 5) {
        sceneObject = D_8009491C;
        asset = func_8004C990(0x1B1, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetPrimColor(D_800D0510++, 0, 0,
                        D_81900784[sceneObject->colorIndex].primRed,
                        D_81900784[sceneObject->colorIndex].primGreen,
                        D_81900784[sceneObject->colorIndex].primBlue,
                        D_81900784[sceneObject->colorIndex].primAlpha);
        gDPSetEnvColor(D_800D0510++,
                       D_81900784[sceneObject->colorIndex].envRed,
                       D_81900784[sceneObject->colorIndex].envGreen,
                       D_81900784[sceneObject->colorIndex].envBlue,
                       D_81900784[sceneObject->colorIndex].primAlpha);
        gDPSetCombine(D_800D0510++, 0x30B3FF, 0x5FFEFE38);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)asset));
        gSPDisplayList(D_800D0510++, D_81900838);
        func_8003CD84();
    }
}
/* mkdraft:func_81900500 end */

extern void func_8003F1DC(void *);
extern s16 D_81900834;
extern s32 D_81900840;
extern s32 D_81900DE0;
void func_819006A0(void *arg0)
{
    u8 *var_s0;
    u8 *var_s1;
    // FAKE: the one-line layout below is load-bearing. as1 breaks prologue
    // scheduling ties by .loc line number; splitting the two initializations
    // and the loop head onto separate lines swaps the lui/addiu order of the
    // s0/s1/s2 address materialization.
    var_s1 = (u8 *) &D_81900820; var_s0 = (u8 *) &D_81900840; do { func_8003F1DC(var_s0);
        var_s0 += 360;
        var_s1 += 4;
        *((s32 *) (var_s1 - 4)) = 0;
    }
    while (var_s0 != ((u8 *) &D_81900DE0));
    D_81900834 = 0;
}
#endif
