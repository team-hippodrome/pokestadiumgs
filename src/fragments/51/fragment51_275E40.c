#include "global.h"


#ifdef VERSION_US
extern void StageFade_StartFromTransparent(s32);
extern void StageContext_SetClearColor(s32);
extern void *D_863075D8;
void func_86300020(s32 arg0) {
    (*(s32 *)((u8 *)(D_863075D8) + (0x8F58))) = arg0;
    (*(s32 *)((u8 *)(D_863075D8) + (0))) = 7;
    (*(s32 *)((u8 *)(D_863075D8) + (4))) = 8;
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(0xA);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86300074.s")
#endif

#ifdef VERSION_US
extern void func_87D00648(void *, void *, void *);
extern void func_87D0059C(void *, void *);
extern u8 D_863071F0[];
extern s32 D_863072B4;

typedef struct {
    char unk00[8];
    u8 unk08;
    u8 unk09;
    char unk0A[2];
} Unk_86307254;

extern Unk_86307254 D_86307254[];
void func_86300120(void) {
    Unk_86307254 *entry;
    s32 i;
    u8 *p1;
    u8 *p2;

    entry = D_86307254;
    i = 0;
    if (D_863072B4 > 0) {
        do {
            p1 = D_863071F0 + entry->unk08 * 8;
            p2 = D_863071F0 + entry->unk09 * 8;
            func_87D00648(entry, p1, p2);
            func_87D0059C(entry, (u8 *)entry + 4);
            i += 1;
            entry = (Unk_86307254 *)((u8 *)entry + 0xC);
        } while (i < D_863072B4);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863001BC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863003DC.s")
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_863003DC(void *);
void func_86300494(void) {
    s32 i;
    void *p;

    p = (u8 *)D_863075D8 + 0x149C;
    for (i = 0; i != 4; i += 1) {
        func_863003DC(p);
        p = (u8 *)p + 0x18C;
    }
}
#endif

void func_863004E8(void) {
}

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern u8 D_863070F0[];
void func_863004F0(s32 arg0, s32 arg1) {
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0x93, 0)));
        gDPSetEnvColor(D_800D0510++, 0x7F, 0x7F, 0x7F, 0xFF);
        gSPDisplayList(D_800D0510++, D_863070F0);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863005B8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863006F8.s")
#endif

#ifdef VERSION_US
u32 func_8003570C();
void func_863007B8(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0x38))) = (f32) ((((f32) func_8003570C() / 4294967296.0f) - 0.5f) * 0.5f);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86300818.s")
#endif

