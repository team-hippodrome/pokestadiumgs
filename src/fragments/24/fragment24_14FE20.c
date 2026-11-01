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

/* mkdraft:func_82B006D8 begin */
extern s16 D_82B12220;
extern s32 D_82B08524;
extern s32 D_82B08528;
extern s32 func_82B0052C(void);
extern void func_82B084AC(void);
extern s32 func_82B084CC(void);
extern s32 func_82B08508(void);
extern s32 func_82B08514(void);
extern u8 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromTransparent(s32 duration);
extern s32 func_81700C0C(s32 arg0);
// FAKE: func_80035424 returns void (include/229E0.h:961, src/340C0.c:811); the s32
// return only re-colors the case-3 tail. Score without it: 110.
extern s32 func_80035424(s32 arg0);
// func_82B0069C is defined above this function in src/fragments/24/fragment24_14FE20.c.



s32 func_82B006D8(s32 arg0, s32 arg1) {
    // FAKE: result[0] is the only element read. Taking the address of a two-element
    // array is what homes the return value in the 0x18/0x1C stack slots and yields the
    // 0x20 frame. Score with a plain s32 return local: 32.
    s32 result[2];
    s16 var_v1;
    s32 temp_v0;
    // FAKE: reading D_82B12220 directly makes IDO emit the load with a different
    // register; the retail read is `lui v1,%hi` + `lh v1,%lo(v1)`. Score without this
    // local pointer: 545.
    s16 *D_82B12220_ptr = &D_82B12220;

    result[0] = arg0;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            result[0] = 1;
            if (arg1 != 0) {
                func_82B084AC();
                func_81700C0C(0);
                func_81700C0C(1);
            } else {
                func_82B084CC();
            }
        }
        break;
    case 1:
        temp_v0 = func_82B0052C();
        if (temp_v0 != 0) {
            switch (temp_v0) {
            case -1:
                D_82B08524 = -1;
                D_82B08528 = -1;
                result[0] = 3;
                D_82B12220 = 0;
                StageFade_StartFromTransparent(5);
                break;
            case 1:
                switch (D_82B08524) {
                case 3:
                    D_82B08528 = func_82B08508();
                    break;
                case 4:
                    D_82B08528 = func_82B08514();
                    break;
                default:
                    D_82B08528 = 0;
                    break;
                }
                result[0] = 3;
                // FAKE: separates `result[0] = 3` from the fade store so IDO schedules
                // `addiu t9,zero,3` ahead of `addiu v1,zero,15`; the label is the only
                // reason the store is not emitted in the other order. Score without it: 20.
                goto Lfade;
            Lfade:
                // FAKE: the pair is a dead compare that leaves the 15 in v1 instead of
                // v0; one compare gives 10, none gives 40. The mask keeps the compare's
                // operand a full register read of arg1.
                if ((arg1 & 0xF) == 0xF) {
                }
                if ((arg1 & 0xF) == 0xF) {
                }
                D_82B12220 = 15;
                StageFade_StartFromTransparent(5);
                break;
            case 2:
                switch (D_82B08524) {
                case 3:
                    D_82B08528 = func_82B08508();
                    break;
                case 4:
                    D_82B08528 = func_82B08514();
                    break;
                default:
                    D_82B08528 = 0;
                    break;
                }
                result[0] = 2;
                D_82B12220 = 0;
                break;
            }
        }
        break;
    case 2:
        if (func_82B0069C() != 0) {
            result[0] = 5;
        }
        break;
    case 3:
        var_v1 = *D_82B12220_ptr;
        if (var_v1 > 0) {
            var_v1 -= 1;
        }
        if (var_v1 == 0) {
            // FAKE: duplicate of the store below (var_v1 is 0 here); it keeps the
            // D_82B12220 store inside the branch. Score without it: 260.
            D_82B12220 = var_v1;
            func_80035424(10);
            var_v1 = -1;
        }
        D_82B12220 = var_v1;
        // FAKE: `^ 0` is a no-op that flips the bne operand order to retail's
        // `bne a1,v1`. Score without it: 10.
        if (((var_v1 ^ 0) == -1) && (StageContext_GetFadeMode() == 1)) {
            result[0] = 5;
        }
        break;
    }
    return result[0];
}
/* mkdraft:func_82B006D8 end */

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
