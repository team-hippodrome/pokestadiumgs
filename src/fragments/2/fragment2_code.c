#include "global.h"
typedef struct Fragment2Model {
    /* 0x000 */ u8 unk_000[0x14];
    /* 0x014 */ s32 index;
    /* 0x018 */ u8 unk_018[0xC];
    /* 0x024 */ f32 x;
    /* 0x028 */ f32 y;
    /* 0x02C */ u8 unk_02C[4];
    /* 0x030 */ f32 unk_030;
    /* 0x034 */ f32 unk_034;
    /* 0x038 */ f32 unk_038;
    /* 0x03C */ u8 unk_03C[0x168 - 0x3C];
} Fragment2Model; // size = 0x168

typedef struct Fragment2State {
    /* 0x000 */ s32 active[4];
    /* 0x010 */ f32 scale;
    /* 0x014 */ s16 unk_014;
    /* 0x016 */ u8 unk_016[6];
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ Fragment2Model models[4];
} Fragment2State;
// Defined here (pinned at 0x81900820 by datamig_bss.ld) so as1 can fold the
// shared `lui $at` for stores to its fields, as in func_81900020.
static Fragment2State D_81900820;
// FAKE: fills 0x81900DE0..0x81900DFB (D_81900DE0, D_81900DF8 and neighbours)
// so func_8190037C's sBlinkTimer stays at 0x81900DFC.
static u8 sFragment2StatePad[0x1C];


#ifdef VERSION_US
extern s16 D_81900710;
extern f32 D_81900714;
extern s32 D_81900718;
extern u8 D_8190071C[];
extern u8 D_81900750[];
extern s32 D_81900838;
extern s32 D_8190083C;
extern f32 D_81900830;
extern s16 D_81900834;
extern s32 D_81900DE0;
extern s32 func_8004C990(s32, s32);
extern s32 D_81900DF8;
extern s32 func_80040E80(void *, void *);
extern s32 main_pool_get_available(void);
extern void *MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void func_80037E9C(void *, void *);
extern void func_8003F03C(s32, void *);
extern void func_8004C8C0(s32);
extern s32 func_87F08E3C(s32, s32);
void func_81900020(s32 arg0) {
    Fragment2State *st = &D_81900820;
    void *pool;
    s32 i;

    D_81900710 = 0x800;
    D_81900714 = 0.0f;
    D_81900DF8 = 0;
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    if (D_81900718 == 0) {
        D_8190083C = func_80040E80(pool, D_8190071C);
    } else {
        D_8190083C = func_80040E80(pool, D_81900750);
    }
    MainPool_FinalizeAllocation(pool);
    st->scale = 0.0f;
    st->unk_014 = 0;
    func_8004C8C0(0x1B1);
    D_81900838 = func_87F08E3C(func_8004C990(0x1B1, 0), 0x0F000000);
    func_80037E9C(NULL, (void *)&D_81900DE0);
    for (i = 0; i < 4; i++) {
        func_8003F03C((s32)&st->models[i], &D_81900DE0);
        st->active[i] = 0;
    }
}


extern s32 D_81900718;
void func_81900154(void) {
    D_81900718 = 1;
}

