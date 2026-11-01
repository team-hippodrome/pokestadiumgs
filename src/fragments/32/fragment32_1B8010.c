#include "global.h"


#ifdef VERSION_US
extern u8 func_800637C0(u8);
s32 func_88306D00(u16 *arg0, u16 *arg1) {
    struct { u8 pad[3]; u8 first; u32 unused; } result;
    s32 normalized = (*arg0 >= 0xFE) ? 0xC9 : *arg0;
    result.first = func_800637C0(normalized);
    return result.first - func_800637C0((*arg1 >= 0xFE) ? 0xC9 : *arg1);
}

s32 func_88306D6C(u16 *arg0, u16 *arg1) {
    s32 first = (*arg0 >= 0xFE) ? 0xC9 : *arg0;
    s32 second = (*arg1 >= 0xFE) ? 0xC9 : *arg1;
    return first - second;
}

extern u8 func_80073450(u8);
s32 func_88306DAC(u16 *arg0, u16 *arg1) {
    struct { u8 pad[3]; u8 first; u32 unused; } result;
    s32 normalized = (*arg0 >= 0xFE) ? 0xC9 : *arg0;
    result.first = func_80073450(normalized);
    return result.first - func_80073450((*arg1 >= 0xFE) ? 0xC9 : *arg1);
}

extern void func_88004B60(s32, u8, s32 *);
extern u8 D_88601896;
extern s32 D_88601898;
void func_88306E18(s32 arg0) {
    s32 *sp1C;

    switch (arg0) {                                 /* irregular */
    case 0:
        sp1C = &func_88306D00;
        break;
    case 1:
        sp1C = &func_88306D6C;
        break;
    case 2:
        sp1C = &func_88306DAC;
        break;
    }
    func_88004B60(D_88601898, D_88601896, sp1C);
}

extern s32 D_88308EA0;
extern s16 D_88308EB8[];
extern u8 D_88308EB0;
extern s8 D_88308EB1;
extern s16 D_88308EB4;
extern s16 D_88308EC0;
void func_88306E90(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, s8 arg5) {
    D_88308EA0 = 0;
    D_88308EB8[0] = arg0;
    D_88308EB8[1] = arg1;
    D_88308EB8[2] = arg2;
    D_88308EB8[3] = arg3;
    D_88308EB0 = arg4;
    D_88308EB1 = arg5;
    D_88308EB4 = D_88308EB8[arg5];
    D_88308EC0 = 0;
}

extern void func_800226C0(s32);
extern s32 D_88308EA0;
extern s8 D_88308EB1;
extern s8 D_88308EB2;
extern s16 D_88308EB6;
extern s16 D_88308EB8[];
void func_88306F18(u8 arg0) {
    if (arg0 < D_88308EB1) {
        func_800226C0(0x46);
        D_88308EB2 = D_88308EB1 - 1;
        D_88308EB6 = D_88308EB8[D_88308EB2];
        D_88308EA0 = 1;
    }
}

extern void func_800226C0(s32);
extern s32 D_88308EA0;
extern u8 D_88308EB0;
extern s8 D_88308EB1;
extern s8 D_88308EB2;
extern s16 D_88308EB6;
extern s16 D_88308EB8[];
void func_88306F90(void) {
    if (D_88308EB1 < (D_88308EB0 - 1)) {
        func_800226C0(0x46);
        D_88308EB2 = D_88308EB1 + 1;
        D_88308EB6 = D_88308EB8[D_88308EB2];
        D_88308EA0 = 2;
    }
}

extern s32 func_80001FF0(void);
extern void func_880002F4(u8 *, s16);
extern s8 D_88308E04;
extern u8 D_88308E18;
extern s32 D_88308EA0;
extern s8 D_88308EB1;
extern s8 D_88308EB2;
extern s16 D_88308EB4;
extern s16 D_88308EB6;
extern s16 D_88308EC0;

