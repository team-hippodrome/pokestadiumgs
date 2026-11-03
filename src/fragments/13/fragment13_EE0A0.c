#include "global.h"


#ifdef VERSION_US
struct S1_Vec3f {
    f32 x;
    f32 y;
    f32 z;
};
struct S1_Vec3s {
    s16 x;
    s16 y;
    s16 z;
};
struct S1_MainPoolState;
struct S1_unk_D_86002F58_004_000;
extern struct S1_unk_D_86002F58_004_000 *func_80038894(struct S1_MainPoolState *, void *, s16, struct S1_Vec3f *, struct S1_Vec3s *, struct S1_Vec3f *);
extern struct S1_Vec3f D_82407350;
extern struct S1_Vec3s D_8240735C;
extern struct S1_Vec3f D_82407364;
void func_82400020(u8 *arg0) {
    s32 i;
    struct S1_Vec3f position;
    struct S1_Vec3s rotation;
    struct S1_Vec3f scale;

    position = D_82407350;
    rotation = D_8240735C;
    scale = D_82407364;
    for (i = 0; i < 8; i++) {
        func_80038894(NULL, arg0 + i * 0x168, -1, &position, &rotation, &scale);
    }
    *(s32 *)(arg0 + 0xCA8) = 0;
}

extern void func_8003F018(s32);
void func_82400108(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0;
    do {
        func_8003F018(var_s1);
        var_s0 += 0x168;
        var_s1 += 0x168;
    } while (var_s0 != 0xB40);
}

extern void func_8003F114(u8 *, s32, s32, s32);
void func_82400154(u8 *arg0, s32 arg1, void *arg2, f32 arg3, s32 arg4, s16 arg5) {
    struct Vec3 { f32 x; f32 y; f32 z; };
    struct Transform { u8 pad[0x24]; f32 v[6]; };
    struct Vec3 *src = (struct Vec3 *)arg2;
    struct Transform *dst = (struct Transform *)arg0;
    func_8003F114(arg0, arg5, -1, arg1);
    dst->v[0] = src->x;
    dst->v[1] = src->y;
    dst->v[2] = src->z;
    dst->v[3] = arg3;
    dst->v[4] = arg3;
    dst->v[5] = arg3;
}

/* mkdraft:func_824001C0 begin */
extern u8 D_82407370[];
extern u8 D_82408BC0[];
extern s32 func_80071ADC(s32 arg0, s32 arg1);

typedef struct { s32 a, b, c; } Unk12;
typedef struct { s16 a, b, c, d, e, f; } Rec12;



void func_824001C0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    /* Declaration order is load-bearing: IDO 7.1 stores the 12-byte struct copy at
       sp+0x70 (target) when `scale` precedes `local` here, and at sp+0x74 when
       `local` is the first declaration. Both frames are -0x80. */
    f32 scale;
    Unk12 local;
    s32 i;
    s32 cond;
    s32 ret;
    s32 val;
    s32 ca8;
    s32 *p;

    local = *(Unk12 *)D_82408BC0;

    for (i = 0; i < 8; i++) {
        func_8003F1DC(arg0 + i * 0x168);
    }
    ca8 = *(u8 **)(arg0 + 0xCA8);
    if (ca8 != 0) {
        func_8003F1DC(ca8);
    }

    scale = 1.0f;
    p = (s32 *)(arg1 + 0x1C);
    for (i = 7; i >= 0; i--) {
        val = *p;
        cond = (val >= 0);
        if (cond) {
            cond = (val < *(u16 *)(D_82407370 + i * 0x3C + 0x3A));
        }
        if (cond) {
            ret = func_80071ADC(arg5, ((Rec12 *)*(u32 *)(D_82407370 + i * 0x3C + 0x34))[p[0]].a);
        } else {
            ret = func_80071ADC(arg5, 1);
        }
        if (*(u8 **)(arg0 + 0xCA8) && arg2 == i) {
            if (cond) {
                if (arg3 != 0 || arg4 == 0) {
                    func_82400154((u8 *)((s32)arg0 + i * 0x168), ret, D_82407370 + i * 0x3C, scale, 1, 0);
                } else {
                    func_82400154(*(u8 **)(arg0 + 0xCA8), ret, D_82407370 + i * 0x3C, scale, 0, 1);
                    *(s16 *)(*(u8 **)(arg0 + 0xCA8) + 0x20) = 0;
                }
            } else if (arg4) {
                func_82400154(*(u8 **)(arg0 + 0xCA8), ret, D_82407370 + i * 0x3C + 0xC,
                              *(f32 *)(D_82407370 + i * 0x3C + 0x18), 0, 1);
                *(s16 *)(*(u8 **)(arg0 + 0xCA8) + 0x20) = *(u16 *)(arg0 + 0xCAC);
            }
        } else if (cond) {
            func_82400154((u8 *)((s32)arg0 + i * 0x168), ret, D_82407370 + i * 0x3C, scale, 1, 0);
        }
        p--;
    }
}
/* mkdraft:func_824001C0 end */

extern f32 func_82403F10(void);
extern f32 D_82408BD8;
void func_82400438(u8 *arg0) {
    *(u16 *)(arg0 + 0xCAC) += func_82403F10() * D_82408BD8 / 48.0f;
}

void *func_82400520(void *arg0, void *arg1) {
    void *target = *(void **)((u8 *)arg1 + 0x14);
    if (arg0) { }
    *(void **)((u8 *)target + 0xCA8) = arg1;
    return target;
  }
#endif
