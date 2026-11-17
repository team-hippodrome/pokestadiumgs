#include "global.h"


#ifdef VERSION_US
// Not referenced by code or data (debug format strings); they open this file's .rodata.
const char D_8AF2A480[] = "ogMedalCheck() : Congratulation !!!  clear  Class (%d) !! \n";
const char D_8AF2A4BC[] = "ogMedalCheckReigai() MORAISOKONE !!! \n";
const char D_8AF2A4E4[] = "CLASS FUKKATU !!!!\n";
const char D_8AF2A4F8[] = "medal_clear_event_flg = %d\n";
const char D_8AF2A514[] = "ogSetPage_QUIZ_Recover() mode = %d\n";
const char D_8AF2A538[] = "ogSetPage_BATTLE_Recover() class = %d\n";
extern u8 func_80054794(void);
s32 func_8AF244D0(void) {
    s32 var_v1;
    s32 sp1C;

    sp1C = 0;
    var_v1 = sp1C;
    if ((func_80054794() & 7) == 7) {
        var_v1 = 1;
    }
    return var_v1;
}

extern s32 D_8AF279E4;
extern u8 D_8AF3A660;
extern u8 D_8AF3A661;
extern s32 func_8AC004E0(s16);
void func_8AF24508(s16 arg0) {
    u8 flags;
    u8 mask;

    D_8AF279E4 = 0;
    flags = func_80054794();
    mask = 1 << arg0;
    if ((flags & mask) == 0 && func_8AC004E0(arg0) != 0) {
        D_8AF279E4 = 1;
        D_8AF3A660 = flags | mask;
        D_8AF3A661 = arg0;
    }
}

extern u8 func_80054794(void);
extern s32 func_8AC004E0(s16);
extern void func_800547F4(s32);
extern void func_80051D64(s32, s32);
extern void func_80054E48(s32);
extern s32 D_8AF279E4;
void func_8AF2458C(void) {
    s16 i;
    s32 bit;
    u8 flags;

    flags = func_80054794();
    D_8AF279E4 = 0;
    i = 0;
    do {
        bit = (1 << i) & 0xFF;
        if (!(flags & bit) && (func_8AC004E0(i) != 0)) {
            func_800547F4((flags | bit) & 0xFF);
            func_80051D64(0x13, 0);
            func_80054E48(3);
        }
        i++;
    } while (i < 3);
}

typedef struct {
    u16 unused;
    u16 flags;
} Flags_8AF24A7C;

