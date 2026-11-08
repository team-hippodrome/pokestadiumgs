#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_86304DF0 begin */
extern const f32 D_86307464[];
extern const f32 D_86307560;



void func_86304DF0(f32 *arg0, f32 *arg1, f32 *arg2, u8 *arg3, u8 *arg4) {
    f32 var_fv1;
    f32 frac;
    f32 scale;
    s32 temp_v0;
    s32 temp_lo;
    s32 var_a0;

    if (*(s32 *)(arg3 + 0xC) & 0x40000000) {
        temp_v0 = *(s32 *)(arg3 + 0x1C);
        if (temp_v0 < 0xB) {
            temp_lo = temp_v0 / 3;
            var_a0 = temp_lo + 1;
            if (temp_lo == 0xA) {
                var_a0 = 0;
            }
            frac = (f32)(temp_v0 % 3) / 3.0f;
            var_fv1 = (D_86307464[temp_lo] * (1.0f - frac)) + (D_86307464[var_a0] * frac);
        } else {
            var_fv1 = D_86307464[0];
        }
    } else {
        var_fv1 = D_86307464[0];
    }
    scale = D_86307560;
    if (arg0) { } // karodo: empty block; its line boundary attributes the 60.0f materialization here instead of uopt's entry constant pool, so as1 fills the multiply latency slot with it. Without it: 495.
    arg0[0] = (*(f32 *)(arg4 + 0x20) * var_fv1 * scale) + *(f32 *)(arg3 + 0x48);
    arg0[1] = (*(f32 *)(arg4 + 0x24) * var_fv1 * scale) + *(f32 *)(arg3 + 0x4C);

    arg1[0] = arg0[0] - (*(f32 *)(arg4 + 0x18) * 60.0f);
    arg1[1] = arg0[1] - (*(f32 *)(arg4 + 0x1C) * 60.0f);
    arg1[2] = (*(f32 *)(arg4 + 0x18) * 60.0f) + arg0[0];
    arg1[3] = (*(f32 *)(arg4 + 0x1C) * 60.0f) + arg0[1];
    arg1[4] = *(f32 *)(arg4 + 0x44) - (*(f32 *)(arg4 + 0x18) * 60.0f);
    arg1[5] = *(f32 *)(arg4 + 0x48) - (*(f32 *)(arg4 + 0x1C) * 60.0f);
    arg1[6] = (*(f32 *)(arg4 + 0x18) * 60.0f) + *(f32 *)(arg4 + 0x44);
    arg1[7] = (*(f32 *)(arg4 + 0x1C) * 60.0f) + *(f32 *)(arg4 + 0x48);

    arg2[0] = arg0[0] - *(f32 *)(arg4 + 0x44);
    arg2[1] = arg0[1] - *(f32 *)(arg4 + 0x48);
}
/* mkdraft:func_86304DF0 end */

void func_8630500C(void *a) {
    func_86305C48(
        *(s32 *)((u8 *)a + 0xC),
        (u8 *)a + 0x80,
        *(s32 *)((u8 *)a + 0x74)
    );
}

