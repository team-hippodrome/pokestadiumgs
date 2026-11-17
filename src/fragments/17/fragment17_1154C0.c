#include "global.h"

#ifdef VERSION_US
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

extern s32 func_8220D67C(void);

// Slide-in offset for an option node: case 0 records the node's base position
// and resets the offset; case 1 slides it down 0x30 per frame (when
// func_8220D67C allows) up to 0x1E0 and applies it to the node.
s32 func_82205C14(s32 arg0, s16 *arg1) {
    static s16 sX;
    static s16 sY;
    static struct { s16 x; s16 y; } sBase;
    s16 t;

    switch (arg0) {
    case 0:
        sX = 0;
        sBase.x = arg1[4];
        sBase.y = arg1[5];
        sY = 0;
        break;
    case 1:
        if (func_8220D67C() != 0 && sY < 0x1E0) {
            sY += 0x30;
            if (sY >= 0x1E0) {
                sY = 0x1E0;
            }
        }
        arg1[4] = sX + sBase.x;
        arg1[5] = sY + sBase.y;
        break;
    }
    return 0;
}

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

extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern f32 D_8220DBB8[];
extern s32 D_8220EC38;
extern void *D_8220DA08;
extern s32 func_8004C990(s32, s32);
extern s32 func_80050640(u8 *);
extern s32 func_8004D1FC(u8 *);



s32 func_822064DC(s32 arg0, void *arg1) {
    s32 show;
    s32 index;
    u16 *texture;
    f32 width;
    f32 bias; // FAKE: unused stack slot; declaration order maps slot n to 0x54 - 4*n, so it takes sp+0x44 and keeps scale at sp+0x40. Diff score 11 without it.
    f32 scale;
    s32 draw_width;
    s32 draw_height;
    s32 x;
    s32 y;
    f32 step;

    index = *(s32 *)((u8 *)arg1 + 0x20);
    show = 0;
    switch (arg0) {
    case 0:
        *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        break;
    case 1:
        if ((D_8220EC38 == 2) &&
            (index == *(s16 *)((u8 *)*(u8 **)((u8 *)D_8220DA08 + 0x20) + 4))) {
            show = 1;
        }
        if (show != 0) {
            texture = (u16 *)func_8004C990(*(u16 *)((u8 *)arg1 + 0x24),
                                           func_80050640(*(u8 **)((u8 *)arg1 + 0x34)));
            scale = D_8220DBB8[index];
            if ((texture != NULL) && (scale > 0.0f)) {
                width = (f32)(u32)texture[0] * scale;
                draw_width = (s32)(width + ((width > 0.0f) ? 0.5f : -0.5f));
                draw_height = (s32)((f32)(u32)texture[1] * scale + (((f32)(u32)texture[1] * scale > 0.0f) ? 0.5f : -0.5f));
                x = (s32)(texture[0] - draw_width) / 2;
                y = (s32)(texture[1] - draw_height) / 2;
                gSPDisplayList(D_800D0510++, D_80094E38);
                func_8004D1FC((u8 *)texture);
                step = 1024.0f / scale;
                GfxRect_DrawTextured((s16)(*(s16 *)((u8 *)arg1 + 8) + x),
                                     (s16)(*(s16 *)((u8 *)arg1 + 0xA) + y),
                                     (s16)draw_width, (s16)draw_height, 0, 0,
                                     (s32)(step + ((step > 0.0f) ? 0.5f : -0.5f)),
                                     (s32)(step + ((step > 0.0f) ? 0.5f : -0.5f)), 0);
            }
        }
        break;
    }
    return 0;
}

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

/* The 0x18-byte scene record at 0x8220EB80 that func_82206854 clears; the other
 * functions reach its fields through D_8220EB82, D_8220EB88 and D_8220EB90.
 * linker_scripts/us/datamig_bss.ld pins this object's .data there.
 * IDO's assembler gives two stores one lui only when the symbol is defined in
 * this file, and the original uses three symbols: the stores to +0xC and +0x10
 * get their own luis. FAKE: the one-element arrays, indexed by a variable, keep
 * IDO from loading each address into a base register. */
typedef struct F17SceneHeader {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 flags; // bit 0 is tested by func_82205F2C and func_82208518
    /* 0x04 */ s16 unk_04;
    /* 0x08 */ void *unk_08;
} F17SceneHeader; // size = 0xC

typedef struct F17ScenePair {
    /* 0x00 */ s32 unk_00; // D_8220EB90, tested by func_822067C4
    /* 0x04 */ s32 unk_04;
} F17ScenePair; // size = 0x8

static F17SceneHeader sSceneHeader[1] = { 0 };
static s32 sSceneValue[1] = { 0 };
static F17ScenePair sScenePair[1] = { 0 };

extern void _bzero(void *, s32);
extern s32 func_80054CC4(u8 *, u8 *);

// Clears the scene record, then stores arg0 and arg1/arg2. +0x10 stays zero when
// both arg1 and arg2 are set.
void func_82206854(s32 arg0, s32 arg1, s32 arg2) {
    s32 i = 0; // FAKE: constant index written as a variable (see F17SceneHeader)

    _bzero(sSceneHeader, 0x18);
    sSceneHeader[i].flags = 0;
    sSceneHeader[i].unk_00 = arg0;
    sSceneValue[i] = arg1;
    sScenePair[i].unk_00 = arg1;
    sScenePair[i].unk_04 = arg2;
    if ((arg1 != 0) && (arg2 != 0)) {
        sScenePair[i].unk_00 = 0;
    }
    func_80054CC4((u8 *)*(void **)((u8 *)D_8220DA08 + 0x20) + 8, NULL);
}


#endif
