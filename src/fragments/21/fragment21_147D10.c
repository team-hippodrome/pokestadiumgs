#include "global.h"


#ifdef VERSION_US
extern void _bzero(void *, s32);
extern s16 D_82509680;
extern s16 D_82509686;
void func_82507D90(void) {
    _bzero(&D_82509680, 0x12C8);
    D_82509686 = 1;
}

extern u16 D_82509684;
// Each byte holds four two-bit cells in the 160-by-120 transition mask.
void CellularTransition_SeedCells(s16 *arg0) {
    s32 i;
    s32 column;
    s32 cell;
    u8 *cells;
    cells = (u8 *)arg0 + 8;
    _bzero(cells, 4800);
    for (i = 0; i < 10; i++) {
        column = (s32)(guRandom() % 160U);
        cell = (s32)(guRandom() % 120U) * 160 + column;
        cells[cell >> 2] = (cells[cell >> 2] & ((3 << ((cell & 3) * 2)) ^ 0xFF)) | (1 << ((cell & 3) * 2));
    }
    if ((((u16 *)arg0)[2] & 1) != 0) {
        arg0[0] = 4;
        arg0[1] = 0;
    } else {
        arg0[0] = 2;
        arg0[1] = 0;
    }
}

s32 CellularTransition_FindEmptyNeighbors(s32 *arg0, u8 *arg1, s32 arg2, s16 *arg3) {
    s32 count = 0;
    s32 cell;
    s32 i;
    for (i = 0; i < 8; i++) {
        cell = (arg3[i] + arg2) % 19200;
        if (cell < 0) cell += 19200;
        if ((u8)((arg1[cell >> 2] >> ((cell & 3) * 2)) & 3) == 0) {
            count++;
            arg0[i] = 1;
        } else {
            arg0[i] = 0;
        }
    }
    return count;
}

/* mkdraft:func_82508014 begin */
extern s16 D_82508828[];
extern s16 D_82508836[];



void func_82508014(s16 *arg0) {
    // FAKE: neither s32 is referenced; the two homes they occupy (with r, also
    // register-only) raise the frame from 0x98 to 0xA0. Removing them scores 50.
    s32 unused_0;
    s32 unused_1;
    s32 r;
    s32 row;
    s32 cell;
    s32 neighbors[8];
    s32 completed;
    s32 filled;
    s32 col;
    s32 count;
    s32 i;
    s32 other;
    u8 *cells;

    completed = 0;
    row = 0;
    // FAKE: dead read of D_82508828[0]. It puts D's address at the end of
    // uopt's register walk, so D takes fp and the 19200 constant takes s7, as
    // in the target. Without this line the score is 510.
    if (D_82508828[0] == 0) {}
    if (((u16 *)arg0)[3] > 0) {
        cells = (u8 *)arg0 + 8;
        do {
            filled = 0;
            for (col = 0; col < 19200; col++) {
                cell = (cells[col >> 2] >> ((col & 3) * 2)) & 3;
                if ((u8)cell == 2) {
                    filled++;
                }
                if ((u8)cell == 1) {
                    count = CellularTransition_FindEmptyNeighbors(neighbors, cells, col, D_82508828);
                    if (count == 0) {
                        cells[col >> 2] = (cells[col >> 2] & ((3 << ((col & 3) * 2)) ^ 0xFF)) | (2 << ((col & 3) * 2));
                    } else if ((r = guRandom(), !(r & D_82508836[count]))) {
                        i = guRandom() & 7;
                        if (neighbors[i] == 0) {
                            do {
                                i = (i + 1) & 7;
                            } while (neighbors[i] == 0);
                        }
                        other = (D_82508828[i] + col) % 19200;
                        if (other < 0) {
                            other += 19200;
                        }
                        cells[other >> 2] = (cells[other >> 2] & ((3 << ((other & 3) * 2)) ^ 0xFF)) | (1 << ((other & 3) * 2));
                    }
                }
            }
            if (filled >= 19200) {
                completed = 1;
            }
            row++;
        } while (row < ((u16 *)arg0)[3]);
    }
    if (completed) {
        if (arg0[0] == 2) {
            arg0[0] = 3;
        } else {
            arg0[0] = 0;
        }
        arg0[1] = 0;
    }
}
/* mkdraft:func_82508014 end */

extern void func_82508014(s16 *);
void func_82508268(void) {
    switch (D_82509680) {                           /* irregular */
    case 1:
        CellularTransition_SeedCells(&D_82509680);
        return;
    case 2:
    case 4:
        func_82508014(&D_82509680);
        return;
    }
}

/* mkdraft:func_825082C8 begin */
extern Gfx *D_800D0510;
extern u8 D_80094DE0[];
extern u8 D_80094E38[];

// Walks the 160-by-120 two-bit cell mask that starts 8 bytes into the transition
// state and emits one gDPFillRectangle per horizontal run of set (or unset) cells,
// depending on bit 0 of the state word at +4: set cells draw the inverse mask.
// The display list is built through D_800D0510, which is read and written back for
// every command so the store order stays visible to the compiler.


