#include "global.h"


#ifdef VERSION_US
extern u8 D_8AF2C4F8[];
extern u32 D_8AF2C548;
void func_8AF035E0(void *arg0) {
    u32 count = D_8AF2C548;
    if (count < 0xA) {
        u8 *dest = D_8AF2C4F8 + count * 8;
        *(s32 *)dest = *(s32 *)((u8 *)arg0 + 0x4E4);
        *(s32 *)(dest + 4) = *(s32 *)((u8 *)arg0 + 0x4E8);
        D_8AF2C548 = count + 1;
    }
}

extern u8 D_8AF2C4F8[];
extern u32 D_8AF2C548;
void func_8AF03624(void *arg0) {
    if (--D_8AF2C548 < 0xA) {
        *(s32 *)((u8 *)arg0 + 0x4E4) = *(s32 *)(D_8AF2C4F8 + D_8AF2C548 * 8);
        *(s32 *)((u8 *)arg0 + 0x4E8) = *(s32 *)(D_8AF2C4F8 + D_8AF2C548 * 8 + 4);
        *(s32 *)((u8 *)arg0 + 0x4EC) = *(s32 *)((u8 *)arg0 + 0x4E8);
    }
}

void func_8AF03624(void *arg0);
f32 Math_AbsF32(f32);
extern s32 func_8AC06D8C(s32, s32);
void func_8AF03624(void *);
extern s32 D_8AF2BF78;

void func_8AF03678(void *arg0, s32 arg1)
{
  int new_var;
  s16 sp22;
  s16 temp_v1;
  func_8AF03624(arg0);
  temp_v1 = (sp22 = D_8AF2BF78 - (*((s16 *) (((u8 *) func_8AC06D8C(arg1, *((s32 *) (((u8 *) arg0) + 0x4B8)))) + 0xA))));
  if (((f32) (((s32) D_8AF2BF78) / 2)) < Math_AbsF32((f32) (temp_v1 - (*((s32 *) (((u8 *) arg0) + 0x4E8))))))
  {
    *((s32 *) (((u8 *) arg0) + 0x4E4)) = 0;
    *((s32 *) (((u8 *) arg0) + 0x4E8)) = (s32) temp_v1;
    new_var = 0;
    if (temp_v1 > new_var)
    {
      *((s32 *) (((u8 *) arg0) + 0x4E8)) = 0;
    }
    *((s32 *) (((u8 *) arg0) + 0x4EC)) = (s32) (*((s32 *) (((u8 *) arg0) + 0x4E8)));
  }
}

/* mkdraft:func_8AF03730 begin */
extern void func_8005053C(void *, void *);
extern void func_80050578(void *, s32);
extern u8 D_8AF2C550;
extern u8 D_8AF2653C;
extern s16 D_8AF26544;

s32 func_8AF03730(s32 arg0, u8 *arg1)
{
  unsigned int new_var2;
  u8 *new_var;
  new_var2 = 0x400;
  switch (arg0)
  {
    case 0:
      func_8005053C(arg1, &D_8AF2C550);
      new_var = &D_8AF2653C;
      func_80050578(arg1, (s32) new_var);
      break;
    case 1:
      break;
  }
  D_8AF26544 += new_var2;
  return 0;
}
/* mkdraft:func_8AF03730 end */

extern u16 D_8AF2C560;
extern u8 D_8AF2C278[];
extern f32 D_80088E50[];
extern f32 D_8AF28D4C;
void func_8AF03798(void) {
    s32 angle = D_8AF2C560;
    s32 increment;
    f32 result = D_80088E50[angle >> 4] * D_8AF28D4C + 1.0f;
    *(f32 *)(D_8AF2C278 + 0x40) = result;
    *(f32 *)(D_8AF2C278 + 0x44) = result;
    if (1) {
        increment = 0x2000;
    }
    D_8AF2C560 = angle + increment;
}

