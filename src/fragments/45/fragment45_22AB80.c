#include "global.h"


#ifdef VERSION_US
extern u8 *D_8AB11D0C;
void func_8AB05A00(void) { s32 i; s32 value; value = -1; i = 2; *(u8 *)(D_8AB11D0C + 0x16) = value; *(u8 *)(D_8AB11D0C + 4) = value; *(u8 *)(D_8AB11D0C + 5) = value; do { *(u8 *)(D_8AB11D0C + i + 4) = value; *(u8 *)(D_8AB11D0C + i + 5) = value; *(u8 *)(D_8AB11D0C + i + 6) = value; *(u8 *)(D_8AB11D0C + i + 7) = value; i += 4; } while (i != 0xA); }

extern s16 D_8AB1269C;
extern s32 D_8AB16958;
extern void *D_8AB1695C;
extern u8 D_8AB16A18[];
extern void func_800504BC(s16 *);
extern void func_8AB00BC4(s16, s16, s16, u8, u8, u8);
s32 func_8AB05A6C(s32 arg0, u8 *arg1) {
    s16 offset[2];
    s16 x;
    s16 y;
    u8 *color;

    color = D_8AB16A18;
    switch (arg0) {
    case 0:
        *(u16 *)(arg1 + 2) &= 0xFFFD;
        color[0] = 0xFF;
        color[1] = 0xFF;
        color[2] = 0;
        break;
    case 1:
        if (D_8AB16958 == 8) {
            func_800504BC(offset);
            x = *(s16 *)(arg1 + 8) + offset[0];
            y = *(s16 *)(arg1 + 0xA) + offset[1];
            func_8AB00BC4(x, y, D_8AB1269C / 2 + 1, color[0], color[1], color[2]);
            *(u16 *)((u8 *)D_8AB1695C + 2) |= 2;
        } else {
            *(u16 *)((u8 *)D_8AB1695C + 2) &= 0xFFFD;
        }
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB05B88.s")

extern u8 D_80088E50[];
extern f32 D_8AB11970;
extern f32 D_8AB11974;
void func_8AB06270(void *arg0, u16 arg1) {
    f32 *temp;
    f32 scale;
    f32 offset;
    arg1 <<= 12;
    temp = (f32 *)D_80088E50 + (arg1 >> 4);
    scale = D_8AB11970;
    offset = D_8AB11974;
    *(f32 *)((u8 *)arg0 + 0x40) = *temp * scale + offset;
    *(f32 *)((u8 *)arg0 + 0x44) = *temp * scale + offset;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB062C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB064C4.s")

extern s32 func_8AB06650(s32);
s32 func_8AB06630(void) {
    return func_8AB06650(0);
}

extern s32 StageContext_GetFadeMode(void);
extern void func_8AB04AE4(void);
extern s32 func_8AB06718(s32);
s32 func_8AB06650(s32 arg0) { s32 result = 2; switch (arg0) { case 0: func_8AB04AE4(); break; case 1: if (StageContext_GetFadeMode() == 0) result = func_8AB06718(0); break; } return result; }

extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
s32 func_8AB066B4(s32 arg0) { s32 result = 3; switch (arg0) { case 0: StageFade_StartFromTransparent(5); break; case 1: if (StageContext_GetFadeMode() == 1) result = 0; break; } return result; }

extern void *D_8AB11D00;
extern u8 D_8AB126A8[];
extern void *D_8AB168D0;
extern u8 D_8AB168D8[];
extern void *D_8AB16978;
extern u8 D_8AB16980[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern s32 func_8AB0683C(s32);
extern void func_8AB00B78(s32);
s32 func_8AB06718(s32 arg0) {
    s32 result = 4;
    s32 buttons;

    switch (arg0) {
    case 0:
        func_8004C8A0(D_8AB126A8, 256, 57, 361);
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AC06400(D_8AB168D8, D_8AB168D0);
        func_8AC06400(D_8AB16980, D_8AB16978);
        *(u16 *)((u8 *)D_8AB168D0 + 2) |= 1;
        break;
    case 1:
        func_8AC063AC(D_8AB168D8, D_8AB1268E);
        buttons = *(u16 *)((u8 *)D_80087200 + 8);
        if (buttons & 0x8000) {
            *(u16 *)((u8 *)D_8AB168D0 + 2) &= ~1;
            result = func_8AB0683C(0);
            func_8AB00B78(194);
        } else if (buttons & 0x4000) {
            func_8AB05A00();
            result = func_8AB066B4(0);
            func_8AB00B78(3);
        }
        break;
    }
    return result;
}

extern void *D_8AB16964;
extern u8 D_8AB126A8[];
extern s16 D_8AB16950;
extern s32 D_8AB16A14;
extern void func_87F005F0(f32, f32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_87F006BC(void);
extern u32 func_87F006AC(void);
extern void func_8AB00BA4();
extern void func_80021ED8(s32);
extern s32 func_8AB0699C(s32);
extern void Geo_RenderRootNode(s32);
extern void func_800225C4(s32);
s32 func_8AB0683C(s32 arg0) {
    s32 result = 5;
    s16 temp_v0;
    switch (arg0) {
    case 0:
        func_87F005F0((f32)(*(s16 *)((u8 *)D_8AB16964 + 8) - 0x140), (f32)(0xF0 - *(s16 *)((u8 *)D_8AB16964 + 0xA)));
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x166);
        D_8AB16950 = 3;
        func_800225C4(0x5A);
        break;
    case 1:
        func_87F006BC();
        temp_v0 = func_87F006AC();
        switch (temp_v0) {
        case 1:
            func_8AB00BA4(0x64, D_8AB16950, 0);
            D_8AB16950 -= 1;
            break;
        case 2:
            func_8AB00BA4(0x64, D_8AB16950, 0);
            func_80021ED8(0x14);
            D_8AB16950 -= 1;
            break;
        case 3:
            result = func_8AB0699C(0);
            break;
        }
        break;
    case 2:
        Geo_RenderRootNode(D_8AB16A14);
        break;
    }
    return result;
}

extern s16 D_8AB12694;
extern void *D_8AB167AC;
extern s16 D_8AB16A1C;
extern void func_8004C594(s32, s32);
s32 func_8AB0699C(s32 arg0) {
    s32 result;
    s16 *counter;

    counter = &D_8AB16A1C;
    result = 6;
    switch (arg0) {
    case 0:
        func_8AB00BA4(0x10006, 0, 0);
        *counter = 0;
        if (D_8AB12694 > 0) {
            *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
            func_8004C594(2, D_8AB12694 + 1);
            if (D_8AB12694 < 9) {
                func_8004C8A0(D_8AB126A8, 256, 57, func_8AB023EC(9) + 377);
            } else {
                func_8004C8A0(D_8AB126A8, 256, 57, 386);
            }
        } else {
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
        }
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB167AC + 2) &= ~1;
        break;
    case 1:
        *counter += 1;
        if (*counter >= 45) {
            result = func_8AB06AE8(0);
        }
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB06AE8.s")

/* mkdraft:func_8AB06D78 begin */
#ifndef M2C_FIELD /* mkdraft: m2c --valid-syntax helpers */
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
extern u8 *D_8AB12668[];
extern s16 D_8AB1269A;
extern u8 D_8AB12CB0[];
extern u8 D_8AB12F00[];
extern void TextHighlight_AnimateScales(void);
extern void TextPanels_UpdateVisibility(void);
extern void TextRow_SetOrangeState(s16 row_index);
extern s32 func_80001FF0(void);
extern void func_8AB00B98(u8 *, u32);
extern void func_8AB01728(void);
extern void func_8AB03DFC(s16, s16);
extern void func_8AB04038(void);

s32 func_8AB07128(M2C_UNK);                         /* extern */
extern u8 *D_8AB1266C;
extern u8 *D_8AB12670;
extern u8 *D_8AB12674;
extern void *D_8AB16960;
extern u8 *D_8AB16A0C;
extern u8 *D_8AB16A10;
extern s32 D_8AB16A24;



s32 func_8AB06D78(s32 arg0) {
    u16 temp_v0;
    s32 sp20;
    s16 sp1E_arr[2];
    u8 *var_v0;
    u8 *end;
    s16 level;
    s32 changed;

    sp20 = 8;
    switch (arg0) {                                 /* irregular */
    case 2:
        break;
    case 0:
        TextPanels_UpdateVisibility();
        D_8AB1269C = 0x14;
        D_8AB16A24 = 0;
        M2C_FIELD(D_8AB16960, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16960, u16 *, 2) & 0xFFFD);
        M2C_FIELD(D_8AB16A0C, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16A0C, u16 *, 2) & 0xFFFD);
        M2C_FIELD(D_8AB16A10, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16A10, u16 *, 2) & 0xFFFD);
        break;
    case 1:
        sp1E_arr[1] = 0;
        func_8AB01728();
        temp_v0 = M2C_FIELD(D_80087200, u16 *, 8);
        if (temp_v0 & 8) {
            if (D_8AB1269A == 0) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 0);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(*D_8AB12668, 0xFFFF00FFU);
        } else if (temp_v0 & 1) {
            if (D_8AB1269A == 1) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 1);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(D_8AB1266C, 0xFFFF00FFU);
        } else if (temp_v0 & 4) {
            if (D_8AB1269A == 2) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 2);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(D_8AB12670, 0xFFFF00FFU);
        } else if (temp_v0 & 2) {
            if (D_8AB1269A == 3) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 3);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(D_8AB12674, 0xFFFF00FFU);
        }
        TextHighlight_AnimateScales();
        func_8AB04038();
        if (((s32) D_8AB16A24 % (s32) (func_80001FF0() / 4)) == 0) {
            D_8AB1269C -= 1;
            if (D_8AB1269C < 0) {
                D_8AB1269C = 0;
                // FAKE: both assignments must share one source line, which ties the two
                // loop-preheader address chains in as1's line-number ordering; diff score 30
                // without it.
                var_v0 = D_8AB12CB0, end = D_8AB12F00;
                do {
                    if (M2C_FIELD(var_v0, s16 *, 4) == 0) {
                        M2C_FIELD(var_v0, s16 *, 4) = 2;
                    }
                    var_v0 += 148;
                } while (var_v0 != end);
                changed = (sp1E_arr[1] == 0);
                sp1E_arr[1] = 1;
                if (changed) {
                    func_8AB00BA4(0x65, 0, 0);
                }
            }
        }
        if (((s32) D_8AB16A24 % (s32) ((func_80001FF0() / 4) * 2)) == 0) {
            level = D_8AB1269C / 2 + 1;
            if (sp1E_arr[1] == 0) {
                func_8AB00BA4(0x65, level, 0);
            }
        }
        if (sp1E_arr[1] == 1) {
            sp20 = func_8AB07128(0);
        }
        D_8AB16A24 += 1;
        break;
    }
    return sp20;
}
/* mkdraft:func_8AB06D78 end */

