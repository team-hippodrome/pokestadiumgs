#include "global.h"


#ifdef VERSION_US
extern Gfx *D_800D0510;
extern Gfx D_88006030[];
extern u8 D_8800EF30[];
extern s16 D_8800EF32;
extern s32 Envelope_Advance(void *);
extern s32 func_8004C8C0();
extern s32 func_8004C990(s32, s32);
extern s32 D_8800EF3C;
void func_88004FF0(s32 archive) {
    s32 entry;
    func_8004C8C0(archive);
    switch (archive) {
    case 0x3A:
        entry = 0;
        break;
    case 0x3B:
        entry = 0;
        break;
    }
    D_8800EF3C = func_8004C990(archive, entry);
}

extern s32 func_80001FF0(void);
extern void func_88000288(void *, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_8800EF30[];
void func_88005048(void) {
    func_88000288(D_8800EF30, 0, 0xFF, 0x96, (s32)((f32)0 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)0 / 60.0f > 0.0f) ? 0.5f : -0.5f)), (s32)((f32)40 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)40 / 60.0f > 0.0f) ? 0.5f : -0.5f)), (s32)((f32)0 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)0 / 60.0f > 0.0f) ? 0.5f : -0.5f)), (s32)((f32)40 * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)40 / 60.0f > 0.0f) ? 0.5f : -0.5f)));
}

void func_8800528C(s32 mode) {
    gSPDisplayList(D_800D0510++, D_88006030);
    if (mode) {
        gDPSetRenderMode(D_800D0510++, 0x00504340, 0);
        gDPSetEnvColor(D_800D0510++, 150, D_8800EF32, 255, 128);
    } else {
        gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
        gDPSetEnvColor(D_800D0510++, 150, Envelope_Advance(D_8800EF30), 255, 255);
    }
}

