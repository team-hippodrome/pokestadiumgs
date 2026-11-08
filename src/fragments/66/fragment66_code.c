#include "global.h"
/* Two six-word bounds records used by the event callbacks and renderer. */
typedef struct F66DimensionPair { s32 width, height; } F66DimensionPair;
typedef struct F66OutputBounds {
    s32 left, right, top, bottom;
    F66DimensionPair dimensions;
} F66OutputBounds;
static F66OutputBounds sFirstBounds;
static F66OutputBounds sSecondBounds;

#ifdef VERSION_US
typedef struct F66ViewState {
    s32 value;
    s32 x;
    s32 y;
    s32 unused0C;
    s32 secondX;
    s32 secondY;
} F66ViewState;
typedef struct F66OwnedViewPrefix {
    F66ViewState state;
    s32 dimensions[2];
} F66OwnedViewPrefix;
static F66OwnedViewPrefix sOwnedView = {0};
extern F66ViewState D_82E06138;
extern s32 D_82E0713C;
extern s32 D_82E05650;
extern s32 D_82E07130;
extern s32 D_82E07620[];
extern s32 D_82E077B0[];
extern s32 D_82E07940[];
extern s32 D_82E07AD0[];

typedef struct F66RecView {
    s32 state;
    s32 x;
    s32 adjusted;
    s32 old;
    s32 source;
} F66RecView;

typedef struct F66Timer {
    s32 unk0;
    void *owner;
    s32 time;
} F66Timer;

#ifndef CC_CHECK
struct F66Record;
extern struct F66Record D_82E05968[100];
#define F66_RECS ((F66RecView *)D_82E05968)
#else
#define F66_RECS ((F66RecView *)0)
#endif
#define F66_TIMERS ((F66Timer *)&D_82E07130)



