#include "global.h"


#ifdef VERSION_US
extern void Util_Free(s32);
extern void func_888002DC(void);
extern void main_pool_pop_state(s32);
extern void func_8821CE40(s32);
extern s32 D_88234560;
extern s32 D_88234564;

typedef struct {
    u8 unk_00[0x10];
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x18];
} unk_D_88234700_Record;

typedef struct {
    u8 index; // selects the entry of records read by func_88208FF0
    u8 unk_01[7];
    unk_D_88234700_Record records[2];
} unk_D_88234700;

extern unk_D_88234700 *D_88234700;

void func_88207ED0(void) {
    Util_Free(D_88234564);
    func_888002DC();
    main_pool_pop_state(0x4152524D);
    func_8821CE40(1);
    D_88234560 = 5;
}

extern u8 *func_88201ED0(u8, u8);

// Table of entries belonging to the record func_88201ED0 returns: the pointer at
// +0x10 is the array base and the switch below picks its halfword index.
// The same entry layout is spelled out in func_88201F0C (pad[0x10]; void **entries;
// count at 0x15). //@src/fragments/31/fragment31_174460.c
s32 func_88207F18(s32 kind, u8 slot) {
    s16 index;
    void **entries;

    // Header bytes of the slot pair: the two bytes func_88208010 also hands to
    // func_88201ED0. //@src/fragments/31/fragment31_17B150.c
    entries = *(void ***)((u8 *)func_88201ED0(((u8 *)D_88234700)[slot * 2 + 0xA],
                                                ((u8 *)D_88234700)[slot * 2 + 0xB]) + 0x10);
    // Only kinds 0..3 assign index; retail has no default arm, so any other kind
    // indexes the table with the uninitialized halfword. //!bug
    switch (kind) {
    case 0:
        // unk_12 of the slot's record; func_88208FF0 forms delta = unk_10 - unk_12.
        index = D_88234700->records[slot].unk_12;
        break;
    case 1:
        index = D_88234700->records[slot].unk_10;
        break;
    case 2:
        index = 0;
        break;
    case 3:
        // Halfword at 0x74 of D_88234700, independent of slot.
        index = *(s16 *)((u8 *)D_88234700 + 0x74);
        break;
    }
    return (s32)entries[index];
}

extern u8 *func_88201ED0(u8, u8);
extern s32 func_80001FF0(void);
extern void func_88001C6C(void *, u16, u8, s16, u8, s16, s16, s16, s16, s16, s32);
void func_88208010(u8 arg0, u8 arg1, u8 arg2) {
    s16 color;

    if (*(s32 *)((u8 *)D_88234700 + 4) != 0) {
        color = 0xC;
    } else {
        color = 0xF0C;
    }
    ((u8 *)D_88234700)[arg0 * 2 + 0xA] = arg1;
    ((u8 *)D_88234700)[arg0 * 2 + 0xB] = arg2;
    func_88001C6C(D_88234700->records[arg0].unk_00 + 8, func_88201ED0(((u8 *)D_88234700)[arg0 * 2 + 0xA], ((u8 *)D_88234700)[arg0 * 2 + 0xB])[0x15], 6, 0x7D, 27, 14,
                  (s32)(600.0f / func_80001FF0() + ((600.0f / func_80001FF0() > 0.0f) ? 0.5f : -0.5f)),
                  32, 32, color, 70);
}

extern unk_D_88234700 *D_88234700;
extern s32 main_pool_push_state(s32);
extern void func_88800020(void);
extern s32 mem_pool_try_init(s32, s32);
extern void *mem_pool_alloc(void *, s32);
extern s32 func_8004C4B0(s32);
extern void func_882011E0(void *);
extern void func_88A00D0C(void *);
extern void func_88203744(void *);
extern void func_88208010(u8, u8, u8);
extern void Input_SetRepeatController(s32);
extern s32 D_80087200;
extern s32 D_882346F0;
extern s32 D_880068B8;
extern s32 D_880068B4;
extern s32 func_8004C874(s32, s32);
extern s32 func_80049148(s32, s32, const char *, ...);
extern s32 func_80049290(s32, s32, const char *);
extern s32 func_80001FF0(void);
extern void func_88207ED0(void);
extern void func_88000288(void *, s16, s16, s16, u8, u8, u8, u8);
extern void func_88005B60(s32, void (*)(void), void (*)(void), void (*)(void));
extern void D_88000E4C(void);
extern void func_88205EB0(s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, u8, u8, void (*)(void));

