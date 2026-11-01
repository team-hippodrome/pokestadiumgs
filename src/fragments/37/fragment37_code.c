#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void main_pool_push_state(s32);
extern void *Util_Malloc(s32);
extern u8 *D_88804050;
extern void func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);
extern void func_88004FF0(s32);
extern void func_8004C4B0(s32);
extern void *D_80128C64;
extern void *ModelPreview_Create(void *, s32, s32);
extern void func_80042D74(void *, void *);
extern void func_88005714(void);
extern s32 func_80001FF0(void);
void func_88800020(void) {

    main_pool_push_state(0x504D494E);
    D_88804050 = Util_Malloc(0x3C8);
    func_8004C8C0(0x14C);
    *(s32 *)(D_88804050 + 0x360) = func_8004C990(0x14C, 0);
    *(s32 *)(D_88804050 + 0x364) = func_8004C990(0x14C, 1);
    *(s32 *)(D_88804050 + 0x368) = func_8004C990(0x14C, 2);
    *(s32 *)(D_88804050 + 0x36C) = func_8004C990(0x14C, 3);
    *(s32 *)(D_88804050 + 0x370) = func_8004C990(0x14C, 4);
    *(s32 *)(D_88804050 + 0x374) = func_8004C990(0x14C, 5);
    *(s32 *)(D_88804050 + 0x378) = func_8004C990(0x14C, 6);
    *(s32 *)(D_88804050 + 0x37C) = func_8004C990(0x14C, 7);
    *(s32 *)(D_88804050 + 0x380) = func_8004C990(0x14C, 8);
    *(s32 *)(D_88804050 + 0x384) = func_8004C990(0x14C, 9);
    *(s32 *)(D_88804050 + 0x388) = func_8004C990(0x14C, 10);
    *(s32 *)(D_88804050 + 0x38C) = func_8004C990(0x14C, 11);
    *(s32 *)(D_88804050 + 0x390) = func_8004C990(0x14C, 12);
    *(s32 *)(D_88804050 + 0x394) = func_8004C990(0x14C, 13);
    *(s32 *)(D_88804050 + 0x398) = func_8004C990(0x14C, 14);
    *(s32 *)(D_88804050 + 0x39C) = func_8004C990(0x14C, 15);
    *(s32 *)(D_88804050 + 0x3A0) = func_8004C990(0x14C, 16);
    *(s32 *)(D_88804050 + 0x3A4) = func_8004C990(0x14C, 17);
    func_88004FF0(0x3A);
    func_8004C4B0(0x26);
    func_8004C4B0(0xE);
    func_8004C4B0(7);
    *(void **)(D_88804050 + 8) = ModelPreview_Create(D_80128C64, 0x8A, 0x6E);
    **(u16 **)(D_88804050 + 8) &= 0xFFFD;
    func_80042D74(*(void **)(D_88804050 + 8), func_88005714);
    D_88804050[0x51] = (s32)(16.0f * func_80001FF0() / 60.0f + ((func_80001FF0() * 16.0f / 60.0f > 0.0f) ? 0.5f : -0.5f));
    if (D_88804050[0x51] & 1) {
        D_88804050[0x51]++;
    }
}

extern void Util_Free(void *);
extern void main_pool_pop_state(s32);
extern u8 *D_88804050;
void func_888002DC(void) {
    Util_Free(D_88804050);
    main_pool_pop_state(0x504D494E);
}

s32 func_8880030C(void)
{
  u16 flags;
  s32 result = 0 * 0;
  if (((D_80087200->buttonsPressed) & 1) != 0)
  {
    result = 1;
  }
  else
    if (((D_80087200->buttonsPressed) & 4) != 0)
  {
    result = 2;
  }
  else
    if (((D_80087200->buttonsPressed) & 2) != 0)
  {
    result = 3;
  }
  return result;
}