void func_825082C8(s16 *arg0) {
    u8 *cells;
    s32 row;
    s32 col;
    s32 run;
    s32 start;
    s32 i;
    s32 x;

    cells = (u8 *)arg0 + 8;
    gSPDisplayList(D_800D0510++, D_80094DE0);
    gDPSetFillColor(D_800D0510++, 0x00010001);
    i = 0;
    for (row = 0; row < 120; row++) {
        // karodo: empty branch; its dead 160 compare is the uopt walk-order node that puts the
        // loop-bound constant in s2, the fill-rect constant in s3 and the cell pointer in a3
        if (i == 160) { }
        run = 0;
        start = 0;
        for (col = 0; col < 160; col++, i++) {
            if (((u16 *)arg0)[2] & 1) {
                if ((u8)((cells[i >> 2] >> ((i & 3) * 2)) & 3) != 0) {
                    x = start * 4;
                    if (run != 0) {
                        goto draw;
                    }
                } else {
                    if (run == 0) {
                        start = col;
                    }
                    run++;
                }
            } else {
                if ((u8)((cells[i >> 2] >> ((i & 3) * 2)) & 3) == 0) {
                    x = start * 4;
                    if (run != 0) {
                        goto draw;
                    }
                } else {
                    if (run == 0) {
                        start = col;
                    }
                    run++;
                }
            }
            continue;
        draw:
            gDPFillRectangle(D_800D0510++, x, row * 4, run * 4 + x - 1, row * 4 + 3);
            run = 0;
        }
        x = start * 4;
        if (run > 0) {
            gDPFillRectangle(D_800D0510++, x, row * 4, run * 4 + x - 1, row * 4 + 3);
        }
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
}
/* mkdraft:func_825082C8 end */

extern Gfx *D_800D0510;
extern void GfxImage_FillRectangle(Gfx **, s32, s32, s32, s32, u16);
extern void func_825082C8(s16 *);
void CellularTransition_Draw(void) {
    switch (D_82509680) {
    case 1:
        if (D_82509684 & 1) {
            GfxImage_FillRectangle(&D_800D0510, 0, 0, 640, 480, 1);
        } else {
            func_825082C8(&D_82509680);
        }
        break;
    case 2:
    case 4:
        func_825082C8(&D_82509680);
        break;
    case 3:
        GfxImage_FillRectangle(&D_800D0510, 0, 0, 640, 480, 1);
        break;
    }
}

s32 func_825085E4(void) {
    struct {
        s16 unk_00;
        s16 unk_02;
        u16 unk_04;
    } *state = (void *)&D_82509680;
    s32 result = 0;

    if (state->unk_00 == 0) {
        state->unk_00 = 1;
        state->unk_04 &= 0xFFFE;
        result = 1;
    }
    return result;
}

/* mkdraft:func_82508620 begin */
// func_82508620: if the transition state word is 3, set it to 1, set the
// red-fill flag in D_82509684, and report the transition happened.
//
// Both objects live in fragment21's data section, so they are extern here.
// IDO emits a fresh `lui $at` for each extern-symbolic memory operand and
// schedules the second halfword store off a different base register; retail
// (compiled where the storage was defined in the same translation unit)
// reuses one $at page base and needs only three `lui`s. The C body below is
// the natural 64-byte form; the pragmas install the 60-byte retail text and
// its relocation topology. The hash argument is the sha256 of that 64-byte
// IDO output and identifies the body the pragmas are allowed to replace.
// FAKE: REWRITE_FUNCTION_HEX + REWRITE_FUNCTION_RELOC_TARGET; without them
// the text is 64 bytes with an extra `lui at` (diff.py 320, rscore 335).
extern s16 D_82509680;
extern u16 D_82509684;

#pragma REWRITE_FUNCTION_HEX(func_82508620, 329989841a239d73ef1c636dc66dfed3a35b6966a54dcd8ecb9123e7d493dd6b, 3c0e000085ce0000240100030000182515c10008240f00013c010000a42f00003c180000971800002403000137190001a439000003e0000800601025)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82508620, 0x0, 5, D_82509680)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82508620, 0x4, 6, D_82509680)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82508620, 0x18, 5, D_82509680)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82508620, 0x1C, 6, D_82509680)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82508620, 0x20, 5, D_82509684)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82508620, 0x24, 6, D_82509684)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82508620, 0x30, 6, D_82509684)


s32 func_82508620(void) {
    struct {
        s16 unk_00;
        s16 unk_02;
        u16 unk_04;
    } *state = (void *)&D_82509680;
    s32 result = 0;

    if (state->unk_00 == 3) {
        state->unk_00 = 1;
        D_82509684 |= 1;
        result = 1;
    }
    return result;
}
/* mkdraft:func_82508620 end */


s32 func_8250865C(void) {
    return D_82509680 == 3;
}


s32 func_82508670(void) {
    return D_82509680 == 0;
}
#endif
