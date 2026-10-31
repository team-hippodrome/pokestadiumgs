#include "global.h"


#ifdef VERSION_US
// Hex number editor state, laid out like the numeric view of fragment77's
// F77EditorState; func_8F90083C clamps the entered value (words[5]) to 0-255.
//@src/fragments/77/fragment77_code.c
typedef union {
    s32 words[9];
    struct {
        u16 geometry[4];
        s16 selected;
        u16 last;
        s8 digits[8];
        s32 value;
    } numeric;
} F78EditorState;
extern F78EditorState D_8F911650;

/* mkdraft:func_8F900020 begin */
extern Gfx *D_800D0510;
extern u8 D_80094DE0[];

void func_8F900020(s32 arg0, s32 arg1, s32 arg2) {
    gSPDisplayList(D_800D0510++, D_80094DE0);
    gDPPipeSync(D_800D0510++);
    gDPSetFillColor(D_800D0510++, 0xFFC7FFC1);
    gDPFillRectangle(D_800D0510++, arg0, arg1, arg0 + arg2, arg1 + 2);
}
/* mkdraft:func_8F900020 end */

extern void func_80007444(Gfx **, s32, s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_80049628(s32, s32, s32);
extern void func_800499EC(void);
extern void func_8F900020(s32, s32, s32);
extern Gfx * D_800D0510;
void func_8F9000D0(void) {
    s32 index;
    F78EditorState *state = &D_8F911650;

    func_80007444(&D_800D0510, state->numeric.geometry[0], state->numeric.geometry[1], 0x20, 0x16, 1);
    func_800498C4();
    func_800496A4(4, 0);
    for (index = state->numeric.last; index >= 0; index--) {
        if (state->numeric.digits[index] < 10) {
            func_80049628(state->numeric.geometry[0] + (state->numeric.last - index) * 16,
                          state->numeric.geometry[1], state->numeric.digits[index] + 0x30);
        } else {
            func_80049628(state->numeric.geometry[0] + (state->numeric.last - index) * 16,
                          state->numeric.geometry[1], state->numeric.digits[index] + 0x37);
        }
    }
    func_800499EC();
    func_8F900020(state->numeric.geometry[0] + (state->numeric.last - state->numeric.selected) * 16,
                  state->numeric.geometry[1] + 18, 16);
}

extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495BC(s32, s32, s32 *);
void func_8F900200(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 != 0) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    temp_v0 = *(u16 *)(arg0 + 0);
    if ((temp_v0 == 0) || (temp_v0 == 2) || (temp_v0 == 3)) {
        func_800495BC(*(u16 *)(arg0 + 2), *(u16 *)(arg0 + 4), (s32 *)(arg0 + 0x10));
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/78/fragment78_code/func_8F900284.s")

extern u8 D_8F901630;
extern s32 D_8F91163C;
extern s32 D_8F911664;

void func_8F900574(void) {
    D_8F911664 = (s32) *(&D_8F901630 + D_8F91163C);
}


void func_8F900594(void) {
    *(&D_8F901630 + D_8F91163C) = (s8) D_8F911664;
}

extern s32 D_8F911630;
extern s32 D_8F911634;
extern void func_8F900574(void);
void func_8F9005B4(void) {
    s32 value;
    s32 index;

    D_8F911650.numeric.geometry[0] = D_8F911630 * 34 + 0xB4;
    D_8F911650.numeric.geometry[1] = D_8F911634 * 22 + 0x69;
    D_8F911650.numeric.geometry[2] = 0x20;
    D_8F911650.numeric.geometry[3] = 0x14;
    D_8F911650.numeric.selected = 0;
    D_8F911650.numeric.last = 1;
    func_8F900574();
    value = D_8F911650.numeric.value;
    index = 0;
    if (index <= D_8F911650.numeric.last) {
        do {
            D_8F911650.numeric.digits[index] = value % 16;
            value /= 16;
            index++;
        } while (index <= D_8F911650.numeric.last);
    }
}

extern s32 Input_GetRepeatedDPad(void);
extern s32 D_80087200;

// Same code as fragment77's func_8F802B40 on the editor state at D_8F911650; GS plays
// no sound on D-pad input and switches on the input value without an s16 conversion.
//@src/fragments/77/fragment77_code.c
s32 func_8F900690(void) {
    s32 input;
    s32 result = 0;
    s32 buttons;
    u32 value;
    s32 index;
    F78EditorState *state = &D_8F911650;

    input = Input_GetRepeatedDPad();
    if (input) {
        switch (input) {
        case 0x200:
            state->numeric.selected++;
            if (state->numeric.selected > state->numeric.last) {
                state->numeric.selected = state->numeric.last;
            }
            break;
        case 0x100:
            state->numeric.selected--;
            if (state->numeric.selected < 0) {
                state->numeric.selected = 0;
            }
            break;
        case 0x800:
            state->numeric.digits[state->numeric.selected]++;
            if (state->numeric.digits[state->numeric.selected] >= 16) {
                state->numeric.digits[state->numeric.selected] = 0;
            }
            break;
        case 0x400:
            state->numeric.digits[state->numeric.selected]--;
            if (state->numeric.digits[state->numeric.selected] < 0) {
                state->numeric.digits[state->numeric.selected] = 15;
            }
            break;
        }
    }
    buttons = *(u16 *)((u8 *)(u32)D_80087200 + 8);
    if (buttons & 0x8000) {
        value = 0;
        for (index = state->numeric.last; index >= 0; index--) {
            value = value * 16 + state->numeric.digits[index];
        }
        state->numeric.value = value;
        result = 1;
    } else if (buttons & 0x4000) {
        result = 2;
    }
    return result;
}

extern s32 func_8F900690(void);
extern void func_8F9000D0(void);
extern void func_8F900594(void);
extern s32 D_8F911648;
s32 func_8F90083C(void) {
    s32 sp1C;
    s32 var_v0;

    sp1C = func_8F900690();
    func_8F9000D0();
    if (sp1C == 1) {
        var_v0 = D_8F911650.words[5];
        if (var_v0 < 0) {
            D_8F911650.words[5] = 0;
            var_v0 = 0;
        }
        if (var_v0 >= 0x100) {
            D_8F911650.words[5] = 0xFF;
        }
        func_8F900594();
        D_8F911648 = 1;
    } else if (sp1C == 2) {
        D_8F911648 = 1;
    }
    return 1;
}

extern u8 D_8F901630;
extern void func_8005B140(s32);
extern u8 func_8005D92C(s32);
extern s32 GbPak_ReadCommand(s32, u8 *, s32, s32);
extern void GbSave_RequirePakPresent(s32);
extern u32 D_8F911640;

// Same code as func_8F900968 with GbPak_ReadCommand instead of GbPak_WriteCommand;
// GS also sets D_8F911640 to 0xFF80 (0x10000-byte read) or 0x7F80 (0x8000-byte read).
s32 func_8F9008D0(s32 arg0) {
    s32 result;

    func_8005B140(arg0);
    if (func_8005D92C(arg0) == 7) {
        result = GbPak_ReadCommand(arg0, &D_8F901630, 0, 0x10000);
        D_8F911640 = 0xFF80;
    } else {
        result = GbPak_ReadCommand(arg0, &D_8F901630, 0, 0x8000);
        D_8F911640 = 0x7F80;
    }
    GbSave_RequirePakPresent(arg0);
    return result;
}

extern s32 GbPak_WriteCommand(s32, u8 *, s32, s32);
s32 func_8F900968(s32 arg0) {
    s32 result;

    func_8005B140(arg0);
    if (func_8005D92C(arg0) == 7) {
        result = GbPak_WriteCommand(arg0, &D_8F901630, 0, 0x10000);
    } else {
        result = GbPak_WriteCommand(arg0, &D_8F901630, 0, 0x8000);
    }
    GbSave_RequirePakPresent(arg0);
    return result;
}

extern s32 D_8F911644;
extern u16 D_8F901534[][17];
s32 func_8F9009E8(void) {
    s32 result = 1;

    switch (D_8F901534[D_8F911644][0]) {
        case 0:
            result = 0;
            break;
        case 3:
            D_8F911648 = 1;
            break;
        case 2:
            func_8F900968(0);
            break;
    }
    return result;
}

/* mkdraft:func_8F900A6C begin */
extern s16 D_8F90159C;
extern s16 D_8F9015A0;



u16 func_8F900A6C(s32 arg0) {
/* Menu-input auto-repeat for the controller whose state pointer is arg0: the all-button
   counterpart of Input_GetRepeatedDPad (@src/4AAD0.c), which repeats only U/D/L/R on
   D_801270AC. A fresh press is reported at once and reloads the countdown (D_8F90159C = 10)
   and the repeat interval (D_8F9015A0 = 3); while the countdown is non-zero nothing is
   reported. Once the countdown reaches 0 a held button is reported, its interval value is
   copied into the countdown, and the interval is decremented, so later repeats come sooner.
   D_8F9015A0 is clamped at 0 (it also supplies the next countdown) before the held scan.
   The return value is the button mask that func_8F900F14 and func_8F901078 switch on.
   Each pair of stores is a comma expression: IDO evaluates the right operand first, which
   materializes D_8F90159C's 10 ahead of D_8F9015A0's 3 in the generated instruction order. */
    s32 pressed;
    s32 held;
    s16 interval;

    pressed = *(u16 *)((u8 *)(u32)arg0 + 8);
    if (pressed & 0x200) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x200;
    }
    if (pressed & 0x100) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x100;
    }
    if (pressed & 0x800) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x800;
    }
    if (pressed & 0x400) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x400;
    }
    if (pressed & 0x8000) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x8000;
    }
    if (pressed & 0x4000) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x4000;
    }
    if (pressed & 0x1000) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x1000;
    }
    if (pressed & 0x20) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x20;
    }
    if (pressed & 0x10) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x10;
    }
    if (pressed & 0x2000) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x2000;
    }
    if (pressed & 0x8) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x8;
    }
    if (pressed & 0x4) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x4;
    }
    if (pressed & 0x2) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x2;
    }
    if (pressed & 0x1) {
        D_8F90159C = 0xA, D_8F9015A0 = 3;
        return 0x1;
    }
    if (D_8F90159C == 0) {
        if (D_8F9015A0 < 0) {
            D_8F9015A0 = 0;
        }
        held = *(u16 *)((u8 *)(u32)arg0 + 6);
        if (held & 0x200) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x200;
        }
        if (held & 0x100) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x100;
        }
        if (held & 0x800) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x800;
        }
        if (held & 0x400) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x400;
        }
        if (held & 0x8000) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x8000;
        }
        if (held & 0x4000) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x4000;
        }
        if (held & 0x1000) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x1000;
        }
        if (held & 0x20) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x20;
        }
        if (held & 0x10) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x10;
        }
        if (held & 0x2000) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x2000;
        }
        if (held & 0x8) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x8;
        }
        if (held & 0x4) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x4;
        }
        if (held & 0x2) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x2;
        }
        if (held & 0x1) {
            interval = D_8F9015A0;
            D_8F9015A0 = interval - 1;
            D_8F90159C = interval;
            return 0x1;
        }
    } else {
        D_8F90159C -= 1;
    }
    return 0;
}
/* mkdraft:func_8F900A6C end */

