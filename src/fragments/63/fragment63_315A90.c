#include "global.h"


#ifdef VERSION_US
extern void *D_87F119DC;
extern u8 D_87E1AC24[];
extern void func_87F0B4AC(void *, f32 *, f32 *, s16 *);
extern void func_87F0D1A8(void *, void *, s32, s32, s32);
void func_87E12120(void) {
    s32 temp_v1;
    s32 temp_v0;

    temp_v1 = *(s32 *)((u8 *)D_87F119DC + 0x38);
    func_87F0B4AC((void *)(temp_v1 + 0xC),
        (f32 *)((u8 *)D_87F119DC + 0x48),
        (f32 *)((u8 *)D_87F119DC + 0x54),
        (s16 *)((u8 *)D_87F119DC + 0x42));
    temp_v0 = *(s32 *)(temp_v1 + 0x0);
    if ((temp_v0 == 4) || (temp_v0 == 5) ||
        (temp_v0 == 6) || (temp_v0 == 7)) {
        func_87F0D1A8((u8 *)D_87F119DC + 0x60, &D_87E1AC24,
            6, *(s32 *)((u8 *)D_87F119DC + 0x1C), 10);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_315A90/func_87E121AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_315A90/func_87E123B8.s")

extern u8 D_87E1B9D8;
extern u8 D_87E1AB30;
extern s32 process_geo_layout(s32, s32 *);
extern void func_87F0252C(void *, void *, void *, s32);
void func_87E12568(s32 arg0) {
    u8 *sp24;
    u8 *sp20;
    s32 sp1C;
    s32 temp_v0;
    s32 var_a1;
    u8 *var_a0;
    u8 *var_a2;
    u8 *var_a3;
    u8 *var_t0;
    u8 *var_v0;
    u8 *var_v1;
    extern void *main_pool_alloc(s32, s32);
    extern void func_87F0252C(void *, void *, void *, s32);
    extern s32 main_pool_get_available(void);
    extern s32 MainPool_AllocState(s32, s32);
    extern s32 process_geo_layout(s32, s32 *);
    extern void MainPool_FinalizeAllocation(s32);
    extern void func_87E123B8(s32);

    sp24 = (u8 *)main_pool_alloc(0xC60, 0);
    sp20 = (u8 *)main_pool_alloc(0x4A0, 0);
    func_87F0252C(&D_87E1B9D8, (u8 *)(u32)arg0 + 4, sp24, 8);
    var_a0 = sp20;
    var_a1 = 0;
    var_v1 = sp24;
    var_v0 = sp20;
    var_a2 = sp20 + 0x94;
    var_a3 = sp20 + 0x128;
    var_t0 = sp20 + 0x1BC;
    do {
        *(u8 **)(var_v1 + 0x38) = var_a0;
        *(s32 *)(var_v0 + 0x4) = 0;
        *(s32 *)(var_v0 + 0x8) = 0;
        *(u8 **)(var_v1 + 0x1C4) = var_a2;
        *(s32 *)(var_v0 + 0x9C) = 0;
        *(s32 *)(var_v0 + 0x98) = 0;
        *(u8 **)(var_v1 + 0x350) = var_a3;
        *(s32 *)(var_v0 + 0x130) = 0;
        *(s32 *)(var_v0 + 0x12C) = 0;
        *(u8 **)(var_v1 + 0x4DC) = var_t0;
        var_a1 += 4;
        *(s32 *)(var_v0 + 0x1C4) = 0;
        *(s32 *)(var_v0 + 0x1C0) = 0;
        var_t0 += 0x250;
        var_a3 += 0x250;
        var_a2 += 0x250;
        var_a0 += 0x250;
        var_v1 += 0x630;
        var_v0 += 0x250;
    } while (var_a1 != 8);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    *(s32 *)((u8 *)(u32)arg0 + 0x18) = process_geo_layout(temp_v0, (s32 *)&D_87E1AB30);
    MainPool_FinalizeAllocation(sp1C);
    func_87E123B8(arg0);
}

extern void func_8004C8C0(s32);
extern void func_87E12568(s32);
void func_87E12674(s32 arg0, s32 arg1) {
    *(s32 *)arg0 = arg1;
    func_8004C8C0(0x167);
    func_8004C8C0(0x1BB);
    func_8004C8C0(0x175);
    func_87E12568(arg0);
}

extern void func_87F0277C(s32);
void func_87E126B4(s32 arg0) {
    func_87F0277C((arg0 + 4));
}

extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern s32 func_8004C990(s32, s32);
void func_87E126D4(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *var_s0;
    u8 *var_s2 = *(u8 **)(arg0 + 12);
    s32 var_s3;

    for (var_s3 = 0; var_s3 != 8; var_s3++) {
        var_s0 = *(u8 **)(var_s2 + 56);
        if (*(s32 *)var_s0 == arg2) {
            func_87F0B1A4(var_s0 + 12, (f32 *)(var_s2 + 72),
                ((f32 *)arg1)[0], ((f32 *)arg1)[1], ((f32 *)arg1)[2], arg3, arg4);
            if (*(s32 *)var_s0 == 0) {
                *(s32 *)(var_s0 + 4) = func_8004C990(359, *(s32 *)(*(u8 **)arg0 + 8584) - 5);
            }
        }
        var_s2 += 396;
        arg1 = (u8 *)arg1 + 12;
    }
}

void func_87E127B8(void *arg0, s32 arg1, void **arg2, void **arg3) {
    void *var_v0;
    void *temp_a0;
    s32 var_v1;

    *arg2 = 0;
    *arg3 = 0;
    var_v0 = *(void **)((u8 *)arg0 + 0xC);
    var_v1 = 0;
    while (var_v1 != 8) {
        temp_a0 = *(void **)((u8 *)var_v0 + 0x38);
        var_v1++;
        if (*(s32 *)temp_a0 == arg1) {
            *arg3 = temp_a0;
            *arg2 = var_v0;
            break;
        }
        var_v0 = (void *)((u8 *)var_v0 + 0x18C);
    }
}

extern u32 D_87E1ABC4;
extern void func_87E126D4(s32, void *, s32, s32, s32);
void func_87E127FC(s32 arg0) {
    func_87E126D4(arg0, &D_87E1ABC4, 0, 30, 4096);
}

s32 func_80001FF0(void);
s32 func_80001FF0(void);
void func_87E12830(s32 arg0) {
    s32 var_a3;

    if (((f32) func_80001FF0() * 0.33333334f) >= 0.0f) {
        var_a3 = (s32) (((f32) func_80001FF0() * 0.33333334f) + 0.5f);
    } else {
        var_a3 = (s32) (((f32) func_80001FF0() * 0.33333334f) - 0.5f);
    }
    func_87E126D4(arg0, &D_87E1ABC4, 2, var_a3, 0x5000);
}

s32 func_80001FF0(void);
void func_87E12900(s32 arg0) {
    s32 var_a3;

    if (((f32) func_80001FF0() * 0.33333334f) >= 0.0f) {
        var_a3 = (s32) (((f32) func_80001FF0() * 0.33333334f) + 0.5f);
    } else {
        var_a3 = (s32) (((f32) func_80001FF0() * 0.33333334f) - 0.5f);
    }
    func_87E126D4(arg0, &D_87E1ABC4, 1, var_a3, 0x5000);
}

s32 func_80001FF0(void);
void func_87E129D0(s32 arg0) {
    s32 var_a3;

    if (((f32) func_80001FF0() * 0.33333334f) >= 0.0f) {
        var_a3 = (s32) (((f32) func_80001FF0() * 0.33333334f) + 0.5f);
    } else {
        var_a3 = (s32) (((f32) func_80001FF0() * 0.33333334f) - 0.5f);
    }
    func_87E126D4(arg0, &D_87E1ABC4, 3, var_a3, 0x5000);
}

extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
void func_87E12AA0(void *arg0, s32 arg1, void *arg2) {
    s32 sp2C;
    void *sp28;

    func_87E127B8(arg0, arg1 + 4, (void **)&sp2C, (void **)&sp28);
    if (sp2C != 0) {
        *(f32 *)((u8 *)sp2C + 0x50) = 1000.0f;
        func_87F0B1A4((u8 *)((u8 *)sp28 + 0xC),
            (f32 *)((u8 *)sp2C + 0x48),
            *(f32 *)((u8 *)arg2 + 0x48),
            *(f32 *)((u8 *)arg2 + 0x4C),
            *(f32 *)((u8 *)arg2 + 0x50) + 20.0f,
            (arg1 * 5) + 0xA,
            0);
    }
}

void func_87E12B34(s32 arg0) {
    u8 *var_p;
    u8 *var_q;
    s32 var_s0 = 0;

    // FAKE: a for loop with the same bounds assigns different saved registers;
    // diff score 45 with one.
loop:
    func_87E127B8((void *)arg0, var_s0 + 4, (void **)&var_p, (void **)&var_q);
    if (var_p != NULL) {
        func_87F0B1A4(var_q + 0xC, (f32 *)(var_p + 0x48), *(f32 *)(var_p + 0x48), *(f32 *)(var_p + 0x4C), 1000.0f,
                      15, 0x2000);
    }
    var_s0 += 1;
    if (var_s0 != 4) {
        goto loop;
    }
}

extern u32 D_87E1AB64;
void func_87E12BE8(s32 arg0) {
    func_87E126D4(arg0, &D_87E1AB64, 0, 15, 8192);
}

void func_87E12C1C(s32 arg0) {
    func_87E126D4(arg0, &D_87E1AB64, 2, 15, 8192);
}

void func_87E12C50(s32 arg0) {
    func_87E126D4(arg0, &D_87E1AB64, 1, 15, 8192);
}

void func_87E12C84(s32 arg0) {
    func_87E126D4(arg0, &D_87E1AB64, 3, 15, 8192);
}

void func_87E12CB8(s32 arg0) {
    s32 i;
    for (i = 0; i != 8; ++i) {
        func_87E126D4(arg0, &D_87E1AB64, i, 30, 8192);
    }
}

extern void func_87F02684(s32);
void func_87E12D28(s32 arg0) {
    func_87F02684((arg0 + 4));
}

s32 func_87E12D48(u8 *arg0) {
    s32 result = 1;
    u8 *node = *(u8 **)(arg0 + 0x10);
    while (node != 0) {
        u8 *entry = *(u8 **)(node + 0x38);
        if (*(u8 **)(entry + 0x90) != 0) {
            result = 0;
        }
        node = *(u8 **)(node + 4);
    }
    return result;
}
#endif
