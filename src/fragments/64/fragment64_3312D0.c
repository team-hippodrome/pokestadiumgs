#include "global.h"


#ifdef VERSION_US
typedef struct unk_func_87F0E660_00 {
    u8 unk_00[0x5C];
} unk_func_87F0E660_00;

typedef struct unk_func_87F0E660_678 {
    u8 unk_00[0x10];
} unk_func_87F0E660_678;

typedef struct unk_func_87F0E660 {
    /* 0x000 */ unk_func_87F0E660_00 unk_000[18];
    /* 0x678 */ unk_func_87F0E660_678 unk_678[3];
    /* 0x6A8 */ u8 unk_6A8[0x18];
} unk_func_87F0E660; // size = 0x6C0

void func_87F0E660(unk_func_87F0E660 *arg0) {
    s32 i;
    s32 j;
    unk_func_87F0E660 *entry;

    for (i = 0; i < 4; i++) {
        entry = &arg0[i];
        for (j = 0; j < 18; j++) {
            if (arg0[i].unk_000[j].unk_00[0]) {} // karodo
        }
        for (j = 0; j < 3; j++) {
            if (arg0[i].unk_678[j].unk_00[0]) {} // karodo
        }
        if (entry) {} // karodo
    }
}

extern void _bcopy(void *, void *, s32);
s32 func_87F0E6B8(u8 *arg0, s8 arg1, u8 *arg2, s32 arg3, u8 arg4) {
    s32 found = 0;
    s32 i;

    for (i = 0; i < arg3; i++, arg2 += 0x58) {
        s32 ok = 0;

        if (arg2[0x1E] & 1) {
            continue;
        }
        if (arg4 == arg2[0]) {
            if (arg4 == 0x19) {
                if (arg2[0x1E] & 2) {
                    ok = 1;
                } else if (arg2[0x1C] >= 0xFA) {
                    ok = 1;
                }
            } else {
                ok = 1;
            }
            if (ok) {
                arg0[0] = i + 1;
                arg0[1] = arg1;
                _bcopy(arg2, arg0 + 4, 0x58);
                found = 1;
            }
            break;
        }
    }
    return found;
}

