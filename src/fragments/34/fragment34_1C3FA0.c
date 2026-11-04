#include "global.h"
#include "controller.h"

#ifdef VERSION_US
/* Runtime menu allocated by func_88507FA8 (48 bytes). */
typedef struct F34ConfirmMenu {
    void *windows[6];
    s32 mode;
    s8 selection;
    s16 timer;
    s32 transition;
    s16 values[5];
} F34ConfirmMenu;

typedef struct MenuResult {
    s32 state;
    s32 unk_04;
    s32 unk_08;
} MenuResult;

extern void Util_Free(s32);
extern s32 D_880068B4;
extern F34ConfirmMenu *D_88523010;

void func_88506990(void) {
    D_880068B4 = 1;
    Util_Free((s32)D_88523010);
}

extern void func_800226C0(s32);
extern void func_8850A0A0(s32, s32, s32, s32);
void func_885069C0(void) {
    if ((*(s32 *)((u8 *)(D_88523010) + (0x18))) != 0) {
        func_8850A0A0(0, 0x11F, 0x280, 0x65);
        func_800226C0(0x14D);
        return;
    }
    func_8850A0A0(0x28, 0x14, 0x230, 0x100);
}

extern void func_88004990(s32,s32);
void func_88506A20(void){func_8850A0A0(0,0,0x280,0x1E0);func_88004990(0,0);func_88004990(1,0);func_88004990(2,0);if(*(s32 *)((u8 *)D_88523010+0x18)!=0)func_88004990(3,0);func_88004990(4,0);func_88004990(5,0);}

extern s8 D_8800EF41;
extern u8 D_8850D6D8;
extern s8 D_8800EF40;
void func_88506AA8(void) {
    s16 temp_v1;
    s8 *var_a0;

    D_8800EF40 = (s8) (*(s16 *)((u8 *)(D_88523010) + (0x2C)));
    if ((*(s16 *)((u8 *)(D_88523010) + (0x2C))) != -1) {
        temp_v1 = (*(s16 *)((u8 *)(D_88523010) + (0x24)));
        if (temp_v1 < 2) {
            var_a0 = (temp_v1 * 0xA960) + &D_8850D6D8;
        } else {
            var_a0 = ((*(s16 *)((u8 *)(D_88523010) + (0x26))) * 0xA960) + &D_8850D6D8;
        }
        D_8800EF41 = *var_a0;
    }
}

/* mkdraft:func_88506B2C begin */
extern F34ConfirmMenu *D_88523010;
extern u8 D_8850D6D8;
extern u8 D_8850D678[];
extern s8 D_88518CC1;

extern u8 *func_88500CF0(u8);
extern s32 fragment29_main(u8);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_WriteEntries(u8 *, s32, u8 *);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 func_80062304(u8 *);
extern void _bzero(void *, s32);
extern s32 func_80063754(s32);
extern s32 func_80058FD0(s32);
extern s32 func_80059468(s32);
extern s32 func_8005B078(s32);
extern s32 func_8005B058(s32);
extern void GbSave_RequirePakPresent(s32);
extern void func_8005ADD8(s32);
extern void func_8005B140(s32);
extern void GbSave_SetSeenOwnedBits(s32, s32, u16, s32);



