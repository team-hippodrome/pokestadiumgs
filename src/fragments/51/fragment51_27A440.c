#include "global.h"


#ifdef VERSION_US
extern u8 *D_87F119DC;
extern u8 D_8630745D;
extern u8 D_8630745E;
extern u8 D_8630745F;
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern u32 func_8003570C(void);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern s32 func_8003F210(void *, s32);
extern u8 * D_863075D8;
void func_86304620(void) {
    if (*(s32 *)D_863075D8 == 2) {
        ModelAnim_SetSpeed(D_87F119DC + 0x24, 0x20000);
        // FAKE: the comma expression only reorders the loads to match.
        if (*(s16 *)(D_87F119DC + 0x64) == (0, D_8630745D)) {
            if (func_8003570C() % 6 == 0) {
                func_8003570C();
                func_8003F1DC(D_87F119DC + 0x24);
                func_8003F114(D_87F119DC + 0x24, 0, -1,
                              ((s32 (*)[2])(D_863075D8 + 0xE0))[*(s32 *)(D_87F119DC + 0x20)][D_8630745E]);
                func_8003F210(D_87F119DC + 0x24, D_8630745F);
            }
        }
    }
}

/* mkdraft:func_8630470C begin */
extern u8 *D_863075D8;
extern u8 D_8630745C;
extern u8 D_8630745D;
extern void func_86304620(void);
extern void *func_87F025B8(u8 *, void (*)());
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern s32 func_8003F210(void *, s32);
extern u32 func_8003570C(void);
extern void ModelAnim_SetFrame(u8 *, s16);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern s32 func_87F06430(void *, s32);



void func_8630470C(void) {
    // FAKE: these two pointer locals only force the D_8630745D/D_8630745C loads back
    // into the loop body; using the globals directly scores 2221.
    u8 *D_8630745D_ptr = &D_8630745D;
    u8 *D_8630745C_ptr = &D_8630745C;
    s32 slot;
    u8 *anim;
    u8 *node;

    for (slot = 0; slot != 4; slot++) {
        node = func_87F025B8(D_863075D8 + 0x88DC, func_86304620);
        func_8003F1DC(node + 0x24);
        anim = node + 0x24;
        func_8003F114(anim, 0, -1, ((s32 (*)[2])(D_863075D8 + 0xE0))[slot][*D_8630745C_ptr]);
        func_8003F210(anim, *D_8630745D_ptr);
        ModelAnim_SetFrame(anim, (s16) (func_8003570C() % 41));
        ModelAnim_SetSpeed(anim, 0x17FFE);
        func_87F06430(node + 0x48, slot);
        *(s32 *)(node + 0x20) = slot;
        *(f32 *)(node + 0x5C) = 0.1f;
        *(f32 *)(node + 0x58) = 0.1f;
        *(f32 *)(node + 0x54) = 0.1f;
        *(f32 *)(node + 0x4C) = *(f32 *)(node + 0x4C) - 30.0f;
    }
}
/* mkdraft:func_8630470C end */

extern u8 *D_863075D8;
extern void func_87F02684(void *);
extern void func_87F0277C(void *);
void func_8630487C(void) {
    func_87F02684(D_863075D8 + 0x88DC);
}

void func_863048A8(void) {
    func_87F0277C(D_863075D8 + 0x88DC);
}

extern u8 D_87F15B70[];
extern void func_87F0252C(void *, void *, void *, s32);
void func_863048D4(void) {
    func_87F0252C(D_87F15B70, D_863075D8 + 0x88DC, D_863075D8 + 0x88F0, 4);
}
#endif
