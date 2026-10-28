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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B001C4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B007D0.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B00A3C.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B01770.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B01A94.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B023FC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B03228.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B03628.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B04500.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B04970.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B057B0.s")
#endif

#ifdef VERSION_US
s16 MathUtil_Atan2s(f32 y, f32 x);
s16 func_86B07D58(f32 arg0, f32 arg1) {
    return (s16) ((s32) (MathUtil_Atan2s(arg0, -arg1) + 0x3FFF) % 65535);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B07D94.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B08214.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B08978.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B08B74.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B095B4.s")
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B0990C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B0B04C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B0B500.s")
#endif

#ifdef VERSION_US
extern void func_80037E3C(u8 *, void *, s32);
extern s32 func_86B0355C(s32, u8 *);
extern void D_86B0B600(s32, u8 *);
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B0BB24.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B0BF2C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/61/fragment61_code/func_86B0CB1C.s")
#endif
