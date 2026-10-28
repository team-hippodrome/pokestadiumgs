#include "global.h"


#ifdef VERSION_US
extern void func_8004C8C0(s32);
extern void func_87F0277C(s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_3166F0/func_87E12D80.s")

extern void *D_8009491C;
extern Gfx *D_800D0510;
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState();

// Same code as fragment63's func_87E05874, but GS selects the texture (0x258) and the
// display list (0x260) by the index at 0x4 of the model data.
//@src/fragments/63/fragment63_308D70.c
void func_87E130F0(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;

    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60(((u8 **)((u8 *)temp_v0 + 0x258))[*(s32 *)((u8 *)temp_v0 + 4)]));
        gSPDisplayList(D_800D0510++, ((void **)((u8 *)temp_v0 + 0x260))[*(s32 *)((u8 *)temp_v0 + 4)]);
        GeoRender_ApplyMaterialState();
    }
}
extern void func_87E12D80(void);
extern void *func_87F025B8(void *, void (*)(void));
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
void func_87E131D8(void *arg0) {
    void *temp_v0;
    void *temp_a0;

    temp_v0 = func_87F025B8((u8 *)arg0 + 0x2C, func_87E12D80);
    temp_a0 = (void *)((u8 *)temp_v0 + 0x24);
    if (temp_v0 != 0) {
        func_8003F1DC(temp_a0);
        func_8003F114(temp_a0, 0, -1, *(s32 *)((u8 *)arg0 + 0x254));
        *(void **)((u8 *)temp_v0 + 0x38) = arg0;
        *(u8 *)((u8 *)temp_v0 + 0x25) &= 0xFFFE;
    }
}

void func_87E13248(void) {
    func_8004C8C0(361);
}

extern s32 D_87E1ACA0;
extern s32 func_8004C990(s32, s32);
extern s32 func_87F08E3C(s32, s32);
extern void func_87F0252C(void *, void *, void *, s32);
extern void func_87E131D8(void *arg0);
typedef struct Func87E13268_State {
    u8 pad0[0x254];
    s32 field254;
    s32 field258;
    s32 field25C;
    s32 field260;
    s32 field264;
} Func87E13268_State;

void func_87E13268(Func87E13268_State *arg0) {
    s32 sp24;
    s32 temp_v0;
    extern u8 D_87E1EBC0;
    extern s32 process_geo_layout(s32, s32 *);
    extern s32 MainPool_AllocState(s32, s32);
    extern s32 main_pool_get_available(void);
    extern void MainPool_FinalizeAllocation(s32);

    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp24 = temp_v0;
    arg0->field254 = process_geo_layout(temp_v0, &D_87E1ACA0);
    MainPool_FinalizeAllocation(sp24);
    arg0->field258 = func_8004C990(0x169, 1);
    arg0->field25C = func_8004C990(0x169, 2);
    arg0->field260 = func_87F08E3C(arg0->field258, 0x0F000000);
    arg0->field264 = func_87F08E3C(arg0->field25C, 0x0F000000);
    func_87F0252C(&D_87E1EBC0, (u8 *)arg0 + 0x2C, (u8 *)arg0 + 0x40, 1);
    func_87E131D8(arg0);
}

s32 process_geo_layout(s32, s32 *);
extern u8 D_87E1AC40;
extern u8 D_87E1EBC0;
extern void GeoNode_CreateContainer(s32, void *);
extern s32 MainPool_AllocState(s32, s32);
s32 main_pool_get_available(void);
extern void MainPool_FinalizeAllocation(s32);
void func_87E1331C(void *arg0) {
    s32 sp1C;
    s32 temp_v0;

    GeoNode_CreateContainer(0, &D_87E1EBC0);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    (*(s32 *)((u8 *)(arg0) + (0x28))) = process_geo_layout(temp_v0, &D_87E1AC40);
    MainPool_FinalizeAllocation(sp1C);
}

extern u8 *D_87E1EBD8;
extern void func_87E13248(void);
extern void func_87E1331C(void *arg0);
void func_87E13380(void *arg0) {
    D_87E1EBD8 = arg0;
    *(s32 *)((u8 *)arg0 + 0x00) = 4;
    *(s32 *)((u8 *)arg0 + 0x04) = 0;
    *(s32 *)((u8 *)arg0 + 0x0C) = 0;
    *(s32 *)((u8 *)arg0 + 0x268) = 0;
    *(s32 *)((u8 *)arg0 + 0x08) = 6;
    *(f32 *)((u8 *)arg0 + 0x18) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x14) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x10) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x20) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x1C) = 0.0f;
    func_87E13248();
    func_87E1331C(arg0);
    func_87E13268(arg0);
}

