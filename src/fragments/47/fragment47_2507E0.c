#include "global.h"

#ifdef VERSION_US

const s16 D_8600D990[4][2] = { {22, 19}, {270, 19}, {22, 202}, {270, 202} };
const s16 D_8600D9A0[8] = {6, 7, 8, 9, 2, 3, 4, 5};
const s16 D_8600D9B0[4][2] = { {50, 22}, {254, 22}, {50, 203}, {254, 205} };
const s16 D_8600D9C0[4][2] = { {15, 0}, {-15, 0}, {15, 0}, {-15, 0} };
const s16 D_8600D9D0[6] = {0, 1, 2, 3, 2, 1};

s32 func_8600A1C0(f32 arg0) {
    s32 temp_v1;

    temp_v1 = (s32) arg0 & 0x1F;
    return ((temp_v1 << 0xA) + (s32) (((arg0 - (f32) temp_v1) + 0.000488f) * 1024.0f)) & 0xFFFF;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_2507E0/func_8600A20C.s")

extern u8 *func_8004CA60(u8 *);
extern s32 func_8004CA38(u8 *);
extern s32 func_8004CA4C(u8 *);
extern void func_8600A20C(s16, s16, u16, u16, s32, s32, u8 *, s32, s32, s32);
extern s32 func_8004CA10(u16 *);
extern s32 func_8004CA24(u16 *);
void func_8600A5B0(s16 arg0, s16 arg1, u16 arg2, u16 arg3, void *arg4) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp24 = 1;
    u8 *sp34;

    sp44 = func_8004CA10((u16 *)arg4);
    sp40 = func_8004CA24((u16 *)arg4);
    sp34 = func_8004CA60((u8 *)arg4);
    sp3C = func_8004CA38((u8 *)arg4);
    func_8600A20C(arg0, arg1, arg2, arg3, sp44, sp40, sp34, sp3C, func_8004CA4C((u8 *)arg4), sp24);
}

extern Gfx *D_800D0510;
void func_8600A650(f32 x, f32 y, f32 width, f32 height, s16 s, s16 t, f32 horizontal_scale, f32 vertical_scale) {
    f32 right;
    f32 bottom;

    if ((width < 0) || (height < 0) || (320.0f <= x) || (240.0f <= y)) {
        return;
    }
    right = x + width;
    if (right < 0) {
        return;
    }
    bottom = y + height;
    if (bottom < 0) {
        return;
    }
    if (x < 0) {
        s -= x * horizontal_scale;
        width += x;
        x = 0;
    }
    right = x + width;
    if (y < 0) {
        t -= y * vertical_scale;
        height += y;
        y = 0;
    }
    bottom = y + height;
    //!bug Far-edge clipping retains the excess span instead of the visible span.
    if (320.0f <= right) {
        width -= 320.0f - x;
    }
    if (240.0f <= bottom) {
        height -= 240.0f - y;
    }
    right = x + width;
    bottom = y + height;
    gSPScisTextureRectangle(D_800D0510++, x * 4.0f, y * 4.0f, right * 4.0f, bottom * 4.0f, G_TX_RENDERTILE, s << 5, t << 5, (s16)(horizontal_scale * 1024.0f), (s16)(vertical_scale * 1024.0f));
}

extern u8 D_8600D3F0[];
extern u8 D_8600D400;
u8 *func_8600AAA4(s32 arg0) {
    u8 *result;
    if (arg0 >= 0 && arg0 < 4) {
        result = D_8600D3F0 + (arg0 * 4);
    } else {
        result = &D_8600D400;
    }
    return result;
}

extern s32 func_8004C8C0(s32);
extern void func_87F061D0(void);
s32 func_8004C990(s32, s32);
extern s32 D_8600DE10;
extern s32 D_8600DE14;
extern s32 D_8600DE18;
extern s32 D_8600DE1C;
extern s32 D_8600DE20;
void func_8600AAD4(void) {
    func_87F061D0();
    func_8004C8C0(434);
    func_8004C8C0(401);
    func_8004C8C0(402);
    D_8600DE10 = func_8004C990(401, 0);
    D_8600DE14 = func_8004C990(401, 1);
    D_8600DE18 = func_8004C990(401, 2);
    D_8600DE1C = func_8004C990(401, 3);
    D_8600DE20 = func_8004C990(401, 4);
}

extern void func_87F0D600(void *, s32, s32, s32, f32, f32);
extern s32 func_8004D1FC(u8 *);
extern u8 D_80094E38[];
extern u8 D_80094F50[];
void func_8600AB6C(s32 slot, s32 variant, void *context) {
    u8* texture;

    texture = (u8 *)func_8004C990(434, D_8600D9A0[slot + variant * 4]);
    func_8004D1FC(texture);
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_8600A650(
        (f32)D_8600D990[slot][0], (f32)D_8600D990[slot][1],
        func_8004CA10((u16 *)texture) * 0.8f, func_8004CA24((u16 *)texture) * 0.8f,
        0, 0, 1.25f, 1.25f);
    gSPDisplayList(D_800D0510++, D_80094F50);
    func_87F0D600(context, slot, D_8600D990[slot][0], D_8600D990[slot][1], 0.8f, 0.8f);
}