extern Flags_8AF24A7C *D_8AF3A464;
extern Flags_8AF24A7C *D_8AF3A468;
extern Flags_8AF24A7C *D_8AF3A46C;
extern Flags_8AF24A7C *D_8AF3A600;
extern Flags_8AF24A7C *D_8AF3A604;
extern Flags_8AF24A7C *D_8AF3A608;
extern Flags_8AF24A7C *D_8AF3A60C;
extern Flags_8AF24A7C *D_8AF3A610;
extern Flags_8AF24A7C *D_8AF3A614;
extern Flags_8AF24A7C *D_8AF3A618;
extern Flags_8AF24A7C *D_8AF3A61C;
extern Flags_8AF24A7C *D_8AF3A620;
extern Flags_8AF24A7C *D_8AF3A624;
extern Flags_8AF24A7C *D_8AF3A628;
extern Flags_8AF24A7C *D_8AF3A62C;
extern Flags_8AF24A7C *D_8AF3A630;
extern Flags_8AF24A7C *D_8AF3A634;
extern Flags_8AF24A7C *D_8AF3A638;
extern s32 D_8AF3A63C;
extern s32 D_8AF3A640;
extern s32 D_8AF3A644;
extern s32 D_8AF3A648;
extern s32 D_8AF3A64C;
extern s32 D_8AF3A650;
extern s32 D_8AF3A654;
extern s32 D_8AF3A658;
extern s32 D_8AF3A65C;
extern u8 func_8005453C(s32);
// Clears bit 0 of every listed entry's flags, then sets it again for each entry whose
// func_8005453C, func_80054794 bit or func_8AC004E0 check passes. Only the first six of
// the nine D_8AF3A63C-D_8AF3A65C words are reset to 0 first.
void func_8AF24628(void) {
    D_8AF3A464->flags &= ~1;
    D_8AF3A468->flags &= ~1;
    D_8AF3A46C->flags &= ~1;
    D_8AF3A600->flags &= ~1;
    D_8AF3A604->flags &= ~1;
    D_8AF3A608->flags &= ~1;
    D_8AF3A60C->flags &= ~1;
    D_8AF3A610->flags &= ~1;
    D_8AF3A614->flags &= ~1;
    D_8AF3A618->flags &= ~1;
    D_8AF3A61C->flags &= ~1;
    D_8AF3A620->flags &= ~1;
    D_8AF3A624->flags &= ~1;
    D_8AF3A628->flags &= ~1;
    D_8AF3A62C->flags &= ~1;
    D_8AF3A630->flags &= ~1;
    D_8AF3A634->flags &= ~1;
    D_8AF3A638->flags &= ~1;

    D_8AF3A63C = 0;
    D_8AF3A640 = 0;
    D_8AF3A644 = 0;
    D_8AF3A648 = 0;
    D_8AF3A64C = 0;
    D_8AF3A650 = 0;

    if (func_8005453C(0) == 1) {
        D_8AF3A61C->flags |= 1;
        D_8AF3A63C = 1;
    }

    if (func_8005453C(1) == 1) {
        D_8AF3A624->flags |= 1;
        D_8AF3A640 = 1;
    }

    if (func_8005453C(2) == 1) {
        D_8AF3A62C->flags |= 1;
        D_8AF3A644 = 1;
    }

    if (func_8005453C(3) == 1) {
        D_8AF3A618->flags |= 1;
        D_8AF3A648 = 1;
    }

    if (func_8005453C(4) == 1) {
        D_8AF3A620->flags |= 1;
        D_8AF3A64C = 1;
    }

    if (func_8005453C(5) == 1) {
        D_8AF3A628->flags |= 1;
        D_8AF3A650 = 1;
    }

    if (func_8005453C(6) == 1) {
        D_8AF3A630->flags |= 1;
        D_8AF3A654 = 1;
    }

    if (func_8005453C(7) == 1) {
        D_8AF3A634->flags |= 1;
        D_8AF3A658 = 1;
    }

    if (func_8005453C(8) == 1) {
        D_8AF3A638->flags |= 1;
        D_8AF3A65C = 1;
    }

    if ((func_80054794() & 1) != 0) {
        D_8AF3A464->flags |= 1;
    }

    if ((func_80054794() & 2) != 0) {
        D_8AF3A468->flags |= 1;
    }

    if ((func_80054794() & 4) != 0) {
        D_8AF3A46C->flags |= 1;
    }

    if (func_8AC004E0(0) != 0) {
        D_8AF3A600->flags |= 1;
        D_8AF3A604->flags |= 1;
        D_8AF3A608->flags |= 1;
    }

    if (func_8AC004E0(1) != 0) {
        D_8AF3A60C->flags |= 1;
        D_8AF3A610->flags |= 1;
        D_8AF3A614->flags |= 1;
    }
}

extern Flags_8AF24A7C *D_8AF3A3D8[12];

void func_8AF24A7C(void) {
    s32 index;

    for (index = 0; index < 12; index++) {
        D_8AF3A3D8[index]->flags &= ~1;
    }
}

extern void func_8AF24A7C(void);
extern void *D_8AF3A3C0;
extern void *D_8AF3A3DC;
extern void *D_8AF3A3E0;
extern void *D_8AF3A3E4;
extern void *D_8AF3A3E8;
extern void *D_8AF3A3EC;
extern void *D_8AF3A3F0;
extern void *D_8AF3A3F4;
extern void *D_8AF3A3F8;
extern void *D_8AF3A3FC;
extern void *D_8AF3A400;
extern void *D_8AF3A404;
extern void *D_8AF3A5F4;
extern void *D_8AF3A5F8;
extern void *D_8AF3A5FC;
extern s16 D_8AF3A3C8;
extern s16 D_8AF3A3CA;
extern s32 D_8AF3A63C;
extern s32 D_8AF3A640;
extern s32 D_8AF3A644;
extern s32 D_8AF3A648;
extern s32 D_8AF3A64C;
extern s32 D_8AF3A650;
extern s32 D_8AF3A654;
extern s32 D_8AF3A658;
extern s32 D_8AF3A65C;



