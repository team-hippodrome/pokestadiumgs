#include "global.h"
#include "controller.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_190BB0/func_8821D930.s")

extern u8 *func_88216D54(s32);
extern u8 *func_88213A3C(s32);
u8 *func_8821DA70(s32 arg0) {
    switch (arg0) {
        case 0:
        case 1:
        case 2:
            return func_88216D54(arg0);
        case 3:
        case 4:
        case 5:
            return func_88213A3C(arg0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_190BB0/func_8821DAC0.s")

extern u16 D_882345F0;
extern s32 GbSave_GetRecordCapacity(s32);
extern s32 func_80053230(s32);
extern void *mem_pool_alloc(void *, s32);
extern s32 func_80001FF0(void);
extern void func_88001C6C(void *, u16, u8, s16, u8, s16, s16, s16, s16, s16, s32);
void func_8821DC48(void *pool, u8 *arg1, u8 *arg2, u8 *arg3) {
    s16 count;
    u8 *entries[3];
    s32 i;

    count = GbSave_GetRecordCapacity(0x22) + func_80053230(0x12) * 2 + 0x72;
    entries[0] = arg1;
    entries[1] = arg2;
    entries[2] = arg3;
    for (i = 0; i < 3; i++) {
        if (i == 0) {
            *(void **)entries[i] = mem_pool_alloc(pool, count * 4);
        } else {
            *(void **)entries[i] = mem_pool_alloc(pool, D_882345F0 * 4);
        }
        func_88001C6C(entries[i] + 8, 1, 7, 0xC7, 23, 12,
                      (s32)(540.0f / func_80001FF0() + ((540.0f / func_80001FF0() > 0.0f) ? 0.5f : -0.5f)),
                      32, 32, 0xF0C, 70);
    }
}

extern u32 D_882347F0;
extern void func_8821E0BC(void);
void func_8821DE04(void) {
    if ((*(s32 *)((u8 *)(D_882347F0) + 0)) == 0) {
        func_8821E0BC();
        return;
    }
    (*(s32 *)((u8 *)(D_882347F0) + 4)) = 1;
    (*(s32 *)((u8 *)(*(void **)((u8 *)(D_882347F0) + 8)) + 0x2C)) = 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_190BB0/func_8821DE58.s")

typedef struct {
    u8 unk_00[44];
    s32 unk_2C;
} unk_func_8821E0BC_child;

typedef struct {
    void **unk_00;
} unk_func_8821E0BC_list;

typedef struct {
    u8 unk_00[8];
    s16 unk_08;
} unk_func_8821E0BC_selection;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    unk_func_8821E0BC_child *unk_08;
    unk_func_8821E0BC_list *unk_0C;
    unk_func_8821E0BC_selection *unk_10;
} unk_func_8821E0BC;

extern void *D_88234620;
extern void func_8821DE58(void);
void func_8821E0BC(void) {
    unk_func_8821E0BC *state;

    state = (unk_func_8821E0BC *)D_882347F0;
    D_88234620 = state->unk_0C->unk_00[state->unk_10->unk_08];
    if (state->unk_00 == 0) {
        state->unk_08->unk_2C = 0;
        ((unk_func_8821E0BC *)D_882347F0)->unk_04 = 2;
        *((u8 *)D_882347F0 + 1184) = 2;
    } else {
        func_8821DE58();
    }
}

extern void func_88216EFC(s32);
extern s32 D_880068B4;
extern s8 D_889041B8;

void func_8821E13C(s32 arg0) {
    D_880068B4 = 0;
    D_889041B8 = 2;
    if (arg0 == 0) {
        func_88216EFC(0);
    }
}

extern u32 D_882347F0;
extern void func_8821DE58(void);
extern void func_88001900(void);
extern s32 D_889041B4;
void func_8821E174(s32 arg0) {
    D_889041B4 = 0;
    (*(s32 *)((u8 *)(*(void **)((u8 *)(D_882347F0) + 8)) + 0x2C)) = 1;
    (*(s32 *)((u8 *)(*(void **)((u8 *)(D_882347F0) + 8)) + 0x30)) = 1;
    (*(s32 *)((u8 *)(*(void **)((u8 *)(D_882347F0) + 8)) + 0x34)) = 1;
    if (arg0 != 0) {
        func_8821DE58();
        return;
    }
    (*(s32 *)((u8 *)(D_882347F0) + 4)) = 1;
    func_88001900();
}

extern void func_88004990(u8, s32);
extern u32 D_882347F0;
extern s32 D_880068B8;
void func_8821E1E4(void) {
    func_88004990(*(*(u8 **)((u8 *)(D_882347F0) + (8))), 0);
    D_880068B8 = 1;
}

/* mkdraft:func_8821E21C begin */
extern void D_88000E4C(void);
extern s32 D_880068B4;
extern s32 D_880068B8;
extern u32 D_882347F0;
extern s32 D_882345F4;
extern char *LabPC_FormatColoredMoveName(char *output, u8 move);
extern void LabPC_OpenMessageDialog(s8 *title,s16 x,s16 y,s32 style,u8 red,u8 green,u8 blue,u8 delay,u8 kind,s32 *done,s32 *cancel,s32 *extra,void (*callback)(void));
extern s32 func_8004C54C(s32 index,s32 value);
extern void *func_8004C8A0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_88903B00(void);



void func_8821E21C(u8 arg0, s32 arg1) {
    s8 sp150[0x80];
    u8 sp50[0x100];

    func_8004C54C(0x1E, LabPC_FormatColoredMoveName(sp150, arg0));
    switch (arg1) {
    case 0:
        LabPC_OpenMessageDialog(func_8004C8A0(sp50, 0x100, 0x25, 0x61), 0x24D, 0x118, 2, 0xFFU, 0xAAU, 0x8CU, 2U, 2U, (s32 *)(*(s32 *)((u8 *)D_882347F0 + 0x58) + 0x2C), (s32 *)(*(s32 *)((u8 *)D_882347F0 + 8) + 0x30), (s32 *) D_88000E4C, D_88000E4C);
        return;
    case 1:
        func_8004C54C(0x1D, D_882345F4 + 0x3C);
        LabPC_OpenMessageDialog(func_8004C8A0(sp50, 0x100, 0x25, 0x62), 0x17C, 0x11F, 4, 0xDBU, 0xDCU, 0xB4U, 2U, 0U, &D_880068B4, &D_880068B8, (s32 *) func_88903B00, D_88000E4C);
        return;
    case 2:
        LabPC_OpenMessageDialog(func_8004C8A0(sp50, 0x100, 0x25, 0x64), 0x1F6, 0xA1, 2, 0xFFU, 0xAAU, 0x8CU, 0U, 2U, NULL, (s32 *)(*(s32 *)((u8 *)D_882347F0 + 8) + 0x30), (s32 *) D_88000E4C, D_88000E4C);
        return;
    case 3:
        LabPC_OpenMessageDialog(func_8004C8A0(sp50, 0x100, 0x25, 0x64), 0x1FC, 0x1AC, 8, 0xFFU, 0xAAU, 0x8CU, 0U, 2U, NULL, (s32 *)(*(s32 *)((u8 *)D_882347F0 + 8) + 0x30), (s32 *) D_88000E4C, D_88000E4C);
        return;
    }
}
/* mkdraft:func_8821E21C end */

extern void Input_SetRepeatController(void *);
void func_8821E490(void) {
    Input_SetRepeatController(D_80087200);
}

/* mkdraft:func_8821E4B4 begin */
extern u32 D_882347F0;
extern void *D_88234620;
extern s32 D_882345F4;
extern u8 D_8823474F;
extern u8 D_889041A0;
extern void func_8821DE04(void);
extern void LabPC_StartMoveFieldAnimation(void);
extern void LabPC_StartStatChangeAnimation(void);
extern s32 func_88202158();
extern void func_882033B0(void *, void *);
extern void func_8821E21C(u8, s32);



void func_8821E4B4(void)
{
  s32 temp_v0;
  if (*((s32 *) (((u8 *) D_882347F0) + 0x54)))
  {
    temp_v0 = *((s32 *) (((u8 *) D_882347F0) + 4));
    switch (temp_v0)
    {
      case 5:
        func_8821DE04();
        return;

      case 6:
        *((s32 *) (((u8 *) D_882347F0) + 4)) = 3;
        *((s32 *) (((u8 *) (*((s32 *) (((u8 *) D_882347F0) + 0x58)))) + 0x2C)) = 1;
        return;

      case 7:
        *((s32 *) (((u8 *) D_882347F0) + 4)) = 4;
        *((s32 *) (((u8 *) (*((s32 *) (((u8 *) D_882347F0) + 0x58)))) + 0x2C)) = 1;
 do { } while (0);  // FAKE: temp-pool perturbation; without this empty statement IDO hoists
                        // the D_88234620/2 compare constants late and the score is 340.
        return;

      default:
        return;

    }

  }
  else
  {
    temp_v0 = *((s32 *) (((u8 *) D_882347F0) + 4));
    if ((temp_v0 != 5) && (temp_v0 != 6))
    {
      if (temp_v0 == 7)
      {
        func_882033B0((s32) D_882345F4, D_88234620);
        func_8821E21C(((u8 *) D_882345F4)[(s8) D_889041A0 + 0xA], 1);
      }
    }
    else
      if (func_88202158(D_88234620, 2) != 0)
    {
      LabPC_StartMoveFieldAnimation();
    }
    else
      if (func_88202158(D_88234620, 0xFC00) != 0)
    {
      D_8823474F = 3;
    }
    else
    {
      LabPC_StartStatChangeAnimation();
    }
  }
}
/* mkdraft:func_8821E4B4 end */

extern u32 D_882347F0;
extern void func_88004990(u8, s32);
extern void func_800226C0(s32);
extern void func_8821E1E4(void);
extern void func_88002720(void *, u16, void *);
void func_8821E5F8(void) {
    void *temp_v0;
    u16 temp_a0;
    s16 temp_v1;
    s32 temp_v0_2;

    temp_a0 = D_80087200->buttonsPressed;
    temp_v0 = (u8 *)(u32)D_882347F0 + 0x18;
    if (!temp_v0) {
    }
    if (temp_a0 & 0x8000) {
        func_88004990(*(u8 *)(*(void **)((u8 *)(u32)D_882347F0 + 0x14)), 0);
        temp_v1 = *(s16 *)((u8 *)temp_v0 + 0x28);
        if (temp_v1 == 0) {
            func_800226C0(0x5F);
            func_8821E1E4();
            temp_v0_2 = *(s32 *)((u8 *)(u32)D_882347F0 + 4);
            if ((temp_v0_2 == 6) || (temp_v0_2 == 7)) {
                func_88004990(*(u8 *)(*(void **)((u8 *)(u32)D_882347F0 + 0x58)), 0);
            }
        } else if (temp_v1 == 1) {
            func_800226C0(0x48);
            *(s32 *)((u8 *)(u32)D_882347F0 + 0x54) = 1;
        }
    } else {
        if (temp_a0 & 0x4000) {
            func_800226C0(0x48);
            func_88004990(*(u8 *)(*(void **)((u8 *)(u32)D_882347F0 + 0x14)), 0);
            *(s32 *)((u8 *)(u32)D_882347F0 + 0x54) = 1;
            return;
        }
        func_88002720((u8 *)temp_v0 + 0x28,
                      *(u16 *)((u8 *)temp_v0 + 0xC),
                      (u8 *)temp_v0 + 0x2C);
    }
}

extern void func_889033FC(void *arg0, void *arg1);
void func_8821E710(void) {
    func_889033FC((*(void **)((u8 *)(D_882347F0) + (0x14))), D_882347F0 + 0x18);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_190BB0/func_8821E73C.s")

void func_8821E8C8(void) {
    Input_SetRepeatController(D_80087200);
}

extern u32 D_882347F0;
extern void func_8821E0BC(void);
void func_8821E8EC(void) {
    s32 state_mode;

    if ((*(s32 *)((u8 *)(D_882347F0) + 0x68) != 0) &&
        ((state_mode = *(s32 *)((u8 *)(D_882347F0) + 4), (state_mode == 3) || (state_mode == 4)))) {
        if (*(s32 *)((u8 *)(D_882347F0) + 0) == 0) {
            func_8821E0BC();
            return;
        }
        (*(s32 *)((u8 *)(D_882347F0) + 4)) = 1;
        (*(s32 *)((u8 *)(*(void **)((u8 *)(D_882347F0) + 8)) + 0x2C)) = 1;
    }
}

extern void func_8821E21C(u8, s32);
extern u8 D_88006020[];
extern u8 D_889041A0;
extern s32 func_8821E73C();
void func_8821E964(void) {
    u8 *record;
    record = (u8 *)D_882347F0 + 0x58;

    if (D_80087200->buttonsPressed & A_BUTTON) {
        *(s32 *)(*(u8 **)record + 0x2C) = 0;
        D_889041A0 = *(s16 *)(record + 0xC);
        if (*(s32 *)((u8 *)D_882347F0 + 4) == 3) {
            func_800226C0(71);
            func_8821E73C(6);
        } else if (*(s32 *)((u8 *)D_882347F0 + 4) == 4) {
            if (((*(s16 *)(record + 0xC) + *(u8 **)(record + 0x8))[0x18] & 0xC0) >> 6 == 3 ||
                (*(s16 *)(record + 0xC) + *(u8 **)(record + 0x8))[2] == 166) {
                func_800226C0(73);
                func_8821E21C((*(s16 *)(record + 0xC) + *(u8 **)(record + 0x8))[2], 0);
            } else if ((*(s16 *)(record + 0xC) + *(u8 **)(record + 0x8))[2] == 252) {
                func_800226C0(73);
                *(s32 *)(*(u8 **)record + 0x2C) = 1;
            } else {
                func_800226C0(71);
                func_8821E73C(7);
            }
        }
    } else if (D_80087200->buttonsPressed & B_BUTTON) {
        func_800226C0(72);
        func_88004990(**(u8 **)record, 0);
        *(s32 *)(record + 0x10) = 1;
    } else {
        func_88002720(record + 0xC, record[0xE], D_88006020);
    }
}



extern void func_889035FC(s32);
void func_8821EAD8(void) {
    func_889035FC((D_882347F0 + 88));
}

extern u32 D_882347F0;
extern s32 D_882345F4;
extern u8 D_8800ED50[];
extern void func_889035A0(void *, void *, s16, s16);
extern s32 func_88004804(s32,s32,s16,s16,s32,s32,s32,s32,s32,
                          void (*)(void),void (*)(void),void (*)(void),
                          void (*)(void),s32,s32);
extern void func_8821E964(void);
extern void func_8821EAD8(void);
extern void func_8821E8C8(void);
extern void func_8821E8EC(void);
void func_8821EB00(void) {
    u32 *global;
    s32 result;

    func_889035A0((void *)((u8 *)(D_882347F0) + 0x58),
                  (void *)((u8 *)(D_882345F4) + 8), 0x3D, 9);
    result = func_88004804(0, 3, 0x190, 0xA1, 0, 1, 0xDC, 0xDC, 0xB4,
                           func_8821E964, func_8821EAD8,
                           func_8821E8C8, func_8821E8EC, 0, 1);
    global = &D_882347F0;
    (*(void **)((u8 *)(*global) + 0x58)) = D_8800ED50 + (result * 0x4C);
    (*(s16 *)((u8 *)(*(void **)((u8 *)(*global) + 0x58)) + 0x10)) = 0xBE;
    (*(s16 *)((u8 *)(*(void **)((u8 *)(*global) + 0x58)) + 0x12)) = 0xC5;
    (*(s32 *)((u8 *)(*(void **)((u8 *)(*global) + 8)) + 0x2C)) = 0;
}

extern void func_88001900(void);
void func_8821EC10(void) {
    func_88001900();
    D_880068B8 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_190BB0/func_8821EC34.s")

/* mkdraft:func_8821EE00 begin */
extern s32 func_880020CC();
extern void func_88214394(void);

typedef struct {
    s16 unk_00;
    s32 unk_04;
    s16 unk_08;
    u8 unk_0A[0x18];
    s16 unk_22;
} unk_func_8821EE00_selection;

typedef struct {
    void **unk_00;
    s16 unk_04;
} unk_func_8821EE00_list;

typedef struct {
    s32 unk_00;
    s32 unk_04;
    void *unk_08;
    unk_func_8821EE00_list *unk_0C;
    unk_func_8821EE00_selection *unk_10;
} unk_func_8821EE00_state;

// `pressed` is set in both branches of the guard: IDO 7.1 then leaves the
// redundant `b` plus `addiu v0,1` after the test, matching the target.
//
// FAKE: `selected` is a second name for the same selection pointer and carries
// no state of its own. It only changes IDO's register choice for that pointer;
// reading through `selection` alone gives the same instructions with the
// pointer in $a1 and its loaded unk_00 in $a0, which scores 65.


void func_8821EE00(void) {
    s32 pressed;
    unk_func_8821EE00_state *state;
    unk_func_8821EE00_selection *selection;
    unk_func_8821EE00_selection *selected;

    if (*(u8 *)&D_889041B8 != 0) {
        return;
    }
    state = (unk_func_8821EE00_state *)D_882347F0;
    selection = state->unk_10;
    selected = selection;
    if (selected->unk_00 == 0 && selected->unk_04 == 0 && selected->unk_22 == 0) {
        pressed = 1;
    } else {
        pressed = 0;
    }
    if (pressed && (D_80087200->buttonsPressed & B_BUTTON)) {
        func_800226C0(0x48);
        func_8821E1E4();
        return;
    }
    if (selected->unk_00 == 0 && selected->unk_04 == 0 && selected->unk_22 == 0) {
        pressed = 1;
    } else {
        pressed = 0;
    }
    if (pressed && (D_80087200->buttonsPressed & A_BUTTON)) {
        if (state->unk_0C->unk_04 == 0 ||
            *(u8 *)((u8 *)state + selected->unk_08 + 0x9C) == 1) {
            func_800226C0(0x49);
            return;
        }
        if (state->unk_00 == 4 &&
            *(u8 *)((u8 *)state->unk_0C->unk_00[selected->unk_08] + 9) == 0) {
            func_88214394();
        } else {
            func_800226C0(0x47);
        }
        if (*(s32 *)((u8 *)D_882347F0 + 4) == 1) {
            func_8821E0BC();
            return;
        }
        func_8821E1E4();
        *(s32 *)((u8 *)D_882347F0 + 0x49C) = 1;
        state = (unk_func_8821EE00_state *)D_882347F0;
        switch (state->unk_00) {
            case 0:
            case 1:
            case 2:
            case 3:
                D_88234620 = state->unk_0C->unk_00[state->unk_10->unk_08];
                break;
            case 4:
            case 5:
                D_882345F4 = state->unk_0C->unk_00[state->unk_10->unk_08];
                break;
        }
    } else {
        func_880020CC();
    }
}
/* mkdraft:func_8821EE00 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_190BB0/func_8821F01C.s")

typedef struct {
    u8 unk_000[0x4A4];
    u8 (*unk_4A4)(u8);
} unk_D_882347F0;

// Comparator over byte keys: orders by the values unk_4A4 maps them to, then by address.
s32 func_8821FFB4(u8 *arg0, u8 *arg1) {
    s32 difference;

    difference = ((unk_D_882347F0 *)D_882347F0)->unk_4A4(*arg0) -
                 ((unk_D_882347F0 *)D_882347F0)->unk_4A4(*arg1);
    return (difference != 0) ? difference : (arg0 == arg1) ? 0 : (arg0 < arg1) ? -1 : 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_190BB0/func_88220050.s")

extern s32 func_8800005C(void);
extern s32 func_80063754(s32);
extern s32 func_88203FB4(void);
s32 func_88220248(u8 *arg0) {
    s32 result = 0;

    if ((arg0[0x26] & 1) == 0 &&
        arg0[8] != 0xFC &&
        ((func_8800005C() == 0 &&
          (*(u8 **)(*(u8 **)(arg0 + 0)))[8] == 0) ||
         ((*(u8 **)(*(u8 **)(arg0 + 0)))[8] == 2 &&
          (func_80063754(arg0[9]) != 0 || func_88203FB4() != 0)))) {
        result = 1;
    }
    return result;
}

extern u8 func_80063660(u8);
s32 func_882202E8(u8 species, u8 item) {
    s32 result = 0;

    switch (species) {
    case 163:
        if (item == 0x19) {
            result = 1;
        }
        break;
    case 30:
        if (item == 0x71) {
            result = 1;
        }
        break;
    case 105:
        if (item == 0x53) {
            result = 1;
        }
        break;
    case 35:
        if (item == 0x84) {
            result = 1;
        }
        break;
    case 118:
        if (item == 0x68 || item == 0x69) {
            result = 1;
        }
        break;
    case 91:
    case 94:
    case 106:
        break;
    default:
        if (func_80063660(species) != 0) {
            result = 1;
        }
        break;
    }
    return result;
}

extern u16 D_882345F0;
extern u8 *D_88A01C38;
extern s32 func_80063754(s32);
extern s32 func_88220248(u8 *arg0);
void func_88220400(s32 mode, u8 *list) {
    u8 *entry;
    u8 **dst;
    u32 i;
    u16 ok;

    *(s16 *)(list + 4) = 0;
    dst = *(u8 ***)list;
    entry = D_88A01C38;
    for (i = 0; i < D_882345F0; i++, entry += 0x60) {
        switch (mode) {
            case 4:
                ok = func_88220248(entry);
                break;
            case 5:
                ok = func_80063754(entry[9]);
                break;
        }
        if (ok) {
            *dst++ = entry;
            (*(s16 *)(list + 4))++;
        }
    }
}

extern void func_88220050(s32, u8 *);
extern s32 func_88202FD4(void *, void *);
extern void _bzero(void *, s32);
extern s32 func_80063754(s32);
extern s32 func_88220248(u8 *arg0);
extern s32 func_882202E8(u8 species, u8 item);
extern void func_88220400(s32 mode, u8 *list);
extern s32 D_882345F4;
extern u32 D_882347F0;
void func_882204F8(s32 mode, u8 *list) {
    s32 kind = mode;
    u32 i;
    u8 **entry;
    u8 *flags;
    s32 ok;

    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_88220050(kind, list);
        break;
    case 4:
    case 5:
        func_88220400(kind, list);
        break;
    }
    _bzero((u8 *)D_882347F0 + 0x9C, *(s16 *)(list + 4));
    if (kind == 1 || kind == 2) {
        flags = (u8 *)D_882347F0 + 0x9C;
        for (i = 0, entry = *(u8 ***)list; i < *(s16 *)(list + 4); i++, entry++, flags++) {
            if (mode == 1) {
                ok = func_88202FD4((void *)D_882345F4, *entry) == 0;
            } else {
                ok = func_80063754(**entry) && func_88220248((u8 *)D_882345F4) == 0;
            }
            if (ok) {
                *flags = 1;
            } else if (mode == 2 && func_882202E8(**entry, ((u8 *)D_882345F4)[8]) != 0) {
                *flags = 2;
            }
        }
    }
}

/* mkdraft:func_882206A0 begin */
extern void func_88001C24(void *, u16, u8);
extern void func_88001D0C(void *);
extern void func_8821EE00(void);
extern void func_8821F01C(void);
extern void func_8821EC34(void);



void func_882206A0(s32 arg0) {
    u32 *global;
    s32 result;

    global = (u32 *)(u32)&D_882347F0;
    *global = (u32)Util_Malloc(0x4A8);
    if ((arg0 != 0) && (arg0 != 1)) {
        (*(s32 *)((u8 *)(*global) + 4)) = 0;
    } else {
        (*(s32 *)((u8 *)(*global) + 4)) = 1;
    }
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        (*(s16 *)((u8 *)(*global) + 0x6C)) = 0xFD;
        (*(s16 *)((u8 *)(*global) + 0x6E)) = 0x7C;
        (*(s16 *)((u8 *)(*global) + 0x70)) = 0x10F;
        (*(s16 *)((u8 *)(*global) + 0x72)) = 0xD2;
        (*(s16 *)((u8 *)(*global) + 0x74)) = 0xC4;
        (*(s16 *)((u8 *)(*global) + 0x76)) = 0x16;
        (*(s32 *)((u8 *)(*global) + 0x78)) = 0x9A909A9;
        (*(s16 *)((u8 *)(*global) + 0x7C)) = 0x1D3;
        (*(s16 *)((u8 *)(*global) + 0x7E)) = 0xD2;
        (*(s16 *)((u8 *)(*global) + 0x80)) = 0x6B;
        (*(s16 *)((u8 *)(*global) + 0x82)) = 0x16;
        (*(s32 *)((u8 *)(*global) + 0x84)) = 0xDF00DF;
        (*(s16 *)((u8 *)(*global) + 0x94)) = 0x117;
        (*(s16 *)((u8 *)(*global) + 0x96)) = 0xD5;
        (*(s16 *)((u8 *)(*global) + 0x98)) = 0x19D;
        (*(s16 *)((u8 *)(*global) + 0x9A)) = 0x1DB;
        break;
    case 3:
        (*(s16 *)((u8 *)(*global) + 0x6C)) = 0x97;
        (*(s16 *)((u8 *)(*global) + 0x6E)) = 0x71;
        (*(s16 *)((u8 *)(*global) + 0x70)) = 0xA9;
        (*(s16 *)((u8 *)(*global) + 0x72)) = 0xC7;
        (*(s16 *)((u8 *)(*global) + 0x74)) = 0xC4;
        (*(s16 *)((u8 *)(*global) + 0x76)) = 0x16;
        (*(s32 *)((u8 *)(*global) + 0x78)) = 0x9A909A9;
        (*(s16 *)((u8 *)(*global) + 0x7C)) = 0x16D;
        (*(s16 *)((u8 *)(*global) + 0x7E)) = 0xC7;
        (*(s16 *)((u8 *)(*global) + 0x80)) = 0x6B;
        (*(s16 *)((u8 *)(*global) + 0x82)) = 0x16;
        (*(s32 *)((u8 *)(*global) + 0x84)) = 0xDF00DF;
        (*(s16 *)((u8 *)(*global) + 0x94)) = 0xB1;
        (*(s16 *)((u8 *)(*global) + 0x96)) = 0xCA;
        (*(s16 *)((u8 *)(*global) + 0x98)) = 0x137;
        (*(s16 *)((u8 *)(*global) + 0x9A)) = 0x175;
        break;
    case 4:
    case 5:
        (*(s16 *)((u8 *)(*global) + 0x6C)) = 0x97;
        (*(s16 *)((u8 *)(*global) + 0x6E)) = 0x71;
        (*(s16 *)((u8 *)(*global) + 0x70)) = 0xA9;
        (*(s16 *)((u8 *)(*global) + 0x72)) = 0xC7;
        (*(s16 *)((u8 *)(*global) + 0x74)) = 0x5C;
        (*(s16 *)((u8 *)(*global) + 0x76)) = 0x16;
        (*(s32 *)((u8 *)(*global) + 0x78)) = 0x9A909A9;
        (*(s16 *)((u8 *)(*global) + 0x7C)) = 0x105;
        (*(s16 *)((u8 *)(*global) + 0x7E)) = 0xC7;
        (*(s16 *)((u8 *)(*global) + 0x80)) = 0x4D;
        (*(s16 *)((u8 *)(*global) + 0x82)) = 0x16;
        (*(s32 *)((u8 *)(*global) + 0x84)) = 0xDF00DF;
        (*(s16 *)((u8 *)(*global) + 0x88)) = 0x152;
        (*(s16 *)((u8 *)(*global) + 0x8A)) = 0xC7;
        (*(s16 *)((u8 *)(*global) + 0x8C)) = 0x86;
        (*(s16 *)((u8 *)(*global) + 0x8E)) = 0x16;
        (*(s32 *)((u8 *)(*global) + 0x90)) = 0x9A909A9;
        (*(s16 *)((u8 *)(*global) + 0x94)) = 0xB1;
        (*(s16 *)((u8 *)(*global) + 0x96)) = 0xCA;
        (*(s16 *)((u8 *)(*global) + 0x98)) = 0x10D;
        (*(s16 *)((u8 *)(*global) + 0x9A)) = 0x159;
        break;
    }
    (*(u8 **)((u8 *)(*global) + 0xC)) = func_8821DA70(arg0);
    (*(u8 **)((u8 *)(*global) + 0x10)) = (u8 *)(*(u8 **)((u8 *)(*global) + 0xC)) + 8;
    func_882204F8(arg0, *(u8 **)((u8 *)(*global) + 0xC));
    func_88001C24(*(void **)((u8 *)(*global) + 0x10),
                  *(u16 *)((u8 *)(*(void **)((u8 *)(*global) + 0xC)) + 4), 7);
    func_88001D0C(*(void **)((u8 *)(*global) + 0x10));
    result = func_88004804(0, 3, *(s16 *)((u8 *)(*global) + 0x6C),
                           *(s16 *)((u8 *)(*global) + 0x6E), 0, 1, 0xDC, 0xDC, 0xB4,
                           func_8821EE00, func_8821F01C,
                           func_8821EC10, func_8821EC34, 2, 0);
    (*(void **)((u8 *)(*global) + 8)) = D_8800ED50 + (result * 0x4C);
    (*(s16 *)((u8 *)(*(void **)((u8 *)(*global) + 8)) + 0x10)) = 0x156;
    (*(s16 *)((u8 *)(*(void **)((u8 *)(*global) + 8)) + 0x12)) = 0x146;
    (*(u32 *)((u8 *)(*global) + 0)) = arg0;
    (*(s32 *)((u8 *)(*global) + 0x49C)) = 0;
    (*(u8 *)((u8 *)(*global) + 0x4A0)) = 0;
    D_880068B4 = 0;
}
/* mkdraft:func_882206A0 end */
#endif
