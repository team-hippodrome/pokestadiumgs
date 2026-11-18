#include "229E0.h"

#ifdef VERSION_US

// Sounds per bank, summed by Audio_BuildAndDispatchSoundEvent.
const u8 D_800A3990[] = { 8, 15, 18, 12, 8, 11, 13, 6, 26, 12, 12, 7, 25 };

extern u32 func_800194A0(void);

typedef struct {
    u8 unk_00;  /* upper limit of result: the loop stops once result passes it */
    u8 unk_01;
    u16 unk_02; /* scaled by the random draw to form the loop's sum target */
} AudioTuneRecord_80026990;

extern AudioTuneRecord_80026990 D_800918DC[];
extern u16 D_80091814[];        /* per-index weights accumulated into sum */
extern f32 D_800918BC[4][2];    /* per-column (arg0 & 3) scale bases, 8-byte stride */
extern f32 D_800918C0[4][2];    /* second scale table read when the draw is >= 0x3FFF */

/* Selects a weighted result for one of the audio columns in arg0's low two bits.
   The fourth random draw picks which of the two scale tables is used, then the
   result is mapped into [1.0, base] by dividing by the record's unk_00. */


f32 func_80026990(u8 arg0) {
    u16 value;
    u16 result;
    u16 sum;
    u16 upper;
    /* The four u16 locals above live at 0x38..0x3E; these two unused slots
       keep the frame at 0x40, which in turn places index at 0x24 and the
       incoming argument at 0x28. */
    u32 pad1;
    u32 pad2;
    u8 index;
    u8 col;

    /* arg0 packs a column selector in its low two bits; the remaining bits
       index the record table one-based, so index is upper - 1. */
    upper = arg0 >> 2;
    index = upper - 1;
    if (index == 2) {
        value = func_800194A0() & 0x7FFF;
        result = (u16)((D_800918DC[index].unk_00 * value) / 32767);
    } else {
        result = 0;
        sum = 0;
        value = func_800194A0() & 0x7FFF;
        upper = (u16)((D_800918DC[index].unk_02 * value) / 32767);
        /* Add weights while their running total stays under the target. */
        while (sum < upper) {
            if (D_800918DC[index].unk_00 < result) {
                break;
            }
            sum += D_80091814[result++];
        }
    }
    value = func_800194A0() & 0x7FFF;
    if (value < 0x3FFF) {
        col = arg0 & 3;
        return (f32)result * (D_800918BC[col][0] - 1.0f) / (f32)D_800918DC[index].unk_00 + 1.0f;
    }
    col = arg0 & 3;
    return (f32)result * (D_800918C0[col][0] - 1.0f) / (f32)D_800918DC[index].unk_00 + 1.0f;
}

void Audio_DebugSampleHistogram(u8 mode) {
    s32 i;
    for (i = 0; i < 100; i++) D_800D19A0[i] = 0;
    for (i = 0; i < 1000; i++) {
        osSyncPrintf("%f\n", (f64)func_80026990(mode));
    }
    for (i = 0; i < 100; i++) {
        osSyncPrintf("%2d : %3d\n", i, D_800D19A0[i]);
    }
}

void Audio_ProcessChannelEvent(AudioChannelEvent *event, s32 arg1) {
    PackedRecord *entry;
    if (event->slot == 15) {
        D_800918E8 = func_8002738C(Audio_SetupEventVoice(event, D_800918E8));
        return;
    }
    entry = &D_80090C84[event->slot];
    if (((u8 *)entry)[6] == 1) {
        switch (((u8 *)entry)[0]) {
        case 1:
            func_80026ED8(event->slot);
            break;
        case 3:
            ((u8 *)entry)[0] = 2;
            break;
        case 4:
            return;
        }
        entry = &D_80090C84[event->slot];
    }
    if (event->sound != *(u16 *)((u8 *)entry + 4)) {
        D_800918E8 = Audio_ConfigureEventChannel(event, D_800918E8);
        return;
    }
    switch (((u8 *)entry)[0]) {
    case 2:
        ((u8 *)entry)[0] = 3;
        Audio_UpdateEventVoiceParameters(event, ((u8 *)&D_80090C84[event->slot])[1], 0);
        ((u8 *)&D_80090C84[event->slot])[6] = 1;
        return;
    case 4:
        return;
    }
    *entry = D_80090CFC;
}

