#include "global.h"
#include "controller.h"
#include "color_adjustment.h"

// Dialog geometry, transition state, counters and applied fraction.
// Copied as a 48-byte record by func_83306D0C.
typedef struct Fragment57DialogContext {
    s32 x, y, draw_x, draw_y, width, height;
    s32 state, phase, frame, limit, counting;
    f32 fraction;
} Fragment57DialogContext;
static Fragment57DialogContext sDialog;

// The rest of the loader-cleared runtime memory after sDialog (0x8330AC38-0x8330ACE0), in address order, so that
// func_83300CB0's function-scope statics land at 0x8330ACE0-0x8330ACF8.
static s32 D_8330AC38[8];
static s32 D_8330AC58;
static f32 D_8330AC5C;
static f32 D_8330AC60;
static s32 D_8330AC64; // unreferenced
static s32 D_8330AC68[0x19];
static f32 D_8330ACCC;
static f32 D_8330ACD0;
static f32 D_8330ACD4;
static f32 D_8330ACD8;
static f32 D_8330ACDC;


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83300020.s")

s32 func_83300398(s32 arg0, s32 arg1) {
    return arg0 + arg1 / 2;
}

struct unk_D_8330A2B0;
extern struct unk_D_8330A2B0 D_8330A2B0;
extern s32 D_8330AC08;
extern s32 D_8330907C[];
extern s32 D_83308E2C;
extern s32 D_83308E38[];
extern s32 D_833090B0[];
extern u8 *D_83308E34;

typedef struct Func833003B0Blob {
    s32 words[12];
} Func833003B0Blob;



void func_833003B0(s32 arg0) {
    s32 off;
    s32 temp;

    *(s32 *)((u8 *)&D_8330AC08 + 0x20) = 0;
    if (arg0 == 7) {
        *(s32 *)((u8 *)&D_8330AC08 + 0x28) = 1;
        *(s32 *)((u8 *)&D_8330AC08 + 0x24) = 5;
        return;
    }
    *(s32 *)((u8 *)&D_8330A2B0 + 8) = arg0;
    if (*(s16 *)(D_83308E34 + 2) == -1) {
        off = arg0 * 4;
        // FAKE: arg0 is dead after its store above; this assignment only stops uopt
        // from copy-propagating `off = arg0 * 4` into a CSE temp (which adds a
        // `move a2,v0`). Defining off inside this branch also gives the hoisted
        // `sll` a later .loc line, so as1 orders it after the condition's `li at,-1`.
        switch (*(s32 *)((u8 *)D_83308E38 + off)) {
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            return;
        case 16:
            *(Func833003B0Blob *)&D_8330AC08 = *(Func833003B0Blob *)D_8330907C;
            *(s32 *)((u8 *)&D_8330AC08 + 0x18) = 1;
            break;
        }
    } else {
        off = *(s32 *)((u8 *)&D_8330A2B0 + 8) * 4;
        switch (*(s32 *)((u8 *)D_83308E38 + off)) {
        case 11:
            *(Func833003B0Blob *)&D_8330AC08 = *(Func833003B0Blob *)D_8330907C;
            *(s32 *)((u8 *)&D_8330AC08 + 0x28) = 1;
            *(s32 *)((u8 *)&D_8330AC08 + 0x18) = 1;
            break;
        case 12:
        case 14:
            *(Func833003B0Blob *)&D_8330AC08 = *(Func833003B0Blob *)D_8330907C;
            *(s32 *)((u8 *)&D_8330AC08 + 0x18) = 1;
            break;
        case 13:
            *(s32 *)((u8 *)&D_8330AC08 + 0x28) = 1;
            break;
        }
    }
    *(s32 *)((u8 *)&D_8330AC08 + 0xC) = *(s32 *)((u8 *)D_833090B0 + off);
    *(s32 *)((u8 *)&D_8330AC08 + 4) = func_83300398(*(s32 *)((u8 *)&D_8330AC08 + 0xC), *(s32 *)((u8 *)&D_8330AC08 + 0x14));
    temp = D_83308E38[*(s32 *)((u8 *)&D_8330A2B0 + 8)];
    if (temp == 11) {
        *(s32 *)((u8 *)&D_8330AC08 + 0x24) = D_83308E2C * 4;
    }
    if (temp == 13) {
        *(s32 *)((u8 *)&D_8330AC08 + 0x24) = (s32)((f64)D_83308E2C * 1.3);
    }
    if (temp == 17) {
        *(s32 *)((u8 *)&D_8330A2B0 + 0x54) = -1;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_833005F0.s")

typedef struct unk_8330084C {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8 unk_18[0x2C - 0x18];
    /* 0x2C */ f32 unk_2C;
} unk_8330084C;

extern void *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern void Gfx_FillRectRgba(s16, s16, s16, s16, u8, u8, u8, u8);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern u8 *func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_833005F0(void *);

#define gDL (*(Gfx **)&D_800D0510)

// The result of func_8004CA60() is parked in an untyped temp `p` first, so the
// copy into the callee-saved `tex` register is emitted at loop entry, after
// the `i = 0` move (target order: or s3,zero,zero then or s6,zero,v0).


void func_8330084C(unk_8330084C *arg0) {
    s32 pad[4]; // FAKE: pads the frame to 0x90 bytes; never accessed
    s32 x = arg0->unk_08, y = arg0->unk_0C;
    s32 w = (s32)((f32)arg0->unk_10 * arg0->unk_2C);
    s32 h = (s32)((f32)arg0->unk_14 * arg0->unk_2C);
    s32 alpha;
    s32 i;
    s32 qh;
    s32 qw;
    s32 qy;
    s32 qx;
    u8 *tex;
    u8 *p; // temp for the func_8004CA60 result; defers the tex copy to loop entry

    if (h == 0) {} // FAKE: empty if; without it uopt colors w as s7 and h as s8, with it w is fp and h is s7 as in the target

    if (h < 22) {
        h = 22;
    }
    if (w >= 97) {
        alpha = 255;
    } else {
        alpha = w * 255 / 96;
    }

    gDPPipeSync(gDL++);
    gDPSetCycleType(gDL++, G_CYC_1CYCLE);
    gDPSetPrimColor(gDL++, 0, 0, 255, 255, 200, alpha);
    gDPSetCombine(gDL++, 0xFFFFFF, 0xFFFDF6FB);
    gDPSetRenderMode(gDL++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    Gfx_FillRectRgba((s16)(x + 5), (s16)(y + 5), (s16)(w - 10), (s16)(h - 10), 0, 0, 0x3C, alpha);
    func_833005F0(arg0);
    gSPDisplayList(gDL++, D_80094E38);
    p = func_8004CA60(func_8004C990(0x4E, 0));
    i = 0;
    tex = p;
    for (; i < 4; i++, tex += 0x100) {
        gDPLoadTextureBlockS(gDL++, tex, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0,
                             G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                             G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        switch (i) {
            case 0:
                qx = x;
                qy = y;
                qw = w - 16;
                qh = h - 16;
                break;
            case 1:
                qx = x + w - 16;
                qy = y;
                qw = 16;
                qh = h - 16;
                break;
            case 2:
                qx = x;
                qy = y + h - 16;
                qw = w - 16;
                qh = 16;
                break;
            case 3:
                qx = x + w - 16; qy = y + h - 16; qw = 16; qh = 16;
                break;
        }
        GfxRect_DrawTextured((s16)qx, (s16)qy, (s16)qw, (s16)qh, 0, 0, 0x400, 0x400, 0);
    }
    gSPDisplayList(gDL++, D_80094F50);
}

typedef struct unk_D_8330A2B0 {
    /* 0x00 */ u8 unk_00[0xC];
    /* 0x0C */ s32 frame;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u8 unk_14[0x30 - 0x14];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ u8 unk_34[0x40 - 0x34];
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ u8 unk_4C[0x5C - 0x4C];
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ u8 unk_7C[0x80 - 0x7C];
    /* 0x80 */ f32 unk_80;
    /* 0x84 */ u8 unk_84[0x98 - 0x84];
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ u8 unk_9C[0xB8 - 0x9C];
    /* 0xB8 */ f32 unk_B8;
    /* 0xBC */ f32 unk_BC;
    /* 0xC0 */ f32 unk_C0;
    /* 0xC4 */ f32 cameraPos[3];
    /* 0xD0 */ f32 cameraAt[3];
    /* 0xDC */ f32 unk_DC;
    /* 0xE0 */ f32 unk_E0;
    /* 0xE4 */ u8 unk_E4[2][0x14];
    /* 0x10C */ u8 unk_10C[4];
} unk_D_8330A2B0;
extern s32 func_83300020(s32);
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern void func_80037120(void *, void *, f32 *, s16 *, s16 *);
extern void func_800371B4(void *, f32 *, f32, s16, s16);
extern u8 D_8330A380[];
extern u8 D_8330A338[];
extern u8 D_8330A32C[];
extern u8 D_8330A374[];
extern u8 D_8330A35C[];
extern f32 D_8330ACDC;
extern s16 D_833090D4;
extern s16 D_833090D8;
extern s16 D_833090DC;
extern s32 D_8330ABD8;
extern s16 D_83308760[];
extern s16 D_83308770[];
extern s16 D_83308A9C[];
typedef struct { s32 w[17]; } Func83300CB0Entry;
extern Func83300CB0Entry D_83308E9C[];
extern f32 D_8330AC5C;
extern f32 D_8330AC60;
extern f32 D_8330ACCC;
extern f32 D_8330ACD0;
extern f32 D_8330ACD4;
extern f32 D_8330ACD8;

s32 func_83300CB0(s32 arg0, u8 *arg1) {
    static f32 D_8330ACE0;
    static s32 D_8330ACE4; // FAKE
    static s32 D_8330ACE8;
    static s16 *D_8330ACEC;
    static s32 D_8330ACF0;
    static s16 D_8330ACF4;
    static s16 D_8330ACF6;
    s32 ang; // FAKE
    f32 d1, d2, d3, d4, d5;
    s16 x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    f32 v70[3];
    f32 v64[3];
    f32 v58[3];
    f32 vpad[3]; // FAKE
    f32 v40[3];

    D_8330ACE0 = sqrtf(D_8330A2B0.cameraPos[2] * D_8330A2B0.cameraPos[2] + D_8330A2B0.cameraPos[1] * D_8330A2B0.cameraPos[1]);
    GeoCamera_SetPerspective((void *)arg1, 45.0f, D_8330A2B0.unk_DC, D_8330A2B0.unk_E0);
    switch (D_8330A2B0.unk_10) {
    case 1:
        D_8330ACEC = D_83308760;
        D_8330ACF0 = 0;
        break;
    case 2:
        D_8330ACEC = D_83308770;
        D_8330ACF0 = 1;
        break;
    case 3:
        D_8330ACEC = D_83308A9C;
        D_8330ACF0 = 2;
        break;
    case 4:
        if (D_8330A2B0.unk_40 == 1) {
            D_833090DC = (&D_833090D8)[2] + 0x40;
            func_83300020(0);
            D_8330ACF6 = 0;
            D_8330ACF4 = 0;
            d2 = 0.0f;
            d3 = 0.0f;
        }
        func_80037120(D_8330A380, D_8330A338, &d1, &x1, &y1);
        func_80037120(D_8330A380, D_8330A32C, &d2, &x2, &y2);
        func_80037120(D_8330A338, D_8330A32C, &d3, &x3, &y3);
        func_80037120(D_8330A374, D_8330A35C, &d4, &x4, &y4);
        if ((d4 > 40.0f || d2 > 40.0f) && D_8330A2B0.unk_30 == 0) {
            if (D_8330ACF4 > 0x4000) {
                D_8330ACF4 = 0x4000;
            }
            D_8330ACF4 += 0x400;
            func_800371B4(D_8330A380, v58, D_80087E50[(u16)D_8330ACF4 >> 4] * (d2 * 0.15), x2, y2);
            Vec3f_SetComponentsDuplicate((f32 *)D_8330A380, v58[0], v58[1], v58[2]);
            func_800371B4(D_8330A374, v64, D_80087E50[(u16)D_8330ACF4 >> 4] * (d4 * 0.05), x4, y4);
            Vec3f_SetComponentsDuplicate((f32 *)D_8330A374, v64[0], v64[1], v64[2]);
        } else {
            D_8330A2B0.unk_48 = 1;
            D_8330ACF4 = 0;
            if (D_8330A2B0.unk_6C < d3) {
                if (D_8330A2B0.unk_68 < d1 && D_8330A2B0.unk_30 == 1) {
                    D_8330A2B0.unk_44 = 1;
                    func_800371B4(D_8330A380, v70, d1 * D_8330A2B0.unk_60, x1, y1);
                    if (D_8330ABD8 != 0x79 || !(D_8330A2B0.cameraAt[1] < D_8330A2B0.unk_80)) {
                        Vec3f_SetComponentsDuplicate((f32 *)D_8330A380, v70[0], v70[1], v70[2]);
                    }
                    D_8330ACF4 += 0x800;
                    D_8330ACF6 = 0;
                }
            } else if (D_8330A2B0.unk_44 == 1) {
                if (d2 < 10.0f && D_8330A2B0.unk_30 == 0) {
                    D_8330A2B0.unk_44 = 0;
                }
                if (D_8330ACF6 > 0x4000) {
                    D_8330ACF6 = 0x4000;
                }
                func_800371B4(D_8330A380, v58, d2 * D_8330A2B0.unk_64, x2, y2);
                Vec3f_SetComponentsDuplicate(v40, D_8330A2B0.cameraAt[0], D_8330A2B0.cameraAt[1], D_8330A2B0.cameraAt[2]);
                Vec3f_SetComponentsDuplicate((f32 *)D_8330A380, v58[0], v58[1], v58[2]);
                func_80037120(D_8330A380, D_8330A338, &d5, &x5, &y5);
                if (d5 < D_8330A2B0.unk_68 || D_8330A2B0.unk_30 == 0) {
                    D_8330ACF6 += 0x400;
                    D_8330ACF4 = 0;
                } else {
                    Vec3f_SetComponentsDuplicate((f32 *)D_8330A380, v40[0], v40[1], v40[2]);
                }
            }
        }
        func_80038E14(arg1, D_8330A2B0.cameraAt[0] + D_8330A2B0.cameraPos[0] + D_8330A2B0.unk_B8, D_8330A2B0.cameraAt[1] + D_8330A2B0.cameraPos[1] + D_8330A2B0.unk_BC,
                      D_8330A2B0.cameraAt[2] + D_8330A2B0.cameraPos[2] + D_8330A2B0.unk_C0, D_8330A2B0.cameraAt[0], D_8330A2B0.cameraAt[1], D_8330A2B0.cameraAt[2], 0);
        /* fallthrough */
    default:
        D_8330A2B0.unk_DC = 100.0f;
        GeoCamera_SetPerspective((void *)arg1, 45.0f, D_8330A2B0.unk_DC, D_8330A2B0.unk_E0);
        func_80038E14(arg1,
                      D_8330A2B0.cameraAt[0] + ((D_8330ACE0 * D_80088E50[(u16)D_833090D8 >> 4]) * D_80088E50[(u16)D_833090D4 >> 4] + 1.0f) + D_8330A2B0.unk_B8,
                      D_8330A2B0.cameraAt[1] + D_80087E50[(u16)D_833090D8 >> 4] * D_8330ACE0 + D_8330A2B0.unk_BC,
                      D_8330A2B0.cameraAt[2] + (D_8330ACE0 * D_80088E50[(u16)D_833090D8 >> 4]) * D_80087E50[(u16)D_833090D4 >> 4] + D_8330A2B0.unk_C0,
                      D_8330A2B0.cameraAt[0], D_8330A2B0.cameraAt[1], D_8330A2B0.cameraAt[2], 0);
        return 0;
    }
    D_8330ACE8 = 1;
    if (D_83308E9C[D_8330ACF0].w[15] == 1) {
        D_8330ACE8 = 0;
    }
    D_8330ACDC = (D_8330ACEC + D_83308E9C[D_8330ACF0].w[16])[D_8330A2B0.frame * D_8330ACE8];
    GeoCamera_SetPerspective((void *)arg1, D_8330ACDC, D_8330A2B0.unk_DC, D_8330A2B0.unk_E0);
    D_8330ACE8 = 1;
    if (D_83308E9C[D_8330ACF0].w[1] == 1) {
        D_8330ACE8 = 0;
    }
    D_8330AC5C = (D_8330ACEC + D_83308E9C[D_8330ACF0].w[2])[D_8330A2B0.frame * D_8330ACE8];
    D_8330ACE8 = 1;
    if (D_83308E9C[D_8330ACF0].w[3] == 1) {
        D_8330ACE8 = 0;
    }
    D_8330AC60 = (D_8330ACEC + D_83308E9C[D_8330ACF0].w[4])[D_8330A2B0.frame * D_8330ACE8];
    D_8330ACE8 = 1;
    if (D_83308E9C[D_8330ACF0].w[5] == 1) {
        D_8330ACE8 = 0;
    }
    D_8330ACCC = (D_8330ACEC + D_83308E9C[D_8330ACF0].w[6])[D_8330A2B0.frame * D_8330ACE8];
    D_8330ACE8 = 1;
    if (D_83308E9C[D_8330ACF0].w[7] == 1) {
        D_8330ACE8 = 0;
    }
    D_8330ACD0 = (D_8330ACEC + D_83308E9C[D_8330ACF0].w[8])[D_8330A2B0.frame * D_8330ACE8];
    D_8330ACE8 = 1;
    if (D_83308E9C[D_8330ACF0].w[9] == 1) {
        D_8330ACE8 = 0;
    }
    D_8330ACD4 = (D_8330ACEC + D_83308E9C[D_8330ACF0].w[10])[D_8330A2B0.frame * D_8330ACE8];
    D_8330ACE8 = 1;
    if (D_83308E9C[D_8330ACF0].w[11] == 1) {
        D_8330ACE8 = 0;
    }
    D_8330ACD8 = (D_8330ACEC + D_83308E9C[D_8330ACF0].w[12])[D_8330A2B0.frame * D_8330ACE8];
    func_80038E14(arg1, D_8330AC5C, D_8330AC60, D_8330ACCC, D_8330ACD0, D_8330ACD4, D_8330ACD8, 0);
    return 0;
}


/* mkdraft:func_833015C8 begin */
extern void *D_80094908;
extern void func_80037120(void *, void *, f32 *, s16 *, s16 *);
struct unk_D_8330A2B0;
extern struct unk_D_8330A2B0 D_8330A2B0;



s32 func_833015C8(s32 arg0, u8 *arg1) {
    typedef struct {
        u8 unk_00[0xE4];
        u8 unk_E4[8];
    } Overlay;
    s32 i;
    u8 *dst = arg1;
    s32 mode_flag;
    f32 distance;
    s16 angleX;
    s16 angleY;

    if (arg0 == 2) {
        for (i = 0; i < 3; i++) {
            dst[0x18 + i] = ((Overlay *)&D_8330A2B0)->unk_E4[i];
        }
        dst[0x1B] = *(u8 *)((u8 *)&D_8330A2B0 + 0xE7);
        if (*(s32 *)((u8 *)&D_8330A2B0 + 0x18) == 2 && *(s32 *)((u8 *)&D_8330A2B0 + 0x1C) == 0) {
            if (D_80087200->stickX >= 6) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0xF6) += 256;
            }
            if (D_80087200->stickX < -5) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0xF6) -= 256;
            }
            if (D_80087200->stickY >= 6) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0xF4) += 256;
            }
            if (D_80087200->stickY < -5) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0xF4) -= 256;
            }
        }
        mode_flag = 1;
        if (*(s32 *)((u8 *)&D_8330A2B0 + 0x10) > 0 && *(s32 *)((u8 *)&D_8330A2B0 + 0x10) < 4) {
            mode_flag = 0;
        }
        func_80037120((u8 *)D_80094908 + 0xB4, (u8 *)D_80094908 + 0xA8, &distance, &angleX, &angleY);
        *(s16 *)(dst + 0x1C) = (*(s16 *)((u8 *)&D_8330A2B0 + 0xF4) + angleX) + 0x2000;
        *(s16 *)(dst + 0x1E) = angleY - ((*(s16 *)((u8 *)&D_8330A2B0 + 0xF6) + 0x2000) * mode_flag);
    }
    return 0;
}
/* mkdraft:func_833015C8 end */

