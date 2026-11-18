#include "global.h"


#ifdef VERSION_US
void func_86407E00(u8 *arg0, f32 arg1, f32 arg2) {
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(f32 *)(arg0 + 0x00) = arg1;
    *(f32 *)(arg0 + 0x08) = arg1;
    *(f32 *)(arg0 + 0x10) = arg1;
    *(f32 *)(arg0 + 0x04) = arg2;
    *(f32 *)(arg0 + 0x0C) = arg2;
    *(f32 *)(arg0 + 0x14) = arg2;
}

void func_86407E2C(u8 *arg0, f32 arg1, f32 arg2, s32 arg3) {
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x1C) = arg3;
    *(f32 *)(arg0 + 0x10) = arg1;
    *(f32 *)(arg0 + 0x08) = *(f32 *)(arg0 + 0x00);
    *(f32 *)(arg0 + 0x14) = arg2;
    *(f32 *)(arg0 + 0x0C) = *(f32 *)(arg0 + 0x04);
}

/* mkdraft:func_86407E58 begin */
extern u32 func_87F00930(void);
extern f32 D_80088E50[];

// Eases one menu tile from its start position (0x8, 0xC) toward its end position
// (0x10, 0x14) and writes the rounded result to (0x0, 0x4). 0x18 counts elapsed
// frames and 0x1C the total: 0x18 * 180 / 0x1C degrees, scaled by 65535 / 360,
// gives the 16-bit angle whose cosine in D_80088E50 weights the end position
// against the start. The elapsed-frame counter advances only when func_87F00930
// reports that rendering advances the frame, the same test func_861086AC uses
// before GeoRender_AdvanceFrameCounter. func_86407E2C sets both positions and the
// total; func_864082A8 calls func_86408048, which eases each of the five tiles.


void func_86407E58(u8 *arg0) {
    f32 angle;
    f32 blend;
    f32 start_weight;
    f32 end_weight;
    s32 cos_index;

    if (*(s32 *)(arg0 + 0x18) >= *(s32 *)(arg0 + 0x1C)) {
        *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x1C);
    }
    if (*(s32 *)(arg0 + 0x1C) == 0) {
        start_weight = 1.0f;
        end_weight = 0.0f;
    } else {
        angle = (((f32) *(s32 *)(arg0 + 0x18) * 180.0f) / (f32) *(s32 *)(arg0 + 0x1C)) * 182.04167f;
        if (angle >= 0.0f) {
            cos_index = (s32) (angle + 0.5f);
        } else {
            cos_index = (s32) (angle - 0.5f);
        }
        end_weight = (1.0f - D_80088E50[(u16) cos_index >> 4]) * 0.5f;
        start_weight = 1.0f - end_weight;
    }
    blend = (*(f32 *)(arg0 + 0x10) * end_weight) + (*(f32 *)(arg0 + 0x08) * start_weight);
    if (blend >= 0.0f) {
        *(f32 *)(arg0 + 0x00) = (f32) (s32) (blend + 0.5f);
    } else {
        *(f32 *)(arg0 + 0x00) = (f32) (s32) (blend - 0.5f);
    }
    blend = (*(f32 *)(arg0 + 0x14) * end_weight) + (*(f32 *)(arg0 + 0x0C) * start_weight);
    if (blend >= 0.0f) {
        *(f32 *)(arg0 + 0x04) = (f32) (s32) (blend + 0.5f);
    } else {
        *(f32 *)(arg0 + 0x04) = (f32) (s32) (blend - 0.5f);
    }
    if (func_87F00930() == 0) {
        *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x18) + 1;
    }
}
/* mkdraft:func_86407E58 end */

extern u8 *D_86416C00;
extern void func_86407E58(u8 *);
void func_86408048(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    func_86407E58(temp + 0x0C);
    func_86407E58(temp + 0x2C);
    func_86407E58(temp + 0x4C);
    func_86407E58(temp + 0x6C);
    func_86407E58(temp + 0x8C);
}

void func_864080A0(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    s32 i;

    *(s32 *)(temp + 8) = 0;
    *(s32 *)(temp + 0) = -1;
    *(s32 *)(temp + 4) = -1;
    for (i = 0; i < 4; i++) {
        func_86407E00(temp + 0xC + i * 0x20, 114.0f, (f32)(240 + i * 64));
    }
    func_86407E00(temp + 0x8C, 320.0f, 86.0f);
}

void func_86408148(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_86407E2C(temp + 0xC + i * 0x20, 110.0f, (f32)(79 + i * 15), 40);
    }
    func_86407E2C(temp + 0x8C, 156.0f, 86.0f, 40);
}

/* mkdraft:func_864081E8 begin */
void func_864081E8(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    u8 *ptr;
    s32 i;

    for (i = 0x40, ptr = temp + 0xC; i != 0x110; i += 0x34, ptr += 0x20) {
        func_86407E2C(ptr, (f32)i, 198.0f, 0x14);
    }
}
/* mkdraft:func_864081E8 end */

void func_8640826C(void) {
    u8 *temp = D_86416C00 + 0xCE00;
    func_86407E2C(temp + 0x8C, -70.0f, 86.0f, 0x14);
}

extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern u32 func_8003570C(void);
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern void func_8004D1FC(void *);
// Defined without parameters in fragment64; this caller passes the display
// list it just queued, which is what keeps the address in a0 across the call.
extern void func_87F061F0(u32);
extern void func_87F06240(s32, s32, f32, f32, s32);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_87F0D600(void *, s32, s32, s32, f32, f32);
extern void func_87F0CB68(void);

