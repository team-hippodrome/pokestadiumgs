#include "global.h"


#ifdef VERSION_US
extern void func_8004C8C0(s32);
void func_87F061D0(void) {
    func_8004C8C0(429);
}

extern Gfx *D_800D0510;
extern Gfx D_80094E78[];
void func_87F061F0(void) {
    gSPDisplayList(D_800D0510++, D_80094E78);
    gDPSetCombineLERP(D_800D0510++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0,
                     PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, PRIMITIVE, 0, TEXEL0, 0);
}

typedef struct F64TextureExtent { u16 width, height; } F64TextureExtent;
typedef struct F64RectMetrics { s16 width; s16 height; s32 stepX; s32 stepY; } F64RectMetrics;

/* mkdraft:func_87F06240 begin */
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);
extern s32 func_8004C990(s32 arg0, s32 arg1);
extern s32 func_8004D1FC(u8 *arg0);

extern s32 D_87F10CD0[];

void func_87F06240(s16 x, s16 y, f32 scaleX, f32 scaleY, s32 digit) {
    F64TextureExtent *texture;
    F64RectMetrics metrics;
    f32 widthBias;
    f32 stepX;
    f32 scaledHeight;
    f32 height;
    f32 scaledWidth;
    f32 stepY;
    f32 heightBias;
    f32 stepXBias;
    f32 stepYBias;
    s32 resourceAddress;
    digit %= 10;
    resourceAddress = func_8004C990(0x1AD, D_87F10CD0[digit]);
    texture = (F64TextureExtent *)resourceAddress;
    func_8004D1FC((u8 *) resourceAddress);
    scaledWidth = ((f32) (u32) texture->width) * scaleX;
    if (scaledWidth > 0.0f) {
        widthBias = 0.5f;
    } else {
        widthBias = -0.5f;
    }
    scaledHeight = ((f32) (u32) texture->height) * scaleY;
    height = scaledHeight;

    heightBias = (scaledHeight > 0.0f) ? 0.5f : -0.5f,
    stepX = 1024.0f / scaleX,
    stepXBias = (stepX > 0.0f) ? 0.5f : -0.5f,
    stepY = 1024.0f / scaleY,
    stepYBias = (stepY > 0.0f) ? 0.5f : -0.5f;
    metrics.width = (s16) (s32) (widthBias + scaledWidth);
    metrics.height = (s16) (s32) (heightBias + height);
    metrics.stepX = (s32) (stepXBias + stepX);
    metrics.stepY = (s32) (stepYBias + stepY);
    GfxRect_DrawTextured(x, y, (s16) metrics.width, (s16) metrics.height, 0, 0, (s16) metrics.stepX, (s16) metrics.stepY, 0);
}
/* mkdraft:func_87F06240 end */
#endif
