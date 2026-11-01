#include "global.h"


#ifdef VERSION_US
/* Preserve the original named zero word in this file's readonly data. */
const u32 D_813124D0[1] = {0};

s32 func_813055E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 result = (((arg3 + arg1) * 2) + arg2) - 1;
    return result >= 0 ? result : 0;
}

s32 func_8130560C(void *arg0, s32 arg1) {
    u8 *base = (u8 *)arg0;
    if (arg1 >= *(u16 *)(base + 0x50)) {
        return -1;
    }
    return *(u8 *)(base + arg1 + 0x10);
}

s32 func_81305634(void *arg0) {
    s32 temp_a1;

    temp_a1 = func_813055E0((s32) arg0, (s32) (*(s16 *)((u8 *)(arg0) + (0x7C))), (s32) (*(s16 *)((u8 *)(arg0) + (8))), (s32) (*(s16 *)((u8 *)(arg0) + (0xA))));
    if (((*(s16 *)((u8 *)(arg0) + (0x7C))) == 0) && ((*(s16 *)((u8 *)(arg0) + (8))) == 1) && ((*(s16 *)((u8 *)(arg0) + (0xA))) == 0)) {
        return -1;
    }
    return func_8130560C(arg0, temp_a1);
}

f32 func_813056A0(void *arg0) {
    if (*((u8 *)arg0 + 0x87) == 0) {
        return 0.0f;
    }
    if (*(s32 *)arg0 != 0) {
        return 1.0f;
    }
    switch (*((u8 *)arg0 + 0x87)) {
        case 1:
        case 2:
        case 3:
            return 1.0f;
        case 4:
        case 5:
            return 1.0f;
    }
    //!bug: no return for other values; the caller gets whatever is in $f0
}

f32 func_8130571C(void *arg0) { u8 *base = (u8 *)arg0; f32 result = 1.0f; if (base[0x87] == 3) { result = (f32)base[0x82] / (f32)base[0x86]; } return result; }

extern f32 func_813056A0(void *);
extern f32 (*D_8160BD18)(f32);
extern f32 (*D_8160BD1C)(f32);
struct Fragment14GridRectangle {
    s16 x, y, width, height;
};
struct Fragment14GridOrigin {
    u32 header;
    s16 x, y;
};

f32 Fragment14_ComputeGridRectangles(void *arg0, void *arg1, void *arg2, void *arg3) {
    f32 progress;
    f32 width;
    f32 height;

    progress = func_813056A0(arg0);
    width = D_8160BD18(progress);
    height = D_8160BD1C(progress);
    ((struct Fragment14GridRectangle *)arg1)->width = (s16)(148.0f * width);
    ((struct Fragment14GridRectangle *)arg1)->height = (s16)(41.0f * height);
    ((struct Fragment14GridRectangle *)arg1)->x = (s16)(((struct Fragment14GridOrigin *)arg0)->x + (148 - ((struct Fragment14GridRectangle *)arg1)->width) / 2);
    ((struct Fragment14GridRectangle *)arg1)->y = (s16)(((struct Fragment14GridOrigin *)arg0)->y + (41 - ((struct Fragment14GridRectangle *)arg1)->height) / 2);
    ((struct Fragment14GridRectangle *)arg2)->width = (s16)(440.0f * width);
    ((struct Fragment14GridRectangle *)arg2)->height = (s16)(143.0f * height);
    ((struct Fragment14GridRectangle *)arg2)->x = (s16)((f32)((struct Fragment14GridOrigin *)arg0)->x + (440 - ((struct Fragment14GridRectangle *)arg2)->width) / 2);
    ((struct Fragment14GridRectangle *)arg2)->y = (s16)((f32)((struct Fragment14GridOrigin *)arg0)->y + 30.0f + (143 - ((struct Fragment14GridRectangle *)arg2)->height) / 2);
    ((struct Fragment14GridRectangle *)arg3)->width = (s16)(302.0f * width);
    ((struct Fragment14GridRectangle *)arg3)->height = (s16)(67.0f * height);
    ((struct Fragment14GridRectangle *)arg3)->x = (s16)((f32)((struct Fragment14GridOrigin *)arg0)->x + (302 - ((struct Fragment14GridRectangle *)arg3)->width) / 2);
    ((struct Fragment14GridRectangle *)arg3)->y = (s16)((f32)((struct Fragment14GridOrigin *)arg0)->y + 162.0f + (67 - ((struct Fragment14GridRectangle *)arg3)->height) / 2);
    return progress;
}

