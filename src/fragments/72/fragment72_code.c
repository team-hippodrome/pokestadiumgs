#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F400020.s")

extern void Dma_CopyChunks(s32, s32, s32);
s32 func_800356CC(s32);
extern s32 D_8F4020E4;

void func_8F400198(void) {
    s32 temp_v0;

    temp_v0 = func_800356CC(9);
    Dma_CopyChunks(D_8F4020E4, temp_v0, temp_v0 + 0xBDC);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F4001CC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F4009A4.s")

u16 func_8F400A8C(u16* image, u16 stride) {
    u32 alpha = 0;
    u32 blue = 0;
    u32 green = 0;
    u32 red = 0;
    s32 row;
    s32 col;
    s32 pitch = stride;

    /* Keep the masks on the loads: a pixel temporary changes IDO allocation. */
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            red += *image & 0xF800;
            green += *image & 0x7C0;
            blue += *image & 0x3E;
            alpha += *image & 1;
            image++;
        }
        image += pitch - 4;
    }
    red = (red >> 4) & 0xF800;
    green = (green >> 4) & 0x7C0;
    blue = (blue >> 4) & 0x3E;
    alpha = alpha >= 5; /* At least five covered texels out of sixteen. */
    return red | green | blue | alpha;
}

void func_8F400B88(u16* dest, u16* image) {
    u16 x;
    u16 y;
    u16* workingImage = image;
    u16* workingDest = dest;

    /* Sample each 4x4 block of the 160x160 source into a 40x40 thumbnail. */
    for (y = 0; y < 40; y++) {
        for (x = 0; x < 40; x++) {
            *workingDest++ = func_8F400A8C(workingImage, 160);
            workingImage += 4;
        }
        workingImage += 480; /* Remaining three source rows. */
    }
}

void func_8F400C08(s32 arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = func_800356CC(4) + (arg0 * 0xC80);
    Dma_CopyChunks(arg1, temp_a1, temp_a1 + 0xC80);
}

/* mkdraft:func_8F400C58 begin */
extern s32 D_8F4020D0;
extern s32 D_8F4020D4;
extern s16 D_8F4020FC;
extern s16 D_8F4020FE;
extern s16 D_8F402100;
extern s16 D_8F402102;
extern s16 D_8F402104;
extern s16 D_8F402106;
extern void func_80043A0C(void* arg0, void* arg1, s32 arg2);
extern s32 func_8004410C();
extern s32 func_80044144();
extern void func_80044250(s8 value);



