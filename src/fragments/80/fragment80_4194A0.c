#include "global.h"


#ifdef VERSION_US
s32 fragment80_main(const u8 *arg0) {
    return *(u16 *)(*(u8 **)(arg0 + 0x1C) + 0x2E) < *(u16 *)(*(u8 **)(arg0 + 0x18) + 0x2E);
}

extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern u8 func_84200094(u8 *, u8);
extern u8 func_84203464(void);
s32 Species_HasType_fragment80(u8 *arg0, s32 arg1) {
    s32 result;
    result = func_8006397C(arg0[0]) == (u8)arg1;
    if (!result) {
        result = func_800639C0(arg0[0]) == (u8)arg1;
    }
    return result;
}

extern u8 func_80063454(u8, u8, u8, s32);
u8 func_84200094(u8 *arg0, u8 arg1) {
    struct {
        u8 padding[2];
        u8 first;
        u8 unused;
    } scratch;
    u8 second;

    scratch.first = func_8006397C(arg0[0]);
    second = func_800639C0(arg0[0]);
    if (func_80063454(arg1, scratch.first, second, 0) != 0) {
        return 1;
    }
    return 0;
}

u8 Ratio_ScaleToByte_fragment80(u16 value, u16 maximum) {
    s32 scaled = 255;
    u32 divisor = maximum;
    if (divisor != 0) {
        scaled = (value * 255) / (s32)divisor;
    }
    if (scaled > 255) {
        scaled = 255;
    }
    return scaled;
}

void func_84200150(u8 *arg0, u8 arg1) {
    u32 value = func_84203464();
    *(u8 **)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[0x0C] * value * arg1) / 0xFF;
}

void TypeScore_AddCoefficient0D_fragment80(u8 *arg0, u8 arg1) {
    if (!Species_HasType_fragment80(*(u8 **)(arg0 + 0x1C), 3)) {
        if (func_84200094(*(u8 **)(arg0 + 0x1C), arg0[3])) {
            u32 value = func_84203464();
            *(s32 *)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[13] * value * arg1) / 255;
        }
    }
}

void TypeScore_AddCoefficient0E_fragment80(u8 *arg0, u8 arg1) {
    if (!Species_HasType_fragment80(*(u8 **)(arg0 + 0x1C), arg0[3])) {
        if (func_84200094(*(u8 **)(arg0 + 0x1C), arg0[3])) {
            u32 value = func_84203464();
            *(s32 *)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[14] * value * arg1) / 255;
        }
    }
}

void TypeScore_AddCoefficient0F_fragment80(u8 *arg0, u8 arg1) {
    if (!Species_HasType_fragment80(*(u8 **)(arg0 + 0x1C), arg0[3])) {
        if (func_84200094(*(u8 **)(arg0 + 0x1C), arg0[3])) {
            u32 value = func_84203464();
            *(s32 *)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[15] * value * arg1) / 255;
        }
    }
}

void func_84200390(u8 *arg0, u8 arg1) {
    if (func_84200094(*(u8 **)(arg0 + 0x1C), arg0[3])) {
        u32 value = func_84203464();
        *(u8 **)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[0x10] * value * arg1) / 0xFF;
    }
}

extern u8 func_84203470(void);
void func_84200418(u8 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    u32 value = func_84203470();
    *(u8 **)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[arg2 + 0x17] * arg1 * arg3 * value) / 0xFF;
}

void func_842004A8(u8 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    u32 value = func_84203470();
    *(u8 **)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[arg1 + 0x1E] * arg2 * arg3 * value) / 0xFF;
}

void func_84200538(u8 *arg0) {}

void func_84200540(u8 *arg0) {}

void func_84200548(u8 *arg0) {}

void func_84200550(u8 *arg0) {}

extern u8 func_84203494(void);
void func_84200558(u8 *arg0, u8 arg1) {
    if (fragment80_main(arg0)) {
        u32 value = func_84203494();
        *(u8 **)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[0x11] * arg1 * value) / 0xFF;
    }
}

