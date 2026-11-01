#include "global.h"


#ifdef VERSION_US
void func_8AF07CB0(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x28) = arg1;
    *(s32 *)(arg0 + 0x2C) = arg2;
}

extern s16 D_8AF2C960;
extern u8 *D_8AF2C9C8;

extern u8 *D_8AF2C980;
extern u8 *D_8AF2C984;
extern u8 *D_8AF2C988;
extern u8 *D_8AF2C98C;
extern u8 *D_8AF2C990;
extern u8 *D_8AF2C994;
extern void func_8AF07CB0(u8 *arg0, s32 arg1, s32 arg2);
void func_8AF07CBC(void) {
    func_8AF07CB0(D_8AF2C980, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF07CB0(D_8AF2C984, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF07CB0(D_8AF2C988, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF07CB0(D_8AF2C98C, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF07CB0(D_8AF2C990, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF07CB0(D_8AF2C994, 0xC3A05AFF, 0xE1C38CFF);
    switch (D_8AF2C960) {
    case 1:
        *(s16 *)(D_8AF2C9C8 + 0x32) = 7;
        func_8AF07CB0(D_8AF2C980, 0xFFFF00FF, 0xFFFF00FF);
        break;
    case 2:
        *(s16 *)(D_8AF2C9C8 + 0x32) = 8;
        func_8AF07CB0(D_8AF2C988, 0xFFFF00FF, 0xFFFF00FF);
        break;
    case 3:
        *(s16 *)(D_8AF2C9C8 + 0x32) = 9;
        func_8AF07CB0(D_8AF2C994, 0xFFFF00FF, 0xFFFF00FF);
        break;
    case 0:
        *(s16 *)(D_8AF2C9C8 + 0x32) = 10;
        func_8AF07CB0(D_8AF2C984, 0xFFFF00FF, 0xFFFF00FF);
        break;
    case 4:
        *(s16 *)(D_8AF2C9C8 + 0x32) = 11;
        func_8AF07CB0(D_8AF2C98C, 0xFFFF00FF, 0xFFFF00FF);
        break;
    case 5:
        *(s16 *)(D_8AF2C9C8 + 0x32) = 12;
        func_8AF07CB0(D_8AF2C990, 0xFFFF00FF, 0xFFFF00FF);
        break;
    }
}

extern s16 D_8AF2C960;
extern u8 *D_8AF2C964;
extern u8 *D_8AF2C968;
extern u8 *D_8AF2C96C;
extern u8 *D_8AF2C970;
extern u8 *D_8AF2C974;
extern u8 *D_8AF2C978;
void func_8AF07EBC(void) {
    *(u16 *)(D_8AF2C964 + 2) &= ~1;
    *(u16 *)(D_8AF2C968 + 2) &= ~1;
    *(u16 *)(D_8AF2C96C + 2) &= ~1;
    *(u16 *)(D_8AF2C970 + 2) &= ~1;
    *(u16 *)(D_8AF2C974 + 2) &= ~1;
    *(u16 *)(D_8AF2C978 + 2) &= ~1;
    switch (D_8AF2C960) {
    case 0:
        *(u16 *)(D_8AF2C964 + 2) |= 1;
        break;
    case 1:
        *(u16 *)(D_8AF2C968 + 2) |= 1;
        break;
    case 2:
        *(u16 *)(D_8AF2C96C + 2) |= 1;
        break;
    case 3:
        *(u16 *)(D_8AF2C970 + 2) |= 1;
        break;
    case 4:
        *(u16 *)(D_8AF2C974 + 2) |= 1;
        break;
    case 5:
        *(u16 *)(D_8AF2C978 + 2) |= 1;
        break;
    }
}

extern s16 D_8AF2C960;
void func_8AF07FF0(void) {
    D_8AF2C960 = 1;
}

/* mkdraft:func_8AF08000 begin */
extern s16 D_8AF2BDDC;
extern s32 D_8AF2C690;
extern s32 D_8AF2C708;
extern s32 D_8AF2C780;
extern s32 D_8AF2C7F8;
extern s32 D_8AF2C870;
extern s32 D_8AF2C8E8;
extern s32 D_8AF2C998;
extern u8 *D_8AF2C97C;
extern u8 *D_8AF2C964;
extern u8 *D_8AF2C968;
extern u8 *D_8AF2C96C;
extern u8 *D_8AF2C970;
extern u8 *D_8AF2C974;
extern u8 *D_8AF2C978;
extern u8 *D_8AF2C980;
extern u8 *D_8AF2C984;
extern u8 *D_8AF2C988;
extern u8 *D_8AF2C98C;
extern u8 *D_8AF2C990;
extern u8 *D_8AF2C994;
extern u8 *D_8AF2C9C4;
extern u8 *D_8AF2C9C8;
extern s16 D_8AF2C9CC;
extern s32 D_8AF2C9D0;
extern s32 func_8AC00270;
extern s32 func_8AF013D8(s32, void *);

s32 func_8AF00504(s32 arg0);
s32 func_8AF003A8(s32 arg0);
u8 *func_8AC06D8C(s32 arg0, s32 arg1);
s32 func_8004E308(s32 arg0, s32 *arg1, s32 arg2);
s32 func_8AC04744(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8AC05E40(s32 arg0, s32 arg1, s32 *arg2);
s32 func_8AC02C80(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
void func_8AF07EBC(void);



void func_8AF08000(void) {
    s32 page;

    func_8AF00504(0x20);
    func_8AF00504(0x4C);
    func_8AF00504(0x35);
    page = func_8AF003A8(0x4C);
    D_8AF2C9C8 = func_8AC06D8C(page, 0x736C6966);
    *(s16 *)(D_8AF2C9C8 + 0x30) = 0x3B;
    *(s16 *)(D_8AF2C9C8 + 0x32) = 7;
    func_8AC04744(&D_8AF2C9D0, page, 0x73686133, 0x736C6966);
    func_8004E308((s32)func_8AC06D8C(page, 0x6579655F), &func_8AC00270, 0);
    page = func_8AF003A8(0x20);
    D_8AF2C964 = func_8AC06D8C(page, 0x74655F31);
    D_8AF2C968 = func_8AC06D8C(page, 0x74655F32);
    D_8AF2C96C = func_8AC06D8C(page, 0x74655F33);
    D_8AF2C970 = func_8AC06D8C(page, 0x74655F34);
    D_8AF2C974 = func_8AC06D8C(page, 0x74655F35);
    D_8AF2C978 = func_8AC06D8C(page, 0x74655F36);
    func_8004E308((s32)D_8AF2C964, (s32 *)&func_8AF013D8, NULL);
    func_8004E308((s32)D_8AF2C968, (s32 *)&func_8AF013D8, NULL);
    func_8004E308((s32)D_8AF2C96C, (s32 *)&func_8AF013D8, NULL);
    func_8004E308((s32)D_8AF2C970, (s32 *)&func_8AF013D8, NULL);
    func_8004E308((s32)D_8AF2C974, (s32 *)&func_8AF013D8, NULL);
    func_8004E308((s32)D_8AF2C978, (s32 *)&func_8AF013D8, NULL);
    D_8AF2C980 = func_8AC06D8C(page, 0x706F5F66);
    D_8AF2C984 = func_8AC06D8C(page, 0x69745F66);
    D_8AF2C988 = func_8AC06D8C(page, 0x77615F66);
    D_8AF2C98C = func_8AC06D8C(page, 0x74615F66);
    D_8AF2C990 = func_8AC06D8C(page, 0x736F5F66);
    D_8AF2C994 = func_8AC06D8C(page, 0x61695F66);
    D_8AF2C97C = func_8AC06D8C(page, 0x626F6F6B);
    func_8AC05E40(page, 0x6974656D, &D_8AF2C690);
    func_8AC05E40(page, 0x706F6B65, &D_8AF2C708);
    func_8AC05E40(page, 0x77617A61, &D_8AF2C780);
    func_8AC05E40(page, 0x61697368, &D_8AF2C7F8);
    func_8AC05E40(page, 0x74616D61, &D_8AF2C870);
    func_8AC05E40(page, 0x736F7361, &D_8AF2C8E8);
    page = func_8AF003A8(0x35);
    func_8AC02C80(page, 0x74697431, 0x74697432, &D_8AF2C998);
    D_8AF2C9C4 = func_8AC06D8C(page, 0x7469746C);
    *(s16 *)(D_8AF2C9C4 + 0x30) = 0x36;
    *(s16 *)(D_8AF2C9C4 + 0x32) = 0x10;
    func_8AF07EBC();
    *(u16 *)(D_8AF2C97C + 2) &= ~(1 << 1);
    D_8AF2C9CC = 0;
    D_8AF2BDDC = 1;
}
/* mkdraft:func_8AF08000 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F5F20/func_8AF08390.s")

s32 func_8AF00130(s32);
s32 func_8AF180F4();
extern void *D_8AF263C0;

s16 func_8AF084BC(s16 arg0)
{
  u16 temp_v0;
  u16 new_var;
  temp_v0 = *((u16 *) (((u8 *) D_8AF263C0) + 8));
  if (temp_v0 & 0x100)
  {
    D_8AF2C960 = 3;
    D_8AF2C960 = 1;
  }
  else
  {
    new_var = temp_v0;
    if (new_var & 0x400)
    {
      D_8AF2C960 = 3;
    }
    else
      if (new_var & 0x8000)
    {
      func_8AF00130(0xBF);
      arg0 = 0x13;
      func_8AF180F4();
    }
  }
  return arg0;
}
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

s32 func_8AF00130(s32);                     /* extern */
M2C_UNK func_8AF08C90();                            /* extern */
extern void *D_8AF263C0;

s16 func_8AF08538(s16 arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(D_8AF263C0, u16 *, 8);
    if (temp_v0 & 0x400) {
        D_8AF2C960 = 5;
    } else if (temp_v0 & 0x200) {
        D_8AF2C960 = 0;
    } else if (temp_v0 & 0x100) {
        D_8AF2C960 = 2;
    } else if (temp_v0 & 0x8000) {
        func_8AF00130(0xBF);
        arg0 = 8;
        func_8AF08C90();
    }
    return arg0;
}
s32 func_8AF10CD4();

s16 func_8AF085C8(s16 arg0)
{
  u16 temp_v0;
  temp_v0 = *((u16 *) (((u8 *) D_8AF263C0) + 8));
 if (0) { }
  if (temp_v0 & 0x200)
  {
    D_8AF2C960 = 1;
  }
  else
    if (temp_v0 & 0x400)
  {
    D_8AF2C960 = 4;
  }
  else
    if (temp_v0 & 0x8000)
  {
    func_8AF00130(0xBF);
    arg0 = 0xD;
    func_8AF10CD4();
  }
  return arg0;
}
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

s32 func_8AF00130(s32);
void func_8AF15EF0(void);
extern void *D_8AF263C0;

s32 func_8AF08644(s16 arg0) {
    if (M2C_FIELD(D_8AF263C0, u16 *, 8) & 0x800) {
        D_8AF2C960 = 0;
    } else if (M2C_FIELD(D_8AF263C0, u16 *, 8) & 0x100) {
        D_8AF2C960 = 5;
    } else if (M2C_FIELD(D_8AF263C0, u16 *, 8) & 0x8000) {
        func_8AF00130(0xBF);
        func_8AF15EF0();
        arg0 = 0x10;
    }
    return arg0;
}
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

s32 func_8AF00130(s32);                     /* extern */
M2C_UNK func_8AF1B5D4();                            /* extern */
extern void *D_8AF263C0;

s16 func_8AF086C4(s16 arg0) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(D_8AF263C0, u16 *, 8);
    if (temp_v0 & 0x800) {
        D_8AF2C960 = 1;
    } else if (temp_v0 & 0x200) {
        D_8AF2C960 = 3;
    } else if (temp_v0 & 0x100) {
        D_8AF2C960 = 4;
    } else if (temp_v0 & 0x8000) {
        func_8AF00130(0xBF);
        arg0 = 0x15;
        func_8AF1B5D4();
    }
    return arg0;
}
s32 func_8AF1C804();

s16 func_8AF08758(s16 arg0)
{
  unsigned int temp_v0;
  temp_v0 = *((u16 *) (((u8 *) D_8AF263C0) + 8));
  if (temp_v0 & 0x800)
  {
    D_8AF2C960 = 2;
  }
  else
    if (temp_v0 & 0x200)
  {
    D_8AF2C960 = 5;
  }
  else
    if (temp_v0 & 0x8000)
  {
    func_8AF00130(0xBF);
    arg0 = 0x17;
    func_8AF1C804();
  }
  return arg0;
}
/* mkdraft:func_8AF087D4 begin */
extern s16 D_8AF2C9CC;
void func_8AF08390(void);
void func_8AC007FC(void);



s16 func_8AF087D4(void) {
    s16 ret;
    s16 d1; // FAKE: d1..d5 are unused pads that walk the frame to 0x28 and put ret at 0x26(sp), state at 0x1a(sp); diff score 62 without them.
    s16 d2; // FAKE: see d1.
    s16 d3; // FAKE: see d1.
    s16 d4; // FAKE: see d1.
    s16 d5; // FAKE: see d1.
    s16 state;

    ret = 7;
    if (D_8AF2C9CC < 4) {
        D_8AF2C9CC++;
    } else {
        func_8AC007FC();
    }
    if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
        func_8AF00130(3);
        ret = 1;
    } else {
        state = D_8AF2C960;
        switch (D_8AF2C960) {
        case 0:
            ret = func_8AF084BC(7); break;
        case 1:
            ret = func_8AF08538(7); break;
        case 2:
            ret = func_8AF085C8(7); break;
        case 3:
            ret = func_8AF08644(7); break;
        case 5:
            ret = func_8AF086C4(7); break;
        case 4:
            ret = func_8AF08758(7); break;
        }
        if (state != D_8AF2C960) {
            func_8AF00130(1);
        }
    }
    func_8AF07EBC();
    func_8AF08390();
    func_8AF07CBC();
    return ret;
}
/* mkdraft:func_8AF087D4 end */

extern void func_800498C4(void);
extern void func_800499EC(void);
void func_8AF0894C(void) {
    func_800498C4();
    func_800499EC();
}
#endif