extern u8 *D_87E1EBD8;
void func_87E133F0(void) {
    func_87F0277C((s32) (D_87E1EBD8 + 0x2C));
    if ((*(s32 *)((u8 *)(D_87E1EBD8) + (0))) & 4) {
        (*(u32 *)((u8 *)(D_87E1EBD8) + (0x268))) = (u32) ((*(u32 *)((u8 *)(D_87E1EBD8) + (0x268))) + 1);
        if ((u32) (*(u32 *)((u8 *)(D_87E1EBD8) + (0x268))) >= 0xFFFFFF01U) {
            (*(u32 *)((u8 *)(D_87E1EBD8) + (0x268))) = 0U;
        }
    }
}

extern void Geo_RenderRootNode(s32);
void func_87E13458(void) {
    Geo_RenderRootNode(*(s32*)(D_87E1EBD8 + 0x28));
}

void func_87E13480(u8 *arg0) { extern u8 *D_87E1EBD8; *(u8 **)(D_87E1EBD8 + 4) = arg0; }

void func_87E13490(void) {
    *(u32 *)D_87E1EBD8 |= 1;
    *(u32 *)D_87E1EBD8 &= 0xFFFFFFFD;
}

void func_87E134C0(void) {
    *(u32 *)D_87E1EBD8 &= 0xFFFFFFFE;
    *(u32 *)(D_87E1EBD8 + 0xC) = 0;
}

extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
void func_87E134E8(void) {
    func_87F0B1A4(D_87E1EBD8 + 0x1CC, (f32 *)(D_87E1EBD8 + 0x88), (*(f32 *)((u8 *)(D_87E1EBD8) + (0x88))) + -520.0f, (*(f32 *)((u8 *)(D_87E1EBD8) + (0x8C))), (*(f32 *)((u8 *)(D_87E1EBD8) + (0x90))), 0xF, 0x2000);
    (*(s32 *)((u8 *)(D_87E1EBD8) + (0))) = (s32) ((*(s32 *)((u8 *)(D_87E1EBD8) + (0))) | 2);
}

typedef struct unk_func_87E13558 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} unk_func_87E13558;

void func_87E13558(u8 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    if ((*(u32 *)D_87E1EBD8 & 1) && !(*(u32 *)D_87E1EBD8 & 2)) {
        if (*(u8 **)(D_87E1EBD8 + 12) == NULL) {
            *(unk_func_87E13558 *)(D_87E1EBD8 + 136) = *(unk_func_87E13558 *)(arg0 + 72);
            *(f32 *)(D_87E1EBD8 + 16) = arg1;
            *(f32 *)(D_87E1EBD8 + 20) = arg2;
            *(f32 *)(D_87E1EBD8 + 24) = arg3;
            *(s32 *)(D_87E1EBD8 + 616) = 0;
        }
        if (*(u8 **)(D_87E1EBD8 + 12) != arg0) {
            *(u8 **)(D_87E1EBD8 + 12) = arg0;
            func_87F0B1A4(D_87E1EBD8 + 460, (f32 *)(D_87E1EBD8 + 136),
                *(f32 *)(D_87E1EBD8 + 16) + *(f32 *)(*(u8 **)(D_87E1EBD8 + 12) + 72),
                *(f32 *)(D_87E1EBD8 + 20) + *(f32 *)(*(u8 **)(D_87E1EBD8 + 12) + 76),
                *(f32 *)(D_87E1EBD8 + 24) + *(f32 *)(*(u8 **)(D_87E1EBD8 + 12) + 80), arg4, 0);
        }
    }
}

void func_87E13654(void) {
    extern u8 *D_87E1EBD8;
    *(u32 *)D_87E1EBD8 |= 4;
}

void func_87E1366C(void) {
    extern u8 *D_87E1EBD8;
    *(u32 *)D_87E1EBD8 &= 0xFFFFFFFB;
}

s32 func_87E13688(void) {
    return *(s32 *)(D_87E1EBD8 + 0x250) == 0;
}

s32 func_87E1369C(void) {
    s32 result = *(s32 *)(D_87E1EBD8 + 0x250) == 0;
    if ((result == 0) && (*(s32 *)(D_87E1EBD8 + 0x23C) / 2 < *(s32 *)(D_87E1EBD8 + 0x238))) {
        result = 1;
    }
    return result;
}
#endif
