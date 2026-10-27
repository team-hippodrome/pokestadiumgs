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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_code/func_88C00AB0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_code/func_88C00CE4.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/41/fragment41_code/func_88C015DC.s")

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