void func_8F400C58(void) {
    s16 state;
    s16* state_ptr;
    s16* counter_ptr;
    s16* timer_ptr;
    s16* index_ptr;
    s16* mode_ptr;
    s32* base_ptr;

    state_ptr = &D_8F4020FE;
    counter_ptr = &D_8F402102;
    timer_ptr = &D_8F402106;
    index_ptr = &D_8F402100;
    mode_ptr = &D_8F4020FC;
    base_ptr = &D_8F4020D0;
    state = *state_ptr;
    switch (state) {
    case 0:
        func_80043A0C(*base_ptr, 0, *index_ptr);
        if (*mode_ptr == 2) {
            func_80044250((*counter_ptr) + 1);
        }
        *state_ptr = 1;
        *timer_ptr = 0;
        break;
    case 1:
        if (func_80044144(*base_ptr) != 0) {
            *timer_ptr += 1;
            if (*timer_ptr >= 2) {
                *state_ptr = 2;
                *timer_ptr = 0;
            }
        }
        break;
    case 2:
        *counter_ptr += 1;
        func_8F400B88(*(u16**)((u8*)D_8F4020D4 + 8), func_8004410C(*base_ptr, 0));
        func_8F400C08(*counter_ptr, *(u16**)((u8*)D_8F4020D4 + 8));
        if (*counter_ptr < (D_8F402104 - 1)) {
            *state_ptr = 0;
            if (state_ptr[-1] != 2) { // FAKE: D_8F4020FC read through state_ptr (diff score 420 without it); same base symbol stops IDO hoisting the load above the store.
                *index_ptr += 1;
            }
        } else {
            *state_ptr = 3;
        }
        break;
    }
}
/* mkdraft:func_8F400C58 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F400DE8.s")

void func_8F400E74(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == arg1) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
        return;
    }
    if (arg2 == 0) {
        func_8004972C(0x80, 0x80, 0x80, 0xFF);
        return;
    }
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F400EE0.s")

extern s16 D_8F402030[];
extern u8 D_8F402040[];
extern u8 D_8F402044[];
extern u8 D_8F4020C0;
extern s16 D_8F4020FC;
void func_8F401464(void) {
    s32 i;
    s32 y;
    s16 *selection; // FAKE: reads D_8F4020C0 through a local pointer; diff score 655 without it.
    s16 *extra; // FAKE: reads D_8F4020FC through a local pointer; diff score 940 without it.

    Ui_DrawGradientPanel(120, 120, 400, 180, D_8F402040, D_8F402044);
    func_800498C4();
    func_800496A4(8, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0, 0xFF, 0xFF, 0xFF);
    func_800495BC(140, 140, func_8004C874(66, 19));
    Font_DisableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    selection = (s16 *)&D_8F4020C0;
    extra = &D_8F4020FC;
    for (i = 0, y = 180; i < 5; i++, y += 22) {
        if (i != *selection) {
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8004972C(0xFF, 0xFF, 0, 0xFF);
        }
        func_800495BC(140, y, func_8004C874(66, D_8F402030[i]));
        if (i == 4) {
            func_800495F8(500, y, 2, func_8004C874(66, *extra + 34));
        }
    }
    func_800499EC();
}

// Close to fragment20's func_82609938; also skips drawing when arg5 is not positive.
//@src/fragments/20/fragment20_12C460.c
extern void func_80046204(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
void func_8F4015FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    if (arg5 > 0) {
        for (var_s1 = 0; var_s1 < arg4; var_s1 += arg5) {
            temp_v0 = arg4 - var_s1;
            if (temp_v0 < arg5) var_s0 = temp_v0;
            else var_s0 = arg5;
            func_80046204((arg3 * var_s1 * 2) + arg2, 0, 2, arg3, var_s0, 0, 0, arg3, var_s0 - 1, 0, 2, 2, 0, 0, 0, 0);
            GfxRect_DrawTextured((s16)arg0, (s16)(arg1 + var_s1), (s16)arg3, (s16)var_s0, 0, 0, 0x400, 0x400, 0);
        }
    }
}

extern void Dma_CopyChunks(s32, s32, s32);
extern s32 func_800356CC(s32);
extern s32 D_8F4020E4;
extern void func_800226C0(s32);
extern void func_8F4001CC(void);
extern void *D_80087200;
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_8F4020C0;
extern void func_8F4015FC(s32, s32, s32, s32, s32, s32);
#define GFX_DL (*(Gfx **)&D_800D0510)
void func_8F401750(void) {
    s16 temp_a3;
    u8 *temp_t2;
    s32 temp_a2;
    s32 temp_t3;
    s32 temp_t7;

    temp_t2 = (u8 *)(u32)(*(u32 *)((u8 *)&D_8F4020C0 + 0xC));
    temp_a2 = *(s32 *)((u8 *)&D_8F4020C0 + 0x18);
    if ((temp_t2 != NULL) && (temp_a2 != 0)) {
        temp_a3 = *(s16 *)(temp_t2 + 4);
        temp_t3 = *(s16 *)(temp_t2 + 6);
        temp_t7 = (0x800 / temp_a3) & ~1;
        gSPDisplayList(GFX_DL++, D_80094E38);
        gDPSetRenderMode(GFX_DL++, 0x0F0A4000, 0);
        func_8F4015FC(0x64, 0x64, temp_a2, temp_a3, temp_t3, temp_t7);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F401828.s")

extern void GfxImage_FillCurrent(void *, u16);
extern s32 func_80008648(void);
extern void func_800088DC(void);
extern void func_80043E70(s32, s32);
extern void func_8F400EE0(s32, s32);
extern void func_8F401464(void);
extern void func_8F401828(void);

// Per-frame draw callback; arg0 1/2/3 selects the mode-specific setup.
// D_8F4020C0 is an unnamed struct: a pointer at +0x10 and an s16 countdown at +4.
void func_8F401918(s32 arg0) {
    s32 sp1C;
    s32 sp18;
    u8 *state;

    sp1C = 0;
    sp18 = 0;
    state = (u8 *)&D_8F4020C0;
    if (*(void **)(state + 0x10) != NULL) {
        func_80043E70((s32)*(void **)(state + 0x10), 1);
    }
    func_800088DC();
    if (*(s16 *)(state + 4) != 0) {
        GfxImage_FillCurrent(&D_800D0510, 0x7BDF);
        if (*(s16 *)(state + 4) > 0) {
            *(s16 *)(state + 4) -= 1;
        }
    }
    if (arg0 == 1) {
        func_8F401464();
    }
    func_8F401750();
    func_8F401828();
    switch (arg0) {
        case 2:
            sp1C = 1;
            break;
        case 3:
            sp18 = 1;
            break;
    }
    func_8F400EE0(sp1C, sp18);
    func_80008648();
}
extern void func_800226C0(s32);
extern void *D_80087200;

s32 func_8F401A08(s16 *arg0) {
    s32 sp1C;
    s32 previous;

    sp1C = 0;
    previous = *arg0;
    if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x800) {
        (*arg0)--;
        if (*arg0 < 0) {
            *arg0 = 4;
        }
    }
    if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x400) {
        (*arg0)++;
        if (*arg0 >= 5) {
            *arg0 = 0;
        }
    }
    if (previous != *arg0) {
        func_800226C0(1);
    }
    if (*arg0 == 4) {
        if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x200) {
            *(s16 *)((u8 *)arg0 + 0x3C) -= 1;
            if (*(s16 *)((u8 *)arg0 + 0x3C) < 0) {
                *(s16 *)((u8 *)arg0 + 0x3C) = 0;
            }
        }
        if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x100) {
            *(s16 *)((u8 *)arg0 + 0x3C) += 1;
            if (*(s16 *)((u8 *)arg0 + 0x3C) >= 3) {
                *(s16 *)((u8 *)arg0 + 0x3C) = 2;
            }
        }
    }
    if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
        sp1C = 1;
        func_800226C0(2);
    } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
        sp1C = -1;
        func_800226C0(3);
    }
    return sp1C;
}
extern void func_800226C0(s32);
extern void func_8F4001CC();
extern void *D_80087200;
s32 func_8F401B74(s32 arg0) {
    s32 sp1C;

    sp1C = 0;
    func_8F4001CC();
    if ((*(u16 *)((u8 *)(D_80087200) + (8))) & 0x4000) {
        sp1C = -1;
        func_800226C0(3);
    }
    return sp1C;
}

extern void Dma_CopyChunks(s32, s32, s32);
extern s32 func_800356CC(s32);
extern s32 D_8F4020E4;
extern void func_800226C0(s32);
extern void func_8F4001CC(void);
extern void *D_80087200;
extern void func_8F400C58(void);
extern s16 D_8F402102;
extern s16 D_8F402104;
s32 func_8F401BC4(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    sp18 = 0;
    func_8F400C58();
    if (((*(u16 *)((u8 *)(D_80087200) + 8)) & 0x4000) &&
        (D_8F402102 >= (D_8F402104 - 1))) {
        sp18 = -1;
        func_800226C0(3);
    }
    return sp18;
}

/* mkdraft:func_8F401C30 begin */
extern s32 D_8F40203C;
extern s16 D_8F4020C4;
extern s32 D_8F4020CC;
extern s32 D_8F4020D0;
extern s32 D_8F4020D4;
extern s32 D_8F4020D8;
extern u8 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromTransparent(s32 duration);
extern s32 func_8F400020();
extern s32 func_8F4009A4();
extern void main_pool_pop_state(s32);
extern void main_pool_push_state(s32);

