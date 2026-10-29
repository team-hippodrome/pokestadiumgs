#include "global.h"


#ifdef VERSION_US
#pragma pack(1)
typedef struct { s32 a; s32 b; u8 c; } Copy9Layout;
#pragma pack(0)
extern void _bzero(void *, s32);
void func_80068A50(void *arg0, void *arg1) {
    if (arg0 != NULL) {
        _bzero(arg0, 0x5C);
        *(u8 *)arg0 = 0;
        *(Copy9Layout *)((u8 *)arg0 + 4) = *(Copy9Layout *)arg1;
    }
}

extern s32 func_8006A3B8(u16);
extern s32 func_8006A400(s32);
void func_80068AB0(u32 arg0) {
    u16 id = 0xFFFF;
    s16 level = 4;

    switch (arg0) {
    case 0:
        id = 0x200;
        break;
    case 1:
        id = 0x202;
        level = 1;
        break;
    case 2:
        id = 0x202;
        level = 2;
        break;
    case 3:
        id = 0x202;
        level = 3;
        break;
    case 4:
        id = 0x202;
        break;
    case 5:
        id = 0x220;
        break;
    case 7:
        id = 0x201;
        level = 1;
        break;
    case 8:
        id = 0x201;
        level = 2;
        break;
    case 9:
        id = 0x201;
        level = 3;
        break;
    case 10:
        id = 0x201;
        break;
    case 12:
    case 13:
        id = 0x203;
        break;
    case 14:
        id = 0x210;
        break;
    }
    func_8006A3B8(id);
    func_8006A400(level);
}

typedef struct SceneConfig69650 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} SceneConfig69650;

typedef struct Unk68B78 {
    u8 unk_00[0x10];
    u8 unk_10[0x34];
    s16 unk_44;
    u8 unk_46[0xE];
    s8 unk_54;
    s8 unk_55;
    s8 unk_56;
    s8 unk_57;
    u32 bf_00 : 5;
    u32 bf_05 : 2;
    u32 bf_07 : 1;
    u32 bf_08 : 1;
} Unk68B78;

extern SceneConfig69650 D_8009DF30;
extern void func_8006A444(s32);
extern void func_8006A4AC(void *);
extern void func_8006ABD8(void *);
extern void func_8006AC28(s32);
extern void func_8006AE90(u32);
extern void func_80064CB8(s32);
extern void func_80064CD0(u32);
extern s32 func_8006A3E0(void);
extern s32 func_8006A424(void);
extern s32 func_8006A388(void);
extern void func_8006AB8C(u16, s32, s32);

void func_80068B78(Unk68B78 *arg0) {
    SceneConfig69650 sp38;
    s32 var_a1;
    u16 temp_s0;

    sp38 = D_8009DF30;
    func_80068AB0(arg0->unk_44);
    if (arg0->unk_44 != 0xE) {
        func_8006A444(arg0->unk_44);
    } else {
        func_8006A4AC(arg0->unk_10);
    }
    var_a1 = 0;
    if (arg0->bf_08) {
        var_a1 = 1;
        sp38.unk_00 = arg0->unk_54;
        sp38.unk_04 = arg0->unk_55;
        sp38.unk_08 = arg0->unk_56;
        sp38.unk_0C = arg0->unk_57;
        if (sp38.unk_08 == -1) {
        }
    } else {
        sp38.unk_00 = arg0->unk_54;
        sp38.unk_04 = arg0->unk_56;
        sp38.unk_08 = -2;
        sp38.unk_0C = -2;
    }
    func_8006ABD8(&sp38);
    func_8006AC28(var_a1);
    func_8006AE90(arg0->bf_00);
    func_80064CB8(0);
    func_80064CD0(arg0->bf_05);
    temp_s0 = func_8006A3E0();
    func_8006AB8C(temp_s0, func_8006A424(), func_8006A388());
}

