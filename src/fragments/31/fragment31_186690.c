#include "global.h"


#ifdef VERSION_US
extern u8 *D_88234564;
extern void Util_Free(void *);
extern void main_pool_pop_state(s32);
extern void func_8821CE40(s32);
extern s32 D_88234560;
void func_88213410(void) {
    Util_Free(D_88234564);
    main_pool_pop_state(0x4D41494C);
    func_8821CE40(4);
    D_88234560 = 5;
}

extern s32 func_8821BA34(u16, void *);
typedef struct { u8 *entries; u32 unk_04; u32 unk_08; } StorageListEntryPointerRecord;
extern StorageListEntryPointerRecord D_88234640[];
extern u8 * D_88234730;
// Modes 0/1 select start/position, 2 selects the first entry, and 3 uses the shared index.
u8 *StorageList_GetEntry(s32 mode, u8 column) {
    s16 index;

    switch (mode) {
    case 0:
        index = *(s16 *)(D_88234730 + 22 + (u32)column * 44);
        break;
    case 1:
        index = *(s16 *)(D_88234730 + 20 + (u32)column * 44);
        break;
    case 2:
        index = 0;
        break;
    case 3:
        index = *(s16 *)(D_88234730 + 112);
        break;
    }
    return D_88234640[(u32)column * 2].entries + index * 118;
}

typedef struct {
    u8 unk_00[8];
    s16 position;
    s16 start;
    u16 count;
    u8 visible;
    u8 step;
    s16 scroll;
    u8 unk_12[16];
    s16 residual;
    u8 unk_24[8];
} StorageListScrollRecord;

typedef struct {
    u8 count;
    u8 capacity;
    void *entries;
    s32 changed;
} LabPCStorageList186690;

typedef struct unk_D_8823463C {
    u8 unk_00;
    u8 unk_01[11];
} unk_D_8823463C;

extern void func_88213410(void);
extern u8 *D_88234730;
extern unk_D_8823463C D_88234630[];
extern u8 D_88234660[];
extern u8 D_88233820;
extern u8 D_8823382C;
extern u8 D_88233836;
extern s32 D_882346F0;
extern s32 D_882346F4;
extern s32 D_880068B4;
extern s32 D_880068B8;
extern void D_88000E4C(void);
extern void *D_80087200;
extern void Input_SetRepeatController(void *);
s32 func_80001FF0();
s32 func_8004C4B0(s32);
s32 func_8004C8C0(s32);
s32 func_8004C990(s32, u8);
s32 func_88001C6C(u8 *, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_88005B60(s32, s32 *, s32 *, s32 *);
void func_882011E0(s32);
void func_88203744(s32);
s32 func_8821DC48(s32, u8 *, u8 *, u8 *);
void func_88A00D0C(s32);
s32 main_pool_push_state(s32);
u8 *mem_pool_alloc(s32, s32);
s32 mem_pool_try_init(s32, s32);

s32 func_88205EB0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, void (*)());



