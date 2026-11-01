#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_87F01DA0 begin */
extern u8 *D_87F11980;

typedef union {
    struct {
        u8 r, g, b, a;
    };
    u32 rgba;
} Rgba;

void func_87F00944(void *arg0, Rgba c1, Rgba c2, s32 arg3);


s32 func_87F01DA0(s32 arg0, void *arg1) {
    s32 flag;
    Rgba c1;
    Rgba c2;
    // FAKE: unused locals that widen the frame to 0x30 so c1, c2 and the callee's
    // color home slots land at 0x24/0x28; without them the object differs in its
    // stack offsets (score 90).
    Rgba t1;
    Rgba t2;

    flag = 0;
    switch (arg0) {
    case 0:
        (*(u16 *)((u8 *)arg1 + 2)) &= 0xFFFD;
        break;
    case 1:
        switch (*(u32 *)((u8 *)arg1 + 0x20)) {
        case 0:
            if (*(s32 *)(D_87F11980 + 0xC) == 1) {
                flag = 1;
            }
            break;
        case 1:
            if (*(s32 *)(D_87F11980 + 0xC) == 2) {
                flag = 1;
            }
            break;
        case 2:
            if (*(s32 *)(D_87F11980 + 0xC) == 3) {
                flag = 1;
            }
            break;
        }
        c1.rgba = 0xFFFFEBAA;
        c2.rgba = 0xAA5A00FF;
        func_87F00944(arg1, c1, c2, flag);
        break;
    }
    return 1;
}
/* mkdraft:func_87F01DA0 end */

extern u8 *D_87F11980;
void func_87F01E8C(s32 arg0, u8 *arg1) {
    s32 flag;
    u32 mode;

    switch (arg0) {
        case 0:
            *(u16 *)(arg1 + 2) &= 0xFFFD;
            break;
        case 1:
            mode = *(u32 *)(arg1 + 0x20);
            switch (mode) {
                case 0:
                    flag = 1;
                    break;
                case 1:
                    flag = 2;
                    break;
                case 2:
                    flag = 3;
                    break;
            }
            if (flag == *(u32 *)(D_87F11980 + 0xC)) {
                *(u16 *)(arg1 + 2) |= 2;
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
            }
            break;
    }
}

