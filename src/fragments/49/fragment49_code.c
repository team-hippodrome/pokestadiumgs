#include "global.h"


#ifdef VERSION_US
void func_86100020(s8 *arg0, u8 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 value;

    if (arg4 == arg3) {
        value = 0;
    } else {
        value = (s32)(((arg2 - arg3) / (arg4 - arg3)) * (f32)arg1) - (arg1 >> 1) - 1;
    }
    if (value >= 0x80) {
        value = 0x7F;
    }
    if (value < -0x80) {
        value = -0x80;
    }
    *arg0 = value;
}

extern void func_800277C4(u16, u8, void *);
void func_861000B8(void *arg0, u16 arg1) {
    s8 data[4];

    func_86100020(data, 0x7F, *(f32 *)((u8 *)arg0 + 0x48), -364.4109191894531f, 321.53903f);
    data[1] = 0;
    func_800277C4(arg1, *((u8 *)arg0 + 0x23), data);
}
void func_861000B8_padding(void) {}

extern s32 D_8610AD20;
void func_86100120(void) {
    typedef struct {
        u8 pad[0x8F24];
        f32 timer;
        s32 entries[42];
        s32 current;
        s32 index;
    } Context86100120;
    s32 index;

    ((Context86100120 *)(u32)D_8610AD20)->timer = 0.0f;
    ((Context86100120 *)(u32)D_8610AD20)->index += 1;
    if (((Context86100120 *)(u32)D_8610AD20)->index >= 0x2B) {
        ((Context86100120 *)(u32)D_8610AD20)->index = 0;
    }
    index = ((Context86100120 *)(u32)D_8610AD20)->index;
    ((Context86100120 *)(u32)D_8610AD20)->current = ((Context86100120 *)(u32)D_8610AD20)->entries[index];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_861001A0.s")

extern void func_86105C30(f32);
extern s32 D_8610AD20;
void func_861003A4(void) {
    func_86105C30(-((f32)*(u8 *)((u8 *)(u32)*(s32 *)((u8 *)(u32)D_8610AD20 + 0x8FD0) + 1) / 255.0f) * 444.18225f + 213.68527f);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86100418.s")

extern s32 D_8610AD20;
extern s32 func_87F08208(void *);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void func_800226C0(s32);
extern void Audio_PlayDefaultSound(s32);
extern void func_861094BC(s32 arg0);
extern void func_87F0277C(s32);
void func_8610068C(void) {
    s32 temp_v0;

    func_87F0277C(D_8610AD20 + 0x7C);
    temp_v0 = func_87F08208((void *)(u32)(D_8610AD20 + 0x44));
    switch (temp_v0) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)((u8 *)(u32)D_8610AD20 + 0x3C) = 2;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        return;
    case 2:
        func_861094BC(0);
        func_800226C0(3);
        return;
    }
}

extern s32 D_8610AD20;
extern s32 StageContext_GetFadeMode(void);
extern void func_86105008(void);
extern void func_86104CAC(void);
extern void StageFade_StartFromOpaque(s32);
extern void func_87F00688(void);
extern void func_87F0277C(s32);

void func_86100728(void) {
    if (StageContext_GetFadeMode() == 1) {
        func_86105008();
        func_86104CAC();
        StageFade_StartFromOpaque(0x14);
        *(s32 *)((u8 *)(u32)D_8610AD20 + 0x3C) = 3;
        func_87F00688();
    }
    func_87F0277C(D_8610AD20 + 0x7C);
}

/* mkdraft:func_86100790 begin */
extern s32 D_8610AD20;
extern s32 StageContext_GetFadeMode(void);
extern void func_87F0277C(s32);



void func_86100790(void) {
    if (StageContext_GetFadeMode() == 0) {
        (void)(D_8610AD20 ? 1 : 2); // FAKE: dead statement; without it score 100 (branch gone)
        (void)(D_8610AD20 ? 3 : 4); // FAKE: dead statement; without it score 100
    }
    func_87F0277C(D_8610AD20 + 0x6E8);
    func_87F0277C(D_8610AD20 + 0x8914);
}
/* mkdraft:func_86100790 end */

extern s32 func_87F0C930(s32);
extern s32 func_87F0A098(void *, void *, s32, u32, u32, u32, u32);
extern s32 D_8610AD20;
void func_861007D8(void) {
    s32 v0 = *(s32 *)&D_8610AD20;
    if (*(u8 *)((u8 *)(u32)*(s32 *)((u8 *)(u32)v0) + 0x2180) == 4) {
        func_87F0C930(v0 + 0x2C);
        return;
    }
    *(s32 *)((u8 *)(u32)v0 + 0x97DC) = 1;
    v0 = *(s32 *)&D_8610AD20;
    func_87F0A098((void *)((u8 *)(u32)v0 + 0x9704), (void *)*(s32 *)((u8 *)(u32)v0), 0,
                  *(u32 *)((u8 *)(u32)v0 + 0x708) & 0x100000,
                  *(u32 *)((u8 *)(u32)v0 + 0x894) & 0x100000,
                  *(u32 *)((u8 *)(u32)v0 + 0xA20) & 0x100000,
                  *(u32 *)((u8 *)(u32)v0 + 0xBAC) & 0x100000);
}

void func_86100874(void) {
    s32 count = 0;
    s32 i;
    s32 flags;
    s32 base = D_8610AD20 + 0x6FC;
    // FAKE: is_null and the empty if (is_null) {} below keep an extra register live; diff score 45 without them.
    s32 is_null = !base;

    // Four 0x18C-byte records start at D_8610AD20 + 0x6FC; func_861007D8 reads the same
    // flag words at 0x708, 0x894, 0xA20 and 0xBAC.
    for (i = 0; i < 4; i++, base += 0x18C) {
        flags = *(s32 *)(base + 0xC);
        if (flags & 0x200000) {
            count++;
            if (is_null) {} // FAKE: see is_null.
        }
    }
    if (*(s32 *)((u8 *)(u32)D_8610AD20 + 0x97DC) == 0 && count > 0) {
        func_861007D8();
    }
}

extern void func_86100E20(void *, s32);
void func_861008E8(void) {
    struct ScoreContext {
        u8 pad[0x708];
        s32 flag0;
        u8 gap0[392];
        s32 flag1;
        u8 gap1[392];
        s32 flag2;
        u8 gap2[392];
        s32 flag3;
    };
    s32 value;
    // FAKE: these unused words preserve the original stack frame size.
    s32 unused0;
    s32 unused1;

    s32 i;
    s32 highest;
    s32 count;
    u8 *start;
    u8 *node;
    u8 *record;

    start = (u8 *)(u32)D_8610AD20 + 0x8DE0;
    count = 0;
    record = start;
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            highest = *(s32 *)(record + 4);
        }
        value = *(s32 *)(record + 4);
        if (highest < value) {
            highest = value;
        }
        record += 44;
    }
    node = (u8 *)(u32)D_8610AD20 + 0x6FC;
    record = start;
    i = 0;
    do {
        func_86100E20(node, 0x400000);
        if (highest == *(s32 *)(record + 4)) {
            count++;
            *(s32 *)(node + 0xC) |= 0x100000;
        } else {
            *(s32 *)(node + 0xC) |= 0x800000;
        }
        i++;
        record += 44;
        node += 396;
    } while (i != 4);
    if (count == 4) {
        ((struct ScoreContext *)(u32)D_8610AD20)->flag0 = ((struct ScoreContext *)(u32)D_8610AD20)->flag0 & 0xFFEFFFFF;
        ((struct ScoreContext *)(u32)D_8610AD20)->flag1 = ((struct ScoreContext *)(u32)D_8610AD20)->flag1 & 0xFFEFFFFF;
        ((struct ScoreContext *)(u32)D_8610AD20)->flag2 = ((struct ScoreContext *)(u32)D_8610AD20)->flag2 & 0xFFEFFFFF;
        ((struct ScoreContext *)(u32)D_8610AD20)->flag3 = ((struct ScoreContext *)(u32)D_8610AD20)->flag3 & 0xFFEFFFFF;
        func_861007D8();
    }
}

extern void *func_87F0A3E8(void *);
extern void func_86109394(void);
extern void func_861094BC(s32);
void func_86100A58(void) {
    func_86109394();
    if (func_87F0A3E8((void *)((u8 *)(u32)D_8610AD20 + 0x9704)) != NULL) {
        if (*(u8 *)((u8 *)(u32)*(s32 *)((u8 *)(u32)D_8610AD20) + 0x2180) == 1) {
            func_861094BC(2);
        } else {
            *(s32 *)((u8 *)(u32)D_8610AD20 + 0x3C) = 6;
        }
    }
}
void func_86100A58_padding(void) {}

extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86100ACC(s32 a, void *p) {
    s16 pad;
    s32 x;
    s16 y;
    s16 z;
    if (a == 2) {
        func_80037120(
            D_80094908 + 0xB4,
            D_80094908 + 0xA8,
            &x, &y, &z
        );
        *(s16 *)((u8 *)p + 0x1C) = y + 0x2000;
        *(s16 *)((u8 *)p + 0x1E) = z - 0x2000;
    }
    return 0;
}

extern s32 D_80094908;
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);

s32 func_86100B34(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - sp26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 + 0x6000);
    }
    return 0;
}

extern Gfx *D_800D0510;
s32 func_86100BA0(s32 arg0, void *arg1) {
    if (arg0 == 2) {
        gDPSetScissor(D_800D0510++, 0, 0, 10, 320, 230);
    }
    return 1;
}

extern s32 D_8610AD20;
void func_86100BE0(void *arg0) {
    f32 temp_fv1;
    f32 var_fv0;
    void *temp_v0 = (void *)((u8 *)arg0 + 0x24);
    if (*(s32 *)((u8 *)(u32)D_8610AD20 + 0x3C) == 4) {
        var_fv0 = -209.00037f;
    } else {
        var_fv0 = -192.92343f;
    }
    if (*(f32 *)((u8 *)temp_v0 + 0x28) < var_fv0) {
        *(f32 *)((u8 *)temp_v0 + 0x28) = var_fv0;
        temp_fv1 = *(f32 *)((u8 *)arg0 + 0x14);
        if (temp_fv1 < 0.0f) {
            *(f32 *)((u8 *)arg0 + 0x14) = temp_fv1 * -0.5f;
        }
    }
    if (199.3542f < *(f32 *)((u8 *)temp_v0 + 0x28)) {
        *(f32 *)((u8 *)temp_v0 + 0x28) = 199.3542f;
        *(f32 *)((u8 *)arg0 + 0x14) = *(f32 *)((u8 *)arg0 + 0x14) * (f32)0;
    }
    temp_fv1 = -364.41092f;
    var_fv0 = *(f32 *)((u8 *)temp_v0 + 0x24);
    if (var_fv0 < temp_fv1) {
        *(f32 *)((u8 *)temp_v0 + 0x24) = temp_fv1;
        *(f32 *)((u8 *)arg0 + 0x10) *= 0.5f;
    }
    var_fv0 = *(f32 *)((u8 *)temp_v0 + 0x24);
    temp_fv1 = 321.53903f;
    if (temp_fv1 < var_fv0) {
        *(f32 *)((u8 *)temp_v0 + 0x24) = temp_fv1;
        *(f32 *)((u8 *)arg0 + 0x10) *= 0.5f;
    }
}

extern s32 D_8610AD20;
void func_86100CFC(void *arg0) {
    f32 temp_fv1;
    f32 var_fv0;
    void *temp_v0;

    temp_v0 = (void *)((u8 *)arg0 + 0x24);
    if (*(s32 *)((u8 *)(u32)D_8610AD20 + 0x3C) == 4) {
        var_fv0 = -209.00037f;
    } else {
        var_fv0 = -192.92343f;
    }
    if (*(f32 *)((u8 *)temp_v0 + 0x28) < var_fv0) {
        *(f32 *)((u8 *)temp_v0 + 0x28) = var_fv0;
        temp_fv1 = *(f32 *)((u8 *)arg0 + 0x14);
        if (temp_fv1 < 0.0f) {
            *(f32 *)((u8 *)arg0 + 0x14) = temp_fv1 * -0.5f;
        }
    }
    if (199.3542f < *(f32 *)((u8 *)temp_v0 + 0x28)) {
        *(f32 *)((u8 *)temp_v0 + 0x28) = 199.3542f;
        *(f32 *)((u8 *)arg0 + 0x14) = *(f32 *)((u8 *)arg0 + 0x14) * (f32)0;
    }
}

