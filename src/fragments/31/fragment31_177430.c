#include "global.h"


#ifdef VERSION_US
extern void func_800226C0(s32);
extern u8 D_88234680;

void func_882041B0(void) {
    (*(s32 *)((u8 *)(&D_88234680) + (0x2C))) = (s32) (*(s32 *)((u8 *)(&D_88234680) + (0x28)));
    func_800226C0(0x132);
}

extern s32 D_882346AC;
void func_882041E0(void) {
    D_882346AC = 2;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_177430/func_882041F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_177430/func_88204400.s")

extern void func_80044424(s16, s16, s16, s16, s16, s16, s16, s16, s32, s32);



void func_88205114(s32 arg0, s32 arg1) {
    func_80044424((s16)(arg0 - 7), 0, 8, (s16)(arg1 - 7), 0x100, 0xA0, 0x400, 0, 0, 1);
    func_80044424((s16)(arg0 - 7), (s16)(arg1 - 7), 8, 8, 0x300, 0, 0x400, 0x400, 0, 1);
    func_80044424(0, (s16)(arg1 - 7), (s16)(arg0 - 7), 8, 0x2E0, 0, 0, 0x400, 0, 1);
}

/* mkdraft:func_88205200 begin */
extern void func_80044424(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle, s32 tile);

// Both parameters are s32: the target loads arg1 from its incoming-argument home
// slot as a word (lw 0x3c(sp)) and narrows the result with sll/sra, and it also
// reloads arg0 as a word (lw 0x38(sp)) for the last quad's x/width arithmetic.
// Declaring either parameter s16 turns that reload into lh from the home word.


void func_88205200(s32 arg0, s32 arg1) {
    func_80044424((s16)arg0, 0, 5, (s16)(arg1 - 7), 0, 160, 1024, 0, 0, 1);
    func_80044424((s16)arg0, (s16)(arg1 - 7), 5, 8, 512, 0, 1024, 1024, 0, 1);
    func_80044424((s16)(arg0 + 5), (s16)(arg1 - 7), (s16)(0x27B - arg0), 8, 736, 0, 0, 1024, 0, 1);
}
/* mkdraft:func_88205200 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_177430/func_882052F8.s")

s32 func_88205D7C(void) {
    return (D_882346AC == 3) ? 1 : 0;
}
#endif
