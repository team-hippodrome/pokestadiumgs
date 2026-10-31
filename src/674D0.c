#include "global.h"

#ifdef VERSION_US
s32 func_800668D0(s32 a) {
    s32 r = (u32)0xFFFF;

    switch (a) {
    case 1:
        r = 0;
        break;
    case 2:
        r = 1;
        break;
    case 4:
        r = 2;
        break;
    case 3:
        r = 3;
        break;
    }

    return r;
}

extern s32 D_8009DEDC[];
s32 func_80066924(s32 arg0) { s32 result = 0; if (arg0 > 0 && arg0 < 5) { result = D_8009DEDC[arg0]; } return result; }

extern u16 D_8009DEF0[];

s32 func_8006694C(u16 arg0, UNUSED s32 arg1) {
    s32 i;
    s32 result = 0;

    for (i = 0; i < 4; i++) {
        // FAKE: the mask swaps the bnel operands; diff score 10 without it.
        if (arg0 == (func_800668D0(D_8009DEF0[i]) & 0xFFFFFFFF)) {
            result = D_8009DEF0[i];
            break;
        }
    }
    return result;
}

typedef struct SceneConfig674D0 {
    s32 words[4];
} SceneConfig674D0;

typedef struct SceneContext674D0 {
    u8 unk_00[0x2C];
    void *unk_2C;
} SceneContext674D0;

extern SceneConfig674D0 D_8009DEF8;
extern u8 D_81100000[];
extern u8 D_81300000[];
extern u8 D_81400000[];
extern u8 D_81600000[];
extern u8 D_81700000[];
extern u8 D_82300000[];
extern u8 D_82600000[];
extern u8 D_82900000[];
extern u8 D_84100000[];
extern u8 D_84200000[];
extern u8 D_84300000[];

extern u8 fragment11_ROM_START[];
extern u8 fragment11_ROM_END[];
extern u8 fragment12_ROM_START[];
extern u8 fragment13_ROM_START[];
extern u8 fragment14_ROM_START[];
extern u8 fragment15_ROM_START[];
extern u8 fragment18_ROM_START[];
extern u8 fragment18_ROM_END[];
extern u8 fragment19_ROM_START[];
extern u8 fragment20_ROM_START[];
extern u8 fragment21_ROM_START[];
extern u8 fragment27_ROM_START[];
extern u8 fragment28_ROM_START[];
extern u8 fragment67_ROM_START[];
extern u8 fragment68_ROM_START[];
extern u8 fragment79_ROM_START[];
extern u8 fragment80_ROM_START[];
extern u8 fragment81_ROM_START[];
extern u8 fragment82_ROM_START[];

extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern s32 func_8006A328(u16);
extern void func_8006A180(void);
extern s32 Audio_SetModeBlocking(s32, s32, s32);
extern void func_800355E4(s32);
extern void *func_8006CA54(s32);
extern void Fragment_Load(s32, void *, void *);
extern u32 Fragment_LoadAndCall(s32, void *, void *, u32, void *);
extern void func_8006A3B8(u16);
extern void func_8006A400(s32);
extern u16 func_8006A3E0(void);
extern s32 func_8006A424(void);
extern u8 func_8006A388(void);
extern s32 func_8006A600(u16, s32, s32);
extern void func_8006A444(s32);
extern void func_8006AB8C(u16, s32, s32);
extern void func_8006AC4C(s32);
extern void func_8006B7D8(s32);
extern void func_8006CAC0(void *);
extern void *func_8006B928(void);
extern SceneContext674D0 *func_8006A160(s32, void *, void *);
extern void func_8006AC28(s32);
extern void func_8006ABD8(void *);
extern s32 func_8006A35C(s32);
extern void func_8006CDA0(void *, void *);
extern s32 func_8006C58C(void);
extern void func_8006ACCC(s32);
extern s32 func_8006AC70(void);
extern s32 func_8006AD10(u16, s32, s32);
extern void func_8006AE90(s32);
extern void func_8006B0B8(void);
extern void *func_8006BAC4(void);
extern s32 func_8006AEB4(void);
extern void func_80026938(u16);
extern s32 func_8006A48C(void);
extern s32 func_8006A51C(s32);
extern void *func_8006C664(void);
extern u8 *func_8006C644(void);
extern s32 func_8006D268(s32);
extern s32 func_8006A2F8(u16);
extern s32 func_8006AC90(void);
extern void Audio_ResetModeSelector(void);
extern void *func_8006C714(void);
extern void func_8006C9C0(void *);
extern void func_8006A2EC(void);
extern void Game_SetState(s32);
extern void func_80065D90(s32);

