#include "global.h"


#ifdef VERSION_US
extern u8 D_8011FA5C[];
extern u8 D_8011F9DC[];
extern u8 D_8011BE90[];
extern u8 D_80121F44[];
extern void func_8001ED64(void *);
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
extern s32 func_8001DA54(void *, s32);
extern s32 func_8001D340(void *, s32);
extern s32 func_8001CE70(void *, s32);
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
            if (command != -1) { func_8001CE70(layer, command); }
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001CE70.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001DA54.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001DFF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001ED64.s")

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
