#include "global.h"


#ifdef VERSION_US
// The 0.01f step limit at the head of this file's .rodata. It is defined as a
// const array (IDO places const scalars in .data, arrays in .rodata) because
// spelling it as a literal in func_8AF18190 changes that function's register
// scheduling; the array read compiles to the same lwc1 from 0x8AF29B30.
const f32 D_8AF29B30[1] = {0.01f};

/* mkdraft:func_8AF179C0 begin */
extern void func_800504BC(s16 *);
extern void func_8AC015B0(s16, s16, s32, s32, s16);
extern u8 *D_8AF35000;
extern s16 D_8AF27430;
extern s16 D_8AF35008;

s32 func_8AF179C0(s32 mode, void *record) {
    s16 x;
    s16 y;
    void *preserved;
    s16 values[2];

    preserved = record;
    switch (mode) {
    case 0:
        *(u16 *)((u8 *)preserved + 2) &= 0xFFFD;
        break;
    case 1:
        func_800504BC(values);
        x = *(s16 *)((u8 *)preserved + 8) + values[0];
        y = *(s16 *)((u8 *)preserved + 0xA) + values[1];
        func_8AC015B0(x, y, (s32)D_8AF35000, D_8AF27430, D_8AF35008);
        break;
    }
    return 0;
}
/* mkdraft:func_8AF179C0 end */

/* mkdraft:func_8AF17A5C begin */
extern void func_800504BC(s16 *);
extern void func_8AC015B0(s16, s16, s32, s32, s16);
extern u8 *D_8AF35004;
extern s16 D_8AF27434;
extern s16 D_8AF3500A;

s32 func_8AF17A5C(s32 mode, void *record) {
    s16 x;
    s16 y;
    void *preserved;
    s16 values[2];

    preserved = record;
    switch (mode) {
    case 0:
        *(u16 *)((u8 *)preserved + 2) &= 0xFFFD;
        break;
    case 1:
        func_800504BC(values);
        x = *(s16 *)((u8 *)preserved + 8) + values[0];
        y = *(s16 *)((u8 *)preserved + 0xA) + values[1];
        func_8AC015B0(x, y, (s32)D_8AF35004, D_8AF27434, D_8AF3500A);
        break;
    }
    return 0;
}
/* mkdraft:func_8AF17A5C end */