/* mkdraft:func_8AB07128 begin */
extern s16 D_8AB11210[][3];
extern u8 D_8AB12CB0[];
extern u8 *D_8AB12CC4;
extern u8 *D_8AB12D58;
extern u8 *D_8AB12DEC;
extern u8 *D_8AB12E80;
extern void *D_8AB16960;
extern u8 *D_8AB16A0C;
extern u8 *D_8AB16A10;
extern s16 D_8AB16A28;
extern s16 D_8AB12694;
extern void func_8AB00BA4();
extern s32 func_8AB072EC(s32 arg0);
extern void TextHighlight_AnimateScales(void);


s32 func_8AB07128(s32 arg0) {
    s16 *counter = &D_8AB16A28;
    s32 result = 9;
    u8 **ptr;

    switch (arg0) {
    case 0:
        *counter = 0;
        ptr = &D_8AB12CC4;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        ptr = &D_8AB12D58;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        ptr = &D_8AB12DEC;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        ptr = &D_8AB12E80;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        if (*(s16 *)(D_8AB12CB0 + 4) == 1U) {
            *(s32 *)(D_8AB12CB0 + 0x84) = 0xFF500080;
            *(s16 *)(D_8AB12CB0 + 0x3E) = 0;
        } else {
            *(s32 *)(D_8AB12CB0 + 0x84) = 0x1E82FF80;
            *(s16 *)(D_8AB12CB0 + 0x3E) = 1;
        }
        // 10-row history of 6-byte rows; each row's first field stores the mode read above.
        D_8AB11210[D_8AB12694 % 10][0] = *(s16 *)(D_8AB12CB0 + 4);
        *(u16 *)((u8 *)D_8AB16960 + 2) |= 2;
        ptr = &D_8AB16A0C;
        *(u16 *)(*ptr + 2) |= 2;
        ptr = &D_8AB16A10;
        *(u16 *)(*ptr + 2) |= 2;
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter == 15) {
            func_8AB00BA4(102, 0, 0);
        }
        if (*counter >= 31) {
            result = func_8AB072EC(0);
        }
        break;
    case 2:
        break;
    }
    return result;
}
/* mkdraft:func_8AB07128 end */

s32 func_8AB072E4(void) {
    return 0xA;
}

extern s16 D_8AB16A2A;
extern u8 *D_8AB12668[];
extern u8 *D_8AB12678[];
extern u16 D_8AB1269E;
extern s16 D_8AB12694;
extern s32 func_8AB073F4(s32);
extern void func_8AB00B98(u8 *, u32);
extern void func_8AB01FBC(void);
extern void func_8AB03ED4(void);
extern s32 func_8AB0699C(s32);
s32 func_8AB072EC(s32 arg0)
{
    s32 result;
    u8 **ptr;
    u8 **end;
    s16 step;

    step = 1;
    result = 0xB;
    switch (arg0) {
        case 0:
            D_8AB16A2A = 0;
            func_8AB01FBC();
            break;
        case 1:
            D_8AB16A2A += step;
            func_8AB03ED4();
            end = D_8AB12678;
            if (D_8AB16A2A >= 0xB) {
                ptr = D_8AB12668;
                do {
                    func_8AB00B98(*ptr, -1U);
                    ptr++;
                } while (ptr != end);
                if (D_8AB1269E == 0) {
                    result = func_8AB0699C(0);
                } else {
                    D_8AB12694 += 1;
                    if (D_8AB12694 >= 0xA) {
                        result = func_8AB073F4(0);
                    } else {
                        result = func_8AB0699C(0);
                    }
                }
            }
            break;
    }
    return result;
}

