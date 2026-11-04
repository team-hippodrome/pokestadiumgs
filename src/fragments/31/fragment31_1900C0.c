#include "global.h"


#ifdef VERSION_US

typedef struct { u16 unknown_00; u16 flags; u32 unknown_04[3]; } Quad8821CE40;
typedef struct { s32 a, b, c, d; } Word4_88234588;

extern s32 func_80055948(s32);
extern s32 func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004C4B0(s32);
extern s32 func_8004C874(s32, s32);
extern s32 func_800476A0(s32 *, s32);
extern s32 func_800476FC(s32 *, s32);
extern s32 func_80047738(s32, s32, s32, s32);
extern void func_8005487C(Quad8821CE40 *);
extern s32 func_80041C98(s32);
extern void func_882041E0(void);
extern void func_882041F0(void);
extern void func_88004014(void);
extern void func_88200020(s32);
extern s32 main_pool_push_state(s32);
extern s32 func_8800005C(void);
extern s32 func_8005ED78(s8);
extern void *ModelPreview_Create(void *, s32, s32);
extern s32 func_80042D54(u8 *, s32);
extern s32 func_80042FBC(void *, s32);
extern void func_800371B4(s32, s32, s32, s32, s32);
extern s32 func_8003F2C4(void *, s32, s32);

extern s32 D_88234560;
extern s32 D_88234568;
extern s32 D_8823457C;
extern s32 D_88234580;
extern Word4_88234588 D_88234588;
extern s32 D_882345C8;
extern u8 D_882345D4;
extern u8 *D_882347E0;
extern void *D_80128C64;
extern s32 D_8800ECC0;
extern s32 D_8800ECC4;
extern s32 D_8800ECC8;
extern s32 D_8800ECCC;
extern s32 D_8800ECD0;
extern s32 D_8800ECD4;
extern s32 D_8800ECD8;
extern s32 D_8800ECDC;
extern s32 D_8800ECE0;
extern s32 D_8800ECE4;
extern s32 D_8800ECE8;
extern s32 D_8800ECEC;
extern s32 D_8800ECF0;
extern s32 D_8800ECF4;
extern s32 D_8800ECF8;
extern s32 D_8800ECFC;
extern s32 D_8800ED00;
extern s32 D_8800ED04;
extern s32 D_8800ED08;
extern s8 D_88006868;



