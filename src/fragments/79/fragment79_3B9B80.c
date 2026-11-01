#include "global.h"


#ifdef VERSION_US
extern u8 func_84154B24(void);
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B9B80/func_8414A2F0.s")

extern u8 *D_841951F8[];
u8 *func_8414A3A0(u8 arg0) {
    return D_841951F8[arg0] + 0x49C;
}

s32 func_8414A3C0(u8 arg0, u32 arg1) {
    return (*(u32 *)(D_841951F8[arg0] + 0x49C) & arg1) != 0;
}

extern void func_8414A2F0(s32, u8);
void func_8414A3E8(void) {
    s32 i;
    u8 **p;
    p = D_841951F8;
    i = 0;
    do {
        func_8414A2F0(i & 0xFF, (*p)[0x49A]);
        i++;
        p++;
    } while (i != 2);
}

extern void _bzero(void *, s32);
void func_8414A440(u8 *arg0, u8 arg1, u8 arg2) {
    s32 i;
    u8 *var_s0;
    u8 *temp_s2;

    *(s32 *)(arg0 + 0x10) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x0C) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x24) = 0x80000000;
    var_s0 = arg0 + 0x28;
    i = 0;
    do {
        temp_s2 = var_s0;
        _bzero(var_s0, 0x40);
        i += 0x40;
        var_s0 += 0x40;
        temp_s2[arg1 + 6] = arg2;
    } while (i != 0x80);
}

extern void _bzero(void *, s32);
void func_8414A4E4(u8 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 i;
    u8 *var_s0;
    u8 *temp_s2;

    *(s32 *)(arg0 + 0x10) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x0C) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x24) = 0x80000000;
    var_s0 = arg0 + 0x28;
    i = 0;
    do {
        temp_s2 = var_s0;
        _bzero(var_s0, 0x40);
        i += 0x40;
        var_s0 += 0x40;
        temp_s2[arg1 + 2] = arg2;
        temp_s2[arg1 + 6] = arg3;
    } while (i != 0x80);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B9B80/func_8414A59C.s")

/* mkdraft:func_8414B574 begin */
extern u8 D_8419D7C0[];
extern u8 *D_841951F8[];
extern u8 *D_84195208[];
extern u8 func_84154B24(void);
extern void func_84149294(u8);
extern void func_8414A440(u8 *, u8, u8);
extern void func_8414A4E4(u8 *, u8, u8, u8);
extern void func_8414EFD0(u8 *);
extern void func_8414EFF0(u8 *);
extern void func_8414A59C(u8 *, u8);
extern s32 func_8414A3C0(u8, u32);
extern s32 func_8414C924(u8, u8);

// 0x58-byte record stride: the target indexes the same base with a
// /4 quotient (record) and a %4 remainder (byte within the record).
typedef struct { u8 unk00[0x58]; } TeamRecord;



void func_8414B574(void)
{
  s32 temp_v0;
  s32 var_s2;
  u8 *var_s0;
  u8 *temp_t0;
  u8 **new_var;
  temp_v0 = func_84154B24();
  if (func_8414A3C0((u8) temp_v0, 4) == 0)
  {
    func_84149294(1 - temp_v0);
  }
  // Comma init/incr keeps both walkers in one for-clause; this is what lets the
  // loop-invariant &D_841951F8 / &D_84195208 bases materialize before the
  // var_s0 / var_s2 initializations in the target's prologue.
  for (var_s0 = D_8419D7C0, var_s2 = 0; var_s2 != 0x18; var_s2++, var_s0 += 0xA8)
  {
    if ((*var_s0) & 1)
    {
      // FAKE: pointer-to-pointer alias retained only for codegen; the plain
      // `temp_t0 = D_841951F8[temp_v0]` scores 320.
      temp_t0 = *(new_var = &D_841951F8[temp_v0]);
      if ((var_s2 / 4) == temp_t0[0xA])
      {
        if (((&D_84195208[temp_v0][var_s2 % 4])[9] & 0x3F) > 0)
        {
          func_8414A440(var_s0, temp_v0, (&D_84195208[temp_v0][var_s2 % 4])[5]);
        }
        else
        {
          func_8414A440(var_s0, temp_v0, 0xA5);
        }
        func_8414EFD0(var_s0);
        func_8414A59C(var_s0, temp_v0);
      }
      else
      {
        func_8414A4E4(var_s0, temp_v0, var_s2 / 4, ((TeamRecord *) temp_t0)[var_s2 / 4].unk00[(var_s2 % 4) + 0x1A]);
        if ((func_8414A3C0(temp_v0, 2) == 0) || (func_8414C924(var_s2, 4) != 0))
        {
          func_8414EFF0(var_s0);
          func_8414A59C(var_s0, temp_v0);
        }
      }
    }
  }
}
/* mkdraft:func_8414B574 end */

