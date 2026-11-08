#include "global.h"


#ifdef VERSION_US
extern void *D_87E1EB90;
s32 func_87E05400(u32 arg0) {
    s32 var_v1;
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(D_87E1EB90) + (0x158)));
    var_v1 = (*(s32 *)((u8 *)(temp_v0) + (0x98))) == 0;
    if ((arg0 >= 2U) && (var_v1 == 0) && ((u32) (*(u32 *)((u8 *)(temp_v0) + (0x80))) >= (u32) ((u32) (*(u32 *)((u8 *)(temp_v0) + (0x84))) / arg0))) {
        var_v1 = 1;
    }
    return var_v1;
}

/* mkdraft:func_87E05458 begin */
extern void func_87F0B1A4(s32, void *, f32, f32, f32, s32, s32);
typedef struct { f32 x, y, z; } Func87E05458Vec3;

// Positions the camera's view node once per new camera object. When the
// state has no current camera (its word at 0x8 is null), the node at
// state + 0x4 receives the camera's position (0x48..0x50) with x shifted
// by -10.0 and y by 28.0. Whenever the camera object changes, the state
// records it and func_87F0B1A4 starts an interpolation toward that shifted
// position with priority 7. Finally the byte at 0x25 of both the view node
// and the object at state + 0xA0 has bit 0 set or cleared depending on
// whether the state's word at 0x174 equals 1.


void func_87E05458(void *arg0) {
    u8 *root;

    root = *(u8 **)((u8 *)D_87E1EB90 + 0x158);
    if (*(u8 **)(root + 8) == NULL) {
        *(Func87E05458Vec3 *)(*(u8 **)(root + 4) + 0x48) = *(Func87E05458Vec3 *)((u8 *)arg0 + 0x48);
        *(f32 *)(*(u8 **)(root + 4) + 0x48) += -10.0f;
        *(f32 *)(*(u8 **)(root + 4) + 0x4C) += 28.0f;
    }
    if (*(u8 **)(root + 8) != arg0) {
        *(u8 **)(root + 8) = arg0;
        func_87F0B1A4((s32)(root + 0x14),
                      *(u8 **)(root + 4) + 0x48,
                      *(f32 *)((u8 *)arg0 + 0x48) + -10.0f,
                      *(f32 *)((u8 *)arg0 + 0x4C) + 28.0f,
                      *(f32 *)((u8 *)arg0 + 0x50),
                      7, 0);
    }
    if (*(s32 *)((u8 *)D_87E1EB90 + 0x174) == 1) {
        *(u8 *)(*(u8 **)(*(u8 **)((u8 *)D_87E1EB90 + 0x158) + 4) + 0x25) |= 1;
        *(u8 *)(*(u8 **)(*(u8 **)((u8 *)D_87E1EB90 + 0x158) + 0xA0) + 0x25) |= 1;
    } else {
        *(u8 *)(*(u8 **)(*(u8 **)((u8 *)D_87E1EB90 + 0x158) + 4) + 0x25) &= ~1;
        *(u8 *)(*(u8 **)(*(u8 **)((u8 *)D_87E1EB90 + 0x158) + 0xA0) + 0x25) &= ~1;
    }
}
/* mkdraft:func_87E05458 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_308D70/func_87E055B0.s")

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState();
void func_87E05874(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;

    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60(*(u8 **)((u8 *)temp_v0 + 0xC)));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_v0 + 0x10));
        GeoRender_ApplyMaterialState();
    }
}

extern void func_87F0B4AC(void *, f32 *, f32 *, s16 *);
extern void *D_87E1EB90;
extern void *D_87F119DC;

void func_87E05944(void) {
    s32 temp_t0;
    s32 var_a0;
    u8 *var_v1;

    temp_t0 = *(s32 *)((u8 *)D_87F119DC + 0x20);
    var_v1 = (u8 *)temp_t0 + 0x90;
    for (var_a0 = 0; var_a0 != 0xC; var_a0 += 1, var_v1 += 8) {
        if (var_a0 == *(s32 *)((u8 *)D_87E1EB90 + 8)) {
            if (*(u8 *)(var_v1 + 4) >= 0xE7) {
                *(u8 *)(var_v1 + 4) = 0xFF;
            } else {
                *(u8 *)(var_v1 + 4) = *(u8 *)(var_v1 + 4) + 0x19;
            }
        } else {
            if (*(u8 *)(var_v1 + 4) < 0x19) {
                *(u8 *)(var_v1 + 4) = 0;
            } else {
                *(u8 *)(var_v1 + 4) = *(u8 *)(var_v1 + 4) - 0x19;
            }
        }
    }
    func_87F0B4AC((u8 *)temp_t0 + 8, (f32 *)((u8 *)D_87F119DC + 0x48),
                  (f32 *)((u8 *)D_87F119DC + 0x54), (s16 *)((u8 *)D_87F119DC + 0x42));
}
extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void GeoRender_ApplyMaterialState();
void func_87E059F4(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;
    void *temp_a0;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        temp_a0 = *(void **)((u8 *)temp_v0 + 0x20);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF,
                   *(void **)((u8 *)(*(void **)((u8 *)temp_a0 + 4)) + 8));
        gSPDisplayList(D_800D0510++, *(void **)temp_a0);
        GeoRender_ApplyMaterialState(temp_a0);
    }
}

/* mkdraft:func_87E05AB0 begin */
extern void func_87E05458();
extern void func_87F0B0FC(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
extern void func_87F0B154();


void func_87E05AB0(void) {
    struct Position { f32 x; f32 y; f32 z; };
    u8 *object;
    struct Position saved_position;
    u8 alpha;

    object = *(u8 **)((u8 *)D_87F119DC + 0x20);
    func_87F0B4AC(object, (f32 *)((u8 *)D_87F119DC + 0x48), (f32 *)((u8 *)D_87F119DC + 0x54), (s16 *)((u8 *)D_87F119DC + 0x42));
    if (*(s32 *)((u8 *)D_87E1EB90 + 8) == *(s8 *)(object + 0x98)) {
        if (*(u8 *)((u8 *)D_87F119DC + 0x60) < 230) {
            *(u8 *)((u8 *)D_87F119DC + 0x60) += 25;
        } else {
            *(u8 *)((u8 *)D_87F119DC + 0x60) = 255;
        }
        func_87F0B0FC(object, 0, 15.0f, 5.0f, 6);
        saved_position = *(struct Position *)((u8 *)D_87F119DC + 0x48);
        (*(f32 *)((u8 *)D_87F119DC + 0x50)) += 15.0f;
        func_87E05458(D_87F119DC);
        *(struct Position *)((u8 *)D_87F119DC + 0x48) = saved_position;
    } else {
        *(u8 *)((u8 *)D_87F119DC + 0x60) -= 25;
        if (*(u8 *)((u8 *)D_87F119DC + 0x60) < 200) {
            *(u8 *)((u8 *)D_87F119DC + 0x60) = 200;
        }
        func_87F0B154();
    }
    alpha = *(u8 *)((u8 *)D_87F119DC + 0x60);
    *(u8 *)((u8 *)D_87F119DC + 0x62) = alpha;
    *(u8 *)((u8 *)D_87F119DC + 0x61) = alpha;
}
/* mkdraft:func_87E05AB0 end */

/* mkdraft:func_87E05BF0 begin */
extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void func_8003CD84(void);
typedef struct { u8 pad_60[0x60]; u8 red; u8 green; u8 blue; } Func87E0375CColor;

void func_87E05BF0(s32 arg0, s32 arg1) {
    u8 *context;
    Func87E0375CColor *temp_a0;
    void *temp_a1;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_a0 = *(Func87E0375CColor **)(context + 0x14);
        temp_a1 = *(void **)((u8 *)temp_a0 + 0x20);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0x50FFFF, -0xDC8);
        gDPSetEnvColor(D_800D0510++, temp_a0->red, temp_a0->green,
                       temp_a0->blue, 0xFF);
        gSPSegment(D_800D0510++, 0xF,
                   *(void **)((u8 *)(*(void **)((u8 *)temp_a1 + 0x90)) + 8));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_a1 + 0x8C));
        func_8003CD84();
    }}
