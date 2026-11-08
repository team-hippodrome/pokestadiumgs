#include "global.h"
#include "color_adjustment.h"


#ifdef VERSION_US
extern void func_80038E14(s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern void *func_87F025B8(void *, void *);
extern void func_87F0455C(void);
extern void func_87F04314(s32, s32, s32, void *, s32, s32, s32, s32, s32, void *, void *, void *);
extern u8 D_87F0FB6C;
extern u8 D_87F0FB70;
void func_87E156A0(void *arg0) {
    void *p0;
    void *p1;
    void *p2;
    void *p3;
    p0 = (u8 *)arg0 + 0x10C8;
    p1 = (u8 *)arg0 + 0x10CC;
    p2 = (u8 *)arg0 + 0x10D0;
    p3 = (u8 *)arg0 + 0x10D4;
    *(f32 *)p0 = -0.1f;
    *(f32 *)p1 = 0.9999f;
    *(f32 *)p2 = 0.7f;
    *(f32 *)p3 = 1.09f;
    func_87F0455C();
    func_87F04314(0, 0, 0, "GRAVITY", 12, 0, 10, 3, 3, p0, &D_87F0FB6C, &D_87F0FB70);
    func_87F04314(0, 0, 1, "VL DEC ", 12, 1, 10, 3, 7, p1, &D_87F0FB6C, &D_87F0FB70);
    func_87F04314(0, 0, 2, "SPRING ", 12, 2, 10, 3, 3, p2, &D_87F0FB6C, &D_87F0FB70);
    func_87F04314(0, 0, 3, "SHOT   ", 12, 3, 10, 3, 3, p3, &D_87F0FB6C, &D_87F0FB70);
}

void func_87E15874(f32 *arg0, f32 *arg1, f32 *arg2) {
    arg0[0] = arg1[0] * arg2[0] + arg1[1] * arg2[4] + arg1[2] * arg2[8] + arg2[12];
    arg0[1] = arg1[0] * arg2[1] + arg1[1] * arg2[5] + arg1[2] * arg2[9] + arg2[13];
    arg0[2] = arg1[0] * arg2[2] + arg1[1] * arg2[6] + arg1[2] * arg2[10] + arg2[14];
}

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
void func_87E15920(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCFC38);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60((u8 *)func_8004C990(
                       0x1B2, *(s32 *)(context + 0x3C) + 2)));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_v0 + 0x108));
        GeoRender_ApplyMaterialState();
    }
}
void func_87E15920_padding(void) {}

s32 process_geo_layout(s32, s32 *);
s32 func_8004C990(s32, s32);
s32 func_87F08E3C(s32, s32);
extern u8 D_87E1B310;
void func_87E15A08(void *arg0) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    (*(s32 *)((u8 *)(arg0) + (0x104))) = process_geo_layout(temp_v0, &D_87E1B310);
    MainPool_FinalizeAllocation(sp1C);
    (*(s32 *)((u8 *)(arg0) + (0x108))) = func_87F08E3C(func_8004C990(0x1B2, 6), 0x0F000000);
}

