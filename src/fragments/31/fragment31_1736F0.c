#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_88200470 begin */
extern u8 D_882345E0;

// Sets one bit of the eight-bit D_882345E0 mask. arg0 selects a bit pair:
// 1/2, 4/8, 0x10/0x20 or 0x40/0x80; arg1 == 0 and arg1 == 1 set the lower bit
// of the pair and every other arg1 value sets the upper. Any other arg0 leaves
// the mask unchanged. Each inner switch is written out because the compare
// forms compile to a different branch sequence.



void func_88200470(s32 arg0, u8 arg1) {
    switch (arg0) {
        case 1:
            switch (arg1) {
                case 0:
                case 1:
                    D_882345E0 |= 1;
                    break;

                default:
                    D_882345E0 |= 2;
                    break;
            }
            return;

        case 2:
            switch (arg1) {
                case 0:
                case 1:
                    D_882345E0 |= 4;
                    break;

                default:
                    D_882345E0 |= 8;
                    break;
            }
            return;

        case 4:
            switch (arg1) {
                case 0:
                case 1:
                    D_882345E0 |= 0x10;
                    break;

                default:
                    D_882345E0 |= 0x20;
                    break;
            }
            return;

        case 8:
            switch (arg1) {
                case 0:
                case 1:
                    D_882345E0 |= 0x40;
                    break;

                default:
                    D_882345E0 |= 0x80;
                    break;
            }
            return;
    }
}
/* mkdraft:func_88200470 end */

extern s32 func_8005370C(s32, s32);
extern s32 func_8005CF20(s32, s32, s32);

s32 func_88200598(s32 arg0, s32 arg1, s32 arg2) {
    s32 result = 0;

    switch (arg0) {
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
            result = func_8005CF20(arg0, arg1, arg2);
            break;
        case 16:
        case 17:
        case 18:
        case 22:
        case 23:
            result = func_8005370C(arg0, arg2);
            break;
    }

    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1736F0/func_882005F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1736F0/func_882007B0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1736F0/func_882009D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1736F0/func_88200BC4.s")

/* mkdraft:func_88200D04 begin */
extern s32 func_882005F8(void);
extern s32 func_882007B0(void);
extern s32 func_882009D4(void);
extern s32 func_88200BC4(void);
extern u8 D_882345E0;



s32 func_88200D04(u8 arg0) {
    s32 ret = 0;

    D_882345E0 = 0;
    if (arg0 & 1) {
        if (func_882005F8() != 0) {
            ret = 1;
        }
    }
    if (arg0 & 2) {
        if (func_882007B0() != 0) {
            ret = 1;
        }
    }
    if (arg0 & 4) {
        if (func_882009D4() != 0) {
            ret = 1;
        }
    }
    if (arg0 & 8) {
        if (func_88200BC4() != 0) {
            ret = 1;
        }
    }
    return ret;
}
/* mkdraft:func_88200D04 end */

// Same 12-byte layout as LabPCStorageList in
//@src/fragments/31/fragment31_1A5E10.c
typedef struct LabPCStorageList {
    u8 count;
    u8 capacity;
    void *entries;
    s32 changed;
} LabPCStorageList;

extern s8 D_88006868;
extern s32 D_88233760[];
extern LabPCStorageList D_88234630[];
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_WriteEntries(void *, s32, u8 *);
extern s32 func_8006229C(u8 *);

// Writes each of the four D_88234630 lists whose changed flag is set back to its
// deck: func_8006218C opens deck type D_88233760[i] (lists 0 and 1 on port
// D_88006868, lists 2 and 3 on port 0), Deck_WriteEntries stores `count` entries
// and func_8006229C commits the deck if it was modified and frees the handle.
//@src/615D0.c
void func_88200DCC(void) {
    s32 pad[2]; // FAKE: unused 8 bytes of stack; diff score 10 without it.
    u32 i;
    s32 port;
    u8 *deck;
    LabPCStorageList *list;

    for (i = 0; i < 4; i++) {
        list = &D_88234630[i];
        if (list->changed != 0) {
            switch (i) {
                case 0:
                case 1:
                    port = D_88006868;
                    break;

                case 2:
                case 3:
                    port = 0;
                    break;
            }

            deck = func_8006218C(D_88233760[i], port, 0, 1);
            if (deck != NULL) {
                Deck_WriteEntries(list->entries, list->count, deck);
                func_8006229C(deck);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1736F0/func_88200EDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1736F0/func_88201048.s")
#endif
