#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_88223320(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern s32 D_880068B4;
extern s32 D_88234850;
void func_88223348(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_88234850);
}

extern void func_88004990(u8, s32);
void func_88223384(void) {
    func_88004990(*(*(u8 **)((u8 *)(D_88234850) + 0)), 0);
    D_880068B8 = 1;
}

extern void func_880022B4(s32, s32, s32);
void func_882233BC(s32 arg0) {
    (*(s32 *)((u8 *)(D_88234850) + (0x30))) = arg0;
    if (arg0 != 0) {
        func_880022B4(D_88234850 + 4, 0xF00, 0);
        return;
    }
    func_880022B4(D_88234850 + 4, 0xF00, 1);
}

/* mkdraft:func_88223418 begin */
extern void func_800226C0(s32);
extern s8 D_882338E0[];

// The current slot and two choices occupy the last four bytes of menu state.
// func_882241B8 allocates 56 bytes and initializes this tail at offset 0x34.
//@src/fragments/31/fragment31_1965A0.c
typedef struct F31SelectionTail {
    s16 current;
    s8 choices[2];
} F31SelectionTail;

void func_88223418(void) {
    struct {
        s8 selected;
        u8 cleared;
    } change;
    u8 index;

    change.selected = D_882338E0[*(s16 *)((s8 *)(u32)D_88234850 + 0xC)];
    change.cleared = 0;
    Input_SetRepeatController(D_80087200);
    func_882233BC(1);
    if (change.selected != ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current]) {
        func_800226C0(71);
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current] = change.selected;
    } else {
        func_800226C0(72);
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current] = -1;
        change.cleared = 1;
    }
    for (index = 0; index < 2; index++) {
        if (change.selected == ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[index] && index != ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current) {
            ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[index] = -1;
        }
    }
    if (((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[0] != -1 && ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->choices[1] != -1) {
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current = 2;
        return;
    }
    if (change.cleared == 0) {
        ((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current = (s16)(((F31SelectionTail *)((u8 *)D_88234850 + 0x34))->current + 1);
    }
}
/* mkdraft:func_88223418 end */

/* mkdraft:func_88223554 begin */
extern s8 D_88234758[];
extern s8 D_8823475F[];

s32 func_88223554(void) {
    s8 *output;
    s32 result;
    s32 index;
    s8 value;
    s16 sentinel;

    result = 0;
    output = D_8823475F;
    sentinel = -1;
    for (index = 0; index < 2; index = (index + 1) & 0xFF) {
        D_88234758[index + 7] = sentinel;
    }
    for (index = 0; index < 2; index = (index + 1) & 0xFF) {
        value = ((s8 *)(u32)D_88234850)[index + 0x36];
        if (sentinel != value) {
            result = 1;
            *output++ = value;
        }
    }
    return result;
}
/* mkdraft:func_88223554 end */

extern u8 D_88006020[];
extern u8 D_88006880[];
extern void func_88001900(void);
extern s32 func_880020CC();
extern void func_8800225C(void *arg0, s16 arg1, s16 arg2);
extern void func_88002720(void *arg0, u16 arg1, void *arg2);
extern s32 func_8821B7C0(void);
extern void func_8821B980(u16 arg0, s32 arg1);
extern s32 func_8821C0B0(void);
extern void func_8821C2F4(void);
// FAKE: the state block is read through a pointer-typed load of D_88234850
// (`*(u8 **)&D_88234850`). This file declares the global as s32, so the plain
// (u8 *)D_88234850 cast leaves an extra int-to-pointer copy in a1: diff 130.


void func_882235CC(void) {
    s32 index;

    if (*(s32 *)((*(u8 **)&D_88234850) + 0x30) != 0) {
        if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) != 0) {
            func_800226C0(0x48);
            func_88223384();
            return;
        }
        if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) != 0) {
            switch (*(s16 *)((*(u8 **)&D_88234850) + 0x34)) {
            case 2:
                func_800226C0(0x5C);
                func_8821C2F4();
                func_8821B980(4, func_88223554());
                func_8821C0B0();
                func_8800225C(D_88006880, 0, 0);
                func_88223384();
                return;
            case 3:
                func_800226C0(0x137);
                func_8821C2F4();
                for (index = 0; index < 2; index = (index + 1) & 0xFF) {
                    D_88234758[index + 7] = -1;
                }
                func_8821B980(4, 0);
                func_8821C0B0();
                func_8800225C(D_88006880, 0, 0);
                func_88223384();
                return;
            default:
                func_800226C0(0x47);
                func_88001900();
                func_882233BC(0);
                return;
            }
        } else {
            func_880020CC(*(u8 **)&D_88234850 + 4);
            if (func_8821B7C0() != 0) {
                func_88002720((*(u8 **)&D_88234850) + 0x34, 4, D_88006020);
            } else {
                func_88002720((*(u8 **)&D_88234850) + 0x34, 3, D_88006020);
            }
        }
    } else {
        // `index` doubles as the loop counter in case 3; the two uses never
        // overlap, and a second local adds a stack home (diff 595).
        if ((*(s16 *)((*(u8 **)&D_88234850) + 4) == 0) &&
            (*(s32 *)((*(u8 **)&D_88234850) + 8) == 0) &&
            (*(s16 *)((*(u8 **)&D_88234850) + 0x26) == 0)) {
            index = 1;
        } else {
            index = 0;
        }
        if (index != 0) {
            if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) != 0) {
                func_800226C0(0x48);
                func_882233BC(1);
                return;
            }
        }
        if ((*(s16 *)((*(u8 **)&D_88234850) + 4) == 0) &&
            (*(s32 *)((*(u8 **)&D_88234850) + 8) == 0) &&
            (*(s16 *)((*(u8 **)&D_88234850) + 0x26) == 0)) {
            index = 1;
        } else {
            index = 0;
        }
        if (index != 0) {
            if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) != 0) {
                func_88223418();
                return;
            }
        }
        func_880020CC(*(u8 **)&D_88234850 + 4);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1965A0/func_88223850.s")