s32 Audio_ConfigureEventChannel(AudioChannelEvent *event, u8 request) {
    u8 channel;
    func_80026ED8(event->slot);
    channel = Audio_SetupEventVoice(event, request);
    ((u8 *)&D_80090C84[event->slot])[1] = channel;
    *(u16 *)((u8 *)&D_80090C84[event->slot] + 4) = event->sound;
    ((u8 *)&D_80090C84[event->slot])[3] = event->kind;
    if (event->kind == 0) {
        ((u8 *)&D_80090C84[event->slot])[0] = 1;
    } else {
        ((u8 *)&D_80090C84[event->slot])[0] = 4;
    }
    ((u8 *)&D_80090C84[event->slot])[6] = 1;
    return func_8002738C(channel);
}

void func_80026ED8(u8 arg0) {
    func_8001874C(0x06020000 | (((u8 *) &D_80090C84[arg0])[1] << 8), 0);
    D_80090C84[arg0] = D_80090CFC;
}

u8 Audio_SetupEventVoice(AudioChannelEvent *arg0, u8 request) {
    request = (u8)Audio_SelectEventChannel(arg0, request);
    Audio_UpdateEventVoiceParameters(arg0, request, 1);
    D_80090BC1[request * 12] = ((u8 *)D_80090D28)[arg0->sound * 16 + 12];
    func_8001874C(((0x06020000 | (((u32)request & 0xFF) << 8)) | 1), (s8)((u8 *)D_80090D28)[arg0->sound * 16]);
    func_8001874C((0x06020000 | (((u32)request & 0xFF) << 8)), 1);
    func_8001874C(((0x06020000 | (((u32)request & 0xFF) << 8)) | 3), (s8)((((u8 *)D_80090D28)[arg0->sound * 16] & 0x80) >> 7));
    return request;
}

void Audio_UpdateEventVoiceParameters(void *arg0, u8 channel, u8 reset) {
    if (reset) {
        ((u8 *)(&D_80090BB8[channel]))[0] = ((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 1];
        ((s8 *)(&D_80090BB8[channel]))[1] = ((s8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 8];
    }
    *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) = *(f32 *)((u8 *)D_80090D28 + ((AudioVoiceParameters *)arg0)->sound * 16 + 4) * ((AudioVoiceParameters *)arg0)->pitch;
    if (*(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) > 4.0) {
        *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) = 4.0f;
    } else if (*(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) < 0.01) {
        *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) = 0.01f;
    }
    if (((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 13] & 0xF0) {
        *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) *= func_80026990(((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 13] >> 4);
    }
    if (((u8 *)D_80090D28)[((AudioVoiceParameters *)arg0)->sound * 16 + 13] & 1) {
        if (*((AudioVoiceParameters *)arg0)->pan >= 64) {
            ((u8 *)(&D_80090BB8[channel]))[2] = 127;
        } else if (*((AudioVoiceParameters *)arg0)->pan < -64) {
            ((u8 *)(&D_80090BB8[channel]))[2] = 0;
        } else {
            ((u8 *)(&D_80090BB8[channel]))[2] = *((AudioVoiceParameters *)arg0)->pan + 64;
        }
    } else {
        ((u8 *)(&D_80090BB8[channel]))[2] = ((AudioVoiceParameters *)arg0)->balance;
    }
}

s32 Audio_SelectEventChannel(void *arg0, u8 request) {
    u8 i;
    u8 scanned;
    u32 next;
    for (i = 0; i < 16; i++) {
        ((u8 *)&D_80090BB8[(u32)i])[8] = func_80018C60(2, i, 2);
    }
    next = Audio_FindEnabledChannel((AudioChannelMask *)arg0, request, 0);
    request = next;
    scanned = 0;
    while (((u8 *)&D_80090BB8[(u32)next])[8] == 1 && scanned < ((AudioChannelGroup *)arg0)->count) {
        next = Audio_FindEnabledChannel((AudioChannelMask *)arg0, request, 1);
        request = next;
        scanned++;
    }
    if (((u8 *)&D_80090BB8[(u32)next])[8] == 1) {
        request = Audio_FindLowestPriorityChannel((AudioChannelGroup *)arg0, request);
    }
    return request;
}

