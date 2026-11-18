#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_88223320(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern s32 D_880068B4;
extern s32 D_88234850;
void func_88223348(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_88234850);
}

extern void func_88004990(u8, s32);
void func_88223384(void) {
    func_88004990(*(*(u8 **)((u8 *)(D_88234850) + 0)), 0);
    D_880068B8 = 1;
}

extern void func_880022B4(s32, s32, s32);
void func_882233BC(s32 arg0) {
    (*(s32 *)((u8 *)(D_88234850) + (0x30))) = arg0;
    if (arg0 != 0) {
        func_880022B4(D_88234850 + 4, 0xF00, 0);
        return;
    }
    func_880022B4(D_88234850 + 4, 0xF00, 1);
}

/* mkdraft:func_88223418 begin */
extern void func_800226C0(s32);
extern s8 D_882338E0[];

// The current slot and two choices occupy the last four bytes of menu state.
// func_882241B8 allocates 56 bytes and initializes this tail at offset 0x34.
//@src/fragments/31/fragment31_1965A0.c
typedef struct F31SelectionTail {
    s16 current;
    s8 choices[2];
} F31SelectionTail;

void func_88223418(void) {
    struct {
        s8 selected;
        u8 cleared;
    } change;
    u8 index;

    change.selected = D_882338E0[*(s16 *)((s8 *)(u32)D_88234850 + 0xC)];
    change.cleared = 0;
    Input_SetRepeatController(D_80087200);
    func_882233BC(1);
    if (change.selected != ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current]) {
        func_800226C0(71);
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current] = change.selected;
    } else {
        func_800226C0(72);
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current] = -1;
        change.cleared = 1;
    }
    for (index = 0; index < 2; index++) {
        if (change.selected == ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[index] && index != ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current) {
            ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[index] = -1;
        }
    }
    if (((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[0] != -1 && ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[1] != -1) {
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current = 2;
        return;
    }
    if (change.cleared == 0) {
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current = (s16)(((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current + 1);
    }
}
/* mkdraft:func_88223418 end */

/* mkdraft:func_88223554 begin */
extern s8 D_88234758[];
extern s8 D_8823475F[];

s32 func_88223554(void) {
    s8 *output;
    s32 result;
    s32 index;
    s8 value;
    s16 sentinel;

    result = 0;
    output = D_8823475F;
    sentinel = -1;
    for (index = 0; index < 2; index = (index + 1) & 0xFF) {
        D_88234758[index + 7] = sentinel;
    }
    for (index = 0; index < 2; index = (index + 1) & 0xFF) {
        value = ((s8 *)(u32)D_88234850)[index + 0x36];
        if (sentinel != value) {
            result = 1;
            *output++ = value;
        }
    }
    return result;
}
/* mkdraft:func_88223554 end */

extern u8 D_88006020[];
extern u8 D_88006880[];
extern void func_88001900(void);
extern s32 func_880020CC();
extern void func_8800225C(void *arg0, s16 arg1, s16 arg2);
extern void func_88002720(void *arg0, u16 arg1, void *arg2);
extern s32 func_8821B7C0(void);
extern void func_8821B980(u16 arg0, s32 arg1);
extern s32 func_8821C0B0(void);
extern void func_8821C2F4(void);
// FAKE: the state block is read through a pointer-typed load of D_88234850
// (`*(u8 **)&D_88234850`). This file declares the global as s32, so the plain
// (u8 *)D_88234850 cast leaves an extra int-to-pointer copy in a1: diff 130.


void func_882235CC(void) {
    s32 index;

    if (*(s32 *)((*(u8 **)&D_88234850) + 0x30) != 0) {
        if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) != 0) {
            func_800226C0(0x48);
            func_88223384();
            return;
        }
        if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) != 0) {
            switch (*(s16 *)((*(u8 **)&D_88234850) + 0x34)) {
            case 2:
                func_800226C0(0x5C);
                func_8821C2F4();
                func_8821B980(4, func_88223554());
                func_8821C0B0();
                func_8800225C(D_88006880, 0, 0);
                func_88223384();
                return;
            case 3:
                func_800226C0(0x137);
                func_8821C2F4();
                for (index = 0; index < 2; index = (index + 1) & 0xFF) {
                    D_88234758[index + 7] = -1;
                }
                func_8821B980(4, 0);
                func_8821C0B0();
                func_8800225C(D_88006880, 0, 0);
                func_88223384();
                return;
            default:
                func_800226C0(0x47);
                func_88001900();
                func_882233BC(0);
                return;
            }
        } else {
            func_880020CC(*(u8 **)&D_88234850 + 4);
            if (func_8821B7C0() != 0) {
                func_88002720((*(u8 **)&D_88234850) + 0x34, 4, D_88006020);
            } else {
                func_88002720((*(u8 **)&D_88234850) + 0x34, 3, D_88006020);
            }
        }
    } else {
        // `index` doubles as the loop counter in case 3; the two uses never
        // overlap, and a second local adds a stack home (diff 595).
        if ((*(s16 *)((*(u8 **)&D_88234850) + 4) == 0) &&
            (*(s32 *)((*(u8 **)&D_88234850) + 8) == 0) &&
            (*(s16 *)((*(u8 **)&D_88234850) + 0x26) == 0)) {
            index = 1;
        } else {
            index = 0;
        }
        if (index != 0) {
            if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) != 0) {
                func_800226C0(0x48);
                func_882233BC(1);
                return;
            }
        }
        if ((*(s16 *)((*(u8 **)&D_88234850) + 4) == 0) &&
            (*(s32 *)((*(u8 **)&D_88234850) + 8) == 0) &&
            (*(s16 *)((*(u8 **)&D_88234850) + 0x26) == 0)) {
            index = 1;
        } else {
            index = 0;
        }
        if (index != 0) {
            if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) != 0) {
                func_88223418();
                return;
            }
        }
        func_880020CC(*(u8 **)&D_88234850 + 4);
    }
}