void func_86100DA8(void *arg0) {
    if ((*(f32 *)((u8 *)(arg0) + (0x10))) < -15.0f) {
        (*(f32 *)((u8 *)(arg0) + (0x10))) = -15.0f;
    }
    if ((*(f32 *)((u8 *)(arg0) + (0x10))) > 15.0f) {
        (*(f32 *)((u8 *)(arg0) + (0x10))) = 15.0f;
    }
    if ((*(f32 *)((u8 *)(arg0) + (0x14))) < -15.0f) {
        (*(f32 *)((u8 *)(arg0) + (0x14))) = -15.0f;
    }
    if ((*(f32 *)((u8 *)(arg0) + (0x14))) > 15.0f) {
        (*(f32 *)((u8 *)(arg0) + (0x14))) = 15.0f;
    }
}

extern void ModelAnim_SetAnimation(void *, s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern u32 func_8003570C(void);
void func_86100E20(void *arg0, s32 arg1) { if ((arg1 & 0x80000000) != 0) { if ((*(s32 *)((u8 *)arg0+12)<<1)>=0) { *(s32 *)((u8 *)arg0+12)|=arg1; *(s32 *)((u8 *)arg0+28)=0; } } else if ((arg1 & 0x40000000) != 0) { *(s32 *)((u8 *)arg0+12)&=0x7EFFFFFF; *(s32 *)((u8 *)arg0+12)|=arg1; *(s32 *)((u8 *)arg0+28)=0; } else if ((arg1 & 0x00400000) != 0) { *(s32 *)((u8 *)arg0+28)=0; *(s32 *)((u8 *)arg0+12)|=arg1; ModelAnim_SetAnimation((u8 *)arg0+36,5); ModelAnim_SetFrame((u8 *)arg0+36,(s16)(func_8003570C()%12)); } else if ((arg1 & 0x01000000) != 0) { *(s32 *)((u8 *)arg0+196)=0xFF0000AF; *(s32 *)((u8 *)arg0+12)|=arg1; *(s32 *)((u8 *)arg0+28)=0; } else { *(s32 *)((u8 *)arg0+28)=0; *(s32 *)((u8 *)arg0+12)|=arg1; } }

extern void func_861000B8(void *, u16);
typedef union { f32 f; s32 i; } Coord86100F1C;
typedef struct { u8 pad[0x48]; Coord86100F1C x; Coord86100F1C y; Coord86100F1C z; } Object86100F1C;
extern u32 func_8003570C(void);
extern void func_86101558(f32 *arg0, f32 *arg1);
extern void func_86107098(s32, s32, s32, s32, f32, f32, f32, f32);
extern s32 D_8610AD20;
void func_86100F1C(Object86100F1C *arg0, void *arg1, s32 arg2) {
    f32 x;
    f32 y;

    if (*(s32 *)((u8 *)arg1 + 4) > 0) {
        x = ((((f32)func_8003570C() / 4294967296.0f) * 685.94995f + -364.41092f) * 0.7f) - arg0->x.f;
        y = ((((f32)func_8003570C() / 4294967296.0f) * 408.35455f + -209.00037f) * 0.7f) - arg0->y.f;
        func_86101558(&x, &y);
        func_86107098(arg2 | 0x20000000, (s32)arg0, arg0->x.i, arg0->y.i, arg0->z.f, x * 15.0f - *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9774), y * 15.0f, 0.0f);
        (*(s32 *)((u8 *)arg1 + 4))--;
        func_861000B8(arg0, 0xF05);
    }
}

extern void *Vec3f_Subtract(void *, void *, void *);
extern void func_86100BE0(void *);
extern void func_861000B8(void *, u16);
extern void func_86100E20(void *arg0, s32 arg1);
extern f32 func_87D005E8(f32 *, f32 *, f32 *);
extern s32 D_8610AD20;
void func_8610109C(void *arg0, void *arg1) {
#define a ((u8 *)arg0)
#define b ((u8 *)arg1)
    typedef struct { f32 x, y, z; } Vec;
    Vec delta;
    f32 dist;
    Vec normal;
    Vec vel;
    f32 dot;
    Vec aa;
    Vec bb;
    s32 flagA;
    f32 scale;
    f32 factorA;
    f32 factorB;
    f32 limit;
    scale = *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9768) * 0.04f;
    limit = ((scale * 700.0f) * 1.75f) * 0.5f;
    limit *= ((*(f32 *)(a + 0x54) / scale) + (*(f32 *)(b + 0x54) / scale));
    Vec3f_Subtract(&delta, a + 0x48, b + 0x48);
    dist = sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
    if (!(dist < limit)) return;
    if (dist != 0.0f) {
        normal.x = delta.x / dist;
        normal.y = delta.y / dist;
        normal.z = delta.z / dist;
    } else {
        normal.x = 1.0f;
        normal.y = 0.0f;
        normal.z = 0.0f;
    }
    Vec3f_Subtract(&vel, a + 0x10, b + 0x10);
    dot = vel.x * normal.x + vel.y * normal.y + vel.z * normal.z;
    if (*(s32 *)((u8 *)(u32)D_8610AD20 + 0x3C) == 4) goto special;
    factorA = 0.6f;
    factorB = 0.6f;
    goto done_special;
special:
        aa = *(Vec *)(a + 0x10);
        func_87D005E8((f32 *)&aa, &aa.y, &aa.z);
        bb = *(Vec *)(b + 0x10);
        scale = func_87D005E8((f32 *)&bb, &bb.y, &bb.z);
        factorA = 0.8f;
        factorB = 0.8f;
        flagA = *(u32 *)(a + 0xC) & 0x20000;
        if (flagA != 0) {
            if ((*(u32 *)(b + 0xC) & 0x20000) == 0) {
            factorA = 0.5f;
            func_861000B8(b, 0xF01);
            func_86100F1C((Object86100F1C *)b, (void *)&((struct { u8 pad[0x8DE0]; u8 rec[][0x2C]; } *)(u32)D_8610AD20)->rec[*(s32 *)(b + 0x20)], 0x1000000);
            func_86100E20(b, 0x1000000);
            }
        } else if ((*(u32 *)(b + 0xC) & 0x20000) != 0) {
            if (flagA == 0) {
            factorB = 0.5f;
            func_861000B8(a, 0xF01);
            func_86100F1C((Object86100F1C *)a, (void *)&((struct { u8 pad[0x8DE0]; u8 rec[][0x2C]; } *)(u32)D_8610AD20)->rec[*(s32 *)(a + 0x20)], 0x1000000);
            func_86100E20(a, 0x1000000);
            }
        }
done_special:
    *(f32 *)(a + 0x48) += ((limit - dist) * normal.x) * 0.5f;
    *(f32 *)(a + 0x4C) += ((limit - dist) * normal.y) * 0.5f;
    *(f32 *)(a + 0x50) += ((limit - dist) * normal.z) * 0.5f;
    *(f32 *)(b + 0x48) -= ((limit - dist) * normal.x) * 0.5f;
    *(f32 *)(b + 0x4C) -= ((limit - dist) * normal.y) * 0.5f;
    *(f32 *)(b + 0x50) -= ((limit - dist) * normal.z) * 0.5f;
    func_86100BE0(b);
    *(f32 *)(a + 0x10) += ((normal.x * dot) * -(1.0f + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x979C))) * factorA;
    *(f32 *)(a + 0x14) += ((normal.y * dot) * -(1.0f + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x979C))) * factorA;
    *(f32 *)(a + 0x18) += ((normal.z * dot) * -(1.0f + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x979C))) * factorA;
    *(f32 *)(b + 0x10) += ((normal.x * dot) * (1.0f + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x979C))) * factorB;
    *(f32 *)(b + 0x14) += ((normal.y * dot) * (1.0f + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x979C))) * factorB;
    *(f32 *)(b + 0x18) += ((normal.z * dot) * (1.0f + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x979C))) * factorB;
#undef a
#undef b
}

void func_86101558(f32 *arg0, f32 *arg1) {
    f32 temp_fa0;
    f32 temp_fv0;
    f32 temp_fv1;
    temp_fv1 = *arg1;
    temp_fa0 = *arg0;
    temp_fv0 = sqrtf((temp_fv1 * temp_fv1) + (temp_fa0 * temp_fa0));
    if (temp_fv0 != 0.0f) {
        *arg0 = temp_fa0 / temp_fv0;
        *arg1 /= temp_fv0;
    }
}
void func_86101558_padding(void) {}

extern s32 D_8610AD20;
f32 func_861015AC(f32 arg0, f32 arg1) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 var_fv1;
    void *var_v0;

    var_v0 = (*(void **)((u8 *)(D_8610AD20) + (0x260C)));
    var_fv1 = 0.0f;
    if (var_v0 != NULL) {
        do {
            temp_fa0 = arg0 - (*(f32 *)((u8 *)(var_v0) + (0x48)));
            temp_fa1 = arg1 - (*(f32 *)((u8 *)(var_v0) + (0x4C)));
            temp_ft4 = (((700.0f * (0.04f * (*(f32 *)((u8 *)(D_8610AD20) + (0x9768))))) + 30.0f) * 3.0f) - sqrtf((temp_fa0 * temp_fa0) + (temp_fa1 * temp_fa1));
            if (temp_ft4 > 0.0f) {
                var_fv1 += temp_ft4;
            }
            var_v0 = (*(void **)((u8 *)(var_v0) + (4)));
        } while (var_v0 != NULL);
    }
    return var_fv1;
}

void func_8610167C(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 *arg6, f32 *arg7) {
    f32 extra0;
    f32 extra1;
    f32 temp_ft5;
    f32 temp_ft1;
    f32 temp_fv1;
    f32 temp_ft4;
    f32 x;
    f32 y;
    f32 temp_fv0;

    temp_ft5 = arg0 - arg4;
    temp_ft1 = arg1 - arg5;
    temp_fv1 = (arg2 - arg4) - temp_ft5;
    temp_ft4 = (arg3 - arg5) - temp_ft1;
    temp_fv0 = (temp_fv1 * temp_fv1) + (temp_ft4 * temp_ft4);
    *arg7 = (temp_fv0 != 0.0f) ? -(((temp_ft5 * temp_fv1) + (temp_ft1 * temp_ft4)) / temp_fv0) : 0.0f;
    x = (*arg7 * temp_fv1) + temp_ft5;
    y = (*arg7 * temp_ft4) + temp_ft1;
    *arg6 = sqrtf((x * x) + (y * y));
}

extern void * D_87F119DC;
f32 func_86101758(f32 arg0, f32 arg1) {
    f32 result;
    f32 distance;
    f32 t;
    u8 *ptr;

    result = 0.0f;
    ptr = *(u8 **)((u8 *)D_8610AD20 + 0xD38);
    if (ptr != NULL) {
        do {
            // func_8610167C: distance from (arg0, arg1) to the line through both points, and the projection parameter t.
            func_8610167C(*(f32 *)((u8 *)D_87F119DC + 0x48), *(f32 *)((u8 *)D_87F119DC + 0x4C), *(f32 *)(ptr + 0x48),
                          *(f32 *)(ptr + 0x4C), arg0, arg1, &distance, &t);
            if (t > 0.0f && t < 1.0f &&
                distance < ((*(f32 *)((u8 *)D_8610AD20 + 0x9768) * 0.04f * 700.0f + 19.2f) * 0.65f * 1.7f)) {
                result += 70.0f;
            }
            ptr = *(u8 **)(ptr + 4);
        } while (ptr != NULL);
    }
    return result;
}

