#include "global.h"


#ifdef VERSION_US
extern void func_8003CD84(void);
struct TextureRenderHeader;
extern struct TextureRenderHeader *func_8004C990(s32, s32);
extern u16 *func_8004CA60(struct TextureRenderHeader *);
// Slot records indexed from 0 (index - 1 is compared with D_88523009); field offsets are
// Stadium 1 TradeSlotInfo + 6, from the accesses in func_88505264.
typedef struct {
    /* 0x000 */ u8 unk_000[4];
    /* 0x004 */ s16 unk_004;
    /* 0x006 */ u8 unk_006[6];
    /* 0x00C */ s16 unk_00C;
    /* 0x00E */ s16 unk_00E;
    /* 0x010 */ s16 unk_010;
    /* 0x012 */ s16 unk_012;
    /* 0x014 */ s16 unk_014;
    /* 0x016 */ s16 unk_016;
    /* 0x018 */ s16 unk_018;
    /* 0x01A */ s16 unk_01A;
    /* 0x01C */ f32 unk_01C;
    /* 0x020 */ f32 unk_020;
    /* 0x024 */ f32 unk_024;
    /* 0x028 */ u8 unk_028[0x194 - 0x28];
} unk_D_885229B0;
extern unk_D_885229B0 D_885229B0[];

// Draw callback listed in the fragment34 table entry at 0x8850D24C; mode 5 appends the trade
// slot's two texture segments and the caller's display list (arg1 + 0x14) to D_800D0510, calls
// func_8003CD84 and returns 0. D_8009491C is the scene node being rendered (src/340C0.c); its
// word at 0x14 selects the D_885229B0 slot and its byte at 0x1D is the alpha of the black env
// color. Segment 0xF loads entry slot + 0x190 from texture group 0x39 and segment 0xE loads the
// slot's unk_004 from group 0x104, both through func_8004C990. A slot whose unk_004 is -1 gets
// only the pipe sync and env color before func_8003CD84.
s32 func_885045B0(s32 mode, void *arg1) {
    extern Gfx *D_800D0510;
    extern void *D_8009491C;
    s32 index;

    if (mode == 5) {
        index = *(s32 *)((u8 *)D_8009491C + 0x14);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 0, 0, 0, ((u8 *)D_8009491C)[0x1D]);
        if (D_885229B0[index].unk_004 != -1) {
            gSPSegment(D_800D0510++, 0xF,
                       func_8004CA60(func_8004C990(0x39, *(u16 *)((u8 *)&D_885229B0[index] + 0x190))));
            gSPSegment(D_800D0510++, 0xE, func_8004CA60(func_8004C990(0x104, D_885229B0[index].unk_004)));
            gSPDisplayList(D_800D0510++, *(void **)((u8 *)arg1 + 0x14));
        }
        func_8003CD84();
    }
    return 0;
}

extern u8 D_8850D678[];
void func_88504704(void) {
    s32 i;
    u8 *ptr;
    u8 buffer[16];
    u16 value;
    char *name;

    for (i = 0, ptr = D_8850D678; i < 4; i++, ptr += 20) {
        func_8005D9E0(i, buffer);
        *(u8 *)(ptr + 0) = func_8005D8CC(i);
        *(u8 *)(ptr + 1) = func_8005D92C(i);
        *(u8 *)(ptr + 2) = func_8005DDD4(i);
        *(u8 *)(ptr + 3) = func_8005DDF8(i);
        *(u16 *)(ptr + 4) = *(u16 *)buffer;
        name = (char *)buffer + 2;
        HAL_Strcpy((char *)(ptr + 6), name);
    }
}

// Readiness code for a trade record from its state byte arg0[0]: state 0 gives 4, 3 or 0 from
// bytes 3 and 2; state 2 gives 1; states 3 and 5 give 2; others -1. Same body as Pokemon
// Stadium 1 Trade_GetBoxSlotSaveReadiness (src/fragments/trade_machine/trade_machine_28ED00.c
// there) plus the state-5 case.
s16 func_885047B4(u8 *arg0) {
    s16 ret;

    switch (arg0[0]) {
        case 0:
            if (arg0[3] == 0) {
                ret = 4;
            } else if (arg0[2] == 0) {
                ret = 3;
            } else {
                ret = 0;
            }
            break;

        case 2:
            ret = 1;
            break;

        case 3:
        case 5:
            ret = 2;
            break;

        default:
            ret = -1;
            break;
    }
    return ret;
}