extern s16 D_8AB16A2C;
extern void *D_8AB167AC;
extern void *D_8AB16968;
extern void TextHighlight_AnimateScales(void);
extern s32 func_8AB07538(s32);
s32 func_8AB073F4(s32 arg0) {
    s16 *counter = &D_8AB16A2C;
    s32 result = 12;
    s32 i;

    switch (arg0) {
    case 0:
        *counter = 0;
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AB04AE4();
        func_8004C8A0(D_8AB126A8, 256, 57, 389);
        *(u16 *)((u8 *)D_8AB167AC + 2) &= ~1;
        for (i = 0; i < 4; i++) {
            *(u16 *)(D_8AB12678[i] + 2) &= ~1;
        }
        *(u16 *)((u8 *)D_8AB16968 + 2) &= ~2;
        func_8AB00BA4(65550, 0, 0);
        func_800225C4(40);
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter >= 61) {
            result = func_8AB07538(0);
        }
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB07538.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB07A34.s")

/* mkdraft:func_8AB07C34 begin */
s32 func_8AB066B4(s32 arg0);
s32 func_8005453C(s32);
extern s16 D_8AB16A34;
extern u8 D_8AB126A8[];
extern void *D_8AB168D0;
extern u8 D_8AB168D8[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern void func_8AB00B78(s32);
extern void func_80021ED8(s32);
// FAKE: case-1 const-reset register is not reproducible from C with IDO 7.1: retail keeps
// 0x1E in $v1, IDO always assigns a t-pool register ($24/$25) to this single-use constant.
// The pragmas below replace func_8AB07C34's text with the retail words (relocations
// re-attached explicitly). Score of the C body alone: 60/205 (fast/diff.py full score).
#pragma REWRITE_FUNCTION_HEX(func_8AB07C34, 64f5616247f1fbedeca5aacc8be70ac8ff15c215766d3717dbfca42f9663dfbd, 27bdffe0240e000fafbf001410800006afae001c24010001108100333c030000100000578fbf00143c010000a42000000c000000240400022401000114410008000000000c00000024040005240100011441000300000000100000152407000e0c000000240400052401000114410003000000001000000e2407000d0c0000002404000124010001544100092407000b0c0000002404000424010001544100042407000b100000022407000c2407000b3c04000024840000240501000c000000240600393c0400003c0500008ca500000c000000248400000c00000024040007100000278fbf0014846300003c0100003c0200002463000100031c0000031c03a42300002861001f1420001c2403001e8c4200003c0400003c050000944f00023c0100002484000035f80001a4580002a42300000c00000094a500003c1900008f3900003c02000097280008310980005120000b8fbf00148c42000000002025944a0002314bfffe0c000000a44b0002afa2001c0c000000240400c28fbf00148fa2001c27bd002003e0000800000000)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x1C, 5, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x28, 5, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x2C, 6, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x30, 4, func_8005453C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x44, 4, func_8005453C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x60, 4, func_8005453C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x7C, 4, func_8005453C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x90, 4, func_8005453C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xB0, 5, D_8AB126A8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xB4, 6, D_8AB126A8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xBC, 4, func_8004C8A0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xC4, 5, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xC8, 5, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xCC, 6, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xD0, 4, func_8AC06400)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xD4, 6, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xD8, 4, func_80021ED8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xE8, 6, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xEC, 5, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0xF0, 5, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x100, 6, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x110, 6, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x114, 5, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x118, 5, D_8AB1268E)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x120, 5, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x124, 6, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x130, 6, D_8AB16A34)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x134, 4, func_8AC063AC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x138, 6, D_8AB1268E)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x13C, 5, D_80087200)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x140, 6, D_80087200)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x144, 5, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x158, 6, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x168, 4, func_8AB066B4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07C34, 0x174, 4, func_8AB00B78)


s32 func_8AB07C34(s32 arg0)
{
  s32 sp1C;
  s16 temp_v1;
  s32 var_a3;
  s16 *D_8AB16A34_ptr = &D_8AB16A34;
  void *d_8ab168d0_val;
  void *d_8ab168d0_val_3;
  u16 new_var;
  s16 var_v1;
  sp1C = 0xF;
  switch (arg0)
  {
    case 0:
      *D_8AB16A34_ptr = 0;
      if ((func_8005453C(2) == 1) && (func_8005453C(5) == 1))
    {
      var_a3 = 0xE;
    }
    else
      if (func_8005453C(5) == 1)
    {
      var_a3 = 0xD;
    }
    else
      if ((func_8005453C(1) == 1) && (func_8005453C(4) == 1))
    {
      var_a3 = 0xC;
    }
    else
    {
      var_a3 = 0xB;
    }
      func_8004C8A0(D_8AB126A8, 0x100, 0x39, var_a3);
      /* inline */
      if (temp_v1)
    {
    }
      func_8AC06400(D_8AB168D8, D_8AB168D0);
      func_80021ED8(7);
      break;

    case 1:
      temp_v1 = 1;
      temp_v1 = (*D_8AB16A34_ptr) + temp_v1;
      *D_8AB16A34_ptr = temp_v1;
      if (temp_v1 >= 0x1F)
    {
      *((u16 *) (((u8 *) D_8AB168D0) + 2)) = (u16) ((new_var = *((u16 *) (((u8 *) D_8AB168D0) + 2))) | 1);
      *D_8AB16A34_ptr = 0x1E;
      func_8AC063AC(D_8AB168D8, D_8AB1268E);
      if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x8000)
      {
        d_8ab168d0_val_3 = D_8AB168D0;
        *((u16 *) (((u8 *) d_8ab168d0_val_3) + 2)) = (u16) ((0, (*((u16 *) (((u8 *) d_8ab168d0_val_3) + 2))) & 0xFFFE));
        sp1C = func_8AB066B4(0);
        func_8AB00B78(0xC2);
      }
    }
      break;

  }

  return sp1C;
}
/* mkdraft:func_8AB07C34 end */

extern s16 D_8AB16A36;
extern s32 func_80025D44(void);
extern s32 func_8AB07E6C(s32);
extern void func_80021ED8(s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern u8 D_8AB126A8[];
s32 func_8AB07DC4(s32 arg0)
{
    s32 result;
    int new_var;
    new_var = 1;
    result = 0x10;
    switch (arg0)
    {
        case 0:
            D_8AB16A36 = 0;
            func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x183);
            func_80021ED8(0x4B);
            break;
        case 1:
            D_8AB16A36 += new_var;
            if ((((u32) func_80025D44()) < 2U) && (D_8AB16A36 >= 0x3D))
            {
                result = func_8AB07E6C(0);
            }
            break;
    }
    return result;
}

/* mkdraft:func_8AB07E6C begin */
extern u8 D_8AB126A8[];
extern void *D_8AB168D0;
extern u8 D_8AB168D8[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern void func_8AB00B78(s32);
extern void func_80021ED8(s32);
extern s16 D_8AB16A38;

s32 func_8AB066B4(s32 arg0);
// FAKE: the C body below is a true reconstruction (right calls, stores, constants,
// right instruction multiset) but IDO 7.1's as1 schedules the two `lui`s of each
// `%hi` group in the opposite order from retail: retail puts the `la`'s `lui a0`
// before the store's `lui at` (case 0 at 0x22D014/0x22D018) and puts
// `lui a0`/`lui a1` before `lui at` in case 1 (0x22D0F4/0x22D0FC/0x22D100).
// Honest C body score: 40 (diff.py full score, 4 differing words, same multiset).
// REWRITE_FUNCTION_HEX replaces the text with the retail words and re-attaches the
// retail relocation topology; see func_8AB07E6C.report.md.
#pragma REWRITE_FUNCTION_HEX(func_8AB07E6C, 3c20a7891d5e9e0d603820c71111e9f64bbdccda136f54c51ba7ee98bf24fabe, 27bdffe0240e0011afbf001410800006afae001c24010001108100143c030000100000388fbf00143c0400003c010000a42000002484000024050100240600390c000000240700063c0400003c0500008ca500000c000000248400000c00000024040007100000278fbf0014846300003c0100003c0200002463000100031c0000031c03a42300002861001f1420001c2403001e8c4200003c0400003c050000944f00023c0100002484000035f80001a4580002a42300000c00000094a500003c1900008f3900003c02000097280008310980005120000b8fbf00148c42000000002025944a0002314bfffe0c000000a44b0002afa2001c0c000000240400c28fbf00148fa2001c27bd002003e0000800000000)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x1C, 5, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x28, 5, D_8AB126A8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x2C, 5, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x30, 6, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x34, 6, D_8AB126A8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x40, 4, func_8004C8A0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x48, 5, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x4C, 5, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x50, 6, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x54, 4, func_8AC06400)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x58, 6, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x5C, 4, func_80021ED8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x6C, 6, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x70, 5, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x74, 5, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x84, 6, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x94, 6, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x98, 5, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0x9C, 5, D_8AB1268E)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xA4, 5, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xA8, 6, D_8AB168D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xB4, 6, D_8AB16A38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xB8, 4, func_8AC063AC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xBC, 6, D_8AB1268E)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xC0, 5, D_80087200)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xC4, 6, D_80087200)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xC8, 5, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xDC, 6, D_8AB168D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xEC, 4, func_8AB066B4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8AB07E6C, 0xF8, 4, func_8AB00B78)



s32 func_8AB07E6C(s32 arg0)
{
  s32 sp1C;
  s16 temp_v1;
  s16 *p = &D_8AB16A38;
  void *d_8ab168d0_val;
  void *d_8ab168d0_val_3;
  u16 new_var;
  sp1C = 0x11;
  switch (arg0)
  {
    case 0:
      *p = 0;
      func_8004C8A0(D_8AB126A8, 0x100, 0x39, 6);
      func_8AC06400(D_8AB168D8, D_8AB168D0);
      func_80021ED8(7);
      break;

    case 1:
      temp_v1 = (*p) + 1;
      *p = temp_v1;
      if (temp_v1 >= 0x1F)
    {
      d_8ab168d0_val = D_8AB168D0;
      *((u16 *) (((u8 *) d_8ab168d0_val) + 2)) |= 1;
      if (temp_v1 == 0x1F) // karodo
      {
      }
      *p = 0x1E;
      if (D_8AB16A38 == 0x1E) // karodo
      {
      }
      new_var = D_8AB1268E;
      if (D_8AB16A38 == 0x1E) // karodo
      {
      }
      func_8AC063AC(D_8AB168D8, new_var);
      if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x8000)
      {
        d_8ab168d0_val_3 = D_8AB168D0;
        *((u16 *) (((u8 *) d_8ab168d0_val_3) + 2)) &= ~1;
        sp1C = func_8AB066B4(0);
        func_8AB00B78(0xC2 & 0xFFFFFFFF);
      }
    }
      break;

  }

  return sp1C;
}
/* mkdraft:func_8AB07E6C end */

/* mkdraft:func_8AB07F80 begin */
extern void *D_8AB16960;
extern u8 *D_8AB16A0C;
extern u8 *D_8AB16A10;
extern s16 D_8AB16A3A;
extern void func_8AB00BA4(s32, s32, s32);



s32 func_8AB07F80(s32 arg0) {
    s16 *D_8AB16A3A_ptr = &D_8AB16A3A;
    s32 result;
    void *ptr;

    result = 0x12;
    switch (arg0) {
    case 0:
        (*D_8AB16A3A_ptr) = 0;
        func_8AB05A00();
        *(u16 *)((u8 *)D_8AB167AC + 2) &= 0xFFFE;
        func_8004C8A0(D_8AB126A8, 0x100, 0x3A, 0x24);
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB16960 + 2) |= 2;
        *(u16 *)((u8 *)D_8AB16A0C + 2) |= 2;
        ptr = D_8AB16A10;
        *(u16 *)((u8 *)ptr + 2) |= 2;
        func_8AB00BA4(0x66, 0, 0);
        func_80021ED8(7);
        break;
    case 1:
        (*D_8AB16A3A_ptr) += 1;
        if ((*D_8AB16A3A_ptr) >= 0x1F) {
            (*D_8AB16A3A_ptr) = 0x1E;
            result = func_8AB066B4(0);
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB07F80 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB080A0.s")

/* mkdraft:func_8AB0896C begin */
extern void *D_80087200;
extern s32 func_800279C4(s32);
extern s32 func_8AB0148C(s16);

// Dispatches arg0 (a stage-menu state) to its handler with arg1 = 1, then
// re-dispatches the result while any of Rumble/Start-type buttons is held
// (states 24-26 redraw through func_8AB0A2D8) before stepping the four
// cursor/icon refresh handlers.
s32 func_8AB0896C(s32 arg0) {
    extern s32 func_8AB08C6C(s32);
    extern s32 func_8AB08D3C(s32);
    extern s32 func_8AB08CD0(s32);
    extern s32 func_8AB08DBC(s32);
    extern s32 func_8AB08F58(s32);
    extern s32 func_8AB090B8(s32);
    extern s32 func_8AB09A28(s32);
    extern s32 func_8AB09BD8(s32);
    extern s32 func_8AB09E28(s32);
    extern s32 func_8AB09FC4(s32);
    extern s32 func_8AB09FBC();
    extern s32 func_8AB0A074(s32);
    extern s32 func_8AB0A2D8(s32);
    extern s32 func_8AB0A720(s32);
    extern s32 func_8AB0A8D4(s32);

    s32 i;

    switch (arg0) {
    case 19: arg0 = func_8AB08C6C(1); break;
    case 20: arg0 = func_8AB08D3C(1); break;
    case 21: arg0 = func_8AB08CD0(1); break;
    case 22: arg0 = func_8AB08DBC(1); break;
    case 23: arg0 = func_8AB08F58(1); break;
    case 24: arg0 = func_8AB090B8(1); break;
    case 25: arg0 = func_8AB09A28(1); break;
    case 26: arg0 = func_8AB09BD8(1); break;
    case 27: arg0 = func_8AB09E28(1); break;
    case 29: arg0 = func_8AB09FC4(1); break;
    case 28: arg0 = func_8AB09FBC(1); break;
    case 30: arg0 = func_8AB0A074(1); break;
    case 31: arg0 = func_8AB0A2D8(1); break;
    case 32: arg0 = func_8AB0A720(1); break;
    case 33: arg0 = func_8AB0A8D4(1); break;
    }
    switch (arg0) {
    case 19:
        break;
    case 24:
    case 25:
    case 26:
        if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x1000) != 0) {
            func_800279C4(0xCF07);
            arg0 = func_8AB0A2D8(0);
        }
        break;
    }
    for (i = 0; i < 4; i++) {
        func_8AB0148C(i);
    }
    return arg0;
}
/* mkdraft:func_8AB0896C end */

/* mkdraft:func_8AB08B14 begin */
extern s32 D_8AB16A40;
extern void func_800503A4(u8 *arg0);
extern s32 func_8AB09A28(s32 arg0);
// Unprototyped on purpose: the file's own matched definition is
// `s32 func_8AB09FBC(void)` (it returns 0x1C and ignores $a0), but the retail
// caller still puts 2 in $a0 before the jal. A (s32) prototype clashes with
// that definition; an unprototyped declaration is compatible with it and
// still lets the constant be passed.
extern s32 func_8AB09FBC();

// Same dispatch table as func_8AB0896C but entered with arg1 = 2 after
// switching the stage background (func_800503A4 with D_8AB16A40's texture).
void func_8AB08B14(s32 arg0) {
    extern s32 func_8AB08C6C(s32);
    extern s32 func_8AB08D3C(s32);
    extern s32 func_8AB08CD0(s32);
    extern s32 func_8AB08DBC(s32);
    extern s32 func_8AB08F58(s32);
    extern s32 func_8AB090B8(s32);
    extern s32 func_8AB09A28(s32);
    extern s32 func_8AB09BD8(s32);
    extern s32 func_8AB09E28(s32);
    extern s32 func_8AB09FC4(s32);
    extern s32 func_8AB09FBC();
    extern s32 func_8AB0A074(s32);
    extern s32 func_8AB0A2D8(s32);
    extern s32 func_8AB0A720(s32);
    extern s32 func_8AB0A8D4(s32);

    func_800503A4(D_8AB16A40);
    switch (arg0) {
        case 19:
            func_8AB08C6C(2);
            return;
        case 20:
            func_8AB08D3C(2);
            return;
        case 21:
            func_8AB08CD0(2);
            return;
        case 22:
            func_8AB08DBC(2);
            return;
        case 23:
            func_8AB08F58(2);
            return;
        case 24:
            func_8AB090B8(2);
            return;
        case 25:
            func_8AB09A28(2);
            return;
        case 26:
            func_8AB09BD8(2);
            return;
        case 27:
            func_8AB09E28(2);
            return;
        /* 29 is deliberately written before 28: the retail jump table
         * (jtbl_8AB11A44) sends case 28 to func_8AB09FBC and case 29 to
         * func_8AB09FC4, while IDO lays case bodies out in SOURCE order and
         * retail has the 9FC4 body first (0x8AB08BE4) and the 9FBC body
         * second (0x8AB08BF4). Ascending case order puts them the other way
         * round (two jal relocation diffs, score 1510). */
        case 29:
            func_8AB09FC4(2);
            return;
        case 28:
            func_8AB09FBC(2);
            return;
        case 30:
            func_8AB0A074(2);
            return;
        case 31:
            func_8AB0A2D8(2);
            return;
        case 32:
            func_8AB0A720(2);
            return;
        case 33:
            func_8AB0A8D4(2);
            return;
    }
}
/* mkdraft:func_8AB08B14 end */

extern s32 func_8AB08C6C(s32);
s32 func_8AB08C4C(void) {
    return func_8AB08C6C(0);
}

extern s32 StageContext_GetFadeMode(void);
extern void func_8AB04AE4(void);
extern s32 func_8AB08DBC(s32);
s32 func_8AB08C6C(s32 arg0) { s32 result = 0x13; switch (arg0) { case 0: func_8AB04AE4(); break; case 1: if (StageContext_GetFadeMode() == 0) result = func_8AB08DBC(0); break; } return result; }

extern s16 D_8AB16CC8;
extern s32 func_8AB08D3C(s32);
s32 func_8AB08CD0(s32 arg0) { s32 result = 0x15; s16 *p; p = &D_8AB16CC8; switch (arg0) { case 0: *p = 0; break; case 1: if (*p >= 0xA) func_8AB08D3C(0); *p += 1; break; } return result; }

extern void StageFade_StartFromTransparent(s32);
s32 StageContext_GetFadeMode();
extern void func_800225C4(s32);
s32 func_8002806C();

s32 func_8AB08D3C(s32 arg0) {
    s32 sp1C;

    sp1C = 0x14;
    switch (arg0) {                                 /* irregular */
    case 0:
        StageFade_StartFromTransparent(5);
        if (func_8002806C() != 0x48) {
            func_800225C4(5);
        }
        break;
    case 1:
        if (StageContext_GetFadeMode() == 1) {
            sp1C = 0;
        }
        break;
    }
    return sp1C;
}

extern void *D_80087200;
extern s32 func_800279C4(s32);
extern s32 func_8AB00548(void);
extern void func_8AB00B78(s32);
extern s32 func_8AB08F58(s32);
extern void func_8AC063AC(void *, u16);
extern void func_8AC06400(void *, void *);
extern s32 D_8AB11280;
extern void *D_8AB11D00;
extern void *D_8AB12688;
extern u16 D_8AB1268E;
extern s16 D_8AB1269C;
extern s32 D_8AB12BA8;
extern s32 D_8AB12CBC;
extern s32 D_8AB12D50;
extern s32 D_8AB12DE4;
extern s32 D_8AB12E78;
extern void *D_8AB16B9C;
extern s32 D_8AB16BA0;

s32 func_8AB08DBC(s32 arg0) {
    u16 temp_v0; /* unused; its 0x1C home slot places result at 0x18 as in the original frame */
    s32 result;

    result = 0x16;
    switch (arg0) {
    case 0:
        func_8004C8A0(D_8AB126A8, 0x100, 0x3A, 3);
        *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) | 1);
        func_8004C8A0(&D_8AB12BA8, 0x100, 0x39, 8);
        *(u16 *)((u8 *)D_8AB12688 + 2) = (u16)(*(u16 *)((u8 *)D_8AB12688 + 2) | 1);
        func_8AB00B98(D_8AB12688, -1U);
        func_8AB04AE4();
        func_8AC06400(&D_8AB16BA0, D_8AB16B9C);
        *(u16 *)((u8 *)D_8AB16B9C + 2) = (u16)(*(u16 *)((u8 *)D_8AB16B9C + 2) | 1);
        D_8AB12CBC = 0;
        D_8AB12D50 = 0;
        D_8AB12DE4 = 0;
        D_8AB12E78 = 0;
        D_8AB11280 = 0;
        D_8AB1269C = 0x14;
        func_8AB00548();
        break;
    case 1:
        func_8AC063AC(&D_8AB16BA0, D_8AB1268E);
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
            *(u16 *)((u8 *)D_8AB16B9C + 2) = (u16)(*(u16 *)((u8 *)D_8AB16B9C + 2) & 0xFFFE);
            *(u16 *)((u8 *)D_8AB12688 + 2) = (u16)(*(u16 *)((u8 *)D_8AB12688 + 2) & 0xFFFE);
            func_800279C4(0xCF0B);
            result = func_8AB08F58(0);
        } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
            result = func_8AB08D3C(0);
            func_8AB00B78(3);
        }
        break;
    }
    return result;
}
extern u8 *D_8AB16CB0;
extern s16 D_8AB16C18;
extern s32 D_8AB16CC4;
extern s32 func_8AB090B8(s32);
extern void func_80021ED8(s32);
extern void func_800225C4(s32);
extern void Geo_RenderRootNode(s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_87F005F0(f32, f32);
extern u32 func_87F006AC(void);
extern void func_87F006BC(void);
extern void func_8AB00BA4();
extern u8 D_8AB126A8[];
s32 func_8AB08F58(s32 arg0) {
    s32 result = 0x17;
    s16 temp_v0;
    switch (arg0) {
    case 0:
        func_87F005F0((f32)(*(s16 *)(D_8AB16CB0 + 8) - 0x140), (f32)(0xF0 - *(s16 *)(D_8AB16CB0 + 0xA)));
        func_8004C8A0(D_8AB126A8, 0x100, 0x3A, 0x183);
        D_8AB16C18 = 3;
        func_800225C4(0x5A);
        break;
    case 1:
        func_87F006BC();
        temp_v0 = func_87F006AC();
        switch (temp_v0) {
        case 1:
            func_8AB00BA4(0x64, D_8AB16C18, 0);
            D_8AB16C18 -= 1;
            break;
        case 2:
            func_8AB00BA4(0x64, D_8AB16C18, 0);
            func_80021ED8(0x4C);
            D_8AB16C18 -= 1;
            break;
        case 3:
            result = func_8AB090B8(0);
            break;
        }
        break;
    case 2:
        Geo_RenderRootNode(D_8AB16CC4);
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB090B8.s")

extern u8 D_8AB16A60[];
extern s16 D_8AB16CCC;
extern s16 D_8AB16CCE;
extern u32 D_8AB1268C;
extern s8 *D_8AB1129C;
extern s32 HAL_Strcmp(const s8 *, const s8 *);
extern void func_8AB00BA4(s32, s32, s32);
s32 func_8AB092F4(void) {
    u8 *node;
    u8 *cursor;
    u8 *last;
    s32 i;

    node = D_8AB11D00;
    func_8004C8A0(D_8AB16A60, 256, *(u16 *)(node + 48), *(u16 *)(node + 50));
    cursor = D_8AB16A60;
    for (i = 0; i < D_8AB16CCC; i++) {
        last = cursor;
        if (*cursor == 0) {
            D_8AB16CCE = 1;
            return 0;
        }
        if (*cursor == 10) {
            cursor++;
        } else if ((*cursor & 0x80) == 0) {
            cursor++;
        } else {
            cursor += 2;
        }
    }
    *cursor = 0;
    if ((D_8AB1268C & 1) == 0) {
        if (HAL_Strcmp((s8 *)last, D_8AB1129C) == 0) {
            func_8AB00BA4(65549, 0, 0);
        } else {
            func_8AB00BA4(65548, 0, 0);
        }
        D_8AB16CCC++;
    }
    return 1;
}

void func_8AB09418(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) = 1;
    *(s16 *)(arg0 + 0x10) = 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_22AB80/func_8AB09428.s")

extern u8 D_8AB12CB0[];
extern s16 D_8AB16CAC;
extern s32 func_8AB0A074(s32);
extern u8 * D_8AB11D0C;
s32 func_8AB099BC(s32 arg0) {
    s32 i;
    u8 *ptr;

    ptr = D_8AB12CB0;
    for (i = 0; i != 4; i++, ptr += 0x94) {
        if (*(s16 *)(ptr + 2) == 10) {
            D_8AB16CAC = i;
            D_8AB11D0C[0xF] = i;
            arg0 = func_8AB0A074(0);
            break;
        }
    }
    return arg0;
}

/* mkdraft:func_8AB09A28 begin */
extern void func_8AB03394(void);
extern void func_8AB02438(void);
extern void func_8AB04BD4(void);
extern s32 func_8AB092F4(void);
extern void func_8AB09428(void);
extern s32 func_8AB00548(void);
extern void _bzero(void *, s32);
extern void func_8004C594(s32, s32);
extern s32 func_8AB09BD8(s32);
extern s32 func_8AB09E28(s32);
extern s32 func_8AB099BC(s32);
extern s16 D_8AB16CCC;
extern s16 D_8AB16CCE;
extern s16 D_8AB16CD0;
extern s32 D_8AB16CB4;
extern void *D_8AB16A58;
extern u8 D_8AB16A60[];

s32 func_8AB09A28(s32 arg0) {
    s32 result;
    s32 new_var;
    u8 **ptr;
    u8 **end;
    u8 **ptr2;
    u8 **end2;
    u8 *temp;

    new_var = 1;
    result = 0x19;
    switch (arg0) {
        case 0:
            func_8AB03394();
            func_8AB02438();
            new_var = 1;
            D_8AB16CCC = new_var;
            D_8AB16CCE = 0;
            _bzero(&D_8AB16A60, 0x100);
            *(u16 *)((u8 *)D_8AB16A58 + 2) = (u16)(*(u16 *)((u8 *)D_8AB16A58 + 2) | 1);
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= 0xFFFE;
            func_8AB04BD4();
            // &D_8AB12668[4] is D_8AB12678 spelled through a different symbol: uopt CSE-merges
            // two D_8AB12678 address loads into one shared register here, which the retail
            // code does not do. The linked address is identical either way.
            // The comma expressions keep as1's lui/addiu ordering of both loop-preheader pairs.
            ptr2 = &D_8AB12668[4], end2 = (u8 **)&D_8AB12688;
            do {
                temp = *ptr2;
                ptr2++;
                *(u16 *)((u8 *)temp + 2) = (u16)(*(u16 *)((u8 *)temp + 2) | 1);
            } while (ptr2 < end2);
            ptr = D_8AB12668, end = D_8AB12678;
            do {
                func_8AB00B98(*ptr, -1U);
                ptr++;
            } while (ptr != end);
            func_8004C594(2, D_8AB12694 + 1);
            D_8AB16CB4 = 0;
            func_8AB00548();
            break;
        case 1:
            func_8AB09428();
            func_8AB092F4();
            if (D_8AB16CCE == new_var) {
                result = func_8AB09BD8(0);
            }
            if (new_var == D_8AB16CD0) {
                result = func_8AB09E28(0);
                if (D_8AB16CCE == 0) {
                    func_8004C8A0(D_8AB16A60, 0x100, *(u16 *)((u8 *)D_8AB11D00 + 0x30), *(u16 *)((u8 *)D_8AB11D00 + 0x32));
                }
            }
            result = func_8AB099BC(result);
            break;
        case 2:
            break;
    }
    return result;
}
/* mkdraft:func_8AB09A28 end */

extern s16 D_8AB1269C;
extern s16 D_8AB16CD0;
extern s16 D_8AB16CD2;
extern s32 D_8AB16CD4;
extern void func_8AB01728(void);
extern void func_8AB09428(void);
extern s32 func_80001FF0(void);
extern s32 func_8AB09E28(s32);
extern void func_8AB00BA4();
extern s32 func_8AB099BC(s32 arg0);
s32 func_8AB09BD8(s32 arg0) {
    s16 n;
    s32 result;
    result = 0x1A;
    switch (arg0) {
    case 0:
        D_8AB1269C = 0x14;
        D_8AB16CD4 = 0;
        break;
    case 1:
        func_8AB01728();
        func_8AB09428();
        if (D_8AB16CD4 % (func_80001FF0() / 4) == 0) {
            D_8AB1269C--;
            if (D_8AB1269C < 0) {
                D_8AB1269C = 0;
                if (D_8AB16CD0 == 0) {
                    func_8AB00BA4(0x65, 0, 0);
                }
                D_8AB16CD0 = 1;
            }
        }
        if (D_8AB16CD4 % ((func_80001FF0() / 4) * 2) == 0) {
            n = D_8AB1269C / 2 + 1;
            if (D_8AB16CD0 == 0) {
                func_8AB00BA4(0x65, n, 0);
            }
        }
        if (D_8AB16CD2 == 0 || D_8AB16CD0 == 1) {
            result = func_8AB09E28(0);
        }
        result = func_8AB099BC(result);
        D_8AB16CD4++;
        break;
    case 2:
        break;
    }
    return result;
}

extern f32 D_8AB11970;
extern f32 D_8AB11974;
extern u8 D_80088E50[];
extern u16 *D_8AB16C20[];
extern s32 StageContext_GetFadeMode(void);
extern void func_8AB04AE4(void);
extern s32 func_8AB06718(s32);
extern s32 func_8AB08DBC(s32);
void func_8AB09DCC(void *arg0, s32 arg1) {
    u16 *p;
    if (*(s32 *)((u8 *)arg0 + 0xC) == 1) {
        *(s16 *)((u8 *)arg0 + 0x10) -= 1;
        if (*(s16 *)((u8 *)arg0 + 0x10) <= 0) {
            *(s16 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)((u8 *)arg0 + 0xC) = 0;
            if (*(s32 *)((u8 *)arg0 + 8) == 0) {
                p = D_8AB16C20[arg1];
                p[1] &= 0xFFFD;
            }
        }
    }
}

extern s16 D_8AB16CD8;
extern s32 func_8AB09FC4(s32);
// Close to TextMode8_HandleRowCleanupState (fragment45_2324B0.c); returns state 27, counts in
// D_8AB16CD8, updates rows with func_8AB09DCC, sets D_8AB16CB4, and returns
// func_8AB09FC4(0) once the counter reaches 31.
//@src/fragments/45/fragment45_2324B0.c
s32 func_8AB09E28(s32 phase) {
    s32 result = 27;
    s16 *counter = &D_8AB16CD8;
    s32 i;
    s32 all_wrong;
    u8 *row;

    switch (phase) {
    case 0:
        *counter = 0;
        all_wrong = 1;
        for (i = 0; i < 4; i++) {
            row = D_8AB12CB0 + i * 148;
            if (*(s16 *)row != 0 && *(s16 *)(row + 4) != 2) {
                all_wrong = 0;
            }
        }
        if (all_wrong) {
            for (i = 0; i < 4; i++) {
                row = D_8AB12CB0 + i * 148;
                func_8AB09DCC(row, i);
            }
            D_8AB16CB4 = 1;
        } else {
            for (i = 0; i < 4; i++) {
                row = D_8AB12CB0 + i * 148;
                if (*(s16 *)row != 0 && *(s16 *)(row + 4) == 0) {
                    func_8AB09DCC(row, i);
                }
            }
        }
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter == func_80001FF0() / 4) {
            func_8AB00BA4(102, 0, 0);
        }
        if (*counter >= 31) {
            result = func_8AB09FC4(0);
        }
        break;
    case 2:
        break;
    }
    return result;
}

s32 func_8AB09FBC(void) {
    return 0x1C;
}

extern s16 D_8AB16CDA;
extern s16 D_8AB12698;
extern s32 D_8AB16CBC;
extern void func_8AB01FBC(void);
extern void func_8AB03ED4(void);
extern void func_8AB012A4(void);
extern s32 func_8AB090B8(s32);
s32 func_8AB09FC4(s32 arg0)
{
    s32 result;
    int new_var;

    new_var = 1;
    result = 0x1D;
    switch (arg0) {
        case 0:
            D_8AB16CDA = 0;
            func_8AB01FBC();
            break;
        case 1:
            D_8AB16CDA += new_var;
            func_8AB03ED4();
            if (D_8AB16CDA >= 0xB) {
                func_8AB012A4();
                if (D_8AB12698 > 0) {
                    D_8AB16CBC = 1;
                }
                result = func_8AB090B8(0);
            }
            break;
    }
    return result;
}

extern s16 D_8AB16CDC;
extern void Audio_PlayDefaultSound(u16);
extern s32 func_8AB0A720(s32);
s32 func_8AB0A074(s32 arg0) {
    s16 *counter = &D_8AB16CDC;
    s32 result = 30;
    s32 i;

    switch (arg0) {
    case 0:
        *counter = 0;
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        for (i = 0; i < 4; i++) {
            D_8AB16C20[i][1] &= ~2;
        }
        func_8004C8A0(D_8AB126A8, 256, 57, 389);
        *(u16 *)((u8 *)D_8AB16A58 + 2) &= ~1;
        func_8AB00BA4(102, 0, 0);
        Audio_PlayDefaultSound(52998);
        func_800225C4(40);
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter >= 61) {
            result = func_8AB0A720(0);
        }
        break;
    }
    return result;
}

extern u8 *D_8AB16B80;
extern u8 *D_8AB16B84;
extern u8 *D_8AB16B88;
extern u8 *D_8AB16B90;
extern u8 *D_8AB16B94;
extern u8 *D_8AB16B98;
extern s16 D_8AB16CDE;
extern void func_8AB00B98(u8 *, u32);
void func_8AB0A1A4(void) {
    (*(u16 *)((u8 *)(D_8AB16B80) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B80) + (2))) & 0xFFFE);
    (*(u16 *)((u8 *)(D_8AB16B84) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B84) + (2))) & 0xFFFE);
    (*(u16 *)((u8 *)(D_8AB16B88) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B88) + (2))) & 0xFFFE);
    func_8AB00B98(D_8AB16B90, -1U);
    func_8AB00B98(D_8AB16B94, -1U);
    func_8AB00B98(D_8AB16B98, -1U);
    switch (D_8AB16CDE) {
    case 0:
        (*(u16 *)((u8 *)(D_8AB16B80) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B80) + (2))) | 1);
        func_8AB00B98(D_8AB16B90, 0xFFFF00FFU);
        return;
    case 1:
        (*(u16 *)((u8 *)(D_8AB16B84) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B84) + (2))) | 1);
        func_8AB00B98(D_8AB16B94, 0xFFFF00FFU);
        return;
    case 2:
        (*(u16 *)((u8 *)(D_8AB16B88) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B88) + (2))) | 1);
        func_8AB00B98(D_8AB16B98, 0xFFFF00FFU);
        return;
    }
}

