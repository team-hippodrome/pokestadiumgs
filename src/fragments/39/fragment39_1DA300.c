#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA300/func_88A00020.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/39/fragment39_1DA300/func_88A00248.s")

/* mkdraft:func_88A0057C begin */
extern s32 D_88A01C30;
extern s8 D_88006868;
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_WriteEntries(u8 *, s32, u8 *);
extern s32 func_8006229C(u8 *);
extern void GbSave_SetSeenOwnedBits(s32, s32, u16, s32);



void func_88A0057C(void) {
    u32 i;
    u8 *record;
    u8 **table;
    u8 **subtable;
    u8 *handle;
    u32 j;
    u32 k;

    for (i = 0, record = (u8 *)D_88A01C30; i != 3; i++) {
        table = (u8 **)*(u32 *)(record + 0xC);
        for (j = 0; j < record[0x10]; j++) {
            if (*(s32 *)((u8 *)table[0] + 0xC) != 0) {
                handle = func_8006218C(*(s32 *)record, *(s32 *)(record + 4), j, 1);
                if (handle != NULL) {
                    subtable = *(u8 ***)((u8 *)table[0] + 0x10);
                    for (k = 0; k < ((u8 *)table[0])[0x15]; k++) {
                        Deck_WriteEntries((u8 *)*subtable + 8, 1, handle);
                        if ((*(s32 *)record == 0x20 || *(s32 *)record == 0x21) &&
                            (*subtable)[8] > 0 && (*subtable)[8] < 0xFC &&
                            !((*subtable)[0x26] & 1)) {
                            GbSave_SetSeenOwnedBits(D_88006868, (*subtable)[8], *(u16 *)(*subtable + 0x1E), 3);
                        }
                        subtable++;
                    }
                    func_8006229C(handle);
                }
                *(s32 *)((u8 *)table[0] + 0xC) = 0;
            }
            table++;
        }
        record += 0x14;
    }
}
/* mkdraft:func_88A0057C end */
#endif
