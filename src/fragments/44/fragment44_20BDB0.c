#include "global.h"


#ifdef VERSION_US
typedef struct { u32 words[0x52C / 4]; } Snapshot_8AF1DB40;
extern Snapshot_8AF1DB40 *D_8AF27930;
extern Snapshot_8AF1DB40 D_8AF37868;
extern s16 D_8AF37860;
extern s16 D_8AF37862;
extern s16 D_8AF37798;
extern s16 D_8AF2C9E2;

void func_8AF1DB40(void) {
    *D_8AF27930 = D_8AF37868;
    D_8AF37798 = D_8AF37860;
    D_8AF2C9E2 = D_8AF37862;
}

extern s16 D_8AF27934;

void func_8AF1DBA4(void) {
    D_8AF37868 = *D_8AF27930;
    D_8AF37860 = D_8AF37798;
    D_8AF37862 = D_8AF2C9E2;
    D_8AF27934 = 1;
}

typedef struct {
    u32 unk_00[321];
} unk_func_8AF1DC14;

void func_8AF1DC14(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 arg10,
                   s32 arg11, s32 arg12, const unk_func_8AF1DC14 *arg13) {
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
    *(unk_func_8AF1DC14 *)(arg0 + 0x28) = *arg13;
}


typedef struct { u16 h[7]; } Blob14_8AF1DCD4;
extern Blob14_8AF1DCD4 D_8AF37F38; extern s32 D_8AF27938; void func_8AF1DCA8(void) { _bzero(&D_8AF37F38, 0xE); D_8AF27938 = 0; }

extern u8 *func_8AF00504(s32);
extern s32 func_8AF003A8(s32);
extern u8 *func_8AC06D8C(u8 *, s32);
extern s32 func_8004E308(u8 *, void *, u8 *);
extern void func_8AC03C28(void);
extern void func_8AC05E40(u8 *, s32, u8 *);
extern void func_8AC05ED4(u8 *, s32, u8 *);
extern void func_8AC02C80(u8 *, s32, s32, u8 *);
extern void func_8AC06400(u8 *, u8 *);
extern void func_8AC0651C(u8 *, s16, s16, s16, s16);
extern u8 *D_8AF37E88;
extern u8 D_8AF37F08[];
extern u8 D_8AF37E90[];
extern Blob14_8AF1DCD4 D_8AF37F48;
extern u8 D_8AF37D98[];
extern u8 D_8AF37E10[];
extern s16 D_8AF37798;
extern s16 D_8AF2BA90[];
extern void func_8AF1DB40(void);
extern s32 func_8004C874(s32, s32);
extern void func_8004C54C(s32, s32);
extern s32 func_8004C594(s32, s32);
extern s32 func_8AF01718(void *, s32);
extern s32 func_8AF02DA4(void *, s32);
typedef struct {
    s16 f00; u16 f02;
    u8 pad04[0x2C];
    s16 f30; s16 f32;
} Node8AF1DCD4;
typedef struct {
    s16 f6C, f6E;
    s32 f70, f74;
    s16 f78, f7A, f7C, f7E, f80;
    u8 pad82[0xE];
    s32 f90, f94, f98;
    u8 pad9C[4];
    s32 fA0, fA4;
    s16 fA8, fAA;
    u8 padAC[0xA];
    s16 fB6;
    u8 padB8[0x4B8];
} Buf8AF1DCD4;
void func_8AF1DCD4(void) {
    s32 pad0[3]; // FAKE
    s32 h;
    Buf8AF1DCD4 buf;
    s32 pad2; // FAKE
    s32 w;
    u8 *n1;
    u8 *n3;
    u8 *n2;
    u8 *n0;
    u8 *root;
    u8 *snap;
    s32 res;

    func_8AF00504(0x89);
    root = (u8 *)func_8AF003A8(0x89);
    n0 = func_8AC06D8C(root, 0x70696330);
    n1 = func_8AC06D8C(root, 0x70696363);
    ((Node8AF1DCD4 *)n0)->f02 |= 1;
    func_8004E308(n0, func_8AC03C28, n1);
    n1 = func_8AC06D8C(root, 0x77695F31);
    n2 = func_8AC06D8C(root, 0x7469746C);
    ((Node8AF1DCD4 *)n2)->f30 = 0x3B;
    n3 = func_8AC06D8C(root, 0x736C6966);
    ((Node8AF1DCD4 *)n3)->f30 = 0x3B;
    ((Node8AF1DCD4 *)n3)->f32 = 0x1C;
    ((Node8AF1DCD4 *)n3)->f02 &= ~2;
    D_8AF37E88 = func_8AC06D8C(root, 0x6162746E);
    func_8AC05E40(root, 0x6162746E, D_8AF37E90);
    func_8AC06400(D_8AF37E90, D_8AF37E88);
    func_8AC02C80(root, 0x725F6C5F, 0x725F725F, D_8AF37F08);
    func_8AC05ED4(root, 0x79613175, D_8AF37D98);
    func_8AC05ED4(root, 0x79613173, D_8AF37E10);
    w = *(s16 *)(n1 + 8);
    h = *(s16 *)(n1 + 0xA);
    _bzero(&buf, 0x504);
    buf.f6C = *(s16 *)(n1 + 0xC);
    buf.f6E = *(s16 *)(n1 + 0xE);
    buf.f80 = 0xD;
    buf.f90 = 0x55;
    buf.f94 = 0x41;
    buf.f98 = 6;
    buf.fA8 = 3;
    buf.f70 = 0;
    buf.f74 = 0;
    buf.f78 = 0;
    buf.f7A = 0;
    buf.f7E = 0;
    buf.fAA = 1;
    buf.fA0 = 5;
    buf.fA4 = 0;
    buf.fB6 = 0x41;
    func_8AF1DC14((u8 *)D_8AF27930, 0xA, w, h, 8, 0, 0, 0, 0x64, 0x64, 0x64, 4, 0xB, (void *)&buf);
    if (D_8AF27934 == 1) {
        func_8AF1DB40();
    }
    res = func_8004C874(0x3B, D_8AF37798 + 0x12);
    func_8004C54C(0x3D, res);
    ((Node8AF1DCD4 *)n2)->f32 = 0xC4;
    res = func_8AF01718(*(void **)&D_8AF2BA90, D_8AF37798);
    func_8AF02DA4(D_8AF27930, res);
    snap = (u8 *)D_8AF27930 + 0x28;
    func_8AC0651C(&D_8AF37F38, (s16)((*(s32 *)(snap + 0x20) - 1) / 6), 0x3C, 3, 0xA);
    if (D_8AF27938 != 0) {
        D_8AF37F38 = D_8AF37F48;
        D_8AF27938 = 0;
    }
    func_8004C594(2, *(s32 *)(snap + 0x20));
    ((Node8AF1DCD4 *)n3)->f02 |= 2;
}

