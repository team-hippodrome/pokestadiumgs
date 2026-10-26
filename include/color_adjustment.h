#ifndef POKESTADIUMGS_COLOR_ADJUSTMENT_H
#define POKESTADIUMGS_COLOR_ADJUSTMENT_H

#include <ultra64.h>

// Packed HSV adjustments consumed by the scene renderer's color functions.
//@src/229E0.c
// The tag and members match that renderer's existing declaration.
typedef union S1_arg1_func_80010CA8 {
    struct {
        s16 unk_00;
        s8 unk_02;
        s8 unk_03;
    };
    u32 raw;
} ColorAdjustment;

#endif