extern u8 D_81600000[];
extern u8 D_81800000[];
extern u8 D_81700000[];
extern u8 D_83100000[];
extern u8 fragment4_ROM_START[];
extern u8 fragment5_ROM_START[];
extern u8 fragment6_ROM_START[];
extern u8 fragment7_ROM_START[];
extern u8 fragment11_ROM_START[];
extern u8 fragment12_ROM_START[];
extern u8 fragment18_ROM_START[];
extern u8 fragment19_ROM_START[];
extern void *main_pool_alloc(s32, s32);
extern void func_80068A50(void *, void *);
extern void Fragment_Load(s32, void *, void *);
extern s32 Fragment_LoadAndCall(s32, void *, void *, u32, void *);
s32 func_80068CBC(void *arg0) {
    s32 var_v1;
    s32 sp2C;
    void *temp_v0;
    temp_v0 = main_pool_alloc(0x5C, 0);
    func_80068A50(temp_v0, arg0);
    Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment12_ROM_START);
    Fragment_Load((((u32)D_81800000 & 0x0FF00000) >> 20) - 0x10, fragment4_ROM_START, fragment5_ROM_START);
    Fragment_Load((((u32)D_81700000 & 0x0FF00000) >> 20) - 0x10, fragment18_ROM_START, fragment19_ROM_START);
    Fragment_LoadAndCall((((u32)D_83100000 & 0x0FF00000) >> 20) - 0x10, fragment6_ROM_START, fragment7_ROM_START, 0, temp_v0);
    var_v1 = 1;
    *(Copy9Layout *)arg0 = *(Copy9Layout *)((u8 *)temp_v0 + 4);
    if ((*(u8 *)((u8 *)temp_v0 + 0x58) & 1) != 0) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    if (var_v1 != 0) {
        sp2C = var_v1;
        func_80068B78(temp_v0);
    }
    return var_v1;
}

typedef struct SceneContext69650 {
    u8 unk_00[0x2C];
    void *unk_2C;
} SceneContext69650;

extern u8 D_81100000[];
extern u8 D_81300000[];
extern u8 D_81400000[];
extern u8 D_82600000[];
extern u8 D_84100000[];
extern u8 D_84200000[];
extern u8 D_84300000[];
extern u8 fragment11_ROM_END[];
extern u8 fragment13_ROM_START[];
extern u8 fragment14_ROM_START[];
extern u8 fragment15_ROM_START[];
extern u8 fragment20_ROM_START[];
extern u8 fragment21_ROM_START[];
extern u8 fragment27_ROM_START[];
extern u8 fragment28_ROM_START[];
extern u8 fragment79_ROM_START[];
extern u8 fragment80_ROM_START[];
extern u8 fragment81_ROM_START[];
extern u8 fragment82_ROM_START[];

extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern SceneContext69650 *BattleScene_ResetParticipantModelFlags(s32);
extern s32 Audio_SetModeBlocking(s32, s32, s32);
extern void func_8006A180(void);
extern void *func_8006B928(void);
extern s32 func_8006C58C(void);
extern void func_8006AC4C(s32);
extern void func_8006ACCC(s32);
extern void func_8006B0B8(void);
extern void *func_8006BAC4(void);
extern s32 func_8006AEB4(void);
extern void func_80026938(u16);
extern s32 func_8006A48C(void);
extern s32 func_8006A51C(s32);
extern void func_800355E4(s32);
extern void *func_8006C664(void);
extern u8 *func_8006C644(void);
extern s32 func_8006A328(u16);
extern s32 func_8006A2F8(u16);
extern void func_8006A2EC(void);
extern void Game_SetState(s32);

