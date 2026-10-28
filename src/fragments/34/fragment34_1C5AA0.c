#include "global.h"


#ifdef VERSION_US
// Unreferenced debug message ("%s: bug technique (%d) found!"); it opens this file's
// .rodata at 0x8850D530, ahead of func_885084EC's jump table.
const char D_8850D530[] = "%s にバグ技（%d）発見！\n";
extern u8 D_88523100[];
void func_88508490(void){s32 i=0;u8 *p=D_88523100;do{i++;p+=0x24;*(s32 *)(p-0x24)=0;*(s16 *)(p-0x20)=0;*(s16 *)(p-0x1E)=0;*(s16 *)(p-0x1C)=0;*(s16 *)(p-0x1A)=0;*(s16 *)(p-0x18)=0;*(s16 *)(p-0x16)=0;*(s16 *)(p-0x14)=0;*(s16 *)(p-0x12)=0;*(s16 *)(p-0x10)=0;*(f32 *)(p-0xC)=0.0f;*(f32 *)(p-8)=0.0f;*(f32 *)(p-4)=0.0f;}while(i!=2);}

typedef struct { s32 unk_00; s16 unk_02; s16 unk_04; s16 unk_06; s16 unk_08; s16 unk_0A; s16 unk_0C; s16 unk_0E; s16 unk_10; s16 unk_12; f32 unk_14; f32 unk_18; f32 unk_1C; } unk_D_88523100;
extern s16 D_88523034;
extern s16 D_88523048;
extern s16 D_8850D2E0[];
extern s16 D_8850D2E4[];
extern s16 D_8850D2E8[];
// Close to Pokemon Stadium's TradeCable_SetLightState; GS takes a u8 light index, uses
// 0x24-byte light records with an s32 state word, and reads the state 4 position from
// D_8850D2E4 instead of an if/else.
void func_885084EC(u8 arg0, s32 arg1) {
    unk_D_88523100 *temp_v0 = &((unk_D_88523100 *)D_88523100)[arg0];

    temp_v0->unk_00 = arg1;

    switch (arg1) {
        case 1:
            temp_v0->unk_02 = D_8850D2E0[arg0];
            temp_v0->unk_04 = D_88523034 + temp_v0->unk_02;
            temp_v0->unk_06 = 250;
            temp_v0->unk_08 = temp_v0->unk_04 - 64;
            temp_v0->unk_0A = 174;
            temp_v0->unk_0C = 128;
            temp_v0->unk_0E = 72;
            temp_v0->unk_10 = 0;
            temp_v0->unk_12 = 0;
            temp_v0->unk_14 = 1.0f;
            temp_v0->unk_18 = 0.0f;
            temp_v0->unk_1C = 9.0f;
            break;

        case 2:
            temp_v0->unk_08 = 0;
            temp_v0->unk_0A = 0;
            temp_v0->unk_0C = 0;
            temp_v0->unk_0E = 0;
            temp_v0->unk_06 = 190;
            break;

        case 3:
            temp_v0->unk_08 = 0;
            temp_v0->unk_0A = 0;
            temp_v0->unk_0C = 0;
            temp_v0->unk_0E = 0;
            temp_v0->unk_10 = D_88523048;
            break;

        case 4:
            temp_v0->unk_02 = D_8850D2E4[arg0];
            temp_v0->unk_04 = D_88523034 + temp_v0->unk_02;
            temp_v0->unk_14 = 0.75f;
            break;

        case 5:
            temp_v0->unk_12 = 0;
            temp_v0->unk_08 = temp_v0->unk_04 - 64;
            if (temp_v0->unk_08 < 0) {
                temp_v0->unk_08 = 0;
            }
            temp_v0->unk_0A = 194;
            temp_v0->unk_0C = 128;
            temp_v0->unk_0E = 60;
            break;

        case 6:
            temp_v0->unk_02 = D_8850D2E8[arg0];
            temp_v0->unk_04 = D_88523034 + temp_v0->unk_02;
            temp_v0->unk_06 = 160;
            temp_v0->unk_08 = temp_v0->unk_04 - 64;
            if (temp_v0->unk_08 < 0) {
                temp_v0->unk_08 = 0;
            }
            temp_v0->unk_0A = 194;
            temp_v0->unk_0C = 128;
            temp_v0->unk_0E = 60;
            temp_v0->unk_10 = 0;
            temp_v0->unk_12 = 0;
            temp_v0->unk_14 = 0.75f;
            temp_v0->unk_18 = 0.0f;
            temp_v0->unk_1C = 1.0f;
            break;

        case 8:
            temp_v0->unk_02 = D_8850D2E8[arg0];
            temp_v0->unk_04 = D_88523034 + temp_v0->unk_02;
            temp_v0->unk_06 = 160;
            temp_v0->unk_08 = temp_v0->unk_04 - 64;
            if (temp_v0->unk_08 < 0) {
                temp_v0->unk_08 = 0;
            }
            temp_v0->unk_0A = 194;
            temp_v0->unk_0C = 128;
            temp_v0->unk_0E = 60;
            temp_v0->unk_10 = 0;
            temp_v0->unk_12 = 0;
            temp_v0->unk_14 = 0.75f;
            temp_v0->unk_18 = 0.0f;
            temp_v0->unk_1C = 1.0f;
            break;
    }
}

