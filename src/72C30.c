#include "global.h"


#ifdef VERSION_US
extern s32 func_87F0EFA0;
extern s32 (*func_80003240(s32 *))(s32 *);
void Minigame_ProcessPlayerEvents(u8 *arg0, u8 arg1, s32 arg2) {
    ((void (*)(u8 *, u8, s32))(void *)func_80003240(&func_87F0EFA0))(arg0, arg1, arg2);
}

extern s32 func_87F0EDDC;
void Minigame_UpdateControllerState(u8 *arg0, u8 arg1) {
    ((void (*)(u8 *, u8))(void *)func_80003240(&func_87F0EDDC))(arg0, arg1);
}

typedef union unk_func_800720A8_1 {
    u8 unk_00;
    struct {
        u8 unk_00 : 1;
        u8 unk_01 : 1;
        u8 unk_02 : 1;
        u8 unk_03 : 5;
    } unk_01;
} unk_func_800720A8_1;

typedef struct unk_func_800720A8_2 {
    s32 unk_00;
    u8 unk_04[18];
    unk_func_800720A8_1 unk_16;
    u8 unk_17;
} unk_func_800720A8_2;

typedef struct unk_func_800720A8 {
    s32 unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    unk_func_800720A8_2 unk_08[4];
    s32 unk_68;
    u8 unk_6C[2];
    u8 unk_6E;
} unk_func_800720A8;

void func_800720A8(unk_func_800720A8 *arg0) {
    s32 var_v0;

    arg0->unk_00 = 7;
    arg0->unk_68 = 0;
    arg0->unk_05 = 0;
    arg0->unk_06 = 0;
    arg0->unk_07 = 1;
    arg0->unk_6E = 0;
    for (var_v0 = 0; var_v0 < 4; var_v0++) {
        arg0->unk_08[var_v0].unk_00 = 0;
        arg0->unk_08[var_v0].unk_16.unk_00 &= 0xFF7F;
        arg0->unk_08[var_v0].unk_16.unk_01.unk_01 = 0;
        arg0->unk_08[var_v0].unk_16.unk_01.unk_02 = 0;
    }
}

extern u8 D_8012B3F6;
void Minigame_SetPlayerMask(s8 arg0) {
    D_8012B3F6 = 1 << arg0;
}

void Minigame_ResetPlayerSubstate(s32 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 1;
    arg0[3] = 1;
}

void func_80072184(u8 *arg0) {
    arg0[0x2183] = 5;
    arg0[0x2180] = 0;
    arg0[0x2181] = 1;
    // FAKE: s8 store to a byte Minigame_MapControllerButtons reads as u8 bit flags;
    // diff score 130 without it.
    *(s8 *)(arg0 + 0x2182) = 1;
    *(s32 *)(arg0 + 0x2184) = 0;
    func_800720A8((unk_func_800720A8 *)(arg0 + 0x2188));
    Minigame_ResetPlayerSubstate((s32 *)(arg0 + 0x21F8));
}

void Minigame_SetModeDefaults(u8 *arg0) {
    *(s16 *)(arg0 + 0) = 4;
    arg0[0xE] = 1;
}

void Minigame_MapControllerButtons(u8 *arg0, u8 *arg1) {
    arg1[0xE] = 0;
    if (arg0[0x2182] & 1) arg1[0xE] |= 1;
    if (arg0[0x2182] & 2) arg1[0xE] |= 2;
    if (arg0[0x2182] & 4) arg1[0xE] |= 4;
    if (arg0[0x2182] & 8) arg1[0xE] |= 8;
}