extern void func_816048E0(s32, s32, s32, s32, f32);
extern void func_816073A0(void *);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern s32 func_8004C874(s32, s32);
extern void func_800495BC(s32, s32, s32);
extern void func_800499EC(void);
extern void func_81607408(void);
void func_81305A10(void *arg0, void *arg1, f32 arg2) {
    s16 temp_a3;
    s32 color;

    temp_a3 = *(s16 *)((u8 *)arg1 + 6);
    if (temp_a3 >= 0x10) {
        func_816048E0(
            *(s16 *)((u8 *)arg1 + 0),
            *(s16 *)((u8 *)arg1 + 2),
            *(s16 *)((u8 *)arg1 + 4),
            temp_a3,
            arg2);
        if (!(0.1f < arg2)) {
            func_816073A0(arg1);
            func_800498C4();
            func_800496A4(4, 1);
            color = func_8004C874(0xF, 0);
            func_800495BC(
                *(s16 *)((u8 *)arg1 + 0) + 0xC,
                *(s16 *)((u8 *)arg1 + 2) + 0xC,
                color);
            func_800499EC();
            func_81607408();
        }
    }
}

void Fragment14_ComputeGridCursorPosition(u8 *arg0, s16 *arg1) {
    f32 ratio;
    f32 x;
    f32 y;

    ratio = (f32)arg0[0x83] / (f32)arg0[0x85];
    x = (f32)*(s16 *)(arg0 + 0xC) + ((f32)*(s16 *)(arg0 + 8) - (f32)*(s16 *)(arg0 + 0xC)) * ratio;
    y = (f32)*(s16 *)(arg0 + 0xE) + ((f32)*(s16 *)(arg0 + 0xA) - (f32)*(s16 *)(arg0 + 0xE)) * ratio;
    arg1[0] = (s16)(172.0f * x + 38.0f);
    arg1[1] = (s16)(28.0f * y + 18.0f);
}

/* mkdraft:func_81305BA8 begin */
extern f32 func_80071CA0(f32 value, f32 *whole);



