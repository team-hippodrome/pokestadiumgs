#ifndef CORE_229E0_H
#define CORE_229E0_H

#include "global.h"

#ifdef VERSION_US

extern void func_80021ED8(s32);
extern u8 D_800D2B58;
extern void GbAudio_UpdateSquare1Registers(u8);
/* Stadium 1 transfer helper: allocates a typed block from the supplied pool. */
extern void *MainPool_AllocAligned(void *, size_t, s32);
extern Vtx *func_800398F8();

extern unsigned char D_80090137[0x100];
extern unsigned char D_800917F8[0x100];
f32 func_80021DE0(s32 arg0) ;

extern void func_800187AC();
extern s8 D_8009019C;
extern s8 D_800901A0;
extern s8 D_800901A4;
extern void func_80018728(u32, ...);

void func_800225C4(s32 arg0) ;

void func_8002260C(s32 arg0, s32 arg1) ;

s32 func_8002263C(void) ;

extern s8 D_80090220;
extern s32 D_8009022C;
extern s8 D_80090B80;
void func_800238C4(void) ;

void func_8002390C(s32 arg0) ;

extern void func_8001874C(s32, s8);
void func_80023954(void) ;

extern u8 D_80090200[];
/* Returns the selected mask bit, not a normalized boolean. */
u8 Audio_GetSpeciesMaskBit(u32 species) ;

extern s32 D_80090224, D_80090228;

void func_800239B4(s32 arg0, s32 arg1) ;

void func_800239C8(void) ;

extern s32 D_8009061C[][4];
s32 func_80023A10(u8 arg0, u8 arg1) ;

void func_80024180(u32 arg0, s32 arg1) ;

s32 func_80024864(void) ;

extern u32 D_800D1900;
extern u8 D_154F190[];
extern void func_80035068(u32 rom, u8 *destination, u32 remaining);

void func_800248A0(void) ;

void func_800248EC(void *arg0) ;

extern s8 D_80090A54;

void func_80024D10(s32 arg0) ;

extern s32 D_80090A50;
extern u8 D_80090A74[2];
extern s8 D_80090A78;

void func_80024D44(void) ;

extern s32 func_80024E30(u32);
extern u8 D_80090A7C;
typedef struct {
    u8 ids[2];
    u8 unknown02[2];
    s8 active;
    u8 unknown05[3];
    u8 lastSlot;
    u8 unknown09[3];
} AudioResourceCacheView;
s32 Audio_GetOrCacheResourceId(u32 id) ;

/* Original unreachable jr/nop tail at 0x80024E28. */
void func_80024D6C_padding(void) ;

s32 func_80024E30(u32 arg0) ;

extern s32 D_80090A80;
extern void func_80024480(s32, s32);

void func_80024E8C(s32 arg0) ;

/* func_80024F20 is still GLOBAL_ASM, but its .s is hand-maintained (not the
 * splat-generated asm/us/nonmatchings/229E0/func_80024F20.s) so that it can
 * also carry 3 extra .late_rodata padding words ahead of jtbl_800A32C0. See
 * the comment in hand_asm/229E0/func_80024F20_manual.s for why. */

extern void func_80018704(s32, s32);
void func_800251F8(s32 arg0) ;

void func_80025848(s32 arg0) ;

void Audio_ApplyCommandPreset(s32 preset) ;

void func_80025ACC(s32 arg0) ;

extern u8 D_80090BA4;
void Audio_SetPreset(s32 preset) ;

extern s8 D_80090B90;
void func_80025C50(u32 arg0) ;

extern s32 func_80018C14(void);
s32 func_80025C9C(void) ;

extern void func_800315E8();
extern u8 D_80090B9C;
void func_8002B1A0(void);
extern void func_80028140(void);

void func_80025CBC(s32 arg0) ;

extern s32 func_80019378(void);

s32 func_80025D44(void) ;

void func_80025D64(u8 arg0) ;

extern void func_80025DB0();
extern u8 D_800D1910;

void func_80025E7C(void) ;

extern u8 D_80090B8C;
extern u32 D_80090AC0;
extern s16 *D_800D1990[3];
extern void *D_800D198C;
extern void func_80031A6C(s32, void *);
extern s32 func_80031C84(s16 *, s32);
s32 Audio_RenderNextBuffer(s32 arg0, s32 samples, s32 initialize, s32 arg3) ;

extern void func_80034DD0(void);
void Audio_InitializeBufferMemory(void *buffer) ;

extern void func_80018728(u32, ...); extern u8 D_80090B8C; void func_8002602C(void) ;

extern void func_80034E5C(s32, s32);

void func_80026068(u32 arg0) ;

extern u8 GbAudio_GetActiveChannelMask(void); void func_80026098(void) ;

s32 func_80018ACC();
extern u8 D_80090B64;
s32 func_80026298(void) ;

extern s32 D_80090B60;
extern u8 D_80090B68;
extern s16 D_80090B6C;
extern s16 D_80090B70;
void Audio_ResetCategoryState(void) ;

s32 Audio_GetEventConfigIndex(s32 category, u32 request) ;

typedef struct Color_80026938 {
    u8 first;
    u8 second;
    u8 third;
} Color_80026938;
extern u8 D_80090B3C[];
extern Color_80026938 D_80090AD0[];
void func_80026938(u16 arg0) ;

extern u16 D_800D19A0[];
extern char D_800A39A0[];
extern char D_800A39A4[];
extern f32 func_80026990(u8);
void Audio_DebugSampleHistogram(u8 mode) ;

#pragma pack(1)
typedef struct { s32 w0; s32 w4; } PackedRecord;
#pragma pack(0)
extern PackedRecord D_80090C84[];
extern PackedRecord D_80090CFC;
typedef struct AudioChannelEvent {
    u8 bank;
    u8 unknown01;
    u16 sound;
    u8 slot;
    u8 kind;
    u16 mask;
    u8 count;
    u8 unknown09[3];
    void *resource;
    f32 scale;
    u8 unknown14[4];
} AudioChannelEvent;
extern void func_80026ED8(u8);
extern u8 Audio_SetupEventVoice(AudioChannelEvent *, u8);
extern s32 func_8002738C(u8);

extern u8 D_800918E8;
extern s32 Audio_ConfigureEventChannel(AudioChannelEvent *, u8);
extern void Audio_UpdateEventVoiceParameters(void *, u8, u8);
void Audio_ProcessChannelEvent(AudioChannelEvent *event, s32 arg1) ;

s32 Audio_ConfigureEventChannel(AudioChannelEvent *event, u8 request) ;

void func_80026ED8(u8 arg0) ;

extern s32 Audio_SelectEventChannel(void *, u8);
extern void Audio_UpdateEventVoiceParameters(void *, u8, u8);
extern u8 D_80090BC1[];
extern u8 D_80090D28[][16];
u8 Audio_SetupEventVoice(AudioChannelEvent *arg0, u8 request) ;

typedef struct { u8 unknown00[6]; u16 mask; } AudioChannelMask;
typedef struct { s32 w0; s32 w4; s32 w8; } Candidate27F7CRecord;
extern Candidate27F7CRecord D_80090BB8[];
extern Candidate27F7CRecord D_80090C78;
typedef struct { AudioChannelMask channels; u8 count; } AudioChannelGroup;
typedef struct AudioVoiceParameters {
    u8 unknown00[2];
    u16 sound;
    u8 unknown04[8];
    s8 *pan;
    f32 pitch;
    u8 balance;
} AudioVoiceParameters;
extern f64 D_800A39B0;
extern f32 D_800A39B8;
void Audio_UpdateEventVoiceParameters(void *arg0, u8 channel, u8 reset) ;

extern s8 func_80018C60(s32, s32, s32);
extern u8 Audio_FindEnabledChannel(AudioChannelMask *, u8, u8);
extern u8 Audio_FindLowestPriorityChannel(AudioChannelGroup *, u8);
s32 Audio_SelectEventChannel(void *arg0, u8 request) ;

extern s32 func_8002738C(u8);
u8 Audio_FindEnabledChannel(AudioChannelMask *state, u8 channel, u8 advance) ;

s32 func_8002738C(u8 channel) ;

u8 Audio_FindLowestPriorityChannel(AudioChannelGroup *state, u8 channel) ;

extern f32 D_80090BBC[][3];
typedef struct Candidate275E8State {
    u8 unk0;
    u8 flags;
    u8 pad02[0x3A];
    f32 value;
} Candidate275E8State;
typedef struct Candidate275E8Bits {
    u8 unk0;
    unsigned char active : 1;
    unsigned char other : 7;
    u8 pad02[0x3A];
    f32 value;
} Candidate275E8Bits;
s32 func_800275E8(u8 arg0, Candidate275E8Bits *arg1) ;

typedef AudioChannelEvent ResourceContext_80027774;
extern void Audio_BuildAndDispatchSoundEvent(u16, s32, ResourceContext_80027774 *);
extern u8 D_80090D04[];
void func_80027774(u16 arg0, u8 arg1) ;

extern void func_8002781C(u16 resource_id, u8 mode, ...);
void func_800277C4(u16 resource_id, u8 mode) ;

void func_800277F0(u16 resource_id, void *context) ;

void Audio_PlayDefaultSound(u16 id) ;

extern u8 D_800A3990[];
extern u8 D_80090D31[];
// Decode the request, adjust its channel mask, and dispatch nonempty events.
void Audio_BuildAndDispatchSoundEvent(u16 encoded, s32 offset, ResourceContext_80027774 *event) ;

extern void func_80027E30(void);
extern void func_80027F4C(void);

// credit to https://decomp.me/scratch/eFWz0
void func_80027EE0(u16 arg0) ;

extern void func_80027F7C();
extern s8 D_80090BB0;

void func_80027F4C(void) ;

void func_80027F7C(void) ;

extern u8 D_8011F300;
extern void func_80027EE0(u16);
extern void Audio_PlayDefaultSound(u16);

void func_80028014(void) ;

extern u8 D_8011BE90;
extern u16 D_800D2B44;
extern s16 D_800D2BA8;
extern u8 D_800D2B78;
s32 func_8002806C(void) ;

void func_8002809C(void) ;

void func_800280C0(void) ;

void func_800280EC(void) ;

extern u8 D_80090BB4;
void func_80028118(u8 arg0) ;

extern s32 D_800D1A70[2];
extern s32 D_800D1A78[2];
extern s8 D_800D1A80[2];
extern s8 D_800D1A82[2];
void func_80028140(void) ;

// Select a request channel and leave its state for Audio_UpdateDeferredSounds.
void Audio_QueueDeferredSound(s32 sound, s32 delay, u8 parameter) ;

void func_80028300(void) ;

// Count down two pending requests and submit their channel commands when due.
void Audio_UpdateDeferredSounds(void) ;
// Preserve the original two zero words of inter-function alignment.

extern u8 D_8009210C[];
u8 Audio_LookupScaledRatio(u16 numerator, u16 denominator) ;

void Audio_SwapSoundCandidates(u8 *arg0, u8 *arg1) ;

extern u32 D_800D1AD8[24];
u16 Audio_FilterRecentSoundId(u16 arg0) ;

void Audio_RemoveRecentSoundAt(u16 arg0) ;

extern void func_800314D4(s32);
// The first halfword's low byte counts the following 16-bit sound IDs.
//@asm/us/nonmatchings/229E0/func_80028ADC.s
extern s32 func_80028ADC(const void *sound_candidates);
void func_80028CA8(const void *sound_candidates);
void func_80028CA8_padding(void) ;
void func_80028CA8_padding2(void) ;

s32 func_80028CE8(void *arg0, s32 arg1) ;

extern u8 D_800D2660[];
s32 func_80028E60(u32 arg0)
;

void func_80028EA8(void) ;

extern s32 D_800D1A90[10];
extern u8 D_800D2660[32];
extern u32 D_80091A24;
extern u32 D_80091A28;
void Audio_ResetQueueAndBitmap(void) ;

extern u16 D_80090BA0;
extern u8 D_800D2650[];
void func_8002A7A8(s32 arg0, s32 arg1) ;

extern s8 D_80091A0C;

void func_8002A7E8(s32 arg0) ;

extern s8 D_80091A10;

void func_8002A80C(s32 arg0) ;

extern s32 D_800D2630;

void func_8002A9C0(s32 arg0) ;

extern s32 D_800D2634;

void func_8002A9CC(s32 arg0) ;

extern u8 *D_800D1B78[];
extern u8 *D_800D1B80[];
extern char D_800A3A60[];
extern char D_800A3A6C[];
extern char D_800A3A84[];
extern char D_800A3A94[];
extern char D_800A3AA4[];
void func_8002A9D8(void) ;

extern s8 D_80091A18;
void func_8002AAD0(u8 arg0) ;

extern void func_8002A25C();
extern void func_80024180();
void func_8002B1A0(void) ;

extern void func_80023A3C(s32, s32, s32);
extern void func_8002AAFC(s32);
extern void func_800314D4(s32);

void func_8002B43C(void) ;

extern s32 D_80091B08, D_80091B0C;
void func_8002B47C(s32 arg0, s32 arg1) ;

extern u8 D_80091AC8;
extern u8 D_800D1B3B;
extern u32 D_800D2640[];
extern u8 D_800D269E[];
extern u8 D_80091F00[];
extern u8 D_80091EF8[];
extern u8 D_80091EEC[];
void Audio_RequestSlot(u8 slot) ;

extern u32 D_80091A2C;
extern s16 D_800D1AB8[];
void func_8002C2A0(unsigned short arg0)
;

extern u32 D_80091A24;
extern s32 D_800D1A90[];
extern s8 D_80091A0C;
extern s8 D_80091A10;
void func_800314D4(s32 arg0) ;

void func_80031530(u16 a) ;

void func_80031530_padding(void) ;

extern u8 D_80091A1C;
extern u32 D_80091A20;
extern u32 D_80091A30;
extern u8 D_80091A34;
extern u8 D_80091A44;
typedef struct { u8 unk00[38]; u16 unk26; } unk_D_800D1B88;
extern unk_D_800D1B88 *D_800D1B88[2];
extern s32 func_80019230(s32, s32, s32);
// Service queued sound/wait commands and the enabled timed command sequence.
void Audio_UpdateCommandQueue(void) ;

extern u8 D_800D1B90[];
void func_80031844(s32 arg0, s32 arg1) ;

void func_80031880(s32 arg0, s32 arg1) ;

