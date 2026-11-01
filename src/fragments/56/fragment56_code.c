#include "global.h"


#ifdef VERSION_US
s32 func_86800020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 temp_fv0;
    temp_fv0 = (f32)((s32)(arg1 - arg3) / (s32)(arg0 - arg2));
    return (s32)(((f32)arg4 * temp_fv0) + (f32)(arg1 - (s32)((f32)arg0 * temp_fv0)));
}

extern u8 *D_8009491C;
extern s32 D_86807CCC[];
extern s32 D_8680863C;
extern s32 D_8682F2A8;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);
extern Gfx *D_800D0510;
extern s32 func_86800020(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void Fragment56_TextureFadeCallback(s32 event, void *arg1) {
    s32 alpha;
    s32 asset;
    u32 texture_frame;
    u8 *node;
    if (event == 0) {
        func_8004C990(152, D_86807CCC[0]);
    }
    if (event == 5) {
        node = D_8009491C;
        if (*(u32 *)(node + 0x14) >= 12U) {
            *(u32 *)(node + 0x14) = 11;
        }
        texture_frame = *(u32 *)(node + 0x14);
        asset = func_8004C990(152, D_86807CCC[texture_frame]);
        if (*(u32 *)(node + 0x14) < 8U) {
            alpha = func_86800020(0, 255, 6, 185, *(u32 *)(node + 0x14));
        } else {
            alpha = func_86800020(6, 185, 11, 0, *(u32 *)(node + 0x14));
        }
        gDPPipeSync(D_800D0510++);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0, 0, 0, alpha);
        gDPSetCombine(D_800D0510++, 0xFF97FF, 0xFFFCFE38);
        gSPSegment(D_800D0510++, 15, func_8004CA60((u8 *)asset));
        gSPDisplayList(D_800D0510++, D_8680863C);
        func_8003CD84();
        if (*(s32 *)((u8 *)&D_8682F2A8 + 0xC) == 0 && D_8682F2A8 < 9) {
            (*(u32 *)(node + 0x14))++;
        }
        if (D_8682F2A8 == 8) {
            (*(u32 *)(node + 0x14))--;
        }
    }
}

extern s32 D_86808644;
extern s32 D_86808640;
extern s32 D_8682F2B4;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);
extern Gfx * D_800D0510;
void Fragment56_AnimatedTextureCallback(s32 event, void *node) {
    s32 asset;
    static s32 frame_counter;
    if (event == 0) {
        D_86808644 = func_8004C990(227, 0);
    }
    if (event == 5) {
        if (D_8682F2B4 == 0) {
            frame_counter++;
        }
        if (frame_counter >= 21) frame_counter = 0;
        asset = func_8004C990(227, frame_counter / 4);
        D_86808644 = asset;
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 15, func_8004CA60((u8 *)D_86808644));
        gSPDisplayList(D_800D0510++, D_86808640);
        func_8003CD84();
    }
}

extern f32 D_86807CB0;
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
s32 func_868003E4(s32 arg0, void *arg1) {
    // The second (f32) parameter is passed the integer constant 0, which IDO
    // loads with li; writing 0.0f moves it from $f0 instead (diff score 474).
    func_80038E14(arg1, 0, 0.0f, D_86807CB0, 0.0f, 0.0f, 0.0f, 0);
    return 0;
}

extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86800434(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(sp26 + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 - 0x2000);
    }
    return 0;
}

s32 func_8680049C(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - sp26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 + 0x6000);
    }
    return 0;
}

