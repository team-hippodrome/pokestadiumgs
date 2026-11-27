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

extern void func_800231A0(s32, u32, s32, s32);
extern void func_800238C4(void);
extern void func_80026068(u32);
extern s32 func_80026098();
extern s32 func_800504BC(s16 *);
extern void func_8AF070B4(void);
extern void func_8AF07110(void);
extern u16 *D_8AF2BABC;
extern s32 D_8AF2BF74;
extern s32 D_8AF2BF78;
extern s32 D_8AF2BF7C;
extern s32 D_8AF2C090;
extern s16 D_8AF2C2F4[3];
extern s16 D_8AF2C2FC[3];
extern s32 D_8AF2C324;
extern u16 D_8AF2C560;
extern s32 D_8AF2C564;
extern s32 D_8AF2C568;
struct UnkEntry8 {
    u16 id;
    u16 v[3];
};



s32 func_8AF03878(s32 arg0, void *arg1) {
    s16 pad0;
    s16 angle;
    s16 idx;
    u16 val;
    s32 off;
    s16 ages[2];
    s16 *p;
    struct UnkEntry8 *entry;

    idx = (s16)(*(s16 *)((u8 *)arg1 + 0x22) % 3);
    switch (arg0) {
    case 0:
        D_8AF2C2F4[idx] = 0;
        D_8AF2C2FC[idx] = 0x1E;
        D_8AF2C564 = 0;
        D_8AF2C324 = 0;
        D_8AF2C568 = 0;
        break;
    case 1:
        func_800504BC(ages);
        angle = *(s16 *)((u8 *)arg1 + 0xA) + ages[1];
        if (D_8AF2C568 == *(s32 *)((u8 *)arg1 + 4) && D_8AF2C324 != 0 && func_80026098() == 0) {
            D_8AF2C324 = 0;
            func_8AF07110();
            func_800238C4();
        }
        off = idx * 2;
        p = &D_8AF2C2F4[idx];
        if (*p == 0 && D_8AF2BF74 == 0 && D_8AF2BF7C < angle &&
            angle < D_8AF2BF7C + D_8AF2BF78) {
            entry = (struct UnkEntry8 *)D_8AF2BABC;
        loopK:
            if (D_8AF2C090 == entry->id) {
entry = (struct UnkEntry8 *)((u8 *)entry + off + 2);
                val = *(u16 *)entry;
            } else {
                entry++;
                goto loopK;
            }
            switch ((u8)((val & 0x100) >> 8)) {
            case 0:
                D_8AF2C564 = 1;
                // FAKE: `& 0xFFFF` is a no-op on a u16, but it splits val into a second
                // web, which is what makes uopt colour the loaded value a0 and the switch
                // selector v1 (retail).  Without the mask the whole dispatch/tail colouring
                // flips and the asm-differ score is 300 instead of 0.
                *(u8 *)((u8 *)&D_8AF2C560 + 2) = val & 0xFFFF;
                D_8AF2C568 = *(s32 *)((u8 *)arg1 + 4);
                func_8AF070B4();
                break;
            case 1:
                func_800231A0((u8)(val & 0xFF), 1, 0, off);
                break;
            }
            *p = 1;
        }
        if (*p == 1) {
            if (D_8AF2C2FC[idx] > 0) {
                if (D_8AF2C568 == *(s32 *)((u8 *)arg1 + 4) && D_8AF2C564 != 0 && D_8AF2C2FC[idx] < 0x1A) {
                    D_8AF2C564 = 0;
                    D_8AF2C324 = 1;
                    func_80026068(*(u8 *)((u8 *)&D_8AF2C560 + 2));
                }
                D_8AF2C2FC[idx] = D_8AF2C2FC[idx] - 1;
                if (D_8AF2C2FC[idx] == 0) {
                    func_800238C4();
                    *p = 2;
                }
            }
        }
        break;
    }
    return 0;
}

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
/* mkdraft:func_8AF03BC4 begin */
extern s32 D_8AF2BF74;
extern s32 D_8AF2BF78;
extern s32 D_8AF2BF7C;
extern s16 D_8AF2C308;
extern void func_800226C0(s32);
extern s32 func_800504BC(s16 *);

// Per-object UI sound trigger. obj+0x22 selects one of 12 slots. Mode 0 clears the
// slot; mode 1 sets it and plays sound 0xDC + slot the first time the object's x
// coordinate (obj+0xA plus the second halfword of the rectangle filled by
// func_800504BC) falls inside the [D_8AF2BF7C, D_8AF2BF7C + D_8AF2BF78) window,
// provided D_8AF2BF74 is clear.
s32 func_8AF03BC4(s32 mode, void *obj) {
    s16 x;
    // FAKE: unused local. It claims a 4-byte stack home that moves rect to sp+0x28;
    // without it the frame shifts and the diff scores 1218.
    s16 y;
    s16 index;
    s16 rect[4];
    s16 value;

    index = (*(s16 *)((u8 *)obj + 0x22) % 12);
    switch (mode) {
    case 0:
        ((s16 *)&D_8AF2C308)[index] = 0;
        break;
    case 1:
        func_800504BC(rect);
        x = *(s16 *)((u8 *)obj + 0xA) + rect[1];
        if (((s16 *)&D_8AF2C308)[index] == 0 && D_8AF2BF74 == 0 &&
            x > *(s32 *)&D_8AF2BF7C && x < *(s32 *)&D_8AF2BF7C + D_8AF2BF78) {
            ((s16 *)&D_8AF2C308)[index] = 1;
            switch (index) {
            case 0: value = 220; break;
            case 1: value = 221; break;
            case 2: value = 222; break;
            case 3: value = 223; break;
            case 4: value = 224; break;
            case 5: value = 225; break;
            case 6: value = 226; break;
            case 7: value = 227; break;
            case 8: value = 228; break;
            case 9: value = 229; break;
            case 10: value = 230; break;
            case 11: value = 231; break;
            default: value = 220; break;
            }
            func_800226C0(value);
        }
        break;
    }
    return 0;
}
/* mkdraft:func_8AF03BC4 end */

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

// func_8AC0077C and func_800504BC are void in their own files, but their return
// values are read here (FAKE): the live 64-bit v0/v1 result keeps v0 and v1 busy, so
// h, inner and w land in t0, t1 and t2 like retail.
extern s64 func_8AC0077C(s32, s32, s32, s32);
extern s32 D_8AF2BF6C;
extern s32 D_8AF2BF70;
extern s16 D_8AF26464;
extern s16 D_8AF26468;

