#include "global.h"


#ifdef VERSION_US
extern void func_8001CA3C(void *);
extern void func_8001B6D0(void *, s32, s32);
#pragma GLOBAL_ASM("asm/us/nonmatchings/1C2D0/func_8001B6D0.s")

void AudioSequence_Update(u8 *sequence) {
    typedef struct { u8 reserved:5; u8 recalculateVolume:1; u8 reserved1:1; u8 applyBend:1; } SequenceUpdates;
    s32 i;
    u8 *channel;

    if (*(u16 *)(sequence + 0x12) != 0 && *(u32 *)(sequence + 0xDC) == 0) {
        *(f32 *)(sequence + 0x1C) += *(f32 *)(sequence + 0x20);
        ((SequenceUpdates *)sequence)->recalculateVolume = 1;
        if (*(f32 *)(sequence + 0x1C) > 1.0f) { *(f32 *)(sequence + 0x1C) = 1.0f; }
        if (*(f32 *)(sequence + 0x1C) < 0.0f) { *(f32 *)(sequence + 0x1C) = 0.0f; }
        (*(u16 *)(sequence + 0x12))--;
        if (*(u16 *)(sequence + 0x12) == 0) {
            if (sequence[1] == 2) {
                func_8001CA3C(sequence);
                return;
            }
        }
    }
    if (((*(u32 *)sequence << 5) >> 31)) {
        *(f32 *)(sequence + 0x30) = *(f32 *)(sequence + 0x2C) * *(f32 *)(sequence + 0x1C);
    }
    for (i = 0; i < 16; i++) {
        channel = ((u8 **)(sequence + 0x38))[i];
        if ((*(u32 *)channel >> 31) == 1) {
            func_8001B6D0(channel, ((*(u32 *)sequence << 5) >> 31), (sequence[0] & 1));
        }

    }
    ((SequenceUpdates *)sequence)->recalculateVolume = 0;
}

extern f32 D_8008E994[];
f32 func_8001BA28(void *arg0) {
    struct State { u8 pad0[2]; u16 sum; u16 step; u8 pad6[2]; f32 scale; };
    struct State *state = arg0;
    u32 index;
    f32 one;
    f32 result;
    one = 1.0f;
    state->sum += state->step;
    index = (state->sum >> 8) & 0xFF;
    if (index >= 0x7F) {
        index = 0x7F;
        state->pad0[0] = 0;
    }
    result = (D_8008E994[index] - one) * state->scale + one;
    return result;
}

s32 func_8001BA84(u8 *arg0) {
    u32 index;
    *(u32 *)(arg0 + 4) += (s32)*(f32 *)(arg0 + 0x10);
    index = (*(u32 *)(arg0 + 4) >> 10) & 0x3F;
    return (*(s16 **)(arg0 + 8))[index];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1C2D0/func_8001BABC.s")

extern f32 func_8001BA28();
extern f32 func_8001BABC();
void func_8001BCA4(u8 *arg0) {
    u8 *state;
    state = arg0;
    if (state[0x80] != 0) {
        *(f32 *)(state + 0x38) = func_8001BA28(state + 0x80);
    }
    if (state[0xA0] != 0) {
        *(f32 *)(state + 0x3C) = func_8001BABC(state + 0x8C);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1C2D0/func_8001BD00.s")

void func_8001BDF0(u8 *arg0) {
    struct Vector { s32 x, y, z; };

    *(f32 *)(arg0 + 0x38) = 1.0f;
    *(struct Vector *)(arg0 + 0x80) =
        *(struct Vector *)(*(u8 **)(arg0 + 0x44) + 0x30);
}

void func_8001BE1C(void *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    (*(s16 *)((u8 *)(arg0) + (2))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = arg1;
    (*(f32 *)((u8 *)(arg0) + (4))) = 0.0f;
    (*(f32 *)((u8 *)(arg0) + (0x10))) = 0.0f;
    (*(f32 *)((u8 *)(arg0) + (8))) = 0.0f;
    (*(f32 *)((u8 *)(arg0) + (0xC))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1C2D0/func_8001BE44.s")
#endif
