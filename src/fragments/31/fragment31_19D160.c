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

extern void func_800226C0(s32);
extern void func_8821B980(u16, s32);
extern void func_8821C0B0(void);
extern void func_8821C2F4(void);
extern void func_88229F44(void);
extern void func_8800225C(void *, s16, s16);
extern void func_88002720(s16 *, u16, void *);
extern s32 D_882348D0;
// The record cache declared as EntryCache186690 in fragment31_189760.c: three
// reference handles, the deck-entry count at 0xC, then 0x44-byte entries. Here the
// state at D_882348D0 + 0x50 selects a references[] handle and the cursor at
// D_882348D0 + 0x9C selects an entry; the two bytes copied to D_88234758 + 0x1C and
// +0x1D are at +0x36/+0x37 of either record.
//@src/fragments/31/fragment31_189760.c
typedef struct {
    s32 references[3];
    u8 count;
    u8 unk_0D[3];
    u8 entries[8][0x44];
} EntryCache186690;
extern u8 *D_882347C4;
extern u8 D_88234758[];
extern u8 D_88006880[];
#define CACHE ((EntryCache186690 *)D_882347C4)
#define FLAGS ((u8 *)D_88234758)



s32 func_88229FB0(void) {
    u8 *state;

    state = (u8 *)D_882348D0 + 0x28;
    if (D_80087200->buttonsPressed & 0x4000) {
        func_800226C0(0x48);
        if (*(s32 *)((u8 *)D_882348D0 + 0x98) != 0) {
            *(s32 *)((u8 *)D_882348D0 + 0x98) = 0;
            *(s32 *)(state + 0x24) = 1;
        } else {
            func_88229F44();
        }
    } else if (D_80087200->buttonsPressed & 0x8000) {
        if (*(s32 *)((u8 *)D_882348D0 + 0x98) == 0 && *(s16 *)(state + 0x28) == 3) {
            if (CACHE->count == 0 ||
                (CACHE->count == 1 && (*(u16 *)D_88234758 & 0x20) &&
                 *(s32 *)(FLAGS + 0x18) == 3)) {
                func_800226C0(0x49);
            } else {
                func_800226C0(0x47);
                *(s32 *)((u8 *)D_882348D0 + 0x98) = 1;
                *(s32 *)(state + 0x24) = 2;
            }
        } else {
            func_8821C2F4();
            if (*(s16 *)(state + 0x28) == 4) {
                func_800226C0(0x137);
                func_8821B980(0x20, 0);
            } else {
                func_800226C0(0x5C);
                if (*(s16 *)(state + 0x28) == 3) {
                    *(s32 *)(FLAGS + 0x18) = *(s16 *)((u8 *)D_882348D0 + 0x9C) + 3;
                    *(u8 *)(FLAGS + 0x1C) =
                        CACHE->entries[*(s16 *)((u8 *)D_882348D0 + 0x9C)][0x36];
                    *(u8 *)(FLAGS + 0x1D) =
                        CACHE->entries[*(s16 *)((u8 *)D_882348D0 + 0x9C)][0x37];
                } else {
                    *(s32 *)(FLAGS + 0x18) = *(s16 *)(state + 0x28);
                    *(u8 *)(FLAGS + 0x1C) =
                        *(u8 *)(CACHE->references[*(s16 *)(state + 0x28)] + 0x36);
                    *(u8 *)(FLAGS + 0x1D) =
                        *(u8 *)(CACHE->references[*(s16 *)(state + 0x28)] + 0x37);
                }
                func_8821B980(0x20, 1);
            }
            func_8821C0B0();
            func_8800225C(D_88006880, 0, 0);
            func_88229F44();
        }
    } else {
        if (*(s32 *)((u8 *)D_882348D0 + 0x98) != 0) {
            func_88002720((s16 *)((u8 *)D_882348D0 + 0x9C), CACHE->count,
                          (u8 *)D_882348D0 + 0xA0);
        } else {
            func_88002720((s16 *)(state + 0x28), *(u16 *)(state + 0xC), state + 0x2C);
        }
    }
    if (*(s16 *)(state + 0x28) == 3) {
        *(u8 *)(*(s32 *)((u8 *)D_882348D0 + 4) + 0x1C) = 0xDC;
        *(u8 *)(*(s32 *)((u8 *)D_882348D0 + 4) + 0x1D) = 0xDC;
        *(u8 *)(*(s32 *)((u8 *)D_882348D0 + 4) + 0x1E) = 0xB4;
    } else {
        *(u8 *)(*(s32 *)((u8 *)D_882348D0 + 4) + 0x1C) = 0x96;
        *(u8 *)(*(s32 *)((u8 *)D_882348D0 + 4) + 0x1D) = 0x96;
        *(u8 *)(*(s32 *)((u8 *)D_882348D0 + 4) + 0x1E) = 0x82;
    }
}

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

extern u8 D_88000E4C[];
extern u8 D_8800ED50[];
extern u8 D_88234758[];
extern u8 *D_882347C4;
extern void *Util_Malloc(s32 arg0);
extern void _bzero(void *, s32);
extern s32 func_80049290(s32 font, s32 flags, s32 text);
extern s32 func_88002958();
extern s32 func_88002AA8();
extern s32 func_88004804();
extern s32 func_88229FB0();
typedef struct {
    s32 enabled;
    u8 *flags;
} F31TextMask;