/* mkdraft:func_8330173C begin */
extern void *D_80094908;
extern void func_80037120(void *, void *, f32 *, s16 *, s16 *);
struct unk_D_8330A2B0;
extern struct unk_D_8330A2B0 D_8330A2B0;



s32 func_8330173C(s32 arg0, u8 *arg1) {
    typedef struct {
        u8 unk_00[0xF8];
        u8 unk_F8[8];
    } Overlay;
    s32 i;
    u8 *dst = arg1;
    s32 mode_flag;
    f32 distance;
    s16 angleX;
    s16 angleY;

    if (arg0 == 2) {
        for (i = 0; i < 3; i++) {
            dst[0x18 + i] = ((Overlay *)&D_8330A2B0)->unk_F8[i];
        }
        dst[0x1B] = *(u8 *)((u8 *)&D_8330A2B0 + 0xFB);
        if (*(s32 *)((u8 *)&D_8330A2B0 + 0x18) == 2 && *(s32 *)((u8 *)&D_8330A2B0 + 0x1C) == 1) {
            if (D_80087200->stickX >= 6) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0x10A) += 256;
            }
            if (D_80087200->stickX < -5) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0x10A) -= 256;
            }
            if (D_80087200->stickY >= 6) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0x108) += 256;
            }
            if (D_80087200->stickY < -5) {
                *(s16 *)((u8 *)&D_8330A2B0 + 0x108) -= 256;
            }
        }
        mode_flag = 1;
        if (*(s32 *)((u8 *)&D_8330A2B0 + 0x10) > 0 && *(s32 *)((u8 *)&D_8330A2B0 + 0x10) < 4) {
            mode_flag = 0;
        }
        func_80037120((u8 *)D_80094908 + 0xB4, (u8 *)D_80094908 + 0xA8, &distance, &angleX, &angleY);
        *(s16 *)(dst + 0x1C) = -0x2000 - (u32)(*(s16 *)((u8 *)&D_8330A2B0 + 0x108) + angleX);
        *(s16 *)(dst + 0x1E) = (*(s16 *)((u8 *)&D_8330A2B0 + 0x10A) + 0x6000) * mode_flag + angleY;
    }
    return 0;
}
/* mkdraft:func_8330173C end */

// Fields of D_8330A2B0 that func_83303AB0 writes and func_83302AC8 prints. D_8330A344 (+0x94) and D_8330A368 (+0xB8) are
// three-float vectors inside this object; unk_98 and unk_C0 alias their second and third components.

extern unk_D_8330A2B0 D_8330A2B0;

s32 func_833018B8(s32 arg0, void *arg1) {
    if (arg0 == 2) {
        (*(u8 *)((u8 *)(arg1) + (0x18))) = (u8) (*(u8 *)((u8 *)(&D_8330A2B0) + (0x10C)));
        (*(u8 *)((u8 *)(arg1) + (0x19))) = (u8) (*(u8 *)((u8 *)(&D_8330A2B0) + (0x10D)));
        (*(u8 *)((u8 *)(arg1) + (0x1A))) = (u8) (*(u8 *)((u8 *)(&D_8330A2B0) + (0x10E)));
    }
    return 0;
}

extern u8 *D_83308E34;
extern ColorAdjustment D_8330A2A4;
extern s32 D_8330A2A8;
extern s32 D_8330A4CC;
extern u16 D_8330ABDA;
extern s32 D_8330ABDC;
extern s32 D_8330A300;
extern s32 D_8330ABE0;
extern s32 func_80041FD0(s32, u16, ColorAdjustment, s32);
extern ColorAdjustment func_8003F5AC(u8 *);
extern s32 func_8006456C(s32);
typedef struct unk_func_833018E8 {
    u8 unk_00[2];
    u8 unk_02[4];
    u8 unk_06[16];
    u16 unk_16;
} unk_func_833018E8;
void func_833018E8(void) {
    unk_func_833018E8 *var_s0 = (unk_func_833018E8 *)(D_83308E34 + 4);
    s32 var_v0;

    func_80041FD0(D_8330A4CC, D_8330ABDA, D_8330A2A4, D_8330A2A8);
    D_8330A2A4 = func_8003F5AC((u8 *)var_s0);
    D_8330A2A8 = func_8006456C(var_s0->unk_16);
    if (*(s16 *)(D_83308E34 + 2) != -1) {
        D_8330ABDC = var_s0->unk_02[*(s16 *)(D_83308E34 + 2)];
        D_8330A300 = *(s16 *)(D_83308E34 + 2);
    } else {
        for (var_v0 = 3; var_v0 >= 0; var_v0--) {
            if (var_s0->unk_02[var_v0] != 0) {
                D_8330ABDC = var_s0->unk_02[var_v0];
                D_8330A300 = var_v0 + 1;
                break;
            }
        }
    }
    D_8330ABE0 = *(s16 *)D_83308E34;
}

extern s32 D_833090AC;
extern s32 D_8330ABD8;
extern ColorAdjustment D_833091DC;
extern void func_80041FA0(s32, u16, ColorAdjustment);
extern u32 func_8003570C(void);
// Declared non-void here: retail never reuses $v0 after this call.
extern s32 func_800428F8(s32);
extern void *func_80004B4C(s32, s32);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern u8 *D_8330AC00;
extern u8 *D_8330AC04;
extern s32 D_8330A4D0;
extern s32 D_8330ABE0;
extern void func_83303AB0(s32);
extern void func_83305C1C(s32);
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern s32 Gfx_InitDisplayListBuffers(s32, s32);
extern s32 func_80041C98(s32);
extern void func_833018E8(void);
extern f32 func_8004B888(s32);
extern s32 func_8003F2C4(s32, s32 *, s32);
extern s32 func_8003F3BC(s32 *, s32);
#define A2B0_F(off) (*(f32 *)((u8 *)&D_8330A2B0 + (off)))
#define A2B0_S(off) (*(s32 *)((u8 *)&D_8330A2B0 + (off)))
#define A4D0_F(off) (*(f32 *)((u8 *)&D_8330A4D0 + (off)))
void func_833019CC(void) {
    f32 scale;

    A2B0_S(0x48) = 0;
    A2B0_S(0x44) = 0;
    A2B0_F(0xC8) = 600.0f;
    A2B0_F(0x5C) = 0.0f;
    A2B0_F(0xC4) = 0.0f;
    A2B0_F(0xAC) = 0.0f;
    A2B0_F(0xCC) = 700.0f;
    A2B0_F(0xB0) = 200.0f;
    A2B0_F(0xB4) = 1500.0f;
    A2B0_F(0xD4) = 300.0f;
    A2B0_S(0x40) = 1;
    A2B0_S(0x30) = 0;
    A2B0_F(0xD0) = 0.0f;
    A2B0_F(0xD8) = 0.0f;
    A2B0_F(0x7C) = 0.0f;
    A2B0_F(0x80) = 0.0f;
    A2B0_F(0x84) = 0.0f;
    func_83303AB0(D_8330ABD8);
    func_83305C1C(D_8330ABD8);
    main_pool_push_state('SWCH');
    Gfx_InitDisplayListBuffers(0x20000, 0);
    D_8330A4CC = func_80041C98(1);
    if (D_833090AC == 1) {
        D_8330ABDC = func_8003570C() % 101 + 1;
        D_8330ABE0 = func_8003570C() % 101 + 1;
        func_80041FA0(D_8330A4CC, D_8330ABDA, D_833091DC);
    } else {
        func_833018E8();
    }
    func_800428F8(D_8330A4CC);
    A2B0_S(0x28) = 0;
    D_8330AC00 = D_8330AC04;
    *(s16 *)(D_8330AC00 + 0x658) = D_8330ABD8;
    *(void **)(D_8330AC00 + 0x2D4) = func_80004B4C(*(s32 *)(D_8330AC00 + 0x2D0), *(s16 *)(D_8330AC00 + 0x658) - 1);
    func_8003F1DC(&D_8330A4D0);
    func_8003F114((u8 *)&D_8330A4D0, 0, D_8330ABDA, **(void ***)(*(u8 **)(D_8330A4CC + 0x38) + 8));
    scale = func_8004B888(*(s16 *)(D_8330AC00 + 0x658));
    A4D0_F(0x38) = scale;
    A4D0_F(0x34) = scale;
    A4D0_F(0x30) = scale;
    *((u8 *)&D_8330A4D0 + 2) &= ~0x40;
    A4D0_F(0x24) = A2B0_F(0x70);
    A4D0_F(0x28) = A2B0_F(0x74);
    A4D0_F(0x2C) = A2B0_F(0x78);
    A2B0_S(0x34) = *(u8 *)(*(u8 **)(D_8330AC00 + 0x2D4) + 0x13B0);
    A2B0_S(0x38) = *(s8 *)(*(u8 **)(D_8330AC00 + 0x2D4) + 0x13B1);
    if (A2B0_S(0x34) == 0) {
        A2B0_S(0x34) = 3;
        A2B0_S(0x38) = 3;
    }
    func_8003F2C4(D_8330A4CC, &D_8330A4D0, 0);
    func_8003F3BC(&D_8330A4D0, 0);
    main_pool_pop_state('SWCH');
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83301C60.s")

/* mkdraft:func_83302088 begin */
extern f32 D_833091E4;

// Zoom-in step on the record passed in arg0; its only caller, func_83302D8C,
// enters with $a0 = &D_8330AC08 and does not reload it before the call.
// 0x1C caches the offset's progress: -1 unstarted (reset to 0 here), 0 in
// progress, 1 once the offset has clamped. The offset in D_833091E4 is reset to
// 4.0, grows by 8 per step and is capped at half of the value at 0x10; 0x08 and
// 0x0C receive the position moved inward by it (0x0C by the offset scaled with
// 0x14/0x10), and 0x2C the applied fraction of that half span.
// func_8340135C in fragment58 is the same routine against D_83403F18.
// D_833091E4 is defined in asm/us/data/fragments/57/fragment57_data.data.s.


void func_83302088(void *arg0) {
    f32 *offset_accum = &D_833091E4;
    f32 half_span;
    f32 offset;
    f32 ratio;
    s32 new_x;
    s32 x;
    s32 span;
    s32 state;
    s32 state_clamped;

    state_clamped = 1;
    state = *(s32 *)((u8 *)arg0 + 0x1C);
    if (state == -1) {
        // FAKE: one statement expression. As three statements the
        // sw zero,0x1C moves ahead of the lui $at,%hi(D_833091E4) that the
        // final store shares (diff score 60).
        *(s32 *)((u8 *)arg0 + 0x1C) = state = 0, offset = 4.0f, *offset_accum = offset;
        // karodo: empty test, emits nothing. Its use of offset is what keeps the
        // reset's 4.0f constant in $f0; without it, or with if (1), the mtc1
        // targets $f4 and every later FPR shifts (diff score 190).
        if (offset) {
        }
    }
    offset = *offset_accum;
    if (state_clamped != state) {
        offset = offset + 8.0f;
        span = *(s32 *)((u8 *)arg0 + 0x10);
        half_span = (f32) (span / 2);
        if (half_span < offset) {
            offset = half_span;
            *(s32 *)((u8 *)arg0 + 0x1C) = state_clamped;
        }
        ratio = (f32) *(s32 *)((u8 *)arg0 + 0x14) / (f32) span;
        x = *(s32 *)((u8 *)arg0 + 0);
        new_x = (s32) ((f32) x - offset);
        *(s32 *)((u8 *)arg0 + 8) = new_x;
        *(s32 *)((u8 *)arg0 + 0xC) = (s32) ((f32) *(s32 *)((u8 *)arg0 + 4) - offset * ratio);
        *(f32 *)((u8 *)arg0 + 0x2C) = (f32) (x - new_x) / half_span;
        *offset_accum = offset;
    }
}
/* mkdraft:func_83302088 end */

/* mkdraft:func_83302180 begin */
extern f32 D_833091EC;



void func_83302180(void *arg0) {
    f32 *D_833091EC_ptr = &D_833091EC;
    f32 temp_fv0;
    f32 ratio;
    s32 temp_v0;

    if (*(s32 *)((u8 *)arg0 + 0x1C) == -1) {
        *(s32 *)((u8 *)arg0 + 0x1C) = 0;
        temp_fv0 = (f32)(*(s32 *)((u8 *)arg0 + 0x10) / 2);
        (*D_833091EC_ptr) = temp_fv0;
    }
    temp_fv0 = (*D_833091EC_ptr);
    if (1) {} // karodo: the empty if gives uopt a statement boundary here; without it the D_833091EC load is scheduled after the 10.0f and 16.0f materializations (diff score 530).
    temp_fv0 = temp_fv0 - 16.0f;
    if (temp_fv0 < 10.0f) {
        *(s32 *)((u8 *)arg0 + 0x18) = 0;
        (*D_833091EC_ptr) = 10.0f;
        return;
    }
    temp_v0 = *(s32 *)((u8 *)arg0 + 0x10);
    ratio = (f32)*(s32 *)((u8 *)arg0 + 0x14) / (f32)temp_v0;
    *(s32 *)((u8 *)arg0 + 8) = (s32)((f32)*(s32 *)((u8 *)arg0 + 0) - temp_fv0);
    *(s32 *)((u8 *)arg0 + 0xC) = (s32)((f32)*(s32 *)((u8 *)arg0 + 4) - temp_fv0 * ratio);
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32)(*(s32 *)((u8 *)arg0 + 0) - *(s32 *)((u8 *)arg0 + 8)) / (f32)(temp_v0 / 2);
    (*D_833091EC_ptr) = temp_fv0;
}
/* mkdraft:func_83302180 end */


extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800497E4(s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void Font_DisableTwoCycleTexturing(void);
extern s32 D_8330A2CC;

// IDO pads this object's .data section to 16 bytes. Its first word, 0x833091F0, is not
// referenced by any code; it is carried here so func_83302290's blink counter lands at
// 0x833091F4 and the following data blob stays in place.
f32 D_833091F0 = 0.0f;

#define F32(off) (*(f32 *)((u8 *)&D_8330A2B0 + (off)))
#define S32(off) (*(s32 *)((u8 *)&D_8330A2B0 + (off)))
// 20-byte light records start at D_8330A2B0 + 0xE4 (color) / + 0xF4 (direction).
#define LIGHT(i) ((u8 *)&D_8330A2B0 + (i) * 20)

// Debug pause overlay: prints "PAUSE" and either the camera/monster tuning values
// (D_8330A2B0.unk_10 >= 4, cursor at unk_2C) or the lighting values (cursor at unk_18,
// selected light at D_8330A2CC). The selected row blinks via a 21-frame counter.
void func_83302290(void) {
    // Function-scope static: retail reloads its %hi for every access, which IDO does not
    // do for an extern or a file-scope static (both get one cached address register).
    static s32 D_833091F4 = 0;
    s32 idx;

    D_833091F4++;
    if (D_833091F4 >= 21) {
        D_833091F4 = 0;
    }
    func_800498C4();
    func_800496A4(1, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(255, 255, 255, 255);
    func_800497E4(255, 255, 255, 255);
    idx = D_8330A2CC;
    func_800495F8(0xA0, 0x19, 1, "PAUSE");
    if (S32(0x10) >= 4) {
        if (S32(0x2C) != 13 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 40, 0, "offsety:%0.1f ", (f64)F32(0x5c));
        }
        if (S32(0x2C) != 0 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 50, 0, "monsoffset x:%0.1f ", (f64)F32(0x94));
        }
        if (S32(0x2C) != 1 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 60, 0, "monsoffset y:%0.1f ", (f64)F32(0x98));
        }
        if (S32(0x2C) != 2 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 70, 0, "monsoffset z:%0.1f ", (f64)F32(0x9c));
        }
        if (S32(0x2C) != 3 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 80, 0, "cameraoffset x:%0.1f ", (f64)F32(0xb8));
        }
        if (S32(0x2C) != 4 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 90, 0, "cameraoffset y:%0.1f ", (f64)F32(0xbc));
        }
        if (S32(0x2C) != 5 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 100, 0, "cameraoffset z:%0.1f ", (f64)F32(0xc0));
        }
        if (S32(0x2C) != 6 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 110, 0, "move speed:%0.2f", (f64)F32(0x60));
        }
        if (S32(0x2C) != 7 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 120, 0, "move speed2:%0.2f", (f64)F32(0x64));
        }
        if (S32(0x2C) != 8 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 130, 0, "search null:%0.1f ", (f64)F32(0x68));
        }
        if (S32(0x2C) != 9 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 140, 0, "search look:%0.1f ", (f64)F32(0x6c));
        }
        if (S32(0x2C) != 10 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 150, 0, "posx:%0.1f ", (f64)F32(0x70));
        }
        if (S32(0x2C) != 11 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 160, 0, "posy:%0.1f ", (f64)F32(0x74));
        }
        if (S32(0x2C) != 12 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 170, 0, "posz:%0.1f ", (f64)F32(0x78));
        }
    } else {
        if (S32(0x18) != 0 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 0x32, 0, "camera near:%0.1f ", (f64)F32(0xDC));
        }
        if (S32(0x18) != 1 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 0x3C, 0, "camera far :%0.1f ", (f64)F32(0xE0));
        }
        if (S32(0x18) != 2 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 0x46, 0, "lightno :%d", idx);
        }
        func_800495F8(0xA0, 0x50, 0, "(a_x=%5x a_y=%5x)", *(s16 *)(LIGHT(idx) + 0xF4), *(s16 *)(LIGHT(idx) + 0xF6));
        if (S32(0x18) != 3 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 90, 0, "diff_r :%d", *(u8 *)(LIGHT(idx) + 0xE4));
        }
        if (S32(0x18) != 4 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 100, 0, "diff_g :%d", *(u8 *)(LIGHT(idx) + 0xE5));
        }
        if (S32(0x18) != 5 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 110, 0, "diff_b :%d", *(u8 *)(LIGHT(idx) + 0xE6));
        }
        if (S32(0x18) != 6 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 120, 0, "ambient :%d", *(u8 *)(LIGHT(idx) + 0xE7));
        }
        if (S32(0x18) != 7 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 130, 0, "ambient_r :%d", *(u8 *)((u8 *)&D_8330A2B0 + 0x10C));
        }
        if (S32(0x18) != 8 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 140, 0, "ambient_g :%d", *(u8 *)((u8 *)&D_8330A2B0 + 0x10D));
        }
        if (S32(0x18) != 9 || D_833091F4 >= 10) {
            func_800495F8(0x8C, 150, 0, "ambient_b  :%d", *(u8 *)((u8 *)&D_8330A2B0 + 0x10E));
        }
    }
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}

#undef LIGHT
#undef S32
#undef F32

