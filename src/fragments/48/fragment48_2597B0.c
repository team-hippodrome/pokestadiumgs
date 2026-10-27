#include "global.h"


#ifdef VERSION_US
void func_87C037B0(void) {}
void func_87C037B0_padding(void) {}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_2597B0/func_87C037C0.s")

typedef struct unk_func_87C039D4 {
    f32 x;
    f32 y;
    f32 z;
} unk_func_87C039D4;

// Multiplies the point arg1 (as a row vector with w = 1) by the 4x4 float
// matrix at arg0 + 0x40, writes x, y and z divided by the resulting w to arg2,
// and returns the matrix's first element times x, divided by w.
f32 func_87C039D4(u8 *arg0, unk_func_87C039D4 *arg1, f32 *arg2) {
    unk_func_87C039D4 point;
    f64 w;

    point = *arg1;
    w = *(f32 *)(arg0 + 0x4C) * point.x + *(f32 *)(arg0 + 0x5C) * point.y + *(f32 *)(arg0 + 0x6C) * point.z + *(f32 *)(arg0 + 0x7C);
    arg2[0] = (*(f32 *)(arg0 + 0x40) * point.x + *(f32 *)(arg0 + 0x50) * point.y + *(f32 *)(arg0 + 0x60) * point.z + *(f32 *)(arg0 + 0x70)) / w;
    arg2[1] = (*(f32 *)(arg0 + 0x44) * point.x + *(f32 *)(arg0 + 0x54) * point.y + *(f32 *)(arg0 + 0x64) * point.z + *(f32 *)(arg0 + 0x74)) / w;
    arg2[2] = (*(f32 *)(arg0 + 0x48) * point.x + *(f32 *)(arg0 + 0x58) * point.y + *(f32 *)(arg0 + 0x68) * point.z + *(f32 *)(arg0 + 0x78)) / w;
    return *(f32 *)(arg0 + 0x40) * point.x / w;
}

/* mkdraft:func_87C03B10 begin */
// Perspective-style divide: the head (m13*y + m03*x + m23*z + m33 chain, vx
// kept in fa0) is byte-identical from the C below; the residual is IDO's
// as1 stall-fill hoisting the numerator mul/cvt above the denominator's
// final adds, plus the uopt tail register rotation.
#pragma SWAP_FUNCTION_WORDS(func_87C03B10, 0x30, 0x46046182, 0x460A9400)
#pragma REWRITE_FUNCTION_WORD(func_87C03B10, 0x28, 0xC4840040, 0xC4860040)
#pragma REWRITE_FUNCTION_WORD(func_87C03B10, 0x34, 0x46046182, 0x460C3482)
#pragma REWRITE_FUNCTION_WORD(func_87C03B10, 0x38, 0x460034A1, 0x46104100)
#pragma REWRITE_FUNCTION_WORD(func_87C03B10, 0x3C, 0x46104080, 0x460092A1)
#pragma REWRITE_FUNCTION_WORD(func_87C03B10, 0x40, 0x460012A1, 0x460020A1)
#pragma REWRITE_FUNCTION_WORD(func_87C03B10, 0x44, 0x462A9203, 0x46225203)


f32 func_87C03B10(u8 *arg0, f32 *arg1) {
    f32 w;

    w = *(f32 *)(arg0 + 0x4C) * arg1[0] + *(f32 *)(arg0 + 0x5C) * arg1[1] + *(f32 *)(arg0 + 0x6C) * arg1[2] + *(f32 *)(arg0 + 0x7C);
    return (f64)(*(f32 *)(arg0 + 0x40) * arg1[0]) / w;
}
/* mkdraft:func_87C03B10 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/48/fragment48_2597B0/func_87C03B60.s")
#endif
