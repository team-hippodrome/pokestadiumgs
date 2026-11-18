#include "global.h"


#ifdef VERSION_US
// The fragment loader clears these two-halfword transition-control records.
//@src/2CA0.c
typedef struct F17TransitionState {
    s16 state;
    s16 unk_02;
} F17TransitionState;
static F17TransitionState sTransition105E8;
static F17TransitionState sTransition105EC;
/* Transition fade state at D_822105F0: mode, step, current x/y/z/w and the
 * x/y/z/w targets. Local storage (not extern) is what lets as1 share one
 * `lui $at` across the field stores, as the retail object does. */
static s16 sFade105F0[14];

typedef struct { s16 a; s16 b; } Pair16_b2;
extern s16 D_822105F0;
extern s16 D_822105F4;
extern s16 D_822106B2;
extern s16 D_822106B4;
extern s16 D_822106CC, D_822106CE;
extern s16 D_822106BA;
extern f32 D_822106C4;
extern f32 D_822106C8;
extern void func_800226C0(s32);
extern u16 D_822106B6;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern s16 D_82210640;
extern s16 D_82210642;
extern s16 D_82210644;
extern s16 D_82210646;
extern s32 func_8220D67C(void);
void func_822040A0(s16 *arg0) {
    s16 *v0 = &D_822105F0;
    v0[0] = 1;
    v0[1] = 0;
    v0[8] = arg0[4];
    v0[9] = arg0[5];
    v0[10] = arg0[6];
    v0[11] = arg0[7];
    v0[12] = arg0[6] - arg0[0x14];
    v0[13] = arg0[7] - arg0[0x15];
    *(Pair16_b2 *)&D_822105F4 = *(Pair16_b2 *)&v0[8];
    v0[4] = v0[10];
    v0[5] = v0[11];
    v0[6] = v0[4] - v0[12];
    v0[7] = v0[5] - v0[13];
}

void func_82204148(void) {
    s16 step;
    s16 y;
    s32 z;
    s16 *st = sFade105F0;

    switch (st[0]) {
        case 1:
        case 2:
            return;
        case 3:
            step = st[1] + 1;
            if (step < 4) {
                st[2] = (0x3B - st[8]) * step / 4 + st[8];
                st[3] = (0x150 - st[9]) * step / 4 + st[9];
                y = (0x1F4 - st[10]) * step / 4 + st[10];
                z = (0x70 - st[11]) * step / 4 + st[11];
                st[1] = step; z = (s16)z;
            } else {
                st[0] = 2;
                st[2] = 0x3B;
                st[3] = 0x150;
                y = 0x1F4;
                st[1] = 0;
                z = 0x70;
            }
            st[6] = y - st[12];
            st[7] = z - st[13];
            st[5] = z;
            st[4] = y;
            break;
        case 4:
            step = st[1] + 1;
            if (step < 4) {
                st[2] = (st[8] - 0x3B) * step / 4 + 0x3B;
                st[3] = (st[9] - 0x150) * step / 4 + 0x150;
                y = (st[10] - 0x1F4) * step / 4 + 0x1F4;
                z = (st[11] - 0x70) * step / 4 + 0x70;
                st[1] = step; z = (s16)z;
            } else {
                st[0] = 1;
                st[2] = st[8];
                st[3] = st[9];
                y = st[10];
                z = st[11];
                z = (s16)z;
                st[1] = 0;
            }
            st[6] = y - st[12];
            st[7] = z - st[13];
            st[5] = z;
            st[4] = y;
            break;
    }
}

extern s16 D_822105F0;

void func_82204430(s32 arg0) {
    D_822105F0 = arg0;
    ((s16 *)&D_822105F0)[1] = 0;
}

extern void func_800503A4(s32);
extern s32 D_8220DA18;
extern s32 D_8220DA1C;
void func_82204444(void) {
    func_800503A4(D_8220DA18);
    if (D_822105F0 == 2) {
        func_800503A4(D_8220DA1C);
    }
}

