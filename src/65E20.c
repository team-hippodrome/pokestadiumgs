#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_80065220 begin */
extern u8 D_81100000[];
extern u8 D_81A00000[];
extern u8 D_82900000;
extern u8 D_82E00000[];
extern u8 D_83300000[];
extern u8 D_83400000[];
extern u8 D_83500000[];
extern u8 D_84100000[];
extern u8 D_87F00000[];
extern u8 D_8AC00000[];
extern u8 D_8AE00000[];
extern u8 fragment1_ROM_START[];
extern u8 fragment2_ROM_START[];
extern u8 fragment3_ROM_START[];
extern u8 fragment4_ROM_START[];
extern u8 fragment27_ROM_START[];
extern u8 fragment28_ROM_START[];
extern u8 fragment43_ROM_START[];
extern u8 fragment44_ROM_START[];
extern u8 fragment46_ROM_START[];
extern u8 fragment47_ROM_START[];
extern u8 fragment57_ROM_START[];
extern u8 fragment58_ROM_START[];
extern u8 fragment59_ROM_START[];
extern u8 fragment64_ROM_START[];
extern u8 fragment65_ROM_START[];
extern u8 fragment66_ROM_START[];
extern u8 fragment67_ROM_START;
extern u8 fragment68_ROM_START;
extern u8 fragment79_ROM_START[];
extern u8 fragment80_ROM_START[];
extern s32 Fragment_Load(s32, void *, void *);
extern s32 Fragment_LoadAndCall(s32, void *, void *, u32, u32);
extern s32 main_pool_alloc(s32, s32);
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void _bzero(void *, s32);
extern void Audio_ResetModeSelector(void);
extern s32 Audio_SetModeBlocking(s32, s32, s32);
extern void func_80026938(u16);
extern void func_800355E4(s32);
extern s32 func_800718B8(s32);
extern u32 func_8006C714(void);
extern void Game_SetState(s32);



void func_80065220(u32 arg0, s32 arg1) {
    /* FAKE: single-use pointer copy. It claims a 4-byte home in this frame; without it the
       frame shifts and the diff scores 60. */
    u8 *D_81100000_ptr = D_81100000;
    s32 sp38;       /* main_pool_alloc(0x9DC) block; +0x9D4 and +0x9D8 are written in case 1 */
    s32 sp34;       /* main_pool_alloc(0x490) block; +0x3B8 is stored into sp38+0x9D8 */
    s16 sp30[2];    /* case 11 clears halfword 0, then fragment 58 receives the address */
    s32 sp2C;       /* case 13 clears all 4 bytes, then fragment 66 receives the address */
    s16 sp24[3];    /* case 18 sets 1, 1, 0, then fragment 1 receives the address */
    s32 temp_v0;

    main_pool_push_state(0x64627567);
    switch (arg0) {
    case 0:
        Game_SetState(0xC);
        break;
    case 1:
        func_80026938((u16) arg1);
        Audio_SetModeBlocking(8, 0, 1);
        func_800355E4(3);
        sp38 = main_pool_alloc(0x9DC, 0);
        _bzero((void *) sp38, 0x9DC);
        sp34 = main_pool_alloc(0x490, 0);
        _bzero((void *) sp34, 0x490);
        *(s32 *) (sp38 + 0x9D8) = sp34 + 0x3B8;
        *(s32 *) (sp38 + 0x9D4) = func_800718B8(0xC);
        Fragment_Load(((u32) ((s32) D_81100000_ptr & 0x0FF00000) >> 20) - 0x10,
            fragment27_ROM_START, fragment28_ROM_START);
        Fragment_LoadAndCall(((u32) ((s32) D_84100000 & 0x0FF00000) >> 20) - 0x10,
            fragment79_ROM_START, fragment80_ROM_START, (u32) arg1, (u32) sp38);
        Audio_SetModeBlocking(1, 0, 0);
        break;
    case 2:
        Game_SetState(5);
        break;
    case 3:
        Game_SetState(6);
        break;
    case 4:
        Game_SetState(8);
        break;
    case 5:
        Game_SetState(9);
        break;
    case 6:
        Game_SetState(0x13);
        break;
    case 7:
        Fragment_Load(((u32) ((s32) D_8AC00000 & 0x0FF00000) >> 20) - 0x10,
            fragment43_ROM_START, fragment44_ROM_START);
        Fragment_LoadAndCall(((u32) ((s32) D_8AE00000 & 0x0FF00000) >> 20) - 0x10,
            fragment46_ROM_START, fragment47_ROM_START, 0U, 0U);
        break;
    case 8:
        Game_SetState(0xA);
        break;
    case 9:
        Game_SetState(4);
        break;
    case 10:
        Audio_SetModeBlocking(2, 0, 0);
        Fragment_LoadAndCall(((u32) ((s32) &D_82900000 & 0x0FF00000) >> 20) - 0x10,
            &fragment67_ROM_START, &fragment68_ROM_START, 4U, 0U);
        break;
    case 11:
        Audio_SetModeBlocking(0xC, 0, 0);
        Fragment_Load(((u32) ((s32) D_87F00000 & 0x0FF00000) >> 20) - 0x10,
            fragment64_ROM_START, fragment65_ROM_START);
        sp30[0] = 0;
        Fragment_LoadAndCall(((u32) ((s32) &D_83400000 & 0x0FF00000) >> 20) - 0x10,
            fragment58_ROM_START, fragment59_ROM_START, 0U, (u32) sp30);
        break;
    case 12:
        Audio_SetModeBlocking(0xA, 0, 0);
        temp_v0 = func_8006C714();
        if (temp_v0 != 0) {
            Fragment_LoadAndCall(((u32) ((s32) &D_82900000 & 0x0FF00000) >> 20) - 0x10,
                &fragment67_ROM_START, &fragment68_ROM_START, 1U, temp_v0);
        }
        break;
    case 13:
        _bzero(&sp2C, 4);
        Audio_SetModeBlocking(0xD, 0, 0);
        Fragment_LoadAndCall(((u32) ((s32) &D_82E00000 & 0x0FF00000) >> 20) - 0x10,
            fragment66_ROM_START, &fragment67_ROM_START, 0U, (u32) &sp2C);
        break;
    case 14:
        Game_SetState(0x12);
        break;
    case 15:
        Audio_SetModeBlocking(0xD, 0, 0);
        Fragment_LoadAndCall(((u32) ((s32) &D_82900000 & 0x0FF00000) >> 20) - 0x10,
            &fragment67_ROM_START, &fragment68_ROM_START, 2U, 0U);
        break;
    case 16:
        Audio_SetModeBlocking(7, 0, 0);
        Fragment_LoadAndCall(((u32) ((s32) &D_82900000 & 0x0FF00000) >> 20) - 0x10,
            &fragment67_ROM_START, &fragment68_ROM_START, 3U, 0U);
        break;
    case 17:
        Audio_SetModeBlocking(0xC, 0, 0);
        Fragment_Load(((u32) ((s32) D_81A00000 & 0x0FF00000) >> 20) - 0x10,
            fragment3_ROM_START, fragment4_ROM_START);
        Fragment_Load(((u32) ((s32) D_87F00000 & 0x0FF00000) >> 20) - 0x10,
            fragment64_ROM_START, fragment65_ROM_START);
        Fragment_LoadAndCall(((u32) ((s32) D_83300000 & 0x0FF00000) >> 20) - 0x10,
            fragment57_ROM_START, fragment58_ROM_START, 0U, 0U);
        break;
    case 18:
        sp24[0] = 1;
        sp24[1] = 1;
        sp24[2] = 0;
        Audio_ResetModeSelector();
        Audio_SetModeBlocking(0xA, 0, 0);
        Fragment_Load(((u32) ((s32) D_87F00000 & 0x0FF00000) >> 20) - 0x10,
            fragment64_ROM_START, fragment65_ROM_START);
        Fragment_LoadAndCall(((u32) ((s32) D_83500000 & 0x0FF00000) >> 20) - 0x10,
            fragment1_ROM_START, fragment2_ROM_START, 0U, (u32) sp24);
        break;
    }
    main_pool_pop_state(0x64627567);
}
/* mkdraft:func_80065220 end */

