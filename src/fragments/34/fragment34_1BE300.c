#include "global.h"


#ifdef VERSION_US
extern u8 D_8850D6D8;
u8 *func_88500CF0(u8 arg0) {
    typedef struct {
        u8 data[0x58];
    } Item;
    typedef struct {
        Item items[30];
        u8 padA50[0x24];
    } Row;
    typedef struct {
        u8 pad0000[0xC88];
        s8 itemIndex;
        s8 rowIndex;
        u8 pad0C8A[6];
        Row rows[1];
    } State;
    State *state;

    state = (State *)((arg0 * 0xA960) + &D_8850D6D8);
    return (u8 *)&state->rows[state->rowIndex].items[state->itemIndex];
}

extern u8 *D_8850D6D0;
extern u8 *func_8004D878(u8 *dst, s32 id, u8 *src);

// Row arg0 of the current group (byte 0x0A of *D_8850D6D0) holds a count byte followed by
// 0x58-byte entries. Each entry is passed to func_8004D878 with a destination that starts at
// the buffer selected by byte 0x11 (word table at +0x14) and advances 0xC80 per entry; byte
// 0x11 is then toggled to select the other buffer.
void func_88500D60(s8 arg0) {
    u8 *group;
    u8 *entry;
    u8 *dst;
    s32 i;

    i = 0x0A; // FAKE: index through a variable; diff score 40 without it.
    group = D_8850D6D0[i] * 0xA960 + arg0 * 0xA74 + 0xC8C + &D_8850D6D8;
    do {} while (0); // FAKE: diff score 40 without it.
    entry = group + 4;
    dst = ((u8 **)(D_8850D6D0 + 0x14))[D_8850D6D0[0x11]];
    for (i = 0; i < group[0]; i++) {
        func_8004D878(dst, entry[0], entry);
        dst += 0xC80;
        entry += 0x58;
    }
    D_8850D6D0[0x11] ^= 1;
}

extern u8 *D_8850D6D0;
s8 func_88500E4C(void) {
    typedef struct {
        u8 pad2F[0x2F];
        u8 count;
        s8 index;
        u8 pad31;
    } State;
    State *state;
    s8 index;
    s8 result;

    state = (State *)D_8850D6D0;
    index = state->index;
    if (index >= state->count) {
        result = 0;
    } else {
        result = *((s8 *)state + index + 0x32);
    }
    return result;
}

extern void func_88004990(u8, s32);
extern s32 D_880068B8;
void func_88500E80(void) {
    *(s32 *)(*(u8 **)((u8 *)D_8850D6D0 + 0) + 0x34) = 1;
    *(s32 *)(*(u8 **)((u8 *)D_8850D6D0 + 4) + 0x34) = 1;
    func_88004990(**(u8 **)((u8 *)D_8850D6D0 + 0), 0);
    func_88004990(**(u8 **)((u8 *)D_8850D6D0 + 4), 0);
    D_880068B8 = 1;
}

extern u8 *D_8850D6D0;
void func_88500EF4(void) {
    *(s32 *)(*(u8 **)((u8 *)D_8850D6D0 + 4) + 0x30) = 0;
}

extern s32 func_80001FF0(void);
extern void func_880002F4(u8 *, s16);
extern u8 * D_8850D6D0;
void func_88500F08(void) {
    *(s32 *)(*(u8 **)((u8 *)D_8850D6D0 + 4) + 0x30) = 1;
    func_880002F4(D_8850D6D0 + 0x74, (s32)(13.0f * func_80001FF0() / 60.0f + ((func_80001FF0() * 13.0f / 60.0f > 0.0f) ? 0.5f : -0.5f)) + (s32)(10.0f * func_80001FF0() / 60.0f + ((func_80001FF0() * 10.0f / 60.0f > 0.0f) ? 0.5f : -0.5f)) + (s32)(5.0f * func_80001FF0() / 60.0f + ((func_80001FF0() * 5.0f / 60.0f > 0.0f) ? 0.5f : -0.5f)));
}

