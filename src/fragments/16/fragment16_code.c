#include "global.h"
#include "controller.h"


#ifdef VERSION_US
// The initializer clears this 0x144-byte state: a 22-byte header,
// a 15-by-20 signed-byte grid, and natural trailing alignment.
//@src/2CA0.c
typedef struct F16State1D58 {
    // State, adjacent control, current selection, target selection.
    s16 controls[4];
    s32 resources[3];
    s16 fill_counter;
    s8 cells[15][20];
} F16State1D58;
static F16State1D58 sState1D58;

extern s32 func_8005633C(void);
extern s32 func_8004D690(s32);
extern u8 D_82001ED6;
extern void _bzero(void *, s32);
void Fragment16_InitGridState(void) {
    F16State1D58 *state = &sState1D58;

    _bzero(&sState1D58, sizeof(sState1D58));
    state->controls[0] = 0;
    state->controls[1] = 0;
    state->controls[2] = D_82001ED6;
    state->controls[3] = func_8005633C();
    state->resources[0] = func_8004D690(0);
    state->resources[1] = func_8004D690(1);
    state->resources[2] = func_8004D690(28);
}
#endif

#ifdef VERSION_US
extern s16 D_82001D58;
extern s16 D_82001D6C;
extern void func_800226C0(s32);
s32 func_82000098(void) {
    s32 ret = 0;
    F16State1D58 *state = &sState1D58;
    if (*(s16 *)((u8 *)&D_82001D58 + 4) < *(s16 *)((u8 *)&D_82001D58 + 6)) {
        state->controls[0] = 1;
        state->controls[1] = 0;
        D_82001D6C = -1;
        ret = 1;
        func_800226C0(350);
    }
    return ret;
}
#endif

#ifdef VERSION_US
/* mkdraft:Fragment16_UpdateGridFill begin */
extern s16 D_82001D58;
extern s16 D_82001D6C;
// Legacy view of controls[2], retaining its existing object symbol.
extern s16 D_82001D5C;
extern u8 D_82001E70[];
extern u8 D_82001ED0[];
typedef struct { s32 a; s32 b; s32 c; s32 d; } Quad800548C4;
extern void func_800548C4(Quad800548C4 *);

// Fill the transition grid; once every cell reaches five, commit the
// target selection to the saved settings and the current state.
void Fragment16_UpdateGridFill(void) {
    s32 found;
    s32 index;
    s32 level;
    s8 *base;
    s8 *p;
    s16 *sel;
    s16 *flag;
    F16State1D58 *state = &sState1D58;

    flag = &D_82001D58;
    if (*flag == 1) {
        found = 1;
        sel = &D_82001D6C;
        if (*sel < 300) {
            *sel = *sel + 1;
        }
        level = 14;
        base = (s8 *)D_82001E70;
        for (; level >= 0; level--) {
            index = 0;
            p = base + 0x16;
            for (; index < 20; index++, p++) {
                if (*sel >= 33 - index - level) {
                    if (*p < 5) {
                        (*p)++;
                    }
                }
                if (*p != 5) {
                    found = 0;
                }
            }
            base -= 0x14;
        }
        if (found != 0) {
            s16 *controls = state->controls;
            s16 selection;
            controls[0] = 0;
            controls[1] = 0;
            selection = controls[3];
            D_82001ED6 = selection;
            D_82001D5C = selection;
            func_800548C4((Quad800548C4 *)D_82001ED0);
        }
    }
}
/* mkdraft:Fragment16_UpdateGridFill end */
#endif

#ifdef VERSION_US
/* mkdraft:func_820001F0 begin */
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern void func_8004657C(void);



