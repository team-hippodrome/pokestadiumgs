#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_8AF1C3A0 begin */
extern void func_800504BC(s16 *);
extern void func_8AC015B0(s16, s16, s32, s32, s16);
extern u8 D_8AF274A0[];
extern s16 D_8AF27920;
extern s16 D_8AF37798;

s32 func_8AF1C3A0(s32 mode, void *record) {
    s16 x;
    s16 y;
    void *preserved;
    s16 values[2];

    preserved = record;
    switch (mode) {
    case 0:
        *(u16 *)((u8 *)preserved + 2) &= 0xFFFD;
        break;
    case 1:
        func_800504BC(values);
        x = *(s16 *)((u8 *)preserved + 8) + values[0];
        y = *(s16 *)((u8 *)preserved + 0xA) + values[1];
        func_8AC015B0(x, y, (s32)(D_8AF274A0), D_8AF27920, D_8AF37798);
        break;
    }
    return 0;
}
/* mkdraft:func_8AF1C3A0 end */

/* mkdraft:func_8AF1C43C begin */
extern void func_800504BC(s16 *);
extern void func_8AC015B0(s16, s16, s32, s32, s16);
extern u8 D_8AF275E0[];
extern s16 D_8AF27928;
extern s16 D_8AF3779C;

s32 func_8AF1C43C(s32 mode, void *record) {
    s16 x;
    s16 y;
    void *preserved;
    s16 values[2];

    preserved = record;
    switch (mode) {
    case 0:
        *(u16 *)((u8 *)preserved + 2) &= 0xFFFD;
        break;
    case 1:
        func_800504BC(values);
        x = *(s16 *)((u8 *)preserved + 8) + values[0];
        y = *(s16 *)((u8 *)preserved + 0xA) + values[1];
        func_8AC015B0(x, y, (s32)(D_8AF275E0), D_8AF27928, D_8AF3779C);
        break;
    }
    return 0;
}
/* mkdraft:func_8AF1C43C end */

/* mkdraft:func_8AF1C4D8 begin */
extern void func_800504BC(s16 *);
extern void func_8AC015B0(s16, s16, s32, s32, s16);
extern u8 D_8AF277E0[];
extern s16 D_8AF27924;
extern s16 D_8AF3779A;

s32 func_8AF1C4D8(s32 mode, void *record) {
    s16 x;
    s16 y;
    void *preserved;
    s16 values[2];

    preserved = record;
    switch (mode) {
    case 0:
        *(u16 *)((u8 *)preserved + 2) &= 0xFFFD;
        break;
    case 1:
        func_800504BC(values);
        x = *(s16 *)((u8 *)preserved + 8) + values[0];
        y = *(s16 *)((u8 *)preserved + 0xA) + values[1];
        func_8AC015B0(x, y, (s32)(D_8AF277E0), D_8AF27924, D_8AF3779A);
        break;
    }
    return 0;
}
/* mkdraft:func_8AF1C4D8 end */

/* mkdraft:func_8AF1C574 begin */
extern void *D_8AF37778;
extern void *D_8AF37784;
extern void *D_8AF3777C;
extern void *D_8AF37788;
extern void *D_8AF37780;
extern void *D_8AF3778C;

void func_8AF1C574(void) {
    *(u16 *)((u8 *)D_8AF37778 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AF37784 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AF3777C + 2) &= ~2;
    *(u16 *)((u8 *)D_8AF37788 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AF37780 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AF3778C + 2) &= ~2;
}
/* mkdraft:func_8AF1C574 end */

extern void *D_8AF37778;
extern void *D_8AF3777C;
extern void *D_8AF37780;
extern void *D_8AF37784;
extern void *D_8AF37788;
extern void *D_8AF3778C;
void func_8AF1C5F0(void) {
    (*(u16 *)((u8 *)(D_8AF37778) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF37778) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF37784) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF37784) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF3777C) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3777C) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF37788) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF37788) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF37780) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF37780) + (2))) | 2);
    (*(u16 *)((u8 *)(D_8AF3778C) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AF3778C) + (2))) | 2);
}