#define RAND_OFFSET(k) ((f32)(k) * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)(k) / 60.0f > 0.0f) ? 0.5f : -0.5f))



void func_88208174(void) {
    u32 i;
    s32 pool;

    main_pool_push_state(0x4152524D);
    func_88800020();
    pool = mem_pool_try_init(0x20000, 0);
    D_88234700 = mem_pool_alloc((void *)pool, 0x19A0);
    func_8004C4B0(0x20);
    func_882011E0((void *)pool);
    func_88A00D0C((void *)pool);
    func_88203744((void *)pool);
    ((u8 *)D_88234700)[0] = 0;
    *(s32 *)((u8 *)D_88234700 + 4) = 1;
    *(s16 *)((u8 *)D_88234700 + 8) = 0;
    ((u8 *)D_88234700)[0x68] = 0;
    ((u8 *)D_88234700)[0x1988] = 0;
    *(s32 *)((u8 *)D_88234700 + 0x198C) = 0;
    for (i = 0; i != 2; i++) {
        func_88208010(i, i, 0);
        *(s32 *)((u8 *)D_88234700 + i * 4 + 0x6C) = 0;
    }
    Input_SetRepeatController(D_80087200);
    D_882346F0 = 0;
    D_880068B4 = D_880068B8 = 1;
    func_88205EB0(44, 319, 553, 130, 63, 72, 213, 242, 68, 105,
        203, 201, 360, 72, 213, 242, 365, 105, 203, 201,
        71, 108, 197, 17, 71, 286, 197, 17, 368, 108,
        197, 17, 368, 286, 197, 17, 289, 72, 63, 38,
        71, 125, 197, 26, 368, 125, 197, 26, 244, 79,
        370, 79, 80, 112, 249, 112, 379, 112, 548, 112,
        144, 112, 162, 112, 162, 290, 182, 290, 443, 112,
        461, 112, 461, 290, 481, 290, 6, 34, func_88207ED0);
    *(s32 *)((u8 *)D_88234700 + 0x1990) = func_8004C874(0xD, 0x15);
    ((u8 *)D_88234700)[0x1994] = func_80049148(4, 1, "%s%d", *(s32 *)((u8 *)D_88234700 + 0x1990), 9);
    ((u8 *)D_88234700)[0x1995] = func_80049148(4, 1, "%s%d", *(s32 *)((u8 *)D_88234700 + 0x1990), 0x63);
    ((u8 *)D_88234700)[0x1996] = func_80049148(4, 1, "%s%d", *(s32 *)((u8 *)D_88234700 + 0x1990), 0x64);
    ((u8 *)D_88234700)[0x1997] = func_80049290(4, 1, "9");
    ((u8 *)D_88234700)[0x1998] = func_80049290(4, 1, "99");
    ((u8 *)D_88234700)[0x1999] = func_80049290(4, 1, "999");
    func_88000288((u8 *)D_88234700 + 0x76,
                  (s16)((s32)RAND_OFFSET(5) + (s32)RAND_OFFSET(8) + (s32)RAND_OFFSET(30)), 0xFF, 0,
                  (s32)RAND_OFFSET(5), (s32)RAND_OFFSET(8), (s32)RAND_OFFSET(30), (s32)RAND_OFFSET(8));
    func_88005B60(0, D_88000E4C, D_88000E4C, D_88000E4C);
}

extern void func_88001C24(void *, u16, u8);
extern void func_88001D0C(void *);

