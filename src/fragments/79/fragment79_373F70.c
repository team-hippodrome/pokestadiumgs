#include "global.h"


#ifdef VERSION_US
extern void GeoNode_CreateModelPart(s32, u8 *, s32, u8 *, u8 *, u8 *);
extern void func_80038F8C(u8 *, u8 *);
extern u8 D_800948DC[];
extern u8 D_800948E4[];
extern u8 D_800948D0[];
extern u8 D_84190030[];
void func_841046E0(u8 *arg0) {
    GeoNode_CreateModelPart(0, arg0, -1, D_800948D0, D_800948DC, D_800948E4);
    func_80038F8C(D_84190030, arg0);
    arg0[1] &= 0xFFFE;
}

extern u8 D_8418D2A0[];

void func_8410474C(void) {
    s32 i;

    func_80037E9C(0, D_84190030);
    for (i = 0; i < 32; i++) {
        func_841046E0(&D_8418D2A0[i * 0x16C]);
        *(u32 *)&D_8418D2A0[i * 0x16C + 0x168] = 0;
    }
}

s32 func_841047A4(u8 *arg0) {
    return *(s32 *)(arg0 + 0x14);
}

extern u8 D_8418D2A0[];
extern u8 D_84190020[];
extern void func_84105CA0(u8 *);
// Claims the first 0x16C-byte entry of D_8418D2A0 whose word at +0x168 is 0
// and sets that word to 1; func_84104818 clears it again. When every entry up
// to D_84190020 is in use, passes "Can't Alloc Hms Effect Dynamic"
// to func_84105CA0 and returns NULL.
u8 *func_841047AC(void) {
    s32 i;
    u8 *entry;

    entry = NULL;
    i = 0;
    do {
        if (*(s32 *)(D_8418D2A0 + i * 0x16C + 0x168) == 0) {
            *(s32 *)(D_8418D2A0 + i * 0x16C + 0x168) = 1;
            entry = D_8418D2A0 + i * 0x16C;
            break;
        }
        i++;
    } while (D_84190020 != D_8418D2A0 + i * 0x16C);
    if (entry == NULL) {
        func_84105CA0("Can't Alloc Hms Effect Dynamic");
    }
    return entry;
}

extern u8 D_84190020[];
extern void func_84105CA0(u8 *);
extern void func_8003F1DC(void *);

void func_84104818(u8 *arg0) {
    s32 i;

    for (i = 0; i < 32; i++) {
        if (arg0 == (u8 *)D_8418D2A0 + i * 0x16C) {
            break;
        }
    }
    if (D_84190020 == (u8 *)D_8418D2A0 + i * 0x16C) {
        func_84105CA0("Can't Remove Hms Shape");
    }
    *(s32 *)((u8 *)D_8418D2A0 + i * 0x16C + 0x168) = 0;
    ((u8 *)D_8418D2A0 + i * 0x16C)[2] &= 0xFFFD;
    func_8003F1DC((u8 *)D_8418D2A0 + i * 0x16C);
}
extern void func_84104818(u8 *);
void func_8410488C(u8 *arg0) {
    u8 *ptr = *(u8 **)(arg0 + 0xC);
    if (ptr != NULL) func_84104818(ptr);
}

extern void ModelAnim_SetFrame(u8 *, s16);
void BattleAnim_SetModelAnimFrame(u8 *arg0, s16 arg1) {
    ModelAnim_SetFrame(arg0, arg1);
}

extern s32 D_8418CA20[];
extern void func_8003F114(u8 *, s32, s32, s32);
void func_841048E0(u8 *arg0, s16 arg1) {
    func_8003F114(arg0, 0, -1, D_8418CA20[arg1]);
}

extern void ModelAnim_BindTransformCurve(u8 *, s32, s32, s32);
void BattleAnim_BindModelAnim(u8 *arg0, s16 arg1) {
    ModelAnim_BindTransformCurve(arg0, 0, D_8418CA20[arg1], 0x10000);
}

void BattleAnim_BindModelAnimReversed(u8 *arg0, s16 arg1) {
    ModelAnim_BindTransformCurve(arg0, 0, D_8418CA20[arg1], 0xFFFF0000);
    ModelAnim_SetFrame(arg0, (s16)(*(u16 *)(*(u8 **)(arg0 + 0x44) + 0xA) - 1));
}

void func_841049B4(u8* arg0) {
    ModelAnim_SetFrame(arg0, (s16)(*(u16*)(*(u8**)(arg0 + 0x44) + 0xA) - 1));
}

