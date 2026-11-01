#include "global.h"


#ifdef VERSION_US
extern void* func_87C00144(void* arg0);
void func_87C02080(u8 *arg0, f64 arg3, u8 *arg4) {
    f64 *out = (f64 *)arg0;
    f64 *in = (f64 *)arg4;

    out[0] = arg3;
    func_87C00144(arg0 + 32);
    out[1] = (((in[1] * in[1]) + (in[2] * in[2])) * out[0]) / 12.0;
    out[2] = (((in[2] * in[2]) + (in[0] * in[0])) * out[0]) / 12.0;
    out[3] = (((in[0] * in[0]) + (in[1] * in[1])) * out[0]) / 12.0;
}

extern f64 D_87C03DF0;
void func_87C02138(u8 *arg0, f64 arg3, f64 arg4) {
    f64 temp_fv0;

    *(f64 *)arg0 = arg3;
    func_87C00144(arg0 + 32);
    temp_fv0 = (*(f64 *)arg0) * arg4 * arg4 * D_87C03DF0;
    *(f64 *)(arg0 + 8) = temp_fv0;
    *(f64 *)(arg0 + 0x10) = temp_fv0;
    *(f64 *)(arg0 + 0x18) = temp_fv0;
}

extern void *func_87C00160(void *, void *, void *);
extern void *func_87C00238(void *, void *, void *);
extern void *func_87C00198(void *, void *, void *);
void func_87C021A4(u8 *arg0, s32 arg1, u8 *arg2) {
    s32 temp[7];
    s32 value;
    value = (s32)func_87C00160((u8 *)(temp + 1), (void *)arg1, arg0 + 0xA0);
    value = (s32)func_87C00238(arg2, arg0 + 0x58, (void *)value);
    func_87C00198(arg2, arg2, arg0 + 0x20);
}

