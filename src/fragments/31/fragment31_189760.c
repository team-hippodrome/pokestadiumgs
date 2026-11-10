#include "global.h"


#ifdef VERSION_US
extern u8 *D_88234564;
extern void Util_Free(void *);
extern void main_pool_pop_state(s32);
extern void func_8821CE40(s32);
extern s32 D_88234560;
extern s32 func_8821BA34(u16, void *);
typedef struct Color88217F70 {
    u8 red;
    u8 green;
    u8 blue;
} Color88217F70;
extern void *func_8004C874(s32, s32);
extern s32 D_8800687C;
extern u8 * D_88234730;
extern s32 D_882346F0;
extern void func_80049064(s32, s32, s32, s32);
extern void func_80047634(s32);
void func_882164E0(void) {
    Util_Free(D_88234564);
    main_pool_pop_state(0x4C495354);
    func_8821CE40(0);
    D_88234560 = 5;
}

extern void func_88200134(s32, s32);
void func_88216520(void) {
    func_88200134(0, 2);
}


/* mkdraft:func_88216544 begin */
extern u8 *D_88234740;
extern u8 D_88006880[];
extern u16 D_88234744;
extern s32 D_889041B4;
extern s32 D_882345CC;
extern s32 D_882345D0;
extern s32 D_880068B4;
extern s32 D_880068B8;
extern u8 D_889041B8;
extern s8 D_88234746;
extern u8 D_8823474C;
extern u8 D_8823474D;
extern u8 D_8823474E;
extern u8 D_8823474F;
extern s16 D_88234748;
extern s16 D_8823474A;
extern u16 D_8800EF42;
extern u16 D_8800EF44;
extern void D_88000E4C(void);
extern void *D_80087200;
extern s32 main_pool_push_state(s32);
extern s32 mem_pool_try_init(s32, s32);
struct MemPool3A00;
extern void *mem_pool_alloc(struct MemPool3A00 *, s32);
extern s32 func_8004C4B0(s32);
extern s32 func_8004C8C0(u16);
extern s32 func_8004C990(s32, s32);
extern s32 func_80049290(s32, s32, const char *);
extern s32 func_80001FF0(void);
extern void func_882011E0(void *);
extern void StorageList_Initialize(struct MemPool3A00 *);
extern void func_88A00D0C(void *);
extern void func_88203744(void *);
extern void func_8821DAC0(void *, void *, void *);
extern void Input_SetRepeatController(void *);
extern void func_88200020(u8);
extern void func_882000AC(u8, s16, s16, u16, u16, s32, s32, u8);
extern s32 func_88227224();
extern void func_882164E0(void);
extern void func_88001C6C(void *, u16, u8, s16, u8, s16, s16, s16, s16, s16, s32);
extern void func_88000288(void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_88005B60(s32, void (*)(void), void (*)(void), void (*)(void));



void func_88216544(void) {
    s32 i;
    struct MemPool3A00 *pool;

    main_pool_push_state(0x4C495354);
    pool = (struct MemPool3A00 *)(u32)mem_pool_try_init(0x20000, 0);
    D_88234740 = mem_pool_alloc(pool, 0x130);
    func_8004C8C0(0xC0);
    func_8004C8C0(0xF3);
    *(s32 *)((u8 *)D_88234740 + 0x9C) = func_8004C990(0xBF, 1);
    *(s32 *)((u8 *)D_88234740 + 0xA0) = func_8004C990(0xC0, 0);
    *(s32 *)((u8 *)D_88234740 + 0xA4) = func_8004C990(0xBF, 0);
    *(s32 *)((u8 *)D_88234740 + 0xA8) = func_8004C990(0xF3, 0);
    func_8004C8C0(0x1C);
    D_882345CC = func_8004C990(0x1C, 1);
    D_882345D0 = func_8004C990(0x1C, 0);
    func_8004C4B0(0x25);
    *(s32 *)((u8 *)D_88234740 + 0x24) = (s32)func_8004C874(0xD, 0x18);
    *(s32 *)((u8 *)D_88234740 + 0x28) = (s32)func_8004C874(0xD, 0x19);
    *(s32 *)((u8 *)D_88234740 + 0x2C) = (s32)func_8004C874(0x25, 4);
    *(s32 *)((u8 *)D_88234740 + 0x30) = (s32)func_8004C874(0xD, 0x12);
    *(s32 *)((u8 *)D_88234740 + 0x34) = (s32)func_8004C874(0xD, 0x13);
    *(s32 *)((u8 *)D_88234740 + 0x40) = (s32)func_8004C874(0xD, 0x1A);
    *(s32 *)((u8 *)D_88234740 + 0x44) = (s32)func_8004C874(0xD, 2);
    *(s32 *)((u8 *)D_88234740 + 0x48) = (s32)func_8004C874(0xD, 3);
    *(s32 *)((u8 *)D_88234740 + 0x4C) = (s32)func_8004C874(0xD, 4);
    *(s32 *)((u8 *)D_88234740 + 0x50) = (s32)func_8004C874(0xD, 6);
    *(s32 *)((u8 *)D_88234740 + 0x54) = (s32)func_8004C874(0xD, 7);
    *(s32 *)((u8 *)D_88234740 + 0x58) = (s32)func_8004C874(0xD, 5);
    for (i = 0; i != 4; i++) {
        *(s32 *)((u8 *)D_88234740 + i * 4 + 0x5C) = (s32)func_8004C874(0x25, i + 5);
    }
    *(s32 *)((u8 *)D_88234740 + 0x78) = (s32)func_8004C874(0xD, 9);
    *(s32 *)((u8 *)D_88234740 + 0x7C) = (s32)func_8004C874(0xD, 0xA);
    *(s32 *)((u8 *)D_88234740 + 0x80) = (s32)func_8004C874(0xD, 0x1B);
    *(s32 *)((u8 *)D_88234740 + 0x84) = (s32)func_8004C874(0xD, 8);
    *(s32 *)((u8 *)D_88234740 + 0x88) = (s32)func_8004C874(0x25, 0x28);
    func_8004C4B0(9);
    func_8004C4B0(0xB);
    func_8004C4B0(0x45);
    func_882011E0(pool);
    StorageList_Initialize(pool);
    func_88A00D0C(pool);
    func_88203744(pool);
    func_8821DAC0(pool, D_88234740 + 0xC4, D_88234740 + 0xF8);
    Input_SetRepeatController(D_80087200);
    func_88200020(1);
    func_882000AC(0, 0x28, 0x48, 0x233, 0x17F, (s32)func_88227224, (s32)func_882164E0, 0);
    D_889041B4 = 0;
    D_88234746 = 0;
    *(s32 *)((u8 *)D_88234740 + 0x0) = 1;
    *(s8 *)(D_88234740 + 0x4) = 1;
    *(s8 *)(D_88234740 + 0x5) = 0x68;
    *(s8 *)(D_88234740 + 0x6) = 0x40;
    *(s8 *)(D_88234740 + 0x7) = 0x40;
    *(s8 *)(D_88234740 + 0x8) = 0x60;
    *(s8 *)(D_88234740 + 0x9) = 0x60;
    *(s8 *)(D_88234740 + 0xC) = 0x30;
    *(s8 *)(D_88234740 + 0xD) = 0x38;
    *(s8 *)(D_88234740 + 0xE) = 0x40;
    *(s8 *)(D_88234740 + 0xF) = 0x40;
    *(s8 *)(D_88234740 + 0x10) = 0x40;
    *(s8 *)(D_88234740 + 0x11) = 0x40;
    *(s8 *)(D_88234740 + 0x12) = 0x40;
    *(s8 *)(D_88234740 + 0x13) = 0x6A;
    *(s8 *)(D_88234740 + 0x14) = 0x6A;
    *(s8 *)(D_88234740 + 0x15) = 0x6A;
    *(s8 *)(D_88234740 + 0x16) = 0x6A;
    *(s8 *)(D_88234740 + 0x1A) = 0x34;
    *(s8 *)(D_88234740 + 0x1B) = 0x58;
    *(s8 *)(D_88234740 + 0x1C) = 0x68;
    *(s8 *)(D_88234740 + 0x1D) = 0x78;
    *(s8 *)(D_88234740 + 0x1E) = 0x3C;
    D_8823474A = 0;
    D_88234748 = D_8823474A;
    D_880068B4 = D_880068B8 = 1;
    D_8823474C = 2;
    D_8823474D = 0;
    D_889041B8 = 0;
    D_8823474E = 0;
    D_8823474F = 0;
    *(s8 *)(D_88234740 + 0x94) = func_80049290(4, 1, "9");
    *(s8 *)(D_88234740 + 0x95) = func_80049290(4, 1, "99");
    *(s8 *)(D_88234740 + 0x96) = func_80049290(4, 1, "999");
    *(s8 *)(D_88234740 + 0x12C) = 0;
    func_88001C6C(D_88006880, D_88234744, 0xE, 0x93, 0x14, 0xA,
                  (s32)(480.0f / (f32)func_80001FF0() + ((480.0f / (f32)func_80001FF0() > 0.0f) ? 0.5f : -0.5f)),
                  0x38, 0x38, 0xF0C, 0x46);
    func_88000288((u8 *)D_88234740 + 0xAC, 0, 0xFF, 0x64, 0,
                  (s32)((f32)10 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)10 / 60.0f > 0.0f) ? 0.5f : -0.5f)),
                  0,
                  (s32)((f32)10 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)10 / 60.0f > 0.0f) ? 0.5f : -0.5f)));
    func_88000288((u8 *)D_88234740 + 0xB8, 0, 0xFF, 0, 0,
                  (s32)((f32)10 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)10 / 60.0f > 0.0f) ? 0.5f : -0.5f)),
                  0,
                  (s32)((f32)10 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)10 / 60.0f > 0.0f) ? 0.5f : -0.5f)));
    D_8800EF42 = 0x17C;
    D_8800EF44 = 0x11F;
    func_88005B60(0, D_88000E4C, D_88000E4C, D_88000E4C);
}
/* mkdraft:func_88216544 end */