s32 func_80019230(s32, s32, s32);

s32 func_800318C8(void) ;

typedef struct { u8 *ptr; u8 value; u8 pad; u16 limit; } Func31Entry;
extern Func31Entry D_800D27C0[];
// Registers 0xFF10 through 0xFF3F alternate value and write-flag bytes.
// GbAudio_QueueRegisterWrite marks the byte following each written value.
typedef struct {
    u8 unk00; u8 unk01; u8 unk02; u8 unk03;
    u8 unk04; u8 unk05; u8 unk06; u8 unk07;
    u8 unk08; u8 unk09; u8 unk0A; u8 unk0B;
    u8 unkC; u8 unkD; u8 unkE; u8 unkF;
    u8 unk10; u8 unk11; u8 unk12; u8 unk13;
    u8 unk14; u8 unk15; u8 unk16; u8 unk17;
    u8 unk18; u8 unk19; u8 unk1A; u8 unk1B;
    u8 unk1C; u8 unk1D; u8 unk1E; u8 unk1F;
    u8 unk20; u8 unk21; u8 unk22; u8 unk23;
    u8 unk24; u8 unk25; u8 unk26; u8 unk27;
    u8 unk28; u8 unk29; u8 unk2A; u8 unk2B;
    u8 unk2C; u8 unk2D;
    u8 unk2E[50];
} AudioConfig;
extern AudioConfig D_800D2760;
extern u32 D_800D2AE4;
extern u8 D_800D2AD8[];
void GbAudio_QueueRegisterWrite(u16 address, u8 value, u16 delay) ;

u8 GbAudio_GetRegisterValue(u16 arg0)
;

typedef struct {
    u32 unk0;
    s16 unk4;
    s16 unk6;
    u32 unk8;
    u32 unkC;
    u16 duty_ticks[2];
    s16 unk14;
    u8 unk16;
    u8 unk17;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u8 unk24;
} AudioState;
extern AudioState D_800D26E8;
extern u32 D_800D275C;

extern s32 D_800D2AE0;
void func_80031E6C(u16 arg0) ;

// GB sound-register mirror: each register value is followed by a dirty byte.
#define GB_PULSE2_REG(n) (((u8 *)&D_800D2760)[(n) * 2])
#define GB_PULSE2_DIRTY(n) (((u8 *)&D_800D2760)[(n) * 2 + 1])
s16 GbAudio_RenderPulse2(void) ;

extern u8 D_800D2B78;
void func_80032E40(u8 arg0) ;

extern u8 D_800D2B40;
extern u8 D_800D2B46;
extern u8 D_800D2B47;
extern u8 D_800D2B48;
extern u8 D_800D2B4A;
extern u8 D_800D2B4E;
extern u8 D_800D2B54;
extern u8 D_800D2B55;
extern u8 D_800D2B56;
extern u8 D_800D2B57;
extern u8 D_800D2B58;
extern u8 D_800D2B59;
extern u8 D_800D2B5A;
extern u8 D_800D2B5E;
extern u8 D_800D2B5F;
extern u8 D_800D2B62;
extern u8 D_800D2B68;
extern u8 D_800D2B69;
extern u8 D_800D2B6A;
extern u8 D_800D2B6B;
extern u8 D_800D2B6C;
extern u8 D_800D2B6D;
extern u8 D_800D2B6E;
extern u8 D_800D2B6F;
extern u8 D_800D2B73;
extern u16 D_800D2B44;
extern u16 D_800D2B4C;
extern u16 D_800D2B5C;
extern u16 D_800D2B60;
extern u16 D_800D2B64;
extern u16 D_800D2B66;
extern s8 D_800D2B42;
extern u8 D_800D2B43;
extern s8 D_800D2B4B;
extern u32 D_800D2B50;
extern u8 D_800D2B70[3];
extern u8 D_800D2B49;
extern void func_800331C8(void);
extern void func_800331B8(void);
extern void func_80032E40(u8);
// Reset hardware registers and software channels while frame updates are disabled.
void GbAudio_ResetState(void) ;

extern u16 D_800D2B5C;
extern void GbAudio_ResetState(void);
void func_80033188(void) ;

extern u8 D_800D2B41; void func_800331B8(void) ;

extern u8 D_800D2B41; void func_800331C8(void) ;

typedef struct GbAudioStreamRecord {
    s16 unk_00;
    u8 unk_02;
    u8 flags_03;
    u8 flags_04;
    u8 unk_05[15];
    u8 flags_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E[6];
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
    u8 unk_27;
    u8 unk_28[20];
} GbAudioStreamRecord;

void GbAudio_UpdateChannelIfEnabled(u8 channel) ;

extern void GbAudio_QueueRegisterWrite(u16, u8, u16);
extern u8 GbAudio_GetRegisterValue(u16);
extern void GbAudio_QueueChannelReset(u16);
extern s8 D_800D2B42;
extern u8 D_800D2B43;
extern u16 D_800D2B44;
extern s8 D_800D2B4B;
extern u8 D_800D2B78;
void GbAudio_UpdateSquare1Registers(u8 channel) ;

extern void GbAudio_UpdateSquare2Registers(u8);
extern void func_80033864(s32);
extern void GbAudio_UpdateNoiseRegisters(u8);
void func_8003364C(s32 arg0) ;

extern void GbAudio_QueueRegisterWrite(u16, u8, u16);
extern u8 GbAudio_GetRegisterValue(u16);
extern void GbAudio_QueueChannelReset(u16);
extern s8 D_800D2B42;
extern u8 D_800D2B43;
extern u16 D_800D2B44;
extern u8 D_800D2B8C;
void GbAudio_UpdateSquare2Registers(u8 channel)
;

void func_800337D8(s32 arg0) ;

extern void GbAudio_QueueRegisterWrite(u16, u8, u16);
extern u8 D_800D2B43;
void func_800337FC(void) ;

void func_80033864(s32 arg0) ;

void func_8003386C(s32 arg0) ;

extern u8 D_800D2B8C;
extern void GbAudio_QueueChannelReset(u16);
void GbAudio_UpdateNoiseRegisters(u8 channel) ;

void func_800339DC(u8 arg0) ;

void func_800339E4(void) ;

extern void func_80033B04(u8);
extern void func_80033A78(u8 arg0);
extern void func_80033ACC(u8 arg0);
extern u8 D_800D2B78;
void func_800339EC(u8 arg0) ;

extern s8 D_800D2B42;
extern u8 D_800D2B78;
void func_80033A78(u8 arg0) ;

void func_80033ACC(u8 arg0) ;

extern void func_80033C40(s32);
void func_80033BF4(u8 index) ;

void func_80033C40(s32 arg0) ;

void func_80033C48(s32 arg0) ;

void func_80033C50(s32 arg0) ;

extern u8 D_800D2B49;
extern u8 D_800D2B68;
extern u8 D_800D2B6A;
void func_80033C58(u8 arg0) ;

extern u8 D_800D2B78;
extern u8 D_800D2C6B;
extern u8 func_800347E8(u8);
extern void func_80033ED8(u8, u8);
extern void GbAudio_ReadChannelParameters(u8, u8);
extern void func_80033ED0(void);
extern void func_800348C4(u8, u8);
extern s32 func_80034838(u8, u8, u8);
extern void func_800339DC(u8);
void GbAudio_ProcessChannelStream(u8 channel) ;

extern void func_800348C4(u8, u8);
extern u8 func_800347E8(u8 arg0);
void GbAudio_ReadChannelParameters(u8 channel, u8 value) ;

void func_80033ED0(void) ;

extern void (*D_800921E4[])(u8, u8);
void func_80033ED8(u8 a, u8 b) ;

void func_80033F14(s32 arg0, s32 arg1) ;

void func_80033F20(u8 arg0, u8 arg1) ;

void func_80033F5C(s32 arg0, s32 arg1) ;

void func_80033F68(s32 arg0, s32 arg1) ;

u8 func_800347E8(u8);
extern u8 D_800D2B8D;

void func_80034058(u8 arg0, s32 arg1) ;

void func_80034098(s32 arg0, s32 arg1) ;

void func_800340A4(s32 arg0, s32 arg1) ;

extern u8 D_800D2B69;
void func_800340B0(s32 arg0, s32 arg1) ;

extern u8 func_800347E8(u8);
extern u8 D_800D2B78;
void func_800340C8(u8 arg0, s32 arg1) ;

extern u8 func_800347E8(u8);
extern u8 D_800D2B78;
void GbAudio_ReadPackedChannelParameters(u8 channel, u8 high) ;

void func_800341BC(s32 arg0, s32 arg1) ;

typedef struct {
    u8 prefix[4];
    u8 flags;
    u8 unknown05[0x2B];
    u16 value;
    u8 unknown32[0xA];
} ChannelWordRecord;
void AudioSeq_ReadWordParameter(u8 channel, s32 unused) ;

extern u8 func_800347E8(u8);
extern u8 D_800D2B78;
void func_80034238(unsigned char arg0, s32 arg1)
;

void func_8003428C(u8 index, s32 unused) ;

extern u8 func_800347E8(u8);
extern u8 D_800D2B78;
void func_800342F4(char arg0, s32 arg1)
;

extern u8 D_800D2B78;
void func_80034348(u8 arg0, s32 arg1) ;

extern u8 D_800D2B56;
extern u8 D_800D2B78;
void func_80034394(u8 arg0, s32 arg1) ;

extern u8 D_800D2B57;
extern u8 D_800D2B78;
void func_800343FC(u8 arg0, s32 arg1) ;

extern void func_8003455C(u8, s32);
extern u8 D_800D2BAE[];
void func_80034464(u8 arg0, u8 arg1) ;

extern s8 D_800D2B4B;

void func_800344C4(u8 arg0, s32 arg1) ;

extern u8 D_800D2B8E;
void func_80034518(u8 arg0, s32 arg1)
;

u8 func_800347E8(u8);
extern u8 D_800D2B8F;

void func_8003455C(u8 arg0, s32 arg1) ;

extern void func_8003492C(u8, u16);
void func_8003459C(u8 arg0, s32 arg1) ;

extern u8 D_800D2B93[];
void func_800345E8(s32 arg0, s32 arg1) ;

u8 func_800347E8(u8);
extern u8 D_800D2B94;

void func_80034614(u8 arg0, s32 arg1) ;

extern u8 D_80092520;
extern void func_800346A4(u8, u8);
void func_80034654(u8 arg0, u8 arg1) ;

extern u8 D_800D2B78;
void func_800346A4(u8 arg0, u8 arg1) ;

extern u8 D_800D2B59;
extern u8 D_800D2B49;
void func_800346F8(u8 arg0, s32 arg1) ;

extern u16 D_800D2B9A;
void func_8003492C(u8, u16);
extern u8 func_800347E8(u8 arg0);
void func_80034738(u8 arg0, s32 arg1) ;

extern u8 D_800D2B6A;
void func_800347A4(s32 arg0, s32 arg1) ;

void func_800347BC(s32 arg0, s32 arg1) ;

void func_800347D0(s32 arg0, s32 arg1) ;

void func_800347DC(s32 arg0, s32 arg1) ;

extern u8 func_80034D98(const u8 *);
u8 func_800347E8(u8 arg0) ;

extern u8 D_800D2B78;
void func_800348C4(u8 arg0, u8 arg1)
;

extern u8 D_800D2B78;
void func_8003492C(u8 arg0, u16 arg1) ;

extern void func_80034A50(u8);
void func_80034A08(u8 arg0) ;

extern u8 D_800D2B9C[];
extern u8 * func_80034DA0(void);
void func_80034A50(u8 arg0) ;

extern u16 D_800D2B4C;

void func_80034A94(u16 arg0) ;

extern const u8 *D_80094454[];
extern u8 GbAudio_StartSequenceChannel(const u8 *command);
extern u8 func_80034CF8(const u8 *arg0);
extern u8 D_800D2B49;
extern u8 D_800D2B68;
extern u8 D_800D2B6A;
extern u8 D_800D2B78;
void GbAudio_StartSequence(u16 sequence, u16 parameter, u16 volume)
;

void func_80034C48(s32 arg0) ;

void func_80034C50(s32 arg0) ;

extern u8 D_800D2B4E;
extern u8 func_80034CF8(const u8 *arg0);
u8 GbAudio_StartSequenceChannel(const u8 *command) ;

u8 func_80034CF8(const u8 *arg0) ;

void GbAudio_QueueChannelReset(u16 address) ;

u8 func_80034D98(const u8 *arg0) ;

extern u8 D_80092520; extern u8 D_800925E4[]; extern u8 D_800925E8[]; u8 *func_80034DA0(void) ;

extern void GbAudio_ResetState(void); void func_80034DD0(void) ;

extern void func_800331D4(void); void func_80034DF0(void) ;

u8 func_80034E10(const u8 *arg0, s32 unused) ;

extern void GbAudio_ResetState(void);
extern void func_80034A94(u16 arg0);
void func_80034E1C(u16 arg0) ;

typedef struct Func80034E5CRecord {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    u16 unk4;
} Func80034E5CRecord;
extern Func80034E5CRecord D_80092620[];
extern void GbAudio_StartSequence(u16, u16, u16);
void func_80034E5C(s32 arg0, s32 arg1)
;

void func_80034EA4(void) ;

void func_80034EB4(void) ;

extern u8 D_800D2B49; void func_80034EC4(void) ;

void func_80034ED0(void) ;

void func_80034EE0(void) ;

void func_80034EF0(s32 arg0)
;

u8 GbAudio_GetActiveChannelMask(void) ;

extern s32 D_80094570;

void func_80034FE0(void) ;

extern OSMesgQueue D_800D2D60;
extern OSPiHandle *D_800D2D78;
extern void *D_800D2D7C;
void func_80035020(s32 arg0) ;

extern OSMesgQueue D_800D2D60;
extern OSPiHandle *D_800D2D78;
void Audio_ReadRomBlocking(u32 rom, u8 *destination, u32 remaining) ;

extern s32 D_80094850; void func_80035140(s32 value) ;

s32 func_8003514C(void) ;

extern s32 D_80094870[];
s32 func_80035160(s32 index) ;