// Apply a changed slot state to its existing scroll control.
void func_882089E4(u8 arg0, s32 arg1) {
    u8 *control;
    u32 slot = arg0;

    if (arg1 != *(s32 *)((u8 *)D_88234700 + slot * 4 + 108)) {
        control = (u8 *)D_88234700 + slot * 44 + 16;
        *(s32 *)((u8 *)D_88234700 + slot * 4 + 108) = arg1;
        if (arg1 != 0) {
            if (func_88201ED0(((u8 *)D_88234700)[slot * 2 + 10],
                              ((u8 *)D_88234700)[slot * 2 + 11])[21] != 0) {
                func_88001C24(control, *(u16 *)(control + 12) + 1, 6);
                if (*(s16 *)(control + 8) - *(s16 *)(control + 10) == 5) {
                    (*(s16 *)(control + 10))++;
                } else {
                    *(s16 *)(control + 16) += control[15];
                }
            }
        } else {
            if (func_88201ED0(((u8 *)D_88234700)[slot * 2 + 10],
                              ((u8 *)D_88234700)[slot * 2 + 11])[21] != 0) {
                func_88001C24(control, *(u16 *)(control + 12) - 1, 6);
                if (*(s16 *)(control + 8) - *(s16 *)(control + 10) == 5) {
                    (*(s16 *)(control + 10))--;
                } else {
                    *(s16 *)(control + 16) -= control[15];
                }
            }
        }
        func_88001D0C(control);
    }
}



extern s32 func_80063754();
extern s32 func_8800005C();
extern s32 func_880007B0();
extern s32 func_88201F7C();
extern s32 func_88203FB4();
extern s32 func_88207F18(s32, u8);
extern s32 D_882346F0;
extern unk_D_88234700 *D_88234700;



s32 func_88208B38(u8 *arg0) {
    s32 result;
    u8 slot_a;
    u8 slot_b;
    s32 flag;
    s32 same;
    UNUSED u8 pad; // FAKE: unused local; its declaration widens the frame by 8 bytes, placing arg0 and every later slot at retail offsets
    s32 p;
    s32 other;
    s32 e;

    slot_a = ((u8 *)D_88234700 + D_88234700->index * 2)[0xA];
    slot_b = ((u8 *)D_88234700 + (D_88234700->index << 1) * -1)[0xC];

    result = 0;
    flag = func_8800005C();
    p = (s32)(arg0 + 8);
    same = func_88201F7C((void *)p);
    if (*(s32 *)((u8 *)D_88234700 + 4) == 0) {
        if ((D_882346F0 == 0) && (*(s16 *)((u8 *)D_88234700 + 8) == 2)) {
            if ((slot_a == 2) && (slot_b != 2) && (flag != 0) && (func_880007B0((u8 *)p) == 0)) {
                result = 1;
            } else {
                e = func_80063754(arg0[9]);
                if ((flag == 0) && (e != 0) && (slot_b == 1)) {
                    result = 3;
                } else if ((flag != 0) && (e != 0) && (slot_b != 2)) {
                    result = 2;
                } else if ((same == 0) && (((slot_a == 2) && (slot_b != 2)) || ((slot_a != 2) && (slot_b == 2)))) {
                    result = 4;
                } else if ((flag == 0) && (e != 0) && (slot_b == 2) && (slot_a != 2)) {
                    if (func_88203FB4() == 0) {
                        result = 5;
                    }
                }
            }
        } else if ((D_882346F0 == 0) && (*(s16 *)((u8 *)D_88234700 + 8) == 4)) {
            if ((slot_a == 2) && (slot_b != 2) && (flag != 0) && (func_880007B0((u8 *)p) == 0)) {
                result = 1;
            } else {
                e = func_80063754(arg0[9]);
                if ((flag == 0) && (e != 0) && (slot_b == 1)) {
                    result = 3;
                } else if ((flag != 0) && (e != 0) && (slot_b != 2)) {
                    result = 2;
                } else if ((same == 0) && (((slot_a == 2) && (slot_b != 2)) || ((slot_a != 2) && (slot_b == 2)))) {
                    result = 4;
                }
            }
        } else if ((D_882346F0 == 0) && (*(s16 *)((u8 *)D_88234700 + 8) == 5)) {
            if (func_80063754(arg0[9]) != 0) {
                if (flag != 0) {
                    result = 2;
                } else {
                    result = 3;
                }
            }
        } else if (D_882346F0 == 3) {
            if ((slot_a == 2) && (slot_b != 2) && (flag != 0) && (func_880007B0((u8 *)p) == 0)) {
                result = 1;
            } else {
                other = func_80063754(((u8 *)func_88207F18(1, (1 - D_88234700->index) & 0xFF))[9]);
                e = func_80063754(arg0[9]);
                if ((flag == 0) && (e != 0) && (slot_b == 1)) {
                    result = 3;
                } else if ((flag != 0) && (e != 0) && (slot_b != 2)) {
                    result = 2;
                } else if ((same == 0) && (((slot_a == 2) && (slot_b != 2)) || ((slot_a != 2) && (slot_b == 2)))) {
                    result = 4;
                } else if (flag == 0) {
                                        if ((func_88203FB4() == 0) && (((slot_b == 2) && (slot_a != 2) && (other == 0) && (e == 1)) || ((slot_b != 2) && (slot_a == 2) && (other == 1) && (e == 0)))) {
                        result = 5;
                    }
                }
            }
        }
    }
    return result;
}

