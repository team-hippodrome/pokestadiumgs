#include "global.h"


#ifdef VERSION_US
extern void func_800226C0(s32);
extern s32 func_8821C0B0(void);
extern void func_8822AF00(s8 *);
extern void func_88220AD0(s16, s16);
extern void func_88001900(void);
extern s8 *D_882345F4;
extern s32 D_88234660;
extern s32 D_880068B4;
void func_88230EE0(void) {
    func_800226C0(0x5E);
    if (func_8821C0B0() == 0) {
        func_8822AF00(D_882345F4 + 0x3C);
    } else if (D_88234660 != 0) {
        func_88220AD0(0x17C, 0x11F);
    } else {
        func_88001900();
        D_880068B4 = 1;
    }
}

typedef struct {
    u8 unk_00[2];
    s16 x;
    s16 y;
    u16 width;
} unk_D_882349C0;

extern unk_D_882349C0 *D_882349C0;
extern Gfx *D_800D0510;
extern void func_88230E38(void);
void func_88230F5C(void) {
    func_88230E38();
    gDPFillRectangle(D_800D0510++, D_882349C0->x, D_882349C0->y,
                     D_882349C0->x + D_882349C0->width, D_882349C0->y + 20);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1A4160/func_88230FF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1A4160/func_882310A0.s")
#endif
