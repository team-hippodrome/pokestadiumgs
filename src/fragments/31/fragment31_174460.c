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

extern u8 D_88234630[];
extern s32 D_88234638;

// 0x76-byte Lab PC storage entry
typedef struct unk_88201420_rec {
    u16 unk_00[0x3B];
} unk_88201420_rec;



void func_88201420(s32 arg0, s32 arg1) {
    u8 *state;
    s32 value;
    s32 i;
    u8 *list0;
    void **list;
    u8 *dest;

    state = *(u8 **)arg0;
    if (arg1 != 0 && func_80063754(*(u8 *)(arg0 + 9)) != 0) {
        func_88203A58(func_8820137C((void *)arg0));
    }
    state[0x15] = state[0x15] - 1;
    *(s32 *)(state + 0xC) = 1;
    value = func_882012E4((void *)arg0);
    // The bound must go through a pointer local. Inlining list0[0] back into the
    // for condition makes IDO reuse one address register for the preheader and
    // the latch load (diff 235); through list0 it rematerialises the address in
    // the preheader like the retail object.
    list0 = D_88234630;
    if ((*(u8 **)state)[8] == 0) {
        // Keep this if/else on one line: splitting it changes IDO's scheduling of
        // the copy loop (diff 295).
        if (value == -1) { dest = state[0x15] * 118 + (u8 *)D_88234634[0].entries; } else { i = value; dest = value * 118 + (u8 *)D_88234634[0].entries; for (; i < (list0[0] - 1); i++) { *(unk_88201420_rec *)dest = *((unk_88201420_rec *)dest + 1); dest += 118; } }
        _bzero(dest, 0x76);
        D_88234638 = 1;
    }
    if (value != -1) {
        i = value;
        list = *(void ***)(state + 0x10);
        list += value;
        for (; i < state[0x15]; i++) {
            list[0] = list[1];
            ((s8 *)list[0])[4]--;
            list++;
        }
    }
}

extern void func_88201420(s32, s32);
void func_88201608(s32 arg0) {
    func_88201420(arg0, 1);
}

s32 func_88204050();
extern void func_88203BE4(void *, void *, s8);
extern s8 func_882012E4(void *);
extern void *func_8820137C(void *);
extern void *D_88234664;
extern u8 D_88234630[];



void func_88201628(u8 *arg0, u8 *arg1)
{
    struct
    {
        u8 unk_00;  // FAKE: occupies 0x24; without it the 3-byte struct lands at 0x24-0x26 instead of 0x25-0x27 (diff score 9).
        s8 slot;  // battle slot number: written to arg1[0x27], returned by both arm calls, read signed at 0x25 for the final call.
        u8 types[2];  // [0] destination list type from arg1, [1] source list type from arg0; each is byte +8 of *(*arg).
    } ts;
    u8 *entry;
    ts.types[1] = ((u8 *)*(void **)*(void **)arg0)[8];
    ts.types[0] = ((u8 *)*(void **)*(void **)arg1)[8];
    entry = func_8820137C(arg0);
    if (ts.types[0] == 2)
    {
        if (ts.types[1] == 2)
        {
            arg1[0x27] = arg0[0x27];
            arg0[0x27] = 0;
            return;
        }
        ts.slot = (s8)func_88204050();
        if ((!ts.types) && (!ts.types))  // FAKE: always false (an array decays to a non-null pointer); the reference fixes the epilogue temporaries to t8/t0/t9/t2/t1 (diff score 110 without it).
        {
        }
        arg1[0x27] = ts.slot + 1;
    }
    else
    {
        ts.slot = func_882012E4(arg1);
        arg1[0x27] = 0;
    } arg0[0x27] = 0;
    if (entry == D_88234664)
    {
        ((u8 *)entry)[0x75] = arg0[9];
    }
    func_88203BE4(entry, (u8 *)D_88234630 + ts.types[0] * 12, ts.slot);
}

/* mkdraft:func_8820172C begin */
extern s32 func_88204050(void);
extern void func_88203BE4(void *, void *, s8);
extern void *func_8820137C(void *arg0);
extern u8 D_88234630[];
extern void *D_88234664;



void func_8820172C(u8 *arg0, u8 **arg1, s8 arg2) {
    struct {
        u8 unk_00[2]; // FAKE: unused stack slot; puts types at 0x1E/0x1F; diff score 12 without it.
        u8 types[2];  // [0] destination list type from *arg1; [1] source list type from **(void ***)arg0
    } ts;
    u8 *entry;
    s8 slot;

    ts.types[1] = ((u8 *)*(void **)*(void **)arg0)[8];
    ts.types[0] = ((u8 *)*arg1)[8];
    entry = func_8820137C(arg0);
    if (ts.types[0] == 2) {
        if (ts.types[1] == 2) {
            return;
        }
        slot = func_88204050();
        arg0[39] = slot + 1;
    } else {
        slot = arg2;
        arg0[39] = 0;
    }
    if (entry == D_88234664) {
        entry[0x75] = arg0[9];
    }
    func_88203BE4(entry, (u8 *)D_88234630 + ts.types[0] * 12, slot);
}
/* mkdraft:func_8820172C end */

extern void _bzero(void *, s32);
extern s32 func_80063754();
extern void func_88201420(s32, s32);
extern u8 D_88234630[];

// 0x76-byte Lab PC storage entry; the shift loop copies whole entries and
// func_88203ED8 assigns the same-sized record into a storage list.
//@src/fragments/31/fragment31_1768F0.c
typedef struct unk_882017F8_rec {
    u16 unk_00[0x3B];
} unk_882017F8_rec;