s32 func_8AF03E38(s32 arg0, void *arg1) {
    void *inner = *(void **)((u8 *)arg1 + 0x20);
    s32 x;
    s32 y;
    s32 w;
    s32 bottom;
    s32 h;
    s32 r;
    s16 rect[2];

    switch (arg0) {
    case 0:
        break;
    case 1:
        r = func_800504BC(rect);
        x = rect[0] + *(s16 *)((u8 *)inner + 8);
        y = rect[1] + *(s16 *)((u8 *)inner + 0xA);
        w = *(s16 *)((u8 *)inner + 0xC);
        h = *(s16 *)((u8 *)inner + 0xE);
        D_8AF2BF78 = h;
        D_8AF2BF7C = y;
        bottom = y + h + r * 0; // FAKE r * 0
        h = 0; // FAKE: kills y + h so bottom stays a var in its own home
        r = func_8AC0077C(x, y, x + w, bottom);
        if (bottom) {} // FAKE
        if ((y + 0x37) < D_8AF26464) {
            D_8AF2BF6C = 1;
        } else {
            D_8AF2BF6C = 0;
        }
        if (D_8AF26468 < bottom + r * 0) { // FAKE r * 0
            D_8AF2BF70 = 1;
        } else {
            D_8AF2BF70 = 0;
        }
        break;
    }
    return 0;
}

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

extern s16 D_8AF26464;

extern s16 D_8AF26468;

extern u8 *D_8AF2BDD8;

extern u8 *D_8AF26460;

extern s32 D_8AF2BF80;

extern s16 D_8AF2BF84;

extern s16 D_8AF2BF86;

extern u8 func_8AC00334(s16, s16);

extern void func_8AF01020(s16, s16);

extern s16 D_8AF2BA6C;

s32 func_8AF0455C(s32 arg0, u8 *arg1) {
    u8 *inner;
    s32 x;
    s32 y;
    u8 *node = *(u8 **)(arg1 + 0x20);
    u8 flag;
    u8 *entry;
    s16 mode = 0;
    s16 pos[2];
    s32 i;
    u8 *p;
    entry = *(u8 **)(D_8AF2BDD8 + 8);
    inner = D_8AF26460 + 0x28;
    switch (D_8AF2BA6C) {
    case 3: break;
    case 4: mode = 1; break;
    case 5: mode = 2; break;
    }
    flag = func_8AC00334(mode, (s16)(node[0] - 1));
    switch (arg0) {
    case 0:
        p = *(u8 **)(inner + 0x4C8);
        *(s32 *)(inner + 0x4D4) = *(s16 *)(p + 8) + 5;
        *(s32 *)(inner + 0x4DC) = *(s16 *)(p + 0xA) + 190;
        *(s32 *)(inner + 0x4D8) = *(s16 *)(p + 0xC) + *(s16 *)(p + 8) - 5;
        *(s32 *)(inner + 0x4E0) = *(s16 *)(p + 0xE) + *(s16 *)(p + 0xA) + 45;
        if (flag == 0) func_8AF04514(arg1);
        else func_8AF0454C(arg1);
        if (mode == *(s8 *)(entry + 0x16)) {
            for (i = 0; i < 10; i++) {
                if (node[0] == *(s8 *)(entry + i + 4)) func_8AF04530(arg1);
            }
        }
        break;
    case 1:
        D_8AF2BF80 = 1;
        if (*(s32 *)(node + 0xC) == 0) {
            func_800504BC(pos);
            D_8AF26464 = *(s16 *)(arg1 + 0xA) + pos[1];
        } else if (*(s32 *)(node + 0x10) == 0) {
            func_800504BC(pos);
            D_8AF26468 = *(s16 *)(arg1 + 0xA) + pos[1];
        }
        if (*(u16 *)(arg1 + 0x26) == 0) flag = 0xFF;
        if (*(s32 *)(arg1 + 4) == *(s32 *)(inner + 0x4C0)) {
            if (func_800504BC(pos)) {} // FAKE: keeps the s32 return out of the next block
            *(s32 *)(inner + 0x4CC) = *(s16 *)(arg1 + 8) + pos[0];
            *(s32 *)(inner + 0x4D0) = *(s16 *)(arg1 + 0xA) + pos[1];
            if (*(s32 *)(inner + 0x4E0) < *(s32 *)(inner + 0x4D0)) {
                *(s32 *)(inner + 0x4E8) -= 10;
                *(s32 *)(inner + 0x4F8) = 1;
            } else if (*(s32 *)(inner + 0x4D0) < *(s32 *)(inner + 0x4DC)) {
                *(s32 *)(inner + 0x4E8) += 10;
                *(s32 *)(inner + 0x4F8) = -1;
            } else {
                *(s32 *)(inner + 0x4F8) = 0;
            }
            y = (s16)*(s32 *)(inner + 0x4D0);
            if ((s16)*(s32 *)(inner + 0x4CC) != *(s32 *)(inner + 0x4CC) || y != *(s32 *)(inner + 0x4D0)) func_8AF00130(1);
            D_8AF2BF84 = *(s32 *)(inner + 0x4CC) - 45;
            D_8AF2BF86 = *(s32 *)(inner + 0x4D0);
            func_8AF01020(D_8AF2BF84, D_8AF2BF86);
            if (flag == 0) *(s32 *)(arg1 + 0x2C) = 0xFFFF00FF;
        } else if (flag == 0) *(s32 *)(arg1 + 0x2C) = -1;
        break;
    }
    return 0;
}
extern s32 D_8AF2C584;
extern s32 D_8AF2C588;
extern s32 D_8AF2C58C;
extern s16 D_8AF2BA6C;
extern u8 D_8AF28A90[];
extern u8 D_8AF28A94[];
extern u8 D_8AF28A98[];
extern s32 func_800504BC(s16 *);
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

/* mkdraft:func_8AF04A54 begin */
extern u8 D_8AF2C590;
extern u8 D_8AF2C594;
extern s16 D_8AF2C598;
extern s16 D_8AF2C59A;

typedef struct { u8 r, g, b, a; } Func8AF04A54RGBA;

