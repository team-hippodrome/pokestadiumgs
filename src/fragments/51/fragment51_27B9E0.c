#include "global.h"


#ifdef VERSION_US
void func_86305BC0(u8 *arg0, u8 *arg1, u8 *arg2, f32 scale) {
    struct V {
        f32 x;
        f32 y;
    };
    f32 dot = ((struct V *)arg1)->x * ((struct V *)arg2)->x + ((struct V *)arg1)->y * ((struct V *)arg2)->y;

    if (dot >= 0.0f) {
        *(f32 *)(arg0 + 0x48) += ((struct V *)arg1)->x * scale;
        *(f32 *)(arg0 + 0x4C) += ((struct V *)arg1)->y * scale;
        return;
    }
    *(f32 *)(arg0 + 0x48) -= ((struct V *)arg1)->x * scale;
    //!bug: subtracts the x component from 0x4C; the branch above adds y.
    *(f32 *)(arg0 + 0x4C) -= ((struct V *)arg1)->x * scale;
}

void func_86305C48(void *arg0, void *arg1, f32 arg2) {
    *(f32 *)((u8 *)arg0 + 0x48) += *(f32 *)((u8 *)arg1 + 0) * arg2;
    *(f32 *)((u8 *)arg0 + 0x4C) += *(f32 *)((u8 *)arg1 + 4) * arg2;
}

/* mkdraft:func_86305C78 begin */
extern f32 D_86307580;
extern f32 D_86307584;
extern f32 D_86307588;
extern f32 D_8630758C;
extern u32 func_8003570C(void);

// Bounces the 2D vector at +0x10/+0x14 off a surface facing along arg1:
// v -= 2 * (v . dir) * dir. Each arg1 component is jittered before use by a
// uniform value in [-0.0025, 0.0025) (func_8003570C returns the next LCG word,
// divided by 2^32, times 0.005, minus 0.0025). The caller then rescales the
// resulting vector with func_86305D88.


void func_86305C78(u8* arg0, f32* arg1) {
    // FAKE: the two reserved slots keep the frame at 0x28 and put dir_x's spill
    // at 0x18. Diff score 50 without the pad, 8 with pad[1], 58 with pad[3].
    s32 pad[2];
    f32 dot_scale;
    f32 dir_x;
    f32 dir_y;

    dir_x = (arg1[0] + ((f32)func_8003570C() / 4294967296.0f) * D_86307580) - D_86307584;
    dir_y = (arg1[1] + ((f32)func_8003570C() / 4294967296.0f) * D_86307588) - D_8630758C;
    dot_scale = (*((f32*)(arg0 + 0x14)) * arg1[1] + arg1[0] * *((f32*)(arg0 + 0x10))) * -2.0f;
    *(f32*)(arg0 + 0x10) += dir_x * dot_scale;
    *(f32*)(arg0 + 0x14) += dir_y * dot_scale;
}
/* mkdraft:func_86305C78 end */

extern u8 *D_863075D8;
// Rescales the 2D vector at +0x10/+0x14 to length (its current length + 1),
// clamped to the f32 limit at D_863075D8 + 0x8F34. A zero vector is left unchanged.
void func_86305D88(u8 *arg0) {
    f32 max_length;
    f32 x = *(f32 *)(arg0 + 0x10);
    f32 y = *(f32 *)(arg0 + 0x14);
    f32 length = sqrtf(x * x + y * y);

    if (length > 0) {
        *(f32 *)(arg0 + 0x10) = x / length;
        *(f32 *)(arg0 + 0x14) = y / length;
        length += 1.0f;
        max_length = *(f32 *)(D_863075D8 + 0x8F34);
        if (max_length < length) {
            length = max_length;
        }
        *(f32 *)(arg0 + 0x10) *= length;
        *(f32 *)(arg0 + 0x14) *= length;
    }
}