extern u8 D_8419D7C0[];
// D_8419D7C0 holds 24 0xA8-byte records; func_8414BEE8 clears all 0xFC0 bytes.
void func_8414B73C(void) {
    s32 var_s1;
    s32 i;
    u8 *entry;

    var_s1 = func_84154B24();
    for (i = 0; i < 24; i++) {
        entry = &D_8419D7C0[i * 0xA8];
        if (entry[0] & 1) {
            if (!(entry[0] & 2) || func_8414A3C0(var_s1, 2) == 0) {
                func_8414FB24(entry);
            }
        }
    }
}

extern u8 *D_84195200[];
extern u32 func_8414A258(void);
extern u8 * D_84195208[];
s32 func_8414B7BC(u8 side) {
    s32 result;

    result = 0;
    if (D_84195200[side][0x24] & 0x20) {
        result = func_8414A258() * 255;
    } else if (D_84195200[side][0x24] & 7) {
        result = func_8414A258() * 128;
    } else if (D_84195200[side][0x24] & 8) {
        if (D_84195208[side][0x11] & 1) {
            result = -(D_84195208[side][0x14] * func_8414A258() * 32);
        }
    }
    return result;
}

extern u32 func_8414A258(void);
extern u8 * D_84195208[];
s32 func_8414B878(u8 side) {
    u8 other;
    s32 result = 0;

    if (D_84195208[side][0xD] & 0x10) {
        if ((D_84195208[side][0x11] & 0x80) && (D_84195208[other = 1 - side][0xD] & 0x10)) {
            if (D_84195208[side][0x17] == 1) {
                result = -(func_8414A258() << 9);
            } else {
                result = func_8414A258() << 9;
            }
        } else {
            result = -((4 - D_84195208[side][0x17]) * (func_8414A258() << 7));
        }
    }
    return result;
}

/* mkdraft:func_8414B958 begin */
extern u8 *D_84195208[];
extern u32 func_8414A258(void);

s32 func_8414B958(u8 arg0) {
    u32 factor;
    s32 ret;

    ret = 0;
    if (D_84195208[arg0][0x24] >= 8) {
        factor = func_8414A258();
        ret = ((D_84195208[arg0][0x24] << 6) - 0x1C0) * factor;
    }
    return ret;
}
/* mkdraft:func_8414B958 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B9B80/func_8414B9D0.s")

void func_8414BDA0(void) {
    s32 i;
    u8 *entry;

    func_8414A3A0(func_84154B24());
    for (i = 0; i < 24; i++) {
        entry = D_8419D7C0 + i * 168;
        if (entry[0] & 1) {
            *(u32 *)(entry + 36) = *(u32 *)(entry + 20) + *(u32 *)(entry + 12) +
                                   *(u32 *)(entry + 24) + *(u32 *)(entry + 16);
        }
    }
}

extern void func_8414B574(void);
extern void func_8414B73C(void);
extern void func_8414B9D0(void);
extern void func_8414BDA0(void);
void func_8414BEB0(void) {
    func_8414B574();
    func_8414B73C();
    func_8414B9D0();
    func_8414BDA0();
}

extern u8 D_8419D7C0[];
void func_8414BEE8(void) {
    _bzero(D_8419D7C0, 0xFC0);
}

extern u8 func_80062D20(u8);
s32 func_8414BF10(u8 arg0, u8 arg1) {
    u8 temp_v0;

    temp_v0 = func_80062D20(arg1);
    if (D_841951F8[arg0][9] < 2) {
        if (temp_v0 == 7) return 0;
        if (temp_v0 == 0x62) return 0;
        if (temp_v0 == 0x72) return 0;
    }
    return 1;
}

extern s32 func_8413888C(u8);
extern u8 D_84195256[];
s32 func_8414BF94(u8 side, u8 slot) {
    s32 status;
    u8 *mon;
    u8 *move;

    status = func_8413888C(side);
    if (D_84195256[side * 0x18] == 5) {
        return 0;
    }
    mon = D_84195208[side];
    move = (u8 *)((u32)mon + slot);
    if (move[5] == 0) {
        return 0;
    }
    if (move[9] == 0 && status != 0) {
        return 0;
    }
    if (move[5] == mon[0x25]) {
        return 0;
    }
    return 1;
}

/* mkdraft:func_8414C048 begin */
extern u8 * D_8419520C[];

// Selectability test for one party slot of side arg0. Returns 0 when the side is
// in state 2, when arg1 is outside the party (bound test against party[8]), when
// the slot's u16 at 0x3E is zero, or when byte 0x1A + arg2 of its 0x58-byte
// record is zero. Unless the side is in state 5, the choice is also rejected by
// slot 1 of the D_8419520C record table carrying flag 0x80 in byte 0x11, by
// D_84195208[arg0][27] being nonzero, and by func_8414A3C0(arg0, 2) being
// nonzero.


