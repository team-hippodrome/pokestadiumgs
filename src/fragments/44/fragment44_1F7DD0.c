#include "global.h"


#ifdef VERSION_US
typedef struct {
    u32 words[0x52C / 4];
} Snapshot_8AF09B60;

extern Snapshot_8AF09B60 D_8AF2CC38;
extern Snapshot_8AF09B60 *D_8AF26930;
extern s16 D_8AF2CC34;
extern s16 D_8AF2CC36;
extern s16 D_8AF2C9E0;
extern s16 D_8AF2C9E2;

void func_8AF09B60(void) {
    *D_8AF26930 = D_8AF2CC38;
    D_8AF2C9E0 = D_8AF2CC34;
    D_8AF2C9E2 = D_8AF2CC36;
}

extern s16 D_8AF26934;

void func_8AF09BC4(void) {
    D_8AF2CC38 = *D_8AF26930;
    D_8AF2CC34 = D_8AF2C9E0;
    D_8AF2CC36 = D_8AF2C9E2;
    D_8AF26934 = 1;
}

typedef struct Payload_8AF09C34 {
    u32 words[0x504 / 4];
} Payload_8AF09C34;
void func_8AF09C34(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                    u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 arg10,
                    s32 arg11, s32 arg12, const Payload_8AF09C34 *arg13) {
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s32 *)(arg0 + 8) = arg2;
    *(s32 *)(arg0 + 0xC) = arg3;
    *(s32 *)(arg0 + 0x10) = arg4;
    arg0[0x22] = arg5;
    arg0[0x23] = arg6;
    arg0[0x24] = arg7;
    arg0[0x25] = arg8;
    arg0[0x26] = arg9;
    arg0[0x27] = arg10;
    *(s32 *)arg0 = arg11;
    *(s32 *)(arg0 + 0x14) = -1;
    *(s32 *)(arg0 + 0x1C) = arg12;
    *(Payload_8AF09C34 *)(arg0 + 0x28) = *arg13;
}

// 14-byte snapshot header. Copying it as one object is what makes IDO expand the
// assignment into the retail word reads at 0, 8, 4 and the halfword read at 0xC,
// instead of the lwl/lwr pairs a pointer cast produces.
typedef struct { u16 h[7]; } Hdr14_8AF09CF4; extern Hdr14_8AF09CF4 D_8AF2D258; extern s32 D_8AF26938; void func_8AF09CC8(void) { _bzero(&D_8AF2D258, 0xE); D_8AF26938 = 0; }

void func_8004C54C(s32, s32);
s32 func_8004C594(s32, s32);
void *func_8004C874(s32, s32);
void func_8AC02C80(s32, s32, s32, s32 *);
void func_8AC05E40(s32, s32, s32 *);
void func_8AC05ED4(s32, s32, s32 *);
void func_8AC06400(s32 *, void *);
void func_8AC0651C(u8 *, s16, s16, s16, s16);
void *func_8AC06D8C(s32, s32);
void func_8AC06E98(s32);
s32 func_8AF003A8(s32);
void func_8AF00504(s32);
void func_8AF02DA4(s32, s32);
s32 func_8AF01718(s32 *, s16);
extern s16 D_8AF263C4[];
extern s32 *D_8AF2BA90;
extern s32 D_8AF2BAD0;
extern s16 D_8AF2CB80;
extern s32 D_8AF2CC08;
extern u8 D_8AF2D168[];
extern u8 D_8AF2D1E0[];
extern void *D_8AF2D268;
extern s32 D_8AF2D270;
extern Hdr14_8AF09CF4 D_8AF2D2E8;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s32 unk_04;
    s32 unk_08;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    u8 unk_16[0xE];
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    u8 unk_30[4];
    s32 unk_34;
    s32 unk_38;
    s16 unk_3C;
    s16 unk_3E;
    u8 unk_40[0xA];
    s16 unk_4A;
    u8 unk_4C[0x504 - 0x4C];
} ListConfig_8AF09CF4;



