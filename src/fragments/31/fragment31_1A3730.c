#include "global.h"


#ifdef VERSION_US
typedef struct {
    s32 enabled;
    u8 *flags;
} F31TextMask;
extern F31TextMask D_88006020;
extern void *func_8004C874(s32, s32);
extern s32 func_882025B4(s32, u8);
extern void _bzero(void *, s32);
extern void LabPC_OpenMessageDialog(s8 *title, s16 x, s16 y, s32 style, u8 red, u8 green, u8 blue, u8 delay,
                                    u8 kind, s32 *done, s32 *cancel, s32 *extra, void (*callback)(void));
extern s32 D_880068B4;
extern s32 D_880068B8;
extern s32 func_88903B00[];
extern void D_88000E4C(void);
extern u8 *func_88002AA8(u8 *, s32, u8 **, u16, s32, s16, s16, s16, s16, s16, s16, s32, s16, void *);
extern s32 func_800635E0(u8);
extern s32 func_8004C54C(s32, s32);
extern s32 func_80063754(u8);
extern void *func_8004C8A0(void *, s32, s32, s32);
s32 func_882304B0(u8 *node, u8 index) {
    u32 i;
    s16 selection;
    s32 ok;
    F31TextMask mask = D_88006020;

    selection = 0;
    node[0xDF] = index;
    *(s32 *)(node + 0xE0) = 0;
    mask.flags = node + 0x5C;
    _bzero(mask.flags, 3);
    for (i = 0; i < 3; i++) {
        *(void **)(node + 0x50 + i * 4) = func_8004C874(0x23, i + 0x12);
        ok = func_882025B4(i + 2, index);
        if (ok != 0) {
            mask.enabled = 1;
            mask.flags[i] = 1;
            if (selection == i) {
                selection++;
            }
        }
    }
    if (selection == 3) {
        LabPC_OpenMessageDialog(func_8004C874(0x23, 0x10), 320, 240, 4, 255, 170, 140, 2, 0, &D_880068B4,
                                &D_880068B8, func_88903B00, D_88000E4C);
        return 0;
    }
    func_88002AA8(node + 0x1C, 0, (u8 **)(node + 0x50), 3, 8, 1, 6, 0, 0, 0, 0, 0, selection, &mask);
    func_8004C54C(0x19, func_800635E0(index));
    *(void **)(node + 8) = func_8004C8A0(node + 0x5F, 0x80, 0x23, func_80063754(index) ? 0x15 : 0x16);
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 0xC) = 4;
    *(s16 *)(node + 0x10) = 1;
    *(s16 *)(node + 0x12) = 4;
    return 1;
}
#endif
