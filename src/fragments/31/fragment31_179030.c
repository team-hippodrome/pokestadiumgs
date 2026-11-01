#include "global.h"


#ifdef VERSION_US
extern void Util_Free(void *);
extern void *D_882346F8;

void func_88205DB0(void) {
    (*(s32 (**)())((u8 *)(D_882346F8) + (0x9C)))();
    Util_Free(D_882346F8);
}

extern void func_88200134();
void func_88205DE8(void) { func_88200134(0, 1); func_88200134(1, 1); }

extern void D_88000E4C(void);
extern void func_882000AC(u8, s16, s16, u16, u16, s32, s32, u8);
void func_88205E18(void) {
    func_882000AC(2, *(s16 *)((u8 *)D_882346F8 + 0xA), *(s16 *)((u8 *)D_882346F8 + 0xC),
                  *(u16 *)((u8 *)D_882346F8 + 0xE), *(s16 *)((u8 *)D_882346F8 + 0x10), (s32)D_88000E4C,
                  (s32)func_88205DE8, 1);
    func_882000AC(3, *(s16 *)((u8 *)D_882346F8 + 0x1A), *(s16 *)((u8 *)D_882346F8 + 0x1C),
                  *(u16 *)((u8 *)D_882346F8 + 0x1E), *(s16 *)((u8 *)D_882346F8 + 0x20), (s32)D_88000E4C,
                  (s32)D_88000E4C, 1);
}

/* mkdraft:func_88205EB0 begin */
// Copies the caller's 76 s16 values into a 0xA0-byte structure allocated here
// (+2..+0x98), together with two u8 fields (+0/+1) and a callback (+0x9C), then
// allocates four 0x44-byte entries and queues two of them via func_882000AC.
// The wide argument list matches the caller's frame, which hands every value its
// own 32-bit stack slot.
//@src/fragments/31/fragment31_1732A0.c
extern s32 D_88234598;
extern s32 D_8823459C;
extern s32 D_882345A0;
extern s32 D_882345A4;
extern s32 D_882345A8;
extern s32 D_882345AC;
extern s32 D_882345B0;
extern s32 D_882345B4;
extern s32 D_882345B8;
extern s32 D_882345BC;
extern s32 D_882345C0;
extern s32 D_882345C4;
extern s32 func_8004C8C0(u16 arg0);
extern s32 func_8004C990(s32, s32);
extern void func_88200020(u8 count);



