#include "global.h"


#ifdef VERSION_US
extern void func_8414FC30(u8 *, u8);
extern void func_84150268(u8 *, u8);
extern void func_8414D198(u8 *, u8);
extern void func_84153E28(u8 *, u8);
extern void func_8414D348(u8 *, u8);
void func_8414EE20(u8 *arg0, u8 arg1) {
    func_8414FC30(arg0, (u8)arg1);
    func_84150268(arg0, (u8)arg1);
    func_8414D198(arg0, (u8)arg1);
    func_84153E28(arg0, (u8)arg1);
    func_8414D348(arg0, (u8)arg1);
}

/* mkdraft:func_8414EE88 begin */
void BattlePlan_ApplyPursuitMultiplier(u8 *, u8);
void BattleState_PushSnapshot(void);
u8 func_84148C74(u8);
u8 func_841493E8(void);
u8 func_841493F4(void);
s32 func_8414C858(u8 *);
u8 *func_8414C98C(u8 *);
void func_8414C9AC(u8 *, u8);
void func_8414ED5C(u8 *);
void func_84150330(u8 *, u8);
void func_84154820(u8, u8);
u8 func_84154B24(void);
void func_841557B0(void);



void func_8414EE88(u8 *arg0) {
    u8 side;
    u8 other_side;
    u8 count;
    u8 *plan;
    u8 amount;
    s32 count_word;
    side = func_84154B24();
    other_side = (1 - side) & 0xFF;
    count = func_841493F4();
    BattleState_PushSnapshot();
    plan = func_8414C98C(arg0);
    // FAKE: widens count into the s32 word that IDO compares in the tail test; inlining the
    // comparison as (count > 0) drops the widening and shifts every u8 home by 8 bytes (score 106).
    count_word = count;
    func_8414C9AC(plan, (0xFF - count) & 0xFF);
    *(u8 *)((u32)plan + (u32)other_side + 6) = func_84148C74(other_side);
    if (func_8414C858(plan) != 0) {
        plan[5] = side;
    } else {
        plan[5] = other_side;
    }
    func_8414EE20(plan, side);
    func_8414EE20(plan, other_side);
    func_8414ED5C(plan);
    func_841557B0();
    if (count_word > 0) {
        BattleState_PushSnapshot();
        plan = func_8414C98C(arg0);
        plan[1] = plan[1] | 4;
        func_8414C9AC(plan, count);
        BattlePlan_ApplyPursuitMultiplier(plan, side);
        *(u8 *)((u32)plan + (u32)other_side + 2) = func_841493E8();
        amount = func_841493E8();
        func_84154820(other_side, amount);
        func_84150330(plan, other_side);
        func_8414EE20(plan, side);
        func_841557B0();
    }
}
/* mkdraft:func_8414EE88 end */

extern void func_8414EE88(u8 *);
void func_8414EFD0(u8 *arg0) {
    arg0[1] = 0;
    func_8414EE88(arg0);
}

/* mkdraft:func_8414EFF0 begin */
extern void *D_841951F0;
extern void BattleEffects_PlanResidualDamage(u8 *state, u8 side);
extern void BattlePlan_ApplyPursuitMultiplier(u8 *state, u8 side);
extern void BattlePlan_UpdateMoveAccuracy(u8 *plan, u8 side);
extern void BattleState_PushSnapshot(void);
extern u8 func_84148C74(u8);
extern u8 func_841493E8(void);
extern s32 func_8414C858(u8 *arg0);
extern u8 *func_8414C98C(u8 *record);
extern void func_8414C9AC(u8 *arg0, u8 arg1);
extern void func_8414D198(u8 *arg0, u8 arg1);
extern void func_8414D51C(u8 *arg0, u8 arg1);
extern void func_8414D610(u8 *arg0, u8 arg1);
extern void func_8414EDB4(u8 *arg0);
extern void func_8414EE20(u8 *arg0, u8 arg1);
extern void func_8414FC30(u8 *arg0, u8 arg1);
extern void func_84150330(u8 *plan, u8 side);
extern void func_84153E28(u8 *arg0, u8 arg1);
extern void func_84154820(u8, u8);
extern u8 *func_84154B0C(void);
extern u8 func_84154B24(void);
extern u8 *func_84154B64(u8 arg0);
extern void func_841557B0(void);



void func_8414EFF0(u8 *arg0) {
    u8 side;
    u8 other;
    u8 *state;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;
    u8 *other_slot;
    u8 m5;

    side = func_84154B24();
    other = (1 - side) & 0xFF;
    arg0[1] = 0;
    BattleState_PushSnapshot();
    if (arg0[0] & 4) {
        state = func_8414C98C(arg0);
        if (*(u16 *)(func_84154B64(other) + 0x28) == 0) {
            m1 = func_841493E8();
            *(u8 *)((u32)state + (u32)other + 2) = m1;
            m2 = func_841493E8();
            func_84154820(other, m2);
            func_84150330(state, other);
        }
        m5 = *(u8 *)((u32)state + (u32)side + 2);
        other_slot = (u8 *)((u32)state + (u32)other);
        func_84154820(side, m5);
        func_84150330(state, side);
    } else {
        state = func_8414C98C(arg0);
        state[1] = state[1] | 3;
        *(u8 *)((u32)state + (u32)other + 6) = func_84148C74(other);
        BattlePlan_ApplyPursuitMultiplier(state, other);
        func_84154820(side, *(u8 *)((u32)state + (u32)side + 2));
        func_84150330(state, side);
        func_8414C9AC(state, 0xFF);
        func_8414FC30(state, other);
        BattlePlan_UpdateMoveAccuracy(state, other);
        func_8414D198(state, other);
        func_84153E28(state, other);
        func_8414D51C(state, other);
        BattleEffects_PlanResidualDamage(state, other);
        func_8414D610(state, other);
        other_slot = (u8 *)((u32)(state = func_8414C98C(arg0)) + (u32)other);
    }
    if (((u8 *)D_841951F0)[0x9C5] == 1) {
        ((u8 *)func_84154B0C())[0x198] = 0;
    }
    if (*(u16 *)(func_84154B64(other) + 0x28) == 0) {
        m3 = func_841493E8();
        other_slot[2] = m3;
        m4 = func_841493E8();
        func_84154820(other, m4);
        func_84150330(state, other);
    }
    state[1] = state[1] | 2;
    func_8414C9AC(state, 0xFF);
    other_slot[6] = func_84148C74(other);
    if (func_8414C858(state) != 0) {
        state[5] = side;
    } else {
        state[5] = other;
    }
    func_8414EE20(state, side);
    func_8414EE20(state, other);
    func_8414EDB4(state);
    func_841557B0();
}
/* mkdraft:func_8414EFF0 end */
#endif