void func_88800354(void)
{
  unsigned int temp_a0;
  *((s32 *) (((u8 *) D_88804050) + 0)) = (s32) (*((s32 *) (((u8 *) D_88804050) + 4)));
  *((s8 *) (((u8 *) D_88804050) + 0x11)) = 2;
  *((s32 *) (((u8 *) D_88804050) + 0x14)) = 0;
  temp_a0 = *((s32 *) (((u8 *) D_88804050) + 0));
  if (temp_a0 == 1)
  {
    *((s8 *) (((u8 *) D_88804050) + 0x50)) = (s8) (((s32) (*((u8 *) (((u8 *) D_88804050) + 0x51)))) >> 1);
    return;
  }
  if (temp_a0 == 2)
  {
    Input_SetRepeatController(D_80087200);
  }
}

void func_888003CC(void) {
    *(s32 *)D_88804050 = 0;
    D_88804050[0x11] = 2;
}

/* mkdraft:func_888003EC begin */
extern u8 *D_88804050;
extern u8 *D_880068B0;
extern s16 D_8800EF58;
extern void func_800226C0(s32);
extern s32 func_8880030C(void);
extern void func_88004990(u8, u8);
extern void func_88002720(s16 *, u16, u8 *);



void func_888003EC(void)
{
  u32 buttons;
  s32 item;
  u8 index;
  if ((*((s32 *) D_88804050)) == 1)
  {
    buttons = D_80087200->buttonsPressed;
    if (buttons & 0x4000)
    {
      func_800226C0(*((s32 *) (D_88804050 + 0x358)));
      func_88004990(*(*((u8 **) (D_88804050 + 0x20))), 0);
      *((s32 *) (D_88804050 + 0x14)) = 1;
      D_88804050[0x50] = 0;
      *((s8 *) (D_88804050 + 0x26)) = -1;
    }
    else
      if (buttons & 0xF)
    {
      item = func_8880030C();
      index = item;
      if ((item == (*((s8 *) (D_88804050 + 0x26)))) || ((*((u8 *) ((D_880068B0 + item) + 2))) == 0))
      {
        func_800226C0(*((s32 *) (D_88804050 + 0x35C)));
      }
      else
      {
        *((s8 *) (D_88804050 + 0x26)) = index;
        func_800226C0(*((s32 *) (D_88804050 + 0x354)));
        D_88804050[0x50] = D_88804050[0x51] >> 1;
      }
    }
    D_88804050[0x50]++;
    if (D_88804050[0x50] < D_88804050[0x51])
    {
      return;
    }
    D_88804050[0x50] = 0;
  }
  else
    if ((*((s32 *) D_88804050)) == 2)
  {
    if (D_8800EF58 == 0)
    {
      buttons = D_80087200->buttonsPressed;
      if ((buttons & 0x1000) || ((buttons & 0x4000) && ((*((s8 *) (D_88804050 + 0x26))) == (-1))))
      {
        func_800226C0(*((s32 *) (D_88804050 + 0x358)));
        func_88004990(*(*((u8 **) (D_88804050 + 0x20))), 0);
        *((s32 *) (D_88804050 + 0x14)) = 1;
        *((s8 *) (D_88804050 + 0x27)) = -1;
        *((s8 *) (D_88804050 + 0x26)) = *((s8 *) (D_88804050 + 0x27));
        return;
      }
      if ((buttons & 0x4000) && ((*((s8 *) (D_88804050 + 0x26))) != (-1)))
      {
        func_800226C0(*((s32 *) (D_88804050 + 0x358)));
        *((s8 *) (D_88804050 + 0x11)) = 3;
        D_88804050[(*((s8 *) (D_88804050 + 0x26))) + 0x3B0] = 0;
        *((s8 *) (D_88804050 + 0x26)) = -1;
        return;
      }
      if (buttons & 0x8000)
      {
        if (D_880068B0[3] != 0)
        {
          if ((*((s8 *) (D_88804050 + 0x26))) == (-1))
          {
            unsigned int cursor;
            func_800226C0(*((s32 *) (D_88804050 + 0x354)));
            *((s8 *) (D_88804050 + 0x11)) = 3;
            *((s8 *) (D_88804050 + 0x26)) = *((s16 *) (D_88804050 + 0x24));
            D_88804050[(*((s16 *) (D_88804050 + 0x24))) + 0x3B0] = 1;
            cursor = *((s16 *) (D_88804050 + 0x24));
            do
            {
              if (3 == (cursor ^ 0))
              {
                *((s16 *) (D_88804050 + 0x24)) = 0;
              }
              else
              {
                *((s16 *) (D_88804050 + 0x24)) = cursor + 1;
              }
              cursor = *((s16 *) (D_88804050 + 0x24));
            }
            while ((*((u8 *) ((D_88804050 + cursor) + 0x3B0))) != 0);
            return;
          }
          if ((*((s8 *) (D_88804050 + 0x27))) == (-1))
          {
            func_800226C0(0x5D);
            func_800226C0(0x63);
            *((s8 *) (D_88804050 + 0x11)) = 3;
            *((s8 *) (D_88804050 + 0x27)) = *((s16 *) (D_88804050 + 0x24));
 D_88804050[(*((s8 *) (D_88804050 + 0x26))) + 0x3B0] = 0; D_88804050[(*((s8 *) (D_88804050 + 0x27))) + 0x3B0] = 0;
            (*((void (**)(s8, s8, u16)) (D_88804050 + 0x58)))(*((s8 *) (D_88804050 + 0x26)), *((s8 *) (D_88804050 + 0x27)), *((u16 *) (D_88804050 + 0x3B4)));
          }
        }
      }
      else
      {
        func_88002720((s16 *) (D_88804050 + 0x24), 4, D_88804050 + 0x3A8);
      }
    }
  }
}
/* mkdraft:func_888003EC end */

