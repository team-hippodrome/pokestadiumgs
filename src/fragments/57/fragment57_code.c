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

// Fields of D_8330A2B0 that func_83303AB0 writes and func_83302AC8 prints. D_8330A344 (+0x94) and D_8330A368 (+0xB8) are
// three-float vectors inside this object; unk_98 and unk_C0 alias their second and third components.
typedef struct unk_D_8330A2B0 {
    /* 0x00 */ u8 unk_00[0xC];
    /* 0x0C */ s32 frame; // printed as "frame:%d"
    /* 0x10 */ s32 unk_10; // below 3, func_83302AC8 prints D_8330AC5C..D_8330ACD8 instead of cameraPos/cameraAt
    /* 0x14 */ u8 unk_14[0x5C - 0x14];
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
    /* 0xC4 */ f32 cameraPos[3]; // printed as "cam posx", "cam posy", "cam posz"
    /* 0xD0 */ f32 cameraAt[3]; // printed as "cam latx", "cam laty", "cam latz" (look-at point)
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83302290.s")

extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800497E4(s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void Font_DisableTwoCycleTexturing(void);
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

s32 func_8004989C(s32);
s32 func_8004C54C(s32, s32);
s32 func_8004C874(s32, s32);
s8 *func_8004C8A0(s32 *, s32, s32, s32);
s32 func_8330084C(s32 *);
void func_83302088(void *);
void func_83302180(void *);
extern s32 D_83308E38[];
extern s32 D_8330A2B8;
extern s32 D_8330AC08;
extern s32 D_8330AC10;
extern s32 D_8330AC14;
extern s32 D_8330AC20;
extern s32 D_8330AC24;
extern s32 D_8330AC28;
extern s32 D_8330AC2C;
extern s32 D_8330AC30;
extern const char D_833094D4[];
extern const char D_833094D8[];

// FAKE: the two format strings are named .rodata symbols rather than literals
// because COALESCE_AT_LUI translates each relocation it keeps by symbol name
// when it splices the folded body back into this object, and a literal
// relocates against the anonymous .rodata section symbol, which the fold
// refuses (score 574660). The definitions go through a macro only because
// matching_notes/try_candidate.py rejects a prologue line holding `=`.
#define TEXT_FORMAT_CONST(name, literal) const char name[] = literal
TEXT_FORMAT_CONST(D_833094D4, "%s");
TEXT_FORMAT_CONST(D_833094D8, "(%d)");

// FAKE: retail shares one `lui $at` between the two stores of -1 below
// (0x8330AC20 and 0x8330AC24 are in the same page), but IDO expands each store
// with its own `lui $at`; the object fold deletes the second (diff score 105
// without this pragma).
#pragma COALESCE_AT_LUI(func_83302D8C, D_8330AC20, D_8330AC24)


void func_83302D8C(void) {
    // FAKE: pointer alias; with the address inline the fold above refuses,
    // and without the fold direct access scores 2235.
    s32 *D_8330AC20_ptr = &D_8330AC20;
    s32 sp90;           // status-line y, live across func_8004989C
    // FAKE: unused slots; together they place sp2C at sp+0x2C (diff score 455
    // without stack_pad, 465 without both, 15 without sp2C_pad).
    s32 stack_pad[22];
    s16 sp2C_pad;
    // FAKE: pointer alias; direct access of D_8330AC08 scores 915 without
    // the fold.
    s32 *D_8330AC08_ptr = &D_8330AC08;
    s32 sp2C;
    s32 temp_a1;

    if (*(s32 *)((u8 *)D_8330AC08_ptr + 0x18) != 0) {
        if ((*D_8330AC20_ptr) == 1) {
            func_83302088(D_8330AC08_ptr);
            if (D_8330AC2C < D_8330AC28) {
                D_8330AC20_ptr[0] = -1;
                D_8330AC20_ptr[1] = -1;
            }
        }
        if ((*D_8330AC20_ptr) == -1) {
            func_83302180(D_8330AC08_ptr);
        }
        if ((*D_8330AC20_ptr) != 0) {
            func_8330084C(D_8330AC08_ptr);
        }
        func_800498C4();
        func_800496A4(2, 1);
        Font_EnableTwoCycleTexturing();
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        func_800497E4(0xFF, 0xFF, 0xFF, 0xC8);
        sp90 = D_8330AC14 + 0xE;
        func_8004989C(0xE);
        if (D_8330AC24 == 1) {
            if (D_8330AC30 == 1) {
                D_8330AC28 = D_8330AC28 + 1;
            }
            temp_a1 = D_83308E38[D_8330A2B8];
            switch (temp_a1) {
            case 11:
            case 14:
                func_8004C54C(0x19, func_8004C874(0, D_8330ABD8 - 1));
                func_8004C54C(0x41, func_8004C874(6, D_8330ABDC - 1));
                func_800495F8(D_8330AC10 + 0xE, sp90, 0, func_8004C8A0(&sp2C, 0x64, 0x49, D_83308E38[D_8330A2B8]));
                break;
            case 16:
                func_8004C54C(0x19, func_8004C874(0, D_8330ABD8 - 1));
                func_8004C54C(0x42, func_8004C874(6, D_8330ABE0 - 1));
                func_800495F8(D_8330AC10 + 0xE, sp90, 0, func_8004C8A0(&sp2C, 0x64, 0x49, D_83308E38[D_8330A2B8]));
                break;
            default:
                func_800495F8(D_8330AC10 + 0xE, sp90, 0, D_833094D4, func_8004C874(0x49, temp_a1));
                break;
            }
            if (D_833090AC == 1) {
                func_800495F8(*(s32 *)D_8330AC08_ptr, sp90 - 0x14, 1, D_833094D8, D_8330ABD8);
            }
        }
        Font_DisableTwoCycleTexturing();
        func_800499EC();
    }
}
/* mkdraft:func_83302D8C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_8330309C.s")

/* mkdraft:func_83303220 begin */
extern void *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094EC0[];
extern u8 D_80094F50[];
extern s32 D_833091F8;
extern s32 D_833091FC;
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
extern s32 D_8330AC38;
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/57/fragment57_code/func_83307088.s")

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
