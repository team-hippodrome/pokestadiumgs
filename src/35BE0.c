#include "229E0.h"

#ifdef VERSION_US

void func_80034FE0(void) {
    if ((s8) D_80090B8C != 0) {
        func_80034DF0();
    }
    D_80094570 += 1;
}

void func_80035020(s32 arg0) {
    if (arg0 != 1) {
        D_800D2D78 = osCartRomInit();
    }
    osCreateMesgQueue(&D_800D2D60, &D_800D2D7C, 1);
}

void Audio_ReadRomBlocking(u32 rom, u8 *destination, u32 remaining) {
    OSIoMesg message;
    u32 currentRom = rom;
    u8 *currentDestination = destination;
    u32 chunk;
    while (remaining != 0) {
        if (remaining > 0x4000) chunk = 0x4000;
        else chunk = remaining;
        message.hdr.pri = OS_MESG_PRI_NORMAL;
        message.hdr.retQueue = &D_800D2D60;
        message.dramAddr = currentDestination;
        message.devAddr = currentRom;
        message.size = chunk;
        osInvalDCache(currentDestination, chunk);
        osEPiStartDma(D_800D2D78, &message, OS_READ);
        osRecvMesg(&D_800D2D60, NULL, OS_MESG_BLOCK);
        remaining -= chunk;
        currentRom += chunk;
        currentDestination += chunk;
    }
}

#endif