void func_88205EB0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s16 arg8, s16 arg9, s16 arg10, s16 arg11, s16 arg12, s16 arg13, s16 arg14, s16 arg15, s16 arg16, s16 arg17, s16 arg18, s16 arg19, s16 arg20, s16 arg21, s16 arg22, s16 arg23, s16 arg24, s16 arg25, s16 arg26, s16 arg27, s16 arg28, s16 arg29, s16 arg30, s16 arg31, s16 arg32, s16 arg33, s16 arg34, s16 arg35, s16 arg36, s16 arg37, s16 arg38, s16 arg39, s16 arg40, s16 arg41, s16 arg42, s16 arg43, s16 arg44, s16 arg45, s16 arg46, s16 arg47, s16 arg48, s16 arg49, s16 arg50, s16 arg51, s16 arg52, s16 arg53, s16 arg54, s16 arg55, s16 arg56, s16 arg57, s16 arg58, s16 arg59, s16 arg60, s16 arg61, s16 arg62, s16 arg63, s16 arg64, s16 arg65, s16 arg66, s16 arg67, s16 arg68, s16 arg69, s16 arg70, s16 arg71, s16 arg72, s16 arg73, s16 arg74, s16 arg75, u8 arg76, u8 arg77, s32 arg78) {
    s32 unk_01;

    D_882346F8 = Util_Malloc(0xA0);
    func_8004C8C0(0xF);
    D_88234598 = func_8004C990(0xF, 0);
    D_8823459C = func_8004C990(0xF, 1);
    D_882345A0 = func_8004C990(0xF, 3);
    D_882345A4 = func_8004C990(0xF, 4);
    D_882345A8 = func_8004C990(0xF, 5);
    D_882345AC = func_8004C990(0xF, 6);
    D_882345B0 = func_8004C990(0xF, 7);
    D_882345B4 = func_8004C990(0xF, 8);
    D_882345B8 = func_8004C990(0xF, 9);
    D_882345BC = func_8004C990(0xF, 0xA);
    D_882345C0 = func_8004C990(0xF, 0xB);
    D_882345C4 = func_8004C990(0xF, 0xC);
    *(s16 *)((u8 *)D_882346F8 + 2) = arg0;
    *(s16 *)((u8 *)D_882346F8 + 4) = arg1;
    *(s16 *)((u8 *)D_882346F8 + 6) = arg2;
    *(s16 *)((u8 *)D_882346F8 + 8) = arg3;
    *(s16 *)((u8 *)D_882346F8 + 0xA) = arg4;
    *(s16 *)((u8 *)D_882346F8 + 0xC) = arg5;
    *(s16 *)((u8 *)D_882346F8 + 0xE) = arg6;
    *(s16 *)((u8 *)D_882346F8 + 0x10) = arg7;
    *(s16 *)((u8 *)D_882346F8 + 0x12) = arg8;
    *(s16 *)((u8 *)D_882346F8 + 0x14) = arg9;
    *(s16 *)((u8 *)D_882346F8 + 0x16) = arg10;
    *(s16 *)((u8 *)D_882346F8 + 0x18) = arg11;
    *(s16 *)((u8 *)D_882346F8 + 0x1A) = arg12;
    *(s16 *)((u8 *)D_882346F8 + 0x1C) = arg13;
    *(s16 *)((u8 *)D_882346F8 + 0x1E) = arg14;
    *(s16 *)((u8 *)D_882346F8 + 0x20) = arg15;
    *(s16 *)((u8 *)D_882346F8 + 0x22) = arg16;
    *(s16 *)((u8 *)D_882346F8 + 0x24) = arg17;
    *(s16 *)((u8 *)D_882346F8 + 0x26) = arg18;
    *(s16 *)((u8 *)D_882346F8 + 0x28) = arg19;
    *(s16 *)((u8 *)D_882346F8 + 0x2A) = arg20;
    *(s16 *)((u8 *)D_882346F8 + 0x2C) = arg21;
    *(s16 *)((u8 *)D_882346F8 + 0x2E) = arg22;
    *(s16 *)((u8 *)D_882346F8 + 0x30) = arg23;
    *(s16 *)((u8 *)D_882346F8 + 0x32) = arg24;
    *(s16 *)((u8 *)D_882346F8 + 0x34) = arg25;
    *(s16 *)((u8 *)D_882346F8 + 0x36) = arg26;
    *(s16 *)((u8 *)D_882346F8 + 0x38) = arg27;
    *(s16 *)((u8 *)D_882346F8 + 0x3A) = arg28;
    *(s16 *)((u8 *)D_882346F8 + 0x3C) = arg29;
    *(s16 *)((u8 *)D_882346F8 + 0x3E) = arg30;
    *(s16 *)((u8 *)D_882346F8 + 0x40) = arg31;
    *(s16 *)((u8 *)D_882346F8 + 0x42) = arg32;
    *(s16 *)((u8 *)D_882346F8 + 0x44) = arg33;
    *(s16 *)((u8 *)D_882346F8 + 0x46) = arg34;
    *(s16 *)((u8 *)D_882346F8 + 0x48) = arg35;
    *(s16 *)((u8 *)D_882346F8 + 0x4A) = arg36;
    *(s16 *)((u8 *)D_882346F8 + 0x4C) = arg37;
    *(s16 *)((u8 *)D_882346F8 + 0x4E) = arg38;
    *(s16 *)((u8 *)D_882346F8 + 0x50) = arg39;
    *(s16 *)((u8 *)D_882346F8 + 0x52) = arg40;
    *(s16 *)((u8 *)D_882346F8 + 0x54) = arg41;
    *(s16 *)((u8 *)D_882346F8 + 0x56) = arg42;
    *(s16 *)((u8 *)D_882346F8 + 0x58) = arg43;
    *(s16 *)((u8 *)D_882346F8 + 0x5A) = arg44;
    *(s16 *)((u8 *)D_882346F8 + 0x5C) = arg45;
    *(s16 *)((u8 *)D_882346F8 + 0x5E) = arg46;
    *(s16 *)((u8 *)D_882346F8 + 0x60) = arg47;
    *(s16 *)((u8 *)D_882346F8 + 0x62) = arg48;
    *(s16 *)((u8 *)D_882346F8 + 0x64) = arg49;
    *(s16 *)((u8 *)D_882346F8 + 0x66) = arg50;
    *(s16 *)((u8 *)D_882346F8 + 0x68) = arg51;
    *(s16 *)((u8 *)D_882346F8 + 0x6A) = arg52;
    *(s16 *)((u8 *)D_882346F8 + 0x6C) = arg53;
    *(s16 *)((u8 *)D_882346F8 + 0x6E) = arg54;
    *(s16 *)((u8 *)D_882346F8 + 0x70) = arg55;
    *(s16 *)((u8 *)D_882346F8 + 0x72) = arg56;
    *(s16 *)((u8 *)D_882346F8 + 0x74) = arg57;
    *(s16 *)((u8 *)D_882346F8 + 0x76) = arg58;
    *(s16 *)((u8 *)D_882346F8 + 0x78) = arg59;
    *(s16 *)((u8 *)D_882346F8 + 0x7A) = arg60;
    *(s16 *)((u8 *)D_882346F8 + 0x7C) = arg61;
    *(s16 *)((u8 *)D_882346F8 + 0x7E) = arg62;
    *(s16 *)((u8 *)D_882346F8 + 0x80) = arg63;
    *(s16 *)((u8 *)D_882346F8 + 0x82) = arg64;
    *(s16 *)((u8 *)D_882346F8 + 0x84) = arg65;
    *(s16 *)((u8 *)D_882346F8 + 0x86) = arg66;
    *(s16 *)((u8 *)D_882346F8 + 0x88) = arg67;
    *(s16 *)((u8 *)D_882346F8 + 0x8A) = arg68;
    *(s16 *)((u8 *)D_882346F8 + 0x8C) = arg69;
    *(s16 *)((u8 *)D_882346F8 + 0x8E) = arg70;
    *(s16 *)((u8 *)D_882346F8 + 0x90) = arg71;
    *(s16 *)((u8 *)D_882346F8 + 0x92) = arg72;
    *(s16 *)((u8 *)D_882346F8 + 0x94) = arg73;
    *(s16 *)((u8 *)D_882346F8 + 0x96) = arg74;
    *(s16 *)((u8 *)D_882346F8 + 0x98) = arg75;
    *(u8 *)((u8 *)D_882346F8 + 0) = arg76;
    *(u8 *)((u8 *)D_882346F8 + 1) = arg77;
    *(s32 *)((u8 *)D_882346F8 + 0x9C) = arg78;
    func_88200020(4);
    unk_01 = *(u8 *)((u8 *)D_882346F8 + 1);
    // The 4th argument scales the value at +0x50 by the byte at +1 (minus one
    // step); func_882000AC stores it at entry+0xE beside the +0x4A..+0x50 copy.
    func_882000AC(1, *(s16 *)((u8 *)D_882346F8 + 0x4A), *(s16 *)((u8 *)D_882346F8 + 0x4C), (u16) *(u16 *)((u8 *)D_882346F8 + 0x4E), ((*(s16 *)((u8 *)D_882346F8 + 0x50) + *(u8 *)((u8 *)D_882346F8 + 0) * unk_01) - unk_01), (s32) D_88000E4C, (s32) D_88000E4C, 0);
    func_882000AC(0, *(s16 *)((u8 *)D_882346F8 + 2), *(s16 *)((u8 *)D_882346F8 + 4), (u16) *(s16 *)((u8 *)D_882346F8 + 6), (u16) *(s16 *)((u8 *)D_882346F8 + 8), (s32) func_88205E18, (s32) func_88205DB0, 0);
}
/* mkdraft:func_88205EB0 end */