void func_8AF24AE0(void) {
    // FAKE: occupies 0x1C(sp) so that v is placed at 0x18(sp).
    s32 pad;
    s32 v;

    func_8AF24A7C();
    (*(s32 *)((u8 *)(D_8AF3A5F4) + (0x2C))) = 0xBE8C28FF;
    (*(s32 *)((u8 *)(D_8AF3A5F8) + (0x2C))) = 0xBE8C28FF;
    (*(s32 *)((u8 *)(D_8AF3A5FC) + (0x2C))) = 0xBE8C28FF;
    (*(s32 *)((u8 *)(D_8AF3A600) + (0x2C))) = 0x3CB45AFF;
    (*(s32 *)((u8 *)(D_8AF3A604) + (0x2C))) = 0x3CB45AFF;
    (*(s32 *)((u8 *)(D_8AF3A608) + (0x2C))) = 0x3CB45AFF;
    (*(s32 *)((u8 *)(D_8AF3A60C) + (0x2C))) = 0x3C78B4FF;
    (*(s32 *)((u8 *)(D_8AF3A610) + (0x2C))) = 0x3C78B4FF;
    (*(s32 *)((u8 *)(D_8AF3A614) + (0x2C))) = 0x3C78B4FF;
    // Each arm selects its 16-bit index with a conditional expression placed after the
    // arm's stores: IDO 7.1 hoists the false constant above those stores and moves the
    // true constant into the delay slot of the branch to the switch exit. A plain if
    // statement emits beqz/nop/li instead, which is four bytes shorter per arm and
    // colors the result to v1 rather than v0.
    switch (D_8AF3A3C8) {
        case 0:
            switch (D_8AF3A3CA) {
                case 0:
                    D_8AF3A3D8[0]->flags |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A5F4) + (0x2C))) = 0xF0E66EFF;
                    v = D_8AF3A654 ? 61 : 49;
                    break;
                case 1:
                    (*(u16 *)((u8 *)(D_8AF3A3E4) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A600) + (0x2C))) = 0x8CFF8CFF;
                    v = D_8AF3A658 ? 62 : 50;
                    break;
                case 2:
                    (*(u16 *)((u8 *)(D_8AF3A3F0) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A60C) + (0x2C))) = 0x1EFFFFFF;
                    v = D_8AF3A65C ? 63 : 51;
                    break;
            }
            break;
        case 1:
            switch (D_8AF3A3CA) {
                case 0:
                    (*(u16 *)((u8 *)(D_8AF3A3DC) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A5F8) + (0x2C))) = 0xF0E66EFF;
                    v = D_8AF3A648 ? 64 : 52;
                    break;
                case 1:
                    (*(u16 *)((u8 *)(D_8AF3A3E8) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A604) + (0x2C))) = 0x8CFF8CFF;
                    v = D_8AF3A64C ? 65 : 53;
                    break;
                case 2:
                    (*(u16 *)((u8 *)(D_8AF3A3F4) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A610) + (0x2C))) = 0x1EFFFFFF;
                    v = D_8AF3A650 ? 66 : 54;
                    break;
            }
            break;
        case 2:
            switch (D_8AF3A3CA) {
                case 0:
                    (*(u16 *)((u8 *)(D_8AF3A3E0) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A5FC) + (0x2C))) = 0xF0E66EFF;
                    v = D_8AF3A63C ? 67 : 55;
                    break;
                case 1:
                    (*(u16 *)((u8 *)(D_8AF3A3EC) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A608) + (0x2C))) = 0x8CFF8CFF;
                    v = D_8AF3A640 ? 68 : 56;
                    break;
                case 2:
                    (*(u16 *)((u8 *)(D_8AF3A3F8) + (0x2))) |= 1;
                    (*(s32 *)((u8 *)(D_8AF3A614) + (0x2C))) = 0x1EFFFFFF;
                    v = D_8AF3A644 ? 69 : 57;
                    break;
            }
            break;
        case 3:
            switch (D_8AF3A3CA) {
                case 0:
                    (*(u16 *)((u8 *)(D_8AF3A3FC) + (0x2))) |= 1;
                    v = (D_8AF3A648 && D_8AF3A63C && D_8AF3A654) ? 83 : 80;
                    break;
                case 1:
                    (*(u16 *)((u8 *)(D_8AF3A400) + (0x2))) |= 1;
                    v = (D_8AF3A64C && D_8AF3A640 && D_8AF3A658) ? 84 : 81;
                    break;
                case 2:
                    (*(u16 *)((u8 *)(D_8AF3A404) + (0x2))) |= 1;
                    v = (D_8AF3A650 && D_8AF3A644 && D_8AF3A65C) ? 85 : 82;
                    break;
            }
            break;
    }
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (50))) = (s16)v;
}

