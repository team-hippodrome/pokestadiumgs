#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void func_800226C0(s32);
extern void Input_SetRepeatController(s32);
extern void func_88800B24();
extern void **D_882345F4;
void func_88231170(void) {
    func_800226C0(0x5E);
    Input_SetRepeatController(D_80087200);
    func_88800B24();
    (*(s32 *)((u8 *)(*D_882345F4) + (0xC))) = 1;
}

typedef struct {
    s8 unk_00;
    s8 unk_01;
    u16 unk_02;
} unk_func_882313A4;
extern Gfx *D_800D0510;
extern unk_func_882313A4 *D_882349D0;
extern void func_88230D80(s16 *, s16 *);
extern s16 D_8800EF58;
extern u8 *D_880068B0;
extern u8 func_882002F8(u8 *, u8 *);
extern void func_88800EC8(s32);
extern void func_88800D34(s32);
extern void func_88800DC0(s32, u8);
extern s32 func_8004D334(s32, s32);
extern void func_8004D40C(s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_880006BC(u8 *);
extern u8 D_88005FA0[];
void func_882311B8(void) {
    u32 i;
    s16 half;
    s16 alpha;

    func_88230D80(&half, &alpha);
    if (half >= D_8800EF58) {
        alpha = -alpha;
        if (half == D_8800EF58) {
            func_882002F8(D_880068B0 + 0x18 + D_882349D0->unk_00, D_880068B0 + 0x18 + D_882349D0->unk_01);
            func_882002F8(D_880068B0 + 2 + D_882349D0->unk_00, D_880068B0 + 2 + D_882349D0->unk_01);
        }
    }
    gDPPipeSync(D_800D0510++);
    gDPSetRenderMode(D_800D0510++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(D_800D0510++, G_AC_DITHER);
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, alpha);
    for (i = 0; i < 2; i++) {
        func_88800EC8(((s8 *)D_882349D0)[i]);
    }
    func_8004D334(0xEF, 0);
    func_8004D40C(1);
    for (i = 0; i < 2; i++) {
        func_88800D34(((s8 *)D_882349D0)[i]);
    }
    func_800498C4();
    func_800496A4(8, 1);
    func_880006BC(D_88005FA0);
    for (i = 0; i != 2; i++) {
        func_88800DC0(((s8 *)D_882349D0)[i], alpha);
    }
}

extern unk_func_882313A4 *D_882349D0;
extern void *D_8800EF54;
extern void D_88000E4C(void);
extern void func_882311B8(void);
extern void func_88005B60(s32, void (*)(void), void (*)(void), void (*)(void));
extern void *Util_Malloc(s32);

void func_882313A4(s8 arg0, s8 arg1, u16 arg2) {
    func_88005B60(2, D_88000E4C, func_882311B8, func_88231170);
    D_882349D0 = Util_Malloc(4);
    D_882349D0->unk_00 = arg0;
    D_882349D0->unk_01 = arg1;
    D_882349D0->unk_02 = arg2;
    D_8800EF54 = D_882349D0;
}
#pragma C_FUNCTION_PADDING(12)
#endif
