#include "global.h"


#ifdef VERSION_US
extern s32 func_87F0EFA0;
extern s32 (*func_80003240(s32 *))(s32 *);
void Minigame_ProcessPlayerEvents(s32 arg0, u8 arg1, s32 arg2) {
    ((void (*)(s32, u8, s32))(void *)func_80003240(&func_87F0EFA0))(arg0, arg1, arg2);
}

extern s32 func_87F0EDDC;
void Minigame_UpdateControllerState(s32 arg0, u8 arg1) {
    ((void (*)(s32, u8))(void *)func_80003240(&func_87F0EDDC))(arg0, arg1);
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/72C30/func_80072264.s")

extern u8 func_87F097B0;
extern u8 D_801291E0;
extern s8 D_8012B363;
void Minigame_UpdatePlayerCounters(void) {
    ((void (*)(void *, s8))(void *)func_80003240(&func_87F097B0))(&D_801291E0, D_8012B363);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/72C30/func_800723FC.s")

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
void Minigame_ProcessInput(s32 arg0) {
    func_80003240(&func_87F0EE0C)(&D_801291E0);
}

extern u8 func_87F0F390;
void Minigame_ResetControllerPoll(s32 arg0) {
    func_80003240(&func_87F0F390)(arg0);
}

extern u8 func_87F0F3E4;
void Minigame_ResetRoundPlayers(s32 arg0) {
    func_80003240(&func_87F0F3E4)(arg0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/72C30/func_800727D4.s")
#endif
