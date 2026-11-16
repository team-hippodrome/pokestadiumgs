#include "global.h"

#ifdef VERSION_US
extern void func_8130707C(void *arg0, s32 arg1);
extern void func_81307C94(void *arg0);
s32 func_8130A460(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    struct Copy { u8 bytes[8]; };
    struct State {
        u8 pad0[0x137B8];
        f32 b8;
        f32 bc;
        f32 c0;
        f32 c4;
        f32 c8;
        f32 cc;
        f32 d0;
        u8 padD4[8];
        s32 dc;
        s32 e0;
        u8 padE4[8];
        s32 ec;
        s32 f0;
        u8 f4;
        u8 f5;
    };

    ((struct State *)arg0)->f5 = 5;
    ((struct State *)arg0)->d0 = 0.0f;
    ((struct State *)arg0)->b8 = 0.0f;
    ((struct State *)arg0)->bc = (f32)(u32)((struct State *)arg0)->f4;
    ((struct State *)arg0)->c0 = 0.0f;
    ((struct State *)arg0)->c8 = 0.0f;
    ((struct State *)arg0)->c4 = 0.0f;
    ((struct State *)arg0)->cc = 0.0f;
    ((struct State *)arg0)->dc = 0;
    ((struct State *)arg0)->e0 = 0;
    *(struct Copy *)arg0 = *(struct Copy *)arg3;
    ((struct State *)arg0)->ec = arg1;
    ((struct State *)arg0)->f0 = arg2;
    func_81307C94(arg0);
    func_8130707C(arg0, 1);
    return 1;
}

extern void func_8130707C(void *arg0, s32 arg1);
s32 func_8130A570(void *arg0, s32 arg1) {
    struct S { u8 pad0[0x137F0]; s32 value; u8 gap0; u8 state; u8 gap1[4]; u8 mode; };
    struct S *s = arg0;

    if (s->state != 4) {
        return 0;
    }
    s->value = arg1;
    s->mode = 6;
    func_8130707C(arg0, 0);
    return 1;
}

void func_8130A5D0(u8 *arg0) {
    *(s32 *)(arg0 + 0x137E4) = 1;
}

extern s32 func_8130456C(void *, void *);
extern void * func_81307204(void *arg0, s32 arg1);
void func_8130A5E4(arg0)
void *arg0;
{
    struct S { u8 pad[0x137A8]; void *list; s32 base; u8 gap[4]; s16 index; s16 row; };
    struct S *s;
    s32 count;
    for (count = 0; count != 12; count++) {
        void *item = func_81307204(((struct S *)arg0)->list, ((struct S *)arg0)->row);
        if (func_8130456C((u8 *)((struct S *)arg0)->base + 0x15370, (u8 *)item + ((struct S *)arg0)->index * 0xCE8) != 0) break;
        ((struct S *)arg0)->index += 1;
        if (((struct S *)arg0)->index == 4) { ((struct S *)arg0)->index = 0; ((struct S *)arg0)->row = (((struct S *)arg0)->row + 1) % 3; }
    }
}

s32 func_8130A708(u8 *arg0) {
  u8 *new_var;
  int new_var2;
  u8 *state = arg0 + 0x137F5;
  int new_var3;
  new_var3 = 0x137FA;
  new_var = state;
  if ((*new_var) == 4) {
    func_8130A5E4();
    arg0[new_var3] = 3;
    new_var2 = 1;
    return new_var2;
  }
  return 0;
}

s32 func_8130A760(const u8 *arg0) {
    return ((arg0[0x137F5] ^ 2) == 0);
}

/* mkdraft:func_8130A778 begin */


void func_8130A778(u8 *arg0, s32 arg1, u8 (*callback)(u8)) {
    u8 buffer[0x100];
    s32 i;
    s32 j;
    u8 value;
    u8 tmp;

    for (i = 0; i < arg0[0]; i++) {
        buffer[i] = callback(((u8 **) (arg0 + 4))[0][i]);
    }
    for (i = 0; i < arg0[0]; i++) {
        for (j = arg0[0] - 1; j > 0; j--) {
            if (buffer[j] < buffer[j - 1]) {
                tmp = buffer[j];
                value = ((u8 **) (arg0 + 4))[arg1][j];
                buffer[j] = buffer[j - 1];
                ((u8 **) (arg0 + 4))[arg1][j] = ((u8 **) (arg0 + 4))[arg1][j - 1];
                buffer[j - 1] = tmp;
                ((u8 **) (arg0 + 4))[arg1][j - 1] = value;
            }
        }
    }
}
/* mkdraft:func_8130A778 end */

u8 func_8130A880(u8 arg0) {
    return arg0;
}

extern void func_8130A778(u8 *, s32, u8 (*)(u8));
extern u8 func_800637C0(u8);
extern u8 func_80073450(u8);
extern u8 func_8130A880(u8);
void func_8130A88C(u8 *arg0) {
    func_8130A778(arg0, 2, func_8130A880);
    func_8130A778(arg0, 3, func_800637C0);
    func_8130A778(arg0, 4, func_80073450);
}