/* mkdraft:func_8AB0A2D8 begin */
extern s16 D_8AB126A0;
extern s16 D_8AB12CB4;
extern s32 D_8AB13F28;
extern void TextReference_BuildModeSelection(void);
extern void func_800226C0(s32);
extern void func_8AB005B0(void);
extern void func_8AB01288(void);

extern s16 D_8AB12CB2;
extern s32 D_8AB12CB8;
extern s16 D_8AB12CC0;
extern s16 D_8AB12D46;
extern s16 D_8AB12D48;
extern s32 D_8AB12D4C;
extern s16 D_8AB12D54;
extern s16 D_8AB12DDA;
extern s16 D_8AB12DDC;
extern s32 D_8AB12DE0;
extern s16 D_8AB12DE8;
extern s16 D_8AB12E6E;
extern s16 D_8AB12E70;
extern s32 D_8AB12E74;
extern s16 D_8AB12E7C;
extern void *D_8AB16B8C;
extern void *D_8AB16C24;
extern void *D_8AB16C28;
extern void *D_8AB16C2C;
extern void *D_8AB16C98;
extern void *D_8AB16C9C;
extern void *D_8AB16CA0;
extern void *D_8AB16CA4;
extern s32 D_8AB16CC0;
extern s32 D_8AB16CE0;

