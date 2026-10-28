#include "global.h"


#ifdef VERSION_US
s32 func_84104FB0(u8 *arg0) {
    return *(s32 *)(arg0 + 0x14);
}

extern u8 *D_8009491C;
extern s32 func_84104FB0(u8 *);
extern s32 func_8411EF64(s32);
Gfx *func_84104FB8(Gfx *gfx, s32 frame) {
    u8 *tex = (u8 *)func_8411EF64(*(s32 *)(func_84104FB0(D_8009491C) + 8));
    u32 width = *(u16 *)(tex + 4);
    u32 height = *(u16 *)(tex + 6);

    gDPLoadTextureTile(gfx++, *(u16 **)(tex + 8) + frame * width * height, G_IM_FMT_RGBA, G_IM_SIZ_16b, width,
                       height, 0, 0, width - 1, height - 1, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                       G_TX_NOLOD, G_TX_NOLOD);
    return gfx;
}

extern Gfx *D_800D0510;
extern Gfx *func_84104FB8(Gfx *, s32);
void func_841050E4(s32 arg0, u8 *arg1) {
    if (arg0 == 5) {
        D_800D0510 = func_84104FB8(D_800D0510, *(s32 *)(arg1 + 0x14));
    }
}
#endif