/* mkdraft:func_87E05BF0 end */

typedef union { s32 word; s8 bytes[4]; } Func80041FA0State;
extern Func80041FA0State D_87E1A174;
extern void func_80041FA0(s32, u16, Func80041FA0State);
extern void func_800428F8(s32);
extern void func_8003F114(void *, s32, s32, s32);
extern void ModelAnim_SetResourceAnimation(s32, s32, s32);
extern void func_8003F3BC(s32, s32);
void func_87E05CE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Func80041FA0State temp_a2 = D_87E1A174;
    func_80041FA0(arg0, (u16)arg1, temp_a2);
    func_800428F8(arg0);
    func_8003F114((void *)arg2, 0, 0, *(s32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 8)));
    ModelAnim_SetResourceAnimation(arg0, arg2, arg3);
    func_8003F3BC(arg2, arg4);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_308D70/func_87E05D74.s")

extern void func_87F0252C(u8 *, s32, s32, s32);
extern u8 D_80126420;
void func_87F024CC(void);
extern u8 D_87E1B9C0;
s32 main_pool_alloc(s32 arg0, s32 arg1);
extern u8 D_87E1B9D8;
void func_87F024CC(void);
s32 main_pool_alloc(s32 arg0, s32 arg1);
void func_87E06068(s32 arg0) {
    func_87F024CC();
    func_87F0252C(&D_87E1B9C0, arg0 + 0x18, main_pool_alloc(0x141C, 0), 0xD);
    func_87F0252C(&D_80126420, arg0 + 0x2C, main_pool_alloc(0x318, 0), 2);
    func_87F0252C(&D_87E1B9D8, arg0 + 0x40, main_pool_alloc(0x318, 0), 2);
}

extern void func_87E055B0(void);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern void *func_87F025B8(void *, void *);
extern void func_87F0AFD0(void *, void *, void *, void *);
extern s32 func_8004C990(s32, s32);
extern f32 D_87E1B570;