void func_820001F0(s16 *arg0) {
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    s32 index;
    s32 alpha;
    s32 step;

    func_8004657C();
    width = 640;
    height = 480;
    step = 32;
    for (y = 0; y < height; y += step) {
        for (x = 0; x < width; x += step) {
            s32 texture;

            index = (y / step) * 20 + (x / step);
            texture = ((s32 *)((u8 *)arg0 + 8))[arg0[3]] + index * 0x200;
            if (((s8 *)arg0)[index + 0x16] == 5) {
                gDPLoadTextureBlock(D_800D0510++, (u8 *)(texture), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(D_800D0510++, x << 2, y << 2, (x + step) << 2, (y + step) << 2, G_TX_RENDERTILE,
                                    0, 0, 0x200, 0x200);
            }
        }
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    for (y = 0; y < height; y += step) {
        for (x = 0; x < width; x += step) {
            s32 texture;

            index = (y / step) * 20 + (x / step);
            texture = ((s32 *)((u8 *)arg0 + 8))[arg0[3]] + index * 0x200;
            alpha = ((s8 *)arg0)[index + 0x16] * 255 / 5;
            if (alpha > 0 && alpha < 255) {
                gDPPipeSync(D_800D0510++);
                gDPSetEnvColor(D_800D0510++, 255, 255, 255, alpha);
                gDPLoadTextureBlock(D_800D0510++, (u8 *)(texture), G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                    G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(D_800D0510++, x << 2, y << 2, (x + step) << 2, (y + step) << 2, G_TX_RENDERTILE,
                                    0, 0, 0x200, 0x200);
            }
        }
    }
}
/* mkdraft:func_820001F0 end */
#endif

#ifdef VERSION_US
extern s16 D_82001D58;
extern void func_800468A0(s32);
extern void func_820001F0(s16 *);
void func_820006B8(void) {
    s16 *base = &D_82001D58;
    s32 *table = (s32 *)((u8 *)base + 8);
    func_800468A0(table[*(s16 *)((u8 *)base + 4)]);
    if (*base == 1) {
        func_820001F0(base);
    }
}
#endif

#ifdef VERSION_US
typedef struct {
    /* 0x00 */ s16 mode;
    /* 0x02 */ u16 flags;
    /* 0x04 */ s16 counter;
    /* 0x06 */ s16 alpha;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
} Fragment16FadeState;
static Fragment16FadeState sFadeState;
extern s16 D_82001EA0;
extern s16 D_82001EA8;
extern s16 D_82001EAA;
extern s32 func_800061EC(void);


s32 func_8200070C(void) {
    Fragment16FadeState *fade = &sFadeState;

    _bzero(&D_82001EA0, 0xC);
    fade->mode = 0;
    fade->counter = 0;
    fade->alpha = 0;
    D_82001EA8 = 0x140;
    if (func_8003514C() == 0) {
        D_82001EAA = 0x178;
    } else {
        D_82001EAA = 0x141;
    }
    if (func_800061EC()) {
        fade->flags |= 1;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/16/fragment16_code/func_82000794.s")
#endif

#ifdef VERSION_US
typedef struct {
    s16 counter;
    s16 alpha;
} Fragment16Fade;
extern s16 D_82001EA0;
extern Fragment16Fade D_82001EA4;
extern s16 D_82001EA6;
extern s16 D_82001EA8;
extern s16 D_82001EAA;
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern u8 D_80094E38[];
extern Gfx *D_800D0510;
void Fragment16_DrawFadingOverlay(void) {
    s32 texture;
    if (D_82001EA0 != 0 && D_82001EA4.alpha > 0) {
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetEnvColor(D_800D0510++, 255, 255, 255, D_82001EA6);
        texture = func_8004C990(0x13D, 0);
        func_8004D19C(D_82001EA8, D_82001EAA, texture, 1, 0);
    }
}
#endif

#ifdef VERSION_US
// Fragment-local overlay fade state; retail .data words at 0x82001EA0. func_82000794
// dispatches on mode and steps counter each frame; Fragment16_DrawFadingOverlay draws
// the overlay quad with alpha as the env-color alpha. The initializer is dead at
// runtime: func_8200070C bzeroes 12 bytes at this address during fragment setup.
static Fragment16FadeState sFadeState = { 1536, 1920, 1280, 1940, 1536, 1952 };
// IDO pads this object's .data section to 16 bytes, so the retail word at
// 0x82001EAC (D_82001EAC, the old data-blob head) is carried here: the C-owned
// range must be one full aligned section or the following blob shifts 4 bytes.
// func_82000DE8 and func_82001A78 clear/read it as one word; func_8200182C
// reads it alongside the fade-state fields.
static s16 sFadeStateTail[2] = { 1280, 1944 };

// Starts fade sequence mode 1: the screen is held clear, then instantly covered (the
// mode-1 exit in func_82000794 sets alpha = 255, flags bit 1, and mode 2).
void func_82000CB0(void) {
    Fragment16FadeState *fade = &sFadeState;
    if (fade->flags & 1) {
        fade->mode = 1;
        fade->counter = 0;
        fade->alpha = 0;
    }
}
#endif

#ifdef VERSION_US
// Requires the Fragment16FadeState typedef and sFadeState definition spliced with
// func_82000CB0 (do not duplicate them here: cfe rejects the redeclaration).

// Starts fade sequence mode 3: the overlay alpha pulses, and once it reaches 255 after
// the sequence length, func_82000794 enters mode 4, which ramps the overlay back to clear.
void func_82000CE0(void) {
    Fragment16FadeState *fade = &sFadeState;
    if (fade->flags & 1) {
        fade->mode = 3;
        fade->counter = 0;
        fade->alpha = 0;
    }
}
#endif

#ifdef VERSION_US
s32 func_82000D10(s32 arg0, u8 *arg1) {
    if (arg0 == 0) {
        arg1[0x28] = 0x21;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 D_82001EB8;
extern s16 D_82001EBC;
extern s16 D_82001EBE;

s32 func_82000D24(s32 arg0, void *arg1) {
    if (arg0 == 0) {
        (*(s16 *)((u8 *)(&D_82001EB8) + (0))) = (s16) (*(s16 *)((u8 *)(arg1) + (8)));
        (*(s16 *)((u8 *)(&D_82001EB8) + (2))) = (s16) (*(s16 *)((u8 *)(arg1) + (0xA)));
        D_82001EBC = (*(s16 *)((u8 *)(arg1) + (0xC)));
        D_82001EBE = (*(s16 *)((u8 *)(arg1) + (0xE)));
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s16 D_82001EC0;

s32 func_82000D64(s32 arg0, void *arg1) {
    if (arg0 == 0) {
        D_82001EC0 = (*(s16 *)((u8 *)(arg1) + (0xA)));
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_82000D80(s32 arg0, void *arg1) {
    switch (arg0) {                                 /* irregular */
    case 1:
        break;
    case 0:
        if (func_800033A8() != 0) {
            (*(u16 *)((u8 *)(arg1) + (2))) = (u16) ((*(u16 *)((u8 *)(arg1) + (2))) | 2);
        } else {
            (*(u16 *)((u8 *)(arg1) + (2))) = (u16) ((*(u16 *)((u8 *)(arg1) + (2))) & 0xFFFD);
        }
        break;
    }
    return 0;
}
#endif
