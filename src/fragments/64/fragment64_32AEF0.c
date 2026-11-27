#include "global.h"


#ifdef VERSION_US
typedef struct {
    u8 bpp;
    u8 pad1;
    u16 count;
    u16 step;
} F64Rec;
typedef struct {
    u16 width;
    u16 height;
    u8 fmt;
    u8 siz;
} F64Image;
extern void func_87F09120(Gfx **, u8 *, s32, s32, u32, u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_87F09504(Gfx **, u8 *, s32, s32, u32, u32, u32, u32, u32, u32, s32, s32, s32, s32, s32, s32, s32);
extern s32 main_pool_get_available(void);
extern s32 main_pool_alloc(s32, s32);
extern void main_pool_try_free(void *);
s32 func_87F08280(F64Rec *arg0, s32 arg1, F64Image *arg2, u8 *arg3, Vtx *arg4, s32 arg5) {
    s32 i;
    F64Image *img;
    s32 nverts;
    Gfx *gdl;
    Gfx *gfx;
    volatile s32 size;
    s32 nbatches;
    s32 n;

    img = arg2;
    nverts = arg0->count * 2 + 2;
    nverts += arg1 * 0; // FAKE
    n = (nverts - 2) / 30;
    nbatches = n;
    if (n * 30 < nverts - 2) {
        nbatches = n + 1;
    }
    if (arg1 * 0) {} // FAKE
    gfx = (Gfx *)main_pool_alloc(main_pool_get_available(), 0);
    gdl = gfx;
    if (arg5) {
        gSPSetGeometryMode(gdl++, G_CULL_BACK);
    }
    gSPTexture(gdl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gSPEndDisplayList(gdl++);
    size = gdl - gfx;
    gdl = gfx;
    gSPVertex(gdl++, 0, 0, 0);
    size += (gdl - gfx) * nbatches;
    gdl = gfx;
    gSP2Triangles(gdl++, 0, 0, 0, 0, 0, 0, 0, 0);
    switch (arg1) {
    case 0:
        func_87F09120(&gdl, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        gDPSetTileSize(gdl++, 0, 0, 0, 0, 0);
        break;
    case 1:
        func_87F09504(&gdl, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    }
    size += (gdl - gfx) * arg0->count;
    main_pool_try_free(gfx);
    gfx = (Gfx *)main_pool_alloc(size * 8, 0);
    gdl = gfx;
    if (arg5) {
        gSPSetGeometryMode(gdl++, G_CULL_BACK);
    }
    gSPTexture(gdl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    for (i = 0; i < nbatches; i++) {
        s32 last;

        s32 j;

        if (i < nbatches - 1) {
            n = 32;
        } else {
            n = nverts - i * 30;
    if (gdl) {} // FAKE
        }
        last = n / 2 - 1;
        gSPVertex(gdl++, arg4 + i * 30, n, 0);
        for (j = 0; j < last; j++) {
            s32 row;

            s32 rows;
    if (j * 2) {} // FAKE
    if (i) {} // FAKE
            row = arg0->step * (i * 15 + j);
            rows = arg0->step + 2;
    if (j) {} // FAKE
            if (i == nbatches - 1 && j == last - 1) {
                rows = img->height - row;
            } else if (arg1 == 1 && row > 0) {
                row--;
    if (img == 0) {} // FAKE
            }
    if (arg0->step == 0) {} // FAKE
            switch (arg1) {
            case 0:
                func_87F09120(&gdl, arg3 + (((u32)(img->width * row) * arg0->bpp) >> 1), img->fmt, img->siz,
                              img->width, rows, 1, 0, 2, 2, 0, 0, 0, 0);
                gDPSetTileSize(gdl++, 0, 0, row << 2, (img->width - 1) << 2, (row + rows - 1) << 2);
                break;
            case 1:
                func_87F09504(&gdl, arg3, img->fmt, img->siz, img->width, img->height, 0, row,
                              img->width - 1, row + rows - 1, 0, 2, 2, 0, 0, 0, 0);
                break;
            }
            row = j * 2;
            gSP2Triangles(gdl++, row, row + 2, row + 3, row, row, row + 3, row + 1, row);
        }
    }
    gSPEndDisplayList(gdl++);
    return (s32)gfx;
}


// Builds a vertex for texel (s, t) of an image whose u16 width and height are at
// image_size: position is the texel's offset from the image center, flipped in y,
// shifted by (x_offset, y_offset) and multiplied by scale; texture coordinates are
// s and t in 10.5 fixed point. The normal is (0, 0, 127) with alpha 0xFF; the signed
// reload of n[1] when copying it to n[0] matches the s8 Vtx_tn normal.
void func_87F088EC(Vtx *vtx, f32 s, f32 t, f32 x_offset, f32 y_offset, f32 scale, u16 *image_size) {
    f32 x;
    f32 y;

    x = ((s - image_size[0] * 0.5f) + x_offset) * scale;
    if (x >= 0.0f) {
        vtx->n.ob[0] = x + 0.5f;
    } else {
        vtx->n.ob[0] = x - 0.5f;
    }
    y = ((image_size[1] * 0.5f - t) + y_offset) * scale;
    if (y >= 0.0f) {
        vtx->n.ob[1] = y + 0.5f;
    } else {
        vtx->n.ob[1] = y - 0.5f;
    }
    vtx->n.ob[2] = 0;
    vtx->n.flag = 0;
    x = s * 32.0f;
    if (x >= 0.0f) {
        vtx->n.tc[0] = x + 0.5f;
    } else {
        vtx->n.tc[0] = x - 0.5f;
    }
    y = t * 32.0f;
    if (y >= 0.0f) {
        vtx->n.tc[1] = y + 0.5f;
    } else {
        vtx->n.tc[1] = y - 0.5f;
    }
    vtx->n.n[0] = vtx->n.n[1] = 0;
    vtx->n.n[2] = 127;
    vtx->n.a = 0xFF;
}

typedef struct unk_func_87F08A94 {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06[2];
    f32 unk_08;
    f32 unk_0C;
} unk_func_87F08A94;
extern s32 main_pool_alloc(s32, s32);
s32 func_87F08A94(unk_func_87F08A94 *arg0, u16 *arg1) {
    Vtx *var_s1;
    s32 var_s2;
    Vtx *var_v0;
    f32 var_f20;

    var_v0 = (Vtx *)main_pool_alloc((arg0->unk_02 + 1) * 32, 0);
    var_s1 = var_v0;
    for (var_s2 = 0; var_s2 < arg0->unk_02 + 1; var_s2++) {
        if (var_s2 < arg0->unk_02) {
            var_f20 = (u32)arg0->unk_04 * (f32)var_s2;
        } else {
            var_f20 = (u32)arg1[1];
        }
        func_87F088EC(var_s1, 0.0f, var_f20, arg0->unk_08, arg0->unk_0C, 1.0f, arg1);
        var_s1++;
        func_87F088EC(var_s1, (u32)arg1[0], var_f20, arg0->unk_08, arg0->unk_0C, 1.0f, arg1);
        var_s1++;
    }
    return (s32)var_v0;
}

void func_87F08C08(s8 *arg0, void *arg1) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((u8 *)(arg1) + (5)));
    switch (temp_v0) {                              /* irregular */
    case 0:
        *arg0 = 1;
        return;
    case 1:
        *arg0 = 2;
        return;
    case 2:
        *arg0 = 4;
        return;
    case 3:
        *arg0 = 8;
        return;
    }
}

/* mkdraft:func_87F08C68 begin */
// Sets the step (u16 at +4) and span (u16 at +2) of the record whose first byte
// func_87F08C08 fills: the step starts as 0x2000 / (arg1[0] * record) and is made even
// (minus 2, or minus 3 when odd), then the span becomes ceil(arg1[2] / step); arg1[2]
// below the step collapses to step = arg1[2], span = 1. Each field is reloaded as u16
// after its store, so the following division and multiply read the truncated value.


void func_87F08C68(s8 *arg0, void *arg1)
{
    s32 var_v0;
    s32 var_v1;

    *(u16 *) ((u8 *) arg0 + 4) = 0x2000 / ((s32) (*(u16 *) ((u8 *) arg1 + 0) * (u8) *(s8 *) ((u8 *) arg0 + 0)));
    var_v0 = (s32) *(u16 *) ((u8 *) arg1 + 2);
    var_v1 = *(u16 *) ((u8 *) arg0 + 4);
    if (var_v0 < var_v1)
    {
        *(u16 *) ((u8 *) arg0 + 4) = var_v0;
        *(s16 *) ((u8 *) arg0 + 2) = 1;
        return;
    }
    if (var_v1 % 2)
    {
        *(u16 *) ((u8 *) arg0 + 4) = var_v1 - 1;
        var_v1 = *(u16 *) ((u8 *) arg0 + 4);
    }
    *(u16 *) ((u8 *) arg0 + 4) = var_v1 - 2;
    var_v1 = *(u16 *) ((u8 *) arg0 + 4);
    *(s16 *) ((u8 *) arg0 + 2) = ((s32) *(u16 *) ((u8 *) arg1 + 2)) / var_v1;
    var_v0 = *(u16 *) ((u8 *) arg0 + 2);
    if ((var_v0 * var_v1) < ((s32) *(u16 *) ((u8 *) arg1 + 2)))
    {
        *(s16 *) ((u8 *) arg0 + 2) = (s16) (var_v0 + 1);
    }
}
/* mkdraft:func_87F08C68 end */

extern void func_87F08C68(s8 *, void *);
extern s32 func_87F08A94(unk_func_87F08A94 *, u16 *);

typedef struct {
    s8 record;
    u8 pad[7];
    f32 arg2;
    f32 arg3;
} Func87F08D6C_Local;
s32 func_87F08D6C(void *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    volatile Func87F08D6C_Local local;
    s32 result;

    if (arg0 == NULL) {
        result = 0;
    } else {
        local.arg2 = arg2;
        local.arg3 = arg3;
        func_87F08C08((s8 *)&local.record, arg0);
        func_87F08C68((s8 *)&local.record, arg0);
        result = func_87F08280((s8 *)&local.record, arg1, arg0, arg4, func_87F08A94((unk_func_87F08A94 *)&local.record, arg0), arg5);
    }
    return result;
}

extern s32 func_87F08D6C(void *, s32, f32, f32, s32, s32);
s32 func_87F08DF8(void *arg0, f32 arg1, f32 arg2, s32 arg3) {
    return func_87F08D6C(arg0, 0, arg1, arg2, arg3, 1);
}

s32 func_87F08E3C(void *arg0, s32 arg1) {
    return func_87F08D6C(arg0, 0, 0.0f, 0.0f, arg1, 1);
}

typedef struct {
    u16 first;
    u16 second;
    u8 third;
    u8 fourth;
} Func87F08E7C_Record;
s32 func_87F08E7C(u16 arg0, u16 arg1, u8 arg2, u8 arg3, s32 arg4) {
    Func87F08E7C_Record record;

    record.first = arg0;
    record.second = arg1;
    record.third = arg2;
    record.fourth = arg3;
    return func_87F08D6C(&record, 1, 0.0f, 0.0f, arg4, 1);
}

typedef struct {
    u16 first;
    u16 second;
    u8 third;
    u8 fourth;
} Func87F08EEC_Record;
void func_87F08EEC(u16 arg0, u16 arg1, u8 arg2, u8 arg3, f32 arg4, f32 arg5, s32 arg6) {
    Func87F08EEC_Record record;

    record.first = arg0;
    record.second = arg1;
    record.third = arg2;
    record.fourth = arg3;
    func_87F08D6C(&record, 1, arg4, arg5, arg6, 1);
}

s32 func_87F08F58(s32 arg0, s32 arg1) {
    return func_87F08D6C((void *)arg0, 0, 0.0f, 0.0f, arg1, 0);
}
#endif
