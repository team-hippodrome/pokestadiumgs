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

extern s32 func_8800335C(void);

extern void func_88801138(void);

extern s32 D_88804058;

void func_88801138(void) {
    s32 a3;
    s32 v0;
    s32 a1;
    s32 timer;
    u8 index;
    u16 buttons;
    s32 i;
    s32 state = 3;
    u8 *available;

    timer = D_88804050[0x10];
    if (timer != 0) {
        D_88804050[0x10] = timer - 1;
        if (D_88804050[0x10] != 0) return;
        *(s32 *)(*(s32 *)(D_88804050 + 0x1C) + 0x34) = 0;
        timer = *(s32 *)D_88804050;
        if (timer == 3 || timer == 4) {
            *(s32 *)(D_88804050 + 0x14) = 0;
        }
        return;
    }
    buttons = D_88804050[0x11];
    if (buttons != 0) {
        a1 = *(s32 *)D_88804050;
        v0 = *(u32 *)D_88804050;
        if (a1 != 3 && v0 != 4) {
            D_88804050[0x11] = buttons - 1;
            return;
        }
        buttons = D_80087200->buttonsPressed;
        a3 = 1;
        if ((buttons & 0xC000) != 0) {
            v0 = 0;
            if ((buttons & 0x8000) != 0) {
                if (state == a1 && *(s32 *)(D_88804050 + 0x3B8) != 0) {
                    a3 = 0;
                } else if (*(s16 *)(D_88804050 + 0x24) == 0) {
                    D_88804058 = 1;
                    func_800226C0(0x92);
                } else {
                    v0 = 1;
                }
            } else if ((buttons & 0x4000) != 0) {
                v0 = 1;
            }
        if (v0 != 0) {
            func_800226C0(*(s32 *)(D_88804050 + 0x358));
        }
        if (a3 == 0) return;
        func_88004990(*(u8 *)(*(s32 *)(D_88804050 + 0x1C)), 0);
        *(s32 *)(*(s32 *)(D_88804050 + 0x1C) + 0x34) = 1;
        (*(void (*)(void))(*(s32 *)(D_88804050 + 0x54)))();
        return;
        } else {
            if (*(s32 *)(D_88804050 + 0x3B8) != 0) return;
            v0 = *(s16 *)(D_88804050 + 0x24);
            switch (v0) {
            case 0:
                if ((buttons & 0x100) != 0) {
                    func_800226C0(*(s32 *)(D_88804050 + 0x350));
                    *(s16 *)(D_88804050 + 0x24) = 1;
                }
                break;
            case 1:
                if ((buttons & 0x200) != 0) {
                    func_800226C0(*(s32 *)(D_88804050 + 0x350));
                    *(s16 *)(D_88804050 + 0x24) = 0;
                }
                break;
            }
            return;
        }
    }
    if (func_8800335C() != 0) return;
    if (*(s32 *)D_88804050 != 0) return;
    buttons = D_80087200->buttonsPressed;
    if ((buttons & 0x4000) != 0) {
        func_800226C0(*(s32 *)(D_88804050 + 0x358));
        func_88004990(*(u8 *)(*(s32 *)(D_88804050 + 0x1C)), 0);
        *(s32 *)(*(s32 *)(D_88804050 + 0x1C) + 0x34) = 1;
        (*(void (*)(void))(*(s32 *)(D_88804050 + 0x54)))();
        return;
    }
    if ((D_880068B0[0x1E] & 1) != 0) return;
    if ((buttons & 0xF) != 0) {
        v0 = func_8880030C();
        index = v0;
        if (((u8 *)D_880068B0 + v0)[2] == 0) {
            func_800226C0(*(s32 *)(D_88804050 + 0x35C));
            return;
        }
        func_88800A30();
        *(s32 *)(D_88804050 + 4) = 1;
        D_88804050[0x26] = index;
        return;
    }
    if ((buttons & 0x1000) != 0) {
        func_88800A30();
        *(s32 *)(D_88804050 + 4) = 2;
        ((s8 *)D_88804050)[0x27] = -1;
        ((s8 *)D_88804050)[0x26] = ((s8 *)D_88804050)[0x27];
        available = D_880068B0 + 2;
        for (i = 0; i < 4; i++, available++) {
            if (*available == 0) D_88804050[0x3B0 + i] = 1;
            else D_88804050[0x3B0 + i] = 0;
        }
    }
}
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern u8 D_80094DE0[];
extern u8 D_80094E00[];
extern s32 D_88804054;
extern u8 *D_88803EF0[];
extern u8 *D_8800ECC4, *D_8800ECC8, *D_8800ECC0;
extern s32 D_8800ECF8, D_8800ECDC, D_8800ECF0, D_8800ECD8, D_8800ECF4;
extern s32 func_80043678(s32);
extern void func_800088DC(void);
extern void func_88002C2C(u8, u8, u8);
extern void func_80006F70(Gfx **, s32, s32, s32, s32);
extern s32 func_8004CA10(u8 *);
extern void func_88002BA0(s32, s32, s32);
extern void func_8004D334(s32, s32);
extern void func_8004D40C(s32);
extern s32 func_88005CC0(s32, s8 *);
extern void func_8004D27C(u8 *, s32, s32);
extern void func_88002EC0(s32, s32, s32, s32, s32);
extern void func_88002CB8(s32, s32, s32, s32);
extern u8 func_8006461C(u8);
extern s32 Envelope_Advance(u8 *);
extern void *Color_SetRGB(void *, u8, u8, u8);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern void func_880008B0(s32, s32, s32);
extern s32 func_8006397C(u8);
extern s32 func_800639C0(u8);
extern void func_80049064(s32, s32, s32, const char *);
extern const char *func_800646C8(u16, u8);
extern void func_88000308(u8 *, s16);
extern s32 func_8006456C(u16);
extern s32 func_80063754(u8);
extern s32 func_8006483C(u8 *);
extern void func_88005F08(void);
extern void func_880015F4(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_8004B2CC(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_8004B314(s32, s32, s32, s32);
extern s32 func_8800335C(void);

#define DU8(o) (D_88804050[o])
#define DS32(o) (*(s32 *)(D_88804050 + (o)))
#define DS16(o) (*(s16 *)(D_88804050 + (o)))
#define DU16(o) (*(u16 *)(D_88804050 + (o)))
#define DPTR(o) ((char *)(D_88804050 + (o)))
#define BU8(o) (D_880068B0[o])
#define SCALE(a, b, k) ((s32)(1024.0f * (a) / (k) + (((b) * 1024.0f / (k) > 0.0f) ? 0.5f : -0.5f)))

void func_88801554(void) {
    s8 idx;
    s16 y;
    u8 alpha;
    s16 tmp;
    s32 v;
    Color88800DC0 col2;
    const char *str;

    str = func_8004C874(38, 43);
    DS32(0xC) = func_80043678(DS32(8));
    func_800088DC();
    gSPDisplayList(D_800D0510++, D_80094E38);
    if (DU8(0x10) == 0) {
        func_8004D1FC(D_8800ECC4);
        func_88002C2C(DU8(0x34A), DU8(0x34B), DU8(0x34C));
        if (DS32(0x14) == 0) {
            func_80006F70(&D_800D0510, 66, 244, 262, 129);
        }
        GfxRect_DrawTextured(66, 244, 507, 129, 0, 0, SCALE((f32)func_8004CA10(D_8800ECC4), (f32)func_8004CA10(D_8800ECC4), 507.0f), 0, 0);
        if (DS32(0x14) == 0) {
            func_80006F70(&D_800D0510, 0, 0, 640, 480);
        }
        if (DU8(0x11) != 0) {
            GfxRect_DrawTextured(66, 407, 507, 32, 0, 0, SCALE((f32)func_8004CA10(D_8800ECC4), (f32)func_8004CA10(D_8800ECC4), 507.0f), 0, 0);
        }
        if (DS32(0x18) != 0) {
            GfxRect_DrawTextured(66, 90, 507, 26, 0, 0, SCALE((f32)func_8004CA10(D_8800ECC4), (f32)func_8004CA10(D_8800ECC4), 507.0f), 0, 0);
        }
    }
    func_88002BA0(0xFF, 0xFF, 0xFF);
    if (!(BU8(0x1E) & 1)) {
        func_8004D334(239, 0);
        func_8004D40C(1);
        idx = 0;
        do {
            if ((D_880068B0 + 2)[idx] == 0) {
                break;
            }
            if (func_88005CC0(2, &idx) == 0) {
                func_88800D34(idx);
            }
            idx++;
        } while (idx < 4);
    }
    func_8004D27C(D_8800ECC8, 0x100, 2);
    func_88002EC0(74, 244, 254, 126, 3);
    if (DS32(0x14) != 0) {
        func_88002EC0(336, 244, 229, 126, 3);
    }
    if (DU8(0x10) != 0) {
        func_88002EC0(74, 120, 144, 116, 3);
        func_88002EC0(226, 120, 198, 116, 3);
        func_88002EC0(432, 120, 133, 116, 3);
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, ((Color88800DC0 *)DPTR(0x34A))->red, ((Color88800DC0 *)DPTR(0x34A))->green, ((Color88800DC0 *)DPTR(0x34A))->blue, 0xFF);
        func_8004D27C(D_8800ECC0, 0x80, 1);
        func_88002CB8(61, 79, 520, 327);
        func_88002CB8(61, 402, 520, 45);
    } else {
        switch (DS32(0)) {
            case 3:
            case 4:
                gDPPipeSync(D_800D0510++);
                gDPSetEnvColor(D_800D0510++, ((Color88800DC0 *)DPTR(0x34A))->red, ((Color88800DC0 *)DPTR(0x34A))->green, ((Color88800DC0 *)DPTR(0x34A))->blue, 0xFF);
                func_8004D27C(D_8800ECC0, 0x80, 1);
                func_88002CB8(61, 402, 520, 45);
                break;
        }
    }
    if (!(BU8(0x1E) & 1)) {
        v = func_8006461C(BU8(0x20));
        if (v == 1 || v == 2) {
            gDPPipeSync(D_800D0510++);
            gDPSetCombine(D_800D0510++, 0x309661, 0x552EFF7F);
            gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0x78, 0x00, 0xFF);
            if (v == 1) {
                u8 e;
                u8 g;
                Color88800DC0 col3;
                e = Envelope_Advance(D_88804050 + 68);
                g = (s32)(120.0f * (u32)e / 255.0f + (((u32)e * 120.0f / 255.0f > 0.0f) ? 0.5f : -0.5f));
                Color_SetRGB(&col3, e, g, 0);
                gDPSetEnvColor(D_800D0510++, col3.red, col3.green, col3.blue, 0xFF);
            } else if (v == 2) {
                gDPSetEnvColor(D_800D0510++, 0, 0, 0, 0xFF);
            }
            func_8004D19C(400, 211, D_8800ECF8, 0, 0);
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    gSPDisplayList(D_800D0510++, D_80094DE0);
    if (DS32(0x14) != 0) {
        func_880008B0(345, 293, 211);
        func_880008B0(345, 339, 211);
    }
    if (DU8(0x10) != 0) {
        func_880008B0(235, 175, 180);
        func_880008B0(235, 205, 180);
    }
    func_800498C4();
    if (DS32(0x14) != 0) {
        func_800496A4(4, 1);
        func_80048E30(D_8800687C, 345, 253, DPTR(0x1DD), 1);
        func_80048E30(D_8800687C, 345, 273, DPTR(0x21D), 1);
        if (!(BU8(0x1E) & 1)) {
            func_80048E30(D_8800687C, 345, 299, DPTR(0x25D), 1);
            if (BU8(0) != 252) {
                func_80048E30(D_8800687C, 345, 319, DPTR(0x29D), 1);
            }
            func_80048E30(D_8800687C, 345, 345, DPTR(0x2DD), 1);
        }
    }
    if (DU8(0x10) != 0 || DS32(0x18) != 0) {
        if (DU8(0x2A) == 0 || D_8800EF58 != 0) {
            func_800496A4(16, 1);
            func_80048E30(D_8800687C, 77, 90, (const char *)(D_880068B0 + 52), 1);
        }
        if (!(BU8(0x1E) & 1)) {
            func_800496A4(8, 1);
            func_80048E30(D_8800687C, DS16(0x346), 94, DPTR(0x31D), 1);
            func_80048E30(D_8800687C, DS16(0x348), 94, DPTR(0x325), 1);
            if (!(DU8(0x2A) & 1) || D_8800EF58 != 0) {
                func_888010B0();
            }
        }
    }
    if (DU8(0x10) != 0) {
        if (!(BU8(0x1E) & 1)) {
            func_800496A4(8, 1);
            func_880006BC(D_88005FA0);
            if (BU8(0) == 252) {
                func_80048E30(D_8800687C, 311, 127, func_8004C874(12, 9), 1);
                func_800495F8(281, 181, 0, "%s%s%s", str, func_8004C874(38, 7), str);
            } else {
                DU8(0x28) = func_8006397C(BU8(0));
                DU8(0x29) = func_800639C0(BU8(0));
                func_880006E0(func_88000510(&col2, (s8)DU8(0x28)));
                func_80048E30(D_8800687C, 311, 127, (const char *)func_80063270(DU8(0x28)), 1);
                if ((s8)DU8(0x28) != (s8)DU8(0x29)) {
                    func_880006E0(func_88000510(&col2, (s8)DU8(0x29)));
                    func_80048E30(D_8800687C, 311, 151, (const char *)func_80063270(DU8(0x29)), 1);
                }
                func_880006E0((struct Color88800DC0 *)D_88005FA0);
                func_800495F8(281, 181, 0, "%d%s%d", *(u16 *)(D_880068B0 + 38), func_8004C874(38, 7), *(u16 *)(D_880068B0 + 40));
            }
            func_800496A4(4, 1);
            func_80048E30(D_8800687C, 235, 131, func_8004C874(38, 4), 1);
            if (BU8(0) != 252 && (s8)DU8(0x28) != (s8)DU8(0x29)) {
                func_80048E30(D_8800687C, 235, 155, func_8004C874(38, 5), 1);
            }
            func_80048E30(D_8800687C, 235, 185, func_8004C874(38, 6), 1);
            {
            const char *s0str;
            if (BU8(0) == 252) {
                s0str = func_8004C874(14, 0);
            } else {
                s0str = func_800646C8(*(u16 *)(D_880068B0 + 38), BU8(0x24));
            }
            if (func_8006461C(BU8(0x20)) == 1) {
                s0str = func_8004C874(38, 20);
            }
            func_800495F8(235, 211, 0, "%s%s", func_8004C874(38, 8), s0str);
            }
            idx = 0;
            y = 130;
            do {
                func_80048E30(D_8800687C, 441, y, func_8004C874(38, idx + 9), 1);
                if (BU8(0) == 252) {
                    func_80049064(555, y, 2, str);
                } else {
                    switch (idx) {
                        case 0:
                            tmp = *(u16 *)(D_880068B0 + 42);
                            break;
                        case 1:
                            tmp = *(u16 *)(D_880068B0 + 44);
                            break;
                        case 2:
                            tmp = *(u16 *)(D_880068B0 + 48);
                            break;
                        case 3:
                            tmp = *(u16 *)(D_880068B0 + 50);
                            break;
                        case 4:
                            tmp = *(u16 *)(D_880068B0 + 46);
                            break;
                    }
                    func_800495F8(555, y, 2, "%d", tmp);
                }
                y += 20;
                idx++;
            } while (idx < 5);
        }
        func_80049064(319, 376, 1, DPTR(0x15D));
    }
    func_800496A4(8, 1);
    if (DU8(0x10) != 0 || DU8(0x11) != 0) {
        switch (DS32(0)) {
            case 0:
                if (!(BU8(0x1E) & 1)) {
                    func_80048E30(D_8800687C, 188, 413, func_8004C874(38, 27), 1);
                    func_80048E30(D_8800687C, 328, 413, func_8004C874(38, 28), 1);
                }
                break;
            case 1:
                func_80048E30(D_8800687C, 188, 413, func_8004C874(38, 27), 1);
                func_80048E30(D_8800687C, 328, 413, func_8004C874(38, 33), 1);
                break;
            case 2:
                if ((s8)DU8(0x26) == -1) {
                    func_80049064(320, 413, 1, func_8004C874(38, 29));
                } else if ((s8)DU8(0x27) == -1) {
                    func_80049064(320, 413, 1, func_8004C874(38, 30));
                }
                break;
            case 3:
            case 4:
                if (DS32(0x3B8) == 0 ||
                    (DS32(0) == 3 && D_88804054 != 0 && DU8(0x2A) == 0 && func_80063754(BU8(1)) != 0)) {
                    func_80048E30(D_8800687C, DS16(0x3BC), 413, DPTR(0x5D), 1);
                }
                break;
        }
    }
    func_880006BC(D_88005FA0);
    if (BU8(0x1E) & 1) {
        func_8004989C(27);
        func_80049064(201, 0x100, 1, func_8004C874(38, func_8006483C(D_880068B0) + 37));
    } else {
        idx = 0;
        do {
            if ((D_880068B0 + 2)[idx] == 0) {
                break;
            }
            if (func_88005CC0(2, &idx) == 0) {
                if ((D_880068B0 + 2)[idx] < 166 || D_8800EF58 != 0) {
                    func_88800DC0(idx, 0xFF);
                }
            }
            idx++;
        } while (idx < 4);
    }
    if (DU8(0x2A) != 0 && D_8800EF58 == 0) {
        func_88000308((u8 *)&col2, (s16)Envelope_Advance(D_88804050 + 44));
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0x509AA1, 0x3335FEFF);
        gDPSetPrimColor(D_800D0510++, 0, 0, col2.red, col2.green, col2.blue, 0xFF);
        if (BU8(0x1E) & 1) {
            func_880006E0((struct Color88800DC0 *)D_88005FA0);
            func_80048E30(D_8800687C, 465, 94, (const char *)func_8004B7A4(253), 1);
        } else {
            idx = 0;
            do {
                if ((D_880068B0 + 2)[idx] == 0) {
                    break;
                }
                if ((D_880068B0 + 2)[idx] >= 166) {
                    func_88800DC0(idx, 0xFF);
                }
                idx++;
            } while (idx < 4);
            if (DU8(0x2A) & 1) {
                func_880006E0((struct Color88800DC0 *)D_88005FA0);
                func_888010B0();
            }
        }
        func_880006E0((struct Color88800DC0 *)D_88005FA0);
        if (DS32(0) == 3 && DS32(0x3B8) != 0) {
            func_80048E30(D_8800687C, DS16(0x3BC), 413, DPTR(0x5D), 1);
        }
        func_800496A4(16, 1);
        func_80048E30(D_8800687C, 77, 90, (const char *)(D_880068B0 + 52), 1);
    }
    func_800499EC();
    gSPDisplayList(D_800D0510++, D_80094E00);
    if (DU8(0x10) != 0 || DU8(0x11) != 0) {
        switch (DS32(0)) {
            case 0:
                if (!(BU8(0x1E) & 1)) {
                    func_8004D19C(160, 411, D_8800ECDC, 0, 0x200000);
                    func_8004D19C(300, 411, D_8800ECF0, 0, 0x200000);
                }
                break;
            case 1:
                func_8004D19C(160, 411, D_8800ECDC, 0, 0x200000);
                func_8004D19C(300, 411, D_8800ECD8, 0, 0x200000);
                break;
        }
    }
    func_880015F4(77, 123, 138, 110, DS32(0xC), 0, 2, 0);
    if (!(BU8(0x1E) & 1)) {
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetAlphaCompare(D_800D0510++, G_AC_NONE);
        gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
        if (func_8006456C(*(u16 *)(D_880068B0 + 22)) != 0) {
            alpha = Envelope_Advance(D_88804050 + 56);
            gDPSetEnvColor(D_800D0510++, alpha, alpha, 0, 0xFF);
            func_8004D19C(80, 217, D_8800ECF4, 0, 0);
        }
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF);
        y = 254;
        idx = 0;
        do {
            s32 flag = 0;
            if (idx == (s8)DU8(0x26) && DU8(0x50) >= (DU8(0x51) >> 1)) {
                gDPPipeSync(D_800D0510++);
                gDPSetEnvColor(D_800D0510++, 0x80, 0x80, 0x80, 0xFF);
                flag = 1;
            }
            func_8004D19C(83, y, *(s32 *)D_88803EF0[idx], 0, 0);
            if (flag != 0) {
                gDPPipeSync(D_800D0510++);
                gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF);
            }
            y += 27;
            idx++;
        } while (idx < 4);
        ((s8 *)D_88804050)[40] = -1;
        idx = 0;
        do {
            if ((D_880068B0 + 2)[idx] == 0) {
                break;
            }
            if (func_88005CC0(2, &idx) == 0) {
                func_88800EC8(idx);
            }
            idx++;
        } while (idx < 4);
        func_88005F08();
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    switch (DS32(0)) {
        case 2:
            if (func_8800335C() == 0) {
                if ((s8)DU8(0x26) == -1 || (s8)DU8(0x27) == -1) {
                    if ((s8)DU8(0x26) != -1) {
                        func_8004B2CC(105, (s8)DU8(0x26) * 27 + 250, DU16(0x3B4) + 12, 32, 150, 150, 90, 0);
                    }
                    func_8004B314(105, DS16(0x24) * 27 + 250, DU16(0x3B4) + 12, 32);
                }
            }
            break;
        case 3:
        case 4:
            if (DS32(0x3B8) == 0) {
                func_8004B314(((s16 *)(D_88804050 + 958))[DS16(0x24)] - 6, 407,
                              ((u16 *)(D_88804050 + 962))[DS16(0x24)] + 12, 32);
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88802DCC.s")
#endif
