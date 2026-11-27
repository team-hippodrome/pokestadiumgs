#include "global.h"


#ifdef VERSION_US
extern u8 D_8009F860;

s32 func_81306EE0(u8 *arg0, s32 arg1) {
    u8 v1 = D_8009F860;
    if (arg1 == arg0[0x137FB]) {
        if (v1 == 1) {
            return 4;
        }
        return v1;
    }
    return v1;
}

extern f32 (*D_8160BD1C)(f32);

s32 func_81306F20(void *arg0) {
    struct S { u8 pad[0x137D0]; f32 value; };
    return (s32)(D_8160BD1C((16 - ((struct S *)arg0)->value) / 16) * 23.0f);
}
// The 0x15370-offset block func_81306F74 passes to func_81302BB0.
typedef struct unk_D_81306F74_owner {
    /* 0x00000 */ u8 unk_00000[0x15370];
    /* 0x15370 */ u8 unk_15370[1];
} unk_D_81306F74_owner;
// The state func_81306F74 colors: owner at 0x137AC, scale at 0x137D0, flags at 0x137EC/0x137F0,
// mode at 0x137F5.
typedef struct unk_func_81306F74 {
    /* 0x00000 */ s16 unk_00000[4];
    /* 0x00008 */ u8 unk_00008[0x137AC - 0x8];
    /* 0x137AC */ unk_D_81306F74_owner *unk_137AC;
    /* 0x137B0 */ u8 unk_137B0[0x137D0 - 0x137B0];
    /* 0x137D0 */ f32 unk_137D0;
    /* 0x137D4 */ u8 unk_137D4[0x137EC - 0x137D4];
    /* 0x137EC */ s32 unk_137EC;
    /* 0x137F0 */ s32 unk_137F0;
    /* 0x137F4 */ u8 unk_137F4;
    /* 0x137F5 */ u8 unk_137F5;
} unk_func_81306F74;
extern s32 func_81302BB0(u8 *);
extern s16 *func_81609530(s32);
extern void func_8160945C(s16 *, s16 *, s16 *, f32);
extern f32 (*D_8160BD08)(f32);
f32 func_81306F74(unk_func_81306F74 *arg0, s16 *arg1) {
    f32 scale;
    s16 *color;

    color = arg0->unk_00000;
    if (arg0->unk_137F5 == 6 || arg0->unk_137F5 == 1 || arg0->unk_137F5 == 2) {
        if (arg0->unk_137F0 != 0) {
            color = func_81609530(func_81302BB0(arg0->unk_137AC->unk_15370) ? 2 : 4);
        }
    }
    if (arg0->unk_137F5 == 5 || arg0->unk_137F5 == 2) {
        if (arg0->unk_137EC != 0) {
            color = func_81609530(8);
        }
    }
    scale = D_8160BD08(arg0->unk_137D0 / 16);
    func_8160945C(arg1, color, func_81609530(3), scale);
    return scale;
}

extern f32 func_81306F74(unk_func_81306F74 *, s16 *);
extern void func_81609A90(s16 *, s16 *);
void func_8130707C(void *arg0, s32 arg1) {
    struct S { u8 pad[0x137D0]; f32 value; };
    s16 sp30[4];
    s16 sp28[4];
    f32 sp24;

    sp24 = ((struct S *)arg0)->value;
    ((struct S *)arg0)->value = 0.0f;
    func_81306F74(arg0, sp30);
    ((struct S *)arg0)->value = 16.0f;
    func_81306F74(arg0, sp28);
    if (arg1 != 0) {
        func_81609A90(sp30, sp28);
    } else {
        func_81609A90(sp28, sp30);
    }
    ((struct S *)arg0)->value = sp24;
}

extern f32 func_8160762C(u8, s32, s32 *, s32 *);
extern void func_81607440(s32, s32, s32, s32, f32, s32, s32);
typedef struct unk_func_81307128_entry {
    /* 0x00 */ u8 unk_00[8];
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 unk_09[0x18 - 0x9];
} unk_func_81307128_entry;
typedef struct unk_func_81307128 {
    /* 0x00000 */ unk_func_81307128_entry entries[0x137B8 / 0x18];
    /* 0x137B8 */ f32 unk_137B8;
    /* 0x137BC */ u8 unk_137BC[0x137F4 - 0x137BC];
    /* 0x137F4 */ u8 unk_137F4;
    /* 0x137F5 */ u8 unk_137F5[0x137F9 - 0x137F5];
    /* 0x137F9 */ u8 unk_137F9;
} unk_func_81307128;
void func_81307128(unk_func_81307128 *arg0, s32 arg1, s32 arg2) {
    s32 pad; // FAKE
    s32 sp38;
    s32 sp34;
    s32 n = (arg0->entries[arg0->unk_137F4].unk_08 + 3) / 4 - 2;

    arg0->unk_137B8 = (func_8160762C(arg0->unk_137F9, n, &sp38, &sp34) - arg0->unk_137B8) * 0.35f + arg0->unk_137B8;
    func_81607440(arg1 + 7, arg2 + 7, 0x13, 0x8E, arg0->unk_137B8, sp38, sp34);
}

void func_813071FC(void) {
}

void *func_81307204(void *arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = *(void **)((u8 *)arg0 + 0x33A0);
    }
    return arg0;
}

// The jump table is in the fragment's shared loaded rodata.
s32 func_81307228(unk_func_81306F74 *arg0) {

    if (arg0->unk_137D0 < 16.0f) {
        return 0;
    }
    switch (arg0->unk_137F5) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 11:
        return 0;
    case 3:
    case 7:
    case 8:
    case 9:
    case 10:
        return 1;
    }
#ifdef CC_CHECK
    return 0;
#endif
}

/* mkdraft:func_8130728C begin */
extern void func_81600F0C(s32, s32, s32, s32, s32);
extern s32 func_81600DA8(void *, void *);
extern void func_816078C4(s32, s32, s32, s32, s32, s32);
extern void func_81606B5C(s32, s32, s32, s32);
extern void func_816068C0(s32, s32, s32, s32);
extern s32 func_81306F20(void *);
extern void func_8160710C(s32, s32, s32);
extern void func_816071AC(s32, s32, s32);

// FAKE: arg4 is an unused 5th formal. Retail callers pass 4 arguments
// (func_8130881C sets only a0-a3) and the retail prologue homes only a1/a2/a3,
// never a 5th incoming argument. The formal exists so IDO 7.1 keeps the
// selector in an expression temporary (spilled at 0x30(sp) across the
// func_81306F20 call) instead of a declared local's home slot at 0x34(sp).
// It is assigned but never read, so it is harmless at the ABI level.
// See func_8130728C.report.md.