extern void func_8003F018(void *arg0);
extern void func_8003F114(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_88523008[];
extern s8 D_8852300C[];
extern s32 D_88523004;

// Fills the four slot records in D_885229B0 (one per player-info entry at D_8850D678) with the
// entry index and its func_885047B4 readiness code. The entry selected by D_8852300C[0] takes
// slot 0; every other usable entry takes the next slot counted by the s8 counter D_88523008.
// The inner switch maps the player's game-port byte (info[1]) to the savedata slot index at
// +0x190 (Stadium 1 Trade_SetupBoxSlots, src/fragments/trade_machine/trade_machine_28ED00.c).
// Finally each of the D_88523008 active records gets its graph node at +0x28 attached and
// initialised through func_8003F018/func_8003F114 and stamped with its loop index.
//
// Preconditions outside this snippet (already above the GLOBAL_ASM pragma in
// fragment34_1C1BC0.c): the unk_D_885229B0 typedef + `extern unk_D_885229B0 D_885229B0[];`,
// `extern u8 D_8850D678[];` and the func_88504704 / func_885047B4 definitions.


void func_88504828(void) {
    unk_D_885229B0 *rec;
    u8 *info;
    u8 *node;
    s32 i;
    s32 readiness;

    rec = D_885229B0;
    for (i = 0; i < 4; i++, rec++) {
        *(s32 *)((u8 *)rec + 0x0) = 0;
        *(s16 *)((u8 *)rec + 0x4) = -1;
        *(s32 *)((u8 *)rec + 0x8) = 0;
    }

    func_88504704();
    // FAKE: byte store through the u8 array declaration instead of the s8 scalar the rest of the
    // body reads through. Same store, but it keeps the constant 1 in its own scratch register;
    // with `*(s8 *)D_88523008 = 1;` IDO shares that register with the case-3 constant and shifts
    // the whole loop-2/loop-3 coloring (diff score 595, vs 0 with this spelling).
    D_88523008[0] = 1;

    for (i = 0, info = D_8850D678; i < 4; i++, info += 0x14) {
        readiness = func_885047B4(info);
        if (readiness != -1) {
            if (i == *D_8852300C) {
                rec = D_885229B0;
            } else {
                // The subscript form (not an explicit `count * 0x194` byte offset) fixes the
                // temp-creation order: index temp t8 first, multiply chain after.
                rec = &D_885229B0[((s8 *)D_88523008)[0]++];
            }
            *(s16 *)((u8 *)rec + 0x4) = i;
            *(s32 *)((u8 *)rec + 0x8) = readiness;
            switch (readiness) {
                case 0:
                case 2:
                case 3:
                case 4:
                    switch (*(u8 *)(info + 1)) {
                        case 1:
                            *(s16 *)((u8 *)rec + 0x190) = 6;
                            break;
                        case 2:
                            *(s16 *)((u8 *)rec + 0x190) = 5;
                            break;
                        case 3:
                            *(s16 *)((u8 *)rec + 0x190) = 1;
                            break;
                        case 4:
                            *(s16 *)((u8 *)rec + 0x190) = 8;
                            break;
                        case 5:
                            *(s16 *)((u8 *)rec + 0x190) = 4;
                            break;
                        case 6:
                            *(s16 *)((u8 *)rec + 0x190) = 7;
                            break;
                        default:
                            *(s16 *)((u8 *)rec + 0x190) = 2;
                            break;
                    }
                    break;
                case 1:
                    *(s16 *)((u8 *)rec + 0x190) = 3;
                    break;
            }
        }
    }

    rec = D_885229B0;
    for (i = 0; i < *(s8 *)D_88523008; i++, rec++) {
        node = (u8 *)rec + 0x28;
        func_8003F018(node);
        func_8003F114(node, 0, -1, D_88523004);
        *(s32 *)(node + 0x14) = i;
        *(u8 *)(node + 1) &= ~1;
    }
}

extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32 arg0, s32 arg1);
extern s32 process_geo_layout(s32 arg0, void *arg1);
extern void MainPool_FinalizeAllocation(s32 arg0);
extern s32 func_80064C88(void);
extern void func_88504828(void);
extern u8 D_8850D228;
extern u8 D_8850D25C;
extern s32 D_88523000;
extern s32 D_88523004;
extern u8 D_885229A8;
extern s8 D_8852300C[];
extern s8 D_88523009;
void func_88504A54(void) {
    s32 state;
    state = MainPool_AllocState(main_pool_get_available(), 0);
    D_88523000 = process_geo_layout(state, &D_8850D25C);
    D_88523004 = process_geo_layout(state, &D_8850D228);
    MainPool_FinalizeAllocation(state);
    *(s32 *)((u8 *)&D_885229A8 + 0) = 0;
    *(s16 *)((u8 *)&D_885229A8 + 4) = 0;
    D_8852300C[0] = func_80064C88();
    D_8852300C[1] = -1;
    D_88523009 = 0;
    func_88504828();
}

// Eight-byte header at the start of a texture returned by func_8004C990; same
// layout as TextureRenderHeader in src/4CC20.c.
//@src/4CC20.c
typedef struct TextureRenderHeader {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u16 unk_06;
} TextureRenderHeader;

