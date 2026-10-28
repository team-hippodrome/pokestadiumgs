#include "global.h"
#include "controller.h"
#include "color_adjustment.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83300020.s")

s32 func_83300398(s32 arg0, s32 arg1) {
    return arg0 + arg1 / 2;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_833003B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_833005F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_8330084C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83300CB0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_833015C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_8330173C.s")

// Fields of D_8330A2B0 that func_83303AB0 writes. D_8330A344 (+0x94) and D_8330A368 (+0xB8) are
// three-float vectors inside this object; unk_98 and unk_C0 alias their second and third components.
typedef struct unk_D_8330A2B0 {
    /* 0x00 */ u8 unk_00[0x5C];
    /* 0x5C */ f32 unk_5C;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ f32 unk_74;
    /* 0x78 */ f32 unk_78;
    /* 0x7C */ u8 unk_7C[0x98 - 0x7C];
    /* 0x98 */ f32 unk_98;
    /* 0x9C */ u8 unk_9C[0xC0 - 0x9C];
    /* 0xC0 */ f32 unk_C0;
} unk_D_8330A2B0;

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_833019CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83301C60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83302088.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83302180.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83302290.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83302AC8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83302D8C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_8330309C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83303220.s")

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



#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83305C1C.s")

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
M2C_UNK func_833003B0(M2C_UNK);                     /* extern */
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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83306D0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83307088.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_833078C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83307AAC.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83307C7C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_833084B0.s")

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
extern s32 D_8330AC68;

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