typedef struct {
    OSMesg message;
    OSMesgQueue queue;
    u16 unknown1C;
    u16 unknown1E;
    OSTask task;
    u8 unknown60[8];
} AudioThreadTaskBuffer;
extern AudioThreadTaskBuffer D_80122A48[2];
extern OSThread D_80122B20;
extern s32 D_80122A40;
extern s32 D_80122B18;
extern u32 D_800CD020[];
extern s32 D_8009486C;
extern void __osSetFpcCsr(s32);
extern void Sched_InitClientQueue(void *, s32, s32);
extern void func_80005568(void *);
extern OSMesg func_80004F34(u8 *);
extern void profiler_log_thread4_time(void);
extern void Audio_InitializeTaskState(void);
extern s32 Audio_BuildSchedulerTask(void);
extern void Sched_SubmitTask(void *, s32);
extern OSMesgQueue D_80122A4C;
extern OSMesgQueue D_80122AB4;
extern OSMesg D_80122AB0;

void Audio_ThreadMain(void *unused) ;

extern void Audio_ThreadMain(void *);
extern OSThread D_80122B20;
extern u8 D_80124D00[];
void Thread4_CreateThread(void) ;

extern void func_80021BBC(void);
void func_8003539C(void) ;

extern s32 func_80025C9C(void);
extern s32 D_80122A40;
s32 Audio_StopProcessing(void) ;

extern s32 func_80025D44(void);
s32 Audio_WaitForPendingTasks(void) ;

extern void *func_80008494();
void func_80035424(s32 arg0) ;

void Audio_SetProcessingEnabled(s32 enabled) ;

extern s32 D_80094860;
void Audio_ResetModeSelector(void) ;

extern s32 D_80094868;
void Audio_EnableModeFlag(void) ;

extern void func_800260C0(s32, s32, s32);
extern void func_800262F0(void);
s32 Audio_SetModeBlocking(s32 mode, s32 arg1, s32 arg2) ;

extern s32 D_80094864;
void Audio_ResetRequestId(void) ;

s32 Audio_RequestIfChanged(s32 requestId) ;

s32 func_800356CC(s32 arg0) ;

extern u32 D_80124D50;
void func_80035700(u32 seed) ;

u32 func_8003570C(void) ;

typedef struct { u8 r, g, b, a; } Color3573C;
Color3573C *Color_SetRGB(Color3573C *arg0, u8 r, u8 g, u8 b) ;

typedef struct { u8 r, g, b, a; } Color3575C;
Color3575C *Color_SetRGBA(Color3575C *arg0, u8 r, u8 g, u8 b, u8 a) ;

typedef struct { f32 x, y, z; } Vec3f35784;
Vec3f35784 *Vec3f_SetComponents(Vec3f35784 *arg0, f32 x, f32 y, f32 z) ;

typedef Vec3f35784 Vec3f357A8;
Vec3f357A8 *Vec3f_SetComponentsDuplicate(Vec3f357A8 *arg0, f32 x, f32 y, f32 z) ;

typedef struct { f32 x, y, z; } Vec3f357CC;
Vec3f357CC *Vec3f_AddInPlace(Vec3f357CC *arg0, Vec3f357CC *arg1) ;

typedef struct { f32 x, y, z; } Vec3f35804;
Vec3f35804 *Vec3f_Add(Vec3f35804 *arg0, Vec3f35804 *arg1, Vec3f35804 *arg2) ;

typedef struct { f32 x, y, z; } Vec3f3583C;
Vec3f3583C *Vec3f_SubtractInPlace(Vec3f3583C *arg0, Vec3f3583C *arg1) ;

typedef struct { f32 x, y, z; } Vec3f35874;
Vec3f35874 *Vec3f_Subtract(Vec3f35874 *arg0, Vec3f35874 *arg1, Vec3f35874 *arg2) ;

typedef struct { f32 x, y, z; } Vec3f358AC;
typedef struct { s16 x, y, z; } Vec3s358AC;
Vec3f358AC *Vec3f_FromVec3s(Vec3f358AC *arg0, Vec3s358AC *arg1) ;

typedef struct { f32 x, y, z; } Vec3f358F0;
Vec3f358F0 *Vec3f_CrossProductFromPoints(Vec3f358F0 *arg0, Vec3f358F0 *arg1, Vec3f358F0 *arg2, Vec3f358F0 *arg3) ;

typedef Vec3f35784 Vec3f359A0;

Vec3f359A0 *Vec3f_CrossProduct(Vec3f359A0 *out, Vec3f359A0 *a, Vec3f359A0 *b) ;

typedef Vec3f35784 Vec3f35A10;
Vec3f35A10 *func_80035A10(Vec3f35A10 *arg0) ;

void *Vec3s_SetComponents(void *arg0, s16 arg1, s16 arg2, s16 arg3) ;

typedef struct { s16 x, y, z; } Vec3s35AA0;
Vec3s35AA0 *Vec3s_AddInPlace(Vec3s35AA0 *arg0, Vec3s35AA0 *arg1) ;

typedef struct { s16 x, y, z; } Vec3s35AD8;
Vec3s35AD8 *Vec3s_Add(Vec3s35AD8 *arg0, Vec3s35AD8 *arg1, Vec3s35AD8 *arg2) ;

typedef struct { s16 x, y, z; } Vec3s35B10;
Vec3s35B10 *Vec3s_SubtractInPlace(Vec3s35B10 *arg0, Vec3s35B10 *arg1) ;

typedef struct { s16 x, y, z; } Vec3s35B48;
Vec3s35B48 *Vec3s_Subtract(Vec3s35B48 *arg0, Vec3s35B48 *arg1, Vec3s35B48 *arg2) ;

#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
typedef struct { s16 x, y, z; } Vec3s35B80;
typedef struct { f32 x, y, z; } Vec3f35B80;
Vec3s35B80 *Vec3s_FromVec3f(Vec3s35B80 *arg0, Vec3f35B80 *arg1) ;

void MtxF_Copy(u32 *dest, u32 *src) ;

void MtxF_Identity(f32 *arg0) ;

extern void MtxF_Identity(f32 *arg0);
void MtxF_SetTranslation(f32 *dest, f32 *source) ;

typedef struct S1_Vec3s S1_Vec3s;
struct S1_Vec3s {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
};
typedef float S1_MtxF_t[4][4];
typedef union {
    S1_MtxF_t mf;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} S1_MtxF;
typedef struct S1_Vec3f S1_Vec3f;
struct S1_Vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
};

extern f32 D_80087E50[];
extern f32 D_80088E50[0x1000];
void MtxF_SetLookAt(S1_MtxF *matrix, S1_Vec3f *from, S1_Vec3f *to, s16 view_angle) ;

void MtxF_SetRotationTranslation(f32 matrix[4][4], Vec3s35AA0 *position, Vec3s35AA0 *rotation) ;

void MtxF_SetRotationTranslationF(f32 matrix[4][4], Vec3f35784 *position, Vec3s35AA0 *rotation) ;

void MtxF_SetRotationAndTransformTranslation(f32 matrix[4][4], Vec3f35784 *position, Vec3s35AA0 *rotation) ;

void MtxF_SetRotationScaleTranslation(S1_MtxF *matrix, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) ;

void MtxF_SetRotationAndScaledTranslation(S1_MtxF *matrix, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) ;

void func_80036714(void *a0,s32 a1,s32 a2,s32 a3,f32 a4);

void MtxF_SetOrthonormalBasis(f32 matrix[4][4], Vec3f35784 *up_direction, Vec3f35784 *position, s32 rotation_y) ;

