#include "229E0.h"

#ifdef VERSION_US

s32 func_80035160(s32 index) { return D_80094870[index]; }

void Audio_ThreadMain(void *unused) {
    OSTask *task;
    s32 tick;
    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(&D_80122B20, 1, 1);
    func_80005568(&D_80122B20);
    D_80122A40 = 1;
    D_80122B18 = 0;
    osCreateMesgQueue(&D_80122A4C, &D_80122A48[0].message, 1);
    osCreateMesgQueue(&D_80122AB4, &D_80122AB0, 1);
    osSendMesg(&D_80122A4C, (OSMesg)0x444F4E45, OS_MESG_NOBLOCK);
    osSendMesg(&D_80122AB4, (OSMesg)0x444F4E45, OS_MESG_NOBLOCK);
    Audio_InitializeTaskState();
    func_80025C50(2);
    while (1) {
        func_80004F34((u8 *)&D_80122B20);
        profiler_log_thread4_time();
        if (D_80122A40 != 0 && *(s16 *)((u8 *)D_800CD020 + 0xA38) < 21) {
            task = (OSTask *)Audio_BuildSchedulerTask();
            if (task != NULL) {
                D_80122A48[D_80122B18].task = *task;
                Sched_SubmitTask(&D_80122A48[D_80122B18], 0);
            }
        }
        D_80122B18 ^= 1;
        profiler_log_thread4_time();
        tick = D_8009486C;
        D_8009486C = tick + 1;
    }
}

void Thread4_CreateThread(void) {
    osCreateThread(&D_80122B20, 4, Audio_ThreadMain, NULL, D_80124D00, 0x50);
    osStartThread(&D_80122B20);
}

void func_8003539C(void) {
    func_80021BBC();
}

s32 Audio_StopProcessing(void) {
    func_80025C9C();
    D_80122A40 = 0;
    return 0;
}

s32 Audio_WaitForPendingTasks(void) {
    s32 completed = 0;

    while (func_80025D44() != 0) {
        completed++;
    }
    return completed;
}

void func_80035424(s32 arg0) {
    s32 value = arg0;
    void *entry = func_80008494();
    if (entry != 0) {
        value = arg0;
        value *= *(s8 *)((u8 *)entry + 0x10);
    }
    func_80025CBC(value);
}

void Audio_SetProcessingEnabled(s32 enabled) { D_80122A40 = enabled ? 0 : 1; }

void Audio_ResetModeSelector(void) {
    D_80094860 = -1;
}

void Audio_EnableModeFlag(void) {
    D_80094868 = 1;
}

s32 Audio_SetModeBlocking(s32 mode, s32 arg1, s32 arg2) {
    s32 changed = 0;
    s32 tick;
    s32 readyTick;
    if (mode == 2) {
        if (D_80094868 != 0) {
            D_80094868 = 0;
            mode = 11;
        }
    }
    if (mode != D_80094860) {
        D_80094860 = mode;
        changed = 1;
        do {
            tick = *(volatile s32 *)&D_8009486C;
            func_8003539C();
            while (tick == *(volatile s32 *)&D_8009486C) {
            }
        } while (func_80025D44() != 0);
        func_800260C0(mode, arg1, arg2);
        while (func_80026298() == 0) {
            readyTick = *(volatile s32 *)&D_8009486C;
            while (readyTick == *(volatile s32 *)&D_8009486C) {
            }
        }
        func_800262F0();
        if (D_80094860 == 11) {
            D_80094860 = 2;
        }
    }
    return changed;
}

void Audio_ResetRequestId(void) {
    D_80094864 = -1;
}

s32 Audio_RequestIfChanged(s32 requestId) {
    if (requestId != D_80094864) {
        D_80094864 = requestId;
        func_80021ED8(requestId);
    }
    return 0;
}

#endif
