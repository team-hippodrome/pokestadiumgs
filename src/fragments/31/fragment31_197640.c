#include "global.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(void *);
extern void *D_80087200;
extern s32 D_880068B8;

void func_882243C0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern s32 D_880068B4;
extern u32 D_88234860;
void func_882243E8(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_88234860);
}

extern void func_88004990(u8, s32);
extern u32 D_88234860;
void func_88224424(void) {
    func_88004990(*(*(u8 **)((u8 *)(D_88234860) + 0)), 0);
    D_880068B8 = 1;
}

extern u32 D_88234860;
s32 func_8822445C(void) {
    typedef struct {
        u8 pad[0x36];
        u8 slots[4];
    } LookupRecord;
    s32 result;
    u8 i;

    result = 0;
    for (i = 0; i < 4; i++) {
        if (((LookupRecord *)D_88234860)->slots[i] == 0) {
            break;
        }
    }
    if (i == 4) {
        result = 1;
    }
    return result;
}

extern u32 D_88234860;
s32 func_882244B0(u8 arg0) {
    s32 result = 0;
    u8 i;
    for (i = 0; i < 4; i++) {
        if (arg0 == *((u8 *)D_88234860 + i + 0x36)) {
            result = 1;
            break;
        }
    }
    return result;
}

extern void func_880022B4(s32, s32, s32);
void func_882244F8(s32 arg0) {
    (*(s32 *)((u8 *)(D_88234860) + (0x30))) = arg0;
    if (arg0 != 0) {
        func_880022B4(D_88234860 + 4, 0xF00, 0);
        return;
    }
    func_880022B4(D_88234860 + 4, 0xF00, 1);
}

typedef struct Func88224554StateV2 {
    u8 pad00[0xC];
    s16 cursor;
    u8 pad0E[0x26];
    s16 slot;
    u8 assigned[5];
    u8 choices[256];
} Func88224554StateV2;
extern void Input_SetRepeatController(void *);
extern void func_800226C0(s32);
extern s32 func_8822445C(void);
extern void func_882244F8(s32 arg0);
extern void * D_80087200;
extern u32 D_88234860;
void func_88224554(void) {
    u8 i;
    u8 value;
    u8 cleared;

    value = ((Func88224554StateV2 *)D_88234860)->choices[((Func88224554StateV2 *)D_88234860)->cursor];
    cleared = 0;
    Input_SetRepeatController(D_80087200);
    func_882244F8(1);
    if (value != ((Func88224554StateV2 *)D_88234860)->assigned[((Func88224554StateV2 *)D_88234860)->slot]) {
        func_800226C0(0x47);
        ((Func88224554StateV2 *)D_88234860)->assigned[((Func88224554StateV2 *)D_88234860)->slot] = value;
    } else {
        func_800226C0(0x48);
        ((Func88224554StateV2 *)D_88234860)->assigned[((Func88224554StateV2 *)D_88234860)->slot] = 0;
        cleared = 1;
    }
    for (i = 0; i < 4; i++) {
        if (value != ((Func88224554StateV2 *)D_88234860)->assigned[i]) {
            continue;
        }
        if (i == ((Func88224554StateV2 *)D_88234860)->slot) {
            continue;
        }
        ((Func88224554StateV2 *)D_88234860)->assigned[i] = 0;
    }
    if (func_8822445C()) {
        ((Func88224554StateV2 *)D_88234860)->slot = 4;
    } else if (cleared == 0) {
        ((Func88224554StateV2 *)D_88234860)->slot++;
    }
}

extern u8 D_88234758[];
extern u8 D_88234761[];

s32 func_88224688(void) {
    u8 *output;
    s32 result;
    s32 index;
    u8 value;

    result = 0;
    output = D_88234761;
    for (index = 0; index < 4; index = (index + 1) & 0xFF) {
        D_88234758[index + 9] = 0;
    }
    for (index = 0; index < 4; index = (index + 1) & 0xFF) {
        value = ((u8 *)(u32)D_88234860)[index + 0x36];
        if (value != 0) {
            result = 1;
            *output++ = value;
        }
    }
    return result;
}

/* mkdraft:func_882246FC begin */
extern u8 D_88006020[];
extern u8 D_88006880[];
extern void func_88001900(void);
extern void func_880020CC(void *);
extern void func_8800225C(void *, s16, s16);
extern void func_88002720(s16 *, u16, void *);
extern void func_800226C0(s32);
extern s32 func_8821B79C(void);
extern void func_8821B980(u16, s32);
extern void func_8821C0B0(void);
extern void func_8821C2F4(void);
extern void func_88224424(void);
extern void func_882244F8(s32);
extern s32 func_88224688(void);
extern void *D_80087200;
extern u8 D_88234758[];
extern u32 D_88234860;



void func_882246FC(void) {
    u8 i;
    s32 state_empty;
    s32 buttons;

    if (*(void **)((u8 *)D_88234860 + 0x30) != NULL) {
        buttons = *(u16 *)((u8 *)D_80087200 + 8);
        if (buttons & 0x4000) {
            func_800226C0(72);
            func_88224424();
            return;
        }
        if (buttons & 0x8000) {
            switch (*(s16 *)((u8 *)D_88234860 + 0x34)) {
            case 4:
                func_800226C0(92);
                func_8821C2F4();
                func_8821B980(2, func_88224688());
                func_8821C0B0();
                func_8800225C(D_88006880, 0, 0);
                func_88224424();
                return;
            case 5:
                func_800226C0(311);
                func_8821C2F4();
                for (i = 0; i < 4; i++) {
                    *(u8 *)(D_88234758 + i + 9) = 0;
                }
                func_8821B980(2, 0);
                func_8821C0B0();
                func_8800225C(D_88006880, 0, 0);
                func_88224424();
                return;
            default:
                func_800226C0(71);
                func_88001900();
                func_882244F8(0);
                return;
            }
        }
        // Argument is the sub-record at +4: func_880020CC reads an s16 at its +0
        // and a pointer at its +4, matching the pair stored at 0x4/0x8 of this state.
        //@asm/us/nonmatchings/fragments/29/fragment29_167940/func_880020CC.s
        func_880020CC((u8 *)(D_88234860) + 4);
        if (func_8821B79C()) {
            func_88002720((s16 *)((u8 *)D_88234860 + 0x34), 6, D_88006020);
        } else {
            func_88002720((s16 *)((u8 *)D_88234860 + 0x34), 5, D_88006020);
        }
    } else {
        /* Empty-state test evaluated twice: when the 0x4000 button test below
           falls through, it joins the second copy, which feeds the 0x8000 test. */
        if (((*(s16 *)((u8 *)D_88234860 + 4) == 0) &&
             (*(void **)((u8 *)D_88234860 + 8) == NULL) &&
             (*(s16 *)((u8 *)D_88234860 + 0x26) == 0))) {
            state_empty = 1;
        } else {
            state_empty = 0;
        }
        if (state_empty != 0) {
            if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
                func_800226C0(72);
                func_882244F8(1);
                return;
            }
        }
        if (((*(s16 *)((u8 *)D_88234860 + 4) == 0) &&
             (*(void **)((u8 *)D_88234860 + 8) == NULL) &&
             (*(s16 *)((u8 *)D_88234860 + 0x26) == 0))) {
            state_empty = 1;
        } else {
            state_empty = 0;
        }
        if (state_empty != 0) {
            if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
                func_88224554();
                return;
            }
        }
        func_880020CC((u8 *)(D_88234860) + 4);
    }
}
/* mkdraft:func_882246FC end */