// 8-byte record allocated by func_88208FF0 and published through D_8800EF54.
typedef struct {
    s32 unk_00; // func_88207F18(1, index) result
    s8 delta;   // records[index].unk_10 - records[index].unk_12
    u8 index;
} unk_func_88208FF0;

extern void *Util_Malloc(s32);
extern void func_800226C0(s32);
extern s32 func_88207F18(s32, u8);
extern void func_882322B8(void);
extern void *D_8800EF54;
void func_88208FF0(void) {
    unk_func_88208FF0 *record;

    record = Util_Malloc(sizeof(unk_func_88208FF0));
    record->unk_00 = func_88207F18(1, D_88234700->index);
    record->delta = D_88234700->records[D_88234700->index].unk_10 - D_88234700->records[D_88234700->index].unk_12;
    record->index = D_88234700->index;
    D_8800EF54 = record;
    func_800226C0(99);
    func_882322B8();
}

/* mkdraft:func_8820908C begin */
extern u8 *func_88201ED0(u8, u8);
extern s32 func_88207F18(s32, u8);
extern void func_800226C0(s32);
extern void func_88001900(void);
extern void func_88201608(s32);
extern void func_882017F8(s32, u8 *, s8);
extern void func_88220AD0(s32, s32);
extern s32 D_88234660;
extern s32 D_882346F0;

// Per-round update of the two-slot state in D_88234700; the s16 at +8 selects the
// branch. Case 2 runs the state-2-only setup (actor from func_88207F18 for the
// other slot, per-slot word clear, index flip) and falls into the shared record
// refresh; case 5 reaches the same refresh after refreshing the actor only; case 4
// just flips the active slot.


void func_8820908C(void) {
    u8 *pair;
    s32 obj; // func_88207F18 result; func_882017F8 dereferences it as a pointer

    if (*(s16 *)((u8 *)D_88234700 + 8) == 5) {
        func_800226C0(0x136);
    } else {
        func_800226C0(0x5E);
    }
    func_88001900();
    D_882346F0 = 0;
    // Read a second time instead of caching the first load in a local: no store to
    // D_88234700 lies between the two reads of +8, so both see the same value.
    switch (*(s16 *)((u8 *)D_88234700 + 8)) {
        case 2:
        case 5:
            if (*(s16 *)((u8 *)D_88234700 + 8) == 2) {
                obj = func_88207F18(1, (1 - D_88234700->index) & 0xFF);
                pair = (u8 *)D_88234700 + D_88234700->index * 2;
                func_882017F8(obj, func_88201ED0(pair[0xA], pair[0xB]),
                              *(s8 *)((u8 *)D_88234700 + D_88234700->index * 0x2C + 0x19));
                // Per-index word at +0x6C, also read by func_8820B09C.
                *(s32 *)((u8 *)D_88234700 + D_88234700->index * 4 + 0x6C) = 0;
                D_88234700->index ^= 1;
            } else {
                func_88201608(func_88207F18(1, D_88234700->index));
            }
            pair = (u8 *)D_88234700 + D_88234700->index * 2;
            func_88001C24((u8 *)D_88234700 + D_88234700->index * 0x2C + 0x10,
                          func_88201ED0(pair[0xA], pair[0xB])[0x15], 6);
            func_88001D0C((u8 *)D_88234700 + D_88234700->index * 0x2C + 0x10);
            break;

        case 4:
            D_88234700->index ^= 1;
            break;
    }
    if (D_88234660 != 0) {
        *((u8 *)D_88234700 + 0x68) = 2;
        func_88220AD0(0x140, 0xF0);
    }
}
/* mkdraft:func_8820908C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88209278.s")

/* mkdraft:func_8820A56C begin */
extern s32 D_882346F0;
extern unk_D_88234700 *D_88234700;