extern TextureRenderHeader *func_8004C990(s32, s32);
extern u16 *func_8004CA60(TextureRenderHeader *);
extern void func_800459AC(u16 *, u8, u8, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
// Phase of the horizontal wobble; bits 4-15 index the D_80087E50 sine table.
extern u16 D_8850D2BC;
extern f32 D_80087E50[];

// Draws texture 324 twice: once at x shifted right by the wobble offset, and once mirrored
// (s from the last column, dsdx -1024) at x + 12 shifted left by the same offset, 36 pixels
// lower. The wobble is 2 * sine(D_8850D2BC) rounded to an integer. The texture is loaded and
// drawn in two half-height bands; func_800459AC loads each band from data.
//@src/44E70.c
void func_88504AF0(s16 x, s16 y) {
    TextureRenderHeader *tex;
    u16 *data;
    s32 i;
    s16 offset;
    f32 wobble;

    tex = func_8004C990(324, 0);
    data = func_8004CA60(tex);
    wobble = D_80087E50[D_8850D2BC >> 4] * 2.0f;
    offset = (s32)(((wobble > 0.0f) ? 0.5f : -0.5f) + wobble);
    // FAKE: dead store; diff score 70 without it (x + offset and x - offset + 12 swap s4/s5).
    wobble = 0.0f;
    // FAKE: the unsigned bound keeps IDO from reusing the loop-limit register for the two 2
    // arguments of func_800459AC; diff score 593 without it.
    for (i = 0; i != 2U; i++) {
        func_800459AC(data, tex->format, tex->size, tex->width, tex->height / 2, 1, 0, 2, 2, 0, 0, 0, 0);
        GfxRect_DrawTextured(x + offset, y + (i * tex->height) / 2, tex->width, tex->height / 2, -16, -16,
                             1024, 1024, 0);
        GfxRect_DrawTextured(x - offset + 12, y + (i * tex->height) / 2 + 36, tex->width, tex->height / 2,
                             ((tex->width - 1) << 5) - 16, -16, -1024, 1024, 0);
        data += tex->width * tex->height / 2;
    }
    D_8850D2BC = (s16)D_8850D2BC + 0x1000;
}


extern void func_8004AF18(s32 arg0, s16 arg1);
extern u8 D_885229A8;
extern s8 D_88523009;
extern s8 D_8852300A;
extern u16 D_8850D2C0;
extern f32 D_80087E50[];
void func_88504D9C(void) {
    s16 sp1E;
    s16 sp1C;
    s32 active;
    active = 0;
    switch (*(s32 *)&D_885229A8) {
    case 1:
        if (D_88523009 != -1) {
            active = 1;
            sp1E = D_88523009 * 0x8E + 0x7B;
            sp1C = 0x13D;
        }
        break;
    case 3:
        active = 1;
        sp1E = 0xEA;
        sp1C = (D_8852300A << 5) + 0x122;
        break;
    }
    if (active != 0) {
        func_8004AF18((s16)(D_80087E50[D_8850D2C0 >> 4] * 3.0f) + sp1E, sp1C);
    }
    *(s16 *)&D_8850D2C0 = (s16)D_8850D2C0 + 0x1000;
}

extern s8 D_8852300C[];
s32 func_88504E94(u8 arg0) {
    return D_8852300C[arg0];
}

extern s32 D_880068B8;

void func_88504EAC(void) {
    D_880068B8 = 0;
}

extern s32 D_880068B4;
extern void *D_885229A0;
extern void Util_Free(void *);
void func_88504EB8(void) {
    D_880068B4 = 1;
    Util_Free(D_885229A0);
}

/* mkdraft:func_88504EE8 begin */
extern u8 D_88000E4C;
extern void func_880048D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, void (*arg9)(void), void (*arg10)(void), void *arg11, void (*arg12)(void), s32 arg13, s32 arg14, s32 arg15);

extern void *D_885229A0;
extern u8 D_8800ED9C[];
extern u8 D_8800EDE8[];

// Create the two secondary trade-machine panels in func_880048D4 node slots 1 and 2, then give
// their rects their retail sizes: slot 1 is 0x1C7 x 0xA7 at (0x5E, 0xDA) and slot 2 is
// 0x1CC x 0x31 at (0x5B, 0x18F). D_885229A0[slot] holds the 0x4C-byte node; its width and
// height sit at +0x10/+0x12 (F29Rect at node + 4 in fragment29).
//@src/fragments/29/fragment29_168330.c


void func_88504EE8(void) {
    func_880048D4(0, 3, 0x5E, 0xDA, 0, 1, 0xE6, 0xFF, 0xF0, (void (*)(void)) ((u32) &D_88000E4C), (void (*)(void)) ((u32) &D_88000E4C), func_88504EAC, (void (*)(void)) ((u32) &D_88000E4C), 0, 0, 1); // FAKE: keeping the node callback address as a u32 expression makes IDO spill it at 0x4C; spelling it as a plain address rematerializes the constant (diff 2001).
    *(void **)((u8 *)D_885229A0 + 4) = &D_8800ED9C;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 4) + 0x10) = 0x1C7;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 4) + 0x12) = 0xA7;
    func_880048D4(0, 3, 0x5B, 0x18F, 0, 1, 0xE6, 0xFF, 0xF0, (void (*)(void)) ((u32) &D_88000E4C), (void (*)(void)) ((u32) &D_88000E4C), (void *) ((u32) &D_88000E4C), (void (*)(void)) ((u32) &D_88000E4C), 0, 0, 2);
    *(void **)((u8 *)D_885229A0 + 8) = &D_8800EDE8;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 8) + 0x10) = 0x1CC;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 8) + 0x12) = 0x31;
}
/* mkdraft:func_88504EE8 end */