// FAKE: the compiled body is the target code except for the D_8F4020D4 zero
// store. Retail reuses the $at already loaded with %hi(D_8F4020D0); IDO emits a
// second lui, leaving this function at 0x15C bytes instead of 0x158 (diff score
// 100 without these pragmas). REWRITE_FUNCTION_HEX authenticates that compiler
// text by hash and substitutes the 0x158-byte target text with the target
// relocation topology; REWRITE_SECTION_WORD moves the fifth switch-table entry
// at .rodata+0x64 from 0x1D40 to 0x1D3C so it reaches the shifted case-4 block.
// See tools/schedule_patch.py.
#pragma REWRITE_FUNCTION_HEX(func_8F401C30, 6489a4a99f17e1e8882dfe2b13a636c877f1b6b3f26376320c0ee6fcc535db46, 27bdffe0afb000182c810005afbf001c1020004c00808025000470803c010000002e08218c2e005401c00008000000000c00000000000000544000438fbf001c10000040241000013c0400000c000000248400005040003c8fbf001c18400013241000043c0400000c0000008c8400003c0f000085ef0000240100042410000311e10005241800020c000000241000021000002d8fbf001c3c0100000c000000a4380000100000288fbf001c0c00000024040005100000248fbf001c3c0400000c000000248400001040001e3c040000241000010c0000008c8400003c010000ac2000003c01000010000016ac2000003c0400000c00000024840000104000113c040000241000010c0000008c8400003c010000ac200000ac2000003c0100002419ffff10000007a43900000c0000000000000024010001544100038fbf001c241000058fbf001c020010258fb0001803e0000827bd0020)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x1C, 5, .rodata)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x24, 6, .rodata)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x30, 4, StageContext_GetFadeMode)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x4C, 4, func_8F401A08)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x48, 5, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x50, 6, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x68, 4, main_pool_push_state)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x64, 5, D_8F40203C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x6C, 6, D_8F40203C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x70, 5, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x74, 6, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x88, 4, func_8F400020)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x9C, 4, func_8F4009A4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x98, 5, D_8F4020C4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xA0, 6, D_8F4020C4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xAC, 4, StageFade_StartFromTransparent)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xC0, 4, func_8F401B74)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xBC, 5, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xC4, 6, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xD4, 4, main_pool_pop_state)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xCC, 5, D_8F40203C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xD8, 6, D_8F40203C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xDC, 5, D_8F4020CC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xE0, 6, D_8F4020CC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xE4, 5, D_8F4020D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xEC, 6, D_8F4020D8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xF4, 4, func_8F401BC4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xF0, 5, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0xF8, 6, D_8F4020C0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x108, 4, main_pool_pop_state)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x100, 5, D_8F40203C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x10C, 6, D_8F40203C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x110, 5, D_8F4020D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x114, 6, D_8F4020D0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x118, 6, D_8F4020D4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x11C, 5, D_8F4020C4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x128, 6, D_8F4020C4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8F401C30, 0x12C, 4, StageContext_GetFadeMode)
#pragma REWRITE_SECTION_WORD(.rodata, 0x64, 0x1D40, 0x1D3C)