// Mode-dependent test of whether arg1 matches the progress recorded for slot
// arg0. Modes 1 and 3 use records[arg0].unk_10 minus unk_12 and apply to slots
// other than the selected index; mode 2 uses the halfword at 0x74 minus unk_12
// and applies to the selected index. func_88209278 compares that same 0x74
// halfword against records[index].unk_10.


s32 func_8820A56C(u8 arg0, u8 arg1) {
    u32 index = arg0;
    unk_D_88234700 *state;
    s32 result = 0;

    switch (D_882346F0) {
    default:
        break;
    case 0:
        break;
    case 1:
    case 3:
        state = D_88234700;
        if (arg0 == state->index) {
            break;
        }
        if (arg1 == state->records[index].unk_10 - state->records[index].unk_12) {
            result = 1;
        }
        break;
    case 2:
        state = D_88234700;
        if (arg0 != state->index) {
            break;
        }
        if ((s16)arg1 == *(s16 *)((u8 *)state + 0x74) - state->records[index].unk_12) {
            result = 1;
        }
        break;
    }
    return result;
}
/* mkdraft:func_8820A56C end */

extern u8 *func_88201ED0(u8, u8);
extern s32 func_88208B38(u8 *);
extern Gfx *D_800D0510;
extern s32 D_882346F0;
extern unk_D_88234700 *D_88234700;



void func_8820A638(u8 arg0, u8 arg1)
{
  s16 x;
  s16 y;
  s16 top;
  s16 bottom;
  u32 row;
  void **entry;
  entry = &(*((void ***) (func_88201ED0(((u8 *) D_88234700)[(((u32) arg0) * 2) + 0xA], ((u8 *) D_88234700)[(((u32) arg0) * 2) + 0xB]) + 0x10)))[D_88234700->records[arg0].unk_12];
  x = (!arg0) ? (0x47) : (0x170);
  // FAKE: dead assignment. Its only effect is the comparison temporary: CSE creates a
  // stack temp for (arg0 != 0) before arg1's narrowed u8 temp, which moves that temp
  // to the 0x50 slot reloaded at the loop back-edge. The loop overwrites top before
  // the value could be read.
  top = (arg0 != 0);
  y = 0x7D - (*((s16 *) (D_88234700->records[arg0].unk_14 + 0x16)));
  for (row = 0; row != arg1; row++, y += 0x1B)
  {
    top = y;
    bottom = y + 0x19;
    if (row == 0)
    {
      if (top < 0x7D)
      {
        top = 0x7D;
      }
    }
    else
      if (row == 6)
    {
      if (bottom >= 0x11E)
      {
        bottom = 0x11D;
      }
    }
    gDPPipeSync(D_800D0510++);
    if ((func_88201ED0(((u8 *) D_88234700)[(((u32) arg0) * 2) + 0xA], ((u8 *) D_88234700)[(((u32) arg0) * 2) + 0xB])[0x15] == 0) || (row >= (*((u16 *) D_88234700->records[arg0].unk_14))))
    {
      gDPSetFillColor(D_800D0510++, 0x39CF39CF);
    }
    else
      if (func_8820A56C(arg0, row) != 0)
    {
      if (((D_882346F0 == 1) || (D_882346F0 == 3)) || (D_88234700->index == arg0))
      {
        gDPSetFillColor(D_800D0510++, 0x2AFF2AFF);
      }
      else
      {
        gDPSetFillColor(D_800D0510++, 0x39D739D7);
      }
    }
    else
      if (((D_882346F0 == 1) || (D_882346F0 == 3)) || (D_88234700->index == arg0))
    {
      if ((((*((s32 *) ((((u8 *) D_88234700) + (arg0 * 4)) + 0x6C))) == 0) && (func_88208B38(*entry) != 0)) && (arg0 == D_88234700->index))
      {
        gDPSetFillColor(D_800D0510++, 0x50075007);
      }
      else
      {
        gDPSetFillColor(D_800D0510++, 0x09A909A9);
      }
    }
    else
    {
      gDPSetFillColor(D_800D0510++, 0x39CF39CF);
    }
    gDPFillRectangle(D_800D0510++, x, top, x + 0xC4, bottom);
    bottom++;
    if (bottom < 0x11E)
    {
      gDPPipeSync(D_800D0510++);
      if (((D_882346F0 == 1) || (D_882346F0 == 3)) || (D_88234700->index == arg0))
      {
        gDPSetFillColor(D_800D0510++, 0x7D3F7D3F);
      }
      else
      {
        gDPSetFillColor(D_800D0510++, 0x63196319);
      }
      gDPFillRectangle(D_800D0510++, x, bottom, x + 0xC4, bottom);
    }
    if (!(((*((s32 *) ((((u8 *) D_88234700) + (arg0 * 4)) + 0x6C))) != 0) && (((row == (D_88234700->records[arg0].unk_10 - D_88234700->records[arg0].unk_12))) ? 1 : 0)))
    {
      entry++;
    }
  }
}