// Slot record at D_885229B0[index]; offsets are Stadium 1 TradeSlotInfo + 6, from the
// accesses in func_88505264. The 0x194-byte stride backs the signed slot-index division.
extern unk_D_885229B0 D_885229B0[];

// Per-slot animation setup for the box slots in D_885229B0. State 0 clears the enable bit
// at +0x29, states 1 and 2 reset the scale fields and place the slot at x = slot index *
// 0x8E + 0x24 (0x165 for state 2), state 3 picks the rock phase from slot parity, state 4
// places the slot without touching the scale, and states 5 and 6 only restart the timer at
// +0x16. The index is `slot - D_885229B0` (signed division by the 0x194-byte stride).


void func_88505038(void *arg0, s32 arg1) {
    unk_D_885229B0 *slot = (unk_D_885229B0 *)arg0;
    u8 *entry = (u8 *)arg0 + 0x28;

    *(s32 *)arg0 = arg1;
    switch (arg1) {
    case 0:
        entry[1] &= 0xFFFE;
        break;
    case 1:
        if (slot - &D_885229B0[0] == 0) {
            slot->unk_00C = 0xF6;
            slot->unk_00E = 0xB2;
        }
        slot->unk_016 = 0;
        slot->unk_012 = 0;
        slot->unk_014 = 0;
        slot->unk_018 = 0;
        if (*(s32 *)((u8 *)arg0 + 8) != 0) {
            slot->unk_01A = 0x80;
        } else {
            slot->unk_01A = 0xFF;
        }
        slot->unk_01C = 1.0f;
        slot->unk_020 = 1.0f;
        slot->unk_024 = 1.0f;
        entry[1] |= 1;
        break;
    case 2:
        slot->unk_00C = (slot - &D_885229B0[0]) * 0x8E + 0x24;
        slot->unk_00E = 0x165;
        slot->unk_010 = slot->unk_00C;
        slot->unk_016 = 8;
        slot->unk_012 = 0;
        slot->unk_014 = 0;
        slot->unk_018 = 0;
        if (*(s32 *)((u8 *)arg0 + 8) != 0) {
            slot->unk_01A = 0x80;
        } else {
            slot->unk_01A = 0xFF;
        }
        slot->unk_020 = 1.0f;
        slot->unk_024 = 1.0f;
        slot->unk_01C = 0.0f;
        entry[1] |= 1;
        break;
    case 3:
        slot->unk_016 = 0;
        slot->unk_010 = slot->unk_00C;
        if ((slot - &D_885229B0[0]) & 1) {
            slot->unk_012 = -0x8000;
        } else {
            slot->unk_012 = 0;
        }
        slot->unk_014 = slot->unk_012;
        slot->unk_01C = 1.0f;
        break;
    case 4:
        slot->unk_00C = (slot - &D_885229B0[0]) * 0x8E + 0x24;
        slot->unk_00E = 0x165;
        slot->unk_016 = 8;
        slot->unk_012 = 0;
        slot->unk_014 = 0;
        slot->unk_018 = 0;
        slot->unk_020 = 1.0f;
        slot->unk_024 = 1.0f;
        break;
    case 5:
        slot->unk_016 = 8;
        break;
    case 6:
        slot->unk_016 = 8;
        break;
    }
}

extern s16 D_8850D2C2[];
extern f32 D_80088E50[];
extern s32 MathUtil_Random16(void);
// Bob/sway animation of one slot: unk_00C and unk_018 follow the sine of phase unk_012, the
// scales unk_020/unk_024 follow phase unk_014; the slot after D_88523009 moves at double
// amplitude. D_8850D2C2[index] is the per-slot phase step. Same body as Pokemon Stadium 1
// Trade_UpdateBoxSlotBob (src/fragments/trade_machine/trade_machine_28ED00.c there).
void func_88505264(unk_D_885229B0 *arg0) {
    s32 temp_lo = arg0 - &D_885229B0[0];
    s16 var_a2;
    s16 var_a3;
    f32 var_fv0;
    f32 var_fv1;

    if (temp_lo - 1 == D_88523009) {
        var_fv0 = 1.5f;
        var_a2 = D_8850D2C2[temp_lo] * 2;
        var_fv1 = 0.06f;
        var_a3 = 0x3000;
    } else {
        var_a2 = D_8850D2C2[temp_lo];
        var_fv1 = 0.02f;
        var_a3 = 0x2000;
        var_fv0 = 1.0f;
    }

    arg0->unk_00C = arg0->unk_010 - (D_80087E50[(u16) arg0->unk_012 >> 4] * (6.0f * var_fv0));

    arg0->unk_018 = D_80087E50[(u16) arg0->unk_012 >> 4] * (1536.0f * var_fv0);
    arg0->unk_020 = (D_80087E50[(u16) arg0->unk_014 >> 4] * var_fv1) + 1.0f;
    arg0->unk_024 = (D_80088E50[(u16) arg0->unk_014 >> 4] * var_fv1) + 1.0f;

    arg0->unk_012 += var_a2;
    arg0->unk_014 += var_a3 + ((MathUtil_Random16() & 0xF) * 16);
}