extern f32 D_8330AC5C;
extern f32 D_8330AC60;
extern f32 D_8330ACCC;
extern f32 D_8330ACD0;
extern f32 D_8330ACD4;
extern f32 D_8330ACD8;
extern f32 D_8330ACDC;
// Debug overlay: prints the frame counter, then a camera position, look-at point and fovy.
// While D_8330A2B0.unk_10 is below 3 the six vector values come from D_8330AC5C..D_8330ACD8,
// otherwise from D_8330A2B0's cameraPos and cameraAt; fovy is always D_8330ACDC.
//@src/47580.c
void func_83302AC8(void) {
    func_800498C4();
    func_800496A4(1, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    func_800495F8(20, 20, 0, "frame:%d", D_8330A2B0.frame);
    if (D_8330A2B0.unk_10 < 3) {
        func_800495F8(20, 30, 0, "cam posx:%0.1f", D_8330AC5C);
        func_800495F8(20, 40, 0, "cam posy:%0.1f", D_8330AC60);
        func_800495F8(20, 50, 0, "cam posz:%0.1f", D_8330ACCC);
        func_800495F8(20, 60, 0, "cam latx:%0.1f", D_8330ACD0);
        func_800495F8(20, 70, 0, "cam laty:%0.1f", D_8330ACD4);
        func_800495F8(20, 80, 0, "cam latz:%0.1f", D_8330ACD8);
        func_800495F8(20, 90, 0, "cam fovy:%0.1f", D_8330ACDC);
    } else {
        func_800495F8(20, 30, 0, "cam posx:%0.1f", D_8330A2B0.cameraPos[0]);
        func_800495F8(20, 40, 0, "cam posy:%0.1f", D_8330A2B0.cameraPos[1]);
        func_800495F8(20, 50, 0, "cam posz:%0.1f", D_8330A2B0.cameraPos[2]);
        func_800495F8(20, 60, 0, "cam latx:%0.1f", D_8330A2B0.cameraAt[0]);
        func_800495F8(20, 70, 0, "cam laty:%0.1f", D_8330A2B0.cameraAt[1]);
        func_800495F8(20, 80, 0, "cam latz:%0.1f", D_8330A2B0.cameraAt[2]);
        func_800495F8(20, 90, 0, "cam fovy:%0.1f", D_8330ACDC);
    }
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}

/* mkdraft:func_83302D8C begin */
extern s32 D_833090AC;
extern s32 D_8330ABD8;

void func_8004989C(s32);
s32 func_8004C54C(s32, s32);
void *func_8004C874(s32, s32);
void *func_8004C8A0(void *, s32, s32, s32);
void func_8330084C(unk_8330084C *arg0);
void func_83302088(void *);
void func_83302180(void *);
extern s32 D_83308E38[];
extern s32 D_8330A2B8;
extern s32 D_8330AC08;
extern const char D_833094D4[];
extern const char D_833094D8[];

const char D_833094D4[] = "%s";
const char D_833094D8[] = "(%d)";

void func_83302D8C(void) {
    Fragment57DialogContext *dialog = &sDialog;
    s32 line_y;
    char text[100];
    s32 text_id;

    if (dialog->state != 0) {
        if (dialog->state == 1) {
            func_83302088(dialog);
            if (dialog->limit < dialog->frame) {
                dialog->state = -1;
                dialog->phase = -1;
            }
        }
        if (dialog->state == -1) {
            func_83302180(dialog);
        }
        if (dialog->state != 0) {
            func_8330084C((s32 *)dialog);
        }
        func_800498C4();
        func_800496A4(2, 1);
        Font_EnableTwoCycleTexturing();
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        func_800497E4(0xFF, 0xFF, 0xFF, 0xC8);
        line_y = dialog->draw_y + 0xE;
        func_8004989C(0xE);
        if (dialog->phase == 1) {
            if (dialog->counting == 1) {
                dialog->frame = dialog->frame + 1;
            }
            text_id = D_83308E38[D_8330A2B8];
            switch (text_id) {
            case 11:
            case 14:
                func_8004C54C(0x19, (s32)func_8004C874(0, D_8330ABD8 - 1));
                func_8004C54C(0x41, (s32)func_8004C874(6, D_8330ABDC - 1));
                func_800495F8(dialog->draw_x + 0xE, line_y, 0, func_8004C8A0(text, sizeof(text), 0x49, D_83308E38[D_8330A2B8]));
                break;
            case 16:
                func_8004C54C(0x19, (s32)func_8004C874(0, D_8330ABD8 - 1));
                func_8004C54C(0x42, (s32)func_8004C874(6, D_8330ABE0 - 1));
                func_800495F8(dialog->draw_x + 0xE, line_y, 0, func_8004C8A0(text, sizeof(text), 0x49, D_83308E38[D_8330A2B8]));
                break;
            default:
                func_800495F8(dialog->draw_x + 0xE, line_y, 0, D_833094D4, func_8004C874(0x49, text_id));
                break;
            }
            if (D_833090AC == 1) {
                func_800495F8(dialog->x, line_y - 0x14, 1, D_833094D8, D_8330ABD8);
            }
        }
        Font_DisableTwoCycleTexturing();
        func_800499EC();
    }
}
/* mkdraft:func_83302D8C end */

extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 Deck_WriteEntries(u8 *, s32, u8 *);
extern s32 func_80062304(u8 *);
extern u8 func_80062E10(u8);



void func_8330309C(s32 arg0) {
    u8 buffer[30][0x58];
    u8 *handle;
    s32 deckType;
    s32 slot;
    s32 count;
    s32 select;

    select = D_83308E34[0x5D];
    count = 0;
    if (select == 0) {
        deckType = 0x20;
        slot = 0;
    } else {
        deckType = 0x21;
        slot = select - 1;
    }

    handle = func_8006218C(deckType, arg0, slot, 0);
    if (handle != 0) {
        while (Deck_ReadEntries(buffer[count], 1, handle) != 0) {
            count++;
        }
        func_80062304(handle);
    }
    buffer[D_83308E34[0x5E]][*(s32 *)((u8 *)&D_8330A2B0 + 0x50) + 2] = D_8330ABE0;
    buffer[D_83308E34[0x5E]][*(s32 *)((u8 *)&D_8330A2B0 + 0x50) + 0x18] = func_80062E10(D_8330ABE0);

    handle = func_8006218C(deckType, arg0, slot, 1);
    if (handle != 0) {
        Deck_WriteEntries(buffer[0], count, handle);
        func_80062304(handle);
    }
}

/* mkdraft:func_83303220 begin */
extern void *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094EC0[];
extern u8 D_80094F50[];
s32 D_833091F8 = 0;
s32 D_833091FC = 15;
extern s32 D_83309200;
extern u8 *func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_80045DB4(s32, s32, s32, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);

// Emits the translucent full-screen pass for the "whited out" fade: two sprite
// images (0x137, tiles 1 and 0), a fixed pstate, then two gDPSetTileSize commands
// whose width/height follow D_833091F8. The second image's height argument re-reads
// D_833091FC through a second spelling so the load is not CSE'd across the two
// func_80045DB4 calls (retail reloads it for call 1's last two variadic slots).
// D_800D0510 holds the display-list cursor as `void *` in this fragment, so every
// gSP/gDP command advances it through the (Gfx **) cast.
//
// karodo: `if (D_83309200) {}` is a dead empty conditional. The compare never reaches
// the object (the linked body is 209 instructions either way); it only refills uopt's
// expression-temp free list before the `pos` block, which moves `pos` from v0 to t4
// and `-pos` from a2 to a1. Without that line the tail's 8 instructions still differ
// in register names only and the file scores 55.


void func_83303220(void) {
    s32 sp6C;
    s32 sp68;

    sp6C = (s32) func_8004CA60(func_8004C990(0x137, 1));
    sp68 = (s32) func_8004CA60(func_8004C990(0x137, 0));

    gSPDisplayList((*(Gfx **) &D_800D0510)++, D_80094E38);
    gSPDisplayList((*(Gfx **) &D_800D0510)++, D_80094EC0);
    gDPPipeSync((*(Gfx **) &D_800D0510)++);
    gDPSetTextureFilter((*(Gfx **) &D_800D0510)++, G_TF_BILERP);
    gDPSetRenderMode((*(Gfx **) &D_800D0510)++, G_RM_PASS, G_RM_AA_XLU_SURF2);
    gDPSetEnvColor((*(Gfx **) &D_800D0510)++, 0x64, 0xFF, 0x64, 0x96);
    gDPSetPrimColor((*(Gfx **) &D_800D0510)++, 0, 0xC8, 0xFF, 0x37, 0x96, 0xFF);
    gDPSetCombine((*(Gfx **) &D_800D0510)++, 0x772C60, 0x3514E37F);

    D_833091F8++;

    func_80045DB4(sp6C, 0, 0, 4, 0, 0x40, 0x40, 1, 0, 0, 0, 6, 6, D_833091FC, *(u32 *) &D_833091FC);
    func_80045DB4(sp68, 0x100, 1, 4, 0, 0x40, 0x40, 1, 0, 0, 0, 6, 6, D_83309200, D_83309200);

    {
        s32 pos = D_833091F8;
        if (D_83309200) {} // karodo: the compare never reaches the object; the D_83309200 reference only shifts uopt's register walk
        gDPTileSync((*(Gfx **) &D_800D0510)++);
        gDPSetTileSize((*(Gfx **) &D_800D0510)++, 0, pos * 2, -pos, 0xFD, 0xF9);
        gDPSetTileSize((*(Gfx **) &D_800D0510)++, 1, pos * -2, -pos, 0xFB, 0xF9);
    }
    gSPTextureRectangle((*(Gfx **) &D_800D0510)++, 0, 0, 0x500, 0x3C0, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
    gSPDisplayList((*(Gfx **) &D_800D0510)++, D_80094F50);
}
/* mkdraft:func_83303220 end */

extern void *D_800D0510;
extern s32 D_833090AC;
extern u8 D_8330A288[];
extern s32 D_8330A2C4;
extern s32 D_8330A2EC;
extern s32 D_8330A4C8;
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(void *, u16);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(s32);
extern void func_83302290(void);
extern void func_83302AC8(void);
extern void func_83302D8C(void);
extern void func_83303220(void);
extern void func_81A0022C(void *);
extern void func_80008648(void);
void func_83303564(void) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 1);
    if (D_8330A2EC == 1) {
        func_83303220();
    }
    if (D_8330A2C4 == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(D_8330A4C8);
    func_83302D8C();
    if ((D_80087200->buttonsHeld & 0x2000) && (D_833090AC == 1)) {
        func_83302AC8();
    }
    if (D_8330A2C4 == 1) {
        func_83302290();
    }
    func_81A0022C(D_8330A288);
    func_80008648();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83303640.s")

extern f32 D_8330A344[3];
extern f32 D_8330A368[3];
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);

// Zeroes the vectors D_8330A344 and D_8330A368, resets seven floats of D_8330A2B0, then applies the
// per-setting overrides selected by arg0 (1-278). Settings without an entry (4, 69, 254, 258 and any
// value outside 1-278) zero D_8330A344 a second time.
void func_83303AB0(s32 arg0) {
    Vec3f_SetComponentsDuplicate(D_8330A344, 0.0f, 0.0f, 0.0f);
    Vec3f_SetComponentsDuplicate(D_8330A368, 0.0f, 0.0f, 0.0f);
    D_8330A2B0.unk_60 = 0.1f;
    D_8330A2B0.unk_64 = 0.15f;
    D_8330A2B0.unk_68 = 400.0f;
    D_8330A2B0.unk_6C = 200.0f;
    D_8330A2B0.unk_70 = 0.0f;
    D_8330A2B0.unk_74 = -120.0f;
    D_8330A2B0.unk_78 = 0.0f;
    switch (arg0) {
        case 1:
        case 2:
        case 3:
            D_8330A2B0.unk_5C = -40.0f;
            break;
        case 5:
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 6:
            D_8330A2B0.unk_74 = -190.0f;
            D_8330A2B0.unk_C0 = 50.0f;
            break;
        case 7:
            D_8330A2B0.unk_98 = 100.0f;
            break;
        case 8:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_5C = 40.0f;
            break;
        case 9:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_5C = 40.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 10:
            D_8330A2B0.unk_5C = -40.0f;
            break;
        case 11:
            D_8330A2B0.unk_5C = 140.0f;
            D_8330A2B0.unk_98 = 220.0f;
            break;
        case 12:
            D_8330A2B0.unk_74 = 0.0f;
            D_8330A2B0.unk_98 = 80.0f;
            break;
        case 13:
            D_8330A2B0.unk_5C = 80.0f;
            D_8330A2B0.unk_98 = 180.0f;
            break;
        case 14:
            D_8330A2B0.unk_5C = -100.0f;
            break;
        case 15:
            D_8330A2B0.unk_74 = 100.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 16:
            D_8330A2B0.unk_98 = 60.0f;
            D_8330A2B0.unk_6C = 400.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -650.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            break;
        case 17:
            D_8330A2B0.unk_6C = 400.0f;
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -800.0f;
            break;
        case 18:
            D_8330A2B0.unk_6C = 500.0f;
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -900.0f;
            break;
        case 19:
            D_8330A2B0.unk_98 = -50.0f;
            D_8330A2B0.unk_5C = -100.0f;
            break;
        case 20:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_5C = -40.0f;
            break;
        case 21:
            D_8330A2B0.unk_74 = 0.0f;
            D_8330A2B0.unk_98 = 70.0f;
            D_8330A2B0.unk_5C = -40.0f;
            break;
        case 22:
            D_8330A2B0.unk_74 = -50.0f;
            break;
        case 23:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = 100.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_98 = -100.0f;
            break;
        case 24:
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 30.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 25:
            D_8330A2B0.unk_98 = 30.0f;
            D_8330A2B0.unk_74 = -200.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 26:
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 27:
            D_8330A2B0.unk_98 = 30.0f;
            D_8330A2B0.unk_5C = -60.0f;
            break;
        case 28:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 29:
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 30:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 31:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 32:
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 33:
            D_8330A2B0.unk_98 = 40.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 34:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -150.0f;
            D_8330A2B0.unk_C0 = 50.0f;
            break;
        case 35:
            D_8330A2B0.unk_98 = 30.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 36:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 37:
            D_8330A2B0.unk_98 = 70.0f;
            break;
        case 38:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 150.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 39:
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 40:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_5C = 40.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 41:
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_74 = -800.0f;
            break;
        case 42:
            D_8330A2B0.unk_5C = -120.0f;
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 43:
            D_8330A2B0.unk_98 = 100.0f;
            break;
        case 44:
            D_8330A2B0.unk_5C = -40.0f;
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 45:
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_5C = -100.0f;
            break;
        case 46:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 47:
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 48:
            D_8330A2B0.unk_5C = -120.0f;
            D_8330A2B0.unk_98 = -30.0f;
            break;
        case 49:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_74 = -30.0f;
            break;
        case 50:
        case 51:
            D_8330A2B0.unk_74 = -80.0f;
            D_8330A2B0.unk_5C = 50.0f;
            D_8330A2B0.unk_98 = 120.0f;
            break;
        case 52:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 120.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -210.0f;
            break;
        case 53:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -50.0f;
            break;
        case 54:
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 55:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 110.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 56:
            D_8330A2B0.unk_5C = -70.0f;
            break;
        case 57:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 58:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_98 = 60.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 59:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = 170.0f;
            D_8330A2B0.unk_98 = 280.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 61:
            D_8330A2B0.unk_98 = 50.0f;
            // fallthrough
        case 60:
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 62:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 60.0f;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 63:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = 30.0f;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 64:
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 65:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 66:
            D_8330A2B0.unk_98 = 30.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 67:
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 68:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 70:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -120.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -300.0f;
            break;
        case 71:
            D_8330A2B0.unk_74 = 0.0f;
            D_8330A2B0.unk_5C = -150.0f;
            D_8330A2B0.unk_C0 = 600.0f;
            break;
        case 72:
        case 73:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_74 = 100.0f;
            D_8330A2B0.unk_98 = -60.0f;
            D_8330A2B0.unk_5C = -150.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 74:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -300.0f;
            break;
        case 75:
            D_8330A2B0.unk_98 = -30.0f;
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_C0 = -50.0f;
            break;
        case 76:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_98 = -30.0f;
            D_8330A2B0.unk_5C = -130.0f;
            D_8330A2B0.unk_C0 = -50.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 77:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 78:
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 79:
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 80:
            D_8330A2B0.unk_98 = 40.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 81:
            D_8330A2B0.unk_5C = -60.0f;
            D_8330A2B0.unk_74 = -600.0f;
            break;
        case 82:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_74 = 150.0f;
            D_8330A2B0.unk_5C = -70.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 83:
            D_8330A2B0.unk_98 = 80.0f;
            break;
        case 84:
            D_8330A2B0.unk_5C = -70.0f;
            break;
        case 85:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 86:
            D_8330A2B0.unk_98 = 80.0f;
            break;
        case 87:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_74 = 100.0f;
            D_8330A2B0.unk_98 = 56.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 88:
        case 89:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_98 = -100.0f;
            D_8330A2B0.unk_5C = -150.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 90:
            D_8330A2B0.unk_98 = 150.0f;
            D_8330A2B0.unk_5C = 40.0f;
            break;
        case 91:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -320.0f;
            break;
        case 92:
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_74 = 120.0f;
            break;
        case 93:
            D_8330A2B0.unk_74 = 100.0f;
            D_8330A2B0.unk_5C = -100.0f;
            break;
        case 94:
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 95:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = 180.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -250.0f;
            break;
        case 96:
            D_8330A2B0.unk_5C = -70.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 97:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_C0 = 80.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 98:
            D_8330A2B0.unk_98 = 80.0f;
            break;
        case 99:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_5C = 50.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 100:
            D_8330A2B0.unk_5C = -90.0f;
            break;
        case 101:
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            break;
        case 102:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -210.0f;
            D_8330A2B0.unk_98 = -100.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = 20.0f;
            break;
        case 103:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 104:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -100.0f;
            break;
        case 105:
            D_8330A2B0.unk_5C = 30.0f;
            D_8330A2B0.unk_98 = 130.0f;
            break;
        case 106:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_98 = -50.0f;
            D_8330A2B0.unk_74 = -140.0f;
            break;
        case 107:
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -175.0f;
            break;
        case 108:
            D_8330A2B0.unk_98 = 100.0f;
            break;
        case 109:
            D_8330A2B0.unk_5C = -85.0f;
            D_8330A2B0.unk_74 = 90.0f;
            break;
        case 110:
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = 50.0f;
            break;
        case 111:
            D_8330A2B0.unk_5C = -140.0f;
            D_8330A2B0.unk_74 = -90.0f;
            break;
        case 112:
            D_8330A2B0.unk_5C = 60.0f;
            D_8330A2B0.unk_98 = 140.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 113:
            D_8330A2B0.unk_5C = -60.0f;
            D_8330A2B0.unk_98 = 30.0f;
            break;
        case 114:
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 115:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 116:
            D_8330A2B0.unk_74 = 80.0f;
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_5C = -30.0f;
            break;
        case 117:
            D_8330A2B0.unk_74 = 0.0f;
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 118:
            D_8330A2B0.unk_74 = 80.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 119:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = 140.0f;
            break;
        case 120:
            D_8330A2B0.unk_5C = -100.0f;
            break;
        case 121:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 122:
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 123:
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 124:
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = -140.0f;
            break;
        case 125:
            D_8330A2B0.unk_5C = 50.0f;
            D_8330A2B0.unk_98 = 120.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 126:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 127:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 60.0f;
            D_8330A2B0.unk_74 = -220.0f;
            break;
        case 128:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_98 = -80.0f;
            D_8330A2B0.unk_5C = -140.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 129:
            D_8330A2B0.unk_5C = -60.0f;
            break;
        case 130:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -300.0f;
            break;
        case 131:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_5C = 40.0f;
            D_8330A2B0.unk_74 = -240.0f;
            break;
        case 132:
            D_8330A2B0.unk_98 = 150.0f;
            D_8330A2B0.unk_5C = 100.0f;
            break;
        case 133:
            D_8330A2B0.unk_98 = 60.0f;
            break;
        case 134:
            D_8330A2B0.unk_74 = -80.0f;
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            break;
        case 135:
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_98 = 25.0f;
            break;
        case 136:
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 137:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -60.0f;
            D_8330A2B0.unk_98 = 40.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -500.0f;
            break;
        case 138:
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_74 = -80.0f;
            break;
        case 139:
            D_8330A2B0.unk_5C = -90.0f;
            break;
        case 140:
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_98 = -40.0f;
            break;
        case 141:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_98 = 40.0f;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 142:
            D_8330A2B0.unk_74 = 0.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 143:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 144:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_5C = -30.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 145:
            D_8330A2B0.unk_74 = 100.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 146:
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 147:
            D_8330A2B0.unk_5C = 40.0f;
            D_8330A2B0.unk_98 = 130.0f;
            break;
        case 148:
            D_8330A2B0.unk_5C = 100.0f;
            D_8330A2B0.unk_98 = 130.0f;
            break;
        case 149:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 150:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 40.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 151:
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = 50.0f;
            break;
        case 152:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 153:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 120.0f;
            D_8330A2B0.unk_74 = -165.0f;
            break;
        case 154:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = 40.0f;
            D_8330A2B0.unk_98 = 130.0f;
            D_8330A2B0.unk_74 = -155.0f;
            break;
        case 155:
            D_8330A2B0.unk_98 = 60.0f;
            break;
        case 156:
            D_8330A2B0.unk_98 = 200.0f;
            D_8330A2B0.unk_5C = 100.0f;
            break;
        case 157:
            D_8330A2B0.unk_C0 = 150.0f;
            D_8330A2B0.unk_5C = 120.0f;
            D_8330A2B0.unk_98 = 180.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 158:
            D_8330A2B0.unk_98 = 30.0f;
            D_8330A2B0.unk_5C = -30.0f;
            break;
        case 159:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 60.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 160:
            D_8330A2B0.unk_5C = -30.0f;
            D_8330A2B0.unk_98 = 30.0f;
            D_8330A2B0.unk_C0 = 250.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 161:
            D_8330A2B0.unk_5C = -30.0f;
            D_8330A2B0.unk_C0 = 250.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 162:
            D_8330A2B0.unk_98 = 120.0f;
            D_8330A2B0.unk_5C = 130.0f;
            break;
        case 163:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_98 = 70.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 164:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 130.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 165:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = -200.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 166:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_74 = -260.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 167:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 168:
            D_8330A2B0.unk_98 = 40.0f;
            break;
        case 169:
            D_8330A2B0.unk_74 = 100.0f;
            D_8330A2B0.unk_98 = 40.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 170:
            D_8330A2B0.unk_98 = 20.0f;
            D_8330A2B0.unk_74 = -600.0f;
            break;
        case 171:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -40.0f;
            D_8330A2B0.unk_74 = -700.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 172:
            D_8330A2B0.unk_5C = 40.0f;
            D_8330A2B0.unk_98 = 120.0f;
            break;
        case 173:
            D_8330A2B0.unk_98 = 60.0f;
            break;
        case 174:
        case 175:
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 176:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 177:
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_98 = -30.0f;
            break;
        case 178:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 60.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 179:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 180:
            D_8330A2B0.unk_98 = 120.0f;
            break;
        case 181:
            D_8330A2B0.unk_98 = 25.0f;
            D_8330A2B0.unk_5C = -40.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 182:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 183:
            D_8330A2B0.unk_5C = 50.0f;
            D_8330A2B0.unk_98 = 120.0f;
            break;
        case 184:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_98 = 200.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = 170.0f;
            D_8330A2B0.unk_74 = -200.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            break;
        case 185:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = 50.0f;
            D_8330A2B0.unk_98 = 120.0f;
            D_8330A2B0.unk_74 = -215.0f;
            break;
        case 186:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_5C = 60.0f;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 187:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 60.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 188:
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 189:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -60.0f;
            D_8330A2B0.unk_98 = 40.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 190:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_74 = -135.0f;
            break;
        case 191:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -70.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -450.0f;
            break;
        case 192:
            D_8330A2B0.unk_5C = 100.0f;
            D_8330A2B0.unk_98 = 170.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 193:
            D_8330A2B0.unk_C0 = 500.0f;
            D_8330A2B0.unk_6C = 1200.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -600.0f;
            break;
        case 194:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_5C = 50.0f;
            break;
        case 195:
            D_8330A2B0.unk_5C = 150.0f;
            D_8330A2B0.unk_C0 = 150.0f;
            D_8330A2B0.unk_98 = 230.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 196:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 120.0f;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 197:
            D_8330A2B0.unk_5C = -40.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 198:
            D_8330A2B0.unk_5C = 60.0f;
            D_8330A2B0.unk_98 = 140.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 199:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 200:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -65.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -300.0f;
            break;
        case 201:
            D_8330A2B0.unk_98 = 200.0f;
            D_8330A2B0.unk_5C = 130.0f;
            break;
        case 202:
            D_8330A2B0.unk_5C = 200.0f;
            D_8330A2B0.unk_98 = 300.0f;
            D_8330A2B0.unk_74 = -165.0f;
            break;
        case 203:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -80.0f;
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 204:
            D_8330A2B0.unk_5C = -90.0f;
            break;
        case 205:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_5C = -100.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -500.0f;
            break;
        case 206:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -50.0f;
            break;
        case 207:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -400.0f;
            break;
        case 208:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_5C = -110.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -300.0f;
            break;
        case 209:
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 210:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 130.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 211:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -110.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -600.0f;
            break;
        case 212:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_5C = -70.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 213:
            D_8330A2B0.unk_5C = 120.0f;
            D_8330A2B0.unk_98 = 180.0f;
            break;
        case 214:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_5C = 60.0f;
            D_8330A2B0.unk_98 = 170.0f;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 215:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_5C = 30.0f;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 216:
            D_8330A2B0.unk_5C = 60.0f;
            D_8330A2B0.unk_98 = 120.0f;
            break;
        case 217:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 218:
        case 219:
            D_8330A2B0.unk_5C = 120.0f;
            D_8330A2B0.unk_98 = 180.0f;
            break;
        case 220:
            D_8330A2B0.unk_5C = -60.0f;
            break;
        case 221:
            D_8330A2B0.unk_5C = 150.0f;
            D_8330A2B0.unk_98 = 250.0f;
            break;
        case 222:
            D_8330A2B0.unk_5C = 130.0f;
            D_8330A2B0.unk_98 = 180.0f;
            break;
        case 223:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -120.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -500.0f;
            break;
        case 224:
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 225:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 110.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 226:
            D_8330A2B0.unk_6C = 300.0f;
            D_8330A2B0.unk_5C = -60.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -400.0f;
            break;
        case 227:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_74 = -210.0f;
            break;
        case 228:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 229:
            D_8330A2B0.unk_5C = -120.0f;
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = -50.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 230:
            D_8330A2B0.unk_5C = 70.0f;
            D_8330A2B0.unk_C0 = 300.0f;
            D_8330A2B0.unk_98 = 130.0f;
            D_8330A2B0.unk_6C = 500.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -600.0f;
            break;
        case 231:
            D_8330A2B0.unk_5C = -30.0f;
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 232:
            D_8330A2B0.unk_5C = -70.0f;
            D_8330A2B0.unk_98 = 20.0f;
            break;
        case 233:
            D_8330A2B0.unk_98 = 150.0f;
            D_8330A2B0.unk_5C = 90.0f;
            D_8330A2B0.unk_6C = 500.0f;
            D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
            D_8330A2B0.unk_74 = -450.0f;
            break;
        case 234:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_74 = -260.0f;
            break;
        case 235:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_5C = 70.0f;
            D_8330A2B0.unk_98 = 130.0f;
            D_8330A2B0.unk_74 = -150.0f;
            break;
        case 236:
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 237:
            D_8330A2B0.unk_5C = -220.0f;
            D_8330A2B0.unk_98 = -160.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 238:
            D_8330A2B0.unk_98 = 100.0f;
            break;
        case 239:
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 240:
            D_8330A2B0.unk_5C = -40.0f;
            D_8330A2B0.unk_98 = 50.0f;
            break;
        case 241:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 242:
            D_8330A2B0.unk_98 = 50.0f;
            D_8330A2B0.unk_74 = -160.0f;
            break;
        case 243:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = -50.0f;
            D_8330A2B0.unk_5C = -140.0f;
            break;
        case 244:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = -180.0f;
            break;
        case 245:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_5C = -50.0f;
            break;
        case 246:
            D_8330A2B0.unk_98 = 80.0f;
            D_8330A2B0.unk_74 = -170.0f;
            break;
        case 247:
            D_8330A2B0.unk_5C = 250.0f;
            D_8330A2B0.unk_98 = 330.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 248:
            D_8330A2B0.unk_C0 = 200.0f;
            D_8330A2B0.unk_5C = -50.0f;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 249:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 70.0f;
            D_8330A2B0.unk_74 = -200.0f;
            break;
        case 250:
            D_8330A2B0.unk_C0 = 100.0f;
            D_8330A2B0.unk_98 = 120.0f;
            D_8330A2B0.unk_74 = -190.0f;
            break;
        case 251:
            D_8330A2B0.unk_98 = 100.0f;
            D_8330A2B0.unk_74 = -300.0f;
            break;
        case 252:
            D_8330A2B0.unk_5C = 60.0f;
            D_8330A2B0.unk_98 = 130.0f;
            break;
        case 253:
            D_8330A2B0.unk_5C = 200.0f;
            D_8330A2B0.unk_98 = 250.0f;
            break;
        case 255:
            D_8330A2B0.unk_5C = -100.0f;
            break;
        case 256:
            D_8330A2B0.unk_5C = -250.0f;
            D_8330A2B0.unk_98 = -200.0f;
            break;
        case 257:
            D_8330A2B0.unk_5C = -100.0f;
            break;
        case 259:
            D_8330A2B0.unk_5C = -110.0f;
            break;
        case 260:
            D_8330A2B0.unk_5C = -75.0f;
            break;
        case 261:
            D_8330A2B0.unk_98 = 100.0f;
            break;
        case 262:
            D_8330A2B0.unk_98 = 90.0f;
            break;
        case 263:
            D_8330A2B0.unk_98 = 120.0f;
            break;
        case 264:
            D_8330A2B0.unk_5C = 80.0f;
            D_8330A2B0.unk_98 = 170.0f;
            break;
        case 265:
            D_8330A2B0.unk_98 = -150.0f;
            D_8330A2B0.unk_5C = -200.0f;
            break;
        case 266:
        case 268:
        case 269:
        case 270:
            D_8330A2B0.unk_5C = -60.0f;
            break;
        case 267:
        case 275:
        case 276:
            D_8330A2B0.unk_5C = -80.0f;
            break;
        case 271:
        case 272:
        case 273:
        case 274:
        case 278:
            D_8330A2B0.unk_5C = -90.0f;
            break;
        case 277:
            D_8330A2B0.unk_98 = 150.0f;
            D_8330A2B0.unk_5C = 80.0f;
            break;
        default:
            Vec3f_SetComponentsDuplicate(D_8330A344, 0.0f, 0.0f, 0.0f);
            break;
    }
    Vec3f_SetComponentsDuplicate(D_8330A368, 0.0f, 0.0f, 0.0f);
}



/* mkdraft:func_83305C1C begin */


void func_83305C1C(s32 arg0) {
    switch (arg0) {
    case 0x1:
    case 0x3:
    case 0x5:
        D_8330A2B0.unk_98 = 50.0f;
        return;
    case 0x2:
        D_8330A2B0.unk_98 = 25.0f;
        return;
    case 0x4:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_64 = 0.02f;
        D_8330A2B0.unk_98 = 70.0f;
        return;
    case 0x6:
        D_8330A2B0.unk_98 = 70.0f;
        return;
    case 0x7:
        D_8330A2B0.unk_60 = 0.15f;
        D_8330A2B0.unk_64 = 0.15f;
        D_8330A2B0.unk_68 = 135.0f;
        D_8330A2B0.unk_6C = 45.0f;
        return;
    case 0x9:
        D_8330A2B0.unk_98 = 120.0f;
        return;
    case 0xA:
        D_8330A2B0.unk_98 = 40.0f;
        return;
    case 0xE:
        D_8330A2B0.unk_60 = 0.07f;
        D_8330A2B0.unk_64 = 0.1f;
        D_8330A2B0.unk_6C = 600.0f;
        D_8330A2B0.unk_68 = 500.0f;
        return;
    case 0xF:
        D_8330A2B0.unk_98 = 30.0f;
        return;
    case 0x10:
    case 0x11:
    case 0x12:
        D_8330A2B0.unk_6C = 50.0f;
        D_8330A2B0.unk_60 = 0.15f;
        D_8330A2B0.unk_64 = 0.15f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x14:
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_64 = 0.12f;
        D_8330A2B0.unk_68 = 300.0f;
        return;
    case 0x15:
    case 0x16:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_64 = 0.02f;
        D_8330A2B0.unk_6C = 400.0f;
        return;
    case 0x17:
        D_8330A2B0.unk_68 = 700.0f;
        D_8330A2B0.unk_74 = -200.0f;
        return;
    case 0x19:
        D_8330A2B0.unk_6C = 50.0f;
        D_8330A2B0.unk_60 = 0.4f;
        D_8330A2B0.unk_64 = 0.4f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x1A:
        D_8330A2B0.unk_60 = 0.22f;
        D_8330A2B0.unk_64 = 0.22f;
        D_8330A2B0.unk_68 = 125.0f;
        D_8330A2B0.unk_6C = 45.0f;
        return;
    case 0x1D:
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_64 = 0.05f;
        return;
    case 0x20:
        D_8330A2B0.unk_60 = 0.03f;
        D_8330A2B0.unk_6C = 300.0f;
        D_8330A2B0.unk_68 = 200.0f;
        return;
    case 0x22:
        D_8330A2B0.unk_60 = 0.15f;
        D_8330A2B0.unk_64 = 0.3f;
        D_8330A2B0.unk_6C = 50.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x27:
        D_8330A2B0.unk_60 = 0.06f;
        D_8330A2B0.unk_68 = 335.0f;
        D_8330A2B0.unk_6C = 305.0f;
        return;
    case 0x28:
        D_8330A2B0.unk_6C = 200.0f;
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_64 = 0.05f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x29:
        D_8330A2B0.unk_6C = 50.0f;
        D_8330A2B0.unk_60 = 0.2f;
        D_8330A2B0.unk_64 = 0.2f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x2A:
        D_8330A2B0.unk_6C = 400.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x2B:
        D_8330A2B0.unk_68 = 330.0f;
        D_8330A2B0.unk_6C = 370.0f;
        return;
    case 0x2C:
        D_8330A2B0.unk_68 = 70.0f;
        D_8330A2B0.unk_6C = 80.0f;
        D_8330A2B0.unk_60 = 0.35f;
        D_8330A2B0.unk_64 = 0.25f;
        return;
    case 0x2D:
        D_8330A2B0.unk_6C = 30.0f;
        D_8330A2B0.unk_60 = 0.2f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        D_8330A2B0.unk_64 = 0.25f;
        return;
    case 0x30:
        D_8330A2B0.unk_68 = 300.0f;
        D_8330A2B0.unk_6C = 500.0f;
        return;
    case 0x34:
        D_8330A2B0.unk_64 = 0.1f;
        D_8330A2B0.unk_68 = 170.0f;
        D_8330A2B0.unk_6C = 220.0f;
        return;
    case 0x38:
        D_8330A2B0.unk_60 = 0.2f;
        D_8330A2B0.unk_68 = 0.0f;
        D_8330A2B0.unk_6C = 0.0f;
        D_8330A2B0.unk_64 = 0.12f;
        return;
    case 0x39:
        D_8330A2B0.unk_68 = 300.0f;
        D_8330A2B0.unk_6C = 500.0f;
        D_8330A2B0.unk_60 = 0.12f;
        D_8330A2B0.unk_64 = 0.04f;
        return;
    case 0x3B:
        D_8330A2B0.unk_C0 = 100.0f;
        return;
    case 0x3C:
        D_8330A2B0.unk_64 = 0.2f;
        D_8330A2B0.unk_68 = 300.0f;
        D_8330A2B0.unk_6C = 300.0f;
        D_8330A2B0.unk_60 = 0.05f;
        return;
    case 0x3F:
        D_8330A2B0.unk_60 = 0.1f;
        D_8330A2B0.unk_64 = 0.2f;
        D_8330A2B0.unk_68 = 200.0f;
        D_8330A2B0.unk_6C = 400.0f;
        D_8330A2B0.unk_74 = -180.0f;
        return;
    case 0x40:
        D_8330A2B0.unk_64 = 0.1f;
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_68 = 100.0f;
        D_8330A2B0.unk_6C = 400.0f;
        return;
    case 0x41:
        D_8330A2B0.unk_C0 = 150.0f;
        D_8330A2B0.unk_74 = -250.0f;
        return;
    case 0x45:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_6C = 300.0f;
        D_8330A2B0.unk_98 = 50.0f;
        D_8330A2B0.unk_68 = 150.0f;
        return;
    case 0x46:
        D_8330A2B0.unk_68 = 600.0f;
        D_8330A2B0.unk_98 = -50.0f;
        D_8330A2B0.unk_74 = -350.0f;
        return;
    case 0x47:
        D_8330A2B0.unk_C0 = 300.0f;
        return;
    case 0x48:
        D_8330A2B0.unk_98 = -60.0f;
        return;
    case 0x4A:
        D_8330A2B0.unk_68 = 500.0f;
        return;
    case 0x4B:
        D_8330A2B0.unk_64 = 0.05f;
        D_8330A2B0.unk_60 = D_8330A2B0.unk_64;
        return;
    case 0x4D:
        D_8330A2B0.unk_74 = -170.0f;
        return;
    case 0x50:
        D_8330A2B0.unk_60 = 0.15f;
        D_8330A2B0.unk_68 = 200.0f;
        D_8330A2B0.unk_6C = 500.0f;
        return;
    case 0x57:
        D_8330A2B0.unk_68 = 500.0f;
        return;
    case 0x58:
    case 0x5D:
        D_8330A2B0.unk_68 = 600.0f;
        return;
    case 0x59:
    case 0x5A:
    case 0x5B:
        D_8330A2B0.unk_68 = 700.0f;
        return;
    case 0x5F:
        D_8330A2B0.unk_68 = 600.0f;
        D_8330A2B0.unk_74 = -200.0f;
        return;
    case 0x64:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_68 = 450.0f;
        D_8330A2B0.unk_6C = 400.0f;
        return;
    case 0x65:
        D_8330A2B0.unk_6C = 400.0f;
        return;
    case 0x66:
        D_8330A2B0.unk_68 = 180.0f;
        D_8330A2B0.unk_6C = 5.0f;
        D_8330A2B0.unk_C0 = 200.0f;
        D_8330A2B0.unk_74 = -200.0f;
        return;
    case 0x6A:
        D_8330A2B0.unk_68 = 400.0f;
        D_8330A2B0.unk_74 = -180.0f;
        return;
    case 0x70:
        D_8330A2B0.unk_64 = 0.05f;
        D_8330A2B0.unk_60 = D_8330A2B0.unk_64;
        D_8330A2B0.unk_68 = 90.0f;
        D_8330A2B0.unk_6C = 160.0f;
        return;
    case 0x71:
        D_8330A2B0.unk_68 = 10.0f;
        D_8330A2B0.unk_6C = 10.0f;
        D_8330A2B0.unk_74 = -180.0f;
        return;
    case 0x73:
        D_8330A2B0.unk_C0 = 100.0f;
        D_8330A2B0.unk_74 = -200.0f;
        return;
    case 0x79:
        D_8330A2B0.unk_60 = 0.13f;
        D_8330A2B0.unk_64 = 0.13f;
        D_8330A2B0.unk_68 = 410.0f;
        D_8330A2B0.unk_6C = 410.0f;
        return;
    case 0x7E:
        D_8330A2B0.unk_60 = 0.03f;
        D_8330A2B0.unk_64 = 0.03f;
        D_8330A2B0.unk_68 = 185.0f;
        return;
    case 0x81:
        D_8330A2B0.unk_64 = 0.1f;
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_68 = 500.0f;
        return;
    case 0x85:
        D_8330A2B0.unk_68 = 500.0f;
        D_8330A2B0.unk_6C = 700.0f;
        return;
    case 0x89:
        D_8330A2B0.unk_68 = 600.0f;
        return;
    case 0x8A:
        D_8330A2B0.unk_60 = 0.08f;
        D_8330A2B0.unk_64 = 0.15f;
        D_8330A2B0.unk_68 = 200.0f;
        return;
    case 0x8B:
        D_8330A2B0.unk_68 = 200.0f;
        return;
    case 0x8D:
        D_8330A2B0.unk_6C = 500.0f;
        return;
    case 0x8E:
        D_8330A2B0.unk_60 = 0.1f;
        D_8330A2B0.unk_64 = 0.1f;
        D_8330A2B0.unk_68 = 400.0f;
        return;
    case 0x91:
        D_8330A2B0.unk_60 = 0.1f;
        D_8330A2B0.unk_64 = 0.1f;
        D_8330A2B0.unk_68 = 300.0f;
        D_8330A2B0.unk_6C = 250.0f;
        return;
    case 0x93:
        D_8330A2B0.unk_6C = 600.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x98:
        D_8330A2B0.unk_74 = -150.0f;
        D_8330A2B0.unk_6C = 600.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0x9B:
        D_8330A2B0.unk_68 = 300.0f;
        D_8330A2B0.unk_6C = 540.0f;
        return;
    case 0xA1:
        D_8330A2B0.unk_60 = 0.03f;
        D_8330A2B0.unk_64 = 0.03f;
        D_8330A2B0.unk_68 = 500.0f;
        D_8330A2B0.unk_6C = 400.0f;
        return;
    case 0xA2:
        D_8330A2B0.unk_60 = 0.06f;
        D_8330A2B0.unk_64 = 0.08f;
        return;
    case 0xA5:
        D_8330A2B0.unk_6C = 500.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0xA6:
        D_8330A2B0.unk_64 = 0.2f;
        D_8330A2B0.unk_68 = 310.0f;
        D_8330A2B0.unk_6C = 550.0f;
        return;
    case 0xAA:
        D_8330A2B0.unk_74 = -450.0f;
        return;
    case 0xAB:
        D_8330A2B0.unk_6C = 500.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        D_8330A2B0.unk_74 = -500.0f;
        D_8330A2B0.unk_5C = -100.0f;
        return;
    case 0xAE:
        D_8330A2B0.unk_60 = 0.08f;
        D_8330A2B0.unk_64 = 0.08f;
        D_8330A2B0.unk_68 = 350.0f;
        return;
    case 0xB0:
        D_8330A2B0.unk_74 = -200.0f;
        return;
    case 0xB1:
        D_8330A2B0.unk_68 = 350.0f;
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_64 = 0.05f;
        return;
    case 0xB6:
        D_8330A2B0.unk_6C = 500.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        return;
    case 0xB7:
        D_8330A2B0.unk_6C = 800.0f;
        D_8330A2B0.unk_68 = D_8330A2B0.unk_6C;
        D_8330A2B0.unk_74 = -180.0f;
        return;
    case 0xB8:
        D_8330A2B0.unk_68 = 600.0f;
        D_8330A2B0.unk_6C = 600.0f;
        return;
    case 0xBB:
        D_8330A2B0.unk_60 = 0.13f;
        D_8330A2B0.unk_68 = 100.0f;
        D_8330A2B0.unk_6C = 50.0f;
        return;
    case 0xBC:
        D_8330A2B0.unk_68 = 350.0f;
        D_8330A2B0.unk_6C = 350.0f;
        return;
    case 0xBE:
        D_8330A2B0.unk_68 = 265.0f;
        D_8330A2B0.unk_60 = 0.1f;
        D_8330A2B0.unk_64 = 0.3f;
        return;
    case 0xBF:
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_64 = 0.05f;
        D_8330A2B0.unk_68 = 200.0f;
        return;
    case 0xC1:
        D_8330A2B0.unk_74 = -600.0f;
        D_8330A2B0.unk_C0 = 500.0f;
        return;
    case 0xC8:
        D_8330A2B0.unk_C0 = 200.0f;
        D_8330A2B0.unk_68 = 800.0f;
        return;
    case 0xCB:
        D_8330A2B0.unk_C0 = 200.0f;
        D_8330A2B0.unk_68 = 460.0f;
        D_8330A2B0.unk_6C = 400.0f;
        return;
    case 0xD0:
    case 0xDF:
        D_8330A2B0.unk_68 = 800.0f;
        return;
    case 0xD4:
        D_8330A2B0.unk_C0 = 300.0f;
        D_8330A2B0.unk_68 = 500.0f;
        return;
    case 0xD6:
        D_8330A2B0.unk_C0 = 150.0f;
        return;
    case 0xD7:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_68 = 270.0f;
        D_8330A2B0.unk_64 = 0.3f;
        return;
    case 0xE2:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_64 = 0.02f;
        return;
    case 0xED:
        D_8330A2B0.unk_60 = 0.03f;
        D_8330A2B0.unk_68 = 315.0f;
        D_8330A2B0.unk_6C = 385.0f;
        return;
    case 0xEF:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_64 = 0.2f;
        D_8330A2B0.unk_68 = 285.0f;
        D_8330A2B0.unk_6C = 415.0f;
        return;
    case 0xF1:
        D_8330A2B0.unk_60 = 0.02f;
        D_8330A2B0.unk_68 = 200.0f;
        return;
    case 0xF6:
    case 0xFB:
        D_8330A2B0.unk_68 = 200.0f;
        return;
    case 0xF5:
    case 0x100:
    case 0x103:
        D_8330A2B0.unk_68 = 500.0f;
        return;
    case 0x104:
        D_8330A2B0.unk_60 = 0.2f;
        D_8330A2B0.unk_68 = 200.0f;
        return;
    case 0xFA:
        D_8330A2B0.unk_60 = 0.03f;
        D_8330A2B0.unk_64 = 0.06f;
        D_8330A2B0.unk_6C = 350.0f;
        D_8330A2B0.unk_68 = 300.0f;
        return;
    case 0xF7:
        D_8330A2B0.unk_68 = 300.0f;
        D_8330A2B0.unk_60 = 0.05f;
        return;
    case 0xF9:
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_68 = 100.0f;
        return;
    case 0xFC:
        D_8330A2B0.unk_68 = 700.0f;
        return;
    case 0x10F:
    case 0x110:
        D_8330A2B0.unk_60 = 0.05f;
        D_8330A2B0.unk_64 = 0.05f;
        return;
    case 0x111:
        D_8330A2B0.unk_60 = 0.03f;
        D_8330A2B0.unk_64 = 0.03f;
        return;
    case 0x116:
        D_8330A2B0.unk_74 = -230.0f;
        /* fallthrough */
    default:
        return;
    }
}
/* mkdraft:func_83305C1C end */

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

s32 ModelAnim_IsFinished(M2C_UNK *);                /* extern */
M2C_UNK func_80024480(s32, M2C_UNK);                /* extern */
M2C_UNK func_8003F2C4(s32, M2C_UNK *, s32);         /* extern */
M2C_UNK func_8003F3BC(M2C_UNK *, s32);              /* extern */
M2C_UNK func_83300020(M2C_UNK);                     /* extern */
void func_833003B0(s32 arg0);                     /* extern */
M2C_UNK func_83303640(M2C_UNK);                     /* extern */
extern u8 *D_83308E34;
extern s32 D_8330A4CC;
extern M2C_UNK D_8330A4D0;
extern s32 D_8330ABD8;

void func_83306BF0(void) {
    func_83300020(1);
    func_83303640(1);
    if ((ModelAnim_IsFinished(&D_8330A4D0) == 1) && ((M2C_FIELD(&D_8330A2B0, s32 *, 0xC) >= 0x5B) || (M2C_FIELD(D_83308E34, s16 *, 2) == -1))) {
        if (M2C_FIELD(&D_8330A2B0, s32 *, 0x30) == 0) {
            if (M2C_FIELD(&D_8330A2B0, s32 *, 0x48) == 1) {
                M2C_FIELD(&D_8330A2B0, s32 *, 0) = 9;
                func_80024480(D_8330ABD8, 4);
                func_8003F2C4(D_8330A4CC, &D_8330A4D0, M2C_FIELD(&D_8330A2B0, s32 *, 0x34));
                func_8003F3BC(&D_8330A4D0, M2C_FIELD(&D_8330A2B0, s32 *, 0x38));
                M2C_FIELD(&D_8330A2B0, s32 *, 0x30) = 1;
            }
        } else {
            func_8003F2C4(D_8330A4CC, &D_8330A4D0, 0);
            func_8003F3BC(&D_8330A4D0, 0);
            M2C_FIELD(&D_8330A2B0, s32 *, 0) = 9;
        }
        if (M2C_FIELD(&D_8330A2B0, s32 *, 0) == 9) {
            func_833003B0(4);
            M2C_FIELD(&D_8330A2B0, s32 *, 0xC) = 0;
        }
    }
}
/* mkdraft:func_83306D0C begin */
// The retail bytes for this function end at 0x8330707C with the normal
// epilogue; 0x83307080 holds an unreferenced `jr ra; nop` stub that the
// symbol map lists without a name. It is reproduced as the empty
// func_83306D0C_padding below, the same way src/6E850.c carries
// func_8006EB14_padding after Model_CopyPositionBuffer.
typedef struct unk_D_8330907C {
    s32 words[12];
} unk_D_8330907C;

extern s32 D_83308E2C;
extern s32 D_83308E38[];
extern s32 D_8330907C[];
extern s32 D_8330921C;
extern s32 D_8330AA70[];
extern void StageContext_SetClearColor(u16 arg0);
extern s32 StageFade_StartFromTransparent(s32 duration);
extern s32 func_800225C4(s32);
extern void func_800226C0(s32);
extern void func_87F034CC(void *);

void func_83306D0C(void) {
    // FAKE: pins D_8330921C's address in $a1 for the hold-timer increment,
    // reset, and repeat-delay compare; referring to D_8330921C by name scores
    // 1035 because each use then reloads the address.
    s32 *holdTimer = &D_8330921C;
    s32 var_v1;
    s32 temp_v0;
    s32 temp_v0_2;

    if ((ModelAnim_IsFinished(&D_8330A4D0) == 1) && (M2C_FIELD(&D_8330A2B0, s32 *, 0x30) == 1)) {
        func_8003F2C4(D_8330A4CC, &D_8330A4D0, 0);
        func_8003F3BC(&D_8330A4D0, 0);
        M2C_FIELD(&D_8330A2B0, s32 *, 0x54) = 1;
        M2C_FIELD(&D_8330A2B0, s32 *, 0x30) = 0;
    }
    func_83300020(2);
    func_83303640(2);
    if (M2C_FIELD(&D_8330A2B0, s32 *, 0x14) == 0) {
        (*holdTimer) += 1;
    }
    temp_v0 = D_80087200->buttonsPressed;
    if ((temp_v0 & 0x2030) && (M2C_FIELD(&D_8330A2B0, s32 *, 0x30) == 0) && (D_833090AC == 1)) {
        if ((temp_v0 & 0x10) || ((D_83308E2C * 20) < (*holdTimer))) {
            D_8330ABD8 += 1;
        } else if ((temp_v0 & 0x20) && (D_8330ABD8 >= 2)) {
            D_8330ABD8 -= 1;
        }
        if (D_8330ABD8 >= 252) {
            D_8330ABD8 = 1;
        }
        (*holdTimer) = 0;
        func_87F034CC(&D_8330AC38);
        M2C_FIELD(&D_8330AA70, u8 *, 0x1D) = 0xFF;
        M2C_FIELD(&D_8330AA70, f32 *, 0x34) = 0.45f;
        M2C_FIELD(&D_8330AA70, f32 *, 0x38) = (f32) M2C_FIELD(&D_8330AA70, f32 *, 0x34);
        M2C_FIELD(&D_8330A2B0, s32 *, 0) = 7;
        M2C_FIELD(&D_8330AA70, f32 *, 0x30) = (f32) M2C_FIELD(&D_8330AA70, f32 *, 0x38);
        *(unk_D_8330907C *) &D_8330AC08 = *(unk_D_8330907C *) D_8330907C;
        func_800225C4(10);
        StageContext_SetClearColor(1);
        StageFade_StartFromTransparent(20);
    }
    var_v1 = D_83308E38[M2C_FIELD(&D_8330A2B0, s32 *, 8)];
    if (var_v1 == 17) {
        temp_v0_2 = D_80087200->buttonsPressed;
        if ((temp_v0_2 & 0x8000) && (M2C_FIELD(&D_8330A2B0, s32 *, 0x54) == 2)) {
            func_800226C0(2);
            func_833003B0(7);
            if (D_833090AC == 1) {
                M2C_FIELD(&D_8330A2B0, s32 *, 0) = 13;
                M2C_FIELD(&D_8330A2B0, s32 *, 4) = 14;
                M2C_FIELD(&D_8330A2B0, s32 *, 0x4C) = 1;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(30);
            } else {
                M2C_FIELD(&D_8330A2B0, s32 *, 0x58) = -1;
                M2C_FIELD(&D_8330A2B0, s32 *, 0x4C) = 1;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(30);
                M2C_FIELD(&D_8330A2B0, s32 *, 0) = 10;
            }
            var_v1 = D_83308E38[M2C_FIELD(&D_8330A2B0, s32 *, 8)];
        } else if ((temp_v0_2 & 0x4000) && (D_833090AC == 1)) {
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(5);
            M2C_FIELD(&D_8330A2B0, s32 *, 0) = 13;
            M2C_FIELD(&D_8330A2B0, s32 *, 4) = 1;
            func_800225C4(5);
            var_v1 = D_83308E38[M2C_FIELD(&D_8330A2B0, s32 *, 8)];
        }
    }
    if ((var_v1 == 16) && (D_80087200->buttonsPressed & 0x8000) && (M2C_FIELD(&D_8330A2B0, s32 *, 0x54) == 2)) {
        func_833003B0(6);
        func_800226C0(2);
    }
}
/* mkdraft:func_83306D0C end */

/* mkdraft:func_83306D0C_padding begin */
// Bytes at 0x83307080: the retail jr ra/nop stub between this function and
// func_83307088; the symbol map has no name for it. Kept adjacent so the
// linker places it at the retail address.
void func_83306D0C_padding(void) {}
/* mkdraft:func_83306D0C_padding end */

/* mkdraft:func_83307088 begin */
/* mkdraft:func_83307088 begin */
// Controller-driven value adjuster for the D_8330A2B0 state. The word at
// +0x10 selects the branch: below 4, the cursor at +0x18 (clamped to 0xA,
// floor 0) selects one of ten targets -- the position floats at +0xDC and
// +0xE0, the 0/1 switch at +0x1C, the +0xE4..+0xE7 bytes of the record
// indexed by +0x1C (stride 0x14), or the +0x10C..+0x10E bytes. From 4 up,
// the cursor at +0x2C (clamped to 0xD, floor 0) selects one of fourteen
// floats. The three floats at the end copy +0x70/+0x74/+0x78 into D_8330A4D0.
// In cases 3-6 of both branches the +0x1C record pointer is computed a second
// time after the byte store; retail reloads +0x1C and remultiplies by 0x14
// there (0x833071C4, 0x833073F0), so those recomputations are marked // FAKE:.
extern ControllerState *D_80087200;
struct unk_D_8330A2B0;
extern struct unk_D_8330A2B0 D_8330A2B0;
extern s32 D_8330A4D0;


void func_83307088(void)
{
  s32 temp_a1;
  s32 temp_a1_2;
  s32 var_a0;
  s32 var_a2;
  s32 var_v1;
  u8 *temp_v1;
  ControllerState *ctrl;
  if ((*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x10))) < 4)
  {
    ctrl = D_80087200;
    if (ctrl->buttonsPressed & 0x400)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18)) = (s32) ((*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18))) + 1);
    }
    if (ctrl->buttonsPressed & 0x800)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18)) = (s32) ((*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18))) - 1);
    }
    var_a0 = *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18));
    if (var_a0 >= 0xA)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18)) = 0xA;
    }
    if ((*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18))) < 0)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18)) = 0;
    }
    temp_a1 = ctrl->buttonsPressed & 0x100;
    if ((temp_a1 != 0) || (ctrl->buttonsHeld & 1))
    {
      // Step applied by the switch below: 1 when 0x100 was pressed this
      // frame, 5 when the branch is entered through held bit 0 instead.
      var_a2 = 1;
      if (temp_a1 == 0)
      {
        var_a2 = 5;
      }
      switch (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18)))
      {
        case 0:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xDC)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xDC))) + ((f32) var_a2));
          break;

        case 1:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xE0)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xE0))) + ((f32) var_a2));
          break;

        case 2:
          *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C)) = 1;
          break;

        case 3:
          // FAKE: the +0x1C record pointer is computed twice because retail
          // reloads +0x1C and remultiplies by 0x14 after the store
          // (0x833071C4); cases 4-6 here and cases 3-6 below repeat this.
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE4)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE4))) + var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE4)))) >= 0xFF)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE4)) = 0xFFU;
        }
          break;

        case 4:
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE5)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE5))) + var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE5)))) >= 0xFF)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE5)) = 0xFFU;
        }
          break;

        case 5:
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE6)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE6))) + var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE6)))) >= 0xFF)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE6)) = 0xFFU;
        }
          break;

        case 6:
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE7)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE7))) + var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE7)))) >= 0xFF)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE7)) = 0xFFU;
        }
          break;

        case 7:
          if (((u8) (*((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10C)) += var_a2)) >= 0xFF)
        {
          *((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10C)) = 0xFFU;
        }
          break;

        case 8:
          if (((u8) (*((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10D)) += var_a2)) >= 0xFF)
        {
          *((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10D)) = 0xFFU;
        }
          break;

        case 9:
          if (((u8) (*((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10E)) += var_a2)) >= 0xFF)
        {
          *((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10E)) = 0xFFU;
        }
          break;

      }

    }
    temp_a1_2 = ctrl->buttonsPressed & 0x200;
    if ((temp_a1_2 != 0) || (ctrl->buttonsHeld & 2))
    {
      var_a2 = 1;
      if (temp_a1_2 == 0)
      {
        var_a2 = 5;
      }
      switch (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x18)))
      {
        case 0:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xDC)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xDC))) - ((f32) var_a2));
          break;

        case 1:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xE0)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xE0))) - ((f32) var_a2));
          break;

        case 2:
          *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C)) = 0;
          break;

        case 3:
          // FAKE: second computation of the record pointer after the store,
          // as in case 3 above (0x833073F0).
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE4)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE4))) - var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE4)))) <= 0)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE4)) = 0U;
        }
          break;

        case 4:
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE5)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE5))) - var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE5)))) <= 0)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE5)) = 0U;
        }
          break;

        case 5:
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE6)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE6))) - var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE6)))) <= 0)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE6)) = 0U;
        }
          break;

        case 6:
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          *((u8 *) (((u8 *) temp_v1) + 0xE7)) = (u8) ((*((u8 *) (((u8 *) temp_v1) + 0xE7))) - var_a2);
          temp_v1 = (u8 *) (&D_8330A2B0);
          temp_v1 += (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x1C))) * 0x14;
          //!bug dead clamp: the +0xE7 byte is loaded zero-extended, so the
          // sign test can never be true (0x833074C4 is lbu followed by bgez).
          if (((s32) (*((u8 *) (((u8 *) temp_v1) + 0xE7)))) < 0)
        {
          *((u8 *) (((u8 *) temp_v1) + 0xE7)) = 0U;
        }
          break;

        case 7:
          if (((u8) (*((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10C)) -= var_a2)) <= 0)
        {
          *((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10C)) = 0U;
        }
          break;

        case 8:
          if (((u8) (*((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10D)) -= var_a2)) <= 0)
        {
          *((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10D)) = 0U;
        }
          break;

        case 9:
          if (((u8) (*((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10E)) -= var_a2)) <= 0)
        {
          *((u8 *) (((u8 *) (&D_8330A2B0)) + 0x10E)) = 0U;
        }
          break;

      }

    }
  }
  else
  {
    ctrl = D_80087200;
    if (ctrl->buttonsPressed & 0x400)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C)) = (s32) ((*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C))) + 1);
    }
    if (ctrl->buttonsPressed & 0x800)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C)) = (s32) ((*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C))) - 1);
    }
    var_v1 = *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C));
    if (var_v1 >= 0xD)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C)) = 0xD;
      var_v1 = *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C));
    }
    if (var_v1 < 0)
    {
      *((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C)) = 0;
    }
    if ((ctrl->buttonsHeld & 1) || (ctrl->buttonsPressed & 0x100))
    {
      switch (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C)))
      {
        case 0:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0x94)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x94))) + 1.0f);
          break;

        case 1:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x98))) += 1.0f;
          break;

        case 2:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0x9C)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x9C))) + 1.0f);
          break;

        case 3:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xB8)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xB8))) + 1.0f);
          break;

        case 4:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xBC)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xBC))) + 1.0f);
          break;

        case 5:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xC0))) += 1.0f;
          break;

        case 6:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x60))) = (f32) (((f64) (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x60)))) + 0.01);
          break;

        case 7:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x64))) = (f32) (((f64) (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x64)))) + 0.01);
          break;

        case 8:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x68))) += 5.0f;
          break;

        case 9:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x6C))) += 5.0f;
          break;

        case 10:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x70))) += 1.0f;
          break;

        case 11:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x74))) += 1.0f;
          break;

        case 12:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x78))) += 1.0f;
          break;

        case 13:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x5C))) += 1.0f;
          break;

      }

    }
    if ((ctrl->buttonsHeld & 2) || (ctrl->buttonsPressed & 0x200))
    {
      switch (*((s32 *) (((u8 *) (&D_8330A2B0)) + 0x2C)))
      {
        case 0:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0x94)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x94))) - 1.0f);
          break;

        case 1:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x98))) -= 1.0f;
          break;

        case 2:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0x9C)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x9C))) - 1.0f);
          break;

        case 3:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xB8)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xB8))) - 1.0f);
          break;

        case 4:
          *((f32 *) (((u8 *) (&D_8330A2B0)) + 0xBC)) = (f32) ((*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xBC))) - 1.0f);
          break;

        case 5:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0xC0))) -= 1.0f;
          break;

        case 6:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x60))) = (f32) (((f64) (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x60)))) - 0.01);
          break;

        case 7:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x64))) = (f32) (((f64) (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x64)))) - 0.01);
          break;

        case 8:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x68))) -= 5.0f;
          break;

        case 9:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x6C))) -= 5.0f;
          break;

        case 10:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x70))) -= 1.0f;
          break;

        case 11:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x74))) -= 1.0f;
          break;

        case 12:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x78))) -= 1.0f;
          break;

        case 13:
          (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x5C))) -= 1.0f;
          break;

      }

    }
  }
  *((f32 *) (((u8 *) (&D_8330A4D0)) + 0x24)) = (f32) (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x70)));
  *((f32 *) (((u8 *) (&D_8330A4D0)) + 0x28)) = (f32) (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x74)));
  *((f32 *) (((u8 *) (&D_8330A4D0)) + 0x2C)) = (f32) (*((f32 *) (((u8 *) (&D_8330A2B0)) + 0x78)));
}
/* mkdraft:func_83307088 end */