s32 func_800669C4(s32 arg0, u32 *arg1) {
    UNUSED s32 pad54[7];
    s32 sp50;
    s32 sp4C;
    UNUSED s32 pad48;
    void *temp_s3;
    u32 temp_v0;
    s32 temp_s1;
    s32 temp_s0;
    void *temp_s1_ptr;

    sp50 = 0;
    sp4C = 1;
    Gfx_InitDisplayListBuffers(0x18800, 0);
    func_80008514(func_800082E0(1, 0, 2, 0, 2, 1));
    do {
        main_pool_push_state(0x63736C70);
        switch (arg0) {
        case 1:
            func_8006A328(4);
            func_8006A180();
            Audio_SetModeBlocking(7, 0, 0);
            func_800355E4(0x33);
            temp_s3 = func_8006CA54(sp50);
            Fragment_Load((((u32)D_81700000 & 0x0FF00000) >> 20) - 0x10, fragment18_ROM_START, fragment18_ROM_END);
            Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment11_ROM_END);
            temp_v0 = Fragment_LoadAndCall((((u32)D_82300000 & 0x0FF00000) >> 20) - 0x10, fragment19_ROM_START, fragment20_ROM_START, *arg1, temp_s3);
            *arg1 = temp_v0 & 0xFFFF;
            if (temp_v0 != 0) {
                func_8006A3B8(func_800668D0(temp_v0 & 0xF));
                func_8006A400(func_80066924(temp_v0 >> 16));
                temp_s1 = func_8006A3E0() & 0xFFFF;
                temp_s0 = func_8006A424();
                func_8006A444(func_8006A600(temp_s1, temp_s0, func_8006A388()));
                temp_s1 = func_8006A3E0() & 0xFFFF;
                temp_s0 = func_8006A424();
                func_8006AB8C(temp_s1, temp_s0, func_8006A388());
                if (func_8006A3E0() != 2) {
                    arg0 = 3;
                } else {
                    arg0 = 4;
                }
                func_8006AC4C(0);
                func_8006B7D8(0);
            } else {
                arg0 = 0;
            }
            func_8006CAC0(temp_s3);
            break;
        case 3:
            Audio_SetModeBlocking(7, 0, 0);
            temp_s1_ptr = func_8006B928();
            if (temp_s1_ptr != NULL) {
                Fragment_Load((((u32)D_81700000 & 0x0FF00000) >> 20) - 0x10, fragment18_ROM_START, fragment18_ROM_END);
                Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment11_ROM_END);
                if (Fragment_LoadAndCall((((u32)D_81300000 & 0x0FF00000) >> 20) - 0x10, fragment14_ROM_START, fragment15_ROM_START, 0, temp_s1_ptr) != 1) {
                    arg0 = 1;
                    sp50 = 1;
                } else {
                    arg0 = 4;
                }
            }
            break;
        default:
            sp4C = 0;
            break;
        }
        main_pool_pop_state(0x63736C70);
    } while (sp4C != 0);
    func_80008574();
    Gfx_FreeDisplayListBuffers();
    return arg0;
}