void func_8AF09CF4(void) {
    s32 page;
    s32 sel;
    s32 arg2;
    s32 arg3;
    ListConfig_8AF09CF4 config;
    u8 *list;
    u8 *dst; // FAKE: never read; reserves the 0x54 stack slot. Diff score 36 without it.
    void *node_wi;
    void *btn;
    void *title;

    func_8AF00504(0x89);
    page = func_8AF003A8(0x89);
    func_8AC06E98(page);
    node_wi = func_8AC06D8C(page, 0x77695F31);
    title = func_8AC06D8C(page, 0x7469746C);
    *(s16 *)((u8 *)title + 0x30) = 0x3B;
    btn = func_8AC06D8C(page, 0x736C6966);
    *(s16 *)((u8 *)btn + 0x30) = 0x3B;
    *(s16 *)((u8 *)btn + 0x32) = 0x1C;
    *(u16 *)((u8 *)btn + 2) &= 0xFFFD;
    func_8AC02C80(page, 0x725F6C5F, 0x725F725F, &D_8AF2CC08);
    D_8AF2D268 = func_8AC06D8C(page, 0x6162746E);
    func_8AC05E40(page, 0x6162746E, &D_8AF2D270);
    func_8AC06400(&D_8AF2D270, D_8AF2D268);
    func_8AC05ED4(page, 0x79613175, &D_8AF2D168);
    func_8AC05ED4(page, 0x79613173, &D_8AF2D1E0);
    arg2 = *(s16 *)((u8 *)node_wi + 8);
    arg3 = *(s16 *)((u8 *)node_wi + 0xA);
    _bzero(&config, 0x504);
    config.unk_00 = *(s16 *)((u8 *)node_wi + 0xC);
    config.unk_02 = *(s16 *)((u8 *)node_wi + 0xE);
    config.unk_14 = 0xD;
    config.unk_24 = 0x55;
    config.unk_28 = 0x41;
    config.unk_2C = 6;
    config.unk_3C = 3;
    config.unk_04 = 0;
    config.unk_08 = 0;
    config.unk_0C = 0;
    config.unk_0E = 0;
    config.unk_12 = 0;
    config.unk_3E = 1;
    config.unk_34 = 5;
    config.unk_38 = 0;
    config.unk_4A = 0x41;
    func_8AF09C34((u8 *)D_8AF26930, 0xA, arg2, arg3, 8, 0, 0, 0, 0x64, 0x64, 0x64,
                  4, 0xB, (Payload_8AF09C34 *)&config);
    if (D_8AF26934 == 1) {
        func_8AF09B60();
    }
    switch (D_8AF2CB80) {
    case 0:
        func_8004C54C(0x3D, func_8004C874(0x3B, D_8AF2C9E0 + 0x12));
        *(s16 *)((u8 *)title + 0x32) = 0xC4;
        sel = func_8AF01718(D_8AF2BA90, D_8AF2C9E0);
        break;
    case 1:
        func_8004C54C(0x3D, func_8004C874(0xC, D_8AF263C4[D_8AF2C9E2]));
        *(s16 *)((u8 *)title + 0x32) = 0xC3;
        sel = func_8AF01718(&D_8AF2BAD0, D_8AF2C9E2);
        break;
    default:
        *(s16 *)((u8 *)title + 0x32) = 0xC4;
        sel = func_8AF01718(D_8AF2BA90, D_8AF2C9E0);
        break;
    }
    func_8AF02DA4((s32)D_8AF26930, sel);
    list = (u8 *)D_8AF26930 + 0x28;
    func_8AC0651C((u8 *)&D_8AF2D258, (s16)((*(s32 *)(list + 0x20) - 1) / 6), 0x3C, 3, 0xA);
    if (D_8AF26938 != 0) {
        D_8AF2D258 = D_8AF2D2E8;
        D_8AF26938 = 0;
    }
    func_8004C594(2, *(s32 *)(list + 0x20));
    *(u16 *)((u8 *)btn + 2) |= 2;
}