// Case 0 blends the working color D_8AF2C590 with D_8AF2C594, weighting the D_8AF2C594 bytes
// 217/292 and the D_8AF2C590 bytes 75/292, and stores the result in the two RGBA fields
// arg1+0x2C and arg1+0x30 (func_8AF04530 writes 0xDC0000FF, opaque red, to arg1+0x2C).
// unk_D_8AF2BFB4 and D_8AF2BFB4/D_8AF2BFB8 are declared for func_8AF04A14 above.
// The byte loads reach both words through these two pointers rather than through the symbols
// themselves so they cannot be hoisted above the word stores that initialize the words: the
// retail code loads each byte after the store that wrote it.


s32 func_8AF04A54(s32 arg0, u8 *arg1) {
    s32 pad; // FAKE: never read or written; as the first auto it moves c from sp+0xC
             // to sp+0x10 and the frame from 0x10 to 0x18. Score 31 without it.
    Func8AF04A54RGBA c;
    u8 *cur = &D_8AF2C590;
    u8 *tgt = &D_8AF2C594;

    switch (arg0) {
    case 0:
        D_8AF2C598 = *(s16 *)(arg1 + 8);
        D_8AF2C59A = *(s16 *)(arg1 + 0xA);
        *(s32 *)&D_8AF2C590 = *(s32 *)&D_8AF2BFB4;
        *(s32 *)&D_8AF2C594 = *(s32 *)&D_8AF2BFB8;
        c.r = (tgt[0] * 217 + cur[0] * 75) / 292;
        c.g = (tgt[1] * 217 + cur[1] * 75) / 292;
        c.b = (tgt[2] * 217 + cur[2] * 75) / 292;
        c.a = (tgt[3] * 217 + cur[3] * 75) / 292;
        arg1[0x28] = 0x22;
        *(Func8AF04A54RGBA *)(arg1 + 0x2C) = c;
        *(Func8AF04A54RGBA *)(arg1 + 0x30) = c;
        break;
    case 1: // karodo: empty arm; without it the switch compiles as an if
        break;
    }
    return 0;
}
/* mkdraft:func_8AF04A54 end */

s32 func_8AF0455C(s32 arg0, u8 *arg1);
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

extern s32 func_8004DC6C(s32);
extern s32 func_8004EB58(void *, s32);
extern void *MainPool_AllocState(s32, s32);
extern s32 main_pool_get_available(void);
extern void MainPool_FinalizeAllocation(void *);
extern void func_8AC00DF4(s32);
extern s32 func_8004DCFC(u8 *, s32 *);
extern void func_8AC03334(s32, s32, s32, void *);
extern void func_8004C8C0(s32);
extern void func_8AC05E40(s32, s32, void *);
extern void func_8AC06400(void *, s32);
extern void func_8AC05ED4(s32, s32, void *);
extern void func_8AC027D0(s32, s32, void *, s32);
extern void func_8AC02C80(s32, s32, s32, void *);
extern void func_80021ED8(s32);
extern s32 func_8AF013D8(s32, void *);
extern s32 func_8AF03E38(s32, void *);
extern s16 D_8AF2C322;
extern u8 D_8AF27E30[];
extern u8 D_8AF28274[];
extern u8 D_8AF284E4[];
extern u8 D_8AF2C330[];
extern u8 D_8AF2C35C[];
extern u8 D_8AF2C388[];
extern u8 D_8AF2C3B4[];
extern u8 D_8AF2C3E0[];
extern u8 D_8AF2C40C[];
extern u8 *D_8AF2BF64;
extern s32 D_8AF2BF50;
extern s32 D_8AF2BF54;
extern u8 *D_8AF2BF58;
extern u8 *D_8AF2BF5C;
extern u8 *D_8AF2BF48;
extern u8 *D_8AF2BF4C;
extern u8 *D_8AF2BF60;
extern u8 *D_8AF2BF68;
extern u8 D_8AF2C4E8[];
extern u8 D_8AF26498[];
extern u8 D_8AF2BFC0[];
extern u8 D_8AF2BFF0[];
extern u8 D_8AF2C028[];
extern u8 D_8AF2C058[];
extern u8 D_8AF2BF88[];
extern s32 D_8AF2BF6C;
extern s32 D_8AF2BF70;

