#include "229E0.h"

#ifdef VERSION_US

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

#endif