// What the state's 0xE8EC pointer leads to: the selected entry's byte at 0x944.
typedef struct unk_D_8130AEF4_entry {
    /* 0x000 */ u8 unk_000[0x944];
    /* 0x944 */ s8 unk_944;
} unk_D_8130AEF4_entry;
typedef struct unk_D_8130AEF4 {
    /* 0x00000 */ u8 unk_00000[0x1A148];
    /* 0x1A148 */ unk_D_8130AEF4_entry *unk_1A148;
} unk_D_8130AEF4;
// The three nodes func_8130AF94 links into a ring (predecessor at 0x4D94, successor at
// 0x4D98), and the state holding them, the current node and its index; func_8130B06C and
// func_8130B0E0 step the current node forward and back.
typedef struct unk_D_8130B06C_node {
    /* 0x0000 */ u8 unk_0000[0x4D94];
    /* 0x4D94 */ struct unk_D_8130B06C_node *unk_4D94;
    /* 0x4D98 */ struct unk_D_8130B06C_node *unk_4D98;
    /* 0x4D9C */ u8 unk_4D9C[4];
} unk_D_8130B06C_node; // size = 0x4DA0
typedef struct unk_func_8130B06C {
    /* 0x0000 */ s16 unk_0000[4];
    /* 0x0008 */ unk_D_8130B06C_node unk_0008[3];
    /* 0xE8E8 */ unk_D_8130B06C_node *unk_E8E8;
    /* 0xE8EC */ struct unk_D_8130AEF4 *unk_E8EC;
    /* 0xE8F0 */ f32 unk_E8F0;
    /* 0xE8F4 */ u8 unk_E8F4[0xE8FC - 0xE8F4];
    /* 0xE8FC */ f32 unk_E8FC;
    /* 0xE900 */ f32 unk_E900;
    /* 0xE904 */ f32 unk_E904;
    /* 0xE908 */ s32 unk_E908;
    /* 0xE90C */ s32 unk_E90C;
    /* 0xE910 */ u8 unk_E910;
    /* 0xE911 */ u8 unk_E911;
    /* 0xE912 */ u8 unk_E912;
    /* 0xE913 */ u8 unk_E913;
    /* 0xE914 */ u8 unk_E914;
    /* 0xE915 */ u8 unk_E915;
} unk_func_8130B06C;

extern f32 func_8130B3B8(unk_func_8130B06C *, s16 *);
extern void func_81609A90(s16 *, s16 *);
void func_8130A8E0(void *arg0, s32 arg1) {
    struct S { u8 pad[0xE8F0]; f32 value; };
    s16 sp30[4];
    s16 sp28[4];
    f32 sp24;

    sp24 = ((struct S *)arg0)->value;
    ((struct S *)arg0)->value = 0.0f;
    func_8130B3B8(arg0, sp30);
    ((struct S *)arg0)->value = 16.0f;
    func_8130B3B8(arg0, sp28);
    if (arg1 != 0) {
        func_81609A90(sp30, sp28);
    } else {
        func_81609A90(sp28, sp30);
    }
    ((struct S *)arg0)->value = sp24;
}


extern f32 (*D_8160BD1C)(f32);
f32 func_8130A98C(unk_func_8130B06C *arg0) {
    return D_8160BD1C(arg0->unk_E8FC / 16);
}

s32 func_8130A9C8(u8 *arg0) {
    return arg0[0xE912] == 7;
}

// Command lists that this file's .data records point at, and func_8130B220's initial state.
typedef struct { u8 bytes[8]; } B220J4Bytes;
const u16 D_813125F0[] = { 0x004F, 0x00A3, 0x0002, 0x0000, 0x0050, 0x00A3, 0x0004, 0x0000, 0x0051, 0x0003, 0xFFFF, 0x0000 };
const u16 D_81312608[] = { 0x004E, 0x0002, 0x0003, 0x0000 };
const u16 D_81312610[] = { 0x0044, 0x00A3, 0x0001, 0x0000, 0x0045, 0x0003, 0xFFFF, 0x0000 };
const u16 D_81312620[] = { 0x0052, 0x0093, 0x0003, 0x0000, 0x0053, 0x0003, 0xFFFF, 0x0000, 0x0054, 0x00A3, 0x0004, 0x0000 };
const B220J4Bytes D_81312638 = { { 0x00, 0x35, 0x00, 0x46, 0x02, 0x19, 0x01, 0x80 } };

/* Not referenced by any still-GLOBAL_ASM function's relocations picked up by
 * the rodata-ownership scan; it's a single-owner symbol used only by
 * func_8130C570 (still GLOBAL_ASM) elsewhere in this file, but splat's
 * per-function .late_rodata migration only folds jump tables and floats into
 * a function's .s -- plain data taken by address (lui/addiu, not lw/lwc1) is
 * dropped silently. Literal-ized by hand from the retail bytes at 0x10A7D0
 * so the still-assembly func_8130C570.s (which references it externally)
 * keeps linking. */
const u8 D_81312640[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00};

s32 func_8130A9DC(void *arg0) {
    switch (((u8 *)arg0)[0xE912]) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 11:
        return 1;
    case 0:
    case 1:
    case 6:
    case 7:
    case 8:
    case 10:
    case 12:
    case 13:
        return 0;
    case 9:
        break;
    default:
        /* Retail's default case falls through without setting $v0; IDO
         * accepts a valueless `return` from a non-void function here, but
         * GCC's stricter cc-check does not. The CC_CHECK branch is never
         * seen by the real IDO build, so it can't affect the matched bytes. */
#ifdef CC_CHECK
        return 0;
#else
        return;
#endif
    }
}

s32 func_8130AA18(u8 *arg0) {
    /* Case values recovered from jtbl_81312680's actual target addresses
     * (retail table entries, not the positionally-plausible grouping): index
     * 7 targets the "return 1" body (.L8130AA40), and index 9 targets the
     * bare epilogue (.L8130AA4C) directly, skipping the "return 0" body
     * (.L8130AA48) -- i.e. it falls off the switch without setting a value,
     * same as func_8130A9DC's case 9. */
    switch (arg0[0xE912]) {
    case 2:
    case 3:
    case 5:
    case 7:
        return 1;
    case 0:
    case 1:
    case 4:
    case 6:
    case 8:
    case 10:
    case 11:
    case 12:
    case 13:
        return 0;
    case 9:
        break;
    }
#ifdef CC_CHECK
    return 0;
#endif
}