void func_8AF0501C(void *arg0, s32 arg1, s32 arg2) {
    void *state;
    s32 heap;
    s32 slid;
    s32 obj;
    u8 *mark;
    s32 cate;
    s32 idx;
    s32 waku;
    s32 oya;
    s32 sfx;
    s32 *ent;
    u8 *winc;
    u8 *su;
    u8 *base;

    winc = NULL;
    base = (u8 *)arg0 + 0x28;
    D_8AF2C322 = 0;
    if (*(s32 *)((u8 *)arg0 + 0x4D8) < 100) {
        heap = func_8004DC6C(arg1);
        state = MainPool_AllocState(main_pool_get_available(), 0);
        idx = func_8AF04DB8(arg1);
        obj = func_8004EB58(state, heap);
        MainPool_FinalizeAllocation(state);
        if (idx != -1 && idx < 100) {
            ent = (s32 *)base + idx * 3;
            ent[0] = obj;
            ent[1] = func_8AC06D8C(obj, 0x656E646C);
            ent[2] = heap;
            func_8AC00DF4(ent[0]);
            func_8AF04F38(ent[0]);
            switch (D_8AF2BA6C) {
                case 3:
                    D_8AF2BFB4.unk_0 = 0xA07819FF;
                    D_8AF2BFB8.unk_0 = 0xE6DC64FF;
                    sfx = 0x11F;
                    break;
                case 4:
                    D_8AF2BFB4.unk_0 = 0x147D32FF;
                    D_8AF2BFB8.unk_0 = 0x64DB64FF;
                    sfx = 0x120;
                    break;
                case 5:
                    D_8AF2BFB4.unk_0 = 0x143C82FF;
                    D_8AF2BFB8.unk_0 = 0xA5C8FF;
                    sfx = 0x121;
                    break;
                default:
                    sfx = 0;
                    break;
            }
            switch (arg1) {
                case 0x59:
                    if (arg2 == 1) {
                        func_8004DCFC((u8 *)ent[2], 0);
                        func_8AF04C50(arg0, ent[0], D_8AF27E30);
                        func_8AF04CC8(arg0, ent[0], D_8AF27E30);
                        func_8004E308(ent[0], func_8AF03D34, (s32)base);
                        func_8004E308(ent[1], func_8AF03F4C, (s32)base);
                        func_8AC03334(ent[0], 0x74305F6C, 0x74305F72, D_8AF2C330);
                        func_8AC03334(ent[0], 0x74315F6C, 0x74315F72, D_8AF2C35C);
                        func_8AC03334(ent[0], 0x74325F6C, 0x74325F72, D_8AF2C388);
                        func_8AC03334(ent[0], 0x74335F6C, 0x74335F72, D_8AF2C3B4);
                        func_8AC03334(ent[0], 0x74345F6C, 0x74345F72, D_8AF2C3E0);
                        func_8AC03334(ent[0], 0x74355F6C, 0x74355F72, D_8AF2C40C);
                        func_8AF04E8C(ent[0]);
                    }
                    break;
                case 0x42:
                    if (arg2 == 1) {
                        func_8004DCFC((u8 *)ent[2], 0);
                        func_8AF04C50(arg0, ent[0], D_8AF28274);
                        func_8AF04CC8(arg0, ent[0], D_8AF28274);
                        func_8004E308(ent[0], func_8AF03D34, (s32)base);
                        func_8004E308(ent[1], func_8AF03F4C, (s32)base);
                        func_8AC03334(ent[0], 0x74305F6C, 0x74305F72, D_8AF2C330);
                        func_8AC03334(ent[0], 0x74315F6C, 0x74315F72, D_8AF2C35C);
                        func_8AC03334(ent[0], 0x74325F6C, 0x74325F72, D_8AF2C388);
                        func_8AC03334(ent[0], 0x74335F6C, 0x74335F72, D_8AF2C3B4);
                        func_8AC03334(ent[0], 0x74345F6C, 0x74345F72, D_8AF2C3E0);
                        func_8AF04E8C(ent[0]);
                    }
                    break;
                case 0x4D:
                    if (arg2 == 1) {
                        func_8004DCFC((u8 *)ent[2], 0);
                        func_8AF04C50(arg0, ent[0], D_8AF284E4);
                        func_8AF04CC8(arg0, ent[0], D_8AF284E4);
                        func_8004E308(ent[0], func_8AF03D34, (s32)base);
                        func_8004E308(ent[1], func_8AF03F4C, (s32)base);
                        func_8AC03334(ent[0], 0x74305F6C, 0x74305F72, D_8AF2C330);
                        func_8AC03334(ent[0], 0x74315F6C, 0x74315F72, D_8AF2C35C);
                        func_8AC03334(ent[0], 0x74325F6C, 0x74325F72, D_8AF2C388);
                        func_8AC03334(ent[0], 0x74335F6C, 0x74335F72, D_8AF2C3B4);
                        func_8AF04E8C(ent[0]);
                    }
                    break;
                case 0x58:
                    func_8004DCFC((u8 *)ent[2], 0);
                    func_8004E308(func_8AC06D8C(ent[0], 0x6579655F), func_8AF03730, 0);
                    func_8004E308(ent[0], func_8AF03F14, (s32)base);
                    break;
                case 0x30:
                    func_8004C8C0(sfx);
                    func_8004DCFC((u8 *)ent[2], 0);
                    D_8AF2BF64 = (u8 *)func_8AC06D8C(ent[0], 0x6F62695F);
                    su = (u8 *)func_8AC06D8C(ent[0], 0x735F755F);
                    D_8AF2C088 = *(s16 *)((u8 *)func_8AC06D8C(ent[0], 0x735F645F) + 0xA) - *(s16 *)(su + 0xA);
                    D_8AF2BF50 = func_8AC06D8C(ent[0], 0x6162746E);
                    func_8AC05E40(ent[0], 0x6162746E, D_8AF2C278);
                    func_8AC06400(D_8AF2C278, D_8AF2BF50);
                    *(u16 *)((u8 *)D_8AF2BF50 + 2) &= ~1;
                    mark = (u8 *)func_8AC06D8C(ent[0], 0x6D61726B);
                    *(s16 *)(mark + 0x24) = sfx;
                    *(s16 *)(mark + 0x26) = 0;
                    func_8004E308(ent[0], func_8AF03F14, (s32)base);
                    slid = func_8AC06D8C(ent[0], 0x736C6964);
                    func_8004E308(slid, func_8AF04404, (s32)base);
                    func_8005053C((void *)slid, D_8AF2C4E8);
                    func_80050578((void *)slid, (s32)D_8AF26498);
                    cate = func_8AC06D8C(ent[0], 0x63617465);
                    func_8004E308(cate, func_8AF03DA8, cate);
                    func_8004E308(func_8AC06D8C(ent[0], 0x6B6F756D), func_8AF03DF0, (s32)base);
                    func_8004E308(func_8AC06D8C(ent[0], 0x66756B69), func_8AF04A54, 0);
                    func_8AC05ED4(ent[0], 0x79616A31, &D_8AF2C098);
                    func_8AC05ED4(ent[0], 0x79616A32, &D_8AF2C110);
                    oya = func_8AC06D8C(ent[0], 0x6F796131);
                    D_8AF2BF54 = oya;
                    *(u16 *)((u8 *)D_8AF2BF54 + 2) &= ~1;
                    winc = (u8 *)func_8AC06D8C(ent[0], 0x77696E63);
                    D_8AF2BF5C = (u8 *)func_8AC06D8C(ent[0], 0x6D696769);
                    D_8AF2BF58 = (u8 *)func_8AC06D8C(ent[0], 0x68696461);
                    func_8004E308((s32)D_8AF2BF5C, func_8AF013D8, 0);
                    func_8004E308((s32)D_8AF2BF58, func_8AF013D8, 0);
                    D_8AF2BF48 = (u8 *)func_8AC06D8C(ent[0], 0x74616731);
                    D_8AF2BF4C = (u8 *)func_8AC06D8C(ent[0], 0x74616732);
                    func_8AC027D0(ent[0], 0x4D617331, D_8AF2BFC0, D_8AF2BFB8.unk_0);
                    func_8AC027D0(ent[0], 0x4D617332, D_8AF2BFF0, D_8AF2BFB8.unk_0);
                    func_8AC027D0(ent[0], 0x4D617333, D_8AF2C028, D_8AF2BFB4.unk_0);
                    func_8AC027D0(ent[0], 0x4D617334, D_8AF2C058, D_8AF2BFB4.unk_0);
                    func_8AC02C80(ent[0], 0x725F6C5F, 0x725F725F, D_8AF2BF88);
                    break;
                case 4:
                    func_8004DCFC((u8 *)ent[2], 0);
                    waku = func_8AC06D8C(ent[0], 0x77616B75);
                    *(s32 *)(base + 0x4C8) = waku;
                    func_8004E308(waku, func_8AF03E38, waku);
                    D_8AF2BF68 = (u8 *)func_8AC06D8C(ent[0], 0x6B6F6B31);
                    func_8004E308((s32)D_8AF2BF68, func_8AF04A14, 0);
                    break;
                case 0x31:
                    func_8004C8C0(sfx);
                    func_8004C8C0(0xB5);
                    func_8004C8C0(0xB6);
                    D_8AF2BF60 = (u8 *)func_8AC06D8C(ent[0], 0x6F62695F);
                    func_8004E308(ent[0], func_8AF03F14, (s32)base);
                    func_8004E308(func_8AC06D8C(ent[0], 0x7469746C), func_8AF04894, (s32)base);
                    slid = func_8AC06D8C(ent[0], 0x736C6964);
                    func_8004E308(slid, func_8AF04340, (s32)base);
                    func_8005053C((void *)slid, D_8AF2C4E8);
                    func_80050578((void *)slid, (s32)D_8AF26498);
                    su = (u8 *)func_8AC06D8C(ent[0], 0x735F755F);
                    D_8AF2C088 = *(s16 *)((u8 *)func_8AC06D8C(ent[0], 0x735F645F) + 0xA) - *(s16 *)(su + 0xA);
                    func_8004E308(func_8AC06D8C(ent[0], 0x66756B69), func_8AF04A54, 0);
                    mark = (u8 *)func_8AC06D8C(ent[0], 0x6D61726B);
                    *(s16 *)(mark + 0x24) = sfx;
                    *(s16 *)(mark + 0x26) = 0;
                    func_8AC05ED4(ent[0], 0x79616A31, &D_8AF2C188);
                    func_8AC05ED4(ent[0], 0x79616A32, &D_8AF2C200);
                    func_8AC027D0(ent[0], 0x4D617331, D_8AF2BFC0, D_8AF2BFB8.unk_0);
                    func_8AC027D0(ent[0], 0x4D617332, D_8AF2BFF0, D_8AF2BFB8.unk_0);
                    func_8AC027D0(ent[0], 0x4D617333, D_8AF2C028, D_8AF2BFB4.unk_0);
                    func_8AC027D0(ent[0], 0x4D617334, D_8AF2C058, D_8AF2BFB4.unk_0);
                    func_8AC02C80(ent[0], 0x725F6C5F, 0x725F725F, D_8AF2BF88);
                    func_80021ED8(7);
                    break;
                default:
                    func_8004E308(ent[0], func_8AF03FF8, (s32)base);
                    func_8004E308(ent[1], func_8AF03F4C, (s32)base);
                    break;
            }
            if (winc != NULL) {
                *(s32 *)(winc + 0x3C) = D_8AF2BFB4.unk_0;
                *(s32 *)(winc + 0x40) = D_8AF2BFB8.unk_0;
            }
            if (arg2 == 1) {
                *(u16 *)((u8 *)ent[0] + 2) |= 1;
                *(u16 *)((u8 *)ent[0] + 2) |= 2;
            } else {
                *(u16 *)((u8 *)ent[0] + 2) &= ~1;
                *(u16 *)((u8 *)ent[0] + 2) &= ~2;
            }
            D_8AF2C548 = 0;
            D_8AF2BF6C = 0;
            D_8AF2BF70 = 0;
        }
    }
}