extern s32 D_8F911644;
extern u16 D_8F901534[][17];
extern s32 D_8F901530;
extern u16 func_8F900A6C(s32);
extern s32 func_8F9009E8(void);
extern s32 D_80087200;
s32 func_8F900F14(void) {
    s32 result = 1;

    switch (func_8F900A6C(D_80087200)) {
        case 0x8000:
            result = func_8F9009E8();
            break;
        case 0x4000:
            D_8F911644 = 0;
            break;
        case 0x800:
            D_8F911644 = ((u8 *)D_8F901534[D_8F911644])[12];
            break;
        case 0x400:
            D_8F911644 = ((u8 *)D_8F901534[D_8F911644])[13];
            break;
        case 0x200:
            D_8F911644 = ((u8 *)D_8F901534[D_8F911644])[14];
            break;
        case 0x100:
            D_8F911644 = ((u8 *)D_8F901534[D_8F911644])[15];
            break;
        case 0x10:
            if (D_8F901530 != 0) {
                D_8F901530 = 0;
            } else {
                D_8F901530 = 1;
            }
            break;
    }
    return result;
}

extern s32 D_8F911630;
extern s32 D_8F911634;
extern s32 D_8F911638;
extern s32 D_8F91163C;
extern u32 D_8F911640;
extern s32 D_8F911648;
extern s32 D_8F901530;
extern void func_8F9005B4(void);
extern u16 func_8F900A6C(s32);
extern s32 D_80087200;
s32 func_8F901078(void) {
    switch (func_8F900A6C((s32)D_80087200)) {
    case 0x8000:
        func_8F9005B4();
        D_8F911648 = 2;
        break;
    case 0x4000:
        D_8F911648 = 0;
        break;
    case 0x800:
        D_8F911634--;
        if (D_8F911634 < 0) {
            D_8F911634 = 0;
            D_8F911638 -= 8;
            if (D_8F911638 < 0) {
                D_8F911638 = 0;
            }
        }
        break;
    case 0x400:
        D_8F911634++;
        if (D_8F911634 >= 16) {
            D_8F911634 = 15;
            D_8F911638 += 8;
            if (D_8F911640 < D_8F911638) {
                D_8F911638 = D_8F911640;
            }
        }
        break;
    case 0x200:
        D_8F911630--;
        if (D_8F911630 < 0) {
            D_8F911630 = 7;
        }
        break;
    case 0x100:
        D_8F911630++;
        if (D_8F911630 >= 8) {
            D_8F911630 = 0;
        }
        break;
    case 8:
        D_8F911638 -= 0x80;
        if (D_8F911638 < 0) {
            D_8F911638 = 0;
        }
        break;
    case 4:
        D_8F911638 += 0x80;
        if (D_8F911640 < D_8F911638) {
            D_8F911638 = D_8F911640;
        }
        break;
    case 2:
        D_8F911638 -= 0x800;
        if (D_8F911638 < 0) {
            D_8F911638 = 0;
        }
        break;
    case 1:
        D_8F911638 += 0x800;
        if (D_8F911640 < D_8F911638) {
            D_8F911638 = D_8F911640;
        }
        break;
    case 0x10:
        if (D_8F901530 != 0) {
            D_8F901530 = 0;
        } else {
            D_8F901530 = 1;
        }
        break;
    }
    D_8F91163C = D_8F911634 * 8 + D_8F911638 + D_8F911630;
    return 1;
}

