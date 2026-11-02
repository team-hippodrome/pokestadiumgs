#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_8AF08980 begin */
extern void func_800504BC(s16 *);
extern void func_8AC015B0(s16, s16, s32, s32, s16);
extern u8 D_8AF265A8[];
extern s16 D_8AF265A0;
extern s16 D_8AF2C9E0;

s32 func_8AF08980(s32 mode, void *record) {
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
        func_8AC015B0(x, y, (s32)(D_8AF265A8), D_8AF265A0, D_8AF2C9E0);
        break;
    }
    return 0;
}
/* mkdraft:func_8AF08980 end */

/* mkdraft:func_8AF08A1C begin */
extern u8 D_8AF266E8[];
extern s16 D_8AF265A4;
extern s16 D_8AF2C9E2;
extern s16 D_8AF26908;

s32 func_8AF08A1C(s32 mode, void *record) {
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
        func_8AC015B0(x, y, (s32)(D_8AF266E8), D_8AF265A4, D_8AF2C9E2);
        break;
    }
    D_8AF26908 = -1;
    return 0;
}
/* mkdraft:func_8AF08A1C end */

extern void *D_8AF2CB38;
extern void *D_8AF2CB3C;
extern void *D_8AF2CB40;
extern void *D_8AF2CB44;
void func_8AF08AC0(void) {
    (*(u16 *)((u8 *)(D_8AF2CB38) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB38) + (2))) & 0xFFFD);
    (*(u16 *)((u8 *)(D_8AF2CB40) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB40) + (2))) & 0xFFFD);
    (*(u16 *)((u8 *)(D_8AF2CB3C) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB3C) + (2))) & 0xFFFD);
    (*(u16 *)((u8 *)(D_8AF2CB44) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB44) + (2))) & 0xFFFD);
}

void func_8AF08B14(void) {
    (*(u16 *)((u8 *)(D_8AF2CB38) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB38) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF2CB40) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB40) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF2CB3C) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB3C) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF2CB44) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF2CB44) + (2))) | 2);
}

void func_8AF08B68(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x28) = arg1;
    *(s32 *)(arg0 + 0x2C) = arg2;
}

extern s16 D_8AF2CB74;
extern s16 D_8AF2CB1C;
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

M2C_UNK func_8AF01020(s16, s16);                    /* extern */
extern u8 *D_8AF2CB20;
extern u8 *D_8AF2CB24;

void func_8AF08B74(void) {
    s16 sp1E;
    s16 sp1C;

    M2C_FIELD(D_8AF2CB20, u16 *, 2) = (u16) (M2C_FIELD(D_8AF2CB20, u16 *, 2) & 0xFFFD);
    M2C_FIELD(D_8AF2CB24, u16 *, 2) = (u16) (M2C_FIELD(D_8AF2CB24, u16 *, 2) & 0xFFFD);
    func_8AF08B68((u8 *) D_8AF2CB40, -0x3C5FA501, -0x1E3C7301);
    func_8AF08B68((u8 *) D_8AF2CB44, -0x3C5FA501, -0x1E3C7301);
    if (D_8AF2CB74 == 0) {
        switch (D_8AF2CB1C) {                       /* irregular */
        case 0:
            sp1E = M2C_FIELD(D_8AF2CB20, s16 *, 8);
            sp1C = M2C_FIELD(D_8AF2CB20, s16 *, 0xA);
            func_8AF08B68((u8 *) D_8AF2CB40, -0xFF01, -0xFF01);
            break;
        case 1:
            sp1E = M2C_FIELD(D_8AF2CB24, s16 *, 8);
            sp1C = M2C_FIELD(D_8AF2CB24, s16 *, 0xA);
            func_8AF08B68((u8 *) D_8AF2CB44, -0xFF01, -0xFF01);
            break;
        }
        func_8AF01020(sp1E, sp1C);
    }
}
extern s16 D_8AF2C9E0;
extern s16 D_8AF2C9E2;
extern s16 D_8AF2CB1C;
extern s16 D_8AF2CB74;

void func_8AF08C90(void) {
    D_8AF2CB74 = 0;
    D_8AF2C9E0 = 0;
    D_8AF2C9E2 = 0;
    D_8AF2CB1C = 0;
}

/* mkdraft:func_8AF08CB4 begin */
extern void func_8AF00504(s16);
extern s32 func_8AF003A8(s16);
extern void func_8AC06E98(void *);
extern void func_8AC05E40(s32, s32, s32);
extern s32 func_8AC06D8C(s32, s32);
extern void func_8004E308(s32, s32 *, s32 *);
extern void func_8AC02C80(s32, s32, s32, void *);
extern s16 func_8AC01354(void *, s32);
extern void func_8AF08AC0(void);
extern void func_8AF08B74(void);
// This translation unit's rodata pool is supplied by asm/us/data/217360.rodata.s,
// which starts with these two floats. Writing the literals here would emit a second
// .rodata section into the object and shift the pool.
extern f32 D_8AF290F0;
extern f32 D_8AF290F4;
extern u8 D_8AF2C9E8[];
extern u8 D_8AF2CA60[];
extern u8 D_8AF2CAF0[];
extern void *D_8AF2CAD8;
extern void *D_8AF2CADC;
extern void *D_8AF2CAE4;
extern void *D_8AF2CAE8;
extern void *D_8AF2CB28;
extern void *D_8AF2CB2C;
extern void *D_8AF2CB30;
extern void *D_8AF2CB34;
extern void *D_8AF2CB48;
extern void *D_8AF2CB4C;
extern void *D_8AF2CB50;
extern void *D_8AF2CB54;
extern void *D_8AF2CB58;



