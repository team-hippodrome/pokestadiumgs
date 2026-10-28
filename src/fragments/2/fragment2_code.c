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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/2/fragment2_code/func_81900500.s")

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
