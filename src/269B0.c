#include "229E0.h"

#ifdef VERSION_US

/* mkdraft:func_80025DB0 begin */
#include "global.h"
extern u8 D_800D1930[];
extern u8 D_800D1940[];
extern u8 D_800D1980[];
extern u8 D_800D1910;

// Bitfield view of the packed state word at D_800D1930. Big-endian bit order
// puts top at bit 31, mode at bits 28..30, clr at 26..27, en0 at 25, en1 at 24
// and low at bits 0..23.
typedef struct {
    u32 top : 1;
    u32 mode : 3;
    u32 clr : 2;
    u32 en0 : 1;
    u32 en1 : 1;
    u32 low : 24;
} unk_D_800D1930;



void func_80025DB0(void)
{
    /* The four bitfield stores fold into one read-modify-write chain over
       byte 0: mode=4 clears bits 28..30 and sets bit 30, clr=0 clears bits
       26..27, en0=1 sets bit 25, en1=1 sets bit 24.  low=0x200 is lowered
       to a whole-word store that keeps bits 24..31 and forces bit 9. */
    *(s16 *)(&D_800D1980[0]) = 1;
    *(s16 *)(&D_800D1980[2]) = 32000;
    *(s16 *)(&D_800D1980[6]) = 0;
    *(s16 *)(&D_800D1980[4]) = -1;
    *(u8 *)((u8 *)(&D_800D1910) + 0) = 1;
    *(u8 *)((u8 *)(&D_800D1910) + 1) = 0;
    *(u8 *)((u8 *)(&D_800D1910) + 2) = 127;
    *(u8 *)((u8 *)(&D_800D1910) + 3) = 240;
    *(void **)((u8 *)(&D_800D1910) + 4) = (&D_800D1980);
    *(void **)((u8 *)(&D_800D1910) + 0x10) = (&D_800D1930);
    *(u32 *)(&D_800D1940[4]) = 0x10000;
    ((unk_D_800D1930 *)D_800D1930)->mode = 4;
    ((unk_D_800D1930 *)D_800D1930)->clr = 0;
    ((unk_D_800D1930 *)D_800D1930)->en0 = 1;
    *(f32 *)((u8 *)(&D_800D1910) + 0x14) = 0.5f;
    ((unk_D_800D1930 *)D_800D1930)->en1 = 1;
    *(u32 *)(&D_800D1940[0]) = 0;
    *(u32 *)(&D_800D1940[8]) = 1;
    ((unk_D_800D1930 *)D_800D1930)->low = 0x200;
    *(u32 *)(&D_800D1930[4]) = 0;
    *(void **)(&D_800D1930[8]) = (&D_800D1940);
    *(u32 *)(&D_800D1930[0xC]) = 0;
}
/* mkdraft:func_80025DB0 end */

void func_80025E7C(void) {
    func_80025DB0();
    func_80018728(0xE2000700U, &D_800D1910);
}

s32 Audio_RenderNextBuffer(s32 arg0, s32 samples, s32 initialize, s32 arg3) {
    s32 result;
    s16 *buffer;
    if ((s8)D_80090B8C == 0) { return 0; }
    buffer = D_800D1990[D_80090AC0];
    if (initialize == 1) {
        func_80031A6C(32000, D_800D198C);
    }
    result = func_80031C84(buffer, samples);
    D_80090AC0++;
    D_80090AC0 %= 3;
    if ((s8)D_80090B8C == 0) { return 0; }
    if (result == -1) { return result; }
    return (s32)buffer;
}

void Audio_InitializeBufferMemory(void *buffer) {
    u32 aligned = ((u32)buffer + 0xF) & ~0xF;
    u32 mask;
    D_800D198C = (void *)aligned;
    D_800D1990[0] = (s16 *)((u8 *)D_800D198C + 0x2380);
    D_800D1990[1] = (s16 *)((u8 *)D_800D1990[0] + 0x2000);
    D_800D1990[2] = (s16 *)((u8 *)D_800D1990[1] + 0x2000);
    func_80031A6C(32000, D_800D198C);
    func_80018728(0x82030300, 0);
    func_800187AC();
    func_80025E7C();
    func_8001874C(0x06030000, 0);
    func_80034DD0();
    mask = osSetIntMask(1);
    D_80090B8C = 1;
    osSetIntMask(mask);
}

 void func_8002602C(void) { s32 mask; func_80018728(0x83030000, 0); mask = osSetIntMask(1); D_80090B8C = 0; osSetIntMask(mask); }

void func_80026068(u32 arg0) {
    s32 temp_a1;

    if (arg0 != 0) {
        temp_a1 = arg0 - 1;
        if (arg0 < 0xFCU) {
            func_80034E5C(temp_a1 & 0xFFFF, temp_a1);
        }
    }
}

 void func_80026098(void) { GbAudio_GetActiveChannelMask(); }

#endif