void func_80066D24(void) {
    s32 state;
    UNUSED s32 pad2A8;
    u8 *sp2A4;
    s32 temp_s0;
    u32 sp29C;
    SceneContext674D0 *context;
    UNUSED s32 pad294;
    s32 sp290;
    u8 sp270[0x20];
    u8 sp60[0x210];
    SceneConfig674D0 config;

    sp29C = 2;
    sp290 = 0;
    config = D_8009DEF8;
    state = 1;
    main_pool_push_state(0x62747063);
    context = func_8006A160(1, sp270, sp60);
    func_8006AC28(0);
    func_8006ABD8(&config);
    if (func_8006A35C(4) != 0) {
        func_8006CDA0(sp270, sp60);
        func_8006A444(func_8006A600(func_8006A3E0(), func_8006A424(), func_8006A388()));
        func_8006AB8C(func_8006A3E0(), func_8006A424(), func_8006A388());
        state = 4;
        sp29C = func_8006694C(func_8006A3E0(), func_8006A424());
    }
    do {
        main_pool_push_state(0x62746C70);
        switch (state) {
        case 1:
        case 3:
            state = func_800669C4(state, &sp29C);
            break;
        case 4:
            Fragment_Load((((u32)D_84300000 & 0x0FF00000) >> 20) - 0x10, fragment81_ROM_START, fragment82_ROM_START);
            state = 5;
            Audio_SetModeBlocking(9, 0, 0);
            if (func_8006C58C() != 0) {
                Fragment_LoadAndCall((((u32)D_82600000 & 0x0FF00000) >> 20) - 0x10, fragment20_ROM_START, fragment21_ROM_START, 1, context->unk_2C);
                func_8006AC4C(*(s16 *)((u8 *)context->unk_2C + 0x88));
                func_8006ACCC(*(s16 *)((u8 *)context->unk_2C + 0x8A));
                func_8006AE90(func_8006AD10(func_8006A3E0(), func_8006A424(), func_8006AC70()));
                if ((func_8006A3E0() & 0xFF) == 2U) {
                    func_8006B0B8();
                }
            }
            break;
        case 5:
            temp_s0 = (s32)func_8006BAC4();
            if ((void *)temp_s0 != NULL) {
                Fragment_Load((((u32)D_84200000 & 0x0FF00000) >> 20) - 0x10, fragment80_ROM_START, fragment81_ROM_START);
                state = 6;
                Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment11_ROM_END);
                Fragment_LoadAndCall((((u32)D_81400000 & 0x0FF00000) >> 20) - 0x10, fragment12_ROM_START, fragment13_ROM_START, 0, (void *)temp_s0);
            }
            break;
        case 6:
            func_80026938(func_8006AEB4());
            state = 8;
            Audio_SetModeBlocking(8, func_8006A51C(func_8006A48C()), func_8006AC70() + 1);
            func_800355E4(0x5A);
            Fragment_Load((((u32)D_81100000 & 0x0FF00000) >> 20) - 0x10, fragment27_ROM_START, fragment28_ROM_START);
            Fragment_LoadAndCall((((u32)D_84100000 & 0x0FF00000) >> 20) - 0x10, fragment79_ROM_START, fragment80_ROM_START, func_8006AEB4(), func_8006C664());
            break;
        case 8:
            Audio_SetModeBlocking(0xA, 0, 0);
            sp2A4 = func_8006C644();
            if (sp2A4 != NULL) {
                temp_s0 = Fragment_LoadAndCall((((u32)D_82600000 & 0x0FF00000) >> 20) - 0x10, fragment20_ROM_START, fragment21_ROM_START, 2, sp2A4);
                func_8006B7D8(*(s16 *)(sp2A4 + 0x8C));
                if (func_8006D268(0x102) != 0) {
                    state = 4;
                } else {
                    func_8006A328(2);
                    switch (temp_s0) {
                    case 1:
                    case 6:
                        state = 4;
                        func_8006A2F8(2);
                        break;
                    case 2:
                        if (func_8006AC90() != 0) {
                            state = 9;
                        } else {
                            state = 4;
                            func_8006AC4C(func_8006AC70() + 1);
                        }
                        break;
                    case 3:
                    case 4:
                        state = 3;
                        func_8006AC4C(0);
                        func_8006B7D8(0);
                        if (func_8006A35C(4) != 0) {
                            func_8006A328(4);
                            func_8006A180();
                        }
                        break;
                    case 7:
                        sp290 = 1;
                        state = 0;
                        break;
                    default:
                        state = 0;
                        break;
                    }
                }
            }
            break;
        case 9:
            Audio_ResetModeSelector();
            Audio_SetModeBlocking(0xA, 0, 0);
            temp_s0 = (s32)func_8006C714();
            if ((void *)temp_s0 != NULL) {
                Fragment_LoadAndCall((((u32)D_82900000 & 0x0FF00000) >> 20) - 0x10, fragment67_ROM_START, fragment68_ROM_START, 1, (void *)temp_s0);
                state = 1;
                func_8006C9C0((void *)temp_s0);
                func_8006AC4C(0);
            }
            break;
        }
        main_pool_pop_state(0x62746C70);
    } while (state != 0);
    func_8006A2EC();
    main_pool_pop_state(0x62747063);
    if (sp290 != 0) {
        Game_SetState(1);
    } else {
        Game_SetState(3);
        func_80065D90(1);
    }
}
#endif
