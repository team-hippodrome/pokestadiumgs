#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern s32 D_884017E4;
s32 func_88400020(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        D_884017E4 = arg1;
    }
    return 0;
}

s32 func_88400034(s32 arg0, u8 *arg1) {
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;
    s32 result;

    result = 0;
    if (arg0 == 0) {
        var_v0 = 0x800;
        var_a0 = 0x400;
        var_a1 = 0x200;
        var_a2 = 0x100;
    } else {
        var_v0 = 8;
        var_a0 = 4;
        var_a1 = 2;
        var_a2 = 1;
    }
    if ((D_80087200->buttonsHeld & var_v0) != 0) {
        result = 1;
        *(s16 *)(arg1 + 0) = *(s16 *)(arg1 + 0) + 0x400;
    }
    if ((D_80087200->buttonsHeld & var_a0) != 0) {
        result = 1;
        *(s16 *)(arg1 + 0) = *(s16 *)(arg1 + 0) - 0x400;
    }
    if ((D_80087200->buttonsHeld & var_a1) != 0) {
        result = 1;
        *(s16 *)(arg1 + 2) = *(s16 *)(arg1 + 2) + 0x400;
    }
    if ((D_80087200->buttonsHeld & var_a2) != 0) {
        result = 1;
        *(s16 *)(arg1 + 2) = *(s16 *)(arg1 + 2) - 0x400;
    }
    return result;
}

/* mkdraft:ModelPreview_UpdateAutoRotation_fragment33 begin */
extern s16 Math_StepToS(s16, s16, s16);

void ModelPreview_UpdateAutoRotation_fragment33(void *state) {
    s16 step;
    s16 increment;
    s16 *rotation = (s16 *)(*(u8 **)((u8 *)state + 0x1C) + 0x1E);

    if (*(s16 *)((u8 *)state + 0xE) < 256) {
        *(s16 *)((u8 *)state + 0xE) += 16;
    }
    rotation[1] += *(s16 *)((u8 *)state + 0xE);
    increment = *(s16 *)((u8 *)state + 0xE);
    step = (rotation[0] < 0 ? -rotation[0] : rotation[0]) / 12;
    if (step < 8) {
        step = 8;
    }
    if (step < increment) {
        increment = step;
    }
    rotation[0] = Math_StepToS(rotation[0], 0, increment);
}
/* mkdraft:ModelPreview_UpdateAutoRotation_fragment33 end */

extern void ModelPreview_UpdateAutoRotation_fragment33(void *);
// Preview state for fragment 33. Offsets 0x00-0x2F follow the ModelPreviewState layout that
// ModelPreview_Create initializes; func_88401364 performs the same initialization inline.
//@src/43700.c
typedef struct unk_D_884017E0 {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 clearColor;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
    /* 0x08 */ void *callback;
    /* 0x0C */ s16 countdown;
    /* 0x0E */ s16 rotationStep;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s32 resource;
    /* 0x18 */ u8 *layout;
    /* 0x1C */ u8 *model;
    /* 0x20 */ u8 *image;
    /* 0x24 */ u8 *depth;
    /* 0x28 */ u16 selectionFlags;
    /* 0x2C */ u32 selectionValue;
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ u8 unk_31;
    /* 0x32 */ u16 species; // passed to func_80042FE4, which calls ModelPreview_SetSelection
    /* 0x34 */ s8 unk_34;
    /* 0x35 */ s8 unk_35;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s16 unk_3C;
    /* 0x3E */ s16 unk_3E;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ s16 unk_44;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48; // func_884001CC reloads countdown from this after manual rotation
} unk_D_884017E0; // size = 0x4C

