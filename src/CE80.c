#include "global.h"

// Audio command encoders for the RSP audio microcode this driver builds lists
// for. Opcodes and field layouts follow Majora's Mask include/PR/abi.h
// (A_RESAMPLE 0x05, A_SETBUFF 0x08, A_DMEMMOVE 0x0A, A_MIXER 0x0C,
// A_INTERL 0x11, A_ENVSETUP1 0x12, A_LOADBUFF 0x14, A_SAVEBUFF 0x15,
// A_ENVSETUP2 0x16). libultra's PR/abi.h macros encode a different opcode
// set, so these local encoders write the two command words directly.
#define AUDIO_CMD(pkt, word0, word1) \
    {                              \
        Acmd *_cmd = (Acmd *)(pkt); \
        _cmd->words.w0 = (word0);   \
        _cmd->words.w1 = (word1);   \
    }
#define aResample_GS(pkt, f, p, s) \
    AUDIO_CMD(pkt, _SHIFTL(0x05, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(p, 0, 16), (unsigned int)(s))
#define aSetBuffer_GS(pkt, f, i, o, c)                                            \
    AUDIO_CMD(pkt, _SHIFTL(0x08, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(i, 0, 16), \
              _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16))
#define aDMEMMove_GS(pkt, i, o, c) \
    AUDIO_CMD(pkt, _SHIFTL(0x0A, 24, 8) | _SHIFTL(i, 0, 24), _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16))
#define aMix_GS(pkt, f, g, i, o)                                                  \
    AUDIO_CMD(pkt, _SHIFTL(0x0C, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16), \
              _SHIFTL(i, 16, 16) | _SHIFTL(o, 0, 16))
#define aInterl_GS(pkt, i, o, c) \
    AUDIO_CMD(pkt, _SHIFTL(0x11, 24, 8) | _SHIFTL(c, 0, 16), _SHIFTL(i, 16, 16) | _SHIFTL(o, 0, 16))
#define aLoadBuffer_GS(pkt, s, d, c) \
    AUDIO_CMD(pkt, _SHIFTL(0x14, 24, 8) | _SHIFTL((c) >> 4, 16, 8) | _SHIFTL(d, 0, 16), (unsigned int)(s))
#define aSaveBuffer_GS(pkt, s, d, c) \
    AUDIO_CMD(pkt, _SHIFTL(0x15, 24, 8) | _SHIFTL((c) >> 4, 16, 8) | _SHIFTL(s, 0, 16), (unsigned int)(d))
#define aEnvSetup1_GS(pkt, a, b, c, d)                                            \
    AUDIO_CMD(pkt, _SHIFTL(0x12, 24, 8) | _SHIFTL(a, 16, 8) | _SHIFTL(b, 0, 16), \
              _SHIFTL(c, 16, 16) | _SHIFTL(d, 0, 16))
#define aEnvSetup2_GS(pkt, vol_left, vol_right) \
    AUDIO_CMD(pkt, _SHIFTL(0x16, 24, 8), _SHIFTL(vol_left, 16, 16) | _SHIFTL(vol_right, 0, 16))
// The opcode word comes in through bits (D_8008FA4C at the only call site).
#define aEnvMixer_GS(pkt, dmemi, count, swap_lr, x0, x1, x2, x3, m, bits)                               \
    AUDIO_CMD(pkt,                                                                                       \
              (bits) | _SHIFTL((dmemi) >> 4, 16, 8) | _SHIFTL(count, 8, 8) | _SHIFTL(swap_lr, 4, 1) |   \
                  _SHIFTL(x0, 3, 1) | _SHIFTL(x1, 2, 1) | _SHIFTL(x2, 1, 1) | _SHIFTL(x3, 0, 1),        \
              (unsigned int)(m))

// Reverb ring-buffer update record, laid out like Majora's Mask
// ReverbBufferEntry (include/audio/reverb.h). Each reverb holds two frames of
// five records at +0x40 and a second set at +0x158; func_8000C280 fills them
// and the reverb load/save command builders read them.
typedef struct {
    /* 0x00 */ s16 numSamplesAfterDownsampling;
    /* 0x02 */ s16 numSamples;
    /* 0x04 */ s16 *unk_04;
    /* 0x08 */ s16 *unk_08;
    /* 0x0C */ s32 startPos;
    /* 0x10 */ s16 size;
    /* 0x12 */ s16 wrappedSize;
    /* 0x14 */ u16 loadResamplePitch;
    /* 0x16 */ u16 saveResamplePitch;
    /* 0x18 */ u16 saveResampleNumSamples;
} ReverbBufferEntry; // size = 0x1C

// Reverb state, laid out like Majora's Mask SynthesisReverb
// (include/audio/reverb.h). D_8011BE90 + 0x18 holds an array of these with a
// 0x2D0 stride (func_8000C280 indexes it by reverb index).
typedef struct {
    /* 0x000 */ u8 resampleFlags;
    /* 0x001 */ u8 useReverb;
    /* 0x002 */ u8 framesToIgnore;
    /* 0x003 */ u8 curFrame;
    /* 0x004 */ u8 downsampleRate;
    /* 0x005 */ s8 unk_005;
    /* 0x006 */ u16 delayNumSamples;
    /* 0x008 */ s16 unk_008;
    /* 0x00A */ u16 unk_00A;
    /* 0x00C */ u16 unk_00C;
    /* 0x00E */ u16 downsamplePitch;
    /* 0x010 */ s16 leakRtl;
    /* 0x012 */ s16 leakLtr;
    /* 0x014 */ u16 subDelay;
    /* 0x016 */ s16 unk_016;
    /* 0x018 */ u8 resampleEffectOn;
    /* 0x019 */ s8 resampleEffectExtraSamples;
    /* 0x01A */ u16 resampleEffectLoadUnk;
    /* 0x01C */ u16 resampleEffectSaveUnk;
    /* 0x01E */ u8 unk_01E[0x20 - 0x1E];
    /* 0x020 */ s32 nextReverbBufPos;
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ s16 *leftReverbBuf;
    /* 0x02C */ s16 *rightReverbBuf;
    /* 0x030 */ s16 *leftLoadResampleBuf;
    /* 0x034 */ s16 *rightLoadResampleBuf;
    /* 0x038 */ s16 *leftSaveResampleBuf;
    /* 0x03C */ s16 *rightSaveResampleBuf;
    /* 0x040 */ ReverbBufferEntry bufEntry[2][5];
    /* 0x158 */ ReverbBufferEntry subBufEntry[2][5];
    /* 0x270 */ u8 unk_270[0x2D0 - 0x270];
} SynthesisReverb; // size = 0x2D0