void func_8830700C(void) {
    f32 quotient;
    f32 var;

    /* Per-frame scroll stepper: 138240 / frame-time pixels into D_88308EC0,
     * then mode 1/2 walks D_88308EB4 toward target D_88308EB6 by 780 /
     * frame-time; the +/-0.5 rounds the trunc toward the motion direction.
     * On arrival: snap to target, copy the preset index D_88308EB2 ->
     * D_88308EB1, reset mode D_88308EA0, re-arm via func_880002F4
     * (&D_88308E18, 0), and clear D_88308E04. */
    quotient = 138240.0f / (f32)func_80001FF0();
    if (quotient > 0.0f) {
        var = 0.5f;
    } else {
        var = -0.5f;
    }
    D_88308EC0 += (s32)((138240.0f / (f32)func_80001FF0()) + var);
    switch (D_88308EA0) {
    case 1:
        quotient = 780.0f / (f32)func_80001FF0();
        if (quotient > 0.0f) {
            var = 0.5f;
        } else {
            var = -0.5f;
        }
        D_88308EB4 -= (s32)((780.0f / (f32)func_80001FF0()) + var);
        if (D_88308EB6 >= D_88308EB4) {
            D_88308EB4 = D_88308EB6;
            D_88308EB1 = D_88308EB2;
            D_88308EA0 = 0;
            func_880002F4(&D_88308E18, 0);
            D_88308E04 = 0;
        }
        return;
    case 2:
        quotient = 780.0f / (f32)func_80001FF0();
        if (quotient > 0.0f) {
            var = 0.5f;
        } else {
            var = -0.5f;
        }
        D_88308EB4 += (s32)((780.0f / (f32)func_80001FF0()) + var);
        if (D_88308EB4 >= D_88308EB6) {
            D_88308EB4 = D_88308EB6;
            D_88308EB1 = D_88308EB2;
            D_88308EA0 = 0;
            func_880002F4(&D_88308E18, 0);
            D_88308E04 = 0;
        }
        break;
    }
}
/* mkdraft:func_88307294 begin */
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern s32 func_8004D1FC(u8 *);
extern Gfx *D_800D0510;
extern f32 D_80088E50[];
extern f32 D_80087E50[];
extern u8 *D_88308EA4;
extern s16 D_88308EB4;
extern s16 D_88308EC0;

// Draws four copies of the texture at D_88308EA4 on a circle of radius 12
// centred at (336, D_88308EB4), the first at angle D_88308EC0 and each later
// one another 0x4000 further round (90 degrees: the sin/cos tables cover
// 0x10000 units in 4096 entries). D_80087E50 is sin, D_80088E50 is cos, both
// indexed by (u16)angle >> 4; the texture's first two u16s are its width and
// height, which centre each rectangle on its point of the circle.
//@src/340C0.c


void func_88307294(void) {
    s16 angle;
    s32 i;
    s32 index;
    u16 *texture;

    angle = D_88308EC0;
    gDPPipeSync(D_800D0510++);
    gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(D_800D0510++, 0x9B, 0x9B, 0, 0xFF);
    func_8004D1FC(D_88308EA4);
    for (i = 0; i != 4; angle -= 0x4000, i++) {
        index = (u16) angle >> 4;
        texture = (u16 *) D_88308EA4;
        GfxRect_DrawTextured(
            (s16) (s32) (((D_80088E50[index] * 12.0f) + 336.0f) - (f32) ((s32) texture[0] >> 1)),
            (s16) (s32) (((D_80087E50[index] * 12.0f) + (f32) D_88308EB4) - (f32) ((s32) texture[1] >> 1)),
            (s16) texture[0], (s16) texture[1], -0x10, -0x10, 0x400, 0x400, 0);
    }
}
/* mkdraft:func_88307294 end */