extern void func_8004C8C0(s32);
extern void func_800476A0(void *, s32);
extern void func_800476FC(void *, s32);
extern s32 func_8004C990(s32, s32);
extern void func_80047738(s32, s32, s32, s32);
extern void func_8AF00504(s32);
extern u8 *func_8AF003A8(s32);
extern void func_8AC04744(void *, u8 *, s32, s32);
extern u8 *func_8AC06D8C(u8 *, s32);
extern void func_8AC05E40(u8 *, s32, void *);
extern void func_8AC06400(void *, void *);
extern void func_8AC02C80(u8 *, s32, s32, void *);
extern void func_8004E308(void *, void *, s32);
extern void func_8AF013D8(void);
extern void func_8AC03AFC(void);
extern void func_8AC03C28(void);
extern void func_8AC00270(void);
extern s32 Fragment43_TryGrantCompletionReward(s16);
extern void func_8AF2458C(void);
extern u8 D_8AF3A3A0[];
extern u8 D_8AF3A6E8[];
extern u8 D_8AF3A470[];
extern u8 D_8AF3A4E8[];
extern u8 D_8AF3A560[];
extern u8 D_8AF3A408[];
extern u8 D_8AF3A438[];
extern void *D_8AF3A5D8;
extern void *D_8AF3A5DC;
extern void *D_8AF3A5E0;
extern void *D_8AF3A5E4;
extern void *D_8AF3A5E8;
extern void *D_8AF3A5EC;
extern void *D_8AF3A5F0;
extern void *D_8AF3A6E0;
extern void *D_8AF3A664;
extern s32 D_8AF3A668;
extern s16 D_8AF279E0;
extern s16 D_8AF3A3CC;
extern s16 D_8AF3A3CE;
extern s16 D_8AF3A3D0;
extern s16 D_8AF3A662;
extern s16 D_8AF3A6E4;
extern s32 D_8AF279E4;
void func_8AF25028(void) {
    s32 i;
    s32 v;
    u8 *n44;
    void *c44;
    void *n3C;
    void *c3C;
    void *n34;
    void *c34;
    u8 *root;

    func_8004C8C0(0xBE);
    func_8004C8C0(0xBB);
    func_800476A0(D_8AF3A3A0, 2);
    func_800476FC(D_8AF3A3A0, 2);
    v = func_8004C990(0xBE, 0);
    func_80047738(0, v, 0, 0);
    v = func_8004C990(0xBB, 1);
    func_80047738(1, v, 0, 0);
    func_8AF00504(0xCE);
    func_8AF00504(0x9B);
    root = func_8AF003A8(0xCE);
    func_8AC04744(D_8AF3A6E8, root, 0x77696E5F, 0x6D73675F);
    D_8AF3A3D8[0] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F31);
    D_8AF3A3D8[1] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F32);
    D_8AF3A3D8[2] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F33);
    D_8AF3A3D8[3] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F34);
    D_8AF3A3D8[4] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F35);
    D_8AF3A3D8[5] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F36);
    D_8AF3A3D8[6] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F37);
    D_8AF3A3D8[7] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F38);
    D_8AF3A3D8[8] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74655F39);
    D_8AF3A3D8[9] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74653130);
    D_8AF3A3D8[10] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74653131);
    D_8AF3A3D8[11] = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x74653132);
    D_8AF3A464 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x636F7072);
    D_8AF3A468 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x73696C76);
    D_8AF3A46C = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x676F6C64);
    func_8AC05E40(root, 0x636F7072, D_8AF3A470);
    func_8AC06400(D_8AF3A470, D_8AF3A464);
    func_8AC05E40(root, 0x73696C76, D_8AF3A4E8);
    func_8AC06400(D_8AF3A4E8, D_8AF3A468);
    func_8AC05E40(root, 0x676F6C64, D_8AF3A560);
    func_8AC06400(D_8AF3A560, D_8AF3A46C);
    for (i = 0; i < 12; i++) {
        func_8004E308(D_8AF3A3D8[i], func_8AF013D8, 0);
    }
    func_8AC02C80(root, 0x725F6C5F, 0x725F725F, D_8AF3A408);
    func_8AC02C80(root, 0x73616E6C, 0x73616E72, D_8AF3A438);
    D_8AF3A5D8 = func_8AC06D8C(root, 0x686C6330);
    D_8AF3A5DC = func_8AC06D8C(root, 0x686C6331);
    D_8AF3A5E0 = func_8AC06D8C(root, 0x686C6332);
    func_8004E308(D_8AF3A5D8, func_8AC03AFC, 0);
    func_8004E308(D_8AF3A5DC, func_8AC03AFC, 0);
    func_8004E308(D_8AF3A5E0, func_8AC03AFC, 0);
    D_8AF3A5E4 = func_8AC06D8C(root, 0x766C6330);
    D_8AF3A5E8 = func_8AC06D8C(root, 0x766C6331);
    D_8AF3A5EC = func_8AC06D8C(root, 0x766C6332);
    D_8AF3A5F0 = func_8AC06D8C(root, 0x766C6333);
    func_8004E308(D_8AF3A5E4, func_8AC03AFC, 0);
    func_8004E308(D_8AF3A5E8, func_8AC03AFC, 0);
    func_8004E308(D_8AF3A5EC, func_8AC03AFC, 0);
    func_8004E308(D_8AF3A5F0, func_8AC03AFC, 0);
    n44 = func_8AC06D8C(root, 0x70695F5F);
    c44 = func_8AC06D8C(root, 0x70695F63);
    func_8004E308(n44, func_8AC03C28, (s32)c44);
    n3C = func_8AC06D8C(root, 0x70696B61);
    c3C = func_8AC06D8C(root, 0x706B5F63);
    func_8004E308(n3C, func_8AC03C28, (s32)c3C);
    n34 = func_8AC06D8C(root, 0x7261695F);
    c34 = func_8AC06D8C(root, 0x72695F63);
    func_8004E308(n34, func_8AC03C28, (s32)c34);
    D_8AF3A5F4 = func_8AC06D8C(root, 0x6F686131);
    D_8AF3A5F8 = func_8AC06D8C(root, 0x71697A31);
    D_8AF3A5FC = func_8AC06D8C(root, 0x62746C31);
    D_8AF3A600 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x6F686132);
    D_8AF3A604 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x71697A32);
    D_8AF3A608 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x62746C32);
    D_8AF3A60C = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x6F686133);
    D_8AF3A610 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x71697A33);
    D_8AF3A614 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x62746C33);
    D_8AF3A618 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x73747231);
    D_8AF3A61C = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x73747232);
    D_8AF3A620 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x73747233);
    D_8AF3A624 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x73747234);
    D_8AF3A628 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x73747235);
    D_8AF3A62C = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x73747236);
    D_8AF3A630 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x61647331);
    D_8AF3A634 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x61647332);
    D_8AF3A638 = (Flags_8AF24A7C *)func_8AC06D8C(root, 0x61647333);
    D_8AF3A3C0 = func_8AC06D8C(root, 0x6D73675F);
    func_8004E308(func_8AC06D8C(root, 0x6579655F), func_8AC00270, 0);
    root = func_8AF003A8(0x9B);
    D_8AF3A664 = func_8AC06D8C(root, 0x6162746E);
    func_8AC05E40(root, 0x6162746E, &D_8AF3A668);
    func_8AC06400(&D_8AF3A668, D_8AF3A664);
    ((Flags_8AF24A7C *)D_8AF3A664)->flags &= ~1;
    D_8AF3A6E0 = func_8AC06D8C(root, 0x6D65646C);
    i = 0;
    do {
        Fragment43_TryGrantCompletionReward(i);
        i++;
    } while (i != 3);
    D_8AF3A3C8 = 0;
    D_8AF3A3CA = 0;
    if (D_8AF279E0 == 1) {
        D_8AF3A3C8 = D_8AF3A3CC;
        D_8AF3A3CA = D_8AF3A3CE;
    } else {
        func_8AF2458C();
    }
    func_8AF24628();
    func_8AF24AE0();
    D_8AF3A3D0 = 0;
    D_8AF3A662 = 0;
    if (D_8AF279E4 != 0) {
        D_8AF3A662 = 1;
        func_8AF24A7C();
        D_8AF279E4 = 0;
        D_8AF3A6E4 = 0;
    }
}