void func_87E15A78(void *arg0) {
    if (((*(f32 *)((u8 *)(arg0) + (0))) == 0.0f) && ((*(f32 *)((u8 *)(arg0) + (4))) == 0.0f) && ((*(f32 *)((u8 *)(arg0) + (8))) == 0.0f)) {
        (*(f32 *)((u8 *)(arg0) + (0))) = 1.0f;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_319010/func_87E15AD0.s")

void func_87E15E18(f32 *arg0, f32 *arg1, s32 *arg2, s32 arg3) {
    s32 i;
    f32 *p;

    arg0[0] = 0.0f;
    arg0[1] = 0.0f;
    arg0[2] = 0.0f;
    for (i = 0; i < arg3; ++i) {
        p = (f32 *)((u8 *)arg1 + arg2[i] * 0x18);
        arg0[0] += p[0];
        arg0[1] += p[1];
        arg0[2] += p[2];
    }
    arg0[0] /= arg3;
    arg0[1] /= arg3;
    arg0[2] /= arg3;
}

extern void func_87E15E18(f32 *, f32 *, s32 *, s32);
extern void func_80035A10(f32 *);
void func_87E1614C(f32 *arg0, f32 *arg1, s32 *arg2, s32 arg3, s32 *arg4, s32 arg5) {
    s32 pad;
    f32 first[3];
    f32 second[3];

    func_87E15E18(first, arg1, arg2, arg3);
    func_87E15E18(second, arg1, arg4, arg5);
    arg0[0] = second[0] - first[0];
    arg0[1] = second[1] - first[1];
    arg0[2] = second[2] - first[2];
    if ((arg0[0] != 0.0f) || (arg0[1] != 0.0f) || (arg0[2] != 0.0f)) {
        func_80035A10(arg0);
    }
}

extern void Vec3f_CrossProduct(f32 *, f32 *, f32 *);
extern void func_80035A10(f32 *);
void func_87E16200(f32 *arg0, f32 *arg1, f32 *arg2) {
    f32 v64[3];
    f32 v58[3];
    f32 v4C[3];
    f32 v40[3];
    f32 v34[3];
    f32 v28[3];
    Vec3f_CrossProduct(v40, arg2, arg0);
    func_80035A10(v40);
    Vec3f_CrossProduct(v28, arg0, arg1);
    func_80035A10(v28);
    Vec3f_CrossProduct(v58, arg1, arg2);
    func_80035A10(v58);
    Vec3f_CrossProduct(v34, arg0, arg1);
    func_80035A10(v34);
    Vec3f_CrossProduct(v64, arg1, arg2);
    func_80035A10(v64);
    Vec3f_CrossProduct(v4C, arg2, arg0);
    func_80035A10(v4C);
    arg0[0] += v58[0] + v64[0]; arg0[1] += v58[1] + v64[1]; arg0[2] += v58[2] + v64[2];
    arg0[0] /= 3.0f; arg0[1] /= 3.0f; arg0[2] /= 3.0f;
    func_80035A10(arg0);
    arg1[0] += v40[0] + v4C[0]; arg1[1] += v40[1] + v4C[1]; arg1[2] += v40[2] + v4C[2];
    arg1[0] /= 3.0f; arg1[1] /= 3.0f; arg1[2] /= 3.0f;
    func_80035A10(arg1);
    arg2[0] += v28[0] + v34[0]; arg2[1] += v28[1] + v34[1]; arg2[2] += v28[2] + v34[2];
    arg2[0] /= 3.0f; arg2[1] /= 3.0f; arg2[2] /= 3.0f;
    func_80035A10(arg2);
}

void func_87E1643C(void *arg0, void *arg1, void *arg2, void *arg3) {
    (*(f32 *)((u8 *)(arg0) + (0))) = (f32) (*(f32 *)((u8 *)(arg1) + (0)));
    (*(f32 *)((u8 *)(arg0) + (4))) = (f32) (*(f32 *)((u8 *)(arg1) + (4)));
    (*(f32 *)((u8 *)(arg0) + (8))) = (f32) (*(f32 *)((u8 *)(arg1) + (8)));
    (*(f32 *)((u8 *)(arg0) + (0x10))) = (f32) (*(f32 *)((u8 *)(arg2) + (0)));
    (*(f32 *)((u8 *)(arg0) + (0x14))) = (f32) (*(f32 *)((u8 *)(arg2) + (4)));
    (*(f32 *)((u8 *)(arg0) + (0x18))) = (f32) (*(f32 *)((u8 *)(arg2) + (8)));
    (*(f32 *)((u8 *)(arg0) + (0x20))) = (f32) (*(f32 *)((u8 *)(arg3) + (0)));
    (*(f32 *)((u8 *)(arg0) + (0x24))) = (f32) (*(f32 *)((u8 *)(arg3) + (4)));
    (*(f32 *)((u8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((u8 *)(arg3) + (8)));
}

extern void func_87E1614C(f32 *, f32 *, s32 *, s32, s32 *, s32);
extern s32 D_87E1B3A4[4];
extern s32 D_87E1B3B4[4];
extern s32 D_87E1B3C4[4];
extern s32 D_87E1B3D4[4];
extern s32 D_87E1B3E4[4];
extern s32 D_87E1B3F4[4];
void func_87E16488(void *arg0) {
    f32 *p;
    s32 i;
    f32 v4C[3];
    f32 v40[3];
    f32 v34[3];
    f32 count = 8.0f;

    *(f32 *)((u8 *)arg0 + 0x30) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x34) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x38) = 0.0f;
    p = (f32 *)((u8 *)arg0 + 0x40);
    for (i = 0; i < 8; i++) {
        *(f32 *)((u8 *)arg0 + 0x30) += p[0];
        *(f32 *)((u8 *)arg0 + 0x34) += p[1];
        *(f32 *)((u8 *)arg0 + 0x38) += p[2];
        p += 6;
    }
    *(f32 *)((u8 *)arg0 + 0x30) /= count;
    *(f32 *)((u8 *)arg0 + 0x34) /= count;
    *(f32 *)((u8 *)arg0 + 0x38) /= count;
    func_87E1614C(v4C, (f32 *)((u8 *)arg0 + 0x40), D_87E1B3A4, 4, D_87E1B3B4, 4);
    func_87E1614C(v40, (f32 *)((u8 *)arg0 + 0x40), D_87E1B3C4, 4, D_87E1B3D4, 4);
    func_87E1614C(v34, (f32 *)((u8 *)arg0 + 0x40), D_87E1B3E4, 4, D_87E1B3F4, 4);
    func_87E16200(v4C, v40, v34);
    func_87E1643C(arg0, v4C, v40, v34);
}

extern void func_87E15874(f32 *, f32 *, f32 *);
extern f32 D_87E1B344[8][3];


void func_87E16738(void *arg0) {
    f32 *p;
    s32 i;
    f32 vec[3];
    f32 d0, d1, d2;

    p = (f32 *)((u8 *)arg0 + 0x40);
    for (i = 0; i < 8; i++, p += 6) {
        p[3] *= *(f32 *)((u8 *)arg0 + 0xD84);
        p[4] *= *(f32 *)((u8 *)arg0 + 0xD84);
        p[5] *= *(f32 *)((u8 *)arg0 + 0xD84);
        p[4] += *(f32 *)((u8 *)arg0 + 0xD80);
        func_87E15874(vec, D_87E1B344[i], arg0);
        d0 = vec[0] - p[0];
        d1 = vec[1] - p[1];
        d2 = vec[2] - p[2];
        p[3] += d0 * *(f32 *)((u8 *)arg0 + 0xD88);
        p[4] += d1 * *(f32 *)((u8 *)arg0 + 0xD88);
        p[5] += d2 * *(f32 *)((u8 *)arg0 + 0xD88);
        p[0] = vec[0];
        p[1] = vec[1];
        p[2] = vec[2];
        p[0] += p[3];
        p[1] += p[4];
        p[2] += p[5];
    }
}

extern void *D_87E1EC88;
extern void func_87C037C0(void *, void *);
extern void func_87C03B60(void *, void *, void *);
extern void func_8002781C(u16, u8, void *);

// Bounces the 8 records at arg0+0x40 (6 floats each: position, then velocity) off y = 0, playing
// sound 0x8F01 when the rebound exceeds 5, and clamps x to -500..2700 and z to -1600..500 while
// the word at D_87E1EC88+4 is below 60.
void func_87E16894(void *arg0) {
    s32 i;
    f32 *p;
    // FAKE: the original reserves a 12-byte vector at sp+0x64, but only this one-float declaration
    // reproduces its 0x70 frame. func_87C03B60 writes all three floats, so the write runs into the
    // unused stack slots of p and i above it, as in the original. See the fragment63_319010 note.
    f32 pos;

    p = (f32 *)((u8 *)arg0 + 0x40);
    for (i = 0; i != 8; i++, p += 6) {
        if (p[1] < 0.0f) {
            p[1] = 0.0f;
            p[4] *= -1.2f;
            p[3] *= 0.3f;
            p[5] *= 0.3f;
            if (p[4] > 5.0f) {
                func_87C037C0((u8 *)D_87E1EC88 + 0x10D8, *(void **)(*(u8 **)((u8 *)D_87E1EC88 + 0xC) + 0xC));
                func_87C03B60((u8 *)D_87E1EC88 + 0x10D8, p, &pos);
                func_8002781C(0x8F01, ((u8 *)D_87E1EC88)[2], &pos);
            }
        }
        if (*(s32 *)((u8 *)D_87E1EC88 + 4) < 60) {
            if (p[0] < -500.0f) {
                p[0] = -500.0f;
                p[3] *= -0.4f;
            }
            if (p[0] > 2700.0f) {
                p[0] = 2700.0f;
                p[3] *= -0.4f;
            }
            if (p[2] < -1600.0f) {
                p[2] = -1600.0f;
                p[5] *= -0.4f;
            }
            if (p[2] > 500.0f) {
                p[2] = 500.0f;
                p[5] *= -0.4f;
            }
        }
    }
}

extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern void func_80035A10(f32 *);
extern void Vec3f_CrossProduct(f32 *, f32 *, f32 *);
extern void func_87E1643C(void *arg0, void *arg1, void *arg2, void *arg3);
void func_87E16AA4(void *arg0) {
    f32 v0[3];
    f32 v1[3];
    f32 v2[3];
    u8 pad[72];
    Vec3f_SetComponentsDuplicate(v0, *(f32 *)((u8 *)arg0 + 0), *(f32 *)((u8 *)arg0 + 4), *(f32 *)((u8 *)arg0 + 8));
    Vec3f_SetComponentsDuplicate(v1, *(f32 *)((u8 *)arg0 + 0x10), *(f32 *)((u8 *)arg0 + 0x14), *(f32 *)((u8 *)arg0 + 0x18));
    Vec3f_SetComponentsDuplicate(v2, *(f32 *)((u8 *)arg0 + 0x20), *(f32 *)((u8 *)arg0 + 0x24), *(f32 *)((u8 *)arg0 + 0x28));
    func_80035A10(v0);
    Vec3f_CrossProduct(v1, v2, v0);
    func_80035A10(v1);
    Vec3f_CrossProduct(v2, v0, v1);
    func_80035A10(v2);
    func_87E1643C(arg0, v0, v1, v2);
}

extern void func_87D00354(void *arg0, f32 *arg1);
extern void func_87E15874(f32 *arg0, f32 *arg1, f32 *arg2);
extern void *D_87E1EC88;
extern s32 D_87E1B404;
extern s32 D_87E1B3F4[4];
extern void func_87E16AA4(void *arg0);
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
// The file declares D_800CE060 as u8[] further down (line ~544), so a typed
// `extern ControllerState D_800CE060[4]` is a hard conflicting-types error at
// that later declaration. The array-pointer cast below keeps the declaration
// compatible while giving ugen the *array* subscript lowering (base web created
// before the index-scale multiply) that the retail object shows.
extern u8 D_800CE060[];

typedef struct {
    u8 pad0[6];
    u16 buttonsHeld;
    u8 pad1[0x10];
    f32 stickXNorm;
    f32 stickYNorm;
    u8 pad2[8];
} CtrlTemp;





void func_87E16B50(void *arg0) {
    f32 direction[3];
    // FAKE: no source object. The 56 bytes leave frame bytes 0x4C-0x8B unreferenced
    // as in the target and place direction at 0x8C with vec at 0x40.
    u8 pad[56];
    f32 *src;
    f32 *dst;
    f32 vec[3];
    CtrlTemp *ctrl;

    // Store through a different symbol label at the same address (D_87E1B3F4+0x10
    // == D_87E1B404): uopt shares a symbol address across references, and the
    // retail object has two folded lui/%lo references instead of a base register.
    *(s32 *)((u8 *)D_87E1B3F4 + 0x10) = D_87E1B404 + 1;
    if ((1 << (*(s8 *)((u8 *)D_87E1EC88 + 2))) & (*(u8 **)((u8 *)D_87E1EC88 + 8))[0x2182]) {
        // Array-pointer cast, not ((CtrlTemp *)D_800CE060)[i]: the array
        // subscript shares one base+index web with the two reads below and
        // emits lui a2 / addiu a2 / addu a0,a2,t3 / move v1,a0 as retail.
        ctrl = &(*(CtrlTemp (*)[4])D_800CE060)[(*(s8 *)((u8 *)D_87E1EC88 + 2))];
        if (ctrl->stickXNorm != 0.0f || ctrl->stickYNorm != 0.0f) {
            direction[0] = (*(CtrlTemp (*)[4])D_800CE060)[(*(s8 *)((u8 *)D_87E1EC88 + 2))].stickXNorm;
            direction[2] = -(*(CtrlTemp (*)[4])D_800CE060)[(*(s8 *)((u8 *)D_87E1EC88 + 2))].stickYNorm;
        } else {
            // (x > 0) rather than (x != 0) selects the slt-zero compare the target uses.
            direction[0] = (f32)(((ctrl->buttonsHeld & 0x100) > 0) - ((ctrl->buttonsHeld & 0x200) > 0)) * 64.0f;
            direction[2] = (f32)(((ctrl->buttonsHeld & 0x400) > 0) - ((ctrl->buttonsHeld & 0x800) > 0)) * 64.0f;
        }
        direction[1] = 0.0f;
        if (direction[0] != direction[1] * 0.0f || direction[1] != 0.0f || direction[2] != direction[1]) {
            direction[2] = 0.0f;
            direction[0] *= 0.0390625f;
            func_87D00354(arg0, direction);
        }
    }
    // Reached on both guard outcomes; the board writes and trail below are not guarded.
    direction[0] = 0.8f;
    // Integer 0 keeps this store off the guard's constant zero register: the target
    // materializes a fresh zero (mtc1 $zero,$ft1) at .L87E16CD0.
    direction[1] = 0;
    direction[2] = -3.2f;
    func_87D00354(arg0, direction);
    func_87E16AA4(arg0);
    *(f32 *)((u8 *)arg0 + 0x34) = 600.0f;
    // Integer 0 in both zero stores. Written as 0.0f they merge with the guard's
    // constant zero, which then occupies a callee-saved FP register and adds
    // sdc1/bump of the frame to 0xA0.
    *(f32 *)((u8 *)arg0 + 0x30) = 0;
    *(f32 *)((u8 *)arg0 + 0x38) = 0;
    *(f32 *)((u8 *)arg0 + 0x3C) = 1.0f;
    // dst before src: the target emits addiu $s0,$s4,0x40 ahead of the two symbol bases.
    dst = (f32 *)((u8 *)arg0 + 0x40);
    src = (f32 *)D_87E1B344; do {
        func_87E15874(vec, src, arg0);
        dst[3] = vec[0] - dst[0];
        dst[4] = vec[1] - dst[1];
        dst[5] = vec[2] - dst[2];
        Vec3f_SetComponentsDuplicate(dst, vec[0], vec[1], vec[2]);
        src += 3;
        dst += 6;
    } while (src != (f32 *)D_87E1B3A4);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_319010/func_87E16DC0.s")

extern void *D_87E1EC88;
extern s32 func_80001FF0(void);
void func_87E16B50(void *);
void func_87E16DC0(void *);
void func_87E16738(void *);
void func_87E16894(void *);
void func_87E16488(void *);
void func_87E16FC4(void *arg0) {
    s32 i;

    switch (((s8 *)D_87E1EC88)[1]) {
    case 1:
        for (i = 0; i < ((((60.0f / func_80001FF0() * 8.0f)) >= 0.0f) ? (s32)((60.0f / func_80001FF0() * 8.0f) + 0.5f) : (s32)((60.0f / func_80001FF0() * 8.0f) - 0.5f)); i++) {
            func_87E16B50(arg0);
        }
        break;
    case 2:
        *(s32 *)((u8 *)D_87E1EC88 + 4) = 0;
        func_87E16DC0(arg0);
        break;
    case 3:
        for (i = 0; i < ((((60.0f / func_80001FF0() * 20.0f)) >= 0.0f) ? (s32)((60.0f / func_80001FF0() * 20.0f) + 0.5f) : (s32)((60.0f / func_80001FF0() * 20.0f) - 0.5f)); i++) {
            func_87E16738(arg0);
            func_87E16894(arg0);
            func_87E16488(arg0);
        }
        break;
    case 4:
    case 5:
        break;
    }
}

s32 func_87E172F0(f32 arg0, f32 arg1, s32 arg2) {
    s32 result;
    result = 0;
    if (0.99f < arg1) {
        result = 1;
    } else if (arg1 < -0.99f) {
        result = -1;
    }
    return result;
}

extern s32 func_87E172F0(f32 arg0, f32 arg1, s32 arg2);
s32 func_87E1733C(u8 *arg0) {
    u8 pad[8];
    f32 value;
    s32 result = -1;

    value = func_87E172F0(*(f32 *)(arg0 + 0), *(f32 *)(arg0 + 4), *(s32 *)(arg0 + 8));
    if (value != 0.0f) {
        if (value == 1.0f) {
            result = 3;
        } else {
            result = 2;
        }
    } else {
        value = func_87E172F0(*(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x14), *(s32 *)(arg0 + 0x18));
        if (value != 0.0f) {
            if (value == 1.0f) {
                result = 0;
            } else {
                result = 5;
            }
        } else {
            value = func_87E172F0(*(f32 *)(arg0 + 0x20), *(f32 *)(arg0 + 0x24), *(s32 *)(arg0 + 0x28));
            if (value != 0.0f) {
                if (value == 1.0f) {
                    result = 1;
                } else {
                    result = 4;
                }
            }
        }
    }
    return result;
}

/* mkdraft:func_87E17484 begin */
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
f32 sqrtf(f32);



s32 func_87E17484(void *arg0) {
    f32 *p;
    s32 result;
    s32 i;
    f32 sum[3];

    result = 0;
    Vec3f_SetComponentsDuplicate(sum, 0.0f, 0.0f, 0.0f);
    p = (f32 *)((u8 *)arg0 + 0x40);
    for (i = 0; i < 8; i++) {
        sum[0] += p[3];
        sum[1] += p[4];
        sum[2] += p[5];
        p += 6;
    }
    sum[0] /= 8;
    sum[1] /= 8;
    sum[2] /= 8;
    *(f32 *)((u8 *)arg0 + 0x100) = sqrtf(sum[2] * sum[2] + (sum[1] * sum[1] + sum[0] * sum[0]));
    if (*(f32 *)((u8 *)arg0 + 0x100) < 0.025f && -0.025f < *(f32 *)((u8 *)arg0 + 0x100)) {
        result = 1;
    }
    return result;
}
/* mkdraft:func_87E17484 end */

extern void *D_87E1EC88;
s32 func_87E176A0(s32 arg0, s32 arg1) {
    func_80038E14(arg1, (*(s32 *)((u8 *)(D_87E1EC88) + (0x1158))), (*(s32 *)((u8 *)(D_87E1EC88) + (0x115C))), (*(s32 *)((u8 *)(D_87E1EC88) + (0x1160))), (*(f32 *)((u8 *)(D_87E1EC88) + (0x1164))), (*(f32 *)((u8 *)(D_87E1EC88) + (0x1168))), (*(f32 *)((u8 *)(D_87E1EC88) + (0x116C))), 0);
    return 1;
}

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
void func_87E176FC(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCFC38);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60((u8 *)func_8004C990(0x1B2, 6)));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_v0 + 0x18));
        GeoRender_ApplyMaterialState();
    }
}
void func_87E176FC_padding(void) {}

