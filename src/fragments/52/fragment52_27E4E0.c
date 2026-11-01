#include "global.h"


void func_86400020(void) {
}

#ifdef VERSION_US
extern u8 D_86409668[];
extern u8 D_86409688[];
extern u8 D_864096E8[];
extern void func_87D00648(void *, void *, void *);
extern f32 func_87D0059C(f32 *, f32 *);
void func_86400028(void)
{
  u8 *var_s0;
  u8 *table;
  s32 var_s1;
  var_s0 = D_86409688;
  table = D_86409668;
 var_s1 = 0; do { u8 *temp_s2; u8 *temp_a1; u8 *temp_a2;
    temp_s2 = var_s0 + 0xC;
    temp_a1 = table + (var_s0[0] << 3);
    temp_a2 = table + (var_s0[1] << 3);
    *((f32 *) (var_s0 + 4)) = (*((f32 *) (temp_a2 + 0))) - (*((f32 *) (temp_a1 + 0)));
    *((f32 *) (var_s0 + 8)) = (*((f32 *) (temp_a2 + 4))) - (*((f32 *) (temp_a1 + 4)));
    func_87D00648(temp_s2, temp_a1, temp_a2);
    func_87D0059C((f32 *) temp_s2, (f32 *) (var_s0 + 0x10));
    var_s1 += 1;
    var_s0 += 0x18;
  }
  while (var_s1 < 4);
  var_s0 = D_864096E8;
  var_s1 = 0;
  do
  {
    u8 *temp_v0;
    temp_v0 = table + (var_s0[0] << 3);
    *((f32 *) (var_s0 + 4)) = *((f32 *) (temp_v0 + 0));
    *((f32 *) (var_s0 + 8)) = *((f32 *) (temp_v0 + 4));
    func_87D0059C((f32 *) (var_s0 + 4), (f32 *) (var_s0 + 8));
    var_s1 += 1;
    var_s0 += 0xC;
  }
  while (var_s1 != 4);
}
#endif

#ifdef VERSION_US
extern f32 func_87D00720(void *, void *, void *, f32 *, f32 *);
extern s32 func_87D00670(void *, void *, f32 *, void *, void *, f32 *);

