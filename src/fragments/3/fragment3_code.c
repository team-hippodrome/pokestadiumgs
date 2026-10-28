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

extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern void func_80007444(Gfx **, s32, s32, s32, s32, s32);
extern s32 StageContext_IsHighResolution(void);
extern s32 func_8004C594(s32, s32);
extern void *func_8004C874(s32, s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004989C(s32);
extern void func_80049064(s32, s32, s32, const char *);
extern void func_800499EC(void);
void func_81A005FC(s32 x, s32 y, s32 width, s32 height);

// Draws the fragment's message box: a filled rectangle (func_80007444) framed by func_81A005FC,
// sized by whether field 0x8 is -1, then the strings of text group 39 centered at x = 320 (high
// resolution) or 160 through func_80049064 mode 1. Field 0x8 = -1 draws string 9 only; 0, 2 and 3
// draw string 9, the func_8004C8A0 result or string 11 on the first line, and every value other
// than -1 and 0 adds string 12 on the second line. Field 0x14 = 0 draws nothing, and field 0x18
// (set by func_81A005F0) hides the box while field 0x8 is -1.
void func_81A0022C(void *arg0) {
    s32 pad; // FAKE: unused slot above the locals; diff score 279 without it.
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    s32 textX;
    s32 lineY[4];
    char buf[128];
    char *lines[4];

    if (*(s32 *)((u8 *)arg0 + 0x14) == 0) {
        return;
    }
    if (*(s32 *)((u8 *)arg0 + 8) == -1 && *(s32 *)((u8 *)arg0 + 0x18) != 0) {
        return;
    }
    if (StageContext_IsHighResolution()) {
        if (*(s32 *)((u8 *)arg0 + 8) == -1) {
            width = 220;
            height = 26;
            x = 210;
            y = 227;
        } else {
            width = 440;
            height = 154;
            x = 100;
            y = 163;
        }
        func_80007444(&D_800D0510, x - 16, y - 16, width + 32, height + 32, 0x6001);
        gSPDisplayList(D_800D0510++, D_80094E38);
        func_81A005FC(x - 22, y - 22, width + 44, height + 44);
        gSPDisplayList(D_800D0510++, D_80094F50);
    } else {
        if (*(s32 *)((u8 *)arg0 + 8) == -1) {
            width = 110;
            height = 12;
            x = 105;
            y = 114;
        } else {
            width = 220;
            height = 77;
            x = 50;
            y = 82;
        }
        func_80007444(&D_800D0510, x - 8, y - 8, width + 16, height + 16, 0x6001);
        gSPDisplayList(D_800D0510++, D_80094E38);
        func_81A005FC(x - 11, y - 11, width + 22, height + 22);
        gSPDisplayList(D_800D0510++, D_80094F50);
    }
    func_8004C594(1, *(s32 *)((u8 *)arg0 + 0xC) + 1);
    lines[0] = func_8004C874(39, 9);
    lines[1] = func_8004C8A0(buf, 128, 39, 10);
    lines[2] = func_8004C874(39, 11);
    lines[3] = func_8004C874(39, 12);
    func_800498C4();
    if (StageContext_IsHighResolution()) {
        func_800496A4(8, 0);
        func_8004989C(26);
        textX = 320;
        lineY[0] = lineY[1] = lineY[2] = y + 8;
        lineY[3] = y + 52;
    } else {
        func_800496A4(1, 0);
        func_8004989C(13);
        textX = 160;
        lineY[0] = lineY[1] = lineY[2] = y + 4;
        lineY[3] = y + 26;
    }
    if (*(s32 *)((u8 *)arg0 + 8) == -1) {
        func_80049064(textX, lineY[0], 1, lines[0]);
    } else {
        switch (*(s32 *)((u8 *)arg0 + 8)) {
            case 0:
                func_80049064(textX, lineY[0], 1, lines[0]);
                break;
            case 2:
                func_80049064(textX, lineY[1], 1, lines[1]);
                break;
            case 3:
                func_80049064(textX, lineY[2], 1, lines[2]);
                break;
        }
        if (*(s32 *)((u8 *)arg0 + 8) != 0) {
            func_80049064(textX, lineY[3], 1, lines[3]);
        }
    }
    func_800499EC();
}


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
