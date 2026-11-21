#include "global.h"

#ifdef VERSION_US

typedef struct F17FadeClipRectangle {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
} F17FadeClipRectangle;
typedef struct F17FadeClipBuffer {
    s16 count;
    F17FadeClipRectangle rectangles[100];
} F17FadeClipBuffer;
typedef struct F17FadeRenderState {
    s32 resource;
    s16 alpha;
    s16 timer;
    s16 countdown;
    s16 active_buffer;
    F17FadeClipBuffer buffers[2];
} F17FadeRenderState;
// The constructor enumerates 100 rectangle names for each clipping buffer.

typedef struct F17TransitionState {
    s16 state;
    s16 unk_02;
} F17TransitionState;
// func_8220AA54 initializes enabled in six consecutive 28-byte records.
typedef struct Fragment17ChoiceEntry {
    s32 enabled;
    u8 unk_04[24];
} Fragment17ChoiceEntry;
extern Fragment17ChoiceEntry D_8220DEF4[];
typedef struct unk_func_8220AC64_pair { s16 unk_00; s16 unk_02; } unk_func_8220AC64_pair;
// Loader-cleared transition record at 0x822106B0 (a .bss static, pinned in
// datamig_bss.ld; +0x20/+0x22 are cleared by func_82208EB0). The scene's state machine
// value is at +2 (also read as D_822106B2); func_82209360 sets the 0x14/0x18
// scales and the 0x1E screen position when its zoom finishes.
typedef struct F17TransitionRecord {
    s16 unk_00;
    F17TransitionState transition;
    u16 unk_06;
    s16 unk_08;
    u8 unk_0A[0xA];
    f32 unk_14;
    f32 unk_18;
    s16 unk_1C;
    s16 unk_1E;
    s16 unk_20;
    s16 unk_22;
} F17TransitionRecord;
static F17TransitionRecord sTransitionRecord;
extern s16 D_822106B2;
extern s16 D_822106CC, D_822106CE;
extern s16 D_822106BA;
extern f32 D_822106C4;
extern f32 D_822106C8;
extern void func_800226C0(s32);
extern u16 D_822106B6;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern s32 func_8220D67C(void);
extern void func_800503A4(s32);
extern void *D_8220EB88;
extern s32 func_8220AD10(void);
extern void *D_8220DA08;
extern u16 D_8220EB82;
extern u8 D_8220D8D0[];
extern s32 D_8220EC38;
extern u8 D_82210698[];
extern void func_82204444(void);
extern void func_82204744(void);
extern s32 func_822047BC(s32 arg0, s32 arg1);

typedef struct Fragment17TextureHeader {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u8 unk_06[2];
} Fragment17TextureHeader;
typedef struct Fragment17TextureRecord {
    u8 model[360];
    void *layout;
    Fragment17TextureHeader *texture;
    s16 tile_count;
    s16 tile_height;
} Fragment17TextureRecord;

