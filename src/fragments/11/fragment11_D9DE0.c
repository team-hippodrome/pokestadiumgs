#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81602240.s")

extern void func_80006F70(Gfx **, s16, s16, s16, s16);

void Fragment11_SetClippedScissor(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    if (arg3 < 0) {
        arg3 = 0;
    }
    if (arg4 < 0) {
        arg4 = 0;
    }
    func_80006F70(arg0, arg1, arg2, arg3, arg4);
}
extern s32 func_8004C990(s32, s32);
s32 func_81602940(s32 arg0) {
    switch (arg0) {
    case 7:
        return func_8004C990(0x14C, 0);
    case 26:
        return func_8004C990(0x14C, 1);
    case 23:
        return func_8004C990(0x14C, 2);
    case 27:
        return func_8004C990(0x14C, 4);
    case 1:
        return func_8004C990(0x14C, 5);
    case 20:
        return func_8004C990(0x14C, 6);
    case 2:
    case 6:
        return func_8004C990(0x14C, 7);
    case 8:
        return func_8004C990(0x14C, 8);
    case 22:
        return func_8004C990(0x14C, 9);
    case 4:
        return func_8004C990(0x14C, 10);
    case 25:
        return func_8004C990(0x14C, 11);
    case 0:
        return func_8004C990(0x14C, 12);
    case 3:
        return func_8004C990(0x14C, 13);
    case 24:
        return func_8004C990(0x14C, 14);
    case 5:
        return func_8004C990(0x14C, 15);
    case 9:
        return func_8004C990(0x14C, 16);
    case 21:
        return func_8004C990(0x14C, 17);
    case 19:
        return func_8004C990(0x14C, 3);
    default:
        return func_8004C990(0x14C, 12);
    }
}

extern f32 func_816092FC(void);
s32 func_81602AEC(u8 *arg0, u8 *arg1) {
    s32 changed = (arg0 == 0) * 0;
    s32 step = (s32)(func_816092FC() * 0.4f);
    if (step <= 0) step = 1;
    if (arg1[0] != arg0[0]) {
        changed = 1;
        if ((arg0[0] - arg1[0] > 0 ? arg0[0] - arg1[0] : -(arg0[0] - arg1[0])) <= step) {
            arg0[0] = arg1[0];
        } else if (arg0[0] < arg1[0]) {
            arg0[0] = arg0[0] + step;
        } else if (arg1[0] < arg0[0]) {
            arg0[0] = arg0[0] - step;
        }
    }
    if (arg1[1] != arg0[1]) {
        changed = 1;
        if ((arg0[1] - arg1[1] > 0 ? arg0[1] - arg1[1] : -(arg0[1] - arg1[1])) <= step) {
            arg0[1] = arg1[1];
        } else if (arg0[1] < arg1[1]) {
            arg0[1] = arg0[1] + step;
        } else if (arg1[1] < arg0[1]) {
            arg0[1] = arg0[1] - step;
        }
    }
    if (arg1[2] != arg0[2]) {
        changed = 1;
        if ((arg0[2] - arg1[2] > 0 ? arg0[2] - arg1[2] : -(arg0[2] - arg1[2])) <= step) {
            arg0[2] = arg1[2];
        } else if (arg0[2] < arg1[2]) {
            arg0[2] = arg0[2] + step;
        } else if (arg1[2] < arg0[2]) {
            arg0[2] = arg0[2] - step;
        }
    }
    return changed;
}

extern u8 D_8160BDF8[];
extern u8 D_8160BDFC[];
extern u8 D_8160BE00[];
extern u8 D_8160BE04[];
extern u8 D_8160BE08[];
extern u8 D_8160BE0C[];
extern u8 D_8160BE10[];
extern u8 D_8160BE14[];
extern u8 D_8160BE18[];
extern u8 D_8160BE1C[];
extern u8 D_8160BE20[];
extern u8 D_8160BE24[];
extern u8 D_8160BE28[];
extern u8 D_8160BE2C[];
extern u8 D_8160BE30[];
extern u8 D_8160BE34[];
extern u8 D_8160BE38[];
extern u8 D_8160BE3C[];
void *func_81602C68(arg0)
    s32 arg0;
{
    switch (arg0) {
    case 7:
        return D_8160BDF8;
    case 26:
        return D_8160BE00;
    case 23:
        return D_8160BE08;
    case 27:
        return D_8160BE18;
    case 1:
        return D_8160BE20;
    case 20:
        return D_8160BE28;
    case 2:
    case 6:
        return D_8160BE30;
    case 8:
        return D_8160BE38;
    case 22:
        return D_8160BDFC;
    case 4:
        return D_8160BE04;
    case 25:
        return D_8160BE0C;
    case 0:
        return D_8160BE14;
    case 3:
        return D_8160BE1C;
    case 24:
        return D_8160BE24;
    case 5:
        return D_8160BE2C;
    case 9:
        return D_8160BE34;
    case 21:
        return D_8160BE3C;
    case 19:
        return D_8160BE10;
    default:
        return D_8160BE14;
    }
}

extern u8 D_8160BE40;
extern u8 D_8160BE4C;

s32 *func_81602D70(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        return (arg0 * 3) + &D_8160BE40;
    }
    return &D_8160BE4C;
}

extern void func_8004972C(u8, u8, u8, s32);
void *func_81602C68();

void func_81602DA4(void) {
    void *temp_v0;

#ifdef CC_CHECK
    temp_v0 = func_81602C68(0);
#else
    temp_v0 = func_81602C68();
#endif
    func_8004972C((*(u8 *)((u8 *)(temp_v0) + (0))), (*(u8 *)((u8 *)(temp_v0) + (1))), (*(u8 *)((u8 *)(temp_v0) + (2))), 0xFF);
}

extern void func_8004C8C0(s32);
extern void func_8004C4B0(s32);
extern s32 func_8004C990(s32, s32);
extern s32 D_8160BD50;
extern s32 D_8160BD54;
extern s32 D_8160BD58;
extern s32 D_8160BD5C;
extern s32 D_8160BD60;
extern s32 D_8160BD64;
extern s32 D_8160BD68;
extern s32 D_8160BD74;
extern s32 D_8160BD7C;
extern s32 D_8160BD80;
extern s32 D_8160BD84;
extern s32 D_8160BD8C;
extern s32 D_8160BD88;
extern s32 D_8160BD98;
extern s32 D_8160BD9C;
extern s32 D_8160BDA0;
extern s32 D_8160BDA4;
extern s32 D_8160BDA8;
extern s32 D_8160BDAC;
extern s32 D_8160BDB0;
extern s32 D_8160BDBC;
extern s32 D_8160BDC0;
extern s32 D_8160BDCC;
extern s32 D_8160BDD0;
extern s32 D_8160BDD4;
extern s32 D_8160BDD8;
extern s32 D_8160BDDC;
extern s32 D_8160BDE0;
extern s32 D_8160BDE4;
extern s32 D_8160BDE8;
extern s32 D_8160BDEC;
extern s32 D_8160BDF0;
extern void *D_8160BD6C;
extern void *D_8160BD78[];
extern void *D_8160BD90;
extern void *D_8160BD94;
extern void *D_8160BDB4;
extern void *D_8160BDB8;
void func_81602DD8(void) {
    func_8004C8C0(0x14C);
    func_8004C8C0(0x103);
    func_8004C8C0(0x102);
    func_8004C8C0(0x101);
    func_8004C8C0(0x100);
    func_8004C8C0(0x107);
    func_8004C8C0(0x104);
    func_8004C8C0(0xEF);
    func_8004C8C0(0x1B);
    func_8004C8C0(0x34);
    func_8004C8C0(0x9A);
    func_8004C8C0(0x79);
    func_8004C8C0(0x33);
    func_8004C8C0(0x2F);
    func_8004C4B0(8);
    func_8004C4B0(9);
    func_8004C4B0(12);
    func_8004C4B0(13);
    func_8004C4B0(6);
    D_8160BD50 = func_8004C990(0x1B, 0);
    D_8160BD54 = func_8004C990(0x101, 4);
    D_8160BD58 = func_8004C990(0x107, 1);
    D_8160BD5C = func_8004C990(0x102, 0);
    D_8160BD60 = func_8004C990(0x101, 5);
    D_8160BD64 = func_8004C990(0x100, 1);
    D_8160BD68 = func_8004C990(0x100, 0);
    D_8160BD6C = (void *)func_8004C990(0x107, 0);
    D_8160BD74 = func_8004C990(0x104, 4);
    D_8160BD78[0] = (void *)func_8004C990(0x104, 0);
    D_8160BD7C = func_8004C990(0x104, 1);
    D_8160BD80 = func_8004C990(0x104, 2);
    D_8160BD84 = func_8004C990(0x104, 3);
    D_8160BD8C = func_8004C990(0x103, 2);
    D_8160BD88 = func_8004C990(0x103, 3);
    D_8160BD90 = (void *)func_8004C990(0x34, 1);
    D_8160BD94 = (void *)func_8004C990(0x34, 0);
    D_8160BD98 = func_8004C990(0xEF, 0);
    D_8160BD9C = func_8004C990(0x103, 0);
    D_8160BDA0 = func_8004C990(0x103, 1);
    D_8160BDA4 = func_8004C990(0x101, 1);
    D_8160BDA8 = func_8004C990(0x101, 2);
    D_8160BDAC = func_8004C990(0x101, 3);
    D_8160BDB0 = func_8004C990(0x101, 0);
    D_8160BDB4 = (void *)func_8004C990(0x9A, 0);
    D_8160BDB8 = (void *)func_8004C990(0x103, 4);
    D_8160BDBC = func_8004C990(0x42, 0);
    D_8160BDC0 = func_8004C990(0x41, 0);
    D_8160BDCC = func_8004C990(0x39, 6);
    D_8160BDD0 = func_8004C990(0x39, 5);
    D_8160BDD4 = func_8004C990(0x39, 1);
    D_8160BDD8 = func_8004C990(0x39, 8);
    D_8160BDDC = func_8004C990(0x39, 4);
    D_8160BDE0 = func_8004C990(0x39, 7);
    D_8160BDE4 = func_8004C990(0x39, 2);
    D_8160BDE8 = func_8004C990(0x39, 3);
    D_8160BDEC = func_8004C990(0x39, 0);
    D_8160BDF0 = func_8004C990(0x39, 9);
}

