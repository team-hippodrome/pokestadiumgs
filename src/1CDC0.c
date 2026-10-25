#include "global.h"


#ifdef VERSION_US
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001C228.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001C404.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001C570.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001C6C8.s")

extern u8 D_80121EF4[];
extern void func_8001CB1C();
extern void func_8001C6C8();
void func_8001C744(void *arg0, s32 arg1) {
    s32 temp_a2;
    temp_a2 = *(s32 *)((u8 *)arg0 + (arg1 << 2) + 0x54);
    if (temp_a2 != 0) {
        func_8001CB1C(D_80121EF4, (void *)(u32)(temp_a2 + 0x80));
        func_8001C6C8(temp_a2);
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

extern u8 D_80121DDC[];
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

extern void func_8001CA3C(void);
void func_8001CA14(u8 *arg0) {
    *arg0 = ((*arg0) & 0xFF) | 0x40;
    func_8001CA3C();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001CA3C.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001CB9C.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001CCC8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001CDE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001CE70.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001CF5C.s")

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

    func_8001CA3C();
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

#pragma GLOBAL_ASM("asm/us/nonmatchings/1CDC0/func_8001F8C0.s")

extern void func_8001A9E4(void *);
extern void func_8001F7F0(void *arg0);
extern u8 D_80121DDC[];
void func_8001F9B0(void *arg0) {
    s32 i;
    s32 j;
    for (i = 0; i != 16; i++) {
        *(u8 **)((u8 *)arg0 + 0x38 + i * 4) = D_80121DDC;
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