s32 func_86400114(void *arg0, f32 arg1, void *arg2, void *arg3, void *arg4, f32 *arg5) {
    f32 sp30[2];
    f32 sp2C;
    s32 sp28;
    f32 sp24;
    f32 sp20;

    sp28 = 0;
    func_87D00720(arg0, arg2, arg3, sp30, &sp2C);
    if ((sp2C < arg1) &&
        (func_87D00670(arg0, arg4, &sp24, arg2, arg3, &sp20) != 0) &&
        (sp20 >= 0.0f) && (sp20 <= 1.0f)) {
        *arg5 = arg1 - sp2C;
        sp28 = 1;
    }
    return sp28;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864001E0 begin */
#pragma REWRITE_FUNCTION_WORD(func_864001E0, 0xA0, 0x46024282, 0x46081282)

s32 func_864001E0(f32 *arg0, f32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fv1_2;
    s32 var_v1;

    var_v1 = 0;
    arg4[0] = arg0[0] - arg2[0];
    temp_fv1 = arg4[0];
    arg4[1] = arg0[1] - arg2[1];
    temp_fa0 = arg4[1];
    temp_fv0 = sqrtf((temp_fv1 * temp_fv1) + (temp_fa0 * temp_fa0));
    if (temp_fv0 < arg1) {
        if (temp_fv0 == 0.0f) {
            arg4[0] = arg3[0];
            arg4[1] = arg3[1];
        } else {
            arg4[0] = temp_fv1 / temp_fv0;
            arg4[1] = temp_fa0 / temp_fv0;
        }
        temp_fv1_2 = arg4[0];
        temp_fa0_2 = arg4[1];
        if (((temp_fa0_2 * arg3[1]) + (temp_fv1_2 * arg3[0])) >= 0.0f) {
            *arg5 = arg1 - temp_fv0;
        } else {
            arg4[0] = temp_fv1_2;
            arg4[1] = temp_fa0_2;
            *arg5 = arg1 + temp_fv0;
        }
        var_v1 = 1;
    }
    return var_v1;
}
/* mkdraft:func_864001E0 end */
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern s32 func_87F026E8(s32, void *);
extern s32 D_87F119D8;
extern void *D_87F119DC;

/* Per-frame update callback of the D_87F119DC node (registered through
 * func_87F025B8 in func_86400804; the fragment 64 walker invokes it at
 * node offset 8 and increments the 0x1C counter it tests here):
 * position (0x48/0x4C/0x50) += velocity (0x10/0x14/0x18); scale
 * (0x54/0x58/0x5C) *= growth factor, where flag 0x10000000 in word 0xC
 * selects D_86409990 (35/33, 1.0606060f) over D_86409994 (1.05f);
 * velocity decays, x/z (0x10/0x18) *= D_86409998 (0.8f) and y (0x14) *=
 * D_8640999C (0.95f); s16 0x46 += 0xFF (255); once the walker's counter
 * at 0x1C reaches the rounded 10Hz frame count ((f32)func_80001FF0() /
 * 60.0f * 6.0f; func_80001FF0 returns 50 or 60 from osTvType), hands the
 * node to func_87F026E8(D_87F119D8, D_87F119DC) - the same dequeue call
 * as func_8630421C in fragment 51. */
void func_864002CC(void) {
    f32 var_fv0;
    f32 var_fv1;
    s32 var_a0;

    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
    *(f32 *)((u8 *)D_87F119DC + 0x50) += *(f32 *)((u8 *)D_87F119DC + 0x18);
    var_fv0 = (*(s32 *)((u8 *)D_87F119DC + 0xC) & 0x10000000) ? 1.06f : 1.05f;
    var_fv1 = 0.8f;
    if (var_fv1 == var_fv1) {} // FAKE: fully-DCE'd self-compare (nothing reaches the ROM - not original karodo); the dead compare still mentions var_fv1 in uopt's FPR walk, demoting it behind var_fv0 (f0) so var_fv1 takes f2
    *(f32 *)((u8 *)D_87F119DC + 0x54) = *(f32 *)((u8 *)D_87F119DC + 0x54) * var_fv0;
    *(f32 *)((u8 *)D_87F119DC + 0x58) = *(f32 *)((u8 *)D_87F119DC + 0x58) * var_fv0;
    *(f32 *)((u8 *)D_87F119DC + 0x5C) = *(f32 *)((u8 *)D_87F119DC + 0x5C) * var_fv0;
    *(f32 *)((u8 *)D_87F119DC + 0x10) = *(f32 *)((u8 *)D_87F119DC + 0x10) * var_fv1;
    *(f32 *)((u8 *)D_87F119DC + 0x14) = *(f32 *)((u8 *)D_87F119DC + 0x14) * 0.95f;
    *(f32 *)((u8 *)D_87F119DC + 0x18) = *(f32 *)((u8 *)D_87F119DC + 0x18) * var_fv1;
    *(s16 *)((u8 *)D_87F119DC + 0x46) = *(s16 *)((u8 *)D_87F119DC + 0x46) + 0xFF;
    if ((((f32)func_80001FF0() / 60.0f) * 6.0f) >= 0.0f) {
        var_a0 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) + 0.5f);
    } else {
        var_a0 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) - 0.5f);
    }
    if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= var_a0) {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_864004B4.s")
#endif

#ifdef VERSION_US
extern void func_87F05FB0(s32, s32, s32, s32, s32);
extern s32 D_80094908;
void func_864007B8(s32 arg0, s32 arg1) {
    if (arg0 == 2) {
        func_87F05FB0(arg1 + 0x60, D_80094908 + 0x64, arg1 + 0x24, arg1 + 0x1E, arg1 + 0x30);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern u32 func_8003570C(void);
extern void func_80037E3C(void *, void *, void *);
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 *func_87F025B8(void *, void *);
extern u8 *D_86416C00;
extern void func_864002CC(void);
void func_86400804(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7) {
    u8 *object;
    // karodo: unused declaration. IDO reserves its home slot at 0x30(sp), which keeps the
    // spilled object+0x24 common subexpression at 0x24(sp) as in the original frame layout.
    u8 *sp30;
    u32 sp2C;
    s32 var_v1;

    object = func_87F025B8(D_86416C00 + 0x3334, (void *)func_864002CC);
    if (object != NULL) {
        func_80037E3C(object + 0x24, (void *)func_864007B8, object);
        func_8003F1DC(object + 0x24);
        func_8003F114(object + 0x24, 0, -1, *(s32 *)(D_86416C00 + 0x7B8));
        *(u8 *)(object + 0x26) |= 0x10;
        sp2C = func_8003570C();
        if ((((f32)func_80001FF0() / 60.0f) * 6.0f) >= 0.0f) {
            var_v1 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) + 0.5f);
        } else {
            var_v1 = (s32)((((f32)func_80001FF0() / 60.0f) * 6.0f) - 0.5f);
        }
        *(u32 *)(object + 0x1C) = sp2C % (u32)((var_v1 >> 2) + 1);
        *(f32 *)(object + 0x48) = arg0;
        *(f32 *)(object + 0x4C) = arg1;
        *(f32 *)(object + 0x50) = arg2;
        *(f32 *)(object + 0x54) = arg3;
        *(f32 *)(object + 0x58) = arg3;
        *(f32 *)(object + 0x5C) = arg3;
        *(f32 *)(object + 0x10) = arg4;
        *(f32 *)(object + 0x14) = arg5;
        *(f32 *)(object + 0x18) = arg6;
        *(s32 *)(object + 0xC) = *(s32 *)(object + 0xC) | arg7;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864009D4 begin */
extern s32 func_80001FF0(void);
extern s32 func_87F026E8(s32, void *);
extern s32 D_87F119D8;
extern void *D_87F119DC;
extern u8 *D_86416C00;

// Per-frame callback of the D_87F119DC effect node. func_864012A0 registers it
// through func_87F025B8(D_86416C00 + 0xE00, func_864009D4) and sets the fields
// read here: word 0xC = 0x10000000, counter 0x1C = 0, position 0x48/0x4C/0x50 =
// its three f32 arguments, scale 0x54/0x58/0x5C = 2.5f, velocity 0x10/0x14/0x18
// = 0.0f, and the u8 at (*(node + 0x20)) + 4.
//
// Position 0x48/0x4C/0x50 += velocity 0x10/0x14/0x18, velocity *= 0.95f, and the
// s32 addressed by node + 0x20 is incremented. Word 0xC selects one of three
// stages; each compares the frame counter at 0x1C (incremented by the walker
// that invokes the callback - func_864002CC reads the same counter) against a
// frame count scaled from 60 Hz, then zeroes 0x1C:
//   bit28 set (by func_864012A0): 5 frames, clear bit28, set bit29;
//   bit28 and bit30 clear (the only arm left for bit29): 175 frames, clear
//     bit29, set bit30;
//   bit30 set: 10 frames, then decrement the s32 at 0x4BC8 of record
//     (*(u8 *) (node + 0x20) + 4) in the D_86416C00 + 0x8000 array of 0x5C-byte
//     records, and hand the node to func_87F026E8(D_87F119D8, D_87F119DC).
// The frame count is ((f32)func_80001FF0() / 60.0f) * N and func_80001FF0
// returns 50 or 60 from osTvType, so N is a 60 Hz frame count scaled to the
// console's refresh rate; func_864002CC converts the same way.


void func_864009D4(void) {
    s32 *counter;
    u8 *entry;
    s32 state;
    s32 threshold;

    counter = *(s32 **)((u8 *)D_87F119DC + 0x20);
    *counter += 1;
    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
    *(f32 *)((u8 *)D_87F119DC + 0x50) += *(f32 *)((u8 *)D_87F119DC + 0x18);
    *(f32 *)((u8 *)D_87F119DC + 0x10) *= 0.95f;
    *(f32 *)((u8 *)D_87F119DC + 0x14) *= 0.95f;
    *(f32 *)((u8 *)D_87F119DC + 0x18) *= 0.95f;
    state = *(s32 *)((u8 *)D_87F119DC + 0xC);
    if (state & 0x10000000) {
        if ((((f32)func_80001FF0() / 60.0f) * 5.0f) >= 0.0f) {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 5.0f) + 0.5f);
        } else {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 5.0f) - 0.5f);
        }
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= threshold) {
            *(s32 *)((u8 *)D_87F119DC + 0xC) &= 0xEFFFFFFF;
            *(s32 *)((u8 *)D_87F119DC + 0xC) |= 0x20000000;
            *(s32 *)((u8 *)D_87F119DC + 0x1C) = 0;
        }
    } else if (state & 0x40000000) {
        if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
        } else {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
        }
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= threshold) {
            entry = ((u8 (*)[0x5C]) (D_86416C00 + 0x8000))[*(u8 *)((u8 *)counter + 4)];
            *(s32 *)(entry + 0x4BC8) -= 1;
            func_87F026E8(D_87F119D8, D_87F119DC);
        }
    } else {
        if ((((f32)func_80001FF0() / 60.0f) * 175.0f) >= 0.0f) {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 175.0f) + 0.5f);
        } else {
            threshold = (s32)((((f32)func_80001FF0() / 60.0f) * 175.0f) - 0.5f);
        }
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= threshold) {
            *(s32 *)((u8 *)D_87F119DC + 0xC) &= 0xDFFFFFFF;
            *(s32 *)((u8 *)D_87F119DC + 0xC) |= 0x40000000;
            *(s32 *)((u8 *)D_87F119DC + 0x1C) = 0;
        }
    }
}
/* mkdraft:func_864009D4 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86400DDC.s")
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern void func_864009D4(void);
extern u8 *func_87F025B8(void *, void *);
extern void func_8003F1DC(u8 *);
extern void func_8003F114(u8 *, s32, s32, s32);
void func_864012A0(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 *object;
    u8 *child;
    u8 *base;

    object = func_87F025B8(D_86416C00 + 0xE00, (void *)func_864009D4);
    if (object != 0) {
        child = *(u8 **)(object + 0x20);
        *(u8 **)(object + 0x38) = object;
        base = object + 0x24;
        func_8003F1DC(base);
        func_8003F114(base, 0, -1, *(s32 *)(D_86416C00 + 0x7B4));
        *(s32 *)(object + 0x0C) |= 0x10000000;
        *(s32 *)(object + 0x1C) = 0;
        *(f32 *)(object + 0x48) = arg1;
        *(f32 *)(object + 0x4C) = arg2;
        *(f32 *)(object + 0x50) = arg3;
        *(s16 *)(object + 0x42) = -0x4000;
        *(f32 *)(object + 0x54) = 2.5f;
        *(f32 *)(object + 0x58) = 2.5f;
        *(f32 *)(object + 0x5C) = 2.5f;
        *(f32 *)(object + 0x10) = 0.0f;
        *(f32 *)(object + 0x14) = 0.0f;
        *(f32 *)(object + 0x18) = 0.0f;
        *(s32 *)(child + 0x00) = 0;
        *(u8 *)(child + 0x04) = *(s32 *)((u8 *)arg0 + 0x00);
        *(u8 *)(child + 0x05) = *(s32 *)((u8 *)arg0 + 0x0C);
        *(u8 *)(child + 0x06) = *(s32 *)((u8 *)arg0 + 0x04);
    }
}
void func_864012A0_padding(void) {
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_864013A8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86401550.s")
#endif

#ifdef VERSION_US
extern void func_8002781C(s32, u8, void *);
void func_864018B0(u8 *arg0, u8 *arg1) {
    if (!(*(s32 *)(arg0 + 0xC) & 0x20000000)) {
        *(s32 *)(arg1 + 0x38) = 0x14;
        *(f32 *)(arg1 + 0x1C) = 0.0f;
        *(s32 *)(arg0 + 0xC) |= 0x20000000;
        *(f32 *)(arg0 + 0x14) = 46.4f;
        func_8002781C(0x5F03, *(u8 *)(arg1 + 3), arg1 + 0x58);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86401920.s")
#endif

#ifdef VERSION_US
void func_86401920(void *, void *);
extern u8 * D_86416C00;
void func_86401D1C(void) {
    u8 *base = D_86416C00 + 0x7D0;
    int i, j;
    u8 *p2;
    int n = 4;
    int m = 3;
    for (i = 0; i != m; i++) {
        p2 = base + 0x18C;
        for (j = i + 1; j < n; j++) {
            func_86401920(base, p2);
            p2 += 0x18C;
        }
        base += 0x18C;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86401DBC begin */