extern f32 D_8682F304;
extern f32 D_86807C60;
extern f32 D_86807C84;
extern s32 D_86808698[];
extern s32 D_868086C0[];
void func_86800508(void) {
    s32 index;
    f32 t;
    s32 height;
    s32 (*endpoint)[];
    f32 threshold;
    
    
    t = 0.0f;
    threshold = D_8682F304;
    do {
        
        do {
            do {
                
                index = 0;
                height = 500; do {
                    t = 0.0f;
                    for (;;) {
                        if (((f32)height - D_86807C60 * t * t) <= threshold) {
                            D_86808698[index++] = t / D_86807C84;
                            break;
                        }
                        t += D_86807C84;
                    }
                    height += 10;
                } while (&D_86808698[index] != *(endpoint = &D_868086C0));
            } while (0);
        } while (0);
    } while (0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86800594.s")

extern s32 D_86807CB4;
extern s32 D_86808648[20];
// Fills D_86808648 with 0-19 and shuffles it with D_86807CB4 random swaps of two distinct
// entries. func_868063CC advances D_86807CB4 every frame, cycling it through 50-150.
void func_86800A7C(void) {
    s32 i;
    s32 first;
    s32 second;
    s32 temp;

    for (i = 0; i < 20; i++) {
        D_86808648[i] = i;
    }

    for (i = 0; i < D_86807CB4; i++) {
        first = guRandom() % 20;
        do {
            second = guRandom() % 20;
        } while (first == second);

        temp = D_86808648[first];
        D_86808648[first] = D_86808648[second];
        D_86808648[second] = temp;
    }
}

extern f32 D_86807C60;
extern f32 D_86807C94;
extern f32 D_86807C98;
extern f32 D_86807C9C;
extern f32 D_86807CC8;
extern s32 D_8682F2E4;
void Fragment56_UpdateScaledParameters(void) {
    switch (D_8682F2E4) {
    case 1:
        D_86807C60 = 17.0f * D_86807CC8;
        if (D_86807C98 == D_86807C94) {
            D_86807C9C = 4.5f;
        } else {
            D_86807C9C = D_86807C98;
        }
        break;
    case 2:
        D_86807C60 = 13.0f * D_86807CC8;
        if (D_86807C98 == D_86807C94) {
            D_86807C9C = 5.1f;
        } else {
            D_86807C9C = D_86807C98;
        }
        break;
    case 3:
        D_86807C60 = 10.0f * D_86807CC8;
        if (D_86807C98 == D_86807C94) {
            D_86807C9C = 5.4f;
        } else {
            D_86807C9C = D_86807C98;
        }
        break;
    case 4:
        D_86807C60 = 8.0f * D_86807CC8;
        if (D_86807C98 == D_86807C94) {
            D_86807C9C = 8.0f;
        } else {
            D_86807C9C = D_86807C98;
        }
        break;
    }
    D_86807C9C *= D_86807CC8;
}

// Transform fields shared by the 360-byte models in both per-group pools.
typedef struct Fragment56PointModelView {
    u8 unk_000[20];
    s32 unk_014;
    u8 unk_018[6];
    s16 rotation[3];
    f32 position[3];
    f32 scale[3];
    u8 unk_03C[300];
} Fragment56PointModelView;

typedef struct Fragment56PointRecord {
    s32 state;
    f32 angle;
    s16 spin;
    s16 unk_00A;
    f32 apex_time;
    f32 elapsed;
    f32 unk_014;
} Fragment56PointRecord;

typedef struct Fragment56PointGroupView {
    u8 unk_000[16];
    s32 mode;
    u8 unk_014[56];
    s32 pool_cursor;
    s32 active[40];
    u8 unk_0F0[52];
} Fragment56PointGroupView;

extern Fragment56PointModelView D_86817308[4][20];
extern Fragment56PointModelView D_8681EBF8[4][40];
extern Fragment56PointRecord D_8682E618[4][20];
extern Fragment56PointGroupView D_8682EE18[4];
extern u8 D_8682CD18[];
extern s32 D_86807C40;
extern s32 D_86807CC4;
extern s32 D_86807C44;
extern s32 D_86807C3C;
extern s32 D_86807C48;
extern s32 D_86807A74[];
extern s32 D_868084E8;
extern u8 D_868085E8[];
extern u32 func_8003570C(void);
extern void func_87F03B8C(void *);
extern void func_86800594(void);
// Resets four group headers, their word arrays and their 20- and 40-entry pools.
void Fragment56_InitStateRecords(void) {
    u8 *group_state;
    s32 entry_index;
    s32 group_index;
    s32 word_index;

    func_86800A7C();
    for (group_index = 0, group_state = ((u8 *)D_8682EE18); group_index < 4; group_index++, group_state += 292) {
        *(s32 *)(group_state + 0) = 1;
        *(s32 *)(group_state + 4) = 0;
        *(s32 *)(group_state + 16) = 1;
        *(s32 *)(group_state + 20) = 0;
        *(s32 *)(group_state + 24) = 0;
        *(s32 *)(group_state + 28) = 0;
        *(s32 *)(group_state + 32) = 0;
        *(s32 *)(group_state + 36) = -1;
        *(s32 *)(group_state + 48) = 0;
        *(s32 *)(group_state + 40) = 1;
        *(s32 *)(group_state + 56) = 0;
        *(s32 *)(group_state + 52) = 0;
        *(s32 *)(group_state + 64) = 0;
        *(s32 *)(group_state + 68) = -1;
        *(s32 *)(group_state + 72) = 0;
        *(s32 *)(group_state + 76) = 0;

        word_index = 0;
        while (word_index < 40) {
            ((s32 *)(((u8 *)D_8682EE18) + group_index * 292 + 80))[word_index] = 0;
            word_index++;
        }

        for (entry_index = 0; entry_index < 20; entry_index++) {
            *(s16 *)(((u8 *)D_8682E618) + group_index * 480 + entry_index * 24 + 8) = 0;
            *(f32 *)(((u8 *)D_8682E618) + group_index * 480 + entry_index * 24 + 4) = 0.0f;
            *(f32 *)(((u8 *)D_8682E618) + group_index * 480 + entry_index * 24 + 12) = (f32)(func_8003570C() % 3U + 1U);
            *(f32 *)(((u8 *)D_8682E618) + group_index * 480 + entry_index * 24 + 16) = 0.0f;
            *(f32 *)(((u8 *)D_8682E618) + group_index * 480 + entry_index * 24 + 20) = 0.0f;
            *(s32 *)(((u8 *)D_8682E618) + group_index * 480 + entry_index * 24 + 0) = 0;
        }

        for (entry_index = 0; entry_index < 40; entry_index++) {
            *(s16 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 0) = 0;
            *(s32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 4) = -1;
            *(s32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 8) = 0;
            *(s32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 12) = 500;
            *(s32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 20) = 0;
            *(f32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 32) = 0.0f;
            *(s32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 16) = 0;
            *(f32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 36) = 0.0f;
            *(s32 *)(D_8682CD18 + group_index * 1600 + entry_index * 40 + 28) = 0;
        }
    }

    D_86807C3C = D_86807CC4 + D_86807C40 - 1;
    D_86807C48 = D_86807C44;
    *(s32 *)((u8 *)&D_8682F2A8 + 36) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 16) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 12) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 20) = 1;
    *(s32 *)((u8 *)&D_8682F2A8 + 24) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 40) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 28) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 44) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 48) = 1;
    *(s32 *)((u8 *)&D_8682F2A8 + 52) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 68) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 72) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 80) = 1;
    *(s32 *)((u8 *)&D_8682F2A8 + 64) = 0;
    *(s32 *)((u8 *)&D_8682F2A8 + 32) = D_86807C40;
    if (*(s32 *)((u8 *)&D_8682F2A8 + 76) != 0) {
        *(s32 *)((u8 *)&D_8682F2A8 + 60) = 3;
    }
    Fragment56_UpdateScaledParameters();
    D_868084E8 = D_86807A74[*(s32 *)((u8 *)&D_8682F2A8 + 36)];
    func_87F03B8C(D_868085E8);
    func_86800508();
    func_86800594();
}

