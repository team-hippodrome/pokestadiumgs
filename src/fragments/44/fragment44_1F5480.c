#include "global.h"


#ifdef VERSION_US
extern u8 *D_8AF2C638;
extern u8 *D_8AF2C63C;
extern u8 *D_8AF2C640;
extern u8 *D_8AF2C644;
extern s16 D_8AF2C654;

// Resets two flag halfwords (bit 0 of +0x02 in *D_8AF2C638/*D_8AF2C63C) and the two RGBA colors at
// +0x28/+0x2C of *D_8AF2C640/*D_8AF2C644, then highlights the pair selected by D_8AF2C654:
// 0 sets the *D_8AF2C63C flag and turns *D_8AF2C640's colors yellow, 1 does the same for
// *D_8AF2C638 and *D_8AF2C644.
void func_8AF07210(void) {
    *(u16 *)(D_8AF2C638 + 0x02) &= ~1;
    *(u16 *)(D_8AF2C63C + 0x02) &= ~1;
    *(s32 *)(D_8AF2C640 + 0x28) = 0xC3A05AFF;
    *(s32 *)(D_8AF2C640 + 0x2C) = 0xE1C38CFF;
    *(s32 *)(D_8AF2C644 + 0x28) = 0xC3A05AFF;
    *(s32 *)(D_8AF2C644 + 0x2C) = 0xE1C38CFF;
    switch (D_8AF2C654) {
        case 0:
            *(u16 *)(D_8AF2C63C + 0x02) |= 1;
            *(s32 *)(D_8AF2C640 + 0x28) = 0xFFFF00FF;
            *(s32 *)(D_8AF2C640 + 0x2C) = 0xFFFF00FF;
            break;
        case 1:
            *(u16 *)(D_8AF2C638 + 0x02) |= 1;
            *(s32 *)(D_8AF2C644 + 0x28) = 0xFFFF00FF;
            *(s32 *)(D_8AF2C644 + 0x2C) = 0xFFFF00FF;
            break;
    }
}

#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

s32 func_80054794();                                /* extern */
extern u8 *D_8AF2C648;

void func_8AF07300(void) {
    if (func_80054794() == 7) {
        switch (D_8AF2C654) {                       /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            M2C_FIELD(D_8AF2C648, s16 *, 0x32) = 0x26;
            return;
        case 1:                                     /* switch 1 */
            M2C_FIELD(D_8AF2C648, s16 *, 0x32) = 0x25;
            return;
        }
    } else {
        switch (D_8AF2C654) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            M2C_FIELD(D_8AF2C648, s16 *, 0x32) = 2;
            return;
        case 1:                                     /* switch 2 */
            M2C_FIELD(D_8AF2C648, s16 *, 0x32) = 0x30;
            return;
        }
    }
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F5480/func_8AF073B4.s")

/* mkdraft:func_8AF0769C begin */
extern s16 D_8AF2C654;
extern s16 D_8AF26550;
extern s32 D_8AF2BA68;
extern u8 *D_8AF263C0;
extern u8 D_8AF2C5A0;
extern u8 D_8AF2C5D0;
extern s16 D_8AF2C612;
extern void *D_8AF2C634;
extern void *D_8AF2C64C;
extern u8 *D_8AF2C650;
extern s16 D_8AF2C656;
extern s16 D_8AF2C658;
extern s32 D_8AF2C660;
extern s16 D_8AF2C664;
extern s16 D_8AF2C666;
extern s16 D_8AF2C66A;
extern s16 D_8AF2C66E;
extern void func_8AC007FC(void);
extern void func_8AC06A94(void *, void *, void *, void *);
extern void func_8AF00130(s32);
extern void func_8AF07FF0(void);

// Per-frame handler for the pair of candidate cards on the character-select screen.
// D_8AF2C66A is the pair's horizontal slide offset in screen units; negative offsets are stepped
// toward 0 by 40 per frame once D_8AF2C658, a 0..20 entry counter, passes 16, and the offset is
// added to D_8AF2C66E (the pair's resting X) into the field at +0x0A of *D_8AF2C650 while it
// slides. Once the slide settles (D_8AF2C66A == 0) the pair index D_8AF2C654 selected by
// func_8AF07210 is moved with 0x200/0x100 on the input word at +8 of *D_8AF263C0 and confirmed
// with 0x8000, which latches D_8AF2C656/D_8AF26550 and returns 7 (pair 0) or 0x24 (pair 1).
// 0x4000 instead sets D_8AF2C660, which makes every later call count D_8AF2C664 and return 1
// once D_8AF2C666 frames have elapsed.


s16 func_8AF0769C(void) {
    s32 selected_pair;
    s16 previous_pair;
    s16 result;

    result = 1;
    func_8AC06A94(&D_8AF2C5D0, &D_8AF2C5A0, D_8AF2C64C, D_8AF2C634);
    D_8AF2C612 = 9;
    if (D_8AF2C660 != 0) {
        D_8AF2C664 += 1;
        if (D_8AF2C666 < D_8AF2C664) {
            D_8AF2BA68 = 1;
        }
        return 1;
    }
    if (D_8AF2C658 >= 16) {
        func_8AC007FC();
    }
    if (D_8AF2C658 < 20) {
        D_8AF2C658 = D_8AF2C658 + 1;
    }
    if (D_8AF2C658 >= 16 && D_8AF2C66A < 0) {
        D_8AF2C66A += 40;
        if (D_8AF2C658 == 16) {
            func_8AF00130(0xA9);
        }
        if (D_8AF2C66A >= 0) {
            D_8AF2C66A = 0;
            func_8AF00130(0xEB);
        }
    }
    *(s16 *)(D_8AF2C650 + 0xA) = D_8AF2C66E + D_8AF2C66A;
    if (D_8AF2C66A == 0) {
        // FAKE: D_8AF2C654 is read twice so the switch control lands in a 32-bit slot and the
        // pre-switch value in a 16-bit one; the cfe fuses both reads into one load and copies it
        // to $v0 (switch) and $a0 (sign-extended compare). Switching on the global directly with
        // a single saved value scores 20, and the 32-bit local also accounts for the 8-byte frame;
        // without it the return value is spilled at 0x1C(sp) instead of 0x18(sp).
        selected_pair = D_8AF2C654;
        previous_pair = D_8AF2C654;
        switch (selected_pair) {
        case 0:
            if (M2C_FIELD(D_8AF263C0, u16 *, 8) & 0x200) {
                D_8AF2C654 = 1;
            }
            break;
        case 1:
            if (M2C_FIELD(D_8AF263C0, u16 *, 8) & 0x100) {
                D_8AF2C654 = 0;
            }
            break;
        }
        if (previous_pair != D_8AF2C654) {
            func_8AF00130(1);
            func_8AF07300();
        }
        if (M2C_FIELD(D_8AF263C0, u16 *, 8) & 0x8000) {
            D_8AF2C656 = D_8AF2C654;
            D_8AF26550 = 1;
            switch (D_8AF2C654) {
            case 0:
                func_8AF00130(0xBE);
                func_8AF07FF0();
                result = 7;
                break;
            case 1:
                func_8AF00130(0xBE);
                result = 36;
                break;
            }
        } else if (M2C_FIELD(D_8AF263C0, u16 *, 8) & 0x4000) {
            func_8AF00130(3);
            D_8AF2C660 = 1;
        }
    }
    if (D_8AF2C66A == 0) {
        func_8AF07210();
    }
    return result;
}
/* mkdraft:func_8AF0769C end */

void func_8AF07954(void) { }
#endif
