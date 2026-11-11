#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern s8 D_8800ED30; extern s8 D_8800ED31;
void func_88001900(void) { D_8800ED30 = 10; D_8800ED31 = 1; }

extern void func_800226C0(s32);
// Select an enabled pressed direction, then repeat held D-pad directions after
// the shared delay. Bounds suppress the movement sound; the key is still returned.
s16 func_8800191C(void *arg0) {
    s16 key = 0;
    s16 enabled = *(s16 *)((u8 *)arg0 + 36);
    s32 at_bound;

    if ((enabled & 0x800) && (D_80087200->buttonsPressed & 0x800)) {
        key = 0x800;
    } else if ((enabled & 0x400) && (D_80087200->buttonsPressed & 0x400)) {
        key = 0x400;
    } else if ((enabled & 0x200) && (D_80087200->buttonsPressed & 0x200)) {
        key = 0x200;
    } else if ((enabled & 0x100) && (D_80087200->buttonsPressed & 0x100)) {
        key = 0x100;
    } else if ((enabled & 8) && (D_80087200->buttonsPressed & 8)) {
        key = 8;
    } else if ((enabled & 4) && (D_80087200->buttonsPressed & 4)) {
        key = 4;
    }
    if (key != 0) {
        func_88001900();
        if (key == 8 || key == 0x200 || key == 0x800) {
            if (*(s16 *)((u8 *)arg0 + 8) == 0) {
                at_bound = 1;
            } else {
                at_bound = 0;
            }
            if (at_bound == 0) {
                func_800226C0(*(s32 *)((u8 *)arg0 + 40));
            }
        } else {
            if (*(u16 *)((u8 *)arg0 + 12) == *(s16 *)((u8 *)arg0 + 8) + 1) {
                at_bound = 1;
            } else {
                at_bound = 0;
            }
            if (at_bound == 0) {
                func_800226C0(*(s32 *)((u8 *)arg0 + 40));
            }
        }
    } else {
        D_8800ED30--;
        if (D_8800ED30 <= 0) {
            D_8800ED30 = 0;
            if ((enabled & 0x800) && (D_80087200->buttonsHeld & 0x800)) {
                key = 0x800;
            } else if ((enabled & 0x400) && (D_80087200->buttonsHeld & 0x400)) {
                key = 0x400;
            } else if ((enabled & 0x200) && (D_80087200->buttonsHeld & 0x200)) {
                key = 0x200;
            } else if ((enabled & 0x100) && (D_80087200->buttonsHeld & 0x100)) {
                key = 0x100;
            }
            if (key != 0) {
                D_8800ED30 = 1;
                D_8800ED31--;
                if (D_8800ED31 <= 0) {
                    if (key != 0x400 && key != 0x800) {
                        D_8800ED31 = 5;
                    } else {
                        D_8800ED31 = 2;
                    }
                    if (*(s16 *)((u8 *)arg0 + 8) == 0) {
                        at_bound = 1;
                    } else {
                        at_bound = 0;
                    }
                    if (at_bound == 0) {
                        if (*(u16 *)((u8 *)arg0 + 12) == *(s16 *)((u8 *)arg0 + 8) + 1) {
                            at_bound = 1;
                        } else {
                            at_bound = 0;
                        }
                        if (at_bound == 0) {
                            func_800226C0(*(s32 *)((u8 *)arg0 + 40));
                        }
                    }
                }
            }
        }
    }
    return key;
}

void func_88001C24(void *arg0, u16 arg1, u8 arg2) {
    u16 var_v1;

    if (arg1 == 0) {
        (*(u16 *)((u8 *)(arg0) + 0xC)) = 1U;
    } else {
        (*(u16 *)((u8 *)(arg0) + 0xC)) = arg1;
    }
    var_v1 = (*(u16 *)((u8 *)(arg0) + 0xC));
    if (arg2 < var_v1) {
        (*(u8 *)((u8 *)(arg0) + 0xE)) = arg2;
        return;
    }
    // FAKE: the (s8) cast stores the same byte either way, but its uopt
    // conversion temp claims v0, which keeps the 0xC reload colored v1.
    (*(u8 *)((u8 *)(arg0) + 0xE)) = (s8) var_v1;
}
void func_88001C6C(void *arg0, u16 arg1, u8 arg2, s16 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s32 arg10) {
    (*(u16 *)((u8 *)(arg0) + 0x0)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x4)) = 0;
    (*(u16 *)((u8 *)(arg0) + 0x8)) = 0;
    (*(u16 *)((u8 *)(arg0) + 0xA)) = 0;
    (*(u8 *)((u8 *)(arg0) + 0xF)) = arg4;
    (*(s16 *)((u8 *)(arg0) + 0x10)) = arg3;
    (*(s16 *)((u8 *)(arg0) + 0x12)) = arg3;
    (*(u16 *)((u8 *)(arg0) + 0x14)) = 0;
    (*(s16 *)((u8 *)(arg0) + 0x16)) = arg5;
    (*(s16 *)((u8 *)(arg0) + 0x18)) = arg6;
    (*(s16 *)((u8 *)(arg0) + 0x1A)) = arg7;
    (*(s16 *)((u8 *)(arg0) + 0x1C)) = arg8;
    (*(u16 *)((u8 *)(arg0) + 0x1E)) = 0;
    (*(u16 *)((u8 *)(arg0) + 0x20)) = 0;
    (*(u16 *)((u8 *)(arg0) + 0x22)) = 0;
    (*(s16 *)((u8 *)(arg0) + 0x24)) = arg9;
    (*(s32 *)((u8 *)(arg0) + 0x28)) = arg10;
    func_88001C24(arg0, arg1, arg2);
    func_88001900();
}
/* mkdraft:func_88001D0C begin */


