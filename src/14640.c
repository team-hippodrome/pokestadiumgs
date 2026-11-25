#include "global.h"
#include "14640.h"

#ifdef VERSION_US
s32 func_80013A40(u32 devAddr, u8 *ramAddr, u32 size, s32 medium) {
    AudioFrameDmaReq *req;

    if (gAudioContext.curAudioFrameDmaCount == 64) {
        return -1;
    }
    req = &D_800D13B8[gAudioContext.curAudioFrameDmaCount++];
    req->devAddr = devAddr;
    req->ramAddr = ramAddr;
    req->size = size;
    req->medium = medium;
    //!bug: no return value on success
}

extern u8 D_8011E0F0[];
extern u8 D_8011E208[];
extern s32 func_80015584(void *, s32, s32, s32, s32, s32, void *, s32, void *);
extern u8 D_8011BE90[];
void func_80013A8C(void) {
    static const char buffer_name[8] = {66, 85, 70, 70, 69, 82, 0, 0};
    static const char error_message[36] = {84, 89, 80, 69, 32, 37, 100, 58, 73, 68, 32, 37, 100, 32, 105, 115, 32, 110, 111, 116, 32, 69, 120, 116, 101, 114, 110, 97, 108, 32, 77, 97, 112, 46, 10, 0};
    AudioFrameDmaReq *req;
    s32 *output;
    u32 i;
    i = 0;
    if (gAudioContext.curAudioFrameDmaCount != 0) {
        do {
            req = &D_800D13B8[i];
            output = (s32 *)D_8011E208 + i * 6;
            func_80015584(output, 0, 0, req->devAddr, (s32)req->ramAddr, req->size, D_8011E0F0, req->medium, buffer_name);
            i += 1;
        } while (i < gAudioContext.curAudioFrameDmaCount);
    }
    gAudioContext.curAudioFrameDmaCount = 0;
}

// Same code as Majora's Mask AudioLoad_DecreaseSampleDmaTtls (src/audio/lib/load.c).
// Counts down the time-to-live byte (0xE) of each 0x10-byte sample DMA buffer at
// *(D_8011BE90 + 0x29AC); an expired buffer gets its reuse index (0xD) and joins reuse queue 1
// (0x29BC) or 2 (0x2ABC), whose write positions are the bytes at 0x2BBE and 0x2BBF.
void func_80013B54(void) {
    u32 i;

    for (i = 0; i < *(u32 *)(D_8011BE90 + 0x29B4); i++) {
        u8 *dma = (u8 *)(i * 0x10);

        // FAKE: adding the base second orders the addu as the target does; the one-line
        // pointer sum leaves 2 instructions different.
        dma += *(u32 *)(D_8011BE90 + 0x29AC);

        if (dma[0xE] != 0) {
            dma[0xE]--;
            if (dma[0xE] == 0) {
                dma[0xD] = D_8011BE90[0x2BBE];
                D_8011BE90[0x29BC + D_8011BE90[0x2BBE]] = i;
                D_8011BE90[0x2BBE]++;
            }
        }
    }

    for (i = *(u32 *)(D_8011BE90 + 0x29B4); i < *(u32 *)(D_8011BE90 + 0x29B0); i++) {
        u8 *dma = (u8 *)(i * 0x10);

        // FAKE: adding the base second orders the addu as the target does; the one-line
        // pointer sum leaves 2 instructions different.
        dma += *(u32 *)(D_8011BE90 + 0x29AC);

        if (dma[0xE] != 0) {
            dma[0xE]--;
            if (dma[0xE] == 0) {
                dma[0xD] = D_8011BE90[0x2BBF];
                D_8011BE90[0x2ABC + D_8011BE90[0x2BBF]] = i;
                D_8011BE90[0x2BBF]++;
            }
        }
    }

    *(u32 *)(D_8011BE90 + 0x29B8) = 0;
}



extern s32 func_80013A40(u32, u8 *, u32, s32);


// Close to Ocarina of Time AudioLoad_DmaSampleData (src/code/audio_load.c): GS checks only the
// remembered short-lived DMA, marks a fresh DMA with ttl 3 and queues it through func_80013A40.
void *func_80013C40(u32 devAddr, u32 size, s32 arg2, u8 *dmaIndexRef, s32 medium) {
    s32 hasDma = FALSE;
    SampleDma *dma;
    s32 bufferPos;
    u32 i;
    u32 dmaDevAddr;
    u32 dmaIndex;

    if (arg2 != 0 || *dmaIndexRef >= gAudioContext.sampleDmaListSize1) {
        for (i = gAudioContext.sampleDmaListSize1; i < gAudioContext.sampleDmaCount; i++) {
            dma = i + gAudioContext.sampleDmas;
            bufferPos = devAddr - dma->devAddr;
            if (0 <= bufferPos && (u32)bufferPos <= dma->size - size) {
                if (dma->ttl == 0 && gAudioContext.sampleDmaReuseQueue2RdPos != gAudioContext.sampleDmaReuseQueue2WrPos) {
                    if (dma->reuseIndex != gAudioContext.sampleDmaReuseQueue2RdPos) {
                        gAudioContext.sampleDmaReuseQueue2[dma->reuseIndex] =
                            gAudioContext.sampleDmaReuseQueue2[gAudioContext.sampleDmaReuseQueue2RdPos];
                        gAudioContext.sampleDmas[gAudioContext.sampleDmaReuseQueue2[gAudioContext.sampleDmaReuseQueue2RdPos]].reuseIndex =
                            dma->reuseIndex;
                    }
                    gAudioContext.sampleDmaReuseQueue2RdPos++;
                }
                dma->ttl = 32;
                *dmaIndexRef = (u8)i;
                return &dma->ramAddr[devAddr - dma->devAddr];
            }
        }
        if (gAudioContext.sampleDmaReuseQueue2RdPos != gAudioContext.sampleDmaReuseQueue2WrPos && arg2 != 0) {
            dmaIndex = gAudioContext.sampleDmaReuseQueue2[gAudioContext.sampleDmaReuseQueue2RdPos];
            gAudioContext.sampleDmaReuseQueue2RdPos++;
            dma = dmaIndex + gAudioContext.sampleDmas;
            hasDma = TRUE;
        }
    } else {
        dma = gAudioContext.sampleDmas + *dmaIndexRef;
        bufferPos = devAddr - dma->devAddr;
        if (0 <= bufferPos && (u32)bufferPos <= dma->size - size) {
            if (dma->ttl == 0) {
                if (dma->reuseIndex != gAudioContext.sampleDmaReuseQueue1RdPos) {
                    gAudioContext.sampleDmaReuseQueue1[dma->reuseIndex] =
                        gAudioContext.sampleDmaReuseQueue1[gAudioContext.sampleDmaReuseQueue1RdPos];
                    gAudioContext.sampleDmas[gAudioContext.sampleDmaReuseQueue1[gAudioContext.sampleDmaReuseQueue1RdPos]].reuseIndex =
                        dma->reuseIndex;
                }
                gAudioContext.sampleDmaReuseQueue1RdPos++;
            }
            dma->ttl = 2;
            return dma->ramAddr + (devAddr - dma->devAddr);
        }
    }

    if (!hasDma) {
        if (gAudioContext.sampleDmaReuseQueue1RdPos == gAudioContext.sampleDmaReuseQueue1WrPos) {
            return NULL;
        }
        dmaIndex = gAudioContext.sampleDmaReuseQueue1[gAudioContext.sampleDmaReuseQueue1RdPos++];
        dma = dmaIndex + gAudioContext.sampleDmas;
        hasDma = TRUE;
    }

    dmaDevAddr = devAddr & ~0xF;
    dma->ttl = 3;
    dma->devAddr = dmaDevAddr;
    dma->sizeUnused = dma->size;
    func_80013A40(dmaDevAddr, dma->ramAddr, dma->size, medium);
    *dmaIndexRef = dmaIndex;
    return (devAddr - dmaDevAddr) + dma->ramAddr;
}


extern u8 D_8011EBF0[];
extern void *GbApu_Alloc(u8 *, s32);
extern void *func_80010448(void *, s32);
extern s32 func_800103C8(s32, s32);
// Same code as Ocarina of Time AudioLoad_InitSampleDmaBuffers (src/code/audio_load.c).
void func_80013EF8(s32 numNotes) {
    SampleDma *dma;
    s32 i;
    s32 t2;
    s32 j;

    gAudioContext.sampleDmaBufSize = gAudioContext.sampleDmaBufSize1;
    gAudioContext.sampleDmas =
        GbApu_Alloc(D_8011EBF0, 4 * gAudioContext.numNotes * sizeof(SampleDma) * gAudioContext.specUnk4);
    t2 = 3 * gAudioContext.numNotes * gAudioContext.specUnk4;
    for (i = 0; i < t2; i++) {
        dma = &gAudioContext.sampleDmas[gAudioContext.sampleDmaCount];
        dma->ramAddr = func_80010448(D_8011EBF0, gAudioContext.sampleDmaBufSize);
        if (dma->ramAddr == NULL) {
            break;
        } else {
            func_800103C8((s32)dma->ramAddr, gAudioContext.sampleDmaBufSize);
            dma->size = gAudioContext.sampleDmaBufSize;
            dma->devAddr = 0;
            dma->sizeUnused = 0;
            dma->unused = 0;
            dma->ttl = 0;
            gAudioContext.sampleDmaCount++;
        }
    }

    for (i = 0; (u32)i < gAudioContext.sampleDmaCount; i++) {
        gAudioContext.sampleDmaReuseQueue1[i] = i;
        gAudioContext.sampleDmas[i].reuseIndex = i;
    }

    for (i = gAudioContext.sampleDmaCount; i < 0x100; i++) {
        gAudioContext.sampleDmaReuseQueue1[i] = 0;
    }

    gAudioContext.sampleDmaReuseQueue1RdPos = 0;
    gAudioContext.sampleDmaReuseQueue1WrPos = gAudioContext.sampleDmaCount;
    gAudioContext.sampleDmaListSize1 = gAudioContext.sampleDmaCount;
    gAudioContext.sampleDmaBufSize = gAudioContext.sampleDmaBufSize2;

    for (j = 0; j < gAudioContext.numNotes; j++) {
        dma = &gAudioContext.sampleDmas[gAudioContext.sampleDmaCount];
        dma->ramAddr = func_80010448(D_8011EBF0, gAudioContext.sampleDmaBufSize);
        if (dma->ramAddr == NULL) {
            break;
        } else {
            func_800103C8((s32)dma->ramAddr, gAudioContext.sampleDmaBufSize);
            dma->size = gAudioContext.sampleDmaBufSize;
            dma->devAddr = 0;
            dma->sizeUnused = 0;
            dma->unused = 0;
            dma->ttl = 0;
            gAudioContext.sampleDmaCount++;
        }
    }

    for (i = gAudioContext.sampleDmaListSize1; (u32)i < gAudioContext.sampleDmaCount; i++) {
        gAudioContext.sampleDmaReuseQueue2[i - gAudioContext.sampleDmaListSize1] = i;
        gAudioContext.sampleDmas[i].reuseIndex = i - gAudioContext.sampleDmaListSize1;
    }

    for (i = gAudioContext.sampleDmaCount; i < 0x100; i++) {
        gAudioContext.sampleDmaReuseQueue2[i] = gAudioContext.sampleDmaListSize1;
    }

    gAudioContext.sampleDmaReuseQueue2RdPos = 0;
    gAudioContext.sampleDmaReuseQueue2WrPos = gAudioContext.sampleDmaCount - gAudioContext.sampleDmaListSize1;
}

