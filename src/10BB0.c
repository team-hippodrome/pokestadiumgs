#include "global.h"


#ifdef VERSION_US
extern u8 D_8011BE90[];

// Bit 4 of a note's ADSR action byte (playback state + 0x30) requests release.
typedef struct {
    u8 unk_0 : 3;
    u8 release : 1;
} AdsrActionBits;

// Pointer to the 0x100-byte note array, stored at D_8011BE90 + 0x3468.
typedef struct {
    u8 *notes;
} AudioNoteArrayField;

// 0x14-byte sound font entries; the array pointer is at D_8011BE90 + 0x2BD8.
typedef struct {
    u8 numInstruments;
    u8 numDrums;
    u8 sampleBankId1;
    u8 sampleBankId2;
    u16 numSfx;
    u8 unk_6[0x14 - 6];
} AudioFontInfo;

// First byte of a sequence layer: bit 7 = enabled, bit 6 = finished.
typedef struct {
    u8 enabled : 1;
    u8 finished : 1;
} SeqLayerFlags;

extern f32 D_8011EA8C; f32 func_8000FFB0(f32 arg0) { return 256.0f * D_8011EA8C / arg0; }

// Same code as Majora's Mask AudioHeap_InitAdsrDecayTable (src/audio/lib/heap.c).
// Fills the 256-entry f32 ADSR decay table whose pointer is at D_8011BE90 + 0x345C.
void func_8000FFCC(void) {
    s32 i;

    (*(f32 **)(D_8011BE90 + 0x345C))[255] = func_8000FFB0(0.25f);
    (*(f32 **)(D_8011BE90 + 0x345C))[254] = func_8000FFB0(0.33f);
    (*(f32 **)(D_8011BE90 + 0x345C))[253] = func_8000FFB0(0.5f);
    (*(f32 **)(D_8011BE90 + 0x345C))[252] = func_8000FFB0(0.66f);
    (*(f32 **)(D_8011BE90 + 0x345C))[251] = func_8000FFB0(0.75f);

    for (i = 128; i < 251; i++) {
        (*(f32 **)(D_8011BE90 + 0x345C))[i] = func_8000FFB0(251 - i);
    }

    for (i = 16; i < 128; i++) {
        (*(f32 **)(D_8011BE90 + 0x345C))[i] = func_8000FFB0(4 * (143 - i));
    }

    for (i = 1; i < 16; i++) {
        (*(f32 **)(D_8011BE90 + 0x345C))[i] = func_8000FFB0(60 * (23 - i));
    }

    (*(f32 **)(D_8011BE90 + 0x345C))[0] = 0.0f;
}

// Same code as Star Fox 64 AudioHeap_ResetLoadStatus (src/audio/audio_heap.c).
// Load-status arrays: fonts at +0x3364 (100), sample banks at +0x3300 (100),
// sequences at +0x33C8 (140); status 5 is permanent and is kept.
void func_80010110(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        if (D_8011BE90[i + 0x3364] != 5) {
            D_8011BE90[i + 0x3364] = 0;
        }
    }

    for (i = 0; i < 100; i++) {
        if (D_8011BE90[i + 0x3300] != 5) {
            D_8011BE90[i + 0x3300] = 0;
        }
    }

    for (i = 0; i < 140; i++) {
        if (D_8011BE90[i + 0x33C8] != 5) {
            D_8011BE90[i + 0x33C8] = 0;
        }
    }
}

extern u8 D_80121F04;
extern void func_80019D80(u8 *note);
extern void func_8001ADB4(u8 *listItem);
extern void func_8001CB1C(u8 *list, u8 *listItem);
// Same code as Majora's Mask AudioHeap_DiscardFont (src/audio/lib/heap.c).
void func_800101D8(s32 arg0) {
    s32 i;

    for (i = 0; i < *(s32 *)(D_8011BE90 + 0x2C28); i++) {
        // FAKE: same note-address form as func_800102BC.
        u8 *note = (u8 *)(i * 0x100 + (u32)((AudioNoteArrayField *)(D_8011BE90 + 0x3468))->notes);

        if (note[0x33] == arg0) {
            if ((note[0x34] == 0) && (note[0x30] != 0)) {
                (*(SeqLayerFlags **)(note + 0x44))->enabled = 0;
                (*(SeqLayerFlags **)(note + 0x44))->finished = 1;
            }

            func_80019D80(note);
            func_8001ADB4(note);
            func_8001CB1C(&D_80121F04, note);
        }
    }
}

// Same code as Majora's Mask AudioHeap_ReleaseNotesForFont (src/audio/lib/heap.c).
void func_800102BC(s32 arg0) {
    s32 i;

    for (i = 0; i < *(s32 *)(D_8011BE90 + 0x2C28); i++) {
        // FAKE: integer addition through a struct member; the plain
        // &notes[i] form swaps the addu operands (diff score 10).
        u8 *note = (u8 *)(i * 0x100 + (u32)((AudioNoteArrayField *)(D_8011BE90 + 0x3468))->notes);
        u8 *playbackState = note + 0x30;

        if (playbackState[3] == arg0) {
            if (playbackState[0] != 0) {
                playbackState[0] = 1;
                *(f32 *)(playbackState + 0x3C) = *(f32 *)(D_8011BE90 + 0x2BF8);
                ((AdsrActionBits *)(playbackState + 0x30))->release = 1;
            }
        }
    }
}

extern u8 D_8011BE90[];
extern void func_8001CA3C(s32);
void func_80010334(s32 arg0)
{
  s32 index;
  index = 0;
  if ((*((s16 *) (D_8011BE90 + 0x2BF0))) > 0)
  {
    do
    {
      if (((((u32) (*((s32 *) (D_8011BE90 + (index * 0x160) + 0x346C)))) >> 31) != 0) && (arg0 == *((u8 *) (D_8011BE90 + (index * 0x160) + 0x3470))))
      {
        func_8001CA3C(*((s32 *) ((D_8011BE90 + (index * 4)) + 0x604C)));
      }
      index++;
    }
    while (index < (*((s16 *) (D_8011BE90 + 0x2BF0))));
  }
}

