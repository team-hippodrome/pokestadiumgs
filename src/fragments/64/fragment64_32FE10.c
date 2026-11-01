#include "global.h"


#ifdef VERSION_US
u8 *func_87F0D1A0(u8 *arg0) {
    return arg0 + 8;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32FE10/func_87F0D1A8.s")

typedef struct { u8 *value; } Func87F0D44CArg;
extern u8 D_87F112F4[];extern void func_87F0D1A8(void *, void *, s32, s32, s32);
// Plain-pointer signature: retail's call sites pass a0 raw (no struct-by-value
// outgoing-area copy); see the meta for func_87F0D5B8.
void func_87F0D44C(u8 *arg0) {
    func_87F0D1A8(arg0 + 8, D_87F112F4, 0x20, *(s32 *)(arg0 + 4), 8);
}

typedef struct unk_func_87F0D48C {
    s32 unk_00;
    void *unk_04;
    u8 *unk_08;
} unk_func_87F0D48C;

extern s32 func_8004C8C0(u16);
extern s32 func_8004C990(s32, s32);
extern s32 func_87F08E3C(void *, s32);
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern void *func_80040E80(void *, void *);
extern void MainPool_FinalizeAllocation(void *);
extern s32 main_pool_alloc(s32, s32);
extern void func_87F0252C(void *, void *, u8 *, s32);
extern u8 D_87F112C0[];

void func_87F0D48C(u8 *arg0, void *arg1, void *arg2) {
    u8 *pool;
    u8 *objects;
    unk_func_87F0D48C *data;
    s32 i;

    *(void **)arg0 = arg1;
    *(s32 *)(arg0 + 4) = 0;
    *(void **)(arg0 + 32) = NULL;
    func_87F0D44C(arg0);
    func_8004C8C0(372);
    if (arg2 != NULL) {
        *(s32 *)(arg0 + 36) = func_87F08E3C((void *)func_8004C990(372, 0), 0x0F000000);
        pool = MainPool_AllocState(main_pool_get_available(), 0);
        *(void **)(arg0 + 32) = func_80040E80(pool, D_87F112C0);
        MainPool_FinalizeAllocation(pool);
        objects = (u8 *)main_pool_alloc(1584, 0);
        data = (unk_func_87F0D48C *)main_pool_alloc(48, 0);
        func_87F0252C(arg2, arg0 + 12, objects, 4);
        for (i = 0; i < 4; i++) {
            *(unk_func_87F0D48C **)(objects + i * 396 + 56) = &data[i];
            data[i].unk_00 = i;
            data[i].unk_04 = NULL;
            data[i].unk_08 = arg0;
        }
    }
}

extern u32 func_87F00930(void);
extern void func_87F0277C(void *);

void func_87F0D5B8(u8 *arg0) {
    if (func_87F00930() == 0) {
        *(s32 *)(arg0 + 4) += 1;
    }
    func_87F0D44C(arg0);
    func_87F0277C(arg0 + 0xC);
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32FE10/func_87F0D600.s")

// Prefix views for the callback's model node and its three-word callback data.
// GeoNode_CreateModelPart initializes the same vector and color field layouts.
//@src/229E0.c
typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} unk_func_87F0D96C_024;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
} unk_func_87F0D96C_01E;

typedef union {
    u8 rgba[4];
    u32 word;
} unk_func_87F0D96C_03C;

typedef struct unk_func_87F0D96C {
    u8 unk_00[20];
    struct unk_func_87F0D96C_014 *unk_14;
    u8 unk_18[6];
    unk_func_87F0D96C_01E unk_1E;
    unk_func_87F0D96C_024 unk_24;
    unk_func_87F0D96C_024 unk_30;
    unk_func_87F0D96C_03C unk_3C;
} unk_func_87F0D96C;

typedef struct unk_func_87F0D96C_014 {
    s32 unk_00;
    unk_func_87F0D96C *unk_04;
    u8 *unk_08;
} unk_func_87F0D96C_014;