void func_80072264(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 mode;
    s32 i;

    *(s16 *)(arg1 + 0) = 8;
    if (((u32)*(u16 *)(arg0 + 0x21A6) >> 15) != 0 &&
        ((u32)*(u16 *)(arg0 + 0x21BE) >> 15) != 0 &&
        ((u32)*(u16 *)(arg0 + 0x21D6) >> 15) != 0 &&
        ((u32)*(u16 *)(arg0 + 0x21EE) >> 15) != 0) {
        arg1[2] = 2;
    } else {
        mode = *(s8 *)(arg0 + 0x2181);
        switch (mode) {
            case 0:
                arg1[2] = 1;
                break;
            case 1:
                arg1[2] = 2;
                break;
            case 2:
            case 3:
                arg1[2] = 3;
                break;
        }
    }
    arg1[0xE] = 0;
    i = 0;
    do {
        mode = 1 << (i + 4);
        if (((u32)*(u16 *)((arg0 + 0x21A6) + (24 * i)) >> 15) != 0 || arg2 == 0) {
            if (arg0[0x2182] & (1 << i)) {
                arg1[0xE] |= 1 << i;
            } else {
                arg1[0xE] |= mode;
            }
        }
        if (((u32)*(u16 *)((arg0 + 0x21BE) + (24 * i)) >> 15) != 0 || arg2 == 0) {
            if (arg0[0x2182] & (1 << (i + 1))) {
                arg1[0xE] |= 1 << (i + 1);
            } else {
                arg1[0xE] |= 1 << (i + 5);
            }
        }
        i += 2;
    } while (i != 4);
    arg1[0x14] = *(s8 *)(arg0 + 0x2183);
}

extern u8 func_87F097B0;
extern u8 D_801291E0;
extern s8 D_8012B363;
void Minigame_UpdatePlayerCounters(void) {
    ((void (*)(void *, s8))(void *)func_80003240(&func_87F097B0))(&D_801291E0, D_8012B363);
}

struct unk_D_8012B3E8;
// The unk_D_8012B3E8 typedef later in this file completes this tag; the code
// before it uses only D_8012B3E8's address.
extern struct unk_D_8012B3E8 D_8012B3E8;
extern s32 D_8012B364;
extern unk_func_800720A8 D_8012B368;
extern u8 D_8012B386;
extern u8 D_8012B39E;
extern u8 D_8012B3B6;
extern u8 D_8012B3CE;
extern u8 D_8AB00000[];
extern u8 D_8AC00000[];
extern u8 fragment43_ROM_START[];
extern u8 fragment44_ROM_START[];
extern u8 fragment45_ROM_START[];
extern u8 fragment46_ROM_START[];
extern void func_80072264(u8 *, u8 *, s32);
extern void Fragment_Load(s32, u8 *, u8 *);
extern s32 Fragment_LoadAndCall(s32, u8 *, u8 *, u32, u32);



void func_800723FC(s32 arg0, s32 *arg1)
{
  s32 *p364 = &D_8012B364;
  u8 *p386 = &D_8012B386;
  u8 *p39e = &D_8012B39E;
  u8 *p3b6 = &D_8012B3B6;
  int new_var;
  u8 *p3ce = &D_8012B3CE;
  u8 *out = (u8 *) ((u32) (&D_8012B3E8));
  if (((u8 *) (&D_801291E0))[0x2180] == 4)
  {
    *arg1 = 0xFF;
    return;
  }
  switch (*p364)
  {
    case 1:
      if (arg0 == 1)
    {
      *p364 = 0;
    }
      break;

    case 2:
      if (arg0 == 2)
    {
      arg0 = (((((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21A6)))) >> 15) != 0) + ((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21BE)))) >> 15) != 0)) + ((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21D6)))) >> 15) != 0)) + ((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21EE)))) >> 15) != 0));
      if (arg0 != 1)
      {
        if (out)
        {
        }
        func_80072264((u8 *) (&D_801291E0), out, ((((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21A6)))) >> 15) != 0) + ((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21BE)))) >> 15) != 0)) + ((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21D6)))) >> 15) != 0)) + ((((unsigned) (*((u16 *) (((u8 *) (&D_801291E0)) + 0x21EE)))) >> 15) != 0));
        Fragment_Load(((((u32) D_8AC00000) & 0x0FF00000) >> 20) - 0x10, fragment43_ROM_START, fragment44_ROM_START);
        Fragment_LoadAndCall(((((u32) D_8AB00000) & 0x0FF00000) >> 20) - 0x10, fragment45_ROM_START, fragment46_ROM_START, 0, (u32)out);