extern void func_80019580(s32);
#ifdef CC_CHECK
s32 func_800103C8(s32 arg0, s32 arg1) { func_80019580(arg0); arg0 += 0x20000000; return arg0; }
#else
s32 func_800103C8(s32 arg0) { func_80019580(arg0); arg0 += 0x20000000; return arg0; }
#endif

extern u8 D_8011EBC0;
extern s32 D_8011EBD0;
s32 func_80010510();
s32 func_800103F0(void *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (D_8011EBD0 != 0) {
        var_v1 = func_80010510((void *) ((u8 *) &D_8011EBC0 + 0x10));
    }
    if (var_v1 == 0) {
        var_v1 = func_80010510(arg0, arg1);
    }
    return var_v1;
}
extern u8 D_8011EBC0;
extern s32 D_8011EBD0;
s32 GbApu_Alloc();
s32 func_80010448(void *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (D_8011EBD0 != 0) {
        var_v1 = GbApu_Alloc((void *) ((u8 *) &D_8011EBC0 + 0x10), arg1);
    }
    if (var_v1 == 0) {
        var_v1 = GbApu_Alloc(arg0, arg1);
    }
    return var_v1;
}
s32 GbApu_Alloc();
s32 func_80010510();
s32 func_800104A0(void *arg0, s32 arg1) {
#ifndef CC_CHECK
    s32 func_800103C8();
#endif
    s32 result = GbApu_Alloc(arg0, arg1);
    if (result != 0) {
        result = func_800103C8(result, arg1);
    }
    return result;
}

s32 func_800104D8(void *arg0, s32 arg1) {
#ifndef CC_CHECK
    s32 func_800103C8();
#endif
    s32 result = func_80010510(arg0, arg1);
    if (result != 0) {
        result = func_800103C8(result, arg1);
    }
    return result;
}

s32 func_80010510(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    u8 *var_v1;
    temp_v0 = GbApu_Alloc(arg0, arg1);
    if (temp_v0 != 0) {
        var_v1 = (u8 *)temp_v0;
        if ((u32)temp_v0 < *(u32 *)(arg0 + 4)) {
            do {
                *var_v1 = 0;
                var_v1 += 1;
            } while ((u32)var_v1 < *(u32 *)(arg0 + 4));
        }
    }
    return temp_v0;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} T_1056C_A;
s32 func_8001056C(T_1056C_A *arg0, s32 arg1) {
    s32 saved;
    s32 result;
    saved = arg0->unk4;
    result = GbApu_Alloc(arg0, arg1);
    if (result != 0) {
        arg0->unk4 = saved;
        arg0->unkC -= 1;
    }
    return result;
}

#define ALIGN16(val) (((val) + 0xFu) & ~0xFu)
typedef struct S1_unk_func_81206FA0 S1_unk_func_81206FA0;
struct S1_unk_func_81206FA0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
};
s32 GbApu_Alloc(S1_unk_func_81206FA0* arg0, s32 arg1) {
  s32 temp_a2;
  u32 temp_v0;

  temp_v0 = ALIGN16(arg1);
  temp_a2 = arg0->unk_04;
  if ((arg0->unk_00 + arg0->unk_08) >= (arg0->unk_04 + temp_v0)) {
      arg0->unk_04 = temp_v0 + temp_a2;
  } else {
      return 0;
  }
  arg0->unk_0C++;
  return temp_a2;
}

void GbApu_InitAllocator(u8 *arg0, s32 arg1, s32 arg2) {
    s32 aligned = (arg1 + 0xF) & ~0xF;
    *(s32 *)(arg0 + 0) = aligned;
    *(s32 *)(arg0 + 4) = aligned;
    *(s32 *)(arg0 + 8) = arg2 - (arg1 & 0xF);
    *(s32 *)(arg0 + 0xC) = 0;
}

void func_80010638(u8 *arg0) { *(s32 *)(arg0 + 0x10) = 0; *(s32 *)arg0 = 0; *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 4); }

void func_8001064C(void *arg0)
{
  u8 *p = arg0;
  s32 value = *((s32 *) (p + 4));
  *((s32 *) (p + 0x10)) = 0;
  *((s32 *) (p + 0x00)) = 0;
  *((s32 *) (p + 0x20)) = value;
  *((s32 *) (p + 0x20)) += *((s32 *) (p + 0x0C));
  *((s16 *) (p + 0x1E)) = -1;
  *((s16 *) (p + 0x2A)) = -1;
  *((s32 *) (p + 0x08)) = value;
  *((s32 *) (p + 0x14)) = value;
}

void func_8001067C(u8 *arg0) { *(s32 *)(arg0 + 0xC) = 0; *(s32 *)(arg0 + 4) = *(s32 *)arg0; }

extern u8 D_8011F258;
extern u8 D_8011F1F4;
extern u8 D_8011F190;
extern void func_800101D8(s32);
extern void func_80012EAC(s32 arg0);
extern u8 D_8011EC50;
extern u8 D_8011ED60;
extern u8 D_8011EE70;
void func_8001068C(s32 arg0)
{
    typedef struct {
        s32 value;
        s32 other;
        s16 unused;
        s16 id;
    } Record1068C;
    u8 *state;
    u32 count;
    u8 *first;
    s32 value;
    u8 *flags;

    switch (arg0) {
    case 0:
        state = &D_8011EC50;
        flags = &D_8011F258;
        break;
    case 1:
        state = &D_8011ED60;
        flags = &D_8011F1F4;
        break;
    case 2:
        state = &D_8011EE70;
        flags = &D_8011F190;
        break;
    }
    count = *(s32 *)state;
    first = state + 4;
    if (count != 0) {
        value = *(s32 *)((u32)state + count * 0xC + 8);
        (*(s32 *)(first + 0xC))--;
        *(s32 *)(first + 4) = value;
        if (arg0 == 2) {
            func_80012EAC(((Record1068C *)(state + 8))[*(s32 *)state].id);
        }
        if (arg0 == 1) {
            func_800101D8(((Record1068C *)(state + 8))[*(s32 *)state].id);
        }
        flags[*(s16 *)(state + *(s32 *)state * 0xC + 0x12)] = 0;
        (*(s32 *)state)--;
    }
}