s32 func_88506B2C(void) {
    /* 0x76-byte deck record (halfword aligned) */
    typedef struct {
        u16 data[0x3B];
    } DeckRecord;

    typedef struct {
        u8 count;
        u8 pad0C8D[3];
        u8 data[0xA70];
    } Row;
    typedef struct {
        u8 pad0000[0xC88];
        s8 itemIndex;
        s8 rowIndex;
        u8 pad0C8A[2];
        Row rows[2];
    } State;

    s32 i;
    s32 result;
    /* Unused; declaring it keeps the frame at 0x770 and the local slots' offsets. */
    u8 *base;
    u8 *handle;
    u8 *ptr;
    u8 *entries[2];
    s32 ctx[2];
    DeckRecord deckbuf[2][6];
    DeckRecord *selected[2];
    DeckRecord empty[2];
    DeckRecord tmp;

    result = 0;
    if (*(s32 *)((u8 *)D_88523010 + 0x20) != 0) {
        *(s32 *)((u8 *)D_88523010 + 0x20) = 0;
        for (i = 0; i < 2; i++) {
            entries[i] = func_88500CF0(i);
            ctx[i] = fragment29_main(
                D_8850D678[*(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960) * 20 + 1]);
            if (*(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960 + 0xC89) == 0) {
                handle = func_8006218C(
                    0x20, *(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960), 0, 1);
            } else {
                handle = func_8006218C(
                    0x21, *(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960),
                    *(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960 + 0xC89) - 1, 1);
            }
            if ((entries[i][0x1E] & 1) == 0) {
                GbSave_SetSeenOwnedBits(
                    *(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960), entries[i][0],
                    *(u16 *)(entries[i] + 0x16), 3);
                GbSave_SetSeenOwnedBits(
                    *(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960),
                    *(u8 *)((u8 *)&D_8850D6D8 + i * 0xA960 + 0xA958),
                    *(u16 *)(entries[i] + 0x16), 3);
            }
            Deck_WriteEntries(
                ((State *)((u8 *)&D_8850D6D8 + i * 0xA960))
                    ->rows[((State *)((u8 *)&D_8850D6D8 + i * 0xA960))->rowIndex].data,
                ((State *)((u8 *)&D_8850D6D8 + i * 0xA960))
                    ->rows[((State *)((u8 *)&D_8850D6D8 + i * 0xA960))->rowIndex].count,
                handle);
            func_80062304(handle);
        }
        if ((ctx[0] == 0 || ctx[1] == 0) &&
            (*(s8 *)((u8 *)&D_8850D6D8 + 0xC89) == 0 || !D_88518CC1) &&
            (func_80063754(entries[0][1]) != 0 ||
             func_80063754(entries[1][1]) != 0)) {
            for (i = 0; i < 2; i++) {
                _bzero(&empty[i], 0x76);
                if (ctx[i] == 0) {
                    handle = func_8006218C(
                        0x25, ((s8 *)&D_8850D6D8)[i * 0xA960], 0, 0);
                    if (handle != 0) {
                        Deck_ReadEntries((u8 *)deckbuf[i], 6, handle);
                        func_80062304(handle);
                    }
                }
                if (ctx[i] == 0 &&
                    *(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960 + 0xC89) == 0) {
                    selected[i] =
                        &deckbuf[i][*(s8 *)((u8 *)&D_8850D6D8 + i * 0xA960 + 0xC88)];
                } else {
                    selected[i] = &empty[i];
                }
            }
            tmp = *selected[0];
            *selected[0] = *selected[1];
            *selected[1] = tmp;
            for (i = 0; i != 2; i++) {
                if (ctx[i] == 0) {
                    handle = func_8006218C(
                        0x25, ((s8 *)&D_8850D6D8)[i * 0xA960], 0, 1);
                    if (handle != 0) {
                        Deck_WriteEntries((u8 *)deckbuf[i], 6, handle);
                        func_80062304(handle);
                    }
                }
            }
        }
        for (i = 0; i != 2; i++) {
            func_8005B140(((s8 *)&D_8850D6D8)[i * 0xA960]);
        }
    }
    if (*(s16 *)((u8 *)D_88523010 + 0x24) < 2) {
        for (i = 0; i != 2; i++) {
            if (i < *(s16 *)((u8 *)D_88523010 + 0x24)) {
                continue;
            }
            if (func_80058FD0(((s8 *)&D_8850D6D8)[i * 0xA960]) != 0) {
                *(s16 *)((u8 *)D_88523010 + 0x24) += 1;
            } else {
                break;
            }
        }
    }
    if (*(s16 *)((u8 *)D_88523010 + 0x24) < 2) {
        return 0;
    }
    for (i = 0; i != 2; i++) {
        if (i < *(s16 *)((u8 *)D_88523010 + 0x26)) {
            continue;
        }
        handle = (u8 *)(s32)(((s8 *)&D_8850D6D8)[i * 0xA960]);
        ptr = (u8 *)func_80059468((s32)handle);
        if (ptr != 0) {
            ptr = (u8 *)func_8005B078((s32)handle);
            if (ptr != 0) {
                ptr = (u8 *)func_8005B058((s32)handle);
            }
        }
        if (ptr != 0) {
            *(s16 *)((u8 *)D_88523010 + 0x26) += 1;
            GbSave_RequirePakPresent(
                ((s8 *)&D_8850D6D8)[i * 0xA960]);
            func_8005ADD8(((s8 *)&D_8850D6D8)[i * 0xA960]);
        } else {
            break;
        }
    }
    if (*(s16 *)((u8 *)D_88523010 + 0x26) == 2) {
        result = 1;
    }
    return result;
}
/* mkdraft:func_88506B2C end */