extern void func_8AF24508(s16);
extern s16 D_8AF279E0;
extern s16 D_8AF3A3CC;
extern s16 D_8AF3A3CE;
void func_8AF25870(s16 arg0) {
    D_8AF279E0 = 1;
    D_8AF3A3CE = arg0;
    D_8AF3A3CC = 0;
    func_8AF24508(arg0);
}

void func_8AF258B4(s16 arg0, s16 arg1) {
    D_8AF279E0 = 1;
    D_8AF3A3CE = arg1;
    D_8AF3A3CC = arg0;
    func_8AF24508(arg1);
}

extern u8 *D_8AF2BDD8;
extern s16 D_8AF3A3CA;
extern s16 D_8AF3A3C8;

void func_8AF25908(void) {
    u8 *entry = D_8AF2BDD8;

    D_8AF3A3CA = *entry;
    D_8AF3A3C8 = 2;
    D_8AF279E0 = 1;
    D_8AF3A3CE = D_8AF3A3CA;
    D_8AF3A3CC = D_8AF3A3C8;
    func_8AF24508(*entry);
}

extern s16 D_8AF3A3D0;
extern s16 D_8AF3A662;
extern s32 D_8AF3A668;
extern u16 D_8AF2BDC6;
extern void func_8AC007FC(void);
s16 func_8AF25A84(s16 arg0);
extern void func_8AF25DF0(void);
extern void func_8AF25EA0(void);
extern void func_8AF2610C(void);
extern void func_8AF26154(void);
extern void func_8AF261C0(void);
extern void func_8AF26234(void);
extern void func_8AF262AC(void);
extern void func_8AF26324(void);
extern void func_8AC063AC(s32 *, u16);
s16 func_8AF25974(void) {
    s16 var_v0;

    var_v0 = 36;
    if (D_8AF3A3D0 < 16) {
        D_8AF3A3D0 += 1;
    } else {
        func_8AC007FC();
    }

    switch (D_8AF3A662) {
        case 0:
            var_v0 = func_8AF25A84(36);
            break;
        case 1:
            func_8AF25DF0();
            break;
        case 2:
            func_8AF25EA0();
            break;
        case 3:
            func_8AF2610C();
            break;
        case 4:
            func_8AF26154();
            break;
        case 5:
            func_8AF261C0();
            break;
        case 6:
            func_8AF26234();
            break;
        case 7:
            func_8AF262AC();
            break;
        case 8:
            func_8AF26324();
            break;
    }
    func_8AC063AC(&D_8AF3A668, D_8AF2BDC6);
    return var_v0;
}