void func_88001D0C(void *arg0) {
    f32 temp_fv0;
    f32 var_fv1;
    s16 temp_a2;
    s16 temp_a2_2;
    s16 pos;

    if (*(s16 *)((u8 *)arg0 + 0x22) < 0) {
        do {
            *(s16 *)((u8 *)arg0 + 0x22) = *(u8 *)((u8 *)arg0 + 0xF) + *(s16 *)((u8 *)arg0 + 0x22);
            *(s16 *)((u8 *)arg0 + 0xA) = *(s16 *)((u8 *)arg0 + 0xA) - 1;
        } while (*(s16 *)((u8 *)arg0 + 0x22) < 0);
    }
    if (*(s16 *)((u8 *)arg0 + 0xA) < 0) {
        *(s16 *)((u8 *)arg0 + 0x10) = *(s16 *)((u8 *)arg0 + 0x22) + (*(s16 *)((u8 *)arg0 + 0x10) - (*(u8 *)((u8 *)arg0 + 0xF) * -*(s16 *)((u8 *)arg0 + 0xA)));
        *(s16 *)((u8 *)arg0 + 0xA) = 0;
        *(s16 *)((u8 *)arg0 + 0x22) = 0;
    }
    while (*(s16 *)((u8 *)arg0 + 0x22) >= *(u8 *)((u8 *)arg0 + 0xF)) {
        *(s16 *)((u8 *)arg0 + 0x22) = *(s16 *)((u8 *)arg0 + 0x22) - *(u8 *)((u8 *)arg0 + 0xF);
        *(s16 *)((u8 *)arg0 + 0xA) = *(s16 *)((u8 *)arg0 + 0xA) + 1;
    }
    temp_a2 = (s16) (*(u8 *)((u8 *)arg0 + 0xE) + (*(s16 *)((u8 *)arg0 + 0xA) - *(u16 *)((u8 *)arg0 + 0xC)));
    if (temp_a2 >= 0) {
        *(s16 *)((u8 *)arg0 + 0x10) = *(s16 *)((u8 *)arg0 + 0x22) + (temp_a2 * *(u8 *)((u8 *)arg0 + 0xF) + *(s16 *)((u8 *)arg0 + 0x10));
        *(s16 *)((u8 *)arg0 + 0xA) = *(u16 *)((u8 *)arg0 + 0xC) - *(u8 *)((u8 *)arg0 + 0xE);
        *(s16 *)((u8 *)arg0 + 0x22) = 0;
    }
    if (*(s16 *)((u8 *)arg0 + 0x10) < *(s16 *)((u8 *)arg0 + 0x12)) {
        *(s16 *)((u8 *)arg0 + 0x10) = *(s16 *)((u8 *)arg0 + 0x12);
    } else {
        temp_a2_2 = (s16) (*(u8 *)((u8 *)arg0 + 0xF) * (*(u8 *)((u8 *)arg0 + 0xE) - 1) + *(s16 *)((u8 *)arg0 + 0x12));
        if (temp_a2_2 < *(s16 *)((u8 *)arg0 + 0x10)) {
            *(s16 *)((u8 *)arg0 + 0x10) = temp_a2_2;
        }
    }
    temp_fv0 = (f32) ((*(s16 *)((u8 *)arg0 + 0x10) - *(s16 *)((u8 *)arg0 + 0x12)) + *(s16 *)((u8 *)arg0 + 0x22)) / (f32) *(u8 *)((u8 *)arg0 + 0xF);
    if (temp_fv0 > 0.0f) {
        var_fv1 = 0.5f;
    } else {
        var_fv1 = -0.5f;
    }
    pos = *(s16 *)((u8 *)arg0 + 0xA);
    *(s16 *)((u8 *)arg0 + 0x8) = (s16) ((s32) (var_fv1 + temp_fv0) + pos);
}
/* mkdraft:func_88001D0C end */