void func_82204488(s16 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_82204494.s")

/* mkdraft:func_82204744 begin */
extern s16 D_822105E8;
extern u8 D_822105DC[];
extern u8 D_822105EA[];

void func_82204744(void) {
    F17TransitionState *state = &sTransition105E8;

    if (*(s16 *)(D_822105DC + 12) == 0) {
        state->state = 1;
        state->unk_02 = 0;
        func_800226C0(62);
    }
}
/* mkdraft:func_82204744 end */

s32 func_82204780(s32 arg0, s32 arg1) {
    return (arg1 / arg0) & ~1;
}

s32 func_822047BC(s32 arg0, s32 arg1) {
    s32 temp_lo;
    s32 var_v1;

    temp_lo = arg0 / arg1;
    var_v1 = temp_lo;
    if ((arg0 % arg1) > 0) {
        var_v1 = temp_lo + 1;
    }
    return var_v1;
}

extern u8 D_8220D8D0[];
extern s16 D_8220EB98;
extern void *D_8220DA08;
extern Gfx *D_800D0510;
extern u8 D_8220D860[];
extern u8 D_8220DBA8[];
extern u8 D_8220DBAC[];
extern u8 D_8220DBB0[];
extern u8 D_8220DBB4[];

extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_80007328(Gfx **, s32, s32, u8 *);
extern void func_80045DB4(u8 *, s32, s32, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void GfxRect_DrawTextured(s32, s32, s32, s32, s32, s32, s32, s32, s32);

// The retail words pack the colour bytes as g, b, r with alpha in the low byte;
// PR/gbi.h's gDPSetPrimColor and gDPSetEnvColor write r, g, b, a, which makes IDO
// emit the byte loads in a different order.
//@src/fragments/19/fragment19_124E40.c
#define gDPSetPrimColor2(pkt, m, l, r, g, b, a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)); _g->words.w1 = (_SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(r, 24, 8) | _SHIFTL(a, 0, 8)); }
#define gDPSetEnvColor2(pkt, r, g, b, a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETENVCOLOR, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(r, 24, 8) | _SHIFTL(a, 0, 8)); }



void func_82204804(s32 arg0) {
    u8 *base;
    u8 *state;
    void *tex0;
    void *tex1;
    u8 *prim;
    u8 *env;
    u32 uls;
    u32 ult;
    u32 lrs;
    u32 lrt;

    // Row address in the 52-byte table. IDO places its frame adjustment between
    // the first two multiply steps only when the symbol is the first operand of
    // this sum; the retail prologue has it there.
    base = (u8 *)(D_8220D8D0 + arg0 * 52);
    tex0 = (void *)func_8004C990(2, *(u16 *)(base + 0xC));
    tex1 = (void *)func_8004C990(2, *(u16 *)(base + 0xE));
    prim = base + 0x2A;
    env = base + 0x2D;
    if (*(s16 *)(*(u8 **)((u8 *)D_8220DA08 + 0x20)) != 0) {
        switch (arg0) {
        case 0:
            prim = D_8220DBB0;
            env = D_8220DBB4;
            break;
        case 1:
            prim = D_8220DBA8;
            env = D_8220DBAC;
            break;
        }
    }
    state = (u8 *)(arg0 * 24 + (s32)&D_8220EB98);
    func_80007328(&D_800D0510, *(s32 *)(state + 4), arg0, prim);
    gSPDisplayList(D_800D0510++, D_8220D860);
    gDPSetPrimColor2(D_800D0510++, 0, *(s16 *)(base + 0x10), prim[0], prim[1], prim[2], 0xFF);
    gDPSetEnvColor2(D_800D0510++, env[0], env[1], env[2], 0xFF);
    func_80045DB4(func_8004CA60((u8 *)tex0), 0, 0, *(u8 *)((u8 *)tex0 + 4),
                  (s32)*(u8 *)((u8 *)tex0 + 5), (s32)*(u16 *)((u8 *)tex0 + 0),
                  (s32)*(u16 *)((u8 *)tex0 + 2), 1, 0, 0, 0, 5, 5,
                  (s32)*(s16 *)(base + 0x1C), (s32)*(s16 *)(base + 0x1E));
    uls = (u32)(*(f32 *)(state + 8) * 4.0f);
    ult = (u32)(*(f32 *)(state + 0xC) * 4.0f);
    lrs = (u32)((*(f32 *)(state + 8) + 31.0f) * 4.0f);
    lrt = (u32)((*(f32 *)(state + 0xC) + 31.0f) * 4.0f);
    gDPSetTileSize(D_800D0510++, 0, uls, ult, lrs, lrt);
    func_80045DB4(func_8004CA60((u8 *)tex1), 0x100, 1, *(u8 *)((u8 *)tex1 + 4),
                  (s32)*(u8 *)((u8 *)tex1 + 5), (s32)*(u16 *)((u8 *)tex1 + 0),
                  (s32)*(u16 *)((u8 *)tex1 + 2), 1, 0, 0, 0, 5, 5,
                  (s32)*(s16 *)(base + 0x20), (s32)*(s16 *)(base + 0x22));
    uls = (u32)(*(f32 *)(state + 0x10) * 4.0f);
    ult = (u32)(*(f32 *)(state + 0x14) * 4.0f);
    lrs = (u32)((*(f32 *)(state + 0x10) + 31.0f) * 4.0f);
    lrt = (u32)((*(f32 *)(state + 0x14) + 31.0f) * 4.0f);
    gDPSetTileSize(D_800D0510++, 1, uls, ult, lrs, lrt);
    GfxRect_DrawTextured(0, 0, 0x20, 0x20, 0, 0, 0x400, 0x400, 0);
    *(f32 *)(state + 8) += (f32)*(s16 *)(base + 0x14) * 0.25f;
    if (*(f32 *)(state + 8) >= 32.0f) {
        *(f32 *)(state + 8) -= 32.0f;
    }
    if (*(f32 *)(state + 8) < 0.0f) {
        *(f32 *)(state + 8) += 32.0f;
    }
    *(f32 *)(state + 0xC) += (f32)*(s16 *)(base + 0x16) * 0.25f;
    if (*(f32 *)(state + 0xC) >= 32.0f) {
        *(f32 *)(state + 0xC) -= 32.0f;
    }
    if (*(f32 *)(state + 0xC) < 0.0f) {
        *(f32 *)(state + 0xC) += 32.0f;
    }
    *(f32 *)(state + 0x10) += (f32)*(s16 *)(base + 0x18) * 0.25f;
    if (*(f32 *)(state + 0x10) >= 32.0f) {
        *(f32 *)(state + 0x10) -= 32.0f;
    }
    if (*(f32 *)(state + 0x10) < 0.0f) {
        *(f32 *)(state + 0x10) += 32.0f;
    }
    *(f32 *)(state + 0x14) += (f32)*(s16 *)(base + 0x1A) * 0.25f;
    if (*(f32 *)(state + 0x14) >= 32.0f) {
        *(f32 *)(state + 0x14) -= 32.0f;
    }
    if (*(f32 *)(state + 0x14) < 0.0f) {
        *(f32 *)(state + 0x14) += 32.0f;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_8220510C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_822056C0.s")

extern void *D_8220EB88;
s32 func_82205A14(s32 arg0, void *arg1) {
    switch (arg0) {
    case 0:
        D_8220EB88 = arg1;
        *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        break;
    case 1:
        break;
    default:
        break;
    }
    return 0;
}

extern s32 D_8220DA10;
s32 func_82205A48(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_8220DA10 != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}

extern void * D_8220DA08;
extern s32 D_8220DA10;
s32 func_82205A8C(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_8220DA10 != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
            if (*(s16 *)*(u8 **)((u8 *)D_8220DA08 + 0x20) == 0) {
                *(u16 *)((u8 *)arg1 + 0x32) = 0x44;
            } else {
                *(u16 *)((u8 *)arg1 + 0x32) = 0x45;
            }
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}

#endif
