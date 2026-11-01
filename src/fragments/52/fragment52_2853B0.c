#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_86406EF0 begin */
extern u8 *D_86416C00;
extern u8 *D_87F119DC;
extern u32 func_8003570C(void);
extern void func_8003F210(void *, s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern s32 ModelAnim_HasCrossedFrame(u8 *, s16);
extern void func_87C03B60(void *, void *, void *);
extern void func_8002781C(s32, u8, void *);



void func_86406EF0(void) {
    u8 *node;

    node = *(u8 **)(D_87F119DC + 0x20);
    switch (*(s32 *)(D_86416C00 + 0x10)) {
    case 1:
        break;
    case 2:
        if (*(s16 *)(D_87F119DC + 0x64) != 1) {
            func_8003F210(D_87F119DC + 0x24, 1);
            ModelAnim_SetFrame(D_87F119DC + 0x24, (s16)(func_8003570C() % 7U));
        }
        *(f32 *)(node + 0x18) += 3.5f;
        *(f32 *)(D_87F119DC + 0x48) += *(f32 *)(D_87F119DC + 0x10) * *(f32 *)(node + 0x18);
        *(f32 *)(D_87F119DC + 0x4C) += *(f32 *)(D_87F119DC + 0x14) * *(f32 *)(node + 0x18);
        *(f32 *)(D_87F119DC + 0x50) += *(f32 *)(D_87F119DC + 0x18) * *(f32 *)(node + 0x18);
        if (ModelAnim_HasCrossedFrame(D_87F119DC + 0x24, 1) != 0) {
            func_87C03B60(D_86416C00 + 0xCEC8, D_87F119DC + 0x48, node + 0x58);
            func_8002781C(0x5F00, *(u8 *)(node + 3), node + 0x58);
        }
        break;
    }
}
/* mkdraft:func_86406EF0 end */

extern u8 *D_86416C00;
extern void func_87F026E8(void *, void *);
void func_86407034(void) {
    u8 *entry = *(u8 **)(D_86416C00 + 0xEC);

    if (entry != NULL) {
        do {
            func_87F026E8(D_86416C00 + 0xE0, entry);
            entry = *(u8 **)(entry + 4);
        } while (entry != NULL);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/52/fragment52_2853B0/func_8640708C.s")
#endif