s32 func_8130AA54(u8 *arg0, s32 arg1) {
    u8 *base = arg0 + 0x8000;
    return (arg1 != base[0x6914] + base[0x6915])
        || (base[0x6913] != 0)
        || (*(s32 *)(base + 0x690C) != 0)
        || (base[0x6912] < 0xC);
}

extern f32 (*D_8160BD04)(f32);
extern s32 func_8130AA54(u8 *arg0, s32 arg1);
f32 func_8130AAA8(unk_func_8130B06C *arg0, f32 arg1, f32 arg2) {
    f32 t;
    f32 target;
    f32 base;

    if (arg0->unk_E912 == 9 && (f32)(arg0->unk_E915 + arg0->unk_E914) < arg1) {
        arg2 -= D_8160BD04(arg0->unk_E904 / 16);
    }
    if (func_8130AA54((u8 *)arg0, (s32)arg1)) {
        t = func_8130A98C(arg0);
        target = (arg1 - arg0->unk_E915 - arg0->unk_E914) * 166.0f + 101.0f;
    } else {
        t = 1.0f - arg0->unk_E8F0 / 16;
        if (arg0->unk_E908) {
            target = -143.0f;
        } else {
            target = 91.0f;
        }
    }
    base = 166.0f * arg2 + 128.0f;
    return (target - base) * t + base;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1025F0/func_8130AC40.s")


/* mkdraft:func_8130AEF4 begin */
extern s32 func_813002D0(void *);
extern s32 func_8160A438();
extern void func_8160A6AC(void *arg0);
extern void func_8160A994(u8 *arg0);
extern void func_8160B8A8(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_81302290(void *arg0);
// State block based at arg0 + 0x8000; its 0x68EC word holds the record pointer that
// func_81302290 and func_813002D0 inspect. Each use spells the base out because a
// named u8 *local for it takes the 0x18 home slot, while retail keeps the value in
// the 0x1C compiler-temp slot.


void func_8130AEF4(void *arg0, void *arg1, s32 arg2) {
    s32 limit;

    limit = func_81302290(*(s32 *)((u8 *)arg0 + 0x8000 + 0x68EC));
    func_8160B8A8(arg1, func_813002D0(*(s32 *)((u8 *)arg0 + 0x8000 + 0x68EC)), 0);
    if ((arg2 >= 0) && (arg2 < limit)) {
        func_8160A438(arg1,
                      *(s8 *)((u8 *)(*(s32 *)((u8 *)(*(s32 *)((u8 *)arg0 + 0x8000 + 0x68EC) + 0x20000) -
                                                     0x5EB8)) +
                              0x944),
                      arg2);
    } else {
        func_8160A994(arg1);
    }
    func_8160A6AC(arg1);
}
/* mkdraft:func_8130AEF4 end */

extern void func_8130AEF4(void *, void *, s32);
void func_8130AF94(unk_func_8130B06C *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_8130AEF4(arg0, &arg0->unk_0008[i], arg0->unk_E911 + i);
        if (i <= 0) {
            arg0->unk_0008[i].unk_4D94 = &arg0->unk_0008[2];
        } else {
            arg0->unk_0008[i].unk_4D94 = &arg0->unk_0008[i - 1];
        }
        if (i + 1 >= 3) {
            arg0->unk_0008[i].unk_4D98 = &arg0->unk_0008[0];
        } else {
            arg0->unk_0008[i].unk_4D98 = &arg0->unk_0008[i + 1];
        }
    }
    arg0->unk_E8E8 = &arg0->unk_0008[0];
}

extern s32 func_8160A33C(s32 arg0, u8 arg1);
void func_8130B06C(unk_func_8130B06C *arg0) {
    if (arg0->unk_E911 < 8) {
        arg0->unk_E911++;
        arg0->unk_E8E8 = arg0->unk_E8E8->unk_4D98;
        func_8130AEF4(arg0, (void *)func_8160A33C((s32)arg0->unk_E8E8, 2), arg0->unk_E911 + 2);
    }
}

void func_8130B0E0(unk_func_8130B06C *arg0) {
    if (arg0->unk_E911 > 0) {
        arg0->unk_E911--;
        arg0->unk_E8E8 = arg0->unk_E8E8->unk_4D94;
        func_8130AEF4(arg0, arg0->unk_E8E8, arg0->unk_E911);
    }
}

extern void func_8130AF94(unk_func_8130B06C *arg0);
void func_8130B12C(void *arg0) {
    u8 *base=(u8 *)arg0+0x8000;
    s32 value=(s32)*(f32 *)(base+0x68F8);
    s32 state=base[0x6911];
    s32 difference; s32 amount;
    if(value!=state){
        difference=value-state; amount=-difference;
        if(difference>0){amount=difference;}else{amount=-difference;}
        if(amount>=3){func_8130AF94(arg0);return;}
        if(state<value) { do{func_8130B06C(arg0);state=base[0x6911];}while(state<value); }
        if(value<state) { do{func_8130B0E0(arg0);state=base[0x6911];}while(value<base[0x6911]); }
    }
}

extern s32 func_8160A33C(s32 arg0, u8 arg1);
s32 func_8130B1F4(u8 *arg0) {
    u8 *base = arg0 + 0x8000;
    return func_8160A33C(*(s32 *)(base + 0x68E8), base[0x6914]);
}

typedef struct { u8 pad[0xE8EC]; void *owner; } B220J4Owner;
typedef struct { u8 pad[0xE8F0]; f32 f0, f1, f2, f3; } B220J4Floats;
typedef struct { u8 pad[0xE908]; s32 word0, word1; u8 mode, count, state, flag, enabled, last; } B220J4Tail;
typedef struct { u8 a, b, c, d, e, f, g, h; } B220J4Fields;
typedef struct { u8 bytes[4]; } B220J4Half;
typedef struct { B220J4Half first, second; } B220J4Nested;
typedef struct { u16 halves[4]; } B220J4Halves;
typedef struct { u8 first[2]; u16 middle; u8 last[4]; } B220J4Mixed;
extern void func_8130AF94(unk_func_8130B06C *arg0);
void func_8130B220(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 unused;
    s32 count = arg3 - 1;
    s32 enabled = 1;

    if (count < 0) {
        count = 0;
        enabled = 0;
    }
    _bzero(arg0, 0xE918);
    ((B220J4Tail *)arg0)->state = 0;
    ((B220J4Owner *)arg0)->owner = arg1;
    ((B220J4Tail *)arg0)->count = count;
    ((B220J4Tail *)arg0)->mode = arg2;
    func_8130AF94(arg0);
    ((B220J4Floats *)arg0)->f0 = 0.0f;
    ((B220J4Tail *)arg0)->last = count;
    ((B220J4Floats *)arg0)->f2 = count;
    ((B220J4Tail *)arg0)->enabled = enabled;
    ((B220J4Floats *)arg0)->f1 = enabled;
    ((B220J4Floats *)arg0)->f3 = 0.0f;
    *(B220J4Bytes *)arg0 = D_81312638;
    ((B220J4Tail *)arg0)->word0 = 0;
    ((B220J4Tail *)arg0)->flag = 0;
    ((B220J4Tail *)arg0)->word1 = 0;
}

extern void func_8130A8E0(void *, s32);

void func_8130B320(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    struct S {
        u8 pad0[0xE8F0];
        f32 value;
        u8 gap0[0x14];
        s32 word;
        u8 gap1[6];
        u8 state;
        u8 byte;
    };
    typedef struct { u8 raw[8]; } UnalignedCopy8;

    ((struct S *)arg0)->byte = (u8)arg2;
    ((struct S *)arg0)->word = arg3;

    switch (((struct S *)arg0)->state) {
    case 0:
    case 13:
        ((struct S *)arg0)->value = 0.0f;
    case 12:
        ((struct S *)arg0)->state = 1;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        break;
    }

    *(UnalignedCopy8 *)arg0 = *(UnalignedCopy8 *)arg1;
    func_8130A8E0(arg0, 1);
}

extern f32 (*D_8160BD08)(f32);
extern s16 *func_81609530(s32);
extern void func_8160945C(s16 *, s16 *, s16 *, f32);
f32 func_8130B3B8(unk_func_8130B06C *arg0, s16 *arg1) {
    f32 scale;
    s16 *colorA;
    s16 *colorB;

    scale = D_8160BD08(arg0->unk_E8F0 / 16);
    colorA = arg0->unk_0000;
    colorB = func_81609530(1);
    if (arg0->unk_E8FC > 0.0f) {
        scale = func_8130A98C(arg0);
        colorA = func_81609530(1);
        colorB = func_81609530(6);
        func_8160945C(arg1, colorA, colorB, scale);
        return 1.0f;
    }
    if ((arg0->unk_E912 == 12 || arg0->unk_E912 == 13) && arg0->unk_E913 == 0 && arg0->unk_E90C != 1) {
        colorA = func_81609530(arg0->unk_E908 ? 10 : 3);
    }
    func_8160945C(arg1, colorA, colorB, scale);
    return scale;
}

f32 func_8130B4E8(unk_func_8130B06C *arg0, s16 *rect) {
    f32 scale = func_8130B3B8(arg0, rect);
    f32 dx = 19.0f * scale;
    f32 t;
    f32 dy;

    if (arg0->unk_E8FC > 0.0f) {
        t = 1.0f - func_8130A98C(arg0);
    } else {
        t = scale;
    }
    dy = t * 30.0f;
    rect[0] += 8.0f + dx;
    rect[1] += 8.0f + dy;
    rect[2] -= 19 + dx;
    rect[3] -= 19 + dy;
    return scale;
}

extern s32 func_8130B1F4(u8 *arg0);
extern f32 func_8130AAA8(unk_func_8130B06C *, f32, f32);
extern void func_8160B5BC(void *, s16 *);
extern void func_8130EB04(void *, s32, void *, s32, s32, s16 *, s16 *, s32);
s32 func_8130B620(void *arg0, s32 arg1)
{
    struct AddressRecord8130B620 {
        u8 prefix[0x20];
        u8 payload[0xCC8];
    };
    u8 *data;
    s16 pos[4];
    u8 *item;

    data = (u8 *)func_8130B1F4((u8 *)arg0);
    item = ((struct AddressRecord8130B620 *)data)[*(s8 *)(data + 8)].payload;
    if (arg1 != 0 && item == *(u8 **)((u8 *)*(void **)((u8 *)arg0 + 0xE8EC) + 0x6C)) {
        return 0;
    }
    func_8160B5BC(data, pos);
    pos[0] += 0x5F;
    pos[1] += func_8130AAA8(arg0, (f32)(((u8 *)arg0)[0xE914] + ((u8 *)arg0)[0xE911]), 0.0f);
    func_8130EB04(*(void **)((u8 *)arg0 + 0xE8EC), ((u8 *)arg0)[0xE910], item, 2, 0, pos, pos, 0x98);
    return 1;
}

s32 func_8130B74C(void *arg0) {
    struct S { u8 pad[0xE8F0]; f32 x; u8 gap[8]; f32 y; };
    struct S *s = arg0;
    s->x = 0.0f;
    s->y = 0.0f;
    return 1;
}

extern f32 func_816092FC(void);
s32 func_8130B770(void *arg0) {
    struct S { u8 pad0[0xE8F0]; f32 value; u8 gap0[8]; f32 zero; u8 gap1[0x12]; u8 state; };
    struct S *s = arg0;
    s->value += func_816092FC();
    s->zero = 0.0f;
    if (s->value >= 16.0f) {
        s->value = 16.0f;
        s->state = 2;
    }
    return 1;
}

extern f32 func_816092FC(void);
extern s32 func_8130B620(void *, s32);
/* function: func_8130B7F8 */
s32 func_8130B7F8(void *arg0) {
    struct S { u8 pad[0xE8F0]; f32 first; u8 gap[8]; f32 second; u8 gap2[0x12]; u8 mode; };

    ((struct S *)arg0)->first = 16.0f;
    ((struct S *)arg0)->second += func_816092FC();
    if (((struct S *)arg0)->second >= 16.0f) {
        ((struct S *)arg0)->second = 16.0f;
        ((struct S *)arg0)->mode = 7;
        func_8130B620((void *)arg0, (s32)0);
    }
    return 1;
}

extern f32 func_816092FC(void);
extern void func_8130F5AC(s32);
s32 func_8130B88C(void *arg0) {
    struct S { u8 pad[0xE8F0]; f32 x; u8 gap[8]; f32 y; u8 gap2[0x12]; u8 flag; };

    ((struct S *)arg0)->x = 16.0f;
    ((struct S *)arg0)->y = ((struct S *)arg0)->y - func_816092FC();
    if (((struct S *)arg0)->y <= 0.0f) {
        ((struct S *)arg0)->y = 0.0f;
        ((struct S *)arg0)->flag = 2;
    }
    func_8130F5AC(*(s32 *)((u8 *)arg0 + 0xE8EC));
    return 1;
}

extern void func_800226C0(s32);
void func_8130B91C(void *arg0) {
    struct S { u8 pad[0xE912]; u8 state; u8 gap[2]; u8 value; };
    u8 temp_v0 = ((struct S *)arg0)->value;
    if ((s32)temp_v0 > 0) {
        ((struct S *)arg0)->value = temp_v0 - 1;
        ((struct S *)arg0)->state = 5;
        func_800226C0(1);
    }
}

extern void func_800226C0(s32);
void func_8130B95C(void *arg0) {
    struct S { u8 pad[0xE912]; u8 state; u8 gap[2]; u8 value; };
    u8 temp_v0 = ((struct S *)arg0)->value;
    if ((s32)temp_v0 < 8) {
        ((struct S *)arg0)->value = temp_v0 + 1;
        ((struct S *)arg0)->state = 5;
        func_800226C0(1);
    }
}

extern void func_800226C0(s32);
extern void func_8130B91C(void *);
void func_8130B9A0(void *arg0) {
    struct S { u8 pad[0xE912]; u8 state; u8 gap; u8 value; };

    u8 temp_v0 = ((struct S *)arg0)->value;
    if ((s32)temp_v0 > 0) {
        ((struct S *)arg0)->value = temp_v0 - 1;
        ((struct S *)arg0)->state = 3;
        func_800226C0(1);
        return;
    }
    func_8130B91C(arg0);
}

extern void func_800226C0(s32);
extern void func_8130B95C(void *);
void func_8130B9F4(void *arg0) {
    struct S { u8 pad[0xE912]; u8 state; u8 gap; u8 value; };

    u8 temp_v0 = ((struct S *)arg0)->value;
    if ((s32)temp_v0 <= 0) {
        ((struct S *)arg0)->value = temp_v0 + 1;
        ((struct S *)arg0)->state = 3;
        func_800226C0(1);
        return;
    }
    func_8130B95C(arg0);
}

extern void func_800226C0(s32);
extern s32 func_8130B1F4(u8 *arg0);
void func_8130BA48(void *arg0) {
    u8 *record = (u8 *)func_8130B1F4((u8 *)arg0);
    u8 *saved = (u8 *)arg0;
    u8 *base;
    u8 state;
    if (record[0x20] == 0) {
        func_800226C0(5);
        return;
    }
    func_800226C0(0x90);
    base = saved + 0x7FFF;
    state = base[0x6914];
    switch (state) {
    case 0:
    case 1:
        base[0x6913] = 4;
        break;
    case 2:
        base[0x6913] = 6;
        break;
    }
}

extern void func_800226C0(s32);
extern void func_8130B91C(void *arg0);
extern void func_8130B95C(void *arg0);
extern void func_8130B9A0(void *arg0);
extern void func_8130B9F4(void *arg0);
extern void func_8130BA48(void *arg0);
extern u8 D_800CE060[];
s32 func_8130BADC(void *arg0) {
    struct S { u8 pad[0xE8F0]; f32 f0; f32 f1; f32 f2; f32 f3; u8 pad1[0xC]; s32 word; u8 pad2[2]; u8 state; };
    u8 *p = (u8 *)arg0;
    u8 *base = p + 0x8000;
    u8 *record;
    u16 flags;
    record = D_800CE060 + base[0x6910] * 0x28;
    ((struct S *)arg0)->f0 = 16.0f;
    ((struct S *)arg0)->f3 = 0.0f;
    ((struct S *)arg0)->f2 = (f32)base[0x6915];
    ((struct S *)arg0)->f1 = (f32)base[0x6914];
    flags = *(u16 *)(record + 0xC);
    if (flags & 0x8000) {
        func_8130BA48(arg0);
    } else if (flags & 0x800) {
        func_8130B9A0(arg0);
    } else if (flags & 0x400) {
        func_8130B9F4(arg0);
    } else if (flags & 8) {
        func_8130B91C(arg0);
    } else if (flags & 4) {
        func_8130B95C(arg0);
    } else if (flags & 0x4000) {
        func_800226C0(3);
        ((struct S *)arg0)->word = 1;
        ((struct S *)arg0)->state = 12;
    }
    return 1;
}

extern u8 D_800CE060[];
extern s32 func_8160B6E4(s32 arg0);
extern void func_8160B828(s32 arg0);
extern void func_800226C0(s32);
extern s32 func_8130B1F4(u8 *arg0);
extern s32 func_8130B620(void *arg0, s32 arg1);
s32 func_8130BC44(void *arg0) {
    struct St {
        u8 pad0[0xE8EC];
        void *ptr;
        f32 f1;
        u8 gap1[8];
        f32 f2;
        u8 gap2[0x10];
        u8 idx;
        u8 gap3;
        u8 flag;
    };
    u8 *record;
    s32 p;

    record = D_800CE060 + ((struct St *)arg0)->idx * 0x28;
    p = func_8130B1F4(arg0);
    ((struct St *)arg0)->f1 = 16.0f;
    ((struct St *)arg0)->f2 = 16.0f;
    if (func_8160B6E4(p) == 0
        && (*(u16 *)(record + 0xC) & 0x8000) == 0
        && (*(u16 *)(record + 0xC) & 0x4000) != 0
        && *(u8 *)((u8 *)((struct St *)arg0)->ptr + 0x34) < 5) {
        func_800226C0(3);
        ((struct St *)arg0)->flag = 8;
        return 1;
    }
    func_8160B828(p);
    func_8130B620(arg0, 1);
    return 1;
}

extern f32 func_816092FC(void);
extern void func_8130F5AC(s32);
s32 func_8130BD2C(void *arg0) {
    struct S { u8 pad0[0xE8F0]; f32 value; u8 gap0[8]; f32 zero; u8 gap1[0x12]; u8 state; };
    struct S *s = arg0;
    s->zero = 0.0f;
    s->value -= func_816092FC();
    if (s->value <= 0.0f) {
        s->value = 0.0f;
        s->state = 0xD;
    }
    func_8130F5AC(*(s32 *)((u8 *)arg0 + 0xE8EC));
    return 1;
}

extern f32 func_816092FC(void);
extern void func_800226C0(s32);
extern void func_8160A780(s32, s32);
extern void func_8160B9A0(u8 *, s32, s32);
extern s32 func_8130B1F4(u8 *arg0);
s32 func_8130BDB8(unk_func_8130B06C *arg0) {
    u8 *record = (u8 *)func_8130B1F4((u8 *)arg0);
    s32 done;
    s32 i;
    s32 j;
    s32 count;

    arg0->unk_E900 += func_816092FC();
    done = TRUE;
    if (arg0->unk_E900 >= 120.0f) {
        arg0->unk_E900 = 120.0f;
        for (j = 0; j < 6; j++) {
            if (record[0xB + j] != 0) {
                done = FALSE;
                break;
            }
        }
        if (done) {
            arg0->unk_E904 = 0.0f;
            arg0->unk_E912 = 9;
            func_800226C0(0xA8);
            func_8160A780(arg0->unk_E8EC->unk_1A148->unk_944, arg0->unk_E911 + arg0->unk_E914);
        }
    } else {
        count = arg0->unk_E900 * 9.0f / 120.0f;
        if (count >= 7) {
            count = 6;
        }
        for (i = 0; i < count; i++) {
            func_8160B9A0(record, 5 - i, 1);
        }
    }
    return TRUE;
}

extern f32 func_816092FC(void);
extern void func_8130AF94(unk_func_8130B06C *arg0);
extern s32 func_81302290(void *arg0);
extern void func_800226C0(s32 arg0);
s32 func_8130BF1C(unk_func_8130B06C *arg0) {
    arg0->unk_E904 += func_816092FC();
    if (arg0->unk_E904 >= 16.0f) {
        arg0->unk_E904 = 16.0f;
        func_8130AF94(arg0);
        if (func_81302290(arg0->unk_E8EC) > 0) {
            arg0->unk_E912 = 11;
            func_800226C0(0x11);
        } else {
            arg0->unk_E912 = 2;
        }
    }
    return 1;
}

s32 func_8130BFCC(void *arg0) {
    struct S { u8 pad[0xE8F0]; f32 x; u8 gap[8]; f32 y; };
    struct S *s = arg0;
    s->y = 0.0f;
    s->x = 0.0f;
    return 0;
}

// Same code as func_8130C270; GS moves the value to 0xE8F4 and the target count to
// 0xE914, clears the float at 0xE8FC, steps by a quarter of func_816092FC's result
// instead of an eighth, and does not call func_8130B12C.
s32 func_8130BFF0(void *arg0) {
    struct S { u8 pad0[0xE8F4]; f32 value; u8 gap0[4]; f32 unk_E8FC; u8 gap1[0x12]; u8 state; u8 gap2[1]; u8 count; };
    struct S *s = arg0;
    f32 delta = func_816092FC();
    f32 step;
    s->unk_E8FC = 0.0f;
    step = delta / 4;
    if (s->value + step < (f32)s->count) {
        s->value = s->value + step;
    } else {
        if ((f32)s->count < s->value - step) {
            s->value = s->value - step;
        } else {
            s->value = (f32)s->count;
            s->state = 2;
        }
    }
    return 1;
}
extern s32 func_81311C70();
extern u8 D_8131200C[];
extern void func_8130A8E0(void *arg0, s32 arg1);
s32 func_8130C0BC(void *arg0) {
    u8 *new_var;
    u8 *status = ((u8 *)arg0) + 0xE912;
    s32 result = func_81311C70(*(s32 *)((u8 *)arg0 + 0xE8EC) + 0x74, (void *)((u8 *)D_8131200C + *(u8 *)((u8 *)arg0 + 0xE914) * 0x24), *(u8 *)((u8 *)arg0 + 0xE910), -1);
    if (result != -1) { if (result == 1) *(u8 *)(new_var = status) = 2; }
    else { *status = 0xC; func_8130A8E0(arg0, 0); }
    return 1;
}

extern u8 D_81312054[];
extern u8 D_81311FA0[];
extern s32 func_8160A8DC(s32);
typedef struct { u8 bytes[0x24]; } C14CEntry;
typedef struct {
    u8 pad0[0xE8EC];
    u8 *object;
    u8 pad1[0x10];
    f32 value;
    u8 pad2[8];
    s32 counter;
    u8 selection;
    u8 pad3;
    u8 state;
    u8 mode;
    u8 index;
} C14CState;
extern void func_8130A8E0(void *arg0, s32 arg1);
extern s32 func_8130B1F4(u8 *arg0);
extern s32 func_81311C70();
s32 func_8130C14C(void *arg0) {
    s32 id;
    void *entry;
    s32 result;
    C14CState *p = arg0;

    id = func_8130B1F4((u8 *)p);
    if (p->mode == 0) {
        entry = D_81312054 + p->index * 0x24;
    } else {
        entry = D_81311FA0 + p->index * 0x24;
    }
    result = func_81311C70(p->object + 0x74, entry, p->selection, -1);
    switch (result) {
        case 2:
            p->value = 0.0f;
            p->state = 10;
            break;
        case 3:
            if (func_8160A8DC(id) > 0) {
                p->state = 12;
                p->counter = 0;
                func_8130A8E0(arg0, 0);
            }
            break;
        case 4:
            p->state = 6;
            break;
        case -1:
            p->state = 2;
            break;
    }
    return 1;
}

extern f32 func_816092FC(void);
extern void func_8130B12C(void *arg0);
s32 func_8130C270(void *arg0) {
    struct S { u8 pad0[0xE8F8]; f32 value; u8 gap0[0x16]; u8 state; u8 gap1[2]; u8 count; };
    struct S *s = arg0;
    f32 delta = func_816092FC();
    f32 step = delta / 8;
    if (s->value + step < (f32)s->count) {
        s->value = s->value + step;
    } else {
        if ((f32)s->count < s->value - step) {
            s->value = s->value - step;
        } else {
            s->value = (f32)s->count;
            s->state = 2;
        }
    }
    func_8130B12C(arg0);
    return 1;
}

/* mkdraft:func_8130C334 begin */
extern s32 *func_81602D70(u8);
extern s32 func_81602AEC(u8 *, s32 *);
extern void func_81600A34(void *, u8 *, s32, s16, s16, s16, s16);
extern s32 func_8160A50C(unk_D_8130B06C_node *);

// Draws the grid state at 0xE912: the state handler's return value is the
// "active" flag handed to the 0x1-stride panel, while the 0x0 panel is active
// for the three states 2, 3 and 5. The 0x6910 selector indexes the roster
// table at 0x1A144 of the object at 0xE8EC; a nonzero func_81602AEC comparison
// forces the active flag on.


void func_8130C334(u8 *arg0, void *arg1) {
    s16 rect1[4];
    s16 rect2[4];
    s32 i;
    s32 active;

    active = 0;
    switch (arg0[0xE912]) {
    case 0:
        active = func_8130B74C(arg0);
        break;
    case 1:
        active = func_8130B770(arg0);
        break;
    case 2:
        active = func_8130BADC(arg0);
        break;
    case 3:
        active = func_8130BFF0(arg0);
        break;
    case 4:
        active = func_8130C14C(arg0);
        break;
    case 11:
        active = func_8130C0BC(arg0);
        break;
    case 5:
        active = func_8130C270(arg0);
        break;
    case 12:
        active = func_8130BD2C(arg0);
        break;
    case 6:
        active = func_8130B7F8(arg0);
        break;
    case 8:
        active = func_8130B88C(arg0);
        break;
    case 7:
        active = func_8130BC44(arg0);
        break;
    case 10:
        active = func_8130BDB8(arg0);
        break;
    case 9:
        active = func_8130BF1C(arg0);
        break;
    case 13:
        active = func_8130BFCC(arg0);
        break;
    }
    if (func_81602AEC((u8 *)(*(s32 *)(arg0 + 0xE8EC)) + 0x1A144, func_81602D70(arg0[0xE910])) != 0) {
        active = 1;
    }
    // The three unk_0008 nodes; IDO strength-reduces this to a pointer walked
    // by 0x4DA0 and a byte counter compared against 0xE8E0 (3 * 0x4DA0).
    for (i = 0; i < 3; i++) {
        func_8160A50C(&((unk_func_8130B06C *)arg0)->unk_0008[i]);
    }
    func_8130B3B8(arg0, rect1);
    func_81600A34(arg1, arg0,
                  arg0[0xE912] == 5 || arg0[0xE912] == 2 || arg0[0xE912] == 3,
                  rect1[0], rect1[1], rect1[2], rect1[3]);
    func_8130B4E8(arg0, rect2);
    func_81600A34(arg1, arg0 + 1, active, rect2[0], rect2[1], rect2[2], rect2[3]);
}
/* mkdraft:func_8130C334 end */

/* mkdraft:func_8130C570 begin */
extern f32 __sinf(f32);
extern void func_800495BC(s32 arg0, s32 arg1, const char *arg2, ...);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern s32 func_8004C54C(s32 index, s32 value);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern void *func_8004C8A0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_816048E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern void func_816054D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_816054FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_816073A0(void *arg0);
extern void func_81607408(void);
extern void func_81607440(s32, s32, s32, s32, f32, s32, s32);
extern s32 D_813120A0;
extern s32 D_813120A4;
extern const u8 D_81312640[8];



void func_8130C570(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, void *arg5) {
    u8 buf[0x80];
    u16 unk56;
    u8 pad56[6]; // FAKE: unreferenced; without it color[] lands at 0x50 and phase at 0x4C instead of 0x4C and 0x48 (diff score 32).
    u8 color[4];
    f32 phase;
    f32 var_fs0;

    unk56 = 0x55;
    if (arg2 > 0.0f) {
        var_fs0 = (1.0f - arg2) * 30.0f;
    } else {
        var_fs0 = 30.0f * arg1;
    }
    phase = (__sinf(((f32) D_813120A4 * 6.2831855f) / (f32) D_813120A0) * 0.5f) + 0.5f;
    // FAKE: stores D_813120A4 through the address of the word before it (D_813120A0 + 4 is
    // D_813120A4). Two spellings of that address stop IDO from folding the load and the store
    // into one register: the target materializes the load as lui t9/lw t9 and the store as
    // lui at/sw. With D_813120A4 on both sides the address is hoisted once (diff score 765).
    // The call is the left operand because IDO emits add.s operands in reverse of source
    // order, which yields the target's add.s $f16,$f8,$f0: the converted load first, the
    // call result second.
    *(s32 *) ((u8 *) &D_813120A0 + 4) = (s32) (func_816092FC() + (f32) *(s32 *) &D_813120A4);
    color[0] = (u8) (((f32) (D_81312640[0] - D_81312640[3]) * phase) + (f32) D_81312640[3]);
    color[1] = (u8) (((f32) (D_81312640[1] - D_81312640[4]) * phase) + (f32) D_81312640[4]);
    color[2] = (u8) (((f32) (D_81312640[2] - D_81312640[5]) * phase) + (f32) D_81312640[5]);
    switch (arg4) {
    case 0:
        unk56 = 0x56;
        break;
    case 1:
        unk56 = 0x4C;
        break;
    case 2:
        break;
    }
    func_816048E0(*(s16 *) ((u8 *) arg0 + 0), *(s16 *) ((u8 *) arg0 + 2), *(s16 *) ((u8 *) arg0 + 4), *(s16 *) ((u8 *) arg0 + 6), 0.0f);
    if (arg1 > 0.99f) {
        func_81607440(*(s16 *) ((u8 *) arg0 + 0) + 7, (s32) ((f32) (*(s16 *) ((u8 *) arg0 + 2) + 7) + var_fs0), (s32) (19.0f * arg1), (s32) (((f32) *(s16 *) ((u8 *) arg0 + 6) - var_fs0) - 17.0f), arg3, 1, 1);
    } else {
        func_816054D8(*(s16 *) ((u8 *) arg0 + 0) + 7, (s32) ((f32) (*(s16 *) ((u8 *) arg0 + 2) + 7) + var_fs0), (s32) (19.0f * arg1), (s32) (((f32) *(s16 *) ((u8 *) arg0 + 6) - var_fs0) - 17.0f));
    }
    func_816073A0(arg0);
    func_816054FC(*(s16 *) ((u8 *) arg0 + 0) + 7, *(s16 *) ((u8 *) arg0 + 2) + 7, *(s16 *) ((u8 *) arg0 + 4) - 0x11, (s32) var_fs0);
    if (var_fs0 > 3.0f) {
        func_8004C54C(0x14, func_8004C874(0xF, *(s16 *) ((u8 *) arg5 + 0x3E)));
        func_800498C4();
        func_800496A4(4, 1);
        func_800495F8((*(s16 *) ((u8 *) arg0 + 4) + *(s16 *) ((u8 *) arg0 + 0)) - 0x18, (s32) (((f32) (*(s16 *) ((u8 *) arg0 + 2) + 0xE) - 30.0f) + var_fs0), 2, func_8004C8A0(buf, 0x80, 0xF, 0x4D));
        func_8004972C(color[0], color[1], color[2], (s32) (255.0f * arg1));
        func_800495BC(*(s16 *) ((u8 *) arg0 + 0) + 0x14, (s32) (((f32) (*(s16 *) ((u8 *) arg0 + 2) + 0xE) - 30.0f) + var_fs0), func_8004C874(0xF, unk56));
        func_800499EC();
    }
    func_81607408();
}
/* mkdraft:func_8130C570 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_1025F0/func_8130CB5C.s")

s32 func_8130CDD4(void *arg0) {
    u8 *base = (u8 *)arg0 + 0x8000;
    s32 result;
    if (base[0x6912] != 13) {
        return 0;
    }
    if (*(s32 *)(base + 0x690C) != 0) {
        result = -1;
    } else {
        result = base[0x6914] + base[0x6911] + 1;
    }
    return result;
}
#endif
