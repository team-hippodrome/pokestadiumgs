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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F5480/func_8AF0769C.s")

void func_8AF07954(void) { }
#endif
