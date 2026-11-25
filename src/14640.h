#ifndef _14640_H
#define _14640_H

#include "global.h"

// Sound font header, 0x14 bytes per font; func_80015A58 fills the counts and bank IDs from the
// font table at D_8011BE90 + 0x2BC4, and func_800151E0 stores the relocated list pointers.
// Field names follow the Majora's Mask SoundFont struct.
typedef struct SoundFont {
    /* 0x00 */ u8 numInstruments;
    /* 0x01 */ u8 numDrums;
    /* 0x02 */ u8 sampleBankId1;
    /* 0x03 */ u8 sampleBankId2;
    /* 0x04 */ u16 numSfx;
    /* 0x06 */ u8 unk_06[2];
    /* 0x08 */ void **instruments;
    /* 0x0C */ void **drums;
    /* 0x10 */ void *soundEffects;
} SoundFont; // size = 0x14

// Sample header; func_8001454C loads samples by it and func_80016B38 relocates its pointers.
// Bit positions are read from those functions' masks; names follow the Majora's Mask Sample struct.
typedef struct Sample {
    /* 0x00 */ u32 unk_0 : 1;
    /* 0x00 */ u32 codec : 3;
    /* 0x00 */ u32 medium : 2;
    /* 0x00 */ u32 unk_bit26 : 1;
    /* 0x00 */ u32 isRelocated : 1;
    /* 0x01 */ u32 size : 24;
    /* 0x04 */ u8 *sampleAddr;
    /* 0x08 */ void *loop;
    /* 0x0C */ void *book;
} Sample; // size = 0x10

// Audio table entry, 0x10 bytes each, following a 0x10-byte table header. func_80015A58
// reads the font table's entries; field names follow the Majora's Mask AudioTableEntry struct.
typedef struct AudioTableEntry {
    /* 0x00 */ u32 romAddr;
    /* 0x04 */ u32 size;
    /* 0x08 */ s8 medium;
    /* 0x09 */ s8 cachePolicy;
    /* 0x0A */ s16 shortData1;
    /* 0x0C */ s16 shortData2;
    /* 0x0E */ s16 shortData3;
} AudioTableEntry; // size = 0x10

// Audio table: a 0x10-byte header followed by AudioTableEntry records. func_8001454C reads
// unkMediumParam from the sample bank table at D_8011EA58; names follow Majora's Mask AudioTable.
typedef struct AudioTable {
    /* 0x00 */ s16 numEntries;
    /* 0x02 */ s16 unkMediumParam;
    /* 0x04 */ u32 romAddr;
    /* 0x08 */ u8 pad[8];
    /* 0x10 */ AudioTableEntry entries[1];
} AudioTable;

// Sample bank IDs, base addresses and media for one font; func_80014D64 and func_80016754
// fill it and pass it to func_80016C78, which relocates the font's samples against it.
// Field names follow the Majora's Mask SampleBankRelocInfo struct.
typedef struct SampleBankRelocInfo {
    /* 0x00 */ s32 sampleBankId1;
    /* 0x04 */ s32 sampleBankId2;
    /* 0x08 */ s32 baseAddr1;
    /* 0x0C */ s32 baseAddr2;
    /* 0x10 */ s32 medium1;
    /* 0x14 */ s32 medium2;
} SampleBankRelocInfo; // size = 0x18

// Sample preload request; a stack of them starts at D_8011BE90 + 0xAB8 and the stack top
// count is at D_8011BE90 + 0x14BC. Field names follow the Majora's Mask AudioPreloadReq struct.
typedef struct AudioPreloadReq {
    /* 0x00 */ u32 endAndMediumKey;
    /* 0x04 */ Sample *sample;
    /* 0x08 */ u8 *ramAddr;
    /* 0x0C */ u32 encodedInfo;
    /* 0x10 */ s32 isFree;
} AudioPreloadReq; // size = 0x14


