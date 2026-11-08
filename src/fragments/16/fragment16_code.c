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

void func_82000DE0(void) {
}

#ifdef VERSION_US
extern void *D_82001CD0;
extern s32 D_82001CD4;
extern s32 D_82001D50;
extern s32 D_82001EB0;
extern s32 D_82001EB4;
extern s32 D_82001EC4;
extern s32 D_82001EC8;
extern s32 D_82001EAC;
extern void *BinArchive_Open(s32, s32, s32, s32);
extern s32 MainPool_AllocState(s32, s32);
extern s32 MainPool_FinalizeAllocation(s32);
extern s32 func_80001FF0(void);
extern s32 func_800356CC(s32);
extern s32 func_8004DC6C(s32, s16 *);
extern s32 func_8004DCFC(s32, s32);
extern s32 func_8004E308(s32, s32 (*)(s32, u8 *), s32);
extern void *func_8004EB58(s32, s32);
extern s32 func_8005049C(void *, s32);
extern void Fragment16_InitGridState(void);
extern s32 func_8200070C(void);
extern s32 main_pool_get_available(void);

// Fragment 16 (title screen) setup. Resets the menu state words, sets the
// version-stamp delay D_82001D50 to half the current VI count plus 10, and
// zeroes the layout dims at D_82001EB8/D_82001EBC..D_82001EC0. Opens UI
// window config 0xA1; when that succeeds, func_82000DE8 stores its handle,
// finalizes a main-pool allocation for D_82001CD0, and registers the
// title/kuro/moji/EXPA archive callbacks func_82000D10/D24/D64/D80 through
// func_8004E308. Finishes by resetting the fade state (func_8200070C) and
// caching resource 0x10's word at offset 0xC in D_82001EB4.
void func_82000DE8(void) {
    s32 sp20;
    s32 temp_v0;
    s32 sp1C;
    s32 temp_v0_2;

    Fragment16_InitGridState();
    D_82001CD4 = 0;
    func_82000DE0();
    D_82001EC4 = 0;
    D_82001EC8 = 0;
    D_82001EAC = 0;
    D_82001EB0 = 0;
    D_82001D50 = (func_80001FF0() / 2) + 0xA;
    (*(s16 *)((u8 *)(&D_82001EB8) + (2))) = 0;
    D_82001EBE = 0;
    (*(s16 *)((u8 *)(&D_82001EB8) + (0))) = (s16) (*(s16 *)((u8 *)(&D_82001EB8) + (2)));
    D_82001EBC = D_82001EBE;
    D_82001EC0 = 0x170;
    D_82001CD0 = NULL;
    temp_v0 = func_8004DC6C(0xA1, &D_82001EBE);
    if (temp_v0 != 0) {
        sp20 = temp_v0;
        func_8004DCFC(temp_v0, 0);
        temp_v0_2 = MainPool_AllocState(main_pool_get_available(), 0);
        sp1C = temp_v0_2;
        D_82001CD0 = func_8004EB58(temp_v0_2, sp20);
        MainPool_FinalizeAllocation(sp1C);
        func_8004E308(func_8005049C(D_82001CD0, 0x7469746C), func_82000D10, 0);
        func_8004E308(func_8005049C(D_82001CD0, 0x6B75726F), (s32 (*)(s32, u8 *)) func_82000D24, 0);
        func_8004E308(func_8005049C(D_82001CD0, 0x6D6F6A69), (s32 (*)(s32, u8 *)) func_82000D64, 0);
        func_8004E308(func_8005049C(D_82001CD0, 0x45585041), (s32 (*)(s32, u8 *)) func_82000D80, 0);
    }
    func_8200070C();
    D_82001EB4 = (*(s32 *)((u8 *)(BinArchive_Open(func_800356CC(0x10), 0, 1, 1)) + (0xC)));
}
#endif

