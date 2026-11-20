#include "global.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_80087200;
extern s32 D_880068B8;

void func_882219B0(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void Util_Free(void *);
extern s32 D_880068B4;
extern s16 D_8823474A;
extern void *D_88234830;
void func_882219D8(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B4 = (*(s32 *)((u8 *)(D_88234830) + (0x130)));
    if ((*(s8 *)((u8 *)(D_88234830) + (0x12D))) == 1) {
        D_8823474A = (*(s16 *)((u8 *)(D_88234830) + (0x2C)));
    }
    Util_Free(D_88234830);
}

extern void func_88004990(u8, u8);
void func_88221A34(s32 (*arg0)()) {
    func_88004990(*(*(u8 **)((u8 *)(D_88234830) + (0))), 0);
    D_880068B8 = 1;
    (*(s32 *)((u8 *)(D_88234830) + (0x130))) = 0;
    arg0();
}

extern void func_8821C2F4(void);
extern void func_8821B714(s32, s32);
extern void func_8800225C(void *, s16, s16);
extern u8 D_88006880[];

void func_88221A8C(s32 arg0, s32 arg1) {
    func_8821C2F4();
    func_8821B714(arg0, arg1);
    func_8800225C(D_88006880, 0, 0);
    func_88004990(**(u8 **)D_88234830, 0);
    D_880068B8 = 1;
}

extern void func_8821B438(void);
extern void func_8821B758(u8);
extern void func_8821B980(u16, s32);
extern void func_8821C0B0(void);
extern s32 D_88234768;

void func_88221AF0(void) {
    func_8821C2F4();
    if ((*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 1) && (*(s16 *)((u8 *)(D_88234830) + (0x2C)) == 7)) {
        func_8821B438();
    } else if ((*(s8 *)((u8 *)(D_88234830) + (0x12C)) == 0) && (*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 3)) {
        func_8821B758(*(u8 *)((u8 *)(D_88234830) + (0x2D)));
        func_8821B980(0x40, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
    } else if ((*(s8 *)((u8 *)(D_88234830) + (0x12C)) == 3) && (*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 5)) {
        func_8821B980(0x400, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
    } else if ((*(s8 *)((u8 *)(D_88234830) + (0x12C)) == 3) && (*(s8 *)((u8 *)(D_88234830) + (0x12D)) == 6)) {
        if (*(s16 *)((u8 *)(D_88234830) + (0x2C)) == 0) {
            func_8821B980(0x80, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
        } else {
            D_88234768 = *(s16 *)((u8 *)(D_88234830) + (0x2C));
            func_8821B980(0x100, ((s32 *)((u8 *)(D_88234830) + (0x120)))[*(s16 *)((u8 *)(D_88234830) + (0x2C))]);
        }
    }
    func_8821C0B0();
    func_8800225C(D_88006880, 0, 0);
    func_88004990(**(u8 **)D_88234830, 0);
    D_880068B8 = 1;
}

extern void func_800226C0(s32);
extern void func_882206A0(s32);
extern s32 func_88229CB0();
extern s32 func_8822A534();
extern s32 func_88227224();
extern s32 func_88223120();
extern void func_88002720(void *, u16, void *);
extern void func_88004990(u8, u8);
extern void func_88221A34(s32 (*arg0)());
extern void func_88221A8C(s32 arg0, s32 arg1);
extern void func_88221AF0(void);
extern s32 D_80087200;
extern s32 D_880068B8;
extern void * D_88234830;
void func_88221C54(void) {
    if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
        func_800226C0(0x5C);
        if (*(s8 *)(((u8 *)D_88234830) + 0x12D) == 1) {
            switch (*(u16 *)(((u8 *)D_88234830) + 0x2C)) {
            case 0:
                func_88221A8C(12, 1);
                break;
            case 1:
                func_88221A8C(8, 1);
                break;
            case 2:
                func_88221A8C(9, 1);
                break;
            case 3:
                func_88221A34(func_88229CB0);
                break;
            case 4:
                func_88221A34(func_8822A534);
                break;
            case 5:
                func_88004990(**(u8 **)D_88234830, 0);
                D_880068B8 = 1;
                *(s32 *)(((u8 *)D_88234830) + 0x130) = 0;
                func_882206A0(0);
                break;
            case 6:
                func_88221A34(func_88227224);
                break;
            case 7:
                func_88221AF0();
                break;
            }
        } else {
            switch (*(s8 *)(((u8 *)D_88234830) + 0x12C)) {
            case 0:
                switch (*(s8 *)(((u8 *)D_88234830) + 0x12D)) {
                case 2:
                    func_88221A8C(14, 1);
                    break;
                case 3:
                    func_88221AF0();
                    break;
                case 4:
                    func_88221A8C(10, 1);
                    break;
                }
                break;
            case 1:
                if (*(s8 *)(((u8 *)D_88234830) + 0x12D) == 2 && *(s16 *)(((u8 *)D_88234830) + 0x2C) == 2) {
                    func_88221A34(func_88223120);
                } else {
                    func_88221A8C(*(s8 *)(((u8 *)D_88234830) + 0x12D) - 1, *(s16 *)(((u8 *)D_88234830) + 0x2C));
                }
                break;
            case 3:
                switch (*(s8 *)(((u8 *)D_88234830) + 0x12D)) {
                case 2:
                    func_88221A8C(11, 1);
                    break;
                case 3:
                    func_88221A8C(15, 1);
                    break;
                case 4:
                    func_88221A8C(13, *(s16 *)(((u8 *)D_88234830) + 0x2C));
                    break;
                case 5:
                    if (*(s16 *)(((u8 *)D_88234830) + 0x2C) == 0) {
                        func_88221A8C(16, 1);
                    } else {
                        func_88221AF0();
                    }
                    break;
                case 6:
                    func_88221AF0();
                    break;
                }
                break;
            }
        }
    } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
        func_800226C0(0x48);
        func_88004990(**(u8 **)D_88234830, 0);
        D_880068B8 = 1;
    } else {
        func_88002720(((u8 *)D_88234830) + 0x2C, *(u16 *)(((u8 *)D_88234830) + 0x10), ((u8 *)D_88234830) + 0x30);
    }
}

extern void func_889033FC(void *, void *);
void func_88221F28(void) {
    func_889033FC(*(void **)D_88234830, (u8 *)D_88234830 + 4);
}

typedef struct {
    s32 unk0;
    u8 *unk4;
} F31Flags;
typedef struct {
    void *unk0;
    u8 menu[0x34];
    void *items[8];
    u8 flags[8];
    u8 bufs[3][0x40];
    s32 enabled[3];
    s8 mode;
    s8 sub;
    u8 pad12E[2];
    s32 unk130;
} F31Menu;
#define M31 ((F31Menu *)D_88234830)
extern F31Flags D_88006020;
extern u8 D_882338BE[][7];
extern s32 D_882347C0;
extern u16 D_88234744;
extern u8 D_8800ED50[];
extern void func_882254B8(void);
extern void func_882241B8(void);
extern void *Util_Malloc(s32);
extern void *func_8004C874(s32, s32);
extern s32 func_8004C54C(s32, s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern s32 func_8821B884(u8);
extern s32 func_8821B8C8(void);
extern s32 func_8821B8EC(u8);
extern s32 func_8821B95C(void);
extern s32 func_8821B468(void);
extern void _bzero(void *, s32);
extern u8 *func_88002AA8(u8 *, s32, u8 **, u16, s32, s16, s16, s16, s16, s16, s16, s32, s16, void *);
extern s32 func_88216D98(s8, s8);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, void *, void *, void *, void *, s32, s32);
extern void func_88221C54(void);
extern void func_88221F28(void);
void func_88221F54(s8 arg0, s8 arg1) {
    u32 i;
    u8 count;
    s32 style;
    F31Flags flags;
    s16 cursor;
    s32 idx;

    if (arg0 == 2 && arg1 == 2) {
        func_882254B8();
        return;
    }
    if (arg0 == 0 && arg1 == 5) {
        func_882241B8();
        return;
    }
    flags = D_88006020;
    cursor = 0;
    D_88234830 = Util_Malloc(0x134);
    M31->mode = arg0;
    M31->sub = arg1;
    if (arg1 == 1) {
        count = 8;
        cursor = D_8823474A;
    } else if (arg0 == 3 && arg1 == 6 && D_882347C0 == 0) {
        count = 1;
    } else {
        count = D_882338BE[M31->mode][M31->sub];
    }
    if (count <= 0) {
        return;
    }
    if (arg1 == 1) {
        for (i = 0; i < count - 1; i++) {
            M31->items[i] = func_8004C874(0x25, i + 0xC);
        }
        M31->items[count - 1] = func_8004C874(0x25, 0);
    } else {
        switch (M31->mode) {
        case 0:
            switch (M31->sub) {
            case 2:
                M31->items[0] = func_8004C874(0x25, 0x17);
                break;
            case 3:
                for (i = 0; i < count; i++) {
                    M31->enabled[i] = 1 - func_8821B884(i);
                    style = (M31->enabled[i] == 0) ? 0x1A : 0x19;
                    func_8004C54C(0x19, (s32)func_8004C874(0x25, i + 0x3F));
                    M31->items[i] = func_8004C8A0(M31->bufs[i], 0x40, 0x25, style);
                }
                break;
            case 4:
                M31->items[0] = func_8004C874(0x25, 0x18);
                break;
            }
            break;
        case 1:
            for (i = 0; i < count; i++) {
                M31->items[i] = func_8004C874(0x25, i + 0x14);
            }
            break;
        case 3:
            switch (M31->sub) {
            case 2:
                M31->items[0] = func_8004C874(0x25, 0x13);
                break;
            case 3:
                M31->items[0] = func_8004C874(0x25, 0x17);
                break;
            case 4:
                for (i = 0; i < count; i++) {
                    M31->items[i] = func_8004C874(0x25, i + 0x14);
                }
                break;
            case 5:
                M31->items[0] = func_8004C874(0x25, 0x17);
                M31->enabled[1] = 1 - func_8821B95C();
                style = (M31->enabled[1] == 0) ? 0x1A : 0x19;
                func_8004C54C(0x19, (s32)func_8004C874(0x25, 0x24));
                M31->items[1] = func_8004C8A0(M31->bufs[1], 0x40, 0x25, style);
                break;
            case 6:
                for (i = 0; i < count; i++) {
                    if (i == 0) {
                        M31->enabled[i] = 1 - func_8821B8C8();
                    } else {
                        M31->enabled[i] = 1 - func_8821B8EC(i);
                    }
                    style = (M31->enabled[i] == 0) ? 0x1A : 0x19;
                    func_8004C54C(0x19, (s32)func_8004C874(0x25, i + 0x25));
                    M31->items[i] = func_8004C8A0(M31->bufs[i], 0x40, 0x25, style);
                }
                break;
            }
            break;
        }
    }
    flags.unk4 = M31->flags;
    _bzero(flags.unk4, 8);
    if (arg1 == 1) {
        if (D_88234744 == 0 || func_8821B468() != 0) {
            flags.unk0 = 1;
            if (D_88234744 == 0) {
                flags.unk4[5] = 1;
            }
            if (func_8821B468() != 0) {
                flags.unk4[count - 1] = 1;
            }
        }
    } else if (M31->mode == 3 && M31->sub == 6 && count != 1 && (M31->enabled[1] == 0 || M31->enabled[2] == 0)) {
        flags.unk0 = 1;
        if (M31->enabled[1] == 0) {
            flags.unk4[2] = 1;
        } else if (M31->enabled[2] == 0) {
            flags.unk4[1] = 1;
        }
    }
    func_88002AA8(M31->menu, 0, (u8 **)M31->items, count, 8, 1, 6, 15, 16, 13, 16, 1, cursor, &flags);
    idx = func_88004804(M31->menu, 0, func_88216D98(arg0, arg1), 0x93, 0, 1, 0xDC, 0xDC, 0xB4, func_88221C54,
                        func_88221F28, func_882219B0, func_882219D8, 0, 0);
    M31->unk0 = D_8800ED50 + idx * 0x4C;
    D_880068B4 = 0;
    M31->unk130 = 1;
}

#endif