extern void Audio_SetPreset(s32);
extern s32 D_8330A2C0;
extern s32 D_8330A680;
extern s32 D_8330A7E8;
extern s32 D_8330A950;

// Chooses an audio preset from the high halfword of one of the selection
// words: D_8330A2C0 picks D_8330A680 (1), D_8330A7E8 (2) or D_8330A950 (3);
// func_83307C7C stores the same halfwords as the list cursor at offset 0xC.
// Selection 1: values 8, 18, 28, 38, 48, 58 and 68 play preset 6; 49 plays 2;
// 99 plays 3 then 4; 149 plays 5. Selection 2: 0, 49, 159 and 168 play
// presets 7, 9, 10 and 8. Selection 3: 105 plays 11. Every other value plays
// nothing.
void func_833078C4(void) {
    s32 selection;
    s32 selection2;

    switch (D_8330A2C0) {                           /* irregular */
    case 1:
        selection = (s32)D_8330A680 >> 0x10;
        switch (selection) {                         /* irregular */
        case 8:
            Audio_SetPreset(6);
            return;
        case 18:
            Audio_SetPreset(6);
            return;
        case 28:
            Audio_SetPreset(6);
            return;
        case 38:
            Audio_SetPreset(6);
            return;
        case 48:
            Audio_SetPreset(6);
            return;
        case 58:
            Audio_SetPreset(6);
            return;
        case 68:
            Audio_SetPreset(6);
            return;
        case 49:
            Audio_SetPreset(2);
            return;
        case 99:
            Audio_SetPreset(3);
            Audio_SetPreset(4);
            return;
        case 149:
            Audio_SetPreset(5);
            return;
        }
        break;
    case 2:
        selection2 = (s32)D_8330A7E8 >> 0x10;
        switch (selection2) {                         /* irregular */
        case 0:
            Audio_SetPreset(7);
            return;
        case 49:
            Audio_SetPreset(9);
            return;
        case 159:
            Audio_SetPreset(10);
            return;
        case 168:
            Audio_SetPreset(8);
            return;
        }
        break;
    case 3:
        if (((s32)D_8330A950 >> 0x10) == 105) {
            Audio_SetPreset(11);
        }
        break;
    }
}

