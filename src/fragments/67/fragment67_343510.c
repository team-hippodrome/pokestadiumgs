#include "global.h"


#ifdef VERSION_US
void func_82906A10(f32 *arg0, f32 *arg1) { arg0[0] = arg1[0]; arg0[1] = arg1[1]; arg0[2] = arg1[2]; }

void func_82906A2C(f32 *arg0, const f32 *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
}

/* mkdraft:func_82906A50 begin */
extern f32 Math_StepToF(f32, f32, f32, f32);

void func_82906A50(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3) {
    f32 stepX;
    f32 stepY;
    f32 stepZ;

    stepX = (arg1[0] - arg2[0]) / (f32)arg3;
    stepY = (arg1[1] - arg2[1]) / (f32)arg3;
    stepZ = (arg1[2] - arg2[2]) / (f32)arg3;
    if (stepX < 0.0f) stepX *= -1.0f;
    if (stepY < 0.0f) stepY *= -1.0f;
    if (stepZ < 0.0f) stepZ *= -1.0f;
    arg0[0] = Math_StepToF(arg0[0], arg1[0], stepX, stepX);
    arg0[1] = Math_StepToF(arg0[1], arg1[1], stepY, stepY);
    arg0[2] = Math_StepToF(arg0[2], arg1[2], stepZ, stepZ);
}
/* mkdraft:func_82906A50 end */

/* mkdraft:func_82906B6C begin */
extern f32 Math_StepToF(f32, f32, f32, f32);

void func_82906B6C(f32 *arg0, f32 *arg1, f32 *arg2, s16 arg3) {
    f32 stepX;
    f32 stepY;
    f32 stepZ;
    f32 stepW;

    stepX = (arg1[0] - arg2[0]) / (f32)arg3;
    stepY = (arg1[1] - arg2[1]) / (f32)arg3;
    stepZ = (arg1[2] - arg2[2]) / (f32)arg3;
    stepW = (arg1[3] - arg2[3]) / (f32)arg3;
    if (stepX < 0.0f) stepX *= -1.0f;
    if (stepY < 0.0f) stepY *= -1.0f;
    if (stepZ < 0.0f) stepZ *= -1.0f;
    if (stepW < 0.0f) stepW *= -1.0f;
    arg0[0] = Math_StepToF(arg0[0], arg1[0], stepX, stepX);
    arg0[1] = Math_StepToF(arg0[1], arg1[1], stepY, stepY);
    arg0[2] = Math_StepToF(arg0[2], arg1[2], stepZ, stepZ);
    arg0[3] = Math_StepToF(arg0[3], arg1[3], stepW, stepW);
}
/* mkdraft:func_82906B6C end */

extern f32 Math_StepToF(f32, f32, f32, f32);
extern void func_82906A50(f32 *, f32 *, f32 *, s16);
extern void func_82906B6C(f32 *, f32 *, f32 *, s16);
extern f32 D_82912370;
extern f32 D_8291237C;
extern f32 D_82912388;
extern f32 D_82912394;
extern f32 D_829123A4;
extern f32 D_829123B4;
extern f32 D_829123C0;
extern f32 D_829123CC;
extern f32 D_829123D8;
extern f32 D_829123E8;
extern f32 D_829123F8;
extern f32 D_82912408;
extern f32 D_82912418;
extern f32 D_82912424;
extern f32 D_82912430;
extern f32 D_8291243C;
extern f32 D_8291244C;
extern f32 D_8291245C;
extern f32 D_8291246C;
extern f32 D_82919D4C;
extern f32 D_82919D50;
extern f32 D_82919D54;
extern f32 D_82919D64;
extern f32 D_82919D70;
extern f32 D_82919D80;
extern f32 D_82919D8C;
extern f32 D_82919D9C;
void func_82906CC8(s32 arg0) {
    if (arg0 == 0) {
        func_82906A10(&D_82919D64, &D_82912370);
    }
    if ((arg0 >= 4) && (arg0 < 0xC)) {
        func_82906A50(&D_82919D64, &D_8291237C, &D_82912370, 7);
    }
    if ((arg0 >= 0xC) && (arg0 < 0x28)) {
        func_82906A50(&D_82919D64, &D_82912388, &D_8291237C, 0x1B);
    }
}