// FAKE: the two #line directives only renumber these statements for as1, which
// orders the pair of %hi bases hoisted before the first bnez, and the one in its
// delay slot, by .loc line: lowest line first, highest line in the delay slot.
// Retail schedules D_8012B39E's base first, so its assignment needs a line
// number below D_8012B386's even though it is written after them.
// diff score 3 without them.
#line 200
        if (out[0xF] == 0)
        {
          *p386 = (*p386 & 0xFF) | 0x80;
        }
        else
        {
          *p386 &= 0xFF7F;
        }
#line 96
        if (out[0xF] == 1)
        {
          *p39e = (*p39e & 0xFF) | 0x80;
        }
        else
        {
          *p39e &= 0xFF7F;
        }
        if ((u32) out[0xF] == 2)
        {
          *p3b6 = (*p3b6 & 0xFF) | 0x80;
        }
        else
        {
          *p3b6 &= 0xFF7F;
        }
        if (out[0xF] == 3)
        {
          *p3ce = (*p3ce & 0xFF) | 0x80;
        }
        else
        {
          *p3ce &= 0xFF7F;
        }

      }
      if (0)
      {
      }
      Minigame_UpdatePlayerCounters();
      if (out[0xF] == 9)
      {
      }
      if (!out)
      {
      }
    }
    else
    {
      *p364 = 0;
    }

  }

  // FAKE: the dead halfword product is load-bearing; it steers uopt's temp
  // coloring.  With a plain `== 0` the call's s0 base is materialized
  // before the bnel and the tail shifts.  diff score 27 without it.
  if ((*p364) == ((*((u16 *) (((u8 *) (&D_801291E0)) + 0x21BE))) * 0))
  {
    func_800720A8(&D_8012B368);
  }
  *arg1 = -1;
}

/* mkdraft:func_80072650 begin */
typedef struct unk_D_8012B3E8 {
    s16 unk_00;
    s8 unk_02;
    u8 pad_03[11];
    u8 unk_0E;
} unk_D_8012B3E8;

extern unk_D_8012B3E8 D_8012B3E8;
void Minigame_MapControllerButtons(u8 *arg0, u8 *arg1);



void func_80072650(u8 *arg0) {
    s32 var_v0;
    u32 temp_v0;

    temp_v0 = *(u32 *)(arg0 + 0x2184);
    if (temp_v0 == 3U) {
        goto block_3;
    }
    if (temp_v0 == 4U) {
        goto block_4;
    }
    if (temp_v0 == 5U) {
        goto block_3;
    }
    goto block_default;
block_3:
    D_8012B3E8.unk_00 = 6;
    var_v0 = *(s32 *)(arg0 + 0x2200);
    goto block_6;
block_4:
    D_8012B3E8.unk_00 = 4;
    var_v0 = *(s32 *)(arg0 + 0x2204);
    Minigame_MapControllerButtons(arg0, (u8 *)&D_8012B3E8);
    goto block_6;
block_default:
    D_8012B3E8.unk_00 = 6;
    var_v0 = *(s32 *)(arg0 + 0x2200);
    Minigame_MapControllerButtons(arg0, (u8 *)&D_8012B3E8);
block_6:
    switch (var_v0) {
    case 0:
        D_8012B3E8.unk_02 = 1;
        break;
    case 1:
        D_8012B3E8.unk_02 = 2;
        break;
    case 2:
    case 3:
        D_8012B3E8.unk_02 = 3;
        break;
    }
}
/* mkdraft:func_80072650 end */

// Isolated `jr ra; nop` at 0x80072738 with no symbol_addrs entry. It restores neither
// sp nor ra, so it cannot be an epilogue of func_80072650's 0x20-byte frame; IDO emits
// exactly this pair for an empty void function, and the next function
// (Minigame_ProcessInput) starts at 0x80072740.
//@asm/us/nonmatchings/72C30/func_80072650.s
void func_80072738_padding(void) {}

s32 (*func_80003240(s32 *))(s32 *);
extern u8 func_87F0EE0C;
void Minigame_ProcessInput(u8 *arg0) {
    func_80003240(&func_87F0EE0C)(&D_801291E0);
}

extern u8 func_87F0F390;
void Minigame_ResetControllerPoll(u8 *arg0) {
    func_80003240(&func_87F0F390)((s32 *)arg0);
}

extern u8 func_87F0F3E4;
void Minigame_ResetRoundPlayers(u8 *arg0) {
    func_80003240(&func_87F0F3E4)((s32 *)arg0);
}