extern u8 *D_87F119DC;
extern void func_87C037C0(void *, void *);
extern void func_87C03B60(void *, void *, void *);
extern void func_8002781C(u16, u8, void *);
extern void MtxF_Copy(void *, void *);
extern void * D_87E1EC88;
void func_87E177E0(void) {
    s8 screen[8];

    func_87C037C0((u8 *)D_87E1EC88 + 0x10D8, *(void **)(*(u8 **)((u8 *)D_87E1EC88 + 0xC) + 0xC));
    func_87C03B60((u8 *)D_87E1EC88 + 0x10D8, D_87F119DC + 0x48, screen);
    switch (((u8 *)D_87E1EC88)[1]) {
    case 0:
    case 2:
    case 4:
        break;
    case 1:
        func_8002781C(0xC009, ((u8 *)D_87E1EC88)[2], screen);
        break;
    case 3:
        if ((*(s32 *)(D_87F119DC + 0xC) << 2) < 0) {
            func_8002781C(0xCF0D, ((u8 *)D_87E1EC88)[2], screen);
            *(s32 *)(D_87F119DC + 0xC) &= ~0x20000000;
        }
        break;
    case 5:
        *(f32 *)(D_87F119DC + 0x54) *= 0.8f;
        *(f32 *)(D_87F119DC + 0x58) *= 0.8f;
        *(f32 *)(D_87F119DC + 0x5C) *= 0.8f;
        break;
    }
    MtxF_Copy(D_87F119DC + 0x84, (u8 *)D_87E1EC88 + 0x348);
}

