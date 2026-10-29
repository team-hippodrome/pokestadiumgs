#include "global.h"


#ifdef VERSION_US
extern void func_87F02CE0(s32 *, s32, s32);
extern u8 D_80126420;

void func_87F02CB0(s32 arg0, s32 arg1) {
    func_87F02CE0(&D_80126420, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_325920/func_87F02CE0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_325920/func_87F02F00.s")

void func_87F03204(void *arg0, void *arg1)
{
  u8 temp_v0;
  temp_v0 = *((u8 *) (((u8 *) arg1) + 0xC));
  switch (temp_v0)
  {
    case 0:
      *((f32 *) (((u8 *) arg1) + 0x18)) = 1.0f;
      *((s16 *) (((u8 *) arg1) + 0x1C)) = 0x1FF;
      return;

    case 1:
      *((f32 *) (((u8 *) arg0) + 0x14)) = (f32) (-(*((f32 *) (((u8 *) arg1) + 0))));
      *((s16 *) (((u8 *) arg1) + 0x1C)) = 0x1FF;
      *((f32 *) (((u8 *) arg1) + 0x18)) = 1.0f;
      return;

    case 2:

    case 3:
      *((s16 *) (((u8 *) arg1) + 0x1C)) = 0x2FF;
      *((f32 *) (((u8 *) arg1) + 0x18)) = 1.0f;
      return;

  }

}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_325920/func_87F0328C.s")

typedef struct unk_func_87F0339C_color {
    u8 r, g, b, a;
} unk_func_87F0339C_color;

typedef struct unk_func_87F0339C {
    u8 unk_00[16];
    unk_func_87F0339C_color environment;
    unk_func_87F0339C_color primitive;
} unk_func_87F0339C;

extern void *D_8009491C;
extern Gfx *D_800D0510;
extern Gfx D_87F0F7A0[];
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);
void func_87F0339C(s32 arg0, void *arg1) {
    void *context;
    void *node;
    unk_func_87F0339C *state;
    u8 *pixels;

    if (arg0 == 5) {
        context = D_8009491C;
        node = *(void **)((u8 *)context + 20);
        state = *(unk_func_87F0339C **)((u8 *)node + 32);
        pixels = func_8004CA60((u8 *)func_8004C990(147, 0));
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, state->environment.r, state->environment.g,
                      state->environment.b, state->environment.a);
        gDPSetPrimColor(D_800D0510++, 0, 0, state->primitive.r, state->primitive.g,
                       state->primitive.b, state->primitive.a);
        gSPSegment(D_800D0510++, 15, pixels);
        gSPDisplayList(D_800D0510++, D_87F0F7A0);
        func_8003CD84();
    }
}

extern void func_87F02684();

void func_87F034CC(void) {
    func_87F02684();
}
#endif
