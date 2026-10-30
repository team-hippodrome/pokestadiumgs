#include "global.h"


#ifdef VERSION_US
typedef struct F2340Node {
    u8 pad_00[4];
    struct F2340Node *prev;
    struct F2340Node *next;
} F2340Node;
typedef struct {
    u8 pad_00[0xC];
    F2340Node *child;
} F2340State;
extern void GraphNode_RemoveChild(F2340State *, F2340Node *);
void func_87F02340(F2340State *arg0) {
    F2340Node *node;
    node = arg0->child;
    while (node) {
        GraphNode_RemoveChild(arg0, node);
        node = arg0->child;
    }
}

typedef struct {
    s32 count;
    u8 pad_04[4];
    u8 *items;
} F2684State;
extern void func_87F026E8(F2684State *, u8 *);


extern u8 D_80126420[];
extern void func_87F023B0(void *, F2684State *);

void func_87F02388(void *arg0) {
    func_87F023B0(D_80126420, arg0);
}

void func_87F023B0(void *arg0, F2684State *arg1) {
    u8 *item;
    s32 i;

    item = arg1->items;
    i = 0;
    while (i < arg1->count) {
        func_87F026E8(arg1, item);
        GraphNode_RemoveChild(arg0, (F2340Node *)(item + 0x24));
        i += 1;
        item += 0x18C;
    }
}

void func_87F0242C(void *arg0) {
    *(s16 *)((u8 *)arg0 + 0x22) = 0;
    *(s16 *)((u8 *)arg0 + 0x20) = *(s16 *)((u8 *)arg0 + 0x22);
    *(s16 *)((u8 *)arg0 + 0x1E) = *(s16 *)((u8 *)arg0 + 0x22);
    *(f32 *)((u8 *)arg0 + 0x2C) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x28) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x24) = 1.0f;
    *(s16 *)((u8 *)arg0 + 0x18) = 0;
    *(s16 *)((u8 *)arg0 + 0x1A) = 0;
    ((u8 *)arg0)[0x1D] = 0xFF;
    ((u8 *)arg0)[0x1C] = 0;
    *(s32 *)((u8 *)arg0 + 0xA0) = -0x100;
    *(s32 *)((u8 *)arg0 + 0x3C) = -0x100;
    *(s16 *)((u8 *)arg0 + 0x40) = 0;
    *(s32 *)((u8 *)arg0 + 0x44) = 0;
    *(s32 *)((u8 *)arg0 + 0x48) = 0;
    *(s32 *)((u8 *)arg0 + 0x4C) = 0x10000;
    *(s16 *)((u8 *)arg0 + 0x52) = 0;
    *(s16 *)((u8 *)arg0 + 0x54) = 0;
    *(s32 *)((u8 *)arg0 + 0x58) = 0;
    *(s16 *)((u8 *)arg0 + 0x5C) = 0;
    // karodo: always-true block around the second group; without it IDO drops the first +0x1E/+0x20 stores.
    if (1) {
        *(s16 *)((u8 *)arg0 + 0x5E) = 0;
        ((u8 *)arg0)[2] = 0;
        ((u8 *)arg0)[3] = 0;
        *(f32 *)((u8 *)arg0 + 0x38) = 1.0f;
        *(f32 *)((u8 *)arg0 + 0x34) = 1.0f;
        *(f32 *)((u8 *)arg0 + 0x30) = 1.0f;
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        *(f32 *)((u8 *)arg0 + 0x28) = 0.0f;
        *(f32 *)((u8 *)arg0 + 0x2C) = 0.0f;
    }
    *(s16 *)((u8 *)arg0 + 0x20) = *(s16 *)((u8 *)arg0 + 0x22);
    *(s16 *)((u8 *)arg0 + 0x1E) = *(s16 *)((u8 *)arg0 + 0x22);
}

extern u32 D_87F119C0;
extern void GeoNode_CreateContainer(s32, void *);
void func_87F024CC(void) {
    GeoNode_CreateContainer(0, &D_87F119C0);
}

extern void func_87F0252C(void *, F2684State *, u8 *, s32);

void func_87F024F4(F2684State *arg0, u8 *arg1, s32 arg2) {
    func_87F0252C(D_80126420, arg0, arg1, arg2);
}

extern void func_8003F03C(s32, void *);
void func_87F0252C(void *arg0, F2684State *arg1, u8 *arg2, s32 arg3) {
    s32 i;

    arg1->count = arg3;
    *(s32 *)((u8 *)arg1 + 4) = 0;
    arg1->items = arg2;
    *(s32 *)((u8 *)arg1 + 0xC) = 0;
    *(s32 *)((u8 *)arg1 + 0x10) = 0;
    for (i = 0; i < arg1->count; i++) {
        *(s32 *)(arg2 + 0xC) = 0;
        *(s32 *)arg2 = 0;
        *(s32 *)(arg2 + 4) = 0;
        func_8003F03C((s32)(arg2 + 0x24), arg0);
        arg2 += 0x18C;
    }
}