extern const f32 D_86307564;
extern const f32 D_86307568;
extern const f32 D_8630756C;
extern u8 *D_863075D8;
extern void func_87C03B60(void *, void *, void *);
extern void func_800277F0(u16, void *);
void func_86305038(u8 *arg0, u8 *arg1) {
    f32 x;
    s8 position[2];
    u16 sound;
    f32 y;
    f32 length;

    x = *(f32 *)(arg1 + 16);
    y = *(f32 *)(arg1 + 20);
    length = sqrtf(x * x + y * y);
    sound = 28419;
    if (D_86307564 < length) {
        sound = 28426;
    } else if (*(u32 *)(*(u8 **)(arg0 + 4) + 12) & 0x40000000) {
        sound = 28423;
    } else if (D_86307568 < length) {
        sound = 28425;
    } else if (D_8630756C < length) {
        sound = 28424;
    }
    func_87C03B60(D_863075D8 + 36700, *(u8 **)(arg0 + 12) + 72, position);
    func_800277F0(sound, position);
    if (sound == 28426 || sound == 28423) {
        func_800277F0(28428, position);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27AC10/func_86305144.s")

extern s32 func_86304CA8(u8 *, f32 *, u8 *, u8 *, f32 *, u8 *, u8 *);
extern void func_86305144(u8 *, s32);

typedef struct {
    f32 x;
    f32 y;
} Vec2_5448;



s32 func_86305448(u8 *arg0) {
    s32 result;
    Vec2_5448 anchor;
    f32 va;
    f32 vb;
    f32 vc;
    f32 vd;
    f32 *prev = *(f32 **)(*(u8 **)(arg0 + 0xC) + 0x20);
    s32 flag;

    result = 1;
    va = *(f32 *)(arg0 + 0x20) - prev[0];
    vb = *(f32 *)(arg0 + 0x24) - prev[1];
    vc = *(f32 *)(arg0 + 0x28) - prev[0];
    vd = *(f32 *)(arg0 + 0x2C) - prev[1];

    if (va * vd >= vc * vb) {
        anchor = *(Vec2_5448 *)(*(u8 **)(arg0 + 8) + 0x20);
        flag = 0;
    } else {
        anchor.x = -*(f32 *)(*(u8 **)(arg0 + 8) + 0x20);
        anchor.y = -*(f32 *)(*(u8 **)(arg0 + 8) + 0x24);
        flag = 1;
    }
    if (func_86304CA8(*(u8 **)(arg0 + 0xC), prev + 2, arg0 + 0x20, arg0 + 0x40,
                      (f32 *)&anchor, arg0 + 0x70, arg0 + 0x74) != 0) {
        *(Vec2_5448 *)(arg0 + 0x80) = anchor;
        *(u8 **)(arg0 + 0x78) = arg0 + 0x20;
        *(u8 **)(arg0 + 0x7C) = arg0 + 0x40;
        func_8630500C(arg0);
        func_86305144(arg0, flag);
        result = 0;
    }
    return result;
}

extern f32 func_87D0059C(f32 *, f32 *);
s32 func_8630557C(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg3, f32 arg4, s32 *arg5) {
    s32 result = 0;

    *(f32 *)(arg0 + 128) = *(f32 *)(arg1 + 72) - arg2[0];
    *(f32 *)(arg0 + 132) = *(f32 *)(arg1 + 76) - arg2[1];
    *(f32 *)(arg0 + 116) = sqrtf(*(f32 *)(arg0 + 132) * *(f32 *)(arg0 + 132) +
                                 *(f32 *)(arg0 + 128) * *(f32 *)(arg0 + 128));
    if (*(f32 *)(arg0 + 116) < 21.0f) {
        if (0.0f == *(f32 *)(arg0 + 116)) {
            *(f32 *)(arg0 + 128) = arg3;
            *(f32 *)(arg0 + 132) = arg4;
        }
        *(f32 *)(arg0 + 116) = 21.0f - *(f32 *)(arg0 + 116);
        func_87D0059C((f32 *)(arg0 + 128), (f32 *)(arg0 + 132));
        if (*(f32 *)(arg0 + 132) * *(f32 *)(*(u8 **)(arg0 + 8) + 36) +
            *(f32 *)(*(u8 **)(arg0 + 8) + 32) * *(f32 *)(arg0 + 128) < 0.0f) {
            *arg5 = 1;
        } else {
            *arg5 = 0;
        }
        result = 1;
    }
    return result;
}

/* mkdraft:func_86305694 begin */
// Probes the two sample points of the object at arg0 and commits an
// interpolation toward the object's own direction vector (0x40/0x44):
// 0x78/0x7C become the interpolation endpoints and 0x70 the alpha, which
// func_86305144 reads as "0 = stay at arg0 + 0x20, 1 = reach arg0 + 0x40".
// The first probe runs the direction reversed and the second one as stored;
// func_8630557C reports a hit only when the probe point lies within 21 units
// and writes through its last argument whether the probed bearing is
// negative (dot product with the object's 0x20/0x24 vector), which
// func_86305144 uses to choose its offset pair (0x48/0x4C).
// Returns 1 when neither probe point was in range and 0 after a commit.


s32 func_86305694(u8 *arg0) {
    s32 result;
    s32 dot_negative;
    f32 *start;
    f32 *probe;
    s32 pad0;  // FAKE: two unused words inflate the frame to 0x48; without
    s32 pad1;  // them every stack slot lands 8 bytes low (diff score 68).

    probe = (f32 *)(arg0 + 0x20);
    start = probe;
    result = 1;
    if (func_8630557C(arg0, *(u8 **)(arg0 + 0xC), probe, -*(f32 *)(arg0 + 0x40), -*(f32 *)(arg0 + 0x44), &dot_negative) != 0) {
        *(f32 *)(arg0 + 0x70) = 0.0f;
        *(f32 **)(arg0 + 0x78) = start;
        *(f32 **)(arg0 + 0x7C) = (f32 *)(arg0 + 0x40);
        func_8630500C(arg0);
        func_86305144(arg0, dot_negative);
        result = 0;
    } else if (func_8630557C(arg0, *(u8 **)(arg0 + 0xC), (f32 *)(arg0 + 0x28), *(f32 *)(arg0 + 0x40), *(f32 *)(arg0 + 0x44), &dot_negative) != 0) {
        *(f32 *)(arg0 + 0x70) = 1.0f;
        *(f32 **)(arg0 + 0x78) = start;
        *(f32 **)(arg0 + 0x7C) = (f32 *)(arg0 + 0x40);
        func_8630500C(arg0);
        func_86305144(arg0, dot_negative);
        result = 0;
    }
    return result;
}
/* mkdraft:func_86305694 end */

void func_86305790(void) {}
void func_86305790_padding(void) {}

#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif


M2C_UNK func_87D00648(u8 *, u8 *, u8 *);      /* extern */

void func_863057A0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, f32 arg4, f32 arg5) {
    M2C_FIELD(arg0, f32 *, 0) = (f32) (M2C_FIELD(arg3, f32 *, 0) - M2C_FIELD(arg2, f32 *, 0));
    M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg3, f32 *, 4) - M2C_FIELD(arg2, f32 *, 4));
    if ((M2C_FIELD(arg0, f32 *, 0) != 0.0f) || (M2C_FIELD(arg0, f32 *, 4) != 0.0f)) {
        func_87D00648(arg1, arg2, arg3);
        func_87D0059C((f32 *)arg1, (f32 *)(arg1 + 4));
        return;
    }
    M2C_FIELD(arg1, f32 *, 0) = arg4;
    M2C_FIELD(arg1, f32 *, 4) = arg5;
}
extern f32 func_87D0059C(f32 *, f32 *);
extern s32 func_87D00670(f32 *, f32 *, f32 *, f32 *, void *, f32 *);

