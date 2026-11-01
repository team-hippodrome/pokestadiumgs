#include "global.h"


#ifdef VERSION_US
extern s32 D_80128120;
extern u8 D_80128128[];
typedef struct Pair4EC00G { u8 bytes[4]; } Pair4EC00G;
void func_8004EC00(s32 arg0, s32 arg1) {
    s32 index;
    Pair4EC00G *entry;
    Pair4EC00G *entry2;
    index = D_80128120;
    if (index < 0x1F) {
        entry = (Pair4EC00G *)(D_80128128 + index * 4);
        entry[1] = entry[0];
        D_80128120 = index + 1;
        index = D_80128120;
    }
    entry2 = (Pair4EC00G *)(D_80128128 + index * 4);
    *(s16 *)entry2 = arg0;
    *(s16 *)((u8 *)entry2 + 2) = arg1;
}
#endif

#ifdef VERSION_US
extern s32 D_80128120; void func_8004EC5C(void) { if (D_80128120 > 0) { D_80128120--; } }
#endif

#ifdef VERSION_US
// Returns 1 if (x, y) lies within x = -640..640 and y = -479..480, else 0.
// Callers (UiPanelNode_Draw, UiImageNode_DrawUnscaled, UiTextNode_Draw) branch past their following code when it returns 0.
s32 func_8004EC7C(s16 x, s16 y) {
    s32 in_bounds = 1;

    if ((x < -640) || (x > 640)) {
        in_bounds = 0;
    } else if ((y < -479) || (y > 480)) {
        in_bounds = 0;
    }
    return in_bounds;
}
#endif

#ifdef VERSION_US
extern s32 D_80128120;
extern u8 D_80128128[];
extern void func_8004EC00();
extern void func_8004EC5C(void);
typedef void (*CallbackNode_8004ECD4)();
typedef void (*RenderNode_8004ECD4)();
extern RenderNode_8004ECD4 D_80097200[];
typedef struct Node_8004ECD4 {
    u8 type; u8 pad1; u16 flags; u8 pad4[4]; s16 x; s16 y; u8 padC[8];
    struct Node_8004ECD4 *next; u8 pad18[4]; CallbackNode_8004ECD4 callback;
} Node_8004ECD4;
typedef struct Copy4_8004ECD4 { u8 bytes[4]; } Copy4_8004ECD4;
void func_8004ECD4(void *arg0, s32 arg1, s32 arg2) {
    Node_8004ECD4 *head;
    Node_8004ECD4 *node;
    CallbackNode_8004ECD4 callback;
    Copy4_8004ECD4 pair;
    s16 *coords;
    head = *(Node_8004ECD4 **)((u8 *)arg0 + 0x18);
    node = head;
    coords = (s16 *)pair.bytes;
    if (head != NULL) {
        do {
            func_8004EC00(arg1, arg2);
            if (node->flags & 1) {
                callback = node->callback;
                if (callback != NULL) {
                    callback(1, node);
                }
                pair = *(Copy4_8004ECD4 *)(D_80128128 + D_80128120 * 4);
                coords[0] += node->x;
                coords[1] += node->y;
                D_80097200[node->type](node, coords[0], coords[1]);
            }
            func_8004EC5C();
            node = node->next;
        } while (node != head);
    }
}
#endif

#ifdef VERSION_US
extern void func_8004ECD4(void *, s32, s32);
void func_8004EE04(u8 *arg0, s32 arg1, s32 arg2) {
    arg1 += *(s16 *)(arg0 + 8);
    arg2 += *(s16 *)(arg0 + 10);
    func_8004ECD4(arg0, arg1, arg2);
}
#endif

#ifdef VERSION_US
void func_8004EE30(u8 *arg0, const u8 *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
}
#endif

#ifdef VERSION_US
void func_8004EE4C(u16 *arg0, u8 *arg1)
{
  u8 r = arg1[0];
  u8 g = arg1[1];
  u8 b = arg1[2];
  g = (g >> 3) & 0x1F;
  b = (b >> 3) & 0x1F;
  r = r >> 3;
  *arg0 = (((r << 11) | (g << 6)) | (b << 1)) | 1;
}
#endif

void func_8004EE94(void) {
}

#ifdef VERSION_US
// Same layout as TextureRenderHeader in 4CC20.c: texture data begins after this eight-byte header.
//@src/4CC20.c
typedef struct TextureRenderHeader {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u16 unk_06;
} TextureRenderHeader;

extern u8 *func_8004CA60(TextureRenderHeader *texture);
extern void func_800459AC(s32 image, s32 format, s32 size, u32 width, u32 height, s32 swapped, s32 palette, s32 cms,
                          s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);

