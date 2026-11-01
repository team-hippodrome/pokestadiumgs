#include "global.h"


#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_80094DE0[];
void func_8FB00020(s32 arg0, s32 arg1, s32 arg2) {
    gSPDisplayList(D_800D0510++, D_80094DE0);
    gDPPipeSync(D_800D0510++);
    gDPSetFillColor(D_800D0510++, 0xFFC7FFC1);
    gDPFillRectangle(D_800D0510++, arg0, arg1, arg0 + arg2, arg1 + 2);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB000D0.s")

extern s32 func_8FB000D0(void*, void*);
s32 func_8FB00170(void* arg0, void* arg1) {
    *(u16*)((u8*)arg0 + 0) = 230;
    *(u16*)((u8*)arg0 + 2) = 150;
    *(u16*)((u8*)arg0 + 4) = 300;
    *(u16*)((u8*)arg0 + 6) = 210;
    *(u16*)((u8*)arg0 + 32) = *(u16*)((u8*)*(void**)((u8*)arg1 + 68) + 12);
    *(s16*)((u8*)arg0 + 8) = 0;
    *(s16*)((u8*)arg0 + 10) = 0;
    return func_8FB000D0(arg0, arg1);
}

typedef struct {
    /* 0x00 */ u8 info[0xC];
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ u8 unk_0E[2];
    /* 0x10 */ u8 entries[6][0x58];
} unk_func_8FB02108_row; // size = 0x220

// The state func_8FB02560 passes as unk_D_8FB03DF8 (index at 0x34); this view
// adds the ten 0x220-byte rows that follow it at 0x4C.
typedef struct {
    /* 0x000 */ u8 unk_000[0x34];
    /* 0x034 */ s32 index;
    /* 0x038 */ u8 unk_038[0x14];
    /* 0x04C */ unk_func_8FB02108_row rows[10];
} unk_func_8FB02108;

extern void _bcopy(const void *, void *, s32);
extern s32 func_800647C8(u8);
extern void *func_8004C874(s32, s32);
extern s8 *HAL_Strcpy(s8 *, s8 *);
s32 func_8FB001C0(u8 *arg0, u8 *arg1) {
    switch (*(u16 *)*(void **)(arg1 + 68)) {
        case 34:
            if (*(s8 *)(arg0 + 14) != 0) {
                _bcopy(arg0 + 14, *(u8 **)(arg1 + 72) + 52, 12);
            } else {
                HAL_Strcpy((s8 *)*(u8 **)(arg1 + 72) + 52,
                           (s8 *)func_800647C8(**(u8 **)(arg1 + 72)));
            }
            return 1;
        case 6:
            if (*(s8 *)(arg0 + 14) != 0) {
                _bcopy(arg0 + 14,
                       ((unk_func_8FB02108 *)arg1)->rows[*(s32 *)(arg1 + 56)].info, 12);
            } else {
                HAL_Strcpy((s8 *)*(u8 **)(arg1 + 72) + 52,
                           func_8004C874(42, 86));
            }
            return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB002BC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB005E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB009C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB00C1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB00E40.s")

s32 func_8FB00C1C();
s32 func_8FB00F78(void *arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg1) + (0x44)));
    (*(u16 *)((u8 *)(arg0) + (0))) = (u16) (*(u16 *)((u8 *)(temp_v0) + (4)));
    (*(u16 *)((u8 *)(arg0) + (2))) = (u16) (*(u16 *)((u8 *)(temp_v0) + (6)));
    (*(s16 *)((u8 *)(arg0) + (4))) = (s16) ((*(u16 *)((u8 *)(temp_v0) + (0xC))) * 0x14);
    if (func_8FB00C1C() != 0) {
        (*(s16 *)((u8 *)(arg0) + (6))) = (s16) ((*(u16 *)((u8 *)(arg0) + (0xC))) * 0x14);
        return 1;
    }
    return 0;
}

/* mkdraft:func_8FB00FE8 begin */
extern s32 D_80087200;



