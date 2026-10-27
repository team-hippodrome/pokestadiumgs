#include "global.h"


#ifdef VERSION_US
extern u8 *D_87F0F610;
u32 func_87F00930(void) {
    return ((u32)D_87F0F610[0x3D]) >> 7;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3235A0/func_87F00944.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3235A0/func_87F01110.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3235A0/func_87F012BC.s")

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

extern u8 D_800CE060[];
extern void func_80006148(u8 *);
void func_87F01934(void) {
    u8 *entry = D_800CE060;
    s32 offset;

    for (offset = 0; offset < 8; offset += 2) {
        *(u16 *)(D_87F0F610 + offset + 0x34) = *(u16 *)(entry + 0x10);
        func_80006148(entry);
        entry += 0x28;
    }
}

/* mkdraft:func_87F019A4 begin */
void func_87F019A4(void) {
    u8 *entry = D_800CE060;
    s32 offset;

    for (offset = 0; offset < 8; offset += 2) {
        *(u16 *)(entry + 0x10) = *(u16 *)(D_87F0F610 + offset + 0x34);
        entry += 0x28;
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
