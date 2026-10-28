#include "global.h"


#ifdef VERSION_US
/* mkdraft:GeoCallback_InitCamera begin */
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
extern f32 D_8690EB3C;
extern f32 D_8690EB40;
extern f32 D_8690EB44;
extern f32 D_8690EB48;

s32 GeoCallback_InitCamera(s32 arg0, void *arg1) {
    s16 pad;
    GeoCamera_SetPerspective(arg1, D_8690EB48, 100.0f, 12800.0f);
    func_80038E14(arg1, 0, (__sinf(D_8690EB40) * D_8690EB3C) + 400.0f + D_8690EB44, __cosf(D_8690EB40) * D_8690EB3C, 0.0f, D_8690EB44, 0.0f, 0);
    return 1;
}
/* mkdraft:GeoCallback_InitCamera end */
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_869000D0(s32 arg0, void *arg1) {
    s16 pad;
    s32 x;
    s16 y;
    s16 z;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &x, &y, &z);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(y + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(z - 0x2000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86900138(s32 arg0, void *arg1) {
    s16 pad;
    s32 x;
    s16 y;
    s16 z;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &x, &y, &z);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - y);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(z + 0x6000);
    }
    return 0;
}
void func_86900138_padding(void) {}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_869001AC.s")
#endif

#ifdef VERSION_US
extern s32 D_8690E120;
extern u8 D_8690F9E8;
extern u8 D_86919040;
extern u8 D_869195E0;
extern u8 *D_8691AD58;
extern s32 D_8690E11C;
extern s32 func_87F08208(void *);
extern void ModelAnim_SetAnimation(void *, s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void Audio_PlayDefaultSound(s32);
extern void func_869015F0(s32);
extern void func_800226C0(s32);
void func_869003C8(void) {
    u8 *var_s0;
    s32 temp_v0;

    D_8690E120 = 0;
    temp_v0 = func_87F08208(&D_8690F9E8);
    switch (temp_v0) {
    case 1:
        var_s0 = &D_86919040;
        do {
            ModelAnim_SetAnimation(var_s0, 2);
            ModelAnim_SetFrame(var_s0, 0xB);
            var_s0 += 0x168;
        } while (var_s0 != &D_869195E0);
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)D_8691AD58 = 2;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        D_8690E11C = 0;
        return;
    case 2:
        func_869015F0(0);
        func_800226C0(3);
        D_8690E11C = 1;
        return;
    }
}
#endif