extern u8 D_8011F1F4;
extern s32 func_8001510C(s32, s32);
s32 func_80014190(s32 arg0) {
    if (arg0 == 0xFF) {
        return 1;
    }
    if (((u8 *)&D_8011F1F4)[arg0] >= 2) {
        return 1;
    }
    if (((u8 *)&D_8011F1F4)[func_8001510C(1, arg0)] >= 2) {
        return 1;
    }
    return 0;
}

extern u8 D_8011F258;
extern u8 D_8011F190;
extern s32 func_8001510C(s32 arg0, s32 arg1);
s32 func_80014208(s32 arg0) { if (arg0 == 0xFF) { return 1; } if (((u8 *)&D_8011F258)[arg0] >= 2) { return 1; } if (((u8 *)&D_8011F258)[func_8001510C(0, arg0)] >= 2) { return 1; } return 0; }

extern s32 func_8001510C(s32 arg0, s32 arg1);
s32 func_80014280(s32 arg0) { if (arg0 == 0xFF) { return 1; } if (((u8 *)&D_8011F190)[arg0] >= 2) { return 1; } if (((u8 *)&D_8011F190)[func_8001510C(2, arg0)] >= 2) { return 1; } return 0; }

extern u8 D_8011BE90[];
extern u8 *D_80121EDC[];
void func_800142F8(s32 arg0, s32 arg1) { if (arg0 != 0xFF) { u8 *ptr = D_8011BE90 + arg0; if (ptr[0x3364] != 5) ptr[0x3364] = arg1; } }

void func_80014328(s32 arg0, s32 arg1) { if (arg0 != 0xFF) { u8 *ptr = D_8011BE90 + arg0; if (ptr[0x33C8] != 5) ptr[0x33C8] = arg1; } }

extern void func_80012ED8(s32);
extern u8 D_8011BE90[];
void func_80014358(s32 arg0, s32 arg1)
{
  int new_var2;
  u8 *ptr;
  s32 value;
  u8 *new_var;
  new_var2 = 5;
  new_var = D_8011BE90 + arg0;
  if (arg0 != 0xFF)
  {
    ptr = new_var;
    value = ptr[0x3300];
    if (0, value != new_var2)
    {
      ptr[0x3300] = arg1;
      value = arg1 & 0xFF;
    }
    if ((value == new_var2) || (value == 2))
    {
      func_80012ED8(arg0);
    }
  }
}

void func_800143B8(s32 arg0, s32 arg1) { if (arg0 != 0xFF) { u8 *ptr = D_8011BE90 + arg0; if (ptr[0x3300] != 5) ptr[0x3300] = arg1; } }

void func_800143E8(void *arg0, s32 arg1, u16 arg2) { s32 i; u8 *entry; *(s32 *)((u8 *)arg0 + 4) = arg1; *(u16 *)((u8 *)arg0 + 2) = arg2; i = 0; while (i < *(s16 *)arg0) { entry = (u8 *)arg0 + i * 0x10; if (*(s32 *)(entry + 0x14) != 0 && *(s8 *)(entry + 0x18) == 2) { *(s32 *)(entry + 0x10) += arg1; } i++; } }

extern u8 D_8011BE90[];
extern s32 func_80014D64(s32);
s32 func_80014448(s32 arg0, void *arg1) { s32 index; s32 count; s32 value; s32 result; index = *(u16 *)(*(u8 **)(D_8011BE90 + 0x2BD0) + arg0 * 2); count = (*(u8 **)(D_8011BE90 + 0x2BD0))[index++]; value = 0xFF; if (count > 0) { do { value = (*(u8 **)(D_8011BE90 + 0x2BD0))[index++]; result = func_80014D64(value); --count; } while (count > 0); } *(s32 *)arg1 = value; return result; }

extern s32 func_80014448(s32, void *);
extern s32 func_80014BD4(s32);
void func_800144E4(s32 arg0, s32 arg1, s32 arg2, OSMesgQueue *arg3) {
    s32 temp[2];
    if (arg1 & 2) {
        func_80014448(arg0, &temp[0]);
    }
    if (arg1 & 1) {
        func_80014BD4(arg0);
    }
    if (arg2 != 0) {
        osSendMesg(arg3, (OSMesg)(arg2 << 24), 0);
    }
}

// Same code as Majora's Mask AudioLoad_SyncLoadSample (src/audio/lib/load.c).
extern s32 func_80012528(u32, s32, s32, s8, s32);
extern s32 D_8011EA58;
extern void func_80015570(s32, s32, s32, s32);
extern void func_8001544C(u32, u8 *, u32, s32);
s32 func_8001454C(Sample *arg0, s32 arg1) {
    s32 sample_addr;

    if (arg0->isRelocated == 1) {
        if (arg0->medium != 0) {
            sample_addr = func_80012528(arg0->size, arg1, (s32)arg0->sampleAddr, arg0->medium, 1);
            if (sample_addr == 0) {
                return -1;
            }

            if (arg0->medium == 1) {
                func_80015570((s32)arg0->sampleAddr, sample_addr, arg0->size, *(s16 *)(D_8011EA58 + 2));
            } else {
                func_8001544C((u32)arg0->sampleAddr, (u8 *)sample_addr, arg0->size, arg0->medium);
            }
            arg0->medium = 0;
            arg0->sampleAddr = (u8 *)sample_addr;
        }
    }
    //! @bug Missing return on the success path; callers ignore the value.
}

extern s32 func_8001A308(s32, s32);
extern s32 func_8001A3DC(s32, s32);
extern s32 func_8001454C(Sample *, s32);
s32 func_80014638(s32 arg0, s32 arg1, s32 arg2) { s32 *ptr; if (arg1 < 0x7F) { ptr = (s32 *)func_8001A308(arg0, arg1); if (ptr == NULL) return -1; if (((u8 *)ptr)[1] != 0) func_8001454C((Sample *)ptr[2], arg0); func_8001454C((Sample *)ptr[4], arg0); if (((u8 *)ptr)[2] != 0x7F) func_8001454C((Sample *)ptr[6], arg0); } else if (arg1 == 0x7F) { ptr = (s32 *)func_8001A3DC(arg0, arg2); if (ptr == NULL) return -1; func_8001454C((Sample *)ptr[1], arg0); return 0; } }

extern s32 func_80015684(s32, s32, s32, s32, s32);
void func_80014708(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (func_80015684(arg0, arg1, arg2, arg3, arg4) == 0) {
        osSendMesg((OSMesgQueue *)arg4, (OSMesg)-1, 0);
    }
}

extern void func_80014708(s32, s32, s32, s32, s32);
void func_80014740(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80014708(0, arg0, 0, arg2, arg3);
}

void func_80014784(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80014708(2, arg0, 0, arg2, arg3);
}

void func_800147C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80014708(1, arg0, 0, arg2, arg3);
}

extern u8 D_8011BE90[];
s32 func_8001480C(arg0, arg1) s32 arg0; s32 *arg1; { s32 offset; offset = ((u16 *)((struct { u8 pad[0x2BD0]; u8 *base; } *)D_8011BE90)->base)[arg0]; *arg1 = ((u8 *)offset)[(s32)((struct { u8 pad[0x2BD0]; u8 *base; } *)D_8011BE90)->base]; offset++; if (*arg1 == 0) { return 0; } return (s32)((struct { u8 pad[0x2BD0]; u8 *base; } *)D_8011BE90)->base + offset; }

extern void func_80014900(s32);
extern s32 func_8001244C();
extern void func_800142F8(s32 arg0, s32 arg1);
extern s32 func_8001510C(s32 arg0, s32 arg1);
extern u8 D_8011BE90[];
void func_80014850(s32 arg0) { s32 index; s32 count; s32 value; s32 result; index = *(u16 *)(*(u8 **)(D_8011BE90 + 0x2BD0) + arg0 * 2); count = (*(u8 **)(D_8011BE90 + 0x2BD0))[index++]; if (count > 0) { do { --count; value = (*(u8 **)(D_8011BE90 + 0x2BD0))[index++]; result = func_8001510C(1, value); if (func_8001244C(1, result) == 0) { func_80014900(result); func_800142F8(result, 0); } } while (count > 0); } }

// Same code as Majora's Mask AudioLoad_DiscardFont (src/audio/lib/load.c).
// The font cache starts at D_8011BE90 + 0x2ED0 (D_8011ED60): a persistent entry count followed by
// 0xC-byte entries with the font ID at 0x1E from the cache start, then two temporary entries whose
// IDs are at 0xF2 (D_8011EE52) and 0xFE (D_8011EE5E). Taking the cache address in a local, as Majora's
// Mask does, gives the per-access %hi/%lo loads; the relocations then name D_8011BE90 plus an offset.
extern void func_800101D8(s32);
void func_80014900(s32 arg0) {
    u32 i;
    u8 *pool = D_8011BE90 + 0x2ED0;
    u8 *persistent;

    if (arg0 == *(s16 *)(pool + 0xF2)) {
        *(s16 *)(pool + 0xF2) = -1;
    } else if (arg0 == *(s16 *)(pool + 0xFE)) {
        *(s16 *)(pool + 0xFE) = -1;
    }

    persistent = pool;
    for (i = 0; i < *(u32 *)persistent; i++) {
        if (arg0 == *(s16 *)(persistent + i * 0xC + 0x1E)) {
            *(s16 *)(persistent + i * 0xC + 0x1E) = -1;
        }
    }

    func_800101D8(arg0);
}

s32 func_8001519C(s32 arg0);
s32 func_8001519C(s32 arg0);
void func_800149A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v1;

    temp_v1 = func_8001519C(arg0) + (arg1 * 0x10);
    if ((*(s8 *)((u8 *)(temp_v1) + (0x18))) == 5) {
        switch (arg2) {                             /* irregular */
        case 0:
            (*(s32 *)((u8 *)(temp_v1) + (0x10))) = arg3;
            return;
        case 1:
            (*(s32 *)((u8 *)(temp_v1) + (0x14))) = arg3;
            break;
        }
    }
}

s32 func_80014A18(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 func_80014AA8();
    if (*(s32 *)(D_8011BE90 + 0x2D14) != 0) {
        return 0;
    }
    *(s32 *)(*(u8 **)(D_8011BE90 + (arg0 * 4) + 0x604C) + 0xDC) = 0;
    return func_80014AA8(arg0, arg1, arg2);
}