s32 func_8FB00FE8(void *arg0)
{
  s32 result;
  s16 mode;
  mode = *((u16 *) (((u8 *) D_80087200) + 0xC));
  result = 0;
  if (mode != 0)
  {
    func_800226C0(1, arg0);
    switch (mode)
    {
      case 512:
        ((s16 *) arg0)[4] -= *((u16 *) (((u8 *) arg0) + 12));
        if (((s16 *) arg0)[4] < 0)
      {
        ((s16 *) arg0)[4] = 0;
      }
        ((s16 *) arg0)[5] -= *((u16 *) (((u8 *) arg0) + 12));
        if (((s16 *) arg0)[5] < 0)
      {
        ((s16 *) arg0)[5] = 0;
      }
        break;

      case 256:
        ((s16 *) arg0)[4] += *((u16 *) (((u8 *) arg0) + 12));
        if ((*((u16 *) (((u8 *) arg0) + 14))) < ((s16 *) arg0)[4])
      {
        ((s16 *) arg0)[4] = *((u16 *) (((u8 *) arg0) + 14));
      }
        ((s16 *) arg0)[5] += *((u16 *) (((u8 *) arg0) + 12));
        if ((((*((u16 *) (((u8 *) arg0) + 14))) - (*((u16 *) (((u8 *) arg0) + 12)))) + 1) < ((s16 *) arg0)[5])
      {
        ((s16 *) arg0)[5] = ((*((u16 *) (((u8 *) arg0) + 14))) - (*((u16 *) (((u8 *) arg0) + 12)))) + 1;
      }
        break;

      case 2048:
        ((s16 *) arg0)[4]--;
        if (((s16 *) arg0)[4] < 0)
      {
        ((s16 *) arg0)[4] = 0;
      }
        if (((s16 *) arg0)[4] < ((s16 *) arg0)[5])
      {
        ((s16 *) arg0)[5] = ((s16 *) arg0)[4];
      }
        break;

      case 1024:
        ((s16 *) arg0)[4]++;
        if ((*((u16 *) (((u8 *) arg0) + 14))) < ((s16 *) arg0)[4])
      {
        ((s16 *) arg0)[4] = *((u16 *) (((u8 *) arg0) + 14));
      }
        if ((((s16 *) arg0)[5] + (*((u16 *) (((u8 *) arg0) + 12)))) <= ((s16 *) arg0)[4])
      {
        ((s16 *) arg0)[5] = (((s16 *) arg0)[4] - (*((u16 *) (((u8 *) arg0) + 12)))) + 1;
      }
        break;

    }

  }
  if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x8000)
  {
    result = 1;
  }
  else
    if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x4000)
  {
    result = 2;
  }
  return result;
}
/* mkdraft:func_8FB00FE8 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB011DC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB01634.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB01A74.s")

/* Initializes the number-display widget state at
 * arg0 (the same struct drawn by func_8FB01EC4/func_8FB01FCC
 * //@src/fragments/9/fragment9_code.c: u16 x,y,w,h at 0..8, s16 offset at
 * 8, u16 count at 0xA, digit bytes at 0xC, s32 value at 0x14). Geometry
 * comes from the sub-struct at arg1+0x44 (u16 x at +4, u16 y at +6, u16
 * digit count at +0xC): width = digitCount * 20, height fixed 20, offset 0,
 * count = digitCount - 1. If the guard call func_8FB01A74 returns nonzero,
 * the value at +0x14 is decomposed LSB-first into the digit byte array at
 * +0xC in radix arg2 (digits[0] = value % radix, value /= radix, i from 0
 * while i <= count). Returns 1 when the digits were filled, else 0.
 */

s32 func_8FB01A74();