// Draws the border of the width x height box at (x, y) from four corner textures. Each corner is drawn
// at its own size; the edges between corners are drawn with dsdx or dtdy 0, which repeats the
// corner texture's first column or row across the edge. The interior is not drawn.
// Draws nothing unless all four textures are non-NULL.
void func_8004EE9C(s32 x, s32 y, s32 width, s32 height, TextureRenderHeader *topLeft, TextureRenderHeader *topRight,
                   TextureRenderHeader *bottomLeft, TextureRenderHeader *bottomRight) {
    s32 right;
    s32 bottom;
    s16 first_corner_width;
    s16 first_corner_height;
    u8 *image;

    if ((topLeft != NULL) && (topRight != NULL) && (bottomLeft != NULL) && (bottomRight != NULL)) {
        image = func_8004CA60(topLeft);
        func_800459AC((s32)image, topLeft->format, topLeft->size, topLeft->width, topLeft->height, 1, 0, 2,
                      2, 0, 0, 0, 0);
        first_corner_width = topLeft->width;
        first_corner_height = topLeft->height;
        GfxRect_DrawTextured(x, y, first_corner_width, first_corner_height, 0, 0, 0x400, 0x400, 0);

        // Top edge, then the top-right corner.
        func_800459AC((s32)func_8004CA60(topRight), topRight->format, topRight->size, topRight->width, topRight->height, 1,
                      0, 2, 2, 0, 0, 0, 0);
        GfxRect_DrawTextured(topLeft->width + x, y, width - topLeft->width - topRight->width, topRight->height, 0, 0,
                             0, 0x400, 0);
        right = x + width;
        GfxRect_DrawTextured(right - topRight->width, y, topRight->width, topRight->height, 0, 0, 0x400, 0x400, 0);

        // Left edge, then the bottom-left corner.
        func_800459AC((s32)func_8004CA60(bottomLeft), bottomLeft->format, bottomLeft->size, bottomLeft->width,
                      bottomLeft->height, 1, 0, 2, 2, 0, 0, 0, 0);
        GfxRect_DrawTextured(x, topLeft->height + y, bottomLeft->width, height - topLeft->height - bottomLeft->height,
                             0, 0, 0x400, 0, 0);
        bottom = y + height;
        GfxRect_DrawTextured(x, bottom - bottomLeft->height, bottomLeft->width, bottomLeft->height, 0, 0, 0x400, 0x400,
                             0);

        // Bottom edge, right edge, then the bottom-right corner.
        func_800459AC((s32)func_8004CA60(bottomRight), bottomRight->format, bottomRight->size, bottomRight->width,
                      bottomRight->height, 1, 0, 2, 2, 0, 0, 0, 0);
        GfxRect_DrawTextured(bottomLeft->width + x, bottom - bottomLeft->height,
                             width - bottomLeft->width - bottomRight->width, bottomRight->height, 0, 0, 0, 0x400, 0);
        GfxRect_DrawTextured(right - bottomRight->width, topRight->height + y, bottomRight->width,
                             height - topRight->height - bottomRight->height, 0, 0, 0x400, 0, 0);
        GfxRect_DrawTextured(right - bottomRight->width, bottom - bottomRight->height, bottomRight->width,
                             bottomRight->height, 0, 0, 0x400, 0x400, 0);
    }
}

#endif

