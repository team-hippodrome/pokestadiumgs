#include "global.h"


#ifdef VERSION_US
extern void Util_Free(s32);
extern void func_8821CE40(s32);
extern void func_8822EA80();
extern void func_888002DC();
extern void main_pool_pop_state(s32);
extern s32 D_88234560;
extern s32 D_88234564;
extern s32 D_88234720;
void func_88210480(void) {
    Util_Free(D_88234564);
    Util_Free(D_88234720);
    func_8822EA80();
    func_888002DC();
    main_pool_pop_state(0x41525242);
    func_8821CE40(2);
    D_88234560 = 5;
}

extern s32 D_88A01C30;
typedef struct unk_D_88A01C30_20 {
    /* 0x00 */ void **unk_00;
    /* 0x04 */ u8 unk_04[0x10];
} unk_D_88A01C30_20; // size = 0x14, array at D_88A01C30 + 0x20

typedef struct unk_D_88234720 {
    /* 0x00 */ u8 unk_00[0x14];
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ u8 unk_18[0x14];
} unk_D_88234720; // size = 0x2C

void *func_882104DC(s32 mode, u8 slot) {
    s16 index;
    void **table = ((unk_D_88A01C30_20 *)(D_88A01C30 + 0x20))[slot].unk_00;

    switch (mode) {
        case 0:
            index = ((unk_D_88234720 *)D_88234720)[slot].unk_16;
            break;
        case 1:
            index = ((unk_D_88234720 *)D_88234720)[slot].unk_14;
            break;
        case 2:
            index = 0;
            break;
        case 3:
            index = *(s16 *)(D_88234720 + 0x66);
            break;
    }
    //!bug index is uninitialized for any other mode.
    return table[index];
}

extern s32 D_88234720;
void func_88210480(void);
extern s32 D_88A01C30;
extern s32 D_882346F0;
extern s32 D_882346F4;
extern s32 D_88234724;
void Input_SetRepeatController(s32);
s32 Util_Malloc(s32);
s32 func_80001FF0();
s32 func_8004C4B0(s32);
void func_88000288(void *, s32, s32, s32, s32, s32, s32, s32);
s32 func_88001C6C(s32, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_88005B60(s32, s32 *, s32 *, s32 *);
s32 func_882011E0(s32);
s32 func_88204080(s32);
s32 func_88205EB0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, void (*)());
s32 func_8822E950();
s32 func_88800020();
s32 main_pool_push_state(s32);
s32 mem_pool_try_init(s32, s32);
extern s32 D_80087200;
extern s32 D_88000E4C;
extern s32 D_880068B4;
extern s32 D_880068B8;