extern s32 D_8AF2BE80;
extern s32 D_8AF2BE84;
extern s32 D_8AF2BF40;
extern s32 D_8AF2BF74;
extern s16 D_8AF2C094;
extern s32 D_8AF2C2F0;
extern void func_8AC00FFC(s32);
extern s32 func_8004C4B0(s32);
extern void func_8AC006F4(void);
extern u8 *func_8AF04D68(void);

typedef struct {
    u8 unk_000[0x4B0];
    s32 unk_4B0;
    s32 unk_4B4;
    u8 unk_4B8[4];
    s8 unk_4BC;
} unk_func_8AF05C10;

// Resets the per-mode id buffer at arg0 + 0x28, then replays the id list
// returned by func_8AF04D68 through func_8AF0501C.
//
// func_8AF0501C reads the entry counter at arg0 + 0x4D8 (sub->unk_4B0) and
// returns without recording the id once the counter reaches 100, so the
// counter is incremented here after every call.


void func_8AF05C10(void *arg0) {
    s32 var_a2;
    s16 temp_a1;
    s16 *var_s0;
    unk_func_8AF05C10 *sub;

    sub = (unk_func_8AF05C10 *)((u8 *)arg0 + 0x28);
    D_8AF2C2F0 = 0;
    if (D_8AF2BE80 == 0) {
        func_8AC00FFC(0x4F475343);
    }
    D_8AF2BE80 = 1;
    D_8AF2BF40 = 0;
    func_8004C4B0(0x37);
    func_8AC006F4();
    sub->unk_4BC = 0;
    sub->unk_4B0 = 0;
    D_8AF2BF74 = 0;
    D_8AF2C094 = 0;
    var_s0 = (s16 *)func_8AF04D68();
    // func_8AF04D68 returns a -1-terminated list of ids (possibly NULL, empty).
    for (;;) {
        temp_a1 = *var_s0;
        if (temp_a1 == -1) {
            break;
        }
        // Selection flag: func_8AF0501C sets bits 0 and 1 of the record's
        // u16 status word when var_a2 is non-zero, and clears them when it is
        // zero. The mode's own id (D_8AF2BE84 2, 3 or 4) is selected, as are
        // 4, 0x31 and 0x58 in every mode.
        var_a2 = 0;
        switch (temp_a1) {
        case 0x59:
            if (D_8AF2BE84 == 2) {
                var_a2 = 1;
            }
            break;
        case 0x42:
            if (D_8AF2BE84 == 3) {
                var_a2 = 1;
            }
            break;
        case 0x4D:
            if (D_8AF2BE84 == 4) {
                var_a2 = 1;
            }
            break;
        case 4:
        case 0x31:
        case 0x58:
            var_a2 = 1;
            break;
        default:
            break;
        }
        func_8AF0501C(arg0, temp_a1, var_a2);
        var_s0++;
        sub->unk_4B0 += 1;
    }
    // Store the id of the mode's table set. func_8AF05E14 reads it back from
    // arg0 + 0x4DC (sub->unk_4B4) and picks D_8AF27E30, D_8AF28274 or
    // D_8AF284E4 from it.
    switch (D_8AF2BE84) {
    case 2:
        sub->unk_4B4 = 0x59;
        break;
    case 3:
        sub->unk_4B4 = 0x42;
        break;
    case 4:
        sub->unk_4B4 = 0x4D;
        break;
    }
}

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

