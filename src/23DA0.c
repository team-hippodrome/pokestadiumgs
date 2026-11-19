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

s32 func_80023A10(u8 arg0, u8 arg1) {
    return D_8009061C[arg0][arg1];
}

extern u8 D_80090650[];
extern void func_800231A0();
void func_80023A3C(s32 arg0, s32 arg1, s32 arg2) {
    u8 kind;
    u8 idx;

    switch ((u32)arg0) {
        case 0:
            kind = 0;
            if (*(u8 *)&D_80090B90 != 0) {
                switch (D_80090BA0) {
                    case 1: idx = 7; break;
                    case 2: idx = 8; break;
                    case 3: idx = 0x3E; break;
                    case 4: idx = 0x3F; break;
                    case 5: idx = 0x40; break;
                    case 6: idx = 0x41; break;
                    case 7: idx = 0x42; break;
                    case 8: idx = 0x43; break;
                    case 9: idx = 0x44; break;
                    default: return;
                }
            } else {
                switch (D_80090BA0) {
                    case 1: idx = 1; break;
                    case 2: idx = 2; break;
                    case 3: idx = 0x3E; break;
                    case 4: idx = 0x3F; break;
                    case 5: idx = 0x40; break;
                    case 6: idx = 0x41; break;
                    case 7: idx = 0x42; break;
                    case 8: idx = 0x43; break;
                    case 9: idx = 0x44; break;
                    default: return;
                }
            }
            break;
        case 1:
            kind = 1;
            if (D_80090BA0 == 1) {
                idx = 3;
            } else if (D_80090BA0 == 2) {
                idx = 4;
            } else {
                return;
            }
            break;
        case 2:
            kind = 0;
            if (D_80090BA0 == 1) {
                idx = 5;
            } else if (D_80090BA0 == 2) {
                idx = 6;
            } else {
                return;
            }
            if (*(u8 *)&D_80090B90 != 0) {
                if (D_80090BA0 == 1) {
                    idx = 9;
                } else if (D_80090BA0 == 2) {
                    idx = 0xA;
                } else {
                    return;
                }
            }
            break;
        case 3:
            kind = 0;
            if (*(u8 *)&D_80090B90 != 0) {
                switch (D_80090BA0) {
                    case 1: idx = 0x36; break;
                    case 2: idx = 0x37; break;
                    case 3: idx = 0x3E; break;
                    case 4: idx = 0x3F; break;
                    case 5: idx = 0x40; break;
                    case 6: idx = 0x41; break;
                    case 7: idx = 0x42; break;
                    case 8: idx = 0x43; break;
                    case 9: idx = 0x44; break;
                    default: return;
                }
            } else {
                switch (D_80090BA0) {
                    case 1: idx = 0x34; break;
                    case 2: idx = 0x35; break;
                    case 3: idx = 0x3E; break;
                    case 4: idx = 0x3F; break;
                    case 5: idx = 0x40; break;
                    case 6: idx = 0x41; break;
                    case 7: idx = 0x42; break;
                    case 8: idx = 0x43; break;
                    case 9: idx = 0x44; break;
                    default: return;
                }
            }
            break;
        case 4:
            if (arg1 == 0) {
                kind = 2;
                idx = 0xB;
            } else {
                kind = 1;
                idx = 0xC;
            }
            break;
        case 5: kind = 2; idx = 0xD; break;
        case 6: kind = 2; idx = 0xE; break;
        case 60: kind = 2; idx = 0x48; break;
        case 61: kind = 2; idx = 0x4D; break;
        case 7:
            if (arg1 == 0x12C) {
                arg1 = 0x19;
            }
            if (arg1 >= 0xFE && arg1 < 0x117) {
                arg1 = 0xC9;
            }
            if (arg1 == 0x117) {
                arg1 = 0x19;
            }
            if (arg1 <= 0 || arg1 >= 0xFC) {
                return;
            }
            switch (((u8 *)&D_8009022C)[arg1 * 4]) {
                case 0: idx = 0x11; kind = 1; break;
                case 1: idx = 0x10; kind = 1; break;
                case 2: idx = 0xF; kind = 1; break;
                default: return;
            }
            break;
        case 8: kind = 1; idx = 0x12; break;
        case 9: kind = 1; idx = 0x13; break;
        case 10: kind = 1; idx = 0x14; break;
        case 11: kind = 1; idx = 0x15; break;
        case 13: kind = 1; idx = 0x1A; break;
        case 12:
            if (arg1 == 0x12C || arg1 == 0x117) {
                kind = 1;
                idx = 0x19;
                break;
            }
            if (arg1 >= 0xFE && arg1 < 0x117) {
                arg1 = 0xC9;
            }
            if (arg1 <= 0 || arg1 >= 0xFC) {
                return;
            }
            switch (((u8 *)&D_8009022C)[arg1 * 4 + 1]) {
                case 0: idx = 0x18; kind = 1; break;
                case 1: idx = 0x17; kind = 1; break;
                case 2: idx = 0x16; kind = 1; break;
                default: return;
            }
            break;
        case 14: kind = 1; idx = 0x1B; break;
        case 15: kind = 1; idx = 0x1C; break;
        case 16: kind = 1; idx = 0x1D; break;
        case 40: kind = 1; idx = 0x1E; break;
        case 17: kind = 1; idx = 0x1F; break;
        case 18: kind = 1; idx = 0x20; break;
        case 19: kind = 1; idx = 0x22; break;
        case 20: kind = 1; idx = 0x23; break;
        case 21:
            func_800231A0(0xC9, 1, 1);
            return;
        case 22: kind = 1; idx = 0x25; break;
        case 23: kind = 1; idx = 0x26; break;
        case 24: kind = 1; idx = 0x27; break;
        case 25: kind = 1; idx = 0x28; break;
        case 47: kind = 1; idx = 0x4F; break;
        case 26: kind = 0; idx = 0x29; break;
        case 27: kind = 0; idx = 0x2A; break;
        case 28: kind = 0; idx = 0x2B; break;
        case 41: kind = 0; idx = 0x46; break;
        case 42: kind = 0; idx = 0x47; break;
        case 29: kind = 1; idx = 0x2C; break;
        case 30: kind = 1; idx = 0x2D; break;
        case 31: kind = 1; idx = 0x2E; break;
        case 32: kind = 1; idx = 0x2F; break;
        case 38:
            kind = 1;
            idx = 0x21;
            D_80090650[0] = 0;
            break;
        case 39:
            kind = 2;
            idx = 0x30;
            D_80090650[0] = 1;
            break;
        case 33: kind = 1; idx = 0x31; break;
        case 34: kind = 1; idx = 0x32; break;
        case 35: kind = 1; idx = 0x33; break;
        case 36: kind = 1; idx = 0x49; break;
        case 37: kind = 1; idx = 0x4A; break;
        case 46: kind = 1; idx = 0x4E; break;
        case 50:
            kind = 2;
            if (D_80090650[0] == 0) {
                idx = 0x38;
                break;
            }
            D_80090650[0] = 0;
            return;
        case 51:
            kind = 1;
            switch (arg1) {
                case 10: idx = 0x39; break;
                case 3: idx = 0x3A; break;
                case 2: idx = 0x3B; break;
                case 1: idx = 0x3C; break;
                case 0: idx = 0x3D; break;
                default: return;
            }
            break;
        case 52: kind = 2; idx = 0x45; break;
        case 70: kind = 2; idx = 0x4B; break;
        case 45: kind = 2; idx = 0x4C; break;
        case 100: kind = 0; idx = 0x3E; break;
        case 101: kind = 0; idx = 0x3F; break;
        case 102: kind = 0; idx = 0x40; break;
        case 103: kind = 0; idx = 0x41; break;
        case 104: kind = 0; idx = 0x42; break;
        case 105: kind = 0; idx = 0x43; break;
        case 106: kind = 0; idx = 0x44; break;
        default: break;
    }
    func_8001874C(((kind & 0xFF) << 8) | 0x06020000, idx);
}

