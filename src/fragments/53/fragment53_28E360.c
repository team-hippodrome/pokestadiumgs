#include "global.h"

#ifdef VERSION_US
struct Fragment53ActorState {
    u8 prefix[0xC];
    s32 animation;
    s32 pending;
    u8 middle14[4];
    s32 score;
    u8 middle1C[0x68];
    s32 result;
    s32 kind;
    u8 tail[0xC];
};
struct Fragment53Model { u8 opaque[0x168]; };
extern struct Fragment53ActorState D_86511698[];
extern struct Fragment53Model D_8650E120[];
extern s32 D_8650C4AC;
extern s32 D_8650C4B0;
extern f32 D_8650C4B8;
extern s32 D_8650C4D4;
extern s32 D_8650C5EC;
extern s32 D_8650D9D4;
#endif

#ifdef VERSION_US
extern s32 D_8650C4F0;
extern f32 D_8650C4FC;
extern s32 D_8650C610;
extern f32 D_8650F22C[];
extern f32 D_865119A0[];
extern f64 D_8650D800;
extern s32 D_8650C494;
extern f32 D_8650C508;
extern u8 D_865105B0[];
extern struct Fragment53ActorState D_86511698[];





void func_86504EB0(s32 arg0, void *arg1) {
    s32 pad[6]; // FAKE: unused; 24 bytes set the 0x20 stack frame. diff score 10 without it.
    f32 *temp_a1;
    f32 temp_ft2;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    f64 temp_fa0;
    f32 temp_fa1;
    f64 temp_ft4;
    f64 temp_ft3;
    f64 temp_ft0;
    s32 temp_v0;
    s32 temp_t5;
    struct Fragment53ActorState *temp_a0;
    u8 *temp_v1;

    temp_v0 = *(s32 *)((u8 *)arg1 + 0x14);
    switch (arg0) {
    case 0:
        temp_v1 = (u8 *)D_865105B0 + temp_v0 * 0x2D0;
        *(s16 *)(temp_v1 + 0x18A) = 0;
        *(s16 *)(temp_v1 + 0x186) = 0;
        break;
    case 2:
        if (D_8650C494 == 0) {
            temp_v1 = (u8 *)D_865105B0 + temp_v0 * 0x2D0;
            temp_a0 = &D_86511698[temp_v0];
            temp_fv0 = *(f32 *)((u8 *)temp_a0 + 0x70);
            if (*(f32 *)(temp_v1 + 0x28) > -3000.0f) {
                temp_a1 = (f32 *)((u8 *)D_865119A0 + temp_v0 * 4);
                *temp_a1 = (f32)((f64)*temp_a1 + 0.6);
            }
            temp_t5 = D_8650C610;
            if (temp_t5 == 0) {
                temp_fv1 = *(f32 *)((u8 *)D_865119A0 + temp_v0 * 4);
                temp_fa0 = (f64)temp_fv1;
                temp_fa1 = D_8650C508;
                temp_ft3 = (f64)temp_fa1;
                temp_ft0 = 4.9 * temp_ft3 * temp_fa0;
                temp_ft4 = temp_fa0 * temp_ft0;
                temp_ft5 = temp_fv1 - temp_fv0;
                *(f32 *)(temp_v1 + 0x28) = (f32)((f64)*(s32 *)((u8 *)temp_a0 + 0x30) - temp_ft4);
                *(f32 *)(temp_v1 + 0x194) = (f32)((f64)*(f32 *)((u8 *)D_8650F22C + temp_v0 * 0x168) +
                    (temp_ft4 / (f64)*(f32 *)((u8 *)temp_a0 + 0x74)));
                *(f32 *)(temp_v1 + 0x190) = ((f32)*(s32 *)((u8 *)temp_a0 + 0x34) +
                    (5.0f * temp_fv0 * temp_fv0)) - (temp_ft5 * (5.0f * temp_fa1 * temp_ft5));
                temp_ft2 = 256.0f;
                temp_ft2 *= *(f32 *)((u8 *)temp_a0 + 0x68);
                *(s16 *)(temp_v1 + 0x186) = (s16)((f32)*(s16 *)(temp_v1 + 0x186) + (temp_ft2 / 2));
                if (D_8650C4F0 == 1) {
                    *(s16 *)(temp_v1 + 0x18A) = (s16)((temp_ft2 * (f32)*(s32 *)((u8 *)temp_a0 + 0x78) * D_8650C4FC) +
                        (f32)*(s16 *)(temp_v1 + 0x18A));
                } else {
                    *(s16 *)(temp_v1 + 0x18A) = (s16)((temp_ft2 * (f32)*(s32 *)((u8 *)temp_a0 + 0x78)) +
                        (f32)*(s16 *)(temp_v1 + 0x18A));
                }
            }
        }
        // FAKE (FAKE): empty body; keeps the case-2 literal live into a block
        // where the state pointer holds $v1, so the dispatch compares $a2.
        if (temp_v0 == 2) {
        }
        break;
    case 5:
        break;
    }
}
#endif

#ifdef VERSION_US
s32 D_8650D1B0 = 0;
extern s32 D_8650C5E0;
extern s32 D_8650C4CC;
extern u8 D_865110F0[];
extern u8 D_8650F200[];
extern void func_80021ED8(s32);

/* Records are 0x168 bytes (Fragment53Model); the actor-pair records at
 * D_865105B0 are 0x2D0. */
#define F53_MODEL(base, i) ((u8 *)&((struct Fragment53Model *)(base))[i])
typedef struct { u8 opaque[0x2D0]; } Fragment53ModelPair;
#define F53_PAIR(base, i) ((u8 *)&((Fragment53ModelPair *)(base))[i])
#define XF(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define XI(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define XH(p, o) (*(s16 *)((u8 *)(p) + (o)))