extern unk_D_884017E0 *D_884017E0;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
void func_884001CC(u8 *arg0) {
    f32 scale;
    s16 countdown;
    s32 temp_result;
    s32 result;
    u16 flags;

    flags = *(u16 *)(arg0 + 0);
    result = 0;
    if (flags & 2) {
        temp_result = func_88400034((flags & 1) != 0, (u8 *)(u32)(*(s32 *)(arg0 + 0x1C) + 0x1E));
        result = temp_result;
        if (temp_result == 0) {
            result = 0;
        }
    }
    if (result != 0) {
        *(s16 *)(arg0 + 0xE) = 0;
        *(s16 *)(arg0 + 0xC) = *(s16 *)((u8 *)D_884017E0 + 0x48);
    } else if (*(u16 *)(arg0 + 0) & 4) {
        countdown = *(s16 *)(arg0 + 0xC);
        if (countdown > 0) {
            *(s16 *)(arg0 + 0xC) = countdown - 1;
        } else {
            ModelPreview_UpdateAutoRotation_fragment33(arg0);
        }
    }
    scale = *(f32 *)(arg0 + 0x10);
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)*(u32 *)(arg0 + 0x1C) + 0x30), scale, scale, scale);
}

extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern u8 *func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_800459AC(u8 *, u8, u8, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_8800528C(s32);
void func_88400284(s32 arg0) {
    s16 var_s0;
    s16 var_s1;
    s32 var_s3;
    u8 *temp_v0;
    u8 *var_s2;

    temp_v0 = func_8004C990(0x3C, 0);
    var_s2 = func_8004CA60(temp_v0);
    var_s0 = 0;
    var_s1 = 0xD8;
    func_8800528C(arg0);
    var_s3 = 0;
    do {
        func_800459AC(var_s2, temp_v0[4], temp_v0[5], 0xA0, 0x18, 1, 0, 2, 2, 0, 0, 0, 0);
        func_80044270(0, var_s0, 0xA0, 0x18, -0x10, -0x10, 0x400, 0x400, 0);
        func_80044270(0xA0, var_s0, 0xA0, 0x18, 0x13F0, -0x10, -0x400, 0x400, 0);
        func_80044270(0, var_s1, 0xA0, 0x18, -0x10, 0x2F0, 0x400, -0x400, 0);
        func_80044270(0xA0, var_s1, 0xA0, 0x18, 0x13F0, 0x2F0, -0x400, -0x400, 0);
        var_s3 += 1;
        var_s2 += 0xF00;
        var_s0 += 0x18;
        var_s1 -= 0x18;
    } while (var_s3 != 5);
}

extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32); //@src/44E70.c