#ifdef VERSION_US
extern u32 func_8003570C();
extern void * D_87F119DC;
void func_86300C74(s32 *arg0) {
    struct LocalRange {
        u8 pad00[0x10];
        f32 lower;
        f32 upper;
        u8 pad18[0x18];
        f32 target;
    } *p;

    p = *(struct LocalRange **)((u8 *)D_87F119DC + 0x20);
    if (*(u32 *)((u8 *)D_87F119DC + 0xC) & 0x80000000) {
        p->target = (func_8003570C() / 4294967296.0f) * (p->upper - p->lower) + p->lower;
        *(u32 *)((u8 *)D_87F119DC + 0xC) &= 0x7FFFFFFF;
    } else {
        *arg0 = p->target - *(f32 *)((u8 *)D_87F119DC + 0x48);
        if (((*arg0 > 0.0f) ? *arg0 : -*arg0) < 5.0f) {
            if ((func_8003570C() % 101) < 5) {
                *(u32 *)((u8 *)D_87F119DC + 0xC) |= 0x80000000;
            }
        } else if (*arg0 > 0.0f) {
            *arg0 = 0x10;
        } else {
            *arg0 = -0x10;
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86300DD4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86300EF8.s")
#endif

#ifdef VERSION_US
extern void *D_87F119DC;
extern void MtxF_Copy(u32 *dest, u32 *src);
void func_86300FB4(void) {
    void *state = D_87F119DC;
    void *source = *(void **)((u8 *)state + 0x20);
    MtxF_Copy((u32 *)((u8 *)state + 0x84), (u32 *)((u8 *)source + 0x84));
}
#endif

#ifdef VERSION_US
extern void *func_87F025B8(void *, void (*)(void));
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern s32 func_8003F210(void *, s32);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
typedef struct { f32 x, y, z; } Fragment51ScaleVector;
void *Fragment51_CloneScaledActor(void *arg0) {
    u8 *node;
    node = func_87F025B8((u8 *)D_863075D8 + 0x770, func_86300FB4);
    if (node != NULL) {
        func_8003F1DC(node + 0x24);
        func_8003F210(node + 0x24, 2);
        ModelAnim_SetSpeed(node + 0x24, 0x20000);
        node[0x26] |= 0x10;
        *(void **)(node + 0x20) = arg0;
        MtxF_Copy((u32 *)(node + 0x84), (u32 *)((u8 *)arg0 + 0x84));
        *(Fragment51ScaleVector *)(node + 0x54) = *(Fragment51ScaleVector *)((u8 *)arg0 + 0x54);
        ((Fragment51ScaleVector *)(node + 0x54))->x *= 0.9f;
        ((Fragment51ScaleVector *)(node + 0x54))->y *= 0.9f;
    }
    return node;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863010A8.s")
#endif

#ifdef VERSION_US
extern s32 func_86300074(s32 *);
extern s32 ModelAnim_IsFinished();
extern void ModelAnim_SetAnimation();
extern void func_8003F3BC();
extern u8 D_86307334[];
extern u8 D_86307460[];
extern u8 D_86307462[];
typedef struct Func86301250ResourceGrid { u8 pad[0xE0]; void *resources[4][2]; } Func86301250ResourceGrid;
typedef struct Func86301250ResourceRow { void *slots[2]; } Func86301250ResourceRow;
typedef struct Func86301250ResourceRows { u8 pad[0xE0]; Func86301250ResourceRow rows[4]; } Func86301250ResourceRows;
extern void * D_863075D8;
extern void * D_87F119DC;
void func_86301250(void *arg0) {
    u8 *selection;
    s32 animation;
    s32 speed;
    s32 value;
    s32 padding0;
    s32 padding1;

    if ((*(s16 *)((u8 *)D_87F119DC + 0x64) == 0) ||
        ((*(s16 *)((u8 *)D_87F119DC + 0x64) == 1) && ModelAnim_IsFinished((void *)((u8 *)D_87F119DC + 0x24)))) {
        if ((func_86300074(&value) < 4) && (value == ((s32 (*)[19])D_86307334)[*(s32 *)arg0][0])) {
            selection = D_86307460;
            animation = 3;
            speed = 0x40;
        } else {
            selection = D_86307462;
            animation = 4;
            speed = 0x28;
        }
        func_8003F1DC((void *)((u8 *)D_87F119DC + 0x24));
        func_8003F114((void *)((u8 *)D_87F119DC + 0x24), 0, -1,
                     ((Func86301250ResourceGrid *)D_863075D8)->resources[*(s32 *)arg0][selection[0]]);
        ModelAnim_SetAnimation((void *)((u8 *)D_87F119DC + 0x24), selection[1]);
        func_8003F3BC((void *)((u8 *)D_87F119DC + 0x24), 0);
        *(s16 *)((u8 *)*(void **)((u8 *)D_87F119DC + 0x68) + 6) = speed;
        ModelAnim_SetAnimation((void *)((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x24), animation);
        *(s16 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x68) + 6) = speed;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863013C8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863018C4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86301B3C.s")
#endif

#ifdef VERSION_US
extern void func_86301B3C(s32);

void func_86301E14(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_86301B3C(var_s0);
        var_s0 += 1;
    } while (var_s0 != 4);
}
#endif

#ifdef VERSION_US
extern void func_87F02684(void *);
extern void func_8630470C(void);
extern void func_86300494(void);
extern void * D_863075D8;
void func_86301E54(void) {
    typedef struct {
        u8 pad[0x8F24];
        f32 angle;
        s32 one;
        s32 zero;
        s32 copy;
        u8 pad2[0x18];
        s32 source;
    } State;

    func_87F02684((u8 *)D_863075D8 + 0xDB4);
    func_87F02684((u8 *)D_863075D8 + 0x12C);
    func_87F02684((u8 *)D_863075D8 + 0x770);
    func_87F02684((u8 *)D_863075D8 + 0x8298);
    func_87F02684((u8 *)D_863075D8 + 0x1F84);
    ((State *)D_863075D8)->angle = 180.0f;
    func_86300494();
    ((State *)D_863075D8)->zero = 0;
    ((State *)D_863075D8)->one = 1;
    ((State *)D_863075D8)->copy = ((State *)D_863075D8)->source;
    func_8630470C();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86301F0C.s")
#endif

#ifdef VERSION_US
extern void func_87F0277C();
extern void * D_863075D8;
void func_86302404(void) {
    s32 i;

    for (i = 0; i != 3; i += 1) {
        func_87F0277C((u8 *)D_863075D8 + 0x12C);
        func_87F0277C((u8 *)D_863075D8 + 0xDB4);
        func_86305B44();
        func_87F0277C((u8 *)D_863075D8 + 0x8298);
        func_87F0277C((u8 *)D_863075D8 + 0x1F84);
    }
    func_87F0277C((u8 *)D_863075D8 + 0x770);
    func_87F0277C((u8 *)D_863075D8 + 0x1488);
}
#endif

#ifdef VERSION_US
typedef struct {
    u8 unk_0000[0x8F2C];
    s32 result_frame;
} Fragment51ResultFrameContext;

typedef struct {
    u8 unk_00[60];
    s32 score;
    u8 unk_40[12];
} Fragment51ResultRecord;
extern u8 D_863072F8[];
extern void func_87F0C930(void *);
extern void func_87F0A098(void *, void *, s32, s32, s32, s32, s32);
extern s32 func_87F0A3E8(void *);
void Fragment51_UpdateResults(void) {
    s32 top_score;
    ((Fragment51ResultFrameContext *)D_863075D8)->result_frame = ((Fragment51ResultFrameContext *)D_863075D8)->result_frame + 1;
    if (((Fragment51ResultFrameContext *)D_863075D8)->result_frame == 8) {
        if (func_86300074(&top_score) < 4) {
            if ((*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2180)) == 4) {
                func_87F0C930((u8 *)D_863075D8 + 0x38);
            } else {
                func_87F0A098((u8 *)D_863075D8 + 0x7C, *(void **)((u8 *)D_863075D8 + 12), 4,
                              top_score == ((Fragment51ResultRecord *)D_863072F8)[0].score,
                              top_score == ((Fragment51ResultRecord *)D_863072F8)[1].score,
                              top_score == ((Fragment51ResultRecord *)D_863072F8)[2].score,
                              top_score == ((Fragment51ResultRecord *)D_863072F8)[3].score);
            }
        } else {
            if ((*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2180)) == 4) {
                func_87F0C930((u8 *)D_863075D8 + 0x38);
            } else {
                func_87F0A098((u8 *)D_863075D8 + 0x7C, *(void **)((u8 *)D_863075D8 + 12), 4, 0, 0, 0, 0);
            }
        }
    }
    if (func_87F0A3E8((u8 *)D_863075D8 + 0x7C) != 0) {
        if ((*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2180)) == 1) {
            func_86300020(2);
        } else {
            *(s32 *)D_863075D8 = 6;
        }
    }
    func_86302404();
}
#endif

#ifdef VERSION_US
extern void func_87F06240(s32, s32, f32, f32, s32);
void func_86302634(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 x;
    s32 y;

    if (arg0 < 10) {
        x = arg1 + arg3;
        y = arg2 + arg4;
        func_87F06240(x, y, 0.57f, 0.57f, arg0 % 10);
    } else {
        x = arg1 + arg5;
        y = arg2 + arg6;
        func_87F06240(x, y, 0.57f, 0.57f, arg0 / 10);
        func_87F06240(x + 13, y, 0.57f, 0.57f, arg0 % 10);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_8630271C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86302F9C.s")
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_863048A8(void);
extern s32 func_87F08208(void *);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void Audio_PlayDefaultSound(s32);
extern void func_86300020(s32);
extern void func_800226C0(s32);
void func_86303110(void) {
    s32 temp_v0;

    func_863048A8();
    temp_v0 = func_87F08208((u8 *)D_863075D8 + 0x44);
    switch (temp_v0) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)D_863075D8 = 2;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        break;
    case 2:
        func_86300020(0);
        func_800226C0(3);
        break;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863031A4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_8630328C.s")
#endif

#ifdef VERSION_US
extern void func_86302404();
extern void func_863031A4();
extern void func_8630328C();
extern s32 D_863072E8;
s32 func_80001FF0(void);
void func_80028118(u8 arg0);
void func_8630352C(void) {
    if ((*(s32 *)((u8 *)(D_863075D8) + (0x8F30))) < ((func_80001FF0() >> 1) * 0x1E)) {
        func_80028118(6U);
    }
    func_863031A4();
    func_86302404();
    func_8630328C();
    if (D_863072E8 != 4) {
loop_3:
        goto loop_3;
    }
}
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_863048A8(void);
extern s32 StageContext_GetFadeMode(void);
extern void func_8630487C(void);
extern void func_86301E14(void);
extern void StageFade_StartFromOpaque(s32);
extern void func_87F00688(void);
void func_863035B0(void) {
    func_863048A8();
    if (StageContext_GetFadeMode() == 1) {
        func_8630487C();
        func_86301E14();
        StageFade_StartFromOpaque(0x14);
        *(s32 *)D_863075D8 = 3;
        func_87F00688();
    }
}
#endif

#ifdef VERSION_US
extern s32 func_87F01A40(void);
extern u32 func_87F006AC(void);
extern void func_80021ED8(s32);
extern void func_87F0277C();
extern void Audio_PlayDefaultSound(s32);
extern void func_86300020(s32 arg0);
void func_86303610(void) {
    s32 state;

    if (StageContext_GetFadeMode() == 0) {
        state = func_87F01A40();
    } else {
        state = 2;
    }
    switch (state) {
    case 0:
    case 2:
        if (func_87F006AC() == 1) {
            Audio_PlayDefaultSound(0x2F00);
        }
        if (func_87F006AC() == 2) {
            *(s32 *)D_863075D8 = 4;
            Audio_PlayDefaultSound(0x2F01);
            func_80021ED8(0x23);
        }
        break;
    case 3:
        func_86300020(0);
        break;
    case 4:
        func_86300020(1);
        break;
    }
    func_87F0277C((u8 *)D_863075D8 + 0x12C);
    func_87F0277C((u8 *)D_863075D8 + 0x770);
}
#endif

#ifdef VERSION_US
extern void func_87C037C0(void *, void *);
extern u32 func_87F00930(void);
extern void *func_87F006BC(void);
extern s32 func_87F02104(void);
extern void Fragment51_UpdateResults(void);
extern void func_87F0D5B8(void *);
extern s32 func_87F0C6F4(void *);
void Fragment51_UpdateState(void) {
    func_87C037C0((u8 *)D_863075D8 + 0x8F5C, *(void **)((u8 *)*(void **)((u8 *)D_863075D8 + 8) + 12));
    if (func_87F00930() == 0) {
        func_87F006BC();
    }
    switch ((*(s32 *)((u8 *)D_863075D8 + 0))) {
    case 0:
        (*(s32 *)((u8 *)D_863075D8 + 0x8F54)) = 1;
        if (StageContext_GetFadeMode() == 0) {
            (*(s32 *)((u8 *)D_863075D8 + 0)) = 1;
        }
        break;
    case 1:
        func_86303110();
        break;
    case 2:
        func_863035B0();
        break;
    case 3:
        (*(s32 *)((u8 *)D_863075D8 + 0x8F54)) = 0;
        func_86303610();
        break;
    case 4:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_8630352C();
            break;
        case 3:
            func_86300020(0);
            break;
        case 4:
            func_86300020(1);
            break;
        }
        break;
    case 5:
        Fragment51_UpdateResults();
        break;
    case 6:
        (*(s32 *)((u8 *)D_863075D8 + 0x8F54)) = 2;
        switch (func_87F02104()) {
        case 1:
            StageContext_SetClearColor(0);
            (*(s32 *)((u8 *)D_863075D8 + 0)) = 7;
            (*(s32 *)((u8 *)D_863075D8 + 4)) = 0;
            StageFade_StartFromTransparent(10);
            break;
        case 2:
            func_86300020(0);
            break;
        case 3:
            func_86300020(1);
            break;
        }
        break;
    case 7:
        if (StageContext_GetFadeMode() == 1) {
            (*(s32 *)((u8 *)D_863075D8 + 0)) = (*(s32 *)((u8 *)D_863075D8 + 4));
            if ((*(s32 *)((u8 *)D_863075D8 + 0)) == 0) {
                func_86301E54();
                StageFade_StartFromOpaque(10);
            }
        }
        break;
    }
    func_87F0D5B8((u8 *)D_863075D8 + 0x10);
    if (func_87F0C6F4((u8 *)D_863075D8 + 0x38) != 0) {
        (*(s32 *)((u8 *)D_863075D8 + 0x8F58)) = 3;
        (*(s32 *)((u8 *)D_863075D8 + 0)) = 8;
    }
}
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void Fragment51_UpdateState(void);
extern void func_86302F9C(void);
void func_86303974(void) {
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        Fragment51_UpdateState();
        func_86302F9C();
    } while (*(s32 *)D_863075D8 != 8);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863039DC.s")
#endif