typedef struct {
    f32 x;
    f32 y;
} Vec2;



void func_86305840(u8 *arg0) {
    Vec2 vector;
    Vec2 point;
    Vec2 direction;
    f32 lateral;
    f32 progress;
    f32 offset;
    f32 radius;

    point.x = *(f32 *)(arg0 + 0x18);
    point.y = *(f32 *)(arg0 + 0x1C);
    direction.x = -*(f32 *)(*(u8 **)(arg0 + 8) + 0x20);
    direction.y = -*(f32 *)(*(u8 **)(arg0 + 8) + 0x24);
    vector = *(Vec2 *)(arg0 + 0x40);
    func_87D0059C(&vector.x, &vector.y);
    if (func_87D00670((f32 *)(arg0 + 0x10), &vector.x, &lateral, &point.x,
                      &direction, &progress) != 0 &&
        progress > 21.0f && progress < 85.0f &&
        lateral > -22.0f && lateral < 22.0f) {
        /* written this way (infix sum, y term first) to reproduce the original
           FP evaluation and free-list order; the two derefs of arg0 + 0xC are
           deliberate, the second one must be re-read after the first store. */
        radius = sqrtf(*(f32 *)(*(u8 **)(arg0 + 0xC) + 0x14) * *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x14) +
                       *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x10) * *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x10));
        if (lateral > 0.0f) {
            offset = lateral - 22.0f;
        } else {
            /* - (-22.0f), not + 22.0f: IDO keeps the negated constant and emits
               sub.s against 0xC1B00000, which is what the retail code does. */
            offset = lateral - (-22.0f);
        }
        *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x48) = *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x48) + vector.x * offset;
        *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x4C) = *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x4C) + vector.y * offset;
        vector.x += direction.x * 2.0f;
        vector.y += direction.y * 2.0f;
        func_87D0059C(&vector.x, &vector.y);
        *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x10) = vector.x * radius;
        *(f32 *)(*(u8 **)(arg0 + 0xC) + 0x14) = vector.y * radius;
    }
}