extern u8 *D_88234740;
u8 *func_88216D54(s32 arg0) { switch (arg0) { case 0: case 1: return D_88234740 + 0xC4; case 2: return D_88234740 + 0xF8; } }

// Returns the start of column arg1 for entry arg0: 48, 78, then 168 plus the widths of
// columns 2 through arg1 - 1 (the per-column widths that func_88216E28 returns).
s32 func_88216D98(s8 arg0, s8 arg1) {
    s16 x;
    u32 i;
    u8 *width;

    switch (arg1) {
        case 0:
            x = 48;
            break;
        case 1:
            x = 78;
            break;
        default:
            i = 0;
            x = 168;
            width = D_88234740 + 5 + arg0 * 7;
            // FAKE: guarded do-while; diff score 60 as a multi-line while (i + 2 < arg1) loop.
            if (i + 2 < arg1) {
                do {
                    i++;
                    x += *width;
                    width++;
                } while (i + 2 < arg1);
            }
            break;
    }
    return x;
}

s32 func_88216E28(s8 arg0, s8 arg1) {
    s32 result;
    switch (arg1) {
    case 0:
        result = 0x1E;
        break;
    case 1:
        result = 0x58;
        break;
    default:
        result = ((u8 *)D_88234740)[arg0 * 7 + arg1 + 3];
        break;
    }
    return result;
}