void func_869004A4(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_869004AC.s")
#endif

#ifdef VERSION_US
extern u16 D_8691ADB0[];
extern u16 D_80094904;
extern u8 D_86919D00[];
s32 func_86900698(s32 arg0, u8 *arg1) {
    s32 idx;
    u8 *rec;

    idx = *(s32 *)(arg1 + 0x14);
    if (D_80094904 != D_8691ADB0[idx]) {
        if (arg0 != 0 && arg0 == 2 && *(s32 *)D_8691AD58 != 6) {
            rec = D_86919D00 + idx * 0x168;
            *(f32 *)(arg1 + 0x24) = *(f32 *)(rec + 0xDC);
            *(f32 *)(arg1 + 0x28) = *(f32 *)(rec + 0xE0);
            *(f32 *)(arg1 + 0x2C) = *(f32 *)(rec + 0xE4);
            *(s16 *)(arg1 + 0x20) = *(s16 *)(rec + 0x20);
        }
    }
    D_8691ADB0[idx] = D_80094904;
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690073C.s")
#endif

#ifdef VERSION_US
extern s32 D_8690F9E0;
extern void func_80043E70(s32, s32);
extern Gfx *D_800D0510;
extern void func_800088DC(void);
extern void GfxImage_FillCurrent(Gfx **, u16);
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern s32 func_87F00930(void);
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C6B8(u8 *);
extern void func_87F07FE8(u8 *);
extern void func_87F022F0(void);
void func_86905804(void);
void func_86907614(void);
void func_869054CC(void);
void func_86909EAC(void);
void func_8690AA64(void);
extern void func_87F0A5BC(u8 *);
extern u8 D_8690FA20[];
extern void func_81900214(s32);
extern s32 D_8691A424;
extern void func_87F01D44(void);
extern void func_87F0C88C(u8 *);
extern void func_80008648(void);
extern s32 D_8690E11C;
extern s32 D_8690E120;
extern u8 D_8690F9E8;
extern u8 * D_8691AD58;
void func_86901414(void) {
    func_80043E70(D_8690F9E0, 1);
    func_800088DC();
    if (*(s32 *)D_8691AD58 == 8 || *(s32 *)D_8691AD58 == 9 || *(s32 *)D_8691AD58 == 10) {
        GfxImage_FillCurrent(&D_800D0510, 1);
    }
    func_8000766C(&D_800D0510, 0, 0, 0x140, 0xF0);
    if (func_87F00930() == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    func_8003C6B8(*(u8 **)(D_8691AD58 + 8));
    switch (*(u32 *)D_8691AD58) {
    case 0:
    case 1:
    case 2:
        func_87F07FE8(&D_8690F9E8);
        break;
    case 11:
        if (D_8690E11C != 0) {
            func_87F07FE8(&D_8690F9E8);
        }
        if (D_8690E120 != 0) {
            func_87F022F0();
        }
        break;
    case 4:
        func_86905804();
        break;
    case 5:
        func_86907614();
        break;
    case 6:
        func_869054CC();
        break;
    case 7:
        func_86909EAC();
        break;
    case 8:
        func_8690AA64();
        break;
    case 9:
        func_87F0A5BC(D_8690FA20);
        func_81900214(D_8691A424);
        break;
    case 10:
        func_8690AA64();
        func_87F022F0();
        break;
    }
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
    func_87F0C88C(D_8691AD58 + 0x14);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern u8 *D_8691AD58;
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
void func_869015F0(s32 arg0) {
    *(s32 *)(D_8691AD58 + 0x10) = arg0;
    *(s32 *)D_8691AD58 = 0xB;
    *(s32 *)(D_8691AD58 + 4) = 0xC;
    StageContext_SetClearColor((u16)0xFFFF);
    StageFade_StartFromTransparent(0xA);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_86901640.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_86901AA8.s")
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_86901AA8(void);
extern void func_86901414(void);
void func_869020CC(void) {
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        func_86901AA8();
        func_86901414();
    } while (*(s32 *)D_8691AD58 != 0xC);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_86902134.s")
#endif

#ifdef VERSION_US
extern u8 D_8691A2A0[];
extern s32 D_8691A768;

// Sets D_8691A768 to a random amount chosen by the word at D_8691A2A0 + 0x48,
// scaled by a factor chosen by the word at D_8691A2A0 + 0x78.
void func_8690241C(void) {
    //!bug factor is never set when the word at D_8691A2A0 + 0x78 is above 3.
    f32 factor;

    switch (*(s32 *)(D_8691A2A0 + 0x78)) {
        case 0:
            factor = 0.6f;
            break;
        case 1:
            factor = 0.8f;
            break;
        case 2:
            factor = 1.0f;
            break;
        case 3:
            factor = 1.0f;
            break;
    }

    switch (*(u32 *)(D_8691A2A0 + 0x48)) {
        case 0:
            D_8691A768 = (5 + guRandom() % 6) * factor;
            break;
        case 1:
            D_8691A768 = (*(s32 *)(D_8691A2A0 + 0x74) + guRandom() % 11 + 5) * factor;
            break;
        case 2:
            D_8691A768 = (*(s32 *)(D_8691A2A0 + 0x74) + guRandom() % 11 + 10) * factor;
            break;
        case 3:
            D_8691A768 = (*(s32 *)(D_8691A2A0 + 0x74) + guRandom() % 16 + 10) * factor;
            break;
        case 4:
            D_8691A768 = (*(s32 *)(D_8691A2A0 + 0x74) + guRandom() % 11 + 20) * factor;
            break;
    }
}
#endif

#ifdef VERSION_US
typedef struct unk_D_8691A448_entry {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
} unk_D_8691A448_entry; // size = 0x14

typedef struct unk_D_8691A448 {
    /* 0x000 */ unk_D_8691A448_entry entries[40];
    /* 0x320 */ s32 unk_320;
    /* 0x324 */ s32 unk_324;
    /* 0x328 */ s32 unk_328;
    /* 0x32C */ s32 unk_32C;
    /* 0x330 */ s32 unk_330;
    /* 0x334 */ s32 unk_334[4];
    /* 0x344 */ s32 unk_344[4];
    /* 0x354 */ s32 unk_354;
    /* 0x358 */ s32 unk_358;
    /* 0x35C */ s32 unk_35C;
    /* 0x360 */ s32 unk_360;
    /* 0x364 */ s32 unk_364;
    /* 0x368 */ s32 unk_368;
    /* 0x36C */ s32 unk_36C;
    /* 0x370 */ s32 unk_370;
    /* 0x374 */ s32 unk_374;
    /* 0x378 */ s32 unk_378;
    /* 0x37C */ s32 unk_37C;
    /* 0x380 */ s32 unk_380;
    /* 0x384 */ s32 unk_384;
    /* 0x388 */ s32 unk_388;
} unk_D_8691A448; // size = 0x38C

typedef struct unk_D_8690E558 {
    /* 0x00 */ u8 unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} unk_D_8690E558; // size = 0x24

typedef struct unk_D_8690E7BC {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} unk_D_8690E7BC; // size = 0xC

extern unk_D_8691A448 D_8691A448;
extern u8 D_86911448[];
extern unk_D_8690E558 D_8690E558[];
extern unk_D_8690E7BC D_8690E7BC[];
extern s32 D_8690E8CC[];
extern s32 D_8690E8EC[];
extern s32 D_8690E928[];
extern s32 D_8690E944[];
extern s32 D_8690E954[];
extern s32 D_8690EB28[];
extern void func_87F02684(void *);
extern s32 func_86904D48(void);
extern s32 func_8690C20C(s32);
extern void func_8690B700(void);
void func_8690B848(void);

// Shared by the four D_8690E8CC/D_8690E8EC/D_8690E928/D_8690E944 table switches in
// func_86902640: claims the D_8691A448 flag for the picked value (unk_354-unk_36C),
// or jumps back to retry_pick when the flag is already set or the word at
// D_8691A2A0 + 0x78 is below the threshold that value requires.
#define PICK_BODY                                                                                \
    case 0:                                                                                      \
    case 1:                                                                                      \
    case 2:                                                                                      \
        if (D_8691A448.unk_354 != 0) {                                                           \
            goto retry_pick;                                                                     \
        }                                                                                        \
        D_8691A448.unk_354 = 1;                                                                  \
        break;                                                                                   \
    case 3:                                                                                      \
    case 4:                                                                                      \
        if (D_8691A448.unk_358 != 0) {                                                           \
            goto retry_pick;                                                                     \
        }                                                                                        \
        D_8691A448.unk_358 = 1;                                                                  \
        break;                                                                                   \
    case 5:                                                                                      \
    case 6:                                                                                      \
    case 7:                                                                                      \
        if ((*(s32 *)(D_8691A2A0 + 0x78) == 0) || (*(s32 *)(D_8691A2A0 + 0x78) == 1)) {          \
            goto retry_pick;                                                                     \
        }                                                                                        \
        if (D_8691A448.unk_35C != 0) {                                                           \
            goto retry_pick;                                                                     \
        }                                                                                        \
        D_8691A448.unk_35C = 1;                                                                  \
        break;                                                                                   \
    case 8:                                                                                      \
    case 9:                                                                                      \
        if (*(s32 *)(D_8691A2A0 + 0x78) == 0) {                                                  \
            goto retry_pick;                                                                     \
        }                                                                                        \
        if (D_8691A448.unk_360 != 0) {                                                           \
            goto retry_pick;                                                                     \
        }                                                                                        \
        D_8691A448.unk_360 = 1;                                                                  \
        break;                                                                                   \
    case 10:                                                                                     \
    case 11:                                                                                     \
    case 12:                                                                                     \
        if (D_8691A448.unk_364 != 0) {                                                           \
            goto retry_pick;                                                                     \
        }                                                                                        \
        D_8691A448.unk_364 = 1;                                                                  \
        break;                                                                                   \
    case 13:                                                                                     \
    case 14:                                                                                     \
        if ((*(s32 *)(D_8691A2A0 + 0x78) == 0) || (*(s32 *)(D_8691A2A0 + 0x78) == 1)) {          \
            goto retry_pick;                                                                     \
        }                                                                                        \
        if (D_8691A448.unk_368 != 0) {                                                           \
            goto retry_pick;                                                                     \
        }                                                                                        \
        D_8691A448.unk_368 = 1;                                                                  \
        break;                                                                                   \
    case 15:                                                                                     \
    case 16:                                                                                     \
        if ((*(s32 *)(D_8691A2A0 + 0x78) == 0) || (*(s32 *)(D_8691A2A0 + 0x78) == 1) ||          \
            (*(s32 *)(D_8691A2A0 + 0x78) == 2)) {                                                \
            goto retry_pick;                                                                     \
        }                                                                                        \
        if (D_8691A448.unk_36C != 0) {                                                           \
            goto retry_pick;                                                                     \
        }                                                                                        \
        D_8691A448.unk_36C = 1;                                                                  \
        break;

// Fills the first D_8691A448.unk_320 entries of D_8691A448.entries. Picks a table
// row (unk_32C) and each entry's kind (unk_0C) from tables chosen by the word at
// D_8691A2A0 + 0x48, then random x, y and unk_10 values that keep clear of every
// earlier entry (unk_10 is compared only for kinds 3 and 4). It restarts all
// placements after more than 200 rerolls in total or when func_86904D48 returns 0,
// then sets unk_334[i] from func_8690C20C(i) and unk_344[i] (20/10/5/3) from that
// value's range.
void func_86902640(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 z;
    s32 delta_y;
    s32 other_x;
    s32 other_y;
    s32 attempts;
    s32 kind;
    f32 scale;
    s32 chance; // Percent chance of setting unk_388; later reused as the z and x deltas.
    unk_D_8690E558 *range;

    *(s32 *)(D_8691A2A0 + 0x80) = 0;
    *(s32 *)(D_8691A2A0 + 0x24) = 0;
    func_87F02684(D_86911448);
    D_8691A448.unk_324 = 0;

    switch (*(s32 *)(D_8691A2A0 + 0x78)) {
        case 0:
            scale = 0.7f;
            chance = 70;
            break;
        case 1:
            scale = 0.85f;
            chance = 50;
            break;
        case 2:
            scale = 1.0f;
            chance = 30;
            break;
        case 3:
            scale = 1.2f;
            chance = 10;
            break;
    }

    if (*(s32 *)D_8691AD58 != 13) {
    retry_pick:
        if ((*(s32 *)(D_8691A2A0 + 0x48) == 2) || (*(s32 *)(D_8691A2A0 + 0x48) == 3)) {
            if (guRandom() % 100 < chance) {
                D_8691A448.unk_388 = 1;
            } else {
                D_8691A448.unk_388 = 0;
            }
        } else {
            D_8691A448.unk_388 = 0;
        }

        if (D_8691A448.unk_388 != 0) {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                    switch (D_8691A448.unk_32C = guRandom() % 10) {
                        case 0:
                        case 1:
                            if (D_8691A448.unk_370 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_370 = 1;
                            break;
                        case 2:
                        case 3:
                            if (D_8691A448.unk_378 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_378 = 1;
                            break;
                        case 4:
                            if (D_8691A448.unk_37C != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_37C = 1;
                            break;
                        case 5:
                        case 6:
                        case 7:
                            if (D_8691A448.unk_380 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_380 = 1;
                            break;
                        case 8:
                        case 9:
                            if (D_8691A448.unk_384 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_384 = 1;
                            break;
                    }
                    break;
                case 1:
                    D_8691A448.unk_32C = guRandom() % 15;
                    switch (D_8691A448.unk_32C) {
                        case 0:
                        case 1:
                            if (D_8691A448.unk_370 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_370 = 1;
                            break;
                        case 2:
                        case 3:
                            if (D_8691A448.unk_374 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_374 = 1;
                            break;
                        case 4:
                        case 5:
                            if (D_8691A448.unk_378 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_378 = 1;
                            break;
                        case 6:
                        case 7:
                        case 8:
                            if (D_8691A448.unk_37C != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_37C = 1;
                            break;
                        case 9:
                        case 10:
                        case 11:
                            if (D_8691A448.unk_380 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_380 = 1;
                            break;
                        case 12:
                        case 13:
                        case 14:
                            if (D_8691A448.unk_384 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_384 = 1;
                            break;
                    }
                    break;
                case 2:
                    D_8691A448.unk_32C = guRandom() % 3;
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            if (D_8691A448.unk_370 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_370 = 1;
                            break;
                        case 1:
                            if (D_8691A448.unk_374 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_374 = 1;
                            break;
                        case 2:
                            if (D_8691A448.unk_378 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_378 = 1;
                            break;
                    }
                    break;
                case 3:
                    D_8691A448.unk_32C = guRandom() % 3;
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            if (D_8691A448.unk_37C != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_37C = 1;
                            break;
                        case 1:
                            if (D_8691A448.unk_380 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_380 = 1;
                            break;
                        case 2:
                            if (D_8691A448.unk_384 != 0) {
                                goto retry_pick;
                            }
                            D_8691A448.unk_384 = 1;
                            break;
                    }
                    break;
                case 4:
                    D_8691A448.unk_32C = guRandom() % 15;
                    break;
            }
        } else {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                    D_8691A448.unk_32C = guRandom() % 8;
                    switch (D_8690E8CC[D_8691A448.unk_32C]) {
                        PICK_BODY
                    }
                    break;
                case 1:
                    D_8691A448.unk_32C = guRandom() % 15;
                    switch (D_8690E8EC[D_8691A448.unk_32C]) {
                        PICK_BODY
                    }
                    break;
                case 2:
                    D_8691A448.unk_32C = guRandom() % 7;
                    switch (D_8690E928[D_8691A448.unk_32C]) {
                        PICK_BODY
                    }
                    break;
                case 3:
                    D_8691A448.unk_32C = guRandom() % 4;
                    switch (D_8690E944[D_8691A448.unk_32C]) {
                        PICK_BODY
                    }
                    break;
                case 4:
                    D_8691A448.unk_32C = guRandom() % 15;
                    break;
            }
        }
    }

restart:
    func_8690241C();
    attempts = 0;
    for (i = 0; i < D_8691A448.unk_320; i++) {
        if (D_8691A448.unk_388 != 0) {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                case 1:
                case 4:
                    D_8691A448.entries[i].unk_08 = 0;
                    break;
                case 2:
                    D_8691A448.entries[i].unk_08 = guRandom() % 97 % 2;
                    break;
                case 3:
                    D_8691A448.entries[i].unk_08 = guRandom() % 97 % 3;
                    break;
            }
        } else {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                case 1:
                case 4:
                    D_8691A448.entries[i].unk_08 = 0;
                    break;
                case 2:
                    D_8691A448.entries[i].unk_08 = guRandom() % 97 % 2;
                    break;
                case 3:
                    switch (D_8690E944[D_8691A448.unk_32C]) {
                        case 0:
                        case 5:
                            D_8691A448.entries[i].unk_08 = guRandom() % 97 % 3;
                            break;
                        case 3:
                        case 8:
                            D_8691A448.entries[i].unk_08 = guRandom() % 97 % 2;
                            break;
                    }
                    break;
            }
        }

        if (D_8691A448.unk_388 != 0) {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            D_8691A448.entries[i].unk_0C = kind = 1;
                            break;
                        case 1:
                            D_8691A448.entries[i].unk_0C = kind = 13;
                            break;
                        case 2:
                            D_8691A448.entries[i].unk_0C = kind = 0;
                            break;
                        case 3:
                            D_8691A448.entries[i].unk_0C = kind = 12;
                            break;
                        case 4:
                            D_8691A448.entries[i].unk_0C = kind = 0;
                            break;
                        case 5:
                            D_8691A448.entries[i].unk_0C = kind = 2;
                            break;
                        case 6:
                            D_8691A448.entries[i].unk_0C = kind = 11;
                            break;
                        case 7:
                            D_8691A448.entries[i].unk_0C = kind = 15;
                            break;
                        case 8:
                            D_8691A448.entries[i].unk_0C = kind = 13;
                            break;
                        case 9:
                            D_8691A448.entries[i].unk_0C = kind = 10;
                            break;
                    }
                    break;
                case 1:
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            D_8691A448.entries[i].unk_0C = kind = 1;
                            break;
                        case 1:
                            D_8691A448.entries[i].unk_0C = kind = 13;
                            break;
                        case 2:
                            D_8691A448.entries[i].unk_0C = kind = 5;
                            break;
                        case 3:
                            D_8691A448.entries[i].unk_0C = kind = 16;
                            break;
                        case 4:
                            D_8691A448.entries[i].unk_0C = kind = 0;
                            break;
                        case 5:
                            D_8691A448.entries[i].unk_0C = kind = 12;
                            break;
                        case 6:
                            D_8691A448.entries[i].unk_0C = kind = 0;
                            break;
                        case 7:
                            D_8691A448.entries[i].unk_0C = kind = 6;
                            break;
                        case 8:
                            D_8691A448.entries[i].unk_0C = kind = 9;
                            break;
                        case 9:
                            D_8691A448.entries[i].unk_0C = kind = 2;
                            break;
                        case 10:
                            D_8691A448.entries[i].unk_0C = kind = 11;
                            break;
                        case 11:
                            D_8691A448.entries[i].unk_0C = kind = 15;
                            break;
                        case 12:
                            D_8691A448.entries[i].unk_0C = kind = 13;
                            break;
                        case 13:
                            D_8691A448.entries[i].unk_0C = kind = 8;
                            break;
                        case 14:
                            D_8691A448.entries[i].unk_0C = kind = 10;
                            break;
                    }
                    break;
                case 2:
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            switch (D_8691A448.entries[i].unk_08) {
                                case 0:
                                    D_8691A448.entries[i].unk_0C = kind = 1;
                                    break;
                                case 1:
                                    D_8691A448.entries[i].unk_0C = kind = 13;
                                    break;
                            }
                            break;
                        case 1:
                            switch (D_8691A448.entries[i].unk_08) {
                                case 0:
                                    D_8691A448.entries[i].unk_0C = kind = 5;
                                    break;
                                case 1:
                                    D_8691A448.entries[i].unk_0C = kind = 16;
                                    break;
                            }
                            break;
                        case 2:
                            switch (D_8691A448.entries[i].unk_08) {
                                case 0:
                                    kind = D_8691A448.entries[i].unk_0C = 0;
                                    break;
                                case 1:
                                    kind = D_8691A448.entries[i].unk_0C = 12;
                                    break;
                            }
                            break;
                    }
                    break;
                case 3:
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            switch (D_8691A448.entries[i].unk_08) {
                                case 0:
                                    kind = D_8691A448.entries[i].unk_0C = 0;
                                    break;
                                case 1:
                                    D_8691A448.entries[i].unk_0C = kind = 6;
                                    break;
                                case 2:
                                    D_8691A448.entries[i].unk_0C = kind = 9;
                                    break;
                            }
                            break;
                        case 1:
                            switch (D_8691A448.entries[i].unk_08) {
                                case 0:
                                    D_8691A448.entries[i].unk_0C = kind = 2;
                                    break;
                                case 1:
                                    D_8691A448.entries[i].unk_0C = kind = 11;
                                    break;
                                case 2:
                                    D_8691A448.entries[i].unk_0C = kind = 15;
                                    break;
                            }
                            break;
                        case 2:
                            switch (D_8691A448.entries[i].unk_08) {
                                case 0:
                                    D_8691A448.entries[i].unk_0C = kind = 13;
                                    break;
                                case 1:
                                    D_8691A448.entries[i].unk_0C = kind = 8;
                                    break;
                                case 2:
                                    D_8691A448.entries[i].unk_0C = kind = 10;
                                    break;
                            }
                            break;
                    }
                    break;
                case 4:
                    D_8691A448.entries[i].unk_0C = D_8690E954[guRandom() % 97 % 15];
                    kind = D_8691A448.entries[i].unk_0C;
                    break;
            }
        } else {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                    kind = D_8691A448.entries[i].unk_0C = D_8690E8CC[D_8691A448.unk_32C];
                    break;
                case 1:
                    kind = D_8691A448.entries[i].unk_0C = D_8690E8EC[D_8691A448.unk_32C];
                    break;
                case 2:
                    D_8691A448.entries[i].unk_0C = kind = D_8690E928[D_8691A448.unk_32C] + D_8691A448.entries[i].unk_08;
                    break;
                case 3:
                    D_8691A448.entries[i].unk_0C = kind = D_8690E944[D_8691A448.unk_32C] + D_8691A448.entries[i].unk_08;
                    break;
                case 4:
                    D_8691A448.entries[i].unk_0C = D_8690E954[guRandom() % 97 % 15];
                    kind = D_8691A448.entries[i].unk_0C;
                    break;
            }
        }

    retry_place:
        if (attempts > 200) {
            attempts = 0;
            goto restart;
        }
        range = &D_8690E558[kind];
        j = 0;
        z = D_8691A448.entries[i].unk_10 = guRandom() % 197;

        if (D_8691A448.unk_388 != 0) {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                case 1:
                    x = D_8691A448.entries[i].x = (f32)(guRandom() % range->unk_20) * scale + range->unk_1C;
                    break;
                case 2:
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 800) * scale + 300.0f;
                            break;
                        case 1:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1280) * scale + 300.0f;
                            break;
                        case 2:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 800) * scale + 300.0f;
                            break;
                    }
                    break;
                case 3:
                    switch (D_8691A448.unk_32C) {
                        case 0:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1360) * scale + 300.0f;
                            break;
                        case 1:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1040) * scale + 300.0f;
                            break;
                        case 2:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1120) * scale + 300.0f;
                            break;
                    }
                    break;
                case 4:
                    if ((kind == 3) || (kind == 4)) {
                        x = D_8691A448.entries[i].x = guRandom() % range->unk_20 + range->unk_1C;
                        z = D_8691A448.entries[i].unk_10 = guRandom() % 12;
                    } else {
                        x = D_8691A448.entries[i].x = (f32)(guRandom() % 1440) * scale + 300.0f;
                    }
                    break;
            }
        } else {
            switch (*(s32 *)(D_8691A2A0 + 0x48)) {
                case 0:
                case 1:
                    if ((kind == 3) || (kind == 4)) {
                        x = D_8691A448.entries[i].x = guRandom() % range->unk_20 + range->unk_1C;
                    } else {
                        x = D_8691A448.entries[i].x = (f32)(guRandom() % range->unk_20) * scale + range->unk_1C;
                    }
                    break;
                case 2:
                    switch (D_8690E928[D_8691A448.unk_32C]) {
                        case 0:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1040) * scale + 300.0f;
                            break;
                        case 3:
                            x = D_8691A448.entries[i].x = guRandom() % range->unk_20 + range->unk_1C;
                            break;
                        case 5:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1200) * scale + 300.0f;
                            break;
                        case 8:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1360) * scale + 300.0f;
                            break;
                        case 10:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 720) * scale + 300.0f;
                            break;
                        case 13:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 800) * scale + 300.0f;
                            break;
                        case 15:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1280) * scale + 300.0f;
                            break;
                    }
                    break;
                case 3:
                    switch (D_8690E944[D_8691A448.unk_32C]) {
                        case 0:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1040) * scale + 300.0f;
                            break;
                        case 3:
                            x = D_8691A448.entries[i].x = guRandom() % range->unk_20 + range->unk_1C;
                            break;
                        case 5:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1200) * scale + 300.0f;
                            break;
                        case 8:
                            x = D_8691A448.entries[i].x = (f32)(guRandom() % 1360) * scale + 300.0f;
                            break;
                    }
                    break;
                case 4:
                    if ((kind == 3) || (kind == 4)) {
                        x = D_8691A448.entries[i].x = guRandom() % range->unk_20 + range->unk_1C;
                        z = D_8691A448.entries[i].unk_10 = guRandom() % 12;
                    } else {
                        x = D_8691A448.entries[i].x = (f32)(guRandom() % 1440) * scale + 300.0f;
                    }
                    break;
            }
        }

        y = D_8691A448.entries[i].y = guRandom() % range->unk_18 + range->unk_14;
        x += D_8690E7BC[kind].unk_04;
        y += D_8690E7BC[kind].unk_08 * 3.0f;

        // Reroll this entry's position while it lies too close to an earlier entry.
        // chance and delta_y are reused as scratch here: IDO's register assignment in
        // both loops (chance in a0, delta_y in a1, other_x in a2, other_y in a3)
        // needs four distinct variables in these roles.
        if ((kind == 3) || (kind == 4)) {
            for (j = 0; j < i; j++) {
                other_x = D_8690E7BC[(D_8691A448.entries + j)->unk_0C].unk_04 + (D_8691A448.entries + j)->x;
                delta_y = (D_8691A448.entries + j)->unk_10;
                chance = z - delta_y;
                other_y = D_8690E7BC[(D_8691A448.entries + j)->unk_0C].unk_08 * 3.0f + (D_8691A448.entries + j)->y;
                if (chance * chance >= 576) {
                    continue;
                }
                chance = x - other_x;
                delta_y = y - other_y;
                if (chance * chance + delta_y * delta_y < 0x2000) {
                    attempts++;
                    goto retry_place;
                }
            }
        } else {
            for (j = 0; j < i; j++) {
                other_x = D_8690E7BC[(D_8691A448.entries + j)->unk_0C].unk_04 + (D_8691A448.entries + j)->x;
                other_y = D_8690E7BC[(D_8691A448.entries + j)->unk_0C].unk_08 * 3.0f + (D_8691A448.entries + j)->y;
                chance = x - other_x;
                delta_y = y - other_y;
                if (chance * chance + delta_y * delta_y < 0x400) {
                    attempts++;
                    goto retry_place;
                }
                if ((delta_y * delta_y < D_8690EB28[*(s32 *)(D_8691A2A0 + 0x48)]) && (chance * chance < 409600)) {
                    attempts++;
                    goto retry_place;
                }
            }
        }
    }

    if (D_8691A448.unk_388 != 0) {
        switch (*(s32 *)(D_8691A2A0 + 0x48)) {
            case 0:
            case 1:
            case 4:
                D_8691A448.unk_330 = 0;
                break;
            case 2:
                D_8691A448.unk_330 = guRandom() % 97 % 3;
                break;
            case 3:
                switch (guRandom() % 97 % 4) {
                    case 0:
                        D_8691A448.unk_330 = 0;
                        break;
                    case 1:
                        D_8691A448.unk_330 = 1;
                        break;
                    case 2:
                        D_8691A448.unk_330 = 3;
                        break;
                    case 3:
                        D_8691A448.unk_330 = 6;
                        break;
                }
                break;
        }
    } else {
        switch (*(s32 *)(D_8691A2A0 + 0x48)) {
            case 0:
            case 1:
            case 4:
                D_8691A448.unk_330 = 0;
                break;
            case 2:
                switch (D_8690E928[D_8691A448.unk_32C]) {
                    case 13:
                        D_8691A448.unk_330 = 0;
                        break;
                    case 0:
                    case 3:
                    case 5:
                    case 8:
                    case 10:
                    case 15:
                        D_8691A448.unk_330 = guRandom() % 97 % 3;
                        break;
                }
                break;
            case 3:
                switch (D_8690E944[D_8691A448.unk_32C]) {
                    case 0:
                        switch (guRandom() % 97 % 4) {
                            case 0:
                                D_8691A448.unk_330 = 0;
                                break;
                            case 1:
                                D_8691A448.unk_330 = 1;
                                break;
                            case 2:
                                D_8691A448.unk_330 = 3;
                                break;
                            case 3:
                                D_8691A448.unk_330 = 6;
                                break;
                        }
                        break;
                    case 3:
                    case 5:
                    case 8:
                        D_8691A448.unk_330 = guRandom() % 97 % 3;
                        break;
                }
                break;
        }
    }

    if (func_86904D48() == 0) {
        attempts = 0;
        goto restart;
    }

    for (i = 0; i < 4; i++) {
        D_8691A448.unk_334[i] = func_8690C20C(i);
        if (D_8691A448.unk_334[i] < 5) {
            D_8691A448.unk_344[i] = 20;
        } else if (D_8691A448.unk_334[i] < 15) {
            D_8691A448.unk_344[i] = 10;
        } else if (D_8691A448.unk_334[i] < 25) {
            D_8691A448.unk_344[i] = 5;
        } else {
            D_8691A448.unk_344[i] = 3;
        }
    }
    func_8690B700();
    func_8690B848();
}

