#include "global.h"
#include "controller.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/6670/func_80005A70.s")

extern s16 MathUtil_Atan2s(f32, f32);
void func_80005B88(ControllerState *state) { s16 x; s16 y; f32 x_norm; f32 y_norm; f32 magnitude; f32 old_magnitude; f32 scale; x = state->stickX; state->stickXNorm = 0.0f; state->stickYNorm = 0.0f; if (x < -7) { state->stickXNorm = (f32)(x + 6); } if (x >= 8) { state->stickXNorm = (f32)(x - 6); } y = state->stickY; if (y < -7) { state->stickYNorm = (f32)(y + 6); } if (y >= 8) { state->stickYNorm = (f32)(y - 6); } x_norm = state->stickXNorm; y_norm = state->stickYNorm; magnitude = sqrtf((x_norm * x_norm) + (y_norm * y_norm)); state->stickMagnitude = magnitude; if (magnitude > 64.0f) { scale = 64.0f / state->stickMagnitude; state->stickMagnitude = 64.0f; state->stickXNorm = x_norm * scale; state->stickYNorm = y_norm * scale; } if (state->stickMagnitude > 0.0f) { state->stickAngle = MathUtil_Atan2s(-state->stickYNorm, state->stickXNorm); } }

extern s16 D_80087210;
extern s16 D_80087214;
void func_80005CA4(ControllerState *arg0) {
    s32 result = 0;
    if (arg0->buttonsPressed & U_JPAD) { result = U_JPAD; arg0->repeatTimer = D_80087210; }
    if (arg0->buttonsPressed & D_JPAD) { result = (result | D_JPAD) & 0xFFFF; arg0->repeatTimer = D_80087210; }
    if (arg0->buttonsPressed & L_JPAD) { result = (result | L_JPAD) & 0xFFFF; arg0->repeatTimer = D_80087210; }
    if (arg0->buttonsPressed & R_JPAD) { result = (result | R_JPAD) & 0xFFFF; arg0->repeatTimer = D_80087210; }
    if (arg0->buttonsPressed & U_CBUTTONS) { result = (result | U_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087210; }
    if (arg0->buttonsPressed & D_CBUTTONS) { result = (result | D_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087210; }
    if (arg0->buttonsPressed & L_CBUTTONS) { result = (result | L_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087210; }
    if (arg0->buttonsPressed & R_CBUTTONS) { result = (result | R_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087210; }
    arg0->repeatTimer = arg0->repeatTimer - 1;
    if (arg0->repeatTimer <= 0) {
        arg0->repeatTimer = 0;
        if (arg0->buttonsHeld & U_JPAD) { result = (result | U_JPAD) & 0xFFFF; arg0->repeatTimer = D_80087214; }
        if (arg0->buttonsHeld & D_JPAD) { result = (result | D_JPAD) & 0xFFFF; arg0->repeatTimer = D_80087214; }
        if (arg0->buttonsHeld & L_JPAD) { result = (result | L_JPAD) & 0xFFFF; arg0->repeatTimer = D_80087214; }
        if (arg0->buttonsHeld & R_JPAD) { result = (result | R_JPAD) & 0xFFFF; arg0->repeatTimer = D_80087214; }
        if (arg0->buttonsHeld & U_CBUTTONS) { result = (result | U_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087214; }
        if (arg0->buttonsHeld & D_CBUTTONS) { result = (result | D_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087214; }
        if (arg0->buttonsHeld & L_CBUTTONS) { result = (result | L_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087214; }
        if (arg0->buttonsHeld & R_CBUTTONS) { result = (result | R_CBUTTONS) & 0xFFFF; arg0->repeatTimer = D_80087214; }
    }
    arg0->buttonsRepeat = arg0->buttonsPressed | result;
}

extern void Cont_BlockEepromQueue(void); extern OSMesgQueue D_800CE100;
void Cont_StartReadInputs(void) { Cont_BlockEepromQueue(); osContStartReadData(&D_800CE100); }

/* mkdraft:func_80005F0C begin */
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern void Cont_NoBlockEepromQueue(void);
extern s32 GbPak_PollConnection();
extern s32 func_80077424(s32 *);
extern s32 D_800CE130;
extern OSMesgQueue D_800CE100;

// Reads the four controller slots once per call: latches the raw pad buttons,
// converts the stick through func_80005B88, folds stick directions into the
// d-pad bits (0x100/0x200/0x400/0x800) when the normalized stick passes +/-32,
// clears an opposed d-pad axis pair, then derives pressed/released from the
// previous held state before func_80005CA4 handles repeat.
// FAKE: the first clear block carries a copy pair, `var_v0 = var_s0;` followed by
// `var_v0 = var_s0 ^ 0;`, and the second clear block repeats `var_v0 = var_s0;`
// twice. All three are no-ops that uopt drops, but they change which value it
// keeps live in $v0 across the branch (`or v0,s0` placement at the join). Without
// the first block's pair this file scores 3; without the second block's duplicate
// copy it scores 7; with neither the source is the plain two-copy form and scores
// 10 (standalone object diff against expected/build/src/6670.o).


void func_80005F0C(void) {
    ControllerState *var_s1;
    OSContPad *temp_v0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    s32 temp_a1;
    s32 var_s2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;

    var_s1 = D_800CE060;
    osRecvMesg(&D_800CE100, NULL, 1);
    func_80077424(&D_800CE130);
    Cont_NoBlockEepromQueue();
    var_s2 = 0;
    do {
        if (var_s1->portNumber != 0) {
            temp_v0 = var_s1->pad;
            var_s0 = temp_v0->button;
            var_s1->stickX = (s16) temp_v0->stick_x;
            var_s1->stickY = (s16) temp_v0->stick_y;
            func_80005B88(var_s1);
            if (var_s1->flags & 1) {
                temp_fv0 = var_s1->stickXNorm;
                if (temp_fv0 <= -32.0f) {
                    var_s0 = (var_s0 | 0x200) & 0xFFFF;
                }
                if (temp_fv0 >= 32.0f) {
                    var_s0 = (var_s0 | 0x100) & 0xFFFF;
                }
                temp_fv0_2 = var_s1->stickYNorm;
                if (temp_fv0_2 <= -32.0f) {
                    var_s0 = (var_s0 | 0x400) & 0xFFFF;
                }
                if (temp_fv0_2 >= 32.0f) {
                    var_s0 = (var_s0 | 0x800) & 0xFFFF;
                }
            }
            var_v0 = var_s0;
            if ((var_s0 & 0xC00) == 0xC00) {
                var_s0 = (var_v0 & 0xFFFFF3FF) & 0xFFFF;
                var_v0 = var_s0; /* FAKE: see function comment */
                var_v0 = var_s0 ^ 0; /* FAKE: see function comment */
            }
            if ((var_v0 & 0x300) == 0x300) {
                var_s0 = (var_v0 & 0xFFFFFCFF) & 0xFFFF;
                var_v0 = var_s0; /* FAKE: duplicated copy; see function comment */
                var_v0 = var_s0; /* FAKE: see function comment */
            }
            temp_v1 = var_s1->buttonsHeld;
            var_s1->buttonsHeld = var_s0;
            temp_a1 = var_v0 ^ temp_v1;
            var_s1->buttonsPressed = var_v0 & temp_a1;
            var_s1->buttonsReleased = temp_v1 & temp_a1;
            func_80005CA4(var_s1);
        } else {
            var_s1->buttonsPressed = 0;
            var_s1->buttonsReleased = 0;
            var_s1->buttonsHeld = 0;
        }
        var_s2 += 1;
        var_s1++;
    } while (var_s2 != 4);
    GbPak_PollConnection();
}
/* mkdraft:func_80005F0C end */

extern u8 D_800CE118; u8 func_800060E8(void) { return D_800CE118; }

void func_800060F4(s16 arg0, s16 arg1) { extern s16 D_80087210; extern s16 D_80087214; if (arg0 > 0) D_80087210 = arg0; if (arg1 > 0) D_80087214 = arg1; }

extern s16 D_80087210; extern s16 D_80087214; void func_8000612C(void) { D_80087210 = 10; D_80087214 = 2; }

void func_80006148(ControllerState *arg0) { arg0->flags |= 1; }


/* mkdraft:func_80006158 begin */
void func_80006158(void) {
    s32 i;

    func_8000612C();
    for (i = 0; i < 4; i++) {
        D_800CE060[i].flags &= ~1;
    }
}
/* mkdraft:func_80006158 end */

s32 func_800061C4(ControllerState *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->status->type & 0x1F07) == CONT_TYPE_NORMAL) {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_800061EC(void) {
    s32 var_a0;

    var_a0 = (func_800060E8() & 1) != 0;
    if (var_a0 != 0) {
        var_a0 = func_800061C4(D_80087200) != 0;
    }
    return var_a0;
}

extern u8 D_800CE119; s32 func_80006230(void) { return D_800CE119 != 0; }

extern void Cont_NoBlockEepromQueue(void);
s32 func_80006240(u8 *buffer, u32 size, s32 inaddr) {
    s32 result = 1;
    if (D_800CE119) {
        s32 i = 4;
        Cont_BlockEepromQueue();
        do {
            s32 count = size / 8;
            s32 address = (inaddr + 7) & ~7;
            i--;
            result = osEepromLongRead(&D_800CE100, count, buffer, address);
        } while (i > 0 && result);
        Cont_NoBlockEepromQueue();
    }
    return result;
}

s32 func_800062F8(u8 *buffer, u32 size, s32 inaddr) {
    s32 result = 1;
    if (D_800CE119) {
        s32 i = 4;
        Cont_BlockEepromQueue();
        do {
            s32 count = size / 8;
            s32 address = (inaddr + 7) & ~7;
            i--;
            result = osEepromLongWrite(&D_800CE100, count, buffer, address);
        } while (i > 0 && result);
        Cont_NoBlockEepromQueue();
    }
    return result;
}

void Cont_BlockEepromQueue(void) { extern OSMesgQueue D_800CE150; osRecvMesg(&D_800CE150, NULL, OS_MESG_BLOCK); }

void Cont_NoBlockEepromQueue(void) { extern OSMesgQueue D_800CE150; osSendMesg(&D_800CE150, NULL, OS_MESG_NOBLOCK); }

void Cont_InitEepromQueue(void) { extern OSMesgQueue D_800CE150; extern OSMesg D_800CE14C; osCreateMesgQueue(&D_800CE150, &D_800CE14C, 1); osSendMesg(&D_800CE150, NULL, OS_MESG_NOBLOCK); }

extern void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);
extern s32 osContInit(OSMesgQueue *, u8 *, OSContStatus *);
extern s32 osEepromProbe(OSMesgQueue *);
extern OSMesgQueue D_800CE100;
void Cont_InitEepromQueue(void);
void Cont_InitEepromQueue(void);
s32 func_80005A70();
extern OSMesgQueue D_800CE100;
extern OSContStatus D_800CE120;
extern void *D_800CE148;

u8 func_8000644C(void)
{
  OSContStatus *new_var2;
  OSContStatus *var_a0;
  s32 var_v1;
  u8 *new_var;
  int new_var3;
  new_var = &D_800CE118;
  Cont_InitEepromQueue();
  osCreateMesgQueue(&D_800CE100, &D_800CE148, 1);
  osSetEventMesg(5U, &D_800CE100, NULL);
  new_var2 = &D_800CE120;
  osContInit(&D_800CE100, new_var, new_var2);
  var_a0 = new_var2;
  var_v1 = 0;
  do
  {
    new_var3 = 1;
    if ((var_a0->type & 0x1F07) != 5)
    {
      D_800CE118 &= ~(1 << var_v1);
    }
    var_v1 += new_var3;
    var_a0 += new_var3;
  }
  while (var_v1 != (new_var3 = 4));
  D_800CE119 = osEepromProbe(&D_800CE100);
  func_80005A70();
  return D_800CE118;
}
#pragma C_FUNCTION_PADDING(16)
#endif
