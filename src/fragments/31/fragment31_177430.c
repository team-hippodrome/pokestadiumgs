#include "global.h"


#ifdef VERSION_US
extern void func_800226C0(s32);
extern u8 D_88234680;

void func_882041B0(void) {
    (*(s32 *)((u8 *)(&D_88234680) + (0x2C))) = (s32) (*(s32 *)((u8 *)(&D_88234680) + (0x28)));
    func_800226C0(0x132);
}

extern s32 D_882346AC;
void func_882041E0(void) {
    D_882346AC = 2;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_177430/func_882041F0.s")

extern void func_88000288(void *, s16, s16, s16, u8, u8, u8, u8);
extern s32 func_80001FF0(void);
extern void func_88200134();
extern void func_88002720(void *, u16, void *);
extern void func_88003A00(s32);
extern void func_882000AC(u8, s16, s16, u16, u16, s32, s32, u8);
extern void D_88000E4C(void);
extern void func_88216544(void);
extern void func_88208174(void);
extern void func_882105B0(void);
extern void func_8820C258(void);
extern void func_88213530(void);
extern void func_882041E0(void);
extern void Input_SetRepeatController(s32);
extern void Util_Free(void *);
extern void main_pool_pop_state(s32);
extern s32 D_80087200;
extern s32 D_88234560;
extern s32 D_88234564;
extern u8 D_882346B0;
extern u8 D_882346BC;
extern s16 D_882346C8;
extern u16 D_882346CA;
extern u8 D_88234688;
extern u8 D_8823468C;

// k frames at 60 fps, scaled to the current frame rate and rounded half away from zero.
#define FPS_ROUND(k) ((f32)(k) * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)(k) / 60.0f > 0.0f) ? 0.5f : -0.5f))
#define P ((u8 *)&D_88234680)
#define S16(o) (*(s16 *)(P + (o)))
#define S32(o) (*(s32 *)(P + (o)))

void func_88204400(void) {
    switch (S32(0x2C)) {
    case 0:
        S32(0x2C) = 1;
        S16(0) = S16(0) - S16(0) % S16(2);
        func_800226C0(0x12F);
        break;
    case 1:
        S16(0) = S16(0) - S16(2);
        if (S16(0) <= 0) {
            S16(0) = 0;
            S32(0x2C) = 2;
            S16(4) = S16(4) - S16(4) % S16(6);
            func_800226C0(0x130);
        }
        break;
    case 2:
        S16(4) = S16(4) - S16(6);
        if (S16(4) <= 0) {
            S16(4) = 0;
            S32(0x2C) = 3;
            Input_SetRepeatController(D_80087200);
            func_882000AC(0, D_882346C8, 0x141, D_882346CA, 0x60, (s32)D_88000E4C, (s32)func_882041B0, 0);
            func_88000288(&D_882346B0,
                          (s16)((s32)FPS_ROUND(13) + (s32)FPS_ROUND(10) + (s32)FPS_ROUND(5)), 0xFF, 0,
                          (s32)FPS_ROUND(13), (s32)FPS_ROUND(10), (s32)FPS_ROUND(5), (s32)FPS_ROUND(7));
            func_88000288(&D_882346BC,
                          (s16)((s32)FPS_ROUND(20) + (s32)FPS_ROUND(15) + (s32)FPS_ROUND(8)), 0x96, 0x32,
                          (s32)FPS_ROUND(20), (s32)FPS_ROUND(15), (s32)FPS_ROUND(8), (s32)FPS_ROUND(11));
        }
        break;
    case 3: {
        if (((s32 *)D_88234564)[7] == 2) {
            if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
                func_800226C0(0x133);
                switch (*(u16 *)(P + 8)) {
                case 0:
                    S32(0x24) = 0;
                    S32(0x1C) = (s32)func_88216544;
                    break;
                case 1:
                    S32(0x24) = 1;
                    S32(0x1C) = (s32)func_88208174;
                    break;
                case 2:
                    S32(0x24) = 2;
                    S32(0x1C) = (s32)func_882105B0;
                    break;
                case 3:
                    S32(0x24) = 3;
                    S32(0x1C) = (s32)func_8820C258;
                    break;
                case 4:
                    S32(0x24) = 4;
                    S32(0x1C) = (s32)func_88213530;
                    break;
                }
                S32(0x28) = 6;
                func_88200134(0, 0);
            } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
                func_800226C0(0x56);
                S32(0x24) = 6;
                S32(0x1C) = (s32)D_88000E4C;
                S32(0x28) = 7;
                func_88200134(0, 0);
                S16(6) = (s32)(2880.0f / func_80001FF0() + ((2880.0f / func_80001FF0() > 0.0f) ? 0.5f : -0.5f));
            } else {
                func_88002720(&D_88234688, 5, &D_8823468C);
            }
        }
        func_88003A00(D_88234564);
        break;
    }
    case 4:
        *(u8 *)(P + 0x20) -= 1;
        if (*(u8 *)(P + 0x20) == 0) {
            D_88234560 = S32(0x24);
            Util_Free((void *)D_88234564);
            main_pool_pop_state(0x50435345);
            ((void (*)(void))S32(0x1C))();
            S32(0x2C) = 5;
        }
        break;
    case 5:
        func_882041E0();
        break;
    case 6:
        S16(4) = S16(6) + S16(4);
        if (S16(4) >= 0xF5) {
            S16(4) = 0xF5;
            S32(0x2C) = 4;
            *(u8 *)(P + 0x20) = 2;
        }
        break;
    case 7:
        S16(4) = S16(6) + S16(4);
        if (S16(4) >= 0x138) {
            S16(4) = 0x138;
            S32(0x2C) = 8;
            func_800226C0(0x131);
        }
        break;
    case 8:
        S16(0) = S16(2) + S16(0);
        if (S16(0) >= 0x44) {
            S16(0) = 0x44;
            Util_Free((void *)D_88234564);
            main_pool_pop_state(0x50435345);
            D_88234560 = S32(0x24);
            ((void (*)(void))S32(0x1C))();
            S32(0x2C) = 0;
        }
        break;
    }
}
#undef FPS_ROUND
#undef P
#undef S16
#undef S32