extern Gfx *D_800D0510;
// Declarations shared with fragment17_1162A0.c (one object before the split).
extern Fragment17TextureRecord D_8220F290[];
extern Fragment17TextureRecord D_8220F9D8[];
extern Fragment17TextureRecord D_8220FFA8[];
extern Gfx *Gfx_AllocDisplayList(s32);
extern Gfx D_8220DA20[];
extern f32 D_80087E50[];
extern s16 D_8220DA40;
extern s16 D_8220DA5A[];
extern s16 D_8220DA80[];
extern s16 D_8220DA94;
extern s16 D_8220DAAA[];
extern s16 D_8220DAC8[][2];
extern s16 D_8220DAD8;
extern s16 D_8220DAEE[];
extern s16 D_8220DB0C[][2];
extern s16 D_8220EB80[];
extern s16 D_8220EB84;
extern s16 D_8220EB98;
extern s16 D_8220EC44;
extern s16 D_8220EC46;
extern s16 D_8220EC48;
extern s32 D_8220DA0C;
extern s32 D_8220DA10;
extern s32 D_8220DA14;
extern s32 D_8220DA18;
extern s32 D_8220DA1C;
extern s32 D_8220E120;
extern s32 D_8220EC40;
extern s32 D_82210578;
extern s32 StageContext_GetFadeMode(void);
extern s32 StageContext_GetFadeMode(void); extern void func_800086A4(s32); extern void StageFade_StartFromOpaque(s32); extern void func_80064D28(void); extern void func_8220B930(void); extern void func_8220C340(void); extern void func_82204148(void); extern s32 func_82208A1C(s32); extern void func_800548C4(void *); extern void func_80051D64(s32, s32); extern s32 D_8220DA0C; extern u8 D_8220EC28[];
extern s32 StageFade_StartFromTransparent(s32);
extern s32 func_800071A4(s32, s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D690(s32);
extern s32 func_8004EB58(u8 *, s32);
extern s32 func_8005049C(s32, s32);
extern s32 func_80054E10(s32);
extern s32 func_800562B8(s32);
extern s32 func_82205A14(s32, void *);
extern s32 func_82205A48(s32, void *);
extern s32 func_82205A8C(s32, void *);
extern s32 func_82205B00(s32, void *);
extern s32 func_82205C14(s32, void *);
extern s32 func_82205CE8(s32, void *);
extern s32 func_82205D78(s32, void *);
extern s32 func_82205E04(s32, void *);
extern s32 func_82205F2C(s32 arg0, u8 *arg1);
extern s32 func_82206124(s32 arg0, void *arg1);
extern s32 func_822061A8(s32, void *);
extern s32 func_82206304(s32, u8 *);
extern s32 func_82206400(s32 arg0, void *arg1);
extern s32 func_822064DC(s32, void *);
extern s32 func_82206950(void);
extern s32 func_822085EC(void);
extern s32 func_82208678(void);
extern s32 func_822088FC(void);
extern s32 func_822089C0(void);
extern s32 func_8220AC38(void);
extern s32 func_8220AC64(void);
extern s32 func_8220AD04(void);
extern s32 func_8220ADE0(s32);
extern s32 func_8220AE10(void);
extern s32 func_8220D630(void);
extern s32 func_8220D670(void);
extern s32 main_pool_get_available(void);
extern u32 func_800060E8(void);
extern u8 *MainPool_AllocState(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern u8 D_8220DA6C[];
extern u8 D_8220DAB8[];
extern u8 D_8220DAFC[];
extern u8 D_8220DB1C[];
extern u8 D_8220DB8C;
extern u8 D_8220DBC8[];
extern u8 D_8220EBE0[];
extern u8 D_8220EC28[];
extern u8 D_8220F284[];
extern u8 D_822105A0;
extern u8 D_822105AC;
extern u8 D_822105B8;
extern u8 D_822105C4;
extern u8 D_822105D0;
extern u8 D_822105DC[];
extern u8 func_80050518(u8);
extern void * D_8220DA08;
extern void *D_80087200;
extern void *D_8220DA44[];
extern void *D_8220DA98[];
extern void *D_8220DADC[];
extern void *func_8004C874(s32, s32);
extern void *process_geo_layout(struct S1_MemoryBlock *, void *);
extern void BgStage_DrawFrame();
extern void Font_DisableTwoCycleTexturing(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void Geo_RenderRootNode(s32);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
extern void MainPool_FinalizeAllocation(struct S1_MemoryBlock *);
extern void ModelRenderer_InitDisplayRoots(void);
extern void StageContext_SetClearColor(u16);
extern void _bzero(u8 *, size_t);
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern void func_80008648();
extern void func_800225C4(s32);
extern void func_80035424(s32);
typedef s32 (*Fragment17NodeCallback)(s32, void *);
extern void func_80037E3C(void *, Fragment17NodeCallback, void *);
extern void func_8003CD84(void);
extern void func_8003F018(s32);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_800459AC(s32, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80046634();
extern void func_800468A0(s32 arg0);
extern void func_800495BC(s32, s32, const char *);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800497E4(s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_8004C8C0(s32);
extern void func_8004E308(s32, s32 (*)(s32, void *), s32);
extern void func_8005053C(s32, u8 *);
extern void func_80050578(s32, void *);
extern void func_8005487C(u8 *);
extern void func_81600F0C(void *, s32, s32, s32, s32);
extern void func_822040A0(s16 *);
extern void func_82204430(s32);
extern void func_822067C4(s32 arg0, void *arg1);
extern void func_82206804(s32 arg0);
extern void func_82206854(s32, s32, s32);
extern void func_822068E0(void);
extern void func_822069A4();
extern void func_82206A2C();
extern void func_82206BA4(s32, s32, s32, s32, u8 *, s32, s32, s32, s32, s32);
extern void func_82207714(s32);
extern void func_822083C4();
extern void func_82208518(void);
extern void func_82208954(s32);
extern void func_8220AA54(s32, s32);
extern void func_8220ACF4(void);
extern void func_8220AD1C(s16 *);
extern void func_8220AD38(s32, void *);
extern void func_8220AD70(s32, void *);
extern void func_8220ADA8(s32, void *);
extern void func_8220B478();
extern void func_8220B770(void);
extern void func_8220B7A0(s16, s16, u8 *, u8 *);
extern void func_8220B900(void);
extern void func_8220B984();
extern void func_8220BF68(s32);
extern void func_8220D560();
extern s32 D_8220DEE0[][2];
s32 func_82208EB0(void *arg0) {
    F17TransitionRecord *rec = &sTransitionRecord;
    s32 idx = *(s32 *)((u8 *)arg0 + 0x14);
    Fragment17ChoiceEntry *e;

    if (idx == 0) {
        rec->transition.unk_02 = 0;
        rec->unk_06 = 0;
        if (rec->unk_00 < 0) {
            rec->transition.state = 0;
            rec->unk_08 = 1;
        } else {
            rec->transition.state = 3;
            rec->unk_08 = rec->unk_00;
        }
        *(s16 *)&rec->unk_0A[0] = -1;
        *(s16 *)&rec->unk_0A[4] = 0;
        *(s16 *)&rec->unk_0A[6] = 0;
        rec->unk_14 = 0.75f;
        rec->unk_18 = 0.75f;
        e = &D_8220DEF4[rec->unk_08];
        if (*(s32 *)((u8 *)e + 8) != 0) {
            rec->unk_06 |= 1;
        } else {
            rec->unk_06 &= ~1;
        }
        (&D_822106CC)[0] = *(s16 *)((u8 *)e + 0xC);
        if (rec->unk_00 < 0) {
            (&D_822106CC)[1] = -0x20;
        } else {
            (&D_822106CC)[1] = *(s16 *)((u8 *)e + 0xE);
        }
        rec->unk_20 = 0;
        rec->unk_22 = 0;
    }
    *(s32 *)((u8 *)arg0 + 0x16C) = func_8004C990(D_8220DEE0[idx][0], D_8220DEE0[idx][1]);
}

extern s16 D_822106B8;
extern s16 D_822106D4;
// Moves the menu selection (sTransitionRecord.unk_08) in direction arg0 and starts the
// transition when it changes. Writing the record through a local pointer gives retail's
// per-access `lui` (shared for the +2/+4 pair) instead of a hoisted base register.
void func_82209000(s32 arg0) {
    s16 prev = D_822106B8;
    Fragment17ChoiceEntry *cur = &D_8220DEF4[D_822106B8];
    Fragment17ChoiceEntry *nw;
    s16 n;
    F17TransitionRecord *rec = &sTransitionRecord;

    switch (arg0) {
    case 0:
        n = *(s16 *)((u8 *)cur + 0x14);
        if (n >= 0 && D_8220DEF4[n].enabled != 0) {
            rec->unk_08 = n;
        }
        break;
    case 1:
        n = *(s16 *)((u8 *)cur + 0x16);
        if (n >= 0 && D_8220DEF4[n].enabled != 0) {
            rec->unk_08 = n;
        }
        break;
    case 2:
        n = *(s16 *)((u8 *)cur + 0x18);
        if (n >= 0 && D_8220DEF4[n].enabled != 0) {
            rec->unk_08 = n;
        }
        break;
    case 3:
        n = *(s16 *)((u8 *)cur + 0x1A);
        if (n >= 0 && D_8220DEF4[*(s16 *)((u8 *)cur + 0x18)].enabled != 0) {
            rec->unk_08 = n;
        }
        break;
    }
    if (prev != rec->unk_08) {
        nw = &D_8220DEF4[rec->unk_08];
        rec->transition.state = 4;
        rec->transition.unk_02 = 0;
        if (*(s32 *)((u8 *)nw + 8) == 0) {
            rec->unk_06 &= ~1;
        } else {
            rec->unk_06 |= 1;
        }
        *(unk_func_8220AC64_pair *)&D_822106D4 = *(unk_func_8220AC64_pair *)&D_822106CC;
        if (*(s32 *)((u8 *)cur + 4) != 0 || *(s32 *)((u8 *)nw + 4) != 0) {
            func_800226C0(0x34);
        } else {
            func_800226C0(1);
        }
    }
}

f32 func_822091E0(f32 arg0) {
    return 1.5f - arg0;
}

extern f32 D_822106B0[];
extern f32 D_8220DEF0;
extern void func_8220BC7C(s32, s32);
void func_822091F0(void) {
    s32 pad[5]; // FAKE: places the `done` spill at 0x18 in the 0x38 frame
    F17TransitionState *transition;
    F17TransitionRecord *record;
    s32 done;
    s16 *state;
    f32 frame;
    f32 position;
    f32 limit;
    f32 width;
    f32 scale;

    transition = &sTransitionRecord.transition;
    record = &sTransitionRecord;
    state = (s16 *)D_822106B0;
    state[2]++;
    done = 0;
    frame = state[2];
    scale = frame * D_8220DEF0;
    width = 35.0f;
    limit = 320.0f + width;
    position = frame * scale + -32.0f;
    scale = limit - width * 0.4f;
    if (position > scale) {
        position = scale;
        done = 1;
    }
    record->unk_1E = (position > 0.0f ? 0.5f : -0.5f) + position;
    // Clamped directly in the record: uopt keeps unk_18 in a register and writes
    // it back in the call's delay slot.
    record->unk_18 = (limit - position) / 35.0f * 0.75f;
    if (record->unk_18 > 0.75f) {
        record->unk_18 = 0.75f;
    }
    record->unk_14 = func_822091E0(record->unk_18);
    record->unk_20 = 0;
    record->unk_22 = 0;
    if (done) {
        transition->state = 2;
        transition->unk_02 = 0;
        func_8220BC7C(record->unk_1C, record->unk_1E);
        func_800226C0(0x36);
    }
}

extern f32 D_822106B0[];
extern s16 D_822106B4, D_822106BE;
extern f32 func_822091E0(f32 arg0);
void func_82209360(void) {
    F17TransitionState *transition;
    f32 *scales;
    s32 done;
    s16 *state;
    f32 progress;
    f32 scale;
    f32 width;
    f32 position;
    F17TransitionRecord *record;
    transition = &sTransitionRecord.transition;
    record = &sTransitionRecord;
    scales = D_822106B0;
    state = (s16 *)D_822106B0;
    state[2]++;
    done = 0;
    if (state[2] >= 2) {
        width = D_822106B4 - 2;
        progress = width / 5.0f;
        if (progress >= 1.0f) {
            progress = 1.0f;
            done = 1;
        }
        scale = (0.6f * progress + 0.4f) * 0.75f;
        scales[6] = scale;
        scales[5] = func_822091E0(scale);
        width = 35.0f;
        position = 320.0f + width - scales[6] * width;
        ((s16 *)scales)[15] = (position > 0.0f ? 0.5f : -0.5f) + position;
        if (done) {
            transition->state = 3;
            transition->unk_02 = 0;
            D_822106BE = 0;
            scales[5] = 0.75f;
            record->unk_18 = 0.75f;
            record->unk_1E = 320;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_118870/func_822094C4.s")

extern s16 D_822106C0, D_822106D4;
typedef struct F17Point { s16 x, y; } F17Point;
// Lerps the transition record's position (unk_1C/1E) from the saved start point
// D_822106D4/D_822106D6 toward the entry's target over five frames. FAKE forms
// reproduce retail's load order: D_822106D6 is read through the record base
// (0x822106B0 + 0x26) so it stays after the unk_1C store.
void func_8220980C(void) {
    s16 *state = (s16 *)D_822106B0;
    s16 *entry;
    s16 *pt; // FAKE: second name for D_822106D4
    s32 z = 0; // FAKE: zero index
    F17TransitionRecord *rec = &sTransitionRecord;
    f32 progress;
    f32 v;
    f32 v2;

    entry = (s16 *)&D_8220DEF4[state[4]];
    state[2]++;
    pt = &D_822106D4;
    if (state[2] < 5) {
        progress = D_822106B4 / 5.0f;
        v = (entry[6] - ((F17Point *)&D_822106D4)->x) * progress + ((F17Point *)pt)->x;
        (&sTransitionRecord)[z].unk_1C = ((v > 0.0f) ? 0.5f : -0.5f) + v;
        v2 = *(s16 *)((u8 *)rec + 0x26) + (entry[7] - *(s16 *)((u8 *)rec + 0x26)) * progress;
        (&sTransitionRecord)[z].unk_1E = ((v2 > 0.0f) ? 0.5f : -0.5f) + v2;
    } else {
        rec->transition.state = 3;
        rec->transition.unk_02 = 0;
        D_822106C0 = 0;
        rec->unk_1C = entry[6];
        rec->unk_1E = entry[7];
    }
}

extern s16 D_822106D0;
extern s16 D_822106D2;
extern s16 D_822106D6;
// Moves the transition record's position (unk_1C/1E) from D_822106D4/D6 toward the
// selected entry's corner over five frames, then snaps it and starts state 6.
void func_82209974(void) {
    s16 *state = (s16 *)D_822106B0;
    F17TransitionRecord *rec = &sTransitionRecord;
    Fragment17ChoiceEntry *entry;
    s16 tx;
    f32 progress;
    f32 x;
    f32 y;

    entry = &D_8220DEF4[state[4]];
    state[2]++;
    if (((u16 *)state)[3] & 1) {
        tx = *(s16 *)&entry->unk_04[8] - 16;
    } else {
        tx = *(s16 *)&entry->unk_04[8] + 16;
    }
    if (D_822106B4 < 5) {
        progress = D_822106B4 / 5.0f;
        x = state[18] + (tx - state[18]) * progress;
        state[14] = (x > 0.0f ? 0.5f : -0.5f) + x;
        y = state[19] + (*(s16 *)&entry->unk_04[10] + 16 - state[19]) * progress;
        state[15] = (y > 0.0f ? 0.5f : -0.5f) + y;
        D_822106D0 = (s32)((x > 0.0f ? 0.5f : -0.5f) + x) - state[18];
        D_822106D2 = (s32)((y > 0.0f ? 0.5f : -0.5f) + y) - *(s16 *)&entry->unk_04[10];
    } else {
        rec->transition.state = 6;
        rec->transition.unk_02 = 0;
        rec->unk_1C = tx;
        rec->unk_1E = *(s16 *)&entry->unk_04[10] + 16;
        *(unk_func_8220AC64_pair *)&D_822106D4 = *(unk_func_8220AC64_pair *)&D_822106CC;
    }
}

// Second half of the selection transition: lerps the record position toward the
// selected entry's rect, snaps it into state 7 on the fifth frame, then sets the
// zoom scale (C4/C8) from the remaining distance. The `x < 0` int literal makes
// IDO load a fresh 0.0f as retail does, and the (s32) round casts give retail's
// t-register rotation.
void func_82209BA4(void) {
    s16 *state = (s16 *)D_822106B0;
    F17TransitionRecord *rec = &sTransitionRecord;
    s16 *choice;
    f32 progress;
    f32 base;
    f32 target;
    f32 x;
    f32 y;
    f32 scale;
    f32 factor;
    s32 n;

    choice = (s16 *)&D_8220DEF4[state[4]];
    state[2]++;
    if (state[2] >= 5) {
        n = D_822106B4 - 5;
        progress = n / 5.0f;
        target = choice[8] + choice[6];
        base = state[18];
        x = (target - base) * progress + base;
        state[14] = (x > 0.0f ? 0.5f : -0.5f) + x;
        y = state[19] + (choice[7] + choice[9] - state[19]) * progress;
        state[15] = (y > 0.0f ? 0.5f : -0.5f) + y;
        D_822106D0 = (s32)((x > 0.0f ? 0.5f : -0.5f) + x) - state[18];
        D_822106D2 = (s32)((y > 0.0f ? 0.5f : -0.5f) + y) - choice[7];
        if (n == 5) {
            rec->transition.state = 7;
            rec->transition.unk_02 = 0;
            rec->unk_1C = target;
            rec->unk_1E = choice[9] + choice[7];
            D_822106BA = rec->unk_08;
        }
        x = target - D_822106CC; // distance left
        if (x < 0) {
            x = -x;
        }
        scale = (x / 40.0f + 0.4f) * 0.75f;
        if (scale > 0.75f) {
            scale = 0.75f;
        }
        rec->unk_14 = scale;
        base = func_822091E0(scale);
        scale = D_822106C4;
        factor = 1.0f - 0.9f * progress;
        scale *= factor;
        D_822106C8 = base * factor;
        rec->unk_14 = scale;
    }
}

void func_82209E90(void) {
    D_822106B0[5] = 0.0f;
    D_822106B0[6] = 0.0f;
}

extern void func_822091F0(void);
extern void func_82209360(void);
extern void func_822094C4(void);
extern void func_8220980C(void);
extern void func_82209974(void);
extern void func_82209BA4(void);

s32 func_82209EA8(void) {
    switch (D_822106B2) {
        case 0:
            break;
        case 1:
            func_822091F0();
            break;
        case 2:
            func_82209360();
            break;
        case 3:
            func_822094C4();
            break;
        case 4:
            func_8220980C();
            break;
        case 5:
            func_82209974();
            break;
        case 6:
            func_82209BA4();
            break;
        case 7:
            func_82209E90();
            break;
    }
}

extern s16 D_822106D2;
s32 func_82209F50(void *arg0) {
    s32 pad[4]; // FAKE: reserves the 0x38-byte frame, as in sibling func_8220A098.
    f32 fade;
    f32 x;
    f32 y;

    fade = 1.0f - (f32)(320 - D_822106CE) / 360.0f;
    if (fade < 0.001f) {
        fade = 0.0f;
    } else if (1.0f < fade) {
        fade = 1.0f;
    }
    x = D_822106C4 * fade;
    y = D_822106C8 * fade;
    if (D_822106B6 & 1) {
        x = 0.0f - x;
    }
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x24), (f32)D_822106CC - 320.0f, 240.0f - (f32)(D_822106D2 + 0x15E), -579.0f);
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x30), x, y, 1.0f);
}

// Sets the vectors at arg0 + 0x24 to the screen point (D_822106CC, D_822106CE) relative to the
// 640x480 center at depth -579, and at arg0 + 0x30 to (x, D_822106C8, 1), where x is
// D_822106B0[5], negated when bit 0 of the halfword at D_822106B0 + 6 is set.
s32 func_8220A098(void *arg0) {
    s32 pad[4]; // FAKE: reserves the 0x30-byte frame; diff score 58 without it.
    f32 x;

    x = D_822106B0[5];
    if (*(u16 *)((u8 *)D_822106B0 + 6) & 1) {
        x = 0.0f - x;
    }
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x24), D_822106CC - 320.0f, 240.0f - D_822106CE, -579.0f);
    Vec3f_SetComponentsDuplicate((f32 *)((u8 *)arg0 + 0x30), x, D_822106C8, 1.0f);
}

extern s32 func_82208EB0(void *);
extern s32 func_82209F50(void *);
extern s32 func_8220A098(void *);
s32 func_8220A154(s32 arg0, void *arg1) { s32 flag = *(s32 *)((u8 *)arg1 + 0x14); switch (arg0) { case 0: func_82208EB0(arg1); break; case 2: if (flag == 0) { func_82209EA8(); func_82209F50(arg1); } else { func_8220A098(arg1); } break; } return 0; }

extern Gfx D_8220DEB0[];
void func_8220A1C4(s32 texture) {
    s32 alpha;
    s32 strip_count;
    Vtx *vertices;
    u8 *image;
    s32 width;
    s32 remaining_height;
    s32 index;
    s32 strip_height;
    s32 y;
    f32 fade;
    f32 alpha_value;
    f32 rounding;
    s32 left_x;
    s32 right_x;
    s32 pixel_offset;
    s16 bottom_y;
    s16 texture_t;

    strip_count = 1;
    vertices = (Vtx *)Gfx_AllocDisplayList(strip_count * 4 * sizeof(Vtx));
    width = ((Fragment17TextureHeader *)texture)->width;
    remaining_height = ((Fragment17TextureHeader *)texture)->height;
    y = remaining_height / 2;
    image = func_8004CA60((u8 *)texture);
    if (vertices != NULL) {
        fade = 1.0f - (f32)(320 - D_822106CE) / 200.0f;
        if (fade < 0.001f) {
            fade = 0.0f;
        } else if (fade > 1.0f) {
            fade = 1.0f;
        }
        alpha_value = 255.0f * fade;
        if (alpha_value > 0.0f) {
            rounding = 0.5f;
        } else {
            rounding = -0.5f;
        }
        gSPDisplayList(D_800D0510++, D_8220DEB0);
        alpha = (s32)(rounding + alpha_value);
        gDPSetEnvColor(D_800D0510++, 255, 255, 255, alpha);
        left_x = -(width / 2);
        right_x = left_x + width;
        for (index = 0; index < strip_count; index++) {
            if (remaining_height < 34) {
                strip_height = remaining_height;
            } else {
                strip_height = 34;
            }
            pixel_offset = index * (width * 34);
            texture_t = strip_height << 5;
            bottom_y = y - strip_height;
            Gfx_SetVertexAttributes(vertices, (s16)left_x, (s16)y, 0, 0, 0, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 1, (s16)left_x, bottom_y, 0, 0, strip_height << 5, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 2, (s16)right_x, bottom_y, 0, (s16)(width << 5), texture_t, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 3, (s16)right_x, (s16)y, 0, (s16)(width << 5), 0, 255, 255, 255, 255);
            func_800459AC((s32)(image + pixel_offset), ((Fragment17TextureHeader *)texture)->format,
                          ((Fragment17TextureHeader *)texture)->size, width, strip_height,
                          1, 0, 2, 2, 0, 0, 0, 0);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            vertices += 4;
            y -= strip_height;
            remaining_height -= strip_height;
        }
    }
}

extern void GeoRender_ApplyMaterialState();
extern void func_8220A1C4(s32);
extern s32 D_82210844;
s32 func_8220A5BC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5) && (D_82210844 != 0)) {
        func_8220A1C4(D_82210844);
        GeoRender_ApplyMaterialState();
    }
    return 0;
}