extern void *D_8AF263C0;
extern u8 *D_8AF2BDD8;
extern s16 D_8AF3A3C8;
extern s16 D_8AF3A3CA;
extern s16 D_8AF3A3CC;
extern s16 D_8AF3A3CE;
extern s16 D_8AF279E0;
extern void func_8AF00130(s32);
extern s32 func_8AC004E0(s16);
extern void func_8AF07A90(void);
extern void func_8AF24AE0(void);
extern s32 D_8AF2BA68;
extern s32 D_8AF2C65C;

typedef struct {
    /* 0x0 */ u16 a : 16;
    /* 0x2 */ u8 b : 8;
    /* 0x3 */ u8 c : 8;
} unk_func_8AF25A84;



s16 func_8AF25A84(s16 arg0) {
    s16 old_state;
    s16 old_col;
    s32 pressed;
    unk_func_8AF25A84 *e;

    old_state = D_8AF3A3C8;
    old_col = D_8AF3A3CA;
    switch (D_8AF3A3C8) {
        case 0:
            if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x100) {
                D_8AF3A3C8 = 1;
            }
            break;
        case 1:
            if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x200) {
                D_8AF3A3C8 = 0;
            }
            if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x100) {
                D_8AF3A3C8 = 2;
            }
            break;
        case 2:
            if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x200) {
                D_8AF3A3C8 = 1;
            }
            if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x100) {
                D_8AF3A3C8 = 3;
            }
            break;
        case 3:
            if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x200) {
                D_8AF3A3C8 = 2;
            }
            break;
    }
    if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x800) {
        if (D_8AF3A3CA > 0) {
            D_8AF3A3CA--;
        }
    } else if (*(u16 *)((u8 *)D_8AF263C0 + 0xC) & 0x400) {
        if (D_8AF3A3CA < 2 && func_8AC004E0((s32)D_8AF3A3CA) != 0) {
            D_8AF3A3CA++;
        }
    }
    if (old_state != D_8AF3A3C8 || old_col != D_8AF3A3CA) {
        func_8AF00130(1);
    }
    pressed = *(u16 *)((u8 *)D_8AF263C0 + 8);
    if (pressed & 0x8000) {
        D_8AF3A3CC = D_8AF3A3C8;
        D_8AF3A3CE = D_8AF3A3CA;
        D_8AF279E0 = 1;
        switch (D_8AF3A3C8) {
            case 0:
                func_8AF07A90();
                func_8AF00130(0xBF);
                switch (D_8AF3A3CA) {
                    case 0:
                        arg0 = 3;
                        break;
                    case 1:
                        arg0 = 4;
                        break;
                    case 2:
                        arg0 = 5;
                        break;
                }
                break;
            case 2:
                func_8AF00130(0xBF);
                *D_8AF2BDD8 = D_8AF3A3CA;
                arg0 = 0x1F;
                break;
            case 1:
                func_8AF00130(0xBF);
                e = *(unk_func_8AF25A84 **)(D_8AF2BDD8 + 8);
                switch (D_8AF3A3CA) {
                    case 0:
                        e->a = 1;
                        e->b = 1;
                        e->c = 0;
                        break;
                    case 1:
                        e->a = 2;
                        e->b = 2;
                        e->c = 1;
                        break;
                    case 2:
                        e->a = 3;
                        e->b = 3;
                        e->c = 2;
                        break;
                    default:
                        e->a = 0;
                        break;
                }
                D_8AF2BA68 = 3;
                break;
        }
    } else if (pressed & 0x4000) {
        func_8AF00130(3);
        D_8AF2C65C = 0;
        arg0 = 1;
    }
    func_8AF24AE0();
    return arg0;
}