extern u32 func_8003570C(void);
extern u8 D_868086C8[];
extern u8 D_868085C0[];
extern u8 *func_87F03884(u8 *, s32, void *, f32, f32, f32, s16, f32, s32);
void func_8680105C(s32 arg0) {
    volatile s32 pad[8]; // FAKE: unused stack space; original live locals remain unrecovered.
    u32 rand1;
    u32 rand0;
    u8 *ptr;
    u32 scale_multiplier = 4;
    f32 zero;
    rand0 = func_8003570C();
    rand1 = func_8003570C();
    func_8003570C();
    ptr = D_868086C8 + arg0 * 0x168;
    zero = 0.0f;
    func_87F03884(D_868085C0, 0, ptr, 20.0f, *(f32 *)(ptr + 0xB0) - *(f32 *)(ptr + 0x28) + 30.0f, zero, (rand0 % 31) * 0x200, ((f32)rand1 / 4294967296.0f) * 1.8f * (f32)scale_multiplier, 1);
}

extern f32 __cosf(f32);
extern f32 __sinf(f32);
extern void func_80027A28(u16, u8);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern s32 D_86807C4C;
extern s32 D_86807CB8;
extern f32 D_86807CC0;
extern s32 D_86807DF0;
extern f32 D_86807DF4;
extern void *D_8682CD14;