void func_8220A608(s32 texture) {
    s32 intensity;
    Vtx *vertices;
    s32 width;
    s32 remaining_height;
    u8 *image;
    s32 index;
    s32 y;
    s32 strip_height;
    f32 fade;
    f32 intensity_value;
    f32 rounding;
    s32 left_x;
    s32 right_x;
    s16 bottom_y;
    s16 texture_t;

    vertices = (Vtx *)Gfx_AllocDisplayList(3 * 4 * sizeof(Vtx));
    width = ((Fragment17TextureHeader *)texture)->width;
    remaining_height = ((Fragment17TextureHeader *)texture)->height;
    y = remaining_height / 2;
    image = func_8004CA60((u8 *)texture);
    if (vertices != NULL) {
        fade = 1.0f - (f32)(320 - D_822106CE) / 360.0f;
        if (fade < 0.001f) {
            fade = 0.0f;
        } else if (fade > 1.0f) {
            fade = 1.0f;
        }
        intensity_value = 255.0f * fade;
        if (intensity_value > 0.0f) {
            rounding = 0.5f;
        } else {
            rounding = -0.5f;
        }
        gSPDisplayList(D_800D0510++, D_8220DEB0);
        intensity = (s32)(rounding + intensity_value);
        gDPSetEnvColor(D_800D0510++, intensity, intensity, intensity, 255);
        left_x = -(width / 2);
        right_x = left_x + width;
        for (index = 0; index < 3; index++) {
            if (remaining_height < 24) {
                strip_height = remaining_height;
            } else {
                strip_height = 24;
            }
            texture_t = strip_height << 5;
            bottom_y = y - strip_height;
            Gfx_SetVertexAttributes(vertices, (s16)left_x, (s16)y, 0, 0, 0, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 1, (s16)left_x, bottom_y, 0, 0, strip_height << 5, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 2, (s16)right_x, bottom_y, 0, (s16)(width << 5), texture_t, 255, 255, 255, 255);
            Gfx_SetVertexAttributes(vertices + 3, (s16)right_x, (s16)y, 0, (s16)(width << 5), 0, 255, 255, 255, 255);
            func_800459AC((s32)(image + index * (width * 48)), ((Fragment17TextureHeader *)texture)->format,
                          ((Fragment17TextureHeader *)texture)->size, width, strip_height,
                          1, 0, 2, 2, 0, 0, 0, 0);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            vertices += 4;
            y -= strip_height;
            remaining_height -= strip_height;
        }
    }
}