void func_80024180(u32 arg0, s32 arg1) {
    switch (arg0) {
    case 0:
    case 26:
    case 27:
    case 28:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
        func_8001874C(0x06020005, 1);
        return;
    case 30:
    case 35:
        func_8001874C(0x06020105, 1);
        return;
    }
}

extern f32 D_8009064C;
extern struct {
    u8 pad[0x9C4];
    u8 unk_9C4;
} *D_800D1B70;
extern f32 __cosf(f32);
extern f32 __sinf(f32);

void func_8002421C(s32 arg0, f32 arg1, s32 arg2) {
    s32 left;
    s32 right;
    f32 angle;
    f32 ratio;
    s32 pad; // FAKE

    if (arg2 < 0) {
        D_8009061C[arg0][0] = 0;
        D_8009061C[arg0][1] = 63;
        D_8009061C[arg0][2] = 0;
        D_8009061C[arg0][3] = 0;
        return;
    }
    arg1 -= 16384.0f;
    angle = (D_8009064C / 32768.0f) * arg1;
    left = __cosf(angle) * 64.0f + 64.0f;
    if (left >= 128) {
        left = 127;
    }
    right = 64.0f - __sinf(angle) * 64.0f;
    if (right >= 128) {
        right = 127;
    }
    if (arg2 > 30000) {
        arg2 = 30000;
    }
    D_8009061C[arg0][0] = 1;
    D_8009061C[arg0][1] = left;
    D_8009061C[arg0][2] = right;
    ratio = (f32)(30000 - arg2) / 30000.0f;
    D_8009061C[arg0][3] = (u32)(ratio * 32768.0f);
    if (arg0 == 2 && D_80090BA0 == 9 && D_800D1B70 != NULL) {
        // 1U keeps IDO from reusing the s32 1 stored above for this u8 compare.
        if (D_800D1B70->unk_9C4 != 1U && D_800D1B70->unk_9C4 != 3) {
            func_8001874C(0x03020000, left);
            func_8001874C(0x12020000, right);
            func_80018704(0x01020000, ratio);
        }
    }
}

#endif