extern u8 D_8011EBC0;
extern u8 D_8011EBE0;
extern s32 D_8011F2F0;
extern u8 D_8011BE90[];
extern s32 D_8011EBD0;

void func_800107CC(s32 arg0) {
    GbApu_InitAllocator(&D_8011EBE0, D_8011F2F0, arg0);
    GbApu_InitAllocator(&D_8011EBC0, (*(s32 *)((u8 *)(D_8011BE90) + (0x3460))) + arg0, (*(s32 *)((u8 *)(D_8011BE90) + (0x3464))) - arg0);
    D_8011EBD0 = 0;
}

extern u8 D_8011EBF0;
extern S1_unk_func_81206FA0 D_8011EC20;
u8 *func_80012630();
u8 *func_80012BC4();
void func_8001082C(void *arg0) {
    *(s32 *)(D_8011BE90 + 0x2D34) = *(s32 *)(D_8011BE90 + 0x2D30);
    GbApu_InitAllocator(&D_8011EBF0, GbApu_Alloc(&D_8011EBC0, *(s32 *)((u8 *)arg0 + 0)), *(s32 *)((u8 *)arg0 + 0));
    GbApu_InitAllocator((u8 *)&D_8011EC20, GbApu_Alloc(&D_8011EBC0, *(s32 *)((u8 *)arg0 + 0xC)), *(s32 *)((u8 *)arg0 + 0xC));
}

extern u8 D_8011EC30;
extern u8 D_8011EC40;
void func_800108B0(void *arg0) {
    (*(s32 *)((u8 *)(D_8011BE90) + (0x2D94))) = (s32) (*(s32 *)((u8 *)(D_8011BE90) + (0x2D90)));
    GbApu_InitAllocator(&D_8011EC30, GbApu_Alloc(&D_8011EC20, (*(s32 *)((u8 *)(arg0) + (0)))), (*(s32 *)((u8 *)(arg0) + (0))));
    GbApu_InitAllocator(&D_8011EC40, GbApu_Alloc(&D_8011EC20, (*(s32 *)((u8 *)(arg0) + (4)))), (*(s32 *)((u8 *)(arg0) + (4))));
}

extern u8 D_8011EC50;
extern u8 D_8011EC54;
extern u8 D_8011ED60;
extern u8 D_8011ED64;
extern u8 D_8011EE70;
extern u8 D_8011EE74;
extern u8 D_8011ED24;
extern u8 D_8011ED28;
extern u8 D_8011EE34;
extern u8 D_8011EE38;
extern u8 D_8011EF44;
extern u8 D_8011EF48;
void func_80010934(void *arg0) {
    *(s32 *)(D_8011BE90 + 0x2DA4) = *(s32 *)(D_8011BE90 + 0x2DA0);
    GbApu_InitAllocator(&D_8011EC54, GbApu_Alloc(&D_8011EC30, *(s32 *)((u8 *)arg0 + 0)), *(s32 *)((u8 *)arg0 + 0));
    GbApu_InitAllocator(&D_8011ED64, GbApu_Alloc(&D_8011EC30, *(s32 *)((u8 *)arg0 + 4)), *(s32 *)((u8 *)arg0 + 4));
    GbApu_InitAllocator(&D_8011EE74, GbApu_Alloc(&D_8011EC30, *(s32 *)((u8 *)arg0 + 8)), *(s32 *)((u8 *)arg0 + 8));
    func_80010638(&D_8011EC50);
    func_80010638(&D_8011ED60);
    func_80010638(&D_8011EE70);
}

void func_800109F8(void *arg0) {
    *(s32 *)(D_8011BE90 + 0x2DB4) = *(s32 *)(D_8011BE90 + 0x2DB0);
    GbApu_InitAllocator(&D_8011ED28, GbApu_Alloc(&D_8011EC40, *(s32 *)((u8 *)arg0 + 0)), *(s32 *)((u8 *)arg0 + 0));
    GbApu_InitAllocator(&D_8011EE38, GbApu_Alloc(&D_8011EC40, *(s32 *)((u8 *)arg0 + 4)), *(s32 *)((u8 *)arg0 + 4));
    GbApu_InitAllocator(&D_8011EF48, GbApu_Alloc(&D_8011EC40, *(s32 *)((u8 *)arg0 + 8)), *(s32 *)((u8 *)arg0 + 8));
    func_8001064C(&D_8011ED24);
    func_8001064C(&D_8011EE34);
    func_8001064C(&D_8011EF44);
}

// Allocation pool header used by GbApu_Alloc and GbApu_InitAllocator.
typedef struct {
    u8 *startAddr;
    u8 *curAddr;
    s32 size;
    s32 numEntries;
} AudioAllocPoolT;

typedef struct {
    u8 *addr;
    u32 size;
    s16 tableType;
    s16 id;
} AudioCacheEntryT;

// Caches at D_8011EC50 (sequences), D_8011ED60 (fonts) and D_8011EE70 (sample banks).
typedef struct {
    u32 numEntries;
    AudioAllocPoolT pool;
    AudioCacheEntryT entries[16];
} AudioPersistentCacheT;

typedef struct {
    u32 nextSide;
    AudioAllocPoolT pool;
    AudioCacheEntryT entries[2];
} AudioTemporaryCacheT;

typedef struct {
    AudioPersistentCacheT persistent;
    AudioTemporaryCacheT temporary;
} AudioCacheT;

// Bit 31 of a word: the enabled flag of a sequence player (+0x346C) or of a
// note's sample state (note + 0xD0).
typedef struct {
    u32 enabled : 1;
} AudioEnabledBit;

extern s32 D_8011EAB8;
extern u8 *D_8011F2F8;
extern s16 D_8011EA80;
extern void func_800142F8(s32 fontId, s32 status);
extern void func_80010334(s32 seqId);