extern s32 func_80014AA8(s32, s32, s32);
s32 func_80014A5C(s32 arg0, s32 arg1, s32 arg2) {
    if (*(s32 *)(D_8011BE90 + 0x2D14) != 0) {
        return 0;
    }
    *(s32 *)(*(u8 **)(D_8011BE90 + (arg0 * 4) + 0x604C) + 0xDC) = arg2;
    return func_80014AA8(arg0, arg1, 0);
}

extern u8 D_8011BE90[];
extern void func_8001CA3C(void *);
extern void func_8001F7F0(void *);
/* Bitfield view of the slot byte at offset 0: bit 7 is set and bit 6 cleared
   when the slot becomes active (the 0x80/0xBF masks in this function). */
typedef struct { u32 unk_7 : 1; u32 unk_6 : 1; u32 unk_0 : 6; } unk_func_80014AA8;
s32 func_80014AA8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *obj;
    s32 index;
    s32 count;
    s32 value;
    s32 result;

    obj = *(u8 **)(D_8011BE90 + arg0 * 4 + 0x604C);
    func_8001CA3C(obj);
    value = 0xFF;
    index = *(u16 *)(*(u8 **)(D_8011BE90 + 0x2BD0) + arg1 * 2);
    count = (*(u8 **)(D_8011BE90 + 0x2BD0))[index++];
    if (count > 0) {
        do {
            value = (*(u8 **)(D_8011BE90 + 0x2BD0))[index++];
            func_80014D64(value);
            --count;
        } while (count > 0);
    }
    result = func_80014BD4(arg1);
    if (result == 0) {
        return 0;
    }
    func_8001F7F0(obj);
    obj[4] = arg1;
    if (value != 0xFF) {
        obj[5] = func_8001510C(1, value);
    } else {
        obj[5] = 0xFF;
    }
    *(s32 *)(obj + 0x18) = result;
    *(s32 *)(obj + 0x78) = result;
    ((unk_func_80014AA8 *)obj)->unk_7 = 1;
    obj[0x90] = 0;
    *(s16 *)(obj + 0x10) = 0;
    ((unk_func_80014AA8 *)obj)->unk_6 = 0;
    obj[7] = arg0;
}
extern s32 func_80014E68(s32, s32, void *);
extern s32 func_8001510C(s32, s32);
extern u8 D_8011F258;
s32 func_80014BD4(s32 arg0) {
    struct { s32 pad; s32 value[2]; } sp20;
    s32 index;
    index = func_8001510C(0, arg0);
    if (((u8 *)&D_8011F258)[index] == 1) {
        return 0;
    }
    return func_80014E68(0, arg0, &sp20.value[0]);
}

s32 func_80014C48(s32 arg0, s32 arg1, s32 arg2);

s32 func_80014C28(s32 arg0, s32 arg1) {
    return func_80014C48(arg0, arg1, 1);
}

/* mkdraft:func_80014C48 begin */
extern s32 func_80015148(s32, s32);

s32 func_80014C48(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;
    s32 base;
    s32 index;
    s8 mode;

    index = func_8001510C(2, arg0);
    base = func_8001519C(2);
    result = func_80015148(2, index);
    if (result != 0) {
        if (((u8 *)&D_8011F190)[index] != 1) {
            func_800143B8(index, 2);
        }
        *(s32 *)arg1 = 0;
        return result;
    }
    mode = *(s8 *)((u8 *)base + arg0 * 0x10 + 0x19);
    if (mode == 4 || arg2 == 1) {
        *(s32 *)arg1 = *(s8 *)((u8 *)base + arg0 * 0x10 + 0x18);
        return *(s32 *)((u8 *)base + index * 0x10 + 0x10);
    }
    result = func_80014E68(2, arg0, &arg2);
    if (result != 0) {
        *(s32 *)arg1 = 0;
        return result;
    }
    *(s32 *)arg1 = *(s8 *)((u8 *)base + arg0 * 0x10 + 0x18);
    return *(s32 *)((u8 *)base + index * 0x10 + 0x10);
}
/* mkdraft:func_80014C48 end */

// Same code as Majora's Mask AudioLoad_SyncLoadFont (src/audio/lib/load.c).
extern s32 func_8001510C(s32, s32);
extern s32 func_80014C48(s32, s32, s32);
extern s32 func_80014E68(s32, s32, void *);
extern void func_80016C78(s32, s32, SampleBankRelocInfo *, s32);
s32 func_80014D64(s32 arg0) {
    s32 fontData;
    s32 sampleBankId1;
    s32 sampleBankId2;
    s32 didAllocate;
    SampleBankRelocInfo sampleBankReloc;
    s32 realFontId = func_8001510C(1, arg0);

    if (D_8011BE90[0x3364 + realFontId] == 1) {
        return 0;
    }

    sampleBankId1 = (*(u8 **)(D_8011BE90 + 0x2BD8))[realFontId * 0x14 + 2];
    sampleBankId2 = (*(u8 **)(D_8011BE90 + 0x2BD8))[realFontId * 0x14 + 3];

    sampleBankReloc.sampleBankId1 = sampleBankId1;
    sampleBankReloc.sampleBankId2 = sampleBankId2;
    if (sampleBankReloc.sampleBankId1 != 0xFF) {
        sampleBankReloc.baseAddr1 = func_80014C48(sampleBankReloc.sampleBankId1, (s32)&sampleBankReloc.medium1, 0);
    } else {
        sampleBankReloc.baseAddr1 = 0;
    }

    if (sampleBankId2 != 0xFF) {
        sampleBankReloc.baseAddr2 = func_80014C48(sampleBankId2, (s32)&sampleBankReloc.medium2, 0);
    } else {
        sampleBankReloc.baseAddr2 = 0;
    }

    fontData = func_80014E68(1, arg0, &didAllocate);
    if (fontData == 0) {
        return 0;
    }
    if (didAllocate == 1) {
        func_80016C78(realFontId, fontData, &sampleBankReloc, 0);
    }

    return fontData;
}

// Same code as Majora's Mask AudioLoad_SyncLoad (src/audio/lib/load.c).
extern s32 func_800124A4(s32, s32, s32);
extern s32 func_80010ABC(s32, s32, s32, s32);
extern SoundFont *D_8011EA68;
extern s32 func_80015148(s32, s32);
extern s32 func_8001519C(s32);
extern void _bcopy(const void *, void *, s32);
s32 func_80014E68(s32 arg0, s32 arg1, void *arg2) {
    u32 size;
    AudioTable *table;
    s32 medium2;
    u32 medium;
    s32 load_status;
    u32 rom_addr;
    s32 cache_policy;
    s32 ram_addr;
    u32 real_id;
    s32 medium_unk = 1;

    real_id = func_8001510C(arg0, arg1);
    ram_addr = func_80015148(arg0, real_id);
    if (ram_addr != 0) {
        *(s32 *)arg2 = FALSE;
        load_status = 2;
    } else {
        table = (AudioTable *)func_8001519C(arg0);
        size = table->entries[real_id].size;
        size = (size + 0xF) & ~0xF;
        medium = table->entries[arg1].medium;
        cache_policy = table->entries[arg1].cachePolicy;
        rom_addr = table->entries[real_id].romAddr;
        switch (cache_policy) {
            case 0:
                ram_addr = func_800124A4(arg0, real_id, size);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                break;

            case 1:
                ram_addr = func_80010ABC(arg0, size, 1, real_id);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                break;

            case 2:
                ram_addr = func_80010ABC(arg0, size, 0, real_id);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                break;

            case 3:
            case 4:
                ram_addr = func_80010ABC(arg0, size, 2, real_id);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                break;
        }

        *(s32 *)arg2 = TRUE;

        medium2 = medium;
        if (medium == 5) {
            if (rom_addr == 0) {
                return 0;
            }

            if (arg0 == 1) {
                SoundFont *sound_font = &D_8011EA68[real_id];

                sound_font->numInstruments = ((u16 *)rom_addr)[0];
                sound_font->numDrums = ((u16 *)rom_addr)[1];
                sound_font->numSfx = ((u16 *)rom_addr)[2];
                rom_addr += 0x10;
                size -= 0x10;
            }

            _bcopy((void *)rom_addr, (void *)ram_addr, size);
        } else if (medium2 == medium_unk) {
            func_80015570(rom_addr, ram_addr, size, (s16)table->unkMediumParam);
        } else {
            func_8001544C(rom_addr, (u8 *)ram_addr, size, medium);
        }

        load_status = (cache_policy == 0) ? 5 : 2;
    }

    switch (arg0) {
        case 0:
            func_80014328(real_id, load_status);
            break;

        case 1:
            func_800142F8(real_id, load_status);
            break;

        case 2:
            func_80014358(real_id, load_status);
            break;

        default:
            break;
    }

    return ram_addr;
}

s32 func_8001519C(s32);
s32 func_8001510C(s32 arg0, s32 arg1) {
    u8 *temp_v1;
    temp_v1 = (u8 *)(u32)func_8001519C(arg0) + (arg1 << 4);
    if (*(s32 *)(temp_v1 + 0x14) == 0) {
        arg1 = *(s32 *)(temp_v1 + 0x10);
    }
    return arg1;
}

s32 func_80011250(s32, s32, s32);
s32 func_8001244C();
s32 func_80015148(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0_2 = func_8001244C();
    if (temp_v0_2 != 0) {
        return temp_v0_2;
    }
    temp_v0 = func_80011250(arg0, 2, arg1);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    return 0;
}

extern s32 D_8011EA50;
extern s32 D_8011EA54;
extern s32 D_8011EA58;
s32 func_8001519C(s32 arg0) {
    s32 result = 0;
    switch (arg0) {
    case 0: result = D_8011EA50; break;
    case 1: result = D_8011EA54; break;
    case 2: result = D_8011EA58; break;
    default: break;
    }
    return result;
}