/* mkdraft:func_86305A04 begin */
struct unk_func_86305B44;
extern u8 *D_863075D8;
extern void func_86304DF0(f32 *arg0, f32 *arg1, f32 *arg2, u8 *arg3, u8 *arg4);
extern s32 func_86305448();
extern s32 func_86305694(u8 *arg0);
extern void func_86305840();

// unk_func_86305B44 is defined further down this file; the forward declaration
// keeps this definition's parameter type identical to the func_86305A04
// prototype below, which takes unk_func_86305B44 *.


void func_86305A04(struct unk_func_86305B44 *arg0) {
    func_86304DF0((u8 *)arg0 + 0x18, (u8 *)arg0 + 0x20, (u8 *)arg0 + 0x68,
                  *(void **)((u8 *)arg0 + 4), *(s32 *)((u8 *)arg0 + 8));
    *(f32 *)((u8 *)arg0 + 0x40) = *(f32 *)((u8 *)arg0 + 0x28) - *(f32 *)((u8 *)arg0 + 0x20);
    *(f32 *)((u8 *)arg0 + 0x44) = *(f32 *)((u8 *)arg0 + 0x2C) - *(f32 *)((u8 *)arg0 + 0x24);
    func_863057A0((u8 *)arg0 + 0x50, (u8 *)arg0 + 0x60, (u8 *)arg0 + 0x30, (u8 *)arg0 + 0x20,
                  -*(f32 *)((u8 *)arg0 + 0x40), -*(f32 *)((u8 *)arg0 + 0x44));
    func_863057A0((u8 *)arg0 + 0x48, (u8 *)arg0 + 0x58, (u8 *)arg0 + 0x28, (u8 *)arg0 + 0x38,
                  *(f32 *)((u8 *)arg0 + 0x40), *(f32 *)((u8 *)arg0 + 0x44));
    *(f32 *)((u8 *)arg0 + 0x88) =
        *(f32 *)(*(u8 **)((u8 *)arg0 + 8) + 0x24) * *(f32 *)((u8 *)arg0 + 0x6C) +
        *(f32 *)((u8 *)arg0 + 0x68) * *(f32 *)(*(u8 **)((u8 *)arg0 + 8) + 0x20);
    *(u8 **)((u8 *)arg0 + 0xC) = *(u8 **)(D_863075D8 + 0xDC0);
    while (*(u8 **)((u8 *)arg0 + 0xC) != NULL) {
        *(f32 *)((u8 *)arg0 + 0x10) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC) + 0x48);
        *(f32 *)((u8 *)arg0 + 0x14) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC) + 0x4C);
        if (func_86305448((u8 *)arg0)) {
            func_86305694((u8 *)arg0);
        }
        func_86305840((u8 *)arg0);
        *(u8 **)((u8 *)arg0 + 0xC) = *(u8 **)(*(u8 **)((u8 *)arg0 + 0xC) + 4);
    }
    *(f32 *)(*(u8 **)((u8 *)arg0 + 8) + 0x44) = *(f32 *)((u8 *)arg0 + 0x18);
    *(f32 *)(*(u8 **)((u8 *)arg0 + 8) + 0x48) = *(f32 *)((u8 *)arg0 + 0x1C);
}
/* mkdraft:func_86305A04 end */

typedef struct unk_func_86305B44 {
    s32 index;
    u8 *entry;
    u8 *node;
    u8 unk_0C[128];
} unk_func_86305B44;

extern u8 *D_863075D8;
extern void func_86305A04(unk_func_86305B44 *);

void func_86305B44(void) {
    unk_func_86305B44 state;

    state.entry = D_863075D8 + 320;
    state.index = 0;
    do {
        state.node = *(u8 **)(state.entry + 32);
        if (*(s32 *)(state.node + 64) != 0) {
            func_86305A04(&state);
        }
        state.index++;
        state.entry += 396;
    } while (state.index < 4);
}
#endif