#ifdef VERSION_US
extern u8 D_8011BE90[];
// Same code as Majora's Mask AudioSynth_AddReverbBufferEntry (src/audio/lib/synthesis.c).
// D_8011BE90 + 0x18 is the SynthesisReverb array.
void func_8000C280(s32 num_samples, s32 update_index, s32 reverb_index)
{
    SynthesisReverb *reverb;
    ReverbBufferEntry *entry;
    s32 extra_samples;
    s32 num_samples_after_downsampling;
    s32 reverb_buf_pos;
    s32 temp_t2;
    s32 temp_t4;
    s32 count1;
    s32 count2;
    s32 next_reverb_sub_buf_pos;

    reverb = &((SynthesisReverb *)(D_8011BE90 + 0x18))[reverb_index];
    entry = &reverb->bufEntry[reverb->curFrame][update_index];

    num_samples_after_downsampling = num_samples / reverb->downsampleRate;

    // Apply resampling effect
    if (reverb->resampleEffectOn) {
        if (reverb->downsampleRate == 1) {
            count1 = 0;
            count2 = 0;

            num_samples_after_downsampling += reverb->resampleEffectExtraSamples;

            entry->saveResampleNumSamples = num_samples_after_downsampling;
            entry->loadResamplePitch = ((u16)num_samples_after_downsampling << 15) / num_samples;
            entry->saveResamplePitch = (num_samples << 15) / (u16)num_samples_after_downsampling;

            while (TRUE) {
                temp_t2 = (entry->loadResamplePitch * num_samples * 2) + reverb->resampleEffectLoadUnk;
                temp_t4 = temp_t2 >> 16;

                if ((temp_t4 != num_samples_after_downsampling) && (count1 == 0)) {
                    entry->loadResamplePitch =
                        ((num_samples_after_downsampling << 16) - reverb->resampleEffectLoadUnk) / (num_samples * 2);
                    count1++;
                } else {
                    count1++;
                    if (temp_t4 > num_samples_after_downsampling) {
                        entry->loadResamplePitch--;
                    } else if (temp_t4 < num_samples_after_downsampling) {
                        entry->loadResamplePitch++;
                    } else {
                        break;
                    }
                }
            }

            reverb->resampleEffectLoadUnk = temp_t2 & 0xFFFF;

            while (TRUE) {
                temp_t2 = (entry->saveResamplePitch * num_samples_after_downsampling * 2) + reverb->resampleEffectSaveUnk;
                temp_t4 = temp_t2 >> 16;

                if ((temp_t4 != num_samples) && (count2 == 0)) {
                    entry->saveResamplePitch =
                        ((num_samples << 16) - reverb->resampleEffectSaveUnk) / (num_samples_after_downsampling * 2);
                    count2++;
                } else {
                    count2++;
                    if (temp_t4 > num_samples) {
                        entry->saveResamplePitch--;
                    } else if (temp_t4 < num_samples) {
                        entry->saveResamplePitch++;
                    } else {
                        break;
                    }
                }
            }

            reverb->resampleEffectSaveUnk = temp_t2 & 0xFFFF;
        }
    }

    extra_samples = (reverb->nextReverbBufPos + num_samples_after_downsampling) - reverb->delayNumSamples;
    reverb_buf_pos = reverb->nextReverbBufPos;

    // Add a reverb entry
    if (extra_samples < 0) {
        entry->size = num_samples_after_downsampling * sizeof(s16);
        entry->wrappedSize = 0;
        entry->startPos = reverb->nextReverbBufPos;
        reverb->nextReverbBufPos += num_samples_after_downsampling;
    } else {
        // End of the buffer is reached. Loop back around
        entry->size = (num_samples_after_downsampling - extra_samples) * sizeof(s16);
        entry->wrappedSize = extra_samples * sizeof(s16);
        entry->startPos = reverb->nextReverbBufPos;
        reverb->nextReverbBufPos = extra_samples;
    }

    entry->numSamplesAfterDownsampling = num_samples_after_downsampling;
    entry->numSamples = num_samples;

    // Add a sub-reverb entry
    if (reverb->subDelay != 0) {
        next_reverb_sub_buf_pos = reverb->subDelay + reverb_buf_pos;
        if (next_reverb_sub_buf_pos >= reverb->delayNumSamples) {
            next_reverb_sub_buf_pos -= reverb->delayNumSamples;
        }

        entry = &reverb->subBufEntry[reverb->curFrame][update_index];
        num_samples_after_downsampling = num_samples / reverb->downsampleRate;
        extra_samples = (next_reverb_sub_buf_pos + num_samples_after_downsampling) - reverb->delayNumSamples;

        if (extra_samples < 0) {
            entry->size = num_samples_after_downsampling * sizeof(s16);
            entry->wrappedSize = 0;
            entry->startPos = next_reverb_sub_buf_pos;
        } else {
            // End of the buffer is reached. Loop back around
            entry->size = (num_samples_after_downsampling - extra_samples) * sizeof(s16);
            entry->wrappedSize = extra_samples * sizeof(s16);
            entry->startPos = next_reverb_sub_buf_pos;
        }

        entry->numSamplesAfterDownsampling = num_samples_after_downsampling;
        entry->numSamples = num_samples;
    }
}
#endif

