#include "global.h"


#ifdef VERSION_US
extern u8 D_88B05BE0[];
s32 func_88B04380(u8 arg0) {
    // FAKE: the whole body must stay on one source line; split over lines (same tokens) it does not match (diff score 60)
    struct unk_D_88B05BE0 { u16 pad; u16 value; }; struct unk_D_88B05BE0 *p = (struct unk_D_88B05BE0 *)D_88B05BE0; s32 result = 0; while (result < 34) { if (arg0 == p->value) break; result++; p++; } return result & 0xFF;
}

extern u8 D_88B05BE3[];
extern s32 *func_800635E0(u8);
void func_88B043B8(u8 arg0) {
    func_800635E0(D_88B05BE3[arg0 * 4]);
}

extern u8 D_88B05CF8[];
extern void *func_8004C874(s32, s32);
void *func_88B043EC(u8 arg0) {
    return func_8004C874(0x3C, D_88B05CF8[arg0]);
}

void *func_88B04420(u16 arg0) {
    u16 selector = arg0;
    s32 value = selector;

    if (selector >= 0x100) {
        return func_88B043EC(value - 0x100);
    } else {
        return func_800635E0(selector);
    }
}

extern u8 D_88B05BE0[];
s32 func_88B04468(void) {
    u8 *ptr = D_88B05BE0;
    s32 i = 0;
    s32 limit = 0x22;
    do {
        if (*ptr < 3) break;
        i++;
        ptr += 4;
    } while (i != limit);
    return i & 0xFF;
}

