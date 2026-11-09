#include "229E0.h"

#ifdef VERSION_US

// func_800289B0 shifts these 24 IDs toward the oldest entry.
u32 gAudioRecentSoundHistory[24];
extern s32 D_80090B94;
extern s32 D_80090B98;
extern s32 func_800265B0(u32 arg0, s32 arg1);

extern s32 D_80090B5C;
extern s32 func_80018B78(s32 arg0);
extern void func_8002AAFC(s32);
void func_800260C0(s32 kind, s32 category, s32 request) {
    s32 group;
    s32 index;
    u8 force;
    Color_80026938 *entry;

    force = 0;
    func_8002AAFC(0);
    D_80090220 = 0;
    D_80090A54 = 0;
    func_80018728(0x83040000, 0);
    if (kind == 11) {
        kind = 2;
        force = 1;
    }
    switch (kind) {
        case 1:
        case 2:
        case 5:
        case 7:
        case 9:
        case 10:
            group = 1;
            break;
        case 0:
            group = 0;
            break;
        case 3:
        case 4:
            group = 5;
            break;
        case 6:
            group = 6;
            break;
        case 13:
            group = 8;
            break;
        case 12:
            group = 7;
            break;
        case 8:
            index = Audio_GetEventConfigIndex(category, request);
            if (index < 0) {
                index = 0;
            }
            if (D_80090B70 == -1) {
                entry = &D_80090AD0[index];
                group = entry->first;
            } else {
                group = D_80090B70;
                entry = &D_80090AD0[index];
            }
            if (D_80090B6C == -1) {
                D_80090BA0 = entry->second;
            } else {
                D_80090BA0 = D_80090B6C;
            }
            func_8002A80C(entry->third);
            func_8002A7A8(category, request);
            D_80090B94 = category;
            D_80090B98 = request;
            break;
        case 30:
            group = 2;
            break;
        default:
            return;
    }
    D_80090B60 = kind;
    if (force == 0 && group == D_80090B5C) {
        D_80090B64 = 0;
    } else {
        D_80090B5C = group;
        D_80090B64 = 1;
        D_80090B68 = 1;
        D_80090B9C = 0;
        func_80018B78(group);
    }
}

s32 func_80026298(void) {
    func_80018810();
    if (D_80090B64 != 0) {
        if (func_80018ACC() == 0) {
            return 0;
        }
        D_80090B64 = 0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 1;
    }
    return 1;
}

void Audio_ResetCategoryState(void) {
    D_80090B64 = 0;
    D_80090B6C = -1;
    D_80090B70 = -1;
    func_80018728(0x82010000U, 0);
    func_80018704(0x41010000, 0.63f);
    D_80090B80 = 1;
    switch (D_80090B60) {
    case 2:
    case 3:
    case 5:
    case 7:
    case 9:
    case 10:
        func_80018728(0x82040500U, 0);
        func_80018704(0x41040000, 0.63f);
    case 1:
    case 4:
        if (D_80090B9C == 0) {
            func_80018728(0x82020400U, 0);
            func_80018704(0x41020000, 0.63f);
            D_80090B9C = 1;
        }
        break;
    case 12:
        func_80018728(0x82030800U, 0);
        func_80018704(0x41030000, 0.72f);
        break;
    case 0:
        func_80018728(0x82020600U, 0);
        func_80018704(0x41020000, 0.648f);
        break;
    }
    if (D_80090B60 == 3 || D_80090B60 == 4 || D_80090B60 == 6) {
        func_80018728(0x82030300U, 0);
        func_80018704(0x41030000, 0.765f);
        func_800187AC();
        func_80025E7C();
    }
    if (D_80090B68 != 0) {
        D_80090B68 = 0;
        switch (D_80090B60) {
        case 0:
            func_80018728(0x82020600U, 0);
            break;
        case 12:
            func_80018728(0x82040200U, 0);
            func_80018704(0x41020000, 1.0f);
            break;
        case 8:
            func_80018728(0x82040200U, 0);
            func_80018704(0x41020000, 1.0f);
            func_80018728(0x82020100U, 0);
            func_80018704(0x41020000, 0.63f);
            func_80018728(0x82010A00U, 0);
            func_80018728(0x82010000U, 0);
            func_80018704(0x41010000, 0.63f);
            D_80090B80 = 1;
            func_80024D44();
            func_80018728(0x82032300U, 0);
            D_80090A50 = 35;
            break;
        case 30:
            func_80024D44();
            func_80018728(0x82032300U, 0);
            D_80090A50 = 35;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
        case 11:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
            break;
        }
    }
}