extern void func_87E177E0();
void func_87E17928(u8 *arg0) {
    u8 *entry;
    f32 scale;

    entry = func_87F025B8(arg0 + 0x1C, func_87E177E0);
    if (entry != NULL) {
        func_8003F1DC(entry + 0x24);
        func_8003F114(entry + 0x24, 0, -1, *(s32 *)(arg0 + 0x10));
        scale = 1.2f;
        entry[0x25] &= ~1;
        entry[0x26] |= 0x10;
        *(f32 *)(entry + 0x5C) = scale;
        *(f32 *)(entry + 0x58) = scale;
        *(f32 *)(entry + 0x54) = scale;
        *(f32 *)(entry + 0x48) = -1000.0f;
        *(f32 *)(entry + 0x4C) = 0.0f;
        *(f32 *)(entry + 0x50) = 1000.0f;
        *(f32 *)(entry + 0x10) = 80.0f;
        *(f32 *)(entry + 0x14) = 400.0f;
        *(f32 *)(entry + 0x18) = -20.0f;
    }
}

extern u8 D_87E1B270;
extern u8 D_87E1B2DC;
extern u8 D_87E1EC70;
extern void func_87F0C094(void *, f32, f32, f32, f32, s32, s32);
extern void func_87F0252C(void *, void *, void *, s32);
extern s32 process_geo_layout(s32, s32 *);
extern s32 func_8004C990(s32, s32);
extern void func_87E156A0(void *arg0);
extern void func_87E15A08(void *arg0);
extern s32 func_87F08E3C(s32, s32);
extern void * D_87E1EC88;
void func_87E179F4(u8 *arg0, s32 arg1) {
    void *pool;

    D_87E1EC88 = arg0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = arg1;
    arg0[1] = 0;
    func_87E156A0(arg0);
    func_87F0C094(arg0 + 0x1158, 1274.0f, 945.0f, -1018.0f, 7139.0f, -0x238E, 0);
    func_8004C8C0(0x1B2);
    func_8004DDF4(0x98);
    pool = (void *)MainPool_AllocState(main_pool_get_available(), 0);
    *(void **)(arg0 + 0xC) = (void *)process_geo_layout(pool, &D_87E1B270);
    *(void **)(arg0 + 0x10) = (void *)WidgetTree_RunMessagePanelSilent(pool, 0x98);
    *(void **)(arg0 + 0x14) = (void *)process_geo_layout(pool, &D_87E1B2DC);
    MainPool_FinalizeAllocation(pool);
    *(void **)(arg0 + 0x18) = (void *)func_87F08E3C(func_8004C990(0x1B2, 6), 0x0F000000);
    func_80037E9C(0, &D_87E1EC70);
    func_87F0252C(&D_87E1EC70, arg0 + 0x1C, arg0 + 0x30, 2);
    func_87F0252C(&D_87E1EC70, arg0 + 0x454, arg0 + 0x468, 8);
    func_87E15A08(arg0 + 0x348);
}

