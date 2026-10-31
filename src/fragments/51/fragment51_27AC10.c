#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27AC10/func_86304DF0.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27AC10/func_86305448.s")

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
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27AC10/func_86305840.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27AC10/func_86305A04.s")

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
