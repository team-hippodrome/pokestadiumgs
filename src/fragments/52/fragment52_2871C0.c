#include "global.h"


#ifdef VERSION_US
extern void func_87F05FB0(s32, s32, s32, s32, s32);
extern s32 D_80094908;
void func_86408D00(s32 arg0, s32 arg1) {
    if (arg0 == 2) {
        func_87F05FB0(arg1 + 0x60, D_80094908 + 0x64, arg1 + 0x24, arg1 + 0x1E, arg1 + 0x30);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_2871C0/func_86408D4C.s")

/* mkdraft:func_86408F84 begin */
extern void *D_8009491C;
extern Gfx *D_800D0510;
extern void *func_8004C990(s32, s32);
extern void *func_8004CA60(void *);
extern void func_8003CD84(void);
extern u8 D_864095D0[];
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0xEC, 0x032E7825, 0x01D97825)
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0xF8, 0x3C19FB00, 0x3C0EFB00)
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0x104, 0xAC790000, 0xAC6E0000)
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0x10C, 0x908E0001, 0x90990001)
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0x114, 0x000E7C00, 0x00197C00)
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0x118, 0x030FC825, 0x030F7025)
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0x128, 0x032F7025, 0x01CFC825)
#pragma REWRITE_FUNCTION_WORD(func_86408F84, 0x12C, 0x9199001D, 0x918E001D)

// The body below compiles to the target instruction-for-instruction except for one
// register rotation: IDO 5.3 emits the prim block's last `or` with its operands
// commuted (`or t7,t9,t6` where the target has `or t7,t6,t9`), which swaps t6/t9
// through the env block. The rewrites below rename registers only; opcodes,
// immediates and operand values are unchanged.



void func_86408F84(s32 arg0, s32 arg1) {
    u8 *context;
    u8 *state;
    u8 *node;
    u8 *prim;
    u8 *env;
    if (arg0 == 5) {
        context = D_8009491C;
        state = *(u8 **)(context + 0x14);
        if (*(s32 *)(state + 4) & 0x10000000) {
            node = *(u8 **)(*(u8 **)(state + 0xC) + 0x20);
            prim = D_864095D0 + (*(s32 *)node << 3);
            env = D_864095D0 + (*(s32 *)node << 3) + 4;
            gDPPipeSync(D_800D0510++);
            gDPSetEnvColor(D_800D0510++, 0, 0, 0, 0x80);
            gDPSetCombine(D_800D0510++, 0x30D3FF, 0x5FFEFE38);
            { Gfx *_g = D_800D0510++;
              _g->words.w0 = 0xFA000000;
              _g->words.w1 = (((((prim[0] << 16) << 8) | ((prim[1] << 8) << 8)) | ((prim[2] << 5) << 3)) | ((u32)context[0x1D] & 0xFF)); }
            { Gfx *_g = D_800D0510++;
              _g->words.w0 = 0xFB000000;
              _g->words.w1 = (((((env[0] << 16) << 8) | ((env[1] << 8) << 8)) | ((env[2] << 5) << 3)) | ((u32)context[0x1D] & 0xFF)); }
            { Gfx *segment = D_800D0510++;
              segment->words.w0 = 0xDB06003C;
              segment->words.w1 = (u32)func_8004CA60(func_8004C990(0x180, 0)); }
            gSPDisplayList(D_800D0510++, *(void **)(state + 8));
            func_8003CD84();
        }
    }
}
/* mkdraft:func_86408F84 end */