/* mkdraft:func_87F025B8 begin */
#pragma REWRITE_FUNCTION_WORD(func_87F025B8, 0x80, 0x8CC20010, 0x8CCA0010)
#pragma REWRITE_FUNCTION_WORD(func_87F025B8, 0x90, 0xAC620000, 0xAC6A0000)
#pragma REWRITE_FUNCTION_WORD(func_87F025B8, 0x94, 0x8CCA000C, 0x8CCB000C)
#pragma REWRITE_FUNCTION_WORD(func_87F025B8, 0x98, 0x55400003, 0x55600003)
extern void func_87F0242C(void *);

void *func_87F025B8(void *arg0, void *arg1) {
    void *var_v1;
    void *var_v0;

    var_v1 = NULL;
    if (*(s32 *)((u8 *)arg0 + 4) < *(s32 *)((u8 *)arg0 + 0)) {
        var_v0 = *(void **)((u8 *)arg0 + 8);
        do {
            if (*(s32 *)((u8 *)var_v0 + 0xC) == 0) {
                var_v1 = var_v0;
            } else {
                var_v0 = (void *)((u8 *)var_v0 + 0x18C);
            }
        } while (var_v1 == NULL);
        *(s32 *)((u8 *)var_v1 + 0xC) = 1;
        *(s32 *)((u8 *)var_v1 + 8) = arg1;
        *(s32 *)((u8 *)var_v1 + 0x1C) = 0;
        *(f32 *)((u8 *)var_v1 + 0x18) = 0.0f;
        *(f32 *)((u8 *)var_v1 + 0x14) = 0.0f;
        *(f32 *)((u8 *)var_v1 + 0x10) = 0.0f;
        func_87F0242C((u8 *)var_v1 + 0x24);
        *(s32 *)((u8 *)arg0 + 4) += 1;
        {
            void *temp;
            temp = *(void **)((u8 *)arg0 + 0x10);
            *(s32 *)((u8 *)var_v1 + 4) = 0;
            *(void **)((u8 *)var_v1 + 0) = temp;
        }
        if (*(void **)((u8 *)arg0 + 0xC) == NULL) {
            *(void **)((u8 *)arg0 + 0xC) = var_v1;
        }
        if (*(void **)((u8 *)arg0 + 0x10) != NULL) {
            *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x10) + 4) = var_v1;
        }
        *(void **)((u8 *)arg0 + 0x10) = var_v1;
    }
    return var_v1;
}
/* mkdraft:func_87F025B8 end */


void func_87F02684(F2684State *arg0) {
    u8 *item;
    s32 i;
    item = arg0->items;
    i = 0;
    while (i < arg0->count) {
        func_87F026E8(arg0, item);
        i += 1;
        item += 0x18C;
    }
}

extern void func_8003F1DC(void *);
// Releases an active 0x18C-byte item: clears its active flag (+0xC) and unlinks
// it from the state's active list (head +0xC, tail +0x10, count +4), the inverse
// of the append in func_87F025B8. Items link through prev (+0) and next (+4).
void func_87F026E8(F2684State *state, u8 *item) {
    u8 *neighbor;

    if (*(s32 *)(item + 0xC) & 1) {
        func_8003F1DC(item + 0x24);
        *(s32 *)(item + 0xC) = 0;
        neighbor = *(u8 **)item;
        if (neighbor != NULL) {
            *(u8 **)(neighbor + 4) = *(u8 **)(item + 4);
        } else {
            *(u8 **)((u8 *)state + 0xC) = *(u8 **)(item + 4);
        }
        neighbor = *(u8 **)(item + 4);
        if (neighbor != NULL) {
            *(u8 **)neighbor = *(u8 **)item;
        } else {
            *(u8 **)((u8 *)state + 0x10) = *(u8 **)item;
        }
        *(s32 *)((u8 *)state + 4) -= 1;
    }
}

typedef struct unk_func_87F0277C {
    struct unk_func_87F0277C *unk_00;
    struct unk_func_87F0277C *unk_04;
    void (*unk_08)(void);
    u32 unk_0C;
    u8 unk_10[12];
    s32 unk_1C;
} unk_func_87F0277C;

extern void *D_87F119D8;
extern unk_func_87F0277C *D_87F119DC;
void func_87F0277C(void *arg0) {
    D_87F119D8 = arg0;
    D_87F119DC = *(unk_func_87F0277C **)((u8 *)arg0 + 12);
    while (D_87F119DC != NULL) {
        if (D_87F119DC->unk_0C & 1) {
            if (D_87F119DC->unk_08 != NULL) {
                D_87F119DC->unk_08();
            }
            D_87F119DC->unk_1C++;
        }
        D_87F119DC = D_87F119DC->unk_04;
    }
}