/* mkdraft:func_800265B0 begin */

// Case 18's body is emitted before the -1 and -2 bodies: jump-table entries 16, 17 and 18
// point at 0x80026658, 0x80026660 and 0x80026650, so the case labels appear in that order.


s32 func_800265B0(u32 arg0, s32 arg1) {
    s32 result;

    switch (arg0) {
    case 0: result = 0; break;
    case 1: result = 9; break;
    case 2: result = 18; break;
    case 3: result = 27; break;
    case 4: result = 36; break;
    case 5: result = 45; break;
    case 6: result = 54; break;
    case 7: result = 63; break;
    case 8: result = 72; break;
    case 9: result = 81; break;
    case 10: result = 90; break;
    case 11: result = 113; break;
    case 12: return 118;
    case 13: result = 119; break;
    case 14: return 127;
    case 15: return 128;
    case 18: return 131;
    case 16: result = -1; break;
    case 17: result = -2; break;
    default: return 132;
    }
    switch (arg1) {
    case 10:
        if (D_80090B94 >= 10 && D_80090B94 < 16) {
            result += arg1;
        }
        break;
    case 11:
        if (D_80090B94 >= 10 && D_80090B94 < 16) {
            result += arg1;
            break;
        }
        return -2;
    case 40:
        return -3;
    default:
        // No break: the add falls out of the switch into `return result`, which schedules it
        // into the delay slot of the 40 comparison.
        result += arg1;
    }
    return result;
}
/* mkdraft:func_800265B0 end */

s32 Audio_GetEventConfigIndex(s32 category, u32 request) {
    switch (request) {
    case 10: return 31;
    case 11: return 32;
    case 40: return 33;
    }
    switch (category) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 5: return 5;
    case 6: return 6;
    case 7: return 7;
    case 8: return 8;
    case 9: return 9;
    case 10:
        if (request < 2) return 10;
        if (request >= 2 && request < 5) return 11;
        if (request >= 5 && request < 8) return 12;
        if (request >= 8 && request < 11) return 13;
        if (request >= 11 && request < 13) return 14;
        if (request >= 13 && request < 14) return 15;
        if (request >= 14 && request < 18) return 16;
        if (request >= 18 && request < 21) return 17;
        if (request >= 21 && request < 24) return 18;
        return -1;
    case 11: return 19;
    case 12: return 20;
    case 13:
        switch (request) {
        case 0: return 21;
        case 1: return 22;
        case 2: return 23;
        case 3: return 24;
        case 4: return 25;
        case 5: return 26;
        case 6: return 27;
        case 7: return 28;
        default: return -1;
        }
    case 14: return 29;
    case 15: return 30;
    case 18: return 34;
    case 19: return 35;
    }
    return -1;
}

void func_80026938(u16 arg0) {
    s32 index;
    Color_80026938 *entry;

    if (arg0 >= 0x1E) {
        arg0 = 0xE;
    }
    index = D_80090B3C[arg0];
    entry = &D_80090AD0[index];
    D_80090B6C = entry->second;
    D_80090B70 = entry->first;
}