// Same code as Majora's Mask AudioLoad_RelocateFont (src/audio/lib/load.c).
// Drums keep isRelocated at 0x2, their tuned sample at 0x4 and envelope at 0xC; instruments keep
// isRelocated, normalRangeLo and normalRangeHi at 0x0-0x2, envelope at 0x4 and tuned samples at
// 0x8, 0x10 and 0x18; sound effects are 8-byte tuned samples.
extern SoundFont *D_8011EA68;
void func_80016B38(Sample **, u32, SampleBankRelocInfo *);
void func_800151E0(s32 arg0, u32 *arg1, SampleBankRelocInfo *arg2) {
    void *sound_offset;
    u32 sound_list_offset;
    u8 *inst;
    u8 *drum;
    u8 *sound_effect;
    s32 i;
    s32 num_drums = D_8011EA68[arg0].numDrums;
    s32 num_instruments = D_8011EA68[arg0].numInstruments;
    s32 num_sfx = D_8011EA68[arg0].numSfx;
    u32 *font_data = arg1;

#define RELOC_TO_RAM(x) (void *)((u32)(x) + (u32)(arg1))

    sound_list_offset = font_data[0];

    if ((sound_list_offset != 0) && (num_drums != 0)) {
        font_data[0] = (u32)RELOC_TO_RAM(sound_list_offset);

        for (i = 0; i < num_drums; i++) {
            sound_offset = ((u8 **)font_data[0])[i];

            if (sound_offset == NULL) {
                continue;
            }
            sound_offset = RELOC_TO_RAM(sound_offset);
            ((u8 **)font_data[0])[i] = drum = sound_offset;

            if (drum[2]) {
                continue;
            }

            func_80016B38((Sample **)(drum + 4), (u32)arg1, arg2);

            sound_offset = *(void **)(drum + 0xC);
            *(void **)(drum + 0xC) = RELOC_TO_RAM(sound_offset);

            drum[2] = TRUE;
        }
    }

    sound_list_offset = font_data[1];

    if ((sound_list_offset != 0) && (num_sfx != 0)) {
        font_data[1] = (u32)RELOC_TO_RAM(sound_list_offset);

        for (i = 0; i < num_sfx; i++) {
            sound_offset = (u8 *)font_data[1] + i * 8;
            sound_effect = (u8 *)sound_offset;

            if ((sound_effect == NULL) || (*(Sample **)sound_effect == NULL)) {
                continue;
            }

            func_80016B38((Sample **)sound_effect, (u32)arg1, arg2);
        }
    }

    if (num_instruments > 126) {
        num_instruments = 126;
    }

    for (i = 2; i <= 2 + num_instruments - 1; i++) {
        if (font_data[i] != 0) {
            font_data[i] = (u32)RELOC_TO_RAM(font_data[i]);
            inst = (u8 *)font_data[i];

            if (!inst[0]) {
                if (inst[1] != 0) {
                    func_80016B38((Sample **)(inst + 8), (u32)arg1, arg2);
                }

                func_80016B38((Sample **)(inst + 0x10), (u32)arg1, arg2);

                if (inst[2] != 0x7F) {
                    func_80016B38((Sample **)(inst + 0x18), (u32)arg1, arg2);
                }

                sound_offset = *(void **)(inst + 4);
                *(void **)(inst + 4) = RELOC_TO_RAM(sound_offset);

                inst[0] = TRUE;
            }
        }
    }

#undef RELOC_TO_RAM

    D_8011EA68[arg0].drums = (void **)font_data[0];
    D_8011EA68[arg0].soundEffects = (void *)font_data[1];
    D_8011EA68[arg0].instruments = (void **)(&font_data[2]);
}

// Same code as Majora's Mask AudioLoad_SyncDma (src/audio/lib/load.c).
extern OSMesgQueue D_8011E808;
extern OSIoMesg D_8011E824;
extern void func_80019540(void *, s32);
extern s32 func_80015584(void *, s32, s32, s32, s32, s32, void *, s32, void *);
void func_8001544C(u32 arg0, u8 *arg1, u32 arg2, s32 arg3) {
    OSMesgQueue *msgQueue = &D_8011E808;
    OSIoMesg *ioMesg = &D_8011E824;

    arg2 = (arg2 + 0xF) & ~0xF;

    func_80019540(arg1, arg2);

    while (TRUE) {
        if (arg2 < 0x400) {
            break;
        }
        func_80015584(ioMesg, OS_MESG_PRI_HIGH, OS_READ, arg0, (s32)arg1, 0x400, msgQueue, arg3, "FastCopy");
        osRecvMesg(msgQueue, NULL, OS_MESG_BLOCK);
        arg2 -= 0x400;
        arg0 += 0x400;
        arg1 += 0x400;
    }

    if (arg2 != 0) {
        func_80015584(ioMesg, OS_MESG_PRI_HIGH, OS_READ, arg0, (s32)arg1, arg2, msgQueue, arg3, "FastCopy");
        osRecvMesg(msgQueue, NULL, OS_MESG_BLOCK);
    }
}

void func_80015570(s32 a0, s32 a1, s32 a2, s32 a3) {}

// Same code as Majora's Mask AudioLoad_Dma (src/audio/lib/load.c). D_8008FA70 is the DMA
// handler function pointer that func_80015A40 sets.
extern s32 D_8008FA70;
s32 func_80015584(void *arg0, s32 priority, s32 direction, s32 devAddr, s32 ramAddr, s32 size,
                  void *reqQueue, s32 medium, void *dmaFuncType) {
    OSIoMesg *mesg = arg0;
    OSPiHandle *handle;

    if (*(u32 *)(D_8011BE90 + 0x2D14) > 16) {
        return -1;
    }

    switch (medium) {
        case 2: // cartridge
            handle = *(OSPiHandle **)(D_8011BE90 + 0x2128);
            break;

        case 3: // disk drive
            handle = *(OSPiHandle **)(D_8011BE90 + 0x212C);
            break;

        default:
            return 0;
    }

    if (((u32)size % 0x10) != 0) {
        size = (size + 0xF) & ~0xF;
    }

    mesg->hdr.pri = priority;
    mesg->hdr.retQueue = reqQueue;
    mesg->dramAddr = (void *)ramAddr;
    mesg->devAddr = devAddr;
    mesg->size = size;
    handle->transferInfo.cmdType = 2;
    ((s32 (*)(OSPiHandle *, OSIoMesg *, s32))D_8008FA70)(handle, mesg, direction);
    return 0;
}

// Same code as Majora's Mask AudioLoad_Unused1 (src/audio/lib/load.c).
void func_8001565C(void) {
}

void func_80015664(s32 arg0, s32 arg1) { s32 value; func_80014E68(arg0, arg1, &value); }

// Same code as Majora's Mask AudioLoad_AsyncLoadInner (src/audio/lib/load.c).
// Load status bytes are indexed by real table index: sequences at D_8011F258, fonts at
// D_8011F1F4 and sample banks at D_8011F190. The completion message packs the caller's
// value, table type, real index and load status into bytes 3 to 0.
extern u8 D_8011F1F4;
extern u8 D_8011F190;
extern u8 D_8011F258;
extern SoundFont *D_8011EA68;
extern void *func_8001647C(s32, s32, s32, s32, s32, s32, s32, s32);
extern void *func_80016500(s32, s32, u32, s32, s32, s32, s32);
s32 func_80015684(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u32 size;
    AudioTable *table;
    s32 ram_addr;
    s32 medium;
    s8 cache_policy;
    u32 rom_addr;
    s32 load_status;
    SoundFont *sound_font;
    u32 real_id = func_8001510C(arg0, arg1);
    s32 pad;

    switch (arg0) {
        case 0:
            if ((&D_8011F258)[real_id] == 1) {
                return 0;
            }
            break;

        case 1:
            if ((&D_8011F1F4)[real_id] == 1) {
                return 0;
            }
            break;

        case 2:
            if ((&D_8011F190)[real_id] == 1) {
                return 0;
            }
            break;
    }

    ram_addr = func_80015148(arg0, real_id);
    if (ram_addr != 0) {
        load_status = 2;
        osSendMesg((OSMesgQueue *)arg4, (OSMesg)(arg3 << 24), OS_MESG_NOBLOCK);
    } else {
        table = (AudioTable *)func_8001519C(arg0);
        size = table->entries[real_id].size;
        size = (size + 0xF) & ~0xF;
        medium = table->entries[arg1].medium;
        cache_policy = table->entries[arg1].cachePolicy;
        rom_addr = table->entries[real_id].romAddr;
        load_status = 2;

        switch (cache_policy) {
            case 0:
                ram_addr = func_800124A4(arg0, real_id, size);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                load_status = 5;
                break;

            case 1:
                ram_addr = func_80010ABC(arg0, size, 1, real_id);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                break;

            case 2:
                ram_addr = func_80010ABC(arg0, size, 0, real_id);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                break;

            case 3:
            case 4:
                ram_addr = func_80010ABC(arg0, size, 2, real_id);
                if (ram_addr == 0) {
                    return ram_addr;
                }
                break;
        }

        if (medium == 5) {
            if (rom_addr == 0) {
                return 0;
            }

            if (arg0 == 1) {
                sound_font = &D_8011EA68[real_id];

                sound_font->numInstruments = ((u16 *)rom_addr)[0];
                sound_font->numDrums = ((u16 *)rom_addr)[1];
                sound_font->numSfx = ((u16 *)rom_addr)[2];
                rom_addr += 0x10;
                size += -0x10;
            }
        }

        if (medium == 1) {
            func_8001647C((s16)table->unkMediumParam, rom_addr, ram_addr, size, medium, arg2, arg4,
                          (arg3 << 24) | (arg0 << 16) | (real_id << 8) | load_status);
        } else {
            func_80016500(rom_addr, ram_addr, size, medium, arg2, arg4,
                          (arg3 << 24) | (arg0 << 16) | (real_id << 8) | load_status);
        }

        load_status = 1;
    }

    switch (arg0) {
        case 0:
            func_80014328(real_id, load_status);
            break;

        case 1:
            func_800142F8(real_id, load_status);
            break;

        case 2:
            func_80014358(real_id, load_status);
            break;

        default:
            break;
    }

    return ram_addr;
}

extern void func_80016148(s32);
extern s32 func_80017070(s32);
extern void func_80016624(s32);
void func_80015A10(s32 arg0) { func_80016148(arg0); func_80017070(arg0); func_80016624(arg0); }

extern s32 D_8008FA70; void func_80015A40(s32 value) { D_8008FA70 = value; }

extern s32 D_8008FA74; void func_80015A4C(s32 value) { D_8008FA74 = value; }

// Ocarina of Time AudioLoad_InitSoundFontMeta.
void func_80015A58(s32 fontId) {
    SoundFont *font = &gAudioContext.soundFonts[fontId];
    AudioTableEntry *entry = &gAudioContext.soundFontTable->entries[fontId];

    font->sampleBankId1 = (entry->shortData1 >> 8) & 0xFF;
    font->sampleBankId2 = (entry->shortData1) & 0xFF;
    font->numInstruments = (entry->shortData2 >> 8) & 0xFF;
    font->numDrums = entry->shortData2 & 0xFF;
    font->numSfx = entry->shortData3;
}