#define MENU_NODE (*(u8 **)(D_86416C00 + 0x8000 + 0x4DFC))
// Rounds half away from zero when added to x.
#define HALF_ROUND(x) (((x) > 0.0f) ? 0.5f : -0.5f)
// The five eased tiles start at state + 0xC and are 0x20 bytes (8 floats)
// apart, so float 3 of row n is tile n's x and float 4 its y. Entry i of the
// 0x5C-byte table at D_86416C00 + 0xCBA0 picks the tile for slot i.
#define SLOT_TILE(i) ((f32 (*)[8])state)[*(s32 *)(D_86416C00 + 0x8000 + (i) * 0x5C + 0x4BA0)]

// Draws the menu's frame and its four slots. While the menu node's counter at
// 0xC is below 2, the frame's environment colour fades from the colour at
// state + 0 to the one at state + 4 over ten frames, and a new random colour is
// picked each time the fade ends; otherwise the frame is drawn plainly and the
// counter is shown as a digit. Each slot then gets the icon chosen by its bit in
// the flags byte at 0x2182 (texture 6 + i when set, 2 + i when clear), scaled
// by 0.56, and func_87F0D600 is called with each slot's tile position.
void func_864082A8(void) {
    u8 *state;
    s32 tex_id;
    u16 *tex;
    s32 i;
    f32 f, k, sc;

    state = D_86416C00 + 0xCE00;
    if (*(u8 *)(*(u8 **)(D_86416C00 + 0x70) + 0x2180) == 4) {
        return;
    }
    func_86408048();
    if (*(s32 *)(MENU_NODE + 0xC) < 2) {
        *(s32 *)(state + 8) += 1;
        if (*(s32 *)(state + 8) >= 10) {
            *(s32 *)(state + 0) = *(s32 *)(state + 4);
            *(s32 *)(state + 8) = 0;
            *(u32 *)(state + 4) = ((func_8003570C() & 0xFF) << 24) | ((func_8003570C() & 0xFF) << 16) |
                                  ((func_8003570C() & 0xFF) << 8) | 0xFF;
        }
        f = (f32)*(s32 *)(state + 8) / 10.0f;
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetCombine(D_800D0510++, 0x50D2A1, 0xFFA7FFFF);
        {
            Gfx *_g = D_800D0510++;

            _g->words.w0 = _SHIFTL(G_SETENVCOLOR, 24, 8);
            _g->words.w1 = _SHIFTL((u32)((f32)state[1] * (1.0f - f) + (f32)state[5] * f), 16, 8) |
                           _SHIFTL((u32)((f32)state[2] * (1.0f - f) + (f32)state[6] * f), 8, 8) |
                           _SHIFTL((u32)((f32)state[4] * f + (f32)state[0] * (1.0f - f)), 24, 8) |
                           _SHIFTL(0xFF, 0, 8);
        }
        tex_id = func_8004C990(0x181, 0);
        func_8004D19C((s32)(*(f32 *)(state + 0x8C) - 6.0f), (s32)(*(f32 *)(state + 0x90) + 10.0f), tex_id, 0, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
    } else {
        gSPDisplayList(D_800D0510++, D_80094E38);
        tex_id = func_8004C990(0x182, 0);
        func_8004D19C((s32)*(f32 *)(state + 0x8C), (s32)*(f32 *)(state + 0x90), tex_id, 0, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
        func_87F061F0(D_80094F50);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0xE1, 0xF0, 0xFF, 0xFF);
        gDPSetEnvColor(D_800D0510++, 0, 0, 0, 0xFF);
        func_87F06240((s32)(*(f32 *)(state + 0x8C) + 20.0f), (s32)(*(f32 *)(state + 0x90) + 20.0f), 0.7f, 0.7f,
                      *(s32 *)(MENU_NODE + 0xC));
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    tex_id = func_8004C990(0x183, 0);
    func_8004D19C((s32)*(f32 *)(state + 0xC), (s32)*(f32 *)(state + 0x10), tex_id, 0, 0);
    tex_id = func_8004C990(0x183, 1);
    func_8004D19C((s32)*(f32 *)(state + 0x2C), (s32)*(f32 *)(state + 0x30), tex_id, 0, 0);
    tex_id = func_8004C990(0x183, 2);
    func_8004D19C((s32)*(f32 *)(state + 0x4C), (s32)*(f32 *)(state + 0x50), tex_id, 0, 0);
    tex_id = func_8004C990(0x183, 3);
    func_8004D19C((s32)*(f32 *)(state + 0x6C), (s32)*(f32 *)(state + 0x70), tex_id, 0, 0);
    k = 0.56f;
    sc = 0.56f;
    k = 1024.0f / k;
    for (i = 0; i < 4; i++) {
        tex = (u16 *)func_8004C990(0x1B2, ((*(u8 *)(*(u8 **)(D_86416C00 + 0x70) + 0x2182) & (1 << i)) ? 6 : 2) + i);
        func_8004D1FC(tex);
        GfxRect_DrawTextured((s16)(SLOT_TILE(i)[3] + 18.0f), (s16)SLOT_TILE(i)[4],
                             (s16)((f32)tex[0] * sc + HALF_ROUND((f32)tex[0] * sc)),
                             (s16)((f32)tex[1] * sc + HALF_ROUND((f32)tex[1] * sc)), 0, 0,
                             (s16)(HALF_ROUND(k) + k), (s16)(HALF_ROUND(k) + k), 0);
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    for (i = 0; i < 4; i++) {
        func_87F0D600(D_86416C00 + 0x74, i, (s32)(SLOT_TILE(i)[3] + 18.0f), (s32)SLOT_TILE(i)[4], sc, sc);
    }
    func_87F0CB68();
}
#endif
