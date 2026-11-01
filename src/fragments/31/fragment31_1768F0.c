#include "global.h"


#ifdef VERSION_US
extern u8 D_88234618[];
extern u8 D_882345F8[];
extern void _bzero(void *, s32);
void func_88203670(s32 type, u8 *entries, u8 count) {
    u32 i;

    switch (type) {
        case 0:
            for (i = 0; i < count; i++) {
                if (D_88234618[i] == 0) {
                    _bzero(entries, 0x76);
                }
                entries += 0x76;
            }
            break;
        case 2:
            for (i = 0; i < count; i++) {
                if (D_882345F8[i] == 0) {
                    _bzero(entries, 0x76);
                }
                entries += 0x76;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1768F0/func_88203744.s")

typedef struct LabPCStorageList {
    u8 count;
    u8 capacity;
    void *entries;
    s32 changed;
} LabPCStorageList;

// One 0x76-byte Lab PC storage entry (halfword aligned); see func_88203670's 0x76 stride.
typedef struct unk_func_88203ED8 {
    u16 unk_00[0x3B];
} unk_func_88203ED8;

extern LabPCStorageList D_88234630[];

/* mkdraft:func_8820390C begin */

// Index of the D_88234630 list whose 0x76-byte entry array contains the
// address arg0, or 0 when none does. The upper bound is the start address of
// the last allocated entry (entries + count * 0x76 - 0x76), so only that
// entry's first byte is inside the compared range.


s32 func_8820390C(u8 *arg0) {
    LabPCStorageList *list;
    s32 i;

    list = D_88234630;
    for (i = 0; i < 4; i++) {
        if (arg0 >= (u8 *)list->entries && arg0 <= (u8 *)list->entries + list->count * 0x76 - 0x76) {
            return i;
        }
        list++;
    }
    return 0;
}
/* mkdraft:func_8820390C end */

/* mkdraft:func_88203A18 begin */
#pragma REWRITE_FUNCTION_WORD(func_88203A18, 0x00, 0x90A60001, 0x90A20001)
#pragma REWRITE_FUNCTION_WORD(func_88203A18, 0x08, 0x50C0000B, 0x5040000B)
#pragma REWRITE_FUNCTION_WORD(func_88203A18, 0x10, 0x8CA20004, 0x8CA60004)
#pragma REWRITE_FUNCTION_WORD(func_88203A18, 0x14, 0x54820004, 0x54860004)
#pragma REWRITE_FUNCTION_WORD(func_88203A18, 0x28, 0x0066082B, 0x0062082B)
#pragma REWRITE_FUNCTION_WORD(func_88203A18, 0x30, 0x24420076, 0x24C60076)

s32 func_88203A18(s32 arg0, void *arg1) {
    u32 var_v1;
    u8 temp_v0;
    s32 var_a2;

    temp_v0 = *(u8 *)((u8 *)arg1 + 1);
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_a2 = *(s32 *)((u8 *)arg1 + 4);
        do {
            if (arg0 == var_a2) {
                return var_v1 & 0xFF;
            }
            var_v1 += 1;
            var_a2 += 0x76;
        } while (var_v1 < temp_v0);
    }
    return var_v1 & 0xFF;
}
/* mkdraft:func_88203A18 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1768F0/func_88203A58.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1768F0/func_88203BE4.s")

// Same 12-byte layout as LabPCStorageList in
//@src/fragments/31/fragment31_1736F0.c
void func_88203A58(u8 *);

void func_88203ED8(u8 *entry, s32 list) {
    LabPCStorageList *storage = &D_88234630[list];

    if (storage->count != storage->capacity) {
        ((unk_func_88203ED8 *)storage->entries)[storage->count] = *(unk_func_88203ED8 *)entry;
        storage->count++;
        storage->changed = 1;
        func_88203A58(entry);
    }
}

extern u8 D_88A01C40[];
u8 func_88203FB4(void) {
    u8 count = 0;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (D_88A01C40[i] == 0) {
            count++;
        }
    }
    return count;
}

s32 func_88204050(void) {
    s32 var_v1;
    u8 *var_v0;

    var_v0 = D_88A01C40;
    var_v1 = 0;
loop_1:
    if (*var_v0 != 0) {
        var_v1 += 1;
        var_v0 += 1;
        if (var_v1 != 0x1E) {
            goto loop_1;
        }
    }
    return var_v1 & 0xFF;
}

extern u8 D_88006868[];
extern s32 D_88234670[];
void func_88204080(void *arg0) {
    s32 var_s4;
    s32 var_s6;
    s32 var_s0;
    s32 var_s1;

    var_s4 = func_8005CB38(*(s8 *)D_88006868, 33);
    var_s6 = func_800532C4(17);
    D_88234670[0] = mem_pool_alloc(arg0, var_s4 << 2);
    D_88234670[1] = mem_pool_alloc(arg0, var_s6 << 2);
    var_s1 = 0;
    if (var_s4 != 0) {
        do {
            *(void **)(D_88234670[0] + (var_s1 * 4)) =
                mem_pool_alloc(arg0, 9);
            func_8005EE88(*(s8 *)D_88006868, var_s1,
                         *(void **)(D_88234670[0] + (var_s1 * 4)));
            var_s1++;
        } while (var_s1 != var_s4);
    }
    var_s1 = 0;
    if (var_s6 != 0) {
        do {
            *(void **)(D_88234670[1] + (var_s1 * 4)) =
                mem_pool_alloc(arg0, 18);
            func_80053524(var_s1, *(void **)(D_88234670[1] + (var_s1 * 4)));
            var_s1++;
        } while (var_s1 != var_s6);
    }
}
#endif
