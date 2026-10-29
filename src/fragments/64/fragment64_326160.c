#include "global.h"


#ifdef VERSION_US
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern s32 MainPool_AllocAligned(void *, s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void *func_80040E80(void *, void *);
extern s32 func_8004C8C0(u16);
extern void func_87F0252C(void *, void *, u8 *, s32);
extern u8 D_87F0F8E8[];
extern u8 D_87F0F9C8[];

void func_87F034F0(void *arg0, u8 *arg1, s32 arg2) {
    s32 i;
    u8 *pool;

    pool = MainPool_AllocState(main_pool_get_available(), 0);
    *(u8 **)(arg1 + 20) = (u8 *)MainPool_AllocAligned(pool, arg2 * 396, 4);
    *(u8 **)(arg1 + 24) = (u8 *)MainPool_AllocAligned(pool, arg2 * 32, 4);
    *(void **)(arg1 + 28) = func_80040E80(pool, D_87F0F8E8);
    *(void **)(arg1 + 32) = func_80040E80(pool, D_87F0F9C8);
    MainPool_FinalizeAllocation(pool);
    func_8004C8C0(224);
    func_8004C8C0(225);
    func_87F0252C(arg0, arg1, *(u8 **)(arg1 + 20), arg2);
    for (i = 0; i < arg2; i++) {
        *(u8 **)(*(u8 **)(arg1 + 24) + i * 32) = arg1;
        *(u8 **)(*(u8 **)(arg1 + 20) + i * 396 + 32) = *(u8 **)(arg1 + 24) + i * 32;
    }
}

extern void func_87F034F0(void *, u8 *, s32);
extern u8 D_80126420;

void func_87F03700(s32 arg0, s32 arg1) {
    func_87F034F0(&D_80126420, (u8 *)arg0, arg1);
}

extern u16 D_80094904;
extern void *D_80094908;
extern void func_87F026E8(void *, u8 *);
extern void func_87F05FB0(f32 [4][4], f32 [4][4], f32 *, u16 *, void *);
s32 func_87F03730(s32 arg0, u8 *arg1) {
    u8 *object;
    f32 *scale;
    u8 *record;

    object = *(u8 **)(arg1 + 20);
    record = *(u8 **)(object + 32);
    if (D_80094904 != *(u16 *)(record + 24) && arg0 == 2) {
        *(s32 *)(object + 28) += 1;
        *(u16 *)(record + 26) += 1;
        if (*(s32 *)(object + 28) > *(s32 *)(record + 20)) {
            func_87F026E8(*(void **)record, object);
        } else {
            scale = (f32 *)(object + 84);
            switch (record[28]) {
            case 0:
                *(s16 *)(object + 70) += 127;
                break;
            case 1:
                break;
            }
            *(f32 *)(object + 72) = *(f32 *)(record + 4);
            *(f32 *)(object + 76) = *(f32 *)(record + 8);
            *(f32 *)(object + 80) = *(f32 *)(record + 12);
            if (*(u8 **)(record + 16) != NULL) {
                *(f32 *)(object + 72) += *(f32 *)(*(u8 **)(record + 16) + 36);
                *(f32 *)(object + 76) += *(f32 *)(*(u8 **)(record + 16) + 40);
                *(f32 *)(object + 80) += *(f32 *)(*(u8 **)(record + 16) + 44);
            }
            func_87F05FB0((f32 (*)[4])(object + 132),
                          (f32 (*)[4])((u8 *)D_80094908 + 100), (f32 *)(object + 72),
                          (u16 *)(object + 66), scale);
        }
    }
    *(u16 *)(record + 24) = D_80094904;
    //!bug The graph dispatcher consumes a result, but this callback defines none.
    //@src/340C0.c
}

extern void *func_87F025B8(void *, void *);
extern void func_80037E3C(void *, s32 (*)(s32, u8 *), void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
u8 *func_87F03884(u8 *arg0, s32 arg1, void *arg2, f32 arg3, f32 arg4,
                     f32 arg5, s16 arg6, f32 arg7, s32 arg8) {
    u8 *object;
    u8 *record;

    object = func_87F025B8(arg0, NULL);
    if (object != NULL) {
        func_80037E3C(object + 36, func_87F03730, object);
        func_8003F1DC(object + 36);
        switch (arg1) {
        case 0:
            func_8003F114(object + 36, 0, -1, *(void **)(arg0 + 28));
            break;
        case 1:
            func_8003F114(object + 36, 0, -1, *(void **)(arg0 + 28));
            break;
        }
        record = *(u8 **)(object + 32);
        object[38] |= 0x10;
        record[28] = arg1;
        *(s32 *)(record + 20) = arg8;
        *(u16 *)(record + 24) = D_80094904;
        *(u16 *)(record + 26) = 0;
        *(f32 *)(record + 4) = arg3;
        *(f32 *)(record + 8) = arg4;
        *(f32 *)(record + 12) = arg5;
        *(void **)(record + 16) = arg2;
        *(f32 *)(object + 72) = arg3;
        *(f32 *)(object + 76) = *(f32 *)(record + 8);
        *(f32 *)(object + 80) = *(f32 *)(record + 12);
        if (*(u8 **)(record + 16) != NULL) {
            *(f32 *)(object + 72) += *(f32 *)(*(u8 **)(record + 16) + 36);
            *(f32 *)(object + 76) += *(f32 *)(*(u8 **)(record + 16) + 40);
            *(f32 *)(object + 80) += *(f32 *)(*(u8 **)(record + 16) + 44);
        }
        *(f32 *)(object + 84) = arg7;
        *(f32 *)(object + 88) = arg7;
        *(f32 *)(object + 92) = arg7;
        *(s16 *)(object + 70) = arg6;
    }
    return object;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_326160/func_87F039F0.s")

extern void func_87F02684(void);
void func_87F03B8C(void) {
    func_87F02684();
}
#endif
