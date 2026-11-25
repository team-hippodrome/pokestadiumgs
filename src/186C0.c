#include "global.h"
#include "14640.h"

// Audio thread update (Majora's Mask audio_thread.c order) onwards; split from 14640.c at
// func_80017AC0, which starts 16-aligned right after 14640.c's .data and .rodata end padding.

#ifdef VERSION_US
extern u8 D_8011BE90[];
extern u8 D_8011E0F0[];
extern u8 *D_80121EDC[];
extern OSMesgQueue D_8011DFC0;
extern void *D_80122A28;
extern void *D_80122A2C;
extern void func_8001068C(s32 arg0);
extern void func_80013210(); // no prototype here: the prototyped call compiles differently
extern void func_80013B54(void);
extern void func_800144E4(s32 arg0, s32 arg1, s32 arg2, OSMesgQueue *arg3);
extern s32 func_80014638(s32 arg0, s32 arg1, s32 arg2);
extern void func_80014740(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80014784(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800147C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_8001480C(); // K&R definition in 14640.c
extern void func_80014850(s32 arg0);
extern void func_800149A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_80014A18(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_80014A5C(s32 arg0, s32 arg1, s32 arg2);
extern void func_80015A10(s32 arg0);
extern void func_80017A38(void);
extern s32 func_80017B00(void);
extern void func_80013A8C(void);
extern u32 osSetIntMask(u32);
s32 func_80017AC0(void) {
    u32 sp1C;
    s32 temp_v0;
    temp_v0 = func_80017B00();
    sp1C = osSetIntMask(1U);
    func_80013A8C();
    osSetIntMask(sp1C);
    return temp_v0;
}

// Close to Ocarina of Time AudioThread_UpdateImpl (src/audio/internal/thread.c); GS counts
// frame DMAs as unsigned, calls func_8000C6D8 after the script loads, does not point
// gWaveSamples[8] into code, keeps the maximum command count at D_8011BE90 + 0x2D2C and gives
// the task a DRAM stack (D_8008FC90). Returns the RSP task to run this frame, or NULL; the
// task waiting for the last update of a multi-update frame is kept in D_8008FA80.
extern void *D_8008FA80;
extern void *D_80122A20;
extern u8 D_80000460[];
extern u64 D_80086EF0[];
extern u64 D_800871D0[];
extern u8 D_8008FC90[];
extern void func_8000C6D8(void);
extern s32 func_80011B78(void);
extern void func_800195C0(void *, s32);
extern void func_8001895C(u32);
extern s32 func_800187AC(void);
extern s32 func_8000CDB8(s32, s32 *, s16 *, s32);
s32 func_80017B00(void) {
    u32 samplesRemainingInAi;
    s32 abiCmdCnt;
    s32 pad;
    s32 j;
    u32 sp5C;
    s16 *curAiBuffer;
    OSTask_t *task;
    s32 index;
    u32 sp4C;
    u32 sp48;
    u32 i;

    (*(s32 *)(D_8011BE90 + 0x2C30))++;
    if ((*(s32 *)(D_8011BE90 + 0x2C30) % *(s16 *)(D_8011BE90 + 0x2BDC)) != 0) {
        if (D_80122A20 != NULL) {
            ((void (*)(void))D_80122A20)();
        }

        if (*(s16 *)(D_8011BE90 + 0x2BDC) ==
            ((*(s32 *)(D_8011BE90 + 0x2C30) % *(s16 *)(D_8011BE90 + 0x2BDC)) + 1)) {
            return (s32)D_8008FA80;
        } else {
            return (s32)NULL;
        }
    }

    osSendMesg(*(OSMesgQueue **)(D_8011BE90 + 0x6328), (OSMesg) * (s32 *)(D_8011BE90 + 0x2C30), OS_MESG_NOBLOCK);
    *(s32 *)(D_8011BE90 + 0x2C38) ^= 1;
    (*(s32 *)(D_8011BE90 + 0x2C3C))++;
    *(s32 *)(D_8011BE90 + 0x2C3C) %= 3;
    index = (*(s32 *)(D_8011BE90 + 0x2C3C) - 2 + 3) % 3;
    samplesRemainingInAi = osAiGetLength() / 4;

    if (*(volatile u32 *)(D_8011BE90 + 0x2D14) < 16) {
        if (((s16 *)(D_8011BE90 + 0x2D04))[index] != 0) {
            func_800195C0(((s16 **)(D_8011BE90 + 0x2CF8))[index], ((s16 *)(D_8011BE90 + 0x2D04))[index] * 4);
            if (((s16 **)(D_8011BE90 + 0x2CF8))[index]) {}
            if (((s16 *)(D_8011BE90 + 0x2D04))[index]) {}
        }
    }

    if (D_80122A20 != NULL) {
        ((void (*)(void))D_80122A20)();
    }

    sp5C = *(u32 *)(D_8011BE90 + 0x2C34);
    for (i = 0; i < *(u32 *)(D_8011BE90 + 0x2C34); i++) {
        if (osRecvMesg((OSMesgQueue *)D_8011E0F0, NULL, OS_MESG_NOBLOCK) == 0) {
            sp5C--;
        }
    }

    if (sp5C != 0) {
        for (i = 0; i < sp5C; i++) {
            osRecvMesg((OSMesgQueue *)D_8011E0F0, NULL, OS_MESG_BLOCK);
        }
    }

    sp48 = MQ_GET_COUNT((OSMesgQueue *)(D_8011BE90 + 0x2260));
    if (sp48 != 0) {
        for (i = 0; i < sp48; i++) {
            osRecvMesg((OSMesgQueue *)D_8011E0F0, NULL, OS_MESG_NOBLOCK);
        }
    }

    *(u32 *)(D_8011BE90 + 0x2C34) = 0;
    func_80013B54();
    func_80015A10(D_8011BE90[0x3454]);
    func_80017A38();
    func_8000C6D8();

    if (D_8011BE90[0x3454] != 0) {
        if (func_80011B78() == 0) {
            if (D_8011BE90[0x3454] == 0) {
                osSendMesg(*(OSMesgQueue **)(D_8011BE90 + 0x6324), (OSMesg)(u32)D_8011BE90[0x3455], OS_MESG_NOBLOCK);
            }

            D_8008FA80 = NULL;
            return (s32)NULL;
        }
    }

    if (*(volatile u32 *)(D_8011BE90 + 0x2D14) > 16) {
        return (s32)NULL;
    }
    if (*(volatile u32 *)(D_8011BE90 + 0x2D14) != 0) {
        (*(volatile u32 *)(D_8011BE90 + 0x2D14))++;
    }

    *(u8 **)(D_8011BE90 + 0x2C4C) = &D_8011BE90[*(s32 *)(D_8011BE90 + 0x2C38) * 0x50 + 0x2C50];
    *(s32 *)(D_8011BE90 + 0x2C48) = ((s32 *)(D_8011BE90 + 0x2C40))[*(s32 *)(D_8011BE90 + 0x2C38)];

    index = *(s32 *)(D_8011BE90 + 0x2C3C);
    curAiBuffer = ((s16 **)(D_8011BE90 + 0x2CF8))[index];

    ((s16 *)(D_8011BE90 + 0x2D04))[index] =
        (s16)((((*(s16 *)(D_8011BE90 + 0x2BE2) - samplesRemainingInAi) + 0x80) & ~0xF) + 0x10);
    if (((s16 *)(D_8011BE90 + 0x2D04))[index] < *(s16 *)(D_8011BE90 + 0x2BE6)) {
        ((s16 *)(D_8011BE90 + 0x2D04))[index] = *(s16 *)(D_8011BE90 + 0x2BE6);
    }

    if (((s16 *)(D_8011BE90 + 0x2D04))[index] > *(s16 *)(D_8011BE90 + 0x2BE4)) {
        ((s16 *)(D_8011BE90 + 0x2D04))[index] = *(s16 *)(D_8011BE90 + 0x2BE4);
    }

    j = 0;
    if (D_8011BE90[0x3454] == 0) {
        // The message packs the command ring's read and end positions.
        while (osRecvMesg(*(OSMesgQueue **)(D_8011BE90 + 0x632C), (OSMesg *)&sp4C, OS_MESG_NOBLOCK) != -1) {
            if (1) {}
            func_8001895C(sp4C);
            j++;
        }
        if ((j == 0) && (D_8011BE90[0x6316])) {
            func_800187AC();
        }
    }

    *(s32 *)(D_8011BE90 + 0x2C48) =
        func_8000CDB8(*(s32 *)(D_8011BE90 + 0x2C48), &abiCmdCnt, curAiBuffer, ((s16 *)(D_8011BE90 + 0x2D04))[index]);

    *(s32 *)(D_8011BE90 + 0x2D0C) = (*(s32 *)(D_8011BE90 + 0x2D0C) + *(s32 *)(D_8011BE90 + 0x2C30)) * osGetCount();
    *(s32 *)(D_8011BE90 + 0x2D0C) =
        *(s32 *)(D_8011BE90 + 0x2D0C) + ((s16 **)(D_8011BE90 + 0x2CF8))[index][*(s32 *)(D_8011BE90 + 0x2C30) & 0xFF];

    index = *(s32 *)(D_8011BE90 + 0x2C38);
    *(void **)(*(u8 **)(D_8011BE90 + 0x2C4C) + 0x40) = NULL;
    *(void **)(*(u8 **)(D_8011BE90 + 0x2C4C) + 0x44) = NULL;

    task = *(OSTask_t **)(D_8011BE90 + 0x2C4C);
    task->type = M_AUDTASK;
    task->flags = 0;
    task->ucode_boot = (u64 *)D_80000460;
    task->ucode_boot_size = 0x1000;
    task->ucode_data_size = (size_t)(D_800871D0 - D_80086EF0) * sizeof(u64) - 1;
    task->ucode = (u64 *)D_80000460;
    task->ucode_data = D_80086EF0;
    task->ucode_size = 0x1000;
    task->dram_stack = (u64 *)D_8008FC90;
    task->dram_stack_size = 0;
    task->output_buff = NULL;
    task->output_buff_size = NULL;
    if (1) {}
    task->data_ptr = (u64 *)((s32 *)(D_8011BE90 + 0x2C40))[index];
    task->data_size = abiCmdCnt * sizeof(Acmd);
    task->yield_data_ptr = NULL;
    task->yield_data_size = 0;

    if (*(s32 *)(D_8011BE90 + 0x2D2C) < abiCmdCnt) {
        *(s32 *)(D_8011BE90 + 0x2D2C) = abiCmdCnt;
    }

    if (*(s16 *)(D_8011BE90 + 0x2BDC) == 1) {
        return *(s32 *)(D_8011BE90 + 0x2C4C);
    } else {
        D_8008FA80 = *(void **)(D_8011BE90 + 0x2C4C);
        return (s32)NULL;
    }
}

extern void func_800185A8(s32, s32);
extern void func_800185E8(s32, s32);
extern s32 func_800193B8(s32);
extern f32 D_8008EB94[];
extern s16 D_8011EA80;
extern void func_8001F7A0(u8 *);
extern void func_8001CA14(u8 *);
extern s32 ResourceCatalog_SetEntry(s32, s32, s32, s32);
typedef struct { u32 enabled : 1; u32 finished : 1; u32 muted : 1; u32 seqDmaInProgress : 1; u32 fontDmaInProgress : 1; u32 recalculateVolume : 1; u32 stopScript : 1; u32 applyBend : 1; } F78Flags;
typedef struct { u32 pad : 8; u32 hi : 1; } FDBits;
void func_80018078(AudioCmd *cmd) {
    s32 i;
    u8 *note;
    u32 flags;
    u8 playerIndex;
    s32 arg;
    u8 *seqPlayer;
    u32 slot;

    playerIndex = cmd->arg0;
    if (!cmd) {} // FAKE
    seqPlayer = *(u8 **)(D_8011BE90 + 0x604C + playerIndex * 4);
    switch (cmd->op) {
        case 0x81:
            func_800144E4(cmd->arg1, cmd->arg2, cmd->data.asInt, &D_8011DFC0);
            break;
        case 0x82:
            func_80014A18(cmd->arg0, cmd->arg1, cmd->arg2);
            func_800185E8(cmd->arg0, cmd->data.asInt);
            break;
        case 0x85:
            func_80014A5C(cmd->arg0, cmd->arg1, cmd->data.asInt);
            func_8001F7A0(seqPlayer);
            break;
        case 0x83:
            if (((F78Flags *)seqPlayer)->enabled) {
                switch (cmd->data.asInt) {
                    case 0:
                        func_8001CA14(seqPlayer);
                        break;
                    default:
                        func_800185A8(cmd->arg0, cmd->data.asInt);
                        break;
                }
            }
            break;
        case 0xF0:
            *(u8 *)(D_8011BE90 + 0x2C2E) = cmd->data.asInt;
            break;
        case 0xF1:
            if (cmd->arg0 == 0xFF) {
                for (i = 0; i < *(s16 *)(D_8011BE90 + 0x2BF0); i++) {
                    ((F78Flags *)(D_8011BE90 + 0x346C + i * 0x160))->muted = 1;
                    ((F78Flags *)(D_8011BE90 + 0x346C + i * 0x160))->recalculateVolume = 1;
                }
            } else {
                ((F78Flags *)seqPlayer)->muted = 1;
                ((F78Flags *)seqPlayer)->recalculateVolume = 1;
            }
            break;
        case 0xF2:
            if (cmd->data.asInt == 1) {
                for (i = 0; i < *(s32 *)(D_8011BE90 + 0x2C28); i++) {
                    note = i * 0x100 + ((AudioContext *)D_8011BE90)->notes;
                    flags = (u32)(note + 0xD0);
                    if (((F78Flags *)flags)->enabled && note[0x34] == 0 &&
                        (*(u8 *)(*(u8 **)(*(u8 **)(note + 0x44) + 0x60) + 3) & 8) != 0) {
                        ((F78Flags *)flags)->muted = 1;
                    }
                }
            }
            if (cmd->arg0 == 0xFF) {
                for (i = 0; i < *(s16 *)(D_8011BE90 + 0x2BF0); i++) {
                    ((F78Flags *)(D_8011BE90 + 0x346C + i * 0x160))->muted = 0;
                    ((F78Flags *)(D_8011BE90 + 0x346C + i * 0x160))->recalculateVolume = 1;
                }
            } else {
                ((F78Flags *)seqPlayer)->muted = 0;
                ((F78Flags *)seqPlayer)->recalculateVolume = 1;
            }
            break;
        case 0xF3:
            func_80014638(cmd->arg0, cmd->arg1, cmd->arg2);
            break;
        case 0xF4:
            func_80014784(cmd->arg0, cmd->arg1, cmd->arg2, (s32)&D_8011DFC0);
            break;
        case 0xF5:
            func_800147C8(cmd->arg0, cmd->arg1, cmd->arg2, (s32)&D_8011DFC0);
            break;
        case 0xFC:
            func_80014740(cmd->arg0, cmd->arg1, cmd->arg2, (s32)&D_8011DFC0);
            break;
        case 0xF6:
            func_80014850(cmd->arg1);
            break;
        case 0x90:
            *(u16 *)(D_8011BE90 + 0x6318 + cmd->arg0 * 2) = cmd->data.asUShort;
            break;
        case 0xF9:
            *(u8 *)(D_8011BE90 + 0x3454) = 5;
            *(u8 *)(D_8011BE90 + 0x3455) = cmd->data.asInt;
            break;
        case 0xFA:
            if (cmd->data.asInt == 0) {
                *(s8 *)(*(u8 **)(D_8011BE90 + 0x60EC) + 0xD4) = -1;
            } else {
                *(u8 *)(*(u8 **)(D_8011BE90 + 0x60EC) + 0xD2) = cmd->arg1;
                *(u8 *)(*(u8 **)(D_8011BE90 + 0x60EC) + 0xD1) = cmd->arg0;
                *(u8 *)(*(u8 **)(D_8011BE90 + 0x60EC) + 0xD0) = cmd->arg2;
            }
            break;
        case 0xFD:
            flags = cmd->data.asInt + 0x80;
            *(f32 *)(*(u8 **)(D_8011BE90 + 0x60EC) + 0x3C) = D_8008EB94[flags];
            ((FDBits *)*(u8 **)(D_8011BE90 + 0x60EC))->hi = 1;
            flags = cmd->arg2;
            *(s16 *)(*(u8 **)(D_8011BE90 + 0x60EC) + 0x1A) = flags * 4;
            *(s16 *)(*(u8 **)(D_8011BE90 + 0x60EC) + 0x1E) = 0x20;
            break;
        case 0xFB:
            D_80122A20 = cmd->data.asPtr;
            break;
        case 0xE4:
            slot = cmd->arg2;
            if (slot == 0xFF) {
                D_80122A28 = cmd->data.asPtr;
            } else if (slot == 0xFE) {
                D_80122A2C = cmd->data.asPtr;
            } else {
                *(void **)(D_8011BE90 + 0x2D18 + cmd->arg2 * 4) = cmd->data.asPtr;
            }
            break;
        case 0xE0:
        case 0xE1:
        case 0xE2:
            if (ResourceCatalog_SetEntry(cmd->op - 0xE0, cmd->arg1, cmd->arg2, cmd->data.asInt) != 0) {
            }
            break;
        case 0xFE:
            arg = cmd->data.asInt;
            if (arg == 1) {
                for (i = 0; i < *(s16 *)(D_8011BE90 + 0x2BF0); i++) {
                    if (((F78Flags *)(D_8011BE90 + 0x346C + i * 0x160))->enabled) {
                        func_8001CA14(D_8011BE90 + 0x346C + i * 0x160);
                    }
                }
            }
            func_800193B8(arg);
            break;

        case 0xE3:
            func_8001068C(cmd->data.asInt);
            break;
        case 0xE5:
            func_800149A8(cmd->arg0, cmd->arg1, cmd->arg2, cmd->data.asInt);
            break;
        case 0xE6:
            func_80013210(cmd->arg1, cmd->arg0, cmd->data.asInt, 0);
            break;
    }
}

void func_800185A8(s32 arg0, s32 arg1) { u8 *ptr = D_80121EDC[arg0]; if (arg1 == 0) arg1 = 1; ptr[1] = 2; *(s16 *)(ptr + 0x12) = arg1; *(f32 *)(ptr + 0x20) = -(*(f32 *)(ptr + 0x1C) / (f32)arg1); }

void func_800185E8(s32 arg0, s32 arg1) { if (arg1 != 0) { u8 *ptr = D_80121EDC[arg0]; ptr[1] = 1; *(s16 *)(ptr + 0x14) = arg1; *(s16 *)(ptr + 0x12) = arg1; *(f32 *)(ptr + 0x1C) = 0.0f; *(f32 *)(ptr + 0x20) = 0.0f; } }

extern OSMesgQueue D_801221C0;
extern OSMesgQueue D_801221D8;
extern OSMesgQueue D_801221F0;
extern OSMesg D_80122208[];
extern OSMesg D_8012220C[];
extern OSMesg D_80122210[];

void func_80018620(void) {
    D_8011BE90[0x6314] = 0;
    D_8011BE90[0x6315] = 0;
    D_8011BE90[0x6316] = 0;
    *(OSMesgQueue **)(D_8011BE90 + 0x6328) = &D_801221C0;
    *(OSMesgQueue **)(D_8011BE90 + 0x632C) = &D_801221D8;
    *(OSMesgQueue **)(D_8011BE90 + 0x6324) = &D_801221F0;
    osCreateMesgQueue(*(OSMesgQueue **)(D_8011BE90 + 0x6328), D_80122208, 1);
    osCreateMesgQueue(*(OSMesgQueue **)(D_8011BE90 + 0x632C), D_80122210, 4);
    osCreateMesgQueue(*(OSMesgQueue **)(D_8011BE90 + 0x6324), D_8012220C, 1);
}

// Same code as Majora's Mask AudioThread_QueueCmd (src/audio/lib/thread.c).
// Appends an 8-byte command (op/args word, data word) to the ring at D_8011BE90 + 0x6390; the
// write position byte is at 0x6314 and the read position byte at 0x6315.
void func_800186B8(u32 arg0, void **arg1) {
    u8 *cmd = &D_8011BE90[0x6390 + (D_8011BE90[0x6314] & 0xFF) * 8];

    *(u32 *)cmd = arg0;
    *(void **)(cmd + 4) = *arg1;

    D_8011BE90[0x6314]++;

    if (D_8011BE90[0x6315] == D_8011BE90[0x6314]) {
        D_8011BE90[0x6314]--;
    }
}

void func_80018704(s32 arg0, f32 arg1) {
    func_800186B8(arg0, &arg1);
}

void func_80018728(s32 arg0, s32 arg1) {
    func_800186B8(arg0, &arg1);
}

void func_8001874C(s32 arg0, s8 arg1) {
    s32 value;

    value = arg1 << 24;
    func_800186B8(arg0, &value);
}

void func_8001877C(s32 arg0, s16 arg1) {
    s32 value;

    value = arg1 << 16;
    func_800186B8(arg0, &value);
}


// Same code as Majora's Mask AudioThread_ScheduleProcessCmds without the queue-size tracking.
s32 func_800187AC(void) {
    s32 ret;

    ret = osSendMesg(gAudioContext.cmdProcQueueP,
                     (OSMesg)((gAudioContext.cmdRdPos & 0xFF) << 8 |
                              (gAudioContext.cmdWrPos & 0xFF)),
                     OS_MESG_NOBLOCK);
    if (ret != -1) {
        gAudioContext.cmdRdPos = gAudioContext.cmdWrPos;
        ret = 0;
    } else {
        return -1;
    }
    return ret;
}

void func_80018810(void) {
    D_8011BE90[0x6315] = D_8011BE90[0x6314];
    D_8011BE90[0x6316] = 0;
}




extern void func_80018078(AudioCmd *);
extern void func_80018CFC(u8 *, u8 *);
extern void func_80018ED4(u8 *, AudioCmd *);

// Same code as Ocarina of Time Audio_ProcessCmd (src/code/audio_thread.c); GS treats every
// op >= 0xE0 as global and keeps the sequence players as a pointer array.
void func_80018828(AudioCmd *cmd) {
    SequencePlayer *seqPlayer;
    u16 channelMask;
    s32 i;

    if ((cmd->op & 0xF0) >= 0xE0) {
        func_80018078(cmd);
        return;
    }

    if (cmd->arg0 < gAudioContext.numSequencePlayers) {
        seqPlayer = gAudioContext.seqPlayers[cmd->arg0];
        if (cmd->op & 0x80) {
            func_80018078(cmd);
            return;
        }
        if (cmd->op & 0x40) {
            func_80018CFC((u8 *)seqPlayer, (u8 *)cmd);
            return;
        }
        if (cmd->arg1 < 0x10) {
            func_80018ED4(seqPlayer->channels[cmd->arg1], cmd);
            return;
        }
        if (cmd->arg1 == 0xFF) {
            channelMask = gAudioContext.activeChannelMasks[cmd->arg0];
            for (i = 0; i < 16; i++) {
                if (channelMask & 1) {
                    func_80018ED4(seqPlayer->channels[i], cmd);
                }
                channelMask = channelMask >> 1;
            }
        }
    }
}

// File data between func_800179CC's and func_8001895C's statics (rom.yaml .data window).
// D_8008FA80 is probably the audio update's waiting-task static.
void *D_8008FA80 = NULL;
s32 D_8008FA84 = 0;


// Same code as Ocarina of Time Audio_ProcessCmds (src/code/audio_thread.c).
void func_8001895C(u32 msg) {
    static u8 sCurCmdRdPos = 0;
    AudioCmd *cmd;
    u8 endPos;

    if (!gAudioContext.cmdQueueFinished) {
        sCurCmdRdPos = msg >> 8;
    }

    while (TRUE) {
        endPos = msg & 0xFF;
        if (sCurCmdRdPos == endPos) {
            gAudioContext.cmdQueueFinished = FALSE;
            break;
        }
        cmd = &gAudioContext.cmdBuf[sCurCmdRdPos++ & 0xFF];
        if (cmd->op == 0xF8) {
            gAudioContext.cmdQueueFinished = TRUE;
            break;
        }
        func_80018828(cmd);
        cmd->op = 0;
    }
}

extern OSMesgQueue D_8011DFC0;
u32 func_80018A10(s32 *arg0) {
    void *sp1C;

    if (osRecvMesg(&D_8011DFC0, &sp1C, 0) == -1) {
        *arg0 = 0;
        return 0U;
    }
    *arg0 = (s32) sp1C & 0xFFFFFF;
    return (u32) sp1C >> 0x18;
}

void func_80018A74(void) {
    func_8001480C();
}

void func_80018A94(s32 arg0, s32 *arg1, s32 *arg2) { s32 offset = arg0 * 0x14; *arg1 = (*(u8 **)(D_8011BE90 + 0x2BD8))[offset + 2]; *arg2 = (*(u8 **)(D_8011BE90 + 0x2BD8))[offset + 3]; }

extern OSMesgQueue *D_801221B4;
extern u8 D_8011F2E5;
typedef unsigned char AccByte;
s32 func_80018ACC(void) { struct { s32 msg; s32 spare; } local; if (osRecvMesg(D_801221B4, (OSMesg *)&local.msg, 0) == -1) return 0; if (local.msg != D_8011F2E5) return -1; return 1; }

extern u8 D_8011BE90[];

void func_80018B24() {
    s32 status;
    OSMesg msg;

    do {
        status = -1;
    } while (osRecvMesg(*(OSMesgQueue **)(D_8011BE90 + 0x6324), &msg, 0) != status);
}
extern void func_80018B24();
extern void func_80018810(void);
extern s32 func_800187AC(void);
typedef struct {
    s32 leading_pad;
    s32 message;
} Func80018B78Locals;
extern void func_80018728(s32 arg0, s32 arg1);
s32 func_80018B78(s32 arg0) {
    s32 status;
    Func80018B78Locals local;

    func_80018B24(arg0);
    status = D_8011BE90[0x3454];
    if (status == 0) {
    } else {
        func_80018810();
        if (arg0 == D_8011BE90[0x3455]) {
            return -2;
        }
        if (status >= 3) {
            D_8011BE90[0x3455] = arg0;
            return -3;
        }
        osRecvMesg(*(OSMesgQueue **)(D_8011BE90 + 0x6324), &local.message, 1);
    }
    func_80018B24();
    func_80018728(0xF9000000, arg0);
    func_800187AC();
}

extern s32 D_8008FA78;
extern s32 func_80018B78(s32 arg0);
extern u8 D_8011BE90[];
void func_80018C14(void) {
    volatile s32 *word_ptr;
    volatile u8 *byte_ptr;
    word_ptr = (s32 *)D_8011BE90;
    word_ptr[0xB45] = 1;
    if (D_8008FA78 != 0) {
        func_80018B78(0);
        byte_ptr = D_8011BE90;
        byte_ptr[0x3454] = 0;
    }
}

s8 func_80018C60(s32 arg0, s32 arg1, s32 arg2)
{
  u8 *temp_v1;
  u8 *new_var2;
  int new_var;
  new_var = arg1 * 4;
  temp_v1 = D_80121EDC[arg0];
  if (((u32) (*((u32 *) temp_v1))) >> 31)
  {
    new_var2 = *((u8 **) ((temp_v1 + new_var) + 0x38));
    return *((s8 *) ((new_var2 + arg2) + 0xD0));
  }
  return -1;
}

extern u8 *D_80121EDC[]; s8 func_80018CA4(s32 arg0, s32 arg1) { return *(s8 *)(D_80121EDC[arg0] + arg1 + 0x158); }

extern s32 D_8011EBD0;
extern void GbApu_InitAllocator(s32 *, s32, s32);
void func_80018CC0(s32 arg0, s32 arg1) {
    GbApu_InitAllocator(&D_8011EBD0, arg0, arg1);
}

extern s32 D_8011EBD0; void func_80018CF0(void) { D_8011EBD0 = 0; }

// Flag byte at offset 0 of a sequence player; func_80018CFC sets recalculateVolume (0x04)
// and applyBend (0x01). Names follow the Majora's Mask SequencePlayer bitfield.
typedef struct SequencePlayerFlags {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 muted : 1;
    /* 0x00 */ u8 seqDmaInProgress : 1;
    /* 0x00 */ u8 fontDmaInProgress : 1;
    /* 0x00 */ u8 recalculateVolume : 1;
    /* 0x00 */ u8 stopScript : 1;
    /* 0x00 */ u8 applyBend : 1;
} SequencePlayerFlags;

// Same code as Majora's Mask AudioThread_ProcessSeqPlayerCmd (src/audio/lib/thread.c).
// arg1 is an 8-byte audio command: opcode at 0x0, argument bytes at 0x2 and 0x3, data at 0x4.
void func_80018CFC(u8 *arg0, u8 *arg1) {
    f32 fade_volume;

    switch (arg1[0]) {
        case 0x41:
            if (*(f32 *)(arg1 + 4) != *(f32 *)(arg0 + 0x2C)) {
                *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg1 + 4);
                ((SequencePlayerFlags *)arg0)->recalculateVolume = TRUE;
            }
            break;

        case 0x47:
            *(u16 *)(arg0 + 8) = *(s32 *)(arg1 + 4) * 48;
            break;

        case 0x49:
            *(s16 *)(arg0 + 0xC) = *(s32 *)(arg1 + 4) * 48;
            break;

        case 0x4E:
            *(s16 *)(arg0 + 0xC) = *(s32 *)(arg1 + 4);
            break;

        case 0x48:
            *(s16 *)(arg0 + 0xE) = *(s8 *)(arg1 + 4);
            break;

        case 0x46:
            *(s8 *)(arg0 + 0x158 + arg1[3]) = *(s8 *)(arg1 + 4);
            break;

        case 0x4A:
            fade_volume = (s32)arg1[2] / 127.0f;
            goto apply_fade;

        case 0x4B:
            fade_volume = *(f32 *)(arg0 + 0x1C) * ((s32)arg1[2] / 100.0f);
        apply_fade:
            if (arg0[1] != 2) {
                *(f32 *)(arg0 + 0x24) = *(f32 *)(arg0 + 0x1C);
                if (*(s32 *)(arg1 + 4) == 0) {
                    *(f32 *)(arg0 + 0x1C) = fade_volume;
                } else {
                    s32 fade_timer = *(s32 *)(arg1 + 4);

                    arg0[1] = 0;
                    *(u16 *)(arg0 + 0x12) = fade_timer;
                    *(f32 *)(arg0 + 0x20) = (fade_volume - *(f32 *)(arg0 + 0x1C)) / fade_timer;
                }
            }
            break;

        case 0x4C:
            if (arg0[1] != 2) {
                if (*(s32 *)(arg1 + 4) == 0) {
                    *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg0 + 0x24);
                } else {
                    s32 fade_timer = *(s32 *)(arg1 + 4);

                    arg0[1] = 0;
                    *(u16 *)(arg0 + 0x12) = fade_timer;
                    *(f32 *)(arg0 + 0x20) = (*(f32 *)(arg0 + 0x24) - *(f32 *)(arg0 + 0x1C)) / fade_timer;
                }
            }
            break;

        case 0x4D:
            *(f32 *)(arg0 + 0x34) = *(f32 *)(arg1 + 4);
            if (*(f32 *)(arg0 + 0x34) == 1.0f) {
                ((SequencePlayerFlags *)arg0)->applyBend = FALSE;
            } else {
                ((SequencePlayerFlags *)arg0)->applyBend = TRUE;
            }
            break;

        default:
            break;
    }
}

extern void func_80011864(s16 *filter, s32 lowPassCutoff, s32 highPassCutoff);
// Flag bytes at offsets 0 and 1 of a sequence channel; func_80018ED4 writes muted (0x10 in
// byte 0) and the change flags in byte 1. Names follow the Majora's Mask SequenceChannel
// bitfields.
typedef struct SequenceChannelFlags {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 stopScript : 1;
    /* 0x00 */ u8 muted : 1;
    /* 0x00 */ u8 hasInstrument : 1;
    /* 0x00 */ u8 stereoHeadsetEffects : 1;
    /* 0x00 */ u8 largeNotes : 1;
    /* 0x00 */ u8 unused : 1;
    /* 0x01 */ u8 changeFreqScale : 1;
    /* 0x01 */ u8 changeVolume : 1;
    /* 0x01 */ u8 changePan : 1;
} SequenceChannelFlags;

// Close to Majora's Mask AudioThread_ProcessChannelCmd (src/audio/lib/thread.c); GS has one
// extra opcode, 0x15, which stores the command's unsigned byte as a u16 at channel + 0x2A.
// GS channel offsets: vibrato rate/depth targets at 0x18/0x1A, combFilterGain at 0x24,
// seqScriptIO at 0xD0, sfxState at 0xD8, filter at 0xDC, stereo byte at 0xE0 and
// startSamplePos at 0xE4.
void func_80018ED4(u8 *channel, AudioCmd *cmd) {
    u8 filterCutoff;

    switch (cmd->op) {
        case 0x1:
            if (*(f32 *)(channel + 0x2C) != cmd->data.asFloat) {
                *(f32 *)(channel + 0x2C) = cmd->data.asFloat;
                ((SequenceChannelFlags *)channel)->changeVolume = TRUE;
            }
            break;

        case 0x2:
            if (*(f32 *)(channel + 0x30) != cmd->data.asFloat) {
                *(f32 *)(channel + 0x30) = cmd->data.asFloat;
                ((SequenceChannelFlags *)channel)->changeVolume = TRUE;
            }
            break;

        case 0x3:
            if (channel[0xA] != cmd->data.asSbyte) {
                channel[0xA] = cmd->data.asSbyte;
                ((SequenceChannelFlags *)channel)->changePan = TRUE;
            }
            break;

        case 0x7:
            if (channel[0xA] != cmd->data.asSbyte) {
                channel[0xB] = cmd->data.asSbyte;
                ((SequenceChannelFlags *)channel)->changePan = TRUE;
            }
            break;

        case 0x4:
            if (*(f32 *)(channel + 0x3C) != cmd->data.asFloat) {
                *(f32 *)(channel + 0x3C) = cmd->data.asFloat;
                ((SequenceChannelFlags *)channel)->changeFreqScale = TRUE;
            }
            break;

        case 0x5:
            if (channel[0x4] != cmd->data.asSbyte) {
                channel[0x4] = cmd->data.asSbyte;
            }
            break;

        case 0x11:
            if (channel[0x8] != cmd->data.asSbyte) {
                channel[0x8] = cmd->data.asSbyte;
            }
            break;

        case 0x12:
            channel[0x10] = cmd->data.asSbyte;
            break;

        case 0x6:
            if (cmd->arg2 < 8) {
                *(s8 *)(channel + 0xD0 + cmd->arg2) = cmd->data.asSbyte;
            }
            break;

        case 0x8:
            ((SequenceChannelFlags *)channel)->muted = cmd->data.asSbyte;
            break;

        case 0x9:
            channel[0x3] = cmd->data.asSbyte;
            break;

        case 0xA:
            *(u16 *)(channel + 0x1A) = cmd->data.asUbyte * 8;
            *(u16 *)(channel + 0x1E) = 1;
            break;

        case 0xB:
            *(u16 *)(channel + 0x18) = cmd->data.asUbyte * 32;
            *(u16 *)(channel + 0x1C) = 1;
            break;

        case 0xC:
            channel[0xF] = cmd->data.asUbyte;
            break;

        case 0xD:
            *(u16 *)(channel + 0x24) = cmd->data.asUShort;
            break;

        case 0xE:
            channel[0xE0] = cmd->data.asUbyte;
            break;

        case 0xF:
            *(s32 *)(channel + 0xE4) = cmd->data.asInt;
            break;

        case 0x10:
            *(void **)(channel + 0xD8) = cmd->data.asPtr;
            break;

        case 0x13:
            filterCutoff = cmd->arg2;
            if (cmd->data.asPtr != NULL) {
                *(s16 **)(channel + 0xDC) = cmd->data.asPtr;
            }
            if (*(s16 **)(channel + 0xDC) != NULL) {
                func_80011864(*(s16 **)(channel + 0xDC), filterCutoff >> 4, filterCutoff & 0xF);
            }
            break;

        case 0x14:
            channel[0xC] = cmd->data.asUbyte;
            break;

        case 0x15:
            *(u16 *)(channel + 0x2A) = cmd->data.asUbyte;
            break;

        default:
            break;
    }
}

void func_8001911C(s32 arg0, s32 arg1, s32 arg2) {
    func_80018728(((arg0 & 0xFF) << 0x10) | 0xFA000000 | ((arg1 & 0xFF) << 8) | (arg2 & 0xFF), 1);
}

void func_80019164(void) {
    func_80018728(0xFA000000, 0);
}

void func_80019188(s32 arg0, s32 arg1) {
    func_80018728((arg1 & 0xFF) | 0xFD000000, arg0);
}

extern OSMesgQueue *D_801221B8; void func_800191BC(void) { osRecvMesg(D_801221B8, NULL, 0); osRecvMesg(D_801221B8, NULL, 1); }

extern s32 func_8001926C(s32, s32, s32, s32 *, s32 *);
s32 func_800191FC(s32 arg0, s32 arg1, s32 arg2) {
    s32 locals[4];
    if (func_8001926C(arg0, arg1, arg2, &locals[2], &locals[1]) == 0) {
        return 0;
    }
    return locals[1];
}

s32 func_80019230(s32 arg0, s32 arg1, s32 arg2) {
    s32 locals[4];
    if (func_8001926C(arg0, arg1, arg2, &locals[2], &locals[1]) == 0) {
        return 0;
    }
    return locals[2] - locals[1];
}

// Same code as Majora's Mask AudioThread_GetSamplePos (src/audio/lib/thread.c); GS reaches
// the sequence player through the pointer table D_80121EDC, and its note fields sit at
// smaller offsets (parentLayer at 0x44, the isSyntheticWave flag word at 0xD0, tunedSample
// at 0xE0; Majora's Mask uses 0x48, 0xD8 and 0xE8).
// Returns TRUE and writes the sample's loop end and the note's integer sample position when
// the layer's note is still owned by that layer and plays a real sample.
s32 func_8001926C(s32 arg0, s32 arg1, s32 arg2, s32 *loopEnd, s32 *samplePosInt) {
    u8 *seqPlayer = D_80121EDC[arg0];
    u8 *layer;
    u8 *note;
    u8 *tunedSample;

    if ((*(u32 *)seqPlayer >> 31) && (**(u32 **)(seqPlayer + 0x38 + arg1 * 4) >> 31)) {
        layer = *(u8 **)(*(u8 **)(seqPlayer + 0x38 + arg1 * 4) + 0x54 + arg2 * 4);
        if (layer == NULL) {
            return FALSE;
        }

        if (*(u32 *)layer >> 31) {
            if (*(u8 **)(layer + 0x3C) == NULL) {
                return FALSE;
            }

            if (!((*(u32 *)layer << 4) >> 31)) {
                return FALSE;
            }

            note = *(u8 **)(layer + 0x3C);
            if (layer == *(u8 **)(note + 0x44)) {
                if (((*(u32 *)(note + 0xD0) << 13) >> 31) == TRUE) {
                    return FALSE;
                }

                tunedSample = *(u8 **)(note + 0xE0);
                if (tunedSample == NULL) {
                    return FALSE;
                }
                *loopEnd = *(s32 *)(*(u8 **)(*(u8 **)tunedSample + 8) + 4);
                *samplePosInt = *(s32 *)(note + 0x1C);
                return TRUE;
            }
            return FALSE;
        }
    }
    return FALSE;
}

s32 func_800193B8(s32 flags);

void func_80019378(void) {
    func_800193B8(0);
}

void func_80019398(void) {
    func_800193B8(2);
}

// Same code as Ocarina of Time func_800E66C0 (src/audio/internal/thread.c), which counts
// the notes still playing and, for odd flags, releases them; GS's audio context is
// D_8011BE90 with the note count at 0x2C28, 0x100-byte notes from the pointer at
// 0x3468, and the release rate at 0x2BF8.
s32 func_800193B8(s32 flags) {
    typedef struct { u8 unk_bits : 3; u8 release : 1; u8 state : 4; } AdsrAction;
    typedef struct {
        u32 enabled : 1;
        u32 needs_init : 1;
        u32 finished : 1;
        u32 unused : 1;
        u32 strong_right : 1;
        u32 strong_left : 1;
        u32 strong_reverb_right : 1;
        u32 strong_reverb_left : 1;
        u32 reverb_index : 3;
        u32 book_offset : 2;
        u32 is_synthetic_wave : 1;
        u32 has_two_parts : 1;
        u32 use_haas_effect : 1;
        u32 unk_bits : 16;
    } NoteSampleFlags;
    typedef struct { u8 unk_00[0x30]; u8 playback[0xA0]; u8 sample_state[0x30]; } Note;
    typedef struct {
        u8 unk_0000[0x2BF8];
        f32 ticks_per_update_inv;
        u8 unk_2BFC[0x2C];
        s32 num_notes;
        u8 unk_2C2C[0x83C];
        Note *notes;
    } AudioContext;
    s32 count;
    u8 *playback;
    u8 *sample_state;
    s32 i;
    Note *note;
    u8 *tuned_sample;

    count = 0;
    for (i = 0; i < ((AudioContext *)D_8011BE90)->num_notes; i++) {
        // FAKE: adding the note array after the index orders the addu operands like the
        // original; diff score 10 without it.
        note = i + ((AudioContext *)D_8011BE90)->notes;
        playback = note->playback;
        if (((NoteSampleFlags *)note->sample_state)->enabled) {
            sample_state = note->sample_state;
            if (((AdsrAction *)(playback + 0x30))->state != 0) {
                if (flags >= 2) {
                    tuned_sample = *(u8 **)(sample_state + 0x10);
                    if (tuned_sample == NULL || ((NoteSampleFlags *)sample_state)->is_synthetic_wave) {
                        continue;
                    }
                    if ((*(Sample **)tuned_sample)->medium == 0) {
                        continue;
                    }
                }

                count++;
                if ((flags & 1) == 1) {
                    *(f32 *)(playback + 0x3C) = ((AudioContext *)D_8011BE90)->ticks_per_update_inv;
                    ((AdsrAction *)(playback + 0x30))->release = 1;
                }
            }
        }
    }
    return count;
}


// Same code as Ocarina of Time Audio_NextRandom (src/code/audio_thread.c).
u32 func_800194A0(void) {
    static u32 sAudioRandom = 0x12345678;
    static u32 sAudioRandomPrev = 0x11111111;
    u32 count = osGetCount();

    sAudioRandom = (gAudioContext.totalTaskCount + sAudioRandom + count) *
                   (gAudioContext.audioRandom + 0x1234567);
    sAudioRandom = (sAudioRandom & 1) + (sAudioRandom * 2) + sAudioRandomPrev;
    sAudioRandomPrev = count;
    return sAudioRandom;
}


void func_8001951C(void) {
    func_80018620();
}
#endif