void func_882105B0(void)
{
  s32 temp_v0;
  s32 var_s0;
  s32 var_s1;
  s32 temp_s2;
  f32 sp1A4;
  s32 temp_s0;
  f32 sp19C;
  s32 temp_s1;
  f32 sp194;
  s32 sp190;
  f32 sp18C;
  s32 sp188;
  s32 sp184;
  f32 sp180;
  s32 sp17C;
  f32 sp178;
  f32 var_fv0;
  f32 var_fv0_2;
  f32 t18C;
  f32 t178;
  f32 t19C;
  f32 t1A4;
  f32 tfv0;
  f32 var_fv1;
  // FAKE: separate int->float conversion temps. Converting in its own statement makes IDO emit
  // FAKE: mul.s (const, value) as retail emits it; inline casts change the operand order.
  f32 c188;
  f32 c184;
  f32 c17C;
  f32 c190;
  f32 cS1;
  f32 cS0;
  f32 cS2;
  main_pool_push_state(0x41525242);
  func_88800020();
  func_8822E950();
  D_88234720 = Util_Malloc(0x78);
  func_88205EB0(0x2C, 0x191, 0x229, 0x30, 0x2C, 0x48, 0xF2, 0x143, 0x31, 0x69, 0xE5, 0x11A, 0x163, 0x48, 0xF2, 0x143, 0x168, 0x69, 0xE5, 0x11A, 0x34, 0x6C, 0xDF, 0x11, 0x34, 0x16F, 0xDF, 0x11, 0x16B, 0x6C, 0xDF, 0x11, 0x16B, 0x16F, 0xDF, 0x11, 0x121, 0x48, 0x3F, 0x26, 0x34, 0x7D, 0xDF, 0x1A, 0x16B, 0x7D, 0xDF, 0x1A, 0xFB, 0x4F, 0x16B, 0x4F, -1, -1, -1, -1, -1, -1, -1, -1, 0x88, 0x70, 0x9A, 0x70, 0x9A, 0x173, 0xAE, 0x173, 0x1BF, 0x70, 0x1D1, 0x70, 0x1D1, 0x173, 0x1E5, 0x173, 5, 0x22, func_88210480);
  func_8004C4B0(0x22);
  temp_v0 = mem_pool_try_init(0x10000, 0);
  func_882011E0(temp_v0);
  func_88204080(temp_v0);
  *((s8 *) (((u8 *) D_88234720) + 0)) = 0;
  *((s32 *) (((u8 *) D_88234720) + 4)) = 1;
  *((s16 *) (((u8 *) D_88234720) + 8)) = 0;
  var_s1 = 0;
  var_s0 = 0;
  *((s8 *) (((u8 *) D_88234720) + 0x64)) = 0;
  do
  {
    temp_s2 = func_80001FF0();
    if ((600.0f / ((f32) func_80001FF0())) > 0.0f)
    {
      var_fv0 = 0.5f;
    }
    else
    {
      var_fv0 = -0.5f;
    }
    var_fv1 = 600.0f / ((f32) temp_s2);
    func_88001C6C((D_88234720 + var_s1) + 0xC, *((u8 *) (((u8 *) (D_88A01C30 + var_s0)) + 0x25)), 9, 0x7D, 0x1B, 0xE, (s32) (var_fv0 + var_fv1), 0x30, 0x30, 0xC, 0x46);
    var_s0 += 0x14;
    var_s1 = var_s1 + 0x2C;
  }
  while (var_s0 != 0x28);
  Input_SetRepeatController(D_80087200);
  D_882346F0 = 0;
  D_880068B4 = (D_880068B8 = 1);
  D_88234724 = 0;
  D_882346F4 = 0;
  if (((((f32) func_80001FF0()) * 8.0f) / 60.0f) > 0.0f)
  {
    sp178 = 0.5f;
  }
  else
  {
    sp178 = -0.5f;
  }
  sp17C = func_80001FF0();
  if (((((f32) func_80001FF0()) * 5.0f) / 60.0f) > 0.0f)
  {
    sp180 = 0.5f;
  }
  else
  {
    sp180 = -0.5f;
  }
  sp184 = func_80001FF0();
  sp188 = func_80001FF0();
  if (((((f32) func_80001FF0()) * 30.0f) / 60.0f) > 0.0f)
  {
    sp18C = 0.5f;
  }
  else
  {
    sp18C = -0.5f;
  }
  sp190 = func_80001FF0();
  if (((((f32) func_80001FF0()) * 5.0f) / 60.0f) > 0.0f)
  {
    sp194 = 0.5f;
  }
  else
  {
    sp194 = -0.5f;
  }
  temp_s1 = func_80001FF0();
  if (((((f32) func_80001FF0()) * 8.0f) / 60.0f) > 0.0f)
  {
    sp19C = 0.5f;
  }
  else
  {
    sp19C = -0.5f;
  }
  temp_s0 = func_80001FF0();
  if (((((f32) func_80001FF0()) * 30.0f) / 60.0f) > 0.0f)
  {
    sp1A4 = 0.5f;
  }
  else
  {
    sp1A4 = -0.5f;
  }
  temp_s2 = func_80001FF0();
  if (((((f32) func_80001FF0()) * 8.0f) / 60.0f) > 0.0f)
  {
    var_fv0_2 = 0.5f;
  }
  else
  {
    var_fv0_2 = -0.5f;
  }
  c188 = (f32) sp188;
  c184 = (f32) sp184;
  c17C = (f32) sp17C;
  c190 = (f32) sp190;
  cS1 = (f32) temp_s1;
  cS0 = (f32) temp_s0;
  cS2 = (f32) temp_s2;
  t18C = (30.0f * c188) / 60.0f;
  t19C = (8.0f * cS1) / 60.0f;
  t1A4 = (30.0f * cS0) / 60.0f;
  tfv0 = (8.0f * cS2) / 60.0f;
  // FAKE: the (0, sp194) comma expression keeps sp194's reload order; a plain sp194 reloads it at a different point.
  func_88000288(D_88234720 + 0x68, (s16) ((((s32) (sp18C + t18C)) + ((s32) (((5.0f * c184) / 60.0f) + sp180))) + ((s32) (((8.0f * c17C) / 60.0f) + sp178))), 0xFF, 0, (s32) (((0, sp194)) + ((5.0f * c190) / 60.0f)), (s32) (sp19C + t19C), (s32) (sp1A4 + t1A4), (s32) (var_fv0_2 + tfv0));
  func_88005B60(0, &D_88000E4C, &D_88000E4C, &D_88000E4C);
}