void func_8650515C(s32 arg0, void *arg1) {
    static f32 D_8650D1DC = 0.0f;
    static s32 D_8650D9D0;
    s32 i;
    s32 pad; // FAKE: unused; a second home above tbl puts it at sp+0x58.
    s32 tbl[10] = { -99, -95, -90, -86, -83, -83, -86, -90, -99, 0 };

    switch (arg0) {
    case 0:
        break;
    case 2:
        if (D_8650C494 == 0) {
            switch (XI(&D_8650C5E0, 0x30)) {
            case 0:
                break;
            case 1:
                for (i = 0; i < 4; i++) {
                    XF(F53_MODEL(D_865110F0, i), 0x28) = -1500.0f;
                    XI(&D_86511698[i], 0x20) = 0;
                    XI(&D_86511698[i], 0x3C) = 0;
                    XH(F53_MODEL(D_8650F200, i), 0x22) = 0;
                    XH(F53_MODEL(D_8650F200, i), 0x1E) = 0;
                    XF(F53_MODEL(D_8650F200, i), 0x2C) = 40.0f;
                    XF(F53_MODEL(D_8650F200, i), 0x24) = XF(&D_8650E120[i], 0x24);
                    XH(F53_PAIR(D_865105B0, i), 0x18A) = 0;
                    XH(F53_PAIR(D_865105B0, i), 0x186) = 0;
                    XF(F53_PAIR(D_865105B0, i), 0x194) = 40.0f;
                    XI(&D_86511698[i], 0x44) = 0xB2 - (s32)((u32)XI(&D_86511698[i], 0x38) * 0x92) / D_8650C4CC;
                    if (XI(&D_86511698[i], 8) == 0 && XI(&D_86511698[i], 0x80) == 0) {
                        XI(&D_86511698[i], 0x44) = 0xB4;
                    }
                }
                D_8650D1B0 = 0;
                XI(&D_8650C5E0, 0x30) = 2;
                func_80021ED8(0x13);
                break;
            case 2:
                for (i = 0; i < 4; i++) {
                    if (XF(F53_MODEL(D_865110F0, i), 0x28) + (f32)(s32)((f64)((0.0 < (f64)D_8650C508 * 20.0) ? 0.5f : -0.5f) + (f64)D_8650C508 * 20.0) <= -120.0f) {
                        XF(F53_MODEL(D_865110F0, i), 0x28) = (f32)(s32)((f64)D_8650C508 * 20.0 + (f64)((0.0 < (f64)D_8650C508 * 20.0) ? 0.5f : -0.5f)) + XF(F53_MODEL(D_865110F0, i), 0x28);
                    } else {
                        XF(F53_MODEL(D_865110F0, i), 0x28) = 120.0f;
                        if (i == 0) {
                            D_8650D9D0++;
                        }
                        XF(F53_MODEL(D_865110F0, i), 0x28) = (f32)tbl[D_8650D9D0];
                    }
                    if (D_8650D9D0 >= 9) {
                        if (i == 3) {
                            D_8650D9D0 = 0;
                            XI(&D_8650C5E0, 0x30) = 3;
                        }
                        XF(F53_MODEL(D_865110F0, i), 0x28) = -100.0f;
                    }
                }
                break;
            case 3:
                D_8650D1B0++;
                if (D_8650D1B0 >= 0x47) {
                    D_8650D1B0 = 0;
                    XI(&D_8650C5E0, 0x30) = 6;
                    D_8650D1DC = 0.0f;
                }
                break;
            case 4:
                for (i = 0; i < 4; i++) {
                    if (-1500.0f < XF(F53_MODEL(D_865110F0, i), 0x28)) {
                        D_8650D1DC = (f32)((f64)D_8650D1DC + 0.15);
                        XF(F53_MODEL(D_865110F0, i), 0x28) = (f32)(-100.0 - ((f64)D_8650C508 * 4.9) * (f64)D_8650D1DC * (f64)D_8650D1DC);
                    } else {
                        XI(&D_8650C5E0, 0x30) = 5;
                    }
                    if (XF(F53_MODEL(D_865110F0, i), 0x28) < -200.0f) {
                        XI(&D_8650C5E0, 0x3C) = 0;
                    }
                }
                break;
            }
        }
        if (XI(&D_8650C5E0, 0x30) == 2 || XI(&D_8650C5E0, 0x30) == 4) {
            for (i = 0; i < 4; i++) {
                XF(F53_MODEL(D_8650F200, i), 0x28) = XF(F53_MODEL(D_865110F0, i), 0x28) + (f32)(D_8650C4CC / 2) + 25.0f + 2.0f;
                XF(F53_PAIR(D_865105B0, i), 0x28) = XF(F53_MODEL(D_865110F0, i), 0x28) + (f32)(XI(&D_86511698[i], 0x38) / 2) + 25.0f + 2.0f;
                XF(F53_PAIR(D_865105B0, i), 0x190) = XF(F53_PAIR(D_865105B0, i), 0x28) + (f32)(D_8650C4CC / 2) - 5.0f;
                XF(F53_PAIR(D_865105B0, i), 0x18C) = XF(&D_8650E120[i], 0x24) - 20.0f;
            }
        }
        break;
    case 5:
        break;
    }
}
#endif

