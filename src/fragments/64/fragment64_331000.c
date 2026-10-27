#include "global.h"
#include "controller.h"


#ifdef VERSION_US
void func_87F0E390(u8 *arg0, s32 arg1) {
    *(s32 *)arg0 = 0;
    *(s32 *)(arg0 + 4) = arg1;
}

u16 func_87F0E39C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 var_v1 = 0;

    switch (arg2) {
        case 0:
            var_v1 = D_800CE060[arg1].buttonsHeld;
            break;
        case 1:
            var_v1 = D_800CE060[arg1].buttonsPressed;
            break;
        case 2:
            var_v1 = D_800CE060[arg1].buttonsRepeat;
            break;
    }
    if (var_v1 != 0) {
        arg0[8] = arg1;
    }
    return var_v1;
}

s32 func_87F0E420(u8 *arg0, u8 *arg1, s32 arg2) {
    u16 result;
    s32 i;

    *(s8 *)(arg0 + 8) = -1;
    result = func_87F0E39C(arg0, 0, arg2);
    if ((*(u8 **)(arg0 + 4))[0x2182] != 0) {
        for (i = 0; i < 4; i++) {
            if ((*(u8 **)(arg0 + 4))[0x2182] & (1 << i)) {
                result |= func_87F0E39C(arg0, i, arg2);
            }
        }
    } else if ((s32)arg1 != -1) {
        if ((s32)arg1 < ++*(s32 *)arg0) {
            result = 0xFFFF;
            *(s32 *)arg0 = 0;
        }
    }
    return result;
}

extern s32 func_87F0E420(u8 *, u8 *, s32);
void func_87F0E504(u8* arg0, u8* arg1) {
    func_87F0E420(arg0, arg1, 1);
}

s32 func_87F0E524(u8 *arg0, u8 *arg1, s32 arg2) {
    u16 result;
    s32 i;

    *(s8 *)(arg0 + 8) = -1;
    result = func_87F0E39C(arg0, 0, arg2);
    if ((*(u8 **)(arg0 + 4))[0x2182] != 0) {
        for (i = 0; i < 4; i++) {
            if ((*(u8 **)(arg0 + 4))[0x2182] & (1 << i)) {
                result |= func_87F0E39C(arg0, i, arg2);
                break;
            }
        }
    } else if ((s32)arg1 != -1) {
        if ((s32)arg1 < ++*(s32 *)arg0) {
            result = 0xFFFF;
            *(s32 *)arg0 = 0;
        }
    }
    return result;
}

s32 WidgetTree_RunMessagePanelSilent_fragment64(u8 *arg0, u8 *arg1) { extern s32 func_87F0E524(u8 *, u8 *, s32); return func_87F0E524(arg0, arg1, 0); }

s32 func_87F0E610(u8 *arg0, u8 *arg1) { extern s32 func_87F0E524(u8 *, u8 *, s32); return func_87F0E524(arg0, arg1, 1); }

s32 func_87F0E630(u8 *arg0, u8 *arg1) { extern s32 func_87F0E524(u8 *, u8 *, s32); return func_87F0E524(arg0, arg1, 2); }

s8 func_87F0E650(u8 *arg0) { return *(s8 *)(arg0 + 8); }
#endif