// Close to Majora's Mask AudioLoad_Init (src/audio/lib/load.c); GS creates the
// external-load (D_8011DFC0) and preload-sample (D_8011E058) queues with 32 messages
// instead of 16. The custom update function pointer (D_80122A20) is the one func_80017B00 calls.
extern void *D_80122A20;
extern void *D_80122A28;
extern void *D_80122A2C;
extern s32 osTvType;
extern OSMesg D_8011E820;
extern OSMesg D_8011E108[];
extern OSMesg D_8011DFD8[];
extern OSMesgQueue D_8011DFC0;
extern OSMesgQueue D_8011E058;
extern OSMesg D_8011E070[];
extern u8 D_800D2D80[];
// Heap sizes read by func_80015AB8; Majora's Mask calls this gAudioHeapInitSizes.
typedef struct AudioHeapInitSizes {
    /* 0x0 */ s32 heapSize;
    /* 0x4 */ s32 initPoolSize;
    /* 0x8 */ s32 permanentPoolSize;
} AudioHeapInitSizes; // size = 0xC
extern AudioHeapInitSizes D_800A42A4;
extern u8 D_8011EBE0[];
extern u8 D_8011EF80[];
extern u8 D_80086420[];
extern u8 D_80085D60[];
extern u8 D_80086330[];
extern u8 D_80086CC0[];
extern u8 D_14D6660[];
extern u8 D_4AD450[];
extern u8 D_50F7E0[];
extern s32 D_8008FA78;
extern void func_8001951C(void);
extern void func_800107CC(s32);
extern void *func_80010510(u8 *, s32);
extern s32 func_80011B78(void);
extern void *GbApu_Alloc(u8 *, s32);
extern void GbApu_InitAllocator(s32 *, s32, s32);
extern void func_80015A58(s32);
void func_80015AB8(void *heap, s32 heapSize) {
    s32 pad1[9];
    s32 numFonts;
    s32 pad2[2];
    u8 *audioCtxPtr;
    void *addr;
    s32 i;
    s32 j;

    D_80122A20 = NULL;
    D_80122A28 = NULL;
    D_80122A2C = NULL;

    for (i = 0; i < 4; i++) {
        ((void **)(D_8011BE90 + 0x2D18))[i] = NULL;
    }

    *(s32 *)(D_8011BE90 + 0x2D14) = 0;
    D_8011BE90[0x2D28] = FALSE;

    audioCtxPtr = D_8011BE90;
    for (j = 0x6B90; j >= 0; j--) {
        *audioCtxPtr++ = 0;
    }

    switch (osTvType) {
        case OS_TV_PAL:
            *(f32 *)(D_8011BE90 + 0x2CF0) = 20.03042f;
            *(s32 *)(D_8011BE90 + 0x2CF4) = 50;
            break;

        case OS_TV_MPAL:
            *(f32 *)(D_8011BE90 + 0x2CF0) = 16.546f;
            *(s32 *)(D_8011BE90 + 0x2CF4) = 60;
            break;

        case OS_TV_NTSC:
        default:
            *(f32 *)(D_8011BE90 + 0x2CF0) = 16.713f;
            *(s32 *)(D_8011BE90 + 0x2CF4) = 60;
            break;
    }

    func_8001951C();

    for (i = 0; i < 3; i++) {
        ((s16 *)(D_8011BE90 + 0x2D04))[i] = 160;
    }

    *(s32 *)(D_8011BE90 + 0x2C30) = 0;
    *(s32 *)(D_8011BE90 + 0x2C38) = 0;
    *(s32 *)(D_8011BE90 + 0x2C3C) = 0;
    D_8011BE90[0x2C2E] = 0;
    *(void **)(D_8011BE90 + 0x2C4C) = NULL;
    *(s32 *)(D_8011BE90 + 0x2C84) = 0;
    *(s32 *)(D_8011BE90 + 0x2CD4) = 0;

    osCreateMesgQueue(&D_8011E808, &D_8011E820, 1);
    osCreateMesgQueue((OSMesgQueue *)D_8011E0F0, D_8011E108, 64);
    osCreateMesgQueue(&D_8011DFC0, D_8011DFD8, 32);
    osCreateMesgQueue(&D_8011E058, D_8011E070, 32);
    *(s32 *)(D_8011BE90 + 0x2C34) = 0;
    *(s32 *)(D_8011BE90 + 0x29B0) = 0;
    *(OSPiHandle **)(D_8011BE90 + 0x2128) = osCartRomInit();

    if (heap == NULL) {
        *(u8 **)(D_8011BE90 + 0x3460) = D_800D2D80;
        *(s32 *)(D_8011BE90 + 0x3464) = D_800A42A4.heapSize;
    } else {
        void **hp = &heap;

        *(void **)(D_8011BE90 + 0x3460) = *hp;
        *(s32 *)(D_8011BE90 + 0x3464) = heapSize;
    }

    for (i = 0; i < (*(s32 *)(D_8011BE90 + 0x3464) / (s32)sizeof(u64)); i++) {
        (*(u64 **)(D_8011BE90 + 0x3460))[i] = 0;
    }

    func_800107CC(D_800A42A4.initPoolSize);

    for (i = 0; i < 3; i++) {
        ((void **)(D_8011BE90 + 0x2CF8))[i] = func_80010510(D_8011EBE0, 1344 * sizeof(s16));
    }

    *(u8 **)(D_8011BE90 + 0x2BC0) = D_80086420;
    *(u8 **)(D_8011BE90 + 0x2BC4) = D_80085D60;
    *(u8 **)(D_8011BE90 + 0x2BC8) = D_80086330;
    *(u8 **)(D_8011BE90 + 0x2BD0) = D_80086CC0;

    *(s16 *)(D_8011BE90 + 0x2BD4) = **(s16 **)(D_8011BE90 + 0x2BC0);

    D_8011BE90[0x3455] = 0;
    D_8011BE90[0x3454] = 1;
    func_80011B78();

    func_800143E8(*(void **)(D_8011BE90 + 0x2BC0), (s32)D_14D6660, 0);
    func_800143E8(*(void **)(D_8011BE90 + 0x2BC4), (s32)D_4AD450, 0);
    func_800143E8(*(void **)(D_8011BE90 + 0x2BC8), (s32)D_50F7E0, 0);

    numFonts = **(s16 **)(D_8011BE90 + 0x2BC4);
    *(void **)(D_8011BE90 + 0x2BD8) = GbApu_Alloc(D_8011EBE0, numFonts * sizeof(SoundFont));

    for (i = 0; i < numFonts; i++) {
        func_80015A58(i);
    }

    if (addr = GbApu_Alloc(D_8011EBE0, D_800A42A4.permanentPoolSize), addr == NULL) {
        D_800A42A4.permanentPoolSize = 0;
    }

    GbApu_InitAllocator((s32 *)D_8011EF80, (s32)addr, D_800A42A4.permanentPoolSize);
    D_8008FA78 = TRUE;
    osSendMesg(*(OSMesgQueue **)(D_8011BE90 + 0x6328), (OSMesg) * (s32 *)(D_8011BE90 + 0x2C30), OS_MESG_NOBLOCK);
}

extern u8 D_8011BE90[]; void func_80015E58(void) { *(s32 *)(D_8011BE90 + 0x2074) = 0; *(s32 *)(D_8011BE90 + 0x20D8) = 0; }

typedef struct F15E6CEntry { u32 flags; s32 address; u32 unk8; u32 unkC; } F15E6CEntry;
typedef struct F15E6CSlot { u8 type; u8 id; s16 index; s32 field4; s32 source; s32 buffer; s32 current; s32 state; u32 size; u8 *status; F15E6CEntry data; u8 padding[0x34]; } F15E6CSlot;
extern s32 func_80012528(u32, s32, s32, s8, s32);
extern s32 func_8001603C(s32 arg0, s32 arg1);
extern u8 D_8011BE90[];
s32 func_80015E6C(s32 arg0, s32 arg1, u8 *arg2) {
    F15E6CEntry *entry;
    F15E6CSlot *slot;
    entry = (F15E6CEntry *)func_8001603C(arg0, arg1);
    if (entry == 0) {
        *arg2 = 0;
        return -1;
    }
    if (((entry->flags << 4) >> 30) == 0) {
        *arg2 = 2;
        return 0;
    }
    slot = (F15E6CSlot *)&D_8011BE90[*(s32 *)(D_8011BE90 + 0x205C) * 0x64 + 0x2060];
    if (slot->state == 3) {
        slot->state = 0;
    }
    slot->data = *entry;
    slot->status = arg2;
    slot->buffer = func_80012528(entry->flags & 0xFFFFFF, arg0, entry->address, (s8)((entry->flags << 4) >> 30), 0);
    if (slot->buffer == 0) {
        if (((entry->flags << 4) >> 30) == 1 || ((entry->flags << 1) >> 29) == 2) {
            *arg2 = 0;
            return -1;
        }
        *arg2 = 3;
        return -1;
    }
    slot->state = 1;
    slot->size = ((entry->flags & 0xFFFFFF) + 0xF) & ~0xF;
    slot->current = slot->buffer;
    slot->source = entry->address;
    slot->type = (entry->flags << 4) >> 30;
    slot->id = arg0;
    slot->index = arg1;
    if (slot->type == 1) {
        slot->field4 = *(s16 *)(*(u8 **)(D_8011BE90 + 0x2BC8) + 2);
    }
    *(s32 *)(D_8011BE90 + 0x205C) ^= 1;
    return 0;
}

s32 func_8001603C(s32 arg0, s32 arg1) { s32 *ptr; s32 value; if (arg1 < 0x80) { ptr = func_8001A308(arg0, arg1); if (ptr == NULL) return 0; value = ptr[4]; goto done; } if (arg1 < 0x100) { ptr = func_8001A3DC(arg0, arg1 - 0x80); if (ptr == NULL) return 0; value = ptr[1]; goto done; } ptr = func_8001A4C0(arg0, arg1 - 0x100); if (ptr == NULL) return 0; value = ptr[0]; done: return value; }
void func_8001603C_padding(void) {}

/* mkdraft:func_800160D4 begin */
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } unk_func_800160D4;

void func_800160D4(u8 *arg0) {
    u8 *result;

    if (*(s32 *)(arg0 + 0x24) == 0) {
        return;
    }
    result = (u8 *)func_8001603C(arg0[1], *(u16 *)(arg0 + 2));
    if (result != 0) {
        *(unk_func_800160D4 *)(arg0 + 0x20) = *(unk_func_800160D4 *)result;
        *(s32 *)(result + 4) = *(s32 *)(arg0 + 0x10);
        result[0] &= ~0xC;
    }
}
/* mkdraft:func_800160D4 end */

// Same code as Majora's Mask AudioLoad_ProcessSlowLoads (src/audio/lib/load.c).
// Each of the two 0x64-byte slow-load slots at D_8011BE90 + 0x2060 holds a status word at 0x14.
void func_800160D4(u8 *);
void GbApu_InitSlowCopySlot(u8 *, s32);
void func_80016354(s32, s32, s32, s32);
void func_80016148(s32 arg0) {
    u8 *slow_load;
    s32 i;

    for (i = 0; i < 2; i++) {
        slow_load = D_8011BE90 + 0x2060 + i * 0x64;
        switch (*(s32 *)(D_8011BE90 + 0x2060 + i * 0x64 + 0x14)) {
            case 2:
                if (slow_load[0] != 1) {
                    osRecvMesg((OSMesgQueue *)(slow_load + 0x30), NULL, OS_MESG_BLOCK);
                }

                if (arg0 != 0) {
                    *(s32 *)(slow_load + 0x14) = 3;
                    continue;
                }
                // fallthrough
            case 1:
                *(s32 *)(slow_load + 0x14) = 2;
                if (*(s32 *)(slow_load + 0x18) == 0) {
                    func_800160D4(slow_load);
                    *(s32 *)(slow_load + 0x14) = 3;
                    **(s8 **)(slow_load + 0x1C) = 1;
                } else if (*(s32 *)(slow_load + 0x18) < 0x400) {
                    if (slow_load[0] == 1) {
                        s32 size = *(s32 *)(slow_load + 0x18);

                        func_80016354(*(s32 *)(slow_load + 8), *(s32 *)(slow_load + 0xC), size,
                                      *(s32 *)(slow_load + 4));
                    } else {
                        GbApu_InitSlowCopySlot(slow_load, *(s32 *)(slow_load + 0x18));
                    }
                    *(s32 *)(slow_load + 0x18) = 0;
                } else {
                    if (slow_load[0] == 1) {
                        func_80016354(*(s32 *)(slow_load + 8), *(s32 *)(slow_load + 0xC), 0x400,
                                      *(s32 *)(slow_load + 4));
                    } else {
                        GbApu_InitSlowCopySlot(slow_load, 0x400);
                    }
                    *(s32 *)(slow_load + 0x18) -= 0x400;
                    *(s32 *)(slow_load + 0xC) += 0x400;
                    *(s32 *)(slow_load + 8) += 0x400;
                }
                break;
        }
    }
}