extern void func_8AC0619C(s32 *, u16);
extern void func_8AC06220(s32 *, u16);
extern u16 D_8AF2BDC6;
extern s16 D_8AF2C094;
extern u8 D_8AF2C098;
extern u8 D_8AF2C110;
extern u8 D_8AF2C188;
extern u8 D_8AF2C200;
void func_8AF037EC(void) {
    switch (D_8AF2C094) {                           /* irregular */
    case 0:
        func_8AC0619C(&D_8AF2C188, D_8AF2BDC6);
        func_8AC06220(&D_8AF2C200, D_8AF2BDC6);
        return;
    case 1:
        func_8AC0619C(&D_8AF2C098, D_8AF2BDC6);
        func_8AC06220(&D_8AF2C110, D_8AF2BDC6);
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF03878.s")

extern s16 D_8AF2C2F4[3];

s32 func_8AF03B38(void) {
    s32 i;
    s32 ret = 0;

    for (i = 0; i < 3; i++) {
        if (D_8AF2C2F4[i] == 1) {
            ret = 1;
        }
    }
    return ret;
}
extern s16 D_8AF2C2F4[3];
extern s16 D_8AF2C2FC[3];
extern void func_800238C4(void);

void func_8AF03B74(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        D_8AF2C2F4[i] = 0;
        D_8AF2C2FC[i] = 0x1E;
    }
    func_800238C4();
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF03BC4.s")

extern s32 D_8AF2C56C;
extern s32 D_8AF2C570;
s32 func_8AF03D34(s32 arg0, void *arg1) {
    void *inner = *(void **)((u8 *)arg1 + 0x20);
    switch (arg0) {
    case 0:
        D_8AF2C56C = *(s16 *)((u8 *)arg1 + 8);
        D_8AF2C570 = *(s16 *)((u8 *)arg1 + 0xA);
        *(s32 *)((u8 *)inner + 0x4E4) = 0;
        *(s32 *)((u8 *)inner + 0x4E8) = 0;
        *(s32 *)((u8 *)inner + 0x4EC) = 0;
        break;
    case 1:
        *(s16 *)((u8 *)arg1 + 8) = *(s32 *)((u8 *)inner + 0x4E4) + D_8AF2C56C;
        *(s16 *)((u8 *)arg1 + 0xA) = *(s32 *)((u8 *)inner + 0x4E8) + D_8AF2C570;
        break;
    }
    return 0;
}

extern void *D_8AF2BF44;

s32 func_8AF03DA8(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_8AF2BF44 != 0) {
            *(u16 *)((u8 *)arg1 + 0x30) = 0x37;
            *(u16 *)((u8 *)arg1 + 0x32) = *(s32 *)((u8 *)D_8AF2BF44 + 0x28);
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        }
    }
    return 0;
}

extern void *D_8AF2BF44;

s32 func_8AF03DF0(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_8AF2BF44 != 0) {
            *(u16 *)((u8 *)arg1 + 0x30) = 0x37;
            *(u16 *)((u8 *)arg1 + 0x32) = *(s32 *)((u8 *)D_8AF2BF44 + 0x2C);
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF03E38.s")

extern void func_8AC00738();

s32 func_8AF03F14(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 1)) {
        func_8AC00738();
    }
    return 0;
}

extern s32 D_8AF26470;
extern s32 D_8AF2BF78;
extern s32 func_8004C874(u16, u16);
extern s32 func_800472E0(s32);
s32 func_8AF03F4C(s32 arg0, void *arg1) {
    union { s32 i; s32 pad[5]; } width;
    s32 value;
    switch (arg0) {
    case 0:
        D_8AF26470 = 0x1E0;
        break;
    case 1:
        width.i = *(s8 *)((u8 *)arg1 + 0x26);
        value = func_800472E0(func_8004C874(*(u16 *)((u8 *)arg1 + 0x30), *(u16 *)((u8 *)arg1 + 0x32)));
        D_8AF26470 = *(s16 *)((u8 *)arg1 + 0xA) + value * width.i - D_8AF2BF78 - width.i;
        if (D_8AF26470 <= 0) {
            D_8AF26470 = 1;
        }
        break;
    }
    return 0;
}