s32 BattleAnim_IsModelAnimComplete(u8 *arg0) { s32 result = 0; if (*(s32 *)(arg0 + 0x48) == 0) { result = 1; } return result; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_373F70/func_84104A00.s")

/* mkdraft:func_84104D28 begin */
// func_84104D28 - matched in src/fragments/79/fragment79_373F70.c
// (replaces the GLOBAL_ASM pragma for asm/us/nonmatchings/fragments/79/
//  fragment79_373F70/func_84104D28.s).
//
// File-scope declarations already present in fragment79_373F70.c:
//   extern u8 D_84190020[];
//   extern u8 D_8418D2A0[];
// and the functions defined above the splice point:
//   func_841047AC, func_841048E0, BattleAnim_BindModelAnim,
//   BattleAnim_BindModelAnimReversed, func_841049B4.

extern u8 D_84190020[];

// The four 3-float vectors summed by func_84104D28 at arg1+0x38, +0x2C, +0x44
// and +0x50. Reading their components through a struct pointer is what makes
// IDO emit the loads and adds in the retail object's order; the same sum over
// *(f32 *)(arg1 + n) casts orders the last add's operands differently.
typedef struct unk_func_84104D28_Vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} unk_func_84104D28_Vec3f;

extern s32 ParticleMath_HasBits(void *, s32);
extern void func_84102750(u8 *, void *);
extern s32 func_84104A00(u8 *);
extern void BattleAnim_GetPointAlongCameraRay(u8 *, f32);

// Allocates an effect object with func_841047AC (an entry of D_8418D2A0),
// cross-links it with the record arg1 (obj+0x14 = arg1, arg1+0xC = obj) and
// binds the animations named by the s16 indices at *(u8 **)(model + 0x14).
// obj+0x24, +0x28 and +0x2C become the component-wise sum of the four vectors
// at arg1+0x38, +0x2C, +0x44 and +0x50; when bit 0x10 of the word at model+8
// is set, D_84190020 also receives the sum of the first two.


u8 *func_84104D28(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *obj;
    u8 *state;
    u8 *model;

    obj = func_841047AC();
    state = *(u8 **)(arg1 + 8);
    model = *(u8 **)arg0;
    if (obj != NULL) {
        *(u8 **)(obj + 0x14) = arg1;
        *(u8 **)(arg1 + 0xC) = obj;
        arg1[0x7E] = arg2;
        if (ParticleMath_HasBits(model + 4, 1)) {
            BattleAnim_GetPointAlongCameraRay(arg1 + 0x38,
                *(s16 *)(*(u8 **)(model + 0x14) + 6));
        } else {
            func_84104A00(arg1);
        }
        *(f32 *)(obj + 0x24) = ((unk_func_84104D28_Vec3f *)(arg1 + 0x38))->x +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x2C))->x +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x44))->x +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x50))->x;
        *(f32 *)(obj + 0x28) = ((unk_func_84104D28_Vec3f *)(arg1 + 0x38))->y +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x2C))->y +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x44))->y +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x50))->y;
        *(f32 *)(obj + 0x2C) = ((unk_func_84104D28_Vec3f *)(arg1 + 0x38))->z +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x2C))->z +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x44))->z +
            ((unk_func_84104D28_Vec3f *)(arg1 + 0x50))->z;
        if (ParticleMath_HasBits(model + 8, 0x10)) {
            *(f32 *)(D_84190020 + 0) =
                ((unk_func_84104D28_Vec3f *)(arg1 + 0x38))->x +
                ((unk_func_84104D28_Vec3f *)(arg1 + 0x2C))->x;
            *(f32 *)(D_84190020 + 4) =
                ((unk_func_84104D28_Vec3f *)(arg1 + 0x38))->y +
                ((unk_func_84104D28_Vec3f *)(arg1 + 0x2C))->y;
            *(f32 *)(D_84190020 + 8) =
                ((unk_func_84104D28_Vec3f *)(arg1 + 0x38))->z +
                ((unk_func_84104D28_Vec3f *)(arg1 + 0x2C))->z;
        }
        func_84102750(*(u8 **)(arg1 + 0xC), model);
        if (*(s16 *)(*(u8 **)(model + 0x14))) {
            func_841048E0(obj, *(s16 *)(*(u8 **)(model + 0x14)));
            if (state[2] & 2) {
                obj[2] |= 2;
            }
            if (ParticleMath_HasBits(model + 8, 2)) {
                *(s16 *)(obj + 0x18) = 3;
            }
        }
        if (*(s16 *)(*(u8 **)(model + 0x14) + 2)) {
            if (ParticleMath_HasBits(model + 4, 0x4000)) {
                BattleAnim_BindModelAnimReversed(obj,
                    *(s16 *)(*(u8 **)(model + 0x14) + 2));
            } else {
                BattleAnim_BindModelAnim(obj,
                    *(s16 *)(*(u8 **)(model + 0x14) + 2));
            }
            if (ParticleMath_HasBits(model + 4, 0x8000)) {
                func_841049B4(obj);
            }
        }
        obj[0x1D] = arg1[0x87];
    }
    return obj;
}
/* mkdraft:func_84104D28 end */

extern u8 *func_841047AC(void);
extern void BattleAnim_GetPointAlongCameraRay(u8 *, f32);
extern void func_841048E0(u8 *, s16);
u8 *func_84104F54(u8 *arg0) {
    u8 *value;
    value = func_841047AC();
    if (value != NULL) {
        *(u8 **)(value + 0x14) = arg0;
        *(u8 **)(arg0 + 0xC) = value;
        BattleAnim_GetPointAlongCameraRay(value + 0x24, 50.0f);
        func_841048E0(value, 0x130);
    }
    return value;
}
#endif