extern s16 D_8AF2C08A;
extern s16 D_8AF2C322;
extern s16 D_8AF2C094;
extern s32 D_8AF2C2F0;
extern s32 D_8AF2BF40;
extern s32 D_8AF2646C;
extern s32 D_8AF2C090;
extern s32 D_8AF2BF50;
extern s32 D_8AF2BF54;
extern u8 *D_8AF2BAB8;
extern s16 D_8AF2C08C;
extern s32 func_8AF05E14(void *, s32);
extern void func_8AF035E0(void *);
extern s32 func_8AF03878(s32, void *);
extern s32 func_8AF03BC4(s32, void *);
extern void func_8AF03B74(void);
extern s32 *func_8AF04E2C();
extern s32 func_8AC06D8C(s32, s32);
extern void func_8AC00FFC(s32);
extern s32 func_8004DCFC(u8 *, s32 *);
extern void func_80021ED8(s32);


void func_8AF05EE0(void *arg0) {
    u8 *sub;
    s32 *entry;
    u8 *current;
    u8 *old;
    s32 h1, h2, h3, h4, h5, h6, h7, h8, h9, h10, h11, h12, h13, h14, h15;
    u16 *tbl;
    s32 key;

    sub = (u8 *)arg0 + 0x28;
    D_8AF2C322 = 0;
    func_8AF03B74();
    old = (u8 *)*func_8AF04E2C(arg0, *(s32 *)(sub + 0x4B4));
    if ((D_8AF2C090 = func_8AF05E14(arg0, *(s32 *)(sub + 0x4B8))) == -1) {
        return;
    }
    entry = func_8AF04E2C(arg0, D_8AF2C090);
    current = (u8 *)*entry;
    *(s32 *)(sub + 0x4B4) = *(s32 *)&D_8AF2C090;
    D_8AF2C094 = 1;
    D_8AF2C2F0 = 0;

    h1 = func_8AC06D8C(*entry, 0x53453031);
    h2 = func_8AC06D8C(*entry, 0x53453032);
    h3 = func_8AC06D8C(*entry, 0x53453033);
    if (h1 != 0) {
        func_8004E308(h1, (void *)&func_8AF03878, 0);
    }
    if (h2 != 0) {
        func_8004E308(h2, (void *)&func_8AF03878, 1);
    }
    if (h3 != 0) {
        func_8004E308(h3, (void *)&func_8AF03878, 2);
    }

    h4 = func_8AC06D8C(*entry, 0x4A565331);
    h5 = func_8AC06D8C(*entry, 0x4A565332);
    h6 = func_8AC06D8C(*entry, 0x4A565333);
    if (h4 != 0) {
        func_8004E308(h4, (void *)&func_8AF03BC4, 0);
    }
    if (h5 != 0) {
        func_8004E308(h5, (void *)&func_8AF03BC4, 1);
    }
    if (h6 != 0) {
        func_8004E308(h6, (void *)&func_8AF03BC4, 2);
    }

    h7 = func_8AC06D8C(*entry, 0x4A564431);
    h8 = func_8AC06D8C(*entry, 0x4A564432);
    h9 = func_8AC06D8C(*entry, 0x4A564433);
    if (h7 != 0) {
        func_8004E308(h7, (void *)&func_8AF03BC4, 3);
    }
    if (h8 != 0) {
        func_8004E308(h8, (void *)&func_8AF03BC4, 4);
    }
    if (h9 != 0) {
        func_8004E308(h9, (void *)&func_8AF03BC4, 5);
    }

    h10 = func_8AC06D8C(*entry, 0x4A564331);
    h11 = func_8AC06D8C(*entry, 0x4A564332);
    h12 = func_8AC06D8C(*entry, 0x4A564333);
    if (h10 != 0) {
        func_8004E308(h10, (void *)&func_8AF03BC4, 6);
    }
    if (h11 != 0) {
        func_8004E308(h11, (void *)&func_8AF03BC4, 7);
    }
    if (h12 != 0) {
        func_8004E308(h12, (void *)&func_8AF03BC4, 8);
    }

    h13 = func_8AC06D8C(*entry, 0x4A564531);
    h14 = func_8AC06D8C(*entry, 0x4A564532);
    h15 = func_8AC06D8C(*entry, 0x4A564533);
    if (h13 != 0) {
        func_8004E308(h13, (void *)&func_8AF03BC4, 9);
    }
    if (h14 != 0) {
        func_8004E308(h14, (void *)&func_8AF03BC4, 0xA);
    }
    if (h15 != 0) {
        func_8004E308(h15, (void *)&func_8AF03BC4, 0xB);
    }

    func_8AF035E0(sub);
    *(s32 *)(sub + 0x4E4) = 0;
    *(s32 *)(sub + 0x4E8) = 0;
    *(s32 *)(sub + 0x4EC) = 0;
    *(u16 *)((u8 *)D_8AF2BF50 + 2) &= ~1;
    *(u16 *)((u8 *)D_8AF2BF54 + 2) &= ~1;
    D_8AF2C08A = 1;
    func_8004C594(2, D_8AF2C08A);
    D_8AF2C08C = 99;
    tbl = (u16 *)D_8AF2BAB8;
loop:
    if (*tbl == D_8AF2C090) {
        D_8AF2C08C = tbl[1];
    } else {
        tbl += 2;
        goto loop;
    }
    func_8004C594(3, D_8AF2C08C);

    func_8AC00FFC(0x5273635A);
    D_8AF2BF40 = 1;
    func_8004DCFC((u8 *)entry[2], 0);
    *(u16 *)(current + 2) |= 1;
    *(u16 *)(current + 2) |= 2;
    *(u16 *)(old + 2) &= ~1;
    *(u16 *)(old + 2) &= ~2;
    old = (u8 *)*func_8AF04E2C(arg0, 0x31);
    *(u16 *)(old + 2) &= ~1;
    *(u16 *)(old + 2) &= ~2;
    current = (u8 *)*func_8AF04E2C(arg0, 0x30);
    *(u16 *)(current + 2) |= 1;
    *(u16 *)(current + 2) |= 2;
    D_8AF2646C = 0;
    func_80021ED8(103);
}

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