extern void func_8220A608(s32);
extern s32 D_822109B4;
s32 func_8220AA08(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5) && (D_822109B4 != 0)) {
        func_8220A608(D_822109B4);
        GeoRender_ApplyMaterialState();
    }
    return 0;
}

typedef struct Fragment17TransitionModelRecord {
    u8 model[360];
    void *layout;
    u8 unk_16C[4];
} Fragment17TransitionModelRecord;
extern Fragment17TransitionModelRecord D_822106D8[];
extern void *D_8220DED8[];
void func_8220AA54(s32 arg0, s32 arg1) {
    s32 index;
    struct S1_MemoryBlock *pool;
    Fragment17TransitionModelRecord *record;
    Fragment17TransitionModelRecord *entry;
    Fragment17ChoiceEntry *choice;
    s16 *selection;

    selection = (s16 *)D_822106B0;
    for (index = 0; index < 6; index++) {
        choice = &D_8220DEF4[index];
        if (index == 5) {
            choice->enabled = arg1;
        } else {
            choice->enabled = 1;
        }
    }
    *selection = arg0;
    do {
        choice = &D_8220DEF4[*selection];
        if (choice->enabled != 0) {
            break;
        }
        if (*selection > 0) {
            --*selection;
        }
    } while (*selection > 0);
    pool = (struct S1_MemoryBlock *)MainPool_AllocState(main_pool_get_available(), 0);
    for (index = 0; index < 2; index++) {
        entry = &D_822106D8[index];
        entry->layout = process_geo_layout(pool, D_8220DED8[index]);
    }
    MainPool_FinalizeAllocation(pool);
    for (index = 0; index < 2; index++) {
        record = &D_822106D8[index];
        func_8003F018((s32)record->model);
        func_80037E3C(record->model, func_8220A154, (void *)index);
        func_8003F114(record->model, 0, -1, record->layout);
    }
}