// 12-byte storage-list header (count, capacity, record pointer, dirty flag).
// List 0 is D_88234630; func_88200DCC walks all four lists through this layout.
//@src/fragments/31/fragment31_1736F0.c
typedef struct LabPCStorageList {
    u8 count;
    u8 capacity;
    void *entries;
    s32 changed;
} LabPCStorageList;

// Moves slot arg0 to index arg2 of the list owned by slot arg1. When arg1 is a
// newly created slot, the D_88234630 list shifts its entries up by one from
// capacity-1, frees the vacated entry at arg2, and marks the list dirty. The
// tail loop then walks the list from arg2, carrying the displaced entry forward
// until the new count is reached.


void func_882017F8(u8 *arg0, u8 *arg1, s8 arg2) {
    unk_882017F8_rec *p;
    void **list;
    void *cur;
    void *saved;
    s32 i;

    cur = arg0;
    if ((((*(u8 **)*(void **)arg0)[8] == 2) && ((*(u8 **)arg1)[8] != 2)) ||
        (((*(u8 **)*(void **)arg0)[8] != 2) && ((*(u8 **)arg1)[8] == 2))) {
        if (((arg0[38] & 1) != 0) == 0) {
            arg0[36] = 70;
        }
    }
    if (((*(u8 **)arg1))[8] == 0) {
        i = ((LabPCStorageList *)D_88234630)->capacity - 1;
        p = (unk_882017F8_rec *)((LabPCStorageList *)D_88234630)->entries + i;
        for (; i > arg2; i--) {
            *p = *(p - 1);
            p--;
        }
        _bzero(p, 0x76);
        ((LabPCStorageList *)D_88234630)->changed = 1;
    }
    if (func_80063754(arg0[9]) != 0) {
        func_8820172C(arg0, arg1, arg2);
    }
    arg1[0x15] = arg1[0x15] + 1;
    *(s32 *)(arg1 + 0xC) = 1;
    list = *(void ***)(arg1 + 0x10);
    list += arg2;
    for (; arg2 < arg1[0x15]; arg2++, list++) {
        if (arg2 != arg1[0x15] - 1) {
            saved = *list;
        }
        *list = cur;
        if (arg2 != arg1[0x15] - 1) {
            cur = saved;
        }
        ((u8 *)*list)[4] = arg2;
    }
    func_88201420((s32)arg0, 0);
    *(void **)arg0 = arg1;
}

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

/* mkdraft:func_88201B74 begin */
extern u8 func_882002F8(u8 *arg0, u8 *arg1);
extern void func_8820172C(u8 *arg0, u8 **arg1, s8 arg2);



void func_88201B74(void *arg0, void *arg1) {
    u8 **listA;
    u8 **listB;
    u8 slotA;
    u8 slotB;

    listA = *(u8 ***)arg0;
    listB = *(u8 ***)arg1;
    slotA = (*listA)[8];
    slotB = (*listB)[8];

    if (func_80063754(((u8 *)arg0)[9]) && func_80063754(((u8 *)arg1)[9])) {
        if (slotA == 2 && slotB == 2) {
            return;
        }
        func_88200320(func_8820137C(arg0), func_8820137C(arg1));

        *(s32 *)(D_88234630 + (u32)slotB * 12 + 8) = 1; // FAKE: the (u32) cast; diff score 689 without it.
        *(s32 *)(D_88234630 + (u32)slotA * 12 + 8) = 1; // FAKE: the (u32) cast; diff score 689 without it.
        if ((slotA == 2 && slotB == 0) || (slotA == 0 && slotB == 2)) {
            func_882002F8((u8 *)arg0 + 0x27, (u8 *)arg1 + 0x27);
        }
    } else if (func_80063754(((u8 *)arg0)[9])) {
        func_8820172C(arg0, listB, (s8)(s32)func_882012E4(arg1));
    } else if (func_80063754(((u8 *)arg1)[9])) {
        func_8820172C(arg1, listA, (s8)(s32)func_882012E4(arg0));
    }
}
/* mkdraft:func_88201B74 end */

extern void func_88201B74(void *, void *);
extern u32 func_8820030C(u32 *, u32 *);
void func_88201CF4(u8 *arg0, u8 *arg1) {
    u8 *owner_a;
    u8 *owner_b;
    u32 *entry_a;
    u32 *entry_b;
    s8 index;
    void *owner;

    owner_a = *(u8 **)arg0;
    owner_b = *(u8 **)arg1;
    if (((*(u8 **)owner_a)[8] == 2 && (*(u8 **)owner_b)[8] != 2) ||
        ((*(u8 **)owner_a)[8] != 2 && (*(u8 **)owner_b)[8] == 2)) {
        if (((arg0[38] & 1) != 0) == 0) {
            arg0[36] = 70;
        }
        if (((arg1[38] & 1) != 0) == 0) {
            arg1[36] = 70;
        }
    }
    *(s32 *)(owner_a + 12) = *(s32 *)(owner_b + 12) = 1;
    func_88201B74(arg0, arg1);
    entry_a = *(u32 **)(owner_a + 16);
    entry_a += func_882012E4(arg0);
    entry_b = *(u32 **)(owner_b + 16);
    entry_b += func_882012E4(arg1);
    index = *(s8 *)(arg0 + 4);
    arg0[4] = *(s8 *)(arg1 + 4);
    arg1[4] = index;
    owner = *(void **)arg0;
    *(void **)arg0 = *(void **)arg1;
    *(void **)arg1 = owner;
    func_8820030C(entry_a, entry_b);
}

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