extern s32 func_880007B0(u8 *);
extern s32 func_80063754(s32);
extern s32 D_88A01C30;
s32 func_88210D48(void *arg0) {
    s32 result;
    s32 *ptr;
    u32 i;

    result = 0;
    ptr = *(s32 **)((u8 *)arg0 + 0x10);
    i = 0;
    if (*(u8 *)((u8 *)arg0 + 0x15) != 0) {
        do {
            if (func_880007B0((u8 *)(*ptr + 8)) == 0) {
                result = 1;
                break;
            }
            i += 1;
            ptr += 1;
        } while (i < *(u8 *)((u8 *)arg0 + 0x15));
    }
    return result;
}

s32 func_88210DC4(void *arg0) {
    s32 result;
    u8 **ptr;
    u32 i;

    result = 0;
    ptr = *(u8 ***)((u8 *)arg0 + 0x10);
    i = 0;
    if (*(u8 *)((u8 *)arg0 + 0x15) != 0) {
        do {
            if (func_80063754((*ptr)[9]) != 0) {
                result = 1;
                break;
            }
            i += 1;
            ptr += 1;
        } while (i < *(u8 *)((u8 *)arg0 + 0x15));
    }
    return result;
}

extern u8 D_882345D4;
extern s32 func_88201F7C(void *);
s32 func_88210E40(void *arg0) {
    s32 result;
    u8 **ptr;
    u32 i;

    result = 0;
    ptr = *(u8 ***)((u8 *)arg0 + 0x10);
    if (D_882345D4 == 0) {
        i = 0;
        if (*(u8 *)((u8 *)arg0 + 0x15) != 0) {
            do {
                if (func_88201F7C(*ptr + 8) == 0) {
                    result = 1;
                    break;
                }
                i += 1;
                ptr += 1;
            } while (i < *(u8 *)((u8 *)arg0 + 0x15));
        }
    }
    return result;
}

extern s32 D_882346F0;
extern s32 func_8800005C(void);
s32 func_88210ECC(void *arg0) {
    s32 result = 0;

    if (*(s32 *)(D_88234720 + 4) == 0) {
        if ((D_882346F0 == 0 && (*(s16 *)(D_88234720 + 8) == 1 || *(s16 *)(D_88234720 + 8) == 3)) || D_882346F0 == 3) {
            if (func_8800005C() != 0 && *(u8 *)D_88234720 == 1 && func_88210D48(arg0) != 0) {
                result = 1;
            } else if (func_88210DC4(arg0) != 0) {
                result = 2;
            } else if (func_88210E40(arg0) != 0) {
                result = 3;
            }
        }
    }
    return result;
}

extern s32 D_88234720;
extern s32 D_88A01C30;



s32 func_88210FAC(void) {
    s32 *list;
    s32 count;
    s32 result = 0;

    // The unk_D_88A01C30_20 rows start at D_88A01C30 + 0x20. Viewing the base as
    // 0x14-byte elements keeps the row start inside the element, so unk_00 lands
    // at +0x20 and unk_04[1] at +0x25.
    list = *(s32 **)(((u8 (*)[0x14])D_88A01C30)[1 - *(u8 *)D_88234720] + 0x20);
    count = ((u8 (*)[0x14])D_88A01C30)[1 - *(u8 *)D_88234720][0x25];
    while (count != 0) {
        count--;
        if (*(u8 *)(*list + 0x15) == 0) {
            result = 1;
            break;
        }
        list++;
    }
    return result;
}

extern s32 D_88234720;
extern s32 D_88A01C30;



s32 func_88211018(void) {
    s32 result;
    u8 *list;
    s32 count;
    u8 **entries;

    result = 1;
    entries = 0; // FAKE: dead store; starting entries' live range here gives it $v0 and moves
                 // list to $a0. Diff score 9 without it.
    // The opponent's row is rows[1 - idx] of the 0x14-byte array at D_88A01C30, formed as
    // (D_88A01C30 - idx * 0x14) + 0x14. The negated unsigned product is subtracted rather
    // than added so IDO emits negu/addu with D_88A01C30 in $t6 and the index in $t7; a plain
    // `+ (idx * 0x14) * 0xFFFFFFFFu` scores 6 with those two registers swapped.
    list = (u8 *)D_88A01C30 - (0 - ((*(u8 *)((u8 *)D_88234720) * 0x14) * 0xFFFFFFFFu));
    count = *(u8 *)(list + 0x39);
    // FAKE: empty if; with the guard below it places the loop test after the count load,
    // which keeps list in $a0, count in $a1 and entries in $v0. Diff score 9 without it.
    if (count == 0) {
    }
    list += 0x14;
    entries = *(u8 ***)(list + 0x20);
    if (count != 0) {
        do {
            if (*(u8 *)(*entries + 0x15) != 0) {
                result = 0;
                break;
            }
            entries++;
            count--;
        } while (count != 0);
    }
    return result;
}

