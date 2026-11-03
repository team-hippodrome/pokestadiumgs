#include "229E0.h"

#ifdef VERSION_US



f32 func_80021DE0(s32 arg0) {
    u8 value = D_80090137[arg0];
    if (value >= 0x80) {
        value = D_800917F8[value & 0x7F];
        value = (u32)(f32)value;
    }
    return (f32)value / 127.0f;
}

/* mkdraft:func_80021ED8 begin */
extern u8 D_800900B0[];
extern u8 D_80090BA8;
extern s32 D_80090B94;
extern s32 D_80090B98;
extern s8 D_80090BAC;
extern u8 D_800901A8;
extern f32 D_800A2660;
extern void func_80025294();
extern s32 func_800265B0(u32 arg0, s32 arg1);



void func_80021ED8(s32 arg0) {
    s32 blend;
    s32 index;
    s32 alpha;
    f32 volume;
    u8 entered_3E;
    u8 entered_7;

    alpha = 0;
    entered_3E = 0;
    entered_7 = 0;
    if (arg0 != 0x12C) {
        func_8002A25C();
        if (D_80090BA8 != 0) {
            func_80025294(0x10014, 0, 0);
            D_80090BA8 = 0;
        }
        switch (arg0) {
        case 0x3E:
        case 0x45:
            break;
        case 0x53:
            D_80090BAC = 0;
            break;
        case 0x55:
            break;
        default:
            // FAKE: wrapper block; as a bare assignment diff score 175, because IDO then merges
            // the store into the 0x55 compare's branch delay slot instead of branching to it.
            if (1) {
                D_80090BAC = 3;
            }
            break;
        }
        if (arg0 == 0x51) {
            D_800901A8 = 0;
        }
        if (arg0 == 0x64) {
            arg0 = 0x22;
            alpha = 0x11;
        } else if (arg0 == 0x65) {
            arg0 = 0x36;
            alpha = 0x28;
        } else if (arg0 == 0x66) {
            arg0 = 0x3E;
            entered_3E = 1;
        } else if (arg0 == 0x67) {
            arg0 = 7;
            entered_7 = 1;
        } else if (arg0 == 0x68) {
            arg0 = 0x4C;
            alpha = 0x14;
        } else if (arg0 == 0x46) {
            alpha = 4;
        } else if (arg0 == 0x53 && D_800901A8 != 0) {
            arg0 = 0x61;
        }
        switch (arg0) {
        case 0x31:
            func_80025848(0x41);
            break;
        case 0x57:
            D_80090BA4 = 0;
            break;
        case 0x5A:
            func_80023A3C(3, 0, 0);
            if (D_80090B94 == 0x13) {
                arg0 = 0x42;
            } else if (D_80090B98 == 0x28) {
                arg0 = 0x17;
            } else if (D_80090B94 == 0x10) {
                arg0 = 0x17;
            } else if (D_80090B94 == 0x11) {
                arg0 = 0x17;
            } else {
                blend = D_80090B98;
                if (D_80090B98 == 0xB && (D_80090B94 < 0xA || D_80090B94 >= 0x10)) {
                    blend = 0xA;
                }
                if (D_80090B94 == 0xF) {
                    D_800901A8 = 1;
                } else {
                    D_800901A8 = 0;
                }
                // FAKE: the (u32) conversion orders the argument registers; without it
                // diff score 340 (D_80090B94 is an s32 global).
                index = func_800265B0((u32) D_80090B94, blend);
                if (index < 0) {
                    index = 0;
                }
                arg0 = D_800900B0[index];
            }
            break;
        }
        if (arg0 != 0x3E) {
            D_8009019C = 0;
        }
        if (arg0 != 7) {
            D_800901A0 = 0;
        }
        if (arg0 != 0x4C) {
            D_800901A4 = 0;
        }
        if ((u8) D_8009019C == 0 && (u8) D_800901A0 == 0 && (u8) D_800901A4 == 0) {
            if ((u32) arg0 >= 0x62) {
                return;
            }
            volume = func_80021DE0(arg0);
            func_80018728(((u8) (arg0 + 0x27) << 8) | 0x82000000, 0);
            func_80018704(0x41000000, volume * D_800A2660);
            if (alpha != 0) {
                func_80018728(0x49000000, alpha);
            }
            if (arg0 == 0x3E) {
                D_8009019C = 1;
            }
            if (arg0 == 7) {
                D_800901A0 = 1;
            }
            if (arg0 == 0x4C) {
                D_800901A4 = 1;
            }
        }
        if (arg0 == 0x3E) {
            if (entered_3E == 0) {
                func_8001874C(0x08000000, 0);
                func_8001874C(0x08000100, 0);
                func_8001874C(0x08000200, 0);
                func_8001874C(0x08000300, 0);
                func_8001874C(0x08000400, 0);
                func_8001874C(0x08000800, 1);
                func_8001874C(0x08000900, 0);
                func_8001874C(0x08000A00, 1);
                func_8001874C(0x08000B00, 1);
                func_8001874C(0x08000C00, 1);
                func_8001874C(0x08000D00, 1);
                func_8001874C(0x08000E00, 1);
                func_8001874C(0x08000F00, 1);
            } else {
                func_8001874C(0x08000000, 1);
                func_8001874C(0x08000100, 1);
                func_8001874C(0x08000200, 1);
                func_8001874C(0x08000300, 1);
                func_8001874C(0x08000400, 1);
                func_8001874C(0x08000800, 0);
                func_8001874C(0x08000900, 1);
                func_8001874C(0x08000A00, 0);
                func_8001874C(0x08000B00, 0);
                func_8001874C(0x08000C00, 0);
                func_8001874C(0x08000D00, 0);
                func_8001874C(0x08000E00, 0);
                func_8001874C(0x08000F00, 0);
            }
        }
        if (arg0 == 7) {
            if (entered_7 == 0) {
                func_8001874C(0x08000000, 0);
                func_8001874C(0x08000100, 0);
                func_8001874C(0x08000200, 0);
                func_8001874C(0x08000300, 0);
                func_8001874C(0x08000400, 0);
                func_8001874C(0x08000500, 0);
                func_8001874C(0x08000600, 0);
                func_8001874C(0x08000700, 0);
                func_8001874C(0x08000800, 0);
                func_8001874C(0x08000900, 0);
                func_8001874C(0x08000A00, 0);
                func_8001874C(0x08000C00, 1);
                func_8001874C(0x08000D00, 1);
            } else {
                func_8001874C(0x08000000, 1);
                func_8001874C(0x08000100, 1);
                func_8001874C(0x08000200, 1);
                func_8001874C(0x08000300, 1);
                func_8001874C(0x08000400, 1);
                func_8001874C(0x08000500, 1);
                func_8001874C(0x08000600, 1);
                func_8001874C(0x08000700, 1);
                func_8001874C(0x08000800, 1);
                func_8001874C(0x08000900, 1);
                func_8001874C(0x08000A00, 1);
                func_8001874C(0x08000C00, 0);
                func_8001874C(0x08000D00, 0);
            }
        }
        if (arg0 == 0x4C) {
            func_80018728(0x49000000, alpha);
        }
    }
}
/* mkdraft:func_80021ED8 end */

void func_800225C4(s32 arg0) {
    func_80018728(0x83000000U, arg0 * 3, arg0);
    func_800187AC();
    D_8009019C = 0;
    D_800901A0 = 0;
    D_800901A4 = 0;
}

void func_8002260C(s32 arg0, s32 arg1) {
    func_80018728(0x82000100, 0);
  }

s32 func_8002263C(void) {
    return 0x61;
}

extern f32 D_800A2664;
void func_80022644(u32 arg0) {
    f32 volume;

    if (arg0 != 0 && arg0 < 0x62) {
        volume = func_80021DE0(arg0);
        func_80018728(((u8)(arg0 + 0x27) << 8) | 0x82000000, 0);
        func_80018704(0x41000000, volume * D_800A2664);
    }
}

#pragma C_FUNCTION_PADDING(4)


#endif
