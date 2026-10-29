#include "global.h"


#ifdef VERSION_US
extern u8 D_83500000[];
extern u8 D_87F00000[];
extern u8 fragment1_ROM_START[];
extern u8 fragment2_ROM_START[];
extern u8 fragment64_ROM_START[];
extern u8 fragment65_ROM_START[];
void Audio_ResetModeSelector(void);
s32 Audio_SetModeBlocking(s32 mode, s32 arg1, s32 arg2);
void Fragment_Load(s32, void *, void *);
s32 Fragment_LoadAndCall(s32, void *, void *, s32, void *);
s32 GbSave_GetPortAvailability(s32 arg0);
s32 func_8006A388(void);
s32 func_8006A424(void);
s32 func_8006CBB8(s32 arg0);
void *main_pool_alloc(s32, s32);

typedef struct unk_func_80067300 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
} unk_func_80067300;

s32 func_80067300(u8 *arg0) {
    s32 pad1; // FAKE: unreferenced stack slot 0x34; diff score 64 without it (42 without both pads).
    s32 sp30;
    s32 pad2; // FAKE: unreferenced stack slot 0x2C; diff score 48 without it.
    s32 sp28;
    s32 sp24;
    unk_func_80067300 *sp20;
    s32 ret;

    sp30 = 0;
    sp28 = func_8006CBB8(func_8006A424());
    sp20 = main_pool_alloc(8, 0);
    if (sp28 == 2) {
        sp24 = 1;
    } else {
        if (*(s8 *)(arg0 + 0x93C) >= 0 && *(s8 *)(arg0 + 0x93C) < 4 &&
            !GbSave_GetPortAvailability(*(s8 *)(arg0 + 0x93C))) {
            sp30 = 1;
        }
        sp24 = 0;
    }
    _bzero(sp20, 8);
    sp20->unk_00 = sp30;
    sp20->unk_02 = func_8006A388();
    sp20->unk_04 = sp24;
    Audio_ResetModeSelector();
    Audio_SetModeBlocking(10, 0, 0);
    Fragment_Load((((u32)D_87F00000 & 0x0FF00000) >> 20) - 0x10, fragment64_ROM_START, fragment65_ROM_START);
    Fragment_LoadAndCall((((u32)D_83500000 & 0x0FF00000) >> 20) - 0x10, fragment1_ROM_START, fragment2_ROM_START,
                         0, sp20);
    if (sp24 == 0) {
        if (sp30 != 0) {
            ret = 0;
        } else {
            ret = 1;
        }
    } else {
        ret = -1;
    }
    return ret;
}

struct Func800675A0Source;
typedef struct { s32 words[24]; } Func80067454Copy;
void func_80067454(struct Func800675A0Source *arg0, void *arg1) {
    Func80067454Copy *dst;
    Func80067454Copy *src;
    s32 i;
    dst = (Func80067454Copy *)arg0;
    src = *(Func80067454Copy **)((u8 *)arg1 + 0x24);
    for (i = 0; i < 6; i++) {
        ((Func80067454Copy *)arg0)[i] = ((Func80067454Copy *)src)[i];
    }
    ((u8 *)arg0)[0x240] = 0;
}

typedef struct Func800675A0Record {
    s32 words[24];
} Func800675A0Record;

typedef struct Func800675A0Source {
    Func800675A0Record records[6];
    u8 pad240[4];
    s8 index;
    s8 value245;
    u8 value246;
} Func800675A0Source;

typedef struct Func800675A0Dest {
    u16 value0;
    s16 value2;
    Func800675A0Record record;
} Func800675A0Dest;

void func_800675A0(Func800675A0Dest *arg0, Func800675A0Source *arg1) {
    arg0->value0 = arg1->value246;
    arg0->value2 = arg1->value245;
    arg0->record = arg1->records[arg1->index];
}