void func_842005D4(u8 *arg0) { u32 value = func_842034A0(); *(u8 **)(arg0 + 0x10) += (*(u8 **)(arg0 + 0x14))[0x25] * value; }

void func_84200614(u8 *arg0) {}

void func_8420061C(u8 *arg0) {}

void func_84200624(u8 *arg0) { u32 value = func_842034A0(); *(u8 **)(arg0 + 0x10) += (*(u8 **)(arg0 + 0x14))[0x26] * value; }

void func_84200664(u8 *arg0) { u32 value = func_842034A0(); *(u8 **)(arg0 + 0x10) += (*(u8 **)(arg0 + 0x14))[0x27] * value; }

void func_842006A4(u8 *arg0, u8 arg1) {
    u32 value = func_84203494();
    *(u8 **)(arg0 + 0x10) += (s32)((*(u8 **)(arg0 + 0x14))[0x12] * arg1 * value) / 0xFF;
}

void func_84200710(u8 *arg0) {}

void func_84200718(u8 *arg0) { u32 value = func_842034A0(); *(u8 **)(arg0 + 0x10) += (*(u8 **)(arg0 + 0x14))[0x28] * value; }

void func_84200758(u8 *arg0) {}

void func_84200760(u8 *arg0) {}

s32 func_84200768(u8 *arg0) {
    return Species_HasType_fragment80(*(u8 **)(arg0 + 0x1C), 0x16);
}

void func_8420078C(u8 *arg0) { u32 value = func_842034A0(); *(u8 **)(arg0 + 0x10) += (*(u8 **)(arg0 + 0x14))[0x29] * value; }

void func_842007CC(u8 *arg0) {}

void func_842007D4(u8 *arg0) {}

void func_842007DC(u8 *arg0) {}

void func_842007E4(u8 *arg0) {}

void func_842007EC(u8 *arg0) {}

void func_842007F4(u8 *arg0) {}

void func_842007FC(u8 *arg0) {}

void func_84200804(u8 *arg0) {}

void func_8420080C(u8 *arg0) {}

s32 func_84200814(u8 *arg0) {
    return Species_HasType_fragment80(*(u8 **)(arg0 + 0x18), 8);
}

void func_84200838(u8 *arg0) {}

void func_84200840(u8 *arg0) {}

void func_84200848(u8 *arg0) {}

void func_84200850(u8 *arg0) {}

void func_84200858(u8 *arg0) {}

void func_84200860(u8 *arg0) {}

void func_84200868(u8 *arg0) {}

extern s32 func_80064474(u8, u16);
// func_80064474 returns a gender from species gender-ratio data (0 = genderless);
// coefficient 0x15 is added only when the Pokemon at 0x18 and 0x1C have opposite genders.
//@src/641E0.c
void func_84200870(u8 *arg0) {
    u8 gender_a;
    s32 gender_b;
    u8 *pokemon_a;
    u8 *pokemon_b;

    pokemon_a = *(u8 **)(arg0 + 0x18);
    gender_a = func_80064474(pokemon_a[0], *(u16 *)(pokemon_a + 0x16));
    pokemon_b = *(u8 **)(arg0 + 0x1C);
    gender_b = func_80064474(pokemon_b[0], *(u16 *)(pokemon_b + 0x16));
    if ((gender_a != 0) && (gender_b != 0) && (gender_a != gender_b)) {
        u32 value = func_842034A0();
        *(u8 **)(arg0 + 0x10) += (*(u8 **)(arg0 + 0x14))[0x15] * value;
    }
}

void func_842008F8(u8 *arg0) {}

void func_84200900(u8 *arg0) { u32 value = func_842034A0(); *(u8 **)(arg0 + 0x10) += (*(u8 **)(arg0 + 0x14))[0x2E] * value; }

void func_84200940(u8 *arg0) {}

void func_84200948(u8 *arg0) {}

void func_84200950(u8 *arg0) {}

void func_84200958(u8 *arg0) {}

void func_84200960(u8 *arg0) {}

void func_84200968(u8 *arg0) {}

/* mkdraft:func_84200970 begin */
extern u8 func_80062F2C(u8);