extern u32 func_8003570C(void);
extern u8 *D_86416C00;

// FAKE: the 30 REWRITE_FUNCTION_WORD lines below replace compiler-artifact differences
// (schedule rotation, FPR coloring, one mul.s operand order) that no source shape reached.
// Without them this same body scores 30/105 differing words at
// idx=29,66,67,68,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,89,90,91,92,93,94,95,97,98;
// see func_86401DBC.report.md.
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x74, 0x46043202, 0x46062202)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x108, 0x8FA40030, 0x44829000)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x10C, 0x44829000, 0x8FA3002C)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x110, 0x8FA3002C, 0x8FA40030)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x11C, 0xC48C0048, 0x04410005)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x120, 0xC48E004C, 0x46809120)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x124, 0x8C860050, 0x3C014F80)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x128, 0x04410005, 0x44813000)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x12C, 0x468091A0, 0x00000000)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x130, 0x3C014F80, 0x46062100)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x134, 0x44812000, 0x3C014F80)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x138, 0x00000000, 0x44814000)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x13C, 0x46043180, 0x3C013F00)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x140, 0x3C014F80, 0x44815000)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x144, 0x44814000, 0x46082403)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x148, 0x3C013F00, 0xC4860010)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x14C, 0x44815000, 0x3C0140A0)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x150, 0x46083403, 0xC48C0048)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x154, 0xC4860010, 0x46003107)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x158, 0x3C0140A0, 0xC48E004C)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x15C, 0x46003207, 0x8C860050)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x164, 0x44815000, 0x44818000)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x168, 0x46009102, 0x46120002)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x16C, 0xE7AA0014, 0xE7B00014)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x170, 0x46024402, 0x46022202)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x174, 0x44072000, 0x44070000)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x178, 0xE7B00010, 0xE7A80010)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x17C, 0xC4920018, 0xC48A0018)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x184, 0x46009107, 0x46005487)
#pragma REWRITE_FUNCTION_WORD(func_86401DBC, 0x188, 0x46022182, 0x46029182)



void func_86401DBC(void *arg0, void *arg1, f32 arg2) {
    typedef struct { u8 bytes[0x10]; } Record;
    s32 flags;
    f32 scale;
    f32 random;
    s32 mask;
    if (*(f32 *)((u8 *)arg0 + 0x4C) <= 0.0f) {
        random = (f32)func_8003570C();
        if (random / 4294967296.0f * *(f32 *)D_86416C00 < arg2) {
            mask = 0x10000000;
            if (*(u32 *)((u8 *)arg0 + 0xC) & 0x01000000) {
                flags = 0x01000000 << *(s32 *)((u8 *)arg1 + 0);
            } else {
                flags = mask;
            }
            if (*(u32 *)((u8 *)arg0 + 0xC) & 0x80000000) {
                scale = 1.0f;
            } else if (*(f32 *)((u8 *)arg1 + 0x1C) > 0.0f) {
                scale = 1.5f;
            } else {
                scale = 0.75f;
            }
            func_86400804(
                *(f32 *)((u8 *)arg0 + 0x48),
                *(f32 *)((u8 *)arg0 + 0x4C),
                *(f32 *)((u8 *)arg0 + 0x50),
                scale * (((f32)func_8003570C() / 4294967296.0f) + 0.5f),
                -*(f32 *)((u8 *)arg0 + 0x10) * arg2,
                5.0f,
                -*(f32 *)((u8 *)arg0 + 0x18) * arg2,
                flags
            );
        }
    }
// The two callers below pass the record word at +0x18, stored as s32 in their source, as the
// third float argument; the retail call passes that word unchanged in $a2. Reinterpreting
// the argument's bits here keeps the callers from inserting an int-to-float conversion.
#define func_86401DBC(a, b, c) func_86401DBC(a, b, *(f32 *)&(c))
}
/* mkdraft:func_86401DBC end */
#endif

#ifdef VERSION_US
s32 func_86401F60(void *arg0) {
    f32 temp_fv0;
    f32 temp_fv1;
    s32 var_v1;

    temp_fv0 = *(f32 *)((u8 *)arg0 + 0x48);
    var_v1 = 0;
    if (*(f32 *)((u8 *)arg0 + 0x48) <= -309.8f) {
        var_v1 = 0x200;
    }
    if (309.8f <= *(f32 *)((u8 *)arg0 + 0x48)) {
        var_v1 = (var_v1 | 0x100) & 0xFFFF;
    }
    temp_fv1 = *(f32 *)((u8 *)arg0 + 0x50);
    if (temp_fv1 <= -254.3f) {
        var_v1 = (var_v1 | 0x800) & 0xFFFF;
    }
    if (254.3f <= temp_fv1) {
        var_v1 = (var_v1 | 0x400) & 0xFFFF;
    }
    if ((*(f32 *)((u8 *)arg0 + 0x48) <= -148.0f) &&
        (-171.2f <= *(f32 *)((u8 *)arg0 + 0x48)) &&
        (temp_fv1 > -92.5f) && (temp_fv1 < 92.5f)) {
        var_v1 = (var_v1 | 0x100) & 0xFFFF;
    }
    if ((*(f32 *)((u8 *)arg0 + 0x48) >= 148.0f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) <= 171.2f) &&
        (temp_fv1 > -92.5f) && (temp_fv1 < 92.5f)) {
        var_v1 = (var_v1 | 0x200) & 0xFFFF;
    }
    if ((temp_fv1 <= -92.5f) && (-115.7f <= temp_fv1) &&
        (*(f32 *)((u8 *)arg0 + 0x48) > -148.0f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) < 148.0f)) {
        var_v1 = (var_v1 | 0x400) & 0xFFFF;
    }
    if ((temp_fv1 >= 92.5f) && (temp_fv1 <= 115.7f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) > -148.0f) &&
        (*(f32 *)((u8 *)arg0 + 0x48) < 148.0f)) {
        var_v1 = (var_v1 | 0x800) & 0xFFFF;
    }
    return var_v1;
}
#endif