s32 func_8FB01C14(void *arg0, void *arg1, s32 arg2) {
    s32 var_v0;
    s32 var_v1;
    u8 *var_a0;

    (*(u16 *)((u8 *)(arg0) + (0))) = (u16) (*(u16 *)((u8 *)(*(void **)((u8 *)(arg1) + (0x44))) + (4)));
    (*(u16 *)((u8 *)(arg0) + (2))) = (u16) (*(u16 *)((u8 *)(*(void **)((u8 *)(arg1) + (0x44))) + (6)));
    (*(s16 *)((u8 *)(arg0) + (4))) = (s16) ((*(u16 *)((u8 *)(*(void **)((u8 *)(arg1) + (0x44))) + (0xC))) * 20);
    /* The u16 lvalue type below is load-bearing: with s16, uopt CSEs this
     * store's 20 with the multiply's literal 20 above into one shared
     * register (li vN,0x14 + multu t1,vN), losing the sll/addu/sll chain
     * and shifting every later t-temp up one slot. As a u16 store the
     * constant stays a distinct node from the int multiply constant. */
    (*(u16 *)((u8 *)(arg0) + (6))) = 20;
    (*(s16 *)((u8 *)(arg0) + (8))) = 0;
    (*(u16 *)((u8 *)(arg0) + (0xA))) = (u16) ((*(u16 *)((u8 *)(*(void **)((u8 *)(arg1) + (0x44))) + (0xC))) - 1);
    if (func_8FB01A74() != 0) {
        var_v0 = (*(s32 *)((u8 *)(arg0) + (0x14)));
        var_v1 = 0;
        var_a0 = (u8 *)arg0;
        if ((s32)(*(u16 *)((u8 *)(arg0) + (0xA))) >= 0) {
            do {
                (*(s8 *)((u8 *)(var_a0) + (0xC))) = (s8) (var_v0 % arg2);
                var_v1 += 1;
                var_v0 = var_v0 / arg2;
                var_a0 += 1;
            } while ((s32)(*(u16 *)((u8 *)(arg0) + (0xA))) >= var_v1);
        }
        return 1;
    }
    return 0;
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB01CF8.s")

extern u8 D_8FB03490[];
extern u8 D_8FB03494[];
extern void Ui_DrawGradientPanel(s32, s32, s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_80049628(s32, s32, s32);
extern void func_800499EC(void);
extern void func_8FB00020(s32, s32, s32);
void func_8FB01EC4(void *arg0) {
    s32 var_s0;
    u8 *var_s1;
    struct { u16 x; u16 y; u16 w; u16 h; s16 offset; u16 count; } *state = arg0;
    Ui_DrawGradientPanel(state->x - 0xA, state->y - 0xA, state->w + 0x14, state->h + 0x14, (s32)&D_8FB03490, (s32)&D_8FB03494);
    func_800498C4();
    func_800496A4(4, 0);
    var_s0 = state->count;
    var_s1 = (u8 *)arg0 + var_s0;
    if (var_s0 >= 0) {
        do {
            func_80049628(state->x + ((state->count - var_s0) * 0x14), state->y, *(s8 *)(var_s1 + 0xC) + 0x30);
            var_s0 -= 1;
            var_s1 -= 1;
        } while (var_s0 >= 0);
    }
    func_800499EC();
    func_8FB00020(state->x + ((state->count - state->offset) * 0x14), state->y + 0x12, 0x14);
}

void func_8FB01FCC(void *arg0) {
    s8 temp_v0;
    u16 temp_v1;
    s32 var_s0;
    u8 *var_s2;
    struct { u16 x; u16 y; u16 w; u16 h; s16 offset; u16 count; } *state = arg0;
    Ui_DrawGradientPanel(state->x - 0xA, state->y - 0xA, state->w + 0x14, state->h + 0x14, (s32)&D_8FB03490, (s32)&D_8FB03494);
    func_800498C4();
    func_800496A4(4, 0);
    var_s0 = state->count;
    var_s2 = (u8 *)arg0 + var_s0;
    if (var_s0 >= 0) {
        do {
            temp_v0 = *(s8 *)(var_s2 + 0xC);
            temp_v1 = state->count;
            if (temp_v0 < 0xA) {
                func_80049628(state->x + ((temp_v1 - var_s0) * 0x14), state->y, temp_v0 + 0x30);
            } else {
                func_80049628(state->x + ((temp_v1 - var_s0) * 0x14), state->y, temp_v0 + 0x37);
            }
            var_s0 -= 1;
            var_s2 -= 1;
        } while (var_s0 >= 0);
    }
    func_800499EC();
    func_8FB00020(state->x + ((state->count - state->offset) * 0x14), state->y + 0x12, 0x14);
}

extern void func_80055A74(s32);
extern s32 func_80055A9C(void *, s32);
extern s32 func_800533A4(s32, s32);
extern s32 func_80053440(s32, s32, u8 *);

void func_8FB02108(unk_func_8FB02108 *state) {
    s32 i;
    s32 pad; // FAKE: reserves the stack word above buffer; diff score 15 without it.
    struct {
        u8 header[0x10];
        u8 entries[6][0x3C];
        u8 tail[8];
    } buffer;
    s32 j;

    for (i = 0; i < 10; i++) {
        _bzero(&buffer, sizeof(buffer));
        func_80055A74(state->index);
        func_80055A9C(&buffer, i);
        state->rows[i].unk_0C = func_800533A4(16, i);
        func_80053440(16, i, state->rows[i].info);
        for (j = 0; j < 6; j++) {
            func_80051830(state->rows[i].entries[j], buffer.entries[j]);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB021F8.s")

extern s32 func_8006B7FC(s32);
struct MsgState *func_8FB02418(s32 arg0)
{
  s32 temp_v0;
  temp_v0 = func_8006B7FC(arg0);
  return func_800718B8(func_8006A600(temp_v0 & 0xFFFF, (temp_v0 & 0xFF) & 0xFFu, 0));
}

extern u8 D_8FB03A6C[];
void *func_8FB02454(void *arg0) {
    u16 temp_a1;
    void *temp_v0;
    void *var_v1;

    temp_a1 = *(u16 *)((u8 *)func_8FB02418((s32)arg0) + 0x3E);
    temp_v0 = func_8004C874(15, temp_a1);
    if (temp_v0 != NULL) {
        var_v1 = temp_v0;
    } else {
        var_v1 = &D_8FB03A6C;
    }
    return var_v1;
}

struct MsgState { u8 pad[0x40]; u32 flags; };
extern struct MsgState *func_8FB02418(s32);
s32 func_8FB02494(s32 arg0) {
    return (func_8FB02418(arg0)->flags >> 31) == 0;
}

/* mkdraft:Fragment9_UpdateSelectionPointers begin */
extern u8 D_8FB034A0[];

typedef u8 Fragment9SelectionColumn[0x220];
void Fragment9_UpdateSelectionPointers(void *state) {
    s32 row_index;

    if (*(s32 *)((u8 *)state + 0x38) < 0) {
        *(s32 *)((u8 *)state + 0x38) = 9;
    }
    if (*(s32 *)((u8 *)state + 0x38) >= 0xA) {
        *(s32 *)((u8 *)state + 0x38) = 0;
    }
    if (*(s32 *)((u8 *)state + 0x3C) < 0) {
        *(s32 *)((u8 *)state + 0x3C) = 5;
    }
    if (*(s32 *)((u8 *)state + 0x3C) >= 6) {
        *(s32 *)((u8 *)state + 0x3C) = 0;
    }
    row_index = *(s32 *)((u8 *)state + 0x3C);
    *(s32 *)((u8 *)state + 0x48) = (s32)(&((Fragment9SelectionColumn *)((u8 *)state + 0x5C))[*(s32 *)((u8 *)state + 0x38)][row_index * 0x58]);
    *(s32 *)((u8 *)state + 0x44) = (s32)((*(s32 *)((u8 *)state + 0x30) * 0x24) + (s32)&D_8FB034A0);
}
/* mkdraft:Fragment9_UpdateSelectionPointers end */

// Leading fields of the D_8FB03DF8 state. func_8FB031E0 draws images[index] with
// func_800495F8; func_8FB029B4 dispatches on mode and func_8FB032C4 runs until mode is 2.
//@src/fragments/9/fragment9_code.c
typedef struct unk_D_8FB03DF8 {
    /* 0x00 */ void *images[6];
    /* 0x18 */ s32 available[6];
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 index;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 mode;
} unk_D_8FB03DF8;

extern void func_80055948(s32);
extern void func_80055A74(s32);
extern void func_80055BF8(void);
extern void func_8FB02108(unk_func_8FB02108 *);
// Loads the image of each of the six entries (func_8FB02454) and whether its message
// state has bit 31 of its flags clear (func_8FB02494), then resets the selection.
void func_8FB02560(unk_D_8FB03DF8 *state) {
    s32 i;

    for (i = 0; i < 6; i++) {
        state->images[i] = func_8FB02454((void *)i);
        state->available[i] = func_8FB02494(i);
    }
    state->unk_30 = 0;
    state->unk_38 = 0;
    state->index = 0;
    state->mode = 0;
    func_80055948(0);
    func_80055948(1);
    func_80055A74(state->index);
    func_80055BF8();
    Fragment9_UpdateSelectionPointers(state);
    func_8FB02108((unk_func_8FB02108 *)state);
}

/* mkdraft:func_8FB02608 begin */
extern s32 func_8FB00170(void *, void *);
extern s32 func_8FB01C14(void *, void *, s32);
extern s32 func_8FB00F78(void *, void *);

// Mode 0 of func_8FB029B4. Runs the page selected by the u16 at offset 2 of
// the record at arg0 + 0x44 on the page state at arg0 + 0x158C (10 units per
// scroll for list pages, 16 for grid pages) and returns its result.
s32 func_8FB02608(void *arg0) {
    s32 var_v1;

    var_v1 = 0;
    switch (*(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x44) + 2)) {
        case 0:
            var_v1 = func_8FB01C14((u8 *)arg0 + 0x158C, arg0, 0xA);
            break;
        case 1:
            var_v1 = func_8FB01C14((u8 *)arg0 + 0x158C, arg0, 0x10);
            break;
        case 2:
            var_v1 = func_8FB00170((u8 *)arg0 + 0x158C, arg0);
            break;
        case 4:
            break;
        case 3:
            var_v1 = func_8FB00F78((u8 *)arg0 + 0x158C, arg0);
            break;
    }
    return var_v1;
}
/* mkdraft:func_8FB02608 end */

extern s32 D_80087200;
extern u8 D_8FB034AE;
extern u8 D_8FB034AF;
extern u8 D_8FB034B0;
extern u8 D_8FB034B1;
void func_8FB02698(void *arg0) {
    u16 buttons;
    u16 pressed;

    buttons = *(u16 *)((u8 *)D_80087200 + 0xC);
    if (buttons & 0x8000) {
        func_800226C0(2);
        if (func_8FB02608(arg0) != 0) {
            *(s32 *)((u8 *)arg0 + 0x40) = 1;
        } else {
            pressed = *(u16 *)((u8 *)*(void **)((u8 *)arg0 + 0x44));
            if (pressed != 0) {
                if (pressed == 2) {
                    func_8FB021F8(arg0);
                    func_8FB02108(arg0);
                    *(s32 *)((u8 *)arg0 + 0x3C) = 0;
                    *(s32 *)((u8 *)arg0 + 0x38) = 0;
                    Fragment9_UpdateSelectionPointers(arg0);
                }
            } else {
                *(s32 *)((u8 *)arg0 + 0x40) = 2;
            }
        }
    } else if (buttons & 0x4000) {
        func_800226C0(3);
        *(s32 *)((u8 *)arg0 + 0x30) = 2;
    } else {
        pressed = buttons;
        if (pressed == 0x800) {
            func_800226C0(1);
            *(s32 *)((u8 *)arg0 + 0x30) =
                ((u8 *)&D_8FB034AE)[*(s32 *)((u8 *)arg0 + 0x30) * 0x24];
        } else if (pressed == 0x400) {
            func_800226C0(1);
            *(s32 *)((u8 *)arg0 + 0x30) =
                ((u8 *)&D_8FB034AF)[*(s32 *)((u8 *)arg0 + 0x30) * 0x24];
        } else if (pressed == 0x200) {
            func_800226C0(1);
            *(s32 *)((u8 *)arg0 + 0x30) =
                ((u8 *)&D_8FB034B0)[*(s32 *)((u8 *)arg0 + 0x30) * 0x24];
        } else if (pressed == 0x100) {
            func_800226C0(1);
            *(s32 *)((u8 *)arg0 + 0x30) =
                ((u8 *)&D_8FB034B1)[*(s32 *)((u8 *)arg0 + 0x30) * 0x24];
        } else if (pressed & 8) {
            func_800226C0(1);
            *(s32 *)((u8 *)arg0 + 0x3C) -= 1;
        } else if (pressed & 4) {
            func_800226C0(1);
            *(s32 *)((u8 *)arg0 + 0x3C) += 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/9/fragment9_code/func_8FB02878.s")

extern void Fragment9_UpdateSelectionPointers(void *);
extern void func_8FB02698(void *);
extern void func_8FB02878(void *);
void func_8FB029B4(void *arg0) {
    s32 temp_v0;

    temp_v0 = (*(s32 *)((u8 *)(arg0) + (0x40)));
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_8FB02698(arg0);
        break;
    case 1:
        func_8FB02878(arg0);
        break;
    }
    Fragment9_UpdateSelectionPointers(arg0);
}

/* func_8FB02A10 is still GLOBAL_ASM, but its .s is hand-maintained (not the
 * splat-generated asm/us/nonmatchings/.../func_8FB02A10.s) so it can also
 * carry jtbl_8FB03D2C, its own 38-entry switch table, in a .late_rodata
 * block ahead of its .text. The table's bytes are inside this file's
 * [0xD4170, .rodata] range, but splat lists no user for them (this
 * hand-maintained .s is not among the files it regenerates), so nothing
 * but this block emits them. asm-processor places the block at this
 * pragma's position in the .rodata stream: right after func_8FB02878's
 * two tables and immediately before func_8FB03164's own
 * compiler-generated jtbl_8FB03DC4, the exact retail order. A plain C
 * global here would instead be emitted by IDO ahead of ALL switch-table
 * "late" rodata in this compilation (before jtbl_8FB03DC4, which is right
 * where we want it) -- but ahead of the file's other regular named rodata
 * too, changing its order and thus its address, since IDO groups named
 * rodata together in emission order across the whole file. */
#pragma GLOBAL_ASM("hand_asm/fragments/9/func_8FB02A10_manual.s")

extern void func_8FB009C0(void *arg0);
extern void func_8FB011DC(void *arg0, void *arg1);
void func_8FB03164(void *arg0) {
    switch ((*(u16 *)((u8 *)(*(void **)((u8 *)(arg0) + (0x44))) + (2)))) {
    case 0:
        func_8FB01EC4((void *)((u8 *)(arg0) + (0x158C)));
        break;
    case 1:
        func_8FB01FCC((void *)((u8 *)(arg0) + (0x158C)));
        break;
    case 2:
        func_8FB009C0((void *)((u8 *)(arg0) + (0x158C)));
        break;
    case 3:
        func_8FB011DC((void *)((u8 *)(arg0) + (0x158C)), arg0);
        break;
    case 4:
        break;
    }
}

extern u8 D_8FB03B2C[];
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(Gfx **, s32);
extern void func_800495F8(s32, s32, s32, s32);
extern void func_80008648(void);
extern void func_8FB02A10(void *, s32);
extern void func_8FB03164(void *);
void func_8FB031E0(void *arg0) {
    s32 var_s0;
    s32 var_s1;
    struct { u8 pad[0x34]; s32 index; } *state = arg0;
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 0x89);
    func_800498C4();
    func_800496A4(0x10, 0);
    func_800495F8(0x140, 0x1E, 1, (s32)&D_8FB03B2C);
    func_800496A4(8, 0);
    var_s0 = 0;
    var_s1 = 0x1E;
    do {
        func_8FB02A10(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 != var_s1);
    func_800495F8(0x64, 0x46, 1, *(s32 *)((u8 *)arg0 + (state->index << 2)));
    func_800499EC();
    if (*(s32 *)((u8 *)arg0 + 0x40) == 1) {
        func_8FB03164(arg0);
    }
    func_80008648();
}

extern u8 D_8FB03DF8;
void func_80064D28(void);

void func_8FB032C4(s32 arg0, s32 arg1) {
    if ((*(s32 *)((u8 *)(&D_8FB03DF8) + (0x40))) != 2) {
        do {
            func_80064D28();
            func_8FB029B4(&D_8FB03DF8);
            func_8FB031E0(&D_8FB03DF8);
        } while ((*(s32 *)((u8 *)(&D_8FB03DF8) + (0x40))) != 2);
    }
}

extern void func_800060F4(s32, s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_8004C4B0(s32);
extern s32 func_80047588(s32, s32);
extern void func_8FB02560(unk_D_8FB03DF8 *);
extern void func_80008514(s32);
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern s32 D_8FB03DF0;
void func_8FB03328(s32 arg0, s32 arg1) {
    s32 sp24;
    func_800060F4(0xF, 2);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(0x107);
    func_8004C4B0(6);
    func_8004C4B0(8);
    func_8004C4B0(0x41);
    func_8004C4B0(0xF);
    func_8004C4B0(0x2A);
    D_8FB03DF0 = func_80047588(0x1E, 0);
    func_8FB02560((unk_D_8FB03DF8 *)&D_8FB03DF8);
    func_80008514(sp24);
    func_800086A4(2);
    StageFade_StartFromOpaque(0x10);
}

extern void Gfx_FreeDisplayListBuffers();
extern void func_80008574();
extern void func_80047610();
extern void func_8004C398();

void func_8FB033F0(s32 arg0, s32 arg1) {
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
}

extern void func_8FB032C4(s32, s32);
extern void func_8FB03328(s32, s32);
extern void main_pool_pop_state(s32);
extern void main_pool_push_state(s32);
s32 fragment9_main(s32 arg0, s32 arg1) {
    main_pool_push_state(0x52504D45);
    func_8FB03328(arg0, arg1);
    func_8FB032C4(arg0, arg1);
    func_8FB033F0(arg0, arg1);
    main_pool_pop_state(0x52504D45);
    return 0;
}
#endif