void func_8130728C(arg0, arg1, arg2, arg3, arg4)
    void *arg0;
    void *arg1;
    s32 arg2;
    s32 arg3;
    s32 arg4;
{
  struct S { u8 pad[0x137C0]; f32 x; u8 pad4[4]; f32 y; };
  if ((func_81307228(arg0) != 0) && (func_81600DA8(arg1, (void *) 0x54455854) != 0))
  {
    func_81600F0C(*((s32 *) (((u8 *) (*((s32 *) (((u8 *) arg0) + 0x137AC)))) + 0x1A150)), (s16) (arg2 - 0x2F), (s16) (arg3 - 0x37), 0x280, 0x10);
    func_816078C4(arg2 + 0x111, arg3 - 0x37, (*((u8 *) (((u8 *) arg0) + 0x137F5))) != 0xB, func_81306EE0(arg0, *((u8 *) (((u8 *) arg0) + 0x137F4))), *((u8 *) (((u8 *) arg0) + 0x137F4)), *((u8 *) (((u8 *) arg0) + 0x137FB)));
  }
  if (func_81600DA8(arg1, (void *) 0x424F5853) != 0)
  {
    if ((*((s32 *) (((u8 *) arg0) + 0x137E8))) != 0)
    {
      func_81606B5C(arg2 + 0x30, arg3 - 0x20, *((u16 *) (((u8 *) arg0) + 0x137D8)), *((u8 *) (((u8 *) arg0) + 0x137FB)));
    }
    else
    {
      func_816068C0(arg2 + 0x57, (func_81306F20(arg0) + arg3) - 0x20, *((u16 *) (((u8 *) arg0) + 0x137D8)), *((u8 *) (((u8 *) arg0) + 0x137FB)));
    }
  }
  if (func_81600DA8(arg1, (void *) 0x4C5F4254) != 0)
  {
    func_8160710C((s32) (((f32) (arg2 + (arg4 = ((*((s32 *) (((u8 *) arg0) + 0x137E8)) != 0) ? 7 : 46)))) - (((struct S *) arg0)->x)), (func_81306F20(arg0) + arg3) - 0x23, arg4);
  }
  if (func_81600DA8(arg1, (void *) 0x525F4254) != 0)
  {
    func_816071AC((s32) (((f32) (arg2 + (arg4 = ((*((s32 *) (((u8 *) arg0) + 0x137E8)) != 0) ? 0x1F9 : 0x1D4)))) + (((struct S *) arg0)->y)), (func_81306F20(arg0) + arg3) - 0x23, arg4);
  }
}
/* mkdraft:func_8130728C end */

extern s32 func_81600DA8(void *, void *);
void func_813074E4(void *arg0, void *arg1, s32 arg2, s32 arg3)
{
  arg2 += ((*((s32 *) (((u8 *) arg0) + 0x137E8))) != 0) ? (0x30) : (0x57);
 if (0) { }
  arg3 = (func_81306F20(arg0) + ((0, arg3))) - 0x20;
  if (func_81600DA8(arg1, (void *) 0x494E4449) != 0)
  {
    func_81606F88(arg2, arg3, *((s32 *) (((u8 *) arg0) + 0x137BC)), *((s32 *) (((u8 *) arg0) + 0x137E8)));
  }
}

extern s32 func_81600DA8(void *, void *);
extern void func_81606FE0(s32, s32, s32, s32);
void func_81307570(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 offset = (*(s32 *)((u8 *)arg0 + 0x137E8) != 0) ? 0x30 : 0x57;
    if (*(f32 *)((u8 *)arg0 + 0x137D0) < 16.0f) {
        return;
    }
    arg2 += offset;
    arg3 -= 0x20;
    if (func_81600DA8(arg1, arg0) == 0) {
        return;
    }
    func_81606FE0(arg2, arg3, *(s32 *)((u8 *)arg0 + 0x137BC), *(s32 *)((u8 *)arg0 + 0x137E8));
}

// Deck loading debug strings. No retail code references them.
const char D_81312540[] = "Loading %d\n";
const char D_8131254C[] = "Loaded.\n";

/* mkdraft:func_81307600 begin */