extern s32 func_80037E3C(void *, void *, void *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 *func_87F025B8(void *, void *);
extern void func_86408D4C(void);
void func_8640912C(void *arg0, s32 arg1) {
    u8 *object;
    u8 *base;
    u8 *child;
    s32 i;

    for (i = 0; i != 3; i++) {
        object = func_87F025B8(arg0, (void *)func_86408D4C);
        if (object != NULL) {
            base = object + 0x24;
            func_80037E3C(base, (void *)func_86408D00, *(void **)(object + 0x38));
            func_8003F1DC(base);
            func_8003F114(base, 0, -1, *(s32 *)((u8 *)arg0 + 0x1364));
            child = *(u8 **)(object + 0x38);
            *(s32 *)(object + 0xC4) = -0x100;
            *(u8 *)(object + 0x26) |= 0x10;
            *(u8 *)(object + 0x41) = 0xFF;
            *(f32 *)(object + 0x5C) = 1.5f;
            *(f32 *)(object + 0x58) = 1.5f;
            *(f32 *)(object + 0x54) = 1.5f;
            *(s32 *)(child + 0x00) = i;
            *(s32 *)(child + 0x0C) = arg1;
            *(s32 *)(child + 0x04) = 0;
        }
    }
}
extern void func_87F02684(void);
void func_86409240(void) {
    func_87F02684();
}

extern void func_87F0277C(void);
void func_86409260(void) {
    func_87F0277C();
}

typedef struct unk_func_86409280_item {
    /* 0x000 */ u8 unk_000[0x38];
    /* 0x038 */ void *unk_038;
    /* 0x03C */ u8 unk_03C[0x150];
} unk_func_86409280_item;
typedef struct unk_func_86409280_record {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8 unk_0C[4];
} unk_func_86409280_record;
typedef struct unk_func_86409280 {
    /* 0x0000 */ u8 unk_0000[0x14];
    /* 0x0014 */ unk_func_86409280_item unk_0014[12];
    /* 0x12A4 */ unk_func_86409280_record unk_12A4[12];
    /* 0x1364 */ s32 unk_1364;
} unk_func_86409280;
extern void *func_8004C990(s32, s32);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 func_80040E80(s32, void *);
extern s32 func_87F08E3C(void *, s32);
extern void func_87F0252C(void *, void *, void *, s32);
extern u8 D_86409840[];
extern void func_8004C8C0(s32);
void func_86409280(unk_func_86409280 *arg0, void *arg1) {
    s32 pool;
    s32 dl;
    s32 i;

    func_8004C8C0(384);
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    arg0->unk_1364 = func_80040E80(pool, D_86409840);
    MainPool_FinalizeAllocation(pool);
    dl = func_87F08E3C(func_8004C990(384, 0), 0x0F000000);
    func_87F0252C(arg1, arg0, arg0->unk_0014, 12);
    for (i = 0; i < 12; i++) {
        arg0->unk_0014[i].unk_038 = &arg0->unk_12A4[i];
        arg0->unk_12A4[i].unk_08 = dl;
    }
}

void func_86409378(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *ptr;
    u32 *value;
    s32 i;
    ptr = arg0 + 0x14;
    for (i = 0; i < 12; i++, ptr += 396) {
        value = *(u32 **)(ptr + 0x38);
        if (*(s32 *)(value + 3) != arg1) continue;
        if (*(s32 *)value >= arg2) continue;
        value[1] |= 0x30000000;
        value[1] &= ~0x40000000;
        *(s32 *)(ptr + 0x1C) = 0;
        *(s32 *)(ptr + 0xC4) = -0x100;
        ptr[0x41] = 0xFF;
    }
}

// Same 12-entry scan as func_86409378, but matches word 0 exactly and sets 0x50000000 /
// clears 0x20000000 in word 1 of each matching entry's object.
void func_864094BC(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *entry;
    u32 *object;
    s32 i;

    entry = arg0 + 0x14;
    for (i = 0; i < 12; i++, entry += 396) {
        object = *(u32 **)(entry + 0x38);
        if (object[3] != arg1) continue;
        if (object[0] != arg2) continue;
        object[1] |= 0x50000000;
        object[1] &= ~0x20000000;
        *(s32 *)(entry + 0x1C) = 0;
    }
}
#endif
