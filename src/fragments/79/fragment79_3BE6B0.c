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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3BE6B0/func_8414EFF0.s")
#endif
