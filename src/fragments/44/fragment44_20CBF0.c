#include "global.h"


#ifdef VERSION_US
typedef struct {
    u32 words[0x52C / 4];
} Snapshot_8AF1E9D4;
extern Snapshot_8AF1E9D4 *D_8AF27960;
extern Snapshot_8AF1E9D4 D_8AF388C0;
extern s16 D_8AF3779A;
extern s16 D_8AF388BA;
extern s16 D_8AF27964;
void func_8AF1E980(void) {
    *D_8AF27960 = D_8AF388C0;
    D_8AF3779A = D_8AF388BA;
}
void func_8AF1E9D4(void) {
    D_8AF388C0 = *D_8AF27960;
    D_8AF388BA = D_8AF3779A;
    D_8AF27964 = 1;
}

typedef struct Payload_8AF1EA34 {
    u32 words[0x504 / 4];
} Payload_8AF1EA34;
void func_8AF1EA34(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                    u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 arg10,
                    s32 arg11, s32 arg12, const Payload_8AF1EA34 *arg13) {
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
    *(Payload_8AF1EA34 *)(arg0 + 0x28) = *arg13;
}

typedef struct { u16 h[7]; } Hdr14_8AF1EAC8;
extern Hdr14_8AF1EAC8 D_8AF39190; extern s32 D_8AF27968; void func_8AF1EAC8(void) { _bzero(&D_8AF39190, 0xE); D_8AF27968 = 0; }

extern Hdr14_8AF1EAC8 D_8AF391A0;
extern void *D_8AF263C0;
extern s16 D_8AF2D300;
extern s16 D_8AF2D302;
extern s16 D_8AF2D304;
extern u8 D_8AF2BDC4[];
extern u8 D_8AF38DF0[];
extern u8 D_8AF38E68[];
extern u8 D_8AF39118[];
extern s32 func_8AF0326C(void *);
extern void func_8AF00130(s32);
extern void func_8AC0686C(void *, s16);
extern void func_8AC0619C(void *, u16);
extern void func_8AC06220(void *, u16);
extern void func_8AC063AC(void *, u16);

extern void func_8AF00504(s32);

extern s32 func_8AF003A8(s32);

extern void func_8AC06E98(s32);

extern s32 func_8AC06D8C(s32, s32);

extern void func_8AC03C28(void);

extern void func_8004E308(s32, void *, void *);

extern void *D_8AF39110;

extern u8 D_8AF38EE0[];

extern s16 D_8AF38F10[];

extern u16 *D_8AF2BAB0;

extern void *D_8AF2BA90;

extern void func_8AC05E40(s32, s32, void *);

extern void func_8AC06400(void *, void *);

extern void func_8AC02C80(s32, s32, s32, void *);

extern void func_8AC05ED4(s32, s32, void *);

extern s32 func_8004C874(s32, s32);

extern void func_8004C54C(s32, s32);

extern s16 *func_8AF01718(void *, s16);

extern void func_8AF02DA4(void *, void *);

extern void func_8AC0651C(void *, s16, s32, s32, s32);

extern s32 func_8004C594(s32, s32);