s32 func_8F401C30(s32 arg0) {
    s32 var_s0 = arg0;
    s32 temp_v0;

    switch (var_s0) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                var_s0 = 1;
            }
            break;
        case 1:
            temp_v0 = func_8F401A08(&D_8F4020C0);
            if (temp_v0 != 0) {
                if (temp_v0 > 0) {
                    main_pool_push_state(D_8F40203C);
                    if (*(s16 *)&D_8F4020C0 != 4) {
                        var_s0 = 2;
                        func_8F400020();
                    } else {
                        var_s0 = 3;
                        D_8F4020C4 = 2;
                        func_8F4009A4();
                    }
                } else {
                    var_s0 = 4;
                    StageFade_StartFromTransparent(5);
                }
            }
            break;
        case 2:
            if (func_8F401B74((s32)&D_8F4020C0)) {
                var_s0 = 1;
                main_pool_pop_state(D_8F40203C);
                D_8F4020CC = 0;
                D_8F4020D8 = 0;
            }
            break;
        case 3:
            if (func_8F401BC4((s32)&D_8F4020C0)) {
                var_s0 = 1;
                main_pool_pop_state(D_8F40203C);
                D_8F4020D0 = 0;
                D_8F4020D4 = 0;
                D_8F4020C4 = -1;
            }
            break;
        case 4:
            if (StageContext_GetFadeMode() == 1) {
                var_s0 = 5;
            }
            break;
    }
    return var_s0;
}
/* mkdraft:func_8F401C30 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F401D88.s")

extern void Dma_CopyChunks(s32, s32, s32);
extern s32 func_800356CC(s32);
extern s32 D_8F4020E4;
extern void func_800226C0(s32);
extern void func_8F4001CC(void);
extern void *D_80087200;
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_8004C4B0(s32);
extern void func_80047588(s32, s32);
extern void Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_8F400DE8(void);
extern void func_80008514(s32);
extern void func_8F401D88(void);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
s32 fragment72_main(s32 arg0, s32 arg1) {
    s32 sp24;

    main_pool_push_state(0x49434D4B);
    Gfx_InitDisplayListBuffers(0x18000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(3);
    func_8004C4B0(0x42);
    func_80047588(0x18, 0);
    Asset_LoadToSegment(((u32)&D_1000000 & 0x0F000000) >> 24, &D_446E30, &D_447D00, 0);
    func_8F400DE8();
    func_80008514(sp24);
    func_8F401D88();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x49434D4B);
    return 0;
}
#endif