#ifdef VERSION_US
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern void func_80038E14(s32, s32, f32, s32, f32, f32, f32, s32);
extern f32 D_8650C47C;
extern f32 D_8650D1E0;
s32 func_86505858(s32 arg0, s32 arg1) {
    extern s32 D_8650C5E0;
    GeoCamera_SetPerspective((void *)(u32)arg1, D_8650D1E0, 100.0f, 12800.0f);
    func_80038E14(arg1,
        *(s32 *)((u8 *)(&D_8650C5E0) + 0x24),
        D_8650C47C,
        *(s32 *)((u8 *)(&D_8650C5E0) + 0x2C),
        0.0f, D_8650C47C, 0.0f, 0);
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_865058CC(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(sp26 + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 - 0x2000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86505934(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - sp26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 + 0x6000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_28E360/func_865059A0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_28E360/func_86505EA8.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_865064B0 begin */
extern void Font_DisableTwoCycleTexturing(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0,s32 a1,s32 a2,s32 a3);
extern void func_800497E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_87F09040(void);
extern s32 D_8650C470;
extern s32 D_8650C4BC;
extern s32 D_8650C4C0;
extern s32 D_8650C4F0;
extern f32 D_8650C4F4;
extern f32 D_8650C4F8;
extern f32 D_8650C4FC;
extern s32 D_8650C500;
extern s32 D_8650C504;
extern s32 D_8650C5FC;
extern s32 D_8650D2E8;
extern s8 D_8650D490;
extern s8 D_8650D49C;
extern s8 D_8650D4A8;
extern s8 D_8650D4B4;
extern s8 D_8650D4B8;
extern s8 D_8650D4C8;
extern s8 D_8650D4CC;
extern s8 D_8650D4DC;
extern s8 D_8650D4E4;
extern s8 D_8650D4F4;
extern s8 D_8650D4F8;
extern s8 D_8650D508;
extern s8 D_8650D50C;
extern s8 D_8650D520;
extern s8 D_8650D528;
extern s8 D_8650D530;
extern s8 D_8650D540;
extern s8 D_8650D554;
extern s8 D_8650D55C;
extern s8 D_8650D56C;
extern s8 D_8650D578;
extern s8 D_8650D588;
extern s8 D_8650D594;
extern s8 D_8650D5A0;
extern s8 D_8650D5B0;
extern s8 D_8650D5BC;
extern s8 D_8650D5C8;
extern s8 D_8650D5DC;
extern s8 D_8650D5E8;
extern s8 D_8650D5F8;
extern s8 D_8650D60C;
extern s8 D_8650D618;
extern s8 D_8650D624;
extern s8 D_8650D634;



void func_865064B0(void) {
    func_87F09040();
    func_800498C4();
    func_800496A4(1, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    D_8650D2E8++;
    if (D_8650D2E8 >= 0x15) {
        D_8650D2E8 = 0;
    }
    func_800495F8(0x78, 0x32, 0, &D_8650D490);
    func_800495F8(0x78, 0x3C, 0, &D_8650D49C, D_8650D9D4);
    func_800495F8(0x78, 0x46, 0, &D_8650D4A8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 1)) {
        func_800495F8(0xE6, 0x46, 0, &D_8650D4B4, D_8650C4AC);
    }
    func_800495F8(0x78, 0x50, 0, &D_8650D4B8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 2)) {
        func_800495F8(0xE6, 0x50, 0, &D_8650D4C8, D_8650C4CC);
    }
    func_800495F8(0x78, 0x5A, 0, &D_8650D4CC);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 3)) {
        func_800495F8(0xE6, 0x5A, 0, &D_8650D4DC, (f64) D_8650C4B8);
    }
    func_800495F8(0x78, 0x64, 0, &D_8650D4E4);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 4)) {
        func_800495F8(0xE6, 0x64, 0, &D_8650D4F4, D_8650C4BC);
    }
    func_800495F8(0x78, 0x6E, 0, &D_8650D4F8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 5)) {
        func_800495F8(0xE6, 0x6E, 0, &D_8650D508, D_8650C4B0);
    }
    func_800495F8(0x78, 0x78, 0, &D_8650D50C);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 6)) {
        switch (D_8650C4C0) {                       /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            func_800495F8(0xE6, 0x78, 0, &D_8650D520);
            break;
        case 1:                                     /* switch 1 */
            func_800495F8(0xE6, 0x78, 0, &D_8650D528);
            break;
        case 2:                                     /* switch 1 */
            func_800495F8(0xE6, 0x78, 0, &D_8650D530);
            break;
        }
    }
    func_800495F8(0x78, 0x82, 0, &D_8650D540);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 7)) {
        func_800495F8(0xE6, 0x82, 0, &D_8650D554, (f64) D_8650C4F4);
    }
    func_800495F8(0x78, 0x8C, 0, &D_8650D55C);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 8)) {
        switch (D_8650C470) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D56C);
            break;
        case 1:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D578);
            break;
        case 2:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D588);
            break;
        case 3:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D594);
            break;
        }
    }
    func_800495F8(0x78, 0x96, 0, &D_8650D5A0);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 9)) {
        if (D_8650C4F0 == 1) {
            func_800495F8(0xE6, 0x96, 0, &D_8650D5B0);
        } else {
            func_800495F8(0xE6, 0x96, 0, &D_8650D5BC);
        }
    }
    func_800495F8(0x78, 0xA0, 0, &D_8650D5C8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 0xA)) {
        if (D_8650C500 == 0) {
            func_800495F8(0xE6, 0xA0, 0, &D_8650D5DC, (f64) D_8650C4F8);
        } else {
            func_800495F8(0xE6, 0xA0, 0, &D_8650D5E8, (f64) D_8650C4FC);
        }
    }
    func_800495F8(0x78, 0xAA, 0, &D_8650D5F8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 0xB)) {
        if (D_8650C504 == 0) {
            func_800495F8(0xE6, 0xAA, 0, &D_8650D60C);
        } else {
            func_800495F8(0xE6, 0xAA, 0, &D_8650D618);
        }
    }
    func_800495F8(0x78, 0xB4, 0, &D_8650D624);
    func_800495F8(0xE6, 0xB4, 0, &D_8650D634, D_8650C4D4);
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}
/* mkdraft:func_865064B0 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_28E360/func_86506B2C.s")
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void *D_8650DB10;
extern s32 D_8650C404[];
extern s32 D_8650C408;
extern s32 D_8650C42C;
extern s32 D_8650D2EC[];
extern s32 D_8650D2FC[];
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

typedef struct Fragment53FlashColor {
    s32 prim_r;
    s32 prim_g;
    s32 prim_b;
    s32 prim_a;
    s32 env_r;
    s32 env_g;
    s32 env_b;
} Fragment53FlashColor;
extern Fragment53FlashColor D_8650C680[];

#ifndef ROUND_MAX
#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
#endif
#define TEX_WIDTH(tex) ((s16)(s32)ROUND_MAX((f32)*(u16 *)((u8 *)(tex) + 0) * 0.57f))
#define TEX_HEIGHT(tex) ((s16)(s32)ROUND_MAX((f32)*(u16 *)((u8 *)(tex) + 2) * 0.57f))



void func_86506E78(s32 arg0, s32 arg1) {
    struct Fragment53ActorState *state;
    u8 *tex;
    s32 value;
    s32 divisor;
    s32 first_digit;
    s32 digit;
    s32 digit_index;
    s32 y;

    first_digit = -1;
    divisor = 100;
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) != 4) {
        gDPSetPrimColor(D_800D0510++, 0, 0, D_8650C680[arg0].prim_r, D_8650C680[arg0].prim_g,
                        D_8650C680[arg0].prim_b, D_8650C680[arg0].prim_a);
        gDPSetEnvColor(D_800D0510++, D_8650C680[arg0].env_r, D_8650C680[arg0].env_g,
                       D_8650C680[arg0].env_b, 0xFF);
        digit_index = 0;
        if (arg1 == 0) {
            state = &D_86511698[arg0];
            value = state->score;
        } else {
            state = &D_86511698[arg0];
            value = *(s32 *)((u8 *)state + 8);
        }
        if ((*(s32 *)((u8 *)state + 0x80) < 0) && (arg1 == 1)) {
            gDPSetPrimColor(D_800D0510++, 0, 0, D_8650C680[4].prim_r, D_8650C680[4].prim_g,
                            D_8650C680[4].prim_b, D_8650C680[4].prim_a);
            gDPSetEnvColor(D_800D0510++, D_8650C680[4].env_r, D_8650C680[4].env_g, D_8650C680[4].env_b,
                           0xFF);
            y = *(s32 *)((u8 *)state + 0x44);
            if (*(s32 *)((u8 *)state + 0x80) < -5) {
                tex = func_8004C990(0x1AD, D_8650C42C);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[0]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                     0, 0, 1796, 1796, 0);
                tex = func_8004C990(0x1AD, D_8650C408);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[1]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                     0, 0, 1796, 1796, 0);
                tex = func_8004C990(0x1AD, D_8650C404[0]);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[2]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                     0, 0, 1796, 1796, 0);
                return;
            }
            tex = func_8004C990(0x1AD, D_8650C42C);
            func_8004D1FC(tex);
            GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[4]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                 0, 0, 1796, 1796, 0);
            tex = func_8004C990(0x1AD, D_8650C404[-*(s32 *)((u8 *)state + 0x80)]);
            func_8004D1FC(tex);
            GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[5]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                 0, 0, 1796, 1796, 0);
            return;
        }
        do {
            if ((*(s32 *)((u8 *)state + 8) == 0x14) && (arg1 == 1)) {
                gDPSetPrimColor(D_800D0510++, 0, 0, D_8650C680[5].prim_r, D_8650C680[5].prim_g,
                                D_8650C680[5].prim_b, D_8650C680[5].prim_a);
                gDPSetEnvColor(D_800D0510++, D_8650C680[5].env_r, D_8650C680[5].env_g,
                               D_8650C680[5].env_b, 0xFF);
            }
            if (value >= divisor) {
                if (first_digit == -1) {
                    first_digit = digit_index;
                }
                digit = value / divisor;
                value -= digit * divisor;
                divisor /= 10;
                y = 0xCC;
                if (arg1 == 1) {
                    y = *(s32 *)((u8 *)state + 0x44);
                }
                tex = func_8004C990(0x1AD, D_8650C404[digit]);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + *(s32 *)((u8 *)D_8650D2FC + first_digit * 12 + digit_index * 4)),
                                     (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex), 0, 0, 1796, 1796, 0);
            } else {
                divisor /= 10;
                if ((first_digit != -1) || (digit_index == 2)) {
                    if ((digit_index == 2) && (first_digit == -1)) {
                        first_digit = 2;
                    }
                    y = 0xCC;
                    if (arg1 == 1) {
                        y = *(s32 *)((u8 *)state + 0x44);
                    }
                    tex = func_8004C990(0x1AD, D_8650C404[0]);
                    func_8004D1FC(tex);
                    GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + *(s32 *)((u8 *)D_8650D2FC + first_digit * 12 + digit_index * 4)), (s16)y,
                                         TEX_WIDTH(tex), TEX_HEIGHT(tex), 0, 0, 1796, 1796, 0);
                }
            }
            digit_index++;
        } while (digit_index != 3);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_28E360/func_86507AFC.s")
#endif

#ifdef VERSION_US
s32 func_87F00930();
extern void func_87F01D44();

void func_86508294(void) {
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void *D_8650DB1C;
extern void *D_8650DB20;
extern u8 D_8650DA70[];
extern u8 D_8650DA60[];
extern s32 D_8650C62C;
extern s32 D_8650DAD8;
extern s32 D_8650C5E0;
extern void *D_8650DB10;
extern void func_800088DC(void);
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern void func_800468A0(void *);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(void *);
extern void func_87F07FE8(void *);
extern void func_86507AFC(void);
extern void func_87F022F0(void);
extern void func_865064B0(void);
extern void func_87F0A5BC(void *);
extern void func_87F0C88C(void *);
extern void func_80008648(void);
void Fragment53_DrawSceneFrame(void) {
    func_800088DC();
    func_8000766C(&D_800D0510, 0, 0, 320, 240);
    func_800468A0(D_8650DB1C);
    if (D_8650C494 == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(D_8650DB20);
    switch (*(s32 *)((u8 *)&D_8650C5E0 + 0xC)) {
        case 2:
        case 12:
            if (*(s32 *)((u8 *)&D_8650C5E0 + 0x4C) == 1) {
                func_87F07FE8(&D_8650DAD8);
            } else {
                func_86507AFC();
            }
            if (D_8650C62C == 2) {
                func_86507AFC();
                func_87F022F0();
            }
            if (D_8650C62C == 3) {
                func_86507AFC();
                func_86508294();
            }
            break;
        case 0:
        case 4:
        case 5:
            if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) != 4) {
                func_87F07FE8(&D_8650DAD8);
            }
            break;
        case 10:
            func_865064B0(); /* fall through */
        case 1:
        case 6:
            func_86507AFC();
            func_86508294();
            break;
        case 9:
            func_86507AFC();
            func_87F0A5BC(D_8650DA70);
            break;
        case 8:
            func_86507AFC();
            func_87F022F0();
            break;
    }
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) == 4) {
        func_87F0C88C(D_8650DA60);
    }
    func_80008648();
}
#endif