#ifdef VERSION_US
// Draws eight border pieces from one corner texture, mirrored across the box.
// The top row reverses T; the right column reverses S; edge interiors repeat one texel.
//@src/44E70.c
void Ui_DrawMirroredTextureBorder(s32 x, s32 y, s32 width, s32 height, TextureRenderHeader *texture) {
    s32 texture_s;
    s32 corner_width;
    s32 right;
    s32 vertical;

    if (texture != NULL) {
        func_800459AC((s32)func_8004CA60(texture), texture->format, texture->size,
                      texture->width, texture->height, 1, 0, 2, 2, 0, 0, 0, 0);
        vertical = (texture->height - 1) << 5;
        GfxRect_DrawTextured(x, y, texture->width, texture->height,
                             0, vertical, 1024, -1024, 0);
        corner_width = texture->width;
        texture_s = texture->width;
        texture_s = (texture_s - 1) << 5;
        vertical = (texture->height - 1) << 5;
        GfxRect_DrawTextured(corner_width + x, y, width - corner_width * 2, texture->height,
                             texture_s, vertical, 0, -1024, 0);
        corner_width = texture->width;
        texture_s = texture->width;
        right = x + width;
        texture_s = (texture_s - 1) << 5;
        vertical = (texture->height - 1) << 5;
        GfxRect_DrawTextured(right - corner_width, y, corner_width, texture->height,
                             texture_s, vertical, -1024, -1024, 0);
        // Left edge, followed by the bottom-left corner.
        GfxRect_DrawTextured(x, y + texture->height, texture->width, height - texture->height * 2,
                             0, 0, 1024, 0, 0);
        // Reuse the top-row texture coordinate for the bottom screen edge.
        vertical = y + height;
        GfxRect_DrawTextured(x, vertical - texture->height, texture->width, texture->height,
                             0, 0, 1024, 1024, 0);
        corner_width = texture->width;
        texture_s = texture->width;
        texture_s = (texture_s - 1) << 5;
        GfxRect_DrawTextured(corner_width + x, vertical - texture->height,
                             width - corner_width * 2, texture->height,
                             texture_s, 0, 0, 1024, 0);
        corner_width = texture->width;
        texture_s = texture->width;
        texture_s = (texture_s - 1) << 5;
        GfxRect_DrawTextured(right - corner_width, y + texture->height,
                             corner_width, height - texture->height * 2,
                             texture_s, 0, -1024, 0, 0);
        corner_width = texture->width;
        texture_s = texture->width;
        texture_s = (texture_s - 1) << 5;
        GfxRect_DrawTextured(right - corner_width, vertical - texture->height,
                             corner_width, texture->height,
                             texture_s, 0, -1024, 1024, 0);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_80008494(void);
extern void Gfx_FillRectRgba(s16, s16, s16, s16, u8, u8, u8, u8);
extern void Ui_DrawGradientQuad(s32, s32, s32, s32, u8 *, u8 *);
extern Gfx *D_800D0510;
extern Gfx D_80094DB8[], D_80094DE0[], D_80097218[];
extern u8 *D_800971F4;
typedef union UiPanelImageKey {
    struct { u16 archive, entry; } id;
    u32 packed;
} UiPanelImageKey;
typedef union UiPanelTint {
    u32 packed;
    u8 rgba[4];
    struct { u8 r, g, b, a; } channels;
} UiPanelTint;
extern s32 func_8004C990(s32, s32);
// Fills the panel interior, draws its texture border, then traverses child nodes.
void UiPanelNode_Draw(u8 *node, s32 x, s32 y) {
    s32 fill_value;
    u16 *key_fields;
    s32 same_keys;
    s32 fill_mode;
    s16 fill_y;
    s16 fill_x;
    UiPanelImageKey top_left;
    UiPanelImageKey top_right;
    UiPanelImageKey bottom_left;
    UiPanelImageKey bottom_right;
    u8 first_rgb[3];
    u8 second_rgb[3];
    u16 packed_fill;
    UiPanelTint tint;

    func_80008494();
    key_fields = (u16 *)&top_left;
    key_fields[0] = *(u16 *)(node + 44);
    key_fields[1] = *(u16 *)(node + 46);
    key_fields = (u16 *)&top_right;
    key_fields[0] = *(u16 *)(node + 48);
    key_fields[1] = *(u16 *)(node + 50);
    key_fields = (u16 *)&bottom_left;
    key_fields[0] = *(u16 *)(node + 52);
    key_fields[1] = *(u16 *)(node + 54);
    key_fields = (u16 *)&bottom_right;
    key_fields[0] = *(u16 *)(node + 56);
    key_fields[1] = *(u16 *)(node + 58);
    same_keys = 0;
    if (top_left.packed == top_right.packed && top_left.packed == bottom_left.packed &&
        top_left.packed == bottom_right.packed) {
        same_keys = 1;
    }
    if (node[63] != 0xFF) {
        fill_mode = 0;
    } else {
        node[67] = 0xFF;
        if (*(u32 *)(node + 64) != *(u32 *)(node + 60)) {
            fill_mode = 1;
        } else {
            fill_mode = 2;
        }
    }
    fill_x = *(s16 *)(node + 36) + x;
    fill_y = *(s16 *)(node + 38) + y;
    if (*(u16 *)(node + 2) & 2) {
        if (func_8004EC7C((s16)x, (s16)y) != 0 && *(s16 *)(node + 40) > 0 && *(s16 *)(node + 42) > 0) {
            switch (fill_mode) {
            case 0:
                gSPDisplayList(D_800D0510++, D_80094DB8);
                Gfx_FillRectRgba(fill_x, fill_y, *(s16 *)(node + 40), *(s16 *)(node + 42),
                                 node[60], node[61], node[62], node[63]);
                tint = *(UiPanelTint *)(node + 68);
                break;
            case 1:
                func_8004EE30(first_rgb, node + 60);
                func_8004EE30(second_rgb, node + 64);
                Ui_DrawGradientQuad(fill_x, fill_y, *(s16 *)(node + 40), *(s16 *)(node + 42), first_rgb, second_rgb);
                tint.packed = 0xFFFFFFFF;
                break;
            case 2:
                func_8004EE4C(&packed_fill, node + 60);
                gSPDisplayList(D_800D0510++, D_80094DE0);
                {
                    Gfx *color_packet = D_800D0510++;
                    color_packet->words.w0 = _SHIFTL(G_SETFILLCOLOR, 24, 8);
                    fill_value = packed_fill;
                    color_packet->words.w1 = ((u32)fill_value << 16) | fill_value;
                }
                {
                    Gfx *fill_packet = D_800D0510++;
                    // The RDP rectangle ends at the inclusive lower-right pixel.
                    fill_packet->words.w0 =
                        _SHIFTL(fill_y + *(s16 *)(node + 42) - 1, 2, 10) |
                        (_SHIFTL(fill_x - (1 - *(s16 *)(node + 40)), 14, 10) | _SHIFTL(G_FILLRECT, 24, 8)),
                    fill_packet->words.w1 = _SHIFTL(fill_x, 14, 10) | _SHIFTL(fill_y, 2, 10);
                }
                tint = *(UiPanelTint *)(node + 68);
                break;
            }
            gSPDisplayList(D_800D0510++, D_80097218);
            gDPSetEnvColor(D_800D0510++, tint.channels.r, tint.channels.g, tint.channels.b, tint.channels.a);
            if (!same_keys) {
                func_8004EE9C(x, y, *(s16 *)(node + 12), *(s16 *)(node + 14),
                              (TextureRenderHeader *)func_8004C990(*(u16 *)(node + 44), *(u16 *)(node + 46)),
                              (TextureRenderHeader *)func_8004C990(*(u16 *)(node + 48), *(u16 *)(node + 50)),
                              (TextureRenderHeader *)func_8004C990(*(u16 *)(node + 52), *(u16 *)(node + 54)),
                              (TextureRenderHeader *)func_8004C990(*(u16 *)(node + 56), *(u16 *)(node + 58)));
            } else {
                Ui_DrawMirroredTextureBorder(x, y, *(s16 *)(node + 12), *(s16 *)(node + 14),
                              (TextureRenderHeader *)func_8004C990(*(u16 *)(node + 52), *(u16 *)(node + 54)));
            }
        }
    }
    D_800971F4 = node;
    func_8004ECD4(node, x, y);
    D_800971F4 = NULL;
}
#endif

#ifdef VERSION_US
extern Gfx D_80097250[];
typedef struct UiImageStateColor {
    u8 r, g, b, a;
} UiImageStateColor;
// Selects the image combiner and render mode, then loads primary and environment colors.
void UiImageNode_SetRenderState(u8 *node) {
    s32 enabled;
    UiImageStateColor *primary;
    UiImageStateColor *environment;

    primary = (UiImageStateColor *)(node + 44);
    environment = (UiImageStateColor *)(node + 48);
    enabled = 1;
    switch (node[40] & 0xF) {
    case 1:
        gSPDisplayList(D_800D0510++, D_80097250);
        gDPSetCombineMode(D_800D0510++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        break;
    case 2:
        gSPDisplayList(D_800D0510++, D_80097250);
        gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0,
                          PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
        break;
    default:
        enabled = 0;
        break;
    }
    if (enabled) {
        switch (node[40] & 0xF0) {
        default:
            gDPSetRenderMode(D_800D0510++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
            break;
        case 0x10:
            gDPSetRenderMode(D_800D0510++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            break;
        case 0x20:
            gDPSetRenderMode(D_800D0510++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
            break;
        }
        gDPSetPrimColor(D_800D0510++, 0, 0, primary->r, primary->g, primary->b, primary->a);
        gDPSetEnvColor(D_800D0510++, environment->r, environment->g, environment->b, environment->a);
    }
}
#endif

#ifdef VERSION_US
extern s32 UiAnimationCursor_Step(u8 *);
extern s32 func_8004D150(s32, s32, s32, s32, s32, s32);
extern Gfx D_80094F50[];
// Resolves the animated image entry, clips it, and draws at its native dimensions.
// Palette lookup is enabled only for CI images and restored before the default display list.
//@src/4CC20.c
void UiImageNode_DrawUnscaled(u8 *node, s32 x, s32 y) {
    u16 flags;
    s32 image_address;
    s32 entry;
    Gfx *setup_packet;
    Gfx *restore_packet;
    Gfx *footer_packet;
    s32 animated_entry;
    u8 *animation;

    image_address = 0;
    entry = *(u16 *)(node + 38);
    flags = 0;
    if ((animation = *(u8 **)(node + 52)) != NULL) {
        animated_entry = UiAnimationCursor_Step(animation);
        if (animated_entry >= 0) {
            entry = animated_entry;
        } else if (animated_entry == -1) {
            entry = -1;
        }
    }
    if (entry >= 0) {
        image_address = func_8004C990(*(u16 *)(node + 36), entry);
    }
    if (node[1] & 1) {
        flags = 1;
    }
    if (node[1] & 2) {
        flags |= 2;
    }
    if (node[1] & 4) {
        flags |= 0x100;
    }
    if (image_address != 0 && func_8004EC7C((s16)x, (s16)y) != 0) {
        UiImageNode_SetRenderState(node);
        if (((u8 *)image_address)[4] == G_IM_FMT_CI) {
            setup_packet = D_800D0510++;
            gDPSetTextureLUT(setup_packet, G_TT_RGBA16);
        }
        func_8004D150(x, y, image_address, 0, flags, 0);
        if (((u8 *)image_address)[4] == G_IM_FMT_CI) {
            restore_packet = D_800D0510++;
            gDPSetTextureLUT(restore_packet, G_TT_NONE);
        }
        footer_packet = D_800D0510++;
        gSPDisplayList(footer_packet, D_80094F50);
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8004DDAC(s32);
extern Gfx D_80097278[];
// Scales a row-major grid of 16-by-16 RGBA16 tiles to the node dimensions.
// Each tile occupies 512 bytes in the image returned by the current resource pack.
//@src/4CC20.c
void UiImageNode_DrawTiled(u8 *node, s32 x, s32 y) {
    s32 row;
    s32 column;
    s32 draw_x;
    f32 scale;
    f32 rounding;
    f32 vertical_scale;
    s32 image_address;
    s32 tile_width;
    s32 tile_height;
    s32 dsdx;
    f32 unrounded;

    tile_width = node[42] * 16;
    tile_height = node[43] * 16;
    if (tile_width > 0 && tile_height > 0) {
        scale = (f32)*(s16 *)(node + 12) / tile_width;
        vertical_scale = (f32)*(s16 *)(node + 14) / tile_height;
        image_address = func_8004DDAC(*(u16 *)(node + 38));
        rounding = (16.0f * scale) > 0.0f ? 0.5f : -0.5f;
        unrounded = (16.0f * scale);
        tile_width = (s32)(rounding + unrounded);
        rounding = (16.0f * vertical_scale) > 0.0f ? 0.5f : -0.5f;
        unrounded = (16.0f * vertical_scale);
        tile_height = (s32)(rounding + unrounded);
        rounding = (1024.0f / scale) > 0.0f ? 0.5f : -0.5f;
        unrounded = 1024.0f / scale;
        dsdx = (s32)(rounding + unrounded);
        // Carry the inverse vertical texture step through the drawing loop.
        scale = 1024.0f / vertical_scale;
        rounding = scale > 0.0f ? 0.5f : -0.5f;
        gSPDisplayList(D_800D0510++, D_80097278);
        for (row = 0; row < node[43]; row++) {
            column = 0;
            if (node[42] > 0) {
                draw_x = x;
                do {
                    gDPLoadTextureBlock(D_800D0510++, image_address + (node[42] * row + column) * 512,
                                        G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                        G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    GfxRect_DrawTextured((s16)draw_x, (s16)(tile_height * row + y),
                                         (s16)tile_width, (s16)tile_height, 0, 0, (s16)dsdx,
                                         (s16)(s32)(rounding + scale), 0);
                    draw_x += tile_width;
                    column++;
                } while (column < node[42]);
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_800971F8;
extern void UiImageNode_DrawUnscaled(u8 *, s32, s32);
extern void func_8004ECD4(void *, s32, s32);
void func_800501A0(u8 *arg0, s32 arg1, s32 arg2) {
    if (*(u16 *)(arg0 + 2) & 2) {
        if (*(u8 *)(arg0 + 0x29) == 0) {
            UiImageNode_DrawUnscaled(arg0, arg1, arg2);
        } else {
            UiImageNode_DrawTiled(arg0, arg1, arg2);
        }
    }
    D_800971F8 = (s32)arg0;
    func_8004ECD4(arg0, arg1, arg2);
    D_800971F8 = 0;
}
#endif

#ifdef VERSION_US
extern void *func_8004C8A0(void *, s32, s32, s32);
extern s32 func_80049148(s32, s32, const char *, ...);
extern u8 func_80050518(u8);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004989C(s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800497E4(s32, s32, s32, s32);
extern void func_800495BC(s32, s32, const char *, ...);
extern void Font_EnableTwoCycleTexturing(void);
extern void Font_DisableTwoCycleTexturing(void);
extern void func_800499EC(void);
extern u8 *D_800971FC;
// Loads and aligns resource text, applies font spacing and optional two-color rendering,
// then traverses child nodes through func_8004ECD4.
//@src/47580.c
//@src/4CC20.c
void UiTextNode_Draw(u8 *node, s32 x, s32 y) {
    u16 *archive_key;
    u8 *secondary_color;
    u8 *primary_color;
    char buffer[512];
    u16 font_id;
    s32 two_colors;
    s32 draw_x;
    s32 alignment;
    const char *text;
    s32 text_width;

    archive_key = (u16 *)(node + 48);
    two_colors = 0;
    draw_x = x;
    if (*(u16 *)(node + 2) & 2) {
        text = func_8004C8A0(buffer, 512, archive_key[0], *(u16 *)(node + 50));
        font_id = *(u16 *)(node + 36);
        if (font_id != 0 && text != NULL) {
            text_width = func_80049148(font_id, 0, text);
            alignment = func_80050518(node[39]);
            switch (alignment) {
                case 0:
                    draw_x = x - text_width / 2;
                    break;
                case 1:
                    draw_x = x - text_width;
                    break;
            }
            if (func_8004EC7C((s16)draw_x, (s16)y) != 0) {
                func_800498C4();
                secondary_color = node + 44;
                func_800496A4(*(u16 *)(node + 36), 0);
                func_8004989C(*(s8 *)(node + 38));
                primary_color = node + 40;
                func_8004972C(primary_color[0], primary_color[1], primary_color[2], primary_color[3]);
                if (*(u32 *)secondary_color != *(u32 *)(node + 40)) {
                    two_colors = 1;
                    Font_EnableTwoCycleTexturing();
                    func_800497E4(secondary_color[0], secondary_color[1],
                                      secondary_color[2], secondary_color[3]);
                }
                func_800495BC(draw_x, y, text);
                if (two_colors) {
                    Font_DisableTwoCycleTexturing();
                }
                func_800499EC();
            }
        }
    }
    D_800971FC = node;
    func_8004ECD4(node, x, y);
    D_800971FC = NULL;
}
#endif

#ifdef VERSION_US
extern s32 D_800971F0;
extern void func_8004EE04(u8 *, s32, s32);
typedef void (*Callback_800503A4)();
void func_800503A4(u8 *arg0) {
    if (arg0 != NULL && (*(u16 *)(arg0 + 2) & 1)) {
        D_80128120 = 0;
        *(s16 *)(D_80128128 + 0) = 0;
        *(s16 *)(D_80128128 + 2) = 0;
        D_800971F0 = (s32)arg0;
        if (*(Callback_800503A4 *)(arg0 + 0x1C) != NULL) {
            (*(Callback_800503A4 *)(arg0 + 0x1C))(1, arg0);
        }
        func_8004EE04(arg0, 0, 0);
        D_800971F0 = 0;
    }
}
#endif

#ifdef VERSION_US
typedef struct TreeNode_80050428 {
    u8 pad0[4];
    s32 id;
    u8 pad8[12];
    struct TreeNode_80050428 *next;
    struct TreeNode_80050428 *children;
} TreeNode_80050428;
void *func_80050428(arg0, arg1)
TreeNode_80050428 *arg0;
s32 arg1;
{
    TreeNode_80050428 *first;
    TreeNode_80050428 *node;
    void *result;
    result = NULL;
    first = arg0->children;
    if (arg1 == arg0->id) {
        result = arg0;
    } else {
        node = first;
        if (first != NULL) {
            do {
                result = func_80050428(node, arg1);
                if (result != NULL) break;
                node = node->next;
            } while (node != first);
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
void *func_8005049C(TreeNode_80050428 *arg0, s32 arg1) {
    return func_80050428(arg0, arg1);
}
#endif

#ifdef VERSION_US
void func_800504BC(s16 *arg0) {
    if (D_800971F0 != 0) {
        arg0[0] = *(s16 *)(D_80128128 + D_80128120 * 4);
        arg0[1] = *(s16 *)(D_80128128 + D_80128120 * 4 + 2);
        return;
    }
    arg0[0] = 0;
    arg0[1] = 0;
}
#endif

#ifdef VERSION_US
u8 func_80050518(u8 arg0) {
    return arg0 & 0xF;
}
#endif

#ifdef VERSION_US
void func_80050528(u8 *arg0) {
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 4) = 1;
    *(s32 *)(arg0 + 8) = 0;
}
#endif

#ifdef VERSION_US
void func_8005053C(void *arg0, u8 *arg1) {
    if (arg0 != NULL) {
        func_80050528(arg1);
        (*(u8 **)((u8 *)(arg0) + (0x34))) = arg1;
    }
}
#endif

#ifdef VERSION_US
void func_80050578(u8 *arg0, s32 arg1) { if (arg0 != NULL) { u8 *value = *(u8 **)(arg0 + 0x34); if (value != NULL) { *(s16 *)(value + 0) = -1; *(s16 *)(value + 2) = 0; *(s32 *)(value + 8) = arg1; } } }
#endif

#ifdef VERSION_US
// Advances the entry index at duration boundaries and returns the next frame counter.
// The header stores flags, an entry count, and a 32-bit address of four-byte entries.
// UiAnimationCursor_Step stores the returned counter and reads the selected entry value.
s32 UiAnimationCursor_NextFrame(u8 *cursor) {
    u8 *animation_data;
    u8 *entry;
    s16 next_frame;

    next_frame = *(s16 *)cursor + 1;
    animation_data = *(u8 **)(cursor + 8);
    entry = (u8 *)(*(s16 *)(cursor + 2) * 4 + *(u32 *)(animation_data + 4));
    if (next_frame >= *(s16 *)entry) {
        if (*(u16 *)animation_data & 1) {
            *(s16 *)(cursor + 2) = *(s16 *)(cursor + 2) + 1;
            next_frame = 0;
            if (*(s16 *)(cursor + 2) >= *(u16 *)(*(u8 **)(cursor + 8) + 2)) {
                (*(s16 *)(cursor + 2))--;
                next_frame = *(s16 *)cursor;
            }
        } else {
            *(s16 *)(cursor + 2) = *(s16 *)(cursor + 2) + 1;
            next_frame = 0;
            if (*(s16 *)(cursor + 2) >= *(u16 *)(animation_data + 2)) {
                *(s16 *)(cursor + 2) = 0;
            }
        }
    }
    return next_frame;
}
#endif

#ifdef VERSION_US
// Updates an enabled cursor and returns its entry value, or -2 when no animation is active.
s32 UiAnimationCursor_Step(u8 *cursor) {
    s32 result = -2;

    if (*(u16 *)(cursor + 4) & 1) {
        if (*(u8 **)(cursor + 8) != NULL) {
            *(s16 *)cursor = UiAnimationCursor_NextFrame(cursor);
            result = *(s16 *)(*(s16 *)(cursor + 2) * 4 +
                             *(u32 *)(*(u8 **)(cursor + 8) + 4) + 2);
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_800506A4(u8 *arg0) {
    s32 result = 0;
    u8 *value;
    u8 *sub;
    value = *(u8 **)(arg0 + 0x34);
    if (value != NULL) {
        sub = *(u8 **)(value + 8);
        if (sub != NULL) {
            if (*(u16 *)(sub + 2) == *(s16 *)(value + 2) + 1) {
                if (*(s16 *)(*(u8 **)(sub + 4) + (*(s16 *)(value + 2) * 4)) == *(s16 *)value + 1) result = 1;
            }
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 D_801281B4;
extern u8 D_815097B0[];
extern u8 D_800CD020[];
extern void *func_80003240();
extern void __osSetFpcCsr();
extern void Sched_InitClientQueue();
extern void func_80005568();
extern void func_80004F34();
typedef void (*CallbackThread_80050700)();
void GbTower_AudioThread(s32 arg0) {
    CallbackThread_80050700 callback = (CallbackThread_80050700)func_80003240(D_815097B0);
    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(D_801281B4, 0, 1);
    func_80005568(D_801281B4);
loop:
    func_80004F34(D_801281B4);
    if (*(s16 *)(D_800CD020 + 0xA38) >= 0x15) {
        goto loop;
    }
    callback(D_801281B4);
    goto loop;
}
#endif

#ifdef VERSION_US
extern s32 D_801281B0;
extern u8 D_81509440[];
extern u8 D_81509674[];
typedef void (*CallbackThread_800507B8)();
void GbTower_EmuThread(s32 arg0) {
    CallbackThread_800507B8 callback1 = (CallbackThread_800507B8)func_80003240(D_81509440);
    CallbackThread_800507B8 callback2 = (CallbackThread_800507B8)func_80003240(D_81509674);
    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(D_801281B0, 0, 1);
    func_80005568(D_801281B0);
    callback1(D_801281B0);
    osStartThread((OSThread *)D_801281B4);
loop:
    func_80004F34(D_801281B0);
    if (*(s16 *)(D_800CD020 + 0xA38) >= 0x15) {
        goto loop;
    }
    callback2(D_801281B0);
    goto loop;
}
#endif

#ifdef VERSION_US
extern s32 main_pool_alloc(s32, s32);
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern s32 func_80064C88(void);
extern s32 func_8005A014(s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 func_80062304(u8 *);

extern s32 func_8004C09C(u16);
extern u8 *func_8004D878(u8 *, s32, u8 *);
extern void func_8004C398(void);
extern void _bzero(void *, s32);
// Builds six 40-by-40 RGBA16 party-icon slots for the GB Tower state at +0x2204.
// Deck_ReadEntries supplies the party records; func_8004D878 renders each icon.
//@src/615D0.c
//@src/4CC20.c
u8 *GbTower_LoadPartyIcons(void) {
    u8 *result;
    u8 *allocated;
    s32 port;
    u8 party[6][88];
    u8 *handle;
    s32 count;
    s32 i;
    u8 *cursor;

    allocated = (u8 *)main_pool_alloc(19200, 0);
    result = NULL;
    if (allocated != NULL) {
        port = func_80064C88();
        _bzero(allocated, 19200);
        if (port != -1) {
            main_pool_push_state(0x6769636E);
            if (func_8005A014(port) != 0) {
                handle = func_8006218C(32, port, 0, 0);
                count = Deck_ReadEntries(party[0], 6, handle);
                func_80062304(handle);
                func_8004C09C(8);
                cursor = allocated;
                for (i = 0; i < count; i++) {
                    func_8004D878(cursor, 0, party[i]);
                    cursor += 3200;
                }
                func_8004C398();
                result = allocated;
            }
            main_pool_pop_state(0x6769636E);
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 D_801281B8;
extern u8 D_81500000[];
extern u8 D_15877A0[];
extern u8 D_15B9B60[];
extern void main_pool_push_state(s32);
extern s32 main_pool_alloc(s32, s32);
extern void Fragment_Load(s32, void *, void *);
extern s32 func_80047524(void);
extern s32 func_80047558(s32, s32);
extern u8 *GbTower_LoadPartyIcons(void);
extern u8 GbTower_SetPollMask(u8);
typedef struct Copy8_80050994 { u8 bytes[8]; } Copy8_80050994;

// Same code as Pokemon Stadium's GbTower_Start (src/gb_tower_audio.c): allocates the
// emulator state (D_801281B0) and audio thread (D_801281B4), loads the fragment at
// 0x81500000, and starts both threads. GS takes both fonts from the archive returned
// by func_80047524, stores GbTower_LoadPartyIcons's result at 0x2204, and keeps the poll mask
// in D_801281B8.
void func_80050994(void *arg0) {
    s32 archive;

    main_pool_push_state(0x4742454D);
    D_801281B0 = main_pool_alloc(0x2210, 0);
    D_801281B4 = main_pool_alloc(0x21E0, 0);
    Fragment_Load((((u32)D_81500000 & 0x0FF00000) >> 20) - 0x10, D_15877A0, D_15B9B60);
    archive = func_80047524();
    *(s32 *)((u8 *)D_801281B0 + 0x21FC) = func_80047558(archive, 1);
    *(s32 *)((u8 *)D_801281B0 + 0x2200) = func_80047558(archive, 2);
    *(u8 **)((u8 *)D_801281B0 + 0x2204) = GbTower_LoadPartyIcons();
    *(Copy8_80050994 *)((u8 *)D_801281B0 + 0x2208) = *(Copy8_80050994 *)arg0;
    osCreateMesgQueue((OSMesgQueue *)((u8 *)D_801281B0 + 0x21E4), (OSMesg *)((u8 *)D_801281B0 + 0x21E0), 1);
    osCreateThread((OSThread *)D_801281B4, 10, GbTower_AudioThread, NULL, (u8 *)D_801281B4 + 0x21E0, 17);
    osCreateThread((OSThread *)D_801281B0, 8, GbTower_EmuThread, NULL, (u8 *)D_801281B0 + 0x21E0, 15);
    D_801281B8 = GbTower_SetPollMask(0);
    osStartThread((OSThread *)D_801281B0);
}
#endif

#ifdef VERSION_US

void *GbTower_RecvExitMesg(void) {
    void *sp1C;

    osRecvMesg(D_801281B0 + 0x21E4, &sp1C, 1);
    return sp1C;
}
#endif

#ifdef VERSION_US
extern u8 D_801281B8;
extern u8 GbTower_SetPollMask(u8);
extern void Display_ApplyPendingVideoMode(void);
extern void func_800055B0();
extern void main_pool_pop_state();
typedef struct Copy8_80050B40 { u8 bytes[8]; } Copy8_80050B40;
void func_80050B40(void *arg0) {
    *(Copy8_80050B40 *)arg0 = *(Copy8_80050B40 *)((u8 *)D_801281B0 + 0x2208);
    GbTower_SetPollMask(D_801281B8);
    osViBlack(1);
    Display_ApplyPendingVideoMode();
    func_800055B0(D_801281B0);
    func_800055B0(D_801281B4);
    osDestroyThread((OSThread *)D_801281B0);
    osDestroyThread((OSThread *)D_801281B4);
    main_pool_pop_state(0x4742454D);
}
#endif