// Draws a frame around (x, y, width, height) from 8x8 texture tiles: the top edge, the left and
// right edges, the two bottom corners and the bottom edge, selecting each tile by its s
// coordinate (0, 256, 512, 768, 224, 736).
void func_8840045C(s16 x, s16 y, s16 width, s16 height) {
    GfxRect_DrawTextured(x + 8, y, width - 16, 8, 224, 0, 0, 0x400, 0);
    GfxRect_DrawTextured(x, y, 8, height - 8, 0, 0, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x + width - 8, y, 8, height - 8, 0x100, 0, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x, y + height - 8, 8, 8, 0x200, 0, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x + width - 8, y + height - 8, 8, 8, 768, 0, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x + 8, y + height - 8, width - 16, 8, 736, 0, 0, 0x400, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/33/fragment33_code/func_88400610.s")

extern s32 func_80001FF0(void);
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_88400610(void);
extern f32 D_884017D0;
void func_88400F48(void) {
    s32 count;
    s32 i;

    count = (u32) (((f32)func_80001FF0() * D_884017D0) / 2) & 0xFFFF;
    func_800086A4(2);
    StageFade_StartFromOpaque(count);
    i = 0;
    if (count != 0) {
        do {
            func_80064D28();
            func_88400610();
            i += 1;
        } while (i != count);
    }
}

/* mkdraft:func_8840104C begin */
extern void func_800226C0(s32);
extern void func_80026068(u32);
extern s32 func_80026098(void);
extern void func_80064D28(void);
extern void func_88400610(void);

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} PreviewRotation;

extern PreviewRotation D_800948DC;

// Species preview loop. Button input is ignored while the GB audio channel mask is nonzero
// and for three more frames after it becomes 0; then B (0x4000) queues sound 0x48 and exits,
// A (0x8000) queues the selected species' GB audio sequence, and Start (0x1000) restarts the
// idle rotation. Ids above 253 index the species tables as 201 (Unown), as in func_88401364.
//@src/43700.c


void func_8840104C(void) {
    u8 channels;
    s32 exitRequested;

    exitRequested = 0;
    D_884017E0->flags |= 4;
    D_884017E0->flags |= 2;
    *(s32 *)(D_884017E0->model + 0x4C) = 0x10000;
    do {
        // Nonzero while a GB audio channel is active; input is ignored until the sound ends.
        channels = func_80026098();
        func_80064D28();
        if (D_884017E0->unk_31 != 0 && channels == 0) {
            D_884017E0->unk_30 = 3;
        }
        D_884017E0->unk_31 = channels;
        if (D_884017E0->unk_30 != 0) {
            D_884017E0->unk_30 = D_884017E0->unk_30 - 1;
        } else if (channels == 0 && (D_80087200->buttonsPressed & 0x4000)) {
            func_800226C0(0x48);
            exitRequested = 1;
        } else if (channels == 0 && (D_80087200->buttonsPressed & 0x8000)) {
            s32 species = D_884017E0->species;
            func_80026068(species > 253 ? 201 : species);
        } else if (D_80087200->buttonsPressed & 0x1000) {
            if (channels == 0) {
                func_800226C0(0x137);
            }
            D_884017E0->countdown = 0;
            D_884017E0->rotationStep = 256;
            *(PreviewRotation *)(D_884017E0->model + 0x1E) = D_800948DC;
        }
        func_88400610();
    } while (exitRequested == 0);
}
/* mkdraft:func_8840104C end */

extern s32 func_80001FF0(void);
extern void func_80064D28(void);
extern void func_88400610(void);
extern void func_88600020(void *);
extern void StageFade_StartFromTransparent(s32);
extern f32 D_884017D4;
void func_88401200(void) {
    u16 count;
    s32 i;

    count = (u16)(((f32)func_80001FF0() * D_884017D4) / 2);
    *(u16 *)((u8 *)D_884017E0 + 0) = *(u16 *)((u8 *)D_884017E0 + 0) & 0xFFFB;
    *(u16 *)((u8 *)D_884017E0 + 0) = *(u16 *)((u8 *)D_884017E0 + 0) & 0xFFFD;
    *(s32 *)((u8 *)*(u32 *)((u8 *)D_884017E0 + 0x1C) + 0x4C) = 0;
    StageFade_StartFromTransparent(count);
    i = 0;
    if (count != 0) {
        do {
            func_80064D28();
            func_88400610();
            i += 1;
        } while (i != count);
    }
    if (*(s16 *)((u8 *)D_884017E0 + 0xC) < 0x78) {
        *(s16 *)((u8 *)D_884017E0 + 0xC) = *(s16 *)((u8 *)D_884017E0 + 0xC);
    } else {
        *(s16 *)((u8 *)D_884017E0 + 0xC) = 0x78;
    }
    func_88600020(D_884017E0);
}

extern u8 D_88401740;
extern s32 D_80128C64;
extern void func_8004C4B0(s32);
extern void func_8004C8C0(s32);
extern void *Util_Malloc(s32);
extern s8 func_8006397C(u8);
extern s8 func_800639C0(u8);
extern s32 func_8004C874(s32, s32);
extern s32 func_80049290(s32, s32, s32);
extern s32 func_80001FF0(void);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern u8 *process_geo_layout(s32, void *);
extern void MainPool_FinalizeAllocation(s32);
extern void GeoCamera_SetViewport(void *, s16, s16, s16, s32);
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern void func_80042FE4(void *, u16);
extern void func_88600074(void *);
// Allocates D_884017E0 for species `arg0`, fills its unk_34..unk_48 fields, and initializes its
// preview fields the way ModelPreview_Create does (320x240 viewport, 30/100/12800 perspective).
// It then selects the species with func_80042FE4 and copies the saved rotation, rotationStep
// and countdown back into the preview with func_88600074.
//@src/43700.c
//@src/fragments/35/fragment35_1CCC20.c
void func_88401364(s32 arg0) {
    s32 pool;
    unk_D_884017E0 *state;
    s32 temp_v0;
    u8 table_index;
    u16 species;

    func_8004C4B0(40);
    func_8004C8C0(60);
    func_8004C8C0(270);
    func_8004C8C0(269);
    func_8004C8C0(268);
    func_8004C8C0(332);
    D_884017E0 = Util_Malloc(sizeof(unk_D_884017E0));
    D_884017E0->species = arg0;
    // Ids above 253 index the species tables as 201 (Unown). func_886000C8 treats ids other
    // than 201 as offsets from 252, the range used for Unown forms.
    //@src/fragments/35/fragment35_1CCC20.c
    species = arg0;
    if (species > 253) {
        species = 201;
    }
    table_index = species;
    D_884017E0->unk_34 = func_8006397C(table_index);
    D_884017E0->unk_35 = func_800639C0(table_index);
    D_884017E0->unk_38 = func_8004C874(40, 16);
    temp_v0 = func_80049290(1, 0, D_884017E0->unk_38);
    D_884017E0->unk_3C = 283 - temp_v0;
    D_884017E0->unk_3E = D_884017E0->unk_3C - 23;
    D_884017E0->unk_40 = temp_v0 + 32;
    D_884017E0->unk_42 = D_884017E0->unk_3E + 2;
    D_884017E0->unk_44 = D_884017E0->unk_40 - 4;
    D_884017E0->unk_46 = D_884017E0->unk_3E + 9;
    D_884017E0->unk_48 = (u32)((func_80001FF0() * 12.0f) / 2);
    state = D_884017E0;
    state->flags = 0x106;
    state->clearColor = 1;
    state->width = 320;
    state->height = 240;
    state->callback = NULL;
    state->countdown = 0;
    state->rotationStep = 0;
    state->scale = 1.0f;
    state->resource = D_80128C64;
    state->layout = NULL;
    state->model = NULL;
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    state->layout = process_geo_layout(pool, &D_88401740);
    state->model = (u8 *)D_884017E4;
    MainPool_FinalizeAllocation(pool);
    GeoCamera_SetViewport(*(void **)(state->layout + 0xC), 0, 0, state->width, state->height);
    GeoCamera_SetPerspective(*(void **)(state->layout + 0xC), 30.0f, 100.0f, 12800.0f);
    state->selectionFlags = 0;
    state->selectionValue = 0;
    state->flags &= ~4;
    state->flags &= ~2;
    state->flags |= 1;
    func_80042FE4(state, D_884017E0->species);
    func_88600074(state);
    *(s32 *)(state->model + 0x4C) = 0;
    D_884017E0->unk_30 = 0;
    D_884017E0->unk_31 = 0;
}

extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern s32 func_80047588(s32, s32);
extern s32 D_8800687C;
extern void Font_EnableLineBreak(void);
extern void func_88401364(s32);
extern void func_80008514(s32);
extern void func_88400F48(void);
extern void func_8840104C(void);
extern void func_88401200(void);
extern void func_80008574(void);
extern void Util_Free(void *);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
s32 fragment33_main(s32 arg0, s32 arg1) {
    s32 sp24;

    main_pool_push_state(0x5A4F4F4D);
    Gfx_InitDisplayListBuffers(0x14000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    func_8004C09C(3);
    D_8800687C = func_80047588(1, 0);
    Font_EnableLineBreak();
    func_88401364(arg1);
    func_80008514(sp24);
    func_88400F48();
    func_8840104C();
    func_88401200();
    func_80008574();
    Util_Free(D_884017E0);
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x5A4F4F4D);
    return 0;
}
#endif