extern void func_87F06240(s32, s32, f32, f32, s32);
void func_8600ACC4(void *arg0, s32 arg1, s32 arg2, void *arg3, void *arg4) {
    struct ACC4Color { u8 r, g, b, a; };
    gDPSetPrimColor(D_800D0510++, 0, 0, ((struct ACC4Color *)arg3)->r, ((struct ACC4Color *)arg3)->g, ((struct ACC4Color *)arg3)->b, ((struct ACC4Color *)arg3)->a);
    gDPSetEnvColor(D_800D0510++, ((struct ACC4Color *)arg4)->r, ((struct ACC4Color *)arg4)->g, ((struct ACC4Color *)arg4)->b, 0xFF);
    if ((s32)arg0 >= 100) {
        func_87F06240(arg1 + 9, arg2 + 4, 0.7f, 0.61f, (s32)arg0 / 10);
        func_87F06240(arg1 + 25, arg2 + 4, 0.7f, 0.61f, (s32)arg0);
    } else if ((s32)arg0 >= 10) {
        func_87F06240(arg1 + 9, arg2 + 4, 0.7f, 0.61f, (s32)arg0 / 10);
        func_87F06240(arg1 + 25, arg2 + 4, 0.7f, 0.61f, (s32)arg0);
    } else if ((s32)arg0 >= 0) {
        func_87F06240(arg1 + 17, arg2 + 4, 0.7f, 0.61f, (s32)arg0);
    }
}

void func_8600AE6C(u8 *arg0) {
    s32 i;

    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
    for (i = 0; i < *(s32 *)(arg0 + 0x1814); i++) {
        const s32 texture = (&D_8600DE10)[(s8)arg0[0x1990 + i] + 1];
        func_8004D1FC((u8 *)texture);
        func_8600A650(
            (f32)(D_8600D9B0[*(s32 *)(arg0 + 0x1810)][0] + D_8600D9C0[*(s32 *)(arg0 + 0x1810)][0] * i),
            (f32)(D_8600D9B0[*(s32 *)(arg0 + 0x1810)][1] + D_8600D9C0[*(s32 *)(arg0 + 0x1810)][1] * i),
            (f32)func_8004CA10((u16 *)texture),
            (f32)func_8004CA24((u16 *)texture),
            0, 0, 1.0f, 1.0f);
    }
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, 100);
    func_8004D1FC((u8 *)D_8600DE10);
    for (; i < 5; i++) {
        func_8600A650(
            (f32)(D_8600D9B0[*(s32 *)(arg0 + 0x1810)][0] + D_8600D9C0[*(s32 *)(arg0 + 0x1810)][0] * i),
            (f32)(D_8600D9B0[*(s32 *)(arg0 + 0x1810)][1] + D_8600D9C0[*(s32 *)(arg0 + 0x1810)][1] * i),
            (f32)func_8004CA10((u16 *)D_8600DE10),
            (f32)func_8004CA24((u16 *)D_8600DE10),
            0, 0, 1.0f, 1.0f);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_2507E0/func_8600B100.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_2507E0/func_8600B328.s")

void func_8600B468(u8 *arg0, s32 arg1) {}

extern void func_8600B100(void *);
extern void func_8600B328(void *);
extern void func_87F061F0(void);
extern u8 D_8600D43C[];
extern u8 D_8600D440[];
void func_8600B474(void *arg0, void *arg1) {
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_8600B100(arg1);
    func_8600B328(arg1);
    gSPDisplayList(D_800D0510++, D_80094F50);
    func_87F061F0();
    func_8600ACC4(arg0, 0x86, 0x10, D_8600D440, D_8600D43C);
}

void func_8600B51C(s32 arg0, s32 arg1) {
    s32 left;
    s32 top;
    s32 draw_width;
    s32 height;
    s32 width;
    u8* texture;

    texture = (u8 *)func_8004C990(401, 0);
    func_8004D1FC(texture);
    width = func_8004CA10((u16 *)texture);
    height = func_8004CA24((u16 *)texture);
    draw_width = func_8004CA10((u16 *)texture);
    left = arg0 - width / 2;
    top = arg1 - height / 2;
    func_8600A650(
        (f32)left,
        (f32)top,
        (f32)draw_width,
        (f32)func_8004CA24((u16 *)texture),
        0, 0, 1.0f, 1.0f
    );
}
#endif