extern Gfx *D_800D0510;
extern Gfx D_80094DE0[];
extern Gfx D_80094E38[];
extern u8 D_88005FA0[];
extern u8 *D_8800ECFC;
extern u8 *D_8800ED04;
extern u8 *D_8800ECC8;
extern void *D_8800687C;
extern void func_880008B0(s16, s16, s16);
extern void func_88002BA0();
extern void func_8004D1FC();
extern void func_8004D27C();
extern void func_88002EC0(s16, s16, u16, u16, u8);
extern void func_88000C2C(u16, s16, s16, s16, s16, u16, s16, s16, s16, s16);
extern void func_80006F70();
extern void func_880006BC();
extern void *func_88000510(void *, s8);
extern void func_880006E0();
extern void func_80048E30();
extern void func_80049064();
extern s32 func_8004D334(s32, s32);
extern void func_8004D40C();
extern void func_8004D5B8();
extern void func_800498C4();
extern void func_800496A4();
extern void func_8004972C();
extern void func_800499EC();
extern void func_8004B314();
extern void func_8004B2CC();
extern void *func_8004C874();
extern s32 Envelope_Advance();
extern u8 *func_88000308(u8 *, s16);
extern s32 func_80062D98(u8);
extern s32 *func_80062CE0(u8);

// Menu state that D_88234860 points to.
typedef struct {
    /* 0x000 */ u8 unk_000[0xE];
    /* 0x00E */ s16 top;      // first list row shown
    /* 0x010 */ u16 count;
    /* 0x012 */ u8 visible;
    /* 0x013 */ u8 unk_013;
    /* 0x014 */ s16 cursorY;
    /* 0x016 */ u8 unk_016[0x10];
    /* 0x026 */ s16 scroll;   // pixel offset while the list scrolls
    /* 0x028 */ u8 unk_028[8];
    /* 0x030 */ s32 unk_030;  // nonzero highlights every slot box
    /* 0x034 */ s16 cursor;
    /* 0x036 */ u8 slots[4];
    /* 0x03A */ u8 unk_03A;
    /* 0x03B */ u8 list[0xFB];
    /* 0x136 */ u8 envelope[1];
} Menu8822497C;

#define MENU ((Menu8822497C *)D_88234860)
#define SET_COMBINE_DEFAULT() gDPSetCombine(D_800D0510++, 0x129A25, 0xFF37FFFF)
#define SET_COMBINE_ALT() gDPSetCombine(D_800D0510++, 0x509AA1, 0x3335FEFF)

void func_8822497C(void) {
    u8 i;
    u8 entry;
    s16 y;
    s16 rowTop;
    s16 rowBottom;
    u8 color[4];
    u8 rows;

    gSPDisplayList(D_800D0510++, D_80094DE0);
    func_880008B0(0xB2, 0x9D, 0x156);
    rows = MENU->scroll == 0 ? 10 : 11;

    // Four slot boxes on the left.
    for (i = 0, y = 0xAA; i < 4; i++, y += 0x26) {
        gDPPipeSync(D_800D0510++);
        if (MENU->unk_030 != 0 || i == MENU->cursor) {
            gDPSetFillColor(D_800D0510++, 0x09A909A9);
        } else {
            gDPSetFillColor(D_800D0510++, 0x39CF39CF);
        }
        gDPFillRectangle(D_800D0510++, 185, y, 334, y + 0x19);
    }

    // List rows on the right, clipped to the list window.
    for (i = 0, y = 0xBB - MENU->scroll; i < rows; i++, y += 0x17) {
        rowTop = y;
        rowBottom = y + 0x15;
        if (i == 0) {
            if (y < 0xBB) {
                rowTop = 0xBB;
            }
        } else if (i == 10) {
            if (rowBottom >= 0x1A0) {
                rowBottom = 0x19F;
            }
        }
        gDPPipeSync(D_800D0510++);
        if (func_882244B0(MENU->list[MENU->top + i]) != 0) {
            if (MENU->unk_030 != 0) {
                gDPSetFillColor(D_800D0510++, 0x39D739D7);
            } else {
                gDPSetFillColor(D_800D0510++, 0x2AFF2AFF);
            }
        } else {
            if (MENU->unk_030 != 0) {
                gDPSetFillColor(D_800D0510++, 0x39CF39CF);
            } else {
                gDPSetFillColor(D_800D0510++, 0x09A909A9);
            }
        }
        gDPFillRectangle(D_800D0510++, 351, rowTop, 512, rowBottom);
        rowBottom++;
        if (rowBottom < 0x1A0) {
            gDPPipeSync(D_800D0510++);
            if (MENU->unk_030 != 0) {
                gDPSetFillColor(D_800D0510++, 0x63196319);
            } else {
                gDPSetFillColor(D_800D0510++, 0x7D3F7D3F);
            }
            gDPFillRectangle(D_800D0510++, 351, rowBottom, 512, rowBottom);
        }
    }

    gSPDisplayList(D_800D0510++, D_80094E38);
    func_88002BA0(0xFF, 0xFF, 0xFF);
    func_8004D1FC(D_8800ECFC);
    func_8004D27C(D_8800ED04, 0x20, 1);
    func_8004D27C(D_8800ECC8, 0x100, 2);
    func_88002EC0(0x15C, 0xA7, 0xA8, 0x10D, 3);
    for (i = 0, y = 0xA7; i < 4; i++, y += 0x26) {
        func_88002EC0(0xB6, y, 0x9C, 0x20, 3);
    }
    for (i = 0, y = 0x141; i < 2; i++, y += 0x24) {
        func_88002EC0(0xD8, y, 0x57, 0x1E, 2);
    }
    func_88002EC0(0x15F, 0xAA, 0xA2, 0x11, 2);
    func_88002EC0(0x15F, 0x1A0, 0xA2, 0x11, 2);
    // Scroll arrows: up unless at the top, down unless at the end.
    func_88000C2C((MENU->top == 0 && MENU->scroll == 0) ? 0 : 1, 0x196, 0xAE, 0x1A8, 0xAE,
                  (MENU->top == MENU->count - MENU->visible) ? 0 : 1, 0x1A8, 0x1A4, 0x1BC, 0x1A4);

    func_80006F70(&D_800D0510, 0x15F, 0xBB, 0xA2, 0xE5);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
    func_8004D334(0xEF, 0);
    func_8004D40C(1);
    for (i = 0, y = 0xBF - MENU->scroll; i < rows; i++, y += 0x17) {
        func_8004D5B8(0x17E, y, 2, "%d", i + MENU->top + 1);
    }
    func_800498C4();
    func_880006BC(D_88005FA0);
    func_88000308(color, Envelope_Advance(MENU->envelope));
    // gDPSetPrimColor(color[0], color[1], color[2], 255), with the channels in the order retail ORs them.
    {
        Gfx *g = D_800D0510++;

        g->words.w0 = 0xFA000000;
        g->words.w1 = _SHIFTL(color[1], 16, 8) | _SHIFTL(color[2], 8, 8) | _SHIFTL(color[0], 24, 8) |
                      _SHIFTL(0xFF, 0, 8);
    }
    func_800496A4(4, 2);
    for (i = 0, y = 0xBE - MENU->scroll; i < rows; i++, y += 0x17) {
        entry = MENU->list[MENU->top + i];
        gDPPipeSync(D_800D0510++);
        func_880006E0(func_88000510(color, func_80062D98(entry)));
        if (entry >= 0xA6) {
            SET_COMBINE_ALT();
        } else {
            SET_COMBINE_DEFAULT();
        }
        func_80048E30(D_8800687C, 0x187, y, func_80062CE0(entry), 1);
    }
    func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);

    func_800496A4(4, 1);
    gDPPipeSync(D_800D0510++);
    func_880006E0(D_88005FA0);
    SET_COMBINE_DEFAULT();
    func_80048E30(D_8800687C, 0xB2, 0x87, func_8004C874(0x25, 0x35), 1);
    func_800496A4(8, 1);
    for (i = 0, y = 0xAD; i < 4; i++, y += 0x26) {
        gDPPipeSync(D_800D0510++);
        if (*((u8 *)D_88234860 + i + 0x36) == 0) {
            func_880006E0(D_88005FA0);
            SET_COMBINE_DEFAULT();
            func_80049064(0x104, y, 1, func_8004C874(0x25, 0x38));
        } else {
            entry = *((u8 *)D_88234860 + i + 0x36);
            func_880006E0(func_88000510(color, func_80062D98(entry)));
            if (entry >= 0xA6) {
                SET_COMBINE_ALT();
            } else {
                SET_COMBINE_DEFAULT();
            }
            func_80049064(0x104, y, 1, func_80062CE0(entry));
        }
    }
    gDPPipeSync(D_800D0510++);
    func_880006E0(D_88005FA0);
    SET_COMBINE_DEFAULT();
    for (i = 0, y = 0x146; i < 2; i++, y += 0x24) {
        func_80049064(0x103, y, 1, func_8004C874(0x25, i + 0x32));
        if (func_8821B79C() == 0) {
            func_8004972C(0xFF, 0xFF, 0xFF, 0x64);
        }
    }
    func_800499EC();

    // Cursor highlight.
    if (MENU->unk_030 != 0) {
        s16 cursor = MENU->cursor;

        if (cursor >= 4) {
            func_8004B314(0xD3, cursor * 0x24 + 0xAC, 0x61, 0x28);
        } else {
            func_8004B314(0xB1, cursor * 0x26 + 0xA2, 0xA6, 0x2A);
        }
    } else {
        func_8004B314(0x15C, MENU->cursorY - 3, 0xA8, 0x1C);
        func_8004B2CC(0xB1, MENU->cursor * 0x26 + 0xA2, 0xA6, 0x2A, 0x96, 0x96, 0x5A, 0);
    }
}

