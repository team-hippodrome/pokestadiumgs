#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern s32 D_880068B8;
void func_8822AD40(void) {
    D_880068B8 = 0;
}

extern void func_88220AD0(s32, s32);
extern s32 D_88234660;
void Input_SetRepeatController(s32 value);
extern void func_88001900();
extern s32 D_880068B4;
extern void Util_Free(s32);
extern u32 D_882348F0;
void func_8822AD4C(void) {
    if (D_88234660 != 0) {
        func_88220AD0(0x17C, 0x11F);
    } else {
        Input_SetRepeatController((s32)D_80087200);
        func_88001900();
        D_880068B4 = 1;
    }
    Util_Free((s32) D_882348F0);
}

extern void func_88004990(u8, u8);
void func_8822ADB0(void) {
    if (D_80087200->buttonsPressed & 0xC000) {
        func_88004990(**(u8 **)D_882348F0, 0);
        D_880068B8 = 1;
    }
}

extern void func_889033A0(s32);
void func_8822AE04(void) {
    func_889033A0((D_882348F0 + 4));
}

// RGB text colors; the format strings push them as <COL1,PUSH,r,g,b,255>.
typedef struct { u8 r, g, b; } unk_D_88233700;
extern unk_D_88233700 D_88233700[];
char *func_8822AE2C(char *arg0, u8 arg1, u8 arg2) {
    unk_D_88233700 *color = &D_88233700[arg1];

    if (arg1 == 0) {
        sprintf(arg0, "<COL1,PUSH,%d,%d,%d,255>%s<COL1,POP>", color->r, color->g, color->b, func_8004C874(37, 9));
    } else {
        sprintf(arg0, "<COL1,PUSH,%d,%d,%d,255>%s %d<COL1,POP>", color->r, color->g, color->b, func_8004C874(37, arg1 + 9), arg2 + 1);
    }
    return arg0;
}