/* mkdraft:func_8220AC38 begin */

s32 func_8220AC38(void) {
    F17TransitionState *state = &sTransitionRecord.transition;
    s32 ret = 0;
    if (*(s16 *)(D_82210698 + 0x1A) == 0) {
        state->state = 1;
        state->unk_02 = 0;
        ret = 1;
    }
    return ret;
}
/* mkdraft:func_8220AC38 end */

extern s16 D_822106D4;
s32 func_8220AC64(void) {
    F17TransitionState *state = &sTransitionRecord.transition;
    s32 result = 0;

    if (*(s16 *)(D_82210698 + 0x1A) == 3) {
        state->state = 5;
        state->unk_02 = 0;
        *(unk_func_8220AC64_pair *)&D_822106D4 = *(unk_func_8220AC64_pair *)&D_822106CC;
        D_822106C4 = 0.75f;
        D_822106C8 = 0.75f;
        D_822106BA = -1;
        func_800226C0(57);
        result = 1;
    }
    return result;
}


void func_8220ACF4(void) {
    D_822106BA = -1;
}

s32 func_8220AD04(void) {
    return D_822106BA;
}

extern s16 D_822106B8;
s32 func_8220AD10(void) {
    return D_822106B8;
}


void func_8220AD1C(s16 *arg0) {
    arg0[0] = D_822106CC;
    arg0[1] = D_822106CE;
}


