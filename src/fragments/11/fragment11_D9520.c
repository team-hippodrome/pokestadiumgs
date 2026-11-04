#include "global.h"


#ifdef VERSION_US
s32 func_81601980(s32 *arg0, s32 arg1) {
    return arg0[arg1 / 32] & (1 << (arg1 % 32));
}

void func_816019C0(s32 *arg0, s32 arg1, s32 arg2)
{
    s32 mask;
    s32 value;
    ;
    arg0[arg1 / 32] = (arg0[arg1 / 32] & (~mask)) | ((arg2) ? (mask = 1 << (arg1 % 32)) : ((mask = 1 << (arg1 % 32), 0)));
}

void func_81601A38(s32 *arg0, s32 arg1) {
    s32 value;
    s32 i;
    value = arg1 ? -1 : 0;
    for (i = 0; i < 8; i++) {
        arg0[i] = value;
    }
}

void func_81601A78(s32 arg0, s32 arg1) { func_816019C0(arg0, 0xAD, arg1); func_816019C0(arg0, 0x4F, arg1); func_816019C0(arg0, 0x4E, arg1); func_816019C0(arg0, 0x50, arg1); func_816019C0(arg0, 0x54, arg1); func_816019C0(arg0, 0x53, arg1); }


/* mkdraft:func_81601B00 begin */
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 GbSave_GetPortAvailability(s32);
extern s32 func_8005CB38(s32, s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 func_80062304(u8 *);

typedef struct { u8 unk_00[0x01]; u8 unk_01; u8 unk_02[0x5E]; } GbBoxEntry;
typedef struct { u8 data[0x90]; } GbPartyRecord;
typedef struct { u8 data[0x10]; } GbPairRecord;



void func_81601B00(s32 arg0, s32 arg1, s32 arg2) {
    GbBoxEntry box;
    u8 *handle;
    s32 port;
    s32 deck;
    s32 slot;
    u8 *handle2;
    s32 index;
    GbPartyRecord party;
    GbPairRecord pair;
    u8 *mon;

    if (arg1 < 0 || arg1 >= 4 || GbSave_GetPortAvailability(arg1)) {
        return;
    }
    port = 0;
    if (func_8005CB38(arg1, 0x21) >= 0) {
        do {
            deck = (port == 0) ? 0x20 : 0x21;
            slot = (port > 0) ? port - 1 : 0;
            if (arg1 >= 0 && arg1 < 4) {
                handle = func_8006218C(deck, arg1, slot, 0);
                if (handle != 0) {
                    if (Deck_ReadEntries((u8 *)&box, 1, handle) != 0) {
                        do {
                            if (box.unk_01) {
                                func_816019C0(arg0, box.unk_01, arg2);
                            }
                        } while (Deck_ReadEntries((u8 *)&box, 1, handle) != 0);
                    }
                    func_80062304(handle);
                }
            }
            port++;
        } while (func_8005CB38(arg1, 0x21) >= port);
    }
    if (arg1 >= 0 && arg1 < 4) {
        handle2 = func_8006218C(0x23, arg1, 0, 0);
        if (handle2 != 0) {
            if (Deck_ReadEntries((u8 *)&party, 1, handle2) != 0) {
                for (index = 0; index < party.data[0x39]; index++) {
                    mon = party.data + 0x3A + index * 2;
                    if (mon[0] > 0 && mon[1] > 0) {
                        func_816019C0(arg0, mon[0], arg2);
                    }
                }
                func_80062304(handle2);
            }
        }
    }
    if (arg1 >= 0 && arg1 < 4) {
        handle = func_8006218C(0x22, arg1, 0, 0);
        if (handle != 0) {
            if (Deck_ReadEntries((u8 *)&pair, 1, handle) != 0) {
                if (pair.data[0] > 0 && pair.data[1] > 0) {
                    func_816019C0(arg0, pair.data[0], arg2);
                }
            }
            func_80062304(handle);
        }
    }
}
/* mkdraft:func_81601B00 end */

void func_81601D24(s32 arg0, s32 arg1) {
    if (arg1 != 0x19) func_816019C0(arg0, 0xA3, 1);
    if (arg1 != 0x71) func_816019C0(arg0, 0x1E, 1);
    if (arg1 != 0x53) func_816019C0(arg0, 0x69, 1);
    if (arg1 != 0x84) func_816019C0(arg0, 0x23, 1);
    if ((arg1 != 0x68) && (arg1 != 0x69)) func_816019C0(arg0, 0x76, 1);
}

s32 func_81601DE8(u8 arg0, u8 arg1) { if ((arg1 == 0x19) && (arg0 == 0xA3)) return 1; if ((arg1 == 0x71) && (arg0 == 0x1E)) return 1; if ((arg1 == 0x68) && (arg0 == 0x76)) return 1; if ((arg1 == 0x69) && (arg0 == 0x76)) return 1; if ((arg1 == 0x53) && (arg0 == 0x69)) return 1; if ((arg1 == 0x84) && (arg0 == 0x23)) return 1; return 0; }

extern s32 func_81601FA0(u8);
s32 func_81601EAC(u8 arg0, u8 arg1)
{
    s32 value;
    u8 new_var;
    value = func_81601FA0((u8)arg0);
    new_var = (u8)value;
    if (value < 5) {
        return new_var != 0;
    }
    if ((arg1 == (u8)0x19) && (arg0 == (u8)0xA3)) return 1;
    if ((arg1 == (u8)0x71) && (arg0 == (u8)0x1E)) return 1;
    if ((arg1 == (u8)0x68) && (arg0 == (u8)0x76)) return 1;
    if ((arg1 == (u8)0x69) && (arg0 == (u8)0x76)) return 1 & 0xFFFFFFFFFFFFFFFFu;
    if ((arg1 == (u8)0x53) && (arg0 == (u8)0x69)) return 1;
    if ((arg1 == (u8)0x84) && (arg0 == (u8)0x23)) return 1;
    return 0;
}

extern s32 func_80063660(u8);
s32 func_81601FA0(u8 arg0) {
    s32 type;

    switch (arg0) {
        case 146:
        case 152:
            return 3;
        case 30:
        case 35:
        case 105:
        case 118:
        case 163:
            return 5;
        case 78:
        case 79:
        case 80:
        case 83:
        case 84:
        case 173:
            return 1;
        case 91:
        case 94:
        case 106:
            return 0;
    }
    type = func_80063660(arg0);
    if (type == 0) {
        return 0;
    }
    if ((u8)type >= 50 && (u8)type < 67) {
        return 4;
    }
    if ((u8)type < 17) {
        return 2;
    }
    return 3;
}

extern s32 func_8004C874(s32, s32);
s32 *func_816020BC(u8 arg0) {
    s32 *result;
    s32 *temp_v0;

    result = (s32 *)"";
    if (arg0 > 0) {
        temp_v0 = (s32 *)func_8004C874(9, arg0 - 1);
        if (temp_v0 != NULL) {
            result = temp_v0;
        }
    }
    return result;
}

extern u8 D_8160BD30[];
void *func_81602108(s32 arg0) { s32 index = arg0 & 0xFF; s32 *p = &arg0; *p = arg0; if (index >= 6) index = 0; return &D_8160BD30[index * 3]; }

/* Collects into arg0's list: entry 0 is a 0 terminator, then every ID 1..0xFE
 * whose bit is set in the arg1 bitset (func_81601980), grouped so IDs whose
 * func_81601FA0 value equals the outer counter (1..5) come out in pass order;
 * the entry count lands in the u16 at arg0+0x40. func_816021E8 scans this list. */
void func_81602134(u8 *arg0, s32 *arg1) {
    s32 i;
    s32 j;
    s32 value;
    s32 count;

    arg0[0] = 0;
    count = 1;
    for (j = 1; j != 6; j++) {
        for (i = 1; i != 0xFF; i++) {
            if (func_81601980(arg1, i) == 0) {
                continue;
            }
            value = func_81601FA0(i);
            if (j == value) {
                arg0[count] = i;
                count++;
            }
        }
    }
    *(u16 *)(arg0 + 0x40) = count;
}

s32 func_816021E8(u8 *arg0, u8 arg1) {
    s32 i;
    if (arg1 == 0) {
        return 0;
    }
    for (i = 0; i < *(u16 *)(arg0 + 0x40); i++) {
        if (arg0[i] == arg1) {
            return i;
        }
    }
    return 0;
}
#endif