/* mkdraft:func_8AF03FF8 begin */
extern void *D_8AF263C0;
extern s32 D_8AF26470;
extern s32 D_8AF26474;
extern s32 D_8AF2BF74;
extern s16 D_8AF2C08A;
extern s16 D_8AF2C094;
extern s32 D_8AF2C2F0;
extern s32 D_8AF2C324;
extern s32 D_8AF2C574;
extern s32 D_8AF2C578;
extern s32 func_80026098(); /* FAKE: void in src/229E0.c; s32 here so the caller's `bnez v0` test exists (score without the s32 typing: 1085) */
extern s32 func_8004C594(s32, s32);
extern s32 func_8AF03B38(void);
extern void func_8AF00130(s32);



s32 func_8AF03FF8(s32 arg0, void *arg1) {
    void *node;
    s16 delta;
    s16 extent;
    s32 position;
    s32 bound;
    s32 step;
    s32 limit;

    node = *(void **)((u8 *)arg1 + 0x20);
    switch (arg0) {
    case 0:
        D_8AF2C574 = *(s16 *)((u8 *)arg1 + 8);
        D_8AF2C578 = *(s16 *)((u8 *)arg1 + 0xA);
        *(s32 *)((u8 *)node + 0x4E4) = 0;
        *(s32 *)((u8 *)node + 0x4E8) = 0;
        *(s32 *)((u8 *)node + 0x4EC) = 0;
        break;
    case 1:
        if (D_8AF2BF74 == 0 && D_8AF2C094 == 1) {
            if (D_8AF2C2F0 != 0 && func_80026098() == 0 && D_8AF2C324 == 0 && (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x800) && func_8AF03B38() == 0) {
                delta = *(s16 *)((u8 *)*(void **)((u8 *)node + 0x4C8) + 0xE) + *(s32 *)((u8 *)node + 0x4E8);
                if (delta > 0) {
                    *(s32 *)((u8 *)node + 0x4EC) = 0;
                    if (D_8AF2C08A >= 2) {
                        func_8AF00130(0xC4);
                    }
                    D_8AF2C08A = 1;
                } else {
                    *(s32 *)((u8 *)node + 0x4EC) = delta;
                    func_8AF00130(0xC4);
                    D_8AF2BF74 = 1;
                    D_8AF2C08A -= 1;
                }
                func_8004C594(2, D_8AF2C08A);
            } else if (D_8AF2C2F0 != 0 && func_80026098() == 0 && D_8AF2C324 == 0 && (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x8400) && func_8AF03B38() == 0) {
                extent = *(s16 *)((u8 *)*(void **)((u8 *)node + 0x4C8) + 0xE);
                delta = *(s32 *)((u8 *)node + 0x4E8) - extent;
                if (delta != (-D_8AF26470 - extent)) {
                    *(s32 *)((u8 *)node + 0x4EC) = delta;
                    func_8AF00130(0xC4);
                    D_8AF2BF74 = 2;
                    D_8AF2C08A += 1;
                    func_8004C594(2, D_8AF2C08A);
                }
            } else {
                *(s32 *)((u8 *)node + 0x4F4) = 0;
                *(s32 *)((u8 *)node + 0x4F0) = 0;
            }
        }
        limit = *(s32 *)((u8 *)node + 0x4EC);
        if (limit > 0) {
            *(s32 *)((u8 *)node + 0x4EC) = 0;
            limit = 0;
        }
        bound = -D_8AF26470;
        if (limit < bound) {
            *(s32 *)((u8 *)node + 0x4EC) = bound;
            limit = bound;
        }
        position = *(s32 *)((u8 *)node + 0x4E8);
        step = limit - position;
        limit = 0; // FAKE: register-only dead store that ends the limit web (score without it: 85)
        if (step >= 0x14) {
            step = 0x13;
        }
        if (step < -0x13) {
            step = -0x13;
        }
        *(s32 *)((u8 *)node + 0x4E8) = position + step;
        if (step != 0) {
            *(s16 *)((u8 *)node + 0x4FC) = 1;
        } else {
            *(s16 *)((u8 *)node + 0x4FC) = 0;
            D_8AF2BF74 = 0;
        }
        position = *(s32 *)((u8 *)node + 0x4E8);
        if (position > 0) {
            *(s32 *)((u8 *)node + 0x4E8) = 0;
            position = 0;
        }
        bound = -D_8AF26470;
        if (position < bound) {
            *(s32 *)((u8 *)node + 0x4E8) = bound;
            position = bound;
        }
        D_8AF26474 = position;
        *(s16 *)((u8 *)arg1 + 8) = *(s32 *)((u8 *)node + 0x4E4) + D_8AF2C574;
        *(s16 *)((u8 *)arg1 + 0xA) = *(s32 *)((u8 *)node + 0x4E8) + D_8AF2C578;
        break;
    }
    return 0;
}
/* mkdraft:func_8AF03FF8 end */