extern void * D_87F119DC;
s32 func_861018D8(f32 arg0, f32 arg1) { f32 *coord; f32 y; f32 dx; f32 dy; s32 result = 1; coord = &arg1; if (arg0 < -364.41092f) { result = 0; } else { y = *(f32 *)((u8 *)D_87F119DC + 0x48); if (arg0 < y) { dx = y - arg0; dy = *(f32 *)((u8 *)D_87F119DC + 0x4C) - *coord; if ((arg0 - -364.41092f) * 2.0f < sqrtf(dx * dx + dy * dy)) result = 0; } } return result; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86101964.s")

extern void func_86101558(f32 *arg0, f32 *arg1);
extern s32 D_8610AD20;
extern void * D_87F119DC;
f32 func_86101AEC(s32 arg0, f32 *arg1, f32 *arg2) {
    s32 pad[2];
    f32 distance = 0.0f;
    f32 *origin;
    f32 scale;
    s32 *new_var;

    if (arg0 != 0) {
        origin = (f32 *)((u8 *)D_87F119DC + 0x24);
        new_var = &arg0;
        *arg1 = (*(f32 *)((u32)*new_var + 0x48) + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9774) * 4.0f) - origin[9];
        *arg2 = *(f32 *)((u32)arg0 + 0x4C) - origin[10];
        distance = sqrtf(*arg1 * *arg1 + *arg2 * *arg2);
        func_86101558(arg1, arg2);
    } else {
        *arg1 = 0.0f;
        *arg2 = 0.0f;
    }
    scale = 0.3f;
    *arg1 *= scale;
    *arg2 *= scale;
    return distance;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86101BD8.s")

extern s32 D_8610AD20;
extern void * D_87F119DC;
void func_86101E04(f32 arg0, f32 arg1, s32 arg2) {
    f32 value;
    f32 limit;

    value = (arg0 > 0.0f) ? arg0 : -arg0;
    limit = 64.0f;
    limit *= *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9790);
    if (limit < value) {
        arg0 = ((arg0 > 0.0f) ? 1.0f : -1.0f) * limit;
    }
    *(f32 *)((u8 *)D_87F119DC + 0x10) += arg0;
    if (arg2 != 0) {
        value = (arg1 > 0.0f) ? arg1 : -arg1;
        limit = *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784);
        if (limit < value) {
            arg1 = ((arg1 > 0.0f) ? 1.0f : -1.0f) * limit;
        }
        *(f32 *)((u8 *)D_87F119DC + 0x14) += arg1;
        return;
    }
    if (arg1 > 0.0f) {
        limit = *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784);
        value = *(f32 *)((u8 *)D_87F119DC + 0x14);
        if (value < limit) {
            *(f32 *)((u8 *)D_87F119DC + 0x14) = value + limit;
        }
    }
}

extern s32 D_8610AD20;
extern void *D_87F119DC;
extern void func_86101BD8(f32 *, f32 *);
// Gets x/y deltas from func_86101BD8 and, if either is nonzero, adds them to the f32s at
// D_87F119DC + 0x10/0x14. x is limited to +/-64 times the f32 at D_8610AD20 + 0x9790, as in
// func_86101E04. With clamp_y set, y is limited to [-0.25, 2] times the f32 at
// D_8610AD20 + 0x9784; otherwise a positive y adds that f32 once. Returns 1 if the deltas
// were applied. The x clamp is repeated in both branches; hoisting it above the branch does
// not match.
s32 func_86101F60(f32 *x_delta, f32 *y_delta, s32 clamp_y) {
    s32 moved;
    f32 value;
    f32 limit;

    moved = 0;
    func_86101BD8(x_delta, y_delta);
    if ((*x_delta != 0.0f) || (*y_delta != 0.0f)) {
        if (clamp_y != 0) {
            value = (*x_delta > 0.0f) ? *x_delta : -*x_delta;
            limit = 64.0f;
            limit *= *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9790);
            if (limit < value) {
                *x_delta = ((*x_delta > 0.0f) ? 1.0f : -1.0f) * limit;
            }
            *(f32 *)((u8 *)D_87F119DC + 0x10) += *x_delta;
            if (2.0f * *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784) < *y_delta) {
                *y_delta = 2.0f * *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784);
            }
            if (*y_delta < -*(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784) * 0.25f) {
                *y_delta = -*(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784) * 0.25f;
            }
            *(f32 *)((u8 *)D_87F119DC + 0x14) += *y_delta;
        } else {
            value = (*x_delta > 0.0f) ? *x_delta : -*x_delta;
            limit = 64.0f;
            limit *= *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9790);
            if (limit < value) {
                *x_delta = ((*x_delta > 0.0f) ? 1.0f : -1.0f) * limit;
            }
            *(f32 *)((u8 *)D_87F119DC + 0x10) += *x_delta;
            if (*y_delta > 0.0f) {
                *(f32 *)((u8 *)D_87F119DC + 0x14) += *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784);
            }
        }
        moved = 1;
    }
    return moved;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_861021A8.s")

extern s32 D_8610AD20;
extern void * D_87F119DC;
void func_861023D4(void) {
    if (((*(f32 *)((u8 *)D_87F119DC + 0x10) > 0.0f) ? *(f32 *)((u8 *)D_87F119DC + 0x10) : -*(f32 *)((u8 *)D_87F119DC + 0x10)) > 15.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x10) = ((*(f32 *)((u8 *)D_87F119DC + 0x10) > 0.0f) ? 1.0f : -1.0f) * 15.0f;
    }
    if (*(f32 *)((u8 *)D_87F119DC + 0x14) > 15.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x14) -= *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784);
    }
    if (*(f32 *)((u8 *)D_87F119DC + 0x14) < -15.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x14) += *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784);
    }
}

s32 func_86101F60(f32 *, f32 *, s32);
void func_861021A8(f32 *, f32 *);
void func_861023D4(void);
void func_86102C08(void *, s32);
extern void func_86101558(f32 *arg0, f32 *arg1);
extern void func_86101E04(f32 arg0, f32 arg1, s32 arg2);
extern void * D_87F119DC;
void func_861024C8(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    *(f32 *)((u8 *)arg0 + 0xC) += arg1;
    *(f32 *)((u8 *)arg0 + 0x10) += arg2;
    func_86101558((f32 *)((u8 *)arg0 + 0xC), (f32 *)((u8 *)arg0 + 0x10));
    if (func_86101F60(&arg1, &arg2, arg4) == 1) {
        func_86101558(&arg1, &arg2);
        *(f32 *)((u8 *)arg0 + 0xC) += arg1 * 1.5f;
        *(f32 *)((u8 *)arg0 + 0x10) += arg2 * 1.5f;
        func_86101558((f32 *)((u8 *)arg0 + 0xC), (f32 *)((u8 *)arg0 + 0x10));
        return;
    }
    if (arg3 > 0.0f) {
        func_861021A8(&arg1, &arg2);
        arg1 += ((*(f32 *)((u8 *)arg0 + 0xC) * arg3) / 5.0f) - *(f32 *)((u8 *)D_87F119DC + 0x10);
        arg2 += ((*(f32 *)((u8 *)arg0 + 0x10) * arg3) / 5.0f) - *(f32 *)((u8 *)D_87F119DC + 0x14);
        func_86101E04(arg1, arg2, arg4);
        func_861023D4();
        return;
    }
    func_86102C08(arg0, 1);
}

extern s32 D_8610AD20;
s32 *func_86102630(s32 arg0) {
    typedef struct {
        s32 *object;
        s32 score;
        u8 pad[0x24];
    } Entry;
    Entry *p = (Entry *)((u8 *)(u32)D_8610AD20 + 0x8DE0);
    Entry *result = 0;
    s32 best = 0;
    s32 i;

    for (i = 0; i < 4; i++, p++) {
        if ((Entry *)(u32)arg0 != p && p->score > best && (p->object[3] & 0x10000000)) {
            best = p->score;
            result = p;
        }
    }
    return (s32 *)result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86102720.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86102908.s")

extern void *D_87F119DC;
void func_86102B30(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = *(f32 *)((u8 *)arg0 + 0x18) - *(f32 *)((u8 *)D_87F119DC + 0x48);
    *arg2 = *(f32 *)((u8 *)arg0 + 0x1C) - *(f32 *)((u8 *)D_87F119DC + 0x4C);
}

void func_86102B64(void *arg0, f32 *arg1, f32 *arg2) {
    f32 temp_fv0;
    f32 temp_fv0_2;

    temp_fv0 = (*(f32 *)((u8 *)(D_87F119DC) + (0x48)));
    if (temp_fv0 < -158.62593f) {
        *arg1 = -158.62593f - temp_fv0;
    } else {
        *arg1 = (*(f32 *)((u8 *)(arg0) + (0x18))) - temp_fv0;
    }
    temp_fv0_2 = (*(f32 *)((u8 *)(D_87F119DC) + (0x4C)));
    if (temp_fv0_2 < -127.32945f) {
        *arg2 = -127.32945f - temp_fv0_2;
        return;
    }
    if (117.68329f < temp_fv0_2) {
        *arg2 = 117.68329f - temp_fv0_2;
        return;
    }
    *arg2 = (*(f32 *)((u8 *)(arg0) + (0x1C))) - temp_fv0_2;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86102C08.s")

extern s32 func_86101964(f32, s32, f32, f32, f32, f32);
extern f32 func_86101AEC(s32, f32 *, f32 *);
extern void func_861024C8(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
void func_86102D50(void *arg0) {
    f32 x;
    f32 y;
    f32 coefficient;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 enabled;
    s32 result;
    s32 mode;
    f32 z;
    s32 flags;

    flags = *(s32 *)((u8 *)arg0 + 8);
    if (flags & 0x100) {
        coefficient = 464.8498f;
    } else if (flags & 0x200) {
        coefficient = 393.1944f;
    } else {
        coefficient = 321.53903f;
    }
    if (flags & 0x800) {
        enabled = 0;
    } else {
        enabled = 1;
    }
    if (flags & 0x10) {
        a = 1.0f;
        b = 0.0f;
        c = 1.0f;
        d = 1.0f;
    } else if (flags & 0x40) {
        a = 1.0f;
        b = 1.0f;
        c = 2.0f;
        d = 1.0f;
    } else if (flags & 0x80) {
        a = 1.0f;
        b = 1.0f;
        c = 1.0f;
        d = 2.0f;
    } else {
        a = 1.0f;
        b = 1.0f;
        c = 1.0f;
        d = 1.0f;
    }
    if (flags & 8) {
        mode = 1;
    } else {
        mode = 0;
    }
    result = func_86101964(coefficient, enabled, a, b, c, d);
    z = func_86101AEC(result, &x, &y);
    func_861024C8(arg0, x, y, z, mode);
}

extern void func_86102720(void *, void *, f32);
extern void func_86102908(void *, void *);
extern void func_86102C08(void *, s32);
extern void func_86102D50(void *);
extern void * D_87F119DC;
u16 func_86102E8C(void *arg0) {
    u16 result = 0;
    f32 before_x = *(f32 *)((u8 *)D_87F119DC + 0x10);
    f32 before_y = *(f32 *)((u8 *)D_87F119DC + 0x14);
    s32 flags = *(s32 *)((u8 *)arg0 + 8);
    if (flags & 4) { func_86102720(arg0, func_86102D50, 12.0f); }
    else if (flags & 0x2000) { func_86102720(arg0, func_86102D50, 7.0f); }
    else if (flags & 2) { func_86102908(arg0, func_86102D50); }
    else if (flags & 0x1000) { func_86102C08(arg0, 0); }
    else if (flags & 1) { func_86102C08(arg0, 1); }
    else { func_86102D50(arg0); }
    if (*(f32 *)((u8 *)D_87F119DC + 0x10) < before_x) { result = 0x200; }
    else if (before_x < *(f32 *)((u8 *)D_87F119DC + 0x10)) { result = 0x100; }
    if (before_y <= *(f32 *)((u8 *)D_87F119DC + 0x14)) {
        if (*(s16 *)((u8 *)arg0 + 0x26) & 0x8000) *(f32 *)((u8 *)D_87F119DC + 0x14) = before_y;
        else result |= 0x8000;
    }
    return result;
}

extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern s32 ModelAnim_IsFinished(void *);
void func_86102FF0(void) {
    f32 speed;
    f32 y;
    f32 ratio;

    ModelAnim_SetSpeed((u8 *)D_87F119DC + 36, 0x10000);
    if (*(s32 *)((u8 *)D_87F119DC + 12) & 0x01000000) {
        ModelAnim_SetAnimation((u8 *)D_87F119DC + 36, 4);
        if (ModelAnim_IsFinished((u8 *)D_87F119DC + 36)) {
            *(s32 *)((u8 *)D_87F119DC + 12) &= 0xFEFFFFFF;
            ModelAnim_SetAnimation((u8 *)D_87F119DC + 36, 1);
        }
    } else if (*(s32 *)((u8 *)D_87F119DC + 12) & 0x80000000) {
        speed = 1.0f;
        if (*(s32 *)((u8 *)D_87F119DC + 28) >= 9) {
            *(s32 *)((u8 *)D_87F119DC + 12) &= 0x7FFFFFFF;
        }
        if ((*(s32 *)((u8 *)D_87F119DC + 108) >> 16) == 0) {
            func_861000B8(D_87F119DC, 3843);
        }
        y = *(f32 *)((u8 *)D_87F119DC + 20);
        if (y > 0.0f) {
            ratio = y / 15.0f;
            speed += 2.0f * ratio;
        }
        ModelAnim_SetSpeed((u8 *)D_87F119DC + 36, (s32)(speed * 65535.0f));
    } else if (*(s32 *)((u8 *)D_87F119DC + 12) & 0x40000000) {
        ModelAnim_SetAnimation((u8 *)D_87F119DC + 36, 5);
    } else {
        ModelAnim_SetAnimation((u8 *)D_87F119DC + 36, 2);
        if ((*(s32 *)((u8 *)D_87F119DC + 108) >> 16) == 0) {
            func_861000B8(D_87F119DC, 3843);
        }
    }
}

extern void func_8610109C(void *, void *);
void func_86103194(void) {
    void **var_s0;
    s32 var_s1;

    var_s0 = (void **)(u32)(D_8610AD20 + 0x8DE0);
    for (var_s1 = 0; var_s1 != 4; var_s1 += 1) {
        if (*var_s0 != D_87F119DC) {
            func_8610109C(D_87F119DC, *var_s0);
        }
        var_s0 = (void **)((u8 *)var_s0 + 0x2C);
    }
}

extern u8 D_800CE060[];
extern s32 D_8610AD20;
extern void * D_87F119DC;
s32 func_8610320C(void) {
    s32 padding;
    s32 pressed;
    f32 movement;
    u16 result;
    u16 buttons;
    u8 *controller;

    controller = D_800CE060 + *(s32 *)((u8 *)D_87F119DC + 0x20) * 0x28;
    result = 0;
    buttons = *(u16 *)(controller + 6);
    if (buttons & 0x300) {
        movement = (f32)(((buttons & 0x100) > 0) - ((buttons & 0x200) > 0)) * 64.0f;
    } else {
        movement = *(f32 *)(controller + 0x18);
        if (movement > 64.0f) {
            movement = 64.0f;
        }
        if (movement < -64.0f) {
            movement = -64.0f;
        }
    }
    *(f32 *)((u8 *)D_87F119DC + 0x10) += movement * *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9790);
    switch (*(u8 *)((u8 *)(u32)D_8610AD20 + 0x9780)) {
    case 1:
        pressed = *(u16 *)(controller + 6) & 0x8000;
        break;
    case 0:
        pressed = *(u16 *)(controller + 8) & 0x8000;
        break;
    }
    if (pressed != 0) {
        result = 0x8000;
        *(f32 *)((u8 *)D_87F119DC + 0x14) += *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9784);
    }
    if (movement > 0.0f) {
        result |= 0x100;
    } else if (movement < 0.0f) {
        result |= 0x200;
    }
    return result;
}

extern void func_87F03884(void *, s32, void *, f32, f32, f32, s32, f32, s32);
extern u32 func_8003570C(void);
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern s32 D_8610AD20;
extern void * D_87F119DC;
void func_86103384(void)
{
    u16 angle;
    f32 factor;
    u8 *new_var;
    angle = func_8003570C() & 0xFFFF;
    factor = (f32)func_8003570C() / 4294967296.0f;
    factor = (factor + factor) + 0.5f;
    new_var = (u8 *)D_87F119DC;
    if (*(s32 *)(new_var + 0x1C) % 3 == 0) {
        func_87F03884((u8 *)(u32)D_8610AD20 + 0x9018, 1, new_var + 0x24,
            (factor * (700.0f * (0.04f * *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9768)))) * D_80088E50[angle >> 4],
            (factor * (700.0f * (0.04f * *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9768)))) * D_80087E50[angle >> 4],
            100.0f, angle - 0x3FFF, factor * 0.3f, 8);
    }
}