#ifdef VERSION_US
extern struct Fragment53Model D_8650E6C0[];
extern s32 D_8650DB28[];
extern u8 D_8650E6E4[];
extern u8 D_8650EC60[];
extern u8 D_8650DB80[];
extern u8 D_8650F7A0[];
extern u8 D_865118F8[];
extern void func_8003F114(void *, s32, s32, s32);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern void func_8003F3BC(void *, s32);
extern void func_87F06430(void *, s32);
extern void func_8003F1DC(void *);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern void func_819006A0(void *);
extern void Fragment53_InitActorStateAndOrder(void);
void Fragment53_InitActorModels(void) {
    s32 index;

    for (index = 0; index < 4; index++) {
        func_8003F114((u8 *)&D_8650E6C0[index], 0, -1, D_8650DB28[index]);
        ModelAnim_SetAnimation((u8 *)&D_8650E6C0[index], 0);
        ModelAnim_SetSpeed((u8 *)&D_8650E6C0[index], 0x20000);
        ModelAnim_SetFrame((u8 *)&D_8650E6C0[index], (s16)(guRandom() % 15 + 15));
        ModelAnim_SetEventFrame((u8 *)&D_8650E6C0[index], 0);
        func_8003F3BC((u8 *)&D_8650E6C0[index], 0);
        func_87F06430(D_8650E6E4 + index * 0x168, index);
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x38) = 0.095f;
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x34) = 0.095f;
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x30) = 0.095f;
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x28) = 55.0f;
        *(s16 *)((u8 *)&D_8650E6C0[index] + 0x1E) = 0;
        D_86511698[index].animation = 0;
        D_86511698[index].pending = 0;
        func_8003F1DC(D_8650EC60 + index * 0x168);
        func_8003F1DC((u8 *)&D_8650E120[index]);
        *(s16 *)((u8 *)&D_8650E6C0[index] + 0x20) = 0;
        func_8003F1DC(D_8650DB80 + index * 0x168);
        func_8003F1DC(D_8650F7A0 + index * 0x168);
    }
    func_819006A0(*(void **)D_865118F8);
    Fragment53_InitActorStateAndOrder();
}
#endif

