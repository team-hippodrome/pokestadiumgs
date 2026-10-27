#include "global.h"


#ifdef VERSION_US
extern s8 D_88601894;
extern s8 D_88601895;
extern s8 D_883087C0[17];
extern s8 D_883087D4[18];
// Returns the entry at (base + offset) wrapped into the table length: list 0 uses base
// D_88601894 with the 17-entry D_883087C0, list 1 uses D_88601895 with the 18-entry D_883087D4.
s32 func_88307AD0(s32 list, s8 offset) {
    s8 result;
    s8 index;

    switch (list) {
        case 0:
            index = D_88601894 + offset;
            while (index >= 17) {
                index -= 17;
            }
            while (index < 0) {
                index += 17;
            }
            result = D_883087C0[index];
            break;
        case 1:
            index = D_88601895 + offset;
            while (index >= 18) {
                index -= 18;
            }
            while (index < 0) {
                index += 18;
            }
            result = D_883087D4[index];
            break;
    }
    //!bug result is uninitialized when list is neither 0 nor 1.
    return result;
}

extern s32 func_88307AD0(s32, s8);
extern void *func_8004C874(s32, s32);
extern s32 func_80063270(u8);
s32 func_88307BCC(s32 arg0, u8 arg1) {
    s32 value = func_88307AD0(arg0, arg1);
    s8 narrowed = value;
    s32 result;

    if (value == -1) {
        result = (s32)func_8004C874(0x28, 0x24);
    } else {
        result = func_80063270(narrowed);
    }
    return result;
}

/* mkdraft:func_88307C2C begin */
extern float sqrtf(float value);
extern s32 D_88308ED0;
extern s32 D_88308EF0;
extern s8 D_88601894;
extern s8 D_88601895;

void func_88307C2C(void)
{
  float new_var;
  s32 sp30;
  f32 var_fv0;
  float new_var4;
  f32 var_fv0_2;
  f32 new_var2;
  int new_var3;
  sp30 = func_80001FF0();
  if ((1800.0f / ((f32) func_80001FF0())) > 0.0f)
  {
    var_fv0 = 0.5f;
  }
  else
  {
    var_fv0 = -0.5f;
  }
  new_var4 = 1800.0f / ((f32) sp30);
  func_880024FC(&D_88308ED0, &D_88601894, 0x11, 0x8C, (s32) (var_fv0 + new_var4), 0xA, 0x300, 0xE, 0x4B);
  sp30 = func_80001FF0();
  if (new_var3 = (1800.0f / (new_var2 = (f32) func_80001FF0())) > 0.0f)
  {
    var_fv0_2 = 0.5f;
  }
  else
  {
    var_fv0_2 = -0.5f;
  }
  new_var = 1800.0f / ((f32) sp30);
  new_var = var_fv0_2 + new_var;
  func_880024FC(&D_88308EF0, &D_88601895, 0x12, 0x8C, (s32) new_var, 0xA, 0x300, 0xE, 0x4B);
}
/* mkdraft:func_88307C2C end */

extern s8 D_88308EB1;
extern void func_88002640(void *);

void func_88307DA4(void) {
    switch (D_88308EB1) {
    case 0:
    case 1:
        func_88002640((u8 *)&D_88308ED0 + D_88308EB1 * 32);
        break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B8DE0/func_88307DE8.s")

typedef struct unk_D_88308ED0 {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u8 unk_06[2];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8 unk_0C[0xA];
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ u8 unk_18[8];
} unk_D_88308ED0; // size = 0x20

s32 func_88307F28(void) {
    s32 first;
    s32 second;
    s32 result;

    if (((unk_D_88308ED0 *)&D_88308ED0)[0].unk_04 == 0 && ((unk_D_88308ED0 *)&D_88308ED0)[0].unk_08 == 0 && ((unk_D_88308ED0 *)&D_88308ED0)[0].unk_16 == 0) {
        first = 1;
    } else {
        first = 0;
    }
    result = first != 0;
    if (result) {
        if (((unk_D_88308ED0 *)&D_88308ED0)[1].unk_04 == 0 && ((unk_D_88308ED0 *)&D_88308ED0)[1].unk_08 == 0 && ((unk_D_88308ED0 *)&D_88308ED0)[1].unk_16 == 0) {
            second = 1;
        } else {
            second = 0;
        }
        result = second != 0;
    }
    return result;
}
#endif
