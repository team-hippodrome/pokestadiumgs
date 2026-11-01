#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27A740/func_86304920.s")

typedef struct unk_func_86304ACC {
    f32 x;
    f32 y;
} unk_func_86304ACC;

extern f32 func_87D0059C(f32 *, f32 *);

s32 func_86304ACC(void *arg0, unk_func_86304ACC *arg1,
                unk_func_86304ACC *arg2, unk_func_86304ACC *arg3, f32 *arg4) {
    s32 result = 0;

    arg3->x = *(f32 *)((u8 *)arg0 + 72) - arg1->x;
    arg3->y = *(f32 *)((u8 *)arg0 + 76) - arg1->y;
    *arg4 = sqrtf(arg3->x * arg3->x + arg3->y * arg3->y);
    if (*arg4 < 21.0f) {
        if (0.0f == *arg4) {
            *arg3 = *arg2;
        } else {
            func_87D0059C(&arg3->x, &arg3->y);
        }
        *arg4 = 21.0f - *arg4;
        result = 1;
    }
    return result;
}

extern s32 func_87D00670(unk_func_86304ACC *, unk_func_86304ACC *, f32 *,
                         unk_func_86304ACC *, unk_func_86304ACC *, f32 *);
s32 func_86304B98(void *arg0, unk_func_86304ACC *arg1, unk_func_86304ACC *arg2,
                  unk_func_86304ACC *arg3, f32 *arg4, f32 *arg5) {
    unk_func_86304ACC sp30;
    f32 sp2C;
    s32 result;

    sp30.x = *(f32 *)((u8 *)arg0 + 72);
    sp30.y = *(f32 *)((u8 *)arg0 + 76);
    result = 0;
    if (func_87D00670(&sp30, arg1, &sp2C, arg2, arg3, arg4) != 0) {
        sp2C *= -1.0f;
        if ((-21.0f < sp2C) && (sp2C < 21.0f) && (0.0f < *arg4) && (*arg4 < 1.0f)) {
            if (0.0f < sp2C) {
                *arg5 = 21.0f - sp2C;
            } else {
                *arg5 = sp2C + 21.0f;
            }
            result = 1;
        }
    }
    return result;
}

/* mkdraft:func_86304CA8 begin */
s32 func_86304CA8(void *arg0, unk_func_86304ACC *arg1, unk_func_86304ACC *arg2,
                  unk_func_86304ACC *arg3, unk_func_86304ACC *arg4,
                  f32 *arg5, f32 *arg6) {
    f32 sp44;
    f32 sp40;
    f64 unused; // FAKE: unreferenced local puts sp40/sp44 at 0x40/0x44 (score 156 without it)
    unk_func_86304ACC sp30;
    s32 result;
    unk_func_86304ACC sp24;

    sp24.x = *(f32 *)((u8 *)arg0 + 72);
    sp24.y = *(f32 *)((u8 *)arg0 + 76);
    sp30.x = arg2->x + (arg4->x * 21.0f);
    result = 0;
    sp30.y = arg2->y + (arg4->y * 21.0f);
    if ((func_87D00670(&sp24, arg1, &sp44, &sp30, arg3, &sp40) != 0) &&
        (sp44 > 0.0f) && (sp44 < 1.0f) && (sp40 > 0.0f) && (sp40 < 1.0f)) {
        func_87D00670(&sp24, arg4, arg6, &sp30, arg3, arg5);
        result = 1;
    }
    if (result == 0) {
        if (func_86304B98(arg0, arg4, arg2, arg3, arg5, arg6) != 0) {
            result = 1;
        }
    }
    return result;
}
/* mkdraft:func_86304CA8 end */
#endif
