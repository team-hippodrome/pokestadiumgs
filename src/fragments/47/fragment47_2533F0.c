#include "global.h"


#ifdef VERSION_US
extern void func_87F0455C(void);
extern void func_8600BA50(void);
extern void func_8600AAD4(void);
extern void func_87F024CC(void);
extern void func_86004FDC(void *, s32);
extern void ModelRenderer_InitDisplayRoots(void);
extern void func_8600520C(void *);
extern u8 D_8600E110[];
void func_8600CDD0(s32 arg0) {
    func_87F0455C();
    func_8600BA50();
    func_8600AAD4();
    func_87F024CC();
    func_86004FDC(D_8600E110, arg0);
    ModelRenderer_InitDisplayRoots();
    func_8600520C(D_8600E110);
}

extern void BgStage_DrawFrame(void);
extern void GfxImage_ClearDepthRectangle(void *, s32, s32, s32, s32);
extern void func_86006F20(void *);
extern void func_80008648(void);
extern u8 D_800D0510[];
void func_8600CE2C(s32 arg0) {
    BgStage_DrawFrame();
    GfxImage_ClearDepthRectangle(D_800D0510, 0, 0, 0x140, 0xF0);
    func_86006F20(D_8600E110);
    func_80008648();
}

typedef struct {
    u32 active : 1;
    u32 unk_30 : 5;
    u32 skip : 1;
    u32 rest : 25;
} Fragment47StageFlags;
extern void func_86006D64(void *, s32);
extern s32 StageContext_GetFadeMode(void);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_87F0C930(void *);
extern u8 D_86019060[];
extern u8 D_8600E110[];
s32 func_8600CE80(s32 arg0) {
    s32 result = arg0;

    func_86006D64(D_8600E110, arg0);
    switch (arg0) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                if (((Fragment47StageFlags *)(D_8600E110 + 0x75C0))->active) {
                    result = 1;
                    if ((*(u8 **)(D_8600E110 + 0x7580))[0x2180] == 4) {
                        if (!((Fragment47StageFlags *)(D_8600E110 + 0x75C0))->skip) {
                            func_87F0C930(D_86019060);
                        }
                    } else {
                        StageContext_SetClearColor(0xFFFF);
                        StageFade_StartFromTransparent(10);
                    }
                }
            } else if (((Fragment47StageFlags *)(D_8600E110 + 0x75C0))->active &&
                       ((Fragment47StageFlags *)(D_8600E110 + 0x75C0))->skip) {
                result = 1;
            }
            break;
        case 1:
            if (StageContext_GetFadeMode() == 1) {
                result = 2;
            }
            break;
    }
    return result;
}

extern void StageFade_StartFromOpaque(s32);
extern void func_800086A4(s32);
extern void func_80064D28();
s32 func_8600CE80(s32);

void func_8600CF80(void) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        func_8600CE2C(var_s0);
        temp_v0 = func_8600CE80(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != 2);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_2533F0/func_8600CFDC.s")
#endif