/* mkdraft:func_87E17B34 begin */
extern u8 D_800CE060[];
extern s32 func_87E17484(void *);
extern void func_800279C4(s32);
extern void func_87F0277C(void *);



s32 func_87E17B34(void *arg0) {
    s32 result;
    s8 value;

    result = 0;
    D_87E1EC88 = arg0;
    *(s32 *)((u8 *)arg0 + 4) += 1;
    ((u8 *)D_87E1EC88)[3] = 0;
    if (((s8 *)D_87E1EC88)[1] != 0) {
        func_87E16FC4((u8 *)arg0 + 0x348);
    }
    switch (((s8 *)D_87E1EC88)[1]) {
    case 1:
        if ((1 << ((s8 *)arg0)[2]) & *(u8 *)(*(u8 **)((u8 *)arg0 + 8) + 0x2182)) {
            if (*(u16 *)(D_800CE060 + ((s8 *)arg0)[2] * 40 + 8) & 0x8000) {
                ((s8 *)D_87E1EC88)[1] = 2;
            }
        } else if (*(u32 *)((u8 *)D_87E1EC88 + 4) > ((func_8003570C() % 31u) + 15u)) {
            ((s8 *)D_87E1EC88)[1] = 2;
        }
        if (((s8 *)D_87E1EC88)[1] == 2) {
            *(u32 *)((u8 *)arg0 + 0x3C) |= 0x20000000;
            ((u8 *)D_87E1EC88)[3] = 1;
        }
        break;
    case 2:
        ((s8 *)D_87E1EC88)[1] = 3;
        break;
    case 3:
        if (func_87E17484((u8 *)arg0 + 0x348)) {
            value = func_87E1733C((u8 *)arg0 + 0x348);
            ((s8 *)D_87E1EC88)[0] = value;
            if (value != -1) {
                ((s8 *)D_87E1EC88)[1] = 4;
                *(s32 *)((u8 *)D_87E1EC88 + 4) = 0;
                func_800279C4(0xCF0A);
            }
        }
        break;
    case 4:
        if (*(s32 *)((u8 *)D_87E1EC88 + 4) >= func_80001FF0() / 3) {
            ((s8 *)D_87E1EC88)[1] = 5;
        }
        break;
    case 5:
        result = 1;
        break;
    }
    func_87F0277C((u8 *)arg0 + 0x1C);
    return result;
}
/* mkdraft:func_87E17B34 end */

