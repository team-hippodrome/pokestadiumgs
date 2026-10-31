#include "global.h"


#ifdef VERSION_US
// Not referenced by code or data (debug format strings); they open this file's .rodata.
const char D_8418B780[] = "maxHitWaza = %11s\n";
const char D_8418B794[] = "now %11s atk %d dmg %d aph %d dph %d\n";
const char D_8418B7BC[] = "candidate %11s atk %d dmg %d maph %d mdph %d val %d\n";
const char D_8418B7F4[] = "change to %11s %3d\n";
extern void func_84149400(void);
extern void func_8414C18C(void);
extern void func_8414BEB0(void);
extern void func_84156814(void);
extern void func_8414C4AC(void);
void func_84148610(void) {
    func_84149400();
    func_8414C18C();
    func_8414BEB0();
    func_84156814();
    func_8414C4AC();
}

extern void func_84155A1C(void);
extern void func_84154948(u8);
extern void func_84148610(void);
void func_84148650(u8 arg0) {
    func_84155A1C();
    func_84154948(arg0);
    func_84148610();
}

extern void func_84154AD4(void);
extern void func_84156510(void);
extern void func_8414BEE8(void);
void func_84148680(void) {
    func_84154AD4();
    func_84156510();
    func_8414BEE8();
}

extern u8 *func_84154B30(u8);
extern s32 func_84156618(u8, u8, u8);
extern s32 func_800630C0(u8);
extern u8 func_84149424(void);