extern void *D_8AF263C0;

extern u16 D_8AF2BDC6;

extern s16 D_8AF2D302;

extern s32 func_8AF0326C(void *);

extern void func_8AF00130(s32);

extern u8 func_8AF01654(u8);

extern void func_8AC0686C(void *, s16);

extern void func_8AC0619C(void *, u16);

extern void func_8AC06220(void *, u16);

extern void func_8AC063AC(void *, u16);

s16 func_8AF1E034(void) {
    s16 result;
    Snapshot_8AF1DB40 *snapshot;
    u8 *sub;
    u8 *cfg;
    unsigned long buttons;
    s16 state;
    s16 value;
    u8 code;
    result = 24;
    snapshot = D_8AF27930;
    sub = (u8 *)snapshot + 40;
    cfg = (u8 *)snapshot + 68;
    if (func_8AF0326C(snapshot) == 0 && (state = *(s16 *)(sub + 18)) == 0) {
        {
            buttons = *(u16 *)((u8 *)D_8AF263C0 + 8);
            buttons ^= 0;
            if (buttons & 0x4000) {
                func_8AF00130(3);
                result = 23;
                D_8AF27934 = 0;
            } else if (state == 0 && (buttons & 0x8000)) {
                D_8AF37F48 = D_8AF37F38;
                D_8AF27938 = 1;
                state = (s16)(*(s16 *)(sub + 12) + *(s32 *)(cfg + 16) * *(s16 *)(sub + 16));
                value = *(s16 *)(*(u8 **)(sub + 28) + state * 2);
                if (state < *(s32 *)(cfg + 4)) {
                    code = func_8AF01654(value);
                    *(s16 *)(sub + 22) = value;
                    D_8AF2D302 = value;
                    func_8AF1DBA4();
                    D_8AF37798 = value;
                    if ((code & 0xF) == ((code & 0xF0) >> 4)) result = 26;
                    else result = 27;
                    func_8AF00130(194);
                }
            }
        }
    }
    func_8AC0686C(&D_8AF37F38, *(s16 *)(sub + 16));
    func_8AC0619C(D_8AF37D98, D_8AF2BDC6);
    func_8AC06220(D_8AF37E10, D_8AF2BDC6);
    func_8AC063AC(D_8AF37E90, D_8AF2BDC6);
    return result;
}
extern u8 D_8AF37D98[];
extern u8 D_8AF37E10[];

extern void func_8AC00738(void);
extern s32 func_8AC0665C(s16 *, s16);
extern s32 func_8AC0672C(void *, s16);
void func_8AF1E1F4(void) {
    Snapshot_8AF1DB40 *snapshot;
    u8 *bytes; // FAKE: a u8 * copy of snapshot; diff score 24 without it.
    u8 *sub;
    s32 x;
    s32 y;

    snapshot = D_8AF27930;
    bytes = (u8 *)snapshot;
    sub = bytes + 0x28;
    x = *(s16 *)(bytes + 0x34) * *(s32 *)(bytes + 0x4C) + *(s32 *)(bytes + 0x5C) + *(s32 *)(bytes + 8) - 4;
    y = *(s16 *)(bytes + 0x36) * *(s32 *)(bytes + 0x50) + *(s32 *)(bytes + 0x60) + *(s32 *)(bytes + 0xC) - 2;
    func_8AC007B8(*(s32 *)(bytes + 8), *(s32 *)(bytes + 0xC), *(s16 *)sub, 260);
    func_8AF02F18(snapshot);
    func_8004B314(x, y, 88, 68);
    func_8AC00738();
    if (func_8AC0665C((s16 *)&D_8AF37F38, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF37D98);
    }
    if (func_8AC0672C(&D_8AF37F38, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF37E10);
    }
}
#endif
