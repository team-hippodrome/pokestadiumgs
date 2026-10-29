#include "global.h"


#ifdef VERSION_US
extern void func_87F02CE0(void *, u8 *, s32);
extern u8 D_80126420;

void func_87F02CB0(s32 arg0, s32 arg1) {
    func_87F02CE0(&D_80126420, (u8 *)arg0, arg1);
}

extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern s32 MainPool_AllocAligned(void *, s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void *func_80040E80(void *, void *);
extern s32 func_8004C8C0(u16);
extern void func_87F0252C(void *, void *, u8 *, s32);
extern u8 D_87F0F808[];

void func_87F02CE0(void *arg0, u8 *arg1, s32 arg2) {
    s32 i;
    u8 *pool;

    pool = MainPool_AllocState(main_pool_get_available(), 0);
    *(u8 **)(arg1 + 20) = (u8 *)MainPool_AllocAligned(pool, arg2 * 396, 4);
    *(u8 **)(arg1 + 24) = (u8 *)MainPool_AllocAligned(pool, arg2 * 52, 4);
    *(void **)(arg1 + 28) = func_80040E80(pool, D_87F0F808);
    MainPool_FinalizeAllocation(pool);
    func_8004C8C0(147);
    func_87F0252C(arg0, arg1, *(u8 **)(arg1 + 20), arg2);
    for (i = 0; i < arg2; i++) {
        *(u8 **)(*(u8 **)(arg1 + 24) + i * 52 + 8) = arg1;
        *(u8 **)(*(u8 **)(arg1 + 20) + i * 396 + 32) = *(u8 **)(arg1 + 24) + i * 52;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_325920/func_87F02F00.s")

void func_87F03204(void *arg0, void *arg1)
{
  u8 temp_v0;
  temp_v0 = *((u8 *) (((u8 *) arg1) + 0xC));
  switch (temp_v0)
  {
    case 0:
      *((f32 *) (((u8 *) arg1) + 0x18)) = 1.0f;
      *((s16 *) (((u8 *) arg1) + 0x1C)) = 0x1FF;
      return;

    case 1:
      *((f32 *) (((u8 *) arg0) + 0x14)) = (f32) (-(*((f32 *) (((u8 *) arg1) + 0))));
      *((s16 *) (((u8 *) arg1) + 0x1C)) = 0x1FF;
      *((f32 *) (((u8 *) arg1) + 0x18)) = 1.0f;
      return;

    case 2:

    case 3:
      *((s16 *) (((u8 *) arg1) + 0x1C)) = 0x2FF;
      *((f32 *) (((u8 *) arg1) + 0x18)) = 1.0f;
      return;

  }

}
typedef struct unk_func_87F0328C {
    f32 unk_00;
    s32 unk_04;
    void *unk_08;
    u8 mode;
    u8 unk_0D;
    u16 unk_0E;
    u32 environment;
    u32 primitive;
    f32 unk_18;
    s16 unk_1C;
    u8 unk_1E[2];
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    s32 unk_2C;
    f32 unk_30;
} unk_func_87F0328C;

typedef struct S1_GraphNode S1_GraphNode;
extern void *func_87F025B8(void *, void *);
extern s32 func_87F02F00(s32, S1_GraphNode *);
extern void func_80037E3C(S1_GraphNode *, s32 (*)(s32, S1_GraphNode *), void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
void *func_87F0328C(u8 *arg0, s32 arg1, f32 x, f32 y, f32 z, f32 scale, s32 arg6) {
    u8 *object;
    u8 *model;
    unk_func_87F0328C *state;

    object = func_87F025B8(arg0, NULL);
    if (object != NULL) {
        model = object + 36;
        func_80037E3C((S1_GraphNode *)model, func_87F02F00, object);
        func_8003F1DC(model);
        func_8003F114(model, 0, -1, *(void **)(arg0 + 28));
        object[38] |= 0x10;
        state = *(unk_func_87F0328C **)(object + 32);
        *(f32 *)(object + 72) = x;
        *(f32 *)(object + 76) = y;
        *(f32 *)(object + 80) = z;
        *(f32 *)(object + 84) = scale;
        *(f32 *)(object + 88) = scale;
        *(f32 *)(object + 92) = scale;
        state->mode = arg1;
        state->unk_04 = arg6;
        state->unk_00 = scale;
        state->environment = 0xFFFFFFFF;
        state->primitive = 0xFFFF00FF;
        state->unk_18 = 1.0f;
        state->unk_30 = 128.0f * scale;
        state->unk_2C = 0;
        state->unk_20 = 0.0f;
        state->unk_24 = 0.0f;
        state->unk_28 = 0.0f;
        func_87F03204(object, state);
    }
    return object;
}

typedef struct unk_func_87F0339C_color {
    u8 r, g, b, a;
} unk_func_87F0339C_color;

typedef struct unk_func_87F0339C {
    u8 unk_00[16];
    unk_func_87F0339C_color environment;
    unk_func_87F0339C_color primitive;
} unk_func_87F0339C;

extern void *D_8009491C;
extern Gfx *D_800D0510;
extern Gfx D_87F0F7A0[];
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);
void func_87F0339C(s32 arg0, void *arg1) {
    void *context;
    void *node;
    unk_func_87F0339C *state;
    u8 *pixels;

    if (arg0 == 5) {
        context = D_8009491C;
        node = *(void **)((u8 *)context + 20);
        state = *(unk_func_87F0339C **)((u8 *)node + 32);
        pixels = func_8004CA60((u8 *)func_8004C990(147, 0));
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, state->environment.r, state->environment.g,
                      state->environment.b, state->environment.a);
        gDPSetPrimColor(D_800D0510++, 0, 0, state->primitive.r, state->primitive.g,
                       state->primitive.b, state->primitive.a);
        gSPSegment(D_800D0510++, 15, pixels);
        gSPDisplayList(D_800D0510++, D_87F0F7A0);
        func_8003CD84();
    }
}

extern void func_87F02684();

void func_87F034CC(void) {
    func_87F02684();
}
#endif