extern void func_88505038(void *arg0, s32 arg1);
void func_885053E8(void *arg0) {
    s16 value;
    *(s16 *)((u8 *)arg0 + 0x16) = *(s16 *)((u8 *)arg0 + 0x16) - 1;
    value = *(s16 *)((u8 *)arg0 + 0x16);
    *(f32 *)((u8 *)arg0 + 0x1C) = (f32)(8 - value) / 8;
    if (value <= 0) {
        func_88505038(arg0, 3);
    }
}

void func_88505440(unk_D_885229B0 *arg0) {
    func_88505264(arg0);
}

extern void func_88505038(void *arg0, s32 arg1);
extern s8 D_8852300D;
void func_88505460(void *arg0) {
    s16 value;
    *(s16 *)((u8 *)arg0 + 0x16) = *(s16 *)((u8 *)arg0 + 0x16) - 1;
    value = *(s16 *)((u8 *)arg0 + 0x16);
    *(s16 *)((u8 *)arg0 + 0x0C) = (s16)(0x207 - ((0x207 - *(s16 *)((u8 *)arg0 + 0x10)) * value) / 8);
    *(s16 *)((u8 *)arg0 + 0x0E) = (s16)(0xB2 - (value * -0xB3) / 8);
    if (value <= 0) {
        func_88505038(arg0, 1);
        D_8852300D = *(s16 *)((u8 *)arg0 + 4);
    }
}

void func_88505514(void *arg0) {
    (*(s16 *)((u8 *)(arg0) + (0x16))) = (s16) ((*(s16 *)((u8 *)(arg0) + (0x16))) - 1);
    (*(s16 *)((u8 *)(arg0) + (0x1A))) = (s16) ((s32) ((*(s16 *)((u8 *)(arg0) + (0x16))) * 0xFF) / 8);
}

void Trade_UpdateBoxSlotShrink(void *arg0)
{
  s16 temp_v0;
  func_88505264(arg0);
 *((s16 *) (((u8 *) arg0) + 0x16)) = (s16) ((*((s16 *) (((u8 *) arg0) + 0x16))) - 1); temp_v0 = *((s16 *) (((u8 *) arg0) + 0x16));
  *((f32 *) (((u8 *) arg0) + 0x1C)) = (f32) (((f32) temp_v0) / 8);
  if (temp_v0 <= 0)
  {
    func_88505038(arg0, 0);
  }
}

/* mkdraft:func_885055A0 begin */
extern u8 D_88523008[];
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);

// Per-slot animation step: dispatch on the slot's state word, then push the slot's animation
// values into the display object embedded at offset 0x28 of the record. State 0 is the idle
// state written by func_88505038, so it runs no step here but still syncs the object.
// The embedded object's field layout (alpha at 0x1D, rotation at 0x1E, position at 0x24,
// scale at 0x30) is S1_unk_D_86002F58_004_000's; //@include/229E0.h


void func_885055A0(void) {
    struct SlotModel {
        u8 unk_000[0x1D];
        u8 alpha;        /* 0x01D */
        u8 unk_01E[4];   /* 0x01E rotation, x and y */
        s16 rotationZ;   /* 0x022 */
        f32 position[3]; /* 0x024 */
        f32 scaleX;      /* 0x030 */
        f32 scaleY;      /* 0x034 */
    };
    s32 i;
    unk_D_885229B0 *p;

    p = &D_885229B0[0];
    i = 0;
    if (*(s8 *)D_88523008 > 0) {
        do {
            switch (*(s32 *)p) {
                case 0:
                case 1:
                    break;
                case 2:
                    func_885053E8(p);
                    break;
                case 3:
                    func_88505440(p);
                    break;
                case 4:
                    func_88505460(p);
                    break;
                case 5:
                    func_88505514(p);
                    break;
                case 6:
                    Trade_UpdateBoxSlotShrink(p);
                    break;
            }
            if (*(s32 *)p != 0) {
                struct SlotModel *model = (struct SlotModel *)((u8 *)p + 0x28);

                Vec3f_SetComponentsDuplicate(model->position,
                                             (f32)p->unk_00C - 320.0f,
                                             240.0f - (f32)p->unk_00E,
                                             -579.0f);
                model->rotationZ = p->unk_018;
                model->alpha = p->unk_01A;
                model->scaleX = p->unk_020 * p->unk_01C;
                model->scaleY = p->unk_024 * p->unk_01C;
            }
            i++;
            p++;
        } while (i < *(s8 *)D_88523008);
    }
}
/* mkdraft:func_885055A0 end */