extern void func_80019540(void *, s32);
extern s32 func_80015584(void *, s32, s32, s32, s32, s32, void *, s32, void *);
const char D_800A1DC4[9] = "SLOWCOPY";
void GbApu_InitSlowCopySlot(u8 *arg0, s32 arg1) {
    void *queue[1];
    func_80019540(*(void **)(arg0 + 0xC), arg1);
    queue[0] = arg0 + 0x30;
    osCreateMesgQueue(queue[0], arg0 + 0x48, 1);
    func_80015584(arg0 + 0x4C, 0, 0, *(s32 *)(arg0 + 8), *(s32 *)(arg0 + 0xC), arg1, queue[0], *(u8 *)(arg0), (void *)D_800A1DC4);
}
void func_80016354(s32 a0, s32 a1, s32 a2, s32 a3) {}



// Same code as Ocarina of Time AudioLoad_SlowLoadSeq (src/code/audio_load.c).
s32 func_80016368(s32 seqId, u8 *ramAddr, s8 *isDone) {
    AudioSlowLoad *slowLoad;
    AudioTable *seqTable;
    u32 size;

    seqId = func_8001510C(0, seqId);
    seqTable = (AudioTable *)func_8001519C(0);
    slowLoad = &gAudioContext.slowLoads[gAudioContext.slowLoadPos];
    if (slowLoad->status == 3) {
        slowLoad->status = 0;
    }

    slowLoad->sampleAddr = NULL;
    slowLoad->isDone = isDone;
    size = seqTable->entries[seqId].size;
    size = (size + 0xF) & ~0xF;
    slowLoad->curRamAddr = ramAddr;
    slowLoad->status = 1;
    slowLoad->bytesRemaining = size;
    slowLoad->ramAddr = ramAddr;
    slowLoad->curDevAddr = seqTable->entries[seqId].romAddr;
    slowLoad->medium = seqTable->entries[seqId].medium;
    slowLoad->seqOrFontId = seqId;

    if (slowLoad->medium == 1) {
        slowLoad->unkMediumParam = seqTable->unkMediumParam;
    }

    gAudioContext.slowLoadPos ^= 1;
    return 0;
}

/* mkdraft:GbApu_ResetSlotFlags begin */
extern u8 D_8011BE90[];

void GbApu_ResetSlotFlags(void) {
    s32 i;
    for (i = 0; i < 32; i++) {
        D_8011BE90[i * 0x58 + 0x14C0] = 0;
    }
}
/* mkdraft:GbApu_ResetSlotFlags end */

extern void *func_80016500(s32, s32, u32, s32, s32, s32, s32);
extern OSMesgQueue D_8011DE50;
void *func_8001647C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    void *temp_v0;
    void *sp2C;
    temp_v0 = func_80016500(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    if (temp_v0 == NULL) {
        return NULL;
    }
    sp2C = temp_v0;
    osSendMesg(&D_8011DE50, temp_v0, 0);
    (*(s32 *)((u8 *)sp2C + (0x18))) = arg0;
    return sp2C;
}

extern u8 D_8011C990[];
extern u8 D_8011BE90[];
void *func_80016500(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
u8 *slot,*p=D_8011BE90,*limit; do { limit=D_8011C990; if (*(s8 *)(p+0x14C0)==0) { slot=p+0x14C0; break; } p+=0x58; } while(p!=limit); if(p==D_8011C990) return NULL;
*(s8 *)(slot + 0) = 1;
*(s32 *)(slot + 8) = arg0;
*(s32 *)(slot + 4) = arg1;
*(s32 *)(slot + 0xC) = arg1;
*(s32 *)(slot + 0x10) = arg2;
if (arg4 == 0) *(s32 *)(slot + 0x14) = 0x1000;
else if (arg4 == 1) *(s32 *)(slot + 0x14) = arg2;
else { s32 n = (((s32)arg2 / arg4) + 0xFF) & ~0xFF; *(s32 *)(slot + 0x14) = n; if ((u32)n < 0x100) *(s32 *)(slot + 0x14) = 0x100; }
*(s32 *)(slot + 0x20) = arg5;
*(s8 *)(slot + 1) = 3;
*(s8 *)(slot + 2) = arg3;
*(s32 *)(slot + 0x1C) = arg6;
osCreateMesgQueue((OSMesgQueue *)(slot + 0x24), (OSMesg *)(slot + 0x3C), 1);
return slot;

}


void func_80016748(BackgroundCopyRequest *asyncLoad, s32 resetStatus);
void BackgroundCopy_ServiceRequest(BackgroundCopyRequest *job, s32 stop_after_receive);
// Ocarina of Time AudioLoad_ProcessAsyncLoads.
void func_80016624(s32 resetStatus) {
    BackgroundCopyRequest *asyncLoad;
    s32 i;

    if (gAudioContext.resetTimer == 1) {
        return;
    }

    if (gAudioContext.curUnkMediumLoad == NULL) {
        if (resetStatus != 0) {
            // Clear and ignore queue if resetting.
            do {
            } while (osRecvMesg(&gAudioContext.asyncLoadUnkMediumQueue, (OSMesg *)&asyncLoad, OS_MESG_NOBLOCK) != -1);
        } else if (osRecvMesg(&gAudioContext.asyncLoadUnkMediumQueue, (OSMesg *)&asyncLoad, OS_MESG_NOBLOCK) == -1) {
            gAudioContext.curUnkMediumLoad = NULL;
        } else {
            gAudioContext.curUnkMediumLoad = asyncLoad;
        }
    }

    if (gAudioContext.curUnkMediumLoad != NULL) {
        func_80016748(gAudioContext.curUnkMediumLoad, resetStatus);
    }

    for (i = 0; i < 32; i++) {
        if (gAudioContext.asyncLoads[i].active == 1) {
            asyncLoad = &gAudioContext.asyncLoads[i];
            if (asyncLoad->copy_type != 1) {
                BackgroundCopy_ServiceRequest(asyncLoad, resetStatus);
            }
        }
    }
}

void func_80016748(BackgroundCopyRequest *asyncLoad, s32 resetStatus) {}

// Same code as Majora's Mask AudioLoad_FinishAsyncLoad (src/audio/lib/load.c).
// arg0 is a background copy request (see BackgroundCopyRequest below): status byte at 0x0, RAM
// address at 0x4, completion message at 0x1C and completion queue at 0x20. The message packs the
// table type, real table index and load status into bytes 2 to 0.
extern void func_80014328(s32, s32);
extern void func_80014358(s32, s32);
extern s32 func_80014C28(s32, s32);
extern SoundFont *D_8011EA68;
extern void func_800142F8(s32, s32);
void func_80016754(u8 *async_load) {
    u32 ret_msg = *(u32 *)(async_load + 0x1C);
    u32 font_id;
    s32 pad;
    OSMesg done_msg;
    u32 sample_bank_id1;
    u32 sample_bank_id2;
    SampleBankRelocInfo sample_bank_reloc;

    if (1) {} // karodo: also in the Majora's Mask twin; removing it leaves 30 instructions different
    switch ((ret_msg >> 16) & 0xFF) {
        case 0:
            func_80014328((ret_msg >> 8) & 0xFF, ret_msg & 0xFF);
            break;

        case 2:
            func_80014358((ret_msg >> 8) & 0xFF, ret_msg & 0xFF);
            break;

        case 1:
            font_id = (ret_msg >> 8) & 0xFF;
            sample_bank_id1 = D_8011EA68[font_id].sampleBankId1;
            sample_bank_id2 = D_8011EA68[font_id].sampleBankId2;
            sample_bank_reloc.sampleBankId1 = sample_bank_id1;
            sample_bank_reloc.sampleBankId2 = sample_bank_id2;
            sample_bank_reloc.baseAddr1 =
                (sample_bank_id1 != 0xFF) ? func_80014C28(sample_bank_id1, (s32)&sample_bank_reloc.medium1) : 0;
            sample_bank_reloc.baseAddr2 =
                (sample_bank_id2 != 0xFF) ? func_80014C28(sample_bank_id2, (s32)&sample_bank_reloc.medium2) : 0;
            func_800142F8(font_id, ret_msg & 0xFF);
            func_80016C78(font_id, *(s32 *)(async_load + 4), &sample_bank_reloc, 1);
            break;

        default:
            break;
    }

    done_msg = (OSMesg) *(u32 *)(async_load + 0x1C);
    if (1) {} // karodo: also in the Majora's Mask twin; removing it leaves 10 instructions different
    async_load[0] = 0;
    osSendMesg(*(OSMesgQueue **)(async_load + 0x20), done_msg, OS_MESG_NOBLOCK);
}

typedef struct { u8 unknown[2]; s16 unknown_02; } BackgroundCopyHeader;
extern void func_80016AB4(BackgroundCopyRequest *, s32);
extern void func_80016A24(u8 *, s32);
extern void func_80016B24(s32, s32, s32, s32);
// Advances one queued copy after its startup delay and completion message.
void BackgroundCopy_ServiceRequest(BackgroundCopyRequest *job, s32 stop_after_receive) {
    BackgroundCopyHeader *header;
    u32 remaining;
    header = (BackgroundCopyHeader *)D_8011EA58;
    if (job->delay >= 2) {
        job->delay--;
        return;
    }
    if (job->delay == 1) {
        job->delay = 0;
    } else {
        if (stop_after_receive != 0) {
            osRecvMesg(&job->queue, NULL, OS_MESG_BLOCK);
            job->active = 0;
            return;
        }
        if (osRecvMesg(&job->queue, NULL, OS_MESG_NOBLOCK) == -1) {
            return;
        }
    }
    remaining = job->remaining;
    if (remaining == 0) {
        func_80016754(job);
        return;
    }
    if (remaining < job->chunk_size) {
        if (job->copy_type == 1) {
            func_80016B24(job->source, job->destination, remaining, header->unknown_02);
        } else if (job->copy_type == 5) {
            func_80016AB4(job, remaining);
        } else {
            func_80016A24((u8 *)job, remaining);
        }
        job->remaining = 0;
    } else {
        if (job->copy_type == 1) {
            func_80016B24(job->source, job->destination, job->chunk_size, header->unknown_02);
        } else if (job->copy_type == 5) {
            func_80016AB4(job, job->chunk_size);
        } else {
            func_80016A24((u8 *)job, job->chunk_size);
        }
        job->remaining -= job->chunk_size;
        job->source += job->chunk_size;
        job->destination += job->chunk_size;
    }
}

