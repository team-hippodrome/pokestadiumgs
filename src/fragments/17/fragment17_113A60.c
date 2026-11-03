#include "global.h"


#ifdef VERSION_US
// The fragment loader clears these two-halfword transition-control records.
//@src/2CA0.c
typedef struct F17TransitionState {
    s16 state;
    s16 unk_02;
} F17TransitionState;
static F17TransitionState sTransition105E8;

typedef struct { s16 a; s16 b; } Pair16_b2;
extern s16 D_822105F0;
extern s16 D_822105F4;
extern s16 D_822106B2;
extern s16 D_822106B4;
extern s16 D_822106CC, D_822106CE;
extern s16 D_822106BA;
extern f32 D_822106C4;
extern f32 D_822106C8;
extern void func_800226C0(s32);
extern u16 D_822106B6;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern s16 D_82210640;
extern s16 D_82210642;
extern s16 D_82210644;
extern s16 D_82210646;
extern s32 func_8220D67C(void);
void func_822040A0(s16 *arg0) {
    s16 *v0 = &D_822105F0;
    v0[0] = 1;
    v0[1] = 0;
    v0[8] = arg0[4];
    v0[9] = arg0[5];
    v0[10] = arg0[6];
    v0[11] = arg0[7];
    v0[12] = arg0[6] - arg0[0x14];
    v0[13] = arg0[7] - arg0[0x15];
    *(Pair16_b2 *)&D_822105F4 = *(Pair16_b2 *)&v0[8];
    v0[4] = v0[10];
    v0[5] = v0[11];
    v0[6] = v0[4] - v0[12];
    v0[7] = v0[5] - v0[13];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_82204148.s")

extern s16 D_822105F0;

void func_82204430(s32 arg0) {
    D_822105F0 = arg0;
    ((s16 *)&D_822105F0)[1] = 0;
}

extern void func_800503A4(s32);
extern s32 D_8220DA18;
extern s32 D_8220DA1C;
void func_82204444(void) {
    func_800503A4(D_8220DA18);
    if (D_822105F0 == 2) {
        func_800503A4(D_8220DA1C);
    }
}

void func_82204488(s16 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_82204494.s")

/* mkdraft:func_82204744 begin */
extern s16 D_822105E8;
extern u8 D_822105DC[];
extern u8 D_822105EA[];

void func_82204744(void) {
    F17TransitionState *state = &sTransition105E8;

    if (*(s16 *)(D_822105DC + 12) == 0) {
        state->state = 1;
        state->unk_02 = 0;
        func_800226C0(62);
    }
}
/* mkdraft:func_82204744 end */

s32 func_82204780(s32 arg0, s32 arg1) {
    return (arg1 / arg0) & ~1;
}

s32 func_822047BC(s32 arg0, s32 arg1) {
    s32 temp_lo;
    s32 var_v1;

    temp_lo = arg0 / arg1;
    var_v1 = temp_lo;
    if ((arg0 % arg1) > 0) {
        var_v1 = temp_lo + 1;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_82204804.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_8220510C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_822056C0.s")

extern void *D_8220EB88;
s32 func_82205A14(s32 arg0, void *arg1) {
    switch (arg0) {
    case 0:
        D_8220EB88 = arg1;
        *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        break;
    case 1:
        break;
    default:
        break;
    }
    return 0;
}

extern s32 D_8220DA10;
s32 func_82205A48(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_8220DA10 != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}

extern void * D_8220DA08;
extern s32 D_8220DA10;
s32 func_82205A8C(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_8220DA10 != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
            if (*(s16 *)*(u8 **)((u8 *)D_8220DA08 + 0x20) == 0) {
                *(u16 *)((u8 *)arg1 + 0x32) = 0x44;
            } else {
                *(u16 *)((u8 *)arg1 + 0x32) = 0x45;
            }
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}

/* mkdraft:Fragment17_OptionColorCallback begin */
extern s32 D_82210610[];
extern s32 D_82210628[];
extern s32 func_8220AD10(void);
extern s32 D_8220EB90;

s32 Fragment17_OptionColorCallback(s32 mode, void *node) {
    s32 visible;
    typedef struct { u32 rgba; } Fragment17OptionColorWord;

    s32 index = *(s32 *)((u8 *)node + 0x20);
    s32 selection = func_8220AD10();

    switch (mode) {
    case 0:
        ((Fragment17OptionColorWord *)D_82210610)[index] = *(Fragment17OptionColorWord *)((u8 *)node + 0x28);
        ((Fragment17OptionColorWord *)D_82210628)[index] = *(Fragment17OptionColorWord *)((u8 *)node + 0x2C);
        break;
    case 1:
        visible = 1;
        switch (index) {
        case 5:
            if (D_8220EB90 != 0) {
                *(u16 *)((u8 *)node + 2) |= 2;
            } else {
                *(u16 *)((u8 *)node + 2) &= ~2;
                visible = 0;
            }
            break;
        }
        if (visible != 0) {
            if (selection != index) {
                *(Fragment17OptionColorWord *)((u8 *)node + 0x28) = ((Fragment17OptionColorWord *)D_82210610)[index];
                *(Fragment17OptionColorWord *)((u8 *)node + 0x2C) = ((Fragment17OptionColorWord *)D_82210628)[index];
            } else {
                *(u8 *)((u8 *)node + 0x28) = 0xFF;
                *(u8 *)((u8 *)node + 0x29) = 0xFF;
                *(u8 *)((u8 *)node + 0x2A) = 0;
                *(Fragment17OptionColorWord *)((u8 *)node + 0x2C) = *(Fragment17OptionColorWord *)((u8 *)node + 0x28);
            }
        }
        break;
    }
    return 0;
}
/* mkdraft:Fragment17_OptionColorCallback end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_82205C14.s")

extern s16 D_822105F0;
extern s16 D_822105F4;
extern s16 D_822105F6;
extern s16 D_822105F8;
extern s16 D_822105FA;
extern s16 D_822105FC;
extern s16 D_822105FE;
s32 func_82205CE8(s32 arg0, void *arg1) { if (arg0 != 0 && arg0 == 1) { *(s16 *)((u8 *)arg1 + 8) = D_822105F4; *(s16 *)((u8 *)arg1 + 10) = D_822105F6; *(s16 *)((u8 *)arg1 + 12) = D_822105F8; *(s16 *)((u8 *)arg1 + 14) = D_822105FA; *(s16 *)((u8 *)arg1 + 40) = D_822105FC; *(s16 *)((u8 *)arg1 + 42) = D_822105FE; if (D_822105F0 != 2) { *(u16 *)((u8 *)arg1 + 2) |= 2; } else { *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD; } } return 0; }

extern s16 D_822105F0;
extern u8 D_8220D8D2[];
extern s32 func_8220AD10(void);
s32 func_82205D78(s32 arg0, void *arg1) {
    s32 temp_v0;

    temp_v0 = func_8220AD10();
    if ((arg0 != 0) && (arg0 == 1)) {
        if (D_822105F0 == 1) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
            *(s16 *)((u8 *)arg1 + 0x32) =
                *(s16 *)(D_8220D8D2 + temp_v0 * 0x34);
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}

/* mkdraft:func_82205E04 begin */
extern s32 D_8220EB90;
extern u8 D_82210648[];
extern u8 D_82210660[];
typedef struct { s32 unk_0; } unk_func_82205E04_word;



s32 func_82205E04(s32 mode, void *state) {
    s32 value;
    s32 index;
    s32 show;

    index = *(s32 *)((u8 *)state + 0x20);
    value = func_8220AD10();
    switch (mode) {
    case 0:
        ((unk_func_82205E04_word *)D_82210648)[index] =
            *(unk_func_82205E04_word *)((u8 *)state + 0x3C);
        ((unk_func_82205E04_word *)D_82210660)[index] =
            *(unk_func_82205E04_word *)((u8 *)state + 0x40);
        break;
    case 1:
        show = 1;
        // FAKE: a one-case switch on index makes IDO color index into v1;
        // diff score 94 with `if (index == 5)` instead.
        switch (index) {
        case 5:
            if (D_8220EB90 != 0) {
                *(u16 *)((u8 *)state + 2) |= 2;
            } else {
                *(u16 *)((u8 *)state + 2) &= ~2;
                show = 0;
            }
            break;
        }
        if (show != 0) {
            if (value != index) {
                *(unk_func_82205E04_word *)((u8 *)state + 0x3C) =
                    ((unk_func_82205E04_word *)D_82210648)[index];
                *(unk_func_82205E04_word *)((u8 *)state + 0x40) =
                    ((unk_func_82205E04_word *)D_82210660)[index];
            } else {
                *(u8 *)((u8 *)state + 0x3C) = 0;
                *(u8 *)((u8 *)state + 0x3D) = 0x9C;
                *(u8 *)((u8 *)state + 0x3E) = 0xD8;
                *(u8 *)((u8 *)state + 0x40) = 0x34;
                *(u8 *)((u8 *)state + 0x41) = 0x2B;
                *(u8 *)((u8 *)state + 0x42) = 0x87;
            }
        }
        break;
    }
    return 0;
}
/* mkdraft:func_82205E04 end */

/* mkdraft:func_82205F2C begin */
extern void *D_8220DA08;
extern u16 D_8220EB82;
extern u8 D_8220D8D0[];
extern s16 D_8220EB98;

extern void func_800504BC(s16 *);
extern void func_8220510C(void *, s32, s16, s16);
extern void func_822056C0(void *, s32, s16, s16, s32);
extern s32 func_8220AD10(void);
extern s32 func_8220D6AC(void);



s32 func_82205F2C(s32 arg0, u8 *arg1) {
    s32 idx;
    u8 *record;
    s32 pad1[3]; // FAKE: unused; growing the frame from 0x48 to 0x58 bytes also moves counter, flag and
                 //       coords from 0x2C/0x34/0x38 to 0x30/0x38/0x3C; diff score 71 without it.
    s16 *counter;
    s16 coords[2];
    s32 flag;

    idx = *(s32 *)(arg1 + 0x20);
    counter = (s16 *)((u8 *)&D_8220EB98 + idx * 24);
    switch (arg0) {
    case 0:
        *counter = 10;
        *(u8 *)(arg1 + 0x28) = 0x21;
        record = (u8 *)(idx * 52 + 0x30 + (s32)D_8220D8D0);
        *(u8 *)(arg1 + 0x2C) = record[0];
        *(u8 *)(arg1 + 0x2D) = record[1];
        *(u8 *)(arg1 + 0x2E) = record[2];
        *(u16 *)(arg1 + 2) &= 0xFFFD;
        break;
    case 1:
        if (D_8220EB82 & 1) {
            if (func_8220AD10() != idx) {
                if (*counter < 10) {
                    *counter = *counter + 1;
                }
            } else {
                if (*counter > 0) {
                    *counter = *counter - 1;
                }
            }
        }
        func_800504BC(coords);
        coords[0] += *(s16 *)(arg1 + 8);
        coords[1] += *(s16 *)(arg1 + 0xA);
        if (func_8220D6AC() == 0 && *counter < 10) {
            func_8220510C(arg1, idx, coords[0], coords[1]);
        }
        if (*counter <= 0) {
            break;
        }
        flag = *(s16 *)((u8 *)*(void **)((u8 *)D_8220DA08 + 0x20)) != 0;
        if (func_8220D6AC() != 0 && idx == 1) {
            break;
        }
        func_822056C0(arg1, idx, coords[0], coords[1], flag);
        break;
    }
    return 0;
}
/* mkdraft:func_82205F2C end */

extern s32 D_8220EC38;
s32 func_82206124(s32 arg0, void *arg1) { s32 value; s32 result; value = *(s32 *)((u8 *)arg1 + 0x20); result = 0; if (arg0 == 0) goto done; if (arg0 != 1) goto done; switch (D_8220EC38) { case 1: if (value == 0) result = 1; break; case 2: if (value == 1) result = 1; break; default: break; } if (result != 0) *(u16 *)((u8 *)arg1 + 2) |= 2; else *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD; done: return 0; }

/* mkdraft:func_822061A8 begin */
extern u8 D_82210678[];
extern u8 D_82210680[];
typedef union unk_func_822061A8_color {
    u32 word;
    struct {
        u8 r;
        u8 g;
        u8 b;
        u8 a;
    } rgba;
} unk_func_822061A8_color;
u32 func_800060E8(void);


s32 func_822061A8(s32 arg0, void *arg1) {
    u32 flags;
    // Entry index: indexes both color caches and selects a bit of `flags`.
    s32 index;
    s32 changed;
    s32 bit;

    index = *(s32 *)((u8 *)arg1 + 0x20);
    changed = 0;
    flags = func_800060E8();
    switch (arg0) {
    case 0:
        ((unk_func_822061A8_color *)D_82210678)[index] = *(unk_func_822061A8_color *)((u8 *)arg1 + 0x28);
        ((unk_func_822061A8_color *)D_82210680)[index] = *(unk_func_822061A8_color *)((u8 *)arg1 + 0x2C);
        break;
    case 1:
        if (D_8220EC38 == 1) {
            bit = ((flags & 0xFF & (1 << index)) != 0);
            if (bit != 0) {
                // The selected entry (index at +2 of D_8220DA08->[0x20]) is yellow.
                if (index == *(s16 *)((u8 *)*(void **)((u8 *)D_8220DA08 + 0x20) + 2)) {
                    ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.r = 0xFF;
                    ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.g = 0xFF;
                    ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.b = 0;
                    ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.a = 0xFF;
                    *(unk_func_822061A8_color *)((u8 *)arg1 + 0x2C) = *(unk_func_822061A8_color *)((u8 *)arg1 + 0x28);
                } else {
                    *(unk_func_822061A8_color *)((u8 *)arg1 + 0x28) = ((unk_func_822061A8_color *)D_82210678)[index];
                    *(unk_func_822061A8_color *)((u8 *)arg1 + 0x2C) = ((unk_func_822061A8_color *)D_82210680)[index];
                }
            } else {
                // Entries without a mask bit are gray.
                ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.r = 0x80;
                ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.g = 0x80;
                ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.b = 0x80;
                ((unk_func_822061A8_color *)((u8 *)arg1 + 0x28))->rgba.a = 0xFF;
                *(unk_func_822061A8_color *)((u8 *)arg1 + 0x2C) = *(unk_func_822061A8_color *)((u8 *)arg1 + 0x28);
            }
            changed = 1;
        }
        // Bit 1 of the u16 at +2 is set by every sibling callback that keeps the node drawn.
        if (changed != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
        break;
    }
    return 0;
}
/* mkdraft:func_822061A8 end */

typedef union unk_func_82206304_color {
    u32 word;
    struct {
        u8 r;
        u8 g;
        u8 b;
        u8 a;
    } rgba;
} unk_func_82206304_color;
extern u8 D_82210688[];
extern u8 D_82210698[];
s32 func_82206304(s32 arg0, u8 *arg1) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = *(s32 *)(arg1 + 32);
    var_v1 = 0;
    switch (arg0) {
    case 0:
        ((unk_func_82206304_color *)D_82210688)[var_v0] = *(unk_func_82206304_color *)(arg1 + 40);
        ((unk_func_82206304_color *)D_82210698)[var_v0] = *(unk_func_82206304_color *)(arg1 + 44);
        break;
    case 1:
        if (D_8220EC38 == 2) {
            var_v1 = 1;
            if (var_v0 == *(s16 *)((u8 *)*(void **)((u8 *)D_8220DA08 + 32) + 4)) {
                ((unk_func_82206304_color *)(arg1 + 40))->rgba.r = 0xFF;
                ((unk_func_82206304_color *)(arg1 + 40))->rgba.g = 0xFF;
                ((unk_func_82206304_color *)(arg1 + 40))->rgba.b = 0;
                ((unk_func_82206304_color *)(arg1 + 40))->rgba.a = 0xFF;
                *(unk_func_82206304_color *)(arg1 + 44) = *(unk_func_82206304_color *)(arg1 + 40);
            } else {
                *(unk_func_82206304_color *)(arg1 + 40) = ((unk_func_82206304_color *)D_82210688)[var_v0];
                *(unk_func_82206304_color *)(arg1 + 44) = ((unk_func_82206304_color *)D_82210698)[var_v0];
            }
        }
        if (var_v1 != 0) {
            *(u16 *)(arg1 + 2) |= 2;
        } else {
            *(u16 *)(arg1 + 2) &= 0xFFFD;
        }
        break;
    }
    return 0;
}

/* mkdraft:func_82206400 begin */
u32 func_800060E8(void);

s32 func_82206400(s32 arg0, void *arg1) {
    u32 mask;
    s32 index = *(s32 *)((u8 *)arg1 + 0x20);
    s32 show = 0;

    mask = func_800060E8();
    if ((arg0 != 0) && (arg0 == 1)) {
        if ((D_8220EC38 == 1) &&
            (index == *(s16 *)((u8 *)*(u8 **)((u8 *)D_8220DA08 + 0x20) + 2))) {
            show = 1;
            {
                s32 bit = ((mask & 0xFF & (1 << index)) != 0);
                if (bit != 0) {
                    *(u16 *)(*(u8 **)((u8 *)arg1 + 0x34) + 4) =
                        *(u16 *)(*(u8 **)((u8 *)arg1 + 0x34) + 4) | 1;
                } else {
                    *(u16 *)(*(u8 **)((u8 *)arg1 + 0x34) + 4) =
                        *(u16 *)(*(u8 **)((u8 *)arg1 + 0x34) + 4) & 0xFFFE;
                }
            }
        }
        if (show != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}
/* mkdraft:func_82206400 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_822064DC.s")

extern s32 D_8220EB90;

void func_822067C4(s32 arg0, void *arg1) {
    if ((arg0 != 0) && (arg0 == 1)) {
        if (D_8220EB90 != 0) {
            (*(u16 *)((u8 *)(arg1) + (2))) = (u16) ((*(u16 *)((u8 *)(arg1) + (2))) | 2);
            return;
        }
        (*(u16 *)((u8 *)(arg1) + (2))) = (u16) ((*(u16 *)((u8 *)(arg1) + (2))) & 0xFFFD);
    }
}

extern void func_82204494(s16 *);
extern s16 D_822105E8;
void func_82206804(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        func_82204488(&D_822105E8);
        return;
    case 1:
        func_82204494(&D_822105E8);
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_113A60/func_82206854.s")


#endif