extern void func_8000612C(void);
extern s32 D_88804058;
extern void func_88500E80(void);
void func_885010EC(void) {
    typedef struct {
        s32 words[0x320];
    } CopyRecord;
    typedef struct {
        u8 pad00[0x10];
        u8 index;
        u8 pad11[3];
        u8 *records[1];
    } MainState;
    u8 *state;

    state = (D_8850D6D0[0xA] * 0xA960) + &D_8850D6D8;
    func_8000612C();
    *(s32 *)(*(u8 **)(D_8850D6D0 + 4) + 0x2C) = 1;
    *(s32 *)(D_8850D6D0 + 0x64) = 1;
    if (D_88804058 != 0) {
        state[1] = 1;
        *(CopyRecord *)(state + 8) = *(CopyRecord *)((*(s8 *)(state + 0xC88) * 0xC80) + ((MainState *)D_8850D6D0)->records[((MainState *)D_8850D6D0)->index]);
        func_88500E80();
    } else {
        state[1] = 0;
    }
}

typedef struct unk_func_885011EC {
    u8 unk_00[44];
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
} unk_func_885011EC;

typedef struct unk_D_8850D6D0 {
    void* unk_00;
    unk_func_885011EC* unk_04;
    u8 unk_08;
    u8 unk_09[91];
    s32 unk_64;
} unk_D_8850D6D0;

extern void func_88500F08(void);
extern s32 func_88802DCC(s32 arg0, u8* arg1, void (*arg2)(void), void (*arg3)(void),
                        void (*arg4)(void), void* arg5, u8 arg6, u8 arg7);

void func_885011EC(u8* arg0) {
    func_88802DCC(3, arg0, func_88500EF4, func_885010EC, func_88500F08, NULL, 0, 2);
    ((unk_D_8850D6D0*)D_8850D6D0)->unk_04->unk_2C = 0;
    ((unk_D_8850D6D0*)D_8850D6D0)->unk_04->unk_34 = 1;
    ((unk_D_8850D6D0*)D_8850D6D0)->unk_08 = 2;
    ((unk_D_8850D6D0*)D_8850D6D0)->unk_64 = 0;
}

#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
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

s32 func_8004C874(M2C_UNK, s16);                    /* extern */
M2C_UNK func_88903C50(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, u8 *, M2C_UNK *, void (*)()); /* extern */
extern M2C_UNK D_88000E4C;

void func_88501274(s16 arg0) {
    func_88903C50(func_8004C874(0x34, arg0), 0x141, 0x108, 4, 0xFF, 0xAA, 0x8C, 0, 2, M2C_FIELD(D_8850D6D0, s32 *, 4) + 0x2C, D_8850D6D0 + 0x88, &D_88000E4C, func_8000612C);
}
s32 func_8850130C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 result = 0;
    s32 index = 0;

    if (*arg0 == 252) {
        result = 1;
    } else {
        do {
            if (arg0[index + 2] == 0) {
                if (index == 0) {
                    result = 1;
                }
                break;
            }
            if (arg0[index + 2] == 165 || arg0[index + 2] >= 252) {
                result = 1;
                break;
            }
            index++;
        } while (index != 4);
    }
    return result;
}

extern s8 D_8850E361;
extern s8 D_88518CC1;
extern u8 D_8850D6D8;
extern u8 D_8850E368;
extern void _bcopy(void *, void *, s32);
u8 *func_88500CF0(u8 arg0);

typedef struct {
    u32 pad00[7];
    u16 pad1C;
    u8 flags;
    u8 pad1F[7];
    u16 kind;
    u8 pad28[0x30];
} Record;



s32 func_88501380(void) {
    s32 result = 0;
    u32 i;
    u32 j;
    u8 counts[2];
    Record blocks[2][6];

    if (D_8850E361 == 0 || D_88518CC1 == 0) {
        for (i = 0; i < 2; i++) {
            counts[i] = ((u8 *)&D_8850D6D8)[i * 0xA960 + 0xC8C];
            _bcopy((u8 *)&D_8850E368 + i * 0xA960, blocks[i],
                   counts[i] * sizeof(Record));
        }
        for (i = 0; i < 2; i++) {
            if (((s8 *)&D_8850D6D8)[i * 0xA960 + 0xC89] == 0) {
                blocks[i][((s8 *)&D_8850D6D8)[i * 0xA960 + 0xC88]] =
                    *(Record *)func_88500CF0(1 - i);
            }
        }
        for (i = 0; i != 2; i++) {
            Record *rec;
            if (!result) {
                if (counts[i] == 0) {
                    result = 1;
                }
                rec = blocks[i];
                j = 0;
                for (; j < counts[i]; j++, rec++) {
                    if (!(rec->flags & 1) && rec->kind != 0) {
                        break;
                    }
                }
                if (j == counts[i]) {
                    result = 1;
                }
            }
        }
    }
    return result;
}

