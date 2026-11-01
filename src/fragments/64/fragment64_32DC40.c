#include "global.h"


#ifdef VERSION_US
extern f32 D_87F116D0; // 360/65536: converts s16 binary angles to degrees.
s32 func_87F0AFD0(u8 *arg0, f32 *arg1, f32 *arg2, s16 *rotation) {
    /* Byte 0x68 holds the two flags func_87F0B154 tests (bit31/bit30 of its word). */
    struct unk_func_87F0AFD0 {
        u8 pad[0x68];
        u8 bit7 : 1;
        u8 bit6 : 1;
    } *flags = (void *)arg0;
    f32 to_degrees = D_87F116D0;

    // The ROM writes these nine fields twice in a row.
    *(f32 *)(arg0 + 0x0) = arg1[0];
    *(f32 *)(arg0 + 0x4) = arg1[1];
    *(f32 *)(arg0 + 0x8) = arg1[2];
    *(f32 *)(arg0 + 0xC) = arg2[0];
    *(f32 *)(arg0 + 0x10) = arg2[1];
    *(f32 *)(arg0 + 0x14) = arg2[2];
    *(f32 *)(arg0 + 0x18) = rotation[0] * to_degrees;
    *(f32 *)(arg0 + 0x1C) = rotation[1] * to_degrees;
    *(f32 *)(arg0 + 0x20) = rotation[2] * to_degrees;
    *(f32 *)(arg0 + 0x0) = arg1[0];
    *(f32 *)(arg0 + 0x4) = arg1[1];
    *(f32 *)(arg0 + 0x8) = arg1[2];
    *(f32 *)(arg0 + 0xC) = arg2[0];
    *(f32 *)(arg0 + 0x10) = arg2[1];
    *(f32 *)(arg0 + 0x14) = arg2[2];
    *(f32 *)(arg0 + 0x18) = rotation[0] * to_degrees;
    *(f32 *)(arg0 + 0x1C) = rotation[1] * to_degrees;
    *(f32 *)(arg0 + 0x20) = rotation[2] * to_degrees;
    flags->bit7 = 0;
    *(s32 *)(arg0 + 0x6C) = 0;
    *(s32 *)(arg0 + 0x70) = 1;
    *(s32 *)(arg0 + 0x74) = 0;
    *(s32 *)(arg0 + 0x78) = 1;
    *(s32 *)(arg0 + 0x7C) = 0;
    *(s32 *)(arg0 + 0x80) = 1;
    *(s32 *)(arg0 + 0x84) = 0;
    flags->bit6 = 0;
    return 1;
}

void func_87F0B0FC(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    /* Word at +0x68, same flags word func_87F0B154 reads (bit31 = byte 0x68 bit 7). */
    struct unk_func_87F0B0FC {
        u8 pad[0x68];
        u32 bit31 : 1;
        u32 bit30 : 1;
        u32 rest : 30;
    };
    /* Sub-record at arg0+0x48; its tail word at +0x20 is the same flags word. */
    struct unk_func_87F0B0FC_048 {
        s32 unk_00;
        s32 unk_04;
        s32 unk_08;
        u8 pad[8];
        f32 unk_14;
        f32 unk_18;
        f32 unk_1C;
        u32 bit31 : 1;
        u32 bit30 : 1;
        u32 rest : 30;
    };
    struct unk_func_87F0B0FC_048 *work = (void *)((u8 *)arg0 + 0x48);

    if (((struct unk_func_87F0B0FC *)arg0)->bit31 == 0) {
        work->unk_00 = 0;
        work->unk_04 = 0;
        work->unk_08 = arg4;
        work->bit31 = 1;
        work->bit30 = 0;
        work->unk_14 = arg1;
        work->unk_18 = arg2;
        work->unk_1C = arg3;
    }
}
void func_87F0B154(void *arg0) {
    struct State {
        u8 pad[0x68];
        u32 bit31 : 1;
        u32 bit30 : 1;
        u32 rest : 30;
    };
    struct State *state = arg0;
    if ((state->bit30 == 0) && (state->bit31 == 1)) {
        state->bit31 = 0;
        state->bit30 = 1;
    }
}

void func_87F0B18C(u8 *arg0) {
    arg0[0x68] &= 0xFF7F;
    arg0[0x68] &= 0xFFBF;
}

void func_87F0B1A4(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    if (arg2 != arg1[0] || arg3 != arg1[1] || arg4 != arg1[2]) {
        *(f32 *)(arg0 + 0) = arg1[0];
        *(f32 *)(arg0 + 4) = arg1[1];
        *(f32 *)(arg0 + 8) = arg1[2];
        *(s32 *)(arg0 + 108) = 0;
        *(s32 *)(arg0 + 112) = arg5;
        *(u32 *)(arg0 + 132) = (*(u32 *)(arg0 + 132) | 1) | arg6;
        *(f32 *)(arg0 + 40) = arg3;
        *(f32 *)(arg0 + 36) = arg2;
        *(f32 *)(arg0 + 44) = arg4;
        func_87F0B18C(arg0);
    }
}