extern void func_80057944(u8);
void func_88505718(void) {
    s32 i;

    if (D_8852300C[1] != -1) {
        func_80057944(D_8852300C[1]);
        D_8852300C[1] = -1;
    }
    *(s32 *)&D_885229A8 = 1;
    *(s16 *)((u8 *)&D_885229A8 + 4) = 0;
    func_88505038(&D_885229B0[0], 1);
    for (i = 0; i < 3; i++) {
        if (D_885229B0[i + 1].unk_004 != -1) {
            func_88505038(&D_885229B0[i + 1], 2);
        }
    }
}

extern s8 D_8852300A;
extern void func_88505718(void);
extern void func_88504EE8(void);
void func_885057BC(void) {
    if (D_8852300A == 1) {
        func_88505718();
        func_88504EE8();
    }
}

/* mkdraft:func_885057F4 begin */
extern void func_800226C0(s32);
extern void func_880002F4(u8 *arg0, s16 arg1);
extern void func_88004990(u8 slot, u8 amount);
extern void *D_80087200;
extern unk_D_885229B0 D_885229B0[];
extern void *D_885229A0;
extern u8 D_885229A8;
extern s8 D_88523009;
extern s8 D_8852300A;
extern s32 D_880068B8;
// Menu handler for the trade-machine slot list: D_80087200 controller press word bits 0x8000
// (confirm) and 0x4000 (confirm with reset of the selected slot) move D_8852300A to 1 and play
// slot sound 3; bits 0x800/0x400 step D_8852300A down/up by one within 0..1. current keeps the
// pre-step value so the change sound only plays when the selection actually moved.


void func_885057F4(void) {
    s32 pressed;
    s8 current;
    s32 mode;

    mode = *((u16 *)((u8 *)D_80087200 + 8));
    pressed = 0;
    if (mode & 0x8000) {
        func_88004990(3, 0);
        pressed = 1;
    } else if (mode & 0x4000) {
        func_88004990(3, 0);
        pressed = 1;
        D_8852300A = 1;
    } else {
        current = D_8852300A;
        if (mode & 0x800) {
            if (D_8852300A > 0) {
                D_8852300A -= 1;
            }
        } else if (mode & 0x400) {
            if (D_8852300A <= 0) {
                D_8852300A += 1;
            }
        }
        if (current != D_8852300A) {
            func_800226C0(1);
        }
    }
    if (pressed) {
        if (!D_8852300A) {
            func_800226C0(15);
            *(s32 *)&D_885229A8 = 0;
            func_88505038(&D_885229B0[0], 0);
            func_88505038(&D_885229B0[D_88523009 + 1], 0);
            func_88004990(0, 0);
            D_880068B8 = 1;
        } else {
            func_800226C0(3);
            func_88505038(&D_885229B0[D_88523009 + 1], 5);
            func_880002F4((u8 *)D_885229A0 + 0x10, 0);
        }
    }
}
/* mkdraft:func_885057F4 end */

extern void func_800498C4(void);
extern void func_800496A4(s32 arg0, s32 arg1);
extern s32 func_8004C874(s32 arg0, s32 arg1);
extern void func_80048E30(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_800499EC(void);
extern void func_88504D9C(void);
extern s32 D_8800687C;
void func_885059B8(void) {
    s32 i;
    s32 value;
    s32 result;
    func_800498C4();
    func_800496A4(0x10, 1);
    result = func_8004C874(0x34, 6);
    func_80048E30(D_8800687C, 0xD8, 0xFE, result, 1);
    i = 0;
    value = 0x122;
    do {
        result = func_8004C874(0x34, i + 7);
        func_80048E30(D_8800687C, 0x112, value, result, 1);
        i++;
        value += 0x20;
    } while (i != 2);
    func_800499EC();
    func_88504D9C();
}

extern void func_880048D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, void (*arg9)(void), void (*arg10)(void), void *arg11, void (*arg12)(void), s32 arg13, s32 arg14, s32 arg15);
extern void func_885057F4(void);
extern void func_885059B8(void);
extern void func_885057BC(void);
extern void *D_885229A0;
extern u8 D_885229A8;
extern s8 D_8852300A;
extern u8 D_88000E4C;
extern u8 D_8800EE34;
void func_88505A7C(void) {
    *(s32 *)((u8 *)&D_885229A8 + 0) = 3;
    D_8852300A = 0;
    func_880048D4(0, 3, 0xC5, 0xF1, 0, 1, 0xE6, 0xFF, 0xF0, func_885057F4, func_885059B8, &D_88000E4C, func_885057BC, 0, 0, 3);
    *(void **)((u8 *)D_885229A0 + 0x0C) = &D_8800EE34;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 0x0C) + 0x10) = 0xF9;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 0x0C) + 0x12) = 0x79;
}