extern f64 func_87C007DC(const f64 *, const f64 *);
extern f64 func_87C022A0(void *, void *, void *, f64, f64, f64, f64);
extern void * func_87C004C4(void *, void *, void *);
f64 func_87C021FC(u8 *arg0, u8 *arg1, u8 *arg2, f64 arg4, f64 arg6, f64 arg8) {
    f64 temp[7];
    f64 temp_fv0;

    func_87C004C4(temp + 3, arg1, arg0 + 0x38);
    func_87C00198(temp + 3, temp + 3, arg0 + 0xA0);
    temp_fv0 = func_87C007DC((f64 *)arg2, temp + 3);
    if (temp_fv0 < 0.0) {
        return func_87C022A0(arg0, temp + 3, arg2, arg4, arg6, -temp_fv0, arg8);
    }
    return 0.0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258080/func_87C022A0.s")

typedef struct unk_func_87C02488 {
    f64 unk_00[3];
} unk_func_87C02488;

extern void* func_87C008B0(void* arg0);
extern void func_87C02508(s32 arg0);
extern void func_87C02538(u8* arg0);

void func_87C02488(void* arg0, s32 arg1, void* arg2) {
    *(s32*)arg0 = arg1;
    *(unk_func_87C02488*)((u8*)arg0 + 8) = *(unk_func_87C02488*)arg2;
    func_87C00144((u8*)arg0 + 32);
    func_87C00144((u8*)arg0 + 88);
    func_87C008B0((u8*)arg0 + 56);
    func_87C02508((s32)arg0);
    func_87C02538(arg0);
}


void func_87C02508(s32 arg0) {
    func_87C00144((void*)(arg0 + 112));
    func_87C00144((void*)(arg0 + 136));
}

extern void* func_87C00AE4(void *, void *);
extern void *func_87C004C4(void *, void *, void *);
void func_87C02538(u8 *arg0) {
    f64 temp[3];

    func_87C00AE4(arg0 + 0x38, arg0 + 0x38);
    func_87C00198(arg0 + 0xA0, arg0 + 8,
                  func_87C004C4(temp, *(u8 **)arg0 + 0x20, arg0 + 0x38));
}

void func_87C02594(u8 *arg0, s32 arg1, s32 arg2) {
    u8 temp0[0x18];
    u8 temp1[0x18];
    s32 value;
    func_87C00198(arg0 + 0x70, arg0 + 0x70, (void *)arg2);
    func_87C00160(temp0, (void *)arg1, arg0 + 0xA0);
    value = (s32)func_87C00238(temp1, temp0, (void *)arg2);
    func_87C00198(arg0 + 0x88, arg0 + 0x88, (void *)value);
}

/* mkdraft:func_87C025FC begin */
extern void func_87C00628(s32, s32, s32);


f64 func_87C025FC(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 temp0[0x18];
    u8 temp1[0x18];

    func_87C00160(temp0, arg2, arg0 + 0xA0);
    func_87C00238(temp1, temp0, arg1);
    func_87C00628((s32)temp1, (s32)temp1, (s32)(arg0 + 0x38));

    // The three quotients are the per-axis terms v[i]*v[i] / inertia[i]; the
    // inertia triple is the three doubles at *(u8 **)arg0 + 8 (func_87C0288C
    // indexes the same address as its arg3[0..2]).
    // FAKE: the sum is written in reverse axis order (2, then 1, then 0)
    // because the add.d operand order follows the source term order: in axis
    // order 0,1,2 the final add.d comes out commuted (relocation-aware diff
    // score 10), and only the reversed spelling reproduces retail's
    // add.d $f0,$f8,$f10.
    return (*(f64 *)(temp1 + 0x10) * *(f64 *)(temp1 + 0x10)) /
               *(f64 *)((u8 *)*(void **)((void *)arg0) + 0x18) +
           ((*(f64 *)(temp1 + 8) * *(f64 *)(temp1 + 8)) /
                *(f64 *)((u8 *)*(void **)((void *)arg0) + 0x10) +
            (*(f64 *)(temp1) * *(f64 *)(temp1)) /
                *(f64 *)((u8 *)*(void **)((void *)arg0) + 0x8));
}
/* mkdraft:func_87C025FC end */

extern f64 func_87C00208(void *, void *);
extern f64 func_87C025FC(u8 *, u8 *, u8 *);
f64 func_87C02690(u8 *arg0, u8 *arg1, f64 arg2, u8 *arg3, u8 *arg4, f64 arg5) {
    u8 sp30[0x18];

    return (-(1.0f + arg2) * func_87C00208(func_87C00160(sp30, arg0 + 0x20, arg1 + 0x20), arg3)) /
           ((1.0 / *(f64 *)(*(u8 **)arg0) + 1.0 / *(f64 *)(*(u8 **)arg1) + func_87C025FC(arg0, arg3, arg4) +
             func_87C025FC(arg1, arg3, arg4)) *
            arg5);
}

extern void func_87C003BC(void *, void *, void *);
extern void *func_87C00718(void *, void *, f64);
extern void *func_87C002A8(void *, void *, f64);
extern void *func_87C002DC(void *, void *);
f64 func_87C02764(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, f64 arg4, f64 arg6, f64 arg8) {
    f64 result;
    f64 var_spE8[3];
    f64 var_spD0[3];
    f64 var_spB8[3];
    f64 var_spA0[3];
    f64 var_sp88[3];
    f64 var_sp70[3];
    f64 var_sp58[3];
    f64 var_sp40[3];

    func_87C021A4(arg0, (s32)arg3, (u8 *)var_sp58);
    func_87C021A4(arg1, (s32)arg3, (u8 *)var_sp40);
    func_87C00160(var_sp88, var_sp40, var_sp58);
    func_87C003BC(var_spA0, var_sp88, arg2);
    func_87C00718(var_spA0, var_spA0, 1.0);
    result = func_87C02690(arg0, arg1, arg4, arg2, arg3, arg8);
    func_87C00198(var_sp70, func_87C002A8(var_spD0, arg2, result),
                  func_87C002A8(var_spB8, var_spA0, arg6 * result));
    func_87C02594(arg0, (s32)arg3, (s32)var_sp70);
    func_87C02594(arg1, (s32)arg3, (s32)func_87C002DC(var_spE8, var_sp70));
    return result;
}

extern void* func_87C00120(void*, f64, f64, f64);
void* func_87C0288C(void* arg0, f64* arg1, f64* arg2, f64* arg3) {
    return func_87C00120(arg0,
                        (arg2[0] + (arg3[1] - arg3[2]) * arg1[1] * arg1[2]) / arg3[0],
                        (arg2[1] + (arg3[2] - arg3[0]) * arg1[2] * arg1[0]) / arg3[1],
                        (arg2[2] + (arg3[0] - arg3[1]) * arg1[0] * arg1[1]) / arg3[2]);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258080/func_87C02924.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_258080/func_87C02ADC.s")

extern void func_87C00628(s32, s32, s32);
void func_87C02C30(u8 *arg0, void *arg1, void *arg2) {
    f64 var_spA8[3];
    f64 var_sp90[3];
    f64 var_sp78[3];
    f64 var_sp60[3];
    f64 var_sp48[3];
    f64 var_sp30[3];

    func_87C00198(arg0 + 32, arg0 + 32,
                  func_87C002A8(var_spA8, arg2, 1.0 / **(f64 **)arg0));
    func_87C00160(var_sp90, arg1, arg0 + 160);
    func_87C00238(var_sp78, var_sp90, arg2);
    func_87C00628((s32)var_sp48, (s32)(arg0 + 88), (s32)(arg0 + 56));
    func_87C00628((s32)var_sp60, (s32)var_sp78, (s32)(arg0 + 56));
    func_87C0288C(var_sp30, var_sp48, var_sp60, (f64 *)(*(u8 **)arg0 + 8));
    func_87C00198(var_sp48, var_sp48, var_sp30);
    func_87C004C4(arg0 + 88, var_sp48, arg0 + 56);
}

extern void func_87C013CC(void *, void *);
void func_87C02D1C(u8 *arg0, u8 *arg1) {
    func_87C013CC(arg0 + 0x38, arg1);
    *(f32 *)(arg1 + 0x30) = *(f64 *)(arg0 + 8);
    *(f32 *)(arg1 + 0x34) = *(f64 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x38) = *(f64 *)(arg0 + 0x18);
}
#pragma C_FUNCTION_PADDING(12)
#endif