extern u8 D_8850D679[];
extern s32 D_88804054;
extern u8 *D_8850D6D0;
extern u8 D_8850D6D8;
extern u8 *D_80087200;
extern s8 D_8850E361;
extern s32 fragment29_main(u8);
extern s32 func_80063754(s32);
extern void func_800226C0(s32, ...);
extern void func_88500E80(void);
extern s8 func_88500E4C(void);
extern u8 *func_88500CF0(u8);
extern s32 func_8850130C(u8 *, s32, s32);
extern void func_885011EC(u8 *);
extern void func_88501274(s16);
extern void func_88500D60(s8);
extern s32 func_88501380(void);
extern void func_88002640(u8 *, u8 **);
extern void func_880002F4(u8 *, s16);


void func_88501570(void) {
    s8 old30;
    s16 old56;
    u8 *state;
    u8 id;
    s32 ready;
    s16 next;
    s16 old[3];
    // Row is 0x58-byte items at 0x0, State selects one with rowIndex/itemIndex at 0xC88/0xC89;
    // same layout as the Item/Row/State typedefs in func_88500CF0.
    typedef struct {
        u8 data[0x58];
    } Item;
    typedef struct {
        Item items[30];
        u8 padA50[0x24];
    } Row;
    typedef struct {
        u8 pad0000[0xC88];
        s8 itemIndex;
        s8 rowIndex;
        u8 pad0C8A[6];
        Row rows[1];
    } State;
    if ((D_8850D6D0[8] != 0) || (D_8850D6D0[9] != 0)) {
        if (D_8850D6D0[8] != 0) {
            D_8850D6D0[8] -= 1;
            if (D_8850D6D0[8] == 0) {
                *((s32 *) ((*((u8 **) (D_8850D6D0 + 4))) + 0x34)) = 0;
            }
        }
        if (D_8850D6D0[9] != 0) {
            D_8850D6D0[9] -= 1;
            if (D_8850D6D0[9] == 0) {
                *((s32 *) ((*((u8 **) (D_8850D6D0 + 0))) + 0x34)) = 0;
            }
        }
    } else {
        old30 = *((s8 *) (D_8850D6D0 + 0x30));
        old56 = *((s16 *) (D_8850D6D0 + 0x56));
        state = (D_8850D6D0[0xA] * 0xA960) + (&D_8850D6D8);
        // FAKE: D_8850D6D0 tested against itself; no side effect, the dead branch only changes
        // register allocation (diff score 60 without it).
        if (D_8850D6D0 && D_8850D6D0) {
        }
        id = D_8850D679[(*((s8 *) state)) * 0x14];
        ready = (D_88804054 == 0) && (fragment29_main(id) == 0);
        if ((*((s16 *) (D_8850D6D0 + 0x56))) == 0) {
            if ((*((u16 *) (D_80087200 + 8))) & 0x4000) {
                func_800226C0(3, &D_80087200, &D_8850D6D0, state);
                func_88500E80();
            } else if ((*((u16 *) (D_80087200 + 8))) & 0x8000) {
                *((s8 *) (state + 0xC88)) = ((*((s16 *) (D_8850D6D0 + 0xE))) * 6) + (*((s16 *) (D_8850D6D0 + 0xC)));
                // FAKE: comma expression ((0, 0x31)) in place of the addend 0x31 (diff score 10
                // without it).
                *((s8 *) (state + 0xC89)) = *((s8 *) ((D_8850D6D0 + (*((s8 *) (D_8850D6D0 + 0x30)))) + ((0, 0x31))));
                // FAKE: comma expression ((0, 0xC8C)) in place of the addend 0xC8C (diff score 10
                // without it).
                if ((*((s8 *) (state + 0xC88))) >= ((s32) (*((u8 *) ((state + ((*((s8 *) (state + 0xC89))) * 0xA74)) + ((0, 0xC8C))))))) {
                    func_800226C0(5, &D_80087200, &D_8850D6D0, state);
                } else {
                    next = -1;
                    if (func_8850130C(func_88500CF0(D_8850D6D0[0xA]), *((s8 *) (state + 0xC89)), id) != 0) {
                        next = 0x1D;
                    } else if ((((D_8850D6D0[0xA] == 1) && (ready != 0)) && (D_8850E361 != 0)) && (func_80063754(func_88500CF0(1)[1]) != 0)) {
                        next = 0x1B;
                    } else if ((D_8850D6D0[0xA] == 1) && (func_88501380() != 0)) {
                        next = 0x1C;
                    } else {
                        func_800226C0(0x90);
                        func_885011EC((u8 *) &((State *) state)->rows[(*((s8 *) (state + 0xC89)))].items[(*((s8 *) (state + 0xC88)))]);
                    }
                    if (next != (-1)) {
                        func_88501274(next);
                    }
                }
            } else {
                old[0] = *((s16 *) (D_8850D6D0 + 0xC));
                old[1] = *((s16 *) (D_8850D6D0 + 0xE));
                if ((*((u16 *) (D_80087200 + 0xC))) & 0x800) {
                    *((s16 *) (D_8850D6D0 + 0xE)) -= 1;
                    if ((*((s16 *) (D_8850D6D0 + 0xE))) < 0) {
                        *((s16 *) (D_8850D6D0 + 0xE)) = 4;
                    }
                } else if ((*((u16 *) (D_80087200 + 0xC))) & 0x400) {
                    *((s16 *) (D_8850D6D0 + 0xE)) += 1;
                    if ((*((s16 *) (D_8850D6D0 + 0xE))) >= 5) {
                        *((s16 *) (D_8850D6D0 + 0xE)) = 0;
                    }
                }
                if ((*((u16 *) (D_80087200 + 0xC))) & 0x200) {
                    *((s16 *) (D_8850D6D0 + 0xC)) -= 1;
                    if ((*((s16 *) (D_8850D6D0 + 0xC))) < 0) {
                        *((s16 *) (D_8850D6D0 + 0xC)) = 5;
                    }
                } else if ((*((u16 *) (D_80087200 + 0xC))) & 0x100) {
                    *((s16 *) (D_8850D6D0 + 0xC)) += 1;
                    if ((*((s16 *) (D_8850D6D0 + 0xC))) >= 6) {
                        *((s16 *) (D_8850D6D0 + 0xC)) = 0;
                    }
                }
                if ((old[0] != (*((s16 *) (D_8850D6D0 + 0xC)))) || (old[1] != (*((s16 *) (D_8850D6D0 + 0xE))))) {
                    func_800226C0(1, &D_80087200, &D_8850D6D0, state);
                }
            }
        }
        if (((*((s16 *) (D_8850D6D0 + 0x56))) != 0) || (!((*((u16 *) (D_80087200 + 8))) & 0xC000))) {
            if (((*((u8 *) (D_8850D6D0 + 0x2F))) == 0) || ((*((s32 *) (D_8850D6D0 + 0x84))) == 0)) {
                if ((*((u16 *) (D_80087200 + 8))) & 0x30) {
                    func_800226C0(5, &D_80087200);
                }
            } else {
                func_88002640(D_8850D6D0 + 0x40, &D_80087200);
                if ((old56 == 0) && ((*((s16 *) (D_8850D6D0 + 0x56))) != 0)) {
                    if ((*((s16 *) (D_8850D6D0 + 0x44))) != 0x10) {
                        // FAKE: D_8850E361 tested twice in one condition; dead branch (diff score 15
                        // without it).
                        if ((!D_8850E361) && (!D_8850E361)) {
                        }
                        if ((*((s16 *) (D_8850D6D0 + 0x44))) == 0x20) {
                            // FAKE: comma expression ((0, 0x31)) in place of the addend 0x31 (diff
                            // score 10 without it).
                            func_88500D60(*((s8 *) ((D_8850D6D0 + (*((s8 *) (D_8850D6D0 + 0x30)))) + ((0, 0x31)))));
                        }
                    } else {
                        func_88500D60(func_88500E4C());
                    }
                } else if ((old56 != 0) && ((*((s16 *) (D_8850D6D0 + 0x56))) == 0)) {
                    func_880002F4(D_8850D6D0 + 0x74, 0);
                }
                if (old30 != (*((s8 *) (D_8850D6D0 + 0x30)))) {
                    D_8850D6D0[0x10] ^= 1;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1BE300/func_88501AE8.s")

extern u8 D_8850D679[];
extern s32 D_88804054;
extern s32 func_88504E94(u8);
extern s32 fragment29_main(u8);
extern s32 func_80063754(s32);
extern s32 func_8004C990(s32, s32);
extern void func_80047738(s32, s32, s32, s32);

// Picks the value passed to func_88501274: 26 after clearing the word at
// D_8850D6D0 + 0x84, or 25 after passing a value mapped from the byte
// D_8850D679[func_88504E94(1 - D_8850D6D0[0xA]) * 20] to func_8004C990 and
// func_80047738; otherwise calls func_8000612C. Always clears D_880068B8.
void func_88503644(void) {
    s16 next = -1;
    u8 id = D_8850D679[func_88504E94(D_8850D6D0[0xA]) * 20];
    s32 ready = (D_88804054 == 0);
    s32 param;

    if (ready) {
        ready = (fragment29_main(id) == 0);
    }
    if (D_8850D6D0[0xA] == 1 && ready && func_80063754(func_88500CF0(0)[1])) {
        *(s32 *)(D_8850D6D0 + 0x84) = 0;
        next = 26;
    } else if (D_88804054 != 0 && fragment29_main(id) == 0) {
        switch (D_8850D679[func_88504E94(1 - D_8850D6D0[0xA]) * 20]) {
            case 1:
                param = 5;
                break;
            case 2:
                param = 4;
                break;
            case 3:
                param = 1;
                break;
            case 4:
                param = 7;
                break;
            case 5:
                param = 3;
                break;
            case 6:
                param = 6;
                break;
            default:
                param = 2;
                break;
        }
        func_80047738(0, func_8004C990(56, param), 0, 0);
        next = 25;
    } else {
        func_8000612C();
    }
    if (next != -1) {
        func_88501274(next);
    }
    D_880068B8 = 0;
}

extern s32 D_880068B4;
extern void Util_Free(u8 *);
extern void func_888002DC(void);
extern void main_pool_pop_state(s32);
void func_885037EC(void) {
    D_880068B4 = 1;
    Util_Free(D_8850D6D0);
    func_888002DC();
    main_pool_pop_state(0x50495550);
}

typedef struct {
    u8 unk_00;
    u8 type;
    u8 unk_02[18];
} Fragment34Entry;
typedef struct {
    u8 data[0x4C];
} Fragment34Node;
extern Fragment34Entry D_8850D678[];
extern Fragment34Node D_8800ED50[];
extern void main_pool_push_state(s32);
extern void func_88800020(void);
extern void *Util_Malloc(s32);
extern s32 GbSave_GetRecordCapacity(s32);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void *MainPool_AllocAligned(s32, s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 func_8004C8C0(s32);
extern s32 func_8003514C(void);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern u8 Deck_ReadEntries(u8 *, s32, u8 *);
extern void func_8005EE88(s32, s32, u8 *);
extern void func_80062304(u8 *);
extern void HAL_Strcpy(u8 *, s32);
extern s32 func_80001FF0(void);
extern void func_880024FC(u8 *, u8 *, u8, s32, s32, s32, s32, s32, s32);
extern u8 *func_88000578(u8 *, u8);
extern s32 func_88004804(s32, s32, s16, s32, s32, s32, s32, s32, s32, u8 *, u8 *, u8 *, u8 *, s32, s32);
extern void func_88000288(u8 *, s16, s32, s32, s32, s32, s32, s32);
extern void func_88501570(void);
extern void func_88501AE8(void);
extern void func_88503644(void);

/* Converts a duration in 60 Hz frames to func_80001FF0's frame rate, rounding to nearest. */
#define FRAMES_AT_60HZ(n) \
    ((s32)((f32)(n) * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)(n) / 60.0f > 0.0f) ? 0.5f : -0.5f)))
#define STATE_S16(offset) (*(s16 *)(D_8850D6D0 + (offset)))

/* Allocates the 0xA4-byte state at D_8850D6D0 for slot arg0. Reads the arg1 deck records (group 0
   and D_8850D6D0[0x2E] more) into the slot's 0xA960-byte block at D_8850D6D8, then creates the two
   0x4C-byte D_8800ED50 nodes stored at D_8850D6D0[0] and [4]. */
void func_88503830(u8 arg0, s8 arg1) {
    s32 poolState;
    u8 *group;
    s32 i;
    u8 *record;
    s32 node;
    u8 capacity;
    s32 unused; // FAKE: unused, reserves the stack slot between capacity and color.
    u8 color[4];

    main_pool_push_state(0x50495550);
    func_88800020();
    D_8850D6D0 = Util_Malloc(0xA4);
    D_8850D6D0[0xA] = arg0;
    D_8850D6D0[0x2C] = GbSave_GetRecordCapacity(33);
    poolState = MainPool_AllocState(main_pool_get_available(), 0);
    *(void **)(D_8850D6D0 + 0x14) = MainPool_AllocAligned(poolState, D_8850D6D0[0x2C] * 3200, 8);
    *(void **)(D_8850D6D0 + 0x18) = MainPool_AllocAligned(poolState, D_8850D6D0[0x2C] * 3200, 8);
    MainPool_FinalizeAllocation(poolState);
    func_8004C8C0(154);
    *(void **)(D_8850D6D0 + 0x1C) = (void *)func_8004C990(154, 0);
    func_8004C8C0(241);
    *(void **)(D_8850D6D0 + 0x20) = (void *)func_8004C990(241, 0);
    func_8004C8C0(243);
    *(void **)(D_8850D6D0 + 0x24) = (void *)func_8004C990(243, 0);
    func_8004C8C0(252);
    *(void **)(D_8850D6D0 + 0x28) = (void *)func_8004C990(252, 0);
    if (func_8003514C() == 0) {
        D_8850D6D0[0x2D] = 9;
        STATE_S16(0x8C) = 269;
        STATE_S16(0x8E) = 442;
        STATE_S16(0x90) = 135;
        STATE_S16(0x92) = 47;
        STATE_S16(0x94) = 142;
        STATE_S16(0x96) = 143;
        STATE_S16(0x98) = 445;
        STATE_S16(0x9A) = 129;
        STATE_S16(0x9C) = 365;
        STATE_S16(0x9E) = 150;
        STATE_S16(0xA0) = 99;
        STATE_S16(0xA2) = 509;
        switch (D_8850D678[arg1].type) {
            case 1:
            case 2:
            case 3:
            case 4:
                D_8850D6D0[0x2E] = 8;
                break;
            default:
                D_8850D6D0[0x2E] = 9;
                break;
        }
    } else {
        D_8850D6D0[0x2D] = 14;
        STATE_S16(0x8C) = 365;
        STATE_S16(0x8E) = 491;
        STATE_S16(0x90) = 86;
        STATE_S16(0x92) = 23;
        STATE_S16(0x94) = 118;
        STATE_S16(0x96) = 119;
        STATE_S16(0x98) = 494;
        STATE_S16(0x9A) = 80;
        STATE_S16(0x9C) = 461;
        STATE_S16(0x9E) = 126;
        STATE_S16(0xA0) = 87;
        STATE_S16(0xA2) = 534;
        D_8850D6D0[0x2E] = 14;
    }
    group = &D_8850D6D8 + arg0 * 0xA960;
    group[0] = arg1;
    group[1] = 0;
    group[0xC88] = 0;
    group[0xC89] = 0;
    D_8850D6D0[0x31] = 0;
    D_8850D6D0[0x2F] = 0;
    group += 0xC8C;
    for (i = 0; i < D_8850D6D0[0x2E] + 1; i++) {
        if (i == 0) {
            record = func_8006218C(32, arg1, 0, 0);
            capacity = GbSave_GetRecordCapacity(32);
        } else {
            record = func_8006218C(33, arg1, i - 1, 0);
        }
        if (record != NULL) {
            group[0] = Deck_ReadEntries(group + 4, capacity, record);
            if (i != 0 && group[0] != 0) {
                D_8850D6D0[0x2F]++;
                D_8850D6D0[D_8850D6D0[0x2F] + 0x31] = i;
                func_8005EE88(arg1, i - 1, group + 0xA54);
            }
            func_80062304(record);
        }
        if (i == 0) {
            capacity = GbSave_GetRecordCapacity(33);
            HAL_Strcpy(group + 0xA54, func_8004C874(52, 1));
        }
        group += 0xA74;
    }
    D_8850D6D0[0x30] = 0;
    func_880024FC(D_8850D6D0 + 0x40, D_8850D6D0 + 0x30, (u8)(D_8850D6D0[0x2F] + 1), 527,
                  (s32)(1980.0f / func_80001FF0() + ((1980.0f / func_80001FF0() > 0.0f) ? 0.5f : -0.5f)), 0, 48,
                  0, 10);
    D_8850D6D0[0x10] = 0;
    D_8850D6D0[0x11] = 0;
    func_88500D60(0);
    func_88000578(color, D_8850D678[arg1].type);
    // FAKE: the u32 conversion keeps arg0 from being shared with the group address computation.
    node = func_88004804(0, 3, (s16)((u32)arg0 * 273 + 51), 32, 0, 1, color[0], color[1], color[2],
                         (u8 *)&D_88000E4C, (u8 *)&D_88000E4C, (u8 *)&D_88000E4C, (u8 *)&D_88000E4C, 0, 0);
    *(u8 **)D_8850D6D0 = (u8 *)&D_8800ED50[node];
    *(s16 *)(*(u8 **)D_8850D6D0 + 0x10) = 267;
    *(s16 *)(*(u8 **)D_8850D6D0 + 0x12) = 45;
    node = func_88004804(0, 3, 51, 73, 0, 2, 230, 0xFF, 240, (u8 *)func_88501570, (u8 *)func_88501AE8,
                         (u8 *)func_88503644, (u8 *)func_885037EC, 0, 1);
    *(u8 **)(D_8850D6D0 + 4) = (u8 *)&D_8800ED50[node];
    *(s16 *)(*(u8 **)(D_8850D6D0 + 4) + 0x10) = 540;
    *(s16 *)(*(u8 **)(D_8850D6D0 + 4) + 0x12) = 382;
    D_8850D6D0[8] = 2;
    D_8850D6D0[9] = 2;
    STATE_S16(0xE) = 0;
    STATE_S16(0xC) = STATE_S16(0xE);
    *(s32 *)(D_8850D6D0 + 0x64) = 1;
    func_88000288(D_8850D6D0 + 0x68, FRAMES_AT_60HZ(5) + FRAMES_AT_60HZ(8) + FRAMES_AT_60HZ(30), 0xFF, 0,
                  FRAMES_AT_60HZ(5), FRAMES_AT_60HZ(8), FRAMES_AT_60HZ(30), FRAMES_AT_60HZ(8));
    func_88000288(D_8850D6D0 + 0x74, 0, 0xFF, 0, FRAMES_AT_60HZ(13), FRAMES_AT_60HZ(10), FRAMES_AT_60HZ(5),
                  FRAMES_AT_60HZ(7));
    i = D_88804054 != 0;
    if (i) {
        i = fragment29_main(D_8850D678[arg1].type) == 0;
    }
    *(s32 *)(D_8850D6D0 + 0x80) = i;
    *(s32 *)(D_8850D6D0 + 0x84) = 1;
    D_880068B4 = 0;
}

#undef FRAMES_AT_60HZ
#undef STATE_S16
#endif
