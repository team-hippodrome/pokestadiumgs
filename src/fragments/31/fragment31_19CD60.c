#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_88229AE0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(s32);
extern s32 D_880068B4;
extern u32 D_882348C0;
void func_88229B08(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = 1;
    Util_Free(D_882348C0);
}

extern void func_800226C0(s32);
extern void func_88004990(u8, u8);
extern void func_8821C2F4(void);
extern void func_8821B980(u16, s32);
extern s32 func_8821C0B0(void);
extern void func_8800225C(void *, s16, s16);
extern void func_88002720(s16 *, u16, void *);
extern s32 D_8823476C;
extern u8 D_88006880[];

void func_88229B44(void) {
    u8 *menu;
    u32 buttons;

    buttons = D_80087200->buttonsPressed;
    menu = (u8 *)(D_882348C0 + 32);
    if (buttons & 0x4000) {
        func_800226C0(72);
        func_88004990(**(u8 **)D_882348C0, 0);
        D_880068B8 = 1;
    } else if (buttons & 0x8000) {
        func_8821C2F4();
        switch (*(s16 *)(menu + 40)) {
        case 0:
        case 1:
        case 2:
            func_800226C0(92);
            D_8823476C = *(s16 *)(menu + 40);
            func_8821B980(0x200, 1);
            break;
        case 3:
            func_800226C0(311);
            func_8821B980(0x200, 0);
            break;
        }
        func_8821C0B0();
        func_8800225C(D_88006880, 0, 0);
        func_88004990(**(u8 **)D_882348C0, 0);
        D_880068B8 = 1;
    } else {
        func_88002720((s16 *)(menu + 40), *(u16 *)(menu + 12), menu + 44);
    }
}

extern void func_8821D930(s32);
void func_88229C88(void) {
    func_8821D930((D_882348C0 + 4));
}

extern void *Util_Malloc(s32);
extern s32 func_8004C874(s32, s32);
extern s32 func_88002AA8(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, void *);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern s32 func_8821B924(u8);
extern u8 D_8800ED50[];
extern s32 D_880068B4;
extern u32 D_882348C0;
void func_88229AE0(void);
void func_88229B08(void);
void func_88229B44(void);
void func_88229C88(void);

/* Menu state at D_882348C0: four label ids at 0x54, the menu at 0x20, and the
 * three-entry selection mask at 0x64 that func_88002AA8 receives as its {1, data}
 * option pair. func_8821B924(i) is 1 when selection i equals the value held in
 * D_88234758; 0x67 is set when no selection matches.
 *@src/fragments/31/fragment31_19C000.c
 *@src/fragments/31/fragment31_189760.c
 */


void func_88229CB0(void) {
    u32 i;
    s32 index;
    struct { s32 count; u8 *data; } options;

    D_882348C0 = (u32)Util_Malloc(0x68);
    for (i = 0; i < 4U; i++) {
        ((s32 *)((u8 *)D_882348C0 + 0x54))[i] = func_8004C874(0x25, i + 0x3B);
    }
    for (i = 0; i < 3; i++) {
        ((u8 *)D_882348C0)[i + 0x64] = func_8821B924((u8)i) ? 1 : 0;
    }
    if (((u8 *)D_882348C0)[0x64] + ((u8 *)D_882348C0)[0x65] + ((u8 *)D_882348C0)[0x66] == 0) {
        ((u8 *)D_882348C0)[0x67] = 1;
    } else {
        ((u8 *)D_882348C0)[0x67] = 0;
    }
    options.count = 1;
    options.data = (u8 *)D_882348C0 + 0x64;
    func_88002AA8((u8 *)D_882348C0 + 0x20, 0, (u8 *)D_882348C0 + 0x54, 4, 8, 1, 6, 0, 0, 0, 0, 0, 0, &options);
    *(s32 *)((u8 *)D_882348C0 + 0xC) = func_8004C874(0x25, 0x3A);
    *(s32 *)((u8 *)D_882348C0 + 8) = 0;
    *(s32 *)((u8 *)D_882348C0 + 0x10) = 4;
    *(s16 *)((u8 *)D_882348C0 + 0x14) = 1;
    *(s16 *)((u8 *)D_882348C0 + 0x16) = 4;
    index = func_88004804((u8 *)D_882348C0 + 4, 2, 0x4E, 0x93, 0, 1, 0xDC, 0xDC, 0xB4, (s32 *)func_88229B44, (s32 *)func_88229C88, (s32 *)func_88229AE0, (s32 *)func_88229B08, 2, 0);
    *(void **)((u8 *)D_882348C0) = (void *)(index * 0x4C + (s32)D_8800ED50);
    D_880068B4 = 0;
}
#endif
