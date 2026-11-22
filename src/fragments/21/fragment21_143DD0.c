#include "global.h"
extern s16 D_82508F6E;
extern u8 *D_82508F84;
extern s16 D_82508F6A;
extern u8 D_82508D10[];
extern s16 D_82508F7E;
extern s16 D_82508F70;
extern void *D_82508680;
extern void func_800355E4(s32);
extern void func_800226C0(s32);
extern void *D_80087200;
void func_8250202C(void);
s32 func_82502104(void);
s32 func_82502114(void);
extern u8 D_82508FD0[];
extern void func_8004C4B0();
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern s16 D_82508F72;
void func_82502854(s32 arg0);
s16 func_825028E8(u8 *arg0);
s32 func_82502E60(s32 arg0, s32 arg1, s32 arg2, void *arg3, u16 arg4);
extern s32 D_82508D00;
void func_82502EBC(s32 arg0, s32 arg1);
void func_82503840(void);
void func_825038A4(u8 *arg0);
s32 func_82503DDC(void);

#ifdef VERSION_US
extern s32 func_82502104(void);
extern s32 func_82502114(void);
s32 func_82503E50(void) { s32 result; result = 0; if (func_82502104() != 0) { if (func_82502114() == 0x201) { result = 2; } else { result = 1; } } return result; }
#endif

