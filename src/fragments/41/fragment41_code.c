#include "global.h"
#include "controller.h"


#ifdef VERSION_US
typedef struct { u16 unk00; u8 unk02; u8 unk03; u8 unk04; } Frag41_Input;
typedef struct {
    u8 pad00[0x20];
    u16 unk20;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    s16 unk26;
    s32 unk28;
    u8 pad2C[0x2];
    u16 unk2E;
} Frag41_State;
extern void Input_SetRepeatController(void *);
extern Frag41_State *D_88C01A60;
void func_88C00020(Frag41_Input *arg0) {
    D_88C01A60->unk20 = arg0->unk00;
    D_88C01A60->unk22 = arg0->unk02;
    D_88C01A60->unk23 = arg0->unk03;
    D_88C01A60->unk24 = arg0->unk04;
    D_88C01A60->unk26 = 0;
    Input_SetRepeatController(D_80087200);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_code/func_88C00084.s")

extern Gfx* D_800D0510;
extern char D_88C01924[];
extern char D_88C01934[];
extern char D_88C01964[];
extern char D_88C01988[];
extern char D_88C019C4[];
extern char D_88C019F4[];
extern char D_88C019F8[];
extern char D_88C01A08[];
extern char D_88C01A1C[];
extern char D_88C01A20[];
extern char D_88C01A28[];
extern char D_88C01A30[];
extern char D_88C01A38[];
extern char D_88C01A3C[];
extern char D_88C01A40[];
extern char D_88C01A44[];
extern char* D_88C01830[];

void func_88C006B8(void) {
    func_80007444(&D_800D0510, 50, 90, 293, 155, 0x7C67);
    func_800498C4();
    func_800496A4(16, 2);
    func_8004972C(0x32, 0x80, 0xFF, 0xFF);
    func_800495F8(60, 100, 0, D_88C01924);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800495F8(40, 260, 0, D_88C01934);
    func_800495F8(40, 290, 0, D_88C01964, D_88C01A60->unk2E);
    func_800495F8(40, 320, 0, D_88C01988);
    func_8004972C(0xFF, 0x64, 0x64, 0xFF);
    func_800495F8(50, 360, 0, D_88C019C4);
    func_800495F8(50, 390, 0, D_88C019F4);
    func_800496A4(8, 1);
    if (D_88C01A60->unk28 == 2) {
        func_8004972C(0xFF, 0, 0, 0xFF);
        func_800495F8(590, 200, 2, D_88C019F8);
        func_800495F8(590, 220, 2, D_88C01A08);
    }
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800495F8(60, 140, 0, D_88C01A1C);
    func_800495F8(60, 165, 0, D_88C01A20);
    func_800495F8(60, 190, 0, D_88C01A28);
    func_800495F8(60, 215, 0, D_88C01A30);
    if (D_88C01A60->unk26 == 0) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_800495F8(190, 140, 2, D_88C01A38, D_88C01A60->unk20);
    func_800495F8(200, 140, 0, D_88C01830[D_88C01A60->unk20 % 7]);
    if (D_88C01A60->unk26 == 1) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_800495F8(190, 165, 2, D_88C01A3C, D_88C01A60->unk22);
    if (D_88C01A60->unk26 == 2) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_800495F8(190, 190, 2, D_88C01A40, D_88C01A60->unk23);
    if (D_88C01A60->unk26 == 3) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_800495F8(190, 215, 2, D_88C01A44, D_88C01A60->unk24);
    func_800499EC();
}

/* mkdraft:func_88C00AB0 begin */
extern u32 D_800CDA34;
extern s32 func_80001FF0(void);
extern void func_800226C0(s32);

// View of D_88C01A60 as a wall clock: func_88C00AB0 advances unk0C by the frame
// count elapsed since the unk08 timestamp, then cascades unk04/unk03/unk02/unk00
// through 60 seconds, 60 minutes, 24 hours and a day count that wraps at unk2E.
typedef struct {
    u16 unk00;
    u8 unk02;
    u8 unk03;
    u8 unk04;
    u8 pad05[3];
    u32 unk08;
    u16 unk0C;
    u8 pad0E[0x12];
    u16 unk20;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    s16 unk26;
    s32 unk28;
    u16 unk2C;
    u16 unk2E;
} Frag41_Clock;



void func_88C00AB0(s32 arg0) {
    Frag41_Clock *clk = (Frag41_Clock *)D_88C01A60;
    // The frame counter at D_800CDA34 + 0x20 has no symbol of its own.
    u32 now = *(u32 *)((u8 *)&D_800CDA34 + 0x20);
    s32 period;

    // The two arms compute the same value because the late timestamp is handled by
    // the wrap-around form in the second arm; the ROM keeps the two tests separate.
    if (clk->unk08 < now) {
        clk->unk0C = (u16)((clk->unk0C + now) - clk->unk08);
    } else if (now < clk->unk08) {
        // FAKE: 330 without it. Adding 2^32 to now is discarded by the u16 store; the
        // 64-bit type is what makes IDO copy the sum to a new temporary before the
        // subtraction, which sets the register coloring for the rest of the function.
        // Time deltas elsewhere in the engine use this same wrap-around idiom, so the
        // 64-bit add may be original source rather than match-only padding.
        clk->unk0C = (u16)((clk->unk0C + (now + 0xFFFFFFFFLL + 1)) - clk->unk08);
    }
    clk->unk08 = now;

    // func_80001FF0 returns the frame rate, so unk0C accumulates the frames since
    // the last whole second and a full period of them advances the seconds counter.
    period = func_80001FF0();
    if (clk->unk0C < period) {
        return;
    }
    if (arg0 == 1) {
        func_800226C0(0x155);
    }
    clk->unk0C = (u16)(clk->unk0C - func_80001FF0());

    if (++clk->unk04 >= 0x3C) {
        clk->unk04 -= 0x3C;
        if (++clk->unk03 >= 0x3C) {
            clk->unk03 -= 0x3C;
            if (++clk->unk02 >= 0x18) {
                clk->unk02 -= 0x18;
                if (++clk->unk00 > D_88C01A60->unk2E) {
                    clk->unk00 = 0;
                }
            }
        }
    }
}
/* mkdraft:func_88C00AB0 end */

typedef float Frag41_MtxF_t[4][4];
typedef union {
    Frag41_MtxF_t mf;
    struct {
        f32 xx, yx, zx, wx;
        f32 xy, yy, zy, wy;
        f32 xz, yz, zz, wz;
        f32 xw, yw, zw, ww;
    };
} Frag41_MtxF;

void MathUtil_BuildTransformMtx_fragment41(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA) {
    Frag41_MtxF sp20;

    guRotateF(sp20.mf, arg4, arg5, arg6, arg7);

    sp20.xx *= arg1;
    sp20.yx *= arg1;
    sp20.zx *= arg1;

    sp20.xy *= arg2;
    sp20.yy *= arg2;
    sp20.zy *= arg2;

    sp20.xz *= arg3;
    sp20.yz *= arg3;
    sp20.zz *= arg3;

    sp20.xw = arg8;
    sp20.yw = arg9;
    sp20.zw = argA;

    guMtxF2L(sp20.mf, arg0);
}

/* mkdraft:func_88C00CE4 begin */
extern s32 func_8000731C(void);
extern void *Gfx_AllocDisplayList(s32);
extern void Gfx_SetViewportDimensions(void *, s16, s16);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void MathUtil_BuildTransformMtx_fragment41(Mtx *, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
extern char D_88C01850[];
extern f32 D_88C01A48;
extern f32 D_88C01A4C;



void func_88C00CE4(f32 arg0, s32 arg1) {
    s32 pad;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s16 *dims;

    dims = (s16 *)func_8000731C();
    sp50 = Gfx_AllocDisplayList(0x40);
    sp4C = Gfx_AllocDisplayList(0x40);
    sp48 = Gfx_AllocDisplayList(0x10);
    Gfx_SetViewportDimensions((void *)sp48, dims[2], dims[3]);
    gSPViewport(D_800D0510++, (u32)sp48 & 0x1FFFFFFF);
    guOrtho((Mtx *)sp50, -320.0f, 320.0f, -240.0f, 240.0f, -2.0f, 2.0f, 1.0f);
    MathUtil_BuildTransformMtx_fragment41((Mtx *)sp4C, 1.0f, 1.0f, 1.0f, arg0, 0.0f, 0.0f, 1.0f, D_88C01A48, D_88C01A4C, 0.0f);
    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
    gDPSetRenderMode(D_800D0510++, 0x504240, 0);
    if (arg1 == 2) {
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF279);
    } else {
        gDPSetCombine(D_800D0510++, 0x30FE61, 0x55FEF379);
        gDPSetColor(D_800D0510++, G_SETPRIMCOLOR, 0xFFFFFFFF);
        gDPSetColor(D_800D0510++, G_SETENVCOLOR, 0x0F1764FF);
    }
    gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_LIGHTING);
    gSPSetGeometryMode(D_800D0510++, G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(D_800D0510++, G_TP_PERSP);
    switch (arg1) {
    case 0:
        sp44 = 1;
        break;
    case 1:
        sp44 = 2;
        break;
    case 2:
        sp44 = 3;
        break;
    }
    gSPPerspNormalize(D_800D0510++, 0xFFFF);
    func_8004D1FC(func_8004C990(0x1C1, sp44));
    gSPMatrix(D_800D0510++, (u32)sp50 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(D_800D0510++, (u32)sp4C & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(D_800D0510++, (u32)D_88C01850 & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(D_800D0510++, 0, 2, 3, 0, 0, 3, 1, 0);
}
/* mkdraft:func_88C00CE4 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_code/func_88C0107C.s")

extern s32 func_80001FF0(void);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_88C0107C(s32);
extern f32 D_88C01A50;
void func_88C01398(void) {
    u16 count;
    s32 i;
    count = (u16)((f32)func_80001FF0() * D_88C01A50 / 2);
    StageFade_StartFromOpaque(count);
    if (count != 0) {
        i = 0;
        do {
            func_80064D28();
            func_88C0107C(0);
            i++;
        } while (i != count);
    }
}

extern s32 func_88C00084(void);

void func_88C01494(void) {
    s32 done;

    do {
        func_80064D28();
        done = func_88C00084();
        func_88C0107C(1);
    } while (done == 0);
}

extern void func_800225C4(s32);
extern void StageFade_StartFromTransparent(s32);
extern f32 D_88C01A54;
void func_88C014D8(void) {
    u16 count;
    s32 i;
    count = (u16)((f32)func_80001FF0() * D_88C01A54 / 2);
    func_800225C4(count * 2);
    StageFade_StartFromTransparent(count);
    if (count != 0) {
        i = 0;
        do {
            func_80064D28();
            func_88C0107C(2);
            i++;
        } while (i != count);
    }
}

/* mkdraft:func_88C015DC begin */
extern void func_8004C8C0(s32);
extern void func_80057908(s32);
extern void func_8005A014(s32);
extern void func_8005A034(s32);
extern s32 func_8005D92C(s32);
extern s32 GbSave_ReadRtcTimeWithSavedOffset(u8, u16 *, u8 *, u8 *, u8 *);
extern s32 func_8005F3B0(s32, s32, s32, s32, s32);
extern void *Util_Malloc(s32);
extern u32 D_800CDA34;

// Fields func_88C015DC writes into the 0x30-byte block D_88C01A60 points at.
// Frag41_State (above) names the 0x20-0x2E words for func_88C00020 and
// func_88C006B8; this view adds the RTC fields at 0x00-0x04 and 0x10-0x14 and
// the 0x08/0x0C timestamp.
typedef struct {
    u16 unk00;      // days, as reported by GbSave_ReadRtcTimeWithSavedOffset
    u8 unk02;       // hours
    u8 unk03;       // minutes
    u8 unk04;       // seconds
    u8 pad05[3];
    s32 unk08;      // D_800CDA34 plus 0x20
    s16 unk0C;
    s16 pad0E;
    u16 unk10;      // days, as reported by func_8005F3B0
    u8 unk12;       // hours
    u8 unk13;       // minutes
    u8 unk14;       // seconds
    u8 pad15[0x13];
    s32 unk28;      // 2 when the saved RTC time could not be read, 1 when the
                    // time source is busy, 0 when a time was read
    s16 unk2C;      // days elapsed since the saved time, or 0
    u16 unk2E;      // 0x1FF plus the elapsed days; the day text's printf value
} Frag41_SaveState;

// FAKE: func_8005F3B0 is void in src/585D0.c. Declaring the s32 return type here
// is what reproduces the target's argument staging; with void it scores 255.


void func_88C015DC(void) {
    Frag41_SaveState *state;
    s32 day_delta;
    s32 rtc_status;
    s32 status;

    func_80057908(0);
    func_8005A014(0);
    func_8005A034(0);
    D_88C01A60 = Util_Malloc(0x30);
    func_8004C8C0(0x1C3);
    func_8004C8C0(0x1C1);
    func_8004C8C0(0x1C5);
    D_88C01A60->unk28 = 0;
    // The block is cached here, but the stores at 0x10-0x14 and the two 0x28
    // reads below reload D_88C01A60 from the global.
    state = (Frag41_SaveState *) D_88C01A60;
    rtc_status = func_8005D92C(0);
    if ((rtc_status == 1) || (rtc_status == 2) || (rtc_status == 3) || (rtc_status == 4)) {
        D_88C01A60->unk28 = 1;
        status = D_88C01A60->unk28;
    } else {
        if (GbSave_ReadRtcTimeWithSavedOffset(0, &state->unk00, &state->unk02, &state->unk03, &state->unk04) != 0) {
            D_88C01A60->unk28 = 2;
        }
        ((Frag41_SaveState *) D_88C01A60)->unk2C = 0;
        D_88C01A60->unk2E = 0x1FF;
        status = D_88C01A60->unk28;
        if (D_88C01A60->unk28 != 2) {
            func_8005F3B0(0, (s32) &((Frag41_SaveState *) D_88C01A60)->unk10, (s32) &((Frag41_SaveState *) D_88C01A60)->unk12,
                          (s32) &((Frag41_SaveState *) D_88C01A60)->unk13, (s32) &((Frag41_SaveState *) D_88C01A60)->unk14);
            day_delta = (state->unk00 - ((Frag41_SaveState *) D_88C01A60)->unk10) & 0xFF;
            ((Frag41_SaveState *) D_88C01A60)->unk2C = day_delta;
            D_88C01A60->unk2E = day_delta + 0x1FF;
            status = D_88C01A60->unk28;
        }
    }
    if (status != 0) {
        // No usable time: display day 1, 00:00.
        state->unk00 = 1;
        state->unk02 = 1;
        state->unk03 = 0;
        state->unk04 = 0;
    }
    state->unk08 = *(u32 *) ((u8 *) &D_800CDA34 + 0x20);
    state->unk0C = 0;
    func_88C00020((Frag41_Input *) state);
}
/* mkdraft:func_88C015DC end */

extern void Gfx_InitDisplayListBuffers(s32, s32);
s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32);
extern void func_80008574();
extern void func_88C015DC();
extern void main_pool_pop_state(s32);
extern void main_pool_push_state(s32);
s32 fragment41_main(s32 arg0, s32 arg1) {
    s32 sp24;

    main_pool_push_state(0x434C4544);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(3);
    func_80047588(0x18, 0);
    func_88C015DC();
    func_80008514(sp24);
    func_88C01398();
    func_88C01494();
    func_88C014D8();
    func_80008574();
    Util_Free((s32) D_88C01A60);
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    func_80057944(0U);
    main_pool_pop_state(0x434C4544);
    return 0;
}
#endif