extern s32 func_8005CAA4(s32);
extern s32 main_pool_alloc(s32, s32);
extern s32 main_pool_try_free(s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s8 func_80062390(void *, s32, u8 *);
extern s32 func_80062304(u8 *);
extern s32 func_87F0E6B8(u8 *, s8, u8 *, s32, u8);
s32 func_87F0E790(void *arg0, void *arg1, u8 arg2) {
    void *block;
    u8 *handle;
    s32 count;
    s32 result;

    result = 0;
    count = func_8005CAA4(0x20);
    block = (void *)main_pool_alloc(count * 0x58, 0);
    handle = func_8006218C(0x20, (s32)arg0, 0, 0);
    if (handle != NULL) {
        if (func_87F0E6B8(arg1, -1, block,
                          func_80062390(block, count, handle), arg2) != 0) {
            result = 1;
        }
        func_80062304(handle);
    }
    main_pool_try_free((s32)block);
    return result;
}

/* mkdraft:func_87F0E84C begin */
extern s32 Deck_ReadEntries(u8 *buffer, s32 remaining, u8 *handle);
extern s32 GbSave_GetRecordCapacity(s32 selector);
extern s32 func_8005CB38(s32 arg0, s32 arg1);


s32 func_87F0E84C(void *arg0, void *arg1, u8 arg2) {
    s32 i;
    s32 block;
    s32 count;
    s32 cap;
    s32 res;
    s32 read;
    u8 *handle;

    res = 0;
    count = func_8005CB38((s32) arg0, 0x21);
    for (i = 0; i < count; i++) {
        if (res == 0) {
            cap = GbSave_GetRecordCapacity(0x21);
            block = main_pool_alloc(cap * 0x58, 0);
            handle = func_8006218C(0x21, (s32) arg0, i, 0);
            if (handle != 0) {
                read = Deck_ReadEntries((u8 *) block, cap, handle);
                if (func_87F0E6B8((u8 *) arg1, (s8) i, (u8 *) block, read, arg2) != 0) {
                    // FAKE: the do/while gives the assignment its own basic block, which
                    // makes IDO 7.1 colour the callee-saved registers as retail does
                    // (i=$s0, cap=$s1, block=$s2, handle=$s3, res=$s4, count=$s5,
                    // 0x58=$s6, arg0=$s7, arg1=$fp) and spill the u8 arg2 to 0x53($sp),
                    // reloaded after Deck_ReadEntries. Written as a plain `res = 1;`
                    // the identical instruction sequence gets a different assignment
                    // (diff score 154).
                    do {
                        res = 1;
                    } while (0);
                }
                func_80062304(handle);
            }
            main_pool_try_free(block);
        }
    }
    return res;
}
/* mkdraft:func_87F0E84C end */

extern u8 D_87F113D0[];
extern s32 func_800625E0(s32, s32);
void func_87F0E978(u8 *arg0, s32 arg1) {
    arg0[0] = 0;
    arg0[4] = D_87F113D0[arg1];
    func_800625E0((s32)(arg0 + 0x38), arg0[4]);
    if (arg0[4] == 0x19) {
        arg0[0x22] |= 2;
    }
}

extern s32 func_87F0E790(void *, void *, u8);
extern s32 func_87F0E84C(void *, void *, u8);
extern void func_87F0E978(u8 *, s32);
void func_87F0E9D8(void *arg0, void *arg1, s32 arg2) {
    u8 value;
    value = D_87F113D0[arg2];
    if ((func_87F0E790(arg1, arg0, value) == 0) && (func_87F0E84C(arg1, arg0, value) == 0)) {
        func_87F0E978(arg0, arg2);
    }
}

#define NULL ((void *)0)

typedef struct {
    void *unk_00[12];
    struct {
        u8 unk_00[0x5C];
    } unk_30[18];
    u8 unk_6A8[0x18];
} Elem;

extern u32 func_8003570C(void);
extern s8 D_87F113E4[];
extern u8 D_87F11408[];
extern u8 D_87F1142C[];
extern u8 D_800CE060[];



void func_87F0EA40(Elem *arg0, u8 arg1)
{
  s32 i;
  s32 row;
  u8 *state;
  s32 m;
  s32 selected;
  void *records[3];
  s32 found;
  s8 best0;
  s8 best1;
  state = D_800CE060;
  for (i = 0; i < 4; i++)
  {
    for (row = 0; row < 12; row++)
    {
      for (m = 0; m < 3; m++)
      {
        if (arg1 & (1 << i))
        {
          if (D_87F113E4[(row * 3) + m] != (-1))
          {
            records[m] = (void *) (&arg0[i].unk_30[D_87F113E4[(row * 3) + m]].unk_00[0]);
          }
          else
          {
            records[m] = (void *) 0;
          }
        }
        else
          if (D_87F113E4[(row * 3) + m] != (-1))
        {
          records[m] = (void *) ((((u8 *) arg0) + (D_87F113E4[(row * 3) + m] * 0x5C)) + (0, 0x1B00)); // FAKE: diff score 20 without the comma; it flips the addu operand order.
        }
        else
        {
          records[m] = (void *) 0;
        }
      }

      if ((arg1 & (1 << i)) && ((*((u16 *) (state + 6))) & 0xB))
      {
        if (1) // FAKE: diff score 555 without this wrapper; it isolates the selection diamond for the allocator.
        {
          if ((*((u16 *) (state + 6))) & 8)
          {
            selected = 2;
          }
          else
            if ((*((u16 *) (state + 6))) & 2)
          {
            selected = 0;
          }
          else
          {
            selected = 1;
          }
        }
      }
      else
      {
        found = 1;
        for (m = 0; m < 3; m++)
        {
          if ((records[m] != ((void *) 0)) && ((*((s8 *) records[m])) != 0))
          {
            found = 0;
            break;
          }
        }

        if (found)
        {
          selected = ((((f32) func_8003570C()) / 4294967296.0f) < 0.5f) ? (0) : (1);
        }
        else
        {
          for (m = 0; m < 3; m++)
          {
            if ((records[m] == ((void *) 0)) || ((*((s8 *) records[m])) == 0))
            {
              continue;
            }
            selected = m;
            best0 = *((s8 *) records[m]);
            best1 = *((s8 *) (((u8 *) records[m]) + 1));
          }

          for (m = 0; m < 3; m++)
          {
            if ((records[m] == ((void *) 0)) || ((*((s8 *) records[m])) == 0))
            {
              continue;
            }
            if (((*((s8 *) (((u8 *) records[m]) + 1))) < best1) || (((*((s8 *) (((u8 *) records[m]) + 1))) == best1) && ((*((s8 *) records[m])) < best0)))
            {
              selected = m;
 if (0) { } // FAKE: diff score 1279 without it; it keeps retail s-register coloring in this loop.
              best0 = *((s8 *) records[m]);
              best1 = *((s8 *) (((u8 *) records[m]) + 1));
            }
          }

        }
      }
      if (records[selected] == ((void *) 0))
      {
        selected = 0;
      }
      if ((D_87F11408[(row * 3) + selected] == 0) && ((*((s8 *) records[selected])) == 0))
      {
        selected = 0;
      }
      arg0[i].unk_00[row] = records[selected];
    }

    state += 0x28;
  }

}

void func_87F0EA40(Elem *arg0, u8 arg1);
extern void func_87F0E660(unk_func_87F0E660 *);
void func_87F0EDDC(void *arg0, u8 arg1) {
    func_87F0EA40(arg0, arg1);
    func_87F0E660(arg0);
}

typedef struct unk_func_87F0EE0C {
    u8 unk_000[1704];
    u8 unk_6A8[16];
    u8 unk_6B8_7 : 1;
    u8 unk_6B8_6 : 1;
    u8 unk_6B8_5 : 6;
    u8 unk_6B9[7];
} unk_func_87F0EE0C;
extern s32 func_8005D8C0(void);
extern void func_8005D9E0(s32, void *);
void func_87F0EE0C(unk_func_87F0EE0C *arg0) {
    s32 mask;
    s32 i;
    u8 *entry;

    mask = func_8005D8C0();
    for (i = 0; i < 4; i++) {
        arg0[i].unk_6B8_7 = ((1 << i) & mask) > 0;
        arg0[i].unk_6B8_6 = 0;
        func_8005D9E0(i, arg0[i].unk_6A8);
    }
    entry = (u8 *)(arg0 + 4);
    for (i = 0; i < 18; i++) {
        func_87F0E978(entry, i);
        entry += 92;
    }
}

extern u32 D_87F15BB0;
extern void fragment3_main(void *);
extern void func_81A005F0(void *);
void func_87F0EECC(void) { fragment3_main(&D_87F15BB0); func_81A005F0(&D_87F15BB0); }

void func_87F0EEFC(void *arg0, s32 arg1) {
    u8 *base;
    u8 *ptr;
    s32 i;
    s32 index;

    base = (u8 *)arg0 + arg1 * 0x6C0;
    *((u8 *)arg0 + (u32)arg1 * 0x6C0 + 0x6B8) &= 0xFF7F; // FAKE: recomputes base; 0xFF7F on a byte clears bit 7
    index = arg1 & -1 & -1 & -1; // FAKE: arithmetic no-op that keeps arg1 in another register
    i = 0x6A8; // FAKE: the offset goes through the loop counter
    func_8005D9E0(arg1, base + i);
    base = (u8 *)arg0 + index * 0x6C0;
    ptr = base + 0x30;
    for (i = 0; i < 18; i++) {
        func_87F0E978(ptr, i);
        ptr += 0x5C;
    }
}

extern s32 func_8005A0B4(s32);
extern s32 func_8005DED8(s32);
extern void func_87F0E9D8(void *, void *, s32);
extern void func_87F0EEFC(void *, s32);
extern void func_87F0EDDC(void *, u8);
extern u64 osGetTime(void);
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);