/* mkdraft:func_88001EBC begin */
extern void func_88001D0C(void *);

/* m2c field-access helper (see matching_notes/TECHNIQUES.md). */
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))

// Tail of the 0x400/0x800 arm: temp_a1_2 is the 0x12 field plus the product of
// the 0xE and 0xF bytes, truncated to s16 by the comparison below.  The product
// is spelled 0xF * (0xE - 1) so the product compiles to `multu t9,t2`, and it is
// accumulated with `+=` so cfe keeps temp_v1_2 as the add's left operand
// (`addu a1,v1,t1`); written as one expression, cfe builds the mpy node first
// and the sum comes out as `addu a1,t1,v1`.



void func_88001EBC(void *arg0) {
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_a1_3;
    s32 temp_v0_2;
    s16 temp_v0_3;
    s32 temp_v0_4;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 count;
    s16 count_2;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_2;
    s32 var_v0_4;

    var_v0 = M2C_FIELD(arg0, s16 *, 0);
    if ((var_v0 != 4) && (var_v0 != 8) && (var_v0 != 0x100) && (var_v0 != 0x200)) {
        if ((var_v0 == 0x400) || (var_v0 == 0x800)) {
            temp_v1 = M2C_FIELD(arg0, s16 *, 0x14);
            var_v0 = temp_v1;
            M2C_FIELD(arg0, s16 *, 0x10) = (s16) (M2C_FIELD(arg0, s16 *, 0x10) + temp_v1);
            var_v0 = (temp_v1 < 0) ? -temp_v1 : temp_v1;
            temp_a1 = M2C_FIELD(arg0, s16 *, 0x20);
            M2C_FIELD(arg0, s16 *, 0x1E) = (s16) (M2C_FIELD(arg0, s16 *, 0x1E) + var_v0);
            count = M2C_FIELD(arg0, s16 *, 0x1E);
            if (count >= temp_a1) {
                do {
                    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
                        temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x14);
                        M2C_FIELD(arg0, s16 *, 0x14) = 0;
                        M2C_FIELD(arg0, s32 *, 4) = 0;
                        M2C_FIELD(arg0, s16 *, 0) = 0;
                        temp_v0_2 = temp_v0_2 < 0;
                        var_v0_2 = temp_v0_2 ? -1 : 1;
                        M2C_FIELD(arg0, s16 *, 0x1E) = 0;
                        M2C_FIELD(arg0, s16 *, 0x10) = (s16) (M2C_FIELD(arg0, s16 *, 0x10) - (var_v0_2 * (count - temp_a1)));
                    } else {
                        M2C_FIELD(arg0, s16 *, 0x1E) = (s16) (count - temp_a1);
                    }
                    count = M2C_FIELD(arg0, s16 *, 0x1E);
                } while (count >= temp_a1);
            }
            temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x10);
            temp_v1_2 = M2C_FIELD(arg0, s16 *, 0x12);
            if (temp_v0_3 < temp_v1_2) {
                M2C_FIELD(arg0, s16 *, 0x22) = (s16) ((M2C_FIELD(arg0, s16 *, 0x22) - temp_v1_2) + temp_v0_3);
            } else {
                temp_a1_2 = temp_v1_2;
                temp_a1_2 += (M2C_FIELD(arg0, u8 *, 0xF) * (M2C_FIELD(arg0, u8 *, 0xE) - 1));
                if (temp_a1_2 < temp_v0_3) {
                    M2C_FIELD(arg0, s16 *, 0x22) = (s16) ((M2C_FIELD(arg0, s16 *, 0x22) + temp_v0_3) - temp_a1_2);
                }
            }
        }
    } else {
        temp_v1_3 = M2C_FIELD(arg0, s16 *, 0x14);
        var_v0 = temp_v1_3;
        M2C_FIELD(arg0, s16 *, 0x22) = (s16) (M2C_FIELD(arg0, s16 *, 0x22) + temp_v1_3);
        var_v0 = (temp_v1_3 < 0) ? -temp_v1_3 : temp_v1_3;
        temp_a1_3 = M2C_FIELD(arg0, s16 *, 0x20);
        M2C_FIELD(arg0, s16 *, 0x1E) = (s16) (M2C_FIELD(arg0, s16 *, 0x1E) + var_v0);
        count_2 = M2C_FIELD(arg0, s16 *, 0x1E);
        if (count_2 >= temp_a1_3) {
            do {
                if (M2C_FIELD(arg0, s32 *, 4) != 0) {
                    temp_v0_4 = M2C_FIELD(arg0, s16 *, 0x14);
                    M2C_FIELD(arg0, s16 *, 0x14) = 0;
                    M2C_FIELD(arg0, s32 *, 4) = 0;
                    M2C_FIELD(arg0, s16 *, 0) = 0;
                    temp_v0_4 = temp_v0_4 < 0;
                    var_v0_4 = temp_v0_4 ? -1 : 1;
                    M2C_FIELD(arg0, s16 *, 0x1E) = 0;
                    M2C_FIELD(arg0, s16 *, 0x22) = (s16) (M2C_FIELD(arg0, s16 *, 0x22) - (var_v0_4 * (count_2 - temp_a1_3)));
                } else {
                    M2C_FIELD(arg0, s16 *, 0x1E) = (s16) (count_2 - temp_a1_3);
                }
                count_2 = M2C_FIELD(arg0, s16 *, 0x1E);
            } while (count_2 >= temp_a1_3);
        }
    }
    func_88001D0C(arg0);
}
/* mkdraft:func_88001EBC end */