extern void func_80064D28(void);
extern void func_8F900284(void);
extern s32 func_8F900F14(void);
extern s32 func_8F901078(void);
extern s32 func_8F90083C(void);
extern void func_80008648(void);
extern s32 D_8F911648;
void func_8F90132C(void) {
    s32 var_s0;
    s32 var_v0;

    var_s0 = 0;
    do {
        func_80064D28();
        func_8F900284();
        switch (D_8F911648) {
        case 0:
            var_v0 = func_8F900F14();
            goto block_8;
        case 1:
            var_v0 = func_8F901078();
            goto block_8;
        case 2:
            var_v0 = func_8F90083C();
            goto block_8;
        }
        goto block_9;
    block_8:
        var_s0 = var_v0;
    block_9:
        func_80008648();
    } while (var_s0 != 0);
}

extern void Input_SetRepeatController(s32);
extern s32 func_8F9008D0(s32);
extern s32 D_80087200;
extern s32 D_8F911630;
extern s32 D_8F911634;
extern s32 D_8F911638;
extern s32 D_8F911644;
extern s32 D_8F911648;
extern s32 D_8F911668;
void func_8F9013E4(s32 arg0) {
    D_8F911668 = arg0;
    D_8F911648 = 0;
    D_8F911644 = 1;
    D_8F911638 = 0;
    D_8F911630 = 0;
    D_8F911634 = 0;
    Input_SetRepeatController(D_80087200);
    func_8F9008D0(arg0);
}

extern s32 main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_80047588(s32, s32);
extern void Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_8F9013E4(s32);
extern void func_80008514(s32);
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_8F90132C(void);
extern void func_80008574(void);
extern void func_80047610(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 D_1000000;
extern u8 D_446E30[];
extern u8 D_447D00[];
s32 fragment78_main(s32 arg0, s32 arg1) {
    s32 var_v0;

    main_pool_push_state(0x53524544);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    var_v0 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_80047588(0x1C, 0);
    Asset_LoadToSegment((((u32)&D_1000000) & 0x0F000000) >> 24, &D_446E30, &D_447D00, 0);
    func_8F9013E4(0);
    func_80008514(var_v0);
    func_800086A4(2);
    StageFade_StartFromOpaque(0x10);
    func_8F90132C();
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x53524544);
    return 0;
}
#endif