extern f32 D_80087E50[];
extern f32 D_80088E50[0x1000];
extern S1_Vec3f D_800948D0;
typedef union S1_Vec2s_s32 S1_Vec2s_s32;
union S1_Vec2s_s32 {
    struct {
        /* 0x0 */ s16 x;
        /* 0x2 */ s16 y;
    };
    s32 xy;
};
typedef union S1_Color_RGBA8_u32 S1_Color_RGBA8_u32;
union S1_Color_RGBA8_u32 {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
};
typedef struct S1_GraphNode S1_GraphNode;
typedef struct S1_unk_D_86002F34_00C S1_unk_D_86002F34_00C;
typedef struct S1_unk_D_86002F34_00C_040 S1_unk_D_86002F34_00C_040;
typedef struct S1_unk_D_86002F34_00C_0CC S1_unk_D_86002F34_00C_0CC;
typedef struct S1_unk_D_86002F34_00C_060 S1_unk_D_86002F34_00C_060;
typedef struct S1_unk_D_86002F34_00C_024 S1_unk_D_86002F34_00C_024;
typedef struct S1_unk_D_86002F34_00C_018 S1_unk_D_86002F34_00C_018;
typedef s32 (*S1_func_D_86002F34_000_010)(s32, struct S1_GraphNode*);
extern void *func_80003240();
struct S1_GraphNode {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ struct S1_GraphNode* unk_04;
    /* 0x08 */ struct S1_GraphNode* unk_08;
    /* 0x0C */ struct S1_unk_D_86002F34_00C* unk_0C;
    /* 0x10 */ S1_func_D_86002F34_000_010 unk_10;
    /* 0x14 */ void* unk_14;
};
struct S1_unk_D_86002F34_00C_040 {
    /* 0x00 */ Mtx* mtx;
    /* 0x04 */ f32 l;
    /* 0x08 */ f32 r;
    /* 0x0C */ f32 b;
    /* 0x10 */ f32 t;
    /* 0x14 */ f32 n;
    /* 0x18 */ f32 f;
    /* 0x1C */ f32 scale;
};
struct S1_unk_D_86002F34_00C_0CC {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ S1_Color_RGBA8_u32 color;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ u8* texture;
};
struct S1_unk_D_86002F34_00C_024 {
    /* 0x00 */ Mtx* mtx;
    /* 0x04 */ u16 perspNorm;
    /* 0x08 */ f32 fovy;
    /* 0x0C */ f32 aspect;
    /* 0x10 */ f32 near;
    /* 0x14 */ f32 far;
    /* 0x18 */ f32 scale;
};
struct S1_unk_D_86002F34_00C_060 {
    /* 0x00 */ S1_MtxF* p_mtxf;
    /* 0x04 */ S1_MtxF mtxf;
    /* 0x44 */ LookAt* lookat;
    /* 0x48 */ S1_Vec3f eye;
    /* 0x54 */ S1_Vec3f at;
    /* 0x60 */ S1_Vec3f up;
};
struct S1_unk_D_86002F34_00C_018 {
    /* 0x00 */ Vp* vp;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 width;
    /* 0x0A */ s16 height;
};
struct S1_unk_D_86002F34_00C {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ S1_unk_D_86002F34_00C_018 unk_18;	//	viewPort
    /* 0x24 */ S1_unk_D_86002F34_00C_024 unk_24;	//	projection
    /* 0x40 */ S1_unk_D_86002F34_00C_040 unk_40;
    /* 0x60 */ S1_unk_D_86002F34_00C_060 unk_60;	//	camera
    /* 0xCC */ S1_unk_D_86002F34_00C_0CC unk_CC;
    /* 0xEC */ char unkEC[0x4];
};
extern Vtx *GeoOverlay_BuildFadeQuad(S1_unk_D_86002F34_00C_0CC *, S1_unk_D_86002F34_00C_040 *);
typedef struct S1_MainPoolState S1_MainPoolState;
typedef struct S1_MainPoolBlock S1_MainPoolBlock;
struct S1_MainPoolState {
    /* 0x00 */ s32 freeSpace;
    /* 0x04 */ S1_MainPoolBlock *listHeadL;
    /* 0x08 */ S1_MainPoolBlock *listHeadR;
    /* 0x0C */ struct S1_MainPoolState *prev;
};
typedef void (*S1_AllocateFunc)(struct S1_MainPoolBlock*, u32);
struct S1_MainPoolBlock {
    /* 0x00 */ struct S1_MainPoolBlock *prev;
    /* 0x04 */ struct S1_MainPoolBlock *next;
    /* 0x08 */ S1_AllocateFunc func;
    /* 0x0C */ s32 arg; // passed into func as the 2nd argument.
};
typedef struct S1_unk_D_86002F34_alt2 S1_unk_D_86002F34_alt2;
struct S1_unk_D_86002F34_alt2 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ S1_GraphNode* unk_18;
};
typedef struct S1_MemoryBlock S1_MemoryBlock;
struct S1_MemoryBlock {
    /* 0x00 */ struct S1_MemoryBlock *next;
    /* 0x04 */ u32 size;
};
typedef struct S1_unk_D_86002F34_alt13 S1_unk_D_86002F34_alt13;
struct S1_unk_D_86002F34_alt13 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
};
typedef struct S1_unk_D_86002F34_alt1 S1_unk_D_86002F34_alt1;
struct S1_unk_D_86002F34_alt1 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ s8 unk_1C;
    /* 0x1D */ s8 unk_1D;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ Lights7* lights;
};
typedef struct S1_unk_D_86002F34_alt14 S1_unk_D_86002F34_alt14;
struct S1_unk_D_86002F34_alt14 {
    /* 0x00 */ S1_GraphNode unk_00;
};
typedef struct S1_unk_D_86002F34_alt15 S1_unk_D_86002F34_alt15;
struct S1_unk_D_86002F34_alt15 {
    /* 0x00 */ S1_GraphNode unk_00;
};
typedef struct S1_unk_D_86002F34_alt16 S1_unk_D_86002F34_alt16;
struct S1_unk_D_86002F34_alt16 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ u32 unk_18;
};
typedef struct S1_unk_D_8690A610 S1_unk_D_8690A610;
typedef struct S1_unk_D_8690A610_018 S1_unk_D_8690A610_018;
typedef struct S1_unk_D_86002F58_004_000_000 S1_unk_D_86002F58_004_000_000;
typedef struct S1_unk_D_86002F58_004_000_00C S1_unk_D_86002F58_004_000_00C;
typedef struct S1_unk_D_86002F58_004_000_010 S1_unk_D_86002F58_004_000_010;
typedef struct S1_unk_D_86002F58_004_000_010_024 S1_unk_D_86002F58_004_000_010_024;
typedef union S1_arg1_func_80010CA8 S1_arg1_func_80010CA8;
typedef struct S1_unk_D_86002F58_004_000_004 S1_unk_D_86002F58_004_000_004;
typedef struct S1_unk_D_86002F58_004_000_00C_028 S1_unk_D_86002F58_004_000_00C_028;
struct S1_unk_D_8690A610_018 {
    /* 0x00 */ s16 fogNear; // GeoNode_CreateFog's arg2
    /* 0x02 */ s16 fogFar; // GeoNode_CreateFog's arg3
    /* 0x04 */ S1_Color_RGBA8_u32 fogColor;
};
struct S1_unk_D_86002F58_004_000_000 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ struct S1_unk_D_86002F58_004_000_000* unk_04;
    /* 0x08 */ struct S1_unk_D_86002F58_004_000_000* unk_08;
    /* 0x0C */ S1_unk_D_86002F58_004_000_00C* unk_0C;
    /* 0x10 */ S1_unk_D_86002F58_004_000_010* unk_10;
    /* 0x14 */ s32 unk_14;
};
struct S1_unk_D_8690A610 {
    /* 0x00 */ S1_unk_D_86002F58_004_000_000 unk_00;
    /* 0x18 */ S1_unk_D_8690A610_018 unk_18;
};
struct S1_unk_D_86002F58_004_000_004 {
    /* 0x00 */ struct S1_unk_D_86002F58_004_000_004* unk_00[4];
    /* 0x10 */ struct S1_unk_D_86002F58_004_000_00C* unk_10;
    /* 0x14 */ S1_unk_D_86002F58_004_000_010* unk_14;
};
typedef S1_unk_D_86002F58_004_000_00C_028* (*S1_unk_D_86002F58_004_000_00C_028_func)(s32, s32);
struct S1_unk_D_86002F58_004_000_00C {
    /* 0x00 */ S1_unk_D_86002F58_004_000_004 unk_00;
    /* 0x18 */ char unk_18[0x10];
    /* 0x28 */ S1_unk_D_86002F58_004_000_00C_028_func unk_28;
};
union S1_arg1_func_80010CA8 {
    struct {
        /* 0x00 */ s16 unk_00;
        /* 0x02 */ s8 unk_02;
        /* 0x03 */ s8 unk_03;
    };
    u32 raw;
};
struct S1_unk_D_86002F58_004_000_010 {
    /* 0x00 */ u8 configFlags; // PokeIcon_AllocFramebuffers's arg0: bit0=frame-load enabled, bit1=background-load enabled, bit2=double-buffered, bit3=quad-buffered
    /* 0x01 */ u8 pendingFlags; // bit0=frame load pending, bit1=background load pending (PokeIcon_RequestFrameLoad/RequestBackgroundLoad/ApplyLoadResult)
    /* 0x02 */ u8 activeVariant; // index into framebuffers[], flipped by configFlags bit2 in PokeIcon_RequestFrameLoad
    /* 0x04 */ s32 framebuffers[1]; // declared size undersells - up to 5 entries when configFlags bit3 is set (PokeIcon_AllocFramebuffers)
    /* 0x08 */ char pad8[0x10];
    /* 0x18 */ s32 backgroundBuffer; // PokeIcon_RequestBackgroundLoad's poolPtr
    /* 0x1C */ s32 frameResultSize; // PokeIcon_ApplyLoadResult's case 1: poolSize
    /* 0x20 */ s32 backgroundResultSize; // case 2: poolSize
    /* 0x24 */ S1_unk_D_86002F58_004_000_010_024* lastLoadedFragment; // case 1: result; PokeIcon_RequestFrameLoad reuses the load if this matches the requested species
    /* 0x28 */ s32 backgroundResult; // case 2: result
    /* 0x2C */ S1_arg1_func_80010CA8 colorAdjust; // cached alongside lastLoadedFragment for the reuse check
    /* 0x30 */ OSMesgQueue frameQueue;
    /* 0x48 */ OSMesg frameMsgBuf;
    /* 0x4C */ char pad4C[0x4];
    /* 0x50 */ OSMesgQueue backgroundQueue;
    /* 0x68 */ OSMesg backgroundMsgBuf;
    /* 0x6C */ char pad6C[0x4];
};
struct S1_unk_D_86002F58_004_000_010_024 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk02[0x6];
    /* 0x08 */ struct S1_unk_D_86002F58_004_000_004* unk_08;
};
struct S1_unk_D_86002F58_004_000_00C_028 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char pad6[6];
    /* 0x0C */ s32* unk_0C;
    /* 0x10 */ s32* unk_10;
};
typedef struct S1_unk_D_86002F34_alt19 S1_unk_D_86002F34_alt19;
struct S1_unk_D_86002F34_alt19 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ u8 r;
    /* 0x19 */ u8 g;
    /* 0x1A */ u8 b;
};
typedef struct S1_unk_D_86002F34_alt12 S1_unk_D_86002F34_alt12;
struct S1_unk_D_86002F34_alt12 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
};
typedef struct S1_unk_D_86002F34_alt20 S1_unk_D_86002F34_alt20;
struct S1_unk_D_86002F34_alt20 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
};
typedef struct S1_unk_D_86002F34_alt21 S1_unk_D_86002F34_alt21;
struct S1_unk_D_86002F34_alt21 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
};
typedef struct S1_unk_D_86002F34_alt5 S1_unk_D_86002F34_alt5;
struct S1_unk_D_86002F34_alt5 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ S1_Vec3f unk_18;
    /* 0x24 */ S1_Vec3s unk_24;
};
typedef struct S1_unk_D_86002F34_alt22 S1_unk_D_86002F34_alt22;
struct S1_unk_D_86002F34_alt22 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ S1_Vec3f unk_18;
};
typedef struct S1_unk_D_86002F34_alt6 S1_unk_D_86002F34_alt6;
struct S1_unk_D_86002F34_alt6 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ S1_Vec3s unk_18;
    /* 0x1E */ S1_Vec3s unk_1E;
    /* 0x24 */ S1_Vec3f unk_24;
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ u8 unk_31;
    /* 0x32 */ s16 unk_32;
};
typedef struct S1_unk_D_86002F34_alt7 S1_unk_D_86002F34_alt7;
struct S1_unk_D_86002F34_alt7 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ s16 unk_1C;
};
typedef struct S1_unk_D_86002F34_alt8 S1_unk_D_86002F34_alt8;
struct S1_unk_D_86002F34_alt8 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ S1_MtxF unk_1C;
};
typedef struct S1_unk_D_86002F34_alt9 S1_unk_D_86002F34_alt9;
struct S1_unk_D_86002F34_alt9 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ S1_Vec3f unk_1C;
    /* 0x28 */ f32 unk_28;
};
typedef struct S1_unk_func_80011B94 S1_unk_func_80011B94;
struct S1_unk_func_80011B94 {
    /* 0x00 */ S1_unk_D_86002F58_004_000_000 unk_00;
    /* 0x18 */ Gfx* displayList; // GeoNode_CreateDisplayList's arg3
};
typedef struct S1_unk_D_86002F34_alt10 S1_unk_D_86002F34_alt10;
struct S1_unk_D_86002F34_alt10 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ Gfx* unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ u8 unk_22;
    /* 0x24 */ S1_Color_RGBA8_u32 unk_24;
};
typedef struct S1_unk_D_86002F34_alt23 S1_unk_D_86002F34_alt23;
struct S1_unk_D_86002F34_alt23 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
};
typedef struct S1_unk_D_86002F34_alt24 S1_unk_D_86002F34_alt24;
struct S1_unk_D_86002F34_alt24 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ S1_Color_RGBA8_u32 unk_28;
};
extern Gfx* D_800D0510;
extern Mtx D_80094890;
typedef struct S1_unk_D_86002F34_alt3 S1_unk_D_86002F34_alt3;
struct S1_unk_D_86002F34_alt3 {
    /* 0x00 */ S1_GraphNode unk_00;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s32 unk_1C;
};
typedef struct S1_unk_D_800ABCC0_008 S1_unk_D_800ABCC0_008;
typedef struct S1_unk_D_800ABCC0 S1_unk_D_800ABCC0;
typedef struct S1_unk_D_86002F58_004_000_040_004 S1_unk_D_86002F58_004_000_040_004;
struct S1_unk_D_800ABCC0_008 {
    /* 0x00 */ u8 translationKeyCount; // ModelAnim_EvaluateTranslationChannel: ==1 means a static (non-animated) value
    /* 0x01 */ u8 rotationKeyCount;
    /* 0x02 */ u8 scaleKeyCount;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 translationBaseIndex; // index into the context's translation value array
    /* 0x06 */ u16 rotationBaseIndex; // packed-bits index into the context's rotation value array
    /* 0x08 */ u16 scaleBaseIndex; // packed-bits index into the context's scale value array
};
struct S1_unk_D_800ABCC0 {
    /* 0x00 */ u8 isActive; // ModelAnim_BeginCurveContext: 1 when curveData != NULL, else 0
    /* 0x01 */ u8 flags; // mirrors curveData->unk_00; bit2 selects 16-bit vs 12-bit packed scale format
    /* 0x02 */ s16 currentFrame;
    /* 0x04 */ S1_unk_D_86002F58_004_000_040_004* curveData;
    /* 0x08 */ S1_unk_D_800ABCC0_008* channels; // per-joint-axis channel descriptors, indexed by ModelAnim_EvaluateJointTransform's arg3
    /* 0x0C */ s16* translationValues; // raw keyframe values, scaled by /1000.0f
    /* 0x10 */ s16* rotationValues; // PackedBits_ReadSigned source
    /* 0x14 */ s16* scaleValues; // PackedBits_ReadSigned source
};
struct S1_unk_D_86002F58_004_000_040_004 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk02[0x2];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
    /* 0x18 */ u32 unk_18;
};
typedef struct S1_unk_func_80016B30_arg0 S1_unk_func_80016B30_arg0;
struct S1_unk_func_80016B30_arg0 {
    /* 0x00 */ S1_Vec3s vec;
    /* 0x06 */ s16 unk_06;
};
typedef struct S1_unk_D_86002F58_004_000_040_raw S1_unk_D_86002F58_004_000_040_raw;
typedef union S1_unk_D_86002F58_004_000_040_raw_08 S1_unk_D_86002F58_004_000_040_raw_08;
union S1_unk_D_86002F58_004_000_040_raw_08 {
    struct {
        s16 unk_00;
        s16 unk_02;
    };
    s32 raw;
};
struct S1_unk_D_86002F58_004_000_040_raw {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ S1_unk_D_86002F58_004_000_040_004* unk_04;
    /* 0x08 */ S1_unk_D_86002F58_004_000_040_raw_08 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 unk_12;
};
typedef struct S1_unk_D_86002F58_004_000_040 S1_unk_D_86002F58_004_000_040;
typedef struct S1_unk_D_86002F58_004_000 S1_unk_D_86002F58_004_000;
typedef struct S1_unk_D_86002F58_004_000_054 S1_unk_D_86002F58_004_000_054;
typedef struct S1_unk_D_86002F58_004_000_0A8 S1_unk_D_86002F58_004_000_0A8;
typedef struct S1_unk_D_86002F58_004_000_054_004 S1_unk_D_86002F58_004_000_054_004;
struct S1_unk_D_86002F58_004_000_040 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ S1_unk_D_86002F58_004_000_040_004* unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ char unk10[0x2];
    /* 0x12 */ u16 unk_12;
};
struct S1_unk_D_86002F58_004_000_054 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ S1_unk_D_86002F58_004_000_054_004* unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ u16 unk_0A;
};
struct S1_unk_D_86002F58_004_000_0A8 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x04 */ S1_Vec3f unk_04;
};
struct S1_unk_D_86002F58_004_000 {
    /* 0x000 */ S1_unk_D_86002F58_004_000_000 unk_000;
    /* 0x018 */ s16 animType; // Model_InitDisplayObject's arg1
    /* 0x01A */ s16 modelId; // Model_InitDisplayObject's arg2; a species id in most battle-scene consumers
    /* 0x01C */ u8 textureMode; // Model_SetMaterialTextureMode
    /* 0x01D */ u8 materialAlpha; // Model_SetMaterialAlpha
    /* 0x01E */ S1_Vec3s unk_01E;			//	total Rotation
    /* 0x024 */ S1_Vec3f unk_024;			//	global Position
    /* 0x030 */ S1_Vec3f unk_030;			//	scale
    /* 0x03C */ S1_Color_RGBA8_u32 unk_03C;
    /* 0x040 */ S1_unk_D_86002F58_004_000_040 unk_040;
    /* 0x054 */ S1_unk_D_86002F58_004_000_054 unk_054;
    /* 0x060 */ S1_MtxF unk_060;
    /* 0x0A0 */ S1_Color_RGBA8_u32 unk_0A0;    //  vertex color ?
    /* 0x0A4 */ char unk0A4[2];
    /* 0x0A6 */ u8 poolIndex; // stable index into the shared displayObjectPool; GeoRender_RecordAnchorPosition/etc.
    /* 0x0A7 */ u8 anchorCount; // GeoRender_RecordAnchorPosition/FindAnchorPosition; caps at 0xC (12)
    /* 0x0A8 */ S1_unk_D_86002F58_004_000_0A8 anchors[1]; // declared size undersells - indexed up to anchorCount (max 12)
    /* 0x0B8 */ char unk0B8[0x24];
    /* 0x0DC */ S1_Vec3f unk_0DC;
    /* 0x0E0 */ char unk0E0[0x4];
    /* 0x0EC */ S1_Vec3f unk_0EC;
    /* 0x0F8 */ char unk0F8[0x4];
    /* 0x0FC */ S1_Vec3f unk_0FC;
    /* 0x108 */ char unk108[0x60];
};
struct S1_unk_D_86002F58_004_000_054_004 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ void* unk_10;
};
typedef unsigned int S1_uintptr_t;
typedef struct S1_unk_D_800ABE00_cmd8 S1_unk_D_800ABE00_cmd8;
typedef struct S1_unk_D_86002F34_000_014 S1_unk_D_86002F34_000_014;
struct S1_unk_D_800ABE00_cmd8 {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ S1_func_D_86002F34_000_010 callback; // func_80037E3C's arg1
    /* 0x08 */ S1_unk_D_86002F34_000_014* callbackData; // func_80037E3C's arg2
};
struct S1_unk_D_86002F34_000_014 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ u8* unk_04;
};
typedef struct S1_unk_D_800ABE00_cmd9 S1_unk_D_800ABE00_cmd9;
struct S1_unk_D_800ABE00_cmd9 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[3];
};
typedef struct S1_unk_D_800ABE00_cmdA S1_unk_D_800ABE00_cmdA;
struct S1_unk_D_800ABE00_cmdA {
    /* 0x00 */ u8 cmd;
    /* 0x04 */ S1_GraphNode* refNode; // GeoNode_CreateWithReference's arg1
};
typedef struct S1_unk_D_800ABE00_cmdB S1_unk_D_800ABE00_cmdB;
struct S1_unk_D_800ABE00_cmdB {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ u16 fovy;
    /* 0x04 */ u16 viewportX;
    /* 0x06 */ u16 viewportY;
    /* 0x08 */ s16 viewportWidth;
    /* 0x0A */ s16 viewportHeight;
    /* 0x0C */ S1_Vec3s lookAt;
    /* 0x12 */ s16 yaw;
    /* 0x14 */ s16 pitch;
    /* 0x16 */ s16 eyeDistance;
};
typedef struct S1_unk_D_800ABE00_cmdC S1_unk_D_800ABE00_cmdC;
struct S1_unk_D_800ABE00_cmdC {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
};
typedef struct S1_unk_D_800ABE00_cmdD S1_unk_D_800ABE00_cmdD;
struct S1_unk_D_800ABE00_cmdD {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
};
typedef struct S1_unk_D_800ABE00_cmdE S1_unk_D_800ABE00_cmdE;
struct S1_unk_D_800ABE00_cmdE {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
};
typedef struct S1_unk_D_800ABE00_cmdF S1_unk_D_800ABE00_cmdF;
struct S1_unk_D_800ABE00_cmdF {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 unk_02;
};
typedef struct S1_unk_D_800ABE00_cmd10 S1_unk_D_800ABE00_cmd10;
struct S1_unk_D_800ABE00_cmd10 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 r;
    /* 0x02 */ u8 g;
    /* 0x03 */ u8 b;
};
typedef struct S1_unk_D_800ABE00_cmd13 S1_unk_D_800ABE00_cmd13;
struct S1_unk_D_800ABE00_cmd13 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 r;
    /* 0x02 */ u8 g;
    /* 0x03 */ u8 b;
    /* 0x04 */ s16 fogNear;
    /* 0x06 */ s16 fogFar;
};
typedef struct S1_unk_D_800ABE00_cmd14 S1_unk_D_800ABE00_cmd14;
struct S1_unk_D_800ABE00_cmd14 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ s16 pitch; // GeoNode_CreateLight's arg2, scaled (val<<0xF)/180
    /* 0x06 */ s16 yaw; // GeoNode_CreateLight's arg3, scaled (val<<0xF)/180
    /* 0x08 */ u8 r;
    /* 0x09 */ u8 g;
    /* 0x0A */ u8 b;
    /* 0x0B */ u8 a;
};
typedef struct S1_unk_D_800ABE00_cmd18 S1_unk_D_800ABE00_cmd18;
struct S1_unk_D_800ABE00_cmd18 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
};
typedef struct S1_unk_D_800ABE00_cmd19 S1_unk_D_800ABE00_cmd19;
struct S1_unk_D_800ABE00_cmd19 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ s16 nearDistance; // Distance-cull node: children render only when nearDistance <= depth < farDistance
    /* 0x06 */ s16 farDistance;
};
typedef struct S1_unk_D_800ABE00_cmd1A S1_unk_D_800ABE00_cmd1A;
struct S1_unk_D_800ABE00_cmd1A {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s16 caseIndex; // Switch-case node: walks this many siblings from the first child before dispatching
};
typedef struct S1_unk_D_800ABE00_cmd1B S1_unk_D_800ABE00_cmd1B;
struct S1_unk_D_800ABE00_cmd1B {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ s16 rotX; // degrees, scaled (val<<0xF)/180
    /* 0x06 */ s16 rotY;
    /* 0x08 */ s16 rotZ;
    /* 0x0A */ S1_Vec3s translation;
};
typedef struct S1_unk_D_800ABE00_cmd1C S1_unk_D_800ABE00_cmd1C;
struct S1_unk_D_800ABE00_cmd1C {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ char pad[0x3];
    /* 0x04 */ u32 translateX; // Q16 fixed point, /65536.0f
    /* 0x08 */ u32 translateY;
    /* 0x0C */ u32 translateZ;
};
typedef struct S1_unk_D_800ABE00_cmd1D S1_unk_D_800ABE00_cmd1D;
struct S1_unk_D_800ABE00_cmd1D {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 partIndex; // GeoNode_CreateAnimatedPart's arg2
    /* 0x02 */ u8 flags; // bit0/bit1 remapped into GeoNode_CreateAnimatedPart's arg3
    /* 0x03 */ u8 animIndex; // GeoNode_CreateAnimatedPart's arg4
    /* 0x04 */ S1_Vec3s rotationA; // GeoNode_CreateAnimatedPart's arg5
    /* 0x0A */ S1_Vec3s rotationB; // GeoNode_CreateAnimatedPart's arg6
    /* 0x10 */ u32 translateX; // Q16 fixed point, /65536.0f
    /* 0x14 */ u32 translateY;
    /* 0x18 */ u32 translateZ;
};
typedef struct S1_unk_D_800ABE00_cmd1E S1_unk_D_800ABE00_cmd1E;
struct S1_unk_D_800ABE00_cmd1E {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 partIndex; // GeoNode_CreateDisplayListPart's arg2
    /* 0x02 */ s16 unk_02; // GeoNode_CreateDisplayListPart's arg4
    /* 0x04 */ Gfx* displayList;
};
typedef struct S1_unk_D_800ABE00_cmd1F S1_unk_D_800ABE00_cmd1F;
struct S1_unk_D_800ABE00_cmd1F {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 modelIndex; // GeoNode_CreateModelPart's arg2
    /* 0x04 */ s16 rotX; // degrees, scaled (val<<0xF)/180
    /* 0x06 */ s16 rotY;
    /* 0x08 */ s16 rotZ;
    /* 0x0A */ S1_Vec3s position;
    /* 0x10 */ s16 scaleX; // /100.0f
    /* 0x12 */ s16 scaleY;
    /* 0x14 */ s16 scaleZ;
    /* 0x16 */ char pad[0x2];
};
typedef struct S1_unk_D_800ABE00_cmd20 S1_unk_D_800ABE00_cmd20;
struct S1_unk_D_800ABE00_cmd20 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 partIndex; // GeoNode_CreateDisplayListMatrixFromTransform's arg2
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 rotX; // degrees, scaled (val<<0xF)/180
    /* 0x06 */ s16 rotY;
    /* 0x08 */ s16 rotZ;
    /* 0x0A */ S1_Vec3s position;
    /* 0x10 */ Gfx* displayList;
};
typedef struct S1_unk_D_800ABE00_cmd21 S1_unk_D_800ABE00_cmd21;
struct S1_unk_D_800ABE00_cmd21 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 partIndex; // GeoNode_CreateScale's arg2
    /* 0x02 */ S1_Vec3s position;
    /* 0x08 */ u32 scale; // Q16 fixed point, /65536.0f
    /* 0x0C */ Gfx* displayList;
};
typedef struct S1_unk_D_800ABE00_cmd22 S1_unk_D_800ABE00_cmd22;
struct S1_unk_D_800ABE00_cmd22 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 partIndex; // GeoNode_CreateDisplayList's arg2
    /* 0x04 */ Gfx* displayList;
};
typedef struct S1_unk_D_800ABE00_cmd23 S1_unk_D_800ABE00_cmd23;
struct S1_unk_D_800ABE00_cmd23 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 colorOverrideFlag; // Geo_NodeShadowTexture: ==1 forces the shadow color to opaque white
    /* 0x02 */ s16 eventFrame; // ModelAnim_GetEventAtFrame's frame arg
    /* 0x04 */ Gfx* displayList;
    /* 0x07 */ s16 textureIndex1; // indexes D_8006F0A0's first texture array when >= 0
    /* 0x0A */ s16 textureIndex2; // indexes D_8006F0A0's second texture array when >= 0
    /* 0x0C */ u8 r;
    /* 0x0D */ u8 g;
    /* 0x0E */ u8 b;
    /* 0x0F */ u8 a;
};
typedef struct S1_unk_D_800ABE00_cmd24 S1_unk_D_800ABE00_cmd24;
struct S1_unk_D_800ABE00_cmd24 {
    /* 0x00 */ u8 cmd;
    /* 0x02 */ s16 anchorId; // GeoNode_CreateAnchor's arg2
};
typedef struct S1_unk_D_800ABE00_cmd26 S1_unk_D_800ABE00_cmd26;
struct S1_unk_D_800ABE00_cmd26 {
    /* 0x00 */ u8 cmd;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 r;
    /* 0x11 */ u8 g;
    /* 0x12 */ u8 b;
    /* 0x13 */ u8 a;
};
typedef struct S1_arg1_func_80019420 S1_arg1_func_80019420;
struct S1_arg1_func_80019420 {
    /* 0x00 */ s8 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ void* unk_04;
};
void MtxF_Multiply(S1_MtxF* arg0, S1_MtxF* arg1, S1_MtxF* arg2) ;