#ifdef VERSION_US
extern s32 ModelAnim_IsFinished(void *);
extern void func_80027A28(u16, u8);
void Fragment53_UpdateTimedSecondaryAnimation(s32 arg0) {
    s32 index;
    u8 *model;

    index = arg0;
    switch (D_86511698[index].animation) {
    case 0:
        model = (u8 *)&D_8650E6C0[index];
        if ((*(s32 *)(model + 0x48) >> 16) >= 6) {
            ModelAnim_SetAnimation(model, 2);
            ModelAnim_SetFrame(model, 0);
            ModelAnim_SetSpeed(model, 0x30000);
            D_86511698[index].animation = 2;
        }
        break;
    case 2:
        model = (u8 *)&D_8650E6C0[index];
        if (ModelAnim_IsFinished(model) == 1) {
            func_80027A28(0x1F04, (u8)index);
            ModelAnim_SetAnimation(model, 1);
            ModelAnim_SetSpeed(model, 0x20000);
            D_86511698[index].animation = 1;
        }
        break;
    }
}
#endif

void func_86508778(void) {
}

#ifdef VERSION_US
void Fragment53_UpdateSecondaryAnimation(s32 arg0) {
    s32 index;

    index = arg0;
    switch (D_86511698[index].animation) {
    case 0:
        ModelAnim_SetAnimation((u8 *)&D_8650E6C0[index], 2);
        ModelAnim_SetSpeed((u8 *)&D_8650E6C0[index], 0x30000);
        D_86511698[index].animation = 2;
        D_86511698[index].pending = 1;
        break;
    case 2:
        if (ModelAnim_IsFinished((u8 *)&D_8650E6C0[index]) == 1) {
            ModelAnim_SetAnimation((u8 *)&D_8650E6C0[index], 1);
            D_86511698[index].pending = 0;
        }
        break;
    }
}
#endif