extern u8 D_88B05C68[];
s32 func_88B0449C(void) {
    u8 *ptr = D_88B05C68;
    s32 i = 0;
    s32 limit = 0x24;
    do {
        if (*ptr < 3) break;
        i++;
        ptr += 4;
    } while (i != limit);
    return i & 0xFF;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/40/fragment40_1E0550/func_88B044D0.s")

extern u8 D_88B05868[];
extern u16 D_88B05F6E;
extern s32 func_88B04380(u8);
s32 func_88B04698(void) {
    u16 value = D_88B05F6E;
    s32 index = value;

    if (value >= 0x100) {
        return D_88B05868[index * 4];
    } else {
        return D_88B05BE0[func_88B04380(value) * 4];
    }
}

extern s32 func_88B04698(void);
s32 func_88B046F0(void) {
    s32 result;
    if (func_88B04698() < 3) result = 1;
    else result = 0;
    return result;
}

extern u8 D_88B05F80[];
extern u8 D_88B05F82[];
extern u8 D_88B0636C[];
extern u8 D_88B069AC[];
extern u8 D_88B069CE[];
void func_88B04724(void) {
    u32 index;
    void *handle;
    u8 *cursor;

    _bzero(D_88B05F80, 2674);

    // D_88B05F80[0] counts the leading used 20-byte entries at D_88B05F82.
    handle = func_8006218C(28, 0, 0, 0);
    Deck_ReadEntries(D_88B05F82, 50, handle);
    func_8006229C(handle);
    cursor = D_88B05F82;
    index = 0; // FAKE: clearing index before the count reorders the stores; diff score 60 without it.
    D_88B05F80[0] = 0;
    for (; index < 50; index++, cursor += 20) {
        if (*(u16 *)(cursor + 4) == 0 && *(s8 *)(cursor + 8) == 0) {
            break;
        }
        D_88B05F80[0]++;
    }

    // D_88B05F80[0x3EA] counts the leading used 16-byte entries at D_88B0636C.
    handle = func_8006218C(29, 0, 0, 0);
    Deck_ReadEntries(D_88B0636C, 100, handle);
    func_8006229C(handle);
    // FAKE: one source line for both statements keeps retail's schedule; diff score 60 on two lines.
    D_88B05F80[0x3EA] = 0; cursor = D_88B0636C;
    for (index = 0; index < 100; index++, cursor += 16) {
        if (*(u16 *)(cursor + 2) == 0 && *(s8 *)(cursor + 4) == 0) {
            break;
        }
        D_88B05F80[0x3EA]++;
    }

    for (index = 0; index < 34; index++) {
        D_88B069AC[index] = func_80055CCC(index);
        func_88B043B8(index);
    }

    for (index = 0; index < 36; index++) {
        D_88B069CE[index] = func_80055D44(index);
        func_88B043EC(index);
    }
}

extern u8 D_88006868[];
extern u16 D_88B05D1C;
extern void *func_88B043EC(u8 arg0);
extern s32 func_8005F9A4(s32, u16);
s32 func_88B048C4(void)
{
  s32 result;
  u16 *ptr;
  s32 i;
  result = 0;
 do { ptr = &D_88B05D1C; i = 0; do { if (func_8005F9A4(*((s8 *) D_88006868), *ptr) != 0) { func_88B043EC(i); result = (result + 1) & 0xFF; } i += 1; ptr += 1; } while (i != 0x24); return result; } while (0);
}

extern s32 HAL_Strcmp(s8 *, s8 *);
extern s8 D_8800686D[];
extern u8 D_88B05F80[];
extern u8 D_88B05F82[];
s32 func_88B04950(void) {
    s32 result;
    u8 *ptr;
    u32 i;

    result = 1;
    ptr = D_88B05F82;
    i = 0;
    if (D_88B05F80[0] != 0) {
        do {
            if ((*(u16 *)(D_88006868 + 2) == *(u16 *)(ptr + 4)) &&
                (HAL_Strcmp((s8 *)(ptr + 8), D_8800686D) == 0)) {
                result = 0;
                break;
            }
            i += 1;
            ptr += 0x14;
        } while (i < D_88B05F80[0]);
    }
    return result;
}

s32 func_88B04A08(u16 arg0) {
    s32 result;
    u8 *ptr;
    u32 i;

    result = 0;
    ptr = D_88B05F82;
    i = 0;
    if (D_88B05F80[0] != 0) {
        do {
            if ((arg0 == *(u16 *)ptr) && (*(u16 *)(D_88006868 + 2) == *(u16 *)(ptr + 4)) &&
                (HAL_Strcmp((s8 *)(ptr + 8), D_8800686D) == 0)) {
                result = 1;
                break;
            }
            i += 1;
            ptr += 0x14;
        } while (i < D_88B05F80[0]);
    }
    return result;
}

extern u8 D_88B0636C[];
s32 func_88B04ADC(u16 arg0) {
    s32 result;
    u8 *ptr;
    u32 i;

    result = 1;
    ptr = D_88B0636C;
    i = 0;
    if (D_88B05F80[0x3EA] != 0) {
        do {
            if ((arg0 == *(u16 *)ptr) && (*(u16 *)(D_88006868 + 2) == *(u16 *)(ptr + 2)) &&
                (HAL_Strcmp((s8 *)(ptr + 4), D_8800686D) == 0)) {
                result = 0;
                break;
            }
            i += 1;
            ptr += 0x10;
        } while (i < D_88B05F80[0x3EA]);
    }
    return result;
}

extern u8 D_88B069CE[];
u32 func_88B04BB4(void) {
    u32 count;
    u8 *ptr;
    s32 i;

    count = 0;
    // FAKE: the loops must share one source line; split over lines (same tokens), IDO schedules them differently
    do { i = 0; ptr = D_88B069CE; do { if (*ptr != 0) { count = (count + 1) & 0xFF; } i++; ptr++; } while (i != 36); } while (0);
    return count;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/40/fragment40_1E0550/func_88B04C38.s")

extern s8 *HAL_Strcpy(s8 *, s8 *);
extern u16 D_8800686A;
extern u8 D_88B05868[];
extern u16 D_88B05F6E;
extern s32 func_88B04380(u8);
void func_88B04F70(s8 *arg0, s16 arg1) {
    *(s16 *)(arg0 + 0) = arg1;
    *(s16 *)(arg0 + 2) = D_8800686A;
    HAL_Strcpy(arg0 + 4, D_8800686D);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/40/fragment40_1E0550/func_88B04FB0.s")

void func_88B05250(s8 *arg0, s16 arg1) {
    *(s16 *)(arg0 + 0) = arg1;
    *(s16 *)(arg0 + 4) = D_8800686A;
    HAL_Strcpy(arg0 + 8, D_8800686D);
    {
        u16 value = *(u16 *)(arg0 + 2);
        if (value != 0xFFFF) {
            *(u16 *)(arg0 + 2) = value + 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/40/fragment40_1E0550/func_88B052B0.s")

extern u8 D_88B069AC[];
extern u8 D_88B069CE[];
extern s32 D_88B069F4;
void func_88B05494(u16 arg0) {
    s32 result;
    u8 index;

    if (arg0 >= 0x100) {
        result = arg0;
        index = result - 0x100;
        if (D_88B069CE[index] == 0) {
            D_88B069F4 = 1;
            func_80055E54(index, 1);
        }
    } else {
        result = func_88B04380(arg0);
        index = result;
        if (D_88B069AC[result] == 0) {
            D_88B069F4 = 1;
            func_80055DC4(index, 1);
        }
    }
}

/* mkdraft:func_88B0552C begin */
extern s32 D_88B05F64;
extern s32 D_88B05F68;
extern u16 D_88B05F6C;
extern u16 D_88B05F6E;
extern void func_88B04FB0(u16 arg0);
extern void func_88B052B0(u16 arg0);
extern void func_80052ECC(s32 arg0);
extern void func_80054E48(s32 arg0);
extern s32 func_8005B120(s8 arg0);
extern void func_81C00740(u8 arg0, s16 *arg1, s16 *arg2, s32 arg3, u8 arg4);
extern void GbSave_RequirePakPresent(s8 arg0);

// Hands out Mystery Gift reward Pokemon and saves them to the deck lists.
// arg2 != 0 is the short path: func_88B04FB0 appends arg0 to the 16-byte entry list at
// D_88B0636C, then sound command 3 is sent. Otherwise, when arg3 != 0, func_81C00740
// writes the receive and select reward ids to D_88B05F6C/D_88B05F6E
// (@{src/fragments/88/fragment88_code.c}), func_88B04420 resolves both through the
// id-to-pointer lookups (func_800635E0 / func_8004C874), func_88B05494 records the
// select id, and func_88B052B0 merges arg0 into the 20-byte entry list at D_88B05F82;
// arg1 appends arg0 to D_88B0636C before that. A nonzero func_8005B120 result is the
// return value and is recorded in D_88B05F68; arg3 == 0 calls GbSave_RequirePakPresent
// first.


s32 func_88B0552C(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result = 1;

    if (arg2 != 0) {
        func_88B04FB0(arg0);
        func_80052ECC(3);
        func_80054E48(3);
    } else {
        if (arg3 != 0) {
            D_88B069F4 = 0;
            if (arg1 != 0) {
                func_88B04FB0(arg0);
            }
            func_88B052B0(arg0);
            func_81C00740(*D_88006868, (s16 *)&D_88B05F6C, (s16 *)&D_88B05F6E, (s32)D_88B069CE, D_88B05F64);
            func_88B04420(D_88B05F6C);
            func_88B04420(D_88B05F6E);
            func_88B05494(D_88B05F6E);
            func_80052ECC(3);
            func_80054E48(3);
        }
        result = func_8005B120((s8)*D_88006868);
        if (arg3 == 0) {
            GbSave_RequirePakPresent((s8)*D_88006868);
        }
        if (result != 0) {
            D_88B05F68 = 1;
        }
    }
    return result;
}
/* mkdraft:func_88B0552C end */

/* mkdraft:func_88B05650 begin */
extern u16 D_88B05F6C;
extern u16 D_88B05F6E;
extern s32 D_88B069F4;
extern s32 func_8004C54C(s32, void *);
extern void *func_88B04420(u16);
extern s32 func_88B04698(void);



void func_88B05650(s16 *arg0) {
    if ((0x122 == D_88B05F6C) || (0x122 == D_88B05F6E)) {
        *arg0 = 0x1F;
        return;
    }
    if ((0x123 == D_88B05F6C) || (0x123 == D_88B05F6E)) {
        *arg0 = 0x1E;
        return;
    }
    func_8004C54C(0x46, func_88B04420(D_88B05F6E));
    switch (func_88B04698()) {
    case 4:
        if (D_88B05F6E >= 0x100) {
            *arg0 = 0x2A;
            break;
        }
        if (D_88B069F4 != 0) {
            *arg0 = 0x20;
        } else {
            *arg0 = 0x21;
        }
        break;
    case 3:
        if (D_88B05F6E >= 0x100) {
            *arg0 = 0x2B;
            break;
        }
        if (D_88B069F4 != 0) {
            *arg0 = 0x22;
        } else {
            *arg0 = 0x23;
        }
        break;
    case 2:
        if (D_88B05F6E >= 0x100) {
            *arg0 = 0x2C;
            break;
        }
        if (D_88B069F4 != 0) {
            *arg0 = 0x24;
        } else {
            *arg0 = 0x25;
        }
        break;
    case 1:
        if (D_88B05F6E >= 0x100) {
            *arg0 = 0x2D;
            break;
        }
        if (D_88B069F4 != 0) {
            *arg0 = 0x26;
        } else {
            *arg0 = 0x27;
        }
        break;
    }
}
/* mkdraft:func_88B05650 end */
#endif