extern void func_8004C8C0();
extern void func_81602DD8();
void func_8160317C(void) { func_8004C8C0(66); func_8004C8C0(65); func_81602DD8(); }

extern void func_8004C4B0(s32); extern void func_8004C8C0(s32); extern void func_81602DD8(void);
void func_816031AC(void) {
    func_8004C4B0(0x19);
    func_8004C4B0(0x17);
    func_8004C8C0(0x39);
    func_8004C8C0(0x42);
    func_8004C8C0(0x41);
    func_81602DD8();
}

void func_816031F4(void) {
    func_8004C4B0(0xF);
    func_8004C4B0(7);
    func_8004C4B0(0x17);
    func_8004C8C0(0x30);
    func_8004C8C0(0x39);
    func_8004C8C0(0x11B);
    func_8004C8C0(0x9F);
    func_81602DD8();
}

extern u32 D_800D0510;
extern u8 D_80094E38[];
extern void func_8004D1FC(void *);

void func_8160324C(f32 alpha) {
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
    gDPPipeSync((*(Gfx **)&D_800D0510)++);
    gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 100, 255, 255, 255.0f * alpha);
    func_8004D1FC(D_8160BDB8);
}

void func_8160335C(u8 *arg0, s32 arg1) {}


extern s32 GbSave_GetPortAvailability(s32);
extern u8 func_8005D92C(s32);
s32 func_81603368(s32 arg0) {
    if (GbSave_GetPortAvailability(arg0)) {
        return -1;
    }
    switch (func_8005D92C(arg0)) {
        case 0:
            return 7;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        default:
            return 7;
    }
}

extern s32 func_8005D8CC(s32);
extern s32 func_80057A80(s32);
extern s32 func_8005F37C(u8, u16 *, u8 *, u8 *, u8 *);
extern s32 func_8005DE68(s32);
extern s32 func_8005DE8C(s32);
extern s32 func_8005DDF8(s32);
extern s32 func_8005DDD4(s32);
extern u8 func_8005D92C(s32);
s32 func_81603404(s32 arg0, s32 arg1)
{
    s32 status;
    s32 new_var;
    u16 out0;
    u8 out1;
    u8 out2;
    u8 out3;
    s32 pad1;

    status = func_8005D8CC(arg0);
    if ((status == 1) || (status == 4)) {
        return 2;
    }
    new_var = status;
    if ((arg1 & 2) && (func_8005D92C(arg0) != 7)) {
        return 5;
    }
    if ((arg1 & 1) && func_80057A80(arg0)) {
        return 4;
    }
    if ((arg1 & 4) && ((new_var == 3) || (new_var == 5))) {
        return 6;
    }
    if (new_var == 2) {
        return 3;
    }
    if ((arg1 & 0x80) && func_8005F37C((u8)arg0, &out0, &out1, &out2, &out3)) {
        return 1;
    }
    if ((arg1 & 8) && !func_8005DE68(arg0)) {
        return 7;
    }
    if ((arg1 & 0x10) && !func_8005DE8C(arg0)) {
        return 8;
    }
    if ((arg1 & 0x20) && !func_8005DDF8(arg0)) {
        if ((arg1 && arg1) && arg1) {
        }
        return 9;
    }
    if ((arg1 & 0x40) && !func_8005DDD4(arg0)) {
        return 10;
    }
    return 0;
}

extern s32 func_8004CA10(void *);
extern s32 func_8004CA24(void *);
extern s32 func_8004D19C(s32, s32, void *, s32, s32);
extern void func_8004D1FC(void *);
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];

// Draws the image in entry imageIndex of the table at D_8160BDCC (resource 0x39
// images loaded by func_81602DD8) twice: a black copy offset by (6, 6), then a
// white copy at (x, y). Below an alpha of 0.99 both copies are faded through the
// environment alpha; otherwise they are drawn opaque with render mode 0x0F0A7008.
// For the eight entries D_8160BDCC..D_8160BDE8 (D_8160BDEC is the first address
// past them) an iconIndex of 0-3 also draws resource 0x104 image iconIndex,
// scaled to 0.8, at (x + 10, y + 26). fragment14_FCD40.c passes iconIndex -1.
//@src/fragments/14/fragment14_FCD40.c
void func_81603598(s32 x, s32 y, s32 imageIndex, s32 iconIndex, f32 alpha) {
    void *texture;

    if (imageIndex >= 0) {
        texture = *(void **)(&D_8160BDCC + imageIndex);
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
        if (alpha < 0.99f) {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 0, 0, 0, 255.0f * alpha);
        } else {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 0, 0, 0, 255);
            gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0, 0x0F0A7008);
        }
        func_8004D19C(x + 6, y + 6, texture, 0, 0);
        if (alpha < 0.99f) {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 255, 255, 255, 255.0f * alpha);
        } else {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 255, 255, 255, 255);
            gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0, 0x0F0A7008);
        }
        func_8004D19C(x, y, texture, 0, 0);
        // The range test compares the entry's address with the table bounds.
        if ((&D_8160BDCC + imageIndex >= &D_8160BDCC) && (&D_8160BDCC + imageIndex < &D_8160BDEC) &&
            (iconIndex >= 0) && (iconIndex < 4)) {
            f32 width;
            f32 height;

            // D_8160BD74 holds resource 0x104 image 4; the next four words
            // (D_8160BD78[0..3]) hold images 0-3. Retail indexes them from D_8160BD74.
            width = func_8004CA10(((void **)&D_8160BD74)[iconIndex + 1]) * 0.8f;
            height = func_8004CA24(((void **)&D_8160BD74)[iconIndex + 1]) * 0.8f;
            gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0, 0x504240);
            func_8004D1FC(((void **)&D_8160BD74)[iconIndex + 1]);
            // 1.2515644f is the float nearest 1 / 0.799.
            func_81602240(x + 10, y + 26, width, height, 0, 0, 1.2515644f, 1.2515644f);
        }
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
    }
}

extern void *D_8160BDB8;
extern s32 func_8004D19C(s32, s32, void *, s32, s32);
void func_81603984(s32 arg0, s32 arg1) {
    func_8004D19C(arg0, arg1, D_8160BDB8, 0, 0);
}

extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern void func_8004D1FC(void *);
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_8160BD54;

void Fragment11_DrawThickPanelFrame(arg0, arg1, arg2, arg3)
s32 arg0; s32 arg1; s32 arg2; s32 arg3;
{
    if (arg2 >= 0x10 && arg3 >= 0x10) {
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
        func_8004D1FC((void *)(u32)D_8160BD54);
        gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0, 0x0F0A7008);
        func_81602240(arg0, arg1, 16.0f, 16.0f, 0, 0, 1.0f, 1.0f);
        func_81602240((arg0 + arg2) - 0x10, arg1, 16.0f, 16.0f, 0, 0x10, 1.0f, 1.0f);
        func_81602240(arg0, (arg1 + arg3) - 0x10, 16.0f, 16.0f, 0, 0x20, 1.0f, 1.0f);
        func_81602240((arg0 + arg2) - 0x10, (arg1 + arg3) - 0x10, 16.0f, 16.0f, 0, 0x30, 1.0f, 1.0f);
        func_81602240(arg0, arg1 + 0xF, 15.0f, arg3 - 0x1E, 0, 0xC, 1.0f, 0.0f);
        func_81602240(arg0 + 0xF, arg1, arg2 - 0x1E, 15.0f, 0, 0x10, 0.0f, 1.0f);
        func_81602240((arg0 + arg2) - 0xF, arg1 + 0xF, 15.0f, arg3 - 0x1E, 1, 0x1E, 1.0f, 0.0f);
        func_81602240(arg0 + 0xF, (arg1 + arg3) - 0xF, arg2 - 0x1E, 15.0f, 0, 0x31, 0.0f, 1.0f);
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
    }
}
extern s32 func_81602940(s32);
extern void func_8004D1FC(void *);
void func_81603C84(s32 arg0, s32 arg1, s32 arg2) {
    s32 value;
    value = func_81602940(arg2);
    func_8004D1FC((void *)value);
    func_8004D19C(arg0, arg1, (void *)value, 0, 0);
}

/* mkdraft:Fragment11_DrawTexturedPanelBorder begin */
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern void func_8004D1FC(void *);
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_8160BD58;

void Fragment11_DrawTexturedPanelBorder(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 *arg5) {
    if (arg2 >= 0x10 && arg3 >= 0x10) {
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
        func_8004D1FC((void *)(u32)D_8160BD58);
        gDPSetColor((*(Gfx **)&D_800D0510)++, G_SETPRIMCOLOR, (_SHIFTL(((u8 *)arg5)[1], 16, 8) | _SHIFTL(((u8 *)arg5)[2], 8, 8) | _SHIFTL(((u8 *)arg5)[0], 24, 8)));
        gDPSetColor((*(Gfx **)&D_800D0510)++, G_SETENVCOLOR, (_SHIFTL(((u8 *)arg4)[1], 16, 8) | _SHIFTL(((u8 *)arg4)[2], 8, 8) | _SHIFTL(((u8 *)arg4)[0], 24, 8) | _SHIFTL(0xFF, 0, 8)));
        gDPSetCombine((*(Gfx **)&D_800D0510)++, 0x50D2A1, 0x33A5B6DB);
        gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0, 0x0F0A7008);
        func_81602240(arg0, arg1, 8.0f, 8.0f, 0, 0, 1.0f, 1.0f);
        func_81602240((arg0 + arg2) - 8, arg1, 8.0f, 8.0f, 8, 0, 1.0f, 1.0f);
        func_81602240(arg0, (arg1 + arg3) - 8, 8.0f, 8.0f, 0x10, 0, 1.0f, 1.0f);
        func_81602240((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8.0f, 8.0f, 0x18, 0, 1.0f, 1.0f);
        func_81602240(arg0, arg1 + 8, 8.0f, arg3 - 0x10, 0, 7, 1.0f, 0.0f);
        func_81602240(arg0 + 8, arg1, arg2 - 0x10, 8.0f, 8, 0, 0.0f, 1.0f);
        func_81602240((arg0 + arg2) - 8, arg1 + 8, 8.0f, arg3 - 0x10, 8, 7, 1.0f, 0.0f);
        func_81602240(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8.0f, 0x18, 0, 0.0f, 1.0f);
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
    }
}
/* mkdraft:Fragment11_DrawTexturedPanelBorder end */

void func_81604024(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5, s32 *arg6)
{
  Gfx *gfx;
  int new_var;
 do { if ((arg3 > 0) && (arg4 > 0)) { new_var = ((s16) (arg2 * 4)) * ((s16) ((u32) (65536.0f / ((f32) arg4)))); gSPDisplayList((*((Gfx **) (&D_800D0510)))++, D_80094E38); func_8004D1FC((void *) ((u32) D_8160BD5C)); gDPSetColor((*((Gfx **) (&D_800D0510)))++, 0xfa, (((unsigned int) ((((unsigned int) ((u8 *) arg6)[1]) & ((0x01 << 8) - 1)) << 16)) | ((unsigned int) ((((unsigned int) ((u8 *) arg6)[2]) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) ((u8 *) arg6)[0]) & ((0x01 << 8) - 1)) << 24))); gDPSetColor((*((Gfx **) (&D_800D0510)))++, 0xfb, ((((unsigned int) (((((unsigned int) ((u8 *) arg5)[1]) ^ 0) & ((0x01 << 8) - 1)) << 16)) | ((unsigned int) ((((unsigned int) ((u8 *) arg5)[2]) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) ((u8 *) arg5)[0]) & ((0x01 << 8) - 1)) << 24))) | ((unsigned int) ((((unsigned int) 0xFF) & ((0x01 << 8) - 1)) << 0))); gDPSetRenderMode((*((Gfx **) (&D_800D0510)))++, 0, 0x0F0A4000); gDPSetCombine((*((Gfx **) (&D_800D0510)))++, 0x50D2A1, 0x33A5B6DB); if (arg0 != 0) { gfx = (*((Gfx **) (&D_800D0510)))++; gfx->words.w0 = (((unsigned int) ((((unsigned int) 0xe5) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((((s16) ((arg1 + arg3) * 4)) > 0) ? ((s16) ((arg1 + arg3) * 4)) : (0))) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((((s16) ((arg2 + arg4) * 4)) > 0) ? ((s16) ((arg2 + arg4) * 4)) : (0))) & ((0x01 << 12) - 1)) << 0)); gfx->words.w1 = (((unsigned int) ((((unsigned int) G_TX_RENDERTILE) & ((0x01 << 3) - 1)) << 24)) | ((unsigned int) ((((unsigned int) ((((s16) (arg1 * 4)) > 0) ? ((s16) (arg1 * 4)) : (0))) & ((0x01 << 12) - 1)) << 12))) | ((unsigned int) ((((unsigned int) ((((s16) (arg2 * 4)) > 0) ? ((s16) (arg2 * 4)) : (0))) & ((0x01 << 12) - 1)) << 0)); { Gfx *_g = (Gfx *) ((*((Gfx **) (&D_800D0510)))++); _g->words.w0 = (unsigned int) ((((unsigned int) 0xe1) & ((0x01 << 8) - 1)) << 24); _g->words.w1 = (unsigned int) (((unsigned int) ((((unsigned int) (0 - ((((s16) (arg2 * 4)) < 0) ? ((((s16) ((u32) (65536.0f / ((f32) arg4)))) < 0) ? ((((((s16) (arg2 * 4)) * ((s16) ((u32) (65536.0f / ((f32) arg4))))) >> 7) > 0) ? ((((s16) (arg2 * 4)) * ((s16) ((u32) (65536.0f / ((f32) arg4))))) >> 7) : (0)) : (((new_var >> 7) < 0) ? (new_var >> 7) : (0))) : (0)))) & ((0x01 << 16) - 1)) << 16)) | ((unsigned int) ((((unsigned int) (0 - (((arg1 * 4) < 0) ? ((((s16) 0) < 0) ? ((((((s16) (arg1 * 4)) * ((s16) 0)) >> 7) > 0) ? ((((s16) (arg1 * 4)) * ((s16) 0)) >> 7) : (0)) : ((((((s16) (arg1 * 4)) * ((s16) 0)) >> 7) < 0) ? ((((s16) (arg1 * 4)) * ((s16) 0)) >> 7) : (0))) : (0)))) & (((0x01 << 11) << 5) - 1)) << 0))); } ; { Gfx *_g = (Gfx *) ((*((Gfx **) (&D_800D0510)))++); _g->words.w0 = (unsigned int) ((((unsigned int) 0xf1) & ((0x01 << 8) - 1)) << 24); _g->words.w1 = (unsigned int) (((unsigned int) ((((unsigned int) ((u32) (65536.0f / ((f32) arg4)))) & ((0x01 << 16) - 1)) << 16)) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 16) - 1)) << 0))); } ; } else { func_81602240(arg1, arg2, arg3, arg4, 0, 0, 64.0f / ((f32) arg3), 0.0f); } gSPDisplayList((*((Gfx **) (&D_800D0510)))++, D_80094F50); } } while (0);
}

