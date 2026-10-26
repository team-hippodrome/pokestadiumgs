#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_201DA0/func_8AF13B30.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_201DA0/func_8AF141E8.s")

typedef struct {
    u32 unk_00[321];
} unk_func_8AF145B4;

void func_8AF145B4(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 arg5, u8 arg6, u8 arg7,
                   u8 arg8, u8 arg9, u8 arg10, s32 arg11, s32 arg12, const unk_func_8AF145B4* arg13) {
    *(s32*)(arg0 + 24) = arg1;
    *(s32*)(arg0 + 8) = arg2;
    *(s32*)(arg0 + 12) = arg3;
    *(s32*)(arg0 + 16) = arg4;
    arg0[34] = arg5;
    arg0[35] = arg6;
    arg0[36] = arg7;
    arg0[37] = arg8;
    arg0[38] = arg9;
    arg0[39] = arg10;
    *(s32*)arg0 = arg11;
    *(s32*)(arg0 + 20) = -1;
    *(s32*)(arg0 + 28) = arg12;
    *(unk_func_8AF145B4*)(arg0 + 40) = *arg13;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_201DA0/func_8AF14648.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_201DA0/func_8AF14BE8.s")

extern u8 *D_8AF27130;
extern u8 D_8AF33628[];
extern u8 D_8AF336A0[];
extern u8 D_8AF33718[];
void func_8AF14D3C(void) {
    s32 pad1; // FAKE: unused stack padding (with pad2); diff score 10 without both.
    u8 *state;
    u8 *sprite;
    s32 pad2; // FAKE: see pad1.
    s32 x;
    s32 y;

    state = D_8AF27130;
    sprite = state + 0x28;
    x = *(s16 *)(state + 0x34) * *(s32 *)(state + 0x4C) + *(s32 *)(state + 0x5C) + *(s32 *)(state + 8) - 4;
    y = *(s16 *)(state + 0x36) * *(s32 *)(state + 0x50) + *(s32 *)(state + 0x60) + *(s32 *)(state + 0xC) - 2;
    func_8AC007B8(*(s32 *)(state + 8), *(s32 *)(state + 0xC) + 5, *(s16 *)(state + 0x28), *(s16 *)(state + 0x2A) - 50);
    func_8AF02F18(state);
    func_8AC00738();
    func_8004B314(x, y, 88, 68);
    if (func_8AC0665C(D_8AF33718, *(s16 *)(sprite + 0x10)) != 0) {
        func_8AC05F00(D_8AF33628);
    }
    if (func_8AC0672C(D_8AF33718, *(s16 *)(sprite + 0x10)) != 0) {
        func_8AC05F00(D_8AF336A0);
    }
}
#endif