s32 func_81307600(void *arg0p, s32 arg1)
{
  typedef struct unk_81307600_record
  {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[2];
    u8 *unk_04[5];
  } unk_81307600_record;
  typedef struct unk_81307600_state
  {
    u8 unk_00000[8];
    unk_81307600_record records[16];
    u8 unk_00188[0x37AC - 0x188];
    u8 *unk_137AC;
    u8 *unk_137B0;
    u8 unk_137B4[0x37F8 - 0x37B4];
    s8 unk_137F8;
    u8 unk_137F9[0x137FB - 0x137F9];
    u8 unk_137FB;
  } unk_81307600_state;
  extern s32 Deck_ReadEntries(u8 *buffer, s32 remaining, u8 *handle);
  extern s32 func_8005CB38(s32 arg0, s32 arg1);
  extern u8 *func_8006218C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
  extern s32 func_80062304(u8 *arg0);
  extern s32 func_8007126C(s32 arg0, s32 arg1, s32 arg2);
  extern void func_8130A88C(u8 *arg0);
  u8 buffer[0x58];
  u8 *deck;
  s32 j;
  s32 mode;
  s32 handle;
  s32 total;
  s32 i;
  s32 k;
  unk_81307600_record *record;

  i = 0;
  record = &((unk_81307600_state *) arg0p)->records[arg1];
  record->unk_00 = (record->unk_01 = 0);
  total = ((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137FB;
  if (arg1 < total)
  {
    if (arg1 == 0)
    {
      mode = 0x20;
    }
    else
    {
      mode = 0x21;
    }
    if (arg1 > 0)
    {
      handle = arg1 - 1;
    }
    else
    {
      handle = 0;
    }
    if ((((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137F8 < 4) && (((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137F8 >= 0) && (func_8005CB38(((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137F8, 0x21) >= arg1))
    {
      deck = func_8006218C(mode, ((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137F8, handle, 0);
      if (deck != 0)
      {
        while (Deck_ReadEntries(buffer, 1, deck) != 0)
        {
            if ((!(buffer[0x1E] & 1)) && (func_8007126C(*((s32 *) ((*((u8 **) (((u8 *) ((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137AC) + 0x1A148))) + 0x940)), buffer[0] - 1, buffer[0x1D]) != 0))
            {
              record->unk_04[0][record->unk_00] = buffer[0];
              for (k = 1; k < 5; k++)
              {
                record->unk_04[k][record->unk_00] = i;
              }
              record->unk_00++;
            }
          i++;
        }
        func_80062304(deck);
      }
    }
  }
  else if ((arg1 == total) && (((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137B0 != 0))
  {
    record->unk_00 = ((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137B0[0];
    for (j = 0; j < record->unk_00; j++)
    {
      record->unk_04[0][j] = ((unk_81307600_state *) (((u8 *) arg0p) + 0x10000))->unk_137B0[(j * 0x18) + 5];
      for (k = 1; k < 5; k++)
      {
        record->unk_04[k][j] = j;
      }
    }
  }
  func_8130A88C((u8 *) record);
  return record->unk_00;
}
/* mkdraft:func_81307600 end */

extern s32 Deck_ReadEntries(u8 *buffer, s32 remaining, u8 *handle);
extern s32 func_8005CB38(s32 arg0, s32 arg1);
extern u8 *func_8006218C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80062304(u8 *arg0);
extern s32 func_8006236C(u8 *, s32);
extern void func_800619E8(u8 *);
extern void func_80061F44(u8 *);
extern void func_80071E48(u8 *, u8 *);
extern void func_8004D878(u8 *, s32, u8 *);
typedef struct F8130785C_Record {
    u8 count;
    u8 unk_01;
    u8 pad[2];
    u8 *items[5];
} F8130785C_Record;
typedef struct F8130785C_State {
    u8 unk_00000[8];
    F8130785C_Record records[16];
} F8130785C_State;
typedef struct F8130785C_Tail {
    u8 unk_0000[0x37AC];
    u8 *unk_137AC;
    u8 *unk_137B0;
    u8 unk_137B4[0x37F4 - 0x37B4];
    u8 unk_137F4;
    u8 unk_137F5[3];
    s8 unk_137F8;
    u8 unk_137F9[2];
    u8 unk_137FB;
} F8130785C_Tail;
typedef struct F8130785C_Flags { u32 pad:5; u32 bit26:1; u32 rest:26; } F8130785C_Flags;
#define ST ((F8130785C_Tail *)((u8 *)arg0 + 0x10000))
#define ENTRY(n) (((u8 (*)[0xCE8])arg1)[n])

s32 func_8130785C(void *arg0, void *arg1, s32 arg2) {
    s32 k;
    s32 idx;
    u8 *deck;
    s32 count;
    u8 buf[8];
    F8130785C_Record *record;
    F8130785C_Record *rec2;
    s32 i;

    *(s16 *)((u8 *)arg1 + 0x33A8) = ST->unk_137F8;
    *(s16 *)((u8 *)arg1 + 0x33AA) = ST->unk_137F4;
    count = 0;
    for (i = 0; i < 4; i++) {
        ENTRY(i)[0] = 0;
        *(s32 *)(ENTRY(i) + 0x58) = 0;
    }
    if (ST->unk_137F4 < ST->unk_137FB) {
        record = &((F8130785C_State *)arg0)->records[ST->unk_137F4];
        if (ST->unk_137F8 < 4 && ST->unk_137F8 >= 0 && func_8005CB38(ST->unk_137F8, 0x21) >= ST->unk_137F4) {
            if (ST->unk_137F4 == 0) {
                deck = func_8006218C(0x20, ST->unk_137F8, 0, 0);
            } else {
                deck = func_8006218C(0x21, ST->unk_137F8, ST->unk_137F4 - 1, 0);
            }
            if (deck != NULL) {
                i = arg2 * 4;
                for (k = 0; k != 4; k++) {
                    if (i < record->count) {
                        idx = func_81306EE0(arg0, ST->unk_137F4);
                        buf[count] = record->items[idx][i];
                        if (func_8006236C(deck, buf[count]) != 0) {
                            count += Deck_ReadEntries(ENTRY(k), 1, deck);
                            if (ST->unk_137F4 == 0) {
                                func_800619E8(ENTRY(k));
                            }
                            func_80061F44(ENTRY(k));
                        }
                        i++;
                    }
                }
                func_80062304(deck);
            }
        }
    } else if (ST->unk_137B0 != NULL) {
        rec2 = &((F8130785C_State *)arg0)->records[ST->unk_137FB];
        i = arg2 * 4;
        for (k = 0; k != 4; k++) {
            if (i < ST->unk_137B0[0]) {
                idx = func_81306EE0(arg0, ST->unk_137F4);
                buf[count] = rec2->items[idx][i];
                func_80071E48(ENTRY(count), ((u8 (*)[0x18])ST->unk_137B0)[buf[count]] + 4);
                i++;
                ENTRY(count)[0x1E] |= 4;
                count++;
            }
        }
    }
    for (i = 0; i < count; i++) {
        func_8004D878(ENTRY(i) + 0x60, 0, ENTRY(i));
        if (ST->unk_137F4 >= ST->unk_137FB) {
            ENTRY(i)[0x58] = 5;
        } else {
            ENTRY(i)[0x58] = ST->unk_137F8 + 1;
        }
        ENTRY(i)[0x5A] = buf[i];
        ENTRY(i)[0x59] = ST->unk_137F4;
        ENTRY(i)[0x5B] = ENTRY(i)[0];
    }
    if (!((F8130785C_Flags *)(*(u8 **)(*(u8 **)(ST->unk_137AC + 0x1A148) + 0x940) + 0x40))->bit26) {
        for (i = 0; i < count; i++) {
            ENTRY(i)[1] = 0;
        }
    }
    return count;
}
#undef ST
#undef ENTRY

extern s32 func_8130785C(void *, void *, s32);
void func_81307C94(void *arg0) {
    s32 var_s0;
    void *var_s1;

    var_s1 = (*(void **)((u8 *)(arg0) + (0x137A8)));
    var_s0 = 0;
    do {
        func_8130785C(arg0, var_s1, (*(u8 *)((u8 *)(arg0) + (0x137F9))) + var_s0);
        var_s0 += 1;
        var_s1 = (*(void **)((u8 *)(var_s1) + (0x33A0)));
    } while (var_s0 != 3);
}

void func_81307D08(void *arg0) {
    s32 offset = 0;
    s32 i;
    s32 j;
    s32 step;

    for (i = 0; i < ((u8 *)arg0)[0x137FB] + 1; i++) {
        if (i != ((u8 *)arg0)[0x137FB]) {
            step = 0x1E;
        } else {
            step = 0xFE;
        }
        for (j = 0; j < 5; j++) {
            *(u8 **)((u8 *)arg0 + 0xC + i * 0x18 + j * 4) = (u8 *)arg0 + 0x137FC + offset;
            offset += step;
        }
    }
}

extern void func_81307D08(void *);
extern s32 func_81307600(void *, s32);
void func_81307DC0(void *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    u8 *p;
    struct State {
    u8 pad0[0x137A8];
    void * fA8;
    s32 fAC;
    void * fB0;
    s16 fB4;
    s16 fB6;
    u8 pad137B8[0x8];
    f32 fC0;
    f32 fC4;
    f32 fC8;
    f32 fCC;
    f32 fD0;
    s16 fD4;
    s16 fD6;
    u16 fD8;
    u8 pad137DA[0xE];
    s32 fE8;
    u8 pad137EC[0x8];
    u8 fF4;
    u8 fF5;
    u8 pad137F6[0x1];
    u8 fF7;
    u8 fF8;
    u8 fF9;
    u8 fFA;
    u8 fFB;
    };

    s32 i;
    s32 j;
    u8 *q;
    ((struct State *)arg0)->fF9 = 0;
    ((struct State *)arg0)->fAC = arg1;
    ((struct State *)arg0)->fF7 = arg2;
    ((struct State *)arg0)->fF5 = 1;
    ((struct State *)arg0)->fB4 = 0;
    ((struct State *)arg0)->fB6 = 0;
    ((struct State *)arg0)->fF8 = arg3;
    ((struct State *)arg0)->fA8 = (u8 *)arg0 + 0x188;
    ((struct State *)arg0)->fD4 = 0;
    ((struct State *)arg0)->fD6 = 1;
    ((struct State *)arg0)->fD0 = 0.0f;
    ((struct State *)arg0)->fB0 = arg4;
    ((struct State *)arg0)->fC0 = 0.0f;
    ((struct State *)arg0)->fC8 = 0.0f;
    ((struct State *)arg0)->fC4 = 0.0f;
    ((struct State *)arg0)->fCC = 0.0f;
    ((struct State *)arg0)->fD8 = 0;
    ((struct State *)arg0)->fFA = 0;
    ((struct State *)arg0)->fE8 = 1;
    p = (u8 *)arg0;
    if (*(s32 *)(p + 0x137E8)) ((struct State *)arg0)->fFB = 15;
    else ((struct State *)arg0)->fFB = 10;
    q = p;
    for (i = 0; i < 6; i++) {
        *(void **)(q + 0x33B0 + 0x178) = p + 0x188 + ((i + 1) % 6) * 0x33B0;
        *(void **)(q + 0x33B0 + 0x17C) = p + 0x188 + ((i + 5) % 6) * 0x33B0;
        q += 0x33B0;
    }
    func_81307D08(arg0);
    for (i = 15; i >= 0; i--) {
        if (func_81307600(arg0, i) > 0) {
            ((struct State *)arg0)->fF4 = i;
            ((struct State *)arg0)->fD8 |= 1 << i;
        }
    }
}

extern f32 func_816092FC(void);

// Adds this frame's step to D_81311F80 and returns 1 each time the total passes 30, keeping the
// remainder; returns 0 otherwise.
s32 func_81308014(void) {
    // Function-scope static: retail reloads its %hi for each access, which IDO does not
    // do for an extern or a file-scope static (both get one cached address register).
    static f32 D_81311F80 = 0.0f;

    D_81311F80 += func_816092FC();
    if (D_81311F80 > 30.0f) {
        D_81311F80 -= 30.0f;
        return 1;
    }
    return 0;
}

// IDO pads this object's .data section to 16 bytes, so the retail words at 0x81311F84-0x81311F8C
// are carried here to keep the following data blob in place. No code references them.
s32 D_81311F84[] = { 7680, 38400 };
f32 D_81311F8C = 0.43f;

extern Gfx *D_800D0510;
extern void func_81605950(void);
extern void *func_8160771C(u16 arg0, u16 arg1, u16 arg2);
extern void func_816059CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *color);
extern s32 func_81304678(u8 *arg0, u8 *arg1);
extern s32 func_8130456C(void *, void *);
extern void func_8004D998(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern void func_800498C4(void);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_800495BC(s32 arg0, s32 arg1, const char *arg2, ...);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern const char *func_8004C874(s32, s32);
extern void func_800499EC(void);
extern s32 func_81601EAC(u8, u8);
extern s32 func_81304884(u8 *arg0, s32 arg1);
extern void func_81608550(s32, s32, s32, s32, f32);
extern void func_8160324C(f32 alpha);
extern void func_81603984(s32 arg0, s32 arg1);
extern void func_8160852C(void);
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
typedef struct {
    u8 species;
    u8 item;
    u8 pad2[0x1B];
    u8 level;
    u8 pad1E[0x16];
    char name[0x2C];
    u8 icon[0xCE8 - 0x60];
} F14Mon;
#define SCALE (*(f32 *)(arg0 + 0x137D0))
#define OWNER (*(u8 **)(arg0 + 0x137AC) + 0x15370)
#define sx (x0 + i * 0x80)
void func_81308078(u8 *arg0, s16 x0, s16 y, s16 x1, s16 y1, F14Mon *arg5) {
    u8 col[4];
    s32 i;
    s32 item;
    char buf[0x1C];

    if (x1 + 0x224 < x0 || x0 + 0x224 < x1 || y + 0x28 < y1 || y1 + 0x9F < y) {
        return;
    }
    func_81605950();
    func_8160771C(*(u16 *)((u8 *)arg5 + 0x33AA), *(u16 *)(arg0 + 0x137D8), arg0[0x137FB]);
    col[0] = 0;
    col[1] = 0;
    col[2] = 0;
    col[3] = SCALE * 100.0f / 16;
    for (i = 0; i < 4; i++) {
        if (sx > x1 + 0x224 || sx + 0x80 < x1) continue;
        if (arg5[i].species == 0) continue;
        if (func_81304678(OWNER, (u8 *)arg5 + i * 0xCE8) || !func_8130456C(OWNER, &arg5[i])) {
            col[3] = 0x32;
        } else {
            col[3] = 0x64;
        }
        func_816059CC(sx - 8, y - 6, 0x85, 0x34, col);
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, SCALE * 255.0f / 16);
    for (i = 0; i < 4; i++) {
        if (sx <= x1 + 0x224 && sx + 0x80 >= x1) {
            if (arg5[i].species != 0) {
                func_8004D998(sx + 2, y + 2, arg5[i].icon, 0, 1);
            }
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    func_800498C4();
    func_800496A4(4, 1);
    for (i = 0; i < 4; i++) {
        if (sx <= x1 + 0x224 && sx + 0x80 >= x1) {
            if (arg5[i].species != 0) {
                if (func_81304678(OWNER, (u8 *)arg5 + i * 0xCE8)) {
                    // FAKE: empty then-branch (retail branch layout)
                } else {
                    if (func_8130456C(OWNER, &arg5[i])) {
                        func_8004972C(0xFF, 0xFF, 0xFF, (s32)(SCALE * 255.00f / 16));
                    } else {
                        func_8004972C(0x96, 0x96, 0x96, (s32)(SCALE * 255.000f / 16));
                    }
                    func_800496A4(4, 1);
                    func_800495BC(sx + 0x29, y + 2, arg5[i].name);
                    func_800496A4(4, -1);
                    sprintf(buf, "%s %d", func_8004C874(0xD, 0x15), arg5[i].level);
                    func_800495BC(sx + 0x29, y + 0x16, buf);
                }
            }
        }
    }
    func_800499EC();
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, SCALE * 255.0000f / 16);
    func_8160852C();
    if (arg5 == 0) {} // FAKE
    for (i = 0; i < 4; i++) {
        s32 species = arg5[i].species;
        item = arg5[i].item;
        if (!func_81304678(OWNER, (u8 *)&arg5[i])) {
            if (sx <= x1 + 0x224 && sx + 0x80 >= x1 && species != 0) {
                func_81608550(sx + 0x65, y + 0x16, item, func_81601EAC(item, species) != 0 && func_81304884(OWNER, item) == 0, SCALE / 16);
            }
        }
    }
    func_8160324C(SCALE / 16);
    for (i = 0; i < 4; i++) {
        if (func_81304678(OWNER, (u8 *)&arg5[i])) {
            func_81603984(x0 + i * 0x80 + 0x2D, y + 0xA);
        }
    }
}
#undef sx
#undef SCALE
#undef OWNER


extern void func_81308078(u8 *, s16, s16, s16, s16, F14Mon *);
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern void Gfx_FillRectRgb(s16, s16, s16, s16, u8, u8, u8);
extern void func_8004B314(s32, s32, s32, s32);
extern void func_816048E0(s32, s32, s32, s32, f32);
extern f32 (*D_8160BD00)(f32);
extern void func_81607408(void);
extern Gfx *D_800D0510;
extern Gfx D_80094D90[];
void func_8130881C(u8 *arg0, void *arg1) {
    f32 fx;
    f32 fy;
    s16 pos[2];
    f32 r;
    s32 x;
    s32 y;
    s32 s1;
    s32 i;
    u8 *s2;
    s16 t1;
    s32 sy; // unused, keeps the retail frame layout
    Gfx *gfx;
    u8 mode; // unused, keeps the retail frame layout
    f32 k;
    s32 sx;

    func_81306F74((unk_func_81306F74 *)arg0, pos);
    x = pos[0] + 0x1F;
    y = pos[1] + 0xB;
    func_8130728C(arg0, arg1, pos[0], pos[1]);
    if (func_81600DA8(arg1, arg0) == 0) {
        return;
    }
    func_813074E4(arg0, arg1, pos[0], pos[1]);
    func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);
    func_816048E0(pos[0], pos[1], 0x224, 0x9F, 0.0f);
    r = D_8160BD00((f32)*(s16 *)(arg0 + 0x137D4) / (f32)*(s16 *)(arg0 + 0x137D6));
    if (*(s16 *)(arg0 + 0x137D6) < 0) {
        r = -r;
    }
    sx = arg0[0x137F5];
    switch (sx) {
    case 7:
        sx = (*(s16 *)(arg0 + 0x137D6) > 0) ? 0x1FB : -0x1FB;
        func_80006F70(&D_800D0510, (s16)x, (s16)y, 0x1F5, 0x86);
        gfx = D_800D0510++;
        gfx->words.w0 = 0xDE000000; gfx->words.w1 = (u32)D_80094D90;
        Gfx_FillRectRgb((s16)((s16)(s32)((f32)x - 501.0f * r) - 6), (s16)y, 6, 0x86, 200, 200, 200);
        Gfx_FillRectRgb((s16)((s16)(s32)((f32)x - 501.0f * r) + 0x1F5), (s16)y, 6, 0x86, 200, 200, 200);
        if (D_800D0510) {} // FAKE
        if (D_800D0510 + 1) {} // FAKE
        if (D_800D0510 + 1) {} // FAKE
        if ((s16)y) {} // FAKE
        t1 = sx - (0 - (s16)(s32)((f32)x - 501.0f * r));
        for (i = 0, s1 = y, s2 = *(u8 **)(arg0 + 0x137A8); i < 0x8D; i += 0x2F) {
            func_81308078(arg0, t1, (s16)s1, pos[0], pos[1], (F14Mon *)s2);
            s1 += 0x2F;
            s2 = *(u8 **)(s2 + 0x33A0);
        }

        for (i = 0, s1 = y; i != 0x8D; i += 0x2F) {
            func_81308078(arg0, (s16)(s32)((f32)x - 501.0f * r), (s16)s1, pos[0], pos[1], (F14Mon *)s2);
            s1 += 0x2F;
            s2 = *(u8 **)(s2 + 0x33A0);
        }
        func_81607408();
        func_81307128((unk_func_81307128 *)arg0, pos[0], pos[1]);
        break;
    case 8:

        func_80006F70(&D_800D0510, (s16)x, (s16)y, 0x1F5, 0x86);
        if (*(s16 *)(arg0 + 0x137D6) > 0) {
            s2 = *(u8 **)(*(u8 **)(arg0 + 0x137A8) + 0x33A4);
            s1 = (s16)(s32)((f32)y - 47.0f * r);
            for (i = 0; i != 0xBC; i += 0x2F) {
                func_81308078(arg0, (s16)x, (s16)(s1 + i), pos[0], pos[1], (F14Mon *)s2);
                s2 = *(u8 **)(s2 + 0x33A0);
            }
        } else {
            s2 = *(u8 **)(arg0 + 0x137A8);
            s1 = (s16)(s32)((f32)y - 47.0f * r);
            for (i = 0; i != 0xBCU; i += 0x2F) {
                func_81308078(arg0, (s16)x, (s16)(s1 + i - 0x2F), pos[0], pos[1], (F14Mon *)s2);
                s2 = *(u8 **)(s2 + 0x33A0);
            }
        }
        func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);
        func_81307128((unk_func_81307128 *)arg0, pos[0], pos[1]);
        break;
    default:
        if ((s16)x) {} // FAKE
        s2 = *(u8 **)(arg0 + 0x137A8);
        for (i = 0, s1 = y; i != 0x8DU; i += 0x2F) {
            func_81308078(arg0, (s16)x, (s16)s1, pos[0], pos[1], (F14Mon *)s2);
            s1 += 0x2F;
            s2 = *(u8 **)(s2 + 0x33A0);
        }
        func_81307128((unk_func_81307128 *)arg0, pos[0], pos[1]);
        break;
    }
    fx = (f32)(*(s16 *)(arg0 + 0x137B4) * 128 + x);
    fy = (f32)(*(s16 *)(arg0 + 0x137B6) * 47 + y);
    if (arg0[0x137F5] == 10) {
        k = (0.0f < r) ? -1.0f : 1.0f; fy += (r + k) * 47.0f;
    } else if (arg0[0x137F5] == 9) {
        k = (0.0f < r) ? -1.0f : 1.0f; fx += (r + k) * 128.0f;
    }
    switch (arg0[0x137F5]) {
    case 3:
    case 7:
    case 8:
    case 9:
    case 10:
        func_8004B314((s32)fx, (s32)fy, 0x75, 0x28);
        break;
    default:
        break;
    }
    func_81307570(arg0, arg1, pos[0], pos[1]);
}

extern s32 func_8130F578(void *, s32 *);
extern s32 func_81304444(void *, void *, s32);
extern void * func_81307204(void *arg0, s32 arg1);
void func_81308E3C(void *arg0)
{
  struct W
  {
    u8 pad[0x137E4];
    s32 dirty;
    u8 gap[0xD];
    u8 state;
  };
  s32 value;
  s16 status;
  void *record;
  s32 result;
  u8 unused[8];
  result = func_8130F578(*((void **) (((u8 *) arg0) + 0x137AC)), &value);
  status = result;
  if (result > 0)
  {
    func_81307204(*((void **) (((u8 *) arg0) + 0x137A8)), *((s16 *) (((u8 *) arg0) + 0x137B6)));
    ((struct W *) arg0)->state = 3;
  }
  if (status == 1)
  {
    ;
    if (func_81304444(((u8 *) (*((void **) (((u8 *) arg0) + 0x137AC)))) + 0x15370, ((*((s16 *) (((u8 *) arg0) + 0x137B4))) * 0xCE8) + ((u8 *) func_81307204(*((void **) (((u8 *) arg0) + 0x137A8)), *((s16 *) (((u8 *) arg0) + 0x137B6)))), value) != 0)
    {
      ((struct W *) arg0)->dirty = 1;
      ((struct W *) arg0)->state = 4;
    }
    ((struct W *) arg0)->state = 4;
  }
  else
    if (status == 2)
  {
    ((struct W *) arg0)->state = 3;
  }
}

/* mkdraft:func_81308F54 begin */
extern void func_8130EB04(void *, s32, void *, s32, s32, s16 *, s16 *, s32);
extern s32 func_8130456C(void *, void *);
extern void func_800226C0(s32);
extern void func_81304788(u8 *, s32 *, s32);
extern void func_813049AC(u8 *, s16 *);
extern s32 func_8160A920(u8 *);
typedef struct unk_tail { u8 pad[0x137F5]; u8 state; } unk_tail;


void func_81308F54(void *arg0) {
    u8 *table;
    s32 mode;
    s32 flags[8];
    s16 offset[4];
    s16 rect[4];
    s16 position[4];

    table = func_81307204(*(u8 **)((u8 *)arg0 + 0x137A8), *(s16 *)((u8 *)arg0 + 0x137B6));
    if (func_8130456C(
            *(u8 **)((u8 *)arg0 + 0x137AC) + 0x15370,
            ((u8 (*)[3304])table)[*(s16 *)((u8 *)arg0 + 0x137B4)]) != 0) {
        func_81306F74(arg0, offset);
        rect[0] = *(s16 *)((u8 *)arg0 + 0x137B4) * 128 + offset[0] + 31;
        rect[1] = *(s16 *)((u8 *)arg0 + 0x137B6) * 47 + offset[1] + 11;
        rect[2] = 117;
        rect[3] = 40;
        func_813049AC(*(u8 **)((u8 *)arg0 + 0x137AC) + 0x15370, position);
        func_81304788(
            *(u8 **)((u8 *)arg0 + 0x137AC) + 0x15370,
            flags, func_8160A920(*(u8 **)((u8 *)arg0 + 0x137AC) + 0x15370));
        mode = func_81302BB0(*(u8 **)((u8 *)arg0 + 0x137AC) + 0x15370) ? 0x98 : 0x92;
        func_8130EB04(
            *(u8 **)((u8 *)arg0 + 0x137AC),
            *(u8 *)((u8 *)arg0 + 0x137F7),
            ((u8 (*)[3304])table)[*(s16 *)((u8 *)arg0 + 0x137B4)], 0, flags, rect, position, mode);
        func_800226C0(144);
        ((struct unk_tail *)arg0)->state = 11;
    } else {
        func_800226C0(5);
    }
}
/* mkdraft:func_81308F54 end */

extern s32 func_8130437C(s32 arg0);
extern void func_800226C0(s32);
void func_8130911C(void *arg0) {
    struct S { u8 pad0[0x137AC]; s32 value; u8 gap0[0x20]; f32 fvalue; u8 gap1[0x10]; s32 flag; u8 gap2[0x8]; s32 flag2; u8 gap3[1]; u8 state; };
    struct S *s = arg0;
    s32 result = func_8130437C(s->value + 0x15370);
    if (result == -1) {
        goto neg1;
    }
    if (result != 1) {
        goto end;
    }
    s->flag = 1;
    s->state = 4;
    func_800226C0(3);
    goto end;
neg1:
    s->flag2 = 0;
    s->flag = 1;
    s->fvalue = 16.0f;
    s->state = 6;
    func_800226C0(3);
end:
    ;
}

extern s32 func_813042E4(s32, void *);
extern void func_800226C0(s32);
void func_813091E0(void *arg0) {
    struct S { u8 pad0[0x137AC]; s32 value; u8 gap[0x34]; s32 flag; u8 gap1[0xD]; u8 state; };
    struct S *s = arg0;
    if (func_813042E4(s->value + 0x15370, s) != 0) {
        s->flag = 1;
        s->state = 4;
        func_800226C0(2);
    }
}

/* mkdraft:func_8130924C begin */
extern void *func_81307204(void *arg0, s32 arg1);
extern void func_800226C0(s32);
extern void func_81307C94(void *);

typedef struct unk_8130924C_entry {
    u8 pad0[8];
    u8 flag;
    u8 data;
    u8 pad1[0xE];
} unk_8130924C_entry;





void func_8130924C(void *arg0) {
    struct S {
        u8 pad0[0x137A8];
        void *resource;
        u8 gap0[0x28];
        s16 timer;
        s16 state;
        u8 gap1[4];
        s32 active;
        u8 gap2[0x14];
        u8 index;
        u8 flag;
        u8 gap3[3];
        u8 current;
    };
    s16 index;
    s16 start;
    // FAKE: unused slots. The retail frame is 0x38 bytes with the spilled entry pointer at
    // 0x24(sp), the struct base at 0x28(sp) and start at 0x34(sp); these two declared-after
    // locals hold 0x30(sp)/0x2C(sp). Without them start lands at 0x2C(sp) in a 0x30-byte frame.
    UNUSED s32 pad0;
    UNUSED s32 pad1;

    index = ((struct S *)arg0)->index;
    start = ((struct S *)arg0)->index;
    do {
        index = (index + 0x11) % 16;
    } while (index != start && ((unk_8130924C_entry *)arg0)[index].flag == 0);

    if (index != start) {
        ((struct S *)arg0)->index = index;
        ((struct S *)arg0)->resource = func_81307204(((struct S *)arg0)->resource, 3);
        ((unk_8130924C_entry *)arg0)[start].data = ((struct S *)arg0)->current;
        ((struct S *)arg0)->current = ((unk_8130924C_entry *)arg0)[index].data;
        func_800226C0(10);
        func_81307C94(arg0);
        ((struct S *)arg0)->timer = 0;
        ((struct S *)arg0)->state = 0x12;
        ((struct S *)arg0)->flag = 7;
        ((struct S *)arg0)->active = 1;
    }
}
/* mkdraft:func_8130924C end */

/* mkdraft:func_81309394 begin */
extern void *func_81307204(void *arg0, s32 arg1);
extern void func_800226C0(s32);
extern void func_81307C94(void *);

// Record table at the object base: 0x18-byte entries. Byte 8 is the scan flag the do-while
// loop tests (a non-zero entry ends the search); byte 9 is copied to the object's 0x137F9 byte
// and is also where that byte is stored back, into the entry the scan started from.
typedef struct unk_81309394_entry {
    u8 pad0[8];
    u8 flag;
    u8 data;
    u8 pad1[0xE];
} unk_81309394_entry;



void func_81309394(void *arg0) {
    struct S {
        u8 pad0[0x137A8];
        void *resource;
        u8 gap0[0x28];
        s16 timer;
        s16 state;
        u8 gap1[8];
        s32 active;
        u8 gap2[0x10];
        u8 index;
        u8 flag;
        u8 gap3[3];
        u8 current;
    };
    s16 next;
    s16 start;
    // FAKE: unused slots. The retail frame is 0x38 bytes with the spilled entry pointer at
    // 0x24(sp), the struct base at 0x28(sp) and start at 0x34(sp); these two declared-after
    // locals hold 0x30(sp)/0x2C(sp). Without them start lands at 0x2C(sp) in a 0x30-byte frame
    // (diff score 26).
    UNUSED s32 pad0;
    UNUSED s32 pad1;

    next = ((struct S *)arg0)->index;
    start = ((struct S *)arg0)->index;
    do {
        next = (next + 0xF) % 16;
    } while (next != start && ((unk_81309394_entry *)arg0)[next].flag == 0);

    if (next != start) {
        ((struct S *)arg0)->index = next;
        func_800226C0(10);
        ((struct S *)arg0)->resource = func_81307204(((struct S *)arg0)->resource, 3);
        ((unk_81309394_entry *)arg0)[start].data = ((struct S *)arg0)->current;
        ((struct S *)arg0)->current = ((unk_81309394_entry *)arg0)[next].data;
        func_81307C94(arg0);
        ((struct S *)arg0)->timer = 0;
        ((struct S *)arg0)->state = -0x12;
        ((struct S *)arg0)->flag = 7;
        ((struct S *)arg0)->active = 1;
    }
}
/* mkdraft:func_81309394 end */

extern f32 func_816092FC(void);
extern void func_800226C0(s32);
void func_813094E0(void *arg0) {
    struct S { u8 pad0[0x137B4]; s16 count; u8 gap0[0x1E]; s16 x; s16 y; u8 gap1[0x1D]; u8 state; };
    struct S *s = arg0;
    s16 temp_v0;

    temp_v0 = s->count;
    if (temp_v0 > 0) {
        s->count = temp_v0 - 1;
        s->x = -1;
        s->y = -7;
        s->state = 9;
        func_800226C0(1);
    }
}

extern void func_800226C0(s32);
void func_81309550(void *arg0) {
    struct S { u8 pad0[0x137B4]; s16 count; u8 gap0[0x1E]; s16 x; s16 y; u8 gap1[0x1D]; u8 state; };
    struct S *s = arg0;
    s16 temp_v0;

    temp_v0 = s->count;
    if (temp_v0 < 3) {
        s->count = temp_v0 + 1;
        s->x = 1;
        s->y = 7;
        s->state = 9;
        func_800226C0(1);
    }
}

extern void func_800226C0(s32);

// Shared fragment-unit state. arg0 is the unit; the record chain head is at
// 0x137A8, and each record links to the next through its +0x33A4 pointer
// (func_81307C94 walks the same records through +0x33A0). The small
// counter/value/flag block at 0x137D4..0x137F9 is also written by
// func_813094E0 and func_81309550.


void func_813095C4(void *arg0, u16 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x137A8];
        u8 *data;
        u8 pad1[0x137D4 - 0x137AC];
        s16 value;
        s16 flag;
        u8 pad2[0x137F5 - 0x137D8];
        u8 mode;
        u8 pad3[0x137F9 - 0x137F6];
        u8 count;
    } State;
    State *s = arg0;

    if (s->count > 0) {
        if (func_8130785C(arg0, *(void **)(s->data + 0x33A4), s->count - 1)) {
            func_800226C0(1);
            s->count--;
            s->data = *(void **)(s->data + 0x33A4);
            if (arg2 != 0) {
                s->value += arg1;
            } else {
                s->value = 0;
            }
            s->flag = -arg1;
            s->mode = 8;
        }
    }
}

void func_813095C4(void *arg0, u16 arg1, s32 arg2);
extern void func_800226C0(s32);
void func_813096B4(void *arg0) {
    struct S { u8 pad0[0x137B6]; s16 count; u8 gap0[0x1C]; s16 x; s16 y; u8 gap1[0x1D]; u8 state; };
    struct S *s = arg0;
    s16 temp_v0;

    temp_v0 = s->count;
    if (temp_v0 != 0) {
        s->count = temp_v0 - 1;
        s->x = -1;
        s->y = -2;
        s->state = 10;
        func_800226C0(1);
    } else {
        func_813095C4(arg0, 8, 0);
    }
}

/* mkdraft:func_81309740 begin */
extern s32 func_8130785C(void *, void *, s32);
extern void func_800226C0(s32);



void func_81309740(void *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x137A8];
        void *value;
        u8 gap0[0x28];
        s16 timer;
        s16 delay;
        u8 gap1[0x1D];
        u8 flag;
        u8 gap2[3];
        u8 count;
    } State;
    State *state = (State *)((u8 *)arg0);
    if (func_8130785C(((u8 *)arg0), func_81307204(state->value, 3), (s32)(state->count + 3)) != 0) {
        func_800226C0(1);
        state->count++;
        state->value = *(void **)((u8 *)state->value + 0x33A0);
        state->timer = (arg2 != 0) ? (state->timer - (u16)arg1) : 0;
        state->delay = (u16)arg1;
        state->flag = 8;
    }
}
/* mkdraft:func_81309740 end */

extern void func_81309740(void *, s32, s32);
void func_81309820(void *arg0) {
    struct unk_func_81309820 {
        u8 unk_00000[79798];
        s16 unk_137B6;
        u8 unk_137B8[28];
        s16 unk_137D4;
        s16 unk_137D6;
        u8 unk_137D8[29];
        u8 unk_137F5;
    };
    struct unk_func_81309820 *var_a3 = arg0;
    s16 var_v0 = var_a3->unk_137B6;

    if (var_v0 < 2) {
        var_a3->unk_137B6 = var_v0 + 1;
        var_a3->unk_137D4 = 1;
        var_a3->unk_137D6 = 2;
        var_a3->unk_137F5 = 10;
        func_800226C0(1);
    } else {
        func_81309740(arg0, 8, 0);
    }
}

extern void func_800226C0(s32);
extern void func_81307C94(void *arg0);
void func_813098B0(void *arg0) {
    struct S { u8 pad0[0x137B4]; s16 count; s16 count2; u8 gap[0x41]; u8 value; };
    struct S *s = arg0;

    D_8009F860 += 1;
    s->count = 0;
    s->count2 = 0;
    s->value = 0;
    if (D_8009F860 >= 4) {
        D_8009F860 = 1;
    }
    func_81307C94(arg0);
    func_800226C0(0x12);
}

extern void func_81308F54(void *);
extern void func_8130924C(void *);
extern void func_81309394(void *);
extern void func_81309820(void *);
extern void func_81309740(void *, s32, s32);
extern void func_8130911C(void *arg0);
extern void func_813091E0(void *arg0);
extern void func_813094E0(void *arg0);
extern void func_81309550(void *arg0);
void func_813095C4(void *arg0, u16 arg1, s32 arg2);
extern void func_813096B4(void *arg0);
extern void func_813098B0(void *arg0);
extern u8 D_800CE060[];
void func_81309928(struct State *arg0) {
    struct State { u8 pad[0x137D0]; f32 value; u8 gap[0x10]; s32 dirty; u8 gap2[0xF]; u8 idx; };
    u8 *record;
    u16 a1;
    s32 v1;
    record = D_800CE060 + arg0->idx * 0x28;
    a1 = *(u16 *)(record + 0xC);
    arg0->value = 16.0f;
    v1 = *(u16 *)(record + 0xC);
    if (v1 & 0x8000) { func_81308F54(arg0); }
    else if (v1 & 0x4000) { func_8130911C(arg0); }
    else if (v1 & 0x1000) { func_813091E0(arg0); }
    else if (a1 & 0x10) { func_8130924C(arg0); }
    else if (a1 & 0x20) { func_81309394(arg0); }
    else if (v1 & 0x200) { func_813094E0(arg0); }
    else if (v1 & 0x100) { func_81309550(arg0); }
    else if (v1 & 0x800) { func_813096B4(arg0); }
    else if (v1 & 0x400) { func_81309820(arg0); }
    else if (v1 & 0x8) { func_813095C4(arg0, 2, 0); }
    else if (v1 & 0x4) { func_81309740(arg0, 2, 0); }
    else if (a1 & 0x1) { func_813098B0(arg0); }
    arg0->dirty = 1;
}

void func_81309ACC(u8 *arg0) {
    *(f32 *)(arg0 + 0x137D0) = 0.0f;
}

extern void func_8130924C(void *);
extern void func_81309394(void *);
void func_813095C4(void *arg0, u16 arg1, s32 arg2);
extern void func_81309740(void *, s32, s32);
extern f32 func_816092FC(void);
extern u8 D_800CE060[];
void func_81309AE0(void *arg0) {
    struct State {
        u8 pad0[0x137D4];
        s16 current;
        s16 target;
        u8 padD8[0xC];
        s32 dirty;
        u8 padE8[0xD];
        u8 mode;
        u8 padF6;
        u8 index;
    };
    u8 *record;
    s32 mode;

    record = D_800CE060 + ((struct State *)arg0)->index * 0x28;
    mode = ((struct State *)arg0)->mode;
    if (((struct State *)arg0)->target > 0) {
        ((struct State *)arg0)->current += func_816092FC();
        if (((struct State *)arg0)->current >= ((struct State *)arg0)->target) {
            ((struct State *)arg0)->mode = 3;
            if (mode == 8) {
                
                if ((*(u16 *)(record + 0xC)) & 4) {
                    func_81309740(arg0, 2, 1);
                } else if ((*(u16 *)(record + 0xC)) & 0x400) {
                    func_81309740(arg0, 8, 1);
                }
            }
            if (mode == 7) {
                if (*(u16 *)(record + 6) & 0x10) {
                    func_8130924C(arg0);
                }
            }
        }
    } else {
        ((struct State *)arg0)->current = ((struct State *)arg0)->current - func_816092FC();
        if (((struct State *)arg0)->current <= ((struct State *)arg0)->target) {
            ((struct State *)arg0)->mode = 3;
            if (mode == 8) {
                
                if ((*(u16 *)(record + 0xC)) & 8) {
                    func_813095C4(arg0, 2, 1);
                } else if ((*(u16 *)(record + 0xC)) & 0x800) {
                    func_813095C4(arg0, 8, 1);
                }
            }
            if (mode == 7) {
                if (*(u16 *)(record + 6) & 0x20) {
                    func_81309394(arg0);
                }
            }
        }
    }
    ((struct State *)arg0)->dirty = 1;
}

void func_81309D00(u32 arg0)
{
    int new_var;
    u8 *p = (u8 *)((u32)arg0);
    u8 v = p[0x137FA];

    if (v)
    {
        p[0x137F5] = v;
        new_var = 0x137FA;
        if (0) { }
        p[new_var] = 0;
    }
}

extern f32 func_816092FC(void);
void func_81309D34(void *arg0) {
    struct S { u8 pad[0x137D0]; f32 value; };
    struct T { u8 pad[0x137F5]; u8 state; };
    struct U { u8 pad[0x137E4]; s32 flag; };
    struct S *s = (struct S *)arg0;
    s->value += func_816092FC();
    if (s->value <= 0.0f) s->value = 0.0f;
    else if (s->value >= 16.0f) { s->value = 16.0f; ((struct T *)arg0)->state = 4; }
    ((struct U *)arg0)->flag = 1;
}

extern f32 func_816092FC(void);
void func_81309DD8(void *arg0) {
    struct S { u8 pad0[0x137D0]; f32 value; u8 gap0[0x10]; s32 status; u8 gap1[0xD]; u8 state; };
    struct S *s = arg0;
    f32 temp_fv1;

    s->value = (f32)(s->value - func_816092FC());
    temp_fv1 = s->value;
    if (temp_fv1 <= 0.0f) {
        s->state = 2;
        s->value = 0.0f;
    } else if (temp_fv1 >= 16.0f) {
        s->value = 16.0f;
    }
    s->status = 1;
}

f32 func_81309E80(f32 arg0) {
    f32 result;
    if (arg0 > 0.0f) {
        result = arg0;
    } else {
        result = -arg0;
    }
    return result;
}

extern f32 D_81311F90;
extern f32 D_81311F9C;
extern f32 func_81309E80(f32 arg0);
extern f32 func_816092FC(void);
void func_81309EB0(void *arg0) {
    struct S { u8 pad[0x137C0]; f32 x; u8 pad4[4]; f32 y; u8 pad10[0x10]; s32 fy; s32 fx; };
    struct S *s = arg0;
    f32 dummy, tx, ty, step;
    tx = s->fx ? D_81311F90 : 0.0f;
    ty = s->fy ? D_81311F90 : 0.0f;
    step = func_816092FC() * D_81311F9C;
    if (func_81309E80(s->y - ty) < step) {
        s->y = ty;
        s->fy = 0;
    } else if (ty < s->y) {
        s->y -= step;
    } else {
        s->y += step;
    }
    if (func_81309E80(s->x - tx) < step) {
        s->x = tx;
        s->fx = 0;
    } else if (tx < s->x) {
        s->x -= step;
    } else {
        s->x += step;
    }
}

extern void func_81600A34(void *, void *, s32, s32, s32, s32, s32);
extern void func_81606E84(s16 *, s32, s32, f32, s32);
typedef struct F8130A044_State { u8 pad[0x137BC]; f32 unk_137BC; u8 pad2[0x137E4 - 0x137C0]; s32 unk_137E4; } F8130A044_State;
#define ST(t, off) (*(t *)((u8 *)arg0 + (off)))

void func_8130A044(void *arg0, void *arg1) {
    s32 pad0[2];
    s32 dirty;
    s32 prev;
    s32 mode;
    s32 pad1;
    s16 pos[2];
    s32 pad2;
    s32 x;
    s32 y;
    s16 rect[4];

    dirty = 0;
    prev = D_8009F860;
    mode = ST(u8, 0x137F5);
    switch (ST(u8, 0x137F5)) {
        case 1:
        case 2:
            func_81309ACC(arg0);
            return;
        case 4:
            func_81309D00((u32)arg0);
            break;
        case 5:
            func_81309D34(arg0);
            dirty = 1;
            break;
        case 6:
            func_81309DD8(arg0);
            dirty = 1;
            break;
        case 3:
            func_81309928(arg0);
            dirty = 1;
            break;
        case 11:
            func_81308E3C(arg0);
            break;
        case 7:
        case 8:
        case 9:
        case 10:
            func_81309AE0(arg0);
            dirty = 1;
            break;
    }
    func_81309EB0(arg0);
    if (dirty == 0 && ST(s32, 0x137E4) != 0) {
        dirty = 1;
        ((F8130A044_State *)arg0)->unk_137E4 = 0;
    }
    func_81306F74(arg0, pos);
    x = pos[0];
    y = pos[1];
    if (func_81307228(arg0) != 0) {
        func_81600A34(arg1, (void *)0x54455854, ST(u8, 0x137F5) == 7 || prev != D_8009F860 || mode != ST(u8, 0x137F5), x - 0x2F, y - 0x37, 0x280, 0x10);
    }
    func_81600A34(arg1, (void *)0x424F5853, 0, ((ST(s32, 0x137E8) != 0) ? 0x30 : 0x57) + x, func_81306F20(arg0) + y - 0x20, (ST(s32, 0x137E8) != 0) ? 0x1C4 : 0x178, 0x17);
    func_81600A34(arg1, (void *)0x4C5F4254, 0, (s32)((f32)(((ST(s32, 0x137E8) != 0) ? 7 : 0x2E) + x) - ST(f32, 0x137C0)), func_81306F20(arg0) + y - 0x23, 0x20, 0x18);
    func_81600A34(arg1, (void *)0x525F4254, 0, (s32)(ST(f32, 0x137C8) + (f32)(((ST(s32, 0x137E8) != 0) ? 0x1F9 : 0x1D4) + x)), func_81306F20(arg0) + y - 0x23, 0x20, 0x18);
    ((F8130A044_State *)arg0)->unk_137BC = ST(f32, 0x137BC) + ((f32)ST(u8, 0x137F4) - ST(f32, 0x137BC)) * 0.4f;
    func_81606E84(rect, ((ST(s32, 0x137E8) != 0) ? 0x30 : 0x57) + x, func_81306F20(arg0) + y - 0x20, ST(f32, 0x137BC), ST(s32, 0x137E8));
    func_81600A34(arg1, (void *)0x494E4449, 0, rect[0], rect[1], rect[2], rect[3]);
    func_81600A34(arg1, arg0, dirty, x, y, 0x224, 0x9F);
}
#undef ST
#endif