extern void func_8003F114(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_81900164(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    Fragment2Model *model;

    D_81900820.scale = arg3;
    D_81900820.active[arg4] = 1;
    D_81900820.unk_014 = 0;
    model = &D_81900820.models[arg4];
    func_8003F114(model, 0, -1, D_81900820.unk_01C);
    D_81900820.models[arg4].unk_038 = 0.0f;
    D_81900820.models[arg4].unk_034 = 0.0f;
    D_81900820.models[arg4].unk_030 = 0.0f;
    D_81900820.models[arg4].x = arg1;
    D_81900820.models[arg4].y = arg2;
    D_81900820.models[arg4].index = arg4;
}

extern f32 D_80087E50[];
// Each active model pulses: both scale fields get half the base scale plus a
// sine-table term (|sin| * half) indexed by the phase in unk_014.
void func_81900214(s32 arg0) {
    s16 phase;
    f32 halfA;
    s32 i;
    f32 v;
    f32 a;
    u16 idx;
    f32 two;
    s32 z = 0; // FAKE: zero index gives each state access its own lui
    s32 *active;

    two = 2.0f; // a variable, not a literal, keeps div.s (x / 2.0f becomes mul 0.5)
    active = D_81900820.active;
    for (i = 0; i < 4; i++) {
        idx = (u16)(phase = (&D_81900820)[z].unk_014); // FAKE: s16 middle step
        if (active[i] == 0) {
        } else {
            v = D_80087E50[idx >> 4];
            a = (v < 0.0f) ? -v : v;
            halfA = (&D_81900820)[z].scale / two;
            v = (&D_81900820)[z].scale / two;
            D_81900820.models[i].unk_030 = D_81900820.models[i].unk_034 = a * halfA + v;
        }
    }
    (&D_81900820)[z].unk_014 += D_81900710;
}

extern s32 D_81900DF8;
extern s16 D_81900710;
extern f32 D_81900714;
extern char D_81900800[];
extern char D_8190080C[];
extern char D_81900818[];
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800499EC(void);
// Draws three debug readouts while any of the four models is active. The
// readout whose index matches D_81900DF8 blinks: it is hidden for the first
// 10 of every 21 frames. sBlinkTimer lives at 0x81900DFC, past the fragment's
// loaded data (pinned in datamig_bss.ld).
void func_8190037C(s32 arg0) {
    s32 i;
    static s32 sBlinkTimer;
    s32 any = 0;

    for (i = 0; i < 4; i++) {
        if (D_81900820.active[i] == 1) {
            any = 1;
        }
    }
    if (any) {
        func_800498C4();
        sBlinkTimer++;
        if (sBlinkTimer > 20) {
            sBlinkTimer = 0;
        }
        func_800496A4(1, 0);
        func_8004972C(255, 255, 255, 255);
        if (D_81900DF8 != 0 || sBlinkTimer >= 10) {
            func_800495F8(100, 40, 1, D_81900800, D_81900710);
        }
        if (D_81900DF8 != 1 || sBlinkTimer >= 10) {
            func_800495F8(100, 50, 1, D_8190080C, D_81900820.scale);
        }
        if (D_81900DF8 != 2 || sBlinkTimer >= 10) {
            func_800495F8(100, 60, 1, D_81900818, D_81900714);
        }
        func_800499EC();
    }
}

/* mkdraft:func_81900500 begin */
// Partial view of the active scene object at D_8009491C: only the field this
// function reads is typed.
typedef struct Fragment2SceneObject {
    /* 0x00 */ u8 unk_00[0x14];
    /* 0x14 */ s32 colorIndex;
} Fragment2SceneObject;

// Row of D_81900784. Each channel is stored as its own word (the accesses are
// lw, not lbu) and gDPSetPrimColor/gDPSetEnvColor keep only its low 8 bits.
// The env color reuses primAlpha because the table has no separate env alpha.
typedef struct Fragment2Color {
    /* 0x00 */ s32 primRed;
    /* 0x04 */ s32 primGreen;
    /* 0x08 */ s32 primBlue;
    /* 0x0C */ s32 primAlpha;
    /* 0x10 */ s32 envRed;
    /* 0x14 */ s32 envGreen;
    /* 0x18 */ s32 envBlue;
} Fragment2Color;

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern Fragment2Color D_81900784[];
extern s32 D_81900838;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);



void func_81900500(s32 arg0, s32 arg1) {
    s32 pad; // FAKE: unused stack slot the retail frame reserves (score 16 without it)
    Fragment2SceneObject *sceneObject;
    s32 asset;

    if (arg0 == 5) {
        sceneObject = D_8009491C;
        asset = func_8004C990(0x1B1, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetPrimColor(D_800D0510++, 0, 0,
                        D_81900784[sceneObject->colorIndex].primRed,
                        D_81900784[sceneObject->colorIndex].primGreen,
                        D_81900784[sceneObject->colorIndex].primBlue,
                        D_81900784[sceneObject->colorIndex].primAlpha);
        gDPSetEnvColor(D_800D0510++,
                       D_81900784[sceneObject->colorIndex].envRed,
                       D_81900784[sceneObject->colorIndex].envGreen,
                       D_81900784[sceneObject->colorIndex].envBlue,
                       D_81900784[sceneObject->colorIndex].primAlpha);
        gDPSetCombine(D_800D0510++, 0x30B3FF, 0x5FFEFE38);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)asset));
        gSPDisplayList(D_800D0510++, D_81900838);
        func_8003CD84();
    }
}
/* mkdraft:func_81900500 end */

extern void func_8003F1DC(void *);
extern s16 D_81900834;
extern s32 D_81900840;
extern s32 D_81900DE0;
void func_819006A0(void *arg0)
{
    u8 *var_s0;
    u8 *var_s1;
    // FAKE: the one-line layout below is load-bearing. as1 breaks prologue
    // scheduling ties by .loc line number; splitting the two initializations
    // and the loop head onto separate lines swaps the lui/addiu order of the
    // s0/s1/s2 address materialization.
    var_s1 = (u8 *) &D_81900820; var_s0 = (u8 *) &D_81900840; do { func_8003F1DC(var_s0);
        var_s0 += 360;
        var_s1 += 4;
        *((s32 *) (var_s1 - 4)) = 0;
    }
    while (var_s0 != ((u8 *) &D_81900DE0));
    D_81900834 = 0;
}
#endif
