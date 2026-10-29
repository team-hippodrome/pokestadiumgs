#include "global.h"


#ifdef VERSION_US
extern s32 D_882345F4;
extern u32 D_88234910;
extern s32 D_880068B8;
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

M2C_UNK func_800226C0(M2C_UNK);                     /* extern */
M2C_UNK func_88004990(u8, M2C_UNK);                 /* extern */
M2C_UNK func_882026A4(s32, s32);                    /* extern */

void func_8822B580(s32 arg0) {
    func_800226C0(0x47);
    func_882026A4(D_882345F4, arg0);
    M2C_FIELD(D_88234910, s32 *, 0x190) = 1;
    M2C_FIELD(D_88234910, s32 *, 0x194) = arg0;
    if (M2C_FIELD(D_88234910, s32 *, 0x18C) != 0) {
        func_88004990(*M2C_FIELD(D_88234910, u8 **, 0), 8);
    } else {
        func_88004990(*M2C_FIELD(D_88234910, u8 **, 0), 0);
    }
    D_880068B8 = 1;
}
extern void Input_SetRepeatController(s32);
extern s32 D_80087200;
extern s32 D_880068B8;

void func_8822B614(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern u32 D_88234910;
extern s8 D_889041B8;
void func_8822B63C(void) {
    if (*(s32 *)((u8 *)(D_88234910) + 0x18C) == 0) {
        Input_SetRepeatController(D_80087200);
        *(s32 *)((u8 *)(*(void **)((u8 *)(D_88234910) + 0)) + 0x2C) = 1;
        *(s32 *)((u8 *)(D_88234910) + 0x48) = 1;
        D_889041B8 = 2;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19E800/func_8822B6A4.s")

extern u32 D_88234910;
extern void func_8821D930(s32);
void func_8822B7E4(void) {
    func_8821D930((D_88234910 + 88));
}

extern u8 D_8800ED50[];
extern void func_8822B6A4(void);
void func_8822B80C(void) {
    s32 index;

    index = func_88004804(D_88234910 + 0x58, 2, 380, 287, 4, 1, 220, 220, 180, func_8822B6A4, func_8822B7E4,
                          func_8822B614, func_8822B63C, 0, 1);
    *(u8 **)(D_88234910 + 4) = &D_8800ED50[index * 0x4C];
    *(s32 *)(*(u8 **)D_88234910 + 0x2C) = 0;
    *(s32 *)(D_88234910 + 0x48) = 2;
    D_880068B8 = 1;
}

s32 func_8821C0B0();
extern void func_8822AF00(s32);
extern s32 D_882345F4;

void func_8822B8FC(void) {
    if (func_8821C0B0() == 0) {
        func_8822AF00(D_882345F4 + 0x3C);
    }
}

extern u8 D_880068B4[];
extern u8 func_88903B00[];
void func_8822B930(s32 arg0) {
    u8 buffer[128];
    LabPC_OpenMessageDialog(func_8004C8A0(buffer, 128, 37, arg0),
        380, 287, 4, 219, 220, 180, 2, 0, &D_880068B4, &D_880068B8,
        func_88903B00, func_8822B8FC);
}


void func_8822B9C4(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern s32 *func_800635E0(u8);
extern s32 func_8004C54C(s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_88001900(void);
extern void Util_Free(s32);

void func_8822B9EC(void) {
    if (*(s32 *)(D_88234910 + 400) != 0) {
        func_8004C54C(24, (s32)func_800635E0(*(u8 *)(D_88234910 + 393)));
        if (*(s32 *)(D_88234910 + 404) == 4) {
            if (*(s32 *)(D_88234910 + 396) != 0) {
                func_8822B930(116);
            } else {
                func_8822B930(108);
            }
        } else {
            if (*(s32 *)(D_88234910 + 404) == 3) {
                func_8004C54C(25, D_88234910 + 329);
            } else {
                func_8004C54C(25, (s32)func_8004C874(37, *(s32 *)(D_88234910 + 404) + 103));
            }
            if (*(s32 *)(D_88234910 + 396) != 0) {
                func_8822B930(115);
            } else {
                func_8822B930(114);
            }
        }
    } else {
        func_88001900();
        *(s32 *)D_880068B4 = 1;
    }
    Util_Free(D_88234910);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19E800/func_8822BAF8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19E800/func_8822BC58.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19E800/func_8822BE00.s")
#endif