extern s32 D_8AF26474;
extern s16 D_8AF2C088;
extern s32 D_8AF2C57C;
s32 func_8AF04340(s32 arg0, void *arg1) {
    s32 result;

    result = *(s32 *)((u8 *)arg1 + 0x20);
    switch (arg0) {
        case 0:
            D_8AF2C57C = *(s16 *)((u8 *)arg1 + 0xA);
            break;
        case 1:
            if (D_8AF26470 == 0) {
                return 0;
            }
            D_8AF26474 = *(s32 *)((u8 *)result + 0x4E8);
            *(s16 *)((u8 *)arg1 + 0xA) = D_8AF2C57C - (D_8AF2C088 - 30) * D_8AF26474 / (D_8AF26470 - 40);
            *(s32 *)((u8 *)arg1 + 0x2C) = -1;
            break;
    }
    return 0;
}

extern s32 D_8AF2C580;
s32 func_8AF04404(s32 arg0, void *arg1) {
    void *inner = *(void **)((u8 *)arg1 + 0x20);

    switch (arg0) {
        case 0:
            D_8AF2C580 = *(s16 *)((u8 *)arg1 + 0xA);
            break;
        case 1:
            if (D_8AF26470 == 0) {
                return 0;
            }
            D_8AF26474 = *(s32 *)((u8 *)inner + 0x4E8);
            *(s16 *)((u8 *)arg1 + 0xA) = D_8AF2C580 - (D_8AF2C088 - 30) * D_8AF26474 / D_8AF26470;
            *(s32 *)((u8 *)arg1 + 0x2C) = -1;
            break;
    }
    return 0;
}

s32 func_8AF044C4(s32 arg0, void *arg1) {
    void *inner = *(void **)((u8 *)arg1 + 0x20);
    if (arg0 != 0 && arg0 == 1) {
        if (*(s32 *)((u8 *)arg1 + 4) == *(s32 *)((u8 *)inner + 0x4B8)) {
            *(s32 *)((u8 *)arg1 + 0x28) = 0xFFFF00FF;
            *(s32 *)((u8 *)arg1 + 0x2C) = 0xFFFF00FF;
        } else {
            *(s32 *)((u8 *)arg1 + 0x28) = -1;
            *(s32 *)((u8 *)arg1 + 0x2C) = -1;
        }
    }
    return 0;
}