#ifdef VERSION_US
typedef struct SampleDma {
    /* 0x00 */ u8 *ramAddr;
    /* 0x04 */ u32 devAddr;
    /* 0x08 */ u16 sizeUnused;
    /* 0x0A */ u16 size;
    /* 0x0C */ u8 unused;
    /* 0x0D */ u8 reuseIndex;
    /* 0x0E */ u8 ttl;
} SampleDma; // size = 0x10

// Leading part of a sequence player (the full layout is in src/1CDC0.c).
typedef struct SequencePlayer {
    /* 0x00 */ u8 unk_00[0x38];
    /* 0x38 */ u8 *channels[16];
} SequencePlayer;

typedef struct AudioSlowLoad {
    /* 0x00 */ u8 medium;
    /* 0x01 */ u8 seqOrFontId;
    /* 0x02 */ u16 instId;
    /* 0x04 */ s32 unkMediumParam;
    /* 0x08 */ s32 curDevAddr;
    /* 0x0C */ u8 *curRamAddr;
    /* 0x10 */ u8 *ramAddr;
    /* 0x14 */ s32 status;
    /* 0x18 */ s32 bytesRemaining;
    /* 0x1C */ s8 *isDone;
    /* 0x20 */ u32 sampleBits;
    /* 0x24 */ u8 *sampleAddr;
    /* 0x28 */ u8 unk_28[0x3C];
} AudioSlowLoad; // size = 0x64

// Audio thread command queued by func_800186B8: opcode, three argument bytes and a data word.
// func_80018ED4 reads channel commands through it.
typedef struct AudioCmd {
    /* 0x0 */ u8 op;
    /* 0x1 */ u8 arg0;
    /* 0x2 */ u8 arg1;
    /* 0x3 */ u8 arg2;
    union {
        /* 0x4 */ f32 asFloat;
        /* 0x4 */ s32 asInt;
        /* 0x4 */ u16 asUShort;
        /* 0x4 */ s8 asSbyte;
        /* 0x4 */ u8 asUbyte;
        /* 0x4 */ void *asPtr;
    } data;
} AudioCmd; // size = 0x8

// The audio context (Ocarina of Time / Majora's Mask gAudioContext). Only the fields the
// C functions in this file use are named; the rest of the file still reads it as the raw
// byte array D_8011BE90. linker_scripts/us/aliases.ld defines gAudioContext there.
// Initialized by func_80016500; queue and I/O request begin at 0x24 and 0x40.
typedef struct BackgroundCopyRequest {
    s8 active, delay, copy_type; u8 unknown_03;
    s32 destination_base, source, destination;
    s32 remaining;
    s32 chunk_size;
    u32 unknown_18, completion_message;
    OSMesgQueue *completion_queue;
    OSMesgQueue queue;
    OSMesg message;
    OSIoMesg request;
} BackgroundCopyRequest;