extern u8 D_88006020[];
extern s32 D_8800EF54;
extern u32 D_882348F0;
extern s32 D_882345F4;
extern u8 D_8823475C;
extern s32 D_8823476C;
extern u16 D_882347BC;
extern s32 D_880068B4;
extern volatile unsigned char D_8800ED50;
extern void *func_8004B7A4(s32 arg0);
extern s32 func_8004C594(s32 index, s32 value);
extern s32 func_88002AA8();
s32 func_8004C54C(s32, s32);
s32 func_8004C8A0(void *, s32, s32, s32);
s32 func_88004804(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern char *func_8822AE2C(char *, u8, u8);



void func_8822AF00(s32 arg0) {
    s32 pad; // FAKE: unused local, only forces retail's frame (0x160) so result lands at 0x158
    s32 result;
    u8 buf1[0x80];
    u8 buf2[0x80];

    if (D_882347BC != 0) {
        D_882348F0 = (u32)Util_Malloc(0x23C);
        func_8004C54C(0x1A, arg0);
        switch (D_882347BC) {
        case 0x800:
            func_8004C54C(0x25, (s32)func_8822AE2C((char *)buf1, ((u8 *)D_8800EF54)[0], ((u8 *)D_8800EF54)[1]));
            func_8004C54C(0x28, (s32)func_8822AE2C((char *)buf2,
                                                      *(u8 *)(*(s32 *)*(s32 *)D_882345F4 + 8),
                                                      *(u8 *)(*(s32 *)D_882345F4 + 4)));
            result = 0x76;
            break;
        case 1:
            func_8004C594(2, ((u8 *)D_882345F4)[0x25] - 1);
            func_8004C594(3, ((u8 *)D_882345F4)[0x25]);
            result = 0x77;
            break;
        case 2:
            result = 0x78;
            break;
        case 4:
        case 8:
            result = 0x79;
            break;
        case 0x10:
            func_8004C54C(0x1B, (s32)func_8004B7A4(((u8 *)D_882345F4)[8]));
            func_8004C54C(0x1C, (s32)func_8004B7A4(D_8823475C));
            result = 0x7A;
            break;
        case 0x20:
            result = 0x7B;
            break;
        case 0x200:
            switch (D_8823476C) {
            case 0:
                result = 0x7C;
                break;
            case 1:
                result = ((u8 *)D_882345F4)[8] >= 0x98 ? 0x7D : 0x7E;
                break;
            case 2:
                result = 0x7F;
                break;
            }
            break;
        case 0x400:
            result = 0x80;
            break;
        default:
            result = 0x81;
            break;
        }
        *(s32 *)(D_882348F0 + 0x38) = func_8004C8A0((void *)(D_882348F0 + 0x3C), 0x200, 0x25, result);
        func_88002AA8((void *)(D_882348F0 + 4), 0, (void *)(D_882348F0 + 0x38), 1, 8, 1, 6, 0xF, 0x12, 0xD, 0x10, 0, 0, &D_88006020);
        *((void **)((u8 *)D_882348F0)) = (void *)((func_88004804((s32)(D_882348F0 + 4), 0, 0x17C, 0x11F, 4, 1, 0xFF, 0xAA, 0x8C, &func_8822ADB0, &func_8822AE04, &func_8822AD40, &func_8822AD4C, 0, 0) * 0x4C) + (&D_8800ED50));
        D_880068B4 = 0;
        D_882347BC = 0;
    }
}

void func_8822B240(void) {
    D_880068B8 = 0;
}

extern s32 D_88234900;

void func_8822B24C(void) {
    func_88001900();
    D_880068B4 = 1;
    Util_Free(D_88234900);
}

void func_8822B284(void) {
    if (D_80087200->buttonsPressed & 0xC000) {
        func_88004990(**(u8 **)D_88234900, 0);
        D_880068B8 = 1;
    }
}

/* mkdraft:func_8822B2D8 begin */
extern Gfx *D_800D0510;
extern Gfx D_80094DE0[];
extern u8 *D_8800687C;
extern char D_882344F0[];
extern void func_880008B0(s16, s16, s16);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
// FAKE: int return, not the callee's real void *. func_8822AE2C calls
// func_8004C874 before any declaration, creating an implicit int() prototype in
// this file; a pointer-returning declaration here conflicts with it. Only the
// value is forwarded to func_80048E30, so the return type does not affect
// codegen. Without this line the build fails on "conflicting types".
extern int func_8004C874(s32, s32);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
extern void func_80049668(s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_8004989C(s32);
extern void func_80047634(s32);
extern void func_80049064(s32, s32, s32, s32);
extern void func_80047650(s32);

// Storage entry at D_88234900+4: byte 0x66 is the entry's name, halfword 0x72 its
// value. Header + first two rows are drawn unconditionally; the name value row,
// the count row and the textured panel only when the entry has a name.


void func_8822B2D8(void) {
    gSPDisplayList(D_800D0510++, D_80094DE0);
    func_880008B0(210, 257, 332);
    func_800498C4();
    func_800496A4(4, 1);
    func_80048E30(D_8800687C, 210, 235, (const char *)(D_88234900 + 8), 1);
    if (*(s8 *)(*(u8 **)(D_88234900 + 4) + 0x66) != 0) {
        func_80048E30(D_8800687C, 280, 321,
                      (const char *)(*(u8 **)(D_88234900 + 4) + 0x66), 1);
        func_80048E30(D_8800687C, 365, 321, (const char *)func_8004C874(13, 9), 1);
        func_80049668(0);
        func_800495F8(400, 321, 0, D_882344F0,
                      *(u16 *)(*(u8 **)(D_88234900 + 4) + 0x72));
        func_800496A4(8, 1);
        func_8004989C(26);
        func_80047634(1);
        func_80049064(376, 267, 1, (s32)*(u8 **)(D_88234900 + 4));
        func_80047650(1);
    }
}
/* mkdraft:func_8822B2D8 end */

void func_8822B240(void);
void func_8822B24C(void);
void func_8822B284(void);
s32 func_8004C54C(s32, s32);
s32 func_8004C8A0(void *, s32, s32, s32);
s32 func_800635E0(u8);
s32 func_88004804(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
s32 func_8820137C(s32);
extern volatile unsigned char D_8800ED50;
extern s32 D_882345F4;
void func_8822B240(void);
void func_8822B24C(void);
void func_8822B284(void);
void func_8822B2D8(void);

void func_8822B43C(u8 arg0)
{
  D_88234900 = Util_Malloc(0x48);
  *((s32 *) (((u8 *) D_88234900) + 4)) = func_8820137C(D_882345F4);
  func_8004C54C(0x18, func_800635E0(arg0));
  func_8004C8A0(D_88234900 + 8, 0x40, 0x25, 0x75);
  *((void **) (((u8 *) D_88234900) + 0)) = (void *) ((func_88004804(0, 3, 0xC7, 0xE0, 0, 1, 0xDC, 0xDC, 0xB4, &func_8822B284, &func_8822B2D8, &func_8822B240, &func_8822B24C, 2, 0) * 0x4C) + (&D_8800ED50));
  *((s16 *) (((u8 *) (*((void **) (((u8 *) D_88234900) + 0)))) + 0x10)) = 0x165;
  *((s16 *) (((u8 *) (*((void **) (((u8 *) D_88234900) + 0)))) + 0x12)) = 0x81;
  D_880068B4 = 0;
}
#endif