void func_8822A534(void) {
    u32 i;
    s32 offset;
    F31TextMask state;

    D_882348D0 = (s32)Util_Malloc(0xB0);
    for (i = 0; i < 5; i++) {
        *(s32 *)((u8 *)(u32)D_882348D0 + i * 4 + 0x5C) = func_8004C874(0x25, i + 0x4B);
    }

    i = 0;
    for (; i < D_882347C4[0xC]; i++) {
        *(void **)((u8 *)(u32)D_882348D0 + i * 4 + 0x78) = (void *)((u8 *)D_882347C4 + i * 0x44 + 0x10);
    }

    state.enabled = 0;
    state.flags = (u8 *)(u32)D_882348D0 + 0x70;
    _bzero(state.flags, 5);
    *(s32 *)((u8 *)(u32)D_882348D0 + 0xA0) = 0;
    *(s32 *)((u8 *)(u32)D_882348D0 + 0xA4) = (s32)((u8 *)(u32)D_882348D0 + 0xA8);
    _bzero((u8 *)(u32)D_882348D0 + 0xA8, 8);
    *(s16 *)((u8 *)(u32)D_882348D0 + 0x9C) = 0;

    if ((*(u16 *)D_88234758 & 0x20) == 0) {
        state.enabled = 1;
        *(u8 *)((u8 *)(u32)D_882348D0 + 0x74) = 1;
    } else {
        for (i = 0; i < 3; i++) {
            if (i == *(s32 *)((u8 *)D_88234758 + 0x18)) {
                state.enabled = 1;
                *(u8 *)((u8 *)(u32)D_882348D0 + i + 0x70) = 1;
            }
        }
        for (i = 0; i < D_882347C4[0xC]; i++) {
            if (i + 3 == *(s32 *)((u8 *)D_88234758 + 0x18)) {
                *(s32 *)((u8 *)(u32)D_882348D0 + 0xA0) = 1;
                *(u8 *)((u8 *)(u32)D_882348D0 + i + 0xA8) = 1;
                if (i == *(s16 *)((u8 *)(u32)D_882348D0 + 0x9C)) {
                    *(s16 *)((u8 *)(u32)D_882348D0 + 0x9C) += 1;
                }
            }
        }
    }

    func_88002AA8((u8 *)(u32)D_882348D0 + 0x28, 0, (u8 *)(u32)D_882348D0 + 0x5C, 5, 8, 1, 6, 0, 0, 0, 0, 0, 0, &state);
    *(s32 *)((u8 *)(u32)D_882348D0 + 0x14) = func_8004C874(0x25, 0x4A);
    *(s32 *)((u8 *)(u32)D_882348D0 + 0x10) = 0;
    *(s32 *)((u8 *)(u32)D_882348D0 + 0x18) = 4;
    *(s16 *)((u8 *)(u32)D_882348D0 + 0x1C) = 1;
    *(s16 *)((u8 *)(u32)D_882348D0 + 0x1E) = 4;

    *(s32 *)((u8 *)(u32)D_882348D0 + 0) = func_88004804((u8 *)(u32)D_882348D0 + 0xC, 2, 0xA7, 0x7C, 0, 1, 0xDC, 0xDC, 0xB4,
                           func_88229FB0, func_8822A2B4, func_88229EE0, func_88229F08, 2, 0) * 76 + D_8800ED50;

    *(s32 *)((u8 *)(u32)D_882348D0 + 4) = func_88004804(0, 3, (s16)(*(u16 *)((u8 *)*(s32 *)(u32)D_882348D0 + 0x10) + 0xAB), 0x7C, 0, 1, 0x96, 0x96, 0x82,
                           D_88000E4C, D_88000E4C, D_88000E4C, D_88000E4C, 2, 0) * 76 + D_8800ED50;
    *(u16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 4) + 0x12) = *(u16 *)((u8 *)*(s32 *)(u32)D_882348D0 + 0x12);

    if (D_882347C4[0xC] == 0) {
        *(s16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 4) + 0x10) =
            func_80049290(4, 1, func_8004C874(0x25, 0x57));
    } else {
        *(s16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 4) + 0x10) =
            func_88002958((u8 *)(u32)D_882348D0 + 0x78, D_882347C4[0xC], 4, 1);
    }

    *(s16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 4) + 0x10) =
        (*(u16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 4) + 0x10) >= 62
             ? *(u16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 4) + 0x10)
             : 61) + 41;

    *(s32 *)((u8 *)(u32)D_882348D0 + 8) = func_88004804(0, 3, 0xA7, 311, 0, 1, 0xDC, 0xDC, 0xB4,
                           D_88000E4C, D_88000E4C, D_88000E4C, D_88000E4C, 2, 0) * 76 + D_8800ED50;
    *(s16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 8) + 0x10) = 311;
    *(s16 *)((u8 *)*(s32 *)((u8 *)(u32)D_882348D0 + 8) + 0x12) = 123;
    D_880068B4 = 0;
    *(s32 *)((u8 *)(u32)D_882348D0 + 0x98) = 0;
}
#endif