s32 func_82E00020(s32 arg0, u8 *arg1) {
    s32 numerator = 5;
    s32 denominator = 6;
    s32 diff;

    switch (arg0) {
    case 0:
        D_82E07620[*(u32 *)(arg1 + 0x20)] = *(s16 *)(arg1 + 8);
        D_82E077B0[*(u32 *)(arg1 + 0x20)] = *(s16 *)(arg1 + 0xA);
        D_82E07940[*(u32 *)(arg1 + 0x20)] = *(u8 *)(arg1 + 0x28) - 0x80;
        D_82E07AD0[*(u32 *)(arg1 + 0x20)] = 0x80 - *(u8 *)(arg1 + 0x29);
        F66_TIMERS[*(u32 *)(arg1 + 0x20)].time = *(u8 *)(arg1 + 0x2B) + (*(u8 *)(arg1 + 0x2A) << 8);
        F66_RECS[*(u32 *)(arg1 + 0x20)].source = ((*(u8 *)(arg1 + 0x2E) << 8) + *(u8 *)(arg1 + 0x2F))
            - (*(u8 *)(arg1 + 0x2A) << 8) - *(u8 *)(arg1 + 0x2B);
        F66_TIMERS[*(u32 *)(arg1 + 0x20)].owner = arg1;
        if (D_82E05650 == 0) {
            F66_TIMERS[*(u32 *)(arg1 + 0x20)].time = (F66_TIMERS[*(u32 *)(arg1 + 0x20)].time * numerator) / denominator;
            F66_RECS[*(u32 *)(arg1 + 0x20)].source = (F66_RECS[*(u32 *)(arg1 + 0x20)].source * numerator) / denominator;
        }
        *(u16 *)(arg1 + 2) &= 0xFFFE;
        break;
    case 1:
        diff = D_82E07130 - F66_TIMERS[*(u32 *)(arg1 + 0x20)].time;
        if (diff < F66_RECS[*(u32 *)(arg1 + 0x20)].old) {
            if (D_82E05650 != 0) {
                *(s16 *)(arg1 + 8) = D_82E07620[*(u32 *)(arg1 + 0x20)] + (D_82E07940[*(u32 *)(arg1 + 0x20)] * diff) / 10;
                do { *(s16 *)(arg1 + 0xA) = D_82E077B0[*(u32 *)(arg1 + 0x20)] + (D_82E07AD0[*(u32 *)(arg1 + 0x20)] * diff) / 10; } while (0);
                break;
            }
            *(s16 *)(arg1 + 8) = D_82E07620[*(u32 *)(arg1 + 0x20)] + ((D_82E07940[*(u32 *)(arg1 + 0x20)] * diff * denominator) / numerator) / 10;
            do { } while (0);
            *(s16 *)(arg1 + 0xA) = D_82E077B0[*(u32 *)(arg1 + 0x20)] + ((D_82E07AD0[*(u32 *)(arg1 + 0x20)] * diff * denominator) / numerator) / 10;
            break;
        }
        *(u16 *)(arg1 + 2) &= 0xFFFE;
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82E07130;
extern f32 D_80087E50[];
// Depends on the file's existing func_82E00020 declarations: F66RecView,
// F66Timer, D_82E05968, F66_RECS and F66_TIMERS (fragment66_code.c).


s32 func_82E0048C(s32 phase, u8 *memory) {
    s32 diff;
    s32 angle;
    s32 value;
    f32 ratio;

    if (phase != 0 && phase == 1) {
        diff = D_82E07130 - F66_TIMERS[*(u32 *)(memory + 0x20)].time;
        if (diff < F66_RECS[*(u32 *)(memory + 0x20)].x) {
            ratio = (180.0f * (f32)diff / (f32)(F66_RECS[*(u32 *)(memory + 0x20)].x - F66_RECS[*(u32 *)(memory + 0x20)].state) - 90.0f) * 182.0416718f;
            if (ratio >= 0.0f) {
                angle = (s32)(ratio + 0.5f);
            } else {
                angle = (s32)(ratio - 0.5f);
            }
            value = (s32)((D_80087E50[(angle & 0xFFFF) >> 4] * 0.5f + 0.5f) * 255.0f);
        } else if (diff < F66_RECS[*(u32 *)(memory + 0x20)].adjusted) {
            value = 0xFF;
        } else if (diff < F66_RECS[*(u32 *)(memory + 0x20)].old) {
            ratio = (180.0f * (f32)(diff - F66_RECS[*(u32 *)(memory + 0x20)].adjusted) / (f32)(F66_RECS[*(u32 *)(memory + 0x20)].old - F66_RECS[*(u32 *)(memory + 0x20)].adjusted) - 90.0f) * 182.0416718f;
            if (ratio >= 0.0f) {
                angle = (s32)(ratio + 0.5f);
            } else {
                angle = (s32)(ratio - 0.5f);
            }
            value = (s32)(255.0f - (D_80087E50[(angle & 0xFFFF) >> 4] * 0.5f + 0.5f) * 255.0f);
        } else {
            value = 0;
            *(u16 *)(memory + 2) &= 0xFFFE;
        }
        switch (*(u8 *)memory) {
        case 3:
            *(s32 *)(memory + 0x2C) = value | 0xFFFFFF00;
            break;
        case 4:
            *(u8 *)(memory + 0x2B) = value;
            *(u8 *)(memory + 0x2F) = value;
            break;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
/* Same storage as D_82E06138 (aliases.ld), with the callback's coordinate view.
 * Keep the direct scalar store separate from the following structured accesses. */
extern F66ViewState D_82E06138_view;
extern s32 D_82E05650;
s32 func_82E00700(s32 kind, u8* event) {
    switch (kind) {
    case 0:
        switch (*(u32*)(event + 0x20)) {
        case 0:
            D_82E06138.value = event[0x2B] + (event[0x2A] << 8);
            D_82E06138_view.x = *(s16*)(event + 8) - 160;
            D_82E06138_view.y = 120 - *(s16*)(event + 0xA);
            if (D_82E05650 == 0) {
                D_82E06138_view.value = (D_82E06138_view.value * 5) / 6;
            }
            *(u16*)(event + 2) &= 0xFFFE;
            break;
        case 1:
            D_82E06138_view.secondX = *(s16*)(event + 8) - 160;
            D_82E06138_view.secondY = 120 - *(s16*)(event + 0xA);
            *(u16*)(event + 2) &= 0xFFFE;
            break;
        }
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82E075E4;
extern s32 D_82E05650;
extern s32 D_82E07130;
s32 func_82E007F0(s32 arg0, u8 *arg1) {
    switch (arg0) {
    case 0:
        D_82E075E4 = arg1[0x2B] + (arg1[0x2A] << 8);
        if (D_82E05650 == 0) {
            *(s32 *)((u8 *)&D_82E07130 + 0x4B4) = (*(s32 *)((u8 *)&D_82E07130 + 0x4B4) * 5) / 6;
        }
        *(u16 *)(arg1 + 2) &= ~1;
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82E00868 begin */
extern s32 D_82E05650;
extern s32 D_82E05948;
extern s32 D_82E0594C;
extern s32 D_82E05950;
extern s32 D_82E05954;
extern s32 D_82E05958;
extern s32 D_82E05960;
extern s32 D_82E05964;
extern s32 D_82E06144;
extern s32 D_82E06150;
extern s32 D_82E06154;

/* Copy event bounds and dimensions, scaling by 5/6 in the alternate mode.
 * The loader clears the owned runtime records after consuming relocations. */
s32 func_82E00868(s32 kind, void *data) {
    s32 numerator = 5;
    s32 denominator = 6;
    u8 *event = data;
    s32 selector;

    switch (kind) {
    case 0:
        selector = *(s32 *)(event + 0x20);
        switch (selector) {
        case 0:
            sFirstBounds.left = 0;
            sFirstBounds.right = event[0x28];
            sFirstBounds.top = (event[0x2A] << 8) + event[0x2B] - event[0x29];
            sFirstBounds.bottom = event[0x2B] + (event[0x2A] << 8);
            sFirstBounds.dimensions.width = event[0x28];
            sFirstBounds.dimensions.height = event[0x29];
            if (D_82E05650 == 0) {
                sFirstBounds.right = (event[0x28] * numerator) / denominator;
                sFirstBounds.top = (((event[0x2A] << 8) + event[0x2B]) * numerator) / denominator - (event[0x29] * numerator / denominator);
                sFirstBounds.bottom = ((event[0x2B] + (event[0x2A] << 8)) * numerator) / denominator;
                sFirstBounds.dimensions.width = (event[0x28] * numerator) / denominator;
                sFirstBounds.dimensions.height = (event[0x29] * numerator) / denominator;
            }
            break;
        case 1:
            sSecondBounds.left = 0;
            sSecondBounds.right = event[0x28];
            sSecondBounds.top = (event[0x2A] << 8) + event[0x2B] - event[0x29];
            sSecondBounds.bottom = event[0x2B] + (event[0x2A] << 8);
            sSecondBounds.dimensions.width = event[0x28];
            sSecondBounds.dimensions.height = event[0x29];
            D_82E06144 = event[0x2B] + (event[0x2A] << 8);
            sOwnedView.dimensions[0] = event[0x2D] + (event[0x2C] << 8);
            sOwnedView.dimensions[1] = event[0x2F] + (event[0x2E] << 8);
            if (D_82E05650 == 0) {
                sSecondBounds.right = (event[0x28] * numerator) / denominator;
                sSecondBounds.top = (((event[0x2A] << 8) + event[0x2B]) * numerator) / denominator - (event[0x29] * numerator / denominator);
                sSecondBounds.bottom = ((event[0x2B] + (event[0x2A] << 8)) * numerator) / denominator;
                sSecondBounds.dimensions.width = (event[0x28] * numerator) / denominator;
                sSecondBounds.dimensions.height = (event[0x29] * numerator) / denominator;
                D_82E06144 = ((event[0x2B] + (event[0x2A] << 8)) * numerator) / denominator;
                sOwnedView.dimensions[0] = ((event[0x2D] + (event[0x2C] << 8)) * numerator) / denominator;
                sOwnedView.dimensions[1] = ((event[0x2F] + (event[0x2E] << 8)) * numerator) / denominator;
            }
            break;
        }
        *(u16 *)(event + 2) &= 0xFFFE;
        break;
    case 1:
        break;
    }
    return 0;
}
/* mkdraft:func_82E00868 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E00E5C.s")
#endif

#ifdef VERSION_US
extern s32 D_82E0710C, D_82E07110, D_82E07114, D_82E07118, D_82E0711C, D_82E07120, D_82E07124;
s32 func_82E017E0(s32 kind, u8* event) {
    switch (kind) {
    case 0:
        switch (*(u32*)(event + 0x20)) {
        case 0:
            D_82E0710C = *(s16*)(event + 8);
            D_82E07118 = event[0x28];
            break;
        case 1:
            D_82E07110 = *(s16*)(event + 8);
            D_82E0711C = event[0x28];
            break;
        case 2:
            D_82E07114 = *(s16*)(event + 8);
            break;
        case 3:
            D_82E07120 = event[0x28];
            break;
        case 4:
            D_82E07124 = event[0x28];
            break;
        }
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82E05650;
s32 func_82E01898(s32 kind, u8* event) {
    s32 numerator = 5;
    s32 denominator = 6;
    switch (kind) {
    case 0:
        D_82E06138.value = event[0x29] + (event[0x28] << 8);
        D_82E0713C = event[0x2B] + (event[0x2A] << 8);
        if (D_82E05650 == 0) {
            D_82E06138.value = ((event[0x29] + (event[0x28] << 8)) * numerator) / denominator;
            D_82E0713C = ((event[0x2B] * numerator) / denominator) + (event[0x2A] << 8);
        }
        *(u16*)(event + 2) &= 0xFFFE;
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82E07128;
extern s32 D_82E0615C;
s32 func_82E019B0(s32 arg0, u8 *arg1) {
    switch (arg0) {
        case 0:
            D_82E07128 = arg1[0x28];
            D_82E0615C = arg1[0x2B] + (arg1[0x2A] << 8);
            *(u16 *)(arg1 + 2) &= 0xFFFE;
            break;
        case 1:
            break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82E01A00 begin */
extern F66ViewState D_82E06138;
extern s32 D_82E05650;

extern s32 D_82E05954;
extern s32 D_82E05958;
extern s32 D_82E05960;
extern s32 D_82E05964;
extern s32 D_82E06150;
extern s32 D_82E06154;
extern s32 D_82E07108;

/* Initialize the alternate bounds and the view dimensions from node parameters. */
s32 func_82E01A00(s32 kind, u8 *state)
{
  F66OwnedViewPrefix *view = &sOwnedView;
  F66DimensionPair *dimensions = &sSecondBounds.dimensions;
  s32 numerator = 5;
  s32 denominator = 6;
  switch (kind)
  {
    case 0:
      sSecondBounds.left = 0;
      D_82E05954 = state[0x28];
      D_82E05958 = 0xFFFF - state[0x29];
      sSecondBounds.bottom = 0xFFFF;
      dimensions->width = state[0x28];
      dimensions->height = state[0x29];
      D_82E07108 = state[0x2A];
      view->dimensions[0] = state[0x2D] + (state[0x2C] << 8);
      view->dimensions[1] = state[0x2F] + (state[0x2E] << 8);
      D_82E06138.unused0C = 0xFFFF;
      if (D_82E05650 == 0)
    {
      D_82E05954 = (state[0x28] * numerator) / denominator;
      D_82E05958 = 0xFFFF - ((state[0x29] * numerator) / denominator);
      sSecondBounds.bottom = 0xFFFF;
      dimensions->width = (state[0x28] * numerator) / denominator;
      dimensions->height = (state[0x29] * numerator) / denominator;
      D_82E07108 = (state[0x2A] * denominator) / numerator;
      view->dimensions[0] = ((state[0x2D] + (state[0x2C] << 8)) * numerator) / denominator;
      view->dimensions[1] = ((state[0x2F] + (state[0x2E] << 8)) * numerator) / denominator;
      D_82E06138.unused0C = 0xFFFF;
    }
      *((u16 *) (state + 2)) &= 0xFFFE;
      break;

    case 1:
      break;

  }

  return 0;
}
/* mkdraft:func_82E01A00 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E01CE8.s")
#endif

#ifdef VERSION_US
extern u8 *D_82E075E8;
extern u8 *D_82E075EC;
extern u8 *D_82E075F0;
extern s32 D_82E07614;
extern s32 D_82E07618;
s32 func_82E02378(s32 arg0, u8 *arg1) {
    switch (arg0) {
    case 0:
        switch (*(u32 *)(arg1 + 0x20)) {
        case 0:
            break;
        case 1:
            D_82E075E8 = arg1;
            *(u16 *)(arg1 + 2) &= ~1;
            break;
        case 2:
            D_82E075EC = arg1;
            *(u16 *)(arg1 + 2) &= ~1;
            break;
        case 3:
            D_82E075F0 = arg1;
            *(u16 *)(arg1 + 2) &= ~1;
            break;
        }
        break;
    case 1:
        if (arg1[0] == 3) {
            switch (*(u32 *)(arg1 + 0x20)) {
            case 0:
                *(s32 *)(arg1 + 0x2C) = D_82E07614 | 0xFFFFFF00;
                break;
            case 1:
            case 2:
            case 3:
                *(s32 *)(arg1 + 0x2C) = D_82E07618 | 0xFFFFFF00;
                break;
            }
        }
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s16 D_82E06158;
extern s32 D_82E05650;
s32 func_82E0248C(s32 arg0, u8 *arg1) {
    s32 mode;
    switch (arg0) {
    case 0:
        mode = 6;
        D_82E06158 = arg1[0x29] + (arg1[0x28] << 8);
        if (D_82E05650 == 0) {
            D_82E06158 = ((arg1[0x29] + (arg1[0x28] << 8)) * 5) / mode;
        }
        *(u16 *)(arg1 + 2) &= ~1;
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern s32 main_pool_get_available(void);
extern void* MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(void*);
extern s32 process_geo_layout(void*, void*);
extern void* func_800071A4(s32, s32, s32, s32, s32);
extern void ModelRenderer_InitDisplayRoots(void);
extern void func_8003F018(void*);
extern s32 main_pool_push_state(s32);
extern void func_82E04040(s32);
extern void func_80021ED8(s32);
extern u8 D_82E04EB0[], D_82E04F1C[], D_82E04F50[];
extern u8 D_82E05660[], D_82E057C8[];
extern s32 D_82E05650, D_82E05654, D_82E05658, D_82E0565C;
extern s32 D_82E0543C;
extern void* D_82E07600;
extern void* D_82E07604;
extern void* D_82E07608;
void func_82E02508(void) {
    void* pool;
    if (func_80001FF0() == 60) {
        D_82E05650 = 1;
    } else {
        D_82E05650 = 0;
    }
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    D_82E05654 = process_geo_layout(pool, D_82E04EB0);
    D_82E05658 = process_geo_layout(pool, D_82E04F1C);
    D_82E0565C = process_geo_layout(pool, D_82E04F50);
    MainPool_FinalizeAllocation(pool);
    D_82E07600 = func_800071A4(0, 2, 320, 240, 0);
    D_82E07604 = func_800071A4(0, 2, 320, 240, 0);
    D_82E07608 = func_800071A4(0, 2, 320, 240, 0);
    ModelRenderer_InitDisplayRoots();
    func_8003F018(D_82E05660);
    func_8003F018(D_82E057C8);
    main_pool_push_state(0x64617461);
    func_82E04040(D_82E0543C++);
    func_80021ED8(0x52);
}
#endif

#ifdef VERSION_US
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(Gfx **, s32);
extern void GfxImage_FillRectangle(Gfx **, s32, s32, s32, s32, s32);
extern void GfxImage_SetRenderTarget(Gfx **, void *);
extern void func_82E02CA4(s32);
extern s32 func_8004D690(s32);
extern s32 main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(s32);
extern void func_800503A4(void *);
extern void func_80008648(void);
extern void func_82E02EB0(s32, s32, s32);
extern void func_82E02F00(s32, s32, u8);
extern Gfx *D_800D0510;
extern s32 D_82E0543C;
extern s32 D_82E05654;
extern u8 D_82E06163;
extern s32 D_82E06164;
extern s32 D_82E07130;
extern s32 D_82E075F4;
extern u8 *D_82E0760C;
extern void *D_82E07600;
extern void *D_82E07604;
extern void *D_82E07608;
void func_82E02658(void) {
    BgStage_DrawFrame();
    if (D_82E0543C != 8) {
        GfxImage_FillCurrent(&D_800D0510, 1);
    } else {
        GfxImage_FillRectangle(&D_800D0510, 0x28, 0, 0x230, 0x1E0, 1);
    }
    if (D_82E07130 == 0) {
        GfxImage_SetRenderTarget(&D_800D0510, D_82E07600);
        func_82E02CA4(D_82E075F4);
    }
    if (D_82E0543C == 8) {
        if (D_82E07130 == 1) {
            main_pool_push_state(0x6A706567);
            D_82E075F4 = func_8004D690(0x21);
            GfxImage_SetRenderTarget(&D_800D0510, D_82E07604);
            func_82E02CA4(D_82E075F4);
            main_pool_pop_state(0x6A706567);
        } else if (D_82E07130 == 2) {
            main_pool_push_state(0x6A706567);
            D_82E075F4 = func_8004D690(0x1F);
            GfxImage_SetRenderTarget(&D_800D0510, D_82E07608);
            func_82E02CA4(D_82E075F4);
            main_pool_pop_state(0x6A706567);
        }
        BgStage_DrawFrame();
        func_82E02EB0(0xA0, 0x78, (*(s32 **)((u8 *)&D_82E07600 + (D_82E06164 * 4)))[2]);
        func_82E02F00(0xA0, 0x78, D_82E06163);
    }
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_82E05654);
    func_800503A4(D_82E0760C);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
extern void func_82E030B0(void);
extern void func_800225C4(s32);
extern s32 D_82E05440;

s32 func_82E02828(s32 arg0) {
    s32 state = arg0;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            state = 1;
        }
        break;
    case 1:
        func_82E030B0();
        if (D_82E05440 != 0) {
            state = 2;
            StageFade_StartFromTransparent(5);
            func_800225C4(0xA);
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
#endif

#ifdef VERSION_US
extern void StageFade_StartFromOpaque(s32);
extern void func_800086A4(s32);
extern void func_80064D28();
extern void func_82E02658();
s32 func_82E02828(s32);
void func_82E028D0(void) {
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        func_80064D28();
        var_s0 = func_82E02828(var_s0);
        func_82E02658();
    } while (var_s0 != 3);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82E0292C begin */
extern s32 func_80055948(s32);
extern void func_80055EF0(void *, s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern s32 func_8004C09C(s32);
extern s32 func_8004C4B0(s32);
extern u8 *func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern u8 D_1000000[], D_446E30[], D_447D00[];
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern s32 D_82E07610;
extern u8 *D_82E05930;

s32 func_82E0292C(s32 arg0, s16 *arg1) {
    s32 configuration;
    u8 data[0x20];

    func_80055948(3);
    func_80055EF0(data, *arg1 ? 1 : 0);
    if (data[0xD] == 0) {
        D_82E07610 = 1;
    } else {
        D_82E07610 = 0;
    }
    main_pool_push_state(0x454E4447);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    configuration = func_800082E0(1, 1, 2, 0, 2, 1);
    func_8004C09C(0x107);
    func_8004C4B0(0x35);
    D_82E05930 = func_80047588(0x3F, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_82E02508();
    func_80008514(configuration);
    func_82E028D0();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x454E4447);
    return D_82E07610;
}
/* mkdraft:func_82E0292C end */
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_82E05450[];
void Font_EndTexturedTextRendering_fragment66(void) { Gfx *temp_v1 = D_800D0510++; temp_v1->words.w0 = 0xDE000000; temp_v1->words.w1 = (u32)D_82E05450; }
#endif

void func_82E02A9C(void) {
}

#ifdef VERSION_US
/* mkdraft:func_82E02AA4 begin */
void func_82E02AA4(s32 arg0) {
    s32 i;
    s32 j;
    s32 width = 320;
    s32 height = 240;
    s32 yl;
    s32 yh;

    for (i = 0; i < height; i += 16) {
        yh = (i + 16) << 2;
        for (j = 0; j < width; j += 16) {
            gDPLoadTextureBlock(D_800D0510++, (u8 *)arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            yl = i << 2;
            arg0 += 0x200;
            gSPTextureRectangle(D_800D0510++, j << 2, yl, (j + 16) << 2, yh,
                                G_TX_RENDERTILE, 0, 0, 1024, 1024);
        }
    }
}
/* mkdraft:func_82E02AA4 end */
#endif

#ifdef VERSION_US
extern void Font_EndTexturedTextRendering_fragment66();
extern void func_82E02AA4(s32);

void func_82E02CA4(s32 arg0) {
    Font_EndTexturedTextRendering_fragment66();
    func_82E02AA4(arg0);
}
#endif

#ifdef VERSION_US


void func_82E02CCC(s32 arg0, s32 arg1, s32 arg2)
{
  s32 temp_t5;
  s32 var_t4;
  s32 height;
  s32 c0;
 do { c0 = arg0; height = 0xF0; for (var_t4 = arg1; var_t4 < (arg1 + height); var_t4 += 6) { temp_t5 = var_t4 + 6; { Gfx *_g = D_800D0510++; _g->words.w1 = (u32) arg2; _g->words.w0 = 0xFD10013F; } { Gfx *_g = D_800D0510++; _g->words.w1 = 0x07080200; _g->words.w0 = 0xF510A000; } arg2 += 0xF00; { Gfx *_g = D_800D0510++; _g->words.w1 = 0; _g->words.w0 = 0xE6000000; } { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF4000000; _g->words.w1 = 0x074FC014; } gDPPipeSync(D_800D0510++); { Gfx *_g = D_800D0510++; _g->words.w1 = 0x80200; _g->words.w0 = 0xF510A000; } { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF2000000; _g->words.w1 = 0x4FC014; } { Gfx *_g = D_800D0510++; _g->words.w0 = (((((c0 + 0x140) << 2) & 0xFFF) << 0xC) | 0xE4000000) | ((temp_t5 << 2) & 0xFFF); _g->words.w1 = (((c0 << 2) & 0xFFF) << 0xC) | ((var_t4 << 2) & 0xFFF); } { Gfx *_g = D_800D0510++; _g->words.w1 = 0; _g->words.w0 = 0xE1000000; } { Gfx *_g = D_800D0510++; _g->words.w0 = 0xF1000000; _g->words.w1 = 0x04000400; } } } while (0);
}
#endif

#ifdef VERSION_US
extern void Font_EndTexturedTextRendering_fragment66(void);
extern void func_82E02CCC(s32, s32, s32);
void func_82E02EB0(s32 arg0, s32 arg1, s32 arg2) {
    Font_EndTexturedTextRendering_fragment66();
    func_82E02CCC(arg0, arg1, arg2);
}
void func_82E02EB0_padding(void) {}
void func_82E02EB0_padding2(void) {}
void func_82E02EB0_padding3(void) {}
#endif

#ifdef VERSION_US
extern Gfx D_82E05500[];
void func_82E02F00(s32 x, s32 y, u8 opacity) {
    gSPDisplayList(D_800D0510++, D_82E05500);
    gDPSetEnvColor(D_800D0510++, 0, 0, 0, 255 - opacity);
    gSPScisTextureRectangle(D_800D0510++, x << 2, y << 2,
                           (x + 320) << 2, (y + 240) << 2,
                           G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E030B0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E0393C.s")
#endif

#ifdef VERSION_US
extern void func_8003F1DC(void*);
extern s32 func_8004DC6C(s32);
extern void func_8004DCFC(u8*, s32*);
extern s32 func_8004EB58(s32, s32);
extern void func_82E0424C(s32);
extern void func_82E04734(void);
void func_82E04040(s32 scene) {
    void* allocation;
    u8* resource;
    /* Valid scene indices are 0..10, as in the original switch. */
    main_pool_pop_state(0x64617461);
    main_pool_push_state(0x64617461);
    func_8003F1DC(D_82E05660);
    func_8003F1DC(D_82E057C8);
    switch (scene) {
    case 0:
        D_82E075F4 = func_8004D690(0x22);
        resource = (u8*)(u32)func_8004DC6C(0xE4);
        break;
    case 1:
        D_82E075F4 = func_8004D690(0x23);
        resource = (u8*)(u32)func_8004DC6C(0xE8);
        break;
    case 2:
        D_82E075F4 = func_8004D690(0x24);
        resource = (u8*)(u32)func_8004DC6C(0xCD);
        break;
    case 3:
        D_82E075F4 = func_8004D690(0x25);
        resource = (u8*)(u32)func_8004DC6C(0xD0);
        break;
    case 4:
        D_82E075F4 = func_8004D690(0x26);
        resource = (u8*)(u32)func_8004DC6C(0xCF);
        break;
    case 5:
        D_82E075F4 = func_8004D690(0x27);
        resource = (u8*)(u32)func_8004DC6C(0xE9);
        break;
    case 6:
        D_82E075F4 = func_8004D690(0x28);
        resource = (u8*)(u32)func_8004DC6C(0x90);
        break;
    case 7:
        D_82E075F4 = func_8004D690(0x29);
        resource = (u8*)(u32)func_8004DC6C(0x97);
        break;
    case 8:
        D_82E075F4 = func_8004D690(0x2A);
        resource = (u8*)(u32)func_8004DC6C(0xCC);
        break;
    case 9:
        D_82E075F4 = func_8004D690(0x2B);
        resource = (u8*)(u32)func_8004DC6C(0x9E);
        break;
    case 10:
        resource = (u8*)(u32)func_8004DC6C(0x8F);
        break;
    }
    func_8004DCFC(resource, 0);
    allocation = MainPool_AllocState(main_pool_get_available(), 0);
    D_82E0760C = (u8*)(u32)func_8004EB58((s32)(u32)allocation, (s32)(u32)resource);
    MainPool_FinalizeAllocation(allocation);
    func_82E0424C(scene);
    func_82E04734();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E0424C.s")
#endif

#ifdef VERSION_US
typedef struct F66Record {
    s32 state;
    s32 x;
    s32 adjusted;
    s32 old;
    s32 source;
} F66Record;
extern F66Record D_82E05968[100];
extern s32 D_82E05948, D_82E0594C;
void func_82E04734(void) {
    s32 i;
    for (i = 0; i < 100; i++) {
        D_82E05968[i].state = 0;
        D_82E05968[i].x = D_82E05948;
        D_82E05968[i].adjusted = D_82E05968[i].source - D_82E0594C;
        D_82E05968[i].old = D_82E05968[i].source;
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern Gfx D_82E05550[];
extern u8 D_82E0567D;
extern Gfx *Gfx_AllocDisplayList(s32);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);



void func_82E047C4(s32 arg0) {
    Vtx *vertices;
    s32 y;
    s32 count;
    s32 offset;
    s32 image;
    u8 alpha;

    vertices = (Vtx *)Gfx_AllocDisplayList(0xA00);
    count = 0xF0;
    y = 0x78;
    if (vertices != 0) {
        alpha = D_82E0567D;
        gSPDisplayList(D_800D0510++, D_82E05550);
        gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, alpha);
        // 40 rows of 6 pixels: 0x25800 / 0xF00. `count` steps 6 per row
        // like `y`, and its final value is never read.
        for (offset = 0, image = arg0; offset != 0x25800;
             offset += 0xF00, image += 0xF00) {
            Gfx_SetVertexAttributes(vertices, -0xA0, y, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 1, -0xA0, y - 6, 0, 0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 2, 0xA0, y - 6, 0, 0x2800, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 3, 0xA0, y, 0, 0x2800, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, image);
            gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0x50, 0, G_TX_LOADTILE, 0,
                       G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(D_800D0510++);
            gDPLoadTile(D_800D0510++, G_TX_LOADTILE, 0, 0, 0x4FC, 0x14);
            gDPPipeSync(D_800D0510++);
            gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0x50, 0, G_TX_RENDERTILE, 0,
                       G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 0x4FC, 0x14);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            vertices += 4;
            // The unsigned 6 keeps this update distinct from the `y - 6`
            // vertex arguments, so uopt does not reuse the truncated loop
            // value there; `y` stays in $s4 and the tail is `addiu s4,s4,-6`.
            y -= 6U;
            count -= 6;
        }
        // FAKE: two dead compares. The first keeps the write-only counter
        // alive for uopt's register walk; the second makes that walk reach
        // the counter just before the shared 0xF510A000 tile-constant web,
        // so they take the last two slots in order: $s7 and $fp. Without
        // both the counter is deleted (198 instructions, score 2405); with
        // either one alone the counter and tile constant swap registers
        // (score 40).
        if (count) { }
        if (count == 0xF510A000) { }
    }
}
#endif

#ifdef VERSION_US
extern void GeoRender_ApplyMaterialState();
extern void func_82E047C4(s32);
extern void *D_82E07600;
s32 func_82E04AE4(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5)) {
        func_82E047C4((*(s32 *)((u8 *)(D_82E07600) + (8))));
        GeoRender_ApplyMaterialState();
    }
    return 0;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82E04B28 begin */
extern Gfx *D_800D0510;
extern Gfx *Gfx_AllocDisplayList(s32);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
extern u8 D_82E05578[];
extern u8 D_82E0567D;
extern u8 D_82E057E5;

void func_82E04B28(s32 arg0) {
    Vtx *vertices;
    s32 image;
    s32 y;
    s32 height; // Counts 0xF0 down in step with y and is never read; the empty `if` at the end of the function keeps it live in $fp.
    s32 offset;
    s16 top;
    s16 bottom;
    s32 alpha;

    vertices = Gfx_AllocDisplayList(0xA00);
    height = 0xF0;
    y = 0x78;
    if (vertices != 0) {
        gSPDisplayList(D_800D0510++, D_82E05578);
        alpha = D_82E057E5;
        if (D_82E0567D < alpha) {
            alpha = D_82E0567D;
        }
        gDPSetEnvColor(D_800D0510++, 0xF0, 0xC8, 0x7D, alpha);
        offset = 0;
        image = arg0;
        for (; offset < 0x25800; offset += 0xF00) {
            top = y;
            Gfx_SetVertexAttributes(vertices, -0xA0, top, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            // The unsigned 6 keeps this subtraction a distinct expression from the loop update `y += -6`, so the
            // untruncated difference gets a register of its own instead of being reused from the loop tail; the
            // assignment keeps the low halfword. With a signed 6, uopt CSEs the two and diff score is 2230.
            bottom = y - 6U;
            Gfx_SetVertexAttributes(vertices + 1, -0xA0, bottom, 0, 0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 2, 0xA0, bottom, 0, 0x2800, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 3, 0xA0, top, 0, 0x2800, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetTextureImage(D_800D0510++, G_IM_FMT_IA, G_IM_SIZ_16b, 320, image);
            gDPSetTile(D_800D0510++, G_IM_FMT_IA, G_IM_SIZ_16b, 0x50, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPLoadSync(D_800D0510++);
            gDPLoadTile(D_800D0510++, G_TX_LOADTILE, 0, 0, 0x13F << 2, 5 << 2);
            gDPPipeSync(D_800D0510++);
            gDPSetTile(D_800D0510++, G_IM_FMT_IA, G_IM_SIZ_16b, 0x50, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
            gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 0x13F << 2, 5 << 2);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            image += 0xF00;
            vertices += 4;
            y += -6;
            height += -6;
        }
    }
    if (height) { // FAKE: empty; keeps the write-only height counter in $fp. Without it that callee-saved register holds the hoisted 0xFD70013F instead and diff score is 2390.
    }
}
/* mkdraft:func_82E04B28 end */
#endif

#ifdef VERSION_US
extern void func_82E04B28(s32);
s32 func_82E04E60(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5)) {
        func_82E04B28((*(s32 *)((u8 *)(D_82E07600) + (8))));
        GeoRender_ApplyMaterialState();
    }
    return 0;
}
#endif