#ifndef M2C_FIELD /* mkdraft: m2c --valid-syntax helpers */
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



s32 func_8AB0A2D8(s32 arg0) {
    s32 temp_v0;
    s32 var_sp18;
    u16 **D_8AB16C20_ptr = D_8AB16C20;
    void **D_8AB16CA4_ptr = &D_8AB16CA4;
    void **D_8AB16C28_ptr = &D_8AB16C28;
    void **D_8AB16CA0_ptr = &D_8AB16CA0;
    void **D_8AB16C9C_ptr = &D_8AB16C9C;
    void **D_8AB16C98_ptr = &D_8AB16C98;
    void **D_8AB16C24_ptr = &D_8AB16C24;
    void **D_8AB16C2C_ptr = &D_8AB16C2C;

    if (var_sp18 != 0x1F) {
        D_8AB16CE0 = var_sp18;
        var_sp18 = 0x1F;
    }
    switch (arg0) {                                 /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_8AB16CDE = 0;
        *(u16 *)((u8 *)D_8AB16A58 + 2) &= ~1;
        if (D_8AB16CC0 == 0) {
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
            func_8AB005B0();
        }
        M2C_FIELD(D_8AB16B8C, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B8C, u16 *, 2) | 2);
        M2C_FIELD(D_8AB16B90, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B90, u16 *, 2) | 2);
        M2C_FIELD(D_8AB16B94, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B94, u16 *, 2) | 2);
        M2C_FIELD(D_8AB16B98, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B98, u16 *, 2) | 2);
        M2C_FIELD((*D_8AB16C98_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C98_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) = (u16) (M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C9C_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C9C_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16CA0_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16CA0_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16CA4_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16CA4_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) & 0xFFFD);
        func_8AB04AE4();
        D_8AB126A0 = 0;
        func_8AB00BA4(0x66, 0, 0);
        func_80021ED8(0x50);
        D_8AB1269C = 0x14;
        break;
    case 1:                                         /* switch 1 */
        temp_v0 = M2C_FIELD(D_8AB13F28, u16 *, 8);
        if (temp_v0 & 0x800) {
            D_8AB16CDE -= 1;
            if (D_8AB16CDE < 0) {
                D_8AB16CDE = 2;
            }
            func_800279C4(0xCF01);
        } else if (temp_v0 & 0x400) {
            D_8AB16CDE += 1;
            if (D_8AB16CDE >= 3) {
                D_8AB16CDE = 0;
            }
            func_800279C4(0xCF01);
        } else if (M2C_FIELD(D_80087200, u16 *, 8) & 0x8000) {
            switch (D_8AB16CDE) {                   /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                func_800279C4(0xCF02);
                M2C_FIELD(D_8AB16B8C, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B8C, u16 *, 2) & 0xFFFD);
                M2C_FIELD(D_8AB16B90, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B90, u16 *, 2) & 0xFFFD);
                M2C_FIELD(D_8AB16B94, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B94, u16 *, 2) & 0xFFFD);
                M2C_FIELD(D_8AB16B98, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B98, u16 *, 2) & 0xFFFD);
                D_8AB16CDE = -1;
                func_8AB01288();
                M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) = (u16) (M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) & 0xFFFD);
                D_8AB12CB2 = 0;
                D_8AB12CB4 = 0;
                D_8AB12CB8 = 0;
                D_8AB12CBC = 0;
                D_8AB12CC0 = 0;
                M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) & 0xFFFD);
                D_8AB12D46 = 0;
                D_8AB12D48 = 0;
                D_8AB12D4C = 0;
                D_8AB12D50 = 0;
                D_8AB12D54 = 0;
                M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) & 0xFFFD);
                D_8AB12DDA = 0;
                D_8AB12DDC = 0;
                D_8AB12DE0 = 0;
                D_8AB12DE4 = 0;
                D_8AB12DE8 = 0;
                M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) & 0xFFFD);
                D_8AB12E6E = 0;
                D_8AB12E70 = 0;
                D_8AB12E74 = 0;
                D_8AB12E78 = 0;
                D_8AB12E7C = 0;
                D_8AB16CBC = 0;
                TextReference_BuildModeSelection();
                var_sp18 = func_8AB08DBC(0);
                break;
            case 1:                                 /* switch 2 */
                func_800279C4(0xCF02);
                M2C_FIELD(D_8AB11D0C, s32 *, 0x10) = 1;
                var_sp18 = func_8AB08D3C(0);
                break;
            case 2:                                 /* switch 2 */
                func_800226C0(3);
                var_sp18 = func_8AB08D3C(0);
                break;
            }
        }
        func_8AB0A1A4();
        break;
    }
    return var_sp18;
}
/* mkdraft:func_8AB0A2D8 end */