#undef MENU
#undef SET_COMBINE_DEFAULT
#undef SET_COMBINE_ALT

// Unreferenced empty strings that follow func_8822497C's "%d" in .rodata.
const char D_882343B4[] = "";
const char D_882343B8[] = "";
const char D_882343BC[] = "";

extern void *Util_Malloc(s32);
extern s32 D_880068B4;
extern u32 D_88234860;
extern u8 D_88234758[];
extern u8 D_8800ED50[];
extern s32 func_80001FF0(void);
extern u8 func_80073510(u8 arg0);
extern s32 func_8800005C(void);
extern void func_88000288(void *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
extern void func_88001C6C(void *arg0, u16 arg1, u8 arg2, s16 arg3, u8 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s32 arg10);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern void func_882243C0(void);
extern void func_882243E8(void);



void func_882254B8(void)
{
  // FAKE: unused stack words. The two words size the local area to the target
  // frame of 0xA0; without the array the frame is 0x98 (5 differing rows), and
  // pad[1] scores 28 rows.
  s32 pad[2];
  f32 var_fv0;
  f32 var_fv1;
  f32 h[3][2];
  s32 sp74;
  s32 sp70;
  f32 sp6C;
  s32 sp68;
  f32 sp64;
  f32 var_fv0_2;
  f32 rat6;
  f32 rat8;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_s1;
  s32 temp_s2;
  s32 temp_s3;
  u8 var_s0;
  s32 var_s1;
  u8 temp_a0;
  u8 temp_t9;
  u8 temp_v0;
  void *temp_t0;
  D_88234860 = Util_Malloc(0x144);
    *((void **) (((u8 *) D_88234860) + 0)) = (void *) ((func_88004804(NULL, 3, 0xA7, 0x7C, 0, 1, 0xDC, 0xDC, 0xB4, &func_882246FC, &func_8822497C, (s32 *) func_882243C0, (s32 *) func_882243E8, 0, 0) * 0x4C) + D_8800ED50);
    *((s16 *) (((u8 *) (*((void **) (((u8 *) D_88234860) + 0)))) + 0x10)) = 0x16F;
      // FAKE: the stores below and the fill loop share one physical source
      // line. Splitting them changes IDO's line-based grouping of statements and
      // swaps addiu v0,v0,0 with move s1,zero (2 extra differing rows).
 var_s1 = 0; *((s16 *) (((u8 *) (*((void **) (((u8 *) D_88234860) + 0)))) + 0x12)) = 0x146; D_880068B4 = 0; *((s32 *) (((u8 *) D_88234860) + 0x30)) = 1; *((s16 *) (((u8 *) D_88234860) + 0x34)) = 0; do { *((u8 *) (((u8 *) D_88234860) + var_s1) + 0x36) = *((u8 *) (((u8 *) (&D_88234758[var_s1])) + 9)); var_s1 = (var_s1 + 1) & 0xFF; } while (var_s1 < 4);
      if (func_8800005C() != 0)
      {
        *((u8 *) (((u8 *) D_88234860) + 0x3A)) = 0xA4U;
      }
      else
      {
        *((u8 *) (((u8 *) D_88234860) + 0x3A)) = 0xFAU;
      }
      var_s0 = 0;
      var_s1 = 0;
      if (((s32) (*((u8 *) (((u8 *) D_88234860) + 0x3A)))) > 0)
      {
        do
        {
          // FAKE: both gotos retry the current iteration, matching the target's
          // 0x12c8 back edge. Removing the label and the jumps scores 408 rows.
          loop_7:
          *((u8 *) (((u8 *) (D_88234860 + var_s1)) + 0x3B)) = func_80073510(var_s0 + 1);

          if ((*((u8 *) (((u8 *) D_88234860) + 0x3A))) == 0xA4)
          {
            if ((*((u8 *) (((u8 *) (&((u8 *) D_88234860)[var_s1])) + 0x3B)) == 0xA5) || (((s32) *((u8 *) (((u8 *) (&((u8 *) D_88234860)[var_s1])) + 0x3B))) >= 0xA6))
            {
              var_s0++;
              goto loop_7;
            }
          }
          else
            if ((*((u8 *) (((u8 *) (&((u8 *) D_88234860)[var_s1])) + 0x3B))) == 0xA5)
          {
            var_s0++;
            goto loop_7;
          }
          var_s1 = (var_s1 + 1) & 0xFF;
          var_s0++;
        }
        while (var_s1 < ((s32) (*((u8 *) (((u8 *) D_88234860) + 0x3A)))));
      }
      if (((((f32) func_80001FF0()) * 8.0f) / 60.0f) > 0.0f)
      {
        sp64 = 0.5f;
      }
      else
      {
        sp64 = -0.5f;
      }
      sp68 = func_80001FF0();
      if (((((f32) func_80001FF0()) * 5.0f) / 60.0f) > 0.0f)
      {
        sp6C = 0.5f;
      }
      else
      {
        sp6C = -0.5f;
      }
      sp70 = func_80001FF0();
      sp74 = func_80001FF0();
      if (((((f32) func_80001FF0()) * 30.0f) / 60.0f) > 0.0f)
      {
        h[0][0] = 0.5f;
      }
      else
      {
        h[0][0] = -0.5f;
      }
      temp_s3 = func_80001FF0();
      if (((((f32) func_80001FF0()) * 5.0f) / 60.0f) > 0.0f)
      {
        h[1][0] = 0.5f;
      }
      else
      {
        h[1][0] = -0.5f;
      }
      temp_s2 = func_80001FF0();
      if (((((f32) func_80001FF0()) * 8.0f) / 60.0f) > 0.0f)
      {
        h[2][0] = 0.5f;
      }
      else
      {
        h[2][0] = -0.5f;
      }
      temp_s1 = func_80001FF0();
      if (((((f32) func_80001FF0()) * 30.0f) / 60.0f) > 0.0f)
      {
        var_fv1 = 0.5f;
      }
      else
      {
        var_fv1 = -0.5f;
      }
      temp_s0 = func_80001FF0();
      var_fv0 = (((((f32) func_80001FF0()) * 8.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f);
      // FAKE: the (0, 30.0f) and (0, 8.0f) comma expressions are load-bearing.
      // Hoisting the two ratios into plain f32 locals makes both operands of the
      // following add.s plain loads, so the sign-first operand order of the two
      // last arguments survives; plain 30.0f/8.0f literals score 80 rows.
      rat6 = (((0, 30.0f)) * ((f32) temp_s1)) / 60.0f;
      rat8 = (((0, 8.0f)) * ((f32) temp_s0)) / 60.0f;
      func_88000288(D_88234860 + 0x136, (s16) ((((s32) (h[0][0] + ((30.0f * ((f32) sp74)) / 60.0f))) + ((s32) (((5.0f * ((f32) sp70)) / 60.0f) + sp6C))) + ((s32) (((8.0f * ((f32) sp68)) / 60.0f) + sp64))), 0xFF, 0, (u8) ((s32) (h[1][0] + ((5.0f * ((f32) temp_s3)) / 60.0f))), (u8) ((s32) (h[2][0] + ((8.0f * ((f32) temp_s2)) / 60.0f))), (u8) ((s32) (var_fv1 + rat6)), (u8) ((s32) (var_fv0 + rat8)));
      temp_s0_2 = func_80001FF0();
      if ((540.0f / ((f32) func_80001FF0())) > 0.0f)
      {
        var_fv0_2 = 0.5f;
      }
      else
      {
        var_fv0_2 = -0.5f;
      }
      func_88001C6C(((u8 *) D_88234860) + 4, (u16) (*((u8 *) (((u8 *) D_88234860) + 0x3A))), 0xAU, 0xBB, 0x17U, 0xC, (s16) ((s32) ((f32) var_fv0_2 + (540.0f / ((f32) temp_s0_2)))), 0x2E, 0x2E, 0xC, 0x46);
}

void func_88225B70(void) {
    D_880068B8 = 0;
}

extern u8 D_8823474C;
void func_88225B7C(void) { D_880068B8 = 1; D_8823474C = 2; }

extern void func_888002DC(void);
void func_88225B98(void) { D_880068B4 = 1; func_888002DC(); }

extern void func_88800020();
s32 func_88802DCC(s32, s32, void (*)(), void (*)(), void (*)(), s32 *, s32, s32);
extern u8 func_882313A4;

void func_88225BC0(s32 arg0) {
    func_88800020();
    func_88802DCC(0, arg0, func_88225B70, func_88225B98, func_88225B7C, &func_882313A4, 2, 0);
}

void func_88225C20(void) { Input_SetRepeatController(D_80087200); D_880068B8 = 0; }

extern u8 *D_88234870;
extern void func_88001900(void);
void func_88225C48(void) {
    u32 i;

    Input_SetRepeatController(D_80087200);
    func_88001900();
    D_880068B4 = 1;
    for (i = 0; i < *(u16 *)(D_88234870 + 0x18); i++) {
        Util_Free((*(s32 **)(D_88234870 + 0x78))[i]);
    }
    for (i = 0; i < *(u16 *)(D_88234870 + 0x28); i++) {
        Util_Free((*(s32 **)(D_88234870 + 0x7C))[i]);
    }
    Util_Free(*(s32 *)(D_88234870 + 0x78));
    Util_Free(*(s32 *)(D_88234870 + 0x7C));
    Util_Free(*(s32 *)(D_88234870 + 0x98));
    Util_Free(*(s32 *)(D_88234870 + 0x9C));
    Util_Free(*(s32 *)(D_88234870 + 0xA8));
    Util_Free(*(s32 *)(D_88234870 + 0xAC));
    Util_Free(D_88234870);
    main_pool_pop_state(0x4C53424C);
}

extern u8 *D_88A01C30;
extern u8 *D_88A01C34;
extern u8 *D_88234870;
void func_88225D80(s32 direction) {
    u8 *groups;
    u8 *entries;
    s32 i;
    u32 j;
    for (i = 0, groups = D_88A01C30, entries = D_88A01C34; i < 3; i++) {
        for (j = 0; j < groups[0x10]; j++) {
            switch (i) {
            case 0:
                if (direction == 0) {
                    D_88234870[0x94] = *(s32 *)(entries + 8);
                } else {
                    *(s32 *)(entries + 8) = D_88234870[0x94];
                }
                break;
            case 1:
                if (direction == 0) {
                    (*(u8 **)(D_88234870 + 0x98))[j] = *(s32 *)(entries + 8);
                } else {
                    *(s32 *)(entries + 8) = (*(u8 **)(D_88234870 + 0x98))[j];
                }
                break;
            case 2:
                if (direction == 0) {
                    (*(u8 **)(D_88234870 + 0x9C))[j] = *(s32 *)(entries + 8);
                } else {
                    *(s32 *)(entries + 8) = (*(u8 **)(D_88234870 + 0x9C))[j];
                }
                break;
            }
            entries += 0x18;
        }
        groups += 0x14;
    }
}

extern u8 *D_88234870;
s32 func_88225EA0(void) {
    u32 index;
    s32 result;
    u8 *state;
    u32 count;
    u8 *entry;
    result = 0;
    index = 0;
    state = D_88234870;
    count = *(u16 *)(state + 0x18);
    if (count != 0) {
        entry = *(u8 **)(state + 0x98);
loop:
        if (*entry != 0) {
            result = 1;
            goto done;
        }
        index++;
        entry++;
        if (index < count) {
            goto loop;
        }
    }
done:
    return result;
}

s32 func_88225EEC(void) {
    u32 index;
    s32 result;
    u8 *state;
    u32 count;
    u8 *entry;
    result = 0;
    index = 0;
    state = D_88234870;
    count = *(u16 *)(state + 0x28);
    if (count != 0) {
        entry = *(u8 **)(state + 0x9C);
loop:
        if (*entry != 0) {
            result = 1;
            goto done;
        }
        index++;
        entry++;
        if (index < count) {
            goto loop;
        }
    }
done:
    return result;
}

extern s32 func_88225EA0(void);
extern s32 func_88225EEC(void);
extern u8 * D_88234870;
void func_88225F38(void)
{
  s32 first;
  s32 second;
  first = func_88225EA0();
  second = func_88225EEC();
  if (((second + (*(((u8 *) D_88234870) + 0x94))) + first) != ((0, 0)))
  {
    *((s32 *) (((u8 *) D_88234870) + 0x88)) = 0;
    *(((u8 *) D_88234870) + 0x93) = 0;
  }
  else
  {
    *((s32 *) (((u8 *) D_88234870) + 0x88)) = 1;
    *(((u8 *) D_88234870) + 0x93) = 1;
  }
}

extern u8 * D_88234870;
s32 func_88225FA8(void) {
    u32 i;
    s8 *p;

    i = 0;
    p = (s8 *)D_88234870 + 0xA0;
    for (; i < 3; i++, p += 2) {
        if (*p != 0) {
            return 1;
        }
    }
    i = 0;
    p = *(s8 **)((u8 *)D_88234870 + 0xA8);
    for (; i < *(u16 *)((u8 *)D_88234870 + 0x18); i++, p += 2) {
        if (*p != 0) {
            return 1;
        }
    }
    i = 0;
    p = *(s8 **)((u8 *)D_88234870 + 0xAC);
    for (; i < *(u16 *)((u8 *)D_88234870 + 0x28); i++, p += 2) {
        if (*p != 0) {
            return 1;
        }
    }
    return 0;
}

void func_88226058(u8 *arg0, u8 arg1) { arg0[1] = arg1 ? 1 : -1; }

void func_88226080(void *arg0) {
    s8 temp_v0;
    s8 temp_v0_2;
    s8 temp_v0_3;

    temp_v0 = (*(s8 *)((u8 *)(arg0) + (1)));
    if (temp_v0 > 0) {
        (*(s8 *)((u8 *)(arg0) + (0))) = (s8) ((*(s8 *)((u8 *)(arg0) + (0))) + 1);
        temp_v0_2 = (*(s8 *)((u8 *)(arg0) + (0)));
        if (temp_v0_2 == 0) {
            (*(s8 *)((u8 *)(arg0) + (1))) = 0;
            return;
        }
        if (temp_v0_2 == 2) {
            (*(s8 *)((u8 *)(arg0) + (1))) = -1;
        }
    } else if (temp_v0 < 0) {
        (*(s8 *)((u8 *)(arg0) + (0))) = (s8) ((*(s8 *)((u8 *)(arg0) + (0))) - 1);
        temp_v0_3 = (*(s8 *)((u8 *)(arg0) + (0)));
        if (temp_v0_3 == 0) {
            (*(s8 *)((u8 *)(arg0) + (1))) = 0;
            return;
        }
        if (temp_v0_3 == -2) {
            (*(s8 *)((u8 *)(arg0) + (1))) = 1;
        }
    }
}

extern void func_88226080(void *arg0);
extern u8 * D_88234870;
void func_88226100(void) {
    u32 i;
    u16 *p;

    i = 0;
    p = (u16 *)((u8 *)D_88234870 + 0xA0);
    for (; i < 3; i++, p++) {
        func_88226080(p);
    }
    i = 0;
    p = *(u16 **)((u8 *)D_88234870 + 0xA8);
    for (; i < *(u16 *)((u8 *)D_88234870 + 0x18); i++, p++) {
        func_88226080(p);
    }
    i = 0;
    p = *(u16 **)((u8 *)D_88234870 + 0xAC);
    for (; i < *(u16 *)((u8 *)D_88234870 + 0x28); i++, p++) {
        func_88226080(p);
    }
}

// func_80044424 truncates dsdx/dtdy to s16 internally, but this call site passes
// the full 32-bit rounded ratios: the target stores the mfc1 results straight
// into the 0x18/0x1C stack arguments with no sll/sra pair.
//@src/44E70.c
extern void func_80044424(s16, s16, s16, s16, s16, s16, s32, s32, s32, s32);

#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))



void func_882261CC(s16 arg0, s16 arg1, u16 arg2, u16 arg3, u8 arg4, s8 arg5) {
    f32 ratio_x;
    f32 ratio_y;
    s32 growth;
    u16 base_x;
    u16 base_y;

    growth = arg5 * 2;
    base_x = arg2;
    base_y = arg3;
    arg2 = (arg2 + growth) & 0xFFFF;
    arg3 = (arg3 + growth) & 0xFFFF;
    // Base-to-grown extent ratio in Q10, passed as the texture-coordinate gradients.
    ratio_x = (f32) base_x * 1024.0f / (f32) arg2;
    ratio_y = (f32) base_y * 1024.0f / (f32) arg3;
    func_80044424((s16) (arg0 - arg5), (s16) (arg1 - arg5), (s16) arg2, (s16) arg3,
        0, 0, (s32) ROUND_MAX(ratio_x), (s32) ROUND_MAX(ratio_y), 0, arg4);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_197640/func_88226378.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_197640/func_88226918.s")

extern u8 D_88000E4C[];
extern s8 D_88006868;
extern void *func_8004C874(s32, void *);
extern void func_88226378(void);
extern void func_88226918(void);
extern void _bzero(void *, s32);
extern s32 func_8003514C(void);
extern void func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);
extern u16 func_800532C4(s32);
extern void func_80053524(s32, void *);
extern u16 func_8005CB38(s8, s32);
extern void func_8005EE88(s8, u32, void *);
extern void func_88002AA8(u8 *, s32, u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, void *);
extern s32 func_880032C4(void *);
extern void main_pool_push_state(s32);

#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))

typedef struct Func88227224Pair {
    s32 unk0;
    s32 unk4;
} Func88227224Pair;



void func_88227224(void) {
    s32 var_v0;
    s32 var_s0;
    s32 var_s1_2;
    u32 var_s1;

    main_pool_push_state(0x4C53424C);
    D_88234870 = Util_Malloc(0xC0U);
    func_8004C8C0(0x12);
    M2C_FIELD(D_88234870, s32 *, 0xB0) = func_8004C990(0x12, 1);
    M2C_FIELD(D_88234870, s32 *, 0xB4) = func_8004C990(0x12, 0);
    M2C_FIELD(D_88234870, s32 *, 0xB8) = func_8004C990(0x12, 3);
    M2C_FIELD(D_88234870, s32 *, 0xBC) = func_8004C990(0x12, 2);
    if (func_8800005C() != 0) {
        M2C_FIELD(D_88234870, u8 *, 0) = 3;
    } else {
        M2C_FIELD(D_88234870, u8 *, 0) = 2;
    }
    M2C_FIELD(D_88234870, s32 *, 0x10) = 1;
    M2C_FIELD(D_88234870, u16 *, 0x18) = func_8005CB38(D_88006868, 0x21);
    M2C_FIELD(D_88234870, u16 *, 0x28) = func_800532C4(0x11);
    M2C_FIELD(D_88234870, u8 **, 0x78) = Util_Malloc(M2C_FIELD(D_88234870, u16 *, 0x18) * 4);
    var_s1 = 0;
    M2C_FIELD(D_88234870, u8 **, 0x7C) = Util_Malloc(M2C_FIELD(D_88234870, u16 *, 0x28) * 4);
    var_s0 = 0;
    for (var_s1 = 0; var_s1 < (u16) M2C_FIELD(D_88234870, u16 *, 0x18); var_s1++) {
        *(void **)(*(u8 **)(D_88234870 + 0x78) + var_s1 * 4) = Util_Malloc(9U);
        func_8005EE88(D_88006868, var_s1, *(void **)(*(u8 **)(D_88234870 + 0x78) + var_s1 * 4));
    }
    for (var_s1 = 0; var_s1 < (u16) M2C_FIELD(D_88234870, u16 *, 0x28); var_s1++) {
        *(void **)(*(u8 **)(D_88234870 + 0x7C) + var_s1 * 4) = Util_Malloc(0x12U);
        func_80053524(var_s1, *(void **)(*(u8 **)(D_88234870 + 0x7C) + var_s1 * 4));
    }
    M2C_FIELD(D_88234870, s32 *, 0x14) = (s32) M2C_FIELD(D_88234870, s32 *, 0x78);
    M2C_FIELD(D_88234870, u8 **, 0x24) = (u8 *) M2C_FIELD(D_88234870, u8 **, 0x7C);
    M2C_FIELD(D_88234870, s32 *, 0x34) = 4;
    M2C_FIELD(D_88234870, s16 *, 0x38) = 1;
    M2C_FIELD(D_88234870, s16 *, 0x3A) = 4;
    M2C_FIELD(D_88234870, s16 *, 0x1A) = 0;
    M2C_FIELD(D_88234870, s16 *, 0x2A) = 0;
    *(Func88227224Pair *)(D_88234870 + 0x1C) = *(Func88227224Pair *)D_88006020;
    *(Func88227224Pair *)(D_88234870 + 0x2C) = *(Func88227224Pair *)D_88006020;
    if (func_880032C4(&D_88006020) == 0) {
        var_s1_2 = 0;
    } else {
        var_s1_2 = 2;
    }
    M2C_FIELD(D_88234870, void **, 4) = (void *) ((func_88004804(NULL, 3, 0xA7, 0x92, 0, 1, 0xDC, 0xDC, 0xB4, &func_88226378, &func_88226918, func_88225C20, func_88225C48, var_s1_2, 0) * 0x4C) + D_8800ED50);
    M2C_FIELD(M2C_FIELD(D_88234870, void **, 4), s16 *, 0x10) = 0xCA;
    M2C_FIELD(M2C_FIELD(D_88234870, void **, 4), s16 *, 0x12) = 0xA7;
    if (func_8003514C() == 0) {
        var_v0 = 0x92;
    } else {
        var_v0 = 0x7E;
    }
    M2C_FIELD(D_88234870, void **, 8) = (void *) ((func_88004804(D_88234870 + 0x10, 1, 0x175, var_v0, 0, 1, 0x96, 0x96, 0x82, (s32) D_88000E4C, (s32) D_88000E4C, (void (*)()) (s32) D_88000E4C, (void (*)()) (s32) D_88000E4C, var_s1_2, 0) * 0x4C) + D_8800ED50);
    if (M2C_FIELD(D_88234870, u8 *, 0) == 3) {
        M2C_FIELD(D_88234870, void **, 0x74) = func_8004C874(0x25, (void *)0x36);
        func_88002AA8(D_88234870 + 0x40, 0, D_88234870 + 0x74, 1, 8, 1, 6, 0xF, 0x12, 0xD, 0x10, 0, 0, &D_88006020);
        M2C_FIELD(D_88234870, void **, 0xC) = (void *) ((func_88004804(D_88234870 + 0x40, 0, 0x170, 0x13D, 2, 1, 0x96, 0x96, 0x82, (s32) D_88000E4C, (s32) D_88000E4C, (void (*)()) (s32) D_88000E4C, (void (*)()) (s32) D_88000E4C, var_s1_2, 0) * 0x4C) + D_8800ED50);
    }
    D_880068B4 = 0;
    M2C_FIELD(D_88234870, u8 **, 0x98) = Util_Malloc(M2C_FIELD(D_88234870, u16 *, 0x18));
    M2C_FIELD(D_88234870, u8 **, 0x9C) = Util_Malloc(M2C_FIELD(D_88234870, u16 *, 0x28));
    func_88225D80(0);
    M2C_FIELD(D_88234870, s32 *, 0x80) = 1;
    M2C_FIELD(D_88234870, s16 *, 0x84) = 3;
    _bzero(D_88234870 + 0x90, 4);
    M2C_FIELD(D_88234870, u8 **, 0x8C) = (u8 *) (D_88234870 + 0x90);
    func_88225F38();
    _bzero(D_88234870 + 0xA0, 6);
    M2C_FIELD(D_88234870, u8 **, 0xA8) = Util_Malloc(M2C_FIELD(D_88234870, u16 *, 0x18) * 2);
    _bzero(M2C_FIELD(D_88234870, u8 **, 0xA8), M2C_FIELD(D_88234870, u16 *, 0x18) * 2);
    M2C_FIELD(D_88234870, u8 **, 0xAC) = Util_Malloc(M2C_FIELD(D_88234870, u16 *, 0x28) * 2);
    _bzero(M2C_FIELD(D_88234870, u8 **, 0xAC), M2C_FIELD(D_88234870, u16 *, 0x28) * 2);
}

void func_882277D0(void) { Input_SetRepeatController(D_80087200); D_880068B8 = 0; }

typedef struct Func882277F8Data {
    u8 pad00[0x10];
    u16 countA;
    u8 pad12[6];
    s32 blockA;
    u8 pad1C[4];
    u16 countB;
    u8 pad22[6];
    s32 blockB;
    u8 pad2C[12];
    s32 *arrayA;
    s32 *arrayB;
} Func882277F8Data;
extern void Util_Free(s32);
extern void * D_88234880;
void func_882277F8(void) {
    u32 i;

    for (i = 0; i < *(u16 *)((u8 *)D_88234880 + 0x10); i++) {
        Util_Free((*(s32 **)((u8 *)D_88234880 + 0x38))[i]);
    }
    for (i = 0; i < *(u16 *)((u8 *)D_88234880 + 0x20); i++) {
        Util_Free((*(s32 **)((u8 *)D_88234880 + 0x3C))[i]);
    }
    Util_Free(*(s32 *)((u8 *)D_88234880 + 0x18));
    Util_Free(*(s32 *)((u8 *)D_88234880 + 0x28));
    Util_Free(*(s32 *)((u8 *)D_88234880 + 0x38));
    Util_Free(*(s32 *)((u8 *)D_88234880 + 0x3C));
    Util_Free((s32)D_88234880);
}

extern void func_88001900(void);
extern void func_882277F8();
extern void *D_88234880;

void func_882278EC(void) {
    func_88001900();
    D_880068B4 = (*(s32 *)((u8 *)(D_88234880) + (0x64)));
    func_882277F8();
}

extern void func_88004990(u8, s32);
void func_88227924(void) {
    func_88004990(*(*(u8 **)((u8 *)(D_88234880) + (0))), 0);
    func_88004990(*(*(u8 **)((u8 *)(D_88234880) + (4))), 0);
    D_880068B8 = 1;
}

extern void *func_8004C874(s32, void *);
extern s32 func_88903C50();
extern void func_88903B00();
extern u8 D_88000E4C[];
extern void * D_88234880;
void func_88227974(void *arg0) {
    void *temp;

    temp = func_8004C874(0x1F, arg0);
    func_88903C50(temp, 0x17C, 0x11F, 4, 0xFF, 0xAA, 0x8C, 2, 1, *(u8 **)D_88234880 + 0x2C, 0, func_88903B00, D_88000E4C);
}

extern void func_800226C0(s32);
extern void func_882017F8(s32, void *, s8);
extern void func_88227924();
extern void func_882310A0();
extern s32 D_882345F4;
extern s8 D_88234746;
void func_88227A04(void *arg0) {
    func_800226C0(0x5D);
    func_800226C0(0x63);
    D_88234746 = 0;
    func_882310A0();
    func_882017F8(D_882345F4, arg0, (*(s8 *)((u8 *)(arg0) + (0x15))));
    (*(s32 *)((u8 *)(D_88234880) + (0x64))) = 0;
    func_88227924();
}

extern void func_800226C0(s32);
extern s32 func_8800005C(void);
extern s32 func_80063754(u8);
extern s32 func_88201F7C(void *);
extern void func_88227924(void);
extern void func_88227974(void *);
extern void func_88227A04(void *);
extern void func_88002720(s16 *, u16, void *);
extern s32 func_88203FB4(void);
extern void *D_88234880;
extern void *D_80087200;
extern s32 D_882345F4;
extern u8 *D_88A01C30;
extern u8 *D_88A01C34;
extern u8 D_889041B8;

typedef struct {
    u8 unk[0x18];
} Unk88227A60Entry;



void func_88227A60(void) {
    u8 *list;
    u8 *target;
    s32 result;
    u8 unk;
    u16 pressed;

    if (D_889041B8 != 0) {
        return;
    }
    switch (*(s16 *)((u8 *)D_88234880 + 0x44)) {
    case 1:
        list = (u8 *)D_88234880 + 0xC;
        target = (u8 *)((Unk88227A60Entry *)D_88A01C34 + *(s16 *)(list + 6) + D_88A01C30[0x10]);
        break;
    case 2:
        list = (u8 *)D_88234880 + 0x1C;
        target = (u8 *)((Unk88227A60Entry *)D_88A01C34 + D_88A01C30[0x10] +
                        *(s16 *)(list + 6) + D_88A01C30[0x24]);
        break;
    }
    if (*(s32 *)((u8 *)D_88234880 + 0x40) != 0) {
        pressed = *(u16 *)((u8 *)D_80087200 + 8);
        if (pressed & 0x4000) {
            func_800226C0(0x48);
            func_88227924();
        } else if (pressed & 0x8000) {
            result = func_88201F7C((void *)(D_882345F4 + 8));
            unk = *(u8 *)(*(s32 *)(*(s32 *)D_882345F4) + 8);
            if (*(s16 *)((u8 *)D_88234880 + 0x44) == 0) {
                if (func_8800005C() != 0 && func_80063754(*(u8 *)(D_882345F4 + 9)) != 0) {
                    func_800226C0(0x47);
                    func_88227974((void *)0x10);
                } else if (result == 0 && unk == 2) {
                    func_800226C0(0x47);
                    func_88227974((void *)0x12);
                } else {
                    func_88227A04(D_88A01C34);
                }
            } else {
                func_800226C0(0x47);
                if (func_8800005C() == 0 && func_80063754(*(u8 *)(D_882345F4 + 9)) != 0 &&
                    *(s16 *)((u8 *)D_88234880 + 0x44) == 1) {
                    func_88227974((void *)0xF);
                } else if (func_8800005C() != 0 && func_80063754(*(u8 *)(D_882345F4 + 9)) != 0 &&
                    *(s16 *)((u8 *)D_88234880 + 0x44) != 2) {
                    func_88227974((void *)0x10);
                } else if (result == 0 &&
                    ((*(s16 *)((u8 *)D_88234880 + 0x44) == 2 && unk != 2) ||
                     (*(s16 *)((u8 *)D_88234880 + 0x44) != 2 && unk == 2))) {
                    func_88227974((void *)0x12);
                } else if (func_8800005C() == 0 && func_80063754(*(u8 *)(D_882345F4 + 9)) != 0 &&
                    *(s16 *)((u8 *)D_88234880 + 0x44) == 2 && unk != 2 && func_88203FB4() == 0) {
                    func_88227974((void *)0x11);
                } else {
                    *(s32 *)((u8 *)D_88234880 + 0x40) = 0;
                }
            }
        } else {
            func_88002720((s16 *)((u8 *)D_88234880 + 0x44), 3, (u8 *)D_88234880 + 0x48);
        }
    } else {
        pressed = *(u16 *)((u8 *)D_80087200 + 8);
        if (pressed & 0x4000) {
            func_800226C0(0x48);
            *(s32 *)((u8 *)D_88234880 + 0x40) = 1;
        } else if (pressed & 0x8000) {
            func_88227A04(target);
        } else {
            switch (*(s16 *)((u8 *)D_88234880 + 0x44)) {
            case 1:
            case 2:
                func_88002720((s16 *)(list + 6), *(u16 *)(list + 4), list + 8);
                break;
            }
        }
    }
    switch (*(s16 *)((u8 *)D_88234880 + 0x44)) {
    default:
        ((u8 *)(*(s32 *)((u8 *)D_88234880 + 4)))[0x1C] = 0x96;
        ((u8 *)(*(s32 *)((u8 *)D_88234880 + 4)))[0x1D] = 0x96;
        ((u8 *)(*(s32 *)((u8 *)D_88234880 + 4)))[0x1E] = 0x82;
        break;
    case 1:
    case 2:
        ((u8 *)(*(s32 *)((u8 *)D_88234880 + 4)))[0x1C] = 0xDC;
        ((u8 *)(*(s32 *)((u8 *)D_88234880 + 4)))[0x1D] = 0xDC;
        ((u8 *)(*(s32 *)((u8 *)D_88234880 + 4)))[0x1E] = 0xB4;
        break;
    }
}

extern s32 func_8004D334(s32,s32);

extern Gfx *D_800D0510;

extern Gfx D_80094DE0[], D_80094E38[], D_80094F50[];

extern void *D_8800687C;

extern void func_880008B0(s16,s16,s16);

extern void func_88002BA0(s32,s32,s32);

extern void func_8004D40C(s32);

extern s32 func_80049290(s32,s32,void *);

extern void func_8004D5B8();

extern void func_88000FC4(s32,s32,s32,s32,s32,s32);

extern void func_800498C4(void);

extern void func_800496A4(s32,s32);

extern void func_8004C54C(s32,void *);

extern void func_8004989C(s32);

extern void *func_8004C8A0(void *,s32,s32,s32);

extern void func_80048E30(void *,s32,s32,void *,s32);

extern void func_88002820(s16,s16,s32,void *,s32,s32,void *);

extern void func_800499EC(void);

extern void func_880009A8(s32,s16,s16,s16,s32,s32,s32);

extern void func_8004B2CC(s32,s32,s32,s32,s32,s32,s32,s32);

extern void func_8004B314(s32,s32,s32,s32);

void func_88227EE8(s32 arg0) {
    u8 i;
    s16 x;
    s16 y;
    u8 *list;
    u8 *entry;
    s32 row;
    switch (arg0 = *(s16 *)((u8 *)D_88234880 + 0x44)) {
    case 1:
        entry = D_88A01C34 + 24 * D_88A01C30[16];
        list = (u8 *)D_88234880 + 0xC;
        break;
    case 2:
        entry = D_88A01C34 + 24 * D_88A01C30[16] + 24 * D_88A01C30[36];
        list = (u8 *)D_88234880 + 0x1C;
        break;
    }
    gSPDisplayList(D_800D0510++, D_80094DE0);
    func_880008B0(178,199,151);
    gSPDisplayList(D_800D0510++, D_80094E38);
    {
    u8 text[64];
    func_88002BA0(255,255,255);
    func_8004D334(239,0);
    func_8004D40C(2);
    func_8004D5B8(188 + func_80049290(8,1,func_8004C874(37,(void *)44)),215,0,"%d/%d",D_88A01C34[21],D_88A01C34[20]);
    if ((arg0 = *(s16 *)((u8 *)D_88234880 + 0x44)) == 1 || arg0 == 2) {
        x = *(u16 *)((u8 *)D_88234880 + 0x34) + *(s16 *)(*(u8 **)((u8 *)D_88234880 + 4) + 12) + 30;
        y = *(s16 *)(*(u8 **)((u8 *)D_88234880 + 4) + 14) + 12;
        for (i = 0; i < *(u16 *)(list + 4); i++) {
            func_88000FC4(x,y,1,2,entry[21],entry[20]);
            y += 20;
            entry += 24;
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    func_800498C4();
    func_800496A4(4,1);
    func_8004C54C(37,((void **)((u8 *)D_88234880 + 0x54))[(**(u8 ***)D_882345F4)[8]]);
    func_8004989C(20);
    func_80048E30(D_8800687C,178,157,func_8004C8A0(text,64,37,43),1);
    }
    if ((arg0 = *(s16 *)((u8 *)D_88234880 + 0x44)) == 1 || arg0 == 2) {
        func_88002820(*(s16 *)(*(u8 **)((u8 *)D_88234880 + 4) + 12) + 24,
            *(s16 *)(*(u8 **)((u8 *)D_88234880 + 4) + 14) + 11,0,
            *(void **)list,*(u16 *)(list+4),*(s16 *)((u8 *)D_88234880+0x32),list+8);
    }
    func_800496A4(8,1);
    func_88002820(182,209,0,(u8 *)D_88234880+0x54,3,6,(u8 *)D_88234880+0x48);
    func_800499EC();
    if (*(s32 *)((u8 *)D_88234880+0x40)) {
        func_880009A8(*(s32 *)(*(u8 **)D_88234880+0x2C),182,(s16)(209+26 * *(s16 *)((u8 *)D_88234880+0x44)),*(s16 *)((u8 *)D_88234880+0x60),20,5,5);
    } else {
        func_8004B2CC(177,204+26 * *(s16 *)((u8 *)D_88234880+0x44),*(u16 *)((u8 *)D_88234880+0x60)+10,30,150,150,90,0);
        row = *(s16 *)((u8 *)D_88234880+0x44)==1 ? *(s8 *)((u8 *)D_88234880+0x13) : *(s8 *)((u8 *)D_88234880+0x23);
        func_8004B314(*(s16 *)(*(u8 **)((u8 *)D_88234880+4)+12)+19,*(s16 *)(*(u8 **)((u8 *)D_88234880+4)+14)+20*row+6,*(u16 *)((u8 *)D_88234880+0x36)+10,26);
    }
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_197640/func_88228390.s")
#endif