extern void func_82906A2C(f32 *arg0, const f32 *arg1);
void func_82906D64(s32 arg0) {
    if (arg0 == 0) {
        func_82906A2C(&D_82919D54, &D_82912394);
    }
    if ((arg0 > 0) && (arg0 < 4)) {
        func_82906B6C(&D_82919D54, &D_829123A4, &D_82912394, 2);
    }
    if ((arg0 >= 0x27) && (arg0 < 0x2D)) {
        func_82906B6C(&D_82919D54, &D_82912394, &D_829123A4, 5);
    }
}

void func_82906DFC(s32 arg0) {
    D_82919D4C = Math_StepToF(D_82919D4C, 18.0f, 0.5f, 0.5f);
    if (arg0 == 0) {
        func_82906A10(&D_82919D80, &D_829123B4);
    }
    if ((arg0 >= 4) && (arg0 < 0xC)) {
        func_82906A50(&D_82919D80, &D_829123C0, &D_829123B4, 7);
    }
    if ((arg0 >= 0xC) && (arg0 < 0x23)) {
        func_82906A50(&D_82919D80, &D_829123CC, &D_829123C0, 0x16);
    }
}

extern void func_82906A2C(f32 *arg0, const f32 *arg1);
void func_82906EC4(s32 arg0) {
    if (arg0 == 0) {
        func_82906A2C(&D_82919D70, &D_829123D8);
    }
    if ((arg0 > 0) && (arg0 < 4)) {
        func_82906B6C(&D_82919D70, &D_829123E8, &D_829123D8, 2);
    }
    if ((arg0 >= 4) && (arg0 < 0xC)) {
        func_82906B6C(&D_82919D70, &D_829123F8, &D_829123E8, 7);
    }
    if ((arg0 >= 0xC) && (arg0 < 0x23)) {
        func_82906B6C(&D_82919D70, &D_82912408, &D_829123F8, 0x16);
    }
}

void func_82906F8C(s32 arg0) {
    D_82919D50 = Math_StepToF(D_82919D50, 36.0f, 1.0f, 1.0f);
    if (arg0 == 0) {
        func_82906A10(&D_82919D9C, &D_82912418);
    }
    if ((arg0 >= 4) && (arg0 < 0xC)) {
        func_82906A50(&D_82919D9C, &D_82912424, &D_82912418, 7);
    }
    if ((arg0 >= 0xC) && (arg0 < 0x1E)) {
        func_82906A50(&D_82919D9C, &D_82912430, &D_82912424, 0x11);
    }
}

extern void func_82906A2C(f32 *arg0, const f32 *arg1);
void func_82907054(s32 arg0) {
    if (arg0 == 0) {
        func_82906A2C(&D_82919D8C, &D_8291243C);
    }
    if ((arg0 > 0) && (arg0 < 4)) {
        func_82906B6C(&D_82919D8C, &D_8291244C, &D_8291243C, 2);
    }
    if ((arg0 >= 4) && (arg0 < 0xC)) {
        func_82906B6C(&D_82919D8C, &D_8291245C, &D_8291244C, 7);
    }
    if ((arg0 >= 0xC) && (arg0 < 0x1E)) {
        func_82906B6C(&D_82919D8C, &D_8291246C, &D_8291245C, 0x11);
    }
}

extern void func_82906B6C(f32 *, f32 *, f32 *, s16);
extern f32 D_8291247C;
extern u8 D_8291248C;
extern f32 D_82919DA8;
void func_8290711C(s32 arg0) {
    if (arg0 == 0) {
        func_82906A2C(&D_82919DA8, &D_8291247C);
    }
    if ((arg0 >= 0xC) && (arg0 < 0x27)) {
        func_82906B6C(&D_82919DA8, &D_8291248C, &D_8291247C, 0x1A);
    }
}

typedef struct {
    /* 0x00 */ u8 state; // 0 = reset counter, 1 = advancing, 2 = finished after frame 61
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 frame; // passed to the seven interpolation steps in func_82907188
    /* 0x03 */ u8 unk03;
    /* 0x04 */ f32 f04; // D_82919D4C
    /* 0x08 */ f32 f08; // D_82919D50
    /* 0x0C */ f32 f0C, f10, f14, f18; // prim color for the center text
    /* 0x1C */ f32 f1C, f20, f24;      // env color for the center text
    /* 0x28 */ f32 f28, f2C, f30, f34; // prim color for the vertical pair
    /* 0x38 */ f32 f38, f3C, f40;      // env color for the vertical pair
    /* 0x44 */ f32 f44, f48, f4C, f50; // prim color for the horizontal pair
    /* 0x54 */ f32 f54, f58, f5C;      // env color for the horizontal pair
    /* 0x60 */ f32 f60, f64, f68;
    /* 0x6C */ f32 f6C; // alpha of the top text
} F67TextBlock;

