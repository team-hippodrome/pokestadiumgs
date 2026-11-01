#include "global.h"


#ifdef VERSION_US
extern void Util_Free(s32);
extern void func_888002DC(void);
extern void main_pool_pop_state(s32);
extern void func_8821CE40(s32);
extern s32 D_88234560;
extern s32 D_88234564;

typedef struct {
    u8 unk_00[0x10];
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x18];
} unk_D_88234700_Record;

typedef struct {
    u8 index; // selects the entry of records read by func_88208FF0
    u8 unk_01[7];
    unk_D_88234700_Record records[2];
} unk_D_88234700;

extern unk_D_88234700 *D_88234700;

void func_88207ED0(void) {
    Util_Free(D_88234564);
    func_888002DC();
    main_pool_pop_state(0x4152524D);
    func_8821CE40(1);
    D_88234560 = 5;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88207F18.s")

extern u8 *func_88201ED0(u8, u8);
extern s32 func_80001FF0(void);
extern void func_88001C6C(void *, u16, u8, s16, u8, s16, s16, s16, s16, s16, s32);
void func_88208010(u8 arg0, u8 arg1, u8 arg2) {
    s16 color;

    if (*(s32 *)((u8 *)D_88234700 + 4) != 0) {
        color = 0xC;
    } else {
        color = 0xF0C;
    }
    ((u8 *)D_88234700)[arg0 * 2 + 0xA] = arg1;
    ((u8 *)D_88234700)[arg0 * 2 + 0xB] = arg2;
    func_88001C6C(D_88234700->records[arg0].unk_00 + 8, func_88201ED0(((u8 *)D_88234700)[arg0 * 2 + 0xA], ((u8 *)D_88234700)[arg0 * 2 + 0xB])[0x15], 6, 0x7D, 27, 14,
                  (s32)(600.0f / func_80001FF0() + ((600.0f / func_80001FF0() > 0.0f) ? 0.5f : -0.5f)),
                  32, 32, color, 70);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88208174.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_882089E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88208B38.s")

// 8-byte record allocated by func_88208FF0 and published through D_8800EF54.
typedef struct {
    s32 unk_00; // func_88207F18(1, index) result
    s8 delta;   // records[index].unk_10 - records[index].unk_12
    u8 index;
} unk_func_88208FF0;

extern void *Util_Malloc(s32);
extern void func_800226C0(s32);
extern s32 func_88207F18(s32, s32);
extern void func_882322B8(void);
extern void *D_8800EF54;
void func_88208FF0(void) {
    unk_func_88208FF0 *record;

    record = Util_Malloc(sizeof(unk_func_88208FF0));
    record->unk_00 = func_88207F18(1, D_88234700->index);
    record->delta = D_88234700->records[D_88234700->index].unk_10 - D_88234700->records[D_88234700->index].unk_12;
    record->index = D_88234700->index;
    D_8800EF54 = record;
    func_800226C0(99);
    func_882322B8();
}

/* mkdraft:func_8820908C begin */
extern u8 *func_88201ED0(u8, u8);
extern s32 func_88207F18(s32, s32);
extern void func_800226C0(s32);
extern void func_88001900(void);
extern void func_88001C24(u8 *, u8, s32);
extern void func_88001D0C(u8 *);
extern void func_88201608(s32);
extern void func_882017F8(s32, u8 *, s8);
extern void func_88220AD0(s32, s32);
extern s32 D_88234660;
extern s32 D_882346F0;

// Per-round update of the two-slot state in D_88234700; the s16 at +8 selects the
// branch. Case 2 runs the state-2-only setup (actor from func_88207F18 for the
// other slot, per-slot word clear, index flip) and falls into the shared record
// refresh; case 5 reaches the same refresh after refreshing the actor only; case 4
// just flips the active slot.


void func_8820908C(void) {
    u8 *pair;
    s32 obj; // func_88207F18 result; func_882017F8 dereferences it as a pointer

    if (*(s16 *)((u8 *)D_88234700 + 8) == 5) {
        func_800226C0(0x136);
    } else {
        func_800226C0(0x5E);
    }
    func_88001900();
    D_882346F0 = 0;
    // Read a second time instead of caching the first load in a local: no store to
    // D_88234700 lies between the two reads of +8, so both see the same value.
    switch (*(s16 *)((u8 *)D_88234700 + 8)) {
        case 2:
        case 5:
            if (*(s16 *)((u8 *)D_88234700 + 8) == 2) {
                obj = func_88207F18(1, (1 - D_88234700->index) & 0xFF);
                pair = (u8 *)D_88234700 + D_88234700->index * 2;
                func_882017F8(obj, func_88201ED0(pair[0xA], pair[0xB]),
                              *(s8 *)((u8 *)D_88234700 + D_88234700->index * 0x2C + 0x19));
                // Per-index word at +0x6C, also read by func_8820B09C.
                *(s32 *)((u8 *)D_88234700 + D_88234700->index * 4 + 0x6C) = 0;
                D_88234700->index ^= 1;
            } else {
                func_88201608(func_88207F18(1, D_88234700->index));
            }
            pair = (u8 *)D_88234700 + D_88234700->index * 2;
            func_88001C24((u8 *)D_88234700 + D_88234700->index * 0x2C + 0x10,
                          func_88201ED0(pair[0xA], pair[0xB])[0x15], 6);
            func_88001D0C((u8 *)D_88234700 + D_88234700->index * 0x2C + 0x10);
            break;

        case 4:
            D_88234700->index ^= 1;
            break;
    }
    if (D_88234660 != 0) {
        *((u8 *)D_88234700 + 0x68) = 2;
        func_88220AD0(0x140, 0xF0);
    }
}
/* mkdraft:func_8820908C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88209278.s")

/* mkdraft:func_8820A56C begin */
extern s32 D_882346F0;
extern unk_D_88234700 *D_88234700;

// Mode-dependent test of whether arg1 matches the progress recorded for slot
// arg0. Modes 1 and 3 use records[arg0].unk_10 minus unk_12 and apply to slots
// other than the selected index; mode 2 uses the halfword at 0x74 minus unk_12
// and applies to the selected index. func_88209278 compares that same 0x74
// halfword against records[index].unk_10.


s32 func_8820A56C(u8 arg0, u8 arg1) {
    u32 index = arg0;
    unk_D_88234700 *state;
    s32 result = 0;

    switch (D_882346F0) {
    default:
        break;
    case 0:
        break;
    case 1:
    case 3:
        state = D_88234700;
        if (arg0 == state->index) {
            break;
        }
        if (arg1 == state->records[index].unk_10 - state->records[index].unk_12) {
            result = 1;
        }
        break;
    case 2:
        state = D_88234700;
        if (arg0 != state->index) {
            break;
        }
        if ((s16)arg1 == *(s16 *)((u8 *)state + 0x74) - state->records[index].unk_12) {
            result = 1;
        }
        break;
    }
    return result;
}
/* mkdraft:func_8820A56C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820A638.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820AAD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820ACD0.s")

extern u8 *func_88201ED0(u8, u8);
extern void func_8004D5B8(s32, s32, s32, const char *, ...);
void func_8820AF54(void) {
    s32 i;
    u8 *entry;
    u8 *first;
    u8 *second;
    s16 x;

    for (i = 0, x = 262; i != 4; i += 2, x += 297) {
        entry = (u8 *)D_88234700 + i;
        first = func_88201ED0(entry[10], entry[11]);
        entry = (u8 *)D_88234700 + i;
        second = func_88201ED0(entry[10], entry[11]);
        func_8004D5B8(x, 287, 2, "%d/%d", first[0x15], second[0x14]);
    }
}

extern void func_80049064(s32, s32, s32, s32);
extern void func_800496A4(s32, s32);
s32 func_8004C874(s32, s32);
extern unk_D_88234700 *D_88234700;

void func_8820B020(void) {
    func_800496A4(4, 2);
    func_80049064(0x140, 0x198, 1, func_8004C874(0x20, 7));
    func_800496A4(0x10, 2);
    func_80049064(0x140, 0x15F, 1, func_8004C874(0x20, (*(s16 *)((u8 *)(D_88234700) + (8))) + 1));
}

extern s16 D_8800EF58;
extern u8 *func_88201ED0(u8, u8);
s32 func_8820B09C(void) {
    s32 result = 0;
    u8 *entry;

    if ((*(s32 *)((u8 *)D_88234700 + 4) == 0) && (D_8800EF58 == 0) &&
        (*(s32 *)((u8 *)D_88234700 + D_88234700->index * 4 + 0x6C) == 0)) {
        entry = func_88201ED0(((u8 *)D_88234700)[D_88234700->index * 2 + 0xA], ((u8 *)D_88234700)[D_88234700->index * 2 + 0xB]);
        if (entry[0x15] != 0) {
            result = 1;
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820B124.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820B6C8.s")
#endif
