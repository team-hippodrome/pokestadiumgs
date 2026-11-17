#include "global.h"
#include "controller.h"


#ifdef VERSION_US
// The "9" digit string that func_88223120 measures with func_80049290. The function's
// nonmatchings .s carried these bytes in its .rodata section; this definition now
// supplies the object's whole 16-byte .rodata (the [0x1A7610, .rodata,
// fragments/31/fragment31_195910] subsegment).
const char D_88234390[] = "9";

extern void func_88004EB0();
extern s32 D_880068B8;

void func_88222690(void) {
    func_88004EB0();
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern void Input_SetRepeatController(s32);
extern s32 D_880068B4;
extern s32 D_88234840;

void func_882226B4(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_88234840);
}

typedef struct unk_func_882226F0 {
    u8 *unk_00;
    s16 unk_04;
    s16 unk_06;
    u8 unk_08;
    u8 unk_09;
    s16 unk_0A;
    s16 unk_0C[3];
    s16 unk_12[3];
    s16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
} unk_func_882226F0;

extern u8 D_88006880[];

extern void func_800226C0(s32);

extern void func_88004990(u8, u8);

extern void func_8821C2F4(void);

extern void func_8821B980(u16, s32);

extern void func_8821B700(s32, s32);

extern s32 func_8821C0B0(void);

extern void func_8800225C(void *, s16, s16);

extern s32 func_88004EC0(void);

extern s32 func_8821B778(void);

extern u8 D_88234758[];

extern void func_882226F0(void);