extern u8 *D_863075D8;
extern void func_87C03B60(void *, void *, void *);
extern void func_800277F0(u16, void *);
void func_86305E20(u8 *arg0) {
    s8 position[2];

    if (*(s32 *)D_863075D8 == 4) {
        func_87C03B60(D_863075D8 + 0x8F5C, arg0 + 0x48, position);
        func_800277F0(0x6F04, position);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27B9E0/func_86305E70.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27B9E0/func_86305FD8.s")

s32 func_86305E70();
extern void func_86305FD8(s32);

void func_863060CC(s32 arg0) {
    if (func_86305E70() != 0) {
        func_86305FD8(arg0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27B9E0/func_863060FC.s")

extern void *D_87F119DC;

// Advances the screen tint state at D_87F119DC by one frame. The mode word at
// +0xC holds two fade bits: while 0x1000000 is set the tint is white and its
// alpha at +0xC7 fades from 255 to 0 as the frame counter at +0x1C goes from 0
// to 15; while 0x2000000 is set the tint fades over 60 frames instead, taking
// its color from +0xC4 (white for the first 3 frames, then the color chosen by
// the signed byte at arg0 + 0x20). Each fade bit clears itself, zeroing the
// alpha, once the counter passes that fade's length.
void func_863063C0(void *arg0) {
    s32 elapsed;

    if ((*(s32 *)((u8 *)D_87F119DC + 0xC)) & 0x3000000) {
        if ((*(s32 *)((u8 *)D_87F119DC + 0xC)) & 0x1000000) {
            (*(s32 *)((u8 *)D_87F119DC + 0xC4)) = 0xFFFFFF00;
            elapsed = (*(s32 *)((u8 *)D_87F119DC + 0x1C));
            if (elapsed >= 0x10) {
                (*(s32 *)((u8 *)D_87F119DC + 0xC)) &= ~0x1000000;
                (*(u8 *)((u8 *)D_87F119DC + 0xC7)) = 0;
            } else {
                (*(u8 *)((u8 *)D_87F119DC + 0xC7)) = (u8)(255.0f - (((f32)elapsed / 15.0f) * 255.0f));
            }
        } else {
            if ((*(s32 *)((u8 *)D_87F119DC + 0x1C)) < 3) {
                (*(s32 *)((u8 *)D_87F119DC + 0xC4)) = 0xFFFFFF00;
            } else {
                switch (*(s8 *)((u8 *)arg0 + 0x20)) {
                    case 0:
                        (*(s32 *)((u8 *)D_87F119DC + 0xC4)) = 0xAAAAFF00;
                        break;
                    case 1:
                        (*(s32 *)((u8 *)D_87F119DC + 0xC4)) = 0xAAFFAA00;
                        break;
                    case 2:
                        (*(s32 *)((u8 *)D_87F119DC + 0xC4)) = 0xFFAAAA00;
                        break;
                    case 3:
                        (*(s32 *)((u8 *)D_87F119DC + 0xC4)) = 0xFFFFAA00;
                        break;
                    default:
                        (*(s32 *)((u8 *)D_87F119DC + 0xC4)) = 0xFFFFFF00;
                        break;
                }
            }
            elapsed = (*(s32 *)((u8 *)D_87F119DC + 0x1C));
            if (elapsed >= 61) {
                (*(s32 *)((u8 *)D_87F119DC + 0xC)) &= ~0x2000000;
                (*(u8 *)((u8 *)D_87F119DC + 0xC7)) = 0;
            } else {
                (*(u8 *)((u8 *)D_87F119DC + 0xC7)) = (u8)(255.0f - (((f32)elapsed / 60.0f) * 255.0f));
            }
        }
    } else {
        (*(u8 *)((u8 *)D_87F119DC + 0xC7)) = 0;
    }
}

void func_86306638(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0))) = (f32) (*(f32 *)((u8 *)(D_87F119DC) + (0x48)));
    (*(f32 *)((u8 *)(arg0) + (4))) = (f32) (*(f32 *)((u8 *)(D_87F119DC) + (0x4C)));
}


void func_8630665C(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (8))) = (f32) ((*(f32 *)((u8 *)(D_87F119DC) + (0x48))) - (*(f32 *)((u8 *)(arg0) + (0))));
    (*(f32 *)((u8 *)(arg0) + (0xC))) = (f32) ((*(f32 *)((u8 *)(D_87F119DC) + (0x4C))) - (*(f32 *)((u8 *)(arg0) + (4))));
}

extern s32 func_86304920(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_86306690(u8 *arg0, s8 *arg1) {
    if (arg1[33] != -1) {
        if (func_86304920(*(f32 *)(arg0 + 72), *(f32 *)(arg0 + 76),
                         0.0f, 180.0f, -180.0f, 0.0f, 0.0f, -180.0f, 180.0f, 0.0f) != 0) {
            arg1[32] = arg1[33];
            arg1[33] = -1;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27B9E0/func_86306710.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_27B9E0/func_86306AC0.s")

extern void func_863060FC(void **);
extern void func_86306710(void **);
extern void func_86306AC0(void **);
void func_86306CC4(void) {
    s32 temp_v1;
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(D_87F119DC) + (0x20)));
    (*(s32 *)((u8 *)(temp_v0) + (0x1C))) = (s32) ((*(s32 *)((u8 *)(temp_v0) + (0x1C))) + 1);
    temp_v1 = (*(s32 *)((u8 *)(D_87F119DC) + (0xC)));
    if (temp_v1 & 0x10000000) {
        func_863060FC(&D_87F119DC);
        return;
    }
    if (temp_v1 & 0x20000000) {
        func_86306AC0(&D_87F119DC);
        return;
    }
    func_86306710(&D_87F119DC);
}

extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern u32 func_8003570C(void);
extern void func_86304544(void *);

void func_86306D3C(void) {
    u8 *obj;
    u8 *data;
    s8 position[2];
    u8 *node;

    obj = func_87F025B8(D_863075D8 + 0xDB4, (void *)func_86306CC4);
    if (obj != NULL) {
        data = *(u8 **)(obj + 0x20);
        node = obj + 0x24;
        func_8003F1DC(node);
        func_8003F114(node, 0, -1, *(s32 *)(D_863075D8 + 0x100));
        *(u8 **)(obj + 0x38) = obj;
        *(s32 *)(obj + 0xC) |= 0x10000000;
        *(s16 *)(obj + 0x46) = -0x2000;
        *(f32 *)(obj + 0x4C) = 0.0f;
        *(f32 *)(obj + 0x48) = 0.0f;
        *(f32 *)(obj + 0x5C) = 0.0f;
        *(f32 *)(obj + 0x58) = 0.0f;
        *(f32 *)(obj + 0x54) = 0.0f;
        *(f32 *)(obj + 0x50) = 100.0f;
        *(f32 *)(data + 0) = 0.0f;
        *(f32 *)(data + 0x4) = *(f32 *)(obj + 0x4C);
        *(s8 *)(data + 0x20) = -1;
        *(s8 *)(data + 0x21) = -1;
        *(s32 *)(data + 0x1C) = 0;
        *(f32 *)(data + 0x10) = 0.0f;
        *(f32 *)(data + 0x14) = 0.0f;
        *(f32 *)(data + 0x18) = 0.0f;
        *(s32 *)(obj + 0x1C) = (s32)((((f32)func_8003570C() / 4294967296.0f) + 2.0f) * -48.0f);
        func_86304544(obj);
        func_87C03B60(D_863075D8 + 0x8F5C, obj + 0x48, position);
        func_800277F0(0x6F02, position);
    }
}
#endif
