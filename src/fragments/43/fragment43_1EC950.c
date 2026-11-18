#include "global.h"


#ifdef VERSION_US
typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
} unk_func_8220B248_018;
typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A[14];
    unk_func_8220B248_018 unk_18[16];
} unk_func_8220B248;

extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern f32 D_8AC07E28;
extern f32 D_8AC07E2C;

void func_8AC06F60(unk_func_8220B248 *arg0) {
    s32 i;
    s16 *pos = &arg0->unk_04;
    unk_func_8220B248_018 *entry = arg0->unk_18;

    for (i = 0; i < 16; i++) {
        entry->unk_00 = pos[0];
        entry->unk_04 = pos[1];
        entry->unk_08 = 0.75f;
        entry->unk_0C = 0.75f;
        entry->unk_10 = D_80087E50[(u16)(i * 0x1000 + 0x800) >> 4] * D_8AC07E28;
        entry->unk_14 = 0.0f - D_80088E50[(u16)(i * 0x1000 + 0x800) >> 4] * D_8AC07E28 + D_8AC07E2C;
        entry++;
    }
}

extern f32 D_8AC07E30;
extern s16 D_8AC07E34;

void func_8AC07378(unk_func_8220B248 *arg0) {
    unk_func_8220B248_018 *var_v0 = arg0->unk_18;
    s32 var_v1;
    s32 var_a1;
    s16 *var_v3;
    f32 var_fv0;
    f32 var_fv1;
    arg0->unk_02++;
    var_v1 = arg0->unk_02 - 10;
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    arg0->unk_08 = 255 - (var_v1 * 255) / D_8AC07E34;
    if (arg0->unk_08 > 0) {
        var_v3 = &arg0->unk_04;
        for (var_a1 = 0; var_a1 < 16; var_a1++) {
            var_fv0 = var_v0->unk_10;
            var_fv1 = var_v0->unk_14 + D_8AC07E30 * arg0->unk_02;
            var_v0->unk_00 = var_v3[0] + var_fv0 * arg0->unk_02;
            var_v0->unk_04 = var_v3[1] + var_fv1 * arg0->unk_02;
            var_v0++;
        }
    } else {
        arg0->unk_00 = 0;
    }
}

// One particle of an entry: screen position, x/y scale and velocity.
typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 scale_x;
    /* 0x0C */ f32 scale_y;
    /* 0x10 */ f32 vel_x;
    /* 0x14 */ f32 vel_y;
} Particle_8AC075A8; // size = 0x18

// func_8AC075A8 packs each triple into an RDP color command.
typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
} unk_func_8AC07AF4_00C;

typedef struct {
    s16 state;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A[2];
    unk_func_8AC07AF4_00C unk_0C;
    unk_func_8AC07AF4_00C unk_0F;
    u8 unk_12[2];
    s32 resource;
    Particle_8AC075A8 particles[16];
} Entry_8AC07A8C;
extern Entry_8AC07A8C D_8AC099D0[3];
extern s32 func_8004C990(s32, s32);

// x/y pair view of a particle's scale; func_8AC075A8 reads the scale through it for the size test.
typedef struct {
    f32 x;
    f32 y;
} Scale_8AC075A8;

extern Gfx *D_800D0510;
extern u8 D_8AC07DF0[];
extern s32 func_8004D1FC(u16 *);
#define ROUND_HALF_43(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))

// Draws each active entry's 16 particles as textured rectangles sized by the texture's width and
// height (the resource's first two u16s) times the particle scale.
void func_8AC075A8(void) {
    s32 k;
    s32 j;
    Entry_8AC07A8C *e;
    Particle_8AC075A8 *p;
    u16 *tex;
    s32 width, height;
    s16 x, y, dsdx, dtdy, x2, y2;
    f32 fw, fh;
    Scale_8AC075A8 *s;
    unk_func_8AC07AF4_00C *prim;
    unk_func_8AC07AF4_00C *env;

    e = D_8AC099D0;
    for (k = 0; k < 3; k++, e++) {
        if (e->state != 0) {
            func_8AC07378((unk_func_8220B248 *)e);
        }
        if (e->state == 0) {
            continue;
        }
        tex = (u16 *)e->resource;
        p = e->particles;
        prim = &e->unk_0C;
        env = &e->unk_0F;
        if (tex == NULL) {
            continue;
        }
        gSPDisplayList(D_800D0510++, D_8AC07DF0);
        gDPSetPrimColor(D_800D0510++, 0, 0, prim->unk_00, prim->unk_01, prim->unk_02, e->unk_08);
        gDPSetEnvColor(D_800D0510++, env->unk_00, env->unk_01, env->unk_02, 0xFF);
        func_8004D1FC(tex);
        for (j = 0; j < 16; j++, p++) {
            s = (Scale_8AC075A8 *)&p->scale_x;
            fw = (f32)(u32)tex[0] * p->scale_x;
            fh = (f32)(u32)tex[1] * p->scale_y;
            width = (s32)ROUND_HALF_43(fw);
            height = (s32)ROUND_HALF_43(fh);
            if (s->x > 0.001f && s->y > 0.001f) {
                dsdx = (s32)(1024.0f / s->x);
                dtdy = (s32)(1024.0f / s->y);
                x = (s32)(p->x - fw / 2);
                y = (s32)(p->y - fh / 2);
                x2 = x + width;
                y2 = y + height;
                gSPScisTextureRectangle(D_800D0510++, x << 2, y << 2, x2 << 2, y2 << 2, G_TX_RENDERTILE, width, height, dsdx, dtdy);
            }
        }
    }
}

void func_8AC07A8C(void) {
    Entry_8AC07A8C *entry = D_8AC099D0;
    s32 index;

    _bzero(entry, 0x4C8);
    index = 0;
    do {
        entry->state = 0;
        entry->resource = func_8004C990(0x93, 0);
        index++;
        entry++;
    } while (index != 3);
}

s32 func_8AC07AF4(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    Entry_8AC07A8C *var_s0 = D_8AC099D0;
    s32 var_v0;

    for (var_v0 = 0; var_v0 < 3; var_v0++, var_s0++) {
        if (var_s0->state == 0) {
            var_s0->state = 1;
            var_s0->unk_02 = 0;
            var_s0->unk_04 = arg0;
            var_s0->unk_06 = arg1;
            var_s0->unk_0C = *(unk_func_8AC07AF4_00C *)arg2;
            var_s0->unk_0F = *(unk_func_8AC07AF4_00C *)arg3;
            var_s0->unk_08 = 255;
            func_8AC06F60((unk_func_8220B248 *)var_s0);
            return 1;
        }
    }
    return 0;
}
#endif