void MtxF_ScaleRows(S1_MtxF* dest, S1_MtxF* mtx, S1_Vec3f* s) ;

void func_80036D8C(f32 *arg0, f32 *arg1) ;

void MtxF_TransformVec3s(S1_MtxF* arg0, S1_Vec3s* arg1) ;

void MtxF_ToFixed(void *destination, S1_MtxF *source) ;

extern void func_80036714(void *, s32, s32, s32, f32);
extern void MtxF_SetRotationTranslationF(f32 matrix[4][4], Vec3f35784 *position, Vec3s35AA0 *rotation);
void MtxF_BuildTransform(S1_MtxF *arg0, S1_Vec3f *arg1, S1_Vec3s *arg2, S1_Vec3f *arg3, S1_MtxF *arg4, S1_MtxF *arg5) ;

extern s16 MathUtil_Atan2s(f32 y, f32 x);
void func_80037120(S1_Vec3f *arg0, S1_Vec3f *arg1, f32 *arg2, s16 *arg3, s16 *arg4) ;

void Camera_ComputeEyeFromAngles(S1_Vec3f *from, S1_Vec3f *to, f32 dist, s16 pitch, s16 yaw) ;

s16 Math_StepToS(s16 current, s16 target, s16 inc) ;

s32 Math_StepToS32(s32 current, s32 target, s32 inc, s32 dec) ;

f32 Math_StepToF(f32 current, f32 target, f32 inc, f32 dec) ;

s16 func_80037360(s16* arg0, s32 arg1, s32 arg2) ;

void Color_RGBToHSV(f32 arg0, f32 arg1, f32 arg2, S1_Vec3f* arg3) ;

void Color_RGBA8ToHSV(S1_Color_RGBA8_u32 arg0, S1_Vec3f* arg1) ;

void Color_RGB5551ToHSV(u16 arg0, S1_Vec3f* arg1) ;

f32 Color_HSVInterpolate(f32 arg0, f32 arg1, f32 arg2) ;

void Color_HSVToRGB(f32* arg0, f32* arg1, f32* arg2, S1_Vec3f* arg3) ;

u16 Color_HSVToRGB5551(S1_Vec3f* arg0) ;

S1_Color_RGBA8_u32* Color_HSVToRGBA8(S1_Color_RGBA8_u32* arg0, S1_Vec3f* arg1, s32 arg2) ;

extern u16 D_80095120[16][256];
extern const f32 D_800A42B0;
u16 Color_AdjustRGB5551(u16 color, S1_arg1_func_80010CA8 adjustment) ;

extern const f32 D_800A42B4;
u32 Color_AdjustRGBA8(u32 word, S1_arg1_func_80010CA8 adjustment) ;

void GeoNode_Init(S1_GraphNode* arg0, u8 arg1) ;

void func_80037E3C(S1_GraphNode* arg0, S1_func_D_86002F34_000_010 arg1, void* arg2) ;

S1_GraphNode* GeoNode_CreateContainer(S1_MainPoolState* arg0, S1_GraphNode* arg1) ;

S1_unk_D_86002F34_alt2* GeoNode_CreateWithReference(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt2* arg1, S1_GraphNode* arg2) ;

extern void GeoCamera_SetViewport(S1_unk_D_86002F34_00C *, s16, s16, s16, s16);
extern void GeoCamera_SetPerspective(S1_unk_D_86002F34_00C *, f32, f32, f32);
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
extern void GeoCamera_SetBackground(S1_unk_D_86002F34_00C *, s16, s16, u8, u8, u8);
S1_unk_D_86002F34_00C *GeoNode_CreateCamera(S1_MainPoolState *pool, S1_unk_D_86002F34_00C *node, s16 x, s16 y, s16 width, s16 height) ;

S1_unk_D_86002F34_alt13* GeoNode_CreateType3(S1_MemoryBlock* arg0, S1_unk_D_86002F34_alt13* arg1, s16 arg2) ;

S1_unk_D_86002F34_alt1* GeoNode_CreateType4(S1_MemoryBlock* arg0, S1_unk_D_86002F34_alt1* arg1, s16 arg2) ;

void *func_800380B8(S1_MainPoolState *arg0, s32 arg1, s16 arg2) ;

void *func_8003811C(S1_MainPoolState *arg0, s32 arg1, s16 arg2) ;

S1_unk_D_86002F34_alt16* GeoNode_CreateBackground(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt16* arg1, u8 arg2, u8 arg3, u8 arg4) ;

s32 func_8003820C(s32 arg0, s32 arg1) ;

S1_unk_D_8690A610* GeoNode_CreateFog(s32 arg0, S1_unk_D_8690A610* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a) ;

extern S1_Vec3s D_800948DC;
typedef struct {
    S1_GraphNode node;
    S1_Color_RGBA8_u32 color;
    s16 pitch;
    s16 yaw;
    S1_Vec3s direction;
    u16 pad26;
    u8 red;
    u8 green;
    u8 blue;
    u8 overrideDirection;
} SceneDirectionalLight;
void *GeoNode_CreateLight(S1_MainPoolState *pool, void *storage, s16 pitch, s16 yaw, u8 red, u8 green, u8 blue, u8 alpha) ;

typedef struct Candidate38390Node {
    u8 pad00[0x20];
    S1_Vec3s vector;
    u8 pad26[2];
    u8 red;
    u8 green;
    u8 blue;
    u8 enabled;
} Candidate38390Node;
typedef struct Candidate38390UnsignedVector {
    u16 x;
    u16 y;
    u16 z;
} Candidate38390UnsignedVector;
void func_80038390(void *arg0, S1_Vec3s *arg1, u8 arg2, u8 arg3, u8 arg4) ;