extern u8 *func_800534FC(s32);
extern s8 *HAL_Strcpy(s8 *, s8 *);
extern s32 func_8004C594(s32, s32);
extern s32 func_8004C8A0(void *, s32, s32, s32);
void *func_88211084(void *arg0, void *arg1) {
    if ((*(u8 **)((u8 *)arg0 + 0))[8] == 2) {
        HAL_Strcpy((s8 *)arg1, (s8 *)func_800534FC(*(u8 *)((u8 *)arg0 + 4)));
    } else {
        func_8004C594(2, *(u8 *)((u8 *)arg0 + 4) + 1);
        func_8004C8A0(arg1, 0x40, 0x41, 0);
    }
    return arg1;
}

extern s32 HAL_Strcmp(const s8 *, const s8 *);
extern s8 **D_8823466C[];
s32 func_882110FC(void *arg0) {
    s32 result = 0;
    s8 text[0x20];
    s8 *value;

    value = func_88211084(arg0, text);
    if (HAL_Strcmp(D_8823466C[(*(u8 **)arg0)[8]][*(u8 *)((u8 *)arg0 + 4)], value) != 0) {
        result = 1;
    }
    return result;
}

/* mkdraft:func_88211168 begin */
typedef struct LabPCListExchangeMotion {
    /* 0x00 */ u8 *lists[2];
    /* 0x08 */ s8 rows[2];
    /* 0x0A */ u8 columns[2];
    /* 0x0C */ s32 rename;
    /* 0x10 */ s8 names[2][0x20];
} LabPCListExchangeMotion;

// Published through D_8800EF54; size 0x50.

extern s32 D_88234720;
extern void *D_8800EF54;
extern s8 **D_8823466C[];
s32 Util_Malloc(s32);
extern void func_800226C0(s32);
extern void func_88232820(s32);



void func_88211168(s32 arg0, s8 *arg1) {
    LabPCListExchangeMotion *motion;
    s16 start;
    s16 remaining;
    s32 mode;
    s32 i;

    start = ((unk_D_88234720 *)D_88234720)[*(u8 *)D_88234720].unk_16;
    mode = ((s16 *)(s32)D_88234720)[4] + 9;
    motion = Util_Malloc(0x50);
    motion->rename = arg0;
    switch (mode) {
    case 11:
        motion->lists[0] = func_882104DC(3, *(u8 *)D_88234720);
        motion->lists[1] = func_882104DC(1, *(u8 *)D_88234720);
        remaining = *(s16 *)(D_88234720 + 0x66) - start;
        if (remaining >= 0 && remaining < 9) {
            motion->rows[0] = remaining;
        } else {
            motion->rows[0] = -1;
        }
        motion->rows[1] = ((unk_D_88234720 *)D_88234720)[*(u8 *)D_88234720].unk_14 - start;
        motion->columns[0] = motion->columns[1] = *(u8 *)D_88234720;
        break;
    case 10:
    case 12:
        for (i = 0; i != 2; i++) {
            motion->lists[i] = func_882104DC(1, i);
            motion->rows[i] = ((unk_D_88234720 *)D_88234720)[i].unk_14 -
                              ((unk_D_88234720 *)D_88234720)[i].unk_16;
            motion->columns[i] = i;
        }
        break;
    case 13:
        motion->lists[0] = func_882104DC(1, *(u8 *)D_88234720);
        motion->lists[1] = NULL;
        motion->rows[0] = ((unk_D_88234720 *)D_88234720)[*(u8 *)D_88234720].unk_14 - start;
        motion->rows[1] = -1;
        motion->columns[0] = motion->columns[1] = *(u8 *)D_88234720;
        break;
    }
    if (arg0 != 0) {
        switch (mode) {
        case 11:
        case 12:
            for (i = 0; i != 2; i++) {
                if (func_882110FC(motion->lists[i]) != 0) {
                    HAL_Strcpy(motion->names[1 - i],
                               D_8823466C[(*(u8 **)motion->lists[i])[8]][motion->lists[i][4]]);
                } else {
                    func_88211084(motion->lists[1 - i], motion->names[1 - i]);
                }
            }
            break;
        case 10:
            HAL_Strcpy(motion->names[*(u8 *)D_88234720],
                       D_8823466C[(*(u8 **)motion->lists[1 - *(u8 *)D_88234720])[8]]
                                 [motion->lists[1 - *(u8 *)D_88234720][4]]);
            func_88211084(motion->lists[1 - *(u8 *)D_88234720],
                          motion->names[1 - *(u8 *)D_88234720]);
            break;
        case 13:
            HAL_Strcpy(motion->names[0], arg1);
            break;
        }
    }
    D_8800EF54 = motion;
    func_800226C0(0x63);
    func_88232820(mode);
}
/* mkdraft:func_88211168 end */