// Steps the three byte values in rows 0-1 of the D_8330A2B0 overlay (and row 2
// on the first outer pass) by |start - end| / arg0 per counter tick. Each
// D_83308E54 row holds three start values then three end values; D_83308E84 is
// the third such row.
typedef struct {
    u8 unk_00[0x24];
    s32 counter;
    u8 unk_28[0xBC];
    u8 rows[3][0x14];
} Fragment57Fade;
extern s32 D_83308E54[2][6];
extern s32 D_83308E84[6];
void func_83307AAC(s32 arg0) {
    s32 i;
    s32 *src;
    s32 j;
    s32 diff;
    s32 val;

    if (((Fragment57Fade *)&D_8330A2B0)->counter <= arg0) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j++) {
                if (i == 0) {
                    src = &D_83308E84[j];
                    val = *src;
                    diff = val - src[3];
                    ((Fragment57Fade *)&D_8330A2B0)->rows[2][j] =
                        val - ((diff < 0 ? -diff : diff) / arg0) * ((Fragment57Fade *)&D_8330A2B0)->counter;
                }
                val = D_83308E54[i][j];
                diff = val - D_83308E54[i][j + 3];
                ((Fragment57Fade *)&D_8330A2B0)->rows[i][j] =
                    val - ((diff < 0 ? -diff : diff) / arg0) * ((Fragment57Fade *)&D_8330A2B0)->counter;
            }
        }
        ((Fragment57Fade *)&D_8330A2B0)->counter++;
    }
}