typedef struct {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    char pad1C[0x28];
    s16 unk44;
    char pad46[2];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
} Struct861034A8;
extern u32 func_8003570C(void);
extern s32 D_8610AD20;
void func_861034A8(Struct861034A8 *arg0, s32 arg1) {
    f32 scale;

    arg0->unk10 = ((f32)func_8003570C() / 4294967296.0f) * 100.0f;
    arg0->unk14 = ((f32)func_8003570C() / 4294967296.0f) * 100.0f;
    arg0->unk18 = 0.0f;

    switch (arg1) {
    case 0:
        arg0->unk48 = 0.0f;
        arg0->unk4C = 99.6771f;
        break;
    case 1:
        arg0->unk48 = 160.76952f;
        arg0->unk4C = 0.0f;
        break;
    case 2:
        arg0->unk48 = 0.0f;
        arg0->unk4C = -104.50018f;
        break;
    case 3:
        arg0->unk48 = -182.20546f;
        arg0->unk4C = 0.0f;
        break;
    }

    scale = 0.04f;
    arg0->unk50 = 1200.0f;
    arg0->unk54 = (*(f32 *)((u8 *)D_8610AD20 + 0x9768)) * scale;
    arg0->unk5C = (*(f32 *)((u8 *)D_8610AD20 + 0x9768)) * scale;
    arg0->unk58 = (*(f32 *)((u8 *)D_8610AD20 + 0x9768)) * scale;
    arg0->unk44 = 0x3FFF;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_8610362C.s")

extern void func_86100DA8(void *arg0);
extern s32 D_8610AD20;
extern void * D_87F119DC;
void func_86103B74(void) {
    void *temp_v1 = (void *)((u8 *)D_87F119DC + 0x24);
    *(f32 *)((u8 *)D_87F119DC + 0x14) += *(f32 *)((u8 *)(u32)D_8610AD20 + 0x97CC);
    func_86100DA8(D_87F119DC);
    { f32 scale = 0.97f;
      *(f32 *)((u8 *)temp_v1 + 0x24) += *(f32 *)((u8 *)D_87F119DC + 0x10);
      *(f32 *)((u8 *)temp_v1 + 0x28) += *(f32 *)((u8 *)D_87F119DC + 0x14);
      *(f32 *)((u8 *)temp_v1 + 0x2C) += *(f32 *)((u8 *)D_87F119DC + 0x18);
      *(f32 *)((u8 *)D_87F119DC + 0x10) *= scale;
      *(f32 *)((u8 *)D_87F119DC + 0x14) *= scale;
      *(f32 *)((u8 *)D_87F119DC + 0x18) *= scale;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86103C48.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_861044EC.s")

extern f32 D_8610ABE4;
extern f32 D_8610ABE8;
void func_861047CC(void *arg0) {
    u8 *a;
    u8 *b;
    u8 *c;
    u8 *d;
    u8 *modelEntry;

    d = ((*(s32 *)((u8 *)arg0 + 0x20)) * 0x18c) + *(u8 **)(((u8 *)(u32)D_8610AD20) + 0x8fec);
    *(u32 *)(d + 0xC) &= 0xEFFFFFFF;
    modelEntry = ((*(s32 *)((u8 *)arg0 + 0x20)) * 0x18) + *(u8 **)(((u8 *)(u32)D_8610AD20) + 0x8ff0);
    *(void **)modelEntry = (u8 *)arg0 + 0x24;
    a = ((*(s32 *)((u8 *)arg0 + 0x20)) * 0x18) + *(u8 **)(((u8 *)(u32)D_8610AD20) + 0x8ff0);
    *(f32 *)(a + 4) = 0.0f;
    *(f32 *)(a + 8) = *(f32 *)(((u8 *)(u32)D_8610AD20) + 0x9768) * D_8610ABE4 * 700.0f * D_8610ABE8;
    *(f32 *)(a + 0xC) = 0.0f;
    b = ((*(s32 *)((u8 *)arg0 + 0x20)) * 0x18c) + *(u8 **)(((u8 *)(u32)D_8610AD20) + 0x8fec);
    *(f32 *)(b + 0x54) = 1.75f;
    *(f32 *)(b + 0x58) = 1.75f;
    *(f32 *)(b + 0x5C) = 1.75f;
    c = ((*(s32 *)((u8 *)arg0 + 0x20)) * 0x18) + *(u8 **)(((u8 *)(u32)D_8610AD20) + 0x8ff0);
    c[0x12] = 0xFF;
    c[0x13] = 0xFF;
    c[0x14] = 0xFF;
    c[0x15] = 0xC8;
}

extern void func_86104B2C();
void func_861048FC(void **p) {
    void *sp1C;
    sp1C = *p;
    func_86104B2C();
    *(f32 *)((u8 *)sp1C + 0x18) = 0;
    *(f32 *)((u8 *)sp1C + 0x14) = 0;
    *(u32 *)((u8 *)sp1C + 0x0C) |= 0x02000000;
    *(f32 *)((u8 *)sp1C + 0x10) = 0;
    *(f32 *)((u8 *)sp1C + 0x50) = 0;
}

extern s32 D_8610AD20;
extern void func_861048FC(void **);

void func_86104948(void) {
    typedef struct {
        u8 pad[0xC];
        s32 flags;
    } Node;
    s32 var_s1;
    Node **var_s0;
    var_s0 = (Node **)(u32)(D_8610AD20 + 0x8DE0);
    for (var_s1 = 0; var_s1 != 4; var_s1 += 1) {
        if (!((*var_s0)->flags & 0x02000000)) {
            func_861048FC((void **)var_s0);
        }
        var_s0 = (Node **)((u8 *)var_s0 + 0x2C);
    }
}

extern s32 func_861044EC();

void func_861049C0(void) {
    void **sp1C;

    if (!(*(s32 *)((u8 *)D_87F119DC + 0xC) & 0x02000000)) {
        sp1C = (void **)((*(u8 (**)[0x2C])&D_8610AD20)[*(s32 *)((u8 *)D_87F119DC + 0x20)] + 0x8DE0);
        if (func_861044EC(sp1C) != 0) {
            func_861048FC(sp1C);
        }
    }
}

void func_861049C0_padding(void) {}

#pragma GLOBAL_ASM("hand_asm/fragments/49/func_86104A3C_rodata_manual.s")

extern u32 func_8003570C(void);
extern f32 D_8610AC08;
extern f32 D_8610AC0C;
extern f32 D_8610AC10;
extern f32 D_8610AC14;
void func_86104B2C(void *arg0) {
    (*(f32 *)((u8 *)arg0 + 0x18)) = ((f32)func_8003570C() / 4294967296.0f) * D_8610AC08 + D_8610AC0C;
    (*(f32 *)((u8 *)arg0 + 0x1C)) = ((f32)func_8003570C() / 4294967296.0f) * D_8610AC10 + D_8610AC14;
    (*(f32 *)((u8 *)arg0 + 0x20)) = 0.0f;
}

extern u32 func_8003570C(void);
extern f32 D_8610AC18;
extern f32 D_8610AC1C;
extern f32 D_8610AC20;
extern f32 D_8610AC24;
void func_86104BEC(void *arg0) {
    (*(f32 *)((u8 *)arg0 + 0x18)) = ((f32)func_8003570C() / 4294967296.0f) * D_8610AC18 + D_8610AC1C;
    (*(f32 *)((u8 *)arg0 + 0x1C)) = ((f32)func_8003570C() / 4294967296.0f) * D_8610AC20 + D_8610AC24;
    (*(f32 *)((u8 *)arg0 + 0x20)) = 0.0f;
}

#pragma GLOBAL_ASM("hand_asm/fragments/49/func_86104CAC_rodata_manual.s")

extern s32 D_8610AD20;
extern void func_87F026E8(s32, s32);

void func_86105008(void) {
    s32 var_s0;
    s32 var_s1;
    var_s0 = D_8610AD20 + 0x90;
    for (var_s1 = 0; var_s1 != 4; var_s1 += 1) {
        func_87F026E8(D_8610AD20 + 0x7C, var_s0);
        var_s0 += 0x18C;
    }
}

extern f32 func_87D005E8(f32 *, f32 *, f32 *);
extern u32 func_8003570C(void);
void func_86105070(void *arg0, f32 *arg1) {
    f32 random;
    random = (f32)func_8003570C() / 4294967296.0f;
    arg1[6] = random + random - 1.0f;
    random = (f32)func_8003570C() / 4294967296.0f;
    arg1[7] = random + random - 1.0f;
    random = (f32)func_8003570C() / 4294967296.0f;
    arg1[8] = random + 2.0f;
    func_87D005E8(&arg1[6], &arg1[7], &arg1[8]);
    arg1[6] *= 500.0f;
    arg1[7] *= 500.0f;
    arg1[8] *= 1000.0f;
}

extern f32 D_80087E50[];
s16 MathUtil_Atan2s(f32 y, f32 x);
void func_8610519C(void) {
    (*(f32 *)((u8 *)(D_87F119DC) + (0x10))) = (f32) D_80087E50[(s32) (((*(s32 *)((u8 *)(D_87F119DC) + (0x1C))) * 0xFF) & 0xFFFF) >> 4];
    (*(s16 *)((u8 *)(D_87F119DC) + (0x44))) = MathUtil_Atan2s((*(f32 *)((u8 *)(D_87F119DC) + (0x18))), (*(f32 *)((u8 *)(D_87F119DC) + (0x10))));
}

extern f32 D_8610AC38;
extern void func_800277C4(u16, u8, void *);
extern s32 D_8610AD20;
extern void *D_87F119DC;
void func_86105204(void) {
    // One 44-byte record of the array at D_8610AD20 + 0x8DE0; the D_87F119DC actor's
    // +0x20 field points at its current record, and func_86105070 rolls the x/y/z at
    // +0x18 as the next position for the actor to chase.
    typedef struct {
        u8 unk_00[0x18];
        f32 x;
        f32 y;
        f32 z;
    } Record86105204;
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec86105204;
    Record86105204 *target;
    Vec86105204 delta;
    s8 data[2];
    f32 limit;
    f32 dz;

    target = *(Record86105204 **)((u8 *)D_87F119DC + 0x20);
    delta.x = target->x - *(f32 *)((u8 *)D_87F119DC + 0x48);
    delta.z = target->z - *(f32 *)((u8 *)D_87F119DC + 0x50);
    // func_86101558 normalizes the x/z direction toward the target position.
    func_86101558(&delta.x, &delta.z);
    delta.z *= 6.0f;
    if (*(f32 *)((u8 *)D_87F119DC + 0x4C) < target->y) {
        delta.y = 5.0f;
    } else {
        delta.y = 0.0f;
    }
    // Steer the actor's velocity (+0x10): the y bias of -1.0f sinks it when the
    // target is not above, and the position (+0x48) follows the new velocity.
    *(f32 *)((u8 *)D_87F119DC + 0x10) += delta.x;
    *(f32 *)((u8 *)D_87F119DC + 0x14) += delta.y - 1.0f;
    *(f32 *)((u8 *)D_87F119DC + 0x18) += delta.z;
    *(s16 *)((u8 *)D_87F119DC + 0x44) = MathUtil_Atan2s(*(f32 *)((u8 *)D_87F119DC + 0x18), *(f32 *)((u8 *)D_87F119DC + 0x10));
    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
    *(f32 *)((u8 *)D_87F119DC + 0x50) += *(f32 *)((u8 *)D_87F119DC + 0x18);
    dz = (target->x > *(f32 *)((u8 *)D_87F119DC + 0x48)) ? (target->x - *(f32 *)((u8 *)D_87F119DC + 0x48)) : -(target->x - *(f32 *)((u8 *)D_87F119DC + 0x48));
    // FAKE: the comma expression schedules the D_8610AC38 load before the address
    // chain of D_8610AD20 + 0x9768; diff score 290 without it.
    limit = (D_8610AC38 * *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9768)) * (0, 700.0f) * 10.0f;
    if (dz < limit) {
        if (((target->y > *(f32 *)((u8 *)D_87F119DC + 0x4C)) ? (target->y - *(f32 *)((u8 *)D_87F119DC + 0x4C)) : -(target->y - *(f32 *)((u8 *)D_87F119DC + 0x4C))) < limit) {
            dz = (target->z > *(f32 *)((u8 *)D_87F119DC + 0x50)) ? (target->z - *(f32 *)((u8 *)D_87F119DC + 0x50)) : -(target->z - *(f32 *)((u8 *)D_87F119DC + 0x50));
            if (dz < limit) {
                func_86105070(D_87F119DC, (f32 *)target);
            }
        }
    }
    if ((*(s32 *)((u8 *)D_87F119DC + 0x6C) >> 16) == 0) {
        data[1] = 0;
        data[0] = 0;
        // The second argument is the record's index in the D_8610AD20 + 0x8DE0 array.
        func_800277C4(0xF03, ((s32)((u8 *)target - (u8 *)(u32)D_8610AD20) - 0x8DE0) / 44 & 0xFF, data);
    }
}

extern void func_8610519C(void);
extern void func_86105204(void);
void func_861054B0(void) {
    s32 temp_v0;
    temp_v0 = *(s32 *)((u8 *)(D_8610AD20) + (0x3C));
    switch (temp_v0) {
    case 1:
        func_8610519C();
        return;
    case 2:
        func_86105204();
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86105508.s")

#pragma GLOBAL_ASM("hand_asm/fragments/49/func_861056C0_rodata_manual.s")

extern f32 D_8610AC50;
void func_86105928(f32 *arg0) { f32 zero; f32 value; zero = 0.0f; value = D_8610AC50; arg0[4] = zero; arg0[5] = zero; arg0[6] = zero; arg0[23] = value; arg0[22] = value; arg0[21] = value; }

extern void *D_87F119D8;
extern f32 D_8610AC54;
extern f32 D_8610AC58;
extern f32 __sinf(f32);
extern void func_861056C0(void *, void *);
void func_86105950(void) {
    u8 *record;
    u8 *pool;
    s32 i;

    pool = (u8 *)(u32)D_8610AD20 + 0x8DE0;
    record = *(u8 **)((u8 *)D_87F119DC + 0x20);
    (*(s32 *)record) += 1;
    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u32)D_8610AD20 + 0x9774);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) = *(f32 *)(record + 4) + (__sinf((f32)(*(s32 *)record) * D_8610AC54) * 10.0f);
    for (i = 0; i < 4; i++) {
        func_861056C0(pool, D_87F119DC);
        pool += 44;
    }
    if (*(f32 *)((u8 *)D_87F119DC + 0x48) < D_8610AC58) {
        func_87F026E8((s32)D_87F119D8, (s32)D_87F119DC);
    }
    if (*(s32 *)((u8 *)D_87F119DC + 0xC) & 0x10000000) {
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= 16) {
            *(s32 *)((u8 *)D_87F119DC + 0xC) &= 0xEFFFFFFF;
        }
        if ((*(s32 *)((u8 *)D_87F119DC + 0x1C) % 3) != 0) {
            *(s32 *)((u8 *)D_87F119DC + 0xC4) = 159;
        } else {
            *(s32 *)((u8 *)D_87F119DC + 0xC4) = -97;
        }
    } else {
        *(s32 *)((u8 *)D_87F119DC + 0xC4) = -256;
    }
}