void func_84200970(u8 *arg0) {
    u8 scale;

    /* arg0[1] is the action id; 1..0x94 are tabulated, everything else falls
     * through the default. The scale byte comes from func_80062F2C(arg0[0]),
     * a D_8009782F[arg0[0] * 6] lookup, and reaches the TypeScore helpers as
     * the arg1 that multiplies their tabulated coefficient. */
    scale = func_80062F2C(arg0[0]);
    switch (arg0[1]) {
    case 0x1:
        func_84200150(arg0, 0xFFU);
        return;
    case 0x21:
    case 0x42:
        TypeScore_AddCoefficient0D_fragment80(arg0, 0xFFU);
        return;
    case 0x2:
    case 0x4D:
        TypeScore_AddCoefficient0D_fragment80(arg0, scale);
        return;
    case 0x4:
    case 0x6C:
    case 0x7D:
        TypeScore_AddCoefficient0E_fragment80(arg0, scale);
        return;
    case 0x5:
        TypeScore_AddCoefficient0F_fragment80(arg0, scale);
        return;
    case 0x43:
        func_84200390(arg0, 0xFFU);
        return;
    case 0x6:
    case 0x98:
        func_84200390(arg0, scale);
        return;
    case 0xA:
        func_84200418(arg0, 0xFFU, 0U, 1U);
        return;
    case 0x32:
        func_84200418(arg0, 0xFFU, 0U, 2U);
        return;
    case 0x8B:
        func_84200418(arg0, scale, 0U, 2U);
        return;
    case 0xB:
    case 0x91:
    case 0x9C:
        func_84200418(arg0, 0xFFU, 1U, 1U);
        return;
    case 0x33:
        func_84200418(arg0, 0xFFU, 1U, 2U);
        return;
    case 0x8A:
        func_84200418(arg0, scale, 1U, 2U);
        return;
    case 0xC:
        func_84200418(arg0, 0xFFU, 2U, 1U);
        return;
    case 0x34:
        func_84200418(arg0, 0xFFU, 2U, 2U);
        return;
    case 0xD:
        func_84200418(arg0, 0xFFU, 3U, 1U);
        return;
    case 0x35:
        func_84200418(arg0, 0xFFU, 3U, 2U);
        return;
    case 0xE:
        func_84200418(arg0, 0xFFU, 4U, 1U);
        return;
    case 0x36:
        func_84200418(arg0, 0xFFU, 4U, 2U);
        return;
    case 0xF:
        func_84200418(arg0, 0xFFU, 5U, 1U);
        return;
    case 0x37:
        func_84200418(arg0, 0xFFU, 5U, 2U);
        return;
    case 0x10:
        func_84200418(arg0, 0xFFU, 6U, 1U);
        return;
    case 0x38:
        func_84200418(arg0, 0xFFU, 6U, 2U);
        return;
    case 0x8C:
        func_84200418(arg0, scale, 0U, 1U);
        func_84200418(arg0, scale, 1U, 1U);
        func_84200418(arg0, scale, 2U, 1U);
        func_84200418(arg0, scale, 3U, 1U);
        func_84200418(arg0, scale, 4U, 1U);
        return;
    case 0x12:
        func_842004A8(arg0, 0xFFU, 0U, 1U);
        return;
    case 0x3A:
        func_842004A8(arg0, 0xFFU, 0U, 2U);
        return;
    case 0x44:
        func_842004A8(arg0, scale, 0U, 1U);
        return;
    case 0x13:
        func_842004A8(arg0, 0xFFU, 1U, 1U);
        return;
    case 0x3B:
        func_842004A8(arg0, 0xFFU, 1U, 2U);
        return;
    case 0x45:
        func_842004A8(arg0, scale, 1U, 1U);
        return;
    case 0x14:
        func_842004A8(arg0, 0xFFU, 2U, 1U);
        return;
    case 0x3C:
        func_842004A8(arg0, 0xFFU, 2U, 2U);
        return;
    case 0x46:
        func_842004A8(arg0, scale, 2U, 1U);
        return;
    case 0x15:
        func_842004A8(arg0, 0xFFU, 3U, 1U);
        return;
    case 0x3D:
        func_842004A8(arg0, 0xFFU, 3U, 2U);
        return;
    case 0x47:
        func_842004A8(arg0, scale, 3U, 1U);
        return;
    case 0x16:
        func_842004A8(arg0, 0xFFU, 4U, 1U);
        return;
    case 0x3E:
        func_842004A8(arg0, 0xFFU, 4U, 2U);
        return;
    case 0x48:
        func_842004A8(arg0, scale, 4U, 1U);
        return;
    case 0x17:
        func_842004A8(arg0, 0xFFU, 5U, 1U);
        return;
    case 0x3F:
        func_842004A8(arg0, 0xFFU, 5U, 2U);
        return;
    case 0x49:
        func_842004A8(arg0, scale, 5U, 1U);
        return;
    case 0x18:
        func_842004A8(arg0, 0xFFU, 6U, 1U);
        return;
    case 0x40:
        func_842004A8(arg0, 0xFFU, 6U, 2U);
        return;
    case 0x4A:
        func_842004A8(arg0, scale, 6U, 1U);
        return;
    case 0x19:
        func_84200538(arg0);
        return;
    case 0x1B:
        func_84200540(arg0);
        return;
    case 0x1C:
        func_84200548(arg0);
        return;
    case 0x1E:
        func_84200550(arg0);
        return;
    case 0x8D:
        func_84200558(arg0, 0xFFU);
        return;
    case 0x1F:
    case 0x92:
        func_84200558(arg0, scale);
        return;
    case 0x23:
        func_842005D4(arg0);
        return;
    case 0x24:
        func_84200614(arg0);
        return;
    case 0x2A:
        func_8420061C(arg0);
        return;
    case 0x2E:
        func_84200624(arg0);
        return;
    case 0x2F:
        func_84200664(arg0);
        return;
    case 0x31:
        func_842006A4(arg0, 0xFFU);
        return;
    case 0x4C:
        func_842006A4(arg0, scale);
        return;
    case 0x39:
        func_84200710(arg0);
        return;
    case 0x41:
        func_84200718(arg0);
        return;
    case 0x4F:
        func_84200758(arg0);
        return;
    case 0x52:
        func_84200760(arg0);
        return;
    case 0x54:
        func_84200768(arg0);
        return;
    case 0x56:
        func_8420078C(arg0);
        return;
    case 0x5A:
        func_842007CC(arg0);
        return;
    case 0x5D:
        func_842007D4(arg0);
        return;
    case 0x5E:
        func_842007DC(arg0);
        return;
    case 0x62:
        func_842007E4(arg0);
        return;
    case 0x64:
        func_842007EC(arg0);
        return;
    case 0x66:
        func_842007F4(arg0);
        return;
    case 0x69:
        func_842007FC(arg0);
        return;
    case 0x6A:
        func_84200804(arg0);
        return;
    case 0x6B:
        func_8420080C(arg0);
        return;
    case 0x6D:
        func_84200814(arg0);
        return;
    case 0x6F:
        func_84200838(arg0);
        return;
    case 0x70:
        func_84200840(arg0);
        return;
    case 0x71:
        func_84200848(arg0);
        return;
    case 0x72:
        func_84200850(arg0);
        return;
    case 0x73:
        func_84200858(arg0);
        return;
    case 0x74:
        func_84200860(arg0);
        return;
    case 0x76:
        func_84200868(arg0);
        return;
    case 0x78:
        func_84200870(arg0);
        return;
    case 0x7C:
        func_842008F8(arg0);
        return;
    case 0x7F:
        func_84200900(arg0);
        return;
    case 0x81:
        func_84200940(arg0);
        return;
    case 0x88:
        func_84200948(arg0);
        return;
    case 0x89:
        func_84200950(arg0);
        return;
    case 0x8E:
        func_84200958(arg0);
        return;
    case 0x8F:
        func_84200960(arg0);
        return;
    case 0x94:
        func_84200968(arg0);
        /* fallthrough */
    default:
        return;
    }
}
/* mkdraft:func_84200970 end */
#endif
