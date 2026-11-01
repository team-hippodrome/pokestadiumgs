#include "global.h"


#ifdef VERSION_US
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern s32 MainPool_AllocAligned(void *, s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void *func_80040E80(void *, void *);
extern s32 func_8004C8C0(u16);
extern void func_87F024F4(void *, u8 *, s32);
extern u8 D_87F0FAA8[];

void func_87F03BB0(u8 *arg0, s32 arg1) {
    s32 i;
    u8 *pool;

    pool = MainPool_AllocState(main_pool_get_available(), 0);
    *(u8 **)(arg0 + 20) = (u8 *)MainPool_AllocAligned(pool, arg1 * 396, 4);
    *(u8 **)(arg0 + 24) = (u8 *)MainPool_AllocAligned(pool, arg1 * 32, 4);
    *(void **)(arg0 + 28) = func_80040E80(pool, D_87F0FAA8);
    MainPool_FinalizeAllocation(pool);
    func_8004C8C0(159);
    func_87F024F4(arg0, *(u8 **)(arg0 + 20), arg1);
    for (i = 0; i < arg1; i++) {
        *(u8 **)(*(u8 **)(arg0 + 24) + i * 32 + 8) = arg0;
        *(u8 **)(*(u8 **)(arg0 + 20) + i * 396 + 32) = *(u8 **)(arg0 + 24) + i * 32;
    }
}

extern u16 D_80094904;
extern void *D_80094908;
extern void func_87F026E8(void *, u8 *);
extern void func_87F05FB0(f32 [4][4], f32 [4][4], f32 *, u16 *, void *);
s32 func_87F03D9C(s32 arg0, u8 *arg1) {
    u8 *object;
    f32 *scale;
    u8 *record;

    object = *(u8 **)(arg1 + 20);
    record = *(u8 **)(object + 32);
    if (D_80094904 != *(u16 *)(record + 14) && arg0 == 2) {
        *(s32 *)(object + 28) += 1;
        *(u16 *)(record + 28) += *(u16 *)(record + 30);
        if (*(s32 *)(object + 28) > *(s32 *)(record + 4)) {
            func_87F026E8(*(void **)(record + 8), object);
        } else {
            scale = (f32 *)(object + 84);
            *(f32 *)(object + 72) += *(f32 *)(object + 16);
            *(f32 *)(object + 76) += *(f32 *)(object + 20);
            *(f32 *)(object + 80) += *(f32 *)(object + 24);
            *(s16 *)(object + 70) += *(s16 *)(record + 20);
            scale[0] *= *(f32 *)(record + 24);
            scale[1] *= *(f32 *)(record + 24);
            scale[2] *= *(f32 *)(record + 24);
            func_87F05FB0((f32 (*)[4])(object + 132),
                          (f32 (*)[4])((u8 *)D_80094908 + 100),
                          (f32 *)(object + 72), (u16 *)(object + 66), scale);
        }
    }
    *(u16 *)(record + 14) = D_80094904;
    //!bug The graph dispatcher consumes a result, but this callback defines none.
    //@src/340C0.c
}

extern f32 D_87F11480;
extern f32 D_87F11484;
void func_87F03EDC(u8 *arg0, u8 *arg1) {
    switch (arg1[0xC]) {
    case 0:
        *(f32 *)(arg1 + 0x18) = D_87F11480;
        *(s16 *)(arg1 + 0x14) = 0xF;
        break;
    case 1:
        *(f32 *)(arg0 + 0x14) = *(f32 *)arg1;
        *(f32 *)(arg1 + 0x18) = D_87F11484;
        *(s16 *)(arg1 + 0x14) = 0xFF;
        break;
    }
}

extern void *func_87F025B8(void *, void *);
extern void func_80037E3C(void *, void *, void *);
extern void func_8003F1DC(void *);
extern void *func_8003F114(void *, s32, s32, s32);
extern s32 func_87F03D9C(s32, u8 *);

u8 *func_87F03F38(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    u8 *obj;
    u8 *sub;

    obj = func_87F025B8(arg0, NULL);
    if (obj != NULL) {
        func_80037E3C(obj + 0x24, func_87F03D9C, obj);
        func_8003F1DC(obj + 0x24);
        func_8003F114(obj + 0x24, 0, -1, *(s32 *)(arg0 + 0x1C));
        sub = *(u8 **)(obj + 0x20);
        *(u8 *)(obj + 0x26) |= 0x10;
        *(f32 *)(obj + 0x48) = arg2;
        *(f32 *)(obj + 0x4C) = arg3;
        *(f32 *)(obj + 0x50) = arg4;
        *(f32 *)(obj + 0x54) = arg5;
        *(f32 *)(obj + 0x58) = arg5;
        *(f32 *)(obj + 0x5C) = arg5;
        *(u8 *)(sub + 0xC) = arg1;
        *(s32 *)(sub + 0x4) = arg6;
        *(f32 *)(sub + 0x0) = arg5;
        *(s32 *)(sub + 0x10) = -1;
        *(s16 *)(sub + 0x1C) = 0;
        *(s16 *)(sub + 0x1E) = 0x80;
        func_87F03EDC(obj, sub);
    }
    return obj;
}
/* mkdraft:func_87F04018 begin */
typedef struct unk_func_87F04018_color {
    u8 r, g, b, a;
} unk_func_87F04018_color;

typedef struct unk_func_87F04018 {
    f32 unk_00;
    s32 unk_04;
    void *unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u16 unk_0E;
    unk_func_87F04018_color environment;
    f32 unk_14;
    f32 unk_18;
    u16 unk_1C;
    u8 unk_1E[2];
} unk_func_87F04018;

extern void *D_8009491C;
extern Gfx *D_800D0510;
extern u8 D_87F0F670[];
extern Gfx D_87F0FA40[];
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);



void func_87F04018(s32 arg0, s32 arg1) {
    // Declaration order fixes IDO's stack slots: scale spills to 0x18(sp) and state to 0x24(sp).
    void *context;
    void *node;
    unk_func_87F04018 *state;
    s32 index;
    u8 *pixels;
    f32 scale;

    if (arg0 == 5) {
        context = D_8009491C;
        node = *(void **)((u8 *)context + 20);
        state = *(unk_func_87F04018 **)((u8 *)node + 32);
        scale = 2.0f * (1.0f - (f32)(*(s32 *)((u8 *)node + 28)) / (f32)state->unk_04);
        if (scale > 1.0f) {
            scale = 1.0f;
        }
        // High byte of the u16 at state+0x1C selects the byte D_87F0F670 passes to func_8004C990.
        index = (state->unk_1C >> 8) % 8;
        pixels = func_8004CA60((u8 *)func_8004C990(159, D_87F0F670[index]));
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, state->environment.r, state->environment.g,
                       state->environment.b, (u32)((f32)state->environment.a * scale));
        gDPSetPrimColor(D_800D0510++, 0, 0, state->environment.r, state->environment.g,
                        state->environment.b, 0xFF);
        gSPSegment(D_800D0510++, 0xF, pixels);
        gSPDisplayList(D_800D0510++, D_87F0FA40);
        func_8003CD84();
    }
}
/* mkdraft:func_87F04018 end */
#endif