s32 func_87F0D96C(s32 arg0, unk_func_87F0D96C *arg1) {
    unk_func_87F0D96C_014 *var_v0;

    if (arg0 == 2) {
        var_v0 = arg1->unk_14;
        if (var_v0->unk_04 != NULL) {
            arg1->unk_24 = var_v0->unk_04->unk_24;
            arg1->unk_30 = var_v0->unk_04->unk_30;
            arg1->unk_1E = var_v0->unk_04->unk_1E;
            arg1->unk_3C = *(unk_func_87F0D96C_03C *)func_87F0D1A0(var_v0->unk_08);
        }
    }
    return 1;
}

/* mkdraft:func_87F0DA08 begin */
extern Gfx *D_800D0510;
extern unk_func_87F0D96C *D_8009491C;
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);

// Color byte view of unk_3C, whose four bytes gDPSetEnvColor takes as separate
// r/g/b/a arguments.
// FAKE: the named-member struct cast; diff score 1080 with the union's rgba[] array.
typedef struct { u8 r, g, b, a; } Color87F0DA08;

// Emits the RDP combine and env-color packets, segment 0xF from the main-pool object at
// 0x174, and the display list at node->unk_08 + 0x24, then calls func_8003CD84. Runs
// only when arg0 is 5 and bit 13 of the word at node->unk_08 + node->unk_00 * 0x18
// + 0x21A4 is set.


void func_87F0DA08(s32 arg0, s32 arg1) {
    unk_func_87F0D96C *state;
    unk_func_87F0D96C_014 *node;

    state = D_8009491C;
    if (arg0 != 5) {
        return;
    }
    node = state->unk_14;
    // FAKE: the shift pair is how the bit 13 test keeps the block's temporaries in the
    // target's registers; diff score 260 with `<< 18 < 0`.
    if (((*(s32 *)(*(u8 **)node->unk_08 + node->unk_00 * 0x18 + 0x21A4) << 18) >> 31) != 0) {
        gDPSetCombine(D_800D0510++, 0xFCFF9BFF, 0xFFFEFE38);
        gDPSetEnvColor(D_800D0510++, ((Color87F0DA08 *)&state->unk_3C)->r, ((Color87F0DA08 *)&state->unk_3C)->g, ((Color87F0DA08 *)&state->unk_3C)->b, ((Color87F0DA08 *)&state->unk_3C)->a);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0x174, 0)));
        gSPDisplayList(D_800D0510++, *(void **)(node->unk_08 + 0x24));
        func_8003CD84();
    }
}
/* mkdraft:func_87F0DA08 end */

extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_80037E3C(void *, s32 (*)(s32, unk_func_87F0D96C *), void *);

// When arg0 + 0x20 holds model data, takes a free 0x18C-byte object from the pool
// at arg0 + 0xC with func_87F025B8, initializes the object's model node at +0x24 with
// that data and installs func_87F0D96C as the node callback. The callback data
// (object + 0x38, the node's unk_14) receives arg1 and `source`, the node whose
// unk_1E/unk_24/unk_30 fields func_87F0D96C copies into this node. func_867068EC
// passes another pool object's model node as `source`. Pool functions:
//@src/fragments/64/fragment64_324FB0.c
void func_87F0DB3C(u8 *arg0, s32 arg1, unk_func_87F0D96C *source) {
    u8 *object;
    unk_func_87F0D96C_014 *data;

    if (*(void **)(arg0 + 0x20) != NULL) {
        object = func_87F025B8(arg0 + 0xC, NULL);
        if (object != NULL) {
            data = *(unk_func_87F0D96C_014 **)(object + 0x38);
            func_8003F1DC(object + 0x24);
            func_8003F114(object + 0x24, 0, -1, *(void **)(arg0 + 0x20));
            func_80037E3C(object + 0x24, func_87F0D96C, data);
            data->unk_00 = arg1;
            data->unk_04 = source;
        }
    }
}
#endif