void func_88213530(void)
{
  s32 temp_v0;
  s32 column;
  s32 var_s0;
  s32 var_s1_2;
  s32 var_s2_2;
  u8 *var_s0_2;
  u8 *var_s1;
  u8 *var_s5;
  u8 *var_s2;
  main_pool_push_state(0x4D41494C);
  temp_v0 = mem_pool_try_init(0x20000, 0);
  do
  {
    D_88234730 = mem_pool_alloc(temp_v0, 0x164);
    func_8004C4B0(0x23);
    func_8004C4B0(9);
    func_8004C4B0(0xB);
    func_8004C8C0(0xC3);
 for (var_s2 = &D_88233820, var_s0 = 0, var_s1 = &D_88233820 + 12; var_s1 < &D_88233820 + 22; var_s2 += 1, var_s1 += 1, var_s0 += 8) {
      *((s32 *) ((D_88234730 + var_s0) - (-0x74))) = func_8004C990(0xC3, *var_s2);
      *((s32 *) ((D_88234730 + var_s0) + 0x78)) = func_8004C990(0xC3, *var_s1);
    }
    func_882011E0(temp_v0);
    func_88A00D0C(temp_v0);
    func_88203744(temp_v0);
    func_8821DC48(temp_v0, D_88234730 + 0xC4, D_88234730 + 0xF8, D_88234730 + 0x12C);
    *D_88234730 = 0;
    *((s32 *) (D_88234730 + 4)) = 1;
    *((s16 *) (D_88234730 - (-8))) = 0;
    var_s1_2 = 0; } while (0); *((s8 *) (D_88234730 - -0x64)) = 0;
  for (column = 0; column < 2; column++)
  {
    *((s32 *) ((D_88234730 + column * 4) + 0x68)) = 0;
    func_88001C6C((u8 *) &(((StorageListScrollRecord *) (D_88234730 + 12))[column]), ((LabPCStorageList186690 *) D_88234630)[column * 2 + 1].count, 6, 0x7D, 0x1B, 0xE, (s32) ((600.0f / ((f32) func_80001FF0())) + ((600.0f / ((f32) func_80001FF0())) > 0.0f ? 0.5f : -0.5f)), 0x20, 0x20, 0xC, 0x46);
  }
  Input_SetRepeatController(D_80087200);
  D_882346F0 = 0;
  D_880068B4 = (D_880068B8 = 1);
  D_882346F4 = 0;
  func_88205EB0(0x2C, 0x13F, 0x229, 0x82, 0x2C, 0x48, 0xF2, 0xF2, (unsigned int) 0x31, 0x69, 0xE5, 0xC9, 0x163, 0x48, 0xF2, 0xF2, 0x168, 0x69, 0xE5, 0xC9, 0x34, 0x6C, 0xDF, 0x11, 0x34, 0x11E, 0xDF, 0x11, 0x16B, 0x6C, 0xDF, 0x11, 0x16B, 0x11E, 0xDF, 0x11, 0x121, 0x48, 0x3F, 0x26, 0x34, 0x7D, 0xDF, 0x1A, 0x16B, 0x7D, 0xDF, 0x1A, 0xFB, 0x4F, 0x16B, 0x4F, -(((1 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu), -1, -1, -1, -1, -1, -1, -1, 0x88, 0x70, 0x9A, 0x70, 0x9A, 0x122, 0xAE, 0x122, 0x1BF, 0x70, 0x1D1, 0x70, 0x1D1, 0x122, 0x1E5, 0x122, 7, 0x22, func_88213410);
  func_88005B60(0, (s32 *) &D_88000E4C, (s32 *) &D_88000E4C, (s32 *) &D_88000E4C);
}

u8 *func_88213A3C(s32 arg0) { switch (arg0) { case 3: return D_88234730 + 0xC4; case 4: return D_88234730 + 0xF8; case 5: return D_88234730 + 0x12C; } }

extern void func_88001C24(void *, u16, u8);
extern void func_88001D0C(void *);

/* Storage-list pair metadata. */
extern unk_D_8823463C D_8823463C[];
// Update the optional row count and preserve the six-row scroll position.
//@src/fragments/29/fragment29_167940.c
void StorageList_UpdateScrollCount(u8 column, s32 enabled) {
    StorageListScrollRecord *scroll;
    if (((s32 *)(D_88234730 + 104))[column] != enabled) {
        scroll = (StorageListScrollRecord *)(D_88234730 + 12) + column;
        ((s32 *)(D_88234730 + 104))[column] = enabled;
        if (enabled != 0) {
            if (D_8823463C[column * 2].unk_00 != 0) {
                func_88001C24(scroll, scroll->count + 1, 6);
                if (scroll->position - scroll->start == 5) {
                    scroll->start++;
                } else {
                    scroll->scroll += scroll->step;
                }
            }
        } else {
            if (D_8823463C[column * 2].unk_00 != 0) {
                func_88001C24(scroll, scroll->count - 1, 6);
                if (scroll->position - scroll->start == 5) {
                    scroll->start--;
                } else {
                    scroll->scroll -= scroll->step;
                }
            }
        }
        func_88001D0C(scroll);
    }
}

extern u8 *D_88234730;
typedef struct {
    u8 *entry;
    u8 *other;
    s8 row;
    s8 otherRow;
    u8 column;
    u8 otherColumn;
} StorageListMessage;
extern void *D_8800EF54;
extern void *Util_Malloc(s32);
extern void func_800226C0(s32);
extern void func_88232E30(s32);
extern u8 * StorageList_GetEntry(s32, u8);
void func_88213BE4(s32 mode, s32 sound) {
    u8 column;
    StorageListMessage *msg;
    s16 start;
    s16 pos;
    s16 otherStart;
    s16 otherPos;
    s16 delta;

    msg = Util_Malloc(0xC);
    column = *D_88234730;
    start = ((StorageListScrollRecord *)(D_88234730 + 12))[column].start;
    pos = ((StorageListScrollRecord *)(D_88234730 + 12))[column].position;
    otherStart = ((StorageListScrollRecord *)(D_88234730 + 12))[1 - column].start;
    otherPos = ((StorageListScrollRecord *)(D_88234730 + 12))[1 - column].position;
    switch (mode) {
    case 15:
    case 17:
        msg->entry = StorageList_GetEntry(1, 1 - column);
        if (mode == 17) {
            msg->other = StorageList_GetEntry(1, *D_88234730);
        } else {
            msg->other = NULL;
        }
        msg->row = otherPos - otherStart;
        msg->otherRow = pos - start;
        msg->column = 1 - *D_88234730;
        msg->otherColumn = *D_88234730;
        break;
    case 16:
        msg->entry = StorageList_GetEntry(3, column);
        msg->other = StorageList_GetEntry(1, *D_88234730);
        delta = *(s16 *)(D_88234730 + 0x70) - start;
        if (delta >= 0 && delta < 6) {
            msg->row = delta;
        } else {
            msg->row = -1;
        }
        msg->otherRow = pos - start;
        msg->column = msg->otherColumn = *D_88234730;
        break;
    case 18:
        msg->entry = StorageList_GetEntry(1, column);
        msg->other = NULL;
        msg->row = pos - start;
        msg->otherRow = -1;
        msg->column = *D_88234730;
        msg->otherColumn = 1 - *D_88234730;
        break;
    case 19:
        msg->entry = NULL;
        msg->other = NULL;
        msg->row = pos - start;
        msg->otherRow = -1;
        msg->column = *D_88234730;
        msg->otherColumn = 1 - *D_88234730;
        break;
    }
    D_8800EF54 = msg;
    if (sound) {
        func_800226C0(0x5D);
    }
    func_800226C0(0x63);
    func_88232E30(mode);
}

extern u8 *D_882345F4;
extern unk_D_8823463C D_88234630[];
extern u8 D_88234648;
extern s32 D_882346F0;
extern s32 D_882346F4;
extern s32 D_880068B4;
extern s32 D_880068B8;
extern u8 func_88903B00[];
extern void D_88000E4C(void);
extern void *D_80087200;
extern void func_88001900(void);
extern void func_882064B4(s32, s32 *, void *, void *);
extern void func_88221034(s16, s16, s32, s32);
extern void func_88203A58(u8 *);
extern void func_88203BE4(u8 *, void *, s8);
extern s32 func_88204050(void);
extern u8 *func_8820137C(u8 *);
extern s32 func_800635E0(u8);
extern s32 func_80063754(u8);
extern s8 *func_8004C8A0(void *, s32, s32, s32);
extern void Input_SetRepeatController(void *);
extern void LabPC_OpenMessageDialog(s8 *, s16, s16, s32, u8, u8, u8, u8, u8, s32 *, s32 *, s32 *, void (*)(void));
typedef struct {
    u8 unk_00[0x15];
    s8 unk_15;
    u8 unk_16[0x16];
} LabPCScrollRec186690;
typedef struct {
    u8 pad[12];
    StorageListScrollRecord rec[2];
} LabPCScrollBlock186690;



void func_88213E9C(void) {
    u8 text[0x80];
    u8 *entry;

    func_800226C0(0x5E);
    func_88001900();
    D_882346F0 = 0;
    D_882346F4 = 0;
    switch (*(s16 *)(D_88234730 + 8)) {
    case 0:
    case 5:
    case 6:
        if (*(s16 *)(D_88234730 + 8) == 0) {
            func_88203BE4(StorageList_GetEntry(1, 1 - *D_88234730),
                          &D_88234630[*D_88234730 * 2] + 1,
                          ((LabPCScrollRec186690 *)(D_88234730))[(u32)*D_88234730].unk_15);
            ((s32 *)(D_88234730 + 104))[*D_88234730] = 0;
            *D_88234730 ^= 1;
        } else if (*(s16 *)(D_88234730 + 8) == 5) {
            entry = StorageList_GetEntry(1, *D_88234730);
            D_88234730[0x64] = 2;
            func_88221034(0x140, 0xF0, D_882345F4 + 0x3C, func_800635E0(entry[0x75]));
            D_882345F4[9] = entry[0x75];
            *(s32 *)(*(u8 **)D_882345F4 + 0xC) = 1;
            switch ((**(u8 ***)D_882345F4)[8]) {
            case 0:
                D_882345F4[0x27] = 0;
                func_88203BE4(entry, D_88234630, *(s8 *)(D_882345F4 + 4));
                break;
            case 2:
                D_882345F4[0x27] = func_88204050() + 1;
                func_88203BE4(entry, &D_88234648, (s8)(D_882345F4[0x27] - 1));
                break;
            }
        } else {
            D_88234730[0x64] = 2;
            LabPC_OpenMessageDialog(func_8004C8A0(text, 0x80, 0x23, 0x18), 0x140, 0xF0, 4, 0xDB, 0xDC, 0xB4,
                                    2, 0, &D_880068B4, &D_880068B8, (s32 *)func_88903B00, D_88000E4C);
            func_88203A58(StorageList_GetEntry(1, *D_88234730));
        }
        func_88001C24(&((LabPCScrollBlock186690 *)(D_88234730))->rec[*D_88234730],
                      D_8823463C[*D_88234730 * 2].unk_00, 6);
        func_88001D0C(&((LabPCScrollBlock186690 *)(D_88234730))->rec[*D_88234730]);
        return;
    case 2:
        *D_88234730 ^= 1;
        break;
    case 4:
        entry = func_8820137C(D_882345F4);
        if (func_80063754(entry[0x75]) == 0) {
            entry[0x75] = D_882345F4[9];
        }
        func_88203BE4(entry, &D_88234630[*D_88234730 * 2] + 1,
                      ((LabPCScrollRec186690 *)(D_88234730))[(u32)*D_88234730].unk_15);
        ((s32 *)(D_88234730 + 104))[*D_88234730] = 0;
        D_882345F4[0x27] = 0;
        D_882345F4[9] = D_882345F4[0x27];
        *(s32 *)(*(u8 **)D_882345F4 + 0xC) = 1;
        func_882064B4(1, (s32 *)(D_88234730 + 4), D_88234730 + 0xC, D_88234730 + 0x38);
        Input_SetRepeatController(D_80087200);
        break;
    }
}

extern void func_882064B4(s32, s32 *, void *, void *);
extern void StorageList_UpdateScrollCount(u8, s32);
extern s32 D_882346F0;
void func_882142DC(void) {
    D_882346F0 = 4;
    func_882064B4(0, (s32 *)(D_88234730 + 4), D_88234730 + 0xC, D_88234730 + 0x38);
    StorageList_UpdateScrollCount(*D_88234730, 1);
}

extern void func_88213BE4(s32, s32);
extern void func_88220E08(s32);
extern s32 D_880068B4;
void func_88214330(void) {
    s16 temp_v0;

    temp_v0 = (*(s16 *)((u8 *)(D_88234730) + (8)));
    switch (temp_v0) {                              /* irregular */
    case 3:
        func_88220E08(1);
        return;
    case 5:
        D_880068B4 = 1;
        func_88213BE4(0x12, 0);
        return;
    }
}

extern void func_800226C0(s32);
void func_88214394(void) {
    s16 temp_v0;

    temp_v0 = (*(s16 *)((u8 *)(D_88234730) + (8)));
    switch (temp_v0) {                              /* irregular */
    case 3:
        func_800226C0(0x5C);
        return;
    case 5:
        func_800226C0(0x5D);
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_186690/func_882143EC.s")

/* mkdraft:func_882152F4 begin */
typedef struct { u8 pad[8]; s16 position; s16 start; u8 pad2[0x20]; } Scroll18690;
typedef struct { u8 slot; u8 reserved[0xB]; Scroll18690 records[2]; u8 pad[0xC]; s32 position; } State18690;
extern s32 D_882346F4;

s32 func_882152F4(u8 arg0, u8 arg1) {
    u32 index = arg0;
    State18690 *state;
    s32 result = 0;

    switch (D_882346F0) {
    default:
        goto done;
    case 0:
        if (D_882346F4 == 0) {
            goto done;
        }
        state = (State18690 *)D_88234730;
        if (arg0 != state->slot) {
            goto done;
        }
        if (arg1 == state->records[index].position - state->records[index].start) {
            result = 1;
            goto done;
        }
        goto done;
    case 1:
    case 3:
        state = (State18690 *)D_88234730;
        if (arg0 == state->slot) {
            goto done;
        }
        if (arg1 == state->records[index].position - state->records[index].start) {
            result = 1;
            goto done;
        }
        goto done;
    case 2:
        state = (State18690 *)D_88234730;
        if (arg0 != state->slot) {
            goto done;
        }
        if ((s16)arg1 == *(s16 *)((u8 *)state + 0x70) - state->records[index].start) {
            result = 1;
        }
        goto done;
    }
done:
    return result;
}
/* mkdraft:func_882152F4 end */

/* mkdraft:func_88215420 begin */
extern unk_D_8823463C D_88234630[];
extern Gfx *D_800D0510;

// Storage list header; same layout as StorageList186690, which is declared
// further down this file, after this function.
typedef struct {
    u8 count;
    u8 capacity;
    void *entries;
    s32 changed;
} ListHeader186690;

// Emits the display-list packets for one storage list column: for each row, a
// pipe sync, a fill color, and a fill rectangle covering x..x+222 and
// top..bottom, followed by a one-pixel separator line while the list is on
// screen. Rows are 25 pixels tall with 27-pixel spacing; the visible part of
// the list spans y = 125..285.


void func_88215420(u8 column, u8 count) {
    u32 row;
    s16 x;
    s16 y;
    s16 top;
    s16 bottom;

    x = column == 0 ? 52 : 363;
    y = 125 - ((StorageListScrollRecord *)(D_88234730 + 12))[column].residual;
    for (row = 0; row != count; row++, y += 27) {
        top = y;
        bottom = y + 25;
        // Clip the first and last row to the edges of the list viewport.
        if (row == 0) {
            if (top < 125) {
                top = 125;
            }
        } else if (row == 6) {
            if (bottom >= 286) {
                bottom = 285;
            }
        }
        gDPPipeSync(D_800D0510++);
        // Empty columns and rows past the stored record count use 0x39CF39CF;
        // the row at the column's scroll cursor (func_882152F4) uses 0x2AFF2AFF
        // in the active column and 0x39D739D7 otherwise.
        if (((ListHeader186690 *)D_88234630)[column * 2 + 1].count == 0 ||
            row >= ((StorageListScrollRecord *)(D_88234730 + 12))[column].count) {
            gDPSetFillColor(D_800D0510++, 0x39CF39CF);
        } else if (func_882152F4(column, row) != 0) {
            if (D_882346F0 == 1 || D_882346F0 == 3 || column == *D_88234730) {
                gDPSetFillColor(D_800D0510++, 0x2AFF2AFF);
            } else {
                gDPSetFillColor(D_800D0510++, 0x39D739D7);
            }
        } else if (D_882346F0 == 1 || D_882346F0 == 3 || column == *D_88234730) {
            gDPSetFillColor(D_800D0510++, 0x09A909A9);
        } else {
            gDPSetFillColor(D_800D0510++, 0x39CF39CF);
        }
        gDPFillRectangle(D_800D0510++, x, top, x + 222, bottom);
        // Separator: both y coordinates are the row's lower edge plus one.
        bottom++;
        if (bottom < 286) {
            gDPPipeSync(D_800D0510++);
            if (D_882346F0 == 1 || D_882346F0 == 3 || column == *D_88234730) {
                gDPSetFillColor(D_800D0510++, 0x7D3F7D3F);
            } else {
                gDPSetFillColor(D_800D0510++, 0x63196319);
            }
            gDPFillRectangle(D_800D0510++, x, bottom, x + 222, bottom);
        }
    }
}
/* mkdraft:func_88215420 end */

extern s32 func_8003514C(void);
// Copy at most limit characters, treating high bytes as two-byte characters in mode zero.
//@src/340C0.c
s8 *Text_CopyCharacterPrefix(s8 *output, s8 *input, s32 limit) {
    s8 *destination;
    s32 count;
    s32 byte;
    s32 width;

    count = 0;
    for (destination = output; ; count++) {
        if (count >= limit || *input == 0) break;
        if ((u8)*input >= 0x80 && func_8003514C() == 0) {
            width = 2;
        } else {
            width = 1;
        }
        for (byte = 0; byte < width; byte++) {
            *destination++ = *input++;
        }
    }
    *destination = 0;
    return output;
}

extern void func_800496A4(s32, s32); extern void func_80049064(s32, s32, s32, s32); extern s32 func_8003514C(void); extern void func_80047634(s32); extern s32 D_8800687C; extern s32 func_80048E30(u8 *, s32, s32, const char *, s32); extern void func_80047650(s32);
void func_882158E4(s16 arg0, s16 arg1, s8 *arg2) { s8 temp[0x44]; s32 count; if (arg2[0x66] != 0) { func_800496A4(4, 1); func_80049064(arg0 + 0xD3, arg1 + 4, 2, arg2 + 0x66); if (func_8003514C() == 0) count = 6; else count = 0xC; Text_CopyCharacterPrefix(temp + 4, arg2, count); func_800496A4(8, 2); func_80047634(1); func_80048E30((u8 *)D_8800687C, arg0, arg1, (const char *)(temp + 4), 1); func_80047650(1); } }

typedef struct Color88217F70 {
    u8 red;
    u8 green;
    u8 blue;
} Color88217F70;
typedef struct { u8 r; u8 g; u8 b; u8 a; } RowColor186690;
extern RowColor186690 *Color_SetRGB(RowColor186690 *, u8, u8, u8);
extern void func_880006E0(Color88217F70 *);
extern Color88217F70 D_88005FA0;
extern s32 func_88005CC0(s32, void *);
void StorageList_DrawRows(u8 column, u8 limit) {
    s16 x;
    s16 y;
    s32 row;
    u8 selected;

    if (D_8823463C[column * 2].unk_00 != 0) {
        Color88217F70 gray;
        u8 *entry;

        entry = StorageList_GetEntry(0, column);
        x = column == 0 ? 58 : 369;
        {
            u16 available = ((StorageListScrollRecord *)(D_88234730 + 12))[(u32)column].count;

            row = 0;
            limit = limit < available ? limit : available;
        }
        y = 128 - ((StorageListScrollRecord *)(D_88234730 + 12))[(u32)column].residual;
        for (; row != limit; row++, y += 27) {
            if (((s32 *)(D_88234730 + 104))[column] != 0) {
                selected = row == ((StorageListScrollRecord *)(D_88234730 + 12))[(u32)column].position -
                                  ((StorageListScrollRecord *)(D_88234730 + 12))[(u32)column].start ? 1 : 0;
                if (selected != 0) continue;
            }
            if (D_882346F0 == 1 || D_882346F0 == 3 || column == *D_88234730) {
                func_880006E0(&D_88005FA0);
            } else {
                func_880006E0((Color88217F70 *)Color_SetRGB((RowColor186690 *)&gray, 150, 150, 150));
            }
            if (func_88005CC0(15, entry) == 0 &&
                func_88005CC0(16, entry) == 0 &&
                func_88005CC0(17, entry) == 0 &&
                func_88005CC0(18, entry) == 0 &&
                func_88005CC0(19, entry) == 0) {
                func_882158E4(x, y, (s8 *)entry);
            }
            entry += 118;
        }
    }
}

// Storage list header, laid out like fragment31_1A5E10's LabPCStorageList.
//@src/fragments/31/fragment31_1A5E10.c
typedef struct StorageList186690 {
    u8 count;
    u8 capacity;
    void *entries;
    s32 changed;
} StorageList186690;
extern unk_D_8823463C D_88234630[];
extern void func_8004D5B8(s32, s32, s32, const char *, ...);

// Prints "count/capacity" of the second storage list of each of the two
// D_88234630 pairs at x = 269 and 580, y = 287.
void func_88215BCC(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_8004D5B8(269 + i * 311, 287, 2, "%d/%d",
                      ((StorageList186690 *)D_88234630)[i * 2 + 1].count,
                      ((StorageList186690 *)D_88234630)[i * 2 + 1].capacity);
    }
}
extern void func_800496A4(s32, s32); extern void *func_8004C874(s32, s32); extern void func_80049064(s32, s32, s32, s32); extern s16 D_8800EF58; extern s32 D_882346F0; extern u8 *D_88234730;
void func_88215C4C(void) { if (D_8800EF58 == 0) { if (D_882346F0 == 0) { func_800496A4(4, 2); func_80049064(0x140, 0x198, 1, func_8004C874(0x23, 7)); } } func_800496A4(0x10, 2); func_80049064(0x140, 0x15F, 1, func_8004C874(0x23, *(s16 *)(D_88234730 + 8))); }

s32 func_88215CE0(void) {
    u8 *var_v0 = D_88234730;
    s32 var_v1 = 0;

    if (*(s32 *)(var_v0 + 4) == 0) {
        if (D_8800EF58 == 0) {
            if (((s32 *)(var_v0 + 104))[var_v0[0]] == 0) {
                if (D_8823463C[var_v0[0] * 2].unk_00 != 0) {
                    var_v1 = 1;
                }
            }
        }
    }
    return var_v1;
}

extern u8 *StorageList_GetEntry(s32, u8); extern void func_8004989C(s32); extern void func_80049668(s32); extern void func_800495F8(s32, s32, s32, const char *, ...); extern void func_80047634(s32);
extern void func_80047650(s32);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
extern void func_80049064(s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
void func_88215D4C(void) { u8 *p; p = StorageList_GetEntry(1, *D_88234730); if (((s8 *)p)[0x66] != 0) { func_8004989C(0x20); func_800496A4(0x10, 2); func_80047634(1); func_80049064(0x13F, 0x154, 1, (s32)p); func_80047650(1); func_800496A4(8, 1); func_80048E30((u8 *)D_8800687C, 0xD5, 0x196, (const char *)(p + 0x66), 1); func_800496A4(4, 1); func_80048E30((u8 *)D_8800687C, 0x13E, 0x19A, (const char *)func_8004C874(0xD, 9), 1); func_80049668(0); func_800495F8(0x161, 0x19A, 0, "%05d", *(u16 *)(p + 0x72)); } }

/* mkdraft:func_88215E54 begin */
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s32 s, s32 t, s32 dsdx, s32 dtdy, s32 cycle);
extern s32 func_8004D1FC(u8 *arg0);
extern Gfx *D_800D0510;
extern u8 *StorageList_GetEntry(s32 mode, u8 column);

extern u8 D_88233838[];
extern u8 D_88233844[];
extern s32 D_88234644[];
extern u8 *D_88234730;



void func_88215E54(void)
{
  s16 var_s1;
  s32 var_s2;
  s32 var_s3;
  u16 temp_v0_6;
  u32 var_a0;
  s32 var_s6;
  u8 *temp_s0;
  u8 *temp_v0;
  u8 *var_v1;
  u8 temp_a1;
  u8 *temp_v1;
  u32 found;
  var_s6 = 0;
  temp_v0 = StorageList_GetEntry(1, *D_88234730);
  var_v1 = D_88233838;
  var_a0 = 0;
  temp_a1 = temp_v0[0x75];
  // FAKE: `^ 0` on the loop-compare result; the plain `var_a0 < 10` form scores 600.
  // Score without: 600.
  for (; (var_a0 <= (10 - 1)) ^ 0; var_a0++)
  {
    if (temp_a1 == (*var_v1))
    {
      var_s6 = var_a0;
      break;
    }
    var_v1++;
  }

  found = (var_a0 == 0xA);
  if (found)
  {
    temp_v0[0x75] = 0xBA;
    *((s32 *) ((u8 *) D_88234644 + ((*D_88234730) << 1) * 12)) = 1;
    var_s6 = 6;
  }
  // FAKE: second read of `found`; removal scores 965. Score without: 965.
  if (found)
  {
  }
  gDPPipeSync(D_800D0510++);
  gDPSetCombine(D_800D0510++, 0x309661, 0x552EFF7F);
  temp_v1 = (var_s6 * 6) + D_88233844;
  gDPSetPrimColor(D_800D0510++, 0, 0, temp_v1[0], temp_v1[1], temp_v1[2], 0xFF);
  var_s2 = 0;
  gDPSetEnvColor(D_800D0510++, temp_v1[3], temp_v1[4], temp_v1[5], 0xFF);
  do
  {
    // FAKE: multiply by one, keeps the var_s6 web live across the loop; removal scores 365.
    // Score without: 365.
    var_s6 = var_s6 * 1;
    temp_s0 = *((u8 **) (((D_88234730 + 0x74) + (var_s6 * 8)) + var_s2));
    // FAKE: empty `if (1)` wrapper; removal scores 50. Score without: 50.
    if (1)
    {
      if (var_s2 == 0)
      {
        var_s1 = 0x154;
        // FAKE: u16-to-s16 truncation of the width difference; removal scores 460.
        // Score without: 460.
        var_s3 = (s16) (0x23C - (*((u16 *) temp_s0)));
        // FAKE: goto to the immediately following label; removal scores 50.
        // Score without: 50.
        goto dummy_label_320532;
        dummy_label_320532:
        ;
      }
      else
      {
        var_s1 = 0x194;
        var_s3 = (s16) (0x23C - (*((u16 *) temp_s0)));
      }
    }
    func_8004D1FC(temp_s0);
    GfxRect_DrawTextured(0x42, (s16) var_s1, *((s16 *) temp_s0), *((s16 *) (temp_s0 + 2)), -0x10, -0x10, 0x400, 0x400, 0);
    temp_v0_6 = *((u16 *) temp_s0);
    // FAKE: empty `if (1)` wrapper; removal scores 50. Score without: 50.
    if (1)
    {
    }
    GfxRect_DrawTextured((s16) var_s3, (s16) var_s1, temp_v0_6, *((s16 *) (temp_s0 + 2)), (temp_v0_6 << 5) - 0x10, -0x10, -0x400, 0x400, 0);
    // FAKE: empty `if` on the loop counter; it moves constant 8 one step later in the
    // callee-saved register walk, landing it in $s5 after the 0x23C constant in $s4.
    // Removal scores 45. Score without: 45.
    if (var_s2 == 8) {}
    var_s2 += 4;
  }
  while (var_s2 != 8);
}
/* mkdraft:func_88215E54 end */

/* mkdraft:func_882160F8 begin */
extern u8 D_80094DE0[];
extern u8 D_80094E00[];
extern u8 D_80094F50[];
extern Gfx *D_800D0510;
extern s32 D_880068B8;
extern u8 D_8800686C;
extern u8 *D_88234564;
extern u8 *D_88234730;
extern u8 D_88233880[];
extern s32 D_882345C8;
extern s32 D_882346F0;
extern s16 D_8800EF58;
extern void func_88206668(void);
extern void func_88206714(u8 *, u8);
extern void func_88207D14(u8 *);
extern void func_88207D80(u8, s32, s16, u8 *, u8 *, s32);
extern s32 func_88215CE0(void);
extern void func_88215C4C(void);
extern void func_88215D4C(void);
extern void func_88215E54(void);
extern void func_88215420(u8, u8);
extern void func_88206CC0(u8 *, u8, s32, s16, u8 *, u8 *, void *);
extern void StorageList_DrawRows(u8, u8);
extern void func_88215BCC(void);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_800496A4(s32, s32);
extern void func_80049064(s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_88000808(u8, s32, s32, s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern void func_880006BC(Color88217F70 *);
extern void func_88005C7C(void);
extern void func_88005F08(void);
extern s32 func_880032C4(void);
extern void func_80006F70(Gfx **, s32, s32, s32, s32);


void func_882160F8(void) {
    s32 padA[2]; // FAKE: frame pad; without it the frame is 0x58 and the diff score is 10.
    s32 modes[2];
    Gfx *gfx;
    s32 alternate_mode;
    s32 i;
    s32 padC[4]; // FAKE: frame pad; without it the frame is 0x50 and the diff score is 132.

    if (D_880068B8 == 0) {
        return;
    }

    if (*(s32 *)(D_88234564 + 0x1C) != 2) {
        func_88206668();
        return;
    }

    if (*(s32 *)(D_88234564 + 0xA4) != 2) {
        func_88206714(D_88233880, D_88234730[0]);
        func_800498C4();
        func_88215C4C();
        func_800499EC();
        return;
    }

    alternate_mode = func_88215CE0();
    func_88207D14(D_88234730 + 0x64);

    for (i = 0; i < 2; i++) {
        if (((StorageListScrollRecord *)(D_88234730 + 12))[i].residual == 0) {
            modes[i] = 6;
        } else {
            modes[i] = 7;
        }
    }

    gfx = D_800D0510++; gfx->words.w0 = 0xDE000000; gfx->words.w1 = (u32)D_80094DE0;
    func_88215420(0, modes[0]);
    func_88215420(1, modes[1]);
    func_88005C7C();
    func_88206CC0(D_88233880, D_88234730[0], *(s32 *)(D_88234730 + 4),
                  *(s16 *)(D_88234730 + 8), D_88234730 + 0xC, D_88234730 + 0x38,
                  func_88215BCC);

    if (alternate_mode != 0) {
        func_88215E54();
    }

    gfx = D_800D0510++; gfx->words.w0 = 0xDE000000; gfx->words.w1 = (u32)D_80094E00;
    func_88000808(D_8800686C, 0x46, 0x50, 1, 0x200000);
    func_8004D19C(0x238, 0x50, D_882345C8, 1, 0x200000);
    gfx = D_800D0510++; gfx->words.w0 = 0xDE000000; gfx->words.w1 = (u32)D_80094F50; if ((!modes) && (!modes)) { } // FAKE: emits no code; the test only shifts ugen temp allocation so this group's &D_800D0510 address lands in $a1 (without it: $a0, diff score 25).
    func_800498C4();
    func_880006BC(&D_88005FA0);
    func_800496A4(4, 1);
    func_80049064(0xA9, 0x53, 1, func_8004C874(0x23, 8));
    func_80049064(0x1D5, 0x53, 1, func_8004C874(0x23, 9));
    func_80006F70(&D_800D0510, 0x34, 0x7D, 0xDF, 0xA1);
    StorageList_DrawRows(0, modes[0]);
    func_80006F70(&D_800D0510, 0x16B, 0x7D, 0xDF, 0xA1);
    StorageList_DrawRows(1, modes[1]);
    func_80006F70(&D_800D0510, 0x2C, 0x48, 0x229, 0x17F);
    func_880006E0(&D_88005FA0);

    if (*(s32 *)(D_88234730 + 4) != 0) {
        func_88215C4C();
    } else if (alternate_mode != 0) {
        func_88215D4C();
    } else if (D_882346F0 == 4 && D_8800EF58 == 0) {
        func_800496A4(4, 2);
        func_80049064(0x140, 0x198, 1, func_8004C874(0x23, 7));
        func_800496A4(0x10, 2);
        func_80049064(0x140, 0x15F, 1, func_8004C874(0x23, 0x19));
    }

    func_88005F08();
    func_800499EC();
    func_88207D80(D_88234730[0], *(s32 *)(D_88234730 + 4),
                  *(s16 *)(D_88234730 + 8), D_88234730 + 0xC,
                  D_88234730 + 0x38, func_880032C4() == 0);
}
/* mkdraft:func_882160F8 end */
#endif