/* mkdraft:func_880020CC begin */
s16 func_8800191C(void *);
void func_88001EBC(void *);


void func_880020CC(void *arg0)
{
  s16 temp_v0;
  s16 temp_v1;
  if ((*((s32 *) (((u8 *) arg0) + 4))) == 0)
  {
    temp_v0 = func_8800191C(arg0);
    temp_v1 = *((s16 *) (((u8 *) arg0) + 0));
    if (temp_v0 != temp_v1)
    {
      if (temp_v1 == 0)
      {
        *((s16 *) (((u8 *) arg0) + 0)) = temp_v0;
        /* The case labels are deliberately written in DESCENDING order.  IDO sorts the
           emitted compare chain ascending (4, 8, 0x100, 0x200, 0x400, 0x800) but emits
           the bodies in source order; together with the switch's direct `break` join
           this reproduces the retail block layout and lets as1 fill the final store
           into the branch delay slot (a nested if/else chain leaves a join label
           between the store and the branch, costing one `nop`). */
        switch (temp_v0)
        {
        case 0x800:
          *((s16 *) (((u8 *) arg0) + 0x20)) = (s16) (*((u8 *) (((u8 *) arg0) + 0xF)));
          if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x800)
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = (s16) (-(*((s16 *) (((u8 *) arg0) + 0x16))));
          }
          else
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = (s16) (-(*((s16 *) (((u8 *) arg0) + 0x18))));
          }
          break;
        case 0x400:
          *((s16 *) (((u8 *) arg0) + 0x20)) = (s16) (*((u8 *) (((u8 *) arg0) + 0xF)));
          if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x400)
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = *((s16 *) (((u8 *) arg0) + 0x16));
          }
          else
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = *((s16 *) (((u8 *) arg0) + 0x18));
          }
          break;
        case 8:
        case 0x200:
          *((s16 *) (((u8 *) arg0) + 0x20)) = (s16) ((*((u8 *) (((u8 *) arg0) + 0xE))) * (*((u8 *) (((u8 *) arg0) + 0xF))));
          if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x208)
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = (s16) (-(*((s16 *) (((u8 *) arg0) + 0x1A))));
          }
          else
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = (s16) (-(*((s16 *) (((u8 *) arg0) + 0x1C))));
          }
          break;
        case 4:
        case 0x100:
          *((s16 *) (((u8 *) arg0) + 0x20)) = (s16) ((*((u8 *) (((u8 *) arg0) + 0xE))) * (*((u8 *) (((u8 *) arg0) + 0xF))));
          if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x104)
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = *((s16 *) (((u8 *) arg0) + 0x1A));
          }
          else
          {
            *((s16 *) (((u8 *) arg0) + 0x14)) = *((s16 *) (((u8 *) arg0) + 0x1C));
          }
          break;
        }
      }
      else
      {
        *((s32 *) (((u8 *) arg0) + 4)) = 1;
      }
    }
  }
  func_88001EBC(arg0);
}
/* mkdraft:func_880020CC end */

extern void func_88001D0C(void*);
void func_8800225C(void* arg0, s16 arg1, s16 arg2) {
    *(s16*)((u8*)arg0 + 10) = arg1;
    *(s16*)((u8*)arg0 + 8) = arg2;
    *(s16*)((u8*)arg0 + 16) = (arg2 - arg1) * *(u8*)((u8*)arg0 + 15) + *(s16*)((u8*)arg0 + 18);
    func_88001D0C(arg0);
}

void func_880022B4(void *arg0, s16 arg1, s32 arg2) {
    if (arg2 == 0) {
        (*(s16 *)((u8 *)(arg0) + (0x24))) = (s16) ((*(s16 *)((u8 *)(arg0) + (0x24))) & ~arg1);
        return;
    }
    (*(s16 *)((u8 *)(arg0) + (0x24))) = (s16) ((*(s16 *)((u8 *)(arg0) + (0x24))) | arg1);
}
#endif
