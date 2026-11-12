#include "global.h"


#ifdef VERSION_US
typedef struct unk_func_86407290_1 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} unk_func_86407290_1;

typedef struct unk_func_86407290 {
    u8 unk_00[20];
    unk_func_86407290_1 unk_14;
    unk_func_86407290_1 unk_20;
    unk_func_86407290_1 unk_2C;
    unk_func_86407290_1 unk_38;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    s32 unk_5C;
    s32 unk_60;
    // Last frame applied by func_864073B0.
    u16 unk_64;
} unk_func_86407290;

extern void *D_86416C00;

void func_86407290(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6) {
    ((unk_func_86407290 *)D_86416C00)->unk_2C = ((unk_func_86407290 *)D_86416C00)->unk_14;
    ((unk_func_86407290 *)D_86416C00)->unk_38 = ((unk_func_86407290 *)D_86416C00)->unk_20;
    ((unk_func_86407290 *)D_86416C00)->unk_44 = arg0;
    ((unk_func_86407290 *)D_86416C00)->unk_48 = arg1;
    ((unk_func_86407290 *)D_86416C00)->unk_4C = arg2;
    ((unk_func_86407290 *)D_86416C00)->unk_50 = arg3;
    ((unk_func_86407290 *)D_86416C00)->unk_54 = arg4;
    ((unk_func_86407290 *)D_86416C00)->unk_58 = arg5;
    ((unk_func_86407290 *)D_86416C00)->unk_60 = arg6;
    ((unk_func_86407290 *)D_86416C00)->unk_5C = 0;
}

/* mkdraft:func_86407330 begin */
extern void *D_86416C00;
typedef struct { f32 x, y, z; } V3;
typedef struct {
    V3 cur0;
    V3 cur1;
    V3 from;
    V3 unk38;
    V3 to;
    V3 unk50;
    s32 f5C;
    s32 f60;
} POSE;



void func_86407330(f32 a, f32 b, f32 c, f32 d, f32 e, f32 g) {
    POSE *s = (POSE *)((u8 *)D_86416C00 + 0x14);
    s->cur0.x = a;
    s->cur0.y = b;
    s->cur0.z = c;
    s->cur1.x = d;
    s->cur1.y = e;
    s->cur1.z = g;
    s->from = s->cur0;
    s->to = s->cur0;
    s->f5C = 2;
    s->f60 = 1;
}
/* mkdraft:func_86407330 end */

extern f32 D_86409BC0;
extern f32 D_80088E50[];
extern u16 D_80094904;
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);

// Mode 2 advances once per frame; all modes apply the two camera triplets.
s32 func_864073B0(s32 arg0, void *arg1) {
    f32 angle;
    s32 rounded;
    f32 weight;
    f32 inverse;

    switch (arg0) {
        case 0:
            func_86407330(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -100.0f);
            break;
        case 2:
            if (((unk_func_86407290 *)D_86416C00)->unk_64 != D_80094904 &&
                ((unk_func_86407290 *)D_86416C00)->unk_5C < ((unk_func_86407290 *)D_86416C00)->unk_60) {
                ((unk_func_86407290 *)D_86416C00)->unk_5C++;
                angle = (((f32)((unk_func_86407290 *)D_86416C00)->unk_5C * 180.0f) / (f32)((unk_func_86407290 *)D_86416C00)->unk_60) * D_86409BC0;
                if (angle >= 0.0f) {
                    rounded = angle + 0.5f;
                } else {
                    rounded = angle - 0.5f;
                }
                weight = (1.0f - D_80088E50[(u16)rounded >> 4]) * 0.5f;
                inverse = 1.0f - weight;
                ((unk_func_86407290 *)D_86416C00)->unk_14.unk_00 = ((unk_func_86407290 *)D_86416C00)->unk_2C.unk_00 * inverse + ((unk_func_86407290 *)D_86416C00)->unk_44 * weight;
                ((unk_func_86407290 *)D_86416C00)->unk_14.unk_04 = ((unk_func_86407290 *)D_86416C00)->unk_2C.unk_04 * inverse + ((unk_func_86407290 *)D_86416C00)->unk_48 * weight;
                ((unk_func_86407290 *)D_86416C00)->unk_14.unk_08 = ((unk_func_86407290 *)D_86416C00)->unk_2C.unk_08 * inverse + ((unk_func_86407290 *)D_86416C00)->unk_4C * weight;
                ((unk_func_86407290 *)D_86416C00)->unk_20.unk_00 = ((unk_func_86407290 *)D_86416C00)->unk_38.unk_00 * inverse + ((unk_func_86407290 *)D_86416C00)->unk_50 * weight;
                ((unk_func_86407290 *)D_86416C00)->unk_20.unk_04 = ((unk_func_86407290 *)D_86416C00)->unk_38.unk_04 * inverse + ((unk_func_86407290 *)D_86416C00)->unk_54 * weight;
                ((unk_func_86407290 *)D_86416C00)->unk_20.unk_08 = ((unk_func_86407290 *)D_86416C00)->unk_38.unk_08 * inverse + ((unk_func_86407290 *)D_86416C00)->unk_58 * weight;
            }
            break;
    }
    func_80038E14(arg1,
        ((unk_func_86407290 *)D_86416C00)->unk_14.unk_00,
        ((unk_func_86407290 *)D_86416C00)->unk_14.unk_04,
        ((unk_func_86407290 *)D_86416C00)->unk_14.unk_08,
        ((unk_func_86407290 *)D_86416C00)->unk_20.unk_00,
        ((unk_func_86407290 *)D_86416C00)->unk_20.unk_04,
        ((unk_func_86407290 *)D_86416C00)->unk_20.unk_08, 0);
    ((unk_func_86407290 *)D_86416C00)->unk_64 = D_80094904;
    return 1;
}