// Advances parabolic model paths and recycles models below the group height threshold.
void Fragment56_UpdateBallisticModels(s32 group_index) {
    f32 elapsed;
    f32 apex_time;
    f32 angle;
    f32 height;
    f32 scale;
    s16 spin;
    s32 base_height;
    s32 slot;
    s32 entry_index;
    s32 sound_played;
    Fragment56PointGroupView *group_state;

    sound_played = 0;
    for (entry_index = 0; entry_index < 20; entry_index++) {
        if (D_8682E618[group_index][entry_index].state == 1) {
            D_8682E618[group_index][entry_index].elapsed = (f32)((f64)D_8682E618[group_index][entry_index].elapsed + 0.5 * (f64)D_86807DF4);
            spin = D_8682E618[group_index][entry_index].spin;
            D_86817308[group_index][entry_index].rotation[0] = D_86817308[group_index][entry_index].rotation[0] + spin;
            D_86817308[group_index][entry_index].rotation[2] = D_86817308[group_index][entry_index].rotation[2] + spin;
            elapsed = D_8682E618[group_index][entry_index].elapsed;
            apex_time = D_8682E618[group_index][entry_index].apex_time;
            angle = D_8682E618[group_index][entry_index].angle;
            group_state = &D_8682EE18[group_index];
            D_86817308[group_index][entry_index].position[0] += (f64)(__cosf(angle) * elapsed) / 3.0;
            D_86817308[group_index][entry_index].position[2] += (f64)(__sinf(angle) * elapsed) * 0.5f;
            base_height = D_86807C4C;
            D_86817308[group_index][entry_index].position[1] =
                (f32)((f64)base_height
                    + (4.9 * (f64)apex_time * (f64)apex_time)
                    - (4.9 * (f64)(elapsed - apex_time) * (f64)(elapsed - apex_time)));
            if (D_8682EE18[group_index].mode == 14) {
                height =
                    (f32)((f64)(base_height + 60)
                        + (4.9 * (f64)apex_time * (f64)apex_time)
                        - (4.9 * (f64)(elapsed - apex_time) * (f64)(elapsed - apex_time)));
                D_86817308[group_index][entry_index].position[1] = height;
                if (height < (f32)(base_height - D_86807DF0)) {
                    func_8003F1DC(&D_86817308[group_index][entry_index]);
                    if (sound_played == 0) {
                        func_80027A28(32517, (u8)group_index);
                        sound_played = 1;
                    }
                    slot = group_state->pool_cursor;
                    group_state->active[slot] = 1;
                    func_8003F114((u8 *)&D_8681EBF8[group_index][slot], 0, -1, D_8682CD14);
                    D_8681EBF8[group_index][slot].position[2] = D_86817308[group_index][entry_index].position[2];
                    D_8681EBF8[group_index][slot].unk_014 = 0;
                    D_8681EBF8[group_index][slot].position[0] = D_86817308[group_index][entry_index].position[0];
                    D_8681EBF8[group_index][slot].position[1] = (f32)D_86807CB8;
                    scale = D_86807CC0;
                    D_8681EBF8[group_index][slot].scale[2] = scale;
                    D_8681EBF8[group_index][slot].scale[1] = scale;
                    D_8681EBF8[group_index][slot].scale[0] = scale;
                    group_state->pool_cursor++;
                    if (group_state->pool_cursor >= 40) {
                        group_state->pool_cursor = 0;
                    }
                    D_8682E618[group_index][entry_index].state = 0;
                }
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_868014C0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86801E8C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86802740.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86802EE8.s")

extern s32 D_868074C0;
extern s32 D_868074C4;
extern s32 D_86807EE4;
extern s32 D_86807EE8;
extern s32 D_86807EEC;
extern s32 D_86807EF4;
extern s32 D_86807EF8;
extern s32 D_86807F04;
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
void func_8680349C(s32 arg0) {
    s32 sp2C;
    s32 temp_lo;
    s32 temp_v0;
    if (arg0 == 0x64) {
        func_8004D19C(D_86807EE4, 0x1A, func_8004C990(0x194, D_868074C4), 0, 0);
        temp_v0 = func_8004C990(0x194, D_868074C0);
        func_8004D19C(D_86807EE8, 0x1A, temp_v0, 0, 0);
        func_8004D19C(D_86807EEC, 0x1A, temp_v0, 0, 0);
        return;
    }
    if (arg0 >= 0xA) {
        temp_lo = arg0 / 10;
        sp2C = temp_lo;
        func_8004D19C(D_86807EF4, 0x1A, func_8004C990(0x194, (&D_868074C0)[temp_lo]), 0, 0);
        temp_v0 = arg0 - (sp2C * 0xA);
        func_8004D19C(D_86807EF8, 0x1A,
                      func_8004C990(0x194, (&D_868074C0)[temp_v0]), 0, 0);
        return;
    }
    func_8004D19C(D_86807F04, 0x1A, func_8004C990(0x194, (&D_868074C0)[arg0]), 0, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86803618.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_868039F8.s")

s32 func_87F00930();
extern void func_87F01D44();

void func_86803EA4(void) {
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
}

extern Gfx *D_800D0510;
extern void func_800088DC(void);
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern void func_800468A0(s32);
extern s32 D_8682F2B4;
extern s32 D_8682F2A8;
extern s32 D_8682F2B8;
extern s32 D_868086C4;
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C6B8(s32);
extern s32 D_86808558;
extern void *D_86808590;
extern u8 D_868084F0[];
extern u8 D_86808630[];
extern void func_87F07FE8(void *);
extern void func_87F0A5BC(u8 *);
extern void func_87F022F0(void);
extern void func_87F0C88C(u8 *);
extern void func_80008648(void);
void func_868039F8(void);
void Fragment56_UpdateModelAnimations(void);
void func_86802EE8(void);
extern void func_86803EA4(void);
extern s32 D_868086C0[];
void func_86803ED8(void) {
    func_800088DC();
    func_8000766C(&D_800D0510, 0, 0, 0x140, 0xF0);
    func_800468A0(D_868086C0[0]);
    if (D_8682F2B4 == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    if (D_8682F2A8 != 1) {
        func_8003C6B8(D_868086C4);
    }
    switch (D_8682F2A8) {
    case 9:
    case 12:
        if (D_8682F2B8 == 1) {
            func_87F07FE8(&D_86808558);
        } else {
            func_868039F8();
        }
        if (D_8682F2B8 == 2) {
            Fragment56_UpdateModelAnimations();
            func_868039F8();
            func_87F022F0();
        }
        if (D_8682F2B8 == 3) {
            func_868039F8();
            func_86803EA4();
        }
        if (D_8682F2B8 == 0) {
            Fragment56_UpdateModelAnimations();
        }
        break;
    case 0:
    case 3:
    case 4:
        if (*(u8 *)((u8 *)D_86808590 + 0x2180) != 4) {
            func_87F07FE8(&D_86808558);
        }
        break;
    case 8:
        func_86802EE8();
    case 2:
    case 5:
        func_868039F8();
        func_86803EA4();
        break;
    case 1:
        func_868039F8();
        func_8003C6B8(D_868086C4);
        func_86803EA4();
        break;
    case 7:
        func_868039F8();
        func_87F0A5BC(D_868084F0);
        break;
    case 6:
        func_868039F8();
        func_87F022F0();
        break;
    }
    if (*(u8 *)((u8 *)D_86808590 + 0x2180) == 4) {
        func_87F0C88C(D_86808630);
    }
    func_80008648();
}

extern s32 D_86807C7C;
extern u8 D_8682CD20[];
s32 func_868040EC(s32 arg0, s32 arg1) {
    s32 value;
    s32 result = -1;
    if (D_86807C7C == 0) {
        return 1;
    }
    value = *(s32 *)(&((u8 *)D_8682EE18)[arg0 * 0x124] + 0x1C);
    switch (value) {
    case 0:
        break;
    case 2:
        if (*(s32 *)&D_8682CD20[(arg0 * 0x640) + (arg1 * 0x28)] == 1) { result = 1; *(s32 *)(&((u8 *)D_8682EE18)[arg0 * 0x124] + 0x10) = 1; }
        break;
    case 1:
        if (*(s32 *)&D_8682CD20[(arg0 * 0x640) + (arg1 * 0x28)] == 3) { result = 1; *(s32 *)(&((u8 *)D_8682EE18)[arg0 * 0x124] + 0x10) = 3; }
        break;
    case 3:
        if (*(s32 *)&D_8682CD20[(arg0 * 0x640) + (arg1 * 0x28)] == 2) { result = 1; *(s32 *)(&((u8 *)D_8682EE18)[arg0 * 0x124] + 0x10) = 2; }
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_8680422C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_868044D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_868048C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86804C5C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86804EE0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_8680537C.s")

extern s32 D_8682F2B4;
extern s32 D_86807C3C;
extern s32 D_86807C88;
extern s32 D_86807C48;
extern s32 D_868084E8;
extern u8 D_8682CD18[];
extern void func_8680537C(void);
extern void func_868044D4(void);
extern void func_868048C8(void);
extern void func_86804C5C(void);
extern void func_800279C4(u16);
void Fragment56_UpdatePoolCompletion(void) {
    static s32 drain_counter = 0;
    s32 group_index;
    s32 entry_index;
    s32 all_empty;
    if (D_8682F2B4 != 1) {
        D_86807C3C--;
        func_8680537C();
        func_868044D4();
        func_868048C8();
        if (D_86807C88 == 1) {
            if (D_86807C48 <= 0) {
                all_empty = 1;
                for (group_index = 0; group_index < 4; group_index++) {
                    for (entry_index = 0; entry_index < 40; entry_index++) {
                        if (*(s32 *)(D_8682CD18 + group_index * 0x640 + entry_index * 0x28 + 4) != -1) {
                            all_empty = 0;
                        }
                    }
                    for (entry_index = 0; entry_index != 20; entry_index++) {
                        if (*(s32 *)(((u8 *)D_8682E618) + group_index * 0x1E0 + entry_index * 0x18) == 1) {
                            all_empty = 0;
                        }
                    }
                }
                if (all_empty == 1) {
                    drain_counter++;
                }
                if (drain_counter == 5) {
                    func_800279C4(0xCF06);
                }
                if (drain_counter >= 31) {
                    func_86804C5C();
                }
            } else {
                drain_counter = 0;
            }
        } else if (D_868084E8 == 0) {
            all_empty = 1;
            for (group_index = 0; group_index < 4; group_index++) {
                for (entry_index = 0; entry_index < 40; entry_index++) {
                    if (*(s32 *)(D_8682CD18 + group_index * 0x640 + entry_index * 0x28 + 4) != -1) {
                        all_empty = 0;
                    }
                }
                for (entry_index = 0; entry_index != 20; entry_index++) {
                    if (*(s32 *)(((u8 *)D_8682E618) + group_index * 0x1E0 + entry_index * 0x18) == 1) {
                        all_empty = 0;
                    }
                }
            }
            if (all_empty == 1) {
                func_86804C5C();
            }
        }
    }
}

extern u8 D_86809208[];
extern u8 D_86808C8C[];
extern void *D_8682F308;
extern void func_87F06430(f32 *, s32);
extern void func_819006A0(void *);
extern void Fragment56_InitStateRecords(void);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern void func_8003F210(void *, s32);
extern u8 D_868086C8[];
extern u8 D_86808C68[];
extern s32 D_8682CD00[];
void Fragment56_InitModelGroups(void) {
    s32 group_index;
    s32 model_index;
    f32 scale = 0.045f;
    f32 height = 56.0f;
    for (group_index = 0; group_index < 4; group_index++) {
        for (model_index = 0; model_index != 40; model_index++) {
            func_8003F1DC(((u8 *)D_8681EBF8) + group_index * 0x3840 + model_index * 0x168);
        }
        for (model_index = 0; model_index < 40; model_index++) {
            func_8003F1DC(D_86809208 + group_index * 0x3840 + model_index * 0x168);
        }
        for (model_index = 0; model_index != 20; model_index++) {
            func_8003F1DC(((u8 *)D_86817308) + group_index * 0x1C20 + model_index * 0x168);
        }
        func_8003F1DC(D_868086C8 + group_index * 0x168);
        func_8003F114(D_86808C68 + group_index * 0x168, 0, -1, (void *)D_8682CD00[group_index]);
        func_8003F210(D_86808C68 + group_index * 0x168, 0);
        ModelAnim_SetFrame(D_86808C68 + group_index * 0x168, (s16)(guRandom() % 24));
        func_87F06430((f32 *)(D_86808C8C + group_index * 0x168), group_index);
        *(f32 *)(D_86808C68 + group_index * 0x168 + 0x38) = scale;
        *(f32 *)(D_86808C68 + group_index * 0x168 + 0x34) = scale;
        *(f32 *)(D_86808C68 + group_index * 0x168 + 0x30) = scale;
        *(f32 *)(D_86808C68 + group_index * 0x168 + 0x28) = height;
    }
    func_819006A0(D_8682F308);
    Fragment56_InitStateRecords();
}

extern s32 D_8682F2A8;
extern s32 func_87F02104(void);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
void func_86805C88(void) {
    s32 temp_v0;
    temp_v0 = func_87F02104();
    switch (temp_v0) {
    case 1:
        *(s32 *)((u8 *)&D_8682F2A8 + 0x10) = 2;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x0) = 0xC;
        StageContext_SetClearColor(1);
        StageFade_StartFromTransparent(0xA);
        return;
    case 2:
        *(s32 *)((u8 *)&D_8682F2A8 + 0x8) = 0;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x0) = 9;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x10) = 2;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    case 3:
        *(s32 *)((u8 *)&D_8682F2A8 + 0x8) = 1;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x0) = 9;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x10) = 2;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    }
}

extern void *D_86808590;
extern s32 D_8682F2A8;
void func_86805D50(void) {
    if (StageContext_GetFadeMode() == 0) {
        if ((*(u8 *)((u8 *)(D_86808590) + (0x2180))) == 4) {
            StageFade_StartFromOpaque(0x14);
            func_87F00688();
            D_8682F2A8 = 5;
            return;
        }
        D_8682F2A8 = 3;
    }
}

typedef struct Fragment56MotionRecord {
    s32 state;
    s32 variant;
    s32 ticks;
    f32 horizontal_divisor;
    f32 vertical_multiplier;
    f32 initial_x;
    f32 initial_y;
    f32 horizontal_offset;
} Fragment56MotionRecord;

typedef struct Fragment56MovingModel {
    u8 unk_000[36];
    f32 position[3];
    f32 scale[3];
    u8 unk_03C[300];
} Fragment56MovingModel;

extern Fragment56MotionRecord D_8682ED98[4];
extern Fragment56MovingModel D_8681E388[4];
extern f32 D_86808050[4];
extern f32 D_8682F300;
extern void *D_8682CCFC;
extern void *D_8682CD10;
extern u32 func_8003570C(void);
extern void func_8003F114(u8 *, s16, s16, void *);
void Fragment56_ResetMovingModels(void) {
    u8 *moving_model;
    s32 random_value;
    s32 sign;
    s32 variant_offset;
    s32 group_index;
    f32 position_scale;
    f32 travel_distance;
    for (group_index = 0, moving_model = ((u8 *)D_8681E388); group_index < 4; group_index++) {
        variant_offset = 0;
        random_value = func_8003570C() % 101;
        sign = random_value % 2 ? 1 : -1;
        *(s32 *)(((u8 *)D_8682ED98) + group_index * 32 + 8) = 0;
        *(f32 *)(moving_model + 0x2C) = 1000.0f;
        *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x1C) = (f32)(sign * random_value * 2);
        *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x18) = (f32)((sign * random_value) / 4);
        *(f32 *)(moving_model + 0x28) = *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x18);
        *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x14) = (f32)(-sign * random_value * 5);
        *(f32 *)(moving_model + 0x24) = *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x14);
        random_value = func_8003570C() % 51;
        if (random_value < 10) {
            *(s32 *)(((u8 *)D_8682ED98) + group_index * 32) = 1;
            *(s32 *)(((u8 *)D_8682ED98) + group_index * 32 + 4) = 1;
            func_8003F114(moving_model, 0, -1, D_8682CCFC);
            *(f32 *)(moving_model + 0x38) = 1.1f;
            *(f32 *)(moving_model + 0x34) = 1.1f;
            *(f32 *)(moving_model + 0x30) = 1.1f;
        } else {
            *(s32 *)(((u8 *)D_8682ED98) + group_index * 32) = 0;
            *(s32 *)(((u8 *)D_8682ED98) + group_index * 32 + 4) = 1;
            if (random_value >= 21) {
                *(s32 *)(((u8 *)D_8682ED98) + group_index * 32 + 4) = 3;
                variant_offset = -5;
            }
            if (random_value >= 36) {
                *(s32 *)(((u8 *)D_8682ED98) + group_index * 32 + 4) = 2;
                variant_offset = 5;
            }
            func_8003F114(moving_model, 0, -1, D_8682CD10);
            *(f32 *)(moving_model + 0x38) = 0.05f;
            *(f32 *)(moving_model + 0x34) = 0.05f;
            *(f32 *)(moving_model + 0x30) = 0.05f;
        }
        travel_distance = 1000.0f;
        travel_distance += *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x1C);
        position_scale = D_8682F300;
        *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0xC) = travel_distance / (D_86808050[group_index] + (f32)variant_offset * position_scale);
        *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x10) = -((56.0f + 7.0f * position_scale) - *(f32 *)(((u8 *)D_8682ED98) + group_index * 32 + 0x18)) / travel_distance;
        moving_model += 360;
    }
}