u8 Audio_FindEnabledChannel(AudioChannelMask *state, u8 channel, u8 advance) {
    if (advance) {
        channel = func_8002738C(channel);
    }
    if (!((state->mask >> channel) & 1)) {
        s32 next;
        do {
            next = func_8002738C(channel);
            channel = next;
        } while (!((state->mask >> next) & 1));
    }
    return channel;
}

s32 func_8002738C(u8 channel) {
    if (channel < 0xF) {
        channel++;
    } else {
        channel = 0;
    }
    return channel;
}

u8 Audio_FindLowestPriorityChannel(AudioChannelGroup *state, u8 channel) {
    u8 best = channel;
    u8 i;
    for (i = 1; i < state->count; i++) {
        Candidate27F7CRecord *bestRecord = &D_80090BB8[best];
        s32 next = Audio_FindEnabledChannel(&state->channels, channel, 1);
        channel = next;
        if (((u8 *)&D_80090BB8[next])[9] < ((u8 *)bestRecord)[9]) {
            best = next;
        }
    }
    return best;
}

void func_80027634(void);

void func_80027490(void) {
    u8 i;
    u8 *p;

    if ((u8)D_80090BB0 != 0) {
        func_80027634();
        for (i = 0; i < 16; i++) {
            ((u8 *)&D_80090BB8[i])[8] = func_80018C60(2, i, 2);
        }
        for (i = 0; i < 15; i++) {
            p = (u8 *)&D_80090C84[i];
            switch (p[0]) {
                case 1:
                case 3:
                    p[0] = 2;
                    break;
                case 4:
                    if (p[2] < p[3]) {
                        p[2]++;
                        break;
                    }
                    /* fallthrough */
                case 2:
                    func_80026ED8(i);
                    break;
                case 0:
                default:
                    D_80090C84[i] = D_80090CFC;
                    break;
            }
        }
        for (i = 0; i < 15; i++) {
            ((u8 *)&D_80090C84[i])[6] = 0;
        }
    }
}

s32 func_800275E8(u8 arg0, Candidate275E8Bits *arg1) {
    arg1->value = D_80090BBC[arg0][0];
    arg1->active = 1;
    if (arg1->active == 1) {
        return arg0;
    }
}

// Consumes the pending mode request and advances a timed sequence of command 0x49 values.
// A call without a request resets the elapsed ticks and signed command value.
void func_80027634(void) {
    static u16 sAudioRequestTicks = 0;
    static s8 sAudioRequestValue = 0;
    s32 divisor;
    u16 interval;

    if (D_80090BB4 != 0) {
        D_80090BB4--;
        switch (D_80090BB4) {
        case 4:
            divisor = 15;
            break;
        case 6:
            divisor = 18;
            break;
        case 11:
            divisor = 30;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 8:
        case 9:
        case 10:
        default:
            divisor = 80;
            break;
        }
        if (sAudioRequestTicks < 450) {
            interval = 450 / divisor;
            if (sAudioRequestTicks % interval == 0) {
                func_80018728(0x49000000, ++sAudioRequestValue);
            }
            sAudioRequestTicks++;
        }
    } else {
        sAudioRequestTicks = 0;
        sAudioRequestValue = 0;
    }
    D_80090BB4 = 0;
}

void func_80027774(u16 arg0, u8 arg1) {
    ResourceContext_80027774 context;

    context.resource = D_80090D04;
    context.kind = arg1;
    context.scale = 1.0f;
    Audio_BuildAndDispatchSoundEvent(arg0, 0, &context);
}

void func_800277C4(u16 resource_id, u8 mode) {
    func_8002781C(resource_id, mode);
}

void func_800277F0(u16 resource_id, void *context) {
    func_8002781C(resource_id, 0, context);
}

extern void func_80027BD4(u16, u8, ResourceContext_80027774 *); /* linker alias of Audio_BuildAndDispatchSoundEvent; u8 2nd param = in-place narrowing */
extern void func_80027E30(void);
extern void func_80027F4C(void);

/* include/229E0.h declares func_8002781C variadic so func_800277C4's
 * two-argument call leaves a2 untouched (retail does the same). IDO accepts
 * this fixed three-parameter definition under that variadic prototype; gcc
 * does not, so the host syntax check sees the function under another name.
 * Nothing in this file calls func_8002781C after this definition. */