void func_8220AD38(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = &D_8220DEF4[arg0];
        (*(s16 *)((u8 *)(temp_v0) + (0xC))) = (s16) (*(s16 *)((u8 *)(arg1) + (0)));
        (*(s16 *)((u8 *)(temp_v0) + (0xE))) = (s16) (*(s16 *)((u8 *)(arg1) + (2)));
    }
}


void func_8220AD70(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = &D_8220DEF4[arg0];
        (*(s16 *)((u8 *)(arg1) + (0))) = (s16) (*(s16 *)((u8 *)(temp_v0) + (0xC)));
        (*(s16 *)((u8 *)(arg1) + (2))) = (s16) (*(s16 *)((u8 *)(temp_v0) + (0xE)));
    }
}


void func_8220ADA8(s32 arg0, void *arg1) {
    void *temp_v0;

    if (arg0 < 6) {
        temp_v0 = &D_8220DEF4[arg0];
        (*(s16 *)((u8 *)(temp_v0) + (0x10))) = (s16) (*(s16 *)((u8 *)(arg1) + (0)));
        (*(s16 *)((u8 *)(temp_v0) + (0x12))) = (s16) (*(s16 *)((u8 *)(arg1) + (2)));
    }
}

extern u8 D_8220DEF8[];
s32 func_8220ADE0(s32 arg0) {
    s32 result = 0;
    if ((arg0 >= 0) && (arg0 < 6)) {
        result = *(s32 *)(D_8220DEF8 + (arg0 * 0x1C));
    }
    return result;
}


s32 func_8220AE10(void) {
    return D_822106B2 == 3;
}
#endif
