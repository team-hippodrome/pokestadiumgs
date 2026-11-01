#include "global.h"


#ifdef VERSION_US
extern void func_8004C8C0(s32);
void func_87F061D0(void) {
    func_8004C8C0(429);
}

extern Gfx *D_800D0510;
extern Gfx D_80094E78[];
void func_87F061F0(void) {
    gSPDisplayList(D_800D0510++, D_80094E78);
    gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                     PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
}

/* mkdraft:func_87F06240 begin */
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern s32 func_8004C990(s32 arg0, s32 arg1);
extern s32 func_8004D1FC(u8 *arg0);

extern s32 D_87F10CD0[];

// FAKE: the C body below reproduces the retail instruction stream exactly except
// for one as1 schedule tie at +0xD4: retail issues the scaleY reload
// (`lwc1 $f4,0x5C(sp)`) before the -0.5f constant (`lui $at,0xBF000000`), and
// IDO 7.1 emits those two words the other way round for every statement order
// tried. *Without this pragma the diff score is 60* (that single swapped pair).
#pragma SWAP_FUNCTION_WORDS(func_87F06240, 0xD4, 0x3C01BF00, 0xC7A4005C)



void func_87F06240(s16 arg0, s16 arg1, f32 arg2, f32 arg3, s32 arg4) {
    s32 sp4C;
    s32 pad[3];
    f32 sp3C;
    f32 temp_fa1;
    f32 temp_ft2;
    f32 sp34;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 var_fa0;
    f32 var_ft4;
    f32 var_fv1;
    s32 temp_v0;
    arg4 %= 10;
    temp_v0 = func_8004C990(0x1AD, D_87F10CD0[arg4]);
    sp4C = temp_v0;
    func_8004D1FC((u8 *) temp_v0);
    temp_ft5 = ((f32) (u32) (*(u16 *) (sp4C + 0))) * arg2;
    if (temp_ft5 > 0.0f) {
        sp3C = 0.5f;
    } else {
        sp3C = -0.5f;
    }
    temp_ft2 = ((f32) (u32) (*(u16 *) (sp4C + 2))) * arg3;
    sp34 = temp_ft2;
    if (temp_ft2 > 0.0f) {
        var_fa0 = 0.5f;
    } else {
        var_fa0 = -0.5f;
    }
    temp_fa1 = 1024.0f / arg2;
    if (temp_fa1 > 0.0f) {
        var_ft4 = 0.5f;
    } else {
        var_ft4 = -0.5f;
    }
    temp_fv0 = 1024.0f / arg3;
    if (temp_fv0 > 0.0f) {
        var_fv1 = 0.5f;
    } else {
        var_fv1 = -0.5f;
    }
    GfxRect_DrawTextured(arg0, arg1, (s16) (s32) (sp3C + temp_ft5), (s16) (s32) (var_fa0 + sp34), 0, 0, (s16) (s32) (var_ft4 + temp_fa1), (s16) (s32) (var_fv1 + temp_fv0), 0);
}
/* mkdraft:func_87F06240 end */
#endif