extern u8 D_88523100[];
extern s16 D_88523034;
// Trade cable sequence record: Pokemon Stadium's TradeCableState with an s32 state word and
// without that struct's s16 at 0x0E. func_8850A0EC writes every field, func_8850A3F0 and
// func_8850A710 count unk_18 down, and func_8850A8BC sets and clears bits of the u16 unk_0E.
typedef struct { s32 unk_00; s16 unk_04; s16 unk_06; s16 unk_08; s16 unk_0A; s16 unk_0C; u16 unk_0E; f32 unk_10; u16 unk_14; u16 unk_16; s16 unk_18; } unk_D_88523030;
extern unk_D_88523030 D_88523030;
extern f32 D_80087E50[];
s32 func_8850CED8(s32);
extern void func_8850A0EC(s32);
void func_885084EC(u8, s32);
void func_88508780(u8 *arg0) {
    *(s16 *)(arg0 + 8) = *(s16 *)(arg0 + 8) - 2;
    if (*(s16 *)(arg0 + 8) < 0xBF) {
        func_885084EC((u8)((arg0 - D_88523100) / 0x24), 2);
    }
}

/* mkdraft:func_885087D4 begin */
extern f32 D_80087E50[];

void func_885087D4(unk_D_88523100 *arg0) {
    arg0->unk_04 = D_88523034 + arg0->unk_02;
    arg0->unk_06 = (s16)(D_80087E50[(u16)(arg0->unk_12) >> 4] * 3.0f + ((D_80087E50[(u16)(arg0->unk_12) >> 4] * 3.0f) > 0.0f ? 0.5f : -0.5f)) + 0xBE;

    arg0->unk_12 += 0x800;

    arg0->unk_1C -= 0.2f;
    if (arg0->unk_1C < 1.0f) {
        arg0->unk_1C = 1.0f;
    }
}
/* mkdraft:func_885087D4 end */

// Close to Pokemon Stadium's TradeCable_UpdateLightSlideIn, computed in floats instead of
// integer division. As the sequence countdown D_88523030.unk_18 (treated as 0 while it exceeds
// arg0->unk_10) falls, unk_02 eases to 80 for light 0 or 566 for light 1, unk_06 settles at 210
// plus a sine pulse, and unk_14 falls to 0.75; below 1 the light enters state 4.
void func_8850889C(unk_D_88523100 *arg0) {
    s16 var_v1 = D_88523030.unk_18;
    s32 light_index;
    s32 var_a1;
    s16 var_a2;
    f32 var_f12;
    f32 var_f2;

    if (arg0->unk_10 < var_v1) {
        var_v1 = 0;
    }
    light_index = (u8)((s32)((u8 *)arg0 - D_88523100) / 0x24);
    if (light_index == 0) {
        arg0->unk_02 = (s16)((80.0f - (f32)(var_v1 * -20) / arg0->unk_10) + ((80.0f > (f32)(var_v1 * -20) / arg0->unk_10) ? 0.5f : -0.5f));
    } else {
        arg0->unk_02 = (s16)((566.0f - (f32)(var_v1 * -146) / arg0->unk_10) + ((566.0f > (f32)(var_v1 * -146) / arg0->unk_10) ? 0.5f : -0.5f));
    }
    var_a1 = var_v1 * 20;
    var_f12 = (f32)var_a1 / arg0->unk_10;
    arg0->unk_04 = D_88523030.unk_04 + arg0->unk_02;
    var_a2 = (s16)((210.0f - var_f12) + ((210.0f > var_f12) ? 0.5f : -0.5f));
    var_f2 = 2.0f - (var_v1 * -1.0f) / arg0->unk_10;
    arg0->unk_06 = (s16)(D_80087E50[(u16)arg0->unk_12 >> 4] * var_f2 + ((D_80087E50[(u16)arg0->unk_12 >> 4] * var_f2) > 0.0f ? 0.5f : -0.5f)) + var_a2;
    arg0->unk_12 += 0x800;
    arg0->unk_14 = 0.75f - (var_v1 * -0.25f) / arg0->unk_10;
    if (var_a1 < 20) {
        func_885084EC(light_index, 4);
    }
}