#ifdef VERSION_US
extern Acmd *func_8000DDC8(Acmd *cmd, u16 dmem, u16 start_pos, s32 size, SynthesisReverb *reverb);
extern Acmd *func_8000DE34(Acmd *cmd, u16 dmem, u16 start_pos, s32 size, SynthesisReverb *reverb);
// GB APU channel slots, initialized by func_8000C614 and serviced by func_8000C6D8.
typedef struct {
    /* 0x00 */ u8 *apu;
    /* 0x04 */ s32 active;
    /* 0x08 */ s32 mode;
    /* 0x0C */ u8 *unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ u8 *unk_14;
} GbApuChannelSlot; // size = 0x18
extern s32 D_8008FA40;
extern GbApuChannelSlot D_800D1220[7];
extern u8 D_8011EBF0[];
void func_8000C614(s32 arg0)
{
    s32 i;
    GbApuChannelSlot *entry;

    if (arg0 >= 8) {
        arg0 = 7;
    }
    D_8008FA40 = arg0;
    for (i = 0; i < 7; i++) {
        entry = &D_800D1220[i];
        entry->active = 0;
        entry->mode = 0;
        if (i < D_8008FA40) {
            entry->apu = (u8 *)GbApu_Alloc(D_8011EBF0, 0x25D8);
            entry->unk_0C = (u8 *)GbApu_Alloc(D_8011EBF0, 0x280);
            if (entry->apu != NULL) {
                entry->unk_14 = entry->apu + 0x198;
            }
        } else {
            entry->apu = NULL;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_8001FD50(u8 *);
extern s32 D_8008FA40;

void func_8000C6D8(void) {
    GbApuChannelSlot *slot;
    u8 *apu;
    s32 i;

    for (i = 0; i < D_8008FA40; i++) {
        slot = &D_800D1220[i];
        apu = slot->apu;
        if (apu == NULL) {
            continue;
        }
        if (slot->active != 0) {
            if ((u32)(*(s32 *)(apu + 0x25CC) - *(s32 *)(apu + 0x25C8)) <= 0x500 || slot->mode == 2) {
                func_8001FD50(apu);
            }
            if ((u32)(*(s32 *)(apu + 0x25CC) - *(s32 *)(apu + 0x25C8)) <= 0x500 || slot->mode == 2) {
                func_8001FD50(apu);
            }
            if ((u32)(*(s32 *)(apu + 0x25CC) - *(s32 *)(apu + 0x25C8)) <= 0x500 || slot->mode == 2) {
                func_8001FD50(apu);
            }
        }
    }
}
#endif

#ifdef VERSION_US
void func_8000C800(s32 arg0, s32 arg1, s32 arg2, OSMesgQueue *arg3)
{
    if (arg0 & 0x80000000) {
        _bcopy(arg0, arg1, arg2);
        osSendMesg(arg3, (OSMesg)1, 0);
    } else {
        func_8001544C(arg0, arg1, arg2, 2);
        osSendMesg(arg3, (OSMesg)1, 0);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000C85C.s")
#endif

#ifdef VERSION_US
extern u8 D_8011BE90[];
void func_8000CCF0(s32 arg0)
{
    s32 i;
    s32 offset;
    s32 target_offset;
    s32 product;
    u8 *entry;
    s32 new_var;
    u8 *target;

    i = 0;
    offset = 0;
    product = *(s32 *)(D_8011BE90 + 0x2C28) * arg0;
    target_offset = product << 5;
    while (i < *(s32 *)(D_8011BE90 + 0x2C28)) {
        entry = (u8 *)(offset + *(u32 *)(D_8011BE90 + 0x3468)) + (new_var = 0xD0);
        target = (u8 *)(target_offset + *(u32 *)(D_8011BE90 + 0x14)) + (new_var = 0);
        if ((*(u32 *)entry >> 31) != 0) {
            func_8001FC60(target, entry);
            entry[0] &= 0xFFBF;
        } else {
            target[0] &= 0xFF7F;
        }
        entry[6] = 0;
        i++;
        offset += 0x100;
        target_offset += 0x20;
    }
}
#endif

#ifdef VERSION_US
extern Acmd *func_8000E1E4(s16 *ai_buf, s32 num_samples_per_update, Acmd *cmd, s32 update_index);
// Same code as Majora's Mask AudioSynth_Update (src/audio/lib/synthesis.c).
Acmd *func_8000CDB8(Acmd *abi_cmd_start, s32 *num_abi_cmds, s16 *ai_buf_start, s32 num_samples_per_frame)
{
    s32 num_samples_per_update;
    s16 *cur_ai_buf_pos;
    Acmd *cur_cmd = abi_cmd_start;
    s32 reverse_update_index;
    s32 reverb_index;
    SynthesisReverb *reverb;

    for (reverse_update_index = *(s16 *)(D_8011BE90 + 0x2BE8); reverse_update_index > 0;
         reverse_update_index--) {
        Audio_UpdateSequencesAndNotes(reverse_update_index - 1);
        func_8000CCF0(*(s16 *)(D_8011BE90 + 0x2BE8) - reverse_update_index);
    }

    cur_ai_buf_pos = ai_buf_start;
    *(s32 *)(D_8011BE90 + 0x10) = 0;

    // Build the command list in several updates per frame
    for (reverse_update_index = *(s16 *)(D_8011BE90 + 0x2BE8); reverse_update_index > 0;
         reverse_update_index--) {
        if (reverse_update_index == 1) {
            // Final update takes the remaining samples
            num_samples_per_update = num_samples_per_frame;
        } else if ((num_samples_per_frame / reverse_update_index) >= *(s16 *)(D_8011BE90 + 0x2BEC)) {
            num_samples_per_update = *(s16 *)(D_8011BE90 + 0x2BEC);
        } else if ((num_samples_per_frame / reverse_update_index) <= *(s16 *)(D_8011BE90 + 0x2BEE)) {
            num_samples_per_update = *(s16 *)(D_8011BE90 + 0x2BEE);
        } else {
            num_samples_per_update = *(s16 *)(D_8011BE90 + 0x2BEA);
        }

        for (reverb_index = 0; reverb_index < *(s8 *)(D_8011BE90 + 1); reverb_index++) {
            if (((SynthesisReverb *)(D_8011BE90 + 0x18))[reverb_index].useReverb) {
                func_8000C280(num_samples_per_update, *(s16 *)(D_8011BE90 + 0x2BE8) - reverse_update_index,
                              reverb_index);
            }
        }

        cur_cmd = func_8000E1E4(cur_ai_buf_pos, num_samples_per_update, cur_cmd,
                                *(s16 *)(D_8011BE90 + 0x2BE8) - reverse_update_index);
        num_samples_per_frame -= num_samples_per_update;
        cur_ai_buf_pos += num_samples_per_update * sizeof(s16);
    }

    // Update reverb frame info
    for (reverb_index = 0; reverb_index < *(s8 *)(D_8011BE90 + 1); reverb_index++) {
        if (((SynthesisReverb *)(D_8011BE90 + 0x18))[reverb_index].framesToIgnore != 0) {
            ((SynthesisReverb *)(D_8011BE90 + 0x18))[reverb_index].framesToIgnore--;
        }
        ((SynthesisReverb *)(D_8011BE90 + 0x18))[reverb_index].curFrame ^= 1;
    }

    *num_abi_cmds = cur_cmd - abi_cmd_start;
    return cur_cmd;
}
#endif

#ifdef VERSION_US
void func_8000CFB4(s32 arg0, s32 arg1)
{
    struct LocalEntry {
        u32 unk0 : 1;
        u32 unk1 : 1;
        u32 unk2 : 30;
    };
    s32 i;
    u8 *ptr;

    i = arg0 + 1;
    while (i < *(s16 *)(D_8011BE90 + 0x2BE8)) {
        ptr = (u8 *)(*(u32 *)(D_8011BE90 + 0x14) + (((*(u32 *)(D_8011BE90 + 0x2C28) * i) + arg1) << 5));
        if (((struct LocalEntry *)ptr)->unk1) {
            break;
        }
        ptr[0] &= 0xFF7F;
        i++;
    }
}
#endif

#ifdef VERSION_US
s32 func_8000D024(s32 arg0, u8 *arg1, s16 arg2)
{
    u8 *entry;

    entry = ((arg1 + (arg1[3] * 0x8C)) + (arg2 * 0x1C)) + ((0, 0x40));
    arg0 = func_8000DDC8(arg0, 0x3D0, *(u16 *)(entry + 0xE), *(s16 *)(entry + 0x10), arg1);
    if (*(s16 *)(entry + 0x12) != 0) {
        arg0 = func_8000DDC8(arg0, (*(s16 *)(entry + 0x10) + 0x3D0) & 0xFFFF, 0, *(s16 *)(entry + 0x12), arg1);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
s32 func_8000D0CC(s32 arg0, u8 *arg1, s16 arg2)
{
    u8 *entry;

    entry = ((arg1 + (arg1[3] * 0x8C)) + (arg2 * 0x1C)) + ((0, 0x40));
    arg0 = func_8000DE34(arg0, 0x3D0, *(u16 *)(entry + 0xE), *(s16 *)(entry + 0x10), arg1);
    if (*(s16 *)(entry + 0x12) != 0) {
        arg0 = func_8000DE34(arg0, (*(s16 *)(entry + 0x10) + 0x3D0) & 0xFFFF, 0, *(s16 *)(entry + 0x12), arg1);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_LeakReverb (src/audio/lib/synthesis.c).
Acmd *func_8000D174(Acmd *cmd, SynthesisReverb *reverb)
{
    aDMEMMove_GS(cmd++, 0xC70, 0x710, 416);
    aMix_GS(cmd++, 416 >> 4, reverb->leakRtl, 0xE10, 0xC70);
    aMix_GS(cmd++, 416 >> 4, reverb->leakLtr, 0x710, 0xE10);
    return cmd;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_LoadDownsampledReverbSamples (src/audio/lib/synthesis.c).
Acmd *func_8000D1D8(Acmd *cmd, s32 num_samples_per_update, SynthesisReverb *reverb, s16 update_index)
{
    ReverbBufferEntry *entry = &reverb->bufEntry[reverb->curFrame][update_index];
    s16 offset_size = (entry->startPos & 7) * sizeof(s16);
    s16 wrapped_offset_size = (offset_size + entry->size + 0xF) & ~0xF;

    cmd = func_8000DDC8(cmd, 0x3D0, entry->startPos - (offset_size / (s32)sizeof(s16)), 416, reverb);

    if (entry->wrappedSize != 0) {
        cmd = func_8000DDC8(cmd, 0x3D0 + wrapped_offset_size, 0, 416 - wrapped_offset_size, reverb);
    }

    aSetBuffer_GS(cmd++, 0, 0x3D0 + offset_size, 0xC70, num_samples_per_update * sizeof(s16));
    aResample_GS(cmd++, reverb->resampleFlags, reverb->downsamplePitch, reverb->leftLoadResampleBuf);
    aSetBuffer_GS(cmd++, 0, 0x3D0 + 416 + offset_size, 0xE10, num_samples_per_update * sizeof(s16));
    aResample_GS(cmd++, reverb->resampleFlags, reverb->downsamplePitch, reverb->rightLoadResampleBuf);

    return cmd;
}
#endif

#ifdef VERSION_US
extern Acmd *func_8000DC7C(Acmd *cmd, u16 dmem, u16 size, u32 start_addr);
// Same code as Majora's Mask AudioSynth_SaveResampledReverbSamples (src/audio/lib/synthesis.c).
Acmd *func_8000D374(Acmd *cmd, SynthesisReverb *reverb, s16 update_index)
{
    ReverbBufferEntry *entry = &reverb->bufEntry[reverb->curFrame][update_index];
    s16 num_samples = entry->numSamples;
    u32 size = num_samples * sizeof(s16);

    // Left channel
    aDMEMMove_GS(cmd++, 0xC70, 0x3D0, size);
    aSetBuffer_GS(cmd++, 0, 0x3D0, 0x710, entry->saveResampleNumSamples * sizeof(s16));
    aResample_GS(cmd++, reverb->resampleFlags, entry->saveResamplePitch, reverb->leftSaveResampleBuf);

    cmd = func_8000DC7C(cmd, 0x710, entry->size, (u32)&reverb->leftReverbBuf[entry->startPos]);

    if (entry->wrappedSize != 0) {
        cmd = func_8000DC7C(cmd, entry->size + 0x710, entry->wrappedSize, (u32)reverb->leftReverbBuf);
    }

    // Right channel
    aDMEMMove_GS(cmd++, 0xE10, 0x3D0, size);
    aSetBuffer_GS(cmd++, 0, 0x3D0, 0x710, entry->saveResampleNumSamples * sizeof(s16));
    aResample_GS(cmd++, reverb->resampleFlags, entry->saveResamplePitch, reverb->rightSaveResampleBuf);

    cmd = func_8000DC7C(cmd, 0x710, entry->size, (u32)&reverb->rightReverbBuf[entry->startPos]);

    if (entry->wrappedSize != 0) {
        cmd = func_8000DC7C(cmd, entry->size + 0x710, entry->wrappedSize, (u32)reverb->rightReverbBuf);
    }

    return cmd;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_LoadResampledReverbSamples (src/audio/lib/synthesis.c).
Acmd *func_8000D56C(Acmd *cmd, s32 num_samples_per_update, SynthesisReverb *reverb, s16 update_index)
{
    ReverbBufferEntry *entry = &reverb->bufEntry[reverb->curFrame][update_index];
    s16 offset_size = (entry->startPos & 7) * sizeof(s16);
    s16 wrapped_offset_size = (offset_size + entry->size + 0xF) & ~0xF;

    cmd = func_8000DDC8(cmd, 0x3D0, entry->startPos - (offset_size / (s32)sizeof(s16)), 416, reverb);

    if (entry->wrappedSize != 0) {
        cmd = func_8000DDC8(cmd, wrapped_offset_size + 0x3D0, 0, 416 - wrapped_offset_size, reverb);
    }

    aSetBuffer_GS(cmd++, 0, 0x3D0 + offset_size, 0xC70, num_samples_per_update * sizeof(s16));
    aResample_GS(cmd++, reverb->resampleFlags, entry->loadResamplePitch, reverb->leftLoadResampleBuf);
    aSetBuffer_GS(cmd++, 0, 0x3D0 + 416 + offset_size, 0xE10, num_samples_per_update * sizeof(s16));
    aResample_GS(cmd++, reverb->resampleFlags, entry->loadResamplePitch, reverb->rightLoadResampleBuf);

    return cmd;
}
#endif

#ifdef VERSION_US
// Appends the two custom-ucode commands for each of arg2's two slots
// (slot data pointers at 0x270/0x274, second pointers at 0x280/0x284, and a
// byte at 0 shared by both slots that lands in word 0 bits 16-23 of the
// second command). Each command is one 8-byte Gfx entry: word 0 = opcode
// 0x07 plus a 16-bit likely-TMEM address, word 1 = the data pointer. The
// first command per slot is the 0x07020000 shape func_8000DB0C emits, with
// arg1's low 16 bits as the address; the second is the 0x07000000 shape
// func_8000DAE8 emits, with the fixed addresses 0xC70/0xE10 (0x1A0 apart,
// the slot-pair stride func_8000DDC8 also emits). The ucode at ROM 0xA8600
// identifies as "RSP Gfx ucode F3DEX       fifo 2.08" (F3DEX2 2.08 with the
// name string patched), so opcode 0x07 is not stock G_QUAD; what the RSP
// does with these commands is unverified.
Gfx *func_8000D710(Gfx *arg0, s32 arg1, u8 *arg2)
{
    Gfx *cmd_gfx;
    Gfx *cmd_gfx2;

    if (*(s32 *)(arg2 + 0x270) != 0) {
        cmd_gfx = arg0++;
        cmd_gfx->words.w0 = (arg1 & 0xFFFF) | 0x07020000;
        cmd_gfx->words.w1 = *(s32 *)(arg2 + 0x270);
        cmd_gfx2 = arg0++;
        // FAKE: the shift pair folds to << 0x10; the folded first shift
        // claims one IDO temp-walk slot, which the t-register rotation of
        // both slot blocks depends on.
        cmd_gfx2->words.w0 = ((*(u8 *)arg2 << 8) << 8) | 0x07000000 | 0xC70;
        cmd_gfx2->words.w1 = *(s32 *)(arg2 + 0x280);
    }
    if (*(s32 *)(arg2 + 0x274) != 0) {
        cmd_gfx = arg0++;
        cmd_gfx->words.w0 = (arg1 & 0xFFFF) | 0x07020000;
        cmd_gfx->words.w1 = *(s32 *)(arg2 + 0x274);
        cmd_gfx2 = arg0++;
        // FAKE: same << 0x10 fold, spelled differently from the first slot's
        // chain so uopt does not CSE the two folds into one walk-slot claim.
        cmd_gfx2->words.w0 = ((*(u8 *)arg2 << 4) << 12) | 0x07000000 | 0xE10;
        cmd_gfx2->words.w1 = *(s32 *)(arg2 + 0x284);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_MixOtherReverbIndex (src/audio/lib/synthesis.c).
// D_8011BE90 + 1 is the reverb count and D_8011BE90 + 0x18 the SynthesisReverb array;
// unk_005 is the index of the reverb to mix in and unk_008 its mix gain.
Acmd *func_8000D7B8(Acmd *cmd, SynthesisReverb *reverb, s32 update_index)
{
    SynthesisReverb *mix_reverb;

    if (reverb->unk_005 >= (s8)D_8011BE90[1]) {
        return cmd;
    }

    mix_reverb = &((SynthesisReverb *)(D_8011BE90 + 0x18))[reverb->unk_005];
    if (mix_reverb->downsampleRate == 1) {
        cmd = (Acmd *)func_8000D024((s32)cmd, (u8 *)mix_reverb, update_index);
        aMix_GS(cmd++, 832 >> 4, reverb->unk_008, 0xC70, 0x3D0);
        cmd = (Acmd *)func_8000D0CC((s32)cmd, (u8 *)mix_reverb, update_index);
    }

    return cmd;
}
void func_8000D7B8_padding(void) {}
#endif

#ifdef VERSION_US
void func_8000D880(u8 *arg0, s32 arg1, s32 arg2) { *(u32 *)(arg0 + 0) = ((u32)arg1 & 0x00FFFFFF) | 0x02000000; *(u32 *)(arg0 + 4) = arg2; }
#endif

#ifdef VERSION_US
void func_8000D8A0(void) {}
void func_8000D8A0_padding(void) {}
void func_8000D8A0_padding2(void) {}
void func_8000D8A0_padding3(void) {}
void func_8000D8A0_padding4(void) {}
void func_8000D8A0_padding5(void) {}
void func_8000D8A0_padding6(void) {}
#endif

#ifdef VERSION_US
void func_8000D8D8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  *((s32 *) (((u8 *) arg0) + 0)) = (s32) ((((arg1 & 0xFF) << 0x10) | 0x08000000) | (arg2 & 0xFFFF));
  *((s32 *) (((u8 *) arg0) + 4)) = (s32) ((arg3 << 0x10) | (arg4 & 0xFFFF));
  *((s32 *) (((u8 *) arg0) + 4)) = (s32) (((arg3 << 3) << 13) | (arg4 & 0xFFFF));
}
#endif

#ifdef VERSION_US
void func_8000D90C(void) {}
void func_8000D90C_padding(void) {}
#endif

#ifdef VERSION_US
void func_8000D91C(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  *((s32 *) (((u8 *) arg0) + 0)) = (s32) ((arg1 & 0xFFFFFF) | 0x0A000000);
  *((s32 *) (((u8 *) arg0) + 4)) = (s32) (((arg2 << 4) << 12) | (arg3 & 0xFFFF));
}
#endif

#ifdef VERSION_US
void func_8000D948(void) {}
void func_8000D948_padding(void) {}
void func_8000D948_padding2(void) {}
void func_8000D948_padding3(void) {}
#endif

#ifdef VERSION_US
void func_8000D968(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  *((s32 *) (((u8 *) arg0) + 0)) = (arg3 & 0xFFFF) | 0x11000000;
  *((s32 *) (((u8 *) arg0) + 4)) = (s32) (((arg1 << 8) << 8) | (arg2 & 0xFFFF));
}
#endif

#ifdef VERSION_US
void func_8000D98C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  *((s32 *) (((u8 *) arg0) + 0)) = (s32) ((((arg1 & 0xFF) << 0x10) | 0x12000000) | (arg2 & 0xFFFF));
  *((s32 *) (((u8 *) arg0) + 4)) = (s32) (((arg3 << 4) << 12) | (arg4 & 0xFFFF));
}
#endif

void func_8000D9C0(void) {
}

#ifdef VERSION_US
void func_8000D9C8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((u8 *)(arg0) + (0))) = (s32) ((((arg2 >> 4) & 0xFF) << 0x10) | 0x14000000 | (arg1 & 0xFFFF));
    (*(s32 *)((u8 *)(arg0) + (4))) = arg3;
}
#endif

void func_8000D9F0(void) {
}

#ifdef VERSION_US
void func_8000D9F8(void *arg0, s32 arg1, s32 arg2)
{
  u8 *new_var;
  new_var = (u8 *) arg0;
  *((s32 *) (new_var + 0)) = 0x16000000;
 do { *((s32 *) (((u8 *) arg0) + 4)) = (s32) (((arg1 << 7) << 9) | (arg2 & 0xFFFF)); } while (0);
}
#endif

#ifdef VERSION_US
void func_8000DA14(void) {}
void func_8000DA14_padding(void) {}
void func_8000DA14_padding2(void) {}
#endif

#ifdef VERSION_US
void func_8000DA2C(u8 *arg0, s32 arg1, s32 arg2) { *(u32 *)(arg0 + 0) = 0x17000000 | (((u32)arg1 & 0xFF) << 16); *(u32 *)(arg0 + 4) = arg2; }
#endif

#ifdef VERSION_US
void func_8000DA48(u32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0[0] = ((arg1 & 0xFF) << 16) | 0x0E000000 | (arg4 & 0xFFFF);
    arg0[1] = ((arg2 & 0xFFFF) << 16) | (arg3 & 0xFFFF);
}
#endif

#ifdef VERSION_US
void func_8000DA7C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  u8 *p = arg0;
  *((u32 *) (p + 0x00)) = ((arg4 & 0xFF) << 16) | (arg3 & 0xFFFF);
  *((u32 *) (p + 0x04)) = ((arg1 << 14) << 2) | (arg2 & 0xFFFF);
}
#endif

#ifdef VERSION_US
void ParticleGfx_NoopStub2(void) {}
void func_8000DAA8_padding(void) {}
void func_8000DAA8_padding2(void) {}
void func_8000DAA8_padding3(void) {}
void func_8000DAA8_padding4(void) {}
void func_8000DAA8_padding5(void) {}
void func_8000DAA8_padding6(void) {}
void func_8000DAA8_padding7(void) {}
#endif

#ifdef VERSION_US
void func_8000DAE8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) { *(u32 *)(arg0 + 0) = 0x07000000 | (((u32)arg1 & 0xFF) << 16) | ((u32)arg2 & 0xFFFF); *(u32 *)(arg0 + 4) = arg3; }
#endif

#ifdef VERSION_US
void func_8000DB0C(u8 *arg0, s32 arg1, s32 arg2) { *(u32 *)(arg0 + 0) = 0x07020000 | ((u32)arg1 & 0xFFFF); *(u32 *)(arg0 + 4) = arg2; }
#endif

#ifdef VERSION_US
s32 func_8000DB24(s32 arg0, s32 arg1, u8 *arg2, s16 arg3)
{
    u8 *entry;

    entry = ((arg2 + (arg2[3] * 0x8C)) + (arg3 * 0x1C)) + ((0, 0x40));
    arg0 = func_8000DDC8(arg0, 0xC70, *(u16 *)(entry + 0xE), *(s16 *)(entry + 0x10), arg2);
    if (*(s16 *)(entry + 0x12) != 0) {
        arg0 = func_8000DDC8(arg0, (*(s16 *)(entry + 0x10) + 0xC70) & 0xFFFF, 0, *(s16 *)(entry + 0x12), arg2);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
s32 func_8000DBD0(s32 arg0, s32 arg1, u8 *arg2, s16 arg3)
{
    u8 *entry;

    entry = ((arg2 + (arg2[3] * 0x8C)) + (arg3 * 0x1C)) + ((0, 0x158));
    arg0 = func_8000DDC8(arg0, 0xC70, *(u16 *)(entry + 0xE), *(s16 *)(entry + 0x10), arg2);
    if (*(s16 *)(entry + 0x12) != 0) {
        arg0 = func_8000DDC8(arg0, (*(s16 *)(entry + 0x10) + 0xC70) & 0xFFFF, 0, *(s16 *)(entry + 0x12), arg2);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_SaveResampledReverbSamplesImpl (src/audio/lib/synthesis.c).
Acmd *func_8000DC7C(Acmd *cmd, u16 dmem, u16 size, u32 start_addr)
{
    s32 start_addr_align_dropped;
    u32 end_addr;
    s32 end_addr_align_dropped;

    end_addr = start_addr + size;

    end_addr_align_dropped = end_addr & 0xF;
    if (end_addr_align_dropped != 0) {
        aLoadBuffer_GS(cmd++, end_addr - end_addr_align_dropped, 0x3B0, 16);
        aDMEMMove_GS(cmd++, dmem, 0x3C0, size);
        aDMEMMove_GS(cmd++, 0x3B0 + end_addr_align_dropped, size + 0x3C0, 16 - end_addr_align_dropped);

        size += 16 - end_addr_align_dropped;
        dmem = 0x3C0;
    }

    start_addr_align_dropped = start_addr & 0xF;
    if (start_addr_align_dropped != 0) {
        aLoadBuffer_GS(cmd++, start_addr - start_addr_align_dropped, 0x3B0, 16);
        aDMEMMove_GS(cmd++, dmem, start_addr_align_dropped + 0x3B0, size);

        size += start_addr_align_dropped;
        dmem = 0x3B0;
    }

    aSaveBuffer_GS(cmd++, dmem, start_addr - start_addr_align_dropped, size);

    return cmd;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_LoadReverbSamplesImpl (src/audio/lib/synthesis.c).
Acmd *func_8000DDC8(Acmd *cmd, u16 dmem, u16 start_pos, s32 size, SynthesisReverb *reverb)
{
    aLoadBuffer_GS(cmd++, &reverb->leftReverbBuf[start_pos], dmem, size);
    aLoadBuffer_GS(cmd++, &reverb->rightReverbBuf[start_pos], dmem + 416, size);
    return cmd;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_SaveReverbSamplesImpl (src/audio/lib/synthesis.c).
Acmd *func_8000DE34(Acmd *cmd, u16 dmem, u16 start_pos, s32 size, SynthesisReverb *reverb)
{
    aSaveBuffer_GS(cmd++, dmem, &reverb->leftReverbBuf[start_pos], size);
    aSaveBuffer_GS(cmd++, dmem + 416, &reverb->rightReverbBuf[start_pos], size);
    return cmd;
}
#endif

void func_8000DEA0(void) {
}

#ifdef VERSION_US
s32 func_8000DEA8(s32 arg0, s32 arg1, u8 *arg2, s16 arg3)
{
    if (arg2[4] == 1) {
        arg0 = func_8000DBD0(arg0, arg1, arg2, arg3);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
s32 func_8000DEE8(s32 arg0, s32 arg1, u8 *arg2, s16 arg3)
{
    if (arg2[4] == 1) {
        if (arg2[0x18] != 0) {
            arg0 = func_8000D56C(arg0, arg1, arg2, arg3);
        } else {
            arg0 = func_8000DB24(arg0, arg1, arg2, arg3);
        }
    } else {
        arg0 = func_8000D1D8(arg0, arg1, arg2, arg3);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_SaveReverbSamples (src/audio/lib/synthesis.c).
Acmd *func_8000DF5C(Acmd *cmd, SynthesisReverb *reverb, s16 update_index)
{
    ReverbBufferEntry *entry = &reverb->bufEntry[reverb->curFrame][update_index];
    s32 downsample_rate;
    s32 num_samples;

    if (reverb->downsampleRate == 1) {
        if (reverb->resampleEffectOn) {
            cmd = func_8000D374(cmd, reverb, update_index);
        } else {
            // Save the wet channels to the ring buffer
            cmd = func_8000DE34(cmd, 0xC70, entry->startPos, entry->size, reverb);
            if (entry->wrappedSize != 0) {
                // Ring buffer wrapped
                cmd = func_8000DE34(cmd, 0xC70 + entry->size, 0, entry->wrappedSize, reverb);
            }
        }
    } else {
        // karodo: also present in the Majora's Mask twin; removing it gives diff score 834.
        if (1) {}

        downsample_rate = reverb->downsampleRate;
        num_samples = 13 * 16;

        while (downsample_rate >= 2) {
            aInterl_GS(cmd++, 0xC70, 0xC70, num_samples);
            aInterl_GS(cmd++, 0xE10, 0xE10, num_samples);
            downsample_rate >>= 1;
            num_samples >>= 1;
        }

        if (entry->size != 0) {
            cmd = func_8000DC7C(cmd, 0xC70, entry->size, (u32)&reverb->leftReverbBuf[entry->startPos]);
            cmd = func_8000DC7C(cmd, 0xE10, entry->size, (u32)&reverb->rightReverbBuf[entry->startPos]);
        }

        if (entry->wrappedSize != 0) {
            cmd = func_8000DC7C(cmd, entry->size + 0xC70, entry->wrappedSize, (u32)reverb->leftReverbBuf);
            cmd = func_8000DC7C(cmd, entry->size + 0xE10, entry->wrappedSize, (u32)reverb->rightReverbBuf);
        }
    }

    reverb->resampleFlags = 0;

    return cmd;
}
#endif

#ifdef VERSION_US
s32 func_8000E13C(s32 arg0, u8 *arg1, s16 arg2)
{
    u8 *entry;

    entry = ((arg1 + (arg1[3] * 0x8C)) + (arg2 * 0x1C)) + ((0, 0x158));
    arg0 = func_8000DE34(arg0, 0xC70, *(u16 *)(entry + 0xE), *(s16 *)(entry + 0x10), arg1);
    if (*(s16 *)(entry + 0x12) != 0) {
        arg0 = func_8000DE34(arg0, (*(s16 *)(entry + 0x10) + 0xC70) & 0xFFFF, 0, *(s16 *)(entry + 0x12), arg1);
    }
    return arg0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000E1E4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000E750.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/CE80/func_8000F4E0.s")
#endif

#ifdef VERSION_US
// Same code as Majora's Mask AudioSynth_FinalResample (src/audio/lib/synthesis.c).
Acmd *func_8000F794(Acmd *cmd, u8 *synth_state, s32 size, u16 pitch, u16 inp_dmem, s32 resample_flags)
{
    if (pitch == 0) {
        func_8000D880((u8 *)cmd++, 0x3B0, size);
    } else {
        aSetBuffer_GS(cmd++, 0, inp_dmem, 0x3B0, size);
        aResample_GS(cmd++, resample_flags, pitch, *(u8 **)(synth_state + 0x10) + 0x20);
    }
    return cmd;
}
#endif

#ifdef VERSION_US
// Per-voice mixer input, laid out like Majora's Mask NoteSampleState
// (include/audio/playback.h); only the fields func_8000F834 reads are named.
typedef struct {
    /* 0x00 */ struct {
        u8 unk_0 : 4;
        u8 strongRight : 1;
        u8 strongLeft : 1;
        u8 strongReverbRight : 1;
        u8 strongReverbLeft : 1;
    } bitField0;
    /* 0x01 */ struct {
        u8 unk_0 : 7;
        u8 useHaasEffect : 1;
    } bitField1;
    /* 0x02 */ u8 unk_02[3];
    /* 0x05 */ u8 targetReverbVol;
    /* 0x06 */ u8 unk_06[2];
    /* 0x08 */ u16 targetVolLeft;
    /* 0x0A */ u16 targetVolRight;
    /* 0x0C */ u8 unk_0C[4];
    /* 0x10 */ void *unk_10;
    /* 0x14 */ void *unk_14;
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 surroundEffectIndex;
    /* 0x1A */ u8 unk_1A[6];
} NoteSampleState; // size = 0x20

// Per-voice mixer state, laid out like the start of Majora's Mask
// NoteSynthesisState (include/audio/synthesis.h).
typedef struct {
    /* 0x00 */ u8 unk_00[4];
    /* 0x04 */ u8 curReverbVol;
    /* 0x05 */ u8 unk_05[0x10 - 0x05];
    /* 0x10 */ void *unk_10;
    /* 0x14 */ s16 curVolLeft;
    /* 0x16 */ s16 curVolRight;
} NoteSynthesisState;

extern s8 D_8011EABE;
extern f32 D_8008F708[];
extern u32 D_8008FA4C;
extern u32 D_8008FA50;
extern u32 D_8008FA54;
extern u32 D_8008FA58;
// Same code as Majora's Mask AudioSynth_ProcessEnvelope (src/audio/lib/synthesis.c).
// D_8011EABE is the sound mode (4 selects the per-voice pan table D_8008F708);
// D_8008FA50/D_8008FA54/D_8008FA58 are the left-delay, right-delay, and default
// envelope-mixer DMEM destination words, and D_8008FA4C is the envelope-mixer
// opcode word.
Acmd *func_8000F834(Acmd *cmd, NoteSampleState *sample_state, NoteSynthesisState *synth_state,
                    s32 num_samples_per_update, u16 dmem_src, s32 haas_effect_delay_side, s32 flags)
{
    u32 dmem_dests;
    u16 cur_vol_left;
    u16 target_vol_left;
    s32 cur_reverb_vol;
    u16 cur_vol_right;
    s16 target_reverb_vol;
    s16 ramp_left;
    s16 ramp_right;
    s16 ramp_reverb;
    s16 cur_reverb_vol_and_flags;
    u16 target_vol_right;
    f32 default_pan_volume;
    s32 pad; // FAKE: unused stack slot, also in the Majora's Mask twin; removing it gives diff score 194.

    target_reverb_vol = sample_state->targetReverbVol;

    cur_vol_left = synth_state->curVolLeft;
    cur_vol_right = synth_state->curVolRight;

    target_vol_left = sample_state->targetVolLeft;
    target_vol_left <<= 4;
    target_vol_right = sample_state->targetVolRight;
    target_vol_right <<= 4;

    if ((D_8011EABE == 4) && (sample_state->surroundEffectIndex != 0xFF)) {
        default_pan_volume = D_8008F708[sample_state->surroundEffectIndex];
        target_vol_left *= default_pan_volume;
        target_vol_right *= default_pan_volume;
    }

    if (target_vol_left != cur_vol_left) {
        ramp_left = (target_vol_left - cur_vol_left) / (num_samples_per_update >> 3);
    } else {
        ramp_left = 0;
    }

    if (target_vol_right != cur_vol_right) {
        ramp_right = (target_vol_right - cur_vol_right) / (num_samples_per_update >> 3);
    } else {
        ramp_right = 0;
    }

    cur_reverb_vol_and_flags = synth_state->curReverbVol;
    cur_reverb_vol = cur_reverb_vol_and_flags & 0x7F;

    if (cur_reverb_vol_and_flags != target_reverb_vol) {
        ramp_reverb = (((target_reverb_vol & 0x7F) - cur_reverb_vol) << 9) / (num_samples_per_update >> 3);
        synth_state->curReverbVol = target_reverb_vol;
    } else {
        ramp_reverb = 0;
    }

    synth_state->curVolLeft = cur_vol_left + (ramp_left * (num_samples_per_update >> 3));
    synth_state->curVolRight = cur_vol_right + (ramp_right * (num_samples_per_update >> 3));

    if (sample_state->bitField1.useHaasEffect) {
        func_8000D880((u8 *)cmd++, 0x5B0, 416);
        func_8000D98C(cmd++, cur_reverb_vol * 2, ramp_reverb, ramp_left, ramp_right);
        func_8000D9F8(cmd++, cur_vol_left, cur_vol_right);

        switch (haas_effect_delay_side) {
            case 1:
                // Store the left dry channel in a temp space to be delayed
                dmem_dests = D_8008FA50;
                break;

            case 2:
                // Store the right dry channel in a temp space to be delayed
                dmem_dests = D_8008FA54;
                break;

            default:
                dmem_dests = D_8008FA58;
                break;
        }
    } else {
        aEnvSetup1_GS(cmd++, cur_reverb_vol * 2, ramp_reverb, ramp_left, ramp_right);
        aEnvSetup2_GS(cmd++, cur_vol_left, cur_vol_right);
        dmem_dests = D_8008FA58;
    }

    aEnvMixer_GS(cmd++, dmem_src, num_samples_per_update, (cur_reverb_vol_and_flags & 0x80) >> 7,
                 sample_state->bitField0.strongReverbRight, sample_state->bitField0.strongReverbLeft,
                 sample_state->bitField0.strongRight, sample_state->bitField0.strongLeft, dmem_dests, D_8008FA4C);

    return cmd;
}
#endif

#ifdef VERSION_US
// A_CLEARBUFF 0x02, A_ADDMIXER 0x04 and A_RESAMPLE_ZOH 0x06 encoders, following
// Majora's Mask include/PR/abi.h aClearBuffer, aAddMixer and aResampleZoh.
#define aClearBuffer_GS(pkt, d, c) AUDIO_CMD(pkt, _SHIFTL(0x02, 24, 8) | _SHIFTL(d, 0, 24), (unsigned int)(c))
#define aAddMixer_GS(pkt, count, dmemi, dmemo, a4)                                         \
    AUDIO_CMD(pkt, _SHIFTL(0x04, 24, 8) | _SHIFTL((count) >> 4, 16, 8) | _SHIFTL(a4, 0, 16), \
              _SHIFTL(dmemi, 16, 16) | _SHIFTL(dmemo, 0, 16))
#define aResampleZoh_GS(pkt, pitch, pitch_accu) \
    AUDIO_CMD(pkt, _SHIFTL(0x06, 24, 8) | _SHIFTL(pitch, 0, 16), _SHIFTL(pitch_accu, 0, 16))
#define ALIGN16(val) (((val) + 0xF) & ~0xF)
#define ALIGN64(val) (((val) + 0x3F) & ~0x3F)

// Close to Majora's Mask AudioSynth_ApplyHaasEffect (src/audio/lib/synthesis.c);
// GS clears the delay area with A_CLEARBUFF on the A_INIT path even when the
// delay size is 0. Delay sizes: sample state bytes 3 (left) and 4 (right);
// previous sizes: synthesis state bytes 2 (left) and 3 (right). The delay
// state buffer is at synthesis buffers + 0xA0. DMEM: 0x930 left channel,
// 0xAD0 right channel, 0x5B0 Haas temp, 0x3B0 temp.
Acmd *func_8000FCF0(Acmd *cmd, NoteSampleState *sample_state, NoteSynthesisState *synth_state, s32 size, s32 flags,
                    s32 haas_effect_delay_side)
{
    u16 dmem_dest;
    u16 pitch;
    u8 prev_haas_effect_delay_size;
    u8 haas_effect_delay_size;

    switch (haas_effect_delay_side) {
        case 1:
            // Delay the sample on the left channel
            dmem_dest = 0x930;
            haas_effect_delay_size = sample_state->unk_02[1];
            prev_haas_effect_delay_size = synth_state->unk_00[2];
            synth_state->unk_00[3] = 0;
            synth_state->unk_00[2] = haas_effect_delay_size;
            break;

        case 2:
            // Delay the sample on the right channel
            dmem_dest = 0xAD0;
            haas_effect_delay_size = sample_state->unk_02[2];
            prev_haas_effect_delay_size = synth_state->unk_00[3];
            synth_state->unk_00[3] = haas_effect_delay_size;
            synth_state->unk_00[2] = 0;
            break;

        default:
            return cmd;
    }

    if (flags != 1) {
        // Slightly adjust the sample rate in order to fit a change in sample delay
        if (haas_effect_delay_size != prev_haas_effect_delay_size) {
            pitch = (((size << 15) / 2) - 1) / ((size + haas_effect_delay_size - prev_haas_effect_delay_size - 2) / 2);
            aSetBuffer_GS(cmd++, 0, 0x5B0, 0x3B0, size + haas_effect_delay_size - prev_haas_effect_delay_size);
            aResampleZoh_GS(cmd++, pitch, 0);
        } else {
            aDMEMMove_GS(cmd++, 0x5B0, 0x3B0, size);
        }

        if (prev_haas_effect_delay_size != 0) {
            aLoadBuffer_GS(cmd++, (u8 *)synth_state->unk_10 + 0xA0, 0x5B0, ALIGN16(prev_haas_effect_delay_size));
            aDMEMMove_GS(cmd++, 0x3B0, 0x5B0 + prev_haas_effect_delay_size,
                         size + haas_effect_delay_size - prev_haas_effect_delay_size);
        } else {
            aDMEMMove_GS(cmd++, 0x3B0, 0x5B0, size + haas_effect_delay_size);
        }
    } else {
        // Just apply a delay directly
        aDMEMMove_GS(cmd++, 0x5B0, 0x3B0, size);
        aClearBuffer_GS(cmd++, 0x5B0, haas_effect_delay_size);
        aDMEMMove_GS(cmd++, 0x3B0, 0x5B0 + haas_effect_delay_size, size);
    }

    if (haas_effect_delay_size) {
        // Save excess samples for the next update
        aSaveBuffer_GS(cmd++, 0x5B0 + size, (u8 *)synth_state->unk_10 + 0xA0, ALIGN16(haas_effect_delay_size));
    }

    aAddMixer_GS(cmd++, ALIGN64(size), 0x5B0, dmem_dest, 0x7FFF);

    return cmd;
}
#endif