extern s32 D_8800687C;
extern s32 func_80048E30();
extern void func_80049628(s32 arg0, s32 arg1, s32 arg2);
extern void func_88000488(s32 *arg0, s32 arg1);
extern s32 func_880007B0(u8 *arg0);
extern void func_88000EC0(s8 *arg0, s16 arg1, s32 arg2);
extern void func_80049064(s32, s32, s32, s32);
extern void func_800496A4(s32, s32);
s32 func_8004C874(s32, s32);

// Byte view of D_88234700 for this function; the repo file already declares the
// symbol with its field layout.
extern unk_D_88234700 *D_88234700;



void func_8820AAD0(s16 arg0, s16 arg1, u8 *arg2) {
    s8 buffer[8]; // FAKE: func_88000EC0 writes only buffer[0..2]; the 8-byte object puts it at sp+0x50, a 3- or 4-byte declaration at sp+0x54, diff score 10.
    s32 i;

    if (func_880007B0(arg2) == 0) {
        func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 1);
    } else {
        func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 0);
    }

    func_800496A4(8, 2);
    func_80048E30(D_8800687C, arg0, arg1, arg2 + 0x34, 1);

    if (arg2[0x1E] & 1) {
        return;
    }

    func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 0);
    func_800496A4(4, 1);

    if (arg2[0] == 0xFC) {
        func_80049064(arg0 + 0xB9, arg1 + 4, 2, func_8004C874(0x20, 0x19));
    } else {
        s32 x;
        s32 y;

        x = arg0 + 0xB9;
        y = arg1 + 4;
        func_88000EC0(buffer, arg2[0x1D], 0);

        for (i = 2; i >= 0; i--) {
            if (buffer[i] >= 0) {
                func_80049628(x - *(u8 *)((u8 *)D_88234700 + i + 0x1997), y, buffer[i] + 0x30);
            }
        }

        if (arg2[0x1D] >= 0x64) {
            x -= *(u8 *)((u8 *)D_88234700 + 0x1996);
            x--;
        } else if (arg2[0x1D] >= 0xA) {
            x -= *(u8 *)((u8 *)D_88234700 + 0x1995);
            x--;
        } else {
            x -= *(u8 *)((u8 *)D_88234700 + 0x1994);
            x--;
        }

        func_80048E30(D_8800687C, x, y, *(s32 *)((u8 *)D_88234700 + 0x1990), 1);
    }
}




extern unk_D_88234700 *D_88234700;
extern u8 *func_88201ED0(u8, u8);
extern s32 func_88208B38(u8 *);
extern s32 func_88005CC0(s32, void *);
extern s32 D_882346F0;

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
} Color8820ACD0;
extern void func_880006E0(void *);
extern void *Color_SetRGB(void *, s32, s32, s32);
extern void func_8820AAD0(s16, s16, u8 *);
extern u8 D_88005FA0[];