// Same code as Majora's Mask AudioHeap_AllocCached (src/audio/lib/heap.c).
// tableType: 0 = sequence, 1 = font, 2 = sample bank. cache: 0 = temporary,
// 1 = persistent, 2 = either. Load status values: 0 = not loaded, 1 = in progress,
// 2 = complete, 3 = discardable, 4 = maybe discardable.
// D_8011EAB8 is the note count (D_8011BE90 + 0x2C28), D_8011F2F8 the note array
// (D_8011BE90 + 0x3468), and D_8011EA80 the sequence player count.
void *func_80010ABC(s32 tableType, s32 size, s32 cache, s32 id) {
    AudioCacheT *loadedCache;
    AudioTemporaryCacheT *temporaryCache;
    AudioAllocPoolT *temporaryPool;
    void *persistentAddr;
    void *temporaryAddr;
    u8 loadStatusEntry0;
    u8 loadStatusEntry1;
    s32 i;
    u8 *loadStatus;
    s32 side;

    switch (tableType) {
        case 0:
            loadedCache = (AudioCacheT *)&D_8011EC50;
            loadStatus = &D_8011F258;
            break;

        case 1:
            loadedCache = (AudioCacheT *)&D_8011ED60;
            loadStatus = &D_8011F1F4;
            break;

        case 2:
            loadedCache = (AudioCacheT *)&D_8011EE70;
            loadStatus = &D_8011F190;
            break;
    }

    if (cache == 0) {
        temporaryCache = &loadedCache->temporary;
        temporaryPool = &temporaryCache->pool;

        if ((s32)temporaryPool->size < (s32)size) {
            return NULL;
        }

        loadStatusEntry0 = (temporaryCache->entries[0].id == -1) ? 0 : loadStatus[temporaryCache->entries[0].id];
        loadStatusEntry1 = (temporaryCache->entries[1].id == -1) ? 0 : loadStatus[temporaryCache->entries[1].id];

        if (tableType == 1) {
            if (loadStatusEntry0 == 4) {
                for (i = 0; i < D_8011EAB8; i++) {
                    if ((D_8011F2F8[i * 0x100 + 0x33] == temporaryCache->entries[0].id) &&
                        ((AudioEnabledBit *)(D_8011F2F8 + i * 0x100 + 0xD0))->enabled) {
                        break;
                    }
                }

                if (i == D_8011EAB8) {
                    func_800142F8(temporaryCache->entries[0].id, 3);
                    loadStatusEntry0 = 3;
                }
            }

            if (loadStatusEntry1 == 4) {
                for (i = 0; i < D_8011EAB8; i++) {
                    if ((D_8011F2F8[i * 0x100 + 0x33] == temporaryCache->entries[1].id) &&
                        ((AudioEnabledBit *)(D_8011F2F8 + i * 0x100 + 0xD0))->enabled) {
                        break;
                    }
                }

                if (i == D_8011EAB8) {
                    func_800142F8(temporaryCache->entries[1].id, 3);
                    loadStatusEntry1 = 3;
                }
            }
        }

        if (loadStatusEntry0 == 0) {
            temporaryCache->nextSide = 0;
        } else if (loadStatusEntry1 == 0) {
            temporaryCache->nextSide = 1;
        } else if ((loadStatusEntry0 == 3) && (loadStatusEntry1 == 3)) {
            // Use the opposite side from last time.
        } else if (loadStatusEntry0 == 3) {
            temporaryCache->nextSide = 0;
        } else if (loadStatusEntry1 == 3) {
            temporaryCache->nextSide = 1;
        } else {
            // Check if there is a side which isn't in active use, if so, evict that one.
            if (tableType == 0) {
                if (loadStatusEntry0 == 2) {
                    for (i = 0; i < D_8011EA80; i++) {
                        if (((AudioEnabledBit *)(D_8011BE90 + i * 0x160 + 0x346C))->enabled &&
                            *(D_8011BE90 + i * 0x160 + 0x3470) == temporaryCache->entries[0].id) {
                            break;
                        }
                    }

                    if (i == D_8011EA80) {
                        temporaryCache->nextSide = 0;
                        goto done;
                    }
                }

                if (loadStatusEntry1 == 2) {
                    for (i = 0; i < D_8011EA80; i++) {
                        if (((AudioEnabledBit *)(D_8011BE90 + i * 0x160 + 0x346C))->enabled &&
                            *(D_8011BE90 + i * 0x160 + 0x3470) == temporaryCache->entries[1].id) {
                            break;
                        }
                    }

                    if (i == D_8011EA80) {
                        temporaryCache->nextSide = 1;
                        goto done;
                    }
                }
            } else if (tableType == 1) {
                if (loadStatusEntry0 == 2) {
                    for (i = 0; i < D_8011EAB8; i++) {
                        if ((D_8011F2F8[i * 0x100 + 0x33] == temporaryCache->entries[0].id) &&
                            ((AudioEnabledBit *)(D_8011F2F8 + i * 0x100 + 0xD0))->enabled) {
                            break;
                        }
                    }
                    if (i == D_8011EAB8) {
                        temporaryCache->nextSide = 0;
                        goto done;
                    }
                }

                if (loadStatusEntry1 == 2) {
                    for (i = 0; i < D_8011EAB8; i++) {
                        if ((D_8011F2F8[i * 0x100 + 0x33] == temporaryCache->entries[1].id) &&
                            ((AudioEnabledBit *)(D_8011F2F8 + i * 0x100 + 0xD0))->enabled) {
                            break;
                        }
                    }
                    if (i == D_8011EAB8) {
                        temporaryCache->nextSide = 1;
                        goto done;
                    }
                }
            }

            // No such luck. Evict the side that wasn't chosen last time, except
            // if it is being loaded into.
            if (temporaryCache->nextSide == 0) {
                if (loadStatusEntry0 == 1) {
                    if (loadStatusEntry1 == 1) {
                        goto fail;
                    }
                    temporaryCache->nextSide = 1;
                }
            } else {
                if (loadStatusEntry1 == 1) {
                    if (loadStatusEntry0 == 1) {
                        goto fail;
                    }
                    temporaryCache->nextSide = 0;
                }
            }

            if (0) {
            fail:
                // Both sides are being loaded into.
                return NULL;
            }
        }
    done:

        side = temporaryCache->nextSide;

        if (temporaryCache->entries[side].id != -1) {
            if (tableType == 2) {
                func_80012EAC(temporaryCache->entries[side].id);
            }

            loadStatus[temporaryCache->entries[side].id] = 0;

            if (tableType == 1) {
                func_800101D8(temporaryCache->entries[side].id);
            }
        }

        switch (side) {
            case 0:
                temporaryCache->entries[0].addr = temporaryPool->startAddr;
                temporaryCache->entries[0].id = id;
                temporaryCache->entries[0].size = size;
                temporaryPool->curAddr = temporaryPool->startAddr + size;

                if ((temporaryCache->entries[1].id != -1) &&
                    (temporaryCache->entries[1].addr < temporaryPool->curAddr)) {
                    if (tableType == 2) {
                        func_80012EAC(temporaryCache->entries[1].id);
                    }

                    loadStatus[temporaryCache->entries[1].id] = 0;

                    switch (tableType) {
                        case 0:
                            func_80010334((s32)temporaryCache->entries[1].id);
                            break;

                        case 1:
                            func_800101D8((s32)temporaryCache->entries[1].id);
                            break;
                    }

                    temporaryCache->entries[1].id = -1;
                    temporaryCache->entries[1].addr = temporaryPool->startAddr + temporaryPool->size;
                }

                temporaryAddr = temporaryCache->entries[0].addr;
                break;

            case 1:
                temporaryCache->entries[1].addr =
                    (u8 *)((u32)(temporaryPool->startAddr + temporaryPool->size - size) & ~0xF);
                temporaryCache->entries[1].id = id;
                temporaryCache->entries[1].size = size;
                if ((temporaryCache->entries[0].id != -1) &&
                    (temporaryCache->entries[1].addr < temporaryPool->curAddr)) {
                    if (tableType == 2) {
                        func_80012EAC(temporaryCache->entries[0].id);
                    }

                    loadStatus[temporaryCache->entries[0].id] = 0;

                    switch (tableType) {
                        case 0:
                            func_80010334(temporaryCache->entries[0].id);
                            break;

                        case 1:
                            func_800101D8(temporaryCache->entries[0].id);
                            break;
                    }

                    temporaryCache->entries[0].id = -1;
                    temporaryPool->curAddr = temporaryPool->startAddr;
                }

                temporaryAddr = temporaryCache->entries[1].addr;
                break;

            default:
                return NULL;
        }

        temporaryCache->nextSide ^= 1;
        return temporaryAddr;
    }

    persistentAddr = (void *)GbApu_Alloc((S1_unk_func_81206FA0 *)&loadedCache->persistent.pool, size);
    loadedCache->persistent.entries[loadedCache->persistent.numEntries].addr = persistentAddr;

    if (persistentAddr == NULL) {
        switch (cache) {
            case 2:
                return func_80010ABC(tableType, size, 0, id);

            case 0:
            case 1:
                return NULL;
        }
    }

    loadedCache->persistent.entries[loadedCache->persistent.numEntries].id = id;
    loadedCache->persistent.entries[loadedCache->persistent.numEntries].size = size;

    return loadedCache->persistent.entries[loadedCache->persistent.numEntries++].addr;
}