#undef PICK_BODY

#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_86904D48.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_869053B4.s")
#endif

void func_869054CC(void) {
}

#ifdef VERSION_US
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern s32 D_86919030[];
void func_869054D4(void) {
    s32 i;
    s16 frame;

    for (i = 0; i < 4; i++) {
        if (ModelAnim_IsFinished(&D_86919040 + i * 0x168)) {
            ModelAnim_SetFrame(&D_86919040 + i * 0x168, 10);
        }
    }

    if (StageContext_GetFadeMode() == 1) {
        for (i = 0; i < 4; i++) {
            func_8003F1DC(&D_86919040 + i * 0x168);
            func_8003F114(&D_869195E0 + i * 0x168, 0, -1, D_86919030[i]);
            func_8003F210(&D_869195E0 + i * 0x168, 0);
            frame = guRandom() % 20;
            ModelAnim_SetFrame(&D_869195E0 + i * 0x168, frame);
            func_8003F3BC(&D_869195E0 + i * 0x168, 0);
        }
        StageFade_StartFromOpaque(20);
        *(s32 *)D_8691AD58 = 4;
        fragment64_main(25);
        func_87F00688();
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_86905630.s")
#endif

void func_86905804(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690580C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_86907614.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690941C.s")
#endif

#ifdef VERSION_US
extern s32 D_8690FABC;
extern u8 D_8691A2A0[];
extern void func_87F0A6C8(s32, s32, s32 *, s32 *);
extern void func_800503A4(s32);
extern void func_8690CA50(void);
void func_86909EAC(void) {
    s32 var_v0;
    s32 color1;
    s32 color2;

    var_v0 = *(s32 *)(D_8691A2A0 + 0x4C);
    if (var_v0 < 30) {
        if (*(s32 *)(D_8691A2A0 + 0x48) < 4) {
            *(s32 *)(D_8691A2A0 + 0x70) = 1;
        }
    } else if (var_v0 < 60) {
        *(s32 *)(D_8691A2A0 + 0x70) = 1;
        color1 = 0xFFB400FF;
        color2 = 0x000096FF;
        func_87F0A6C8(D_8690FABC, 0x50503643, &color1, &color2);
        func_800503A4(D_8690FABC);
    } else if (var_v0 < 90) {
        *(s32 *)(D_8691A2A0 + 0x70) = 1;
        color1 = 0xFFB400FF;
        color2 = 0x000096FF;
        func_87F0A6C8(D_8690FABC, 0x50503643, &color1, &color2);
        func_800503A4(D_8690FABC);
        func_8690CA50();
    } else {
        *(s32 *)(D_8691A2A0 + 0x70) = 0;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_86909FAC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690AA64.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690ABCC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690AD3C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690B2A8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690B700.s")
#endif

#ifdef VERSION_US
extern void func_8690AD3C(s32);
void func_8690B848(void) {
    s32 var_s0;

    var_s0 = 0;
    if ((*(s32 *)((u8 *)(&D_8691A448) + (0x320))) > 0) {
        do {
            func_8690AD3C(var_s0);
            var_s0 += 1;
        } while (var_s0 < (*(s32 *)((u8 *)(&D_8691A448) + (0x320))));
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8691AB68[4];
extern u8 D_8690FA20[];
extern void func_87F0C930(void *);
extern void func_87F0A098(void *, void *, s32, s32, s32, s32, s32);
void func_8690B89C(void) {
    s32 *p;
    s32 max;
    s32 i;

    max = -1;
    for (p = (s32 *)D_8691A2A0; p < (s32 *)(D_8691A2A0 + 0x10); p++) {
        if (max < p[10]) {
            max = p[10];
        }
    }
    for (i = 0; i < 4; i++) {
        if (max == ((s32 *)D_8691A2A0)[i + 10]) {
            D_8691AB68[i] = 1;
        }
    }
    if (*(u8 *)(*(u8 **)(D_8691AD58 + 0xC) + 0x2180) == 4) {
        func_87F0C930(D_8691AD58 + 0x14);
    } else {
        func_87F0A098(D_8690FA20, *(void **)(D_8691AD58 + 0xC), 7, D_8691AB68[0], D_8691AB68[1], D_8691AB68[2], D_8691AB68[3]);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690B984.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690C20C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690C46C.s")
#endif

#ifdef VERSION_US
extern s32 D_8690FAC0;
extern s32 D_8690FAC4;
extern s32 D_8690FAC8;
extern s32 D_8690FACC;
extern void func_87F0A6C8(s32, s32, s32 *, s32 *);
void func_8690C6C4(s32 arg0) {
    s32 sp24;
    s32 sp20;

    sp24 = -1;
    sp20 = 0x960000FF;
    switch (arg0) {
    case 0:
        func_87F0A6C8(D_8690FAC0, 0x4E4D3143, &sp24, &sp20);
        return;
    case 1:
        func_87F0A6C8(D_8690FAC4, 0x4E4D3243, &sp24, &sp20);
        func_87F0A6C8(D_8690FAC4, 0x4E4D3343, &sp24, &sp20);
        return;
    case 2:
        func_87F0A6C8(D_8690FAC8, 0x4E4D3443, &sp24, &sp20);
        func_87F0A6C8(D_8690FAC8, 0x4E4D3143, &sp24, &sp20);
        func_87F0A6C8(D_8690FAC8, 0x4E4D3543, &sp24, &sp20);
        return;
    case 3:
        func_87F0A6C8(D_8690FACC, 0x4E4D3143, &sp24, &sp20);
        return;
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_8690F9E0;
extern s32 func_8004410C(s32, s32);
extern void Gfx_DrawTextureRgba16(s16, s16, s16, s16, u8 *, s16, s32);

void func_8690C7F0(s32 arg0) {
    switch (arg0) {
    case 0:
        gSPDisplayList(D_800D0510++, D_80094E38);
        Gfx_DrawTextureRgba16(140, 111, 40, 40, (u8 *)func_8004410C(D_8690F9E0, 0), 40, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
        break;
    case 1:
        gSPDisplayList(D_800D0510++, D_80094E38);
        Gfx_DrawTextureRgba16(101, 111, 40, 40, (u8 *)func_8004410C(D_8690F9E0, 0), 40, 0);
        Gfx_DrawTextureRgba16(179, 111, 40, 40, (u8 *)func_8004410C(D_8690F9E0, 1), 40, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
        break;
    case 2:
        gSPDisplayList(D_800D0510++, D_80094E38);
        Gfx_DrawTextureRgba16(62, 111, 40, 40, (u8 *)func_8004410C(D_8690F9E0, 0), 40, 0);
        Gfx_DrawTextureRgba16(140, 111, 40, 40, (u8 *)func_8004410C(D_8690F9E0, 1), 40, 0);
        Gfx_DrawTextureRgba16(218, 111, 40, 40, (u8 *)func_8004410C(D_8690F9E0, 2), 40, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
        break;
    case 3:
        break;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690CA50.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690CCB8.s")
#endif

#ifdef VERSION_US
extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern u8 D_8690FFE8;
extern s32 D_86911290;
extern void func_8690CCB8(void);
void func_8690CF8C(s32 arg0) {
    u8 *v1 = func_87F025B8(&D_8690FFE8, func_8690CCB8);
    if (v1 != NULL) {
        *(s32 *)(v1 + 0x38) = arg0;
        *(s32 *)(v1 + 0x20) = arg0;
        *(f32 *)(v1 + 0x48) = 0.0f;
        *(f32 *)(v1 + 0x4C) = 0.0f;
        *(f32 *)(v1 + 0x50) = 0.0f;
        func_8003F1DC(v1 + 0x24);
        func_8003F114(v1 + 0x24, 0, -1, D_86911290);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690D000.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/59/fragment59_code/func_8690DC88.s")
#endif

#ifdef VERSION_US
extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern u8 D_86911298;
extern s32 D_8691143C;
extern void func_8690DC88(void);
void func_8690DF18(void) {
    u8 *v1 = func_87F025B8(&D_86911298, func_8690DC88);
    if (v1 != NULL) {
        *(f32 *)(v1 + 0x48) = 0.0f;
        *(f32 *)(v1 + 0x4C) = 0.0f;
        *(f32 *)(v1 + 0x54) = 0.0f;
        *(f32 *)(v1 + 0x58) = 0.0f;
        *(f32 *)(v1 + 0x5C) = 0.0f;
        *(f32 *)(v1 + 0x50) = 50.0f;
        func_8003F1DC(v1 + 0x24);
        func_8003F114(v1 + 0x24, 0, -1, D_8691143C);
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8690DF90 begin */
extern Gfx* D_800D0510;
extern s32 func_8004C990(s32, s32);
extern s32 func_8004CA60(s32);
extern void func_8003CD84(void);
extern Gfx* D_86911440;



void func_8690DF90(s32 arg0, s32 arg1) {
    s32 texture;

    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xBE, 0xF0, 0xFF);
        gDPSetEnvColor(D_800D0510++, 0x46, 0x00, 0x28, 0xFF);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, K5, K5, 0, COMBINED, 0, 0, 0, COMBINED);
        texture = func_8004C990(0x1A0, 0x13);
        { Gfx* segment = D_800D0510++;
        segment->words.w0 = 0xDB06003C;
        segment->words.w1 = (u32)func_8004CA60(texture); }
        gSPDisplayList(D_800D0510++, D_86911440);
        func_8003CD84();
    }
}
/* mkdraft:func_8690DF90 end */
#endif