void func_882226F0(void) {
    s16 old[2];
    s16 direction;
    s16 *value;
    s8 step;
    s16 base;
    if (D_80087200->buttonsHeld & 0xC00) {
        ((unk_func_882226F0 *)D_88234840)->unk_1C = 0;
    } else {
        ((unk_func_882226F0 *)D_88234840)->unk_1C = ((unk_func_882226F0 *)D_88234840)->unk_1C + 0x2000;
    }
    if (D_80087200->buttonsPressed & 0x4000) {
        func_800226C0(72);
        func_88004990(**(u8 **)D_88234840, 0);
        D_880068B8 = 1;
    } else if (D_80087200->buttonsPressed & 0x8000) {
        if (((unk_func_882226F0 *)D_88234840)->unk_18 == 6 && ((unk_func_882226F0 *)D_88234840)->unk_1A == 0) {
            func_800226C0(92);
            func_8821C2F4();
            D_88234758[2] = ((unk_func_882226F0 *)D_88234840)->unk_04;
            D_88234758[3] = ((unk_func_882226F0 *)D_88234840)->unk_06;
            func_8821B980(1, 1);
            if (D_88234758[3] < D_88234758[2]) func_8821B700(1, 0);
            else if (D_88234758[2] < D_88234758[3]) func_8821B700(1, 1);
            func_8821C0B0();
            func_8800225C(D_88006880, 0, 0);
            func_88004990(**(u8 **)D_88234840, 0);
            D_880068B8 = 1;
        } else if (((unk_func_882226F0 *)D_88234840)->unk_18 == 6 && ((unk_func_882226F0 *)D_88234840)->unk_1A == 1) {
            func_800226C0(311);
            func_8821C2F4();
            D_88234758[2] = 1;
            D_88234758[3] = 100;
            func_8821B980(1, 0);
            func_8821C0B0();
            func_8800225C(D_88006880, 0, 0);
            func_88004990(**(u8 **)D_88234840, 0);
            D_880068B8 = 1;
        }
    } else {
        old[0] = ((unk_func_882226F0 *)D_88234840)->unk_18;
        old[1] = ((unk_func_882226F0 *)D_88234840)->unk_1A;
        if (((unk_func_882226F0 *)D_88234840)->unk_18 == 0 && (D_80087200->buttonsPressed & 0x200)) {
            ((unk_func_882226F0 *)D_88234840)->unk_18 = 6;
            func_88004EB0();
        } else if (((unk_func_882226F0 *)D_88234840)->unk_18 == 3 && (D_80087200->buttonsPressed & 0x200)) {
            ((unk_func_882226F0 *)D_88234840)->unk_18 = 2;
            func_88004EB0();
        } else if ((((unk_func_882226F0 *)D_88234840)->unk_18 == 2 || ((unk_func_882226F0 *)D_88234840)->unk_18 == 5) && (D_80087200->buttonsPressed & 0x100)) {
            ((unk_func_882226F0 *)D_88234840)->unk_18 = ((unk_func_882226F0 *)D_88234840)->unk_18 + 1;
            func_88004EB0();
        } else if (((unk_func_882226F0 *)D_88234840)->unk_18 == 6) {
            if (D_80087200->buttonsPressed & 0x200) {
                ((unk_func_882226F0 *)D_88234840)->unk_18 = 5;
                func_88004EB0();
            } else if (D_80087200->buttonsPressed & 0x100) {
                ((unk_func_882226F0 *)D_88234840)->unk_18 = 0;
                func_88004EB0();
            } else if (func_8821B778() != 0) {
                switch (func_88004EC0()) {
                case 0x400:
                case 0x800:
                    ((unk_func_882226F0 *)D_88234840)->unk_1A = ((unk_func_882226F0 *)D_88234840)->unk_1A ^ 1;
                    break;
                }
            }
        } else {
            direction = func_88004EC0();
            if (((unk_func_882226F0 *)D_88234840)->unk_18 >= 0 && ((unk_func_882226F0 *)D_88234840)->unk_18 < 3) {
                value = &((unk_func_882226F0 *)D_88234840)->unk_04;
                base = 0;
            } else if (((unk_func_882226F0 *)D_88234840)->unk_18 >= 3 && ((unk_func_882226F0 *)D_88234840)->unk_18 < 6) {
                base = 3;
                value = &((unk_func_882226F0 *)D_88234840)->unk_06;
            }
            switch (direction) {
            case 0x200:
                ((unk_func_882226F0 *)D_88234840)->unk_18 = ((unk_func_882226F0 *)D_88234840)->unk_18 - 1;
                if (((unk_func_882226F0 *)D_88234840)->unk_18 < base) ((unk_func_882226F0 *)D_88234840)->unk_18 = base;
                break;
            case 0x100:
                ((unk_func_882226F0 *)D_88234840)->unk_18 = ((unk_func_882226F0 *)D_88234840)->unk_18 + 1;
                if (((unk_func_882226F0 *)D_88234840)->unk_18 > base + 2) ((unk_func_882226F0 *)D_88234840)->unk_18 = base + 2;
                break;
            case 0x400:
            case 0x800:
                if (!(D_80087200->buttonsHeld & 0x300)) {
                    func_800226C0(70);
                    switch (direction) {
                    case 0x800: step = 1; break;
                    case 0x400: step = -1; break;
                    }
                    if (*value == 100 && direction == 0x800) *value = 1;
                    else if (*value == 1 && direction == 0x400) *value = 100;
                    else {
                        if (((unk_func_882226F0 *)D_88234840)->unk_18 == base) *value += step * 100;
                        else if (((unk_func_882226F0 *)D_88234840)->unk_18 == base + 1) *value += step * 10;
                        else if (((unk_func_882226F0 *)D_88234840)->unk_18 == base + 2) *value += step;
                        if (*value <= 0) *value = 1;
                        else if (*value > 100) *value = 100;
                    }
                }
                break;
            }
        }
        { s32 option = old[1]; if (old[0] != *(s16 *)((u8 *)D_88234840 + 24) || option != ((unk_func_882226F0 *)D_88234840)->unk_1A) func_800226C0(70); }
    }
}
/* mkdraft:func_88222CBC begin */
extern Gfx *D_800D0510;
extern u8 D_80094DE0[];
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern f32 D_80087E50[];
extern u8 *D_8800687C;
extern u8 *D_8800ECC8;
extern u8 *D_882345D0;
extern s32 D_88234840;
extern void func_880008B0(s16, s16, s16);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void *func_8004C874(s32, s32);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
extern void func_80049668(s32);
extern void func_88000EC0(s8 *, s16, s32);
extern void func_80049628(s32, s32, s32);
extern void func_80049064(s32, s32, s32, const char *);
extern s32 func_8821B778(void);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800499EC(void);
extern void func_88002BA0(u8, u8, u8);
extern s32 func_8004D27C(u8 *, s32, s32);
extern void func_88002EC0(s16, s16, u16, u16, u8);
extern void func_8004B314(s32, s32, s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);



