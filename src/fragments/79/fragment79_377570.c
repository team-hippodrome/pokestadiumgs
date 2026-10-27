#include "global.h"


#ifdef VERSION_US
extern s32 D_84190170;
void func_84107CE0(void) {
    D_84190170 = 0;
}

extern s32 D_84190178;
void func_84107CEC(void) {
    D_84190178 = 0;
    D_84190170 += 4;
}

void func_84107D0C(void) {
    D_84190170 += 4;
}

extern s32 D_84190174;
void func_84107D24(void) {
    D_84190174 = 0;
    D_84190178 = 0;
    D_84190170 += 4;
}

void func_84107D4C(void) {
    u8 *ptr = (u8 *)(u32)D_84190170;
    (*(void (**)(s32, s32))(ptr + 4))(*(s32 *)(ptr + 8), *(s32 *)(ptr + 0xC));
    D_84190170 += 0x10;
}

extern s32 D_8416A210;
extern u8 D_8416A218[];
// Script command handler: steps the script pointer D_84190170 past this command, then
// skips whole commands (length from the command's D_8416A218 entry) until it reaches
// command 3 or the command 10 whose zero-based occurrence number equals D_8416A210.
void func_84107D90(void) {
    typedef struct { void (*callback)(void); s32 unk_04; } unk_D_8416A218;
    s32 index;
    u8 cmd;

    index = 0;
    D_84190170 += 4;
    while (TRUE) {
        cmd = *(u8 *)(u32)D_84190170;
        if (cmd == 10) {
            if (index == D_8416A210) {
                break;
            }
            index++;
        } else if (cmd == 3) {
            break;
        }
        D_84190170 += ((unk_D_8416A218 *)D_8416A218)[cmd].unk_04;
    }
}

void func_84107E08(void) {
    D_84190170 += 4;
}

extern s32 D_84190170;
extern u8 D_8416A218[];

void func_84107E20(void) {
    u8 cmd;

    D_84190170 += 4;
    while (TRUE) {
        cmd = *(u8 *)(u32)D_84190170;
        if (cmd == 3) {
            break;
        }
        if (cmd == 0) {
            break;
        }
        D_84190170 += *(s32 *)(D_8416A218 + cmd * 8 + 4);
    }
}
extern s32 D_8416A210;
extern s16 D_8416A214;
extern u8 D_8416A218[];
extern s32 D_84190194;
extern u8 *D_84193DD0;
extern s32 func_8411E1F8(s32);
extern s32 func_8006456C(s32);
extern u32 func_80003240(u32);
extern s32 func_84105DD0(void);
void func_84107E70(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u8 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = *(u8 *)((u8 *)(u32)source + 1);
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = *(u8 *)((u8 *)(u32)source + 2);
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 0;
        *(s16 *)((u8 *)(u32)D_84190174 + 0xA) = D_8416A214;
    }
    D_84190170 += 8;
}

void func_84107F18(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u8 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = *(u8 *)((u8 *)(u32)source + 1);
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = *(u8 *)((u8 *)(u32)source + 2);
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 1;
        *(s16 *)((u8 *)(u32)D_84190174 + 0xA) = D_8416A214;
    }
    D_84190170 += 8;
}

void func_84107FC4(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u8 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = *(u8 *)((u8 *)(u32)source + 1);
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = *(u8 *)((u8 *)(u32)source + 2);
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 7;
    }
    D_84190170 += 8;
}

void func_84108060(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u32 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = 0;
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = 1;
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 2;
    }
    D_84190170 += 8;
}

void func_841080F8(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u32 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = 0;
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = 1;
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 4;
    }
    D_84190170 += 8;
}

void func_84108190(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u32 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = 0;
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = 1;
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 8;
    }
    D_84190170 += 8;
}

void func_84108228(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u16 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = 0;
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = 1;
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 5;
    }
    D_84190170 += 8;
}

void func_841082C0(void) {
    u8 *ptr;
    u32 source;

    ptr = (u8 *)(u32)D_84190170;
    source = func_80003240(*(u32 *)(ptr + 4));
    D_84190174 = func_84105DD0();
    if (D_84190174 == 0) {
        D_84190170 = 0;
    } else {
        *(s32 *)((u8 *)(u32)D_84190174 + 0) = source;
        *(u8 *)((u8 *)(u32)D_84190174 + 4) = *(u16 *)((u8 *)(u32)source + 0);
        *(u8 *)((u8 *)(u32)D_84190174 + 5) = 0;
        *(u8 *)((u8 *)(u32)D_84190174 + 7) = 1;
        *(u8 *)((u8 *)(u32)D_84190174 + 9) = 6;
    }
    D_84190170 += 8;
}

void func_84108358(void) {
    s32 index;

    index = func_8411E1F8(D_84190194);
    if (func_8006456C(*(u16 *)((u8 *)(u32)D_84193DD0 + (index << 4) + 0x14)) == 1) {
        D_8416A210 = 1;
    } else {
        D_8416A210 = 0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_377570/func_841083B0.s")

void func_84108630(void) {
    D_84190178 = 1;
    D_84190170 += 4;
}

extern s32 D_84182154[];
void func_84108654(u16 arg0, u16 arg1) {
    typedef struct { void (*callback)(void); s32 unk_04; } unk_D_8416A218;
    s32 temp_s0;
    u8 *var_p;

    D_84190170 = D_84182154[arg0];
    D_8416A214 = arg1;
    temp_s0 = D_84190170;
    var_p = D_8416A218;
    if (temp_s0 != 0) {
        do {
            ((unk_D_8416A218 *)var_p)[*(u8 *)temp_s0].callback();
            temp_s0 = D_84190170;
        } while (temp_s0 != 0);
    }
}
#endif
