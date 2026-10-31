#include "global.h"


#ifdef VERSION_US
extern s8 D_8800ED30; extern s8 D_8800ED31;
void func_88001900(void) { D_8800ED30 = 10; D_8800ED31 = 1; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/29/fragment29_167940/func_8800191C.s")

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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/29/fragment29_167940/func_88001D0C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/29/fragment29_167940/func_88001EBC.s")

/* mkdraft:func_880020CC begin */
s16 func_8800191C();
s32 func_88001EBC(void *);
extern void *D_80087200;


void func_880020CC(void *arg0)
{
  s16 temp_v0;
  s16 temp_v1;
  if ((*((s32 *) (((u8 *) arg0) + 4))) == 0)
  {
    temp_v0 = func_8800191C();
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
