#include "global.h"

#ifdef VERSION_US
extern s32 func_8821BA34(u16, void *);

typedef struct unk_D_88234758 { u16 unk_00; u8 unk_02; u8 unk_03; u8 unk_04[3]; s8 unk_07[2]; } unk_D_88234758;
extern u8 D_88234761;
extern u8 D_88234762;
extern u8 D_88234763;
extern u8 D_88234764;
extern u16 D_88234758;
// Nonzero bytes collected by func_88224688 from its four input slots.
//@src/fragments/31/fragment31_197640.c
static u8 sCollectedValues[4];

void func_8821B3E0(void) {
    unk_D_88234758 *state = (unk_D_88234758 *)&D_88234758;
    s32 index;

    state->unk_00 = 0;
    state->unk_02 = 1;
    state->unk_03 = 100;
    for (index = 0; index < 2; index++) {
        state->unk_07[index] = -1;
    }
    for (index = 0; index < 4; index++) {
        sCollectedValues[index] = 0;
    }
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_18E660/func_8821BA34.s")

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

extern u16 StorageList_FilterPointers(u16, u16);
extern u32 func_8821B9EC(s32);
extern void StorageList_BuildPointers(s32);
extern void func_8821B714(s32, s32);
extern void func_88001C24(void *, u16, u8);
extern void func_88001D0C(void *);
extern u8 D_88234780[];
extern u8 D_88006880[];
extern u8 *D_882345F4;
extern u16 D_88234744;
extern u16 D_882347BC;
extern u16 D_88234758;
extern s32 D_88234778;
extern s32 D_8823477C;
extern s32 D_882347B0;



s32 func_8821C0B0(void) {
    s32 sp44;
    s32 pad;     // frame layout: 0x44 result, 0x3C saved call result, then 8 bytes of padding
    u32 sp3C;
    s32 var_s1;
    s32 var_v0;
    u32 temp_v0;
    u32 var_v1;
    s32 var_s0;
    s32 lim;     // 0x800 limit: a variable, not a literal, so the loop test keeps it in s4 as rs

    sp44 = 1;
    sp3C = func_8821B9EC((s32)D_882345F4);
    D_882347BC = 0;
    StorageList_BuildPointers(0);
    if (func_8821B9EC((s32)D_882345F4) == -1U) {
        D_882347BC = 0x800;
    }
    var_s1 = 0;
    var_v0 = 1;
    lim = 0x800;
    if (D_88234758 != 0) {
        do {
            var_s0 = var_v0;
            if (D_88234758 & var_v0) {
                var_s0 = var_v0;
                D_88234744 = StorageList_FilterPointers(var_v0, D_88234744);
                if (D_882347BC == 0) {
                    var_v0 = func_8821B9EC((s32)D_882345F4);
                    if (1) {
                    }    // FAKE: without it the mask lands in v1 (score 30)
                    if (var_v0 == -1U) {
                        D_882347BC = var_s0;
                    }
                }
                if (D_88234744 == 0) {
                    break;
                }
            }
            var_s1 += 1;
            var_v0 = var_s1;    // FAKE: folding into `1 << var_s1` puts the mask in v1 (score 30)
            var_v0 = 1 << var_v0;
            do {
            } while (0);        // FAKE: without it the mask lands in v1 (score 143)
        } while (lim != var_v0);
    }
    func_8821B714(D_88234778, D_8823477C);
    func_88001C24(D_88006880, D_88234744, 0xE);
    if (D_88234744 == 0) {
        if ((s32)sp3C >= 0) {
            sp44 = 0;
        }
    } else if (D_882347B0 != 0) {
        *(s16 *)(D_88006880 + 8) = *(s16 *)(D_88234780 + 0x28);
        *(s16 *)(D_88006880 + 0xA) = *(s16 *)(D_88234780 + 0x2A);
        *(s16 *)(D_88006880 + 0x10) = *(s16 *)(D_88234780 + 0x2C);
    } else {
        temp_v0 = func_8821B9EC((s32)D_882345F4);
        var_v1 = temp_v0;
        if (temp_v0 == -1U) {
            var_v1 = sp3C;
            if ((s32)var_v1 >= 0) {
                sp44 = 0;
            }
        }
        *(s16 *)(D_88006880 + 0xA) = *(s16 *)(D_88006880 + 0xA) + (var_v1 - *(s16 *)(D_88006880 + 8));
        func_88001D0C(D_88006880);
    }
    return sp44;
}

extern s32 D_88234778;s32 func_8821C0B0(void); void func_8821C298(void) { if (D_88234778 == 0x10) func_8821C0B0(); }

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