typedef struct unk_func_87F0EFA0 {
    /* 0x000 */ u8 unk_000[18][0x5C];
    /* 0x678 */ u8 unk_678[0x40];
    /* 0x6B8 */ u32 unk_6B8_7 : 1;
                u32 unk_6B8_6 : 1;
                u32 unk_6B8_29_0 : 30;
    /* 0x6BC */ u8 unk_6BC[4];
} unk_func_87F0EFA0; // size = 0x6C0



void func_87F0EFA0(unk_func_87F0EFA0 *arg0, u8 arg1, s32 arg2) {
    s32 i;
    u8 *port;

    osGetTime();
    main_pool_push_state(0x6D47426D);
    for (i = 0, port = (u8 *)arg0; i < 4; i++, port += 0x6C0) {
        if (((unk_func_87F0EFA0 *)port)->unk_6B8_6) {
            continue;
        }
        if (arg2 == 0) {
            // FAKE: empty then-branch. Without it IDO colors arg2/arg0/arg1
            // as s7/s5/s6 and puts the 0x6B8 loads in t5/t7 instead of t8.
        } else if (((arg1 & (1 << i)) != 0) && func_8005A0B4(i)) {
            ((unk_func_87F0EFA0 *)port)->unk_6B8_7 = 1;
            ((unk_func_87F0EFA0 *)port)->unk_6B8_6 = 1;
            func_8005DED8(i);
        }
        if (((unk_func_87F0EFA0 *)port)->unk_6B8_7 && (arg1 & (1 << i)) != 0 && arg2 != 0) {
            s32 j;
            u8 *entry;

            for (j = 0, entry = (u8 *)arg0 + i * 0x6C0 + 0x30; j < 18; j++, entry += 0x5C) {
                func_87F0E9D8(entry, (void *)i, j);
            }
        } else {
            func_87F0EEFC(arg0, i);
        }
    }
    func_87F0EDDC(arg0, arg1);
    main_pool_pop_state(0x6D47426D);
}