extern void *Util_Malloc(s32);
extern s32 func_88004804(s32, s32, s16, s16, s32, s32, s32, s32, s32,
                         void (*)(void), void (*)(void), void (*)(void),
                         void (*)(void), s32, s32);
extern void func_88001C6C(void *, u16, u8, s16, u8, s16, s16, s16, s16, s16, s32);
extern s32 func_80001FF0(void);
extern u8 D_8800ED50[];
extern void func_882235CC(void);
extern void func_88223850(void);

void func_882241B8(void) {
    s32 result;
    s32 index;
    s32 first_refresh_rate;

    D_88234850 = (s32)Util_Malloc(0x38);
    result = func_88004804(0, 3, 167, 146, 0, 1, 220, 220, 180,
                           func_882235CC, func_88223850, func_88223320,
                           func_88223348, 0, 0);
    *(void **)D_88234850 = D_8800ED50 + result * 0x4C;
    *(s16 *)(*(s32 *)D_88234850 + 0x10) = 253;
    *(s16 *)(*(s32 *)D_88234850 + 0x12) = 303;
    D_880068B4 = 0;
    *(s32 *)((u8 *)D_88234850 + 0x30) = 1;
    *(s16 *)((u8 *)D_88234850 + 0x34) = 0;
    for (index = 0; index < 2; index = (index + 1) & 0xFF) {
        ((s8 *)(u32)D_88234850)[index + 0x36] = D_88234758[index + 7];
    }
    first_refresh_rate = func_80001FF0();
    func_88001C6C((u8 *)D_88234850 + 4, 17, 9, 209, 23, 12,
                 (s32)(540.0f / (f32)first_refresh_rate + (0.0f < (540.0f / func_80001FF0()) ? 0.5f : -0.5f)),
                 41, 41, 12, 70);
}
/* Retail carries three zero words after the epilogue (882243B4-882243BC);
 * fragment31_1965A0.o .text must stay 0x10A0 bytes so fragment31_197640.o
 * keeps starting at 0x882243C0 (same class as fragment31_1A43F0.c). */
#pragma C_FUNCTION_PADDING(12)
#endif
