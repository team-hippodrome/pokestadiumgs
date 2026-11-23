// include/229E0.h declares these four audio register wrappers with s32 formals
// (a spelling that exists so the `s32 *p = &arg0;` masks in src/340C0.c compile).
// The retail wrappers take u8: func_800333CC's switch passes a u8 local and the
// targets mask with `andi a0,a1,0xFF` only under a u8 formal. Renaming the four
// identifiers during the include keeps the header's s32 declarations out of
// this TU; nothing else in this file calls them.
#define func_8003364C func_8003364C_s32decl
#define func_800337D8 func_800337D8_s32decl
#define func_80033864 func_80033864_s32decl
#define func_8003386C func_8003386C_s32decl
#include "229E0.h"
#undef func_8003364C
#undef func_800337D8
#undef func_80033864
#undef func_8003386C

#ifdef VERSION_US

void func_80032E40(u8 arg0) {
    u8 *p = &D_800D2B78 + (arg0 * 3 * 4 * 5);
    *(u16 *)(p + 0) = 0; p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0;
    *(s32 *)(p + 8) = 0; *(s32 *)(p + 12) = 0; *(s32 *)(p + 16) = 0;
    p[20] = 0; p[21] = 0; p[22] = 0; p[23] = 0; *(u16 *)(p + 24) = 0;
    p[26] = 0; p[27] = 0; p[28] = 0; p[29] = 0; p[30] = 0; p[31] = 0; p[32] = 0; *(u16 *)(p + 34) = 0;
    p[36] = 0; p[37] = 0; p[38] = 0; p[39] = 0; p[40] = 0; p[41] = 0; p[42] = 0; p[43] = 0; p[44] = 0; p[45] = 0; p[46] = 0; p[47] = 0;
    *(u16 *)(p + 48) = 0; p[50] = 0; p[51] = 0; p[52] = 0; p[53] = 0; p[54] = 0; p[55] = 0; p[56] = 0; p[57] = 0;
}

void GbAudio_ResetState(void) {
    OSIntMask saved_mask;
    u32 index;

    saved_mask = osSetIntMask(OS_IM_NONE);
    func_800331C8();
    osSetIntMask(saved_mask);
    for (index = 0; index < 4; index++) {
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF10, 0, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF11, 0, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF12, 8, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF13, 0, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF14, 0x80, 0);
    }
    GbAudio_QueueRegisterWrite(0xFF24, 0, 0);
    GbAudio_QueueRegisterWrite(0xFF25, 0, 0);
    GbAudio_QueueRegisterWrite(0xFF26, 0x80, 0);
    for (index = 0; index != 8; index++) {
        func_80032E40(index);
    }
    D_800D2B40 = 0;
    D_800D2B42 = 0;
    D_800D2B43 = 0;
    D_800D2B44 = 0;
    D_800D2B46 = 0;
    D_800D2B47 = 0;
    D_800D2B48 = 0;
    D_800D2B4A = 0;
    D_800D2B4B = 0;
    D_800D2B4C = 0;
    D_800D2B4E = 0;
    D_800D2B50 = 0;
    D_800D2B54 = 0;
    D_800D2B55 = 0;
    D_800D2B56 = 0;
    D_800D2B57 = 0;
    D_800D2B58 = 0;
    D_800D2B59 = 0;
    D_800D2B5A = 0;
    D_800D2B5C = 0;
    D_800D2B5E = 0;
    D_800D2B5F = 0;
    D_800D2B60 = 0;
    D_800D2B62 = 0;
    D_800D2B64 = 0;
    D_800D2B66 = 0;
    D_800D2B68 = 0;
    D_800D2B69 = 0;
    D_800D2B6A = 0;
    D_800D2B6B = 0;
    D_800D2B6C = 0;
    D_800D2B6D = 0;
    D_800D2B6E = 0;
    D_800D2B6F = 0;
    D_800D2B70[0] = 0;
    D_800D2B70[1] = 0;
    D_800D2B70[2] = 0;
    D_800D2B73 = 0;
    D_800D2B49 = 0x77;
    saved_mask = osSetIntMask(OS_IM_NONE);
    func_800331B8();
    osSetIntMask(saved_mask);
}