void func_8821CE40(s32 arg0) {
    u32 i;
    Quad8821CE40 sp3C;
    s32 tv;

    if (arg0 == 6) {
        D_88234560 = 5;
        i = 0;
        do {
            func_80055948(i + 1);
            i = i + 1;
        } while (i < 3U);

        func_8004C8C0(0xEF);
        func_8004C8C0(0x1B);
        func_8004C8C0(0x10);
        D_8800ECC0 = func_8004C990(0x10, 1);
        D_8800ECC8 = func_8004C990(0x10, 0);
        func_8004C8C0(0x11);
        D_8800ECC4 = func_8004C990(0x11, 0);
        func_8004C8C0(0x32);
        D_8800ECCC = func_8004C990(0x32, 0);
        D_8800ECD0 = func_8004C990(0x32, 1);
        func_8004C8C0(0x33);
        D_8800ECD4 = func_8004C990(0x33, 0);
        D_8800ECD8 = func_8004C990(0x33, 1);
        D_8800ECDC = func_8004C990(0x33, 2);
        D_8800ECE0 = func_8004C990(0x33, 6);
        D_8800ECE4 = func_8004C990(0x33, 3);
        D_8800ECE8 = func_8004C990(0x33, 4);
        D_8800ECEC = func_8004C990(0x33, 5);
        D_8800ECF0 = func_8004C990(0x33, 7);
        func_8004C8C0(0xBF);
        D_8800ECF4 = func_8004C990(0xBF, 5);
        D_8800ECF8 = func_8004C990(0xBF, 4);
        func_8004C8C0(0x125);
        D_8800ECFC = func_8004C990(0x125, 0);
        D_8800ED00 = func_8004C990(0x125, 2);
        D_8800ED04 = func_8004C990(0x125, 1);
        func_8004C8C0(0x38);
        D_882345C8 = func_8004C990(0x38, 0);
        func_8004C8C0(0x151);
        D_8823457C = func_8004C990(0x151, 1);
        D_88234580 = func_8004C990(0x151, 0);
        func_8004C8C0(0x37);
        func_800476A0(&D_8800ED08, 2);
        func_800476FC(&D_8800ED08, 2);
        func_8005487C(&sp3C);
        if (!(sp3C.flags & 0x100)) {
            func_8004C8C0(0x143);
            func_80047738(0, func_8004C990(0x143, 0), 0, 0);
        } else {
            func_80047738(0, func_8004C990(0x37, 1), 0, 0);
        }
        func_80047738(1, func_8004C990(0x37, 0), 0, 0);
        func_8004C4B0(0xD);
        func_8004C4B0(0x1F);
        func_8004C4B0(6);
        func_8004C4B0(0xC);
        func_8004C4B0(0x27);
        func_8004C4B0(8);
        func_8004C4B0(0xA);
        for (i = 0; i != 5; i++) {
            *(&D_88234568 + i) = func_8004C874(0x1F, i + 1);
        }

        D_80128C64 = (void *)func_80041C98(1);
        func_882041F0();
    } else {
        func_882041E0();
    }
    func_88004014();
    func_88200020(1);
    main_pool_push_state(0x50435345);
    func_8004C8C0(0xFB);
    D_88234588.a = func_8004C990(0xFB, 0);
    D_88234588.b = func_8004C990(0xFB, 1);
    D_88234588.c = func_8004C990(0xFB, 2);
    D_88234588.d = func_8004C990(0xFB, 3);
    if ((func_8800005C() != 0) || (func_8005ED78(D_88006868) >= 0x96)) {
        D_882345D4 = 1;
        D_882347E0 = ModelPreview_Create(D_80128C64, 0x64, 0x3C);
        *(u16 *)D_882347E0 &= 0xFFFB;
        *(u16 *)D_882347E0 &= 0xFFFD;
        func_80042D54(D_882347E0, 0);
        func_80042FBC(D_882347E0, 0xAC);
        tv = *(s32 *)(*(u8 **)(D_882347E0 + 0x18) + 0xC);
        func_800371B4(tv + 0xB4, tv + 0xA8, 0x449C4000, 0x71C, 0);
        func_8003F2C4(D_80128C64, *(s32 *)(D_882347E0 + 0x1C), 7);
        return;
    }
    D_882345D4 = 0;
}

extern Gfx *D_800D0510;
extern Gfx D_80094E00[];
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern u8 D_882345D4;
extern s32 D_882347E4;
extern s32 func_88205D7C(void);
void func_8821D308(void) {
    if (func_88205D7C()) {
        func_80006F70(&D_800D0510, 50, 68, 590, 349);
    }
    func_882001E8();
    if (func_88205D7C()) {
        func_80006F70(&D_800D0510, 0, 0, 640, 480);
    }
    func_882052F8();
    if (D_882345D4 != 0 && func_88205D7C()) {
        gSPDisplayList(D_800D0510++, D_80094E00);
        func_880015F4(50, 355, 100, 60, D_882347E4, 0, 2, 0);
    }
}

extern u8 *D_882347E0;
extern u8 *D_88234564;
extern s32 D_88234560;
extern s8 D_8800EF18;
extern s32 ModelAnim_IsFinished(void *);
extern void ModelAnim_SetFrame(u8 *, s16);
extern f32 func_8004B888(s32);
extern s32 func_80043678(void *);
extern void func_800088DC(void);
extern void func_8821811C(void);
extern void func_8820B6C8(void);
extern void func_88212EA0(void);
extern void func_8820FDF8(void);
extern void func_882160F8(void);
extern void func_88004180(void);
extern void func_80008648(void);
extern s32 func_88205D7C(void);
extern void func_8821D308(void);
extern u8 D_882345D4;
extern s32 D_882347E4;
void func_8821D3FC(void) {
    u8 *anim;

    if (D_882345D4 != 0 && D_88234560 == 5 && func_88205D7C() != 0) {
        anim = *(u8 **)(D_882347E0 + 0x1C);
        if (ModelAnim_IsFinished(anim) != 0) {
            ModelAnim_SetFrame(anim, 0);
        }
        *(f32 *)(D_882347E0 + 0x10) = func_8004B888(0xAC) * (f32)*(s8 *)(D_88234564 + 0x20) / (f32)D_8800EF18;
        D_882347E4 = func_80043678(D_882347E0);
    }
    func_800088DC();
    switch (D_88234560) {
    case 5:
    case 6:
        func_8821D308();
        break;
    case 0:
        func_8821811C();
        break;
    case 1:
        func_8820B6C8();
        break;
    case 2:
        func_88212EA0();
        break;
    case 3:
        func_8820FDF8();
        break;
    case 4:
        func_882160F8();
        break;
    }
    func_88004180();
    func_80008648();
}