#ifdef VERSION_US
extern s32 func_82507CF4();
s32 func_82503E98(void) {
    s32 result = 0;
    if (func_82507CF4() != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_82503EC8(void) {
    s32 result = 0;
    if (func_82507CF4() != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_82503EF8(void) {
    s32 result = 0;
    if (func_82507CF4() != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern void func_82507B6C(s32, s16);
extern s32 StageContext_GetFadeMode(void);
extern s32 func_82507AF4(void);
extern void func_81700C0C(s32);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern s32 func_80001FF0(void);
extern s16 D_82508F70;
extern u8 D_82508F68[];
extern s16 D_82508D0E;
s32 func_82503F28(s32 arg0, s32 arg1) {
    static struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
    } D_82508F78;
    s32 padA[1];
    s32 state = arg0;
    s32 padB[3];
    u8 *a2 = D_82508F84;
    u8 *rec;
    u8 *a1;

    switch (arg0) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                if (func_82502E60(*(s16 *)D_82508F68, D_82508F6A, *(s16 *)((u8 *)D_82508680 + 2), D_82508D10,
                                  *(u16 *)D_82508FD0) == 0) {
                    state = 2;
                    func_82507AF4();
                    if (arg1 == 0) {
                        func_81700C0C(0);
                    }
                    D_82508F7E = 1;
                } else {
                    state = 1;
                    D_82508F78.unk2 = 0;
                    D_82508F78.unk4 = 0;
                }
            }
            break;

        case 1:
            D_82508F78.unk2++;
            if (D_82508F78.unk2 >= func_80001FF0() / 2 + 10) {
                D_82508F78.unk2 = 0;
                D_82508F78.unk4 = 0;
                state = 2;
                // D_82508F68 read through the same symbol as the stores above, so that
                // the assembler keeps the load after them (separate symbols get reordered).
                if (!(((s16 *)&D_82508F78)[-8] == 1 &&
                      *(s16 *)(*(u8 **)(a2 + 0x1C) + D_82508F6A * 0x30 + 0x26) == 0xE)) {
                    func_82507AF4();
                    if (arg1 == 0) {
                        func_81700C0C(0);
                    }
                }
                D_82508F7E = 1;
            }
            break;

        case 2:
            arg1 = func_82503988();
            if (arg1 != 0) {
                switch ((u32)arg1) {
                    case -1:
                        state = 8;
                        D_82508D0E = -1;
                        StageContext_SetClearColor(0xFFFF);
                        StageFade_StartFromTransparent(5);
                        func_80035424(0xF);
                        goto end;
                    case -2:
                        state = 3;
                        D_82508D0E = -1;
                        D_82508F70 = 1;
                        break;
                    case -3:
                        state = 4;
                        D_82508D0E = -1;
                        break;
                    case -4:
                        state = 6;
                        break;
                    default:
                        rec = *(u8 **)(a2 + 0x1C) + arg1 * 0x30 - 0x30;
                        D_82508D0E = *(s32 *)rec - 1;
                        a1 = D_82508D10 + arg1 * 0x3C - 0x3C;
                        if (*(s16 *)(a2 + 8) == 0 && **(u8 **)(D_82508D10 + arg1 * 0x3C - 0x30) == 1) {
                            state = 7;
                            func_82507BFC();
                            func_800226C0(0x8D);
                            func_800225C4(func_80001FF0());
                            goto end;
                        }
                        state = 5;
                        func_825038A4(a1);
                        if (*(s16 *)(rec + 0x24) != -1) {
                            func_82507B6C(0x31, *(s16 *)(rec + 0x24));
                        } else {
                            func_82507B6C(0x29, func_825028E8(*(u8 **)(a1 + 0xC)));
                        }
                        func_800226C0(0x8C);
                        D_82508F6E = 0;
                        break;
                }
            }
            break;

        case 3:
            arg1 = func_82503DDC();
            if (arg1 != 0) {
                if (arg1 != -1) {
                    if (arg1 == 1) {
                        state = 7;
                        func_82507BFC();
                        func_800226C0(0x8D);
                        func_800225C4(func_80001FF0());
                        goto end;
                    }
                } else {
                    state = 2;
                    D_82508F6E = 1;
                }
            }
            break;

        case 4:
            arg1 = func_82503E50();
            if (arg1 != 0) {
                if (arg1 == 2) {
                    state = 8;
                    D_82508D0E = -2;
                    StageContext_SetClearColor(0xFFFF);
                    StageFade_StartFromTransparent(5);
                    func_80035424(5);
                    goto end;
                }
                state = 2;
            }
            break;

        case 5:
            if (func_82503EC8() != 0) {
                state = 9;
            }
            break;

        case 6:
            if (func_82503EF8() != 0) {
                state = 9;
            }
            break;

        case 7:
            if (func_82503E98() != 0) {
                state = 8;
                StageContext_SetClearColor(0xFFFF);
                StageFade_StartFromTransparent(5);
                goto end;
            }
            break;

        case 8:
            if (StageContext_GetFadeMode() == 1) {
                state = 9;
            }
            break;
    }
end:
    return state;
}

#endif

#ifdef VERSION_US
extern s16 D_82508F72;
extern void func_8004C09C();
extern void func_8004C4B0();
extern void func_8004C398();
extern void func_80008624();
extern void func_800086A4();
extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromOpaque();
extern void StageLoader_WaitForRetrace(void);
extern void func_80064D28();
extern void func_8170024C();
extern void func_825075B0();
extern void func_82502EBC();
extern s32 func_82503F28();
extern void func_8250202C(void);
extern void func_82503840(void);
s32 func_825043AC(s32 arg0, s32 arg1) {
    s32 state = 0;
    s32 result;

    func_8004C09C(0x147);
    func_8004C4B0(0x31);
    func_8004C4B0(0x29);
    func_8004C4B0(0x2A);
    func_82502EBC(arg0, arg1);
    func_80008624();
    if (StageContext_GetFadeMode() != 0) {
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    do {
        func_80064D28();
        func_825075B0();
        func_8170024C();
        func_8250202C();
        func_82503840();
        state = func_82503F28(state, arg1);
    } while (state != 9);
    StageLoader_WaitForRetrace();
    switch (D_82508F72) {
        case 1:
        case 2:
        case 3:
        case 4:
            result = D_82508F72;
            break;
        default:
            result = 5;
            break;
    }
    func_8004C398();
    func_800226C0(0x122);
    return result;
}
#endif

#ifdef VERSION_US
extern void Fragment_LoadAndCall(s32, s32 *, s32 *, s32, s32);
s32 func_800718B8(s32);
extern u8 D_82C00000;
extern u8 fragment83_ROM_START;
extern u8 fragment84_ROM_START;

void func_825044D0(void) {
    Fragment_LoadAndCall(((u32) ((s32) &D_82C00000 & 0x0FF00000) >> 0x14) - 0x10, &fragment83_ROM_START, &fragment84_ROM_START, 0x300, func_800718B8(6));
}
#endif

#ifdef VERSION_US
extern void *D_82508680;
extern s16 D_82508F6A;
void func_82504524(void) {
    u8 *state;
    u8 *node;
    u8 *entry;
    state = D_82508F68;
    node = *(u8 **)(state + 0x1C);
    entry = *(s16 *)(state + 2) * 0x30 + *(u8 **)(node + 0x1C);
    *(s16 *)((u8 *)D_82508680 + 8) = *(s16 *)state;
    switch (*(s16 *)((u8 *)D_82508680 + 8)) {
        case 1:
            *(s16 *)((u8 *)D_82508680 + 0xA) = D_82508F6A;
            if (*(s16 *)(entry + 0x20) != -1) {
                *(s16 *)((u8 *)D_82508680 + 0xA) -= 1;
                if (*(s16 *)((u8 *)D_82508680 + 0xA) < 0) {
                    *(s16 *)((u8 *)D_82508680 + 0xA) = 0;
                }
            }
            break;
        case 3:
            *(s16 *)((u8 *)D_82508680 + 0xC) = D_82508F6A;
            break;
        case 2:
            *(s16 *)((u8 *)D_82508680 + 0xE) = D_82508F6A;
            break;
    }
}
#endif

#ifdef VERSION_US
extern s16 D_82508D0E;
// Returns D_82508D0E + 1 when it is non-negative, 100 when it is -2 and 0 otherwise.
s32 func_825045EC(void) {
    s32 result = 0;
    s16 *value = &D_82508D0E; // FAKE: pointer alias that makes each test reload the global; diff score 460 without it.

    if (*value >= 0) {
        result = *value + 1;
    } else if (*value == -2) {
        result = 100;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_80055948(s32);
extern void func_82502854(s32);
extern void func_80008514(s32);
extern s32 func_8006D268(s32);
extern s32 func_82504BA0(s32 *, s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void Gfx_FreeDisplayListBuffers(void);

extern s32 D_82508D00;
extern void StageLoader_WaitForRetrace(void);
extern void func_800355E4(s32);
extern void func_80064D28();
extern s32 func_825043AC(s32 arg0, s32 arg1);
extern void func_825044D0(void);
extern void func_82504524(void);
extern void * D_80087200;
extern void * D_82508680;
void func_82504628(s32 arg0, u8 *arg1) {
    s32 state;
    s32 prev;
    s32 config;
    s32 back;

    state = *(s16 *)(arg1 + 8);
    D_82508680 = arg1;
    prev = state;
    main_pool_push_state(0x47594D4C); // 'GYML'
    Gfx_InitDisplayListBuffers(0x10000, 0);
    config = func_800082E0(1, 0, 2, 0, 2, 1);
    func_80047588(28, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_80055948(3);
    func_82502854(state);
    func_80008514(config);
    StageLoader_WaitForRetrace();
    if (func_8006D268(0x301) != 0) {
        func_80064D28();
        if (*(u16 *)((u8 *)D_80087200 + 6) & 0x2000) {
            state = 0;
        }
    }
    do {
        main_pool_push_state(0x6C6F6F70); // 'loop'
        switch (state) {
            case 0:
                func_800355E4(62);
                prev = state;
                state = func_82504BA0(&D_82508D00, state);
                break;
            case 4:
                func_825044D0();
                state = prev;
                prev = 4;
                break;
            default:
                back = prev == 4;
                prev = state;
                state = func_825043AC(state, back ? 1 : 0);
                func_82504524();
                break;
        }
        main_pool_pop_state(0x6C6F6F70);
    } while (state != 5);
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x47594D4C);
    func_825045EC();
}
#endif
