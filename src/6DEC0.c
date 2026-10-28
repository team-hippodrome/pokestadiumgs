#include "global.h"


#ifdef VERSION_US
extern u16 D_80094904;
extern u32 D_80128C00;
extern u32 D_80128C04;
extern u32 D_80128C08;
extern u32 D_80128C0C;
extern u32 D_80128C10;
extern u32 D_80128C14;
extern u32 D_80128C18;
extern u32 D_80128C1C;
extern u32 D_80128C20;
extern u32 D_80128C24;
extern u32 D_80128C28;
extern u32 D_80128C2C;
extern u32 D_80128C30;
extern u32 D_80128C34;
extern u32 D_80128C38;
extern u32 D_80128C3C;
extern u32 D_80128C40;
extern u32 D_80128C44;
extern u32 D_80128C48;
extern u32 D_80128C4C;
extern u32 D_80128C50;
extern u32 D_80128C54;

// Close to Pokemon Stadium's Particle_UpdateFrameCounters; GS copies the u16 frame
// counter D_80094904 (advanced by GeoRender_AdvanceFrameCounter) instead of
// incrementing its own word, then derives the same masks, shifts and mod/div-3 values.
//@src/229E0.c
void func_8006D2C0(void) {
    D_80128C00 = D_80094904;
    D_80128C04 = D_80128C00 & 0x3F;
    D_80128C08 = D_80128C00 & 0x1F;
    D_80128C0C = D_80128C00 & 0xF;
    D_80128C10 = D_80128C00 & 7;
    D_80128C14 = D_80128C00 & 3;
    D_80128C18 = D_80128C00 % 3;
    D_80128C1C = D_80128C00 & 1;
    D_80128C20 = D_80128C00 >> 6;
    D_80128C24 = D_80128C00 >> 5;
    D_80128C28 = D_80128C00 >> 4;
    D_80128C2C = D_80128C00 >> 3;
    D_80128C30 = D_80128C00 >> 2;
    D_80128C34 = D_80128C00 / 3;
    D_80128C38 = D_80128C00 >> 1;
    D_80128C3C = D_80128C20 & 1;
    D_80128C40 = D_80128C24 & 1;
    D_80128C44 = D_80128C28 & 1;
    D_80128C48 = D_80128C2C & 1;
    D_80128C4C = D_80128C30 & 1;
    D_80128C50 = D_80128C34 & 1;
    D_80128C54 = D_80128C38 & 1;
}

s32 func_8006D424(void) { return D_80128C00; }

void func_8006D430(s32 arg0) {}

void func_8006D438(s32 arg0) {}


typedef struct {
    s32 state;
    u8 pad[3];
    u8 controller;
} LocalState;

extern u8 D_81600000[]; extern u8 D_81800000[]; extern u8 D_82800000[]; extern u8 D_81C00000[]; extern u8 D_88000000[]; extern u8 D_88B00000[]; extern u8 D_8009DFB0[]; extern u8 D_437610[];
extern u8 fragment4_ROM_START[]; extern u8 fragment5_ROM_START[]; extern u8 fragment10_ROM_START[]; extern u8 fragment11_ROM_START[]; extern u8 fragment12_ROM_START[];
extern u8 fragment29_ROM_START[]; extern u8 fragment30_ROM_START[]; extern u8 fragment40_ROM_START[]; extern u8 fragment41_ROM_START[]; extern u8 fragment88_ROM_START[];
void main_pool_push_state(s32); void main_pool_pop_state(s32); void Fragment_Load(s32, void *, void *);
s32 Fragment_LoadAndCall(s32, void *, void *, s32, void *); void func_80064C94(s32); s32 func_80064C88(void);

extern s32 D_80128C60;
extern s32 D_80128C64;
extern u8 D_8009DFA0[];
extern u8 D_8009DFA8[];
extern u8 D_88A00000[];
extern u8 D_88100000[];
extern u8 D_88700000[];
extern u8 D_88800000[];
extern u8 D_88900000[];
extern u8 D_88200000[];
extern u8 D_88600000[];
extern u8 D_88300000[];
extern u8 D_88400000[];
extern u8 D_8AC00000[];
extern u8 D_8AE00000[];
extern u8 D_88500000[];