/* mkdraft:func_88505B58 begin */
extern void LabPC_OpenMessageDialog();
extern void func_800226C0(s32);
extern void func_80057908(u8 arg0);
extern void func_88004990(u8 slot, u8 amount);
extern u8 D_88523008[];
extern void *D_80087200;
extern u8 D_88522B49[];
extern s8 D_88523009;
extern unk_D_885229B0 D_885229B0[];
extern u8 D_885229A8;
extern s32 D_880068B8;
extern s32 func_8004C874(s32, s32);
extern void func_88505038(void*, s32);



void func_88505B58(void)
{
  s32 index; // FAKE: never read; the declaration shifts temp numbering, diff score 20 when dropped.
  s32 result;
  s32 mode_index;
  s16 temp_a0;
  s32 flags;
  u8 *p;
  u8 *end;
  unk_D_885229B0 *slot;
  MathUtil_Random16();
  flags = *((u16 *) (((u8 *) D_80087200) + 8));
  if (flags & 0x8000)
  {
    if (D_88523009 != (-1))
    {
      slot = &D_885229B0[D_88523009];
      if (((*((s32 *) (((u8 *) slot) + 0x19C))) == (-1)) || ((*((s16 *) (((u8 *) slot) + 0x198))) == (-1)))
      {
        func_800226C0(5);
        return;
      }
      if ((*((s32 *) (((u8 *) slot) + 0x19C))) == 0)
      {
        func_800226C0(0x8F);
        *((s32 *) (&D_885229A8)) = 2;
        *((s16 *) (((u8 *) (&D_885229A8)) + 4)) = 8;
        for (mode_index = 0; mode_index != 3; mode_index++)
        {
          p = (u8 *) (&D_885229B0[mode_index]);
          if ((*((s16 *) (p + 0x198))) != (-1))
          {
            if (mode_index != D_88523009)
            {
              func_88505038(p + 0x194, 6);
            }
            else
            {
              func_88505038(p + 0x194, 4);
              if (!p) // FAKE: empty block after func_88505038(p + 0x194, 4); diff score 80 without it.
              {
              }
            }
          }
        }

        func_88004990(1, 0);
        func_88004990(2, 0);
        D_880068B8 = 1;
        func_80057908(*((u8 *) (((u8 *) (&D_88522B49)) + (D_88523009 * 0x194))));
        return;
      }
      switch (*((s32 *) (((u8 *) slot) + 0x19C)))
      {
        case 1:
          result = func_8004C874(0x34, 9);
          break;

        case 2:
          result = func_8004C874(0x34, 0xA);
          break;

        case 3:
          result = func_8004C874(0x34, 0xB);
          break;

        case 4:
          result = func_8004C874(0x34, 0xC);
          break;

      }

      LabPC_OpenMessageDialog(result, 0x141, 0x12D, 4, 0xFF, 0xAA, 0x8C, 0, 1, ((u8 *) D_885229A0) + 0x1C, ((u8 *) D_885229A0) + 0x20, &D_88000E4C, &D_88000E4C);
      return;
    }
  }
  if (flags & 0x4000)
  {
    func_800226C0(3);
    *((s32 *) (&D_885229A8)) = 0;
    p = (u8 *) (&D_885229B0[0]); end = (u8 *) (&D_88523000);
    do
    {
      func_88505038(p, 0);
      p += 0x194;
    }
    while (p != end);
    func_88004990(0, 0);
    func_88004990(1, 0);
    func_88004990(2, 0);
    D_880068B8 = 1;
    return;
  }
  if (D_88523009 == (-1))
  {
    return;
  }
  temp_a0 = D_88523009;
  if (flags & 0x200)
  {
    if (D_88523009 > 0)
    {
      D_88523009 = D_88523009 - 1;
    }
  }
  else
    if (flags & 0x100)
  {
    if (D_88523009 < (*(s8 *)D_88523008 - 2))
    {
      D_88523009 = D_88523009 + 1;
    }
  }
  if (temp_a0 != D_88523009)
  {
    func_800226C0(1);
  }
}
/* mkdraft:func_88505B58 end */

extern void func_88505A7C();
extern u8 D_885229A8;

void func_88505E9C(void) {
    (*(s16 *)((u8 *)(&D_885229A8) + (4))) = (s16) ((*(s16 *)((u8 *)(&D_885229A8) + (4))) - 1);
    if ((*(s16 *)((u8 *)(&D_885229A8) + (4))) <= 0) {
        func_88505A7C();
    }
}