extern u8 D_81600000[];
extern u8 D_81800000[];
extern u8 D_81A00000[];
extern u8 D_82F00000[];
extern u8 D_83300000[];
extern u8 fragment11_ROM_START[];
extern u8 fragment12_ROM_START[];
extern u8 fragment3_ROM_START[];
extern u8 fragment4_ROM_START[];
extern u8 fragment5_ROM_START[];
extern u8 fragment8_ROM_START[];
extern u8 fragment9_ROM_START[];
extern u8 fragment57_ROM_START[];
extern u8 fragment58_ROM_START[];
void main_pool_push_state(s32);
void main_pool_pop_state(s32);
void func_800354B4(s32, s32, s32);
void func_80067454(Func800675A0Source *, void *);
void func_800675F8(void *arg0) {
    Func800675A0Source *sp2C;
    Func800675A0Dest *sp28;
    s32 sp24;
    s8 temp_v1;

    sp24 = 0;
    main_pool_push_state(0x777A7063);
    sp2C = main_pool_alloc(0x248, 0);
    sp28 = main_pool_alloc(0x64, 0);
    func_800354B4(0xA, 0, 0);
    main_pool_push_state(0x77617A61);
    func_80067454(sp2C, arg0);
    Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10,
        fragment11_ROM_START, fragment12_ROM_START);
    Fragment_Load((((u32)D_81800000 & 0x0FF00000) >> 20) - 0x10,
        fragment4_ROM_START, fragment5_ROM_START);
    Fragment_LoadAndCall((((u32)D_82F00000 & 0x0FF00000) >> 20) - 0x10,
        fragment8_ROM_START, fragment9_ROM_START, 0, sp2C);
    temp_v1 = sp2C->index;
    if ((temp_v1 >= 0) && (temp_v1 < 6)) {
        sp24 = 1;
        func_800675A0(sp28, sp2C);
    }
    main_pool_pop_state(0x77617A61);
    if (sp24 != 0) {
        func_800354B4(0xC, 0, 0);
        main_pool_push_state(0x77617A61);
        Fragment_Load((((u32)D_81A00000 & 0x0FF00000) >> 20) - 0x10,
            fragment3_ROM_START, fragment4_ROM_START);
        Fragment_Load((((u32)D_87F00000 & 0x0FF00000) >> 20) - 0x10,
            fragment64_ROM_START, fragment65_ROM_START);
        Fragment_LoadAndCall((((u32)D_83300000 & 0x0FF00000) >> 20) - 0x10,
            fragment57_ROM_START, fragment58_ROM_START, 0, sp28);
        main_pool_pop_state(0x77617A61);
    }
    main_pool_pop_state(0x777A7063);
}

s32 func_80067800(s32 arg0) {
    s32 result = 0;

    switch (arg0) {
        case 1: result = 5; break;
        case 2: result = 6; break;
        case 3: result = 7; break;
        case 4: result = 8; break;
        case 5: result = 9; break;
        case 6: result = 10; break;
        case 7: result = 11; break;
        case 8: result = 12; break;
        case 9: result = 13; break;
        case 10: result = 14; break;
        case 11: result = 15; break;
        case 12: result = 16; break;
        case 13: result = 17; break;
        case 14: result = 18; break;
        case 15: result = 19; break;
        case 16: result = 20; break;
        case 17: result = 21; break;
        case 18: result = 22; break;
        case 19: result = 23; break;
        case 20: result = 24; break;
    }
    return result;
}

s32 func_80067800(s32);
s32 func_800678CC(s32 arg0) {
    s32 result;
    s32 i;

    result = 0;
    i = 1;
loop:
    if (func_80067800(i) == arg0) {
        result = i;
    } else {
        i += 1;
        if (i != 0x15) {
            goto loop;
        }
    }
    return result;
}