void func_87E06100(void *arg0) {
    f32 temp_fs0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 temp_a1;
    s32 var_s3;
    s32 var_s5;
    void *temp_s1;
    u8 *temp_s2;
    u8 *temp_v0;
    void *temp_v0_3;
    void *var_s6;

    var_s6 = NULL;
    for (var_s3 = 0, var_s5 = 0, temp_fs0 = D_87E1B570; var_s3 != 2; var_s3++, var_s5 += 0x9C) {
        temp_s2 = *(u8 **)((u8 *)arg0 + 0x158) + var_s5;
        temp_v0 = func_87F025B8((u8 *)arg0 + 0x40, (void *)func_87E055B0);
        if (temp_v0 != NULL) {
            temp_s1 = temp_v0 + 0x24;
            *(void **)((u8 *)arg0 + 0x54) = temp_v0;
            func_8003F1DC(temp_s1);
            func_8003F114(temp_s1, 0, -1, *(s32 *)((u8 *)arg0 + 0x168));
            *(u8 **)(temp_v0 + 0x38) = temp_s2;
            *(void **)(temp_s2 + 4) = temp_v0;
            switch (var_s3) {
            case 0:
                *(void **)(temp_s2 + 8) = NULL;
                *(f32 *)(temp_v0 + 0x54) = temp_fs0;
                *(f32 *)(temp_v0 + 0x58) = temp_fs0;
                *(f32 *)(temp_v0 + 0x5C) = temp_fs0;
                temp_v0_2 = *(s32 *)((u8 *)arg0 + 0x178);
                var_s6 = temp_v0;
                if ((temp_v0_2 >= 0) && (temp_v0_2 < 4)) {
                    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x170) + 0x2182) & (1 << temp_v0_2)) {
                        temp_a1 = 6;
                    } else {
                        temp_a1 = 2;
                    }
                    var_a1 = temp_a1 + temp_v0_2;
                } else {
                    var_a1 = 1;
                }
                *(s32 *)(temp_s2 + 0xC) = func_8004C990(0x1B2, var_a1);
                break;
            case 1:
                *(void **)(temp_s2 + 8) = var_s6;
                break;
            }
            func_87F0AFD0(temp_s2 + 0x14, temp_v0 + 0x48, temp_v0 + 0x54, temp_v0 + 0x42);
            temp_v0_3 = *(void **)(temp_s2 + 4);
            *(u8 *)((u8 *)temp_v0_3 + 0x25) &= ~1;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_308D70/func_87E06290.s")

extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern void func_80007328(Gfx **, void *);
extern void func_80007444(Gfx **, s32, s32, s32, s32, s32);
extern void func_87F0BD48(u8 *);
extern void func_8004D19C(s32, s32, s32, s32, s32);

// FAKE: K&R implicit-int parameter; the natural ANSI form fails to build because the already-matched caller func_87E079FC calls it with no arguments.


void func_87E0664C(arg0) {
    s32 i;
    u8 *var_s0;
    u8 *state;

    func_80007328(&D_800D0510, *(void **)((u8 *)arg0 + 0x5C));
    state = *(u8 **)((u8 *)arg0 + 0x5C);
    func_80007444(&D_800D0510, 0, 0, *(u16 *)(state + 4), *(u16 *)(state + 6), 0);
    func_87F0BD48((u8 *)arg0 + 0x148);
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetRenderMode(D_800D0510++, 0x00504340, 0);
    gDPSetCombine(D_800D0510++, 0x30D261, 0x55A6FF7F);
    gDPSetPrimColor(D_800D0510++, 0, 0, 255, 240, 200, 255);
    for (i = 0, var_s0 = (u8 *)arg0 + 0xE8; i != 0xC; i++, var_s0 += 8) {
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 100, 60, 0, *(u8 *)(var_s0 + 4));
        func_8004D19C(9, 3, *(s32 *)var_s0, 0, 0);
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}

u32 func_87E067F0(s32 arg0, s32 arg1) {
    extern u32 D_87E19B4C[];
    return D_87E19B4C[arg0];
}

extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern void GfxImage_SetRenderTarget(Gfx **, s32);
extern void GfxImage_FillCurrent(Gfx **, u16);
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
void func_87E06808(s32 arg0) {
    u8 *var_s1;
    s32 var_s2;

    var_s1 = *(u8 **)((u8 *)arg0 + 0x150);
    for (var_s2 = 0; var_s2 != 0xC; var_s2 += 1, var_s1 += 0x9C) {
        GfxImage_SetRenderTarget(&D_800D0510, *(s32 *)(var_s1 + 0x90));
        GfxImage_FillCurrent(&D_800D0510, 0xFFFE);
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
        func_8004D19C(0, 0, func_8004C990(0x172, func_87E067F0(var_s2, *(s32 *)(var_s1 + 0x88))), 0, 0);
    }
}

extern void func_8004C8C0(s32);
void func_87E06908(s32 arg0) {
    func_8004C8C0(0x18B);
    func_8004C8C0(0x177);
    func_8004C8C0(0x176);
    func_8004C8C0(0x17F);
    func_8004C8C0(0x184);
    func_8004C8C0(0x193);
    func_8004C8C0(0x18C);
    func_8004C8C0(0x190);
    func_8004C8C0(0x195);
    func_8004C8C0(0x198);
    func_8004C8C0(0x19B);
    func_8004C8C0(0x1A1);
    func_8004C8C0(0x172);
    func_8004C8C0(0x1BF);
    func_8004C8C0(0x169);
    func_8004C8C0(0x1B2);
}

