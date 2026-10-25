#include "global.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_80087200;
extern s32 D_880068B8;

void func_88228D80(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

typedef struct {
    u8 unused[0x60];
    u8 selected;
    u8 padding[3];
    void (*callback)(void);
} Cleanup_88228DA8;
extern u32 D_882348A0;
extern s32 D_880068B4;
extern void func_88001900(void);
extern void Util_Free(s32);
void func_88228DA8(void) {
    Cleanup_88228DA8 *state = (Cleanup_88228DA8 *)D_882348A0;

    if (state->selected != 0) {
        state->callback();
    } else {
        Input_SetRepeatController(D_80087200);
        func_88001900();
        D_880068B4 = 1;
    }
    Util_Free((s32)D_882348A0);
}

void func_88228E14(void) {
    void *state;

    state = (u8 *)D_882348A0 + 0x20;
    if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
        func_800226C0(72);
        func_88004990(**(u8 **)D_882348A0, 0);
        D_880068B8 = 1;
        *((u8 *)D_882348A0 + 0x60) = 0;
    } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
        func_88004990(**(u8 **)D_882348A0, 0);
        D_880068B8 = 1;
        *((u8 *)D_882348A0 + 0x60) = 2 - *(s16 *)((u8 *)state + 0x28);
        if (*(s16 *)((u8 *)state + 0x28) == 1) {
            func_800226C0(302);
        } else {
            func_800226C0(72);
        }
    } else {
        func_88002720((u8 *)state + 0x28, *(u16 *)((u8 *)state + 0xC), (u8 *)state + 0x2C);
    }
}

extern u32 D_882348A0;
extern void func_8821D930(s32);
void func_88228F08(void) {
    func_8821D930((D_882348A0 + 4));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_19C000/func_88228F30.s")
#endif
