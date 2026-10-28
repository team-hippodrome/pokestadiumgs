#include "global.h"
#include "controller.h"


#ifdef VERSION_US
s32 D_82615330 = 0;
void func_826005F0(s32 arg0) {
    D_82615330 = arg0;
}

extern char D_826157D0[];
extern char D_826157D8[];
extern void Ui_DrawGradientPanel(s32, s32, s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495BC(s32, s32, const char *, ...);
extern s32 func_8004C874(s32, s32);
extern void func_800499EC(void);
typedef struct {
    u8 r, g, b;
} Fragment20Color;
// IDO copies the two initialized colors from anonymous .data templates (D_82615334, D_82615338).
void func_826005FC(void) {
    s32 i;
    Fragment20Color top = { 0, 0, 30 };
    Fragment20Color bottom = { 0, 0, 150 };
    u8 *entry;
    s32 highlighted;

    Ui_DrawGradientPanel(100, 120, 320, 280, (s32)&top, (s32)&bottom);
    func_800498C4();
    func_800496A4(8, 0);
    func_8004972C(255, 255, 255, 255);
    if (*(u16 *)(*(u8 **)D_82615330 + 8) != 0x500) {
        for (i = 0; i < *(s16 *)((u8 *)D_82615330 + 0x14); i++) {
            entry = ((s16 *)((u8 *)D_82615330 + 0x18))[i] * 0x98 + *(u8 **)((u8 *)D_82615330 + 0xC) + 4;
            highlighted = 0;
            if (i == *(s16 *)((u8 *)D_82615330 + 0x16)) {
                highlighted = 1;
            }
            if (!highlighted) {
                func_8004972C(255, 255, 255, 255);
            } else {
                func_8004972C(255, 255, 0, 255);
            }
            func_800495BC(120, i * 20 + 220, D_826157D0, func_8004C874(0x29, entry[0] - 1), func_8004C874(0x2A, entry[1] - 1));
        }
    } else {
        func_800495BC(120, 220, D_826157D8, *(s32 *)((u8 *)D_82615330 + 0x98));
    }
    func_800499EC();
}

extern void func_80008648();
extern void BgStage_DrawFrame();
extern void func_826005FC();
extern void func_82602710(s32);
extern void func_826042A0();
s32 D_8261533C = 1;
void func_826007E4(void) {
    BgStage_DrawFrame();
    func_82602710(D_82615330);
    func_826042A0();
    if (D_8261533C != 0) {
        func_826005FC();
    }
    func_80008648();
}

/* D_82615330 is declared s32 earlier in this file; the (u8 *)D_82615330 casts
 * load that value and dereference it as the stage-state pointer. */

extern s32 StageContext_GetFadeMode(void);

s32 func_82600838(s32 arg0) {
    s32 var_a2;
    ControllerState *var_v1;
    /* FAKE: exists only so the three `*base` reads constant-propagate to ugen's
     * `lw $r, D_80087200` macro form (as1: lui %hi + lw %lo with base=dest in
     * v1) instead of routing through the live la of the bare reads; removing it
     * re-joins those loads to the a3 la web and loses the reload pairs. */
    ControllerState **base;

    base = &D_80087200;
    var_a2 = arg0;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            var_a2 = 1;
        }
        break;
    case 1:
        if (*(u16 *)((u8 *)*(void **)D_82615330 + 8) != 0x500) {
            if (D_80087200->buttonsRepeat & 0x800) {
                *(s16 *)((u8 *)D_82615330 + 0x16) = *(s16 *)((u8 *)D_82615330 + 0x16) - 1;
                if (*(s16 *)((u8 *)D_82615330 + 0x16) < 0) {
                    *(s16 *)((u8 *)D_82615330 + 0x16) = *(s16 *)((u8 *)D_82615330 + 0x14) - 1;
                }
            }
            if (D_80087200->buttonsRepeat & 0x400) {
                *(s16 *)((u8 *)D_82615330 + 0x16) = *(s16 *)((u8 *)D_82615330 + 0x16) + 1;
                if (*(s16 *)((u8 *)D_82615330 + 0x16) >= *(s16 *)((u8 *)D_82615330 + 0x14)) {
                    *(s16 *)((u8 *)D_82615330 + 0x16) = 0;
                }
            }
            var_v1 = *base;
        } else {
            var_v1 = D_80087200;
            if (var_v1->buttonsRepeat & 0x800) {
                *(s32 *)((u8 *)D_82615330 + 0x98) = *(s32 *)((u8 *)D_82615330 + 0x98) + 1;
                var_v1 = *base;
            }
            if (var_v1->buttonsRepeat & 0x400) {
                *(s32 *)((u8 *)D_82615330 + 0x98) = *(s32 *)((u8 *)D_82615330 + 0x98) - 1;
                var_v1 = *base;
            }
        }
        if (var_v1->buttonsPressed & 0x8000) {
            var_a2 = 3;
        }
        break;
    }
    return var_a2;
}
void func_826009A0(void) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        func_80064D28();
        func_82604170();
        func_826007E4();
        temp_v0 = func_82600838(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != 3);
    if (*(s16 *)((u8 *)D_82615330 + 0x16) != *(s16 *)(*(u8 **)D_82615330 + 0x88)) {
        *(s16 *)(*(u8 **)D_82615330 + 0x88) = *(s16 *)((u8 *)D_82615330 + 0x16);
        *(*(u8 **)D_82615330 + 0xE) = 0;
    }
}
#endif