/* mkdraft:func_8850716C begin */
extern MenuResult D_88523018;

s32 func_8005A228(s8);
s32 func_88506B2C();



void func_8850716C(void) {
    s16 temp_v1;
    s32 temp_v0;

    *(s16 *)((u8 *)(D_88523010) + (0x1E)) = (s16) (*(s16 *)((u8 *)(D_88523010) + (0x1E)) - 1);
    if (*(s16 *)((u8 *)(D_88523010) + (0x1E)) <= 0) {
        *(s16 *)((u8 *)(D_88523010) + (0x1E)) = 0;
        if (*(s16 *)((u8 *)(D_88523010) + (0x28)) == 1) {
            temp_v0 = func_8005A228(*(s8 *)((u8 *)&D_8850D6D8 + (*(s16 *)((u8 *)(D_88523010) + (0x26)) * 0xA960)));
            if (temp_v0 == 1) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 1;
            }
            if (temp_v0 == 3) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 3;
            }
            if (temp_v0 == 2) {
                *(s16 *)((u8 *)(D_88523010) + (0x28)) = 2;
                *(s16 *)((u8 *)(D_88523010) + (0x2A)) = 3;
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 0;
            }
        }
        if (*(s16 *)((u8 *)(D_88523010) + (0x28)) == 2) {
            *(s16 *)((u8 *)(D_88523010) + (0x2A)) = (s16) (*(s16 *)((u8 *)(D_88523010) + (0x2A)) - 1);
            temp_v1 = *(s16 *)((u8 *)(D_88523010) + (0x2A));
            if (temp_v1 == 1) {
                if (*(s8 *)((u8 *)(D_88523010) + (0x1C)) == 0) {
                    func_800226C0(0x14A);
                } else {
                    func_800226C0(0x14B);
                }
            } else if (temp_v1 <= 0) {
                *(s16 *)((u8 *)(D_88523010) + (0x28)) = 0;
                *(s16 *)((u8 *)(D_88523010) + (0x2A)) = 0;
            }
        }
        if (*(s16 *)((u8 *)(D_88523010) + (0x28)) == 0) {
            if (func_88506B2C() != 0) {
                D_88523018.state = 0;
                func_88506A20();
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = -1;
                func_800226C0(0x11);
                return;
            }
            *(s16 *)((u8 *)(D_88523010) + (0x28)) = 1;
            func_800226C0(5);
            *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 2;
            temp_v0 = func_8005A228(*(s8 *)((u8 *)&D_8850D6D8 + (*(s16 *)((u8 *)(D_88523010) + (0x26)) * 0xA960)));
            if (temp_v0 == 1) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 1;
                return;
            }
            if (temp_v0 == 3) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 3;
            }
        }
    }
}
/* mkdraft:func_8850716C end */

/* mkdraft:func_88507370 begin */
extern MenuResult D_88523018;
#ifndef M2C_FIELD /* mkdraft: m2c --valid-syntax helpers */
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

// FAKE: REWRITE_FUNCTION_HEX + RELOC_TARGET rotate 56 words (offsets 0x100..0x1DC)
// FAKE: without them this C body scores 520 on the differ (as1 delay-slot placement
// FAKE: of the D_88523018 store: retail has la before beql, C gives la inside the block).


