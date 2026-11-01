#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_88229EE0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern s32 D_880068B4;
extern s32 D_882348D0;

void func_88229F08(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_882348D0);
}

extern void func_88004990(u8, u8);
void func_88229F44(void) {
    s32 offset;

    for (offset = 0; offset < 0xC; offset += 4) {
        func_88004990(**(u8 **)((u8 *)D_882348D0 + offset), 0);
    }
    D_880068B8 = 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19D160/func_88229FB0.s")

/* mkdraft:func_8822A2B4 begin */
extern void func_80048E30(u8 *, s32, s32, const char *, s32);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_8004989C(s32);
extern void func_800498C4(void);
extern void func_8004B314(s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_88002820(s32, s32, s32, s32, s32, s32, s32);
extern void func_8821D930(s32);
extern s32 D_8800687C;
// EntryCache186690 *: byte 0xC is the count of entries Deck_ReadEntries filled.
//@{src/fragments/31/fragment31_189760.c}
extern u8 *D_882347C4;
// Three 3-byte rows of RGB text colors indexed by the draw loop below.
extern u8 D_8823370C[];

// D_882348D0 is the 0xB0-byte block that func_8822A534 allocates.


void func_8822A2B4(void) {
    u32 row;
    s16 x;
    s16 y;

    func_800498C4();
    func_800496A4(4, 1);
    // unk_50: 3 selects the screen whose title bar and deck-name caption are drawn.
    if (*(s16 *)(D_882348D0 + 0x50) == 3) {
        x = *(s16 *)(*(u8 **)(D_882348D0 + 4) + 0xC) + 0x13;
        if (D_882347C4[0xC] == 0) {
            func_8004989C(0x14);
            func_80048E30(D_8800687C, x, 0x90, func_8004C874(0x25, 0x57), 1);
        } else {
            func_88002820(x, 0x90, 0, D_882348D0 + 0x78, D_882347C4[0xC], 4, D_882348D0 + 0xA0);
        }
    }
    func_80048E30(D_8800687C, 0xB2, 0x142, func_8004C874(0x25, 0x56), 1);
    func_800496A4(8, 1);
    // Rows 1 and 2 tint the label text; row 0 keeps the color left by the previous screen.
    for (row = 0, y = 0x15A; row < 3U; row++, y += 0x1A) {
        switch (row) {
        case 1:
            func_8004972C(D_8823370C[0], D_8823370C[1], D_8823370C[2], 0xFF);
            break;
        case 2:
            func_8004972C(D_8823370C[3], D_8823370C[4], D_8823370C[5], 0xFF);
            break;
        }
        func_80048E30(D_8800687C, 0xB6, y, func_8004C874(0x25, row + 0x50), 1);
    }
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    for (row = 0, y = 0x15A; row != 3; y += 0x1A, row++) {
        func_80048E30(D_8800687C, 0x100, y, func_8004C874(0x25, row + 0x53), 1);
    }
    func_8821D930(D_882348D0 + 0xC);
    if (*(s32 *)(D_882348D0 + 0x98) != 0) {
        func_8004B314(x - 6, *(s16 *)(D_882348D0 + 0x9C) * 0x14 + 0x8A, *(u16 *)(*(u8 **)(D_882348D0 + 4) + 0x10) - 0x1D, 0x1C);
    }
}
/* mkdraft:func_8822A2B4 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19D160/func_8822A534.s")
#endif
