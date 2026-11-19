#include "229E0.h"

#ifdef VERSION_US

extern u8 D_80091B00;
extern void func_8003121C(u8, s32, s32);
void func_800231A0(u32 arg0, u32 arg1, u32 arg2) {
    u8 flag;
    u8 v;
    s32 key;
    s32 vol;
    s32 sel;

    flag = 0;
    if (arg1 == 0x117) {
        arg1 = 0x12C;
    }
    if (arg1 >= 0xFE && arg1 < 0x117) {
        arg1 = 0xC9;
    }
    if (arg0 == 0x12C) {
        arg0 = 1;
        flag = 1;
    }
    if (arg0 == 0 || arg0 >= 0xFC) {
        return;
    }
    if ((arg2 == 0 || arg2 == 2) && D_80090B60 != 4 && flag == 0) {
        func_8003121C(D_80091B00, arg0, arg1);
    }
    if (D_80091B00 == 1) {
        if (arg2 == 0 || arg2 == 2) {
            switch (arg0) {
                case 0x31:
                case 0x79:
                case 0xB1:
                case 0xD9:
                case 0xF6:
                case 0xF7:
                    arg2 = 3;
                    break;
                case 0xCD:
                    if (arg1 == 0x4C || arg1 == 0xE8 || arg1 == 0xF1) {
                        arg2 = 0x10;
                    } else {
                        arg2 = 3;
                    }
                    break;
            }
        } else if (arg2 == 1) {
            if (arg0 == 0xB1 || arg0 == 0xF6) {
                arg2 = 4;
            }
        }
    } else if (arg2 == 0 || arg2 == 2) {
        if (arg0 == 0xCD) {
            if (arg1 == 0x4C || arg1 == 0xE8 || arg1 == 0xF1) {
                arg2 = 0xF;
            } else {
                arg2 = 0;
            }
        }
    }
    key = (arg0 - 1) / 10;
    vol = ((arg0 - 1) % 10) * 7;
    if (arg0 == 0xFB) {
        key = key - 1;
        vol = 0x46;
    }
    key += 10;
    D_80090A54 = 0;
    if (key != D_8009022C || D_80090B80 != 2) {
        func_80018728(0x82010000 | ((key & 0xFF) << 8), 0);
        func_80018704(0x41010000, 0.585f);
        func_800187AC();
        func_80018728(0xF8000000, 0);
        func_80018728(0xF8000000, 0);
        func_80018728(0xF8000000, 0);
        D_8009022C = key;
    }
    D_80090B80 = 2;
    switch (arg2) {
        case 0:
            if (Audio_GetSpeciesMaskBit(arg0) == 0) {
                func_80024D10(0x14);
            }
            switch (arg0) {
                case 0x2D:
                case 0x2E:
                    if (arg1 != 0x12C) {
                        func_80024480(arg1, 0);
                    }
                    v = vol + 1;
                    sel = 0;
                    break;
                case 0x85:
                    func_80023A3C(0x28, 0, 0);
                    return;
                case 0x7A:
                    if (arg1 == 0x2A || arg1 == 0x5A || arg1 == 0x5C || arg1 == 0x5E || arg1 == 0xAD) {
                        v = vol + 2;
                    } else {
                        v = vol + 1;
                    }
                    sel = 0;
                    break;
                default:
                    if (((arg0 - 1) == 0x34 || (arg0 - 1) == 0x52) && arg1 == 6) {
                        v = vol + 7;
                    } else {
                        v = vol + 1;
                    }
                    sel = 0;
                    break;
            }
            break;
        case 1:
            switch (arg0) {
                case 0xD:
                case 0x10:
                case 0x4B:
                case 0x5D:
                case 0x5E:
                case 0x6C:
                case 0x72:
                case 0x7B:
                case 0x7F:
                case 0x81:
                case 0x89:
                case 0x8B:
                case 0x95:
                case 0xAA:
                case 0xB5:
                case 0xC4:
                case 0xF3:
                    func_800239B4(0x28, 0xB4);
                    goto common;
                case 0xAD:
                case 0xE5:
                    func_800239B4(0x14, 0xB4);
                    goto common;
                case 0xB4:
                    func_800239B4(0x5A, 0xB4);
                    goto common;
                case 0xEF:
                case 0xFA:
                    func_800239B4(0x37, 0xB4);
                    goto common;
                case 0x12:
                case 0xC1:
                    func_800239B4(0x3C, 0xB4);
                    goto common;
                case 0x2B:
                case 0x86:
                case 0xB8:
                    func_8002390C(0x5A);
                    return;
                case 0x30:
                case 0x5F:
                case 0x67:
                    func_8002390C(0xB4);
                    return;
                default:
                    func_80023954();
                case 0xB:
                case 0xC:
                case 0x2E:
                case 0x2F:
                case 0x36:
                case 0x39:
                case 0x4D:
                case 0x4E:
                case 0x4F:
                case 0x78:
                case 0x80:
                case 0x8E:
                case 0x93:
                case 0x99:
                case 0xAB:
                case 0xAE:
                case 0xB1:
                case 0xBA:
                case 0xC3:
                case 0xC9:
                case 0xD4:
                case 0xD9:
                case 0xE6:
                common:
                    sel = 1;
                    v = vol + 4;
                    break;
            }
            break;
        case 2:
            if (Audio_GetSpeciesMaskBit(arg0) == 0) {
                func_80024D10(0x14);
            }
            switch (arg0) {
                case 0x2D:
                case 0x2E:
                    if (arg1 != 0x12C) {
                        func_80024480(arg1, 0);
                    }
                    v = vol + 1;
                    sel = 0;
                    break;
                case 0x85:
                    func_80023A3C(0x28, 0, 0);
                    return;
                case 0x7A:
                    if (arg1 == 0x2A || arg1 == 0x5A || arg1 == 0x5C || arg1 == 0x5E || arg1 == 0xAD) {
                        v = vol + 2;
                    } else {
                        v = vol + 1;
                    }
                    sel = 0;
                    break;
                default:
                    if (((arg0 - 1) == 0x34 || (arg0 - 1) == 0x52) && arg1 == 6) {
                        v = vol + 7;
                    } else {
                        v = vol + 5;
                    }
                    sel = 0;
                    break;
            }
            break;
        case 15:
            func_80024D10(0x14);
            v = vol + 6;
            sel = 0;
            break;
        case 16:
            func_80024D10(0x14);
            v = vol + 7;
            sel = 0;
            break;
        case 3:
            func_80024D10(0x14);
            v = vol + 2;
            sel = 0;
            break;
        case 4:
            func_80024D10(0x14);
            v = vol + 3;
            sel = 0;
            break;
        case 5:
            func_80018704(0x41010000, 0.413595f);
            return;
        case 10:
            if ((arg0 - 1) != 0xB8) {
                return;
            }
            v = vol + 6;
            sel = 0;
            break;
        case 11:
            if ((arg0 - 1) != 0xD8 && (arg0 - 1) != 0xA7) {
                return;
            }
            v = vol + 6;
            sel = 1;
            break;
        default:
            return;
    }
    D_80090220 = 1;
    func_8001874C(((sel & 0xFF) << 8) | 0x06010000, (s8)v);
}

void func_800238C4(void) {
    if (D_80090B80 == 2) {
        D_80090220 = 0;
        func_80018728(0x83010000U, 0xB4);
        D_8009022C = -1;
    }
}

void func_8002390C(s32 arg0) {
    if (D_80090B80 == 2) {
        D_80090220 = 0;
        func_80018728(0x83010000U, arg0);
        D_8009022C = -1;
    }
}

void func_80023954(void) {
    func_8001874C(0x06010005, 1);
}

u8 Audio_GetSpeciesMaskBit(u32 species) {
    u8 value;
    u8 bit;
    u8 mask;
    value = D_80090200[(u8)((species - 1) >> 3)];
    bit = (species - 1) & 7;
    mask = 1 << (7 - bit);
    value &= mask;
    return value;
}

void func_800239B4(s32 arg0, s32 arg1) {
    D_80090224 = arg0;
    D_80090228 = arg1;
}

void func_800239C8(void) {
    if (D_80090224 >= 0) {
        D_80090224--;
        if (D_80090224 < 0) {
            func_8002390C(D_80090228);
            D_80090228 = 0;
        }
    }
}

#endif
