#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_885045B0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_88504828.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_88504EE8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_88505038.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_885055A0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_885057F4.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C1BC0/func_88505B58.s")

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