void func_87F0B24C(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    if (arg2 != arg1[0] || arg3 != arg1[1] || arg4 != arg1[2]) {
        *(f32 *)(arg0 + 12) = arg1[0];
        *(f32 *)(arg0 + 16) = arg1[1];
        *(f32 *)(arg0 + 20) = arg1[2];
        *(s32 *)(arg0 + 116) = 0;
        *(s32 *)(arg0 + 120) = arg5;
        *(u32 *)(arg0 + 132) = (*(u32 *)(arg0 + 132) | 0x10) | arg6;
        *(f32 *)(arg0 + 52) = arg3;
        *(f32 *)(arg0 + 48) = arg2;
        *(f32 *)(arg0 + 56) = arg4;
        func_87F0B18C(arg0);
    }
}

/* mkdraft:func_87F0B2F4 begin */
#include "global.h"
extern f32 D_87F116D4;
extern f32 D_87F116D8;
extern void func_87F0B18C(u8 *arg0);

// Degree-valued counterpart of func_87F0B1A4 and func_87F0B24C. The requested
// components (arg2..arg4) are scaled by 65536/360 and rounded to the nearest
// integer before being compared with the previous orientation, which arg1 holds
// as s16 binary angles. On any mismatch the state captures the old orientation
// in degrees (bytes 24/28/32), the new orientation in degrees (bytes 60/64/68),
// the elapsed word (124), the duration (128), and flag 0x100 together with the
// caller's mask (byte 132), then calls func_87F0B18C.
// The first rounding block and the two arg1 comparisons share one source line.
// IDO 7.1 breaks scheduling ties with .loc line numbers; splitting them moves
// the lwc1 of arg3 (0x24(sp)) after the 0.5f constant and changes two words.



void func_87F0B2F4(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    s16 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    f32 to_degrees;

    temp_fv0 = arg2 * D_87F116D4;
    do {
        if ((arg2 * D_87F116D4) >= 0.0f) {
            var_v0 = (s32) (temp_fv0 + 0.5f); } else { var_v0 = (s32) (temp_fv0 - 0.5f); } temp_v1 = *((s16 *) ((u8 *) arg1)); if (temp_v1 == ((s16) var_v0)) { temp_fv0_2 = arg3 * D_87F116D4;
            if (temp_fv0_2 >= 0.0f) {
                var_v0_2 = (s32) (temp_fv0_2 + 0.5f);
            } else {
                var_v0_2 = (s32) (temp_fv0_2 - 0.5f);
            }
            if (*((s16 *) ((u8 *) arg1 + 2)) == (0, (s16) var_v0_2)) { // FAKE: comma keeps the arg1 load ahead of the narrowing cast
                temp_fv0_3 = arg4 * D_87F116D4;
                if (temp_fv0_3 >= 0.0f) {
                    var_v0_3 = (s32) (temp_fv0_3 + 0.5f);
                } else {
                    var_v0_3 = (s32) (temp_fv0_3 - 0.5f);
                }
                if (*((s16 *) ((u8 *) arg1 + 4)) != (0, (s16) var_v0_3)) { // FAKE: as above
                    goto block_12;
                }
            } else {
                goto block_12;
            }
        } else {
        block_12:
            to_degrees = D_87F116D8;
            *(f32 *) (arg0 + 24) = (f32) (((f32) temp_v1) * to_degrees);
            *(f32 *) (arg0 + 28) = (f32) (((f32) (*((s16 *) ((u8 *) arg1 + 2))) * to_degrees));
            *(f32 *) (arg0 + 32) = (f32) (((f32) (*((s16 *) ((u8 *) arg1 + 4))) * to_degrees));
            *(s32 *) (arg0 + 124) = 0;
            *(s32 *) (arg0 + 128) = arg5;
            *(s32 *) (arg0 + 132) = (s32) (((*(s32 *) (arg0 + 132)) | 0x100) | arg6);
            *(f32 *) (arg0 + 60) = arg2;
            *(f32 *) (arg0 + 64) = arg3;
            *(f32 *) (arg0 + 68) = arg4;
            func_87F0B18C(arg0);
        }
    } while (0);
}
/* mkdraft:func_87F0B2F4 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32DC40/func_87F0B4AC.s")

extern void func_8004C8C0(s32);
void func_87F0BD10(void) {
    func_8004C8C0(447);
}

void func_87F0BD30(u8 *arg0, u16 arg1, u16 arg2, s32 arg3) {
    *(u16 *)(arg0 + 0) = arg1;
    *(u16 *)(arg0 + 2) = arg2;
    *(s32 *)(arg0 + 4) = arg3;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32DC40/func_87F0BD48.s")
#endif