#pragma C_FUNCTION_PADDING(8)

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
        osSyncPrintf(D_800A39A0, (f64)func_80026990(mode));
    }
    for (i = 0; i < 100; i++) {
        osSyncPrintf(D_800A39A4, i, D_800D19A0[i]);
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
    } else if (*(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) < D_800A39B0) {
        *(f32 *)((u8 *)(&D_80090BB8[channel]) + 4) = D_800A39B8;
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_80027490.s")

s32 func_800275E8(u8 arg0, Candidate275E8Bits *arg1) {
    arg1->value = D_80090BBC[arg0][0];
    arg1->active = 1;
    if (arg1->active == 1) {
        return arg0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_80027634.s")

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

extern f64 D_800A3A00, D_800A3A08, D_800A3A10;



void func_800278C0(u16 channel, u8 type, void *resource, f32 pitch) {
    ResourceContext_80027774 context;

    context.resource = resource;
    context.kind = 0;
    context.scale = pitch;
    if (channel == 0x4000) {
        context.scale = (pitch * 0.5) + 0.25;
        switch (type) {
        case 0: context.scale -= D_800A3A00; break;
        case 1: context.scale += D_800A3A08; break;
        case 2: break;
        case 3: context.scale -= D_800A3A10; break;
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_80027A28.s")

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

#pragma C_FUNCTION_PADDING(20)

void func_80028140(void) {
    (*(s32 *)((u8 *)(&D_800D1A70) + (0))) = -1;
    (*(s32 *)((u8 *)(&D_800D1A70) + (4))) = -1;
    (*(s32 *)((u8 *)(&D_800D1A78) + (0))) = -1;
    (*(s32 *)((u8 *)(&D_800D1A78) + (4))) = -1;
    (*(s8 *)((u8 *)(&D_800D1A80) + (0))) = 0x7F;
    (*(s8 *)((u8 *)(&D_800D1A80) + (1))) = 0x7F;
    (*(s8 *)((u8 *)(&D_800D1A82) + (0))) = 0;
    (*(s8 *)((u8 *)(&D_800D1A82) + (1))) = 0;
}

void Audio_QueueDeferredSound(s32 sound, s32 delay, u8 parameter) {
    u16 channel;
    u8 mode = 0;

    channel = (sound >= 266) ? 1 : 0;
    if (channel == 1) {
        mode = ((sound & 0xF000) == 0x3000) ? 2 : 1;
        sound &= 0xFFF;
    }
    func_8001874C((0x06040000 | ((u8)channel << 8)) | 3, 1);
    //!bug Zero delay becomes two before the immediate-play branch tests for zero.
    if (delay == 0) {
        delay = 2;
    }
    if (delay == 0) {
        func_8001874C((0x06040000 | ((u8)channel << 8)), sound % 64);
        func_8001874C((0x06040000 | ((u8)channel << 8)) | 1, sound / 64);
        func_8001874C((0x06040000 | ((u8)channel << 8)) | 2, parameter);
        if (channel == 1) {
            func_8001874C((0x06040000 | ((u8)channel << 8)) | 4, mode);
        }
    } else {
        D_800D1A70[channel] = sound;
        D_800D1A78[channel] = delay;
        D_800D1A80[channel] = parameter;
        D_800D1A82[channel] = mode;
    }
}

void func_80028300(void) {
    func_8001874C(0x06040003, 1);
    func_8001874C(0x06040103, 1);
    func_80028140();
}

void Audio_UpdateDeferredSounds(void) {
    u32 channel;
    s32 command;

    for (channel = 0; channel < 2; channel++) {
        if (D_800D1A70[channel] != -1) {
            if (D_800D1A78[channel] == 1) {
                func_8001874C((0x06040000 | ((u8)channel << 8)) | 3, 1);
            }
            if (D_800D1A78[channel] == 0) {
                command = 0x06040000 | ((u8)channel << 8);
                func_8001874C(command, D_800D1A70[channel] % 64);
                func_8001874C(command | 1, D_800D1A70[channel] / 64);
                func_8001874C(command | 2, D_800D1A80[channel]);
                if (channel == 1) {
                    func_8001874C(command | 4, D_800D1A82[channel]);
                }
                D_800D1A70[channel] = -1;
                D_800D1A78[channel] = -1;
                D_800D1A80[channel] = 127;
                D_800D1A82[channel] = 0;
            } else {
                D_800D1A78[channel]--;
            }
        }
    }
}

#pragma C_FUNCTION_PADDING(8)

u8 Audio_LookupScaledRatio(u16 numerator, u16 denominator) {
    s32 scaled = (numerator * 48) / denominator;
    s32 index = 0;
    for (; index < 6; index++) {
        if (D_8009210C[index * 2] >= scaled) {
            break;
        }
    }
    return D_8009210C[index * 2 + 1];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_80028540.s")

void Audio_SwapSoundCandidates(u8 *arg0, u8 *arg1) { if (*arg0 != *arg1) { u8 temp = *arg0; *arg0 = *arg1; *arg1 = temp; } }

u16 Audio_FilterRecentSoundId(u16 arg0) {
    s32 i;
    for (i = 0; i < 24; i++) {
        if (arg0 == D_800D1AD8[i]) return 0;
    }
    return arg0;
}

/* mkdraft:func_800289B0 begin */
void func_800289B0(u16 arg0) {
    s32 i;

    for (i = 0; i < 23; i++) {
        gAudioRecentSoundHistory[i] = gAudioRecentSoundHistory[i + 1];
    }
    gAudioRecentSoundHistory[23] = arg0;
}
/* mkdraft:func_800289B0 end */

void Audio_RemoveRecentSoundAt(u16 arg0) {
    u32 i;
    for (i = arg0; i > 0; i--) D_800D1AD8[i] = D_800D1AD8[i - 1];
    D_800D1AD8[0] = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_80028ADC.s")

void func_80028CA8(const void *sound_candidates) {
    s32 v0;
    s32 masked;

    v0 = func_80028ADC(sound_candidates);
    masked = v0 & 0xFFFF;
    if (v0 != 0) {
        func_800314D4(masked);
    }
}

void func_80028CA8_padding(void) {}

void func_80028CA8_padding2(void) {}

s32 func_80028CE8(void *arg0, s32 arg1) {
    struct Node { u32 a; u32 b; struct Node *next; };
    struct Root { u32 a; struct Node *next; };
    struct Node *node = ((struct Root *)arg0)->next;
    s32 i = 0;
    while (i != arg1) {
        if (node->next == 0) return (s32)node;
        node = node->next;
        i++;
    }
    return (s32)node;
}

/* mkdraft:func_80028D9C begin */
extern s32 func_80028CE8(void *arg0, s32 arg1);
extern void func_80028CA8(const void *sound_candidates);



void func_80028D9C(void *arg0) {
    struct Node { u32 a; u32 b; struct Node *next; };
    struct Root { u32 a; struct Node *next; };
    u32 pad0;                        // FAKE: unused; holds frame word 0x2c above count; diff score 24 without it.
    u32 count;
    u32 pad1[3];                     // FAKE: unused; holds frame words 0x24-0x1c below count; diff score 66 without it.
    struct Node *found;              // FAKE: second name for the matched node; keeps it in a stack home across the
                                     // two calls so uopt emits one reload after func_80028CA8; diff score 100 without it.
    struct Node *node;

    node = ((struct Root *)arg0)->next;
    count = 1;
    if (node->a == 0) {
loop:
        if (node->next != 0) {
            node = node->next;
            count++;
            if (node->a == 0) {
                goto loop;
            }
        }
    }
    found = node;
    func_80028CA8((const void *)((struct Node *)func_80028CE8(arg0, func_800194A0() % count))->b);
    node = found;
    ((struct Root *)arg0)->a++;
    if (node->next != 0 && ((struct Root *)arg0)->a >= node->a) {
        ((struct Root *)arg0)->next = node->next;
    }
}
/* mkdraft:func_80028D9C end */

s32 func_80028E60(u32 arg0)
{
  u8 *ptr;
  int value;
  u32 mask;
  s32 result;
  arg0--;
  ptr = &D_800D2660[arg0 >> 3];
  value = *ptr;
  mask = 1U << (arg0 & 7);
  result = value & mask;
  value |= mask;
  if ((mask = result) != 0U)
  {
    return 1;
  }
  *ptr = value;
  return mask != (mask = 0);
}

void func_80028EA8(void) { extern u8 D_80091B90[]; func_80028D9C(D_80091B90); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_80028ECC.s")

void Audio_ResetQueueAndBitmap(void) {
    s32 i;
    for (i = 0; i < 10; i++) {
        D_800D1A90[i] = 0;
    }
    D_80091A24 = 0;
    D_80091A28 = 0;
    for (i = 0; i < 32; i++) {
        D_800D2660[i] = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_8002A25C.s")

void func_8002A7A8(s32 arg0, s32 arg1) { D_800D2650[0] = arg0; D_800D2650[1] = arg1; D_800D2650[3] = D_80090BA0; if (D_80090BA0 == 1) D_800D2650[2] = 1; else D_800D2650[2] = 0; D_800D2650[4] = 0; *(u32 *)(D_800D2650 + 8) = 0; }

void func_8002A7E8(s32 arg0) {
    if (arg0 != 0) {
        D_80091A0C = 1;
        return;
    }
    D_80091A0C = 0;
}

void func_8002A80C(s32 arg0) {
    if (arg0 != 0) {
        D_80091A10 = 1;
        return;
    }
    D_80091A10 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_8002A830.s")

void func_8002A9C0(s32 arg0) {
    D_800D2630 = arg0;
}

void func_8002A9CC(s32 arg0) {
    D_800D2634 = arg0;
}

void func_8002A9D8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        osSyncPrintf(D_800A3A60, i);
        osSyncPrintf(D_800A3A6C, D_800D1B78[i][1]);
        osSyncPrintf(D_800A3A84, D_800D1B80[i][0]);
        osSyncPrintf(D_800A3A94, D_800D1B80[i][3]);
        osSyncPrintf(D_800A3AA4, D_800D1B80[i][4]);
    }
}

void func_8002AAD0(u8 arg0) {
    if (arg0) {
        D_80091A18 = 1;
        return;
    }
    D_80091A18 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_8002AAFC.s")

void func_8002B1A0(void) { func_8002A25C(); func_80024180(0, 0); }

/* mkdraft:func_8002B1CC begin */
extern u16 D_80091900[];
extern u8 D_80091A14;
extern s32 func_800265B0();
extern void func_800314D4(s32);
extern void func_80031530(u16);



void func_8002B1CC(void) {
    s32 index;
    s32 sel;

    D_80091A14 = 1;
    if (D_80090B98 == 0x28) {
        func_800314D4(0x3117);
        return;
    }
    index = D_80090B94;
    if ((index < 0xA) || (index >= 0x10)) {
        if (D_80090B98 == 0xA) {
            func_800314D4(0x310C);
            func_80031530(6);
            index = D_80090B94;
        } else if (D_80090B98 == 0xB) {
            func_800314D4(0x3116);
            func_80031530(6);
            index = D_80090B94;
        }
        if (index == 0x10) {
            func_800314D4(0x3115);
            return;
        }
        if (index == 0x11) {
            func_800314D4(0x3114);
            return;
        }
    }
    // FAKE: empty block; it ends the outer if's basic block. Without it the tail
    // D_80090B98 load is `lui a1; lw a1,(a1)` instead of `lui v0; lw a1,(v0)`; diff score 10.
    if (1) {
    }
    sel = D_80090B98;
    if ((sel == 0xB) && ((index < 0xA) || (index >= 0x10))) {
        sel = 0xA;
    }
    // FAKE: ^ 0 is a no-op. Without it IDO keeps index in a2 rather than v1 for the rest of
    // the tail; diff score 95.
    index = func_800265B0(index ^ 0, sel);
    if (index < 0) {
        index = 0;
    }
    func_800314D4(D_80091900[index]);
}
/* mkdraft:func_8002B1CC end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/26CC0/func_8002B2FC.s")

void func_8002B43C(void) {
    D_80091A18 = 0;
    func_8002AAFC(0);
    func_80023A3C(3, 0, 0);
    func_800314D4(0x2226);
}

void func_8002B47C(s32 arg0, s32 arg1) {
    D_80091B08 = arg0;
    D_80091B0C = arg1;
}

void Audio_RequestSlot(u8 slot) {
    if (D_80091AC8 != 0) {
        if (D_800D1B3B == 0)
        {
            func_800314D4(0x2028);
        }
        if (D_800D2640[slot] < 2U) {
            D_800D269E[slot] = 1;
        }
    } else {
        if (D_800D2640[slot] < 2U) {
            if (*(D_800D269E + slot) != 0) {
                if (D_800D1B3B == 0) {
                    func_80028CA8(D_80091F00);
                }
            } else if (D_800D1B3B == 0) {
                func_80028CA8(D_80091EF8);
            }
            *(D_800D269E + slot) = 1;
        } else if (D_800D1B3B == 0) {
            func_80028CA8(D_80091EEC);
        }
    }
    D_80091AC8 = 1;
}

#endif