extern u8 D_868085E8[];
extern u8 D_86808C68[];
extern f32 D_8682F30C;
extern s32 D_8682F310;
extern u32 func_8003570C(void);
extern u8 *func_87F03884(u8 *, s32, void *, f32, f32, f32, s16, f32, s32);
void func_86806044(s32 arg0) {
    volatile s32 pad[3]; // FAKE: unused stack space; original live locals remain unrecovered.
    u32 rand1;
    u32 rand0;
    u32 rand2;
    u8 *ptr;
    D_8682F310 = 1;
    D_8682F30C = 1.2f;
    rand0 = func_8003570C();
    rand1 = func_8003570C();
    rand2 = func_8003570C();
    ptr = D_86808C68 + arg0 * 0x168;
    func_87F03884(D_868085E8, 0, ptr, 0.0f, *(f32 *)(ptr + 0xB0) - 20.0f, -20.0f, (rand0 % 31) * 0x200, ((f32)rand1 / 4294967296.0f) * 1.5f * D_8682F30C, (rand2 % (D_8682F310 + 1)) + 1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86806180.s")

extern s32 D_86807CB4;
extern s32 D_86808558;
extern s32 func_87F08208(void *);
extern void Fragment56_ResetMovingModels(void);
extern void func_800225C4(s32);
extern void func_800226C0(s32);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void Audio_PlayDefaultSound(s32);
extern s32 D_8682F2A8;
void func_868063CC(void) {
    s32 temp_v0;
    if (++D_86807CB4 >= 0x97) {
        D_86807CB4 = 0x32;
    }
    temp_v0 = func_87F08208(&D_86808558);
    switch (temp_v0) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        Fragment56_ResetMovingModels();
        D_8682F2A8 = 4;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        return;
    case 2:
        D_8682F2A8 = 9;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x10) = 1;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x8) = 0;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        func_800226C0(3);
        return;
    }
}

extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern void func_8003F210(void *, s32);
extern void func_86800A7C(void);
extern void func_86806180(void);
extern u8 D_868086C8[];
extern u8 D_86808C68[];
extern s32 D_8682CD00[];
extern s32 D_8682F2A8;

void func_8680649C(void) {
    s32 i;

    /* Fade-mode 1 intro: reset the 4 stage models (parallel arrays D_86808C68/
     * D_8681E388/D_868086C8 stride 0x168, s32 D_8682CD00, D_8682EE18 stride
     * 0x124), give each a random anim frame, then hand off to func_86800A7C,
     * start the fade and enter state D_8682F2A8 = 5. The cursors are IDO's
     * strength-reduced induction pointers from the indexed accesses; the loop
     * bound is the EE18 element count (D_8682F2A8 = D_8682EE18 + 4*0x124),
     * materialized by the IV transform. */
    if (StageContext_GetFadeMode() == 1) {
        i = 0;
        do {
            func_8003F1DC(&D_86808C68[i * 0x168]);
            func_8003F1DC(&((u8 *)D_8681E388)[i * 0x168]);
            func_8003F114(&D_868086C8[i * 0x168], 0, -1, D_8682CD00[i]);
            D_868086C8[i * 0x168 + 0xA0] = 0xFF;
            D_868086C8[i * 0x168 + 0xA1] = 0;
            D_868086C8[i * 0x168 + 0xA2] = 0;
            *(s32 *)(&((u8 *)D_8682EE18)[i * 0x124] + 0x10) = 1;
            func_8003F210(&D_868086C8[i * 0x168], 1);
            ModelAnim_SetFrame(&D_868086C8[i * 0x168], (s16)(guRandom() % 10));
            i++;
        } while (i != 4);
        func_86800A7C();
        StageFade_StartFromOpaque(0x14);
        func_87F00688();
        D_8682F2A8 = 5;
        return;
    }
    func_86806180();
}
extern s32 D_8682F2A8;
extern s32 func_87F01A40(void);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
void func_8680660C(void) {
    s32 temp_v0;
    *(s32 *)((u8 *)&D_8682F2A8 + 0xC) = 1;
    temp_v0 = func_87F01A40();
    switch (temp_v0) {
    case 0:
    case 2:
        *(s32 *)((u8 *)&D_8682F2A8 + 0xC) = 0;
        return;
    case 3:
        *(s32 *)((u8 *)&D_8682F2A8 + 0x8) = 0;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x0) = 9;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x10) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    case 4:
        *(s32 *)((u8 *)&D_8682F2A8 + 0x8) = 1;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x0) = 9;
        *(s32 *)((u8 *)&D_8682F2A8 + 0x10) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    }
}

