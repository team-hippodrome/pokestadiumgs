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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_186690/func_88213530.s")

u8 *func_88213A3C(s32 arg0) { switch (arg0) { case 3: return D_88234730 + 0xC4; case 4: return D_88234730 + 0xF8; case 5: return D_88234730 + 0x12C; } }

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
extern void func_88001C24(void *, u16, u8);
extern void func_88001D0C(void *);

typedef struct unk_D_8823463C {
    u8 unk_00;
    u8 unk_01[11];
} unk_D_8823463C;
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_186690/func_88213BE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_186690/func_88213E9C.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_186690/func_88215420.s")

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
extern u8 D_88234630[];
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_186690/func_88215E54.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_186690/func_882160F8.s")
#endif
