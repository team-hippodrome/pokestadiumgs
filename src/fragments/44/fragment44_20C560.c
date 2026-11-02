#include "global.h"


#ifdef VERSION_US
s32 func_8AF1E2F0(u8 arg0, u8 arg1) {
    s32 nibble = arg1 & 0xF;
    if ((nibble == (arg0 & 0xF)) || (nibble == ((arg0 & 0xF0) >> 4))) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 func_80063804(u8);
extern s32 func_80064474(u8, u16);
extern u8 func_8AF01654(u8);
// Writes to arg0, terminated by -1, each species from func_80063804(1) through
// func_80063804(251) whose nibble-packed group byte (func_8AF01654) has arg1
// in either nibble (func_8AF1E2F0). Other than for groups 13 and 15, the
// species must also pass func_80064474(species, 128), which returns 0 only for
// genderless species. Group 16, also used when arg1 is 0, selects species whose
// group byte is 0. The two nibbles look like Gen 2's two egg groups; that
// reading is not confirmed against decoded data.
//@src/fragments/44/fragment44_1EE290.c
void func_8AF1E32C(s16 *arg0, u8 arg1) {
    s32 i;
    u8 species;
    u8 groups;

    if (arg1 == 0) {
        arg1 = 16;
    }
    for (i = 0; i < 251; i++) {
        species = func_80063804(i + 1);
        groups = func_8AF01654(species);
        switch (arg1) {
            case 13:
            case 15:
                if (func_8AF1E2F0(groups, arg1) != 0) {
                    *arg0++ = species;
                }
                break;
            case 16:
                if (groups == 0) {
                    *arg0++ = species;
                }
                break;
            default:
                if (func_80064474(species, 128) != 0 && func_8AF1E2F0(groups, arg1) != 0) {
                    *arg0++ = species;
                }
                break;
        }
    }
    *arg0 = -1;
}
#endif

#ifdef VERSION_US
typedef struct Snapshot_8AF1E45C {
    u32 words[0x52C / 4];
} Snapshot_8AF1E45C;
extern Snapshot_8AF1E45C D_8AF38208;
extern Snapshot_8AF1E45C *D_8AF27940;
extern s16 D_8AF38206;
extern s16 D_8AF3779C;
void func_8AF1E45C(void) {
    *D_8AF27940 = D_8AF38208;
    D_8AF3779C = D_8AF38206;
}
#endif

void func_8AF1E4B0(void) {
}

#ifdef VERSION_US
typedef struct Payload_8AF1E4B8 {
    u32 words[0x504 / 4];
} Payload_8AF1E4B8;
void func_8AF1E4B8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                    u8 arg5, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 arg10,
                    s32 arg11, s32 arg12, const Payload_8AF1E4B8 *arg13) {
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
    *(Payload_8AF1E4B8 *)(arg0 + 0x28) = *arg13;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8AF1E54C begin */
extern void *func_8AF00504(s16);
extern s32 func_8AF003A8(s16);
extern void func_8AC06E98(void *);
extern s32 func_8AC06D8C(s32, s32);
extern void func_8004E308(s32, s32 *, s32 *);
extern s32 func_8AC03C28(s32, void *);
extern void func_8AC02C80(s32, s32, s32, void *);
extern void func_8AC05ED4(s32, s32, s32);
extern void _bzero(void *, s32);
extern s16 D_8AF27954;
extern u8 D_8AF27944[];
extern s16 D_8AF3779C;
extern s32 D_8AF38738;
extern s32 D_8AF387B0;
extern s32 D_8AF38828;
extern u8 D_8AF37FD8[];
extern u8 D_8AF38008[];
extern void func_8AF02DA4(void *, void *);
extern s32 func_8004C874(s32, s32);
extern s32 func_8004C54C(s32, s32);
// Returns 1 on success. The return type also decides the register of the last
// reload: declaring it void selects v0 instead of v1. //@{src/4CC20.c}
extern s32 func_8004C594(s32, s32);
extern void func_8AC0651C(void *, s16, s16, s16, s16);



void func_8AF1E54C(void) {
    s32 pad0;  // FAKE: two spare slots raise the frame from 0x580 to 0x588;
    s32 pad1;  // FAKE: diff score 10 without both.
    u8 *state;  // FAKE: unused; diff score 118 without it.
    s32 height;
    Payload_8AF1E4B8 payload;
    s32 visible;
    s32 idx;
    s32 w1;
    s32 slif;
    s32 title;
    s32 page;
    u8 *sprite;  // FAKE: unused; diff score 8 without it.
    s32 pic0;
    s32 pic1;

    func_8AF00504(0x92);
    page = func_8AF003A8(0x92);
    func_8AC06E98((void *)page);
    pic0 = func_8AC06D8C(page, 0x70696330);
    pic1 = func_8AC06D8C(page, 0x70696363);
    *(u16 *)((u8 *)pic0 + 2) |= 1;
    func_8004E308(pic0, (s32 *)func_8AC03C28, (s32 *)pic1);
    w1 = func_8AC06D8C(page, 0x77695F31);
    title = func_8AC06D8C(page, 0x7469746C);
    *(s16 *)((u8 *)title + 0x30) = 0x3B;
    slif = func_8AC06D8C(page, 0x736C6966);
    *(s16 *)((u8 *)slif + 0x30) = 0x3B;
    *(s16 *)((u8 *)slif + 0x32) = 0x1C;
    *(u16 *)((u8 *)slif + 2) &= ~2;
    func_8AC02C80(page, 0x725F6C5F, 0x725F725F, D_8AF37FD8);
    func_8AC05ED4(page, 0x79613175, (s32)&D_8AF38738);
    func_8AC05ED4(page, 0x79613173, (s32)&D_8AF387B0);
    visible = *(s16 *)((u8 *)w1 + 8);
    height = *(s16 *)((u8 *)w1 + 0xA);
    _bzero(&payload, 0x504);
    *(s16 *)((u8 *)&payload + 0x0) = *(s16 *)((u8 *)w1 + 0xC);
    *(s16 *)((u8 *)&payload + 0x2) = *(s16 *)((u8 *)w1 + 0xE);
    *(s32 *)((u8 *)&payload + 0x4) = 0;
    *(s32 *)((u8 *)&payload + 0x8) = 0;
    *(s16 *)((u8 *)&payload + 0xC) = 0;
    *(s16 *)((u8 *)&payload + 0xE) = 0;
    *(s16 *)((u8 *)&payload + 0x12) = 0;
    *(s16 *)((u8 *)&payload + 0x14) = 0xD;
    *(s32 *)((u8 *)&payload + 0x24) = 0x55;
    *(s32 *)((u8 *)&payload + 0x28) = 0x41;
    *(s32 *)((u8 *)&payload + 0x2C) = 6;
    *(s16 *)((u8 *)&payload + 0x3C) = 3;
    *(s16 *)((u8 *)&payload + 0x3E) = 1;
    *(s32 *)((u8 *)&payload + 0x34) = 5;
    *(s32 *)((u8 *)&payload + 0x38) = 0;
    *(s16 *)((u8 *)&payload + 0x4A) = 0x41;
    func_8AF1E4B8((u8 *)D_8AF27940, 0xA, visible, height, 8, 0, 0, 0, 0x64, 0x64, 0x64, 4, 0xB, &payload);
    if (D_8AF27954 == 1) {
        func_8AF1E45C();
    }
    idx = D_8AF27944[D_8AF3779C];
    func_8004C54C(0x45, func_8004C874(0x3B, idx + 0xEB));
    *(s16 *)((u8 *)title + 0x32) = 0xFD;
    func_8AF1E32C((s16 *)D_8AF38008, idx);
    func_8AF02DA4(D_8AF27940, D_8AF38008);
    page = (s32)D_8AF27940;
    *(s16 *)((u8 *)page + 0x40) = 1;
    page += 0x28;  // same dword as +0x48 above, now at +0x20
    func_8AC0651C(&D_8AF38828, (s16)((*(s32 *)((u8 *)page + 0x20) - 1) / 6), 0x3C, 3, 0xA);
    func_8004C594(2, *(s32 *)((u8 *)page + 0x20));
    *(u16 *)((u8 *)slif + 2) |= 2;
}
/* mkdraft:func_8AF1E54C end */
#endif

#ifdef VERSION_US
extern void *D_8AF263C0;
extern s16 D_8AF27954;
extern u16 D_8AF2BDC6;
extern s32 D_8AF38828;
extern s32 D_8AF38738;
extern s32 D_8AF387B0;
extern s32 func_8AF0326C(void *);
extern void func_8AF00130(s32);
extern void func_8AC0686C(void *, s16);
extern void func_8AC0619C(s32 *, u16);
extern void func_8AC06220(s32 *, u16);
s16 func_8AF1E840(void) {
    s16 result = 0x19;
    u8 *state = (u8 *)D_8AF27940;

    if (func_8AF0326C(state) == 0) {
        if (*(u16 *)((u8 *)D_8AF263C0 + 8) & 0x4000) {
            func_8AF00130(3);
            result = 0x17;
            D_8AF27954 = 0;
        }
    }
    func_8AC0686C(&D_8AF38828, *(s16 *)(state + 0x38));
    func_8AC0619C(&D_8AF38738, D_8AF2BDC6);
    func_8AC06220(&D_8AF387B0, D_8AF2BDC6);
    return result;
}
#endif

#ifdef VERSION_US
void func_8AF1E8E4(void) {
    u8 *state;
    u8 *sprite;
    s32 pad[2]; // FAKE: unused stack padding; diff score 10 without it.
    s32 one = 1; // FAKE: always-true condition variable; diff score 23 without it and its if.

    state = (u8 *)D_8AF27940;
    sprite = state + 0x28;
    func_8AC007B8(*(s32 *)(state + 8), *(s32 *)(state + 0xC), *(s16 *)(state + 0x28), 260);
    if (one) {
        func_8AF02F18(state);
        func_8AC00738();
    }
    if (func_8AC06800(&D_8AF38828, *(s16 *)(sprite + 0x10)) != 0) {
        func_8AC05F00(&D_8AF38738);
    }
    if (func_8AC06834(&D_8AF38828, *(s16 *)(sprite + 0x10)) != 0) {
        func_8AC05F00(&D_8AF387B0);
    }
}
#endif