extern void *D_8AF3A3C0;
extern void *D_8AF3A664;
extern void *D_8AF263C0;
extern s16 D_8AF3A662;
extern s16 D_8AF3A6E4;
extern s16 D_8AF3A6E6;
extern void func_8AF00130(s32);

void func_8AF25DF0(void) {
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x30))) = 0x36;
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x32))) = 0x4A;
    if (D_8AF3A6E4 < 0x1E) {
        D_8AF3A6E4 += 1;
        return;
    }
    (*(u16 *)((u8 *)(D_8AF3A664) + (2))) =
        (u16)((*(u16 *)((u8 *)(D_8AF3A664) + (2))) | 1);
    if ((*(u16 *)((u8 *)(D_8AF263C0) + (8))) & 0x8000) {
        D_8AF3A662 = 2;
        func_8AF00130(0xC2);
        D_8AF3A6E6 = 0;
        (*(u16 *)((u8 *)(D_8AF3A664) + (2))) =
            (u16)((*(u16 *)((u8 *)(D_8AF3A664) + (2))) & 0xFFFE);
    }
}

/* mkdraft:func_8AF25EA0 begin */
extern u8 D_8AF3A660;
extern void func_8AF24628(void);
extern s32 func_8AF25F40(s32);

void func_8AF25EA0(void) {
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x30))) = 0x36;
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x32))) = 0x4B;
    if (D_8AF3A6E6 >= 0x15) {
        func_800547F4(D_8AF3A660);
        func_80051D64(0x13, 0);
        func_80054E48(3);
        func_8AF24628();
        D_8AF3A662 = 3;
        func_8AF25F40(0);
        func_8AF00130(0xC2);
    }
    D_8AF3A6E6 += 1;
}
/* mkdraft:func_8AF25EA0 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/44/fragment44_212740/func_8AF25F40.s")

s32 func_8AF25F40(s32);
extern s16 D_8AF3A662;
extern void *D_8AF3A664;

void func_8AF2610C(void) {
    (*(u16 *)((u8 *)(D_8AF3A664) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3A664) + (2))) & 0xFFFE);
    if (func_8AF25F40(1) == -1) {
        D_8AF3A662 = 4;
    }
}

extern void func_80021ED8(s32);
s32 func_80025D44();
extern u8 D_8AF3A661;

void func_8AF26154(void) {
    if (func_80025D44() == 0) {
        (*(u16 *)((u8 *)(D_8AF3A664) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3A664) + (2))) | 1);
        func_80021ED8(7);
        D_8AF3A662 = 5;
        if (D_8AF3A661 == 2) {
            D_8AF3A662 = 6;
        }
    }
}

extern void func_8AF00130(s32);
extern void *D_8AF263C0;
extern void *D_8AF3A3C0;
void func_8AF261C0(void) {
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x30))) = 0x36;
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x32))) = 0x4C;
    if ((*(u16 *)((u8 *)(D_8AF263C0) + (8))) & 0x8000) {
        (*(u16 *)((u8 *)(D_8AF3A664) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3A664) + (2))) & 0xFFFE);
        D_8AF3A662 = 0;
        func_8AF00130(0xC2);
    }
}

void func_8AF26234(void) {
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x30))) = 0x36;
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x32))) = 0x4D;
    (*(u16 *)((u8 *)(D_8AF3A664) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3A664) + (2))) | 1);
    if ((*(u16 *)((u8 *)(D_8AF263C0) + (8))) & 0x8000) {
        D_8AF3A662 = 7;
        func_8AF00130(0xC2);
    }
}

void func_8AF262AC(void) {
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x30))) = 0x36;
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x32))) = 0x4E;
    (*(u16 *)((u8 *)(D_8AF3A664) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3A664) + (2))) | 1);
    if ((*(u16 *)((u8 *)(D_8AF263C0) + (8))) & 0x8000) {
        D_8AF3A662 = 8;
        func_8AF00130(0xC2);
    }
}

void func_8AF26324(void) {
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x30))) = 0x36;
    (*(s16 *)((u8 *)(D_8AF3A3C0) + (0x32))) = 0x4F;
    (*(u16 *)((u8 *)(D_8AF3A664) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3A664) + (2))) | 1);
    if ((*(u16 *)((u8 *)(D_8AF263C0) + (8))) & 0x8000) {
        (*(u16 *)((u8 *)(D_8AF3A664) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3A664) + (2))) & 0xFFFE);
        D_8AF3A662 = 0;
        func_8AF00130(0xC2);
    }
}

void func_8AF263AC(void) {
}
#endif