/* mkdraft:func_88800714 begin */
struct Color88800DC0;
extern u8 *D_88804050;
extern u8 *D_8800687C;
extern u8 *D_880068B0;
extern u8 D_88005FA0[];
extern s16 D_8800EF58;
extern struct Color88800DC0 *func_88000510(struct Color88800DC0 *, s8);
extern void func_880006E0(struct Color88800DC0 *);
extern void func_880006BC(void *);
extern const char *func_8004C874(s32, s32);
extern const char *func_80062CE0(u8);
extern u8 func_80062D98(u8);
extern u8 func_80062D5C(u8);
extern u8 func_80062DD4(u8);
extern s8 *func_80063270(u8);
extern s8 *func_80049290(s32, s8, s8 *);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800498C4(void);
extern void func_8004989C(s32);
extern void func_800499EC(void);
extern void func_800496A4(s32, s32);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);

// Draws the move summary panel: the move name (func_8004C874 table 0x26), a 0..100
// value derived from func_80062DD4(move) * 100 / 255, a color that func_88000510
// builds from func_80062D98(move) and func_880006E0 draws, and the effect string
// from func_80062CE0(move). The move ID is read from the per-Pokemon move table
// (move IDs at +2, as in func_88800D34), indexed by the s8 at 0x26 of D_88804050
// for state 1 and by the s16 at 0x24 for state 2.


void func_88800714(void) {
    const char *sp44;
    u8 sp43;
    u8 sp40[3];
    u8 sp3F;
    u8 sp3E;

    sp44 = func_8004C874(0x26, 0x15);
    if (*(s32 *)D_88804050 == 1) {
        // FAKE: D_880068B0 is reached through `*(u8 **)&D_880068B0`, the pointer stored
        // at the symbol's address instead of the symbol's value. Both spellings name the
        // same pointer, but uopt only loads the table base before the index byte
        // (`lw t6,%lo(D_880068B0)`, then `lb t7,0x26(v1)`) with the address-of form;
        // diff score 430 without it (plain `D_880068B0` in both branches), 215 with it
        // in one branch only.
        sp43 = (*(s8 *)(D_88804050 + 0x26) + *(u8 **)&D_880068B0)[2];
    } else if (*(s32 *)D_88804050 == 2) {
        if (D_8800EF58 != 0) {
            return;
        }
        sp43 = (*(s16 *)(D_88804050 + 0x24) + *(u8 **)&D_880068B0)[2];
    }
    //!bug: only state 1 and state 2 assign sp43. Any other state falls through and the
    // test below reads the uninitialized stack slot (retail `lbu t5,0x43(sp)`).
    if (((s32)sp43 > 0) && ((s32)sp43 < 252)) {
        sp3E = func_80062D5C(sp43);
        func_800498C4();
        func_8004989C(0x14);
        func_880006BC(D_88005FA0);
        func_800496A4(4, 0);
        func_80048E30(D_8800687C, 0x1BB, 0x103, sp44, 1);
        if ((sp3E == 0) || (sp3E == 1)) {
            func_800495F8(0x12F, 0x117, 0, "%s%s", func_8004C874(0x26, 0x16), func_8004C874(0x26, 0x18));
        } else {
            func_800495F8(0x12F, 0x117, 0, "%s%3d", func_8004C874(0x26, 0x16), (s32)sp3E);
        }
        func_800495F8(0x1AD, 0x117, 0, "%s%3d", func_8004C874(0x26, 0x17),
            (s32)(((f32)(func_80062DD4(sp43) * 100) / 255.0f) +
                (((f32)(func_80062DD4(sp43) * 100) / 255.0f) > 0.0f ? 0.5f : -0.5f)));
        func_80048E30(D_8800687C, 0x12F, 0x12F, func_8004C874(7, (s32)sp43 - 1), 1);
        sp3F = func_80062D98(sp43);
        func_880006E0(func_88000510((struct Color88800DC0 *)&sp40, (s8)sp3F));
        // Message 0x1BB, plus the byte at 0x78 of D_8800687C twice: once through
        // func_80049290 and once directly.
        func_80048E30(D_8800687C, (s32)(*(s8 *)(D_8800687C + 0x78) + func_80049290(0, *(s8 *)(D_8800687C + 0x78), sp44)) + 0x1BB, 0x103, func_80063270(sp3F), 1);
        func_800496A4(8, 0);
        func_80048E30(D_8800687C, 0x12F, 0xFF, func_80062CE0(sp43), 1);
        func_800499EC();
    }
}
/* mkdraft:func_88800714 end */