/* mkdraft:func_8AB0A720 begin */
extern s32 D_8AB11A04;
extern void *D_8AB11D00;
extern void *D_8AB16A58;
extern void *D_8AB16C98;
extern void *D_8AB16C9C;
extern void *D_8AB16CA0;
extern void *D_8AB16CA4;
extern s16 D_8AB16CAC;
extern u16 *D_8AB16C20[];
extern s32 D_8AB16CC0;
extern s16 D_8AB16CE4;
extern u8 D_8AB126A8[];
extern s16 D_8AB126A0;
extern void func_8004C54C(s32, s32);
extern void func_80021ED8(s32);
extern s32 func_8AB00618(void);
extern s32 func_8AB007E0(void);
extern void func_80027774(s32, s32);
extern s32 func_8AB0A8D4(s32);
extern void func_8AB04AE4(void);
extern void TextHighlight_AnimateScales(void);

// Retail names the D_8AB16C20[0] pointer with $v0.  This body keeps the
// discarded func_8AB007E0() result in $v0 for the rest of the element
// clears, so IDO 7.1 allocates $v1 there.  The three rewritten words differ
// only in that register field and carry no relocation.

#pragma REWRITE_FUNCTION_WORD(func_8AB0A720, 0x114, 0x8CE30000, 0x8CE20000)
#pragma REWRITE_FUNCTION_WORD(func_8AB0A720, 0x118, 0x946A0002, 0x944A0002)
#pragma REWRITE_FUNCTION_WORD(func_8AB0A720, 0x120, 0xA46E0002, 0xA44E0002)



