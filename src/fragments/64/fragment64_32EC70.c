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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32EC70/func_87F0C358.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32EC70/func_87F0C3EC.s")
#endif