s32 func_88200D04(s32);
s32 func_88201F0C();
s32 func_88228BCC(s32, s32, void (*)());
s32 func_88228F30(s32, s32, void (*)());
s32 func_882295E4(s32, s32, void (*)());

void func_88216E80(void) {
    if (func_88201F0C() != 0) {
        func_88228F30(0x17C, 0x11F, func_88216520);
        return;
    }
    if (func_88200D04(7) != 0) {
        func_882295E4(0x17C, 0x11F, func_88216520);
        return;
    }
    func_88228BCC(0x17C, 0x11F, func_88216520);
}

extern u8 D_88006880[];
extern void *D_80087200;
extern void func_880022B4(void *, s32, s32);
extern void func_88001900(void);
extern void Input_SetRepeatController(void *);
void func_88216EFC(void *arg0) {
    if (*(void **)D_88234740 != arg0) {
        *(void **)D_88234740 = arg0;
        if (arg0 != 0) {
            func_880022B4(D_88006880, 0xF00, 1);
            func_88001900();
        } else {
            func_880022B4(D_88006880, 0xF00, 0);
            Input_SetRepeatController(D_80087200);
        }
    }
}

extern void func_800226C0(s32); extern void *D_80087200; extern u8 *D_88234740; extern s8 D_88234746; extern u8 D_882338A4[];
void func_88216F74(void) { func_800226C0(0x4B); if ((*(u16 *)((u8 *)D_80087200 + 8) & 2) != 0) { D_88234746--; if (D_88234746 < 0) D_88234746 = 3; } else if ((*(u16 *)((u8 *)D_80087200 + 8) & 1) != 0) { D_88234746++; if (D_88234746 >= 4) D_88234746 = 0; } if (D_882338A4[D_88234746] + 1 < ((s8 *)D_88234740)[4]) D_88234740[4] = D_882338A4[D_88234746] + 1; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_189760/func_88217040.s")

#ifndef M2C_FIELD /* m2c --valid-syntax helpers (mirrors mkdraft.py) */
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

void func_80049628(s32, s32, s32);
void func_88000EC0(s8 *, s16, s32);
s32 func_88216D98(s8, s8);
void func_800495F8(s32, s32, s32, const char *, ...);

void func_88217C90(s8 arg0, s16 arg1, s16 arg2) {
    s8 sp4A;
    M2C_UNK sp48;
    s16 temp_s1;
    s32 temp_s2;
    s32 var_s0;
    s8 *var_s1;
    s8 temp_v0;

    temp_s1 = func_88216E28(1, arg0), var_s0 = func_88216D98(1, arg0);
    temp_s2 = ((s32) M2C_FIELD(D_88234740, u8 *, 0x96) >> 1) + var_s0 + (temp_s1 >> 1);
    if (arg2 < 0) {
        func_800495F8(temp_s2, arg1 + 2, 2, func_8004C874(0x25, 0x82));
        return;
    }
    func_88000EC0((s8 *) &sp48, arg2, 0);
    var_s0 = 2;
    var_s1 = (s8 *) &sp48 + 2;
    do {
        temp_v0 = *var_s1;
        if (temp_v0 >= 0) {
            func_80049628(temp_s2 - M2C_FIELD((D_88234740 + var_s0), u8 *, 0x94), arg1 + 2, temp_v0 + 0x30);
        }
        var_s0 -= 1;
        var_s1 -= 1;
    } while (var_s0 >= 0);
}
extern Color88217F70 D_88233700[];
extern void func_880006E0(Color88217F70 *);
extern void func_8004972C(s32, s32, s32, s32);
extern s32 func_80049290(s32, s32, const char *);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
extern void func_80049628(s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern u8 * D_88234740;
void StorageList_DrawCategoryLabel(s16 x, s16 y, u8 category, u8 ordinal, u8 alpha) {
    const char *text;
    if (alpha == 0) return;
    if (alpha == 255) {
        func_880006E0(&D_88233700[category]);
    } else {
        func_8004972C(D_88233700[category].red, D_88233700[category].green,
                     D_88233700[category].blue, alpha);
    }
    if (category == 0) {
        func_80048E30((u8 *)D_8800687C, x + 11, y + 2, (const char *)func_8004C874(37, 9), 1);
    } else {
        text = (const char *)func_8004C874(37, category + 9);
        x += 11;
        y += 2;
        func_80048E30((u8 *)D_8800687C, x, y, text, 1);
        x += func_80049290(4, 1, text);
        x += func_80049290(4, 1, " ");
        if (ordinal + 1 >= 10) {
            func_80049628(x, y, 49);
            func_80049628(x + D_88234740[148], y, ordinal + 39);
        } else {
            func_80049628(x, y, ordinal + 49);
        }
    }
}

extern Color88217F70 *func_88000510(Color88217F70 *, s8);
extern void func_880006E0(Color88217F70 *);
extern u8 func_80062D98(u8);
extern s32 func_80062CE0(u8);
extern void func_8004972C(s32, s32, s32, s32);
void func_88217F70(s16 x, s16 y, u8 move, u8 alpha) {
    Color88217F70 color;

    if (alpha == 0 || move == 0) {
        return;
    }
    func_88000510(&color, move == 252 ? 0 : func_80062D98(move));
    if (alpha == 255) {
        func_880006E0(&color);
    } else {
        func_8004972C(color.red, color.green, color.blue, alpha);
    }
    func_80048E30((u8 *)D_8800687C, x + 5, y + 2, (const char *)(move == 252 ? func_8004C874(0x45, 0x13) : func_80062CE0(move)), 1);
}

extern s32 D_889041B4;
s32 func_88218064(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 result = 1;
    *arg2 = arg0;
    *arg3 = arg0 + arg1 - 1;
    if (D_889041B4 == 3) {
        if (*arg2 >= 0xFD) {
            result = 0;
        } else if (*arg3 >= 0xFD) {
            *arg3 = 0xFC;
        }
    }
    return result;
}

void func_882180C4(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    *arg2 = arg1;
    *arg3 = arg1 + 0x13;
    if (arg0 == 0) {
        if (*arg2 < 0x93) {
            *arg2 = 0x93;
        }
    } else if (arg0 == 0xE) {
        if (*arg3 >= 0x1AB) {
            *arg3 = 0x1AA;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_189760/func_8821811C.s")

#endif