/* mkdraft:func_87F01F34 begin */
extern u8 *D_87F11980;
extern u8 D_87F11988;
extern s32 func_87F01DA0(s32, void *);
extern void func_87F01E8C(s32, u8 *);
extern void func_87F0E390(u8 *, s32);
extern s32 func_8004DC6C(s32);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern s32 func_8004EB58(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern void func_8004DCFC(u8 *, s32 *);
extern void func_87F0AB08(s32, s32, void (*)(s32, u8 *), s32);
extern void func_87F0AA80(s32, s32, void *);
extern u8 D_87F1121C;
extern u8 D_87F11234;
extern u8 D_87F11298;



void func_87F01F34(s32 arg0) {
    s32 state;
    s32 pad[7]; // FAKE: fills the frame to 0x58 and puts state at 0x54; scores 98 without it.
    void (*callback)(s32, u8 *); // FAKE: unreferenced; its home at 0x24 sets the frame to 0x58 and the saved-callback slot to 0x24; scores 50 without it.
    s32 temp_v0;
    s32 temp_v0_2;

    D_87F11980 = &D_87F11988;
    *(s32 *)(D_87F11980 + 0xC) = 1;
    *(s32 *)(D_87F11980 + 0x10) |= 0x10000000;
    D_87F11980[0x28] = 0;
    func_87F0E390(D_87F11980 + 0x14, arg0);
    temp_v0 = func_8004DC6C(0x75);
    *(s32 *)D_87F11980 = temp_v0;
    if (temp_v0 != 0) {
        temp_v0_2 = MainPool_AllocState(main_pool_get_available(), 0);
        state = temp_v0_2;
        *(s32 *)(D_87F11980 + 4) = func_8004EB58(temp_v0_2, *(s32 *)D_87F11980);
        MainPool_FinalizeAllocation(state);
        func_8004DCFC(*(u8 **)D_87F11980, (s32 *)(D_87F11980 + 8));
        func_87F0AB08(*(s32 *)(D_87F11980 + 4), 0x504E4331, func_87F01DA0, 0);
        func_87F0AB08(*(s32 *)(D_87F11980 + 4), 0x504E4332, func_87F01DA0, 1);
        func_87F0AB08(*(s32 *)(D_87F11980 + 4), 0x504E4333, func_87F01DA0, 2);
        func_87F0AB08(*(s32 *)(D_87F11980 + 4), 0x504B4D33, func_87F01E8C, 0);
        func_87F0AB08(*(s32 *)(D_87F11980 + 4), 0x504B4D34, func_87F01E8C, 1);
        func_87F0AB08(*(s32 *)(D_87F11980 + 4), 0x504B4D32, func_87F01E8C, 2);
        func_87F0AA80(*(s32 *)(D_87F11980 + 4), 0x504B4D33, &D_87F1121C);
        func_87F0AA80(*(s32 *)(D_87F11980 + 4), 0x504B4D34, &D_87F11298);
        func_87F0AA80(*(s32 *)(D_87F11980 + 4), 0x504B4D32, &D_87F11234);
    }
}
/* mkdraft:func_87F01F34 end */

/* mkdraft:func_87F02104 begin */
extern s32 func_80001FF0(void);
extern s32 func_87F0E610(u8 *, u8 *);
extern void func_80006148(void *);
extern void func_800279C4(s32);
extern u8 *D_87F11980;
extern u8 D_800CE060[];
extern u16 D_800CE070;
extern u8 D_800CE088[];

// NON_MATCHING: Pointer liveness, independent instruction order, and address-load placement differ.
#ifdef NON_MATCHING
s32 func_87F02104(void) {
    s32 result;
    u8 *p;
    u8 *o;
    u16 buttons;
    s32 i;

    result = 0;
    buttons = func_87F0E610((*(u8 **)((u32)&D_87F11980)) + 0x14, (u8 *)(func_80001FF0() * 2));

    if (*(u32 *)((*(u8 **)((u32)&D_87F11980)) + 0x10) & 0x10000000) {
        *(u32 *)((*(u8 **)((u32)&D_87F11980)) + 0x10) &= 0xEFFFFFFF;
        p = D_800CE060;
        for (i = 0; i != 8; i += 2) {
            *(u16 *)((*(u8 **)((u32)&D_87F11980)) + i + 0x20) = *(u16 *)(p + 0x10);
            func_80006148(p);
            p += 0x28;
        }
        if (*(u8 *)(*(u8 **)((*(u8 **)((u32)&D_87F11980)) + 0x18) + 0x2182) != 0) {
            *(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC) = 1;
        } else {
            *(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC) = 2;
        }
        (*(u8 **)((u32)&D_87F11980))[0x28] = 0;
    }

    if (buttons & 0x8000) {
        s32 mode = *(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC);
        result = mode;
        if (mode == 1) {
            *(u32 *)((*(u8 **)((u32)&D_87F11980)) + 0x10) |= 0x10000000;
        }
        D_800CE070 = *(u16 *)((*(u8 **)((u32)&D_87F11980)) + 0x20);
        p = (u8 *)((u32)D_800CE088 + 0x50);
        *(u16 *)(p - 0x40) = *(u16 *)((*(u8 **)((u32)&D_87F11980)) + 0x22);
        *(u16 *)(p - 0x18) = *(u16 *)((*(u8 **)((u32)&D_87F11980)) + 0x24);
        *(u16 *)(p + 0x10) = *(u16 *)((*(u8 **)((u32)&D_87F11980)) + 0x26);
        func_800279C4(0xCF02);
    } else {
        *(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC) = *(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC)
            + ((buttons & 0x400) > 0) - ((buttons & 0x800) > 0);
        if (*(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC) <= 0) {
            *(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC) = 3;
        }
        if (*(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC) >= 4) {
            *(s32 *)((*(u8 **)((u32)&D_87F11980)) + 0xC) = 1;
        }
        if (buttons & 0xC00) {
            func_800279C4(0xCF01);
        }
    }

    if (result == 8) {}
    if (*(u8 *)((*(u8 **)((u32)&D_87F11980)) + 0x28) < 0xA0) {
        *(u8 *)((*(u8 **)((u32)&D_87F11980)) + 0x28) = *(u8 *)((*(u8 **)((u32)&D_87F11980)) + 0x28) + 0x14;
    } else {
        *(u8 *)((*(u8 **)((u32)&D_87F11980)) + 0x28) = 0xB4;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_324A10/func_87F02104.s")
#endif
/* mkdraft:func_87F02104 end */

extern u8 *D_87F11980; extern void func_87F08FA0(u8); extern void func_800503A4(void *); void func_87F022F0(void) { func_87F08FA0(D_87F11980[0x28]); func_800503A4(*(void **)(D_87F11980 + 4)); }

extern u8 *D_87F11980; void func_87F02328(void) { D_87F11980[0x28] = 0; }
#pragma C_FUNCTION_PADDING(8)
#endif
