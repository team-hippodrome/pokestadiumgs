#include "global.h"


#ifdef VERSION_US
extern s32 func_80063754();
extern s16 func_88A00248(void *, s32 *, u8 **, void *, s32, s8);
extern void _bcopy(void *, void *, s32);
extern void _bzero(void *, s32);
extern s8 D_88006868;
extern s16 D_882345F0;
extern u8 D_882345F8[];
extern u8 D_88234618[];
extern s32 D_88A01C30;
extern u8 *D_88A01C34;
extern u8 (*D_88A01C38)[0x60];
extern u8 D_88A01C40[];

void func_882011E0(void *arg0) {
    u32 i;

    D_882345F0 = func_88A00248(arg0, &D_88A01C30, &D_88A01C34, &D_88A01C38, 3, D_88006868);
    _bcopy(D_88A01C40, D_882345F8, 30);
    _bzero(D_88234618, 6);
    for (i = 0; i < D_88A01C34[0x15]; i++) {
        if (func_80063754(D_88A01C38[i][9]) != 0) {
            D_88234618[i] = 1;
        }
    }
}
s8 func_882012E4(void *arg0) {
    u8 *state = *(u8 **)arg0;
    void **entry = *(void ***)(state + 0x10);
    s32 index = 0;
    u32 count = state[0x15];
    s32 result = -1;
    if (count != 0) {
loop:
        if (*entry == arg0) {
            return index;
        }
        index++;
        entry++;
        if (index < count) {
            goto loop;
        }
    }
    return result;
}

s8 func_88201330(void *arg0) {
    u8 *state = *(u8 **)arg0;
    void **entry = *(void ***)(state + 0xC);
    s32 index = 0;
    u32 count = state[0x11];
    s32 result = -1;
    if (count != 0) {
loop:
        if (*entry == arg0) {
            return index;
        }
        index++;
        entry++;
        if (index < count) {
            goto loop;
        }
    }
    return result;
}

typedef struct unk_D_88234634 {
    u8 *entries;
    u8 unk_04[8];
} unk_D_88234634;

extern unk_D_88234634 D_88234634[];
extern void *D_88234664;

void *func_8820137C(void *arg0) {
    u8 type = ((u8 *)**(void ***)arg0)[8];
    s8 index;

    switch (type) {
        case 0:
            index = func_882012E4(arg0);
            break;
        case 2:
            index = ((u8 *)arg0)[39] - 1;
            break;
        default:
            return D_88234664;
    }
    return D_88234634[type].entries + index * 118;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_174460/func_88201420.s")

extern void func_88201420(s32, s32);
void func_88201608(s32 arg0) {
    func_88201420(arg0, 1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_174460/func_88201628.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_174460/func_8820172C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_174460/func_882017F8.s")

extern void func_88200320(void *, void *);
extern void func_88201628(u8 *, u8 *);
extern u8 D_88234630[];
extern s32 func_80063754();
extern void * func_8820137C(void *arg0);
void func_88201A74(u8 *a, u8 *b) {
    u8 **listA;
    u8 **listB;
    u8 slotA;
    u8 slotB;
    void *first;

    listA = *(u8 ***)a;
    listB = *(u8 ***)b;
    slotA = (*listA)[8];
    slotB = (*listB)[8];

    if (func_80063754(a[9]) && func_80063754(b[9])) {
        first = func_8820137C(a);
        func_88200320(first, func_8820137C(b));
        *(s32 *)(D_88234630 + slotB * 12 + 8) = 1;
        *(s32 *)(D_88234630 + slotA * 12 + 8) = 1;
    } else if (func_80063754(a[9])) {
        func_88201628(a, b);
    } else if (func_80063754(b[9])) {
        func_88201628(b, a);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_174460/func_88201B74.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_174460/func_88201CF4.s")

void func_88201E28(void *arg0, void *arg1) {
    void **var_v1;
    void **var_a3;
    u8 var_a0;
    void *var_t0;
    void *var_t1;

    *(s32 *)((u8 *)arg0 + 12) = *(s32 *)((u8 *)arg1 + 12) = 1;
    var_v1 = *(void ***)((u8 *)*(void **)arg0 + 12);
    var_v1 += func_88201330(arg0);
    var_a3 = *(void ***)((u8 *)*(void **)arg1 + 12);
    var_a3 += func_88201330(arg1);
    var_a0 = ((u8 *)arg0)[4];
    ((u8 *)arg0)[4] = ((u8 *)arg1)[4];
    ((u8 *)arg1)[4] = var_a0;
    var_t0 = *(void **)arg0;
    *(void **)arg0 = *(void **)arg1;
    *(void **)arg1 = var_t0;
    var_t1 = *var_v1;
    *var_v1 = *var_a3;
    *var_a3 = var_t1;
}

typedef struct {
    u8 pad[0xC];
    void **entries;
    u32 unused;
} EntryRow_88201ED0;
extern s32 D_88A01C30;
void *func_88201ED0(u8 arg0, u8 arg1) {
    void **entries = ((EntryRow_88201ED0 *)D_88A01C30)[arg0].entries;
    return entries[arg1];
}

s32 func_88201F0C(void) {
    struct S {
        u8 pad[0x10];
        void **entries;
        u8 unk_14;
        u8 count;
    };
    struct R {
        u8 pad[0x26];
        u8 flags;
    };
    struct R **entry = ((struct S *)D_88A01C34)->entries;
    u32 i;

    if (((struct S *)D_88A01C34)->count == 0) {
        return 1;
    }
    for (i = 0; i < ((struct S *)D_88A01C34)->count; i++, entry++) {
        if (!((*entry)->flags & 1) && *(u16 *)((u8 *)*entry + 0x2E) != 0) {
            return 0;
        }
    }
    return 1;
}

extern s32 HAL_Strcmp(const s8 *, const s8 *);
extern s8 D_8800686D[];
extern u8 D_882345D4;
extern u16 D_8800686A;
s32 func_88201F7C(void *arg0) {
    s32 result = 1;
    if (D_882345D4 == 0) {
        if (*(u16 *)((u8 *)arg0 + 6) != *(u16 *)&D_8800686A ||
            HAL_Strcmp(D_8800686D, (s8 *)((u8 *)arg0 + 0x40)) != 0) result = 0;
    }
    return result;
}
#endif