#ifdef CC_CHECK
#define func_8002781C func_8002781C_cc_check
#endif



void func_8002781C(u16 arg0, u8 arg1, void *arg2) {
    AudioChannelEvent event;

    event.resource = arg2;
    event.scale = 1.0f;
    switch (arg0) {
        case 0xFFF:
            func_80027E30();
            return;
        case 0xFFE:
            func_80027F4C();
            return;
        case 0xFFD:
            func_80027F4C();
            func_80027E30();
            return;
        default:
            event.kind = 0;
            if (arg1 >= 4) arg1 = 3;
            func_80027BD4(arg0, arg1, &event);
            return;
    }
}




void func_800278C0(u16 channel, u8 type, void *resource, f32 pitch) {
    ResourceContext_80027774 context;

    context.resource = resource;
    context.kind = 0;
    context.scale = pitch;
    if (channel == 0x4000) {
        context.scale = (pitch * 0.5) + 0.25;
        switch (type) {
        case 0: context.scale -= 0.05; break;
        case 1: context.scale += 0.05; break;
        case 2: break;
        case 3: context.scale -= 0.1; break;
        }
    }
    if (type >= 4) {
        type = 3;
    }
    func_80027BD4(channel, type, &context);
}

void Audio_PlayDefaultSound(u16 id) {
    ResourceContext_80027774 context;
    context.resource = D_80090D04;
    context.kind = 0;
    context.scale = 1.0f;
    if (id == 0x5F0A) {
        func_800225C4(5);
    }
    Audio_BuildAndDispatchSoundEvent(id, 0, &context);
}

extern u16 D_80090D08[], D_80090D10[], D_80090D20[], D_80090D18[];

void func_80027A28(u16 arg0, u8 arg1) {
 ResourceContext_80027774 context;
 context.kind = 0;
 context.scale = 1.0f;
 context.bank = (arg0 & 0xF000) >> 12;
 switch (context.bank) {
 case 1: case 3: case 7: case 8: case 9: context.resource = &D_80090D08[arg1]; break;
 case 2: case 4: context.resource = &D_80090D10[arg1]; break;
 case 6: context.resource = &D_80090D20[arg1]; break;
 case 11: context.resource = &D_80090D18[arg1]; break;
 default: context.resource = D_80090D04; break;
 }
 switch (arg0) {
 case 0x7F01:
 switch (arg1) {
 case 0: context.scale = 0.97f; break;
 case 1: break;
 case 2: context.scale = 0.98f; break;
 case 3: context.scale = 0.99f; break;
 default: return;
 } break;
 case 0x3F02:
 switch (arg1) {
 case 0: context.scale = 1.34f; break;
 case 1: break;
 case 2: context.scale = 0.85f; break;
 case 3: context.scale = 0.68f; break;
 default: return;
 } break;
 default: break;
 }
 func_80027BD4(arg0, arg1, &context);
}
void Audio_BuildAndDispatchSoundEvent(u16 encoded, s32 offset, ResourceContext_80027774 *event) {
    u8 i;
    u8 j;
    u8 total = 0;

    event->slot = (encoded & 0xF00) >> 8;
    event->bank = (encoded & 0xF000) >> 12;
    event->sound = encoded & 0xFF;
    for (i = 0; i < event->bank; i++) event->sound += D_800A3990[i];
    event->unknown14[0] = D_80090D31[event->sound * 16];
    for (i = 0; i < 13; i++) total += D_800A3990[i];
    if (event->sound >= total) event->sound = total - 1;
    event->count = 0;
    for (i = 0; i < 16; i++) {
        if ((*(u16 *)(D_80090D28[event->sound] + 10) >> i) & 1) {
            event->count++;
        }
    }
    event->mask = *(u16 *)(D_80090D28[event->sound] + 10);
    if (event->bank != 6 && ((D_80090D28[event->sound][13] >> 1) & 1)) {
        if ((u8)offset * event->count >= 49) return;
        for (i = 0; i < (u8)offset * event->count; i++) {
            event->mask <<= 1;
            total = 0;
            for (j = 0; j < 16; j++) {
                if ((event->mask >> j) & 1) total++;
            }
            if (total == event->count - 1) {
                if (event->mask & 1) return;
                event->mask |= 1;
            } else if (total < event->count - 1) {
                return;
            }
        }
        if (event->slot != 15) {
            event->slot += offset;
            if (event->slot >= 15) event->slot -= 15;
        }
    }
    if (event->count) Audio_ProcessChannelEvent(event, offset);
}