extern Gfx D_80094DE0[];
extern s32 func_8004D1FC(u8 *);
extern void func_80044270(s16, s16, s16, s16, s16, s16, s16, s16, s32);
/* The legacy wrapper forwards an opaque fourth argument that retail ignores. */
#ifdef CC_CHECK
void func_88005390(s32 mode, s16 width, s16 height, void *unused) {
#else
void func_88005390(mode, width, height)
s32 mode;
s16 width;
s16 height;
{
#endif
    s16 textureWidth = *(s16 *)(u32)D_8800EF3C;
    s16 textureHeight = *(s16 *)((u8 *)(u32)D_8800EF3C + 2);
    s16 halfWidth = width >> 1;
    s16 halfHeight = height >> 1;
    s32 stepX = (s32)((((f32)textureWidth * 1024.0f / (f32)halfWidth > 0.0f) ? 0.5f : -0.5f) +
                     ((f32)textureWidth * 1024.0f / (f32)halfWidth));
    s32 stepY;
    stepY = (s32)((((f32)textureHeight * 1024.0f / (f32)halfHeight > 0.0f) ? 0.5f : -0.5f) +
                 ((f32)textureHeight * 1024.0f / (f32)halfHeight));
    func_8800528C(mode);
    func_8004D1FC((u8 *)(u32)D_8800EF3C);
    func_80044270(0, 0, halfWidth, halfHeight, -16, -16, stepX, stepY, 0);
    func_80044270(halfWidth, 0, halfWidth, halfHeight, ((textureWidth - 1) << 5) + 16, -16, -stepX, stepY, 0);
    func_80044270(0, halfHeight, halfWidth, halfHeight, -16, ((textureHeight - 1) << 5) + 16, stepX, -stepY, 0);
    func_80044270(halfWidth, halfHeight, halfWidth, halfHeight, ((textureWidth - 1) << 5) + 16,
                  ((textureHeight - 1) << 5) + 16, -stepX, -stepY, 0);
    if ((width & 1) || (height & 1)) {
        gSPDisplayList(D_800D0510++, D_80094DE0);
        gDPSetFillColor(D_800D0510++, 0x00010001);
        if (width & 1) gDPFillRectangle(D_800D0510++, width - 1, 0, width - 1, height - 1);
        if (height & 1) gDPFillRectangle(D_800D0510++, 0, height - 1, width - 1, height - 1);
    }
}

void func_88005714(void *arg0) {
    func_88005390(0, (*(s16 *)((u8 *)(arg0) + (4))), (*(s16 *)((u8 *)(arg0) + (6))), arg0);
}

extern s8 D_8800EF40;
extern u8 D_8800EF41;
extern s16 D_8800EF42;
extern s16 D_8800EF44;
extern u8 *D_8800ECC0;
extern u8 *D_8800ECC4;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern void func_8004C594(s32, s32);
extern void *func_8004C874(s32, s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern s32 func_800472E0(u8 *);
extern s32 func_88002958(u8 **, u16, s32, s16);
extern s32 func_8004D27C(u8 *, s32, s32);
extern s32 func_8004CA10(u8 *);
extern void func_88002C2C(u8, u8, u8);
extern void func_88002BA0(u8, u8, u8);
extern void func_88002CB8(s16, s16, u16, u16);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004989C(s32);
extern void func_80049064(s32, s32, s32, u8 *);
extern void func_800499EC(void);

#define MAX_88005740(a, b) ((a) > (b) ? (a) : (b))

void func_88005740(void) {
    s32 i;
    s16 x;
    s16 y;
    s16 w;
    u8 buf[0x80];
    u8 *strs[4];
    u8 lens[4];
    u8 count;
    s16 ys[4];
    s32 n;

    func_8004C594(1, D_8800EF41 + 1);
    strs[0] = func_8004C874(0x27, 9);
    strs[1] = func_8004C8A0(buf, 0x80, 0x27, 10);
    strs[2] = func_8004C874(0x27, 11);
    strs[3] = func_8004C874(0x27, 12);
    for (i = 0; i < 4; i++) {
        lens[i] = func_800472E0(strs[i]);
    }
    // FAKE: puts the lens[1]/lens[2] values ahead of the MAX temp in uopt's item order.
    if (lens[1] > lens[2] && lens[2] > lens[1]) {}
    n = MAX_88005740(lens[0], MAX_88005740(lens[1], lens[2]));
    count = lens[3] + n + 1;
    w = func_88002958(strs, 4, 8, 1) + 0x21;
    x = D_8800EF42 - (w >> 1);
    y = D_8800EF44 - ((s16)(count * 20 + count * 6 + 23) >> 1);
    for (i = 0; i < 3; i++) {
        ys[i] = y + 13;
    }
    // FAKE: keeps lens[1]/lens[2] live past the box height so its spill lands at 0x3C.
    if (lens[1] > lens[2] && lens[2] > lens[1]) {}
    ys[3] = y + (count - lens[3]) * 26 + 13;
    func_8004D1FC(D_8800ECC4);
    func_8004D27C(D_8800ECC0, 0x80, 1);
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_88002C2C(0xFF, 0xAA, 0x8C);
    // One line: as1 fills the delay slot as retail does.
    n = func_8004CA10(D_8800ECC4); GfxRect_DrawTextured(x + 5, y + 5, w - 13, (s16)(count * 20 + count * 6 + 23) - 13, 0, 0, (s32)((((f32)func_8004CA10(D_8800ECC4) * 1024.0f / (f32)(w - 13)) > 0.0f ? 0.5f : -0.5f) + 1024.0f * (f32)n / (f32)(w - 13)), 0, 0);
    func_88002BA0(0xFF, 0xAA, 0x8C);
    func_88002CB8(x, y, w, (s16)(count * 20 + count * 6 + 23));
    gSPDisplayList(D_800D0510++, D_80094F50);
    func_800498C4();
    func_800496A4(8, 1);
    func_8004989C(0x1A);
    switch (D_8800EF40) {
        case 0:
            func_80049064(D_8800EF42, ys[0], 1, strs[0]);
            break;
        case 2:
            func_80049064(D_8800EF42, ys[1], 1, strs[1]);
            break;
        case 3:
            func_80049064(D_8800EF42, ys[2], 1, strs[2]);
            break;
    }
    if (D_8800EF40 != 0) {
        func_80049064(D_8800EF42, ys[3], 1, strs[3]);
    }
    func_800499EC();
}

#endif
