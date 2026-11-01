#include "global.h"


#ifdef VERSION_US
u8 func_80073420(u8 arg0) { extern u8 D_8009F87F[]; if (arg0 > 0 && arg0 < 0xFE) return D_8009F87F[arg0]; return 0; }

u8 func_80073450(u8 arg0) { extern u8 D_8009F97F[]; if (arg0 > 0 && arg0 < 0xFE) return D_8009F97F[arg0]; return 0; }

extern u8 D_8009F87F[]; extern u8 D_8009F880[];
u8 func_80073480(u8 arg0) {
    s32 index = arg0;
    if (arg0 > 0) {
        if (index < 0x32) return D_8009F87F[index];
        if (arg0 < 0xFC) return D_8009F880[arg0];
    }
    return 0;
}

extern u8 D_8009FF6B[];
extern u8 D_8009F97F[];
extern u8 D_8009F87F[];
extern u8 D_8009F880[];
u8 func_800734CC(u8 arg0) {
    s32 index = arg0;
    u8 result = 0;
    if ((arg0 > 0) && (arg0 < 0xFC)) {
        result = D_8009F97F[index];
        if (result >= 0x33) result--;
    }
    return result;
}

u8 func_80073510(u8 arg0) { extern u8 D_8009FA7F[]; if (arg0 > 0 && arg0 < 0xFC) return D_8009FA7F[arg0]; return 0; }

u8 func_80073540(u8 arg0) { extern u8 D_8009FB7B[]; if (arg0 > 0 && arg0 < 0xFC) return D_8009FB7B[arg0]; return 0; }

u8 func_80073570(u8 arg0) { extern u8 D_8009FC77[]; if (arg0 > 0 && arg0 < 0xFB) return D_8009FC77[arg0]; return 0; }

u8 func_800735A0(u8 arg0) { extern u8 D_8009FD73[]; if (arg0 > 0 && arg0 < 0xFB) return D_8009FD73[arg0]; return 0; }

u8 func_800735D0(u8 arg0) { extern u8 D_8009FE6F[]; if (arg0 > 0 && arg0 < 0xFB) return D_8009FE6F[arg0]; return 0; }

u8 func_80073600(u8 arg0) {
    if (arg0 > 0 && arg0 < 0xFB) return D_8009FF6B[arg0];
    return 0;
}
void func_80073600_padding(void) {}

#pragma GLOBAL_ASM("asm/us/nonmatchings/74020/func_80073638.s")

extern void _bzero(void *dst, s32 size);
extern int func_80073638(s8 *src, u8 *dst, int maxLen);

s32 func_80073828(s8 *str1, s8 *str2) {
    s32 i;
    u8 buf1[0x100];
    u8 buf2[0x100];

    _bzero(buf1, 0x100);
    func_80073638(str1, buf1, 0x80);
    _bzero(buf2, 0x100);
    func_80073638(str2, buf2, 0x80);

    for (i = 0; i < 0x80 && buf1[i * 2] != 0; i++) {
        if (buf2[i * 2] < buf1[i * 2]) {
            return 1;
        }
        if (buf1[i * 2] < buf2[i * 2]) {
            return -1;
        }
    }

    if (buf2[i * 2] != 0) {
        return 1;
    }

    for (i = 0; i < 0x80 && buf1[i * 2] != 0; i++) {
        if ((s32)((u32)buf2[i * 2 + 1] >> 1) < (s32)((u32)buf1[i * 2 + 1] >> 1)) {
            return 1;
        }
        if ((s32)((u32)buf1[i * 2 + 1] >> 1) < (s32)((u32)buf2[i * 2 + 1] >> 1)) {
            return -1;
        }
    }

    for (i = 0; i < 0x80 && buf1[i * 2] != 0; i++) {
        if ((buf2[i * 2 + 1] & 1) < (buf1[i * 2 + 1] & 1)) {
            return 1;
        }
        if ((buf1[i * 2 + 1] & 1) < (buf2[i * 2 + 1] & 1)) {
            return -1;
        }
    }

    return 0;
}

/* mkdraft:func_800739EC begin */
extern s8 D_8012B410;

// Converts one EUC/JIS byte pair to Shift-JIS into arg1 (or D_8012B410 when arg1
// is NULL) and returns arg1. Bytes below 0x80 are copied through; a lead byte
// >= 0x80 with a zero trail byte ends the output.


s8 *func_800739EC(u8 *arg0, s8 *arg1) {
    s8 *p;
    u8 c;
    u8 d;
    s32 t;
    s32 base;

    if (arg1 == NULL) {
        arg1 = &D_8012B410;
    }
    c = *arg0;
    p = arg1;
    arg0++;
    while (c != 0) {
        if (c < 0x80) {
            *p = c;
            p++;
        } else {
            t = c;
            d = *arg0++;
            if (d == 0) {
                break;
            }
            c &= 0x7F;
            d &= 0x7F;
            t = (c & 1) ? ((d < 0x60) ? 0x1F : 0x20) : 0x7E;
            d += t;
            if (c < 0x5F) {
                base = 0x71;
            } else {
                base = 0xB1;
            }
            // FAKE: no-code use of t that ends its live range before the base
            // constants are materialized; uopt then colours base t0 (0x71/0xB1
            // into t0) instead of reusing t's v0. Without this block the two
            // base constants land in v0 (2 instructions differ).
            if (t) {
            }

            t = base;
            t += (c - 1) / 2;
            *p = t;
            // FAKE: second no-code use of t; it makes the t = base assignment
            // above a real definition instead of folding it into the store, so
            // the sum stays in t's v0 (addu v0,t0,t8 / sb v0). Without this
            // block the sum is a fresh temp (addu t9,t0,t8 / sb t9, 2
            // instructions differ).
            if (t) {
            }
            p[1] = d;

            p += 2;
        }
        c = *arg0;
        arg0++;
    }
    *p = 0;
    return arg1;
}
/* mkdraft:func_800739EC end */

#endif