void func_80068E14(void) {
    s32 state;
    void *sp90;
    void *sp8C;
    u8 *sp88;
    u32 var_fp;
    s32 i;
    SceneContext69650 *context;
    s32 temp_s0;
    s32 pad74;
    s32 pad70;
    Copy9Layout sp64;
    s32 pad60;
    s16 sp5C[2];

    state = 0xA;
    var_fp = 1;
    for (i = 0; i < 2; i++) {
        sp5C[i] = 0;
    }
    main_pool_push_state(0x62747063);
    context = BattleScene_ResetParticipantModelFlags(0);
    do {
        main_pool_push_state(0x62746C70);
        switch (state) {
        case 10:
            Audio_SetModeBlocking(7, 0, 0);
            if (var_fp != 0) {
                var_fp = 0;
                _bzero(&sp64, sizeof(Copy9Layout));
            }
            func_8006A180();
            if (func_80068CBC(&sp64) != 0) {
                if ((func_8006A3E0() & 0xFF) != 2U) {
                    state = 3;
                } else {
                    state = 4;
                }
                for (i = 0; i < 2; i++) {
                    sp5C[i] = 0;
                }
            } else {
                state = 0;
            }
            break;
        case 3:
            Audio_SetModeBlocking(7, 0, 0);
            sp90 = func_8006B928();
            if (sp90 != NULL) {
                Fragment_Load((((u32)D_81700000 & 0x0FF00000) >> 20) - 0x10, fragment18_ROM_START, fragment19_ROM_START);
                Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment11_ROM_END);
                if (Fragment_LoadAndCall((((u32)D_81300000 & 0x0FF00000) >> 20) - 0x10, fragment14_ROM_START, fragment15_ROM_START, 0, sp90) != 1) {
                    state = 0xA;
                } else {
                    state = 4;
                }
            }
            break;
        case 4:
            Audio_SetModeBlocking(9, 0, 0);
            state = 5;
            if (func_8006C58C() != 0) {
                Fragment_Load((((u32)D_84300000 & 0x0FF00000) >> 20) - 0x10, fragment81_ROM_START, fragment82_ROM_START);
                Fragment_LoadAndCall((((u32)D_82600000 & 0x0FF00000) >> 20) - 0x10, fragment20_ROM_START, fragment21_ROM_START, 1U, context->unk_2C);
                func_8006AC4C(*(s16 *)((u8 *)context->unk_2C + 0x88));
                func_8006ACCC(*(s16 *)((u8 *)context->unk_2C + 0x8A));
                if ((func_8006A3E0() & 0xFF) == 2U) {
                    func_8006B0B8();
                }
            }
            break;
        case 5:
            sp8C = func_8006BAC4();
            if (sp8C != NULL) {
                Fragment_Load((((u32)D_84200000 & 0x0FF00000) >> 20) - 0x10, fragment80_ROM_START, fragment81_ROM_START);
                Fragment_Load((((u32)D_81600000 & 0x0FF00000) >> 20) - 0x10, fragment11_ROM_START, fragment11_ROM_END);
                if (Fragment_LoadAndCall((((u32)D_81400000 & 0x0FF00000) >> 20) - 0x10, fragment12_ROM_START, fragment13_ROM_START, 0, sp8C) != 1) {
                    state = 3;
                } else {
                    state = 6;
                }
            }
            break;
        case 6:
            func_80026938(func_8006AEB4());
            state = 8;
            Audio_SetModeBlocking(8, func_8006A51C(func_8006A48C()), 0xA);
            func_800355E4(0x5A);
            Fragment_Load((((u32)D_81100000 & 0x0FF00000) >> 20) - 0x10, fragment27_ROM_START, fragment28_ROM_START);
            temp_s0 = func_8006AEB4();
            Fragment_LoadAndCall((((u32)D_84100000 & 0x0FF00000) >> 20) - 0x10, fragment79_ROM_START, fragment80_ROM_START, temp_s0, func_8006C664());
            break;
        case 8:
            Audio_SetModeBlocking(0xA, 0, 0);
            sp88 = func_8006C644();
            if (sp88 != NULL) {
                for (i = 0; i < 2; i++) {
                    ((s16 *)(sp88 + 0x900))[i] = sp5C[i];
                }
                temp_s0 = Fragment_LoadAndCall((((u32)D_82600000 & 0x0FF00000) >> 20) - 0x10, fragment20_ROM_START, fragment21_ROM_START, 2U, context->unk_2C);
                for (i = 0; i < 2; i++) {
                    sp5C[i] = ((s16 *)(sp88 + 0x900))[i];
                }
                func_8006A328(2);
                switch (temp_s0) {
                case 1:
                case 2:
                    state = 4;
                    func_8006A2F8(2);
                    break;
                case 5:
                    state = 0xA;
                    var_fp = 1;
                    break;
                default:
                    state = 0;
                    break;
                }
            }
            break;
        }
        main_pool_pop_state(0x62746C70);
    } while (state != 0);
    func_8006A2EC();
    main_pool_pop_state(0x62747063);
    Game_SetState(3);
}
#endif
