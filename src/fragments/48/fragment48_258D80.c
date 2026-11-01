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

/* mkdraft:func_87C02E24 begin */
extern void func_8003F03C(s32 arg0, void *arg1);
extern void func_8003F1DC(void *arg0);
extern void func_8003F114(u8 *arg0, s16 arg1, s16 arg2, void *arg3);
extern void func_87C02D1C(u8 *arg0, u8 *arg1);




void func_87C02E24(u8 *arg0, void *arg1, void *arg2, void *arg3) {
    f32 scale;
    s32 i;
    s32 offset;
    u8 *model;
    u8 *target;

    scale = *(f32 *)(arg0 + 0x388) / 250.0f;
    func_8003F03C((s32)arg0, arg2);
    func_8003F03C((s32)(arg0 + 0x168), arg1);
    i = 0;
    model = arg0;
    offset = 0;
    do {
        func_8003F1DC(model);
        func_8003F114(model, 0, -1, arg3);
        *(f32 *)(model + 0x30) = scale;
        *(f32 *)(model + 0x34) = scale;
        *(f32 *)(model + 0x38) = scale;
        func_87C02D1C(arg0 + 0x2D0, arg0 + 0x60 + offset);
        model += 0x168;
        switch (i) {
        case 1:
            target = (u8 *)arg0 + i * 0x168;
            *(f32 *)(target + 0x64) = *(f32 *)(target + 0x64) * -1.0f;
            *(f32 *)(target + 0x74) = *(f32 *)(target + 0x74) * -1.0f;
            *(f32 *)(target + 0x84) = *(f32 *)(target + 0x84) * -1.0f;
            *(f32 *)(target + 0x94) = *(f32 *)(target + 0x94) * -1.0f;
            break;
        }
        i++;
        offset += 0x168;
    } while (i != 2);
}
/* mkdraft:func_87C02E24 end */

extern void *func_87C008B0(void *arg0);
extern void func_87C010AC(void *arg0, void *arg1, void *arg2);
extern u8 D_87C03E00[];
void func_87C02F74(u8 *arg0, s32 mode) {
    if (mode == 1) {
        func_87C008B0(arg0 + 0x308);
    } else if (mode >= 2 && mode < 7) {
        func_87C010AC(arg0 + 0x308, D_87C03E00 + mode * 24 - 24, D_87C03E00);
    }
}

void func_87C02F74_padding(void) {
}

/* mkdraft:func_87C02FEC begin */
extern f64 D_87C03ED8[];
extern u8 D_87C04088[];
extern void *func_87C00120(void *arg0, f64 arg1, f64 arg2, f64 arg3);
extern void *func_87C002A8(void *arg0, void *arg1, f64 arg2);
extern void func_87C021FC(void *arg0, void *arg1, void *arg2, f64 arg4, f64 arg6, f64 arg8);


void func_87C02FEC(void *arg0, void *arg1, f64 arg2) {
    typedef struct {
        u8 pad[0x388];
        f32 scale;
    } ScaleSource;

    s32 i;
    s32 j;
    s32 k;
    f64 *p;
    f64 matrix[3];

    // IDO 7.1 materialises the sentinel address D_87C04088 before D_87C03ED8 only while
    // `do` shares this source line with the assignment. With `do` on its own line the two
    // %lo addiu instructions swap and the object differs by two instructions (diff score 30).
    p = D_87C03ED8; do {
        func_87C002A8(matrix, p, (f64)((ScaleSource *)arg0)->scale);
        func_87C021FC((u8 *)arg0 + 0x2D0, matrix, arg1,
                      *(f64 *)((u8 *)arg1 + 0x20), *(f64 *)((u8 *)arg1 + 0x28), arg2);
        p += 3;
    } while (p != (f64 *)D_87C04088);

    // Scale a unit rotation by +-scale in each axis and apply it at arg0 + 0x2D0.
    for (k = -1; k != 3; k += 2) {
        for (j = -1; j != 3; j += 2) {
            for (i = -1; i != 3; i += 2) {
                f64 vec[3];
                func_87C00120(vec, (f32)k * ((ScaleSource *)arg0)->scale, (f32)j * ((ScaleSource *)arg0)->scale, (f32)i * ((ScaleSource *)arg0)->scale);
                func_87C021FC((u8 *)arg0 + 0x2D0, vec, arg1,
                              *(f64 *)((u8 *)arg1 + 0x20), *(f64 *)((u8 *)arg1 + 0x28), arg2);
            }
        }
    }
}
/* mkdraft:func_87C02FEC end */

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