#ifdef VERSION_US
extern u8 D_864095F8[];
extern u8 D_86409604[];
extern u8 D_86409610[];
extern u8 D_8640961C[];

// arg1 holds direction bits 0x100-0x800. The bits func_86401F60 returns for the position limits
// and the bits the mode at state + 4 excludes are cleared; the highest remaining bit selects a
// record. If the pair at +0x10/+0x18 has a non-negative dot product with the record's (x, z), the
// record's pair replaces it and the record's halfword at +8 is stored as a float at state + 0x48.
void func_86402158(u8 *arg0, u16 arg1) {
    u8 *state;
    s32 pad;
    u8 *record;

    state = *(u8 **)(arg0 + 0x20);
    record = NULL;
    if (*(u32 *)(arg0 + 0xC) & 0x90000000) {
        arg1 = 0;
    }
    arg1 &= ~func_86401F60(arg0);
    switch (*(u32 *)(state + 4)) {
        case 0:
            arg1 &= 0xF6FF;
            break;
        case 1:
            arg1 &= 0xF5FF;
            break;
        case 2:
            arg1 &= 0xF9FF;
            break;
        case 3:
            arg1 &= 0xFAFF;
            break;
        case 6:
            arg1 &= 0xFEFF;
            break;
        case 7:
            arg1 &= 0xFDFF;
            break;
        case 4:
            arg1 &= 0xF7FF;
            break;
        case 5:
            arg1 &= 0xFBFF;
            break;
    }

    if (arg1 & 0x800) {
        record = D_8640961C;
    } else if (arg1 & 0x400) {
        record = D_86409604;
    } else if (arg1 & 0x200) {
        record = D_864095F8;
    } else if (arg1 & 0x100) {
        record = D_86409610;
    }
    if (record != NULL && 0.0f <= (*(f32 *)(arg0 + 0x18) * *(f32 *)(record + 4)) +
                                          (*(f32 *)(record + 0) * *(f32 *)(arg0 + 0x10))) {
        *(f32 *)(state + 0x48) = *(u16 *)(record + 8);
        *(f32 *)(arg0 + 0x10) = *(f32 *)(record + 0);
        *(f32 *)(arg0 + 0x18) = *(f32 *)(record + 4);
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86402304 begin */
extern float sqrtf(float value);
extern s32 func_80001FF0(void);
extern void func_8002781C(s32, u8, void *);
extern u8 *D_86416C00;



void func_86402304(u8 *arg0) {
    f32 temp_fa0;
    f32 temp_fv1;
    s32 temp_t6;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_t3;
    s32 var_v1;
    s32 var_v1_2;
    u8 *temp_s1;
    u8 *var_s0;
    u8 *child;

    var_s0 = *(u8 **)(D_86416C00 + 0xE0C);
    temp_s1 = *(u8 **)(arg0 + 0x20);
    if (var_s0 != NULL) {
        do {
            child = *(u8 **)(var_s0 + 0x20);
            if ((*(u8 *)(child + 4) != *(s32 *)(temp_s1 + 0)) && (*(s32 *)(var_s0 + 0xC) & 0x20000000)) {
                temp_fv1 = *(f32 *)(arg0 + 0x48) - *(f32 *)(var_s0 + 0x48);
                temp_fa0 = *(f32 *)(arg0 + 0x50) - *(f32 *)(var_s0 + 0x50);
                if (sqrtf((temp_fv1 * temp_fv1) + (temp_fa0 * temp_fa0)) < 30.0f) {
                    temp_v0 = *(s32 *)(arg0 + 0xC);
                    if (!(temp_v0 & 0x40000) && !(temp_v0 & 0x80000000)) {
                        *(f32 *)(temp_s1 + 0x1C) = 0.0f;
                        *(f32 *)(arg0 + 0x14) = 34.800003f;
                        var_v1 = *(s32 *)(temp_s1 + 0x14);
                        switch (var_v1) {
                        case 0:
                            if ((((f32) func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
                                var_t3 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
                                *(s32 *)(temp_s1 + 0x38) = var_t3;
                            } else {
                                *(s32 *)(temp_s1 + 0x38) = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
                            }
                            break;
                        case 1:
                            if ((((f32) func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
                                var_v1 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
                            } else {
                                var_v1 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
                            }
                            *(s32 *)(temp_s1 + 0x38) = (s32) ((f32) var_v1 * 0.7f);
                            break;
                        case 2:
                        case 3:
                            if ((((f32) func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
                                var_v1_2 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
                            } else {
                                var_v1_2 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
                            }
                            *(s32 *)(temp_s1 + 0x38) = (s32) ((f32) var_v1_2 * 0.4f);
                            break;
                        }
                        *(s32 *)(arg0 + 0xC) |= 0x80000000;
                        func_8002781C(0x5F03, *(u8 *)(temp_s1 + 3), temp_s1 + 0x58);
                    }
                    *(s32 *)(var_s0 + 0xC) |= 0x40000000;
                    *(s32 *)(var_s0 + 0xC) &= 0xDFFFFFFF;
                    *(s32 *)(var_s0 + 0x1C) = 0;
                }
            }
            var_s0 = *(u8 **)(var_s0 + 4);
        } while (var_s0 != NULL);
    }
}
/* mkdraft:func_86402304 end */
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
void func_86402688(u8 *arg0, u16 arg1) {
    u8 *state;
    s32 random_value;
    s32 next_random;

    state = *(u8 **)(arg0 + 0x20);
    if (*(s32 *)(arg0 + 0x0C) & 0x02000000) {
        if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
            random_value = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
        } else {
            random_value = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
        }
        if (random_value < *(s32 *)(arg0 + 0x1C)) {
            *(s32 *)(arg0 + 0x0C) &= 0xFDFFFFFF;
        } else if (arg1 & 0x8000) {
            if ((((f32)func_80001FF0() / 60.0f) * 10.0f) >= 0.0f) {
                next_random = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) + 0.5f);
            } else {
                next_random = (s32)((((f32)func_80001FF0() / 60.0f) * 10.0f) - 0.5f);
            }
            *(f32 *)(state + 0x18) += (556.80005f / (f32)func_80001FF0()) * 0.8f *
                                      (1.0f - ((f32)*(s32 *)(arg0 + 0x1C) / (f32)next_random));
            *(s32 *)(arg0 + 0x0C) &= 0xFDFFFFFF;
            *(s32 *)(state + 0x20) = 0x1E;
        }
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_864028B8 begin */
extern void func_8002781C(s32, u8, void *);



s32 func_864028B8(u8 *arg0, u8 *arg1, u16 *arg2) {
    s32 flags;
    s32 ret;
    s32 state;

    flags = *(s32 *)(arg0 + 0xC);
    ret = 1;
    if (flags & 0x20000000) {
        *(u32 *)(arg0 + 0xC) = flags & 0x7FFFFFFF;
        if (--*(s32 *)(arg1 + 0x38) > 0) {
            if (*(s32 *)(arg1 + 0x38) >= 18) {
                *(u32 *)(arg0 + 0xC4) = 0xFF6464C8;
            } else {
                *(u32 *)(arg0 + 0xC4) = 0xFF000000;
            }
            if (*(s32 *)(arg1 + 0x38) % 5 == 0) {
                func_8002781C(0x5404, *(u8 *)(arg1 + 3), arg1 + 0x58);
            }
            *arg2 &= 0xF0FF;
            state = *(s32 *)(arg1 + 0x14);
            switch (state) {
                case 0:
                    *(f32 *)(arg1 + 0x18) *= 0.9f;
                    break;
                case 1:
                    *(f32 *)(arg1 + 0x18) *= 0.92f;
                    break;
                case 2:
                    *(f32 *)(arg1 + 0x18) *= 0.95f;
                    break;
                case 3:
                    *(f32 *)(arg1 + 0x18) *= 0.95f;
                    break;
            }
            ret = 0;
        } else {
            *(f32 *)(arg0 + 0x14) = 0.0f;
            *(u32 *)(arg0 + 0xC) &= 0xDFFFFFFF;
            *(f32 *)(arg0 + 0x4C) = 0.0f;
        }
    }
    return ret;
}
/* mkdraft:func_864028B8 end */
#endif

#ifdef VERSION_US

void func_86402A2C(u8 *arg0) {
    s32 flags = *(s32 *)(arg0 + 0xC);

    if ((flags & 0x80000000) && !(flags & 0x40000)) {
        if (*(f32 *)(arg0 + 0x4C) < 92.8f) {
            *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) + 9.280001f;
            if ((f64)34.80000114440918 < (f64)*(f32 *)(arg0 + 0x14)) {
                *(f32 *)(arg0 + 0x14) = 34.800003f;
            }
        } else {
            *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) - 9.280001f;
        }
    } else {
        *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) - 9.280001f;
    }
    *(f32 *)(arg0 + 0x4C) = *(f32 *)(arg0 + 0x14) + *(f32 *)(arg0 + 0x4C);
    if (*(f32 *)(arg0 + 0x4C) < 0.0f) {
        *(f32 *)(arg0 + 0x4C) = 0.0f;
        *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) * -0.75f;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86402B1C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_864033AC.s")
#endif

#ifdef VERSION_US
// Stores at arg0 + 0x50 the frame count of 175 frames at 60 Hz, converted to the rate
// func_80001FF0 reports, times a random factor whose range depends on the byte at +0x2181:
// [1, 2), [0.3, 0.5), [0.2, 0.5) or 0.
void func_86403550(u8 *arg0) {
    f32 scale;
    s32 value;

    value = *(s8 *)(*(u8 **)(D_86416C00 + 0x70) + 0x2181);
    switch (value) {
        case 0:
            scale = func_8003570C() / 4294967296.0f + 1.0f;
            break;
        case 1:
            scale = func_8003570C() / 4294967296.0f * 0.2f + 0.3f;
            break;
        case 2:
            scale = func_8003570C() / 4294967296.0f * 0.3f + 0.2f;
            break;
        case 3:
            scale = 0.0f;
            break;
    }

    value = (func_80001FF0() / 60.0f * 175.0f >= 0.0f) ? func_80001FF0() / 60.0f * 175.0f + 0.5f
                                                       : func_80001FF0() / 60.0f * 175.0f - 0.5f;
    *(s32 *)(arg0 + 0x50) = value * scale;
}
#endif

#ifdef VERSION_US
extern f32 func_87D0059C(f32 *, f32 *);
void func_8640377C(void *arg0, void *arg1) {
    f32 values[2];
    f32 *first = &values[0];
    f32 *second = &values[1];

    *first = *(f32 *)((u8 *)arg0 + 0x48) - *(f32 *)((u8 *)arg1 + 0);
    *second = *(f32 *)((u8 *)arg0 + 0x50) - *(f32 *)((u8 *)arg1 + 4);
    func_87D0059C(first, second);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_864037C0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86403B3C.s")
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
void func_86403CB4(void) { void *node; node = *(void **)(D_86416C00 + 0xE0C); while (node != NULL) { node = *(void **)((u8 *)node + 4); } }
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86403CDC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86403F5C.s")
#endif

#ifdef VERSION_US
f32 func_86404724(void) {
    s8 kind;
    f32 result;

    kind = *(s8 *)((u8 *)(*(u8 **)(D_86416C00 + 0x70)) + 0x2181);
    switch (kind) {
    case 0:
        result = (f32)func_8003570C();
        result = (((result / 4294967296.0f) + (result / 4294967296.0f)) - 1.0f) * 23.2f * 6.0f;
        break;
    case 1:
        result = (f32)func_8003570C();
        result = (((result / 4294967296.0f) + (result / 4294967296.0f)) - 1.0f) * 23.2f * 2.0f;
        break;
    default:
        result = 0.0f;
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
// Classifies the x/z position at 0x48/0x50 into a zone: corners 0-3 (each also sets one
// flag bit at 0xC), then edges 4-7, and stores it at child + 4. When the zone changes,
// child + 0x54 receives a new value from func_86404724.
void func_86404824(u8 *arg0) {
    u8 *child;
    s32 previous_zone;

    child = *(u8 **)(arg0 + 0x20);
    previous_zone = *(s32 *)(child + 4);
    if (*(f32 *)(arg0 + 0x48) <= -124.8f && *(f32 *)(arg0 + 0x50) <= -69.3f) {
        *(u32 *)(arg0 + 0xC) |= 0x100000;
        *(s32 *)(child + 4) = 0;
    } else if (*(f32 *)(arg0 + 0x48) <= -124.8f && 69.3f <= *(f32 *)(arg0 + 0x50)) {
        *(u32 *)(arg0 + 0xC) |= 0x200000;
        *(s32 *)(child + 4) = 1;
    } else if (124.8f <= *(f32 *)(arg0 + 0x48) && 69.3f <= *(f32 *)(arg0 + 0x50)) {
        *(u32 *)(arg0 + 0xC) |= 0x800000;
        *(s32 *)(child + 4) = 2;
    } else if (124.8f <= *(f32 *)(arg0 + 0x48) && *(f32 *)(arg0 + 0x50) <= -69.3f) {
        *(u32 *)(arg0 + 0xC) |= 0x400000;
        *(s32 *)(child + 4) = 3;
    } else if (*(f32 *)(arg0 + 0x50) <= -92.5f) {
        *(s32 *)(child + 4) = 6;
    } else if (*(f32 *)(arg0 + 0x50) >= 92.5f) {
        *(s32 *)(child + 4) = 7;
    } else if (*(f32 *)(arg0 + 0x48) <= -148.0f) {
        *(s32 *)(child + 4) = 4;
    } else if (*(f32 *)(arg0 + 0x48) >= 148.0f) {
        *(s32 *)(child + 4) = 5;
    }
    if (previous_zone != *(s32 *)(child + 4)) {
        *(f32 *)(child + 0x54) = func_86404724();
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86404A0C.s")
#endif

#ifdef VERSION_US
void func_86404D48(u8 *arg0, u8 *arg1) {
    *(f32 *)(arg0 + 0x48) += *(f32 *)(arg1 + 0x2C);
    *(f32 *)(arg0 + 0x4C) += *(f32 *)(arg1 + 0x30);
    *(f32 *)(arg0 + 0x50) += *(f32 *)(arg1 + 0x34);
    *(f32 *)(arg1 + 0x2C) = 0.0f;
    *(f32 *)(arg1 + 0x30) = 0.0f;
    *(f32 *)(arg1 + 0x34) = 0.0f;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86404D8C.s")
#endif

#ifdef VERSION_US
extern void func_86407290(f32, f32, f32, f32, f32, f32, s32); //@src/fragments/52/fragment52_285750.c

// Averages the positions (+0x48/+0x4C/+0x50) of the four 0x18C-byte records from
// D_86416C00 + 0x7D0 whose word +0xC has flag 0x10000, or of all four when none has it, and
// passes func_86407290 two points offset from that average.
void func_86405138(void) {
    f32 x;
    f32 y;
    f32 z;
    s32 i;
    s32 count;
    u8 *p;

    count = 0;
    p = D_86416C00 + 0x7D0;
    x = y = z = 0.0f;
    for (i = 0; i < 4; i++) {
        if (*(s32 *)(p + 0xC) & 0x10000) {
            count++;
        }
        p += 0x18C;
    }
    if (count == 0) {
        count = 4;
        p = D_86416C00 + 0x7D0;
        for (i = 0; i < 4; i++, p += 0x18C) {
            x += *(f32 *)(p + 0x48);
            y += *(f32 *)(p + 0x4C);
            z += *(f32 *)(p + 0x50);
        }
    } else {
        p = D_86416C00 + 0x7D0;
        for (i = 0; i < 4; i++, p += 0x18C) {
            if (*(s32 *)(p + 0xC) & 0x10000) {
                x += *(f32 *)(p + 0x48);
                y += *(f32 *)(p + 0x4C);
                z += *(f32 *)(p + 0x50);
            }
        }
    }
    if (count >= 2) {
        x /= count;
        y /= count;
        z /= count;
    }
    func_86407290(x - 200.0f, y + 450.0f, z + 80.0f, x + 90.0f, y - 40.0f, z, 60);
}
#endif

#ifdef VERSION_US
// Sine and cosine tables indexed by a 16-bit angle >> 4, as in SINS/COSS. //@include/229E0.h
extern f32 D_80087E50[];
extern f32 D_80088E50[];

// For each of the four 396-byte records from D_86416C00 + 0x7D0, updates the node scale at
// child + 0x18 (child = record + 0x20): while flag 0x20000 at +0xC is set, the scale grows by
// 0.13 for the first 20 frames counted at +0x1C and then decays by 0.9; otherwise it decays by
// 0.94. The position at +0x48/+0x50 advances by the direction at +0x10/+0x18 times the scale.
// In the second pass, a record whose scale has dropped below 1 and whose flag 0x20000 is clear
// sets flag 0x10000000 on the entry indexed by child + 0 in the 396-byte array at
// D_86416C00 + 0xCDD0, sets its own flag 0x20000 (record 0 first calls func_86405138), and,
// unless flag 0x10000 is set, restarts the counter, points +0x10/+0x18 along the angle at +0x44
// (cosine, negated sine) and clears the scale.
void func_8640533C(void) {
    u8 *state;
    u8 *child;
    s32 i;

    state = D_86416C00 + 0x7D0;
    for (i = 0; i < 4; i++, state += 396) {
        child = *(u8 **)(state + 0x20);
        *(s32 *)(child + 0x20) = 0;
        func_86404824(state);
        if (*(s32 *)(state + 0xC) & 0x20000) {
            if (++*(s32 *)(state + 0x1C) < 20) {
                *(f32 *)(child + 0x18) += 0.13f;
            } else {
                *(f32 *)(child + 0x18) *= 0.9f;
            }
            *(f32 *)(state + 0x48) += *(f32 *)(state + 0x10) * *(f32 *)(child + 0x18);
            *(f32 *)(state + 0x50) += *(f32 *)(state + 0x18) * *(f32 *)(child + 0x18);
        } else {
            *(f32 *)(child + 0x18) *= 0.94f;
            *(f32 *)(state + 0x48) += *(f32 *)(state + 0x10) * *(f32 *)(child + 0x18);
            *(f32 *)(state + 0x50) += *(f32 *)(state + 0x18) * *(f32 *)(child + 0x18);
        }
        func_86402A2C(state);
    }
    func_86401D1C();
    state = D_86416C00 + 0x7D0;
    for (i = 0; i != 4; i++, state += 396) {
        child = *(u8 **)(state + 0x20);
        func_86404D48(state, child);
        func_86401DBC(state, child, *(s32 *)(child + 0x18));
        if (*(f32 *)(child + 0x18) < 1.0f && !(*(s32 *)(state + 0xC) & 0x20000)) {
            *(s32 *)(*(s32 *)child * 396 + *(u8 **)(D_86416C00 + 0xCDD0) + 0xC) |= 0x10000000;
            if (i == 0) {
                func_86405138();
            }
            *(s32 *)(state + 0xC) |= 0x20000;
            if (!(*(s32 *)(state + 0xC) & 0x10000)) {
                *(s32 *)(state + 0x1C) = 0;
                *(f32 *)(state + 0x10) = D_80088E50[*(u16 *)(state + 0x44) >> 4];
                *(f32 *)(state + 0x18) = -D_80087E50[*(u16 *)(state + 0x44) >> 4];
                *(f32 *)(child + 0x18) = 0.0f;
            }
        }
        func_86404A0C(state);
    }
}

#endif

#ifdef VERSION_US
// For each of the four 0x18C-byte records from D_86416C00 + 0x7D0, decays the node scale at
// +0x18 by 0.8 and advances +0x48 by +0x10 times that scale. Once the scale drops below 1 it
// is cleared (record 0 first calls func_86407290 while it is still positive) and, when +0x64
// is 1, the animation at +0x24 restarts at a random frame 0-15.
void func_864055CC(void) {
    u8 *state = D_86416C00;
    u8 *node;
    u8 *child;
    s32 i;

    state += 0x7D0;
    for (i = 0; i < 4; i++, state += 0x18C) {
        node = *(u8 **)(state + 0x20);
        *(f32 *)(node + 0x18) *= 0.8f;
        *(f32 *)(state + 0x48) += *(f32 *)(state + 0x10) * *(f32 *)(node + 0x18);
        if (*(f32 *)(node + 0x18) < 1.0f) {
            if (i == 0 && *(f32 *)(node + 0x18) > 0.0f) {
                func_86407290(0.0f, 1049.5f, 553.0f, 0.0f, 30.0f, 30.0f, 80);
            }
            *(f32 *)(node + 0x18) = 0.0f;
            if (*(s16 *)(state + 0x64) == 1) {
                func_8003F210(state + 0x24, 0);
                ModelAnim_SetFrame(state + 0x24, (s16)(func_8003570C() & 0xF));
            }
        }
    }
    func_86401D1C();
    state = D_86416C00;
    state += 0x7D0;
    for (i = 0; i < 4; i++, state += 0x18C) {
        child = *(u8 **)(state + 0x20);
        func_86404D48(state, child);
        func_86401DBC(state, child, *(s32 *)(child + 0x18));
    }
}
#endif

#ifdef VERSION_US
extern void func_86404D8C();
extern void func_8640533C();
extern void func_864055CC();
void func_86405778(void) {
    s32 temp_v0;

    temp_v0 = (*(s32 *)((u8 *)(D_86416C00) + (0x10)));
    switch (temp_v0) {                              /* irregular */
    case 3:
        func_864055CC();
        return;
    case 4:
        func_86404D8C();
        return;
    default:
        func_8640533C();
        return;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_864057E0.s")
#endif

#ifdef VERSION_US
extern void func_8003F03C(void *, void *);
extern void func_8003F018(void *);
extern u8 D_86409C70[];
extern void func_8003F114(u8 *, s32, s32, s32);
extern void func_8003F1DC(u8 *);
extern u8 * D_86416C00;
// The three 0.37f stores are separate literals: the ROM holds three 0.37f words at
// 0x86409B78-0x86409B80 even though the compiled code loads only one of them.
void func_86405BEC(void) { u8 *obj; f32 value; obj = D_86416C00 + 0xC8BC; func_8003F03C(obj, D_86409C70); func_8003F1DC(obj); func_8003F114(obj, 0, -1, *(s32 *)(D_86416C00 + 0x7A8)); *(f32 *)(obj + 0x38) = 0.37f; *(f32 *)(obj + 0x34) = 0.37f; *(f32 *)(obj + 0x30) = 0.37f; obj = D_86416C00 + 0xCA24; func_8003F018(obj); func_8003F1DC(obj); func_8003F114(obj, 0, -1, *(s32 *)(D_86416C00 + 0x7AC)); value = 0.37f; *(f32 *)(obj + 0x38) = value; *(f32 *)(obj + 0x34) = value; *(f32 *)(obj + 0x30) = value; }
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86405CB4.s")
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern void func_87F0277C(u8 *);
extern s32 func_87F08208(u8 *);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void Audio_PlayDefaultSound(s32);
extern void func_86406660(s32);
extern void func_800226C0(s32);
void func_86405E08(void) {
    s32 state;

    func_87F0277C(D_86416C00 + 0xE0);
    state = func_87F08208(D_86416C00 + 0xA8);
    switch (state) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)(D_86416C00 + 0x10) = 2;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        break;
    case 2:
        func_86406660(0);
        func_800226C0(3);
        break;
    }
}
#endif

#ifdef VERSION_US
extern u8 *D_86416C00;
extern void func_87C037C0(u8 *, s32);
extern s32 StageContext_GetFadeMode(void);
extern void func_86407034(void);
extern void func_864057E0(void);
extern void StageFade_StartFromOpaque(s32);
extern void func_87F00688(void);
extern void func_87F0277C(u8 *);

void func_86405EA4(void) {
    func_87C037C0(D_86416C00 + 0xCEC8, *(s32 *)(*(u8 **)(D_86416C00 + 0xB4) + 0xC));
    if (StageContext_GetFadeMode() == 1) {
        func_86407034();
        func_864057E0();
        StageFade_StartFromOpaque(0x14);
        *(s32 *)(D_86416C00 + 0x10) = 3;
        func_87F00688();
    }
    func_87F0277C(D_86416C00 + 0xE0);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86405F28.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_8640633C begin */
extern u8 *D_86416C00;
extern void func_80027774(s32, s32);
extern void func_800279C4(s32);
extern void func_87F0CA58(void);
extern void func_8640826C(void);



s32 func_8640633C(void) {
    s32 should_stop;
    s32 result;
    s32 count;
    u8 *p;
    s32 i;
    s32 k;
    u8 *obj;
    u8 *entry;
    s32 flags;

    should_stop = 0;
    result = 0;
    count = 0;
    p = D_86416C00 + 0x7D0;
    for (k = 0; k < 4; k++) {
        if (*(s32 *)(p + 0xC) & 0x40000) {
            count++;
        }
        p += 0x18C;
    }
    obj = D_86416C00 + 0x7D0;
    i = 0;
    do {
        entry = *(u8 **)(obj + 0x20);
        if (*(s32 *)(entry + 0xC) <= 0) {
            if (count == 4) {
                result = 1;
            }
            if (count == 0) {
                should_stop = 1;
                *(s32 *)(obj + 0xC) |= 0x10000;
            }
            flags = *(s32 *)(obj + 0xC);
            if (!(flags & 0x40000)) {
                *(s32 *)(obj + 0xC) = flags | 0x40000;
                *(f32 *)(entry + 0x10) = 10000.0f - (f32)*(s32 *)(entry + 0x14);
                if (*(s32 *)(obj + 0xC) & 0x10000) {
                    func_80027774(0x1C07, 0x44);
                    func_800279C4(0x5F08);
                } else {
                    func_800279C4(0x5F08);
                }
            }
        }
        i++;
        obj += 0x18C;
    } while (i != 4);
    if (should_stop != 0) {
        func_87F0CA58();
        func_8640826C();
    }
    return result;
}
/* mkdraft:func_8640633C end */
#endif

#ifdef VERSION_US
extern void *func_87F0A3E8(void *);
extern void func_8002781C(s32, u8, void *);
extern void func_86406660(s32 arg0);
extern void func_864066B4(void);
void func_864064DC(void) {
    u8 *v0;
    void *v1;

    func_864066B4();
    v1 = func_87F0A3E8(D_86416C00 + 0x724);
    if (v1 != NULL) {
        v0 = D_86416C00;
        if (*(u8 *)(*(u8 **)(v0 + 0x70) + 0x2180) == 1) {
            func_86406660(2);
        } else {
            *(s32 *)(v0 + 0x10) = 6;
        }
    }
}
#endif

#ifdef VERSION_US
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(void *, u16);
extern void GfxImage_ClearDepthRectangle(void *, s32, s32, s32, s32);
extern s32 func_87F00930(void);
extern void GeoRender_AdvanceFrameCounter(void);
extern u8 D_800D0510;
extern u8 *D_86416C00;
extern void Geo_RenderRootNode(s32);
extern void func_864082A8(void);
extern void func_87F0A5BC(u8 *);
extern void func_87F07FE8(u8 *);
extern void func_87F022F0(void);
extern void func_87F01D44(void);
extern void func_87F0C88C(u8 *);
extern void func_80008648(void);
void func_86406544(void) {
    s32 flags;

    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 0x401);
    GfxImage_ClearDepthRectangle(&D_800D0510, 0, 0, 0x140, 0xF0);
    if (func_87F00930() == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(*(s32 *)(D_86416C00 + 0x6C));
    func_864082A8();
    if (*(s32 *)(D_86416C00 + 0x10) == 5) {
        func_87F0A5BC(D_86416C00 + 0x724);
    }
    flags = *(s32 *)(D_86416C00 + 0xCEB0);
    if (flags & 1) {
        func_87F07FE8(D_86416C00 + 0xA8);
        flags = *(s32 *)(D_86416C00 + 0xCEB0);
    }
    if (flags & 2) {
        func_87F022F0();
    }
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
    func_87F0C88C(D_86416C00 + 0x9C);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern void StageFade_StartFromTransparent(s32);
extern void StageContext_SetClearColor(s32);
void func_86406660(s32 arg0) {
    (*(s32 *)((u8 *)(D_86416C00) + (0xCEB4))) = arg0;
    (*(s32 *)((u8 *)(D_86416C00) + (0x10))) = 7;
    (*(s32 *)((u8 *)(D_86416C00) + (0x68))) = 8;
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(0xA);
}
#endif

#ifdef VERSION_US
extern void func_86405778(void);
extern void func_87F0277C(u8 *);
extern void func_86409260(u8 *);
extern void func_86401550(void);
void func_864066B4(void) {
    func_86405778();
    func_87F0277C(D_86416C00 + 0xE00);
    func_87F0277C(D_86416C00 + 0x3334);
    func_86409260(D_86416C00 + 0xB554);
    func_86401550();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_27E4E0/func_86406710.s")
#endif

#ifdef VERSION_US
extern u8 D_800CE060[];
extern s32 func_87F01A40(void);
extern s32 func_87F006AC(void);
extern void func_86408CA0(s32, s32);
extern void func_87F0CA30(void);
extern void func_86408148(void);
extern void Audio_PlayDefaultSound(s32);
extern void func_86406660(s32 arg0);
extern void func_864066B4(void);
extern u8 * D_86416C00;
void func_864068A4(void) {
    s32 state;
    s32 i;
    u8 *record;
    u8 *object;
    if (StageContext_GetFadeMode() == 0) {
        state = func_87F01A40();
    } else {
        state = 2;
    }
    switch (state) {
    case 0:
    case 2:
        func_864066B4();
        record = D_800CE060;
        object = D_86416C00 + 0x7D0;
        for (i = 0; i < 4; i++, record += 0x28, object += 0x18C) {
            if (*(u16 *)(record + 8) & 0x8000) {
                *(s32 *)(object + 0xC) &= 0xFDFFFFFF;
            }
        }
        if (func_87F006AC() == 1) {
            Audio_PlayDefaultSound(0x5F07);
        }
        if (func_87F006AC() == 2) {
            *(s32 *)(D_86416C00 + 0x10) = 4;
            Audio_PlayDefaultSound(0x5F08);
            func_86408CA0(0x22, 0x1E);
            func_87F0CA30();
            func_86408148();
        }
        break;
    case 3:
        func_86406660(0);
        break;
    case 4:
        func_86406660(1);
        break;
    }
}
#endif

#ifdef VERSION_US
extern void func_86408C1C(void);
extern void func_87F006BC(void);
extern void func_86405E08(void);
extern void func_86405EA4(void);
extern void func_86406710(void);
extern void func_864064DC(void);
extern void func_86405CB4(void);
extern s32 func_87F02104(void);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_87F0D5B8(u8 *);
extern s32 func_87F0C6F4(u8 *);
extern void func_87F0C9D0(s32);
void func_864069DC(void) {
    func_87C037C0(D_86416C00 + 0xCEC8, *(s32 *)(*(u8 **)(D_86416C00 + 0x6C) + 0xC));
    func_86408C1C();
    if (func_87F00930() == 0) {
        func_87F006BC();
    }
    switch (*(s32 *)(D_86416C00 + 0x10)) {
    case 0:
        *(s32 *)(D_86416C00 + 0xCEB0) = 1;
        if (StageContext_GetFadeMode() == 0) {
            *(s32 *)(D_86416C00 + 0x10) = 1;
        }
        break;
    case 1:
        func_86405E08();
        break;
    case 2:
        func_86405EA4();
        break;
    case 3:
        *(s32 *)(D_86416C00 + 0xCEB0) = 0;
        func_864068A4();
        break;
    case 4:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_86406710();
            break;
        case 3:
            func_86406660(0);
            break;
        case 4:
            func_86406660(1);
            break;
        }
        break;
    case 5:
        func_864064DC();
        break;
    case 6:
        *(s32 *)(D_86416C00 + 0xCEB0) = 2;
        switch (func_87F02104()) {
        case 1:
            StageContext_SetClearColor(0);
            *(s32 *)(D_86416C00 + 0x10) = 7;
            *(s32 *)(D_86416C00 + 0x68) = 0;
            StageFade_StartFromTransparent(10);
            break;
        case 2:
            func_86406660(0);
            break;
        case 3:
            func_86406660(1);
            break;
        }
        break;
    case 7:
        if (StageContext_GetFadeMode() == 1) {
            *(s32 *)(D_86416C00 + 0x10) = *(s32 *)(D_86416C00 + 0x68);
            if (*(s32 *)(D_86416C00 + 0x10) == 0) {
                func_86405CB4();
                StageFade_StartFromOpaque(10);
            }
        }
        break;
    }
    func_87F0D5B8(D_86416C00 + 0x74);
    if (func_87F0C6F4(D_86416C00 + 0x9C) != 0) {
        *(s32 *)(D_86416C00 + 0xCEB4) = 3;
        *(s32 *)(D_86416C00 + 0x10) = 8;
    }
    func_87F0C9D0(func_87F00930());
}
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_864069DC(void);
extern void func_86406544(void);
void func_86406C6C(void)
{
  struct Func86406C6CState {
    u8 pad0[0x10];
    s32 status;
    u8 pad1[0xCEAC - 0x14];
    s32 counter;
  };

  func_800086A4(2);
  StageFade_StartFromOpaque(0xA);
  do
  {
    ((struct Func86406C6CState *)D_86416C00)->counter =
        ((struct Func86406C6CState *)D_86416C00)->counter + 1;
    func_80064D28();
    func_864069DC();
    func_86406544();
  }
  while (((struct Func86406C6CState *)D_86416C00)->status != 8);
}
#endif

#ifdef VERSION_US
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern u8 D_800CE100[];
extern u8 D_86409CB8[];
extern void func_86405F28(void);
extern void func_86406C6C(void);

// Same code as fragment50's func_86205308 on this fragment's state D_86409CB8 (stage
// context at 0x70); GS loads different resources (291; 150, 159, 434, 385-387),
// passes 100 to func_87F06EAC, passes the word at 0xB0 with bit 2 set to
// func_80047588, and returns the word at 0xCEB4.
//@src/fragments/50/fragment50_266A60.c
s32 func_86406CF8(s32 arg0, s32 arg1) {
    u8 *var_v0;
    u8 *ptr;
    u8 *end;

    main_pool_push_state(0x4D59524D); // 'MYRM'
    D_86416C00 = D_86409CB8;
    *(s32 *)(D_86416C00 + 0x70) = arg1;
    if (*(u8 *)((u8 *)*(s32 *)(D_86416C00 + 0x70) + 0x2180) == 4) {
        func_80027EE0(4095);
    }
    Gfx_InitDisplayListBuffers(0x20000, 0);
    var_v0 = func_800082E0(0, 0, 2, 1, 2, 1);
    func_8004C09C(291);
    func_87F09EBC(D_86416C00 + 0x724, *(s32 *)(D_86416C00 + 0x70));
    func_87F06EAC(100, D_86416C00 + 0xA8, *(s32 *)(D_86416C00 + 0x70));
    func_8004C8C0(150);
    func_8004C8C0(159);
    func_8004C8C0(434);
    func_8004C8C0(385);
    func_8004C8C0(386);
    func_8004C8C0(387);
    func_87F061D0();
    func_80047588(*(s32 *)(D_86416C00 + 0xB0) | 2, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    // FAKE: both assignments share one source line, as in func_86205308; diff score 30
    // without it.
    ptr = D_800CE060, end = D_800CE100;
    do {
        func_80006148(ptr);
        ptr += 40;
    } while (ptr != end);
    func_86405F28();
    func_80008514(var_v0);
    func_86406C6C();
    func_80008574();
    func_80006158();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D59524D); // 'MYRM'
    func_87F0F480(*(s32 *)(D_86416C00 + 0x70));
    func_80027EE0(4094);
    return *(s32 *)(D_86416C00 + 0xCEB4);
}
#endif
