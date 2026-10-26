#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32DC40/func_87F0AFD0.s")

void func_87F0B0FC(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    /* Word at +0x68, same flags word func_87F0B154 reads (bit31 = byte 0x68 bit 7). */
    struct unk_func_87F0B0FC {
        u8 pad[0x68];
        u32 bit31 : 1;
        u32 bit30 : 1;
        u32 rest : 30;
    };
    /* Sub-record at arg0+0x48; its tail word at +0x20 is the same flags word. */
    struct unk_func_87F0B0FC_048 {
        s32 unk_00;
        s32 unk_04;
        s32 unk_08;
        u8 pad[8];
        f32 unk_14;
        f32 unk_18;
        f32 unk_1C;
        u32 bit31 : 1;
        u32 bit30 : 1;
        u32 rest : 30;
    };
    struct unk_func_87F0B0FC_048 *work = (void *)((u8 *)arg0 + 0x48);

    if (((struct unk_func_87F0B0FC *)arg0)->bit31 == 0) {
        work->unk_00 = 0;
        work->unk_04 = 0;
        work->unk_08 = arg4;
        work->bit31 = 1;
        work->bit30 = 0;
        work->unk_14 = arg1;
        work->unk_18 = arg2;
        work->unk_1C = arg3;
    }
}
void func_87F0B154(void *arg0) {
    struct State {
        u8 pad[0x68];
        u32 bit31 : 1;
        u32 bit30 : 1;
        u32 rest : 30;
    };
    struct State *state = arg0;
    if ((state->bit30 == 0) && (state->bit31 == 1)) {
        state->bit31 = 0;
        state->bit30 = 1;
    }
}

void func_87F0B18C(u8 *arg0) {
    arg0[0x68] &= 0xFF7F;
    arg0[0x68] &= 0xFFBF;
}

void func_87F0B1A4(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    if (arg2 != arg1[0] || arg3 != arg1[1] || arg4 != arg1[2]) {
        *(f32 *)(arg0 + 0) = arg1[0];
        *(f32 *)(arg0 + 4) = arg1[1];
        *(f32 *)(arg0 + 8) = arg1[2];
        *(s32 *)(arg0 + 108) = 0;
        *(s32 *)(arg0 + 112) = arg5;
        *(u32 *)(arg0 + 132) = (*(u32 *)(arg0 + 132) | 1) | arg6;
        *(f32 *)(arg0 + 40) = arg3;
        *(f32 *)(arg0 + 36) = arg2;
        *(f32 *)(arg0 + 44) = arg4;
        func_87F0B18C(arg0);
    }
}

void func_87F0B24C(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    if (arg2 != arg1[0] || arg3 != arg1[1] || arg4 != arg1[2]) {
        *(f32 *)(arg0 + 12) = arg1[0];
        *(f32 *)(arg0 + 16) = arg1[1];
        *(f32 *)(arg0 + 20) = arg1[2];
        *(s32 *)(arg0 + 116) = 0;
        *(s32 *)(arg0 + 120) = arg5;
        *(u32 *)(arg0 + 132) = (*(u32 *)(arg0 + 132) | 0x10) | arg6;
        *(f32 *)(arg0 + 52) = arg3;
        *(f32 *)(arg0 + 48) = arg2;
        *(f32 *)(arg0 + 56) = arg4;
        func_87F0B18C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32DC40/func_87F0B2F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32DC40/func_87F0B4AC.s")

extern void func_8004C8C0(s32);
void func_87F0BD10(void) {
    func_8004C8C0(447);
}

void func_87F0BD30(u8 *arg0, u16 arg1, u16 arg2, s32 arg3) {
    *(u16 *)(arg0 + 0) = arg1;
    *(u16 *)(arg0 + 2) = arg2;
    *(s32 *)(arg0 + 4) = arg3;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32DC40/func_87F0BD48.s")
#endif
