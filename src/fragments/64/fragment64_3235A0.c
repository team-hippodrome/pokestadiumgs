#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern u8 *D_87F0F610;
u32 func_87F00930(void) {
    return ((u32)D_87F0F610[0x3D]) >> 7;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3235A0/func_87F00944.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3235A0/func_87F01110.s")

// Sets or clears bit 1 of the u16 at arg1 + 2. arg0 == 0 always clears it.
// arg0 == 1 clears it unless a mode pairing matches: the word at
// D_87F0F610 + 0x10 picks a row (0..2), the word at arg1 + 0x20 picks a
// column, and the word at D_87F0F610 + 0x30 must equal the column's
// required value (row 0: columns 0/1/2 require 2/3/4; rows 1 and 2:
// columns 0/1 require 2 and 4). func_87F01870 writes both state words.
void func_87F012BC(s32 arg0, void *arg1) {
    s32 temp_v0;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v0_4;

    switch (arg0) {                                 /* irregular */
    case 0:
        (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
        return;
    case 1:
        temp_v0 = (*(s32 *)(D_87F0F610 + 0x10));
        switch (temp_v0) {                          /* irregular */
        case 0:
            temp_v0_2 = (*(s32 *)((u8 *)arg1 + 0x20));
            switch (temp_v0_2) {                    /* irregular */
            case 0:
                if ((*(s32 *)(D_87F0F610 + 0x30)) == 2) {
                    (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) | 2);
                    return;
                }
                (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
                return;
            case 1:
                if ((*(s32 *)(D_87F0F610 + 0x30)) == 3) {
                    (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) | 2);
                    return;
                }
                (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
                return;
            case 2:
                if ((*(s32 *)(D_87F0F610 + 0x30)) == 4) {
                    (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) | 2);
                    return;
                }
                (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
                return;
            }
            break;
        case 1:
            temp_v0_3 = (*(s32 *)((u8 *)arg1 + 0x20));
            switch (temp_v0_3) {                    /* irregular */
            case 0:
                if ((*(s32 *)(D_87F0F610 + 0x30)) == 2) {
                    (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) | 2);
                    return;
                }
                (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
                return;
            case 1:
                if ((*(s32 *)(D_87F0F610 + 0x30)) == 4) {
                    (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) | 2);
                    return;
                }
                (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
                return;
            }
            break;
        case 2:
            temp_v0_4 = (*(s32 *)((u8 *)arg1 + 0x20));
            switch (temp_v0_4) {                    /* irregular */
            case 0:
                if ((*(s32 *)(D_87F0F610 + 0x30)) == 2) {
                    (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) | 2);
                    return;
                }
                (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
                return;
            case 1:
                if ((*(s32 *)(D_87F0F610 + 0x30)) == 4) {
                    (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) | 2);
                    return;
                }
                (*(u16 *)((u8 *)arg1 + 2)) = (u16) ((*(u16 *)((u8 *)arg1 + 2)) & 0xFFFD);
                return;
            }
            break;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3235A0/func_87F014C4.s")

extern u8 D_87F11940[];
void func_87F01870(void *arg0) {
    D_87F0F610 = D_87F11940;
    *(void **)(D_87F0F610 + 0xC) = arg0;
    *(s32 *)(D_87F0F610 + 0x30) = 2;
    D_87F0F610[0x3D] &= ~0x80; // Clears the bit func_87F00930 returns.
    D_87F0F610[0x3C] = 0;
    func_87F0E390(D_87F0F610, *(void **)(D_87F0F610 + 0xC));
    switch ((*(u8 **)(D_87F0F610 + 0xC))[0x2180]) {
        case 0:
            *(s32 *)(D_87F0F610 + 0x10) = 0;
            func_87F014C4(0, 118);
            break;
        case 1:
            *(s32 *)(D_87F0F610 + 0x10) = 1;
            func_87F014C4(1, 194);
            func_87F014C4(2, 121);
            break;
    }
}

void func_87F01934(void) {
    ControllerState *entry = D_800CE060;
    s32 offset;

    for (offset = 0; offset < 8; offset += 2) {
        *(u16 *)(D_87F0F610 + offset + 0x34) = entry->flags;
        func_80006148(entry);
        entry++;
    }
}

/* mkdraft:func_87F019A4 begin */
void func_87F019A4(void) {
    ControllerState *entry = D_800CE060;
    s32 offset;

    for (offset = 0; offset < 8; offset += 2) {
        entry->flags = *(u16 *)(D_87F0F610 + offset + 0x34);
        entry++;
    }
}
/* mkdraft:func_87F019A4 end */

extern void Audio_PlayDefaultSound(s32);
extern void func_8002809C();
void func_87F019F0(void) {
    func_8002809C();
    if ((*(s32 *)((u8 *)(D_87F0F610) + (0x30))) == 2) {
        Audio_PlayDefaultSound(0xCF08);
        return;
    }
    Audio_PlayDefaultSound(0xCF02);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3235A0/func_87F01A40.s")

extern void func_87F08FA0(u8);
extern void func_800503A4(s32);
void func_87F01D44(void) {
    if ((u32)D_87F0F610[0x3D] >> 7) {
        func_87F08FA0(D_87F0F610[0x3C]);
        func_800503A4(((s32 *)(D_87F0F610 + 0x20))[*(s32 *)(D_87F0F610 + 0x10)]);
    }
}
#endif