s32 func_87F02800(s32 arg0, u8 *arg1) {
    u8 *resource;
    u8 *position;

    if (arg0 == 2) {
        resource = *(u8 **)(arg1 + 0x14);
        position = *(u8 **)(resource + 0x20);
        *(f32 *)(arg1 + 0x24) = *(f32 *)(position + 4);
        *(f32 *)(arg1 + 0x28) = *(f32 *)(position + 8);
        *(f32 *)(arg1 + 0x2C) = *(f32 *)(position + 0xC);
        if (*(u8 **)position != NULL) {
            *(f32 *)(arg1 + 0x24) += *(f32 *)(*(u8 **)position + 0x24);
            *(f32 *)(arg1 + 0x28) += *(f32 *)(*(u8 **)position + 0x28);
            *(f32 *)(arg1 + 0x2C) += *(f32 *)(*(u8 **)position + 0x2C);
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_324FB0/func_87F02878.s")

extern u32 D_87F119C0;
extern void func_87F029EC(void *, u8 *, u8);
void func_87F029B8(s32 arg0, u8 arg1) {
    func_87F029EC(&D_87F119C0, (u8 *)arg0, arg1);
}

extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern s32 MainPool_AllocAligned(void *, s32, s32);
extern void *func_80040E80(void *, void *);
extern void MainPool_FinalizeAllocation(void *);
extern s32 func_8004C8C0(u16);
extern void func_80037E3C(void *, s32 (*)(s32, u8 *), void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void *Vec3f_SetComponentsDuplicate(void *, f32, f32, f32);
extern u8 D_87F0F728[];

void func_87F029EC(void *arg0, u8 *arg1, u8 arg2) {
    u8 *pool;
    u8 *object;
    u8 *model;
    s32 i;
    s32 offset;

    pool = MainPool_AllocState(main_pool_get_available(), 0);
    *(u8 **)(arg1 + 20) = (u8 *)MainPool_AllocAligned(pool, 1584, 4);
    *(u8 **)(arg1 + 24) = (u8 *)MainPool_AllocAligned(pool, 96, 4);
    *(void **)(arg1 + 28) = func_80040E80(pool, D_87F0F728);
    MainPool_FinalizeAllocation(pool);
    func_8004C8C0(434);
    func_87F0252C(arg0, (F2684State *)arg1, *(u8 **)(arg1 + 20), 4);
    for (i = 0; i != 4; i++) {
        object = func_87F025B8(arg1, NULL);
        if (object != NULL) {
            offset = i * 24;
            model = object + 36;
            func_80037E3C(model, func_87F02800, object);
            *(u8 **)(object + 32) = *(u8 **)(arg1 + 24) + offset;
            func_8003F1DC(model);
            func_8003F114(model, 0, -1, *(void **)(arg1 + 28));
            object[38] |= 8;
        }
    }
    (*(u8 **)(arg1 + 24))[18] = 0xFF;
    (*(u8 **)(arg1 + 24))[19] = 0xFF;
    (*(u8 **)(arg1 + 24))[20] = 0xFF;
    (*(u8 **)(arg1 + 24))[21] = 0xFF;
    (*(u8 **)(arg1 + 24))[17] = arg2 & 1;
    (*(u8 **)(arg1 + 24))[16] = 0;
    *(s32 *)(*(u8 **)(arg1 + 24) + 0) = 0;
    Vec3f_SetComponentsDuplicate(*(u8 **)(arg1 + 24) + 4, 0.0f, 0.0f, 0.0f);
    (*(u8 **)(arg1 + 24))[42] = 0xFF;
    (*(u8 **)(arg1 + 24))[43] = 0xFF;
    (*(u8 **)(arg1 + 24))[44] = 0xFF;
    (*(u8 **)(arg1 + 24))[45] = 0xFF;
    (*(u8 **)(arg1 + 24))[41] = arg2 & 2;
    (*(u8 **)(arg1 + 24))[40] = 1;
    *(s32 *)(*(u8 **)(arg1 + 24) + 24) = 0;
    Vec3f_SetComponentsDuplicate(*(u8 **)(arg1 + 24) + 28, 0.0f, 0.0f, 0.0f);
    (*(u8 **)(arg1 + 24))[66] = 0xFF;
    (*(u8 **)(arg1 + 24))[67] = 0xFF;
    (*(u8 **)(arg1 + 24))[68] = 0xFF;
    (*(u8 **)(arg1 + 24))[69] = 0xFF;
    (*(u8 **)(arg1 + 24))[65] = arg2 & 4;
    (*(u8 **)(arg1 + 24))[64] = 2;
    *(s32 *)(*(u8 **)(arg1 + 24) + 48) = 0;
    Vec3f_SetComponentsDuplicate(*(u8 **)(arg1 + 24) + 52, 0.0f, 0.0f, 0.0f);
    (*(u8 **)(arg1 + 24))[90] = 0xFF;
    (*(u8 **)(arg1 + 24))[91] = 0xFF;
    (*(u8 **)(arg1 + 24))[92] = 0xFF;
    (*(u8 **)(arg1 + 24))[93] = 0xFF;
    (*(u8 **)(arg1 + 24))[89] = arg2 & 8;
    (*(u8 **)(arg1 + 24))[88] = 3;
    *(s32 *)(*(u8 **)(arg1 + 24) + 72) = 0;
    Vec3f_SetComponentsDuplicate(*(u8 **)(arg1 + 24) + 76, 0.0f, 0.0f, 0.0f);
}
#endif