const char D_800A1DD0[8] = "BGCOPY";
extern s32 func_80015584(void *, s32, s32, s32, s32, s32, void *, s32, void *);
extern void func_80019540(void *arg0, s32 arg1);
void func_80016A24(u8 *arg0, s32 arg1) {
    void *queue[1];
    arg1 += 0xF;
    arg1 &= ~0xF;
    func_80019540(*(void **)(arg0 + 0xC), arg1);
    queue[0] = arg0 + 0x24;
    osCreateMesgQueue(queue[0], arg0 + 0x3C, 1);
    func_80015584(arg0 + 0x40, 0, 0, *(s32 *)(arg0 + 8), *(s32 *)(arg0 + 0xC), arg1, queue[0], *(s8 *)(arg0 + 2), (void *)D_800A1DD0);
}

void func_80016AB4(BackgroundCopyRequest *arg0, s32 arg1) {
    OSMesgQueue *queue[1]; // FAKE: a one-element array for the stack slot; as a plain local diff score 8

    arg1 += 0xF;
    arg1 &= ~0xF;
    func_80019540(arg0->destination, arg1);
    queue[0] = &arg0->queue;
    osCreateMesgQueue(queue[0], &arg0->message, 1);
    _bcopy((void *)arg0->source, (void *)arg0->destination, arg1);
    osSendMesg(queue[0], NULL, 0);
}

void func_80016B24(s32 a0, s32 a1, s32 a2, s32 a3) {}

// Same code as Majora's Mask AudioLoad_RelocateSample (src/audio/lib/load.c).
// arg0 points at a tuned sample whose first word is its Sample pointer.
void func_80016B38(Sample **arg0, u32 arg1, SampleBankRelocInfo *arg2) {
    Sample *sample;
    void *reloc;

    if ((u32)*arg0 <= 0x80000000) {
        sample = *arg0 = reloc = (void *)((u32)*arg0 + arg1);

        if ((sample->size != 0) && (sample->isRelocated != 1)) {
            sample->loop = reloc = (void *)((u32)sample->loop + arg1);
            sample->book = reloc = (void *)((u32)sample->book + arg1);

            switch (sample->medium) {
                case 0:
                    sample->sampleAddr = reloc = (void *)((u32)sample->sampleAddr + arg2->baseAddr1);
                    sample->medium = arg2->medium1;
                    break;

                case 1:
                    sample->sampleAddr = reloc = (void *)((u32)sample->sampleAddr + arg2->baseAddr2);
                    sample->medium = arg2->medium2;
                    break;

                case 2:
                case 3:
                    break;
            }

            sample->isRelocated = 1;

            if (sample->unk_bit26 && (sample->medium != 0)) {
                *(Sample **)(D_8011BE90 + 0x8B8 + *(s32 *)(D_8011BE90 + 0x14B8) * 4) = sample;
                (*(s32 *)(D_8011BE90 + 0x14B8))++;
            }
        }
    }
}

extern s32 D_800D1300;
extern void *func_80016500(s32, s32, u32, s32, s32, s32, s32);
extern OSMesgQueue D_8011E058;
// Same code as Ocarina of Time / Majora's Mask AudioLoad_RelocateFontAndPreloadSamples, including
// its two empty ifs on size and on the disk drive medium (3).
void func_80016C78(s32 fontId, s32 fontData, SampleBankRelocInfo *sampleBankReloc, s32 isAsync) {
    AudioPreloadReq *preload;
    AudioPreloadReq *topPreload;
    Sample *sample;
    s32 size;
    s32 nChunks;
    u8 *sampleRamAddr;
    s32 preloadInProgress;
    s32 i;

    preloadInProgress = FALSE;
    if (gAudioContext.preloadSampleStackTop != 0) {
        preloadInProgress = TRUE;
    } else {
        D_800D1300 = 0;
    }

    gAudioContext.numUsedSamples = 0;
    func_800151E0(fontId, (u32 *)fontData, sampleBankReloc);

    size = 0;
    for (i = 0; i < gAudioContext.numUsedSamples; i++) {
        size += (gAudioContext.usedSamples[i]->size + 0xF) & ~0xF;
    }
    if (size && size) {} // FAKE, as in OoT

    for (i = 0; i < gAudioContext.numUsedSamples; i++) {
        if (gAudioContext.preloadSampleStackTop == 120) {
            break;
        }

        sample = gAudioContext.usedSamples[i];
        sampleRamAddr = NULL;
        switch (isAsync) {
            case FALSE:
                if (sample->medium == sampleBankReloc->medium1) {
                    sampleRamAddr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId1,
                                                        (s32)sample->sampleAddr, sample->medium, 1);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    sampleRamAddr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId2,
                                                        (s32)sample->sampleAddr, sample->medium, 1);
                } else if (sample->medium == 3) {
                    sampleRamAddr = (u8 *)func_80012528(sample->size, 0xFE, (s32)sample->sampleAddr,
                                                        sample->medium, 1);
                }
                break;

            case TRUE:
                if (sample->medium == sampleBankReloc->medium1) {
                    sampleRamAddr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId1,
                                                        (s32)sample->sampleAddr, sample->medium, 0);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    sampleRamAddr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId2,
                                                        (s32)sample->sampleAddr, sample->medium, 0);
                } else if (sample->medium == 3) {
                    sampleRamAddr = (u8 *)func_80012528(sample->size, 0xFE, (s32)sample->sampleAddr,
                                                        sample->medium, 0);
                }
                break;
        }
        if (sampleRamAddr == NULL) {
            continue;
        }

        switch (isAsync) {
            case FALSE:
                if (sample->medium == 1) {
                    func_80015570((s32)sample->sampleAddr, (s32)sampleRamAddr, sample->size,
                                  gAudioContext.sampleBankTable->unkMediumParam);
                    sample->sampleAddr = sampleRamAddr;
                    sample->medium = 0;
                } else {
                    func_8001544C((u32)sample->sampleAddr, sampleRamAddr, sample->size, sample->medium);
                    sample->sampleAddr = sampleRamAddr;
                    sample->medium = 0;
                }
                if (sample->medium == 3) {} // FAKE, as in OoT
                break;

            case TRUE:
                preload = &gAudioContext.preloadSampleStack[gAudioContext.preloadSampleStackTop];
                preload->sample = sample;
                preload->ramAddr = sampleRamAddr;
                preload->encodedInfo = (gAudioContext.preloadSampleStackTop << 24) | 0xFFFFFF;
                preload->isFree = FALSE;
                preload->endAndMediumKey = (u32)sample->sampleAddr + sample->size + sample->medium;
                gAudioContext.preloadSampleStackTop++;
                break;
        }
    }
    gAudioContext.numUsedSamples = 0;

    if (gAudioContext.preloadSampleStackTop != 0 && !preloadInProgress) {
        topPreload = &gAudioContext.preloadSampleStack[gAudioContext.preloadSampleStackTop - 1];
        sample = topPreload->sample;
        nChunks = (sample->size >> 12) + 1;
        func_80016500((s32)sample->sampleAddr, (s32)topPreload->ramAddr, sample->size, sample->medium, nChunks,
                      (s32)&D_8011E058, topPreload->encodedInfo);
    }
}


// Same code as Ocarina of Time AudioLoad_ProcessSamplePreloads (src/code/audio_load.c), with the
// sample address and size cached in locals; GS's RAM medium is 0.
s32 func_80017070(s32 resetStatus) {
    Sample *sample;
    AudioPreloadReq *preload;
    u32 preloadIndex;
    u32 key;
    u32 nChunks;
    s32 pad;
    u32 size;
    u8 *sampleAddr;

    if (gAudioContext.preloadSampleStackTop > 0) {
        if (resetStatus != 0) {
            osRecvMesg(&gAudioContext.preloadSampleQueue, (OSMesg *)&preloadIndex,
                       OS_MESG_NOBLOCK);
            gAudioContext.preloadSampleStackTop = 0;
            return 0;
        }
        if (osRecvMesg(&gAudioContext.preloadSampleQueue, (OSMesg *)&preloadIndex,
                       OS_MESG_NOBLOCK) == -1) {
            return 0;
        }

        preloadIndex >>= 24;
        preload = &gAudioContext.preloadSampleStack[preloadIndex];

        if (preload->isFree == FALSE) {
            sample = preload->sample;
            key = (u32)sample->sampleAddr + sample->size + sample->medium;
            if (key == preload->endAndMediumKey) {
                sample->sampleAddr = preload->ramAddr;
                sample->medium = 0;
            }
            preload->isFree = TRUE;
        }

        for (;;) {
            if (gAudioContext.preloadSampleStackTop <= 0) {
                break;
            }
            preload = &gAudioContext.preloadSampleStack[gAudioContext.preloadSampleStackTop - 1];
            if (preload->isFree == TRUE) {
                gAudioContext.preloadSampleStackTop--;
                continue;
            }

            sample = preload->sample;
            sampleAddr = sample->sampleAddr;
            size = sample->size;
            nChunks = (size >> 12) + 1;
            key = (u32)sampleAddr + size + sample->medium;
            if (key != preload->endAndMediumKey) {
                preload->isFree = TRUE;
                gAudioContext.preloadSampleStackTop--;
            } else {
                size = sample->size;
                func_80016500((s32)sampleAddr, (s32)preload->ramAddr, size, sample->medium, nChunks,
                              (s32)&gAudioContext.preloadSampleQueue, preload->encodedInfo);
                break;
            }
        }
    }
    return 1;
}

s32 func_80017224(void *arg0, s32 arg1, void **arg2) {
    s32 i = 0;
    while (i < arg1) {
        if (*(s32 *)((u8 *)arg0 + 4) == *(s32 *)((u8 *)arg2[i] + 4)) {
            break;
        }
        i++;
    }
    if (i == arg1) {
        arg2[arg1] = arg0;
        arg1++;
    }
    return arg1;
}

