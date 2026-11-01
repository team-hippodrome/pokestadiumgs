#include "global.h"
#include "controller.h"


#ifdef VERSION_US
// The "9" digit string that func_88223120 measures with func_80049290. The function's
// nonmatchings .s carried these bytes in its .rodata section; this definition now
// supplies the object's whole 16-byte .rodata (the [0x1A7610, .rodata,
// fragments/31/fragment31_195910] subsegment).
const char D_88234390[] = "9";

extern void func_88004EB0();
extern s32 D_880068B8;

void func_88222690(void) {
    func_88004EB0();
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern void Input_SetRepeatController(s32);
extern s32 D_880068B4;
extern s32 D_88234840;

void func_882226B4(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_88234840);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_195910/func_882226F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_195910/func_88222CBC.s")

/* mkdraft:func_88223120 begin */
extern u8 D_8800ED50[];
extern u8 D_88234758[];
extern const char D_88234390[];
extern s32 func_882226F0;
extern s32 func_88222CBC;
extern s32 func_80049290(s32 font, s32 flags, const char *text);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);

// Allocates a 0x20-byte object at D_88234840 whose first word points at entry
// func_88004804(...) of the 0x4C-byte table at D_8800ED50. Fields 0x10/0x12 of that entry are
// set to the coordinates 272 and 126 (0x110/0x7E in the asm); the object itself holds two s16
// fields (0x4, 0x6) copied from D_88234758[2..3], a u8 measured text width at 0x8, and two
// three-entry s16 tables at 0xC and 0x12 whose entries are one measured width plus one pixel apart.


void func_88223120(void) {
    s8 i;
    s16 y;

    D_88234840 = Util_Malloc(0x20);
    *(void **) D_88234840 = (void *) (D_8800ED50 + func_88004804(NULL, 3, 167, 146, 0, 1, 220, 220, 180, &func_882226F0, &func_88222CBC, (s32 *) func_88222690, (s32 *) func_882226B4, 2, 0) * 0x4C);
    *(s16 *) ((u8 *) *(void **) D_88234840 + 0x10) = 272;
    *(s16 *) ((u8 *) *(void **) D_88234840 + 0x12) = 126;
    *(s16 *) (D_88234840 + 4) = D_88234758[2];
    *(s16 *) (D_88234840 + 6) = D_88234758[3];
    *(u8 *) (D_88234840 + 8) = func_80049290(8, 0, D_88234390);
    for (i = 2, y = 182; i >= 0; i--) {
        *(s16 *) (D_88234840 + i * 2 + 0xC) = y;
        y += *(u8 *) (D_88234840 + 8) + 1;
    }
    *(s16 *) (D_88234840 + 0xA) = y + 3;
    y = *(s16 *) (D_88234840 + 0xA) + func_80049290(4, 0, func_8004C874(37, 49)) + 4;
    for (i = 2; i >= 0; i--) {
        *(s16 *) (D_88234840 + i * 2 + 0x12) = y;
        y += *(u8 *) (D_88234840 + 8) + 1;
    }
    *(s16 *) (D_88234840 + 0x18) = 2;
    *(s16 *) (D_88234840 + 0x1A) = 0;
    *(s16 *) (D_88234840 + 0x1C) = 0;
}
/* mkdraft:func_88223120 end */
#endif