void func_8AF1EAF4(void) {
    s32 pad0[4]; // FAKE: preserves the original frame size.
    s32 page;
    s32 height;
    Payload_8AF1EA34 payload;
    s32 visible;
    s16 *sel;
    s32 w1;
    s32 slif;
    s32 title;
    s32 pic1;
    s32 pic0;
    s16 *dest;
    u16 *flags;
    func_8AF00504(137);
    page = func_8AF003A8(137);
    func_8AC06E98(page);
    w1 = func_8AC06D8C(page, 0x77695F31);
    title = func_8AC06D8C(page, 0x7469746C);
    *(s16 *)((u8 *)title + 0x30) = 59;
    slif = func_8AC06D8C(page, 0x736C6966);
    *(s16 *)((u8 *)slif + 0x30) = 59;
    *(s16 *)((u8 *)slif + 0x32) = 28;
    *(u16 *)((u8 *)slif + 2) &= ~2;
    pic0 = func_8AC06D8C(page, 0x70696330);
    pic1 = func_8AC06D8C(page, 0x70696363);
    *(u16 *)((u8 *)pic0 + 2) |= 1;
    func_8004E308(pic0, func_8AC03C28, (void *)pic1);
    D_8AF39110 = (void *)func_8AC06D8C(page, 0x6162746E);
    func_8AC05E40(page, 0x6162746E, D_8AF39118);
    func_8AC06400(D_8AF39118, D_8AF39110);
    func_8AC02C80(page, 0x725F6C5F, 0x725F725F, D_8AF38EE0);
    func_8AC05ED4(page, 0x79613175, D_8AF38DF0);
    func_8AC05ED4(page, 0x79613173, D_8AF38E68);
    visible = *(s16 *)((u8 *)w1 + 8);
    height = *(s16 *)((u8 *)w1 + 0xA);
    _bzero(&payload, 1284);
    *(s16 *)((u8 *)&payload + 0) = *(s16 *)((u8 *)w1 + 0xC);
    *(s16 *)((u8 *)&payload + 2) = *(s16 *)((u8 *)w1 + 0xE);
    *(s32 *)((u8 *)&payload + 4) = 0;
    *(s32 *)((u8 *)&payload + 8) = 0;
    *(s16 *)((u8 *)&payload + 0xC) = 0;
    *(s16 *)((u8 *)&payload + 0xE) = 0;
    *(s16 *)((u8 *)&payload + 0x12) = 0;
    *(s16 *)((u8 *)&payload + 0x14) = 13;
    *(s32 *)((u8 *)&payload + 0x24) = 85;
    *(s32 *)((u8 *)&payload + 0x28) = 65;
    *(s32 *)((u8 *)&payload + 0x2C) = 6;
    *(s16 *)((u8 *)&payload + 0x3C) = 3;
    *(s16 *)((u8 *)&payload + 0x3E) = 1;
    *(s32 *)((u8 *)&payload + 0x34) = 5;
    *(s32 *)((u8 *)&payload + 0x38) = 0;
    *(s16 *)((u8 *)&payload + 0x4A) = 65;
    func_8AF1EA34((u8 *)D_8AF27960, 10, visible, height, 8, 0, 0, 0, 100, 100, 100, 4, 11, &payload);
    if (D_8AF27964 == 1) func_8AF1E980();
    func_8004C54C(61, func_8004C874(59, D_8AF3779A + 18));
    *(s16 *)((u8 *)title + 0x32) = 196;
    sel = func_8AF01718(D_8AF2BA90, D_8AF3779A);
    flags = D_8AF2BAB0;
    dest = D_8AF38F10;
    while (1) {
        pic1 = *sel;
        if (pic1 == -1) break;
        if (flags[pic1 - 1] & 0x20) *dest++ = pic1;
        sel++;
    }
    *dest = -1;
    func_8AF02DA4(D_8AF27960, D_8AF38F10);
    page = (s32)D_8AF27960;
    page += 0x28;
    func_8AC0651C(&D_8AF39190, (s16)((*(s32 *)((u8 *)page + 0x20) - 1) / 6), 60, 3, 10);
    if (D_8AF27968 != 0) {
        D_8AF39190 = D_8AF391A0;
        D_8AF27968 = 0;
    }
    func_8004C594(2, *(s32 *)((u8 *)page + 0x20));
    *(u16 *)((u8 *)slif + 2) |= 2;
}
s16 func_8AF1EEA8(void) {
    s16 result;
    Snapshot_8AF1E9D4 *snapshot;
    u8 *bytes; // FAKE: u8 * copy of snapshot; without it the frame shrinks and result moves.
    u8 *sub;
    u8 *cfg;
    s16 index;
    s16 value;

    result = 0x1C;
    snapshot = D_8AF27960;
    bytes = (u8 *)snapshot;
    sub = bytes + 0x28;
    cfg = bytes + 0x44;
    if (func_8AF0326C(snapshot) == 0 && *(s16 *)(sub + 0x12) == 0) {
        if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
            func_8AF00130(3);
            result = 0x17;
            D_8AF27964 = 0;
        } else if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x8000) {
            D_8AF391A0 = D_8AF39190;
            D_8AF27968 = 1;
            index = *(s16 *)(sub + 0xC) +
                    *(s32 *)(cfg + 0x10) * *(s16 *)(sub + 0x10);
            value = *(s16 *)(*(u8 **)(sub + 0x1C) + index * 2);
            if (index < *(s32 *)(cfg + 4)) {
                func_8AF00130(0xC2);
                *(s16 *)(sub + 0x16) = value;
                D_8AF2D302 = value;
                result = 0x1D;
                D_8AF2D300 = 0x1C;
                D_8AF2D304 = 1;
                func_8AF1E9D4();
            }
        }
    }
    func_8AC0686C(&D_8AF39190, *(s16 *)(sub + 0x10));
    func_8AC0619C((void *)D_8AF38DF0, *(u16 *)(D_8AF2BDC4 + 2));
    func_8AC06220((void *)D_8AF38E68, *(u16 *)(D_8AF2BDC4 + 2));
    func_8AC063AC((void *)D_8AF39118, *(u16 *)(D_8AF2BDC4 + 2));
    return result;
}
extern void func_8AC007B8(s32, s32, s32, s32);
extern void func_8AF02F18(void *);
extern void func_8004B314(s32, s32, s32, s32);
extern void func_8AC00738(void);
extern void func_8AC05F00(void *);
extern s32 func_8AC0665C(s16 *, s16);
extern s32 func_8AC0672C(void *, s16);
extern u8 D_8AF38DF0[];
extern u8 D_8AF38E68[];

// Same code as func_8AF1E1F4 in fragment44_20BDB0.c, for this file's snapshot D_8AF27960,
// list D_8AF39190 and strings D_8AF38DF0/D_8AF38E68.
//@src/fragments/44/fragment44_20BDB0.c
void func_8AF1F038(void) {
    Snapshot_8AF1E9D4 *snapshot;
    u8 *bytes; // FAKE: a u8 * copy of snapshot; diff score 24 without it.
    u8 *sub;
    s32 x;
    s32 y;

    snapshot = D_8AF27960;
    bytes = (u8 *)snapshot;
    sub = bytes + 0x28;
    x = *(s16 *)(bytes + 0x34) * *(s32 *)(bytes + 0x4C) + *(s32 *)(bytes + 0x5C) + *(s32 *)(bytes + 8) - 4;
    y = *(s16 *)(bytes + 0x36) * *(s32 *)(bytes + 0x50) + *(s32 *)(bytes + 0x60) + *(s32 *)(bytes + 0xC) - 2;
    func_8AC007B8(*(s32 *)(bytes + 8), *(s32 *)(bytes + 0xC), *(s16 *)sub, 260);
    func_8AF02F18(snapshot);
    func_8004B314(x, y, 88, 68);
    func_8AC00738();
    if (func_8AC0665C((s16 *)&D_8AF39190, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF38DF0);
    }
    if (func_8AC0672C(&D_8AF39190, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF38E68);
    }
}
#endif