/* mkdraft:Fragment11_DrawBorderedPanelFill begin */
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern void func_81609344(s32, s32, s32, s32, s32);
extern void func_81607408(void);
extern void func_8004D1FC(void *);
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_8160BDBC;
extern s32 D_8160BDC0;

void Fragment11_DrawBorderedPanelFill(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5) {
    if (arg2 >= 0x10 && arg3 >= 0x10) {
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
        gDPPipeSync((*(Gfx **)&D_800D0510)++);
        gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0x504240, 0);
        gDPSetColor((*(Gfx **)&D_800D0510)++, G_SETENVCOLOR, (_SHIFTL(arg5[1], 16, 8) | _SHIFTL(arg5[2], 8, 8) | _SHIFTL(arg5[0], 24, 8) | _SHIFTL(0xFF, 0, 8)));
        if (arg4 == 0) {
            func_81609344(arg0, arg1, arg2 - 4, arg3 - 4, 1);
        }
        func_8004D1FC((void *)(u32)D_8160BDBC);
        func_81602240(arg0, arg1, 8.0f, 8.0f, 0, 0, 1.0f, 1.0f);
        func_81602240((arg0 + arg2) - 8, arg1, 8.0f, 8.0f, 0, 8, 1.0f, 1.0f);
        func_81602240(arg0, (arg1 + arg3) - 8, 8.0f, 8.0f, 0, 0x10, 1.0f, 1.0f);
        func_81602240((arg0 + arg2) - 8, (arg1 + arg3) - 8, 8.0f, 8.0f, 0, 0x18, 1.0f, 1.0f);
        func_81602240(arg0, arg1 + 8, 8.0f, arg3 - 0x10, 0, 7, 1.0f, 0.0f);
        func_81602240(arg0 + 8, arg1, arg2 - 0x10, 8.0f, 7, 0, 0.0f, 1.0f);
        func_81602240((arg0 + arg2) - 8, arg1 + 8, 8.0f, arg3 - 0x10, 0, 0xE, 1.0f, 0.0f);
        func_81602240(arg0 + 8, (arg1 + arg3) - 8, arg2 - 0x10, 8.0f, 7, 0x10, 0.0f, 1.0f);
        gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0x504240, 0);
        func_8004D1FC((void *)(u32)D_8160BDC0);
        func_81602240(arg0 + 3, arg1 + 3, arg2 - 0xA, arg3 - 0xA, 0, 0, (f32)(u32)*(u16 *)(u8 *)(u32)D_8160BDC0 / (f32)(arg2 - 6), (f32)(u32)*(u16 *)((u8 *)(u32)D_8160BDC0 + 2) / (f32)(arg3 - 6));
        if (arg4 == 0) {
            func_81607408();
        }
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
    }
}
/* mkdraft:Fragment11_DrawBorderedPanelFill end */

extern void Fragment11_DrawThickPanelFrame();
extern void func_81608044(s32, s32, s32, s32, f32, s32 *);
extern u8 D_8160BE50;
void func_816048E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
#ifdef CC_CHECK
    /* Retail calls this with the caller's registers untouched; the K&R definition above reads as a
       prototype to clang, so the host check needs the argument-less call spelled through a cast. */
    ((void (*)(void))Fragment11_DrawThickPanelFrame)();
#else
    Fragment11_DrawThickPanelFrame();
#endif
    func_81608044(arg0 + 8, arg1 + 8, arg2 - 0x13, arg3 - 0x13, 0.0f, &D_8160BE50);
}

extern void Fragment11_DrawTexturedPanelBorder(s32, s32, s32, s32, s32 *, s32 *);
extern void func_81604024(s32, s32, s32, s32, s32, s32 *, s32 *);
void func_81604944(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 *arg5) {
    Fragment11_DrawTexturedPanelBorder(arg0, arg1, arg2, arg3, arg4, arg5);
    func_81604024(0, arg0 + 5, arg1 + 5, arg2 - 0xD, arg3 - 0xD, arg4, arg5);
}

extern u8 D_8160BDC4;
extern u8 D_8160BDC8;
extern void Fragment11_DrawTexturedPanelBorder(s32, s32, s32, s32, s32 *, s32 *);
extern void func_81604024(s32, s32, s32, s32, s32, s32 *, s32 *);
void func_816049BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Fragment11_DrawTexturedPanelBorder(arg0, arg1, arg2, arg3, (s32 *)&D_8160BDC4, (s32 *)&D_8160BDC8);
    func_81604024(0, arg0 + 5, arg1 + 5, arg2 - 0xD, arg3 - 0xD, (s32 *)&D_8160BDC4, (s32 *)&D_8160BDC8);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81604A44.s")

extern void func_81604A44(s32, s32, s32, s32, s32);
void func_816054D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_81604A44(arg0, arg1, arg2, arg3, 1);
}

void func_816054FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_81604A44(arg0, arg1, arg2, arg3, 0);
}

/* mkdraft:func_8160551C begin */
extern u8 *func_8004CA60(u8 *);
extern void func_800459AC(u8 *, u8, u8, u16, u16, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_8160BD64;

void func_8160551C(void) {
    func_800459AC(
        func_8004CA60((u8 *)(u32)D_8160BD64),
        ((u8 *)(u32)D_8160BD64)[4],
        ((u8 *)(u32)D_8160BD64)[5],
        *(u16 *)(u8 *)(u32)D_8160BD64,
        *(u16 *)((u8 *)(u32)D_8160BD64 + 2),
        1, 0, 1, 1, 5, 5, 0, 0
    );
}
/* mkdraft:func_8160551C end */

/* mkdraft:func_81605598 begin */
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];



void func_81605598(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
    gDPSetCombine((*(Gfx **)&D_800D0510)++, 0x119623, 0xFF2FFFFF);
    gDPSetColor((*(Gfx **)&D_800D0510)++, G_SETPRIMCOLOR, (_SHIFTL(((u8 *)arg4)[1], 16, 8) | _SHIFTL(((u8 *)arg4)[2], 8, 8) | _SHIFTL(((u8 *)arg4)[3], 0, 8) | _SHIFTL(((u8 *)arg4)[0], 24, 8)));
    gSPScisTextureRectangle((*(Gfx **)&D_800D0510)++, arg0 * 4, arg1 * 4, (arg0 + arg2) * 4, (arg1 + arg3) * 4,
        G_TX_RENDERTILE, 0, 0x400, (s32)(32768.0f / ((f32)arg2 * 0.5f)),
        -(s32)(32768.0f / ((f32)arg3 * 0.5f)));
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
}
/* mkdraft:func_81605598 end */

extern void func_8160551C(void);
extern void func_81605598(s32, s32, s32, s32, s32);
void func_81605908(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) { func_8160551C(); func_81605598(arg0, arg1, arg2, arg3, arg4); }

void func_81605950(void) {
    func_800459AC(
        func_8004CA60((u8 *)(u32)D_8160BD68),
        ((u8 *)(u32)D_8160BD68)[4],
        ((u8 *)(u32)D_8160BD68)[5],
        *(u16 *)(u8 *)(u32)D_8160BD68,
        *(u16 *)((u8 *)(u32)D_8160BD68 + 2),
        1, 0, 1, 1, 4, 4, 0, 0
    );
}
/* mkdraft:func_816059CC begin */
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];