extern F67TextBlock D_82919D48;
void func_82907188(void) {
    switch (D_82919D48.state) {
    case 0:
        D_82919D48.state = 1;
        D_82919D48.frame = 0;
        func_82906D64(D_82919D48.frame);
        func_82906CC8(D_82919D48.frame);
        func_82906EC4(D_82919D48.frame);
        func_82906DFC(D_82919D48.frame);
        func_82907054(D_82919D48.frame);
        func_82906F8C(D_82919D48.frame);
        func_8290711C(D_82919D48.frame);
        break;
    case 1:
        D_82919D48.frame++;
        func_82906D64(D_82919D48.frame);
        func_82906CC8(D_82919D48.frame);
        func_82906EC4(D_82919D48.frame);
        func_82906DFC(D_82919D48.frame);
        func_82907054(D_82919D48.frame);
        func_82906F8C(D_82919D48.frame);
        func_8290711C(D_82919D48.frame);
        if (D_82919D48.frame == 61) {
            D_82919D48.state = 2;
        }
        break;
    }
}


extern Gfx D_829124D0[];
extern Gfx D_829124A0[];
extern Gfx *D_800D0510;
extern char *func_8004B7A4(s32);
extern s32 func_80049148(s32, s32, char *);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800497E4(s32, s32, s32, s32);
extern void func_800495BC(s32, s32, const char *, ...);
extern void func_800499EC(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void Font_DisableTwoCycleTexturing(void);
extern char D_829174E0[], D_829174E4[], D_829174E8[], D_829174EC[], D_829174F0[], D_829174F4[];

void func_82907274(s16 arg0) {
    char *str;
    s32 halfW;

    if (D_82919D48.state == 0) {
        return;
    }
    str = func_8004B7A4(arg0);
    halfW = func_80049148(0x10, 0, str) / 2;
    func_800498C4();
    func_800496A4(0x10, 0);
    gSPDisplayList(D_800D0510++, D_829124D0);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, (u8)D_82919D48.f54, (u8)D_82919D48.f58, (u8)D_82919D48.f5C, 255);
    gDPSetPrimColor(D_800D0510++, 0, 0, (u8)D_82919D48.f44, (u8)D_82919D48.f48, (u8)D_82919D48.f4C, (u8)D_82919D48.f50);
    func_800495BC((0xA0 - halfW) - (s16)(s32)D_82919D48.f08, 0xB4, D_829174E0, str);
    func_800495BC((0xA0 - halfW) + (s16)(s32)D_82919D48.f08, 0xB4, D_829174E4, str);
    func_800499EC();
    func_800498C4();
    func_800496A4(0x10, 0);
    gSPDisplayList(D_800D0510++, D_829124D0);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, (u8)D_82919D48.f38, (u8)D_82919D48.f3C, (u8)D_82919D48.f40, 255);
    gDPSetPrimColor(D_800D0510++, 0, 0, (u8)D_82919D48.f28, (u8)D_82919D48.f2C, (u8)D_82919D48.f30, (u8)D_82919D48.f34);
    func_800495BC((0xA0 - halfW) - (s16)(s32)D_82919D48.f04, 0xB4, D_829174E8, str);
    func_800495BC((0xA0 - halfW) + (s16)(s32)D_82919D48.f04, 0xB4, D_829174EC, str);
    func_800499EC();
    func_800498C4();
    func_800496A4(0x10, 0);
    gSPDisplayList(D_800D0510++, D_829124A0);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, (u8)D_82919D48.f1C, (u8)D_82919D48.f20, (u8)D_82919D48.f24, 255);
    gDPSetPrimColor(D_800D0510++, 0, 0, (u8)D_82919D48.f0C, (u8)D_82919D48.f10, (u8)D_82919D48.f14, (u8)D_82919D48.f18);
    func_800495BC((0xA0 - halfW), 0xB4, D_829174F0, str);
    func_800499EC();
    func_800498C4();
    func_800496A4(0x10, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0, 0x80, 0xFF, (u8)D_82919D48.f6C);
    func_800497E4(0xFF, 0xFF, 0xFF, (u8)D_82919D48.f6C);
    func_800495BC((0xA0 - halfW), 0xB4, D_829174F4, str);
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}
#endif