void func_88206430(void) { func_88200134(2, 2); func_88200134(3, 2); }

extern void func_88003A00(s32);
extern s32 D_88234564;
void func_88206460(void) {
    func_88003A00(D_88234564 + 0x88);
    func_88003A00(D_88234564 + 0xCC);
    func_88003A00(D_88234564 + 0x44);
    func_88003A00(D_88234564);
}

extern void func_880022B4(void *, s16, s32);
void func_882064B4(s32 arg0, s32 *arg1, void *arg2, void *arg3) {
    s32 mode;

    *arg1 = arg0;
    if (arg0 != 0) {
        mode = 0;
    } else {
        mode = 1;
    }
    func_880022B4(arg2, 0xF00, mode);
    func_880022B4(arg3, 0xF00, mode);
}

extern void func_800226C0(s32);
extern void func_88903C50(void *, s16, s16, s32, u8, u8, u8, u8, u8,
                         s32 *, s32 *, void (*)(void), void (*)(void));
extern void func_88903B00(void);
extern void D_88000E4C(void);
extern s32 D_880068B4;
extern s32 D_880068B8;

void func_88206508(void *arg0, u8 *arg1) {
    *arg1 = 2;
    func_800226C0(73);
    func_88903C50(arg0, 320, 240, 4, 255, 170, 140, 2, 0,
                 &D_880068B4, &D_880068B8, func_88903B00, D_88000E4C);
}

