#include "global.h"


#ifdef VERSION_US
extern void func_8004C8C0(s32);
s32 func_8004C4B0(s32 value);
void fragment3_main(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = -1;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 4;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    func_8004C8C0(0x1C0);
    func_8004C8C0(0x15D);
    func_8004C4B0(0x27);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/3/fragment3_code/func_81A00074.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/3/fragment3_code/func_81A0022C.s")

void func_81A005F0(u8 *arg0) {
    *(s32 *)(arg0 + 0x18) = 1;
}

extern s32 StageContext_IsHighResolution(void);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

// Close to func_8260B8CC (fragment20); draws resource 349 in high resolution and 448 otherwise,
// returns early when func_8004C990 finds no resource or height is not positive, and passes the
// resource to func_8004D1FC before drawing.
void func_81A005FC(s32 x, s32 y, s32 width, s32 height) {
    s32 resource;
    s32 tile_width;
    s32 tile_height;

    if (StageContext_IsHighResolution()) {
        resource = func_8004C990(349, 0);
    } else {
        resource = func_8004C990(448, 0);
    }
    if (resource != 0 && height > 0) {
        tile_width = ((u16 *)resource)[0] / 4;
        tile_height = ((u16 *)resource)[1];
        func_8004D1FC((u8 *)resource);
        GfxRect_DrawTextured(x, y, tile_width, tile_height, 0, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + tile_width, y, width - tile_width * 2, tile_height,
                             tile_width << 5, 0, 0, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y, tile_width, tile_height,
                             tile_width << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x, y + tile_height, tile_width, height - tile_height * 2,
                             (tile_width * 2) << 5, 0, 1024, 0, 0);
        GfxRect_DrawTextured(x, y + height - tile_height, tile_width, tile_height,
                             (tile_width * 2) << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + tile_width, y + height - tile_height,
                             width - tile_width * 2, tile_height,
                             (tile_width * 3) << 5, 0, 0, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y + height - tile_height,
                             tile_width, tile_height, (tile_width * 3) << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y + tile_height,
                             tile_width, height - tile_height * 2,
                             (tile_width * 3) << 5, 0, 1024, 0, 0);
    }
}
#endif