extern void GfxImage_ClearDepthRectangle(Gfx **, s32, s32, s32, s32);
extern void Geo_RenderRootNode(s32);
extern Gfx * D_800D0510;
extern void * D_87E1EC88;
void func_87E17D40(u8 *arg0) {
    D_87E1EC88 = arg0;
    GfxImage_ClearDepthRectangle(&D_800D0510, 0, 0, 320, 240);
    Geo_RenderRootNode(*(s32 *)(arg0 + 0xC));
    switch (*(s8 *)((u8 *)D_87E1EC88 + 1)) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

/* mkdraft:func_87E17DAC begin */
extern void *D_87E1EC88;
extern void func_87F02684(u8 *);
extern void func_87E17928(u8 *);
extern void func_87E15AD0(u8 *);

// Re-initialises the record published through D_87E1EC88: the first four bytes
// become (-1, 1, arg1, 0), the pointer is advanced 0x30 bytes to the field block
// whose bit 0 at +0x25 and floats at +0x10..+0x5C (80/400/-20 and 1.2 x3,
// 1000/0/-1000) are set, then bit 0 of the record's 0x1BD byte is set and
// func_87E15AD0 is handed arg0 + 0x348.


void func_87E17DAC(u8 *arg0, s32 arg1) {
    u8 *p;

    D_87E1EC88 = arg0;
    func_87F02684(arg0 + 0x1C);
    func_87E17928(arg0);
    *(s8 *)((u8 *)D_87E1EC88 + 0) = -1;
    *(s32 *)((u8 *)D_87E1EC88 + 4) = 0;
    *(s8 *)((u8 *)D_87E1EC88 + 2) = (s8) arg1;
    *(s8 *)((u8 *)D_87E1EC88 + 1) = 1;
    p = D_87E1EC88;
    p += 0x30;
    p[0x25] |= 1;
    *(f32 *)(p + 0x54) = 1.2f;
    *(f32 *)(p + 0x58) = 1.2f;
    *(f32 *)(p + 0x5C) = 1.2f;
    *(f32 *)(p + 0x48) = -1000.0f;
    *(f32 *)(p + 0x4C) = 0.0f;
    *(f32 *)(p + 0x50) = 1000.0f;
    *(f32 *)(p + 0x10) = 80.0f;
    *(f32 *)(p + 0x14) = 400.0f;
    *(f32 *)(p + 0x18) = -20.0f;
    *(u8 *)((u8 *)D_87E1EC88 + 0x1BD) |= 1;
    func_87E15AD0(arg0 + 0x348);
}
/* mkdraft:func_87E17DAC end */

s32 func_87E17EA8(u8 *arg0) {
    return *(s8 *)(arg0 + 1) == 5;
}

s32 func_87E17EB8(u8 *arg0) {
    return *(s8 *)(arg0 + 3) == 1;
}

s32 func_87E17EC8(u8 *arg0) {
    return *(s8 *)(arg0 + 1);
}

extern s32 main_pool_push_state(s32);
extern void func_87E03594(void *, s32);
extern void func_87E03CEC(void *);
void func_87E17ED0(void *arg0) {
    main_pool_push_state(0x4D51454A);
    func_87E03594((u8 *)arg0 + 0x30, *(s32 *)((u8 *)arg0 + 0x264));
    func_87E03CEC((u8 *)arg0 + 0x30);
}

extern void func_87E01628();
extern void func_87E03D28(s32);
extern void main_pool_pop_state(s32);

void func_87E17F14(s32 arg0) {
    func_87E03D28(arg0 + 0x30);
    func_87E01628();
    main_pool_pop_state(0x4D51454A);
}


void func_87E17F48(void) {
    func_87E01628();
    main_pool_pop_state(0x4D514D53);
}

extern s32 main_pool_push_state(s32);
extern void func_87E17ED0(void *);
extern void func_87E18A14(void *, s32, s32);
void func_87E17F74(void *arg0, void *arg1) {
    s32 state;

    main_pool_push_state(0x4D514D53);
    *(void **)((u8 *)arg0 + 0x264) = arg1;
    state = *(s32 *)((u8 *)arg1 + 0x21F8);
    switch (state) {
    case 0:
    case 1:
        *(s32 *)((u8 *)arg0 + 0) = 1;
        func_87E18A14((u8 *)arg0 + 4,
                      *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x264) + 0x2200),
                      0x2C);
        break;
    case 2:
        *(s32 *)((u8 *)arg0 + 0) = 3;
        func_87E17ED0(arg0);
        break;
    case 3:
        *(s32 *)((u8 *)arg0 + 0) = 4;
        func_87E18A14((u8 *)arg0 + 0x238,
                      *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x264) + 0x2204),
                      0x2D);
        break;
    }
}