extern s32 func_88004804(s32, s32, s16, s16, s32, s32, s32, s32, s32,
                         void (*)(void), void (*)(void), void (*)(void),
                         void (*)(void), s32, s32);
extern void func_800226C0(s32);
extern u8 D_8800ED50[];
extern void func_888003EC(void);
extern void func_88800714(void);
void func_88800A30(void) {
    s32 result;

    result = func_88004804(0, 3, 292, 244, 0, 1, D_88804050[0x34A], D_88804050[0x34B], D_88804050[0x34C],
                           func_888003EC, func_88800714, func_88800354, func_888003CC, 0, D_88804050[0x5C]);
    *(u8 **)(D_88804050 + 0x20) = D_8800ED50 + result * 0x4C;
    *(s16 *)(*(u8 **)(D_88804050 + 0x20) + 0x10) = 279;
    *(s16 *)(*(u8 **)(D_88804050 + 0x20) + 0x12) = 129;
    func_800226C0(*(s32 *)(D_88804050 + 0x354));
}

extern s32 func_80001FF0(void);
extern void func_880002F4(u8 *, s16);
extern u8 * D_88804050;
void func_88800B24(void) {
    ((s8 *)D_88804050)[0x27] = -1;
    ((s8 *)D_88804050)[0x26] = ((s8 *)D_88804050)[0x27];
    D_88804050[0x11] = 3;
    if (D_88804050[0x2A] != 0) {
        // Rounds frame-rate-scaled durations (func_80001FF0 returns 50 or 60).
        func_880002F4(D_88804050 + 0x2C,
                      (s32)((5.0f * func_80001FF0() / 60.0f) + (((func_80001FF0() * 5.0f / 60.0f) > 0.0f) ? 0.5f : -0.5f)) +
                      (s32)((8.0f * func_80001FF0() / 60.0f) + (((func_80001FF0() * 8.0f / 60.0f) > 0.0f) ? 0.5f : -0.5f)) +
                      (s32)((30.0f * func_80001FF0() / 60.0f) + (((func_80001FF0() * 30.0f / 60.0f) > 0.0f) ? 0.5f : -0.5f)));
    }
}

extern u8 *D_880068B0;
extern u8 func_80062EB0(u8, u8);
extern void func_88000FC4(s32, s32, s32, s32, s16, s16);
void func_88800D34(s8 slot) {
    // Byte arrays indexed by move slot: move IDs at +2, PP bytes at +0x18 (low 6 bits = current PP).
    if ((D_880068B0 + 2)[slot] != 252) {
        func_88000FC4(273, slot * 27 + 259, 1, 1, (D_880068B0 + 0x18)[slot] & 0x3F,
                      func_80062EB0((D_880068B0 + 2)[slot], (D_880068B0 + 0x18)[slot]) & 0x3F);
    }
}