extern u8 fragment30_ROM_START[];
extern u8 fragment31_ROM_START[];
extern u8 fragment32_ROM_START[];
extern u8 fragment32_ROM_END[];
extern u8 fragment33_ROM_START[];
extern u8 fragment34_ROM_START[];
extern u8 fragment35_ROM_START[];
extern u8 fragment36_ROM_START[];
extern u8 fragment37_ROM_START[];
extern u8 fragment38_ROM_START[];
extern u8 fragment39_ROM_START[];
extern u8 fragment40_ROM_START[];
extern u8 fragment43_ROM_START[];
extern u8 fragment44_ROM_START[];
extern u8 fragment46_ROM_START[];
extern u8 fragment47_ROM_START[];

extern void func_80041E2C(void);
extern void func_80057908(u8);
extern void func_8005A0F4(s32);
extern void func_80057944(u8);
extern s32 func_80041C98(s32);
extern s32 func_8005D92C(s32);

void func_8006D440(void) {
    LocalState sp;
    s32 result;
    u16 var_s3;

    sp.state = 8;
    main_pool_push_state(0x4353454C);
    Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment12_ROM_START);
    Fragment_Load((((u32)D_81800000 & 0x0FF00000) >> 20) - 0x10, fragment4_ROM_START, fragment5_ROM_START);
    result = Fragment_LoadAndCall((((u32)D_82800000 & 0x0FF00000) >> 20) - 0x10, fragment10_ROM_START, fragment11_ROM_START, -1, D_8009DFA0);
    main_pool_pop_state(0x4353454C);

    if (result != -1) {
        func_80064C94(result);
        D_80128C60 = 7;
        main_pool_push_state(0x4C414243);
        Fragment_Load((((u32)D_88000000 & 0x0FF00000) >> 20) - 0x10, fragment29_ROM_START, fragment30_ROM_START);
        func_80041E2C();
        sp.controller = func_80064C88();
        main_pool_push_state(0x47424D4F);
        func_80057908(sp.controller);
        func_8005A0F4(sp.controller);

        if (D_80128C60 != 8) {
            do {
                main_pool_push_state(0x4C414250);
                switch (D_80128C60) {
                case 7:
                    Fragment_Load((((u32)D_88A00000 & 0x0FF00000) >> 20) - 0x10, fragment39_ROM_START, fragment40_ROM_START);
                    D_80128C60 = Fragment_LoadAndCall((((u32)D_88100000 & 0x0FF00000) >> 20) - 0x10, fragment30_ROM_START, fragment31_ROM_START, sp.state, 0);
                    break;
                case 0:
                    sp.state = D_80128C60;
                    Fragment_Load((((u32)D_88A00000 & 0x0FF00000) >> 20) - 0x10, fragment39_ROM_START, fragment40_ROM_START);
                    Fragment_Load((((u32)D_88700000 & 0x0FF00000) >> 20) - 0x10, fragment36_ROM_START, fragment37_ROM_START);
                    Fragment_Load((((u32)D_88800000 & 0x0FF00000) >> 20) - 0x10, fragment37_ROM_START, fragment38_ROM_START);
                    Fragment_Load((((u32)D_88900000 & 0x0FF00000) >> 20) - 0x10, fragment38_ROM_START, fragment39_ROM_START);
                    D_80128C60 = Fragment_LoadAndCall((((u32)D_88200000 & 0x0FF00000) >> 20) - 0x10, fragment31_ROM_START, fragment32_ROM_START, 0, 0);
                    break;
                case 1:
                {
                    u16 temp;
                    main_pool_push_state(0x424F434F);
                    temp = 0x98;
                    var_s3 = 0;
                    Fragment_Load((((u32)D_88600000 & 0x0FF00000) >> 20) - 0x10, fragment35_ROM_START, fragment36_ROM_START);
                    D_80128C64 = func_80041C98(5);
                    sp.state = D_80128C60;
                    if (D_80128C60 == 1) {
                        do {
                            temp = (u16)Fragment_LoadAndCall((((u32)D_88300000 & 0x0FF00000) >> 20) - 0x10, fragment32_ROM_START, fragment32_ROM_END, var_s3, (void *)(s32)temp);
                            switch (D_80128C60) {
                            case 2:
                                Fragment_LoadAndCall((((u32)D_88400000 & 0x0FF00000) >> 20) - 0x10, fragment33_ROM_START, fragment34_ROM_START, 0, (void *)(s32)temp);
                                var_s3 = 1;
                                D_80128C60 = 1;
                                break;
                            case 3:
                                main_pool_push_state(0x4F474157);
                                Fragment_Load((((u32)D_8AC00000 & 0x0FF00000) >> 20) - 0x10, fragment43_ROM_START, fragment44_ROM_START);
                                Fragment_LoadAndCall((((u32)D_8AE00000 & 0x0FF00000) >> 20) - 0x10, fragment46_ROM_START, fragment47_ROM_START, func_8005D92C(sp.controller), (void *)(s32)temp);
                                main_pool_pop_state(0x4F474157);
                                var_s3 = 2;
                                D_80128C60 = 1;
                                break;
                            }
                        } while (D_80128C60 == 1);
                    }
                    main_pool_pop_state(0x424F434F);
                }
                    break;
                case 5:
                    sp.state = D_80128C60;
                    Fragment_Load((((u32)D_88800000 & 0x0FF00000) >> 20) - 0x10, fragment37_ROM_START, fragment38_ROM_START);
                    Fragment_Load((((u32)D_88900000 & 0x0FF00000) >> 20) - 0x10, fragment38_ROM_START, fragment39_ROM_START);
                    D_80128C60 = Fragment_LoadAndCall((((u32)D_88500000 & 0x0FF00000) >> 20) - 0x10, fragment34_ROM_START, fragment35_ROM_START, 0, 0);
                    break;
                case 6:
                    sp.state = D_80128C60;
                    result = (s32)D_8009DFA8;
                    Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment12_ROM_START);
                    Fragment_Load((((u32)D_81800000 & 0x0FF00000) >> 20) - 0x10, fragment4_ROM_START, fragment5_ROM_START);
                    result = Fragment_LoadAndCall((((u32)D_82800000 & 0x0FF00000) >> 20) - 0x10, fragment10_ROM_START, fragment11_ROM_START, sp.controller, (void *)(s32)result);
                    if (result != -1) {
                        func_80064C94(result);
                    }
                    D_80128C60 = 7;
                    break;
                default:
                    break;
                }
                main_pool_pop_state(0x4C414250);
                if (func_80064C88() != sp.controller) {
                    func_80057944(sp.controller);
                    main_pool_pop_state(0x47424D4F);
                    sp.controller = func_80064C88();
                    main_pool_push_state(0x47424D4F);
                    func_80057908(sp.controller);
                    func_8005A0F4(sp.controller);
                }
            } while (D_80128C60 != 8);
        }
        func_80057944(sp.controller);
        main_pool_pop_state(0x47424D4F);
        main_pool_pop_state(0x4C414243);
    }
}


void Game_State19_Run(void) {
    s32 result;
    main_pool_push_state(0x4353454C);
    Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment12_ROM_START);
    Fragment_Load((((u32)D_81800000 & 0x0FF00000) >> 20) - 0x10, fragment4_ROM_START, fragment5_ROM_START);
    result = Fragment_LoadAndCall((((u32)D_82800000 & 0x0FF00000) >> 20) - 0x10, fragment10_ROM_START, fragment11_ROM_START, -1, D_8009DFB0);
    main_pool_pop_state(0x4353454C);
    if (result != -1) {
        func_80064C94(result);
        main_pool_push_state(0x4C414243);
        Fragment_Load((((u32)D_81C00000 & 0x0FF00000) >> 20) - 0x10, fragment88_ROM_START, D_437610);
        Fragment_Load((((u32)D_88000000 & 0x0FF00000) >> 20) - 0x10, fragment29_ROM_START, fragment30_ROM_START);
        Fragment_LoadAndCall((((u32)D_88B00000 & 0x0FF00000) >> 20) - 0x10, fragment40_ROM_START, fragment41_ROM_START, func_80064C88(), 0);
        main_pool_pop_state(0x4C414243);
    }
}
#endif