typedef struct AudioContext {
    /* 0x0000 */ u8 unk_0000[0x8B8];
    /* 0x08B8 */ Sample *usedSamples[128];
    /* 0x0AB8 */ AudioPreloadReq preloadSampleStack[128];
    /* 0x14B8 */ s32 numUsedSamples;
    /* 0x14BC */ s32 preloadSampleStackTop;
    /* 0x14C0 */ BackgroundCopyRequest asyncLoads[32];
    /* 0x1FC0 */ OSMesgQueue asyncLoadUnkMediumQueue;
    /* 0x1FD8 */ u8 unk_1FD8[0x2058 - 0x1FD8];
    /* 0x2058 */ BackgroundCopyRequest *curUnkMediumLoad;
    /* 0x205C */ s32 slowLoadPos;
    /* 0x2060 */ AudioSlowLoad slowLoads[2];
    /* 0x2128 */ u8 unk_2128[0x21C8 - 0x2128];
    /* 0x21C8 */ OSMesgQueue preloadSampleQueue;
    /* 0x21E0 */ u8 unk_21E0[0x29AC - 0x21E0];
    /* 0x29AC */ SampleDma *sampleDmas;
    /* 0x29B0 */ u32 sampleDmaCount;
    /* 0x29B4 */ u32 sampleDmaListSize1;
    /* 0x29B8 */ u8 unk_29B8[4];
    /* 0x29BC */ u8 sampleDmaReuseQueue1[0x100];
    /* 0x2ABC */ u8 sampleDmaReuseQueue2[0x100];
    /* 0x2BBC */ u8 sampleDmaReuseQueue1RdPos;
    /* 0x2BBD */ u8 sampleDmaReuseQueue2RdPos;
    /* 0x2BBE */ u8 sampleDmaReuseQueue1WrPos;
    /* 0x2BBF */ u8 sampleDmaReuseQueue2WrPos;
    /* 0x2BC0 */ AudioTable *sequenceTable;
    /* 0x2BC4 */ AudioTable *soundFontTable;
    /* 0x2BC8 */ AudioTable *sampleBankTable;
    /* 0x2BCC */ u8 unk_2BCC[4];
    /* 0x2BD0 */ u8 *sequenceFontTable;
    /* 0x2BD4 */ u16 numSequences;
    /* 0x2BD8 */ SoundFont *soundFonts;
    /* 0x2BDC */ s16 specUnk4;
    /* 0x2BDE */ u8 unk_2BDE[0x2BF0 - 0x2BDE];
    /* 0x2BF0 */ s16 numSequencePlayers;
    /* 0x2BF2 */ u8 unk_2BF2[0x2C08 - 0x2BF2];
    /* 0x2C08 */ s32 sampleDmaBufSize1;
    /* 0x2C0C */ s32 sampleDmaBufSize2;
    /* 0x2C10 */ u8 unk_2C10[0x2C20 - 0x2C10];
    /* 0x2C20 */ s32 sampleDmaBufSize;
    /* 0x2C24 */ u8 unk_2C24[4];
    /* 0x2C28 */ s32 numNotes;
    /* 0x2C2C */ u8 unk_2C2C[4];
    /* 0x2C30 */ s32 totalTaskCount;
    /* 0x2C34 */ s32 curAudioFrameDmaCount;
    /* 0x2C38 */ u8 unk_2C38[0x2D0C - 0x2C38];
    /* 0x2D0C */ s32 audioRandom;
    /* 0x2D10 */ u8 unk_2D10[4];
    /* 0x2D14 */ u32 resetTimer;
    /* 0x2D18 */ u8 unk_2D18[0x3468 - 0x2D18];
    /* 0x3468 */ u8 *notes; // Note array, 0x100 bytes per note
    /* 0x346C */ u8 unk_346C[0x604C - 0x346C];
    /* 0x604C */ SequencePlayer *seqPlayers[5];
    /* 0x6060 */ u8 unk_6060[0x6314 - 0x6060];
    /* 0x6314 */ u8 cmdWrPos;
    /* 0x6315 */ u8 cmdRdPos;
    /* 0x6316 */ u8 cmdQueueFinished;
    /* 0x6317 */ u8 unk_6317;
    /* 0x6318 */ u16 activeChannelMasks[10];
    /* 0x632C */ OSMesgQueue *cmdProcQueueP;
    /* 0x6330 */ u8 unk_6330[0x6390 - 0x6330];
    /* 0x6390 */ AudioCmd cmdBuf[0x100];
} AudioContext;

extern AudioContext gAudioContext;

// Audio-frame DMA request queued by func_80013A40 and started by func_80013A8C.
typedef struct AudioFrameDmaReq {
    /* 0x00 */ u32 devAddr;
    /* 0x04 */ u8 *ramAddr;
    /* 0x08 */ u32 size;
    /* 0x0C */ s32 medium;
} AudioFrameDmaReq; // size = 0x10

extern AudioFrameDmaReq D_800D13B8[64];

#endif

#endif
