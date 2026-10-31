#include "global.h"


#ifdef VERSION_US
s32 func_82B00020(u8 *arg0) {
    s32 result;

    if (arg0[1] != 0) {
        if (arg0[0] == 0) {
            if (arg0[2] < 6) {
                result = 5;
            } else {
                result = 0;
            }
        } else {
            result = 3;
        }
    } else if (arg0[0] == 2) {
        result = 4;
    } else if (arg0[4] != 0) {
        result = 1;
    } else {
        result = 2;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B00098.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B002B8.s")

extern void BgStage_DrawFrame();
extern void func_82B080D0();
extern void func_80008648();
void func_82B004FC(s32 arg0) {
    BgStage_DrawFrame();
    func_82B080D0();
    func_80008648();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B0052C.s")

typedef struct Target82BState Target82BState;
struct Target82BState { u8 pad_0000[0x1A60]; s16 value; };
extern Target82BState D_82B107C0;
extern s16 D_82B12220;
s32 func_82B0069C(void) {
    s32 result = 1;
    volatile Target82BState *state = &D_82B107C0;
    D_82B12220 = state->value + 1;
    if (state->value < 2) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B006D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B00914.s")

extern s32 D_82B08524;
extern s32 D_82B08528;

// Packs D_82B08524 + 1 (only for 0-4; other non-negative values give 1) into the
// upper halfword and the low halfword of D_82B08528 into the lower one; returns 0
// while D_82B08524 is negative.
u32 func_82B00B78(void) {
    u32 result = 0;
    u32 high;

    if (D_82B08524 >= 0) {
        high = 0x10000;
        switch (D_82B08524) {
            case 0:
                break;
            case 1:
                high = 0x20000;
                break;
            case 2:
                high = 0x30000;
                break;
            case 3:
                high = 0x40000;
                break;
            case 4:
                high = 0x50000;
                break;
        }
        result = (D_82B08528 & 0xFFFF) | high;
    }
    return result;
}

/* mkdraft:func_82B00BE0 begin */
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80008624(void);
extern void func_8004C398(void);
extern void func_80047610(void);
extern u8 *func_80047588(s32, s32);
extern s32 func_80055948(s32);
extern void func_8005A014(s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern s32 Fragment_LoadAndCall(s32, u8 *, u8 *, u32, u32);
extern void StageLoader_WaitForRetrace(void);
extern void func_82B002B8(u32, s32, s32, s32);
extern s32 func_82B00914(s32);
extern s32 func_82B08508(void);
extern s32 func_82B08514(void);
extern u8 D_1000000[], D_446E30[], D_447D00[];
extern u8 D_82C00000[], fragment83_ROM_START[], fragment84_ROM_START[];
extern s32 D_82B08520;
extern s32 D_82B0852C;
extern s32 D_82B12448;



u32 func_82B00BE0(u32 arg0, s32 arg1) {
    // FAKE: unused frame padding. Without it the frame is 0x50 instead of 0x60 and
    // only the prologue/epilogue stack adjust differs (diff score 10).
    s32 pad[4];
    // Packed value returned to the caller, kept from the last stage frame.
    u32 result;
    // Request slot for the next fragment. Held in a local because reading the global
    // directly costs the D_82C00000 base its $fp home (diff score 635).
    s32 *request = &D_82B12448;
    // 1 on the first pass only; func_82B002B8 skips its setup while this is nonzero.
    s32 first_frame;
    // func_800082E0 result, handed to func_80008514.
    s32 configuration;
    // Loop state: 0 draws a stage frame, 1 loads and runs the requested fragment, 2 exits.
    s32 state;
    s32 var_s3;
    s32 var_s4;

    state = 0;
    first_frame = 1;
    result = 0;
    var_s3 = 0;
    var_s4 = 0;
    main_pool_push_state(0x4556534C);
    D_82B08520 = arg1;
    Gfx_InitDisplayListBuffers(0x10000, 0);
    configuration = func_800082E0(1, 0, 2, 0, 2, 1);
    func_80047588(0x1C, 0);
    Asset_LoadToSegment((u32) ((s32) &D_1000000 & 0x0F000000) >> 0x18, &D_446E30, &D_447D00, 0);
    func_80055948(3);
    func_8005A014(0);
    func_8005A014(1);
    D_82B0852C = -1;
    func_80008514(configuration);
    do {
        main_pool_push_state(0x6C6F6F70);
        switch (state) {
        case 0:
            func_80008624();
            func_82B002B8(arg0, first_frame, var_s3, var_s4);
            state = func_82B00914(first_frame);
            first_frame = 0;
            StageLoader_WaitForRetrace();
            func_8004C398();
            result = func_82B00B78();
            arg0 = result;
            var_s3 = func_82B08508();
            var_s4 = func_82B08514();
            break;
        case 1:
            state = 0;
            if (*request != 0) {
                Fragment_LoadAndCall(((u32) ((s32) &D_82C00000 & 0x0FF00000) >> 0x14) - 0x10, &fragment83_ROM_START, &fragment84_ROM_START, 0x100, *request);
            }
            break;
        }
        main_pool_pop_state(0x6C6F6F70);
    } while (state != 2);
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4556534C);
    return result;
}
/* mkdraft:func_82B00BE0 end */
#endif