s32 func_8414C048(u8 arg0, u8 arg1, u8 arg2) {
    // FAKE: u32 copy of arg1 that only steers codegen. The bound test below is
    // signed (slt), and the two record-stride products keep separate types
    // (mulu through slot, mul through arg1), so uopt emits retail's two shift
    // chains and leaves masked arg0 in $a0. Without the copy uopt promotes
    // arg1 into a fresh register, evicts arg0 to $a3 and the closest signed
    // spelling scores 76 differences; the closest copy-free source, an unsigned
    // bound test, scores 2 (sltu for slt).
    u32 slot = arg1;

    if (D_84195256[(u32)arg0 * 24] == 2) {
        return 0;
    }
    if ((s32)slot >= ((u8 *)D_841951F8[arg0])[8]) {
        return 0;
    }
    if (*(u16 *)(((u8 *)D_841951F8[arg0]) + slot * 88 + 62) == 0) {
        return 0;
    }
    if (((u8 *)D_841951F8[arg0])[arg1 * 88 + 26 + arg2] == 0) {
        return 0;
    }
    if (D_84195256[(u32)arg0 * 24] != 5) {
        /* D_8419520C names slot 1 of the two-pointer record table. */
        if ((*(u8 **)((u8 *)D_8419520C + -((s32)arg0 * (s32)sizeof(D_8419520C[0]))))[17] & 0x80) {
            return 0;
        }
        if (D_84195208[arg0][27] > 0) {
            return 0;
        }
        if (func_8414A3C0(arg0, 2) != 0) {
            return 0;
        }
    }
    return 1;
}
/* mkdraft:func_8414C048 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B9B80/func_8414C18C.s")

/* mkdraft:func_8414C3BC begin */
extern u32 func_8003570C(void);

u8 func_8414C3BC(void) {
    s32 i;
    s32 best;
    u32 bestVal;
    u8 *entry;

    best = -1;
    bestVal = 0;
    entry = D_8419D7C0;
    for (i = 0; i != 24; i++, entry += 0xA8) {
        u8 flag = *entry;
        if ((flag & 1) != 0 && (flag & 2) == 0) {
            if ((flag & 0x10) == 0) {
                u32 val = func_8003570C();
                if (bestVal < val) {
                    bestVal = val;
                    best = i;
                } else if (bestVal == val) {
                    if (best == -1 || (func_8003570C() & 1) != 0) {
                        best = i;
                    }
                }
            } else {
                if (best == -1) {
                    best = i;
                }
            }
        }
    }
    if (best < 0) {
        best = 0;
    }
    return best;
}
/* mkdraft:func_8414C3BC end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3B9B80/func_8414C4AC.s")

s32 func_8414C7D4(u8 arg0) {
    switch (func_80062D20(arg0)) {
        case 111:
        case 116:
            return 3;
        case 103:
            return 2;
        case 28:
        case 89:
        case 144:
            return 0;
        default:
            if (arg0 == 233) {
                return 0;
            }
            return 1;
    }
}

extern u8 *func_84154B0C(void);

// 0xCC-byte records at the base returned by func_84154B0C.
typedef struct unk_func_84154B0C {
    /* 0x00 */ u8 unk_00[0x42];
    /* 0x42 */ u16 unk_42;
    /* 0x44 */ u8 unk_44[0x88];
} unk_func_84154B0C; // size = 0xCC

// Comparator over the two record indices stored at bytes 0x19A/0x19B of func_84154B0C's base:
// ranks each by func_8414C7D4(arg0[6 + index]) and returns 1 when the second ranks below the first,
// 0 when it ranks above; on a tie, returns whether the second record's unk_42 is below the first's.
s32 func_8414C858(u8 *arg0) {
    u8 *records = func_84154B0C();
    u8 first_index = records[0x19A];
    u8 second_index = records[0x19B];
    u8 first;
    s32 second; // FAKE: s32 and narrowed only for the second comparison; diff score 120 without it.

    first = func_8414C7D4((arg0 + 6)[first_index]);
    second = func_8414C7D4((arg0 + 6)[second_index]);
    if (second < first) {
        return 1;
    }
    if (first < (u8)second) {
        return 0;
    }
    if (((unk_func_84154B0C *)records)[second_index].unk_42 < ((unk_func_84154B0C *)records)[first_index].unk_42) {
        return 1;
    }
    return 0;
}

s32 func_8414C924(u8 arg0, u8 arg1) {
    return (D_8419D7C0[arg0 * 0xA8] & arg1) != 0;
}

u8 *func_8414C960(u8 arg0) {
    return D_8419D7C0 + arg0 * 0xA8;
}

// Returns the next free 0x40-byte slot of the array at +0x28 in a 0xA8-byte
// D_8419D7C0 record and increments the record's slot count at +1.
u8 *func_8414C98C(u8 *record) {
    u8 *slot = record;

    slot += record[1] * 0x40;
    slot += 0x28;
    record[1]++;
    if (0) {} // karodo: diff score 200 without it.
    return slot;
}

extern u8 *func_84154B30(u8);
void func_8414C9AC(u8 *arg0, u8 arg1) {
    arg0[0] = arg1;
    arg0[2] = func_84154B30(0)[1];
    arg0[3] = func_84154B30(1)[1];
}
#endif