extern void func_80044424(s16, s16, s16, s16, s16, s16, s16, s16, s32, s32);



void func_88205114(s32 arg0, s32 arg1) {
    func_80044424((s16)(arg0 - 7), 0, 8, (s16)(arg1 - 7), 0x100, 0xA0, 0x400, 0, 0, 1);
    func_80044424((s16)(arg0 - 7), (s16)(arg1 - 7), 8, 8, 0x300, 0, 0x400, 0x400, 0, 1);
    func_80044424(0, (s16)(arg1 - 7), (s16)(arg0 - 7), 8, 0x2E0, 0, 0, 0x400, 0, 1);
}

/* mkdraft:func_88205200 begin */
extern void func_80044424(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle, s32 tile);

// Both parameters are s32: the target loads arg1 from its incoming-argument home
// slot as a word (lw 0x3c(sp)) and narrows the result with sll/sra, and it also
// reloads arg0 as a word (lw 0x38(sp)) for the last quad's x/width arithmetic.
// Declaring either parameter s16 turns that reload into lh from the home word.


void func_88205200(s32 arg0, s32 arg1) {
    func_80044424((s16)arg0, 0, 5, (s16)(arg1 - 7), 0, 160, 1024, 0, 0, 1);
    func_80044424((s16)arg0, (s16)(arg1 - 7), 5, 8, 512, 0, 1024, 1024, 0, 1);
    func_80044424((s16)(arg0 + 5), (s16)(arg1 - 7), (s16)(0x27B - arg0), 8, 736, 0, 0, 1024, 0, 1);
}
/* mkdraft:func_88205200 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_177430/func_882052F8.s")

s32 func_88205D7C(void) {
    return (D_882346AC == 3) ? 1 : 0;
}
#endif
