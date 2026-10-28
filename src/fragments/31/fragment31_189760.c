#include "global.h"


#ifdef VERSION_US
extern void *func_8004C874(s32, s32);
extern s32 D_8800687C;
extern u8 *D_88234564;
extern void Util_Free(void *);
extern void main_pool_pop_state(s32);
extern void func_8821CE40(s32);
extern s32 D_88234560;
extern s32 func_8821BA34(u16, void *);
void func_882164E0(void) {
    Util_Free(D_88234564);
    main_pool_pop_state(0x4C495354);
    func_8821CE40(0);
    D_88234560 = 5;
}

extern void func_88200134(s32, s32);
void func_88216520(void) {
    func_88200134(0, 2);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_189760/func_88216544.s")

extern u8 *D_88234740;
u8 *func_88216D54(s32 arg0) { switch (arg0) { case 0: case 1: return D_88234740 + 0xC4; case 2: return D_88234740 + 0xF8; } }

// Returns the start of column arg1 for entry arg0: 48, 78, then 168 plus the widths of
// columns 2 through arg1 - 1 (the per-column widths that func_88216E28 returns).
s32 func_88216D98(s8 arg0, s8 arg1) {
    s16 x;
    u32 i;
    u8 *width;

    switch (arg1) {
        case 0:
            x = 48;
            break;
        case 1:
            x = 78;
            break;
        default:
            i = 0;
            x = 168;
            width = D_88234740 + 5 + arg0 * 7;
            // FAKE: guarded do-while; diff score 60 as a multi-line while (i + 2 < arg1) loop.
            if (i + 2 < arg1) {
                do {
                    i++;
                    x += *width;
                    width++;
                } while (i + 2 < arg1);
            }
            break;
    }
    return x;
}

s32 func_88216E28(s8 arg0, s8 arg1) {
    s32 result;
    switch (arg1) {
    case 0:
        result = 0x1E;
        break;
    case 1:
        result = 0x58;
        break;
    default:
        result = ((u8 *)D_88234740)[arg0 * 7 + arg1 + 3];
        break;
    }
    return result;
}

s32 func_88200D04(s32);
s32 func_88201F0C();
s32 func_88228BCC(s32, s32, void (*)());
s32 func_88228F30(s32, s32, void (*)());
s32 func_882295E4(s32, s32, void (*)());

void func_88216E80(void) {
    if (func_88201F0C() != 0) {
        func_88228F30(0x17C, 0x11F, func_88216520);
        return;
    }
    if (func_88200D04(7) != 0) {
        func_882295E4(0x17C, 0x11F, func_88216520);
        return;
    }
    func_88228BCC(0x17C, 0x11F, func_88216520);
}

extern u8 D_88006880[];
extern void *D_80087200;
extern void func_880022B4(void *, s32, s32);
extern void func_88001900(void);
extern void Input_SetRepeatController(void *);
void func_88216EFC(void *arg0) {
    if (*(void **)D_88234740 != arg0) {
        *(void **)D_88234740 = arg0;
        if (arg0 != 0) {
            func_880022B4(D_88006880, 0xF00, 1);
            func_88001900();
        } else {
            func_880022B4(D_88006880, 0xF00, 0);
            Input_SetRepeatController(D_80087200);
        }
    }
}

extern void func_800226C0(s32); extern void *D_80087200; extern u8 *D_88234740; extern s8 D_88234746; extern u8 D_882338A4[];
void func_88216F74(void) { func_800226C0(0x4B); if ((*(u16 *)((u8 *)D_80087200 + 8) & 2) != 0) { D_88234746--; if (D_88234746 < 0) D_88234746 = 3; } else if ((*(u16 *)((u8 *)D_80087200 + 8) & 1) != 0) { D_88234746++; if (D_88234746 >= 4) D_88234746 = 0; } if (D_882338A4[D_88234746] + 1 < ((s8 *)D_88234740)[4]) D_88234740[4] = D_882338A4[D_88234746] + 1; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_189760/func_88217040.s")

#ifndef M2C_FIELD /* m2c --valid-syntax helpers (mirrors mkdraft.py) */
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

void func_80049628(s32, s32, s32);
void func_88000EC0(s8 *, s16, s32);
s32 func_88216D98(s8, s8);
void func_800495F8(s32, s32, s32, const char *, ...);

void func_88217C90(s8 arg0, s16 arg1, s16 arg2) {
    s8 sp4A;
    M2C_UNK sp48;
    s16 temp_s1;
    s32 temp_s2;
    s32 var_s0;
    s8 *var_s1;
    s8 temp_v0;

    temp_s1 = func_88216E28(1, arg0), var_s0 = func_88216D98(1, arg0);
    temp_s2 = ((s32) M2C_FIELD(D_88234740, u8 *, 0x96) >> 1) + var_s0 + (temp_s1 >> 1);
    if (arg2 < 0) {
        func_800495F8(temp_s2, arg1 + 2, 2, func_8004C874(0x25, 0x82));
        return;
    }
    func_88000EC0((s8 *) &sp48, arg2, 0);
    var_s0 = 2;
    var_s1 = (s8 *) &sp48 + 2;
    do {
        temp_v0 = *var_s1;
        if (temp_v0 >= 0) {
            func_80049628(temp_s2 - M2C_FIELD((D_88234740 + var_s0), u8 *, 0x94), arg1 + 2, temp_v0 + 0x30);
        }
        var_s0 -= 1;
        var_s1 -= 1;
    } while (var_s0 >= 0);
}
typedef struct Color88217F70 {
    u8 red;
    u8 green;
    u8 blue;
} Color88217F70;
extern Color88217F70 D_88233700[];
extern void func_880006E0(Color88217F70 *);
extern void func_8004972C(s32, s32, s32, s32);
extern s32 func_80049290(s32, s32, const char *);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
extern void func_80049628(s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern u8 * D_88234740;
void StorageList_DrawCategoryLabel(s16 x, s16 y, u8 category, u8 ordinal, u8 alpha) {
    const char *text;
    if (alpha == 0) return;
    if (alpha == 255) {
        func_880006E0(&D_88233700[category]);
    } else {
        func_8004972C(D_88233700[category].red, D_88233700[category].green,
                     D_88233700[category].blue, alpha);
    }
    if (category == 0) {
        func_80048E30((u8 *)D_8800687C, x + 11, y + 2, (const char *)func_8004C874(37, 9), 1);
    } else {
        text = (const char *)func_8004C874(37, category + 9);
        x += 11;
        y += 2;
        func_80048E30((u8 *)D_8800687C, x, y, text, 1);
        x += func_80049290(4, 1, text);
        x += func_80049290(4, 1, " ");
        if (ordinal + 1 >= 10) {
            func_80049628(x, y, 49);
            func_80049628(x + D_88234740[148], y, ordinal + 39);
        } else {
            func_80049628(x, y, ordinal + 49);
        }
    }
}

extern Color88217F70 *func_88000510(Color88217F70 *, s8);
extern void func_880006E0(Color88217F70 *);
extern u8 func_80062D98(u8);
extern s32 func_80062CE0(u8);
extern void func_8004972C(s32, s32, s32, s32);
void func_88217F70(s16 x, s16 y, u8 move, u8 alpha) {
    Color88217F70 color;

    if (alpha == 0 || move == 0) {
        return;
    }
    func_88000510(&color, move == 252 ? 0 : func_80062D98(move));
    if (alpha == 255) {
        func_880006E0(&color);
    } else {
        func_8004972C(color.red, color.green, color.blue, alpha);
    }
    func_80048E30((u8 *)D_8800687C, x + 5, y + 2, (const char *)(move == 252 ? func_8004C874(0x45, 0x13) : func_80062CE0(move)), 1);
}

extern s32 D_889041B4;
s32 func_88218064(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 result = 1;
    *arg2 = arg0;
    *arg3 = arg0 + arg1 - 1;
    if (D_889041B4 == 3) {
        if (*arg2 >= 0xFD) {
            result = 0;
        } else if (*arg3 >= 0xFD) {
            *arg3 = 0xFC;
        }
    }
    return result;
}

void func_882180C4(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    *arg2 = arg1;
    *arg3 = arg1 + 0x13;
    if (arg0 == 0) {
        if (*arg2 < 0x93) {
            *arg2 = 0x93;
        }
    } else if (arg0 == 0xE) {
        if (*arg3 >= 0x1AB) {
            *arg3 = 0x1AA;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_189760/func_8821811C.s")

typedef struct unk_D_88234758 { u16 unk_00; u8 unk_02; u8 unk_03; u8 unk_04[3]; s8 unk_07[2]; } unk_D_88234758;
extern u8 D_88234761;
extern u8 D_88234762;
extern u8 D_88234763;
extern u8 D_88234764;
extern u16 D_88234758;
#pragma COALESCE_AT_LUI(func_8821B3E0, D_88234762, D_88234763, D_88234764, D_88234761)
void func_8821B3E0(void) {
    unk_D_88234758 *s = (unk_D_88234758 *)&D_88234758;
    s32 i;

    s->unk_00 = 0;
    s->unk_02 = 1;
    s->unk_03 = 100;
    for (i = 0; i < 2; i++) {
        ((unk_D_88234758 *)&D_88234758)->unk_07[i] = -1; // FAKE: re-forms the base address
    }
    i = 0; // FAKE
    D_88234762 = 0;
    D_88234763 = i;
    D_88234764 = 0;
    D_88234761 = 0;
}

extern void func_8821B3E0(void);
extern s32 D_88234778;
extern s32 D_8823477C;
void func_8821B438(void) {
    func_8821B3E0();
    D_88234778 = 0;
    D_8823477C = 1;
}

extern u16 D_88234758; extern s32 D_88234778; s32 func_8821B468(void) { s32 result = 0; if (D_88234758 == 0) { if (D_88234778 == 0) result = 1; } return result; }

extern s32 func_8800005C(void);
extern s32 func_880007B0(u8 *);
extern s32 func_8006461C(s32);
extern s16 D_882345F0;
extern u8 (*D_88A01C38)[96];
extern s32 D_882347C0;
extern u16 D_88234744;
extern u8 * D_88234750;
// Collect eligible 96-byte records and optionally update the one-time byte-40 marker.
//@src/fragments/29/fragment29_166060.c
void StorageList_BuildPointers(s32 detect_marker) {
    u8 *record;
    u8 **destination;
    u32 index;
    s32 mode;
    u16 eligible;

    mode = func_8800005C() != 0 ? 1 : 0;
    D_88234744 = 0;
    for (index = 0, record = (u8 *)D_88A01C38, destination = (u8 **)D_88234750; index < (u16)D_882345F0; index++, record += 96) {
        if (detect_marker != 0 && D_882347C0 == 0) {
            eligible = mode != 0 ? func_880007B0(record + 8) : 1;
            if (eligible != 0 && func_8006461C(record[40]) != 0) {
                D_882347C0 = 1;
            }
        }
        if (*(s32 *)(*(u8 **)record + 8) != 0) {
            eligible = mode != 0 ? func_880007B0(record + 8) : 1;
            if (eligible != 0) {
                *destination++ = record;
                D_88234744++;
            }
        }
    }
}

struct MemPool3A00;
extern void *mem_pool_alloc(struct MemPool3A00 *, s32);
typedef struct {
    s32 references[3];
    u8 count;
    u8 unk_0D[3];
    u8 entries[8][68];
} EntryCache186690;
extern EntryCache186690 *D_882347C4;
extern u8 *D_882345F4;
extern s32 D_882347B0;
extern u32 D_882347B4;
extern s32 func_800718B8(s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 func_80062304(u8 *);

extern u8 D_882347B8[];
extern void func_8821B438(void);
extern void func_8821B498(s32 arg0);
extern s16 D_882345F0;
extern u8 * D_88234750;
extern s32 D_882347C0;
void StorageList_Initialize(struct MemPool3A00 *pool) {
    u8 *handle;

    D_88234750 = mem_pool_alloc(pool, (u16)D_882345F0 * sizeof(u8 *));
    func_8821B438();
    D_882347B0 = 0;
    D_882347B4 = 0;
    D_882347C0 = 0;
    func_8821B498(1);
    D_882345F4 = *(u8 **)D_88234750;
    D_882347B8[0] = 1;
    D_882347B8[1] = 2;
    D_882347B8[2] = 0;
    D_882347C4 = mem_pool_alloc(pool, sizeof(EntryCache186690));
    D_882347C4->references[0] = func_800718B8(0);
    D_882347C4->references[1] = func_800718B8(7);
    D_882347C4->references[2] = func_800718B8(12);
    handle = func_8006218C(24, 0, 0, 0);
    D_882347C4->count = Deck_ReadEntries(D_882347C4->entries[0], 8, handle);
    func_80062304(handle);
}

extern s32 D_88234778; extern s32 D_8823477C; void func_8821B700(s32 arg0, s32 arg1) { D_88234778 = arg0; D_8823477C = arg1; }

extern u16 D_88234744; extern void func_8821B700(s32, s32); extern void func_8821CCE8(s32, s32); void func_8821B714(s32 arg0, s32 arg1) { func_8821B700(arg0, arg1); if (D_88234744 >= 2) func_8821CCE8(arg0, arg1); }

extern u8 D_88234765; extern u8 D_882347B8[]; void func_8821B758(u8 arg0) { D_88234765 = D_882347B8[arg0]; }

extern u16 D_88234758; s32 func_8821B778(void) { s32 result = 0; if (D_88234758 & 1) { result = 1; } return result; }

extern u16 D_88234758; s32 func_8821B79C(void) { s32 result = 0; if (D_88234758 & 2) { result = 1; } return result; }

extern u16 D_88234758; s32 func_8821B7C0(void) { s32 result = 0; if (D_88234758 & 4) { result = 1; } return result; }

extern u16 D_88234758; s32 func_8821B7E4(u8 arg0) { s32 result = 0; if (D_88234758 & 0x10) { if (((u8 *)&D_88234758)[4] == arg0) result = 1; } return result; }

s32 func_8821B81C(s8 arg0, s8 arg1) {
    s32 result = 0;
    if ((D_88234758 & 8) &&
        (((arg0 == ((s8 *)&D_88234758)[5]) && (arg1 == ((s8 *)&D_88234758)[6])) ||
         ((arg1 == ((s8 *)&D_88234758)[5]) && (arg0 == ((s8 *)&D_88234758)[6])))) result = 1;
    return result;
}

extern u16 D_88234758; extern u8 D_882347B8[]; s32 func_8821B884(u8 arg0) { s32 result = 0; if (D_88234758 & 0x40) { if (((u8 *)&D_88234758)[0xD] == D_882347B8[arg0]) result = 1; } return result; }

extern u16 D_88234758; s32 func_8821B8C8(void) { s32 result = 0; if (D_88234758 & 0x80) { result = 1; } return result; }

extern u16 D_88234758; typedef struct { u16 flags; u8 pad[14]; u32 value; } State_8821B8EC_rev; s32 func_8821B8EC(u8 arg0) { s32 result = 0; if (D_88234758 & 0x100) { if (arg0 == ((State_8821B8EC_rev *)&D_88234758)->value) result = 1; } return result; }

extern u16 D_88234758; typedef struct { u16 flags; u8 pad[18]; u32 value; } State_8821B924_rev; s32 func_8821B924(u8 arg0) { s32 result = 0; if (D_88234758 & 0x200) { if (arg0 == ((State_8821B924_rev *)&D_88234758)->value) result = 1; } return result; }

extern u16 D_88234758; s32 func_8821B95C(void) { s32 result = 0; if (D_88234758 & 0x400) { result = 1; } return result; }

void func_8821B980(u16 arg0, s32 arg1) {
    u8 bit_index;

    for (bit_index = 0; (1 << bit_index) != 0x800; bit_index++) {
        if (arg0 & (1 << bit_index)) {
            if (arg1) {
                D_88234758 |= 1 << bit_index;
            } else {
                D_88234758 &= ~(1 << bit_index);
            }
        }
    }
}

u32 func_8821B9EC(s32 arg0) {
    u8 *p = (u8 *)D_88234750;
    u32 i = 0;

    if (D_88234744) {
        do {
            if (arg0 == *(s32 *)p)
                return i;
            p += 4;
            i++;
        } while (i < (u16)D_88234744);
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_189760/func_8821BA34.s")

// Compact the current pointer list in place and return the number of matching entries.
u16 StorageList_FilterPointers(u16 filter, u16 count) {
    u8 **source = (u8 **)D_88234750;
    u8 **destination;
    u8 *entry;
    s32 index;
    u16 limit = count;

    count = 0;
    index = 0;
    for (destination = source; index != limit; index++) {
        entry = *source;
        if (func_8821BA34(filter, entry + 8)) {
            *destination++ = entry;
            count++;
        }
        source++;
    }
    return count;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_189760/func_8821C0B0.s")

extern s32 D_88234778; extern void func_8821C0B0(void); void func_8821C298(void) { if (D_88234778 == 0x10) func_8821C0B0(); }

extern u32 D_882347B4; extern u8 D_8823474D; void func_8821C2C8(s32 arg0) { if (D_882347B4 != arg0) { D_882347B4 = arg0; D_8823474D = 2; } }

// func_8821C39C restores this same 32-byte block from D_88234780.
typedef struct {
    u32 words[8];
} unk_func_8821C2F4_000;

typedef struct {
    unk_func_8821C2F4_000 unk_00;
    s32 unk_20;
    s32 unk_24;
    s16 unk_28;
    s16 unk_2A;
    s16 unk_2C;
} unk_func_8821C2F4;

extern u8 D_88234780[];

void func_8821C2F4(void) {
    unk_func_8821C2F4 *var_v0 = (unk_func_8821C2F4 *)D_88234780;

    var_v0->unk_00 = *(unk_func_8821C2F4_000 *)&D_88234758;
    var_v0->unk_20 = D_88234778;
    var_v0->unk_24 = D_8823477C;
    var_v0->unk_28 = *(s16 *)(D_88006880 + 8);
    var_v0->unk_2A = *(s16 *)(D_88006880 + 10);
    var_v0->unk_2C = *(s16 *)(D_88006880 + 16);
    func_8821C2C8(1);
}

extern s32 D_882347B0;
void func_8821C39C(void) {
    typedef struct {
        u32 words[8];
    } unk_D_88234758;

    if (D_882347B4 != 0) {
        *(unk_D_88234758 *)&D_88234758 = *(unk_D_88234758 *)&D_88234780;
        D_88234778 = *(s32 *)((u8 *)&D_88234780 + 0x20);
        D_8823477C = *(s32 *)((u8 *)&D_88234780 + 0x24);
        D_882347B0 = 1;
        func_8821C0B0();
        D_882347B0 = 0;
        func_8821C2C8(0);
    }
}
#endif
