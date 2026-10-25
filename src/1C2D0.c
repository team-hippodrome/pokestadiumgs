#include "global.h"


#ifdef VERSION_US
extern u8 D_8008FC20[];
extern s16 *D_8008E778;
extern void func_8001CA3C(void *);
void AudioChannel_Update(void *arg0, s32 updateVolume, s32 updateFrequency) {
    typedef struct { u8 frequency:1; u8 volume:1; u8 pan:1; u8 other:5; } ChannelUpdateFlags;
    typedef struct { u32 reserved:9; u32 volumeChanged:1; u32 panChanged:1; u32 rest:21; } ChannelWordFlags;
    typedef struct { u32 reserved:2; u32 muted:1; u32 rest:29; } SequenceWordFlags;
    typedef struct { u32 reserved:17; u32 ignoreFrequency:1; u32 tail:14; } LayerFrequencyFlags;
    typedef struct { u16 ignoreVolume:1; u16 tail:15; } LayerVolumeFlags;
    typedef struct { u8 ignorePan:1; u8 tail:7; } LayerPanFlags;
    s32 i;
    u8 *layer;
    u8 *updates;
    f32 volume;
    f32 frequency;

    if (((ChannelWordFlags *)arg0)->volumeChanged || updateVolume) {
        volume = *(f32 *)(*(u8 **)(((u8 *)arg0) + 0x50) + 0x30) * (*(f32 *)(((u8 *)arg0) + 0x2C) * *(f32 *)(((u8 *)arg0) + 0x30));
        if (((SequenceWordFlags *)(*(u8 **)(((u8 *)arg0) + 0x50)))->muted && (((u8 *)arg0)[3] & 0x20)) {
            volume = *(f32 *)(*(u8 **)(((u8 *)arg0) + 0x50) + 0x28) * volume;
        }
        *(f32 *)(((u8 *)arg0) + 0x38) = volume * volume;
    }
    if (((ChannelWordFlags *)arg0)->panChanged) { *(s32 *)(((u8 *)arg0) + 0x34) = ((u8 *)arg0)[0xB] * ((u8 *)arg0)[0xA]; }
    frequency = *(f32 *)(((u8 *)arg0) + 0x3C);
    if (updateFrequency) {
        frequency *= *(f32 *)(*(u8 **)(((u8 *)arg0) + 0x50) + 0x34);
        ((ChannelUpdateFlags *)((u8 *)arg0 + 1))->frequency = 1;
    }

    for (i = 0; i < 6; i++) {
        layer = ((u8 **)(((u8 *)arg0) + 0x54))[i];
        if (layer != NULL && (*(u32 *)layer >> 31) && *(u8 **)(layer + 0x3C) != NULL) {
            updates = ((u8 *)arg0) + 1;
            if (layer[0] & 1) {
                updates = D_8008FC20;
                layer[0] &= 0xFFFE;
            }
            if (((ChannelUpdateFlags *)updates)->frequency) {
                if (((LayerFrequencyFlags *)(layer + 8))->ignoreFrequency == 0) { *(f32 *)(layer + 0x54) = *(f32 *)(layer + 0x40); }
                else { *(f32 *)(layer + 0x54) = *(f32 *)(layer + 0x40) * frequency; }
            }
            if (((ChannelUpdateFlags *)updates)->volume || updateVolume) {
                if (((LayerVolumeFlags *)(layer + 0xA))->ignoreVolume == 0) { *(f32 *)(layer + 0x50) = *(f32 *)(layer + 0x48); }
                else { *(f32 *)(layer + 0x50) = *(f32 *)(((u8 *)arg0) + 0x38) * *(f32 *)(layer + 0x48); }
            }
            if (((ChannelUpdateFlags *)updates)->pan) {
                if (((LayerPanFlags *)(layer + 0xB))->ignorePan == 0) { *(f32 *)(layer + 0x50) = (f32)(u32)layer[6]; }
                else { layer[7] = (layer[6] * (128 - ((u8 *)arg0)[0xB]) + *(s32 *)(((u8 *)arg0) + 0x34)) >> 7; }
            }
        }
    }
    ((u8 *)arg0)[1] = 0;
}

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
            AudioChannel_Update(channel, ((*(u32 *)sequence << 5) >> 31), (sequence[0] & 1));
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

