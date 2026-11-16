#include "229E0.h"

#ifdef VERSION_US

void func_80025C50(u32 arg0) {
    if (arg0 < 5U) {
        if (arg0 == 4) {
            D_80090B90 = 1;
        } else {
            D_80090B90 = 0;
        }
        func_80018728(0xF0000000U, arg0);
    }
}

s32 func_80025C9C(void) {
    return func_80018C14();
}

void func_80025CBC(s32 arg0) {
    s32 temp_s0;

    func_8002B1A0();
    Audio_DisableCommandQueue();
    func_80028140();
    temp_s0 = arg0 * 3;
    func_80018728(0x83000000U, temp_s0);
    func_80018728(0x83010000U, temp_s0);
    func_80018728(0x83020000U, temp_s0);
    func_80018728(0x83030000U, temp_s0);
    func_80018728(0x83040000U, temp_s0);
    D_80090B9C = 0;
}

s32 func_80025D44(void) {
    return func_80019378();
}

void func_80025D64(u8 arg0) {
    if (arg0 != 0) {
        func_80018728(0xF1FF0000U, 0);
    } else {
        func_80018728(0xF2FF0000U, 0);
    }
}

#endif
