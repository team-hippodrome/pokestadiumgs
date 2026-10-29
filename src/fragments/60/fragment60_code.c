#include "global.h"

// Five-entry ring queue for one player in D_86A443F0. ItemQueue_TryPush appends at head + count;
// func_86A0405C removes the entry at head, wraps head at five entries, and returns the value.
typedef struct unk_D_86A443F0_108 {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 head;
    /* 0x08 */ s32 values[5];
} unk_D_86A443F0_108; // size = 0x1C

// RGBA color. func_86A07334 copies whole colors and reads the channels; the u32 member gives the
// union 4-byte alignment, so a copy compiles to one lw/sw pair.
typedef union Fragment60Color {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
} Fragment60Color;

// Fragment60 minigame state. Most members are per-player arrays indexed by the player number
// (0-3). Spans that only unmatched code touches are left as byte arrays until their element
// types and strides are confirmed.
typedef struct unk_D_86A443F0 {
    /* 0x0000 */ s32 unk_0000; // func_86A06D04 compares it against multiples of D_86A0F8E4
    /* 0x0004 */ f32 position[4][2]; // ground-plane x, z; func_86A0B7F0 and func_86A0BA80 copy them to object x and z
    /* 0x0024 */ s32 unk_0024[4]; // func_86A06C3C sets 9 when func_86A0585C reports the player past the edge
    /* 0x0034 */ char unk_0034[0x10];
    /* 0x0044 */ f32 unk_0044[4][2]; // func_86A06BDC adds unk_0074 and unk_0094 when unk_0064 is set
    /* 0x0064 */ s32 unk_0064[4];
    /* 0x0074 */ f32 unk_0074[4][2];
    /* 0x0094 */ f32 unk_0094[4][2];
    /* 0x00B4 */ s32 unk_00B4[4]; // func_86A0B49C (asm) flags in unk_0178 the players holding the maximum
    /* 0x00C4 */ s32 unk_00C4[4]; // func_86A07334 draws each player's value in decimal digits
    /* 0x00D4 */ s32 unk_00D4; // while set, func_86A07334 draws the players flagged in unk_0178 in the blended color
    /* 0x00D8 */ f32 unk_00D8[4]; // func_86A0405C subtracts the popped D_86A0D560 entry's f32 at 0x8
    /* 0x00E8 */ s32 unk_00E8[4]; // func_86A0405C subtracts the popped D_86A0D560 entry's s32 at 0x4
    /* 0x00F8 */ s32 unk_00F8[4]; // ItemQueue_TryPush stores the last value it queued
    /* 0x0108 */ unk_D_86A443F0_108 queues[4];
    /* 0x0178 */ s32 unk_0178[4];
    /* 0x0188 */ s32 unk_0188[4]; // func_86A06C3C sets 40 together with unk_0024 = 9
    /* 0x0198 */ char unk_0198[0x14];
    /* 0x01AC */ s32 unk_01AC; // func_86A06D88 clears it
    /* 0x01B0 */ char unk_01B0[0xC98];
    /* 0x0E48 */ u8 unk_0E48[4][2]; // func_86A0B5CC passes the player's pair to func_8002781C
    /* 0x0E50 */ char unk_0E50[4];
    /* 0x0E54 */ Fragment60Color unk_0E54; // func_86A07334 blends from this color to unk_0E58
    /* 0x0E58 */ Fragment60Color unk_0E58; // both are refilled from D_86A464C0 every 10 frames
    /* 0x0E5C */ s32 unk_0E5C; // frame counter 0-59 that func_86A07334 advances
    /* 0x0E60 */ char unk_0E60[4];
    /* 0x0E64 */ s16 unk_0E64[4]; // func_86A06400 stores the heading from MathUtil_Atan2s
    /* 0x0E6C */ char unk_0E6C[8];
    /* 0x0E74 */ s16 unk_0E74[4]; // func_86A0638C stores the heading from MathUtil_Atan2s
    /* 0x0E7C */ char unk_0E7C[0x44];
    /* 0x0EC0 */ s32 unk_0EC0; // number of unk_16A8 entries CollisionBounds_ContainsPoint (asm) tests; func_86A06D88 clears it
    /* 0x0EC4 */ char unk_0EC4[0x7BC];
    /* 0x1680 */ s32 unk_1680; // func_86A06D88 clears it
    /* 0x1684 */ f32 unk_1684[4][2]; // func_86A0C7B4 passes the player's pair to func_86A0CF80
    /* 0x16A4 */ s32 unk_16A4;
    /* 0x16A8 */ f32 unk_16A8[5][2]; // x, z pairs; five entries reach D_86A45AC0, the next symbol
} unk_D_86A443F0; // size = 0x16D0

extern unk_D_86A443F0 D_86A443F0;


