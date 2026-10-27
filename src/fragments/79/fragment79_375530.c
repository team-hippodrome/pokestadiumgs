#include "global.h"


#ifdef VERSION_US
void func_84105CA0(u8 *arg0) {}
#endif

void func_84105CA8(void) {
}

#ifdef VERSION_US
void func_84105CB0(u8 *arg0) {}
#endif

#ifdef VERSION_US
void func_84105CB8(u8 *arg0) {}
#endif

#ifdef VERSION_US
void func_84105CC0(u8 *arg0) {}
#endif

#ifdef VERSION_US
void func_84105CC8(void) {}
void func_84105CC8_padding(void) {}
void func_84105CC8_padding2(void) {}
void func_84105CC8_padding3(void) {}
#endif

void func_84105CE8(void) {
}

void func_84105CF0(void) {
}

#ifdef VERSION_US
void func_84105CF8(u8 *arg0) {}
#endif

#ifdef VERSION_US
extern u8 *D_84190150;
extern s32 D_84190154;
extern u8 *main_pool_alloc(s32, s32);
void func_84105D00(void) {
    D_84190150 = main_pool_alloc(0x300, 0);
    _bzero(D_84190150, 0x300);
    D_84190154 = 0;
}
#endif

#ifdef VERSION_US
u8 *func_84105D40(void) {
    s32 i;
    s32 index;
    u8 *ptr;
    index = D_84190154;
    ptr = D_84190150 + index * 0xC;
    for (i = 0; i < 0x40; i++) {
        if ((ptr[8] & 1) == 0) break;
        index++;
        if (index >= 0x40) {
            index = 0;
            ptr = D_84190150;
        } else ptr += 0xC;
    }
    if (i >= 0x40) ptr = NULL;
    else {
        D_84190154 = index + 1;
        if (D_84190154 >= 0x40) D_84190154 = 0;
    }
    return ptr;
}
#endif

#ifdef VERSION_US
extern u8 * func_84105D40(void);
u8 *func_84105DD0(void) {
    u8 *entry;

    entry = func_84105D40();
    if (entry != NULL) {
        entry[8] = 0;
        entry[4] = 0;
        entry[5] = 0;
        entry[6] = 0;
        entry[7] = 1;
        entry[8] = 0; // FAKE: repeated clear before the flag is set
        *(s32 *)entry = 0;
        entry[8] |= 1;
    }
    return entry;
}
#endif

#ifdef VERSION_US
void func_84105E20(u8 *arg0)
{
  *((s8 *) (((u8 *) arg0) + 7)) = 0;
  *((s8 *) (((u8 *) arg0) + 8)) = 0;
  *((s8 *) (((u8 *) arg0) + 5)) = 0;
  *((s8 *) (((u8 *) arg0) + 4)) = 0;
  *((s8 *) (((u8 *) arg0) + 6)) = ((s8) (*((s8 *) (((u8 *) arg0) + 7)))) & 0xFF;
}
#endif

#ifdef VERSION_US
extern void func_84105E20(u8 *);
void func_84105E3C(void) {
    u8 *ptr = D_84190150;
    s32 i = 0;
    while (i != 0x40) {
        if (ptr[8] & 1) {
            func_84105E20(ptr);
        }
        i++;
        ptr += 0xC;
    }
}
#endif

