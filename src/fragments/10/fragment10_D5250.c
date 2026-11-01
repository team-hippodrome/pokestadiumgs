#include "global.h"


#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern s16 D_82802890[][4][2];

void func_82800620(s32 arg0, s32 arg1, f32 arg2) {
    gDPPipeSync(D_800D0510++);
    if (arg1 != 0) {
        gDPSetPrimColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0x64, 0x64, (u32)(255.0f * arg2));
        gDPSetEnvColor(D_800D0510++, 0x40, 0x0A, 0x0A, 0);
    } else {
        gDPSetPrimColor(D_800D0510++, 0xFF, 0xFF, 0x64, 0xFF, 0x64, (u32)(255.0f * arg2));
        gDPSetEnvColor(D_800D0510++, 0x0A, 0x40, 0x0A, 0);
    }
    func_8004D19C(D_82802890[arg1][arg0][0], D_82802890[arg1][arg0][1], func_8004C990(0x36, 0), 0, 0);
}
void func_82800864(f32 arg0, s16* arg1) {
    typedef struct { s16 x; s16 y; } Point;
    extern f32 D_82802830;
    extern Point D_828028C0[];

    s32 index;
    f32 fraction;
    f32 one_minus_fraction;
    s16 result_x;
    s16 result_y;
    f32 distance;
    f32 weight;

    index = arg0;
    fraction = arg0 - index;
    one_minus_fraction = 1.0f - fraction;
    weight = D_82802830;

    result_x = D_828028C0[index].x * one_minus_fraction + D_828028C0[index + 1].x * fraction;
    result_y = D_828028C0[index].y * one_minus_fraction + D_828028C0[index + 1].y * fraction;

    distance = sqrtf((result_x * result_x) + (result_y * result_y));

    arg1[0] = (s16)(((f32)result_x * weight) / distance + 319.0f);
    arg1[1] = (s16)(((f32)result_y * weight) / distance + 354.0f);
}

extern u8 D_828028B0[];
void func_82800984(s32 arg0, f32 arg1) {
    s32 mode;
    s16 (*pairs)[2];

    pairs = (s16 (*)[2])D_828028B0;
    gDPSetEnvColor(D_800D0510++, 80, 210, 240, 0);
    gDPSetPrimColor(D_800D0510++, 0xFF, 0xFF, 255, 255, 255, (u32)(255.0f * arg1));
    if (arg0 == 0 || arg0 == 3) {
        mode = 1;
    } else {
        mode = 2;
    }
    func_8004D150(pairs[arg0][0], pairs[arg0][1], func_8004C990(54, mode), 0, (arg0 >= 2) ? 1 : 0, 0);
}

extern void func_82800864(f32, s16 *);
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
void func_82800AE0(u8 *arg0) {
    s16 coords[2];

    func_82800864(*(f32 *)(arg0 + 0x94), coords);
    gDPPipeSync(D_800D0510++);
    gDPSetPrimColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0x64, 0x64, 0xFF);
    gDPSetEnvColor(D_800D0510++, 0x40, 0x0A, 0x0A, 0);
    func_8004D19C(coords[0] - 4, coords[1] - 4, func_8004C990(0x36, 0), 0, 0);
}

s32 func_82800B94(u8 *arg0) {
    return *(u32 *)(arg0 + 0x88) == 0 || *(u32 *)(arg0 + 0x8C) == 0;
}

