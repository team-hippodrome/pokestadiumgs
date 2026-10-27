#include "global.h"


#ifdef VERSION_US
typedef struct S1_unk_func_88316128 {
    /* 0x00 */ char unk00[0x8];
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk09[0xD];
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ char unk18[0x14];
    /* 0x2C */ u8 unk_2C;
    /* 0x2E */ u16 unk_2E;
    /* 0x30 */ u16 unk_30;
    /* 0x32 */ u16 unk_32;
    /* 0x34 */ u16 unk_34;
    /* 0x36 */ u16 unk_36;
    /* 0x38 */ u8 unk_38;
    /* 0x39 */ char unk39[0xA];
    /* 0x43 */ u8 unk_43;
} S1_unk_func_88316128;
s32 LabPCList_CompareByPointer(S1_unk_func_88316128* arg0, S1_unk_func_88316128* arg1) {
    return (arg0 == arg1) ? 0 : (arg0 < arg1) ? -1 : 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_18F6D0/func_8821C47C.s")

extern void func_8821C47C(s32, s32, s32);
void func_8821C690(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 1);
}

void func_8821C6B0(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 2);
}

void func_8821C6D0(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 3);
}

void func_8821C6F0(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 4);
}

void func_8821C710(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 5);
}

void func_8821C730(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 6);
}

void func_8821C750(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 7);
}

s32 func_8821C770(S1_unk_func_88316128 *arg0, S1_unk_func_88316128 *arg1) {
    s32 difference;
    s32 result;
    S1_unk_func_88316128 *entries[2];
    u8 values[2];
    u8 i;

    entries[0] = arg0;
    entries[1] = arg1;
    for (i = 0; i < 2; i++) {
        if (((u8 *)entries[i])[38] & 1) {
            values[i] = 253;
        } else {
            values[i] = entries[i]->unk_08;
        }
    }
    difference = values[0] - values[1];
    if (difference != 0) {
        result = difference;
    } else {
        result = LabPCList_CompareByPointer(arg0, arg1);
    }
    return result;
}

extern u8 func_800637C0(u8);
s32 func_8821C820(S1_unk_func_88316128 *arg0, S1_unk_func_88316128 *arg1) {
    s32 difference;
    s32 result;
    S1_unk_func_88316128 *entries[2];
    s16 values[2];
    u8 i;

    entries[0] = arg0;
    entries[1] = arg1;
    for (i = 0; i < 2; i++) {
        if (((u8 *)entries[i])[38] & 1) {
            values[i] = 257;
        } else if (entries[i]->unk_08 == 252) {
            values[i] = 256;
        } else {
            values[i] = func_800637C0(entries[i]->unk_08);
        }
    }
    difference = values[0] - values[1];
    if (difference != 0) {
        result = difference;
    } else {
        result = LabPCList_CompareByPointer(entries[0], entries[1]);
    }
    return result;
}


typedef struct {
    u8 pad_00[8];
    u8 unk_08;
} Func8821C924Leaf;
typedef struct {
    Func8821C924Leaf *unk_00;
    u8 unk_04;
} Func8821C924Inner;
typedef struct {
    Func8821C924Inner *unk_00;
    s8 unk_04;
} Func8821C924Item;

s32 func_8821C924(Func8821C924Item *arg0, Func8821C924Item *arg1) {
    s32 result;
    result = arg0->unk_00->unk_00->unk_08 - arg1->unk_00->unk_00->unk_08;
    if (result == 0) {
        result = arg0->unk_00->unk_04 - arg1->unk_00->unk_04;
        if (result == 0) {
            result = arg0->unk_04 - arg1->unk_04;
        }
    }
    return result;
}

s32 func_8821C970(S1_unk_func_88316128 *arg0, S1_unk_func_88316128 *arg1) {
    s32 difference;
    s32 result;
    S1_unk_func_88316128 *entries[2];
    s32 values[2];
    u8 i;

    entries[0] = arg0;
    entries[1] = arg1;
    for (i = 0; i < 2; i++) {
        if (((u8 *)entries[i])[38] & 1) {
            values[i] = 100000;
        } else {
            values[i] = *(u16 *)((u8 *)entries[i] + 14);
        }
    }
    difference = values[0] - values[1];
    if (difference != 0) {
        result = difference;
    } else {
        result = LabPCList_CompareByPointer(arg0, arg1);
    }
    return result;
}