extern s32 D_83308E2C;
extern void func_80021ED8(s32);
s32 func_83307C2C(s32 arg0) {
    if (arg0 > 0) {
        arg0 += 1;
    }
    if ((D_83308E2C * 5 + 5) < arg0) {
        func_80021ED8(0x57);
        arg0 = 0;
    }
    return arg0;
}



extern u8 D_8330A638[];
extern u8 D_8330A7A0[];
extern u8 D_8330A908[];
extern s32 D_8330AC58;
extern s32 D_8330AC20;
extern s32 D_8330ABE8[];
extern s32 D_8330ABEC;
extern s32 D_8330ABF0;
extern u8 D_83308F68[];
extern s32 D_83308E84[];
extern s16 D_833090D4;
extern s16 D_833090D8;
extern s32 StageContext_GetFadeMode(void);
extern void func_8003F210(void *, s32);
extern void StageContext_SetClearColor(u16);
extern s32 StageFade_StartFromOpaque(s32);
extern s32 StageFade_StartFromTransparent(s32);
extern void func_83307AAC(s32);
extern void func_833003B0(s32);
extern void func_8330309C(s32);
extern void func_83306BF0(void);
extern void func_83306D0C(void);
extern s32 func_83307C2C(s32);
extern void func_833078C4(void);
extern s32 func_81A00074(void *, s32);
extern void func_83307088(void);
extern void func_833019CC(void);
typedef struct { s32 w[12]; } Func83307C7CBlob48;
typedef struct { s32 w[68]; } Func83307C7CBlob110;
#define S32(off) (*(s32 *)((u8 *)&D_8330A2B0 + (off)))
#define F32(off) (*(f32 *)((u8 *)&D_8330A2B0 + (off)))