/* mkdraft:func_87E069A4 begin */
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 func_80040E80(s32, void *);
extern u8 D_87E19AB0;
extern s32 func_87F08E7C(u16, u16, u8, u8, s32);
extern s32 func_8004C990(s32, s32);
extern void func_87F0BD30(u8 *, u16, u16, s32);



void func_87E069A4(u8 *arg0) {
    s32 state;
    s32 sp28;
    s32 var_v1;
    u8 *var_v0;

    state = MainPool_AllocState(main_pool_get_available(), 0);
    sp28 = state;
    *(s32 *)((u8 *)arg0 + 0x160) = func_80040E80(state, &D_87E19AB0);
    MainPool_FinalizeAllocation(sp28);
    *(s32 *)((u8 *)arg0 + 0x58) = func_87F08E7C(0x102, 0x17, 0, 2, 0xF000000);
    func_87F0BD30(arg0 + 0x148, 0x102, 0x17, 0xFFC85AFF);
    var_v1 = 0;
    var_v0 = arg0;
    do {
        var_v1 += 4;
        *(u8 *)(var_v0 + 0xF4) = 0;
        *(u8 *)(var_v0 + 0xFC) = 0;
        *(u8 *)(var_v0 + 0x104) = 0;
        var_v0 += 0x20;
        *(u8 *)(var_v0 + 0xCC) = 0;
    } while (var_v1 != 0xC);
    *(s32 *)((u8 *)arg0 + 0xE8) = func_8004C990(0x18B, 0);
    *(s32 *)((u8 *)arg0 + 0xF0) = func_8004C990(0x190, 0);
    *(s32 *)((u8 *)arg0 + 0xF8) = func_8004C990(0x18C, 0);
    *(s32 *)((u8 *)arg0 + 0x100) = func_8004C990(0x195, 0);
    *(s32 *)((u8 *)arg0 + 0x108) = func_8004C990(0x176, 0);
    *(s32 *)((u8 *)arg0 + 0x110) = func_8004C990(0x198, 0);
    *(s32 *)((u8 *)arg0 + 0x118) = func_8004C990(0x17F, 0);
    *(s32 *)((u8 *)arg0 + 0x120) = func_8004C990(0x19B, 0);
    *(s32 *)((u8 *)arg0 + 0x128) = func_8004C990(0x1A1, 0);
    *(s32 *)((u8 *)arg0 + 0x130) = func_8004C990(0x177, 0);
    *(s32 *)((u8 *)arg0 + 0x138) = func_8004C990(0x193, 0);
    *(s32 *)((u8 *)arg0 + 0x140) = func_8004C990(0x184, 0);
}
/* mkdraft:func_87E069A4 end */

s32 func_800071A4(s32, s32, s32, s32, s32);

void func_87E06B18(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x5C))) = func_800071A4(0, 2, 0x102, 0x17, 0);
}

extern s32 PokeIcon_AllocLoadContext(s32);
void func_87E06B54(s32 arg0) {
    s32 i;
    void *entry;

    entry = main_pool_alloc(0x128, 0);
    *(s32 *)((u8 *)arg0 + 0x154) = (s32)entry;
    for (i = 0; i != 2; i += 1, entry = (void *)((u8 *)entry + 0x94)) {
        *(s32 *)((u8 *)entry + 0) = -1;
        *(s32 *)((u8 *)entry + 4) = i;
        *(s32 *)((u8 *)entry + 0x90) = PokeIcon_AllocLoadContext(5);
    }
}

/* mkdraft:func_87E06BCC begin */
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 func_80040E80(s32, void *);
extern u8 D_87E19AE4;
extern s32 func_87F08E7C(u16, u16, u8, u8, s32);



void func_87E06BCC(u8 *arg0) {
    s32 state;
    s32 unk;
    s32 i;
    s32 temp;
    u8 *record;

    state = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)((u8 *)arg0 + 0x164) = func_80040E80(state, &D_87E19AE4);
    MainPool_FinalizeAllocation(state);
    *(s32 *)((u8 *)arg0 + 0x150) = main_pool_alloc(0x750, 0);
    unk = func_87F08E7C(0x40, 0x40, 0, 2, 0xF000000);
    record = *(u8 **)((u8 *)arg0 + 0x150);
    for (i = 0; i != 12; i++, record += 0x9C, *(s32 *)(record - 0xC) = temp) {
        *(u8 *)(record + 0x98) = i;
        *(s32 *)(record + 0x88) = 0;
        *(s32 *)(record + 0x8C) = unk;
        *(f32 *)(record + 0x94) = 0.0f;
        temp = func_800071A4(0, 2, 0x40, 0x40, 0);
    }
}
/* mkdraft:func_87E06BCC end */

extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 process_geo_layout(s32, void *);
extern u8 D_87E19B18;
extern s32 func_87F08E3C(s32, s32);
extern s32 func_87F08DF8(s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
void func_87E06CB4(void *arg0) {
    s32 state;

    state = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)((u8 *)arg0 + 0x168) = process_geo_layout(state, &D_87E19B18);
    MainPool_FinalizeAllocation(state);
    state = main_pool_alloc(0x138, 0);
    *(s32 *)((u8 *)arg0 + 0x158) = state;
    *(s32 *)(state + 0) = 0;
    *(s32 *)(state + 0xC) = func_8004C990(0x1B2, 1);
    *(s32 *)(state + 0x10) = func_87F08E3C(*(s32 *)(state + 0xC), 0x0F000000);
    state = *(s32 *)((u8 *)arg0 + 0x158);
    state += 0x9C;
    *(s32 *)(state + 0) = 1;
    *(s32 *)(state + 0xC) = func_8004C990(0x169, 0);
    *(s32 *)(state + 0x10) = func_87F08DF8(*(s32 *)(state + 0xC), 0x41000000, 0xC1180000, 0x0F000000);
}

void func_87E06D84(u8 *arg0) {}

extern s32 main_pool_push_state(s32);
extern void func_87F0BD10(void);
extern void PokeIcon_InitResourceArchives(void);
extern void func_87E069A4(u8 *);
extern void func_87E06BCC(u8 *);
extern void func_87E10E64(s32);
extern void func_87E10EA8(s32);
extern void func_87E10F2C(s32);

void func_87E06D8C(u8 *arg0, s32 arg1) {
    main_pool_push_state(1296516947);
    *(s32 *)(arg0 + 368) = arg1;
    *(s32 *)(arg0 + 8) = *(s8 *)((u8 *)(u32)arg1 + 8579);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0) = 0;
    arg0[396] &= ~0x80;
    func_87F0BD10();
    PokeIcon_InitResourceArchives();
    func_87E06D84(arg0);
    func_87E06908((s32)arg0);
    func_87E069A4(arg0);
    func_87E06BCC(arg0);
    func_87E06B54((s32)arg0);
    func_87E06CB4(arg0);
    func_87E06B18(arg0);
    func_87E06068((s32)arg0);
    func_87E10E64(-1);
    func_87E10EA8(-1);
    func_87E10F2C(-1);
}

s32 func_87E06E48(void *arg0) {
    s32 result;
    s32 i;
    void *entry;

    result = 1;
    entry = *(void **)((u8 *)arg0 + 0x150);
    for (i = 0; i < 12; i++) {
        if (*(s32 *)((u8 *)entry + 0x84)) { result = 0; i = 0; break; }
        entry = (void *)((u8 *)entry + 0x9C);
    }
    if (*(s32 *)((u8 *)arg0 + 0xE4)) result = 0;
    entry = *(void **)((u8 *)arg0 + 0x154);
    for (i = 0; i < 2; i++) {
        if (*(s32 *)((u8 *)entry + 0x8C)) { result = 0; break; }
        entry = (void *)((u8 *)entry + 0x94);
    }
    return result;
}

extern u8 D_87E1A0E4[];
extern void func_87F0B1A4(s32, void *, f32, f32, f32, s32, s32);

typedef struct {
    f32 x, y, z;
} Vec3;

// Sends the flagged entries of the two object lists at arg0+0x24 and arg0+0x38
// to func_87F0B1A4 with node+0x48 as the position pointer. A flagged entry of
// the first list passes the entry's object with the three floats of the 12-byte
// D_87E1A0E4 vector selected by the object's signed byte at 0x98. A flagged
// entry of the second list passes the object 8 bytes in, with floats copied
// from the entry's position, Y lowered by 20 and Z advanced by 150.
// Old-style (K&R) definition: its only caller, func_87E07330, passes no
// arguments in retail, so the call keeps that form for the IDO build.


void func_87E06EC0(arg0)
void *arg0;
{
    u8 *node;
    u8 *object;
    u8 *state;
    Vec3 pos;
    u32 index; // FAKE: never read; this unused local grows the frame from 0x68 to 0x70 as in retail. Diff score 87 without it.
    node = *(u8 **)((u8 *)arg0 + 0x24);
    if (node != NULL) {
        do {
            object = NULL;
            if (*(s32 *)(node + 0xC) & 0x20000000) {
                object = *(u8 **)(node + 0x20);
                state = &D_87E1A0E4[*(s8 *)(object + 0x98) * 12];
            }
            if (object != NULL) {
                func_87F0B1A4(object, node + 0x48, *(f32 *)(state + 0), *(f32 *)(state + 4), *(f32 *)(state + 8), 0xF, 0x2000);
            }
            node = *(u8 **)(node + 4);
        } while (node != NULL);
    }
    node = *(u8 **)((u8 *)arg0 + 0x38);
    if (node != NULL) {
        do {
            object = NULL;
            if (*(s32 *)(node + 0xC) & 0x40000000) {
                object = *(u8 **)(node + 0x20) + 8;
                state = (u8 *)&pos;
                pos = *(Vec3 *)(node + 0x48);
                pos.y = pos.y - 20.0f;
                pos.z = pos.z + 150.0f;
            }
            if (object != NULL) {
                func_87F0B1A4(object, node + 0x48, *(f32 *)(state + 0), *(f32 *)(state + 4), *(f32 *)(state + 8), 0xF, 0x2000);
            }
            node = *(u8 **)(node + 4);
        } while (node != NULL);
    }
}