void func_80067930(s32 arg0, s32 *arg1, s32 *arg2) {
    switch (arg0) {
    case 1:
        *arg1 = 0xA;
        *arg2 = 0;
        return;
    case 2:
        *arg1 = 0xA;
        *arg2 = 2;
        return;
    case 3:
        *arg1 = 0xA;
        *arg2 = 5;
        return;
    case 4:
        *arg1 = 0xA;
        *arg2 = 8;
        return;
    case 5:
        *arg1 = 0xA;
        *arg2 = 0xB;
        return;
    case 6:
        *arg1 = 0xA;
        *arg2 = 0xD;
        return;
    case 7:
        *arg1 = 0xA;
        *arg2 = 0xE;
        return;
    case 8:
        *arg1 = 0xA;
        *arg2 = 0x12;
        return;
    case 9:
        *arg1 = 0xA;
        *arg2 = 0x15;
        return;
    case 10:
        *arg1 = 0xB;
        *arg2 = -1;
        return;
    case 11:
        *arg1 = 0xC;
        *arg2 = -1;
        return;
    case 12:
        *arg1 = 0xD;
        *arg2 = 2;
        return;
    case 13:
        *arg1 = 0xD;
        *arg2 = 5;
        return;
    case 14:
        *arg1 = 0xD;
        *arg2 = 1;
        return;
    case 15:
        *arg1 = 0xD;
        *arg2 = 3;
        return;
    case 16:
        *arg1 = 0xD;
        *arg2 = 4;
        return;
    case 17:
        *arg1 = 0xD;
        *arg2 = 0;
        return;
    case 18:
        *arg1 = 0xD;
        *arg2 = 6;
        return;
    case 19:
        *arg1 = 0xD;
        *arg2 = 7;
        return;
    case 20:
        *arg1 = 0xE;
        *arg2 = -1;
        /* fallthrough */
    default:
        return;
    }
}
void func_80067930(s32, s32 *, s32 *);
u16 func_8006A3E0(void);
s32 func_8006AB8C(u16, s32, s32);
void func_80067AE0(s32 arg0, s32 *arg1, s32 *arg2) {
    volatile u8 pad[8];
    s32 sp1C;
    u16 sp1A;

    func_8006A400(func_80067800(arg0));
    sp1A = func_8006A3E0();
    sp1C = func_8006A424();
    func_8006AB8C(sp1A, sp1C, func_8006A388());
    func_80067930(arg0, arg1, arg2);
}