void func_800383DC(void *arg0, s16 arg1, s16 arg2) ;

S1_unk_D_86002F34_alt19* GeoNode_CreateAmbientLight(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt19* arg1, u8 r, u8 g, u8 b) ;

s32 func_80038474(s32 arg0, s32 arg1) ;

S1_GraphNode *func_800384C0(void *arg0, S1_GraphNode *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u16 arg8) ;

S1_unk_D_86002F34_alt12* GeoNode_CreateShadow(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt12* arg1, s16 arg2, s16 arg3, s16 arg4,
                                    s16 arg5) ;

S1_unk_D_86002F34_alt20* GeoNode_CreateCullDistance(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt20* arg1, s16 arg2, s16 arg3) ;

S1_unk_D_86002F34_alt21* GeoNode_CreateSwitchCase(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt21* arg1, s16 arg2, s16 arg3) ;

S1_unk_D_86002F34_alt5* GeoNode_CreateTranslateRotate(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt5* arg1, S1_Vec3f* arg2, S1_Vec3s* arg3) ;

S1_unk_D_86002F34_alt22* GeoNode_CreateTranslate(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt22* arg1, S1_Vec3f* arg2) ;

S1_unk_D_86002F34_alt6* GeoNode_CreateAnimatedPart(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt6* arg1, s16 arg2, s16 arg3, s16 arg4,
                                   S1_Vec3s* arg5, S1_Vec3s* arg6, S1_Vec3f* arg7) ;

S1_unk_D_86002F34_alt7* GeoNode_CreateDisplayListPart(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt7* arg1, s32 arg2, Gfx* arg3, s16 arg4) ;

S1_unk_D_86002F58_004_000 *GeoNode_CreateModelPart(S1_MainPoolState *pool, void *storage, s16 model, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) ;

extern void MtxF_Identity(f32 *arg0);
void *func_8003899C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) ;

extern void *func_8003899C(s32, s32, s32, s32, void *);
void *GeoNode_CreateDisplayListMatrixFromTransform(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) ;

S1_unk_D_86002F34_alt9* GeoNode_CreateScale(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt9* arg1, s32 arg2, Gfx* arg3, S1_Vec3f* arg4,
                                   f32 arg5) ;

S1_unk_func_80011B94* GeoNode_CreateDisplayList(S1_MainPoolState* arg0, S1_unk_func_80011B94* arg1, s32 arg2, Gfx* arg3) ;

S1_unk_D_86002F34_alt10* GeoNode_CreateShadowTexture(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt10* arg1, s16 arg2, s16 arg3, Gfx* arg4,
                                    s16 arg5, s16 arg6, u8 r, u8 g, u8 b, u8 a) ;

S1_unk_D_86002F34_alt23* GeoNode_CreateAnchor(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt23* arg1, s16 arg2) ;

S1_unk_D_86002F34_alt24* GeoNode_CreateGroup(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt24* arg1, s32 arg2, s16 arg3, s16 arg4,
                                    s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9, u8 r, u8 g, u8 b, u8 a) ;

void GeoCamera_SetViewport(S1_unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) ;

void GeoCamera_SetPerspective(S1_unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3) ;

extern f32 D_80087E50[];
extern f32 D_80088E50[0x1000];
void func_80038E14(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u16 arg7) ;

void GeoCamera_SetBackground(S1_unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5) ;

void func_80038F8C(void *arg0, void *arg1) ;

typedef struct GraphNodeLink {
    char pad0[4];
    struct GraphNodeLink *prev;
    struct GraphNodeLink *next;
} GraphNodeLink;
typedef struct {
    char pad[0xC];
    GraphNodeLink *child;
} GraphNode38FD4;

void GraphNode_RemoveChild(GraphNode38FD4 *root, GraphNodeLink *node) ;

typedef struct unk_func_80039018 {
    u32 unk_00[2];
    struct unk_func_80039018 *unk_08;
    struct unk_func_80039018 *unk_0C;
} unk_func_80039018;

unk_func_80039018 *func_80039018(unk_func_80039018 *arg0, s32 arg1) ;

extern Gfx *Gfx_AllocDisplayList(s32);
extern void MtxF_ToFixed(void *, S1_MtxF *);
extern u8 D_80124F68;
typedef struct {
    S1_MtxF matrices[64];
    Mtx *stack[32];
    s8 flags[32];
    s32 top;
} SceneTransformPool;
void func_80039070(s32 arg0) ;

void GeoRender_CommitMatrix(Mtx *fixed) ;

Mtx *GeoRender_SetMatrix(S1_MtxF *matrix, Mtx *fixed) ;

void GeoRender_PushMultipliedMatrix(S1_MtxF *matrix, Mtx *fixed) ;

Mtx *GeoRender_PushScaledMatrix(S1_Vec3f *scale, Mtx *fixed) ;

extern u8 D_80124F68;
void *func_8003936C(s32 arg0) ;

extern u8 D_80124F68;

void *GeoRender_GetMatrix(s32 arg0) ;

extern u8 D_80126010;
extern u8 D_800948E4[];
void GeoRender_ResetTransformStack(void) ;

extern u8 D_80126010;
void func_800393F0(S1_Vec3f *arg0) ;

extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
// Allocate the four projection-plane corners used by GeoOverlay_DrawFadeQuad.
Vtx *GeoOverlay_BuildFadeQuad(S1_unk_D_86002F34_00C_0CC *overlay, S1_unk_D_86002F34_00C_040 *projection) ;

void GeoOverlay_DrawFadeQuad(S1_unk_D_86002F34_00C_0CC* arg0, S1_unk_D_86002F34_00C_040* arg1) ;

extern s32 D_80039808_alpha_hint_0;
#define COSS(x) D_80088E50[(u16)(x) >> 4]
#define SINS(x) D_80087E50[(u16)(x) >> 4]
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
void func_80039808(Vtx* arg0, S1_unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) ;

Vtx *func_800398F8(S1_unk_D_86002F34_00C_0CC *arg0) ;

void GeoOverlay_DrawRotatingQuad(S1_unk_D_86002F34_00C_0CC* arg0, UNUSED S1_unk_D_86002F34_00C_040* arg1) ;

void GeoOverlay_Draw(S1_unk_D_86002F34_00C_0CC* arg0, S1_unk_D_86002F34_00C_040* arg1) ;

extern s32 D_80124D60;
extern void *D_80094924[];
void Geo_ProcessNodeChildren(void *root) ;

extern s32 D_80124D60;
extern void func_8003B690(s32);
extern void Geo_PrepareAnimatedPart(s32);
void Geo_PrepareShadowChildren(s32 root) ;

extern s32 D_80124D60;
extern void *D_80094924[];
extern void Geo_ProcessNodeChildren(void *);
void Geo_NodeReference(void *arg0) ;

/* mkdraft:func_8003A4CC begin */
extern Gfx *D_800D0510;
extern void *D_80094908;
extern void Gfx_ApplyScissorRect(void **);
extern void func_80077DC0(Mtx *, u16 *, f32, f32, f32, f32, f32);
extern void func_8003A2C8(void *);

void func_8003A4CC(S1_GraphNode *arg0) ;
/* mkdraft:func_8003A4CC end */

extern s32 D_8009490C;
extern void Geo_ProcessNodeChildren(void *);
void Geo_NodeType3Pass(s32 arg0) ;

typedef struct {
    u8 pad[0x1A];
    u16 unk_1A;
    s8 lightCount;
    s8 unknown1D;
    s8 activeLights;
    s8 extraGeometryMode;
    u32 unknown20;
    Lights7 *lights;
} ModelFrame;
extern ModelFrame *D_80094910;
extern u16 D_80094904;
extern void ModelAnim_ResetCurveContext(void);
extern void ModelAnim_ResetEventContext(void);
extern void Geo_ProcessNodeChildren(void *);
extern Gfx* D_800D0510;
extern u8 D_80124F68;
void Geo_NodeModelRoot(void *root) ;

extern S1_unk_D_86002F34_00C *D_80094914;
extern s32 D_80094900;
extern void GeoRender_InitMaterialState(s32, s32);
extern void GeoRender_FlushMaterialSlots(void);
void Geo_NodeModelPartRoot(void *root) ;

extern S1_unk_D_86002F34_00C *D_80094914;
extern void Geo_NodeModelPartRoot(void *);
extern void * D_80094908;
extern Gfx* D_800D0510;
void Geo_NodeOrtho(void *root) ;

void Geo_NodePerspective(void *root) ;

extern void *D_80094908;
extern void GfxImage_FillRectangle(Gfx **, s16, s16, s16, s16, s32);
extern Gfx* D_800D0510;
void Geo_NodeBackground(u8 *arg0) ;

extern void *D_80094908;
extern void GfxImage_ClearDepthRectangle(void *, s32, s32, s32, s32);
extern Gfx* D_800D0510;
void Geo_NodeClearDepth(s32 arg0) ;

void func_8003AC84(s32 arg0) ;

extern ModelFrame *D_80094910;
extern Gfx* D_800D0510;
void Geo_NodeFog(S1_GraphNode *root) ;

typedef union {
    Light directional;
    struct {
        u32 color;
        u32 colorCopy;
        S1_Vec3s position;
        u8 quadratic;
        u8 padF;
    } point;
} SceneLightRecord;
extern f32 D_80087E50[];
extern f32 D_80088E50[0x1000];
extern Gfx* D_800D0510;
void Geo_NodeLight(S1_GraphNode *root) ;

void func_8003B03C(s32 arg0) ;

extern Gfx *D_800D0510;
typedef struct {
    S1_GraphNode node;
    S1_Color_RGBA8_u32 color;
} SceneAmbientLightNode;
void Geo_NodeAmbientLight(void *root) ;

extern Gfx* D_800D0510;
void Geo_NodeUpdateLights(S1_GraphNode *root) ;

extern void Geo_ProcessNodeChildren(void *root);
extern void * D_80094908;
extern u8 D_80124F68;
void Geo_NodeCullDistance(S1_GraphNode *root) ;

extern void * D_80094924[];
void Geo_NodeSwitchCase(S1_GraphNode *root) ;

extern void GeoRender_PushMultipliedMatrix(S1_MtxF *, Mtx *);
void func_8003B5AC(u8 *arg0) ;

extern u8 *D_80094920;
extern s32 D_8009499C;
extern Mtx *GeoRender_PushScaledMatrix(S1_Vec3f *, Mtx *);
void func_8003B600(u8 *arg0) ;

Mtx *GeoRender_PushScaledMatrix(S1_Vec3f *, Mtx *);
extern void Geo_PrepareShadowChildren(s32);
extern s32 D_8009499C;

void func_8003B690(s32 arg0) ;

extern void func_8003E8C8(S1_Vec3f *, S1_Vec3s *, S1_Vec3f *, s32);
extern void MtxF_SetRotationScaleTranslation(S1_MtxF *, S1_Vec3f *, S1_Vec3s *, S1_Vec3f *);
extern void MtxF_SetRotationAndScaledTranslation(S1_MtxF *, S1_Vec3f *, S1_Vec3s *, S1_Vec3f *);
extern void func_800393F0(S1_Vec3f *);
extern s32 D_80124D68[];
extern s32 D_80126190;
typedef struct {
    S1_Vec3f vectors[32];
    s32 top;
} SceneScaleStack;
extern void GeoRender_CommitMatrix(Mtx *fixed);
extern void * D_80094908;
extern u8 D_80124F68;
extern u8 D_80126010;
extern void Geo_ProcessNodeChildren(void *root);
extern u8 * D_80094920;
void Geo_NodeAnimatedPart(s32 root) ;

void Geo_PrepareAnimatedPart(s32 root) ;

extern s32 D_80124D68[];
extern void GeoRender_SubmitMaterial(s16, Mtx *);
extern void func_8003DA20(s32, s32);
extern void Geo_ProcessNodeChildren(void *);
void func_8003BC48(void *arg0) ;

extern ModelFrame *D_80094910;
extern void *D_8009491C;
extern void *D_80094908;
extern u16 D_80094904;
extern void func_8003E7B0(S1_unk_D_86002F58_004_000_040_raw *, u16, s32);
extern void ModelAnim_BeginEventContext(S1_unk_D_86002F58_004_000_054 *, u16, s32);
extern void ModelAnim_EndCurveContext(void);
extern void ModelAnim_EndEventContext(void);
extern void GeoRender_SetMaterialParams(S1_Color_RGBA8_u32, u8, u32);
extern void func_800707D0(void *);
extern void func_80070860(s32);
extern void Geo_ProcessNodeChildren(void *);
extern u8 D_80124F68;
void Geo_NodeModelPart(void *root) ;

extern void GeoRender_PushMultipliedMatrix(S1_MtxF *, Mtx *);
extern void GeoRender_SubmitMaterial(s16, Mtx *);
extern void func_8003DA20(s32, s32);
extern s32 D_80126008;
extern void Geo_ProcessNodeChildren(void *);
extern u8 D_80124F68;
void func_8003BEF0(void *arg0) ;

extern Mtx *GeoRender_SetMatrix(S1_MtxF *, Mtx *);
extern void Geo_ProcessNodeChildren(void *);
extern void * D_80094908;
extern u8 D_80124F68;
void func_8003BF9C(void *arg0) ;

extern void Geo_ProcessNodeChildren(void *);
extern u8 D_80124F68;
void Geo_NodeDisplayList(void *arg0) ;

typedef union CandidateColor {
    struct { u8 r, g, b, a; };
    u32 rgba;
} CandidateColor;
extern u8 *D_80094920;
extern void *D_8009491C;
extern void func_8003EE20(s32 *, s32, s32);
extern void GeoRender_SetMaterialTexture(s32, CandidateColor, void *, void *, s32);
extern void Geo_ProcessNodeChildren(void *);
void Geo_NodeShadowTexture(void *root) ;

extern void *D_8009491C;
extern u8 D_80124F68;
typedef struct {
    u16 id;
    u8 unknown02;
    S1_Vec3f position;
} SceneAnchorPosition;
typedef struct {
    S1_unk_D_86002F58_004_000_000 header;
    s16 animation;
    s16 model;
    u8 textureMode;
    u8 materialAlpha;
    S1_Vec3s rotation;
    S1_Vec3f position;
    S1_Vec3f scale;
    S1_Color_RGBA8_u32 tint;
    S1_unk_D_86002F58_004_000_040 transform;
    S1_unk_D_86002F58_004_000_054 events;
    S1_MtxF matrix;
    S1_Color_RGBA8_u32 color;
    u16 unknownA4;
    u8 poolIndex;
    u8 anchorCount;
    SceneAnchorPosition anchors[12];
} SceneDisplayObjectAnchors;
void func_8003C2D8(s32 id) ;