s32 func_82800BB4(u8 *arg0) {
    return (*(u32 *)(arg0 + 0) & 0x100000) != 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_82800BC8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_82800E94.s")

extern f32 (*D_8160BD08)(f32);
extern s16 D_828028F4[][4][2];

void func_8280105C(u8 *arg0, s16 *arg1, s32 arg2) {
    f32 ratio;

    ratio = D_8160BD08(*(f32 *)(arg0 + 4) / 12.0f);
    if (func_82800BB4(arg0) != 0) {
        ratio = 1.0f;
    }
    arg1[0] = (s16)((((f32)(D_828028F4[0][arg2][0] - D_828028F4[1][arg2][0])) * ratio) + ((f32)D_828028F4[1][arg2][0]));
    arg1[1] = (s16)((((f32)(D_828028F4[0][arg2][1] - D_828028F4[1][arg2][1])) * ratio) + ((f32)D_828028F4[1][arg2][1]));
}
// Unreferenced static empty function: the trailing jr ra; nop at 0x8280113C
// that IDO keeps because statics are never dead-stripped.
static void func_8280113C(void) {}
extern s32 func_8004C874(s32, s32);
extern void Fragment11_DrawBorderedPanelFill(s32, s32, s32, s32, s32, void *);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004989C(s32);
extern void func_800495BC(s32, s32, s32 *);
extern void func_800495F8(s32, s32, s32, s32);
extern void func_800499EC(void);
extern u8 D_82802838;
void func_82801144(void) {
    s32 result1;
    s32 result2;

    result1 = func_8004C874(0x19, 0xE);
    result2 = func_8004C874(0x19, 0x12);
    Fragment11_DrawBorderedPanelFill(0x63, 0xDC, 0x1BC, 0x92, 1, &D_82802838);
    func_800498C4();
    func_800496A4(0x10, 1);
    func_8004989C(0x20);
    func_800495BC(0x70, 0xE7, result1);
    func_800496A4(8, 1);
    func_800495F8(0x20E, 0x14B, 2, result2);
    func_800499EC();
}

s32 func_828011F8(s32 arg0) {
    switch (arg0) {
    case 3:
        return 1;
    case 5:
        return 2;
    case 2:
        return 8;
    case 4:
        return 2;
    case 7:
        return 6;
    case 8:
        return 7;
    case 9:
        return 5;
    case 10:
        return 4;
    case 1:
        return 17;
    case 6:
        return 3;
    default:
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_82801278.s")

extern s32 func_800606E8(s32);

u8 func_828014AC(void) {
    u8 result = 0;
    s32 index = 0;

loop:
    if (func_800606E8(index) != 0) result |= 1 << index;
    index++;
    if (index != 4) goto loop;
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_82801510.s")

s32 func_828016AC(u8 *arg0) {
    *(f32 *)(arg0 + 4) = 0.0f;
    return 0;
}

extern f32 func_816092FC(void);
s32 func_828016BC(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 4) += step;
    if (*(f32 *)(arg0 + 4) >= 12.0f) {
        *(f32 *)(arg0 + 4) = 12.0f;
        *(u8 *)(arg0 + 0xC) = 2;
    }
    return 1;
}

/* mkdraft:func_82801718 begin */


s32 func_82801718(u8 *arg0, s32 arg1, s32 arg2) {
    s32 result;
    s32 index;

    result = arg1;
    index = arg1;
    if (*(s32 *)(arg0 + 0x88) != 0) {
        do {
            index += arg2;
            if (index < 0) {
                break;
            }
            if (index >= 4) {
                break;
            }
            if (*(u8 *)((u8 *)arg0 + index + 0x18) == 0) {
                break;
            }
        } while (1);
    } else {
        index = arg1 + arg2;
    }
    return (index >= 0 && index < 4) ? index : result;
}
/* mkdraft:func_82801718 end */

/* mkdraft:func_82801774 begin */
extern s32 func_82800B94(u8 *);
extern s32 func_82801718(u8 *, s32, s32);
extern void func_800226C0(s32);
extern void func_80057908(u8);
extern u8 D_800CE060[];

// The selected slot is the s32 at +0x10 (-1 when nothing is selected) and the four bytes at
// +0x18 are per-slot enable flags; func_82801718 walks those flags from a start index in steps
// of +1/-1 and returns the index it reached.
// D_800CE060 holds four 0x28-byte controller records; +0x8 is the pressed-button mask.
//@include/controller.h


s32 func_82801774(u8 *arg0) {
    s32 next;
    u8 *record;
    s32 index;

    record = D_800CE060 + arg0[0xD] * 40;
    *(f32 *)(arg0 + 4) = 12.0f;
    if (func_82800B94(arg0) != 0 && arg0[0x90] == 0) {
        if (*(u16 *)(record + 8) & 0x200) {
            next = func_82801718(arg0, *(s32 *)(arg0 + 0x10), -1);
            if (next < *(s32 *)(arg0 + 0x10)) {
                func_800226C0(1);
                *(s32 *)(arg0 + 0x10) = next;
                return 1;
            }
        }
        if (*(u16 *)(record + 8) & 0x100) {
            next = func_82801718(arg0, *(s32 *)(arg0 + 0x10), 1);
            if (*(s32 *)(arg0 + 0x10) < next) {
                func_800226C0(1);
                *(s32 *)(arg0 + 0x10) = next;
                return 1;
            }
        }
    }
    // The +0x18 flags are read through an array subscript because that is the ROM's
    // addressing form: it puts the base in the first addu operand, where a pointer sum
    // puts the index there.
    if (*(u16 *)(record + 8) & 0x4000) {
        func_800226C0(3);
        *(s32 *)(arg0 + 0x10) = -1;
        arg0[0xC] = 3;
    } else if (*(u16 *)(record + 8) & 0x8000) {
        if (arg0[0x90] != 0) {
            // FAKE: the enclosing `else if` already tested this bit; the ROM repeats the
            // test (diff score 380 without the repetition).
            if (*(u16 *)(record + 8) & 0x8000) {
                func_800226C0(2);
                arg0[0x90] = 0;
            }
        } else if ((*(u8 (*)[4])(arg0 + 0x18))[*(s32 *)(arg0 + 0x10)] == 0) {
            func_800226C0(0xF);
            index = *(s32 *)(arg0 + 0x10);
            arg0[0xC] = 3;
            if (index >= 0 && index < 4 && *(u8 *)(arg0 + 0x18 + index) == 0) {
                func_80057908(index);
            }
        } else if (*(s32 *)(arg0 + 0x8C) != 0 && (*(s32 *)(arg0) & 0x20000000)) {
            func_800226C0(0xF);
            arg0[0xC] = 3;
        } else {
            func_800226C0(5);
        }
    } else if (func_82800B94(arg0) != 0 && (*(u16 *)(record + 8) & 1) && (*(s32 *)(arg0) & 0x20000)) {
        *(s32 *)(arg0 + 0x84) = !*(s32 *)(arg0 + 0x84);
        func_800226C0(0x12);
    }
    return 1;
}
/* mkdraft:func_82801774 end */

s32 func_828019B4(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 4) -= step;
    if (*(f32 *)(arg0 + 4) <= 0.0f) {
        *(f32 *)(arg0 + 4) = 0.0f;
        *(u8 *)(arg0 + 0xC) = 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_82801A08.s")

void func_82801BE8(u8 *arg0, void *arg1) {
    f32 step;
    s32 i;
    s16 coordinates[4];

    func_81801420();
    func_82801278(arg0, 0);
    switch (arg0[0xC]) {
        case 0:
            func_828016AC(arg0);
            break;
        case 1:
            func_828016BC(arg0);
            break;
        case 2:
            func_82801774(arg0);
            break;
        case 3:
            func_828019B4(arg0);
            break;
    }
    func_82801A08(arg0);
    for (i = 0; i < 4; i++) {
        func_82800E94(arg0, coordinates, i);
        func_81600A34(arg1, arg0 + i, 0, coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
    }
    if (*(s32 *)(arg0 + 0x10) >= 0) {
        step = func_816092FC() / 20.0f;
        if (*(f32 *)(arg0 + 0x94) + step < *(s32 *)(arg0 + 0x10)) {
            *(f32 *)(arg0 + 0x94) += step;
        } else if (*(s32 *)(arg0 + 0x10) < *(f32 *)(arg0 + 0x94) - step) {
            *(f32 *)(arg0 + 0x94) -= step;
        } else {
            *(f32 *)(arg0 + 0x94) = *(s32 *)(arg0 + 0x10);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_82801D7C.s")

/* mkdraft:func_82801F88 begin */
extern u8 D_8280284C[][3];
extern s32 func_800472E0(s32);
extern void func_81607408(void);

// Draws the box behind the annotation text of entry arg1: 122 pixels wide,
// (line count * 20) + 14 tall, at the position func_8280105C computes for the entry,
// filled with D_8280284C[flag] where flag is the entry's byte at 0x18. The entry's
// font string is drawn into it once the scale factor (entry + 4 over 12) passes 0.99.
// func_8004C874 returns a pointer to that font string; this file's prototypes carry
// these strings as s32 (see the func_800495BC declaration above), and the s32 text
// local follows them.
//@src/47580.c


void func_82801F88(u8 *arg0, s32 arg1) {
    s32 text;
    s32 lines;
    s32 height;
    f32 ratio;
    s16 position[2];

    if (*(s32 *)((u8 *)arg0 + arg1 * 4 + 0x74) >= 0) {
        // FAKE: the (u8 *) casts on this u8 * argument are redundant but set IDO's
        // temp-register coloring; spelled without them the differ scores 35.
        text = func_8004C874(0x19, *(s32 *)((u8 *)arg0 + arg1 * 4 + 0x74));
        lines = func_800472E0(text);
        height = (lines * 20) + 14;
        ratio = D_8160BD08(*(f32 *)(arg0 + 4) / 12.0f);
        func_8280105C(arg0, position, arg1);
        Fragment11_DrawBorderedPanelFill(position[0], position[1], 122, height, 1,
            D_8280284C[*(u8 *)(arg0 + arg1 + 0x18) == 0]);
        if (ratio > 0.99f) {
            func_800498C4();
            func_800496A4(4, 1);
            func_8004989C(20);
            func_800495BC(position[0] + 7, position[1] + 7, text);
            func_800499EC();
        }
        func_81607408();
    }
}
/* mkdraft:func_82801F88 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_828020C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/10/fragment10_D5250/func_82802224.s")

s32 func_8280276C(u8 *arg0) {
    if (arg0[0xC]) return -2;
    if (*(u32 *)(arg0 + 0x8C)) {
        if ((*(s32 *)(arg0 + 0) << 2) < 0 && *(s32 *)(arg0 + 0x10) != -1) return 7;
    }
    return *(s32 *)(arg0 + 0x10);
}

extern void func_80054248(void *);
extern void func_80051D64(s32, s32);
extern void func_80054E48(s32);
void func_828027C0(u8 *arg0) {
    if ((*(s32 *)arg0 << 14) >= 0) {
        return;
    }
    if (*(u32 *)(arg0 + 0x84) != 0) {
        arg0[0x4E] |= 1;
    } else {
        arg0[0x4E] &= 0xFFFE;
    }
    func_80054248(arg0 + 0x4C);
    func_80051D64(0x14, 0);
    func_80054E48(3);
}
#endif