// Per-frame step of the intro sequence: advances the state in D_8330A2B0 (+0x0), swaps the
// animated models per stage and returns the next state. The +0xC frame counter is read as
// D_8330A2B0.frame in case 9; the S32() form there makes IDO evaluate the compare in the wrong order.
s32 func_83307C7C(s32 arg0) {
    s32 i, j;

    S32(0) = arg0;
    switch (D_8330A2B0.unk_10) {
    case 1:
        D_8330A2B0.frame = D_8330A680 >> 16;
        break;
    case 2:
        D_8330A2B0.frame = D_8330A7E8 >> 16;
        break;
    case 3:
        D_8330A2B0.frame = D_8330A950 >> 16;
        break;
    case 4:
        if (S32(0x14) == 0) {
            if (D_8330A2B0.frame < D_83308E2C * 20) {
                D_8330A2B0.frame += 1;
            }
        }
        break;
    }
    if ((D_80087200->buttonsPressed & 0x1000) && D_833090AC == 1) {
        S32(0x14) = 1 - S32(0x14);
    }
    func_833078C4();
    switch (S32(0)) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            S32(0) = S32(4);
        }
        break;
    case 1:
        func_8003F1DC(&D_8330A4D0);
        func_8003F1DC(D_8330AA70);
        func_80021ED8(0x56);
        *(Func83307C7CBlob48 *)&D_8330AC08 = *(Func83307C7CBlob48 *)D_8330907C;
        *(Func83307C7CBlob110 *)&D_8330A2B0 = *(Func83307C7CBlob110 *)D_83308F68;
        D_833090D4 = 0x4000;
        D_833090D8 = 0;
        S32(0x3C) = 0;
        D_8330A2B0.unk_10 = 1;
        F32(0xC8) = 200.0f;
        F32(0xCC) = 1200.0f;
        F32(0xD0) = 0.0f;
        F32(0xD4) = 10.0f;
        F32(0xDC) = 100.0f;
        func_87F034CC(&D_8330AC38);
        func_8003F114(D_8330A638, 0, -1, D_8330ABE8[0]);
        func_8003F210(D_8330A638, 0);
        func_8003F3BC((s32 *)D_8330A638, 0);
        ModelAnim_SetFrame(D_8330A638, 0);
        ModelAnim_SetEventFrame(D_8330A638, 0);
        D_8330A2B0.frame = 0;
        S32(0) = 2;
        D_8330AC58 = 0;
        break;
    case 2:
        if (D_8330A2B0.frame >= 0x81) {
            S32(0) = 3;
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(0x14);
        }
        break;
    case 3:
        if (StageContext_GetFadeMode() == 1) {
            StageFade_StartFromOpaque(0xA);
            D_8330A2B0.unk_10 = 2;
            func_8003F1DC(D_8330A638);
            func_8003F114(D_8330A7A0, 0, -1, D_8330ABEC);
            func_8003F210(D_8330A7A0, 0);
            ModelAnim_SetFrame(D_8330A7A0, 0);
            D_8330A2B0.frame = 0;
            S32(0) = 4;
        }
        break;
    case 4:
        if (D_8330A2B0.frame == 1) {
            func_833003B0(0);
        }
        if ((D_8330A7E8 >> 16) >= 0x32) {
            func_83307AAC(0x15);
        }
        if (D_8330A2B0.frame >= 0xC7) {
            S32(0) = 5;
        }
        break;
    case 5:
        D_8330A2B0.unk_10 = 3;
        D_8330A2B0.frame = 0;
        F32(0xDC) = 5.0f;
        func_8003F1DC(D_8330A7A0);
        func_8003F114(D_8330A908, 0, -1, D_8330ABF0);
        func_8003F210(D_8330A908, 0);
        S32(0) = 6;
        break;
    case 6:
        if (D_8330A2B0.frame == 0x28) {
            func_833003B0(1);
        }
        if (D_8330A2B0.frame == 0x64) {
            func_833003B0(2);
        }
        if (D_8330A2B0.frame >= 0x6D) {
            func_800225C4(0x28);
            StageContext_SetClearColor(0xFFFF);
            S32(0) = 7;
            StageFade_StartFromTransparent(0x28);
        }
        break;
    case 7:
        if (StageContext_GetFadeMode() == 1) {
            D_8330A2B0.unk_10 = 4;
            D_8330A2B0.frame = 0;
            S32(0x3C) = 1;
            D_833090D4 = 0x4000;
            D_833090D8 = 0;
            F32(0xDC) = 100.0f;
            func_8003F1DC(D_8330A908);
            S32(0) = 8;
            S32(0x40) = 1;
            func_83303AB0(D_8330ABD8);
            func_83305C1C(D_8330ABD8);
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromOpaque(0x23);
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 3; j++) {
                    D_8330A2B0.unk_10C[j] = D_83308E84[j];
                    D_8330A2B0.unk_E4[i][j] = D_83308E54[i][j];
                }
            }
        }
        break;
    case 8:
        if (D_8330A2B0.frame == 5) {
            func_80021ED8(0x31);
            D_8330AC58 = 1;
            func_833003B0(3);
        }
        if (D_8330A2B0.frame == 0x50) {
            func_833003B0(4);
        }
        if (S32(0x40) == 1) {
            func_833019CC();
            S32(0x40) = 0;
        }
        func_83306BF0();
        break;
    case 9:
        if (D_8330A2B0.frame == D_83308E2C + 10) {
            func_833003B0(5);
        }
        func_83306D0C();
        break;
    case 13:
        if (S32(0x4C) > 0) {
            S32(0x4C) += 1;
        }
        if (S32(0x4C) >= 0x15 && func_80025D44() != 0) {
            func_80025CBC(2);
        }
        if (StageContext_GetFadeMode() == 1) {
            S32(0) = S32(4);
            if (S32(0) != 0xE && D_833090AC == 1) {
                StageFade_StartFromOpaque(0xA);
            }
        }
        break;
    case 10:
        if (S32(0x4C) > 0) {
            S32(0x4C) += 1;
        }
        if (S32(0x4C) >= 0x15 && func_80025D44() != 0) {
            func_80025CBC(2);
        }
        if (func_80025D44() == 0) {
            if (StageContext_GetFadeMode() == 1) {
                S32(0x58) = -1;
                S32(0x3C) = 0;
                D_8330AC20 = 0;
                func_8003F1DC(&D_8330A4D0);
                func_8003F1DC(D_8330AA70);
                func_87F034CC(&D_8330AC38);
                S32(0) = 0xB;
                S32(0x58) = 1;
                StageFade_StartFromOpaque(3);
            }
        }
        break;
    case 11:
        func_8330309C(((s8 *)D_83308E34)[0x5C] - 1);
        S32(0) = 0xC;
        break;
    case 12:
        if (S32(0x58) > 0) {
            S32(0x58) += 1;
        }
        if (S32(0x58) < 0) {
            S32(0x58) -= 1;
        }
        if (func_81A00074(D_8330A288, ((s8 *)D_83308E34)[0x5C] - 1) != 0) {
            if (S32(0x58) > 0) {
                S32(0) = 0xD;
                S32(4) = 0xE;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(5);
            } else {
                S32(0) = 0xE;
            }
        } else {
            if (S32(0x58) <= 0) {
                S32(0x58) = 1;
                StageFade_StartFromOpaque(5);
            }
            S32(0) = 0xC;
        }
        break;
    }
    if (S32(0x14) == 1) {
        func_83307088();
    }
    D_8330AC58 = func_83307C2C(D_8330AC58);
    return S32(0);
}
#undef S32
#undef F32


/* mkdraft:func_833084B0 begin */
extern void StageContext_SetClearColor(u16 arg0);
extern s32 StageFade_StartFromOpaque(s32 duration);
extern s32 func_800086A4(s32);
extern void func_80064D28(void);
extern s32 func_83307C7C();



s32 func_833084B0(void) {
    s32 value;
    s32 var_s0;

    var_s0 = 1;
    func_800086A4(2);
    StageContext_SetClearColor(1);
    StageFade_StartFromOpaque(0xA);
    do {
        // FAKE: the 64-bit round trip only steers register allocation (t6 instead of v0).
        value = (s64)*(s32 *)(D_8330A288 + 8);
        if (value == -1) {
            func_80064D28();
        }
        func_83303564();
        var_s0 = func_83307C7C(var_s0);
    } while (var_s0 != 0xE);
}
/* mkdraft:func_833084B0 end */

s32 Asset_LoadToSegment(u32, s32 *, s32 *, s32); /* extern */
s32 Gfx_FreeDisplayListBuffers();               /* extern */
s32 Gfx_InitDisplayListBuffers(s32, s32); /* extern */
s32 fragment3_main(s32 *);                  /* extern */
s32 func_80001FF0();                                /* extern */
s32 func_800082E0(s32, s32, s32, s32, s32, s32); /* extern */
s32 func_80008514(s32);                         /* extern */
s32 func_80008574();                            /* extern */
s32 func_800086A4(s32);                     /* extern */
s32 func_80047588(s32, s32);            /* extern */
s32 func_80047610();                            /* extern */
s32 func_8004C09C(s32);                     /* extern */
s32 func_8004C398();                            /* extern */
s32 func_8004C4B0(s32);                     /* extern */
s32 func_8004D690(s32);                         /* extern */
s32 func_80057908(s32);                         /* extern */
s32 func_80057944(s32);                         /* extern */
s32 func_8005A134(s32);                         /* extern */
s32 func_83301C60();                            /* extern */
s32 func_833084B0();                            /* extern */
extern s32 D_1000000;
extern s32 D_446E30;
extern s32 D_447D00;
extern f32 D_83308E30;
extern s32 D_8330A4C4;

s32 func_8330853C(s32 arg0, u8 *arg1) {
    s32 sp24;
    u8 value;

    if (func_80001FF0() == 0x3C) {
        D_83308E2C = 0x1E;
        D_83308E30 = 1.0f;
    } else {
        D_83308E2C = 0x19;
        D_83308E30 = 1.2f;
    }
    D_83308E34 = arg1;
    D_833090AC = 0;
    if (D_83308E34 == NULL) {
        value = 1;
        D_833090AC = value;
        *(s16 *)&D_8330AC68 = 0;
        *(s16 *)((u8 *)&D_8330AC68 + 2) = -1;
        *(u8 *)((u8 *)&D_8330AC68 + 4) = 1;
        D_83308E34 = &D_8330AC68;
    } else {
        func_80057908((*(s8 *)(D_83308E34 + 0x5C) - 1) & 0xFF);
    }
    main_pool_push_state(0x4D525357);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = func_800082E0(0, 1, 2, 1, 2, 1);
    func_8004C09C(0x127);
    D_8330A4C4 = func_8004D690(0x18);
    func_8004C4B0(0x49);
    func_8004C4B0(6);
    func_8004C4B0(0);
    func_8004C8C0(0x4E);
    func_8004C8C0(0x164);
    func_8004C8C0(0x137);
    func_80047588(0x13, 0);
    Asset_LoadToSegment((u32) ((s32) &D_1000000 & 0x0F000000) >> 0x18, &D_446E30, &D_447D00, 0);
    func_8005A134(*(s8 *)(D_83308E34 + 0x5C) - 1);
    func_83301C60();
    fragment3_main(&D_8330A288);
    func_80008514(sp24);
    func_833084B0();
    func_800086A4(2);
    func_80008574();
    if (D_833090AC == 0) {
        func_80057944((*(s8 *)(D_83308E34 + 0x5C) - 1) & 0xFF);
    }
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D525357);
    return 0;
}
#endif