extern u8 D_8610A0D0[];
extern Gfx D_8610A970[];
extern void GeoRender_ApplyMaterialState(void);
extern s32 func_8004C990(s32, s32);
extern u8 * func_8004CA60(u8 *);
extern void * D_8009491C;
extern Gfx * D_800D0510;
void func_86105AD8(s32 arg0, s32 arg1) {
    void *context;
    void *temp_v0;
    s32 *countPtr;
    s32 divisor;
    s32 idx;

    if (arg0 == 5) {
        context = D_8009491C;
        temp_v0 = *(void **)((u8 *)context + 0x14);
        countPtr = *(s32 **)((u8 *)temp_v0 + 0x20);
        if (*(s32 *)((u8 *)temp_v0 + 0xC) & 0x10000000) {
            divisor = 1;
        } else {
            divisor = 3;
        }
        idx = (*countPtr % (divisor * 8)) / divisor;
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0x45, D_8610A0D0[idx])));
        gSPDisplayList(D_800D0510++, D_8610A970);
        GeoRender_ApplyMaterialState();
    }
}

extern void *func_87F025B8(void *, void *);
extern void func_86105950(void);
extern f32 D_8610AC5C;
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
void func_86105C30(f32 arg0) {
    struct NodeC30 {
        u8 pad0[0x20];
        void *data;
        u8 model[0x14];
        void *self;
        u8 pad3C[0xC];
        f32 x;
        f32 y;
        f32 z;
    };
    struct NodeC30 *obj;
    u8 *data;

    obj = func_87F025B8((u8 *)(u32)D_8610AD20 + 0xD2C, (void *)func_86105950);
    if (obj != NULL) {
        data = obj->data;
        obj->self = obj;
        func_86105928((f32 *)obj);
        obj->x = D_8610AC5C;
        obj->y = arg0;
        obj->z = 0.0f;
        *(u32 *)data = 0;
        *(f32 *)(data + 4) = arg0;
        func_8003F1DC(obj->model);
        func_8003F114(obj->model, 0, -1, *(s32 *)((u8 *)(u32)D_8610AD20 + 0x6C4));
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86105CD8.s")

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
void func_86105F68(s32 arg0, s32 arg1) {
    void *context;
    void *temp_v0;
    if (arg0 == 5) {
        context = D_8009491C;
        temp_v0 = *(void **)((u8 *)context + 0x14);
        gDPPipeSync(D_800D0510++);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0xDD, *(s32 *)temp_v0)));
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)(u32)D_8610AD20 + 0x6E0));
        GeoRender_ApplyMaterialState();
    }
}

extern u8 D_8610A10C;
extern void func_86105CD8(void);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern void * func_87F025B8(void *, void *);
extern s32 D_8610AD20;
void func_86106044(f32 arg0) {
    u8 *obj;
    s32 *data;
    void *node;

    obj = func_87F025B8((u8 *)(u32)D_8610AD20 + 0x8914, (void *)func_86105CD8);
    if (obj != NULL) {
        data = *(s32 **)(obj + 0x20);
        *(s32 **)(obj + 0x38) = data;
        node = obj + 0x24;
        *(f32 *)(obj + 0x48) = arg0;
        *(f32 *)(obj + 0x50) = -100.0f;
        *(f32 *)(obj + 0x4C) = 0.0f;
        *(f32 *)(obj + 0x54) = 3.375f;
        *(f32 *)(obj + 0x58) = 3.375f;
        *(f32 *)(obj + 0x5C) = 3.375f;
        func_8003F1DC(node);
        func_8003F114(node, 0, -1, *(s32 *)((u8 *)(u32)D_8610AD20 + 0x6C8));
        *data = D_8610A10C;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_861060F8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_861061B0.s")

extern s32 func_861060F8(void *, void *);
extern void func_861061B0(s32);
s32 func_86106504(void *arg0)
{
  s32 next; // FAKE: unused local preserves the original stack frame.
  s32 i;
  s32 result;
  u8 *other;
  u8 *entry;
  entry = ((u8 *) ((u32) D_8610AD20)) + 0x8DE0;
  result = 0;
 i = 0; do {
    other = *((u8 **) entry);
    if (((!((*((u32 *) (other + 0xC))) & 0x200000)) && (((other != (*((u8 **) (((u8 *) D_87F119DC) + 0x20)))) && (!((*((u32 *) (((u8 *) D_87F119DC) + 0xC))) & 0x1000000))) || ((*((s32 *) (((u8 *) D_87F119DC) + 0x1C))) >= 0x10))) && func_861060F8(D_87F119DC, other))
    {
      if ((*((s32 *) (((u8 *) ((u32) D_8610AD20)) + 0x3C))) == 4)
      {
        if ((++(*((s32 *) (entry + 4)))) >= 100)
        {
          *((s32 *) (entry + 4)) = 99;
        }
        func_861000B8(*((void **) entry), 0xF04);
      }
      result = 1;
      func_861061B0(*((s32 *) ((*((u8 **) entry)) + 0x20)));
      break;
    }
    i++;
    entry += 0x2C;
  }
  while (i != 4);
  return result;
}

void func_86106630(void *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    typedef struct {
        u8 pad0[0xC];
        u32 mask;
        f32 f10;
        f32 f14;
        f32 f18;
        u8 pad1[0x2C];
        f32 f48;
        f32 f4C;
        f32 f50;
        f32 f54;
        f32 f58;
    } Obj;
    Obj *o = (Obj *)arg0;
    if ((o->mask |= (u32)arg1) & 0x80000000u) {
        o->f58 = 0.0f;
        o->f54 = 0.0f;
    }
    o->f10 = arg5;
    o->f14 = arg6;
    o->f18 = arg7;
    o->f48 = arg2;
    o->f4C = arg3;
    o->f50 = arg4;
}

extern f32 D_8610AC74;
extern f32 D_8610AC78;
void func_86106688(void) {
    f32 var_fv0;

    var_fv0 = (*(f32 *)((u8 *)(D_87F119DC) + (0x4C)));
    if (D_8610AC74 < var_fv0) {
        (*(f32 *)((u8 *)(D_87F119DC) + (0x4C))) = (f32) D_8610AC74;
        (*(f32 *)((u8 *)(D_87F119DC) + (0x14))) = (f32) ((*(f32 *)((u8 *)(D_87F119DC) + (0x14))) * -1.0f);
        var_fv0 = (*(f32 *)((u8 *)(D_87F119DC) + (0x4C)));
    }
    if (var_fv0 < D_8610AC78) {
        (*(f32 *)((u8 *)(D_87F119DC) + (0x4C))) = (f32) D_8610AC78;
        (*(f32 *)((u8 *)(D_87F119DC) + (0x14))) = (f32) ((*(f32 *)((u8 *)(D_87F119DC) + (0x14))) * -1.0f);
    }
}

extern f32 D_8610AC7C;
void func_86106710(void) {
    f32 scale = D_8610AC7C;

    *(f32 *)((u8 *)D_87F119DC + 0x10) *= scale;
    *(f32 *)((u8 *)D_87F119DC + 0x14) *= scale;
    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10) + *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9774);
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
}

