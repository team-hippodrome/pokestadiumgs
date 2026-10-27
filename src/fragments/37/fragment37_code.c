#include "global.h"
#include "controller.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88800020.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_888003EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88800714.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88800B24.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88800DC0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/37/fragment37_code/func_88800EC8.s")

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
