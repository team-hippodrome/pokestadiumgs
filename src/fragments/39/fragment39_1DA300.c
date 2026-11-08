#include "global.h"


#ifdef VERSION_US
#include "global.h"

extern u8 D_88A01C40[];
extern void _bzero(void *, s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 func_8006229C(u8 *);
extern void *func_8004B7A4(s32);
extern s32 func_80053230(s32);



u16 func_88A00020(void *arg0, void *arg1, void *arg2, u8 arg3)
{
    u32 i;
    u32 j;
    u32 k;
    u8 *q;
    u8 *rec;
    u8 *p;
    u8 **entries;
    u8 *mp;
    u16 count;
    u8 *handle;

    count = 0;
    _bzero(D_88A01C40, 0x1E);
    i = 0;
    p = (u8 *)arg0;
    q = (u8 *)arg1;
    rec = (u8 *)arg2;
    for (; i < arg3; i++, p += 0x14) {
        for (j = 0; j < p[0x10]; j++, q += 0x18) {
            handle = func_8006218C(*(s32 *)p, *(s32 *)(p + 4), j, 0);
            if (handle != NULL) {
                entries = *(u8 ***)(q + 0x10);
                q[0x15] = 0;
                do {
                    _bzero(rec + 8, 0x58);
                    if (Deck_ReadEntries(rec + 8, 1, handle) == 0) {
                        break;
                    }
                    k = 0;
                    if (rec[0x27]) {
                        if (i != 2 || rec[0x27] <= 0 || func_80053230(0x17) < rec[0x27] || D_88A01C40[rec[0x27] - 1] != 0) {
                            rec[0x27] = 0;
                        } else {
                            D_88A01C40[rec[0x27] - 1] = 1;
                        }
                    }
                    mp = rec + 0xA;
                    for (; k != 4; k++, mp++) {
                        if (*mp == 0) {
                            break;
                        }
                        if (*mp == 0xA5 || *mp >= 0xFC) {
                            func_8004B7A4(rec[8]);
                            *mp = 0xFC;
                        }
                    }
                    *(u8 **)rec = q;
                    rec[4] = q[0x15];
                    q[0x15] = q[0x15] + 1;
                    *entries++ = rec;
                    count++;
                    rec += 0x60;
                } while (1);
                func_8006229C(handle);
            }
        }
    }
    return count;
}

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