extern void func_87F0B1A4(s32, void *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(s32, void *, f32, f32, f32, s32, s32);
extern u32 func_8003570C(void);
void func_87E07040(s32 arg0, void *arg1, s32 arg2) {
    u8 *temp_s0;
    u32 temp_v0;
    u32 temp_v1;
    u32 temp_a0;
    temp_s0 = (u8 *)arg1;
    func_87F0B1A4(arg0, temp_s0 + 0x48, *(f32 *)(temp_s0 + 0x48), *(f32 *)(temp_s0 + 0x4C) + -360.0f, *(f32 *)(temp_s0 + 0x50), arg2, 0x2000);
    temp_v1 = func_8003570C();
    temp_v0 = func_8003570C();
    temp_a0 = func_8003570C();
    func_87F0B2F4(arg0, (void *)(temp_s0 + 0x42), (f32)temp_v1 / 4294967296.0f * 90.0f - 45.0f, (f32)temp_v0 / 4294967296.0f * 90.0f - 45.0f, (f32)temp_a0 / 4294967296.0f * 360.0f - 180.0f, arg2, 0);
}

extern void func_87E07040(s32, void *, s32);
extern void func_87F0B24C(s32, u8 *, f32, f32, f32, s32, s32);
void func_87E07194(void *arg0) {
    u8 *var_s0;
    s32 temp_v0;
    f32 temp_f0;

    var_s0 = *(u8 **)((u8 *)arg0 + 0x24);
    if (var_s0 != NULL) {
        do {
            temp_v0 = *(s32 *)(var_s0 + 0xC);
            if (temp_v0 & 0x20000000) {
                func_87E07040(*(s32 *)(var_s0 + 0x20), var_s0, 0xF);
            } else if (temp_v0 & 0x10000000) {
                func_87E07040(*(s32 *)(var_s0 + 0x20) + 8, var_s0, 0xF);
            }
            var_s0 = *(u8 **)(var_s0 + 4);
        } while (var_s0 != NULL);
    }
    var_s0 = *(u8 **)((u8 *)arg0 + 0x38);
    if (var_s0 != NULL) {
        temp_f0 = 0.0f;
        do {
            func_87F0B24C(*(s32 *)(var_s0 + 0x20) + 8,
                          var_s0 + 0x54, 0.0f, 0.0f, temp_f0, 0xF, 0);
            var_s0 = *(u8 **)(var_s0 + 4);
        } while (var_s0 != NULL);
    }
}

s32 func_87E07278(u8 *arg0) {
    s32 count = 0;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (*(u16 *)(*(u8 **)(arg0 + 0x170) + 0x21F4) & (1 << i)) {
            count++;
        }
    }
    return count;
}

void func_87E072FC(void *a, u16 b) {
    u8 *p;
    p = *(u8 **)((u8 *)a + 368);
    *(u16 *)(p + 8692) |= b;
    p = *(u8 **)((u8 *)a + 368);
    if (*(u16 *)(p + 8692) == 0xFFF)
        *(u16 *)(p + 8692) = 0;
}

extern void func_87E0168C(s32, s32, s32);
extern void func_87E06EC0();

void func_87E07330(void *arg0) {
#ifdef CC_CHECK
    func_87E06EC0(0);
#else
    func_87E06EC0();
#endif
    (*(s32 *)((u8 *)(arg0) + (4))) = 2;
    func_87E0168C(0, 0x64, -1);
}

/* mkdraft:func_87E0736C begin */
s32 func_800279C4();
extern void func_87E015F4(s32 arg0, s32 arg1);

s32 func_87E07278(u8 *arg0);



void func_87E0736C(void *arg0) {
    u8 buffer[4];
    u16 mask;

    // 0x188 selects the running phase; 0x17C counts the frames spent in it.
    switch (*(u32 *)((u8 *)arg0 + 0x188)) {
    case 0:
        if (*(u32 *)((u8 *)arg0 + 0x17C) >= 21U) {
            func_87E015F4(*(u32 *)((u8 *)arg0 + 0x54) + 72, buffer);
            func_8002781C(0xCF04, *(u8 *)((u8 *)arg0 + 0x17B), buffer);
            (*(s32 *)((u8 *)arg0 + 8))++;
            if (*(s32 *)((u8 *)arg0 + 8) >= 12) {
                *(s32 *)((u8 *)arg0 + 8) = 0;
            }
            (*(s32 *)((u8 *)arg0 + 0x180))++;
            if (*(s32 *)((u8 *)arg0 + 0x184) < *(s32 *)((u8 *)arg0 + 0x180)) {
                mask = 1 << *(s32 *)((u8 *)arg0 + 8);
                if ((*(u16 *)((u8 *)(*(void **)((u8 *)arg0 + 0x170)) + 0x21F4) & mask) == 0) {
                    if ((func_8003570C() % (13 - func_87E07278(arg0))) == 0) {
                        func_87E072FC(arg0, mask);
                        *(u32 *)((u8 *)arg0 + 0x188) = 1;
                        *(u32 *)((u8 *)arg0 + 0x17C) = 0;
                    }
                }
            }
        }
        break;
    case 1:
        if (*(u32 *)((u8 *)arg0 + 0x17C) >= 31U) {
            func_87E07330(arg0);
            func_800279C4(0xCF05);
            if (1) { } // karodo: the empty block boundary keeps the tail increment's
                       // temp in v0; without it uopt colors it v1 (diff score 40).
        }
        break;
    default:
        break;
    }

    (*(u32 *)((u8 *)arg0 + 0x17C)) += 1;
}
/* mkdraft:func_87E0736C end */