extern Gfx *D_800D0510;
extern u8 *D_88308EA8;
extern u8 *D_88308EAC;
extern s32 func_8004D1FC(u8 *);
extern s32 func_8004D27C(u8 *, s32, s32);
void func_88307468(void) {
    gDPPipeSync(D_800D0510++);
    gDPSetCombine(D_800D0510++, 0x309661, 0x552EFF7F);
    func_8004D1FC(D_88308EA8);
    func_8004D27C(D_88308EAC, 0x100, 1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B8010/func_883074E4.s")

/* mkdraft:func_8830765C begin */
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_80044424(s16, s16, s16, s16, s16, s16, s16, s16, s32, s32);
#pragma REWRITE_FUNCTION_WORD(func_8830765C, 0x84, 0x004C2021, 0x01822021)
#pragma REWRITE_FUNCTION_WORD(func_8830765C, 0x148, 0x00492021, 0x01222021)



void func_8830765C(u16 *arg0, u16 *arg1, s16 arg2, s16 arg3, u16 arg4) {
    GfxRect_DrawTextured(arg2, arg3, (s16)*arg0, (s16)(arg4 - *(arg1 + 1)),
                         -0x10, -0x10, 0x400, 0x400, 0);
    GfxRect_DrawTextured((s16)(arg2 + *arg0), arg3, *arg0,
                         (s16)(arg4 - *(arg1 + 1)),
                         (s16)((*arg0 << 5) - 0x10), -0x10, -0x400, 0x400, 0);
    func_80044424(arg2, (s16)(arg3 + arg4 - *(arg1 + 1)), (s16)*arg1,
                  (s16)*(arg1 + 1), -0x10, -0x10, 0x400, 0x400, 0, 1);
    func_80044424((s16)(arg2 + *arg1), (s16)(arg3 + arg4 - *(arg1 + 1)),
                  *arg1, (s16)*(arg1 + 1),
                  (s16)((*arg1 << 5) - 0x10), -0x10, -0x400, 0x400, 0, 1);
}
/* mkdraft:func_8830765C end */

/* mkdraft:func_8830780C begin */
extern void func_800459AC(u8 *, u8, u8, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_8004CA60(u8 *arg0);

typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4;
    u8 unk5;
} unk_func_8830780C;

typedef struct {
    s32 unk0;
    s32 unk4; // FAKE: unused second word; sizes the record so the two locals land at 0x50/0x48 (diff score 12 with plain s32 locals).
} unk_func_8830780C_pos;



void func_8830780C(unk_func_8830780C *arg0, s8 arg1) {
    unk_func_8830780C_pos var_v1;
    unk_func_8830780C_pos var_a1;

    if (!arg1) {
        var_v1.unk0 = 95;
        var_a1.unk0 = 95;
    } else {
        var_v1.unk0 = 150;
        var_a1.unk0 = 150;
    }
    func_800459AC(func_8004CA60((u8 *)arg0), arg0->unk4, arg0->unk5, arg0->unk0, arg0->unk2,
                  1, 0, 1, 2, 4, 0, 0, 0);
    GfxRect_DrawTextured(0x172, (s16)var_v1.unk0, (s16)arg0->unk0, (s16)arg0->unk2,
                         -0x10, -0x10, 0x400, 0x400, 0);
    GfxRect_DrawTextured(0x21A, (s16)var_a1.unk0, (s16)arg0->unk0, (s16)arg0->unk2,
                         (s16)((arg0->unk0 << 5) - 0x10), -0x10, 0x400, 0x400, 0);
}
/* mkdraft:func_8830780C end */

extern s32 func_8004C990(s32, s32);
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
// Tiles texture 6 of archive 264 over the rectangle (x, y, width, height),
// with func_80006F70 clipping to (clip_x, clip_y, clip_width, clip_height); the calls in
// func_88301C00 pass the same rectangle for both. The texture header holds its
// width and height in the first two u16s.
void func_88307938(s32 x, s32 y, s32 width, s32 height, s16 clip_x, s16 clip_y, s16 clip_width,
                   s32 clip_height) {
    u16 *texture;
    s32 row;
    s32 column;

    texture = (u16 *)func_8004C990(264, 6);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, 0x64, 0x6E, 0x78, 0xFF);
    func_8004D1FC((u8 *)texture);
    func_80006F70(&D_800D0510, clip_x, clip_y, clip_width, clip_height);
    //!bug The row loop starts at x instead of y.
    for (row = x; row < y + height; row += texture[1]) {
        for (column = x; column < x + width; column += texture[0]) {
            GfxRect_DrawTextured(column, row, texture[0], texture[1], 0, 0, 0x400, 0x400, 0);
        }
    }
    func_80006F70(&D_800D0510, 0, 0, 640, 480);
}
#endif
