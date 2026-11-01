#include "global.h"


#ifdef VERSION_US
extern u8 *D_88A01C64;
u8 *func_88A00710(s32 arg0, s16 arg1) {
    u8 *result;
    switch (arg0) {
    case 0:
        result = (u8 *)((u8 *)D_88A01C64 + (arg1 << 1) + 9);
        break;
    case 1:
        result = *(u8 **)((u8 *)D_88A01C64 + 0xF0) + (arg1 << 1);
        break;
    case 2:
        result = *(u8 **)((u8 *)D_88A01C64 + 0xF8) + (arg1 << 1);
        break;
    case 3:
        result = *(u8 **)((u8 *)D_88A01C64 + 0x100) + (arg1 << 1);
        break;
    }
    return result;
}

u8 func_88A007BC(s32 arg0) {
    u8 result;
    switch (arg0) {
    case 0: result = D_88A01C64[0]; break;
    case 1: result = D_88A01C64[0xEF]; break;
    case 2: result = D_88A01C64[0xF4]; break;
    case 3: result = D_88A01C64[0xFC]; break;
    }
    return result;
}

s32 func_88A0083C(u8 *arg0) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0 < func_88A00710(i, 0)) continue;
        if (func_88A00710(i, func_88A007BC(i) - 1) < arg0) continue;
        return i;
    }
    return 0;
}