s32 func_8AB0A720(s32 arg0) {
    s32 result = 0x20;
    s16 *counter = &D_8AB16CE4;
    void **p_c98 = &D_8AB16C98;
    void **p_c9c = &D_8AB16C9C;
    void **p_ca0 = &D_8AB16CA0;
    void **p_ca4 = &D_8AB16CA4;

    switch (arg0) {
    case 0:
        *counter = 0;
        *(u16 *)((u8 *)D_8AB16A58 + 2) = (u16)(*(u16 *)((u8 *)D_8AB16A58 + 2) & 0xFFFE);
        func_8AB04AE4();
        *((u16 *)((u8 *)(*p_c98) + 2)) = (u16)(*((u16 *)((u8 *)(*p_c98) + 2)) & 0xFFFD);
        *((u16 *)((u8 *)(*p_c9c) + 2)) = (u16)(*((u16 *)((u8 *)(*p_c9c) + 2)) & 0xFFFD);
        *((u16 *)((u8 *)(*p_ca0) + 2)) = (u16)(*((u16 *)((u8 *)(*p_ca0) + 2)) & 0xFFFD);
        *((u16 *)((u8 *)(*p_ca4) + 2)) = (u16)(*((u16 *)((u8 *)(*p_ca4) + 2)) & 0xFFFD);
        func_8004C54C(0xF, (s32)&D_8AB11A04);
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, D_8AB16CAC + 0x224);
        { void *d; d = D_8AB11D00; if (d == 0) {} } // karodo
        *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) | 1);
        D_8AB16CC0 = 1;
        func_80021ED8(0x37);
        func_80027774(0xCA0F, 0x24);
        func_8AB007E0();
        D_8AB126A0 = 0;
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 0)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 0)) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 4)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 4)) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 8)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 8)) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 12)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 12)) + 2) & 0xFFFD);
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        func_8AB00618();
        if (*counter >= 0x79) {
            *counter = 0x78;
            result = func_8AB0A8D4(0);
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB0A720 end */

extern s16 D_8AB16CE6;
extern s32 func_8AB0A2D8(s32);
s32 func_8AB0A8D4(s32 arg0) { s32 result = 0x21; s16 *count = &D_8AB16CE6; switch (arg0) { case 0: *count = 0; break; case 1: if (*count >= 0x1F) result = func_8AB0A2D8(0); *count = *count + 1; break; } return result; }
#endif
