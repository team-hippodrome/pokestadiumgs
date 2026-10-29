#include "global.h"

// This object's .data (0x8220D6F0-0x8220D770): four animation key lists, the
// records that point at them, the record table used by func_822000F0, and the
// slide state func_82200020 keeps between geo callbacks.
typedef struct Fragment17AnimKeys {
    /* 0x0 */ s16 unk_0;
    /* 0x2 */ s16 count;
    /* 0x4 */ s16 *keys;
} Fragment17AnimKeys; // size = 0x8

s16 D_8220D6F0[8] = { 0x3C, -1, 2, 1, 2, 2, 2, 1 };
Fragment17AnimKeys D_8220D700 = { 1, 4, D_8220D6F0 };
s16 D_8220D708[12] = { 0x28, -1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 1 };
Fragment17AnimKeys D_8220D720 = { 1, 6, D_8220D708 };
s16 D_8220D728[8] = { 0x50, -1, 2, 1, 2, 2, 2, 1 };
Fragment17AnimKeys D_8220D738 = { 1, 4, D_8220D728 };
s16 D_8220D740[8] = { 0x78, -1, 1, 1, 1, 2, 1, 1 };
Fragment17AnimKeys D_8220D750 = { 1, 4, D_8220D740 };
s32 D_8220D758[4] = { (s32)&D_8220D700, (s32)&D_8220D720, (s32)&D_8220D738, (s32)&D_8220D750 };
static s16 D_8220D768 = 0;
static s16 D_8220D76C = 0;


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10F9E0/func_82200020.s")

/* mkdraft:func_822000F0 begin */
extern s32 func_800506A4(void *);
extern void func_80050578(void *, s32);

s32 func_822000F0(s32 arg0, void *arg1) {
    s32 index = *(s32 *)((u8 *)arg1 + 0x20);

    switch (arg0) {
    case 0:
        *(s8 *)((u8 *)arg1 + 0x28) = 0x21;
        if (index == 1) {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
        break;
    case 1:
        if (func_800506A4(arg1) != 0) {
            s32 idx = guRandom() & 3;
            func_80050578(arg1, D_8220D758[idx]);
        }
        break;
    }
    return 0;
}
/* mkdraft:func_822000F0 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10F9E0/func_82200184.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10F9E0/func_82200374.s")

extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern s32 func_8004C09C(s32);
extern void func_80055948(s32);
extern void func_80054E48(s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern u8 D_1000000[], D_446E30[], D_447D00[];
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void func_82200184(s32 *, s32);
extern void func_82200374(void);
extern void func_822033BC(s32 *);
extern void func_8220402C(void);
extern void func_8220792C(s32 *, s32);
extern void func_82208DCC(void);
extern s32 D_8220E2D0;

void func_822003EC(u32 arg0, s32 arg1) {
    s32 phase;
    s32 mode;
    s32 configuration;

    switch (arg0) {
        case 0:
            phase = 0;
            mode = -1;
            break;
        case 1:
            phase = 1;
            mode = 0;
            break;
        case 2:
            phase = 1;
            mode = 1;
            break;
        case 3:
            phase = 1;
            mode = 2;
            break;
        case 4:
            phase = 1;
            mode = 3;
            break;
        case 5:
            phase = 1;
            mode = 4;
            break;
        case 6:
            phase = 1;
            mode = 5;
            break;
        case 7:
            phase = 1;
            mode = 1;
            break;
        default:
            phase = 1;
            mode = -1;
            break;
    }
    main_pool_push_state(0x47424348); // "GBCH"
    Gfx_InitDisplayListBuffers(0x20000, 0);
    configuration = func_800082E0(1, 0, 2, 0, 2, 1);
    func_8004C09C(263);
    func_80055948(3);
    func_82200184(&D_8220E2D0, arg1);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_80008514(configuration);
    while (phase >= 0) {
        main_pool_push_state(0x6D707263); // "mprc"
        switch (phase) {
            case 0:
                func_822033BC(&D_8220E2D0);
                func_8220402C();
                if (D_8220E2D0 >= 0) {
                    phase = 1;
                } else {
                    phase = -1;
                }
                break;
            case 1:
                func_8220792C(&D_8220E2D0, mode);
                phase = -1;
                func_82208DCC();
                break;
        }
        main_pool_pop_state(0x6D707263); // "mprc"
    }
    func_80008574();
    func_80054E48(3);
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x47424348); // "GBCH"
    func_82200374();
}
#endif
