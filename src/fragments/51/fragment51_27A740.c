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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27A740/func_86304B98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27A740/func_86304CA8.s")
#endif