void func_8AF1C66C(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)(arg0 + 0x28) = arg1;
    *(s32 *)(arg0 + 0x2C) = arg2;
}

extern s16 D_8AF37754;
extern u8 *D_8AF37758;
extern u8 *D_8AF3775C;
extern u8 *D_8AF37760;
extern s16 D_8AF3779E;
void func_8AF1C678(void) {
    s16 pos[2]; // FAKE: two scalars in an array for their stack slots; as separate locals the function does not match (fd 22)

    *(u16 *)(D_8AF37758 + 2) &= ~2;
    *(u16 *)(D_8AF3775C + 2) &= ~2;
    *(u16 *)(D_8AF37760 + 2) &= ~2;
    func_8AF1C66C(D_8AF37778, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF1C66C(D_8AF3777C, 0xC3A05AFF, 0xE1C38CFF);
    func_8AF1C66C(D_8AF37780, 0xC3A05AFF, 0xE1C38CFF);
    if (D_8AF3779E == 0) {
        switch (D_8AF37754) {
            case 0:
                pos[1] = *(s16 *)(D_8AF37758 + 8);
                pos[0] = *(s16 *)(D_8AF37758 + 0xA);
                func_8AF1C66C(D_8AF37778, 0xFFFF00FF, 0xFFFF00FF);
                break;
            case 2:
                pos[1] = *(s16 *)(D_8AF3775C + 8);
                pos[0] = *(s16 *)(D_8AF3775C + 0xA);
                func_8AF1C66C(D_8AF3777C, 0xFFFF00FF, 0xFFFF00FF);
                break;
            case 1:
                pos[1] = *(s16 *)(D_8AF37760 + 8);
                pos[0] = *(s16 *)(D_8AF37760 + 0xA);
                func_8AF1C66C(D_8AF37780, 0xFFFF00FF, 0xFFFF00FF);
                break;
        }
        func_8AF01020(pos[1], pos[0]);
    }
}

extern s16 D_8AF37754;
extern s16 D_8AF37798;
extern s16 D_8AF3779A;
extern s16 D_8AF3779C;
extern s16 D_8AF3779E;

void func_8AF1C804(void) {
    D_8AF3779E = 0;
    D_8AF37798 = 0;
    D_8AF3779C = 0;
    D_8AF3779A = 0;
    D_8AF37754 = 0;
}

/* mkdraft:func_8AF1C830 begin */
// func_8AF1C830 (src/fragments/44/fragment44_20A610.c) - matched C body.
// US target: asm/us/nonmatchings/fragments/44/fragment44_20A610/func_8AF1C830.s

extern void func_8004E308(s32, s32 *, s32 *);
extern s16 func_8AC01354(u8 *, s32);
extern void func_8AC02C80(s32, s32, s32, void *);
extern void func_8AC05E40(s32, s32, s32);
extern s32 func_8AC06D8C(s32, s32);
extern void func_8AC06E98(void *);
extern s32 func_8AF003A8(s16);
extern void func_8AF00504(s32);
extern void func_8AF1C574(void);
extern void func_8AF1C678(void);

extern f32 D_8AF29E58;
extern f32 D_8AF29E5C;
extern u8 D_8AF375A0[];
extern u8 D_8AF37618[];
extern u8 D_8AF37690[];
extern void *D_8AF37708;
extern void *D_8AF3770C;
extern void *D_8AF37710;
extern void *D_8AF37718;
extern void *D_8AF3771C;
extern void *D_8AF37720;
extern u8 D_8AF37728[];
extern s32 D_8AF37764;
extern s32 D_8AF37768;
extern s32 D_8AF3776C;
extern s32 D_8AF37770;
extern s32 D_8AF37774;
extern u8 *D_8AF37790;
extern u8 *D_8AF377BC;
extern u8 *D_8AF377C0;
extern u8 *D_8AF377C4;
extern u8 *D_8AF377C8;
extern u8 *D_8AF377CC;
extern u8 *D_8AF377D0;



void func_8AF1C830(void) {
    s32 page;

    func_8AF00504(0x8C);
    func_8AF00504(0x35);
    page = func_8AF003A8(0x8C);
    func_8AC06E98((void *)page);
    func_8AC05E40(page, 0x6E616D65, (s32)D_8AF375A0);
    func_8AC05E40(page, 0x67727570, (s32)D_8AF37618);
    func_8AC05E40(page, 0x756D6172, (s32)D_8AF37690);
    D_8AF37708 = D_8AF375A0;
    D_8AF3770C = D_8AF37618;
    D_8AF37710 = D_8AF37690;
    D_8AF3776C = func_8AC06D8C(page, 0x6E616D65);
    D_8AF37770 = func_8AC06D8C(page, 0x67727570);
    D_8AF37774 = func_8AC06D8C(page, 0x756D6172);
    D_8AF37758 = func_8AC06D8C(page, 0x74655F31);
    D_8AF3775C = func_8AC06D8C(page, 0x74655F33);
    D_8AF37760 = func_8AC06D8C(page, 0x74655F32);
    D_8AF37764 = func_8AC06D8C(page, 0x626F6F6B);
    D_8AF37768 = func_8AC06D8C(page, 0x70616765);
    D_8AF37784 = (void *)func_8AC06D8C(page, 0x6E5F7769);
    D_8AF37788 = (void *)func_8AC06D8C(page, 0x675F7769);
    D_8AF3778C = (void *)func_8AC06D8C(page, 0x755F7769);
    D_8AF37778 = (void *)func_8AC06D8C(page, 0x6E5F665F);
    D_8AF3777C = (void *)func_8AC06D8C(page, 0x675F665F);
    D_8AF37780 = (void *)func_8AC06D8C(page, 0x755F665F);
    D_8AF377BC = (u8 *)func_8AC06D8C(page, 0x6E6E6E6E);
    D_8AF377C0 = (u8 *)func_8AC06D8C(page, 0x6E5F6E5F);
    *(u16 *)((u8 *)D_8AF377BC + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AF377BC + 2) &= 0xFFFD;
    D_8AF377C4 = (u8 *)func_8AC06D8C(page, 0x67676767);
    D_8AF377C8 = (u8 *)func_8AC06D8C(page, 0x675F675F);
    *(u16 *)((u8 *)D_8AF377C4 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AF377C4 + 2) &= 0xFFFD;
    D_8AF377CC = (u8 *)func_8AC06D8C(page, 0x75757575);
    D_8AF377D0 = (u8 *)func_8AC06D8C(page, 0x755F755F);
    *(u16 *)((u8 *)D_8AF377CC + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AF377CC + 2) &= 0xFFFD;
    func_8004E308((s32)D_8AF377C0, (s32 *)func_8AF1C3A0, NULL);
    func_8004E308((s32)D_8AF377C8, (s32 *)func_8AF1C43C, NULL);
    func_8004E308((s32)D_8AF377D0, (s32 *)func_8AF1C4D8, NULL);
    page = func_8AF003A8(0x35);
    func_8AC02C80(page, 0x74697431, 0x74697432, D_8AF37728);
    D_8AF37790 = (u8 *)func_8AC06D8C(page, 0x7469746C);
    *(s16 *)((u8 *)D_8AF37790 + 0x30) = 0x36;
    *(s16 *)((u8 *)D_8AF37790 + 0x32) = 0x10;
    D_8AF27920 = func_8AC01354(D_8AF274A0, 0xA);
    D_8AF27924 = func_8AC01354(D_8AF277E0, 0xA);
    D_8AF27928 = func_8AC01354(D_8AF275E0, 0x10);
    func_8AF1C678();
    switch (D_8AF3779E) {
    case 1:
        D_8AF37718 = D_8AF37708;
        D_8AF3771C = D_8AF3770C;
        D_8AF37720 = D_8AF37710;
        func_8AF1C574();
        break;
    case 3:
        D_8AF3771C = D_8AF37708;
        D_8AF37718 = D_8AF3770C;
        D_8AF37720 = D_8AF37710;
        func_8AF1C574();
        break;
    case 2:
        D_8AF3771C = D_8AF37708;
        D_8AF37720 = D_8AF3770C;
        D_8AF37718 = D_8AF37710;
        func_8AF1C574();
        break;
    case 0:
    default:
        break;
    }
    if (D_8AF3779E != 0) {
        // 0.01 and 0.6 from fragment44_rodata_tail.rodata; copied to locals so
        // each store reuses one load instead of reloading around float stores.
        f32 small = D_8AF29E58;
        f32 big = D_8AF29E5C;

        *(f32 *)((u8 *)D_8AF37718 + 0x40) = big;
        *(f32 *)((u8 *)D_8AF37718 + 0x44) = big;
        *(f32 *)((u8 *)D_8AF3771C + 0x40) = small;
        *(f32 *)((u8 *)D_8AF3771C + 0x44) = small;
        *(f32 *)((u8 *)D_8AF37720 + 0x40) = small;
        *(f32 *)((u8 *)D_8AF37720 + 0x44) = small;
        *(f32 *)((u8 *)D_8AF37718 + 0x48) = 120.0f;
        *(f32 *)((u8 *)D_8AF37718 + 0x4C) = 180.0f;
    }
}
/* mkdraft:func_8AF1C830 end */

void func_8AF1CDAC(f32 *arg0, f32 arg1, f32 arg2) {
    f32 value = *arg0;
    if (arg1 < value) {
        value -= arg2;
        if (value < arg1) value = arg1;
        *arg0 = value;
    }
}

void func_8AF1CDEC(f32 *arg0, f32 arg1, f32 arg2) {
    f32 value = *arg0;
    if (value < arg1) {
        value += arg2;
        if (arg1 < value) value = arg1;
        *arg0 = value;
    }
}

extern u8 *D_8AF263C0;

extern void *D_8AF37714;

extern s16 D_8AF37794;

extern s16 D_8AF37796;

extern s16 D_8AF377A0;

extern s16 D_8AF377A2;

s16 func_8AF1CE2C(void) {
    s16 result = 23;
    f32 scale;
    s16 old_selection;
    switch (D_8AF3779E) {
    case 0:
        if (*(u16 *)(D_8AF263C0 + 8) & 0x4000) {
            func_8AF00130(3);
            result = 7;
            break;
        }
        old_selection = D_8AF37754;
        switch (D_8AF37754) {
case 0:
if (*(u16 *)(D_8AF263C0 + 8) & 0x100) D_8AF37754 = 2;
else if (*(u16 *)(D_8AF263C0 + 8) & 0x8000) {
func_8AF00130(192);
D_8AF3779E = 4;
D_8AF37798 = 0;

D_8AF37794 = (s16)*(f32 *)((u8 *)D_8AF37708 + 0x48);
D_8AF37796 = (s16)*(f32 *)((u8 *)D_8AF37708 + 0x4C);
func_8AF1C574();
} break;
case 2:
if (*(u16 *)(D_8AF263C0 + 8) & 0x200) D_8AF37754 = 0;
else if (*(u16 *)(D_8AF263C0 + 8) & 0x100) D_8AF37754 = 1;
else if (*(u16 *)(D_8AF263C0 + 8) & 0x8000) {
func_8AF00130(192);
D_8AF3779E = 6;
D_8AF3779C = 0;
D_8AF377A0 = 0; D_8AF377A2 = 0;
D_8AF37794 = (s16)*(f32 *)((u8 *)D_8AF3770C + 0x48);
D_8AF37796 = (s16)*(f32 *)((u8 *)D_8AF3770C + 0x4C);
func_8AF1C574();
} break;
case 1:
if (*(u16 *)(D_8AF263C0 + 8) & 0x200) D_8AF37754 = 2;
else if (*(u16 *)(D_8AF263C0 + 8) & 0x8000) {
func_8AF00130(192);
D_8AF3779E = 5;
D_8AF3779A = 0;

D_8AF37794 = (s16)*(f32 *)((u8 *)D_8AF37710 + 0x48);
D_8AF37796 = (s16)*(f32 *)((u8 *)D_8AF37710 + 0x4C);
func_8AF1C574();
} break;
} if (old_selection != D_8AF37754) func_8AF00130(1); break;
case 1:
if (*(u16 *)(D_8AF263C0 + 8) & 0x8000) { func_8AF00130(193); result = 24; func_8AF1DCA8(); }
else if (*(u16 *)(D_8AF263C0 + 8) & 0x4000) { func_8AF00130(3); D_8AF3779E = 7; }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x800) && D_8AF37798 > 0) { func_8AF00130(1); D_8AF37798--;  }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x400) && D_8AF37798 < D_8AF27920 - 1) { func_8AF00130(1); D_8AF37798++;  }
break;
case 3:
if (*(u16 *)(D_8AF263C0 + 8) & 0x8000) { func_8AF00130(193); result = 25;  }
else if (*(u16 *)(D_8AF263C0 + 8) & 0x4000) { func_8AF00130(3); D_8AF3779E = 9; }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x800) && D_8AF377A2 > 0) {  D_8AF377A2--; func_8AF00130(1); }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x400) && D_8AF377A2 < 7) {  D_8AF377A2++; func_8AF00130(1); }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x200) && D_8AF377A0 > 0) { D_8AF377A0--; func_8AF00130(1); }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x100) && D_8AF377A0 <= 0) { D_8AF377A0++; func_8AF00130(1); }
D_8AF3779C = D_8AF377A2 + D_8AF377A0 * 8;
break;
case 2:
if (*(u16 *)(D_8AF263C0 + 8) & 0x8000) { func_8AF00130(193); result = 28; func_8AF1EAC8(); }
else if (*(u16 *)(D_8AF263C0 + 8) & 0x4000) { func_8AF00130(3); D_8AF3779E = 8; }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x800) && D_8AF3779A > 0) { func_8AF00130(1); D_8AF3779A--;  }
else if ((*(u16 *)(D_8AF263C0 + 12) & 0x400) && D_8AF3779A < D_8AF27924 - 1) { func_8AF00130(1); D_8AF3779A++;  }
break;
} switch (D_8AF3779E) {
case 0:
func_8AC06400(D_8AF37708, D_8AF3776C);
func_8AC06400(D_8AF3770C, D_8AF37770);
func_8AC06400(D_8AF37710, D_8AF37774);
switch (D_8AF37754) {
case 0: D_8AF37714 = D_8AF37708; break;
case 2: D_8AF37714 = D_8AF3770C; break;
case 1: D_8AF37714 = D_8AF37710; break;
default: D_8AF37714 = D_8AF37708; break;
}
scale = 1.1f;
*(f32 *)((u8 *)D_8AF37714 + 0x40) = scale;
*(f32 *)((u8 *)D_8AF37714 + 0x44) = scale;
break;
case 1: case 4: case 7:
D_8AF37718 = D_8AF37708;
D_8AF3771C = D_8AF3770C;
D_8AF37720 = D_8AF37710;
scale = 1.1f; break;
case 3: case 6: case 9:
D_8AF3771C = D_8AF37708;
D_8AF37718 = D_8AF3770C;
D_8AF37720 = D_8AF37710;
scale = 1.1f; break;
case 2: case 5: case 8:
D_8AF3771C = D_8AF37708;
D_8AF37720 = D_8AF3770C;
D_8AF37718 = D_8AF37710;
scale = 1.1f; break;
default: scale = 1.1f; break;
}
switch (D_8AF3779E) {
case 4: case 5: case 6:
func_8AF1CDAC((f32 *)((u8 *)D_8AF37718 + 0x40), 0.6f, 0.1f);
func_8AF1CDAC((f32 *)((u8 *)D_8AF3771C + 0x40), 0.01f, 0.4f);
func_8AF1CDAC((f32 *)((u8 *)D_8AF37720 + 0x40), 0.01f, 0.4f);
func_8AF1CDAC((f32 *)((u8 *)D_8AF37718 + 0x44), 0.6f, 0.1f);
func_8AF1CDAC((f32 *)((u8 *)D_8AF3771C + 0x44), 0.01f, 0.4f);
func_8AF1CDAC((f32 *)((u8 *)D_8AF37720 + 0x44), 0.01f, 0.4f);
*(f32 *)((u8 *)D_8AF37718 + 0x48) += (120.0f - (*(f32 *)((u8 *)D_8AF37718 + 0x48))) * 0.25f;
*(f32 *)((u8 *)D_8AF37718 + 0x4C) += (180.0f - (*(f32 *)((u8 *)D_8AF37718 + 0x4C))) * 0.25f;
if (-0.2f < (120.0f - (*(f32 *)((u8 *)D_8AF37718 + 0x48)))) *(f32 *)((u8 *)D_8AF37718 + 0x48) = 120.0f;
if (-0.2f < (180.0f - (*(f32 *)((u8 *)D_8AF37718 + 0x4C)))) *(f32 *)((u8 *)D_8AF37718 + 0x4C) = 180.0f;
if ((s16)(*(f32 *)((u8 *)D_8AF37718 + 0x48)) == 120 && (s16)(*(f32 *)((u8 *)D_8AF37718 + 0x4C)) == 180) {
switch (D_8AF3779E) { case 4: D_8AF3779E = 1; break; case 6: D_8AF3779E = 3; break; case 5: D_8AF3779E = 2; break; }
} break;
case 7: case 8: case 9:
func_8AF1CDEC((f32 *)((u8 *)D_8AF37718 + 0x40), scale, 0.1f);
func_8AF1CDEC((f32 *)((u8 *)D_8AF3771C + 0x40), 1.0f, 0.4f);
func_8AF1CDEC((f32 *)((u8 *)D_8AF37720 + 0x40), 1.0f, 0.4f);
func_8AF1CDEC((f32 *)((u8 *)D_8AF37718 + 0x44), 1.1f, 0.1f);
func_8AF1CDEC((f32 *)((u8 *)D_8AF3771C + 0x44), 1.0f, 0.4f);
func_8AF1CDEC((f32 *)((u8 *)D_8AF37720 + 0x44), 1.0f, 0.4f);
*(f32 *)((u8 *)D_8AF37718 + 0x48) += ((f32)D_8AF37794 - (*(f32 *)((u8 *)D_8AF37718 + 0x48))) * 0.25f;
*(f32 *)((u8 *)D_8AF37718 + 0x4C) += ((f32)D_8AF37796 - (*(f32 *)((u8 *)D_8AF37718 + 0x4C))) * 0.25f;
if (((f32)D_8AF37794 - (*(f32 *)((u8 *)D_8AF37718 + 0x48))) < 1.0f) *(f32 *)((u8 *)D_8AF37718 + 0x48) = (f32)D_8AF37794;
if (((f32)D_8AF37796 - (*(f32 *)((u8 *)D_8AF37718 + 0x4C))) < 1.0f) *(f32 *)((u8 *)D_8AF37718 + 0x4C) = (f32)D_8AF37796;
if (D_8AF37794 == (s16)(*(f32 *)((u8 *)D_8AF37718 + 0x48)) && D_8AF37796 == (s16)(*(f32 *)((u8 *)D_8AF37718 + 0x4C))) { D_8AF3779E = 0; func_8AF1C5F0(); }
break;
}
func_8AF1C678();
switch (D_8AF3779E) {
case 1:
*(u16 *)(D_8AF377BC + 2) |= 1;
*(u16 *)(D_8AF377C4 + 2) &= ~1;
*(u16 *)(D_8AF377CC + 2) &= ~1;
break;
case 3:
*(u16 *)(D_8AF377BC + 2) &= ~1;
*(u16 *)(D_8AF377C4 + 2) |= 1;
*(u16 *)(D_8AF377CC + 2) &= ~1;
break;
case 2:
*(u16 *)(D_8AF377BC + 2) &= ~1;
*(u16 *)(D_8AF377C4 + 2) &= ~1;
*(u16 *)(D_8AF377CC + 2) |= 1;
break;
case 0: default:
*(u16 *)(D_8AF377BC + 2) &= ~1;
*(u16 *)(D_8AF377C4 + 2) &= ~1;
*(u16 *)(D_8AF377CC + 2) &= ~1;
break;
}
return result;
}
void func_8AF1DB30(void) {

}
#endif