void func_8820ACD0(u8 slot, u8 limit) {
    s32 row;
    s16 color;
    s16 y;
    u8 selected;

    if (!(func_88201ED0(((u8 *)D_88234700)[((u32)slot) * 2 + 0xA], ((u8 *)D_88234700)[((u32)slot) * 2 + 0xB])[0x15] == 0)) {
        {
            Color8820ACD0 gray;
            u8 **entry;

            entry = (u8 **)(*(u32 *)(func_88201ED0(((u8 *)D_88234700)[((u32)slot) * 2 + 0xA], ((u8 *)D_88234700)[((u32)slot) * 2 + 0xB]) + 0x10) + D_88234700->records[slot].unk_12 * 4);
            color = slot == 0 ? 0x4D : 0x176;
            {
                u16 available = *(u16 *)D_88234700->records[slot].unk_14;
                limit = limit + 1 <= available ? limit : available;
            }
            for (row = 0, y = 0x80 - *(s16 *)(D_88234700->records[slot].unk_14 + 0x16); row != limit; row++, y += 0x1B) {
                if (((s32 *)((u8 *)D_88234700 + 0x6C))[slot] != 0) {
                    selected = row == (D_88234700->records[slot].unk_10 - D_88234700->records[slot].unk_12) ? 1 : 0;
                    if (selected != 0) {
                        continue;
                    }
                }
                if (D_882346F0 == 1 || D_882346F0 == 3 || D_88234700->index == slot) {
                    if (func_88208B38(*entry) != 0 && slot == D_88234700->index) {
                        func_880006E0(Color_SetRGB(&gray, 150, 150, 150));
                    } else {
                        func_880006E0(D_88005FA0);
                    }
                } else {
                    func_880006E0(Color_SetRGB(&gray, 150, 150, 150));
                }
                if (func_88005CC0(6, *entry) == 0 && func_88005CC0(7, *entry) == 0 &&
                    func_88005CC0(8, *entry) == 0 && func_88005CC0(9, *entry) == 0) {
                    func_8820AAD0(color, y, *entry + 8);
                }
                entry++;
            }
        }
    }
}

extern u8 *func_88201ED0(u8, u8);
extern void func_8004D5B8(s32, s32, s32, const char *, ...);
void func_8820AF54(void) {
    s32 i;
    u8 *entry;
    u8 *first;
    u8 *second;
    s16 x;

    for (i = 0, x = 262; i != 4; i += 2, x += 297) {
        entry = (u8 *)D_88234700 + i;
        first = func_88201ED0(entry[10], entry[11]);
        entry = (u8 *)D_88234700 + i;
        second = func_88201ED0(entry[10], entry[11]);
        func_8004D5B8(x, 287, 2, "%d/%d", first[0x15], second[0x14]);
    }
}

extern void func_80049064(s32, s32, s32, s32);
extern void func_800496A4(s32, s32);
s32 func_8004C874(s32, s32);
extern unk_D_88234700 *D_88234700;

void func_8820B020(void) {
    func_800496A4(4, 2);
    func_80049064(0x140, 0x198, 1, func_8004C874(0x20, 7));
    func_800496A4(0x10, 2);
    func_80049064(0x140, 0x15F, 1, func_8004C874(0x20, (*(s16 *)((u8 *)(D_88234700) + (8))) + 1));
}

extern s16 D_8800EF58;
extern u8 *func_88201ED0(u8, u8);
s32 func_8820B09C(void) {
    s32 result = 0;
    u8 *entry;

    if ((*(s32 *)((u8 *)D_88234700 + 4) == 0) && (D_8800EF58 == 0) &&
        (*(s32 *)((u8 *)D_88234700 + D_88234700->index * 4 + 0x6C) == 0)) {
        entry = func_88201ED0(((u8 *)D_88234700)[D_88234700->index * 2 + 0xA], ((u8 *)D_88234700)[D_88234700->index * 2 + 0xB]);
        if (entry[0x15] != 0) {
            result = 1;
        }
    }
    return result;
}

extern s32 D_8800687C;
extern u8 D_88005FA0[];
extern s32 func_80049290(s32, s32, const char *);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_80049628(s32, s32, s32);
extern s32 func_80049668(s32);
extern s32 *func_80062CE0(u8);
extern u8 func_80062D98(u8);
extern s32 func_80063270(u8);
extern s32 *func_800635E0(u8);
extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern void func_88000488(s32 *, s32);
extern void *func_88000510(void *, s8);
extern void func_880006E0(void *);
extern s32 func_880007B0(u8 *);
extern void func_88000EC0(s8 *, s16, s32);