// Same code as Majora's Mask AudioLoad_GetSamplesForFont (src/audio/lib/load.c).
extern SoundFont *D_8011EA68;
s32 func_8001726C(s32 arg0, void **arg1) {
    s32 i;
    s32 num_samples = 0;
    s32 num_drums = D_8011EA68[arg0].numDrums;
    s32 num_instruments = D_8011EA68[arg0].numInstruments;

    for (i = 0; i < num_drums; i++) {
        u8 *drum = (u8 *)func_8001A3DC(arg0, i);

        if (drum == NULL) {
            continue;
        }

        num_samples = func_80017224(*(void **)(drum + 4), num_samples, arg1);
    }

    for (i = 0; i < num_instruments; i++) {
        u8 *instrument = (u8 *)func_8001A308(arg0, i);

        if (instrument == NULL) {
            continue;
        }

        if (instrument[1] != 0) {
            num_samples = func_80017224(*(void **)(instrument + 8), num_samples, arg1);
        }

        if (instrument[2] != 0x7F) {
            num_samples = func_80017224(*(void **)(instrument + 0x18), num_samples, arg1);
        }

        num_samples = func_80017224(*(void **)(instrument + 0x10), num_samples, arg1);
    }

    return num_samples;
}

extern u8 D_8011BE90[];
void func_800173A0(void *arg0) {
    void *entry;
    u32 value;
    s32 count;
    entry = *((void **) arg0);
    value = *((u32 *) entry);
    count = 0xFFFFFF;
    if ((value & count) == 0) {
        return;
    }
    if (((s32) ((value << 5) << 1)) >= 0) {
        return;
    }
    if (((value << 4) >> 30) == 0) {
        return;
    }
    *((void **) ((D_8011BE90 + 0x8B8) + ((*((s32 *) (D_8011BE90 + 0x14B8))) * 4))) = entry;
    *((s32 *) (D_8011BE90 + 0x14B8)) = (*((s32 *) (D_8011BE90 + 0x14B8))) + 1;
}

// Instrument records returned by func_8001A308/func_8001A3DC/func_8001A4C0; names follow Majora's Mask.
typedef struct TunedSample {
    /* 0x00 */ Sample *sample;
    /* 0x04 */ f32 tuning;
} TunedSample; // size = 0x8

typedef struct Instrument {
    /* 0x00 */ u8 isRelocated;
    /* 0x01 */ u8 normalRangeLo;
    /* 0x02 */ u8 normalRangeHi;
    /* 0x03 */ u8 adsrDecayIndex;
    /* 0x04 */ void *envelope;
    /* 0x08 */ TunedSample lowPitchTunedSample;
    /* 0x10 */ TunedSample normalPitchTunedSample;
    /* 0x18 */ TunedSample highPitchTunedSample;
} Instrument; // size = 0x20

typedef struct Drum {
    /* 0x00 */ u8 adsrDecayIndex;
    /* 0x01 */ u8 pan;
    /* 0x02 */ u8 isRelocated;
    /* 0x04 */ TunedSample tunedSample;
    /* 0x0C */ void *envelope;
} Drum; // size = 0x10

typedef struct SoundEffect {
    /* 0x00 */ TunedSample tunedSample;
} SoundEffect; // size = 0x8

// Majora's Mask AudioLoad_PreloadSamplesForFont.
void func_800173F8(s32 fontId, s32 async, SampleBankRelocInfo *sampleBankReloc) {
    s32 numDrums;
    s32 numInstruments;
    s32 numSfx;
    Drum *drum;
    Instrument *instrument;
    SoundEffect *soundEffect;
    AudioPreloadReq *preload;
    AudioPreloadReq *topPreload;
    u8 *addr; //!bug: never initialized, so a sample on neither medium reuses the previous address
    s32 size;
    s32 i;
    Sample *sample;
    s32 preloadInProgress;
    s32 nChunks;

    preloadInProgress = FALSE;
    if (gAudioContext.preloadSampleStackTop != 0) {
        preloadInProgress = TRUE;
    }

    gAudioContext.numUsedSamples = 0;
    numDrums = gAudioContext.soundFonts[fontId].numDrums;
    numInstruments = gAudioContext.soundFonts[fontId].numInstruments;
    numSfx = gAudioContext.soundFonts[fontId].numSfx;

    for (i = 0; i < numInstruments; i++) {
        instrument = (Instrument *)func_8001A308(fontId, i);
        if (instrument != NULL) {
            if (instrument->normalRangeLo != 0) {
                func_800173A0(&instrument->lowPitchTunedSample);
            }
            if (instrument->normalRangeHi != 0x7F) {
                func_800173A0(&instrument->highPitchTunedSample);
            }
            func_800173A0(&instrument->normalPitchTunedSample);
        }
    }

    for (i = 0; i < numDrums; i++) {
        drum = (Drum *)func_8001A3DC(fontId, i);
        if (drum != NULL) {
            func_800173A0(&drum->tunedSample);
        }
    }

    for (i = 0; i < numSfx; i++) {
        soundEffect = (SoundEffect *)func_8001A4C0(fontId, i);
        if (soundEffect != NULL) {
            func_800173A0(&soundEffect->tunedSample);
        }
    }

    if (gAudioContext.numUsedSamples == 0) {
        return;
    }

    size = 0;
    for (i = 0; i < gAudioContext.numUsedSamples; i++) {
        size += (gAudioContext.usedSamples[i]->size + 0xF) & ~0xF;
    }
    if (size) {}

    for (i = 0; i < gAudioContext.numUsedSamples; i++) {
        if (gAudioContext.preloadSampleStackTop == 120) {
            break;
        }

        sample = gAudioContext.usedSamples[i];
        if (sample->medium == 0) {
            continue;
        }

        switch (async) {
            case FALSE:
                if (sample->medium == sampleBankReloc->medium1) {
                    addr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId1, (s32)sample->sampleAddr,
                                               sample->medium, 1);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    addr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId2, (s32)sample->sampleAddr,
                                               sample->medium, 1);
                }
                break;

            case TRUE:
                if (sample->medium == sampleBankReloc->medium1) {
                    addr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId1, (s32)sample->sampleAddr,
                                               sample->medium, 0);
                } else if (sample->medium == sampleBankReloc->medium2) {
                    addr = (u8 *)func_80012528(sample->size, sampleBankReloc->sampleBankId2, (s32)sample->sampleAddr,
                                               sample->medium, 0);
                }
                break;
        }
        if (addr == NULL) {
            continue;
        }

        switch (async) {
            case FALSE:
                if (sample->medium == 1) {
                    func_80015570((s32)sample->sampleAddr, (s32)addr, sample->size,
                                  gAudioContext.sampleBankTable->unkMediumParam);
                    sample->sampleAddr = addr;
                    sample->medium = 0;
                } else {
                    func_8001544C((u32)sample->sampleAddr, addr, sample->size, sample->medium);
                    sample->sampleAddr = addr;
                    sample->medium = 0;
                }
                break;

            case TRUE:
                preload = &gAudioContext.preloadSampleStack[gAudioContext.preloadSampleStackTop];
                preload->sample = sample;
                preload->ramAddr = addr;
                preload->encodedInfo = (gAudioContext.preloadSampleStackTop << 24) | 0xFFFFFF;
                preload->isFree = FALSE;
                preload->endAndMediumKey = (u32)sample->sampleAddr + sample->size + sample->medium;
                gAudioContext.preloadSampleStackTop++;
                break;
        }
    }
    gAudioContext.numUsedSamples = 0;

    if (gAudioContext.preloadSampleStackTop != 0 && !preloadInProgress) {
        topPreload = &gAudioContext.preloadSampleStack[gAudioContext.preloadSampleStackTop - 1];
        sample = topPreload->sample;
        nChunks = (sample->size >> 12) + 1;
        func_80016500((s32)sample->sampleAddr, (s32)topPreload->ramAddr, sample->size, sample->medium, nChunks,
                      (s32)&gAudioContext.preloadSampleQueue, topPreload->encodedInfo);
    }
}

// Same code as Majora's Mask AudioLoad_LoadPermanentSamples (src/audio/lib/load.c).
extern void func_800173F8(s32, s32, SampleBankRelocInfo *);
void func_80017874(void) {
    s32 pad;
    u32 font_id;
    AudioTable *sample_bank_table;
    s32 pad2;
    s32 i;

    sample_bank_table = (AudioTable *)func_8001519C(2);
    for (i = 0; i < *(s32 *)(D_8011BE90 + 0x30FC); i++) {
        SampleBankRelocInfo sample_bank_reloc;

        if (*(s16 *)(D_8011BE90 + 0x3108 + i * 0xC) == 1) {
            font_id = func_8001510C(1, *(s16 *)(D_8011BE90 + 0x310A + i * 0xC));
            sample_bank_reloc.sampleBankId1 = (*(SoundFont **)(D_8011BE90 + 0x2BD8))[font_id].sampleBankId1;
            sample_bank_reloc.sampleBankId2 = (*(SoundFont **)(D_8011BE90 + 0x2BD8))[font_id].sampleBankId2;

            if (sample_bank_reloc.sampleBankId1 != 0xFF) {
                sample_bank_reloc.sampleBankId1 = func_8001510C(2, sample_bank_reloc.sampleBankId1);
                sample_bank_reloc.medium1 = sample_bank_table->entries[sample_bank_reloc.sampleBankId1].medium;
            }

            if (sample_bank_reloc.sampleBankId2 != 0xFF) {
                sample_bank_reloc.sampleBankId2 = func_8001510C(2, sample_bank_reloc.sampleBankId2);
                sample_bank_reloc.medium2 = sample_bank_table->entries[sample_bank_reloc.sampleBankId2].medium;
            }
            func_800173F8(font_id, 0, &sample_bank_reloc);
        }
    }
}

void func_800179B4(void) {}
void func_800179B4_padding(void) {}
void func_800179B4_padding2(void) {}

// File data before func_800179CC's static, in retail order (rom.yaml .data window 0x90670).
s32 D_8008FA70 = (s32)osEPiStartDma;
s32 D_8008FA74 = 0;
s32 D_8008FA78 = 0;

// Same code as Majora's Mask AudioLoad_ScriptLoad (src/audio/lib/load.c).
// sLoadIndex is the slot index into D_800D1378 and the message value.
extern u8 D_800D1378;
extern OSMesgQueue D_800D1320;
void func_800179CC(s32 arg0, s32 arg1, s8 *arg2) {
    static u32 sLoadIndex = 0;

    ((s8 **)&D_800D1378)[sLoadIndex] = arg2;
    func_80014708(arg0, arg1, 0, sLoadIndex, &D_800D1320);
    sLoadIndex++;
    if (sLoadIndex == 16) {
        sLoadIndex = 0;
    }
}

extern OSMesgQueue D_800D1320;
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern u8 D_800D1378;
void func_80017A38(void) {
    struct { s32 pad; void *value[2]; } sp20;
    s8 *temp_v0;
    if (osRecvMesg(&D_800D1320, (OSMesg *)sp20.value, 0) != -1) {
        temp_v0 = *(s8 **)((u8 *)&D_800D1378 + (((u32)sp20.value[0] >> 0x18) * 4));
        if (temp_v0 != NULL) {
            *temp_v0 = 0;
        }
    }
}

extern OSMesgQueue D_800D1320; extern OSMesg D_800D1338[]; void func_80017A90(void){osCreateMesgQueue(&D_800D1320,D_800D1338,0x10);}

#endif