extern void func_800354B4(s32, s32, s32);
extern void func_800355E4(s32);
extern s32 Fragment_LoadAndCall(s32, void *, void *, u32, u32);
extern u8 D_82000000;
extern u8 fragment16_ROM_START;
extern u8 fragment17_ROM_START;
void func_800657B0(void) {
    func_800354B4(1, 0, 0);
    func_800355E4(0x24);
    Fragment_LoadAndCall(((u32)((s32)&D_82000000 & 0x0FF00000) >> 20) - 0x10,
        &fragment16_ROM_START, &fragment17_ROM_START, 0, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/65E20/func_80065814.s")

extern void func_80065814(s32);
extern void Audio_ResetRequestId(void);
extern void func_800727D4(s32);
extern void Game_State17_Boot(void);
void func_80065974(u32 arg0) {
    s32 temp_v0;
    temp_v0 = arg0 & 1;
    switch (temp_v0) {
    case 0:
        func_80065814(arg0 >> 1);
        Audio_ResetRequestId();
        return;
    case 1:
        func_800354B4(6, 0, 0);
        func_800727D4(1);
        Audio_ResetRequestId();
        if (((arg0 >> 1) % 3U) == 2) {
            func_800354B4(0, 0, 0);
            Game_State17_Boot();
        }
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/65E20/func_80065A18.s")

extern void Game_SetState(s32);
extern u8 D_83F00000;
extern u8 D_82900000;
extern u8 fragment15_ROM_START;
extern u8 fragment67_ROM_START;
extern u8 fragment68_ROM_START;
void Game_State17_Boot(void) {
    Fragment_LoadAndCall(((u32)((s32)&D_83F00000 & 0x0FF00000) >> 20) - 0x10,
        &fragment15_ROM_START, &fragment16_ROM_START, 0, 0);
    Fragment_LoadAndCall(((u32)((s32)&D_82900000 & 0x0FF00000) >> 20) - 0x10,
        &fragment67_ROM_START, &fragment68_ROM_START, 0, 0);
    Game_SetState(1);
}
#endif