extern s32 func_8800005C(void);
extern s32 func_88A0083C(u8 *arg0);
s32 func_88A008CC(arg0)
u8 *arg0;
{
    s32 result;

    if (func_8800005C() != 0) {
        if (func_88A0083C(arg0) == 2) {
            result = 0;
        } else {
            result = 1;
        }
        return result;
    }
    if (func_88A0083C(arg0) == 3) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

extern void func_800635E0(u8, u8 *);
extern void func_80063620(u8, u8 *);
#ifdef CC_CHECK
s32 func_88A008CC(u8 *);
#else
s32 func_88A008CC();
#endif

void func_88A00938(u8 *arg0) {
#ifdef CC_CHECK
    if (func_88A008CC((u8 *)0) != 0) {
#else
    if (func_88A008CC() != 0) {
#endif
        func_80063620(*arg0, arg0);
        return;
    }
    func_800635E0(*arg0, arg0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA9F0/func_88A00978.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA9F0/func_88A00B44.s")

/* mkdraft:func_88A00D0C begin */
extern s8 D_88006868;
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 func_8006229C(u8 *);
extern u8 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 GbSave_GetRecordCapacity(s32);
extern s32 _bcopy(u8 *, u8 *, s32);
extern u16 func_80053230(s32);
extern s32 func_88A00978(u8 *, u8 *);
extern s32 func_88A015A0(s32);
extern u8 *mem_pool_alloc(s32, s32);
extern u8 *D_88A01C60;
extern u8 *D_88A01C64;



void func_88A00D0C(s32 arg0) {
    s32 pad[2]; // FAKE: dead stack pad; DIFF 2 without it
    u16 sp3C[2]; // FAKE: 2-element array only to force the 4-byte-aligned frame slot at 0x3c; DIFF 2 as a scalar u16
    s32 sp38_arr[2];
    s32 sp2C; // FAKE: dead store; DIFF 13 without it
    s32 temp_a1;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 var_s1;
    u8 *temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;
    u8 *temp_v0_4;

    temp_s1 = GbSave_GetRecordCapacity(0x22) & 0xFFFF;
    sp3C[0] = func_80053230(0x12);
    D_88A01C60 = mem_pool_alloc(arg0, 0xB0);
    D_88A01C64 = mem_pool_alloc(arg0, 0x114);
    *(u8 **)((u8 *)D_88A01C60 + 0x9C) = mem_pool_alloc(arg0, (sp38_arr[1] = temp_s1) * 2);
    *(u8 **)((u8 *)D_88A01C64 + 0xF0) = mem_pool_alloc(arg0, (sp38_arr[1] * 2) + 2);
    temp_s1_2 = sp3C[0] * 2;
    sp38_arr[0] = (s32) sp3C[0];
    *(u8 **)((u8 *)D_88A01C60 + 0xA4) = mem_pool_alloc(arg0, temp_s1_2);
    temp_a1 = (sp38_arr[0] * 2) + 2;
    sp2C = temp_a1; // FAKE: dead store; DIFF 13 without it
    *(u8 **)((u8 *)D_88A01C64 + 0xF8) = mem_pool_alloc(arg0, temp_a1);
    *(u8 **)((u8 *)D_88A01C60 + 0xAC) = mem_pool_alloc(arg0, temp_s1_2);
    *(u8 **)((u8 *)D_88A01C64 + 0x100) = mem_pool_alloc(arg0, temp_a1);
    temp_v0 = func_8006218C(0x23, (s32) D_88006868, 0, 0);
    Deck_ReadEntries(D_88A01C60, 1, temp_v0);
    func_8006229C(temp_v0);
    func_88A00978(D_88A01C60, D_88A01C64);
    temp_v0_2 = func_8006218C(0x22, (s32) D_88006868, 0, 0);
    *(u8 *)((u8 *)D_88A01C60 + 0x98) = Deck_ReadEntries(*(u8 **)((u8 *)D_88A01C60 + 0x9C), sp38_arr[1], temp_v0_2);
    func_8006229C(temp_v0_2);
    _bcopy(*(u8 **)((u8 *)D_88A01C60 + 0x9C), *(u8 **)((u8 *)D_88A01C64 + 0xF0), *(u8 *)((u8 *)D_88A01C60 + 0x98) * 2);
    *(u8 *)((u8 *)D_88A01C64 + 0xEF) = *(u8 *)((u8 *)D_88A01C60 + 0x98);
    temp_v0_3 = func_8006218C(0x12, 0, 0, 0);
    *(u8 *)((u8 *)D_88A01C60 + 0xA0) = Deck_ReadEntries(*(u8 **)((u8 *)D_88A01C60 + 0xA4), sp38_arr[0], temp_v0_3);
    func_8006229C(temp_v0_3);
    _bcopy(*(u8 **)((u8 *)D_88A01C60 + 0xA4), *(u8 **)((u8 *)D_88A01C64 + 0xF8), *(u8 *)((u8 *)D_88A01C60 + 0xA0) * 2);
    *(u8 *)((u8 *)D_88A01C64 + 0xF4) = *(u8 *)((u8 *)D_88A01C60 + 0xA0);
    temp_v0_4 = func_8006218C(0x12, 0, 1, 0);
    *(u8 *)((u8 *)D_88A01C60 + 0xA8) = Deck_ReadEntries(*(u8 **)((u8 *)D_88A01C60 + 0xAC), sp38_arr[0], temp_v0_4);
    func_8006229C(temp_v0_4);
    _bcopy(*(u8 **)((u8 *)D_88A01C60 + 0xAC), *(u8 **)((u8 *)D_88A01C64 + 0x100), *(u8 *)((u8 *)D_88A01C60 + 0xA8) * 2);
    *(u8 *)((u8 *)D_88A01C64 + 0xFC) = *(u8 *)((u8 *)D_88A01C60 + 0xA8);
    for (var_s1 = 0; var_s1 != 4; var_s1++) {
        temp_s1 = var_s1 * 4;
        *(s32 *)((u8 *)&D_88A01C64[temp_s1] + 0x104) = 0;
        func_88A015A0(var_s1);
    }
}
/* mkdraft:func_88A00D0C end */

s32 func_88A00FD4(u8 arg0) {
    s32 result = 0;
    switch (arg0) {
    case 2:
        result = 3;
        break;
    case 3:
        result = 1;
        break;
    case 4:
        result = 2;
        break;
    }
    return result;
}

s32 func_88A01018(u8 arg0) {
    u8 *table;
    s16 index;
    u32 i;

    table = D_88A01C64;
    index = table[7];
    for (i = 0; i < table[3]; i++) {
        if (arg0 < ((u8 (*)[2])(table + 9))[index][0]) {
            break;
        }
        index++;
    }
    return index;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA9F0/func_88A01074.s")

// Adds arg1 to byte 0, byte arg0 + 1 and bytes arg0 + 6 through 8 of *D_88A01C64.
void func_88A013E8(s32 arg0, s8 arg1) {
    u32 i;

    D_88A01C64[0] += arg1;
    (D_88A01C64 + arg0)[1] += arg1;
    for (i = arg0 + 1; i < 4; i++) {
        (D_88A01C64 + i)[5] += arg1;
    }
}

extern s32 func_8800005C(void);
extern u8 func_8006378C(u8);
extern s32 func_88A00FD4(u8);
extern void func_88A013E8(s32, s8);
void func_88A014C8(s32 arg0, u8 arg1, s8 arg2) {
    s32 index;

    switch (arg0) {
    case 0:
        if (func_8800005C() != 0) {
            index = 0;
        } else {
            index = func_88A00FD4(func_8006378C(arg1));
        }
        func_88A013E8(index, arg2);
        break;
    case 1:
        D_88A01C64[0xEF] += arg2;
        break;
    case 2:
        D_88A01C64[0xF4] += arg2;
        break;
    case 3:
        D_88A01C64[0xFC] += arg2;
        break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA9F0/func_88A015A0.s")

// A two-byte list entry; func_88A016F0 inserts one and shifts the rest up.
typedef struct Fragment39Entry {
    /* 0x0 */ u8 unk_00;
    /* 0x1 */ u8 unk_01;
} Fragment39Entry; // size = 0x2
extern u8 * func_88A00710(s32 arg0, s16 arg1);
extern u8 func_88A007BC(s32 arg0);
extern void func_88A014C8(s32 arg0, u8 arg1, s8 arg2);
void func_88A016F0(s32 arg0, Fragment39Entry *arg1, s16 index) {
    Fragment39Entry *p;
    s32 i;
    u16 count;
    Fragment39Entry cur;
    Fragment39Entry tmp;

    func_88A014C8(arg0, arg1->unk_00, 1);
    count = func_88A007BC(arg0);
    p = (Fragment39Entry *)func_88A00710(arg0, index);
    cur = *arg1;
    for (i = index; ; i++) {
        if (i == count - 1) {
            *p = cur;
            break;
        }
        tmp = *p;
        *p++ = cur;
        cur = tmp;
    }
}

/* mkdraft:func_88A017B4 begin */
extern s32 func_8800005C(void);
extern u8 func_8006378C(u8);
extern s32 func_88A00FD4(u8);
extern s32 func_88A01018(u8);
extern void func_88A016F0(s32 arg0, Fragment39Entry *arg1, s16 index);

// Adds the two-byte entry {arg0, 1} to the list selected by arg1, unless the
// list already holds an entry whose first byte is arg0 and whose second byte is
// below 99: that entry only has its second byte raised. The party list
// (arg1 == 0) is ordered rather than appended: the species group comes from
// func_88A00FD4(func_8006378C(arg0)), group 2 finds its slot by scanning with
// func_88A01018, and the other groups insert after the counters at
// D_88A01C64 + group + 1 and D_88A01C64 + group + 5. Lists 1-3, and the party
// list while func_8800005C() is nonzero, append at the end. The write flag at
// D_88A01C64 + arg1 * 4 + 0x104 is set for func_88A01990.


void func_88A017B4(u8 arg0, s32 arg1) {
    s32 slot;
    u8 count;
    u8 *p;
    Fragment39Entry entry;
    s16 index;
    u32 i;

    count = func_88A007BC(arg1);
    p = func_88A00710(arg1, 0);
    *(s32 *)(D_88A01C64 + (arg1 << 2) + 0x104) = 1;
    for (i = 0; i < count; i++) {
        if (p[0] == arg0 && p[1] != 0x63) {
            p[1]++;
            return;
        }
        p += 2;
    }
    entry.unk_00 = arg0;
    entry.unk_01 = 1;
    if (func_8800005C() == 0 && arg1 == 0) {
        slot = func_88A00FD4(func_8006378C(arg0));
        if (slot == 2) {
            index = func_88A01018(arg0);
        } else {
            index = *(D_88A01C64 + slot + 5) + *(D_88A01C64 + slot + 1);
        }
    } else {
        index = count;
    }
    func_88A016F0(arg1, &entry, index);
}
/* mkdraft:func_88A017B4 end */

extern s8 D_88006868;
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_WriteEntries(void *, s32, u8 *);
extern s32 func_8006229C(u8 *);
extern void func_88A00B44(u8 *, u8 *);
// For each of the four pending-write flags at D_88A01C64 + 0x104, opens the
// matching save handle with func_8006218C, writes that table's entries with
// Deck_WriteEntries, closes the handle and clears the flag.
void func_88A01990(void) {
    s32 i;
    s32 offset;
    u8 buffer[0x98];
    u8 *handle;

    for (i = 0; i < 4; i++) {
        offset = i * 4;
        if (*(s32 *)(D_88A01C64 + offset + 0x104)) {
            switch ((u32)i) {
                case 0:
                    handle = func_8006218C(35, D_88006868, 0, 1);
                    if (handle != NULL) {
                        func_88A00B44(D_88A01C64, buffer);
                        Deck_WriteEntries(buffer, 1, handle);
                        func_8006229C(handle);
                    }
                    break;
                case 1:
                    handle = func_8006218C(34, D_88006868, 0, 1);
                    if (handle != NULL) {
                        Deck_WriteEntries(*(u8 **)(D_88A01C64 + 0xF0), D_88A01C64[0xEF], handle);
                        func_8006229C(handle);
                    }
                    break;
                case 2:
                    handle = func_8006218C(18, 0, 0, 1);
                    if (handle != NULL) {
                        Deck_WriteEntries(*(u8 **)(D_88A01C64 + 0xF8), D_88A01C64[0xF4], handle);
                        func_8006229C(handle);
                    }
                    break;
                case 3:
                    handle = func_8006218C(18, 0, 1, 1);
                    if (handle != NULL) {
                        Deck_WriteEntries(*(u8 **)(D_88A01C64 + 0x100), D_88A01C64[0xFC], handle);
                        func_8006229C(handle);
                    }
                    break;
            }
            *(s32 *)(D_88A01C64 + offset + 0x104) = 0;
        }
    }
}

#pragma C_FUNCTION_PADDING(8)
#endif
