#ifndef POKESTADIUMGS_CONTROLLER_H
#define POKESTADIUMGS_CONTROLLER_H

#include <ultra64.h>

// Per-port controller state. func_80005A70 clears the four records and fills portNumber, status
// and pad for each port present in D_800CE118; func_80005F0C refreshes them every frame from the
// OSContPad data and derives the edge, repeat and stick fields.
//@src/6670.c
typedef struct ControllerState {
    /* 0x00 */ s16 portNumber; // 1-4 for a connected port, 0 when absent; func_80005F0C skips 0
    /* 0x02 */ s16 stickX; // OSContPad stick_x
    /* 0x04 */ s16 stickY; // OSContPad stick_y
    /* 0x06 */ u16 buttonsHeld; // OSContPad button, plus stick-as-D-pad bits when flags bit 0 is set
    /* 0x08 */ u16 buttonsPressed; // held this frame and not the previous one
    /* 0x0A */ u16 buttonsReleased; // held the previous frame and not this one
    /* 0x0C */ u16 buttonsRepeat; // func_80005CA4: pressed, plus auto-repeat of held D-pad and C buttons
    /* 0x0E */ s16 repeatTimer; // func_80005CA4 reloads it from D_80087210 or D_80087214
    /* 0x10 */ u16 flags; // bit 0: stick drives the D-pad bits; func_80006148 sets it, func_80006158 clears it
    /* 0x12 */ s16 stickAngle; // func_80005B88: MathUtil_Atan2s of the dead-zoned stick
    /* 0x14 */ f32 stickMagnitude; // func_80005B88: length of the dead-zoned stick, capped at 64
    /* 0x18 */ f32 stickXNorm; // func_80005B88: stickX with the dead zone removed
    /* 0x1C */ f32 stickYNorm; // func_80005B88: stickY with the dead zone removed
    /* 0x20 */ OSContStatus *status;
    /* 0x24 */ OSContPad *pad;
} ControllerState; // size = 0x28

extern ControllerState D_800CE060[4];

// Initialized to &D_800CE060[0..3]. They are four separate pointers rather than one array: matched
// code that selects a port (TextInterface_RunMainLoop, TextMode8_HandleAnswerInput) loads each
// with its own lui, which an indexed array access does not reproduce.
//@src/fragments/45/fragment45_2251A0.c
extern ControllerState *D_80087200;
extern ControllerState *D_80087204;
extern ControllerState *D_80087208;
extern ControllerState *D_8008720C;

// Defined in src/6670.c.
void func_80006148(ControllerState *controller);
void func_80006158(void);
s32 func_800061C4(ControllerState *controller);

#endif
