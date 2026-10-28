#include "global.h"


#ifdef VERSION_US
extern u8 D_8011FA5C[];
extern u8 D_8011F9DC[];
extern u8 D_8011BE90[];
extern u8 D_80121F44[];
extern void func_8001ED64();
extern void AudioSequence_Update(u8 *);
extern void func_80019DE4(void);
extern void func_8001C744(void *, s32);
extern s32 func_8001A308(s32, s32);
extern u8 D_8008FB90[];
extern u8 func_8001CC3C(u8 **);
extern s16 func_8001CC50(u8 **);
s32 func_8001C1C0(u8 **arg0, u8 arg1) {
    u8 value;
    u8 bits;
    s32 result;

    value = D_8008FB90[arg1];
    result = 0;
    bits = value & 3;
    if (bits == 1) {
        if (!(value & 0x80)) {
            result = func_8001CC3C(arg0) & 0xFFFF;
        } else {
            result = func_8001CC50(arg0) & 0xFFFF;
        }
    }
    return result;
}

extern u32 func_8001CC88(u8 **);
typedef struct {
    u8 *pc;
    u8 *stack[4];
    u8 remaining_loop_iterations[4];
    u8 depth;
    s8 value;
} AudioScriptState;
// Same code as Majora's Mask AudioScript_HandleScriptFlowControl (src/audio/lib/seqplayer.c),
// except that the delay opcodes are swapped: here 0xFD reads a delay and 0xFE delays one frame
// (jtbl_800A1FD0 entries 11 and 12).
s32 func_8001C228(u8 *player, AudioScriptState *state, s32 cmd, s32 cmd_arg) {
    u32 depth;

    switch (cmd) {
        case 0xFF: // End script, or return from a call.
            if (state->depth == 0) {
                return -1;
            }
            state->pc = state->stack[--state->depth];
            break;

        case 0xFD: // Delay by a compressed u16 frame count.
            return func_8001CC88(&state->pc);

        case 0xFE: // Delay one frame.
            return 1;

        case 0xFC: // Call.
            state->stack[depth = state->depth++] = state->pc;
            state->pc = *(u8 **) (player + 0x18) + (u16) cmd_arg;
            break;

        case 0xF8: // Loop start.
            state->remaining_loop_iterations[depth = state->depth] = cmd_arg;
            state->stack[state->depth++] = state->pc;
            break;

        case 0xF7: // Loop end.
            state->remaining_loop_iterations[state->depth - 1]--;
            if (state->remaining_loop_iterations[state->depth - 1] != 0) {
                state->pc = state->stack[state->depth - 1];
            } else {
                state->depth--;
            }
            break;

        case 0xF6: // Break out of a loop.
            state->depth--;
            break;

        case 0xF5: // Branch if value >= 0.
        case 0xF9: // Branch if value < 0.
        case 0xFA: // Branch if value == 0.
        case 0xFB: // Jump.
            if ((cmd == 0xFA) && (state->value != 0)) {
                break;
            }
            if ((cmd == 0xF9) && (state->value >= 0)) {
                break;
            }
            if ((cmd == 0xF5) && (state->value < 0)) {
                break;
            }
            state->pc = *(u8 **) (player + 0x18) + (u16) cmd_arg;
            break;

        case 0xF2: // Relative branch if value < 0.
        case 0xF3: // Relative branch if value == 0.
        case 0xF4: // Relative jump.
            if ((cmd == 0xF3) && (state->value != 0)) {
                break;
            }
            if ((cmd == 0xF2) && (state->value >= 0)) {
                break;
            }
            state->pc += (s8) (cmd_arg & 0xFF);
            break;
    }

    return 0;
}

extern void func_8001A9E4(void *);
extern u8 D_8008F1B4[];
// Same code as Majora's Mask AudioScript_InitSequenceChannel (src/audio/lib/seqplayer.c).
void func_8001C404(s32 arg0) {
    typedef struct {
        u8 enabled:1; u8 finished:1; u8 stop_script:1; u8 muted:1;
        u8 has_instrument:1; u8 stereo_headset_effects:1; u8 large_notes:1; u8 unused:1;
    } ChannelFlags;
    u8 *channel = (u8 *) arg0;
    s32 i;

    if (channel == D_8011BE90 + 0x5F4C) {
        return;
    }

    ((ChannelFlags *) channel)->enabled = 0;
    ((ChannelFlags *) channel)->finished = 0;
    ((ChannelFlags *) channel)->stop_script = 0;
    ((ChannelFlags *) channel)->muted = 0;
    ((ChannelFlags *) channel)->has_instrument = 0;
    ((ChannelFlags *) channel)->stereo_headset_effects = 0;
    *(s16 *) (channel + 0x2A) = 0;
    ((ChannelFlags *) channel)->large_notes = 0;
    channel[0x9] = 0;
    channel[0xE0] = 0;
    channel[0x1] = 0xFF;
    channel[0x84] = 0;
    channel[0xA] = 64;
    channel[0xB] = 128;
    channel[0x10] = 0xFF;
    channel[0xD] = 0;
    channel[0xE] = 0;
    *(void **) (channel + 0x44) = NULL;
    channel[0x8] = 0;
    channel[0x4] = 0;
    channel[0xC] = 0;
    channel[0x5] = 3;
    channel[0x6] = 1;
    *(s16 *) (channel + 0x22) = 0;
    *(u8 **) (channel + 0x8C) = D_8008F1B4;
    channel[0x88] = 240;
    channel[0x89] = 0;
    *(u16 *) (channel + 0x18) = 0x800;
    *(u16 *) (channel + 0x14) = 0x800;
    *(u16 *) (channel + 0x1A) = 0;
    *(u16 *) (channel + 0x16) = 0;
    *(u16 *) (channel + 0x1C) = 0;
    *(u16 *) (channel + 0x1E) = 0;
    *(u16 *) (channel + 0x20) = 0;
    *(void **) (channel + 0xDC) = NULL;
    *(u16 *) (channel + 0x24) = 0;
    channel[0xF] = 0;
    *(f32 *) (channel + 0x30) = 1.0f;
    *(f32 *) (channel + 0x2C) = 1.0f;
    *(f32 *) (channel + 0x3C) = 1.0f;

    for (i = 0; i < 8; i++) {
        ((s8 *) (channel + 0xD0))[i] = -1;
    }

    ((ChannelFlags *) channel)->unused = 0;
    func_8001A9E4(channel + 0x90);
    *(s32 *) (channel + 0xE4) = 0;
    *(s32 *) (channel + 0xE8) = 0;
    *(void **) (channel + 0xD8) = NULL;
}

extern u8 D_80121EF4[];
extern s32 func_8001CB5C(void *);
extern void func_8001A994(void *);
typedef struct AudioLayerAllocateChannel AudioLayerAllocateChannel;
typedef struct { u8 release; u8 unknown01[3]; void *envelope; } AudioLayerAllocateAdsr;
typedef struct { u8 enabled:1; u8 finished:1; u8 stop:1; u8 continuous:1; u8 bit27:1; u8 bit26:1; u8 bit25:1; u8 bit24:1; } AudioLayerAllocateFlags;
typedef struct {
    AudioLayerAllocateFlags flags; u8 status; u8 instrument_id; u8 duration;
    u8 unknown04[2]; u8 pan; u8 unknown07; u8 value08; u8 policy;
    u16 unknown0A; u16 unknown0C; u16 unknown0E; u16 unknown10;
    u16 unknown12; u16 unknown14; u16 unknown16; u16 unknown18;
    s16 delay; s16 gate; s16 unknown1E; u8 unknown20[2]; s16 transposition;
    u8 unknown24[4]; AudioLayerAllocateAdsr adsr; u8 portamento; u8 unknown31[11];
    void *note; f32 frequency; f32 frequency_multiplier; f32 velocity;
    u8 unknown4C[12]; void *instrument; u8 unknown5C[4]; AudioLayerAllocateChannel *channel;
    u8 unknown64[24]; u8 script_depth;
} AudioLayerAllocateRecord;
struct AudioLayerAllocateChannel { u8 unknown00[4]; u8 policy; u8 unknown05[79]; AudioLayerAllocateRecord *layers[6]; u8 unknown6C[28]; AudioLayerAllocateAdsr adsr; };
s32 AudioChannel_AllocateLayer(AudioLayerAllocateChannel *channel, s32 index) {
    AudioLayerAllocateRecord *layer;
    if (channel->layers[index] == NULL) {
        AudioLayerAllocateRecord *layer;
        layer = (AudioLayerAllocateRecord *)func_8001CB5C(D_80121EF4);
        channel->layers[index] = layer;
        if (layer == NULL) { channel->layers[index] = NULL; return -1; }
    } else {
        func_8001A994(channel->layers[index]);
    }
    layer = channel->layers[index];
    layer->channel = channel;
    layer->adsr = channel->adsr;
    layer->adsr.release = 0;
    layer->policy = channel->policy;
    layer->flags.enabled = 1;
    layer->flags.finished = 0;
    layer->flags.stop = 0;
    layer->flags.continuous = 0;
    layer->flags.bit27 = 0;
    layer->flags.bit26 = 0;
    layer->flags.bit25 = 0;
    layer->flags.bit24 = 0;
    layer->status = 0;
    layer->portamento = 0;
    layer->script_depth = 0;
    layer->duration = 0x80;
    layer->value08 = 0x80;
    layer->pan = 0x40;
    layer->transposition = 0;
    layer->delay = 0;
    layer->gate = 0;
    layer->unknown1E = 0;
    layer->note = NULL;
    layer->instrument = NULL;
    layer->instrument_id = 0xFF;
    layer->unknown0A = 0xFFFF;
    layer->unknown10 = 0x800;
    layer->unknown0C = 0x800;
    layer->unknown12 = 0;
    layer->unknown0E = 0;
    layer->unknown14 = 0;
    layer->unknown16 = 0;
    layer->unknown18 = 0;
    layer->frequency = 1.0f;
    layer->frequency_multiplier = 1.0f;
    layer->velocity = 0.0f;
    return 0;
}

typedef struct { u8 unknown[80]; void *player; } AudioChannelPrefix;
extern AudioChannelPrefix D_80121DDC;
extern void func_8001A994(void *);
extern void func_8001A9B4(void *);
typedef struct { u8 enabled:1; u8 finished:1; u8 low:6; } AudioLayerDisableFlags;
typedef struct { AudioLayerDisableFlags flags; u8 unknown01[95]; AudioChannelPrefix *channel; } AudioLayerDisablePrefix;
void AudioLayer_Disable(AudioLayerDisablePrefix *layer) {
    if (layer != NULL) {
        if (layer->channel != &D_80121DDC && (((*(u32 *)layer->channel->player << 1) >> 31) == 1)) {
            func_8001A9B4(layer);
        } else {
            func_8001A994(layer);
        }
        layer->flags.enabled = 0;
        layer->flags.finished = 1;
    }
}