/* mkdraft:func_88505EDC begin */
// func_88505EDC: per-frame refresh of the four trade records in D_885229B0 plus
// the trade state machine step.
//
// When the trade state word is nonzero the records are rebuilt from controller
// state by func_88504704 (it fills four 20-byte entries of D_8850D678), then
// each of the four 0x194-byte slots has its readiness re-evaluated:
// func_885047B4 reads the entry selected by the slot's s16 index at +4 and the
// result is cached at +8; a failed (-1) evaluation clears the slot index and
// hides the slot with func_88505038(slot, 0).
//
// The switch then dispatches on the state word: 1 enters func_88505B58 when the
// menu object's +0x20 word is 2 and D_885229A0+0x1C is set, 2 counts down via
// func_88505E9C, 3 does nothing. func_885055A0 runs every frame.
//
// Score 0 in the GS decomp tree (build/pokestadiumgs-us.z64: OK); the
// formatting constraints that hold the match are annotated below.
extern u8 D_8850D678[];
extern void func_88504704(void);
extern s16 func_885047B4(u8 *arg0);
extern void func_88505038(void *arg0, s32 arg1);
extern u8 D_885229A8;
extern void *D_885229A0;
extern void func_88505B58(void);
extern void func_88505E9C(void);
extern void func_885055A0(void);

/* mkdraft:func_88505EDC begin */



void func_88505EDC(void)
{
  u8 *new_var2;
  u8 *var_s0;
  s32 temp_v0_2;
  s32 var_s2;
  // FAKE: the single header line below is load-bearing. as1 breaks scheduling
  // ties by .loc line number: emitting the two pointer initializations, the
  // D_885229A8 test, the func_88504704() call and the for header on separate
  // lines swaps the lui/addiu order of the s4 (D_8850D678) and s0
  // (D_885229B0) address materialization.
  // FAKE: the empty `if (var_s2 == 4)` at the top of the loop body places the
  // loop bound in $s3 (bne $s2,$s3) and the 20-byte record stride in $s5
  // (multu $v0,$s5); without it the two constants take each other's register
  // and seven instruction words differ.
  new_var2 = (u8 *)D_885229B0; var_s0 = (u8 *)D_885229B0; if ((*((s32 *) (((u8 *) (&D_885229A8)) + 0))) != 0) { func_88504704(); var_s0 = new_var2; for (var_s2 = 0; var_s2 < 4; var_s2++, var_s0 += 0x194) {
    if (var_s2 == 4) {}
    if ((*((s16 *) (var_s0 + 4))) != (-1)) {
      temp_v0_2 = func_885047B4(&D_8850D678[*((s16 *) (var_s0 + 4)) * 20]);
      *((s32 *) (var_s0 + 8)) = temp_v0_2;
      if ((temp_v0_2 == (-1)) && ((*((s16 *) (var_s0 + 4))) != (-1))) {
        *((s16 *) (var_s0 + 4)) = -1;
        func_88505038(var_s0, 0);
      }
    }
  }
  switch (*((s32 *) (((u8 *) (&D_885229A8)) + 0))) {
    case 3:
      break;
    case 1:
      if (((*((s32 *) (((u8 *) (*((void **) (((u8 *) D_885229A0) + 4)))) + 0x20))) == 2) && ((*((s32 *) (((u8 *) D_885229A0) + 0x1C))) != 0)) {
        func_88505B58();
      }
      break;
    case 2:
      func_88505E9C();
      break;
  }
  func_885055A0();
  }
}
/* mkdraft:func_88505EDC end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_88506018.s")

extern void *Util_Malloc(s32);
extern s32 D_885229B8;
extern u8 D_8800ED50;
extern void func_88505EDC(void);
extern void func_88506018(void);
extern void func_88504EB8(void);
extern void func_88000288(void *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_80001FF0(void);
extern void func_880048D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, void (*arg9)(void), void (*arg10)(void), void *arg11, void (*arg12)(void), s32 arg13, s32 arg14, s32 arg15);
extern void func_88504828(void);
extern void func_88504EE8(void);
extern void func_88505718(void);
extern u8 D_88000E4C;
extern s32 D_880068B4;
extern void * D_885229A0;
extern s8 D_88523009;
void func_88506618(void) {
    func_88504828();
    D_885229A0 = Util_Malloc(0x24);
    func_88505718();
    D_88523009 = -1;
    if (D_885229B8 == 0) {
        D_88523009 = 0;
    }
    func_880048D4(0, 3, 0x41, 0x3E, 0, 1, 0xE6, 0xFF, 0xF0, func_88505EDC, func_88506018, &D_88000E4C, func_88504EB8, 0, 0, 0);
    *(void **)((u8 *)D_885229A0 + 0) = &D_8800ED50;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 0) + 0x10) = 0x201;
    *(s16 *)((u8 *)*(void **)((u8 *)D_885229A0 + 0) + 0x12) = 0x8E;
    func_88504EE8();
    func_88000288((u8 *)D_885229A0 + 0x10, 0, 0xAA, 0x46, (s32)((f32)1 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)1 / 60.0f > 0.0f) ? 0.5f : -0.5f)), (s32)((f32)20 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)20 / 60.0f > 0.0f) ? 0.5f : -0.5f)), (s32)((f32)1 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)1 / 60.0f > 0.0f) ? 0.5f : -0.5f)), (s32)((f32)20 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)20 / 60.0f > 0.0f) ? 0.5f : -0.5f)));
    D_880068B4 = 0;
    *(s32 *)((u8 *)D_885229A0 + 0x1C) = 1;
}
#endif
