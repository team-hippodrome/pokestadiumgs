#include "global.h"


#ifdef VERSION_US
extern s32 D_880068B8;
void func_8822C2F0(void) {
    D_880068B8 = 0;
}

void func_8822C2FC(void) {
    D_880068B8 = 1;
}

extern u8 *fragment38_main(void);
extern s8 *HAL_Strcpy(s8 *, s8 *);
extern void func_88900494(void);
extern s32 func_8821C0B0(void);
extern void func_8822AF00(s8 *);
extern void func_88001900(void);
extern s32 D_880068B4;

void func_8822C30C(void) {
    s8 text[0x20];

    HAL_Strcpy(text, (s8 *)fragment38_main());
    func_88900494();
    if (func_8821C0B0() == 0) {
        func_8822AF00(text);
    } else {
        func_88001900();
        D_880068B4 = 1;
    }
}

extern u8 *D_882345F4;
extern s8 D_88006868;
extern s32 func_80001FF0(void);
extern void LabPC_InitEvolutionView(void);
extern u8 LabPC_OpenEvolutionView(s32, u8 *, s32, s32, void *, void *, void *, s32);
extern void func_8822C2F0(void);
extern void func_8822C2FC(void);
extern void func_8822C30C(void);
extern s32 D_880068B4;
void func_8822C374(s32 arg0) {
    LabPC_InitEvolutionView();
    LabPC_OpenEvolutionView(arg0, D_882345F4 + 8, D_88006868, (**(u8 ***)D_882345F4)[8] == 2,
                            func_8822C2F0, func_8822C30C, func_8822C2FC,
                            (u16)(u32)((f32)func_80001FF0() * 0.5f / 2));
    D_880068B4 = 0;
}

extern u8 **D_88234920;
extern void func_80049064(s32, s32, s32, const char *);
extern void *func_8004C874(s32, s32);
extern s32 func_8800005C(void);

void func_8822C4A0(void) {
    s32 sp1C;
    s32 var_a1;

    switch (*(s16 *)((u8 *) D_88234920 + 0x40)) {
    case 0:
        if (func_8800005C() != 0) {
            var_a1 = 0x16;
        } else {
            var_a1 = 0x17;
        }
        break;
    case 1:
        var_a1 = 0x18;
        break;
    case 2:
        var_a1 = 0x19;
        break;
    case 3:
        var_a1 = 0x1A;
        break;
    default:
        var_a1 = sp1C;
        break;
    }
    func_80049064(0x140, 0x183, 1, func_8004C874(0x21, var_a1));
}
extern void Input_SetRepeatController(void *);
extern void *D_80087200;
extern s32 D_88234714;
void func_8822C53C(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
    D_88234714 = 1;
}

extern void Util_Free(s32);
extern s32 D_880068B4;
extern u8 **D_88234920;
void func_8822C570(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(*(volatile void **)(&D_88234920));
}

extern void func_88004990(u8, s32);

void func_8822C5AC(void) {
    func_88004990(**D_88234920, 0);
    D_880068B8 = 1;
    D_88234714 = 0;
}

typedef struct {
    u8 unk_00[4];
    u8 unk_04;
    u8 unk_05[0x1F];
    u16 unk_24;
    u8 unk_26[0x1A];
    s16 cursor;    // func_88002720 moves it; func_8822C4A0 switches on it
    u8 unk_42[0xA];
    u8 unk_4C[1];  // per-cursor byte; nonzero rejects A with sound 73
} unk_D_88234920;
extern u8 D_88006020[];
// A plays sound 73 if unk_4C[cursor] is set, otherwise passes cursor to func_8820C114 and
// closes; B closes; any other input goes to func_88002720 to move the cursor.
void func_8822C5EC(void) {
    u32 pressed;

    pressed = *(u16 *)((u8 *)D_80087200 + 8);
    if (pressed & A_BUTTON) {
        if (((unk_D_88234920 *)D_88234920)->unk_4C[((unk_D_88234920 *)D_88234920)->cursor] != 0) {
            func_800226C0(73);
        } else {
            func_800226C0(71);
            func_8820C114(((unk_D_88234920 *)D_88234920)->unk_04, ((unk_D_88234920 *)D_88234920)->cursor);
            func_8822C5AC();
        }
    } else if (pressed & B_BUTTON) {
        func_800226C0(72);
        func_8822C5AC();
    } else {
        func_88002720(&((unk_D_88234920 *)D_88234920)->cursor, ((unk_D_88234920 *)D_88234920)->unk_24, D_88006020);
    }
}

extern void func_889033FC(void *, void *);
void func_8822C6AC(void) {
    func_889033FC(*D_88234920, (u8 *)D_88234920 + 0x18);
}

extern void *Util_Malloc(s32);
extern void _bzero(void *, s32);
extern u8 *func_88002AA8(u8 *, s32, u8 **, u16, s32, s16, s16, s16, s16, s16, s16, s32, s16, void *);
extern u8 func_88004804(s32, s32, s16, s16, s32, s32, u8, u8, u8, s32 *, s32 *, s32 *, s32 *, u8, u8);
extern u8 D_8800ED50[];
void func_8822C6D8(u8 arg0, s32 *arg1, u8 *arg2) {
    s32 i;
    s32 x;
    s32 text_id;
    u8 slot;
    struct {
        s32 enabled;
        u8 *flags;
    } mask;

    D_88234920 = Util_Malloc(80);
    if (func_8800005C() != 0) {
        text_id = 17;
    } else {
        text_id = 18;
    }
    D_88234920[2] = func_8004C874(33, text_id);
    D_88234920[3] = arg2;
    D_88234920[4] = func_8004C874(33, 20);
    D_88234920[5] = func_8004C874(33, 21);
    mask.enabled = 1;
    mask.flags = (u8 *)D_88234920 + 76;
    _bzero((u8 *)D_88234920 + 76, 4);
    for (i = 0; i < 2; i++, arg1++) {
        ((u8 *)D_88234920)[*arg1 + 76] = 1;
    }
    func_88002AA8((u8 *)D_88234920 + 24, 0, D_88234920 + 2, 4,
                  8, 1, 6, 15, 16, 13, 16, 0, 0, &mask);
    ((u8 *)D_88234920)[4] = arg0;
    if (arg0 == 0) {
        x = 163;
    } else {
        x = 474;
    }
    slot = func_88004804((s32)((u8 *)D_88234920 + 24), 0, (s16)x, 104, 1, 1,
                         220, 220, 180, (s32 *)func_8822C5EC, (s32 *)func_8822C6AC,
                         (s32 *)func_8822C53C, (s32 *)func_8822C570, 0, 0);
    *D_88234920 = D_8800ED50 + slot * 76;
    D_880068B4 = 0;
}

