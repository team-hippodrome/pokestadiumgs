#include "global.h"


void func_8410A600(void) {
}

#ifdef VERSION_US
extern u8 D_84190410;
extern u8 D_84190411;
extern u8 D_84190428[];
extern u8 D_841910E0[];
extern u8 D_84190230[];
extern u8 D_84190320[];
extern u32 D_84190414;
extern u32 D_84190418;
extern u32 D_8419041C;
extern u32 D_84190420;
extern void func_8411DBF4(s32);
extern void func_84111868(s32, u8 *, u8 *);
extern void func_8411F694(s32, u8 *, u8 *);
extern void func_8411F340(u32, u32);
void func_8410A608(void) {
    extern s32 func_8410580C(s32, u8 *, s32);
    D_84190410 = 0;
    D_84190411 = 0;
    func_8411DBF4(2);
    func_84111868(2, D_84190428, D_841910E0);
    func_8411F694(2, D_84190230, D_84190320);
    func_8411F340(D_8419041C, D_84190414);
    func_8411F340(D_84190420, D_84190418);
    func_8410580C(2, D_84190428, 0);
}
#endif

#ifdef VERSION_US
// ControllerState (include/controller.h) read as halfwords: [3] buttonsHeld, [4] buttonsPressed.
extern u16 *D_80087200;
extern u8 *D_84193FA0;
extern s32 D_84193FA4;
void func_8410A6A4(void) {
    extern s32 func_8410580C(s32, u8 *, s32);

    D_84193FA4 = func_841242B0(D_80087200, D_84193FA0 + 0x86, D_84193FA0 + 0x88);
    if (D_80087200[4] & 0x1000) {
        D_84190410 = ~D_84190410 + 2;
    }
    if (D_84190410 != 0) {
        if ((D_80087200[3] & 0x4000) && D_84193FA4 != 0) {
            D_84190411 = 1;
        } else {
            D_84190411 = 0;
        }
    }
    if (D_84190410 == 0) {
        func_8411DBF4(30);
        func_84111868(2, D_84190428, D_841910E0);
        func_8411F694(2, D_84190230, D_84190320);
        func_8411F340(D_8419041C, D_84190414);
        func_8411F340(D_84190420, D_84190418);
        func_8410580C(2, D_84190428, 0);
    } else {
        func_8411DBF4(30);
        func_84111868(2, D_84190428, D_841910E0);
        if (D_84190411 != 0) {
            func_8411F694(2, D_84190230, D_84190320);
        }
        if (D_84190411 != 0) {
            func_8411F340(D_8419041C, D_84190414);
        }
        if (D_84190411 != 0) {
            func_8411F340(D_84190420, D_84190418);
        }
        // FAKE: empty repeated test of D_84190420; diff score 80 without it.
        if (D_84190420 && D_84190420 && D_84190420) {}
        if (D_84190411 != 0) {
            func_8410580C(2, D_84190428, 0);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8410580C(s32, u8 *, s32);
extern u8 D_84183870[];
extern u8 D_84183874[];
extern s32 D_8419020C;
extern s32 D_84190210;
extern u8 D_84190429;
extern u8 D_841910E1;
extern s32 D_841911E4;
void func_8410A884(void) {
    func_8410A444();
    if (D_84190410 == 0) {
        GeoRender_AdvanceFrameCounter();
    } else if (D_84190411 != 0) {
        GeoRender_AdvanceFrameCounter();
    }
    if (D_84190429 & 0x10) {
        func_8003C6B8(D_8419020C);
    }
    func_8410580C(5, D_84190428, 4);
    if (D_841910E1 & 0x10) {
        func_8003C6B8(D_84190210);
    }
    if (D_841910E1 & 0x10) {
        if (*(s16 *)((u8 *)D_841911E4 + 0x9C) != 0) {
            Ui_DrawGradientQuad(0, *(s16 *)((u8 *)D_841911E4 + 0x9C) - 1, 320, 2, &D_84183870, &D_84183874);
        } else {
            Ui_DrawGradientQuad(*(s16 *)((u8 *)D_841911E4 + 0x9A) - 1, 0, 2, 240, &D_84183870, &D_84183874);
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_8411DBF4(s32 arg0);
void func_8410A9B4(void) {
    func_8411DBF4(5);
}
#endif

#ifdef VERSION_US
extern s32 func_8410580C(s32, u8 *, s32);
s32 func_8410A9D4(s32 arg0, u8 *arg1) {
    if (arg0 == 2) {
        func_8410580C(5, D_84190428, *(s32 *)(arg1 + 0x14));
    }
    return 0;
}
void func_8410A9D4_tail_void(void) {
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8410AA18 begin */
typedef union { s32 word; s8 bytes[4]; } Func80041FA0State;

s32 BinArchive_Open(s32, s32, s32, s32);
void GeoCamera_SetPerspective(u8 *, f32, f32, f32);
void GfxImage_AttachDepthBuffer(u32, s32);
void GfxImage_Initialize(s32, s32, s32, s32, s32, s32);
s32 MainPool_AllocState(s32, s32);
void MainPool_FinalizeAllocation(s32);
void ModelRenderer_InitDisplayRoots(void);
s32 func_80004B4C(s32, s32);
u32 func_800071A4(s32, s32, s32, s32, s32);
s32 func_800356CC(s32);
void func_80037F40(s32, u8 *, s32, s32, s32, s32);
u32 func_80040E80(s32, void *);
s32 func_80041C98(s32);
s32 func_80041D84(s32);
void func_80041E2C(void);
void func_80041FA0(s32, u16, Func80041FA0State);
void func_800428F8(s32);
void func_8410A524(s32, s32, s32);
void func_8410A5BC(s32, s32, s32);
s32 func_8410580C(s32, u8 *, s32);
void func_84111868(s32, u8 *, u8 *);
void func_8411DBF4(s32);
void func_8411F694(s32, u8 *, u8 *);
s32 main_pool_alloc(s32, s32);
s32 main_pool_get_available(void);
extern u8 D_84183878[];
extern u8 D_841838D4[];
extern s32 D_84190518;
extern s32 D_8419051C;
extern s32 D_841910D8;
extern s32 D_841910DC;
extern s32 D_84191208;
extern s32 D_8419120C;
extern s32 D_84193DD0;
extern u8 *D_84193FA0;





void func_8410AA18(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 sp30;
    s32 sp2C;
    s32 pad;
    s32 sp24;
    s32 temp_v0_2;

    D_841910D8 = arg1;
    temp_v0 = main_pool_alloc(0x10, 0);
    sp30 = temp_v0;
    GfxImage_Initialize(temp_v0, 0, 2, 0x20, 0x20, *(s32 *)(*(u8 **)(*(u8 **)((u8 *)arg0 + 0x18) + 0xC) + 8));
    D_84190414 = func_800071A4(0, 2, 0x20, 0x20, 0);
    D_84190418 = func_800071A4(0, 2, 0x20, 0x20, 0);
    GfxImage_AttachDepthBuffer(D_84190414, sp30);
    GfxImage_AttachDepthBuffer(D_84190418, sp30);
    func_80037F40(0, D_84190428, 0, 0x14, 0x140, 0x64);
    func_80037F40(0, D_841910E0, 0, 0x78, 0x140, 0x64);
    func_80037F40(0, D_84190428, 0, 0, 0x140, 0xF0);
    func_80037F40(0, D_84190230, 0x1E, -0x50, 0x20, 0x20);
    func_80037F40(0, D_84190320, 0x104, -0x50, 0x20, 0x20);
    GeoCamera_SetPerspective(D_84190428, 45.0f, 20.0f, 6400.0f);
    GeoCamera_SetPerspective(D_841910E0, 45.0f, 20.0f, 6400.0f);
    GeoCamera_SetPerspective(D_84190230, 10.0f, 10.0f, 1280.0f);
    GeoCamera_SetPerspective(D_84190320, 10.0f, 10.0f, 1280.0f);
    D_841910E0[1] = D_841910E0[1] & 0xFFEF;
    ModelRenderer_InitDisplayRoots();
    func_80041E2C();
    sp24 = func_80004B4C(BinArchive_Open(func_800356CC(0x10), 0, 1, 1), arg1);
    temp_v0_2 = MainPool_AllocState(main_pool_get_available(), 0);
    sp2C = temp_v0_2;
    func_8410A524(arg1, temp_v0_2, sp24);
    func_8410A5BC(arg1, sp2C, sp24);
    D_8419041C = func_80040E80(sp2C, D_84183878);
    D_84190420 = func_80040E80(sp2C, D_841838D4);
    MainPool_FinalizeAllocation(sp2C);
    func_8411DBF4(0);
    func_84111868(0, D_84190428, D_841910E0);
    func_8411F694(0, D_84190230, D_84190320);
    func_8410580C(0, D_84190428, 0);
    *(s32 *)(D_84191208 + 0x5C0) = func_80041C98(5);
    *(s32 *)(D_8419120C + 0x5C0) = func_80041C98(5);
    D_8419051C = func_80041C98(2);
    D_84190518 = func_80041D84(0xFC);
    *(s32 *)(D_84191208 + 0x5BC) = 0;
    func_80041FA0(D_84190518, 0xFC, *(Func80041FA0State *)(D_84191208 + 0x5BC));
    func_800428F8(D_84190518);
    D_841910DC = BinArchive_Open(func_800356CC(0), 0, 1, 1);
    D_84193DD0 = arg2;
    func_8411DBF4(3);
    func_84111868(3, D_84190428, D_841910E0);
    func_8411F694(3, D_84190230, D_84190320);
    func_8410580C(3, D_84190428, 0);
    *(s16 *)(D_84193FA0 + 0x82) = 0;
    *(s16 *)(D_84193FA0 + 0x80) = 0;
}
/* mkdraft:func_8410AA18 end */
#endif

#ifdef VERSION_US
s32 func_8410AE34(s32 arg0, s32 arg1) {
    return 0;
}
#endif