void func_8820B124(void) {
    u8 *record;
    u8 *entry;
    s32 y;
    s8 genders[2];
    s32 i;
    u8 color[3];
    s16 value;
    s8 digits[4];
    s32 j;
    s32 tmp;

    record = (u8 *)(func_88207F18(1, D_88234700->index) + 8);
    func_800496A4(8, 2);
    if (func_880007B0(record) == 0) {
        func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 1);
    } else {
        func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 0);
    }
    func_80049064(0x6E, 0x14F, 1, (s32)(record + 0x34));
    i = 0;
    y = 0x14F;
    if (!(record[0x1E] & 1)) {
        for (entry = record; i < 4; i++, entry++, y += 0x19) {
            if (entry[2] == 0) {
                i = 0;
                break;
            }
            if (entry[2] >= 0xA6) {
                func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 1);
            } else {
                func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 0);
            }
            func_880006E0(func_88000510(color, entry[2] == 0xFC ? 0 : func_80062D98(entry[2])));
            func_80048E30((u8 *)D_8800687C, 0x130, y,
                entry[2] == 0xFC ? (const char *)func_8004C874(0x20, 0x17) : (const char *)func_80062CE0(entry[2]), 1);
        }
        i = 0;
        func_88000488((s32 *)((u8 *)D_88234700 + 0x84), 0);
        func_880006E0(D_88005FA0);
        if (record[0] == 0xFC) {
            func_80049064(0xE6, 0x14F, 2, func_8004C874(0x20, 0x18));
        } else {
            func_800495F8(0xE6, 0x14F, 2, "%d", *(u16 *)(record + 0x28));
        }
        func_800496A4(4, 2);
        func_80048E30((u8 *)D_8800687C, 0xAE, 0x153, (const char *)func_8004C874(0x20, 0x13), 1);
        if (record[0] == 0xFC) {
            func_800495F8(0x8E, 0x16F, 0, "%s%s", func_8004C874(0x20, 0x14), func_8004C874(0xC, 9));
            y = 0x14F;
        } else {
            genders[0] = func_8006397C(record[0]);
            genders[1] = func_800639C0(record[0]);
            y = 0x16F;
            for (i = 0; i != 2; i++, y += 0x14) {
                if (i == 1 && genders[0] == genders[1]) {
                    i = 0;
                    y = 0x14F;
                    goto nxt;
                }
                tmp = func_8004C874(0x20, i + 0x14);
                func_880006E0(D_88005FA0);
                func_80048E30((u8 *)D_8800687C, 0x8E, y, (const char *)tmp, 1);
                func_880006E0(func_88000510(color, (s8)genders[i]));
                func_80048E30((u8 *)D_8800687C,
                    *(s8 *)((u8 *)D_8800687C + 0x78) +
                        func_80049290(0, *(s8 *)((u8 *)D_8800687C + 0x78), (const char *)tmp) + 0x8E, y,
                    (const char *)func_80063270(genders[i]), 1);
            }
            i = 0;
            y = 0x14F;
        nxt: ;
        }
        func_880006E0(D_88005FA0);
        tmp = func_8004C874(0x20, 0x16);
        func_80048E30((u8 *)D_8800687C, 0x4E, 0x19E, (const char *)tmp, 1);
        func_80048E30((u8 *)D_8800687C,
            *(s8 *)((u8 *)D_8800687C + 0x78) +
                func_80049290(0, *(s8 *)((u8 *)D_8800687C + 0x78), (const char *)tmp) + 0x4E, 0x19E,
            (const char *)func_800635E0(record[1]), 1);
        func_80049668(1);
        for (; i != 5; i++, y += 0x14) {
            switch (i) {
            case 0:
                tmp = func_8004C874(0xD, 3);
                value = *(s16 *)(record + 0x2A);
                break;
            case 1:
                tmp = func_8004C874(0xD, 4);
                value = *(s16 *)(record + 0x2C);
                break;
            case 2:
                tmp = func_8004C874(0xD, 6);
                value = *(s16 *)(record + 0x30);
                break;
            case 3:
                tmp = func_8004C874(0xD, 7);
                value = *(s16 *)(record + 0x32);
                break;
            case 4:
                tmp = func_8004C874(0xD, 5);
                value = *(s16 *)(record + 0x2E);
                break;
            }
            func_80048E30((u8 *)D_8800687C, 0x1CE, y, (const char *)tmp, 1);
            if (record[0] == 0xFC) {
                func_80049064(0x241, y, 2, func_8004C874(0x20, 0x18));
            } else {
                func_88000EC0(digits, value, 0);
                for (j = 2; j >= 0; j--) {
                    if (digits[j] >= 0) {
                        func_80049628(0x241 - ((u8 *)D_88234700)[j + 0x1997], y, digits[j] + 0x30);
                    }
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820B6C8.s")
#endif