s32 func_80067800();
void func_80067930();
s32 func_8006AB8C(u16, s32, s32);
s32 func_80067B48(s32 arg0) {
    s32 result;

    switch (func_8006CBB8(arg0)) {
    case 1:
        result = 2;
        break;
    case 2:
        result = 3;
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

typedef struct SceneConfig67B8C {
    s32 words[4];
} SceneConfig67B8C;

typedef struct SceneContext67B8C {
    u8 unk_00[0x24];
    u8 *unk_24;
    u8 unk_28[4];
    void *unk_2C;
} SceneContext67B8C;

typedef struct UnkCAE0 {
    u8 unk_00[8];
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
} UnkCAE0;

extern SceneConfig67B8C D_8009DF10;
extern u8 D_81100000[];
extern u8 D_81300000[];
extern u8 D_81400000[];
extern u8 D_81700000[];
extern u8 D_82500000[];
extern u8 D_82600000[];
extern u8 D_84100000[];
extern u8 D_84200000[];
extern u8 fragment13_ROM_START[];
extern u8 fragment14_ROM_START[];
extern u8 fragment15_ROM_START[];
extern u8 fragment18_ROM_START[];
extern u8 fragment19_ROM_START[];
extern u8 fragment20_ROM_START[];
extern u8 fragment21_ROM_START[];
extern u8 fragment22_ROM_START[];
extern u8 fragment27_ROM_START[];
extern u8 fragment28_ROM_START[];
extern u8 fragment79_ROM_START[];
extern u8 fragment80_ROM_START[];
extern u8 fragment81_ROM_START[];

SceneContext67B8C *func_8006A160(s32, void *, void *);
void func_8006A444(s32);
void func_8006AC28(s32);
void func_8006ABD8(void *);
s32 func_8006A35C(s32);
void func_8006CDA0(void *, void *);
void func_8006A3B8(s32);
s32 func_8006CAE0(s32, s32, s32, s32, s32, u16);
void func_8006CB80(s32);
void func_8006A180(void);
void *func_8006B928(void);
s32 func_8006C58C(void);
void func_8006AC4C(s32);
void func_8006ACCC(s32);
s32 func_8006AC70(void);
s32 func_8006AD10(u16, s32, s32);
void func_8006AE90(s32);
void *func_8006BAC4(void);
s32 func_8006AEB4(void);
void func_80026938(u16);
void func_800355E4(s32);
void *func_8006C664(void);
s32 func_8006C644(void);
s32 func_8006AC90(void);
void func_8006A328(s32);
void func_8006A2EC(void);
void Game_SetState(s32);
void func_80065D90(s32);

void func_80067B8C(void) {
    s32 state;
    s32 temp_v0;
    void *sp2DC;
    void *sp2D8;
    s32 temp_s0_3;
    s32 var_s5;
    s32 var_s6;
    s32 var_s3;
    s32 sp2C4;
    s32 sp2C0;
    SceneContext67B8C *context;
    s32 sp2B8;
    s32 sp2B4;
    s32 sp2B0;
    u8 sp288[0x28];
    u8 sp78[0x210];
    s32 sp74;
    u16 sp72;
    SceneConfig67B8C config;

    sp2C4 = 0;
    sp2C0 = 0;
    sp2B8 = -1;
    sp2B4 = -1;
    sp2B0 = -1;
    sp74 = 0;
    sp72 = 0;
    config = D_8009DF10;
    state = 2;
    var_s5 = 1;
    var_s6 = -1;
    var_s3 = 0;
    main_pool_push_state(0x62747063);
    context = func_8006A160(1, sp288, sp78);
    func_8006A444(6);
    func_8006AC28(0);
    func_8006ABD8(&config);
    if (func_8006A35C(4) != 0) {
        func_8006CDA0(sp288, sp78);
        state = 4;
        func_80067AE0(func_800678CC(func_8006A424()), &sp2C4, &sp2C0);
        var_s5 = func_80067B48(func_8006A424());
        switch (var_s5) {
        case 1:
            sp2B8 = -2;
            break;
        case 2:
            sp2B0 = -2;
            break;
        case 3:
            sp2B4 = -2;
            break;
        }
        sp72 = func_8006A424();
    } else {
        func_8006A3B8(0x300);
    }
    do {
        main_pool_push_state(0x62746C70);
        switch (state) {
        case 2:
            Audio_SetModeBlocking(7, 0, 0);
            Fragment_Load((((u32)D_81700000 & 0x0FF00000) >> 20) - 0x10, fragment18_ROM_START, fragment19_ROM_START);
            Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment12_ROM_START);
            temp_s0_3 = func_8006CAE0(var_s5, sp2B8, sp2B4, sp2B0, var_s6, sp72);
            var_s6 = -1;
            temp_v0 = Fragment_LoadAndCall((((u32)D_82500000 & 0x0FF00000) >> 20) - 0x10, fragment21_ROM_START, fragment22_ROM_START, 0, (void *)temp_s0_3);
            if (temp_v0 == 0) {
                state = 0;
            } else if (temp_v0 == 0x64) {
                state = 0xC;
            } else {
                func_80067AE0(temp_v0, &sp2C4, &sp2C0);
                if (func_8006A424() != 0xF) {
                    var_s3 = 1;
                    state = 3;
                } else {
                    var_s3 = 0;
                    state = 4;
                }
            }
            var_s5 = ((UnkCAE0 *)temp_s0_3)->unk_08;
            sp2B8 = ((UnkCAE0 *)temp_s0_3)->unk_0A;
            sp2B4 = ((UnkCAE0 *)temp_s0_3)->unk_0C;
            sp2B0 = ((UnkCAE0 *)temp_s0_3)->unk_0E;
            func_8006CB80(temp_s0_3);
            break;
        case 3:
            if (var_s3 != 0) {
                func_8006A180();
                var_s3 = 0;
            }
            Audio_SetModeBlocking(7, 0, 0);
            sp2DC = func_8006B928();
            if (sp2DC != NULL) {
                Fragment_Load((((u32)D_81700000 & 0x0FF00000) >> 20) - 0x10, fragment18_ROM_START, fragment19_ROM_START);
                Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment12_ROM_START);
                if (Fragment_LoadAndCall((((u32)D_81300000 & 0x0FF00000) >> 20) - 0x10, fragment14_ROM_START, fragment15_ROM_START, 0, sp2DC) != 1) {
                    state = 2;
                } else {
                    state = 4;
                }
            }
            break;
        case 4:
            Audio_SetModeBlocking(9, 0, 0);
            state = 5;
            if (func_8006C58C() != 0) {
                Fragment_LoadAndCall((((u32)D_82600000 & 0x0FF00000) >> 20) - 0x10, fragment20_ROM_START, fragment21_ROM_START, 1, context->unk_2C);
                func_8006AC4C(*(s16 *)((u8 *)context->unk_2C + 0x88));
                func_8006ACCC(*(s16 *)((u8 *)context->unk_2C + 0x8A));
                func_8006AE90(func_8006AD10(func_8006A3E0(), func_8006A424(), func_8006AC70()));
            }
            break;
        case 5:
            sp2D8 = func_8006BAC4();
            if (sp2D8 != NULL) {
                Fragment_Load((((u32)D_84200000 & 0x0FF00000) >> 20) - 0x10, fragment80_ROM_START, fragment81_ROM_START);
                Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment12_ROM_START);
                if (Fragment_LoadAndCall((((u32)D_81400000 & 0x0FF00000) >> 20) - 0x10, fragment12_ROM_START, fragment13_ROM_START, 0, sp2D8) != 1) {
                    state = 3;
                } else {
                    state = 6;
                }
            }
            break;
        case 6:
            var_s6 = -1;
            func_80026938(func_8006AEB4());
            state = 8;
            if (sp2C0 != -1) {
                Audio_SetModeBlocking(8, sp2C4, func_8006AC70() + sp2C0);
            } else {
                Audio_SetModeBlocking(8, sp2C4, func_8006AC70() + 1);
            }
            func_800355E4(0x5A);
            Fragment_Load((((u32)D_81100000 & 0x0FF00000) >> 20) - 0x10, fragment27_ROM_START, fragment28_ROM_START);
            temp_s0_3 = func_8006AEB4();
            if (temp_s0_3 >= 0) {
                Fragment_LoadAndCall((((u32)D_84100000 & 0x0FF00000) >> 20) - 0x10, fragment79_ROM_START, fragment80_ROM_START, temp_s0_3, func_8006C664());
            }
            break;
        case 8:
            Audio_SetModeBlocking(0xA, 0, 0);
            if (func_8006C644() != 0) {
                switch (Fragment_LoadAndCall((((u32)D_82600000 & 0x0FF00000) >> 20) - 0x10, fragment20_ROM_START, fragment21_ROM_START, 2, context->unk_2C)) {
                case 2:
                    if (func_8006AC90() != 0) {
                        var_s6 = func_8006A424();
                        if (var_s6 == 0x18) {
                            state = 0xC;
                        } else {
                            state = 2;
                            func_8006AC4C(0);
                        }
                    } else {
                        state = 4;
                        func_8006AC4C(func_8006AC70() + 1);
                    }
                    break;
                case 3:
                case 4:
                    state = 3;
                    func_8006AC4C(0);
                    if (func_8006A424() == 0xF) {
                        sp2B0 = 0;
                        func_80067AE0(0xA, &sp2C4, &sp2C0);
                    }
                    if (func_8006A35C(4) != 0) {
                        var_s3 = 1;
                        func_8006A328(4);
                    }
                    break;
                case 7:
                    state = 0;
                    sp74 = 1;
                    break;
                default:
                    state = 0;
                    break;
                }
            }
            break;
        case 12:
            switch (func_80067300(context->unk_24)) {
            case 0:
                state = 0xD;
                break;
            case 1:
                state = 2;
                var_s5 = 3;
                break;
            default:
                state = 0;
                break;
            }
            break;
        case 13:
            func_800675F8(context);
            state = 2;
            var_s5 = 3;
            break;
        }
        main_pool_pop_state(0x62746C70);
    } while (state != 0);
    func_8006A2EC();
    main_pool_pop_state(0x62747063);
    if (sp74 != 0) {
        Game_SetState(1);
    } else {
        Game_SetState(3);
        func_80065D90(4);
    }
}

#endif