extern void func_8005777C();

void func_87F0F118(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_8005777C();
        var_s0 += 1;
    } while (var_s0 != 0x10);
}

extern s32 func_8005A364();
extern void func_87F0EEFC(void *, s32);
void func_87F0F158(void *arg0, s32 arg1) {
    if (((*(u32 *)((u8 *)arg0 + arg1 * 0x6C0 + 0x6B8) >> 31) != 0) &&
        (func_8005A364(arg1) == 0)) {
        func_87F0EEFC(arg0, arg1);
    }
}

extern void func_87F0F3E4(void *);
extern s32 func_8005A0B4(s32);
extern void func_87F0EEFC(void *, s32);
extern void func_87F0F390(void *);
void func_87F0F1C0(void *arg0, s32 arg1) {
    func_87F0F3E4(arg0);
    if (((*(u32 *)((u8 *)arg0 + arg1 * 0x6C0 + 0x6B8) >> 31) != 0) &&
        (func_8005A0B4(arg1) == 0)) {
        func_87F0EEFC(arg0, arg1);
    }
    func_87F0F390(arg0);
}

extern s32 func_8006236C(u8 *, s32);
extern void func_8006249C(void *, s32, u8 *);
void func_87F0F234(s32 arg0, s8 *arg1) {
    struct { u8 *handle; u32 unused[2]; } scratch;
    s32 type;
    s32 slot;

    if (arg1[1] == -1) {
        type = 0x20;
        slot = 0;
    } else {
        type = 0x21;
        slot = arg1[1];
    }
    scratch.handle = func_8006218C(type, arg0, slot, 2);
    if (scratch.handle != NULL) {
        func_8006236C(scratch.handle, arg1[0] - 1);
        func_8006249C(arg1 + 4, 1, scratch.handle);
        func_80062304(scratch.handle);
    }
}

extern s32 func_81A00074(u8 *, s32);
typedef struct unk_func_87F0F2B8_Item {
    /* 0x00 */ u8 unk_00[0x30];
    /* 0x30 */ s8 unk_30;
    /* 0x31 */ u8 unk_31[0x2B];
} unk_func_87F0F2B8_Item; // size = 0x5C

typedef struct unk_func_87F0F2B8 {
    /* 0x000 */ unk_func_87F0F2B8_Item items[18];
    /* 0x678 */ u8 unk_678[0x40];
    /* 0x6B8 */ u32 unk_6B8_flag : 1;
    /* 0x6BC */ u8 unk_6BC[4];
} unk_func_87F0F2B8; // size = 0x6C0

s32 func_87F0F2B8(unk_func_87F0F2B8 *ports, s32 port) {
    s32 i;
    s32 result = 0;

    osGetTime();
    if (ports[port].unk_6B8_flag) {
        for (i = 0; i < 18; i++) {
            if (ports[port].items[i].unk_30 != 0) {
                func_87F0F234(port, &ports[port].items[i].unk_30);
            }
        }
        if (func_81A00074((u8 *)&D_87F15BB0, port)) {
            result = 1;
        }
    } else {
        result = 1;
    }
    return result;
}

s8 GbTower_SetPollMask(s32);
extern void func_80057944(s32);
void func_87F0F390(void *arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_80057944(var_s0 & 0xFF);
        var_s0 += 1;
    } while (var_s0 != 4);
    (*(s8 *)((u8 *)(arg0) + (0x2178))) = GbTower_SetPollMask(0);
}

extern void func_87F0F118(void);
extern void func_87F0F158(void *, s32);
void func_87F0F3E4(void *arg0) {
    s32 i;
    GbTower_SetPollMask(*(u8 *)((u8 *)arg0 + 0x2178));
    func_87F0F118();
    i = 0;
    do {
        func_87F0F158(arg0, i);
        i += 1;
    } while (i != 4);
}

extern void func_81A0022C(void *);
void StageLoader_UpdateSegments(void) {
    func_81A0022C(&D_87F15BB0);
}

extern u32 D_87F15BB8;
u32 func_87F0F468(void) {
    return D_87F15BB8;
}
#pragma C_FUNCTION_PADDING(12)
#endif
