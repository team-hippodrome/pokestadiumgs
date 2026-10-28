#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1BD630/func_88500020.s")

extern s32 D_8850D670;
extern void func_8850A0EC(s32);
extern void func_88506618(void);
extern u8 D_8850D6C8;
extern s8 D_8850D6C9;
extern s32 func_88504E94(s32);
extern s32 main_pool_pop_state(s32);
extern s32 main_pool_push_state(s32);
extern void func_8005A0F4(s32);
extern void func_88503830(s32, s32);
extern void func_88507FA8(s32);
extern s32 func_80001FF0(void);
extern void StageFade_StartFromTransparent(s32);
void func_885002A0(s32 mode) {
    D_8850D670 = mode;
    switch (mode) {
    case 1:
    case 3:
        break;
    case 2:
        func_8850A0EC(0);
        func_88506618();
        break;
    case 4:
        if (D_8850D6C8 == 1 && func_88504E94(D_8850D6C8) != D_8850D6C9) {
            if (D_8850D6C9 >= 0) {
                main_pool_pop_state(0x65786368);
            }
            main_pool_push_state(0x65786368);
            D_8850D6C9 = func_88504E94(D_8850D6C8);
            func_8005A0F4(D_8850D6C9);
        }
        func_88503830(D_8850D6C8, (s8)func_88504E94(D_8850D6C8));
        break;
    case 5:
        func_88507FA8(0);
        break;
    case 6:
        func_88507FA8(1);
        break;
    case 7:
        StageFade_StartFromTransparent((u16)((f32)func_80001FF0() * 0.3f / 2));
        break;
    }
}

extern void func_885002A0(s32);
extern void func_8850A0EC(s32);
extern s32 D_8850D6CC;

void func_88500460(s32 arg0) {
    D_8850D6CC = arg0;
    func_885002A0(3);
    func_8850A0EC(arg0);
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

M2C_UNK func_80008648();                            /* extern */
M2C_UNK func_800088DC();                            /* extern */
M2C_UNK func_80049064(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800496A4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800498C4();                            /* extern */
M2C_UNK func_800499EC();                            /* extern */
s32 func_8004C874(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_88004180();                            /* extern */
M2C_UNK func_8850C998();                            /* extern */
extern s32 D_880068B8;
extern s32 D_8850D670;

void func_88500494(void) {
    func_800088DC();
    if (D_880068B8 != 0) {
        func_8850C998();
        if (D_8850D670 == 1) {
            func_800498C4();
            func_800496A4(0x10, 2);
            func_80049064(0x140, 0x168, 1, func_8004C874(0x34, 0));
            func_800499EC();
        }
    }
    func_88004180();
    func_80008648();
}
extern s32 D_880068B4;
extern u8 *D_80087200;
extern u8 D_8850D6C8;
extern u8 D_8850D6D9[];
extern u8 D_8850D679[];
extern s32 D_8852301C;
extern s32 D_88523020;
extern s32 D_88804054;
extern void func_800226C0(s32);
extern void func_80057944(u8);
extern void func_88500020(void);
extern s32 func_88504E94(s32);
extern s32 func_8850CED8(s32);
extern s32 fragment29_main(u8);

// Steps the state machine at D_8850D670 while D_880068B4 is set. Returns 0 once
// state 7 sees fade mode 1, otherwise 1.
s32 func_8850052C(void) {
    s32 result = 1;
    s32 pad; // FAKE: unused; enlarges the frame to 0x28 bytes; diff score 42 without it.
    s32 first;

    if (D_880068B4 != 0) {
        switch (D_8850D670) {
            case 0:
                if (StageContext_GetFadeMode() == 0) {
                    func_885002A0(1);
                }
                break;
            case 1:
                if (*(u16 *)(D_80087200 + 8) & 0x4000) {
                    func_800226C0(3);
                    func_885002A0(7);
                } else if (*(u16 *)(D_80087200 + 8) & 0x8000) {
                    func_800226C0(2);
                    func_885002A0(2);
                }
                break;
            case 2:
                if (func_88504E94(1) == -1) {
                    func_885002A0(7);
                } else {
                    func_88500460(1);
                    first = fragment29_main(D_8850D679[func_88504E94(0) * 20]);
                    if (fragment29_main(D_8850D679[func_88504E94(1) * 20]) != first) {
                        D_88804054 = 1;
                    } else {
                        D_88804054 = 0;
                    }
                }
                break;
            case 3:
                switch (D_8850D6CC) {
                    case 1:
                        if (func_8850CED8(1)) {
                            func_885002A0(4);
                        }
                        break;
                    case 19:
                        if (func_8850CED8(2)) {
                            func_885002A0(4);
                        }
                        break;
                    case 4:
                    case 8:
                    case 11:
                        if (func_8850CED8(3)) {
                            func_885002A0(2);
                        }
                        break;
                    case 20:
                        if (func_8850CED8(6)) {
                            func_885002A0(5);
                        }
                        break;
                    case 21:
                        if (func_8850CED8(8)) {
                            func_88500020();
                            func_88500460(12);
                        }
                        break;
                    case 12:
                        if (func_8850CED8(10)) {
                            func_885002A0(6);
                        }
                        break;
                }
                break;
            case 4:
                if (D_8850D6D9[D_8850D6C8 * 0xA960] != 0) {
                    if (D_8850D6C8 == 0) {
                        func_88500460(19);
                    } else {
                        func_88500460(20);
                    }
                    D_8850D6C8 ^= 1;
                } else if (D_8850D6C8 == 0) {
                    func_88500460(4);
                } else {
                    func_88500460(8);
                    D_8850D6C8 = 0;
                }
                break;
            case 5:
                if (D_8852301C != 0) {
                    func_88500460(21);
                } else {
                    func_88500460(11);
                }
                break;
            case 6:
                if (D_88523020 != 0) {
                    func_885002A0(2);
                } else {
                    func_80057944(func_88504E94(1));
                    func_885002A0(7);
                }
                break;
            case 7:
                if (StageContext_GetFadeMode() == 1) {
                    result = 0;
                }
                break;
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1BD630/func_8850089C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1BD630/func_885009D0.s")

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

M2C_UNK Font_EnableLineBreak();                     /* extern */
M2C_UNK Gfx_FreeDisplayListBuffers();               /* extern */
M2C_UNK Gfx_InitDisplayListBuffers(M2C_UNK, M2C_UNK); /* extern */
s32 func_800082E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80008514(s32);                         /* extern */
M2C_UNK func_80008574();                            /* extern */
M2C_UNK func_800086A4(M2C_UNK);                     /* extern */
s32 func_80047588(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80047610();                            /* extern */
M2C_UNK func_8004C09C(M2C_UNK);                     /* extern */
M2C_UNK func_8004C398();                            /* extern */
M2C_UNK func_8850089C();                            /* extern */
M2C_UNK func_885009D0();                            /* extern */
M2C_UNK main_pool_pop_state(M2C_UNK);               /* extern */
M2C_UNK main_pool_push_state(M2C_UNK);              /* extern */
extern s32 D_8800687C;

s32 func_88500C10(s32 arg0, M2C_UNK arg1) {
    s32 sp24;

    main_pool_push_state(0x504D4558);
    Gfx_InitDisplayListBuffers(0x14000, 0);
    sp24 = func_800082E0(1, 0, 2, 0, 2, 1);
    func_8004C09C(0xB);
    D_8800687C = func_80047588(0x1C, 0);
    Font_EnableLineBreak();
    func_885009D0();
    func_80008514(sp24);
    func_8850089C();
    func_800086A4(2);
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x504D4558);
    return 7;
}
#endif
