#include "global.h"


#ifdef VERSION_US
typedef struct {
    u8 flags;
    u8 unk_01[7];
    u8 selected[2];
    u8 unk_0A[42];
    u32 score[2];
} BattlePlanScoreHeader;

typedef struct {
    u8 unk_00[13];
    u8 stages[7];
} BattlePlanStageRecord;

extern u8 *func_84154B64(u8);
extern u8 *func_84154B30(u8);
extern void *func_84156590(u8);
extern s32 func_84156618(u8, u8, s32);
extern u8 func_84149424(void);
extern u8 func_80062D20(u8);
extern u8 func_84154B18(void);
void func_8414FC30(u8 *plan, u8 side) {
    u8 *slot;
    u8 *own;
    u8 *other;
    u8 move;
    u8 a1;
    u8 a3;
    u8 x;

    own = func_84154B64(side);
    other = func_84154B64(1 - side);
    a3 += 0; // FAKE: starts a3's live range at entry (fixes spill slot order)
    slot = plan;
    slot += side;
    slot += 4;
    move = slot[2];
    if (*(u16 *)(own + 0x28) == 0) {
        slot[4] = 1;
        return;
    }
    if (*(u16 *)(other + 0x28) == 0) {
        return;
    }
    if (own[0x18] & 0x20) {
        return;
    }
    if (own[0x17] & 8) {
        return;
    }
    slot[4] = 0xFF;
    a1 = *(u16 *)(own + 0x26);
    if (a1 & 0x20) {
        if (move != 0xAC && move != 0xDD) {
            slot[4] = 0x19;
        }
    } else if (*(u16 *)(own + 0x26) & 7) {
        a1 = func_84154B30(side)[1];
        a3 = ((u8 *)func_84156590(side))[0xD];
        if (func_84156618(side, a1, 0x20) != 0) {
            if (a3 < 2 && move != 0xD6 && move != 0xAD) {
                slot[4] = 1;
            } else {
                slot[4] = 0xFF;
            }
        } else {
            if (a3 <= 0) {
                x = 1;
            } else if (a3 < 3) {
                x = ((func_84149424() & 3) + 1) * (a3 + 1) << 4;
            } else {
                x = 0xFF;
            }
            if (move != 0xD6 && move != 0xAD) {
                slot[4] = x;
            } else {
                slot[4] = 0xFF - x;
            }
        }
    }
    if (own[0x17] & 0x80) {
        slot[4] = slot[4] * 0.7;
    }
    if (own[0x15] & 0x80) {
        slot[4] = slot[4] * 0.7;
    }
    if (*(u16 *)(own + 0x26) & 0x40) {
        slot[4] = slot[4] * 0.8;
    }
    switch (func_80062D20(move)) {
        case 0x27:
        case 0x4B:
        case 0x91:
        case 0x9B:
            if (slot[4] < 0xFF) {
                slot[4] = slot[4] * 0.7;
            }
            break;
        case 0x97:
            if (slot[4] < 0xFF) {
                if (func_84154B18() != 2) {
                    slot[4] = slot[4] * 0.7;
                }
            }
            break;
    }
}

extern void func_8414A180(u8 *, u8, u8);
extern void func_8414A144(u8 *);
extern u8 * func_84154B64(u8);
void BattlePlan_UpdateMoveAccuracy(u8 *plan, u8 side) {
    u8 move;
    u8 *entry;
    u8 context[12];
    entry = (u8 *)((u32)plan + (u32)side);
    move = entry[6];
    func_84154B64(side);
    if (move != 0) {
        func_8414A180(context, side, move);
        func_8414A144(context);
        entry[10] = context[2];
    }
}

extern void func_8414D198(void *, u8);
void BattlePlan_ApplyPursuitMultiplier(u8 *state, u8 side) {
    u8 *entry;
    if (*(u8 *)((u32)state + (u32)side + 6) == 228) {
        func_8414D198(state, side);
        entry = (u8 *)((u32)state + ((u32)side << 1));
        entry += 4;
        *(u16 *)(entry + 10) *= 2;
    }
}

extern u16 func_84148520(u16, u16, u8);
extern u8 * func_84154B30(u8);
extern s32 func_84155544(u8 *, u8);
void func_84150330(void *plan, u8 side) {
    s32 base;
    u8 *mon;
    s16 amount;

    mon = func_84154B30(side);
    if ((mon[3] & 1) == 0) return;
    if (func_84155544(mon + 8, 2) != 0) return;
    base = (s32)(u32)plan + 4;
    amount = func_84148520(*(u16 *)(mon + 0x30), *(u16 *)(mon + 0x32), 3);
    ((u16 *)(u32)base)[(u32)side + 0x11] += amount;
}
#endif