extern void * D_80087200;
void func_8822C8E0(void) {
    Input_SetRepeatController(D_80087200);
}

extern void func_88001900();
extern s32 D_88234930;

void func_8822C904(void) {
    func_88001900();
    D_880068B4 = 1;
    Util_Free(D_88234930);
}

/* mkdraft:func_8822C93C begin */
extern s32 D_880068B4;
extern void Input_SetRepeatController(void *);
extern void *D_80087200;
extern void func_88004990(u8, s32);
extern s32 D_88234930;
extern s32 D_88234718;
extern s8 D_88234934;
extern s32 Input_GetRepeatedDPad(void);



void func_8822C93C(void)
{
  s16 temp_t1;
  s8 var_t2;
  s32 dpad;
  if ((D_88234718 == 1) && (!((*((u16 *) (((u8 *) D_80087200) + 6))) & 0xC00)))
  {
    *((s16 *) (((u8 *) D_88234930) + 0x10)) += 0x2000;
  }
  else
  {
    *((s16 *) (((u8 *) D_88234930) + 0x10)) = 0;
  }
  if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x8000)
  {
    if (D_88234718 == 1)
    {
      D_88234718 = 2;
      (*((void (**)(void)) (((u8 *) D_88234930) + 0x14)))();
      *((s32 *) ((*((u8 **) ((u8 *) D_88234930))) + 0x2C)) = 0;
      D_880068B4 = 1;
      D_88234934 = *((s16 *) (((u8 *) D_88234930) + 4));
    }
  }
  else
    if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x4000)
  {
    switch (D_88234718)
    {
      case 1:
        func_800226C0(0x48);
        func_88004990(*(*((u8 **) ((u8 *) D_88234930))), 0);
        D_88234718 = 0;
        return;

      case 2:
        D_88234718 = 1;
        return;

    }

  }
  else
    if (D_88234718 == 1)
  {
    if (((*((s16 *) (((u8 *) D_88234930) + 0xE))) == 1) && ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x200))
    {
      func_800226C0(0x46);
      *((s16 *) (((u8 *) D_88234930) + 0xE)) = 0;
      Input_SetRepeatController(D_80087200);
      return;
    }
    if (((*((s16 *) (((u8 *) D_88234930) + 0xE))) == 0) && ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x100))
    {
      func_800226C0(0x46);
      *((s16 *) (((u8 *) D_88234930) + 0xE)) = 1;
      Input_SetRepeatController(D_80087200);
      return;
    }
    if (!((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x300))
    {
      dpad = Input_GetRepeatedDPad();
      temp_t1 = *((s16 *) (((u8 *) D_88234930) + 4));
      if ((dpad == 0x400) || (dpad == 0x800))
      {
        switch (dpad)
        {
          case 0x800:
            var_t2 = 1;
            break;

          case 0x400:
            var_t2 = -1;
            break;

          default:
            var_t2 = var_t2;
            break;

        }
        if (((*((u8 *) (((u8 *) D_88234930) + 6))) == (*((s16 *) (((u8 *) D_88234930) + 4)))) && (dpad == 0x800))
        {
          *((s16 *) (((u8 *) D_88234930) + 4)) = 1;
        }
        else
          if (((*((s16 *) (((u8 *) D_88234930) + 4))) == 1) && (dpad == 0x400))
        {
          *((s16 *) (((u8 *) D_88234930) + 4)) = *((u8 *) (((u8 *) D_88234930) + 6));
        }
        else
        {
          if ((*((s16 *) (((u8 *) D_88234930) + 0xE))) == 0)
          {
            *((s16 *) (((u8 *) D_88234930) + 4)) = (s16) ((*((s16 *) (((u8 *) D_88234930) + 4))) + (var_t2 * 0xA));
          }
          else
            if ((*((s16 *) (((u8 *) D_88234930) + 0xE))) == 1)
          {
            *((s16 *) (((u8 *) D_88234930) + 4)) = (s16) ((*((s16 *) (((u8 *) D_88234930) + 4))) + var_t2);
          }
          if ((*((s16 *) (((u8 *) D_88234930) + 4))) <= 0)
          {
            *((s16 *) (((u8 *) D_88234930) + 4)) = 1;
          }
          else
            if ((*((u8 *) (((u8 *) D_88234930) + 6))) < (*((s16 *) (((u8 *) D_88234930) + 4))))
          {
            *((s16 *) (((u8 *) D_88234930) + 4)) = *((u8 *) (((u8 *) D_88234930) + 6));
          }
        }
        if (temp_t1 != (*((s16 *) (((u8 *) D_88234930) + 4))))
        {
          func_800226C0(0x46);
        }
      }
    }
  }
}
/* mkdraft:func_8822C93C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19F570/func_8822CC50.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19F570/func_8822CED0.s")
#endif