void func_80033188(void) {
    u16 sp1E;

    sp1E = D_800D2B5C;
    GbAudio_ResetState();
    D_800D2B5C = sp1E;
}

 void func_800331B8(void) { D_800D2B41 = 1; }

 void func_800331C8(void) { D_800D2B41 = 0; }

/* mkdraft:func_800331D4 begin */
void func_800333CC(u8 arg0);

// D_800D2B78 holds eight 0x3C-byte GbAudioStreamRecord entries; the record
// checks below address them through this base.
#define REC(i) (((GbAudioStreamRecord *)&D_800D2B78)[i])



void func_800331D4(void) {
    u32 i;
    u8 channel;

    if (D_800D2B41 != 0) {
        D_800D2B4A = 0;
        for (i = 0; i != 8; i++) {
            if (REC(i).flags_03 & 1) {
                channel = i;
                if (REC(i).unk_1D < 2) {
                    REC(i).unk_26 = REC(i).unk_27;
                    REC(i).flags_04 &= ~2;
                    GbAudio_ProcessChannelStream(channel);
                } else {
                    REC(i).unk_1D--;
                }
                func_80033BF4(channel);
                D_800D2B42 = REC(i).unk_16;
                D_800D2B43 = REC(i).unk_17;
                D_800D2B44 = REC(i).unk_18;
                func_800339EC(channel);
                func_80033C48(channel & 0xFF);
                if (D_800D2B6A != 0 && i < 4 &&
                        ((REC(4).flags_03 & 1) || (REC(5).flags_03 & 1) ||
                         (REC(6).flags_03 & 1) || (REC(7).flags_03 & 1))) {
                    REC(i).flags_14 |= 0x20;
                }
                if (i >= 4 || !(REC(4).flags_03 & 1)) {
                    func_800333CC(channel);
                    D_800D2B4A |= REC(i).unk_24;
                }
                REC(i).flags_14 = 0;
            }
        }
        func_800319D0(0xFF24, D_800D2B49, 0);
        func_800319D0(0xFF25, D_800D2B4A, 0);
    }
}
/* mkdraft:func_800331D4 end */

/* mkdraft:func_800333CC begin */
extern void func_80033488(u8 arg0);
extern void func_800334C0(u8 arg0);
extern void func_80033670(u8 arg0);
extern void func_80033890(u8 arg0);
extern void func_8003364C(u8 arg0);
extern void func_800337D8(u8 arg0);
extern void func_80033864(u8 arg0);
extern void func_8003386C(u8 arg0);
// No FAKE construct in this body. The u8 formals above are the real types: every
// callee masks its own argument (andi a0,a0,0xff in its jal delay slot), and a
// u8-parameter definition of the wrappers reproduces retail 9/9 (t36.py), while
// the s32 spelling declared in include/229E0.h needs an "s32 *p = &arg0;" hack
// to get there. The header types are the artifact, not this code.
// TU consequence: include/229E0.h declares func_8003364C/337D8/33864/3386C with
// s32, so these u8 externs conflict with it (hard cfe error) unless the TU hides
// those four names with a #define/#undef pair around the #include -- which is
// what the top of this file does. No other function in this file calls them.



void func_800333CC(u8 arg0) {
    u8 v;
    v = arg0 & 7;
    switch (v) {
    case 0: func_80033488(v); break;
    case 1: func_8003364C(v); break;
    case 2: func_800337D8(v); break;
    case 3: func_8003386C(v); break;
    case 4: func_800334C0(v); break;
    case 5: func_80033670(v); break;
    case 6: func_80033864(v); break;
    case 7: func_80033890(v); break;
    }
}
/* mkdraft:func_800333CC end */

void GbAudio_UpdateChannelIfEnabled(u8 channel) {
    if (!(D_800D2B58 & 0x80)) {
        GbAudio_UpdateSquare1Registers(channel);
    }
}

#endif