#ifdef VERSION_US
typedef struct {
    u8 r;
    u8 g;
    u8 b;
} Fragment16Color;
extern s32 D_82001EB0, D_82001EB4;
extern s32 D_82001EAC;
extern s32 D_82001CD4;
extern s16 D_82001C10[];
extern Fragment16Color D_82001CF0, D_82001CF4, D_82001CF8, D_82001CFC;
extern char D_82001D10[], D_82001D24[], D_82001D2C[];
extern void *func_8004C874(s32, s32);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800495BC(s32, s32, const char *, ...);
extern s32 func_80049148(s32, s32, const char *, ...);
extern void Ui_DrawGradientPanel(s32, s32, s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_800226C0(s32);
extern void _bcopy(const void *, void *, s32);
void Fragment16_DrawVersionStamp(void) {
    s8 month[4];
    s8 day[4];
    s8 hour[4];
    s8 minute[4];

    _bcopy((u8 *)(u32)D_82001CD4, month, 2);
    if (month[0] == '0') {
        month[0] = month[1];
        month[1] = 0;
    }
    month[2] = 0;
    _bcopy((u8 *)(u32)D_82001CD4 + 2, day, 2);
    if (day[0] == '0') {
        day[0] = day[1];
        day[1] = 0;
    }
    day[2] = 0;
    _bcopy((u8 *)(u32)D_82001CD4 + 4, hour, 2);
    hour[2] = 0;
    _bcopy((u8 *)(u32)D_82001CD4 + 6, minute, 2);
    minute[2] = 0;
    func_800496A4(0x10, 0);
    func_8004972C(255, 255, 255, 255);
    func_800495F8(600, 50, 2, D_82001D10, month, day, hour, minute);
}
#endif

#ifdef VERSION_US
void Fragment16_DrawSelectionList(void) {
    s32 i;
    Fragment16Color top = D_82001CF0;
    Fragment16Color bottom = D_82001CF4;
    s16 *entry;
    s32 y;

    Ui_DrawGradientPanel(100, 30, 300, 420, (s32)&top, (s32)&bottom);
    func_800498C4();
    func_800496A4(8, 0);
    for (i = 0, entry = D_82001C10, y = 50; i < 19; i++, entry++, y += 20) {
        if (i == D_82001EAC) {
            func_8004972C(255, 255, 0, 255);
        } else {
            func_8004972C(255, 255, 255, 255);
        }
        func_800495BC(120, y, func_8004C874(0x42, *entry));
    }
    func_800499EC();
}
#endif

#ifdef VERSION_US
void Fragment16_DrawSelectionPopup(void) {
    char *name;
    char buffer[0x80];
    s32 width;

    name = func_8004C874(0x16, D_82001EB0 + 1);
    {
        Fragment16Color top = D_82001CF8;
        Fragment16Color bottom = D_82001CFC;
        if (name != NULL) {
            sprintf(buffer, D_82001D24, D_82001EB0, name);
        } else {
            sprintf(buffer, D_82001D2C, D_82001EB0);
        }
        width = func_80049148(8, 0, buffer);
        Ui_DrawGradientPanel(140, 140, width + 40, 60, (s32)&top, (s32)&bottom);
        func_800498C4();
        func_800496A4(8, 0);
        func_8004972C(255, 255, 255, 255);
        if (name != NULL) {
            func_800495BC(160, 160, buffer);
        } else {
            func_800495BC(160, 160, buffer);
        }
        func_800499EC();
    }
}
#endif

#ifdef VERSION_US
void func_82001304(void) {
    func_800498C4();
    if (D_82001CD4 != 0) {
        Fragment16_DrawVersionStamp();
    }
    func_800499EC();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/16/fragment16_code/func_82001344.s")
#endif

#ifdef VERSION_US
extern void *D_82001CD0;
extern s32 D_82001EC4;
extern s32 D_82001EC8;
extern s32 func_8006D268(s32);
extern void BgStage_DrawFrame(void);
extern void func_800503A4(void *);
extern void Fragment16_DrawFadingOverlay(void);
extern void func_82001344(void);
extern void Fragment16_DrawSelectionList(void);
extern void Fragment16_DrawSelectionPopup(void);
extern void func_82001304(void);
extern void func_80008648(void);
extern void func_820006B8(void);
void func_820014C4(void) {
    BgStage_DrawFrame();
    if (func_8006D268(0x202) != 0 && ((D_80087200->buttonsPressed) & 4) != 0) {
        (*(s16 *)((u8 *)&D_82001D58 + 4)) =
            (s16)((*(s16 *)((u8 *)&D_82001D58 + 4) + 1) % 3);
    }
    func_820006B8();
    func_800503A4(D_82001CD0);
    Fragment16_DrawFadingOverlay();
    func_82001344();
    if (D_82001EC4 != 0) {
        Fragment16_DrawSelectionList();
    }
    if (D_82001EC8 != 0) {
        Fragment16_DrawSelectionPopup();
    }
    func_82001304();
    func_80008648();
}
#endif

#ifdef VERSION_US
s32 Fragment16_HandleSelectionInput(void) {
    s32 result = 0;
    s32 previousSelection = D_82001EB0;
    if ((D_80087200->buttonsRepeat) & 0x200) {
        D_82001EB0--;
        if (D_82001EB0 < 0) {
            D_82001EB0 = D_82001EB4 - 1;
        }
    }
    if ((D_80087200->buttonsRepeat) & 0x100) {
        D_82001EB0++;
        if (D_82001EB0 >= D_82001EB4) {
            D_82001EB0 = 0;
        }
    }
    if (previousSelection != D_82001EB0) {
        func_800226C0(1);
    }
    if ((D_80087200->buttonsPressed) & 0x8000) {
        result = 1;
        func_800226C0(2);
    }
    if ((D_80087200->buttonsPressed) & 0x4000) {
        result = -1;
        func_800226C0(3);
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 func_80025D44(void);
s32 func_82001688(void) {
    s32 result = 0;
    if (func_80025D44() == 0) {
        result = 1;
    } else if (func_8006D268(0x201) != 0 && ((D_80087200->buttonsPressed) & 2) != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u16 D_82001EA2;
s32 Fragment16_HandleListInput(void) {
    s32 result = 0;
    s32 previousSelection;

    if ((D_82001EA2 & 2) || D_82001EC4 != 0) {
        if (D_82001EC4 != 0) {
            previousSelection = D_82001EAC;
            if ((D_80087200->buttonsRepeat) & 0x800) {
                if (--D_82001EAC < 0) {
                    D_82001EAC = 18;
                }
            }
            if ((D_80087200->buttonsRepeat) & 0x400) {
                if (++D_82001EAC >= 19) {
                    D_82001EAC = 0;
                }
            }
            if (previousSelection != D_82001EAC) {
                func_800226C0(1);
            }
        }
        if ((D_80087200->buttonsPressed) & 0x9000) {
            result = 1;
            func_800226C0(0x32);
        }
    }
    if (result == 0) {
        if (func_82001688() != 0) {
            result = -1;
            D_82001EAC = -1;
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_8200180C(void) {
    s32 result = 0;
    if (D_82001D58 == 0) result = 1;
    return result;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8200182C begin */
// Dispatches the fragment16 sequence: mode 0/1 run the intro handlers
// (func_82000098/func_8200180C, entering mode 2 on completion), mode 2 runs
// the list/selection input handlers (case 4's body sits before case 3's in the
// source because IDO lays case bodies out in source order and retail has
// func_82001590's body at 0x8200193C, before func_82001590-of-D_82001EA0's
// check at 0x82001988), and modes 3/5 finish the sequence through the fade.
// Case numbers are the jump-table targets of jtbl_82001D30.
// func_820016EC / func_82001590 are the linker aliases of
// Fragment16_HandleListInput / Fragment16_HandleSelectionInput
// (linker_scripts/us/aliases.ld); the alias spelling is used because the
// retail relocation symbols carry those names.
extern u8 D_82001C38[];
extern s32 D_82001EAC;
extern s32 func_820016EC();
extern s32 func_82001590();

s32 func_8200182C(s32 arg0) {
    s32 var_s0;
    u8 *temp_v0_3;
    s32 temp_v0;

    var_s0 = arg0;
    switch (arg0) {
        case 0:
            if (!StageContext_GetFadeMode()) {
                if (func_82000098()) {
                    var_s0 = 1;
                } else {
                    var_s0 = 2;
                    func_82000CB0();
                }
            }
            break;
        case 1:
            if (func_8200180C()) {
                var_s0 = 2;
                func_82000CB0();
            }
            break;
        case 2:
            switch (func_820016EC()) {
                case 1:
                    temp_v0_3 = (u8 *)(&D_82001C38) + (D_82001EAC << 3);
                    var_s0 = (*(s32 *)((u8 *)(temp_v0_3) + (4)));
                    switch (var_s0) {
                        case 5:
                            var_s0 = 3;
                            func_82000CE0();
                            break;
                        case 4:
                            D_82001EC8 = 1;
                            break;
                    }
                    break;
                case -1:
                    var_s0 = 5;
                    StageContext_SetClearColor(1);
                    StageFade_StartFromTransparent(5);
                    func_80035424(15);
                    break;
            }
            break;
        case 4:
            temp_v0 = func_82001590();
            if (temp_v0 == 1) {
                var_s0 = 5;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(5);
                func_80035424(15);
            } else if (temp_v0 == -1) {
                var_s0 = 2;
                D_82001EC8 = 0;
            }
            break;
        case 3:
            if (D_82001EA0 == 5) {
                var_s0 = 5;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(5);
                func_80035424(15);
            }
            break;
        case 5:
            if (StageContext_GetFadeMode() == 1) {
                var_s0 = 6;
            }
            break;
    }
    return var_s0;
}
/* mkdraft:func_8200182C end */
#endif

#ifdef VERSION_US
extern void Fragment16_UpdateGridFill();
extern void func_82000794();
extern void func_820014C4();
s32 func_8200182C(s32);
extern s32 D_82001D50;
void func_820019EC(void) {
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        Fragment16_UpdateGridFill();
        func_82000794();
        func_820014C4();
        if (D_82001D50 != 0) {
            D_82001D50 -= 1;
        }
        temp_v0 = func_8200182C(var_s1);
        var_s1 = temp_v0;
    } while (temp_v0 != 6);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82001A78 begin */
extern s32 D_82001EAC;
extern s32 D_82001EB0;
extern s32 D_82001EC4;
s32 func_82001A78(void) {
    s32 result;

    if (D_82001EC4 != 0) {
        result = (D_82001EAC & 0xFF) << 8;
        result |= 2;
        result |= (D_82001EB0 & 0xFF) << 16;
    } else if (D_82001EAC == -1) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
/* mkdraft:func_82001A78 end */
#endif

#ifdef VERSION_US
extern u8 D_82001ED0[];
extern u8 D_1000000[];
extern u8 D_446E30[], D_447D00[];
extern s32 func_82001A78(void);
extern void func_82000DE8(void);
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern s32 func_80055948(s32);
extern void func_8005487C(void *);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern void *StageContext_Allocate(s8, s8, s8, s8, s8, s32);
extern s32 func_8004C09C(s32);
extern void func_8004C4B0(s32);
extern s32 func_8004C8C0(u16);
extern u8 *func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_80051D64(s32, s32);
extern s32 func_80055028(void);
s32 fragment16_main(s32 arg0, s32 arg1) {
    s32 context;

    main_pool_push_state(0x5449544C);
    func_80055948(3);
    func_8005487C(D_82001ED0);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    context = (s32)StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(0x107);
    func_8004C4B0(0x16);
    func_8004C4B0(0x41);
    func_8004C4B0(0x42);
    func_8004C8C0(0x13D);
    func_80047588(0x18, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_82000DE8();
    func_80008514(context);
    func_820019EC();
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    func_80051D64(0x14, 0);
    func_80055028();
    main_pool_pop_state(0x5449544C);
    return func_82001A78();
}
#endif