#pragma GLOBAL_ASM("hand_asm/fragments/49/func_86106784_rodata_manual.s")

extern void func_86106688();
extern s32 func_86106504();
void func_86106C28(void) { func_86106688(); func_86106504(D_87F119DC); }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86106C54.s")

extern u8 D_8610A890[];
extern void GeoRender_ApplyMaterialState(void);
extern s32 func_8004C990(s32, s32);
extern u8 * func_8004CA60(u8 *);
extern void * D_8009491C;
extern Gfx * D_800D0510;
void func_86106E7C(s32 arg0, s32 arg1) {
    u8 *root;
    u8 *temp_a1;
    u8 *temp_a2;
    s32 temp;
    u8 alpha;

    if (arg0 != 5) {
        return;
    }
    root = D_8009491C;
    temp_a1 = *(u8 **)(root + 0x14);
    temp_a2 = *(u8 **)(temp_a1 + 0x20);
    gDPPipeSync(D_800D0510++);
    if ((*(s32 *)(temp_a1 + 0xC) << 1) < 0) {
        alpha = (u8)((1.0f - ((f32)*(s32 *)(temp_a1 + 0x1C) / 6.0f)) * 255.0f);
    } else {
        alpha = 0xFF;
    }
    if (temp_a2 == NULL) {
        temp = 0;
    } else {
        switch (*(s32 *)(temp_a2 + 0x20)) {
        case 0:
            temp = 1;
            break;
        case 1:
            temp = 2;
            break;
        case 2:
            temp = 3;
            break;
        case 3:
            temp = 4;
            break;
        }
    }
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, alpha);
    gSPSegment(D_800D0510++, 0xF, func_8004CA60(func_8004C990(0xDE, temp)));
    gSPDisplayList(D_800D0510++, D_8610A890);
    GeoRender_ApplyMaterialState();
}

extern void func_86106C54(void);
extern void func_86106630(void *, s32, f32, f32, f32, f32, f32, f32);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern void * func_87F025B8(void *, void *);
extern s32 D_8610AD20;
void func_86107098(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    u8 *obj;

    obj = func_87F025B8((u8 *)(u32)D_8610AD20 + 0x2600, (void *)func_86106C54);
    if (obj != NULL) {
        *(u8 **)(obj + 0x38) = obj;
        func_86106630(obj, arg0, *(f32 *)&arg2, *(f32 *)&arg3, arg4, arg5, arg6, arg7);
        func_8003F1DC(obj + 0x24);
        func_8003F114(obj + 0x24, 0, -1, *(s32 *)((u8 *)(u32)D_8610AD20 + 0x6C0));
        *(s32 *)(obj + 0x20) = arg1;
    }
}

extern f32 D_80088E50[];
extern void func_86107098(s32, s32, s32, s32, f32, f32, f32, f32);
extern u32 func_8003570C(void);
extern f32 D_80087E50[];
extern s32 D_8610AD20;
extern void * D_87F119DC;
void func_86107150(s32 arg0) {
    u32 rand = func_8003570C();
    u32 rem = rand % 0xA000;
    s16 angle = (s16)(rem - 0x1FFF);
    u8 *base = (u8 *)D_87F119DC + 0xD0;
    if (*(s32 *)((u8 *)D_8610AD20 + 0x3C) == 5) {
        u32 idx = (u16)angle >> 4;
        func_86107098((s32)0x80000000, arg0, *(s32 *)(base + 0), *(s32 *)(base + 4),
                      *(f32 *)(base + 8), D_80088E50[idx] * 10.0f, D_80087E50[idx] * 10.0f, 0.0f);
    }
}

extern void func_86107150(s32 arg0);
extern s32 D_8610AD20;
extern void * D_87F119DC;
void func_86107208(void) {
    void *obj;
    s32 state;
    s32 cond;

    obj = D_87F119DC;
    *(f32 *)((u8 *)obj + 0x48) += *(f32 *)((u8 *)(u32)D_8610AD20 + 0x9774) * 0.5f;
    state = *(s32 *)((u8 *)obj + 0x6C) >> 16;
    cond = 0;
    if ((state == 8) || (state == 0x2F)) {
        if (*(f32 *)((u8 *)(u32)D_8610AD20 + 0x9774) == 0.0f) {
            cond = 1;
        }
    }
    if (cond != 0) {
        func_86107150(0);
    }
}

extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern void ModelAnim_SetAnimation(void *, s32);
extern void func_86107208(void);
extern void * func_87F025B8(void *, void *);
extern s32 D_8610AD20;
void func_861072AC(f32 arg0) {
    u8 *obj;
    f32 scale;
    u8 *node;

    obj = func_87F025B8((u8 *)(u32)D_8610AD20 + 0x8C40, (void *)func_86107208);
    if (obj != NULL) {
        node = obj + 0x24;
        func_8003F1DC(node);
        func_8003F114(node, 0, -1, *(s32 *)((u8 *)(u32)D_8610AD20 + 0x6DC));
        scale = (ModelAnim_SetAnimation(node, 0), 0.2f);
        *(f32 *)(obj + 0x5C) = scale;
        *(f32 *)(obj + 0x58) = scale;
        *(f32 *)(obj + 0x54) = scale;
        *(f32 *)(obj + 0x48) = arg0;
        *(f32 *)(obj + 0x4C) = -242.92343f;
        *(f32 *)(obj + 0x50) = -100.0f;
        *(s16 *)(obj + 0x44) = -0xFFF;
    }
}

/* mkdraft:func_86107360 begin */
extern s32 D_8610AD20;
typedef struct {
    u8 pad0000[0x9768];
    f32 f9768;
    f32 f976C;
    f32 f9770;
    f32 f9774;
    f32 f9778;
    f32 f977C;
    s8 s9780;
    s8 s9781;
    s8 s9782;
    s8 s9783;
    f32 f9784;
    f32 f9788;
    f32 f978C;
    f32 f9790;
    f32 f9794;
    f32 f9798;
    f32 f979C;
    f32 f97A0;
    f32 f97A4;
    f32 f97A8;
    f32 f97AC;
    f32 f97B0;
    s32 f97B4;
    s32 f97B8;
    s32 f97BC;
    f32 f97C0;
    f32 f97C4;
    f32 f97C8;
    f32 f97CC;
    f32 f97D0;
    f32 f97D4;
    s8 s97D8;
} Context86107360;


void func_86107360(void) {
    ((Context86107360 *)(u32)D_8610AD20)->s97D8 = 0;
    ((Context86107360 *)(u32)D_8610AD20)->f9768 = 1.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f976C = (f32) 0.1f;
    ((Context86107360 *)(u32)D_8610AD20)->f9770 = 10.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f9774 = -8.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f9778 = -50.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f977C = 50.0f;
    ((Context86107360 *)(u32)D_8610AD20)->s9780 = 0;
    ((Context86107360 *)(u32)D_8610AD20)->s9781 = 0;
    ((Context86107360 *)(u32)D_8610AD20)->s9782 = 1;
    ((Context86107360 *)(u32)D_8610AD20)->f9784 = 9.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f9788 = 0.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f978C = (f32) (((Context86107360 *)(u32)D_8610AD20)->f9784 * 100.0f);
    ((Context86107360 *)(u32)D_8610AD20)->f9790 = (f32) 0.023f;
    ((Context86107360 *)(u32)D_8610AD20)->f9794 = 0.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f9798 = 1.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f97A8 = 20.5f;
    ((Context86107360 *)(u32)D_8610AD20)->f97AC = 0.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f97B0 = 99.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f979C = (f32) 0.6f;
    ((Context86107360 *)(u32)D_8610AD20)->f97A0 = 0.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f97A4 = 99.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f97B4 = 0x4B0;
    ((Context86107360 *)(u32)D_8610AD20)->f97B8 = 0;
    ((Context86107360 *)(u32)D_8610AD20)->f97BC = 0x1A5E0;
    ((Context86107360 *)(u32)D_8610AD20)->f97CC = (f32) (-0.58f);
    ((Context86107360 *)(u32)D_8610AD20)->f97D0 = -99.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f97D4 = 99.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f97C0 = 0.5f;
    ((Context86107360 *)(u32)D_8610AD20)->f97C4 = 0.0f;
    ((Context86107360 *)(u32)D_8610AD20)->f97C8 = 1.0f;

}
/* mkdraft:func_86107360 end */

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

M2C_UNK func_87F04314(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_87F0455C();                            /* extern */

void func_861075DC(void) {
    func_87F0455C();
    func_87F04314(0, 0, 0, "SCROLL SPD", 0xC, 0, 0xA, 3, 3, D_8610AD20 + 0x9774, D_8610AD20 + 0x9778, D_8610AD20 + 0x977C);
    func_87F04314(0, 0, 1, "FLAP TYPE ", 0xC, 1, 3, 1, 0, D_8610AD20 + 0x9780, D_8610AD20 + 0x9781, D_8610AD20 + 0x9782);
    func_87F04314(0, 0, 2, "FLAP SPD  ", 0xC, 2, 0xA, 3, 3, D_8610AD20 + 0x9784, D_8610AD20 + 0x9788, D_8610AD20 + 0x978C);
    func_87F04314(0, 0, 3, "SPD X     ", 0xC, 3, 0xA, 1, 5, D_8610AD20 + 0x9790, D_8610AD20 + 0x9794, D_8610AD20 + 0x9798);
    func_87F04314(0, 0, 4, "ENEMY  BND", 0xC, 4, 0xA, 2, 3, D_8610AD20 + 0x97A8, D_8610AD20 + 0x97AC, D_8610AD20 + 0x97B0);
    func_87F04314(0, 0, 5, "PLAYER BND", 0xC, 5, 0xA, 2, 3, D_8610AD20 + 0x979C, D_8610AD20 + 0x97A0, D_8610AD20 + 0x97A4);
    func_87F04314(0, 0, 6, "GRAVITY   ", 0xC, 6, 0xA, 4, 5, D_8610AD20 + 0x97CC, D_8610AD20 + 0x97D0, D_8610AD20 + 0x97D4);
    func_87F04314(0, 0, 7, "DROP RATE ", 0xC, 7, 0xA, 1, 5, D_8610AD20 + 0x97C0, D_8610AD20 + 0x97C4, D_8610AD20 + 0x97C8);
    func_87F04314(0, 0, 8, "TIME", 0xC, 8, 6, 7, 0, D_8610AD20 + 0x97B4, D_8610AD20 + 0x97B8, D_8610AD20 + 0x97BC);
    func_87F04314(0, 0, 9, "GOLBAT SC", 0xC, 9, 0xA, 3, 3, D_8610AD20 + 0x9768, D_8610AD20 + 0x976C, D_8610AD20 + 0x9770);
}
void func_86107A10(void) {}
void func_86107A10_padding(void) {}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86107A20.s")

extern void func_87F06240(s32, s32, f32, f32, s32);
extern Gfx * D_800D0510;
void func_86107EBC(s32 arg0, s32 arg1, s32 arg2, char arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8)
{
  {
    Gfx *_g = (Gfx *) (D_800D0510++);
    _g->words.w0 = (((((unsigned int) 0xfa) & ((0x01 << 8) - 1)) << 24) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) 0) & ((0x01 << 8) - 1)) << 0));
    _g->words.w1 = ((((unsigned int) ((((unsigned int) arg3) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) arg4) & ((0x01 << 8) - 1)) << 16))) | ((unsigned int) ((((unsigned int) arg5) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) 255) & ((0x01 << 8) - 1)) << 0));
  }
  ;
  {
    Gfx *_g = (Gfx *) (D_800D0510++);
    _g->words.w0 = (unsigned int) ((((unsigned int) 0xfb) & ((0x01 << 8) - 1)) << 24);
    _g->words.w1 = (unsigned int) (((((unsigned int) ((((unsigned int) arg6) & ((0x01 << 8) - 1)) << 24)) | ((unsigned int) ((((unsigned int) arg7) & ((0x01 << 8) - 1)) << 16))) | ((unsigned int) ((((unsigned int) arg8) & ((0x01 << 8) - 1)) << 8))) | ((unsigned int) ((((unsigned int) 255) & ((0x01 << 8) - 1)) << 0)));
  }
  ;
  if (arg0 < 10) {
    func_87F06240(arg1 + 0x24, arg2 + 2, 0.57f, 0.57f, arg0 % 10);
    return;
  }
  ;
  func_87F06240(arg1 + 0x1C, arg2 + 2, 0.57f, 0.57f, arg0 / 10);
  func_87F06240(arg1 + 0x29, arg2 + 2, 0.57f, 0.57f, arg0 % 10);
}