/* mkdraft:func_87E074BC begin */
extern u8 D_87E19B7C[];


u16 func_87E074BC(u8 *arg0) {
    u8 *record;
    u16 result;
    s32 indices[4];
    s32 i;
    s32 smallest;
    s32 smallest_index;

    record = D_87E19B7C + *(s32 *)(arg0 + 8) * 4;
    result = 0;
    if (*(s32 *)(arg0 + 0xC) == *(s32 *)(arg0 + 8)) {
        if (*(u32 *)arg0 >= 31) {
            result = 0x8000;
        }
    } else if (*(u32 *)arg0 >= 16) {
        *(u32 *)arg0 = 0;
        if ((f32)(*(s32 *)(arg0 + 0xC) - record[0]) > 0.0f) {
            indices[0] = *(s32 *)(arg0 + 0xC) - record[0];
        } else {
            indices[0] = -(*(s32 *)(arg0 + 0xC) - record[0]);
        }
        if ((f32)(*(s32 *)(arg0 + 0xC) - record[1]) > 0.0f) {
            indices[1] = *(s32 *)(arg0 + 0xC) - record[1];
        } else {
            indices[1] = -(*(s32 *)(arg0 + 0xC) - record[1]);
        }
        if ((f32)(*(s32 *)(arg0 + 0xC) - record[2]) > 0.0f) {
            indices[2] = *(s32 *)(arg0 + 0xC) - record[2];
        } else {
            indices[2] = -(*(s32 *)(arg0 + 0xC) - record[2]);
        }
        if ((f32)(*(s32 *)(arg0 + 0xC) - record[3]) > 0.0f) {
            indices[3] = *(s32 *)(arg0 + 0xC) - record[3];
        } else {
            indices[3] = -(*(s32 *)(arg0 + 0xC) - record[3]);
        }
        smallest = indices[0];
        smallest_index = 0;
        for (i = 1; i != 4; i++) {
            if ((indices[i] < smallest) || ((smallest == indices[i]) && (func_8003570C() % 100 < 49))) {
                smallest = indices[i];
                smallest_index = i;
            }
        }
        switch (smallest_index) {
        case 0: result = 0x800; break;
        case 1: result = 0x400; break;
        case 2: result = 0x200; break;
        case 3: result = 0x100; break;
        }
    }
    return result;
}
/* mkdraft:func_87E074BC end */

extern s32 func_87E05400(u32);
extern void func_87E072FC(void *, u16);
extern void func_87E07330(void *);
extern void func_87E07194(void *);
extern void func_800226C0(s32);
extern u8 D_800CE060[];
extern u8 D_87E19B7C[];



void func_87E076E0(void *arg0) {
    u8 *table;
    u16 buttons;
    s8 result[4]; // FAKE: 4-byte size reproduces the target's 12-byte named-local region

    table = D_87E19B7C + *(s32 *)((u8 *)arg0 + 8) * 4;
    if ((1 << *(s32 *)((u8 *)arg0 + 0x178)) & *(u8 *)(*(u8 **)((u8 *)arg0 + 0x170) + 0x2182)) {
        buttons = *(u16 *)(D_800CE060 + *(s32 *)((u8 *)arg0 + 0x178) * 0x28 + 8);
    } else {
        buttons = func_87E074BC(arg0);
    }
    if ((*(u32 *)((u8 *)arg0 + 0x18C) >> 31) != 0) {
        if (func_87E05400(1) != 0) {
            if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x170) + 0x2180) == 1) {
                func_87E072FC(arg0, (1 << *(s32 *)((u8 *)arg0 + 8)) & 0xFFFF);
            }
            func_87E07330(arg0);
        }
    } else {
        if (buttons & 0x8000) {
            func_800279C4(0xCF05, buttons);
            // FAKE: redundant & 0xFF on a u8 read; deleting it moves the tail's
            // t-registers one slot behind the target starting at this load.
            *(u8 *)((u8 *)arg0 + 0x18C) = (*(u8 *)((u8 *)arg0 + 0x18C) & 0xFF) | 0x80;
        }
        if (buttons & 0x4000) {
            if ((func_87E05400(1) != 0) && (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x170) + 0x2180) == 0)) {
                func_87E07194(arg0);
                *(s32 *)((u8 *)arg0 + 4) = 3;
                func_800226C0(3);
            }
        }
        if ((func_87E05400(2) != 0) && ((buttons & 0x8000) == 0) && ((buttons & 0x4000) == 0)) {
            if (buttons & 0x800) {
                *(s32 *)((u8 *)arg0 + 8) = table[0];
            }
            if (buttons & 0x400) {
                *(s32 *)((u8 *)arg0 + 8) = table[1];
            }
            if (buttons & 0x200) {
                *(s32 *)((u8 *)arg0 + 8) = table[2];
            }
            if (buttons & 0x100) {
                *(s32 *)((u8 *)arg0 + 8) = table[3];
            }
            if (buttons & 0xF00) {
                func_87E015F4(*(s32 *)((u8 *)arg0 + 0x54) + 0x48, result);
                func_8002781C(0xCF04, *(u8 *)((u8 *)arg0 + 0x17B), result);
            }
        }
    }
}