s32 func_8004C990(s32, s32);
s32 func_8004D150(s32, s32, s32, s32, s32, s32);
extern s32 D_8823459C;
extern s32 D_882345A0;
extern s32 D_882345A4;
extern s32 D_882345B0;
extern s32 D_882345BC;
extern s32 D_882345C0;
extern s32 D_882345C4;

void func_8820659C(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u16 flag = 0;

    if (arg3 != 0) {
        if (arg2 == D_8823459C) {
            arg2 = func_8004C990(0xF, 2);
        } else if ((arg2 == D_882345A0) || (arg2 == D_882345A4) || (arg2 == D_882345B0) ||
                   (arg2 == D_882345BC) || (arg2 == D_882345C0) || (arg2 == D_882345C4)) {
            flag = 1;
        }
    }
    func_8004D150(arg0, arg1, arg2, 0, flag, 0);
}
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern u8 *D_8800ECC0;
extern void func_882001E8(void);
extern void func_882052F8(void);
extern s32 func_8004D27C(u8 *, s32, s32);
extern void func_88002BA0(u8, u8, u8);
extern void func_88200180(u8);

void func_88206668(void) {
    func_882001E8();
    func_882052F8();
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_8004D27C(D_8800ECC0, 128, 1);
    func_88002BA0(220, 220, 180);
    func_88200180(0);
    func_88200180(1);
    gSPDisplayList(D_800D0510++, D_80094F50);
}

/* mkdraft:func_88206714 begin */
extern void Gfx_SetScissorRect(Gfx **, s16, s16, s16, s16);
extern s32 func_8004CA10(u16 *);
extern void func_8004D1FC(u8 *);
extern void func_88002C2C(u8, u8, u8);
extern void func_88002CB8(s16, s16, u16, u16);
extern u8 *D_8800ECC4;
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s32, s32, s32, s32, s32);