// Draws the panel border as nine func_81602240 quads: four 16x16 corners, two 16-wide
// vertical edges of height arg3 - 0x20, two 16-high horizontal edges of width
// arg2 - 0x20, and the centre quad arg2 - 0x20 by arg3 - 0x20. UVs are 0 or 0x10 and
// s/t are 1, -1 or 0 for each piece.
//
// The prim-color bytes are OR'd in the order arg4[1], arg4[2], arg4[3], arg4[0].
// Ascending order 0,1,2,3 builds a different `or` tree: 62 instructions differ, same value.


void func_816059CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
    gDPSetCombine((*(Gfx **)&D_800D0510)++, 0x119623, 0xFF2FFFFF);
    gDPSetColor((*(Gfx **)&D_800D0510)++, G_SETPRIMCOLOR,
                _SHIFTL(((u8 *)arg4)[1], 16, 8) | _SHIFTL(((u8 *)arg4)[2], 8, 8) |
                    _SHIFTL(((u8 *)arg4)[3], 0, 8) | _SHIFTL(((u8 *)arg4)[0], 24, 8));
    func_81602240(arg0, arg1, 16.0f, 16.0f, 0, 0x10, 1.0f, -1.0f);
    func_81602240((arg0 + arg2) - 0x10, arg1, 16.0f, 16.0f, 0x10, 0x10, -1.0f, -1.0f);
    func_81602240(arg0, (arg1 + arg3) - 0x10, 16.0f, 16.0f, 0, 0, 1.0f, 1.0f);
    func_81602240((arg0 + arg2) - 0x10, (arg1 + arg3) - 0x10, 16.0f, 16.0f, 0x10, 0, -1.0f, 1.0f);
    func_81602240(arg0, arg1 + 0x10, 16.0f, arg3 - 0x20, 0, 0, 1.0f, 0.0f);
    func_81602240(arg0 + 0x10, arg1, arg2 - 0x20, 16.0f, 0x10, 0x10, 0.0f, -1.0f);
    func_81602240((arg0 + arg2) - 0x10, arg1 + 0x10, 16.0f, arg3 - 0x20, 0x10, 0, -1.0f, 0.0f);
    func_81602240(arg0 + 0x10, (arg1 + arg3) - 0x10, arg2 - 0x20, 16.0f, 0x10, 0, 0.0f, 1.0f);
    func_81602240(arg0 + 0x10, arg1 + 0x10, arg2 - 0x20, arg3 - 0x20, 0x10, 0, 0.0f, 0.0f);
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
}
/* mkdraft:func_816059CC end */

extern void func_81605950(void);
extern void func_816059CC(s32, s32, s32, s32, s32);
void func_81605CDC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) { func_81605950(); func_816059CC(arg0, arg1, arg2, arg3, arg4); }

extern void *D_8160BD6C;
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern u32 D_800D0510;
extern void func_8004D1FC(void *);
void func_81605D24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    Gfx *gfx;
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
    func_8004D1FC(D_8160BD6C);
    gDPSetCombine((*(Gfx **)&D_800D0510)++, 0x119623, 0xFF2FFFFF);
    gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0x0F0A7008, 0);
    gfx = (*(Gfx **)&D_800D0510)++;
    gfx->words.w0 = 0xFA00FFFF;
    gfx->words.w1 = _SHIFTL(arg4[1], 16, 8) | _SHIFTL(arg4[2], 8, 8) | _SHIFTL(arg4[0], 24, 8) | 0xFF;
    func_81602240((f32)arg0, (f32)arg1, 16.0f, 16.0f, 0, 0, 1.0f, 1.0f);
    func_81602240((f32)arg0, (f32)(arg1 + arg3 - 16), 16.0f, 16.0f, 0, 32, 1.0f, 1.0f);
    func_81602240((f32)(arg0 + arg2 - 16), (f32)arg1, 16.0f, 16.0f, 0, 16, 1.0f, 1.0f);
    func_81602240((f32)arg0, (f32)(arg1 + 16), 16.0f, (f32)(arg3 - 32), 0, 32, 1.0f, 0.0f);
    func_81602240((f32)(arg0 + 16), (f32)arg1, (f32)(arg2 - 32), 16.0f, 0, 16, 0.0f, 1.0f);
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
}

extern void *D_8160BD78[];
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern void func_8004D1FC(void *);
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern u32 D_800D0510;
void func_81605F94(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, f32 arg4) {
    Gfx *gfx;
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
    func_8004D1FC(D_8160BD78[arg2]);
    gDPSetCombine((*(Gfx **)&D_800D0510)++, 0x119623, 0xFF2FFFFF);
    gfx = (*(Gfx **)&D_800D0510)++;
    gfx->words.w0 = 0xFA00FFFF;
    gfx->words.w1 = _SHIFTL(arg3[1], 16, 8) | _SHIFTL(arg3[2], 8, 8) | _SHIFTL(arg3[0], 24, 8) | _SHIFTL((u32)(255.0f * arg4), 0, 8);
    func_81602240((f32)arg0, (f32)arg1, 48.0f, 24.0f, 0, 0, 1.0f, 1.0f);
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
}

const char D_8160C0C0[] = "%d";

/* mkdraft:func_8160615C begin */
extern void func_800496A4(s32, s32);
extern void func_8004972C(u8, u8, u8, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern s32 func_8004D19C(s32, s32, void *, s32, s32);
extern void func_800495BC();
extern const char D_8160C0C0[];



void func_8160615C(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
    gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 255, 255, 255, 255.0f * arg3);
    func_8004D19C(arg0 + 0x11, arg1 - 0x13, (void *)func_8004C990(0x11B, 0), 0, 0);
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
    func_800498C4();
    func_800496A4(8, -4);
    func_8004972C(0xFF, 0xFF, 0xFF, (s32)(255.0f * arg3));
    func_800495BC(arg0 - 6, arg1 - 0x11, D_8160C0C0, arg2);
    func_800499EC();
}
/* mkdraft:func_8160615C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81606304.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81606694.s")

/* mkdraft:func_81606800 begin */
extern s32 D_8160BE5C;