f32 AudioVibrato_Update(void *arg0) {
    typedef struct { u16 rateStart; u16 extentStart; u16 rateTarget; u16 extentTarget; u16 rateDelay; u16 extentDelay; u16 delay; } VibratoParams;
    typedef struct { VibratoParams *params; u32 phase; s16 *curve; f32 extent; f32 rate; s8 active; u8 pad15; u16 rateTimer; u16 extentTimer; u16 delay; } VibratoState;
    VibratoState *state = arg0;
    VibratoParams *params;
    s32 pitchChange;
    f32 extent;
    f32 result;
    params = state->params;
    if (state->delay != 0) {
        state->delay--;
        return 1.0f;
    }
    if (params != NULL) {
        if (state->extentTimer) {
            if (state->extentTimer == 1) { state->extent = (s32)params->extentTarget; }
            else { state->extent += ((s32)params->extentTarget - state->extent) / (s32)state->extentTimer; }
            state->extentTimer--;
        } else if (params->extentTarget != (s32)state->extent) {
            if ((state->extentTimer = params->extentDelay) == 0) { state->extent = (s32)params->extentTarget; }
        }
        if (state->rateTimer) {
            if (state->rateTimer == 1) { state->rate = (s32)params->rateTarget; }
            else { state->rate += ((s32)params->rateTarget - state->rate) / (s32)state->rateTimer; }
            state->rateTimer--;
        } else if (params->rateTarget != (s32)state->rate) {
            if ((state->rateTimer = params->rateDelay) == 0) { state->rate = (s32)params->rateTarget; }
        }
    }
    if (state->extent == 0.0f) { return 1.0f; }
    pitchChange = func_8001BA84(arg0);
    extent = state->extent / 4096.0f;
    result = 65536.0f / (65536.0f + pitchChange * extent);
    return result;
}

extern f32 func_8001BA28();
void func_8001BCA4(u8 *arg0) {
    u8 *state;
    state = arg0;
    if (state[0x80] != 0) {
        *(f32 *)(state + 0x38) = func_8001BA28(state + 0x80);
    }
    if (state[0xA0] != 0) {
        *(f32 *)(state + 0x3C) = AudioVibrato_Update(state + 0x8C);
    }
}

void AudioVibrato_Init(void *arg0) {
    typedef struct { u16 rateStart; u16 extentStart; u16 rateTarget; u16 extentTarget; u16 rateDelay; u16 extentDelay; u16 delay; } NoteVibratoParams;
    typedef struct { NoteVibratoParams *params; u32 phase; s16 *curve; f32 extent; f32 rate; s8 active; u8 pad15; u16 rateTimer; u16 extentTimer; u16 delay; } NoteVibratoState;
    typedef struct { u8 pad0[8]; u32 reserved:19; u32 channelVibrato:1; u32 tail:12; u8 padC[0x54]; u8 *channel; } NoteVibratoLayer;
    typedef struct { u8 priority; u8 pad1[3]; u8 state; u8 pad5[7]; f32 vibratoScale; void *previous; NoteVibratoLayer *parent; void *wanted; } NoteVibratoPlayback;
    typedef struct { u8 pad0[0x30]; NoteVibratoPlayback playback; u8 pad4C[0x40]; NoteVibratoState vibrato; } NoteVibratoOwner;

    NoteVibratoOwner *note = arg0;
    NoteVibratoPlayback *playback;
    NoteVibratoState *vibrato;
    NoteVibratoParams *params;
    note->vibrato.active = 1;
    note->vibrato.curve = D_8008E778;
    playback = &note->playback;
    vibrato = &note->vibrato;
    if (playback->parent->channelVibrato == 1) {
        vibrato->params = (NoteVibratoParams *)(playback->parent->channel + 0x14);
    } else {
        vibrato->params = (NoteVibratoParams *)((u8 *)playback->parent + 0xC);
    }
    params = vibrato->params;
    if ((vibrato->extentTimer = params->extentDelay) == 0) {
        vibrato->extent = (s32)params->extentTarget;
    } else { vibrato->extent = (s32)params->extentStart; }
    if ((vibrato->rateTimer = params->rateDelay) == 0) {
        vibrato->rate = (s32)params->rateTarget;
    } else { vibrato->rate = (s32)params->rateStart; }
    playback->vibratoScale = 1.0f;
    vibrato->phase = 0;
    vibrato->delay = params->delay;
}

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
