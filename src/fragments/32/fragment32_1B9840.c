#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_88308530 begin */
// Texture-page descriptor with the header func_8004CA60 expects: the compressed pixel data starts
// at the end of the header. Same layout as TextureRenderHeader in 4F800.c.
//@src/4F800.c
typedef struct unk_func_88308530 {
    /* 0x0 */ u16 width;
    /* 0x2 */ u16 height;
    /* 0x4 */ u8 format;
    /* 0x5 */ u8 size;
} unk_func_88308530;

extern void GfxRect_DrawTextured(s16, s16, s32, s32, s32, s32, s32, s32, s32);
extern void func_800459AC(s32, u8, u8, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern unk_func_88308530 *func_8004C990(s32, s32);
extern s32 func_8004CA60(void *);

// Draws one 20x20 glyph at (x, y) out of the four-column glyph atlas that func_8004C990(0x7B, 0)
// returns. `code` is a character code whose glyphs start at 0x61 ('a'): the atlas row is
// (code - 0x61) / 4 and the column is (code - 0x61) % 4, so that row's pixels start
// width * 20 bytes into the atlas. func_8830865C draws a whole string with this, one glyph per
// character and 19 pixels apart.
//@src/fragments/32/fragment32_1B9840.c


void func_88308530(s16 x, s16 y, s32 code) {
    unk_func_88308530 *texture; // 0x54
    s32 pad;                    // FAKE: unused; only this seven-local set gives the 0x58-byte
                                // frame, and with the pad removed the score is 82.
    s32 pixels;
    u16 width;
    s32 glyph;   // glyph index, spilled to 0x44 across the func_800459AC call
    s32 palette; // copy of `code`, then reused for func_800459AC's palette argument
    s32 row_offset;

    palette = code;
    texture = func_8004C990(0x7B, 0);
    pixels = func_8004CA60(texture);
    width = texture->width;
    glyph = palette - 0x61;
    palette = 0;
    row_offset = (((s32)(width * 0x14 * (glyph / 4)) / 2) * 2);
    func_800459AC(pixels + row_offset, texture->format, texture->size, width, 0x14, 1, palette, 2, 2, 0, 0, 0, 0);
    GfxRect_DrawTextured(x, y, 0x14, 0x14, (((glyph % 4) * 0x14) << 5) - 0x10, -0x10, 0x400, 0x400, 0);
}
/* mkdraft:func_88308530 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B9840/func_8830865C.s")
#endif