#define SEG(x) (((((u32)(x)) & 0x0FF00000) >> 20) - 0x10)
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void func_80035424(s32);
extern void func_80072184(u8 *);
extern void Minigame_SetModeDefaults(u8 *);
extern void Minigame_ProcessInput(u8 *);
extern void Minigame_ResetControllerPoll(u8 *);
extern void Minigame_ResetRoundPlayers(u8 *);
extern u8 D_8009F870;
static const s16 D_800A5B00[] = { 1, 0, 3, 4, 6, 2, 5, 8, 10, 7, 9, 11 };
extern s32 D_8012B3F8;
extern u8 D_87C00000[];
extern u8 D_87D00000[];
extern u8 D_87E00000[];
extern u8 D_86100000[];
extern u8 D_86000000[];
extern u8 D_86500000[];
extern u8 D_86200000[];
extern u8 D_86300000[];
extern u8 D_86600000[];
extern u8 D_86400000[];
extern u8 D_86900000[];
extern u8 D_86700000[];
extern u8 D_86A00000[];
extern u8 D_86800000[];
extern u8 D_86B00000[];
extern u8 D_81A00000[];
extern u8 D_87F00000[];
extern u8 D_81000000[];
extern u8 D_81900000[];
extern u8 fragment2_ROM_START[];
extern u8 fragment3_ROM_START[];
extern u8 fragment4_ROM_START[];
extern u8 fragment26_ROM_START[];
extern u8 fragment27_ROM_START[];
extern u8 fragment47_ROM_START[];
extern u8 fragment48_ROM_START[];
extern u8 fragment49_ROM_START[];
extern u8 fragment50_ROM_START[];
extern u8 fragment51_ROM_START[];
extern u8 fragment52_ROM_START[];
extern u8 fragment53_ROM_START[];
extern u8 fragment54_ROM_START[];
extern u8 fragment55_ROM_START[];
extern u8 fragment56_ROM_START[];
extern u8 fragment57_ROM_START[];
extern u8 fragment59_ROM_START[];
extern u8 fragment60_ROM_START[];
extern u8 fragment61_ROM_START[];
extern u8 fragment62_ROM_START[];
extern u8 fragment63_ROM_START[];
extern u8 fragment64_ROM_START[];
extern u8 fragment65_ROM_START[];
extern u8 fragment66_ROM_START[];
extern u8 fragment26_ROM_END[];
extern u8 fragment2_ROM_END[];
extern u8 fragment3_ROM_END[];
extern u8 fragment43_ROM_END[];
extern u8 fragment45_ROM_END[];
extern u8 fragment47_ROM_END[];
extern u8 fragment48_ROM_END[];
extern u8 fragment49_ROM_END[];
extern u8 fragment50_ROM_END[];
extern u8 fragment51_ROM_END[];
extern u8 fragment52_ROM_END[];
extern u8 fragment53_ROM_END[];
extern u8 fragment54_ROM_END[];
extern u8 fragment55_ROM_END[];
extern u8 fragment56_ROM_END[];
extern u8 fragment59_ROM_END[];
extern u8 fragment60_ROM_END[];
extern u8 fragment61_ROM_END[];
extern u8 fragment63_ROM_END[];
extern u8 fragment64_ROM_END[];
extern u8 fragment65_ROM_END[];
#define G ((u8 *)&D_801291E0)
void func_800727D4(s32 arg0) {
    s32 state;
    main_pool_push_state(0x6D696E69);
    Fragment_Load(SEG(D_81A00000), fragment3_ROM_START, fragment3_ROM_END);
    Fragment_Load(SEG(D_87F00000), fragment64_ROM_START, fragment64_ROM_END);
    Fragment_Load(SEG(D_81000000), fragment26_ROM_START, fragment26_ROM_END);
    Fragment_Load(SEG(D_81900000), fragment2_ROM_START, fragment2_ROM_END);
    func_80072184(G);
    Minigame_ProcessInput(G);
    Minigame_SetModeDefaults((u8 *)&D_8012B3E8);
    switch (arg0) {
        case 0:
            state = -1;
            break;
        case 1:
            D_8009F870++;
            if (D_8009F870 >= 12) {
                D_8009F870 = 0;
            }
            state = D_800A5B00[D_8009F870];
            // s8 store: the stored 1 shares the register of the switch compare
            *(s8 *)(G + 0x2181) = 1;
            G[0x2180] = 4;
            G[0x2182] = 0xF;
            Minigame_ProcessPlayerEvents(G, G[0x2182], 0);
            break;
    }
    Minigame_UpdateControllerState(G, G[0x2182]);
    Minigame_ResetControllerPoll(G);
    // a goto loop (not do/while) gives G s2 and &state s3
loop:
    main_pool_push_state(0x7A6D676D);
    switch (state) {
    case 0xFE:
        func_80072650(G);
        Fragment_Load(SEG(D_8AC00000), fragment43_ROM_START, fragment43_ROM_END);
        Fragment_LoadAndCall(SEG(D_8AB00000), fragment45_ROM_START, fragment45_ROM_END, 0, (u32)&D_8012B3E8);
        if (D_8012B3F8 != 0) {
            *(s32 *)(G + 0x2184) = 6;
        }
        state = -1;
        break;
    case -1:
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        Fragment_Load(SEG(D_87D00000), fragment65_ROM_START, fragment65_ROM_END);
        state = Fragment_LoadAndCall(SEG(D_87E00000), fragment63_ROM_START, fragment63_ROM_END, 0, (u32)G);
        break;
    case 1:
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86000000), fragment47_ROM_START, fragment47_ROM_END, 0, (u32)G), &state);
        break;
    case 2:
        Minigame_UpdateControllerState(G, G[0x2182]);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86500000), fragment53_ROM_START, fragment53_ROM_END, 0, (u32)G), &state);
        break;
    case 5:
        Minigame_UpdateControllerState(G, G[0x2182]);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86600000), fragment54_ROM_START, fragment54_ROM_END, 0, (u32)G), &state);
        break;
    case 8:
        Minigame_UpdateControllerState(G, G[0x2182]);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86700000), fragment55_ROM_START, fragment55_ROM_END, 0, (u32)G), &state);
        break;
    case 10:
        func_800723FC(Fragment_LoadAndCall(SEG(D_86800000), fragment56_ROM_START, fragment56_ROM_END, 0, (u32)G), &state);
        break;
    case 0:
        Fragment_Load(SEG(D_87D00000), fragment65_ROM_START, fragment65_ROM_END);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86100000), fragment49_ROM_START, fragment49_ROM_END, 0, (u32)G), &state);
        break;
    case 3:
        Fragment_Load(SEG(D_87D00000), fragment65_ROM_START, fragment65_ROM_END);
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        Minigame_UpdateControllerState(G, G[0x2182]);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86200000), fragment50_ROM_START, fragment50_ROM_END, 0, (u32)G), &state);
        break;
    case 4:
        Fragment_Load(SEG(D_87D00000), fragment65_ROM_START, fragment65_ROM_END);
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86300000), fragment51_ROM_START, fragment51_ROM_END, 0, (u32)G), &state);
        break;
    case 6:
        Fragment_Load(SEG(D_87D00000), fragment65_ROM_START, fragment65_ROM_END);
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86400000), fragment52_ROM_START, fragment52_ROM_END, 0, (u32)G), &state);
        break;
    case 7:
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        Minigame_UpdateControllerState(G, G[0x2182]);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86900000), fragment59_ROM_START, fragment59_ROM_END, 0, (u32)G), &state);
        break;
    case 9:
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86A00000), fragment60_ROM_START, fragment60_ROM_END, 0, (u32)G), &state);
        break;
    case 11:
        Fragment_Load(SEG(D_87C00000), fragment48_ROM_START, fragment48_ROM_END);
        func_800723FC(Fragment_LoadAndCall(SEG(D_86B00000), fragment61_ROM_START, fragment61_ROM_END, 0, (u32)G), &state);
        break;

    }
    main_pool_pop_state(0x7A6D676D);
    if (state != 0xFF) goto loop;
    Minigame_ResetRoundPlayers(G);
    func_80035424(2);
    main_pool_pop_state(0x6D696E69);
}

#endif