extern u8 *D_8AF2BF48;

extern u8 *D_8AF2BF4C;

extern u8 *D_8AF2BF58;

extern u8 *D_8AF2BF5C;

extern u8 *D_8AF2BF64;

extern u8 *D_8AF2BF68;

extern s16 D_8AF2C320;

extern s16 D_8AF2C328;

extern s32 D_8AF26564;

extern s32 func_8AC008E4(void);

extern void func_8AC00824(void);

extern void func_8AF258B4(s32, s16);

extern void *Util_Malloc(s32);

extern void Util_Free(void *);

s32 func_8AF065DC(void *arg0) {
    s32 pad0[4]; /* FAKE: reserve the original frame's unused local slots. */
    s16 mode = 0;
    s32 pad1[2]; /* FAKE: preserve the original local-variable offsets. */
    u8 *sub;
    s32 result;
    u8 *save;
    u8 *temporary;
    s32 count;
    s32 pad2[1]; /* FAKE: preserve scratch-pointer stack slots. */
    if (func_8AC008E4() == 0) {
        if (D_8AF2C322 < 10) {
            if (D_8AF2BF60) *(u16 *)(D_8AF2BF60 + 2) |= 1;
            if (D_8AF2BF64) *(u16 *)(D_8AF2BF64 + 2) |= 1;
        } else {
            if (D_8AF2BF60) *(u16 *)(D_8AF2BF60 + 2) &= ~1;
            if (D_8AF2BF64) *(u16 *)(D_8AF2BF64 + 2) &= ~1;
        }
        D_8AF2C322++;
        if (D_8AF2C322 > 1000) D_8AF2C322 = 1000;
    } else {
        if (D_8AF2BF60) *(u16 *)(D_8AF2BF60 + 2) |= 1;
        if (D_8AF2BF64) *(u16 *)(D_8AF2BF64 + 2) |= 1;
    }
    if (*(s32 *)arg0 == 4) {
    sub = (u8 *)arg0 + 40;
    D_8AF2BF44 = func_8AF05DC8(sub);
    switch (*(s32 *)(sub + 0x4B4)) {
    case 89:
        func_8004C594(2, *(u8 *)D_8AF2BF44);
        func_8004C594(3, 20); break;
    case 66:
        mode = 1;
        func_8004C594(2, *(u8 *)D_8AF2BF44);
        func_8004C594(3, 11); break;
    case 77:
        mode = 2;
        func_8004C594(2, *(u8 *)D_8AF2BF44);
        func_8004C594(3, 11); break;
    }
    func_8AF037EC();
    switch (D_8AF2C094) {
    case 0:
        if (D_8AF2C2F0 && !*(s32 *)(sub + 0x4F8) && D_8AF2BF80 == 1) {
            if (*(u16 *)((u8 *)D_8AF263C0 + 12) & 0x800) {
                if (D_8AF2BF44 && *(s32 *)((u8 *)D_8AF2BF44 + 12)) {
                    func_8AF00130(1);
                    *(s32 *)(sub + 0x4B8) = *(s32 *)((u8 *)D_8AF2BF44 + 12);
                    *(s32 *)(sub + 0x4C0) = *(s32 *)((u8 *)D_8AF2BF44 + 24);
                }
            } else if (*(u16 *)((u8 *)D_8AF263C0 + 12) & 0x400) {
                if (D_8AF2BF44 && *(s32 *)((u8 *)D_8AF2BF44 + 16)) {
                    func_8AF00130(1);
                    *(s32 *)(sub + 0x4B8) = *(s32 *)((u8 *)D_8AF2BF44 + 16);
                    *(s32 *)(sub + 0x4C0) = *(s32 *)((u8 *)D_8AF2BF44 + 28);
                }
            } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x8000) {
                result = func_8AF05E94(sub);
                if (result != -1 && result != *(s32 *)(sub + 0x4B4)) {
                    func_8AF00130(192);
                    func_8AF05EE0(arg0);
                }
            } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
                func_8AF00130(3);
                func_8AF258B4(0, mode);
                return -1;
            }
        }
        break;
    case 1:
        if (D_8AF2C08A == D_8AF2C08C && !D_8AF2BF74) {
            *(u16 *)((u8 *)D_8AF2BF50 + 2) |= 1;
            func_8AF03798();
        } else *(u16 *)((u8 *)D_8AF2BF50 + 2) &= ~1;
        if (D_8AF2C2F0 && !D_8AF2646C &&
            !(*(u16 *)((u8 *)D_8AF263C0 + 12) & 0x800) &&
            !(*(u16 *)((u8 *)D_8AF263C0 + 12) & 0x400) &&
            !(*(u16 *)((u8 *)D_8AF263C0 + 6) & 0x800) &&
            !(*(u16 *)((u8 *)D_8AF263C0 + 6) & 0x400) &&
            !(*(u16 *)((u8 *)D_8AF263C0 + 6) & 0x200) &&
            !(*(u16 *)((u8 *)D_8AF263C0 + 6) & 0x100)) {
            if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x8000) {
                if (D_8AF2C08A == D_8AF2C08C && !D_8AF2BF74) {
                    if (!D_8AF26564) {
                        D_8AF2C094 = 2;
                        D_8AF2C320 = 0;
                        *(u16 *)((u8 *)D_8AF2BF54 + 2) |= 1;
                        D_8AF2C328 = 0;
                        *(u16 *)(D_8AF2BF5C + 2) &= ~1;
                        *(u16 *)(D_8AF2BF58 + 2) &= ~1;
                        *(u16 *)((u8 *)D_8AF2BF50 + 2) &= ~1;
                        func_8AF00130(194);
                    } else {
                        func_8AF00130(3);
                        func_8AF06404(sub);
                        if (D_8AF26564) { func_80021ED8(7); return -2; }
                    }
                }
            } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
                if (func_8AF03B38() == 0) {
                    func_8AF00130(3);
                    result = func_8AF06404(sub);
                    if (D_8AF26564) { func_80021ED8(7); return -2; }
                    if (result != -1 && result != *(s32 *)(sub + 0x4B4)) {
                        func_8AF06450(arg0, result);
                        func_8AC00824();
                    } else return -1;
                }
            }
        }
        break;
    case 2:
        count = D_8AF2C328;
        if (count >= 3) {
            *(u16 *)((u8 *)D_8AF2BF68 + 2) &= ~2;
            D_8AF2C328 = 3;
        } else D_8AF2C328 = count + 1;
        if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x8000) {
            if (D_8AF2C320 == 0) {
                save = *(u8 **)(D_8AF2BDD8 + 8);
                save[21] = *(u8 *)D_8AF2BF44;
                temporary = Util_Malloc(1284);
                func_8AF03624(temporary);
                *(s16 *)(save + 24) = *(s32 *)(temporary + 0x4E8);
                Util_Free(temporary);
                switch (D_8AF2BA6C) {
                default: save[3] = 0; break;
                case 3: save[3] = 0; break;
                case 4: save[3] = 1; break;
                case 5: save[3] = 2; break;
                }
                func_8AF00130(193);
                return -3;
            }
            func_8AF00130(3);
            result = func_8AF06404(sub);
            func_8AF06450(arg0, result);
            func_8AC00824();
            *(u16 *)((u8 *)D_8AF2BF54 + 2) &= ~1;
            *(u16 *)((u8 *)D_8AF2BF68 + 2) |= 2;
        } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
            *(u16 *)((u8 *)D_8AF2BF54 + 2) &= ~1;
            *(u16 *)((u8 *)D_8AF2BF68 + 2) |= 2;
            func_8AF00130(3);
            result = func_8AF06404(sub);
            func_8AF06450(arg0, result);
            func_8AC00824();
        } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x200) {
            if (D_8AF2C320 != 0) func_8AF00130(1);
            D_8AF2C320 = 0;
        } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x100) {
            if (D_8AF2C320 != 1) func_8AF00130(1);
            D_8AF2C320 = 1;
        }
        switch (D_8AF2C320) {
        case 0:
            *(u32 *)(D_8AF2BF48 + 40) = 0xFFFF00FF;
            *(u32 *)(D_8AF2BF48 + 44) = 0xFFFF00FF;
            *(u32 *)(D_8AF2BF4C + 40) = 0xFFFFFFFF;
            *(u32 *)(D_8AF2BF4C + 44) = 0xFFFFFFFF;
            *(u16 *)(D_8AF2BF58 + 2) |= 1;
            *(u16 *)(D_8AF2BF5C + 2) &= ~1;
            break;
        case 1:
            *(u32 *)(D_8AF2BF48 + 40) = 0xFFFFFFFF;
            *(u32 *)(D_8AF2BF48 + 44) = 0xFFFFFFFF;
            *(u32 *)(D_8AF2BF4C + 40) = 0xFFFF00FF;
            *(u32 *)(D_8AF2BF4C + 44) = 0xFFFF00FF;
            *(u16 *)(D_8AF2BF58 + 2) &= ~1;
            *(u16 *)(D_8AF2BF5C + 2) |= 1;
            break;
        }
        break;
    }
    D_8AF2BF80 = 0;
    }
    return 0;
}
extern void func_800503A4(s32);
s32 *func_8AF04E2C();