void func_8AF08CB4(void) {
    s32 page;

    func_8AF00504(0x4E);
    func_8AF00504(0x35);
    page = func_8AF003A8(0x4E);
    func_8AC06E98((void *)page);
    func_8AC05E40(page, 0x6E616D65, (s32)D_8AF2C9E8);
    func_8AC05E40(page, 0x74797065, (s32)D_8AF2CA60);
    D_8AF2CAD8 = D_8AF2C9E8;
    D_8AF2CADC = D_8AF2CA60;
    D_8AF2CB30 = (void *)func_8AC06D8C(page, 0x6E616D65);
    D_8AF2CB34 = (void *)func_8AC06D8C(page, 0x74797065);
    D_8AF2CB20 = (void *)func_8AC06D8C(page, 0x74655F31);
    D_8AF2CB24 = (void *)func_8AC06D8C(page, 0x74655F32);
    D_8AF2CB28 = (void *)func_8AC06D8C(page, 0x626F6F6B);
    D_8AF2CB2C = (void *)func_8AC06D8C(page, 0x70616765);
    D_8AF2CB38 = (void *)func_8AC06D8C(page, 0x6E5F7769);
    D_8AF2CB40 = (void *)func_8AC06D8C(page, 0x6E5F3230);
    D_8AF2CB3C = (void *)func_8AC06D8C(page, 0x745F7769);
    D_8AF2CB44 = (void *)func_8AC06D8C(page, 0x745F3230);
    D_8AF2CB48 = (void *)func_8AC06D8C(page, 0x6E6E6E6E);
    D_8AF2CB4C = (void *)func_8AC06D8C(page, 0x6E5F6E5F);
    *(u16 *)((u8 *)D_8AF2CB48 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AF2CB48 + 2) &= 0xFFFD;
    D_8AF2CB50 = (void *)func_8AC06D8C(page, 0x74747474);
    D_8AF2CB54 = (void *)func_8AC06D8C(page, 0x745F745F);
    *(u16 *)((u8 *)D_8AF2CB50 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AF2CB50 + 2) &= 0xFFFD;
    func_8004E308((s32)D_8AF2CB4C, (s32 *)func_8AF08980, NULL);
    func_8004E308((s32)D_8AF2CB54, (s32 *)func_8AF08A1C, NULL);
    page = func_8AF003A8(0x35);
    func_8AC02C80(page, 0x74697431, 0x74697432, D_8AF2CAF0);
    D_8AF2CB58 = (void *)func_8AC06D8C(page, 0x7469746C);
    *(s16 *)((u8 *)D_8AF2CB58 + 0x30) = 0x36;
    *(s16 *)((u8 *)D_8AF2CB58 + 0x32) = 0x10;
    D_8AF265A0 = func_8AC01354(D_8AF265A8, 10);
    D_8AF265A4 = func_8AC01354(D_8AF266E8, 0x12);
    func_8AF08B74();
    *(u16 *)((u8 *)D_8AF2CB2C + 2) &= 0xFFFD;
    switch (D_8AF2CB74) {
    case 1:
        D_8AF2CAE4 = D_8AF2CAD8;
        D_8AF2CAE8 = D_8AF2CADC;
        func_8AF08AC0();
        goto scale;
    case 2:
        D_8AF2CAE8 = D_8AF2CAD8;
        D_8AF2CAE4 = D_8AF2CADC;
        func_8AF08AC0();
        goto scale;
    case 0:
    default:
        break;
    }
scale:
    if (D_8AF2CB74 != 0) {
        f32 scale = D_8AF290F0;
        f32 shrink = D_8AF290F4;

        *(f32 *)((u8 *)D_8AF2CAE4 + 0x40) = scale;
        *(f32 *)((u8 *)D_8AF2CAE4 + 0x44) = scale;
        *(f32 *)((u8 *)D_8AF2CAE8 + 0x40) = shrink;
        *(f32 *)((u8 *)D_8AF2CAE8 + 0x44) = shrink;
        *(f32 *)((u8 *)D_8AF2CAE4 + 0x48) = 120.0f;
        *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C) = 180.0f;
    }
}
/* mkdraft:func_8AF08CB4 end */

void func_8AF090B0(f32 *arg0, f32 arg1, f32 arg2) {
    f32 value = *arg0;
    if (arg1 < value) {
        value -= arg2;
        if (value < arg1) value = arg1;
        *arg0 = value;
    }
}

void func_8AF090F0(f32 *arg0, f32 arg1, f32 arg2) {
    f32 value = *arg0;
    if (value < arg1) {
        value += arg2;
        if (arg1 < value) value = arg1;
        *arg0 = value;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_1F6BF0/func_8AF09130.s")

extern void func_800498C4(void);
extern void func_800499EC(void);
void func_8AF09B2C(void) {
    func_800498C4();
    func_800499EC();
}
#pragma C_FUNCTION_PADDING(12)
#endif