/* mkdraft:func_86407610 begin */
extern u8 D_864097F0[];
extern u8 D_864097F4[];
extern u8 D_864097F8[];
extern u8 D_864097FC[];
extern u8 D_86409BD0[];
extern u8 D_86409BDC[];
extern u8 D_86409BE8[];
extern u8 D_86409BF4[];
extern u8 D_86409C00[];
extern u8 D_86409C0C[];
extern u8 D_86409C18[];
extern u8 D_86409C24[];
extern u8 D_86409C30[];
extern f32 D_86409C38;
extern s32 func_80001FF0(void);
extern void func_87F04314(s32, s32, s32, void *, s32, s32, s32, s32, s32, void *, void *, void *);
extern void func_87F0455C(void);



void func_86407610(void) {
    ((u8 *)D_86416C00)[0xC] &= 0xFF7F;
    *(f32 *)((u8 *)D_86416C00 + 0) = D_86409C38 / (f32)func_80001FF0();
    *(f32 *)((u8 *)D_86416C00 + 4) = 51.0f / (f32)func_80001FF0();
    *(s32 *)((u8 *)D_86416C00 + 8) = 9;
    func_87F0455C();
    func_87F04314(0, 0, 0, D_86409BD0, 12, 0, 10, 5, 3, (u8 *)D_86416C00 + 0x14, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 1, D_86409BDC, 12, 1, 10, 5, 3, (u8 *)D_86416C00 + 0x18, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 2, D_86409BE8, 12, 2, 10, 5, 3, (u8 *)D_86416C00 + 0x1C, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 3, D_86409BF4, 12, 3, 10, 5, 3, (u8 *)D_86416C00 + 0x20, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 4, D_86409C00, 12, 4, 10, 5, 3, (u8 *)D_86416C00 + 0x24, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 5, D_86409C0C, 12, 5, 10, 5, 3, (u8 *)D_86416C00 + 0x28, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 6, D_86409C18, 12, 6, 10, 5, 3, D_86416C00, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 7, D_86409C24, 12, 7, 10, 5, 3, (u8 *)D_86416C00 + 4, D_864097F0, D_864097F4);
    func_87F04314(0, 0, 8, D_86409C30, 12, 8, 6, 5, 0, (u8 *)D_86416C00 + 8, D_864097F8, D_864097FC);
}
/* mkdraft:func_86407610 end */

typedef struct unk_func_864079AC {
    u8 unk_00[0xC];
    u32 unk_0C_flag : 1;
} unk_func_864079AC;

extern void *D_80087208;
extern void func_87F04894(void);
void func_864079AC(void) {
    if (*(u16 *)((u8 *)D_80087208 + 8) & 0x10) {
        // karodo: both arms clear the same controller bit.
        if (((unk_func_864079AC *)D_86416C00)->unk_0C_flag ^= 1) {
            *(u16 *)((u8 *)D_80087208 + 0x10) &= 0xFFFE;
        } else {
            *(u16 *)((u8 *)D_80087208 + 0x10) &= 0xFFFE;
        }
    }
    if (((unk_func_864079AC *)D_86416C00)->unk_0C_flag) {
        func_87F04894();
    }
}

extern void func_87F05204(s32 *);
extern void func_87F09040();
extern u8 D_800D0510;
extern void *D_86416C00;
void func_86407A54(void) {
    if (((u32) (*(u32 *)((u8 *)(D_86416C00) + (0xC))) >> 0x1F) != 0) {
        func_87F05204(&D_800D0510);
        func_87F09040();
    }
}
#endif