extern void *D_8AF263C0;
extern u8 D_8AF2BDC4[];
extern u8 D_8AF2D168[];
extern u8 D_8AF2D1E0[];
extern s16 D_8AF2D300;
extern s16 D_8AF2D302;
extern s16 D_8AF2D304;
extern void func_8AC0619C(void *, u16);
extern void func_8AC06220(void *, u16);
extern void func_8AC063AC(void *, u16);
extern void func_8AC0686C(void *, s16);
extern void func_8AF00130(s32 code);
extern s32 func_8AF0326C(void *);
extern void func_8AF09BC4(void);



s16 func_8AF0A0B4(void) {
    s16 result;
    Snapshot_8AF09B60 *snapshot;
    u8 *bytes; // FAKE: u8 * copy of snapshot; without it the frame shrinks to 0x38 and result moves to 0x36 (diff 813).
    u8 *sub;
    u8 *cfg;
    s16 index;
    s16 value;

    result = 9;
    snapshot = D_8AF26930;
    bytes = (u8 *)snapshot;
    sub = bytes + 0x28;
    cfg = bytes + 0x44;
    if (func_8AF0326C(snapshot) == 0 && *(s16 *)(sub + 0x12) == 0) {
        if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
            func_8AF00130(3);
            result = 8;
            D_8AF26934 = 0;
        } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x8000) {
            D_8AF2D2E8 = D_8AF2D258;
            D_8AF26938 = 1;
            index = *(s16 *)(sub + 0xC) +
                    *(s32 *)(cfg + 0x10) * *(s16 *)(sub + 0x10);
            value = *(s16 *)(*(u8 **)(sub + 0x1C) + index * 2);
            if (index < *(s32 *)(cfg + 4)) {
                func_8AF00130(0xC2);
                *(s16 *)(sub + 0x16) = value;
                D_8AF2D302 = value;
                result = 10;
                D_8AF2D300 = 9;
                D_8AF2D304 = 1;
                func_8AF09BC4();
            }
        }
    }
    func_8AC0686C(&D_8AF2D258, *(s16 *)(sub + 0x10));
    func_8AC0619C((void *)D_8AF2D168, *(u16 *)(D_8AF2BDC4 + 2));
    func_8AC06220((void *)D_8AF2D1E0, *(u16 *)(D_8AF2BDC4 + 2));
    func_8AC063AC((void *)&D_8AF2D270, *(u16 *)(D_8AF2BDC4 + 2));
    return result;
}

extern void func_8AC007B8(s32, s32, s32, s32);
extern void func_8AF02F18(void *);
extern void func_8004B314(s32, s32, s32, s32);
extern void func_8AC00738(void);
extern void func_8AC05F00(void *);
extern s32 func_8AC0665C(s16 *, s16);
extern s32 func_8AC0672C(void *, s16);
extern u8 D_8AF2D168[];
extern u8 D_8AF2D1E0[];

// Same code as func_8AF1E1F4 in fragment44_20BDB0.c, for this file's snapshot D_8AF26930,
// list D_8AF2D258 and strings D_8AF2D168/D_8AF2D1E0.
//@src/fragments/44/fragment44_20BDB0.c
void func_8AF0A244(void) {
    Snapshot_8AF09B60 *snapshot;
    u8 *bytes; // FAKE: a u8 * copy of snapshot; diff score 24 without it.
    u8 *sub;
    s32 x;
    s32 y;

    snapshot = D_8AF26930;
    bytes = (u8 *)snapshot;
    sub = bytes + 0x28;
    x = *(s16 *)(bytes + 0x34) * *(s32 *)(bytes + 0x4C) + *(s32 *)(bytes + 0x5C) + *(s32 *)(bytes + 8) - 4;
    y = *(s16 *)(bytes + 0x36) * *(s32 *)(bytes + 0x50) + *(s32 *)(bytes + 0x60) + *(s32 *)(bytes + 0xC) - 2;
    func_8AC007B8(*(s32 *)(bytes + 8), *(s32 *)(bytes + 0xC), *(s16 *)sub, 260);
    func_8AF02F18(snapshot);
    func_8004B314(x, y, 88, 68);
    func_8AC00738();
    if (func_8AC0665C((s16 *)&D_8AF2D258, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF2D168);
    }
    if (func_8AC0672C(&D_8AF2D258, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF2D1E0);
    }
}
#endif
