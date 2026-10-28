#include "global.h"


#ifdef VERSION_US
typedef struct { u8 bytes[0x6C0]; } Fragment64ModelSpan;
typedef struct { u8 counts[18]; s16 state; u8 rest[4]; } Fragment64CounterRow;
extern u8 D_87F113D0[18];
void Fragment64_IncrementMatchingCounters(u8 *root, s32 slot) {
    s32 row;
    s32 kind;
    u8 *counter;
    u8 value;
    u8 *cursor;
    for (row = 0, cursor = root; row < 4; row++, cursor += 24) {
        if ((*(u16 *)(cursor + 0x21A6) >> 15) != 0) {
            for (kind = 0; kind < 18; kind++) {
                if (D_87F113D0[kind] == (*(u8 **)(((Fragment64ModelSpan *)root)[row].bytes + slot * 4))[4]) {
                    counter = &((Fragment64CounterRow *)(root + 0x2194))[row].counts[kind];
                    break;
                }
            }
            value = *counter;
            if (value < 255) {
                *counter = value + 1;
            } else {
                *counter = 255;
            }
        }
    }
}

extern void _bzero(void *, s32);
void func_87F09870(s32 *arg0) { _bzero(arg0, 0x1C); *arg0 = 0; }

extern void Audio_PlayDefaultSound(u16);
void func_87F0989C(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = -0x100;
    (*(f32 *)((u8 *)(arg0) + (4))) = 160.0f;
    (*(f32 *)((u8 *)(arg0) + (0xC))) = 0.0f;
    (*(f32 *)((u8 *)(arg0) + (0x10))) = 0.0f;
    (*(f32 *)((u8 *)(arg0) + (8))) = 240.0f;
    Audio_PlayDefaultSound(0xCF11);
}

typedef struct { s32 mode; f32 x, y, width, velocity; u8 rgba[4]; s32 frame; } Fragment64MotionState;
extern f32 D_87F116A0, D_87F116A4;
extern f32 D_80088E50[0x1000];
void Fragment64_AdvancePanelAnimation(Fragment64MotionState *state) {
    s32 mode;
    s32 frame;
    s32 angle;
    f32 phase;
    mode = state->mode;
    if (mode == 0) return;
    switch (mode) {
    case 1:
        state->velocity -= D_87F116A0;
        state->y += state->velocity;
        if (state->y < 108.0f) {
            state->frame = 0;
            state->y = 108.0f;
            state->mode = 2;
            Audio_PlayDefaultSound(0xCF10);
            return;
        }
    case 5:
        return;
    case 2:
        frame = state->frame;
        phase = (((f32)frame * 180.0f) / 7.0f) * D_87F116A4;
        if (phase >= 0.0f) angle = (s32)(phase + 0.5f);
        else angle = (s32)(phase - 0.5f);
        state->width = (1.0f - D_80088E50[(u16)angle >> 4]) * 90.0f;
        state->frame++;
        state->x = 160.0f - state->width * 0.5f;
        if (state->frame >= 8) {
            state->frame = 0;
            state->mode = 3;
        }
        if (state->frame == 3) {
            Audio_PlayDefaultSound(0xCF17);
            return;
        }
        break;
    case 3:
        frame = state->frame;
        state->rgba[3] = (u32)(((f32)frame * 255.0f) / 8);
        state->frame++;
        if (state->frame >= 9) {
            state->frame = 0;
            state->mode = 5;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32C420/func_87F09B7C.s")

extern void func_87F0E390(u8 *, s32);
extern s32 func_8004DC6C(s32);
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern s32 func_8004EB58(s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void func_8004DCFC(u8 *, s32 *);
extern s32 func_8004C8C0(u16);

void func_87F09EBC(u8 *arg0, s32 arg1) {
    u8 *sp2C;
    s32 sp28;
    void *var_v1;

    func_87F0E390(arg0 + 0x58, arg1);
    *(s32 *)(arg0 + 0) = func_8004DC6C(0x5D);
    if (*(s32 *)(arg0 + 0) != 0) {
        sp2C = MainPool_AllocState(main_pool_get_available(), 0);
        *(s32 *)(arg0 + 0x10) = func_8004EB58((s32)sp2C, *(s32 *)(arg0 + 0));
        MainPool_FinalizeAllocation(sp2C);
    }
    *(s32 *)(arg0 + 4) = func_8004DC6C(0x5E);
    if (*(s32 *)(arg0 + 4) != 0) {
        sp2C = MainPool_AllocState(main_pool_get_available(), 0);
        *(s32 *)(arg0 + 0x14) = func_8004EB58((s32)sp2C, *(s32 *)(arg0 + 4));
        MainPool_FinalizeAllocation(sp2C);
    }
    *(s32 *)(arg0 + 8) = func_8004DC6C(0x5F);
    if (*(s32 *)(arg0 + 8) != 0) {
        sp2C = MainPool_AllocState(main_pool_get_available(), 0);
        *(s32 *)(arg0 + 0x18) = func_8004EB58((s32)sp2C, *(s32 *)(arg0 + 8));
        MainPool_FinalizeAllocation(sp2C);
    }
    *(s32 *)(arg0 + 0xC) = func_8004DC6C(0x60);
    if (*(s32 *)(arg0 + 0xC) != 0) {
        sp2C = MainPool_AllocState(main_pool_get_available(), 0);
        *(s32 *)(arg0 + 0x1C) = func_8004EB58((s32)sp2C, *(s32 *)(arg0 + 0xC));
        MainPool_FinalizeAllocation(sp2C);
    }
    func_8004DCFC((u8 *)*(s32 *)(arg0 + 0), &sp28);
    *(s32 *)(arg0 + 0x20) |= sp28;
    func_8004DCFC((u8 *)*(s32 *)(arg0 + 4), &sp28);
    *(s32 *)(arg0 + 0x20) |= sp28;
    func_8004DCFC((u8 *)*(s32 *)(arg0 + 8), &sp28);
    *(s32 *)(arg0 + 0x20) |= sp28;
    func_8004DCFC((u8 *)*(s32 *)(arg0 + 0xC), &sp28);
    *(s32 *)(arg0 + 0x20) |= sp28;
    func_8004C8C0(444);
    func_8004C8C0(445);
    var_v1 = *(void **)(arg0 + 0x10);
    *(s32 *)(arg0 + 0x38) = 0;
    *(void **)(arg0 + 0x24) = var_v1;
    *(s16 *)((u8 *)var_v1 + 0xA) = -0xF0;
    *(s32 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(f32 *)(arg0 + 0x28) = -240.0f;
    *(f32 *)(arg0 + 0x2C) = 0.0f;
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32C420/func_87F0A098.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32C420/func_87F0A3E8.s")

extern void func_800503A4(s32);
extern void func_87F09B7C(void *);
void func_87F0A5BC(void *arg0) {
    func_800503A4(*(s32 *)((u8 *)arg0 + 0x24));
    func_87F09B7C((u8 *)arg0 + 0x3C);
}
#endif