void func_88222CBC(void) {
    s16 y;
    s16 x;
    s8 buf[8];
    s16 n;
    s8 i;
    s16 idx;

    gSPDisplayList(D_800D0510++, D_80094DE0);
    func_880008B0(178, 179, 247);
    func_800498C4();
    func_800496A4(4, 1);
    func_80048E30(D_8800687C, 178, 157, func_8004C874(0x25, 0x30), 1);
    func_80049668(0);
    func_80048E30(D_8800687C, *(s16 *)((u8 *)D_88234840 + 0xA), 197,
                  func_8004C874(0x25, 0x31), 1);
    func_800496A4(8, 1);
    func_88000EC0(buf, *(s16 *)((u8 *)D_88234840 + 4), 1);
    for (i = 2; i >= 0; i--) {
        func_80049628(((s16 *)((u8 *)D_88234840 + 0xC))[i], 195, buf[i] + 0x30);
    }
    func_88000EC0(buf, *(s16 *)((u8 *)D_88234840 + 6), 1);
    for (i = 2; i >= 0; i--) {
        func_80049628(((s16 *)((u8 *)D_88234840 + 0x12))[i], 195, buf[i] + 0x30);
    }
    for (i = 0, n = 195; i < 2; i++, n += 0x24) {
        func_80049064(379, n, 1, func_8004C874(0x25, i + 0x32));
        if (func_8821B778() == 0) {
            func_8004972C(0xFF, 0xFF, 0xFF, 100);
        }
    }
    func_800499EC();
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_88002BA0(0xFF, 0xFF, 0xFF);
    func_8004D27C(D_8800ECC8, 0x100, 2);
    for (i = 0, n = 190; i < 2; i++, n += 0x24) {
        func_88002EC0(336, n, 87, 30, 2);
    }
    idx = *(s16 *)((u8 *)D_88234840 + 0x18);
    if (idx == 6) {
        func_8004B314(333, *(s16 *)((u8 *)D_88234840 + 0x1A) * 0x24 + 0xBB, 93, 0x24);
    } else {
        y = (s8)(D_80087E50[(*(u16 *)((u8 *)D_88234840 + 0x1C)) >> 4] * 2);
        if (idx >= 0 && idx < 3) {
            x = ((s16 *)((u8 *)D_88234840 + 0x10))[0 - idx] + 1;
        } else if (idx >= 3 && idx < 6) {
            x = ((s16 *)((u8 *)D_88234840 + 0x1C))[0 - idx] + 1;
        }
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0x00, 0xFF);
        func_8004D1FC(D_882345D0);
        GfxRect_DrawTextured(x, y + 0xB9, *(s16 *)((u8 *)D_882345D0 + 0),
                             *(s16 *)((u8 *)D_882345D0 + 2), 0, 0, 0x400, 0x400, 0);
        GfxRect_DrawTextured(x, 0xD8 - y, *(s16 *)((u8 *)D_882345D0 + 0),
                             *(u16 *)((u8 *)D_882345D0 + 2), 0,
                             (*(u16 *)((u8 *)D_882345D0 + 2) - 1) << 5, 0x400, -0x400, 0);
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_88222CBC end */

/* mkdraft:func_88223120 begin */
extern u8 D_8800ED50[];
extern u8 D_88234758[];
extern const char D_88234390[];
extern s32 func_80049290(s32 font, s32 flags, const char *text);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);

// Allocates a 0x20-byte object at D_88234840 whose first word points at entry
// func_88004804(...) of the 0x4C-byte table at D_8800ED50. Fields 0x10/0x12 of that entry are
// set to the coordinates 272 and 126 (0x110/0x7E in the asm); the object itself holds two s16
// fields (0x4, 0x6) copied from D_88234758[2..3], a u8 measured text width at 0x8, and two
// three-entry s16 tables at 0xC and 0x12 whose entries are one measured width plus one pixel apart.


void func_88223120(void) {
    s8 i;
    s16 y;

    D_88234840 = Util_Malloc(0x20);
    *(void **) D_88234840 = (void *) (D_8800ED50 + func_88004804(NULL, 3, 167, 146, 0, 1, 220, 220, 180, &func_882226F0, &func_88222CBC, (s32 *) func_88222690, (s32 *) func_882226B4, 2, 0) * 0x4C);
    *(s16 *) ((u8 *) *(void **) D_88234840 + 0x10) = 272;
    *(s16 *) ((u8 *) *(void **) D_88234840 + 0x12) = 126;
    *(s16 *) (D_88234840 + 4) = D_88234758[2];
    *(s16 *) (D_88234840 + 6) = D_88234758[3];
    *(u8 *) (D_88234840 + 8) = func_80049290(8, 0, D_88234390);
    for (i = 2, y = 182; i >= 0; i--) {
        *(s16 *) (D_88234840 + i * 2 + 0xC) = y;
        y += *(u8 *) (D_88234840 + 8) + 1;
    }
    *(s16 *) (D_88234840 + 0xA) = y + 3;
    y = *(s16 *) (D_88234840 + 0xA) + func_80049290(4, 0, func_8004C874(37, 49)) + 4;
    for (i = 2; i >= 0; i--) {
        *(s16 *) (D_88234840 + i * 2 + 0x12) = y;
        y += *(u8 *) (D_88234840 + 8) + 1;
    }
    *(s16 *) (D_88234840 + 0x18) = 2;
    *(s16 *) (D_88234840 + 0x1A) = 0;
    *(s16 *) (D_88234840 + 0x1C) = 0;
}
/* mkdraft:func_88223120 end */
#endif
