#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void* PokeIcon_AllocLoadContext(s32 arg0);
extern void PokeIcon_InitResourceArchives(void);
extern u16* func_80042C68(void* arg0, s32 arg1, s32 arg2);
extern u16* D_8F000924;
extern s32 D_8F00092C;
extern s32 D_8F000920;

void func_8F000020(s32 arg0) {
    void* var_v0;

    var_v0 = PokeIcon_AllocLoadContext(5);
    PokeIcon_InitResourceArchives();
    D_8F000924 = func_80042C68(var_v0, 128, 128);
    *D_8F000924 &= 0xFEFF;
    D_8F00092C = 0;
    D_8F000920 = 0;
    if (arg0 != 0) {
        D_8F000920 = arg0 - 1;
    }
}

/* mkdraft:func_8F000098 begin */
extern void Font_EnableTwoCycleTexturing(void);
extern void Font_DisableTwoCycleTexturing(void);
extern void func_80049064(s32 arg0, s32 arg1, s32 arg2, const char *arg3);
extern void func_800495F8(s32 arg0, s32 arg1, s32 arg2, const char *arg3, ...);
extern void func_800496A4(s32 arg0, s32 arg1);
extern void func_8004972C(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800497E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern s16 D_8F0008F0;
extern s32 D_8F000914;

// Per-frame draw of the 16-entry selection list. D_8F0008F0 supplies the string archive 0x42
// entry id of each row; index / 10 selects the column (x = column * 320 + 160) and index % 10 the
// row (y = row * 26 + 70). The row equal to D_8F000920, the index func_8F000524 moves with 0..15
// wrap, is drawn yellow instead of white. C-up toggles D_8F000914.


void func_8F000098(void) {
    // FAKE: only this pointer local produces the target's `lui t9; lw t9; lui at; sw t0,lo(at)`
    // address materialization; the direct `D_8F000914 ^= 1` writes `lui v0; addiu v0; lw; sw` and
    // scores 225.
    s32 *D_8F000914_ptr = &D_8F000914;
    s16 *entry_id;
    const char *text;
    s32 index;

    if (D_80087200->buttonsPressed & U_CBUTTONS) {
        (*D_8F000914_ptr) ^= 1;
    }
    func_800498C4();
    func_800496A4(16, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0, 0, 0xFF, 0xFF);
    func_800495F8(320, 40, 1, func_8004C874(0x42, 0));
    Font_DisableTwoCycleTexturing();
    for (index = 0, entry_id = &D_8F0008F0; index != 16; index++, entry_id++) {
        text = func_8004C874(0x42, *entry_id);
        if (index == D_8F000920) {
            func_8004972C(0xFF, 0xFF, 0, 0xFF);
        } else {
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        }
        func_80049064(((index / 10) * 320) + 160, ((index % 10) * 26) + 70, 1, text);
    }
    func_800499EC();
}
/* mkdraft:func_8F000098 end */

extern Gfx* D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_8F000918;
extern s32 D_8F00091C;
extern s32 D_8F000928;
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);

/*
 * Draws the scrolling background: the 128x128 RGBA16 image at D_8F000928 (set each frame from
 * func_80043678 in func_8F00068C) is loaded as eight 128x16 bands of 4 KiB each, and every band
 * is drawn in a 5x5 grid of rectangles spaced 128 pixels apart. D_8F000918 is the horizontal
 * texture offset in texels (+1 per frame, wraps at 128); D_8F00091C is the vertical screen
 * offset (-1 per frame, reset to 0 below -127).
 */