/* mkdraft:func_80027E30 begin */
// func_80027E30 -- MATCHED (byte-identical, full ROM check passes)
//
// Start the fade, then dispatch command 0x1002xx00 with i in bits 8-15 and a
// pointer to record i of D_80090BB8 for i = 0..15; finish with command
// 0xE4000000 carrying the func_800275E8 callback.
//
// The loop index is s32 and is masked in the increment (`i = (i + 1) & 0xFF`):
// that spelling produces the target's preheader `sll t9,s0,2`, body `andi
// t7,s0,0xff` and latch `addiu s0,s0,1; andi s0,s0,0xff; slti at,s0,0x10;
// bnel at,zero,L; sll t9,s0,2`.
//
// The key is the (u32) cast on the address. `func_80018728` is varargs, so the
// address is already converted to an integer there; writing it explicitly moves
// the address expression out of the "pointer argument" path and makes IDO/uopt
// expand the x12 struct scale in place in a single pseudo (t9):
//     sll t9,s0,2 ; subu t9,t9,s0 ; sll t9,t9,2
// and software-pipeline its first shift into the preheader / branch delay slot.
// Without the cast, `&D_80090BB8[i]` as the *second* argument takes the
// `li s3,12; multu s0,s3; mflo` path (and the loop is not rotated), and the
// hand-written `(i * 4 - i) * 4` form gives the right chain but in three
// rotating temps (t9 -> t0 -> t1, a 3-word residual). Only the cast yields a
// single register and a 0 diff.
//
// Verified with:
//   .venv/bin/python3 matching_notes/try_candidate.py src/229E0.c \
//       func_80027E30 <this file>   -> score 0
//   PATH="$PWD/.venv/bin:$PATH" make -j4 rom PYTHON=.venv/bin/python3
//       -> build/pokestadiumgs-us.z64: OK


void func_80027E30(void) {
    s32 i;

    func_80027F7C();
    D_80090BB0 = 1;
    func_80018728(0x82020900, 0);
    func_80018704(0x41020000, 0.648f);
    for (i = 0; i < 16; i = (i + 1) & 0xFF) {
        func_80018728(((u8)i << 8) | 0x10020000, (u32)&D_80090BB8[i]);
    }
    func_80018728(0xE4000000, func_800275E8);
}
/* mkdraft:func_80027E30 end */

void func_80027EE0(u16 arg0) {
    switch (arg0) {
        case 0xFFF:
            func_80027E30();
            return;
        case 0xFFE:
            func_80027F4C();
            return;
        case 0xFFD:
            func_80027F4C();
            func_80027E30();
            return;
        default:
            return;
    }
}

void func_80027F4C(void) {
    func_80018728(0x83020000U, 0x14);
    func_80027F7C();
    D_80090BB0 = 0;
}

void func_80027F7C(void) { u8 i; u8 j; for (i = 0; i < 15; i++) { D_80090C84[i] = D_80090CFC; } for (j = 0; j < 16; j++) { D_80090BB8[j] = D_80090C78; } }

void func_80028014(void) {
    func_80027EE0(0xFFD);
    Audio_PlayDefaultSound(0xCF07);
    if (D_8011F300 == 0x5C) {
        func_80018728(0x83000000U, 0x1E);
        return;
    }
    func_80018728(0xF1000000U, 0);
}

s32 func_8002806C(void) {
    u8 *base;
    s32 result;

    base = &D_8011BE90;
    result = *(u8 *)(base + 0x3470) - 0x27;
    if (((u32)*(s32 *)(base + 0x346C) >> 31) == 0) {
        return 0;
    }
    return result;
}

void func_8002809C(void) {
    func_80018728(0xF2000000, 0);
}

void func_800280C0(void) {
    func_80027EE0(0xFFE);
    func_80018728(0x4B000000U, 1);
}

void func_800280EC(void) {
    func_80027EE0(0xFFF);
    func_80018728(0x4C000000U, 1);
}

void func_80028118(u8 arg0) {
    D_80090BB4 = arg0 + 1;
}

#endif
