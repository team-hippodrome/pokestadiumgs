#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_8AF14E40 begin */
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern u8 D_8AF27140[];

typedef struct {
    u8 r, g, b, a;
} Color;



void func_8AF14E40(s16 arg0, s16 arg1, s16 arg2, s16 arg3, Color arg4) {
    Color *color = &arg4; // FAKE: the alias makes the draw-list cursor spill at four packet sites instead of two; diff score 1466 without it.
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetEnvColor(D_800D0510++, color->r, color->g, color->b, color->a);
    gDPLoadTextureBlock(D_800D0510++, D_8AF27140, G_IM_FMT_IA, G_IM_SIZ_16b, 4, 2, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    gSPTextureRectangle(D_800D0510++, arg0 * 4, arg1 * 4,
        (arg0 + arg2) * 4, (arg1 + arg3) * 4, G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
    gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_8AF14E40 end */

extern s16 D_8AF337E8[17][17];
extern s16 Trade_GetSelectedBox(s16);
extern u8 func_80063550(u8, u8);
// Fills D_8AF337E8[attacker][defender] for the 17 type slots. Trade_GetSelectedBox
// maps a slot to a type id, and func_80063550 looks up the attacker/defender
// pair in the type matchup triples at D_80097E90.
//@src/63CF0.c
void func_8AF15080(void) {
    s32 i;
    s32 j;
    u8 attacker;
    u8 defender;

    for (i = 0; i < 17; i++) {
        attacker = Trade_GetSelectedBox(i);
        for (j = 0; j < 17; j++) {
            defender = Trade_GetSelectedBox(j);
            D_8AF337E8[i][j] = func_80063550(attacker, defender);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_2030B0/func_8AF15120.s")

extern s16 D_8AF33A30[17][17];
extern void _bzero(void *, s32);
extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern s16 func_8AF01530(s16);
void func_8AF152A8(void) {
    s32 i;
    s16 a;
    s16 b;

    _bzero(D_8AF33A30, sizeof(D_8AF33A30));
    for (i = 1; i < 252; i++) {
        a = func_8AF01530(func_8006397C(i));
        b = func_8AF01530(func_800639C0(i));
        D_8AF33A30[a][b]++;
        D_8AF33A30[b][a]++;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_2030B0/func_8AF15384.s")

extern Gfx *D_800D0510;

void func_8AF154EC(s32 arg0, s32 arg1) {
    gSPTextureRectangle(D_800D0510++, arg0 << 2, arg1 << 2,
                        (arg0 + 24) << 2, (arg1 + 24) << 2,
                        G_TX_RENDERTILE, 0, 0, 1024, 1024);
}

extern s16 D_8AF337E8[17][17];
void func_8AF15584(s16 arg0, s16 arg1, s16 arg2) {
    s32 row;
    s32 col;

    func_8AF15384(arg0 & 0xFF);
    for (row = 0; row < 17; row++) {
        for (col = 0; col < 17; col++) {
            if (arg0 == D_8AF337E8[row][col]) {
                func_8AF154EC(arg1 + col * 20, arg2 + row * 20);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_2030B0/func_8AF15670.s")

extern u8 D_8AF33770[][2];
extern s16 D_8AF33C72;
extern s16 D_8AF33C80;
// Paired-column variant of func_8AF15584. For each of the D_8AF33C80 byte pairs starting at
// pair D_8AF33C72 of D_8AF33770, and each of the 17 rows of D_8AF337E8, draws a 24x24
// rectangle with func_8AF154EC wherever the table entry for either index of the pair equals
// value. Pairs are 60 pixels apart; the second index is drawn 20 pixels right of the first
// and skipped when both indices are equal.
void func_8AF15954(s16 value, s16 x, s16 y) {
    s32 row;
    s32 col;
    u8 first;
    u8 second;

    func_8AF15384(value & 0xFF);
    for (row = 0; row < 17; row++) {
        for (col = 0; col < D_8AF33C80; col++) {
            first = D_8AF33770[D_8AF33C72 + col][0];
            second = D_8AF33770[D_8AF33C72 + col][1];
            if (value == D_8AF337E8[row][first]) {
                func_8AF154EC(x + col * 60, y + row * 20);
            }
            if (first != second && value == D_8AF337E8[row][second]) {
                func_8AF154EC(x + col * 60 + 20, y + row * 20);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_2030B0/func_8AF15AD8.s")

extern void func_8AF15670(s32);
extern void func_8AF15AD8(s32);
extern s16 D_8AF33C78;
s32 func_8AF15E80(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 1)) {
        switch (D_8AF33C78) {                       /* irregular */
        case 0:
        case 1:
            func_8AF15670(arg1);
            break;
        case 2:
        case 3:
            func_8AF15AD8(arg1);
            break;
        }
    }
    return 0;
}

extern s16 D_8AF33C72;
extern s16 D_8AF33C74;
extern s16 D_8AF33C76;
extern s16 D_8AF33C7C;

void func_8AF15EF0(void) {
    D_8AF33C72 = 0;
    D_8AF33C74 = 8;
    D_8AF33C76 = 8;
    D_8AF33C78 = 0;
    D_8AF33C7C = D_8AF33C74;
}

extern s32 D_8AF337E0;
extern s32 D_8AF337E4;
extern s16 D_8AF33C7A;
extern s16 D_8AF33C7E;
extern u8 D_8AF33C88[];
extern u8 D_8AF33CB8[];
extern u8 D_8AF33D30[];
extern s32 D_8AF33DAC;
extern s32 D_8AF33DB0;
extern s32 D_8AF33DB4;

void func_8AF15F28(void) {
    s32 temp_v0;

    func_8004C8C0(179);
    D_8AF33DAC = func_8004C990(179, 1);
    D_8AF33DB0 = func_8004C990(179, 3);
    D_8AF33DB4 = func_8004C990(179, 5);
    func_8AF0A340();
    func_8AF00504(113);
    temp_v0 = func_8AF003A8(113);
    func_8AC06E98(temp_v0);
    // The hex arguments below are four-character ASCII tags: "po_w", "ya_l", "ya_r",
    // "onof", "r_l_" and "r_r_".
    D_8AF337E0 = func_8AC06D8C(temp_v0, 0x706F5F77);
    func_8004E308(D_8AF337E0, (s32 *)func_8AF15E80, 0);
    func_8AC05ED4(temp_v0, 0x79615F6C, &D_8AF33CB8);
    func_8AC05ED4(temp_v0, 0x79615F72, &D_8AF33D30);
    D_8AF337E4 = func_8AC06D8C(temp_v0, 0x6F6E6F66);
    func_8AC02C80(temp_v0, 0x725F6C5F, 0x725F725F, D_8AF33C88);
    func_8AF15080();
    func_8AF152A8();
    D_8AF33C7A = 0;
    D_8AF33C7E = 360;
}

/* mkdraft:func_8AF16064 begin */
extern u8 D_8AF33770[][2];
extern s16 D_8AF33C72;
extern s16 D_8AF33C80;
extern s16 D_8AF33C78;
extern s16 D_8AF33C74;
extern s16 D_8AF33C76;
extern s16 D_8AF33C7C;
extern s32 D_8AF337E4;
extern s16 D_8AF33C7A;
extern s16 D_8AF33C7E;
extern u8 D_8AF33CB8[];
extern u8 D_8AF33D30[];
extern s16 D_8AF2BDDC;
extern u16 D_8AF2BDC6;
extern u8 D_8AF33C75;
extern void func_8AC007FC(void);
extern void func_8AC062A4(void *, u16);
extern void func_8AC06328(void *, u16);
extern void func_8AF00130(s32);
extern void func_8AF15120(u8);
extern void func_8AF16774(u8);
extern void func_8AF16878(u8, u8);
extern void func_8AF16EF0(s16);

// D_8AF263C0 holds &D_8AF2A590, the per-frame copy of ControllerState D_80087200 that
// func_8AF0007C takes (asm/us/data/fragments/44/fragment44_data.data.s holds the
// initialiser, and no code stores to the pointer), so the words below are the
// controller record's button fields at the same offsets.
//@include/controller.h
//@src/fragments/44/fragment44_1EE290.c
typedef struct MenuInputState {
    u8 header[6];
    /* 0x06 */ u16 held;
    /* 0x08 */ u16 pressed;
    /* 0x0A */ u16 released;
    /* 0x0C */ u16 repeat;
} MenuInputState;
extern MenuInputState *D_8AF263C0;

// Frame handler for the type matchup grid that func_8AF15F28 sets up and func_8AF15670
// draws (20 is its row spacing). D_8AF33770 holds the type pairs the C buttons pick,
// and func_8AF16774/func_8AF16878 turn a pick into a species list.
//
// D_8AF33C78 is the screen mode. Modes 0 and 3 take input: mode 0 shows the whole grid,
// mode 3 shows the grid scrolled onto the row saved in D_8AF33C7C. Modes 1 and 2 are
// scroll transitions this function only finishes: mode 1 ends when D_8AF33C7A ==
// D_8AF33C7C * 20 and D_8AF33C7E == 20 and switches to mode 3; mode 2 ends when
// D_8AF33C7A == D_8AF33C7C and D_8AF33C7E == 17 and switches to mode 0, restoring the
// saved row into D_8AF33C74. Mode 1 steps both counters by 40 per frame and mode 2 by
// 1 per frame; both are entered from outside this function.
//
// Returns a screen code: 16 stays on this screen, 17 reports a cell picked with a C
// button, 18 reports C-down or C-left moving the sub-cursor D_8AF33C76 through
// func_8AF16EF0, and 7 reports B cancelling out of mode 0.


s16 func_8AF16064(void) {
    s16 result = 16;
    s32 limit;
    // FAKE: the arms of the mode switch below reach D_8AF33C74 through this alias so
    // that each read-modify-write keeps its own address register; with the plain
    // D_8AF33C74 symbol in all four places the score is 4445.
    s16 *p74 = &D_8AF33C74;

    if (D_8AF2BDDC >= 2) {
        func_8AC007FC();
    }
    // The two vertex transforms func_8AF15F28 registers under the ASCII tags "ya_l"
    // and "ya_r"; func_8AC06328 is func_8AC062A4 with the offset subtracted instead of
    // added.
    //@src/fragments/43/fragment43_1E5A10.c
    func_8AC062A4(&D_8AF33CB8, D_8AF2BDC6);
    func_8AC06328(&D_8AF33D30, D_8AF2BDC6);

    // Holding A or B suppresses the C-button picks below. func_8AF00130 asks
    // func_800226C0 for the sound effects: 1 = cursor move and 3 = cancel, the codes
    // func_8AF133C0 also uses, with 0xC2 and 0xC3 for the C-button picks.
    if (!(D_8AF263C0->held & (A_BUTTON | B_BUTTON))) {
        // C-up or C-right picks a cell: mode 0 always takes the first pair, mode 3 the
        // pair at D_8AF33C72 + D_8AF33C74.
        switch (D_8AF33C78) {
        case 0:
            if ((D_8AF263C0->pressed & U_CBUTTONS) || (D_8AF263C0->pressed & R_CBUTTONS)) {
                func_8AF00130(0xC2);
                func_8AF15120(D_8AF33C75);
                func_8AF16774(D_8AF33770[0][0]);
                result = 17;
            }
            break;
        case 3:
            if ((D_8AF263C0->pressed & U_CBUTTONS) || (D_8AF263C0->pressed & R_CBUTTONS)) {
                func_8AF00130(0xC2);
                func_8AF16878(D_8AF33770[D_8AF33C72 + D_8AF33C74][0],
                              D_8AF33770[D_8AF33C72 + D_8AF33C74][1]);
                result = 17;
            }
            break;
        }
        // C-down or C-left moves the sub-cursor D_8AF33C76 instead.
        switch (D_8AF33C78) {
        case 0:
        case 3:
            if ((D_8AF263C0->pressed & L_CBUTTONS) || (D_8AF263C0->pressed & D_CBUTTONS)) {
                func_8AF00130(0xC2);
                func_8AF16EF0(D_8AF33C76);
                result = 18;
            }
            break;
        }
    }

    switch (D_8AF33C78) {
    case 0:
        // Bit 0 of the u16 at D_8AF337E4 + 2 is raised while the grid is in mode 0 and
        // cleared in mode 3; D_8AF337E4 is the object func_8AF15F28 looks up under the
        // ASCII tag "onof".
        *(u16 *)((u8 *)D_8AF337E4 + 2) |= 1;
        if (D_8AF263C0->pressed & B_BUTTON) {
            func_8AF00130(3);
            result = 7;
            break;
        }
        if (D_8AF263C0->pressed & A_BUTTON) {
            // A opens row D_8AF33C74: its value is saved in D_8AF33C7C for mode 3, and
            // both cursors return to 0.
            s16 v;
            func_8AF00130(0xC3);
            D_8AF33C7A = 0;
            v = *p74;
            D_8AF33C7E = 360;
            D_8AF33C7C = v;
            func_8AF15120(v);
            D_8AF33C78 = 3;
            D_8AF33C74 = 0;
            D_8AF33C72 = 0;
            break;
        }
        if (D_8AF263C0->repeat & L_JPAD) {
            s16 t = *p74;
            if (t > 0) {
                *p74 = t - 1;
                func_8AF00130(1);
                break;
            }
        }
        if (D_8AF263C0->repeat & R_JPAD) {
            s16 t = *p74;
            if (t < 16) {
                *p74 = t + 1;
                func_8AF00130(1);
                break;
            }
        }
        if (D_8AF263C0->repeat & U_JPAD) {
            if (D_8AF33C76 > 0) {
                D_8AF33C76--;
                func_8AF00130(1);
                break;
            }
        }
        if (D_8AF263C0->repeat & D_JPAD) {
            if (D_8AF33C76 < 16) {
                D_8AF33C76++;
                func_8AF00130(1);
                break;
            }
        }
        break;
    case 1: {
        // Scroll in: 40 per frame toward D_8AF33C7C * 20 for the grid scroll, and
        // D_8AF33C7E (start-up value 360, 18 rows of 20) down to 20.
        limit = D_8AF33C7C * 20;
        if (D_8AF33C7A == limit && D_8AF33C7E == 20) {
            D_8AF33C78 = 3;
            D_8AF33C74 = 0;
            D_8AF33C72 = 0;
        }
        if (D_8AF33C7A < limit) {
            D_8AF33C7A = D_8AF33C7A + 40;
            if (D_8AF33C7A > limit) {
                D_8AF33C7A = limit;
            }
        }
        if (D_8AF33C7E >= 21) {
            D_8AF33C7E -= 40;
            if (D_8AF33C7E < 20) {
                D_8AF33C7E = 20;
            }
        }
        break;
    }
    case 2: {
        // Scroll out: 1 per frame back to the start, then hand the saved row
        // D_8AF33C7C to D_8AF33C74 and return to mode 0.
        if (D_8AF33C7A == D_8AF33C7C && D_8AF33C7E == 17) {
            D_8AF33C78 = 0;
            D_8AF33C74 = D_8AF33C7C;
        }
        if (D_8AF33C7A > 0) {
            D_8AF33C7A = D_8AF33C7A - 1;
        }
        if (D_8AF33C7E < 17) {
            D_8AF33C7E++;
        }
        break;
    }
    case 3:
        *(u16 *)((u8 *)D_8AF337E4 + 2) &= ~1;
        // Either button closes the row view and restores the cursor it was opened on.
        if ((D_8AF263C0->pressed & B_BUTTON) || (D_8AF263C0->pressed & A_BUTTON)) {
            func_8AF00130(3);
            *p74 = D_8AF33C7C;
            D_8AF33C7A = 0;
            D_8AF33C7C = 0;
            D_8AF33C7E = 360;
            D_8AF33C78 = 0;
            break;
        }
        if (D_8AF263C0->repeat & L_JPAD) {
            if (D_8AF33C74 > 0) {
                D_8AF33C74 = D_8AF33C74 - 1;
                func_8AF00130(1);
            } else if (D_8AF33C72 > 0) {
                D_8AF33C72 = D_8AF33C72 - 1;
                func_8AF00130(1);
            }
            break;
        } else if (D_8AF263C0->repeat & R_JPAD) {
            // D-pad right advances the row cursor D_8AF33C74 first, bounded by
            // D_8AF33C80 - 1 and by a hard cap of 6, then the column cursor
            // D_8AF33C72 while seven further columns still fit below D_8AF33C80.
            if (D_8AF33C74 < D_8AF33C80 - 1 && D_8AF33C74 < 6) {
                D_8AF33C74++;
                func_8AF00130(1);
            } else if (D_8AF33C80 >= 8 && D_8AF33C72 + 7 < D_8AF33C80) {
                D_8AF33C72++;
                func_8AF00130(1);
            }
            break;
        }
        if (D_8AF263C0->repeat & U_JPAD) {
            if (D_8AF33C76 > 0) {
                D_8AF33C76--;
                func_8AF00130(1);
                break;
            }
        }
        if (D_8AF263C0->repeat & D_JPAD) {
            if (D_8AF33C76 < 16) {
                D_8AF33C76++;
                func_8AF00130(1);
            }
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AF16064 end */

extern s16 D_8AF33C80;
extern u8 D_8AF33CB8[];
extern u8 D_8AF33D30[];
extern void func_8AC05F00(void *);
void func_8AF1666C(void) {
    if (D_8AF33C78 == 3) {
        if (D_8AF33C72 > 0) {
            func_8AC05F00(D_8AF33CB8);
        }
        if (D_8AF33C72 + 7 < D_8AF33C80) {
            func_8AC05F00(D_8AF33D30);
        }
    }
}
#endif
