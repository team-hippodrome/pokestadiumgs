#include "global.h"

/* func_82500780 is in its own file so that its function static
 * D_82508F7C can be pinned (see datamig_bss.ld). IDO keeps a function
 * static in a register between its load and store-back; an extern or
 * file static is reloaded after every store. */

#ifdef VERSION_US
typedef struct {
    s32 value;
} Fragment21Word; // copied as a struct (one lw/sw pair per field)

#ifndef ROUND_MAX
#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
#endif

extern f32 func_825003DC(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5);
extern void func_825004A4(s32 arg0, s32 arg1, u16 *arg2, f32 arg3, u8 *arg4, u8 *arg5, s32 arg6);
extern u8 D_82508D10[];
#define ENTRY (D_82508D10 + idx * 0x3C) // 0x3C-byte record of entry idx
extern u8 *D_82508F84;
extern s16 D_82508F6A;
extern s16 D_82508F70;
extern s16 D_82508F7A;
extern s32 D_82508798;
extern s32 D_8250879C;
extern s32 D_825087A0;
extern s32 D_825087A4;
extern s32 D_825087A8;
extern s32 D_825087AC;
extern s32 D_825087B0;
extern s32 D_825087B4;
extern s32 D_825087B8;
extern s32 func_8004C990(s32, s32);
extern void func_800226C0(s32);
s32 func_82500780(s32 arg0, u8 *arg1) {
    static s16 D_82508F7C;
    s32 pad0; // unused locals keep the retail stack layout
    s32 idx;
    s32 sub;
    s32 pad1;
    s16 *p;
    u8 *state;
    s32 tex;
    s32 show;
    s32 pad2[2];
    f32 alpha;
    s32 flag;

    sub = (u32)*(s32 *)(arg1 + 0x20) >> 8;
    state = D_82508F84;
    idx = *(s32 *)(arg1 + 0x20) & 0xFF;
    tex = func_8004C990(*(u16 *)(arg1 + 0x24), *(u16 *)(arg1 + 0x26));
    alpha = 0.0f;
    flag = 0;
    switch (arg0) {
        case 0:
            arg1[0x28] = 2;
            if (sub < 2) {
                p = (s16 *)(D_82508D10 + idx * 0x3C + sub * 4);
                p[10] = *(s16 *)(arg1 + 8);
                p[11] = *(s16 *)(arg1 + 0xA);
            }
            *(u16 *)(arg1 + 2) &= 0xFFFD;
            break;
        case 1:
            if (*(u8 **)(ENTRY + 4) != NULL) {
                *(Fragment21Word *)(arg1 + 0x2C) = *(Fragment21Word *)(*(u8 **)(ENTRY + 4) + 0x28);
                *(Fragment21Word *)(arg1 + 0x30) = *(Fragment21Word *)(*(u8 **)(ENTRY + 4) + 0x2C);
            }
            switch (*(s16 *)(state + 0xE)) {
                case 2:
                    show = 1;
                    if (*(s16 *)(ENTRY + 2) != 0) {
                        alpha = func_825003DC(D_82508798 - idx * 10, D_8250879C, D_825087A0, D_825087A4, D_825087A8, &flag);
                    } else {
                        show = 0;
                    }
                    break;
                case 1:
                    if (*(s16 *)(ENTRY + 2) != 0) {
                        show = 1;
                        if (idx != D_82508F6A) {
                            alpha = 1.0f;
                        } else {
                            alpha = func_825003DC(D_82508798, D_825087AC, D_825087B0, D_825087B4, D_825087B8, &flag);
                        }
                    } else if (idx != D_82508F6A) {
                        show = 0;
                    } else {
                        alpha = func_825003DC(D_82508798, D_825087AC, D_825087B0, D_825087B4, D_825087B8, &flag);
                        show = 1;
                    }
                    break;
                default:
                    if (*(s16 *)(ENTRY + 2) != 0) {
                        show = 1;
                        if (idx != D_82508F6A) {
                            alpha = 1.0f;
                        } else {
                            alpha = func_825003DC(D_82508798, D_825087AC, D_825087B0, D_825087B4, D_825087B8, &flag);
                            if (D_82508F7A > 0 && flag != 0) {
                                if (D_82508F7C < 4) {
                                    D_82508F7C++;
                                }
                                if (D_82508F7C == 2) {
                                    func_800226C0(1);
                                }
                            }
                        }
                    } else {
                        show = 0;
                    }
                    break;
            }
            if (show) {
                // FAKE: the dead tests make IDO compute the two call-argument
                // addresses before the rounding, like retail; keep them on this line.
                if (arg1 + 0x2C) {} if (arg1 + 0x30) {} arg1[0x2F] = (s32)ROUND_MAX(255.0f * alpha);
                p = (s16 *)(ENTRY + sub * 4);
                *(s16 *)(arg1 + 8) = p[10];
                *(s16 *)(arg1 + 0xA) = p[11];
                func_825004A4(*(s16 *)(arg1 + 8), *(s16 *)(arg1 + 0xA), (u16 *)tex, 1.0f, arg1 + 0x2C, arg1 + 0x30, *(s16 *)(state + 0x10));
                if (flag != 0 && D_82508F7A > 0) {
                    func_800226C0(0x10F);
                }
            }
            if (D_82508D10 == ENTRY && D_82508F70 == 0) {
                D_82508798++;
            }
            break;
    }
    return 0;
}
#endif
