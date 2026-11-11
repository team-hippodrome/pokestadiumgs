#include "global.h"


#ifdef VERSION_US
extern s8 D_88006868;
extern u8 *D_88601890;
extern u8 D_88601896;
extern void func_8005E6B8(s32);
extern s32 func_8005E728(s32, s32);
extern u8 func_80063804(u8);
extern s32 func_886000F0(u16);
extern s32 func_8800005C(void);
extern s32 func_8005ECA4(s32), func_8005ED78(s32), func_8005EE4C(s32);
extern void _bzero(void *, s32);
extern s32 GbSave_GetUnownDexEntry(s32, u8);
extern s32 main_pool_push_state(s32), main_pool_pop_state(s32);
extern s32 mem_pool_try_init(s32, s32);
extern void *mem_pool_alloc(void *, s32);
extern s32 GbSave_GetRecordCapacity(s32);
extern s32 func_8005CB38(s32, s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern void func_80062304(u8 *);
extern u8 func_80064520(u16);
// Build species flags and Unown form flags for D_88601890. Saved dex entries
// mark forms with 2; species-201 records in the selector-32/33 archives mark 3.
void func_88308080(void) {
    u32 i;
    s32 form;
    u8 *record;
    void *pool;
    u8 *records;
    u8 *handle;
    s32 first_capacity;
    s32 box_capacity;
    u32 boxes;
    u32 total;
    s32 capacity;
    s32 count;

    func_8005E6B8(D_88006868);
    for (i = 0; i < 251; i++) {
        D_88601890[628 + i] = func_8005E728(D_88006868, i + 1);
    }
    for (i = 1; i < 252; i++) {
        if (func_886000F0(func_80063804(i)) != 0) {
            D_88601890[905] = i;
        }
        if (func_886000F0(i) != 0) {
            D_88601890[906] = i;
        }
    }
    if (func_8800005C() != 0) {
        D_88601896 = D_88601890[906];
    } else {
        D_88601896 = D_88601890[905];
    }
    D_88601890[907] = func_8005ECA4(D_88006868);
    D_88601890[908] = func_8005ED78(D_88006868);
    D_88601890[909] = func_8005EE4C(D_88006868);
    _bzero(D_88601890 + 879, 26);
    D_88601890[911] = 0;
    D_88601890[910] = D_88601890[911];
    if (func_8800005C() == 0) {
        for (i = 0; i < 26; i++) {
            form = GbSave_GetUnownDexEntry(D_88006868, i);
            if (form == 0) {
                break;
            }
            D_88601890[878 + (u8)form] = 2;
        }
        D_88601890[910] = i;
        main_pool_push_state(0x554E4B4E);
        pool = (void *)mem_pool_try_init(0x8000, 0);
        first_capacity = GbSave_GetRecordCapacity(32);
        box_capacity = GbSave_GetRecordCapacity(33);
        boxes = func_8005CB38(D_88006868, 33);
        total = 0;
        records = mem_pool_alloc(pool, (boxes * box_capacity + first_capacity) * 88);
        for (i = 0, record = records; i < boxes + 1; i++) {
            if (i == 0) {
                handle = func_8006218C(32, D_88006868, 0, 0);
                capacity = first_capacity;
            } else {
                handle = func_8006218C(33, D_88006868, i - 1, 0);
                capacity = box_capacity;
            }
            if (handle != NULL) {
                count = Deck_ReadEntries(record, capacity, handle);
                total += count;
                record += count * 88;
                func_80062304(handle);
            }
        }
        for (i = 0, record = records; i != total; i++, record += 88) {
            if (record[0] == 201) {
                D_88601890[878 + func_80064520(*(u16 *)(record + 22))] = 3;
            }
        }
        for (i = 0; i != 26; i++) {
            if ((D_88601890 + 879)[i] == 3) {
                D_88601890[911]++;
            }
        }
        main_pool_pop_state(0x554E4B4E);
    }
}

extern u16 **D_88601898;
extern s32 func_886000F0(u16);
u8 func_883083C8(u8 *arg0) {
    s32 at_first;
    s32 count;
    s32 i;

    if (*(s16 *)(arg0 + 8) == 0) {
        at_first = 1;
    } else {
        at_first = 0;
    }
    if (at_first) {
        return 0;
    }
    count = 1;
    i = *(s16 *)(arg0 + 8) - 1;
    while (TRUE) {
        if (func_886000F0(*D_88601898[i])) {
            return count;
        }
        if (i == 0) {
            return 0;
        }
        count++;
        i--;
    }
}

/* mkdraft:func_88308464 begin */
extern s32 func_886000F0(u16);



u8 func_88308464(const u8 *arg0) {
    s32 at_last;
    s32 count;
    s32 i;

    do {
        if (*(u16 *)(arg0 + 12) == *(s16 *)(arg0 + 8) + 1) {
            at_last = 1;
        } else {
            at_last = 0;
        }
        if (at_last) {
            return 0;
        }
        i = *(s16 *)(arg0 + 8);
        i++;
        count = 1; while (TRUE) {
            if (func_886000F0(*D_88601898[i])) {
                return count;
            }
            if (i == *(u16 *)(arg0 + 12) - 1) {
                return 0;
            }
            i++;
            count++;
        }
    } while (0);
}
/* mkdraft:func_88308464 end */
#endif