extern u8 D_8AF27170[];
extern u8 D_8AF272B0[];
extern u8 D_8AF27390[];
extern s16 D_8AF34D70;
extern s16 D_8AF34FAC;
void func_8AF17AF8(void) {
    D_8AF35000 = D_8AF27170;
    D_8AF27430 = func_8AC01354(D_8AF35000, 10);
    D_8AF34D70 = D_8AF34FAC;
    switch (D_8AF34FAC) {
        case 2:
            D_8AF35004 = D_8AF27390;
            D_8AF27434 = func_8AC01354(D_8AF35004, 5);
            return;
        case 3:
            D_8AF35004 = D_8AF272B0;
            D_8AF27434 = func_8AC01354(D_8AF35004, 7);
            return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_205C30/func_8AF17BA8.s")

void func_8AF17F0C(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x28) = arg1;
    *(s32 *)(arg0 + 0x2C) = arg2;
}

extern s16 D_8AF3500C;
extern s16 D_8AF34FAC;
extern s16 D_8AF34FAE;
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

extern u8 *D_8AF34FB0;
extern u8 *D_8AF34FB4;
extern u8 *D_8AF34FE0;
extern u8 *D_8AF34FE4;
extern u8 *D_8AF34FE8;
extern u8 *D_8AF34FEC;

void func_8AF17F18(void) {
    M2C_FIELD(D_8AF34FB0, u16 *, 2) = (u16) (M2C_FIELD(D_8AF34FB0, u16 *, 2) & 0xFFFE);
    M2C_FIELD(D_8AF34FB4, u16 *, 2) = (u16) (M2C_FIELD(D_8AF34FB4, u16 *, 2) & 0xFFFE);
    func_8AF17F0C(D_8AF34FE0, -0x3C5FA501, -0x1E3C7301);
    func_8AF17F0C(D_8AF34FE4, -0x3C5FA501, -0x1E3C7301);
    func_8AF17F0C(D_8AF34FE8, -0x3C5FA501, -0x1E3C7301);
    func_8AF17F0C(D_8AF34FEC, -0x3C5FA501, -0x1E3C7301);
    switch (D_8AF3500C) {                           /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        switch (D_8AF34FAC) {                       /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            M2C_FIELD(D_8AF34FB0, u16 *, 2) = (u16) (M2C_FIELD(D_8AF34FB0, u16 *, 2) | 1);
            func_8AF17F0C(D_8AF34FE8, -0xFF01, -0xFF01);
            return;
        case 3:                                     /* switch 2 */
            M2C_FIELD(D_8AF34FB4, u16 *, 2) = (u16) (M2C_FIELD(D_8AF34FB4, u16 *, 2) | 1);
            func_8AF17F0C(D_8AF34FEC, -0xFF01, -0xFF01);
            return;
        }
        break;
    case 7:                                         /* switch 1 */
        switch (D_8AF34FAE) {                       /* switch 3; irregular */
        case 0:                                     /* switch 3 */
            M2C_FIELD(D_8AF34FB0, u16 *, 2) = (u16) (M2C_FIELD(D_8AF34FB0, u16 *, 2) | 1);
            func_8AF17F0C(D_8AF34FE0, -0xFF01, -0xFF01);
            return;
        case 1:                                     /* switch 3 */
            M2C_FIELD(D_8AF34FB4, u16 *, 2) = (u16) (M2C_FIELD(D_8AF34FB4, u16 *, 2) | 1);
            func_8AF17F0C(D_8AF34FE4, -0xFF01, -0xFF01);
            return;
        }
        break;
    }
}
extern s16 D_8AF34FAC;
extern s16 D_8AF34FAE;
extern s16 D_8AF34FFC;
extern s16 D_8AF35008;
extern s16 D_8AF3500A;
extern s16 D_8AF3500C;

void func_8AF180F4(void) {
    D_8AF3500C = 0;
    D_8AF34FAC = 2;
    D_8AF34FAE = 0;
    D_8AF34FFC = 0;
    D_8AF35008 = 0;
    D_8AF3500A = 0;
}

extern u8 *D_8AF34F70;
extern u8 *D_8AF34F74;
extern f32 D_8AF29B24;
extern f32 D_8AF29B28;

void func_8AF1812C(void) {
    f32 first = D_8AF29B24;
    f32 second = D_8AF29B28;
    *(f32 *)(D_8AF34F70 + 0x40) = first;
    *(f32 *)(D_8AF34F70 + 0x44) = first;
    *(f32 *)(D_8AF34F74 + 0x40) = second;
    *(f32 *)(D_8AF34F74 + 0x44) = second;
    *(f32 *)(D_8AF34F70 + 0x48) = 120.0f;
    *(f32 *)(D_8AF34F70 + 0x4C) = 180.0f;
}

extern u8 *D_8AF34F78;
extern u8 *D_8AF34F7C;
extern f32 D_8AF29B2C;

void func_8AF18190(void) {
    f32 first = D_8AF29B2C;
    f32 second = D_8AF29B30[0];
    *(f32 *)(D_8AF34F78 + 0x40) = first;
    *(f32 *)(D_8AF34F78 + 0x44) = first;
    *(f32 *)(D_8AF34F7C + 0x40) = second;
    *(f32 *)(D_8AF34F7C + 0x44) = second;
    *(f32 *)(D_8AF34F78 + 0x48) = 120.0f;
    *(f32 *)(D_8AF34F78 + 0x4C) = 260.0f;
}

/* mkdraft:func_8AF181F4 begin */
extern void func_800476A0(u8 *arg0, s32 arg1);
extern s32 func_800476FC(s32 arg0, s32 arg1);
extern s32 func_80047738(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_8004C4B0(s32 value);
extern s32 func_8004C8C0(u16 arg0);
extern s32 func_8004C990(s32 arg0, s32 arg1);
extern void func_8004E308();
extern void func_8AC02C80(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern void func_8AC05E40(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8AC06D8C(s32 arg0, s32 arg1);
extern void func_8AC06E98(void *arg0);
extern s32 func_8AF00020(void);
extern s32 func_8AF003A8(s16 arg0);
extern void func_8AF00504(s32);

s32 func_8AF17BA8();                            /* extern */
extern u8 D_8AF34D78;
extern u8 D_8AF34DF0;
extern u8 D_8AF34E68;
extern u8 D_8AF34EE0;
extern u8 *D_8AF34F58;
extern u8 *D_8AF34F5C;
extern u8 *D_8AF34F60;
extern u8 *D_8AF34F64;
extern s32 D_8AF34F80;
extern s32 D_8AF34FB8;
extern s32 D_8AF34FBC;
extern s32 D_8AF34FC0;
extern s32 D_8AF34FC4;
extern s32 D_8AF34FC8;
extern s32 D_8AF34FCC;
extern s32 D_8AF34FD0;
extern s32 D_8AF34FD4;
extern s32 D_8AF34FD8;
extern s32 D_8AF34FDC;
extern s32 D_8AF34FF0;
extern s32 D_8AF35020;
extern s32 D_8AF35024;
extern s32 D_8AF35028;
extern s32 D_8AF3502C;
extern u8 D_8AF35030;
extern void func_8AF013D8(void);



void func_8AF181F4(void) {
    s32 temp_v0_2;
    // FAKE: no instruction reads this local; the only C read is the copy-propagated
    // D_8AF34FF0 assignment below. Its named-local home slot moves the compiler's $a1
    // spill from 0x24(sp) to the retail 0x20(sp); diff score 8 without it.
    s32 temp_v0_3;
    void *temp_v0;
    s32 d_8af34fcc_val;

    func_8004C4B0(8);
    func_8004C4B0(0xA);
    func_8004C4B0(9);
    func_8004C4B0(0xB);
    func_8004C4B0(7);
    func_8004C8C0(0x37U);
    func_8004C8C0(0x143U);
    func_800476A0(&D_8AF35030, 2);
    func_800476FC((s32) &D_8AF35030, 2);
    func_80047738(0, func_8004C990(0x37, 0), 0, 0);
    if (func_8AF00020() != 0) {
        func_80047738(1, func_8004C990(0x37, 1), 0, 0);
    } else {
        func_80047738(1, func_8004C990(0x143, 0), 0, 0);
    }
    func_8AF00504(0x78);
    func_8AF00504(0x35);
    temp_v0 = func_8AF003A8(0x78);
    func_8AC06E98(temp_v0);
    D_8AF34FC0 = func_8AC06D8C((s32) temp_v0, 0x6E616D65);
    D_8AF34FC4 = func_8AC06D8C((s32) temp_v0, 0x6B6F6B61);
    D_8AF34FC8 = func_8AC06D8C((s32) temp_v0, 0x616B615F);
    D_8AF34FCC = func_8AC06D8C((s32) temp_v0, 0x6B696E5F);
    if (func_8AF00020() != 0) {
        d_8af34fcc_val = D_8AF34FCC;
        *(s16 *)((u8 *)(d_8af34fcc_val) + 0x24) = 0xB1;
        *(s16 *)((u8 *)(d_8af34fcc_val) + 0x26) = 1;
    } else {
        d_8af34fcc_val = D_8AF34FCC;
        *(s16 *)((u8 *)(d_8af34fcc_val) + 0x24) = 0x143;
        *(s16 *)((u8 *)(d_8af34fcc_val) + 0x26) = 1;
    }
    func_8AC05E40((s32) temp_v0, 0x6E616D65, (s32) &D_8AF34D78);
    func_8AC05E40((s32) temp_v0, 0x6B6F6B61, (s32) &D_8AF34DF0);
    func_8AC05E40((s32) temp_v0, 0x616B615F, (s32) &D_8AF34E68);
    func_8AC05E40((s32) temp_v0, 0x6B696E5F, (s32) &D_8AF34EE0);
    D_8AF34F58 = &D_8AF34D78;
    D_8AF34F5C = &D_8AF34DF0;
    D_8AF34F60 = &D_8AF34E68;
    D_8AF34F64 = &D_8AF34EE0;
    D_8AF34FB0 = func_8AC06D8C((s32) temp_v0, 0x74655F31);
    D_8AF34FB4 = func_8AC06D8C((s32) temp_v0, 0x74655F33);
    func_8004E308((s32) D_8AF34FB0, func_8AF013D8, NULL);
    func_8004E308((s32) D_8AF34FB4, func_8AF013D8, NULL);
    D_8AF34FB8 = func_8AC06D8C((s32) temp_v0, 0x626F6F6B);
    D_8AF34FBC = func_8AC06D8C((s32) temp_v0, 0x70616765);
    D_8AF34FD0 = func_8AC06D8C((s32) temp_v0, 0x6E5F7769);
    D_8AF34FD4 = func_8AC06D8C((s32) temp_v0, 0x6B5F7769);
    D_8AF34FD8 = func_8AC06D8C((s32) temp_v0, 0x615F7769);
    D_8AF34FDC = func_8AC06D8C((s32) temp_v0, 0x675F7769);
    D_8AF34FE0 = func_8AC06D8C((s32) temp_v0, 0x6E5F665F);
    D_8AF34FE4 = func_8AC06D8C((s32) temp_v0, 0x6B5F665F);
    D_8AF34FE8 = func_8AC06D8C((s32) temp_v0, 0x615F665F);
    D_8AF34FEC = func_8AC06D8C((s32) temp_v0, 0x675F665F);
    D_8AF35020 = func_8AC06D8C((s32) temp_v0, 0x6E6E6E6E);
    D_8AF35024 = func_8AC06D8C((s32) temp_v0, 0x6E5F6E5F);
    *(u16 *)((u8 *)(D_8AF35020) + 2) = (u16) (*(u16 *)((u8 *)(D_8AF35020) + 2) & 0xFFFE);
    *(u16 *)((u8 *)(D_8AF35020) + 2) = (u16) (*(u16 *)((u8 *)(D_8AF35020) + 2) & 0xFFFD);
    D_8AF35028 = func_8AC06D8C((s32) temp_v0, 0x6B6B6B6B);
    D_8AF3502C = func_8AC06D8C((s32) temp_v0, 0x6B5F6B5F);
    *(u16 *)((u8 *)(D_8AF35028) + 2) = (u16) (*(u16 *)((u8 *)(D_8AF35028) + 2) & 0xFFFE);
    *(u16 *)((u8 *)(D_8AF35028) + 2) = (u16) (*(u16 *)((u8 *)(D_8AF35028) + 2) & 0xFFFD);
    func_8004E308(D_8AF35024, (s32 *) func_8AF179C0, NULL);
    func_8004E308(D_8AF3502C, (s32 *) func_8AF17A5C, NULL);
    temp_v0_2 = func_8AF003A8(0x35);
    temp_v0_3 = func_8AC06D8C(temp_v0_2, 0x7469746C);
    D_8AF34FF0 = temp_v0_3;
    *(s16 *)((u8 *)(D_8AF34FF0) + 0x30) = 0x36;
    *(s16 *)((u8 *)(D_8AF34FF0) + 0x32) = 0x10;
    func_8AC02C80(temp_v0_2, 0x74697431, 0x74697432, &D_8AF34F80);
    func_8AF17AF8();
    func_8AF17F18();
    switch (D_8AF3500C) {                           /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        D_8AF34F78 = D_8AF34F58;
        D_8AF34F7C = D_8AF34F5C;
        func_8AF17BA8();
        func_8AF1812C();
        func_8AF18190();
        return;
    case 4:                                         /* switch 1 */
        D_8AF34F7C = D_8AF34F58;
        D_8AF34F78 = D_8AF34F5C;
        func_8AF17BA8();
        func_8AF1812C();
        func_8AF18190();
        return;
    case 0:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
        switch (D_8AF34FAC) {                       /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            D_8AF34F70 = D_8AF34F60;
            D_8AF34F74 = D_8AF34F64;
            func_8AF17BA8();
            func_8AF1812C();
            return;
        case 3:                                     /* switch 2 */
            D_8AF34F74 = D_8AF34F60;
            D_8AF34F70 = D_8AF34F64;
            func_8AF17BA8();
            func_8AF1812C();
            return;
        }
        break;
    }
}
/* mkdraft:func_8AF181F4 end */

void func_8AF18808(f32 *arg0, f32 arg1, f32 arg2) {
    f32 value = *arg0;
    if (arg1 < value) {
        value -= arg2;
        if (value < arg1) value = arg1;
        *arg0 = value;
    }
}

void func_8AF18848(f32 *arg0, f32 arg1, f32 arg2) {
    f32 value = *arg0;
    if (value < arg1) {
        value += arg2;
        if (arg1 < value) value = arg1;
        *arg0 = value;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_205C30/func_8AF18888.s")

extern void func_800498C4(void);
extern void func_800499EC(void);
void func_8AF19850(void) {
    func_800498C4();
    func_800499EC();
}
#pragma C_FUNCTION_PADDING(8)
#endif
