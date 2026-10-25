#include "global.h"


#ifdef VERSION_US
typedef struct unk_func_87F0C000 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
} unk_func_87F0C000;

extern f32 D_80087E50[];
extern f32 D_80088E50[];

void func_87F0C000(unk_func_87F0C000* arg0) {
    f32 var_fv0;

    var_fv0 = arg0->unk_18;
    arg0->unk_00 = D_80088E50[arg0->unk_1C >> 4] * D_80087E50[arg0->unk_1E >> 4] * var_fv0 + arg0->unk_0C;
    arg0->unk_04 = -D_80087E50[arg0->unk_1C >> 4] * var_fv0 + arg0->unk_10;
    arg0->unk_08 = D_80088E50[arg0->unk_1C >> 4] * D_80088E50[arg0->unk_1E >> 4] * var_fv0 + arg0->unk_14;
}

void func_87F0C094(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6) {
    (*(f32 *)((u8 *)(arg0) + (0xC))) = arg1;
    (*(f32 *)((u8 *)(arg0) + (0x10))) = arg2;
    (*(f32 *)((u8 *)(arg0) + (0x14))) = arg3;
    (*(f32 *)((u8 *)(arg0) + (0x18))) = arg4;
    (*(s16 *)((u8 *)(arg0) + (0x1C))) = arg5;
    (*(s16 *)((u8 *)(arg0) + (0x1E))) = arg6;
    func_87F0C000(arg0);
    (*(s32 *)((u8 *)(arg0) + (0x20))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x24))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x28))) = 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32EC70/func_87F0C0FC.s")

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f_87F0C358;

typedef struct {
    u8 unk_00[12];
    Vec3f_87F0C358 unk_0C;
    f32 unk_18;
    s16 unk_1C;
    s16 unk_1E;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    Vec3f_87F0C358 unk_2C;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
} unk_func_87F0C358;

extern f32 D_87F11714;
void func_87F0C358(unk_func_87F0C358 *arg0, s32 arg1, f32 arg2, f32 arg3,
                   f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 factor;

    factor = D_87F11714;
    arg0->unk_2C = arg0->unk_0C;
    arg0->unk_38 = arg0->unk_18;
    arg0->unk_3C = arg0->unk_1C * factor;
    arg0->unk_40 = arg0->unk_1E * factor;
    arg0->unk_44 = arg2;
    arg0->unk_48 = arg3;
    arg0->unk_4C = arg4;
    arg0->unk_50 = arg5;
    arg0->unk_54 = arg6;
    arg0->unk_58 = arg7;
    arg0->unk_20 = 1;
    arg0->unk_24 = 0;
    arg0->unk_28 = arg1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32EC70/func_87F0C3EC.s")
#endif
