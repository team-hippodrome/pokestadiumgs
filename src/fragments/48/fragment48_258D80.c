#include "global.h"


#ifdef VERSION_US
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
s32 func_87C02D80(s32 arg0, void *camera) {
    if (arg0 != 2) {
        return 0;
    }
    func_80038E14(camera, 0, 7000.0f, 5600.0f, 0.0f, 0.0f, 0.0f, 0);
    GeoCamera_SetPerspective(camera, 45.0f, 64.0f, 32768.0f);
    return 1;
}

extern void func_87C02488(void *arg0, s32 arg1, void *arg2);
void func_87C02DF0(u8 *arg0, s32 arg1, void *arg2, f32 arg3) {
    func_87C02488(arg0 + 0x2D0, arg1, arg2);
    *(f32 *)(arg0 + 0x388) = arg3;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258D80/func_87C02E24.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258D80/func_87C02F74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258D80/func_87C02FEC.s")

extern Gfx *D_800D0510;
extern Gfx D_87C03CD0[];
//!bug Declared s32 but never returns a value; the register allocation (display-list pointer
// in v0) only matches with a non-void return type, diff score 20 as void.
s32 func_87C03178(s32 arg0, u8 *arg1) {
    if (arg0 == 2) {
        arg1[0x1D] = 100;
        gSPDisplayList(D_800D0510++, D_87C03CD0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258D80/func_87C031B8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258D80/func_87C03370.s")

extern void Geo_RenderRootNode(s32); void WidgetTree_OpenMessagePanel_fragment48(u8 *arg0) { Geo_RenderRootNode(*(s32 *)(arg0 + 0)); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258D80/func_87C03574.s")

s32 func_87C0379C(u8 *arg0) {
    return *(s32 *)(arg0 + 0x548);
}
#endif