typedef struct Color88800DC0 {
    u8 red;
    u8 green;
    u8 blue;
} Color88800DC0;
extern u8 *D_880068B0;
extern u8 *D_8800687C;
extern Color88800DC0 *func_88000510(Color88800DC0 *, s8);
extern void func_880006E0(Color88800DC0 *);
extern u8 func_80062D98(u8);
extern const char *func_80062CE0(u8);
extern const char *func_8004C874(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
void func_88800DC0(s8 index, u8 alpha) {
    u8 move;
    Color88800DC0 color;

    if (alpha == 0) {
        return;
    }
    move = (D_880068B0 + 2)[index];
    func_88000510(&color, move == 252 ? 0 : func_80062D98(move));
    if (alpha == 255) {
        func_880006E0(&color);
    } else {
        func_8004972C(color.red, color.green, color.blue, alpha);
    }
    func_80048E30(D_8800687C, 0x87, index * 27 + 0x100, move == 252 ? func_8004C874(0x26, 0x2A) : func_80062CE0(move), 1);
}

extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern s32 func_8004D1FC(u8 *arg0);
extern u8 func_80062D98(u8);
void func_88800EC8(s8 arg0) {
    u8 value;
    void *ptr;

    value = ((s8 *)D_880068B0)[arg0 + 2];
    if (value == 252) {
        D_88804050[0x29] = 19;
    } else {
        D_88804050[0x29] = func_80062D98(value);
    }

    if (((s8 *)D_88804050)[0x28] != ((s8 *)D_88804050)[0x29]) {
        switch (((s8 *)D_88804050)[0x29]) {
            case 7: ptr = *(void **)(D_88804050 + 0x360); break;
            case 26: ptr = *(void **)(D_88804050 + 0x364); break;
            case 23: ptr = *(void **)(D_88804050 + 0x368); break;
            case 19: ptr = *(void **)(D_88804050 + 0x36C); break;
            case 27: ptr = *(void **)(D_88804050 + 0x370); break;
            case 1: ptr = *(void **)(D_88804050 + 0x374); break;
            case 20: ptr = *(void **)(D_88804050 + 0x378); break;
            case 2: ptr = *(void **)(D_88804050 + 0x37C); break;
            case 8: ptr = *(void **)(D_88804050 + 0x380); break;
            case 22: ptr = *(void **)(D_88804050 + 0x384); break;
            case 4: ptr = *(void **)(D_88804050 + 0x388); break;
            case 25: ptr = *(void **)(D_88804050 + 0x38C); break;
            case 0: ptr = *(void **)(D_88804050 + 0x390); break;
            case 3: ptr = *(void **)(D_88804050 + 0x394); break;
            case 24: ptr = *(void **)(D_88804050 + 0x398); break;
            case 5: ptr = *(void **)(D_88804050 + 0x39C); break;
            case 9: ptr = *(void **)(D_88804050 + 0x3A0); break;
            case 21: ptr = *(void **)(D_88804050 + 0x3A4); break;
        }
        func_8004D1FC(ptr);
        ((s8 *)D_88804050)[0x28] = ((s8 *)D_88804050)[0x29];
    }

    GfxRect_DrawTextured(
        111,
        (s16)(arg0 * 27 + 256),
        *(s16 *)((u8 *)*(void **)(D_88804050 + 0x360) + 0),
        *(s16 *)((u8 *)*(void **)(D_88804050 + 0x360) + 2),
        0, 0, 1024, 1024, 0);
}

extern void func_800496A4(s32, s32);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
extern s32 func_8004B7A4(s32);
extern u8 *D_8800687C;
extern u8 *D_880068B0;
void func_888010B0(void) {
    func_800496A4(4, 1);
    func_80048E30(D_8800687C, 0x170, 0x62, (const char *)(D_88804050 + 0x335), 1);
    func_800496A4(8, 1);
    func_80048E30(D_8800687C, 0x1D1, 0x5E, (const char *)func_8004B7A4(*D_880068B0), 1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88801138.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88801554.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88802DCC.s")
#endif