#ifdef VERSION_US
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
extern f32 D_86A0D4D8;
extern f32 D_86A0D4DC;
extern f32 D_86A0D4E0;
extern f32 D_86A0D4E4;
extern f32 D_86A0D4E8;
s32 func_86A00020(s32 arg0, void *camera) {
    u16 roll = 0;

    GeoCamera_SetPerspective(camera, D_86A0D4E8, 100.0f, 12800.0f);
    func_80038E14(camera, 0, (__sinf(D_86A0D4DC) * D_86A0D4D8) + 400.0f + D_86A0D4E0, (__cosf(D_86A0D4DC) * D_86A0D4D8) + D_86A0D4E4, 0.0f, D_86A0D4E0, D_86A0D4E4, roll);
    return 1;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86A000DC(s32 arg0, void *arg1) {
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
s32 func_86A00144(s32 arg0, void *arg1) {
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
typedef struct {
    s32 count;
    u8 unk_04[4];
    u8 *items;
} StagePoolResetState;
extern void func_87F02684(StagePoolResetState *);
extern void func_87F02328(void);
extern u8 D_86A45AD0[];
extern u8 D_86A45F20[];
extern unk_D_86A443F0 D_86A0D924;
extern s32 D_86A0F8E4;
extern u8 *D_86A46548;
extern u8 D_86A11190;
extern u8 D_86A1AAD0;
extern u8 D_86A2DD40;
extern u8 D_86A40FA0;
extern u8 D_86A104F0;
extern u8 D_86A0FEA0;
extern u8 D_86A10B38;
// Both allocators scan all 198 records and test active at offset 0x1C.
typedef struct {
    u8 unk_00[28];
    s32 active;
} StagePoolResetRecord;
extern StagePoolResetRecord D_86A41490[198];

// Clears stage pools, restores the complete default state, and applies context flags.
void StageState_ResetPoolsAndDefaults(void) {
    s32 *word;
    s32 i;

    for (word = (s32 *)D_86A45AD0; word < (s32 *)(D_86A45AD0 + 0x44C); word++) {
        *word = 0;
    }
    for (word = (s32 *)D_86A45F20; word < (s32 *)(D_86A45F20 + 0x550); word++) {
        *word = 0;
    }
    for (i = 0; i < 198; i++) {
        *(s32 *)((u8 *)D_86A41490 + i * 0x20 + 0x1C) = 0;
    }
    func_87F02684((StagePoolResetState *)&D_86A11190);
    func_87F02684((StagePoolResetState *)&D_86A1AAD0);
    func_87F02684((StagePoolResetState *)&D_86A2DD40);
    func_87F02684((StagePoolResetState *)&D_86A40FA0);
    func_87F02684((StagePoolResetState *)&D_86A104F0);
    func_87F02684((StagePoolResetState *)&D_86A0FEA0);
    func_87F02684((StagePoolResetState *)&D_86A10B38);
    D_86A443F0 = D_86A0D924;
    D_86A443F0.unk_0000 = D_86A0F8E4 * 60;
    switch ((*(s8 *)((*(u8 **)(D_86A46548 + 0xC)) + 0x2181))) {
        case 0:
            *(s32 *)D_86A443F0.unk_01B0 = 0;
            break;
        case 1:
            *(s32 *)D_86A443F0.unk_01B0 = 1;
            break;
        case 2:
            *(s32 *)D_86A443F0.unk_01B0 = 2;
            break;
        case 3:
            *(s32 *)D_86A443F0.unk_01B0 = 3;
            break;
    }
    if (((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 1) && ((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 2) &&
        ((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 4) && ((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 8)) {
        *(s32 *)(D_86A443F0.unk_01B0 + 4) = 1;
        *(s32 *)D_86A443F0.unk_01B0 = 1;
    } else {
        *(s32 *)(D_86A443F0.unk_01B0 + 4) = 0;
    }
    func_87F02328();
}
#endif

#ifdef VERSION_US
extern u8 D_86A43E50[];
extern u8 *D_86A46548;
extern s32 D_86A0D4D0;
extern s32 D_86A0D4D4;
extern u8 D_86A0F8E8[];
extern void ModelAnim_SetFrame(u8 *, s16);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void func_800226C0(s32);
extern void func_800279C4(u16);
extern s32 func_8003EC54(u8 *);
extern s32 func_8003F210(u8 *, s32);
extern void func_86A01480(s32);
extern s32 func_87F08208(u8 *);
void func_86A003A8(void) {
    u8 *model;

    // FAKE: same-line statement and loop head order the address setup; diff score 215 without it.
    model = D_86A43E50; do {
        func_8003F210(model, 11);
        if (func_8003EC54(model) > 0) {
            ModelAnim_SetFrame(model, 0);
            ModelAnim_SetSpeed(model, 98304); // 1.5 times the 0x10000 speed passed elsewhere
        }
        model += 360;
    } while (model != (u8 *)&D_86A443F0);
    D_86A0D4D4 = 0;
    switch (func_87F08208(D_86A0F8E8)) {
        case 1:
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(20);
            *(s32 *)D_86A46548 = 2;
            func_800225C4(40);
            func_800279C4(53003);
            D_86A0D4D0 = 0;
            break;
        case 2:
            func_86A01480(0);
            func_800226C0(3);
            D_86A0D4D0 = 1;
            break;
    }
}
#endif

void func_86A004AC(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A004B4.s")
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void func_800088DC(void);
extern void GfxImage_FillCurrent(Gfx **, u16);
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern s32 func_87F00930(void);
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C6B8(u8 *);
extern void func_86A095A0(void);
extern void func_87F07FE8(u8 *);
extern s32 D_86A444C4;
extern void func_86A07334(void);
extern void func_87F022F0(void);
extern void func_86A06E0C(void);
extern void func_87F0A5BC(u8 *);
extern void func_87F01D44(void);
extern void func_87F0C88C(u8 *);
extern void func_80008648(void);
extern u8 D_86A0F920[];
extern s32 D_86A0D4D0;
extern s32 D_86A0D4D4;
extern u8 D_86A0F8E8[];
extern u8 * D_86A46548;
void func_86A012D4(void) {
    func_800088DC();
    GfxImage_FillCurrent(&D_800D0510, 1);
    func_8000766C(&D_800D0510, 0, 0, 0x140, 0xF0);
    if (func_87F00930() == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    func_8003C6B8(*(u8 **)(D_86A46548 + 8));
    func_86A095A0();
    switch (*(u32 *)D_86A46548) {
    case 0:
    case 1:
    case 2:
        func_87F07FE8(D_86A0F8E8);
        break;
    case 8:
        if (D_86A0D4D0 != 0) {
            func_87F07FE8(D_86A0F8E8);
        }
        if (D_86A444C4 != 0) {
            func_86A07334();
        }
        if (D_86A0D4D4 != 0) {
            func_87F022F0();
        }
        break;
    case 4:
        func_86A06E0C();
        break;
    case 5:
        func_86A06E0C();
        func_86A07334();
        break;
    case 6:
        func_86A06E0C();
        func_86A07334();
        func_87F0A5BC(D_86A0F920);
        break;
    case 7:
        func_86A06E0C();
        func_86A07334();
        func_87F022F0();
        break;
    }
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
    func_87F0C88C(D_86A46548 + 0x1C);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern u8 *D_86A46548;
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
void func_86A01480(s32 arg0) {
    *(s32 *)(D_86A46548 + 0x18) = arg0;
    *(s32 *)D_86A46548 = 8;
    *(s32 *)(D_86A46548 + 4) = 9;
    StageContext_SetClearColor((u16)0xFFFF);
    StageFade_StartFromTransparent(0xA);
}
#endif

#ifdef VERSION_US
extern void func_80028118(u8);
extern void func_86A05DCC(void);
extern s32 D_86A4459C;
extern s32 D_86A44414;
extern s32 D_86A44418;
extern s32 D_86A4441C;
extern s32 D_86A44420;
extern s32 func_86A04100(void);
extern void func_86A06D04(void);
extern void func_86A06D88(void);
extern s32 D_86A0F8E4;

// Advance the countdown and wait for the terminal player states before leaving the stage.
void StageCountdown_UpdateAndCheckExit(void) {
    if (D_86A443F0.unk_0000 <= D_86A0F8E4 * 30) {
        func_80028118(8);
    }
    if (D_86A443F0.unk_0000 == D_86A0F8E4 * 3) {
        func_800279C4(0xCF00);
    }
    if (D_86A443F0.unk_0000 == D_86A0F8E4 * 2) {
        func_800279C4(0xCF00);
    }
    if (D_86A0F8E4 == D_86A443F0.unk_0000) {
        func_800279C4(0xCF00);
    }
    if (D_86A443F0.unk_0000 == 0) {
        func_800279C4(0xCF06);
    }
    if (D_86A443F0.unk_0000 > 0) {
        D_86A443F0.unk_0000--;
        func_86A05DCC();
        func_86A06D04();
        func_86A06D88();
    } else if (D_86A4459C || func_86A04100() ||
               D_86A44414 == 9 || D_86A44418 == 9 ||
               D_86A4441C == 9 || D_86A44420 == 9) {
        func_86A05DCC();
        func_86A06D88();
        if (D_86A443F0.unk_0000-- < -60) {
            *(s32 *)D_86A46548 = 5;
        }
    } else {
        *(s32 *)D_86A46548 = 5;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A0167C.s")
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_86A0167C(void);
extern void func_86A012D4(void);
extern u8 *D_86A46548;
void func_86A01C5C(void) {
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        func_86A0167C();
        func_86A012D4();
    } while (*(s32 *)D_86A46548 != 9);
}
#endif

#ifdef VERSION_US
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern u8 D_86A0F8E8[];
extern s32 D_86A0F8F0;
extern u8 D_86A0F920[];
extern s32 D_86A0F940;
extern u8 D_86A0F988[];
extern u8 D_86A46550[];

s32 func_86A01CC4(s32 arg0, s32 arg1) {
    void *stage;
    s32 pad; // FAKE: unused stack space; diff score 54 without it.
    s32 flags;

    main_pool_push_state(0x4B414D45);
    D_86A46548 = D_86A46550;
    *(s32 *)(D_86A46548 + 0xC) = arg1;
    if ((*(u8 **)(D_86A46548 + 0xC))[0x2180] == 4) {
        func_80027EE0(0xFFF);
    }
    Gfx_InitDisplayListBuffers(0x20000, 0);
    stage = func_800082E0(0, 0, 2, 1, 2, 1);
    func_8004C09C(303);
    func_87F06EAC(111, D_86A0F8E8, *(u8 **)(D_86A46548 + 0xC));
    func_87F09EBC(D_86A0F920, *(u8 **)(D_86A46548 + 0xC));
    func_87F0D48C(D_86A0F988, *(u8 **)(D_86A46548 + 0xC), 0);
    func_8004DDF4(103);
    func_8004DDF4(82);
    func_8004DDF4(92);
    func_8004DDF4(96);
    func_8004DDF4(175);
    func_8004DDF4(176);
    func_8004DDF4(181);
    func_8004DDF4(169);
    func_8004DDF4(180);
    func_8004DDF4(174);
    func_8004DDF4(184);
    func_8004DDF4(177);
    func_8004DDF4(170);
    func_8004DDF4(148);
    func_8004DDF4(147);
    //!bug: flags is never assigned; this ORs whatever the stack slot holds.
    func_80047588(D_86A0F8F0 | 0x2D | D_86A0F940 | flags, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_86A004B4();
    func_80008514(stage);
    func_86A01C5C();
    func_80008574();
    func_80006158();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4B414D45);
    func_87F0F480(*(u8 **)(D_86A46548 + 0xC));
    func_80027EE0(0xFFE);
    return *(s32 *)(D_86A46548 + 0x18);
}

#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A01EF0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A02A9C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A03234.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A036F4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A03B10.s")
#endif

#ifdef VERSION_US
extern void func_87F026E8(s32, void *);
extern s32 D_87F119D8;
extern void * D_87F119DC;
void func_86A03D0C(void) {
    s32 flag;

    flag = 0;
    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
    *(f32 *)((u8 *)D_87F119DC + 0x50) += *(f32 *)((u8 *)D_87F119DC + 0x18);
    *(f32 *)((u8 *)D_87F119DC + 0x14) -= 1.0;
    *((u8 *)D_87F119DC + 0x41) -= 7;
    if (*(f32 *)((u8 *)D_87F119DC + 0x4C) < -11.11111111111111) {
        flag = 1;
    }
    if (flag != 0) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_86A2DD40;
extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern s32 D_86A0FD08;
extern s32 D_86A0FD0C;
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern void func_86A03D0C(void);
void func_86A03DDC(f32 x, f32 z, f32 px, f32 pz, s32 kind) {
    u8 *node;
    u16 angle;
    u8 *anim;

    angle = guRandom() % 0xFFFF;
    node = func_87F025B8(&D_86A2DD40, func_86A03D0C);
    if (node != NULL) {
        *(f32 *)(node + 0x48) = x;
        *(f32 *)(node + 0x4C) = 1.0f;
        *(f32 *)(node + 0x50) = z;
        *(f32 *)(node + 0x10) = D_80088E50[angle >> 4] * 4.0f + px;
        *(f32 *)(node + 0x14) = 8.0f;
        *(f32 *)(node + 0x18) = D_80087E50[angle >> 4] * 4.0f + pz;
        node[0x41] = 0xFF;
        *(s32 *)(node + 0x1C) = 0;
        *(f32 *)(node + 0x54) = 0.11111111f;
        *(f32 *)(node + 0x58) = 0.11111111f;
        *(f32 *)(node + 0x5C) = 0.11111111f;
        anim = node + 0x24;
        func_8003F1DC(anim);
        switch (kind) {
        case 0:
            func_8003F114(anim, 0, -1, D_86A0FD08);
            break;
        case 1:
        case 2:
            func_8003F114(anim, 0, -1, D_86A0FD0C);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            func_8003F114(anim, 0, -1, D_86A0FD08);
            break;
        }
    }
}
#endif

#ifdef VERSION_US
// Each 24-byte entry supplies queue cost and collision dimensions.
// func_86A0405C subtracts cost and unk_08 when removing an item.
typedef struct {
    s32 unk_00;
    s32 cost;
    f32 unk_08;
    s32 unk_0C;
    f32 width;
    f32 height;
} Fragment60QueueEntry;
extern u8 D_86A0D560[];
extern void func_86A0BA80(s32);

// Appends an item when both the five-entry queue and its cost budget permit it.
s32 ItemQueue_TryPush(s32 player, s32 item) {
    s32 count;
    s32 head;
    s32 cost;
    Fragment60QueueEntry *entry;

    count = D_86A443F0.queues[player].count;
    head = D_86A443F0.queues[player].head;
    if (count == 5) {
        return 0;
    }

    entry = &((Fragment60QueueEntry *)D_86A0D560)[item];
    if (D_86A443F0.unk_00E8[player] + (cost = entry->cost) >= 6) {
        return 0;
    }
    D_86A443F0.queues[player].count++;
    if (head + count < 5) {
        head = head + count;
    } else {
        head = head + count - 5;
    }
    D_86A443F0.queues[player].values[head] = item;
    D_86A443F0.unk_00D8[player] = D_86A443F0.unk_00D8[player] + entry->unk_08;
    D_86A443F0.unk_00F8[player] = item;
    D_86A443F0.unk_00E8[player] = D_86A443F0.unk_00E8[player] + cost;
    if (D_86A443F0.unk_00E8[player] == 5) {
        func_86A0BA80(player);
    }
    return 1;
}
#endif

#ifdef VERSION_US
s32 func_86A0405C(s32 arg0) {
    s32 count;
    s32 index;
    s32 value;

    index = D_86A443F0.queues[arg0].head;
    count = D_86A443F0.queues[arg0].count;
    if (count == 0) {
        return -1;
    }
    D_86A443F0.queues[arg0].count = count - 1;
    value = D_86A443F0.queues[arg0].values[index++];
    if (index < 5) {
        D_86A443F0.queues[arg0].head = index;
    } else {
        D_86A443F0.queues[arg0].head = 0;
    }
    D_86A443F0.unk_00E8[arg0] -= *(s32 *)(D_86A0D560 + value * 0x18 + 4);
    D_86A443F0.unk_00D8[arg0] -= *(f32 *)(D_86A0D560 + value * 0x18 + 8);
    return value;
}
#endif

#ifdef VERSION_US
extern s32 D_86A4149C;
extern s32 D_86A414AC;
extern s32 D_86A414BC;
extern s32 D_86A414CC;
extern u8 D_86A414D0[];

s32 func_86A04100(void) {
    s32 count = 0;
    s32 i;
    s32 j;

    if (D_86A414AC != 0) {
        if (D_86A4149C != 0) {
            count++;
        }
    }
    if (D_86A414CC != 0) {
        if (D_86A414BC != 0) {
            count++;
        }
    }
    for (i = 0; i < 49; i++) {
        for (j = 0; j < 4; j++) {
            if (((*(s32 *)(D_86A414D0 + i * 0x80 + j * 0x20 + 0x1C)) != 0) &&
                ((*(s32 *)(D_86A414D0 + i * 0x80 + j * 0x20 + 0xC)) != 0)) {
                count++;
            }
        }
    }
    return count;
}

#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A041D8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A046A4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A04C04.s")
#endif

#ifdef VERSION_US
extern s32 D_86A0EFF4[];
typedef struct { f32 x; f32 y; } F60C7Pair;
// Returns the OR of the D_86A0EFF4 bits for each of the four D_86A443F0.position points
// that lies strictly inside the square of half-width D_86A0F62C around (arg0, arg1).
s32 func_86A05344(f32 arg0, f32 arg1) {
    s32 i;
    f32 x;
    f32 y;
    s32 result = 0;
    f32 half_size = 19.199999f;

    for (i = 0; i != 4; i++) {
        x = D_86A443F0.position[i][0];
        y = D_86A443F0.position[i][1];
        if (x < arg0 + half_size && arg0 - half_size < x && y < arg1 + half_size && arg1 - half_size < y) {
            result |= D_86A0EFF4[i];
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 D_86A452B0;

// Tests active centers using a square for modes 0-2 and wider bounds for mode 3.
s32 CollisionBounds_ContainsPoint(f32 point_x, f32 point_z) {
    s32 index;
    s8 mode;
    f32 x;
    f32 z;

    for (index = 0; index < D_86A452B0; index++) {
        x = D_86A443F0.unk_16A8[index][0];
        mode = (s8)(*(u8 **)(D_86A46548 + 0xC))[0x2181];
        z = D_86A443F0.unk_16A8[index][1];
        switch (mode) {
        case 0:
        case 1:
        case 2:
            if (point_x < x + 19.199999f && x - 19.199999f < point_x && point_z < z + 19.199999f && z - 19.199999f < point_z) {
                return 1;
            }
            break;
        case 3:
            if (point_x < x + 36.199997f && x - 36.199997f < point_x && point_z < z + 31.199999f && z - 31.199999f < point_z) {
                return 1;
            }
            break;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 PlayerBounds_ContainsPointExceptPlayer(s32 excluded_player, f32 point_x, f32 point_z) {
    s32 player;
    f32 half_size;
    f32 x;
    f32 z;

    for (player = 0; player < 4; player++) {
        if (player == excluded_player) {
            continue;
        }
        half_size = 31.19999886f;
        x = D_86A443F0.position[player][0];
        z = D_86A443F0.position[player][1];
        if (x - half_size < point_x && point_x < x + half_size &&
            z - half_size < point_z && point_z < z + half_size) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_86A0585C(f32 arg0, f32 arg1) {
    if (arg1 < -140.0f) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s16 MathUtil_Atan2s(f32, f32);
extern s32 D_86A444D8[4];
extern F60C7Pair D_86A0F2D4[6];
extern f32 D_86A0F2BC[6];
extern f32 D_80088E50[];
extern f32 D_80087E50[];

// Tests a point against the player's rotated item offset and squared radius.
s32 ItemBounds_ContainsRotatedOffset(s32 player, f32 point_x, f32 point_z) {
    s32 player_offset;
    f32 z;
    f32 x;
    s32 angle;
    f32 radius;
    f32 dx;
    f32 dz;

    player_offset = player * 4;
    angle = *(s32 *)((u8 *)D_86A444D8 + player_offset);
    x = D_86A0F2D4[angle].x;
    z = D_86A0F2D4[angle].y;
    angle = MathUtil_Atan2s(x, z);
    radius = sqrtf(x * x + z * z);
    angle = (angle + ((s16 *)D_86A443F0.unk_0E6C)[player]) & 0xFFFF;
    angle >>= 4;
    angle *= sizeof(f32);
    dx = -*(f32 *)((u8 *)D_80088E50 + angle) * radius;
    dz = *(f32 *)((u8 *)D_80087E50 + angle) * radius;
    dx = D_86A443F0.position[player][0] + dx - point_x;
    dz = D_86A443F0.position[player][1] + dz - point_z;
    if (dx * dx + dz * dz < *(f32 *)((u8 *)D_86A0F2BC + player_offset)) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern f32 D_86A45AC8;

// Tests the player's position against the item's bounds around (arg1, arg2).
// The upper vertical extent is zero; the lower extent spans the scaled height.
s32 ItemBounds_ContainsPlayerPosition(s32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    F60C7Pair upper_extent;
    f32 x;
    f32 z;
    f32 *position;
    Fragment60QueueEntry *entry;
    f32 margin;

    position = D_86A443F0.position[arg0];
    entry = &((Fragment60QueueEntry *)D_86A0D560)[arg3];
    x = position[0];
    z = position[1];
    margin = D_86A45AC8;
    upper_extent.x = entry->width * 8.333333f * 0.8f + margin;
    upper_extent.y = 0.0f;
    if (x < upper_extent.x + arg1 && arg1 - upper_extent.x < x &&
        z < upper_extent.y + margin + arg2 &&
        (f64)arg2 - (2.0 * (f64)(entry->height * 8.333333f) * (f64)0.8f + margin) < (f64)z) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s16 MathUtil_Atan2s(f32, f32);
s32 func_86A05AAC(s32 arg0, f32 arg1, f32 arg2) {
    f32 *pos;
    s16 angle;
    s16 current;
    f32 x;
    f32 z;

    pos = D_86A443F0.position[arg0];
    x = pos[0];
    z = pos[1];
    angle = (MathUtil_Atan2s(arg1 - x, -(arg2 - z)) + 0x3FFF) % 0xFFFF;
    current = D_86A443F0.unk_0E64[arg0];
    if ((current - angle >= 0x2000) || (angle - current < -0x1FFF)) {
        return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
// Active collision records have a 20-byte stride and select a queue-entry footprint.
typedef struct {
    f32 x;
    f32 z;
    s32 unk_08;
    s32 unk_0C;
    s32 item;
} Fragment60CollisionEntry;
extern s32 D_86A45A70;
extern f32 D_86A45ACC;

// Sums item costs for active footprints containing (point_x, point_z).
s32 ItemBounds_SumCostsAtPoint(f32 point_x, f32 point_z) {
    s32 index;
    s32 total = 0;
    s32 item;
    f32 x;
    f32 z;
    Fragment60QueueEntry *entry;
    f32 upper_z_extent;

    for (index = 0; index < D_86A45A70; index++) {
        x = ((Fragment60CollisionEntry *)D_86A443F0.unk_0EC4)[index].x;
        z = ((Fragment60CollisionEntry *)D_86A443F0.unk_0EC4)[index].z;
        item = ((Fragment60CollisionEntry *)D_86A443F0.unk_0EC4)[index].item;
        entry = &((Fragment60QueueEntry *)D_86A0D560)[item];
        upper_z_extent = 0.0f;
        if (point_x < (entry->width * 8.333333f * 0.8f + D_86A45ACC) + x && x - (entry->width * 8.333333f * 0.8f + D_86A45ACC) < point_x &&
            point_z < upper_z_extent + D_86A45ACC + z &&
            (f64)z - (2.0 * (f64)(entry->height * 8.333333f) * (f64)0.8f + D_86A45ACC) < (f64)point_z) {
            total += entry->cost;
        }
    }
    return total;
}
#endif

#ifdef VERSION_US
// Returns 1 when (point_x, point_z) lies inside any active item footprint.
// The upper edge has zero extent; the lower edge spans the scaled item height.
s32 ItemBounds_AnyContainsPoint(f32 point_x, f32 point_z) {
    s32 index;
    s32 item;
    f32 x;
    f32 z;
    Fragment60QueueEntry *entry;
    f32 upper_z_extent;

    for (index = 0; index < D_86A45A70; index++) {
        x = ((Fragment60CollisionEntry *)D_86A443F0.unk_0EC4)[index].x;
        z = ((Fragment60CollisionEntry *)D_86A443F0.unk_0EC4)[index].z;
        item = ((Fragment60CollisionEntry *)D_86A443F0.unk_0EC4)[index].item;
        entry = &((Fragment60QueueEntry *)D_86A0D560)[item];
        upper_z_extent = 0.0f;
        if (point_x < (entry->width * 8.333333f * 0.8f + D_86A45ACC) + x && x - (entry->width * 8.333333f * 0.8f + D_86A45ACC) < point_x &&
            point_z < upper_z_extent + D_86A45ACC + z &&
            (f64)z - (2.0 * (f64)(entry->height * 8.333333f) * (f64)0.8f + D_86A45ACC) < (f64)point_z) {
            return 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A05DCC.s")
#endif

#ifdef VERSION_US
extern s16 MathUtil_Atan2s(f32, f32);
void func_86A0638C(s32 arg0, f32 arg1, f32 arg2) {
    if ((arg1 != 0.0f) || (arg2 != 0.0f)) {
        D_86A443F0.unk_0E74[arg0] = (s16)((MathUtil_Atan2s(arg1, -arg2) + 0x3FFF) % 0xFFFF);
    }
}
#endif

#ifdef VERSION_US
extern s16 MathUtil_Atan2s(f32, f32);
void func_86A06400(s32 arg0, f32 arg1, f32 arg2) {
    if ((arg1 != 0.0f) || (arg2 != 0.0f)) {
        D_86A443F0.unk_0E64[arg0] = (s16)((MathUtil_Atan2s(arg1, -arg2) + 0x3FFF) % 0xFFFF);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A06474.s")
#endif

#ifdef VERSION_US
extern s32 func_86A066F4(s16 arg0, s16 arg1);
s32 func_86A06650(s16 arg0, s16 arg1, s16 arg2) {
    s16 pad;
    s16 distance;
    s16 plus;
    s16 minus;
    s32 secondDistance;

    if (arg2 < func_86A066F4(arg0, arg1)) {
        plus = arg1 + arg2;
        distance = func_86A066F4(arg0, plus);
        minus = arg1 - arg2;
        secondDistance = func_86A066F4(arg0, minus);
        if (distance < secondDistance) {
            return plus;
        } else {
            return minus;
        }
    }
    return arg0;
}
#endif

#ifdef VERSION_US
s32 func_86A066F4(s16 arg0, s16 arg1) {
    s32 diff;
    if (arg0 >= arg1) {
        diff = arg0 - arg1;
    } else {
        diff = arg1 - arg0;
    }
    if (diff >= 0x8000) {
        diff = 0xFFFF - diff;
    }
    return (s16)diff;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A06740.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A06A1C.s")
#endif

#ifdef VERSION_US
void func_86A06BDC(s32 arg0) {
    if (D_86A443F0.unk_0064[arg0]) {
        D_86A443F0.unk_0044[arg0][0] += D_86A443F0.unk_0074[arg0][0] + D_86A443F0.unk_0094[arg0][0];
        D_86A443F0.unk_0044[arg0][1] += D_86A443F0.unk_0074[arg0][1] + D_86A443F0.unk_0094[arg0][1];
        D_86A443F0.unk_0064[arg0] = 0;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_86A0585C(f32 arg0, f32 arg1);
void func_86A06C3C(void) {
    s32 i;
    s32 x;
    s32 y;

    for (i = 0; i < 4; i++) {
        x = D_86A443F0.position[i][0];
        y = D_86A443F0.position[i][1];
        if (func_86A0585C((f32)x, (f32)y) != 0) {
            if ((D_86A443F0.unk_0024[i] != 9) && (D_86A443F0.unk_00E8[i] != 0)) {
                D_86A443F0.unk_0024[i] = 9;
                D_86A443F0.unk_0188[i] = 40;
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_86A0F8E4;
extern void func_86A03234();
extern void func_86A046A4();
void func_86A06D04(void) {
    if (D_86A0F8E4 * 3 < D_86A443F0.unk_0000) {
        func_86A03234();
    }
    if ((D_86A0F8E4 * 3 < D_86A443F0.unk_0000) && (D_86A443F0.unk_0000 < D_86A0F8E4 * 59)) {
        func_86A046A4();
    }
}
#endif

#ifdef VERSION_US
extern void func_87F0277C(s32 *);
extern u8 D_86A0FEA0;
extern u8 D_86A104F0;
extern u8 D_86A10B38;
extern u8 D_86A11190;
extern u8 D_86A1AAD0;
extern u8 D_86A2DD40;
extern u8 D_86A40FA0;
void func_86A06D88(void) {
    D_86A443F0.unk_0EC0 = 0;
    D_86A443F0.unk_1680 = 0;
    func_87F0277C(&D_86A11190);
    D_86A443F0.unk_01AC = 0;
    func_87F0277C(&D_86A1AAD0);
    func_87F0277C(&D_86A2DD40);
    func_87F0277C(&D_86A40FA0);
    func_87F0277C(&D_86A104F0);
    func_87F0277C(&D_86A0FEA0);
    func_87F0277C(&D_86A10B38);
}
#endif

void func_86A06E0C(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A06E14.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A07124.s")
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094E78[];
extern Gfx D_80094F50[];
extern u8 *D_86A46470[4];
extern u8 *D_86A46480[4];
extern u8 *D_86A46490[10];
extern u8 *D_86A464B8;
extern Fragment60Color D_86A464C0[6];
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

// Texture width (u16 at 0) or height (u16 at 2) times scale, rounded half away from zero; the
// textures are the ones func_8004D1FC loads before each GfxRect_DrawTextured call.
#define TEX_SCALED_WIDTH(tex, scale) \
    ((f32)(u32)((u16 *)(tex))[0] * (scale) + (((f32)(u32)((u16 *)(tex))[0] * (scale) > 0.0f) ? 0.5f : -0.5f))
#define TEX_SCALED_HEIGHT(tex, scale) \
    ((f32)(u32)((u16 *)(tex))[1] * (scale) + (((f32)(u32)((u16 *)(tex))[1] * (scale) > 0.0f) ? 0.5f : -0.5f))

// Draws screen rectangles with GfxRect_DrawTextured:
// - four icons at x 98, one per bit 0-3 of byte 0x2182 of the record at D_86A46548 + 0xC:
//   D_86A46470[n] while the bit is set (or byte 0x2180 is 4), D_86A46480[n] otherwise;
// - for each player, D_86A443F0.unk_00C4[player] in decimal digits (D_86A46490, drawn right to
//   left from x 182) and the texture D_86A464B8 after them. A player flagged in unk_0178 is drawn
//   in a color that blends from unk_0E54 to unk_0E58 while unk_00D4 is set; otherwise each player
//   has fixed primitive and environment colors.
void func_86A07334(void) {
    s32 value;
    s32 digit_index;
    f32 digit_scale;
    f32 current_weight;
    f32 next_weight;

    digit_scale = 0.57f;
    gSPDisplayList(D_800D0510++, D_80094E38);

    if ((*(u8 **)(D_86A46548 + 0xC))[0x2180] == 4 || ((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 1)) {
        func_8004D1FC(D_86A46470[0]);
        GfxRect_DrawTextured(98, 114, TEX_SCALED_WIDTH(D_86A46470[0], 0.8f), TEX_SCALED_HEIGHT(D_86A46470[0], 0.8f),
                             0, 0, 1280, 1280, 0);
    } else {
        func_8004D1FC(D_86A46480[0]);
        GfxRect_DrawTextured(98, 114, TEX_SCALED_WIDTH(D_86A46480[0], 0.8f), TEX_SCALED_HEIGHT(D_86A46480[0], 0.8f),
                             0, 0, 1280, 1280, 0);
    }
    if ((*(u8 **)(D_86A46548 + 0xC))[0x2180] == 4 || ((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 2)) {
        func_8004D1FC(D_86A46470[1]);
        GfxRect_DrawTextured(98, 137, TEX_SCALED_WIDTH(D_86A46470[1], 0.8f), TEX_SCALED_HEIGHT(D_86A46470[1], 0.8f),
                             0, 0, 1280, 1280, 0);
    } else {
        func_8004D1FC(D_86A46480[1]);
        GfxRect_DrawTextured(98, 137, TEX_SCALED_WIDTH(D_86A46480[1], 0.8f), TEX_SCALED_HEIGHT(D_86A46480[1], 0.8f),
                             0, 0, 1280, 1280, 0);
    }
    if ((*(u8 **)(D_86A46548 + 0xC))[0x2180] == 4 || ((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 4)) {
        func_8004D1FC(D_86A46470[2]);
        GfxRect_DrawTextured(98, 160, TEX_SCALED_WIDTH(D_86A46470[2], 0.8f), TEX_SCALED_HEIGHT(D_86A46470[2], 0.8f),
                             0, 0, 1280, 1280, 0);
    } else {
        func_8004D1FC(D_86A46480[2]);
        GfxRect_DrawTextured(98, 160, TEX_SCALED_WIDTH(D_86A46480[2], 0.8f), TEX_SCALED_HEIGHT(D_86A46480[2], 0.8f),
                             0, 0, 1280, 1280, 0);
    }
    if ((*(u8 **)(D_86A46548 + 0xC))[0x2180] == 4 || ((*(u8 **)(D_86A46548 + 0xC))[0x2182] & 8)) {
        func_8004D1FC(D_86A46470[3]);
        GfxRect_DrawTextured(98, 183, TEX_SCALED_WIDTH(D_86A46470[3], 0.8f), TEX_SCALED_HEIGHT(D_86A46470[3], 0.8f),
                             0, 0, 1280, 1280, 0);
    } else {
        func_8004D1FC(D_86A46480[3]);
        GfxRect_DrawTextured(98, 183, TEX_SCALED_WIDTH(D_86A46480[3], 0.8f), TEX_SCALED_HEIGHT(D_86A46480[3], 0.8f),
                             0, 0, 1280, 1280, 0);
    }

    gSPDisplayList(D_800D0510++, D_80094F50);
    gSPDisplayList(D_800D0510++, D_80094E78);

    // Every 10 frames of the 60-frame cycle, the blend moves one step through the six D_86A464C0 colors.
    if (D_86A443F0.unk_0E5C == 0) {
        D_86A443F0.unk_0E54 = D_86A464C0[0];
        D_86A443F0.unk_0E58 = D_86A464C0[1];
    }
    // FAKE: the reversed operands give the target's bne register order.
    if (10 == D_86A443F0.unk_0E5C) {
        D_86A443F0.unk_0E54 = D_86A464C0[1];
        D_86A443F0.unk_0E58 = D_86A464C0[2];
    }
    if (D_86A443F0.unk_0E5C == 20) {
        D_86A443F0.unk_0E54 = D_86A464C0[2];
        D_86A443F0.unk_0E58 = D_86A464C0[3];
    }
    if (D_86A443F0.unk_0E5C == 30) {
        D_86A443F0.unk_0E54 = D_86A464C0[3];
        D_86A443F0.unk_0E58 = D_86A464C0[4];
    }
    if (D_86A443F0.unk_0E5C == 40) {
        D_86A443F0.unk_0E54 = D_86A464C0[4];
        D_86A443F0.unk_0E58 = D_86A464C0[5];
    }
    if (D_86A443F0.unk_0E5C == 50) {
        D_86A443F0.unk_0E54 = D_86A464C0[5];
        D_86A443F0.unk_0E58 = D_86A464C0[0];
    }
    next_weight = (f32)(D_86A443F0.unk_0E5C % 10) / 10.0f;
    current_weight = 1.0f - next_weight;
    D_86A443F0.unk_0E5C++;
    if (D_86A443F0.unk_0E5C >= 60) {
        D_86A443F0.unk_0E5C = 0;
    }

    if (D_86A443F0.unk_00D4 != 0 && D_86A443F0.unk_0178[0] != 0) {
        gDPSetPrimColor(D_800D0510++, 0, 0,
                        D_86A443F0.unk_0E54.r * current_weight + D_86A443F0.unk_0E58.r * next_weight,
                        D_86A443F0.unk_0E54.g * current_weight + D_86A443F0.unk_0E58.g * next_weight,
                        D_86A443F0.unk_0E54.b * current_weight + D_86A443F0.unk_0E58.b * next_weight, 255);
        gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    } else {
        gDPSetPrimColor(D_800D0510++, 0, 0, 0, 0, 155, 255);
        gDPSetEnvColor(D_800D0510++, 170, 245, 255, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    }
    digit_index = 0;
    value = D_86A443F0.unk_00C4[0];
    do {
        func_8004D1FC(D_86A46490[value % 10]);
        GfxRect_DrawTextured(182 - digit_index * 13, 116, TEX_SCALED_WIDTH(D_86A46490[value % 10], digit_scale),
                             TEX_SCALED_HEIGHT(D_86A46490[value % 10], digit_scale), 0, 0, 1796, 1796, 0);
        digit_index++;
        value /= 10;
    } while (value != 0);
    func_8004D1FC(D_86A464B8);
    GfxRect_DrawTextured(198, 120, TEX_SCALED_WIDTH(D_86A464B8, 0.8f), TEX_SCALED_HEIGHT(D_86A464B8, 0.8f), 0, 0,
                         1280, 1280, 0);

    if (D_86A443F0.unk_00D4 != 0 && D_86A443F0.unk_0178[1] != 0) {
        gDPSetPrimColor(D_800D0510++, 0, 0,
                        D_86A443F0.unk_0E54.r * current_weight + D_86A443F0.unk_0E58.r * next_weight,
                        D_86A443F0.unk_0E54.g * current_weight + D_86A443F0.unk_0E58.g * next_weight,
                        D_86A443F0.unk_0E54.b * current_weight + D_86A443F0.unk_0E58.b * next_weight, 255);
        gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    } else {
        gDPSetPrimColor(D_800D0510++, 0, 0, 0, 100, 0, 255);
        gDPSetEnvColor(D_800D0510++, 200, 255, 155, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    }
    digit_index = 0;
    value = D_86A443F0.unk_00C4[1];
    do {
        func_8004D1FC(D_86A46490[value % 10]);
        GfxRect_DrawTextured(182 - digit_index * 13, 139, TEX_SCALED_WIDTH(D_86A46490[value % 10], digit_scale),
                             TEX_SCALED_HEIGHT(D_86A46490[value % 10], digit_scale), 0, 0, 1796, 1796, 0);
        digit_index++;
        value /= 10;
    } while (value != 0);
    func_8004D1FC(D_86A464B8);
    GfxRect_DrawTextured(198, 143, TEX_SCALED_WIDTH(D_86A464B8, 0.8f), TEX_SCALED_HEIGHT(D_86A464B8, 0.8f), 0, 0,
                         1280, 1280, 0);

    if (D_86A443F0.unk_00D4 != 0 && D_86A443F0.unk_0178[2] != 0) {
        gDPSetPrimColor(D_800D0510++, 0, 0,
                        D_86A443F0.unk_0E54.r * current_weight + D_86A443F0.unk_0E58.r * next_weight,
                        D_86A443F0.unk_0E54.g * current_weight + D_86A443F0.unk_0E58.g * next_weight,
                        D_86A443F0.unk_0E54.b * current_weight + D_86A443F0.unk_0E58.b * next_weight, 255);
        gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    } else {
        gDPSetPrimColor(D_800D0510++, 0, 0, 120, 0, 0, 255);
        gDPSetEnvColor(D_800D0510++, 255, 160, 190, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    }
    digit_index = 0;
    value = D_86A443F0.unk_00C4[2];
    do {
        func_8004D1FC(D_86A46490[value % 10]);
        GfxRect_DrawTextured(182 - digit_index * 13, 162, TEX_SCALED_WIDTH(D_86A46490[value % 10], digit_scale),
                             TEX_SCALED_HEIGHT(D_86A46490[value % 10], digit_scale), 0, 0, 1796, 1796, 0);
        digit_index++;
        value /= 10;
    } while (value != 0);
    func_8004D1FC(D_86A464B8);
    GfxRect_DrawTextured(198, 166, TEX_SCALED_WIDTH(D_86A464B8, 0.8f), TEX_SCALED_HEIGHT(D_86A464B8, 0.8f), 0, 0,
                         1280, 1280, 0);

    if (D_86A443F0.unk_00D4 != 0 && D_86A443F0.unk_0178[3] != 0) {
        gDPSetPrimColor(D_800D0510++, 0, 0,
                        D_86A443F0.unk_0E54.r * current_weight + D_86A443F0.unk_0E58.r * next_weight,
                        D_86A443F0.unk_0E54.g * current_weight + D_86A443F0.unk_0E58.g * next_weight,
                        D_86A443F0.unk_0E54.b * current_weight + D_86A443F0.unk_0E58.b * next_weight, 255);
        gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    } else {
        gDPSetPrimColor(D_800D0510++, 0, 0, 210, 90, 0, 255);
        gDPSetEnvColor(D_800D0510++, 255, 255, 140, 255);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
    }
    digit_index = 0;
    value = D_86A443F0.unk_00C4[3];
    do {
        func_8004D1FC(D_86A46490[value % 10]);
        GfxRect_DrawTextured(182 - digit_index * 13, 185, TEX_SCALED_WIDTH(D_86A46490[value % 10], digit_scale),
                             TEX_SCALED_HEIGHT(D_86A46490[value % 10], digit_scale), 0, 0, 1796, 1796, 0);
        digit_index++;
        value /= 10;
    } while (value != 0);
    func_8004D1FC(D_86A464B8);
    GfxRect_DrawTextured(198, 189, TEX_SCALED_WIDTH(D_86A464B8, 0.8f), TEX_SCALED_HEIGHT(D_86A464B8, 0.8f), 0, 0,
                         1280, 1280, 0);

    gSPDisplayList(D_800D0510++, D_80094F50);
}

#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A095A0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A0B49C.s")
#endif

#ifdef VERSION_US
extern s32 func_86A0405C(s32);
extern void func_86A03B10();
extern void func_8002781C(s32, s32, void *);
void func_86A0B5CC(s32 arg0) {
    if (D_86A443F0.unk_0188[arg0] == 8 || D_86A443F0.unk_0188[arg0] == 15 || D_86A443F0.unk_0188[arg0] == 22 || D_86A443F0.unk_0188[arg0] == 29 || D_86A443F0.unk_0188[arg0] == 36) {
        s32 result;
        result = func_86A0405C(arg0);
        if (result != -1) {
            func_86A03B10(arg0, result);
            func_8002781C(0x8F0B, arg0 & 0xFF, D_86A443F0.unk_0E48[arg0]);
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_87F026E8(s32, void *);
extern s32 D_87F119D8;
extern void *D_87F119DC;
void func_86A0B66C(void) {
    f32 temp_fv0;
    s32 var_v0;

    var_v0 = 0;
    (*(f32 *)((u8 *)(D_87F119DC) + (0x48))) = (f32) ((*(f32 *)((u8 *)(D_87F119DC) + (0x10))) + (*(f32 *)((u8 *)(D_87F119DC) + (0x48))));
    temp_fv0 = (*(f32 *)((u8 *)(D_87F119DC) + (0x48)));
    if ((temp_fv0 < -270.0f) || (temp_fv0 > 270.0f)) {
        var_v0 = 1;
    }
    if (var_v0 != 0) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern void func_86A0B66C(void);
extern void * func_87F025B8(void *, void *);
extern s32 D_86A104E8;
extern u8 D_86A104F0;
void func_86A0B6F8(f32 arg0, f32 arg1, f32 arg2) {
    u8 *temp_v0;

    temp_v0 = func_87F025B8(&D_86A104F0, func_86A0B66C);
    if (temp_v0 != NULL) {
        *(f32 *)(temp_v0 + 0x48) = arg0;
        *(f32 *)(temp_v0 + 0x4C) = 1.0f;
        *(f32 *)(temp_v0 + 0x50) = arg1;
        *(f32 *)(temp_v0 + 0x10) = arg2;
        *(s16 *)(temp_v0 + 0x42) = -0x4001;
        *(f32 *)(temp_v0 + 0x54) = 2.5f;
        *(f32 *)(temp_v0 + 0x5C) = 2.5f;
        *(f32 *)(temp_v0 + 0x58) = 1.5f;
        func_8003F1DC(temp_v0 + 0x24);
        func_8003F114(temp_v0 + 0x24, 0, -1, D_86A104E8);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_86A42D70;
extern void *D_87F119DC;
void func_86A0B7A0(void)
{
  s32 new_var;
  void *temp_a0;
  new_var = *((s32 *) (((u8 *) D_87F119DC) + 0x20));
  temp_a0 = (new_var * 0x168) + (&D_86A42D70);
  *((f32 *) (((u8 *) D_87F119DC) + 0x48)) = (f32) (*((f32 *) (((u8 *) temp_a0) + 0x24)));
  *((f32 *) (((u8 *) D_87F119DC) + 0x50)) = (f32) (*((f32 *) (((u8 *) temp_a0) + 0x2C)));
}
#endif

#ifdef VERSION_US
extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern s32 D_86A104E8;
extern void func_86A0B7A0(void);
extern u8 D_86A0FEA0;
void func_86A0B7F0(s32 arg0) {
    u8 *temp_v0;

    temp_v0 = func_87F025B8(&D_86A0FEA0, func_86A0B7A0);
    if (temp_v0 != NULL) {
        *(f32 *)(temp_v0 + 0x48) = D_86A443F0.position[arg0][0];
        *(f32 *)(temp_v0 + 0x4C) = 1.0f;
        *(f32 *)(temp_v0 + 0x50) = D_86A443F0.position[arg0][1];
        *(s16 *)(temp_v0 + 0x42) = -0x4001;
        *(s32 *)(temp_v0 + 0x38) = arg0;
        *(s32 *)(temp_v0 + 0x20) = arg0;
        *(f32 *)(temp_v0 + 0x54) = 2.5f;
        *(f32 *)(temp_v0 + 0x58) = 2.5f;
        *(f32 *)(temp_v0 + 0x5C) = 2.5f;
        func_8003F1DC(temp_v0 + 0x24);
        func_8003F114(temp_v0 + 0x24, 0, -1, D_86A104E8);
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern s32 D_86A104EC;
void func_86A0B8A4(s32 arg0, s32 arg1) {
    s32 pad[2];
    s32 temp_v0;

    if (arg0 == 5) {
        temp_v0 = func_8004C990(0x133, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 0, 0, 0, 0x80);
        gDPSetCombine(D_800D0510++, 0xFCFFD3FF, 0xFFFEFE38);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)temp_v0));
        gSPDisplayList(D_800D0510++, D_86A104EC);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
void func_86A0B98C(void) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    s32 temp_v1;
    s32 var_a0;

    var_a0 = 0;
    *(f32 *)((u8 *)D_87F119DC + 0x48) =
        D_86A443F0.position[*(s32 *)((u8 *)D_87F119DC + 0x20)][0];
    *(f32 *)((u8 *)D_87F119DC + 0x50) =
        D_86A443F0.position[*(s32 *)((u8 *)D_87F119DC + 0x20)][1];
    temp_v1 = *(s32 *)((u8 *)D_87F119DC + 0x1C);
    if (temp_v1 < 0x14) {
        temp_fv0 = (f32)temp_v1 * 0.05f;
        *(f32 *)((u8 *)D_87F119DC + 0x5C) = temp_fv0;
        *(f32 *)((u8 *)D_87F119DC + 0x58) = temp_fv0;
        *(f32 *)((u8 *)D_87F119DC + 0x54) = temp_fv0;
    } else {
        *(f32 *)((u8 *)D_87F119DC + 0x5C) = 1.0f;
        temp_fv0_2 = *(f32 *)((u8 *)D_87F119DC + 0x5C);
        *(f32 *)((u8 *)D_87F119DC + 0x58) = temp_fv0_2;
        *(f32 *)((u8 *)D_87F119DC + 0x54) = temp_fv0_2;
    }
    if (D_86A443F0.unk_00E8[*(s32 *)((u8 *)D_87F119DC + 0x20)] != 5) {
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
extern s32 D_86A11180;
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern void func_86A0B98C(void);
extern void * func_87F025B8(void *, void *);
extern u8 D_86A10B38;
void func_86A0BA80(s32 arg0) {
    u8 *obj;
    f32 *pos;

    obj = func_87F025B8(&D_86A10B38, func_86A0B98C);
    if (obj != NULL) {
        pos = D_86A443F0.position[arg0];
        *(f32 *)(obj + 0x48) = pos[0];
        *(f32 *)(obj + 0x4C) = 82.0f;
        *(f32 *)(obj + 0x50) = pos[1];
        *(s32 *)(obj + 0x1C) = 0;
        *(s32 *)(obj + 0x38) = arg0;
        *(s32 *)(obj + 0x20) = arg0;
        *(f32 *)(obj + 0x54) = 0.0f;
        *(f32 *)(obj + 0x58) = 0.0f;
        *(f32 *)(obj + 0x5C) = 0.0f;
        func_8003F1DC(obj + 0x24);
        func_8003F114(obj + 0x24, 0, -1, D_86A11180);
        obj[0x26] |= 8;
    }
}
#endif

#ifdef VERSION_US
extern void *D_8009491C;
extern u32 D_86A11184;
extern u8 *D_86A11188;
void func_86A0BB40(s32 arg0, s32 arg1) {
    void *context;
    s32 temp_v0;

    if (arg0 == 5) {
        context = D_8009491C;
        temp_v0 = *(s32 *)((u8 *)context + 0x14);
        switch (temp_v0) {
        case 0:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetEnvColor(D_800D0510++, 0, 0, 0x9B, 0xFF);
            break;
        case 1:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetEnvColor(D_800D0510++, 0, 0x82, 0, 0xFF);
            break;
        case 2:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetEnvColor(D_800D0510++, 0x9B, 0, 0, 0xFF);
            break;
        case 3:
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetEnvColor(D_800D0510++, 0xC3, 0x64, 0, 0xFF);
            break;
        }
        gDPSetCombine(D_800D0510++, 0x30B3FF, 0x5FFEFE38);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60(D_86A11188));
        gSPDisplayList(D_800D0510++, D_86A11184);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A0BD34.s")
#endif

#ifdef VERSION_US
extern f32 func_86A0CF80(f32 *, f32 *, s32);
extern s32 func_86A0C9B4(s32, s32);
extern void func_86A0CED8(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3);
extern u8 D_800CE060[];
extern u8 D_86A0F004[];
void func_86A0C7B4(s32 arg0) {
    F60C7Pair value;
    f32 delta;
    f32 *position;

    if (func_86A0CF80(&D_86A443F0.unk_1684[arg0][0], &D_86A443F0.unk_1684[arg0][1], arg0) > 0.0f) {
        position = D_86A443F0.position[arg0];
        delta = D_86A443F0.unk_1684[arg0][0] - position[0];
        *(f32 *)(D_86A0F004 + 0xD8) = delta;
        *(f32 *)(D_86A0F004 + 0x90) = delta;
        delta = D_86A443F0.unk_1684[arg0][1] - position[1];
        *(f32 *)(D_86A0F004 + 0xDC) = delta;
        *(f32 *)(D_86A0F004 + 0x94) = delta;
        if (position[0] > 0.0f) {
            value = ((F60C7Pair *)D_86A0F004)[func_86A0C9B4(arg0, 0) + 18];
        } else {
            value = ((F60C7Pair *)D_86A0F004)[func_86A0C9B4(arg0, 0) + 27];
        }
        func_86A0CED8((f32 *)(D_800CE060 + arg0 * 0x28 + 0x18), (f32 *)(D_800CE060 + arg0 * 0x28 + 0x1C), value.x, value.y);
    }
}
#endif

#ifdef VERSION_US
typedef struct {
    f32 unk0;
    f32 unk4;
} Pair;
typedef struct {
    s32 pad;
    Pair pair;
} Local;
extern u8 D_86A0F004[];
extern u8 D_800CE060[];
extern s32 func_86A0C9B4(s32, s32);
extern void func_86A0CED8(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3);
void func_86A0C8DC(s32 arg0) {
    Local local;
    s32 temp_v0;
    if (D_86A443F0.position[arg0][0] > 0.0f) {
        temp_v0 = func_86A0C9B4(arg0, 1);
        local.pair = *(Pair *)((u8 *)D_86A0F004 + (temp_v0 << 3));
    } else {
        temp_v0 = func_86A0C9B4(arg0, 1);
        local.pair = *(Pair *)((u8 *)D_86A0F004 + (temp_v0 << 3) + 0x48);
    }
    func_86A0CED8(
        (f32 *)((u8 *)D_800CE060 + (arg0 * 0x28) + 0x18),
        (f32 *)((u8 *)D_800CE060 + (arg0 * 0x28) + 0x1C),
        local.pair.unk0,
        local.pair.unk4
    );
}
#endif

#ifdef VERSION_US
void func_86A0C9AC(u8 *arg0) {}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A0C9B4.s")
#endif

#ifdef VERSION_US
void func_86A0CED8(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3) {
    f32 var_fv1;
    f64 temp_fv0;

    if ((arg2 == 0.0f) && (arg3 == 0.0f)) {
        *arg0 = 0.0f;
        *arg1 = 0.0f;
        return;
    }
    var_fv1 = sqrtf((arg2 * arg2) + (arg3 * arg3));
    if (var_fv1 < 0.01f) {
        var_fv1 = 0.01f;
    }
    temp_fv0 = (f64) var_fv1;
    *arg0 = (f32) (((f64) arg2 * 64.0) / temp_fv0);
    *arg1 = (f32) -(((f64) arg3 * 64.0) / temp_fv0);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/60/fragment60_code/func_86A0CF80.s")
#endif