s32 func_800112A8();
s32 func_8001244C();
void func_8001291C();
s32 func_80011250(s32 arg0, s32 arg1, s32 arg2) {
    s32 result = func_8001244C(arg0, arg2);
    if (result != 0) {
        return result;
    }
    if (arg1 == 3) {
        return 0;
    }
    return func_800112A8(arg0, arg1, arg2);
}

extern s32 func_80011250(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_8011EC50;
extern u8 D_8011ED60;
extern u8 D_8011EE70;
s32 func_800112A8(s32 arg0, volatile s32 arg1, s32 arg2)
{
    u8 *p;
    u8 *base;
    u32 i;
    u8 *loopBase;

    switch (arg0) {
    case 0: base = &D_8011EC50; break;
    case 1: base = &D_8011ED60; break;
    case 2: base = &D_8011EE70; break;
    }
    p = base + 0xD4;
    if (arg1 == 0) {
        if (arg2 == *(s16 *)(p + 0x1E)) {
            *(s32 *)p = 1;
            return *(s32 *)(p + 0x14);
        }
        if (arg2 == *(s16 *)(p + 0x2A)) {
            *(s32 *)p = 0;
            return *(s32 *)(p + 0x20);
        }
        return 0;
    }
    loopBase = base;
    for (i = 0, p = base; i < *(u32 *)loopBase; i++, p += 0xC) {
        if (arg2 == *(s16 *)(p + 0x1E)) {
            return *(s32 *)(p + 0x14);
        }
    }
    if (arg1 == 2) {
        return func_80011250(arg0, 0, arg2);
    }
    return 0;
}

// Same code as Star Fox 64 func_8000CAF4 (src/audio/audio_heap.c).
// Unused here as well. The loop stores into out instead of tmp, so later
// iterations read uninitialized tmp entries.
void func_800113B4(f32 p, f32 q, u16 *out) {
    s32 i;
    f32 tmp[16];

    tmp[0] = (f32) (q * 262159.0f);
    tmp[8] = (f32) (p * 262159.0f);
    tmp[1] = (f32) ((q * p) * 262159.0f);
    tmp[9] = (f32) (((p * p) + q) * 262159.0f);

    for (i = 2; i < 8; i++) {
        out[i] = q * tmp[i - 2] + p * tmp[i - 1];
        out[8 + i] = q * tmp[6 + i] + p * tmp[7 + i];
    }

    for (i = 0; i < 16; i++) {
        out[i] = tmp[i];
    }
}

void func_80011788(void *arg0) { s32 var_v0 = 0; u8 *var_v1 = (u8 *)arg0; do { var_v0 += 4; *(s16 *)(var_v1 + 2) = 0; *(s16 *)(var_v1 + 4) = 0; *(s16 *)(var_v1 + 6) = 0; var_v1 += 8; *(s16 *)(var_v1 - 8) = 0; } while (var_v0 != 8); }

extern u8 D_8008D660[];
void func_800117B8(s16 *arg0, s32 arg1) { s32 i; for (i = 0; i < 8; i += 4) { arg0[i] = ((s16 *)D_8008D660)[arg1 * 8 + i]; arg0[i + 1] = ((s16 *)D_8008D660)[arg1 * 8 + i + 1]; arg0[i + 2] = ((s16 *)D_8008D660)[arg1 * 8 + i + 2]; arg0[i + 3] = ((s16 *)D_8008D660)[arg1 * 8 + i + 3]; } }

extern u8 D_8008D760[];
void func_8001180C(s16 *arg0, s32 arg1) { s32 i; s32 offset; offset = (arg1 - 1) * 8; i = 0; if (8 > 0) { do { arg0[i] = ((s16 *)D_8008D760)[offset + i]; arg0[i + 1] = ((s16 *)D_8008D760)[offset + i + 1]; arg0[i + 2] = ((s16 *)D_8008D760)[offset + i + 2]; arg0[i + 3] = ((s16 *)D_8008D760)[offset + i + 3]; i += 4; } while (i < 8); } }

extern s16 D_8008D850[];
extern s16 D_8008DEE0[];
// Same code as Majora's Mask AudioHeap_LoadFilter (src/audio/lib/heap.c).
// D_8008D850 holds band-stop and D_8008DEE0 band-pass filter coefficients.
void func_80011864(s16 *filter, s32 lowPassCutoff, s32 highPassCutoff) {
    s32 i;
    s32 j;
    s32 k;
    s32 cutOff;

    // The filter is left unset when both cutoffs are equal and nonzero.
    if ((lowPassCutoff == 0) && (highPassCutoff == 0)) {
        // Identity filter.
        func_800117B8(filter, 0);
    } else if (highPassCutoff == 0) {
        func_800117B8(filter, lowPassCutoff);
    } else if (lowPassCutoff == 0) {
        func_8001180C(filter, highPassCutoff);
    } else {
        k = 0;
        j = 14;

        cutOff = lowPassCutoff;
        if (lowPassCutoff < highPassCutoff) {

            for (i = 1; i < cutOff; i++) {
                k += j;
                j--;
            }

            k += highPassCutoff - lowPassCutoff - 1;
            for (i = 0; i < 8; i++) {
                // Reads coefficients at k + i rather than 8 * k + i.
                filter[i] = D_8008D850[k + i];
            }
        } else if (highPassCutoff < lowPassCutoff) {

            cutOff = highPassCutoff;
            for (i = 1; i < cutOff; i++) {
                k += j;
                j--;
            }

            k += lowPassCutoff - highPassCutoff - 1;
            for (i = 0; i < 8; i++) {
                // Reads coefficients at k + i rather than 8 * k + i.
                filter[i] = D_8008DEE0[k + i];
            }
        }
    }
}

void func_80011A40(u8 *arg0) {}

extern void func_80011A40(u8 *arg0);
void func_80011A48(void) {
    s32 mode;
    s32 i;
    s32 j;
    if (*(s16 *)(D_8011BE90 + 0x2BDC) == 2) mode = 2; else mode = 1;
    i = 0;
    while (i < *(s8 *)(D_8011BE90 + 1)) {
        j = 0;
        while (j < mode) {
            func_80011A40(D_8011BE90 + i * 0x2D0 + 0x18);
            j++;
        }
        i++;
    }
}

extern u8 D_8011BE90[];
void func_80011B0C(void)
{
    s32 index;
    s32 i;
    u8 *slot;

    index = *(s32 *)(D_8011BE90 + 0x2C3C);
    i = 0;
    slot = D_8011BE90 + index * 4;
    *(s16 *)(D_8011BE90 + index * 2 + 0x2D04) = *(s16 *)(D_8011BE90 + 0x2BE6);
    do {
        *(s16 *)(*(u8 **)(slot + 0x2CF8) + i * 2) = 0;
        i++;
    } while (i != 0x540);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/10BB0/func_80011B78.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/10BB0/func_80011E7C.s")

extern u8 D_8011BE90[];
extern s32 D_8011EF8C;
s32 func_8001244C(s32 arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < D_8011EF8C; i++) {
        if (arg0 == *(s16 *)(D_8011BE90 + i * 0xC + 0x3108) && arg1 == *(s16 *)(D_8011BE90 + i * 0xC + 0x310A)) {
            return *(s32 *)(D_8011BE90 + i * 0xC + 0x3100);
        }
    }
    return 0;
}

extern S1_unk_func_81206FA0 D_8011EF80;
extern s32 D_8011EF8C;
s32 func_800124A4(s32 arg0, s32 arg1, s32 arg2)
{
  s32 locals[2];
  s32 result;
  locals[0] = D_8011EF8C;
  result = GbApu_Alloc(&D_8011EF80, arg2);
  *((s32 *) ((D_8011BE90 + (locals[0] * 0xC)) + 0x3100)) = result;
  if (result == 0)
  {
    return 0;
    return result;
  }
  *((s16 *) ((D_8011BE90 + (locals[0] * 0xC)) + 0x3108)) = arg0;
  *((s16 *) ((D_8011BE90 + (locals[0] * 0xC)) + 0x310A)) = arg1;
  *((s32 *) ((D_8011BE90 + (locals[0] * 0xC)) + 0x3104)) = arg2;
}

s32 func_80012528(s32 arg0, s32 arg1, s32 arg2, s8 arg3, s32 arg4) {
    u8 *result;
    if (arg4 == 0) {
        result = func_80012630(arg0);
    } else {
        result = func_80012BC4(arg0);
    }
    if (result != NULL) {
        result[2] = arg1;
        *(s32 *)(result + 0xC) = arg2;
        result[1] = arg3;
        return *(s32 *)(result + 8);
    }
    return 0;
}

extern u8 D_8011F110;
extern u8 D_8011F138;
// Same code as Majora's Mask AudioHeap_InitSampleCaches (src/audio/lib/heap.c).
// Persistent sample cache: pool D_8011F110 (size at +0x3288), entry count at +0x32A4.
// Temporary sample cache: pool D_8011F138 (size at +0x32B0), entry count at +0x32CC.
void func_80012598(s32 persistentSize, s32 temporarySize) {
    s32 addr;

    addr = func_80010448(&D_8011EBF0, persistentSize);
    if (addr == 0) {
        *(s32 *)(D_8011BE90 + 0x3288) = 0;
    } else {
        GbApu_InitAllocator(&D_8011F110, addr, persistentSize);
    }

    addr = func_80010448(&D_8011EBF0, temporarySize);
    if (addr == 0) {
        *(s32 *)(D_8011BE90 + 0x32B0) = 0;
    } else {
        GbApu_InitAllocator(&D_8011F138, addr, temporarySize);
    }

    *(s32 *)(D_8011BE90 + 0x32A4) = 0;
    *(s32 *)(D_8011BE90 + 0x32CC) = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/10BB0/func_80012630.s")

extern u8 *func_8001A308(s32 fontId, s32 instId);
extern u8 *func_8001A3DC(s32 fontId, s32 drumId);
extern u8 *func_8001A4C0(s32 fontId, s32 sfxId);
void func_80012B80(u8 *arg0, u8 *arg1);
// Same code as Majora's Mask AudioHeap_UnapplySampleCacheForFont (src/audio/lib/heap.c).
// Instruments: range low/high at +1/+2, sample pointers at +8 (low), +0x10 (normal),
// +0x18 (high). Drums keep their sample at +4, sound effects at +0.
void func_8001291C(u8 *entry, s32 fontId) {
    u8 *drum;
    u8 *inst;
    u8 *soundEffect;
    s32 instId;
    s32 drumId;
    s32 sfxId;

    for (instId = 0; instId < (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].numInstruments; instId++) {
        inst = func_8001A308(fontId, instId);
        if (inst != NULL) {
            if (inst[1] != 0) {
                func_80012B80(entry, *(u8 **)(inst + 8));
            }
            if (inst[2] != 0x7F) {
                func_80012B80(entry, *(u8 **)(inst + 0x18));
            }
            func_80012B80(entry, *(u8 **)(inst + 0x10));
        }
    }

    for (drumId = 0; drumId < (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].numDrums; drumId++) {
        drum = func_8001A3DC(fontId, drumId);
        if (drum != NULL) {
            func_80012B80(entry, *(u8 **)(drum + 4));
        }
    }

    for (sfxId = 0; sfxId < (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].numSfx; sfxId++) {
        soundEffect = func_8001A4C0(fontId, sfxId);
        if (soundEffect != NULL) {
            func_80012B80(entry, *(u8 **)(soundEffect + 0));
        }
    }
}

extern s32 func_80014190(s32 fontId);
// Same code as Majora's Mask AudioHeap_DiscardSampleCacheEntry (src/audio/lib/heap.c).
// entry + 2 holds the sample bank id; the font table pointer is at D_8011BE90 + 0x2BC4.
void func_80012A90(u8 *entry) {
    s32 numFonts;
    s32 sampleBankId1;
    s32 sampleBankId2;
    s32 fontId;

    numFonts = **(s16 **)(D_8011BE90 + 0x2BC4);
    for (fontId = 0; fontId < numFonts; fontId++) {
        sampleBankId1 = (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].sampleBankId1;
        sampleBankId2 = (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].sampleBankId2;
        if (((sampleBankId1 != 0xFF) && (entry[2] == sampleBankId1)) ||
            ((sampleBankId2 != 0xFF) && (entry[2] == sampleBankId2)) || (entry[2] == 0) ||
            (entry[2] == 0xFE)) {
            if (func_80011250(1, 2, fontId) == 0) {
                continue;
            }
            if (func_80014190(fontId) != 0) {
                func_8001291C(entry, fontId);
            }
        }
    }
}

void func_80012B80(u8 *arg0, u8 *arg1) { if (arg1 != 0) { if ((*((s32 *) (arg0 + 8))) == (*((s32 *) (arg1 + 4)))) { *((s32 *) (arg1 + 4)) = *((s32 *) (arg0 + 0xC)); *arg1 = ((*arg1) & 0xFFF3) | (((*((s8 *)(arg0 + 1)) << 1) << 1) & 0xC); } } }

#pragma GLOBAL_ASM("asm/us/nonmatchings/10BB0/func_80012BC4.s")

void func_80012C64(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 value = arg0[2];
    if ((arg1 == value) || (arg2 == value) || (value == 0)) {
        func_8001291C(arg0, arg3);
    }
}

// Same code as Majora's Mask AudioHeap_DiscardSampleCaches (src/audio/lib/heap.c).
// Sample cache entries are 0x14 bytes: persistent entries start at +0x3290
// (count at +0x32A4), temporary entries at +0x32B8 (count at +0x32CC).
void func_80012CA0(void) {
    s32 numFonts;
    s32 sampleBankId1;
    s32 sampleBankId2;
    s32 fontId;
    s32 j;

    numFonts = **(s16 **)(D_8011BE90 + 0x2BC4);
    for (fontId = 0; fontId < numFonts; fontId++) {
        sampleBankId1 = (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].sampleBankId1;
        sampleBankId2 = (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].sampleBankId2;
        if ((sampleBankId1 == 0xFF) && (sampleBankId2 == 0xFF)) {
            continue;
        }
        if ((func_80011250(1, 3, fontId) == 0) || !func_80014190(fontId)) {
            continue;
        }

        for (j = 0; j < *(s32 *)(D_8011BE90 + 0x32A4); j++) {
            func_80012C64(D_8011BE90 + 0x3290 + j * 0x14, sampleBankId1, sampleBankId2, fontId);
        }
        for (j = 0; j < *(s32 *)(D_8011BE90 + 0x32CC); j++) {
            func_80012C64(D_8011BE90 + 0x32B8 + j * 0x14, sampleBankId1, sampleBankId2, fontId);
        }
    }
}

extern s32 D_800D12F0;
// Sample header word: bits 31-28 hold flags and codec, bits 27-26 the storage medium.
typedef struct {
    u32 unk_0 : 4;
    u32 medium : 2;
    u32 unk_6 : 26;
    u8 *sampleAddr;
} AudioSampleHeader;

// Address range move applied to samples by func_80012DF0.
typedef struct {
    u32 oldAddr;
    u32 newAddr;
    u32 size;
    u8 newMedium;
} AudioStorageChange;

// Same code as Majora's Mask AudioHeap_ChangeStorage (src/audio/lib/heap.c).
// D_800D12F0 selects the direction (set by func_80012EAC and func_80012ED8).
void func_80012DF0(AudioStorageChange *change, AudioSampleHeader *sample) {
    if ((sample != NULL) && ((sample->medium == change->newMedium) || (D_800D12F0 != 1)) &&
        ((sample->medium == 0) || (D_800D12F0 != 0))) {
        u32 startAddr = change->oldAddr;
        u32 endAddr = change->oldAddr + change->size;

        if (((u32)sample->sampleAddr >= startAddr) && ((u32)sample->sampleAddr < endAddr)) {
            sample->sampleAddr += -startAddr + change->newAddr;
            if (D_800D12F0 == 0) {
                sample->medium = change->newMedium;
            } else {
                sample->medium = 0;
            }
        }
    }
}

void func_80012F08(s32 apply, s32 sampleBankId);void func_80012EAC(s32 arg0){D_800D12F0=0;func_80012F08(0,arg0);}

void func_80012ED8(s32 arg0){D_800D12F0=1;func_80012F08(1,arg0);}

// Audio table: 0x10-byte header, then 0x10-byte entries (ROM address, size, medium).
typedef struct {
    u32 romAddr;
    u32 size;
    s8 medium;
    u8 unk_9[7];
} AudioTableEntryT;
typedef struct {
    s16 numEntries;
    u8 unk_2[0xE];
    AudioTableEntryT entries[1];
} AudioTableT;

// Same code as Majora's Mask AudioHeap_ApplySampleBankCacheInternal (src/audio/lib/heap.c).
// The sample bank table pointer is at D_8011BE90 + 0x2BC8. For every loaded font that
// uses the bank, moves its sample addresses between the bank's ROM range and the
// cached copy (direction chosen by apply).
void func_80012F08(s32 apply, s32 sampleBankId) {
    AudioTableT *sampleBankTable;
    AudioTableEntryT *entry;
    s32 numFonts;
    s32 instId;
    s32 drumId;
    s32 sfxId;
    AudioStorageChange change;
    s32 sampleBankId1;
    s32 sampleBankId2;
    s32 fontId;
    u8 *drum;
    u8 *inst;
    u8 *soundEffect;
    u32 *newAddr;
    s32 pad[4];

    sampleBankTable = *(AudioTableT **)(D_8011BE90 + 0x2BC8);
    numFonts = (*(AudioTableT **)(D_8011BE90 + 0x2BC4))->numEntries;
    change.oldAddr = func_80011250(2, 2, sampleBankId);
    if (change.oldAddr == 0) {
        return;
    }

    entry = &sampleBankTable->entries[sampleBankId];
    change.size = entry->size;
    change.newMedium = entry->medium;
    change.newAddr = entry->romAddr;

    newAddr = &change.oldAddr;
    if (apply && (apply == 1)) {
        u32 oldAddr;

        oldAddr = change.newAddr;

        change.newAddr = *newAddr;
        change.oldAddr = oldAddr;
    }

    for (fontId = 0; fontId < numFonts; fontId++) {
        sampleBankId1 = (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].sampleBankId1;
        sampleBankId2 = (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].sampleBankId2;
        if ((sampleBankId1 != 0xFF) || (sampleBankId2 != 0xFF)) {
            if (!func_80014190(fontId) || func_80011250(1, 2, fontId) == 0) {
                continue;
            }

            if (sampleBankId1 == sampleBankId) {
            } else if (sampleBankId2 == sampleBankId) {
            } else {
                continue;
            }

            for (instId = 0; instId < (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].numInstruments; instId++) {
                inst = func_8001A308(fontId, instId);
                if (inst != NULL) {
                    if (inst[1] != 0) {
                        func_80012DF0(&change, *(AudioSampleHeader **)(inst + 8));
                    }
                    if (inst[2] != 0x7F) {
                        func_80012DF0(&change, *(AudioSampleHeader **)(inst + 0x18));
                    }
                    func_80012DF0(&change, *(AudioSampleHeader **)(inst + 0x10));
                }
            }

            for (drumId = 0; drumId < (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].numDrums; drumId++) {
                drum = func_8001A3DC(fontId, drumId);
                if (drum != NULL) {
                    func_80012DF0(&change, *(AudioSampleHeader **)(drum + 4));
                }
            }

            for (sfxId = 0; sfxId < (*(AudioFontInfo **)(D_8011BE90 + 0x2BD8))[fontId].numSfx; sfxId++) {
                soundEffect = func_8001A4C0(fontId, sfxId);
                if (soundEffect != NULL) {
                    func_80012DF0(&change, *(AudioSampleHeader **)(soundEffect + 0));
                }
            }
        }
    }
}

// Same code as Majora's Mask AudioHeap_DiscardSampleBanks (src/audio/lib/heap.c).
// The sample-bank cache is at D_8011BE90 + 0x2FE0 (D_8011EE70): persistent entry
// count at +0 with 12-byte entries (s16 id at +0x1E); the temporary cache at +0xD4
// has entry ids at +0x1E and +0x2A.
void func_80013174(void) {
    u8 *cache;
    u8 *persistent;
    u8 *temporary;
    u32 i;

    cache = D_8011BE90 + 0x2FE0;
    temporary = cache + 0xD4;

    if (*(s16 *)(temporary + 0x1E) != -1) {
        func_80012EAC(*(s16 *)(temporary + 0x1E));
    }

    if (*(s16 *)(temporary + 0x2A) != -1) {
        func_80012EAC(*(s16 *)(temporary + 0x2A));
    }

    persistent = cache;
    for (i = 0; i < *(u32 *)persistent; i++) {
        func_80012EAC(*(s16 *)(persistent + i * 0xC + 0x1E));
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/10BB0/func_80013210.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/10BB0/func_800137AC.s")
#endif