// NON_MATCHING: The equality branch compares the same registers in the opposite operand order.
#ifdef NON_MATCHING
void func_81606800(s32 arg0, s32 arg1) {
    if (arg1 != 0 || arg0 != D_8160BE5C) {
        D_8160BE5C = arg0;
        gDPPipeSync((*(Gfx **)&D_800D0510)++);
        if (arg0 != 0) {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 0, 0, 0, 0xFF);
            gDPSetPrimColor((*(Gfx **)&D_800D0510)++, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 0xFF, 0xFF, 0xFF, 0xFF);
            gDPSetPrimColor((*(Gfx **)&D_800D0510)++, 0xFF, 0xFF, 0, 0, 0, 0xFF);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81606800.s")
#endif
/* mkdraft:func_81606800 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_816068C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81606B5C.s")

// [14..15] are D_8160C10C (aliases.ld), a zero word read by func_816078C4.
const s16 D_8160C0F0[16] = { 0, 60, 88, 116, 144, 172, 200, 228, 256, 284, 312, 372, 432, 0, 0, 0 };
f32 func_81606E14(f32 arg0, s32 arg1) {
    s32 index;
    if (arg1) {
        return 28.0f * arg0;
    }
    index = (s32)arg0;
    return ((f32)D_8160C0F0[index + 1] - (f32)D_8160C0F0[index]) * (arg0 - (f32)index) + (f32)D_8160C0F0[index];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81606E84.s")

extern void func_81606E84(s16 *, s32, s32, f32, s32);
extern void Fragment11_DrawThickPanelFrame();
void func_81606F88(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    s16 sp20[4];

    func_81606E84(sp20, arg0, arg1, arg2, arg3);
    Fragment11_DrawThickPanelFrame(sp20[0], sp20[1], sp20[2], sp20[3]);
}

void func_81606FE0(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    struct {
        s16 x;
        s16 y;
        s16 width;
        s16 height;
    } rect;

    func_81606E84(&rect.x, arg0, arg1, arg2, arg3);
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
    func_8004D1FC((void *)(u32)D_8160BDB0);
    gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0x0F0A7008, 0);
    func_81602240(rect.x + rect.width / 2 - 4, arg1 + 29, 8.0f, 6.0f, 0, 0, 1.0f, 1.0f);
    gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
}

extern u32 D_800D0510;
#define GFX_DL (*(Gfx **)&D_800D0510)
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern void *D_8160BD94;
extern void *D_8160BD90;
extern s32 func_8004D19C(s32, s32, void *, s32, s32);
void func_8160710C(s32 arg0, s32 arg1) {
    gSPDisplayList(GFX_DL++, D_80094E38);
    gDPSetRenderMode(GFX_DL++, 0x0F0A7008, 0);
    func_8004D19C(arg0, arg1, D_8160BD94, 0, 0);
    gSPDisplayList(GFX_DL++, D_80094F50);
}

extern s32 func_8004D19C(s32, s32, void *, s32, s32);
void func_816071AC(s32 arg0, s32 arg1) {
    gSPDisplayList(GFX_DL++, D_80094E38);
    gDPSetRenderMode(GFX_DL++, 0x0F0A7008, 0);
    func_8004D19C(arg0, arg1, D_8160BD90, 0, 0);
    gSPDisplayList(GFX_DL++, D_80094F50);
}

void func_8160724C(s16 *arg0, s16 *arg1) { s16 value; value = arg1[0]; if (arg0[0] < value) arg0[0] = value; value = arg1[1]; if (arg0[1] < value) arg0[1] = value; if ((arg1[0] + arg1[2]) < (arg0[2] + arg0[0])) { arg0[2] = (arg1[0] + arg1[2]) - arg0[0]; if (arg0[2] < 0) arg0[2] = 0; } if ((arg1[1] + arg1[3]) < (arg0[3] + arg0[1])) { arg0[3] = (arg1[1] + arg1[3]) - arg0[1]; if (arg0[3] < 0) arg0[3] = 0; } }

void func_816072FC(void *arg0) {
    if ((*(s16 *)((u8 *)(arg0) + (4))) < 0x10) {
        (*(s16 *)((u8 *)(arg0) + (4))) = 0;
    }
    if ((*(s16 *)((u8 *)(arg0) + (6))) < 0x10) {
        (*(s16 *)((u8 *)(arg0) + (6))) = 0;
    }
}

void func_8160732C(void *arg0, void *arg1) {
    (*(s16 *)((u8 *)(arg0) + (0))) = (s16) ((*(s16 *)((u8 *)(arg1) + (0))) + 8);
    (*(s16 *)((u8 *)(arg0) + (2))) = (s16) ((*(s16 *)((u8 *)(arg1) + (2))) + 8);
    (*(s16 *)((u8 *)(arg0) + (4))) = (s16) ((*(s16 *)((u8 *)(arg1) + (4))) - 0x13);
    (*(s16 *)((u8 *)(arg0) + (6))) = (s16) ((*(s16 *)((u8 *)(arg1) + (6))) - 0x13);
}

extern void Fragment11_SetClippedScissor(void *, s16, s16, s16, s16);
extern u32 D_800D0510;
void func_81607360(s32 arg0) {
    Fragment11_SetClippedScissor(&D_800D0510, *(s16 *)((u8 *)(arg0) + (0)), *(s16 *)((u8 *)(arg0) + (2)), *(s16 *)((u8 *)(arg0) + (4)), *(s16 *)((u8 *)(arg0) + (6)));
}

void func_816073A0(void *arg0) {
    Fragment11_SetClippedScissor(&D_800D0510, (s16) ((*(s16 *)((u8 *)(arg0) + (0))) + 8), (s16) ((*(s16 *)((u8 *)(arg0) + (2))) + 8), (s16) ((*(s16 *)((u8 *)(arg0) + (4))) - 0x13), (*(s16 *)((u8 *)(arg0) + (6))) - 0x13);
}

void func_81607408(void) {
    Fragment11_SetClippedScissor(&D_800D0510, 0, 0, 640, 480);
}

/* mkdraft:func_81607440 begin */
extern void func_816054D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void Fragment11_SetClippedScissor(void *, s16, s16, s16, s16);
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 D_8160BDA4;
extern s32 D_8160BDA8;
extern void func_8004D1FC(void *);
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern void func_81607408(void);


void func_81607440(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    Gfx *gfx;
    Gfx *gfx2;

    func_816054D8(arg0, arg1, arg2, arg3);
    Fragment11_SetClippedScissor(&D_800D0510, (s16)arg0, (s16)arg1, (s16)arg2, arg3);
    arg1 = (s32)((f32)(arg1 + 13) + ((f32)(arg3 - 26) * arg4));
    gSPDisplayList(GFX_DL++, D_80094E38);
    gDPSetCombine(GFX_DL++, 0x119623, 0xFF2FFFFF);
    gDPSetRenderMode(GFX_DL++, 0x0F0A7008, 0);
    gfx2 = GFX_DL++;
    gfx2->words.w1 = -1;
    gfx2->words.w0 = 0xFA00FFFF;
    gfx = GFX_DL++;
    gfx->words.w1 = 0xFFFF00FF;
    gfx->words.w0 = 0xFA00FFFF;
    arg0 += 3;
    func_8004D1FC((void *)(u32)D_8160BDA4);
    func_81602240((f32)arg0, (f32)(arg1 - 10), 16.0f, 10.0f, 0, 0, 1.0f, 1.0f);
    func_8004D1FC((void *)(u32)D_8160BDA8);
    func_81602240((f32)arg0, (f32)arg1, 16.0f, 10.0f, 0, 0, 1.0f, 1.0f);
    gSPDisplayList(GFX_DL++, D_80094F50);
    func_81607408();
}
/* mkdraft:func_81607440 end */

f32 func_8160762C(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    f32 result;
    s32 first;
    s32 next;
    if (arg1 < 2) {
        result = 0.0f;
        *arg3 = 0;
        *arg2 = 0;
    } else {
        result = (f32)arg0 / (f32)(arg1 - 1);
        first = arg0 != 0;
        next = arg0;
        next++;
        *arg2 = first;
        *arg3 = arg1 != next;
    }
    return result;
}

extern u32 D_8160BE60;
extern u32 D_8160BE64;
extern u32 D_8160BE68;
extern u32 D_8160BE6C;
void *func_81607680(u16 arg0, u16 arg1, u16 arg2) {
    if (arg0 <= 0) {
        return (arg1 & 1) ? &D_8160BE6C : &D_8160BE64;
    }
    if (arg0 >= arg2) {
        return (arg1 & 0x400) ? &D_8160BE68 : &D_8160BE64;
    }
    return (arg1 & (1 << arg0)) ? &D_8160BE60 : &D_8160BE64;
}

extern u32 D_8160BE70;
extern u32 D_8160BE74;
extern u32 D_8160BE78;
extern u32 D_8160BE7C;
void *func_8160771C(u16 arg0, u16 arg1, u16 arg2) {
    if (arg0 <= 0) {
        return (arg1 & 1) ? &D_8160BE7C : &D_8160BE74;
    }
    if (arg0 >= arg2) {
        return (arg1 & 0x400) ? &D_8160BE78 : &D_8160BE74;
    }
    return (arg1 & (1 << arg0)) ? &D_8160BE70 : &D_8160BE74;
}

extern void * func_81607680(u16 arg0, u16 arg1, u16 arg2);
extern u32 D_800D0510;
void func_816077B8(u16 arg0, u16 arg1, u16 arg2) {
    u8 *color;
    Gfx *gfx;
    color = func_81607680(arg0, arg1, arg2);
    gfx = (Gfx *)D_800D0510;
    D_800D0510 += sizeof(Gfx);
    gfx->words.w0 = 0xFA00FFFF;
    gfx->words.w1 = _SHIFTL(color[1], 16, 8) | _SHIFTL(color[2], 8, 8) | _SHIFTL(color[0], 24, 8) | 255;
}

extern void * func_81607680(u16 arg0, u16 arg1, u16 arg2);
extern u32 D_800D0510;
void func_81607834(u16 arg0, u16 arg1, u16 arg2) {
    struct Color07834RGB { u8 r; u8 g; u8 b; } *color;
    color = func_81607680(arg0, arg1, arg2);
    gDPPipeSync((*(Gfx **)&D_800D0510)++);
    gDPSetEnvColor((*(Gfx **)&D_800D0510)++, color->r, color->g, color->b, 255);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_816078C4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81607B1C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81607DB0.s")

/* mkdraft:func_81608044 begin */
void func_81608044(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 *arg5) {
    Gfx *gfx;
    f32 alpha;
    f32 t;
    t = 1.0f - arg4;
    if (!t) {} // FAKE: diff score 380 without this empty block.
    alpha = t * t * t;
    if ((arg3 >= 0) && (arg2 >= 0)) {
        gDPSetCycleType((*(Gfx **)&D_800D0510)++, G_CYC_2CYCLE);
        gDPSetPrimColor((*(Gfx **)&D_800D0510)++, 0xFF, 0xFF, 0, 0, 0, 0xFF);
        gfx = (*(Gfx **)&D_800D0510)++;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = _SHIFTL((u32)((f32)(u32)((u8 *)arg5)[1] * alpha), 16, 8) | _SHIFTL((u32)((f32)(u32)((u8 *)arg5)[2] * alpha), 8, 8) | _SHIFTL((u32)((f32)(u32)((u8 *)arg5)[0] * alpha), 24, 8) | 0xFF;
        gDPSetCombine((*(Gfx **)&D_800D0510)++, 0x71FFFF, 0xFFFEFC38);
        gDPSetRenderMode((*(Gfx **)&D_800D0510)++, 0x0F0A4000, 0);
        func_81602240(arg0, arg1, arg2, arg3, 0, 0, 1.0f, 1.0f);
    }
}
/* mkdraft:func_81608044 end */

extern s32 func_8000731C(void);
extern void *Gfx_AllocDisplayList(s32);
extern void Gfx_SetViewportDimensions(void *, s16, s16);
extern Mtx D_80094890;
extern u32 D_800D0510;
void func_816083A4(void) {
    s16 *dims;
    Mtx *matrix;
    Vp *viewport;
    dims = (s16 *)func_8000731C();
    matrix = Gfx_AllocDisplayList(0x40);
    viewport = Gfx_AllocDisplayList(0x10);
    Gfx_SetViewportDimensions(viewport, dims[2], dims[3]);
    gSPViewport((*(Gfx **)&D_800D0510)++, (u32)viewport & 0x1FFFFFFF);
    guOrtho(matrix, 0.5f, (f32)(u16)dims[2] - 0.5f, (f32)(u16)dims[3] - 0.5f, 0.5f, -2.0f, 2.0f, 1.0f);
    gSPPerspNormalize((*(Gfx **)&D_800D0510)++, 0xFFFF);
    gSPMatrix((*(Gfx **)&D_800D0510)++, (u32)matrix & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix((*(Gfx **)&D_800D0510)++, (u32)&D_80094890 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

extern void *D_8160BDB4;
void func_8160852C(void) {
    func_8004D1FC(D_8160BDB4);
}

extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern u32 D_800D0510;
void func_81608550(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    Gfx *gfx;
    if (arg2 != 0) {
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
        if (arg3 != 0) {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 0xFF, 0xAA, 0, (u32)(255.0f * arg4));
        } else {
            gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 0x82, 0x82, 0x82, (u32)(255.0f * arg4));
        }
        func_81602240((f32)arg0, (f32)arg1, 16.0f, 16.0f, 0, 0, 1.0f, 1.0f);
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
    }
}

extern void func_81608550(s32, s32, s32, s32, f32);
void func_8160877C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    if (arg2 != 0) {
        func_8160852C();
        func_81608550(arg0, arg1, arg2, arg3, arg4);
    }
}

extern s32 HAL_Strcmp(const s8 *, const s8 *);
extern s32 func_80064474(u8, u16);
extern s32 func_800647C8(u8);
extern s32 func_8004C874(s32, s32);
// Selects the gender text shown after a Pokemon's name. func_80064474 reads the
// species byte at D_80098313[species * 22] and the u16 at +0x16 and returns
// 0 (genderless), 1 or 2; cases 1 and 2 use text 29 and 30 of table 13.
// Species 29 and 32 (Nidoran female and male) whose name at +0x34 equals the
// species name from func_800647C8 get the empty string D_8160C120 instead.
//@src/641E0.c
s32 func_816087C8(u8 *arg0) {
    u8 gender;

    gender = func_80064474(arg0[0], *(u16 *)(arg0 + 0x16));
    if ((arg0[0] == 29 || arg0[0] == 32) && HAL_Strcmp((s8 *)(arg0 + 0x34), (s8 *)func_800647C8(arg0[0])) == 0) {
        return (s32)"";
    }
    switch (gender) {
        case 0:
            return (s32)"";
        case 1:
            return func_8004C874(13, 29);
        case 2:
            return func_8004C874(13, 30);
    }
}

extern s32 func_80064474(u8, u16);
extern void func_800495BC(s32, s32, s32);
extern s32 func_8004C874(s32, s32);
void func_81608890(s32 arg0, s32 arg1, u8 *arg2) {
    s32 status;
    status = func_80064474(arg2[0], *(u16 *)(arg2 + 0x16));
    switch (status) {
    case 0:
        return;
    case 1:
        func_800495BC(arg0, arg1, func_8004C874(0xD, 0x1D));
        break;
    case 2:
        func_800495BC(arg0, arg1, func_8004C874(0xD, 0x1E));
        break;
    }
}

extern f32 func_8160BCB0(f32, f32);
extern void func_8004AF18(s32, s32);
extern f32 func_816092FC(void);
void func_81608918(s32 arg0, s32 arg1, f32 *arg2) {
    *arg2 = func_8160BCB0(*arg2 + func_816092FC(), 24.0f);
    if (*arg2 < 12.0f) {
        arg0 += *arg2 / 2;
    } else {
        arg0 += (24.0f - *arg2) / 2;
    }
    func_8004AF18(arg0, arg1);
}

extern s32 D_8160BE80;

// Returns the previously cached image pointer while adopting the current one:
// func_8000731C returns the GfxImage that GfxImage_SetRenderTarget bound last
// (D_80087220), whose img_p field sits at offset 8. With no render target
// bound, the cached pointer is returned unchanged.
//@src/7A50.c
s32 func_816089E0(void) {
    s32 *cached_image = &D_8160BE80;
    s32 previous;
    s32 target;

    target = func_8000731C();
    if ((target != 0) && (*(s32 *)((u8 *)target + 8) != 0)) {
        previous = *cached_image;
        *cached_image = *(s32 *)((u8 *)target + 8);
        return previous;
    }
    return *cached_image;
}

extern u8 D_80094D90[];
extern u8 D_80094DB8[];
extern void Gfx_FillRectRgb(s16, s16, s16, s16, u32, u32, u32);
extern void Gfx_FillRectRgba(s16, s16, s16, s16, u32, u32, u32, u32);
extern u32 D_800D0510;
void func_81608A38(s32 arg0, s32 arg1, u8 arg2, f32 arg3) {
    Gfx *gfx;
    if (0.98f < arg3) {
        gfx = (Gfx *)D_800D0510;
        D_800D0510 += 8;
        gSPDisplayList(gfx, D_80094D90);
        if (arg2 & 1) {
            Gfx_FillRectRgb((s16)(arg0 + 0x9E), (s16)(arg1 + 9), 1, 0x7A, 0, 0, 0);
        }
        if (arg2 & 2) {
            Gfx_FillRectRgb((s16)(arg0 + 0x138), (s16)(arg1 + 9), 1, 0x7A, 0, 0, 0);
        }
        if (arg2 & 4) {
            Gfx_FillRectRgb((s16)(arg0 + 0xD), (s16)(arg1 + 0x45), 0x1BC, 1, 0, 0, 0);
        }
        if (arg2 & 1) {
            Gfx_FillRectRgb((s16)(arg0 + 0x9F), (s16)(arg1 + 9), 1, 0x7A, 0xFF, 0xFF, 0xFF);
        }
        if (arg2 & 2) {
            Gfx_FillRectRgb((s16)(arg0 + 0x139), (s16)(arg1 + 9), 1, 0x7A, 0xFF, 0xFF, 0xFF);
        }
        if (arg2 & 4) {
            Gfx_FillRectRgb((s16)(arg0 + 0xD), (s16)(arg1 + 0x46), 0x1BC, 1, 0xFF, 0xFF, 0xFF);
        }
    } else {
        gfx = (Gfx *)D_800D0510;
        D_800D0510 += 8;
        gSPDisplayList(gfx, D_80094DB8);
        if (arg2 & 1) {
            Gfx_FillRectRgba((s16)(arg0 + 0x9E), (s16)(arg1 + 9), 1, 0x7A, 0, 0, 0, (u32)(255.0f * arg3));
        }
        if (arg2 & 2) {
            Gfx_FillRectRgba((s16)(arg0 + 0x138), (s16)(arg1 + 9), 1, 0x7A, 0, 0, 0, (u32)(255.0f * arg3));
        }
        if (arg2 & 4) {
            Gfx_FillRectRgba((s16)(arg0 + 0xD), (s16)(arg1 + 0x45), 0x1BC, 1, 0, 0, 0, (u32)(255.0f * arg3));
        }
        if (arg2 & 1) {
            Gfx_FillRectRgba((s16)(arg0 + 0x9F), (s16)(arg1 + 9), 1, 0x7A, 0xFF, 0xFF, 0xFF, (u32)(255.0f * arg3));
        }
        if (arg2 & 2) {
            Gfx_FillRectRgba((s16)(arg0 + 0x139), (s16)(arg1 + 9), 1, 0x7A, 0xFF, 0xFF, 0xFF, (u32)(255.0f * arg3));
        }
        if (arg2 & 4) {
            Gfx_FillRectRgba((s16)(arg0 + 0xD), (s16)(arg1 + 0x46), 0x1BC, 1, 0xFF, 0xFF, 0xFF, (u32)(255.0f * arg3));
        }
    }
}

/* mkdraft:func_81609170 begin */
extern s32 func_800472E0(s32);
extern s32 func_80049148(s32, s32, s32);
extern void func_800495F8(s32, s32, s32, s32);
extern void func_800496A4(s32, s32);
extern void func_8004989C(s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_81607B1C(s32, s32, s32, s32, f32, u8 *, u8 *);
extern u8 D_8160BE84;
extern u8 D_8160BE87;



void func_81609170(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, s32 arg8) {
    s32 temp_t0;
    s32 temp_v0;
    s32 temp_v1;

    temp_t0 = func_80049148(arg2, arg3, arg8) + (arg5 * 2);
    temp_v0 = func_800472E0(arg8);
    temp_v1 = (arg6 * 2) + (arg4 * temp_v0);
    func_81607B1C((s32) ((f32) arg0 - ((f32) (temp_t0 / 2) * arg7)), (s32) ((f32) arg1 + ((f32) (temp_v1 / 2) * arg7)), (s32) ((f32) temp_t0 * arg7), (s32) ((f32) temp_v1 * arg7), 1.0f - arg7, &D_8160BE84, &D_8160BE87);
    if (0.1f < arg7) {
        func_800498C4();
        func_800496A4(arg2, arg3);
        func_8004989C(arg4);
        func_800495F8(arg0, arg1 + arg6, 1, arg8);
        func_800499EC();
    }
}
/* mkdraft:func_81609170 end */

s32 func_80001FF0();
s32 func_80008970();

f32 func_816092FC(void) {
    s32 sp1C;

    sp1C = func_80008970();
    return ((f32) sp1C * 60.0f) / (f32) func_80001FF0();
}

extern void Fragment11_SetClippedScissor(void *, s16, s16, s16, s16);
extern u32 D_800D0510;
void func_81609344(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4){s32 width=arg4?0x280:0x140; s32 height=arg4?0x1E0:0xF0; if(arg0<0){arg2+=arg0;arg0=0;} if(arg1<0){arg3+=arg1;arg1=0;} if(arg0+arg2>=width)arg2=width-arg0; if(arg1+arg3>=height)arg3=height-arg1; if(arg2<=0||arg3<=0||arg0>=width||arg1>=height||arg0+arg2<=0||arg1+arg3<=0)Fragment11_SetClippedScissor(&D_800D0510,0,0,0,0); Fragment11_SetClippedScissor(&D_800D0510,(s16)arg0,(s16)arg1,(s16)arg2,arg3);}

void func_8160945C(s16 *arg0, s16 *arg1, s16 *arg2, f32 arg3) { arg0[0] = arg1[0] + (arg2[0] - arg1[0]) * arg3; arg0[1] = arg1[1] + (arg2[1] - arg1[1]) * arg3; arg0[2] = arg1[2] + (arg2[2] - arg1[2]) * arg3; arg0[3] = arg1[3] + (arg2[3] - arg1[3]) * arg3; }

const u8 D_8160C128[0x58] = { 0x00, 0x3A, 0x00, 0xA5, 0x02, 0x0F, 0x01, 0x1B, 0x00, 0x35, 0x00, 0x46, 0x02, 0x19, 0x01, 0x80, 0x00, 0x55, 0x00, 0x67, 0x01, 0xD8, 0x01, 0x3E, 0x00, 0x2F, 0x01, 0x27, 0x02, 0x24, 0x00, 0x9F, 0x00, 0x2F, 0x01, 0xF4, 0x02, 0x24, 0x00, 0x9F, 0xFD, 0xF1, 0x00, 0xA5, 0x02, 0x0F, 0x01, 0x1B, 0x00, 0x35, 0x00, 0x46, 0x02, 0x19, 0x00, 0xBF, 0x02, 0x80, 0x00, 0xA5, 0x02, 0x0F, 0x01, 0x1B, 0x02, 0x80, 0x01, 0x27, 0x02, 0x24, 0x00, 0x9F, 0xFD, 0xDC, 0x01, 0x27, 0x02, 0x24, 0x00, 0x9F, 0x00, 0x35, 0x01, 0xE0, 0x02, 0x19, 0x00, 0x14 };
// .rodata color read by func_8160955C (still assembly).
const u8 D_8160C180[8] = { 0x96, 0x96, 0x96, 0xFF, 0xFF, 0x00, 0x00, 0x00 };

void *func_81609530(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 0xB)) {
        return NULL;
    }
    return (arg0 * 8) + D_8160C128;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_8160955C.s")

struct Color098 { u8 r, g, b; };
extern s32 func_8004CA10(void *);
extern s32 func_8004CA24(void *);
extern s32 func_8004D19C(s32, s32, void *, s32, s32);
extern u8 D_80094E38[];
extern u8 D_80094F50[];
void func_816098B0(void *arg0, struct Color098 *arg1) {
    s32 x;
    s32 y;
    gSPDisplayList(GFX_DL++, D_80094E38);
    gDPSetRenderMode(GFX_DL++, 0x0F0A4000, 0);
    gDPSetEnvColor(GFX_DL++, arg1->r, arg1->g, arg1->b, 0xFF);
    for (x = 0; x < 640; x += func_8004CA10(arg0)) {
        for (y = 0; y < 480; y += func_8004CA24(arg0)) {
            func_8004D19C(x, y, arg0, 0, 0);
        }
    }
    gSPDisplayList(GFX_DL++, D_80094F50);
}

static const u16 D_8160C188[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, void *, s32, s32);
extern void func_8004D1FC(void *);
void func_816099E0(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    void *temp;

    if (arg3 > 1.0f) {
        arg3 = 0.99f;
    }
    if (arg3 < 0.0f) {
        arg3 = 0.0f;
    }
    temp = (void *)func_8004C990(0x9F, D_8160C188[(s32)(arg3 * 8.01f)]);
    func_8004D1FC(temp);
    func_8004D19C(arg0 - 0x10, arg1 - 0x10, temp, 0, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81609A90.s")

extern u32 D_8160BDF4;
extern void func_800226C0(s32);
extern void _bzero(void *, s32);
void func_81609CB8(void) { if ((D_8160BDF4 >> 31) != 0) func_800226C0(0xA5); if (((D_8160BDF4 << 1) >> 31) != 0) func_800226C0(0xA6); if (((D_8160BDF4 << 2) >> 31) != 0) func_800226C0(0xA9); if (((D_8160BDF4 << 3) >> 31) != 0) func_800226C0(0xA7); if (((D_8160BDF4 << 4) >> 31) != 0) func_800226C0(0xA8); if (((D_8160BDF4 << 5) >> 31) != 0) func_800226C0(0xAA); if (((D_8160BDF4 << 6) >> 31) != 0) func_800226C0(0xAC); if (*(u8 *)&D_8160BDF4 & 1) func_800226C0(0xAB); _bzero(&D_8160BDF4, 4); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_D9DE0/func_81609DC0.s")
#endif
