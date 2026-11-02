#include "global.h"


#ifdef VERSION_US
typedef struct unk_func_87F0C000 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
} unk_func_87F0C000;

extern f32 D_80087E50[];
extern f32 D_80088E50[];

void func_87F0C000(unk_func_87F0C000* arg0) {
    f32 var_fv0;

    var_fv0 = arg0->unk_18;
    arg0->unk_00 = D_80088E50[arg0->unk_1C >> 4] * D_80087E50[arg0->unk_1E >> 4] * var_fv0 + arg0->unk_0C;
    arg0->unk_04 = -D_80087E50[arg0->unk_1C >> 4] * var_fv0 + arg0->unk_10;
    arg0->unk_08 = D_80088E50[arg0->unk_1C >> 4] * D_80088E50[arg0->unk_1E >> 4] * var_fv0 + arg0->unk_14;
}

void func_87F0C094(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, s16 arg6) {
    (*(f32 *)((u8 *)(arg0) + (0xC))) = arg1;
    (*(f32 *)((u8 *)(arg0) + (0x10))) = arg2;
    (*(f32 *)((u8 *)(arg0) + (0x14))) = arg3;
    (*(f32 *)((u8 *)(arg0) + (0x18))) = arg4;
    (*(s16 *)((u8 *)(arg0) + (0x1C))) = arg5;
    (*(s16 *)((u8 *)(arg0) + (0x1E))) = arg6;
    func_87F0C000(arg0);
    (*(s32 *)((u8 *)(arg0) + (0x20))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x24))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x28))) = 1;
}

/* mkdraft:func_87F0C0FC begin */
#include "controller.h"

// Aim-point record: three f32 components at 0x00/0x04/0x08 are the base position func_87F0C000
// offsets from, three more at 0x0C/0x10/0x14 hold the aim direction/position it accumulates,
// 0x18 is a scale factor, and 0x1C/0x1E are angles. func_87F0C358 reads 0x1C/0x1E with lh and
// scales them by D_87F11714, so the pair is s16.
//@src/fragments/64/fragment64_32EC70.c
typedef struct unk_87F0C0FC {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    s16 unk_1C;
    s16 unk_1E;
} unk_87F0C0FC;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f_87F0C0FC;

extern void func_80035A10(Vec3f_87F0C0FC *arg0);
extern f32 D_87F11710;



void func_87F0C0FC(unk_87F0C0FC *arg0) {
    Vec3f_87F0C0FC dir;
    Vec3f_87F0C0FC lateral;
    Vec3f_87F0C0FC up;

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;

    dir.x = arg0->unk_0C - arg0->unk_00;
    dir.y = arg0->unk_10 - arg0->unk_04;
    dir.z = arg0->unk_14 - arg0->unk_08;
    func_80035A10(&dir);
    lateral.x = up.y * dir.z - up.z * dir.y;
    lateral.y = up.z * dir.x - up.x * dir.z;
    lateral.z = up.x * dir.y - up.y * dir.x;
    func_80035A10(&lateral);
    up.x = dir.y * lateral.z - dir.z * lateral.y;
    up.y = dir.z * lateral.x - dir.x * lateral.z;
    up.z = dir.x * lateral.y - dir.y * lateral.x;
    func_80035A10(&up);

    if ((D_80087200->buttonsHeld & 0x8000) != 0) {
        f32 limit = D_87F11710;

        arg0->unk_18 -= D_80087200->stickYNorm;
        if (arg0->unk_18 < limit) {
            arg0->unk_18 = limit;
        }
    } else if ((D_80087200->buttonsHeld & 0x4000) != 0) {
        arg0->unk_0C += -lateral.x * D_80087200->stickXNorm + up.x * D_80087200->stickYNorm;
        arg0->unk_10 += -lateral.y * D_80087200->stickXNorm + up.y * D_80087200->stickYNorm;
        arg0->unk_14 += -lateral.z * D_80087200->stickXNorm + up.z * D_80087200->stickYNorm;
    } else {
        arg0->unk_1C -= D_80087200->stickYNorm * 5.0f;
        arg0->unk_1E += D_80087200->stickXNorm * 5.0f;
    }

    func_87F0C000(arg0);
}
/* mkdraft:func_87F0C0FC end */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f_87F0C358;

