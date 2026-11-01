#include "global.h"


#ifdef VERSION_US
extern void func_82902808(s32 arg0, s32 arg1);
extern s32 func_829056A4(void *arg0, void *arg1);
extern s32 func_82908A54(s32 arg0, s32 arg1);
extern void func_8290FB3C(s32 arg0, s32 arg1);
extern void func_8291199C(s32 arg0, s32 arg1);

void func_82900020(s32 arg0, s32 arg1) {
    switch (arg0) {
        case 0:
            func_82902808(arg0, arg1);
            break;
        case 1:
            func_829056A4((void *)arg0, (void *)arg1);
            break;
        case 2:
            func_82908A54(arg0, arg1);
            break;
        case 3:
            func_8290FB3C(arg0, arg1);
            break;
        case 4:
            func_8291199C(arg0, arg1);
            break;
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_82911B00[];
extern u8 D_82911B40[];
void func_829000A0(void) { Gfx *temp_v1 = D_800D0510++; temp_v1->words.w0 = 0xDE000000; temp_v1->words.w1 = (u32)D_82911B00; }
#endif

#ifdef VERSION_US
void func_829000CC(void) { Gfx *temp_v1 = D_800D0510++; temp_v1->words.w0 = 0xDE000000; temp_v1->words.w1 = (u32)D_82911B40; }
#endif

#ifdef VERSION_US
void func_829000F8(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gDPPipeSync(D_800D0510++);
    gDPSetPrimColor(D_800D0510++, 0, 0, arg0, arg1, arg2, arg3);
}
#endif

#ifdef VERSION_US
void func_82900168(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gDPPipeSync(D_800D0510++);
    gDPSetFillColor(D_800D0510++, (GPACK_RGBA5551(arg0, arg1, arg2, arg3) << 16) |
                                     GPACK_RGBA5551(arg0, arg1, arg2, arg3));
}
#endif

#ifdef VERSION_US
void func_829001E4(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, arg0, arg1, arg2, arg3);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82900254 begin */
extern Gfx D_80094DE0[];
extern Gfx *D_800D0510;
extern void func_82900168(u8 arg0, u8 arg1, u8 arg2, u8 arg3);

// Paints the window (arg4, arg5, arg4+arg6, arg5+arg7) minus the box
// (arg0, arg1, arg0+arg2, arg1+arg3) as eight clamped fill rectangles: the
// corner and side strips around the box, split so each piece stays axis-aligned.
// The caller func_82901554 supplies both rectangles' bounds: the box from its
// arguments and the window from D_829188B0 (corner at [3]/[4], size at [1]/[2]).
//@src/fragments/67/fragment67_33D6A0.c
// func_8413FDB0 draws the same ring against the fixed screen bounds
// (0, 0, 0x140, 0xF0); its top strip starts at y = 0 while this one's starts at
// the literal 30, so the top strip ignores arg5.
//@src/fragments/79/fragment79_3ADCA0.c


void func_82900254(s16 arg0, s16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    gSPDisplayList(D_800D0510++, D_80094DE0);
    func_82900168(0, 0, 0, 1);
    if (arg4 < arg0) {
        if (arg5 < arg1) gDPScisFillRectangle(D_800D0510++, arg4, arg5, arg0, arg1);
        if (arg1 + arg3 < arg5 + arg7) gDPScisFillRectangle(D_800D0510++, arg4, arg1 + arg3, arg0, arg5 + arg7);
        gDPScisFillRectangle(D_800D0510++, arg4, arg1, arg0, arg1 + arg3);
    }
    if (arg0 + arg2 < arg4 + arg6) {
        if (arg5 < arg1) gDPScisFillRectangle(D_800D0510++, arg0 + arg2, arg5, arg4 + arg6, arg1);
        if (arg1 + arg3 < arg5 + arg7) gDPScisFillRectangle(D_800D0510++, arg0 + arg2, arg1 + arg3, arg4 + arg6, arg5 + arg7);
        gDPScisFillRectangle(D_800D0510++, arg0 + arg2, arg1, arg4 + arg6, arg1 + arg3);
    }
    if (arg5 < arg1) gDPScisFillRectangle(D_800D0510++, arg0, 30, arg0 + arg2, arg1);
    if (arg1 + arg3 < arg5 + arg7) gDPScisFillRectangle(D_800D0510++, arg0, arg1 + arg3, arg0 + arg2, arg5 + arg7);
}
/* mkdraft:func_82900254 end */
#endif

#ifdef VERSION_US
extern f32 D_829173D0;
s32 func_8290074C(f32 arg0) {
    s32 temp_v1;

    temp_v1 = (s32) arg0 & 0x1F;
    return ((temp_v1 << 0xA) + (s32) (((arg0 - (f32) temp_v1) + D_829173D0) * 1024.0f)) & 0xFFFF;
}
#endif

void func_82900798(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/67/fragment67_33CB20/func_829007A0.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_82900AFC begin */
extern s32 func_8004CA10(u16 *);
extern s32 func_8004CA24(u16 *);
extern u8 *func_8004CA60(u8 *);
extern s32 func_8004CA38(u8 *);
extern s32 func_8004CA4C(u8 *);
extern void func_829007A0(s16, s16, u16, u16, s32, s32, u8 *, s32, s32, s32);

void func_82900AFC(s16 arg0, s16 arg1, u16 arg2, u16 arg3, u16 *arg4) {
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp24 = 1;
    u8 *sp34;
    sp44 = func_8004CA10(arg4);
    sp40 = func_8004CA24(arg4);
    sp34 = func_8004CA60((u8 *)arg4);
    sp3C = func_8004CA38((u8 *)arg4);
    func_829007A0(arg0, arg1, arg2, arg3, sp44, sp40, sp34, sp3C, func_8004CA4C((u8 *)arg4), sp24);
}
/* mkdraft:func_82900AFC end */
#endif