extern void func_8003C2D8(s32);
extern void Geo_ProcessNodeChildren(void *);
void Geo_NodeAnchor(void *arg0) ;

extern void Geo_ProcessNodeChildren(void *); void Geo_NodeGroup(void *arg0) ;

extern S1_Vec3f *GeoRender_FindAnchorPosition(u8 *, s16, S1_Vec3f *);
extern u8 D_1000C80[];
extern u8 D_1000D08[];
extern Gfx* D_800D0510;
extern u8 D_80124F68;
// Project the model shadow onto y = 0 and fade it with height.
void Geo_NodeShadow(S1_unk_D_86002F34_alt12 *node) ;

extern s32 D_80094900;
extern void func_8006D2C0(void);
void Geo_RenderRootNode(u8 *node) ;

extern void *D_80094918;
extern void * D_80094908;
extern void * D_8009491C;
void Geo_ProcessCallbacks(S1_GraphNode *root, s32 event) ;

extern s32 D_80094900;
void func_8003C964(s32 value) ;

extern u16 D_80094904;
void GeoRender_AdvanceFrameCounter(void) ;

extern ModelFrame *D_80094910; extern u16 D_80094904;
s32 GeoRender_IsModelFrameCurrent(void) ;

S1_Vec3f *GeoRender_FindAnchorPosition(u8 *object, s16 id, S1_Vec3f *out) ;
/* Preserve the two zero words at the end of the original assembly owner. */

typedef struct S1_arg1_func_81407874_014_000_010 S1_arg1_func_81407874_014_000_010;
struct S1_arg1_func_81407874_014_000_010 {
      u8 unk_00;
      u8 unk_01;
      u8 unk_02;
      u8 unk_03;
      u8 unk_04;
      u8 unk_05;
      u8 unk_06;
      u8 unk_07;
      u8 unk_08;
      u8 unk_09;
      u8 unk_0A;
      u8 unk_0B;
      u8 unk_0C;
      u8 unk_0D;
      u8 unk_0E;
      u8 unk_0F;
};
void func_8003CA30(Gfx* arg0, S1_arg1_func_81407874_014_000_010* arg1) ;

extern S1_arg1_func_81407874_014_000_010 D_80094AAC[];
void func_8003CB3C(Gfx *arg0, u8 arg1, u8 arg2) ;

extern s32 D_801261A8;
extern Gfx* D_800D0510;
void func_8003CBD4(void) ;

typedef struct SceneMaterialState {
    s32 unknown00;
    void *unknown04;
    void *unknown08;
    void *unknown0C;
    S1_Color_RGBA8_u32 primitiveColor;
    S1_Color_RGBA8_u32 fogColor;
    void *unknown18;
    void *unknown1C;
    void *unknown20;
    u8 unknown24;
    u8 combineMode;
    u8 primitiveLevel;
    u8 unknown27;
} SceneMaterialState;
extern void *D_801263A8;
extern s32 D_801261A0;
extern s32 D_801261A4;
extern s32 D_801261A8;
extern s32 D_800949A4[][11];
extern Gfx* D_800D0510;
void GeoRender_SetRenderMode(void) ;

s32 func_8003CD58(s32 arg0) ;

extern void func_8003CB3C(Gfx *arg0, u8 arg1, u8 arg2);
extern void * D_80094908;
extern Gfx* D_800D0510;
extern void * D_801263A8;
void GeoRender_ApplyMaterialState(void) ;

typedef struct {
    u8 mode;
    u8 level;
    u8 unknown02;
    u8 textureVariant;
    S1_Color_RGBA8_u32 primitiveColor;
    S1_Color_RGBA8_u32 fogColor;
    void *texture;
    void *material;
    Gfx *displayList;
} SceneMaterialParameters;
extern void func_8003CBD4(void);
extern Gfx* D_800D0510;
extern void * D_801263A8;
void GeoRender_SetFogColor(SceneMaterialParameters *node) ;

extern void GeoRender_SetRenderMode();
extern void *D_801263A8;

void GeoRender_RestoreRenderMode(s32 arg0) ;

typedef struct {
    u8 mode;
    u8 level;
    u8 unknown02;
    u8 unknown03;
    S1_Color_RGBA8_u32 color;
} ScenePrimitiveColor;
void GeoRender_SetPrimitiveColor(ScenePrimitiveColor *node) ;

extern void func_8003CBD4(void);
extern void func_8003D188_batch_decl_marker(void);
extern void func_8003CB3C(Gfx *arg0, u8 arg1, u8 arg2);
extern Gfx* D_800D0510;
extern void * D_801263A8;
void func_8003D188(u8 *arg0) ;

extern Gfx* D_800D0510;
extern void * D_801263A8;
void func_8003D1F8(s32 arg0) ;

typedef struct {
    u8 format;
    u8 size;
    s16 width;
    s16 height;
    s16 numTexels;
    void *image;
} SceneBoundTexture;
typedef struct {
    u8 unknown00[8];
    Gfx *displayList;
} SceneBoundPalette;
extern s16 D_80094B9C[];
extern Gfx* D_800D0510;
extern void * D_801263A8;
void GeoRender_BindTexture(SceneMaterialParameters *node) ;

extern u8 D_1000000[];
extern u8 D_10019D0[];
void GeoRender_EnableTextureGeneration(SceneMaterialParameters *node) ;

extern s32 D_801263AC;
extern SceneMaterialState D_801261C8[];
extern Gfx* D_800D0510;
extern void * D_801263A8;
void GeoRender_SelectMaterialSlot(s16 slot) ;

extern SceneMaterialParameters D_801261B0;
void func_8003D7B8(s16 arg0) ;

extern u8 D_801261B1;
s16 func_8003D808(s16 arg0) ;

extern s32 D_800949A0;
extern s32 D_801261A4;
extern void GeoRender_SelectMaterialSlot(s16);
extern void GeoRender_SetFogColor(SceneMaterialParameters *);
extern void GeoRender_BindTexture(SceneMaterialParameters *);
extern void GeoRender_ApplyMaterialState(void);
void GeoRender_SubmitMaterial(s16 format, Mtx *matrix) ;

extern u32 Memmap_GetFragmentVaddr(Gfx **);
extern void GeoRender_ApplyMaterialState(void);
extern s32 D_800949A0;
extern s32 D_801261A4;
extern Gfx* D_800D0510;
extern u8 D_801261B1;
void func_8003DA20(s32 arg0, s32 arg1) ;

void GeoRender_SetMaterialParams(S1_Color_RGBA8_u32 color, u8 level, u32 flags) ;

void GeoRender_SetMaterialTexture(s32 arg0, CandidateColor arg1, void *arg2, void *arg3, s32 arg4) ;

extern Gfx* D_800D0510;
extern void * D_801263A8;
void GeoRender_InitMaterialState(s32 mode, s32 flags) ;

void GeoRender_FlushMaterialSlots(void) ;

f32 ModelAnim_EvaluateTranslationChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) ;

s16 ModelAnim_EvaluateRotationChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) ;

f32 ModelAnim_EvaluateScaleChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) ;

f32 ModelAnim_InterpolateKeyframe(S1_Vec3s* arg0, s16 arg1, s16 arg2) ;

f32 ModelAnim_InterpolateKeyframeTangent(S1_unk_func_80016B30_arg0* arg0, s16 arg1, s16 arg2) ;

f32 ModelAnim_EvaluateTranslationCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) ;

s16 ModelAnim_EvaluateRotationCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) ;

f32 ModelAnim_EvaluateScaleCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) ;

s32 ModelAnim_AdvanceCurveFrame(S1_unk_D_86002F58_004_000_040_raw* arg0, u16 arg1) ;

extern s32 D_801263E0; void ModelAnim_ResetCurveContext(void) ;

extern void * func_80003240();
void func_8003E7B0(S1_unk_D_86002F58_004_000_040_raw *arg0, u16 arg1, s32 arg2) ;

extern s32 D_801263E0; void ModelAnim_EndCurveContext(void) ;

extern S1_unk_D_800ABCC0 D_801263B0[2];
void func_8003E8C8(S1_Vec3f *arg0, S1_Vec3s *arg1, S1_Vec3f *arg2, s32 arg3) ;

void ModelAnim_ClearTransformChannel(u8 *arg0) ;

s32 ModelAnim_BindTransformCurve(S1_unk_D_86002F58_004_000* arg0, s16 arg1, void* arg2, s32 arg3) ;

s32 ModelAnim_SetSpeed(u8 *arg0, s32 arg1) ;

void ModelAnim_SetFrame(u8 *arg0, s16 value) ;

typedef struct { char pad[0x40]; struct { s16 pad0; void *data; s32 frame; s32 speed; } curve; } ModelAnim;
s32 ModelAnim_HasCrossedFrame(ModelAnim *arg0, s16 arg1) ;

typedef struct { s16 flags; char pad2[4]; s16 fallback; char pad8[2]; u16 frameCount; } EventData;
s32 ModelAnim_IsAnimationDone(ModelAnim *arg0) ;

typedef struct { u8 pad[0x44]; u8 *value44; s32 value48; } Func3EC34;
s32 ModelAnim_IsFinished(Func3EC34 *arg0) ;

typedef struct { u8 pad[0x48]; s32 value48; s32 value4C; } Func3EC54;
s32 func_8003EC54(Func3EC54 *arg0) ;

typedef struct { u16 keyCount; u16 baseIndex; } EventIndex;
s32 ModelAnim_ResolveEventIndex(s32 arg0, EventIndex* arg1, s32 arg2) ;

s16 ModelAnim_AdvanceEventFrame(S1_unk_D_86002F58_004_000_054* arg0, u16 arg1) ;

extern s32 D_80126410; void ModelAnim_ResetEventContext(void) ;

extern u8 D_801263F0[];
typedef struct {
    u8 active;
    u8 unknown01;
    s16 frame;
    S1_unk_D_86002F58_004_000_054_004 *data;
    EventIndex *indices;
    u8 *values;
} SceneEventContext;
void ModelAnim_BeginEventContext(S1_unk_D_86002F58_004_000_054 *state, u16 renderFrame, s32 advance) ;

extern s32 D_80126410; void ModelAnim_EndEventContext(void) ;

extern u8 D_801263F0[];
void func_8003EE20(s32 *arg0, s32 arg1, s32 arg2) ;

void ModelAnim_ClearEventTrack(u8 *arg0) ;

s16 ModelAnim_BindEventTrack(S1_unk_D_86002F58_004_000* arg0, s16 arg1, s32 arg2) ;

void ModelAnim_SetEventFrame(u8 *arg0, s16 value) ;

void func_8003EF60(u8 *arg0) ;

void func_8003EF70(u8 *arg0) ;

s32 ModelAnim_IsEventFrame(u8 *arg0, s16 value) ;

s32 ModelAnim_IsEventTrackNearEnd(u8 *arg0) ;

s32 ModelAnim_IsEventTrackDone(u8 *arg0) ;

extern S1_GraphNode* GeoNode_CreateContainer(S1_MainPoolState*, S1_GraphNode*);
extern u8 D_80126420[];
extern u8 D_80126438[];
void ModelRenderer_InitDisplayRoots(void) ;

extern void func_8003F03C(s32, void *);
void func_8003F018(s32 arg0) ;

extern S1_unk_D_86002F58_004_000 *GeoNode_CreateModelPart(S1_MainPoolState *, void *, s16, S1_Vec3f *, S1_Vec3s *, S1_Vec3f *);
extern S1_Vec3s D_800948DC;
void func_8003F03C(s32 arg0, void *arg1) ;

void ModelRenderer_AttachSecondaryDisplayObject(void *arg0) ;

extern void func_8007074C(void *);
extern void func_8006D430(s32);
void func_8003F114(u8 *node, s16 animation, s16 model, void *data) ;

extern void func_8006D438();

void func_8003F1DC(void *arg0) ;

typedef struct {
    u32 unknown00;
    u8 transformCount;
    u8 eventCount;
    u8 unknown06[6];
    void **transformTracks;
    void **eventTracks;
} SceneAnimationBank;
typedef SceneAnimationBank *(*SceneAnimationBankGetter)(s32, s32);
typedef struct {
    S1_GraphNode node;
    u8 unknown18[0x14];
    SceneAnimationBankGetter getAnimationBank;
} SceneAnimationAsset;
s32 ModelAnim_SetAnimation(S1_unk_D_86002F58_004_000 *object, s32 animation) ;

extern s32 func_80042ADC(u8 *);
extern s32 func_800422B4(u8 *, s32, u16, u16);
extern void func_80042968(s32);
typedef struct {
    u16 first;
    u16 second;
} SceneAnimationTransfer;

typedef struct { u8 unknown00[0x40]; void *loadedCurve; } SceneAnimationResource;
s32 ModelAnim_SetResourceAnimation(SceneAnimationResource *resource, u8 *object, s32 animation) ;

s32 ModelAnim_SetEventTrack(void *arg0, s32 arg1) ;

void func_8003F454(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) ;

void func_8003F498(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) ;

void func_8003F4DC(u8 *arg0, u8 value) ;

void func_8003F4E8(u8 *arg0, u8 value) ;

extern void *D_8009491C;
s32 func_8003F4F4(void *arg0, s32 arg1) ;

extern void *func_80003240();
void *func_8003F54C(void *arg0) ;

extern void _bzero(void *arg0, s32 arg1);
void func_8003F818(s32 *arg0, s32 arg1) ;

void func_8003F84C(u8 *arg0, u32 value1, u32 value2) ;

void func_8003F864(u8 *arg0) ;

extern s32 func_800421E0(u8 *, s32, s32);
extern void PokeIcon_WaitBackgroundLoad(s32);
typedef struct {
    u8 *context;
    u8 flags;
    u8 unknown05[3];
    s32 source;
    s32 background;
} SceneBackgroundRequest;
void PokeIcon_RequestBackgroundForObject(SceneBackgroundRequest *request) ;

extern s32 func_80042808(s32);
void func_8003F904(u8 *arg0) ;

s32 func_8003F954(u16 value) ;

