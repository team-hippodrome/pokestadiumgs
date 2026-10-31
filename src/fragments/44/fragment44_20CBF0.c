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

extern u8 D_8AF39190[]; extern s32 D_8AF27968; void func_8AF1EAC8(void) { _bzero(D_8AF39190, 0xE); D_8AF27968 = 0; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20CBF0/func_8AF1EAF4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_20CBF0/func_8AF1EEA8.s")

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
    if (func_8AC0665C((s16 *)D_8AF39190, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF38DF0);
    }
    if (func_8AC0672C(D_8AF39190, *(s16 *)(sub + 0x10)) != 0) {
        func_8AC05F00(D_8AF38E68);
    }
}
#endif