void func_87E18034(u8 *arg0, s32 arg1) {
    *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x2200) = arg1;
    *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x2184) = 3;
    *(s32 *)arg0 = 1;
}

extern s32 func_87E18F08(u8 *);
extern void func_87E189E8(u8 *);
extern void func_87E18034(u8 *arg0, s32 arg1);
s32 func_87E18054(u8 *arg0) {
    s32 result;
    s32 state;

    result = 0;
    state = func_87E18F08(arg0 + 4);
    if (state != 0) {
        func_87E189E8(arg0 + 4);
        switch (state) {
        case 1:
            func_87E18034(arg0, 0);
            result = 2;
            break;
        case 2:
            func_87E18034(arg0, 1);
            result = 2;
            break;
        case 3:
            func_87E18034(arg0, 2);
            result = 2;
            break;
        case 4:
            result = 1;
            break;
        }
    }
    return result;
}

extern s32 func_87E04114(u8 *);
extern void func_87E17F14(s32);
extern void func_87E18A14(void *, s32, s32);
s32 func_87E18120(s32 arg0) {
    s32 result;
    s32 state;
    result = 0;
    state = func_87E04114((u8 *)arg0 + 0x30);
    if (state != 2) {
        func_87E17F14(arg0);
        switch (state) {
        case 0:
            *(s32 *)arg0 = 4;
            func_87E18A14((u8 *)arg0 + 0x238,
                          *(s32 *)(*(u8 **)((u8 *)arg0 + 0x264) + 0x2204),
                          0x2D);
            break;
        case 1:
            result = 1;
            break;
        }
    }
    return result;
}