extern Gfx *D_800D0510;
extern Gfx D_80094DE0[];
extern Gfx D_80094E38[];
extern u8 D_88005FA0[];
extern u8 *D_8800ECFC;
extern u8 *D_8800ED04;
extern u8 *D_8800ECC8;
extern u8 *D_8800687C;
extern void func_880008B0(s16, s16, s16);
extern void func_88002BA0(u8, u8, u8);
extern s32 func_8004D1FC(u8 *);
extern s32 func_8004D27C(u8 *, s32, s32);
extern void func_88002EC0(s16, s16, u16, u16, u8);
extern void func_88000C2C(u16, s16, s16, s16, s16, u16, s16, s16, s16, s16);
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern s32 func_8004D334(s32, s32);
extern void func_8004D40C(s32);
extern void func_8004D5B8(s32, s32, s32, const char *, ...);
extern void func_800498C4();
extern void func_880006BC(u8 *);
extern void func_800496A4();
extern void *func_88000510(void *, s8);
extern void func_880006E0(void *);
extern s32 func_80063270(u8);
extern void func_80048E30(void *, s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_80049064(s32, s32, s32, const char *);
extern void func_8004972C();
extern void func_800499EC();
extern void func_8004B314(s32, s32, s32, s32);
extern void func_8004B2CC(s32, s32, s32, s32, u8, u8, u8, s32);
#define ST ((u8 *)D_88234850)
#define F(o, t) (*(t *)(ST + (o)))
#define SELECTED(i) D_882338E0[F(0xE, s16) + (i)]

void func_88223850(void) {
    u8 buf[12];
    u8 i;
    Gfx *g;
    s16 y;
    s16 a1;
    s16 a3;
    u8 n;
    s8 c;

    gSPDisplayList(D_800D0510++, D_80094DE0);
    func_880008B0(0xB2, 0xB3, 0xE4);
    n = F(0x26, s16) == 0 ? 9 : 0xA;
    for (i = 0, y = 0xC0; i < 2; i++, y += 0x26) {
        g = D_800D0510++;
        g->words.w1 = 0;
        g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        if (F(0x30, s32) != 0 || i == ((F31SelectionTail *)(ST + 0x34))->current) {
            g = D_800D0510++;
            g->words.w1 = (unsigned int)(0x09A909A9);
            g->words.w0 = _SHIFTL(G_SETFILLCOLOR, 24, 8);
        } else {
            g = D_800D0510++;
            g->words.w1 = (unsigned int)(0x39CF39CF);
            g->words.w0 = _SHIFTL(G_SETFILLCOLOR, 24, 8);
        }
        gDPFillRectangle(D_800D0510++, 185, y, 277, y + 0x19);
    }
    y = 0xD1 - F(0x26, s16);
    for (i = 0; i < n; i++, y += 0x17) {
        a3 = y;
        a1 = y + 0x15;
        if (i == 0) {
            if (y < 0xD1) {
                a3 = 0xD1;
            }
        } else if (i == 9 && a1 >= 0x19F) {
            a1 = 0x19E;
        }
        gDPPipeSync(D_800D0510++);
        if ((c = SELECTED(i)) == F(0x36, s8) || c == F(0x37, s8)) {
            if (F(0x30, s32) != 0) {
                gDPSetFillColor(D_800D0510++, 0x39D739D7);
            } else {
                gDPSetFillColor(D_800D0510++, 0x2AFF2AFF);
            }
        } else {
            if (F(0x30, s32) != 0) {
                gDPSetFillColor(D_800D0510++, 0x39CF39CF);
            } else {
                gDPSetFillColor(D_800D0510++, 0x09A909A9);
            }
        }
        gDPFillRectangle(D_800D0510++, 294, a3, 398, a1);
        a1++;
        if (a1 < 0x19F) {
            gDPPipeSync(D_800D0510++);
            if (F(0x30, s32) != 0) {
                gDPSetFillColor(D_800D0510++, 0x63196319);
            } else {
                gDPSetFillColor(D_800D0510++, 0x7D3F7D3F);
            }
            gDPFillRectangle(D_800D0510++, 294, a1, 398, a1);
        }
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_88002BA0(0xFF, 0xFF, 0xFF);
    func_8004D1FC(D_8800ECFC);
    func_8004D27C(D_8800ED04, 0x20, 1);
    func_8004D27C(D_8800ECC8, 0x100, 2);
    func_88002EC0(0x123, 0xBD, 0x6F, 0xF6, 3);
    for (i = 0, y = 0xBD; i < 2; i++, y += 0x26) {
        func_88002EC0(0xB6, y, 0x63, 0x20, 3);
    }
    for (i = 0, y = 0x10B; i < 2; i++, y += 0x24) {
        func_88002EC0(0xBC, y, 0x57, 0x1E, 2);
    }
    func_88002EC0(0x126, 0xC0, 0x69, 0x11, 2);
    func_88002EC0(0x126, 0x19F, 0x69, 0x11, 2);
    func_88000C2C((F(0xE, s16) == 0 && F(0x26, s16) == 0) ? 0 : 1, 0x141, 0xC4, 0x153, 0xC4,
                  ((u16)F(0x10, u16) - F(0x12, u8) == F(0xE, s16)) ? 0 : 1, 0x153, 0x1A3, 0x167, 0x1A3);
    func_80006F70(&D_800D0510, 0x126, 0xD1, 0x69, 0xCE);
    g = D_800D0510++;
    g->words.w1 = 0;
    g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
    func_8004D334(0xEF, 0);
    func_8004D40C(1);
    y = 0xD5 - F(0x26, s16);
    for (i = 0; i < n; i++, y += 0x17) {
        func_8004D5B8(0x13C, y, 2, "%d", i - (-1 - F(0xE, s16)));
    }
    func_800498C4();
    func_880006BC(D_88005FA0);
    func_800496A4(4, 2);
    y = 0xD4 - F(0x26, s16);
    for (i = 0; i < n; i++, y += 0x17) {
        c = SELECTED(i);
        func_880006E0(func_88000510(buf, c));
        func_80048E30(D_8800687C, 0x145, y, func_80063270(c), 1);
    }
    func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);
    func_800496A4(4, 1);
    func_880006E0(D_88005FA0);
    func_80048E30(D_8800687C, 0xB2, 0x9D, func_8004C874(0x25, 0x34), 1);
    func_800496A4(8, 1);
    y = 0xC3;
    for (i = 0; i < 2; i++, y += 0x26) {
        if (((s8 *)(ST + 0x36))[i] == -1) {
            func_880006E0(D_88005FA0);
            func_80049064(0xE7, y, 1, func_8004C874(0x25, 0x39));
        } else {
            c = ((s8 *)(ST + 0x36))[i];
            func_880006E0(func_88000510(buf, c));
            func_80049064(0xE7, y, 1, func_80063270(c));
        }
    }
    func_880006E0(D_88005FA0);
    for (i = 0, y = 0x110; i < 2; i++, y += 0x24) {
        func_80049064(0xE7, y, 1, func_8004C874(0x25, i + 0x32));
        if (func_8821B7C0() == 0) {
            func_8004972C(0xFF, 0xFF, 0xFF, 0x64);
        }
    }
    func_800499EC();
    if (F(0x30, s32) != 0) {
        s16 v = F(0x34, s16);
        if (v >= 2) {
            func_8004B314(0xB7, v * 0x24 + 0xBE, 0x61, 0x28);
        } else {
            func_8004B314(0xB1, v * 0x26 + 0xB8, 0x6D, 0x2A);
        }
    } else {
        func_8004B314(0x123, F(0x14, s16) - 3, 0x6F, 0x1C);
        func_8004B2CC(0xB1, F(0x34, s16) * 0x26 + 0xB8, 0x6D, 0x2A, 0x96, 0x96, 0x5A, 0);
    }
}

extern void *Util_Malloc(s32);
extern s32 func_88004804(s32, s32, s16, s16, s32, s32, s32, s32, s32,
                         void (*)(void), void (*)(void), void (*)(void),
                         void (*)(void), s32, s32);
extern void func_88001C6C(void *, u16, u8, s16, u8, s16, s16, s16, s16, s16, s32);
extern s32 func_80001FF0(void);
extern u8 D_8800ED50[];
extern void func_882235CC(void);
extern void func_88223850(void);

void func_882241B8(void) {
    s32 result;
    s32 index;
    s32 first_refresh_rate;

    D_88234850 = (s32)Util_Malloc(0x38);
    result = func_88004804(0, 3, 167, 146, 0, 1, 220, 220, 180,
                           func_882235CC, func_88223850, func_88223320,
                           func_88223348, 0, 0);
    *(void **)D_88234850 = D_8800ED50 + result * 0x4C;
    *(s16 *)(*(s32 *)D_88234850 + 0x10) = 253;
    *(s16 *)(*(s32 *)D_88234850 + 0x12) = 303;
    D_880068B4 = 0;
    *(s32 *)((u8 *)D_88234850 + 0x30) = 1;
    *(s16 *)((u8 *)D_88234850 + 0x34) = 0;
    for (index = 0; index < 2; index = (index + 1) & 0xFF) {
        ((s8 *)(u32)D_88234850)[index + 0x36] = D_88234758[index + 7];
    }
    first_refresh_rate = func_80001FF0();
    func_88001C6C((u8 *)D_88234850 + 4, 17, 9, 209, 23, 12,
                 (s32)(540.0f / (f32)first_refresh_rate + (0.0f < (540.0f / func_80001FF0()) ? 0.5f : -0.5f)),
                 41, 41, 12, 70);
}
/* Retail carries three zero words after the epilogue (882243B4-882243BC);
 * fragment31_1965A0.o .text must stay 0x10A0 bytes so fragment31_197640.o
 * keeps starting at 0x882243C0 (same class as fragment31_1A43F0.c). */
#endif