void TradeCable_UpdateLightWaitPulse(unk_D_88523100 *arg0) {
    arg0->unk_04 = D_88523034 + arg0->unk_02;
    arg0->unk_06 = (s16)(2.0f * D_80087E50[(u16)(arg0->unk_12) >> 4] + ((2.0f * D_80087E50[(u16)(arg0->unk_12) >> 4]) > 0.0f ? 0.5f : -0.5f)) + 0xD2;

    arg0->unk_12 += 0x800;
}
// Close to Pokemon Stadium's TradeCable_UpdateLightShrinkOut; GS light records are 0x24 bytes
// with an s32 state word.
void func_88508B98(unk_D_88523100 *arg0) {
    arg0->unk_04 = D_88523034 + arg0->unk_02;
    arg0->unk_12--;
    arg0->unk_06 += arg0->unk_12;
    if (arg0->unk_06 < 121) {
        arg0->unk_00 = 0;
        arg0->unk_06 = 120;
    }
}

extern u8 D_88523100[];
extern s32 MathUtil_Random16(void);
void func_88508BEC(u8 *arg0) {
    *(s16 *)(arg0 + 0x14) = *(s16 *)(arg0 + 0x14) + 1;
    *(s16 *)(arg0 + 8) = *(s16 *)(arg0 + 0x14) + *(s16 *)(arg0 + 8);
    if (*(s16 *)(arg0 + 8) >= 0xD2) {
        *(s32 *)(arg0 + 0) = 7;
        *(s16 *)(arg0 + 8) = 0xD2;
        *(f32 *)(arg0 + 0x1C) = (f32)(MathUtil_Random16() % 16);
        *(s16 *)(arg0 + 0x14) = MathUtil_Random16();
        if (((s32)(arg0 - D_88523100) / 0x24) == 0) {
            D_88523030.unk_0E &= 0xFFDF;
        }
    }
}

void TradeCable_UpdateLightFlashPulse(unk_D_88523100 *arg0) {
    arg0->unk_04 = D_88523034 + arg0->unk_02;
    arg0->unk_06 = (s16)(2.0f * D_80087E50[(u16)(arg0->unk_12) >> 4] + ((2.0f * D_80087E50[(u16)(arg0->unk_12) >> 4]) > 0.0f ? 0.5f : -0.5f)) + 0xD2;

    arg0->unk_12 += 0x800;
}
// Light fade-in (unk_1C rises by 0.2 to 9.0) with the sine pulse of
// TradeCable_UpdateLightWaitPulse, then a hold that clears the light once unk_06 reaches 260.
// Same body as Pokemon Stadium 1 TradeCable_UpdateLightFadeInThenPulse.
void func_88508D34(unk_D_88523100 *arg0) {
    if (arg0->unk_1C < 9.0f) {
        arg0->unk_04 = D_88523034 + arg0->unk_02;
        arg0->unk_06 = (s16)(2.0f * D_80087E50[(u16)(arg0->unk_12) >> 4] + ((2.0f * D_80087E50[(u16)(arg0->unk_12) >> 4]) > 0.0f ? 0.5f : -0.5f)) + 210;
        arg0->unk_12 += 0x800;

        arg0->unk_1C += 0.2f;
        if (arg0->unk_1C >= 9.0f) {
            arg0->unk_1C = 9.0f;
        }
    } else {
        arg0->unk_1C = 9.0f;
        arg0->unk_06 += 2;
        if (arg0->unk_06 >= 260) {
            arg0->unk_00 = 0;
            arg0->unk_06 = 0;
        }
    }
}