extern void func_800226C0(s32);
extern s32 D_88234724;
void func_88001900(void);
extern s32 D_882346F0;
void func_882114EC(void) {
    s16 temp_v1;

    func_800226C0(0x5E);
    func_88001900();
    D_882346F0 = 0;
    D_88234724 = 0;
    temp_v1 = (*(s16 *)((u8 *)(D_88234720) + (8)));
    if ((temp_v1 == 1) || (temp_v1 == 3)) {
        (*(u8 *)((u8 *)(D_88234720) + (0))) = (u8) ((*(u8 *)((u8 *)(D_88234720) + (0))) ^ 1);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_183700/func_88211550.s")

// Layout of the D_88234720 state, as in fragment31_186690's State18690.
//@src/fragments/31/fragment31_186690.c
typedef struct { u8 pad[8]; s16 position; s16 start; u16 count; u8 pad2[0x14]; s16 residual; u8 pad3[8]; } Scroll183700;
typedef struct { u8 slot; u8 reserved[0xB]; Scroll183700 records[2]; } State183700;
extern s32 D_882346F4;

// Same code as fragment31_186690's func_882152F4 on D_88234720; in mode 2 GS compares
// against the halfword at 0x66, and while D_88234724 is set it also accepts the mode-0
// match when the switch found none.
//@src/fragments/31/fragment31_186690.c
s32 func_88212440(u8 arg0, u8 arg1) {
    u32 index = arg0;
    State183700 *state;
    s32 result = 0;

    switch (D_882346F0) {
    default:
        goto done;
    case 0:
        if (D_882346F4 == 0) {
            goto done;
        }
        state = (State183700 *)D_88234720;
        if (arg0 != state->slot) {
            goto done;
        }
        if (arg1 == state->records[index].position - state->records[index].start) {
            result = 1;
            goto done;
        }
        goto done;
    case 1:
    case 3:
        state = (State183700 *)D_88234720;
        if (arg0 == state->slot) {
            goto done;
        }
        if (arg1 == state->records[index].position - state->records[index].start) {
            result = 1;
            goto done;
        }
        goto done;
    case 2:
        state = (State183700 *)D_88234720;
        if (arg0 != state->slot) {
            goto done;
        }
        if ((s16)arg1 == *(s16 *)((u8 *)state + 0x66) - state->records[index].start) {
            result = 1;
        }
        goto done;
    }
done:
    if (result == 0 && D_88234724 != 0) {
        state = (State183700 *)D_88234720;
        if (arg0 == state->slot && arg1 == state->records[index].position - state->records[index].start) {
            result = 1;
        }
    }
    return result;
}
extern Gfx *D_800D0510;
extern s32 D_882346F0;
extern s32 D_88234720;
extern s32 D_88A01C30;
s32 func_88210ECC(void *arg0);
s32 func_88212440(u8 arg0, u8 arg1);



void func_882125C0(u8 arg0, u8 arg1)
{
  s16 x;
  s16 y;
  s16 top;
  s16 bottom;
  u32 row;
  s32 *entry;

  entry = (s32 *) ((*((s32 *) ((((u8 *) ((u32) D_88A01C30)) + (arg0 * 0x14)) + 0x20))) + ((*((s16 *) ((((u8 *) ((u32) D_88234720)) + (((u32) arg0) * 0x2C)) + 0x16))) * 4));
  x = (!arg0) ? (0x34) : (0x16B);
  y = 0x7D - (*((s16 *) ((((u8 *) ((u32) D_88234720)) + (((u32) arg0) * 0x2C)) + 0x2E)));
  for (row = 0; row != arg1; row++, y += 0x1B)
  {
    top = y;
    bottom = y + 0x19;
    if (row == 0)
    {
      if (top < 0x7D)
      {
        top = 0x7D;
      }
    }
    else
      if (row == 9)
    {
      if (bottom >= 0x16F)
      {
        bottom = 0x16E;
      }
    }
    gDPPipeSync(D_800D0510++);
    if (row >= (*((u16 *) ((((u8 *) ((u32) D_88234720)) + (((u32) arg0) * 0x2C)) + 0x18))))
    {
      gDPSetFillColor(D_800D0510++, 0x39CF39CF);
    }
    else
      if (func_88212440(arg0, (u8) row) != 0)
    {
      if (((D_882346F0 == 1) || (D_882346F0 == 3)) || (arg0 == (*((u8 *) ((u32) D_88234720)))))
      {
        gDPSetFillColor(D_800D0510++, 0x2AFF2AFF);
      }
      else
      {
        gDPSetFillColor(D_800D0510++, 0x39D739D7);
      }
    }
    else
      if (((D_882346F0 == 1) || (D_882346F0 == 3)) || (arg0 == (*((u8 *) ((u32) D_88234720)))))
    {
      if ((func_88210ECC(*entry) != 0) && (arg0 == ((State183700 *) D_88234720)->slot))
      {
        gDPSetFillColor(D_800D0510++, 0x50075007);
      }
      else
      {
        gDPSetFillColor(D_800D0510++, 0x09A909A9);
      }
    }
    else
    {
      gDPSetFillColor(D_800D0510++, 0x39CF39CF);
    }
    gDPFillRectangle(D_800D0510++, x, top, x + 0xDE, bottom);
    bottom++;
    if (bottom < 0x16F)
    {
      gDPPipeSync(D_800D0510++);
      if (((D_882346F0 == 1) || (D_882346F0 == 3)) || (arg0 == (*((u8 *) ((u32) D_88234720)))))
      {
        gDPSetFillColor(D_800D0510++, 0x7D3F7D3F);
      }
      else
      {
        gDPSetFillColor(D_800D0510++, 0x63196319);
      }
      gDPFillRectangle(D_800D0510++, x, bottom, x + 0xDE, bottom);
    }
    entry++;
  }
}

extern void func_80047634(s32);
extern void func_80047650(s32);
extern void func_80048E30(s32, s16, s16, s32, s32);
extern void func_800496A4(s32, s32);
extern s32 D_8800687C;
void func_882129DC(s16 arg0, s16 arg1, s32 arg2) {
    func_800496A4(8, 2);
    func_80047634(1);
    func_80048E30(D_8800687C, arg0, arg1, arg2, 1);
    func_80047650(1);
}

extern void func_800495F8(s32, s32, s32, s32 *, s32);
void func_88212A3C(s16 arg0, s16 arg1, u8 arg2) {
    func_800496A4(4, 1);
    func_800495F8(arg0 + 0xD3, arg1 + 4, 2, "%d", (s32) arg2);
}

/* mkdraft:func_88212A94 begin */
extern s32 D_882346F0;
extern s32 D_88234720;
extern s32 D_88A01C30;
extern s8 **D_8823466C[];
extern s32 func_88005CC0(s32, void *);
extern s32 func_88210ECC(void *);
extern s32 func_88210D48(void *);
extern void func_88000488(s32, s32);
extern void func_882129DC(s16, s16, s32);
extern void func_88212A3C(s16, s16, u8);
extern s32 func_8800005C(void);

// Color filled by Color_SetRGB for a row that is drawn in the gray 150/150/150.
typedef struct {
    u8 red;
    u8 green;
    u8 blue;
} Color183700;

// Entry of the table at unk_D_88A01C30_20.unk_00, one per row of a scroll window:
// unk_00 is a pointer, unk_04 and unk_15 are the bytes this function reads. The
// remaining fields are not identified.
typedef struct {
    u8 *unk_00;
    u8 unk_04;
    u8 unk_05[0x10];
    u8 unk_15;
} unk_func_88212A94;

extern Color183700 D_88005FA0;
extern void func_880006E0(Color183700 *);
extern Color183700 *Color_SetRGB(Color183700 *, s32, s32, s32);

// Draw the rows of one column's scroll window that are visible in the list: each row is
// 27 pixels tall, the first row sits at y = 128 above the window's residual offset, and
// only limit rows are drawn.
void func_88212A94(u8 column, u8 limit) {
    s16 x;
    s16 y;
    u32 row;
    Color183700 gray;
    unk_func_88212A94 **entry;

    entry = (unk_func_88212A94 **)(((unk_D_88A01C30_20 *)(D_88A01C30 + 0x20))[column].unk_00 +
                                   ((State183700 *)D_88234720)->records[column].start);
    x = column == 0 ? 58 : 369;
    limit = limit < ((State183700 *)D_88234720)->records[column].count
                ? limit
                : ((State183700 *)D_88234720)->records[column].count;
    row = 0;
    y = 128 - ((State183700 *)D_88234720)->records[column].residual;
    for (; row != limit; entry++, row++, y += 27) {
        if (D_882346F0 == 1 || D_882346F0 == 3 || column == *(u8 *)D_88234720) {
            if ((func_88210ECC(*entry) != 0 && column == ((State183700 *)D_88234720)->slot) ||
                (*(s32 *)(D_88234720 + 4) == 0 &&
                 ((*(s16 *)(D_88234720 + 8) == 0 && (*entry)->unk_15 == 0) ||
                  (*(s16 *)(D_88234720 + 8) == 1 && (*entry)->unk_15 == 0 && D_882346F0 == 0) ||
                  (D_882346F0 == 1 && column == ((State183700 *)D_88234720)->slot && (*entry)->unk_15 != 0) ||
                  (*(s16 *)(D_88234720 + 8) == 2 && (*entry)->unk_15 == 0 && D_882346F0 == 0) ||
                  (*(s16 *)(D_88234720 + 8) == 3 && (*entry)->unk_15 == 0) ||
                  (*(s16 *)(D_88234720 + 8) == 4 && func_8800005C() != 0 && *(u8 *)D_88234720 == 0)))) {
                func_880006E0(Color_SetRGB(&gray, 150, 150, 150));
            } else {
                func_880006E0(&D_88005FA0);
            }
        } else {
            func_880006E0(Color_SetRGB(&gray, 150, 150, 150));
        }
        if (func_88005CC0(11, *entry) == 0 &&
            func_88005CC0(12, *entry) == 0 &&
            func_88005CC0(10, *entry) == 0 &&
            func_88005CC0(13, *entry) == 0) {
            if (func_88210D48(*entry) != 0) {
                func_88000488(D_88234720 + 0x74, 1);
            }
            func_882129DC(x, y, (s32)D_8823466C[(*entry)->unk_00[8]][(*entry)->unk_04]);
            func_88000488(D_88234720 + 0x74, 0);
            func_88212A3C(x, y, (*entry)->unk_15);
        }
    }
}
/* mkdraft:func_88212A94 end */

extern s16 D_8800EF58;
extern s32 func_8004C874(s32, s32);
extern void func_80049064(s32, s32, s32, s32);
extern void func_80048E30(s32, s16, s16, s32, s32);
extern void func_800496A4(s32, s32);
void func_88212E00(void) {
    if (D_8800EF58 == 0 && D_882346F0 == 0) {
        func_800496A4(4, 2);
        func_80049064(0x247, 0x1A4, 2, func_8004C874(0x22, 0x17));
    }
    func_800496A4(0x10, 2);
    func_80048E30(D_8800687C, 0x39, 0x19C, func_8004C874(0x22, *(s16 *)((u8 *)D_88234720 + 8)), 1);
}

extern s32 D_88234564;
extern s32 D_88234720;
extern s16 D_8800EF58;
extern Gfx *D_800D0510;
extern Gfx D_80094DE0[];
extern Gfx D_80094E00[];
extern Gfx D_80094F50[];
extern s32 D_880068B8;
extern u8 D_88233800;
extern u8 D_8800686C;
extern s32 D_882345C8;
extern s16 Envelope_Advance();
extern s32 func_80001FF0(void);
extern void func_80006F70();
extern void func_800498C4(void);
extern void func_800499EC(void);
extern s32 func_8004D19C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_880002F4(u8 *arg0, s16 arg1);
extern u8 *func_88000308(u8 *arg0, s16 arg1);
extern void func_880006BC(u8 *arg0);
extern s32 func_88000808();
extern u8 func_880032C4(void);
extern void func_88005C7C(void);
extern void func_88005F08(void);
extern void func_88206668(void);
extern s32 func_88206714();
extern s32 func_88206CC0();
extern void func_88207D14(u8 *arg0);
extern s32 func_88207D80();
extern void func_882125C0(u8 arg0, u8 arg1);


void func_88212EA0(void)
{
  u32 i;
  s32 values[2];
  s32 *p;          /* unused; its auto slot is what fixes the frame at 0x80 with values at 0x74 and sp68 at 0x68 */
  u8 *rec;
  u8 sp68[4];

  if (D_880068B8 != 0)
  {
    if ((*((s32 *) (((u8 *) ((u32) D_88234564)) + 0x1C))) != 2)
    {
      func_88206668();
      return;
    }
    if ((*((s32 *) (((u8 *) ((u32) D_88234564)) + 0xA4))) != 2)
    {
      func_88206714(&D_88233800, *((u8 *) (((u8 *) ((u32) D_88234720)) + 0)));
      func_800498C4();
      func_88212E00();
      func_800499EC();
      return;
    }
    func_88207D14(((u8 *) ((u32) D_88234720)) + 0x64);
    for (i = 0, rec = (u8 *) ((u32) D_88234720); i < 2; i++, rec += 0x2C)
    {
      if ((*((s16 *) (rec + 0x2E))) == 0)
      {
        *(s32 *) ((u8 *) values + i * 4) = 9;
      }
      else
      {
        *(s32 *) ((u8 *) values + i * 4) = 10;
      }
    }

    gSPDisplayList(D_800D0510++, D_80094DE0);
    for (i = 0; i < 2; i++)
    {
      func_882125C0(i, *((u8 *) ((((u8 *) values) + (i * 4)) + 3)));
    }

    func_88005C7C();
    func_88206CC0(&D_88233800, *((u8 *) (((u8 *) ((u32) D_88234720)) + 0)), *((s32 *) (((u8 *) ((u32) D_88234720)) + 4)), *((s16 *) (((u8 *) ((u32) D_88234720)) + 8)), ((u8 *) ((u32) D_88234720)) + 0xC, ((u8 *) ((u32) D_88234720)) + 0x38, &D_88000E4C);
 do { gSPDisplayList(D_800D0510++, D_80094E00); func_88000808(D_8800686C, 0x46, 0x50, 1, 0x200000); func_8004D19C(0x238, 0x50, D_882345C8, 1, 0x200000); gSPDisplayList(D_800D0510++, D_80094F50); func_800498C4(); } while (0);
    func_880006BC((u8 *)&D_88005FA0);
    *((s32 *) (((u8 *) ((u32) D_88234720)) + 0x74)) = 0;
    if ((func_880032C4() != 0) || (D_8800EF58 != 0))
    {
      func_880002F4(((u8 *) ((u32) D_88234720)) + 0x68, (((s32) (((5.0f * func_80001FF0()) / 60.0f) + ((((func_80001FF0() * 5.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f)))) + ((s32) (((8.0f * func_80001FF0()) / 60.0f) + ((((func_80001FF0() * 8.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f))))) + ((s32) (((30.0f * func_80001FF0()) / 60.0f) + ((((func_80001FF0() * 30.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f)))));
    }
    func_88000308(sp68, Envelope_Advance(((u8 *) ((u32) D_88234720)) + 0x68));
    { Gfx *primg = D_800D0510++; primg->words.w0 = 0xFA000000; primg->words.w1 = _SHIFTL(sp68[1], 16, 8) | _SHIFTL(sp68[2], 8, 8) | _SHIFTL(sp68[0], 24, 8) | _SHIFTL(0xFF, 0, 8); }
    func_800496A4(4, 1);
    for (i = 0; i != 2; i++)
    {
      func_80049064(0xA9 + i * 0x12C, 0x53, 1, func_8004C874(0x22, i + 0x15));
    }

    func_80006F70(&D_800D0510, 0x34, 0x7D, 0xDF, 0xF2);
    func_88212A94(0, *((u8 *) (((u8 *) values) + 3)));
    func_80006F70(&D_800D0510, 0x16B, 0x7D, 0xDF, 0xF2);
    func_88212A94(1, *((u8 *) (((u8 *) values) + 7)));
    func_80006F70(&D_800D0510, 0x2C, 0x48, 0x229, 0x17F);
    func_880006E0(&D_88005FA0);
    func_88212E00();
    func_88005F08();
    func_800499EC();
    func_88207D80(*((u8 *) (((u8 *) ((u32) D_88234720)) + 0)), *((s32 *) (((u8 *) ((u32) D_88234720)) + 4)), *((s16 *) (((u8 *) ((u32) D_88234720)) + 8)), ((u8 *) ((u32) D_88234720)) + 0xC, ((u8 *) ((u32) D_88234720)) + 0x38, func_880032C4() == 0);
  }
}
#endif