extern s32 D_8682F2B4;
void func_868066B8(void) {
    if (D_8682F2B4 != 1) {
        if (func_87F006AC() == 1) {
            Audio_PlayDefaultSound(0x7F03);
        }
        if (func_87F006AC() == 2) {
            D_8682F2A8 = 2;
            Audio_PlayDefaultSound(0x7F04);
        }
    }
}

extern s32 D_86807C4C;
extern f32 D_86807C50;
extern f32 D_86807C54;
extern s32 D_86807C78;
extern f32 D_8682F2FC;
extern f32 D_8682F304;
extern u8 D_8681E928[];
extern void func_86800508(void);
extern u8 D_868086C8[];
void Fragment56_UpdateModelGridTransforms(void) {
    s32 row;
    s32 column;
    u8 *model;
    u8 *grid_model;
    f32 height;
    D_8682F2FC = (D_86807C54 / 0.17f) * (D_86807C50 / 0.17f);
    D_8682F304 = D_8682F2FC * 7.0 + D_86807C4C;
    height = D_86807C4C;
    for (row = 0; row < 4; row++) {
        model = D_868086C8 + row * 0x168;
        *(f32 *)(model + 0x30) = *(f32 *)(model + 0x34) = *(f32 *)(model + 0x38) = D_86807C50;
        *(f32 *)(model + 0x28) = height;
        *(f32 *)(model + 0x24) = (row * 16 - 24) * D_8682F2FC;
        for (column = 0; column < 20; column++) {
            grid_model = ((u8 *)D_86817308) + row * 0x1C20 + column * 0x168;
            *(f32 *)(grid_model + 0x30) = *(f32 *)(grid_model + 0x34) = *(f32 *)(grid_model + 0x38) = D_86807C50;
        }
    }
    *(f32 *)(D_8681E928 + 0x28) = D_8682F304;
    *(f32 *)(D_8681E928 + 0x190) = D_8682F304 - D_86807C78;
    func_86800508();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_8680686C.s")

extern s32 D_8680806C;
typedef struct { u8 pad[0x44]; u8 *value44; s32 value48; } Func3EC34;
extern s32 ModelAnim_IsFinished(Func3EC34 *);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern s32 ModelAnim_SetEventTrack(void *, s32);
extern void func_80027A28(u16, u8);
extern void func_8680422C(s32);
extern void Fragment56_UpdateBallisticModels(s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_8003F1DC(void *);
extern void func_8003F210(void *, s32);
extern u8 D_868086C8[];
void Fragment56_UpdateModelAnimations(void) {
    struct AnimState {
        u8 before_state[0x10];
        s32 state;
        u8 before_ticks[0x34];
        s32 ticks;
        u8 tail[0xD8];
    };
    struct AnimState *state;
    u8 *node;
    s32 model_index;
    s32 effect_index;
    for (state = (struct AnimState *)((u8 *)D_8682EE18), node = D_868086C8, model_index = 0; model_index < 4; model_index++, state++, node += 0x168) {
        state->ticks++;
        if (ModelAnim_IsFinished((Func3EC34 *)node)) {
            if (state->state == 15) {
                state->ticks = 49;
                ModelAnim_SetEventFrame(node, 49);
                ModelAnim_SetFrame(node, 49);
                ModelAnim_SetEventTrack(node, 1);
            }
            if (state->state == 14) {
                func_8003F210(node, 14);
                ModelAnim_SetFrame(node, 14);
                state->ticks = 14;
                node[0x1D] = 255;
            }
        }
        if (state->state == 14) {
            if (D_8680806C == (*(s32 *)(node + 0x48) >> 16)) {
                func_80027A28(0x7F00, (u8)model_index);
                for (effect_index = 0; effect_index < 40; effect_index++) {
                    func_8003F1DC(((u8 *)D_8681EBF8) + model_index * 0x3840 + effect_index * 0x168);
                }
                func_8680422C(model_index);
            }
            Fragment56_UpdateBallisticModels(model_index);
            if (state->ticks >= 70) {
                func_8003F210(node, 14);
                ModelAnim_SetFrame(node, 14);
                node[0x1D] = 255;
                state->ticks = 14;
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/56/fragment56_code/func_86806E94.s")

extern s32 func_86806E94(s32);
extern void *D_86808590;
extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern void func_8003F210(void *, s32);
extern void func_86800A7C(void);
extern void func_86803ED8(void);
extern u8 D_868086C8[];
extern u8 D_86808C68[];
extern s32 D_8682CD00[];
extern s32 D_8682F2A8;
void Fragment56_RunSceneLoop(void) {
    s32 i;
    if (*((u8 *)D_86808590 + 0x2180) == 4) {
        func_86800A7C();
        i = 0;
        do {
            func_8003F1DC(&D_86808C68[i * 0x168]);
            func_8003F1DC(&((u8 *)D_8681E388)[i * 0x168]);
            func_8003F114(&D_868086C8[i * 0x168], 0, -1, (void *)D_8682CD00[i]);
            *(s32 *)(&((u8 *)D_8682EE18)[i * 0x124] + 0x10) = 1;
            func_8003F210(&D_868086C8[i * 0x168], 1);
            ModelAnim_SetFrame(&D_868086C8[i * 0x168], (s16)(guRandom() % 10));
            i++;
        } while (i != 4);
    }
    func_800086A4(2);
    StageFade_StartFromOpaque(10);
    do {
        func_80064D28();
        func_86803ED8();
    } while (func_86806E94(D_8682F2A8) != 13);
}

extern s32 func_80001FF0(void);
extern void func_80027EE0(u16);
extern void main_pool_push_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32,s32,s32,s32,s32,s32);
extern void func_8004C09C(s32);
extern void func_8004C8C0(s32);
extern s32 func_87F08E3C(s32,s32);
extern s32 func_8004D690(s32);
extern void func_87F06EAC(s32,s32 *,void *);
extern void func_80047588(s32,s32);
extern u8 *Asset_LoadToSegment(s32,u8 *,u8 *,s32);
extern void func_87F00030(void);
extern void func_87F01F34(void *);
extern void func_86802740(void);
extern void func_80008514(s32);
extern void Fragment56_RunSceneLoop(void);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern void main_pool_pop_state(s32);
extern void func_87F0F480(void *);
extern s32 D_86807CC4;
extern f32 D_86807CC8;
extern s32 D_86808640;
extern s32 D_8680863C;
extern s32 D_86808560;
extern s32 D_86808510;
extern s32 D_8682F2B0;
extern u8 D_1000000;
extern u8 D_446E30[];
extern u8 D_447D00[];
extern s32 func_8004C990(s32, s32);
extern s32 D_86808558;
extern void * D_86808590;
extern s32 D_868086C0[];
s32 func_8680729C(s32 arg0, void *arg1) {
    s32 sp24;
    if (func_80001FF0() == 0x3C) { D_86807CC4 = 0x1E; D_86807CC8 = 1.0f; }
    else { D_86807CC4 = 0x19; D_86807CC8 = 1.4f; }
    D_86808590 = arg1;
    if (*(u8 *)((u8 *)D_86808590 + 0x2180) == 4) func_80027EE0(0xFFF);
    main_pool_push_state(0x4D523034);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    func_8004C09C(0x127);
    func_8004C8C0(0xE3); func_8004C8C0(0x1B2); func_8004C8C0(0x1AD); func_8004C8C0(0x194); func_8004C8C0(0x98);
    D_86808640 = func_87F08E3C(func_8004C990(0xE3, 0), 0xF000000);
    D_8680863C = func_87F08E3C(func_8004C990(0x98, 0), 0xF000000);
    D_868086C0[0] = func_8004D690(0x13);
    func_87F06EAC(0x6E, &D_86808558, D_86808590);
    func_80047588((D_86808560 | 5) | D_86808510, 0);
    Asset_LoadToSegment((((u32)&D_1000000 & 0x0F000000) >> 24), &D_446E30, D_447D00, 0);
    func_87F00030(); func_87F01F34(D_86808590); func_86802740(); func_80008514(sp24); Fragment56_RunSceneLoop();
    func_80008574(); func_80047610(); func_8004C398(); Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D523034); func_87F0F480(D_86808590); func_80027EE0(0xFFE);
    return D_8682F2B0;
}
#endif
