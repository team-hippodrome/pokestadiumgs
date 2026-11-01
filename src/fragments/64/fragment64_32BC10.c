#include "global.h"


#ifdef VERSION_US
extern Gfx *D_800D0510;
extern Gfx D_87F11190[];

// D_87F11190 is the mode-setting Gfx display list in this fragment's data
// (asm/us/data/fragments/64/fragment64_data.data.s:2071, ends with G_ENDDL);
// D_800D0510 is the shared display-list cursor (the file-idiom Gfx * extern).
// The u8 parameter is load-bearing for the register schedule: ugen homes a
// narrow register parameter framelessly into the caller's outgoing-arg area
// (sw a0, 0(sp), raw value, no sp adjustment), and the macro's _SHIFTL(a, 0, 8)
// mask on the alpha subsumes the in-place entry narrowing, so the single
// andi t3, a0, 0xff sits at the use reading raw a0. A wider parameter type
// drops the home store entirely (verified score 315) and also loses the
// as1 interleave that splits the first command's lui/addiu pair around the
// pointer advance.
void func_87F08FA0(u8 arg0) {
    gSPDisplayList(D_800D0510++, D_87F11190);
    gDPSetEnvColor(D_800D0510++, 0, 0, 0, arg0);
    gSPTextureRectangle(D_800D0510++, 0, 0, 320 << 2, 240 << 2, G_TX_RENDERTILE, 0, 0, 1024, 1024);
}
extern Gfx D_80094DE0[];
void func_87F09040(void) {
    gSPDisplayList(D_800D0510++, D_80094DE0);
    gDPPipeSync(D_800D0510++);
    gDPSetFillColor(D_800D0510++, 0xFFFFFFFF);
    gDPFillRectangle(D_800D0510++, 22, 16, 298, 16);
    gDPFillRectangle(D_800D0510++, 22, 224, 298, 224);
    gDPFillRectangle(D_800D0510++, 22, 16, 22, 224);
    gDPFillRectangle(D_800D0510++, 298, 16, 298, 224);
}

/* mkdraft:func_87F09120 begin */


void func_87F09120(void **arg0, s32 image, s32 format, s32 size, u32 width, u32 height, s32 swapped,
                   s32 palette, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt) {
    Gfx *cmd;
    u32 loadSize;
    u32 increment;
    u32 shift;
    u32 dxt;
    u32 rowBytes;
    s32 renderTile;
    u32 renderLine;

    cmd = *(Gfx **)arg0;
    switch (size) {
    case 0:
        loadSize = 2;
        increment = 3;
        shift = 2;
        dxt = CALC_DXT_4b((u32)width);
        renderLine = (((u32)width >> 1) + 7) >> 3;
        break;
    case 1:
        loadSize = 2;
        increment = 1;
        shift = 1;
        rowBytes = (u32)width * G_IM_SIZ_8b_BYTES;
        dxt = CALC_DXT((u32)width, 1);
        renderLine = (rowBytes + 7) >> 3;
        break;
    case 2:
        loadSize = 2;
        increment = 0;
        shift = 0;
        rowBytes = (u32)width * 2;
        dxt = CALC_DXT((u32)width, 2);
        renderLine = (rowBytes + 7) >> 3;
        break;
    case 3:
        loadSize = 3;
        increment = 0;
        shift = 0;
        dxt = CALC_DXT((u32)width, 4);
        renderLine = ((u32)width * 2 + 7) >> 3;
        break;
    default:
        return;
    }
    if (swapped != 0) {
        dxt = 0;
    }
    gDPSetTextureImage(cmd++, format, loadSize, 1, (u8 *)image);
    gDPSetTile(cmd++, format, loadSize, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(cmd++);
    gDPLoadBlock(cmd++, G_TX_LOADTILE, 0, 0, ((((u32)width * height + increment) >> shift) - 1), dxt);
    gDPPipeSync(cmd++);
    renderTile = G_TX_RENDERTILE;
    gDPSetTile(cmd++, format, size, renderLine, 0, renderTile, palette, cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(cmd++, renderTile, 0, 0, (width - 1) << 2, (height - 1) << 2);
    *(Gfx **)arg0 = cmd;
}
/* mkdraft:func_87F09120 end */

/* mkdraft:func_87F09504 begin */
// Uploads a texture image with the tile width derived from the pixel size, loads
// the tile, then programs the render tile with the same row count. The display
// list is taken from and written back through displayList rather than the
// fragment-global D_800D0510 cursor used by the neighboring functions.


void func_87F09504(Gfx **displayList, u8 *image, s32 format, s32 size, u32 width, u32 height, u32 uls, u32 ult, u32 lrs, u32 lrt, s32 palette, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt) {
    Gfx *cmd;
    u32 renderLine;
    u32 loadLine;
    s32 renderTile;
    s32 pad; // FAKE: declared-only stack slot; the ugen temporaries shift by 4 bytes without it (diff score 36)

    cmd = *displayList;
    switch (size) {
    case 0:
        width >>= 1;
        renderLine = loadLine = ((((lrs - uls + 1) >> 1) + 7) >> 3);
        size = G_IM_SIZ_8b;
        break;
    case 1:
        renderLine = loadLine = ((lrs - uls + 1 + 7) >> 3);
        break;
    case 2:
        renderLine = loadLine = (((lrs - uls + 1) * 2 + 7) >> 3);
        break;
    case 3:
        renderLine = loadLine = (((lrs - uls + 1) * 2 + 7) >> 3);
        break;
    default:
        return;
    }
    gDPSetTextureImage(cmd++, format, size, width, image);
    gDPSetTile(cmd++, format, size, loadLine, 0, G_TX_LOADTILE, 0,
               cmt, maskt, shiftt, cms, masks, shifts);
    gDPLoadSync(cmd++);
    gDPLoadTile(cmd++, G_TX_LOADTILE, uls << 2, ult << 2, lrs << 2, lrt << 2);
    gDPPipeSync(cmd++);
    renderTile = G_TX_RENDERTILE;
    gDPSetTile(cmd++, format, size, renderLine, 0, renderTile, palette,
               cmt, maskt, shiftt, cms, masks, shifts);
    gDPSetTileSize(cmd++, renderTile, uls << 2, ult << 2, lrs << 2, lrt << 2);
    *displayList = cmd;
}
/* mkdraft:func_87F09504 end */
#endif