void func_87E181B4(u8 *arg0, s32 arg1) {
    *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x2204) = arg1;
    *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x2184) = 4;
    *(s32 *)arg0 = 4;
}

extern void func_87E17ED0(void *arg0);
extern void func_87E181B4(u8 *arg0, s32 arg1);
extern void func_87E189E8(u8 *);
extern s32 func_87E18F08(u8 *);
s32 func_87E181D0(u8 *arg0) {
    s32 result;
    s32 state;

    result = 0;
    state = func_87E18F08(arg0 + 0x238);
    if (state != 0) {
        func_87E189E8(arg0 + 0x238);
        switch (state) {
        case 1:
            func_87E181B4(arg0, 0);
            result = 2;
            break;
        case 2:
            func_87E181B4(arg0, 1);
            result = 2;
            break;
        case 3:
            func_87E181B4(arg0, 2);
            result = 2;
            break;
        case 4:
            *(s32 *)arg0 = 3;
            func_87E17ED0(arg0);
            break;
        }
    }
    return result;
}

extern s32 func_87E18054(u8 *);
extern s32 func_87E181D0();
extern s32 func_87E18120(s32 arg0);
s32 func_87E182A8(u8 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v1;

    temp_v0 = *(s32 *)(arg0 + 0);
    var_v1 = 0;
    switch (temp_v0) {
    case 1:
        var_v1 = func_87E18054(arg0);
        break;
    case 3:
        var_v1 = func_87E18120((s32)arg0);
        break;
    case 4:
        var_v1 = func_87E181D0(arg0);
        break;
    }
    if (var_v1 == 2) {
        temp_v0_2 = *(s32 *)(arg0 + 0);
        switch (temp_v0_2) {
        case 0:
            *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x21F8) = 0;
            break;
        case 1:
            *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x21F8) = 1;
            break;
        case 3:
            *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x21F8) = 2;
            break;
        case 4:
            *(s32 *)(*(u8 **)(arg0 + 0x264) + 0x21F8) = 3;
            break;
        }
    }
    return var_v1;
}

extern void func_87E1918C(s32);
extern void func_87E03448();
void func_87E183A0(void *arg0) {
    s32 value;
    value = *(s32 *)arg0;
    switch (value) {
    case 1:
        func_87E1918C((s32)((u8 *)arg0 + 4));
        break;
    case 3:
        func_87E03448((u8 *)arg0 + 0x30);
        break;
    case 4:
        func_87E1918C((s32)((u8 *)arg0 + 0x238));
        break;
    }
}
#endif
