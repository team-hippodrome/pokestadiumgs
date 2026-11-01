#include "global.h"
#include "controller.h"


#ifdef VERSION_US
s32 func_83400020(s32 arg0, s32 arg1) {
    return arg0 + arg1 / 2;
}

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
} Fragment58State;
extern Fragment58State D_83404888;
extern Fragment58State D_83403DCC;
extern s32 D_83403D68[];
extern s32 D_83403E08[];
extern s32 D_83404190;
void func_83400038(s32 arg0) {
    s32 temp_v0;
    if (arg0 == 3) {
        D_83404888.unk24 = 0xA;
        D_83404888.unk28 = 1;
    } else {
        D_83404190 = arg0;
        D_83404888.unk34 = -1;
    }
    D_83404888.unk20 = 0;
    temp_v0 = D_83404190 * 4;
    if (D_83403D68[D_83404190] == 4) {
        D_83404888 = D_83403DCC;
        D_83404888.unk18 = 1;
    }
    D_83404888.unk0C = D_83403E08[D_83404190];
    D_83404888.unk04 = func_83400020(D_83404888.unk0C, D_83404888.unk14);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_8340010C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_834006A8.s")

// Fragment state record at D_83404188 (only the fields C code here reads are named).
typedef struct {
    /* 0x00 */ s32 state;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8 unk_0C[0x8];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ u8 unk_1C[0x18];
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ u8 unk_38[0x40];
    /* 0x78 */ u8 colorA[4];
    /* 0x7C */ u8 unk_7C[0x10];
    /* 0x8C */ u8 colorB[4];
} Fragment58State188;
extern u8 *D_80094908;
extern void func_80037120(void *, void *, f32 *, s16 *, s16 *);
extern Fragment58State188 D_83404188;
s32 func_83400A64(s32 arg0, u8 *arg1) {
    s32 i;
    u8 *dst = arg1;
    f32 distance;
    s16 angleX;
    s16 angleY;

    if (arg0 == 2) {
        for (i = 0; i < 3; i++) {
            dst[0x18 + i] = D_83404188.colorA[i];
        }
        dst[0x1B] = D_83404188.colorA[3];
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &distance, &angleX, &angleY);
        *(s16 *)(dst + 0x1C) = angleX + 0x2000;
        *(s16 *)(dst + 0x1E) = angleY;
    }
    return 0;
}