s32 func_841486B0(u8 arg0, u8 arg1) {
    s32 v1;
    s32 p;
    s32 q;
    s32 x;

    p = func_84156618(arg0, func_84154B30(arg0)[1], 0x4);
    q = func_84156618(arg0, func_84154B30(arg0)[1], 0x8);
    x = func_800630C0(arg1);

    if (p != 0 && q != 0) {
        if (func_84149424() & 1) {
            v1 = x;
        } else {
            v1 = x == 0;
        }
    } else if (p != 0) {
        v1 = x && (func_84149424() & 1);
    } else if (q != 0) {
        v1 = (x == 0) && (func_84149424() & 1);
    } else {
        v1 = 0;
    }
    return v1;
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B7EA0/func_841487A8.s")

extern u8 *func_84154B64(u8);
extern void func_841487A8(u8 *);
extern s32 func_800643CC(s32, s32, s32);
void func_84148A4C(u8 *arg0) {
    s32 i;
    u8 *value;

    value = func_84154B64(arg0[0]);
    i = 1;
    do {
        arg0[1] = (u8)i;
        if (func_800643CC(value[0], i & 0xFF, value[0xC]) != 0) {
            func_841487A8(arg0);
        }
        i += 1;
    } while (i != 0xFC);
}

extern u8 *D_84195208[];
extern void func_841487A8(u8 *);
void func_84148AC8(u8 *arg0) {
    s32 i;

    for (i = 0; i != 4; i++) {
        arg0[1] = D_84195208[arg0[0]][i + 5];
        func_841487A8(arg0);
    }
}

extern u8 *func_841565E0(s32);
extern void func_841487A8(u8 *);
void func_84148B40(u8 *arg0) {
    s32 i = 0;
    while (i != 4) {
        u8 *value = func_841565E0(arg0[0]);
        arg0[1] = *(value + i + 1);
        if (arg0[1] > 0 && arg0[1] < 0xFC) {
            func_841487A8(arg0);
        }
        i += 1;
    }
}

extern u8 *func_84154B0C(void);
extern u8 *D_841951F8[];
u8 func_84148BB4(u8 arg0) {
    u8 index;
    s32 result;
    u8 *entry;
    u8 *ptr;
    entry = func_84154B0C() + arg0 * 0xCC;
    index = arg0;
    ptr = entry + 8;
    if (entry[0x21] & 0x10) {
        return ptr[0x25];
    }
    result = ptr[0x17];
    if (result & 1) {
        return 0x75;
    }
    if (ptr[0x18] & 0x20) {
        return 0;
    }
    if ((result & 0x12) || (ptr[0x15] & 0x20)) {
        return D_841951F8[index][1];
    }
    return 0xFF;
}

/* mkdraft:func_84148C74 begin */
extern void _bzero(void *, s32);
extern u8 func_84155D5C(u8 arg0, u8 arg1, u8 arg2);


s32 func_84148C74(u8 arg0) {
    u8 value;
    // Candidate-search record shared with func_841487A8 and the candidate
    // enumerators above: bytes[0] is the current species and bytes[1] the
    // candidate being tried; func_841487A8 records its selections in
    // bytes[2] and bytes[3], with comparison values in bytes[4] and
    // bytes[6] (u16).
    u8 record[8];

    value = func_84148BB4(arg0);
    if (value != 0xFF) {
        return value;
    }

    _bzero(record, 8);
    record[0] = arg0;
    value = func_84155D5C(
        arg0,
        func_84154B30(arg0)[1],
        func_84154B30((1 - (u32)arg0) & 0xFF)[1]
    );
    record[1] = value;
    if (value != 0) {
        func_841487A8(record);
        func_84148B40(record);
        return record[3];
    }
    if (func_84156618(arg0, func_84154B30(arg0)[1], 2) != 0) {
        func_84148AC8(record);
        return record[3];
    }
    func_84148A4C(record);
    return record[3];
}
/* mkdraft:func_84148C74 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B7EA0/func_84148D54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B7EA0/func_84149294.s")

extern u8 D_8419D7B0[];
extern u8 D_8419D7B1;
extern u8 D_8419D7B2;
extern u8 D_84187030;
extern u16 D_84187038;
u8 *func_841493DC(void) {
    return D_8419D7B0;
}

u8 func_841493E8(void) {
    return D_8419D7B0[0];
}

u8 func_841493F4(void) { return D_8419D7B1; }

extern u32 func_8003570C(void);
void func_84149400(void) {
    D_8419D7B2 = func_8003570C();
}

u8 func_84149424(void) { return D_8419D7B2; }

typedef struct Fragment79DamageContext { u8 unk_00, unk_01; u8 effect, power, type, level; u8 unk_06, unk_07; u16 attack, defense; s32 damage; u8 *attacker, *defender; u8 *unk_18; u8 *unk_1C; } Fragment79DamageContext;

// Loads the attack and defense stats for the damage formula: types below 20 use the
// Attack/Defense words at attacker + 0x36 and defender + 0x38, the others the Special
// words at + 0x3C and + 0x3E. Doubles defense when the matching flag in unk_1C[3] is set,
// and applies the held-item doublers checked by species/item byte pairs: Cubone (104) or
// Marowak (105) with Thick Club (118), Pikachu (25) with Light Ball (163), and Ditto (132)
// with Metal Powder (35), which raises defense by half.
void func_84149430(Fragment79DamageContext *arg0) {
    if (arg0->power != 0) {
        if (arg0->type < 20) {
            arg0->attack = *(u16 *)(arg0->attacker + 0x36);
            arg0->defense = *(u16 *)(arg0->defender + 0x38);
            if (arg0->unk_1C[3] & 0x10) {
                arg0->defense <<= 1;
            }
            if (arg0->attacker[1] == 118 && (arg0->attacker[0] == 104 || arg0->attacker[0] == 105)) {
                arg0->attack <<= 1;
            }
        } else {
            arg0->attack = *(u16 *)(arg0->attacker + 0x3C);
            arg0->defense = *(u16 *)(arg0->defender + 0x3E);
            if (arg0->unk_1C[3] & 8) {
                arg0->defense <<= 1;
            }
            if (arg0->attacker[1] == 163 && arg0->attacker[0] == 25) {
                arg0->attack <<= 1;
            }
        }
        if (arg0->defender[1] == 35 && arg0->defender[0] == 132) {
            arg0->defense += arg0->defense >> 1;
        }
        arg0->level = arg0->attacker[0xC];
    }
}

/* mkdraft:MoveDamage_ComputeBase_fragment79 begin */
extern s32 func_800636C0(u8, u8);
extern u8 func_80063690(u8);

void MoveDamage_ComputeBase_fragment79(void *arg0) {
    Fragment79DamageContext *ctx = arg0;
    if (ctx->power != 0) {
        if (ctx->effect == 7) {
            ctx->defense >>= 1;
        }
        if (ctx->defense == 0) {
            ctx->defense++;
        }
        ctx->damage = (((ctx->level * 2 / 5 + 2) * ctx->power * ctx->attack) / ctx->defense) / 50;
        if (func_800636C0(ctx->attacker[1], ctx->type)) {
            ctx->damage *= func_80063690(ctx->attacker[1]) + 100;
            ctx->damage /= 100;
        }
        if (ctx->damage >= 999) {
            ctx->damage = 996;
        }
        ctx->damage += 2;
    }
}
/* mkdraft:MoveDamage_ComputeBase_fragment79 end */

extern void func_84124360(s32 *, u8, u8);
extern s32 func_800632CC(s32 *, u8, u8, u8, s32);
void func_841496C0(u8 *arg0) {
    Fragment79DamageContext *ctx = (Fragment79DamageContext *)arg0;

    if (ctx->unk_01 == 0xA5) {
        return;
    }
    if (ctx->type == ctx->attacker[2] || ctx->type == ctx->attacker[3]) {
        ctx->damage += ctx->damage >> 1;
    }
    func_84124360(&ctx->damage, ctx->unk_06, ctx->type);
    if (ctx->effect == 0x97 && ctx->unk_06 == 1) {
        ctx->damage >>= 1;
    }
    func_800632CC(&ctx->damage, ctx->type, ctx->defender[2], ctx->defender[3], (ctx->defender[0x15] & 8) != 0);
}

extern u8 func_80063454(u8, u8, u8, s32);
void func_8414978C(u8 *arg0) {
    u8 *ptr;
    if (arg0[1] == 0xA5) {
        return;
    }
    ptr = arg0;
    if (func_80063454(ptr[4], (*(u8 **)(ptr + 0x14))[2], (*(u8 **)(ptr + 0x14))[3],
                       ((*(u8 **)(ptr + 0x14))[0x15] & 8) != 0) == 0) {
        *(s32 *)(ptr + 0xC) = 0;
    }
}

void func_841497E8(void *arg0) {
    u8 *state = arg0;

    switch (state[2]) {
        case 99:
            state[3] = Audio_LookupScaledRatio_fragment79(*(u16 *)(*(u8 **)(state + 0x10) + 0x28),
                                                          *(u16 *)(*(u8 **)(state + 0x10) + 0x2A));
            func_84149430(state);
            break;
        case 121:
            func_84149430(state);
            state[3] = (*(u8 **)(state + 0x10))[0x14] * 10 / 25;
            break;
        case 122:
            func_84149430(state);
            state[3] = 52;
            break;
        case 123:
            func_84149430(state);
            state[3] = (-(*(u8 **)(state + 0x10))[0x14] * 10 + 2550) / 25;
            break;
        case 126:
            func_84149430(state);
            state[3] = 64;
            break;
        case 135:
            state[4] = func_84126EDC(*(u16 *)(*(u8 **)(state + 0x10) + 0x40));
            state[3] = func_84126E88(*(u16 *)(*(u8 **)(state + 0x10) + 0x40));
            func_84149430(state);
            break;
        default:
            func_84149430(state);
            break;
    }
}

typedef struct unk_D_841951F0_9D4 {
    u8 unk_00[0x40];
    u32 unk_40_31 : 4;
    u32 unk_40_27 : 1; // Gates effect 41 in func_84149928.
} unk_D_841951F0_9D4;

extern u8 *D_841951F0;

// Same code as fragment80's MoveDamage_ApplyEffect_fragment80; GS reads the level at
// 0xC and HP at 0x28 of the Pokemon records, and effect 41 deals the move's power only
// while bit 27 of the word at (D_841951F0 + 0x9D4)->0x40 is set (0 damage otherwise).
//@src/fragments/80/fragment80_41A5F0.c
void func_84149928(void *arg0) {
    Fragment79DamageContext *ctx = arg0;
    switch (ctx->effect) {
    case 38:
        if (ctx->attacker[0xC] >= ctx->defender[0xC]) {
            ctx->damage = 65535;
        }
        return;
    case 40:
        ctx->damage = *(u16 *)(ctx->defender + 0x28) >> 1;
        if (!ctx->damage) {
            ctx->damage++;
        }
        return;
    case 41:
        if ((*(unk_D_841951F0_9D4 **)(D_841951F0 + 0x9D4))->unk_40_27) {
            ctx->damage = ctx->power;
        } else {
            ctx->damage = 0;
        }
        return;
    case 87:
        ctx->damage = ctx->attacker[0xC];
        return;
    case 88:
        ctx->damage = ctx->attacker[0xC] * 0.75;
        return;
    default:
        MoveDamage_ComputeBase_fragment79(ctx);
        return;
    }
}
extern void func_8414978C(u8 *);
extern void func_841496C0(u8 *);
void func_84149A50(void *arg0) {
    u8 *value;
    value = arg0;
    if (value[0] & 1) {
        return;
    }
    if (value[2] == 0x26 || value[2] == 0x28 || value[2] == 0x29 || value[2] == 0x57 || value[2] == 0x58 || value[2] == 0x94) {
        func_8414978C(value);
    } else {
        func_841496C0(value);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B7EA0/func_84149AC8.s")

extern f64 D_8418B9A0;
void func_84149C70(void *arg0) {
    u8 *value;
    value = arg0;
    if (value[2] == 0x26 || value[2] == 0x28 || value[2] == 0x29 || value[2] == 0x57 || value[2] == 0x58) {
        return;
    }
    if (value[1] == 2 || value[1] == 0xD || value[1] == 0x4B || value[1] == 0x98 || value[1] == 0xA3 || value[1] == 0xB1 || value[1] == 0xEE) {
        return;
    }
    *(s32 *)(value + 0xC) = (s32)((f64)*(s32 *)(value + 0xC) * D_8418B9A0);
}

extern void func_841497E8(void *);
extern void func_84149928(void *);
extern void func_84149A50(void *);
extern void func_84149C70(void *);
extern void func_84149AC8(void *);
void func_84149D0C(void *arg0) {
    func_841497E8(arg0);
    func_84149928(arg0);
    func_84149A50(arg0);
    func_84149C70(arg0);
    func_84149AC8(arg0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B7EA0/func_84149D54.s")

u8 func_84149E58(u8 *arg0) {
    if (arg0[1] == 8) {
        if ((*(u16 *)(*(u8 **)(arg0 + 8) + 0x26) & 7) == 0) {
            return 1;
        }
    }
    if ((*(u8 **)(arg0 + 8))[0x18] & 0x10) {
        if (arg0[1] == 3) {
            return 1;
        }
        if (arg0[1] == 8) {
            return 1;
        }
    }
    return 0;
}

s32 func_84149EC8(u8 *arg0) {
    u8 *value;
    value = *(u8 **)(arg0 + 8);
    if (value[0x19] & 0x20) {
        if (value[0x17] & 0x40) {
            if (arg0[0] == 0x59 || arg0[0] == 0x5A || arg0[0] == 0xDE) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
void func_84149EC8_padding(void) {}

u8 func_84149F30(u8 *arg0) {
    if (arg0[0] == 0x57) {
        if (arg0[3] == 1) {
            return 1;
        }
        if (arg0[3] == 2) {
            arg0[2] = 0x80;
        }
    }
    return 0;
}

extern void func_84124410(u8 *, u8, u8, u8 *);
void func_84149F74(u8 *arg0) {
    u8 *value = *(u8 **)(arg0 + 8);
    if (!(value[0x15] & 8)) {
        func_84124410(arg0 + 2, (*(u8 **)(arg0 + 4))[0x12], value[0x13], arg0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B7EA0/func_84149FB8.s")

extern u8 func_80062D98(u8);
extern s32 func_84155574(u8 *, u8);
void func_8414A0C8(u8 *arg0) {
    s32 difference;
    s32 result;
    difference = (*(u8 **)(arg0 + 4))[0xC] - (*(u8 **)(arg0 + 8))[0xC];
    result = func_84155574(*(u8 **)(arg0 + 8), func_80062D98(arg0[0]));
    if (result != 0 && difference >= 0) {
        arg0[2] += difference * 2;
    } else {
        arg0[2] = 0;
    }
}

extern void func_8414A0C8(u8 *);
extern void func_84149FB8(u8 *);
void func_8414A144(u8 *arg0) {
    if (arg0[1] == 0x26) {
        func_8414A0C8(arg0);
    }
    func_84149FB8(arg0);
}

/* mkdraft:func_8414A180 begin */
extern u8 *func_84154B0C(void);
extern s8 func_80062D20(u8);
extern s8 func_80062DD4(u8);

void func_8414A180(void *arg0, unsigned char arg1, u8 arg2)
{
  u8 *sp24;
  int new_var2;
  unsigned char new_var;
  sp24 = func_84154B0C();
  _bzero(arg0, 0xC);
  *((u8 *) (((u8 *) arg0) + 0)) = arg2;
  new_var = arg1;
  *((s8 *) (((u8 *) arg0) + 1)) = func_80062D20(arg2);
  *((s8 *) (((u8 *) arg0) + 2)) = func_80062DD4(arg2);
  *((u8 *) (((u8 *) arg0) + 3)) = sp24[0x198];
  new_var2 = new_var * 0xCC;
  *((void **) (((u8 *) arg0) + 4)) = (&sp24[new_var2]) + 8;
  *((void **) (((u8 *) arg0) + 8)) = (&sp24[((s32) arg1) * (-((0, 0xCC)))]) + ((0, 0xD4));
}
/* mkdraft:func_8414A180 end */

u8 func_8414A240(void) { return D_84187030; }

extern u8 D_84187034;
u8 func_8414A24C(void) {
    return D_84187034;
}

u16 func_8414A258(void) { return D_84187038; }

extern u8 D_84187040;
u8 func_8414A264(void) {
    return D_84187040;
}

extern u8 D_84187044[];
u8 func_8414A270(u8 arg0) {
    return D_84187044[arg0];
}

extern u8 D_8418704C;
u8 func_8414A288(void) {
    return D_8418704C;
}

extern u8 D_84187054;
u8 func_8414A294(void) {
    return D_84187054;
}

extern u8 D_84187058;
u8 func_8414A2A0(void) {
    return D_84187058;
}

extern u8 D_84187050;
u8 func_8414A2AC(void) {
    return D_84187050;
}

extern u8 D_8418705C;
u8 func_8414A2B8(void) {
    return D_8418705C;
}

extern u8 D_8418703C;
u8 func_8414A2C4(void) {
    return D_8418703C;
}

extern u8 D_84187060;
u8 func_8414A2D0(void) {
    return D_84187060;
}

extern u8 D_84187064;
u8 func_8414A2DC(void) {
    return D_84187064;
}
#endif