void func_8AF04514(void *arg0) {
    (*(s16 *)((u8 *)(arg0) + (0x24))) = 0xB5;
    (*(s16 *)((u8 *)(arg0) + (0x26))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = -1;
}

void func_8AF04530(void *arg0) {
    (*(s16 *)((u8 *)(arg0) + (0x24))) = 0xB5;
    (*(s16 *)((u8 *)(arg0) + (0x26))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = 0xDC0000FF;
}

void func_8AF0454C(u8 *arg0) {
    *(s16 *)(arg0 + 0x24) = 0xB6;
    *(s16 *)(arg0 + 0x26) = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF0455C.s")

extern s32 D_8AF2C584;
extern s32 D_8AF2C588;
extern s32 D_8AF2C58C;
extern s16 D_8AF2BA6C;
extern u8 D_8AF28A90[];
extern u8 D_8AF28A94[];
extern u8 D_8AF28A98[];
extern void func_800504BC(void *);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, void *, s32);
extern void func_800499EC(void);
extern s32 func_8004C874(u16, u16);
void func_8AF04894(s32 arg0, u8 *arg1) {
    s16 pos[5];
    switch (arg0) {
    case 0:
        *(u16 *)(arg1 + 2) &= ~2;
        D_8AF2C584 = func_8004C874(0x37, 0x1EE);
        D_8AF2C588 = func_8004C874(0x37, 0x1EF);
        D_8AF2C58C = func_8004C874(0x37, 0x1F0);
        break;
    case 1:
        func_800504BC(pos);
        pos[3] = *(s16 *)(arg1 + 8) + pos[0];
        pos[2] = *(s16 *)(arg1 + 0xA) + pos[1];
        func_800498C4();
        func_800496A4(8, 0);
        func_8004972C(0xFF, 0xFF, 5, 0xFF);
        switch (D_8AF2BA6C) {
        case 3:
            func_800495F8(pos[3], pos[2], 1, D_8AF28A90, D_8AF2C584);
        break;
        case 4:
            func_800495F8(pos[3], pos[2], 1, D_8AF28A94, D_8AF2C588);
        break;
        case 5:
            func_800495F8(pos[3], pos[2], 1, D_8AF28A98, D_8AF2C58C);
        break;
        }
        func_800499EC();
        break;
    }
}

typedef struct { s32 unk_0; } unk_D_8AF2BFB4;
extern unk_D_8AF2BFB4 D_8AF2BFB4;
extern unk_D_8AF2BFB4 D_8AF2BFB8;
s32 func_8AF04A14(s32 arg0, u8 *arg1) {
    switch (arg0) {
        case 0:
            *(unk_D_8AF2BFB4 *)(arg1 + 0x3C) = D_8AF2BFB4;
            *(unk_D_8AF2BFB4 *)(arg1 + 0x40) = D_8AF2BFB8;
            break;
        case 1: // karodo: empty arm; without it the switch compiles as an if
            break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF04A54.s")

extern void func_8AF0455C();
extern void func_8004E308(s32, void *, s32);
extern s32 func_8AC06D8C(s32, s32);
void func_8AF04C50(void *arg0, s32 arg1, u8 *arg2) {
    void *callback = func_8AF0455C;
    *(s32 *)((u8 *)arg0 + 0x4E8) = *(s32 *)(arg2 + 0x14);
    *(u8 **)((u8 *)arg0 + 0x528) = arg2;
    while (1) {
        s32 value = *(s32 *)(arg2 + 0x14);
        s32 found;
        if (value == 0) {
            break;
        }
        found = func_8AC06D8C(arg1, value);
        if (found != 0) {
            func_8004E308(found, callback, (s32)arg2);
        }
        arg2 += 0x34;
    }
}

extern void func_8004E308(s32, void *, s32);
extern s32 func_8AC06D8C(s32, s32);
extern s32 func_8AF044C4(s32 arg0, void *arg1);
void func_8AF04CC8(void *arg0, s32 arg1, u8 *arg2) {
    void *callback = func_8AF044C4;
    u8 *offset;
    struct Pair {s32 x; s32 y;}; *(struct Pair *)((u8 *)arg0 + 0x4E0) = *(struct Pair *)(arg2 + 4); *(u8 **)((u8 *)arg0 + 0x528) = arg2;
    while (1) {
        s32 value = *(s32 *)(arg2 + 4);
        s32 found;
        if (value == 0) break;
        offset = (u8 *)arg0 + 0x28;
        found = func_8AC06D8C(arg1, value);
        *(s32 *)(*(u8 **)(offset + 0x500) + 0x30) = found;
        if (found != 0) func_8004E308(found, callback, (s32)offset);
        arg2 += 0x34;
    }
}

extern u8 D_8AF264A0[];
extern u8 D_8AF264D4[];
extern u8 D_8AF264F8[];
u8 *func_8AF04D68(void) {
    u8 *result;

    switch (D_8AF2BA6C) {
    case 3:
        result = D_8AF264A0;
        break;
    case 4:
        result = D_8AF264D4;
        break;
    case 5:
        result = D_8AF264F8;
        break;
    default:
        result = NULL;
        break;
    }
    return result;
}

// Returns the index of id in the -1-terminated s16 list chosen by func_8AF04D68,
// or -1 if id is absent or no list exists for D_8AF2BA6C.
s32 func_8AF04DB8(s32 id) {
    s32 index;
    s16 *entry;
    s32 result = -1;

    entry = (s16 *)func_8AF04D68();
    if (entry == NULL) {
        return -1;
    }

    for (index = 0;; index++) {
        if (*entry == -1) {
            break;
        }
        if (id == *entry) {
            result = index;
            break;
        }
        entry++;
    }
    return result;
}

extern s32 func_8AF04DB8(s32);
s32 *func_8AF04E2C(arg0, arg1)
void *arg0;
s32 arg1;
{
    s32 index;

    index = func_8AF04DB8(arg1);
    if (index == -1) {
        return NULL;
    }
    if (index >= 100) {
        return NULL;
    }
    return (s32 *)((u8 *)arg0 + index * 0xC + 0x28);
}

extern s32 func_8AC06D8C(s32, s32);
extern void func_8AC03C28(void);
extern void func_8004E308(s32, void *, s32);
void func_8AF04E8C(s32 arg0) {
    s32 result;
    s32 i;
    void *callback = func_8AC03C28;
    func_8AC06D8C(arg0, 0x706C7463);
    result = func_8AC06D8C(arg0, 0x69636E63);
    for (i = 0; i < 6; i++) {
        s32 value = func_8AC06D8C(arg0, 0x69636E30 + i);
        if (value) {
            func_8004E308(value, callback, result);
        }
    }
}

/* mkdraft:func_8AF04F38 begin */
extern s32 func_8AC06D8C(s32, s32);
extern void func_8004E308(s32, void *, s32);
extern void func_8AC04604(void);

void func_8AF04F38(s32 arg0) {
    s32 value;
    s32 handles[6];
    s32 i;
    void *callback = func_8AC04604;

    handles[0] = func_8AC06D8C(arg0, 0x74636131);
    handles[1] = func_8AC06D8C(arg0, 0x74636132);
    handles[2] = func_8AC06D8C(arg0, 0x74636133);
    handles[3] = func_8AC06D8C(arg0, 0x74636134);
    handles[4] = func_8AC06D8C(arg0, 0x74636135);
    handles[5] = func_8AC06D8C(arg0, 0x74636136);
    for (i = 0; i < 6; i++) {
        value = handles[i];
        if (value != 0) {
            func_8004E308(value, callback, i);
        }
    }
}
/* mkdraft:func_8AF04F38 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF0501C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF05C10.s")

void *func_8AF05DC8(void *arg0) {
    u8 *node;
    s32 key;
    s32 entry_key;
    void *result;

    node = *(u8 **)((u8 *)arg0 + 0x500);
    key = *(s32 *)((u8 *)arg0 + 0x4B8);
    result = NULL;
    if (node == NULL) {
        return NULL;
    }
loop:
    entry_key = *(s32 *)(node + 4);
    if (entry_key != 0) {
        if (entry_key == key) {
            result = node;
        } else {
            node += 0x34;
            goto loop;
        }
    }
    return result;
}

extern u8 D_8AF27E30[];
extern u8 D_8AF28274[];
extern u8 D_8AF284E4[];
s32 func_8AF05E14(void *arg0, s32 arg1) {
    s32 result;
    u8 *node;
    s32 state;
    s32 entry;

    result = -1;
    state = *(s32 *)((u8 *)arg0 + 0x4DC);
    switch (state) {
    default:
        break;
    case 0x59:
        node = D_8AF27E30;
        break;
    case 0x42:
        node = D_8AF28274;
        break;
    case 0x4D:
        node = D_8AF284E4;
        break;
    }
    while (1) {
        entry = *(s32 *)(node + 4);
        if (entry == 0) {
            break;
        }
        if (arg1 == entry) {
            result = *(s32 *)(node + 0x20);
            break;
        }
        node += 0x34;
    }
    return result;
}

s32 func_8AF05E94(void *arg0) {
    u8 *node;
    s32 key;
    s32 entry_key;
    s32 result;

    node = *(u8 **)((u8 *)arg0 + 0x500);
    key = *(s32 *)((u8 *)arg0 + 0x4B8);
    result = -1;
    if (node == NULL) {
        return -1;
    }
loop:
    entry_key = *(s32 *)(node + 4);
    if (entry_key != 0) {
        if (entry_key == key) {
            result = *(s32 *)(node + 0x20);
        } else {
            node += 0x34;
            goto loop;
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF05EE0.s")

s32 func_8AF06404(void *arg0) {
    u8 *node;
    s32 key;
    s32 entry_key;
    s32 result;

    node = *(u8 **)((u8 *)arg0 + 0x500);
    key = *(s32 *)((u8 *)arg0 + 0x4B8);
    result = -1;
    if (node == NULL) {
        return -1;
    }
loop:
    entry_key = *(s32 *)(node + 4);
    if (entry_key != 0) {
        if (entry_key == key) {
            result = *(s32 *)(node + 0x24);
        } else {
            node += 0x34;
            goto loop;
        }
    }
    return result;
}

extern s16 D_8AF2C322;
extern s32 D_8AF2C2F0;
extern s32 D_8AF2BF40;
extern u8 *D_8AF2BF60;
extern void func_8AF03B74(void);
extern void func_8AF03678(void *, s32);
extern void func_80021ED8(s32);
extern void func_8AC01064(s32);
extern s32 func_8AC06D8C(s32, s32);
extern s32 * func_8AF04E2C();
extern void func_8AF07110(void);
extern s16 D_8AF2C094;
void func_8AF06450(void *arg0, s32 arg1) {
    u8 *sub = (u8 *)arg0 + 0x28;
    u8 *old;
    u8 *current;
    s32 *entry;
    D_8AF2C322 = 0;
    func_8AF03B74();
    D_8AF2C094 = 0;
    D_8AF2C2F0 = 0;
    old = (u8 *)*func_8AF04E2C(arg0, *(s32 *)(sub + 0x4B4));
    current = (u8 *)*func_8AF04E2C(arg0, arg1);
    *(s32 *)(sub + 0x4B4) = arg1;
    func_8AF03678(sub, (s32)current);
    func_8AF07110();
    if (D_8AF2BF40 != 0) {
        func_8AC01064(0x5273635A);
        D_8AF2BF40 = 0;
    }
    *(u16 *)(current + 2) |= 1;
    *(u16 *)(current + 2) |= 2;
    *(u16 *)(old + 2) &= ~1;
    *(u16 *)(old + 2) &= ~2;
    old = (u8 *)*func_8AF04E2C(arg0, 0x30);
    *(u16 *)(old + 2) &= ~1;
    *(u16 *)(old + 2) &= ~2;
    current = (u8 *)*func_8AF04E2C(arg0, 0x31);
    *(u16 *)(current + 2) |= 1;
    *(u16 *)(current + 2) |= 2;
    *(u16 *)(D_8AF2BF60 + 2) |= 1;
    entry = func_8AF04E2C(arg0, 0x58);
    current = (u8 *)*entry;
    *(u16 *)(current + 2) |= 1;
    *(u16 *)(current + 2) |= 2;
    current = (u8 *)func_8AC06D8C(*entry, 0x6A6F6261);
    *(u16 *)(current + 2) |= 1;
    *(u16 *)(current + 2) |= 2;
    func_80021ED8(7);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF065DC.s")

extern void func_800503A4(s32);
s32 *func_8AF04E2C();

void func_8AF06E74(void) {
    s32 *temp_v0;

#ifdef CC_CHECK
    temp_v0 = func_8AF04E2C((void *)0, 0);
#else
    temp_v0 = func_8AF04E2C();
#endif
    if (temp_v0 != NULL) {
        func_800503A4(*temp_v0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F1850/func_8AF06EA4.s")

s32 main_pool_alloc(s32, s32);
extern void func_80025F84(s32);
extern void func_8AC00FFC(s32);
extern s32 D_8AF2646C;
extern s32 D_8AF2C020;

void func_8AF070B4(void) {
    if (D_8AF2646C == 0) {
        func_8AC00FFC(0x47425345);
        D_8AF2646C = 1;
        D_8AF2C020 = main_pool_alloc(0x8400, 0);
    }
    func_80025F84(D_8AF2C020);
}

extern void func_8002602C();
extern void func_8AC01064(s32);
void func_8AF07110(void) {
    func_8002602C();
    if (D_8AF2646C != 0) {
        D_8AF2646C = 0;
        func_8AC01064(0x47425345);
    }
}
#endif