s32 func_83400AFC(s32 arg0, u8 *arg1) {
    s32 i;
    u8 *dst = arg1;
    f32 distance;
    s16 angleX;
    s16 angleY;

    if (arg0 == 2) {
        for (i = 0; i < 3; i++) {
            dst[0x18 + i] = D_83404188.colorB[i];
        }
        dst[0x1B] = D_83404188.colorB[3];
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &distance, &angleX, &angleY);
        *(s16 *)(dst + 0x1C) = -0x2000 - angleX;
        *(s16 *)(dst + 0x1E) = angleY;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_83400B98.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_83400EA4.s")

/* mkdraft:func_8340135C begin */
extern f32 D_83403F18;

// Moves the state's 0x08/0x0C position inward by the shared offset in D_83403F18: x by
// the offset, the other axis by the offset scaled by unk14/unk10, with the applied
// fraction of the half span in unk38. unk1C caches the offset's progress: -1 unstarted
// (reset to 0 here), 0 in progress, 1 once the offset has clamped to half of unk10.
// func_8340156C, the only caller, passes &D_83404888, so arg0 is a Fragment58State
// (typedef earlier in src/fragments/58/fragment58_code.c); unk38 holds a float although
// that struct declares its word s32.
// D_83403F18 is initialised to .float 32 in asm/us/data/fragments/58/fragment58_data.data.s


void func_8340135C(Fragment58State *arg0) {
    f32 *offset_accum = &D_83403F18;
    f32 half_span;
    f32 offset;
    s32 new_x;
    s32 x;
    s32 span;
    f32 ratio;
    s32 state;
    s32 stateClamped;

    stateClamped = 1;
    state = arg0->unk1C;
    if (state == -1) {
        // FAKE: the four writes must share one statement expression; as separate
        // statements the reset schedules differently (diff score 60).
        arg0->unk1C = state = 0, offset = 8.0f, *offset_accum = offset;
        // FAKE: empty test that emits nothing; its extra use of offset in uopt's FPR
        // walk is what keeps the accumulator in f0 (diff score 190 without it).
        if (offset) {
        }
    }
    offset = *offset_accum;
    if (stateClamped != state) {
        // int 8, not 8.0f: the reset's 0x41000000 and this one stay separate constant
        // webs only when the two expressions have different types (8.0f here: score 885).
        offset = offset + 8;
        span = arg0->unk10;
        half_span = (f32) (span / 2);
        if (half_span < offset) {
            offset = half_span;
            arg0->unk1C = stateClamped;
        }
        x = arg0->unk00;
        new_x = (s32) ((f32) x - offset);
        ratio = (f32) arg0->unk14 / (f32) span;
        arg0->unk08 = new_x;
        arg0->unk0C = (s32) ((f32) arg0->unk04 - offset * ratio);
        *(f32 *)&arg0->unk38 = (f32) (x - new_x) / half_span;
        *offset_accum = offset;
    }
}
/* mkdraft:func_8340135C end */

/* mkdraft:func_83401454 begin */
extern f32 D_83403F20;

// Moves the state's 0x08/0x0C position back out of the transition offset shared through
// D_83403F20: x by the offset, the other axis by the offset scaled by unk14/unk10, and
// the applied fraction of the half span into unk38. func_8340135C grows that kind of
// offset by 8 per call from 8; this function starts the offset at half of unk10 and
// takes 16 off per call, clamped to a 12.0f floor. The clamp clears unk18 and returns 1;
// unk1C == -1 resets the shared offset to the state's half span before the first step.
// func_8340156C is the only caller: it passes &D_83404888 here while D_834048A0 is -1
// and calls func_8340135C instead while that word is 1, so arg0 is a Fragment58State
// (typedef earlier in src/fragments/58/fragment58_code.c) and the two functions are the
// in and out halves of one transition. unk38 holds a float although that struct declares
// its word s32.
// D_83403F20 is initialised to .float 32 in asm/us/data/fragments/58/fragment58_data.data.s
// FAKE: local alias for D_83403F20; naming the global in each statement scores 98445.
// FAKE: the always-true block keeps uopt from hoisting the 12.0f clamp constant into
// the unk1C == -1 branch's delay slot (bne becomes bnel and the FP results move to
// ft0/fv0/fv1/ft1); diff score 530 without it.


s32 func_83401454(Fragment58State *arg0) {
    f32 *offset_accum = &D_83403F20;
    f32 offset;
    f32 ratio;
    s32 new_x;
    s32 x;
    s32 span;
    s32 state_clamped;

    if (1) {
        state_clamped = 1;
        if (arg0->unk1C == -1) {
            arg0->unk1C = 0;
            offset = (f32) (arg0->unk10 / 2);
            *offset_accum = offset;
        }
        offset = *offset_accum;
    }

    offset = offset - 16.0f;
    if (offset < 12.0f) {
        arg0->unk18 = 0;
        *offset_accum = 12.0f;
        return state_clamped;
    }

    span = arg0->unk10;
    x = arg0->unk00;
    new_x = (s32) ((f32) x - offset);
    ratio = ((f32) arg0->unk14) / ((f32) span);
    arg0->unk08 = new_x;
    arg0->unk0C = (s32) ((f32) arg0->unk04 - (offset * ratio));
    *((f32 *) (&arg0->unk38)) = ((f32) (x - new_x)) / ((f32) (span / 2));
    *offset_accum = offset;
    return 0;
}
/* mkdraft:func_83401454 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_8340156C.s")

extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void Font_EnableTwoCycleTexturing(void);
extern void Font_DisableTwoCycleTexturing(void);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800497E4(s32, s32, s32, s32);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800499EC(void);
extern s32 D_83404194;
extern f32 D_834048C4;
extern f32 D_834048C8;
extern f32 D_834048CC;
extern f32 D_834048D0;
extern f32 D_834048D4;
extern f32 D_834048D8;
extern f32 D_834048DC;
// Debug overlay: prints D_83404194 as the frame number and D_834048C4..DC as the
// camera's eye x/y/z, look-at x/y/z and fovy, per the format strings above
// (asm/us/data/fragments/58/fragment58_data.data.s).
void func_83401904(void) {
    func_800498C4();
    func_800496A4(1, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    func_800495F8(20, 20, 0, "frame:%d", D_83404194);
    func_800495F8(20, 30, 0, "cam posx:%0.1f", D_834048C4);
    func_800495F8(20, 40, 0, "cam posy:%0.1f", D_834048C8);
    func_800495F8(20, 50, 0, "cam posz:%0.1f", D_834048CC);
    func_800495F8(20, 60, 0, "cam latx:%0.1f", D_834048D0);
    func_800495F8(20, 70, 0, "cam laty:%0.1f", D_834048D4);
    func_800495F8(20, 80, 0, "cam latz:%0.1f", D_834048D8);
    func_800495F8(20, 90, 0, "cam fovy:%0.1f", D_834048DC);
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_83401AAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_83401E64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_834022F8.s")

extern void *D_800D0510;
extern Fragment58State188 D_83404188;
extern s32 D_834041A4;
extern s32 D_834041CC;
extern s32 D_83404248;
extern u8 D_83404170;
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(void *, u16);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(s32);
extern void func_834022F8(void);
extern void func_8340156C(void);
extern void func_83401AAC(void);
extern void func_87F0DFB4(void *);
extern void func_80008648(void);
void func_8340295C(void) {
    BgStage_DrawFrame();
    if (D_834041CC == 0) {
        GfxImage_FillCurrent(&D_800D0510, 1);
    }
    if (D_834041A4 == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(D_83404248);
    switch (D_83404188.state) {
    case 2:
        func_834022F8();
        break;
    case 6:
    default:
        break;
    }
    func_8340156C();
    if (D_834041A4 == 1) {
        func_83401AAC();
    }
    func_87F0DFB4(&D_83404170);
    func_80008648();
}

extern s32 D_834048B8;
extern void func_800226C0(s32);
extern s32 StageFade_StartFromTransparent(s32);
extern void func_83400038(s32 arg0);
void func_83402A24(void) {
    if (D_83404188.unk_08 == 2) {
        if ((D_80087200->buttonsPressed & A_BUTTON) && D_834048B8 == 0xFF) {
            func_800226C0(2);
            func_83400038(3);
            D_83404188.state = 7;
            D_83404188.unk_04 = 8;
            D_83404188.unk_34 = 1;
            StageFade_StartFromTransparent(20);
        }
    } else if ((D_80087200->buttonsPressed & A_BUTTON) && D_834048B8 == 0xFF) {
        func_800226C0(2);
        func_83400038(++D_83404188.unk_08);
    }
}

void func_83402B08(void) {
}

extern f32 func_8004B888(s32);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F2C4(s32, s32, s32);
extern void func_8003F3BC(void *, s32);
extern void *D_83404164;
extern s32 D_834041B0;
extern s32 D_8340424C;
extern u8 D_83404250;
extern u8 D_83404688;
extern s32 D_834047F0;
extern s16 D_834047F2;
extern s32 D_83404800;

/* uopt colors the 300.0f constant before the 0x24/0x28 read-backs; the retail
 * allocation rotates the three fpu temps {f4, f6, f8} by one slot (300.0f in
 * f6, 0x28 read in f8, 0x24 read in f4). The six words below only rewrite the
 * ft register fields; the tail's f4/f6 reuse and the 0x53 block (f10/f16/f18)
 * already match. */
#pragma REWRITE_FUNCTION_WORD(func_83402B10, 0x90, 0x44812000, 0x44813000)
#pragma REWRITE_FUNCTION_WORD(func_83402B10, 0x9C, 0xE6040028, 0xE6060028)
#pragma REWRITE_FUNCTION_WORD(func_83402B10, 0xA0, 0xC6060028, 0xC6080028)
#pragma REWRITE_FUNCTION_WORD(func_83402B10, 0xA8, 0xC6080024, 0xC6040024)
#pragma REWRITE_FUNCTION_WORD(func_83402B10, 0xC0, 0xE6260028, 0xE6280028)
#pragma REWRITE_FUNCTION_WORD(func_83402B10, 0xC4, 0xE6280024, 0xE6240024)

/* mkdraft:func_83402B10 begin */
void func_83402B10(void) {
    f32 temp_fv0;

    D_834041B0 = 0;
    func_8003F1DC(&D_83404250);
    func_8003F114(&D_83404250, 0, D_834047F2,
                  **(s32 **)((u8 *)*(void **)((u8 *)D_8340424C + 0x38) + 8));
    func_8003F114(&D_83404688, 0, -1, (void *)D_83404800);
    *(u8 *)(&D_83404688 + 0x1D) = 0xFF;
    temp_fv0 = func_8004B888(*(s16 *)((u8 *)D_83404164 + 0x658));
    *(f32 *)(&D_83404688 + 0x2C) = 0.0f;
    *(f32 *)(&D_83404688 + 0x28) = 300.0f;
    *(f32 *)(&D_83404688 + 0x24) = *(f32 *)(&D_83404688 + 0x2C);
    *(f32 *)(&D_83404250 + 0x38) = temp_fv0;
    *(f32 *)(&D_83404250 + 0x34) = temp_fv0;
    *(f32 *)(&D_83404250 + 0x30) = temp_fv0;
    *(f32 *)(&D_83404250 + 0x2C) = *(f32 *)(&D_83404688 + 0x2C);
    *(f32 *)(&D_83404250 + 0x28) = *(f32 *)(&D_83404688 + 0x28);
    *(f32 *)(&D_83404250 + 0x24) = *(f32 *)(&D_83404688 + 0x24);
    if (D_834047F0 != 0x53) {
        *(volatile f32 *)(&D_83404688 + 0x28) = 150.0f;
        *(f32 *)(&D_83404688 + 0x28) = -150.0f;
        *(f32 *)(&D_83404250 + 0x28) = *(f32 *)(&D_83404688 + 0x28);
    }
    *(f32 *)(&D_83404688 + 0x38) = 0.0f;
    *(f32 *)(&D_83404688 + 0x34) = *(f32 *)(&D_83404688 + 0x38);
    *(f32 *)(&D_83404688 + 0x30) = *(f32 *)(&D_83404688 + 0x34);
    func_8003F2C4(D_8340424C, (s32)&D_83404250, 0);
    func_8003F3BC(&D_83404250, 0);
    *(u8 *)(&D_83404250 + 2) = *(u8 *)(&D_83404250 + 2) & 0xFFBF;
    D_83404188.unk_14 = *(u8 *)((u8 *)*(void **)((u8 *)D_83404164 + 0x2D4) + 0x13B0);
    D_83404188.unk_18 = *(s8 *)((u8 *)*(void **)((u8 *)D_83404164 + 0x2D4) + 0x13B1);
}
/* mkdraft:func_83402B10 end */

s32 GeoRender_FindAnchorPosition(s32 *, s32, f32 *);
extern f32 D_834041D4;
extern u8 D_83404250;
extern f32 *Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
void func_83402C80(void) {
    Vec3f_SetComponentsDuplicate(&D_834041D4, (*(f32 *)((u8 *)(&D_83404250) + (0x24))), (*(f32 *)((u8 *)(&D_83404250) + (0x28))), (*(f32 *)((u8 *)(&D_83404250) + (0x2C))));
    if (GeoRender_FindAnchorPosition(&D_83404250, 0x64, &D_834041D4) == 0) {
        GeoRender_FindAnchorPosition(&D_83404250, 9, &D_834041D4);
        return;
    }
    GeoRender_FindAnchorPosition(&D_83404250, 0x64, &D_834041D4);
}

extern f32 D_83404274[3];
extern f32 D_83403D80[3];
extern void func_80037120(void *, void *, f32 *, s16 *, s16 *);
extern void Camera_ComputeEyeFromAngles(void *, void *, f32, s16, s16);
void func_83402D00(void) {
    f32 position[3];
    f32 distance;
    s16 angle_x;
    s16 angle_y;

    func_80037120(D_83404274, D_83403D80, &distance, &angle_x, &angle_y);
    if (distance > 10.0f) {
        Camera_ComputeEyeFromAngles(D_83404274, position, (f32)((f64)distance * 0.1), angle_x, angle_y);
        Vec3f_SetComponentsDuplicate(D_83404274, position[0], position[1], position[2]);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_83402DA8.s")

extern u8 D_83404250;
extern s32 D_8340419C;
extern s32 D_834041A0;
extern s32 D_834041B0;
extern s32 D_8340424C;
extern s32 D_834047F0;
extern s32 ModelAnim_IsFinished(u8 *);
extern void func_80024480(s32, s32);
extern void ModelAnim_SetResourceAnimation(s32, u8 *, s32);
extern void ModelAnim_SetEventTrack(u8 *, s32);
extern void func_83400038(s32);
void func_83402F08(void) {
    if (ModelAnim_IsFinished(&D_83404250) == 1) {
        switch (D_834041B0) {
        case 0:
            func_80024480(D_834047F0, 4);
            ModelAnim_SetResourceAnimation(D_8340424C, &D_83404250, D_8340419C);
            ModelAnim_SetEventTrack(&D_83404250, D_834041A0);
            D_834041B0 = 1;
            return;
        case 1:
            func_83400038(0);
            ModelAnim_SetResourceAnimation(D_8340424C, &D_83404250, 0);
            ModelAnim_SetEventTrack(&D_83404250, 0);
            D_834041B0 = 2;
            break;
        case 2:
        default:
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/58/fragment58_code/func_83402FE8.s")

extern void func_80055948(s32);
extern void func_80054A24(s32, s32);
extern void func_800086A4(s32);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_8340295C(void);
extern s32 func_83402FE8(s32);
extern s32 D_834047F0;
void func_834034CC(void) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    var_s0 = 1;
    var_s1 = 1;
    func_80055948(3);
    if (D_834047F0 == 0x53) {
        var_s1 = 0;
    }
    func_80054A24(var_s1, 1);
    func_800086A4(2);
    StageContext_SetClearColor(1);
    StageFade_StartFromOpaque(0x14);
    var_s1 = 8;
    do {
        func_80064D28();
        func_8340295C();
        temp_v0 = func_83402FE8(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != var_s1);
}

/* mkdraft:func_83403560 begin */
u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32); /* extern */
void Gfx_FreeDisplayListBuffers(void);          /* extern */
void Gfx_InitDisplayListBuffers(s32, s32);      /* extern */
s32 func_80001FF0(void);                        /* extern */
s32 func_800082E0(s32, s32, s32, s32, s32, s32); /* extern */
void func_80008514(s32);                        /* extern */
void func_80008574(void);                       /* extern */
s32 func_80047588(s32, s32);                    /* extern */
s32 func_80047610(void);                        /* extern */
s32 func_8004C09C(s32);                         /* extern */
s32 func_8004C398(void);                        /* extern */
s32 func_8004C4B0(s32);                         /* extern */
s32 func_8004C8C0(s32);                         /* extern */
s32 func_8004D690(s32);                         /* extern */
void func_80051D64(s32, s32);                   /* extern */
void func_8005487C(void *);                     /* extern */
void func_800548C4(void *);                     /* extern */
s32 func_80055028(void);                        /* extern */
void func_80055EF0(void *, s32);                /* extern */
void func_80055F6C(void *, s32);                /* extern */
s32 func_83400B98(void);                        /* extern */
s32 func_87F0DBE0(u8 *, s32);                   /* extern */
s32 main_pool_pop_state(s32);                   /* extern */
s32 main_pool_push_state(s32);                  /* extern */
extern s32 D_1000000;
extern u8 D_446E30;
extern u8 D_447D00;
extern f32 D_83403C78;
extern s32 D_83403C7C;
extern s16 *D_8340416C;
extern u8 D_83404170;
extern s32 D_83404244;



s32 func_83403560(s32 arg0, s16 *arg1) {
    s32 sp4C;
    s32 sp48;
    u8 sp30[0x18];  /* 0x18-byte per-player record copied from func_80051138(0) + mode*0x18 + 0x1C by
                       func_80055EF0 and written back by func_80055F6C. */
    u8 sp20[0x10];  /* 0x10-byte quad copied from func_80051138(0) + 4 by func_8005487C and written
                       back by func_800548C4. */

    if (func_80001FF0() == 0x3C) {
        D_83403C7C = 0x1E;
        D_83403C78 = 1.0f;
    } else {
        D_83403C7C = 0x19;
        D_83403C78 = 1.2f;  /* Value of the D_83404120 literal pool entry (late_rodata, 1.2). */
    }
    D_8340416C = arg1;
    main_pool_push_state(0x504D5052);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp4C = func_800082E0(0, 1, 2, 1, 2, 1);
    func_8004C09C(0x127);
    D_83404244 = func_8004D690(0x18);
    func_8004C4B0(0);
    func_8004C4B0(0x14);
    func_8004C8C0(0x164);
    func_8004C8C0(0x102);
    func_8004C8C0(0x101);
    func_8004C8C0(0x4E);
    func_8004C8C0(0xF9);
    func_8004C8C0(0xF8);
    func_80047588(0x13, 0);
    Asset_LoadToSegment((u32) ((s32) &D_1000000 & 0x0F000000) >> 0x18, &D_446E30, &D_447D00, 0);
    func_83400B98();
    func_80008514(sp4C);
    func_87F0DBE0(&D_83404170, sp4C);
    func_834034CC();
    func_80008574();
    /* *D_8340416C selects the record set: func_80055EF0/func_80055F6C accept 0 or 1 and index
       func_80051138(0) + mode*0x18. */
    sp48 = (*D_8340416C != 0) ? 1 : 0;
    func_80055EF0(sp30, sp48);
    sp30[0xD] = 1;
    func_80055F6C(sp30, sp48);
    if (*D_8340416C == 0) {
        func_8005487C(sp20);
        *(u16 *)(sp20 + 2) |= 1;
        func_800548C4(sp20);
    }
    func_80051D64(0x14, 0);
    func_80055028();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x504D5052);
    return 0;
}
/* mkdraft:func_83403560 end */
#endif