void func_8F000284(void) {
    s32 band;
    s32 band_y;
    s32 row;
    u32 column; // FAKE: unsigned column counter; diff score 1250 without it.
    s32 scroll_s;
    s32 scroll_y;

    gSPDisplayList(D_800D0510++, D_80094E38);
    for (band = 0, band_y = 0; band < 8; band++, band_y += 16) {
        for (row = 0; row < 640; row += 128) {
            for (column = 0; column < 640; column += 128) {
                if (column == 0 && row == 0) {
                    gDPLoadTextureBlock(D_800D0510++, D_8F000928 + (band << 12), G_IM_FMT_RGBA, G_IM_SIZ_16b, 128,
                                        16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 7, G_TX_NOMASK,
                                        G_TX_NOLOD, G_TX_NOLOD);
                }
                scroll_y = D_8F00091C;
                scroll_s = D_8F000918;
                GfxRect_DrawTextured(column, row + scroll_y + band_y, 128, 16, scroll_s << 5, 0, 1024, 1024, 0);
            }
        }
    }
    scroll_s = D_8F000918 + 1;
    D_8F000918 = scroll_s;
    if (scroll_s >= 128) {
        D_8F000918 = 0;
    }
    scroll_y = D_8F00091C - 1;
    D_8F00091C = scroll_y;
    if (scroll_y < -127) {
        D_8F00091C = 0;
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}


extern void func_80008648();
extern void BgStage_DrawFrame();
extern void func_8F000098();
extern void func_8F000284();

void func_8F0004EC(void) {
    BgStage_DrawFrame();
    func_8F000284();
    func_8F000098();
    func_80008648();
}

extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
extern void func_800226C0(s32);

s32 func_8F000524(s32 incoming) {
    s32 state = incoming;
    s32 previous = D_8F000920;
    s32 leaving = 0;

    switch (incoming) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            state = 1;
        }
        break;
    case 1:
        if (D_80087200->buttonsRepeat & 0x800) {
            if (--D_8F000920 < 0) {
                D_8F000920 = 15;
            }
        }
        if (D_80087200->buttonsRepeat & 0x400) {
            if (++D_8F000920 >= 16) {
                D_8F000920 = 0;
            }
        }
        if (previous != D_8F000920) {
            func_800226C0(1);
        }
        if (D_80087200->buttonsPressed & 0x8000) {
            leaving = 1;
            func_800226C0(2);
        } else if (D_80087200->buttonsPressed & 0x4000) {
            D_8F000920 = -1;
            leaving = 1;
            func_800226C0(3);
        }
        if (leaving) {
            state = 2;
            StageFade_StartFromTransparent(5);
        }
        break;
    case 2:
        if (StageContext_GetFadeMode() == 1) {
            state = 3;
        }
        break;
    }
    return state;
}

/* Raw six-byte state at offset 0x1E of the node behind object offset 0x1C. */
typedef struct F68SavedVector {
    u16 values[3];
} F68SavedVector;
extern s32 D_8F000910;
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern s32 func_80042FBC(void *, s32);
extern void func_80064D28(void);
extern s32 func_80043064(void*);
extern s32 func_80043678(void*);

void func_8F00068C(void) {
    s32 state = 0;
    s32 remaining;
    F68SavedVector saved;

    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        saved = *(F68SavedVector*)(*(u8**)((u8*)D_8F000924 + 0x1C) + 0x1E);
        remaining = D_8F00092C;
        if (remaining == 0) {
            D_8F00092C = 150;
            func_80042FBC(D_8F000924, D_8F000910);
            if (++D_8F000910 >= 252) {
                D_8F000910 = 0;
            }
        } else {
            D_8F00092C = remaining - 1;
        }
        func_80064D28();
        if (func_80043064(D_8F000924)) {
            *(F68SavedVector*)(*(u8**)((u8*)D_8F000924 + 0x1C) + 0x1E) = saved;
        }
        D_8F000928 = func_80043678(D_8F000924);
        func_8F0004EC();
        state = func_8F000524(state);
    } while (state != 3);
}

s32 func_8F0007C8(void) {
    s32 result = 0;
    if (D_8F000920 >= 0) result = D_8F000920 + 1;
    return result;
}

extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern s32 func_8004C09C(s32);
extern s32 func_8004C4B0(s32);
extern u8* func_80047588(s32, s32);
extern u8* Asset_LoadToSegment(s32, u8*, u8*, s32);
extern u8 D_1000000[], D_446E30[], D_447D00[];
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);

/* Both incoming words have stack homes in the original entry-point ABI. */
s32 fragment68_main(s32 selection, s32 unused) {
    s32 configuration;

    main_pool_push_state(0x4442534C);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    configuration = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(3);
    func_8004C4B0(0x42);
    func_80047588(0x1B, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_80006148(D_80087200);
    func_8F000020(selection);
    func_80008514(configuration);
    func_8F00068C();
    func_80008574();
    func_80006158();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4442534C);
    return func_8F0007C8();
}
#endif