#ifdef VERSION_US
void func_86508890(void) {
    s32 i;

    if (StageContext_GetFadeMode() == 1) {
        for (i = 0; i < 4; i++) {
            func_8003F1DC(&D_8650E6C0[i]);
            func_8003F114(&D_8650E120[i], 0, -1, D_8650DB28[i]);
            ModelAnim_SetEventFrame((u8 *)&D_8650E120[i], 0);
            func_8003F3BC(&D_8650E120[i], 0);
            func_8003F210(&D_8650E120[i], 0);
            ModelAnim_SetFrame((u8 *)&D_8650E120[i], (s16)(guRandom() % 15 + 15));
            D_86511698[i].animation = 0;
        }
        StageFade_StartFromOpaque(20);
        func_87F00688();
        D_8650C5EC = 6;
        return;
    }
    for (i = 0; i < 4; i++) {
        if (D_86511698[i].kind == 55) {
            Fragment53_UpdateTimedSecondaryAnimation(i);
        } else {
            Fragment53_UpdateSecondaryAnimation(i);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 StageFade_StartFromTransparent(s32);
extern s32 func_800226C0(s32);
extern s32 func_86501280();
s32 func_87F08208(s32 *);
extern s32 D_8650C5E0;
extern s32 D_8650DAD8;
extern void Audio_PlayDefaultSound(s32);
void func_86508A14(void) {
    s32 temp_v0;

    temp_v0 = func_87F08208(&D_8650DAD8);
    switch (temp_v0) {                              /* irregular */
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        func_86501280();
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 5;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        return;
    case 2:
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 2;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x4C))) = 1;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x58))) = 0;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        func_800226C0(3);
        return;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C5EC;
extern void *D_8650DB10;
void func_86508ABC(void) {
    if (StageContext_GetFadeMode() == 0) {
        if ((*(u8 *)((u8 *)(D_8650DB10) + (0x2180))) == 4) {
            StageFade_StartFromOpaque(0x14);
            func_87F00688();
            D_8650C5EC = 6;
            return;
        }
        D_8650C5EC = 4;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650DB40[];
extern s32 D_8650DB70[];
extern u32 func_87F006AC(void);
extern void func_80027774(u16, u8);
/* The caller discards this value; only the paused path specifies a result. */
s32 Fragment53_UpdateStartState(void) {
    s32 i;

    if (D_8650C494 == 1) {
        return 0;
    }
    if ((s32)func_87F006AC() == 1) {
        Audio_PlayDefaultSound(0x1F0D);
    }
    if ((s32)func_87F006AC() == 2) {
        Audio_PlayDefaultSound(0x1F0E);
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 1;
        *(s32 *)((u8 *)&D_8650C5E0 + 8) = -2;
        func_80027774(0x1B06, 140);
        *(s32 *)((u8 *)&D_8650C5E0 + 0x38) = 1;
        for (i = 0; i < 4; i++) {
            func_8003F114(D_8650DB80 + i * 0x168, 0, -1, D_8650DB40[i]);
            func_8003F114(D_8650F7A0 + i * 0x168, 0, -1, D_8650DB70[0]);
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_28E360/func_86508C2C.s")
#endif

#ifdef VERSION_US
extern s16 D_8650D3F8;
extern f32 D_8650D3FC;
extern s32 D_8650D404;
extern s32 D_8650DB7C;


void func_86509318(void)
{
  /* D_8650E120 is the 0x168-stride model array (fields named at 0x28/0xAC/0xB4);
     D_8650EC60 is the matching node array (fields named at 0x24/0x28/0x2C and the
     three 0.0f stores at 0x30/0x34/0x38). */
  struct F53ModelF {
    u8 pad00[0x28];
    f32 h;
    u8 pad2C[0x80];
    f32 z;
    u8 padB0[4];
    f32 x;
    u8 tail[0xB0];
  };
  struct F53NodeF {
    u8 pad00[0x1D];
    u8 u;
    u8 pad1E[6];
    f32 z;
    f32 h;
    f32 x;
    f32 b30, b34, b38;
    u8 tail[0x12C];
  };
  s32 temp_v0;
  s32 var_s2;
  u8 *var_s3;
  struct F53ModelF *temp_s1;
  struct F53NodeF *temp_s0;
  f32 zero;
  f32 dy;
  f32 *sc;
  sc = &D_8650D3FC;
 zero = *sc; var_s2 = 0; var_s3 = (u8 *) D_86511698; do { if ((*((s32 *) (var_s3 + 0xC))) == 6) {
      temp_s1 = (struct F53ModelF *)&D_8650E120[var_s2];
      if (((*((s32 *) (((u8 *) temp_s1) + 0x48))) >> 0x10) >= 0x3C)
      {
        temp_s0 = (struct F53NodeF *)&D_8650EC60[var_s2 * 0x168];
        if (((*((s32 *) (((u8 *) temp_s1) + 0x48))) >> 0x10) == 0x3C)
        {
          func_8003F114((u8 *) temp_s0, 0, -1, D_8650DB7C);
          func_8003F210((u8 *) temp_s0, 0);
          /* Same address as temp_s0, but written out again: uopt gives this
             recomputed node pointer an alias class relative to temp_s1, so as1
             can move the three model loads ahead of the three zero stores in the
             block below. Reusing temp_s0 here leaves the pointer unclassified and
             the loads stay under the stores. */
          *((u8 *) (((u8 *) &D_8650EC60[var_s2 * 0x168]) + 0x1D)) = 0;
          dy = *sc;
          zero = dy;
        }
        dy = (f32) D_8650D404;
        temp_v0 = temp_s0->u + 5;
        if (temp_v0 < 0xFF)
        {
          temp_s0->u = temp_v0;
        }
        else
        {
          temp_s0->u = 0xFF;
        }
        temp_s0->b38 = zero;
        temp_s0->b34 = zero;
        temp_s0->b30 = zero;
        temp_s0->x = temp_s1->x;
        temp_s0->z = temp_s1->z;
        temp_s0->h = temp_s1->h + dy;
        *((s16 *) (((u8 *) temp_s0) + 0x1E)) = D_8650D3F8;
      }
    }
    var_s2 += 1;
    var_s3 += 0x98;
  }
  while (var_s2 != 4);
}
#endif

#ifdef VERSION_US
s32 func_87F01A40();
extern s32 D_8650C494;
void func_86509480(void) {
    s32 temp_v0;

    D_8650C494 = 1;
    temp_v0 = func_87F01A40();
    switch (temp_v0) {                              /* irregular */
    case 0:
    case 2:
        D_8650C494 = 0;
        return;
    case 3:
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x58))) = 0;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 2;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x4C))) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    case 4:
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x58))) = 1;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 2;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x4C))) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_28E360/func_8650952C.s")
#endif

