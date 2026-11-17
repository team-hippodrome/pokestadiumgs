#include "229E0.h"

#ifdef VERSION_US
extern s32 D_80090B94;
extern void func_8002AAFC(s32);
extern u32 func_800194A0(void);
extern void func_800314D4(s32);
extern s32 D_80090B98;

// func_800289B0 shifts these 24 IDs toward the oldest entry.
u32 gAudioRecentSoundHistory[24];

u8 Audio_LookupScaledRatio(u16 numerator, u16 denominator) {
    s32 scaled = (numerator * 48) / denominator;
    s32 index = 0;
    for (; index < 6; index++) {
        if (D_8009210C[index * 2] >= scaled) {
            break;
        }
    }
    return D_8009210C[index * 2 + 1];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/290C0/func_80028540.s")

void Audio_SwapSoundCandidates(u8 *arg0, u8 *arg1) { if (*arg0 != *arg1) { u8 temp = *arg0; *arg0 = *arg1; *arg1 = temp; } }

u16 Audio_FilterRecentSoundId(u16 arg0) {
    s32 i;
    for (i = 0; i < 24; i++) {
        if (arg0 == D_800D1AD8[i]) return 0;
    }
    return arg0;
}

/* mkdraft:func_800289B0 begin */
void func_800289B0(u16 arg0) {
    s32 i;

    for (i = 0; i < 23; i++) {
        gAudioRecentSoundHistory[i] = gAudioRecentSoundHistory[i + 1];
    }
    gAudioRecentSoundHistory[23] = arg0;
}
/* mkdraft:func_800289B0 end */

void Audio_RemoveRecentSoundAt(u16 arg0) {
    u32 i;
    for (i = arg0; i > 0; i--) D_800D1AD8[i] = D_800D1AD8[i - 1];
    D_800D1AD8[0] = 0;
}

extern u8 D_800D1B40[];

s32 func_80028ADC(const void *arg0) {
 u32 i;
 u32 j;
 u16 count;
 u16 sound;
 count = (u16)(((const u16 *)arg0)[0] & 0xFF);
 for (i = 0; i < count; i++) {
  D_800D1B40[i] = i + 1;
 }
 for (i = 0; i < count * 3; i++) Audio_SwapSoundCandidates(D_800D1B40, (func_800194A0() % count) + D_800D1B40);
 for (i = 0; i < count; i++) {
  sound = Audio_FilterRecentSoundId(((const u16 *)arg0)[D_800D1B40[i]]);
  if (sound != 0) { func_800289B0(sound); return (u16)sound; }
 }
 for (i = 0; i < 24; i++) {
  for (j = 1; j <= count; j++) {
   sound = ((const u16 *)arg0)[j];
   if ((u32)sound == D_800D1AD8[i]) {
    Audio_RemoveRecentSoundAt(i); func_800289B0(sound); return sound;
   }
  }
 }
 return 0;
}
void func_80028CA8(const void *sound_candidates) {
    s32 v0;
    s32 masked;

    v0 = func_80028ADC(sound_candidates);
    masked = v0 & 0xFFFF;
    if (v0 != 0) {
        func_800314D4(masked);
    }
}

void func_80028CA8_padding(void) {}

void func_80028CA8_padding2(void) {}

s32 func_80028CE8(void *arg0, s32 arg1) {
    struct Node { u32 a; u32 b; struct Node *next; };
    struct Root { u32 a; struct Node *next; };
    struct Node *node = ((struct Root *)arg0)->next;
    s32 i = 0;
    while (i != arg1) {
        if (node->next == 0) return (s32)node;
        node = node->next;
        i++;
    }
    return (s32)node;
}

/* mkdraft:func_80028D9C begin */
extern s32 func_80028CE8(void *arg0, s32 arg1);
extern void func_80028CA8(const void *sound_candidates);



void func_80028D9C(void *arg0) {
    struct Node { u32 a; u32 b; struct Node *next; };
    struct Root { u32 a; struct Node *next; };
    u32 pad0;                        // FAKE: unused; holds frame word 0x2c above count; diff score 24 without it.
    u32 count;
    u32 pad1[3];                     // FAKE: unused; holds frame words 0x24-0x1c below count; diff score 66 without it.
    struct Node *found;              // FAKE: second name for the matched node; keeps it in a stack home across the
                                     // two calls so uopt emits one reload after func_80028CA8; diff score 100 without it.
    struct Node *node;

    node = ((struct Root *)arg0)->next;
    count = 1;
    if (node->a == 0) {
loop:
        if (node->next != 0) {
            node = node->next;
            count++;
            if (node->a == 0) {
                goto loop;
            }
        }
    }
    found = node;
    func_80028CA8((const void *)((struct Node *)func_80028CE8(arg0, func_800194A0() % count))->b);
    node = found;
    ((struct Root *)arg0)->a++;
    if (node->next != 0 && ((struct Root *)arg0)->a >= node->a) {
        ((struct Root *)arg0)->next = node->next;
    }
}
/* mkdraft:func_80028D9C end */

s32 func_80028E60(u32 arg0)
{
  u8 *ptr;
  int value;
  u32 mask;
  s32 result;
  arg0--;
  ptr = &D_800D2660[arg0 >> 3];
  value = *ptr;
  mask = 1U << (arg0 & 7);
  result = value & mask;
  value |= mask;
  if ((mask = result) != 0U)
  {
    return 1;
  }
  *ptr = value;
  return mask != (mask = 0);
}

void func_80028EA8(void) { extern u8 D_80091B90[]; func_80028D9C(D_80091B90); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/290C0/func_80028ECC.s")

void Audio_ResetQueueAndBitmap(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        D_800D1A90[i] = 0;
    }
    D_80091A24 = 0;
    D_80091A28 = 0;
    for (i = 0; i < 32; i++) {
        D_800D2660[i] = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/290C0/func_8002A25C.s")

void func_8002A7A8(s32 arg0, s32 arg1) { D_800D2650[0] = arg0; D_800D2650[1] = arg1; D_800D2650[3] = D_80090BA0; if (D_80090BA0 == 1) D_800D2650[2] = 1; else D_800D2650[2] = 0; D_800D2650[4] = 0; *(u32 *)(D_800D2650 + 8) = 0; }

void func_8002A7E8(s32 arg0) {
    if (arg0 != 0) {
        D_80091A0C = 1;
        return;
    }
    D_80091A0C = 0;
}

void func_8002A80C(s32 arg0) {
    if (arg0 != 0) {
        D_80091A10 = 1;
        return;
    }
    D_80091A10 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/290C0/func_8002A830.s")

void func_8002A9C0(s32 arg0) {
    D_800D2630 = arg0;
}

void func_8002A9CC(s32 arg0) {
    D_800D2634 = arg0;
}

void func_8002A9D8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        osSyncPrintf("party[%d]", i);
        osSyncPrintf("   select_waza = %d\n", D_800D1B78[i][1]);
        osSyncPrintf("   mons = %d\n", D_800D1B80[i][0]);
        osSyncPrintf("   waza = %d\n", D_800D1B80[i][3]);
        osSyncPrintf("   waza = %d\n", D_800D1B80[i][4]);
    }
}

void func_8002AAD0(u8 arg0) {
    if (arg0) {
        D_80091A18 = 1;
        return;
    }
    D_80091A18 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/290C0/func_8002AAFC.s")

void func_8002B1A0(void) { func_8002A25C(); func_80024180(0, 0); }

/* mkdraft:func_8002B1CC begin */
extern u16 D_80091900[];
extern u8 D_80091A14;
extern s32 func_800265B0();
extern void func_800314D4(s32);
extern void func_80031530(u16);



void func_8002B1CC(void) {
    s32 index;
    s32 sel;

    D_80091A14 = 1;
    if (D_80090B98 == 0x28) {
        func_800314D4(0x3117);
        return;
    }
    index = D_80090B94;
    if ((index < 0xA) || (index >= 0x10)) {
        if (D_80090B98 == 0xA) {
            func_800314D4(0x310C);
            func_80031530(6);
            index = D_80090B94;
        } else if (D_80090B98 == 0xB) {
            func_800314D4(0x3116);
            func_80031530(6);
            index = D_80090B94;
        }
        if (index == 0x10) {
            func_800314D4(0x3115);
            return;
        }
        if (index == 0x11) {
            func_800314D4(0x3114);
            return;
        }
    }
    // FAKE: empty block; it ends the outer if's basic block. Without it the tail
    // D_80090B98 load is `lui a1; lw a1,(a1)` instead of `lui v0; lw a1,(v0)`; diff score 10.
    if (1) {
    }
    sel = D_80090B98;
    if ((sel == 0xB) && ((index < 0xA) || (index >= 0x10))) {
        sel = 0xA;
    }
    // FAKE: ^ 0 is a no-op. Without it IDO keeps index in a2 rather than v1 for the rest of
    // the tail; diff score 95.
    index = func_800265B0(index ^ 0, sel);
    if (index < 0) {
        index = 0;
    }
    func_800314D4(D_80091900[index]);
}
/* mkdraft:func_8002B1CC end */

// The two mode dispatch tables are shared with the original loaded rodata.
void func_8002B2FC(void) {
    D_80091A18 = 0;
    if (D_80090B94 != 19) {
        func_80023A3C(70, 0, 0);
    }
    func_80023A3C(3, 0, 0);
    if (D_80090B94 != 19) {
        func_80021ED8(38);
    }
    if (D_800D1B78[0][9] != 0) {
        switch (D_80090B94) {
        case 14:
            func_800314D4(8362);
            return;
        case 12:
            func_800314D4(8361);
            return;
        case 13:
            func_800314D4(8360);
            return;
        case 10:
            switch (D_80090B98) {
            case 1: case 4: case 7: case 10: case 12: case 13: case 17: case 20: case 23:
                func_800314D4(8360);
                return;
            }
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            if (D_80090B98 == 8) {
                func_800314D4(8359);
                return;
            }
            break;
        }
    }
    func_800314D4(8358);
}
void func_8002B43C(void) {
    D_80091A18 = 0;
    func_8002AAFC(0);
    func_80023A3C(3, 0, 0);
    func_800314D4(0x2226);
}

void func_8002B47C(s32 arg0, s32 arg1) {
    D_80091B08 = arg0;
    D_80091B0C = arg1;
}

void Audio_RequestSlot(u8 slot) {
    if (D_80091AC8 != 0) {
        if (D_800D1B3B == 0)
        {
            func_800314D4(0x2028);
        }
        if (D_800D2640[slot] < 2U) {
            D_800D269E[slot] = 1;
        }
    } else {
        if (D_800D2640[slot] < 2U) {
            if (*(D_800D269E + slot) != 0) {
                if (D_800D1B3B == 0) {
                    func_80028CA8(D_80091F00);
                }
            } else if (D_800D1B3B == 0) {
                func_80028CA8(D_80091EF8);
            }
            *(D_800D269E + slot) = 1;
        } else if (D_800D1B3B == 0) {
            func_80028CA8(D_80091EEC);
        }
    }
    D_80091AC8 = 1;
}

#endif