void func_88507370(void) {
    s32 var_a3;
    s32 temp_a1;
    s32 var_a1;
    s8 temp_t0;
    s8 temp_v0;
    s8 var_v0;
    u16 temp_a0;
    var_a3 = 0;
    if (M2C_FIELD(D_88523010->windows[2], s32 *, 0x20) == 2) {
        temp_a0 = D_80087200->buttonsPressed;
        if (temp_a0 & 0x8000) {
            var_a3 = 1;
        } else {
            temp_a1 = D_88523010->mode;
            if ((temp_a1 == 0) && (temp_a0 & 0x4000)) {
                var_a3 = 1;
                D_88523010->selection = 1;
            } else {
                var_v0 = D_88523010->selection;
                temp_t0 = var_v0;
                if (temp_a1 != 0) {
                    var_a1 = 3;
                } else {
                    var_a1 = 2;
                }
                if (temp_a0 & 0x800) {
                    if (var_v0 > 0) {
                        D_88523010->selection = (s8) (var_v0 - 1);
                        var_v0 = D_88523010->selection;
                    }
                } else if ((temp_a0 & 0x400) && (var_v0 < (var_a1 - 1))) {
                    D_88523010->selection = (s8) (var_v0 + 1);
                    var_v0 = D_88523010->selection;
                }
                if (temp_t0 != var_v0) {
                    var_a3 = 0;
                    func_800226C0(1);
                }
            }
        }
        if (var_a3 != 0) {
            if (D_88523010->mode != 0) {
                temp_v0 = D_88523010->selection;
                if (temp_v0 == 2) {
                    func_800226C0(0x14);
                    D_88523018.unk_08 = 0;
                    D_88523018.state = 0;
                    func_88506A20();
                } else {
                    if (temp_v0 == 0) {
                        func_800226C0(0x14A);
                        D_88523018.unk_08 = 0;
                    } else {
                        func_800226C0(0x14B);
                        D_88523018.unk_08 = 1;
                    }
                    D_88523018.state = 3;
                    D_88523010->timer = 2;
                    D_88523010->transition = 1;
                    D_88523010->values[0] = 0;
                    D_88523010->values[1] = 0;
                    D_88523010->values[2] = 0;
                    D_88523010->values[3] = 0;
                    D_88523010->values[4] = -1;
                }
            } else {
                D_88523018.state = 0;
                if (D_88523010->selection == 0) {
                    func_800226C0(0x14C);
                    D_88523018.unk_04 = 1;
                } else {
                    func_800226C0(3);
                    D_88523018.unk_04 = 0;
                }
                func_88506A20();
            }
        }
    }
}
/* mkdraft:func_88507370 end */

extern s32 func_8004C874(s32, s32);
extern s32 func_88002958(s32 *, s32, s32, s32);
// Returns the selected resource address as a 32-bit word.
//@src/4CC20.c
extern s32 func_8004C990(s32, s32);
extern void func_880048D4(s32, s32, s16, s16, s32, s32, u8, u8, u8,
                           s32 *, s32 *, s32 *, s32 *, u8, u8, s32);
extern void D_88000E4C(void);
extern s32 D_8800EDE8;
extern MenuResult D_88523018;
void func_885075A8(void) {
    s8 pad;
    s32 sp68[3];
    s32 var_s1;
    s32 var_s0;

    var_s0 = 0;
    *(s16 *)((u8 *)D_88523010 + 0x1E) = *(s16 *)((u8 *)D_88523010 + 0x1E) - 1;
    var_s1 = (s32)sp68;
    if (D_80087200->buttonsPressed & 0x8000) {
        *(s16 *)((u8 *)D_88523010 + 0x1E) = 0;
    }
    if (*(s16 *)((u8 *)D_88523010 + 0x1E) <= 0) {
        for (; var_s0 != 3; var_s0 += 1, var_s1 += 4) {
            *(s32 *)var_s1 = func_8004C874(0x34, var_s0 + 0x14);
        }
        var_s1 = func_88002958(sp68, 3, 8, 1) & 0xFFFF;
        var_s0 = ((s32)*(u16 *)((u8 *)func_8004C990(0x79, 0)) + var_s1 + 0x35) & 0xFFFF;
        func_880048D4(0, 3, 0x13F - (var_s0 >> 1), 0x11F, 0, 1, 0xE6, 0xFF, 0xF0,
                      (s32 *)D_88000E4C, (s32 *)D_88000E4C, (s32 *)D_88000E4C, (s32 *)D_88000E4C, 0, 0, 2);
        *(s32 *)((u8 *)D_88523010 + 8) = (s32)&D_8800EDE8;
        *(s16 *)((u8 *)(*(s32 *)((u8 *)D_88523010 + 8)) + 0x10) = (s16)var_s0;
        *(s16 *)((u8 *)(*(s32 *)((u8 *)D_88523010 + 8)) + 0x12) = 0x65;
        D_88523018.state = 1;
    }
}

extern void func_88506AA8();
extern void func_8850716C();
extern void func_88507370();
extern void func_885075A8();
extern MenuResult D_88523018;
void func_88507724(void) {
    switch (D_88523018.state) {                           /* irregular */
    case 0:
        break;
    case 1:
        func_88507370();
        break;
    case 2:
        func_885075A8();
        break;
    case 3:
        func_8850716C();
        break;
    }
    func_88506AA8();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C3FA0/func_8850779C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C3FA0/func_88507FA8.s")
#endif