extern s32 func_87E06E48(void *);
extern void func_87E0736C(void *);
extern void func_87E076E0(void *);
extern void func_87F0277C(void *);
s32 func_87E078DC(s32 arg0) {
    s32 temp_v0;
    s32 sp20;

    sp20 = 2;
    D_87E1EB90 = arg0;
    func_87F0277C(arg0 + 0x18);
    func_87F0277C(arg0 + 0x2C);
    func_87F0277C(arg0 + 0x40);
    temp_v0 = *(s32 *)(arg0 + 4);
    switch (temp_v0) {
    case 0:
        if (func_87E06E48((void *)arg0) != 0) *(s32 *)(arg0 + 4) = 1;
        break;
    case 1: {
        s32 temp_v0_2;
        temp_v0_2 = *(s32 *)(arg0 + 0x174);
        switch (temp_v0_2) {
        case 0:
            func_87E0736C((void *)arg0);
            break;
        case 1:
            func_87E076E0((void *)arg0);
            break;
        }
        break;
    }
    case 2:
        if (func_87E06E48((void *)arg0) != 0) {
            sp20 = 0;
            *(u8 *)(*(s32 *)(arg0 + 0x170) + 0x2183) = *(s32 *)(arg0 + 8);
        }
        break;
    case 3:
        if (func_87E06E48((void *)arg0) != 0) {
            sp20 = 1;
            *(u8 *)(*(s32 *)(arg0 + 0x170) + 0x2183) = *(s32 *)(arg0 + 8);
        }
        break;
    }
    *(s32 *)(arg0 + 0) = *(s32 *)(arg0 + 0) + 1;
    return sp20;
}

extern void BgStage_DrawFrame();
extern void func_87E0664C();
extern void func_87E06808(s32);

void func_87E079FC(s32 arg0) {
#ifdef CC_CHECK
    func_87E0664C(0);
#else
    func_87E0664C();
#endif
    func_87E06808(arg0);
    BgStage_DrawFrame();
}

/* mkdraft:func_87E07A2C begin */

s32 func_87E07A2C(u8 *state) {
    s32 selection;
    s32 used_bit;
    s32 remaining;
    s32 step;
    u8 *data;

    selection = 0;
    remaining = func_8003570C() % 145U;
    data = *(u8 **)(state + 0x170);
    if (*(u16 *)(data + 0x21F4) == 0xFFF) {
        *(u16 *)(data + 0x21F4) = 0;
    }
    for (step = 0; step < (s32)remaining; step++) {
        do {
            selection++;
            if (selection >= 12) {
                selection = 0;
            }
            used_bit = *(u16 *)(*(u8 **)(state + 0x170) + 0x21F4) & ((u32)(1 << selection));
        } while (used_bit);
    }
    return selection;
}
/* mkdraft:func_87E07A2C end */
extern void func_87E06290(u8 *);
extern s32 func_87E07A2C(u8 *);
extern u32 func_8003570C(void);
void func_87E07AC4(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 8) = (s32)*(s8 *)((u8 *)*(void **)(arg0 + 0x170) + 0x2183);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x188) = 0;
    *(s32 *)(arg0 + 0x17C) = 0;
    *(s32 *)(arg0 + 0x180) = 0;
    *(s32 *)(arg0 + 0x184) = (func_8003570C() % 13U) + 6;
    *(s32 *)(arg0 + 0x178) = arg1;
    *(s32 *)(arg0 + 0xC) = func_87E07A2C(arg0);
    if (*(u8 *)((u8 *)*(void **)(arg0 + 0x170) + 0x2180) == 0) {
        *(s32 *)(arg0 + 0x174) = 1;
    } else if (*(s8 *)((u8 *)*(void **)(arg0 + 0x170) + 0x218F) == 0) {
        *(s32 *)(arg0 + 0x174) = 0;
    } else {
        *(s32 *)(arg0 + 0x174) = 1;
    }
    func_87E06290(arg0);
}

extern void func_87F02684(s32);
extern void func_87E01628(void);
extern void main_pool_pop_state(s32);
void func_87E07B74(s32 arg0) {
    func_87F02684(arg0 + 0x18);
    func_87F02684(arg0 + 0x2C);
    func_87F02684(arg0 + 0x40);
    func_87E01628();
    main_pool_pop_state(0x4D474753);
}
#endif
