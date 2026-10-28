#include "global.h"


#ifdef VERSION_US
extern void _bcopy(void *, void *, s32);
void func_87F0A5F0(s32 arg0) { s32 sp18[2]; _bcopy(&arg0, &sp18[0], 4); }

extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern s32 MainPool_AllocAligned(s32, s32, s32);
extern void MainPool_FinalizeAllocation(s32);
s32 func_87F0A61C(void) { s32 ptr = MainPool_AllocState(main_pool_get_available(), 0); s32 result = MainPool_AllocAligned(ptr, 0xC, 4); MainPool_FinalizeAllocation(ptr); return result; }

void func_87F0A66C(u8 *arg0, u32 *arg1, u32 *arg2) {
    arg0[0x28] = 2;
    *(u32 *)(arg0 + 0x2C) = *arg1;
    *(u32 *)(arg0 + 0x30) = *arg2;
}

typedef struct TreeNode_80050428 TreeNode_80050428;
extern void *func_8005049C(TreeNode_80050428 *, s32);
void func_87F0A688(TreeNode_80050428 *arg0, s32 arg1, s32 arg2) {
    u8 *entry = func_8005049C(arg0, arg1);
    if (entry == NULL) {
        func_87F0A5F0(arg1);
    } else {
        *(s16 *)(entry + 0x26) = arg2;
    }
}

void func_87F0A6C8(TreeNode_80050428 *arg0, s32 arg1, u32 *arg2, u32 *arg3) {
    u8 *entry = func_8005049C(arg0, arg1);
    if (entry == NULL) {
        func_87F0A5F0(arg1);
    } else {
        func_87F0A66C(entry, arg2, arg3);
    }
}

extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_800504BC(s16 *);
typedef struct {
    u8 r, g, b, a;
} Fragment64Rgba;
typedef struct {
    /* 0x00 */ s32 orientation;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 *bounds;
} Fragment64BarLayout;
typedef struct {
    /* 0x00 */ u8 unk_00[2];
    /* 0x02 */ u16 flags;
    /* 0x04 */ u8 unk_04[4];
    /* 0x08 */ s16 x;
    /* 0x0A */ s16 y;
    /* 0x0C */ u8 unk_0C[0x14];
    /* 0x20 */ Fragment64BarLayout *layout;
    /* 0x24 */ u16 textureId;
    /* 0x26 */ u16 textureIndex;
    /* 0x28 */ u8 unk_28[4];
    /* 0x2C */ Fragment64Rgba prim;
    /* 0x30 */ Fragment64Rgba env;
} Fragment64BarNode;
void func_87F0A714(s32 arg0, Fragment64BarNode *arg1) {
    struct { s16 position[2]; u32 unused; } scratch;
    Fragment64BarLayout *layout;
    s16 *texture;

    switch (arg0) {
        case 0:
            layout = arg1->layout;
            func_800504BC(scratch.position);
            layout->x = arg1->x + scratch.position[0];
            layout->y = arg1->y + scratch.position[1];
            arg1->flags &= 0xFFFD;
            break;
        case 1:
            layout = arg1->layout;
            gSPDisplayList(D_800D0510++, D_80094E38);
            gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, PRIMITIVE,
                              ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0);
            gDPSetPrimColor(D_800D0510++, 0, 0, arg1->prim.r, arg1->prim.g, arg1->prim.b, arg1->prim.a);
            gDPSetEnvColor(D_800D0510++, arg1->env.r, arg1->env.g, arg1->env.b, arg1->env.a);
            texture = (s16 *)func_8004C990(arg1->textureId, arg1->textureIndex);
            func_8004D1FC((u8 *)texture);
            switch (layout->orientation) {
                case 0:
                    GfxRect_DrawTextured(layout->x, layout->y, layout->bounds[2] - layout->x, texture[1], 0, 0, 0x400,
                                         0x400, 0);
                    break;
                case 1:
                    GfxRect_DrawTextured(layout->x, layout->y, texture[0], layout->bounds[3] - layout->y, 0, 0, 0x400,
                                         0x400, 0);
                    break;
            }
            break;
    }
}

extern void func_800504BC(s16 *);

void func_87F0A91C(s32 arg0, u8 *arg1) {
    struct { s16 position[2]; u32 unused; } scratch;
    u8 *entry;

    switch (arg0) {
        case 0:
            entry = *(u8 **)(arg1 + 0x20);
            func_800504BC(scratch.position);
            *(s16 *)(entry + 4) = *(s16 *)(arg1 + 8) + scratch.position[0];
            *(s16 *)(entry + 6) = *(s16 *)(arg1 + 0xA) + scratch.position[1];
            break;
        case 1:
            break;
    }
}

struct TargetGraphNode;
extern void func_8004E308(struct TargetGraphNode *, s32 (*)(s32, struct TargetGraphNode *), void *);
void func_87F0A714(s32, Fragment64BarNode *);
void func_87F0A988(TreeNode_80050428 *arg0, s32 arg1, s32 arg2, s32 arg3, u32 *arg4, u32 *arg5) {
    u8 *first;
    u8 *second;

    first = func_8005049C(arg0, arg2);
    if (first == NULL) {
        func_87F0A5F0(arg2);
        return;
    }
    second = func_8005049C(arg0, arg3);
    if (second == NULL) {
        func_87F0A5F0(arg3);
        return;
    }
    func_87F0A66C(first, arg4, arg5);
    func_87F0A66C(second, arg4, arg5);
    func_8004E308((struct TargetGraphNode *)first, (s32 (*)(s32, struct TargetGraphNode *))func_87F0A714, (void *)func_87F0A61C());
    func_8004E308((struct TargetGraphNode *)second, (s32 (*)(s32, struct TargetGraphNode *))func_87F0A91C, (void *)func_87F0A61C());
    **(s32 **)(first + 0x20) = arg1;
    **(s32 **)(second + 0x20) = arg1;
    *(void **)(*(u8 **)(first + 0x20) + 8) = *(void **)(second + 0x20);
    *(void **)(*(u8 **)(second + 0x20) + 8) = NULL;
}

#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

M2C_UNK func_8005053C(u8 *, s32);                 /* extern */
M2C_UNK func_80050578(u8 *, s32);                 /* extern */

void func_87F0AA80(TreeNode_80050428 *arg0, s32 arg1, s32 arg2) {
    u8 *sp24;
    s32 sp20;
    s32 sp1C;
    s32 temp_v0;

    sp24 = func_8005049C(arg0, arg1);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    sp20 = MainPool_AllocAligned(temp_v0, 0xC, 4);
    MainPool_FinalizeAllocation(sp1C);
    if (sp24 == NULL) {
        func_87F0A5F0(arg1);
        return;
    }
    func_8005053C(sp24, sp20);
    func_80050578(sp24, arg2);
}
/* Warning: struct TreeNode_80050428 is not defined (only forward-declared) */
typedef struct TargetGraphNode TargetGraphNode;
typedef s32 (*TargetGraphCallback)(s32, TargetGraphNode *);
extern void func_8004E308(TargetGraphNode *, TargetGraphCallback, void *);
void *func_87F0AB08(TreeNode_80050428 *arg0, s32 arg1, void (*arg2)(s32, u8 *), void *arg3) {
    void *entry = func_8005049C(arg0, arg1);

    if (entry == NULL) {
        func_87F0A5F0(arg1);
    } else {
        func_8004E308(entry, (TargetGraphCallback)arg2, arg3);
    }
    return entry;
}
#endif