extern u8 func_80073450(u8);
s32 func_8821CA24(S1_unk_func_88316128 *arg0, S1_unk_func_88316128 *arg1) {
    s32 difference;
    s32 result;
    S1_unk_func_88316128 *entries[2];
    u8 values[2];
    u8 first;
    u8 i;

    entries[0] = arg0;
    entries[1] = arg1;
    for (i = 0; i < 2; i++) {
        if (((u8 *)entries[i])[38] & 1) {
            values[i] = 253;
        } else {
            values[i] = entries[i]->unk_08;
        }
    }
    first = func_80073450(values[0]);
    difference = first - func_80073450(values[1]);
    if (difference != 0) {
        result = difference;
    } else {
        result = LabPCList_CompareByPointer(entries[0], entries[1]);
    }
    return result;
}

void func_8821CADC(s32 arg0, s32 arg1) {
    func_8821C47C(arg0, arg1, 13);
}

extern s32 func_80073828(s8 *, s8 *);
s32 func_8821CAFC(S1_unk_func_88316128 *arg0, S1_unk_func_88316128 *arg1) {
    s32 value = func_80073828((s8 *)arg0 + 0x3C, (s8 *)arg1 + 0x3C);
    s32 result;
    if (value != 0) {
        result = value;
    } else {
        result = LabPCList_CompareByPointer(arg0, arg1);
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_18F6D0/func_8821CB48.s")

extern u8 func_800735A0(u8);
s32 func_8821CC0C(S1_unk_func_88316128 *arg0, S1_unk_func_88316128 *arg1) {
    s32 difference;
    s32 result;
    S1_unk_func_88316128 *entries[2];
    s16 values[2];
    u8 i;

    entries[0] = arg0;
    entries[1] = arg1;
    for (i = 0; i < 2; i++) {
        if (((u8 *)entries[i])[9] == 0 || (((u8 *)entries[i])[38] & 1)) {
            values[i] = 256;
        } else {
            values[i] = func_800735A0(((u8 *)entries[i])[9]);
        }
    }
    difference = values[0] - values[1];
    if (difference != 0) {
        result = difference;
    } else {
        result = LabPCList_CompareByPointer(entries[0], entries[1]);
    }
    return result;
}

extern void func_88004B60(void *, s32, void *);
extern s32 func_8821C820(S1_unk_func_88316128 *, S1_unk_func_88316128 *);
extern s32 func_8821CB48(S1_unk_func_88316128 *, S1_unk_func_88316128 *);
extern void *D_88234750;
extern u16 D_88234744;
extern s32 D_882347D0;

// Sorts the D_88234744 entries at D_88234750 with the comparator selected by
// sort_mode (1-16); mode 0 leaves the list unsorted. arg1 is stored in D_882347D0.
void func_8821CCE8(u32 sort_mode, s32 arg1) {
    void *compare;

    D_882347D0 = arg1;
    switch (sort_mode) {
        case 0:
            return;
        case 1:
            compare = (void *)func_8821C690;
            break;
        case 2:
            compare = (void *)func_8821C6B0;
            break;
        case 3:
            compare = (void *)func_8821C6D0;
            break;
        case 4:
            compare = (void *)func_8821C6F0;
            break;
        case 5:
            compare = (void *)func_8821C710;
            break;
        case 6:
            compare = (void *)func_8821C730;
            break;
        case 7:
            compare = (void *)func_8821C750;
            break;
        case 8:
            compare = (void *)func_8821C770;
            break;
        case 9:
            compare = (void *)func_8821C820;
            break;
        case 10:
            compare = (void *)func_8821C924;
            break;
        case 11:
            compare = (void *)func_8821C970;
            break;
        case 12:
            compare = (void *)func_8821CA24;
            break;
        case 13:
            compare = (void *)func_8821CADC;
            break;
        case 14:
            compare = (void *)func_8821CAFC;
            break;
        case 15:
            compare = (void *)func_8821CB48;
            break;
        case 16:
            compare = (void *)func_8821CC0C;
            break;
    }
    func_88004B60(D_88234750, D_88234744, compare);
}
#endif