#ifdef VERSION_US
extern s32 func_87F02104(void);
void func_86509D8C(void) {
    s32 temp_v0;

    temp_v0 = func_87F02104();
    switch (temp_v0) {
    case 1:
        StageContext_SetClearColor(1);
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 0xC;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x4C) = 2;
        StageFade_StartFromTransparent(0xA);
        *(s32 *)((u8 *)&D_8650C5E0 + 0x8) = 0;
        return;
    case 2:
        *(s32 *)((u8 *)&D_8650C5E0 + 0x58) = 0;
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 2;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x4C) = 2;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    case 3:
        *(s32 *)((u8 *)&D_8650C5E0 + 0x58) = 1;
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 2;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x4C) = 2;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_8650DA38[];
extern s32 D_8650C638;
extern s32 func_87F0C6F4(u8 *);
extern s32 func_87F00930(void);
extern void func_87F006BC(void);
extern void func_81900214(s32);
extern s32 Fragment64_UpdateBounceAndConfirm(u8 *);
extern void func_87F02328(void);
extern void func_87F0D5B8(u8 *);

// Per-frame scene state dispatcher. Fragment53_RunScene passes the current state
// (D_8650C5EC) as arg0, but the dispatch reads the global directly; the state left
// in D_8650C5EC is returned to the caller.
s32 func_86509E54(s32 arg0) {
    // FAKE: returning through a u32 local reproduces the original's return-value registers.
    u32 state;

    if ((((u8 *)D_8650DB10)[0x2180] == 4) && (func_87F0C6F4(D_8650DA60) != 0)) {
        D_8650C5EC = 3;
        D_8650C638 = 3;
    }
    if ((func_87F00930() == 0) && (D_8650C5EC != 10)) {
        func_87F006BC();
    }
    switch (D_8650C5EC) {
        case 0:
            func_86508ABC();
            break;
        case 4:
            func_86508A14();
            break;
        case 5:
            func_86508890();
            break;
        case 6:
            func_86509480();
            func_86508B20();
            break;
        case 9:
            func_81900214(*(s32 *)D_865118F8);
            func_86509318();
            if (Fragment64_UpdateBounceAndConfirm(D_8650DA70) != 0) {
                if (((u8 *)D_8650DB10)[0x2180] == 1) {
                    StageContext_SetClearColor(0xFFFF);
                    StageFade_StartFromTransparent(10);
                    D_8650C638 = 2;
                    D_8650C5EC = 2;
                    D_8650C62C = 0;
                } else {
                    func_87F02328();
                    D_8650C5EC = 8;
                }
            }
            break;
        case 1:
            func_86509480();
            func_8650952C();
            break;
        case 8:
            func_86509D8C();
            break;
        case 12:
            if (StageContext_GetFadeMode() == 1) {
                func_86508484();
                D_8650C5EC = 11;
                StageFade_StartFromOpaque(10);
            }
            break;
        case 11:
            D_8650C5EC = 0;
            break;
        case 10:
            func_86508C2C();
            break;
        case 2:
            if (StageContext_GetFadeMode() == 1) {
                D_8650C5EC = 3;
            }
            break;
    }
    func_87F0D5B8(D_8650DA38);
    state = D_8650C5EC;
    return state;
}
#endif

#ifdef VERSION_US
extern s32 D_8650C4B0;
extern s32 D_8650C46C;
extern s32 D_8650C480[];
extern s32 D_8650C494;
extern s32 D_8650C504;
extern f32 D_8650C508;
extern s32 D_8650C5E0;
extern u8 D_865118F8[];
extern f32 D_8650D12C;
extern s32 D_8650D428;
extern s32 D_8650D42C;
extern s32 D_8650D9E0[];
extern u32 func_8003570C(void);