void func_88206714(s32 **arg0, u8 arg1) {
    s32 x;
    s32 y;
    u32 i;
    s32 offset;
    s32 **entry;

    // func_80006F70 in the ROM.
    //@linker_scripts/us/aliases.ld
    Gfx_SetScissorRect(&D_800D0510, 0x2C, 0x48, 0x229, 0x17F);
    func_882001E8();
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_8004D1FC(D_8800ECC4);
    func_8004D27C(D_8800ECC0, 0x80, 1);
    func_88002C2C(220, 220, 180);
    // 16-bit field at D_8800ECC4 + 0, scaled by 1024 / width into a texture offset.
    offset = func_8004CA10((u16 *)D_8800ECC4);
    GfxRect_DrawTextured((s16)(*(s16 *)((u8 *)D_882346F8 + 2) + 5),
                         (s16)(*(s16 *)((u8 *)D_882346F8 + 4) + 5),
                         (s16)(*(s16 *)((u8 *)D_882346F8 + 6) - 13),
                         (s16)(*(s16 *)((u8 *)D_882346F8 + 8) - 13), 0, 0,
                         (s32)(1024.0f * (f32)offset / (f32)(*(s16 *)((u8 *)D_882346F8 + 6) - 13) + ((((f32)func_8004CA10((u16 *)D_8800ECC4) * 1024.0f / (f32)(*(s16 *)((u8 *)D_882346F8 + 6) - 13)) > 0.0f) ? 0.5f : -0.5f)), 0, 0);
    i = 0;
    y = *(s16 *)((u8 *)D_882346F8 + 0x4C);
    if (*(u8 *)D_882346F8 != 0) {
        do {
            offset = func_8004CA10((u16 *)D_8800ECC4);
            GfxRect_DrawTextured((s16)(*(s16 *)((u8 *)D_882346F8 + 0x4A) + 5), (s16)(y + 5),
                                 (s16)(*(s16 *)((u8 *)D_882346F8 + 0x4E) - 13),
                                 (s16)(*(s16 *)((u8 *)D_882346F8 + 0x50) - 13), 0, 0,
                         (s32)(1024.0f * (f32)offset / (f32)(*(s16 *)((u8 *)D_882346F8 + 0x4E) - 13) + ((((f32)func_8004CA10((u16 *)D_8800ECC4) * 1024.0f / (f32)(*(s16 *)((u8 *)D_882346F8 + 0x4E) - 13)) > 0.0f) ? 0.5f : -0.5f)), 0, 0);
            i++;
            y += *(u8 *)((u8 *)D_882346F8 + 1);
        } while (i < *(u8 *)D_882346F8);
        i = 0;
    }
    gDPPipeSync(D_800D0510++);
    gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
    // Bands 1 and 2 use opposite arg1 polarities for the 220,220,180 tint.
    if (arg1 == 0) {
        gDPSetEnvColor(D_800D0510++, 220, 220, 180, 255);
    } else {
        gDPSetEnvColor(D_800D0510++, 150, 150, 130, 255);
    }
    func_88200180(2);
    gDPPipeSync(D_800D0510++);
    if (arg1) {
        gDPSetEnvColor(D_800D0510++, 220, 220, 180, 255);
    } else {
        gDPSetEnvColor(D_800D0510++, 150, 150, 130, 255);
    }
    func_88200180(3);
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++, 220, 220, 180, 255);
    func_88002CB8(*(s16 *)((u8 *)D_882346F8 + 2), *(s16 *)((u8 *)D_882346F8 + 4),
                  *(u16 *)((u8 *)D_882346F8 + 6), *(u16 *)((u8 *)D_882346F8 + 8));
    y = *(s16 *)((u8 *)D_882346F8 + 0x4C);
    if (*(u8 *)D_882346F8 != 0) {
        do {
            func_88002CB8(*(s16 *)((u8 *)D_882346F8 + 0x4A), y, *(u16 *)((u8 *)D_882346F8 + 0x4E),
                          *(u16 *)((u8 *)D_882346F8 + 0x50));
            i++;
            y += *(u8 *)((u8 *)D_882346F8 + 1);
        } while (i < *(u8 *)D_882346F8);
        i = 0;
    }
    gDPPipeSync(D_800D0510++);
    gDPSetRenderMode(D_800D0510++, 0x00504240, 0);
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
    x = 77;
    i = 0;
    // entry is only read by the loop below, so it is initialized inside the guard.
    if (*(u8 *)D_882346F8 != 0) {
        entry = arg0;
        do {
            func_8820659C(295, x, **entry, arg1);
            i++;
            x += *(u8 *)((u8 *)D_882346F8 + 1);
            entry++;
        } while (i < *(u8 *)D_882346F8);
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_88206714 end */

extern s32 D_882346F0;

void func_88206C2C(u16 arg0) {
    gDPPipeSync(D_800D0510++);
    if (D_882346F0 == 1 || D_882346F0 == 3 || arg0 != 0) {
        gDPSetEnvColor(D_800D0510++, 220, 220, 180, 255);
    } else {
        gDPSetEnvColor(D_800D0510++, 150, 150, 130, 255);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_179030/func_88206CC0.s")

extern void Gfx_SetScissorRect(Gfx **, s16, s16, s16, s16);
s32 func_880032C4();
extern void func_882001E8();
extern Gfx *D_800D0510;

void func_88207D14(u8 *arg0) {
    if (*arg0 != 0) {
        Gfx_SetScissorRect(&D_800D0510, 0x2C, 0x48, 0x229, 0x17F);
        func_882001E8();
        if (func_880032C4() == 0) {
            *arg0 -= 1;
        }
    }
}

/* mkdraft:func_88207D80 begin */
// func_88207D80 -- matched, ROM-gated (build/pokestadiumgs-us.z64: OK,
// md5 1561c75d11cedf356a8ddb1a4a5f9d5d) on gs-night-4, 2026-10-30.
// D_882346F8 is already declared as `extern void *D_882346F8;` at the top of
// src/fragments/31/fragment31_179030.c; it is repeated here so this file
// stands alone.
extern void *D_882346F8;
extern s16 D_8800EF58;
extern s32 D_880068B4;
extern void func_880009A8(s32, s16, s16, s16, s16, s16, s16);
extern void func_8004B2CC(s32, s32, s32, s32, u8, u8, u8, s32);
extern void func_8004B314(s32, s32, s32, s32);

// Draws list row arg2: the background rectangle at +0x4A/+0x4C (x/y), +0x4E
// (width) and row_height = byte +1 (height), then the slot highlight expanded
// by 2 pixels on every side. arg0 == 0 selects the highlight rect at
// +0x52/+0x56/+0x58, otherwise +0x5A/+0x5E/+0x60; its y comes from field 0x10
// of arg3 or arg4. arg1 selects the textured background (func_880009A8) over
// the solid fill (func_8004B2CC), and arg5 gates the highlight.


void func_88207D80(u8 arg0, s32 arg1, s16 arg2, void *arg3, void *arg4, u16 arg5) {
    s32 pos_x;
    s32 pos_y;
    s32 row_height;

    row_height = *(u8 *)((u8 *)D_882346F8 + 1);
    pos_x = *(s16 *)((u8 *)D_882346F8 + 0x4A);
    pos_y = *(s16 *)((u8 *)D_882346F8 + 0x4C) + (arg2 * row_height);
    if (arg1 != 0) {
        func_880009A8(D_880068B4, pos_x, pos_y, *(s16 *)((u8 *)D_882346F8 + 0x4E), row_height, -2, -2);
        return;
    }
    func_8004B2CC(pos_x + 2, pos_y + 2, *(s16 *)((u8 *)D_882346F8 + 0x4E) - 4, row_height - 4, 0x96, 0x96, 0x5A, 0);
    if ((D_8800EF58 == 0) && (arg5 != 0)) {
        if (arg0 == 0) {
            func_8004B314(*(s16 *)((u8 *)D_882346F8 + 0x52) - 2, *(s16 *)((u8 *)arg3 + 0x10) - 2,
                          *(s16 *)((u8 *)D_882346F8 + 0x56) + 4, *(s16 *)((u8 *)D_882346F8 + 0x58) + 4);
            return;
        }
        func_8004B314(*(s16 *)((u8 *)D_882346F8 + 0x5A) - 2, *(s16 *)((u8 *)arg4 + 0x10) - 2,
                      *(s16 *)((u8 *)D_882346F8 + 0x5E) + 4, *(s16 *)((u8 *)D_882346F8 + 0x60) + 4);
    }
}
/* mkdraft:func_88207D80 end */
#endif