typedef struct {
    u8 unk_00[12];
    Vec3f_87F0C358 unk_0C;
    f32 unk_18;
    s16 unk_1C;
    s16 unk_1E;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    Vec3f_87F0C358 unk_2C;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
} unk_func_87F0C358;

extern f32 D_87F11714;
void func_87F0C358(unk_func_87F0C358 *arg0, s32 arg1, f32 arg2, f32 arg3,
                   f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 factor;

    factor = D_87F11714;
    arg0->unk_2C = arg0->unk_0C;
    arg0->unk_38 = arg0->unk_18;
    arg0->unk_3C = arg0->unk_1C * factor;
    arg0->unk_40 = arg0->unk_1E * factor;
    arg0->unk_44 = arg2;
    arg0->unk_48 = arg3;
    arg0->unk_4C = arg4;
    arg0->unk_50 = arg5;
    arg0->unk_54 = arg6;
    arg0->unk_58 = arg7;
    arg0->unk_20 = 1;
    arg0->unk_24 = 0;
    arg0->unk_28 = arg1;
}

/* mkdraft:func_87F0C3EC begin */
extern f32 D_80088E50[];
extern f32 D_87F11718;
extern f32 D_87F1171C;
extern f32 D_87F11720;
extern f32 D_87F11724;
extern f32 D_87F11728;

// Advances the pose blend armed by func_87F0C358: over unk_28 samples the keys
// recorded in unk_2C/unk_38/unk_3C/unk_40 ease toward the target keys in
// unk_44..unk_58. The frame fraction becomes a half turn in 16-bit turn units
// (180 degrees * 65535 / 360), and weight is (cos(angle) + 1) / 2, falling from
// 1 to 0 across the blend. D_80088E50 is the cosine table indexed by angle >> 4,
// paired with the sine table D_80087E50 0x1000 bytes before it.
//@src/340C0.c
// func_87F0C000 then rebuilds unk_00..unk_08 from the blended anchor, height
// and yaw/pitch pair.


void func_87F0C3EC(unk_func_87F0C358 *arg0) {
    f32 weight;
    f32 inverse;
    f32 phase;
    f32 ratio;
    s32 angle;

    if (arg0->unk_20 & 1) {
        ratio = (f32) arg0->unk_24 / (f32) arg0->unk_28;
        phase = 180.0f * ratio * D_87F11718;
        if (phase >= 0.0f) {
            angle = (s32) (phase + 0.5f);
        } else {
            angle = (s32) (phase - 0.5f);
        }
        weight = (D_80088E50[(u16) angle >> 4] + 1.0f) * 0.5f;
        inverse = 1.0f - weight;
        arg0->unk_0C.x = arg0->unk_2C.x * weight + arg0->unk_44 * inverse;
        arg0->unk_0C.y = arg0->unk_2C.y * weight + arg0->unk_48 * inverse;
        arg0->unk_0C.z = arg0->unk_2C.z * weight + arg0->unk_4C * inverse;
        arg0->unk_18 = arg0->unk_38 * weight + arg0->unk_50 * inverse;
        if ((arg0->unk_3C * weight + arg0->unk_54 * inverse) * D_87F1171C >= 0.0f) {
            arg0->unk_1C = (s32) ((arg0->unk_3C * weight + arg0->unk_54 * inverse) * D_87F11720 + 0.5f);
        } else {
            arg0->unk_1C = (s32) ((arg0->unk_3C * weight + arg0->unk_54 * inverse) * D_87F11724 - 0.5f);
        }
        phase = (arg0->unk_40 * weight + arg0->unk_58 * inverse) * D_87F11728;
        if (phase >= 0.0f) {
            arg0->unk_1E = (s32) (phase + 0.5f);
        } else {
            arg0->unk_1E = (s32) (phase - 0.5f);
        }
        func_87F0C000((unk_func_87F0C000 *) arg0);
        arg0->unk_24++;
        if (arg0->unk_24 > arg0->unk_28) {
            arg0->unk_20 &= ~1;
        }
    }
}
/* mkdraft:func_87F0C3EC end */
#endif