void func_8650A074(void) {
    s32 busy;
    s32 mode;
    s32 offset;
    struct Fragment53ActorState *state;

    s32 *p;
    s32 *q;

    p = &D_8650D42C;
    q = &D_8650D428;

    mode = *(s32 *)((u8 *)&D_8650C5E0 + 8);
    // FAKE: no-op kept only to steer uopt's register assignment; without it mode/offset
    // land in v1/v0 and the function scores 45 instead of 0 (80 without both no-ops).
    if (mode) {}
    if (mode == 0) {
        *(s32 *)((u8 *)&D_8650C5E0 + 0x18) += 1;
        if (*(s32 *)((u8 *)&D_8650C5E0 + 0x18) >= 21) {
            *(s32 *)((u8 *)&D_8650C5E0 + 0x18) = 0;
        }
        if (*(s32 *)((u8 *)&D_8650C5E0 + 0) == 0) {
            *q = 3;
            *p = 0;
        }
    }
    offset = D_8650D42C;
    if (mode == -1 && D_8650C494 == 0 &&
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) == 1) {
        D_8650C46C += 1;
    }
    if (D_8650C504 == 1) {
        *q = D_8650D9E0[*(s32 *)((u8 *)&D_8650C5E0 + 0)];
        offset = 0;
    }
    *p = offset;
    if ((f32)(D_8650C480[D_8650D428] + offset) < (f32)D_8650C46C * D_8650C508) {
        if (D_8650C494 == 0) {
            busy = 0;
            state = D_86511698;
            do {
                if (state->animation != 1) {
                    busy = 1;
                }
                state++;
            } while (state != (struct Fragment53ActorState *)D_865118F8);
            if (busy == 0) {
                D_8650C46C = 0;
                // FAKE: no-op kept only to steer uopt's register assignment; without it busy
                // and the loop-end pointer land in v1/a0 and the function scores 35 instead of 0.
                if (busy) {}
                offset = func_8003570C() % 51;
                *p = offset;
                if (offset < 15) {
                    *p = 0;
                }
                D_8650D12C = 0.0f;
                *q = func_8003570C() % 5;
                *(s32 *)((u8 *)&D_8650C5E0 + 8) = 1;
                D_8650D12C = 0.0f;
            }
            if (D_8650C4B0 < *(s32 *)((u8 *)&D_8650C5E0 + 0)) {
                *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 9;
                D_8650C494 = 1;
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void func_80064D28(void);
extern void func_8650A074(void);
extern void Fragment53_DrawSceneFrame(void);
extern s32 func_86509E54(s32);
void Fragment53_RunSceneTransition(void) {
    u8 *model;
    struct Fragment53ActorState *state;
    u8 *secondary;
    s32 *resource;
    s32 result;

    func_800086A4(2);
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) == 4) {
        secondary = (u8 *)D_8650E6C0; model = (u8 *)D_8650E120;
        resource = D_8650DB28; state = D_86511698; do {
            func_8003F1DC(secondary);
            func_8003F114(model, 0, -1, *resource);
            ModelAnim_SetEventFrame(model, 0);
            func_8003F3BC(model, 0);
            ModelAnim_SetAnimation(model, 0);
            ModelAnim_SetFrame(model, (s16)(guRandom() % 15 + 15));
            state++;
            secondary += 0x168;
            model += 0x168;
            resource++;
            state[-1].animation = 0;
        } while ((struct Fragment53ActorState *)D_865118F8 != state);
    }
    StageFade_StartFromOpaque(10);
    do {
        func_8650A074();
        func_80064D28();
        Fragment53_DrawSceneFrame();
        result = func_86509E54(*(s32 *)((u8 *)&D_8650C5E0 + 0xC));
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = result;
    } while (*(s32 *)((u8 *)&D_8650C5E0 + 0xC) != 3);
}
#endif

#ifdef VERSION_US
extern s32 D_8650DB18;
extern u32 D_8650DAE0;
extern u32 D_8650DA90;
extern s32 D_8650C638;
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern s32 func_80001FF0(void);
extern void func_80027EE0(s32);
extern void main_pool_push_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_87F06EAC(s32, void *, void *);
extern s32 func_8004DDF4(s32);
extern void func_8004C8C0(s32);
extern s32 func_8004DEF8(s32);
extern s32 func_8004D690(s32);
extern void func_80047588(u32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_87F00030(void);
extern void func_87F01F34(void *);
extern void func_86505EA8(void);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern void main_pool_pop_state(s32);
extern void func_87F0F480(void *);
s32 Fragment53_RunScene(s32 arg0, void *context) {
    s32 handle;

    if (func_80001FF0() == 60) {
        D_8650C508 = 1.0f;
    } else {
        D_8650C508 = 1.2f;
    }
    D_8650DB10 = context;
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) == 4) {
        func_80027EE0(0xFFF);
    }
    main_pool_push_state(0x4D523031);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    handle = func_800082E0(0, 1, 3, 1, 2, 1);
    func_8004C09C(0x127);
    func_87F06EAC(0x6B, &D_8650DAD8, D_8650DB10);
    func_8004DDF4(0x51);
    func_8004DDF4(0x6F);
    func_8004DDF4(0x70);
    func_8004DDF4(0x3B);
    func_8004C8C0(0x1B2);
    func_8004C8C0(0x1AD);
    func_8004C8C0(0x18D);
    func_8004C8C0(0x18F);
    func_8004C8C0(0x18E);
    D_8650DB18 = func_8004DEF8(0x3B);
    D_8650DB1C = (void *)func_8004D690(15);
    func_80047588(D_8650DAE0 | 5 | D_8650DA90, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_87F00030();
    func_87F01F34(D_8650DB10);
    func_86505EA8();
    func_80008514(handle);
    Fragment53_RunSceneTransition();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D523031);
    func_87F0F480(D_8650DB10);
    func_80027EE0(0xFFE);
    return D_8650C638;
}
#endif
