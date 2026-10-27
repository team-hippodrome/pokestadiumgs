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

s32 func_8004C874(s32, s32);
s32 func_88002AA8(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, void *);
s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern s32 D_88233900;
extern unsigned char D_8800ED50;
void func_88228D80(void);
void func_88228DA8(void);
void func_88228E14(void);

// Same code as fragment31_19BCA0's func_88228BCC on a 0x68-byte state at D_882348A0;
// GS loads three menu strings (39, 4-6) instead of two, passes func_88002AA8 a
// {1, &D_88233900} pair instead of D_88006020, and keeps arg2 at 0x64.
//@src/fragments/31/fragment31_19BCA0.c
void func_88228F30(s16 arg0, s16 arg1, s32 arg2)
{
  u8 i;
  struct { s32 count; s32 *data; } options;

  D_882348A0 = Util_Malloc(0x68);
  for (i = 0; i < 3; i++) {
    ((s32 *) (((u8 *) D_882348A0) + 0x54))[i] = func_8004C874(0x27, i + 4);
  }
  options.count = 1;
  options.data = &D_88233900;
  func_88002AA8(D_882348A0 + 0x20, 0, D_882348A0 + 0x54, 3, 8, 1, 6, 0, 0, 0, 0, 0, 1, &options);
  *((s32 *) (((u8 *) D_882348A0) + 0xC)) = func_8004C874(0x27, 2);
  *((s32 *) (((u8 *) D_882348A0) + 8)) = 0;
  *((s32 *) (((u8 *) D_882348A0) + 0x10)) = 4;
  *((s16 *) (((u8 *) D_882348A0) + 0x14)) = 1;
  *((s16 *) (((u8 *) D_882348A0) + 0x16)) = 4;
  *((void **) (((u8 *) D_882348A0) + 0)) = (void *) ((func_88004804(D_882348A0 + 4, 2, arg0, arg1, 4, 1, 0xDC, 0xDC, 0xB4, &func_88228E14, &func_88228F08, &func_88228D80, &func_88228DA8, 0, 0) * 0x4C) + (&D_8800ED50));
  D_880068B4 = 0;
  *((s32 *) (((u8 *) D_882348A0) + 0x64)) = arg2;
}
#endif
