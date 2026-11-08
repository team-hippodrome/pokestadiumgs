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

extern u8 D_800A0068[];
extern u8 D_800A006C[];
extern u8 D_800A0070[];
extern u8 D_800A0074[];
extern u8 D_800A0078[];

// FAKE: the `& 0xFF` chains below are u8-to-u8 masks that uopt folds away, so none
// of them change the emitted instructions; each one only reserves expression-temp
// slots, and the number of slots before a statement decides which of t6..t9 the
// surrounding loads and results get. Retail's build shows the same four-register
// rotation, so the masks are reproduced to place each temp on retail's register.
// Removing all of them scores 49 differing instructions of 124; per group (differ
// score with that group alone reverted): the three `| 1` stores 47, the 0xDC store
// 26, the twelve double-glyph loads 16, the lowercase `& 0xFFu` 56.


s32 func_80073638(u8 *arg0, u8 *arg1, s32 arg2)
{
  s32 i = 0;
  s8 value = arg0[0];
  while ((value != 0) && (i < arg2))
  {
    if ((value >= 0x61) && (value < 0x7B))
    {
      arg1[i * 2] = value - 0x20;
      // FAKE: one masked-away slot; reverting this line alone scores 56.
      arg1[(i * 2) + 1] = (arg1[(i * 2) + 1] & 0xFF01) & 0xFFu;
      arg1[(i * 2) + 1] |= 1;
      i++;
    }
    else
    {
      switch (value)
      {
        case 0xE4:
          // FAKE: one masked-away slot. Reverting the three `| 1` stores of cases
          // 0xE4, 0xF6 and 0xFC to plain `|= 1` scores 47.
          arg1[(i * 2) + 1] = (arg1[(i * 2) + 1] & 0xFF) | 1;

        case 0xC4:
          arg1[i * 2] = 0x41;
          arg1[(i * 2) + 1] = (arg1[(i * 2) + 1] & 0xFF01) | 0xA;
          i++;
          break;

        case 0xF6:
          // FAKE: one masked-away slot, as in case 0xE4.
          arg1[(i * 2) + 1] = (arg1[(i * 2) + 1] & 0xFF) | 1;

        case 0xD6:
          arg1[i * 2] = 0x4F;
          arg1[(i * 2) + 1] = (arg1[(i * 2) + 1] & 0xFF01) | 0xA;
          i++;
          break;

        case 0xFC:
          // FAKE: one masked-away slot, as in case 0xE4.
          arg1[(i * 2) + 1] = (arg1[(i * 2) + 1] & 0xFF) | 1;

        case 0xDC:
          arg1[i * 2] = 0x55;
          // FAKE: three masked-away slots; reverting them scores 26. Their count is
          // what puts the first double-glyph load of case 0xDF on retail's t9.
          arg1[(i * 2) + 1] = ((arg1[(i * 2) + 1] & 0xFF01) | 0xA) & 0xFF & 0xFF & 0xFF;
          i++;
          break;
          // FAKE: unreachable (after the break) but kept because uopt allocates its
          // temp slot before the following cases; without it the score is 2.
          return i;

        case 0xDF:
          // FAKE: two masked-away slots per store. Each store then advances the temp
          // pool by three, which is why the four stores read t9,t8,t7,t6 instead of
          // counting upwards. Reverting the twelve double-glyph stores of cases 0xDF,
          // 0xBC and 0xBD scores 16.
          arg1[i * 2] = D_800A0078[0] & 0xFF & 0xFF;
          arg1[(i * 2) + 1] = D_800A0078[1] & 0xFF & 0xFF;
          arg1[(i * 2) + 2] = D_800A0078[0] & 0xFF & 0xFF;
          arg1[(i * 2) + 3] = D_800A0078[1] & 0xFF & 0xFF;
          i += 2;
          break;

        case 0xBC:
          arg1[i * 2] = D_800A0068[0] & 0xFF & 0xFF;
          arg1[(i * 2) + 1] = D_800A0068[1] & 0xFF & 0xFF;
          arg1[(i * 2) + 2] = D_800A006C[0] & 0xFF & 0xFF;
          arg1[(i * 2) + 3] = D_800A006C[1] & 0xFF & 0xFF;
          i += 2;
          break;

        case 0xBD:
          arg1[i * 2] = D_800A0070[0] & 0xFF & 0xFF;
          arg1[(i * 2) + 1] = D_800A0070[1] & 0xFF & 0xFF;
          arg1[(i * 2) + 2] = D_800A0074[0] & 0xFF & 0xFF;
          arg1[(i * 2) + 3] = D_800A0074[1] & 0xFF & 0xFF;
          i += 2;
          break;

        default:
          arg1[i * 2] = value;
          i++;
          break;

      }

    }
    value = arg0[1];
    arg0++;
  }

}

extern void _bzero(void *dst, s32 size);
s32 func_80073638(u8 *arg0, u8 *arg1, s32 arg2);

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