extern u8 D_80121EF4[];
extern void func_8001CB1C();
extern void AudioLayer_Disable();
void func_8001C744(void *arg0, s32 arg1) {
    s32 temp_a2;
    temp_a2 = *(s32 *)((u8 *)arg0 + (arg1 << 2) + 0x54);
    if (temp_a2 != 0) {
        func_8001CB1C(D_80121EF4, (void *)(u32)(temp_a2 + 0x80));
        AudioLayer_Disable(temp_a2);
        *(s32 *)((u8 *)arg0 + (arg1 << 2) + 0x54) = 0;
    }
}

void func_8001C744();
void func_8001AAD8();
void func_8001C794(s32 arg0)
{
  u32 new_var;
  s32 i;
  i = 0;
  *((u8 *) ((u32) arg0)) = (u8) (((*((u8 *) (new_var = (u32) arg0))) & 0xFFFFu) | 0x40);
  do
  {
    func_8001C744((void *) ((u32) arg0), i);
    i++;
  }
  while (i != 6);
  func_8001AAD8((void *) ((u32) (arg0 + 0x90)));
  *((u8 *) ((u32) ((arg0 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu))) = (u8) ((*((u8 *) ((u32) arg0))) & 0xFF7F);
}

void func_8001C804(void *arg0, u16 arg1) {
    s32 i;
    u8 *dst;

    i = 0;
    do {
        if (arg1 & 1) {
            dst = *(u8 **)((u8 *)arg0 + (i * 4) + 0x38);
            dst[7] = *((u8 *)arg0 + 5);
            dst[3] = *((u8 *)arg0 + 3);
            dst[2] = *((u8 *)arg0 + 2);
        }
        arg1 = (arg1 >> 1) & 0xFFFF;
        if (arg1 & 1) {
            dst = *(u8 **)((u8 *)arg0 + (i * 4) + 0x3C);
            dst[7] = *((u8 *)arg0 + 5);
            dst[3] = *((u8 *)arg0 + 3);
            dst[2] = *((u8 *)arg0 + 2);
        }
        arg1 = (arg1 >> 1) & 0xFFFF;
        if (arg1 & 1) {
            dst = *(u8 **)((u8 *)arg0 + (i * 4) + 0x40);
            dst[7] = *((u8 *)arg0 + 5);
            dst[3] = *((u8 *)arg0 + 3);
            dst[2] = *((u8 *)arg0 + 2);
        }
        arg1 = (arg1 >> 1) & 0xFFFF;
        if (arg1 & 1) {
            dst = *(u8 **)((u8 *)arg0 + (i * 4) + 0x44);
            dst[7] = *((u8 *)arg0 + 5);
            dst[3] = *((u8 *)arg0 + 3);
            dst[2] = *((u8 *)arg0 + 2);
        }
        i += 4;
        arg1 = (arg1 >> 1) & 0xFFFF;
    } while (i != 0x10);
}

extern AudioChannelPrefix D_80121DDC;
extern void func_8001C794(s32);
void func_8001C8FC(void *arg0, s32 arg1)
{
  s32 i;
  u8 *entry;
  s32 value;
  s32 different;
  i = ((s32) ((u32) (&D_80121DDC))) * 0;
  entry = (u8 *) arg0;
  do
  {
    value = *((s32 *) (entry + 0x38));
    different = value != ((s32) ((u32) (&D_80121DDC)));
    if (different == 1)
    {
      func_8001C794(value);
    }
    i += 4;
    entry += 4;
  }
  while (i != 0x40);
}

void AudioChannel_StartScript(u8 *player, u8 index, u8 *script) {
    typedef struct { u8 enabled:1; u8 finished:1; u8 low:6; } ChannelFlags;
    u8 *channel;
    s32 i;
    channel = ((u8 **)(player + 0x38))[index];
    channel[0x84] = 0;
    *(u8 **)(channel + 0x6C) = script;
    ((ChannelFlags *)channel)->enabled = 1;
    ((ChannelFlags *)channel)->finished = 0;
    *(s16 *)(channel + 0x22) = 0;
    for (i = 0; i != 6; i++) {
        if (*(u8 **)(channel + 0x54 + i * 4) != NULL) { func_8001C744(channel, i); }
    }
}

extern void AudioSequence_Disable(u8 *);
void func_8001CA14(u8 *arg0) {
    *arg0 = ((*arg0) & 0xFF) | 0x40;
    AudioSequence_Disable(arg0);
}

extern void func_8001C8FC(void *, s32);
extern void AudioNotePool_Clear(void *);
extern s32 func_80014208(s32);
extern void func_80014328(s32, s32);
extern s32 func_80014190(s32);
extern void func_800142F8(s32, s32);
extern void func_800102BC(s32);
extern u8 D_8011BE90[];
void AudioSequence_Disable(u8 *player) {
    typedef struct { u8 enabled:1; u8 finished:1; u8 low:6; } PlayerFlags;
    s32 was_finished;
    was_finished = ((*(u32 *)player << 1) >> 31);
    func_8001C8FC(player, 0xFFFF);
    AudioNotePool_Clear(player + 0x9C);
    if ((*(u32 *)player >> 31) != 0) {
        ((PlayerFlags *)player)->enabled = 0;
        ((PlayerFlags *)player)->finished = 1;
        if (func_80014208(player[4])) { func_80014328(player[4], 3); }
        if (func_80014190(player[5])) {
            func_800142F8(player[5], 4);
            if (was_finished) { func_800102BC(player[5]); }
        }
        if (player[5] == *(s16 *)(D_8011BE90 + 0x2FC2)) {
            *(s32 *)(D_8011BE90 + 0x2FA4) = 1;
        } else if (player[5] == *(s16 *)(D_8011BE90 + 0x2FCE)) {
            *(s32 *)(D_8011BE90 + 0x2FA4) = 0;
        }
    }
}

void func_8001CB1C(void *arg0, void *arg1)
{
  if ((*((void **) (((u8 *) arg1) + 0))) == 0)
  {
    *((void **) (((u8 *) (*((void **) (((u8 *) arg0) + 0)))) + 4)) = arg1;
    *((void **) (((u8 *) arg1) + 0)) = *((void **) (((u8 *) arg0) + 0));
    *((void **) (((u8 *) arg1) + 4)) = arg0;
    *((void **) (((u8 *) arg0) + 0)) = arg1;
    *((s32 *) (((u8 *) arg0) + 8)) = (*((s32 *) (((u8 *) arg0) + 8))) + 1;
    *((s32 *) (((u8 *) arg1) + 0xC)) = *((s32 *) (((u8 *) arg0) + 0xC));
  }
}

s32 func_8001CB5C(void *arg0) {
    void *node = *(void **)arg0;
    if (node == arg0) return 0;
    *(void **)((u8 *)*(void **)node + 4) = arg0;
    *(void **)arg0 = *(void **)node;
    *(void **)node = NULL;
    *(s32 *)((u8 *)arg0 + 8) = *(s32 *)((u8 *)arg0 + 8) - 1;
    return *(s32 *)((u8 *)node + 8);
}

void AudioLayerPool_Init(void) {
    s32 i;
    *(u8 **)(D_8011BE90 + 0x6064) = D_80121EF4;
    *(u8 **)(D_8011BE90 + 0x6068) = D_80121EF4;
    *(s32 *)(D_8011BE90 + 0x606C) = 0;
    *(void **)(D_8011BE90 + 0x6070) = NULL;
    i = 0;
    do {
        *(u8 **)(D_8011BE90 + 0x3BD4 + i * 144) = D_8011F9DC + i * 144;
        *(void **)(D_8011BE90 + 0x3BCC + i * 144) = NULL;
        func_8001CB1C(D_80121EF4, D_8011FA5C + i * 144);
        i += 1;
    } while (i != 64);
}

u8 func_8001CC3C(u8 **arg0) { u8 result = **arg0; (*arg0)++; return result; }

s16 func_8001CC50(u8 **arg0) {
    s16 value;
    value = (*(*arg0)) << 8;
    (*arg0)++;
    value = (0, (*(*arg0)) | value); (*arg0)++;
    return value;
}

u32 func_8001CC88(u8 **arg0) {
    struct { u16 value; } result;
    result.value = *(*arg0)++;
    if (result.value & 0x80) {
        result.value <<= 8;
        result.value &= 0x7F00;
        result.value = *(*arg0)++ | result.value;
    }
    return result.value;
}

extern void func_8001A994(void *);
typedef struct AudioLayerPreparePrefix AudioLayerPreparePrefix;
extern void AudioLayer_PrepareNote(AudioLayerPreparePrefix *);
extern s32 func_8001CF5C(void *);
extern s32 func_8001DA54();
extern s32 func_8001D340(void *, s32);
struct SequenceLayer;
extern s32 func_8001CE70(struct SequenceLayer *, s32);
typedef struct { u32 enabled:1; u32 finished:1; u32 stop:1; u32 continuous_notes:1; u32 low:28; } AudioLayerUpdateWordFlags;
typedef struct { AudioLayerUpdateWordFlags flags; u8 unknown04[22]; s16 delay; s16 gate; u8 unknown1E[30]; void *note; } AudioLayerUpdatePrefix;
void AudioLayer_UpdateScript(AudioLayerUpdatePrefix *layer) {
    typedef struct { u8 high:2; u8 stop:1; u8 low:5; } LayerStopFlags;
    s32 command;
    if (layer->flags.enabled != 0) {
        if (layer->delay >= 2) {
            layer->delay--;
            if (layer->flags.stop == 0 && layer->delay <= layer->gate) {
                func_8001A994(layer);
                ((LayerStopFlags *)layer)->stop = 1;
            }
        } else {
            AudioLayer_PrepareNote((AudioLayerPreparePrefix *)layer);
            do {
                command = func_8001CF5C(layer);
                if (command == -1) { return; }
                command = func_8001DA54(layer, command);
            } while (command == -1 && layer->delay == 0);
            if (command != -1) { command = func_8001D340(layer, command); }
            if (command != -1) { func_8001CE70((struct SequenceLayer *)layer, command); }
            if (layer->flags.stop == 1 && (layer->note != NULL || layer->flags.continuous_notes != 0)) {
                func_8001A994(layer);
            }
        }
    }
}

extern void func_8001A994(void *);
typedef struct { u32 enabled:1; u32 finished:1; u32 stop:1; u32 continuous_notes:1; u32 low:28; } AudioLayerPrepareFlags;
typedef struct { u8 unknown[72]; AudioLayerPreparePrefix *previous_layer; } AudioNotePreviousPrefix;
struct AudioLayerPreparePrefix { AudioLayerPrepareFlags flags; u8 unknown04[44]; u8 portamento; u8 unknown31[11]; AudioNotePreviousPrefix *note; };
void AudioLayer_PrepareNote(AudioLayerPreparePrefix *layer) {
    typedef struct { u8 high:7; u8 bit0:1; } LayerLowFlags;
    s32 mode;
    if (layer->flags.continuous_notes == 0) {
        func_8001A994(layer);
    } else {
        if (layer->note != NULL && layer->note->previous_layer == layer) { func_8001A994(layer); }
    }
    mode = layer->portamento & ~0x80;
    if (mode == 1 || mode == 2) { layer->portamento = 0; }
    ((LayerLowFlags *)layer)->bit0 = 1;
}

// Sequence player, channel and layer records, laid out like Majora's Mask
// SequencePlayer, SequenceChannel and SequenceLayer (include/audio/seqplayer.h),
// except that GS's channel has two more bytes at 0x12 and six layers
// (func_8001C404 and func_8001C794 use the shifted offsets and the layer count).
// The players are the 0x160-byte records at D_8011BE90 + 0x346C that
// Audio_UpdateSequencesAndNotes steps. Only the members that the script
// interpreters below use are typed; pointers to notes, instruments and samples
// are left as u8 *.
typedef struct {
    /* 0x0 */ u16 vibratoRateStart;
    /* 0x2 */ u16 vibratoDepthStart;
    /* 0x4 */ u16 vibratoRateTarget;
    /* 0x6 */ u16 vibratoDepthTarget;
    /* 0x8 */ u16 vibratoRateChangeDelay;
    /* 0xA */ u16 vibratoDepthChangeDelay;
    /* 0xC */ u16 vibratoDelay;
} VibratoSubStruct; // size = 0xE

typedef struct {
    /* 0x0 */ u8 decayIndex;
    /* 0x1 */ u8 sustain;
    /* 0x4 */ u8 *envelope;
} AdsrSettings; // size = 0x8

typedef struct {
    /* 0x0 */ u8 mode;
    /* 0x2 */ u16 cur;
    /* 0x4 */ u16 speed;
    /* 0x8 */ f32 extent;
} Portamento; // size = 0xC

typedef struct AudioListItem {
    /* 0x0 */ struct AudioListItem *prev;
    /* 0x4 */ struct AudioListItem *next;
    /* 0x8 */ void *value;
    /* 0xC */ void *pool;
} AudioListItem; // size = 0x10

typedef struct {
    /* 0x00 */ AudioListItem disabled;
    /* 0x10 */ AudioListItem decaying;
    /* 0x20 */ AudioListItem releasing;
    /* 0x30 */ AudioListItem active;
} NotePool; // size = 0x40

typedef union {
    struct {
        u8 unused : 2;
        u8 type : 2;
        u8 strongRight : 1;
        u8 strongLeft : 1;
        u8 strongReverbRight : 1;
        u8 strongReverbLeft : 1;
    } s;
    u8 asByte;
} StereoData; // size = 0x1

typedef struct SequencePlayer {
    /* 0x000 */ u8 enabled : 1;
    /* 0x000 */ u8 finished : 1;
    /* 0x000 */ u8 muted : 1;
    /* 0x000 */ u8 seqDmaInProgress : 1;
    /* 0x000 */ u8 fontDmaInProgress : 1;
    /* 0x000 */ u8 recalculateVolume : 1;
    /* 0x000 */ u8 stopScript : 1;
    /* 0x000 */ u8 applyBend : 1;
    /* 0x001 */ u8 state;
    /* 0x002 */ u8 noteAllocPolicy;
    /* 0x003 */ u8 muteFlags;
    /* 0x004 */ u8 seqId;
    /* 0x005 */ u8 defaultFont;
    /* 0x006 */ u8 unk_06[1];
    /* 0x007 */ s8 playerIndex;
    /* 0x008 */ u16 tempo;
    /* 0x00A */ u16 tempoAcc;
    /* 0x00C */ s16 tempoChange;
    /* 0x00E */ s16 transposition;
    /* 0x010 */ u16 delay;
    /* 0x012 */ u16 fadeTimer;
    /* 0x014 */ u16 storedFadeTimer;
    /* 0x016 */ u16 unk_16;
    /* 0x018 */ u8 *seqData;
    /* 0x01C */ f32 fadeVolume;
    /* 0x020 */ f32 fadeVelocity;
    /* 0x024 */ f32 volume;
    /* 0x028 */ f32 muteVolumeScale;
    /* 0x02C */ f32 fadeVolumeScale;
    /* 0x030 */ f32 appliedFadeVolume;
    /* 0x034 */ f32 bend;
    /* 0x038 */ struct SequenceChannel *channels[16];
    /* 0x078 */ AudioScriptState scriptState;
    /* 0x094 */ u8 *shortNoteVelocityTable;
    /* 0x098 */ u8 *shortNoteGateTimeTable;
    /* 0x09C */ NotePool notePool;
    /* 0x0DC */ s32 skipTicks;
    /* 0x0E0 */ u32 scriptCounter;
    /* 0x0E4 */ u8 unk_E4[0x74];
    /* 0x158 */ s8 seqScriptIO[8];
} SequencePlayer; // size = 0x160

typedef struct SequenceChannel {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 stopScript : 1;
    /* 0x00 */ u8 muted : 1;
    /* 0x00 */ u8 hasInstrument : 1;
    /* 0x00 */ u8 stereoHeadsetEffects : 1;
    /* 0x00 */ u8 largeNotes : 1;
    /* 0x00 */ u8 unused : 1;
    union {
        struct {
            /* 0x01 */ u8 freqScale : 1;
            /* 0x01 */ u8 volume : 1;
            /* 0x01 */ u8 pan : 1;
        } s;
        /* 0x01 */ u8 asByte;
    } changes;
    /* 0x02 */ u8 noteAllocPolicy;
    /* 0x03 */ u8 muteFlags;
    /* 0x04 */ u8 targetReverbVol;
    /* 0x05 */ u8 notePriority;
    /* 0x06 */ u8 someOtherPriority;
    /* 0x07 */ u8 fontId;
    /* 0x08 */ u8 reverbIndex;
    /* 0x09 */ u8 bookOffset;
    /* 0x0A */ u8 newPan;
    /* 0x0B */ u8 panChannelWeight;
    /* 0x0C */ u8 gain;
    /* 0x0D */ u8 velocityRandomVariance;
    /* 0x0E */ u8 gateTimeRandomVariance;
    /* 0x0F */ u8 combFilterSize;
    /* 0x10 */ u8 surroundEffectIndex;
    /* 0x11 */ u8 channelIndex;
    /* 0x12 */ u8 unk_12[2];
    /* 0x14 */ VibratoSubStruct vibrato;
    /* 0x22 */ u16 delay;
    /* 0x24 */ u16 combFilterGain;
    /* 0x26 */ u16 unk_22;
    /* 0x28 */ s16 instOrWave;
    /* 0x2A */ s16 transposition;
    /* 0x2C */ f32 volumeScale;
    /* 0x30 */ f32 volume;
    /* 0x34 */ s32 pan;
    /* 0x38 */ f32 appliedVolume;
    /* 0x3C */ f32 freqScale;
    /* 0x40 */ u8 (*dynTable)[][2];
    /* 0x44 */ u8 *noteUnused;
    /* 0x48 */ struct SequenceLayer *layerUnused;
    /* 0x4C */ u8 *instrument;
    /* 0x50 */ SequencePlayer *seqPlayer;
    /* 0x54 */ struct SequenceLayer *layers[6];
    /* 0x6C */ AudioScriptState scriptState;
    /* 0x88 */ AdsrSettings adsr;
    /* 0x90 */ NotePool notePool;
    /* 0xD0 */ s8 seqScriptIO[8];
    /* 0xD8 */ u8 *sfxState;
    /* 0xDC */ s16 *filter;
    /* 0xE0 */ StereoData stereoData;
    /* 0xE4 */ s32 startSamplePos;
    /* 0xE8 */ s32 unk_E0;
} SequenceChannel; // size = 0xEC

typedef struct SequenceLayer {
    /* 0x00 */ u32 enabled : 1;
    /* 0x00 */ u32 finished : 1;
    /* 0x00 */ u32 muted : 1;
    /* 0x00 */ u32 continuousNotes : 1;
    /* 0x00 */ u32 bit3 : 1;
    /* 0x00 */ u32 ignoreDrumPan : 1;
    /* 0x00 */ u32 bit1 : 1;
    /* 0x00 */ u32 notePropertiesNeedInit : 1;
    /* 0x01 */ StereoData stereoData;
    /* 0x02 */ u8 instOrWave;
    /* 0x03 */ u8 gateTime;
    /* 0x04 */ u8 semitone;
    /* 0x05 */ u8 portamentoTargetNote;
    /* 0x06 */ u8 pan;
    /* 0x07 */ u8 notePan;
    /* 0x08 */ u8 surroundEffectIndex;
    /* 0x09 */ u8 targetReverbVol;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ VibratoSubStruct vibrato;
    /* 0x1A */ s16 delay;
    /* 0x1C */ s16 gateDelay;
    /* 0x1E */ s16 delay2;
    /* 0x20 */ u16 portamentoTime;
    /* 0x22 */ s16 transposition;
    /* 0x24 */ s16 shortNoteDefaultDelay;
    /* 0x26 */ s16 lastDelay;
    /* 0x28 */ AdsrSettings adsr;
    /* 0x30 */ Portamento portamento;
    /* 0x3C */ u8 *note;
    /* 0x40 */ f32 freqScale;
    /* 0x44 */ f32 bend;
    /* 0x48 */ f32 velocitySquare2;
    /* 0x4C */ f32 velocitySquare;
    /* 0x50 */ f32 noteVelocity;
    /* 0x54 */ f32 noteFreqScale;
    /* 0x58 */ u8 *instrument;
    /* 0x5C */ u8 *tunedSample;
    /* 0x60 */ SequenceChannel *channel;
    /* 0x64 */ AudioScriptState scriptState;
    /* 0x80 */ AudioListItem listItem;
} SequenceLayer; // size = 0x90

extern void *AudioVoice_AcquireForRequest(u8 *request);
extern void AudioVibrato_Init(void *);
extern void func_8001BDF0(u8 *);

// Same code as Ocarina of Time AudioSeq_SeqLayerProcessScriptStep5 (src/code/audio_seqplayer.c),
// without the synthetic-wave reinit. A note's parent layer is at note + 0x44.
s32 func_8001CE70(SequenceLayer *layer, s32 sameSound) {
    u8 *note;

    if ((layer->continuousNotes == 1) && (layer->bit1 == 1)) {
        return 0;
    }

    if ((layer->continuousNotes == 1) && (layer->note != NULL) && layer->bit3 && (sameSound == 1U) &&
        (*(void **)(layer->note + 0x44) == layer)) {
        // OoT reinitializes a synthetic wave here; GS has no such call.
    } else {
        if (sameSound == 0) {
            func_8001A994(layer);
        }
        layer->note = AudioVoice_AcquireForRequest((u8 *)layer);
        if ((layer->note != NULL) && (*(void **)(layer->note + 0x44) == layer)) {
            AudioVibrato_Init(layer->note);
        }
    }

    if ((layer->note != NULL) && (*(void **)(layer->note + 0x44) == layer)) {
        note = layer->note;
        func_8001BDF0(note);
    }
    return 0;
}

extern u8 AudioChannel_ResolveInstrument(u8 *channel, u8 program, u8 **out_instrument, u8 *adsr);
extern f32 D_8008EB94[];
// Same code as Majora's Mask AudioScript_SeqLayerProcessScriptStep2 (src/audio/lib/seqplayer.c).
s32 func_8001CF5C(void *arg0) {
    typedef struct {
        u8 enabled:1; u8 finished:1; u8 stop:1; u8 continuous_notes:1;
        u8 bit3:1; u8 ignore_drum_pan:1; u8 bit1:1; u8 bit0:1;
    } LayerFlags;
    u8 *layer = arg0;
    u8 *channel = *(u8 **) (layer + 0x60);
    u8 **state = (u8 **) (layer + 0x64);
    u8 *player = *(u8 **) (channel + 0x50);
    u8 cmd;
    u8 cmd_arg8;
    u16 cmd_arg16;
    u16 velocity;

    while (TRUE) {
        cmd = func_8001CC3C(state);

        // Note commands, handled by func_8001DA54 and later steps.
        if (cmd <= 0xC0) {
            return cmd;
        }

        // Control-flow commands.
        if (cmd >= 0xF2) {
            // func_8001C1C0 already masks its result to 16 bits.
            if (func_8001C228(player, (AudioScriptState *) state, cmd, func_8001C1C0(state, cmd)) == 0) {
                continue;
            }
            AudioLayer_Disable((AudioLayerDisablePrefix *) layer);
            return -1;
        }

        switch (cmd) {
            case 0xC1: // Set short-note velocity.
            case 0xCA: // Set pan.
                cmd_arg8 = *((*state)++);
                if (cmd == 0xC1) {
                    *(f32 *) (layer + 0x4C) = (cmd_arg8 * cmd_arg8) / (127.0f * 127.0f);
                } else {
                    layer[0x6] = cmd_arg8;
                }
                break;

            case 0xC9: // Set short-note gate time.
            case 0xC2: // Set transposition in semitones.
                cmd_arg8 = *((*state)++);
                if (cmd == 0xC9) {
                    layer[0x3] = cmd_arg8;
                } else {
                    *(s16 *) (layer + 0x22) = cmd_arg8;
                }
                break;

            case 0xC4: // Continuous notes on.
            case 0xC5: // Continuous notes off.
                if (cmd == 0xC4) {
                    ((LayerFlags *) layer)->continuous_notes = TRUE;
                } else {
                    ((LayerFlags *) layer)->continuous_notes = FALSE;
                }
                ((LayerFlags *) layer)->bit1 = FALSE;
                func_8001A994(layer);
                break;

            case 0xC3: // Set short-note default delay.
                cmd_arg16 = func_8001CC88(state);
                *(s16 *) (layer + 0x24) = cmd_arg16;
                break;

            case 0xC6: // Set instrument.
                cmd = func_8001CC3C(state);
                if (cmd >= 0x7E) {
                    if (cmd == 0x7E) {
                        layer[0x2] = 1;
                    } else if (cmd == 0x7F) {
                        layer[0x2] = 0;
                    } else {
                        layer[0x2] = cmd;
                        *(u8 **) (layer + 0x58) = NULL;
                    }

                    if (cmd == 0xFF) {
                        layer[0x28] = 0;
                    }
                } else {
                    if ((layer[0x2] = AudioChannel_ResolveInstrument(channel, cmd, (u8 **) (layer + 0x58),
                                                                     layer + 0x28)) == 0) {
                        layer[0x2] = 0xFF;
                    }
                }
                break;

            case 0xC7: // Enable portamento.
                layer[0x30] = func_8001CC3C(state);

                cmd = func_8001CC3C(state);
                cmd += *(s16 *) (channel + 0x2A);
                cmd += *(s16 *) (layer + 0x22);
                cmd += *(s16 *) (player + 0xE);

                if (cmd >= 0x80) {
                    cmd = 0;
                }

                layer[0x5] = cmd;

                // Bit 7 of the portamento mode selects a u8 time instead of a compressed u16.
                if (layer[0x30] & 0x80) {
                    *(s16 *) (layer + 0x20) = *((*state)++);
                    break;
                }

                cmd_arg16 = func_8001CC88(state);
                *(s16 *) (layer + 0x20) = cmd_arg16;
                break;

            case 0xC8: // Disable portamento.
                layer[0x30] = 0;
                break;

            case 0xCB: // Set envelope, then fall through to set the release rate.
                cmd_arg16 = func_8001CC50(state);
                *(u8 **) (layer + 0x2C) = *(u8 **) (player + 0x18) + cmd_arg16;
            case 0xCF: // Set release rate.
                layer[0x28] = func_8001CC3C(state);
                break;

            case 0xCC: // Ignore drum pan.
                ((LayerFlags *) layer)->ignore_drum_pan = TRUE;
                break;

            case 0xCD: // Set stereo effects.
                layer[0x1] = func_8001CC3C(state);
                break;

            case 0xCE: // Bend pitch.
                cmd_arg8 = func_8001CC3C(state);
                *(f32 *) (layer + 0x44) = D_8008EB94[(u8) (cmd_arg8 + 0x80)];
                break;

            case 0xF0:
                cmd_arg16 = func_8001CC50(state);
                *(u16 *) (layer + 0xA) &= (cmd_arg16 ^ 0xFFFF);
                break;

            case 0xF1:
                layer[0x8] = func_8001CC3C(state);
                break;

            default:
                switch (cmd & 0xF0) {
                    case 0xD0: // Set short-note velocity from the player's table.
                        velocity = (*(u8 **) (player + 0x94))[cmd & 0xF];
                        *(f32 *) (layer + 0x4C) = (velocity * velocity) / (127.0f * 127.0f);
                        break;

                    case 0xE0: // Set short-note gate time from the player's table.
                        layer[0x3] = (*(u8 **) (player + 0x98))[cmd & 0xF];
                        break;
                }
                break;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001D340.s")


// Close to Majora's Mask AudioScript_SeqLayerProcessScriptStep3 (src/audio/lib/seqplayer.c);
// GS does not check the channel's muted flag before the skip-ticks check.
// D_8011EB9C is the audio random value (D_8011BE90 + 0x2D0C).
extern u32 D_8011EB9C;
s32 func_8001DA54(SequenceLayer *layer, s32 cmd) {
    AudioScriptState *state = &layer->scriptState;
    u16 delay;
    s32 velocity;
    SequenceChannel *channel = layer->channel;
    SequencePlayer *seq_player = channel->seqPlayer;
    s32 int_delta;
    f32 float_delta;

    if (cmd == 0xC0) { // Layer delay.
        layer->delay = func_8001CC88(&state->pc);
        layer->muted = TRUE;
        layer->bit1 = FALSE;
        return -1;
    }

    layer->muted = FALSE;

    if (channel->largeNotes == TRUE) {
        switch (cmd & 0xC0) {
            case 0x00: // Large note with delay, velocity and gate time.
                delay = func_8001CC88(&state->pc);
                velocity = *(state->pc++);
                layer->gateTime = *(state->pc++);
                layer->lastDelay = delay;
                break;

            case 0x40: // Large note with delay and velocity.
                delay = func_8001CC88(&state->pc);
                velocity = *(state->pc++);
                layer->gateTime = 0;
                layer->lastDelay = delay;
                break;

            case 0x80: // Large note with velocity and gate time.
                delay = layer->lastDelay;
                velocity = *(state->pc++);
                layer->gateTime = *(state->pc++);
                break;
        }

        if ((velocity > 0x7F) || (velocity < 0)) {
            velocity = 0x7F;
        }
        layer->velocitySquare = ((f32)velocity * (f32)velocity) / (127.0f * 127.0f);
        cmd -= (cmd & 0xC0);
    } else {
        switch (cmd & 0xC0) {
            case 0x00: // Small note with a delay.
                delay = func_8001CC88(&state->pc);
                layer->lastDelay = delay;
                break;

            case 0x40: // Small note with the default delay.
                delay = layer->shortNoteDefaultDelay;
                break;

            case 0x80: // Small note with the previous delay.
                delay = layer->lastDelay;
                break;
        }
        cmd -= (cmd & 0xC0);
    }

    if (channel->velocityRandomVariance != 0) {
        float_delta = layer->velocitySquare * (D_8011EB9C % channel->velocityRandomVariance) / 100.0f;
        if ((D_8011EB9C & 0x8000) != 0) {
            float_delta = -float_delta;
        }

        layer->velocitySquare2 = layer->velocitySquare + float_delta;

        if (layer->velocitySquare2 < 0.0f) {
            layer->velocitySquare2 = 0.0f;
        } else if (layer->velocitySquare2 > 1.0f) {
            layer->velocitySquare2 = 1.0f;
        }
    } else {
        layer->velocitySquare2 = layer->velocitySquare;
    }

    layer->delay = delay;
    layer->gateDelay = (layer->gateTime * delay) >> 8;

    if (channel->gateTimeRandomVariance != 0) {
        //!bug the gate-time variance check scales by velocityRandomVariance, as in Majora's Mask
        int_delta = (layer->gateDelay * (D_8011EB9C % channel->velocityRandomVariance)) / 100;
        if ((D_8011EB9C & 0x4000) != 0) {
            int_delta = -int_delta;
        }

        layer->gateDelay += int_delta;
        if (layer->gateDelay < 0) {
            layer->gateDelay = 0;
        } else if (layer->gateDelay > layer->delay) {
            layer->gateDelay = layer->delay;
        }
    }

    // Mute flags 0x40 and 0x10 stop notes and layers.
    if (seq_player->muted && (channel->muteFlags & 0x50)) {
        layer->muted = TRUE;
        return -1;
    }

    if (seq_player->skipTicks != 0) {
        layer->muted = TRUE;
        return -1;
    }

    return cmd;
}

void func_8001DE58(u8 *arg0, u8 arg1) {
    s32 value;
    s32 low;
    s32 high;
    value = arg1 & 0xFF;
    low = value & 0xF;
    if (low != 0) {
        arg0[5] = low;
    }
    high = (value >> 4) & 0xFF;
    if (high != 0) {
        arg0[6] = high;
    }
    if (arg0[5] < 2) {
        arg0[5] = 2;
    }
    if (arg0[6] <= (low * 0)) {
        arg0[5] = 1;
    }
}

u8 AudioChannel_ResolveInstrument(u8 *channel, u8 program, u8 **out_instrument, u8 *adsr) {
    u8 *instrument;
    instrument = (u8 *)func_8001A308(channel[7], program);
    if (instrument == NULL) { *out_instrument = NULL; return 0; }
    *(u32 *)(adsr + 4) = *(u32 *)(instrument + 4);
    adsr[0] = instrument[3];
    *out_instrument = instrument;
    program += 2;
    return program;
}

void AudioChannel_SetProgram(u8 *channel, u8 program) {
    typedef struct { u8 high:4; u8 has_instrument:1; u8 low:3; } ChannelFlags;
    if (program >= 0x80) {
        *(s16 *)(channel + 0x28) = program;
        *(u32 *)(channel + 0x4C) = 0;
    } else if (program == 0x7F) {
        *(s16 *)(channel + 0x28) = 0;
        *(u32 *)(channel + 0x4C) = 1;
    } else if (program == 126) {
        *(s16 *)(channel + 0x28) = 1;
        *(u32 *)(channel + 0x4C) = 2;
    } else {
        if ((*(s16 *)(channel + 0x28) = AudioChannel_ResolveInstrument(channel, program, (u8 **)(channel + 0x4C), channel + 0x88)) == 0) { ((ChannelFlags *)channel)->has_instrument = 0; goto done; }
    }
    ((ChannelFlags *)channel)->has_instrument = 1;
done:
    return;
}

void func_8001DFD0(void *arg0, u8 arg1) {
    s32 value = arg1;
    *(f32 *)((u8 *)arg0 + 0x30) = (f32)value / 127.0f;
}

extern void ResourcePool_AcquireEntries(void *pool, s32 count);
extern s32 func_80011250(s32 table_type, s32 cache, s32 id);
extern void func_80011864(s16 *filter, s32 low_pass_cutoff, s32 high_pass_cutoff);
extern s32 func_80015E6C(s32 font_id, s32 sample_id, s8 *status);
extern f32 D_8008E794[];
extern u8 *D_8011EA60;
extern u8 (*D_8011EBA8[])(s8 value, SequenceChannel *channel);
extern u8 (*D_80122A24)(s8 value, SequenceChannel *channel);
extern u32 func_800194A0(void);
// Close to Majora's Mask AudioScript_SequenceChannelProcessScript (src/audio/lib/seqplayer.c);
// GS has no commands 0xA7 (shift value) and 0xA8 (random pointer), draws the random values of
// commands 0xB7 and 0xB8 from func_800194A0 (the generator Majora's Mask calls
// AudioThread_NextRandom) instead of the stored audio random value, and its
// layer commands accept layer indices 0-5. D_8011EA60 is the sequence font
// table, D_8008E794 and D_8008EB94 are the one-octave and two-semitone bend
// tables, and D_8011EBA8 holds five custom sequence functions, the one being
// called is stored in D_80122A24.
void func_8001DFF4(SequenceChannel *channel) {
    s32 i;
    u8 *data;
    SequencePlayer *seq_player;

    if (channel->stopScript) {
        goto exit_loop;
    }

    seq_player = channel->seqPlayer;
    if (seq_player->muted && (channel->muteFlags & 0x80)) {
        return;
    }

    if (channel->delay >= 2) {
        channel->delay--;
        goto exit_loop;
    }

    while (TRUE) {
        AudioScriptState *script_state = &channel->scriptState;
        s16 temp1;
        u16 cmd_arg_u16;
        s8 cmd_arg_s8;
        u8 cmd = func_8001CC3C(&script_state->pc);
        u8 low_bits;
        u8 high_bits;
        s32 delay;
        u32 cmd_args[3];
        u8 depth;
        u8 *seq_data = seq_player->seqData;

        // Commands 0xA0 - 0xFF
        if (cmd >= 0xA0) {
            // The argument table for commands 0xA0-0xFF starts at 0x8008FC30,
            // D_8008FB90 + 0xA0 (entry 0x81 for command 0xA0: one s16 argument).
            high_bits = (D_8008FB90 + 0xA0)[cmd - 0xA0];
            low_bits = high_bits & 3;

            // Read the command's arguments.
            for (i = 0; i < low_bits; i++, high_bits <<= 1) {
                if (!(high_bits & 0x80)) {
                    cmd_args[i] = func_8001CC3C(&script_state->pc);
                } else {
                    cmd_args[i] = func_8001CC50(&script_state->pc);
                }
            }

            // Control-flow commands
            if (cmd >= 0xF2) {
                delay = func_8001C228((u8 *)seq_player, script_state, cmd, cmd_args[0]);

                if (delay != 0) {
                    if (delay == -1) {
                        func_8001C794((s32)channel);
                    } else {
                        channel->delay = delay;
                    }
                    break;
                }
                continue;
            }

            switch (cmd) {
                case 0xEA: // Stop the script.
                    channel->stopScript = TRUE;
                    goto exit_loop;

                case 0xF1: // Reserve notes.
                    AudioNotePool_Clear(&channel->notePool);
                    cmd = (u8)cmd_args[0];
                    ResourcePool_AcquireEntries(&channel->notePool, cmd);
                    break;

                case 0xF0: // Release reserved notes.
                    AudioNotePool_Clear(&channel->notePool);
                    break;

                case 0xC2: // Set the dynamic table.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    channel->dynTable = (void *)&seq_player->seqData[cmd_arg_u16];
                    break;

                case 0xC5: // Set the dynamic table from the dynamic table.
                    if (script_state->value != -1) {
                        data = (*channel->dynTable)[script_state->value];
                        cmd_arg_u16 = (u16)((data[0] << 8) + data[1]);
                        script_state->pc = (void *)&seq_player->seqData[cmd_arg_u16];
                    }
                    break;

                case 0xEB: // Set sound font and instrument.
                    cmd = (u8)cmd_args[0];

                    if (seq_player->defaultFont != 0xFF) {
                        cmd_arg_u16 = ((u16 *)D_8011EA60)[seq_player->seqId];
                        low_bits = D_8011EA60[cmd_arg_u16];
                        cmd = D_8011EA60[cmd_arg_u16 + low_bits - cmd];
                    }

                    if (func_80011250(1, 2, cmd)) {
                        channel->fontId = cmd;
                    }

                    cmd_args[0] = cmd_args[1];
                    // fallthrough
                case 0xC1: // Set instrument.
                    cmd = (u8)cmd_args[0];
                    AudioChannel_SetProgram((u8 *)channel, cmd);
                    break;

                case 0xC3: // Large notes off.
                    channel->largeNotes = FALSE;
                    break;

                case 0xC4: // Large notes on.
                    channel->largeNotes = TRUE;
                    break;

                case 0xDF: // Set volume.
                    cmd = (u8)cmd_args[0];
                    func_8001DFD0(channel, cmd);
                    channel->changes.s.volume = TRUE;
                    break;

                case 0xE0: // Set volume scale.
                    cmd = (u8)cmd_args[0];
                    channel->volumeScale = (f32)(s32)cmd / 128.0f;
                    channel->changes.s.volume = TRUE;
                    break;

                case 0xDE: // Set frequency scale.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    channel->freqScale = (f32)(s32)cmd_arg_u16 / 0x8000;
                    channel->changes.s.freqScale = TRUE;
                    break;

                case 0xD3: // Bend pitch by up to one octave.
                    cmd = (u8)cmd_args[0];
                    cmd += 0x80;
                    channel->freqScale = D_8008E794[cmd];
                    channel->changes.s.freqScale = TRUE;
                    break;

                case 0xEE: // Bend pitch by up to two semitones.
                    cmd = (u8)cmd_args[0];
                    cmd += 0x80;
                    channel->freqScale = D_8008EB94[cmd];
                    channel->changes.s.freqScale = TRUE;
                    break;

                case 0xDD: // Set pan.
                    cmd = (u8)cmd_args[0];
                    channel->newPan = cmd;
                    channel->changes.s.pan = TRUE;
                    break;

                case 0xDC: // Set pan weight.
                    cmd = (u8)cmd_args[0];
                    channel->panChannelWeight = cmd;
                    channel->changes.s.pan = TRUE;
                    break;

                case 0xDB: // Set transposition.
                    cmd_arg_s8 = (s8)cmd_args[0];
                    channel->transposition = cmd_arg_s8;
                    break;

                case 0xDA: // Set envelope.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    channel->adsr.envelope = &seq_player->seqData[cmd_arg_u16];
                    break;

                case 0xD9: // Set release rate.
                    cmd = (u8)cmd_args[0];
                    channel->adsr.decayIndex = cmd;
                    break;

                case 0xD8: // Set vibrato depth.
                    cmd = (u8)cmd_args[0];
                    channel->vibrato.vibratoDepthTarget = cmd * 8;
                    channel->vibrato.vibratoDepthStart = 0;
                    channel->vibrato.vibratoDepthChangeDelay = 0;
                    break;

                case 0xD7: // Set vibrato rate.
                    cmd = (u8)cmd_args[0];
                    channel->vibrato.vibratoRateChangeDelay = 0;
                    channel->vibrato.vibratoRateTarget = cmd * 32;
                    channel->vibrato.vibratoRateStart = cmd * 32;
                    break;

                case 0xE2: // Set a vibrato depth ramp.
                    cmd = (u8)cmd_args[0];
                    channel->vibrato.vibratoDepthStart = cmd * 8;
                    cmd = (u8)cmd_args[1];
                    channel->vibrato.vibratoDepthTarget = cmd * 8;
                    cmd = (u8)cmd_args[2];
                    channel->vibrato.vibratoDepthChangeDelay = cmd * 16;
                    break;

                case 0xE1: // Set a vibrato rate ramp.
                    cmd = (u8)cmd_args[0];
                    channel->vibrato.vibratoRateStart = cmd * 32;
                    cmd = (u8)cmd_args[1];
                    channel->vibrato.vibratoRateTarget = cmd * 32;
                    cmd = (u8)cmd_args[2];
                    channel->vibrato.vibratoRateChangeDelay = cmd * 16;
                    break;

                case 0xE3: // Set vibrato delay.
                    cmd = (u8)cmd_args[0];
                    channel->vibrato.vibratoDelay = cmd * 16;
                    break;

                case 0xD4: // Set reverb volume.
                    cmd = (u8)cmd_args[0];
                    channel->targetReverbVol = cmd;
                    break;

                case 0xC6: // Set sound font.
                    cmd = (u8)cmd_args[0];

                    if (seq_player->defaultFont != 0xFF) {
                        cmd_arg_u16 = ((u16 *)D_8011EA60)[seq_player->seqId];
                        low_bits = D_8011EA60[cmd_arg_u16];
                        cmd = D_8011EA60[cmd_arg_u16 + low_bits - cmd];
                    }

                    if (func_80011250(1, 2, cmd)) {
                        channel->fontId = cmd;
                    }
                    break;

                case 0xC7: // Write into the sequence data.
                    cmd = (u8)cmd_args[0];
                    cmd_arg_u16 = (u16)cmd_args[1];
                    seq_data = &seq_player->seqData[cmd_arg_u16];
                    seq_data[0] = (u8)script_state->value + cmd;
                    break;

                case 0xC8: // Subtract from value.
                case 0xCC: // Set value.
                case 0xC9: // Bitwise AND with value.
                    cmd_arg_s8 = (s8)cmd_args[0];

                    if (cmd == 0xC8) {
                        script_state->value -= cmd_arg_s8;
                    } else if (cmd == 0xCC) {
                        script_state->value = cmd_arg_s8;
                    } else {
                        script_state->value &= cmd_arg_s8;
                    }
                    break;

                case 0xCD: // Disable a channel.
                    cmd = (u8)cmd_args[0];
                    func_8001C794((s32)seq_player->channels[cmd]);
                    break;

                case 0xCA: // Set mute behavior.
                    cmd = (u8)cmd_args[0];
                    channel->muteFlags = cmd;
                    channel->changes.s.volume = TRUE;
                    break;

                case 0xCB: // Read the sequence data into value.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    script_state->value = *(seq_player->seqData + (u32)(cmd_arg_u16 + script_state->value));
                    break;

                case 0xCE: // Set the pointer register.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    channel->unk_22 = cmd_arg_u16;
                    break;

                case 0xCF: // Write the pointer register into the sequence data.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    seq_data = &seq_player->seqData[cmd_arg_u16];
                    seq_data[0] = (channel->unk_22 >> 8) & 0xFF;
                    seq_data[1] = channel->unk_22 & 0xFF;
                    break;

                case 0xD0: // Stereo headset effects.
                    cmd = (u8)cmd_args[0];
                    if (cmd & 0x80) {
                        channel->stereoHeadsetEffects = TRUE;
                    } else {
                        channel->stereoHeadsetEffects = FALSE;
                    }
                    channel->stereoData.asByte = cmd & 0x7F;
                    break;

                case 0xD1: // Set note allocation policy.
                    cmd = (u8)cmd_args[0];
                    channel->noteAllocPolicy = cmd;
                    break;

                case 0xD2: // Set sustain.
                    cmd = (u8)cmd_args[0];
                    channel->adsr.sustain = cmd;
                    break;

                case 0xE5: // Set reverb index.
                    cmd = (u8)cmd_args[0];
                    channel->reverbIndex = cmd;
                    break;

                case 0xE4: // Call through the dynamic table.
                    if (script_state->value != -1) {
                        data = (*channel->dynTable)[script_state->value];
                        depth = script_state->depth;
                        //!bug no stack depth check
                        script_state->stack[depth] = script_state->pc;
                        script_state->depth++;
                        cmd_arg_u16 = (u16)((data[0] << 8) + data[1]);
                        script_state->pc = seq_player->seqData + cmd_arg_u16;
                    }
                    break;

                case 0xE6: // Set sample book offset.
                    cmd = (u8)cmd_args[0];
                    channel->bookOffset = cmd;
                    break;

                case 0xE7: // Load channel parameters from the sequence data.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    data = &seq_player->seqData[cmd_arg_u16];
                    channel->muteFlags = *data++;
                    channel->noteAllocPolicy = *data++;
                    func_8001DE58((u8 *)channel, *data++);
                    channel->transposition = (s8)*data++;
                    channel->newPan = *data++;
                    channel->panChannelWeight = *data++;
                    channel->targetReverbVol = *data++;
                    channel->reverbIndex = *data++;
                    //!bug the reverb change is not flagged
                    channel->changes.s.pan = TRUE;
                    break;

                case 0xE8: // Set channel parameters.
                    channel->muteFlags = cmd_args[0];
                    channel->noteAllocPolicy = cmd_args[1];
                    cmd = (u8)cmd_args[2];
                    func_8001DE58((u8 *)channel, cmd);
                    channel->transposition = (s8)func_8001CC3C(&script_state->pc);
                    channel->newPan = func_8001CC3C(&script_state->pc);
                    channel->panChannelWeight = func_8001CC3C(&script_state->pc);
                    channel->targetReverbVol = func_8001CC3C(&script_state->pc);
                    channel->reverbIndex = func_8001CC3C(&script_state->pc);
                    //!bug the reverb change is not flagged
                    channel->changes.s.pan = TRUE;
                    break;

                case 0xEC: // Reset vibrato and other effects.
                    channel->vibrato.vibratoDepthTarget = 0;
                    channel->vibrato.vibratoDepthStart = 0;
                    channel->vibrato.vibratoDepthChangeDelay = 0;
                    channel->vibrato.vibratoRateTarget = 0;
                    channel->vibrato.vibratoRateStart = 0;
                    channel->vibrato.vibratoRateChangeDelay = 0;
                    channel->filter = NULL;
                    channel->gain = 0;
                    channel->adsr.sustain = 0;
                    channel->velocityRandomVariance = 0;
                    channel->gateTimeRandomVariance = 0;
                    channel->combFilterSize = 0;
                    channel->combFilterGain = 0;
                    channel->bookOffset = 0;
                    channel->startSamplePos = 0;
                    channel->unk_E0 = 0;
                    channel->freqScale = 1.0f;
                    break;

                case 0xE9: // Set note priority.
                    func_8001DE58((u8 *)channel, (u8)cmd_args[0]);
                    break;

                case 0xED: // Set gain.
                    cmd = (u8)cmd_args[0];
                    channel->gain = cmd;
                    break;

                case 0xB0: // Set filter.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    data = seq_player->seqData + cmd_arg_u16;
                    channel->filter = (s16 *)data;
                    break;

                case 0xB1: // Clear filter.
                    channel->filter = NULL;
                    break;

                case 0xB3: // Load filter coefficients.
                    cmd = cmd_args[0];

                    if (channel->filter != NULL) {
                        low_bits = (cmd >> 4) & 0xF; // Low-pass cutoff
                        cmd &= 0xF;                  // High-pass cutoff
                        func_80011864(channel->filter, low_bits, cmd);
                    }
                    break;

                case 0xB2: // Read a u16 from the sequence data into the pointer register.
                    cmd_arg_u16 = (u16)cmd_args[0];
                    channel->unk_22 = *(u16 *)(seq_player->seqData + (u32)(cmd_arg_u16 + script_state->value * 2));
                    break;

                case 0xB4: // Set the dynamic table from the pointer register.
                    channel->dynTable = (void *)&seq_player->seqData[channel->unk_22];
                    break;

                case 0xB5: // Read the dynamic table into the pointer register.
                    channel->unk_22 = ((u16 *)(channel->dynTable))[script_state->value];
                    break;

                case 0xB6: // Read the dynamic table into value.
                    script_state->value = (*channel->dynTable)[0][script_state->value];
                    break;

                case 0xB7: // Random pointer register.
                    channel->unk_22 = (cmd_args[0] == 0) ? (func_800194A0() & 0xFFFF) : (func_800194A0() % cmd_args[0]);
                    break;

                case 0xB8: // Random value.
                    script_state->value = (cmd_args[0] == 0) ? (func_800194A0() & 0xFFFF) : (func_800194A0() % cmd_args[0]);
                    break;

                case 0xB9: // Set velocity random variance.
                    channel->velocityRandomVariance = cmd_args[0];
                    break;

                case 0xBA: // Set gate time random variance.
                    channel->gateTimeRandomVariance = cmd_args[0];
                    break;

                case 0xBB: // Set comb filter.
                    channel->combFilterSize = cmd_args[0];
                    channel->combFilterGain = cmd_args[1];
                    break;

                case 0xBC: // Add to the pointer register.
                    channel->unk_22 += cmd_args[0];
                    break;

                case 0xBD: // Set sample start position.
                    channel->startSamplePos = cmd_args[0];
                    break;

                case 0xBE: // Call a custom sequence function.
                    if (cmd_args[0] < 5) {
                        if (1) {} // karodo: also in Majora's Mask; diff score 1725 without it.
                        if (D_8011EBA8[cmd_args[0]] != NULL) {
                            D_80122A24 = D_8011EBA8[cmd_args[0]];
                            script_state->value = D_80122A24(script_state->value, channel);
                        }
                    }
                    break;

                case 0xA0: // Read from the sound effect state at an argument offset.
                case 0xA1: // Read from the sound effect state at the pointer register.
                case 0xA2: // Write to the sound effect state at an argument offset.
                case 0xA3: // Write to the sound effect state at the pointer register.
                    if ((cmd == 0xA0) || (cmd == 0xA2)) {
                        cmd_arg_u16 = (u16)cmd_args[0];
                    } else {
                        cmd_arg_u16 = channel->unk_22;
                    }

                    if (channel->sfxState != NULL) {
                        if ((cmd == 0xA0) || (cmd == 0xA1)) {
                            script_state->value = channel->sfxState[cmd_arg_u16];
                        } else {
                            channel->sfxState[cmd_arg_u16] = script_state->value;
                        }
                    }
                    break;

                case 0xA4: // Set surround effect index.
                    channel->surroundEffectIndex = cmd_args[0];
                    break;

                case 0xA5: // Add the channel index to value.
                    script_state->value += channel->channelIndex;
                    break;

                case 0xA6: // Write into the sequence data at an offset by the channel index.
                    cmd = (u8)cmd_args[0];
                    cmd_arg_u16 = (u16)cmd_args[1];
                    seq_data = seq_player->seqData + (u32)(cmd_arg_u16 + channel->channelIndex);
                    seq_data[0] = (u8)script_state->value + cmd;
                    break;
            }
            continue;
        }

        // Commands 0x70 - 0x9F
        if (cmd >= 0x70) {
            low_bits = cmd & 0x7;

            if (((cmd & 0xF8) != 0x70) && (low_bits >= 6)) {
                low_bits = 0;
            }

            switch (cmd & 0xF8) {
                case 0x80: // Test whether a layer is finished.
                    if (channel->layers[low_bits] != NULL) {
                        script_state->value = channel->layers[low_bits]->finished;
                    } else {
                        script_state->value = -1;
                    }
                    break;

                case 0x88: // Start a layer.
                    cmd_arg_u16 = func_8001CC50(&script_state->pc);
                    if (!AudioChannel_AllocateLayer((AudioLayerAllocateChannel *)channel, low_bits)) {
                        channel->layers[low_bits]->scriptState.pc = &seq_player->seqData[cmd_arg_u16];
                    }
                    break;

                case 0x90: // Free a layer.
                    func_8001C744(channel, low_bits);
                    break;

                case 0x98: // Start a layer through the dynamic table.
                    if ((script_state->value != -1) &&
                        (AudioChannel_AllocateLayer((AudioLayerAllocateChannel *)channel, low_bits) != -1)) {
                        data = (*channel->dynTable)[script_state->value];
                        cmd_arg_u16 = (data[0] << 8) + data[1];
                        channel->layers[low_bits]->scriptState.pc = &seq_player->seqData[cmd_arg_u16];
                    }
                    break;

                case 0x70: // Write an IO value.
                    channel->seqScriptIO[low_bits] = script_state->value;
                    break;

                case 0x78: // Start a layer at a relative offset.
                    temp1 = func_8001CC50(&script_state->pc);
                    if (!AudioChannel_AllocateLayer((AudioLayerAllocateChannel *)channel, low_bits)) {
                        channel->layers[low_bits]->scriptState.pc = &script_state->pc[temp1];
                    }
                    break;
            }
            continue;
        }

        // Commands 0x00 - 0x6F
        low_bits = cmd & 0xF;

        switch (cmd & 0xF0) {
            case 0x00: // Short delay.
                channel->delay = low_bits;
                if (low_bits == 0) {
                    break;
                }
                goto exit_loop;

            case 0x10: // Load a sample.
                if (low_bits < 8) {
                    channel->seqScriptIO[low_bits] = -1;
                    // karodo: the empty result check is also in Majora's Mask; diff score 1360 without both.
                    if (func_80015E6C(channel->fontId, script_state->value, &channel->seqScriptIO[low_bits]) == -1) {}
                } else {
                    low_bits -= 8;
                    channel->seqScriptIO[low_bits] = -1;
                    if (func_80015E6C(channel->fontId, channel->unk_22 + 0x100, &channel->seqScriptIO[low_bits]) ==
                        -1) {} // karodo
                }
                break;

            case 0x60: // Read an IO value.
                script_state->value = channel->seqScriptIO[low_bits];
                if (low_bits < 2) {
                    channel->seqScriptIO[low_bits] = -1;
                }
                break;

            case 0x50: // Subtract an IO value.
                script_state->value -= channel->seqScriptIO[low_bits];
                break;

            case 0x20: // Start a channel.
                cmd_arg_u16 = func_8001CC50(&script_state->pc);
                AudioChannel_StartScript((u8 *)seq_player, low_bits, &seq_player->seqData[cmd_arg_u16]);
                break;

            case 0x30: // Write another channel's IO value.
                cmd = func_8001CC3C(&script_state->pc);
                seq_player->channels[low_bits]->seqScriptIO[cmd] = script_state->value;
                break;

            case 0x40: // Read another channel's IO value.
                cmd = func_8001CC3C(&script_state->pc);
                script_state->value = seq_player->channels[low_bits]->seqScriptIO[cmd];
                break;
        }
    }
exit_loop:

    for (i = 0; i < 6; i++) {
        if (channel->layers[i] != NULL) {
            AudioLayer_UpdateScript((AudioLayerUpdatePrefix *)channel->layers[i]);
        }
    }
}

extern s32 func_80014A18(s32 player_index, s32 seq_id, s32 arg2);
extern void func_80016368(s32 seq_id, u8 *ram_addr, s8 *status);
extern void func_800179CC(s32 arg0, s32 arg1, s8 *arg2);
// Close to Majora's Mask AudioScript_SequencePlayerProcessSequence (src/audio/lib/seqplayer.c);
// GS's start-sequence command (0xC4) with player 0xFF restarts the current
// player even while it fades out. D_8011BE90 + 0x2C2C is the maximum tempo; D_8011EB9C is the audio random value.
void func_8001ED64(SequencePlayer *seq_player) {
    u8 cmd;
    u8 cmd_low_bits;
    AudioScriptState *seq_script = &seq_player->scriptState;
    s16 temp_s;
    u16 temp;
    s32 i;
    s32 value;
    u8 *data1;
    u8 *data2;
    u8 *data3;
    u8 *data4;
    s32 tempo_change;
    s32 j;
    SequenceChannel *channel;
    u16 *new_var;
    s32 delay;

    if (!seq_player->enabled) {
        return;
    }

    if (!func_80014208(seq_player->seqId) || !func_80014190(seq_player->defaultFont)) {
        // These calls have no effect.
        if (func_80014208(seq_player->seqId)) {}
        if (func_80014208(seq_player->defaultFont)) {}

        AudioSequence_Disable((u8 *)seq_player);
        return;
    }

    func_80014328(seq_player->seqId, 2);
    func_800142F8(seq_player->defaultFont, 2);

    if (seq_player->muted && (seq_player->muteFlags & 0x80)) {
        return;
    }

    seq_player->scriptCounter++;

    tempo_change = seq_player->tempo + seq_player->tempoChange;
    if (tempo_change > *(s16 *)(D_8011BE90 + 0x2C2C)) {
        tempo_change = *(s16 *)(D_8011BE90 + 0x2C2C);
    }

    seq_player->tempoAcc += tempo_change;

    if (seq_player->tempoAcc < *(s16 *)(D_8011BE90 + 0x2C2C)) {
        return;
    }

    seq_player->tempoAcc -= (u16)*(s16 *)(D_8011BE90 + 0x2C2C);
    seq_player->unk_16++;

    if (seq_player->stopScript == TRUE) {
        return;
    }

    if (seq_player->delay > 1) {
        seq_player->delay--;
    } else {
        seq_player->recalculateVolume = TRUE;

        while (TRUE) {
            cmd = func_8001CC3C(&seq_script->pc);

            // 0xF2 and above are control-flow commands, including termination.
            if (cmd >= 0xF2) {
                delay = func_8001C228((u8 *)seq_player, seq_script, cmd,
                                      func_8001C1C0(&seq_player->scriptState.pc, cmd));

                if (delay != 0) {
                    if (delay == -1) {
                        AudioSequence_Disable((u8 *)seq_player);
                    } else {
                        seq_player->delay = delay;
                    }
                    break;
                }
                continue;
            }

            // Commands 0xC0 - 0xF1
            if (cmd >= 0xC0) {
                switch (cmd) {
                    case 0xF1: // Reserve notes.
                        AudioNotePool_Clear(&seq_player->notePool);
                        cmd = func_8001CC3C(&seq_script->pc);
                        ResourcePool_AcquireEntries(&seq_player->notePool, cmd);
                        break;

                    case 0xF0: // Release reserved notes.
                        AudioNotePool_Clear(&seq_player->notePool);
                        break;

                    case 0xDF: // Set transposition.
                        seq_player->transposition = 0;
                        // fallthrough
                    case 0xDE: // Add to transposition.
                        seq_player->transposition += (s8)func_8001CC3C(&seq_script->pc);
                        break;

                    case 0xDD: // Set tempo in beats per minute.
                        seq_player->tempo = func_8001CC3C(&seq_script->pc) * 48;
                        if (seq_player->tempo > *(s16 *)(D_8011BE90 + 0x2C2C)) {
                            seq_player->tempo = *(s16 *)(D_8011BE90 + 0x2C2C);
                        }

                        if ((s16)seq_player->tempo <= 0) {
                            seq_player->tempo = 1;
                        }
                        break;

                    case 0xDC: // Set tempo change.
                        seq_player->tempoChange = (s8)func_8001CC3C(&seq_script->pc) * 48;
                        break;

                    case 0xDA: // Set fade mode and time.
                        cmd = func_8001CC3C(&seq_script->pc);
                        temp = func_8001CC50(&seq_script->pc);
                        switch (cmd) {
                            case 0:
                            case 1:
                                if (seq_player->state != 2) {
                                    seq_player->storedFadeTimer = temp;
                                    seq_player->state = cmd;
                                }
                                break;

                            case 2: // Fade out.
                                seq_player->fadeTimer = temp;
                                seq_player->state = cmd;
                                seq_player->fadeVelocity = (0.0f - seq_player->fadeVolume) / (s32)seq_player->fadeTimer;
                                break;
                        }
                        break;

                    case 0xDB: // Set volume.
                        value = func_8001CC3C(&seq_script->pc);
                        switch (seq_player->state) {
                            case 1: // Fade in.
                                seq_player->state = 0;
                                seq_player->fadeVolume = 0.0f;
                                // fallthrough
                            case 0:
                                seq_player->fadeTimer = seq_player->storedFadeTimer;
                                if (seq_player->storedFadeTimer != 0) {
                                    seq_player->fadeVelocity =
                                        ((value / 127.0f) - seq_player->fadeVolume) / (s32)seq_player->fadeTimer;
                                } else {
                                    seq_player->fadeVolume = value / 127.0f;
                                }
                                break;

                            case 2: // Fade out.
                                break;
                        }
                        break;

                    case 0xD9: // Set volume scale.
                        seq_player->fadeVolumeScale = (s8)func_8001CC3C(&seq_script->pc) / 127.0f;
                        break;

                    case 0xD7: // Initialize channels.
                        temp = func_8001CC50(&seq_script->pc);
                        func_8001C804(seq_player, temp);
                        break;

                    case 0xD6: // Disable channels (argument ignored).
                        func_8001CC50(&seq_script->pc);
                        break;

                    case 0xD5: // Set mute volume scale.
                        seq_player->muteVolumeScale = (s8)func_8001CC3C(&seq_script->pc) / 127.0f;
                        break;

                    case 0xD4: // Mute.
                        seq_player->muted = TRUE;
                        break;

                    case 0xD3: // Set mute behavior.
                        seq_player->muteFlags = func_8001CC3C(&seq_script->pc);
                        break;

                    case 0xD1: // Set short-note gate time table.
                    case 0xD2: // Set short-note velocity table.
                        temp = func_8001CC50(&seq_script->pc);
                        data3 = &seq_player->seqData[temp];
                        if (cmd == 0xD2) {
                            seq_player->shortNoteVelocityTable = data3;
                        } else {
                            seq_player->shortNoteGateTimeTable = data3;
                        }
                        break;

                    case 0xD0: // Set note allocation policy.
                        seq_player->noteAllocPolicy = func_8001CC3C(&seq_script->pc);
                        break;

                    case 0xCE: // Random value.
                        cmd = func_8001CC3C(&seq_script->pc);
                        if (cmd == 0) {
                            seq_script->value = (D_8011EB9C >> 2) & 0xFF;
                        } else {
                            seq_script->value = (D_8011EB9C >> 2) % cmd;
                        }
                        break;

                    case 0xCD: // Call through a table indexed by the script value.
                        temp = func_8001CC50(&seq_script->pc);
                        if ((seq_script->value != -1) && (seq_script->depth != 3)) {
                            data1 = seq_player->seqData + (u32)(temp + (seq_script->value << 1));
                            seq_script->stack[seq_script->depth] = seq_script->pc;
                            seq_script->depth++;
                            temp = (data1[0] << 8) + data1[1];
                            seq_script->pc = &seq_player->seqData[temp];
                        }
                        break;

                    case 0xCC: // Set value.
                        seq_script->value = func_8001CC3C(&seq_script->pc);
                        break;

                    case 0xC9: // Bitwise AND with value.
                        seq_script->value &= func_8001CC3C(&seq_script->pc);
                        break;

                    case 0xC8: // Subtract from value.
                        seq_script->value -= func_8001CC3C(&seq_script->pc);
                        break;

                    case 0xC7: // Write into the sequence data.
                        cmd = func_8001CC3C(&seq_script->pc);
                        temp = func_8001CC50(&seq_script->pc);
                        data2 = &seq_player->seqData[temp];
                        *data2 = (u8)seq_script->value + cmd;
                        break;

                    case 0xC2: // Jump through a table indexed by the script value.
                        temp = func_8001CC50(&seq_script->pc);
                        if (seq_script->value != -1) {
                            data4 = seq_player->seqData + (u32)(temp + (seq_script->value << 1));

                            temp = (data4[0] << 8) + data4[1];
                            seq_script->pc = &seq_player->seqData[temp];
                        }
                        break;

                    case 0xC6: // Stop the script.
                        seq_player->stopScript = TRUE;
                        return;

                    case 0xC5: // Set the script counter.
                        seq_player->unk_16 = func_8001CC50(&seq_script->pc);
                        break;

                    case 0xEF: // Arguments ignored.
                        func_8001CC50(&seq_script->pc);
                        func_8001CC3C(&seq_script->pc);
                        break;

                    case 0xC4: // Start a sequence.
                        cmd = func_8001CC3C(&seq_script->pc);
                        if (cmd == 0xFF) {
                            cmd = seq_player->playerIndex;
                        }

                        cmd_low_bits = func_8001CC3C(&seq_script->pc);
                        func_80014A18(cmd, cmd_low_bits, 0);
                        if (cmd == (u8)seq_player->playerIndex) {
                            return;
                        }
                        break;

                    case 0xC3: // Mute channels from a bit mask in the sequence data.
                        temp = func_8001CC50(&seq_script->pc);
                        if (seq_script->value != -1) {
                            new_var = (u16 *)(seq_player->seqData + (u32)(temp + seq_script->value * 2));
                            temp = *new_var;

                            for (i = 0; i < 16; i++) {
                                seq_player->channels[i]->muted = temp & 1;
                                temp = temp >> 1;
                            }
                        }
                        break;
                }
                continue;
            }

            // Commands 0x00 - 0xBF
            cmd_low_bits = cmd & 0x0F;

            switch (cmd & 0xF0) {
                case 0x00: // Test whether a channel is disabled.
                    seq_script->value = seq_player->channels[cmd_low_bits]->enabled ^ 1;
                    break;

                case 0x50: // Subtract an IO value.
                    seq_script->value -= seq_player->seqScriptIO[cmd_low_bits];
                    break;

                case 0x70: // Write an IO value.
                    seq_player->seqScriptIO[cmd_low_bits] = seq_script->value;
                    break;

                case 0x80: // Read an IO value.
                    seq_script->value = seq_player->seqScriptIO[cmd_low_bits];
                    if (cmd_low_bits < 2) {
                        seq_player->seqScriptIO[cmd_low_bits] = -1;
                    }
                    break;

                case 0x40: // Disable a channel.
                    func_8001C794((s32)seq_player->channels[cmd_low_bits]);
                    break;

                case 0x90: // Start a channel.
                    temp = func_8001CC50(&seq_script->pc);
                    AudioChannel_StartScript((u8 *)seq_player, cmd_low_bits, (void *)&seq_player->seqData[temp]);
                    break;

                case 0xA0: // Start a channel at a relative offset.
                    temp_s = func_8001CC50(&seq_script->pc);
                    AudioChannel_StartScript((u8 *)seq_player, cmd_low_bits, (void *)&seq_script->pc[temp_s]);
                    break;

                case 0xB0: // Load a sequence.
                    cmd = func_8001CC3C(&seq_script->pc);
                    temp = func_8001CC50(&seq_script->pc);
                    data2 = &seq_player->seqData[temp];
                    func_80016368(cmd, data2, &seq_player->seqScriptIO[cmd_low_bits]);
                    break;

                case 0x60: // Asynchronous load.
                    cmd = func_8001CC3C(&seq_script->pc);
                    value = cmd;
                    temp = func_8001CC3C(&seq_script->pc);
                    func_800179CC(value, temp, &seq_player->seqScriptIO[cmd_low_bits]);
                    break;
            }
        }
    }

    for (j = 0; j < 16; j++) {
        channel = seq_player->channels[j];
        if (channel->enabled) {
            func_8001DFF4(channel);
        }
    }
}

void Audio_UpdateSequencesAndNotes(s32 update_index) {
    u32 i;
    u8 *sequence;
    *(u32 *)(D_8011BE90 + 0x6060) = *(u32 *)(D_8011BE90 + 0x2C28) * (*(s16 *)(D_8011BE90 + 0x2BE8) - update_index - 1);
    for (i = 0; i < *(s16 *)(D_8011BE90 + 0x2BF0); i++) {
        sequence = D_8011BE90 + i * 352 + 0x346C;
        if ((*(u32 *)sequence >> 31) == 1) {
            func_8001ED64(sequence);
            AudioSequence_Update(sequence);
        }
    }
    func_8001ED64(D_80121F44);
    AudioSequence_Update(D_80121F44);
    func_80019DE4();
}

extern void func_8001B8D0(void *);
void func_8001F7A0(void *arg0) {
    s32 temp_t8;

    if (*(s32 *)((u8 *)arg0 + 0xDC) > 0) {
        do {
            func_8001ED64(arg0);
            func_8001B8D0(arg0);
            temp_t8 = --(*(s32 *)((u8 *)arg0 + 0xDC));
        } while (temp_t8 > 0);
    }
}

extern void func_8001C404(s32);
extern u8 D_8008F194[];
extern u8 D_8008F1A4[];
void func_8001F7F0(void *arg0) {
    u8 *var_s1;
    s32 var_s0;

    AudioSequence_Disable((u8 *)arg0);
    var_s1 = (u8 *)arg0;
    var_s0 = 0;
    var_s1 = var_s1;

    *(u8 *)(var_s1 + 0) = *(u8 *)(var_s1 + 0) & 0xFFFD;
    *(u16 *)(var_s1 + 0x10) = 0;
    *(u8 *)(var_s1 + 1) = 1;
    *(u16 *)(var_s1 + 0x12) = 0;
    *(u16 *)(var_s1 + 0x14) = 0;
    *(u16 *)(var_s1 + 0xA) = 0;
    *(u16 *)(var_s1 + 8) = 0x1680;
    *(u16 *)(var_s1 + 0xC) = 0;
    *(u16 *)(var_s1 + 0xE) = 0;
    *(u8 *)(var_s1 + 2) = 0;
    *(u32 *)(var_s1 + 0x94) = (u32)D_8008F194;
    *(u32 *)(var_s1 + 0x98) = (u32)D_8008F1A4;
    *(u32 *)(var_s1 + 0xE0) = 0;
    *(u16 *)(var_s1 + 0x16) = 0;
    *(f32 *)(var_s1 + 0x1C) = 1.0f;
    *(f32 *)(var_s1 + 0x20) = 0.0f;
    *(f32 *)(var_s1 + 0x24) = 0.0f;
    *(f32 *)(var_s1 + 0x28) = 0.5f;

    do {
        func_8001C404(*(s32 *)(var_s1 + 0x38));
        var_s0 += 4;
        var_s1 += 4;
    } while (var_s0 != 0x40);
}

extern u8 D_8011BE90[];
extern u8 D_8011EBF0[];
extern s32 func_80010510(u8 *, s32);
extern void func_8001C404(s32);
typedef struct {
 u8 unknown00[17]; u8 index; u8 unknown12[62]; void *player; void *layers[6];
} AudioPreallocatedChannel;
typedef struct { u8 unknown00[56]; AudioPreallocatedChannel *channels[16]; } AudioPreallocatePlayer;
void AudioSequence_AllocateChannels(s32 player_index) {
    typedef struct { u8 enabled:1; u8 low:7; } ChannelEnabledFlag;
    AudioPreallocatePlayer *player;
    AudioPreallocatedChannel *channel;
    s32 i;
    s32 j;
    player = (AudioPreallocatePlayer *)(D_8011BE90 + (player_index * 352 + 0x346C));
    for (i = 0; i < 16; i++) {
        player->channels[i] = (AudioPreallocatedChannel *)func_80010510(D_8011EBF0, 256);
        if (player->channels[i] == NULL) {
            player->channels[i] = (AudioPreallocatedChannel *)&D_80121DDC;
        } else {
            channel = player->channels[i];
            channel->player = player;
            channel->index = i;
            ((ChannelEnabledFlag *)channel)->enabled = 0;
            for (j = 0; j < 6; j++) {
                channel->layers[j] = NULL;
            }
        }
        func_8001C404((s32)player->channels[i]);
    }
}

extern void func_8001A9E4(void *);
extern void func_8001F7F0(void *arg0);
extern AudioChannelPrefix D_80121DDC;
void func_8001F9B0(void *arg0) {
    s32 i;
    s32 j;
    for (i = 0; i != 16; i++) {
        *(u8 **)((u8 *)arg0 + 0x38 + i * 4) = (u8 *)&D_80121DDC;
    }
    *(u8 *)arg0 &= 0xFF7F;
    *(u8 *)arg0 &= 0xDF;
    *(u8 *)arg0 &= 0xF7;
    *(u8 *)arg0 &= 0xEF;
    *(u8 *)arg0 &= 0xFE;
    for (j = 0; j != 8; j++) {
        *((s8 *)arg0 + 0x158 + j) = -1;
    }
    *((u8 *)arg0 + 3) = 0x60;
    *(f32 *)((u8 *)arg0 + 0x2C) = 1.0f;
    *(f32 *)((u8 *)arg0 + 0x34) = 1.0f;
    func_8001A9E4((u8 *)arg0 + 0x9C);
    func_8001F7F0(arg0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001FA80.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001FBE0.s")
#endif