s32 func_8003F970(s32 arg0, u16 arg1) ;

s32 SceneObject_SetModelVariant(u8 *object, s32 kind, u16 value) ;

extern void func_80027E30(void);
extern void func_80027F4C(void);
extern s16 D_8012651A;
extern s32 D_80126458[];
extern s16 D_8012651E;
extern s16 D_80126518;
extern s32 D_80126520;
extern void *func_80003240();
void geo_layout_cmd_branch_and_link(void)
;

void geo_layout_cmd_2A(void) ;

extern s16 D_80126518;
extern s16 D_8012651A;
extern s16 D_8012651E;
void func_8003FB2C(void) ;

extern s32 D_80126520;
void geo_layout_cmd_jump(void) ;

extern void * func_80003240();
extern s16 D_8012651A;
void func_8003FBE0(void) ;

extern s16 D_8012651A;
extern s32 D_80126458[];
extern void * func_80003240();
void geo_layout_cmd_27(void)
;

extern s16 D_8012651A;
void geo_layout_cmd_return(void) ;

extern s16 D_80126518;
extern s32 D_80126498[];
void geo_layout_cmd_open_node(void) ;

void geo_layout_cmd_close_node(void) ;

extern void *D_80126454;
extern void func_80038F8C(void *arg0, void *arg1);
extern s16 D_80126518;
void func_8003FD34(void *arg0) ;

extern S1_MainPoolState *D_80126450;
extern void func_8003FD34(void *);
extern void *func_800380B8(S1_MainPoolState *, s32, s16);
extern void *func_8003811C(S1_MainPoolState *, s32, s16);
void geo_layout_cmd_attach_node(void) ;

extern s16 D_80126518;
void func_8003FDD0(void) ;

extern S1_GraphNode *func_80037E9C(S1_MainPoolState *, S1_GraphNode *);
extern void func_8003FD34(void *arg0);
void func_8003FE2C(void) ;

void geo_layout_cmd_create_reference(void) ;

extern S1_unk_D_86002F34_00C *GeoNode_CreateCamera(S1_MainPoolState *, S1_unk_D_86002F34_00C *, s16, s16, s16, s16);
extern void Camera_ComputeEyeFromAngles(S1_Vec3f *, S1_Vec3f *, f32, s16, s16);
extern void func_8003FD34(void *);
void func_8003FEB8(void) ;

void geo_layout_cmd_create_type3(void) ;

void geo_layout_cmd_create_type4(void) ;

void geo_layout_cmd_create_ortho(void) ;

void geo_layout_cmd_create_perspective(void) ;

void geo_layout_cmd_create_background(void) ;

extern s32 func_8003820C(s32, s32);
void geo_layout_cmd_create_clear_depth(void) ;

void geo_layout_cmd_noop(void) ;

void geo_layout_cmd_create_fog(void) ;

extern void *GeoNode_CreateLight(S1_MainPoolState *, void *, s16, s16, u8, u8, u8, u8);
extern void func_8003FD34(void *);
void geo_layout_cmd_create_light(void) ;

void geo_layout_cmd_28(void) ;

s32 func_80038474(s32, s32);

void geo_layout_cmd_29(void) ;

extern s32 D_80126520; void geo_layout_cmd_skip(void) ;

typedef struct S1_unk_D_800ABE00_cmd16 S1_unk_D_800ABE00_cmd16;
struct S1_unk_D_800ABE00_cmd16 {
      u8 cmd;
      u8 r;
      u8 g;
      u8 b;
};
void geo_layout_cmd_create_ambient_light(void) ;

void geo_layout_cmd_17(void) ;

void geo_layout_cmd_create_shadow(void) ;

void geo_layout_cmd_create_cull_distance(void) ;

void geo_layout_cmd_create_switch_case(void) ;

void geo_layout_cmd_create_translate_rotate(void) ;

void geo_layout_cmd_create_translate(void) ;

void geo_layout_cmd_create_animated_part(void) ;

void geo_layout_cmd_create_display_list_part(void) ;

void geo_layout_cmd_create_model_part(void) ;

extern void func_8003FD34(void *);
void geo_layout_cmd_create_display_list_matrix(void) ;

void geo_layout_cmd_create_scale(void) ;

void geo_layout_cmd_create_display_list(void) ;

void geo_layout_cmd_create_shadow_texture(void) ;

void geo_layout_cmd_create_anchor(void) ;

extern s16 D_80126518;
void geo_layout_cmd_set_node_flag4(void) ;

void geo_layout_cmd_create_group(void) ;

extern s32 D_80094BB0;
extern void (*D_80094BB4[])(void);
void *process_geo_layout(S1_MemoryBlock *pool, void *script) ;

typedef struct {
    u8 mode;
    u8 type;
    s16 width;
    s16 height;
    s16 numTexels;
    void *texture;
} SceneTextureData;
typedef struct {
    s32 count;
    u16 *colors;
    u32 unknown08;
} ScenePaletteData;
typedef struct {
    S1_GraphNode node;
    SceneTextureData *textures;
    ScenePaletteData *palettes;
    Vtx *vertices;
    u8 textureCount;
    u8 paletteCount;
    s16 unknown26;
    void *callback;
} SceneTextureModel;
extern u16 Color_AdjustRGB5551(u16, S1_arg1_func_80010CA8);
extern u32 Color_AdjustRGBA8(u32, S1_arg1_func_80010CA8);
void Model_AdjustTextureColors(SceneTextureModel *model, S1_arg1_func_80010CA8 adjustment) ;

typedef struct { s32 unused0; s32 unused1; s32 offset; s32 size; } CandidateJpegHeader;
extern s32 Jpeg_DecodeImage(u32, s32, u8 *);
extern void MainPool_ResetStateToOffset(void *, s32);
void *func_80041130(void *arg0, void *arg1, s32 arg2, CandidateJpegHeader *arg3) ;

extern void Yay0_DecompressAndRelocate(u8 *, u8 *);
u8 *func_800411F0(void *arg0, u8 *arg1, s32 arg2, u8 *arg3) ;

extern void Util_Memcpy(u32 *, const u32 *, s32);
extern void *MainPool_AllocAligned(void *, size_t, s32);
void *func_8004124C(void *arg0, void *arg1, s32 arg2, s32 arg3, u32 arg4) ;

extern void func_80003F74(u8 *, u8 *, u8 *, s32);
s32 Fragment_LoadResourceFromRomRange(s32 pool, s32 destination, s32 start, s32 end, s32 buffer, s32 capacity) ;

#define RELOCATIONS_SIZE 1
typedef struct S1_Fragment S1_Fragment;
struct S1_Fragment {
      u32 inst[2];
      char magic[8];
      u32 headerSize;
      u32 relocOffset;
      u32 sizeInRom;
      u32 sizeInRam;
      char data[RELOCATIONS_SIZE];
};
void func_800413A0(S1_MainPoolState* arg0, u32 arg1, S1_Fragment* arg2) ;

extern s32 Fragment_LoadResourceFromRomRange(s32, s32, s32, s32, s32, s32);
s32 func_800413E8(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5) ;

s32 func_80041430(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) ;

typedef struct SceneProcessedModel SceneProcessedModel;
typedef SceneProcessedModel *(*SceneModelEntry)(s32, s32);
struct SceneProcessedModel {
    u16 species;
    u8 format;
    u8 geometryCount;
    u8 transformCount;
    u8 eventCount;
    u8 unknown06[2];
    void **geometry;
    void *transformTracks;
    void *eventTracks;
    SceneModelEntry entry;
};
typedef struct {
    S1_GraphNode node;
    u8 unknown18[0x14];
    SceneModelEntry entry;
} SceneGeometryNode;
extern void *process_geo_layout(S1_MemoryBlock *, void *);
// K&R definition (no prototype): this file's caller of the narrowed `u8 format`
// formal must forward the cached s16 format word as a full lw; a prototyped
// form narrows it to lbu at the call. The callee reads lbu either way.
SceneProcessedModel *Fragment_ProcessGeoLayout();

extern void *process_geo_layout(S1_MemoryBlock *, void *);
void Fragment_ProcessGeoLayoutList(S1_MemoryBlock* arg0, S1_arg1_func_80019420* arg1) ;

/* mkdraft:func_800416C8 begin */
typedef struct { s16 kind; s16 id; s16 buffer; s8 variant; u8 unknown07; OSMesgQueue *reply; void *data; s32 source; u8 *destination; s32 size; S1_arg1_func_80010CA8 adjustment; } SceneWorkerMessageLoad;
extern u8 *MainPool_InitState(u8 *, s32);
extern void MainPool_FinalizeAllocation(S1_MemoryBlock *);
extern OSThread D_80126530;

void func_800416C8(SceneWorkerMessageLoad *message) ;
/* mkdraft:func_800416C8 end */

typedef struct {
    s16 kind;
    s16 id;
    s16 buffer;
    s8 variant;
    u8 unknown07;
    OSMesgQueue *reply;
    void *data;
    s32 source;
    u8 *destination;
    s32 size;
    S1_arg1_func_80010CA8 adjustment;
} SceneWorkerMessage;
extern u8 *MainPool_InitState(u8 *, s32);
extern void MainPool_FinalizeAllocation(S1_MemoryBlock *);
extern OSThread D_80126530;
void PokeIcon_LoadResourceList(SceneWorkerMessage *message) ;

s32 func_80041430(s32, s32, s32, s32, s32, s32);
extern OSThread D_80126530;
void func_8002B1A0(void);
s32 func_80041430(s32, s32, s32, s32, s32, s32);
void func_80041A18(void *arg0) ;

extern void __osSetFpcCsr(s32);
// Dispatcher passes an OSMesg (void*) that this handler reads as a
// SceneWorkerMessageLoad (the typedef above func_800416C8's splice).
extern void func_800416C8(SceneWorkerMessageLoad *);
extern void PokeIcon_LoadResourceList(SceneWorkerMessage *);
extern void func_8004186C(void *);
extern void func_80041A18(void *arg0);
extern OSMesgQueue D_80126F00;
void func_80041A78(void *arg0) ;

void func_80041A78(void *);
extern void *D_80126EE0;
extern OSMesgQueue D_80126F00;
void func_80041B84(void) ;

typedef struct {
    OSMesgQueue queue;
    OSMesg messages[2];
} SceneLoadQueue;
typedef struct {
    u8 flags;
    u8 pending;
    u8 variant;
    u8 bufferCount;
    void *modelBuffers[2];
    void *backgroundBuffer;
    void *animationBuffers[2];
    void *imageBuffers[2];
    s32 modelBufferSize;
    s32 animationBufferSizes[2];
    s32 modelSize;
    s32 backgroundSize;
    s32 curveSize;
    SceneAnimationBank *loadedModel;
    void *loadedBackground;
    void *loadedCurve;
    u32 unknown44;
    S1_arg1_func_80010CA8 colorAdjust;
    u16 species;
    u16 unknown4E;
    SceneLoadQueue queues[4];
} SceneLoadContext;
void PokeIcon_InitLoadContext(SceneLoadContext *context, s32 flags, s32 modelBufferSize) ;

extern s32 main_pool_alloc(s32, s32);
SceneLoadContext *PokeIcon_AllocLoadContext(u32 flags) ;

SceneLoadContext *PokeIcon_AllocSpecialModelContext(u16 modelId) ;

extern s32 BinArchive_Open(s32, s32, s32, s32);
typedef void (*SceneFragmentEntry)(void);
extern SceneFragmentEntry Fragment_Load(s32, u8 *, u8 *);
extern u8 D_81000000[];
extern u8 fragment26_ROM_START[];
extern u8 fragment27_ROM_START[];
extern OSThread D_80126530;
void PokeIcon_InitResourceArchives(void) ;

s32 main_pool_alloc(s32, s32);
s32 BinArchive_Open(s32, s32, s32, s32);
extern s32 D_80126F28;
extern s32 D_80126F2C;
void func_80041F14(void) ;

extern s16 D_8009F428[];
s32 func_80041F60(s16 *arg0) ;

typedef union { s32 word; s8 bytes[4]; } Func80041FA0State;
typedef Func80041FA0State Func80041FA0Packed;
extern s32 func_80041FD0(s32, u16, Func80041FA0State, s32);
void func_80041FA0(s32 arg0, u16 arg1, Func80041FA0State arg2) ;

extern void *Util_Malloc(s32);
extern OSMesgQueue D_80126F00;
s32 func_800421E0(u8 *arg0, s32 arg1, s32 arg2) ;

extern OSMesgQueue D_80126F00;
s32 func_800422B4(u8 *arg0, s32 arg1, u16 arg2, u16 arg3) ;

extern OSMesgQueue D_80126F00;
s32 func_8004239C(u8 *arg0, s32 arg1) ;

u32 Model_FindLowestTextureAddress(SceneTextureModel *model) ;

typedef struct {
    s16 kind;
    s16 id;
    s16 buffer;
    s8 variant;
    u8 unknown07;
    OSMesgQueue *reply;
    void *data;
    s32 source;
    void *destination;
    s32 size;
    S1_arg1_func_80010CA8 adjustment;
} SceneLoadResult;
extern void Util_Free(void *);
s32 PokeIcon_ApplyResourceLoadResult(SceneLoadContext *context, SceneLoadResult *message) ;

extern s32 PokeIcon_ApplyResourceLoadResult(SceneLoadContext *, SceneLoadResult *);

s32 func_800427B8(s32 arg0) ;

s32 func_80042808(s32 arg0) ;

s32 func_80042858(s32 arg0) ;

s32 func_800428A8(s32 arg0) ;

extern s32 PokeIcon_ApplyResourceLoadResult(SceneLoadContext *, SceneLoadResult *);

void func_800428F8(s32 arg0) ;

void PokeIcon_WaitBackgroundLoad(s32 arg0) ;

void func_80042968(s32 arg0) ;

void func_800429A0(s32 arg0) ;

s32 func_80042A64(s32 arg0) ;

extern void *func_80004B4C(s32 arg0, s32 arg1);
extern S1_MemoryBlock *MainPool_AllocState(s32 arg0, s32 arg1);
extern s32 main_pool_get_available(void);
extern void MainPool_FinalizeAllocation(S1_MemoryBlock *arg0);
extern s32 D_80126F24;
S1_arg1_func_80019420 *BattleAnim_LoadResourceTable(s32 arg0) ;

s32 func_80042ADC(u8 *arg0) ;

#endif

#endif
