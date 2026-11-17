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
        f32 scale = 0.6f;
        f32 shrink = 0.01f;

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


extern u8 *D_8AF263C0;
extern s16 D_8AF2CB74;
extern s16 D_8AF2CB1C;
extern s16 D_8AF2C9E0;
extern s16 D_8AF2C9E2;
extern s16 D_8AF265A0;
extern s16 D_8AF2CB5C;
extern s16 D_8AF2CB5E;
extern s16 D_8AF2CB60;
extern s16 D_8AF2CB62;
extern s16 D_8AF2CB80;
extern void *D_8AF2CAE0;
extern void func_8AF00130(s32);
extern void func_8AF09CC8(void);
extern void func_8AF08B14(void);
extern void func_8AC06400(void *, void *);
void func_8AF090B0(f32 *, f32, f32);
void func_8AF090F0(f32 *, f32, f32);

s16 func_8AF09130(void) {
    s16 ret = 8;
    f32 f;
    s16 prev;
    u16 b;
    u16 h;
    switch (D_8AF2CB74) {
    case 0:
        b = *(u16 *)(D_8AF263C0 + 8);
        if (b & 0x4000) {
            func_8AF00130(3);
            ret = 7;
            break;
        }
        prev = D_8AF2CB1C;
        switch (D_8AF2CB1C) {
        case 0:
            if (b & 0x100) {
                D_8AF2CB1C = 1;
            } else if (b & 0x8000) {
                func_8AF00130(0xC0);
                D_8AF2CB74 = 3;
                D_8AF2C9E0 = 0;
                D_8AF2CB5C = *(f32 *)((u8 *)D_8AF2CAD8 + 0x48);
                D_8AF2CB5E = *(f32 *)((u8 *)D_8AF2CAD8 + 0x4C);
                func_8AF08AC0();
            }
            break;
        case 1:
            if (b & 0x200) {
                D_8AF2CB1C = 0;
            } else if (b & 0x8000) {
                func_8AF00130(0xC0);
                D_8AF2CB74 = 4;
                D_8AF2C9E2 = 0;
                D_8AF2CB5C = *(f32 *)((u8 *)D_8AF2CADC + 0x48);
                D_8AF2CB5E = *(f32 *)((u8 *)D_8AF2CADC + 0x4C);
                D_8AF2CB60 = 0;
                D_8AF2CB62 = 0;
                func_8AF08AC0();
            }
            break;
        }
        if (prev != D_8AF2CB1C) {
            func_8AF00130(1);
        }
        break;
    case 1:
        b = *(u16 *)(D_8AF263C0 + 8);
        if (b & 0x8000) {
            func_8AF00130(0xC1);
            D_8AF2CB80 = 0;
            ret = 9;
            func_8AF09CC8();
        } else if (b & 0x4000) {
            func_8AF00130(3);
            D_8AF2CB74 = 5;
        } else {
            h = *(u16 *)(D_8AF263C0 + 0xC);
            if ((h & 0x800) && D_8AF2C9E0 > 0) {
                func_8AF00130(1);
                D_8AF2C9E0--;
            } else if ((h & 0x400) && D_8AF2C9E0 < D_8AF265A0 - 1) {
                func_8AF00130(1);
                D_8AF2C9E0++;
            }
        }
        break;
    case 2:
        h = *(u16 *)(D_8AF263C0 + 0xC);
        if ((h & 0x800) && D_8AF2CB62 > 0) {
            D_8AF2CB62--;
            func_8AF00130(1);
        } else if ((h & 0x400) && D_8AF2CB62 < 8) {
            D_8AF2CB62++;
            func_8AF00130(1);
        } else if ((h & 0x200) && D_8AF2CB60 > 0) {
            D_8AF2CB60--;
            func_8AF00130(1);
        } else if ((h & 0x100) && D_8AF2CB60 <= 0) {
            D_8AF2CB60++;
            func_8AF00130(1);
        } else {
            b = *(u16 *)(D_8AF263C0 + 8);
            if (b & 0x8000) {
                if (D_8AF2C9E2 < 0x11) {
                    func_8AF00130(0xC1);
                    D_8AF2CB80 = 1;
                    ret = 9;
                    func_8AF09CC8();
                }
            } else if (b & 0x4000) {
                func_8AF00130(3);
                D_8AF2CB74 = 6;
            }
        }
        D_8AF2C9E2 = D_8AF2CB62 + D_8AF2CB60 * 9;
        break;
    }
    switch (D_8AF2CB74) {
    case 0:
        func_8AC06400(D_8AF2CAD8, D_8AF2CB30);
        func_8AC06400(D_8AF2CADC, D_8AF2CB34);
        switch (D_8AF2CB1C) {
        case 0:
            D_8AF2CAE0 = D_8AF2CAD8;
            break;
        case 1:
            D_8AF2CAE0 = D_8AF2CADC;
            break;
        default:
            D_8AF2CAE0 = D_8AF2CAD8;
            break;
        }
        f = 1.1f;
        *(f32 *)((u8 *)D_8AF2CAE0 + 0x40) = f;
        *(f32 *)((u8 *)D_8AF2CAE0 + 0x44) = f;
        break;
    case 1:
    case 3:
    case 5:
        D_8AF2CAE4 = D_8AF2CAD8;
        D_8AF2CAE8 = D_8AF2CADC;
        func_8AF08AC0();
        f = 1.1f;
        break;
    case 2:
    case 4:
    case 6:
        D_8AF2CAE8 = D_8AF2CAD8;
        D_8AF2CAE4 = D_8AF2CADC;
        func_8AF08AC0();
        f = 1.1f;
        break;
    default:
        f = 1.1f;
        break;
    }
    switch (D_8AF2CB74) {
    case 3:
    case 4:
        func_8AF090B0((f32 *)((u8 *)D_8AF2CAE4 + 0x40), 0.6f, 0.1f);
        func_8AF090B0((f32 *)((u8 *)D_8AF2CAE8 + 0x40), 0.01f, 0.4f);
        func_8AF090B0((f32 *)((u8 *)D_8AF2CAE4 + 0x44), 0.6f, 0.1f);
        func_8AF090B0((f32 *)((u8 *)D_8AF2CAE8 + 0x44), 0.01f, 0.4f);
        *(f32 *)((u8 *)D_8AF2CAE4 + 0x48) += (120.0f - *(f32 *)((u8 *)D_8AF2CAE4 + 0x48)) * 0.25f;
        *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C) += (180.0f - *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C)) * 0.25f;
        if (-0.2f < 120.0f - *(f32 *)((u8 *)D_8AF2CAE4 + 0x48)) {
            *(f32 *)((u8 *)D_8AF2CAE4 + 0x48) = 120.0f;
        }
        if (-0.2f < 180.0f - *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C)) {
            *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C) = 180.0f;
        }
        if ((s16)*(f32 *)((u8 *)D_8AF2CAE4 + 0x48) == 0x78 && (s16)*(f32 *)((u8 *)D_8AF2CAE4 + 0x4C) == 0xB4) {
            switch (D_8AF2CB74) {
            case 3:
                D_8AF2CB74 = 1;
                break;
            case 4:
                D_8AF2CB74 = 2;
                break;
            }
        }
        break;
    case 5:
    case 6:
        func_8AF090F0((f32 *)((u8 *)D_8AF2CAE4 + 0x40), f, 0.1f);
        func_8AF090F0((f32 *)((u8 *)D_8AF2CAE8 + 0x40), 1.0f, 0.4f);
        func_8AF090F0((f32 *)((u8 *)D_8AF2CAE4 + 0x44), 1.1f, 0.1f);
        func_8AF090F0((f32 *)((u8 *)D_8AF2CAE8 + 0x44), 1.0f, 0.4f);
        *(f32 *)((u8 *)D_8AF2CAE4 + 0x48) += ((f32)D_8AF2CB5C - *(f32 *)((u8 *)D_8AF2CAE4 + 0x48)) * 0.25f;
        *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C) += ((f32)D_8AF2CB5E - *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C)) * 0.25f;
        if (((f32)D_8AF2CB5C - *(f32 *)((u8 *)D_8AF2CAE4 + 0x48)) < 1.0f) {
            *(f32 *)((u8 *)D_8AF2CAE4 + 0x48) = (f32)D_8AF2CB5C;
        }
        if (((f32)D_8AF2CB5E - *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C)) < 1.0f) {
            *(f32 *)((u8 *)D_8AF2CAE4 + 0x4C) = (f32)D_8AF2CB5E;
        }
        if (D_8AF2CB5C == (s16)*(f32 *)((u8 *)D_8AF2CAE4 + 0x48) && D_8AF2CB5E == (s16)*(f32 *)((u8 *)D_8AF2CAE4 + 0x4C)) {
            D_8AF2CB74 = 0;
            func_8AF08B14();
        }
        break;
    }
    func_8AF08B74();
    switch (D_8AF2CB74) {
    case 1:
        *(u16 *)((u8 *)D_8AF2CB48 + 2) |= 1;
        *(u16 *)((u8 *)D_8AF2CB50 + 2) &= 0xFFFE;
        break;
    case 2:
        *(u16 *)((u8 *)D_8AF2CB50 + 2) |= 1;
        *(u16 *)((u8 *)D_8AF2CB48 + 2) &= 0xFFFE;
        break;
    case 0:
    default:
        *(u16 *)((u8 *)D_8AF2CB48 + 2) &= 0xFFFE;
        *(u16 *)((u8 *)D_8AF2CB50 + 2) &= 0xFFFE;
        break;
    }
    return ret;
}

extern void func_800498C4(void);
extern void func_800499EC(void);
void func_8AF09B2C(void) {
    func_800498C4();
    func_800499EC();
}
#endif
