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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA9F0/func_88A00D0C.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA9F0/func_88A017B4.s")

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
