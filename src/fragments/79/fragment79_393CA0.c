#include "global.h"

/* Existing retail debug literal immediately preceding this TU's early tables. */
#ifdef VERSION_US
const char D_8418AD80[] = "SendFightThread\n";
#endif


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84124410.s")
#endif

#ifdef VERSION_US
/* mkdraft:Audio_LookupScaledRatio_fragment79 begin */
extern u8 D_84185448[];
extern u8 D_84185454[];

u8 Audio_LookupScaledRatio_fragment79(u16 numerator, u16 denominator) {
    s32 scaled = (numerator * 48) / denominator;
    s32 index = 0;
    do {
        if (D_84185448[index * 2] >= scaled) {
            break;
        }
        index++;
    } while (D_84185454 != &D_84185448[index * 2]);
    return D_84185448[index * 2 + 1];
}
/* mkdraft:Audio_LookupScaledRatio_fragment79 end */
#endif

#ifdef VERSION_US
extern u8 *D_84195200[];
extern void func_84134CBC(u8, u8);
void func_84124594(u8 arg0) {
    if (D_84195200[arg0][0x24] & 7) {
        func_84134CBC(arg0, 4);
    } else if (D_84195200[arg0][0x24] & 0x20) {
        func_84134CBC(arg0, 2);
    } else {
        func_84134CBC(arg0, 3);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951E6;
extern void func_84134F78(u8, u8);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
void func_84124604(u8 arg0, u8 arg1) {
    func_84134DD8(arg1);
    if (D_84195200[arg0][0x24] & 7) {
        func_84134CBC(arg0, 0xB);
    } else if (D_84195200[arg0][0x24] & 0x20) {
        func_84134CBC(arg0, 0xD);
    } else {
        func_84134CBC(arg0, 0xA);
    }
    if (D_841951E6 != 0) {
        func_84134F78(arg0, 1);
    }
}
#endif

#ifdef VERSION_US
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84134E30(s32 arg0);
extern void func_84134E7C(u8 arg0, u8 arg1);
extern void func_84134F78(u8 arg0, u8 arg1);
extern u8 D_841951E6;
extern u8 * D_84195200[];
void func_841246AC(u8 arg0, u8 arg1) {
    func_84134DD8(arg1);
    func_84134E30(1);
    func_84134E7C(0, 1);
    if (D_84195200[arg0][0x24] & 7) {
        func_84134CBC(arg0, 0x13);
    } else if (D_84195200[arg0][0x24] & 0x20) {
        func_84134CBC(arg0, 0x12);
    } else {
        func_84134CBC(arg0, 0x11);
    }
    if (D_841951E6 != 0) {
        func_84134F78(arg0, 1);
    }
}
#endif

#ifdef VERSION_US
extern void func_84134DD8(u8);
void func_84124768(u8 arg0) {
    func_84134DD8(0xC2);
    func_84134CBC(arg0, 0x55);
}
#endif

#ifdef VERSION_US
extern u8 D_841951E4;
extern void func_84136678(u8, s16);
extern void func_84135B00(u16);
extern void func_84136218(u8, u8);
extern s32 func_841360C0(u8, s16, u16, u8, u8);
extern s32 func_8004C54C(u8, s32);
void func_84124798(u8 arg0) {
    u8 other = 1 - arg0;

    switch (D_841951E4) {
    case 1:
        func_84136678(arg0, -1);
        func_84135B00(41);
        func_84136218(arg0, 4);
        func_84136218(other, 3);
        if (func_841360C0(other, -1, 60, 3, 0) == 0) {
            func_8004C54C(26, (s32)(D_84195200[arg0] + 0x34));
            func_8004C54C(28, (s32)(D_84195200[other] + 0x34));
            func_841360C0(arg0, -1, 60, 4, 0);
            func_8004C54C(26, (s32)(D_84195200[other] + 0x34));
            func_8004C54C(28, (s32)(D_84195200[arg0] + 0x34));
        }
        break;
    case 2:
        func_84136678(arg0, -1);
        func_84135B00(62);
        break;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951E4, D_841951E5;
extern void func_84136678(u8, s16);
extern void func_84135B00(u16);
void func_841248DC(u8 arg0) {
    if (D_841951E4 != 2) {
        if (D_841951E5 >= 0xB) {
            func_84136678(arg0, -1);
            func_84135B00(0x25);
        } else if (D_841951E5 < 0xA) {
            func_84136678(arg0, -1);
            func_84135B00(0x44);
        }
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951E7;
extern u8 D_841951C6;
extern s32 *func_800635E0(u8);
extern s32 func_8004C54C(u8, s32);
void func_84124954(u8 arg0) {
    switch (D_841951E7) {
    case 1:
        func_84136678(arg0, -1);
        func_84135B00(0x62);
        break;
    case 2:
        func_84136678(arg0, -1);
        func_8004C54C(0x2A, func_800635E0(D_841951C6));
        func_84135B00(0x86);
        break;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951E6;
void func_841249D8(u8 arg0) {
    if (D_841951E6 == 0) return;
    func_84136678(arg0, -1);
    func_84135B00(0x7D);
}
#endif

#ifdef VERSION_US
extern u8 D_841951BF;
extern void func_84136D40(u8);
extern void func_84136CA8(void);
void func_84124A14(u8 arg0) {
    if (D_841951E6 == 2) {
        func_84136678(arg0, -1);
        func_84135B00(0x7B);
        func_84134DD8(D_841951BF);
        func_84134CBC(arg0, 0x27);
        func_84136D40(3);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern u8 func_80062D20(u8);
extern void func_84134E30(s32 arg0);
extern void func_84134E7C(u8 arg0, u8 arg1);
extern u8 D_841951BF;
extern u8 D_841951E5;
void func_84124A7C(void) {
    if (D_841951E4 == 1 || D_841951E4 == 2) { func_84134E30(4); func_84134E7C(0, 4); }
    else if (D_841951E5 >= 0xB) { func_84134E30(3); func_84134E7C(0, 3); }
    else if (D_841951E5 < 0xA) { func_84134E30(2); func_84134E7C(0, 2); }
    else { func_84134E30(0); func_84134E7C(0, 0); }
    if (D_841951BF == 0x14 || D_841951BF == 0x23 || D_841951BF == 0x84) { func_84134E30(5); func_84134E7C(0, 5); }
    if (func_80062D20(D_841951BF) == 0x75) { func_84134E30(5); func_84134E7C(0, 5); }
}
#endif

#ifdef VERSION_US
void func_84124BA0(u8 arg0) {
    if (D_84195200[arg0][0x24] & 7) {
        func_84134CBC(arg0, 8);
    } else if (D_84195200[arg0][0x24] & 0x20) {
        func_84134CBC(arg0, 9);
    } else {
        func_84134CBC(arg0, 7);
    }
}
#endif

#ifdef VERSION_US
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern u8 * D_84195200[];
void func_84124C10(u8 arg0) {
    u8 *ptr = D_84195200[arg0];
    if (*(u16 *)(ptr + 0x26) == 0) {
        func_84134CBC(arg0, 0x37);
    } else if (ptr[0x24] & 7) {
        func_84134CBC(arg0, 0x1F);
    } else if (ptr[0x24] & 0x20) {
        func_84134CBC(arg0, 0x20);
    } else {
        func_84134CBC(arg0, 0x1E);
    }
    func_84136A9C(arg0, -1, 0, 5);
}
#endif

#ifdef VERSION_US
extern void func_84134CBC(u8 arg0, u8 arg1);
extern u8 * D_84195200[];
void func_84124CC4(u8 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        if (D_84195200[arg0][0x24] & 7) {
            func_84134CBC(arg0, 0x2A);
        } else if (D_84195200[arg0][0x24] & 0x20) {
            func_84134CBC(arg0, 0x2B);
        } else {
            func_84134CBC(arg0, 0x29);
        }
    } else if (arg2 != 0) {
        if (D_84195200[arg0][0x24] & 7) {
            func_84134CBC(arg0, 0x39);
        } else if (D_84195200[arg0][0x24] & 0x20) {
            func_84134CBC(arg0, 0x3A);
        } else {
            func_84134CBC(arg0, 0x38);
        }
    } else {
        if (D_84195200[arg0][0x24] & 7) {
            func_84134CBC(arg0, 0x23);
        } else if (D_84195200[arg0][0x24] & 0x20) {
            func_84134CBC(arg0, 0x24);
        } else {
            func_84134CBC(arg0, 0x21);
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84134E30(s32); extern void func_84134E00(u8);
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern u8 D_841951BC;
extern u8 D_841951BF;
void func_84124DEC(u8 arg0) {
    if (arg0 == D_841951BC) {
        func_84134CBC(arg0, 0x41);
    } else {
        func_84124604(arg0, D_841951BF);
        func_84134E00(8);
        func_84134E30(5);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8004B7A4(s32);
extern s32 func_8004C54C(u8, s32);
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_84124E44(u8 arg0) {
    u8 other;

    func_8004C54C(0x19, func_8004B7A4(D_84195208[arg0][0]));
    func_8004C54C(0x1A, (s32)(D_84195200[arg0] + 0x34));
    other = 1 - arg0;
    func_8004C54C(0x1B, func_8004B7A4(D_84195208[other][0]));
    func_8004C54C(0x1C, (s32)(D_84195200[other] + 0x34));
}
#endif

#ifdef VERSION_US
s32 func_84124EFC(u8 arg0, u8 *arg1) {
    while (*arg1 != 0xFF) {
        if (*arg1 == arg0) {
            return 1;
        }
        arg1++;
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84124F40.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84125080.s")
#endif

#ifdef VERSION_US
extern u8 D_84195188[];
u8 func_84125158(u8 arg0) {
    return D_84195188[arg0];
}
#endif

#ifdef VERSION_US
extern u8 D_84195180;
u8 func_84125170(void) {
    return D_84195180;
}
#endif

#ifdef VERSION_US
extern u8 func_80063660(u8);
extern s32 func_84124EFC(u8, u8 *);
extern u8 D_8418549C[];
s32 func_8412517C(u8 arg0) {
    return func_84124EFC((u8)func_80063660(arg0), D_8418549C);
}
#endif

#ifdef VERSION_US
u8 func_841251B0(u8 arg0) {
    return (arg0 << 4) | (arg0 >> 4);
}
#endif

#ifdef VERSION_US
extern u8 func_80062D98(u8);
s32 func_841251CC(u8 arg0) {
    if (func_80062D98(arg0) < 0x14) return 0;
    return 1;
}
#endif

#ifdef VERSION_US
extern u8 D_841951D1, D_841951BC, D_841951BD;
extern u8 *D_84195208[];
s32 func_84125200(u8 arg0) {
    if (D_841951D1 == 0) return 1;
    if (arg0 == 0) {
        if (D_84195208[D_841951BD][0x1F] < D_84195208[D_841951BC][0x1E]) return 1;
        return 0;
    }
    if (D_84195208[D_841951BD][0x22] < D_84195208[D_841951BC][0x21]) return 1;
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_841252D0.s")
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern s32 D_841951B8;
void func_841253F4(void) {
    D_84195208[D_841951BC][0x29] = 1;
    D_841951B8 = -1;
}
#endif

#ifdef VERSION_US
extern u8 D_84195198[];
extern s32 D_841951B8;
void func_84125424(u8 arg0) {
    while ((D_84195198[D_841951B8] != 0xFF) && (D_84195198[D_841951B8] != arg0)) {
        D_841951B8++;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84195198[];
extern s32 D_841951B8;
void func_84125484(u8 arg0) {
    while ((D_841951B8 > 0) && (arg0 != D_84195198[D_841951B8])) {
        D_841951B8--;
    }
    D_841951B8--;
}
#endif

#ifdef VERSION_US
extern u8 D_84195198[];
void func_841254E0(void) {
    D_84195198[D_841951B8 + 1] = 0xFF;
    D_84195198[D_841951B8 + 2] = 0xFF;
    D_84195198[D_841951B8 + 3] = 0xFF;
}
#endif

#ifdef VERSION_US
extern u8 D_84185410[];
void func_84125508(u8 *arg0, u16 arg1, u8 arg2) {
    if (arg2 != 0) {
        *(u16 *)arg0 = (arg1 * D_84185410[(arg2 - 1) * 2]) / D_84185410[(arg2 - 1) * 2 + 1];
        if (*(u16 *)arg0 == 0) {
            *(u16 *)arg0 = 1;
        }
        if (*(u16 *)arg0 >= 1000) {
            *(u16 *)arg0 = 999;
        }
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84185410[];
void func_841255AC(u8 *arg0, u16 arg1, u8 arg2) {
    if (arg2 != 0) {
        *(u16 *)arg0 = (arg1 * D_84185410[(arg2 - 1) * 2 + 1]) / D_84185410[(arg2 - 1) * 2];
        if (*(u16 *)arg0 == 0) {
            *(u16 *)arg0 = 1;
        }
        if (*(u16 *)arg0 >= 1000) {
            *(u16 *)arg0 = 999;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84125508(u8 *, u16, u8);
void func_84125650(u8 *arg0, u8 arg1) {
    u16 flags;
    s32 i;

    i = 0;
    do {
        func_84125508((u8 *)((u32)arg0 + (i << 1) + 0x3C), *(u16 *)((u32)arg0 + (i << 1) + 0x32), *(u8 *)((u32)arg0 + i + 0x1E));
        i = (i + 1) & 0xFF;
    } while (i < 5);
    flags = *(u16 *)((u8 *)&arg1 - 1);
    if (!arg0) {
    }
    if (flags & 0x40) {
        *(u16 *)((u32)arg0 + 0x40) >>= 2;
    }
    if (flags & 0x10) {
        *(u16 *)((u32)arg0 + 0x3C) >>= 1;
    }
}
#endif

#ifdef VERSION_US
extern void func_84125508(u8 *arg0, u16 arg1, u8 arg2);
extern u8 * D_84195208[];
void func_841256E0(u8 arg0, u8 arg1) {
    u8 *base;
    u16 *entry;

    base = D_84195208[arg0];
    entry = (u16 *)base + arg1;
    func_84125508((u8 *)(entry + 0x1E), entry[0x19], (base + 0x1E)[arg1]);
}
#endif

#ifdef VERSION_US
extern u8 *D_84195200[];
extern u8 *D_84195208[];
extern void *D_841951F8[];
extern void func_84125650(u8 *, u8);
extern void func_841334D8(u8);
extern void Battle_RefreshSideAfterSwitch(u8);
void func_84125734(u8 arg0) {
    func_84125650(D_84195208[arg0], D_84195200[arg0][0x24]);
}
#endif

#ifdef VERSION_US
extern void func_84136B9C(u8, s16, u16);
extern void func_841566D0(u8, u8, u8);
extern void BattleRecord_AdvanceWriteSlot(void);
extern s32 func_84125778(u8);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern void * D_841951F8[];
extern u8 * D_84195200[];
extern u8 * D_84195208[];
s32 func_84125778(u8 arg0) {
    s32 kind;
    u8 flags;

    kind = func_80063660(D_84195200[arg0][1]);
    flags = D_84195200[arg0][0x24];
    switch (kind) {
    case 10:
        if ((flags & 0x8) == 0) {
            return 0;
        }
        break;
    case 11:
        if ((flags & 0x20) == 0) {
            return 0;
        }
        break;
    case 12:
        if ((flags & 0x10) == 0) {
            return 0;
        }
        break;
    case 13:
        if ((flags & 0x7) == 0) {
            return 0;
        }
        break;
    case 14:
        if ((flags & 0x40) == 0) {
            return 0;
        }
        break;
    case 15:
        if ((flags & 0x7F) == 0) {
            return 0;
        }
        break;
    default:
        return 0;
    }
    func_84136B9C(arg0, -1, 0);
    func_84136678(arg0, -1);
    func_84135B00(72);
    func_84134DD8(D_841951BF);
    if (flags & 0x20) {
        func_84134CBC(arg0, 44);
    } else if (flags & 7) {
        func_84134CBC(arg0, 29);
        func_841566D0(D_841951BC, ((u8 *)D_841951F8[D_841951BC])[0xA], 0x20);
    } else {
        func_84134CBC(arg0, 86);
    }
    BattleRecord_AdvanceWriteSlot();
    D_84195200[arg0][0x24] = 0;
    D_84195208[arg0][0x14] = 0;
    D_84195208[arg0][0x11] &= 0xFFFE;
    D_84195208[arg0][0xD] &= 0xFFFE;
    if (kind == 15) {
        D_84195208[arg0][0xF] &= 0xFF7F;
    }
    func_84125734(arg0);
    if (func_8412517C(D_84195200[arg0][1])) {
        D_84195200[arg0][1] = 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern void BattleRecord_AdvanceWriteSlot(void);
void func_841259D4(u8 arg0) {
    s32 result;

    if (D_84195208[arg0][0xF] & 0x80) {
        result = func_80063660(D_84195200[arg0][1]);
        if (result == 16 || result == 15) {
            D_84195208[arg0][0xF] &= ~0x80;
            func_84136678(arg0, -1);
            func_8004C54C(28, (s32)D_84195200[arg0] + 0x34);
            func_8004C54C(42, func_800635E0(D_84195200[arg0][1]));
            func_84135B00(95);
            func_84134CBC(arg0, 86);
            BattleRecord_AdvanceWriteSlot();
            D_84195200[arg0][1] = 0;
        }
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951C3;
s32 func_84125AB8(u8 arg0) {
    if ((s32) D_841951C3 < 0x12) {
        return 0;
    }
    if ((s32) D_841951C3 < 0x19) {
        return ((*(u8 *)((u8 *)(D_84195208[arg0]) + (0x10))) & 2) != 0;
    }
    if ((s32) D_841951C3 < 0x3A) {
        return 0;
    }
    if ((s32) D_841951C3 < 0x41) {
        return ((*(u8 *)((u8 *)(D_84195208[arg0]) + (0x10))) & 2) != 0;
    }
    if ((s32) D_841951C3 < 0x44) {
        return 0;
    }
    if ((s32) D_841951C3 < 0x4B) {
        return ((*(u8 *)((u8 *)(D_84195208[arg0]) + (0x10))) & 2) != 0;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 * D_84195208[];
s32 func_84125B88(u8 arg0, u8 arg1, u8 arg2) {
    if (arg2 == 0) {
        if (*(D_84195208[arg0] + arg1 + 0x1E) >= 0xD) return 0;
        if (arg1 != 5 && arg1 != 6 && *(u16 *)(D_84195208[arg0] + 0x3C + arg1 * 2) >= 0x3E7) return 0;
    } else {
        if (*(D_84195208[arg0] + arg1 + 0x1E) < 2) return 0;
        if (arg1 != 5 && arg1 != 6 && *(u16 *)(D_84195208[arg0] + 0x3C + arg1 * 2) < 2) return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern u8 D_841951D2;
extern u8 D_841951D3;
extern u8 * D_84195208[];
s32 func_84125C68(u8 arg0, u8 arg1) {
    if (D_841951D2 != 0) {
        return 0;
    }
    if (D_841951D3 != 0) {
        return 0;
    }
    if (arg1 == 1) {
        if (D_84195208[arg0][0x10] & 0x10) {
            return 0;
        }
        if (D_84195208[arg0][0xF] & 0x60) {
            return 0;
        }
    }
    return 1;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84125CF8.s")
#endif

#ifdef VERSION_US
extern void func_841256E0(u8 arg0, u8 arg1);
extern s32 func_84125AB8(u8 arg0);
extern s32 func_84125B88(u8 arg0, u8 arg1, u8 arg2);
extern u8 D_841951BF;
extern u8 D_841951D8;
extern u8 D_841951D9;
extern u8 * D_84195208[];
void func_84125EC0(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    arg1 = arg1 & 0xFF;
    D_841951D9 = arg1 | ((arg2 - 1) << 4);
    if (arg3 == 1 && func_84125AB8(arg0) != 0) {
        D_841951D8 = 3;
        return;
    }
    if (func_84125B88(arg0, arg1, arg3) != 0) {
        *(D_84195208[arg0] + arg1 + 0x1E) += (1 - arg3 * 2) * arg2;
        if (*(D_84195208[arg0] + arg1 + 0x1E) >= 0xE) {
            *(D_84195208[arg0] + arg1 + 0x1E) = 0xD;
            }
        if (*(D_84195208[arg0] + arg1 + 0x1E) <= 0) {
            *(D_84195208[arg0] + arg1 + 0x1E) = 1;
        }
        if (arg1 < 4) {
            func_841256E0(arg0, arg1);
        }
        if (arg1 == 6 && D_841951BF == 0x6B) {
            D_84195208[arg0][0x2A] = 1;
        }
        D_841951D8 = 0;
        return;
    }
    D_841951D8 = 2;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_84126064 begin */
extern void * D_841951F8[];


s32 func_84126064(u8 arg0) {
    u8 count = 0;
    u8 *ptr = D_841951F8[arg0];
    s32 i = 0;

    if (ptr[8] > 0) {
        do {
            if (*(u16 *)(ptr + i + 0x3E) > 0) {
                count++;
            }
            i += 0x58;
        } while (i < ptr[8] * 0x58);
    }
    ptr[9] = count;
    return count;
}
/* mkdraft:func_84126064 end */
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
s32 func_841260D4(u8 arg0, u8 arg1, u8 arg2) {
    u8 count = 0;
    s32 i;

    for (i = arg1; i < arg2; i++) {
        if (*(u16 *)((u8 *)D_841951F8[arg0] + i * 0x58 + 0x3E) > 0) {
            count++;
        }
    }
    return count;
}
#endif

#ifdef VERSION_US
extern void func_84126200(u8); extern s32 func_84126260(u8); extern s32 func_84126064(u8); extern s32 func_841260D4(u8, u8, u8); extern s32 func_84129C8C(u8);
extern void * D_841951F8[];
void func_84126200(u8 arg0) {
    u8 *ptr = D_841951F8[arg0];

    if (ptr[0xA] < ptr[3]) {
        func_841260D4(arg0, 0, ptr[3]);
    } else {
        func_841260D4(arg0, ptr[3], ptr[8]);
    }
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
s32 func_84126260(u8 arg0) {
    u8 *ptr = D_841951F8[arg0];

    if (ptr[0xA] < ptr[3]) {
        func_841260D4(arg0, ptr[3], ptr[8]);
    } else {
        func_841260D4(arg0, 0, ptr[3]);
    }
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
extern s32 func_84126260(u8);
extern s32 func_84126064(u8);
s32 func_841262C4(u8 arg0) {
    if (((u8 *) D_841951F8[arg0])[0x12] != 0) {
        return 0 < func_84126260(arg0);
    } else {
        return func_84126064(arg0) >= 2;
    }
}
#endif

#ifdef VERSION_US
extern void func_84134E30(s32); extern u8 D_84199D81; extern u8 D_8418548C[];
extern s32 func_84126064(u8);
extern void func_84126200(u8 arg0);
extern void * D_841951F8[];
s32 func_84126320(u8 arg0) {
    if (((u8 *) D_841951F8[arg0])[0x12] != 0) {
        func_84126200(arg0);
    } else {
        return func_84126064(arg0);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951BE;
s32 func_84126374(void) {
    return D_841951BC == D_841951BE;
}
#endif

#ifdef VERSION_US
s32 func_84126390(u8 arg0, u8 arg1)
{
  s32 result = arg1 == D_84195208[arg0][1];
  u8 *ptr = D_84195208[arg0];
  if (result == 0)
  {
    result = arg1 == ptr[2];
  }
  return result;
}
#endif

#ifdef VERSION_US
extern u8 * D_84195208[];
s32 func_841263D8(u8 arg0, u8 arg1) {
    u8 *ptr;
    s32 i;
    u8 value;
    arg1 &= 0xFF;
    ptr = D_84195208[arg0];
    i = 0;
    while (1) {
        value = *(u8 *)((unsigned long)ptr + (unsigned long)i + 5);
        if (value != 0) {
            if (value == arg1) {
                return (i + 1) & 0xFF;
            }
            i = (i + 1) & 0xFF;
            if (i < 4) {
                continue;
            }
        }
        return 0;
    }
}
#endif

#ifdef VERSION_US
extern u8 func_80062D20(u8);
s32 func_84126440(u8 arg0) {
    switch (func_80062D20(arg0)) {
    case 0x91:
        return 1;
    case 0x27:
        return 1;
    case 0x4B:
        return 1;
    case 0x97:
        return 1;
    case 0x9B:
        return 1;
    case 0x1A:
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_84126440(u8);
s32 BattleMove_IsSleepTalkEffectExcluded(u8 move) {
    return func_84126440(move);
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_841264F0(u8 arg0) {
    D_84195208[arg0][0xD] &= 0xFFBF;
    D_84195208[arg0][0xF] &= 0xFFEC;
    if (((u8 *)D_841951F8[arg0])[1] == 0x13 || ((u8 *)D_841951F8[arg0])[1] == 0x5B) {
        D_84195208[arg0][0xF] &= 0xFF9F;
    }
    D_84195208[arg0][0x18] = 0;
}
#endif

#ifdef VERSION_US
extern u8 * D_84195208[];
s32 func_84126568(u8 arg0) {
    u8 *ptr = D_84195208[arg0];
    if (ptr[0x10] & 0x20) {
        return 1;
    }
    if (ptr[0xF] & 0x13) {
        return 1;
    }
    if (ptr[0xD] & 0x40) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 D_841951D6;
extern s32 D_841951C8;
void func_841265D4(void) {
    D_841951D6 = 1;
    D_841951C8 = 0;
}
#endif

#ifdef VERSION_US
extern u16 D_841951CC, D_841951CE;
extern u8 D_841951D0;
extern u8 D_841951BC;
extern s8 D_841951C2;
extern s32 D_841951C8;
extern void * D_841951F8[];
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_841265EC(void) { s32 offset = D_841951BC * 4; u8 *src = *(u8 **)((u8 *)D_84195208 + offset); D_841951C8 = 0; D_841951CC = *(u16 *)(src + 0x3C); D_841951CE = *(u16 *)(src + 0x3E); if (((u8 *)*(void **)((u8 *)D_841951F8 + offset))[0xB] & 0x10) D_841951CE = D_841951CE << 1; if (D_841951CC >= 0x100 || D_841951CE >= 0x100) { D_841951CC >>= 2; if (!D_841951CC) D_841951CC = 1; D_841951CE >>= 2; if (!D_841951CE) D_841951CE = 1; } D_841951C2 = 0x28; D_841951D0 = (*(u8 **)((u8 *)D_84195200 + offset))[0x1D]; }
#endif

#ifdef VERSION_US
extern void func_841252D0(u8);
extern s32 func_841263D8(u8 arg0, u8 arg1);
extern u8 D_841951BC;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_841266C4(void) {
    s32 result;

    D_84195208[D_841951BC][3] = ((u8 *)D_841951F8[D_841951BC])[1];
    result = func_841263D8(D_841951BC, D_84195208[D_841951BC][3]);
    if (result != 0) {
        D_84195208[D_841951BC][4] = result - 1;
    }
    func_841252D0(D_84195208[D_841951BC][3]);
}
#endif

#ifdef VERSION_US
extern u8 * D_84195200[];
s32 func_8412676C(u8 arg0, u8 arg1) {
    u16 *ptr = (u16 *)D_84195200[arg0];
    s32 result;
    u16 limit;
    result = (u16)(ptr[0x14] >> arg1);
    limit = ptr[0x13];
    if (result > limit) {
        result = limit & 0xFFFF;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 * D_84195200[];
s32 func_841267B4(u8 arg0, u8 arg1) { struct Record { u8 pad[0x26]; u16 b; u16 a; }; struct Record *record = (struct Record *)D_84195200[arg0]; s32 result = (record->a >> arg1) & 0xFFFF; if (record->a < record->b + result) result = (record->a - record->b) & 0xFFFF; return result; }
#endif

#ifdef VERSION_US
/* mkdraft:func_84126804 begin */
extern float sqrtf(float value);
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];
extern u8 *D_84195200[];

u32 func_84126804(u8 arg0, u16 arg1)
{
  u8 *ptr = D_84195200[arg0];
  u16 take = arg1;
  arg0 = 0;
  if ((*((u16 *) (ptr + 0x26))) < arg1)
  {
    arg1 = *((u16 *) (ptr + 0x26));
    take = arg1;
  }
  *((u16 *) (ptr + 0x26)) = (*((u16 *) (ptr + 0x26))) - take;
  return arg1;
}
/* mkdraft:func_84126804 end */
#endif

#ifdef VERSION_US
extern u8 * D_84195200[];
u16 func_84126850(u8 arg0, u16 arg1) {
    u8 *ptr = D_84195200[arg0];

    if (*(u16 *)(ptr + 0x28) < *(u16 *)(ptr + 0x26) + arg1) {
        arg1 = *(u16 *)(ptr + 0x28) - *(u16 *)(ptr + 0x26);
    }
    *(u16 *)(ptr + 0x26) += arg1;
    return arg1;
}
#endif

#ifdef VERSION_US
extern u16 D_841951CA;
extern void func_8412EE5C(void);
extern void func_841265EC(void);
extern u32 func_84126804(u8, u16);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern s32 D_841951C8;
void func_841268A0(void) {
    func_84136678(D_841951BC, -1);
    func_84135B00(0x5C);
    func_84134CBC(D_841951BC, 1);
    func_84136CA8();
    D_841951D1 = 0;
    func_841265EC();
    func_8412EE5C();
    D_841951C8 = func_84126804(D_841951BC, D_841951CA);
    func_84136A9C(D_841951BC, -1, -D_841951C8, 1);
}
#endif

#ifdef VERSION_US
void func_8412693C(u8 arg0) {
    D_84195208[arg0][0x1E] = 7;
    D_84195208[arg0][0x1F] = 7;
    D_84195208[arg0][0x20] = 7;
    D_84195208[arg0][0x21] = 7;
    D_84195208[arg0][0x22] = 7;
    D_84195208[arg0][0x23] = 7;
    D_84195208[arg0][0x24] = 7;
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
extern u8 * D_84195208[];
extern u8 * D_8419520C[];
void func_84126994(u8 arg0) { s32 offset; u8 **other; D_84195208[arg0][0x26]=0; D_84195208[arg0][0x27]=0; D_84195208[arg0][0x0D]=0; D_84195208[arg0][0x0E]=0; D_84195208[arg0][0x0F]=0; D_84195208[arg0][0x10]=0; D_84195208[arg0][0x11]=0; D_84195208[arg0][0x15]=0; offset=arg0<<2; offset=-offset; other=(u8 **)((u8 *)D_8419520C+offset); D_84195208[arg0][0x18]=0; D_84195208[arg0][0x19]=0; D_84195208[arg0][0x1D]=0; D_84195208[arg0][0x25]=0; D_84195208[arg0][0x2A]=0; D_84195208[arg0][0x1B]=0; (*other)[0x26]=0; (*other)[0x1B]=0; (*other)[0x11]&=0xFF7F; ((u8 *)D_841951F8[arg0])[6]=0; }
#endif

#ifdef VERSION_US
void func_84126A64(void) {
    D_84195208[0][0xD] &= 0xFF7F;
    D_84195208[1][0xD] &= 0xFF7F;
}
#endif

#ifdef VERSION_US
extern void func_841246AC(u8, u8);
extern u8 D_841951BF;
extern u8 *D_84195208[];
extern void func_84136678(u8, s16);
extern void func_84135B00(u16);
extern void func_84136CA8(void);
void func_84126A90(u8 arg0, u8 arg1, u8 arg2) {
    func_84136678(arg0, -1);
    if ((arg2 != 0) && (D_84195208[arg1][0xD] & 4)) {
        func_84135B00(0xA5);
    } else {
        func_84135B00(0xA4);
    }
    func_841246AC(arg1, D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
void func_84126B1C(u8 arg0, u8 arg1, u8 arg2) {
    func_84136678(arg0, -1);
    if ((arg2 != 0) && (D_84195208[arg1][0xD] & 4)) {
        func_84135B00(0x56);
    } else {
        func_84135B00(0x55);
    }
    func_841246AC(arg1, D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
extern void func_841246AC(u8, u8);
void func_84126BA8(u8 arg0) {
    func_84136678(arg0, -1);
    func_84135B00(0xB5U);
    func_841246AC((1 - arg0) & 0xFF, D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
void func_84126BFC(u8 arg0) {
    func_84136678(arg0, -1);
    func_84135B00(0xB5U);
    func_84124594(arg0);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
extern void func_841246AC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136CA8(void);
extern u8 D_841951BF;
extern u8 * D_8419520C[];
void func_84126C3C(u8 arg0) {
    func_84136678(arg0, -1);
    if ((*(u8 **)((u8 *)D_8419520C + -(arg0 << 2)))[0xD] & 4) {
        func_84135B00(0xB6);
    } else {
        func_84135B00(0xB5);
    }
    func_841246AC((1 - arg0) & 0xFF, D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84126CD0.s")
#endif

#ifdef VERSION_US
// Hidden Power base power from a packed DV word (attack, defense, speed and special
// nibbles from high to low): (5 * (top bit of each DV) + (special DV & 3)) / 2 + 31.
s32 func_84126E88(u16 dvs) {
    u16 power = ((dvs & 0x8000) >> 12) | ((dvs & 0x800) >> 9) | ((dvs & 0x80) >> 6) | ((dvs & 8) >> 3);

    power *= 5;
    power += dvs & 3;
    power >>= 1;
    power += 31;
    return power;
}
#endif

#ifdef VERSION_US
s32 func_84126EDC(u16 arg0) {
    u8 value;

    value = (((arg0 & 0x3000) >> 10) | ((arg0 & 0x300) >> 8)) + 1;
    if (value >= 6) {
        value++;
        if (value >= 10) {
            value += 10;
        }
    }
    return value;
}
#endif

#ifdef VERSION_US
extern void *D_841951F8[];

s32 func_84126F2C(u8 arg0, u16 arg1) {
    s32 i = 0;
    u8 *ptr = D_841951F8[arg0];

    for (; i < ptr[8]; i++) {
        if ((*(u16 *)(ptr + i * 0x58 + 0x3E) != 0) && (*(u8 *)(ptr + i * 0x58 + 0x3C) & arg1)) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void *func_8004C874(s32, s32);
void func_84126FA0(u8 arg0) {
    switch (arg0) {
    case 0:
        func_8004C54C(43, (s32)func_8004C874(16, 9));
        break;
    case 1:
        func_8004C54C(43, (s32)func_8004C874(16, 11));
        break;
    case 2:
        func_8004C54C(43, (s32)func_8004C874(16, 13));
        break;
    case 3:
        func_8004C54C(43, (s32)func_8004C874(16, 14));
        break;
    case 4:
        func_8004C54C(43, (s32)func_8004C874(16, 15));
        break;
    case 5:
        func_8004C54C(43, (s32)func_8004C874(16, 12));
        break;
    case 6:
        func_8004C54C(43, (s32)func_8004C874(16, 10));
        break;
    case 7:
        func_8004C54C(43, (s32)func_8004C874(16, 8));
        break;
    }
}
#endif

#ifdef VERSION_US
extern void *D_841951F0;

// Stores (arg0 & 1) << 4 | (arg1 & 0xF) into the first 0xFF byte of the
// 12-byte table at D_841951F0 + 0x9C8. Declared s32 but has no return on the
// path that reaches the end; its caller discards the result.
s32 func_841270D8(u8 arg0, u8 arg1)
{
  s32 slot;
  slot = 0;
  if ((*((u8 *) (((u8 *) D_841951F0) + 0x9C8))) != 0xFF)
  {
 while (slot != 11) { slot++; // FAKE: one-line loop head (permuter layout)
      if ((*((u8 *) ((((u8 *) D_841951F0) + 0x9C8) + slot))) == 0xFF)
      {
        break;
        return slot; // FAKE: unreachable after break
      }
    }

  }
  *((u8 *) ((((u8 *) D_841951F0) + 0x9C8) + slot)) = ((arg0 & 1) << 4) | (arg1 & 0xF);
}
#endif

#ifdef VERSION_US
extern void *D_841951F8[];
s32 func_84127140(u8 a) {
    u8 *p;
    u8 x;
    u8 *new_var;

    p = D_841951F8[a];
    x = p[0x49A];
    new_var = p;
    if (p[0x11] != 0) {
        return 0;
    }
    if ((x > 0) && (x < 0xFF)) {
        return 1;
    }
    return new_var[0x49A] * 0;
}
#endif

#ifdef VERSION_US
extern u8 D_841951D7;
extern u8 D_841951D5;
extern u16 D_841951EA;
extern void *func_84156590(u8, u8);
extern void func_841566D0(u8, u8, u8);
extern s32 func_80062CE0(u8);
extern void func_84136B9C(u8, s16, u16);
extern void BattleRecord_AdvanceWriteSlot(void);
extern s32 func_8004C54C(u8, s32);
extern void func_84124594(u8 arg0);
extern void func_84124E44(u8 arg0);
extern s32 func_84125080(void);
extern void func_841264F0(u8 arg0);
extern void func_841265D4(void);
extern void func_841268A0(void);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16 arg0);
extern s32 func_841360C0(u8 arg0, s16 arg1, u16 arg2, u8 arg3, u8 arg4);
extern void func_84136218(u8 arg0, u8 arg1);
extern void func_84136678(u8 arg0, s16 arg1);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951D2;
extern u8 D_841951D3;
extern u8 D_841951E4;
extern u8 D_841951E5;
extern u8 D_841951E6;
extern u8 D_841951E7;
extern u16 D_841951E8;
extern void * D_841951F8[];
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleTurn_CheckMoveStatus(void) {
    if (((u8 *)D_841951F8[D_841951BC])[1] == 0) {
        func_841265D4();
        return;
    }
    D_841951D2 = 0;
    D_841951D3 = 0;
    D_841951D7 = 0;
    D_841951D5 = 10;
    D_841951E5 = 10;
    D_841951E4 = 0;
    D_841951E6 = 0;
    D_841951E7 = 0;
    D_841951E8 = 0;
    D_841951EA = 0;
    if (D_84195208[D_841951BC][16] & 0x20) {
        D_84195208[D_841951BC][16] &= ~0x20;
        func_84136678(D_841951BC, -1);
        func_84135B00(84);
        BattleRecord_AdvanceWriteSlot();
        func_84124594(D_841951BC);
        BattleRecord_AdvanceWriteSlot();
        func_841264F0(D_841951BC);
        func_841265D4();
        return;
    }
    if (D_84195200[D_841951BC][36] & 7) {
        ((u8 *)func_84156590(D_841951BC, ((u8 *)D_841951F8[D_841951BC])[10]))[13]++;
        D_84195200[D_841951BC][36]--;
        if (D_84195200[D_841951BC][36] > 0) {
            func_84136678(D_841951BC, -1);
            func_84135B00(168);
            BattleRecord_AdvanceWriteSlot();
            func_84134CBC(D_841951BC, 4);
            if (((u8 *)D_841951F8[D_841951BC])[1] != 173 && ((u8 *)D_841951F8[D_841951BC])[1] != 214) {
                BattleRecord_AdvanceWriteSlot();
                func_841264F0(D_841951BC);
                func_841265D4();
                return;
            }
        } else {
            func_84136678(D_841951BC, -1);
            func_84135B00(169);
            BattleRecord_AdvanceWriteSlot();
            func_84136B9C(D_841951BC, -1, 0);
            func_84134CBC(D_841951BC, 29);
            func_841264F0(D_841951BC);
            D_84195208[D_841951BC][13] &= ~1;
            func_841566D0(D_841951BC, ((u8 *)D_841951F8[D_841951BC])[10], 0x20);
        }
    }
    if (D_84195200[D_841951BC][36] & 0x20) {
        BattleRecord_AdvanceWriteSlot();
        if (((u8 *)D_841951F8[D_841951BC])[1] != 172 && ((u8 *)D_841951F8[D_841951BC])[1] != 221) {
            func_84136678(D_841951BC, -1);
            func_84135B00(66);
            func_84134CBC(D_841951BC, 2);
            BattleRecord_AdvanceWriteSlot();
            func_841264F0(D_841951BC);
            func_841265D4();
            return;
        } else {
            func_84136678(D_841951BC, -1);
            func_84136B9C(D_841951BC, -1, 0);
            func_84135B00(77);
            func_84134CBC(D_841951BC, 44);
            D_84195200[D_841951BC][36] &= ~0x20;
        }
    }
    if (D_84195208[D_841951BC][15] & 8) {
        BattleRecord_AdvanceWriteSlot();
        func_84136678(D_841951BC, -1);
        func_84135B00(90);
        func_84124E44(D_841951BD);
        func_84136218(D_841951BD, 6);
        func_841360C0(D_841951BD, -2, 60, 6, 7);
        func_84124594(D_841951BC);
        BattleRecord_AdvanceWriteSlot();
        D_84195208[D_841951BC][15] &= ~8;
        func_841264F0(D_841951BC);
        func_841265D4();
        return;
    }
    if (D_84195208[D_841951BC][21] > 0) {
        D_84195208[D_841951BC][21]--;
        D_84195208[D_841951BC][21] &= 0xF;
        if (D_84195208[D_841951BC][21] == 0) {
            D_84195208[D_841951BC][37] = 0;
            func_84136678(D_841951BC, -1);
            func_84135B00(159);
        }
    }
    if (D_84195208[D_841951BC][15] & 0x80) {
        func_84136678(D_841951BC, -1);
        D_84195208[D_841951BC][19]--;
        if (D_84195208[D_841951BC][19] == 0) {
            D_84195208[D_841951BC][15] &= ~0x80;
            func_84135B00(93);
        } else {
            func_84135B00(91);
            BattleRecord_AdvanceWriteSlot();
            func_84134CBC(D_841951BC, 38);
            if (func_84125080() < 128) {
                BattleRecord_AdvanceWriteSlot();
                D_84195208[D_841951BC][15] &= 0x80;
                func_841268A0();
                func_84134CBC(D_841951BC, 16);
                BattleRecord_AdvanceWriteSlot();
                func_841264F0(D_841951BC);
                func_841265D4();
                return;
            }
        }
    }
    if (D_84195208[D_841951BC][13] & 0x80) {
        func_84136678(D_841951BC, -1);
        func_84135B00(120);
        BattleRecord_AdvanceWriteSlot();
        if (func_84125080() >= 128) {
            func_84136678(D_841951BC, -1);
            func_84135B00(121);
            func_841264F0(D_841951BC);
            func_841265D4();
            func_84134CBC(D_841951BC, 6);
            BattleRecord_AdvanceWriteSlot();
            return;
        } else {
            func_84134CBC(D_841951BC, 6);
        }
    }
    if (((u8 *)D_841951F8[D_841951BC])[1] != 0 && ((u8 *)D_841951F8[D_841951BC])[1] == D_84195208[D_841951BC][37]) {
        D_84195208[D_841951BC][15] &= ~0x10;
        func_84136678(D_841951BC, -1);
        func_8004C54C(29, func_80062CE0(((u8 *)D_841951F8[D_841951BC])[1]));
        func_84135B00(42);
        BattleRecord_AdvanceWriteSlot();
        func_841264F0(D_841951BC);
        func_841265D4();
        func_84124594(D_841951BC);
        BattleRecord_AdvanceWriteSlot();
        return;
    }
    if (D_84195200[D_841951BC][36] & 0x40) {
        if (func_84125080() < 63) {
            func_84136678(D_841951BC, -1);
            func_84135B00(109);
            BattleRecord_AdvanceWriteSlot();
            func_841264F0(D_841951BC);
            func_841265D4();
            func_84134CBC(D_841951BC, 54);
            BattleRecord_AdvanceWriteSlot();
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_841278E4.s")
#endif

#ifdef VERSION_US
extern u8 D_841951C0;

void func_84127B00(void) {
    if (D_84195208[D_841951BC][0x29] != 0) {
        return;
    }
    if (D_841951BF == 0xA5) {
        return;
    }
    if (D_84195208[D_841951BC][0xF] & 7) {
        return;
    }
    if ((D_84195208[D_841951BC][D_841951C0 + 9] & 0x3F) > 0) {
        D_84195208[D_841951BC][D_841951C0 + 9]--;
        if (D_84195208[D_841951BC][0x11] & 8) {
            return;
        }
        if (D_84195200[D_841951BC][D_841951C0 + 2] == 0x66) {
            if (D_84195208[D_841951BC][D_841951C0 + 5] != 0x66) {
                return;
            }
        }
        D_84195200[D_841951BC][D_841951C0 + 0x18]--;
        return;
    }
    D_841951D2 = 1;
    func_84136678(D_841951BC, -1);
    if ((D_841951C3 == 0x1A) || (D_841951C3 == 0x1B) || (D_841951C3 == 0x27) || (D_841951C3 == 0x4B) || (D_841951C3 == 0x75) || (D_841951C3 == 0x91) || (D_841951C3 == 0x97) || (D_841951C3 == 0x9B)) {
        func_84135B00(0x93);
    } else {
        func_84135B00(0x92);
    }
    func_84134CBC(D_841951BC, 5);
    func_84136CA8();
    func_841254E0();
}
#endif

#ifdef VERSION_US
extern u8 D_8418547C[];
extern u8 D_84185484[];
extern u8 D_841951C5;
extern s32 func_84125080(void);
extern u8 func_80063660(u8);
extern s32 func_84124EFC(u8 arg0, u8 *arg1);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern s8 D_841951C2;
extern u8 * D_84195208[];
void BattleDamage_RollCriticalHit(void) {
    u8 stage;
    D_841951D1 = 0;
    D_841951E4 = 0;
    if ((u8)D_841951C2 != 0) {
        stage = 0;
        switch (D_84195208[D_841951BC][0]) {
        case 113:
            if (D_841951C5 == 30) {
                stage = 2;
            }
            break;
        case 83:
            if (D_841951C5 == 105) {
                stage = 2;
            }
            break;
        default:
            if (D_84195208[D_841951BC][16] & 4) {
                stage = 1;
            }
            if (func_84124EFC(D_841951BF, D_8418547C)) {
                stage += 2;
            }
            if (func_80063660(D_841951C5) == 73) {
                stage++;
            }
            break;
        }
        if (func_84125080() < D_84185484[stage]) {
            D_841951D1 = 1;
            D_841951E4 = 1;
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84127DB8.s")
#endif

#ifdef VERSION_US
extern u8 func_800632CC(s32 *, u8, u8, u8, s32);
extern void func_84124360(s32 *, u8, u8);
extern s32 func_84126390(u8 arg0, u8 arg1);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern s8 D_841951C1;
extern u8 D_841951C3;
extern s32 D_841951C8;
extern u8 D_841951D2;
extern u8 D_841951D5;
extern void * D_841951F0;
extern u8 * D_84195208[];
void func_841280D8(void) {
    u8 result;
    if (D_841951BF != 165) {
    if (func_84126390(D_841951BC, D_841951C1) != 0) {
        D_841951C8 += D_841951C8 >> 1;
        D_841951D5 |= 0x80;
    }
    func_84124360(&D_841951C8, ((u8 *)D_841951F0)[2500], D_841951C1);
    if (D_841951C3 == 151 && ((u8 *)D_841951F0)[2500] == 1) {
        D_841951C8 >>= 1;
    }
    result = func_800632CC(&D_841951C8, D_841951C1, D_84195208[D_841951BD][1], D_84195208[D_841951BD][2], (D_84195208[D_841951BD][13] & 8) != 0);
    if (result == 0) D_841951D2 = 1;
    D_841951D5 = (D_841951D5 & 0x80) | result;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_841951C8;

// Same function as func_84125080 (undefined_syms.ld); this caller declares the return as
// unsigned short because that type puts the result in a separate temp, which IDO
// colors v1 via `move v1,v0` in both loop delay slots. The callee returns an lbu byte.
extern unsigned short func_84125080_u16();
void func_84128204(void)
{
  s32 temp_v0;
  s32 temp_v0_2;
  s32 new_var2;
  s32 var_v1;
  s32 new_var;
  if (D_841951C8 >= 2)
  {
    temp_v0 = func_84125080_u16();
    var_v1 = temp_v0;
    if (temp_v0 < 217)
    {
      do
      {
        temp_v0_2 = func_84125080_u16();
        var_v1 = temp_v0_2;
      }
      while (temp_v0_2 < 217);
    }
    // FAKE: xor-0 arithmetic nop; the promotion web its conversion node creates claims a
    // uopt walk slot (the zero-instruction-temp family - see func_80019C08's documented xor-0).
    D_841951C8 = ((s32) ((new_var = var_v1 ^ 0) * D_841951C8)) / 255;
    new_var2 = D_841951C8;
    // FAKE: multiply-by-zero spells the zero constant as an expression tree, keeping the
    // compare's operand out of the shared-constant pool (permuter-found, same device family).
    if (new_var2 == (217 * 0))
    {
      D_841951C8 += 1;
    }
  }
}
#endif

#ifdef VERSION_US
extern u8 D_841951C3; extern u8 D_841951D2;
void func_84128298(void) { if (D_841951C3 != 0x2D) D_841951C8 = 0; D_841951D2 = 1; }
#endif

#ifdef VERSION_US
s32 func_841282C0(void)
{
  u8 *temp_v0;
  u8 temp_v1;
  temp_v0 = D_84195208[D_841951BD];
  ;
  if ((*((u8 *) (((u8 *) temp_v0) + 0x11))) & 0x20)
  {
    *((u8 *) (((u8 *) temp_v0) + 0x11)) = (u8) ((*((u8 *) (((u8 *) temp_v0) + 0x11))) & 0xFFDF);
    if (((*((u8 *) (((u8 *) D_84195208[D_841951BD]) + 0xF))) & 0x40) && (((D_841951BF == 0x59) || (D_841951BF == 0x5A)) || (D_841951BF == 0xDE)))
    {
      return 0;
    }
    return 1;
  }
  return 0;
}
#endif

#ifdef VERSION_US
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 * D_84195208[];
s32 func_84128354(void) {
    s32 state;
    state = D_84195208[D_841951BD][0xF];
    if ((state & 0x60) == 0) {
        return 0;
    }
    if (state & 0x40) {
        if (D_841951BF == 0x10 || D_841951BF == 0x12 || D_841951BF == 0x57 || D_841951BF == 0xEF) {
            return 0;
        }
        return 1;
    }
    if (D_841951BF == 0x59 || D_841951BF == 0x5A || D_841951BF == 0xDE) {
        return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern void *D_841951F0;

s32 func_841283FC(void) {
    if ((D_841951BF == 0x57) && ((*(u8 *)((u8 *)(D_841951F0) + (0x9C4))) == 1)) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_84124410();
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951C4;
extern u8 * D_84195208[];
void func_84128438(void) {
    u8 *temp_v0;
    temp_v0 = D_84195208[D_841951BD];
    if (!(temp_v0[0xD] & 8)) {
        func_84124410(&D_841951C4, D_84195208[D_841951BC][0x23], temp_v0[0x24]);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84128354(void);
extern void func_84128438(void);
extern s32 D_84187020;
extern u8 func_80063660(u8);
extern u8 func_80063690(u8);
extern s32 func_84125080();
extern void func_84128298(void);
extern s32 func_841283FC(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951C3;
extern u8 D_841951C4;
extern u8 D_841951C6;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_841284A4(void) {
    unsigned short value;
    if ((D_841951C3 == 8 && !(D_84195200[D_841951BD][0x24] & 7)) || (D_84195208[D_841951BD][0xD] & 4) || ((D_84195208[D_841951BD][0x10] & 0x10) && (D_841951C3 == 3 || D_841951C3 == 8))) { func_84128298(); return; }
    if (func_841282C0() != 0) return;
    if (func_84128354() != 0) { func_84128298(); return; }
    if (func_841283FC() != 0 || (D_84195208[D_841951BC][0x10] & 1) || D_841951C3 == 0x11 || D_84187020 != 0) return;
    func_84128438();
    if (func_80063660(D_841951C6) == 0x4D) { value = func_80063690(D_841951C6); if (D_841951C4 >= value) D_841951C4 -= value; else D_841951C4 = 0; }
    if (D_841951C4 != 0xFF && func_84125080() >= D_841951C4) func_84128298();
}
#endif

#ifdef VERSION_US
void BattleCommand_008(void) {
    if (D_841951D2 != 0) {
        func_84136678(D_841951BC, -1);
        if ((D_841951D5 & 0x7F) == 0) {
            func_84135B00(102);
        } else if (D_841951C3 == 148) {
            func_84135B00(129);
            if (D_84195208[D_841951BD][13] & 0x4) func_84135B00(182);
            else func_84135B00(181);
        } else if (D_841951D1 != 255) {
            if (D_84195208[D_841951BD][13] & 0x4) func_84135B00(86);
            else func_84135B00(85);
        } else {
            func_84135B00(191);
        }
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
        D_841951D1 = 0;
        if (D_841951C3 == 45 && (D_841951D5 & 0x7F)) {
            D_841951C8 >>= 3;
            if (D_841951C8 == 0) D_841951C8 = 1;
            func_84136678(D_841951BC, -1);
            func_84135B00(38);
            if (*(u16 *)(D_84195200[D_841951BC] + 38) < D_841951C8) D_841951C8 = *(u16 *)(D_84195200[D_841951BC] + 38);
            func_84136A9C(D_841951BC, -1, (s16)-func_84126804(D_841951BC, (u16)D_841951C8), 2);
            func_84134CBC(D_841951BC, 20);
            BattleRecord_AdvanceWriteSlot();
        }
        if (D_841951BF == 251) {
            func_84134CBC(D_841951BC, 40);
            func_84134DD8(D_841951BF);
            BattleRecord_AdvanceWriteSlot();
            D_84195208[D_841951BC][15] &= 0xFFFB;
        }
        func_841254E0();
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern u8 D_841951BD;
extern s32 D_841951C8;
extern u8 *D_84195208[];
extern void func_84125424(u8);
void func_841288DC(void) {
    u8 *temp_v0;

    temp_v0 = D_84195208[D_841951BD];
    if (!((*(u8 *)((u8 *)temp_v0 + 0x10)) & 0x10)) {
        *(s32 *)((u8 *)temp_v0 + 0x4C) += D_841951C8;
        temp_v0 = D_84195208[D_841951BD];
        if ((u32)(*(s32 *)((u8 *)temp_v0 + 0x4C)) >= 0x10000U) {
            *(s32 *)((u8 *)temp_v0 + 0x4C) = 0xFFFF;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_8412D8C8(void);
extern u8 func_80063660(u8);
extern u8 func_80063690(u8);
extern s32 func_84125080();
extern void func_841288DC(void);
extern u8 D_841951BD;
extern u8 D_841951C6;
extern s32 D_841951C8;
extern u8 D_841951D4;
extern u8 D_841951E6;
extern u8 D_841951E7;
extern u16 D_841951E8;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_84128954(void) {
    u8 chance;

    D_841951E7 = 0;
    if (D_84195208[D_841951BD][0xD] & 0x20) {
        func_8412D8C8();
        if (D_841951D4 == 1) {
            D_841951E7 = 1;
        }
    } else if (func_80063660(D_841951C6) == 0x4F) {
        chance = func_80063690(D_841951C6);
        if (func_84125080() < chance) {
            func_8412D8C8();
            if (D_841951D4 == 1) {
                D_841951E7 = 2;
            }
        }
    }
    func_841288DC();
    if (D_841951C8 != 0) {
        D_841951E6 = 0;
        if (D_84195208[D_841951BD][0x10] & 0x10) {
            D_841951E6 = 1;
            if (D_841951C8 >= *(u16 *)(D_84195208[D_841951BD] + 0x46)) {
                D_84195208[D_841951BD][0x10] &= ~0x10;
                *(u16 *)(D_84195208[D_841951BD] + 0x46) = 0;
                D_841951E6 = 2;
            } else {
                *(u16 *)(D_84195208[D_841951BD] + 0x46) -= D_841951C8;
            }
            D_841951C8 = 0;
        } else {
            if (*(u16 *)(D_84195200[D_841951BD] + 0x26) < D_841951C8) {
                D_841951C8 = *(u16 *)(D_84195200[D_841951BD] + 0x26);
            }
            *(u16 *)(D_84195200[D_841951BD] + 0x26) -= D_841951C8;
        }
        D_841951E8 = D_841951C8;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84128B04.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84128B30.s")
#endif

#ifdef VERSION_US
extern s16 D_841951EC;
extern s32 func_8004C54C(u8, s32);
extern void func_84124768(u8 arg0);
extern void func_841254E0(void);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_84128B4C(void) {
    s16 *status = &D_841951EC;
    *status = 0;
    if (*(u16 *)(D_84195200[D_841951BD] + 0x26) <= 0) {
        if (D_84195208[D_841951BD][0x11] & 0x40) {
            if (*(u16 *)(D_84195200[D_841951BC] + 0x26) > 0) {
                func_8004C54C(0x1A, D_84195200[D_841951BC] + 0x34);
                func_8004C54C(0x1C, D_84195200[D_841951BD] + 0x34);
                func_84136A9C(D_841951BC, -1, -(s32)*(u16 *)(D_84195200[D_841951BC] + 0x26), 2);
                func_84136678(D_841951BD, -1);
                func_84135B00(0x83);
                func_84124768(D_841951BC);
                func_84136CA8();
            }
            *(u16 *)(D_84195200[D_841951BC] + 0x26) = 0;
        }
        if (D_841951BF == 0xFB) {
            func_84134CBC(D_841951BC, 0x28);
            func_84134DD8(D_841951BF);
            func_84136CA8();
        }
        func_841254E0();
    }
}
#endif

#ifdef VERSION_US
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BD;
extern u8 D_841951D2;
extern u8 * D_84195208[];
void func_84128CB8(void) {
    if (D_841951D2 == 0) {
        u8 *ptr = D_84195208[D_841951BD];
        if (ptr[0x10] & 0x40) {
            if (ptr[0x1D] < 0xFF) {
                ptr[0x1D]++;
                func_84136678(D_841951BD, -1);
                func_84135B00(0x43);
                func_84134CBC(D_841951BD, 0x41);
                func_84136CA8();
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84125778(u8);
extern void func_84136BEC(u8, u16, u16);
extern void func_84135B40(u16 arg0);
extern s32 func_84136124(u8 arg0, s16 arg1, u16 arg2, u8 arg3, u8 arg4);
extern void func_841366C4(u8 arg0, s16 arg1);
void BattleCommand_014(void) {
    if ((D_84195208[D_841951BD][16] & 0x10) != 0) {
        return;
    }
    if (D_84195200[D_841951BD][36] != 0) {
        return;
    }
    if ((D_841951D5 & 0x7F) == 0) {
        return;
    }
    if (func_84126390(D_841951BD, 3) != 0) {
        return;
    }
    if (func_80063660(D_841951C6) == 20) {
        return;
    }
    if (D_841951D3 != 0) {
        return;
    }
    if ((((u8 *)D_841951F8[D_841951BD])[11] & 0x4) != 0) {
        return;
    }
    D_84195200[D_841951BD][36] |= 0x8;
    func_84136BEC(D_841951BD, 0xFFFF, 0x8);
    func_84136218(D_841951BC, 6);
    func_84136218(D_841951BD, 5);
    func_841366C4(D_841951BD, -1);
    func_84135B40(148);
    if (func_84136124(D_841951BC, -2, 60, 6, 2) == 0) {
        func_84136124(D_841951BD, -2, 60, 5, 2);
    }
    func_84125778(D_841951BD);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84128EC0.s")
#endif

#ifdef VERSION_US
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern s32 D_841951C8;
extern u8 * D_84195200[];
void func_84129180(void) {
    u16 amount;

    amount = D_841951C8 >> 1;
    if (amount == 0) {
        amount++;
    }
    if (*(u16 *)(D_84195200[D_841951BC] + 0x26) + amount > *(u16 *)(D_84195200[D_841951BC] + 0x28)) {
        amount = *(u16 *)(D_84195200[D_841951BC] + 0x28) - *(u16 *)(D_84195200[D_841951BC] + 0x26);
    }
    *(u16 *)(D_84195200[D_841951BC] + 0x26) += amount;
    func_84136A9C(D_841951BC, -1, amount, 1);
    func_84136678(D_841951BC, -1);
    func_84135B00(0xAF);
    switch (D_841951BF) {
        case 0x8D:
            func_84134CBC(D_841951BC, 0x51);
            break;
        case 0x47:
            func_84134CBC(D_841951BC, 0x54);
            break;
        case 0x48:
            func_84134CBC(D_841951BC, 0x52);
            break;
        case 0xCA:
            func_84134CBC(D_841951BC, 0x53);
            break;
        default:
            func_84134CBC(D_841951BC, 0x4A);
            break;
    }
    func_84136CA8();
}
#endif

#ifdef VERSION_US
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern s32 D_841951C8;
extern u8 * D_84195200[];
void func_841292C4(void) {
    u16 delta = (u16)(D_841951C8 >> 1);
    u16 old_value = *(u16 *)(D_84195200[D_841951BC] + 0x26);
    u16 limit = *(u16 *)(D_84195200[D_841951BC] + 0x28);
    if (limit < old_value + delta) { delta = limit - old_value; }
    *(u16 *)(D_84195200[D_841951BC] + 0x26) = old_value + delta;
    func_84136A9C(D_841951BC, -1, (s16)delta, 1);
    func_84136678(D_841951BC, -1);
    func_84135B00(0xBE);
    func_84134CBC(D_841951BC, 0x4A);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
extern s8 D_841951C1;
extern void func_84134D28(u8 arg0, u8 arg1);
void BattleCommand_018(void) {
    if ((D_84195208[D_841951BD][16] & 0x10) == 0) {
        if (D_84195200[D_841951BD][36] != 0) {
            if ((D_84195200[D_841951BD][36] & 0x20) != 0) {
                func_84136BEC(D_841951BD, 0xFFFF, 0);
                func_841366C4(D_841951BD, -1);
                func_84135B40(119);
                func_84134D28(D_841951BD, 15);
                D_84195200[D_841951BD][36] = 0;
            }
        } else {
            if ((D_841951D5 & 0x7F) != 0 &&
                ((u8)D_841951C1 == 0 || func_84126390(D_841951BD, (u8)D_841951C1) == 0) &&
                func_80063660(D_841951C6) != 21 &&
                D_841951D3 == 0 &&
                (((u8 *)D_841951F8[D_841951BD])[11] & 0x4) == 0) {
                *(u16 *)(D_84195208[D_841951BD] + 60) >>= 1;
                D_84195200[D_841951BD][36] |= 0x10;
                func_84136BEC(D_841951BD, 0xFFFF, 0x10);
                func_841366C4(D_841951BD, -1);
                func_84135B40(188);
                func_84136218(D_841951BC, 6);
                func_84136218(D_841951BD, 5);
                if (func_84136124(D_841951BC, -2, 60, 6, 4) == 0) {
                    func_84136124(D_841951BD, -2, 60, 5, 4);
                }
                func_84125778(D_841951BD);
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84134FEC(u8, u8);
extern void func_84134D80(u8, u8, u8);
void BattleCommand_019(void) {
    u16 saved;

    if ((D_84195208[D_841951BD][0x10] & 0x10) != 0) {
        return;
    }
    if (D_84195200[D_841951BD][0x24] != 0) {
        return;
    }
    if ((D_841951D5 & 0x7F) == 0) {
        return;
    }
    if (((u8 *)D_841951F0)[0x9C4] == 2) {
        return;
    }
    if ((u8)D_841951C1 != 0 && func_84126390(D_841951BD, (u8)D_841951C1) != 0) {
        return;
    }
    if (func_80063660(D_841951C6) == 22) {
        return;
    }
    if (D_841951D3 != 0) {
        return;
    }
    if (func_84126F2C(D_841951BD, 0x20) != 0) {
        return;
    }
    if (((u8 *)D_841951F8[D_841951BD])[0xB] & 4) {
        return;
    }
    D_84195200[D_841951BD][0x24] |= 0x20;
    func_84136218(D_841951BC, 6);
    func_84136218(D_841951BD, 5);
    if (D_841951E6 == 2) {
        func_84136B9C(D_841951BD, -1, 0x20);
        func_84136678(D_841951BD, -1);
        func_84135B00(65);
        func_84134DD8(D_841951BF);
        func_84134CBC(D_841951BD, 59);
        func_84134FEC(D_841951BD, 6);
        if (func_841360C0(D_841951BC, -2, 60, 6, 5) == 0) {
            func_841360C0(D_841951BD, -2, 60, 5, 5);
        }
        BattleRecord_AdvanceWriteSlot();
    } else {
        func_84136BEC(D_841951BD, 65535, 0x20);
        func_841366C4(D_841951BD, -1);
        func_84135B40(65);
        func_84134D28(D_841951BD, 14);
        if (func_84136124(D_841951BC, -2, 60, 6, 5) == 0) {
            func_84136124(D_841951BD, -2, 60, 5, 5);
        }
    }
    if (func_84125778(D_841951BD) == 0) {
        D_84195208[D_841951BD][0xD] &= ~0x20;
        D_84195208[D_841951BD][0xF] &= ~0x13;
        D_84195208[D_841951BD][0x18] = 0;
        if (D_84195208[D_841951BD][3] == 19 || D_84195208[D_841951BD][3] == 91) {
            D_84195208[D_841951BD][0xF] &= ~0x60;
        }
        D_84195208[D_841951BD][0x10] &= ~0x20;
        D_84195208[D_841951BD][0x28] = 1;
    }
    if (D_841951E6 == 2 && (D_84195208[D_841951BD][3] == 19 || D_84195208[D_841951BD][3] == 91)) {
        saved = D_84195200[D_841951BD][0x24];
        D_84195200[D_841951BD][0x24] = 0;
        func_84134D80(3, D_841951BD, 39);
        D_84195200[D_841951BD][0x24] = saved;
    }
}
#endif

#ifdef VERSION_US
void BattleCommand_020(void) {
    if ((D_84195208[D_841951BD][16] & 0x10) == 0 &&
        D_84195200[D_841951BD][36] == 0 &&
        (D_841951D5 & 0x7F) != 0 &&
        func_80063660(D_841951C6) != 24 &&
        D_841951D3 == 0 &&
        (((u8 *)D_841951F8[D_841951BD])[11] & 0x4) == 0) {
        D_84195200[D_841951BD][36] |= 0x40;
        func_84136BEC(D_841951BD, 0xFFFF, 0x40);
        func_841366C4(D_841951BD, -1);
        func_84135B40(108);
        func_84136218(D_841951BC, 6);
        func_84136218(D_841951BD, 5);
        if (func_84136124(D_841951BC, -2, 60, 6, 6) == 0) {
            func_84136124(D_841951BD, -2, 60, 5, 6);
        }
        *(u16 *)(D_84195208[D_841951BD] + 64) >>= 2;
        func_84125778(D_841951BD);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern u8 *D_84195200[];
extern u8 *D_84195208[];
extern void func_84136A9C(u8, s16, s16, u8);
extern void func_84136B9C(u8, s16, u16);
void func_84129A80(void) {
    func_84136A9C(D_841951BC, -1, (s16)(-*(u16 *)((u8 *)(D_84195200[D_841951BC]) + 0x26)), 3);
    func_84136B9C(D_841951BC, -1, 0);
    *(u8 *)((u8 *)(D_84195200[D_841951BC]) + 0x24) = 0;
    *(u16 *)((u8 *)(D_84195200[D_841951BC]) + 0x26) = 0;
    D_84195208[D_841951BC][0x10] &= 0xFF7F;
    D_84195208[D_841951BC][0x11] &= 0xFFBF;
}
#endif

#ifdef VERSION_US
extern void func_841252D0(u8);
extern void func_84124594(u8 arg0);
extern void func_841253F4(void);
extern void func_841254E0(void);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_84129B60(void) {
    u8 a2;

    D_84195208[D_841951BC][0x26] = 0;
    D_84195208[D_841951BC][0x27] = 0;

    a2 = D_84195208[D_841951BD][0x26];

    if (a2 == 0 || a2 == D_84195208[D_841951BC][5] || a2 == D_84195208[D_841951BC][6] || a2 == D_84195208[D_841951BC][7] || a2 == D_84195208[D_841951BC][8]) {
        func_84136678(D_841951BC, -1);
        func_84135B00(0x8C);
        func_84124594(D_841951BC);
        func_84136CA8();
        func_841254E0();
    } else {
        ((u8 *)D_841951F8[D_841951BC])[0] = 0xFF;
        ((u8 *)D_841951F8[D_841951BC])[1] = a2;
        func_841252D0(a2);
        func_841253F4();
    }
}
void func_84129B60_padding1(void) {}
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern u8 * D_84195208[];
s32 func_84129C8C(u8 arg0) {
    u8 value;
    value = D_84195208[D_841951BC][arg0 + 5];
    if (value == 0) {
        return 0;
    }
    value = func_80062D98(value);
    if (value == 0x13) {
        return 0;
    }
    if (value == D_84195208[D_841951BC][1]) {
        return 0;
    }
    if (value == D_84195208[D_841951BC][2]) {
        return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
s32 func_84129D3C(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_84129C8C((u8) i) != 0) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_80063270(u8);
extern s32 func_8004C54C(u8, s32);
extern s32 func_84125080();
extern s32 func_84129C8C(u8);
extern void func_84135B40(u16);
extern void func_841366C4(u8, s16);
extern u8 D_841951BC;
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_000(void) {
    u8 var;

    if (func_84129D3C() != 0) {
        do {
            var = func_84125080() & 3;
        } while (func_84129C8C(var) == 0);

        var = func_80062D98(D_84195208[D_841951BC][var + 5]);
        D_84195208[D_841951BC][1] = var;
        D_84195208[D_841951BC][2] = var;
        func_841366C4(D_841951BC, -1);
        func_8004C54C(0x2F, func_80063270(var));
        func_84135B40(0x3C);
    } else {
        func_841366C4(D_841951BC, -1);
        func_84135B40(0xB5);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC, D_841951BD;
extern u8 *D_84195208[];
// Resets all seven stat stages (bytes 0x1E-0x24, 7 = neutral; func_84125B88 bounds them to
// 1-13) of both active Pokemon, then has func_84125734 recompute the five stats at 0x3C
// from those stages.
void func_84129E84(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        D_84195208[D_841951BC][i + 0x1E] = 7;
        D_84195208[D_841951BD][i + 0x1E] = 7;
    }
    func_84125734(D_841951BC);
    func_84125734(D_841951BD);
    func_841366C4(D_841951BC, -1);
    func_84135B40(104);
}
#endif

#ifdef VERSION_US
extern void func_84124594(u8 arg0);
extern void func_84125424(u8 arg0);
extern void func_841254E0(void);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern s8 D_841951C2;
extern s32 D_841951C8;
extern u8 D_841951D2;
extern u8 * D_84195208[];
void func_8412A028(void) {
    if (D_84195208[D_841951BC][0xF] & 1) {
        D_84195208[D_841951BC][0x12]--;
        if (D_84195208[D_841951BC][0x12] > 0) {
            func_84136678(D_841951BC, -1);
            func_84135B00(0x35);
            func_84124594(D_841951BC);
            func_84136CA8();
            func_841254E0();
        } else {
            D_84195208[D_841951BC][0xF] &= ~1;
            func_84136678(D_841951BC, -1);
            func_84135B00(0x36);
            *(u8 *)&D_841951C2 = 1;
            D_841951C8 = *(s32 *)(D_84195208[D_841951BC] + 0x4C) * 2;
            *(s32 *)(D_84195208[D_841951BC] + 0x4C) = 0;
            D_84195208[D_841951BC][0x29] = 0;
            D_841951BF = 0x75;
            if (D_841951C8 >= 0x10000) {
                D_841951C8 = 0xFFFF;
            }
            if (D_841951C8 == 0) {
                D_841951D2 = 1;
            }
            func_84125424(0x1B);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84125080();
extern void func_841254E0(void);
void BattleAnim_Table_84185F10_003(void) {
    u8 *temp_v0;

    *(u8 *)((u8 *)D_84195208[D_841951BC] + 0xF) |= 1;
    *(s32 *)((u8 *)D_84195208[D_841951BC] + 0x4C) = 0;
    *(u8 *)((u8 *)D_84195208[D_841951BC] + 0x12) = (func_84125080() & 1) + 2;
    func_841254E0();
}
#endif

#ifdef VERSION_US
s32 func_841262C4(u8);

s32 func_8412A200(u8 arg0) {
    s32 var_a0;

    var_a0 = func_84126374() == 0;
    if (var_a0 != 0) {
        var_a0 = func_841262C4(arg0) != 0;
    }
    return var_a0;
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
s32 func_8412A23C(u8 arg0,u8 arg1){s32 result=arg1;u8 *ptr=D_841951F8[arg0];u8 *record=ptr;record+=(u32)arg1*0x58;if(result==ptr[0xA])return 1;if(result>=ptr[8])return 1;if(*(u16 *)(record+0x3E)==0)return 1;if(ptr[0x12]!=0){if(ptr[0xA]<ptr[3]){if(result<ptr[3])return 1;}else if(result>=ptr[3])return 1;}return 0;}
#endif

#ifdef VERSION_US
extern s32 func_8412A23C(u8, u8);
extern s32 func_8004C54C(u8, s32);
extern void func_84124604(u8 arg0, u8 arg1);
extern s32 func_84125080();
extern void func_84126BA8(u8 arg0);
extern s32 func_8412A200(u8 arg0);
extern void func_84131EAC(u8 arg0);
extern void func_84133984(u8 arg0, u8 arg1);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 D_841951D2;
extern u8 * D_84195200[];
void BattleAnim_Table_84185F10_004(void) {
    if (func_8412A200(D_841951BD) != 0) {
        if (D_841951D2 != 0) func_84126B1C(D_841951BC, D_841951BD, 1);
        else {
            u8 value; do { value = func_84125080() & 7; } while (func_8412A23C(D_841951BD, value) != 0);
            func_84124604(D_841951BD, D_841951BF); func_84136CA8(); func_84133984(D_841951BD, value); func_84136678(D_841951BD, -1);
            func_8004C54C(0x1C, D_84195200[D_841951BD] + 0x34); func_84135B00(0x45);
            if (D_84195200[D_841951BD][0x24] & 7) func_84134CBC(D_841951BD, 0x2F); else if (D_84195200[D_841951BD][0x24] & 0x20) func_84134CBC(D_841951BD, 0x2E); else func_84134CBC(D_841951BD, 0x2D);
            func_84136CA8(); func_84131EAC(D_841951BD);
        }
    } else func_84126BA8(D_841951BC);
}
#endif

#ifdef VERSION_US
extern void BattleAnim_Table_84186004_070(void);
extern s32 func_84125080();
extern void func_84125484(u8 arg0);
extern void func_841254E0(void);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84135068(u8 arg0, u8 arg1);
extern void func_841350AC(u8 arg0, u8 arg1, u8 arg2);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern u8 D_841951C3;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_8412A454(void) {
    u8 choice;
    u8 timer;
    if (D_84195208[D_841951BC][0xF] & 4) {
        D_84195208[D_841951BC][0x12]--;
        if (D_84195208[D_841951BC][0x12] != 0) goto update;
        D_84195208[D_841951BC][0xF] &= ~4;
        *(s32 *)(D_84195208[D_841951BC] + 0x4C) = 0;
        if (D_841951BF == 0xFB) {
            func_84135068(0, 0);
            func_84134CBC(D_841951BC, 0x28);
            func_84134DD8(D_841951BF);
            func_84136CA8();
        }
        return;
    }
    D_84195208[D_841951BC][0xF] |= 4;
    switch (D_841951C3) {
    case 0x2C:
    case 0x4D:
        D_84195208[D_841951BC][0x12] = 1;
        *(s32 *)(D_84195208[D_841951BC] + 0x4C) = 2;
        break;
    case 0x68:
        do { choice = func_84125080() & 3; } while (choice == 0);
        choice = (u8)(choice - 1);
        if (choice > 0) {
            D_84195208[D_841951BC][0x12] = choice;
            choice = (u8)(choice + 1);
            *(s32 *)(D_84195208[D_841951BC] + 0x4C) = choice;
        } else {
            D_84195208[D_841951BC][0xF] &= ~4;
            *(s32 *)(D_84195208[D_841951BC] + 0x4C) = 1;
            func_841350AC(1, 0, 0);
            return;
        }
        break;
    case 0x9A:
        if (((u8 *)D_841951F8[D_841951BC])[8] < 2) {
            D_84195208[D_841951BC][0xF] &= ~4;
            func_84135068(0, 0);
            BattleAnim_Table_84186004_070();
            func_841254E0();
            return;
        }
        D_84195208[D_841951BC][0x12] = ((u8 *)D_841951F8[D_841951BC])[8] - 1;
        *(s32 *)(D_84195208[D_841951BC] + 0x4C) = ((u8 *)D_841951F8[D_841951BC])[9];
        break;
    default:
        choice = func_84125080() & 3;
        if (choice >= 2) choice = func_84125080() & 3;
        choice += 1;
        D_84195208[D_841951BC][0x12] = choice;
        choice = (u8)(choice + 1);
        *(s32 *)(D_84195208[D_841951BC] + 0x4C) = choice;
    }
update:
    func_84125484(3);
}
#endif

#ifdef VERSION_US
extern u8 D_841951D3;
extern s32 func_84126374(void);
void BattleAnim_Table_84185F10_006(void) {
    if (!(((u8 *)D_84195208[D_841951BD])[0x10] & 0x10) &&
        !(((u8 *)D_84195200[D_841951BD])[0x24] & 0x27) &&
        (func_84126374() != 0) &&
        (D_841951D3 == 0)) {
        ((u8 *)D_84195208[D_841951BD])[0xF] |= 8;
        ((u8 *)D_84195208[D_841951BD])[0x10] &= 0xFFDF;
    }
}
#endif

#ifdef VERSION_US
extern u8 func_80062DD4(u8);
void BattleCommand_031(void) {
    D_841951C8 = 0;
    if (!(D_841951D5 & 0x7F) || D_84195200[D_841951BC][29] < D_84195200[D_841951BD][29]) {
        D_841951D1 = 255;
        D_841951E4 = 255;
        D_841951D2 = 1;
    } else {
        u16 result = func_80062DD4(D_841951BF);
        result += (D_84195200[D_841951BC][29] - D_84195200[D_841951BD][29]) * 2;
        if (result >= 256) {
            result = 255;
        }
        D_841951C4 = result;
        func_841284A4();
        if (D_841951D2 == 0) {
            D_841951C8 = 65535;
            D_841951D1 = 2;
            D_841951E4 = 2;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84126320(u8 arg0);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern s32 D_841951C8;
extern u8 * D_84195200[];
void BattleAnim_Table_84185F10_008(void) {
    s32 amount;
    s32 value;
    if (func_84126320(D_841951BD) > 0) {
        amount = D_841951C8 >> 2;
        if (amount == 0) amount++;
        value = *(u16 *)(D_84195200[D_841951BC] + 0x26);
        if (value < amount) amount = value;
        *(u16 *)(D_84195200[D_841951BC] + 0x26) = value - amount;
        func_84136A9C(D_841951BC, -1, (s16)(-amount), 2);
        func_84136678(D_841951BC, -1);
        func_84135B00(0x38);
        func_84134CBC(D_841951BC, 0x14);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern void func_84135B40(u16);
extern void func_841366C4(u8, s16);
extern u8 D_841951BC;
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_009(void) {
    u8 *ptr = D_84195208[D_841951BC];
    if (ptr[0x10] & 2) {
        func_841366C4(D_841951BC, -1);
        func_84135B40(0xB5);
    } else {
        ptr[0x10] |= 2;
        func_841366C4(D_841951BC, -1);
        func_84135B40(0x2F);
    }
}
#endif

#ifdef VERSION_US
extern void func_84124594(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
void BattleAnim_Table_84185F10_010(void) {
    u8 *ptr = D_84195208[D_841951BC];
    if (ptr[0x10] & 4) {
        func_84126BFC(D_841951BC);
        return;
    }
    ptr[0x10] |= 4;
    func_84136678(D_841951BC, -1);
    func_84135B00(0x58);
    func_84124594(D_841951BC);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
void BattleCommand_035(void) {
    u8 type;
    if (func_80063660(D_841951C6) == 25) {
        func_84136678(D_841951BD, -1);
        func_84135B00(71);
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    } else {
        if ((D_84195208[D_841951BD][15] & 0x80) != 0) {
            func_84136678(D_841951BC, -1);
            func_84135B00(96);
            func_841246AC(D_841951BD, D_841951BF);
            BattleRecord_AdvanceWriteSlot();
        } else if ((D_84195208[D_841951BD][16] & 0x10) != 0) {
            if (D_841951C3 != 76 && D_841951C3 != 92 && D_841951C3 != 118) {
                func_84126A90(D_841951BC, D_841951BD, 1);
            }
        } else if (D_841951D2 != 0) {
            if (D_841951C3 != 76 && D_841951C3 != 92 && D_841951C3 != 118) {
                func_84126B1C(D_841951BC, D_841951BD, 1);
            }
        } else {
            D_84195208[D_841951BD][19] = (func_84125080() & 0x3) + 2;
            D_84195208[D_841951BD][15] |= 0x80;
            func_84136218(D_841951BC, 6);
            func_84136218(D_841951BD, 5);
            func_84136678(D_841951BD, -1);
            func_84135B00(94);
            if (func_841360C0(D_841951BC, -2, 60, 6, 9) == 0) {
                func_841360C0(D_841951BD, -2, 60, 5, 9);
            }
            func_84124604(D_841951BD, D_841951BF);
            if (D_841951BF == 186) {
                func_84134E30(5);
            } else {
                func_84134E30(0);
            }
            BattleRecord_AdvanceWriteSlot();
            type = func_80063660(D_841951C6);
            if (type == 15 || type == 16) {
                D_84195200[D_841951BD][1] = 0;
                D_841951C6 = 0;
                D_84195208[D_841951BD][15] &= ~0x80;
                func_84136678(D_841951BD, -1);
                func_84135B00(95);
                func_84134CBC(D_841951BD, 86);
                func_84134DD8(D_841951BF);
                BattleRecord_AdvanceWriteSlot();
            }
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_8412ADF8.s")
#endif

#ifdef VERSION_US
extern void *func_84156590(u8, u8);
extern s32 func_84156674(u8, u8, s32);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern void *D_841951F8[];
extern u8 *D_84195200[];
extern u8 *D_84195208[];

void func_8412AFE0(void) {
    if (*(u16 *)(D_84195200[D_841951BC] + 0x26) >= *(u16 *)(D_84195200[D_841951BC] + 0x28)) {
        func_84136678(D_841951BC, -1);
        func_84135B00(0x76);
        func_84124594(D_841951BC);
        func_84136CA8();
        return;
    }
    func_84136678(D_841951BC, -1);
    if (D_841951BF == 0x9C) {
        D_84195208[D_841951BC][0x11] &= 0xFFFE;
        func_84156674(D_841951BC, ((u8 *)D_841951F8[D_841951BC])[0xA], 0x20);
        ((u8 *)func_84156590(D_841951BC, ((u8 *)D_841951F8[D_841951BC])[0xA]))[0xD] = 0;
        if (D_84195200[D_841951BC][0x24] != 0) {
            func_84135B00(0x4F);
        } else {
            func_84135B00(0x4E);
        }
        D_84195200[D_841951BC][0x24] = 3;
        func_84125734(D_841951BC);
        func_84136A9C(D_841951BC, -1, (s16)func_84126850(D_841951BC, *(u16 *)(D_84195200[D_841951BC] + 0x28)), 1);
        func_84136B9C(D_841951BC, -1, 7);
    } else {
        func_84136A9C(D_841951BC, -1, (s16)func_84126850(D_841951BC, (u16)func_841267B4(D_841951BC, 1)), 1);
    }
    func_84135B00(0x50);
    func_84134CBC(D_841951BC, 0);
    func_84134DD8(D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
void _bcopy(void *, void *, s32);
void func_841352DC(u8 arg0);
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

M2C_UNK func_8003F6E0(u8 *, u8 *, u8);              /* extern */

void func_8412B1D4(void) {
    s32 var_a1;
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;
    u8 temp_a0;

    M2C_FIELD(D_84195208[D_841951BC], s8 *, 0x26) = 0;
    M2C_FIELD(D_84195208[D_841951BC], s8 *, 0x27) = 0;
    temp_v0 = D_84195208[D_841951BD];
    if ((M2C_FIELD(temp_v0, u8 *, 0x11) & 8) || (M2C_FIELD(temp_v0, u8 *, 0xF) & 0x60)) {
        func_84134E7C(0U, 1U);
        func_841366C4(D_841951BC, -1);
        func_84135B40(0xB5U);
        return;
    }
    temp_v0_2 = D_84195208[D_841951BC];
    M2C_FIELD(temp_v0_2, u8 *, 0x11) = (u8) (M2C_FIELD(temp_v0_2, u8 *, 0x11) | 8);
    M2C_FIELD(D_84195208[D_841951BC], s8 *, 0x15) = 0;
    M2C_FIELD(D_84195208[D_841951BC], s8 *, 0x25) = 0;
    *D_84195208[D_841951BC] = *D_84195208[D_841951BD];
    M2C_FIELD(D_84195208[D_841951BC], u16 *, 0x2C) = (u16) M2C_FIELD(D_84195208[D_841951BD], u16 *, 0x2C);
    M2C_FIELD(D_84195208[D_841951BC], u16 *, 0x2E) = (u16) M2C_FIELD(D_84195208[D_841951BD], u16 *, 0x2E);
    M2C_FIELD(D_84195208[D_841951BC], u8 *, 0x2A) = (u8) M2C_FIELD(D_84195208[D_841951BD], u8 *, 0x2A);
    _bcopy(D_84195208[D_841951BD] + 5, D_84195208[D_841951BC] + 5, 4);
    _bcopy(D_84195208[D_841951BD] + 1, D_84195208[D_841951BC] + 1, 2);
    _bcopy(D_84195208[D_841951BD] + 0x32, D_84195208[D_841951BC] + 0x32, 0xA);
    _bcopy(D_84195208[D_841951BD] + 0x3C, D_84195208[D_841951BC] + 0x3C, 0xA);
    _bcopy(D_84195208[D_841951BD] + 0x1E, D_84195208[D_841951BC] + 0x1E, 7);
    func_8003F6E0(D_84195208[D_841951BC] + 0x50, D_84195200[D_841951BC], *D_84195208[D_841951BD]);
    var_a1 = 0;
    do {
        temp_v0_3 = &D_84195208[D_841951BC][var_a1];
        temp_a0 = M2C_FIELD(temp_v0_3, u8 *, 5);
        var_a1 = (var_a1 + 1) & 0xFF;
        if (temp_a0 == 0) {
            M2C_FIELD(temp_v0_3, s8 *, 9) = 0;
        } else if (temp_a0 == 0xA6) {
            M2C_FIELD(temp_v0_3, s8 *, 9) = 1;
        } else {
            M2C_FIELD(temp_v0_3, s8 *, 9) = 5;
        }
    } while (var_a1 < 4);
    func_841366C4(D_841951BC, -1);
    func_84135B40(0x3DU);
    func_841352DC(D_841951BC);
}
#endif

#ifdef VERSION_US
extern void func_84124594(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951C3;
extern void * D_841951F8[];
void BattleAnim_Table_84185F10_015(void) {
    u8 *ptr;
    u8 flags;
    if (D_841951C3 == 0x23) {
        ptr = (u8 *)D_841951F8[D_841951BC];
        flags = ptr[0xB];
        if (flags & 8) {
            func_84126BFC(D_841951BC);
            return;
        }
        ptr[0xB] = flags | 8;
        ((u8 *)D_841951F8[D_841951BC])[0xD] = 5;
        func_84136678(D_841951BC, -1);
        func_84135B00(0x4B);
        func_84124594(D_841951BC);
        func_84136CA8();
    } else if (D_841951C3 == 0x41) {
        ptr = (u8 *)D_841951F8[D_841951BC];
        flags = ptr[0xB];
        if (flags & 0x10) {
            func_84126BFC(D_841951BC);
            return;
        }
        ptr[0xB] = flags | 0x10;
        ((u8 *)D_841951F8[D_841951BC])[0xE] = 5;
        func_84136678(D_841951BC, -1);
        func_84135B00(0x4C);
        func_84124594(D_841951BC);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
void BattleCommand_040(void) {
    if ((D_841951D5 & 0x7F) == 0 || func_84126390(D_841951BD, 3) != 0) {
        func_84136678(D_841951BD, -1);
        func_84135B00(102);
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    } else if ((D_84195200[D_841951BD][36] & 0x8) != 0) {
        func_84136678(D_841951BD, -1);
        func_84135B00(150);
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    } else if (func_80063660(D_841951C6) == 20) {
        func_84136678(D_841951BD, -1);
        func_84135B00(71);
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    } else {
        if (D_84195200[D_841951BD][36] != 0 || (D_84195208[D_841951BD][16] & 0x10) != 0) {
            func_84126A90(D_841951BC, D_841951BD, 0);
        } else if (D_841951D2 != 0) {
            func_84126B1C(D_841951BC, D_841951BD, 1);
        } else {
            D_84195200[D_841951BD][36] = D_84195200[D_841951BD][36] | 0x8;
            func_84136B9C(D_841951BD, -1, 0x8);
            func_84136218(D_841951BC, 6);
            func_84136218(D_841951BD, 5);
            if (D_841951C3 == 33) {
                D_84195208[D_841951BD][17] |= 0x1;
                D_84195208[D_841951BD][20] = 0;
                func_84136678(D_841951BC, -1);
                func_84135B00(149);
                if (func_841360C0(D_841951BC, -2, 60, 6, 3) == 0) {
                    func_841360C0(D_841951BD, -2, 60, 5, 3);
                }
            } else {
                func_84136678(D_841951BC, -1);
                func_84135B00(148);
                if (func_841360C0(D_841951BC, -2, 60, 6, 2) == 0) {
                    func_841360C0(D_841951BD, -2, 60, 5, 2);
                }
            }
            func_84124604(D_841951BD, D_841951BF);
            BattleRecord_AdvanceWriteSlot();
            func_84125778(D_841951BD);
        }
    }
}
#endif

#ifdef VERSION_US
void BattleCommand_041(void) {
    if ((D_841951D5 & 0x7F) == 0) {
        func_84136678(D_841951BD, -1);
        func_84135B00(102);
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    } else if ((D_84195200[D_841951BD][36] & 0x40) != 0) {
        func_84136678(D_841951BD, -1);
        func_84135B00(110);
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    } else if (func_80063660(D_841951C6) == 24) {
        func_84136678(D_841951BD, -1);
        func_84135B00(71);
        func_841246AC(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    } else {
        if (D_84195200[D_841951BD][36] != 0 || (D_84195208[D_841951BD][16] & 0x10) != 0) {
            func_84126A90(D_841951BC, D_841951BD, 0);
        } else if (D_841951D2 != 0) {
            func_84126B1C(D_841951BC, D_841951BD, 1);
        } else {
            D_84195200[D_841951BD][36] = D_84195200[D_841951BD][36] | 0x40;
            func_84125734(D_841951BD);
            func_84136B9C(D_841951BD, -1, 0x40);
            func_84136218(D_841951BC, 6);
            func_84136218(D_841951BD, 5);
            if (func_841360C0(D_841951BC, -2, 60, 6, 6) == 0) {
                func_841360C0(D_841951BD, -2, 60, 5, 6);
            }
            func_84136678(D_841951BD, -1);
            func_84135B00(108);
            func_84124604(D_841951BD, D_841951BF);
            BattleRecord_AdvanceWriteSlot();
            func_84125778(D_841951BD);
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84124594(u8 arg0);
extern s32 func_8412676C(u8 arg0, u8 arg1);
extern u32 func_84126804(u8, u16);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_8412BB9C(void) {
    u8 *resource; u8 flags; u16 value;
    flags = D_84195208[D_841951BC][0x10];
    if (0x10 & flags) { func_84136678(D_841951BC,-1); func_84135B00(0x7E); func_84124594(D_841951BC); func_84136CA8(); return; }
    resource = D_84195200[D_841951BC];
    if (((*(u16 *)(resource+0x28))>>2) >= *(u16 *)(resource+0x26)) { func_84136678(D_841951BC,-1); func_84135B00(0x7F); func_84124594(D_841951BC); func_84136CA8(); return; }
    D_84195208[D_841951BC][0x10] = flags | 0x10;
    value = (u8)func_8412676C(D_841951BC,2);
    *(u16 *)(D_84195208[D_841951BC]+0x46) = value;
    D_84195208[D_841951BC][0x1B] = 0; D_84195208[D_841951BC][0x1C] = 0;
    func_84136A9C(D_841951BC,-1,(s16)(-func_84126804(D_841951BC,value)),1);
    func_84136678(D_841951BC,-1); func_84135B00(0x7C); func_84134CBC(D_841951BC,0); func_84134DD8(D_841951BF); func_84136CA8();
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC; extern u8 *D_84195208[]; void BattleAnim_Table_84185F10_019(void) { D_84195208[D_841951BC][0x10] |= 0x20; }
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951D2;
extern u8 * D_84195208[];
s32 func_8412BD3C(void) {
    u8 value; u8 i;
    if (D_841951D2 != 0) return 0;
    if ((D_84195208[D_841951BD][0xF] & 0x60) != 0) return 0;
    value = D_84195208[D_841951BD][0x26];
    if (value == 0 || value == 0xA5) return 0;
    for (i = 0; i < 4; i++) if (D_84195208[D_841951BC][((unsigned long)i) + 5] == value) return 0;
    return 1;
}
#endif

#ifdef VERSION_US
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

s32 func_80062CE0(u8);                              /* extern */
extern u8 D_841951C0;

void func_8412BDF0(void) {
    M2C_FIELD(D_84195208[D_841951BC], s8 *, 0x26) = 0;
    M2C_FIELD(D_84195208[D_841951BC], s8 *, 0x27) = 0;
    if (func_8412BD3C() != 0) {
        M2C_FIELD(&D_84195208[D_841951BC][D_841951C0], u8 *, 5) = (u8) M2C_FIELD(D_84195208[D_841951BD], u8 *, 0x26);
        M2C_FIELD(&D_84195208[D_841951BC][D_841951C0], s8 *, 9) = 5;
        func_84136678(D_841951BC, -1);
        func_8004C54C(0x1EU, func_80062CE0(M2C_FIELD(D_84195208[D_841951BD], u8 *, 0x26)));
        func_84135B00(0x85U);
    } else {
        func_84136678(D_841951BC, -1);
        if (M2C_FIELD(D_84195208[D_841951BD], u8 *, 0xD) & 4) {
            func_84135B00(0xB6U);
        } else {
            func_84135B00(0xB5U);
        }
    }
    func_84124594(D_841951BC);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
extern u8 D_8418548C[]; extern s32 func_84124EFC(u8, u8 *);
extern u8 D_841951BC;
extern u8 * D_84195208[];
s32 func_8412BF4C(u8 arg0) {
    u8 i;

    if (arg0 == 0 || arg0 >= 0xFC) {
        return 1;
    }
    if (func_84124EFC(arg0, D_8418548C) != 0) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        if (D_84195208[D_841951BC][((unsigned long) i) + 5] == arg0) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_841252D0(u8);
extern s32 func_84125080();
extern void func_841253F4(void);
extern s32 func_8412BF4C(u8 arg0);
extern u8 D_841951BC;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_021(void) {
    u8 value;
    D_84195208[D_841951BC][0x26] = 0;
    D_84195208[D_841951BC][0x27] = 0;
    do {
        value = func_84125080() & 0xFF;
    } while (func_8412BF4C(value));
    ((u8 *)D_841951F8[D_841951BC])[0] = 0xFF;
    ((u8 *)D_841951F8[D_841951BC])[1] = value;
    func_841252D0(value);
    func_841253F4();
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8412C0AC begin */
extern void func_84136218(u8, u8);
extern s32 func_841360C0(u8, s16, u16, u8, u8);

void func_8412C0AC(void) {
    s32 id;

    if (func_84126390(D_841951BD, 22) != 0) {
        func_84136678(D_841951BD, -1);
        func_84135B00(102);
        func_841246AC(D_841951BD, D_841951BF);
        func_84136CA8();
    } else {
        id = D_841951BD;
        if ((D_84195208[id][0x10] & 0x10) || (D_84195208[id][0x10] & 0x80)) {
            func_84136678(id, -1);
            func_84135B00(87);
            func_841246AC(D_841951BD, D_841951BF);
            func_84136CA8();
        } else if (D_841951D2 != 0) {
            func_84126B1C(D_841951BC, id, 1);
        } else {
            D_84195208[id][0x10] |= 0x80;
            func_84136218(D_841951BC, 6);
            func_84136218(D_841951BD, 5);
            func_84136678(D_841951BC, -1);
            func_84135B00(186);
            if (func_841360C0(D_841951BC, -2, 60, 6, 13) == 0) {
                func_841360C0(D_841951BD, -2, 60, 5, 13);
            }
            func_84124604(D_841951BD, D_841951BF);
            func_84136CA8();
        }
    }
}
/* mkdraft:func_8412C0AC end */
#endif

#ifdef VERSION_US
void BattleAnim_Table_84185F10_023(void) {
    func_84136678(D_841951BC, -1);
    func_84135B00(0x87U);
    func_84134CBC(D_841951BC, 0U);
    func_84134DD8(D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
void BattleCommand_048(void) {
    u8 turns;
    u8 move;
    move = D_84195208[D_841951BD][38];
    if (D_84195208[D_841951BD][21] > 0 || move == 0 || move == 165 || (*(D_84195208[D_841951BD][4] + (D_84195208[D_841951BD] + 9)) & 0x3F) == 0) {
        func_84126C3C(D_841951BC);
    } else if (D_841951D2 != 0) {
        func_84126B1C(D_841951BC, D_841951BD, 1);
    } else {
        do {
            turns = func_84125080() & 0x7;
        } while (turns == 0);
        turns++;
        turns += func_841251B0(D_84195208[D_841951BD][4] + 1);
        D_84195208[D_841951BD][21] = turns;
        D_84195208[D_841951BD][37] = move;
        func_8004C54C(30, func_80062CE0(move));
        func_84136218(D_841951BC, 6);
        func_84136218(D_841951BD, 5);
        func_84136678(D_841951BC, -1);
        func_84135B00(82);
        if (func_841360C0(D_841951BC, -2, 60, 6, 8) == 0) {
            func_841360C0(D_841951BD, -2, 60, 5, 8);
        }
        func_84124604(D_841951BD, D_841951BF);
        func_84134E30(5);
        BattleRecord_AdvanceWriteSlot();
    }
}
#endif

#ifdef VERSION_US
extern void func_84125424(u8 arg0);
extern void func_841254E0(void);
extern void func_84126BA8(u8 arg0);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern u8 D_841951C3;
extern s32 D_841951C8;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_8412C47C(void) {
    if (D_84195200[D_841951BC][0x24] & 7) { func_84126BA8(D_841951BC); func_841254E0(); return; }
    if (D_84195208[D_841951BC][0x29] == 0) { D_84195208[D_841951BC][0x26] = D_841951BF; D_84195208[D_841951BC][0x27] = D_841951BF; func_84136CA8(); }
    D_841951C8 = 0; func_84136678(D_841951BC, -1); func_84134DD8(D_841951BF);
    switch (D_841951BF) { case 0xD: func_84135B00(0x51); func_84134CBC(D_841951BC, 0x16); break; case 0x4C: func_84135B00(0xAA); func_84134CBC(D_841951BC, 0x17); break; case 0x82: func_84135B00(0x9E); func_84134CBC(D_841951BC, 0x18); break; case 0x8F: func_84135B00(0x37); func_84134CBC(D_841951BC, 0x19); break; case 0x13: func_84135B00(0x69); func_84134CBC(D_841951BC, 0x1A); break; case 0x5B: func_84135B00(0x24); func_84134CBC(D_841951BC, 0x1B); break; }
    D_84195208[D_841951BC][0xF] |= 0x10; switch (D_841951BF) { case 0x13: D_84195208[D_841951BC][0xF] |= 0x40; break; case 0x5B: D_84195208[D_841951BC][0xF] |= 0x20; break; }
    func_84136CA8(); if (D_841951C3 == 0x91) func_84125424(0xFE); else func_841254E0();
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern u8 *D_84195208[];
extern void func_84125424(u8);
void BattleAnim_Table_84185F10_026(void) {
    u8 *rec = D_84195208[D_841951BC];
    if (rec[0xF] & 0x10) {
        rec[0xF] &= 0xFF8F;
        func_84125424(0x31);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84125080();
void BattleAnim_Table_84185F10_027(void) {
    u8 *temp_v0;
    temp_v0 = D_84195208[D_841951BD];
    if ((temp_v0[0x1B] <= 0) && !(temp_v0[0x10] & 0x10)) {
        *(u8 *)((u8 *)D_84195208[D_841951BD] + 0x1B) =
            (func_84125080() & 3) + 3;
        *(u8 *)((u8 *)D_84195208[D_841951BD] + 0x1C) = D_841951BF;
    }
}
#endif

#ifdef VERSION_US
s32 func_84125080();
void BattleAnim_Table_84185F10_028(void) {
    u8 *temp_v0;

    if (!((*(u8 *)((u8 *)(D_84195200[D_841951BC]) + (0x24))) & 7)) {
        temp_v0 = D_84195208[D_841951BC];
        (*(u8 *)((u8 *)(temp_v0) + (0xF))) = (u8) ((*(u8 *)((u8 *)(temp_v0) + (0xF))) | 2);
        (*(s8 *)((u8 *)(D_84195208[D_841951BC]) + (0x12))) = (s8) ((func_84125080() & 1) + 1);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84125080();
extern void func_84125424(u8);
extern u8 D_841951BC;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_029(void) {
    if ((D_84195208[D_841951BC][0xF] & 2) == 0) {
        return;
    }
    D_84195208[D_841951BC][0x12]--;
    if (D_84195208[D_841951BC][0x12] == 0) {
        D_84195208[D_841951BC][0xF] &= 0xFFFD;
        if ((((u8 *)D_841951F8[D_841951BC])[0xB] & 4) == 0) {
            D_84195208[D_841951BC][0xF] |= 0x80;
            D_84195208[D_841951BC][0x13] = (func_84125080() & 1) + 2;
        }
    }
    func_84125424(0x34);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_8412C95C.s")
#endif

#ifdef VERSION_US
extern u8 func_80062D5C(u8);
extern u8 func_80063454(u8, u8, u8, s32);
extern s32 func_841251CC(u8 arg0);
extern s32 func_84126374(void);
extern u8 D_841951BD;
extern s32 D_841951C8;
extern u8 D_841951D2;
extern u8 D_841951D5;
extern u8 D_841951E5;
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_031(void) {
    u8 field = D_84195208[D_841951BD][0x26];
    D_841951D2 = 1;
    if (field != 0 && field != 0x44) {
        if (func_80063454(0, D_84195208[D_841951BD][1], D_84195208[D_841951BD][2], (D_84195208[D_841951BD][0xD] & 8) != 0) == 0) { D_841951D5 = 0; D_841951E5 = 0; return; }
        if (func_84126374() == 0 && func_80062D5C(field) != 0 && func_841251CC(field) != 1) {
            if (D_841951C8 != 0) { D_841951C8 *= 2; if (D_841951C8 >= 0x10000) D_841951C8 = 0xFFFF; D_841951D2 = 0; }
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_8412CBE8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_8412CDA4.s")
#endif

#ifdef VERSION_US
extern void func_84126C3C(u8);
void BattleAnim_Table_84185F10_034(void) {
    if (!((*(u8 *)((u8 *)(D_84195200[D_841951BC]) + (0x24))) & 7)) {
        D_841951C8 = 0;
        D_841951D2 = 1;
        func_84126C3C(D_841951BC);
        func_841254E0();
    }
}
#endif

#ifdef VERSION_US
extern u8 func_80063454(u8, u8, u8, s32);
extern u8 D_841951BD;
extern u8 * D_84195208[];
s32 func_8412CFE4(u8 arg0, u8 arg1) {
    u8 value = arg1;
    if ((value < 10) || ((value >= 20) && (value < 28))) {
        if (func_80063454(arg0, value, value, (D_84195208[D_841951BD][0xD] & 8) != 0) < 10) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_80063270(u8);
extern s32 func_8004C54C(u8, s32);
extern s32 func_84125080();
extern s32 func_8412CFE4(u8 arg0, u8 arg1);
extern void func_84135B40(u16);
extern void func_841366C4(u8, s16);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951D2;
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_035(void) {
    u8 status = D_84195208[D_841951BD][0x26];
    u8 result = func_80062D98(status);
    if (status == 0 || result == 0x13) {
        func_841366C4(D_841951BC, -1);
        if (D_84195208[D_841951BD][0xD] & 4) func_84135B40(0xB6);
        else func_84135B40(0xB5);
        return;
    }
    if (D_841951D2 != 0) {
        func_841366C4(D_841951BC, -1);
        if (D_84195208[D_841951BD][0xD] & 4) func_84135B40(0x56);
        else func_84135B40(0x55);
        return;
    }
    for (;;) {
        u8 candidate = func_84125080() & 0x1F;
        if (func_8412CFE4(result, candidate)) {
            D_84195208[D_841951BC][1] = candidate;
            D_84195208[D_841951BC][2] = candidate;
            func_841366C4(D_841951BC, -1);
            func_8004C54C(0x2F, func_80063270(candidate));
            func_84135B40(0x3C);
            return;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_84126A90(u8 arg0, u8 arg1, u8 arg2);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 D_841951D2;
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_036(void) {
    u8 *ptr = D_84195208[D_841951BD];
    if (ptr[0x10] & 0x10) {
        func_84126A90(D_841951BC, D_841951BD, 0);
    } else if (D_841951D2 != 0) {
        func_84126B1C(D_841951BC, D_841951BD, 1);
    } else {
        ptr[0x11] |= 0x20;
        func_84136678(D_841951BC, -1);
        func_84135B00(0x6A);
        func_84124604(D_841951BD, D_841951BF);
        func_84134E30(5);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84185F10_037(void) {
    (*(s8 *)((u8 *)(D_84195208[D_841951BC]) + (0x26))) = 0;
    (*(s8 *)((u8 *)(D_84195208[D_841951BC]) + (0x27))) = 0;
    func_84136678(D_841951BC, -1);
    func_84135B00(0x87U);
    func_84134CBC(D_841951BC, 0U);
    func_84134DD8(D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84185F10_038(void) {
    u8 *temp_v0;

    temp_v0 = D_84195200[D_841951BD];
    if ((*(u8 *)((u8 *)(temp_v0) + (0x24))) & 0x20) {
        (*(u8 *)((u8 *)(temp_v0) + (0x24))) = 0U;
    }
}
#endif

#ifdef VERSION_US
s32 BattleMove_HasSleepTalkChoice(void) {
    s32 slot;
    if (D_841951D2 != 0) return 0;
    if ((D_84195200[D_841951BC][36] & 7) == 0) return 0;
    for (slot = 0; slot < 4; slot = (u8)(slot + 1)) {
        D_841951BF = D_84195208[D_841951BC][slot + 5];
        if (D_841951BF == 0) return 0;
        if (BattleMove_IsSleepTalkEffectExcluded(D_841951BF) == 0 && D_841951BF != 214 && D_841951BF != D_84195208[D_841951BC][37]) return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 BattleMove_IsSleepTalkSlotEligible(u8 slot) {
    u8 move = D_84195208[D_841951BC][slot + 5];
    if (move == 0 || move == 214 || BattleMove_IsSleepTalkEffectExcluded(move) != 0 || move == D_84195208[D_841951BC][37]) return 0;
    return 1;
}
#endif

#ifdef VERSION_US
extern s32 func_84125080();
extern void func_841252D0(u8);
extern void func_841253F4(void);
extern void func_84126BFC(u8 arg0);
extern u8 D_841951BC;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_8412D53C(void) {
    u8 choice;
    D_84195208[D_841951BC][0x26] = 0;
    D_84195208[D_841951BC][0x27] = 0;
    if (BattleMove_HasSleepTalkChoice() != 0) {
        do {
            choice = func_84125080() & 3;
        } while (BattleMove_IsSleepTalkSlotEligible(choice) == 0);
        ((u8 *)D_841951F8[D_841951BC])[0] = 0xFF;
        ((u8 *)D_841951F8[D_841951BC])[1] = *((u8 *)D_84195208[D_841951BC] + choice + 5);
        func_841252D0(*((u8 *)D_84195208[D_841951BC] + choice + 5));
        func_841253F4();
    } else {
        func_84126BFC(D_841951BC);
    }
}
#endif

#ifdef VERSION_US
s32 func_84126320(u8);
extern void func_84135B40(u16);
extern void func_841366C4(u8, s16);
void BattleAnim_Table_84185F10_040(void) {
    u8 *temp_v0;

    if (func_84126320(D_841951BC) >= 2) {
        temp_v0 = D_84195208[D_841951BC];
        (*(u8 *)((u8 *)(temp_v0) + (0x11))) = (u8) ((*(u8 *)((u8 *)(temp_v0) + (0x11))) | 0x40);
        func_841366C4(D_841951BC, -1);
        func_84135B40(0x82);
        return;
    }
    func_84126BA8(D_841951BC);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_8412D6C0.s")
#endif

#ifdef VERSION_US
extern u8 D_841951D4;
extern u16 D_841951E8;
extern u8 D_841951BD;
extern s32 D_841951C8;
extern u8 * D_84195200[];
void BattleAnim_Table_84185F10_042(void) {
    if (D_841951C8 < *(u16 *)(D_84195200[D_841951BD] + 0x26)) {
        D_841951D4 = 0;
    } else {
        D_841951D4 = 1;
        D_841951C8 = *(u16 *)(D_84195200[D_841951BD] + 0x26) - 1;
        D_841951E8 = D_841951C8;
        if (D_841951D1 == 2) {
            D_841951D1 = 0;
            D_841951E4 = 0;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84136678(u8, s16);
extern void func_84135B00(u16);
extern void func_84134DD8(u8);
extern void func_84134CBC(u8, u8);
extern void BattleRecord_AdvanceWriteSlot(void);
extern void func_84136B9C(u8, s16, u16);
extern void func_841566D0(u8, u8, u8);
extern void func_84125734(u8 arg0);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern void * D_841951F8[];
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleEffect_ClearPartyStatus(void) {
    u8 next_index;
    u16 previous_status;
    s32 index;
    u8 *pokemon;
    u8 *party;
    func_84136678(D_841951BC, -1);
    func_84135B00(180);
    func_84134DD8(D_841951BF);
    func_84134CBC(D_841951BC, 0);
    BattleRecord_AdvanceWriteSlot();
    D_84195208[D_841951BC][13] &= ~1;
    pokemon = D_84195200[D_841951BC];
    previous_status = pokemon[36];
    pokemon[36] = 0;
    func_84136B9C(D_841951BC, -1, 0);
    func_84125734(D_841951BC);
    if (previous_status & 0x20) {
        func_84134CBC(D_841951BC, 44);
    } else if (previous_status & 7) {
        func_84134CBC(D_841951BC, 29);
        func_841566D0(D_841951BC, ((u8 *)D_841951F8[D_841951BC])[10], 0x20);
    } else {
        func_84134CBC(D_841951BC, 86);
    }
    BattleRecord_AdvanceWriteSlot();
    index = 0;
    D_84195208[D_841951BC][20] = 0;
    party = (u8 *)D_841951F8[D_841951BC];
    while (index < party[8]) {
        party[index * 88 + 60] = 0;
        next_index = index + 1;
        index = next_index;
        party = (u8 *)D_841951F8[D_841951BC];
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951C5;
extern u8 func_80063690(u8);
extern u8 func_80063660(u8);
extern s32 func_84125080();
void BattleAnim_Table_84185F10_044(void) {
    u8 limit;
    if ((D_841951D2 == 0) &&
        (func_80063660(D_841951C5) == 0x4B) &&
        !(((u8 *)D_84195208[D_841951BD])[0x10] & 0x10)) {
        limit = func_80063690(D_841951C5);
        if (func_84125080() < limit) {
            ((u8 *)D_84195208[D_841951BD])[0x10] &= 0xFFDF;
            ((u8 *)D_84195208[D_841951BD])[0xF] |= 8;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_841951C8;
extern u8 D_841951D7;
void BattleAnim_Table_84185F10_045(void) {
    if (D_841951D7 != 0) {
        D_841951C8 *= D_841951D7 + 1;
        if (D_841951C8 >= 0x10000) D_841951C8 = 0xFFFF;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951D7;
void BattleAnim_Table_84185F10_046(void) {
    D_841951D7 += 1;
}
#endif

#ifdef VERSION_US
extern s32 func_80063754(s32);
extern void func_84134EC8(u8 arg0);
extern void func_84135B40(u16);
extern void func_841366C4(u8, s16);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951D3;
extern u8 * D_84195200[];
void func_8412DC20(void) {
    u8 value;

    if (D_84195200[D_841951BC][1] == 0) {
        value = D_84195200[D_841951BD][1];
        if ((value != 0) && (func_80063754(value) == 0) && (D_841951D3 == 0)) {
            D_84195200[D_841951BC][1] = D_84195200[D_841951BD][1];
            D_84195200[D_841951BD][1] = 0;
            func_841366C4(D_841951BD, -1);
            func_84135B40(0x2D);
            func_84134EC8(0x20);
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_84126BA8(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 * D_84195208[];
void BattleAnim_Table_84185F10_048(void) {
    if ((D_84195208[D_841951BD][0xF] & 0x60) != 0 || (D_84195208[D_841951BC][0x11] & 0x80) != 0) {
        func_84126BA8(D_841951BC);
    } else {
        D_84195208[D_841951BC][0x11] |= 0x80;
        func_84136678(D_841951BD, -1);
        func_84135B00(0xAE);
        func_84124604(D_841951BD, D_841951BF);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern void BattleRecord_AdvanceWriteSlot(void);
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_84126BA8(u8 arg0);
extern void func_84134E30(s32 arg0);
extern void func_84135B00(u16 arg0);
extern void func_84136678(u8 arg0, s16 arg1);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleCommand_073(void) {
    u8 *ptr = D_84195208[D_841951BD];
    if ((ptr[15] & 0x60) || (ptr[16] & 0x10) || !(D_84195200[D_841951BD][36] & 7) || (ptr[13] & 1)) {
        func_84126BA8(D_841951BC);
    } else {
        ptr[13] |= 1;
        func_84136678(D_841951BD, -1);
        func_84135B00(30);
        func_84134E30(5);
        func_84124604(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
    }
}
void BattleCommand_NoOp074(void) {
}
#endif

#ifdef VERSION_US
extern void func_84126FA0(u8);
extern void BattleAnim_Table_84186004_018(void);
extern void BattleAnim_Table_84186004_019(void);
extern void BattleAnim_Table_84186004_076(void);
extern void func_84136AF8(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
void BattleCommand_075(void) {
    u16 amount;
    u32 damage;
    u8 changed;
    if (func_84126390(D_841951BC, 8) != 0) {
        if ((D_84195208[D_841951BD][15] & 0x60) != 0 ||
            (D_84195208[D_841951BD][16] & 0x10) != 0 ||
            (D_84195208[D_841951BD][13] & 0x2) != 0) {
            func_84126BA8(D_841951BC);
        } else {
            BattleAnim_Table_84186004_076();
            D_84195208[D_841951BD][13] |= 0x2;
            amount = func_8412676C(D_841951BC, 1);
            damage = func_84126804(D_841951BC, amount);
            func_84136AF8(D_841951BC, -1, (s16)(-damage), 1);
            func_84136218(D_841951BC, 6);
            func_84136218(D_841951BD, 5);
            func_841366C4(D_841951BC, -1);
            func_84135B40(103);
            if (func_84136124(D_841951BC, -2, 60, 6, 11) == 0) {
                func_84136124(D_841951BD, -2, 60, 5, 11);
            }
            func_84134EC8(0x80);
            func_84134E30(5);
            func_84124604(D_841951BD, D_841951BF);
            BattleRecord_AdvanceWriteSlot();
        }
    } else if (func_84125B88(D_841951BC, 0, 0) != 0 || func_84125B88(D_841951BC, 1, 0) != 0) {
        D_841951D2 = 0;
        changed = 0;
        func_84125EC0(D_841951BC, 2, 1, 1);
        if (D_841951D8 == 0) {
            func_84136678(D_841951BC, -1);
            func_84126FA0((u8)(D_841951D9 & 0xF));
            func_8004C54C(28, (s32)(D_84195200[D_841951BC] + 52));
            func_84135B00(141);
            func_8004C54C(28, (s32)(D_84195200[D_841951BD] + 52));
            changed = 1;
        }
        D_841951D2 = 0;
        BattleAnim_Table_84186004_018();
        if (D_841951D8 == 0) {
            func_84136678(D_841951BC, -1);
            func_84126FA0((u8)(D_841951D9 & 0xF));
            func_84135B00(143);
        }
        D_841951D2 = 0;
        BattleAnim_Table_84186004_019();
        if (D_841951D8 == 0) {
            func_84136678(D_841951BC, -1);
            func_84126FA0((u8)(D_841951D9 & 0xF));
            func_84135B00(143);
        }
        func_84134DD8(D_841951BF);
        if (changed != 0) {
            func_84134CBC(D_841951BC, 79);
        } else {
            func_84134CBC(D_841951BC, 65);
        }
        BattleRecord_AdvanceWriteSlot();
    } else {
        BattleRecord_AdvanceWriteSlot();
        D_841951D8 = 2;
        D_841951D9 = 7;
        func_84124594(D_841951BC);
        func_84136678(D_841951BC, -1);
        func_84126FA0((u8)(D_841951D9 & 0xF));
        func_84135B00(99);
        BattleRecord_AdvanceWriteSlot();
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84125080();
extern s32 func_84126374(void);
extern u8 D_841951BC;
extern u8 * D_84195208[];
s32 func_8412E220(void) {
    u8 pad[8];
    s32 count;
    s32 value;
    if (func_84126374() != 0) {
        if (!(D_84195208[D_841951BC][0x10] & 0x10)) {
            count = (0xFF >> D_84195208[D_841951BC][0x19]) & 0xFF;
            if (count > 0) {
                do {
                    value = func_84125080();
                } while (value == 0);
                value = (value - 1) & 0xFF;
                if (value < count) {
                    D_84195208[D_841951BC][0x19]++;
                    return 1;
                }
            }
        }
    }
    D_84195208[D_841951BC][0x19] = 0;
    func_84126BFC(D_841951BC);
    return 0;
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84185FDC_001(void) {
    u8 *temp_v0;

    if (func_8412E220() != 0) {
        temp_v0 = D_84195208[D_841951BC];
        (*(u8 *)((u8 *)(temp_v0) + (0xD))) = (u8) ((*(u8 *)((u8 *)(temp_v0) + (0xD))) | 4);
        func_84136678(D_841951BC, -1);
        func_84135B00(0x74U);
        func_84134CBC(D_841951BC, 0U);
        func_84134DD8(D_841951BF);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_84134E30(s32 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern void * D_841951F8[];
void BattleAnim_Table_84185FDC_002(void) {
    u8 *ptr = (u8 *)D_841951F8[D_841951BD];
    if (ptr[0xB] & 1) {
        func_84126C3C(D_841951BC);
        return;
    }
    ptr[0xB] |= 1;
    func_84136678(D_841951BC, -1);
    func_84135B00(0x70);
    func_84134E30(5);
    func_84124604(D_841951BD, D_841951BF);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_84126B1C(u8 arg0, u8 arg1, u8 arg2);
extern void func_84126C3C(u8);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84134E30(s32 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 D_841951D2;
extern u8 * D_84195208[];
void func_8412E420(void) {
    u8 *ptr;

    ptr = D_84195208[D_841951BD];
    if ((ptr[0xF] & 0x60) || (ptr[0xD] & 8)) {
        func_84126C3C(D_841951BC);
    } else if (D_841951D2 != 0) {
        func_84126B1C(D_841951BC, D_841951BD, 1);
    } else {
        ptr[0xD] |= 8;
        func_84134CBC(D_841951BC, 0);
        func_84134DD8(D_841951BF);
        func_84136CA8();
        func_84136678(D_841951BC, -1);
        func_84135B00(0x84);
        func_84134E30(5);
        func_84124604(D_841951BD, D_841951BF);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
void BattleCommand_079(void) {
    if (((D_84195208[D_841951BC][13] & 0x10) && (D_84195208[D_841951BD][13] & 0x10)) || func_84126320(D_841951BC) < 2) {
        func_84126BFC(D_841951BC);
        return;
    }
    if ((D_84195208[D_841951BC][13] & 0x10) == 0) {
        D_84195208[D_841951BC][13] |= 0x10;
        D_84195208[D_841951BC][23] = 4;
    }
    if ((D_84195208[D_841951BD][13] & 0x10) == 0) {
        D_84195208[D_841951BD][13] |= 0x10;
        D_84195208[D_841951BD][23] = 4;
    }
    func_84136678(D_841951BC, -1);
    func_84135B00(63);
    func_84134E30(5);
    func_84124604(D_841951BD, D_841951BF);
    BattleRecord_AdvanceWriteSlot();
    func_84134CBC(D_841951BC, 89);
    BattleRecord_AdvanceWriteSlot();
}
#endif

#ifdef VERSION_US
void BattleCommand_080(void) {
    if (((u8 *)D_841951F0)[2500] == 3) {
        func_84126BFC(D_841951BC);
    } else {
        ((u8 *)D_841951F0)[2500] = 3;
        ((u8 *)D_841951F0)[2501] = 5;
        func_84136218(D_841951BC, 6);
        func_84136218(D_841951BD, 5);
        func_841366C4(D_841951BC, -1);
        func_84135B40(178);
        if (func_84136124(D_841951BC, -1, 60, 6, 16) == 0) {
            func_84136124(D_841951BD, -1, 60, 5, 16);
        }
    }
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84185FDC_006(void) {
    u8 *temp_v0;

    if (func_8412E220() != 0) {
        temp_v0 = D_84195208[D_841951BC];
        (*(u8 *)((u8 *)(temp_v0) + (0xD))) = (u8) ((*(u8 *)((u8 *)(temp_v0) + (0xD))) | 0x20);
        func_84136678(D_841951BC, -1);
        func_84135B00(0x61U);
        func_84134DD8(D_841951BF);
        func_84134CBC(D_841951BC, 0U);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern void func_84125424(u8);
void BattleAnim_Table_84185FDC_007(void) {
    u8 *temp_v0;

    temp_v0 = D_84195208[D_841951BC];
    if ((*(u8 *)((u8 *)(temp_v0) + (0xD))) & 0x40) {
        func_84125424(2);
        return;
    }
    (*(s8 *)((u8 *)(temp_v0) + (0x12))) = 0;
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern s32 D_841951C8;
extern u8 D_841951D2;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleCommand_083(void) {
    u8 *ptr;
    s32 bit;
    if (!(D_84195200[D_841951BC][36] & 7)) {
        if (D_841951D2) {
            ptr = D_84195208[D_841951BC];
            ptr[13] &= 0xFFBF;
            return;
        }
        ptr = D_84195208[D_841951BC];
        ptr[18]++;
        ptr = D_84195208[D_841951BC];
        if (ptr[18] >= 5) {
            ptr[13] &= 0xFFBF;
        } else {
            ptr[13] |= 0x40;
        }
        ptr = D_84195208[D_841951BC];
        if (ptr[14] & 1) {
            bit = 1;
        } else {
            bit = 0;
        }
        D_841951C8 <<= ptr[18] + bit + 31;
        if (D_841951C8 >= 0x10000) {
            D_841951C8 = 0xFFFF;
        }
    }
}
void BattleCommand_NoOp084(void) {
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern s32 D_841951C8;
extern u8 D_841951D2;
extern u8 * D_84195208[];
void BattleAnim_Table_84186004_000(void) {
    if (D_841951D2 != 0) {
        D_84195208[D_841951BC][0x18] = 0;
        return;
    }
    D_84195208[D_841951BC][0x18]++;
    if (D_84195208[D_841951BC][0x18] >= 6) {
        D_84195208[D_841951BC][0x18] = 5;
    }
    D_841951C8 <<= D_84195208[D_841951BC][0x18] + 0x1F;
    if (D_841951C8 >= 0x10000) D_841951C8 = 0xFFFF;
}
#endif

#ifdef VERSION_US
s32 func_8412EA28(void) {
    u8 first_value;
    u8 second_value;

    if (D_841951D2 != 0) {
        return 0;
    }
    if ((D_84195208[D_841951BD][0xF] & 0x60) != 0) {
        return 0;
    }
    if (D_84195208[D_841951BD][0xD] & 0x80) {
        return 0;
    }
    first_value = func_80064474(D_84195200[D_841951BC][0], *(u16 *)(D_84195200[D_841951BC] + 0x16));
    second_value = func_80064474(D_84195200[D_841951BD][0], *(u16 *)(D_84195200[D_841951BD] + 0x16));
    if (first_value == 0 || second_value == 0 || first_value == second_value) {
        return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern s32 func_8412EA28(void);
extern u8 *D_84195208[];
extern void func_84134DD8(u8);
extern void func_84134CBC(u8, u8);
extern void BattleRecord_AdvanceWriteSlot(void);
extern void func_84136218(u8, u8);
extern void func_84136678(u8, s16);
extern void func_84135B00(u16);
extern s32 func_841360C0(u8, s16, u16, u8, u8);
extern void func_84134E30(s32);
extern void func_84124604(u8, u8);
extern void func_84126C3C(u8);

void func_8412EB10(void) {
    if (func_8412EA28() != 0) {
        D_84195208[D_841951BD][0xD] |= 0x80;
        func_84134DD8(D_841951BF);
        func_84134CBC(D_841951BC, 0);
        BattleRecord_AdvanceWriteSlot();
        func_84136218(D_841951BC, 6);
        func_84136218(D_841951BD, 5);
        func_84136678(D_841951BD, -1);
        func_84135B00(122);
        if (func_841360C0(D_841951BC, -2, 60, 6, 10) == 0) {
            func_841360C0(D_841951BD, -2, 60, 5, 10);
        }
        func_84134E30(5);
        func_84124604(D_841951BD, D_841951BF);
        BattleRecord_AdvanceWriteSlot();
        return;
    }
    func_84126C3C(D_841951BC);
}
#endif

#ifdef VERSION_US
extern s8 D_841951C2;

void BattleAnim_Table_84186004_002(void) {
    D_841951C2 = (s8) ((s32) ((*(u8 *)((u8 *)(D_84195200[D_841951BC]) + (0x1C))) * 0xA) / 25);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_8412EC70.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_8412EE5C.s")
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern s8 D_841951C2;
extern u8 * D_84195200[];
void BattleAnim_Table_84186004_005(void) {
    D_841951C2 = ((-(s32)D_84195200[D_841951BC][0x1C] * 10) + 0x9F6) / 25;
}
#endif

#ifdef VERSION_US
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern void * D_841951F8[];
void BattleAnim_Table_84186004_006(void) {
    if ((((u8 *)D_841951F8[D_841951BC])[0xB] & 4) != 0) { func_84126BFC(D_841951BC); return; }
    ((u8 *)D_841951F8[D_841951BC])[0xB] = ((u8 *)D_841951F8[D_841951BC])[0xB] | 4; ((u8 *)D_841951F8[D_841951BC])[0xC] = 5;
    func_84136678(D_841951BC, -1); func_84135B00(0xA3); func_84134DD8(D_841951BF);
    func_84134CBC(D_841951BC, 0); func_84136CA8();
}
#endif

#ifdef VERSION_US
extern void func_841254E0(void);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
void BattleAnim_Table_84186004_007(void) {
    if (((u8 *)D_841951F8[D_841951BD])[0xB] & 4) {
        D_841951D2 = 1;
        func_84136678(D_841951BD, -1);
        func_84135B00(0x73);
        func_841246AC(D_841951BD, D_841951BF);
        func_84136CA8();
        func_841254E0();
    }
}
#endif

#ifdef VERSION_US
extern u8 D_8418546C[];
void func_84135034(u8, u8);
extern void func_8004C594(s32, s32);
extern s32 func_84125080();
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern u8 D_841951BC;
extern s8 D_841951C2;
void func_8412F170(void) {
    u8 value;
    u8 count;
    u8 (*p)[2];
    s32 raw;

    raw = func_84125080();
    value = raw;
    p = (u8 (*)[2])D_8418546C;
    count = 4;
    if ((*p)[0] < raw) {
        do {
            count++;
            p++;
        } while ((*p)[0] < value);
    }
    D_841951C2 = (*p)[1];
    func_84136678(D_841951BC, -1);
    func_8004C594(1, count);
    func_84135B00(0x6B);
    func_84135034(count, count);
}
#endif

#ifdef VERSION_US
extern void Battle_ApplySwitchInState(u8);
extern s32 func_841262C4(u8 arg0);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134DD8(u8 arg0);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleAnim_Table_84186004_009(void) {
    u8 *record;
    if (func_841262C4(D_841951BC) != 0) {
        func_84134DD8(D_841951BF);
        func_84134CBC(D_841951BC, 0);
        func_84136CA8();
        Battle_ApplySwitchInState(D_841951BC);
        if ((D_84195200[D_841951BC][0x24] & 7) == 0) {
            record = D_84195208[D_841951BC];
            record[0xD] &= 0xFFFE;
        }
        D_84195208[D_841951BC][0x15] = 0;
        D_84195208[D_841951BC][0x25] = 0;
        func_84126A64();
        record = D_84195208[D_841951BC];
        record[0x11] &= 0xFFE7;
        D_84195208[D_841951BC][0x27] = 0;
        D_84195208[D_841951BC][0x1B] = 0;
        D_84195208[D_841951BD][0x1B] = 0;
    } else {
        func_84126BFC(D_841951BC);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951BD;
extern void *D_841951F8[];
extern u8 *D_84195208[];
extern s32 D_841951C8;
void BattleAnim_Table_84186004_010(void) {
    void *rec = D_841951F8[D_841951BD];
    u8 *flag = (u8 *) rec + 0x10;
    if (*flag != 0) {
        D_841951C8 = D_841951C8 << 1;
        if (D_841951C8 >= 0x10000) {
            D_841951C8 = 0xFFFF;
        }
    }
    *flag = 0;
}
#endif

#ifdef VERSION_US
extern void func_84135B8C(u8 arg0, u16 arg1);
extern void func_84136720(u8 arg0, u8 arg1, s16 arg2);
extern u8 D_841951BC;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_8412F39C(void) {
    if (D_84195208[D_841951BC][0x10] & 0x80) {
        D_84195208[D_841951BC][0x10] &= 0xFF7F;
        func_84136720(0, D_841951BC, -1);
        func_84135B8C(0, 0xAC);
    }
    if (((u8 *)D_841951F8[D_841951BC])[0xB] & 1) {
        ((u8 *)D_841951F8[D_841951BC])[0xB] &= 0xFFFE;
        func_84136720(0, D_841951BC, -1);
        func_84135B8C(0, 0xAD);
    }
    if (D_84195208[D_841951BC][0x1B] > 0) {
        D_84195208[D_841951BC][0x1B] = 0;
        func_84136720(0, D_841951BC, -1);
        func_84135B8C(0, 0xAB);
    }
}
#endif

#ifdef VERSION_US
extern void func_841366C4(u8, s16);
extern void func_84135B40(u16);
extern void func_84136AF8(u8, s16, s16, u8);
extern u8 D_841951BC;
extern void * D_841951F0;
extern u8 * D_84195200[];
void BattleEffect_HealByWeather(void) {
    u16 amount;
    u8 shift;
    s32 missing;
    s32 healing;
    u16 maximum_hp;
    u16 current_hp;
    u8 *pokemon;
    pokemon = D_84195200[D_841951BC];
    maximum_hp = *(u16 *)(pokemon + 40);
    current_hp = *(u16 *)(pokemon + 38);
    if (maximum_hp == current_hp) {
        func_841366C4(D_841951BC, -1);
        func_84135B40(118);
        return;
    }
    switch (((u8 *)D_841951F0)[2500]) {
    case 0:
        shift = 1;
        break;
    case 2:
        shift = 0;
        break;
    case 1:
    case 3:
        shift = 2;
        break;
    }
    missing = maximum_hp - current_hp;
    healing = maximum_hp >> shift;
    if (missing < healing) {
        amount = missing;
    } else {
        amount = healing;
    }
    *(u16 *)(pokemon + 38) = current_hp + amount;
    func_84136AF8(D_841951BC, -1, amount, 1);
    func_841366C4(D_841951BC, -1);
    func_84135B40(80);
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_012(void) {
    func_8412F49C();
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_013(void) {
    func_8412F49C();
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_014(void) {
    func_8412F49C();
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC; extern u8 *D_84195208[]; extern s8 D_841951C1; extern s8 D_841951C2; extern s32 func_84126EDC(u16); extern s32 func_84126E88(u16); extern void func_84127DB8(void);
void BattleAnim_Table_84186004_015(void) {
    u16 val = *(u16 *)(D_84195208[D_841951BC] + 0x2E);
    D_841951C1 = func_84126EDC(val);
    D_841951C2 = func_84126E88(val);
    func_84127DB8();
}
#endif

#ifdef VERSION_US
extern void *D_841951F0;
extern u8 D_841951BC;
extern void func_84136218(u8, u8);
extern void func_841366C4(u8, s16);
extern void func_84135B40(u16);
extern s32 func_84136124(u8, s16, u16, u8, u8);
void BattleAnim_Table_84186004_016(void) {
    (*(u8 *)((u8 *)D_841951F0 + 0x9C4)) = 1;
    (*(u8 *)((u8 *)D_841951F0 + 0x9C5)) = 5;
    func_84136218(D_841951BC, 6);
    func_841366C4(D_841951BC, -1);
    func_84135B40(0x23);
    func_84136124(D_841951BC, -1, 0x3C, 6, 0xF);
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_017(void) {
    (*(u8 *)((u8 *)D_841951F0 + 0x9C4)) = 2;
    (*(u8 *)((u8 *)D_841951F0 + 0x9C5)) = 5;
    func_84136218(D_841951BC, 6);
    func_841366C4(D_841951BC, -1);
    func_84135B40(0x8A);
    func_84136124(D_841951BC, -1, 0x3C, 6, 0xE);
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_018(void) { func_84125CF8(D_841951BC, 0, 1, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_019(void) { func_84125CF8(D_841951BC, 1, 1, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_020(void) { func_84125CF8(D_841951BC, 2, 1, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_021(void) { func_84125CF8(D_841951BC, 3, 1, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_022(void) { func_84125CF8(D_841951BC, 4, 1, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_023(void) { func_84125CF8(D_841951BC, 5, 1, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_024(void) { func_84125CF8(D_841951BC, 6, 1, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_025(void) { func_84125CF8(D_841951BC, 0, 2, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_026(void) { func_84125CF8(D_841951BC, 1, 2, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_027(void) { func_84125CF8(D_841951BC, 2, 2, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_028(void) { func_84125CF8(D_841951BC, 3, 2, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_029(void) { func_84125CF8(D_841951BC, 4, 2, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_030(void) { func_84125CF8(D_841951BC, 5, 2, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BC; void BattleAnim_Table_84186004_031(void) { func_84125CF8(D_841951BC, 6, 2, 0); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_032(void) { func_84125CF8(D_841951BD, 0, 1, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_033(void) { func_84125CF8(D_841951BD, 1, 1, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_034(void) { func_84125CF8(D_841951BD, 2, 1, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_035(void) { func_84125CF8(D_841951BD, 3, 1, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_036(void) { func_84125CF8(D_841951BD, 4, 1, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_037(void) { func_84125CF8(D_841951BD, 5, 1, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_038(void) { func_84125CF8(D_841951BD, 6, 1, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_039(void) { func_84125CF8(D_841951BD, 0, 2, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_040(void) { func_84125CF8(D_841951BD, 1, 2, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_041(void) { func_84125CF8(D_841951BD, 2, 2, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_042(void) { func_84125CF8(D_841951BD, 3, 2, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_043(void) { func_84125CF8(D_841951BD, 4, 2, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_044(void) { func_84125CF8(D_841951BD, 5, 2, 1); }
#endif

#ifdef VERSION_US
extern u8 D_841951BD; void BattleAnim_Table_84186004_045(void) { func_84125CF8(D_841951BD, 6, 2, 1); }
#endif

#ifdef VERSION_US
extern void func_84124DEC(u8);
extern u8 D_841951D8;
extern void func_84126FA0(u8);
extern u8 D_841951D9;
void BattleAnim_Table_84186004_046(void) {
    if (D_841951D8 == 0) {
        func_84136678(D_841951BC, -1);
        func_84126FA0(D_841951D9 & 0xF & 0xFF);
        if (D_841951D9 & 0xF0) {
            func_84135B00(0x90U);
        } else {
            func_84135B00(0x8FU);
        }
        func_84124DEC(D_841951BC);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_84126FA0(u8);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84134E00(u8 arg0);
extern void func_84134E30(s32 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136CA8(void);
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 D_841951D8;
extern u8 D_841951D9;
void func_8412FD24(void) {
    if (D_841951D8 == 0) {
        func_84126FA0((u8)(D_841951D9 & 0xF));
        func_84124604(D_841951BD, D_841951BF);
        switch (D_841951BF) {
            case 0x2D:
            case 0x51:
            case 0x67:
            case 0x6C:
            case 0xB2:
            case 0xCC:
            case 0xE6:
                func_84134E30(5);
            case 0x1C:
            case 0x94:
                func_84136CA8();
                func_84136678(D_841951BD, -1);
                if (D_841951D9 & 0xF0) {
                    func_84135B00(0x8E);
                } else {
                    func_84135B00(0x8D);
                }
                func_84134CBC(D_841951BD, 0x42);
                break;
            case 0x27:
            case 0x2B:
            case 0x86:
            case 0xB8:
                func_84136678(D_841951BD, -1);
                if (D_841951D9 & 0xF0) {
                    func_84135B00(0x8E);
                } else {
                    func_84135B00(0x8D);
                }
                func_84134E30(6);
                func_84134E00(0x10);
                break;
            default:
                func_84136678(D_841951BD, -1);
                if (D_841951D9 & 0xF0) {
                    func_84135B00(0x8E);
                } else {
                    func_84135B00(0x8D);
                }
                func_84134E00(0x10);
                func_84134E30(5);
                break;
        }
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_048(void) {
    switch (D_841951D8) {                           /* irregular */
    case 1:
        func_84126BA8(D_841951BC);
        return;
    case 2:
        func_841366C4(D_841951BC, -1);
        func_84126FA0(D_841951D9 & 0xF & 0xFF);
        func_84135B40(0x63);
        /* fallthrough */
    case 0:
        return;
    }
}
#endif

#ifdef VERSION_US
extern void func_84126BA8(u8 arg0);
extern void func_84126FA0(u8);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 D_841951D8;
extern u8 D_841951D9;
void func_8412FF80(void) {
    switch (D_841951D8) {
    case 1:
        func_84126BA8(D_841951BC);
        return;
    case 2:
        func_84136678(D_841951BC, -1);
        func_84126FA0(D_841951D9 & 0xF & 0xFF);
        func_84135B00(0x64);
        func_841246AC(D_841951BD, D_841951BF);
        func_84136CA8();
        return;
    case 3:
        func_84136678(D_841951BC, -1);
        func_84135B00(0x30);
        func_841246AC(D_841951BD, D_841951BF);
        func_84136CA8();
        return;
    case 0:
    default:
        return;
    }
}
#endif

#ifdef VERSION_US
extern u8 func_80062F2C(u8);
extern s32 func_84125080();
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u8 D_841951D3;
extern u8 * D_84195208[];
void BattleAnim_Table_84186004_050(void) {
    u8 value;

    D_841951D3 = 0;
    if ((D_84195208[D_841951BD][0x10] & 0x10) ||
        (value = func_80062F2C(D_841951BF), func_84125080() >= value)) {
        D_841951D3 = 1;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8004B7A4(s32);
extern s32 func_8004C54C(u8, s32);
extern u8 D_841951BC;
extern u8 D_841951BD;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_841300D0(void) {
    D_841951BC = 1 - D_841951BC;
    D_841951BD = 1 - D_841951BD;
    func_8004C54C(0x19, func_8004B7A4(D_84195208[D_841951BC][0]));
    func_8004C54C(0x1A, (s32)(D_84195200[D_841951BC] + 0x34));
    func_8004C54C(0x1B, func_8004B7A4(D_84195208[D_841951BD][0]));
    func_8004C54C(0x1C, (s32)(D_84195200[D_841951BD] + 0x34));
}
#endif

#ifdef VERSION_US
extern s32 func_84126374(void);
void BattleAnim_Table_84186004_052(void) {
    if (D_841951D2 == 0) {
        if ((((u8 *)D_84195208[D_841951BD])[0x10] & 0x10) ||
            (*(u8 *)((u8 *)D_84195200[D_841951BD] + 0x24) & 0x27) ||
            (func_84126374() == 0)) {
            D_841951D2 = 1;
            return;
        }
        ((u8 *)D_84195208[D_841951BD])[0xF] |= 8;
        ((u8 *)D_84195208[D_841951BD])[0x10] &= 0xFFDF;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_84125B88(u8, u8, u8);
extern s32 func_8412676C(u8 arg0, u8 arg1);
extern u32 func_84126804(u8, u16);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleAnim_Table_84186004_053(void) {
    if (func_84125B88(D_841951BC, 0, 0) == 0 || (((u16 *)D_84195200[D_841951BC])[0x14] >> 1) >= ((u16 *)D_84195200[D_841951BC])[0x13]) {
        func_84126BFC(D_841951BC);
        return;
    }
    {
        s32 value = func_84126804(D_841951BC, (u16)func_8412676C(D_841951BC, 1));
        func_84136A9C(D_841951BC, -1, (s16)-value, 1);
        D_84195208[D_841951BC][0x1E] = 0xD;
        func_841256E0(D_841951BC, 0);
        func_84136678(D_841951BC, -1);
        func_84135B00(0x39);
        func_84134CBC(D_841951BC, 0x41);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_84130380 begin */
extern u8 D_841951BD;
extern u8 D_841951BC;
extern u8 *D_84195208[];
extern void func_84125734(u8);
extern void func_841366C4(u8, s16);
extern void func_84135B40(u16);
extern void func_84126BFC(u8);

void func_84130380(void) {
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_2;

    var_a1 = 0;
    for (var_v0 = 0; var_v0 < 7; var_v0 = (var_v0 + 1) & 0xFF) {
        if (D_84195208[D_841951BD][var_v0 + 0x1E] != 7) {
            var_a1 = 1;
            break;
        }
    }
    if (var_a1 != 0) {
        for (var_v0_2 = 0; var_v0_2 < 7; var_v0_2 = (var_v0_2 + 1) & 0xFF) {
            D_84195208[D_841951BC][var_v0_2 + 0x1E] = D_84195208[D_841951BD][var_v0_2 + 0x1E];
        }
        func_84125734(D_841951BC);
        func_841366C4(D_841951BC, -1);
        func_84135B40(0x49);
        return;
    }
    func_84126BFC(D_841951BC);
}
/* mkdraft:func_84130380 end */
#endif

#ifdef VERSION_US
extern u8 D_841951BC; extern u8 *D_84195208[]; void BattleAnim_Table_84186004_055(void) { D_84195208[D_841951BC][0x10] |= 0x40; }
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_056(void) {
    if (D_84195208[D_841951BD][0xF] & 0x40) {
        D_841951C8 = D_841951C8 << 1;
        if (D_841951C8 >= 0x10000) {
            D_841951C8 = 0xFFFF;
        }
    }
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_057(void) {
    if (D_84195208[D_841951BD][0xF] & 0x20) {
        D_841951C8 = D_841951C8 << 1;
        if (D_841951C8 >= 0x10000) {
            D_841951C8 = 0xFFFF;
        }
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951BD;
extern u8 *D_84195208[];
extern u8 D_841951D2;
extern u8 D_841951D5;
extern u8 D_841951E5;
extern s32 D_841951C8;
extern u8 func_80063454(u8, u8, u8, s32);
extern u8 func_80062D5C(u8);
extern s32 func_84126374(void);
extern s32 func_841251CC(u8);
void BattleAnim_Table_84186004_058(void) {
    u8 field;
    u8 *rec;

    rec = D_84195208[D_841951BD];
    field = rec[0x26];
    D_841951D2 = 1;
    if (field == 0 || field == 0xF3) {
        return;
    }
    if (func_80063454(0x18, rec[1], rec[2], (rec[0xD] & 8) != 0) == 0) {
        D_841951D5 = 0;
        D_841951E5 = 0;
        return;
    }
    if (func_84126374() != 0) {
        return;
    }
    if (func_80062D5C(field) == 0) {
        return;
    }
    if (func_841251CC(field) != 0) {
        if (D_841951C8 != 0) {
            D_841951C8 = D_841951C8 << 1;
            if (D_841951C8 >= 0x10000) {
                D_841951C8 = 0xFFFF;
            }
            D_841951D2 = 0;
        }
    }
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_059(void) {
    u8 *temp_v0;

    temp_v0 = D_84195208[D_841951BC];
    if (*(u8 *)((u8 *)temp_v0 + 0x1A) == 1) {
        *(u8 *)((u8 *)temp_v0 + 0x1A) = 0;
        D_841951C8 = *(u16 *)((u8 *)D_84195208[D_841951BC] + 0x30);
        func_84125424(0x91);
    }
}
#endif

#ifdef VERSION_US
extern void BattleAnim_Table_84186004_076(void);
extern void func_841254E0(void);
extern void func_84126BA8(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern u8 D_841951BC;
extern u8 D_841951BF;
extern s32 D_841951C8;
extern u8 * D_84195208[];
void func_841306AC(void) {
    if (D_84195208[D_841951BC][0x29] == 0) {
        D_84195208[D_841951BC][0x26] = D_841951BF;
        D_84195208[D_841951BC][0x27] = D_841951BF;
    }
    if (D_84195208[D_841951BC][0x1A] != 0) {
        D_841951C8 = 0;
        func_84126BA8(D_841951BC);
    } else {
        D_84195208[D_841951BC][0x1A] = 4;
        *(s16 *)(D_84195208[D_841951BC] + 0x30) = D_841951C8;
        D_841951C8 = 0;
        func_84136678(D_841951BC, -1);
        func_84135B00(0x80);
        BattleAnim_Table_84186004_076();
    }
    func_841254E0();
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_061(void) {
    if (D_84195208[D_841951BD][0x2A] != 0) {
        D_841951C8 = D_841951C8 << 1;
        if (D_841951C8 >= 0x10000) {
            D_841951C8 = 0xFFFF;
        }
    }
}
#endif

#ifdef VERSION_US

void BattleAnim_Table_84186004_062(void) {
    if ((*(u8 *)((u8 *)(D_841951F0) + (0x9C4))) == 2) {
        func_84125424(0x31);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951C4;
void BattleAnim_Table_84186004_063(void) {
    u8 value = *(u8 *)((u8 *)D_841951F0 + 0x9C4);
    if (value != 1) {
        if (value == 2) {
            D_841951C4 = 0x80;
        }
    } else {
        D_841951C4 = 0xFF;
    }
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_064(void) {
    func_84136678(D_841951BC, -1);
    func_84135B00(0xB5U);
    func_84124594(D_841951BC);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
extern void func_8413523C(u8, u8);
extern s32 D_841951E0;
void BattleCommand_150(void) {
    u8 slot;
    D_841951C8 = 0;
    if ((D_84195208[D_841951BC][15] & 0x4) == 0) {
        D_84195208[D_841951BC][18] = 0;
        D_841951E0 = 0;
    }
    slot = D_84195208[D_841951BC][18];
    if (*(u16 *)(((u8 *)D_841951F8[D_841951BC] + (u32)slot * 88) + 62) == 0 || ((u8 *)D_841951F8[D_841951BC] + (u32)slot * 88)[60] != 0) {
        func_84125424(13);
        return;
    }
    D_841951E0 = 1;
    D_841951CC = *(u16 *)(((u8 *)D_841951F8[D_841951BC] + (u32)slot * 88) + 66);
    D_841951CE = *(u16 *)(D_84195208[D_841951BD] + 52);
    D_841951D0 = ((u8 *)D_841951F8[D_841951BC] + (u32)slot * 88)[53];
    func_84136678(D_841951BC, -1);
    func_8004C54C(26, (s32)((u8 *)D_841951F8[D_841951BC] + (u32)slot * 88 + 76));
    func_84135B00(52);
    func_84134CBC(D_841951BC, 0);
    if (D_84195208[D_841951BC][15] & 0x4) {
        func_84135034((u8)(*(s32 *)(D_84195208[D_841951BC] + 76) - slot), (u8)(*(s32 *)(D_84195208[D_841951BC] + 76) - 1));
    } else {
        func_84135034(0, 1);
    }
    func_84134DD8(D_841951BF);
    func_8413523C(D_841951BC, slot);
    BattleRecord_AdvanceWriteSlot();
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC;
extern s32 D_841951C8;
extern u8 * D_84195208[];
void func_84130A74(void) {
    D_841951C8 *= D_84195208[D_841951BC][0x1D] + 1;
    if (D_841951C8 >= 0x10000) {
        D_841951C8 = 0xFFFF;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951D5;
extern u8 func_80063454(u8, u8, u8, s32);
void BattleAnim_Table_84186004_067(void) {
    u8 *temp_v0;

    temp_v0 = D_84195208[D_841951BD];
    if (func_80063454(D_841951C1,
                      *(u8 *)((u8 *)temp_v0 + 1),
                      *(u8 *)((u8 *)temp_v0 + 2),
                      ((*(u8 *)((u8 *)temp_v0 + 0xD) & 8) != 0)) == 0) {
        D_841951C8 = 0;
        D_841951D5 = 0;
        D_841951E5 = 0;
        D_841951D2 = 1;
    }
}
#endif

#ifdef VERSION_US
extern void func_84126FA0(u8);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BC;
extern u8 D_841951D2;
extern u8 D_841951D8;
void BattleAnim_Table_84186004_068(void) {
    s32 done = 0;
    s32 i;
    for (i = 0; i < 5; i = (i + 1) & 0xFF) {
        D_841951D2 = 0;
        func_84125CF8(D_841951BC, (u8)i, 1, 0);
        if (D_841951D8 == 0) done = 1;
    }
    if (done != 0) {
        func_84136678(D_841951BC, -1);
        func_84126FA0(7);
        func_84135B00(0x8F);
        func_84134CBC(D_841951BC, 0x4E);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern void func_84130EA8();
extern u8 D_841951D5;
extern u8 D_841951D2;
extern void func_84126BA8(u8);
void BattleAnim_Table_84186004_069(void) {
    if (D_841951D2 != 0) {
        if (D_841951D5 & 0x7F) {
            func_84126BA8(D_841951BC);
            return;
        }
        func_84136678(D_841951BC, -1);
        func_84135B00(0x66U);
        func_841246AC((s32) D_841951BD, D_841951BF);
        func_84136CA8();
        return;
    }
    func_84130EA8();
}
#endif

#ifdef VERSION_US
extern s32 D_841951E0;

void BattleAnim_Table_84186004_070(void) {
    if (D_841951E0 == 0) {
        func_84126BA8(D_841951BC);
    }
}
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_071(void) {
    if (D_841951D2 != 0) D_841951C8 = 0;
}
#endif

#ifdef VERSION_US
extern s32 func_84125080();
void BattleAnim_Table_84186004_072(void) {
    u8 val;

    func_8413005C();
    do {
        val = func_841251B0(func_84125080()) & 3;
    } while (val == 0);
    switch (val) {
    case 1:
        BattleCommand_020();
        break;
    case 2:
        BattleCommand_019();
        break;
    case 3:
        BattleCommand_018();
        break;
    }
}
#endif

#ifdef VERSION_US
extern void func_84128B30();
void BattleAnim_Table_84186004_073(void) {
    if (!((*(u8 *)((u8 *)(D_84195208[D_841951BC]) + (0xF))) & 4)) {
        func_84128B30();
    }
}
#endif

#ifdef VERSION_US
extern u8 D_841951BC; extern u8 *D_84195208[]; void BattleAnim_Table_84186004_074(void) { D_84195208[D_841951BC][0x12] = 0; }
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_075(void) { D_84195208[D_841951BC][0xE] |= 1; }
#endif

#ifdef VERSION_US
extern void func_84134E30(s32);
void func_84134DD8(u8 arg0);
void func_84136D40(u8 arg0);
void BattleAnim_Table_84186004_076(void) {
    if (D_841951D2 != 0) {
        func_84134E30(1);
    }
    if ((D_841951BF == 0xAD) && !((*(u8 *)((u8 *)(D_84195200[D_841951BC]) + (0x24))) & 7)) {
        func_84124594(D_841951BC);
    } else {
        func_84134CBC(D_841951BC, 0U);
    }
    func_84134DD8(D_841951BF);
    func_84136D40(0U);
    func_84136CA8();
}
#endif

#ifdef VERSION_US
void func_84124798(u8);
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

s32 func_800630C0(u8);                              /* extern */
M2C_UNK func_841562BC(u8, u8, M2C_UNK);             /* extern */

void func_84130EA8(void) {
    func_84124798(D_841951BD);
    func_841248DC(D_841951BD);
    func_84124954(D_841951BD);
    func_841249D8(D_841951BD);
    if (D_841951BF == 6) {
        func_84136678(D_841951BC, -1);
        func_84135B00(0x88U);
    }
    func_84124A7C();
    func_84136A9C(D_841951BD, -1, (s16) ((s16) D_841951E8 * -1), 2U);
    if ((s16) D_841951E8 == M2C_FIELD(D_84195200[D_841951BD], u16 *, 0x28)) {
        if (func_84127140(D_841951BD) != 0) {
            func_84136218(D_841951BD, 1U);
        } else if (func_84127140(D_841951BC) != 0) {
            func_84136218(D_841951BC, 2U);
        }
    }
    if ((s16) D_841951E8 > 0) {
        if (M2C_FIELD(D_841951F8[D_841951BC], u8 *, 0x49A) != 0) {
            if (func_800630C0(D_841951BF) != 0) {
                func_841562BC(D_841951BD, M2C_FIELD(D_841951F8[D_841951BD], u8 *, 0xA), 1);
            } else {
                func_841562BC(D_841951BD, M2C_FIELD(D_841951F8[D_841951BD], u8 *, 0xA), 4);
            }
        }
        if (M2C_FIELD(D_841951F8[D_841951BD], u8 *, 0x49A) != 0) {
            if (func_800630C0(D_841951BF) != 0) {
                func_841562BC(D_841951BC, M2C_FIELD(D_841951F8[D_841951BC], u8 *, 0xA), 0);
            } else {
                func_841562BC(D_841951BC, M2C_FIELD(D_841951F8[D_841951BC], u8 *, 0xA), 3);
            }
        }
    }
    func_84124604(D_841951BD, D_841951BF);
    func_84136D40(2U);
    func_84136CA8();
    func_84124A14(D_841951BD);
}
#endif

#ifdef VERSION_US
void func_84134DD8(u8 arg0);
void func_84135034(u8 arg0, u8 arg1);
void BattleAnim_Table_84186004_078(void) {
    s32 temp_v1;
    u8 *temp_v0;

    if ((*(u8 *)((u8 *)(D_84195208[D_841951BC]) + (0xF))) & 4) {
        func_84134CBC(D_841951BC, 0U);
        func_84134DD8(D_841951BF);
        temp_v0 = D_84195208[D_841951BC];
        temp_v1 = (*(s32 *)((u8 *)(temp_v0) + (0x4C)));
        func_84135034((temp_v1 - (*(u8 *)((u8 *)(temp_v0) + (0x12)))) & 0xFF, (temp_v1 - 1) & 0xFF);
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
void func_84124798(u8);
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

void func_84131174(void) {
    s32 temp_v1;
    u8 *var_v0;
    u8 var_a2;

    func_84136678(D_841951BD, -1);
    func_84124798(D_841951BD);
    var_v0 = D_84195208[D_841951BC];
    if (!(M2C_FIELD(var_v0, u8 *, 0xF) & 4)) {
        func_841248DC(D_841951BD);
        func_84135034(0U, 1U);
        func_84136D40(1U);
    } else {
        var_a2 = M2C_FIELD(var_v0, u8 *, 0x12);
        if (var_a2 == 1) {
            func_84136678(D_841951BD, -1);
            if (D_841951BF != 0xFB) {
                func_8004C594(1, M2C_FIELD(D_84195208[D_841951BC], s32 *, 0x4C));
                func_84135B00(0x9CU);
            }
            func_84124954(D_841951BD);
            var_v0 = D_84195208[D_841951BC];
            var_a2 = M2C_FIELD(var_v0, u8 *, 0x12);
        }
        temp_v1 = M2C_FIELD(var_v0, s32 *, 0x4C);
        func_84135034((temp_v1 - var_a2) & 0xFF, (temp_v1 - 1) & 0xFF);
    }
    func_841249D8(D_841951BD);
    func_84124A7C();
    func_84136A9C(D_841951BD, -1, (s16) ((s16) D_841951E8 * -1), 2U);
    func_84124604(D_841951BD, D_841951BF);
    func_84136CA8();
    func_84124A14(D_841951BD);
}
#endif

#ifdef VERSION_US
extern void func_84124798(u8);
extern void func_84124A7C(void);
extern void func_84124604(u8 arg0, u8 arg1);
extern void func_841248DC(u8 arg0);
extern void func_84124954(u8 arg0);
extern void func_841249D8(u8 arg0);
extern void func_84124A14(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 D_841951BD;
extern u8 D_841951BF;
extern u16 D_841951E8;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleAnim_Table_84186004_080(void) { func_84124798(D_841951BD); func_841248DC(D_841951BD); func_84124954(D_841951BD); func_841249D8(D_841951BD); if (D_84195208[D_841951BD][0x1B] == 0 || !(D_84195208[D_841951BD][0x10] & 0x10) || *(s16 *)&D_841951E8 < ((u16 *)D_84195200[D_841951BD])[0x13]) { func_84136678(D_841951BD, -1); switch (D_841951BF) { case 0x14: func_84135B00(0xA0); break; case 0x23: func_84135B00(0x72); break; case 0x53: func_84135B00(0xB7); break; case 0x80: func_84135B00(0x53); break; case 0xFA: func_84135B00(0xB7); break; } } func_84124A7C(); func_84136A9C(D_841951BD, -1, (s16)(-*(s16 *)&D_841951E8), 2); func_84124604(D_841951BD, D_841951BF); func_84136CA8(); func_84124A14(D_841951BD); }
#endif

#ifdef VERSION_US
void BattleAnim_Table_84186004_081(void) {
    u32 value;

    if (D_841951D8 == 0) {
        switch (D_841951BF) {
        case 14:
        case 96:
        case 97:
        case 104:
        case 106:
        case 107:
        case 110:
        case 111:
        case 112:
        case 133:
        case 151:
        case 159:
            BattleAnim_Table_84186004_046();
            break;
        default:
            func_841366C4(D_841951BC, -1);
            func_84134EC8(8);
            value = D_841951D9;
            if (value & 0xF0) {
                func_84126FA0(value & 0xF);
                func_84135B40(144);
            } else {
                func_84126FA0(value & 0xF);
                func_84135B40(143);
            }
            break;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84126FA0(u8);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136CA8(void);
extern u8 D_841951BD;
extern u8 D_841951D8;
extern u8 D_841951D9;
void BattleAnim_Table_84186004_082(void) {
    if (D_841951D8 == 0) {
        func_84134CBC(D_841951BD, 0x42);
        func_84136678(D_841951BD, -1);
        {
            int status = D_841951D9;
            u8 low = status & 0xF;
            if (status & 0xF0) {
                func_84126FA0(low);
                func_84135B00(0x8E);
            } else {
                func_84126FA0(low);
                func_84135B00(0x8D);
            }
        }
        func_84136CA8();
    }
}
#endif

#ifdef VERSION_US
extern void (*D_84185EB0[])(void);
extern u8 D_84195198[];
extern s32 D_841951B8;
void BattleCommand_RunSequence(void) {
    s32 command = D_84195198[0];
    D_841951B8 = 0;
    while (command < 254 && D_841951B8 < 27) {
        D_84185EB0[command]();
        D_841951B8++;
        command = D_84195198[D_841951B8];
    }
}
#endif

#ifdef VERSION_US
extern void func_84136D84(void);
void Battle_RunSideCommandSequence(u8 arg0) {
    if (((u8 *)D_841951F8[arg0])[16] == 0) {
        D_841951BC = arg0;
        D_841951BD = 1 - arg0;
        D_841951C5 = D_84195200[D_841951BC][1];
        D_841951C6 = D_84195200[D_841951BD][1];
        func_84124E44(D_841951BC);
        func_8004C54C(42, func_800635E0(D_84195200[D_841951BD][1]));
        D_841951D6 = 0;
        func_84136D84();
        BattleTurn_CheckMoveStatus();
        if (D_841951D6 == 0) {
            func_841266C4();
            BattleCommand_RunSequence();
        }
    }
}
#endif

#ifdef VERSION_US
extern void *func_8004C874(s32, s32);
extern s32 func_8004C54C(u8, s32);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136CA8(void);
extern u8 D_841951D2;
extern u8 D_841951D3;
extern u8 *D_84195200[];
extern u8 *D_84195208[];

void func_84131760(void) {
    s32 i;
    s32 ret;
    u8 t;

    for (i = 0; i != 2; i++) {
        if (D_84195200[i][1] == 152) {
            D_84195200[i][1] = 0;
            D_84195208[i][0xF] |= 0x80;
            ret = func_84125080();
            t = i;
            D_84195208[i][0x13] = (ret & 3) + 2;
            D_841951D2 = 0;
            D_841951D3 = 0;
            func_84125CF8(t & 0xFF, 0, 2, 0);
            func_84136678(t, -1);
            func_8004C54C(26, D_84195200[i] + 0x34);
            func_8004C54C(42, func_8004C874(8, 151));
            func_84135B00(151);
            func_8004C54C(28, D_84195200[i] + 0x34);
            func_84135B00(94);
            func_84134CBC(t, 65);
            func_84136CA8();
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_841318C0.s")
#endif

#ifdef VERSION_US
extern void func_841318C0(u8, u8);
extern void * D_841951F8[];
void func_84131AB8(u8 arg0) {
    func_841318C0(arg0, ((u8 *) D_841951F8[arg0])[0] - 4);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84131AF8.s")
#endif

#ifdef VERSION_US
extern s32 func_8412676C(u8, u8);
extern u32 func_84126804(u8, u16);
extern s32 func_8004C54C(u8, s32);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern void * D_841951F8[];
extern u8 * D_84195200[];
void func_84131EAC(u8 arg0) {
    u16 v0;
    s16 result;

    if (((u8 *) D_841951F8[arg0])[0xB] & 1) {
        if (func_84126390(arg0, 2) == 0) {
            func_8004C54C(0x1A, D_84195200[arg0] + 0x34);
            func_84136678(arg0, -1);
            func_84135B00(0x71);
            func_84134CBC(arg0, 0x46);
            v0 = func_8412676C(arg0, 3);
            result = -func_84126804(arg0, v0);
            func_84136A9C(arg0, -1, result, 1);
            func_84136CA8();
        }
    }
}
#endif

#ifdef VERSION_US
extern u8 D_8418545C[];
u8 BattleMove_GetCurrentPriority(u8 side) {
    u8 *table = D_8418545C;
    s32 effect = func_80062D20(((u8 *)D_841951F8[side])[1]);
    if (((u8 *)D_841951F8[side])[1] == 233) return 0;
    while (table[0] != 255) {
        if (effect == table[0]) return table[1];
        table += 2;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern u8 BattleMove_GetCurrentPriority(u8);
s32 func_8413202C(void) {
    u8 first;
    s32 second;

    first = BattleMove_GetCurrentPriority(0);
    second = BattleMove_GetCurrentPriority(1);
    if (second == first) {
        return 0;
    }
    if (second < (s32)first) {
        return 1;
    }
    return 2;
}
#endif

#ifdef VERSION_US
extern u8 *D_84195208[];
s32 func_8413207C(void) {
    u16 y = *(u16 *)(D_84195208[0] + 0x40);
    u16 x = *(u16 *)(D_84195208[1] + 0x40);
    if (y == x) {
        if (func_84125080() < 0x80) {
            return 1;
        }
        return 2;
    }
    if (x < y) {
        return 1;
    }
    return 2;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_841320E8.s")
#endif

#ifdef VERSION_US
extern void func_84133C10(s32);
extern void *D_84195204;
void func_84132300(void) {
    if ((*(u16 *)((u8 *)(*D_84195200) + (0x26))) == 0) {
        func_84133C10(1);
    }
    if ((*(u16 *)((u8 *)(D_84195204) + (0x26))) == 0) {
        func_84133C10(0);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84132350.s")
#endif

#ifdef VERSION_US
extern s32 func_8412676C(u8, u8);
extern u32 func_84126804(u8, u16);
extern s32 func_8004C54C(u8, s32);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern void * D_841951F0;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_841324EC(void) {
    s32 i;
    if (((u8 *)D_841951F0)[0x9C4]) {
        ((u8 *)D_841951F0)[0x9C5] = (u8)(((u8 *)D_841951F0)[0x9C5] - 1);
        if (((u8 *)D_841951F0)[0x9C5] > 0) {
            func_84136678(0, -1);
            switch (((u8 *)D_841951F0)[0x9C4]) {
            case 1: func_84135B00(0x22); func_84134CBC(0, 0x32); break;
            case 2: func_84135B00(0x3B); func_84134CBC(0, 0x31); break;
            case 3: func_84135B00(0xB1); func_84134CBC(0, 0x30); break;
            }
            func_84136CA8();
            if (((u8 *)D_841951F0)[0x9C4] == 3) {
                for (i = 0; i < 2; ++i) {
                    if (!(D_84195208[i][0xF] & 0x20) && func_84126390((u8)i, 5) == 0 && func_84126390((u8)i, 4) == 0 && func_84126390((u8)i, 9) == 0) {
                        func_84136A9C((u8)i, -1, (s16)(-func_84126804((u8)i, func_8412676C((u8)i, 3))), 1);
                        func_84136678((u8)i, -1);
                        func_8004C54C(0x1A, D_84195200[i] + 0x34);
                        func_84135B00(0xB3); func_84134CBC((u8)i, 0x48); func_84136CA8();
                    }
                }
            }
        } else {
            func_84136678(0, -1);
            switch (((u8 *)D_841951F0)[0x9C4]) {
            case 1: func_84135B00(0x21); func_84134CBC(0, 0x35); break;
            case 2: func_84135B00(0x3A); func_84134CBC(0, 0x34); break;
            case 3: func_84135B00(0xB0); func_84134CBC(0, 0x33); break;
            }
            func_84136CA8(); ((u8 *)D_841951F0)[0x9C4] = 0;
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84132778.s")
#endif

#ifdef VERSION_US
extern void func_8004C594(s32, s32);
extern s32 func_8004C54C(u8, s32);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84136CA8(void);
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_8413293C(void) {
    s32 i;
    u8 id;

    for (i = 0; i != 2; i++) {
        id = i;
        if (D_84195208[i][0xD] & 0x10) {
            func_84136678(id, -1);
            func_8004C54C(0x1A, (s32)(D_84195200[i] + 0x34));
            D_84195208[i][0x17]--;
            if (D_84195208[i][0x17] == 0) {
                D_84195208[i][0xD] &= ~0x10;
                func_8004C594(1, D_84195208[i][0x17]);
                func_84135B00(0x28);
                func_84136A9C(id, -1, -*(u16 *)(D_84195200[i] + 0x26), 1);
                *(u16 *)(D_84195200[i] + 0x26) = 0;
                func_84134CBC(id, 0x57);
            } else {
                func_8004C594(1, D_84195208[i][0x17]);
                func_84135B00(0x28);
                func_84134CBC(id, 0x49);
            }
            func_84136CA8();
        }
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_84132A94 begin */
extern u8 func_80063660(u8);
extern s32 func_841267B4(u8, u8);
extern u16 func_84126850(u8, u16);
extern void func_84136A9C(u8, s16, s16, u8);
extern void func_84136678(u8, s16);
extern s32 func_8004C54C(u8, s32);
extern s32 *func_800635E0(u8);
extern void func_84135B00(u16);
extern void func_84134CBC(u8, u8);
extern void func_84136CA8(void);
extern u8 *D_84195200[];

void func_84132A94(void) {
    s32 i;
    u8 player;
    s32 kind;

    kind = 3;
    for (i = 0; i < 2; i++) {
        s32 result;

        result = func_80063660(D_84195200[i][1]);
        if (kind != result) {
            continue;
        }
        player = i;
        if (*(u16 *)(D_84195200[i] + 0x26) == *(u16 *)(D_84195200[i] + 0x28)) {
            continue;
        }
        func_84136A9C(player, -1, (s16)func_84126850(player, (u16)func_841267B4(player, 4)), 1);
        func_84136678(player, -1);
        func_8004C54C(0x1C, (s32)(D_84195200[i] + 0x34));
        func_8004C54C(0x2A, func_800635E0(D_84195200[i][1]));
        func_84135B00(0x40);
        func_84134CBC(player, 0x4A);
        func_84136CA8();
    }
}
/* mkdraft:func_84132A94 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84132B9C.s")
#endif

#ifdef VERSION_US
extern s32 func_8004C54C(u8, s32);
extern s32 func_84125080();
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern void func_84136678(u8, s16);
extern void func_84136B9C(u8 arg0, s16 arg1, u16 arg2);
extern void func_84136CA8(void);
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_84132D44(void) {
    s32 count;
    s32 offset = 0;
    for (count = 0; count != 2; count++) {
        if ((D_84195200[count][0x24] & 0x20) != 0) {
            if (D_84195208[count][0x28] == 0) {
                if (func_84125080() < 0x19) {
                    func_84136678(count, -1);
                    func_8004C54C(0x1C, D_84195200[count] + 0x34);
                    func_84136B9C(count, -1, 0);
                    func_84135B00(0x77);
                    func_84134CBC(count, 0x2C);
                    func_84136CA8();
                    D_84195200[count][0x24] = 0;
                }
            }
        }
        offset += 4;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8004C54C(u8, s32);
extern void func_84124594(u8 arg0);
extern void func_84135B00(u16);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136CA8(void);
extern void * D_841951F8[];
extern u8 * D_84195200[];
void func_84132E40(void) {
    s32 i;

    for (i = 0; i != 2; i++) {
        if (((u8 *)D_841951F8[i])[0xB] & 4) {
            ((u8 *)D_841951F8[i])[0xC]--;
            if (((u8 *)D_841951F8[i])[0xC] == 0) {
                ((u8 *)D_841951F8[i])[0xB] &= ~4;
                func_84136678(i, -1);
                func_8004C54C(0x1A, (s32)(D_84195200[i] + 0x34));
                func_84135B00(0x59);
                func_84124594(i);
                func_84136CA8();
            }
        }
    }
}
#endif

#ifdef VERSION_US
void func_84132F34(void) {
    s32 i;
    u8 **record;

    for (i = 0; i < 2; i++) {
        record = &D_841951F8[i];
        if ((*record)[0xB] & 8) {
            (*record)[0xD]--;
            if ((*record)[0xD] == 0) {
                (*record)[0xB] &= ~8;
                func_84136678(i, -1);
                func_8004C54C(26, D_84195200[i] + 0x34);
                func_84135B00(74);
                func_84124594(i);
                BattleRecord_AdvanceWriteSlot();
            }
        }
        if ((*record)[0xB] & 0x10) {
            (*record)[0xE]--;
            if ((*record)[0xE] == 0) {
                (*record)[0xB] &= ~0x10;
                func_84136678(i, -1);
                func_8004C54C(26, D_84195200[i] + 0x34);
                func_84135B00(155);
                func_84124594(i);
                BattleRecord_AdvanceWriteSlot();
            }
        }
    }
}
#endif

void func_841330B4(void) {
}

#ifdef VERSION_US
extern s32 func_84125778(u8);
void Battle_ProcessLowHpHeldItems(void) {
    s32 i;
    u8 side;
    u8 **entry;
    entry = D_84195200;
    i = 0;
    do {
        func_8004C54C(28, (s32)((*entry) + 52));
        func_8004C54C(42, (s32)func_800635E0((*entry)[1]));
        if (func_80063660((*entry)[1]) == 1) {
            if (*(u16 *)((*entry) + 38) < (*(u16 *)((*entry) + 40) >> 1)) {
                side = i;
                func_84136A9C(side, -1, (s16)func_84126850(side, (u16)func_80063690((*entry)[1])), 1);
                func_84136678(side, -1);
                func_84135B00(72);
                func_84134CBC(side, 74);
                BattleRecord_AdvanceWriteSlot();
                if (func_8412517C((*entry)[1])) {
                    (*entry)[1] = 0;
                }
            }
        }
        side = i;
        func_84125778(side);
        func_841259D4(side);
        i++;
        entry++;
    } while (i < 2);
}
#endif

#ifdef VERSION_US
// Same code as func_84132E40 on D_84195208's records, with flag 0x10 at 0x11 and its
// counter at 0x16; GS also ends the effect early when the low six bits of the byte at
// 9 + record[4] are clear, and passes 0x1C to func_8004C54C and 0x31 to func_84135B00.
void func_841331F8(void) {
    s32 i;

    for (i = 0; i != 2; i++) {
        if (D_84195208[i][0x11] & 0x10) {
            D_84195208[i][0x16]--;
            // FAKE: adding the index before the record pointer orders the addu operands like
            // the original; diff score 10 without it.
            if (D_84195208[i][0x16] == 0 || !((D_84195208[i][4] + D_84195208[i])[9] & 0x3F)) {
                D_84195208[i][0x11] &= ~0x10;
                func_84136678(i, -1);
                func_8004C54C(0x1C, (s32)(D_84195200[i] + 0x34));
                func_84135B00(0x31);
                func_84124594(i);
                func_84136CA8();
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_84124E44(u8);
extern s32 func_841270D8(u8, u8);
extern void Battle_RunSideCommandSequence(u8);
extern u8 func_80062D20(u8);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_84135B00(u16);
extern s32 func_841360C0(u8 arg0, s16 arg1, u16 arg2, u8 arg3, u8 arg4);
extern void func_84136678(u8 arg0, s16 arg1);
extern void func_84136CA8(void);
extern void * D_841951F8[];
extern u8 * D_84195200[];
s32 func_84133304(u8 arg0) {
    u8 other = 1 - arg0;

    if (*(u16 *)(D_84195200[arg0] + 0x26) == 0) {
        return 1;
    }
    if (func_80062D20(((u8 *)D_841951F8[other])[1]) == 0x80) {
        Battle_RunSideCommandSequence(other);
        ((u8 *)D_841951F8[other])[1] = 0;
        if (*(u16 *)(D_84195200[arg0] + 0x26) == 0) {
            func_841270D8(arg0, ((u8 *)D_841951F8[arg0])[0xA]);
            func_84124E44(other);
            func_841360C0(other, -1, 0x3C, 2, 0);
            func_84124E44(arg0);
            func_84136678(arg0, -1);
            func_84135B00(0x6F);
            func_84134CBC(arg0, 0x1C);
            func_84136CA8();
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_84132300(void);
extern void func_84132350(void);
extern void func_841324EC(void);
extern void func_84132778(void);
extern void func_8413293C(void);
extern void func_84132A94(void);
extern void func_84132B9C(void);
extern void func_84132D44(void);
extern void func_84132E40(void);
extern void func_84132F34(void);
extern void Battle_ProcessLowHpHeldItems(void);
extern void func_841331F8(void);
void func_84133440(void) {
    func_84132300();
    func_84132350();
    func_84132300();
    func_841324EC();
    func_84132300();
    func_84132778();
    func_84132300();
    func_8413293C();
    func_84132300();
    func_84132A94();
    func_84132B9C();
    func_84132D44();
    func_84132E40();
    func_84132F34();
    Battle_ProcessLowHpHeldItems();
    func_841331F8();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_841334D8.s")
#endif

#ifdef VERSION_US
extern void func_84135C78(u8 arg0, s16 arg1, u16 arg2, u16 arg3);
void Battle_QueueSwitchInHpMessage(u8 arg0, s32 arg1, s32 arg2) {
    s32 ratio;
    u16 animation;
    u16 message;

    func_84136678(arg0, -1);
    func_8004C54C(25, func_8004B7A4(D_84195208[arg0][0]));
    func_8004C54C(26, (s32)(D_84195200[arg0] + 52));
    if (((u8 *)D_841951F0)[2503]) {
        animation = 3;
        message = 22;
        func_84134CBC(arg0, 34);
    } else {
        *(u16 *)(D_84195208[1 - arg0] + 72) = *(u16 *)(D_84195200[1 - arg0] + 38);
        if (*(u16 *)(D_84195208[arg0] + 72) == 0) {
            *(u16 *)(D_84195208[arg0] + 72) = *(u16 *)(D_84195200[arg0] + 38);
        }
        ratio = (*(u16 *)((*(u8 **)((u8 *)&D_84195204 + -(arg0 << 2))) + 38)) * 25 / (*(u16 *)((*(u8 **)((u8 *)&D_84195204 + -(arg0 << 2))) + 40) >> 2);
        if (ratio >= 70 || (*(u16 *)((*(u8 **)((u8 *)&D_84195204 + -(arg0 << 2))) + 38)) == 0) {
            animation = 4;
            message = 22;
        } else if (ratio >= 40) {
            animation = 5;
            message = 18;
        } else if (ratio >= 10) {
            animation = 6;
            message = 16;
        } else {
            animation = 7;
            message = 39;
        }
        func_84124CC4(arg0, arg1, arg2);
    }
    func_84135B00(message);
    if (func_84127140(arg0)) {
        func_84135C78(arg0, -1, 60, animation);
    }
    BattleRecord_AdvanceWriteSlot();
}
#endif

#ifdef VERSION_US
extern u8 *D_8419520C[];
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_84133924(u8 arg0) {
    s32 offset;
    offset = arg0 << 2;
    offset = -offset;
    D_84195208[arg0][0x26] = 0;
    (*(u8 **)((u8 *)D_8419520C + offset))[0x26] = 0;
    (*(u8 **)((u8 *)D_8419520C + offset))[0x27] = 0;
    D_84195208[arg0][0x1B] = 0;
    ((u8 *)D_841951F8[arg0])[1] = 0;
}
#endif

#ifdef VERSION_US
extern void func_8412693C(u8);
extern void func_84126994(u8);
extern void func_841318C0(u8, u8);
extern void func_84133924(u8);
void func_84133984(u8 arg0, u8 arg1) {
    func_84133924(arg0);
    func_841318C0(arg0, arg1);
    func_84126994(arg0);
    func_8412693C(arg0);
    func_84126A64();
}
#endif

#ifdef VERSION_US
extern void Battle_QueueSwitchInHpMessage(u8, s32, s32);
extern void func_841252D0(u8);
extern void func_8412693C(u8 side);
extern void func_84126994(u8 side);
extern void func_84126A64(void);
extern void func_84131AB8(u8 side);
extern void func_84131EAC(u8 side);
extern u8 D_841951D5;
extern void * D_841951F8[];
extern u8 * D_84195200[];
extern u8 * D_84195208[];
extern u8 * D_8419520C[];
void Battle_RefreshSideAfterSwitch(u8 side) {
    s32 fainted;
    D_84195208[side][16] &= ~0x40;
    fainted = 0;
    if (*(u16 *)(D_84195200[side] + 38) == 0) fainted = 1;
    func_84131AB8(side);
    func_8412693C(side);
    Battle_QueueSwitchInHpMessage(side, fainted, 0);
    func_84126994(side);
    func_84126A64();
    ((u8 *)D_841951F8[side])[1] = 0;
    D_84195208[side][38] = 0;
    (*(u8 **)((u8 *)D_8419520C + -(side << 2)))[38] = 0;
    D_84195208[side][39] = 0;
    D_841951D5 = 0;
    func_841252D0(0);
    func_84131EAC(side);
}
#endif

#ifdef VERSION_US
void func_84133ACC(u8 arg0) {
    ((u8 *) D_841951F8[arg0])[0x10] = 1;
    func_841334D8(arg0);
    Battle_RefreshSideAfterSwitch(arg0);
}
#endif

#ifdef VERSION_US
extern void func_84137DB8(void);
extern void func_841383B4(u8, u8, u8);
extern void func_84131AB8(u8);
extern void func_84125734(u8);
extern void Battle_QueueSwitchInHpMessage(u8, s32, s32);
extern void func_84131EAC(u8);
extern u8 *D_84195200[];
extern void *D_841951F8[];
extern u8 *D_84195208[];
extern u8 *D_8419520C[];
extern u8 D_841951D5;
void Battle_ApplySwitchInState(u8 arg0) {
    s32 fainted;
    fainted = 0;
    func_84137DB8();
    if (arg0) func_841383B4(12, 5, 1);
    else func_841383B4(5, 12, 1);
    if (*(u16 *)(D_84195200[arg0] + 38) == 0) fainted = 1;
    func_84131AB8(arg0);
    func_84125734(arg0);
    Battle_QueueSwitchInHpMessage(arg0, fainted, 1);
    ((u8 *)D_841951F8[arg0])[1] = 0;
    D_84195208[arg0][38] = 0;
    (*(u8 **)((u8 *)D_8419520C + -(arg0 << 2)))[38] = 0;
    D_84195208[arg0][39] = 0;
    D_841951D5 = 0;
    func_84131EAC(arg0);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84133C10.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_393CA0/func_84133F10.s")
#endif

#ifdef VERSION_US
extern u8 * D_84195208[];
s32 func_84134018(u8 arg0) {
    if (D_84195208[arg0][0x10] & 0x20) return 0;
    D_84195208[arg0][0xF] &= 0xFFF7;
    if (D_84195208[arg0][0xF] & 0x12) return 0;
    if (D_84195208[arg0][0xD] & 0x40) return 0;
    return 1;
}
#endif

#ifdef VERSION_US
extern s32 func_84134018(u8 arg0);
extern void * D_841951F8[];
extern u8 * D_84195208[];
u8 func_84134098(u8 arg0) { u8 result; u16 index; result = 1; index = arg0 * 4; ((u8 *)D_841951F8[arg0])[0] = 0xFF; if (func_84134018(arg0)) { if (D_84195208[arg0][0xF] & 1) { D_84195208[arg0][0x18] = 0; D_84195208[arg0][0x19] = 0; D_84195208[arg0][0x1D] = 0; D_84195208[arg0][0x10] &= 0xFFBF; } } else { result = 0xC; D_84195208[arg0][0x18] = 0; D_84195208[arg0][0x19] = 0; D_84195208[arg0][0x1D] = 0; D_84195208[arg0][0x10] &= 0xFFBF; } return result; }
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
void func_84134170(u8 arg0) {
    u8 **ptr = (u8 **)&D_841951F8[arg0];
    (*ptr)[0] = 0xFF;
    (*ptr)[1] = 0;
    (*ptr)[6] = 0;
    (*ptr)[0xB] = 0;
    (*ptr)[0xC] = 0;
    (*ptr)[0xD] = 0;
    (*ptr)[0xE] = 0;
    (*ptr)[0xF] = 0;
    (*ptr)[0x10] = 0;
}
#endif

#ifdef VERSION_US
extern s32 func_8006A48C(void);
extern void * D_841951F8[];
void func_841341D8(void) {
    s32 i; s32 flag;
    for (i = 0; i < 2; i++) {
        flag = ((u8 *)D_841951F8[i])[2] == 2;
        if (flag != 0) flag = func_8006A48C() != 5;
        ((u8 *)D_841951F8[i])[0x12] = flag;
    }
}
#endif

#ifdef VERSION_US
void func_8413425C(void) {
    u8 i;

    func_84124F40(**(void ***)((u8 *)D_841951F0 + 0x9D8));
    func_841341D8();
    ((u8 *)D_841951F0)[0x9C7] = 1;
    ((u8 *)D_841951F0)[0x9C4] = 0;
    ((u8 *)D_841951F0)[0x9C5] = 0;
    ((u8 *)D_841951F0)[0x9C6] = 0;
    // Mark every slot of the 12-byte table filled by func_841270D8 as empty (0xFF).
    HAL_Memset((u8 *)D_841951F0 + 0x9C8, 0xFF, 12);
    for (i = 0; i < 2; i++) {
        func_84134170(i);
        func_84126994(i);
        D_84195208[i][0x12] = 0;
        D_84195208[i][0x13] = 0;
        D_84195208[i][0x14] = 0;
        D_84195208[i][0x15] = 0;
        D_84195208[i][0x16] = 0;
        D_84195208[i][0x17] = 0;
        D_84195208[i][0x18] = 0;
        D_84195208[i][0x19] = 0;
        D_84195208[i][0x1A] = 0;
        *(u16 *)(D_84195208[i] + 0x48) = *(u16 *)(D_84195200[i] + 0x26);
        func_8412693C(i);
    }
    if (((u8 *)D_841951F0)[0x9C3] == 0) {
        func_84136A9C(0, -1, ((u8 *)D_841951F8[0])[0xA], 4);
        Battle_QueueSwitchInHpMessage(0, 0, 0);
        func_84136A9C(1, -1, ((u8 *)D_841951F8[1])[0xA], 4);
        Battle_QueueSwitchInHpMessage(1, 0, 0);
    }
    func_84126A64();
}
#endif

#ifdef VERSION_US
extern s32 func_841320E8(void);
extern s32 func_84133F10(u8);
extern void *D_841951FC[];
void func_841343FC(void) {
    u8 side;
    s32 result;

    switch (func_841320E8()) {
    case 1:
        func_84134CBC(0, 91);
        func_84136A9C(0, 5, 0, 6);
        D_841951BE = 0;
        result = func_84133F10(0);
        func_84137DB8();
        ((u8 *)D_841951F8[0])[6]++;
        if (result == 0) {
            func_84124BA0(1);
            func_84136A9C(1, 5, 0, 6);
            func_84133F10(1);
            func_84137DB8();
            ((u8 *)D_841951FC[0])[6]++;
        }
        break;
    case 2:
        func_84134CBC(1, 91);
        func_84136A9C(1, 5, 0, 6);
        D_841951BE = 1;
        result = func_84133F10(1);
        func_84137DB8();
        ((u8 *)D_841951F8[0])[6]++;
        if (result == 0) {
            func_84124BA0(0);
            func_84136A9C(0, 5, 0, 6);
            func_84133F10(0);
            func_84137DB8();
            ((u8 *)D_841951FC[0])[6]++;
        }
        break;
    case 3:
        func_84134CBC(0, 91);
        func_84136A9C(0, 5, 0, 6);
        D_841951BE = 0;
        func_84133ACC(0);
        result = func_84133F10(0);
        func_84137DB8();
        ((u8 *)D_841951F8[0])[6]++;
        if (result == 0) {
            func_84124BA0(1);
            func_84136A9C(1, 5, 0, 6);
            func_84133F10(1);
            func_84137DB8();
            ((u8 *)D_841951FC[0])[6]++;
        }
        break;
    case 4:
        func_84134CBC(1, 91);
        func_84136A9C(1, 5, 0, 6);
        D_841951BE = 1;
        func_84133ACC(1);
        result = func_84133F10(1);
        func_84137DB8();
        ((u8 *)D_841951FC[0])[6]++;
        if (result == 0) {
            func_84124BA0(0);
            func_84136A9C(0, 5, 0, 6);
            func_84133F10(0);
            func_84137DB8();
            ((u8 *)D_841951F8[0])[6]++;
        }
        break;
    case 5:
        side = func_84125080() & 1;
        func_84134CBC(side, 91);
        func_84136A9C(side, 5, 0, 6);
        func_84133ACC(side);
        func_84137DB8();
        ((u8 *)D_841951F8[side])[6]++;
        func_84124BA0(1 - side);
        func_84136A9C(1 - side, 5, 0, 6);
        func_84133ACC(1 - side);
        func_84133F10(1 - side);
        func_84137DB8();
        ((u8 *)D_841951F8[1 - side])[6]++;
        func_84133F10(side);
        func_84137DB8();
        break;
    }
}
#endif