/* mkdraft:func_8821D550 begin */
extern s32 func_80001FF0(void);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_8821D3FC(void);

void func_8821D550(void) {
    u32 count;
    s32 i;
    count = (u16)((f32)func_80001FF0() * 0.3f / 2);
    StageFade_StartFromOpaque(count);
    if (count != 0) {
        i = 0;
        do {
            func_80064D28();
            func_8821D3FC();
            i++;
        } while (i != count);
    }
}
/* mkdraft:func_8821D550 end */

extern s32 D_88234560;
extern s8 D_8800EF40;
extern void func_80064D28(void);
extern void func_88204400(void);
extern void func_88217040(void);
extern void func_88209278(void);
extern void func_88211550(void);
extern void func_8820CF8C(void);
extern void func_882143EC(void);
extern void func_880040D4(void);
void func_8821D3FC(void);
void func_8821D64C(void) {
    while (D_88234560 != 6) {
        if (D_8800EF40 == -1) {
            func_80064D28();
        }
        switch (D_88234560) {
        case 5:
            func_88204400();
            break;
        case 0:
            func_88217040();
            break;
        case 1:
            func_88209278();
            break;
        case 2:
            func_88211550();
            break;
        case 3:
            func_8820CF8C();
            break;
        case 4:
            func_882143EC();
            break;
        }
        func_880040D4();
        func_8821D3FC();
    }
}

/* mkdraft:func_8821D74C begin */
extern s32 func_80001FF0(void);
extern void StageFade_StartFromTransparent(s32);
extern void func_80064D28(void);
extern void func_8821D3FC(void);

void func_8821D74C(void) {
    u32 count;
    s32 i;
    count = (u16)((f32)func_80001FF0() * 0.3f / 2);
    StageFade_StartFromTransparent(count);
    if (count != 0) {
        i = 0;
        do {
            func_80064D28();
            func_8821D3FC();
            i++;
        } while (i != count);
    }
}
/* mkdraft:func_8821D74C end */

#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

M2C_UNK Font_EnableLineBreak();                     /* extern */
M2C_UNK Gfx_FreeDisplayListBuffers();               /* extern */
M2C_UNK Gfx_InitDisplayListBuffers(M2C_UNK, M2C_UNK); /* extern */
s32 func_800082E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80008514(s32);                         /* extern */
M2C_UNK func_80008574();                            /* extern */
s32 func_80047588(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80047610();                            /* extern */
M2C_UNK func_8004C09C(M2C_UNK);                     /* extern */
M2C_UNK func_8004C398();                            /* extern */
void func_8821CE40(s32 arg0);                     /* extern */
M2C_UNK main_pool_pop_state(M2C_UNK);               /* extern */
M2C_UNK main_pool_push_state(M2C_UNK);              /* extern */
extern s32 D_8800687C;

s32 func_8821D848(s32 arg0, M2C_UNK arg1) {
    s32 sp24;

    main_pool_push_state(0x50435445);
    Gfx_InitDisplayListBuffers(0x1A000, 0);
    sp24 = func_800082E0(1, 0, 2, 0, 2, 1);
    func_8004C09C(0xB);
    D_8800687C = func_80047588(0x1C, 0);
    Font_EnableLineBreak();
    func_8821CE40(6);
    func_80008514(sp24);
    func_8821D550();
    func_8821D64C();
    func_8821D74C();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x50435445);
    return 7;
}
#endif