extern void func_8004D1FC(void *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_87F0D600(void *, s32, s32, s32, f32, f32);
extern void func_87F061F0(void);
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
// Close to fragment50's func_862040AC; reads the four archive-434 texture indices as
// s32 words at 0x96F4 and ends after the four func_86107EBC calls, without the
// trailing two-digit func_87F06240 counter.
//@src/fragments/50/fragment50_266A60.c
void func_86108018(void) {
    u16 *p;
    f32 scale;
    f32 xa, ya;
    f32 bx, by;
    if (*(u8 *)((u8 *)*(void **)((u8 *)D_8610AD20 + 0) + 0x2180) != 4) {
        gSPDisplayList(D_800D0510++, D_80094E38);
        p = (u16 *)func_8004C990(434, *(s32 *)((u8 *)D_8610AD20 + 0x96F4));
        func_8004D1FC(p);
        scale = 0.8f;
        xa = (f32)p[0] * scale;
        if (xa > 0.0f) { bx = 0.5f; } else { bx = -0.5f; }
        ya = (f32)p[1] * scale;
        if (ya > 0.0f) { by = 0.5f; } else { by = -0.5f; }

        GfxRect_DrawTextured(28, 16, (s16)(s32)(bx + xa), (s16)(s32)(by + ya), 0, 0, 0x500, 0x500, 0);
        p = (u16 *)func_8004C990(434, *(s32 *)((u8 *)D_8610AD20 + 0x96F8));
        func_8004D1FC(p);

        xa = (f32)p[0] * scale;
        if (xa > 0.0f) { bx = 0.5f; } else { bx = -0.5f; }
        ya = (f32)p[1] * scale;
        if (ya > 0.0f) { by = 0.5f; } else { by = -0.5f; }

        GfxRect_DrawTextured(97, 16, (s16)(s32)(bx + xa), (s16)(s32)(by + ya), 0, 0, 0x500, 0x500, 0);
        p = (u16 *)func_8004C990(434, *(s32 *)((u8 *)D_8610AD20 + 0x96FC));
        func_8004D1FC(p);

        xa = (f32)p[0] * scale;
        if (xa > 0.0f) { bx = 0.5f; } else { bx = -0.5f; }
        ya = (f32)p[1] * scale;
        if (ya > 0.0f) { by = 0.5f; } else { by = -0.5f; }

        GfxRect_DrawTextured(166, 16, (s16)(s32)(bx + xa), (s16)(s32)(by + ya), 0, 0, 0x500, 0x500, 0);
        p = (u16 *)func_8004C990(434, *(s32 *)((u8 *)D_8610AD20 + 0x9700));
        func_8004D1FC(p);

        xa = (f32)p[0] * scale;
        if (xa > 0.0f) { bx = 0.5f; } else { bx = -0.5f; }
        ya = (f32)p[1] * scale;
        if (ya > 0.0f) { by = 0.5f; } else { by = -0.5f; }

        GfxRect_DrawTextured(235, 16, (s16)(s32)(bx + xa), (s16)(s32)(by + ya), 0, 0, 0x500, 0x500, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
        func_87F0D600((u8 *)D_8610AD20 + 4, 0, 28, 16, scale, scale);
        func_87F0D600((u8 *)D_8610AD20 + 4, 1, 97, 16, scale, scale);
        func_87F0D600((u8 *)D_8610AD20 + 4, 2, 166, 16, scale, scale);
        func_87F0D600((u8 *)D_8610AD20 + 4, 3, 235, 16, scale, scale);
        func_87F061F0();
        func_86107EBC(*(s32 *)((u8 *)D_8610AD20 + 0x8DE4), 28, 16, 0x00, 0x00, 0x9B, 0xAA, 0xF5, 0xFF);
        func_86107EBC(*(s32 *)((u8 *)D_8610AD20 + 0x8E10), 97, 16, 0x00, 0x64, 0x00, 0xC8, 0xFF, 0x9B);
        func_86107EBC(*(s32 *)((u8 *)D_8610AD20 + 0x8E3C), 166, 16, 0x78, 0x00, 0x00, 0xFF, 0xA0, 0xBE);
        func_86107EBC(*(s32 *)((u8 *)D_8610AD20 + 0x8E68), 235, 16, 0xD2, 0x5A, 0x00, 0xFF, 0xFF, 0x8C);
    }
}

extern Gfx *D_800D0510;
extern s32 D_8610AD20;
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(void *, u16);
extern void GfxImage_ClearDepthRectangle(void *, s32, s32, s32, s32);
extern s32 func_87F00930(void);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(s32);
extern void func_86108018(void);
extern void func_87F0A5BC(u8 *);
extern void func_87F07FE8(u8 *);
extern void func_87F022F0(void);
extern void func_87F01D44(void);
extern void func_87F0C88C(u8 *);
extern void func_80008648(void);
void func_861086AC(void) {
    s32 flags;
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 1);
    GfxImage_ClearDepthRectangle(&D_800D0510, 0, 0, 0x140, 0xF0);
    if (func_87F00930() == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(*(s32 *)((u8 *)D_8610AD20 + 0x38));
    if (*(s32 *)((u8 *)D_8610AD20 + 0x3C) == 5) {
        func_86108018();
        if (*(s32 *)((u8 *)D_8610AD20 + 0x97DC) != 0) {
            func_87F0A5BC((u8 *)D_8610AD20 + 0x9704);
        }
        flags = *(s32 *)((u8 *)D_8610AD20 + 0x97E0);
    } else {
        flags = *(s32 *)((u8 *)D_8610AD20 + 0x97E0);
        if (!(flags & 1)) {
            func_86108018();
            flags = *(s32 *)((u8 *)D_8610AD20 + 0x97E0);
        }
    }
    if (flags & 1) {
        func_87F07FE8((u8 *)D_8610AD20 + 0x44);
        flags = *(s32 *)((u8 *)D_8610AD20 + 0x97E0);
    }
    if (flags & 2) {
        func_87F022F0();
    }
    func_87F01D44();
    func_87F0C88C((u8 *)D_8610AD20 + 0x2C);
    func_80008648();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_8610880C.s")

extern s32 D_8610AD20;
s32 func_86108A50(s32 *arg0) {
    s32 count;
    s32 *p;
    s32 i;
    void *slot;

    count = 0;
    p = arg0;
    i = 0;
    do {
        i++;
        p++;
        p[-1] = 0;
    } while (i < 4);

    slot = (void *)((u8 *)(u32)D_8610AD20 + 0x8DE0);
    for (i = 0; i < 4; i++) {
        if (*(s32 *)((u8 *)(*(void **)slot) + 0xC) & 0x20000000) {
            *arg0++ = (s32)slot;
            count++;
        }
        slot = (void *)((u8 *)slot + 0x2C);
    }
    return count;
}

void func_86108B14(s32 *arg0, s32 *arg1) {
    s32 temp_v0;

    temp_v0 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_v0;
}

extern void func_86108B14(s32 *arg0, s32 *arg1);
void func_86108B28(u8 *arg0, s32 arg1) {
    u8 *temp_a0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s5;
    void *var_s0;
    var_s5 = 1;
    if (arg1 >= 2) {
        var_s3 = arg1 - 1;
        do {
            var_s2 = 0;
            if (var_s3 > 0) {
                var_s1 = 0;
                var_s0 = arg0;
                do {
                    temp_a0 = var_s1 + arg0;
                    if (*(s32 *)((u8 *)((u32 *)var_s0)[0] + 4) < *(s32 *)((u8 *)((u32 *)var_s0)[1] + 4)) {
                        func_86108B14((s32 *)temp_a0, (s32 *)(temp_a0 + 4));
                    }
                    var_s2 += 1; var_s1 += 4; var_s0 = (u8 *)var_s0 + 4;
                } while (var_s2 != var_s3);
            }
            var_s5 += 1; var_s3 -= 1;
        } while (var_s5 != arg1);
    }
}

void func_86108BE0(s32 arg0, u32 arg1)
{
  s32 temp_s4;
  s32 var_s0;
  u32 temp_s1;
  temp_s4 = arg1 * 3;
  var_s0 = 0;
  if (temp_s4 > 0)
  {
    do
    {
      temp_s1 = func_8003570C() % arg1;
      func_86108B14((temp_s1 * 4) + arg0, ((func_8003570C() % arg1) * 4) + arg0);
      var_s0 += 1;
    }
    while (var_s0 != (arg1 * 3));
  }
}

extern s32 D_8610A0A0[];

// Same code as func_86108EE4 with the flags table D_8610A0A0; GS marks records from
// rank 5, and when the active record's value at 4 is at least 9 and above three times
// the first record's rank, it sets flag 2 (clearing 4) on the last record.
void func_86108C90(void) {
    typedef struct { s32 pad; s32 rank; u32 flags; } Record;
    s32 count;
    s32 i;
    Record *slots[4];
    Record **p;
    s32 *active;

    count = func_86108A50((s32 *)slots);
    func_86108BE0((s32)slots, count);
    func_86108B28((u8 *)slots, count);
    p = slots;
    for (i = 0; i < count; i++, p++) {
        (*p)->flags = D_8610A0A0[i];
        if ((*p)->rank >= 5) {
            (*p)->flags |= 0x1000;
            (*p)->flags &= ~0x2006;
        }
    }
    active = func_86102630(0);
    if (active != 0 && count >= 2 && active[1] >= 9 && slots[0]->rank * 3 < active[1]) {
        slots[count - 1]->flags |= 2;
        slots[count - 1]->flags &= ~4;
    }
}
extern s32 D_8610A0B0[];
extern s32 *func_86102630(s32);
extern s32 func_86108A50(s32 *arg0);
extern void func_86108B28(u8 *arg0, s32 arg1);
extern void func_86108BE0(s32 arg0, u32 arg1);
void func_86108EE4(void) {
    typedef struct { s32 pad; s32 rank; u32 flags; } Record;
    s32 count;
    s32 i;
    Record *slots[4];
    Record **p;
    s32 *active;

    count = func_86108A50((s32 *)slots);
    func_86108BE0((s32)slots, count);
    func_86108B28((u8 *)slots, count);
    p = slots;
    for (i = 0; i < count; i++, p++) {
        (*p)->flags = D_8610A0B0[i];
        if ((*p)->rank >= 9) {
            (*p)->flags |= 0x1000;
            (*p)->flags &= ~0x2006;
        }
    }
    active = func_86102630(0);
    if (active != 0 && count >= 2 && active[1] >= 6 && slots[0]->rank < active[1]) {
        if (slots[0]->rank * 2 < active[1]) {
            slots[count - 1]->flags |= 4;
            slots[count - 1]->flags &= ~2;
        } else {
            slots[count - 1]->flags |= 2;
            slots[count - 1]->flags &= ~4;
        }
    }
}

extern s32 D_8610A0C0[];
extern s32 * func_86102630(s32);
extern s32 func_86108A50(s32 *arg0);
extern void func_86108B28(u8 *arg0, s32 arg1);
extern void func_86108BE0(s32 arg0, u32 arg1);
void func_8610916C(void) {
    s32 count;
    s32 i;
    s32 *entries[4];
    s32 **cursor;
    s32 *selected;

    count = func_86108A50((s32 *)entries);
    func_86108BE0((s32)entries, count);
    func_86108B28((u8 *)entries, count);
    cursor = entries;
    for (i = 0; i < count; i++, cursor++) {
        (*cursor)[2] = D_8610A0C0[i];
    }
    selected = func_86102630(0);
    cursor = entries;
    if ((selected != 0) && (count >= 2) && (selected[1] >= 4) && (cursor[0][1] < selected[1])) {
        if ((f32)cursor[0][1] * 2.33f < (f32)selected[1]) {
            cursor[count - 1][2] |= 4;
            cursor[count - 1][2] &= ~2;
        } else {
            cursor[count - 1][2] |= 2;
            cursor[count - 1][2] &= ~4;
        }
    }
}

extern void func_86108C90(void);
extern void func_86108EE4(void);
extern void func_8610916C(void);
void func_86109318(void) {
    s8 mode;

    mode = *(s8 *)((u8 *)(u32)D_8610AD20 + 0x97E4);
    if (mode == 0) {
        return;
    }
    switch (mode) {
    case 1:
        func_86108C90();
        break;
    case 2:
        func_86108EE4();
        break;
    case 3:
        func_8610916C();
        break;
    }
}

extern void func_87F0277C(s32);
void func_86109394(void) {
    func_87F0277C(D_8610AD20 + 0x6E8);
    func_87F0277C(D_8610AD20 + 0xD2C);
    func_87F0277C(D_8610AD20 + 0x2600);
    func_87F0277C(D_8610AD20 + 0x8914);
    func_87F0277C(D_8610AD20 + 0x8C40);
}

extern void func_800225C4(s32);
extern void func_86109318(void);
extern void func_86109394(void);
extern s32 D_8610AD20;
void func_86109404(void) {
    func_86109318();
    if (((u32)(*(u8 *)(D_8610AD20 + 0x97D9)) >> 7) != 0) {
        func_86100418();
    }
    func_86109394();
    *(s32 *)((u8 *)(u32)D_8610AD20 + 0x97B4) = *(s32 *)(D_8610AD20 + 0x97B4) - 1;
    if (*(f32 *)(D_8610AD20 + 0x9774) == 0.0f) {
        *(s32 *)(D_8610AD20 + 0x3C) = 5;
        *(s32 *)(D_8610AD20 + 0x8F20) = 0;
        func_800225C4(0x28);
        func_861008E8();
    }
}

extern void StageFade_StartFromTransparent(s32);
extern void StageContext_SetClearColor(s32);
void func_861094BC(s32 arg0) {
    (*(s32 *)((u8 *)(D_8610AD20) + (0x97E8))) = arg0;
    (*(s32 *)((u8 *)(D_8610AD20) + (0x3C))) = 7;
    (*(s32 *)((u8 *)(D_8610AD20) + (0x40))) = 8;
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(0xA);
}

extern s32 func_87F01A40(void);
extern s32 func_87F006AC(void);
extern void func_80021ED8(s32);
extern void Audio_PlayDefaultSound(s32);
extern void func_86104948(void);
extern void func_861094BC(s32 arg0);
extern s32 D_8610AD20;
void func_86109510(void) {
    s32 state;
    if (StageContext_GetFadeMode() == 0) { state = func_87F01A40(); } else { state = 2; }
    switch (state) {
    case 0:
    case 2: {
        func_86100790();
        if (func_87F006AC() == 1) { Audio_PlayDefaultSound(0xF06); }
        if (func_87F006AC() == 2) {
            *(s32 *)((u8 *)(u32)D_8610AD20 + 0x3C) = 4;
            Audio_PlayDefaultSound(0xF07); func_80021ED8(0xD); func_86104948();
        }
        break;
    }
    case 3: { func_861094BC(0); break; }
    case 4: { func_861094BC(1); break; }
    }
}

extern void func_87F006BC(void);
extern void func_8610880C(void);
extern s32 func_87F02104(void);
extern void func_87F0D5B8(void *);
extern s32 func_87F0C6F4(void *);
void func_861095EC(void) {
    if (func_87F00930() == 0) {
        func_87F006BC();
    }
    switch (*(s32 *)((u8 *)D_8610AD20 + 0x3C)) {
        case 0:
            *(s32 *)((u8 *)D_8610AD20 + 0x97E0) = 1;
            if (StageContext_GetFadeMode() == 0) {
                *(s32 *)((u8 *)D_8610AD20 + 0x3C) = 1;
            }
            break;
        case 1:
            func_8610068C();
            break;
        case 2:
            func_86100728();
            break;
        case 3:
            *(s32 *)((u8 *)D_8610AD20 + 0x97E0) = 0;
            func_86109510();
            break;
        case 4:
            switch (func_87F01A40()) {
                case 0:
                case 2:
                    func_86109404();
                    break;
                case 3:
                    func_861094BC(0);
                    break;
                case 4:
                    func_861094BC(1);
                    break;
            }
            break;
        case 5:
            func_86100A58();
            break;
        case 6:
            *(s32 *)((u8 *)D_8610AD20 + 0x97E0) = 2;
            func_86109394();
            switch (func_87F02104()) {
                case 1:
                    StageContext_SetClearColor(0);
                    *(s32 *)((u8 *)D_8610AD20 + 0x3C) = 7;
                    *(s32 *)((u8 *)D_8610AD20 + 0x40) = 0;
                    StageFade_StartFromTransparent(10);
                    break;
                case 2:
                    func_861094BC(0);
                    break;
                case 3:
                    func_861094BC(1);
                    break;
            }
            break;
        case 7:
            if (*(s32 *)((u8 *)D_8610AD20 + 0x40) == 0) {
                func_86109394();
            }
            if (StageContext_GetFadeMode() == 1) {
                *(s32 *)((u8 *)D_8610AD20 + 0x3C) = *(s32 *)((u8 *)D_8610AD20 + 0x40);
                if (*(s32 *)((u8 *)D_8610AD20 + 0x3C) == 0) {
                    func_8610880C();
                    StageFade_StartFromOpaque(10);
                }
            }
            break;
    }
    func_87F0D5B8((u8 *)D_8610AD20 + 4);
    if (func_87F0C6F4((u8 *)D_8610AD20 + 0x2C) != 0) {
        *(s32 *)((u8 *)D_8610AD20 + 0x97E8) = 3;
        *(s32 *)((u8 *)D_8610AD20 + 0x3C) = 8;
    }
}

extern void func_861086AC();
extern void func_861095EC();
void func_86109864(void) {
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        func_861095EC();
        func_861086AC();
    } while ((*(s32 *)((u8 *)(D_8610AD20) + (0x3C))) != 8);
}

extern s64 main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern u8 D_8610AD28[];
extern void func_80027EE0(u16);
extern u8 D_800CE060[];
extern u8 D_800CE100[];
extern void func_80006148(void *);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_87F09EBC(void *, s32);
extern void func_87F06EAC(s32, void *, s32);
extern void func_8004C8C0(s32);
extern void func_87F061D0(void);
extern void func_80047588(s32, s32);
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern void Asset_LoadToSegment(s32, void *, void *, s32);
extern void func_86107A20(void);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80006158(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern void func_87F0F480(s32);
extern void func_86109864(void);
extern s32 D_8610AD20;
s32 fragment49_main(s32 arg0, s32 arg1) {
    u8 *ptr;
    u8 *end;
    s32 stage;

    main_pool_push_state(0x4D59524D);
    D_8610AD20 = (s32)D_8610AD28;
    *(s32 *)D_8610AD20 = arg1;

    if (*(u8 *)(*(s32 *)D_8610AD20 + 0x2182) == 15) {
        *(s8 *)((u8 *)D_8610AD20 + 0x97E4) = 1;
    } else {
        *(s8 *)((u8 *)D_8610AD20 + 0x97E4) = *(s8 *)(*(s32 *)D_8610AD20 + 0x2181);
    }

    if (*(u8 *)(*(s32 *)D_8610AD20 + 0x2180) == 4) {
        func_80027EE0(0xFFF);
    }

    ptr = D_800CE060, end = D_800CE100;
    do {
        func_80006148(ptr);
        ptr += 0x28;
    } while (ptr != end);

    Gfx_InitDisplayListBuffers(0x20000, 0);
    stage = StageContext_Allocate(0, 0, 2, 1, 2, 1);
    func_8004C09C(0x123);
    func_87F09EBC((u8 *)D_8610AD20 + 0x9704, *(s32 *)D_8610AD20);
    func_87F06EAC(0x61, (u8 *)D_8610AD20 + 0x44, *(s32 *)D_8610AD20);
    func_8004C8C0(0x45);
    func_8004C8C0(0xDD);
    func_8004C8C0(0xDE);
    func_87F061D0();
    func_80047588(*(s32 *)((u8 *)D_8610AD20 + 0x9724) | (*(s32 *)((u8 *)D_8610AD20 + 0x4C) | 0x28), 0);
    Asset_LoadToSegment(((u32)&D_1000000 & 0x0F000000) >> 24, &D_446E30, D_447D00, 0);
    func_86107A20();
    func_80008514(stage);
    func_86109864();
    func_80008574();
    func_80006158();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D59524D);
    func_87F0F480(*(s32 *)D_8610AD20);
    func_80027EE0(0xFFE);
    return *(s32 *)((u8 *)D_8610AD20 + 0x97E8);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/49/fragment49_code/func_86109AE0.s")

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern u8 D_8610A224[];
extern void GeoRender_ApplyMaterialState(void);
typedef struct {
    u8 prim_r;
    u8 prim_g;
    u8 prim_b;
    u8 prim_a;
    u8 env_r;
    u8 env_g;
    u8 env_b;
    u8 env_a;
} Func86109D64Color;
void func_86109D64(s32 arg0, s32 arg1) {
    u8 *context;
    void *record;
    Func86109D64Color *color;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        record = *(void **)(context + 0x14);
        color = (Func86109D64Color *)(D_8610A224 + (*(u8 *)((u8 *)record + 0x10) << 3));
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0x30E7FF, 0x5FFE9E38);
        gDPSetPrimColor(D_800D0510++, 0, 0, color->prim_r, color->prim_g, color->prim_b, color->prim_a);
        gDPSetEnvColor(D_800D0510++, color->env_r, color->env_g, color->env_b, color->env_a);
        gSPSegment(D_800D0510++, 0xF, *(void **)((u8 *)record + 4));
        gSPDisplayList(D_800D0510++, *(void **)record);
        GeoRender_ApplyMaterialState();
    }
}

extern void *func_87F025B8(void *, void *);
extern void func_80037E3C(void *, void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_86109AE0(void);
void func_86109EAC(void *arg0, s32 arg1, s32 arg2) {
    u8 *result;
    u8 *entry;
    s32 table_value;

    result = func_87F025B8(arg0, NULL);
    if (result == NULL) return;
    table_value = arg1 * 20;
    entry = (u8 *)arg0 + table_value;
    entry[0x654] = arg1;
    *(s32 *)(entry + 0x64C) = arg2;
    func_80037E3C(result + 0x24, func_86109AE0, entry + 0x644);
    func_8003F1DC(result + 0x24);
    func_8003F114(result + 0x24, 0, -1, *(s32 *)((u8 *)arg0 + 0x694));
    *(f32 *)(result + 0x5C) = 2.25f;
    *(f32 *)(result + 0x58) = 2.25f;
    *(f32 *)(result + 0x54) = 2.25f;
}

extern void func_87F02684(void);
void func_86109F58(void) {
    func_87F02684();
}

extern s32 main_pool_get_available(void);
extern void *MainPool_AllocState(s32, s32);
extern void *process_geo_layout(void *, void *);
extern void MainPool_FinalizeAllocation(void *);
extern void *func_87F08DF8(void *, f32, f32, s32);
extern void func_87F0252C(void *, void *, void *, s32);
extern u8 D_8610A1F0[];
extern u32 func_8003570C(void);
extern void func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);
extern u8 * func_8004CA60(u8 *);
void func_86109F78(void *arg0, void *arg1) {
    u8 *ptr;
    void *pool;
    void *obj;
    void *model;
    s32 i;

    func_8004C8C0(0x157);
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    *(void **)((u8 *)arg0 + 0x694) = process_geo_layout(pool, D_8610A1F0);
    MainPool_FinalizeAllocation(pool);
    obj = func_8004C990(0x157, 0);
    model = func_87F08DF8(obj, 0.0f, 0.0f, 0x0F000000);
    func_87F0252C(arg1, arg0, (u8 *)arg0 + 0x14, 4);
    ptr = arg0;
    for (i = 0; i < 4; i++, ptr += 0x14) {
        *(void **)(ptr + 0x644) = model;
        *(void **)(ptr + 0x648) = func_8004CA60(func_8004C990(0x157, 0));
        *(u8 *)(ptr + 0x654) = i;
        *(u32 *)(ptr + 0x650) = func_8003570C() % 0x169;
    }
}
#endif