// Old-style empty parameter list: func_8AF06EA4 calls this with two arguments
// that the body never reads, and a prototype with parameters would home them.
void func_8AF06E74() {
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

extern u8 D_8AF2BDCC[];
extern u8 D_8AF2BFC0[];
extern u8 D_8AF2BFF0[];
extern u8 D_8AF2C028[];
extern u8 D_8AF2C058[];
extern s16 D_8AF2C08A;
extern s16 D_8AF2C08C;
extern s32 D_8AF2BF6C;
extern s32 D_8AF2BF70;
extern void func_8AC05F00(void *);
extern void func_8AC0695C();
extern void func_8AC06A2C();
extern u8 *func_8AF04D68();
extern void func_8AF06E74();

// State machine for the mode stored in D_8AF2BA6C: func_8AF04D68 picks the
// -1-terminated s16 list of mode ids; for the "options" entry (0x31) it
// (re)builds the two option panels through func_8AC0695C/func_8AC06A2C, then
// func_8AF06E74 pushes the entry's object. On the first entry of the mode
// (D_8AF2C2F0 clear) it also raises a notification panel per visible option.
// FAKE: `volatile` holds the parameter in its 0x60(sp) home slot and reloads it
// for each func_8AF06E74 call; retail keeps that reload and spends the
// callee-saved registers on the loop-invariant panel addresses instead.
// Score without it: 1153.


void func_8AF06EA4(void *volatile arg0) {
    u8 *state = func_8AF04D68();
    s16 value;

    while (1) {
        value = *(s16 *)state;
        if (value == -1) {
            break;
        }
        if (value == 49) {
            func_8AC0695C((void *)&D_8AF2BFF0, (void *)&D_8AF2BFC0, 0, 0, 8, 0, 0, 15, *(u32 *)&D_8AF2BFB8, *(u32 *)&D_8AF2BFB8, *(u32 *)&D_8AF2BDCC);
            func_8AC06A2C((void *)&D_8AF2C058, (void *)&D_8AF2C028, 0, 0, 8, 0, 0, 15, *(u32 *)&D_8AF2BFB4, *(u32 *)&D_8AF2BFB4, *(u32 *)&D_8AF2BDCC);
        }
        func_8AF06E74(arg0, value);
        state += 2;
    }

    if (D_8AF2C2F0 != 0) {
        switch (D_8AF2C094) {
        case 0:
            if (D_8AF2BF6C == 0) {
                func_8AC05F00(&D_8AF2C188);
            }
            if (D_8AF2BF70 == 0) {
                func_8AC05F00(&D_8AF2C200);
            }
            break;
        case 1:
        case 2:
            if (D_8AF2C08A >= 2) {
                func_8AC05F00(&D_8AF2C098);
            }
            if (D_8AF2C08A < D_8AF2C08C) {
                func_8AC05F00(&D_8AF2C110);
            }
            break;
        }
    }
    D_8AF2C2F0 = 1;
}

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
