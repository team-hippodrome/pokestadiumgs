#include "global.h"


#ifdef VERSION_US
typedef struct { s16 x; s16 y; } Vec2s; void func_82303D60(Vec2s *arg0, Vec2s *arg1, Vec2s *arg2) { arg0->x = arg1->x + arg2->x; arg0->y = arg1->y + arg2->y; }

s32 func_82303D84(u32 arg0) {
    s32 value = arg0 % 45;
    s32 result;

    if (value < 5) {
        result = value * 255 / 5;
    } else if (value < 10) {
        result = 255;
    } else if (value < 40) {
        result = 255 - (value * 255 - 2550) / 30;
    } else {
        result = 0;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_124E40/func_82303E14.s")

/* mkdraft:func_82304260 begin */
extern void func_82303E14(u8 *);
extern s32 func_82301428(void);
extern void *Vec3f_SetComponentsDuplicate(void *, f32, f32, f32);
extern f32 D_82305D64;
extern Vec2s D_82306AF4;
extern u8 D_82306AF8[];
extern s16 D_82306DDA[];



s32 func_82304260(s32 arg0, u8 *arg1) {
    u8 padding[0xC]; /* FAKE: only claims stack so the frame is 0x50; without it the frame is 0x48 and the score is 27 */
    s32 index;
    u8 *record;
    Vec2s result;
    f32 scale;
    Vec2s *result_dst = &D_82306AF4;

    index = *(s32 *)(arg1 + 0x14);
    switch (arg0) {
    case 0:
        /* Per-instance flag array: one s16 flag per 0x2F0-byte slot. */
        *(s16 *)((u8 *)D_82306DDA + index * 0x2F0) = 0;
        break;
    case 2:
        /* Records start 8 bytes past D_82306AF8's header fields. */
        record = D_82306AF8 + index * 0x2F0 + 8;
        func_82303E14(record);
        if (*(s16 *)(record + 0x2D4) != 0) {
            /* Index-dependent id written to the renderable at arg1+0x1D. */
            if (index < *(s16 *)D_82306AF8) {
                *(u8 *)(arg1 + 0x1D) = 0xFF;
            } else {
                *(u8 *)(arg1 + 0x1D) = 0x80;
            }
            /* func_82303D60 sums two Vec2s near the end of the record. */
            func_82303D60(&result, (Vec2s *)(record + 0x2DE), (Vec2s *)(record + 0x2E2));
            /* Screen position: 320/240 is the screen centre, -579 the fixed depth. */
            Vec3f_SetComponentsDuplicate((void *)(arg1 + 0x24),
                                         (f32)result.x - 320.0f,
                                         240.0f - (f32)result.y,
                                         -579.0f);
            *(s16 *)(arg1 + 0x22) = *(s16 *)(record + 0x2DA);
            if (func_82301428() != index) {
                scale = 1.0f;
            } else {
                /* Only the entry func_82301428 reports as current updates D_82306AF4. */
                scale = D_82305D64;
                *result_dst = result;
            }
            Vec3f_SetComponentsDuplicate((void *)(arg1 + 0x30), scale, scale, scale);
        }
        break;
    }
    return 0;
}
/* mkdraft:func_82304260 end */

/* mkdraft:func_823043D8 begin */
extern s32 func_82301428(void);
extern void *Vec3f_SetComponentsDuplicate(void *, f32, f32, f32);
extern void func_82303D60(Vec2s *arg0, Vec2s *arg1, Vec2s *arg2);
extern f32 D_82305D68;
extern u8 D_82306AF8[];
extern u16 D_82306AEC;
// The return type must also be applied to the file-scope declaration at
// fragment19_124E40.c:30; Vec3f_SetComponentsDuplicate returns its first argument.


s32 func_823043D8(s32 arg0, void *arg1) {
    // 0x2F0-byte records addressed from D_82306AF8.
    typedef struct { u8 bytes[0x2F0]; } Record;
    s32 result; // FAKE: never referenced; its slot moves position to 0x34 and makes the frame 0x48. Without it the differ scores 39 (frame 0x40).
    s32 selected_index = *(s32 *)((u8 *)arg1 + 0x14);
    s32 current_index;
    Record *entry;
    Vec2s position;
    f32 scale;
    u8 *base = D_82306AF8;
    u16 *counter = &D_82306AEC;

    entry = (Record *)(base + 8 + selected_index * sizeof(Record));
    if ((arg0 != 0) && (arg0 == 2)) {
        if (selected_index == 0) {
            (*counter) += 1;
        }
        if (*(s16 *)((u8 *)entry + 0x2D4) != 0) {
            if (selected_index < *(s16 *)base) {
                *(u8 *)((u8 *)arg1 + 0x1D) = 0xFF;
            } else {
                *(u8 *)((u8 *)arg1 + 0x1D) = 0x80;
            }
            func_82303D60(&position, (Vec2s *)((u8 *)entry + 0x2DE), (Vec2s *)((u8 *)entry + 0x2E2));
            Vec3f_SetComponentsDuplicate((void *)((u8 *)arg1 + 0x24), (f32)position.x - 320.0f, 240.0f - (f32)position.y, -579.0f);
            *(s16 *)((u8 *)arg1 + 0x22) = *(s16 *)((u8 *)entry + 0x2DA);
            current_index = func_82301428();
            if (current_index != selected_index) {
                scale = 1.0f;
            } else {
                scale = D_82305D68;
            }
            Vec3f_SetComponentsDuplicate((u8 *)arg1 + 0x30, scale, scale, scale);
        }
    }
    return 0;
}
/* mkdraft:func_823043D8 end */

extern s32 func_82301428(void);
extern void *Vec3f_SetComponentsDuplicate(void *, f32, f32, f32);
extern f32 D_82305D6C;
extern Vec2s D_82306AF0;
extern Vec2s D_82306AF4;
extern u8 D_82306DD4[];
extern void func_82303D60(Vec2s *arg0, Vec2s *arg1, Vec2s *arg2);
s32 func_82304520(s32 arg0, s32 arg1) {
    u8 padding[0x14];
    Vec2s sp20;
    s32 temp_v0;

    temp_v0 = func_82301428();
    if ((arg0 != 0) && (arg0 == 2) && (*(s16 *)(D_82306DD4 + (temp_v0 * 0x2F0)) != 0)) {
        func_82303D60(&sp20, &D_82306AF0, &D_82306AF4);
        Vec3f_SetComponentsDuplicate((void *)(arg1 + 0x24),
                                      (f32)sp20.x - 320.0f,
                                      240.0f - (f32)sp20.y,
                                      -579.0f);
        Vec3f_SetComponentsDuplicate((void *)(arg1 + 0x30), D_82305D6C, D_82305D6C, D_82305D6C);
    }
    return 0;
}

extern Gfx *Gfx_AllocDisplayList(s32);
extern s32 func_80046540(s32, s32);
extern s32 func_800464F8(s32, s32);
extern void func_800459AC(u8 *, u8, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
extern Gfx *D_800D0510;
extern Gfx D_82305C20[];

typedef struct UnkStruct19 {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u16 unk_06;
} UnkStruct19;

extern u8 *func_8004CA60();

#define gDPPrim2(pkt, m, l, r, g, b, a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)); _g->words.w1 = (_SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(r, 24, 8) | _SHIFTL(a, 0, 8)); }
#define gDPEnv2(pkt, r, g, b, a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETENVCOLOR, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(r, 24, 8) | _SHIFTL(a, 0, 8)); }



void func_82304608(s32 x, s32 y, void *texture, u8 *colorTop, u8 *colorBottom, s32 alpha) {
    s32 width;
    Vtx *vertices;
    s32 rows_per_chunk;
    s32 chunk_count;
    s32 remaining_height;
    u8 *chunk;
    s32 i;
    s32 chunk_height;
    s16 dy;
    s32 right_edge;
    u8 *base;

    width = ((UnkStruct19 *) texture)->width;
    remaining_height = ((UnkStruct19 *) texture)->height;
    rows_per_chunk = func_80046540(width, 0x1000);
    chunk_count = func_800464F8(remaining_height, rows_per_chunk);
    vertices = Gfx_AllocDisplayList((chunk_count * 4) * (sizeof(Vtx)));
    base = func_8004CA60(texture);
    if (vertices != 0) {
        gSPDisplayList(D_800D0510++, D_82305C20);
        gDPPrim2(D_800D0510++, 0, 0, ((u8 *) colorTop)[0], ((u8 *) colorTop)[1], ((u8 *) colorTop)[2], 0xFF);
        gDPEnv2(D_800D0510++, ((u8 *) colorBottom)[0], ((u8 *) colorBottom)[1], ((u8 *) colorBottom)[2],
                alpha);
        for (i = 0; i < chunk_count; i++) {
            chunk_height = (remaining_height < rows_per_chunk) ? (remaining_height) : (rows_per_chunk);
            right_edge = x + width;
            chunk = base + (i * (width * rows_per_chunk));
            dy = y - chunk_height;
            Gfx_SetVertexAttributes(vertices, (s16) x, (s16) y, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 1, (s16) x, (s16) dy, 0, 0, (s16) (chunk_height << 5), 0xFF, 0xFF,
                                    0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 2, (s16) right_edge, (s16) dy, 0, (s16) (width << 5),
                                    (s16) (chunk_height << 5), 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 3, (s16) right_edge, (s16) y, 0, (s16) (width << 5), 0, 0xFF, 0xFF,
                                    0xFF, 0xFF);
            func_800459AC(chunk, ((UnkStruct19 *) texture)->format, ((UnkStruct19 *) texture)->size,
                          width, chunk_height, 1, 0, 2, 2, 0, 0, 0, 0);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            remaining_height = remaining_height - chunk_height;
            y -= chunk_height;
            vertices += 4;
        }
    }
}

/* mkdraft:func_823049A8 begin */
extern void *D_8009491C;
extern u8 D_82305BC0[];
extern u8 D_82305BD0[];
extern u8 D_82305BE8[];
extern u8 D_82305C08[];
extern u16 D_82306AEC;
extern s16 D_82306AFC;

extern s32 func_82301428(void);
extern s32 func_82303D84(u32);
extern void *func_8004C990(s32, s32);
extern void func_82304608(s32, s32, void *, u8 *, u8 *, s32);
extern void func_8003CD84(void);



s32 func_823049A8(s32 arg0, s32 arg1) {
    s32 palette_index;
    s32 blend;
    u8 *target_color;
    u8 color[3];
    u8 shade[3];
    u8 *palette;
    void *sprite;
    // FAKE: unused; IDO places color[3]/shade[3] at 0x40/0x3C only in a 0x50 frame. Score without this line: 196.
    u8 padding[12];

    if ((arg0 != 0) && (arg0 == 5)) {
        palette_index = *(s32 *)((u8 *)D_8009491C + 0x14);
        if (func_82301428() != palette_index) {
            blend = 0;
        } else {
            blend = func_82303D84(D_82306AEC);
        }
        if (D_82306AFC == 1) {
            palette = D_82305BC0 + palette_index * 3;
            target_color = D_82305BD0;
        } else {
            palette = D_82305BE8 + palette_index * 3;
            target_color = D_82305C08;
        }
        color[0] = palette[0] + ((target_color[0] - palette[0]) * blend) / 0xFF;
        color[1] = palette[1] + ((target_color[1] - palette[1]) * blend) / 0xFF;
        color[2] = palette[2] + ((target_color[2] - palette[2]) * blend) / 0xFF;
        shade[0] = (target_color[3] * blend) / 0xFF;
        shade[1] = (target_color[4] * blend) / 0xFF;
        shade[2] = (target_color[5] * blend) / 0xFF;
        sprite = func_8004C990(0x49, 2);
        func_82304608(-((s32)*(u16 *)((u8 *)sprite + 0) / 2),
                      (s32)*(u16 *)((u8 *)sprite + 2) / 2,
                      sprite, color, shade,
                      *(u8 *)((u8 *)D_8009491C + 0x1D));
        func_8003CD84();
    }
    return 0;
}
/* mkdraft:func_823049A8 end */

/* mkdraft:func_82304C88 begin */
extern u8 D_82305BCC[];
extern u8 D_82305BF4[];
extern u8 D_82305BD0[];
extern u8 D_82305C08[];
extern u8 D_82306DD0[];
extern u16 D_82306AEC;
extern s16 D_82306AFC;
extern void *D_8009491C;
extern s32 func_82301428(void);
extern s32 func_82303D84(u32);
extern void func_82304608(s32, s32, void *, u8 *, u8 *, s32);

s32 func_82304C88(s32 arg0, s32 arg1) {
    s32 sp4C;
    // FAKE: never read or written; occupies the two 4-byte slots that move sp4C from 0x44 to 0x4C and grow the frame to 0x50. Score without both: 42.
    s32 pad0;
    s32 pad1;
    s32 weight;
    u8 *prim;
    u8 *env;
    s32 max;
    u16 *coords;
    u8 sp2C[4];
    u8 sp28[4];

    if ((arg0 != 0) && (arg0 == 5)) {
        sp4C = *(s32 *)((u8 *)D_8009491C + 0x14);
        if (func_82301428() != sp4C) {
            weight = 0;
        } else {
            weight = func_82303D84(D_82306AEC);
        }
        if (D_82306AFC == 1) {
            prim = D_82305BCC;
            env = D_82305BD0;
        } else {
            prim = D_82305BF4;
            env = D_82305C08;
        }
        max = 255;
        coords = (u16 *)*(u32 *)(D_82306DD0 + (sp4C * 0x2F0));
        sp2C[0] = prim[0] + (env[0] - prim[0]) * weight / max;
        sp2C[1] = prim[1] + (env[1] - prim[1]) * weight / max;
        sp2C[2] = prim[2] + (env[2] - prim[2]) * weight / max;
        sp28[0] = env[3] * weight / max;
        sp28[1] = env[4] * weight / max;
        sp28[2] = env[5] * weight / max;
        func_82304608(-((s32)coords[0] / 2), (s32)coords[1] / 2 - 7, coords, sp2C, sp28, *(u8 *)((u8 *)D_8009491C + 0x1D));
        func_8003CD84();
    }
    return 0;
}
/* mkdraft:func_82304C88 end */

/* mkdraft:func_82304F5C begin */
extern Gfx *Gfx_AllocDisplayList(s32);
extern s32 func_80046540(s32, s32);
extern s32 func_800464F8(s32, s32);
extern void func_800459AC(u8 *, u8, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
extern Gfx *D_800D0510;
extern Gfx D_82305C40[];

// Texture data begins after this eight-byte header; same layout as TextureRenderHeader
// in src/4CC20.c.
//@src/4CC20.c
typedef struct TextureRenderHeader {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u16 unk_06;
} TextureRenderHeader;

extern u8 *func_8004CA60(TextureRenderHeader *);

// The retail words carry alpha in the low byte and pack the colour bytes as g, b, r;
// PR/gbi.h's gDPSetPrimColor and gDPSetEnvColor use r, g, b, a instead.
#define gDPSetPrimColor2(pkt, m, l, r, g, b, a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)); _g->words.w1 = (_SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(r, 24, 8) | _SHIFTL(a, 0, 8)); }
#define gDPSetEnvColor2(pkt, r, g, b, a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETENVCOLOR, 24, 8); _g->words.w1 = (unsigned int)(_SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(r, 24, 8) | _SHIFTL(a, 0, 8)); }

// Draws a width x height texture at (x, y) as horizontal strips. func_80046540 returns
// how many even rows of this width fit in one 0x1000-texel TMEM tile, and func_800464F8
// rounds the height up to that strip size, so a tall texture is drawn as one four-vertex
// quad per strip with that strip's pixels uploaded by func_800459AC.
//
// The parameters are void * to agree with this file's forward declaration of
// func_82304F5C; the texture header is reached through casts rather than through a
// typed local copy, because an extra local shifts the frame from 0xC8 to 0xCC bytes.

void func_82304F5C(s32 x, s32 y, void *texture, void *colorTop, void *colorBottom, s32 alpha) {
    s32 width;
    Vtx *vertices;
    s32 rows_per_chunk;
    s32 chunk_count;
    s32 remaining_height;
    u8 *chunk;
    s32 i;
    s32 chunk_height;
    s16 dy;
    s32 right_edge;
    u8 *base;

    width = ((TextureRenderHeader *) texture)->width;
    remaining_height = ((TextureRenderHeader *) texture)->height;
    rows_per_chunk = func_80046540(width, 0x1000);
    chunk_count = func_800464F8(remaining_height, rows_per_chunk);
    vertices = Gfx_AllocDisplayList((chunk_count * 4) * (sizeof(Vtx)));
    base = func_8004CA60(texture);
    if (vertices != 0) {
        gSPDisplayList(D_800D0510++, D_82305C40);
        gDPSetPrimColor2(D_800D0510++, 0, 0, ((u8 *) colorTop)[0], ((u8 *) colorTop)[1], ((u8 *) colorTop)[2], 0xFF);
        gDPSetEnvColor2(D_800D0510++, ((u8 *) colorBottom)[0], ((u8 *) colorBottom)[1], ((u8 *) colorBottom)[2],
                        alpha);
        for (i = 0; i < chunk_count; i++) {
            chunk_height = (remaining_height < rows_per_chunk) ? (remaining_height) : (rows_per_chunk);
            // Right edge of the strip quad. Kept as a named s32: writing x + width inline
            // in the two vertex calls that use it changes the register allocation.
            right_edge = x + width;
            chunk = base + (i * (width * rows_per_chunk));
            dy = y - chunk_height;
            Gfx_SetVertexAttributes(vertices, (s16) x, (s16) y, 0, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 1, (s16) x, (s16) dy, 0, 0, (s16) (chunk_height << 5), 0xFF, 0xFF,
                                    0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 2, (s16) right_edge, (s16) dy, 0, (s16) (width << 5),
                                    (s16) (chunk_height << 5), 0xFF, 0xFF, 0xFF, 0xFF);
            Gfx_SetVertexAttributes(vertices + 3, (s16) right_edge, (s16) y, 0, (s16) (width << 5), 0, 0xFF, 0xFF,
                                    0xFF, 0xFF);
            func_800459AC(chunk, ((TextureRenderHeader *) texture)->format, ((TextureRenderHeader *) texture)->size,
                          width, chunk_height, 1, 0, 2, 2, 0, 0, 0, 0);
            gSPVertex(D_800D0510++, vertices, 4, 0);
            gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
            remaining_height = remaining_height - chunk_height;
            y -= chunk_height;
            vertices += 4;
        }
    }
}
/* mkdraft:func_82304F5C end */

extern void GeoRender_ApplyMaterialState(void);
extern s32 func_82303D84(u32);
extern void func_82304F5C(s32, s32, void *, void *, void *, s32);
extern u8 D_82305BD0[];
extern u8 D_82305C08[];
extern u8 *D_82306AE8;
extern u16 D_82306AEC;
extern s16 D_82306AFC;
s32 func_823052FC(s32 arg0, s32 arg1) {
    u8 *var_a3;
    s32 temp_v1;
    u16 *coords;

    if ((arg0 != 0) && (arg0 == 5)) {
        temp_v1 = func_82303D84(D_82306AEC);
        if (D_82306AFC == 1) {
            var_a3 = D_82305BD0;
        } else {
            var_a3 = D_82305C08;
        }
        coords = (u16 *)D_82306AE8;
        func_82304F5C(-((s32)coords[0] / 2), (s32)coords[1] / 2, coords, var_a3, var_a3 + 3, temp_v1);
        GeoRender_ApplyMaterialState();
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_124E40/func_823053A8.s")

/* mkdraft:func_823055DC begin */
extern void func_800226C0(s32);
extern s32 D_82305C60;



void func_823055DC(u8 *arg0) {
    s32 var_s1;
    s32 var_s2;
    s32 var_s6;
    s32 var_v0;
    u8 *temp_s3;
    u8 *var_s0;

    *((s16 *) (arg0 + 6)) = (*((s16 *) (arg0 + 6))) + 1;
    var_s6 = 1;
    var_s2 = (*(s16 *) (arg0 + 6)) / D_82305C60;
    // Written after the division.  With the addition textually first, as1
    // substitutes $4 for $fp in `addiu $16,$30,8` and the saved-register copy
    // becomes `addiu s0,a0,8`; the division expands to a trapping sequence
    // that ends the propagation window, giving the target's `addiu s0,fp,8`.
    var_s0 = arg0 + 8;
    temp_s3 = (var_s2 * 0x2F0) + arg0 + 8;
    var_s1 = 0;
    // Shares the `do` line: the zero initialization then carries the loop's
    // .loc and as1 schedules it after the loop-invariant li group, at 0x5660.
    // On a line of its own it lands at 0x5650, before the li group.
    var_v0 = 0; do {
        if ((temp_s3 >= var_s0) && ((*((s16 *) (var_s0 + 0x2D4))) == 0)) {
            *((s16 *) (var_s0 + 0x2D4)) = 1;
            *((s16 *) (var_s0 + 0x2D6)) = 0;
            func_800226C0(0xAF);
            // FAKE: dead store, read only by the empty comparison below; it
            // keeps var_v0's zero initialization from being deleted, which
            // supplies the target's `or v0,zero,zero`.  Score without: 100.
            var_v0 = var_s1;
        }
        // FAKE: emits no instructions, but keeps var_s2's web loop-carried so
        // the quotient stays in s2 across the jal instead of taking v0.
        // Score without: 647.
        var_s2 ^= 0;
        var_s1 += 0x2F0;
        if ((*((s16 *) (var_s0 + 0x2D4))) != 2) {
            var_s6 = 0;
        }
        var_s0 += 0x2F0;
    } while (var_s1 != 0xBC0);
    // karodo: never taken (var_v0 is 0 or a multiple of 0x2F0); it is the
    // reader that keeps var_v0 live.
    if (var_v0 == 2) {
    }
    if (var_s6 != 0) {
        *((s16 *) (arg0 + 2)) = 2;
        *((s16 *) (arg0 + 6)) = 0;
    }
}
/* mkdraft:func_823055DC end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_124E40/func_8230570C.s")

extern void func_800226C0(s32);
void func_8230583C(u8 *arg0)
{
  s32 var_s2;
  s32 var_s6;
  u8 *var_s0;
  u8 *var_s1;
  var_s6 = 1;
  *((s16 *) (arg0 + 6)) = (*((s16 *) (arg0 + 6))) + 1;
  var_s0 = arg0 + 8;
  var_s1 = arg0;
  var_s2 = 0;
  do
  {
    if ((*((s16 *) (var_s1 + 0x2DC))) == 2)
    {
      *((s16 *) (var_s0 + 0x2D4)) = 4;
      *((s16 *) (var_s0 + 0x2D6)) = 0;
      if ((*((s16 *) (var_s0 + 0x2DC))) == 0)
      {
        func_800226C0(0xB2);
      }
 dummy_label_437240: ;
    }
    var_s2 += 0x2F0;
    var_s1 += 0x2F0;
    if ((*((s16 *) (var_s0 + 0x2D4))) != 0)
    {
      var_s6 = 0;
    }
    var_s0 += 0x2F0;
  }
  while (var_s2 != 0xBC0);
  if (var_s6 != 0)
  {
    *((s16 *) (arg0 + 2)) = 0;
    *((s16 *) (arg0 + 6)) = 0;
  }
}

extern void func_823055DC(u8 *);
extern void func_8230570C(u8 *);
extern void func_8230583C(u8 *);
extern u8 D_82306AF8[];
void func_82305914(void) {
    switch ((*(s16 *)((u8 *)(D_82306AF8) + (2)))) {      /* irregular */
    case 1:
        func_823055DC(D_82306AF8);
        return;
    case 3:
        func_8230570C(D_82306AF8);
        return;
    case 4:
        func_8230583C(D_82306AF8);
        /* fallthrough */
    case 0:
        return;
    }
}

extern s16 D_82306AFA;
void func_82305988(u16 arg0, s32 arg1) {
    s16 *flag;
    s16 *state;
    flag = &D_82306AFA;
    state = &D_82306AFC;
    switch (arg0) {
    case 1:
        *state = 1;
        break;
    case 2:
        *state = 2;
        break;
    default:
        *flag = 0;
        break;
    }
    *(u16 *)D_82306AF8 = arg1;
}

void func_823059D4(void) {
    *(s16 *)(D_82306AF8 + 2) = 1;
    *(s16 *)(D_82306AF8 + 6) = -1;
}

void func_823059F0(void) {
    *(s16 *)(D_82306AF8 + 2) = 3;
    *(s16 *)(D_82306AF8 + 6) = -1;
}

void func_82305A0C(void) {
    *(s16 *)(D_82306AF8 + 2) = 4;
    *(s16 *)(D_82306AF8 + 6) = -1;
}

extern s16 D_82306AFA;
s32 func_82305A28(void) {
    s32 result = 0;
    if (D_82306AFA == 2) result = 1;
    return result;
}

s32 func_82305A4C(void) {
    s32 result = 0;
    if (D_82306AFA == 0) result = 1;
    return result;
}
#endif