void func_8850889C(unk_D_88523100 *arg0);
// Close to Pokemon Stadium's TradeCable_UpdateLights; GS light records are 0x24 bytes
// with an s32 state word, and the phase wrap is a plain signed divide by 16.
void func_88508E34(void) {
    s32 var_s1;
    unk_D_88523100 *var_s0;
    s32 i;

    var_s0 = (unk_D_88523100 *)D_88523100;

    for (i = 0; i < 2; i++, var_s0++) {
        var_s1 = 1;

        switch (var_s0->unk_00) {
            case 0:
                var_s1 = 0;
                break;

            case 1:
                func_88508780((u8 *)var_s0);
                break;

            case 2:
                func_885087D4(var_s0);
                break;

            case 3:
                func_8850889C(var_s0);
                break;

            case 4:
                TradeCable_UpdateLightWaitPulse(var_s0);
                break;

            case 5:
                func_88508B98(var_s0);
                break;

            case 6:
                func_88508BEC((u8 *)var_s0);
                break;

            case 7:
                TradeCable_UpdateLightFlashPulse(var_s0);
                break;

            case 8:
                func_88508D34(var_s0);
                break;
        }

        if (var_s1 != 0) {
            var_s0->unk_18 += var_s0->unk_1C;
            var_s0->unk_18 -= ((s32)var_s0->unk_18 / 16) * 16;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_88508F78.s")

extern void Gfx_SetScissorRect(Gfx **, s32, s32, s32, s32);
extern void func_88508F78(s32, s32, s32, s16);
extern Gfx *D_800D0510;
extern u8 D_88523148;
extern u8 D_88523100[];
void func_88509290(void) {
    s32 changed = 0;
    s32 limit = 2;
    u8 *p; s32 i = 0; p = D_88523100; do {
        if (*(s32 *)(p + 0) != 0) {
            if ((*(s16 *)(p + 0xE) != 0) && (*(s16 *)(p + 0x10) != 0)) {
                *(s16 *)(p + 0xA) = *(s16 *)(p + 6) - 0x40;
                changed = 1;
                if (*(s16 *)(p + 0xA) < 0) {
                    *(s16 *)(p + 0xA) = 0;
                }
                Gfx_SetScissorRect(&D_800D0510, *(s16 *)(p + 0xA), *(s16 *)(p + 0xC), *(s16 *)(p + 0xE), *(s16 *)(p + 0x10));
            }
            func_88508F78(*(s16 *)(p + 6), *(s16 *)(p + 8), *(s32 *)(p + 0x18), (s16)(*(f32 *)(p + 0x1C) + ((0.0f < *(f32 *)(p + 0x1C)) ? 0.5f : -0.5f)));
        }
        i++;
        p += 0x24;
        if (i == limit) break;
    } while (1);
    if (changed != 0) {
        u8 *q = &D_88523148;
        Gfx_SetScissorRect(&D_800D0510, *(s16 *)(q + 0), *(s16 *)(q + 2), *(s16 *)(q + 4), *(s16 *)(q + 6));
    }
}

extern u8 D_88523050[];
void func_885093F0(void) { s32 i = 0; u8 *ptr = D_88523050; do { i += 1; ptr += 0x50; *(s32 *)(ptr - 0x50) = 0; } while (i != 2); }

typedef struct { s16 unk_00; s16 unk_02; s16 unk_04; } unk_func_88509418_012;
// Same layout as unk_D_88523050 (declared further down in this file): one ball
// record = state word, seven s16 fields, ten 6-byte trail ghosts. Declaring an
// equivalent type here keeps this function self-contained ahead of that typedef.
typedef struct {
    s32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    unk_func_88509418_012 unk_12[10];
} unk_func_88509418;

// arg0 must stay u8: ugen then homes the incoming register framelessly
// (sw a0, 0(sp)) and narrows it in place (andi a0, a0, 0xFF); a wider
// parameter type drops the home store. The ball base is indexed through
// the cast type instead of an explicit arg0 * 80: with an explicit
// multiply uopt copies the narrowed arg0 out of a0 before the base addu,
// which recolors the pointer and turns the ghost loop's strength-reduced
// pointer into a byte-offset counter plus a per-iteration addu.
void func_88509418(u8 arg0, s32 arg1) {
    unk_func_88509418 *temp_v0 = &((unk_func_88509418 *)D_88523050)[arg0];
    s32 i;

    temp_v0->unk_00 = arg1;
    switch (arg1) {
    case 1:
        temp_v0->unk_08 = 40;
        temp_v0->unk_06 = 90;
        temp_v0->unk_04 = (arg0 * 90) + 250;
        temp_v0->unk_0E = 0;
        temp_v0->unk_10 = 0;
        for (i = 0; i < 10; i++) {
            // Chained on purpose: the assignment to unk_00 re-reads unk_02
            // through memory (the target's lh right after the sh), rather
            // than reusing the constant.
            temp_v0->unk_12[i].unk_00 = temp_v0->unk_12[i].unk_02 = 0;
            temp_v0->unk_12[i].unk_04 = 0;
        }
        break;
    case 2:
        temp_v0->unk_08 = 30;
        temp_v0->unk_0A = 0;
        temp_v0->unk_0E = 0xFF;
        break;
    case 3:
        temp_v0->unk_08 = 0;
        temp_v0->unk_0A = 0;
        temp_v0->unk_0C = 0;
        temp_v0->unk_0E = 0xFF;
        break;
    }
}
void func_88509538(u8 *arg0) {
    s32 var_v0;
    f32 var_fv0;
    f32 var_fv1;
    f32 var_ft3;

    (*(s16 *)(arg0 + 8))--;
    var_v0 = *(s16 *)(arg0 + 8);
    var_fv0 = (f32)(var_v0 * 255) / 40.0f;
    var_ft3 = 255.0f - var_fv0;
    var_fv1 = var_fv0 < 255.0f ? 0.5f : -0.5f;
    *(s16 *)(arg0 + 14) = (s32)(var_fv1 + var_ft3);
    if (var_v0 <= 0) {
        func_88509418((s32)(arg0 - D_88523050) / 80, 2);
    }
}

extern f32 D_80088E50[];
extern void func_800226C0(s32);
// Close to Pokemon Stadium's TradeCable_UpdateBallSpinPulse; GS uses 0x50-byte ball records,
// keeps the ball index in a u8 for func_88509418, and plays sound 0x144.
void func_885095EC(unk_func_88509418 *ball) {
    u8 sp1C;

    if (ball->unk_08 > 0) {
        ball->unk_08--;
    }

    ball->unk_0A += 0x200;

    ball->unk_0E = ((D_80088E50[(u16)ball->unk_0A >> 4] * 0.5f) + 0.5f) * 255.0f +
                   ((((D_80088E50[(u16)ball->unk_0A >> 4] * 0.5f) + 0.5f) * 255.0f) > 0.0f ? 0.5f : -0.5f);

    if ((ball->unk_08 <= 0) && (ball->unk_0E >= 0xFF)) {
        sp1C = (ball - (unk_func_88509418 *)D_88523050);
        func_88509418(sp1C, 3);
        if (sp1C == 0) {
            func_800226C0(324);
        }
    }
}

typedef struct { s16 unk_00; s16 unk_02; s16 unk_04; } unk_D_88523050_012;
typedef struct { s32 unk_00; s16 unk_04; s16 unk_06; s16 unk_08; s16 unk_0A; s16 unk_0C; s16 unk_0E; s16 unk_10; unk_D_88523050_012 unk_12[10]; } unk_D_88523050;

void TradeCable_SpawnBallTrailGhost(unk_D_88523050 *arg0) {
    s32 i;
    unk_D_88523050_012 *var_v0 = NULL;

    for (i = 0; i < 10; i++) {
        if (arg0->unk_12[i].unk_04 == 0) {
            break;
        }
    }

    if (i < 10) {
        var_v0 = &arg0->unk_12[i];
    }

    if (var_v0 != NULL) {
        var_v0->unk_00 = arg0->unk_04;
        var_v0->unk_02 = arg0->unk_06;
        var_v0->unk_04 = 0x14;
        arg0->unk_10++;
    }
}
// Counts down each live trail ghost timer (unk_04); a ghost reaching 0 decrements the live
// ghost count unk_10. Same body as Pokemon Stadium 1 TradeCable_UpdateBallTrailGhosts
// (src/fragments/trade_machine/trade_machine_2942C0.c there).
void func_8850974C(u8 *arg0) {
    unk_D_88523050 *ball = (unk_D_88523050 *)arg0;
    s32 i;
    unk_D_88523050_012 *ptr;

    for (i = 0, ptr = &ball->unk_12[0]; i < 10; i++, ptr++) {
        if (ptr->unk_04 != 0) {
            ptr->unk_04--;
            if (ptr->unk_04 <= 0) {
                ball->unk_10--;
            }
        }
    }
}

extern void func_8850974C(u8 *);
extern void TradeCable_SpawnBallTrailGhost(unk_D_88523050 *);
extern void func_885084EC(u8, s32);
void func_88509870(u8 *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;

    if (*(s16 *)(arg0 + 0x10) > 0) {
        func_8850974C(arg0);
    }
    temp_v0 = *(s16 *)(arg0 + 4);
    if ((temp_v0 < 0xA0) || (temp_v0 >= 0x1C3)) {
        if (*(s16 *)(arg0 + 0x10) == 0) {
            *(s32 *)(arg0 + 0) = 0;
            func_885084EC((((s32)(arg0 - D_88523050) / 80) ^ 1) & 0xFF, 6);
        }
    } else {
        temp_v0_2 = *(s16 *)(arg0 + 8);
        if (temp_v0_2 > 0) {
            *(s16 *)(arg0 + 8) = temp_v0_2 - 1;
        }
        temp_v0_2 = *(s16 *)(arg0 + 8);
        if (temp_v0_2 == 0) {
            if (*(s16 *)(arg0 + 0x10) < 0xA) {
                TradeCable_SpawnBallTrailGhost((unk_D_88523050 *)arg0);
                *(s16 *)(arg0 + 8) = 2;
            }
        }
        if ((((s32)(arg0 - D_88523050) / 80) & 0xFF) != 0) {
            *(s16 *)(arg0 + 0xC) = *(s16 *)(arg0 + 0xC) - 1;
        } else {
            *(s16 *)(arg0 + 0xC) = *(s16 *)(arg0 + 0xC) + 1;
        }
        *(s16 *)(arg0 + 4) = *(s16 *)(arg0 + 0xC) + *(s16 *)(arg0 + 4);
    }
}

extern u8 D_88523050[];
extern s32 D_88523018;
extern s32 func_8850CED8(s32);
extern void func_88509538(u8 *);
extern void func_885095EC(unk_func_88509418 *);
extern void func_88509870(u8 *);
extern void func_88509418(u8, s32);
extern void func_800226C0(s32);
void func_8850998C(void) {
    s32 i;
    u8 *ptr;
    s32 state;

    ptr = D_88523050;
    i = 0;
    do {
        state = *(s32 *)ptr;
        switch (state) {
        case 1:
            func_88509538(ptr);
            break;
        case 2:
            func_885095EC((unk_func_88509418 *)ptr);
            break;
        case 3:
            func_88509870(ptr);
            break;
        }
        i += 1;
        ptr += 0x50;
    } while (i != 2);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_88509A38.s")

extern u8 D_885230F0;
void func_8850A0A0(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_88509E74(void) {
    if (D_885230F0 == 0) {
        func_8850A0A0(0x200, 0xB9, 0x4C, 0x5A);
        return;
    }
    func_8850A0A0(0x2D, 0xB9, 0x4C, 0x5A);
}

extern u8 D_8850D6D8;
void func_8850A0A0(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
extern s32 D_880068B8;
extern void func_8004D878(s32, s32, s32);
void func_8850A0A0(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
void func_88509EC8(void) {
    func_8850A0A0(0, 0, 0x280, 0x1E0);
    D_880068B8 = 1;
    if ((*(u8 *)((u8 *)(&D_885230F0) + (8))) != 0) {
        func_8004D878((s32) (((*(u8 *)((u8 *)(&D_885230F0) + (0))) * 0xA960) + 8 + &D_8850D6D8), 0, (*(s32 *)((u8 *)(&D_885230F0) + (4))));
    }
}

extern void func_88900494();
extern s32 D_880068B4;

void func_88509F40(void) {
    D_880068B4 = 1;
    func_88900494();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_88509F68.s")

extern u8 D_88523148;
void func_8850A0A0(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    (*(s16 *)((u8 *)(&D_88523148) + (0))) = arg0;
    (*(s16 *)((u8 *)(&D_88523148) + (2))) = arg1;
    (*(s16 *)((u8 *)(&D_88523148) + (4))) = arg2;
    (*(s16 *)((u8 *)(&D_88523148) + (6))) = arg3;
}

// Close to Pokemon Stadium's TradeCable_SetSequenceState: states below 18 are stored in
// D_88523030.unk_00, then each state sets the countdown unk_18, the flag bits in unk_0E or
// light states (func_885084EC). GS state 0 also calls func_8850A0A0 with a 640x480 rectangle.
void func_8850A0EC(s32 arg0) {
    s32 pad; // FAKE: unreferenced stack slot (removal diff score 8).
    unk_D_88523100 *light;
    s32 i;

    if (arg0 < 18) {
        D_88523030.unk_00 = arg0;
    }

    switch (arg0) {
        case 0:
            D_88523030.unk_04 = -20;
            D_88523030.unk_06 = 24;
            D_88523030.unk_10 = 1.5f;
            D_88523030.unk_08 = 180;
            D_88523030.unk_0A = 228;
            D_88523030.unk_0C = 170;
            D_88523030.unk_14 = 128;
            D_88523030.unk_16 = 64;
            D_88523030.unk_0E = 0;
            D_88523030.unk_0E |= 0xF;
            func_8850A0A0(0, 0, 640, 480);
            break;
        case 1:
            D_88523030.unk_18 = 30;
            D_88523030.unk_0E |= 0x10;
            func_800226C0(320);
            break;
        case 2:
        case 4:
            D_88523030.unk_18 = 10;
            break;
        case 3:
            D_88523030.unk_18 = 2;
            break;
        case 6:
            D_88523030.unk_18 = 10;
            break;
        case 7:
            D_88523030.unk_18 = 2;
            break;
        case 8:
        case 9:
            D_88523030.unk_18 = 10;
            light = (unk_D_88523100 *)D_88523100;
            for (i = 0; i < 2; i++, light++) {
                if (light->unk_00 != 0) {
                    func_885084EC(i, 3);
                }
            }
            break;
        case 11:
            func_885084EC(0, 8);
            func_885084EC(1, 8);
            break;
        case 12:
            D_88523030.unk_18 = 10;
            break;
        case 14:
            D_88523030.unk_18 = 10;
            break;
        case 16:
            D_88523030.unk_18 = 10;
            break;
        case 5:
        case 17:
            D_88523030.unk_18 = 30;
            break;
        case 19:
            func_885084EC(0, 1);
            func_800226C0(322);
            break;
        case 20:
            func_885084EC(1, 1);
            func_800226C0(322);
            break;
        case 21:
            if (1) {} // karodo: removal diff score 1359; Stadium 1's TradeCable_SetSequenceState has empty ifs in this case too.
            func_885084EC(0, 5);
            func_885084EC(1, 5);
            break;
    }
}

void func_8850A2F4(void) {
    D_88523030.unk_18--;
    D_88523030.unk_14 = (s16)((32.0f - (D_88523030.unk_18 * -96) / 30.0f) + ((32.0f > (D_88523030.unk_18 * -96) / 30.0f) ? 0.5f : -0.5f));
    D_88523030.unk_16 = (s16)((128.0f - (D_88523030.unk_18 * 64) / 30.0f) + ((128.0f > (D_88523030.unk_18 * 64) / 30.0f) ? 0.5f : -0.5f));
    if (D_88523030.unk_18 <= 0) {
        func_8850A0EC(2);
    }
}

// Same body as Pokemon Stadium's TradeCable_UpdateSequenceSlideVertical, computed in floats:
// counts unk_18 down, interpolates unk_04, unk_06, unk_10 and unk_0C (state 4 runs the
// countdown in reverse), and at 0 moves to sequence state 5 (from state 4) or 3.
void func_8850A3F0(void) {
    s16 var_v0;

    D_88523030.unk_18--;
    var_v0 = D_88523030.unk_18;
    if (D_88523030.unk_00 == 4) {
        var_v0 = 10 - var_v0;
    }
    D_88523030.unk_04 = (s16)((190.0f - (var_v0 * 210) / 10.0f) + ((190.0f > (var_v0 * 210) / 10.0f) ? 0.5f : -0.5f));
    D_88523030.unk_06 = (s16)((-43.0f - (var_v0 * -67) / 10.0f) + ((-43.0f > (var_v0 * -67) / 10.0f) ? 0.5f : -0.5f));
    D_88523030.unk_10 = 1.9f - (var_v0 * 0.39999998f) / 10.0f;
    D_88523030.unk_0C = (s16)((167.0f - (var_v0 * -3) / 10.0f) + ((167.0f > (var_v0 * -3) / 10.0f) ? 0.5f : -0.5f));
    if (D_88523030.unk_18 <= 0) {
        if (D_88523030.unk_00 == 4) {
            func_8850A0EC(5);
        } else {
            func_8850A0EC(3);
        }
    }
}

extern u8 D_88523100[];
extern s16 D_88523034;
extern f32 D_80087E50[];
s32 func_8850CED8(s32);
extern void func_8850A0EC(s32);
void func_885084EC(u8, s32);
void func_8850A5CC(void) {
    s16 v = D_88523030.unk_18;
    if (v > 0) {
        D_88523030.unk_18 = v - 1;
    }
    if (func_8850CED8(4) != 0) {
        func_8850A0EC(6);
    }
}

extern void func_8850A0EC(s32);
void func_8850A614(void) {
    D_88523030.unk_18--;
    D_88523030.unk_04 = (s16)((-420.0f - (D_88523030.unk_18 * -610) / 10.0f) + ((-420.0f > (D_88523030.unk_18 * -610) / 10.0f) ? 0.5f : -0.5f));
    if (D_88523030.unk_18 <= 0) {
        func_8850A0EC(7);
    }
}

void func_8850A6C8(void) {
    s16 v = D_88523030.unk_18;
    if (v > 0) {
        D_88523030.unk_18 = v - 1;
    }
    if (func_8850CED8(5) != 0) {
        func_8850A0EC(9);
    }
}

// Same body as Pokemon Stadium's TradeCable_UpdateSequenceSlideBack, computed in floats;
// at 0 it moves to sequence state 5 (from state 8) or 10.
void func_8850A710(void) {
    D_88523030.unk_18--;
    D_88523030.unk_04 = (s16)((-20.0f - (D_88523030.unk_18 * 400) / 10.0f) + ((-20.0f > (D_88523030.unk_18 * 400) / 10.0f) ? 0.5f : -0.5f));
    D_88523030.unk_06 = (s16)((24.0f - (D_88523030.unk_18 * 67) / 10.0f) + ((24.0f > (D_88523030.unk_18 * 67) / 10.0f) ? 0.5f : -0.5f));
    D_88523030.unk_10 = 1.5f - (D_88523030.unk_18 * -0.39999998f) / 10.0f;
    D_88523030.unk_0C = (s16)((170.0f - (D_88523030.unk_18 * 3) / 10.0f) + ((170.0f > (D_88523030.unk_18 * 3) / 10.0f) ? 0.5f : -0.5f));
    if (D_88523030.unk_18 <= 0) {
        if (D_88523030.unk_00 == 8) {
            func_8850A0EC(5);
        } else {
            func_8850A0EC(10);
        }
    }
}

void func_8850A8BC(void) {
    if (D_88523018 == 1) {
        D_88523030.unk_0E &= 0xFFF6;
    } else {
        D_88523030.unk_0E |= 9;
    }
    if (func_8850CED8(7) != 0) {
        if ((D_88523030.unk_0E & 0x20) == 0) {
            D_88523030.unk_0E |= 0x20;
            func_88509418(0, 1);
            func_88509418(1, 1);
            func_800226C0(0x143);
        }
    }
}

extern void func_8850A0EC(s32);
s32 func_8850CED8(s32);

void func_8850A958(void) {
    if (func_8850CED8(7) != 0) {
        func_8850A0EC(5);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850A988.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850AAA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850ABCC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850ACD8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850AEA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850AFDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850B2DC.s")

s32 func_8004C990(s32, s32);
extern void func_8850B2DC(s32, s32, s16, s16, f32, s32, s32, s32, s32, s32);

void func_8850B914(s16 arg0, s16 arg1, f32 arg2) {
    func_8850B2DC(func_8004C990(0x147, 0), 0, arg0, arg1, arg2, 0, 0xE4, 0, 0xE4, -0x10);
}

s32 func_8004C990(s32, s32);

void func_8850B980(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5) {
    func_8850B2DC(func_8004C990(0x148, 1), 0, arg0, arg1, arg2, (s32) arg3, (s32) arg4, (s32) arg5, 0x64, 0);
}

extern Gfx *D_800D0510;
extern u8 D_8850D300[];
extern s32 func_8004C990(s32, s32);
extern void func_8850B2DC(s32, s32, s16, s16, f32, s32, s32, s32, s32, s32);
void func_8850B9F4(s16 arg0, s16 arg1, f32 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    s32 local[4];
    gSPDisplayList(D_800D0510++, D_8850D300);
    gDPSetPrimColor(D_800D0510++, 0, 0, 0x64, 0x64, 0xFF, arg6);
    local[0] = func_8004C990(0x148, 0);
    func_8850B2DC(local[0], func_8004C990(0x148, 1), arg0, arg1, arg2, arg3, arg4, arg5, 0x64, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850BACC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850BDE8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850C514.s")

s32 func_800071A4(s32, s32, s32, s32, s32);
extern void func_88508490();
extern s32 D_8852304C;

void func_8850C948(void) {
    func_8850A0EC(0);
    func_88508490();
    func_885093F0();
    D_8852304C = func_800071A4(0, 2, 0x20, 0x20, 1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C5AA0/func_8850C998.s")

s32 func_8850CED8(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    switch (arg0) {
        case 1:
            if ((*(s32 *)((u8 *)&D_88523030 + 0) == 3) && (*(s16 *)((u8 *)&D_88523030 + 0x18) == 0)) {
                var_v1 = 1;
            }
            break;
        case 2:
            if ((*(s32 *)((u8 *)&D_88523030 + 0) == 7) && (*(s16 *)((u8 *)&D_88523030 + 0x18) == 0)) {
                var_v1 = 1;
            }
            break;
        case 3:
            if (*(s32 *)((u8 *)&D_88523030 + 0) == 0) {
                var_v1 = 1;
            }
            break;
        case 4:
            if ((*(s32 *)(D_88523100 + 0) == 2) && (*(f32 *)(D_88523100 + 0x20) <= 1.0f)) {
                var_v1 = 1;
            }
            break;
        case 5:
            if ((*(s32 *)(D_88523100 + 0x24) == 2) && (*(f32 *)(D_88523100 + 0x44) <= 1.0f)) {
                var_v1 = 1;
            }
            break;
        case 6:
            if (*(s32 *)((u8 *)&D_88523030 + 0) == 0xA) {
                var_v1 = 1;
            }
            break;
        case 8:
            if ((*(s32 *)(D_88523100 + 0) == 7) && (*(s32 *)(D_88523100 + 0x24) == 7)) {
                var_v1 = 1;
            }
            break;
        case 7:
        case 9:
            if ((*(s32 *)(D_88523100 + 0) == 0) && (*(s32 *)(D_88523100 + 0x24) == 0)) {
                var_v1 = 1;
            }
            break;
        case 10:
            if (*(s32 *)((u8 *)&D_88523030 + 0) == 0) {
                var_v1 = 1;
            }
            break;
    }
    return var_v1;
}
#endif