#ifdef VERSION_US
extern s32 ParticleMath_RandomRange(s32 arg0);
extern s32 ParticleMath_RandomSigned(s32 arg0);
s16 func_84105E9C(s16 sign, u16 range) {
    s32 limit;

    if (!range) {
        return 0;
    } else {
        limit = range;
        if (range == 0xFFFF) {
            limit = 0x10000;
        }
        if (sign == 0) {
            return ParticleMath_RandomRange(limit);
        } else {
            return ParticleMath_RandomSigned(limit);
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_84105F10.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_84105FC8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_841063D8.s")
#endif

#ifdef VERSION_US
s16 func_84106540(void *arg0, void *arg1, u16 arg2, unsigned long arg3) {
    s16 result;

    switch (arg2) {
        case 1:
            result = 0;
            break;
        case 2:
            result = (*(u8 *)((u8 *)arg1 + 3) * *(s8 *)((u8 *)arg0 + 6)) + arg3;
            break;
        case 3:
            result = arg3;
            break;
        case 4:
            result = arg3;
            break;
        case 5:
            result = (*(u8 *)((u8 *)arg1 + 3) * *(s8 *)((u8 *)arg0 + 6)) + arg3;
            break;
        case 6:
            result = *(s8 *)((u8 *)arg0 + 6);
            break;
        default:
            result = 0;
            break;
    }
    return result;
}
#endif

#ifdef VERSION_US
void func_841065E0(void *arg0, void *arg1, void *arg2, s16 arg3, f32 arg4) {
    u8 *p;

    p = arg1;
    if (p != NULL) {
        if (*(s16 *)p == 1) {
            if (arg3 == 0) {
                *(s16 *)arg2 = func_84105E9C(1, *(u16 *)(p + 0xC));
            }
        } else {
            *(s16 *)arg2 = func_84105E9C(1, *(u16 *)(p + 0xC));
        }
        *(f32 *)arg0 += (f32)(*(s16 *)(p + 6) + *(s16 *)arg2) * arg4;
    }
}
#endif

#ifdef VERSION_US
extern u8 *D_8418C950;
void func_8410668C(u8 *arg0) {
    u8 *record;
    u8 *found;
    s32 i;

    record = D_8418C950;
    found = NULL;
    i = 0;
    do {
        // FAKE: comma expression around the second 0x10 load; diff score 15 without it.
        if ((*(s8 *)(record + 0x98) != 0) && (*(u8 **)(record + 0x10) != NULL) &&
            (ParticleMath_HasBits((0, *(u8 **)(record + 0x10)) + 4, 0x400000) != 0)) {
            if (func_84100054(record, 2) != 0) {
                if (func_84100054(arg0, 2) != 0) {
                    found = record;
                    break;
                }
            } else if (func_84100074(arg0, 2) != 0) {
                found = record;
                break;
            }
        }
        i++;
        record += 156;
    } while (i != 300);

    if (found != NULL) {
        *(f32 *)(arg0 + 0x2C) += *(f32 *)(found + 0x20);
        *(f32 *)(arg0 + 0x30) += *(f32 *)(found + 0x24);
        *(f32 *)(arg0 + 0x34) += *(f32 *)(found + 0x28);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_8410679C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_84106AC4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_84106F34.s")
#endif

#ifdef VERSION_US
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

M2C_UNK func_84100020(u8 *, M2C_UNK);             /* extern */
extern s32 D_84190194;
extern s32 D_841901A4;

void func_84107170(u8 *arg0, u8 *arg1) {
    u8 *temp_s1;

    temp_s1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg1, u8 **, 0x10) = temp_s1;
    M2C_FIELD(arg1, u8 *, 0x7C) = (u8) M2C_FIELD(arg0, u8 *, 9);
    M2C_FIELD(arg1, u16 *, 0x68) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    M2C_FIELD(arg1, s32 *, 8) = (s32) D_84190194;
    if (M2C_FIELD(temp_s1, s32 *, 4) & 0x10) {
        func_84100020(arg1, 1);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 0x400) {
        func_84100020(arg1, 0x40);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 8) {
        func_84100020(arg1, 0x200);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 0x20000000) {
        func_84100020(arg1, 0x10000);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 4) {
        func_84100020(arg1, 0x100);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 0x100) {
        func_84100020(arg1, 0x400);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 0x10000000) {
        func_84100020(arg1, 0x20000);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 0x08000000) {
        func_84100020(arg1, 0x8000);
    }
    if (M2C_FIELD(temp_s1, s32 *, 4) & 0x80000000) {
        func_84100020(arg1, 0x40000);
    }
    if (M2C_FIELD(temp_s1, s32 *, 8) & 4) {
        func_84100020(arg1, 0x80000);
        D_841901A4 = 0;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_841072BC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_841076B8.s")
#endif

#ifdef VERSION_US
extern u8 *func_84100328(void);
s32 func_841077E8(u8 *arg0) {
    u8 *obj;

    if (*(s32 *)arg0 != 0) {
        obj = func_84100328();
        if (obj == NULL) {
            return 0;
        }
        obj[0x7C] = arg0[9];
        *(s32 *)(obj + 0x10) = *(s32 *)arg0;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 *func_84100328(void);
extern void fragment27_main(u32 *, u32);
extern u8 *func_84104F54(u8 *);
s32 func_84107838(u8 *arg0) {
    u8 *obj;

    if (*(s32 *)(arg0 + 0) != 0) {
        obj = func_84100328();
        if (obj == NULL) {
            return -1;
        }
        fragment27_main((u32 *)(obj + 0x14), 8);
        fragment27_main((u32 *)(obj + 0x14), 0x20);
        *(s32 *)(obj + 0x10) = *(s32 *)(arg0 + 0);
        obj[0x7C] = arg0[9];
        func_84104F54(obj);
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_841078B8(u8 *arg0) {
    u8 *obj;

    if (*(s32 *)arg0 != 0) {
        obj = func_84100328();
        if (obj == NULL) {
            return -1;
        }
        fragment27_main((u32 *)(obj + 0x14), 0x7028);
        *(s32 *)(obj + 0x10) = *(s32 *)arg0;
        obj[0x7C] = arg0[9];
        *(f32 *)(obj + 0x44) = 160.0f;
        *(f32 *)(obj + 0x48) = 120.0f;
        *(f32 *)(obj + 0x20) = 160.0f;
        *(f32 *)(obj + 0x24) = 120.0f;
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_84107948(u8 *arg0) {
    u8 *obj;

    if (*(s32 *)arg0 != 0) {
        obj = func_84100328();
        if (obj == NULL) {
            return 0;
        }
        obj[0x7C] = arg0[9];
        *(s32 *)(obj + 0x10) = *(s32 *)arg0;
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_375530/func_84107998.s")
#endif

#ifdef VERSION_US
void func_84107B68(void) {
    s32 i;
    u8 *entry;

    entry = D_84190150;
    i = 0;
loop:
    if ((*(u8 *)(entry + 8) & 1) != 0) {
        if (*(u8 *)(entry + 4) != 0) {
            (*(u8 *)(entry + 4))--;
        }
        if (*(u8 *)(entry + 4) == 0) {
            switch (*(u8 *)(entry + 9)) {
            case 0: func_84107998(entry); break;
            case 1: func_84107998(entry); break;
            case 7: func_841076B8(entry); break;
            case 2: func_841077E8(entry); break;
            case 4: func_84107838(entry); break;
            case 5: func_84107948(entry); break;
            case 6: func_84107948(entry); break;
            case 8: func_841078B8(entry); break;
            }
            if (*(s8 *)(entry + 7) > 0) {
                //!bug: byte 7 is read as s8, so it never equals 255 and this branch never runs
                if (*(s8 *)(entry + 7) == 255) {
                    *(u8 *)(entry + 4) = *(u8 *)(entry + 5);
                } else {
                    *(s8 *)(entry + 6) += 1;
                    if (*(s8 *)(entry + 7) == *(s8 *)(entry + 6)) {
                        func_84105E20(entry);
                    } else {
                        *(u8 *)(entry + 4) = *(u8 *)(entry + 5);
                    }
                }
            }
        }
    }
    i++;
    entry += 0xC;
    if (i != 64) goto loop;
}
#endif