void func_81305BA8(void *arg0, s32 *arg1, s32 *arg2) {
    s32 offset;
    f32 whole;

    offset = (s32) (-func_80071CA0(
        (f32)(u32)(*(u8 *)((u8 *)arg0 + 0x8A)) +
            (((f32)(*(s16 *)((u8 *)arg0 + 0x7C)) - (f32)(u32)(*(u8 *)((u8 *)arg0 + 0x8A))) *
             func_8130571C(arg0)),
        &whole) * 28.0f);
    *arg1 = (s32) whole;
    *arg2 = offset;
}
/* mkdraft:func_81305BA8 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FD770/func_81305C54.s")

extern s32 func_81305634(void *);
extern Gfx *D_800D0510;
extern void func_8004989C(s32);
extern s32 func_816020BC(u8);
void func_81305FB4(void *arg0, void *arg1, f32 arg2) {
    s32 result;

    result = func_81305634(arg0);
    if (*(s16 *)((u8 *)arg1 + 6) >= 0x10) {
        gDPPipeSync(D_800D0510++);
        func_816048E0(
            *(s16 *)((u8 *)arg1 + 0),
            *(s16 *)((u8 *)arg1 + 2),
            *(s16 *)((u8 *)arg1 + 4),
            *(s16 *)((u8 *)arg1 + 6),
            arg2);
        if (!(0.1f < arg2) && (result > 0)) {
            gDPPipeSync(D_800D0510++);
            func_816073A0(arg1);
            func_800498C4();
            func_800496A4(4, 1);
            func_8004989C(0x14);
            func_800495BC(
                *(s16 *)((u8 *)arg1 + 0) + 0xE,
                *(s16 *)((u8 *)arg1 + 2) + 0xE,
                func_816020BC((u8)result));
            func_800499EC();
            func_81607408();
        }
    }
}

extern f32 Fragment14_ComputeGridRectangles(void *, void *, void *, void *);
extern void func_81305A10(void *, void *, f32);
extern void func_81305C54(void *, void *, f32);
extern void func_81305FB4(void *, void *, f32);
extern s32 func_81600DA8(void *, void *);
void func_813060C8(void *arg0, void *arg1) {
    u8 sp38[8];
    u8 sp30[8];
    u8 sp28[8];
    f32 sp24;

    if (*(u8 *)((u8 *)arg0 + 0x87) != 0) {
        sp24 = 1.0f - Fragment14_ComputeGridRectangles(arg0, sp38, sp30, sp28);
        if (func_81600DA8(arg1, (u8 *)arg0 + 1) != 0) {
            func_81305A10(arg0, sp38, sp24);
        }
        if (func_81600DA8(arg1, (u8 *)arg0 + 2) != 0) {
            func_81305C54(arg0, sp30, sp24);
        }
        if (func_81600DA8(arg1, (u8 *)arg0 + 3) != 0) {
            func_81305FB4(arg0, sp28, sp24);
        }
    }
}

extern s32 func_81601980(s32 *, s32);
extern void func_800226C0(s32);
void Fragment14_ConfirmGridSelection(u8 *arg0) {
    s32 selected = func_81305634(arg0);

    if (selected < 0 || func_81601980((s32 *)(arg0 + 0x54), selected) != 0) {
        func_800226C0(5);
    } else {
        arg0[0x87] = 5;
        *(s16 *)(arg0 + 0x7E) = selected;
        *(f32 *)(arg0 + 0x78) = 4.0f;
    }
}

void func_813061E8(u8 *arg0) {
    arg0[0x87] = 5;
    *(s16 *)(arg0 + 0x7E) = -2;
    *(f32 *)(arg0 + 0x78) = 4.0f;
}

extern void func_800226C0(s32);
extern f32 D_81311F70;
// The cursor cell (column, row) at +8, copied to +0xC as the previous cell.
typedef struct unk_D_813064E8 {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} unk_D_813064E8;

void func_81306208(u8 *arg0) {
    if (*(s16 *)(arg0 + 8) > 0) {
        *(unk_D_813064E8 *)(arg0 + 0xC) = *(unk_D_813064E8 *)(arg0 + 8);
        *(s16 *)(arg0 + 8) -= 1;
        arg0[0x87] = 2;
        arg0[0x83] = 0;
        arg0[0x85] = 4;
        func_800226C0(1);
    }
}

void func_81306264(u8 *arg0) {
    if (*(s16 *)(arg0 + 8) > 0) {
        return;
    }
    *(unk_D_813064E8 *)(arg0 + 0xC) = *(unk_D_813064E8 *)(arg0 + 8);
    *(s16 *)(arg0 + 8) += 1;
    arg0[0x87] = 2;
    arg0[0x83] = 0;
    arg0[0x85] = 4;
    func_800226C0(1);
}

void func_813062C0(u8 *arg0) {
    s32 delta;
    s32 distance;

    if (*(s16 *)(arg0 + 0x7C) > 0) {
        arg0[0x8A] = *(s16 *)(arg0 + 0x7C);
        *(s16 *)(arg0 + 0x7C) -= 4;
        if (*(s16 *)(arg0 + 0x7C) < 0) {
            *(s16 *)(arg0 + 0x7C) = 0;
        }
        arg0[0x87] = 3;
        delta = *(s16 *)(arg0 + 0x7C) - arg0[0x8A];
        arg0[0x82] = 0;
        if (delta > 0) {
            distance = delta;
        } else {
            distance = -delta;
        }
        arg0[0x86] = (u32)((f32)distance * D_81311F70);
        func_800226C0(1);
    }
}

void Fragment14_ScrollGridForward(u8 *arg0) {
    s32 limit;
    s32 delta;
    s32 distance;

    limit = arg0[0x84] - 4;
    if (*(s16 *)(arg0 + 0x7C) < limit) {
        arg0[0x8A] = *(s16 *)(arg0 + 0x7C);
        *(s16 *)(arg0 + 0x7C) += 4;
        if (*(s16 *)(arg0 + 0x7C) > limit) {
            *(s16 *)(arg0 + 0x7C) = limit;
        }
        arg0[0x87] = 3;
        delta = *(s16 *)(arg0 + 0x7C) - arg0[0x8A];
        arg0[0x82] = 0;
        if (delta > 0) {
            distance = delta;
        } else {
            distance = -delta;
        }
        arg0[0x86] = (u32)((f32)distance * D_81311F70);
        func_800226C0(1);
    }
}

void func_813064E8(u8 *arg0) {
    s32 delta;
    s32 distance;

    if (*(s16 *)(arg0 + 0xA) > 0) {
        *(unk_D_813064E8 *)(arg0 + 0xC) = *(unk_D_813064E8 *)(arg0 + 8);
        *(s16 *)(arg0 + 0xA) -= 1;
        arg0[0x87] = 2;
        arg0[0x83] = 0;
        arg0[0x85] = 1;
        func_800226C0(1);
        return;
    }
    if (*(s16 *)(arg0 + 0x7C) > 0) {
        arg0[0x8A] = *(s16 *)(arg0 + 0x7C);
        *(s16 *)(arg0 + 0x7C) -= 1;
        arg0[0x87] = 3;
        delta = *(s16 *)(arg0 + 0x7C) - arg0[0x8A];
        arg0[0x82] = 0;
        if (delta > 0) {
            distance = delta;
        } else {
            distance = -delta;
        }
        arg0[0x86] = (u32)((f32)distance * D_81311F70);
        func_800226C0(1);
    }
}

// Moves the grid cursor down one row while the s16 row at 0xA is below 3; on the last
// row it instead scrolls the grid forward by one row, the single-row counterpart of
// Fragment14_ScrollGridForward.
void func_8130662C(u8 *grid) {
    s16 scroll_row;
    s32 delta;
    s32 distance;

    if (*(s16 *)(grid + 0xA) < 3) {
        *(unk_D_813064E8 *)(grid + 0xC) = *(unk_D_813064E8 *)(grid + 8);
        *(s16 *)(grid + 0xA) += 1;
        grid[0x87] = 2;
        grid[0x83] = 0;
        grid[0x85] = 1;
        func_800226C0(1);
    } else {
        scroll_row = *(s16 *)(grid + 0x7C);
        if (scroll_row < grid[0x84] - 4) {
            *(s16 *)(grid + 0x7C) = scroll_row + 1;
            grid[0x8A] = scroll_row;
            grid[0x87] = 3;
            delta = *(s16 *)(grid + 0x7C) - grid[0x8A];
            grid[0x82] = 0;
            if (delta > 0) {
                distance = delta;
            } else {
                distance = -delta;
            }
            grid[0x86] = (u32)((f32)distance * D_81311F70);
            func_800226C0(1);
        }
    }
}

extern u8 D_800CE060[];
void func_81306780(u8 *arg0) {
    u16 flags;
    u8 *entry;

    // D_800CE060 holds four 0x28-byte ControllerState records; +0xC is buttonsRepeat.
    //@include/controller.h
    entry = D_800CE060 + *(u8 *)(arg0 + 0x89) * 0x28;
    flags = *(u16 *)(entry + 0xC);
    // FAKE: the first two tests reread entry + 0xC instead of flags; diff score 600 without it.
    if (*(u16 *)(entry + 0xC) & 0x8000) {
        func_81306178();
    } else if (*(u16 *)(entry + 0xC) & 0x4000) {
        func_813061E8(arg0);
    } else if (flags & 0x200) {
        func_81306208(arg0);
    } else if (flags & 0x100) {
        func_81306264(arg0);
    } else if (flags & 0x800) {
        func_813064E8(arg0);
    } else if (flags & 0x400) {
        func_8130662C(arg0);
    } else if (flags & 8) {
        func_813062C0(arg0);
    } else if (flags & 4) {
        func_813063CC(arg0);
    }
}

void Fragment14_UpdateGridCursorStep(u8 *arg0) {
    s32 count = arg0[0x83];
    if (count >= arg0[0x85]) {
        arg0[0x83] = 0;
        arg0[0x87] = 1;
        *(unk_D_813064E8 *)(arg0 + 0xC) = *(unk_D_813064E8 *)(arg0 + 8);
    } else {
        arg0[0x83] = count + 1;
    }
}

void func_813068C0(void *arg0)
{
  unsigned int temp_v0;
  temp_v0 = *((u8 *) (((u8 *) arg0) + 0x82));
  if (((s32) temp_v0) >= ((s32) (*((u8 *) (((u8 *) arg0) + 0x86)))))
  {
    *((u8 *) (((u8 *) arg0) + 0x82)) = 0U;
    *((s8 *) (((u8 *) arg0) + 0x8A)) = (s8) (*((s16 *) (((u8 *) arg0) + 0x7C)));
    *((s8 *) (((u8 *) arg0) + 0x87)) = 1;
    return;
  }
  *((u8 *) (((u8 *) arg0) + 0x82)) = (u8) (temp_v0 + 1);
}

extern f32 func_816092FC(void);
void func_813068FC(void *arg0) { *(f32 *)((u8 *)arg0 + 0x78) += func_816092FC(); if (*(f32 *)((u8 *)arg0 + 0x78) >= 4.0f) { *(f32 *)((u8 *)arg0 + 0x78) = 4.0f; *(u8 *)((u8 *)arg0 + 0x87) = 1; } }

f32 func_816092FC(void);
void func_81306954(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0x78))) = (f32) ((*(f32 *)((u8 *)(arg0) + (0x78))) - func_816092FC());
    if ((*(f32 *)((u8 *)(arg0) + (0x78))) <= 0.0f) {
        (*(f32 *)((u8 *)(arg0) + (0x78))) = 0.0f;
        if ((*(s32 *)((u8 *)(arg0) + (0))) == 0) {
            (*(s8 *)((u8 *)(arg0) + (0x87))) = 0;
        }
    }
}

void func_813069B0(u8 *arg0) {
    *(f32 *)(arg0 + 0x78) = 0.0f;
}

extern void func_81306780(u8 *);
extern void func_81600A34(void *, void *, s32, s32, s32, s32, s32);
void Fragment14_UpdateGridState(u8 *arg0, void *arg1) {
    s32 active = 0;
    s16 first[4], second[4], third[4];

    switch (arg0[0x87]) {
    case 0:
        func_813069B0(arg0);
        return;
    case 1:
        active = 1;
        func_81306780(arg0);
        break;
    case 3:
        active = 1;
        func_813068C0(arg0);
        break;
    case 2:
        active = 1;
        Fragment14_UpdateGridCursorStep(arg0);
        break;
    case 4:
        func_813068FC(arg0);
        break;
    case 5:
        func_81306954(arg0);
        break;
    }
    Fragment14_ComputeGridRectangles(arg0, &first, &second, &third);
    func_81600A34(arg1, arg0 + 1, 0, first[0], first[1], first[2], first[3]);
    func_81600A34(arg1, arg0 + 2, active, second[0], second[1], second[2], second[3]);
    func_81600A34(arg1, arg0 + 3, active, third[0], third[1], third[2], third[3]);
}

s16 func_81306B0C(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((u8 *)(arg0) + (0x87)));
    if ((temp_v0 == 0) || (temp_v0 == 5)) {
        (*(s16 *)((u8 *)(arg0) + (0x80))) = func_813055E0((s32) arg0, (s32) (*(s16 *)((u8 *)(arg0) + (0x7C))), (s32) (*(s16 *)((u8 *)(arg0) + (8))), (s32) (*(s16 *)((u8 *)(arg0) + (0xA))));
        return (*(s16 *)((u8 *)(arg0) + (0x7E)));
    }
    return -1;
}

extern void func_81601A38(s32 *, s32);
extern void func_81602134(void *, void *);
void Fragment14_ResetGrid(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    func_81601A38((s32 *)(arg0 + 0x54), 0);
    if (arg4 != 0) {
        func_81602134(arg0 + 0x10, arg4);
    }
    *(s16 *)(arg0 + 8) = 0;
    *(s16 *)(arg0 + 0xA) = 0;
    *(s32 *)arg0 = 0;
    *(s16 *)(arg0 + 0x7C) = 0;
    *(unk_D_813064E8 *)(arg0 + 0xC) = *(unk_D_813064E8 *)(arg0 + 8);
    *(s16 *)(arg0 + 4) = arg1;
    *(s16 *)(arg0 + 6) = arg2;
    arg0[0x87] = 0;
    arg0[0x85] = 4;
    arg0[0x84] = 4;
    *(f32 *)(arg0 + 0x78) = 0.0f;
    *(f32 *)(arg0 + 0x74) = 0.5f;
    arg0[0x89] = arg3;
    *(s16 *)(arg0 + 0x80) = 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/14/fragment14_FD770/func_81306C18.s")

void Fragment14_BeginGridClose(u8 *arg0) {
    switch (arg0[0x87]) {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
        *(f32 *)(arg0 + 0x78) = 4.0f;
        /* fall through */
    case 4:
    case 5:
        arg0[0x87] = 5;
        break;
    }
    *(s32 *)arg0 = 0;
}
#endif
